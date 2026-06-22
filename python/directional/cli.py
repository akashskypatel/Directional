from __future__ import annotations

import argparse
import sys
from importlib import metadata
from pathlib import Path
from typing import Any, Iterable

import numpy as np


_NATIVE_NAMES = (
    "CrossFieldOptions",
    "RemeshOptions",
    "extract_cross_field",
    "remesh_from_cross_field",
    "remesh_from_mesh",
    "remesh_from_raw_cross_field",
)


def _package_version() -> str:
    try:
        return metadata.version("directional")
    except metadata.PackageNotFoundError:
        return "0.1.0"


def _load_native_module() -> Any:
    try:
        from directional import _directional as native
    except ImportError as exc:
        raise RuntimeError(
            "The directional native extension could not be imported. "
            "Build/install the package before running cross-field or remeshing commands."
        ) from exc

    missing = [name for name in _NATIVE_NAMES if not hasattr(native, name)]
    if missing:
        raise RuntimeError(
            "The directional native extension is incomplete. "
            f"Missing symbols: {', '.join(missing)}"
        )

    return native


def _load_native_api() -> tuple[type[Any], Any, Any]:
    """Return the original remeshing API tuple for backward compatibility."""
    native = _load_native_module()
    return (
        native.RemeshOptions,
        native.remesh_from_cross_field,
        native.remesh_from_raw_cross_field,
    )


def _load_cross_field_api() -> tuple[type[Any], Any, Any]:
    native = _load_native_module()
    return (
        native.CrossFieldOptions,
        native.extract_cross_field,
        native.remesh_from_mesh,
    )


def _load_input(path: Path) -> dict[str, np.ndarray]:
    if path.suffix.lower() != ".npz":
        raise ValueError("Input must be a .npz file.")

    with np.load(path) as data:
        return {key: data[key] for key in data.files}


def _content_lines(path: Path) -> Iterable[str]:
    with path.open("r", encoding="utf-8-sig") as stream:
        for raw_line in stream:
            line = raw_line.partition("#")[0].strip()
            if line:
                yield line


def _load_obj(path: Path) -> dict[str, np.ndarray]:
    vertices: list[tuple[float, float, float]] = []
    faces: list[tuple[int, int, int]] = []

    for line_number, line in enumerate(_content_lines(path), start=1):
        parts = line.split()
        if not parts:
            continue

        if parts[0] == "v":
            if len(parts) < 4:
                raise ValueError(f"OBJ vertex on line {line_number} has fewer than 3 coordinates.")
            vertices.append((float(parts[1]), float(parts[2]), float(parts[3])))
            continue

        if parts[0] != "f":
            continue

        if len(parts) != 4:
            raise ValueError(
                f"OBJ face on line {line_number} is not triangular; "
                "triangulate the mesh before processing."
            )

        face: list[int] = []
        for token in parts[1:]:
            vertex_token = token.split("/", 1)[0]
            if not vertex_token:
                raise ValueError(f"OBJ face on line {line_number} has an invalid vertex index.")

            index = int(vertex_token)
            if index == 0:
                raise ValueError(f"OBJ face on line {line_number} uses invalid index 0.")
            if index < 0:
                index = len(vertices) + index
            else:
                index -= 1

            if index < 0 or index >= len(vertices):
                raise ValueError(f"OBJ face on line {line_number} references an invalid vertex.")
            face.append(index)

        faces.append((face[0], face[1], face[2]))

    return _validated_mesh_arrays(vertices, faces, path)


def _load_off(path: Path) -> dict[str, np.ndarray]:
    lines = iter(_content_lines(path))
    try:
        header = next(lines).split()
    except StopIteration as exc:
        raise ValueError("OFF input is empty.") from exc

    if header[0] != "OFF":
        raise ValueError("OFF input must begin with the OFF header.")

    if len(header) >= 4:
        counts = header[1:4]
    else:
        try:
            counts = next(lines).split()
        except StopIteration as exc:
            raise ValueError("OFF input is missing vertex and face counts.") from exc

    if len(counts) < 2:
        raise ValueError("OFF input has an invalid counts line.")

    vertex_count = int(counts[0])
    face_count = int(counts[1])
    vertices: list[tuple[float, float, float]] = []
    faces: list[tuple[int, int, int]] = []

    for vertex_index in range(vertex_count):
        try:
            values = next(lines).split()
        except StopIteration as exc:
            raise ValueError("OFF input ended while reading vertices.") from exc
        if len(values) < 3:
            raise ValueError(f"OFF vertex {vertex_index} has fewer than 3 coordinates.")
        vertices.append((float(values[0]), float(values[1]), float(values[2])))

    for face_index in range(face_count):
        try:
            values = next(lines).split()
        except StopIteration as exc:
            raise ValueError("OFF input ended while reading faces.") from exc
        if len(values) < 4 or int(values[0]) != 3:
            raise ValueError(
                f"OFF face {face_index} is not triangular; "
                "triangulate the mesh before processing."
            )
        faces.append((int(values[1]), int(values[2]), int(values[3])))

    return _validated_mesh_arrays(vertices, faces, path)


def _validated_mesh_arrays(
    vertices: Any,
    faces: Any,
    source: Path,
) -> dict[str, np.ndarray]:
    vertex_array = np.asarray(vertices, dtype=np.float64)
    face_array = np.asarray(faces, dtype=np.int32)

    if vertex_array.ndim != 2 or vertex_array.shape[1] != 3:
        raise ValueError(f"{source} must contain a non-empty #V x 3 vertex array.")
    if face_array.ndim != 2 or face_array.shape[1] != 3:
        raise ValueError(f"{source} must contain a non-empty #F x 3 triangle array.")
    if vertex_array.shape[0] == 0 or face_array.shape[0] == 0:
        raise ValueError(f"{source} must contain at least one vertex and one triangle.")
    if not np.isfinite(vertex_array).all():
        raise ValueError(f"{source} contains non-finite vertex coordinates.")
    if np.any(face_array < 0) or np.any(face_array >= vertex_array.shape[0]):
        raise ValueError(f"{source} contains a face index outside the vertex array.")

    return {"vertices": vertex_array, "faces": face_array}


def _load_mesh_input(path: Path) -> dict[str, np.ndarray]:
    suffix = path.suffix.lower()
    if suffix == ".npz":
        data = _load_input(path)
        mesh = _validated_mesh_arrays(
            _require_array(data, "vertices"),
            _require_array(data, "faces"),
            path,
        )
        data["vertices"] = mesh["vertices"]
        data["faces"] = mesh["faces"]
        return data
    if suffix == ".obj":
        return _load_obj(path)
    if suffix == ".off":
        return _load_off(path)
    raise ValueError("Input mesh must be an .npz, .obj, or .off file.")


def _require_array(data: dict[str, np.ndarray], key: str) -> np.ndarray:
    if key not in data:
        raise ValueError(f"Input .npz is missing required array: {key}")
    return data[key]


def _optional_array(data: dict[str, np.ndarray], key: str) -> np.ndarray | None:
    return data.get(key)


def _require_npz_output(path: Path) -> None:
    if path.suffix.lower() != ".npz":
        raise ValueError("Output must use the .npz extension.")


def _make_options(args: argparse.Namespace) -> Any:
    RemeshOptions, _, _ = _load_native_api()
    options = RemeshOptions()
    options.lengthRatio = args.length_ratio
    options.integralSeamless = not args.no_integral_seamless
    options.roundSeams = args.round_seams
    options.featureAlign = args.feature_align
    options.verbose = args.verbose
    options.normalizeDirections = not args.no_normalize_directions
    return options


def _make_cross_field_options(args: argparse.Namespace) -> Any:
    CrossFieldOptions, _, _ = _load_cross_field_api()
    options = CrossFieldOptions()
    options.normalizeDirections = not args.no_normalize_directions
    options.computeMatching = not args.no_matching
    return options


def _result_array(result: Any, *names: str) -> np.ndarray | None:
    for name in names:
        if hasattr(result, name):
            return getattr(result, name)
    return None


def _result_payload(result: Any) -> dict[str, Any]:
    payload: dict[str, Any] = {
        "success": np.array(bool(getattr(result, "success", False))),
    }
    fields = {
        "vertices": ("vertices",),
        "degrees": ("degrees",),
        "faces": ("faces",),
        "cut_vertices": ("cutVertices", "cut_vertices"),
        "cut_faces": ("cutFaces", "cut_faces"),
        "cut_functions": ("cutFunctions", "cut_functions"),
        "cut_corner_functions": ("cutCornerFunctions", "cut_corner_functions"),
        "raw_cross_field": ("rawCrossField", "raw_cross_field"),
        "cross_field_matching": ("crossFieldMatching", "cross_field_matching"),
        "cross_field_effort": ("crossFieldEffort", "cross_field_effort"),
        "cross_field_singular_cycles": (
            "crossFieldSingularCycles",
            "cross_field_singular_cycles",
        ),
        "cross_field_singular_indices": (
            "crossFieldSingularIndices",
            "cross_field_singular_indices",
        ),
    }
    for output_name, candidate_names in fields.items():
        value = _result_array(result, *candidate_names)
        if value is not None:
            payload[output_name] = value
    return payload


def _cross_field_payload(result: Any) -> dict[str, Any]:
    return {
        "degree": np.array(int(result.degree), dtype=np.int32),
        "raw_cross_field": result.rawField,
        "primary_directions": result.primaryDirections,
        "secondary_directions": result.secondaryDirections,
        "matching": result.matching,
        "effort": result.effort,
        "singular_cycles": result.singularCycles,
        "singular_indices": result.singularIndices,
    }


def _cmd_info(_args: argparse.Namespace) -> int:
    print(f"directional {_package_version()}")
    try:
        _load_native_module()
    except RuntimeError as exc:
        print(f"native extension: unavailable ({exc})")
    else:
        print("native extension: available")
    return 0


def _cmd_cross_field(args: argparse.Namespace) -> int:
    _require_npz_output(args.output)
    _, extract_cross_field, _ = _load_cross_field_api()
    data = _load_mesh_input(args.input)
    options = _make_cross_field_options(args)

    result = extract_cross_field(data["vertices"], data["faces"], options)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    np.savez_compressed(args.output, **_cross_field_payload(result))
    if args.verbose:
        print(f"Wrote {args.output}")
    return 0


def _cmd_remesh(args: argparse.Namespace) -> int:
    _require_npz_output(args.output)
    _, remesh_from_cross_field, remesh_from_raw_cross_field = _load_native_api()
    data = _load_mesh_input(args.input)
    vertices = data["vertices"]
    faces = data["faces"]
    options = _make_options(args)

    raw_cross_field = _optional_array(data, "raw_cross_field")
    primary_directions = _optional_array(data, "primary_directions")
    secondary_directions = _optional_array(data, "secondary_directions")

    if raw_cross_field is not None:
        result = remesh_from_raw_cross_field(vertices, faces, raw_cross_field, options)
    elif primary_directions is not None and secondary_directions is not None:
        result = remesh_from_cross_field(
            vertices,
            faces,
            primary_directions,
            secondary_directions,
            options,
        )
    elif primary_directions is not None:
        result = remesh_from_cross_field(vertices, faces, primary_directions, options)
    else:
        _, _, remesh_from_mesh = _load_cross_field_api()
        result = remesh_from_mesh(vertices, faces, options)

    args.output.parent.mkdir(parents=True, exist_ok=True)
    np.savez_compressed(args.output, **_result_payload(result))
    if args.verbose:
        print(f"Wrote {args.output}")
    return 0


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="directional",
        description="Command line tools for Directional cross-field extraction and remeshing.",
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    info_parser = subparsers.add_parser(
        "info",
        help="Show package and native extension status.",
    )
    info_parser.set_defaults(func=_cmd_info)

    cross_field_parser = subparsers.add_parser(
        "cross-field",
        help="Extract a face-based N=4 cross field from an NPZ, OBJ, or OFF mesh.",
    )
    cross_field_parser.add_argument(
        "input",
        type=Path,
        help="Input .npz, triangular .obj, or triangular .off mesh.",
    )
    cross_field_parser.add_argument(
        "output",
        type=Path,
        help="Output .npz containing field directions and diagnostics.",
    )
    cross_field_parser.add_argument("--no-normalize-directions", action="store_true")
    cross_field_parser.add_argument("--no-matching", action="store_true")
    cross_field_parser.add_argument("--verbose", action="store_true")
    cross_field_parser.set_defaults(func=_cmd_cross_field)

    remesh_parser = subparsers.add_parser(
        "remesh",
        help=(
            "Run remeshing from an NPZ, OBJ, or OFF mesh. "
            "A cross field is extracted automatically when the input does not provide one."
        ),
    )
    remesh_parser.add_argument(
        "input",
        type=Path,
        help="Input .npz, triangular .obj, or triangular .off mesh.",
    )
    remesh_parser.add_argument("output", type=Path, help="Output .npz file.")
    remesh_parser.add_argument("--length-ratio", type=float, default=0.02)
    remesh_parser.add_argument("--no-integral-seamless", action="store_true")
    remesh_parser.add_argument("--round-seams", action="store_true")
    remesh_parser.add_argument("--feature-align", action="store_true")
    remesh_parser.add_argument("--no-normalize-directions", action="store_true")
    remesh_parser.add_argument("--verbose", action="store_true")
    remesh_parser.set_defaults(func=_cmd_remesh)

    return parser


def main(argv: list[str] | None = None) -> int:
    parser = _build_parser()
    args = parser.parse_args(argv)
    try:
        return int(args.func(args))
    except Exception as exc:
        print(f"directional: error: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())

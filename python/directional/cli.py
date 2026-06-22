from __future__ import annotations

import argparse
import sys
from importlib import metadata
from pathlib import Path
from typing import Any

import numpy as np
import trimesh

from .field_conversion import (
    FIELD_FORMATS,
    convert_field,
    infer_input_format,
    load_crossfield_vec,
    load_rawfield,
    load_rosy,
    write_crossfield_vec,
    write_rawfield,
    write_rosy_from_alpha,
)

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
            "Build or install the package before running this command."
        ) from exc

    missing = [name for name in _NATIVE_NAMES if not hasattr(native, name)]
    if missing:
        raise RuntimeError(
            "The directional native extension is incomplete. "
            f"Missing symbols: {', '.join(missing)}"
        )
    return native


def _load_npz(path: Path) -> dict[str, np.ndarray]:
    with np.load(path) as data:
        return {key: data[key] for key in data.files}


def _validated_mesh_arrays(
    vertices: Any,
    faces: Any,
    source: Path,
) -> dict[str, np.ndarray]:
    vertex_array = np.ascontiguousarray(vertices, dtype=np.float64)
    face_array = np.ascontiguousarray(faces, dtype=np.int32)
    if vertex_array.ndim != 2 or vertex_array.shape[1] != 3:
        raise ValueError(f"{source} must contain a #V x 3 vertex array.")
    if face_array.ndim != 2 or face_array.shape[1] != 3:
        raise ValueError(f"{source} must contain a triangular #F x 3 face array.")
    if vertex_array.shape[0] == 0 or face_array.shape[0] == 0:
        raise ValueError(f"{source} must contain at least one vertex and one triangle.")
    if not np.isfinite(vertex_array).all():
        raise ValueError(f"{source} contains non-finite vertex coordinates.")
    if np.any(face_array < 0) or np.any(face_array >= vertex_array.shape[0]):
        raise ValueError(f"{source} contains a face index outside the vertex array.")
    return {"vertices": vertex_array, "faces": face_array}


def _trimesh_geometry(path: Path) -> trimesh.Trimesh:
    loaded = trimesh.load(path, process=False)
    if isinstance(loaded, trimesh.Scene):
        geometries = tuple(
            geometry
            for geometry in loaded.geometry.values()
            if isinstance(geometry, trimesh.Trimesh)
        )
        if not geometries:
            raise ValueError(f"{path} contains no mesh geometry.")
        loaded = trimesh.util.concatenate(geometries)
    if not isinstance(loaded, trimesh.Trimesh):
        raise ValueError(f"{path} did not load as a triangle mesh.")
    return loaded


def _load_mesh_input(
    path: Path,
) -> tuple[dict[str, np.ndarray], trimesh.Trimesh | None]:
    if path.suffix.lower() == ".npz":
        data = _load_npz(path)
        if "vertices" not in data or "faces" not in data:
            raise ValueError("Input .npz must contain vertices and faces arrays.")
        mesh_data = _validated_mesh_arrays(data["vertices"], data["faces"], path)
        data.update(mesh_data)
        return data, None

    mesh = _trimesh_geometry(path)
    return _validated_mesh_arrays(mesh.vertices, mesh.faces, path), mesh


def _make_remesh_options(args: argparse.Namespace) -> Any:
    native = _load_native_module()
    options = native.RemeshOptions()
    options.lengthRatio = args.length_ratio
    options.integralSeamless = not args.no_integral_seamless
    options.roundSeams = args.round_seams
    options.verbose = args.verbose
    options.normalizeDirections = not args.no_normalize_directions
    return options


def _make_cross_field_options(args: argparse.Namespace) -> Any:
    native = _load_native_module()
    options = native.CrossFieldOptions()
    options.normalizeDirections = not args.no_normalize_directions
    options.computeMatching = not args.no_matching
    return options


def _infer_output_format(path: Path, requested: str) -> str:
    if requested != "auto":
        return requested
    suffix = path.suffix.lower()
    if suffix == ".rawfield":
        return "rawfield"
    if suffix == ".rosy":
        return "rosy"
    if suffix in {".vec", ".txt"}:
        return "crossfield"
    raise ValueError(
        f"Cannot infer field format from output extension: {suffix or '<none>'}"
    )


def _write_field_result(path: Path, output_format: str, result: Any) -> None:
    fmt = _infer_output_format(path, output_format)
    if fmt == "crossfield":
        write_crossfield_vec(
            result.primaryDirections,
            result.secondaryDirections,
            path,
        )
    elif fmt == "rosy":
        write_rosy_from_alpha(result.primaryDirections, path)
    elif fmt == "rawfield":
        write_rawfield(result.rawField, path, degree=int(result.degree))
    else:
        raise ValueError(f"Unsupported field output format: {fmt}")


def _orthogonal_beta(
    alpha: np.ndarray,
    normals: np.ndarray,
) -> tuple[np.ndarray, np.ndarray]:
    projected = alpha - np.sum(alpha * normals, axis=1, keepdims=True) * normals
    lengths = np.linalg.norm(projected, axis=1, keepdims=True)
    if np.any(lengths < 1e-12):
        raise ValueError("Cannot reconstruct beta from a near-zero tangent projection.")
    projected = projected / lengths
    beta = np.cross(normals, projected)
    beta_lengths = np.linalg.norm(beta, axis=1, keepdims=True)
    if np.any(beta_lengths < 1e-12):
        raise ValueError("Cannot reconstruct beta from mesh face normals.")
    return projected, beta / beta_lengths


def _load_field_for_mesh(
    path: Path,
    requested_format: str,
    mesh: trimesh.Trimesh,
) -> tuple[np.ndarray | None, np.ndarray, np.ndarray]:
    fmt = infer_input_format(path, requested_format)
    face_count = len(mesh.faces)
    if fmt == "crossfield":
        primary, secondary = load_crossfield_vec(path)
        raw = None
    elif fmt == "rawfield":
        raw = load_rawfield(path)
        if raw.ndim != 2 or raw.shape[1] < 3 or raw.shape[1] % 3 != 0:
            raise ValueError("Rawfield data must contain 3 * degree columns.")
        primary = raw[:, 0:3]
        if raw.shape[1] >= 6:
            secondary = raw[:, 3:6]
        else:
            primary, secondary = _orthogonal_beta(
                primary,
                np.asarray(mesh.face_normals),
            )
    elif fmt == "rosy":
        primary = load_rosy(path)
        primary, secondary = _orthogonal_beta(
            primary,
            np.asarray(mesh.face_normals),
        )
        raw = None
    else:
        raise ValueError(f"Unsupported field format: {fmt}")

    primary = np.ascontiguousarray(primary, dtype=np.float64)
    secondary = np.ascontiguousarray(secondary, dtype=np.float64)
    if primary.shape != (face_count, 3) or secondary.shape != (face_count, 3):
        raise ValueError(
            f"Field row count must match mesh face count ({face_count}); got "
            f"{primary.shape[0]} and {secondary.shape[0]}."
        )
    if raw is not None:
        raw = np.ascontiguousarray(raw, dtype=np.float64)
    return raw, primary, secondary


def _quadrangulate_polygons(
    vertices: Any,
    degrees: Any,
    faces: Any,
) -> tuple[np.ndarray, np.ndarray]:
    """Convert a conforming polygon mesh into a conforming quad-only mesh.

    Each source face receives one center vertex. Each unique source edge receives
    one shared midpoint. A source n-gon then becomes n quads, one around each
    original corner. Sharing edge midpoint vertices prevents T-junctions between
    adjacent source faces.
    """
    vertex_array = np.asarray(vertices, dtype=np.float64)
    degree_array = np.asarray(degrees, dtype=np.int64).reshape(-1)
    face_array = np.asarray(faces, dtype=np.int64)

    if vertex_array.ndim != 2 or vertex_array.shape[1] != 3:
        raise ValueError("Native remesh output vertices must have shape (#V, 3).")
    if face_array.ndim != 2:
        raise ValueError("Native remesh output faces must be a two-dimensional array.")
    if degree_array.shape[0] != face_array.shape[0]:
        raise ValueError("Native remesh output contains inconsistent polygon arrays.")
    if not np.isfinite(vertex_array).all():
        raise ValueError("Native remesh output contains non-finite vertex coordinates.")

    output_vertices = [vertex.copy() for vertex in vertex_array]
    output_faces: list[tuple[int, int, int, int]] = []
    edge_midpoints: dict[tuple[int, int], int] = {}

    for row, degree_value in zip(face_array, degree_array, strict=True):
        degree = int(degree_value)
        if degree < 3 or degree > row.shape[0]:
            raise ValueError("Native remesh output contains an invalid polygon degree.")

        polygon = [int(index) for index in row[:degree]]
        if any(index < 0 or index >= vertex_array.shape[0] for index in polygon):
            raise ValueError("Native remesh output contains an invalid vertex index.")
        if len(set(polygon)) != degree:
            raise ValueError("Native remesh output contains a degenerate polygon.")

        center_index = len(output_vertices)
        output_vertices.append(vertex_array[polygon].mean(axis=0))

        midpoint_indices: list[int] = []
        for corner, first in enumerate(polygon):
            second = polygon[(corner + 1) % degree]
            edge = (min(first, second), max(first, second))
            midpoint_index = edge_midpoints.get(edge)
            if midpoint_index is None:
                midpoint_index = len(output_vertices)
                output_vertices.append(
                    0.5 * (vertex_array[first] + vertex_array[second])
                )
                edge_midpoints[edge] = midpoint_index
            midpoint_indices.append(midpoint_index)

        for corner, vertex_index in enumerate(polygon):
            output_faces.append(
                (
                    vertex_index,
                    midpoint_indices[corner],
                    center_index,
                    midpoint_indices[(corner - 1) % degree],
                )
            )

    if not output_faces:
        raise ValueError("Native remesh output contains no polygons.")

    return (
        np.ascontiguousarray(output_vertices, dtype=np.float64),
        np.ascontiguousarray(output_faces, dtype=np.int64),
    )


def _write_quad_obj(
    path: Path,
    vertices: np.ndarray,
    faces: np.ndarray,
) -> None:
    with path.open("w", encoding="utf-8", newline="\n") as stream:
        for x, y, z in vertices:
            stream.write(f"v {x:.17g} {y:.17g} {z:.17g}\n")
        for face in faces:
            indices = " ".join(str(int(index) + 1) for index in face)
            stream.write(f"f {indices}\n")


def _write_quad_off(
    path: Path,
    vertices: np.ndarray,
    faces: np.ndarray,
) -> None:
    with path.open("w", encoding="utf-8", newline="\n") as stream:
        stream.write("OFF\n")
        stream.write(f"{vertices.shape[0]} {faces.shape[0]} 0\n")
        for x, y, z in vertices:
            stream.write(f"{x:.17g} {y:.17g} {z:.17g}\n")
        for face in faces:
            indices = " ".join(str(int(index)) for index in face)
            stream.write(f"4 {indices}\n")


def _triangulate_quads(faces: np.ndarray) -> np.ndarray:
    triangles = np.empty((faces.shape[0] * 2, 3), dtype=np.int64)
    triangles[0::2] = faces[:, (0, 1, 2)]
    triangles[1::2] = faces[:, (0, 2, 3)]
    return triangles


def _write_mesh(path: Path, vertices: Any, degrees: Any, faces: Any) -> None:
    suffix = path.suffix.lower()
    if not suffix:
        raise ValueError("Mesh output requires a file extension.")

    quad_vertices, quad_faces = _quadrangulate_polygons(
        vertices,
        degrees,
        faces,
    )
    path.parent.mkdir(parents=True, exist_ok=True)

    if suffix == ".obj":
        _write_quad_obj(path, quad_vertices, quad_faces)
        return
    if suffix == ".off":
        _write_quad_off(path, quad_vertices, quad_faces)
        return

    # trimesh.Trimesh stores triangular faces. OBJ and OFF are handled above
    # because those formats can preserve four-corner polygon records directly.
    mesh = trimesh.Trimesh(
        vertices=quad_vertices,
        faces=_triangulate_quads(quad_faces),
        process=False,
    )
    try:
        mesh.export(path)
    except Exception as exc:
        raise ValueError(
            f"Trimesh cannot export mesh format '{suffix}'."
        ) from exc


def _cmd_info(_args: argparse.Namespace) -> int:
    print(f"directional {_package_version()}")
    try:
        _load_native_module()
    except RuntimeError as exc:
        print(f"native extension: unavailable ({exc})")
    else:
        print("native extension: available")
    return 0


def _cmd_convert_field(args: argparse.Namespace) -> int:
    output = convert_field(
        args.input,
        args.output,
        input_format=infer_input_format(args.input, args.input_format),
        output_format=args.output_format,
        mesh_path=args.mesh,
        degree=args.degree,
    )
    print(f"Wrote {output}")
    return 0


def _cmd_cross_field(args: argparse.Namespace) -> int:
    native = _load_native_module()
    data, _mesh = _load_mesh_input(args.input)
    result = native.extract_cross_field(
        data["vertices"],
        data["faces"],
        _make_cross_field_options(args),
    )
    _write_field_result(args.output, args.output_format, result)
    if args.verbose:
        print(f"Wrote {args.output}")
    return 0


def _cmd_remesh(args: argparse.Namespace) -> int:
    native = _load_native_module()
    data, mesh = _load_mesh_input(args.input)
    vertices = data["vertices"]
    faces = data["faces"]
    options = _make_remesh_options(args)

    if args.field is not None:
        if mesh is None:
            mesh = trimesh.Trimesh(
                vertices=vertices,
                faces=faces,
                process=False,
            )
        raw, primary, secondary = _load_field_for_mesh(
            args.field,
            args.field_format,
            mesh,
        )
        if raw is not None and raw.shape[1] == 12:
            result = native.remesh_from_raw_cross_field(
                vertices,
                faces,
                raw,
                options,
            )
        else:
            result = native.remesh_from_cross_field(
                vertices,
                faces,
                primary,
                secondary,
                options,
            )
    else:
        raw_cross_field = data.get("raw_cross_field")
        primary_directions = data.get("primary_directions")
        secondary_directions = data.get("secondary_directions")
        if raw_cross_field is not None:
            result = native.remesh_from_raw_cross_field(
                vertices,
                faces,
                raw_cross_field,
                options,
            )
        elif primary_directions is not None and secondary_directions is not None:
            result = native.remesh_from_cross_field(
                vertices,
                faces,
                primary_directions,
                secondary_directions,
                options,
            )
        elif primary_directions is not None:
            result = native.remesh_from_cross_field(
                vertices,
                faces,
                primary_directions,
                options,
            )
        else:
            result = native.remesh_from_mesh(vertices, faces, options)

    if not bool(result.success):
        raise RuntimeError("Remeshing failed.")
    _write_mesh(
        args.output,
        result.vertices,
        result.degrees,
        result.faces,
    )
    if args.verbose:
        print(f"Wrote {args.output}")
    return 0


def _add_field_format_argument(
    parser: argparse.ArgumentParser,
    name: str,
    default: str,
) -> None:
    parser.add_argument(
        name,
        choices=("auto", *sorted(FIELD_FORMATS)),
        default=default,
    )


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="directional",
        description="Directional cross-field extraction, conversion, and remeshing tools.",
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    info_parser = subparsers.add_parser(
        "info",
        help="Show package and native extension status.",
    )
    info_parser.set_defaults(func=_cmd_info)

    convert_parser = subparsers.add_parser(
        "convert-field",
        help="Convert between crossfield, rosy, and rawfield files.",
    )
    convert_parser.add_argument("input", type=Path)
    convert_parser.add_argument("output", type=Path, nargs="?")
    _add_field_format_argument(convert_parser, "--input-format", "auto")
    _add_field_format_argument(convert_parser, "--output-format", "crossfield")
    convert_parser.add_argument("--mesh", type=Path)
    convert_parser.add_argument("--degree", type=int, choices=(2, 4), default=4)
    convert_parser.set_defaults(func=_cmd_convert_field)

    cross_parser = subparsers.add_parser(
        "cross-field",
        help="Extract a face-based degree-4 cross field from a mesh.",
    )
    cross_parser.add_argument("input", type=Path)
    cross_parser.add_argument("output", type=Path)
    _add_field_format_argument(cross_parser, "--output-format", "auto")
    cross_parser.add_argument("--no-normalize-directions", action="store_true")
    cross_parser.add_argument("--no-matching", action="store_true")
    cross_parser.add_argument("--verbose", action="store_true")
    cross_parser.set_defaults(func=_cmd_cross_field)

    remesh_parser = subparsers.add_parser(
        "remesh",
        help="Remesh a mesh, optionally using a supplied field file.",
    )
    remesh_parser.add_argument("input", type=Path)
    remesh_parser.add_argument("output", type=Path)
    remesh_parser.add_argument("--field", type=Path)
    _add_field_format_argument(remesh_parser, "--field-format", "auto")
    remesh_parser.add_argument("--length-ratio", type=float, default=0.02)
    remesh_parser.add_argument("--no-integral-seamless", action="store_true")
    remesh_parser.add_argument("--round-seams", action="store_true")
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

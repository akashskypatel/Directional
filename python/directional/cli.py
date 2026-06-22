from __future__ import annotations

import argparse
import sys
from importlib import metadata
from pathlib import Path
from typing import Any

import numpy as np


_NATIVE_NAMES = (
    "RemeshOptions",
    "remesh_from_cross_field",
    "remesh_from_raw_cross_field",
)


def _package_version() -> str:
    try:
        return metadata.version("directional")
    except metadata.PackageNotFoundError:
        return "0.1.0"


def _load_native_api() -> tuple[type[Any], Any, Any]:
    try:
        from directional import _directional as native
    except ImportError as exc:
        raise RuntimeError(
            "The directional native extension could not be imported. "
            "Build/install the package before running remeshing commands."
        ) from exc

    missing = [name for name in _NATIVE_NAMES if not hasattr(native, name)]
    if missing:
        raise RuntimeError(
            "The directional native extension is not available. "
            f"Missing symbols: {', '.join(missing)}"
        )

    return (
        native.RemeshOptions,
        native.remesh_from_cross_field,
        native.remesh_from_raw_cross_field,
    )


def _load_input(path: Path) -> dict[str, np.ndarray]:
    if path.suffix.lower() != ".npz":
        raise ValueError("Input must be a .npz file.")

    with np.load(path) as data:
        return {key: data[key] for key in data.files}


def _require_array(data: dict[str, np.ndarray], key: str) -> np.ndarray:
    if key not in data:
        raise ValueError(f"Input .npz is missing required array: {key}")
    return data[key]


def _optional_array(data: dict[str, np.ndarray], key: str) -> np.ndarray | None:
    return data.get(key)


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
    }
    for output_name, candidate_names in fields.items():
        value = _result_array(result, *candidate_names)
        if value is not None:
            payload[output_name] = value
    return payload


def _cmd_info(_args: argparse.Namespace) -> int:
    print(f"directional {_package_version()}")
    try:
        _load_native_api()
    except RuntimeError as exc:
        print(f"native extension: unavailable ({exc})")
    else:
        print("native extension: available")
    return 0


def _cmd_remesh(args: argparse.Namespace) -> int:
    _, remesh_from_cross_field, remesh_from_raw_cross_field = _load_native_api()
    data = _load_input(args.input)
    vertices = _require_array(data, "vertices")
    faces = _require_array(data, "faces")
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
        raise ValueError(
            "Input .npz must contain either raw_cross_field or primary_directions."
        )

    args.output.parent.mkdir(parents=True, exist_ok=True)
    np.savez_compressed(args.output, **_result_payload(result))
    if args.verbose:
        print(f"Wrote {args.output}")
    return 0


def _build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="directional",
        description="Command line tools for the Directional remeshing library.",
    )
    subparsers = parser.add_subparsers(dest="command", required=True)

    info_parser = subparsers.add_parser("info", help="Show package and native extension status.")
    info_parser.set_defaults(func=_cmd_info)

    remesh_parser = subparsers.add_parser(
        "remesh",
        help="Run the headless remeshing pipeline from a .npz input file.",
    )
    remesh_parser.add_argument("input", type=Path, help="Input .npz file.")
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

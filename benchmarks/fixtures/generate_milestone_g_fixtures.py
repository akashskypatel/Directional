#!/usr/bin/env python3
"""Generate analytic Milestone G fixtures and verify committed external assets."""

from __future__ import annotations

import hashlib
import json
import math
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, Hashable

Vec3 = tuple[float, float, float]


def add(a: Vec3, b: Vec3) -> Vec3:
    return (a[0] + b[0], a[1] + b[1], a[2] + b[2])


def sub(a: Vec3, b: Vec3) -> Vec3:
    return (a[0] - b[0], a[1] - b[1], a[2] - b[2])


def mul(a: Vec3, scale: float) -> Vec3:
    return (a[0] * scale, a[1] * scale, a[2] * scale)


def dot(a: Vec3, b: Vec3) -> float:
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]


def cross(a: Vec3, b: Vec3) -> Vec3:
    return (
        a[1] * b[2] - a[2] * b[1],
        a[2] * b[0] - a[0] * b[2],
        a[0] * b[1] - a[1] * b[0],
    )


def norm(a: Vec3) -> float:
    return math.sqrt(dot(a, a))


def normalize(a: Vec3) -> Vec3:
    length = norm(a)
    if length <= 1.0e-12:
        raise ValueError("near-zero vector")
    return mul(a, 1.0 / length)


def tangent_on_triangle(direction: Vec3, a: Vec3, b: Vec3, c: Vec3) -> Vec3:
    normal = normalize(cross(sub(b, a), sub(c, a)))
    projected = sub(direction, mul(normal, dot(direction, normal)))
    if norm(projected) <= 1.0e-10:
        projected = sub(b, a)
    return normalize(projected)


def balanced_cross_axes(
    primary_direction: Vec3,
    secondary_direction: Vec3,
    a: Vec3,
    b: Vec3,
    c: Vec3,
) -> tuple[Vec3, Vec3]:
    """Fit an orthogonal cross equally to the two source-cell side families."""

    normal = normalize(cross(sub(b, a), sub(c, a)))
    primary = tangent_on_triangle(primary_direction, a, b, c)
    secondary_target = tangent_on_triangle(secondary_direction, a, b, c)
    primary_orthogonal = normalize(cross(normal, primary))
    if dot(primary_orthogonal, secondary_target) < 0.0:
        secondary_target = mul(secondary_target, -1.0)

    angle = math.atan2(
        dot(secondary_target, primary_orthogonal),
        dot(secondary_target, primary),
    )
    rotation = 0.5 * (angle - 0.5 * math.pi)
    axis_x = normalize(
        add(mul(primary, math.cos(rotation)),
            mul(primary_orthogonal, math.sin(rotation)))
    )
    axis_y = normalize(cross(normal, axis_x))
    return axis_x, axis_y


@dataclass
class MeshBuilder:
    vertices: list[Vec3] = field(default_factory=list)
    faces: list[tuple[int, int, int]] = field(default_factory=list)
    fields: list[tuple[Vec3, Vec3]] = field(default_factory=list)
    vertex_by_key: dict[Hashable, int] = field(default_factory=dict)

    def vertex(self, key: Hashable, position: Vec3) -> int:
        existing = self.vertex_by_key.get(key)
        if existing is not None:
            old = self.vertices[existing]
            if norm(sub(old, position)) > 1.0e-9:
                raise ValueError(f"inconsistent position for key {key!r}")
            return existing
        index = len(self.vertices)
        self.vertex_by_key[key] = index
        self.vertices.append(position)
        return index

    def add_quad(
        self,
        keys: tuple[Hashable, Hashable, Hashable, Hashable],
        positions: tuple[Vec3, Vec3, Vec3, Vec3],
        outward_hint: Vec3 | None = None,
        *,
        balanced: bool = True,
    ) -> None:
        k00, k10, k11, k01 = keys
        p00, p10, p11, p01 = positions
        normal = cross(sub(p10, p00), sub(p01, p00))
        if outward_hint is not None and dot(normal, outward_hint) < 0.0:
            k10, k01 = k01, k10
            p10, p01 = p01, p10

        v00 = self.vertex(k00, p00)
        v10 = self.vertex(k10, p10)
        v11 = self.vertex(k11, p11)
        v01 = self.vertex(k01, p01)
        face_specs = (
            (
                (v00, v10, v11),
                (p00, p10, p11),
                sub(p10, p00),
                sub(p11, p10),
            ),
            (
                (v00, v11, v01),
                (p00, p11, p01),
                sub(p11, p01),
                sub(p01, p00),
            ),
        )
        quad_primary = add(sub(p10, p00), sub(p11, p01))
        quad_secondary = add(sub(p01, p00), sub(p11, p10))
        for face, points, primary_direction, secondary_direction in face_specs:
            self.faces.append(face)
            if balanced:
                axis_x, axis_y = balanced_cross_axes(
                    primary_direction, secondary_direction, *points
                )
            else:
                # Highly curved tube cells are intentionally validated as a
                # difficult/possibly unsupported final-output case, but their
                # committed field must still identify the source-cell lattice
                # without missing candidate pairs. Fit the cross from the
                # whole source quad, then project it into each triangle.
                a, b, c = points
                axis_x = tangent_on_triangle(quad_primary, a, b, c)
                face_normal = normalize(cross(sub(b, a), sub(c, a)))
                axis_y = normalize(cross(face_normal, axis_x))
            self.fields.append((axis_x, axis_y))


def write_fixture(root: Path, name: str, mesh: MeshBuilder) -> tuple[Path, Path]:
    mesh_path = root / f"{name}.obj"
    field_path = root / f"{name}.rawfield"
    with mesh_path.open("w", encoding="utf-8", newline="\n") as stream:
        stream.write(f"# Deterministic Milestone G fixture: {name}\n")
        for x, y, z in mesh.vertices:
            stream.write(f"v {x:.17g} {y:.17g} {z:.17g}\n")
        for a, b, c in mesh.faces:
            stream.write(f"f {a + 1} {b + 1} {c + 1}\n")
    with field_path.open("w", encoding="utf-8", newline="\n") as stream:
        stream.write(f"4 {len(mesh.faces)}\n")
        for primary, secondary in mesh.fields:
            vectors = (primary, secondary, mul(primary, -1.0), mul(secondary, -1.0))
            stream.write(" ".join(f"{value:.17g}" for vector in vectors for value in vector))
            stream.write("\n")
    return mesh_path, field_path


def plane(nx: int, ny: int, *, prefix: str = "plane", z: float = 0.0) -> MeshBuilder:
    mesh = MeshBuilder()
    for y in range(ny):
        for x in range(nx):
            keys = tuple(
                (prefix, i, j)
                for i, j in ((x, y), (x + 1, y), (x + 1, y + 1), (x, y + 1))
            )
            positions = tuple((float(i) / nx, float(j) / ny, z) for _, i, j in keys)
            mesh.add_quad(keys, positions, (0.0, 0.0, 1.0))
    return mesh


def cylinder(nu: int, nv: int) -> MeshBuilder:
    mesh = MeshBuilder()
    for j in range(nv):
        z0 = -1.0 + 2.0 * j / nv
        z1 = -1.0 + 2.0 * (j + 1) / nv
        for i in range(nu):
            i1 = (i + 1) % nu
            t0 = 2.0 * math.pi * i / nu
            t1 = 2.0 * math.pi * i1 / nu
            keys = (("c", i, j), ("c", i1, j), ("c", i1, j + 1), ("c", i, j + 1))
            positions = (
                (math.cos(t0), math.sin(t0), z0),
                (math.cos(t1), math.sin(t1), z0),
                (math.cos(t1), math.sin(t1), z1),
                (math.cos(t0), math.sin(t0), z1),
            )
            hint = normalize(add(add(positions[0], positions[1]), add(positions[2], positions[3])))
            mesh.add_quad(keys, positions, hint)
    return mesh


def torus(nu: int, nv: int, major: float = 1.6, minor: float = 0.55) -> MeshBuilder:
    mesh = MeshBuilder()

    def position(i: int, j: int) -> Vec3:
        u = 2.0 * math.pi * (i % nu) / nu
        v = 2.0 * math.pi * (j % nv) / nv
        radial = major + minor * math.cos(v)
        return (radial * math.cos(u), radial * math.sin(u), minor * math.sin(v))

    for j in range(nv):
        for i in range(nu):
            i1, j1 = (i + 1) % nu, (j + 1) % nv
            keys = (("t", i, j), ("t", i1, j), ("t", i1, j1), ("t", i, j1))
            positions = tuple(position(a, b) for _, a, b in keys)
            u = 2.0 * math.pi * (i + 0.5) / nu
            v = 2.0 * math.pi * (j + 0.5) / nv
            hint = (math.cos(u) * math.cos(v), math.sin(u) * math.cos(v), math.sin(v))
            mesh.add_quad(keys, positions, hint)
    return mesh


def bent_tube(nu: int, nv: int) -> MeshBuilder:
    mesh = MeshBuilder()

    def frame(i: int) -> tuple[Vec3, Vec3, Vec3]:
        angle = -0.75 * math.pi + 1.5 * math.pi * i / nu
        center = (1.5 * math.cos(angle), 0.0, 1.5 * math.sin(angle))
        normal = normalize((math.cos(angle), 0.0, math.sin(angle)))
        binormal = (0.0, 1.0, 0.0)
        return center, normal, binormal

    def position(i: int, j: int) -> Vec3:
        center, normal, binormal = frame(i)
        angle = 2.0 * math.pi * (j % nv) / nv
        radius = 0.22
        return add(center, add(mul(normal, radius * math.cos(angle)),
                               mul(binormal, radius * math.sin(angle))))

    for i in range(nu):
        for j in range(nv):
            j1 = (j + 1) % nv
            keys = (("b", i, j), ("b", i + 1, j), ("b", i + 1, j1), ("b", i, j1))
            positions = tuple(position(a, b) for _, a, b in keys)
            center, _, _ = frame(i)
            hint = normalize(sub(add(add(positions[0], positions[1]), add(positions[2], positions[3])), mul(center, 4.0)))
            mesh.add_quad(keys, positions, hint, balanced=False)
    return mesh


def close_sheets(nx: int, ny: int) -> MeshBuilder:
    mesh = MeshBuilder()
    for sheet, z, orientation in ((0, -0.035, 1.0), (1, 0.035, -1.0)):
        for y in range(ny):
            for x in range(nx):
                coords = ((x, y), (x + 1, y), (x + 1, y + 1), (x, y + 1))
                keys = tuple(("s", sheet, i, j) for i, j in coords)
                positions = tuple((float(i) / nx, float(j) / ny, z) for i, j in coords)
                mesh.add_quad(keys, positions, (0.0, 0.0, orientation))
    return mesh


def cube_surface(n: int, mapping: Callable[[Vec3], Vec3]) -> MeshBuilder:
    mesh = MeshBuilder()
    faces = (
        ("px", lambda u, v: (n, u, v)),
        ("nx", lambda u, v: (0, u, v)),
        ("py", lambda u, v: (u, n, v)),
        ("ny", lambda u, v: (u, 0, v)),
        ("pz", lambda u, v: (u, v, n)),
        ("nz", lambda u, v: (u, v, 0)),
    )

    def physical(key: tuple[int, int, int]) -> Vec3:
        cube = tuple(-1.0 + 2.0 * value / n for value in key)
        return mapping(cube)  # type: ignore[arg-type]

    for _, key_fn in faces:
        for v in range(n):
            for u in range(n):
                keys = (key_fn(u, v), key_fn(u + 1, v), key_fn(u + 1, v + 1), key_fn(u, v + 1))
                positions = tuple(physical(key) for key in keys)
                hint = normalize(tuple(sum(position[axis] for position in positions) for axis in range(3)))
                mesh.add_quad(keys, positions, hint)
    return mesh


def sphere_mapping(cube: Vec3) -> Vec3:
    return normalize(cube)


def mechanical_mapping(cube: Vec3) -> Vec3:
    x, y, z = cube
    panel = 0.06 * math.cos(math.pi * x) * math.cos(math.pi * z) if y < -0.99 else 0.0
    return (1.4 * x, 0.72 * y - panel, 0.9 * z)


def seam_fixture(nx: int, ny: int) -> MeshBuilder:
    mesh = plane(nx, ny, prefix="seam")
    for face, (primary, secondary) in enumerate(mesh.fields):
        cell = face // 2
        x = cell % nx
        if x >= nx // 2:
            mesh.fields[face] = (secondary, mul(primary, -1.0))
    return mesh


def sha256(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for chunk in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(chunk)
    return digest.hexdigest()


def main() -> None:
    script = Path(__file__).resolve()
    fixture_root = script.parent / "milestone-g"
    repository_root = script.parents[2]
    fixture_root.mkdir(parents=True, exist_ok=True)

    generated: dict[str, tuple[Path, Path]] = {}
    generated["plane"] = write_fixture(fixture_root, "plane", plane(4, 3))
    generated["cylinder"] = write_fixture(fixture_root, "cylinder", cylinder(16, 4))
    generated["torus"] = write_fixture(fixture_root, "torus", torus(12, 6))
    generated["thin_bent_tube"] = write_fixture(fixture_root, "thin_bent_tube", bent_tube(10, 12))
    generated["close_sheets"] = write_fixture(fixture_root, "close_sheets", close_sheets(3, 3))
    sphere = cube_surface(4, sphere_mapping)
    generated["sphere_prescribed"] = write_fixture(fixture_root, "sphere_prescribed", sphere)
    generated["multi_face_seam"] = write_fixture(fixture_root, "multi_face_seam", seam_fixture(4, 4))
    generated["mechanical_feature"] = write_fixture(fixture_root, "mechanical_feature", cube_surface(5, mechanical_mapping))

    bunny_mesh = fixture_root / "bunny_1k_random.obj"
    vase_mesh = fixture_root / "vase.off"
    for required_mesh, description in (
        (bunny_mesh, "random-triangulation bunny regression"),
        (vase_mesh, "open-boundary vase production"),
    ):
        if not required_mesh.is_file():
            raise FileNotFoundError(
                f"Required committed {description} asset is missing: "
                f"{required_mesh}"
            )

    corner_keys = tuple((x, y, z) for x in (0, 4) for y in (0, 4) for z in (0, 4))
    singular_vertices = sorted(sphere.vertex_by_key[key] for key in corner_keys)
    metadata_path = fixture_root / "sphere_prescribed.fieldmeta.json"
    metadata_path.write_text(
        json.dumps(
            {
                "degree": 4,
                "singular_vertices": singular_vertices,
                "singular_indices": [1] * len(singular_vertices),
                "index_convention": "degree-4 integer numerator; valence = 4 - index",
            },
            indent=2,
            sort_keys=True,
        )
        + "\n",
        encoding="utf-8",
    )

    license_path = fixture_root / "LICENSE.md"
    license_path.write_text(
        "# Milestone G fixture licensing\n\n"
        "The analytic meshes and cross fields stored in this directory are "
        "deterministic project-authored fixtures generated by "
        "`generate_milestone_g_fixtures.py` and may be used under the same "
        "license as Directional.\n\n"
        "`bunny_1k_random.obj` and `vase.off` are externally supplied "
        "production regression artifacts and are intentionally not generated "
        "or modified by the fixture script. Their benchmarks intentionally "
        "omit prescribed fields so Directional must calculate the cross field. "
        "Redistribution must follow the provenance and license terms recorded "
        "by the repository maintainer; this fixture record does not assert "
        "that either mesh is project-authored.\n",
        encoding="utf-8",
    )

    asset_paths = [path for pair in generated.values() for path in pair]
    asset_paths.extend((bunny_mesh, vase_mesh, metadata_path, license_path, script))
    manifest = {
        "generator": str(script.relative_to(repository_root)).replace("\\", "/"),
        "assets": [
            {
                "path": str(path.relative_to(repository_root)).replace("\\", "/"),
                "sha256": sha256(path),
                "bytes": path.stat().st_size,
            }
            for path in sorted(asset_paths)
        ],
    }
    (fixture_root / "asset-manifest.json").write_text(
        json.dumps(manifest, indent=2, sort_keys=True) + "\n", encoding="utf-8"
    )


if __name__ == "__main__":
    main()

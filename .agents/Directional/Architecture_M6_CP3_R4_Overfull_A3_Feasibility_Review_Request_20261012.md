# M6-CP3-CB1-ENTRY-R4 — overfull hard-rail/A3 feasibility: independent Review request

**Classification:** source-exact static proof and proposed Definition/Review decision, **not** an accepted normative amendment, test result, or permission to run TB497. Canonical R4 Code + Build continues; the overfull-incidence question remains open until independent Review adjudicates it.

**Source authority:** exact GMP/GMPXX compile-package source `3c1f001fa03dde476222bbad48ae46cfebe12c9a`, workflow [38188542762](https://github.com/akashskypatel/Directional/actions/runs/38188542762), artifact `11720182846`, verified 28/28 manifest and `runtimeExecution=false`. Read the exact source archive; no Directional executable or test was run for this analysis.

## Concrete test and first-check sequence

`tests/SurfaceCellTransitionQuotientTests.cpp:1879-2019` contains `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`. Its three-face negative constructs three distinct triangles containing source edge `(0,1)`, calls `TriMesh::set_mesh`, then attempts an independently built `FieldTransportAtlas::make`. It currently accepts the broad `InvalidSourceAuthority` enum for `count=3`, without proving the later A4 `railIncidenceCounts > 2` check was reached. The one-/two-face controls were strengthened previously and are a separate matter.

The relevant production ordering is:

1. `TriMesh::set_mesh` calls `compute_edge_quantities` (`include/directional/core/TriMesh.h:331-341`).
2. `compute_edge_quantities` invokes `dcel.check_consistency(verbose, true, true, true)` and throws on failure (`TriMesh.h:145-163`).
3. That consistency check rejects **repeated directed halfedges** (`include/directional/core/DCEL.h:1470-1519`).
4. `FieldTransportAtlas` has a private constructor and its public `make` requires the source `TriMesh`, its edge/face adjacency and a matching `SourceTopologyRegions` (`include/directional/authority/FieldTransportAtlas.h:835-910`; `src/authority/FieldTransportAtlas.cpp:1893-1912`).
5. `SurfacePhaseFrontProduct::make` rejects a missing or source-mismatched atlas at entry (`src/geometry/SurfaceCellTracing.cpp:8045-8060`); only **later** does it form and check `railIncidenceCounts` (`:8155-8185`).

## Bounded graph/topology argument

Every triangular face containing the same undirected edge contributes one directed halfedge over that edge, oriented either `0->1` or `1->0`. Three such faces and only two possible directions force at least two identical directed halfedges by the pigeonhole principle, regardless of row order or triangle winding. This violates `DCEL::check_consistency` with `checkHalfedgeRepetition=true`. Consequently the standard source-mesh constructor throws *before* an authenticated A3 can be produced.

Changing face order, reversing triangles, publishing only two of the three face transitions, or omitting the carrier cannot make this source valid. Forging an atlas, bypassing `TriMesh`, or weakening the A4 source-binding gate is expressly outside current authority. A two-face atlas with an added third A4 source row cannot pass `matches_source_faces`, which compares the complete row topology and count (`src/authority/FieldTransportAtlas.cpp:3090-3110`).

**Provisional conclusion:** within the published exact-source `TriMesh -> A3 -> checked A4` construction contract, a *source-valid* fixture that reaches A4's `count>2` hard-rail guard is unrealizable. This is a structural reachability conclusion, not a runtime claim about the current test's throw or first rejection. The guard remains valuable as fail-closed defensive validation and must not be removed.

## Requested independent Definition/Review decision

1. Confirm or refute the above reachability proof against the actual `TriMesh`, DCEL, A3 and A4 contract, including exceptional construction paths if any. A refutation must exhibit a complete reproducible source-valid A3 instance with three same-edge incident faces, not a fabricated relation graph.
2. If confirmed, amend **only** the impossible requirement to verify the A4 `count>2` branch using such a source-valid A3. Retain the existing count guard and its fail-closed semantics. Do not infer a runtime PASS.
3. Authorize a separate, explicitly labeled **producer/source-input** nonmanifold negative that asserts rejection at its actual first check (DCEL/source-validation), and retain independent A4 one-/two-face and absent-carrier source-valid controls. Do not quietly reinterpret those controls as an overfull-A4 predicate test.
4. Decide how to modify the existing *supplemental* test so its three-face cases no longer throw unhandled exceptions or silently pass at an earlier null-A3 gate. Do not rename or alter any frozen-497 selector.
5. Preserve RA-46's separate terminal-path ruling, the source-authoritative A3/A4 gates, and the 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 / six CP3 / genuine odd-τ multi-carrier obligations. Runtime verification belongs to a separately authorized Test + Benchmark turn.

**Disposition:** REQUESTED REVIEW; no production/test source or acceptance ledger modified by this note.

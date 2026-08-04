# Milestone G P5 Post-TB20 Topology, Route, and Completion Code/Build Plan

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-CB126 through P5-CB134 code changes plus compile-only build

## Purpose

Correct the exact producers exposed by P5-TB20 while preserving compact
ownership, typed failures, rollback identity, full-suite termination, and the
face-edge resource improvement. The code/build turn may change source and tests
but must execute no project binary.

## Preserved closures

- compact one-per-complex exact ownership registry;
- unlabeled intrinsic ownership and face-row invariance;
- Phase 16 **39/39** and Phase 17 **26/26**;
- canonical rollback fixture closure;
- malformed midpoint mutation and bit-exact rollback;
- typed domain and incidence evidence;
- rejection of repeated-node/halfedge/non-simple subdivision commits;
- full-suite termination;
- no fallback or source-grid recovery;
- face-edge bunny wall/RSS limits.

## P5-CB126 — restore valid provenance-test geometry

`CompletionVerticesCarrySourceProvenance` currently supplies a zig-zag boundary
`(i, i mod 2, 1)` that is not a simple embedded patch. Replace the fixture with
a simple nondegenerate polygon on `z=1` while retaining the intended component,
sheet, face, barycentric, and position assertions.

Do not weaken `completed_quads_have_simple_embedding`. Add a separate negative
regression proving the old zig-zag/bow-tie geometry is rejected with
`InvalidCompletionQuadEmbedding`.

## P5-CB127 — type and repair the shared-parity precondition

The two-odd-cell fixture is topology-invalid before parity repair.

- run `SurfaceCellIncidenceAudit` and domain audit after canonical ownership;
- report the first invalid cell/halfedge/twin/next and ownership class in the
  fixture assertion;
- correct the manual DCEL only if the fixture contradicts a valid pair of
  adjacent source triangles;
- if canonicalization is wrong, fix production canonicalization instead;
- require a valid baseline before invoking parity repair;
- atomically split the shared interface and rebuild both cells plus exterior
  cycle;
- prove exact rollback on any failed mutation.

Do not make parity repair accept an invalid baseline.

## P5-CB128 — repair the open-cylinder non-disk cell

Typed evidence is `non-disk-cell`, cell `0`, halfedge `43`, twin `42`, next
`29`.

- trace cell 0's ordered cycle through periodic seam canonicalization;
- rebuild from directed DCEL adjacency, not position or row order;
- preserve twin and predecessor symmetry;
- retain one connected open cylinder, Euler characteristic 0, two boundary
  loops, consistent orientation, disk interior cells, and protected rail/strand
  support;
- add face-row and seam-start permutation regressions.

## P5-CB129 — produce a valid alternative after repeated-node rejection

Mechanical, sphere, and face-edge bunny now reject the first invalid
replacement path. Completion still stops.

- record candidate route, orientation, repeated entity, and affected cells;
- enumerate only bounded deterministic alternatives implied by local side-repair
  topology;
- validate every alternative before commit for incidence, simple domain,
  ownership, and source charts;
- choose by deterministic topological key and objective, not fixture IDs,
  counts, or arbitrary subset search;
- return the first typed rejection when all bounded alternatives fail;
- preserve rollback identity and exact diagnostics.

## P5-CB130 — two-layer same-corner ownership and real reuse

The exact-disjoint rule is too permissive for renamed semantic duplicates,
while the valid annular route still fails before cache reuse.

Define route equivalence using both:

1. canonical boundary occurrence intervals and orientation; and
2. canonical embedded source-route/domain ownership derived from source faces,
   charts, and support—not rail/curve numeric names alone.

Requirements:

- reject the duplicated semantic-domain fixture before candidate expansion;
- permit the valid annular parallel route only when its embedded source route is
  genuinely distinct and non-overlapping;
- prevent duplicate stitched output after structural repair;
- rebind cached completions to current canonical node/halfedge identities;
- validate rebind before counting reuse;
- produce genuine `reused > 0` and `recomputed > 0` in both guaranteed reuse
  tests;
- never synthesize counters.

## P5-CB131 — restore pipeline stage and fallback lineage

Modify `RemeshPipeline.cpp` directly.

- preserve completion producer and completion validation as real stages;
- apply injected optimization or validation failure at the declared stage only
  after preceding stages legitimately complete;
- preserve the earliest genuine producer failure when completion is invalid;
- make fixtures intended to reach later injection stages construct a valid
  completed checkpoint rather than bypass validation;
- preserve original failure, terminal failure, fallback cause, last-valid-stage
  artifacts, and debug lineage;
- keep `Fail`, `ReturnInputMesh`, and legacy behavior explicit;
- report `CompletedSurfaceCells` only for a valid selected checkpoint.

## P5-CB132 — classify and repair local completion embedding

Current failures identify only `localQuad=<n>`. Extend typed evidence with:

- owning patch/cell;
- backend and bounded variant;
- local and canonical global corner identities;
- repeated vertex, zero-area, bow-tie, orientation reversal, or nonfinite
  classification;
- source component/sheet and supporting source faces.

Repair the actual completion producer for:

- general bounded fallback local quad 0;
- cylinder local quad 1;
- thin tube local quad 0;
- smooth bunny local quad 0.

Use only bounded deterministic variants. Do not disable validation or delete an
invalid face after assembly.

## P5-CB133 — enforce source-sheet-consistent global stitching and inventory

Plane, seam, and close-sheets now fail `LocalSheetMismatch` after producing 12,
24, and 34 quads.

- select corner provenance from the owning patch's exact source component/sheet;
- require adjacent completed faces to agree on shared source-chart occurrences;
- distinguish source-sheet mismatch, source-face leakage, duplicate face,
  reversed duplicate, and transverse intersection;
- reject invalid patch output before global insertion and try only a bounded
  valid template alternative;
- resolve torus `IncompleteSurfaceCellComplex` using the exact first unresolved
  patch/inventory reason;
- retain authoritative ownership arbitration across patches.

## P5-CB134 — telemetry, regressions, and compile/package gate

Extend simultaneous memory accounting for active/rollback/prepared complexes,
descriptors, route candidates, completion inventories, cache products, retained
vector capacity, allocator/runtime, mapped files, and an explicit unexplained
remainder. Measure all categories from the same sample as RSS. Do not sum phase
maxima.

Compile-valid regressions must cover:

- valid provenance fixture and invalid zig-zag fixture;
- typed valid shared-parity baseline and conforming transaction;
- open-cylinder seam/cycle permutations;
- repeated-node alternate route selection and all-invalid rollback;
- semantic duplicate rejection versus valid annular route;
- genuine reuse/recompute accounting;
- pipeline injection/fallback lineage;
- typed local embedding classification;
- source-sheet-consistent stitching;
- torus first unresolved inventory;
- memory-accounting invariants.

### Compile/package boundary

- shallow-initialize recursive submodules;
- clean Ninja Release;
- compile exactly:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`;
- execute no compiled project binary;
- require empty source status;
- package source, binaries/libraries, fixtures, submodules, checksums, and logs;
- initialize persistent logging before fallible work;
- always upload a separate detailed log artifact.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

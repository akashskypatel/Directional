# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB20 artifact-only runtime validation is complete. P5 remains open.

Tested checkpoint:

- exact source `bc8ed616adfe59d4a3e0d5dca8ef7503d3c00e83`;
- implementation commit `a8f8971766f55cf11828a1ae90daad3b98b50664`;
- artifact `8879272440`,
  `surface-cell-p5-cb125-github-source-linux-release`;
- SHA-256
  `bb9aca3881727093411f7f1012dbae9a65e1d62805a4c5a4900af58bd8f7fc76`;
- empty source status;
- checksums **40/40**;
- fixture files **26**;
- recursive submodule records **9**.

No configure, build, relink, patch, regeneration, or source modification
occurred during P5-TB20.

The next turn is **P5-CB126 through P5-CB134 code changes + compile-only
build**. Execute no test, benchmark, custom mesh, help/list/discovery command, or
compiled project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB20_Topology_Route_Completion_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb20-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB20_Topology_Route_Completion_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_CB117_CB125_Code_Build_Report.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Runtime result

Closed:

- package integrity;
- Phase 16 **39/39** and Phase 17 **26/26**;
- canonical rollback baseline;
- typed cylinder incidence evidence;
- rejection and exact rollback for repeated-node/halfedge/non-simple
  replacement commits;
- full-suite termination: **581/599** in 103.05 s, maximum RSS 529,739,776 B;
- four stable face-edge failed runs within established wall/RSS limits;
- no fallback or source-grid recovery.

Open or regressed:

- Phase 14–18 **234/235** because the provenance test fixture is geometrically
  invalid;
- 18 full-suite failures;
- shared-edge parity fixture invalid before mutation;
- cylinder DCEL `non-disk-cell`, cell 0, halfedge 43, twin 42, next 29;
- repeated-node proposals reject but no valid alternate path is selected;
- same-corner arbitration accepts renamed semantic duplicates and still does
  not reach cache reuse (`0/0`);
- pipeline stage/injection/fallback lineage;
- all eight production fixtures;
- smooth second run exceeds the wall limit, so four-run determinism is not
  established;
- at least 75% same-sample memory reconciliation.

## Earliest typed producers

### Shared parity

`SharedEdgeParityRepairConforminglyCompletesTwoOddCells` fails its initial
`topologyValid` assertion. Audit the canonicalized manual fixture before parity
mutation. Correct an invalid fixture field or production canonicalization;
never allow parity repair to consume an invalid baseline.

### Open cylinder

`CylindricalOpenStrandCommitsWithTopologyPreserved` reports:

`non-disk-cell cell=0 halfedge=43 twin=42 next=29`.

Rebuild the periodic cell cycle from directed DCEL adjacency while preserving
Euler 0, two boundary loops, orientation, and protected rails.

### Repeated-node replacement paths

- mechanical: cell 2, halfedge 719, node 65, source face 109;
- sphere: cell 2, halfedge 37, node 13, source face 7;
- face-edge bunny: cell 2, halfedge 45, node 20, source face 0.

False successful commit is fixed. Add a bounded deterministic conforming
alternative rather than only rejecting the first invalid route.

### Same-corner and reuse

The renamed duplicate-domain fixture is now incorrectly accepted. The valid
annular route still fails with `same-corner-distinct-boundary` duplicate output.
Use both exact boundary occurrences and canonical embedded source-route/domain
ownership. Raw rail/curve IDs cannot distinguish semantic duplicates. Rebind
and validate real cached completions before incrementing counters.

### Completion geometry and provenance

The provenance test uses `(i, i mod 2, 1)`, a non-simple boundary. Replace it
with valid simple geometry and retain a separate negative regression.

Real producer failures:

- general fallback: invalid local quad 0;
- cylinder: invalid local quad 1;
- thin tube: invalid local quad 0;
- smooth bunny: invalid local quad 0;
- plane/seam/close sheets: `LocalSheetMismatch` after 12/24/34 quads;
- torus: incomplete complex.

Extend local embedding diagnostics with owning patch, backend, variant, corner
identity, and exact classification before repairing bounded template output.

### Pipeline and resources

`RemeshPipeline.cpp` remains unchanged; GP23/GP24/Phase20 stage-lineage failures
remain. Smooth runs complete with the same failed signature at 31.545 and
45.549 s; the second exceeds the 39.228299 s limit. Face-edge peak working set
is about 141 MB, improved from about 204 MB in TB19. Memory coverage is about
27% face-edge and 39% smooth.

## Required next work

Follow P5-CB126–P5-CB134 in the post-TB20 plan, in order:

1. valid provenance fixture plus negative zig-zag regression;
2. typed shared-parity baseline and conforming transaction;
3. cylinder non-disk periodic cycle repair;
4. valid bounded alternative after repeated-node rejection;
5. two-layer same-corner identity and genuine reuse;
6. pipeline stage/injection/fallback lineage;
7. typed local embedding producer repair;
8. source-sheet-consistent stitching and incomplete inventory;
9. memory telemetry, regression sources, and four-target compile/package gate.

## Compile-only boundary

Shallow-initialize recursive submodules and compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not run them. Initialize detailed workflow logging before fallible work and
always upload a separate log artifact under `if: always()`.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- A validator can expose an invalid test fixture; fix the fixture when its
  geometry does not exercise the intended contract.
- Rejecting an invalid transaction is necessary but does not complete the
  producer; a valid bounded alternative is still required.
- Geometric coincidence and renamed route IDs are insufficient ownership proof.
- Local validity does not imply source-sheet-consistent global stitching.
- Stable failed output and reduced memory are progress, not successful
  quadrangulation.

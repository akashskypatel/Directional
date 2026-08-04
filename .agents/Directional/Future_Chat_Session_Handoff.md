# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB21 artifact-only runtime validation is complete. P5 remains open.

Tested checkpoint:

- exact source `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- implementation commit `01788193457e60bb8817a40b2c1551e672c4de5c`;
- artifact `8890167812`, `surface-cell-p5-cb134-github-source-linux-release`;
- SHA-256 `34a4da9a9c9e3374ed861c41b72493beefc90afbc85743fd25979484f3222bf1`;
- empty source status;
- checksums **41/41**;
- fixture files **26**;
- recursive submodules **9**.

No configure, build, relink, patch, regeneration, or source modification occurred during P5-TB21.

The next turn is **P5-CB135 through P5-CB142 code changes + compile-only build**. Execute no test, benchmark, custom mesh, help/list/discovery command, or compiled project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB21_Artifact_Only_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb21-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB21_Production_Termination_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_CB126_CB134_Code_Build_Report.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB21 runtime result

Closed or improved:

- package authority;
- Phase 14–18 **236/236**;
- Phase 16 **39/39**;
- Phase 17 **26/26**;
- corrected positive provenance fixture;
- explicit negative zig-zag embedding fixture;
- focused shared-edge parity transaction;
- semantic-only duplicate route rejection;
- typed local embedding evidence;
- explicit torus incomplete inventory.

Open or regressed:

- full suite does not terminate on bunny aggregate cases within 1,200 s and 900 s attempts;
- bounded subset is **583/597** with 14 failures;
- Milestone D **6/7**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase 20 **46/48**;
- production **0/8**;
- positive completion reuse/recompute `0/0`;
- face-edge fourth repetition does not terminate in the resource window;
- smooth run 40.090 s exceeds the 39.228299 s limit;
- same-sample memory measurement unavailable and 75% reconciliation open.

## Earliest authoritative producers

### Alternative repair termination

Three face-edge runs complete in 20.191–22.047 s with the same repeated-node failure. A fourth repetition fails to produce a result within the remaining approximately 257 seconds of a 300-second batch. Full-suite aggregate bunny cases also stall.

The next implementation must bound work by canonical topology states and unique incident alternatives, not elapsed time. Detect repeated states, memoize T-join and boundary validation, report typed exhaustion/cycle evidence, and preserve exact rollback.

### Repeated-node alternatives

- sphere: cell 2, halfedge 37, node 13, source face 7;
- mechanical: cell 2, halfedge 719, node 65, source face 109;
- face-edge bunny: cell 2, halfedge 45, node 20, source face 0.

The initial invalid cycle rejects correctly, but no valid bounded alternative commits.

### Cylinder

`CylindricalOpenStrandCommitsWithTopologyPreserved` remains:

`non-disk-cell cell=0 halfedge=43 twin=42 next=29`

Repair the directed periodic DCEL incidence; do not relabel invalid topology as disk.

### Local completion variants

Typed producers:

- focused fallback: patch 0, bounded-combinatorial variant 23, `degenerate-normal`;
- cylinder: patch 10, pattern variant 25, local quad 1, `bow-tie-intersection`;
- thin tube: patch 108, bounded-combinatorial variant 21, `degenerate-normal`;
- smooth bunny: patch 9181, closed-form variant 0, `degenerate-normal`, source face 406.

Validate each candidate variant before authority and continue only through the existing bounded deterministic catalog.

### Parallel route and reuse

Renamed semantic duplicates reject, but the valid annular/parallel route still fails as `same-corner-distinct-boundary`. The one-candidate budget contract reports zero incremental recomputation and reuse/recompute `0/0`.

Use separate semantic-overlap and stitch-separation identities. Invalidate only changed dependencies and count reuse/recompute only after real validated operations.

### Source-sheet agreement

- plane: 12 quads, `LocalSheetMismatch`, cell 4, face 7;
- multi-face seam: 24 quads, cell 2, face 15;
- close sheets: 34 quads, cell 3, face 13.

Local rebinding is insufficient. Build a global intrinsic source-chart equivalence graph and require shared completed vertices/edges to agree before commit. Keep disconnected close sheets distinct.

### Pipeline lineage

GP23/GP24/Phase20 later-stage fixtures still encounter real completion failure before intended optimization or validation evidence. Correct invalid preceding-stage fixtures or producers; do not bypass completion or reorder production stages.

### Torus and memory

Torus reports:

`IncompleteSurfaceCellComplex;descriptor=22;cell=23;reason=3;attempted=41;failed=2;total=43`

Replace numeric public reason with a stable typed name and repair the missing/infeasible producer.

Memory telemetry honestly reports `sameSampleOwnershipMeasurementAvailable=false`. Implement actual same-timestamp working-set and owned-byte sampling; never sum phase maxima.

## Required next work

Follow P5-CB135–P5-CB142 in the post-TB21 plan, in order:

1. deterministic canonical alternative-state budget and cycle detection;
2. valid repeated-node alternatives;
3. cylinder periodic DCEL repair;
4. valid local completion variants;
5. parallel-route identity and genuine reuse;
6. global source-sheet chart agreement;
7. production-valid stage-injection and failure lineage;
8. torus inventory, same-sample memory sampling, and exact compile/package gate.

## Compile-only boundary

Shallow-initialize recursive submodules and compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not run them. Initialize detailed workflow logging before fallible work and always upload a separate log artifact.

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

- Typed rejection is not enough; the producer must find a valid topologically bounded alternative.
- A search described as bounded can still be operationally unbounded without canonical state deduplication and topology-derived limits.
- Full-suite termination is a production gate; a filtered subset is diagnostic evidence only.
- Route semantic overlap and stitch separation are distinct identities.
- Local source-chart validity does not imply global cross-patch chart agreement.
- Honest unavailable memory measurement is preferable to unsupported coverage, but it does not satisfy reconciliation.

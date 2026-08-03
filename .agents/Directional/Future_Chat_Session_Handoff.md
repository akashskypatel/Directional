# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB15 tested artifact `8866222973` directly without rebuilding. P5 remains open.

- Exact source: `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.
- Digest: `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`.
- Source status empty; checksums **36/36**; fixture closure valid from an arbitrary path.
- Phase 14–18: **230/230 passed**.
- Complete packaged disposition: **579/592 passed**, with 10 assertion failures and 3 signal-11 tests.
- Four face-edge random-bunny processes terminate deterministically within wall and memory limits but fail closed before descriptors at `BoundaryParityRepair:MixedCellSourceScope`.
- The generated-smooth-field production case still exits `139`; stage injection isolates the fault to FlowRep strands after a deterministic `80,862`-segment trace network.
- Next turn: **P5-CB83 through P5-CB90 code changes + compile-only build**.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB15_Parity_Scope_Reuse_Rail_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_Parity_Scope_FlowRep_Reuse_Rail_Code_Build_Plan.md`
5. `benchmark-results/p5-tb15-summary.json`
6. `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Report.md`
7. `benchmark-results/p5-cb82-summary.json`

## P5-TB15 results

Newly passing:

- exact rollback for the real permitted side-repair failure;
- partial multi-edge interface fixture;
- complete multi-edge interface fixture with protected rails.

Still failing:

- both positive exact completion-reuse regressions;
- invalid-midpoint fixture, which currently exercises missing common chart instead;
- final authoritative rail identity;
- topology-invalid cylinder simplification fixture;
- Phase 20 cylinder production output;
- four GP26 end-to-end production cases;
- three generated-smooth-field production-matrix processes with signal 11.

The face-edge random-bunny path now has deterministic bounded simplification:

- wall: `17.594136–19.939944 s`;
- peak working set: `137,039,872–137,162,752 B`;
- trace segments: `12,130`;
- arrangement/simplified cells: `7,405 / 7,405`;
- simplification generations: `5`;
- peak live candidates: `747`;
- fallback/recovery: neither used.

It still emits no descriptors or output because the parity transaction reduces odd cells `1,860 -> 0` only inside a transaction rejected for mixed cell source scope.

## Required next turn

Implement P5-CB83 through P5-CB90 from the parity-scope/FlowRep/reuse/rail plan.

Priorities:

1. Eliminate stale references, unsafe recursion, and ownership faults in high-cardinality FlowRep input, selection, and endpoint completion.
2. Replace parity source-scope frequency voting with one authoritative pre-transaction cell scope inherited by every oriented replacement piece and twin.
3. Define completion reuse identity only from canonical authoritative source-domain dependencies and produce positive exact reuse.
4. Preserve authoritative rail/curve identity and complete provenance to final arrangement halfedges and lineage.
5. Split the missing-chart and invalid-midpoint regressions into valid scenarios; rebuild the cylinder fixture from a valid DCEL without duplicate coincident per-face arcs.
6. Repair remaining plane, cylinder, seam, torus, mechanical-feature, and Phase 20 cylinder producer defects without weakening validation.
7. Add current and peak stage-owned bytes for trace, FlowRep, arrangement, simplification, and completion, avoiding double counting moved buffers.
8. Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no binary.

Preserve all prohibitions: no final-face deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, arbitrary subset search, timeout-as-correctness, or production ID special case.

Workflow files under `.github/workflows` must be changed directly through the GitHub connector, never through a patch-applicator workflow.

# Milestone G Production Readiness TODO

Last updated: 2026-08-03  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`.
- Implementation: `1dab9a0e8915e7d9641c9b005bfa57eaefb4a8cc`.
- Exact compiled source: `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.
- Compile-only run / job: `30839059634` / `91771355792` — success.
- Artifact: `8866222973` (`surface-cell-p5-cb82-mixed-sheet-liveness-linux-release`).
- Digest: `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`.
- Build: **131/131**; source status empty; checksums **36/36**.
- Completed turn: P5-CB75 through P5-CB82.
- Next turn: P5-TB15 artifact-only test and benchmark.

Runtime correctness, positive reuse, signal-11 elimination, liveness, successful output, timing, and successful-path RSS are not claimed.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB50 — initial global-frontier implementation.
- [x] P5-TB11 — complete inventory diagnosis; closure gates failed.
- [x] P5-CB51–P5-CB58 — budget batching, memory lifetime, fixture closure, compile-only artifact.
- [x] P5-TB12 — rollback/result/lifetime diagnosis.
- [x] P5-CB59–P5-CB66 — rollback-integrity implementation and compile-only artifact.
- [x] P5-TB13 — successful-transaction identity, reuse, rail, simplification, lifetime, and wall diagnosis.
- [x] P5-CB67–P5-CB74 — successful-subdivision audit, semantic index, fixed-point API, fixture, rail, and lifetime source changes.
- [x] P5-TB14 — mixed-sheet, rollback, reuse, rail, fixture, liveness, crash, output, and wall diagnosis.
- [x] P5-CB75 — exact component/sheet source-chart identity through successful subdivision.
- [x] P5-CB76 — compact structurally exact rollback restoration and undo-byte reporting.
- [x] P5-CB77 — multi-product semantic reuse buckets with one-time exact consumption.
- [x] P5-CB78 — authoritative rail/curve and complete-provenance rebinding.
- [x] P5-CB79 — explicit valid Milestone D DCEL and complete cylinder incident charts.
- [x] P5-CB80 — generation-bounded, deduplicated, stale-safe simplification frontier.
- [x] P5-CB81 — scoped occurrence and frontier lifetime corrections for the in-pipeline bunny path.
- [x] P5-CB82 — memory diagnostics and compile/package gate.
- [ ] P5-TB15 — artifact-only mixed-sheet/liveness closure validation.
- [ ] P6–P8 — final validation, regression closure, and production disposition.

## Implemented source-sheet contract

- Node occurrences carry exact source face, barycentric coordinates, component, sheet, arc/provenance identity, source interval, and rail/curve interval.
- Every oriented replacement halfedge and its twin select compatible source provenance independently.
- Affected cells are rebound to one deterministic exact component/sheet scope derived from their oriented boundary.
- Missing or mixed cell scope rejects the successful subdivision atomically before descriptor acceptance.
- Structural and pipeline hashes include the extended occurrence identity.

## Rollback, reuse, rail, fixture, and liveness changes

- Rollback restores logical-side metadata and all extended occurrence fields before proving identity; compact undo ownership is reported separately.
- Reusable-product buckets retain multiple products, skip consumed entries, and consume an exact collision-safe dependency match once.
- Rail/curve parameters, source scope, hard-feature classification, and complete provenance survive post-stitch halfedge rebinding.
- The Milestone D multi-edge fixture is an explicit two-interior-cell DCEL with two canonical shared edges and a valid exterior cycle.
- Cylinder arcs are emitted in every incident source-triangle chart.
- Simplification candidates carry generation and semantic identity, are deduplicated per generation, reject stale generations, require monotone edge reduction, and replace rather than append the refreshed frontier.
- Candidate-generation and rollback-undo diagnostics are available in benchmark JSON.

## P5-TB15 gates

- Validate artifact `8866222973` from an arbitrary extraction path without rebuilding.
- Run all 13 P5-TB14 assertion failures and the three former signal-11 tests independently.
- Run focused mixed-sheet, rollback, reuse, rail, simplification, Milestone D, and lifetime regressions.
- Run `PatchDescriptorMilestoneE.*`, Phase 14–18, P23 + Phase 20, Milestone D, and the full packaged binary.
- Require every former crash case to terminate normally alone and in-suite.
- Require the real failed side-repair path to return equal exact rollback identity and structural hashes.
- Require positive exact reuse for unaffected completion products.
- Run at least two formal and two supplementary fresh random-bunny processes with `SurfaceCells`, fallback `Fail`, and recovery disabled.
- Require deterministic termination, valid domain audits, nonzero descriptors, zero ownership conflicts, nonempty pure-quad output, and valid lineage/provenance in all four processes.
- Require no fallback, recovery, partial output, final-face deduplication, positional merge, source-triangle pairing, validator weakening, or ID-specific repair.
- Require wall time `<= 39.228299 s` and peak memory `<= 1,115,394,560 B` in every process.
- Reconcile simplification frontier, reusable-product, rollback-undo, and stage-owned bytes with process RSS.

## Current authority

- `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_TB14_Successful_Subdivision_Identity_Test_Benchmark_Report.md`
- `benchmark-results/p5-cb82-summary.json`
- `benchmark-results/p5-tb14-summary.json`

P5 remains open. PR #8 remains draft and unmerged.

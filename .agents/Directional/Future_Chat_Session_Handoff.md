# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB75 through P5-CB82 implemented mixed-sheet identity, exact rollback, semantic-product, rail, fixture, simplification-frontier, lifetime, and memory-diagnostic changes, then completed a compile-only build. P5 remains open.

- Implementation: `1dab9a0e8915e7d9641c9b005bfa57eaefb4a8cc`.
- Exact compiled source: `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.
- Run / job: `30839059634` / `91771355792` — success.
- Artifact: `8866222973` (`surface-cell-p5-cb82-mixed-sheet-liveness-linux-release`).
- Digest: `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`.
- Build **131/131**; source status empty; checksums **36/36**; fixture files **26**.
- Packaged random bunny: **502 vertices / 1,000 faces**.
- No executable ran.
- Next turn: **P5-TB15 artifact-only test and benchmark**.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_Mixed_Sheet_Liveness_Code_Build_Plan.md`
5. `benchmark-results/p5-cb82-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB14_Successful_Subdivision_Identity_Test_Benchmark_Report.md`
7. `benchmark-results/p5-tb14-summary.json`

## Implemented contracts to validate

- Arrangement-node occurrences carry exact face, barycentric, component, sheet, arc/provenance, source interval, and rail/curve interval identity.
- Oriented replacement halfedges and twins rebind independently to compatible source-sheet provenance.
- Rebuilt cells require one exact deterministic component/sheet scope and fail closed on missing or mixed identity.
- Rollback restores logical-side and extended occurrence state before proving exact identity; compact undo-owned bytes are reported separately.
- Reusable completion-product buckets retain multiple products and consume one exact collision-safe match without moving unmatched payloads.
- Rail/curve parameters, source scope, hard-feature classification, and complete provenance survive final arrangement rebinding.
- Milestone D uses an explicit valid two-cell DCEL; cylinder arcs cover every incident source-triangle chart.
- Simplification uses semantic candidate generations, per-generation deduplication, stale rejection, monotone commits, and frontier replacement rather than stale accumulation.
- Candidate-generation, rollback-undo, and stage-owned memory diagnostics are serialized.

None of these runtime outcomes is proven by this compile-only turn.

## Required next turn

Use artifact `8866222973` directly from an arbitrary extraction path without rebuilding.

1. Verify exact source, empty status, all checksums, fixture closure, binaries, libraries, logs, source archive, and submodules.
2. Run all 13 P5-TB14 assertion-failing tests and all three former signal-11 tests independently.
3. Run focused mixed-sheet, rollback, reuse, rail, simplification, Milestone D, and result-lifetime tests, then every prior authoritative suite and the full packaged binary.
4. Require exact rollback identity and structural-hash equality on the real permitted failed side-repair path.
5. Require positive exact reuse for unaffected completion products.
6. Run two formal and two supplementary fresh `bunny_1k_random.obj` processes with `SurfaceCells`, fallback `Fail`, and recovery disabled.
7. Require every process to terminate deterministically with valid domain audits, nonzero authoritative descriptors, zero ownership conflicts, nonempty pure-quad output, valid lineage/provenance, and no fallback/recovery.
8. Require wall `<= 39.228299 s` and peak memory `<= 1,115,394,560 B` in every process; reconcile frontier, product, undo, and stage-owned bytes with process RSS.

Preserve all prohibitions: no final-face deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, arbitrary subset search, or production ID special case.

Workflow files under `.github/workflows` must be changed directly through the GitHub connector, never through a patch-applicator workflow.

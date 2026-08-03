# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-CB59 through P5-CB66 implemented rollback-integrity, result, reuse, lifetime-isolation, and regression changes, then completed a compile-only build. P5 remains open.

- Implementation: `4dcba533915aad116824f5e47e91a47a440e7718`.
- Exact compiled source: `074ec5d125b531db03fcfbda9d6d3654bfc696b7`.
- Run / job: `30824384650` / `91722103206` — success.
- Artifact: `8860409984` (`surface-cell-p5-cb66-rollback-integrity-linux-release`).
- Digest: `sha256:37c04eaa694a87ed9ab4f48b2123b54f52c0a0d16d8fb9672d367ebdfdbfcee3`.
- Build **131/131**; source status empty; checksums **36/36**; fixture files **26**.
- No executable ran.
- Next turn: **P5-TB13 artifact-only test and benchmark**.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_Rollback_Integrity_Code_Build_Plan.md`
5. `benchmark-results/p5-cb66-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB12_Memory_Frontier_Test_Benchmark_Report.md`
7. `benchmark-results/p5-tb12-summary.json`

## Implemented contracts to validate

- Rejected subdivision and side-repair transactions restore the exact committed complex through a compact undo log and expose before/after identity hashes plus `rollbackEquivalent`.
- Permitted general-completion handoff requires rollback equivalence.
- Inserted nodes preserve source-face support, component, sheet, rail, and hard-barrier identity.
- An initially successful assembly finalizes directly with descriptors, completed patches, quads, and no failure.
- Failures preserve compact descriptors and typed diagnostics while releasing heavy geometry.
- `SameCornerDistinctBoundaryOverlap:` remains typed.
- Exact product reuse ignores allocation-local compact IDs but retains semantic dependencies.
- Explicit simplification transactions do not append unrelated recomputed candidates.
- P26/P27 cases are independently attributable and returned-result ownership is tested after temporary input destruction.

None of these runtime outcomes is yet proven by this compile-only turn.

## Required next turn

Use artifact `8860409984` directly from an arbitrary extraction path without rebuilding.

1. Verify exact source, empty status, all checksums, fixture closure, binaries, libraries, logs, source archive, and submodules.
2. Run focused rollback, descriptor, reuse, semantic-overlap, simplification, lifetime, and matrix-isolation tests.
3. Run all prior authoritative P5 suites, Milestone D, and the full packaged binary. The former P26/P27 signal-11 cases must terminate normally alone and in-suite.
4. Run two formal and two supplementary fresh `bunny_1k_random.obj` processes with `SurfaceCells`, fallback `Fail`, and recovery disabled.
5. Require authoritative descriptors, deterministic zero-conflict nonempty pure-quad output, valid lineage/provenance, no fallback/recovery, and positive unaffected-product reuse where expected.
6. Require wall `<= 39.228299 s` and peak memory `<= 1,115,394,560 B` in every process. Compare successful-path RSS with P5-TB12's early-failure maximum `158,949,376 B` and explain the difference using owned-byte diagnostics.

Preserve all prohibitions: no final-face deduplication, positional merge, source-triangle pairing, fallback, recovery, validator weakening, arbitrary subset search, or production ID special case.

Workflow files under `.github/workflows` must be changed directly through the GitHub connector, never through a patch-applicator workflow.

# P13 nine-cell provenance — isolated Review scratch execution (2026-11-02)

**Owning turn:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`. **This document is Review evidence, not a Code + Build or Test + Benchmark acceptance record.**

## Frozen immutable source and scratch exception

- Production semantic CB76 source: `f59f92f889fc6fe22d689fd7559c024cd09c6c72`. The independently downloaded source snapshot at `898316210ab810daa10d2072db927f9ebe4b2a98` has identical `RemeshPipeline.cpp` SHA-256 `fca712094c21313fddb81f40160b392dbf1ab1888e632fa4f3c00e17b764db12`; archive and 6092/6092 source checksums passed.
- **Exceptional scratch-only branch** `agent/scratch-p13-sliver-provenance-20261102` from exact CB76, source SHA `95684f2e18c3c573dcbf11d35deaad696d0316d3`. Necessary because Review permits a diagnostic probe but forbids production-source mutation; the standard dispatcher compile request can select an exact commit on an isolated branch. This branch must not be merged, promoted or treated as canonical source. It remains temporary until the probe evidence is preserved and branch retirement can be performed by an authorized branch-deletion tool.
- GitHub `compare_commits(f59f92...,95684f...)`: exactly **one source path** `src/pipeline/RemeshPipeline.cpp` changed (+149/−0), no product semantic behavior changes intended. The scratch blob `2cc737e903a5a0b6d1d36a8ef1ba20d10e9e7221` matched the locally computed exact `git hash-object`; original blob `91d681bd98db2f1bbf3767cabd83c03e2a6b0b5e`. The opt-in instrumentation is `DIRECTIONAL_P13_SLIVER_PROBE=1`; no permanent context retention or topology edits.
- Original patch is preserved in the ChatGPT File Library/conversation as `directional-p13-sliver-scratch-probe.patch`, SHA-256 `2deb0780ef3fe3991bbbcda820a7ca286f0826aab5a5e683b2d65b6f03a4c00e`.

## Verified scratch GMP compile

- Triggering working-branch dispatcher request commit `9dafa1680f0dc8cb699780a053c3b58c3cda954b`, operation `compile`, exact source `95684f2e...`, target `directional_surface_cell_producer_tests`. No reusable workflow or permissions edited.
- Workflow `41398086098` **successful**; mailbox key `m6-cp3-p13-sliver-review-scratch-compile-20261102-v1` on dedicated `workflow-mailbox` ref; source/event identities verified. Immutable artifact `13119948654`, ZIP SHA-256 `e283bdb1070dd29658ece5964f2574529ce70e3359f1480d14a37cd44ea0fd7a`, **23/23 packaged checksums PASS**, source SHA exact, exit code 0, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, link evidence includes `gmpxx` and `gmp`. This is **scratch compile evidence only**, not a product build or accepted-green test.
- Artifact backup available to the user as `directional-p13-sliver-scratch-compile-41398086098.zip`.

## Scratch runtime diagnostic

- One fresh local process launched at **2026-11-02T06:12:35Z** from that exact packaged binary with source-archive fixtures supplied adjacent to the executable, environment `DIRECTIONAL_P13_SLIVER_PROBE=1`, gtest filter `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`. This fixture explicitly requests `SurfaceCells`, `fallbackPolicy=Fail`, `allowSourceGridRecovery=false` and `retainIntermediateGeometry=false`. **It is an authorized Review scratch diagnostic, not a formal TB gate.**
- The process is bounded by `timeout -k 10s 390s`; raw stdout/stderr and exit-status files live under `/mnt/data/p13_review_0601/`. No result/ownership claim should be made until terminal evidence and all nine receipts are independently checked.
- Receipt checker `p13_sliver_receipt.py` SHA-256 `2405a11451ac21c3a2b11b9f15145388d8e4a5a8d767fd5b84eb7dd4254ec114`. Optional geometric observational processor `p13_sliver_geometry.py` SHA-256 `7764b0b17165da3fde6722725142c441489d88b73544afbe935141a1eb54d831`, syntax checked, no output yet. Euclidean minima and chords are **not** intrinsic distances or field matching certificates.

## Required Review completion

Capture and independently audit the nine target cells (needles 6095,20533,20968,22350; lenses 26735,26764,26781,26802,26812). Distinguish source-provenance arc selection from arrangement successor pairing, compute same-sheet intrinsic widths and chart-transported field-vs-rail tangent angles where source authority permits. Freeze **one** falsifiable producer owner and exact CB/TB plan only with complete evidence. Do not relax admissibility, modify the frozen selector, claim a successful production output, or mix this diagnostic with accepted TB70 (880/880, membership 961) and CP2 (491/491). P13-e remains independent.

**Closeout rule:** If the scratch process has not delivered adequate evidence by the bounded turn response, preserve this Review as `IN_PROGRESS`, same original Started at `2026-11-02T05:14:30Z`, latest Resumed at `2026-11-02T06:02:10Z`, blank Ended at, and the same-turn successor. No authorized Code + Build successor is named yet.


## Verified terminal scratch observation — 2026-11-02T06:19Z

The direct scratch Vase process exited **1** (expected non-acceptance), with one gtest failure and the same first production terminal as TB70: `NotProductionReady:completion / PatchCompletionRejected / InvalidCompletionQuadEmbedding;patch=6095;backend=closed-form;variant=0;localQuad=1;classification=source-orientation-mismatch`, 192482 traces, 26827 arrangement cells, **0 output quads**, measured 261644 ms. No production acceptance, rebuilt product, fixture or selector gate is claimed.

Independent scratch provenance receipt: **9/9 complete, 0 validation errors**. Needle cells `6095/20533/20968/22350` have 4 sides each, 6/6/9/10 directed halfedges, **no rails**, and span 4/4/2/3 distinct proposal IDs respectively. Lens cells `26735/26764/26781/26802/26812` each have 2 sides, 5 directed halfedges, hard rail `0`, and no proposal IDs. Original retained FlowRep IDs, compact source-arc joins and per-node source-face/chart occurrences are included in the independently checked receipt. The field-trace/hard-rail boundaries pre-exist completion; completion did not invent those arcs. Same-source-face cross-arm/rail chord angle samples include **0.249°, 0.607°, 1.273°, 9.960°, 15.138°, 26.937°**. Opposite-side Euclidean minima (not intrinsic distance) are recorded for all four needles.

**Preserved user-visible evidence:** `directional-p13-sliver-nine-cell-review-evidence.zip`, SHA-256 `3ccb768d4d2871ac94170a102d69b1e3ef949ba26be360d964ef8978fb15cdf2`. Contains raw stdout/stderr/exit receipt, 9/9 provenance JSON, geometry observations JSON, original exact probe patch and the independently auditable scripts/report. Geometric helper's final SHA-256 `c612af85d19e43276a9f7be2963e3a5040434a8941b277672f753c1593f76069` supersedes the provisional helper hash above.

**Unresolved owner:** These observations do NOT establish whether an upstream trace/FlowRep selection admitted incompatible rails/strands or the arrangement selected wrong directed successors. The arrangement has materialized the selected source arcs, and completion correctly fails closed, but a single authoritative corrective producer has **not** been proven. An exact same-sheet intrinsic separation and transported field/rail family-angle certificate remains outstanding. No code patch or successor CB is authorized. Preserve this Review as unfinished. Temporary diagnostic branch must be retired once its reproducibility purpose is served, through authorized branch deletion (not available in the current GitHub connector).

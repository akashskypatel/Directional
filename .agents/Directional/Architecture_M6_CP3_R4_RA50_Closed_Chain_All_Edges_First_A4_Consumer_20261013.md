# M6-CP3-CB1-ENTRY-R4 — closed rail cyclic edge first-consumer validation

Canonical R4 Code + Build continuation; this is not Test + Benchmark or runtime acceptance. Draft PR #8; working branch `agent/surface_cell_quad/p5-recover-bridge-healing`.

## Scope and source authority

Snapshot workflow [38480299675](https://github.com/akashskypatel/Directional/actions/runs/38480299675) captured exact `be6b3bedd0c136ec94587821d7a6705c91d38664`. Artifact `11855913556` outer ZIP SHA256 `91a68ca9727505a618597ff9a5761aa53da3fc4e6119b2666c27de29fd660da7`, embedded source tar SHA256 `db49b5bf61a4263864bcecc4506603f594400448944fa33b4082c359792658a7`, verified **5771/5771** file hashes, `runtimeExecution=false`. The GitHub comparison to the dispatch head showed no source/test edits since this snapshot (mailbox-only changes).

The prior RA-50 first-consumer guard checked that a keyed `hardRailClosedChains` chain contains the exact endpoint carrier but did not verify that *every other* cyclic edge was in the producer-published hard-feature set, or that each source vertex was unique. The checked A4 product factory checked both later. A forged chain containing the true carrier and at least one non-hard other edge could proceed through A4's endpoint consumer before failing downstream.

Two-file source/test amendment: `src/geometry/SurfaceCellTracing.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`. Require at least three distinct source vertices, reject any repetition (`a2bProbeFailure=closed-rail-chain-not-simple`), preserve existing non-owning-edge first rejection, then require **each** consecutive cyclic typed source edge to exist in `hardFeatureEdges` (`a2bProbeFailure=closed-rail-chain-non-hard-edge`). Do not alter the accepted closed-rail carrier-face or A3 transport predicates; no new test name/fixture selector. Extend the existing `SurfaceCellAuthorityContractCutover.MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback` case with (1) real carrier plus foreign non-hard side and (2) repeated source vertex while retaining the previous non-owning negative.

Patch `R4_ClosedChain_AllCyclicEdges_FirstConsumer.patch`: header exact base `be6b3bedd0c136ec94587821d7a6705c91d38664`; body SHA256 `ac1b27ef82abc66129d745e13884ff1ed23e787296fbe464ae5310fe8bb6f2b7`; outer SHA256 `418f8b3460ec01fa7f32ceb65ad36ca10ddff77336ceaa8f518a9c77ff33ba96`. Forward/reverse `git apply --check` and `git diff --check` passed; intended files verified independently. Drive stage `16Z7oXb0cHL1kXqumPlxMTbWJC8iqSNLI` was owner permanently deleted. [Apply workflow 38480875955](https://github.com/akashskypatel/Directional/actions/runs/38480875955) succeeded, immutable apply receipt artifact `11856534313` SHA256 `993e0a50109848e44fddc97844f0d39064bc5fdd2eaf54bf11854c52d34d3e07`, applied source commit [`2b0e49865`](https://github.com/akashskypatel/Directional/commit/2b0e49865f88e378e34233202bc8e85701d458b2); `runtimeExecution=false`.

## Compile and evidence boundary

Eight-target GMP/GMPXX compile-only request `8996f9a1fb8198875f49d850ce2f9505d66d4284`, pinned source `2b0e49865f88e378e34233202bc8e85701d458b2`, mailbox `.workflow-mailbox/m6-cp3-r4-closedchain-cyclic-hard-edges-compile/latest.json`.

**Pinned compile GREEN:** [workflow 38481058598](https://github.com/akashskypatel/Directional/actions/runs/38481058598), compile job `115583575459`, semantic source `2b0e49865f88e378e34233202bc8e85701d458b2`, immutable result artifact `11856309261` outer ZIP SHA256 `a3cfa3da78e0a36bb00cd35077332e59a4837d1a23ca31de3c1a9a2e8f4512bd`, log artifact `11856379315` SHA256 `2ab5cf776cfa6056f5cb9c88f31f048d666224b0217dd4d79b30670c296bbae5`. Verified **28/28** packaged SHA256SUMS, **8/8** required compiled targets, preflight/build exit `0/0`, `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx.so` and `libgmp.so` present in generated linker command, five empty source-status checkpoints, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No Directional binary, test, or benchmark executed.

No generated Directional binary, tests, benchmarks, discovery, CLI or TB497 was executed in Code + Build. A compiled regression is NOT a runtime PASS; source-level first-rejection assertions remain unexecuted.

## Continuing canonical R4

Further RA-43.1 live transit/germ, RA-43.4 legacy standalone diagnostic migration, additional reachable RA-46.5 negatives, RA-47.12 executed producer liveness, 39 endpoint and 34 Phase10 historical failures, seven DCEL restorations, 88 accepted CP2 losses, six CP3 positives and genuine odd-τ multi-carrier remain. RA-50/RA-51 frozen decisions and fail-closed guards, frozen 497 selector, CP2 accepted 491/491, R3 rejected 403/497, historical ledger 66/17/49 debt1 all retained. Do not start successor or TB497 without the formal gate.

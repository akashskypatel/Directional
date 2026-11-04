# TB78 — CB88 immutable full gate and production census (2026-11-04)

**Turn:** `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-EXEC` — artifact-only Test + Benchmark. **Execution complete; the registered Vase quad count is a semantic MISMATCH.** The frozen 899-case gate is GREEN independently of this census mismatch. The next authorized separate turn is `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV` (Review under RA-202.9); no retries, source/test/fixture changes, new CB, P13-l work, or promotion in TB78.

## Immutable authority and verification

- CB88 compiled semantic source `6cc50f878ef829711e16262759afb3367bec2aff`, Linux GMP/GMPXX [compile run 41902419082](https://github.com/akashskypatel/Directional/actions/runs/41902419082), immutable package artifact `13358062295`; provider ZIP SHA-256 `3263722850d1e139eb69c3a3543225e8a7a009abc9a2a8f4cc46e2d7a1af0c09`, **28/28** internal hashes.
- Verified source snapshot: exact executor source `bc77797c3c90b643a6e0bbf0e6779915353083de`, [snapshot run 41905331946](https://github.com/akashskypatel/Directional/actions/runs/41905331946), artifact `13359219644`, provider ZIP SHA-256 `18415d4b1ba11404900c3bac833a40867c3a11ae5cb65ab8856214101856cd6f`; source file manifest **6,165/6,165** verified.
- Gate [run 41906228679](https://github.com/akashskypatel/Directional/actions/runs/41906228679), result artifact `13360412752`, provider ZIP SHA-256 `f81bb8dfe426ec7fcf37e2e4d932f0897451b02fd902f09bf14087c73b6cc2e5`: manifest 899 SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`, deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, **899/899 PASS**, 81 deferred, membership **980**, **1,806/1,806** internal SHA256SUMS, each of 899 case rows executed. GUARD rows 897–899 PASS. No unexpected red, abnormal, missing, skipped or duplicate entries; postflight true, exit zero.
- Census [run 41906541304](https://github.com/akashskypatel/Directional/actions/runs/41906541304), result artifact `13361996286`, ZIP SHA-256 `674a585cb0c838e6f420533b8dd5c78246524be4a72b8a7c6000c72add3ef161`: three-case manifest `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, **9/9** internal SHA256SUMS including each raw log and resource file. Process totals: planned/executed 3/3, one PASS, two RED, zero ABNORMAL, missing, skipped, duplicates, control failures; postflight true, exit zero.
- Gate and census execution-boundary records both identify CB88 artifact `13358062295` and exact semantic source; `configure=false`, `compile=false`, `relink=false`, `benchmark=false`. No package repair, instrumentation, code, test, fixture, selector or build-system modifications during this TB.

## Fixture census versus RA-202.9 registration

| Fixture | Observed Linux runtime | Registered disposition |
|---|---|---|
| Cylinder | PASS, exit 0, wall **11.69 s**, peak RSS **48,520 KiB** | PASS — MATCH |
| BunnyRandom | RED, exit 1, wall **0.98 s**, peak RSS **24,520 KiB**. `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, no quads. | Existing P13-e RED at source vertex 49 — MATCH |
| Vase | RED, exit 1, wall **268.93 s** (4:28.93), peak RSS **2,080,256 KiB**; `NotProductionReady:completion detail=SelfIntersectingFace`, trace segments **192,482**, arrangement cells **26,817**, completed quads **67,784**. | RED within 600 s, same terminal and stage, 192,482 traces, 26,817 cells, **67,829 completed quads** — **MISMATCH by −45 quads** |

The timed and terminal improvement is real on this immutable Linux package: Vase now returns a completed `SelfIntersectingFace` verdict within 600 seconds instead of TB77's `HARNESS_TIMEOUT 600s`. However, a matching typed verdict is **insufficient** under RA-202.9: the completed-quad count was explicitly frozen at 67,829, and the observed 67,784 is not a match. The 45-quad difference is **unexplained**, not yet proof of algorithmic non-determinism or of a specific CB failure. Do not normalize the discrepancy as a timing variance, re-register it, or infer a root cause without Review probes.

## Dispatch and evidence integrity

- The successful gate dispatcher was `m6-cp3-tb78-gate-20261104a`, request commit `e909b3d66b7a044854eea056968c2cf190b2b1c7`.
- First census request contained a malformed two-character-short digest at `745ed22ae2434923a69dbdcfc3f66f1f60b9d598`; it was corrected to request `m6-cp3-tb78-census-20261104b` at commit `01a398be0e96c39f3077525c3a1cc17fdc18269d`. **Only the corrected census run 41906541304 is semantic execution evidence.** No result from the invalid request was promoted.
- The prior session verified temporary-state cleanup [run 41907335448](https://github.com/akashskypatel/Directional/actions/runs/41907335448); the durable dispatcher slot remains retained. Source, gate and census evidence are separately retained as immutable artifacts.

## Decision and carried obligations

**RA-202.9 mismatch route is mandatory:** `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`. The Review must re-run the RA-202 probe recipe (as specified by RA-202.9) against the measured 67,784-vs-67,829 discrepancy, account for source/package/run attribution, and decide whether the difference is a genuine semantic delta, fixture-dependent initialization difference, nondeterminism or a flawed preregistration; none of those hypotheses is asserted here. No unreviewed rerun or silent count adjustment. No successor work performed in TB78.

Accepted CP2 remains **491/491**, stable regression accounting **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**. The P13-m cost candidate remains unpromoted; P13-l completed-mesh orientation and P13-e port-class count are still independent open Review obligations, as are O27–O29. Selector497 and CP3 remain unpromoted. The census discrepancy is documented as a candidate/mismatch, not silently counted as a new accepted stable regression.

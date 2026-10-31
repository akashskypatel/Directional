# Independent CB44 Review — selector405 fixed-plan rail provenance (2026-10-26)

**Turn:** `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE-REV`. **Verdict: ACCEPT STATIC CODE+BUILD SCOPE; NO RUNTIME CLAIM.** The only semantic change in commit `c256671115c92f7dd55fea5d680feeac3cbb5190` is the body of the existing 405 test. Authorize separately bounded artifact-only `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY` using the reviewed four-case manifest `Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Case_Manifest.tsv`. The three GUARD cases are **off-gate**; do not count them toward selector497 or CP3 acceptance.

## Independent primary-evidence verification

- Verified source snapshot at event/source `bf4c378424aab768072d843f33fd79817204ac30`, run `40379231530`, artifact `12677042578`, ZIP SHA-256 `0704a532312d0e060e2a5c3a21845d8251ebb5a5b0ff2565e1c2abb5740283b6`, all **5920/5920** internal source checksums. This is after CB44; its `tests/SurfaceCellsPhase10Tests.cpp` SHA-256 is `bb066ca105a033b7faa707a9d12adb310c068774878bc60047ccdcd267ab5f1a`, the exact file recorded by the compile package.
- GitHub's actual commit `c256671` has **one changed file**, `tests/SurfaceCellsPhase10Tests.cpp`: +9/-4 test lines. It leaves all original positive expectations, conformity receipt comparison, nonempty interval requirement and equality check untouched. Changes: derives rail provenance once using `hard_rail_source_provenance_from_rails(fixture.rails, fixture.mesh.V.rows())`; asserts `has_value()`; passes `terminalContacts` and `closedChains` into the 0.5 and 2.0 helper calls. The 3-parameter gap is the existing `hardEdges` override, intentionally null.
- Verified `build_fixed_plan_rectangular_hard_rail_network` (`tests/SurfaceCellsPhase10Tests.cpp:7099–7132`) copies passed terminal contacts, reconstructs open chains from the same authoritative rails when contacts exist, and copies passed closed chains. The producer (`src/pipeline/RemeshPipeline.cpp:12775–12782`) publishes precisely contacts, open chains and closed chains from the same provenance function; its declaration is public in `include/directional/pipeline/RemeshPipeline.h`. No helper or producer change was introduced in CB44.
- Compile artifact `12674401457` from [run 40373930737](https://github.com/akashskypatel/Directional/actions/runs/40373930737): independently verified outer ZIP SHA-256 `38d88bbda3b6b768f1d243b9b121db6233a740d3b296ccd35a58a9d1e5932bd3`, **28/28** manifest entries, exact semantic source `c256671`, eight declared compiled targets, preflight/build `0/0`, clean packaged source status, `DIRECTIONAL_ENABLE_GMP=ON`, `libgmpxx.so` and `libgmp.so` in recorded linker command. Package declares `runtimeExecution=false`; neither compiled binaries nor tests/benchmarks were executed in this Review.
- Recomputed 365-row selector LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, and accepted 449-row selector LF SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; both match published authorities. GitHub semantic compare from CB44 base `a9c99c` to compiled `c256671` changes no selector. Frozen 497 selection/harness not modified. Accepted CP2 491/491; stable 66/17/49, debt 1, RP-01 open.

## Non-vacuity, residual risks, and TB44 falsifiers

The pre-fix test supplied no rail-source provenance, whereas the production source always supplies all three maps. The new assertion would fail for an absent producer provenance; if present, the downstream positive `Produced` checks, independently nonempty intervals, and equality across both sizes still can fail. Therefore the fixture repairs a missing input, **not** the product outcome. Compile success alone does not prove 405 passes.

Freeze exactly the four rows in `Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Case_Manifest.tsv` in that order: 405 must PASS as a positive; the three GUARD tests must retain exact separate-source GTest PASS and their existing typed asserted failure reasons. The guards are off-gate and cannot substitute for 405. In particular, RA-161 P1 is **carried to TB44-REV**: guards 7414 and 8219 may be discriminating despite an empty default; inspect their actual sites/logs before declaring them proved. If 405 is still RED, preserve its new first cause and route to Review rather than editing tests inside TB44. Require exact-one execution, zero skips/duplicates, no compile/relink/configure or benchmark, package/source and result SHA256SUMS, per-case raw logs, postflight receipt. The runtime acceptance result is explicitly unresolved.

Prior obligations: RA-161.4 **discharged at static scope**; RA-161 P1 **carried to TB44-REV**. RA-161 T2 and post-RP-01 O2 **carried unchanged**; nine TB38 REDs remain until independent remeasurement. No new stable regression ID and no selector promotion.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 365: `6b5b6555…14b8a1`; 449: `d4a0d1b7…8d6414`, identical to recorded hashes |
| Decisive claims independently re-derived | Exact GitHub c256 hunk; producer/helper contract; compile ZIP and 28 members; clean metadata |
| Non-vacuity checked | Missing provenance assertion plus positive 0.5/2.0 outputs and nonempty/equal interval checks remain falsifiable |
| Prior obligations discharged/carried | RA-161.4 static discharged; P1 TB44-REV; T2/O2 post-RP-01, rest unchanged |
| Stable accounting | 66 / 17 / 49, debt 1; accepted CP2 491/491; selector497 frozen/unpromoted |
| New candidates/obligations recorded | No new evidence-backed event; RA-161 P1 remains in tracker unchanged |
| ORIENTATION currency line | Updated to CB44-REV accepted and TB44 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 updated; §4 n/a no witness executed; §7 immediate owner updated; §8 n/a no new defect pattern |
| CHANGELOG | CB44-REV entry added |
| ROADMAP | n/a no checkpoint acceptance/status change |
| Selector manifest | n/a no required-green selector edited; TB44 case manifest added separately |
| LESSONS | existing evidence/acceptance, fixture, and mechanics sections apply; no new generalizable lesson |
| Consolidation under CLEAN_UP_POLICY | n/a CB44 compile record remains current package authority until TB44; no superseded report folded |
| Successor frozen | `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY`; above manifest, falsifiers and stop rules |
| Turn boundary held | Static Review only, no tests/build or source/test/fixture/selector/benchmark edits |
| review_check.py boundary | Snapshot has no historical `.git`; locally created synthetic Git cannot validate historical baseline `8b7299b43`. Must report history-specific check unresolved, not PASS |
| `STATUS` lifecycle maintained | Entry direct-write complete; final beacon is separate required final repository action |
| Pushed to origin, branch in sync | Requires connector apply + exact HEAD verification; no local origin clone is available, so `git status -sb` cannot prove remote sync |

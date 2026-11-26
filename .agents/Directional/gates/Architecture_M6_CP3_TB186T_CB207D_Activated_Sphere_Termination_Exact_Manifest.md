# TB-EXEC-186T observe manifest and contingent CB-207D exact diff (2026-11-26 UTC)

**Review artifact only.** Frozen by the [TB-REV-187Q adversarial continuation](../Architecture_M6_CP3_TB_REV_187Q_Adversarial_Review_20261126.md). Nothing applied, built or run here.

## `M6-CP3-TB-EXEC-186T` — bounded activated-sphere termination census

- **Candidate:** the CB-206 compile package (exact CB-206 manifest; source = CB-207B postimage + CB-206).
- **Harness:** unchanged `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`, **census mode** (all rows `OBSERVE`, no `MEMBERSHIP_LEDGER`, no `REACH_TERMINATION_DIAGNOSTIC`). Census mode runs each row once with `process.wait(timeout=600)` and writes `HARNESS_TIMEOUT 600s`, exit 124, on cutoff. Diagnostic mode is not usable: it observes only `cases[-1]` and reads `raw/1006.log`.
- **Case manifest:** [`Architecture_M6_TB186T_P13_Activated_Sphere_Termination_Observe_Case_Manifest.tsv`](Architecture_M6_TB186T_P13_Activated_Sphere_Termination_Observe_Case_Manifest.tsv), SHA-256 `80970f595b3fe0d46fca08ae47fae1f53567a6d2b9b500ec34f74de24019eefc`, `EXPECTED_CASE_COUNT=6`. Rows are gate rows 648, 843, 844, 858, 979, 1006 (test and binary copied byte-for-byte from the frozen 1006 manifest).

| Census row | Gate row | Sphere recipe | lengthRatio |
|---|---|---|---|
| 1 | 648 | `build_cp4c_pipeline_products_fixture` | 0.2 |
| 2 | 843 | `produced_network()` | 0.02 (default) |
| 3 | 844 | `produced_network()` | 0.02 |
| 4 | 858 | `run_fixture` (`SurfaceCellTracingDisplayTests.cpp:22–57`) | 0.02 |
| 5 | 979 | `observe_cp4c_witness` | 0.2 |
| 6 | 1006 | pipeline-products 0.2 and polyline-defaults 0.02 | both |

**Report, per row:** verdict, exit, elapsed and peak RSS (`/usr/bin/time -v`), timeout marker, raw log hash, first failure. Plus, verbatim:
- row 648 `m3Cp4c3BW4` line versus the CB-206 prediction;
- row 858 `SphereDisplayStop` line, or the `ASSERT_NE("None", …)` failure text;
- row 979 `SphereStagedCutGraph unstagedCut=` line;
- row 1006 eleven receipt lines versus the CB-206 frozen LF SHA-256 `d8407bea…0c`.

No gate credit, no PASS/RED adjudication, no rerun, no rebuild. An organic RED is data. STOP only on provenance, package or postflight failure.

## Contingent `M6-CP3-CB-207D-QF1-ROOTED-CLASS-PATH-SEARCH-ONCE-PER-ROOT`

Applied **only if TB-REV-186T authorizes it** (a 0.02 row reaches the 600 s cap).

- **Exact diff:** [the diff file](../Architecture_M6_CP3_CB207D_QF1_Rooted_Class_Path_Search_Once_Per_Root_Exact.diff), 7,489 B, SHA-256 `8d76d42c2f4956e52e98a9d95e3210809e7e3dae778d9fba1a3589c8b8e661a3`, one path, +65/−17.
- **`src/pipeline/RemeshPipeline.cpp`:** `5da1fcc98dcb08b21279a3ba59ccd81861bc1f2fc3f2d2bf2ba3acd2c979dd03` (CB-207B postimage = HEAD; CB-206 does not touch this path) → `955d794c1c50cb3b6d83c6a247180681518dd0c4ef1d4c2728c498d3bbcd29a0`.

**What changes.**
- `quotient_forest_path` is split into `quotient_forest_parents` (the unchanged depth-first search, with an optional stop target) and `quotient_forest_path_from_parents` (the unchanged parent walk). `quotient_forest_path` composes them and remains the cycle-closing query (producer, publication).
- `QuotientForestRootedPaths` searches once per root, exhaustively, and reuses the parents for every target. It is used at the three root→member sites: producer final class paths, publication `selectedPaths` check, verifier A6 path check.

**Why the result is identical.** The search assigns each parent once, at first discovery, in the same stack and reverse-adjacency order. The early-stop loop only ends sooner; every parent it assigned is the one the exhaustive search assigns. So the walk from any target gives the same records, for any input graph, cyclic or not; missing targets still give `nullopt`. Error codes, record order and outputs are unchanged.

**Cost.** Per class of M members: from M−1 searches of O(M log M) to one. Not changed: cycle-closing queries on the growing forest, and the published per-member `orderedRelations` (Σ depth). Deep classes stay O(M·depth) by representation; that is a design question for a size receipt (CB-207C, via `productSnapshots.quotientProduct`, `RemeshPipeline.h:359`), not a further cost fix.

**Checks done in Review:** generated in a throwaway `CLAUDE_` worktree at HEAD, since removed; syntax-only 0 errors, 31 warnings at HEAD and patched, identical sets (adversarial Y3). Not compile evidence.

**Falsifiers if applied:** exact hashes and single path; eight-target compile, `runtimeExecution=false`; then rerun the same six-row census (`TB-EXEC-186U`) and the full gate later compared under N1–N3.

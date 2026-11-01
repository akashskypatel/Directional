# TB64 — CB65 immutable Linux full gate and P13 census (2026-11-01)

**Turn:** `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` (TB-EXEC). **All RA-190.6 pre-registered outcomes met:** full gate **866/866 PASS** (856 GUARD, 10 POSITIVE), exact **947** membership, and independent OBSERVE-only census **Cylinder PASS / BunnyRandom RED / Vase RED** at the specified signatures. This is an immutable runtime result, **not** a CP3 or selector497 promotion.

## Source, frozen inputs and execution authority

- Verified CB65 Release/static Linux GMP/GMPXX package: source `dbc38661efabdfa051f48f8f71ee3c604841842c`, artifact `13062413347` from [compile run 41253674256](https://github.com/akashskypatel/Directional/actions/runs/41253674256). ZIP SHA-256 `1a2ab39d43742cfa5d3b7b2c09242482ef63712b2efbaf9644a54b83e2b0948b`; root `SHA256SUMS` SHA-256 `0c69aaea7a2eea6d1a9fe1fcd78724a0c3a320f757357de0b07aece738286ff5`; source tar SHA-256 `c30b58f0aa85375480ed7d794c543faa59f5c613480dba1aaa3df0647cbd3ba5`. Package independently verified, GMP/GMPXX links present, build metadata `runtimeExecution=false`.
- Artifact-only P8 harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; two frozen manifests passed `--self-check` before execution. Full gate: `Architecture_M6_TB64_P13_Dyadic_Exit_Full_Gate_Case_Manifest.tsv` 866 rows, SHA-256 `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`. Deferred ledger v5: 81 rows, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Separate three-row OBSERVE census: `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (no membership ledger).

## Immutable run evidence

| Record | Full gate | Three-case census |
|---|---|---|
| Dispatcher request commit | `ad71f7ded0219ccca95b16d0b3deec000c10a8fe` | `3d2d605f6093659a7ff2ddbc7482b523c44011f5` |
| GitHub run | [41256874416](https://github.com/akashskypatel/Directional/actions/runs/41256874416) SUCCESS | [41256885685](https://github.com/akashskypatel/Directional/actions/runs/41256885685) SUCCESS |
| Runtime job | `124701893151` SUCCESS | `124704285341` SUCCESS |
| Result artifact | `13063712419` | `13064115441` |
| Result ZIP SHA-256 | `34e0c457756821ea739ae14547a6122b134ff897a730aa8422141a00d47afb66` | `adea50730ac6b835f9fbf16a7f8fe6dc0958b87760e8f4161fc43139880fad97` |
| Internal SHA-256 | **1740/1740** matched | **9/9** matched |
| Verdict | **866 PASS, 0 RED, 0 abnormal** | **1 PASS, 2 expected RED, 0 abnormal** |
| Execution boundary | `postflight=true`, exit 0, membership 947 | `postflight=true`, exit 0, membership 0 |

Both `.workflow-mailbox/<request-key>/latest.json` records published successfully on orphan branch `workflow-mailbox` and matched exact source/event SHAs. `execution-boundary.json` in each artifact attests `compile=false`, `relink=false`, `configure=false`, `benchmark=false` and no skipped/missing/duplicate/abnormal cases. The compile and Drive-apply dispatcher jobs were skipped. No package, implementation, fixture, manifest, or build-logic mutation occurred within the TB-EXEC workloads.

## Independent reconciliation and non-vacuity

All 866 ordered `(row,kind,identity,test,binary)` tuples match their frozen manifest. Verdict/exit/run/pass/skip fields match the registered gate outcome; every raw log SHA-256 matches its ledger row and the ZIP checksum manifest. All 866 logs contain exactly one GTest `[ RUN ]` and a passing `[ OK ]`; the 866 `resources/*.time.txt` receipts identify the exact selected test with `GTEST_FAIL_IF_NO_TEST_SELECTED=1` and matching process exit. No zero-selected tests.

Membership is the exact distinct union of **866 GATED + 81 DEFERRED = 947**, including every registered `(binary,test)` and no extras. The 81 deferred cases were **not executed** in this gate. The two new dyadic guards at ordinals **865/866** pass; no accepted-green loss occurred.

All three census rows match their OBSERVE manifest and were executed in separate fresh processes, with verified raw log/resource receipts and correct exit codes:

1. **Cylinder (`offgate:362`)**: PASS; source-authoritative pure-quad acceptance test succeeded.
2. **BunnyRandom (`offgate:360`)**: expected RED; `InvalidFieldTransportAtlas:field-transport-atlas/CutTransportDomainIdentityMismatch`, `cutChi=-3`; known P13-c tip–tip single-edge barrier slit obligation.
3. **Vase (`offgate:365`)**: expected RED; `terminal=NotProductionReady:completion`, `completion=SideSubdivisionRepair:InvalidInputIncidence`, `detail=None`, `traceSegments=192482`; `BranchContinuationExactMagnitudeExceeded` did not recur. Known P13-d completion-incidence obligation and O18 missing-detail diagnostic remain.

These two OBSERVE REDs are **not** new gated regressions. P13-b / O15c A2a continuation-width stop is discharged at this tested artifact under DESIGN Amendment 24; Vase now reaches completion. No claim of Vase or Bunny production success is made.

## Classification and turn boundary

No newly introduced accepted-green regression, unexpected Linux RED, non-stable candidate requiring a new ID, or stable-count increment. Stable accounting remains **66 events / 17 categories / 49 recurrences**, debt **1**. Accepted CP2 **491/491** remains authority; selector497 unpromoted; CP3 not accepted. O16 (macOS), O17, O18, O6/O9, DR1/DR3 and DR2/DR4 remain carried. This executor does not discharge open architectural obligations simply because the registered gate passes.

**Exactly one next turn:** `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (Review/Definition, P13-c), as ordered in RA-190.7; afterward, separately `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d plus O18). No review, repair, successor implementation or selector promotion was performed within TB64. Neither TB64-REV nor infrastructure-retry is triggered because the expected outcomes matched.

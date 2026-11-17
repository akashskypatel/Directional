# TB126 — exact mandatory-edge terminal correction execution (2026-11-17 UTC)

## Situation

**MISMATCH under RA-244 §5.** The immutable CB144 package passed 950 of 951 gate cases. New required guard row 951 failed with a C++ exception. All 950 inherited test verdicts and substantive ledger fields are unchanged. The separate three-case census advances BunnyRandom beyond both inventoried multi-cut edge failure classes to a new rotation-system rejection. Cylinder and Vase are unchanged. No production acceptance or independent Review is claimed.

## Background — immutable authority

- [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) §5 freezes the MATCH requirements and the mismatch route. [CB144 record](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Owner_Correction_Code_Build_Record_20261117.md): source `7b0668d432ccb187c5a2d856494064f0bcb2fb95`, package artifact `14293047782`, ZIP SHA-256 `638eaf00618283551bbec607c1f9484447d96d0bb5000f5ad5df7870d42af929`, 28/28 packaged hashes verified, GMP/GMPXX exact backend, `runtimeExecution=false`. Root manifest SHA-256 `810ebf4186f4099a26f98664fa83c048862944e54e57f5b486f32689df846858`; source archive `43fb1f865bc8fab6db708f9d2ee27529d2615112cd7ae66917fb8b1e740724c0`.
- Executor snapshot `a4141a2d6ac2183e977cf43d9eb6e9e8b0b3c92f`, [run 44005047937](https://github.com/akashskypatel/Directional/actions/runs/44005047937), artifact `14293942606`, ZIP SHA-256 `f88424eef94dc3914371d41dc3378f3ed6b925be6a584b42098d637b34e77296`, 5,576/5,576 checksums; source archive `9a81d1170f796c7884029f500bc29c0f254714ff4505a46887081f467497d99f`. Snapshot marker removed at `ab8b087478d0b0c510ad2416612b6dbb4c9bbc82`.
- Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; gate `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f`; census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; deferred ledger v5 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Gate request event `d18120e83be9ba573e777a2cab1761656d7772b3`, [run 44005423680](https://github.com/akashskypatel/Directional/actions/runs/44005423680), runtime job `133779695458` failure, mailbox `m6-cp3-tb126-gate-v1` attempt 1 on `workflow-mailbox`; result artifact `14294372593`, ZIP SHA-256 `c13a0f5e29ab961a6c6d7a31c2883cfaafbdc577d5727f291eb127e9cc8ea55e`, 1,910/1,910 checksums; log artifact `14294312534`, SHA-256 `2f3565373c252cf3208bfdac1bf001e0cb94a69656ce54244cf953548a3cdaaf`.
- Census request event `82389b7425565a9513a6e9adadb82f95854dd059`, [run 44005461405](https://github.com/akashskypatel/Directional/actions/runs/44005461405), runtime job `133783349211` success, mailbox `m6-cp3-tb126-census-v1` attempt 1 on `workflow-mailbox`; result artifact `14294313207`, ZIP SHA-256 `79acdba05b737e6987a39d3908ce7bf3f9375f4c051b5c4a35566670b63eb95f`, 9/9 checksums; log artifact `14294044969`, SHA-256 `038acbea6f2791490db48bbafa4f086123b40b7ce1fa95a618fb143b93552265`.
- Comparison: TB125 gate artifact `14289730737`, ZIP `c1754245b4ecbde49ba9bbaf9103cbb7975fdb34d40cae57b4e25b7ac56061c8`, 1,908/1,908 hashes; census `14289927334`, ZIP `2f5a4b511d1fac710338acba368b3a892f05e5621eb5e0c89dcbb5143e3ff8d6`, 9/9 hashes. Both result artifacts retained. No duplicate dispatch.

## Assessment — execution and comparison

| Required check | Result |
|---|---|
| Full gate | 951 planned/executed, 950 PASS, 1 RED, 0 skipped/missing/duplicate/abnormal, 1,032 membership (81 deferred), `postflight=true`, exit 90 (`required controls failed`) |
| Inherited gate | All 950 substantive ledger rows equal TB125. After GoogleTest elapsed-time normalization, only rows 156, 173, 190, 191, 477 and 705 differ. The exact `M3_CP4AB_FRAGMENT_DIAG` record multisets agree per row; removing those records and their empty lines leaves all 950 logs equal. No other difference found. |
| New required guard | Row 951 RED, one execution, exit 1, no skip. `MandatoryEdgeTerminalSplit.SplitsAtOrderedDistinctCutsAndRejectsAmbiguousOnes`; `unknown file: Failure`, `C++ exception with description "std::get: wrong index for variant" thrown in the test body`. Raw log SHA-256 `a17f4092754d04dc2e20c79569911afc474460206e0928d2c9011382d8b18b01`. |
| Gate inventory | Zero `mandatoryEdgeTerminalInventory` records across all 951 logs. |
| Census | 3 executed: 1 PASS, 2 RED, zero skipped/missing/duplicate/abnormal; `postflight=true`, exit 0. All substantive ledger fields equal TB125 (the harness ledger does not encode the specific production origin). |
| Census logs | Cylinder and Vase complete logs equal TB125 after normalizing GoogleTest timings and process-dependent `GetParam()` object bytes. BunnyRandom differs in exactly three lines (all terminal reports); all other lines and all four mandatory-edge inventory records agree. |
| Immutable boundary | Both executions record `compile=false`, `relink=false`, `configure=false`, `benchmark=false`; no package repair, source/fixture/test/selector change or local Directional binary execution. |

### Census — observed direct producer state

| Case | Verdict | Actual terminal or output |
|---|---|---|
| Cylinder | PASS | 288 output quads; every receipt unchanged. |
| BunnyRandom | RED | `NotProductionReady:surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`, locus `face=(5,104,359)`, zero output quads. |
| Vase | RED | `NotProductionReady:completion`, `AggregateCompletionValidationFailure`, 189,462 trace segments, 26,817 arrangement cells, 67,750 completed quads internally, zero accepted output; unchanged. |

BunnyRandom previously returned `MandatoryEdgeTerminalOrderUnresolved`, locus `edge=(241,251)`. The current terminal is neither that origin nor `InvalidNetworkBinding` or `RotationEdgeRayEndpointDirectionUnavailable` on either inventoried edge. The two edges each retain two distinct exact cuts (printed in two attempts): `(241,251)` traces 107/38, nodes 149/178; `(251,278)` traces 92/41, nodes 184/162. Exact residual, sector, edge-port, field-follow and pre-cut receipts are unchanged because the entire normalized log apart from the three terminal lines is identical. The census satisfies the scoped RA-244 production progression requirements, but this cannot override the RED guard. The new rotation-system cause is not yet classified; it may be a latent failure exposed by the split or an introduced defect. Do not infer either without independent evidence.

### Regression assessment — candidate root cause and limits

The exception is consistent with an invalid test identity, not yet with a demonstrated production split failure. In `tests/FieldAlignedCurveNetworkTests.cpp:18588–18598`, both typed ID factories use `idCount=16U`. At line 18650, the test constructs `cut(38,13,...)`; its `trace(38)` calls `TraceId::from_index(38,16).value()`. `SemanticId::from_index` (`include/directional/authority/AuthorityIds.h:182–195`) returns `IndexOutOfRange` for any index >= extent, and `DomainResult::value()` (lines 84–85) uses `std::get<T>` on that error variant. The resulting exception matches the observed log. The later `trace(38)` expected values also exceed the declared extent. This source-derived explanation is a candidate, not a runtime stack trace; the guard does not establish that the N=2 chain or its subsequent exact/equal/endpoint/shared-node controls pass. An independent Review must establish the first failing site, preserve all assertions, and decide any test-only correction. Do not fix the test or relax a validator in TB126.

No previously accepted green row was lost. Row 951 was newly introduced, and BunnyRandom was already RED; therefore neither observation establishes a new stable regression ID or historical-count change. C3 remains open pending independent Review; the new rotation-system terminal is a separate unclassified non-stable P13-e candidate. O42/O43 open; O44/C1 closed. Stable 66 events / 17 categories / 49 recurrences, debt 1, deferred 81; CP2 accepted 491/491; CP3/selector497 unpromoted; `chainRimSchedules=false`; D11=A, D12=A, D10 deferred, D6 pending.

## Recommendation — strict turn boundary

The RA-244 mismatch route is **`M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV`** (independent, runtime-free Review). Check the immutable primary evidence and the source-derived guard failure; distinguish test validity from producer correctness, preserve the BunnyRandom new terminal, and decide the next bounded turn. The MATCH-only outcome DEFN and parked CB145 do not start here. Do not repeat either test request or convert this mismatch into an infrastructure failure.

Process note: the initial attempt inspected several documents before applying the mandatory snapshot-read mode. It corrected that ordering miss with the verified snapshot. This continuation reused the same snapshot and did not repeat runtime. Tool-call accounting for the original attempt is incomplete; no fabricated total.

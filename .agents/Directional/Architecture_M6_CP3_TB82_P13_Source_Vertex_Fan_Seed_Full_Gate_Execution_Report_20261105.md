# TB82 — Source-vertex fan-seed immutable full gate and census (2026-11-05)

**Canonical turn:** `M6-CP3-TB82-P13-SOURCE-VERTEX-FAN-SEED-FULL-GATE-EXEC`, separate Linux artifact-only Test + Benchmark under [RA-207 §5](Architecture_M6_CP3_DEFN_P13_Row_Permutation_Seeds_Review_Fan_Seeding_20261105.md). **COMPLETE / MATCH:** all registered gate, census, execution-boundary and digest falsifiers passed. This does **not** promote M6-CP3, selector497, or direct production.

## Immutable source, package and harness

- CB92 semantic source `d9921cdd5a174bbb00b68387082cf08df80f97c5`; immutable package artifact `13427203329` from [compile run 42052009404](https://github.com/akashskypatel/Directional/actions/runs/42052009404); package ZIP SHA-256 `fb547adcc5bede25d3df2a79f6656ec83cf142907ce77cb5a5a4a3f287a5c2ca`. Independent ZIP CRC passed; all **28/28 packaged checksums** verified; embedded exact source and six executable modes `100755` verified; packaged GMP/GMPXX linkage evidence retained. Runtime runner preflight and postflight succeeded.
- Executor commit `12341865b2176c4f97d36e96219132f7b7688e0e`; existing harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Exact runner identity in both frozen requests and `execution-boundary.json`.
- 901-row manifest `Architecture_M6_TB82_P13_Vertex_Fan_Seeds_Full_Gate_Case_Manifest.tsv` SHA-256 `9fbf329167cbe84698d5a08eda6e5374200c7729a5f0f1e4292836227902f878`. Ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- The result boundaries independently show `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`, no errors and harness `exit=0`. Source, test, fixture, selector and build inputs were not modified by the TB jobs. Test identities ran as fresh processes; the census has three separate resource records.

## Full 901-row gate — MATCH

- [Run 42057136562](https://github.com/akashskypatel/Directional/actions/runs/42057136562), frozen request commit `464f4aa18119335085ce40421fe11df735003905`, mailbox `m6-cp3-tb82-gate-20261105-v1` on `workflow-mailbox`; result artifact **`13429919548`**, ZIP SHA-256 `5b1f11f62895e8fb9ad132bf0da7e3639829238d1938073ebdf8e39c2ffc2fff`.
- Independently verified ZIP integrity and all **1,810/1,810 `SHA256SUMS` entries**; 901 unique ledger identities, 901 independently present `raw/<row>.log` files with matching `log_sha256`; every ledger verdict PASS and each recorded exactly one run and one pass.
- **901/901 PASS**, 0 RED, 0 abnormal, missing, skipped, duplicate, control-bad or unexpected-pass, 0 red-site errors. Membership **982 = 901 GATED + 81 DEFERRED**; postflight passed, exit 0.
- New GUARD row 900 `SurfaceCellTracingPhase14.VertexSeedsFollowSourceVertexFansNotFaceRows` **PASS**; row 901 `SurfaceCellTracingPhase14.VertexSeedsCoverEachHardBarrierFanInBothRowOrders` **PASS**. These provide targeted independent nonvacuity on canonical fan seeding; they do not establish invariance of completed meshes for arbitrary face permutations.

## Three-fixture production census — MATCH

- [Run 42057191097](https://github.com/akashskypatel/Directional/actions/runs/42057191097), request commit `1cbc6fb13aa1c75ae1cea687bb11c9104abed78e`, mailbox `m6-cp3-tb82-census-20261105-v1`; result artifact **`13430164928`**, ZIP SHA-256 `ec15230851df439dc8a0917dca74d61d6f02a7a7590cb05873a3a1356119a4c0`.
- ZIP CRC verified; **9/9 internal checksums** verified, including all three raw process logs, ledger, source/mode boundary and resource evidence. Three unique identities, no missing/abnormal/duplicated/skipped cases. Harness exit 0, postflight true.

| Fixture | Raw process | Registered judgment |
|---|---|---|
| Cylinder | PASS, exit 0; **8.63 s wall**, 48,692 KiB peak RSS | MATCH — direct success |
| BunnyRandom | RED, exit 1; **0.82 s wall**, 24,896 KiB peak RSS; `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` | MATCH — existing P13-e, not success |
| Vase | RED, exit 1; **204.77 s wall**, 2,079,952 KiB peak RSS; `NotProductionReady:completion detail=SelfIntersectingFace`; **189,462 trace segments / 30,989 strands / 26,817 arrangement cells / 67,750 completed quads** | MATCH — existing P13-l; terminal under 600 s, informational counts, no completed production output |

## Registered seven-digest comparison against TB81

Exactly one `platform-digest` line was present in each gate row 795, 796, 797, 864 and census row 1, 2, 3. Raw output compared byte-for-byte against the seven lines preserved in [TB81](Architecture_M6_CP3_TB81_P13_Final_Validation_Binding_Full_Gate_Execution_Report_20261105.md), in that order.

| Rows / case | Check |
|---|---|
| Gate 795 CloseSheets, 796 MultiFaceSeam, 797 Plane, 864 Cylinder | **4/4 identical full digest lines** |
| Census 1 Cylinder and 2 BunnyRandom | **2/2 identical full digest lines** |
| Census 3 Vase | **Identical through `global-conformity-baseline`**; from `tracing` onward changes as permitted by RA-207 §5 |

Vase compared with TB81: tracing `192,482 → 189,462` (hash changes); strands `30,989 → 30,989` (hash changes); arrangement cell count `26,817 → 26,817` (hash changes); quads `67,746 → 67,750` (hash changes). This is consistent with CB92's intentional source-vertex fan-seed construction change. No unregistered semantic-digest requirement was imposed on these downstream stages.

## Regression and acceptance disposition

- All registered conditions MATCH; **O32a's source-vertex fan seeding is discharged to the extent proven by RA-207 and this TB**, including the two synthetic row-order/fan tests. Residual `AdaptiveSeedCandidate` face-row tie and O32b/c trace/strand semantic content, O32d arrangement key, O32e completion ownership count dependence remain open. A single Linux Vase run does not prove all permutations produce identical completed topology.
- BunnyRandom's P13-e and Vase's P13-l are **pre-existing, unpromoted candidate failures**, not new stable regression events; no accepted CP2 green was lost. Stable **66 events / 17 categories / 49 recurrences**, debt **1**, accepted CP2 **491/491**, selector497 and CP3 **unpromoted**. No new stable ID or recurrence assigned. Other carried O30b/O31/O33/O27–O29 and DR obligations remain unchanged.
- **Authorized next separate Review:** `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l), per RA-207 §6; scratch analysis may be used under Review rules, but no code/build or additional TB work begins in this turn.

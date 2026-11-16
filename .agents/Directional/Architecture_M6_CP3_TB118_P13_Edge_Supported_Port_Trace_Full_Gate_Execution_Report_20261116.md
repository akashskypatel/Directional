# TB118 — edge-supported port trace: immutable full gate and production census (2026-11-16 UTC)

## Situation

`M6-CP3-TB118-P13-EDGE-SUPPORTED-PORT-TRACE-FULL-GATE-EXEC` meets **RA-237 §4 scoped MATCH**, subject to the explicitly disclosed legacy raw-log duplication qualification below. The authorized separate successor is Review-only `M6-CP3-DEFN-P13-EDGE-PORT-TRACE-OUTCOME`. The result does **not** establish that A2a executed the edge-port departure: BunnyRandom advances past vertex 49 but fails in A1 at vertex 367.

## Background — immutable authorities

- Exact CB137 semantic source `4a63be7a17b5784f0fa742883bbf99e4fe546360`, GMP/GMPXX compiled package artifact `14190250585` (outer SHA-256 `4ec81008bfb8270d2299005a5ec6f08ad57fb99ef00676001f680cb476fee8e3`, 28/28 internal hashes; compile-only `43784411304`). No rebuild.
- Executor snapshot event `9afc87052def367896fbf4115256bab7332ed779`, [run 43788669854](https://github.com/akashskypatel/Directional/actions/runs/43788669854), artifact `14191880708` (outer SHA-256 `61ac6743900819a44ddd5213bf7c61f31eeb217d641e943037b6a43ce51d9373`; 5,541/5,541 file hashes and source archive verified).
- Frozen full gate: `.agents/Directional/gates/Architecture_M6_TB118_P13_Edge_Supported_Port_Trace_Full_Gate_Case_Manifest.tsv`, SHA-256 `5fee837d7760c8e60a8dc47e8734576465adfd67c44ebebb33789c675ee39d00`; TB117 945-row prefix unchanged, guard row 946 added; deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 deferred; expected membership 1,027. Three-case census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Artifact-only harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Both dispatcher `test_benchmark` runs report `compile=false`, `configure=false`, `relink=false`, `benchmark=false` and `postflight=true`; compilation jobs skipped.
- TB117 predecessor: full-gate artifact `14186446054` (SHA-256 `c5806278c67b9321bf26aceb5f557f94437a897e073db976ab2a4fc09b579574`) and census artifact `14186002854` (SHA-256 `a31b7d9b495d1e2fbed1fada6c8a1ee0c585ed5e5a715a44b91def70e93aef33`).

## Assessment — independently verified results

| Evidence | Verified result |
|---|---|
| [Full gate run 43788910187](https://github.com/akashskypatel/Directional/actions/runs/43788910187) | `success`; event `5e96e7c77b71486173d6f85b7d9ce19944c50231`; artifact `14191897640`, outer SHA-256 `8603e4f7898f1d2ff609d21c8596af4a319bdf68b5644d3603ae907cb89b2389` |
| Full gate internal checks | **1,900/1,900** valid; 946/946 PASS; membership 1,027; zero missed/skipped/duplicate/abnormal/RED or control errors |
| Inherited tests | First 945 ledger entries unchanged apart from run-specific log hashes; selected `platform-digest`, `a3-coverage`, `switch-*`, `annulus-*` and atlas partition receipts unchanged in all 945 logs |
| New guard row 946 | `FieldTransportAtlas.PublishesEdgeSupportedPortForRadialStraddle` PASS; two atlas `edgePorts` summaries with `identity=1`, exactly one `edgePort singularity=0 fanIndex=2 branch=2 carrier=(4,6) attached=1` |
| Gate atlas counts | 464 `partition edgePorts` lines, one `partition edgePort` attachment, zero `edgePortDeparture` lines; zero `identity=0` |
| [Production census run 43788935665](https://github.com/akashskypatel/Directional/actions/runs/43788935665) | `success`; event `d81529f4d165841b51d4c4253b8e103216e51aaf`; artifact `14192370504`, outer SHA-256 `317e3623e0b958a3da42750f3883dea1146a6ec3f66abf2bd31035282a73f7fb` |
| Production census internal checks | **9/9** valid; all 3 cases executed; Cylinder PASS, BunnyRandom RED, Vase RED; all three ledger semantic entries match TB117 (excluding log hashes) |
| Cylinder and Vase receipts | Inherited selected receipt lines unchanged; production verdicts unchanged |

**Raw-log qualification:** Inherited gate rows **168, 173, 177, 190, 705** do not have wholly byte-identical raw logs. A pre-existing `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` line sometimes contains the same 465-character diagnostic concatenated twice (930 characters), and sometimes appears once. The direction differs by row. All required inherited receipt lines, case identities and verdicts match, so no semantic regression is established from this legacy text duplication. The complete logs must **not** be described as byte-identical.

**BunnyRandom new earliest terminal:**

```text
FieldTransportAtlas.partition edgePorts singularity=6 sourceVertex=49 classes=4 edgePorts=1 expectedClasses=5 identity=1 straddles= (0,1,48-49)
FieldTransportAtlas.partition edgePort singularity=6 fanIndex=0 branch=1 carrier=(48,49) attached=1
InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=367;topologyRegion=0
FieldTransportAtlas.partition edgePorts singularity=32 sourceVertex=367 classes=3 edgePorts=2 expectedClasses=5 identity=1 straddles= (1,0,170-367) (3,1,366-367)
```

At vertex 367, the `(170,367)` candidate at `fanIndex=1 branch=0` records `attached=0`; the `(366,367)` candidate at `fanIndex=3 branch=1` records `attached=1`. The census has 32 `partition edgePorts` summaries, 11 candidate `edgePort` lines, 10 `attached=1`, one `attached=0`, zero `identity=0`, and zero `edgePortDeparture`. BunnyRandom reports `traceSegments=0`, `arrangementCells=0`, `completedQuads=0`: the trace network was not reached. The authorized review must own the new A1 port-count terminal before any production departure claim. O42 (grazing-segment contact classification) remains open and untested in this census.

**Regression classification:** The new earliest terminal at vertex 367 is an **unresolved, non-stable P13-e candidate**, not a demonstrated accepted-green regression. Vertex 49's previous terminal is removed, but the production fixture remains RED before A2a. Vase's completion RED is already registered and unchanged. No stable event/category/recurrence increase is supported; counts stay **66/17/49**, debt **1**, deferred **81**. Accepted CP2 stays **491/491**, CP3/selector497 remain unpromoted, and production `chainRimSchedules=false`. No source, tests, fixtures, selectors, manifests, build logic or production options changed during TB118.

## Recommendation

Close TB118 as **scoped MATCH with the raw-log qualification documented**. Only the separate Review `M6-CP3-DEFN-P13-EDGE-PORT-TRACE-OUTCOME` may assign the next producer owner and corrective design. Preserve both immutable artifacts and the deferred/O41/O42/O31/O32 obligations. Do not start that Review, execute a replacement test, or promote the selector within TB118.

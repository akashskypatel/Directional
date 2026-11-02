## TB72 invalid gate evidence and TB72A correction (2026-11-02)

- [x] **TB72 invalid gate documentation closeout:** [run 41533361438](https://github.com/akashskypatel/Directional/actions/runs/41533361438) used stale TB71 executor (no TB72 manifest). Preflight exit 90, planned/executed 0/0; no semantic verdict. [Failure report](.agents/Directional/Architecture_M6_CP3_TB72_Orchestration_Failure_Report_20261102.md). Census run `41533460744` was independently verified at 1 PASS and 2 registered RED, within 600 s for Vase; supplementary only. No changes to accepted CP2 or TB71.
- [x] **TB72A orchestration corrected and immutable gate verified:** [run 41540264758](https://github.com/akashskypatel/Directional/actions/runs/41540264758), exact executor `df586285…`, CB78 immutable artifact `13181887585`, **883/883 PASS**, 81 deferred, membership 964, 1,774/1,774 packaged hashes, no rebuild; preserved invalid TB72 attempt. [Record](.agents/Directional/Architecture_M6_CP3_TB72A_Orchestration_Record_20261102.md).
- [ ] **Next independent Review/Definition:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (RA-199.3/6): probe the P13-j source-support and stitched-vertex ownership, decide whether assembly/completion/arrangement owns the defect; freeze an exact patch. No speculative code changes or CP3 promotion.

## CURRENT — TB72A 883/883 verified; CB78 immutable; P13-j Review next (2026-11-02)

- [x] **CB77 Code + Build**: exact RA-198.8 patch at [`25713a0c0eb0`](https://github.com/akashskypatel/Directional/commit/25713a0c0eb0979155c6954f86f8fb13417d5463); [Linux compile 41485148422](https://github.com/akashskypatel/Directional/actions/runs/41485148422) eight GMP/GMPXX Release/static targets PASS, package `13160673891` (28/28 hashes), runtimeExecution=false. [Record](.agents/Directional/Architecture_M6_CP3_CB77_P13_Needle_Grid_Boundary_Search_Code_Build_Record_20261102.md). **TB71 COMPLETE:** [gate 41492237758](https://github.com/akashskypatel/Directional/actions/runs/41492237758) 881/881 PASS, membership 962; [census 41492364954](https://github.com/akashskypatel/Directional/actions/runs/41492364954) Cylinder PASS, BunnyRandom P13-e RED, Vase P13-i RED (registered). [Report](.agents/Directional/Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md). No selector/CP3 promotion.
- [x] Done (records in `.agents/Directional/`, history in `CHANGELOG.md`): RP-01 closure (RA-174…[RA-179](.agents/Directional/Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) → O15 (RA-180, CB55, TB54, [RA-181](.agents/Directional/Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md)) → row 935 (RA-182, CB56, TB55) → O2 entry gate ([RA-183](.agents/Directional/Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md), CB57, TB56) → **DIAG-RETAIN** ([RA-184](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md), [RA-185](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md), [RA-186](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md), [RA-187](.agents/Directional/Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md); CB58–CB61, last source `e1fd0e4b…`). TB57–TB60 ran on macOS arm64 only; the latest, TB60, gave **862/863** on the TB58 manifest (863 rows; only row 283, O16), membership 945. TB59 ran only CLI cases; TB60 is the full-gate TB for both CB60 and CB61 (RA-187.1).
- [x] **Independent Linux TB61 full-gate review of CB58–CB61; owner authorized exact Linux CLI/GUI successor** (user direction, 2026-10-31; handoff step 1):
  - [x] `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE`: no source patch; Linux Release/static GMP/GMPXX eight-target package artifact `13034987618` from `e7c27b0a5f53…` (record: [CB62](.agents/Directional/Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md)).
  - [x] `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC`: verified Linux run `41182654107`, CB62 package `13034987618`, source `e7c27b0a…`, TB58 manifest 863, ledger v4 82, **863/863 PASS**, membership 945, row 283 PASS; [TB61 execution report](.agents/Directional/Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). No new Linux regression; stable accounting unchanged.
  - [x] **`M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` evidence adjudication:** independent artifact/manifest/log/package audit 863/863; Linux CLI/GUI switches both OFF in CB62. [Review report](.agents/Directional/Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md).
  - [x] **Owner authorization 2026-10-31:** exact next `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` selected; [compile plan](.agents/Directional/Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md) governs Linux CLI+GUI GMP/GMPXX compile evidence. Full-history `review_check.py boundary` and `ledgers` passed on unshallow GitHub run 41200958419.
  - [x] **`M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE`:** Linux Release/static ten-target compile/link, CLI/GUI ON, GMP/GMPXX generated links; source `f6113c4e…`, [run 41202931582](https://github.com/akashskypatel/Directional/actions/runs/41202931582), artifact `13043004468` (30/30 verified); [report](.agents/Directional/Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md). No runtime.
  - [x] **`M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC`:** immutable CB63 Linux ten-target package `13043004468` (`f6113c4e…`), [run 41205693716](https://github.com/akashskypatel/Directional/actions/runs/41205693716), result `13046191343`: **863/863 PASS**, 82 DEFERRED, membership945, 1,734/1,734 result hashes, postflight true; 11/11 registered Linux CLI checks and GUI link evidence with no GUI launch, zero rebuild. [TB62 report](.agents/Directional/Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Report_20261031.md). No new Linux regression; macOS O16 separate.
- [x] **`M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`** (Review/Definition): independently re-audited TB62 863/863 and CB63 30/30; ruled runtime probes cannot execute within a DEFN despite 'probe-capable' handoff; froze separate CB→TB observation without modifying 863-case gate, v4 82 ledger or design acceptance. [P13 decision](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Design_Acceptance_Decision_20261031.md).
- [x] **[RA-188](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md) `M6-CP3-DEFN-P13-PROBE-ADJUDICATION`** (DEFN, Review, scratch probes on current source):
  - It upholds the P13 audit, but the decision planned on stale pre-CB55 dispositions and skipped the Review probes (RA-166.6 F6). Its CB64-REGISTRATION (a 300 s harness edit) and TB63-CYLINDER-FIRST are withdrawn.
  - **P13-a, Cylinder:** PASS in 182 s. 96% of that time is O(F) `matches_source_faces` re-validation inside `SourceChartTransitionGraph::available()`. With the fix it runs in 7.8 s with byte-identical output.
  - **P13-b, Vase:** A4 `BranchContinuationExactMagnitudeExceeded`. The exact width grows about 200 bits per step and fails at step 21. This is the O15c trigger, and it is architectural.
  - **P13-c, BunnyRandom:** A3 `CutTransportDomainIdentityMismatch`. Two tip–tip single-edge barrier arcs cannot be slit under DESIGN Amendment 15.3.
  - The patch probe gate gives 862/863 (only O16 row 283).
- [x] **`M6-CP3-CB64-P13-CHART-BINDING-CACHE`** (CB; implementation agent; Linux).
  - The RA-188.8 exact patch: SHA `fad8986c…`, numstat `7 4` and `2 2`. It caches the build-time source binding in `available()` and adds `detail=` to the design-acceptance `failure_context`.
  - Exact two-file patch committed as `d56d990580163f4fd0ceda4137f7ecd16ceb6027`; Linux eight-target compile [run 41221202501](https://github.com/akashskypatel/Directional/actions/runs/41221202501), artifact `13050072901`, 28/28 checksums, GMP/GMPXX, no runtime. [CB64 report](.agents/Directional/Architecture_M6_CB64_Chart_Binding_Code_Build_Continuation_20261031.md).
- [x] **`M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC`** (TB-EXEC; Linux; [report](.agents/Directional/Architecture_M6_CP3_TB63_P13_Census_Full_Gate_Execution_Report_20261031.md)).
  - CB64 immutable artifact `13050072901`, source `d56d9905…`; full [gate run 41224438897](https://github.com/akashskypatel/Directional/actions/runs/41224438897), result `13051413577`, **863/863 PASS** (854 GUARD / 9 POSITIVE), 82 DEFERRED and exact membership 945, 1734/1734 result checksums, 863 per-process logs, postflight true; no rebuild.
  - [Census run 41224395380](https://github.com/akashskypatel/Directional/actions/runs/41224395380), result `13051470763`, **1 PASS / 2 expected RED**: Cylinder PASS, BunnyRandom `CutTransportDomainIdentityMismatch` / `cutChi=-3`, Vase `detail=BranchContinuationExactMagnitudeExceeded`; no new regression. Stable 66/17/49, debt 1 and CP2 491/491 unchanged; selector497/CP3 not promoted.
- [x] **`M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH`** (Review) — [RA-189](.agents/Directional/Architecture_M6_CP3_DEFN_P13_O15C_Continuation_Width_Review_20261031.md) elects versioned exact-predicate dyadic A2a output, not original exact curve equivalence; approves prospective Cylinder 864/81 gate membership only. TB63 remains 863/863 and Vase RED.
- [x] **[RA-190](.agents/Directional/Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md) closes `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH`** (Review, scratch probes on current source).
  - The block was procedural. The unmodified `review_check.py boundary` passes on an authentic checkout.
  - RA-189's dyadic choice and Cylinder promotion stand. Its design defects R1–R7 are ruled:
    - Rounding must happen inside the resolver, because four consumers replay it.
    - The endpoint-collapse failure is replaced by the open grid, since exact HEAD arithmetic already makes 12 near-vertex exits on the prescribed sphere.
    - The certificate and receipt obligations are withdrawn.
    - The monolithic CB is replaced by an exact patch.
    - Membership becomes 947.
  - Probes (macOS):
    - 864-row gate: 863/864 (only O16); 74 rounding rows pass.
    - Deferred rows: 81/81 verdicts unchanged.
    - **Vase passes A4**, then fails at completion `SideSubdivisionRepair:InvalidInputIncidence`; uncapped exact arithmetic gives the same result.
  - DESIGN Amendment 24 is rewritten.
- [x] **`M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT`** (CB; implementation agent; Linux).
  - RA-190.8 exact patch, SHA `ed125319…`, numstat `26 1` / `26 2` / `79 0` / `2 1`, on base `d56d9905…`.
  - Linux eight-target compile [run 41253674256](https://github.com/akashskypatel/Directional/actions/runs/41253674256), artifact `13062413347`, source `dbc38661efabdfa051f48f8f71ee3c604841842c`, ZIP `1a2ab39d43742cfa5d3b7b2c09242482ef63712b2efbaf9644a54b83e2b0948b`; no runtime. [CB65 record](.agents/Directional/Architecture_M6_CP3_CB65_P13_Canonical_Dyadic_Trace_Exit_Code_Build_Report_20261031.md).
  - Mismatch → `M6-CP3-PLAN-P13-DYADIC-EXIT-STOP`; infrastructure → `M6-CP3-CB65A-P13-DYADIC-EXIT-ORCH`.
- [x] **`M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC`** (TB-EXEC; Linux; [report](.agents/Directional/Architecture_M6_CP3_TB64_P13_Canonical_Dyadic_Full_Gate_Execution_Report_20261101.md)).
  - Gate: 866-row manifest `289d887c…` plus ledger v5 `fd433f54…`, pre-registered 866/866, membership 947.
  - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom `CutTransportDomainIdentityMismatch` `cutChi=-3`; Vase `NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence`.
  - Mismatch → `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-REV`.
  - Observed: **866/866 PASS**, **947** membership, **1740/1740** checksums; independent census Cylinder PASS, BunnyRandom P13-c RED, Vase P13-d RED at registered signatures, 9/9 checksums; no rebuild, zero unexpected regression. O15c discharged for A2a, stable 66/17/49 unchanged.
- [x] **`M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT`**:
  - [RA-191](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Single_Edge_Barrier_Slit_Review_Decision_20261101.md) diagnosed the slit.
  - [RA-192](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md) probe-adjudicated it. It proves the interior tip–tip edge is the only configuration the face array glues, and replaces RA-191's incidence product and open-ended CB66 with an A1 slit adapter (Amendment 25, rewritten) and an exact patch.
  - Probes: 869-row candidate gate 868/869 (only O16); ledger 81/81 RED in both modes; BunnyRandom reaches P13-e; mutants M1–M3 each caught.
- [x] **`M6-CP3-CB66-P13-SLIT-CYCLE-BASIS`** (CB; implementation agent; Linux workflow runner):
  - Precheck `git diff --quiet dbc38661… HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
  - Apply the RA-192.8 block, SHA-256 `c83fefa2298e8fb5fc1b6ef14a8fe47f46ce5cf92d0acc89f4fd6d7da0c4377c`. Numstat `1 0` / `173 33` / `182 0`; result SHA-256s per RA-192.5.
  - **Completed:** exact 3-path source patch at `911840c195b52ce1800b3ac7ff3ea7380137ad9c`; [eight-target compile run 41265565212](https://github.com/akashskypatel/Directional/actions/runs/41265565212), artifact `13067780359`, 28/28 hashes, GMP/GMPXX, no runtime. [Report](.agents/Directional/Architecture_M6_CP3_CB66_P13_Slit_Cycle_Basis_Code_Build_Report_20261101.md).
- [x] **`M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC`** (TB-EXEC; Linux; verified CB66 package only):
  - Gate: 869-row manifest `baaef9e7…` plus ledger v5 `fd433f54…`, pre-registered 869/869, membership 950.
  - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` with `cutChi=-5`, `cutBoundaryLoops=7`, no `CutTransportDomainIdentityMismatch`; Vase `NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence`.
  - **Observed:** Linux 869/869 PASS, membership 950, 1746/1746 result checksums; census Cylinder PASS, BunnyRandom expected P13-e RED, Vase expected P13-d/O18 RED, 9/9 hashes; zero rebuild or unexpected regression. [TB65 report](.agents/Directional/Architecture_M6_CP3_TB65_P13_Slit_Full_Gate_Execution_Report_20261101.md). No TB65-REV/TB65A invoked.
- [x] **`M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE`** (P13-d/O18, Review/Definition):
  - The [static decision](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Vase_Completion_Incidence_Review_Decision_20261101.md) left the producer unproved and froze an open-ended diagnostics CB67.
  - [RA-193](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md) probe-adjudicated it. The arrangement publishes zero cells (`RepeatedNodeCycle`, node 33) because its directed wedges split per face chart (R1) and 72 of 167 multi-ray edge rotations are mirrored (R2); the pipeline ignores that typed failure (R3, O18). Amendment 26 added. The decision's CB67 is withdrawn.
  - Probes: gate 868/869 in both patched states and 870/871 on the clean RA-193 build (only O16); ledger 0/81 PASS in both modes, only Vase changes; with both fixes Vase's arrangement is valid (26,827 cells) and completion exceeds 600 s (P13-f).
  - [RA-194](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md): the withdrawn diagnostics CB67 landed anyway as `829a47b2d` (uncompiled). It compiles and keeps verdicts, but it still ends Vase at `completion`, records the symptom `HalfedgeCellOutOfRange` instead of the arrangement's `RepeatedNodeCycle`, and its only test is in the unbuilt historical target, in a file that no longer compiles. Ruled: revert exactly; RA-193's patches are renumbered CB69 and CB70.
- [x] **`M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST`** (P13-f, Review/Definition):
  - The [static decision](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Review_Decision_20261101.md) named the two validator sites. It ran no probe, left Vase's next failure unnamed, froze an open-ended [CB71 plan](.agents/Directional/Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md) (API, binding and tests left to the agent), and set TB obligations a TB cannot observe.
  - [RA-195](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md) probe-adjudicated it.
    - Graph construction is 93.5 % of Vase's completion CPU, and the per-vertex closure is 83.2 %.
    - With one graph per mesh and one per pass, Vase ends in 138 s at `completion` with `InvalidCompletionQuadEmbedding` (P13-g).
    - Binding is ruled as exact borrowing (Amendment 27), replacing the decision's self-contradictory pointer-identity ban.
    - The plan is replaced by two exact patches; O20 (residual per-call O(F)) is recorded.
  - Probes, production build: gate 872/873 on macOS (only O16 row 283); ledger: only Vase (row 365) changes, TIMEOUT → RED; mutants M1 and M2 are each caught by their own new test.
- [ ] **Turn sequence (implementation agent, Linux workflow runner, one exact patch per turn):**
  1. [x] **COMPLETE `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE`** (Code; exact revert, no build):
     - Precheck `git diff --quiet 829a47b2d96eb7313e64402c3de666266725ba7e HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-194.6 block, SHA-256 `a6b8cf62c8f9543bfa35766782906dc28c9d6cbe7263d5db0d1cabc1d4174c21`, numstat per RA-194.4.
     - Postcheck verified against exact applied commit [`90fa3a15`](https://github.com/akashskypatel/Directional/commit/90fa3a155930c2683ed0789ef88e9f8f52775437): no source/build/test path differences from CB66 `911840c1…`, package `13067780359`, TB65 869/869. Drive apply [run 41306617232](https://github.com/akashskypatel/Directional/actions/runs/41306617232), no build/runtime; Drive patch retired.
     - Mismatch → `M6-CP3-PLAN-P13-INCIDENCE-PROBE-REVERT-STOP`; infrastructure → `M6-CP3-CB68A-P13-INCIDENCE-PROBE-REVERT-ORCH`.
  2. [x] **COMPLETE `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL`** (CB, compile only; RA-193's "CB67"):
     - Precheck `git diff --quiet 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-193.10 block, SHA-256 `35727214ac067ac3337ce640ec78fd23a8e92f7f14c444d953053feef7209822`. Numstat `29 1`; result SHA-256 `d478a64c…` (RA-193.5).
     - [CB69 report](.agents/Directional/Architecture_M6_CP3_CB69_Arrangement_Incidence_Terminal_Code_Build_Record_20261101.md): exact RA-193.10 applied at `5b08abe42f91`, compile [run 41310503404](https://github.com/akashskypatel/Directional/actions/runs/41310503404) artifact `13084749209`; GMP/GMPXX eight-target; runtimeExecution=false. Initial dispatcher schema error corrected in v2; no TB acceptance.
     - Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP`; infrastructure → `M6-CP3-CB69A-P13-ARRANGEMENT-TERMINAL-ORCH`.
  3. [x] **COMPLETE `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC`** (TB-EXEC): TB65 manifest 869 `baaef9e7…` + ledger v5 `fd433f54…`, pre-registered 869/869, membership 950; census `3af1dc0d…` Cylinder PASS, BunnyRandom unchanged, Vase `terminal=NotProductionReady:arrangement detail=RepeatedNodeCycle`, `arrangementCells=0`, empty `completion=`. Mismatch → `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-REV`; infrastructure → `M6-CP3-TB66A-P13-ARRANGEMENT-TERMINAL-ORCH`.
     - **Observed:** [gate run 41312768151](https://github.com/akashskypatel/Directional/actions/runs/41312768151), artifact `13086562028`, 869/869 PASS, membership 950, 1746/1746 hashes; [census 41312834931](https://github.com/akashskypatel/Directional/actions/runs/41312834931), artifact `13086079391`, Cylinder PASS, BunnyRandom expected P13-e RED and Vase expected `arrangement/RepeatedNodeCycle` RED, 9/9 hashes. Both immutable/postflight, no unexpected regression. [Report](.agents/Directional/Architecture_M6_CP3_TB66_P13_Arrangement_Terminal_Full_Gate_Execution_Report_20261101.md).
  4. [x] **COMPLETE `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION`** (CB, compile only; RA-193's "CB68"): RA-193.11 block, SHA-256 `e93f5d8c5966f520e4650259a4d836bba1fbfa6ac025d08fe98e49a3065e0f82`, numstat `37 30` / `95 0`, result SHA-256s per RA-193.7. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP`; infrastructure → `M6-CP3-CB70A-P13-ARRANGEMENT-WEDGE-ORCH`.
  5. [x] **COMPLETE `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC`** (TB-EXEC): manifest 871 `434e6d37…` + ledger v5, pre-registered 871/871, membership 952; census Cylinder PASS, BunnyRandom unchanged, Vase ABNORMAL (600 s harness timeout in completion). Mismatch → `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-REV`; infrastructure → `M6-CP3-TB67A-P13-ARRANGEMENT-WEDGE-ORCH`.
     - **Observed:** [gate run 41318594024](https://github.com/akashskypatel/Directional/actions/runs/41318594024) **871/871 PASS**, 952 membership, 1750/1750 internal hashes; [census run 41318624551](https://github.com/akashskypatel/Directional/actions/runs/41318624551) Cylinder PASS, BunnyRandom P13-e expected RED, Vase expected ABNORMAL after 600 seconds, 9/9 hashes. Both postflight true, zero rebuild or unexpected regression. [TB67 report](.agents/Directional/Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md). P13-f Review followed (static decision, then RA-195).
  6. [x] **COMPLETE `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE`** (CB, compile only; RA-195.4):
     - Precheck `git diff --quiet 9754500b2058229b7f0a6268838953650690b031 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-195.8 block verbatim plus a trailing newline. Keep its 6 single-space context lines. SHA-256 `8512400fe56c59f35ac3770383890366f35028c47346ba1fdeb04ca5014e5852`.
     - Numstat `14 0` PureQuadCompletion.h / `18 0` SourceChartTransitions.h / `49 9` PureQuadCompletion.cpp / `86 0` PureQuadCompletionPhase18Tests.cpp. Result SHA-256s per RA-195.4.
     - **Observed:** RA-195.8 exact patch committed [`042979f7`](https://github.com/akashskypatel/Directional/commit/042979f7a264dff21de4e3b1af25a1a27fe27c95), only four approved paths; [compile run 41329208274](https://github.com/akashskypatel/Directional/actions/runs/41329208274) eight GMP/GMPXX Release/static targets, immutable artifact `13092069619`, 28/28 hashes, source clean, `runtimeExecution=false`; no runtime. [CB71 record](.agents/Directional/Architecture_M6_CP3_CB71_Completion_Chart_Graph_Reuse_Code_Build_Record_20261101.md).
     - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`; infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH`.
  7. [x] **COMPLETE `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH`** (CB, compile only; RA-195.5):
     - Precheck: the source differs from `9754500b2…` in exactly CB71's four paths, each at its RA-195.4 result SHA-256.
     - Apply the RA-195.9 block, SHA-256 `514c6d87b7ad47083262b802e7b59da931a9bbeb71e0f3c14af49a6668ff5d6f`. Numstat `6 1` / `10 1` PatchDescriptor.cpp / `17 6` / `58 0`.
     - **Observed:** exact RA-195.9 patch committed [`7b85b450`](https://github.com/akashskypatel/Directional/commit/7b85b450bc98abfb65db511fdcd524eb11f537f8) (four approved source/test paths, all resulting SHA-256 hashes matched). [Linux compile run 41333097065](https://github.com/akashskypatel/Directional/actions/runs/41333097065): 8/8 Release/static GMP/GMPXX targets, artifact `13093439789`, 28/28 packaged checksums, `runtimeExecution=false`, clean source. [CB72 record](.agents/Directional/Architecture_M6_CP3_CB72_Completion_Pass_Graph_Code_Build_Record_20261101.md). No runtime/gate acceptance.
     - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-PASS-GRAPH-STOP`; infrastructure → `M6-CP3-CB72A-P13-COMPLETION-PASS-GRAPH-ORCH`.
  8. [x] **COMPLETE `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC`** (TB-EXEC; RA-195.6):
     - Gate: manifest 873 `3b6b9f42…` plus ledger v5 `fd433f54…`, pre-registered 873/873, membership 954.
     - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom P13-e unchanged; **Vase RED within 600 s** at `NotProductionReady:completion` with `completion=InvalidCompletionQuadEmbedding;…` (the locus is recorded, not registered). A Vase timeout is a mismatch.
     - Mismatch → `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-REV`; infrastructure → `M6-CP3-TB68A-P13-COMPLETION-GRAPH-ORCH`.
     - **Observed:** [gate 41336974483](https://github.com/akashskypatel/Directional/actions/runs/41336974483) 873/873 PASS, membership954, 1754/1754 hashes, 873/873 raw process logs; [census 41337227653](https://github.com/akashskypatel/Directional/actions/runs/41337227653) Cylinder PASS, BunnyRandom P13-e RED, Vase P13-g RED at completion/InvalidCompletionQuadEmbedding in 213.553 s (9/9 hashes); no rebuild or new stable event. [TB68 report](.agents/Directional/Architecture_M6_CP3_TB68_P13_Completion_Graph_Full_Gate_Execution_Report_20261101.md). P13-g Review followed (static decision, then RA-196).
  9. [x] **`M6-CP3-CB73-P13-COMPLETION-EMBEDDING`** (CB, compile only; [RA-196](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md).4). The static decision's CB73 scope is superseded. The attempt started at 21:39:52Z under that scope changed only `STATUS`; restart from RA-196.9.
     - Precheck: `git diff --quiet 7b85b450bc98abfb65db511fdcd524eb11f537f8 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-196.9 block verbatim plus a trailing newline, keeping its 5 single-space context lines. SHA-256 `4020fad1d3a16c536504d0a3d58e11522dfd99688111bdc09e77b3a6885fabf1`.
     - Numstat `10 0` PureQuadCompletion.h / `124 63` PureQuadCompletion.cpp / `73 0` PureQuadCompletionPhase18Tests.cpp. Result SHA-256s per RA-196.4.
     - Content: the Amendment 28 source-orientation predicate (`quad_embedding_failure`, `SourceOrientationMismatch`) in the completion validator. Gate rows 874–875.
     - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-STOP`; infrastructure → `M6-CP3-CB73A-P13-COMPLETION-EMBEDDING-ORCH`.
     - **Observed:** exact patch applied as `57c24325f539`, [GMP compile](https://github.com/akashskypatel/Directional/actions/runs/41357670136) immutable artifact `13104267023`; see [CB73 record](.agents/Directional/Architecture_M6_CP3_CB73_P13_Completion_Embedding_Code_Build_Record_20261101.md). No tests or runtime executed.
  10. [x] **COMPLETE `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH`** (CB, compile only; RA-196.5):
     - Precheck: the source differs from `7b85b450…` in exactly CB73's three paths, each at its RA-196.4 result SHA-256.
     - Apply the RA-196.10 block, keeping its 5 single-space context lines. SHA-256 `b2c6a251c915371845d93c05d753cbf7ad5ed92936cf0fa66879d0dd307c7b4b`. Numstat `3 0` / `146 7` / `131 0`.
     - Content: exhaustive forward-rotation search for an embedded boundary-only quadrangulation, plus the typed `NoEmbeddedQuadrangulation`. Gate rows 876–877.
     - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-QUADRANGULATION-STOP`; infrastructure → `M6-CP3-CB74A-P13-COMPLETION-QUADRANGULATION-ORCH`.
     - **Observed:** exact RA-196.10 applied at `4d4ae3ecaa7f`; [GMP/GMPXX eight-target compile](https://github.com/akashskypatel/Directional/actions/runs/41359781910), package `13105515249`, 28/28 checksums; runtimeExecution=false, focused tests compiled, no execution. See [CB74 record](.agents/Directional/Architecture_M6_CP3_CB74_P13_Completion_Quadrangulation_Search_Code_Build_Record_20261101.md).
  11. [x] **COMPLETE `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL`** (CB, compile only; RA-196.6):
     - Precheck: the source differs from `7b85b450…` in exactly the CB73/CB74 paths, each at its RA-196.5 result SHA-256.
     - Apply the RA-196.11 block, keeping its 1 single-space context line. SHA-256 `d1f5652a979c414e53f11f8b62a71f9d528a79428c0067f2b4946ad71844d933`. Numstat `23 0` PatchDescriptor.h / `6 2` RemeshPipeline.cpp / `22 0` PatchDescriptorMilestoneETests.cpp.
     - Content: the completion terminal's detail becomes the typed completion failure kind. Gate row 878.
     - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-TERMINAL-STOP`; infrastructure → `M6-CP3-CB75A-P13-COMPLETION-TERMINAL-ORCH`.
     - **Observed:** exact RA-196.11 source patch at `8656c4fed507`, [GMP/GMPXX eight-target compile](https://github.com/akashskypatel/Directional/actions/runs/41365067300), package `13107147891`, 28/28 SHA-256 checks, no binary execution. [CB75 record](.agents/Directional/Architecture_M6_CP3_CB75_P13_Completion_Terminal_Detail_Code_Build_Record_20261102.md); next separate TB69.
  12. [x] **COMPLETE `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC`** (TB-EXEC; RA-196.7):
     - Gate: manifest 878 `aaaba077…` plus ledger v5 `fd433f54…`, pre-registered 878/878, membership 959.
     - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom P13-e unchanged; **Vase RED within 600 s** at `NotProductionReady:completion detail=PatchCompletionRejected` with `completion=InvalidCompletionQuadEmbedding;…;backend=closed-form;…`. The locus is recorded, not registered.
     - A `bounded-combinatorial`/`pattern` backend, `detail=None` or a timeout is a mismatch.
     - Mismatch → `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-REV`; infrastructure → `M6-CP3-TB69A-P13-COMPLETION-EMBEDDING-ORCH`. Neither occurred.
     - **Verified:** [TB69 report](.agents/Directional/Architecture_M6_CP3_TB69_P13_Completion_Embedding_Full_Gate_Execution_Report_20261102.md); gate [41367521935](https://github.com/akashskypatel/Directional/actions/runs/41367521935) 878/878 PASS, membership 959, 81 deferred; independent census [41367552244](https://github.com/akashskypatel/Directional/actions/runs/41367552244) Cylinder PASS, BunnyRandom expected P13-e RED, Vase expected P13-h closed-form RED in 256.96 s. No rebuild or CP3 promotion. **Exact next separate Review:** `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (P13-h/P13-i).
  13. [x] **COMPLETE `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START`** (CB, compile only; [RA-197](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md) §4, exact §7; Amendment 29):
     - Precheck `git diff --quiet 8656c4fed5070a467da491b60ead5c8ab1d99dbd HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-197.7 block verbatim (keep its 3 single-space context lines), SHA-256 `5c7918fbd6dea765848ce3bd0272aba336c22952fde398acf5beb4d3ccc6af19`. Numstat `10 0` `src/geometry/PatchDescriptor.cpp` (result `108e5481…`) and `61 0` `tests/PatchDescriptorMilestoneETests.cpp` (result `e1eda480…`).
     - Content: `derive_patch_descriptor` rotates its boundary to side 0's first halfedge; GUARD tests (rows 879–880) `PatchBoundaryStartsAtTheFirstVertexOfSideZero` and `ClosedFormStripRungsJoinOppositeSideVertices`.
     - One eight-target Linux GMP/GMPXX package, `runtimeExecution=false`.
     - Mismatch → `M6-CP3-PLAN-P13-PATCH-SIDE-START-STOP`; infrastructure → `M6-CP3-CB76A-P13-PATCH-SIDE-START-ORCH`.
     - [CB76 build record](.agents/Directional/Architecture_M6_CP3_CB76_P13_Patch_Boundary_Side_Start_Code_Build_Record_20261102.md): source `f59f92f889fc`, compile 41387260857, package 13115678045, 28/28 hashes, GMP/GMPXX, no execution.
  14. [x] **COMPLETE `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC`** (TB-EXEC; RA-197.5):
     - Gate: manifest 880 `a9f964c8…` (TB69's 878 rows plus 879–880) plus ledger v5 `fd433f54…`, pre-registered 880/880, membership 961.
     - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom P13-e unchanged; **Vase RED within 600 s** at `NotProductionReady:completion detail=PatchCompletionRejected` with `completion=InvalidCompletionQuadEmbedding;…;backend=closed-form;…` and a negative (generated) id in `vertices=`. The macOS locus (patch 6095) is recorded, not registered.
     - Mismatch: all-non-negative `vertices=` (a strip still fails), `bounded-combinatorial`/`pattern`, `IncompleteSurfaceCellComplex`, `detail=None` or a timeout.
     - Mismatch → `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-REV`; infrastructure → `M6-CP3-TB70A-P13-PATCH-SIDE-START-ORCH`. Neither occurred.
     - **Observed:** [TB70 report](Architecture_M6_CP3_TB70_P13_Patch_Side_Start_Full_Gate_Execution_Report_20261102.md); [gate run 41388843062](https://github.com/akashskypatel/Directional/actions/runs/41388843062) 880/880 PASS, membership 961, 1768/1768 hashes; [census run 41388863937](https://github.com/akashskypatel/Directional/actions/runs/41388863937) 9/9 hashes, Cylinder PASS, BunnyRandom P13-e RED vertex49, Vase P13-h2 `closed-form` generated-vertex RED at patch6095 in 258.988 s. Both registered outcomes matched; no rebuild or CP3 promotion. **Exact next separate Review:** `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`.
  15. [x] **`M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH`** (CB, compile only; [RA-198](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md) §4, exact §8; Amendment 30):
     - Precheck `git diff --quiet f59f92f889fc6fe22d689fd7559c024cd09c6c72 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-198.8 block verbatim (no single-space context lines), SHA-256 `673010d4a76f611bc3f7fbedd40306022ac3fa136ee1acea414a45cb415727db`. Numstat `23 0` `src/geometry/PureQuadCompletion.cpp` (result `9eb46a71…`) and `27 0` `tests/PatchDescriptorMilestoneETests.cpp` (result `e6f8b3cc…`).
     - Content: a closed-form grid with generated vertices whose quads do not all embed gives way to `complete_pattern` over the same boundary when that search succeeds. GUARD test (row 881) `BentNeedleGridCompletesByTheBoundarySearch`.
     - One eight-target Linux GMP/GMPXX package, `runtimeExecution=false`.
     - Mismatch → `M6-CP3-PLAN-P13-NEEDLE-GRID-STOP`; infrastructure → `M6-CP3-CB77A-P13-NEEDLE-GRID-ORCH`.
  16. [x] **`M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC`** (TB-EXEC; RA-198.5):
     - Gate: manifest 881 `f2503dca…` (TB70's 880 rows plus row 881) plus ledger v5 `fd433f54…`, pre-registered 881/881, membership 962.
     - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom P13-e unchanged; **Vase RED within 600 s** at `NotProductionReady:completion detail=PatchCompletionRejected` with `completion=IncompleteSurfaceCellComplex;…;reason=side-count-unsupported;…`. The macOS locus (descriptor 23933, cell 26735, `failed=5`) is recorded, not registered.
     - Mismatch: `InvalidCompletionQuadEmbedding` (a needle grid still fails), any other completion code or reason, `detail=None` or a timeout.
     - **Verified:** [TB71 report](.agents/Directional/Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md); gate 881/881 PASS (871 GUARD + 10 POSITIVE), 962 membership; registered census 1 PASS / 2 RED; no mismatch or infrastructure route. Neither conditional successor activated.
     - Mismatch → `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-REV`; infrastructure → `M6-CP3-TB71A-P13-NEEDLE-GRID-ORCH`.
  17. [x] **COMPLETE `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION`** (CB, compile only; [RA-199](.agents/Directional/Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md) §4, exact §8; Amendment 31):
     - Precheck `git diff --quiet 25713a0c0eb0979155c6954f86f8fb13417d5463 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
     - Apply the RA-199.8 block verbatim (**keep its 3 single-space context lines**), SHA-256 `1d8b80e7f5a07c41643967a140b8290cbd563068abf000ae44775bed8159150d`. Numstat `119 0` `src/geometry/FlowRepStrands.cpp` (result `0b15f6da…`) and `153 0` `tests/FlowRepStrandsPhase15Tests.cpp` (result `c7138a47…`).
     - Content: `deactivate_unmet_support_chords` leaves inactive every support trace that returns to the rail it left and meets no other non-rail arc; called once in `build_flow_rep_selection_input` before coverage samples. GUARD tests (rows 882–883) `UnmetSupportChordIsNotAdmittedToSelection` and `CrossingSupportChordsRemainAdmitted`.
     - One eight-target Linux GMP/GMPXX package, `runtimeExecution=false`.
     - **CB78 verified:** [Code + Build record](.agents/Directional/Architecture_M6_CP3_CB78_P13_Support_Chord_Admission_Code_Build_Record_20261102.md), source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`, run `41531251636`, artifact `13181887585`, 28/28 hashes, no runtime.
      - Mismatch → `M6-CP3-PLAN-P13-SUPPORT-CHORD-STOP`; infrastructure → `M6-CP3-CB78A-P13-SUPPORT-CHORD-ORCH`.
  18. [x] **INVALID ORCHESTRATION `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC`** (TB-EXEC; RA-199.5):
     - Gate: manifest 883 `e9eabb06…` (TB71's 881 rows plus rows 882–883) plus ledger v5 `fd433f54…`, pre-registered 883/883, membership 964.
     - Census `3af1dc0d…`: Cylinder PASS; BunnyRandom P13-e unchanged; **Vase RED within 600 s** at `NotProductionReady:completion detail=AssemblyRejected` with `completion=NonManifoldStitchedVertex`. The macOS counts (26,817 cells, 0 quads) are recorded, not registered.
     - Mismatch: `PatchCompletionRejected`/`IncompleteSurfaceCellComplex` (a two-sided cell remains), any other assembly or completion code, `detail=None` or a timeout.
     - Mismatch → `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-REV`; infrastructure → `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH`.
- [ ] **Review track** (probe DEFNs):
  - [x] **`M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING`** (P13-g): the static [decision](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Review_Decision_20261101.md) ran no probe and froze an open A/B CB73. [RA-196](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md) probes settle it:
    - Patch 1200's boundary is simple (branch A is false).
    - The fixed balanced split reaches 4 of 12 octagon quadrangulations, and the 2 embedded ones are fans.
    - The validator accepts folds: 2,552 of 12,452 accepted boundary-only completions disagree with the source normal.
    - Patch 1200 is only the first of 150 failed descriptors in one pass.
    - Outcome: Amendment 28 → exact CB73/CB74/CB75 → TB69.
  - [x] **`M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING`** (P13-h/P13-i): ChatGPT's [review WIP](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Review_WIP_20261102.md) blocked on "no trace". [RA-197](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md) ran the probe:
    - 220 of the 224 closed-form failures are strips. `ordered_boundary` starts at the smallest halfedge id and `extract_sides` closes side 0 across it, so `boundaryVertices[0]` is often mid-side and the grid's ladder is twisted.
    - 5,868 of 23,329 four-sided descriptors are offset at HEAD; 222 fail and 2,055 more are accepted twisted.
    - With the boundary rotated to side 0, 0 strips fail. Bilinear, Coons and Tutte interiors each break some needle grid.
    - Outcome: Amendment 29 → exact CB76 → TB70.
  - [x] **`M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS`** (P13-h2 + P13-i): ChatGPT's [review WIP](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Review_WIP_20261102.md) blocked on "Review policy prohibits runtime probes", though RA-197 had put this probe DEFN on the Review track. [RA-198](.agents/Directional/Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md) ran the probes:
    - P13-h2: the four needle grids complete under the existing Amendment 28 pattern search over the same boundary; the closed-form dispatch never offers it. Scoped to grids with generated vertices (an unscoped fall-through broke gate rows 144, 570, 875).
    - P13-i: the five lenses are optional rim-seed support traces (1037/878/20/422/612). The field is not aligned with the rim (departures 0.1°–88°), so no tangent rule separates them. FlowRep selection removes 0 of 4,057 candidates: same-face coverage blocks 104 support flowlines and exact junction degrees block 11. Dropping the five named traces exposes three other two-sided cells.
    - Outcome: Amendment 30 → exact CB77 → TB71; P13-i → `M6-CP3-DEFN-P13-FLOWREP-SELECTION`; O24 new.
  - [x] **`M6-CP3-DEFN-P13-FLOWREP-SELECTION`** (P13-i): ChatGPT's [probe preflight](.agents/Directional/Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Preflight_20261102.md) blocked on "no scratch execution"; RA-198.6 had put this probe DEFN on the Review track. [RA-199](.agents/Directional/Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md) ran the probes:
    - Selection cannot see whether a support meets the layout: seed traces never end on another trace, so each of the 115 supports is one flowline touching only its rail.
    - Exactly 10 supports return to the rail they left and meet no other trace; all five lenses are among them. Not admitting them clears every two-sided cell (one pass is the fixed point).
    - Coverage is not the criterion: lenses 20/422/612 lie 2–6 % of target size from the rail (tolerance 2 %); cross-face coverage plus relaxed degrees removes 13 supports and still leaves 3 lenses. → O25.
    - Outcome: Amendment 31 → exact CB78 → TB72; Vase's next failure P13-j `AssemblyRejected`/`NonManifoldStitchedVertex`.
  - [ ] **NEXT (Review, can start now) `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`** (P13-j; probe DEFN on the CB78 scratch state, Claude):
    - With CB78, completion succeeds on every Vase cell and assembly rejects with `NonManifoldStitchedVertex` (26,817 cells, 0 quads); RA-198's tangent-skip probe reached the same failure by another route.
    - Name the stitched vertex, its source support and the patches meeting there; decide whether assembly, completion boundary sharing or an arrangement node owns it; then freeze an exact patch.
  - **`M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT`** (P13-e; can run now, in parallel). A1 requires `4 − index` port classes. BunnyRandom's index −1 vertex 49 has 4 sector incidences in an 8-face fan, on macOS, FMA-off and Linux (TB65). Decide whether A1's sector rule or the field owns this.
  - Then re-census P13, take O6/O9 where they are reached, and aim for matrix 6/6.
- [x] **DIAG-RETAIN (user-directed, 2026-10-21): closed** by CB58–CB61 (snapshots, display adapter and dump, CLI sidecar, GUI layers). Open: DR1 (no in-helper A6/A7 rejection witness; waits for a stimulus), DR3 (pre-existing snapshot fields written when retention is off). DR2 (multi-component snapshot drop) and DR4 (`--diagnostics-prefix` cut sidecars throw on SurfaceCells products, `src/cli/RemeshOutput.cpp:388–392`) → M8-CP2. The GUI layers' appearance is a manual check.
- [ ] **Then:** retire CB → FIXTURE slices (each DEFN first confirms the production pipeline reaches its stage) → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV.
  - **CP3-exit conditions (RA-174.3):** RP-01 closed (done); zero ledger rows; design-acceptance matrix gated at 6/6 (Cylinder is required); O14 enforced; O7 resolved; O15 discharged (done); CP3-REV decides selector497 promotion.
- [ ] Carried separately (owners per RA-174.3):
  - **O2b** (retire the public no-atlas APIs, the legacy detail branches, their 12 gated unit tests and the historical suite) → a retirement DEFN after P13. **O16** (row 283, LegacyInteger NFunctionMesher macOS failure, not FMA) → a legacy-backend probe DEFN; not CP3-blocking.
  - O6 (bounded disks that are not rectangular are rejected by design). No P13 fixture reaches it at current source (RA-188.2) → P13 re-census.
  - **O19** (RA-192): a genus > 0 region whose `dual_cycles` handle generator crosses a slit fails closed (`HandleGeneratorCrossesSlit`). Torus sweep: 35 of 216 edges. Not CP3-blocking, because all six matrix fixtures are genus 0 → a later DEFN when a fixture needs it.
  - **O18** (the pipeline recorded the arrangement stage as succeeded even when the arrangement reported invalid incidence) → CB69; discharged by TB66.
  - **O21** (RA-196, quality, non-blocking): the boundary-only search takes the first embedded quadrangulation, not the best, and quads with a straight (180°) corner are accepted (332 in Vase's exact single-face subset). A §2.1 item 10 quality criterion, owned by the M7 quality gates.
  - **O23** (RA-197, quality, non-blocking): needle cells (thickness/length down to 6·10⁻⁴) from near-parallel traces give needle quads even when they embed. Owned by M7 quality; after CB77 the four Vase needles complete by the boundary search.
  - **O25** (RA-199, quality, non-blocking): support selection is inert. `build_coverage_index` lets only same-face arcs cover a sample (a sample one edge from a covering arc is uncovered), and `protected_endpoint_degrees` freezes every rail node, so no support is ever removed by coverage. On the census fixtures this decides only which near-duplicate supports survive (needles, O23). Owned by M7 with O23; a change must state a cross-face intrinsic metric and its falsifiers (the RA-199 preflight contract is the reference).
  - **O24** (RA-198, quality, non-blocking): the cross field is not aligned with Vase's boundary rail; rim support traces leave it at 0.1°–88°, so boundary cells have arbitrary corner angles. Owned by M7 quality unless the selection DEFN finds it blocks a valid layout.
  - **O22** (RA-196, cleanup, non-blocking): reversed completion variants (pattern/bounded `n…2n−1`, transition 3–5) can never embed under Amendment 28. Drop them from `completion_variant_count`.
  - **O20** (RA-195, residual per-call O(F) source work, non-blocking):
    - the per-patch `SurfaceProjectionBvh` in `complete_pure_quad_patch` (1.0 % of HEAD completion CPU, about 0.5 ms per patch);
    - assembly's per-certificate `matches_source_faces` in `owner_validated_typed_authority_certificate`;
    - the per-lineage graph in `rebuild_aggregate_output_identity_caches`, which is multi-component aggregation only.
    - Owner: a performance slice, or the first fixture whose census times out in one of these.
  - The historical arrangement suite (`SurfaceArrangementPhase16Tests.cpp`, not built) is stale: none of its tests passes `sourceAuthority` (RA-193.2) → O2b's retirement DEFN.
  - **O17** (production code writes diagnostics to stderr unconditionally: `GlobalTopologyPlan.cpp:2634`, `FieldTransportAtlas.cpp:746`) → M8-CP2.
  - O7 (oracle-tests target does not compile) → its own probe DEFN.
  - O8 (`InvalidFrontBoundaryAuthority` on the 3×3 midline at `lengthRatio=0.29`) and O10 (non-hard isolation-barrier producer) → CP3-exit probe DEFNs after P13.
  - O9 ruled (RA-178.3): kept as accepted-defensive. Falsifier (a produced route with more than one step) → P13 re-census, once Vase or BunnyRandom reaches A4 routes.
  - O12 (R61 `review_check.py` selector collision) → Review tooling.
  - O14 → P8.
  - **O15c** → RA-190 dyadic exit (Amendment 24); discharged for A2a when TB64 matches. The 4,096-bit guard stays as the backstop. **O15b** (fields-stage `principal_matching` argmin tie; degenerate input only) → CP3-REV.
  - RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4. G4-B002 exit row is gated; the discharge decision belongs to CP3-REV.
- **Rules:**
  - CB and TB run on the Linux workflow runner. A TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187); the latest verified Linux gate is TB71 (881-row manifest `f2503dca…`, ledger v5 81, membership 962); the next gate is TB72 after CB78 (883-row manifest `e9eabb06…`, membership 964); prior TB70 used 880 rows (`a9f964c8…`, membership 961); TB69 used 878 rows (`aaaba077…`, membership 959); TB68 used 873 rows (`3b6b9f42…`, membership 954); TB67 used the 871-row manifest `434e6d37…` (membership 952). Earlier TB65 was 869 rows, TB64 866 rows and TB58 863 rows.
  - One CB per exact patch; implementation agents get only exact patches and frozen manifests. Probe-requiring DEFN and TB-REV turns stay on the Review track. Every gate run needs `MEMBERSHIP_LEDGER`.
  - **Naming (RA-167.6):** types per `turn_type_from_turn`; DEFN/PLAN IDs carry no `-CB<n>`/`-TB<n>` segment and no final R+letters qualifier.
  - RA-170 (a gate pass says nothing about off-gate tests), RA-171 (self-check every manifest; census rows are OBSERVE), RA-172 (a DEFN needs a reachable exit), RA-174 (verify completeness against the package, not against the gate's own scope), RA-176 (a result that differs by platform is a determinism defect; compute the exact answer before classifying), RA-178 (a test that targets an accepted-defensive guard has no repair exit; witness the guard at its checked factory or retire the test), RA-179 (trace fixture use through helper accessors, not literal grep; confirm per-file flag changes in the built object).
- **Frozen:** stable 66/17/49, debt 1; CP2 491/491 last accepted; TB52 853/0 reviewed Linux candidate; TB60 862/863 latest macOS candidate; TB62 863/863 latest independently reconciled Linux full-gate candidate (ten-target scope); TB61 prior eight-target candidate (TB54 856/857 reviewed macOS, RA-181); RP-01 closed; selector497 frozen and unpromoted; Gate C suspended; PR #8 draft and unmerged.
- Completed per-turn task history before 2026-10-31 was pruned at the user's direction; it is in `CHANGELOG.md`, the per-turn records and git history (`TODO.md` at `4a5578fad`).

## Recorded observations (carried from pruned history)

- [ ] `M5-CP3-TB1-R16-REV-OBS-02` — **RECORDED / NOT FIRING.** Rows 446/447 pin inverse canonical storage. If it fires, classify it as test-authority drift and keep the pin.
- [ ] Review guard (`M5-CP3-TB2-REV-OBS-03`): every Review runs `review_check.py ledgers --base <previous-review-commit>` to catch overwritten ledgers (the tracker and CHANGELOG were each overwritten once and restored).
- [ ] M8-CP2 observations recorded in `Architecture_M6_Frozen_Definitions.md`: `M6-CP1-CB12-REV-OBS-01` (the source-row-order scope of the test-only `make_surface_optimization_overlay`, RA-26) and `M6-CP1-TB12-R1-REV-OBS-02` (the adapter drops A7's cross-sheet site, RA-27b).

---

## Deferred hygiene

- [ ] **Repair `.github/workflows/agent-turn-cleanup.yml` comment handling and trigger safety.** The workflow still deletes **all** PR conversation and inline review comments before its observer step, and creating `.agents/connector-triggers/turn-cleanup/manifest.txt` auto-triggers it. Run `32591251950 / 97075340976` demonstrated 27 conversation-comment deletions. User commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` explicitly superseded the old prohibition by requiring the manifest/workflow at every turn closeout. Until the workflow is repaired, preserve durable repository evidence before publishing the closeout manifest and treat PR comments as non-durable.

Inherited baseline-red / non-gating fixtures remain frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] `WU2A-TB-CAND-01`: successful-side-subdivision ownership-registry precondition.
- [ ] `WU2B-TB-CAND-01`: hard-rail region-copy valid front-boundary-authority precondition.
- [ ] `WU2B-TB-CAND-02`: side-repair rollback ownership-registry/domain-identity precondition.
- [ ] `WU2B-TB-CAND-03`: authoritative-cell-scope subdivision source-scope reconciliation.
- [ ] `WU2B-TB-CAND-04`: five simplification fixtures need independently proven removable/protected/healing preconditions.
- [ ] `WU2B-TB-CAND-05`: FlowRep mandatory-cycle witness needs `selectionSucceeded=true` before later-cycle evidence is creditable.
- [ ] `RA-REV-23-F3`: dispatch stitch-kind audit through an explicit classifier field rather than probe-name text; add a negative self-test.
- [ ] `RA-REV-22-F6`: remove non-falsifiable validation-used assertions or set them where each gate actually executes.
- [ ] `RA-TB6-H1`: repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Milestone status

Checkpoint decomposition, per-milestone acceptance mapping, and the path to production-ready are in **`ROADMAP.md`**. Summary only:

- [x] **M0** preserve evidence  ·  [x] **M1** single-authority cutover  ·  [x] **M2** closed stage products
- [x] **M3 — field-aligned curve network.** **CLOSED / ACCEPTED at `M3-CP4c-3-TB48-REV`.** Package113/TB48 is reviewed authority at 405 PASS / 4 RED over the final audit surface, with accepted required-green selector365 at 365/365 and the AU0–AU9 mechanical-witness criterion met. Closure: `M3_Closure_Record.md`.

- [x] **M4** global conformity plan — **CLOSED / ACCEPTED at `M4-CP4-TB3-REV`**. Final runtime authority is package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**. Closure: `M4_Closure_Record.md`; CP4 closure: `M4_CP4_Closure_Record.md`. M4 handed four periodic/relation debts to M5 and one closed-complex debt to M6; R7 Review discharged two M5 debts and R16 Review discharges the remaining two nonzero-Z4 M5 debts. The sole remaining project debt is the M6 closed-complex subject.
- [x] **M5** certificate-carrying chart/quotient relations — **CLOSED / ACCEPTED at `M5-CP4-TB2-REV`.** Final authority is package/source `10814505512 / e284fea7...` under accepted selector449 **449/449**, SHA `d4a0d1b7...d6414`, owners 32/301/75/41. All §13.1 conjuncts 1-8 are accepted; M6 Definition is frozen and M6-CP1 recovery is now active.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [x] **CP4c-3 protected frontier census evidence:** Part XII was first runtime-proved in TB43: 390/393/406/407 executed the producer-owned census predicates and rejected same-domain corruption. `M3-CP4c3-TB40-EXEC-CAND-02` remains historically CLOSED / RUNTIME-PROVED / NON-STABLE. TB45 historically exposed the stale failure-required precondition; package113/TB48 now re-proves all four receipts non-vacuously through `PlanFrontier`.
- [x] **CP4c-3 protected Part XII success-path observability — CLOSED / RUNTIME-PROVED:** package111 ordinals 390/393/406/407 all PASS on `PlanFrontier`, execute the real census predicates, reject same-domain corruption and emit non-vacuous receipts.
- [x] **CP4c-3 ordinal367 independent oracle — CLOSED / RUNTIME-PROVED / NON-STABLE:** TB47/package112 PASSes ordinal367 under the frozen high-side-only rule; package112 is promoted. Accepted ordinal307 remains a separately recorded latent stale equality and is unchanged.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

- [x] **CP4c-3 ordinal370 empty closed network — CLOSED / RUNTIME-PROVED / NON-STABLE:** package113 ordinal370 PASSes under the frozen identity requiring `EmptyNetworkOnClosedSurface = 6` plus a non-empty `sourceFace` locus. TB48-REV promotes package113 and closes `M3-CP4c2-TB-X2-R8-CAND-02` without changing stable accounting.
- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. TB8 repeated this pre-classified stop; it adds no new product evidence.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch` (last measured 0/3 at artifact `9031804178`, pre-M1). **M6-DEFN disposition:** the original hard-rail→sheet root is absent from current source (production passes an empty isolation-barrier set). Carried as a direct-production evidence debt to **`M6-CP3`** (strict torus 3/3 re-proof). Unmeasured since then; do not weaken `LocalSheetMismatch`.
- [x] `G4-B002` main exact-torus hard-rail pairing blocker — **CLOSED / RECOVERY PROVED at M4-CP3-TB8-REV** on accepted package `10307919492` / selector408 **408/408**. The three produced-witness debts remain open: one closed-complex debt is M6-owned after DEFN-R2 and two periodic debts are M5-owned after DEFN-R1. This checkbox closes the blocker, not those debt items.
- [x] `G4-B003`: nonzero periodic Z4 production — **DISCHARGED at M5 R16 Review**; both direct-production debts are runtime/review proved.
- [ ] `G4-B004`: positive multi-isolation quotient witness. **M5 producer half ACCEPTED / DISCHARGED at `M5-CP4-TB2-REV`; M6 representative-consumption half OPEN.** Selector449 final authority proves the same-region producer join. `M6-DEFN` item 7 now owns representative exact-once materialization/consumption, embedding and independent verifier proof without weakening or reconstructing the producer fact.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates.

## Design and calibration backlog

- [ ] Own the closed-rail cardinality contract once at the rail product boundary rather than re-guarding both closed representations at every consumer.
- [ ] Calibrate `T5` quality/resource thresholds from measured baselines before any milestone asserts a quality gate.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] **Audit every remaining `kBranchTopologyTolerance` comparison for dimensional coherence.**
  `direction_in_incident_vertex_sector` compares a Gram **determinant** — an area-squared quantity — to
  `1e-10`. After E2/E3 the surviving uses are admissibility guards only, but their scale is arbitrary and
  mesh-size dependent. Not a CP4c-0 measure; do not fold it into CB2.
- [ ] **Sweep for other tolerant-selector / exact-consumer seams.** CP4c-0 found the pattern three times
  in one subsystem (flow classification, vertex sector, cross-edge flow). The same audit is owed wherever
  an exact authority was introduced downstream of a `double` decision.

# Directional — Current handoff

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical information required to continue safely. Architecture belongs in `DESIGN.md`; tasks in `TODO.md`; completed history in `CHANGELOG.md`; lessons in `LESSONS.md`; roadmap in `ROADMAP.md`; exact runtime evidence in retained reports/closure records and the regression tracker. Do not add transcripts, chronological tool history, tool/policy/procedural failures, copied old artifact tables, obsolete selections, or procedure owned by policy/skill files. Concision never authorizes deleting durable information.

This section is durable and must be preserved. The displaced chronological handoff remains in Git history, **not** as instructions to replay.

All instructions and sections prefixed `[ChatGPT Web]` are mandatory for `ChatGPT Web` sessions. Non-`ChatGPT Web` agents (`ChatGPT Work`, `Codex`, `Claude`, etc.) can ignore instructions/sections bearing that prefix.

## Policies - Read first at start of every turn - DURABLE, DO NOT DELETE

Policies cannot be deleted or modified without explicit user authorization. The list uses verified existing paths (three old template filenames were outdated).

| Policy | File |
|---|---|
| Turn Cadence | `.agents/Directional/Turn_Cadence.md` |
| Agent Policy | `.agents/Directional/AGENT_POLICY.md` |
| Mandatory Start Checklist | `.agents/Directional/Mandatory_Start_Checklist.md` |
| Clean up Policy | `.agents/Directional/CLEAN_UP_POLICY.md` |
| Handoff Policy | `.agents/Directional/Durable_Handoff_Policy.md` |
| GitHub Workflow Policy | `.agents/Directional/GitHub_Workflow_Policy.md` |
| GMP Compile Policy | `.agents/Directional/GMP_COMPILE_POLICY.md` |
| Retention Policy | `.agents/Directional/RETENTION_POLICY.md` |
| Review Turn Policy | `.agents/Directional/REVIEW_TURN_POLICY.md` |
| Tool Use Conservation Policy | `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` |
| Patch Application Strategy | `.agents/Directional/Patch_Application_Strategy.md` |
| Mandatory End Checklist | `.agents/Directional/Mandatory_End_Checklist.md` |

## Current immutable authority — replace in place

| Field | Exact value / evidence owner |
|---|---|
| Currency | 2026-11-27 UTC. TB-REV-189 independently accepts the activated 1006/1006 test gate (CP2 491/491; membership 1087 = 1006 gated + 81 deferred). NotApplicable legacy fallback confirmed; BB3 falsified (cell164 non-disk bridge excursion). No produced sphere. V5 not rerun: Cylinder PASS 288, Vase RED, BunnyRandom ABNORMAL at 600 s. Stable 67/17/50, debt1/deferred81; no CP3/497/D0/H4 promotion. [Review](Architecture_M6_CP3_TB_REV_189_Sphere_Route_Witness_Independent_Review_20261127.md). [Adversarial](Architecture_M6_CP3_TB_REV_189_Adversarial_Review_20261127.md) withdrew CB-213. [DEFN-65C](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md) froze CB-214 (A2b walk→A3 boundary schedule, behaviour-neutral). CB-214 compiled; no runtime credit. Next `M6-CP3-TB-EXEC-191`. |
| Branch / source | PR #8 draft/open, `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-214 source `9ed5560822ae435e55101206dcb6ecda59bca706`, candidate `15175464398` ZIP SHA-256 `d53298314ab80c89e2fd9e8891b8883b798f4d6e9029acf5e3b177070eba108b`, [compile run 45949296543](https://github.com/akashskypatel/Directional/actions/runs/45949296543), 28/28 checks, eight GMP/GMPXX targets, `runtimeExecution=false` ([record](Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md)). CB-212 and earlier: owning records. |
| Current TB evidence | [TB189 report](Architecture_M6_CP3_TB189_Sphere_Route_Witness_Execution_Report_20261127.md), run `45936843671`, result `15171482516` ZIP `9cf3decbf3dea3a11aa645ec5d5db12307508e73611f962d65c78862ec9b70da`, 2020/2020 checks, CP2 491/491, membership1087. [TB-REV-189](Architecture_M6_CP3_TB_REV_189_Sphere_Route_Witness_Independent_Review_20261127.md) accepts 1006/1006; TB188 reference result `15163822727`. V5 run `45920872749`, result `15165185584`, missing BunnyRandom resource receipt. Older comparators: owning records. |
| Historical comparison | TB182 `14979452472` (1004/1004), TB181 `14967943314`, TB180 `14951803089`; manifests 1004 `d778afbe…8ca5f`, 1003 `2928fd31…f724`, TB169 `82581dd1…e436`, CP2 491 `483f1101…a038`. |
| Regression / debt | Row971 defect discharged for pinned contract. B1 (fallback cell164) held, off-trajectory; fallback cannot be certified (DESIGN §5.2). B2 off-gate runtime cause unproved. Stable 67/17/50, debt1/deferred81; J6 not exercised. |
| Executor | Unchanged harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. TB-EXEC-191 uses the candidate source checkout (older executor lacks the new manifest). Inputs in [record](Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md); no rebuild or V5. |
| Terminal execution request | `m6-cp3-tb189-exec` [run 45936843671](https://github.com/akashskypatel/Directional/actions/runs/45936843671), job `140302018167`, exit0, postflight PASS, attempt1. [Report](Architecture_M6_CP3_TB189_Sphere_Route_Witness_Execution_Report_20261127.md). |
| First unresolved question | Does every sphere (and genus_two) region walk bind to its A3 spans? CB-214/TB-EXEC-191 measure it (predicted 14 regions, 60 sides, 30 paired arcs, all even). Then corners: sphere regions 5 and 10 have 3 walk nodes, impossible for a regular disc with node-only corners (A4D5). Vase is ungated end-to-end. |

## Mandatory next turn

- **COMPLETE:** … → TB-REV-187Q → CB-206 → TB-EXEC-186T → TB-REV-186T (+[adv.](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb_rev_186t_adversarial_review_20261126md)) → TB-REV-186 → CB-209/210 → TB-EXEC-188 → TB-REV-188 → CB-211R → CB-212 (compile only) → TB-EXEC-189 → TB-REV-189 (+adv.) → DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION → CB-214 (compile only).
- **TB-REV-189 adv.** ([record](Architecture_M6_CP3_TB_REV_189_Adversarial_Review_20261127.md)): one closed source-topology region, three declines at the global singularity guard, so CB-213 is code-determined (CC1). It repeats CB102 and violates RA-214 §1.3, so it is WITHDRAWN (CC2). A4 is per A2b disc (DESIGN §5/§5.2/§2.1.7, RA-213), so the ownership DEFN is struck (CC3). No A4 code builds a fragment disc (CC4). Resume 65A–65D (CC5).
- **DEFN-65C** ([record](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md)): A4D1 unit = A2b region; A4D2 domain = boundary schedule → corners → fill; A4D3 owner in A3 module (duplicate lookup debt O50); A4D4 three reachable typed reasons; A4D5 corner falsifier. CB-214 exact diff compiled; [record](Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md).

```text
NEXT_TURN: M6-CP3-TB-EXEC-191
Owner: Test + Benchmark only. Run the frozen 1008-row gate once on CB-214 package 15175464398; no rebuild, retry, timeout substitution or V5.
Authority: Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md; gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md.
  Source/executor checkout 9ed5560822ae435e55101206dcb6ecda59bca706; unchanged harness 423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c; candidate ZIP d53298314ab80c89e2fd9e8891b8883b798f4d6e9029acf5e3b177070eba108b.
  Manifest ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081; 1089 members = 1008 gated + 81 deferred; CP2 491. Rows 1007/1008 new; row858 +16 predicted lines; other inherited rows N1–N3 = TB189 15171482516. STOP on failure or prediction mismatch; preserve evidence.
Then: TB-REV-191 -> corners DEFN (A4D5).
Do not: repair B1/fallback, change dispatch or the veto, activate the schedule, CB-207D, promote CP3/497/D0/H4, start J6/E5/CB-190.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-REV-177 | Adversarial records TB-REV-162…177 (`Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`); TB169 993/993 accepted; TB170–TB177 rejected (same 7 RED); D13 = A ([TB-REV-173](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)). |
| COMPLETE | CB-199A → … → TB-REV-183 (TB179–TB183; 1003→1005 accepted) | Reports and reviews folded in [Vol D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md); adversarial records `Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`. |
| COMPLETE | CB-204 → TB-EXEC-184 (1005/1005) → TB-REV-184 (+[adv.](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md)) → CB-205 → TB185/185R/185S (invalid) → CB-205R/S/T → TB185T → TB-REV-185T (+[adv.](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md)) | [TB185T](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md); others via CHANGELOG, invalid attempts in Vol D3. |
| COMPLETE | CB-205V → TB-EXEC-185V (1006/1006) → TB-REV-185 (+[adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md); X1 corrected by TB-REV-188 adv.) → CB-207A/B → TB-EXEC-187Q (1006/1006) → TB-REV-187Q (+[adv.](Architecture_M6_CP3_TB_REV_187Q_Adversarial_Review_20261126.md)) | [TB185V](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md), [TB187Q](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md); other records via CHANGELOG. |
| COMPLETE | TB-EXEC-186 RED → TB-REV-186 (+adv.) → CB-209/210 → TB-EXEC-188 → TB-REV-188 (gate accepted, V5 unaccepted; +[adv.](Architecture_M6_CP3_TB_REV_188_Adversarial_Review_20261127.md)) | [Review](Architecture_M6_CP3_TB_REV_188_Completion_Receipt_Activated_Full_Gate_Independent_Review_20261127.md). |
| COMPLETE | CB-211R → CB-212 → TB-EXEC-189 (1006/1006) → TB-REV-189 (+[adv.](Architecture_M6_CP3_TB_REV_189_Adversarial_Review_20261127.md)) | [Manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md). |
| **4D NEXT** | DEFN-65C (COMPLETE) → `M6-CP3-CB-214-P13-REGION-BOUNDARY-SCHEDULE` (COMPLETE, compile only) → TB-EXEC-191 (NEXT, 1008 rows) → TB-REV-191 → corners DEFN/CB/TB (A4D5; Vase row) → fill DEFN/CB/TB → 65B → 65D dispatch (O50, Amendment-19) → O41/switch | [Manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md). B2 mechanism is a separate Review item. B1 repair, parameter deletion → V3b → R1 → O48 held. CB-207D held. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-213 `c251d83b…` + TB-EXEC-190/TB-REV-190 (TB-REV-189 adv. CC1–CC2); prose CB-211 plan (TB-REV-188 adv. BB4); CB-208 diff `15dd890d…` (TB-REV-186T adv. Z1); CB-206 → full gate before QF1 (TB-REV-185 adv. X1); prose CB-205U (TB-REV-185T adv. W3); prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); prose CB-197A/196/195/193/187/186/183/180/178/175/173, CB-194, CB-191, DEFN-161A/159A, CB-185 v1, activation-before-plan — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | Fallback repeated-node owner unadjudicated; BunnyRandom cost witness carried. CB-207C conditional; CB-207D held. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB-214 compile record](Architecture_M6_CP3_CB214_P13_Region_Boundary_Schedule_Code_Build_Record_20261127.md); [DEFN-65C](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md); [CB-214/TB-EXEC-191 manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md); [TB-REV-189 adversarial](Architecture_M6_CP3_TB_REV_189_Adversarial_Review_20261127.md); [TB-REV-189](Architecture_M6_CP3_TB_REV_189_Sphere_Route_Witness_Independent_Review_20261127.md); [RA-213/RA-214 (Vol D2)](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_disc_producer_runtime_free_resolution_20261108md); [D10 record](Architecture_M6_CP3_DEFN_P13_A4_Size_Grading_Decision_Review_20261112.md); [DESIGN.md](DESIGN.md) §5, §7; [TB189 report](Architecture_M6_CP3_TB189_Sphere_Route_Witness_Execution_Report_20261127.md); [LESSONS.md](LESSONS.md). Older sphere-route records: via CHANGELOG.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff. Earlier CB/TB/RA records (TB138 back to RA-244), their compile records and preserved exact diffs resolve through `load_next` Reviews and [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
3. [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md), [DESIGN.md](DESIGN.md), [tracker](Regression_Root_Cause_Tracker.md) and [TODO](../../TODO.md).
4. [Historical record index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17) resolves superseded filenames; old turn ladders and navigation preimages are history only, not instructions. CB84 Linux Vase diagnostic timing attempt, CB121A 16-row fan-resolver plan and CB102 withdrawn. Reviews runtime-free; no deprecated scratch-build authorization. D6 pending, chain switch off.

**Review tooling:** `tools/review_check.py authority <sha>` and `tools/review_check.py boundary`, `tools/selector_probe.py` and `tools/fixture_probe.py`; see [tools/README.md](tools/README.md). Consult original normative definitions and [LESSONS.md](LESSONS.md) before any later evidence or semantic decision.

## Resume-critical lessons — DURABLE, DO NOT DELETE

The substantive lessons live in `LESSONS.md`; use the relevant section rather than copying incident accounts.

| Section | Read it before |
|---|---|
| 1. Evidence, acceptance, and scope | Interpreting results, claiming acceptance, changing gates/selectors or classifying regressions. |
| 2. Witnesses, tests, and independent oracles | Designing fixtures, tests, invariants or independent checks. |
| 3. Semantic ownership, identity, and dataflow | Modifying semantic IDs, representations or producer-consumer contracts. |
| 4. Geometry, topology, and mathematical obligations | Changing geometric algorithms, topology or exact predicates. |
| 5. Diagnostics, classifiers, and causal investigation | Instrumentation, rejecting predicates or root-cause hypotheses. |
| 6. Contracts, planning, reviews, and durable records | Requirements, plans, reviews, authorization or documentation. |
| 7. Build, artifact, workflow, and tool mechanics | Compilation, packaging, CI, artifacts or repository operations. |

New lessons belong in `LESSONS.md`, not here.

## Maintenance — one live handoff

At authorized closeout, **replace** current authority, next action, conditional successor and context **in place**. Keep the durable purpose/policy/load/lesson sections. Archive completed changes in `CHANGELOG.md`, evidence in reports/tracker, tasks in `TODO.md`. Never append a second `CURRENT` section, a transcript or old turn ladder. The mandatory end checklist and `Durable_Handoff_Policy.md` govern `STATUS` closeout.

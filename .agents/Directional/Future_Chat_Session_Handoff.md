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
| Currency | 2026-11-27 UTC. [TB192 report](Architecture_M6_CP3_TB192_Singularity_Arrival_Execution_Report_20261127.md): 1010/1010 independently accepted for the test gate only ([TB-REV-192](Architecture_M6_CP3_TB_REV_192_Singularity_Arrival_Independent_Review_20261127.md)). Row858: 10 radial-edge arrivals, all matched and all `portTraced=1`; genus_two has zero arrivals. Rows1009/1010 PASS. D13 = A. [TB-REV-192 adv.](Architecture_M6_CP3_TB_REV_192_Adversarial_Review_20261127.md): 10 claimed ports exact, removal = deletion (14 traces, V12/E18/F8 predicted); O52 slivers 2/4. TB191 comparator 1008/1008; CP2 491/491. Stable 67/17/50, debt1/deferred81. V5 not rerun (Cylinder PASS 288, Vase RED, BunnyRandom ABNORMAL 600 s). |
| Branch / source | PR #8 draft/open, `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-216 source `c76e74b3…3033`, candidate `15192246171` ZIP SHA-256 `e92edf8686722ac4ec96dc07217e7a13923d8786cf89dc6d513793aac381b004`, [compile run 45986095420](https://github.com/akashskypatel/Directional/actions/runs/45986095420), 28/28 checks, eight GMP/GMPXX targets, `runtimeExecution=false` ([CB-216 record](Architecture_M6_CP3_CB216_P13_Singularity_Arrival_Classification_Code_Build_Record_20261127.md)). Prior builds: owning records. |
| Current TB evidence | [TB192 report](Architecture_M6_CP3_TB192_Singularity_Arrival_Execution_Report_20261127.md), run `45992751511`, result `15195820651` ZIP `37bd0d7c8ba3abe1f3f1c74c0140903b9e880bf537e38982111621c472aea0ce`, 2028/2028 checks; 1010/1010 accepted test gate, membership1091 ([TB-REV-192](Architecture_M6_CP3_TB_REV_192_Singularity_Arrival_Independent_Review_20261127.md)). TB191 comparator `15179335926` ZIP `bab546af9cc089db9deb405ede41b3dd859b9e4547f81507d669c58c911bb519`, [accepted review](Architecture_M6_CP3_TB_REV_191_Region_Boundary_Schedule_Independent_Review_20261127.md). V5 run `45920872749`, result `15165185584`, missing BunnyRandom resource receipt. |
| Historical comparison | TB182 `14979452472` (1004/1004); older via CHANGELOG; manifests 1004 `d778afbe…8ca5f`, 1003 `2928fd31…f724`, TB169 `82581dd1…e436`, CP2 491 `483f1101…a038`. |
| Regression / debt | O51 measured, non-stable and open; removal AP4 undecided. O50 open. Row971 defect discharged for pinned contract. B1 (fallback cell164) held, off-trajectory; fallback cannot be certified (DESIGN §5.2). B2 off-gate runtime cause unproved. Stable 67/17/50, debt1/deferred81; J6 not exercised. |
| Executor | Unchanged harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`; TB192 executor `c76e74b35ffa5ba6aa1f3f8662f592e077c63033`, TB191 `9ed5560822ae435e55101206dcb6ecda59bca706`. Both immutable; review is runtime-free. |
| Terminal execution request | `m6-cp3-tb192-exec`, run `45992751511`, job `140484678308`, exit0, postflight PASS, attempt1. |
| First unresolved question | AP4: removal rule for the 10 one-sided sphere co-traces. EE3: no kept trace stops on a claimed one, so A0 (delete + typed fail-closed, recommended) and A (fixed point) coincide on the sphere; new §7.2 step-7 text needs the user's decision. O52 (slivers 2/4) after AP4. Vase ungated end-to-end. |

## Mandatory next turn

- **COMPLETE:** … → TB-REV-188 → CB-211R → CB-212 → TB-EXEC-189 → TB-REV-189 (+adv.) → DEFN-65C → CB-214 → TB-EXEC-191 → TB-REV-191 (+adv.; gate accepted, no production) → CB-215 (compile only) → CB-216 (compile only) → TB-EXEC-192 (execution PASS) → TB-REV-192 (test gate accepted only; +adv. EE1–EE5).
- **TB-REV-192 adv.** ([record](Architecture_M6_CP3_TB_REV_192_Adversarial_Review_20261127.md)): gate upheld; EE1 ports exact; EE2 non-reciprocal; EE3 deletion exact; EE4 slivers 2/4 = O52 (corrects DD2); EE5 classifier hardening first.
- **TB-REV-191 adv.** ([record](Architecture_M6_CP3_TB_REV_191_Adversarial_Review_20261127.md)): gate/CB-214 upheld; DD1 34 = 24 ports + 10 arrivals; DD2 slivers are doubled separatrices, A2a-owned (owner claim corrected by the A2a DEFN §1); DD3 certificate sound; DD4 corners resequenced; DD5 unequal-side construction added.
- **A2a arrival DEFN** ([record](Architecture_M6_CP3_DEFN_P13_A2a_Singularity_Arrival_Port_Ownership_20261127.md)): ownership = D13 = A; AP1 A1 rays + A2a classifier; AP2 exact match rule; AP3 outcomes; AP4 removal rule user-pending; [manifest](gates/Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Exact_Manifest.md).

```text
NEXT_TURN: M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL
Owner: Review/DEFN only, runtime-free. STOP for the user's AP4 decision (A0 delete + typed fail-closed, recommended; or A suppress + re-trace fixed point) before freezing DESIGN §7.2 step-7 text.
Authority: TB-REV-192 adv. EE1-EE5 (sphere: 14 traces, V12/E18/F8; slivers 2/4 = O52, untouched), TB-REV-192 falsifiers, A2a arrival DEFN AP1-AP5, D13.
After the decision: freeze exact CB-217 (candidate-level unique, branch-consistent classification) and CB-218 (claimed co-trace removal) diffs, both compile only, plus the TB-EXEC-193 manifest. Then TB-REV-193 -> corners DEFN + O52. No build, runtime, V5, fallback repair, dispatch/veto change, promotion or held work.
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
| COMPLETE | DEFN-65C → CB-214 → TB-EXEC-191 (1008/1008) → TB-REV-191 (+[adv.](Architecture_M6_CP3_TB_REV_191_Adversarial_Review_20261127.md)) | [Manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md). |
| **4D NEXT** | A2a arrival DEFN (COMPLETE) → 1 CB-215 (COMPLETE, compile only) → 2 `M6-CP3-CB-216-P13-SINGULARITY-ARRIVAL-CLASSIFICATION` (COMPLETE, compile only) → 3 TB-EXEC-192 (COMPLETE, execution) → 4 TB-REV-192 (+adv.) → 5 `M6-CP3-DEFN-P13-A2A-PARTIAL-COTRACE-REMOVAL` (NEXT; AP4 user decision) → CB-217 → CB-218 → TB-EXEC-193 → TB-REV-193 → 6 `M6-CP3-DEFN-P13-A4-DISC-CORNERS` + O52 → CB/TB → 7 Vase row → 8 A4 unequal-side construction → 9 fill → 65B → 65D (O50, Amendment-19) → O41/switch | One DEFN → CB → TB each. B2 a separate Review item; B1, parameter deletion → V3b → R1 → O48, CB-207D held. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-213 `c251d83b…` + TB-EXEC-190/TB-REV-190 (TB-REV-189 adv. CC1–CC2); prose CB-211 plan (TB-REV-188 adv. BB4); CB-208 diff `15dd890d…` (TB-REV-186T adv. Z1); CB-206 → full gate before QF1 (TB-REV-185 adv. X1); prose CB-205U (TB-REV-185T adv. W3); prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); older prose CBs, CB-194, CB-191, DEFN-161A/159A, CB-185 v1 — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | Fallback repeated-node owner unadjudicated; BunnyRandom cost witness carried. CB-207C conditional; CB-207D held. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB-REV-192 adv.](Architecture_M6_CP3_TB_REV_192_Adversarial_Review_20261127.md); [TB-REV-192](Architecture_M6_CP3_TB_REV_192_Singularity_Arrival_Independent_Review_20261127.md); [TB192 report](Architecture_M6_CP3_TB192_Singularity_Arrival_Execution_Report_20261127.md); [CB-216 record](Architecture_M6_CP3_CB216_P13_Singularity_Arrival_Classification_Code_Build_Record_20261127.md); [CB-215 record](Architecture_M6_CP3_CB215_P13_Singularity_Ray_Classes_Code_Build_Record_20261127.md); [A2a arrival DEFN](Architecture_M6_CP3_DEFN_P13_A2a_Singularity_Arrival_Port_Ownership_20261127.md); [CB-215/216 manifest](gates/Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Exact_Manifest.md); [TB-REV-191 adv.](Architecture_M6_CP3_TB_REV_191_Adversarial_Review_20261127.md); [DEFN-65C](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md); [RA-213/RA-214 (Vol D2)](M6_Consolidated_Record_Vol_D2_CP3_P13_from_20261104.md#architecture_m6_cp3_defn_p13_a4_a2b_disc_producer_runtime_free_resolution_20261108md); [D10 record](Architecture_M6_CP3_DEFN_P13_A4_Size_Grading_Decision_Review_20261112.md); [DESIGN.md](DESIGN.md) §5, §7; [LESSONS.md](LESSONS.md). Older records: CHANGELOG.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff. Earlier CB/TB/RA records and diffs: [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
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

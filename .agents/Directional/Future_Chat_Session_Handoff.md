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
| Currency | 2026-11-23 UTC. TB-REV-172 rejects TB172 987/994 (7 mechanical RED). [Second adversarial continuation](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md) (C1–C7): lenses are exactly co-traced zero-area digons (decided by elimination); root cause is A2a (DESIGN §4.5/§4.6, :449); interval-receipt CB-194 withdrawn; exact shared-edge oracle CB-194 next; D13 pending (user). TB169 remains accepted 993/993. |
| Branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB193 source `587b8ba7b1a52409d2fd95cff99dbb9d1da8f881`, GMP/GMPXX compile `45147339047`, package `14805640405` (`58a49461…2cb`), `runtimeExecution=false`; TB172 no rebuild. |
| Current TB evidence | TB172 [run `45149928894`](https://github.com/akashskypatel/Directional/actions/runs/45149928894), artifact `14805479282` SHA-256 `e9ddc7fd80d3e33b25b18901c783fbb21ec2eaf5c1b86438f887e93cee03edbc`, internal **1996/1996** verified, 987/994 PASS, CP2 candidate 490/491, membership 1075; compare TB171 `14799346720` (987/994). [TB172 report](Architecture_M6_CP3_TB172_P13_Along_Edge_Visit_Region_Receipt_Full_Gate_Execution_Report_20261123.md). |
| Accepted comparison | TB169 run `45104059492`, ZIP artifact `14787082075` SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`, internal **1994/1994**, **993/993** accepted, CP2 **491/491** accepted. Frozen prefix SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. |
| Regression / debt | Historical **67 events / 17 categories / 50 recurrences**; witness debt1, deferred81. Same seven accepted-green mechanical controls 445/652/653/656/658/660/786 still RED; new empty-elected-draft subtype not new stable event. |
| First unresolved failure | `RegionElectedCutComponentEmpty` row652: lens orbits 1/3/4/5 are digons of reversed co-traced trace pairs 0/3, 2/8, 4/11, 7/9 along vertex chains 10…35, 10…47, 35…71, 47…71. A2a seeds every port, drops `CollinearOverlap`/`EndpointTouch`, loses the arrival port. Repair at A2a per D13; never credit opposite faces, skip empty drafts, merge arcs downstream, or revert CB-192. Row979 staged `RegionContainsInteriorSingularity` vertex8 |

## Mandatory next turn

- **COMPLETE:** TB-REV-172 (independent + two adversarial continuations). D13 asked, unanswered → re-ask at TB-REV-173 start.

```text
NEXT_TURN: M6-CP3-CB-194-P13-EXACT-SOURCE-PATH-SHARED-EDGE-ORACLE
Owner: implementation agent (Code + Build, compile only)
Authority: Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md (C1-C7); interval-receipt CB-194 (both forms) withdrawn
Apply exactly: .agents/Directional/Architecture_M6_CP3_CB194_P13_Exact_Source_Path_Shared_Edge_Oracle_Exact.diff
  SHA-256 7913097b108c6f8b0d74bedbded1048e5e4b45ae41ab892d069f9398957365e5 (7432 B, +129/-0)
  include/directional/authority/ExactSourcePath.h git c13c13efc3489d6477e5c7a14a06d75068a6ec68 -> sha256 9a6456e5686a01a86a768660ad0359268e07e5d13bca5a4ae2e6f157ae5b9d91
  tests/FieldAlignedCurveNetworkTests.cpp git dbee0e4ead77689f60e6ba6d137246819926c098 -> sha256 4c22f65e07a042f69b74e63a69d4034173078173cfabb84a0ff77898bbffe672
Build: dispatcher compile, GMP/GMPXX targets incl. directional_surface_cell_producer_tests, runtimeExecution=false
Then: M6-CP3-TB-EXEC-173-P13-SHARED-EDGE-ORACLE-FULL-GATE
  manifest gates/Architecture_M6_TB173_P13_Shared_Edge_Oracle_Full_Gate_Case_Manifest.tsv b54de0b28dc646b465daae0d40dd7874f550567fb904647c7dff36a4f2e2ff6e (996 rows, prefix 483f1101...038); membership 1077
  expected 989 PASS: rows 995/996 PASS, same 7 RED (445/652/653/656/658/660/786)
  rules: every other row = TB172 14805479282 under N1-N3 + diff-proven assertion-line moves (none expected); any other difference -> STOP to Review; no census
  -> M6-CP3-TB-REV-173-...: re-ask D13 first; then freeze CB-195 (A2a helpers: arrival-port record + mechanical no-shared-edge premise via oracle) and CB-196 (D13 wiring + every-region-owns-a-face assertion)
On failure/blocker: preimage/hash mismatch or compile failure -> STATUS BLOCKED, report verbatim, return to Review
Do not: edit beyond the diff; wire the oracle; change producer/region code; edit selectors/manifests; run tests; revert CB-192; activate; promote CP3/497/D0/H4
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → … → TB-EXEC-172 | Records: adversarial TB-REV-166…171 files; TB169 993/993 accepted; TB170 986/993, TB171/TB172 987/994 rejected; CB-192 package `14797941489`, CB-193 package `14805640405` (source `587b8ba7…f881`). |
| COMPLETE (rejected) | TB-REV-172 | [Independent](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md), [adv. 1](Architecture_M6_CP3_TB_REV_172_Adversarial_Review_20261123.md), [adv. 2](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md): co-traced digons, A2a root cause, D13 pending. |
| **NEXT** | CB-194 shared-edge oracle | Exact diff, compile only, unwired. |
| 2 | TB-EXEC-173 | 996 rows; 989 PASS, same 7 RED. |
| 3 | TB-REV-173 → CB-195 (A2a helpers) → TB → CB-196 (D13 wiring + region-owns-face assertion) → TB | D13 re-asked first; mechanical controls must turn green with 2 regions. |
| 4 | Row979 `RegionContainsInteriorSingularity` (vertex 8) | After mechanical controls green; read printed locus first. |
| 4A | Branch A (only after the staged plan builds): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-194 interval receipt, both forms (TB-REV-172 adv. 2 C1); prose CB-193 (TB-REV-171 adv. B5); CB-191 reason receipt (TB-REV-170 adv. A1/A6); prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB171 RED report](Architecture_M6_CP3_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Execution_Report_20261123.md), [TB-REV-170 adversarial review](Architecture_M6_CP3_TB_REV_170_Adversarial_Review_20261123.md), [CB-192 Code + Build](Architecture_M6_CP3_CB192_P13_Along_Edge_Face_Piece_Classifier_Code_Build_Record_20261123.md), [CB-189 Code + Build](Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-169 review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md), [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [CB-188 record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-168 independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), [CB-188 manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md), [CB-189 manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md), [TB168 execution report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md), [CB-187 code/build record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md), [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), [TB-REV-167 independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md), [TB167 report](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md).

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

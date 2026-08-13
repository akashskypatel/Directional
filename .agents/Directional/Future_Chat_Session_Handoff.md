# Future Chat Session Handoff

## Purpose

This file contains only durable operating policy, the exact next action, current immutable authority, and resume-critical blockers. Architecture belongs in `DESIGN.md` and `REORIENTATION_PLAN.md`; tasks belong in `TODO.md`; history belongs in `CHANGELOG.md`; exact review evidence belongs in the retained independent-review report and regression tracker.

## Durable handoff policy

At the end of every turn:

1. replace stale next-turn/status text instead of appending narrative;
2. keep only unresolved or immediately resume-critical facts;
3. move completed history to `CHANGELOG.md` and exact evidence to the owning report/tracker;
4. never treat a documentation/control-plane commit as implementation, build, or runtime evidence;
5. preserve the mandatory start/end checklists below.

Do not add transcripts, chronological tool history, copied artifact tables, superseded task selections, or generic procedure already owned by policy/skill files.

## Mandatory start-of-turn checklist

1. Review the turn-based-coding-agent skill if not already reviewed.
2. Fully review this handoff, `RETENTION_POLICY.md`, and `GitHub_Workflow_Policy.md`.
3. Review `TODO.md`, `DESIGN.md`, `REORIENTATION_PLAN.md`, the active M1 Code + Build plan, and the current independent-review report.
4. Confirm the branch head and exact source authority before any write.

## Mandatory next turn

Run one **bounded Code + Build R-A remediation turn for artifact-only retry 2**. The exact immutable package from `92bf0ae2b10856162f175d02aeac318e126f9d22` passed preflight/static inventory/postflight but failed organically at the aggregate authority layer. Do not rerun the unchanged package and do not mark R-A complete.

Repository: `akashskypatel/Directional`
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
PR: #8 remains open, draft, and unmerged
Failed candidate source: `92bf0ae2b10856162f175d02aeac318e126f9d22`
Compile run/job: `31655755100 / 94309741656`
T+B retry run/job: `31656958868 / 94313437913`
T+B result artifact: `9164742196`, SHA-256 `2260c0d672dd3a7836f8916648d02e51cd8e3c53b762f318a23b112d08871921`
T+B log artifact: `9164742553`, SHA-256 `6b07a47937736951b243465f3a4b5abc218d740c13dbb1eb101dcb3127d1066e`

Artifact-only retry 2 was immutable and orchestration-clean: exact result/log digests, archive safety, manifest **25/25**, five empty source-status snapshots, packaged **19-path / 50-probe / 206-match** static inventory, and postflight all passed. Discovery was non-vacuous (**13 authority-kernel / 232 producer / 179 completion / 84 validation**). Across **88 unique R-A contracts, 76 passed / 12 failed**, `orchestration_failed=0`, `rebuild=false`, `sourceMutation=false`, `packageRepair=false`.

Implement only the new retry-2 remediation section **0J** in `Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`:

1. make the aggregate derived-identity rejection diagnostic at the failing sub-invariant, then repair that invariant rather than bypassing `rebuild_aggregate_output_identity_caches`. The post-move success contract and multiple disconnected baselines now reach `component-merge-authority`; the provenance-only counterfactual reports `InvalidGlobalDerivedIdentity` before the final oracle. Because that counterfactual mutates only `outputVertexProvenance`, while the derived-identity rebuild consumes completed-patch/output lineages and typed source authority, this is evidence of a baseline aggregate identity blocker rather than the provenance mutation itself;
2. after the identity blocker is fixed, require the boundary final-oracle, missing-component-report, raw-projection counterfactual, and provenance-tamper contracts to reach their declared seams naturally. Do not weaken the final oracle or fabricate boundary authority;
3. fix component feature-option ownership. The aggregate component runner copies `componentOptions = options` onto compact component-local meshes but does not remap `featureMap.userHardEdges` / `userSoftEdges` from original-global vertex IDs. Build an explicit original-to-local vertex map per component, retain only edges wholly owned by that component, and add no-cross-component-leakage coverage. Then revalidate the hard-feature tamper and feature-bearing final-oracle contracts;
4. regenerate the complete R-A inventory and compile one fresh exact-source package through `agent-compile-reusable.yml`. Code + Build only; execute no generated binary/test/benchmark/discovery/CLI/fuzzer/custom input.

Completion authority is now **18/18**, optimizer/final-validator authority **8/8**, authority kernel **13/13**, isolation-seam authority **6/6**, source validator **8/8**, rail migration **7/7**, and source-support/chart **1/1**. Do not reopen CB-03/CB-04 unless new evidence directly implicates them.

No independent Review turn is requested. After the fresh compile package, retry the same immutable R-A semantic gate. R-A closes only on an organic pass.

RA-REV-23-F3 and RA-REV-22-F6 remain post-R-A hygiene. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

## Current authority

### Normative architecture

`.agents/Directional/DESIGN.md` remains authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest immutable runtime-accepted authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A closure status

- Overall R-A remains **open / runtime-rejected** for candidate `92bf0ae2b10856162f175d02aeac318e126f9d22` after artifact-only retry 2.
- Retry 2 run/job `31656958868 / 94313437913` consumed compile artifacts `9164349848 / 9164350085` without rebuild or mutation. Preflight, **19 paths / 50 probes / 206 matches** static inventory, discovery, and immutable postflight passed; **88 unique selected, 76 passed / 12 failed**, zero orchestration failures.
- CB-03 completion closure is runtime-confirmed for the retained set: **18/18** completion authority contracts passed, including both former positive stitch failures. CB-04 is runtime-confirmed for its focused authority set: **8/8** optimizer/final-validator contracts passed, including typed source mismatch and rail-builder exact-source scope.
- The remaining aggregate suite is **15/27**. Multiple ordinary disconnected baselines and `PostMoveAggregateOptimizerUsesRetainedSourceAuthority` now progress past the former optimization failure but stop at `component-merge-authority`. `FinalMergedOracleRejectsPostComponentProvenanceTamper` exposes `InvalidGlobalDerivedIdentity` before the intended final oracle; source analysis shows that rebuild does not consume the raw provenance vector being mutated, making the derived-identity gate the next baseline blocker.
- The hard-feature aggregate fixture still stops at `completion`. Exact source shows component execution copies global feature-map edge options onto compact local meshes without an original-global to component-local edge remap; this must be corrected before feature-rail aggregate/oracle contracts can be credited.
- Boundary/feature final-oracle counterfactuals remain uncredited because their seam callbacks were not reached. Do not alter their expected oracle semantics to make them green.
- Result/log evidence: `9164742196` SHA-256 `2260c0d672dd3a7836f8916648d02e51cd8e3c53b762f318a23b112d08871921` / `9164742553` SHA-256 `6b07a47937736951b243465f3a4b5abc218d740c13dbb1eb101dcb3127d1066e`.
- The first retry orchestration attempt `31656834137 / 94313056707` stopped before any packaged binary executed because its temporary preflight grepped obsolete inventory heading text; it is infrastructure-only evidence, not a semantic result.
- No stable regression event/recurrence is added: `92bf0ae2b10856162f175d02aeac318e126f9d22` remains an unaccepted R-A candidate. Historical totals remain **34 / 14 / 20**; M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

## Standing product state

- M1 is active; R-B through R-G remain pending after R-A.
- `PR8-R034 / G4-R007 / G4-B001` direct-torus `LocalSheetMismatch` remains active.
- G4-B002 `InvalidHardRailPairing` belongs to revised M4.
- G4-B003 nonzero periodic Z4 and G4-B004 positive multi-isolation evidence belong to M5/M6 after M1.
- Bunny/Vase remain later representative product/resource gates.
- Pipeline A remains unscheduled.

## Resume-critical lessons

- Compile success is build evidence, not semantic acceptance.
- A validator named source-authoritative must reject missing or mismatched typed source authority independently of optional sub-gates.
- A final oracle must receive independent remapped authority; disabling authority or deriving expected state from the output is not validation.
- Derived identity caches must be rebuilt by the same canonical constructor used by their consumers; copied cache kind or a second schema is authority duplication.
- Matching extent is not ownership; exact source-row topology pairing is required.
- A zero-selected test filter is orchestration failure, never a pass.
- A negative test proves only the guard it actually reaches. Check which guard rejects before crediting a contract to the intended validator.
- A non-null pointer is not a live object. After a container is moved from, pointers captured into it still dereference and still report the same variant alternative, but read empty state. Verify the mechanism, not just the symptom, before writing a corrective measure.
- Never delete an "obsolete" negative before its replacement exists and fails closed for the intended reason.
- An assertion on a hardcoded flag cannot fail. Published status flags must be derived from the validator that produced them.
- Do not answer semantic failure by weakening validation, fixtures, lineage, or no-substitution contracts.

## Mandatory end-of-turn checklist

1. Apply `CLEAN_UP_POLICY.md` and `RETENTION_POLICY.md`.
2. Update `TODO.md` for completed/open/blocked work and remove superseded live tasks.
3. Update `CHANGELOG.md` only for durable completed changes or accepted evidence.
4. Update the regression tracker only when a stable event/pattern/blocker changes.
5. Replace this handoff's next action and current authority.
6. Update PR #8's durable description when stale.
7. Add one final summarized PR #8 conversation comment after every other branch/PR write.

## Core references

- `TODO.md`
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`
- `.agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Regression_Root_Cause_Tracker.md`
- `.agents/Directional/CHANGELOG.md`
- `.agents/Directional/CLEAN_UP_POLICY.md`
- `.agents/Directional/RETENTION_POLICY.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `tests/TESTING_STRATEGY.md`

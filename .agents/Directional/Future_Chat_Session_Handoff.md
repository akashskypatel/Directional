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
3. Review `TODO.md`, `DESIGN.md`, `REORIENTATION_PLAN.md`, the retained R-A artifact-only Test + Benchmark plan, and the current closeout report.
4. Confirm the branch head and exact source authority before any write.

## Mandatory next turn

Run one **immutable artifact-only R-A Test + Benchmark retry (attempt 3)** against the fresh Code + Build package. Do not rebuild, relink, patch packaged source, mutate tests/fixtures, repair permissions/content, or change repository implementation during this turn. A zero-selected filter is orchestration failure, never a pass.

Repository: `akashskypatel/Directional`
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
PR: #8 remains open, draft, and unmerged
Implementation commit: `38d8d7d3e97f3b496e63979cb1348ed2cda304bc`
Exact compile/evidence source: `555109796188b318c788ef5777f622705ee0aa94`
Compile run/job: `31665352874 / 94338607395`
Compile result artifact: `9167759672`, SHA-256 `96401aac27a3a231533a785d107cb023cf50a304d06e821585e7c44597c6beb6`
Compile log artifact: `9167759825`, SHA-256 `ed859f380103b183fda2241c71ff877fa0bbc3dc0c808f5c4f5f57290daadda8`

The package is compile-valid at the Code + Build boundary: Release/static/Ninja/PRE_TEST **118/118**, build exit `0`; **26** packaged files with recursive self-excluding manifest **25/25**; five source-status snapshots empty; `runtimeExecution=false`. The regenerated R-A inventory is **19 paths / 59 probes / 261 matches**, raw projection **22 allowed / 0 unexpected**, face-count **2 / 0**, pipeline `stitchIdentity` assignments **2 / 0**, classifier self-test **4/4**, final static **PASS**.

Use `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md` as the execution authority and update `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md` with the exact immutable evidence. Re-run the complete R-A semantic gate, including non-vacuous independent discovery and the newly compiled aggregate identity/feature-option contracts. Preserve the package before and after runtime and prove no rebuild, source mutation, or package repair occurred.

If the gate passes organically with clean immutable pre/postflight and regenerated static inventory, record Step 4 / R-A closure. If any contract fails organically, keep R-A open, preserve the exact failure evidence, classify the earliest intended seam actually reached, and produce the next bounded Code + Build plan. No independent Review turn is requested before this retry.

**Independently reviewed at implementation `38d8d7d3e97f3b496e63979cb1348ed2cda304bc`: RA-CB-F1 through RA-CB-F5 are all CLOSED at the Code + Build boundary; the candidate is cleared for this retry.** F3 and F5 are implemented more strictly than their corrective measures required, and no weakened check was introduced. One durable-document defect was found and **already corrected in this handoff**: the preflight inventory match count read **245** where the packaged inventory regenerates at **261** (probe and path counts were correct), which would have made preflight fail on a correct package. No source, package, or artifact is affected and no recompile is required — package `9167759672 / 9167759825` from `5551097961` remains the valid runtime candidate. Record the regenerated counts verbatim from the packaged inventory in the retry report rather than transcribing them.

**RA-CB-F1 through RA-CB-F5 are Code + Build complete at implementation `38d8d7d3e97f3b496e63979cb1348ed2cda304bc`.** The post-move lifetime contract is isolated from aggregate success; the retry plan carries exact completion/stitch discrimination reasons; a same-region/sheet different-support negative remains fail-closed; boundary-cache anti-stale coverage now proves valid canonical publication and exact rebuild accounting; component hard/soft edge transport is conserved with typed unassigned diagnostics and hard-edge fail-closed behavior. These semantic contracts are compiled, not executed.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority until the retry is accepted. RA-REV-23-F3 and RA-REV-22-F6 remain post-R-A hygiene.

## Current authority

### Normative architecture

`.agents/Directional/DESIGN.md` remains authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest immutable runtime-accepted authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A closure status

- Overall R-A remains **open / runtime-pending** for fresh candidate `555109796188b318c788ef5777f622705ee0aa94`. Compile success is not semantic acceptance.
- Prior runtime candidate `92bf0ae2b10856162f175d02aeac318e126f9d22` remains rejected after retry 2 (**88 unique selected, 76 passed / 12 failed**); its exact failure evidence remains in `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`.
- Section 0J plus RA-CB-F1 through RA-CB-F5 are Code + Build complete: aggregate identity rebuild remains canonical/fail-closed; retained source-authority lifetime is isolated from aggregate success; completion/stitch discrimination is explicitly reason-captured; anti-stale boundary-cache publication is falsifiable; and component hard/soft feature transport is conserved with typed unassigned accounting.
- Fresh source/static evidence is **19 paths / 59 probes / 261 matches**, final static **PASS**. Fresh compile run/job `31665352874 / 94338607395` produced artifacts `9167759672 / 9167759825` with **118/118**, manifest **25/25**, five empty source-status snapshots, and no generated runtime execution.
- Actual runtime acceptance of the RA-CB-F1/F3/F4/F5 semantic contracts, amended reason capture, aggregate/final-oracle reachability, and closure of prior retry-2 failures are intentionally unclaimed until immutable Test + Benchmark retry attempt 3 executes this exact package.
- No stable regression event/recurrence is added at this compile-only boundary. Historical totals remain **34 / 14 / 20**; M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority.

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
- A derived cache must be reconstructible from canonical authority; missing cache cardinality is not itself source authority and must not become a precondition for rebuilding that cache.
- Global source vertex IDs must be explicitly remapped before feature options are passed into compact component-local meshes; ownership is not preserved by copying options.
- In Actions, tracked `.agents` files can still match repository ignore rules; stage intentionally modified audit files with `git add -f` rather than mistaking an ignore refusal for a source defect.

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
- `.agents/Directional/Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Regression_Root_Cause_Tracker.md`
- `.agents/Directional/CHANGELOG.md`
- `.agents/Directional/CLEAN_UP_POLICY.md`
- `.agents/Directional/RETENTION_POLICY.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `tests/TESTING_STRATEGY.md`

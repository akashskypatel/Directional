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

Run one **immutable artifact-only R-A Test + Benchmark retry** against the fresh Code + Build package below. Do not rebuild, edit source/tests/fixtures, repair the package, or activate the dormant full-M1 plan.

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
PR: #8 remains open, draft, and unmerged  
Exact candidate source: `92bf0ae2b10856162f175d02aeac318e126f9d22`  
Compile run/job: `31655755100 / 94309741656`  
Compile result artifact: `9164349848`, SHA-256 `499bb4b4b6bd33408284bb3985bb04f0bda7312834b462b806965f7799e45870`  
Compile log artifact: `9164350085`, SHA-256 `a7fa938991c13d6a79cf4fdab85669d3e37e6eb625dc2541d8c8fdea2388938f`

Pre-runtime requirements: verify the exact source commit, outer artifact digest, archive/path safety, self-excluding manifest **25/25**, dependency revisions, all five empty source-status snapshots, `runtimeExecution=false`, and the packaged **19-path / 50-probe / 206-match** R-A static inventory. A zero-selected filter is orchestration failure.

Execute the same continuous R-A closeout semantic gate that failed on attempt 1, including the F1/F3/F4 aggregate final-oracle contracts, complete `SurfaceCellAuthorityContractCutover.*` selection, retained completion authority contracts, source-authoritative validator contracts, optimizer/final-validator authority contracts, rail-authority migration, isolation-seam authority, source-support/chart authority, plus the new `PostMoveAggregateOptimizerUsesRetainedSourceAuthority` and typed source-authority mismatch optimizer negative. Do not weaken filters or substitute proxy tests.

If every selected contract passes organically and immutable postflight remains clean, mark Step 3 and Step 4 / R-A complete. Any organic semantic failure returns to a bounded Code + Build turn with the exact failing contract and runtime evidence. **No independent Review turn is requested before this retry.**

`R-A-TB-CB-00` through `R-A-TB-CB-04` are Code + Build complete / compile-valid at `92bf0ae2b10856162f175d02aeac318e126f9d22`. CB-00 specifically did not fabricate the unavailable `surfaceCellTopologyRegionCount`: artifact `9163003950` contains no serialized/printed instance of that field; exact-source inspection confirmed the reviewed use-after-move mechanism instead.

RA-REV-23-F3 and RA-REV-22-F6 remain post-R-A hygiene and do not block this runtime retry. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority until the candidate is organically accepted.

## Current authority

### Normative architecture

`.agents/Directional/DESIGN.md` remains authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest immutable runtime-accepted authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A closure status

- Overall R-A remains **open / runtime-pending** for candidate `92bf0ae2b10856162f175d02aeac318e126f9d22`; Code + Build does not establish semantic acceptance.
- `R-A-TB-CB-00` through `R-A-TB-CB-04` are Code + Build complete / compile-valid. CB-00 could not read `surfaceCellTopologyRegionCount` because neither retained runtime artifact serializes it; exact source confirms the use-after-move mechanism and no value was invented.
- CB-01 removes all five post-move `phaseFrontProduct->sourceTopologyRegions` reads, nulls the stale pointer, and routes consumers through the retained pre-move `surfaceCellContext.sourceTopologyRegions`; strict exact-source validation remains unchanged.
- CB-03 separates source-face support authority from geometry projection and publishes owner-valid chart closure over support faces, while generated-interior fixtures now provide real source geometry.
- CB-04 replaces the raw-sheet expectation with a typed exact-owner mismatch negative and completes the rail-builder source-scope fixture.
- Static inventory at `92bf0ae2b10856162f175d02aeac318e126f9d22`: **19 paths / 50 probes / 206 matches**, raw projection **22/0**, face-count **2/0**, pipeline `stitchIdentity` assignments **2/0**, stitch-kind self-test **4/4**, final **PASS**.
- Compile run/job `31655755100 / 94309741656`: Release/static/Ninja/PRE_TEST **118/118**, exit `0`; artifacts `9164349848 / 9164350085`; manifest **25/25**; five empty statuses; no generated runtime executed.
- The mandatory next gate is the immutable artifact-only R-A semantic retry. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains runtime authority; historical regression totals remain **34 / 14 / 20**.

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

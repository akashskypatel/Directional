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

Run **step 3 of the continuous R-A closeout sequence**: one immutable **artifact-only Test + Benchmark turn** against the fresh RA-REV-22-F4/F5 and RA-REV-23-F2 correction package. Do not rebuild or change implementation, test, benchmark, build, fixture, or inventory source.

Repository: `akashskypatel/Directional`
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
PR: #8 remains open, draft, and unmerged
Exact compile-valid implementation/test/audit source: `64fa65a9379ad0a246393371516de3a3a7146243`
Compile run/job: `31649372167 / 94290107577`
Result artifact: `9162042615`, SHA-256 `c521a94e087f660cf93b6ebb9791ae1d0979a885e89eee621bc9c2fa6efe9322`
Log artifact: `9162042971`, SHA-256 `58c64afba7d0c31ea83ac8922128c338694fbf5f0bc94150b94138d94bc6c0e8`

Before executing any packaged binary, verify exact source `64fa65a9379ad0a246393371516de3a3a7146243`, both outer artifact digests, recursive self-excluding manifest **25/25** with zero self references, all five empty source-status snapshots, dependency revisions, Release/static/Ninja/PRE_TEST build exit `0`, and `runtimeExecution=false`. Extract the packaged source archive only for evidence inspection and verify `R_A_Closure_Inventory_Report.md` reports **19 paths, 48 probes, 203 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, 4/4 stitch-kind classifier self-tests, final static PASS**.

Then execute the complete focused R-A gate, without rebuilding. It must include:

- `FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent`, requiring the actual final-oracle issue list to contain `ChangedBoundaryLoop` with zero aggregate publication;
- `FinalMergedOracleRejectsChangedRemappedFeatureRailContent`, preserving non-empty feature authority/cardinality and requiring the actual final-oracle issue list to contain `MissingFeatureRail` with zero publication;
- `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority`, which must prove its precondition `expectedFeatureRailCount > 0` before acceptance;
- retained `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority`, `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`, `FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`, `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches`, and the renamed component aggregation-seam tamper contracts;
- retained REV-21 permutation-pair, REV-23 canonical/re-stitch, REV-24 null/foreign-authority, transactional rollback, optimizer/final-validator authority, and zero-publication contracts needed to detect regressions.

A zero-selected filter is orchestration failure. If a feature-bearing test fails its explicit fixture precondition, classify it as fixture adequacy rather than a semantic contract failure and return to Code + Build. Classify every failure from immutable runtime evidence. Do not rebuild, weaken validation, restore aliases/fallbacks, or alter fixtures inside this Test + Benchmark turn.

Mark overall R-A complete only if this single gate passes organically and the packaged/regenerated static inventory remains clean. Any organic failure returns to Code + Build; R-A does not close on a partial pass.

The retained full M1 artifact-only plan remains dormant until one fresh complete R-A-through-R-G package exists. Do not implement M3, M4, M7, or Pipeline A during this cadence turn.

## Current authority

### Normative architecture

`.agents/Directional/DESIGN.md` remains authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest immutable runtime-accepted authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A closure status

- Overall R-A remains **open / not runtime-accepted**.
- RA-REV-22-F1/F2/F3 and RA-REV-23-F1 remain independently re-reviewed closed at the Code + Build boundary at `032d4cbae9e2de2767579934682e78754180338d`.
- RA-REV-22-F4/F5 and RA-REV-23-F2 are now **Code + Build remediated / compile-valid** at exact source `64fa65a9379ad0a246393371516de3a3a7146243`. They are not independently or runtime accepted.
- F4 adds present-but-wrong boundary/feature final-oracle negatives, a feature-bearing positive witness, and full final-oracle issue-list diagnostics. F5 removes residual option-echo assertions. F2 hardens structural stitch-kind auditing across every pipeline translation unit and proves four evasion cases are caught.
- Complete R-A inventory is regenerated and static-PASS: **19 paths, 48 probes, 203 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline `stitchIdentity` assignments, 4/4 stitch-kind self-tests**.
- Fresh compile evidence: run/job `31649372167 / 94290107577`, artifacts `9162042615 / 9162042971`, exact source `64fa65a9379ad0a246393371516de3a3a7146243`, Release/static/Ninja/PRE_TEST **118/118**, build exit `0`, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.
- No new semantic contract executed in this Code + Build turn. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority; regression totals remain **34 events / 14 categories / 20 recurrences**.

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

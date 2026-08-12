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

Run **step 1 of the R-A closeout sequence**: one **artifact-only Test + Benchmark cadence turn** against the fresh RA-REV-22-F1/F2/F3 and RA-REV-23-F1 correction package. Do not rebuild or change implementation, test, benchmark, build, fixture, or inventory source.

The independent re-review at `032d4cbae9e2de2767579934682e78754180338d` **closed** RA-REV-22-F1/F2/F3 and RA-REV-23-F1 at the Code + Build boundary and opened three non-blocking follow-ups (RA-REV-22-F4, RA-REV-22-F5, RA-REV-23-F2). **This turn cannot close overall R-A** — RA-REV-22-F4 leaves the aggregate content-mismatch contract unwritten. Full sequence and evidence: `Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`, section "Concrete R-A closeout sequence"; task breakdown in `TODO.md`.

Repository: `akashskypatel/Directional`
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
PR: #8 remains open, draft, and unmerged
Exact compile-valid implementation/test source: `032d4cbae9e2de2767579934682e78754180338d`
Compile run/job: `31644502450 / 94274781412`
Result artifact: `9160266493`, SHA-256 `0980b3ca20c1e50be9323c99ecd3fca6d77f8df4655cd84eae9e0917d450ea11`
Log artifact: `9160266848`, SHA-256 `145a614170bec6cd949e51b5113e78509480bffb01670ecbabba9687f89c045d`

Before executing any packaged binary, verify exact source, outer artifact digests, recursive self-excluding manifest **25/25**, five empty source-status snapshots, dependency revisions, Release/static/Ninja/PRE_TEST build exit `0`, and `runtimeExecution=false`. Extract the packaged source archive only for evidence inspection and verify `R_A_Closure_Inventory_Report.md` reports **19 paths, 42 probes, 186 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline stitchIdentity assignments, final static PASS**.

Then execute, without rebuilding:

- `FinalMergedOracleRejectsMissingRemappedBoundaryAuthority` and `FinalMergedOracleRejectsMissingRemappedFeatureAuthority`; both must reach the final-oracle counterfactual seam, fail with the expected validator issue, and publish no aggregate semantics;
- `FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing` and `DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches`, the positive aggregate contract that cross-checks published strict/provenance/boundary/feature flags against `finalSourceAuthorityValidationResult`;
- `ComponentBoundaryRailTamperRejectsAtAggregationSeam` and `ComponentFeatureRailTamperRejectsAtAggregationSeam` — the renamed component tamper tests, classified only as seam-guard coverage. Do not use their pre-`032d4cba` names; a filter built from those selects zero tests;
- retained REV-21 permutation-pair, REV-23 canonical/re-stitch, REV-24 null/foreign-authority, transactional rollback, optimizer/final-validator authority, and zero-publication contracts needed to detect regressions.

A zero-selected filter is orchestration failure. Classify every failure from immutable runtime evidence. Do not rebuild, weaken validation, restore aliases/fallbacks, or alter fixtures to synthesize green output.

If `ComponentFeatureRailTamperRejectsAtAggregationSeam` or `FinalMergedOracleRejectsMissingRemappedFeatureAuthority` fails its `ASSERT_TRUE` fixture precondition, that is a fixture-adequacy failure (the `userHardEdges {0,2}` interior diagonal did not yield a hard-feature rail), not a contract failure. Classify it as such.

Do **not** mark overall R-A complete from this turn even if everything passes: RA-REV-22-F4, RA-REV-22-F5, and RA-REV-23-F2 must land in a Code + Build turn first, followed by a fresh package and a final artifact-only turn. See the closeout sequence in the independent-review report.

The retained full M1 artifact-only plan remains dormant until one fresh complete R-A-through-R-G package exists. Do not implement M3, M4, M7, or Pipeline A during this cadence turn.

## Current authority

### Normative architecture

`.agents/Directional/DESIGN.md` remains authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains the latest immutable runtime-accepted authority. Regression totals remain **34 events / 14 categories / 20 recurrences**.

### R-A closure status

- Overall R-A remains **open / not runtime-accepted**.
- The four follow-up findings from the `9d88d0e...` review are **Code + Build remediated at `032d4cbae9e2de2767579934682e78754180338d` and independently re-reviewed CLOSED at that boundary**. Still not runtime accepted.
- Three new non-blocking follow-ups are open, all owned by closeout step 2: **RA-REV-22-F4** (aggregate oracle proven only against *absent* boundary/feature authority; no `ChangedBoundaryLoop`/rail content-mismatch negative), **RA-REV-22-F5** (`strictValidationUsed` and `authoritativeFeatureRailsUsed` remain option echoes, so two `EXPECT_TRUE`s cannot fail), **RA-REV-23-F2** (the structural stitch-kind probe misses wrapped assignments, `directional::geometry::` qualification, aliases, and `= <expr>.kind` stale-kind copies).
- RA-REV-22-F1: post-remap boundary/feature authority counterfactuals target the final oracle; the older component tamper tests are explicitly aggregation-seam coverage.
- RA-REV-22-F2: aggregate strict/provenance/boundary/feature usage flags are final-oracle-derived.
- RA-REV-22-F3: the typed final-oracle result is published independently of component report completeness.
- RA-REV-23-F1: structural inventory prohibits pipeline stitch-kind schema assignment and classifies every pipeline `stitchIdentity` write.
- Complete R-A inventory is regenerated and static-PASS: **19 paths, 42 probes, 186 matches, 22/0 raw-projection leaves, 2/0 face-count leaves, 2/0 pipeline stitchIdentity assignments**.
- Fresh compile evidence: run/job `31644502450 / 94274781412`, artifacts `9160266493 / 9160266848`, exact source `032d4cbae9e2de2767579934682e78754180338d`, Release/static/Ninja/PRE_TEST **118/118**, manifest **25/25**, five empty source-status snapshots, `runtimeExecution=false`.
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

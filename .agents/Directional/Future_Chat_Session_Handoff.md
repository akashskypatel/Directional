# Future Chat Session Handoff

## Purpose

This file contains only durable operating policy, the exact next action, current immutable authority, and resume-critical blockers. Architecture belongs in DESIGN.md and REORIENTATION_PLAN.md; tasks belong in TODO.md; history belongs in CHANGELOG.md; evidence belongs in retained reports and trackers.

## DURABLE handoff policy — mandatory

### Maintenance policy

At the end of every turn:

1. preserve this policy and both mandatory checklists;
2. replace stale next-turn/status text instead of appending another narrative;
3. keep only unresolved or immediately resume-critical facts;
4. point to authoritative documents rather than duplicating their full contents;
5. move completed history to CHANGELOG.md and exact evidence to the retained report/tracker;
6. never treat a documentation/control-plane commit as implementation or runtime evidence.

### Anti-bloat policy

Do not add:

- transcripts, chronological play-by-play, tool-call history, or exhaustive action descriptions;
- generic procedure already owned by the turn-based-coding-agent skill or policy files;
- superseded milestone narratives or copied artifact tables;
- implementation detail that does not change the next action.

## Mandatory start-of-turn checklist

1. Review the turn-based-coding-agent skill if not already reviewed.
2. Fully review this handoff.
3. Review and follow RETENTION_POLICY.md.
4. Review and follow GitHub_Workflow_Policy.md before repository-side workflow/trigger/payload work.
5. Review TODO.md, DESIGN.md, REORIENTATION_PLAN.md, and the active M1 Code + Build plan.
6. Confirm the current branch head and source authority before any write.

## Mandatory next turn

Run a **targeted artifact-only Test + Benchmark verification of the exact R-A-REV-18-through-R-A-REV-21 partial Code + Build package**. This is the mandatory cadence gate before another Code + Build slice; it is not the retained full-M1 acceptance plan.

Repository: akashskypatel/Directional
Branch: agent/surface_cell_quad/p5-recover-bridge-healing
PR: #8 remains open, draft, and unmerged
Exact compile-valid source: `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca`
Compile run/job: `31625763711 / 94211611771`
Result artifact: `9153147035`, SHA-256 `bbc07fad9a767dc77aff290c540659b4140aab414ddf1148dec1b637fc32af38`
Log artifact: `9153147459`, SHA-256 `ad5984db04ab98a4bbcd058d58c83e1cdef2383890b8bcfab1c209e487b3889b`

The next turn must:

1. download and verify the exact result artifact without rebuilding or changing implementation/test/build source;
2. verify exact source `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca`, the self-excluding **25/25** manifest, command boundary, dependency revisions, and all five empty source-status snapshots before executing any packaged binary;
3. execute focused semantic contracts for REV-18 global aggregate ownership/cache rebuild, REV-19 transactional rollback/final merged oracle, REV-20 strict compatibility-path absence/missing authority, and REV-21 same-extent foreign-topology rejection plus consistent-topology positives;
4. include adjacent retained completion/optimizer/pipeline authority contracts needed to detect regressions from these changes, following `tests/TESTING_STRATEGY.md` and the unit-testing module;
5. classify every failure from runtime evidence; do not rebuild, weaken validation, restore raw mirrors/aliases/fallbacks, or alter fixtures to synthesize green output;
6. if the exact package passes, return to the M1 Code + Build plan to rerun the complete retained R-A inventory before any R-A completion claim.

Do not activate the retained full `Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`; it remains dormant until one fresh full R-A-through-R-G package exists. Do not implement M3, M4, M7, or Pipeline A during this verification.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Independent review decision/planning commit remains `49b94da971ff544ac77f9dd2fa394791a1b67435`; that review rejected source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`. Latest partial Code + Build source is `0580c5c8d7e4b12a41eefb0197f3660a0c7a8fca`.

- Overall R-A is **not complete** and has not been independently re-accepted.
- R-A-REV-17 remains retained compile-valid owner-certificate/canonical-cache progress within the newer source.
- R-A-REV-18 is **Code + Build complete / compile-valid**: global aggregate authority is published and post-remap identities/face cycles are rebuilt.
- R-A-REV-19 is **Code + Build complete / compile-valid**: aggregate publication is staged transactionally and the actual final merged product receives source-authoritative validation.
- R-A-REV-20 remains **Code + Build complete / compile-valid**: the named raw/legacy optimizer/verifier compatibility paths remain absent.
- R-A-REV-21 is **Code + Build complete / compile-valid**: affected boundaries require exact source-face topology binding rather than same-extent completeness.
- REV-14-through-REV-16 remain historical bounded progress until the complete R-A inventory and later acceptance close the combined gate.

Partial Code + Build evidence: run/job `31625763711 / 94211611771`, Release/static/Ninja/PRE_TEST **118/118**, result/log artifacts `9153147035 / 9153147459`, self-excluding manifest **25/25**, five empty source-status snapshots, and `runtimeExecution=false`. This is not an R-A or M1 acceptance candidate.

The reusable compile workflow is mandatory for future builds. Final cache inventory is bounded to two current `directional-ccache-*` entries and zero legacy `m1-ra-*` entries; the successful compile recorded **82.41%** ccache hits.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority. No runtime result or regression total changed; totals remain **34 events / 14 categories / 20 recurrences**.

## Standing product and regression state

- M1 is active; the retained artifact-only plan is dormant until a fresh full R-A-through-R-G package exists.
- PR8-R034 / G4-R007 / G4-B001 direct-torus LocalSheetMismatch remains active.
- G4-B002 InvalidHardRailPairing is owned by revised M4.
- G4-B003 nonzero periodic Z4 and G4-B004 positive multi-isolation evidence are owned by M5/M6 after M1.
- Bunny/Vase remain later representative product/resource gates.
- historical regression totals remain 34 events / 14 categories / 20 recurrences.
- no Pipeline A work is scheduled.

## Resume-critical execution lessons

- Compile success is build evidence, not runtime or semantic acceptance.
- A generic geometry payload derived from typed authority becomes a duplicate semantic owner if production reads it back for equality, order, hashing, lookup, or ownership. Derived identity caches must be rebuilt after any authority remap or removed.
- Matching container extent is not source ownership. Every paired source matrix and authority product must agree on exact checked row topology before semantic use.
- A zero-selected test filter is orchestration failure, never a pass.
- Preserve natural packaged file modes; do not chmod or repair immutable artifacts.
- Do not answer a semantic failure by restoring a numeric mirror, adapter, alias, hash oracle, fallback, fixture exception, or weakened assertion.
- Representation differences are classified by design/product invariants, not obsolete numbering, hashes, row order, or exact counts.
- Pipeline B strict gates require D0; degradation is never a substitute for fixing a strict-path defect.

## Mandatory end-of-turn checklist

1. Review and apply CLEAN_UP_POLICY.md.
2. Update TODO.md for completed, active, blocked, and newly discovered work.
3. Update CHANGELOG.md only for completed durable changes or accepted evidence.
4. Update the regression tracker only when a stable event/pattern/blocker changes.
5. Replace this handoff's exact next action and current authority.
6. Update the active PR description when its durable summary is stale.
7. Add one final summarized PR #8 conversation comment after all other branch/PR writes.

## Core references

- TODO.md
- .agents/Directional/DESIGN.md
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md
- .agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md
- .agents/Directional/REORIENTATION_PLAN.md
- .agents/Directional/Regression_Root_Cause_Tracker.md
- tests/TESTING_STRATEGY.md
- .agents/Directional/CHANGELOG.md
- .agents/Directional/CLEAN_UP_POLICY.md
- .agents/Directional/RETENTION_POLICY.md
- .agents/Directional/GitHub_Workflow_Policy.md

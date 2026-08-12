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

Run a **targeted artifact-only Test + Benchmark verification of the exact R-A-REV-17 / R-A-REV-20 partial Code + Build package**. This is the mandatory cadence gate before another Code + Build slice; it is not the retained full-M1 acceptance plan and must not be relabeled as M1 acceptance.

Repository: akashskypatel/Directional  
Branch: agent/surface_cell_quad/p5-recover-bridge-healing  
PR: #8 remains open, draft, and unmerged  
Exact compile-valid source: `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`
Result artifact: `9149834162`, outer SHA-256 `c5055df51d9b94605c27817e596a04983bddb33956727a2c47c494d42a0b2ee2`
Log artifact: `9149834634`, outer SHA-256 `04291253c21af768af9c35b61f12e327c0ec536642a2ddf8895781657b1261a7`
Compile run/job: `31616904715 / 94181880684`

The next turn must:

1. download and verify the exact result artifact without rebuilding or changing implementation/test/build source;
2. verify the packaged source SHA, self-excluding `SHA256SUMS` manifest, command boundary, and clean source-status records before executing any packaged binary;
3. execute the focused semantic contracts that directly cover REV-17 source-owned stitch/collision authority and REV-20 strict optimizer/verifier missing-authority and compatibility-path removal;
4. include adjacent retained completion/optimizer validation contracts needed to detect regressions caused by these changes, following `tests/TESTING_STRATEGY.md` and the unit-testing module;
5. classify every failure from runtime evidence; do not weaken validators, restore raw mirrors/aliases/fallbacks, alter fixtures to synthesize green output, or rebuild the package;
6. if the exact package passes its focused runtime gate, return the following turn to the M1 Code + Build plan for the still-open R-A-REV-18 and R-A-REV-19 tasks, then rerun the complete R-A inventory before any R-A completion claim.

Do not activate the retained full `Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`; that plan remains dormant until one fresh full R-A-through-R-G package exists. Do not implement M3, M4, M7, or Pipeline A during this verification.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review decision/planning commit: `ab29756e206da3e7b7d6845cfb3f08f25125faa5`.  
Independent review boundary: branch head `fd96852d19defe70effd0dc6fbbaf07db8378e55`; reviewed affected implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e`.

- Overall R-A is **not complete**.
- R-A-REV-17 is **Code + Build complete / compile-valid** at `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`; runtime semantic verification of the exact artifact is the mandatory next turn.
- R-A-REV-20 is **Code + Build complete / compile-valid** at the same source; runtime semantic verification of the exact artifact is the mandatory next turn.
- R-A-REV-18 remains open: global aggregate source-authority publication and post-remap derived-identity closure are not implemented by this partial turn.
- R-A-REV-19 remains open: aggregate publication is not yet fully transactional and the real final merged-product oracle is not yet complete.
- REV-14-through-REV-16 remain retained implementation progress only until the complete R-A closure inventory and later independent acceptance establish that their review findings are fully resolved.

Partial Code + Build evidence: run/job `31616904715 / 94181880684`, Release/static/Ninja/PRE_TEST **118/118**, result/log artifacts `9149834162 / 9149834634`, verified self-excluding manifest **21/21**, five empty source-status snapshots, source audit reporting REV-17/REV-20 closed, and `runtimeExecution=false`. This is authentic partial build evidence only, not an M1 acceptance candidate.

M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority; no runtime result or regression total changed in the completed Code + Build turn.

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

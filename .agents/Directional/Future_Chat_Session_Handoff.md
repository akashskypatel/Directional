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

Run **M1 Single-Authority Cutover remediation — Code + Build only** under:

`.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`

Repository: akashskypatel/Directional  
Branch: agent/surface_cell_quad/p5-recover-bridge-healing  
PR: #8 remains open, draft, and unmerged  
Reviewed implementation/test source: `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`  
Independent review boundary: `356a0bc2733af41e15fad056161e526865c147c5`  
Review decision/planning commit: `49b94da971ff544ac77f9dd2fa394791a1b67435`

The next turn must:

1. close R-A-REV-18 by publishing one checked global aggregate `SourceTopologyRegions`, validating every remapped lineage, rebuilding/removing vertex identity caches, and regenerating both face cycles;
2. close R-A-REV-19 by staging every semantic/context product transactionally, exposing no consumable rejected context, and running actual final merged-product source-authoritative validation;
3. close R-A-REV-21 by binding every affected authority product to the exact supplied source-face topology, with same-extent foreign-authority negatives and a consistent-permutation positive;
4. rerun the complete retained R-A inventory through REV-21 and mark R-A complete only if every gate closes;
5. complete R-B through R-G in the same vertical cutover;
6. produce one fresh full Release/static/Ninja/PRE_TEST package with clean provenance and a verified self-excluding manifest.

Execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input. Do not restore a raw mirror, compatibility identity, fallback, fixture exception, proxy oracle, or extent-only authority bypass.

Do not execute or relabel partial artifacts `9149834162 / 9149834634`; their targeted runtime task is superseded by the rejected source review. The retained full artifact-only plan remains dormant until one fresh full R-A-through-R-G package exists. Do not implement M3, M4, M7, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review decision/planning commit: `49b94da971ff544ac77f9dd2fa394791a1b67435`.  
Independent review boundary: branch head `356a0bc2733af41e15fad056161e526865c147c5`; exact reviewed implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`.

- Overall R-A is **not complete**; the requested checkpoint was rejected.
- R-A-REV-17 bounded owner-certificate/canonical-cache remediation is compile-valid and retained as progress, not independent acceptance.
- R-A-REV-18 remains open: the aggregate publishes no global owner and leaves post-remap identity/face-cycle caches stale.
- R-A-REV-19 remains open: aggregate publication is not transactional and cached component validation is not a final merged-product oracle.
- R-A-REV-20 bounded compatibility-path removal is compile-valid and retained as progress, not independent acceptance.
- R-A-REV-21 is open: affected boundaries accept a foreign same-face-count authority without exact source-topology binding.
- REV-14-through-REV-16 remain historical bounded progress until the complete R-A inventory closes.

Compile-only evidence remains authentic: run/job `31616904715 / 94181880684`, Release/static/Ninja/PRE_TEST **118/118**, result/log artifacts `9149834162 / 9149834634`, verified self-excluding manifest **21/21**, five empty source-status snapshots, and `runtimeExecution=false`. It is not an R-A or M1 acceptance candidate.

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

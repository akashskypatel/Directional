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

Run **M1 Single-Authority Cutover continuation — Code + Build only** under:

.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md

Repository: akashskypatel/Directional  
Branch: agent/surface_cell_quad/p5-recover-bridge-healing  
PR: #8 remains open, draft, and unmerged  
Review policy after the later immutable Test + Benchmark turn: never

R-A-REV-01 through R-A-REV-13 are compile-closed for their reviewed paths at latest review-remediation source `78056ba849fafad27eb55e8008fbc20a56300868`, but R-A itself remains open. The next turn must:

1. rerun the **complete R-A source inventory** across occurrence/materializer, completion/assembly, patch/lineage, arrangement ownership/chart transitions, public optimizer/verifier APIs, source-authoritative validation, rail consumers, generic validation boundaries, top-level component aggregation, exact-key collision behavior, and post-remap publication, and call R-A complete only if every closure item is statically clean;
2. complete R-B through R-G in the same vertical cutover;
3. produce one fresh full Release/static/Ninja/PRE_TEST package using the independently verified out-of-tree, clean-provenance, self-excluding-manifest rules;
4. execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input; activate the artifact-only plan only after that fresh full package exists.

Do not validate, relabel, repair, or reuse any historical/partial package listed in `CHANGELOG.md`. Do not implement M3 curve-network topology, M4 conformity flow, M7 disposition/degraded production, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review boundary that introduced REV-11 through REV-13: PR #8 through `1c4f631ff4d0565f520796fb8fbfab854d5b8ad1`. Latest review-remediation implementation/compile source: `78056ba849fafad27eb55e8008fbc20a56300868`. R-A-REV-11 through R-A-REV-13 are compile-closed for their reviewed paths:

- `R-A-REV-11`: exact stitch-registry entries retain a canonical typed-authority certificate; compatible candidates intersect region/sheet/chart authority under identical support, and incompatible exact-key collisions fail `IncompatibleTypedStitchAuthority` before position-based merge.
- `R-A-REV-12`: every component region/sheet/chart/support remap is checked; invalid mapping fails component merge, complete remapped lineage is required before publication, and real production multi-component/raw-tamper plus malformed-remap semantic contracts are compile-visible.
- `R-A-REV-13`: the replacement repository-wide affected-symbol/read audit includes source-authoritative validation, rail constraints, arrangement/chart ownership, materializer/lineage declarations, component aggregation, and semantic-body checks for REV-11/12. Its successful checkpoint reported REV-11 closed, REV-12 closed, and the repository-wide affected-symbol/read inventory clean.

Compile-only run/job `31584657331 / 94075568409` completed Release/static/Ninja/PRE_TEST **118/118** from exact source `78056ba849fafad27eb55e8008fbc20a56300868`. Result artifact `9136856592` has outer SHA-256 `f6bd76caf0cb1a78b0faaedb04feaf157850d1e11336919efbf5cf698a07ce6d`; log artifact `9136857219` has outer SHA-256 `98353502b1cffa8f0f3e9233bddf8bf1c3d7909f48786e069bae1d3f5a4296f3`. Independent inspection verified exact packaged source, a self-excluding manifest **21/21**, all five source-status snapshots empty, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`.

This remains a partial review-remediation checkpoint only. R-A is not complete until the complete closure inventory is rerun; R-B through R-G remain open; artifact `9136856592` is not an M1 acceptance candidate; M1l remains immutable runtime authority; no runtime/regression total changed.

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
- A generic geometry payload derived from typed authority becomes a duplicate semantic owner if production reads it back for equality, order, hashing, lookup, or ownership.
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
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md
- .agents/Directional/REORIENTATION_PLAN.md
- .agents/Directional/Regression_Root_Cause_Tracker.md
- tests/TESTING_STRATEGY.md
- .agents/Directional/CHANGELOG.md
- .agents/Directional/CLEAN_UP_POLICY.md
- .agents/Directional/RETENTION_POLICY.md
- .agents/Directional/GitHub_Workflow_Policy.md

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

R-A-REV-01 through R-A-REV-10 are compile-closed for their reviewed paths at latest review-remediation source `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e`, but R-A itself remains open. The next turn must:

1. rerun the **complete R-A source inventory** across occurrence/materializer, completion/assembly, patch/lineage, arrangement ownership, public optimizer/verifier APIs, rail consumers, generic validation boundaries, and top-level component aggregation, and call R-A complete only if every closure item is statically clean;
2. complete R-B through R-G in the same vertical cutover;
3. produce one fresh full Release/static/Ninja/PRE_TEST package using the independently verified packaging rules: out-of-tree build, clean source provenance, a self-excluding manifest generated after all payload writes, and manifest verification before upload;
4. execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input;
5. activate the artifact-only plan only after that fresh full package exists.

Do not validate, relabel, repair, or reuse any historical/partial package listed in `CHANGELOG.md`, including partial review-remediation artifacts `9127976318` and `9129549875`. Do not implement M3 curve-network topology, M4 conformity flow, M7 disposition/degraded production, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review boundary: PR #8 through `f81f40524f9ee6978e4e298497d4d54580520cf3`; latest review-remediation implementation source `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e`.

R-A-REV-07 through R-A-REV-10 are compile-closed for their reviewed paths:

- R-A-REV-07: exact boundary identity no longer bypasses complete typed topology-region/isolation-sheet/chart/support lineage; empty-source completion does not publish stitch authority, and exact-only assembly fails `MissingTypedStitchIdentity`.
- R-A-REV-08: SurfaceCells optimization/validation uses source-authoritative fail-closed entry points; the public optional-authority flag is removed, and generic `MeshValidator` no longer treats raw component/sheet labels as sheet authority.
- R-A-REV-09: multi-component typed isolation-sheet extent/offset derives from complete typed lineage; incomplete coverage fails closed, typed remap is primary, and raw labels are one-way projection/export.
- R-A-REV-10: the static audit inventories affected public headers/declarations, completion/assembly, optimizer/verifier modes, generic validation boundaries, component aggregation, and raw component/sheet reads; semantic REV-07-through-09 contract bodies are compile-visible rather than name-only checks.

Compile-only run/job `31565756309 / 94017095695` completed Release/static/Ninja/PRE_TEST **118/118** from exact source `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e`. Result artifact `9129549875` has outer SHA-256 `34f9d4a576ddfd79c2c35997ac95bdd91a0b549ac1bf519bc38a11d36d0559e5`; log artifact `9129550069` has outer SHA-256 `65fe62a061ab090f4929477997b28527d9511816e8c0518a136dac3604941bb0`. Independent inspection verified the self-excluding manifest **20/20**, all five source-status snapshots empty, exact packaged source, and `runtimeExecution=false`. No compiled contract was executed.

This is a partial review-remediation checkpoint only. The complete R-A inventory has not yet been rerun, R-B through R-G remain open, artifact `9129549875` is not an M1 acceptance candidate, M1l remains immutable runtime authority, and no runtime/regression total changed.

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

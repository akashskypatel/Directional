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
5. Review TODO.md, DESIGN.md, REORIENTATION_PLAN.md, the active M1 Code + Build plan, and the redesign/R-A review report.
6. Confirm the current branch head and source authority before any write.

## Mandatory next turn

Run **M1 Single-Authority Cutover Closure — Code + Build only** under:

.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md

Repository: akashskypatel/Directional  
Branch: agent/surface_cell_quad/p5-recover-bridge-healing  
PR: #8 remains open, draft, and unmerged  
Review policy after the later immutable Test + Benchmark turn: never

The turn must:

1. close R-A-REV-01 by giving materializer occurrences required typed sheet/member authority and removing every semantic read of SurfacePoint component/sheet;
2. close R-A-REV-02 by deriving completion/stitch/ownership identity from typed lineage authority and removing raw provenance component/sheet from semantic identity;
3. complete R-B through R-G as the same vertical M1 cutover;
4. compile/package Release/static/Ninja/PRE_TEST only;
5. execute no generated Directional binary, discovery, test, benchmark, ctest, CLI, fuzzer, or custom input;
6. produce a new immutable full-cutover artifact and expanded source audit;
7. update the dormant artifact-only plan with the new exact package authority.

Do not validate, copy, relabel, or repair historical artifact 9105462679 or R-A compile artifact 9124167871. Do not implement M3 curve-network topology, M4 conformity flow, M7 disposition/degraded production, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied replacement .agents/Directional/DESIGN.md is authoritative byte-for-byte.

- Pipeline B is the default and only scheduled path.
- Pipeline A is optional and ineligible until Pipeline B is Certified on the complete representative matrix with stable calibrated quality gates.
- revised milestones are M0-M8; M3 field-aligned curve network and M7 disposition are new.
- strict fixtures require D0 Certified; D1-D3 are truthful degraded output and cannot close strict gates.

Open design clarification/evidence items are tracked in TODO.md and Architecture_Redesign_and_M1_RA_Independent_Review_Report.md. Do not silently edit the supplied design to resolve them.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A compile checkpoint

Reviewed source: bebac907de814b07a55a770add4c897ab6d22ffd  
Compile run/job: 31550744314 / 93972723960  
Result/log artifacts: 9124167871 / 9124168143  
Compile: 118/118 Release/static/Ninja/PRE_TEST  
Generated runtime/discovery/tests/benchmarks: none

The checkpoint substantially implemented R-A items 1-6 and removed raw arrays from the materializer API. It is not R-A-complete because:

- RemeshPipeline.cpp still reads SurfacePoint::sheet for cross-sheet equivalence and representative ordering;
- PureQuadCompletion.cpp still encodes raw provenance component/sheet in fallback stitch identity.

No runtime regression count changed because runtime was not executed.

## Standing product and regression state

- M1 is active; the retained artifact-only plan is dormant.
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
- .agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md
- .agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md
- .agents/Directional/REORIENTATION_PLAN.md
- .agents/Directional/Regression_Root_Cause_Tracker.md
- .agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md
- tests/TESTING_STRATEGY.md
- .agents/Directional/CHANGELOG.md
- .agents/Directional/CLEAN_UP_POLICY.md
- .agents/Directional/RETENTION_POLICY.md
- .agents/Directional/GitHub_Workflow_Policy.md

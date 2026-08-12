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

The complete R-A gate is rejected at exact compiled source `c62c99ffe5b7863820c91f4ff3a93645b22d3591`. The next turn must:

1. close R-A-REV-07 through R-A-REV-10: exact-only completion, the optional non-authoritative optimizer/verifier path, raw-driven component sheet offsets, and incomplete audit/contracts;
2. rerun the complete R-A inventory and call R-A complete only if every closure item is statically clean;
3. complete R-B through R-G in the same vertical cutover;
4. produce one fresh full Release/static/Ninja/PRE_TEST package using the independently verified R-A-REV-06 rules: out-of-tree build, clean source provenance, a self-excluding manifest generated after all payload writes, and manifest verification before upload;
5. execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input;
6. activate the artifact-only plan only after that fresh full package exists.

Do not validate, relabel, repair, or reuse any historical/partial package listed in `CHANGELOG.md`, including partial review-remediation artifact `9127976318`. Do not implement M3 curve-network topology, M4 conformity flow, M7 disposition/degraded production, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review boundary: PR #8 through `f81f40524f9ee6978e4e298497d4d54580520cf3`; exact implementation source `c62c99ffe5b7863820c91f4ff3a93645b22d3591`.

Independent inspection verified compile-only run/job `31561686903 / 94005144300` at **118/118**, exact packaged source, outer artifact digests, all five empty source-status snapshots, and a self-excluding manifest **22/22**. This verifies R-A-REV-06 packaging mechanics, not R-A acceptance. Artifact `9127976318` remains partial and ineligible.

Live R-A blockers:

- R-A-REV-07: exact boundary identities can publish and stitch without complete typed lineage;
- R-A-REV-08: SurfaceCells optimization/validation can bypass typed authority and generic validation reads raw component/sheet labels;
- R-A-REV-09: multi-component aggregation derives typed sheet offsets from raw diagnostic/projection labels;
- R-A-REV-10: the focused audit and name-only contract inventory do not cover those paths.

The active Code + Build plan owns exact evidence, corrective measures, and the closure definition. M1l remains immutable runtime authority; no runtime or regression total changed.

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

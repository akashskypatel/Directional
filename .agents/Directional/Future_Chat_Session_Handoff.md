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

Run **M1 Single-Authority Cutover review remediation — Code + Build only** under:

.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md

Repository: akashskypatel/Directional  
Branch: agent/surface_cell_quad/p5-recover-bridge-healing  
PR: #8 remains open, draft, and unmerged  
Review policy after the later immutable Test + Benchmark turn: never

The independent review of exact source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` rejected overall R-A and the REV-14-through-REV-16 checkpoint. The next turn must:

1. close R-A-REV-17 by requiring owner-validated collision certificates and canonical-only derived identity;
2. close R-A-REV-18 by publishing the global aggregate source-authority domain and rebuilding all identities/face cycles after remap;
3. close R-A-REV-19 by making aggregate publication fully transactional and validating the final merged product with a counterfactual-complete oracle;
4. close R-A-REV-20 by removing or isolating remaining affected optimizer/completion compatibility paths and raw mirrors;
5. rerun the complete R-A source inventory and mark R-A complete only if every gate is statically clean;
6. only then complete R-B through R-G and produce one fresh full Release/static/Ninja/PRE_TEST package with clean provenance and a verified self-excluding manifest.

Execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input. Do not activate, validate, relabel, repair, or reuse a historical/partial package. Do not implement M3 curve-network topology, M4 conformity flow, M7 disposition/degraded production, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied `.agents/Directional/DESIGN.md` remains byte-for-byte authoritative. Pipeline B is the only scheduled path; strict fixtures require D0. Open design clarification/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review decision/planning commit: `ab29756e206da3e7b7d6845cfb3f08f25125faa5`.  
Review boundary: branch head `fd96852d19defe70effd0dc6fbbaf07db8378e55`; exact affected implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e`.

- Overall R-A is **not complete**.
- REV-14's canonical intersection implementation is retained, but its positive contract fabricates unowned IDs, stitching does not validate certificate ownership, and compatibility identity aliases remain.
- REV-15's independent local remap tables are retained, but the aggregate publishes no global owning `SourceTopologyRegions`, does not rebuild derived identities/face cycles after remap, and does not provide complete rollback.
- REV-16's pre-consumer tamper seam is retained, but its snapshot omits owner/cache consistency and compares cached per-component validation rather than validating the final merged product.
- R-A-REV-17 through R-A-REV-20 are the active corrective tasks. Exact evidence and definitions of done are in the independent review report and active Code + Build plan.

The prior compile-only checkpoint remains authentic partial build evidence: run/job `31602025466 / 94131563590`, Release/static/Ninja/PRE_TEST **118/118**, artifacts `9143819164 / 9143819888`, verified manifest **21/21**, and no generated runtime. It is not an M1 acceptance candidate.

M1l remains immutable runtime authority; no runtime or regression total changed.

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

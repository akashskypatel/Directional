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

R-A-REV-01 through R-A-REV-16 are compile-closed for their reviewed paths at latest review-remediation source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e`, but R-A itself remains open. The next turn must:

1. rerun the **complete R-A source inventory** across occurrence/materializer, completion/assembly and post-intersection collision publication, patch/lineage, arrangement ownership/chart transitions, public optimizer/verifier APIs, source-authoritative validation, rail consumers, generic validation boundaries, top-level component aggregation, independent remap domains/owner relations, pre-aggregation raw counterfactual behavior, and fail-closed zero-publication paths, and call R-A complete only if every closure item is statically clean;
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

Review boundary that introduced REV-14 through REV-16: PR #8 through `344f996622606121a9567beaf1dad4001a5374f3`. Latest review-remediation implementation/compile source: `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e`. R-A-REV-14 through R-A-REV-16 are compile-closed for their reviewed paths:

- `R-A-REV-14`: exact-key collision publication uses the final intersected typed certificate as the single authority; the derived authoritative identity and canonical face-owner cycles are regenerated from that result. Overlapping-compatible and disjoint-incompatible contracts are compile-visible.
- `R-A-REV-15`: component aggregation builds independent region/sheet/chart/support remap domains from published source authority, validates ownership and face relations before staging output, and rejects invalid authority with zero publication.
- `R-A-REV-16`: a narrow production-owned pre-aggregation counterfactual exposes raw-label tamper to the real consumer and compares complete semantic/hash/downstream authority-validation output; malformed typed authority rejects before publication; the repository-wide audit classifies affected raw component/sheet reads and checks the remap/collision/counterfactual bodies.

Compile-only run/job `31602025466 / 94131563590` completed Release/static/Ninja/PRE_TEST **118/118** from exact source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e`. Result artifact `9143819164` has outer SHA-256 `e3213d8ed94121e734b69ed17f64501a3a059b64ccfa3cbb6be48a1a98c83e13`; log artifact `9143819888` has outer SHA-256 `c2d0cbc28a296590f22a343aed9173a3e363e1cdb5a53ee198ae4a8dc5e44aa6`. Independent inspection verified exact packaged source, a self-excluding manifest **21/21**, all five source-status snapshots empty, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`.

Initial run/job `31601748377 / 94130625219` stopped before source application/audit/compile because the temporary final transfer chunks lacked a trailing newline and failed the pinned transfer digest. Log artifact `9143393404`, SHA-256 `7da2e3c7ab3222349084926aad29e1233506f3d401d4987a51a4fea9647d070f`. This was orchestration-only; no product patch or generated runtime executed.

This remains a partial review-remediation checkpoint only. R-A is not complete until the complete closure inventory is rerun; R-B through R-G remain open; artifact `9143819164` is not an M1 acceptance candidate; M1l remains immutable runtime authority; no runtime/regression total changed.

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

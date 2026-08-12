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

R-A-REV-01 through R-A-REV-06 are compile-closed for their reviewed paths at review-remediation source `c62c99ffe5b7863820c91f4ff3a93645b22d3591`, but R-A itself remains open. The next turn must:

1. rerun the **complete R-A source inventory** across occurrence/materializer, completion, patch/lineage, arrangement ownership, validator, optimizer, and rail consumers and proceed only if the closure gate is statically clean;
2. complete R-B row-independent face/support/chart identity;
3. complete R-C immutable published products and typed certificate construction;
4. complete R-D checked ingress and removal of compatibility/numeric read-back bridges;
5. complete R-E typed semantic owners/lookups;
6. complete R-F intent-complete compiled contracts and R-G expanded failing source audit;
7. produce one fresh full R-A-through-R-G Release/static/Ninja/PRE_TEST package using the verified R-A-REV-06 rules: out-of-tree build, clean source provenance, manifest generated after all payload writes, `SHA256SUMS` excluded from itself, and manifest verification before upload;
8. execute no generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input;
9. activate the artifact-only plan only after that fresh full package exists.

Do not validate, relabel, repair, or reuse any historical/partial package listed in `CHANGELOG.md`, including partial review-remediation artifact `9127976318`. Do not implement M3 curve-network topology, M4 conformity flow, M7 disposition/degraded production, or Pipeline A during M1.

## Current authority

### Normative architecture

The supplied replacement .agents/Directional/DESIGN.md is authoritative byte-for-byte.

- Pipeline B is the default and only scheduled path.
- Pipeline A is optional and ineligible until Pipeline B is Certified on the complete representative matrix with stable calibrated quality gates.
- revised milestones are M0-M8; M3 field-aligned curve network and M7 disposition are new.
- strict fixtures require D0 Certified; D1-D3 are truthful degraded output and cannot close strict gates.

Open design clarification/evidence items are tracked in TODO.md and REORIENTATION_PLAN.md. Do not silently edit the supplied design to resolve them.

### Immutable runtime authority

M1l implementation bd140cff4572412e6f4ecd70a6ce0fe85310932c remains the latest immutable runtime-accepted authority. Its accepted evidence is retained in CHANGELOG.md and Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md.

### R-A closure status

Review-remediation source `c62c99ffe5b7863820c91f4ff3a93645b22d3591` closes the six named review findings for their reviewed paths while preserving R-A as an open gate:

- R-A-REV-01: materializer occurrence sheet authority is typed; reviewed equivalence, quotient, ordering, and aggregation paths do not read raw `SurfacePoint::sheet`;
- R-A-REV-02: raw provenance component/sheet is absent from the fallback stitch-key encoding;
- R-A-REV-03: standalone/patch-local compatibility identity synthesis is removed, exact boundary identities are checked, and missing complete typed lineage fails with `MissingTypedStitchIdentity`;
- R-A-REV-04: the reviewed validator, optimizer, rail-constraint, completion-hash, and materializer decisions no longer consume raw component/sheet projections as authority;
- R-A-REV-05: positive/mismatch, missing-authority, distinct-typed-sheet, and raw-projection-tamper contracts are present in the compiled test sources; they were not executed in this Code + Build turn;
- R-A-REV-06: partial-package packaging mechanics now build out of tree, record clean source status, exclude `SHA256SUMS` from its own manifest, and verify the manifest before upload.

Compile-only run/job `31561686903 / 94005144300` completed Release/static/Ninja/PRE_TEST **118/118** from source `c62c99ffe5b7863820c91f4ff3a93645b22d3591`. Result artifact `9127976318` has outer SHA-256 `f7bcf34579664f19cd5a73fd384b5ff020304c7b10a89c81ce35a89a92b38588`; log artifact `9127976660` has outer SHA-256 `3f4c5eef39aedbb06666edf3b09e5f2e5071209ba88a3d9ef0f9174083bd536a`. Independent inspection verified the result manifest **22/22**, with the manifest excluded from itself and all five recorded source-status snapshots empty. No generated Directional runtime ran.

This is a **partial review-remediation checkpoint only**. The complete R-A closure inventory has not yet been rerun, R-B through R-G remain open, artifact `9127976318` is not an M1 acceptance candidate, and the final full R-A-through-R-G package must repeat the verified R-A-REV-06 packaging rules. M1l remains immutable runtime authority and regression totals did not change.

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

# Milestone G P5-R2E6 Authoritative Boundary Fan-Sector Cover Code/Build Plan

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Code + Build, compile-only

## Objective

Replace the `rayCount >= 3` assumption that one common canonical wedge must contain the complete boundary-node ray inventory with an authoritative, complete, non-overlapping cover of source-interior fan sectors.

The producer must support:

- multiple interior rays in one manifold boundary fan;
- hard rails that partition the source interior into adjacent fan scopes;
- one authoritative exterior sector from ordered source-boundary continuation;
- exact one-to-one incoming/outgoing successor ownership;
- disk-valid bounded orbits without post-hoc cycle repair.

Retain the passing R2E5 degree-two branch unchanged except for shared audit refactoring that preserves behavior exactly.

## Authority

Start from the P5-TB33 documentation head and read:

1. `.agents/Directional/Milestone_G_P5_TB33_Artifact_Only_R2E5_Test_Benchmark_Report.md`;
2. `benchmark-results/p5-tb33-summary.json`;
3. `.agents/Directional/Milestone_G_P5_R2E5_Code_Build_Report.md`;
4. `.agents/Directional/Milestone_G_P5_R2E5_Test_Benchmark_Plan.md`;
5. `TODO`;
6. `MILESTONE_G_TODO.md`;
7. `.agents/Directional/Future_Chat_Session_Handoff.md`.

## Confirmed state

P5-R2E5 closes degree-two boundary rotation and restores all R2E4 regressions. Remaining evidence:

- higher-valence fan: incidence-valid but non-disk/topology-invalid;
- interior hard rail: `BoundaryRotationalSystemConflict` before orbit publication;
- planar: incidence-valid, repeated-edge/node clean, Euler zero instead of one;
- cylinder: zero direct arrangement inventory and incomplete production output;
- bunny: separate intrinsic singularity-fan producer.

## Required implementation

### 1. Preserve the degree-two path

For exactly two outgoing rays, retain the audited R2E5 construction:

- `exteriorIncoming -> exteriorOutgoing`;
- `twin(exteriorOutgoing) -> exteriorTwin`.

Do not route degree-two nodes through the new general fan-sector cover.

### 2. Build canonical sector evidence for `rayCount >= 3`

For each authoritative boundary node:

1. inventory every local outgoing ray and its reciprocal incoming twin;
2. collect all canonical SourceVertex and SourceEdge wedge memberships produced by R1;
3. convert each wedge's ordered rays into directed adjacent source-interior sector candidates;
4. retain the canonical fan/sheet/component identity on each sector;
5. deduplicate only semantically identical sector records;
6. treat hard-rail rays as sector boundaries shared by the two permitted incident fan scopes, never as a ray that may be crossed;
7. add exactly one exterior sector from ordered source-boundary continuation.

Do not require one wedge identity to contain every ray.

### 3. Solve a complete sector cover, not a target permutation

The accepted local construction must satisfy all of the following directly from authoritative evidence:

- every local incoming halfedge owns exactly one sector;
- every local outgoing halfedge is targeted exactly once;
- every source-interior sector belongs to one R1 fan scope;
- the authoritative exterior sector is unique and follows exact loop order;
- hard-rail barriers separate adjacent interior sectors;
- no sector crosses between unrelated local sheets, pinched fans, components, or close sheets;
- no duplicate, missing, or contradictory sector remains.

The implementation must produce `candidateNext` from this cover transactionally. Do not first create an arbitrary permutation and then repair it.

### 4. Typed fail-closed evidence

Add a typed incidence failure such as `BoundaryFanSectorCoverConflict` for:

- uncovered incoming or outgoing rays;
- duplicate sector ownership;
- contradictory fan/sheet identity;
- hard-rail crossing;
- invalid reciprocal twin;
- non-unique exterior sector;
- endpoint discontinuity;
- incomplete local cardinality.

Keep `BoundaryRotationalSystemConflict` for malformed canonical ray-order evidence that occurs before sector-cover assembly.

Add derived diagnostics only after a complete local cover passes, for example:

- audited fan-sector node count;
- interior sector count;
- hard-rail separator count.

### 5. Preserve global audits and validators

Do not change or weaken:

- global predecessor multiplicity;
- endpoint continuity;
- ordered exterior-loop closure;
- repeated-edge and repeated-node cycle analysis;
- disk/non-disk classification;
- ownership registry/cardinality;
- structural Euler accounting;
- boundary-loop ownership;
- orientation and incidence hashing;
- area validation.

Do not merge or split cells after orbit extraction.

### 6. Scope boundary

Do not modify:

- FlowRep or trace generation semantics;
- simplification or completion;
- fallback/recovery/legacy behavior;
- optimizer, cache, lineage, or memory accounting;
- bunny intrinsic singularity-fan embedding;
- validators to accommodate invalid output.

P5-R2E6 is a boundary-node producer correction only.

## Required tests to compile

Strengthen or add generalized contracts for:

1. R2E5 degree-two boundary sectors remain unchanged and pass;
2. multiple interior rays at one boundary vertex produce disk-valid bounded cells;
3. every higher-valence incoming/outgoing ray is used exactly once;
4. hard rail ending at two boundary vertices yields one exterior and two bounded disks;
5. hard-rail rays separate fan sectors and are never crossed;
6. two R1 fan scopes can jointly cover one canonical boundary node without a common wedge identity;
7. missing or duplicate fan sectors fail typed and transactionally;
8. source-face row permutation preserves sector-cover identities and incidence hash;
9. whole-mesh orientation reversal preserves incidence hash;
10. pinched source-vertex fans and close sheets remain distinct;
11. planar, cylinder, nested, bridge, support-only, nonmanifold, and ownership contracts are not weakened.

Test inputs must genuinely create the named topology. Do not make tests pass synthetically.

## Expected files

The smallest coherent change should remain within:

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`;
- turn documentation and handoff files.

Do not modify unrelated subsystems.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Do not execute tests, benchmarks, custom meshes, project binaries, help/list/discovery commands, or produced binaries.

## Artifact requirements

Produce one bounded Linux release artifact containing the four targets, fixtures, exact and cleaned source archives, source/event/diff authority, logs, target hashes, and a self-excluding recursive manifest.

Require:

- manifest **48/48**;
- files **49** including the manifest;
- fixtures **26**;
- recursive submodules **9**;
- cleaned source with only `agent-source-snapshot.yml` and zero payloads.

Remove the bounded workflow and all patch payloads immediately after artifact upload.

## Next artifact-only acceptance

The next turn must be **P5-TB34 artifact-only R2E6 validation**. Require at minimum:

- source-chart **11/11**;
- source validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**, only bunny allowed;
- R2 focused at least **14/16**, with only planar and bunny allowed after hard-rail and higher-valence closure;
- Milestone D **6/7** or better, with cylinder the only allowed remaining failure;
- Phase 16 at least **45/47**, with only planar and bunny allowed;
- Phase 17 **26/26**;
- Phase 18 **57/57**;
- no regression in degree-two, orientation, ownership, bridge, support-only, nested, nonmanifold, pinched-fan, or close-sheet contracts.

If hard rail and higher-valence close, diagnose planar Euler and cylinder separately. Do not advance to R2F until planar, hard rail, cylinder, and every boundary/orbit/disk/owner/Euler gate closes and bunny is the sole remaining R2 producer.

## End-of-turn requirements

The Code + Build turn closes only when:

- the coherent source/test patch is committed and pushed;
- all four approved targets compile;
- no project binary was executed;
- artifact authority passes;
- the branch retains only the base workflow and zero payloads;
- report, test plan, machine summary, TODOs, and handoff are committed;
- a new final PR #8 handoff comment is posted as the final repository write.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.

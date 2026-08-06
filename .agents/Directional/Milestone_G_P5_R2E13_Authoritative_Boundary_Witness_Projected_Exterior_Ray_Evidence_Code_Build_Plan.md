# Milestone G P5-R2E13 Authoritative Boundary-Witness Projected Exterior-Ray Evidence Code + Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Purpose

Correct the earliest source-supported R2E12 boundary-fan producer without weakening any validation gate.

P5-TB40 proves that planar and interior-hard-rail fixtures still reject before successor publication with aggregate `BoundaryFanSectorCoverConflict`. R2E12's explicit exterior record is created only after requiring each ray's **entire** fan-membership evidence map to contain exactly one normalized entity/root entry. That cardinality requirement can conflate unrelated fan memberships with exterior authority.

The turn must project exterior authority from exact source-boundary witnesses first, then reconcile fan provenance against that authority.

## Required implementation

### 1. Derive boundary-authoritative ray projections

For `exteriorTwin` and `exteriorOutgoing`, derive an exact projection from the already validated `BoundarySubsegmentWitness` and transition graph:

- source-boundary loop identity;
- directed side (`+1` for source ray, `-1` for target ray);
- exact source chart/component/sheet/face supporting the boundary subsegment;
- resolved source entity;
- normalized canonical entity key;
- transition-component root.

Both projected rays must resolve to the same authoritative normalized entity/root contract required by the exterior continuation. Missing or contradictory projection fails closed.

### 2. Reconcile provenance by exact authority, not raw-map cardinality

Replace the requirement that each complete `collect_ray_entity_root_evidence` map has size one.

For each exterior ray:

1. enumerate all exact fan memberships as provenance;
2. partition them by exact equality with the boundary-authoritative normalized entity/root projection;
3. require at least one agreeing membership;
4. preserve all agreeing identities as provenance;
5. fail if any membership that claims the same authoritative boundary identity/side contradicts the projection;
6. retain unrelated fan memberships for their independent interior-pair roles.

This is deterministic authority partitioning. It is not count/order/frequency selection and it must not search arbitrary subsets.

### 3. Exact generic exterior reconciliation

If generic cyclic fan enumeration contributes the exact exterior directed key, require exact agreement on:

- directed triple;
- projected normalized entity key;
- projected transition root;
- source-boundary loop identity;
- source/target sides.

Merge only agreeing provenance. Contradiction fails transactionally.

### 4. Preserve publication gates

Before publishing `candidateNext`, retain all existing requirements:

- exactly one explicit exterior record and one exclusion;
- one non-exterior canonical pair per remaining incoming;
- target multiplicity one;
- complete incoming/target bijection;
- exactly one reconciled chart witness per non-exterior pair;
- predecessor multiplicity one;
- valid chart roots;
- distinct hard-rail opposite-side roots;
- complete bounded-orbit root audit.

No downstream compensation is allowed.

### 5. Deterministic target observability

The current target assertions print only the aggregate incidence failure. Add non-weakening assertion context for:

- `boundaryFanConflict` name/value;
- node/incoming/source-ray/target tuple;
- canonical pair count;
- exterior exclusion count;
- boundary-fan sector node count;
- cyclic-wrap interior-sector count;
- hard-rail separator and side-pair counts.

The assertions and acceptance criteria remain unchanged. This is observability, not validator relaxation.

## Allowed scope

Production/test changes are limited to:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` only if strictly necessary for derived diagnostic authority;
- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

Do not modify Phase 17, P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery, fixtures, manifests, source-authoritative validators, or unrelated tests.

## Prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture, ID, node, halfedge, or test-name special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness;
- no chart-local list used to define whether a canonical pair exists.

## Code + Build gate

1. Inspect and clean stale bounded workflows and temporary payloads before work.
2. Start from the current branch and exact P5-R2E12 source authority.
3. Use exact preimage/blob checks for every modified file.
4. Apply only the bounded source/test changes above.
5. Push the exact source commit before compilation.
6. Configure Release with `-O2 -DNDEBUG`.
7. Build exactly:
   - `directional_core`;
   - `directional_pipeline`;
   - `directional_phase1_tests`;
   - `directional_benchmarks`.
8. Do not execute any project binary, test, benchmark, custom input, help/list/discovery command, CLI, or GUI.
9. Package exact source/test blobs, source status, recursive submodules, binaries/libraries, configure/build/activity logs, and an internal SHA-256 manifest.
10. Upload the build artifact and a separate detailed log artifact.
11. Verify outer digests, all internal manifest entries, source commit, workflow event commit, blobs, submodules, and empty source status.
12. Remove the bounded workflow and all temporary trigger/payload files immediately after verification.

## Compile acceptance

Compile acceptance requires:

- only approved files changed;
- exact boundary-witness projection implemented without arbitrary selection;
- conflicting boundary claims remain fail-closed;
- target diagnostic context is deterministic and non-weakening;
- exactly four approved targets compile/link successfully;
- no project binary is executed;
- artifact and log authority are complete and verified;
- repository workflow/payload hygiene is restored.

Compile evidence does not establish runtime closure.

## Required next plan

After successful compilation, prepare **P5-TB41 artifact-only R2E13 Test + Benchmark**. It must first read the newly exposed derived target diagnostics, then require planar and hard rail to reach unchanged successor, wrap, root, embedding, Euler, ownership, and topology gates. Phase 17 must recover naturally through valid upstream arrangements.

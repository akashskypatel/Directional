# Milestone G P5-R2E11 Normalized Chart-Entity Ownership and Pair-First Witness Reconciliation Code/Build Plan

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Purpose

Correct the earliest P5-TB38 producer failure while preserving the normalized canonical-pair inventory introduced by R2E10.

R2E11 must make normalized canonical entity ownership authoritative throughout chart-witness resolution. Exact original fan identities remain provenance. They must not independently reject a chart after the pair inventory has already proven normalized entity and transition-root equivalence.

The turn is Code + Build only. Do not execute tests, benchmarks, custom inputs, project binaries, CLI, GUI, or help/list/discovery commands.

## Runtime baseline to correct

P5-TB38 against exact source `bf33049157dfee51a1b6c48dff35a97ce980e49f` reports:

- planar: `incidenceValid=false`, `BoundaryFanSectorCoverConflict`, before successor publication;
- interior hard rail: same typed failure and stage;
- R2 focused: **13/16**;
- Phase 17: **20/26**;
- complete suite: **597/625**, 28 failures.

This is unchanged from P5-TB37 and remains a regression from R2E8, where incidence published and Phase 17 reached **26/26**.

## Source-supported defect hypothesis

R2E10 normalizes equivalent fan identities during canonical pair inventory construction using `canonical_entity_key`, but chart resolution later requires the exact chart-resolved canonical identity to equal each original `fanIdentity`. Candidate collection is still nested by original fan identity.

This can reject a valid normalized pair witness before all equivalent provenance identities are reconciled. Current diagnostics expose only `BoundaryFanSectorCoverConflict`, so R2E11 must add derived subreason evidence while preserving the aggregate typed failure.

## Required implementation

### 1. Preserve the canonical pair inventory

Retain one node-level inventory keyed by:

```text
(incoming, sourceRay, target)
```

For each record preserve:

- normalized canonical entity key;
- exact transition-component root;
- all agreeing original fan identities as provenance;
- cyclic-wrap authority;
- exact independently proven exterior relation.

Do not return to chart-filtered consecutive-ray enumeration. Do not select by count, order, frequency, score ranking, or subset search.

### 2. Resolve charts pair-first

After the normalized pair inventory is complete:

1. build node/chart ray evidence independently of one original fan identity;
2. resolve the source entity for each chart corner;
3. apply the same `canonical_entity_key` normalization used by the pair inventory;
4. admit the chart only when its normalized entity key equals the pair record's normalized entity key;
5. require the chart transition-component root to equal the pair record's transition root;
6. preserve the exact resolved entity and agreeing original fan identities as provenance, not ownership selection.

An exact original identity mismatch is not a conflict when normalized entity key and transition root agree.

### 3. Reconcile witnesses before uniqueness

For every non-exterior pair:

1. gather all chart-corner witnesses contributed by all agreeing provenance identities;
2. map source and target directions into the exact continuous chart-corner interval;
3. apply the required `2*pi` lift only for a proven cyclic-wrap pair;
4. reject zero/negative span, span outside the corner, third-ray intrusion, invalid root, or normalized entity mismatch;
5. canonicalize only semantically identical witnesses by `(pair, chart, root, normalized entity key, oriented angles)`;
6. require identical left-score evidence for duplicate witnesses;
7. require exactly one reconciled authoritative witness after canonicalization.

Do not use arbitrary tie-breaking. Multiple non-identical valid witnesses are a typed conflict.

### 4. Exact exterior handling

The authoritative exterior continuation remains derived independently from source-boundary topology. Require its exact directed key in the normalized inventory and exclude it once and only once.

Exterior exclusion must not be repeated per provenance identity or chart.

### 5. Transactional publication

Do not modify `next`, successor ownership, chart support, or diagnostics until:

- every non-exterior canonical pair has exactly one reconciled witness;
- the exact exterior relation is excluded once;
- incoming and target coverage are both complete and one-to-one;
- predecessor multiplicity is one;
- hard-rail separator side-pair checks pass;
- all selected hard-rail orbit roots pass the existing complete-orbit audit.

Any failure leaves the arrangement unmodified and fail-closed.

### 6. Derived diagnostics

Add explicit, derived evidence sufficient to identify the first boundary-cover rejection. Use an enum, structured subreason, or deterministic counters for at least:

- missing canonical pair;
- exterior pair missing or multiply excluded;
- zero chart witness;
- multiple non-identical chart witnesses;
- normalized chart-entity mismatch;
- transition-root mismatch;
- conflicting duplicate witness scores;
- invalid oriented interval or third-ray intrusion;
- incomplete incoming/target cover;
- hard-rail separator or orbit-root conflict.

The existing aggregate `BoundaryFanSectorCoverConflict` remains authoritative. Diagnostics must be computed from actual rejected records; no synthetic counters or post-hoc inference.

### 7. Hard-rail publication authority

Retain the complete bounded-orbit audit from R2E9/R2E10:

- one selected root must remain present on every directed halfedge in the predicted bounded orbit;
- root change, root loss, exterior entry, barrier crossing, nonclosure, or conflicting ownership fails transactionally;
- opposite rail sides require distinct incident roots;
- accepted root becomes authoritative bounded-cell embedding support;
- full provenance remains separately preserved.

## Focused contract changes

Production source:

- `src/geometry/SurfaceArrangement.cpp`;
- `include/directional/geometry/SurfaceArrangement.h` only if typed derived diagnostics require it.

Focused tests may be strengthened only to expose intended generalized contracts:

- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`.

Permitted test changes:

- assert a derived failure subreason on a structurally invalid witness fixture;
- require positive normalized pair/witness inventory and exact exterior exclusion on valid planar/hard-rail fixtures;
- require all equivalent provenance identities to reconcile into one authoritative witness without changing fixture semantics;
- require row/orientation permutations to retain identical structural diagnostics.

Do not weaken existing assertions, alter valid fixture meaning, embed expected output, or modify Phase 17.

## Required invariants to preserve

- degree-two source-boundary publication;
- genuine four-bounded-disk publication;
- row-order and whole-orientation invariance;
- separate pinched source-vertex fans;
- disconnected close-sheet ownership separation;
- bridge/support transactional ownership;
- nested non-disk classification;
- nonmanifold fail-closed behavior;
- source-chart transition authority;
- source-authoritative validators;
- recovery and feature/barrier authority;
- deterministic hashing and diagnostics.

## Explicitly out of scope

Do not modify:

- cylinder open-strand producer;
- bunny singularity-fan producer;
- FlowRep pre-ring producer;
- Phase 17 implementation or tests except compilation caused by public diagnostic type changes;
- completion, side-subdivision repair, optimizer, fallback, source-grid recovery, legacy execution, fixtures, benchmark inputs, source-authoritative validators, or downstream acceptance thresholds.

## Compile-only gate

Before the authoritative compile:

1. push the exact source commit;
2. verify clean source state and changed-file scope;
3. initialize recursive submodules shallowly;
4. configure Release with Ninja and the established options;
5. compile exactly:
   - `directional_core`;
   - `directional_pipeline`;
   - `directional_phase1_tests`;
   - `directional_benchmarks`;
6. package exact source, binaries, libraries, metadata, checksums, fixtures needed by the next artifact-only turn, and detailed logs;
7. upload the compiled artifact and a separate always-uploaded log artifact;
8. execute no generated project binary.

A successful compile proves source/build validity only. The next turn must be artifact-only P5-TB39 runtime validation.

## Required turn outputs

- exact pushed source commit and changed-file audit;
- successful compile evidence for exactly four targets;
- compiled artifact and separate detailed log artifact with IDs/digests;
- P5-R2E11 Code/Build report;
- P5-TB39 artifact-only Test + Benchmark plan;
- updated TODO, milestone tracker, live handoff, machine summary, and PR body;
- removal of bounded workflows, temporary payloads, superseded report/plan/summary records;
- final top-level PR #8 handoff comment after every other repository and PR metadata write.

R2 remains open until artifact-only runtime evidence proves planar and hard-rail publication, planar Euler-one topology, hard-rail embedding, and Phase 17 **26/26** through unchanged downstream validators.

# Milestone G P5-R2E14 Code + Build Report

**Date:** 2026-08-05  
**Turn type:** Code + Build  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E14 two-sided exterior-root authority and chart-seam interval normalization is implemented and compile-valid.

The excluded exterior continuation now retains exact endpoint-specific chart/root/side authority instead of forcing both boundary sides to share one transition root. Non-exterior canonical pairs still require one exact common root. Chart-local circular ordering resolves only the oriented interval of an already-authoritative non-exterior pair and may publish a seam wrap only for unique exact circular adjacency; it cannot create or select pair ownership.

Runtime acceptance is not claimed. P5-TB42 must execute the exact artifact below and determine whether hard rail advances through exterior insertion to bounded-orbit topology and whether planar publishes one genuine seam wrap before unchanged successor and topology gates.

R2 remains open. Do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `c35fd7a4ca44946a233be4e18f175d4aa88bc03d`;
- exact compiled source: `2a8b9870b8e3854ae77a7e4eeae6da29a7899968`;
- workflow run/job: `31077891125` / `92539833523`;
- build artifact: `8958361834`;
- build artifact name: `surface-cell-p5-r2e14-github-source-linux-release`;
- build artifact SHA-256: `1f2607859ecf84d2cb82597f2c4f8f9341491df62d99b694510241f8df719db6`;
- build artifact size: **12,307,622 bytes**;
- log artifact: `8958362185`;
- log artifact SHA-256: `d7b499c3a9a69a6702ca96bff4dd1b3241f7db2051113d88b05320165e9323cb`;
- log artifact size: **5,776 bytes**;
- `SurfaceArrangement.cpp` blob: `bea11b3b24149c552e3569669d170419532f527e`;
- unchanged public header blob: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- unchanged Phase 16 test blob: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- unchanged Milestone D test blob: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`;
- patch SHA-256: `c09ce5e87b4ab7e9a23cdcd2dde6bec05cdd9a62f983917526df1471b3e5dfa1`;
- patch transport SHA-256: `ff17a771c4b01bab46bb402266cec5728666b49f9ac269db841fe8e457558005`;
- recursive manifest: **20/20**;
- packaged files including manifest: **21**;
- recursive submodules: **9**;
- compile/link actions: **132/132**;
- packaged source status: empty.

The downloaded build and log archive digests match GitHub's recorded digests. Every internal manifest entry verifies from the package parent. The packaged source archive reproduces the recorded production/header/test blobs.

## Implementation

### 1. Two-sided excluded exterior authority

`CanonicalFanPairRecord` retains for an exterior record:

- common normalized source-boundary entity and authoritative loop identity;
- exact source endpoint chart, transition root, and side `+1`;
- exact target endpoint chart, transition root, and side `-1`;
- agreeing source-side and target-side fan provenance.

The source and target roots are no longer required to be equal. This permits an authoritative hard rail to separate the incident boundary-side chart components without selecting, merging, or discarding either root. The excluded exterior record has no interior `transitionRoot` and cannot become bounded-orbit root authority.

### 2. Exact generic exterior reconciliation

When generic fan enumeration reaches the exact exterior directed triple, it first resolves the existing authoritative exterior record. Each endpoint claim is checked independently against its projected chart/root. A claim on the projected chart with a different entity or root fails closed as an exterior mismatch. Unrelated memberships on other charts remain available for independent interior-pair authority and do not veto or replace the projected exterior record.

Generic enumeration cannot create a replacement exterior record. Agreeing provenance is canonicalized and both endpoint-side provenance sets must remain non-empty.

### 3. Non-exterior common-root contract preserved

Every non-exterior pair still requires exactly one intersection of source and target transition roots. Duplicate pair contributions must agree on canonical entity and that one root. No count, order, frequency, score, or subset rule chooses ownership.

### 4. Authoritative chart-seam interval normalization

For each already-authoritative non-exterior pair on a matched chart/root:

1. collect the complete chart corner-ray inventory with raw circular angles;
2. reject duplicate ambiguous angular positions;
3. require exact directed-pair provenance from the canonical record;
4. require source and target rays to be adjacent in circular chart order;
5. add `2π` only when target is the last and source the first unique adjacent ray across the seam;
6. reject non-adjacency, third-ray intrusion, non-positive spans, or spans outside the available chart wedge;
7. publish `cyclicWrap=true` only from that exact seam witness.

The old raw fan-vector index no longer defines cyclic-wrap authority. Chart evidence resolves geometry only after node-level pair existence and ownership are fixed.

### 5. Existing gates preserved

P5-R2E14 does not weaken or bypass:

- one exterior record and one exclusion per boundary-fan node;
- complete non-exterior canonical-pair inventory;
- one reconciled chart witness per non-exterior pair;
- complete incoming/target cover and predecessor multiplicity;
- source entity/chart authority;
- hard-rail separator side-pair checks;
- distinct selected bounded-orbit roots;
- complete bounded-orbit root audit;
- embedding, disk, loop, Euler, orientation, area, ownership, or aggregate topology validation.

## Scope audit

Production change only:

- `src/geometry/SurfaceArrangement.cpp`.

Unchanged:

- public header and all tests;
- Phase 17;
- P27, bunny, cylinder, FlowRep, completion, optimization, fallback/recovery;
- fixtures, source-authoritative validators, thresholds, and unrelated diagnostics.

## Compile gate

Configuration:

- Ubuntu 24.04;
- GNU C++ 13.3.0;
- Ninja;
- Release `-O2 -DNDEBUG`;
- static libraries;
- tests and benchmarks enabled;
- CLI, GUI, GMP, PARDISO, cuDSS, and SuiteSparse disabled.

Built exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_phase1_tests`;
4. `directional_benchmarks`.

No test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

## Workflow and repository hygiene

- The patch transport was checksum-verified before application and exact production preimage/postimage blobs were enforced.
- An initially incomplete staging chunk was deleted before the bounded workflow existed; it produced no patch application, source commit, build, or runtime evidence.
- The exact source commit was pushed before configuration and compilation.
- The successful run uploaded the build package and detailed logs separately.
- All temporary patch chunks were removed in the exact source commit.
- The bounded workflow was removed after artifact verification.
- Only the durable source-snapshot workflow remains at turn completion.

## Next turn

Execute **P5-TB42 artifact-only R2E14 Test + Benchmark** using artifact `8958361834`.

Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, fixtures, validators, workflows, or build logic. The runtime turn must first prove or classify:

1. hard rail inserts and excludes one exterior record with exact endpoint-specific roots;
2. excluded exterior roots do not become bounded-orbit root authority;
3. both non-exterior hard-rail side pairs publish one exact common root and preserve complete bounded orbits;
4. planar resolves the prior `InvalidOrientedInterval` as one unique genuine chart-seam wrap;
5. successor/predecessor bijection, Euler `1`, and unchanged topology gates succeed;
6. Phase 17 returns to **26/26** without Phase 17 changes;
7. accepted authority groups and the complete 625-test inventory do not regress;
8. the P27/bunny cumulative-state stop remains separately classified from correctness.

Compile evidence alone does not close R2.

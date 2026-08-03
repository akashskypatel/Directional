# Milestone G P5 — Route-Complete Structural Repair Code + Build Plan

**Next turn type:** Code changes + compile-only build  
**Authoritative input:** P5-TB9 artifact `8843206930` evidence  
**Review policy:** `never`

## Objective

Resolve the deterministic `4956/4954` same-corner ownership claim with an exact, bounded, route-complete boundary-sector transaction. Preserve the global non-recursive work ledger, collision-safe state identity, transactional assembly, and every topology, source-support, provenance, geometry, component/sheet, lineage, and duplicate validator.

## Non-negotiable constraints

- Do not increase budgets merely to hide the current failure.
- Do not enumerate arbitrary boundary-interval powersets.
- Do not commit a candidate that replaces one ownership claim with another.
- Do not delete or deduplicate final faces.
- Do not merge vertices by position.
- Do not special-case production patch or halfedge IDs.
- Do not use source-triangle pairing, source-grid recovery, legacy fallback, or validator weakening.
- This turn may configure and compile only. It must not execute tests, benchmarks, or custom meshes.

## P5-CB34 — Correct the structural-repair fixtures

Replace `make_valid_parallel_route_same_corner_complex()` with an authoritative fixture that proves all of the following before budget-specific assertions:

1. complex incidence and recomputed topology are valid;
2. patch descriptors have unique authoritative domains;
3. the initial completion path reaches an exact `SameCornerDistinctBoundaryClaim`;
4. at least one geometrically distinct parallel route exists;
5. no final output is accepted before repair.

Use either a minimized production-derived arrangement or a direct explicit DCEL with valid source provenance and geometry. Do not assign final validity or conflict diagnostics manually.

Update the tests so that:

- zero budget fails with `CandidateBudget` only after the initial same-corner claim is established;
- one candidate consumes exactly one global candidate and one structural attempt;
- the success fixture actually executes `BoundarySectorSubdivision`;
- patch/source-row order invariance compares nonempty identical ledgers;
- a negative control proves an already successful complex performs zero structural repair.

## P5-CB35 — Route-complete candidate identity

Replace the single-halfedge structural candidate with a compact exact candidate containing:

- ordered canonical shared corner identities;
- one complete differing boundary route or a coupled route-sector pair;
- sorted canonical undirected halfedge IDs;
- exact geometric-support identities for every interval;
- affected patch/domain set;
- hard-feature and component/sheet scope;
- deterministic candidate identity and diagnostic hash.

Derive maximal route chains between consecutive shared authoritative corners. Intervals that belong to one route sector must be evaluated atomically.

Hashes remain diagnostic. Exact identities determine candidate equality and ordering.

## P5-CB36 — Atomic coupled-sector subdivision

For a route-complete candidate:

- build one subdivision request containing every required undirected interval;
- include twins through the existing subdivision machinery;
- validate that the complete route remains conforming across every incident patch;
- rerun parity, coupled side repair, descriptor derivation, completion, and assembly once;
- commit only when assembly succeeds and the exact active claim count reaches zero;
- reject the whole transaction if any interval fails, if another ownership claim appears, or if topology/source support changes illegally.

For the production evidence, the two individual candidates corresponding to halfedges `22706` and `23112` must be recognized through topology—not IDs—as one coupled boundary-sector relationship when appropriate.

Do not add a generic combinatorial subset search. The allowable candidate set must be derived from complete route topology.

## P5-CB37 — Progress and exhaustion semantics

Retain one invocation-owned global ledger.

Add typed outcomes for:

- incomplete route candidate;
- coupled route validation failure;
- route-complete candidate repeated state;
- route-complete candidate introduced ownership;
- no route-complete candidate;
- route candidate budget exhaustion.

The monotonic progress contract remains strict:

- success means zero active ownership claims;
- persistence of the original claim is `NoProgress`;
- any replacement claim is `IntroducedOwnershipClaim`;
- no intermediate conflicting state is committed.

## P5-CB38 — Peak-memory margin

The clean formal runs meet the cap, but two supplementary processes exceed it. Increase safety margin by removing avoidable full-complex duplication:

- allow the non-recursive completion pass to consume/move an owned candidate complex where safe;
- avoid retaining both parity and side-repair complex copies after the next representation is committed;
- retain a compact rollback/edit log or immutable base plus one mutable candidate, not multiple full prepared complexes;
- release candidate completed patches, descriptors, assembly mesh, and repeated failure strings before the next candidate;
- keep peak live candidate-complex count at one;
- report estimated owned bytes for rollback, candidate, descriptors, completed patches, and assembly.

Do not implement incremental recomputation unless exact equivalence is proven.

## P5-CB39 — Diagnostics and semantic hashes

Expose through completion results, pipeline diagnostics, semantic hashes, and benchmark JSON:

- route candidate count and consumed count;
- each candidate's complete interval list;
- shared-corner and route identities;
- affected patches/domains;
- compound inserted-vertex and split-edge totals;
- exact route validation outcome;
- rollback/candidate/descriptor/completed-patch/assembly owned-byte estimates;
- current and peak total structural-repair owned bytes.

## P5-CB40 — Compile-only regression sources

Compile, but do not execute, tests covering:

- initial same-corner precondition for every structural budget test;
- one atomic route-complete repair that succeeds;
- incomplete single-interval repair rejected without commit;
- two route sectors where the first fails and the second succeeds under one global ledger;
- route candidate repeated-state rejection;
- zero/one candidate exact budgets;
- patch and source-face-row order invariance with nonempty ledgers;
- compound candidate diagnostics and semantic-hash mutation;
- already-successful negative control with zero repair work;
- medium fixture with one live candidate and bounded owned-byte accounting.

## P5-CB41 — Compile-only gate

Perform a clean optimized static Release build and compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Package exact source, binaries and libraries, configure/build logs, source commit and empty status, recursive submodule revisions, and checksums.

Run no test, benchmark, or custom mesh executable.

## Required P5-TB10 gates

The following turn must validate the artifact without rebuilding:

- all corrected route-complete structural tests;
- PatchDescriptor, Phase 16/18, Phase 14–18, and P23/Phase20 suites;
- at least two clean-exit direct random-bunny processes;
- no timeout, fallback, or recovery;
- deterministic route candidate ledger and structural hashes;
- direct completion succeeds with nonempty pure-quad output;
- peak memory at or below `1,115,394,560 B` in every formal process;
- wall time at or below `39.228299 s` in every formal process;
- supplementary repeated processes must not exceed the memory cap.

Compilation alone does not close P5.

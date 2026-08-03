# Milestone G P5 — Route-Complete Structural Repair Code + Build Plan

**Turn type:** Code changes + compile-only build  
**Authoritative input:** P5-TB9 artifact `8843206930` evidence  
**Review policy:** `never`  
**Status:** Implemented and compile-valid; runtime validation deferred to P5-TB10.

## Completion checkpoint

- Route-complete implementation commit: `5dcc6da94977c733ada42967ecdafa566cbc5d0b`.
- Exact compiled source: `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`.
- Compile-only run: `30782277625` — success.
- Job: `91589158985` — success.
- Artifact: `8844133680`, `surface-cell-p5-route-complete-linux-release`.
- Digest: `sha256:1f32a4d3600d1a7be39e710d35273f80bed0c24850626d744ab15e7a748a34bb`.
- Build: 131/131 steps; all four required targets linked.
- Source status is empty and all ten packaged checksums pass.
- No test, benchmark, or custom mesh executable ran.

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
- Execute no test, benchmark, or custom mesh binary in this turn.

## P5-CB34 — Correct the structural-repair fixtures — Complete

- Replaced the vacuous fixture with an explicit authoritative DCEL/source-support fixture.
- The initial closed-form completion claims the same authoritative corner cycle through distinct complete boundary routes.
- Budget and order-invariance tests assert the initial `SameCornerDistinctBoundaryClaim` precondition.
- Added an already-successful negative control that requires zero repair work.
- No final validity or ownership-conflict diagnostic is assigned synthetically.

## P5-CB35 — Route-complete candidate identity — Complete

Candidates now contain:

- ordered shared authoritative corner identities;
- maximal complete route chains between consecutive shared corners;
- sorted canonical undirected interval identities;
- exact geometric-support identities;
- affected patches and domains;
- component/sheet scope;
- deterministic exact candidate identity and diagnostic hash.

Exact identities determine equality and ordering. Hashes remain diagnostic.

## P5-CB36 — Atomic coupled-sector subdivision — Complete

- Complete differing route sectors are derived from topology.
- When multiple sectors belong to one unresolved same-corner relationship, one coupled-sector interval union is generated and evaluated first.
- No arbitrary subset or powerset enumeration is used.
- All candidate intervals are submitted in one subdivision request with twin-conforming subdivision.
- Parity, coupled side repair, descriptor derivation, completion, and assembly rerun once for the entire transaction.
- Commit requires assembly success and zero exact ownership conflicts.

## P5-CB37 — Progress and exhaustion semantics — Complete

The global ledger retains strict typed outcomes for:

- incomplete route candidate;
- route validation failure;
- repeated route state;
- no progress;
- introduced ownership claim;
- no route-complete candidate;
- route candidate budget exhaustion;
- committed assembly success.

No intermediate conflicting state is committed.

## P5-CB38 — Peak-memory margin — Source complete

- Superseded failed descriptors, completed patch meshes, assembly storage, and repeated failure strings are released before route evaluation.
- The authoritative rollback complex remains immutable while at most one mutable candidate complex is live.
- Candidate products are released before the next candidate.
- Full recomputation remains authoritative because incremental equivalence has not been proven.
- Runtime memory acceptance remains deferred to P5-TB10.

## P5-CB39 — Diagnostics and semantic hashes — Complete

Completion results, pipeline diagnostics, semantic hashes, and benchmark JSON expose:

- route candidate count and consumed count;
- complete candidate interval lists;
- shared-corner and route identities;
- affected patches and domains;
- compound inserted-vertex and split-edge totals;
- typed route validation outcomes;
- rollback, candidate, descriptor, completed-patch, and assembly byte estimates;
- current and peak structural-repair owned bytes.

## P5-CB40 — Compile-only regression sources — Complete

Compiled sources cover:

- initial same-corner preconditions for structural budget tests;
- one atomic route-complete repair;
- incomplete single-interval rejection;
- coupled-sector evaluation under one global ledger;
- repeated-state rejection;
- exact zero/one candidate budgets;
- nonempty patch/source-row order-invariant ledgers;
- compound diagnostics and semantic-hash mutation;
- already-successful zero-work negative control;
- bounded one-live-candidate byte accounting.

These tests were not executed in this turn.

## P5-CB41 — Compile-only gate — Complete

A clean optimized static Release build compiled only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Artifact `8844133680` packages exact source, binaries, libraries, configure/build logs, source commit and empty status, recursive submodule revisions, and ten passing checksums.

The first compile run `30781889869` also compiled successfully but produced a self-referential checksum manifest. It was superseded by authoritative run `30782277625`, whose workflow writes the manifest outside the artifact before moving it into place.

## Required P5-TB10 gates

The next turn must validate artifact `8844133680` without rebuilding:

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

# Milestone G P5-R2E11 Code/Build Report

**Date:** 2026-08-05
**Turn type:** Code + Build
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Base:** `surface_cell_quad`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Disposition

P5-R2E11 normalized chart-entity ownership and pair-first witness reconciliation is implemented and compile-valid.

This turn preserves the R2E10 node-level canonical pair inventory while removing exact provenance identity as a second ownership gate during chart resolution. Chart evidence is now aggregated at the node/chart level, normalized with the same canonical entity contract used by pair construction, and reconciled per canonical directed pair before uniqueness is enforced.

The aggregate `BoundaryFanSectorCoverConflict` remains fail-closed. R2E11 adds derived, deterministic conflict subreasons so the next artifact-only turn can identify the earliest rejected boundary-cover condition without weakening validation.

Runtime acceptance is not claimed. P5-TB39 must execute the packaged binaries and determine whether planar and hard-rail incidence, planar wrap/Euler-one topology, hard-rail embedding, and Phase 17 **26/26** are restored.

R2 remains open. Do not advance to R2F or R3 from compile evidence.

## Exact source and package authority

- workflow event commit: `5e96846a55acc8fd085836db886fcddbb5cd1dac`;
- exact compiled source: `b3010a36f762bb7317f2201d94733226b418c2c0`;
- workflow run/job: `31056835353` / `92476050630`;
- build artifact: `8950709981`;
- build artifact name: `surface-cell-p5-r2e11-github-source-linux-release`;
- build artifact SHA-256: `012a7782726b849ece1aa72286ae2ae9eb98b6a803106813b87caf348939a31c`;
- build artifact size: **12,281,580 bytes**;
- log artifact: `8950710191`;
- log artifact SHA-256: `06061e79fd11fdbc8683f8f01e4405f1248455782029e082df38771263fbffb6`;
- log artifact size: **5,538 bytes**;
- `SurfaceArrangement.cpp` blob: `22f607ec6d2326edceb8264240b22b5a46da3083`;
- header blob: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- Phase 16 test blob: `e58bceda098f7768b8a7203cca00564f82a7d831`;
- Milestone D test blob: `015a9f02354a91ca07d0e0c6bf6b2632055436ae`;
- recursive manifest: **20/20**;
- packaged files including the manifest: **21**;
- recursive submodules: **9**;
- compile/link actions: **132/132**;
- packaged source status: empty.

The artifact archive digest matches the GitHub artifact digest, and every internal manifest entry verifies. The packaged source archive reproduces all four recorded blobs exactly.

## Implementation

### 1. End-to-end normalized entity ownership

R2E11 retains canonical directed pairs keyed by:

```text
(incoming, sourceRay, target)
```

Each pair retains one normalized canonical entity key, one transition-component root, cyclic-wrap authority, and all agreeing exact fan identities as provenance.

Chart resolution now applies the same `canonical_entity_key` normalization to `transitionGraph.resolve_entity(nodePoint).canonical`. A chart is admitted by normalized entity-key and transition-root agreement with the pair record. Exact fan identity variants no longer independently create or reject ownership.

### 2. Pair-first chart witness reconciliation

Node/chart ray evidence is aggregated independently of one fan identity. Every canonical pair then queries the chart inventory for its source and target rays, validates the continuous corner interval, applies the `2*pi` lift only to a proven wrap pair, rejects third-ray intrusion, and records a candidate for that pair.

Candidates are canonicalized by pair, chart, root, normalized entity key, and quantized oriented angles. Duplicate candidates must agree on left-score evidence. Exactly one semantically distinct authoritative witness is required after reconciliation; no rank, frequency, order, or arbitrary subset selection is used.

### 3. Derived boundary-cover diagnostics

The public header now defines `SurfaceArrangementBoundaryFanConflict` with derived subreasons for:

- missing canonical pair;
- exterior pair mismatch;
- zero chart witness;
- multiple chart witnesses;
- normalized chart-entity mismatch;
- transition-root mismatch;
- conflicting duplicate witness scores;
- invalid oriented interval;
- incomplete incoming/target cover;
- hard-rail separator or orbit conflict.

Diagnostics retain the first derived conflict plus node/incoming/source-ray/target evidence. `record_boundary_fan_conflict` also records the existing aggregate `BoundaryFanSectorCoverConflict`; it does not convert failures into warnings or success.

### 4. Transactional and hard-rail authority

The exact independently proven exterior relation is still required and excluded once. Successors remain unpublished until every non-exterior pair has one reconciled witness, incoming/target coverage is complete and one-to-one, predecessor multiplicity is valid, separator checks pass, and every hard-rail bounded orbit supports its selected root.

The existing complete-orbit root audit, opposite-side root distinction, authoritative bounded-cell chart support, and separate full provenance remain intact.

## Scope audit

Changed:

- `include/directional/geometry/SurfaceArrangement.h`;
- `src/geometry/SurfaceArrangement.cpp`.

Unchanged:

- `tests/SurfaceArrangementPhase16Tests.cpp`;
- `tests/MilestoneDClosureTests.cpp`;
- all Phase 17 implementation and tests;
- cylinder and bunny producers;
- FlowRep, completion, optimization, fallback/recovery, fixtures, source-authoritative validators, and unrelated tests.

The exact source commit differs from the workflow event commit only by the two approved production files and removal of the temporary transformation payload.

## Compile gate

Configuration:

- Ubuntu 24.04;
- GNU C++ 13.3;
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

- The exact source commit was pushed before compilation and packaged as `SOURCE_COMMIT`.
- The persistent activity log was initialized before checkout and uploaded separately on success.
- The temporary transformation payload was removed in the source commit.
- The bounded build workflow is removed in the documentation checkpoint after artifact verification.
- Only the durable `.github/workflows/agent-source-snapshot.yml` remains.
- No temporary trigger/payload directory or generated repository build artifact remains.

## Next turn

Execute **P5-TB39 artifact-only R2E11 Test + Benchmark** using build artifact `8950709981`.

Do not configure, rebuild, relink, patch, regenerate, or modify source, tests, fixtures, validators, workflows, or build logic. The runtime gate must determine whether R2E11:

1. restores planar and hard-rail successor publication;
2. exposes an exact derived boundary-fan conflict when publication still fails;
3. restores planar canonical wrap evidence and Euler-one valid disk topology;
4. validates one complete authoritative hard-rail root per bounded orbit and aggregate embedding/topology;
5. restores Phase 17 **26/26** without Phase 17 changes;
6. preserves all accepted R2, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold authority.

R2 remains open until runtime evidence proves closure.

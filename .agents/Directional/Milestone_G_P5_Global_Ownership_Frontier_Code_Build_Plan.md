# Milestone G P5 — Global Ownership Frontier Code + Build Plan

**Next turn type:** Code changes + compile-only build  
**Authoritative input:** P5-TB10 artifact `8844133680` evidence  
**Review policy:** `never`

## Objective

Replace the first-conflict structural-repair model with an exact global ownership frontier. Resolve multiple independent same-corner claims without accepting partial output, misclassifying latent claims as introduced, or performing one full global recomputation per claim.

## Non-negotiable constraints

- Do not delete or deduplicate final faces.
- Do not merge or split vertices based on position.
- Do not special-case production patch, halfedge, or vertex IDs.
- Do not use source-triangle pairing, source-grid recovery, legacy fallback, or validator weakening.
- Do not treat a different first-reported conflict as proof that the candidate introduced it.
- Do not increase arbitrary search budgets to hide the failure.
- Do not enumerate arbitrary route-candidate subsets.
- This turn may configure and compile only. It must not execute tests, benchmarks, or custom meshes.

## P5-CB42 — Make artifact tests self-contained

Correct `BenchmarkManifestDispatchesBackends` so it does not depend on an absolute CI source path.

Use one of these exact mechanisms:

- copy the required fixture tree beside the test executable and resolve it relative to the executable;
- accept a deterministic runtime fixture-root override;
- generate a temporary manifest and copy the minimum required fixture files from packaged test data.

Update artifact packaging to include the required test data. The test must still exercise real manifest parsing and backend dispatch.

## P5-CB43 — Complete compact conflict inventory

Refactor completed-face assembly so it can scan all completed quads and return a deterministic, complete inventory of ownership conflicts.

Each compact conflict record must contain exact—not hash-only—identity for:

- canonical authoritative corner cycle;
- canonical stitch cycle;
- both patch/domain identities;
- oriented and undirected boundary identities;
- source support, component, and sheet;
- patch/local-quad/backend/variant lineage;
- conflict classification.

Requirements:

- preserve the existing immediate hard failure for degenerate faces, inconsistent shared positions, invalid lineage, and invalid domain ownership;
- collect all duplicate ownership claims for otherwise valid completed faces;
- sort and deduplicate conflicts by exact identity;
- retain bounded verbose diagnostics separately from the compact authoritative inventory;
- include the inventory in semantic hashes and repair-state identity.

## P5-CB44 — Prove latent versus introduced ownership

For every structural candidate, compare complete pre-candidate and post-candidate conflict inventories.

Classify outcomes as:

- `ResolvedAllClaims`: post inventory is empty;
- `StrictConflictReduction`: post inventory is an exact strict subset of pre inventory;
- `LatentClaimExposed`: retained claims were already present in the complete pre inventory;
- `IntroducedOwnershipClaim`: post inventory contains an exact identity absent from pre inventory;
- `NoProgress`: inventories are equal;
- `ConflictRegression`: severity/count increases or an invalid ownership class appears.

Mutation locality is supporting evidence, not the authority. Exact inventory membership is authoritative.

The `4956/4954` route may advance to `14137/14136` only if the latter is proven present in the pre-candidate inventory or if the complete inventory strictly decreases without any new identity.

## P5-CB45 — Deterministic global conflict frontier

Drive repair from one invocation-owned non-recursive frontier:

1. obtain the complete conflict inventory;
2. partition claims into connected components using exact overlap of affected domains, boundary intervals, source support, and shared authoritative corners;
3. derive the unique topology-complete candidate for each claim/component;
4. batch candidates from pairwise-independent components into one atomic subdivision transaction;
5. process overlapping components deterministically without arbitrary subset search;
6. commit an internal working state only on strict conflict-set reduction with no introduced claim;
7. emit final output only when the inventory is empty and all validators pass.

Internal progress commits remain transactional and must never expose partial output.

## P5-CB46 — Exact recomputation reuse and wall-time recovery

The P5-TB10 formal wall mean is `67.221522 s`, above the `39.228299 s` cap. Do not add sequential full global passes.

Implement one or both exact strategies:

### Independent repair batching

Union the interval sets of pairwise-independent conflict components and run parity, side repair, completion, and assembly once.

### Dependency-hash completion reuse

Reuse descriptor/completion products only when all exact dependencies match:

- cell/domain identity;
- ordered boundary-node and undirected-halfedge identities;
- side counts and feature constraints;
- source support/component/sheet;
- singularity ownership;
- completion options and backend selection.

Recompute changed components and their proven dependency closure only, then perform authoritative global assembly from cached and recomputed patch products.

Add debug-time equivalence checks against full recomputation for small fixtures. Incremental reuse is not acceptable without exact dependency identity.

## P5-CB47 — Memory discipline

- Keep one authoritative working complex and at most one mutable candidate transaction.
- Store the conflict frontier in compact interned identities.
- Release verbose conflict strings and rejected patch products immediately.
- Avoid retaining duplicate full completed-patch vectors during assembly.
- Preserve current peak-live-candidate count of one.
- Keep every owned-byte category in diagnostics.

The current maximum resident-set margin is only `20,472,320 B`; the next implementation must not consume that margin.

## P5-CB48 — Diagnostics and semantic hashes

Expose:

- complete pre/post conflict counts and exact inventory hashes;
- retained, removed, latent, and introduced claim counts;
- conflict-component identities and independence relations;
- batched candidate interval sets and affected domains;
- reused versus recomputed descriptor/completion counts;
- dependency-closure size;
- full versus reused completion passes;
- current/peak conflict-frontier and product-cache owned bytes;
- typed progress outcome for each transaction.

Hashes are diagnostic; exact identity equality controls behavior.

## P5-CB49 — Compile-only regression sources

Compile, but do not execute, tests covering:

- two independent latent same-corner claims where first-failure reporting previously hid the second;
- complete inventory detects both before repair;
- one independent batched transaction resolves both;
- different post-candidate first conflict classified as latent, not introduced;
- genuinely new conflict classified as introduced and rejected;
- equal inventory classified as no progress;
- overlapping conflict components processed deterministically;
- conflict inventory invariant to patch, face-row, and insertion order;
- exact dependency-hash reuse matches full recomputation;
- semantic hashes mutate for inventory, component, and reuse changes;
- artifact manifest-dispatch test runs without the original CI source path;
- medium fixture preserves one live candidate and bounded memory accounting.

Do not use synthetic final validity or conflict flags.

## P5-CB50 — Compile-only gate

Perform a clean optimized static Release build and compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Package:

- exact pushed source;
- empty source status;
- binaries and libraries;
- executable-relative test fixtures;
- configure/build logs;
- recursive submodule revisions;
- checksums.

Run no test, benchmark, help/list command, or custom mesh executable.

## Required P5-TB11 gates

The following turn must validate the artifact without rebuilding:

- all global-frontier and prior suites pass from an arbitrary extraction path;
- no source-path staging workaround is required;
- at least two formal and two supplementary direct random-bunny processes;
- direct completion succeeds with a nonempty pure-quad output;
- no fallback, recovery, timeout, or partial output;
- exact conflict frontier reaches zero deterministically;
- wall time at or below `39.228299 s` in every process;
- peak memory at or below `1,115,394,560 B` in every process.

Compilation alone does not close P5.

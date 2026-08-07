# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1, and G2 are closed. The earliest incomplete design gate remains **G3 periodic cylinder / holonomy**.

The periodic-annulus producer is now implemented and compile-valid. Runtime verification is pending, so the latest executed cylinder evidence remains:

- producer disposition `NotApplicable`;
- 732 generic traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback or source-grid recovery.

Compilation does not supersede that runtime evidence.

## Proven producer foundation

Artifact-only G2 validation of source `218dd3ec3f6399dc82183390720a4ba4d3a70b42` using artifact `8994541137` established:

- plane: direct valid `Produced`, 64 quads, hash `730caeae49ec872c`;
- seam: direct valid `Produced`, 64 quads, hash `5bdf34d7802e9fb0`;
- close sheets: direct valid `Produced`, 200 quads, two isolated output components, hash `89b052762f52a5af`;
- focused G2 contracts: 7/7 passed;
- no rebuild or source/test/validator edit during artifact validation.

The producer foundation that must be preserved includes:

- first-class `NotApplicable / Produced / Rejected` authority;
- no generic substitution after `Rejected`;
- local lattice phase and integer lattice coordinates;
- reciprocal ordinary-edge transport;
- ordered source-vertex fan transport;
- complete source route provenance;
- component/local-sheet partitioning;
- sheet-qualified materialization identity;
- direct one-cell-to-one-quad materialization;
- fail-closed source-authoritative validation.

## G3 implementation checkpoint

Source `56f823273cad041a01ebb4d0772c3265ff248f4a` implements the bounded periodic correction:

### Applicability and intrinsic chart

- derives the supported singularity-free annulus from source topology rather than fixture identity;
- derives canonical boundary/ring ordering and a deterministic boundary-to-boundary cut;
- builds a cut-open intrinsic chart without requiring global world-space planarity;
- keeps source face/barycentric attachment for chart samples and cell boundaries.

### Periodic holonomy

The periodic cycle is first-class:

```text
r ∈ Z4 quarter-turn rotation
+t ∈ Z2 integer lattice translation
+ordered canonical source route
```

The source also records the deterministic cut route. Duplicate, missing, incompatible, or non-zero unsupported cylinder holonomy returns typed periodic `Rejected` authority rather than generic substitution.

### Periodic front ownership

Artificial-cut front copies are paired using exact periodic lattice identity and explicit `PeriodicFrontMerge` events. The cut is not treated as a genuine exterior boundary; only the two annulus boundary directions are allowed to remain exterior in the bounded periodic front.

### Materialization

Periodic cut-chart duplicates are quotiented by exact lattice/holonomy identity. No Euclidean proximity, nearest projection, or post-hoc cell merge is used.

### Diagnostics and regression source

Holonomy participates in structural hashing and benchmark diagnostics. Five focused producer contracts were added for annulus applicability, face-row invariance, artificial-cut pairing, malformed holonomy fail-closed behavior, and the exact production cylinder producer boundary. They compiled but were not executed in the Code + Build turn.

## Compile authority

- source commit `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- source patch SHA-256 `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`;
- run/job `31196268841` / `92925122791`;
- build artifact `9001168379`, SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- detailed log artifact `9001167184`, SHA-256 `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`;
- recursive artifact checksums **44/44**;
- compile/link actions **111/111** across seven approved targets;
- no generated project binary/test/benchmark execution.

## Required next verification

Execute `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9001168379` without rebuilding or editing implementation/test/validator/build logic.

Validation order:

1. artifact/source/patch/blob integrity;
2. five focused periodic producer contracts;
3. plane, seam, close-sheet passed-gate regressions;
4. exact production cylinder acceptance;
5. periodic holonomy, artificial-cut pairing, genuine-boundary, and deterministic-output evidence;
6. non-overlapping remaining suites;
7. bunny/vase observations only after the G3 decision.

## G3 acceptance

G3 closes only if cylinder becomes direct deterministic `Produced` pure-quad `CompletedSurfaceCells` output with correct periodic closure, only genuine source boundaries, complete provenance, zero strict validation failures, no fallback/recovery, and all G0–G2 regressions retained.

A new exact typed periodic rejection without generic substitution is material progress but does not close G3. If G3 closes, the next implementation gate is G4 topology-distinct completion and singularities.

## Deferred work

Do not broaden G3 into:

- torus/general genus;
- singularities or topology-distinct completion;
- adaptive 2:1 transitions;
- hard-feature expansion;
- bunny/vase production/performance;
- scheduler timing;
- downstream completion/simplification repair;
- cache/memory/diagnostic hardening unrelated to G3 correctness.

## Acceptance discipline

No validator weakening, fixture special cases, generic-producer substitution after rejection, fallback/recovery, positional sheet merging, Euclidean periodic seam welding, arbitrary subset search, synthetic topology correction, post-hoc cycle decomposition, or timeout-as-correctness is allowed.

# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1, and G2 are closed. The earliest incomplete design gate is now **G3 periodic cylinder / holonomy**.

Latest exact cylinder evidence:

- producer disposition `NotApplicable`;
- 732 generic traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback or source-grid recovery.

The active defect is not another close-sheet or planar transition problem. The bounded producer still requires a globally planar rectangular chart and therefore has no authoritative representation for an intrinsically periodic annulus.

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

## Required G3 architecture correction

Implement the bounded periodic producer described by `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Plan.md`.

### Applicability

Recognize only a connected, orientable, singularity-free annulus-like source sheet with two true boundary cycles. Unsupported topology remains `NotApplicable`; malformed authoritative state is `Rejected`.

### Deterministic cut and intrinsic chart

Choose one canonical source-topology cut joining the two boundary cycles and build an intrinsic cut-open chart using transported local tangent/lattice state. Do not require cylinder vertices to lie in a global plane and do not choose the cut by world-space proximity or fixture identity.

### Periodic holonomy

Make the periodic cycle transition first-class:

```text
r ∈ Z4 quarter-turn rotation
+t ∈ Z2 integer lattice translation
+ordered canonical source route
```

Non-integral, nonreciprocal, ambiguous, branch-incompatible, or missing-provenance holonomy must produce a typed authoritative `Rejected` result and stop.

### Periodic front ownership

Pair the two copies of the artificial cut through exact source-route/lattice-holonomy equivalence. The cut is not an exterior boundary. Preserve only the two real cylinder boundary loops as exterior.

### Materialization

Quotient duplicate chart vertices across the periodic cut through exact periodic identity. Never weld by Euclidean proximity, nearest projection, or post-hoc cell merging.

## Verification sequence

The next Code + Build turn compiles but executes no project binary. Add only the minimum contract sources proving:

1. topology-derived annulus applicability;
2. face-row-invariant cut/holonomy;
3. explicit reciprocal periodic front pairing;
4. typed fail-closed invalid holonomy;
5. exact production cylinder reaches the periodic producer boundary;
6. plane, seam, and close-sheet contracts remain compiled regressions.

Package an immutable artifact and execute it only in the following artifact-only Test + Benchmark turn.

## G3 acceptance

G3 closes only if cylinder becomes direct deterministic `Produced` pure-quad `CompletedSurfaceCells` output with correct periodic closure, only the two true source boundary loops, complete provenance, zero strict validation failures, no fallback/recovery, and all G0–G2 regressions retained.

A new exact typed periodic rejection without generic substitution is material progress but does not close G3.

## Deferred work

Do not broaden the active turn into:

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

# Surface Cell Backend Remediation Plan

## Current blocker

G0, G1 and G2 are closed. G3 periodic topology/cut/holonomy, source-strip conformity, exact quotient and field-authoritative ring-correspondence design remain the active constructive direction.

Exact artifact-only execution of `9008118764` / source `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` reveals a new earlier runtime blocker: exact cylinder now deterministically returns `Rejected/InvalidPeriodicChart` at `tracing/phase-front`, cell 29, before traces. Six nominal G3 periodic contracts regress at the same chart stage; the typed genuinely ambiguous correspondence contract and all retained G1/G2 contracts pass.

This is a regression/no-progress result for G3. Do not restore the old lexicographic diagonal correspondence: it was independently proven to be `37.9670987281°` away from the axial field and was the prior field-P95 defect.

## Proven producer foundation

Retain without redesign:

- first-class `NotApplicable / Produced / Rejected` authority;
- no generic substitution after `Rejected`;
- local phase/integer lattice state;
- reciprocal ordinary-edge and ordered source-vertex transport;
- complete source-route provenance;
- component/local-sheet isolation;
- topology-derived singularity-free annulus applicability;
- deterministic intrinsic cut between true boundaries;
- periodic holonomy `(Z4 rotation, Z2 translation, ordered source route)` design;
- explicit artificial-cut periodic ownership and exact quotient identity;
- canonical source-strip breakpoints and per-strip target subdivisions;
- reciprocal field-authoritative adjacent-ring candidate selection;
- typed `InvalidPeriodicRingCorrespondence` / `AmbiguousPeriodicRingCorrespondence` fail-closed behavior;
- direct one-cell-to-one-quad materialization;
- fail-closed source-authoritative validation.

Plane, seam and close sheets remain mandatory direct regressions and are green 3/3 on the latest artifact.

## Reproduced chart endpoint defect

Independent reconstruction using only the immutable packaged cylinder fixture and source reproduces the runtime's first rejected periodic cell exactly at **cell 29**.

`periodic_chart_segment()` uses approximately `1e-10` tolerance while clipping a chart segment against source-triangle barycentric domains. The tolerance is valid for coverage classification, but the same tolerance-expanded interval limits are then emitted directly as geometric barycentric endpoints.

At cell 29, two sides that mathematically share one exact source vertex contain microscopic source-face-30 tails:

- approximately `(-9.9999e-11, 0) -> (0, 0)`;
- approximately `(0, 0) -> (-1e-10, 1e-10)`.

The unchanged `segments_intersect_beyond_shared_endpoint_2d()` predicate therefore observes emitted overlap beyond an exact shared endpoint, and `validate_closed_boundary_paths()` correctly rejects the emitted geometry. The caller records `InvalidPeriodicChart` for cell 29.

The remediation must therefore canonicalize producer-emitted endpoints upstream. **Do not weaken the validator or broadly increase its tolerance.**

## Required bounded correction

Execute `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Plan.md`.

Required implementation behavior:

1. separate coverage tolerance from emitted geometry;
2. canonicalize barycentric endpoint coordinates within the clipping tolerance of an exact simplex boundary to exact `0/1` values;
3. renormalize accepted barycentrics robustly to the source simplex;
4. reject materially invalid/out-of-simplex values;
5. make adjacent intervals that share one mathematical chart breakpoint consume the same exact canonical source point;
6. remove zero-length/tolerance-only segments after canonicalization;
7. preserve canonical endpoints when merging same-face consecutive segments;
8. keep real beyond-shared-endpoint intersections rejected;
9. keep `Rejected` terminal with no generic/fallback/recovery substitution.

No cylinder ID, cell-29, vertex-number, expected-count, source ordering, angular-position or arbitrary subset special case is permitted.

## Required compile-only regressions

Retain the current field-authoritative correspondence and ambiguity tests and add/compile focused coverage proving:

- exact source-vertex periodic endpoints emit canonical barycentrics;
- adjacent cell sides share the same exact source point and avoid false self-intersection;
- genuine shared-face overlap remains rejected by the existing strict validator;
- the six currently regressed nominal G3 periodic contracts are not weakened;
- G1/G2 producer contracts remain unchanged.

Code + Build executes no generated Directional binary. Compile the seven approved targets with `PRE_TEST`, package exact source/blob/patch authority and a `runtimeExecution=false` artifact.

## Latest runtime evidence

Artifact `9008118764`:

- focused/retained producer: **9/15**;
- plane: `Produced`, 64 quads, hash `730caeae49ec872c`, 3/3;
- seam: `Produced`, 64 quads, hash `5bdf34d7802e9fb0`, 3/3;
- close sheets: `Produced`, 200 quads / two components, hash `89b052762f52a5af`, 3/3;
- cylinder: `Rejected/InvalidPeriodicChart`, cell 29, zero traces/output, 3/3, no fallback/recovery;
- bounded producer suite: **91/99**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**.

The latest direct cylinder runtime supersedes artifact `9004509871` as current execution authority even though it is a regression.

## No-progress discipline

This is the first runtime-no-progress Code + Build result since the prior source-strip material-progress turn. The two-consecutive-Code+Build review rule is not yet triggered. If the endpoint-canonicalization Code + Build also fails its following artifact-only acceptance without material progress, the next turn must be a design review or bounded producer replacement proof.

## Deferred work

Do not broaden the next turn into completed-output quality tuning, torus/general genus, singularities/G4 topology-distinct completion, G5 adaptive transitions/features, G6 bunny/vase production/performance, scheduler timing, historical completion/simplification repair, validator changes or unrelated diagnostics/optimization.

## Acceptance discipline

No validator weakening, fixture special cases, count/order/frequency ownership selection, generic-producer substitution, fallback/recovery, positional sheet merging, Euclidean periodic seam welding, arbitrary subset search, synthetic topology correction, post-hoc cycle/cell merging, or timeout-as-correctness is allowed.

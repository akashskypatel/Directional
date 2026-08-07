# Directional Reorientation Plan

## Current orientation

```text
G0 truthful authority [passed]
→ G1 uniform authoritative phase-front plane [passed]
→ G2 cross-chart / close-sheet isolation [passed]
→ G3 periodic holonomy [ACTIVE; periodic authority proven, output validation remains]
→ G4 topology and singularities
→ G5 adaptivity and hard features
→ G6 bunny and vase production success
→ G7 hardening/default-on
```

## Current disposition

Artifact-only G3 validation materially advanced the exact cylinder from generic `NotApplicable` to the authoritative periodic producer. Source `56f823273cad041a01ebb4d0772c3265ff248f4a`, artifact `9001168379`, now yields:

- `Produced` periodic authority;
- holonomy `r=0`, `t=(29,0)`, ordered route 32 edges, cut four edges;
- 290 direct completed quads / 319 provenance vertices;
- no generic arrangement, fallback, or source-grid recovery;
- deterministic 3/3.

G3 remains open because the pre-optimization completed checkpoint reports two validation failures and terminates at `completion/output-validation:AggregateCompletionValidationFailure`. The benchmark does not serialize the two individual validator threshold fields; do not infer or relax them.

Plane, seam, and close sheets remain direct strict-valid deterministic passed gates with hashes `730caeae49ec872c`, `5bdf34d7802e9fb0`, and `89b052762f52a5af`.

## Focused test finding

The periodic row-enumeration contract fails only because it compares raw DCEL source-edge IDs across meshes whose edge numbering changes with face-row traversal. Mapping those IDs to canonical source-vertex endpoint keys gives identical ordered holonomy routes and cuts. This is an incorrect expectation, not production nondeterminism. Correct the test to compare canonical endpoint identity while preserving ordering and holonomy assertions.

## Immediate objective — source-strip-conforming periodic materialization

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md`.

The bounded next implementation must:

1. preserve the proven topology-derived annulus, intrinsic cut, holonomy, periodic ownership, typed rejection, and exact quotient semantics;
2. derive canonical source-ring strips from source topology;
3. retain every source-strip boundary as a mandatory intrinsic periodic lattice breakpoint;
4. choose deterministic positive per-strip subdivisions nearest the local target metric, without fixture/count special cases;
5. make cumulative strip subdivisions define the integral periodic lattice translation;
6. ensure direct output sides do not bridge mandatory source topological corners;
7. retain one authoritative cell → one quad and prohibit post-hoc splitting/merging/welding;
8. correct the row-order test to compare ordered canonical endpoint routes/cuts instead of raw DCEL IDs;
9. compile only, with no generated project binary execution.

### Material-progress condition

Exact cylinder must remain authoritative `Produced` and reach zero completed-checkpoint validation failures/direct `CompletedSurfaceCells` output while plane, seam, and close sheets remain green. The corrected row-order contract must pass semantically without weakening its route/holonomy invariants.

If that succeeds in the following artifact-only validation, G3 closes and the next design gate is G4 topology-distinct completion and singularities.

## Explicitly deferred work

Until G3 passes, do not prioritize:

- torus/general-genus periodic topology;
- singularity topology or topology-distinct patch completion;
- adaptive 2:1 transitions and hard-feature expansion;
- bunny/vase production or performance remediation;
- scheduler-sensitive timing ratios;
- the ten existing downstream completion/simplification failures;
- cache, memory, ownership compaction, or broad diagnostics unrelated to G3 correctness.

## Evidence discipline

- Direct mandatory fixtures outrank aggregate totals.
- Passed earlier gates are mandatory regressions.
- Exact artifact `9001168379` is the current G3 runtime authority.
- No validator weakening or guessed threshold diagnosis is permitted.
- Narrow contract fixtures isolate algorithms but exact production-route acceptance decides gate closure.
- Test turns remain artifact-only; Code + Build turns may use bounded GitHub workflow compilation under policy.
- Timeout is failure only and never correctness evidence.
# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active; periodic authority proven, output validation remains]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G3 artifact validation complete

Exact artifact-only authority:

- source `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- artifact `9001168379`;
- SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- recursive checksums **44/44**;
- no rebuild or implementation/test/fixture/validator/build edit during Test + Benchmark.

### Material progress

The exact production cylinder now reaches the authoritative periodic producer:

- disposition `Produced` instead of prior `NotApplicable`;
- holonomy available: rotation `0`, translation `(29,0)`, ordered route 32 edges, deterministic cut four edges;
- 2,163 source-attached traces;
- zero generic arrangement cells;
- 290 direct completed quads;
- 319 provenance vertices;
- no fallback/recovery;
- deterministic 3/3.

It does **not** close G3 because the completed checkpoint has exactly two validation failures and terminates at `completion/output-validation:AggregateCompletionValidationFailure` before optimization/final output.

Plane, seam, and close sheets remain strict-valid direct `Produced` outputs with unchanged deterministic hashes `730caeae49ec872c`, `5bdf34d7802e9fb0`, and `89b052762f52a5af`.

## Focused contract classification

Focused/retained producer contracts: **11/12 passed**.

`PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` fails only because it compares raw DCEL source-edge integer IDs across independently built meshes. Face-row reversal renumbers those IDs. Mapping each ID to its canonical unordered source-vertex endpoint pair produces identical ordered 32-edge holonomy routes and identical four-edge cuts. The next Code + Build corrects this **incorrect expectation** to compare ordered canonical endpoint identities without weakening grid/holonomy/route semantics.

## Default evidence

- focused/retained producer: **11/12**;
- remaining producer excluding those 12: **82/86**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total: **315/330**.

Timing, bunny/vase, and historical completion failures remain later-gate evidence and cannot supersede the cylinder blocker.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md` as **Code + Build only**.

Required bounded work:

1. retain the working topology-derived annulus, intrinsic cut, holonomy, periodic pairing, typed rejection, and exact quotient authority;
2. make periodic lattice/materialization retain every canonical source-ring strip boundary as a mandatory intrinsic breakpoint;
3. derive deterministic positive per-strip subdivision counts from source topology/intrinsic length and target size, never from fixture IDs or hard-coded cylinder counts;
4. keep periodic translation integral as the cumulative strip subdivision count;
5. ensure output quad sides do not bridge mandatory source-strip corners;
6. keep one accepted phase-front cell → one quad and prohibit post-hoc splitting/merging/welding;
7. correct the row-order test to compare ordered canonical source-edge endpoint keys rather than raw DCEL edge IDs while preserving its other semantic assertions;
8. compile the seven approved targets with `PRE_TEST`; execute no generated project binary;
9. package an immutable artifact for the next artifact-only G3 Test + Benchmark turn.

The benchmark does not expose the two individual failed validator threshold fields. Do not infer or relax them. G3 closes only when exact cylinder becomes direct deterministic strict-valid `CompletedSurfaceCells` output while G0–G2 remain green.

Review policy remains `never`; the next Code + Build plan is authoritative.

Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
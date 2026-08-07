# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G2 closed

Artifact-only validation of exact artifact `8994541137` closes Gate 2.

Authority:

- source `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- artifact SHA-256 `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- recursive checksums **45/45**;
- focused producer contracts **7/7 passed**;
- no rebuild or source/test/fixture/validator/build edit during the test turn.

Direct mandatory results:

- plane: `Produced`, 64 pure quads, zero validation failures, hash `730caeae49ec872c`, deterministic 3/3;
- seam: `Produced`, 64 pure quads, zero validation failures, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets: `Produced`, 200 pure quads, 242 vertices, two connected components, zero validation failures, hash `89b052762f52a5af`, deterministic 3/3;
- no fallback or source-grid recovery on any passing fixture.

The close-sheet producer contract verifies source keys `{(0,0), (1,1)}` and requires every twinned phase-front edge to retain the same source component/local-sheet identity. The exact production output remains two disconnected 121-vertex sheets at `z=-0.035` and `z=+0.035`, proving no cross-sheet connectivity.

G2 is therefore complete. Plane, seam, and close sheets are mandatory regressions for every later gate.

## Active G3 blocker

Cylinder remains:

- authoritative producer disposition `NotApplicable`;
- 732 generic traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

The active missing contract is periodic phase/front construction on a singularity-free annulus.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Cylinder_Code_Build_Plan.md` as a **Code + Build only** turn.

Required bounded implementation:

1. derive annulus applicability from source topology, not fixture identity;
2. construct a deterministic intrinsic cut between the two source boundary cycles;
3. build an intrinsic cut-open phase chart without requiring world-space planarity;
4. record first-class periodic holonomy as quarter-turn rotation + integer lattice translation + ordered source route;
5. reject malformed/non-integral/branch-incompatible holonomy with a typed authoritative reason;
6. pair periodic front edges across the artificial cut through exact source/phase equivalence;
7. materialize periodic lattice duplicates through exact holonomy identity, never Euclidean seam welding;
8. preserve only the two real cylinder boundary loops as exterior boundaries;
9. compile the required regression sources but execute no generated project binary;
10. preserve G0–G2 direct successes.

If cylinder becomes compile-valid for the periodic producer, package an immutable artifact for the following artifact-only Test + Benchmark turn. If runtime later shows only a new exact typed periodic rejection, fix that general rejection next. Do not broaden to torus, singularities, adaptivity, or bunny/vase production during G3.

## Deferred evidence

Current non-overlapping suites:

- focused G2 contracts: **7/7**;
- remaining producer executable: **82/86**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**.

The remaining producer failures are cylinder/bunny/vase acceptance plus the scheduler-sensitive validator timing ratio. The ten completion/simplification failures remain deferred to later ordered gates.

Every completed turn ends with a new top-level PR #8 comment after all other repository writes.

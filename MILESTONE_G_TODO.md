# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Current runtime authority — artifact 9014730437

The G4 holonomy-basis artifact is now validated artifact-only:

- artifact `9014730437`, workflow `31233594490 / 93042009574`;
- primary implementation `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`;
- final compile source `6e754bdd64482582d39e71184805fbb053c99f86`;
- exact ZIP SHA-256 `14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`;
- recursive checksums **46/46**;
- G4 relation semantics **5/5**;
- G0-G3 focused retention **17/17**.

Direct three-process regression authority is unchanged:

- plane: 64 quads / 81 V, hash `730caeae49ec872c`;
- seam: 64 quads / 81 V, hash `5bdf34d7802e9fb0`;
- close sheets: 200 quads / 242 V / two components, hash `89b052762f52a5af`;
- cylinder: `Produced / CompletedSurfaceCells`, periodic `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 V, zero validation failures, two genuine 32-edge exterior loops, hash `32135be51d7a0a26`;
- no fallback/recovery.

Bounded suites are producer **105/106**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **327/338**. The producer's sole failure is still the scheduler/environment-sensitive validator-overhead timing test; the same ten historical completion/simplification failures remain.

## G4 material progress — scalar holonomy barrier removed

The exact connected closed genus-one torus no longer rejects after the second periodic relation.

Three deterministic runs naturally retain **two** periodic relations and advance to:

- 670 trace segments;
- 113 retained strands;
- 113 embedded arrangement arcs;
- zero arrangement cells;
- `NotProductionReady:completion`;
- `SideSubdivisionRepair:InvalidInputIncidence`;
- no output/fallback/recovery.

The first relation compatibility projection remains `r=0`, `t=(24,0)`, route 24, cut 2, but the benchmark JSON does not serialize the full per-relation vector; do not synthesize unexposed relation metadata.

This is material progress over the old `InvalidPeriodicTopology` / zero-trace failure. The multi-relation representation, canonicalization, diagnostics cardinality, and structural hashing are live.

## Active G4 blocker — authoritative phase-front sheet coverage

Runtime reports `surfaceCellAuthoritativeProducerDisposition = NotApplicable` even though two periodic relations and prior sheet-local work are already retained.

Packaged source explains the exact boundary:

1. `build_uniform_phase_front()` processes deterministic `(component, sheet)` work items;
2. each local sheet tries bounded uniform construction, then periodic-annulus construction;
3. produced local sheets append cells and canonical relations;
4. a later `NotApplicable` local sheet causes immediate return of the partially accumulated aggregate;
5. aggregate `Produced` is set only after every sheet succeeds.

The pipeline therefore correctly declines authoritative materialization and falls into the generic tracing/FlowRep path. Its zero-cell arrangement and later `SideSubdivisionRepair` error are downstream symptoms.

Required next contract:

1. every authoritative source sheet must be covered exactly once by a valid bounded/periodic sheet producer before aggregate `Produced`;
2. a later unsupported sheet after earlier produced work must yield a typed phase-front rejection/incomplete-coverage reason, not partial `NotApplicable`;
3. preserve the current canonical periodic-relation collection and all five G4 relation semantics;
4. preserve G2 source-sheet isolation and the torus's current 48 hard feature edges / four closed feature curves;
5. authoritative materialization must consume the complete mixed-sheet aggregate without Euclidean seam welding or artificial exterior cuts;
6. do not repair generic arrangement or completion until a fully produced/materialized phase-front proves they are first-blocking.

Preferred next-slice result is direct strict-valid torus production. A typed exact unsupported-sheet/materialization failure is acceptable material progress; partial `NotApplicable -> zero arrangement -> SideSubdivisionRepair` is not.

## Later G4 singularity observation

The prescribed sphere remains deferred. Previous runtime authority was 766 traces / 30 arrangement cells followed by repeated-boundary-node / parity-alternative exhaustion at completion. Do not preempt the earlier torus producer-coverage contract with this or the ten historical completion/simplification failures.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md` as **Code + Build only**. No generated Directional project binary may execute in that turn.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.

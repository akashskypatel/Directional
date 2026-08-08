# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G3 closure evidence

Artifact `9013161456`, source/test evidence `117620ec2da2083ce11b205835e58fa404f163ef`, runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`:

- exact artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- corrected field-correspondence witness passes under target subdivision;
- focused/retained contracts **17/17**;
- plane/seam/close sheets/cylinder direct strict-valid outputs pass;
- cylinder periodic authority `r=0`, `t=(32,0)`, route 32, cut 4;
- cylinder 1,728 traces, 290 arrangement/simplified cells, 288 pure output quads, 320 vertices/provenance;
- cylinder validation failures **0**, field P95 `8.537736463e-7°`;
- two genuine 32-edge exterior annulus loops and no artificial-cut exterior seam;
- cylinder output hash `32135be51d7a0a26`, deterministic 3/3;
- no fallback/recovery.

Bounded producer is **100/101**, with only the known scheduler/environment-sensitive validator-overhead performance test failing. Completion/simplification remains **154/164**, validation **60/60**, compiled API **8/8**. Direct gate authority outranks those aggregates.

Local evidence archive: `directional-g3-field-correspondence-witness-tb-evidence.tar.gz`, SHA-256 `cf32b8d49626e41922b0214d437e3c0a8a96cdbf90848aae3bb0428644c0baf8`.

G3 is formally closed. The no-progress stop rule is not triggered.

## G4 first structural blocker — torus

The exact torus fixture is connected, closed, genus one: 72 vertices, 144 triangles, 216 edges, no boundary, Euler characteristic 0.

Artifact `9013161456` reports:

- producer `Rejected`;
- first invalid `tracing/phase-front / InvalidPeriodicTopology`;
- terminal `NotProductionReady:tracing`;
- zero traces/arrangement/completion/output;
- no fallback/recovery;
- one already-retained periodic relation in partial diagnostics: `r=0`, `t=(24,0)`, route 24, cut 2.

Exact source inspection identifies the immediate representation defect: `SurfacePhaseFrontResult` stores only one `SurfacePeriodicHolonomy periodicHolonomy`. During authoritative sheet aggregation, a second enabled local relation is rejected solely because the result already contains one relation. Structural hashing, diagnostics, and phase-front materialization likewise consume only that singular relation.

Required next contract:

1. represent multiple compatible periodic relations as first-class authority;
2. canonicalize/equate them from source topology and reciprocal field transport, not discovery order/ID/count/frequency/proximity;
3. fail closed on conflicting, dependent-ambiguous, or nonreciprocal relation authority;
4. make every retained relation live in structural hashing, diagnostics, provenance, and exact lattice quotient materialization;
5. preserve the single-relation annulus behavior and all G0-G3 regressions.

The exact torus must at minimum stop rejecting merely because a second compatible periodic relation exists. Direct strict-valid torus production is the preferred topology-closure result; a deeper truthful failure after the new authority is live/consumed remains material progress for the first G4 slice.

## Later G4 singularity observation

The prescribed sphere currently reaches completion rather than tracing:

- producer `NotApplicable`;
- 766 traces;
- 30 arrangement/simplified cells;
- zero completion;
- `BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=68;budget=68`;
- no fallback/recovery.

Do not preempt the earlier torus topology contract with historical completion repairs. Return to this singularity case after the torus slice is structurally closed.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md` as **Code + Build only**. Compile/package the seven approved targets and execute no generated Directional binary.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.

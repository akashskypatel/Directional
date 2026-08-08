# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Runtime authority — artifact 9019024467

Exact artifact **`9019024467`** (`g4-source-sheet-boundary-code-build`) is runtime-proven artifact-only:

- implementation `b425898fa7367406fa0c07e8f4441a37efc01315`;
- cleanup `3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`;
- workflow run/job `31247546780 / 93078496378`;
- ZIP SHA-256 `a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`;
- internal manifest SHA-256 `7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`;
- recursive checksums **48/48**;
- source-sheet-boundary semantics **3/3**;
- combined source-sheet-boundary + curved-disk semantics **9/9**;
- sheet coverage **3/3**;
- G4 relation semantics **5/5**;
- retained G0-G3 **17/17**.

Direct 3-process authority remains unchanged:

- plane hash `730caeae49ec872c`, 64 quads / 81 V;
- seam hash `5bdf34d7802e9fb0`, 64 quads / 81 V;
- close sheets hash `89b052762f52a5af`, 200 quads / 242 V / two components;
- cylinder hash `32135be51d7a0a26`, 288 pure quads / 320 V, relation `r=0`, `t=(32,0)`, route 32, cut 4, exactly two genuine 32-edge exterior loops;
- zero strict-validation failures and no passing direct fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Report.md`.

## G4 source-sheet boundary decision

The source-sheet boundary contract is now runtime-live. The same physical non-hard internal source edge is accepted only when authoritative component/sheet labels prove a cross-sheet boundary and rejected when labels prove a hidden same-sheet cut. Row re-enumeration remains invariant. Hard-feature and genuine source-boundary authority are unchanged.

Exact torus consequently advances beyond `InvalidBoundedDiskTopology` and now deterministically reaches the next producer invariant:

- disposition `Rejected`;
- stage `tracing/phase-front`;
- reason **`InvalidBoundedDiskBoundaryPhase`**;
- first invalid face `-1`;
- periodic relation count 2, with compatibility projection `r=0`, `t=(24,0)`, route 24, cut 2;
- no trace/arrangement/simplification/completion output;
- no fallback/recovery.

Observed face IDs, relation counts, sheet counts and boundary lengths remain diagnostics only, never production ownership/branching keys.

## Active G4 blocker — generalized disk boundary phase

The current curved-disk producer globally requires exactly four transported boundary runs in canonical rectangular `U+`, `V+`, `U-`, `V-` order and maps them to a rectangle. The torus fails a global boundary-phase invariant after topology and reciprocal transport have succeeded. Existing diagnostics do not expose which global four-run/canonical-order check fired, so no torus run count or sequence is inferred.

Required next contract:

1. make ordered source-attached field boundary runs/corners first-class;
2. derive branch family/sign and signed quarter-turn corner transitions through reciprocal transported 4-RoSy authority;
3. validate cyclic field/singularity closure intrinsically;
4. preserve the existing valid rectangular four-run path exactly;
5. support a legitimate non-rectangular orthogonal/polygonal disk boundary through a deterministic intrinsic polygonal chart;
6. preserve source component/sheet/hard-feature/source-boundary provenance;
7. fail typed on ambiguous boundary phase, invalid cyclic turn/index closure, chart fold, or front pairing;
8. never manufacture a four-sided boundary by arbitrary run merge/split, threshold relaxation, feature demotion, ID/count/order selection, positional welding, or post-hoc cell merging.

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Plan.md` as **Code + Build only**.

## Bounded suites

- producer **115/116**; only `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` fails and remains the existing sub-millisecond performance threshold;
- completion/simplification **154/164**, unchanged historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **337/348**.

Prescribed sphere remains deferred until torus reaches authoritative materialization/direct strict-valid production. G5/G6 and historical completion/simplification repair remain deferred. Review policy remains `never`.

Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.

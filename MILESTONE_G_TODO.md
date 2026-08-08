# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Runtime authority — artifact 9016834575

The curved-disk candidate is now runtime-proven artifact-only:

- artifact `9016834575`, workflow run/job `31240168780 / 93059691196`;
- implementation `90046be649a0fd051e6c44eceec07198dc542c29`;
- cleanup `508211936b790dfb40cdbece7900bb0522368b76`;
- ZIP SHA-256 `6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`;
- internal manifest SHA-256 `e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`;
- recursive checksums **48/48**;
- curved-disk semantics **6/6**;
- sheet coverage **3/3**;
- G4 relation semantics **5/5**;
- retained G0-G3 **17/17**.

Direct three-process authority remains unchanged:

- plane hash `730caeae49ec872c`, 64 quads / 81 V;
- seam hash `5bdf34d7802e9fb0`, 64 quads / 81 V;
- close sheets hash `89b052762f52a5af`, 200 quads / 242 V / two components;
- cylinder hash `32135be51d7a0a26`, 288 pure quads / 320 V, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, two genuine exterior annulus loops;
- no fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`.

## G4 curved-disk decision

The curved bounded disk producer is runtime-live. Exact torus advances beyond `UnsupportedSourceSheetTopology` and now fails directly at the authoritative producer boundary:

- disposition `Rejected`;
- stage `tracing/phase-front`;
- reason `InvalidBoundedDiskTopology`;
- first invalid source face 52;
- two periodic relations reached before rejection;
- trace/arrangement/completion counts remain zero after rejection;
- terminal `NotProductionReady:tracing`;
- no fallback/recovery.

Face 52 and relation count 2 are diagnostic evidence only, never implementation or acceptance keys.

## Active G4 blocker — non-hard authoritative source-sheet boundaries

Immutable source inspection identifies the exact contract mismatch.

The curved-disk producer currently treats an internal local boundary edge as valid only when it is listed in `hardFeatureEdges`. But authoritative local sheets are created by `classify_source_surface_labels()`, which can also stop traversal across a non-hard internal source edge because of normal incompatibility or close/opposing-sheet separation.

Required next contract:

1. genuine source boundary remains valid;
2. hard-feature internal boundary remains valid;
3. a non-hard internal local boundary is valid when the opposite source face has a different authoritative component/sheet label;
4. a non-hard internal edge whose two source incident faces have the same component/sheet remains an invalid hidden cut;
5. use existing source-label helpers/authority rather than raw IDs/order/counts/proximity;
6. preserve exact source edge/face/component/sheet provenance and do not mutate hard-feature labels to force acceptance;
7. advance the exact torus beyond this boundary-authority failure or expose the next truthful typed invariant.

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Plan.md` as **Code + Build only**.

## Bounded suites

- producer **112/113**; only `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` fails and remains classified as the existing sub-millisecond performance threshold;
- completion/simplification **154/164**, unchanged historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **334/345**.

Prescribed sphere remains deferred until torus reaches authoritative materialization/direct strict-valid production. Review policy remains `never`. Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.

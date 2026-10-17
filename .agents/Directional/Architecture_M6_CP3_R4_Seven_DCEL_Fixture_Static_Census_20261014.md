# M6-CP3-CB1-ENTRY-R4 — seven historical DCEL fixture failures: exact-source static census

**Boundary:** same Code + Build turn. Static source only, no test/benchmark execution or acceptance promotion. Do not mistake a repaired source fixture for a runtime PASS.

**Snapshot authority:** workflow [38596495573](https://github.com/akashskypatel/Directional/actions/runs/38596495573); event/source `840583d57ac0263b6d6230bf0b59e1a9b58b0622`; artifact `11909188937`, outer ZIP SHA-256 `d34dd48b864a7f035af75f25d640d242f8820e4ddfd1bdd6c6caff49e4501959`, inner `source.tar.gz` SHA-256 `7b56c88d414e2d7055b8aab7b8906d53b3ce9163590988f7b88bac7476def88c`; **5963/5963** source hashes verified. Last compiled semantic source `6d6d269dd2df211a96de1fcd20bacb54a4e34358`, GMP/GMPXX compile run `38593643840` GREEN on all eight targets; runtime unexecuted.

## Original seven R3 accepted-prefix losses

The frozen `Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt` preserves these exact original ordinals and test identities. `Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv` identifies each as `R3-REV-NEW-02 / DCEL_FIXTURE_CONSISTENCY_EXCEPTION`, which rejected *before* its intended oracle.

| Ordinal | Test identity | Source |
|---:|---|---|
| 40 | `FlowRepStrandsPhase15.RailTruncatedGenericSupportDoesNotInheritLaterTerminalAnchor` | FlowRep |
| 220 | `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` | Periodic |
| 221 | `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` | Periodic |
| 296 | `SurfacePhaseFrontProductFactoryAuthority.DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory` | Periodic |
| 302 | `SurfacePhaseFrontProductFactoryAuthority.ForeignPeriodicRelationRegionRejectsAtCheckedFactory` | Periodic |
| 304 | `SurfacePhaseFrontProductFactoryAuthority.UnknownPeriodicRelationOwnerRejectsAtCheckedFactory` | Periodic |
| 439 | `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` | Periodic |

**Periodic six already source-migrated.** `tests/SurfaceCellTransitionQuotientTests.cpp:244-362`, shared `direct_periodic_owner_fixture()`, constructs four distinct vertices and two triangles `(0,1,2)`, `(0,2,3)` with opposite halfedge directions on internal diagonal `(0,2)`. It constructs a matching two-face source topology region with four exterior boundary edges, builds `TriMesh::set_mesh`, finalizes a two-face raw cross field, and obtains `FieldTransportAtlas::make` from that same source and region authority. All six preserved original test bodies invoke that fixture, with their original bad relation mutations, reorder checks and expected factory oracles. Do not invent, duplicate, or change fixture identities.

**FlowRep one already source-migrated.** `tests/FlowRepStrandsPhase15Tests.cpp:1448-1528` keeps the first source triangle and original truncated generic-rail support while adding the consistently oriented neighboring triangle `(0,2,3)`; actual `vertices` count four, `faces` count two and region/sheet inputs `{3,3}/{5,5}`. `attach_source_authority` at `:65-119` creates a real TriMesh, independent per-face source cross field and source-matched A3 atlas. Its original two-arc and endpoint anchor assertions remain. Other test uses of one-face fixtures are not evidence that these seven remain uncorrected.

**Disposition:** All seven named R3 source-fixture migration edits are *structurally present* on the last compile-green source. They are **not executed** under this turn. A future *separately authorized* artifact-only TB must execute the seven original exact-one identities and verify the original downstream oracles (not just absence of a DCEL exception); subsequent independent Review decides any accepted-credit restoration. No selector changes, TB497, local builds, extra compile, new tests, or acceptance/event-count change. Preserve the remaining 39/34/88/six, RA-43.1/.2/.4, RA-47.12 and organic D1/D2/D3/D5/A6/A7/odd-τ gates.

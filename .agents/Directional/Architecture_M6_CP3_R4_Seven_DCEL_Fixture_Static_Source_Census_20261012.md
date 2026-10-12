# M6-CP3-CB1-ENTRY-R4 — independent static census of seven historical DCEL fixture losses

**Scope:** same ongoing R4 Code + Build turn. This is an exact-source, runtime-free implementation inventory, **not** an independent R4 acceptance Review, acceptance tally, or TB authorization. No source/test/runtime change here.

## Source and historical evidence

- Immutable source snapshot: run `38231038572`, source commit `5ebddc55b47167d5062914156c4be66a390df41c`, artifact `11738461597`, outer SHA-256 `95fce589553b73ec8cd01a0b4bd80a84f159bafa330024062d9261f8ab7f1462`. Snapshot source archive SHA-256 `4607024483c7e39b958e9d65bdef1d0c803f0155599043816b9fe24d55d3a5da`; independently verified archive `source.tar.gz.sha256` and all `6446/6446` snapshot `SHA256SUMS` entries. `runtimeExecution=false`.
- Historical failure authority: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv` has seven distinct rows tagged `R3-REV-NEW-02 / DCEL_FIXTURE_CONSISTENCY_EXCEPTION` and records the prior `compute_edge_quantities(): DCEL consistency check failed` exception. Their *R3* runtime state is RED. Do not equate source repair with a new PASS.

## Two independently inspected current source paths

**Periodic-owner family (six distinct frozen identities).** `tests/SurfaceCellTransitionQuotientTests.cpp:244-356` defines `direct_periodic_owner_fixture()`. It now uses four vertices and oriented source faces `(0,1,2)` and `(0,2,3)`, with the internal diagonal `(0,2)` oppositely oriented and the four exterior boundary keys `(0,1), (1,2), (2,3), (3,0)`. Its `SourceTopologyRegions` includes both face keys in the same component/sheet and its owned region. The helper calls `TriMesh::set_mesh` on the *two-face* source, finalizes a *two-face* original cross-field, constructs `FieldTransportAtlas::make(sourceMesh, sourceAuthority, {}, sourceField)`, and passes the resulting independent A3 into `SurfacePhaseFrontProduct::make`. The six historical identities share that helper:
1. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` (R3 selector ordinal 220).
2. `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` (221).
3. `SurfacePhaseFrontProductFactoryAuthority.DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory` (296).
4. `SurfacePhaseFrontProductFactoryAuthority.ForeignPeriodicRelationRegionRejectsAtCheckedFactory` (302).
5. `SurfacePhaseFrontProductFactoryAuthority.UnknownPeriodicRelationOwnerRejectsAtCheckedFactory` (304).
6. `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` (439).

The fixture keeps deliberately synthetic periodic-owner labels on a disk; these are adversarial checked-factory *owner relation* tests, **not** physical torus or nonzero-holonomy witnesses. Their exact individual first-rejection oracle must still be established by separately authorized runtime evidence.

**FlowRep family (one frozen identity).** `tests/FlowRepStrandsPhase15Tests.cpp:1448+` defines `FlowRepStrandsPhase15.RailTruncatedGenericSupportDoesNotInheritLaterTerminalAnchor` (ordinal 40). It now preserves original face 0 on a four-vertex two-face disk `(0,1,2), (0,2,3)`. `attach_source_authority` in the same file builds `SourceTopologyRegions`, `TriMesh::set_mesh`, an original two-face orthonormal raw cross-field, source-bound `FieldTransportAtlas`, and checked A4 factory provenance, before the downstream FlowRep support-arc checks. The intended support-anchor oracle is preserved; code presence is **not** proof it passes.

## Disposition and precise next boundary

- **Static code-level repair exists for all seven original setup paths.** No additional seven-case source rewrite is justified solely by the R3 DCEL exception list, absent fresh source-exact evidence of a remaining invalid input. Do not relax `DCEL::check_consistency`, invent single-triangle A3, rewrite frozen selectors, or replace the real periodic-owner negatives with physical torus claims.
- **Runtime recovery remains 0/7 verified in this R4 audit.** The last reviewed baseline is accepted CP2 `491/491`, rejected R3 `403/497` with 94 RED and 88 previously accepted CP2 identities RED. This audit performs **no** new C++ execution, bench, discovery or compile, and creates no acceptance tally.
- The next authorized artifact-only R4 Test + Benchmark turn, **only after this Code + Build turn is formally COMPLETE**, must run the untouched frozen 497-case gate, compare these seven exact identities with the R3 review overlay, distinguish DCEL construction from a later A3/checked-A4/target-oracle rejection, and require each test's original positive/negative assertions. The separate four RA-40(C) tests remain diagnostic-only.
- Remaining R4 implementation gates: RA-43.4 typed-rail migration, authentic producer-owned singleton/multi-carrier and odd-τ A2b/A3 witnesses, 39 carried endpoint cases, 34 Phase10 cases, 88 accepted-prefix losses, six CP3 positives, and the previously requested source-valid overfull-A3 independent feasibility Review. No successor release.

# M3-CP4c-3-CB27 Code + Build Report

## Verdict

**COMPLETE / COMPILE GREEN / RUNTIME NOT EXECUTED / SEMANTICALLY UNACCEPTED.**

CB27 implements Part VII §9 `CG0–CG9`. The authoritative semantic source is
`9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5`. The exact eight-target Release/static/GMP build is GREEN in
GitHub Actions run/job `33870767698 / 101015974984`. Compile package artifact `9935929108`
has SHA-256 `b5e11a2c97c110d2cf484d63bb3afe3b753e7f4769098ec927a5cf1692f5d881`; persistent activity-log artifact `9935929698` has SHA-256
`36042ceb31103219d7a7260b8eae878ba093ea3906b64785c8a233b7dc00822b`.

No Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command, or custom
input was executed. `runtimeExecution=false`; this turn creates **no runtime acceptance evidence**. Accepted
semantic authority therefore remains **365/365** from TB23-R1; CP4c-3 remains **OPEN**. Stable accounting remains
**44 events / 14 categories / 30 recurrences**, produced-witness debt **5**. This successful semantic package is
M3 package **89**.

## Source and preservation authority

- start-of-turn semantic source: `cbc850506f0d763a81e4e3362aab959c8a154377`
- exact source snapshot run/artifact: `33861034272 / 9932133575`
- initial CB27 semantic commit: `30d52522045588b8f970524e999cc34907533eb9`
- final CB27 semantic source after the compile-only correction: `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5`
- selector 397: **397 identities**, SHA-256
  `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`; bytes remain frozen.
- selector 401: **401 identities**, SHA-256
  `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`.
- final work-preservation patch is emitted outside the repository for interruption recovery; it is not semantic,
  build, test, benchmark, or acceptance authority.

## Implemented measures

### CG1 / CG2 — authoritative source-face ownership

`SurfaceCutGraphCellularityCertificate` now publishes a total source-face owner map derived from the certifier's
already-constructed embedded topology and face walk. Each entry carries the canonical source-face topology key,
its certified face orbit(s), and trace-fragment side provenance. `find_source_face_owner()` is the read API.

`proves_cellularity()` is strengthened: the map must be total over source faces, its owner ids must refer to the
certificate's own face orbits, and a certificate that cannot establish ownership fails with typed
`SourceFaceOwnershipNotEstablished` evidence naming the source face. No accepted proof obligation is weakened.

### CG3 — ownership becomes a lookup

`GlobalTopologyPlan` no longer reconstructs source-face ownership from the seed quantity. The old
component-barrier / unlabeled-component / `seedOrbits` ownership path is replaced by certificate lookup. The
`UncutFaceComponentOrbitSeedNotUnique` guard is relocated into an explicit certified-owner consistency check that
can name the component and conflicting owners.

### CG4 — unrelated locus restored

The CB25 `;cutCandidateCount=0` suffix is removed from the unrelated source-face locus, restoring ordinal 397's
byte-frozen expectation rather than weakening the witness.

### CG5 / CG7 — gating witness authority

Ordinal 393's seed-relative assertion is replaced in place by the owner-map contract and remains gating. Four new
identities extend selector 397 to selector 401:

398. `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`
399. `SurfaceCutGraph.CellularityCertificateRejectsOwnerOutsideItsCertifiedFaces`
400. `GlobalTopologyPlan.CertifiedSourceFaceOwnerConsistencyCanRejectConflictingComponentOwners`
401. `TestFixturePaths.MissingPackageFailsClosedInsteadOfReturningMissingPath`

The pair includes the required production proof and independent falsifiability witness for the relocated
consistency rule.

### CG6 — fixture resolution fails closed

`tests/TestFixturePaths.h` no longer returns a non-existent candidate path. Artifact consumers must have a real
packaged or sibling fixture tree before runtime can start.

### CG8 — accepted-prefix construction audit

Accepted identities 1–365 are unchanged by construction. Selector 397 is an exact prefix of selector 401 and is
byte-identical to the TB23-R1 authority. The only existing certificate predicate change is a strengthening of
`proves_cellularity()`.

## Compile evidence

The final build checks exact source `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5` and compiles/links exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Configuration is Release, static, `PRE_TEST`, `DIRECTIONAL_ENABLE_GMP=ON`. The configure evidence resolves GMP
and GMPXX from `/usr`; the authority-kernel link line includes `libgmpxx` followed by `libgmp`.

### Corrective compile provenance

Two non-semantic orchestration/build attempts are retained as provenance, not acceptance:

- `33870167342`: zero-job GitHub Actions startup failure caused by the temporary caller's permission ceiling. No
  Directional compile or runtime started. The caller was corrected once.
- `33870305830 / 101014479201`: configuration and GMP checks passed, then `directional_core` compile failed because
  `SurfaceCutGraphSourceFaceOwnership` contains a non-default-constructible `SourceFaceTopologyKey` while the new
  producer default-constructed the owner and assigned the key afterward. The surgical correction constructs the
  aggregate with `faceKey` directly. No runtime ran in this failed build either.

The final compile run is the only GREEN package authority for CB27.

## TB24 discriminators published by CG9

TB24 must report, without reinterpretation:

1. accepted identities 1–365 remain **365/365**;
2. the source-face owner map is published and total on the mechanical production witness;
3. all **191** certified owners for component 0 are reported and classified as **all equal** or **not all equal**,
   deciding `M3-CP4c3-TB21-CAND-01`;
4. ordinal 366 either clears or fails through the relocated consistency guard with the component and conflicting
   owners named;
5. ordinals **393 and 397 are GREEN**;
6. carried surfaces 367/368/369/370/374 are reported without reclassification in EXEC, while
   371/372/391/392 remain PASS if runtime preserves the prior authority.

## Exact successor

**`M3-CP4c-3-TB24-EXEC` — artifact-only runtime execution of package `9935929108` under
`Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Plan.md`.** No rebuild, relink, package repair, source
mutation, test mutation, fixture mutation, selector mutation, or generated discovery is authorized.

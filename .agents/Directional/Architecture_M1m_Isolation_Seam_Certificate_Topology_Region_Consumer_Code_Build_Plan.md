# M1m Isolation-Seam Certificate Topology-Region Consumer — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Entering immutable authority:** M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Selected bounded seam

M1m is limited to:

`SurfaceTopologyRegion::id / build_isolation_seam_transport_certificates -> SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion -> still-raw materializer/hash compatibility consumers`.

Accepted M1l source shows that `SurfaceIsolationSeamTransportCertificate` still persists `sourceTopologyRegion` as a raw `int`. The certificate builder copies `region.id` directly into that field, certificate ordering/duplicate identity compares the raw value, the structural hash consumes the raw value, and the materializer uses it as a raw topology-region map/graph key and compares it against raw `regionByFace` compatibility data.

This is the next narrow semantic owner after M1l because the certificate is a producer-published authority object with an explicit owning topology region and existing fail-closed materializer validation. M1m is a representation/authority migration only; it does not change isolation-seam transport behavior.

## 2. Required implementation shape

Replace only:

`SurfaceIsolationSeamTransportCertificate::sourceTopologyRegion`

from persistent raw integer identity to explicitly nullable checked semantic authority:

`std::optional<authority::TopologyRegionId>`.

Required behavior:

1. In `build_isolation_seam_transport_certificates`, establish the checked region identity from the existing authoritative `SurfaceTopologyRegion::id` using `LegacyAuthorityAdapters::topology_region(region.id, topologyRegions.size())` or the equivalent existing checked adapter boundary.
2. Fail closed if the region ID is negative, out of range, missing, or otherwise cannot establish checked topology-region authority. Do not synthesize a replacement region.
3. Once established, keep certificate-owned topology-region identity typed through persistent certificate storage, certificate comparison, duplicate semantic identity, and other semantic certificate decisions.
4. Certificate semantic equality/order and duplicate detection must compare typed `TopologyRegionId` authority directly. Do not convert two typed IDs back to integers merely to decide whether they represent the same topology region.
5. Keep the certificate structural hash behaviorally compatible. Add one named certificate typed-to-legacy compatibility helper or equivalent narrow conversion at the hash boundary rather than reintroducing a raw persistent mirror.
6. In `pipeline::build_authoritative_phase_front_mesh`, validate that certificate region authority is present before any raw materializer lookup or graph-key operation. Convert to the legacy integer exactly once at the still-raw materializer boundary and use that representation only for existing raw maps/keys/`regionByFace` comparisons.
7. Preserve the existing fail-closed outcomes. Missing/stale/invalid certificate topology-region authority must fail through existing authoritative certificate/source-authority failure paths such as `InvalidAuthoritativeIsolationSeamCertificate` or `IsolationSeamCertificateSourceAuthorityMismatch`; do not create fallback or repair behavior.
8. Preserve source component, isolation-sheet, transition, seam-edge, face-topology, reciprocal quarter-turn, certificate-bijection, and structural-hash semantics.
9. Do not retain both a typed certificate region and a duplicate raw certificate-region mirror.

## 3. Explicit non-goals

M1m must not migrate, redesign, renumber, or reinterpret:

- `SurfaceTopologyRegion::id`;
- `SourceTopologyRegions::regionByFace`;
- `SurfacePhaseFrontResult::sourceTopologyRegionByFace`;
- `SurfacePeriodicHolonomy::sourceTopologyRegion`;
- `SurfaceBoundedDiskBoundaryPhase::sourceTopologyRegion`;
- local materializer `OccurrenceData::topologyRegion`;
- completion/quotient lineage topology-region vectors or sets;
- topology-region discovery, partition, BFS/order, numbering, or structural region hashes;
- accepted cell/edge `TopologyRegionId` authority from M1k/M1l;
- accepted component, isolation-sheet, field-chart, route, or transition authority;
- source component/sheet certificate schemas;
- relation, rail, cell, occurrence, or quotient IDs;
- M2 through M6 architecture work;
- global conformity/hard-rail scheduling;
- periodic nonzero Z4 capability;
- fallback/recovery behavior;
- optimization/performance policy;
- G4 product repair;
- fixtures, validators, benchmark thresholds, or representative product expectations.

If implementation pressure requires any excluded ownership migration, stop and produce a narrower follow-up plan instead of expanding M1m.

## 4. Existing behavior that must remain authoritative

The accepted source already requires isolation-seam certificates to be reciprocal, uniquely keyed by owning region/seam, source-component consistent, backed by an authoritative internal isolation seam, aligned to exact source incidence and the source-wide transition index, sheet-distinct, quarter-turn reciprocal, structurally hashed, and in bijection with required region isolation seams.

M1m changes only the representation of the certificate's topology-region owner. All those contracts remain unchanged.

Existing tests for reciprocal materialization and missing, duplicate, wrong-owner, wrong-sheet, and nonreciprocal certificates remain preservation authority. If a pre-existing raw tampering expression no longer compiles after the type migration, adapt the test only enough to preserve its semantic intent. In particular, a wrong-owner test must use a genuinely distinct checked topology-region witness when one is required; do not manufacture a typed ID using a knowingly false extent merely to make the test compile.

## 5. Required focused compile contracts

Add exactly six production-path contracts under:

`SurfaceCellIsolationSeamCertificateTopologyRegionAuthorityMigration`

Required tests:

1. `ReciprocalCertificatePublishesCheckedTopologyRegionZero`
   - naturally build the existing reciprocal isolation-seam fixture/path;
   - require certificate topology-region authority to be present;
   - require checked value zero through the named legacy representation boundary only for the compatibility assertion;
   - require normal materialization success.

2. `CertificateTopologyRegionRemainsDistinctFromIsolationSheets`
   - use a scenario where topology-region identity and sheet identity are observably different domains;
   - prove the certificate owner is checked topology-region authority and cannot be inferred from either sheet ID;
   - preserve reciprocal materialization.

3. `MissingOrInvalidCertificateTopologyRegionFailsClosed`
   - tamper only certificate region authority to missing/invalid state without weakening structural/certificate checks;
   - require an existing fail-closed authoritative certificate/materializer failure;
   - no fallback or region reconstruction is allowed.

4. `FaceRowPermutationPreservesTypedCertificateTopologyRegion`
   - build equivalent source geometry under a deterministic source-face row permutation;
   - require the certificate's typed owner to preserve the same semantic topology region under the existing region-numbering contract;
   - require unchanged certificate/materializer behavior.

5. `TypedCertificateRegionAgreesWithOwningTopologyRegionSemantically`
   - resolve the certificate's owning `SurfaceTopologyRegion` through the checked ID;
   - require direct typed semantic agreement rather than legacy-integer equality as the assertion's authority;
   - also preserve component/seam ownership consistency.

6. `TypedCertificateRegionToLegacyMaterializerBoundaryPreservesCompatibility`
   - exercise the public producer-to-materializer path;
   - prove the named typed-to-legacy conversion feeds the existing raw region map/key boundary without changing successful materialization, consumed seam count, topology-region count, or product topology.

These tests are production-path authority contracts, not adapter-only unit tests. Do not weaken existing certificate tests or substitute compile mechanics for semantic coverage.

After adding exactly six producer tests, expected following native producer discovery is **232**. With the same 15 separately classified cases, expected following required-green count is **217/217**.

## 6. Likely allowed files

The intended product/test delta is limited to:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp` only where existing certificate tests require typed-semantic adaptation or a natural multi-region wrong-owner witness.

No CMake, fixture, validator, benchmark, CLI, GUI, fallback/recovery, or optimization file is authorized by this plan.

## 7. Regression-pattern requirements

Review `Regression_Root_Cause_Tracker.md` before editing, especially:

- `RP-01` authority-domain conflation: certificate region identity must become typed and stay typed through semantic decisions;
- `RP-02` proxy/incomplete test authority: focused contracts compile this turn but cannot establish acceptance until the following immutable runtime turn;
- `RP-05` representation-dependent identity: raw map/hash representation must remain an explicit compatibility boundary, not semantic owner;
- `RP-07` cyclic/topology identity preservation: do not alter transport/periodic behavior while migrating the owner representation;
- `RP-09` local consumption of global authority: the materializer verifies the producer-owned certificate and must not reconstruct or repair its region owner.

No new stable regression may be hidden by changing an expectation, fixture semantics, failure classification, or product path.

## 8. Code + Build execution boundary

This turn may:

- edit only the bounded source/test paths above;
- compile the exact pushed implementation;
- use Release/static/Ninja with GoogleTest discovery mode `PRE_TEST` or an equivalent compile-only-safe setting;
- compile/link the approved libraries, producer tests, independent oracle/validation targets, M1a/T1 targets, and benchmarks needed for the following immutable package;
- package exact binaries, libraries, fixtures, source/archive/diff, compile database, metadata, logs, and recursive checksums.

This turn must not execute any generated Directional binary, including:

- GoogleTest discovery/listing;
- any focused or aggregate test;
- any benchmark;
- `ctest`;
- CLI/GUI/help/version/smoke command;
- fuzzer;
- custom mesh/input command.

Compile success is not semantic M1m acceptance.

## 9. Immutable package requirements

The successful Code + Build result must preserve enough authority for a separate artifact-only Test + Benchmark turn to verify without rebuilding:

- exact implementation commit and immediate source parent;
- entering accepted M1l implementation `bd140cff4572412e6f4ecd70a6ce0fe85310932c`;
- exact semantic source diff and source archive;
- source blob identities for every touched product/test file;
- recursive submodule/toolchain/configure/build authority;
- seven required executable targets and two static libraries unless the established package layout changes for a documented non-semantic reason;
- complete 27-file fixture closure including all 21 milestone-G files;
- exact focused-test name manifest for six M1m contracts;
- entering M1l through M1b preservation metadata;
- direct-product, historical/deferred-red, strict-timing, Bunny, and Vase names;
- command-boundary metadata proving all runtime/test/benchmark/discovery flags false;
- recursive `SHA256SUMS` generated only after every package write is complete.

Do not repair package contents after creation. If package provenance or manifest closure is wrong, correct it within this Code + Build turn without executing generated project runtime.

## 10. Following immutable runtime gates

The next Test + Benchmark turn must consume the exact M1m package and, assuming exactly six new producer tests and unchanged exclusions, require at minimum:

- producer discovery **232**;
- M1m **6/6** individually;
- M1l **6/6** and all M1k-M1b focused preservation;
- M1d route counterexamples **3/3**;
- M1c transition counterexamples **3/3**;
- required-green producer **217/217**;
- validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- Plane, MultiFaceSeam, CloseSheets, and Cylinder independent-oracle clean;
- all eight historical/deferred red classes unchanged or explicitly classified if they drift;
- truthful strict-validator characterization without threshold/retry workaround;
- bounded Bunny/Vase comparison;
- exact immutable postflight.

## 11. Stop conditions

Stop the Code + Build turn and do not broaden M1m if:

- checked certificate region authority cannot be established from existing producer topology-region extent without changing topology-region construction;
- a compile failure reveals another persistent raw semantic owner outside the declared certificate seam rather than a narrow compatibility adaptation;
- satisfying a focused contract requires fixture-specific production behavior or weakening an existing certificate test;
- product behavior, G4 logic, periodic capability, hard-rail scheduling, fallback/recovery, optimization, or global topology-region numbering must change;
- a requested change would combine Code + Build with runtime validation.

A successful turn ends after exact compile/package evidence is retained and an artifact-only M1m validation plan is written. Do not execute that plan in the same turn.

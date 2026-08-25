# Architecture M3 CP4c — CB2 Production Witness Code + Build Report

**Turn:** `M3-CP4c-CB2`  
**Scope:** W7–W9, Code + Build only  
**Status:** COMPLETE / BUILD GREEN  
**Semantic source:** `a5edb1a31c315d51df216f3bb51470989ff64e33`  
**Exact next:** `M3-CP4c-TB` — artifact-only cumulative 322/322 acceptance gate

## 1. Scope and stop boundary

CB2 implemented only the frozen W7–W9 work from `Architecture_M3_CP4c_Code_Build_Plan.md`:

- two committed production-path witnesses in `tests/FieldAlignedCurveNetworkTests.cpp` using retained
  `productSnapshots.globalTopologyPlan`, not legacy `traceNetwork`;
- all DEFN §8.2 witness self-preconditions asserted before target assertions;
- exact frozen identities C1–C6 appended to the byte-identical accepted 316 selector, producing the
  cumulative 322 selector.

No generated Directional test, benchmark, discovery/list, CLI, fixture, or custom runtime executed in
CB2. Both build jobs record `runtimeExecution=false`. CB2 consumes no CP4c acceptance attempt and no
additional diagnostic. CP4c remains acceptance **0/3**, diagnostics **1/2**.

The witnesses stop at retained topology authority / disc-proof assertions. They do not advance final
quad emission or completion/materializer authority, so CB2 claims **no `G4-B001` progress**. Produced-
witness debt remains **5**.

## 2. W7–W8 production witnesses and self-preconditions

The committed helpers load the existing `milestone-g/torus` and `milestone-g/mechanical_feature`
OBJ/rawfield pairs through `remesh_from_raw_cross_field` with the frozen SurfaceCells options and
require retained `sourceTopologyRegions`, `fieldTransportAtlas`, `fieldAlignedCurveNetwork`, and
`globalTopologyPlan` products.

Each witness asserts the common DEFN §8.2 capabilities before target evidence:

1. at least one published region covers more than one source face;
2. at least two distinct regions exist;
3. quadrangulability is `established()`.

The torus witness additionally asserts a closed source, Euler characteristic 0, derived genus 1, and a
non-trivial multi-face graph cycle on at least one region boundary. The mechanical witness additionally
asserts at least one `SurfaceCellRailKind::HardFeature` mandatory edge lies on a published region
boundary.

The target assertions then verify retained plan/network source and semantic digests, one certificate per
region, disc proof clauses (`boundaryWalkCount == 1`, connected source faces, Euler characteristic 1,
`proves_disc_topology()`, `proves_field_regularity()`), rotation-system / face-walk agreement, typed
intersection tamper rejection, actually produced terminal-event kinds, and mandatory-edge preservation.

## 3. W9 frozen identities and selector integrity

The exact C1–C6 identities are:

1. `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath`
2. `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
3. `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`
4. `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`
5. `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`
6. `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`

Selector evidence from the immutable CB2 source archive:

- accepted first 316: **316 non-empty / 316 unique**, SHA-256
  `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- exact C1–C6 suffix: **6 non-empty / 6 unique**, SHA-256
  `c187acbadf238992d85e9dcfb0f5bf96916bbb37402449803e6714622c7c4276`;
- cumulative selector: **322 non-empty / 322 unique**, SHA-256
  `981511637bfe17b4ed1f359305e285f618f14c006b9d78a76a83c0795eb899cd`.

The first 316 bytes are unchanged from the independently verified DG1/accepted selector authority.

## 4. Semantic publication evidence

Final authoritative semantic-apply workflow evidence:

- schema validation: run/job `32784809188 / 97614400563` — SUCCESS;
- semantic apply: run/job `32784892656 / 97614667050` — SUCCESS;
- apply result artifact `9541087171`, SHA-256
  `8d35310c30b81e09b49c0e1739d937f4c207d73dc78bf2b687aa459229ebf657`;
- apply log artifact `9541087678`, SHA-256
  `7a0d7330f6c87370e86797a05d47ee1e6d3a0b901504661b9887466d2f6f7c08`;
- semantic patch SHA-256
  `94238719249086f8e4453bcd345ddbbf8054779a145f0e8f85c0d919609387e7`;
- resulting semantic commit `a5edb1a31c315d51df216f3bb51470989ff64e33`.

Earlier CB2 apply runs were orchestration/transport attempts only and produced no semantic commit. They
are non-authoritative process history, not product evidence and not CP4c diagnostics/acceptance attempts.
The corrected apply remained `runtimeExecution=false`.

## 5. Changed-owner Code + Build evidence

Workflow run `32785147649`, changed-owner job `97615440289` — SUCCESS.

- semantic source: `a5edb1a31c315d51df216f3bb51470989ff64e33`;
- compiled/preflight target: `directional_surface_cell_producer_tests`;
- result artifact `9541268763`, SHA-256
  `7f7cfd4e29a92fe1995d560e10e1bef181e2c7c3216871f3a521e57bb656b9e7`;
- log artifact `9541269110`, SHA-256
  `85d3702df3e53a398337f07c10c97bb73c16af25965ec98c1393556f10f38336`;
- source archive SHA-256
  `03e7c09d45715de96f1c58ec6cf21b32ca1b542078cfe196ea359c98dea8de66`;
- recursive self-excluding manifest: **22/22 PASS**;
- configure exit 0, preflight exit 0, build exit 0;
- all five source-status snapshots are empty;
- `runtimeExecution=false`.

## 6. Authoritative immutable package evidence

Workflow run `32785147649`, authoritative-package job `97616308786` — SUCCESS.

Immutable package artifact `9541369624`, SHA-256
`bb636eac863475ce41c336713ce7344c11d4a4ed6cd85a6b04634d083a03a778`.
Package log artifact `9541369963`, SHA-256
`2243502f17aae36a4a8eaa3c295f3b8991956674b50f4b49be551e52fc7a0182`.

The package contains the approved six executables and two libraries:

- `directional_benchmarks`
- `directional_compiled_api_tests`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_validation_tests`
- `libdirectional_core.a`
- `libdirectional_pipeline.a`

Evidence checks:

- semantic source `a5edb1a31c315d51df216f3bb51470989ff64e33`;
- source archive SHA-256
  `03e7c09d45715de96f1c58ec6cf21b32ca1b542078cfe196ea359c98dea8de66`;
- recursive self-excluding package manifest: **27/27 PASS**;
- configure exit 0, preflight exit 0, build exit 0;
- all five source-status snapshots are empty;
- `runtimeExecution=false` and turn boundary `Code+Build-only`.

This immutable package is the sole CB2 input authority for the next Test + Benchmark turn. M3 package
accounting advances **35 → 36**.

## 7. Accounting and exact next

- latest accepted runtime authority remains CP4ab **316/316**;
- CP4c acceptance: **0/3**;
- CP4c diagnostics: **1/2**;
- stable regression accounting: **42 events / 14 categories / 28 recurrences**;
- produced-witness debt: **5**;
- M3 packages: **36**.

**Exact next: `M3-CP4c-TB`.** It is artifact-only Test + Benchmark. Consume immutable package
`9541369624` and the frozen cumulative 322 selector, execute exactly one identity per fresh process,
and require **322/322** with zero orchestration errors. That turn owns CP4c acceptance attempt **1/3**.
It must not configure, rebuild, relink, repair, run generated discovery/list commands, or mutate
source/tests/fixtures/selectors/package bytes.

# Gate 3 Field-Correspondence Test Witness — Artifact-Only Test + Benchmark Report

## Decision

**G3 periodic closure / holonomy is formally passed. G4 topology-distinct completion and singularities is now the active design gate.**

The exact compile-only artifact `9013161456` passes the corrected subdivision-independent field-correspondence witness, all **17/17** focused/retained G0-G3 contracts, and the complete direct G3 acceptance set. The exact cylinder retains deterministic direct `Produced / CompletedSurfaceCells` pure-quad output with zero validation failures, valid first-class periodic authority, two genuine annulus boundaries only, and no fallback/recovery.

No implementation, test, fixture, manifest, validator, benchmark, or build logic was edited or rebuilt during this turn.

## Exact artifact authority

- artifact ID `9013161456`, `g3-field-correspondence-test-witness-code-build`;
- outer SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62` — exact expected match;
- source/test evidence commit `117620ec2da2083ce11b205835e58fa404f163ef`;
- runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- test-only patch SHA-256 `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`;
- workflow run/job `31228899303 / 93028533210`;
- log artifact `9013161584`, SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f` — exact expected match;
- recursive artifact checksums **44/44**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- build log reaches **111/111**;
- metadata records Release / Ninja / seven approved targets / `runtimeExecution=false`;
- exact blobs verified independently from packaged source archive:
  - `tests/SurfaceCellsPhase10Tests.cpp` `80a0b58339102279ab863d9112e243a557cd270d`;
  - `src/geometry/SurfaceCellTracing.cpp` `63e5ee427f675077f710db51ffb56d91838d3519`;
  - `include/directional/geometry/SurfaceCellTracing.h` `c1b816a584d67a3f74c2d7389962bd92d52244c9`.

The packaged test binary retained its Actions build-time absolute fixture path. After the first witness attempt exposed only that path mismatch, the allowed runtime-only symlink `/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g3_field_witness_tb/test-data/benchmarks/fixtures` was created. This changed no packaged bytes and is recorded in the local evidence archive.

## Corrected field-authority witness

`SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` passes on the exact artifact.

Because the corrected test itself requires a nonempty set of source-attached `family == 1` boundary-path segments and checks every qualifying segment's finite normalized barycentric source provenance and tangent alignment to the local authoritative V field family, the pass establishes the intended semantic contract without relying on one un-subdivided source edge, source IDs, counts, order, or discovery frequency.

The initial pre-symlink invocation is classified **infrastructure path exposure**, not a semantic failure. The exact same packaged binary passes immediately after the immutable packaged fixtures are exposed through the allowed runtime-only symlink.

## Focused/retained contracts — 17/17

All 17 required contracts pass in one exact packaged producer-test execution: ordered source-vertex fan traversal and row-order invariance, duplicate transition typed rejection, embedded-only relief blocking, disconnected close-sheet partition and row-order invariance, annulus topology, periodic cut/holonomy row-order invariance, canonical strip breakpoints, endpoint canonicalization with genuine overlap rejection, field-authoritative and field-ambiguous ring correspondence, exact artificial-cut pairing, malformed-holonomy typed rejection, and exact committed cylinder/plane producer-boundary contracts.

## Direct G3 acceptance

| Fixture | Result | Producer / origin | Traces | Arrangement | Quads | Vertices | Validation | Field P95 | Hash |
|---|---|---|---:|---:|---:|---:|---:|---:|---|
| plane | pass | `Produced / CompletedSurfaceCells` | 352 | 65 | 64 | 81 | 0 | `3.10940807e-05°` | `730caeae49ec872c` |
| multi-face seam | pass | `Produced / CompletedSurfaceCells` | 256 | 65 | 64 | 81 | 0 | `3.49019465e-05°` | `5bdf34d7802e9fb0` |
| close sheets | pass | `Produced / CompletedSurfaceCells` | 1104 | 202 | 200 | 242 | 0 | `1.65190872°` | `89b052762f52a5af` |
| cylinder | **pass** | **`Produced / CompletedSurfaceCells`** | 1728 | 290 | **288** | **320** | **0** | **`8.537736463e-07°`** | **`32135be51d7a0a26`** |

All four have pure-quad rate 1, zero non-quads, zero nonmanifold edges/T-junctions/duplicate faces/self-intersections, topology and boundary preservation, complete provenance, no fallback attempt/use, and source-grid recovery disabled/unused.

### Exact cylinder closure

Cylinder retains the prior production result exactly: periodic holonomy rotation `0`, translation `(32,0)`, route 32, cut 4; 1728 traces; 290 arrangement/simplified cells; 288 accepted/completed quads; 320 provenance/output vertices; zero validation failures; output hash `32135be51d7a0a26`; and no fallback/recovery.

The benchmark JSON does not serialize raw normal-P95 or warpage-P95 values. The packaged production `surface_cell_validation_failure_count` counts `normalP95Degrees > 15`, `fieldP95Degrees > 15`, and `warpageP95Degrees > 30` among its hard failures. Therefore exact `surfaceCellValidationFailures = 0` proves those existing thresholds passed without changing them.

Independent output-topology inspection records 64 boundary edges in exactly two degree-2 loops of 32 vertices each: one entirely at z=-1 and one at z=+1. The artificial periodic cut is therefore not exterior.

## Determinism

Plane, seam, close sheets, and cylinder each ran in three independent packaged processes. All are stable **3/3** for success/disposition, output origin, periodic tuple where applicable, route/cut counts, trace/arrangement/simplification/completion/provenance counts, validation count, all stage output hashes, output hash, exposed field P95, and no-fallback/recovery state.

Wall seconds: plane `0.346240 / 0.347302 / 0.343368`; seam `0.521787 / 0.548238 / 0.541981`; close sheets `2.961650 / 3.003050 / 3.013284`; cylinder `2.638203 / 2.630314 / 2.634992`.

## Default suites

- corrected/retained focused producer contracts: **17/17**;
- remaining bounded producer tests excluding the focused set and long BunnyRandom/Vase parameterized design-acceptance cases: **83/84**;
- bounded producer total: **100/101**;
- sole producer failure: `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`, classified as the known scheduler/environment-sensitive performance check, not G3 semantic correctness;
- completion/simplification: **154/164**, the same historical ten failures;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded non-overlapping aggregate: **322/333**.

The ten completion/simplification failures are unchanged historical FlowRep/PatchDescriptor/SurfaceComplexSimplification failures and remain deferred. Direct gate evidence outranks aggregate totals; no historical failure was repaired or reclassified in this turn.

## Mandatory later-fixture observations

To remain consistent with `tests/TESTING_STRATEGY.md`, the two expensive later fixtures were also observed after the G3 decision.

- bunny: producer `NotApplicable`, 80,862 traces, zero arrangement/completion/output, terminal `NotProductionReady:completion`, wall `22.636191s`, peak working set `236716032` bytes, no fallback/recovery. This remains a G6 blocker and does not affect G3 closure.
- vase: no completed record within the bounded 45-second observation. The process was terminated. Timeout is **failure only**; no disposition or correctness inference is synthesized.

## G3 gate decision

All formal G3 conditions are satisfied: exact artifact integrity, corrected semantic witness, **17/17** focused/retained contracts, direct plane/seam/close-sheets/cylinder success, deterministic strict-valid cylinder output, no fallback/recovery, and retained G0-G2 regressions.

**G3 is passed.** Optional Review is skipped; the next Code + Build plan is authoritative.

## First G4 observations

After G3 closure was decided, existing packaged fixtures were used only to locate the earliest G4 structural contract. No source was edited.

### Torus — earliest G4 blocker

The exact torus is a connected closed triangulated surface with 72 vertices, 144 triangles, 216 edges, zero boundary edges, Euler characteristic 0, hence closed orientable genus 1.

Runtime rejects at `tracing/phase-front` with typed `InvalidPeriodicTopology`, zero emitted traces/arrangement/completion/output, and no fallback/recovery. Partial phase-front diagnostics already expose one periodic relation: rotation `0`, translation `(24,0)`, route 24, cut 2.

Exact source inspection isolates a first-class representation/aggregation limit: `SurfacePhaseFrontResult` stores one scalar `SurfacePeriodicHolonomy periodicHolonomy`; while aggregating authoritative sheet results, encountering a second enabled local periodic holonomy immediately rejects `InvalidPeriodicTopology`. Materialization, hashing, and diagnostics likewise consume only that singular relation.

This is the earliest general G4 contract. The next implementation must not simply allow a second relation by discovery order. It must introduce deterministic source-topology/transport authority for multiple compatible periodic relations, canonicalize them without ID/count/frequency/proximity ownership, and make every retained relation live and consumed by hashing, diagnostics, and exact quotient materialization.

### Prescribed singular sphere — later G4 observation

The sphere reaches completion rather than the torus tracing gate: producer `NotApplicable`, 766 traces, 30 arrangement/simplified cells, zero completed output, terminal `NotProductionReady:completion`. Completion reports `BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=68;budget=68`, with domain-identity failure `repeated-boundary-node` at cell 26 / halfedge 39 / node 13 / source face 7. It remains within G4 but is downstream of the torus structural blocker.

## Next authoritative turn

**Code + Build — G4 closed-genus-one periodic authority.**

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md`.

The first slice must preserve all G0-G3 contracts while replacing the singular periodic-holonomy aggregation/consumption assumption with deterministic first-class multi-relation authority sufficient to advance closed genus-one topology. It must fail closed on dependent/inconsistent/ambiguous relations rather than choosing by order/count/frequency. No generated Directional binary may execute in that Code + Build turn.

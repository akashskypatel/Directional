# Gate 3 Periodic Chart Endpoint Canonicalization — Artifact-Only Test + Benchmark Report

## Decision

**Material runtime progress is proven. The production G3 runtime closure contract is now satisfied on the exact cylinder, but formal G3 gate closure remains pending one incorrect unit-test expectation.**

Artifact `9010838200` restores the nominal periodic contracts that had regressed at `InvalidPeriodicChart` cell 29 and advances the exact cylinder all the way to deterministic, direct, strict-valid `CompletedSurfaceCells` output. No fallback or source-grid recovery is used.

The sole focused failure is `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`. Its production precondition now succeeds (`phaseFront.disposition == Produced`); the failure is only `exactInterRingEdges > 0`. That witness requirement is structurally impossible for the test's own target size and fixture: source ring spacing is `0.5`, the test target is `0.25`, production therefore uses `gridV=8` and `stepV=0.25`, so every source inter-ring edge is represented by two phase-front V edges. No single V edge can have both endpoints at distinct exact source-ring vertices. The test must inspect source-attached V boundary-path segments rather than require an un-subdivided source edge.

The next turn is therefore a **test-only Code + Build correction**. Production behavior must not change.

## Exact artifact authority

- artifact ID `9010838200`, `g3-periodic-chart-endpoint-canonicalization-code-build`;
- outer SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- source/test commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- base production checkpoint `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- patch SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`;
- build run/job `31221873296 / 93007996817`;
- log artifact `9010837410`, SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- recursive checksums **44/44**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- final blobs:
  - `SurfaceCellTracing.h` `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
  - `SurfaceCellTracing.cpp` `63e5ee427f675077f710db51ffb56d91838d3519`;
  - `SurfaceCellsPhase10Tests.cpp` `bef95b04c95c9a213c634e604d004b3d7d22646e`;
- build metadata: Release static / Ninja / seven approved targets / `PRE_TEST` / `runtimeExecution=false`;
- build log: `111/111`, `build_exit=0`, `package_exit=0`;
- exact cylinder fixture SHA-256:
  - OBJ `59ed6d736410dbef6bc751136ba0eb1d557a43c9df63fb2a570daf85c79419ae`;
  - raw field `6e861e06fa5d3dd6ed84c48bf7d459df701acd7f6ab241cc2adbde66d829084d`.

A runtime-only `bin/test-data -> ../test-data` symlink exposed immutable packaged fixtures. No packaged byte was changed. No configure, compile, relink, discovery regeneration, source/test/fixture/manifest/validator/benchmark/build edit, or replacement build occurred in this turn.

## Focused/retained contracts

Raw result: **16/17 passed**.

### Endpoint canonicalization — 2/2

- `PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints` — pass;
- `PeriodicChartEndpointCanonicalizationKeepsGenuineOverlapRejected` — pass.

This proves tolerance-based chart ownership no longer leaks tolerance-expanded tails into emitted source geometry, while genuine overlap beyond a shared endpoint remains rejected by the unchanged strict predicate.

### Field correspondence — one raw assertion failure

- `PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed` — pass;
- `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` — **fails only its witness-count assertion** after successfully reaching `Produced`.

Failure:

```text
Expected: exactInterRingEdges > 0
Actual:   0
```

Classification: **incorrect expectation / invalid witness precondition**, not production implementation failure.

The test's `exactInterRingEdges` counter only examines a V phase-front edge when both edge endpoints are distinct exact source vertices. For this fixture/test:

- source rings are at z = `-1, -0.5, 0, 0.5, 1`;
- inter-ring spacing is `0.5`;
- target size is `0.25`;
- production `gridV = round(2.0 / 0.25) = 8`;
- each V phase-front step is `0.25`.

Therefore each authoritative axial source inter-ring edge is deliberately subdivided into two V front edges, and the expected witness cannot exist. The existing test never reaches its axial dot-product assertion because the witness filter removes every valid subdivided V segment.

The fixture itself is valid: it still creates the axial-versus-diagonal correspondence ambiguity, and the separate genuinely field-equivalent ambiguity test passes. The correct regression test should inspect every nonzero source-attached V boundary-path segment (or equivalent transported correspondence evidence), reconstruct its source-space direction from face+barycentric provenance, compare it against the local authoritative V family, and require non-empty observations. A diagonal mapping would then fail by the known ~37.967° deviation without relying on source-edge cardinality or subdivision.

### Retained periodic/G1/G2

All other active/retained contracts pass, including annulus topology derivation, canonical route/cut row-order invariance, canonical boundary-strip breakpoints, artificial-cut pairing, malformed-holonomy typed fail-closed behavior, exact committed cylinder authoritative producer boundary, and all seven retained G1/G2 contracts.

Thus the six nominal G3 periodic regressions from artifact `9008118764` are restored to their intended production/typed behavior; the only raw failure is the invalid field-witness assertion above.

## Direct mandatory fixtures

All active direct fixtures use requested `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, warmup 0, one measured run per independent process.

| Fixture | Result | Producer | Traces | Direct quads | Validation | Output hash | Determinism |
|---|---|---:|---:|---:|---:|---|---|
| plane | pass | `Produced` | 352 | 64 | 0 | `730caeae49ec872c` | 3/3 |
| multi-face seam | pass | `Produced` | 256 | 64 | 0 | `5bdf34d7802e9fb0` | 3/3 |
| close sheets | pass | `Produced` | 1,104 | 200 | 0 | `89b052762f52a5af` | 3/3 |
| cylinder | **pass** | **`Produced`** | **1,728** | **288** | **0** | **`32135be51d7a0a26`** | **3/3** |
| bunny | later gate | `NotApplicable` | 80,862 | 0 | — | none | one bounded |
| vase | later gate | no completed record in 45 s | — | — | — | — | bounded timeout only |

### Cylinder G3 closure evidence

Exact cylinder now reports:

- `surfaceCellAuthoritativeProducerDisposition = Produced`;
- `surfaceCellOutputOrigin = CompletedSurfaceCells`;
- first-class periodic holonomy available;
- quarter-turn rotation `0`;
- translation `(32,0)`;
- ordered holonomy route edge count `32`;
- cut edge count `4`;
- 1,728 trace segments;
- 290 arrangement cells / 290 simplified cells;
- 288 direct completed quads;
- 320 provenance vertices;
- 320 output vertices / 288 output faces / 288 quads / **0 non-quads**;
- `surfaceCellValidationFailures = 0`;
- field alignment P95 `8.537736463e-07°`;
- surface approximation P95 `2.832791574e-16`;
- pure-quad rate `1`;
- zero nonmanifold edges, T-junctions, duplicate faces, self-intersections and degenerate output faces;
- topology preserved and boundary preserved;
- no fallback attempt/use and no source-grid recovery.

The benchmark JSON does not serialize raw `normalP95Degrees` or `warpageP95Degrees`. Authoritative `surfaceCellValidationFailures = 0` proves both existing scalar gates pass because the production failure-count function includes `normalP95Degrees <= 15` and `warpageP95Degrees <= 30` plus all other strict thresholds. As a non-authoritative geometry cross-check, the serialized output has warpage P95/max `0°`, and nearest source-panel normal error P95/max approximately `8.54e-7°`.

Independent output-topology inspection finds exactly **64 boundary edges in two 32-edge degree-2 loops**, one entirely at z=`-1` and one entirely at z=`+1`. Therefore the artificial periodic cut is not an exterior seam; only the two true annulus boundaries remain exterior.

Provenance vertex count equals output vertex count (`320 == 320`), and completed quad count equals output quad count (`288 == 288`).

### Material-progress comparison

Immediately preceding artifact `9008118764` had cylinder `Rejected/InvalidPeriodicChart`, cell 29, with zero traces/completion/output and no terminal holonomy.

Current artifact `9010838200` has cylinder periodic `Produced`, direct strict-valid `CompletedSurfaceCells`, zero completed validation failures, field P95 approximately zero, and deterministic 3/3 output. This is unambiguous material progress and resets the no-progress counter. The mandatory design-review stop rule is **not triggered**.

Compared with earlier source-strip artifact `9004509871`, which reached output validation with field P95 `37.9670987281°`, the current field P95 is `8.537736463e-07°` and validation failures fall from 3 to 0.

## Determinism

Plane, seam, close sheets and cylinder were each executed in three independent processes. For each case, success/disposition/output origin, periodic holonomy tuple and route/cut counts where applicable, trace/arrangement/completion/provenance counts, validation count, stage structural hashes, output structural hash and exposed field P95 are stable 3/3.

Cylinder output hash is `32135be51d7a0a26` in all three runs.

## Later-gate observations

- bunny: `NotApplicable`, 80,862 traces, zero arrangement/completion, `NotProductionReady:completion`, ~22.42 s, peak working set ~247.75 MB, no fallback/recovery;
- vase: no completed record within the bounded 45-second observation; timeout is failure only and carries no correctness inference.

These do not affect G3 acceptance.

## Default suites

Bounded producer suite excluding only the two long BunnyRandom/Vase parameterized design-acceptance cases: **99/101**.

Failures:

1. `StrictValidatorOverheadStaysBelowFivePercent` — known timing/performance gate; repeated independently five times and failed 5/5 in this environment. It remains scheduler/environment-sensitive closeout evidence, not G3 functional authority.
2. `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` — incorrect witness expectation described above.

Other suites:

- completion/simplification: **154/164**, same historical ten failures;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded aggregate: **321/333**.

Direct gate status outranks aggregate totals.

## Gate decision

The **production implementation satisfies the G3 runtime closure contract** on the exact cylinder, including direct deterministic strict-valid periodic output and G0-G2 retention.

Formal project gate status remains **G3 active — closure pending test correction only**, because one focused test currently asserts a witness that cannot exist under its own target subdivision. This is not a justification to weaken the test: the next test should directly observe all source-attached V-family path segments and preserve/strengthen the intended field-authority assertion.

Optional Review is skipped. The following plan is authoritative.

## Next turn

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md` as **Code + Build only**.

Production source should remain unchanged unless source inspection proves an unexpected inconsistency. Correct only the invalid test witness so it verifies the same field-authoritative correspondence invariant independently of target subdivision/cardinality. Compile/package the exact test-only revision; execute no generated project binary.

The following artifact-only turn should rerun the focused 17 contracts plus exact cylinder and passed G0-G2 cases. If the corrected field-authority test passes and direct cylinder remains the same strict-valid periodic output, formally mark G3 passed and advance to G4.

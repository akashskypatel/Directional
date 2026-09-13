# M4-CP3-CB9 Code + Build Plan — restore bounded-disk applicability disposition without regressing cut-open occurrence authority

**Turn:** `M4-CP3-CB9`
**Status:** FROZEN / NOT STARTED
**Turn type:** product Code + Build / runtime-free
**Owner:** `M4-CP3-TB6-REV-CAND-01`
**Entering accepted runtime authority:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Rejected candidate:** CB8 package `10303165017` / selector408 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
**Runtime authority:** none in CB9. Compile/package evidence only.

## 1. Single bounded problem

CB8 correctly introduced cut-open occurrence-domain consumption for the exact torus row408 and TB6 proves that recovery 2/2. The same implementation also changed an accepted negative contract at selector403 ordinal138.

For the square hard-feature fixture, each topology region is a valid one-face disc with exactly three boundary segments. Current CB8 logic activates accepted-cut handling for every region satisfying:

```text
globalTopologyPlan && globalConformityBaselinePlan && regionHasHardFeature
```

and then rejects `acceptedSegments.size() < 4` as `InvalidFrontBoundaryAuthority`. The established bounded-disk cardinality gate later treats `<4` as `NotApplicable`. That order converts “valid domain, producer cannot form a >=4-side bounded chart” into “invalid authority”.

CB9 owns only that distinction. It does not redesign occurrence identity, topology, A3 scheduling, hard-rail pairing, aggregate fail-closed behavior, tests, fixtures or selectors.

## 2. Mandatory pre-mutation guards — STOP on any failed proof

### G1 — ordinal138 must be proved to hit exactly the suspected branch

From exact current source and fixture bytes, derive all of the following before mutation:

1. `make_square_mesh()` has exactly faces `(0,1,2)` and `(0,2,3)`;
2. user hard edge `{0,2}` is effective HardFeature authority for the fixture;
3. A1 partitions the support into exactly two one-face regions;
4. each region is a valid disc (`V/E/F=3/3/1`, `chi=1`) with exactly three boundary support segments;
5. accepted topology/baseline plans are present and bound, so current `useAcceptedCutDomain` is true;
6. accepted A2b boundary incidences for each region materialize exactly three valid segments with no missing/ambiguous carrier, orientation, source-face or schedule authority;
7. current source reaches `acceptedSegments.size() < 4U` and publishes `Rejected/InvalidFrontBoundaryAuthority` **before** the later common `<4 => NotApplicable` gate;
8. pre-CB8/current physical applicability semantics treat a valid `<4` bounded boundary as `NotApplicable` rather than authority corruption.

If any premise is false, **STOP before mutation** and return to Review. Do not change the test or guess a broader fix.

### G2 — row408 must remain a distinct cut-open occurrence-domain case

Re-prove from current source + frozen fixture bytes:

- exact effective HardFeature set is still the 18-edge two-generator torus cut graph;
- raw source support remains `72/216/144`, `chi=0`;
- accepted reduced/cut support remains a disc with exact occurrence authority and 18 two-sided interior barriers;
- current row408 accepted boundary has at least four accepted boundary segments, so the ordinal138 cardinality correction cannot classify row408 as the same small-domain case;
- distinct cut copies/repeated source-vertex occurrences are still required through chart construction and exact A3 pairing.

If the proposed correction would disable the accepted-cut occurrence path for row408, **STOP**.

### G3 — freeze the semantic disposition boundary

Before mutation, write down and check the exact partition:

**Must remain `Rejected/InvalidFrontBoundaryAuthority`:**
- topology/baseline digest mismatch;
- missing or ambiguous region/incidence/arc/source-path binding;
- invalid carrier/source-face ownership;
- contradictory orientation/schedule/span authority;
- non-disc or inconsistent accepted topology authority;
- occurrence collapse or failure to preserve distinct opposite cut copies;
- exact A3 pairing/provenance contradiction.

**Must remain `NotApplicable`:**
- accepted authority is valid and total, but the bounded-disk producer's boundary cardinality is below its minimum chart size (`<4`).

The aggregate hard-feature path remains fail-closed: three producers returning `NotApplicable` still yields the established public `UnsupportedSourceSheetTopology`; no legacy fallback is authorized for mandatory hard rails.

If one code change cannot preserve this partition, **STOP and return to Review** rather than widening CB9.

## 3. Authorized implementation

After G1-G3 all pass, make the smallest product-source change in the curved bounded-disk producer that restores `<4 valid accepted boundary => NotApplicable` while preserving every typed invalid-authority rejection.

Expected seam: `src/geometry/SurfaceCellTracing.cpp` at the current early `acceptedSegments.size() < 4U` guard. Prefer changing only its disposition/return semantics so valid small planned regions flow through the same applicability outcome as valid small physical regions.

The guard result, not this expectation, is authority. If the exact source proof shows a different minimal seam is required, the change must still remain within this function's applicability/disposition handling and satisfy G1-G3. Any second semantic dependency or cross-stage redesign is a STOP.

## 4. Frozen bytes and prohibited changes

Do not modify:

- `tests/**` or fixtures;
- any `Required_Green_Selector_*.txt`;
- row408 thresholds/hard-edge witness;
- A1/A2a/A2b topology writers;
- A3 conformity writer/schedules/breakpoints;
- pipeline aggregate `UnsupportedSourceSheetTopology` fail-closed contract;
- public diagnostic meanings;
- reusable workflow permissions;
- benchmark source.

No geometry/tolerance/local-grid fallback. No broad `InvalidFrontBoundaryAuthority -> NotApplicable` rewrite. No bypass of typed occurrence identity.

Frozen selector authority:

```text
selector403 = 403 / c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector408 = 408 / c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484
first403 = byte-identical selector403
owners = 30 authority-kernel / 262 producer / 75 completion / 41 validation
```

Any selector/owner drift is a STOP.

## 5. Compile/package boundary

CB9 is Code + Build only. No Directional runtime, GTest execution/listing/discovery, `ctest`, or benchmark execution.

After the semantic correction:

1. compile/link the changed owner target `directional_surface_cell_producer_tests` through durable `agent-compile-reusable.yml`;
2. only if green, compile/package the frozen eight targets:
   - `directional_core`
   - `directional_pipeline`
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
   - `directional_compiled_api_tests`
   - `directional_benchmarks`
3. require GMP/GMPXX linkage, `exactArithmeticBackend=GMP`, clean source-status snapshots, exact source archive/manifest, 28/28 root package checksums and `runtimeExecution=false`.

A compile-only defect may receive one bounded mechanical remediation inside the same authorized source seam. A second semantic dependency, changed test, changed selector, or changed public contract stops back to Review.

## 6. Precommitted future runtime falsifiers — not executable in CB9

If and only if CB9 compile/package is green, the next Test + Benchmark plan must consume that immutable package without rebuild or repair and fail fast in this order:

1. **ordinal138 focused A/B:** two fresh exact-filter processes; both must PASS and independently observe the accepted `UnsupportedSourceSheetTopology` + all-three-declined contract;
2. **row408 focused A/B:** two fresh exact-filter processes; both must PASS `Produced` with exact A2b/A3 occurrence-domain receipts;
3. **rows404-407 A/B:** eight fresh exact-filter processes; all must PASS;
4. only after all 12 focused/control processes are GREEN, run selector403 **403/403** fresh processes;
5. only after selector403 is fully GREEN, run selector408 **408/408** fresh processes;
6. immutable pre/postflight is mandatory and Review owns promotion.

Any RED/SKIP/crash/timeout/selection mismatch stops immediately. In particular:

- ordinal138 RED means the compatibility regression persists;
- row408 RED means CB9 overcorrected and regressed the CB8 occurrence-domain repair;
- a typed tamper control RED means CB9 weakened invalid-authority rejection;
- accepted selector403 RED means candidate remains rejected even if both focused witnesses pass.

## 7. Completion criteria

CB9 may close Code + Build only when:

- G1-G3 are recorded GREEN before mutation;
- product mutation is bounded to the proved applicability/disposition seam;
- tests/fixtures/selectors are byte-unchanged;
- no A2b/A3 writer or public aggregate fail-closed semantic changes;
- changed-owner compile is GREEN with GMP/GMPXX;
- frozen eight-target package is GREEN and immutable with `runtimeExecution=false`;
- exactly one immutable Test + Benchmark successor is frozen; no runtime is executed in CB9.

Otherwise STOP and return to Review with the earliest failed guard/compile evidence.

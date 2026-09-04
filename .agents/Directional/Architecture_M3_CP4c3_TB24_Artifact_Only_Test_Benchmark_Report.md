# M3-CP4c-3-TB24 Artifact-Only Test + Benchmark Report

## Status

**COMPLETE / VALID IMMUTABLE SEMANTIC RUNTIME / SEMANTIC RED / ACCEPTED PREFIX SAFE / REVIEW REQUIRED.**

`M3-CP4c-3-TB24-EXEC` executed selector 401 from the immutable CB27 compile package. The formal execution is
valid and complete: **389 PASS / 12 RED**, accepted ordinals **1–365 = 365/365 PASS**. Because gating identities
remain RED, CP4c-3 stays **OPEN** and the exact successor is **`M3-CP4c-3-TB24-REV`**, independent REVIEW + PLAN
only. This report records runtime facts and does not diagnose or classify the RED surfaces.

## Immutable authority

- semantic source: `9c72fea8b666534b9e52fa42bbe8cbf8ae68ffe5`
- immutable CB27 package: `9935929108`, SHA-256
  `b5e11a2c97c110d2cf484d63bb3afe3b753e7f4769098ec927a5cf1692f5d881`
- package producer run/job: `33870767698 / 101015974984`
- formal TB24 run/job: `33891467611 / 101083954177`, **SUCCESS**
- TB24 result artifact: `9944102469`, SHA-256
  `0c72806d0e975bf9829c3b3a130001529a7728fe3f6d1be6e6d8aa3125898f6c`
- TB24 diagnostic-log artifact: `9944102936`, SHA-256
  `0147193e71a493428918d151cf6a26ea2148d1d3d3831eaf4da8afc285aaba74`
- selector 397: 397 identities, SHA-256
  `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`
- selector 401: 401 identities, SHA-256
  `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`
- selector 397 is the exact first 397 lines of selector 401.
- ledger SHA-256: `db6ca1c76373a0cc215096989acbd281852d25d6b5e7db703885d7a46cdd858b`
- identity-map SHA-256: `3549a75613747ecfb252873ead59a7a86700b8f609c873c815a8e29e4217967b`

The downloaded result/log ZIP digests matched the GitHub artifact-provider digests above.

## Orchestration provenance before the formal run

Two earlier caller executions are **orchestration-invalid only** and carry no semantic credit:

1. `33890566735`: stopped before runtime with `runtime_started=false` because the packaged source archive was
   extracted with the wrong root handling, so the required selectors were not found.
2. `33891113785`: stopped before runtime with `runtime_started=false` because the harness expected a source
   `test-data` tree instead of materializing the immutable fixture execution view used by the consumer.

No Directional runtime started in either attempt. The final caller corrected only orchestration; semantic source,
package bytes, binaries, tests, fixtures and selectors were unchanged.

## Preflight and execution boundary

The formal run verified the outer artifact digest, recursive package manifest, exact source SHA, Code + Build
boundary, GMP/GMPXX package evidence, all six runtime executable hashes/modes, both selector hashes/counts, exact
397-prefix relation, fail-closed fixture rule, package hardlinks in the execution view, and pre-runtime censuses.

Final execution boundary:

- `script_exit=0`
- `runtime_started=true`
- `runtime_completed=true`
- `preflight_completed=true`
- `execution_view_verified=true`
- `orchestration_failure=false`
- `benchmark_execution=false`
- `configure_execution=false`
- `compile_execution=false`
- `relink_execution=false`
- `generated_discovery=false`
- `package_repair=false`
- `mode_repair=false`
- `source_test_fixture_selector_mutation=false`

The consumer resolved the staged sibling execution view through
`executableDirectory.parent_path()/test-data`; runtime executables were immutable package hardlinks.

## Authoritative 401-row ledger

- total: **401**
- PASS: **389**
- RED: **12**
- accepted prefix 1–365: **365/365 PASS**
- RED ordinals: **366, 367, 368, 369, 370, 374, 384, 385, 389, 390, 393, 398**

Relative to TB23-R1's selector-397 runtime, this turn factually observes: ordinal 397 changed RED → PASS;
ordinals 384, 385, 389 and 390 changed PASS → RED; new ordinal 398 is RED; new ordinals 399, 400 and 401 PASS.
No classification is assigned here.

## CG9 mandatory discriminators

### D1 — accepted prefix

**365/365 PASS.** No accepted-prefix regression is observed.

### D2 — owner-map production totality

Mechanical fixture source-face count is **300**. Ordinal 398 does not publish a `SurfaceCutGraph` value and REDs
at `mechanical feature:NotProductionReady/SourceFaceOwnershipNotEstablished`.

- source-face count: `300`
- published owner-entry count: `unavailable`
- map total: `not established`
- every owner orbit belongs to certificate face set: `unavailable`
- first typed failure: `SourceFaceOwnershipNotEstablished`

### D3 — component-0 owner multiset

The required 191-face multiset is **not measurable in this execution** because ordinal 393 reaches
`mechanical.cutGraph.has_value() == false` and emits `NotProductionReady` before a certified owner map is
available. Factual report:

- component: `0`
- required component-face count: `191`
- observed owner count: `0`
- unavailable owner count: `191`
- distinct owner count: `unavailable`
- sorted distinct owners: `unavailable`
- all-equal: `unavailable`
- representative source faces: `unavailable`

TB24-EXEC does not adjudicate the all-equal versus not-all-equal branch.

### D4 — relocated ordinal-366 guard

Ordinal **366 RED**. The emitted exception is
`NotProductionReady/surface-cut-graph/SourceFaceOwnershipNotEstablished;detailCode=SourceFaceOwnershipNotEstablished;sourceFace=0,1,2;...`.
No component/conflicting-owner relocated-guard diagnostic is emitted in the authoritative raw log.

### D5 — corrected ordinals 393 and 397

- **393 RED**: `mechanical.cutGraph.has_value()` is false; the test reports `NotProductionReady`.
- **397 PASS**: the frozen unrelated-locus regression witness now passes its byte-identical expectation.

The D5 conjunction is therefore **not green**.

### D6 — carried surfaces

- 367: RED
- 368: RED; production witness reports
  `CellularityNotEstablished/origin=RotationSystemInconsistent` with `TraceEventPositionInvalid`.
- 369: RED; `certificate.saturationUsed` is `true` where the identity expects `false`.
- 370: RED; typed error-code expectation mismatches and the required source-face locus is absent.
- 374: RED; `atlasBuild` is false.
- 371: PASS, unchanged from prior PASS authority.
- 372: PASS, unchanged from prior PASS authority.
- 391: PASS, unchanged from prior PASS authority.
- 392: PASS, unchanged from prior PASS authority.

## New selector-401 witnesses

- 398 `SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`: **RED** at
  `mechanical feature:NotProductionReady/SourceFaceOwnershipNotEstablished`.
- 399 `SurfaceCutGraph.CellularityCertificateRejectsOwnerOutsideItsCertifiedFaces`: **PASS**.
- 400 `GlobalTopologyPlan.CertifiedSourceFaceOwnerConsistencyCanRejectConflictingComponentOwners`: **PASS**.
- 401 `TestFixturePaths.MissingPackageFailsClosedInsteadOfReturningMissingPath`: **PASS**.

## Additional selector-397 RED surfaces observed in TB24

Ordinals **384, 385, 389 and 390**, which passed in TB23-R1, are RED in this immutable run. Each mechanical
production identity reaches `mechanical.cutGraph.has_value() == false` and reports `NotProductionReady` before its
later evidence assertion. EXEC records this comparison only; review owns diagnosis and stable-regression
classification.

## Postflight immutability

All three pre/post censuses are equal:

- package: `da259eb2979175613ac55332c55552f7be0802947e40215ce26586e459f17faf`
- packaged source: `e7f988261ba72d2cd942b3d877832022116ab1e508a82d17067d43f7d02ad696`
- execution view: `0adac8132e1b3a1e7c1a08b7cf195cd6c901b3376456a36032b71e483e9439b4`

No package/source/execution-view mutation occurred.

## Runtime environment and resource evidence

Formal runner: Ubuntu 24.04 / Linux x86_64, glibc 2.39, 4 logical CPUs, Intel Xeon 6973P-C, approximately 16.8 GB
RAM. Per-test `/usr/bin/time -v` evidence is retained for all 401 processes. Peak recorded test RSS is **18,652 kB**
(ordinal 147). Longest recorded elapsed time is **17.89 s** (ordinal 137).

## Outcome routing

TB24-EXEC is a **valid semantic RED** gate. CP4c-3 remains **OPEN**. Per the frozen plan, EXEC makes no stable
regression classification and changes no historical accounting: **44 events / 14 categories / 30 recurrences**,
produced-witness debt **5**, semantic M3 package count **89** pending independent review.

**Exact next boundary: `M3-CP4c-3-TB24-REV` — independent REVIEW + PLAN only.** Review must diagnose/classify the
12-RED ledger, including the newly observed 384/385/389/390 surfaces and ordinal 398, adjudicate the unavailable
D3 discriminator, update stable accounting only when justified, perform mandatory REVIEW consolidation plus
`ORIENTATION.md`, and authorize at most one bounded successor. Do not rerun Directional, rebuild/relink/repair the
package, or patch product/tests before that review.

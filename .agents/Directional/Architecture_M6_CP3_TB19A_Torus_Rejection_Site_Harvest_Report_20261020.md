# M6-CP3 TB19A — Torus factory-rejection-site artifact-only harvest (2026-10-20)

**Turn:** `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE`. **Authority:** RA-108.5 amended by RA-109.4; no adjudication. **Disposition:** artifact-only execution succeeds; six torus rejection cases RED, positive fixture-loaded control PASS. TB19-REV is mandatory next.

## Frozen authority and integrity

- Semantic source: `d2c7483cde8e65d6c35c5df06fa880465a4da46c`.
- Compile/package: CB19A artifact `12275794192`; ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`; 28/28 package entries verified; `runtimeExecution=false`, GMP linked, build exit 0.
- Exact executor/harness commit: `9aa2a84d679088cb40ddd75b5da7738fa5c74154`; harness `.agents/Directional/tools/m6_cp3_tb19a_torus_rejection_site_harness.sh` SHA-256 `21480db48fe005896d126bad30054e4711f5597117324ff4039a30c74d05cabc`.
- Dispatch request: `5335c610a41a844970a738ce0829f975487c2fa3`, request `m6-cp3-tb19a-torus-20261020-01`.
- [Workflow run 39484475466](https://github.com/akashskypatel/Directional/actions/runs/39484475466), attempt 1, completed success.
- Result artifact `12292268624`, ZIP SHA-256 `25d48ed757a54ba77b7876ff0d3b833673cd57dab151f1e9632fcfcb7a8efa7c`; expires 2026-11-03T19:34:19Z.
- Exact filters selected once each: 7/7 planned and executed; 0 missing; 6 RED; 1 PASS. Result `SHA256SUMS` verified; source, package, staged view and frozen selectors postflight unchanged; no build, relink, benchmark or selector-497 execution.
- Corrected staged fixture root `view/test-data/benchmarks/fixtures`; `milestone-g/torus.obj` and `torus.rawfield` both prechecked as regular files. No log contains `test-data package not found`.

## Seven-row ledger

Rows 1–6 share the **exact first failure**:

```text
unknown file: Failure | C++ exception with description "torus nonzero-Z4 source witness producer failed: PublishedProductRejected product=0 detail=none site=gauge-pin-consistency;edge=0,3" thrown in the test body.
```

For rows 1–6, the parsed fields are `product=0`, `detail=none`, `site=gauge-pin-consistency;edge=0,3`. Exit 1, selected 1, passed 0. Row 7 exits 0, selected 1, passed 1, without a first failure, product/detail/site fields. The first-failure column below uses **F** for the exact line reproduced above and **—** for no failure.

| # | Identity | GTest | TB18 | TB19A | First failure | product | detail | site | Raw log SHA-256 |
|---:|---|---|---|---|---|---|---|---|---|
| 1 | `cp3entry:1` | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `ea16747f065e70233f3e465efd60ae1d3e2dfca870efa1defc5c9506e7065e06` |
| 2 | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `82aec80432b7a38921cf40601fa0380ed529093657b4cef8982e08efcd71bd45` |
| 3 | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `c48c808dc33d9b690bf0a3a811340960bf47feb6feb130c51438ae10c87b00f5` |
| 4 | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `b72e021926348298382f243cb175658793d0fc4da126bf88cb0f128611234cd4` |
| 5 | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `3ca69e0a3b2c430f37e8b6e1757c3bfd54c33c3f73624a551ced29de4e48a5f1` |
| 6 | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` | RED | RED | F | 0 | none | gauge-pin-consistency;edge=0,3 | `2da1abd38effd0a90648b4d96fd62e828b5371dbb06f51de34c1f6ada52cb377` |
| 7 | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` | PASS | PASS | — | — | — | — | `c646ddf8759f0d4fbb0d9ac5fddfda5025dc6da2ea252729c73896533d1a4b15` |

## Falsifiers (RA-108.5)

- **G1 HELD:** control `selector:443` PASS. This is the positive witness proving torus fixture resolution and a produced torus that clears the pin.
- **G2 HELD:** each of the six first failures has the specified `torus nonzero-Z4 source witness producer failed: PublishedProductRejected` prefix and appended fields.
- **G3 HELD:** all six sites are `gauge-pin-consistency`; none falls at another site.
- **G4 HELD:** every `product=0` has a nonempty site.
- All six `product` codes are zero; RA-106.5 nonzero-code follow-up is not invoked.

## Static hard-rail edge classification (RA-109.4)

At pinned source `tests/SurfaceCellTransitionQuotientTests.cpp:908–927`, `torus_row408_hard_edges` defines 18 unordered source edges in two cycles:

- **Minor:** 0–3–25–37–49–61–0 (six edges).
- **Major:** 0–1–4–6–8–10–12–14–16–18–20–22–0 (12 edges).

Each of the six observed rejection-site edges is the unordered pair **{0,3}**, a member of the **minor** hard-rail cycle and **not** the major cycle. This is a static input-edge membership observation, not an adjudication of H-pin, transport correctness, periodic-cut semantics, or the R-route.

## Scope and handoff

TB19A does not modify source, tests, selectors, fixtures, package, or binaries; no compile or relink occurred and no benchmark ran. The six TB19 invalid torus readings (fixture staging defect) are now measured here. Together, TB19 (16 valid cases) and TB19A (seven cases including control) are the evidence inputs for mandatory `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV`. Stable counts remain 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497 frozen. RP-01 remains open, RP-02 UNREACHED, Gate C suspended. No repair or promotion is authorized by these results.

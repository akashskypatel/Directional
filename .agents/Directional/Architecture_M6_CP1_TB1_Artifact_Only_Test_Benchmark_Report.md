# M6-CP1-TB1 Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP1-TB1-EXEC`
**Disposition:** COMPLETE / MECHANICALLY VALID / SEMANTIC RED / CANDIDATE UNPROMOTED / REVIEW REQUIRED
**Candidate:** artifact/source `10826090221 / ee8b8ac20571df5773f5f94bf9b382161f37a893`
**Authoritative runtime:** run/job `36045055975 / 107786525272`
**Result/log:** `10828084810 / 10827949954`
**Exact successor:** `M6-CP1-TB1-REV`

## 1. Boundary and immutable preflight

TB1 consumed the CB1 package immutably. The downloaded candidate ZIP re-hashed to `6e3c3b09d272e200f3c213aa5198ed805bff2f293f35b37a55b948176c870a9c`; its root `SHA256SUMS` verified **28/28**, the packaged source archive is exact semantic source `ee8b8ac20571df5773f5f94bf9b382161f37a893`, GMP/GMPXX evidence is present, and the package records `runtimeExecution=false` for its Code + Build origin. Extraction preserved archived executable mode bits; no `chmod`, repair, configure, compile, relink, generated discovery, source/test/fixture/selector mutation, or package mutation occurred.

Selector449 is exactly **449 LF rows** at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 is SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707` with owner census **32 / 301 / 75 / 41**. The six frozen focused identities resolve to packaged targets before runtime.

## 2. Mechanical execution

The frozen harness executed exactly **455 fresh exact-filter processes**: six focused identities followed by all 449 accepted selector identities. Every process selected exactly one test and skipped zero. There were **0 crashes, 0 selection mismatches, 0 skips, 0 benchmark processes**, and no timeout/watchdog was used for the acceptance gate.

Mechanical totals:

| phase | total | PASS | RED |
|---|---:|---:|---:|
| focused | 6 | 3 | 3 |
| accepted selector449 | 449 | 437 | 12 |
| **total** | **455** | **440** | **15** |

The focused PASS identities are `M6CP1.SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell`, `M6CP1.SourceFaceRowPermutationPreservesOccurrenceIdentity`, and `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints`.

Focused RED identities are:

1. `M6CP1.CoincidentUnrelatedOccurrencesRemainDistinct`
2. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`
3. `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`

The accepted selector449 RED ordinals are **115, 116, 139, 140, 141, 143, 186, 225, 239, 444, 446, 448**. All twelve were PASS in the accepted M5 selector449 authority. Selector row449 itself remains PASS.

## 3. Common semantic failure surface

All twelve accepted-selector REDs and focused rows 5/6 stop at the new A5 boundary with `OccurrenceInvalidCornerAuthority`; focused row2 directly receives a non-product `SurfaceOccurrenceComplexProducer::produce(...)` result before its distinctness assertions. No prior accepted assertion becomes the first failure: the candidate stops earlier while constructing/consuming `SurfaceOccurrenceComplex`.

Static localization bounds the new failure to `SurfaceOccurrenceComplexProducer::produce`'s corner-authority validation. That producer consumes the stored trace/projection face as region/component/sheet authority before publishing the occurrence. The existing `SurfacePointSourceSupportResolver` contract explicitly states that `SurfacePoint::face` is a **projection chart** and that an edge- or vertex-supported point may validly use any incident source face; canonical support is the intrinsic authority. This creates an `RP-01 / AUTHORITY_DOMAIN_CONFLATION` failure shape at the new A5 seam: projection-chart representation is being consumed as occurrence ownership authority. The immutable runtime does not distinguish which `InvalidCornerAuthority` sub-predicate fired, so Review must independently confirm the exact sub-predicate and correction boundary; EXEC authorizes no repair or diagnostic rerun.

Under the durable accepted-prefix criterion, the twelve selector PASS -> RED transitions are one newly observed stable event because they share this single newly inserted A5 failure surface. They are not priced as twelve independent events. Stable accounting therefore advances **51 -> 52 events / 14 categories / 37 -> 38 recurrences**. The three focused REDs support localization but do not add separate accepted-prefix events. Project produced-witness debt remains **1**, M6-owned.

## 4. Evidence integrity

Result artifact `10828084810` has provider/download SHA-256 `796dc825a3d2de765d9618d78663611481077227d8d86b0ab2e78fcd76e1d7bd`; its self-excluding `SHA256SUMS` verifies **933/933** files and hashes to `4a802dba3ea24193aad5f527bf2840ef4c9afa3a408c07b5cb00787b1b34d366`. Execution ledger SHA-256 is `fbbb6bd6a28c57b0aa9b9f31831385c9576c1efef255533e45fd63e48cb5c98e`; RED ledger SHA-256 is `09fb3929716b457037c30b012b27a40ea45ef071e40de5c802009e9934ecfe32`.

Diagnostic log artifact `10827949954` has provider/download SHA-256 `144a5832801b3e175dcee7ef1a9c35dce64665bffb6806aa2937d7ac1ce6cbc3`. Its persistent log ends with the frozen completion marker and records no orchestration failure.

Postflight proves package/source/execution-view censuses unchanged, selector/routing/source archive unchanged, pre/post hash inventories equal, and root manifest still **28/28**. `execution-boundary.txt` records `orchestration_failure=false`, `selection_integrity=true`, all 455 planned processes executed, and every prohibited mutation/build/benchmark counter false.

## 5. Stop rule and disposition

The semantic RED is preserved exactly. TB1 performed no retry, rebuild, semantic correction, selector publication, candidate promotion, A5 acceptance, CP1 closure, or G4/debt credit. Accepted runtime authority remains M5 package/source `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7` under selector449 **449/449 PASS**.

`M6-CP1-TB1-REV` must independently re-open the immutable package/result/log evidence, adjudicate the one new stable `RP-01` event and exact `InvalidCornerAuthority` sub-predicate, and either freeze a bounded corrective successor or reject the candidate. No Code + Build correction is authorized before that Review.

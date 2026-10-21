# TB22 — Immutable torus witness-scope harvest plan (RA-116)

**Turn:** `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST`, Test + Benchmark, artifact-only. **Owner:** TB22; reviewed/issued by CB21-REV. **Source:** `8453e19e6ac7d976a9cac45978ad31104a52f034`; **package:** GitHub artifact `12318897957`, ZIP SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`, expires `2026-10-28T03:54:02Z`. Verify 28/28 root package hashes, exact source archive and source/status receipts before execution and unchanged bytes after. Preserve `runtimeExecution` split (CB21 was false; TB22 alone executes tests). Use the durable `test_benchmark` dispatcher and an artifact-only harness with exact frozen hash; no binary regeneration, configuration, relinking, test edits, fixture edits, selector mutation or broader census. Every selected filter must match exactly one test and execute in an independent process; zero skips.

## Exactly eleven rows

| Class | Key | Exact test name |
|---|---|---|
| torus | `cp3entry:1` | `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` |
| torus | `focused30:6` | `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` |
| torus | `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` |
| torus | `focused30:20` | `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership` |
| torus | `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` |
| torus | `selector:446` | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` |
| torus | `selector:447` | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` |
| M2 control | `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` |
| control | `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` |
| control | `TB18 A#14` | `SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorVertexEndpointRejectsForgedTags` |
| control | `selector:443` | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` |

The seven torus rows are the seven consumers of the shared nonzero-Z4 torus fixture, including the D2 row, NOT a new 497-run selector gate. Preserve the accepted 491/491 and frozen 497 selector bytes and the 66/17/49 ledger.

## Predictions (frozen before runtime)

- P1: fixture selection succeeds on genuine reciprocal/holonomy authority and the five CP2-GREEN rows `focused30:6`, `focused30:20`, `focused30:24`, `selector:446`, `selector:447` reach and pass their own assertions. Record selected index and seven counters; `selected=none` or fixture exception invalidates this prediction, even if a process exits successfully.
- P2: `cp3entry:1` reaches **its own D2 odd-gauge assertion** (not earlier fixture failure); predicted RED with `oddFaceGaugePairs=0` and the complete `receipt` visible. If a valid odd witness is actually produced and it passes, report that observation, not the prediction.
- P3: `focused30:12` retains its independently owned A5/factory failure; classify its exact first site, do not count it as a repaired torus row.
- P4: `cp3entry:6` and all three existing controls PASS with unchanged semantics; any regression is a Review stop.

**Decisive falsifier:** if the fixture throws and `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0`, D2 is NOT the established earlier blocker; report the actual `firstPredicate` and route to TB22-REV for periodic source/transport publication, rather than invent a D2 witness or promote the fixture correction. An unexpected out-of-range gauge, failing source/A3 match, post-selection transition mismatch, zero selected test, skip, package/source mismatch, runtime mutation flag, timeout or orchestration error is likewise non-acceptance and requires precise classification. No blanket retry or unrelated repair in TB22.

**After TB22:** always independent `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV` (the next TB22 Review turn, not executable in the same turn). DEFN-T1 and M1 remain conditional on that Review; do not auto-advance.

# M5-CP1-TB1-R2 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP1-TB1-R2-EXEC`
**Turn closeout:** **COMPLETE**
**Gate disposition:** **ORCHESTRATION VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED**
**Candidate:** artifact `10595705100`, semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Accepted runtime authority remains:** M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**
**Exact successor:** `M5-CP1-TB1-R2-REV`

## 1. Outcome

R2 executed the complete frozen artifact-only gate from ordinal 1 with valid orchestration and exact immutable postflight. Workflow run `35491016562` passed schema validation and runtime job `106025849497` completed successfully. The harness executed all **9** focused rows and all **430** selector rows in fresh exact-filter processes with exact-one selection and zero skips; benchmark count remained **0**.

Semantic result: **focused 8/9 PASS / 1 RED**, selector430 **430/430 PASS**. The sole RED is focused ordinal 6, `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`. Its raw receipt fails at `SurfaceCellTransitionQuotientTests.cpp:1449` before the permutation or materialization assertions:

```text
Expected: (reorderedDraft.periodicHolonomies.size()) >= (2U), actual: 1 vs 2
```

The failing assertion is a witness precondition. Candidate source builds `reorderedDraft` from `direct_full_periodic_materializer_draft()`, whose cylinder-backed helper transforms one existing periodic relation and does not add a second relation. The runtime therefore reaches exactly one relation and aborts before `std::reverse(...)`, before either materialization call, and before the selected-certificate comparison. EXEC records this as test-authority evidence and does not infer or patch a product defect.

Candidate `10595705100` remains unpromoted. Per turn cadence, semantic RED routes directly to independent Review + Plan; no R2 retry or corrective Code + Build is authorized before Review.

## 2. Runtime and artifact authority

- workflow run: `35491016562`, event SHA `c9b17632381aab2706ea4c39ec0a7d9660416ed3`;
- schema job `106025833482`: **success**;
- runtime job `106025849497`: **success**;
- result artifact `10598684066`, provider ZIP SHA-256 `5896fee5600a6f842fcefd08534d2a21a67cedee8a38ed67daaeace755d2a5dd`;
- diagnostic artifact `10599222908`, provider ZIP SHA-256 `cabfa52286f006572181c8a0368562b1ec31591061431be7b6fe2055951ac016`;
- canonical harness SHA-256 `b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`;
- focused ledger SHA-256 `07646ddbb8bb4d7e4900981901a846576a0e943a8388a74060f128e2117ad645`;
- selector ledger SHA-256 `e571138329ce808a9bab9544640548bcb73def54b93475918a24833f3968d6c0`.

The candidate and routing downloads independently match their frozen provider/download hashes. Candidate root manifest verifies **28/28** before and after runtime. Selector430 is exactly **430 LF rows** at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, with accepted first427 prefix `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Routing authority remains **430 unique identities**, owners **31 / 283 / 75 / 41**, map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`.

## 3. Focused gate

| Ordinal | Identity | Result |
|---:|---|---|
| 1 | `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator` | PASS |
| 2 | `SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation` | PASS |
| 3 | `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained` | PASS |
| 4 | `SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed` | PASS |
| 5 | `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap` | PASS |
| 6 | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation` | **RED** |
| 7 | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate` | PASS |
| 8 | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation` | PASS |
| 9 | `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` | PASS |

Ordinal 6 selected exactly one test, skipped zero, exited 1, and has raw-log SHA-256 `68ef89b40caab7818f4aedc3ce2078dbde564eae713257ef56fac28666bfb586`. Ordinal 9 remains a `direct_periodic_owner_product()` witness and is therefore **CP1 mechanism-only / no produced-witness credit**.

## 4. Accepted predecessor gate and static audit

Selector430 executed **430/430 PASS**, exact-one selection, zero skips, with no selector substitution. The accepted M4 regression surface therefore remains green on the unchanged CP1 candidate.

Static CP1 audit remains clean:

```text
production_PeriodicRelationId_from_index=0
production_periodicRelationOffset=0
production_reachableHardRailComponents=0
production_hardRailAdjacency=0
SelectedRelationPathCertificate=present
row9_direct_helper_discriminator=present
```

This static evidence does not substitute for the failed ordinal-6 behavior or for any produced-witness debt.

## 5. Postflight and boundary proof

R2 completed immutable postflight successfully:

- package byte+mode census equal before/after;
- packaged-source byte+mode census equal before/after;
- execution-view byte+mode census equal before/after;
- selector unchanged;
- routing map unchanged;
- candidate manifest **28/28** after execution;
- configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector mutation all **false**;
- benchmark execution **false**.

The run is therefore mechanically complete and semantically trustworthy; the RED is not an orchestration artifact.

## 6. Regression classification and accounting

`M5-CP1-TB1-R2-EXEC-CAND-01` is **OPEN / `RP-02 TEST_AUTHORITY_COVERAGE_GAP` / INVALID WITNESS PRECONDITION / NON-STABLE**, owner `M5-CP1-TB1-R2-REV`.

The observed failure does not demonstrate loss of an accepted product behavior: the test aborts before the relation-container permutation or certificate comparison it claims to validate, while accepted selector430 remains **430/430**. Therefore this turn adds **+0 stable event / +0 category / +0 recurrence**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. Candidate `10595705100` is not promoted and accepted M4 runtime authority remains unchanged.

## 7. Exact next

`M5-CP1-TB1-R2-REV` is mandatory and runtime-free. Review must independently reopen the R2 result artifact, ordinal-6 raw receipt, candidate source and frozen CP1 definitions; determine whether a valid relation-container permutation witness exists and whether corrective authority is test-only or semantic; and issue the exact next plan. Review must not import R1 semantic credit, weaken the CP1 certificate invariant, or grant any M5 production-debt credit from direct/helper evidence.

# M5-CP1-TB1-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP1-TB1-R1-EXEC`
**Turn closeout:** **COMPLETE**
**Gate disposition:** **BLOCKED / PRE-RUNTIME ORCHESTRATION EXECUTOR CORRUPTION / ZERO SEMANTIC CREDIT**
**Candidate:** artifact `10595705100`, semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Accepted runtime authority remains:** M4 package `10591801825` / source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**
**Exact successor:** `M5-CP1-CB2`

## 1. Outcome

The corrected R1 execution did **not** execute a Directional binary. Terminal run `35486023017` passed workflow-schema validation, then failed inside the temporary executor before the artifact-only harness existed: decoding the embedded Base64/GZip payload emitted both `gzip: stdin: invalid compressed data--crc error` and `gzip: stdin: invalid compressed data--length error`. The gate exited before the harness SHA check, artifact download, focused gate, selector gate, or postflight.

Runtime counters are **focused 0/9, selector430 0/430, benchmark 0**. `gate_harness_exit` remained empty. The expected result directory was never created, so no result artifact exists. No configure, compile, relink, discovery, package repair, source/test/fixture/selector mutation, or fallback package occurred. Candidate `10595705100` remains unchanged and unpromoted.

## 2. Terminal orchestration evidence

- workflow run: `35486023017`;
- event SHA: `4d96ee94623995514baac0d608a038040dbfa787`;
- validation job `106012437882`: **success**;
- runtime job `106012455346`: **failure before Directional runtime**;
- diagnostic artifact `10597540714` (`directional-m5-cp1-tb1-r1-log-35486023017`), provider SHA-256 `818b69adc1f3e459a2d97bfe7e31335efeeb5600c42f432da279b897d05cd019`;
- result artifact: **none**;
- Directional runtime: **0 processes**.

Earlier runs `35485744292` and `35485883001` remain no-credit control-plane attempts already recorded by the handoff. They contribute no semantic evidence. The terminal attempt closes this execution turn as an orchestration block; another in-place R1 retry is not authorized.

## 3. Immutable authority preserved

Candidate authority remains artifact `10595705100`, source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`, ZIP SHA-256 `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`, root manifest SHA-256 `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d` (**28/28** by predecessor authority), source archive SHA-256 `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`, selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and selector427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Accepted M4 routing authority remains artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, with `identity-map.tsv` SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, header + **430** rows / **430** unique identities, owners **31 / 283 / 75 / 41**.

## 4. Frozen semantic gate carried forward

The focused identities remain exactly these nine, in order:

1. `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
2. `SurfaceCellsPhase10.PeriodicHolonomyDistinctTopologyRegionsRetainEveryRelation`
3. `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained`
4. `SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed`
5. `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap`
6. `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation`
7. `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate`
8. `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation`
9. `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`

Selector430 remains mandatory after the focused gate, one fresh exact-filter process per row; benchmark count remains **0**. Row 9 uses `direct_periodic_owner_product()` and therefore remains **CP1 mechanism-only / no produced-witness credit**. Accepted selector rows 218, 220, 221, and 226 likewise remain regression evidence rather than M5 debt discharge.

## 5. Classification and accounting

`M5-CP1-TB1-R1-EXEC-OBS-01` closes **ORCHESTRATION / EXECUTOR-PAYLOAD AUTHORING / NON-STABLE**. No candidate or accepted test identity executed, so this is not a product regression. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. Accepted runtime authority remains M4 package `10591801825` / selector430 **430/430**.

## 6. Exact next

`M5-CP1-CB2` is a **runtime-free, control-plane-only orchestration correction**. It must reuse candidate `10595705100` and routing artifact `10592987234` unchanged and prove before any fresh runtime that the canonical harness round-trips exactly, the decoded SHA matches its frozen expectation, `bash -n` succeeds, every referenced artifact path exists, all digest literals are valid 64-character lowercase hexadecimal values, and workflow schema/permission checks pass. It may not run a Directional binary or change product/test/fixture/selector/package semantics.

On static green, CB2 may issue fresh `M5-CP1-TB1-R2-EXEC` with the same nine focused identities, selector430, immutable postflight, zero benchmarks, and credit boundary. CB2 must not execute R2 itself.

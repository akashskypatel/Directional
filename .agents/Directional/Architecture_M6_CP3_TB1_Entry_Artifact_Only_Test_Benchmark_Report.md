# Architecture M6 CP3 TB1 Entry Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP3-TB1-ENTRY-EXEC`
**Mechanical execution:** COMPLETE
**Semantic result:** RED — mandatory Review required
**Successor:** `M6-CP3-TB1-ENTRY-REV`

## Closeout and retired-document resolver

Durable RED evidence was committed as `145f7af552483ead00a6605e0ec793cb9f4af595`. Turn cleanup run `37470228257` committed cleanup SHA `4eae760859ed48a7898d9383e583681111fe9023`, removed the runtime/closeout markers, source-snapshot marker, and artifact-only harness, and preserved workflow mailbox history and Actions artifacts. The staged Drive closeout patch required owner retirement and was permanently deleted through the user-authorized Drive connector.

The superseded predecessor files `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`, `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Report.md`, and `Architecture_M6_CP3_TB1_Entry_Exec_WIP_Handoff.md` were retired only after their durable facts were preserved here, in the handoff/TODO/CHANGELOG, and in the regression tracker. Historical references to those filenames in retained records resolve to git commit `4eae760859ed48a7898d9383e583681111fe9023`, where all three remain recoverable. Mandatory `M6-CP3-TB1-ENTRY-REV` must add their names to the appropriate folded-document index per `CLEAN_UP_POLICY.md`.

## Immutable authority

- Candidate compile artifact: `11411137781`
- Candidate semantic source: `912760f1ffc785676f5d50717177b1cd8be69234`
- Candidate ZIP SHA-256: `704b1b70c9fd67aca95c78757c84433b97122fad6524f14326312131d3307234`
- Candidate root `SHA256SUMS`: `f1e0fefb72df8f8e4175cda5d0cd1f05ab8fc94b29d8250a960e6de3d6f8b153`
- Packaged source archive SHA-256: `bf0f21a8899cc5a078a9c02761d18836be728df403b7d200226d7f39b4620e67`
- Frozen focused30/focused12/selector449/routing449 SHA-256: `1e815443...1d6`, `2aa57aac...74ed`, `d4a0d1b7...6414`, `9c88a5ed...5707`.

Authoritative runtime is run/job `37464309062 / 112271440079`. Result/log artifacts are `11413899043 / 11413964659`, provider SHA-256 `61dab4f603dab94fa12b4317fbd4c5cbf9c0ba3d535f2c4ee900cab5c98fd243 / d26bb31810049edc79d480c27f6fefbca56066e18a9c7e891416bccae5b2eeba`.

## Execution boundary and result

The gate executed exactly **497 fresh exact-filter processes** with exact-one selection and zero skips:

- focused30: **4 PASS / 26 RED**
- focused12: **0 PASS / 12 RED**
- selector449: **369 PASS / 80 RED**
- six CP3-entry identities: **0 PASS / 6 RED**
- aggregate: **373 PASS / 124 RED**
- benchmark executions: **0**

The result artifact self-manifest verifies **1019/1019** non-manifest files. Candidate package manifest remained **28/28** before and after runtime. Package, packaged-source and execution-view byte/mode censuses are identical pre/post; all four frozen gate hashes are unchanged. The harness reports no configure, compile, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation or runtime retry.

A successful workflow conclusion means the harness completed and evidence was packaged; it does **not** mean the semantic gate was green. The 124 RED rows are authoritative test evidence.

## Regression classification

All **124/124** RED rows are categorized in `Architecture_M6_CP3_TB1_Entry_Red_Classification.tsv` with immutable raw-log SHA-256. EXEC does not promote any candidate to stable accounting; mandatory Review owns adjudication.

| Candidate | Rows | EXEC evidence / root-cause analysis |
|---|---:|---|
| `M6-CP3-TB1-ENTRY-EXEC-CAND-01` | 73 | **A4 face-gauge publication gap.** These rows explicitly report `InvalidFrontBoundaryAuthority`. Static source comparison shows multi-region `build_uniform_phase_front_state` now requires every successful regional result to publish a full `faceBranchRotation` vector, while the planar-uniform and periodic-annulus regional producers do not publish it; only the curved bounded-disk path does. Their successful output therefore fails the new merge check before downstream stages. This is a production implementation defect candidate introduced by CB1. |
| `...-CAND-02` | 5 | **A6/D7 isolation-side evidence overreach.** Five produced-torus rows explicitly reject with `MissingIsolationSeamEquivalenceAuthority:a6-side-evidence`. CB1 strengthened cross-sheet relation evidence requirements; Review must determine whether the new requirement exceeds RA-30/30a or exposes missing producer evidence. |
| `...-CAND-03` | 42 | **Downstream reachability / variant mismatch, not safely localized in EXEC.** Six rows throw `std::get: wrong index for variant`; the remainder fail later-stage non-vacuity/expected-product assertions without an explicit stable diagnostic. They are classified, but EXEC evidence does not justify assigning them to CAND-01/02/05 or creating stable root-cause IDs. Review must trace these rows against the candidate source and determine which are downstream recurrences versus distinct defects. |
| `...-CAND-04` | 1 | **D1 test-authority witness non-vacuity failure.** The frozen exact-A3 test fails its first witness assertion because the selected reciprocal pair does not have the required 90°/270° endpoint face-gauge delta. RA-30a explicitly defined absence of that property at TB as test-authority RED for Review, not automatically a product defect. |
| `...-CAND-05` | 2 | **D2 HardRail baseline rejection before intended branch assertions.** Both new HardRail identities reach a non-product A5 variant and therefore cannot exercise the intended certificate/global-sheet assertions. EXEC does not expose the exact A5 error family; Review must localize whether the new branch certificate rejects a valid produced baseline or the fixture fails a prerequisite. |
| `...-CAND-06` | 1 | **D4 typed-barrier semantic/witness mismatch.** The produced periodic-carried typed hard-feature witness does not split the asserted chart components, and removing the feature does not change the expected component signature; its later square subcase also reaches `InvalidFrontBoundaryAuthority`. The first failures are the D4 non-vacuity/semantic assertions, so this row is kept separate from CAND-01 for Review. |

The classification is deliberately conservative. No EXEC-only inference changes the stable ledger. **Stable accounting remains 60 events / 16 categories / 44 recurrences, debt 1** pending `M6-CP3-TB1-ENTRY-REV`.

## Six CP3-entry identities

1. `M6CP3.PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority` — RED at the required 90°/270° gauge-delta witness.
2. `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` — RED because A5 is not a product.
3. `M6CP3.OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition` — RED with `InvalidFrontBoundaryAuthority` from the split-isolation square producer.
4. `M6CP3.A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds` — RED on typed-barrier component/signature assertions, then `InvalidFrontBoundaryAuthority` in the square subcase.
5. `M6CP3.ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition` — RED with `InvalidFrontBoundaryAuthority` from the split-isolation square producer.
6. `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` — RED because A5 is not a product.

## Disposition

Execution is complete and immutable evidence is preserved. The candidate is **not promoted**. Exact successor is mandatory `M6-CP3-TB1-ENTRY-REV`, which must independently adjudicate all six candidate groups and the 124-row mapping before any CB2 work.

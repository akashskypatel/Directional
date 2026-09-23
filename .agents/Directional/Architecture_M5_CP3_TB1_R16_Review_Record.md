# M5-CP3-TB1-R16 Independent Review Record

**Turn:** `M5-CP3-TB1-R16-REV`
**Date:** 2026-09-23 UTC
**Boundary:** runtime-free independent Review
**Reviewed execution:** `M5-CP3-TB1-R16-EXEC`
**Verdict:** **APPROVED / CANDIDATE PROMOTED / ALL M5 PRODUCED DEBTS DISCHARGED / SELECTOR448 PRECOMMITTED / M5 STILL OPEN**

## 1. Independent evidence re-opened

Review does not inherit the EXEC disposition. It independently re-opened the immutable R16 result/log bytes, the CB19 candidate package/source, the current selector/routing authority and the exact source implementing the corrected rows16/17.

- candidate artifact/source: `10763242885 / a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1`;
- candidate provider/download ZIP SHA-256: `abe4c381511d3b4025f22612978388bb554bd686b86b6f9dc406538998e990aa`;
- candidate root manifest: **28/28**, `SHA256SUMS` SHA-256 `cda95dd99d7c201fb4fc1f5021f24c6e720e82dc737a89418245e687bf010c25`;
- packaged source archive SHA-256: `54962d495891b35dd800fbede63ddc7d622c28091b42a0faeb8e8b3597726d91`;
- R16 run/job: `35889831381 / 107279255523`;
- result/log artifacts: `10765221644 / 10764573644`;
- independently re-hashed result/log ZIP SHA-256: `d2ec2703f2255cdfa7797da3989aab20e6d10d7203e006ba4068892df1909f46 / 3b8d16d1dbed5ee96e7990f6482d7961f454be1410e35097ba08c931d3097103`;
- result evidence: **921 actual non-manifest files / 921 manifest rows / 921 successful checksum verifications**; `SHA256SUMS` SHA-256 `c2f898912e19fb57061b50945a58e79af74e244c145de9c5d6ef367ee3185784`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, exact first427 prefix SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, owner census **31 / 283 / 75 / 41**.

The execution boundary independently confirms `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`, `selection_integrity=true`, exactly **18 + 430 = 448** generated processes and benchmark count **0**. Configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start are all false. Package/source/execution-view censuses are unchanged after runtime and the candidate root manifest remains 28/28.

The complete fresh ledger is therefore upheld:

| phase | PASS | RED | total |
|---|---:|---:|---:|
| mechanism / semantic | 11 | 0 | 11 |
| focused atlas | 1 | 0 | 1 |
| produced CP3 | 6 | 0 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **448** | **0** | **448** |

Every row selected exactly one GTest with zero skips. Protected selector ordinals **191, 192, 247 and 408 PASS**. Nonselector ledger SHA-256 is `5716a0b6b8512ba07dc575219bf59538c43cb4227fcf6e136629bf7976168987`; selector ledger SHA-256 is `9b2f4e1d2e2578c84ce9e05fa43759fc6a554eeea9e69a65032b2d3cdfc8fd25`.

## 2. Rows16/17 are now non-vacuous product evidence

The CB19 correction did not replace an independent oracle with production output. `make_nonzero_z4_torus_witness_fixture()` still selects the committed source/A3 witness before relation comparison. The expected quarter-turn is independently fixed at **`Q=3`**: source transition authority and the atlas cross-check agree before any stored relation is interpreted. Frozen §16.3 derives the same value from semantic Forward face 22, Reverse face 1, directed carrier action `A=3` and cancelling occurrence gauges `G_F=G_R=0`.

Canonical storage is representation-only. Production may store the inverse action while reversing both routes; `resolve_periodic_relation_semantic_action(...)` restores the exact A3 Forward -> Reverse action from the stored cut-route orientation. The committed candidate actually exercises that branch. Both corrected tests require `storageInverted=true`, require stored action to differ from semantic action and stored generator route to differ from the semantic generator route, and then compare the resolved semantic values against the independent witness. Thus a green result cannot be explained by the correction becoming a self-authorizing resolver check.

### 2.1 Row16 — nonzero rotation + translation reaches materialization and consumption

`M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` is exact-one / zero-skip / exit0 / PASS; raw SHA-256 is `c59eea07dfbee79d58ace0031701f7d454fd35b3541608ecd4b7af705b0ece7d`.

Static source inspection proves the test executes, in order, all of the discriminators that R15-R1 could not reach: independent source/atlas `Q=3`; exact Forward/Reverse A3 edge binding; inverted-storage proof; resolved semantic generator route equality to the independent witness; nonzero semantic rotation and translation; all four endpoint-state expectations; both Forward -> Reverse lattice/action equations and branch equations; successful production materialization; non-empty selected relation certificates; a selected certificate naming the relation under stored action or its exact inverse; and `consumedPeriodicHolonomies > 0`.

Because the complete R16 process PASSes, all of those assertions execute successfully. This is direct production evidence for frozen §8.2 debt 3.

### 2.2 Row17 — one transform mutation reaches exact typed rejection

`M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` is exact-one / zero-skip / exit0 / PASS; raw SHA-256 is `a22dd174cd788521a3845b3b1697805829e0db394a354fa3093367c975685655`.

The test establishes the same independent `Q=3`, exact A3 pair and inverted-storage non-vacuity first. It then clones the produced product, changes **only** the stored relation action rotation by one quarter-turn, asserts that the action changed while source region, generator route, cut route and canonical relation ID remain unchanged, and submits the result to the checked factory. The expected and observed exact typed failure is `NonReciprocalPeriodicRelation`. This is direct production evidence for frozen §8.2 debt 4.

## 3. Gauge-model validation remains correctly separated

The committed CP3 witness has `G_F=G_R=0`; its green produced rows therefore do **not** independently validate that both occurrence-gauge terms in `Q = G_R^-1 A G_F` matter. That obligation stays at the mechanism identity `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges`, which is PASS in the same complete R16 ledger and uses the discriminating synthetic case `A=1, G_F=2, G_R=1 -> Q=2 != A`, with negative checks excluding either one-sided formula.

This separation preserves the DEFN-R1 review guard: produced CP3 validates direct production/materialization/tamper behavior; the dedicated mechanism row validates the gauge correction itself.

## 4. Debt, observation and candidate adjudication

### 4.1 M5 produced debts

Frozen §8.2 has four M5 debts. R7 already discharged relation/container-order ownership and missing-owner typing. R16 independently supplies the two remaining direct-production proofs:

1. **nonzero-Z4 rotation + translation through materialization/lineage/quotient — DISCHARGED by row16**;
2. **same direct-production subject with nonzero-Z4 transform tamper and typed rejection — DISCHARGED by row17**.

All four M5 produced-witness debts are now discharged. Project-wide produced-witness debt moves **3 -> 1**; the sole remaining debt is the previously re-homed M6 closed-complex `G4-B002` subject. Stable history does not decrement: it remains **51 events / 14 categories / 37 recurrences**.

### 4.2 `M5-CP3-TB1-R6-REV-OBS-01` — DISCHARGED

The original direction observation required both an independently authored produced action expectation and a discriminating inverse. R16 now supplies both in the same produced relation. Exact A3 roles select semantic Forward -> Reverse; source/A3 authority fixes `Q=3` independently; the actual canonical stored representative is deliberately inverted and therefore carries the concrete inverse quarter-turn `1`. The test requires stored action != semantic action and the stored route orientation to differ, then requires resolved semantic action == independent `Q=3`.

The inverse is therefore not merely an unchosen alternative. It physically exists in the accepted produced object and fails the independent semantic comparator: treating the stored/inverse representative as Forward -> Reverse yields `Q=1`, not independently required `Q=3`. The prior zero-Z4 ambiguity is gone. Observation closed.

### 4.3 `M5-CP2-TB1-REV-OBS-01` — DISCHARGED BY PRECOMMITMENT

The publication precondition was a complete corrected green CP3 gate plus independent Review. R16 is 448/448 with complete 921/921 immutable evidence, and this Review independently accepts the mechanism/produced/selector authority. Section 5 therefore precommits the exact cumulative successor selector bytes. Publication itself still belongs to separate `M5-CP3-CB20`; this Review does not write or accept selector448 as a published selector.

### 4.4 `M5-CP3-TB1-R15-R1-REV-OBS-01` — DISCHARGED

CB19 preserved the independent source/A3 `Q=3` expectation and explicit inverse-storage proof; R16 now proves rows16/17 reach and pass their final runtime discriminators. The source/compile-only satisfaction recorded by CB19 is therefore promoted to complete runtime proof.

### 4.5 `M5-DEFN-REV-OBS-01` — CARRIED TO FINAL M5 REVIEW

The observation requires the final closure Review to state the reconciled M5 exit theorem and confirm all four debts. This Review confirms the debt portion but M5 is not yet eligible to close because the precommitted cumulative selector has not been published, executed as the published selector, and independently reviewed. Carry unchanged to `M5-CP3-TB2-REV`.

### 4.6 Candidate promotion

CB19 candidate package/source **`10763242885 / a8b33cb7145d5a99d47eaf5f70bb12f1c71238d1` is PROMOTED** as current accepted M5 runtime authority under the still-published selector430. Promotion rests on compile/package authority plus the complete independent R16 pre-publication gate, not on selector448 publication. Selector430 remains the accepted published selector until CB20 and the later published-selector gate/review complete.

`M5-CP3-TB1-R15-R1-CAND-01` is **RECOVERY PROVED / CLOSED / NON-STABLE / +0**. The CB19 test-authority correction removes exactly the stale representation assumption and the corrected rows pass without weakening their product falsifiers. No new stable event or recurrence is created.

## 5. Exact selector448 precommit

Frozen §13.3 requires a green independent pre-publication Review to precommit exact successor-selector bytes/order/hash/owner census before a separate publication Code + Build. This Review does so now.

Selector448 is **exact selector430 bytes as rows 1-430**, followed by the full fixed R16 nonselector vector in its pre-runtime order as rows 431-448. The 18 appended identities were all committed before R16 execution and all are reviewed M5 mechanism/production authority; none is selected after observing runtime. The nine frozen §13.2 identities, the two later load-bearing mechanism/recovery identities, the independent hard-feature atlas authority identity and all six produced CP3 identities remain non-superseded.

| ordinal | appended exact identity |
|---:|---|
| 431 | `M5CP3.PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges` |
| 432 | `M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` |
| 433 | `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator` |
| 434 | `SurfaceCellsPhase10.PeriodicHolonomySameRegionTopologyDistinctRelationsAreRetained` |
| 435 | `M5CP1.ComponentAggregationPreservesCanonicalPeriodicRelationIdWithoutOffsetRemap` |
| 436 | `M5CP1.SelectedRelationPathCertificateSurvivesRelationContainerPermutation` |
| 437 | `M5CP1.UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate` |
| 438 | `M5CP1.AlteredSelectedRelationTransformFailsCertificateValidation` |
| 439 | `SurfacePhaseFrontProductFactoryAuthority.ConflictingPeriodicRelationValueRejectsAtCheckedFactory` |
| 440 | `SurfacePhaseFrontProductFactoryAuthority.NonReciprocalPeriodicRelationRejectsAtCheckedFactory` |
| 441 | `SurfacePhaseFrontProductFactoryAuthority.RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory` |
| 442 | `FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency` |
| 443 | `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges` |
| 444 | `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate` |
| 445 | `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped` |
| 446 | `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` |
| 447 | `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` |
| 448 | `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` |

Precommit invariants:

- rows: **448**, unique identities: **448**;
- bytes: **36,382**, LF count: **448**, terminal LF present;
- selector448 SHA-256: **`70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`**;
- first 430 rows are byte-identical to accepted selector430: **35,001 bytes**, SHA-256 **`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`**;
- appended rows have no duplicate in selector430 and no duplicate among themselves;
- owner census: **32 authority-kernel / 300 producer / 75 completion / 41 validation = 448**.

The precommitted publication path is `.agents/Directional/Architecture_M5_CP3_CB20_Required_Green_Selector_448.txt`. CB20 may write only those exact bytes at that path; any byte/order/hash/prefix/census mismatch fails the turn rather than being normalized or regenerated.

The durable selector manifest is **not** updated in this Review because selector448 is not yet published or accepted. Current accepted selector authority remains selector430.

## 6. M5 exit theorem and why M5 remains open

Frozen §13.1's semantic/mechanism/debt requirements are now satisfied on the pre-publication candidate, but §13.3 is part of the milestone exit contract. The remaining sequence is mechanical and intentionally separate:

1. `M5-CP3-CB20` publishes exactly the precommitted selector448 and compile/packages all standard targets with mandatory GMP/GMPXX; no runtime;
2. `M5-CP3-TB2-EXEC` executes exactly the published selector448 as **448 fresh exact-filter processes**, exact-one/zero-skip, benchmark 0, with immutable package/source/execution-view postflight;
3. mandatory `M5-CP3-TB2-REV` independently re-hashes selector448/prefix430/owner census, reopens the full runtime evidence, discharges or carries `M5-DEFN-REV-OBS-01`, and alone may close M5.

This Review therefore does **not** close M5 and does not label selector448 accepted. It authorizes exactly one successor: **`M5-CP3-CB20`**.

## 7. Process evidence and turn boundary

This Review is runtime-free: no Directional executable, benchmark, configure, compile, relink or generated project runtime was invoked. Product/test/fixture/CMake/benchmark/selector bytes are unchanged. Cross-file substantive inspection used a verified source snapshot after an initial setup-order miss: several repository documents were fetched directly before the turn recognized that the snapshot threshold was mandatory. Piecemeal inspection stopped, exact snapshot authority was established, and all substantive cross-file source review proceeded from verified snapshot bytes. This is an existing `LESSONS.md` 152 process-pattern instance only; it contributes no product or semantic evidence.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; independently constructed selector448 preserves the exact 430-row prefix. |
| Decisive claims independently re-derived | R16 ZIP hashes; 921/921 self-manifest; 448-row exact-one/zero-skip ledger; immutable boundary/postflight; source/A3 `Q=3`; canonical inverse-storage semantics; row16 final materialization/certificate/consumption path; row17 one-transform exact typed rejection; selector448 bytes/hash/prefix/owner census. |
| Non-vacuity checked | Actual committed relation is storage-inverted (`Q=3` semantic vs concrete inverse `1` stored); rows16/17 require stored != semantic action/route before final discriminators; row16 requires nonzero rotation+translation and consumed holonomy; row17 changes exactly one transform value. |
| Prior obligations discharged/carried | DISCHARGE `M5-CP3-TB1-R6-REV-OBS-01`, `M5-CP2-TB1-REV-OBS-01`, `M5-CP3-TB1-R15-R1-REV-OBS-01`; all four M5 produced debts discharged; CARRY `M5-DEFN-REV-OBS-01` to final `M5-CP3-TB2-REV`. |
| Stable accounting | **51 events / 14 categories / 37 recurrences**; project debt **1** (M6 only); accepted package/source promoted to `10763242885 / a8b33cb...`; accepted published selector remains selector430 430/430. |
| New candidates/obligations recorded | No new regression candidate. Exact selector448 publication/runtime/final-review sequence frozen as remaining M5 closure obligation. |
| ORIENTATION currency line | `M5-CP3-TB1-R16-REV`, 2026-09-23 UTC written. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated: accepted package/debt state, torus witness, open publication sequence, and existing storage-semantics/non-vacuity + setup-order process instances; stale R16-next bullets removed. |
| CHANGELOG | Agent and root changelogs updated with R16 Review disposition. |
| ROADMAP | Updated to promoted candidate, debt 1, selector448 precommit and CB20 -> TB2 sequence. |
| Selector manifest | n/a — selector448 is precommitted only, not yet published or accepted; selector430 remains manifest authority. |
| LESSONS | Existing authority/non-vacuity and `LESSONS.md` 152 setup-order pattern cited; no genuinely new recurring defect pattern. |
| Consolidation under CLEAN_UP_POLICY | Folded consumed CB19 plan plus superseded R15-R1 runtime report/review into `M5_Consolidated_Record.md`; retained current R16 runtime report, this Review, one CB20 plan and normative definitions. |
| Successor frozen | Exactly `M5-CP3-CB20`; exact selector bytes/hash/prefix/owner census and compile-only falsifiers are frozen here, frozen §17 and the CB20 plan. |
| Turn boundary held | Yes — runtime-free Review; no product/test/fixture/CMake/benchmark/selector semantic bytes mutated. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** on the complete Review/consolidation diff. |
| `STATUS` lifecycle maintained | Entry beacon published for `M5-CP3-TB1-R16-REV`; terminal COMPLETE -> `M5-CP3-CB20` is reserved for the final repository mutation. |
| Pushed to origin, branch in sync | **YES** — durable Review batch is pushed; temporary workflow/trigger state is retired before terminal STATUS. |

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

Closeout control-plane note: a redundant late Drive patch-apply attempt (`35900492250`) was fail-closed before mutation because the already-landed Review batch had changed one intended historical path. Its staged Drive file, temporary caller and trigger were retired; the only follow-up repository correction was a surgical TODO reconciliation that marked the already-adjudicated R6, CP2 and DEFN-R1 observations consistently closed. This orchestration-only duplicate contributes no semantic/runtime evidence.

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

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Adjudication UPHELD.** Candidate promotion, both debt discharges, the three observation discharges, the carry of `M5-DEFN-REV-OBS-01` and selector448 are all correct. I re-derived each from primary bytes rather than from this record. The **closeout was incomplete**: a frozen definition stayed false, the selector manifest missed the package promotion, and two compiled M5 identities went unmentioned. Per `REVIEW_TURN_POLICY.md` §6.1 I fixed those gaps in this addendum rather than only noting them. Accounting is unchanged at **51 / 14 / 37**, project debt **1**, successor **`M5-CP3-CB20`**.

### V1 — primary evidence re-derived from bytes, not from this record

- **R16 artifacts downloaded fresh from GitHub.** Result/log ZIP SHA-256 `d2ec2703...9f46 / 3b8d16d1...3097` match. `SHA256SUMS` hashes to `c2f89891...5784`, has 921 rows over 921 non-manifest files, and all 921 verify, with no unlisted or missing file.
- **Ledgers.** Ledger SHA-256s `5716a0b6...8987 / 9b2f4e1d...fd25` match. All **448** rows are `exit=0 / selected=1 / skipped=0 / passed=1 / PASS`. **All 448 raw-log SHA-256s** re-hash to their ledger values. The selector-ledger identity sequence equals selector430 bytes exactly, and the nonselector order equals precommit rows 431-448 exactly. Protected ordinals 191/192/247/408 PASS. `execution-boundary.txt` shows every forbidden counter false, and the package/source/execution-view censuses are byte-identical before and after.
- **Candidate package downloaded fresh.** ZIP `abe4c381...90aa`, 28/28 manifest at `cda95dd9...0c25`, source archive `54962d49...6d91`. The unpacked `src/`, `tests/` and `include/` trees are identical to the working branch. `compiled-targets.txt` lists the eight standard targets, and the link lines show GMPXX+GMP.
- **Selector448 rebuilt independently** as selector430 plus §5 rows 431-448: **448 rows / 36,382 bytes / SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`**, first-430 SHA `1c412850...9db6`, first-427 SHA `f9c88380...e86f`, zero duplicates.
- **Owner census re-derived two independent ways.** (a) Runtime routing binaries in the R16 ledgers. (b) **Static** `cmake/DirectionalTests.cmake` target membership, parsing every `TEST/TEST_F/TEST_P` in each standard owner's sources. Both give **32 / 300 / 75 / 41** and agree row for row on all 448 rows.

### V2 — rows16/17 non-vacuity holds, with one assertion that cannot fail

The load-bearing claims hold from source (`tests/SurfaceCellTransitionQuotientTests.cpp:3281-3507`, helper `:1816-1864`). The expectation `Q=3` is a hard-coded constant (DEFN-R1 §7), checked against the source cross-field's directed transition. The pipeline transition must equal the pre-finalized source transition (`:1371-1377`). The production resolver only *normalizes representation*. It never supplies the expected value. `storageInverted` is computed by the test from `cutRoute` versus the Forward edge's route. If the product were direction-inverted, the resolved rotation would be `1`, and `EXPECT_EQ(witness.sourceRotation, semanticAction.rotation)` would fail. `Q=3` is not self-inverse, so the check discriminates. The guard `M5-CP3-TB1-R15-R1-REV-OBS-01` set for CB19 is therefore honored, and its discharge is correct.

**Correction — the atlas "cross-check" is a selection filter, not a falsifier.** `select_torus_source_witness` already `continue`s whenever `atlasValue->transport != *sourceRotation` (`:1233-1237`). That makes `ASSERT_EQ(witness.sourceRotation, witness.atlasRotation)` (`:3287`, `:3449`) unable to fail (`LESSONS.md` 64r). §2 above and `ORIENTATION.md` §8 present the atlas as part of the independent expectation. My own R15-R1 addendum V3 made the same overstatement ("cross-checked against `witness.atlasRotation` in the test's own opening assertion"), and I withdraw it. The conclusion stands, because the constant, the source cross-field and the pipeline-equals-source check carry the independence. The atlas contributes only witness *selection*.

**Row17 positive control — checked, holds by construction.** Row17 never shows that the *untampered* nonzero-witness draft round-trips through `construct_phase_front_product`. The only gated test that does so on this fixture would be `ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`, which is ungated (V4). The round-trip is nevertheless guaranteed. `SurfacePhaseFrontProduct` has a private constructor (`include/directional/geometry/SurfaceCellTracing.h:1831-1832`), so `make` is its only construction path. `PhaseFrontDraft` carries all nine `make` arguments, and the produced product therefore already passed `make` on identical inputs. The typed rejection is attributable to the single tamper. No obligation is issued.

**Translation scope.** Row16 proves the translation is nonzero, consistent with all four endpoint lattice states and accepted by materialization. It does not prove an independently derived translation value, because none exists for this witness. That satisfies §8.2 debt 3 as written. I recorded the scope in frozen §8.2 so the final Review cannot overstate it.

**Certificate check is direction-agnostic by design.** Row16 accepts `appliedTransport == action()` **or** `action().inverse()` (`:3385-3386`). A path step may traverse the seam either way, so the certificate check proves the relation is *named and consumed*. It does not prove direction. Direction is carried by the rotation assertion and the four lattice/branch equations. §2.1's wording is accurate on this point.

### V3 — closeout gaps found and fixed in this addendum

| # | Gap | Fix |
|---|---|---|
| G1 | `Architecture_M5_Frozen_Definitions.md` §11 "Current exact successor" still named **`M5-CP3-CB14`**. It had been false since R12, and every later Review/DEFN missed it, this one included. A cold start reading the frozen record is sent to a superseded turn. §8.2's heading "Four M5 debts remain unchanged" read as "still open", and §9's M5-CP3 heading carried no status. `REVIEW_TURN_POLICY.md` §3.2 requires editing a frozen document whose claim is false. | §11 now names CB20 → TB2-EXEC → TB2-REV and marks the CB14 text as superseded, citing where it is retained. §8.2 gains a discharge note and translation-scope note with requirements unweakened. §9 M5-CP3 gains its status. |
| G2 | The `Required_Green_Selector_Manifest.md` closeout said "n/a — selector448 not published". That misses the **package promotion**: CP1-REV and CP2-REV each recorded their promotion under selector430 there (lines for `10600353027` and `10601978228`). The manifest therefore still implied `10601978228` was current. | Added the R16-REV promotion line. Selector448 is recorded as precommitted only, with no table row. |
| G3 | **Two compiled M5CP3 identities are in no gate and no durable document:** `M5CP3.PeriodicRelationEndpointGaugeIsIndependentAndExact` and `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`. Both were added at CB14 (`fd7de8a1`). `git log --all -S` finds each name only in that test-source commit, so they have never been executed or adjudicated. Excluding them from selector448 is **correct**, since §13.3 lets a Review precommit only identities it accepted green. The gap is that §5 presents the 18 as the complete reviewed set without saying 2 of the file's 10 `M5CP3` identities are excluded or why. They stay compiled into the producer binary with unknown status. | Recorded **`M5-CP3-TB1-R16-REV-OBS-01`**, owned by `M5-CP3-TB2-REV`. CB20 plan §6.4 prohibits touching them. |
| G4 | The ORIENTATION §8 `RP-01` bullet still said "product debt proof remains pending fresh R16 after test-only CB19". That is a superseded clause left standing (`REVIEW_TURN_POLICY.md` §3.1 item 4). The new §8 storage entry also repeated the atlas overstatement (V2). | Both edited in place. |
| G5 | Nothing recorded that `ASSERT_TRUE(storageInverted)` pins rows 446/447 to the *current* canonical storage orientation. That pin is intentional, because it is what makes the inverse path non-vacuous (`LESSONS.md` 171). But once selector448 is accepted, a later representation-only canonicalization change would turn both rows RED with no product defect. | Recorded **`M5-CP3-TB1-R16-REV-OBS-02` — RECORDED / NOT FIRING**, parallel to the ordinal307 entry. |
| G6 | `M5_Consolidated_Record.md` has duplicate section numbers: two §4.17 (CB16, CB17) and two §4.18 (R14-EXEC, R15-EXEC). §§4.17-4.22 also sit after §5. Any citation of "§4.17" or "§4.18" is ambiguous. The disorder predates R16-REV, and this consolidation did not introduce it. | Not restructured here, to keep the change surgical. Carried as **`M5-CP3-TB1-R16-REV-OBS-03`** to the M5 closure consolidation at `M5-CP3-TB2-REV`. |
| G7 | The CB20 plan's falsifier 5 ("exactly one approved owner target") would fire spuriously on seven prefix identities. Six `MilestoneGP26.*` identities (ordinals 41-46) and `SurfaceArrangementPhase16.FaceInteriorSupport...` (ordinal 113) are also defined in sources compiled only into the optional `historical_tests` target. The plan also gave TB2 no routing authority for rows 431-448, because routing map `7a92e7a3...` covers only 430 rows. | CB20 plan §6 scopes owners to the four standard executables, requires a recorded 448-row static routing receipt and requires the manifest index, following the CB8 precedent. Selector bytes, hash, prefix and census are unchanged. |

G1-G7 do not change any adjudicated outcome. None of them could have turned the gate red. They are closeout and completeness defects of the kind `REVIEW_TURN_POLICY.md` §1 describes.

### V4 — obligations after this addendum

- `M5-DEFN-REV-OBS-01`: **carried** to `M5-CP3-TB2-REV` (unchanged).
- `M5-CP3-TB1-R16-REV-OBS-01` (G3): **new, carried** to `M5-CP3-TB2-REV`. That Review must state an explicit disposition for both identities: never executed, excluded from selector448, and **no credit toward any §13.1 conjunct**. It must route their deletion or gating to a named later turn. It may not add them to the TB2 vector or stitch in a report-only run.
- `M5-CP3-TB1-R16-REV-OBS-02` (G5): **recorded / not firing**. If rows 446/447 fail solely on `storageInverted`, classify the failure as test-authority representation drift. Do not delete the pin. Supply a witness that exercises inverse storage instead.
- `M5-CP3-TB1-R16-REV-OBS-03` (G6): **carried** to `M5-CP3-TB2-REV` consolidation. Renumber or fold so every section number is unique and ordered, and repair citations.

Each new item passes the deletion test. Without OBS-01, M5 could close while two dormant `M5CP3` tests of unknown status sat in its gate binary with no stated disposition. Without OBS-03, the closure fold would inherit ambiguous citations. OBS-02 carries no obligation until it fires, which is why it is recorded rather than assigned.

## Review closeout — reviewing-agent addendum

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` (430 rows / 35,001 B); first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; rebuilt selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789` with first430 equal to selector430. |
| Decisive claims independently re-derived | Fresh GitHub download and re-hash of the result/log/candidate ZIPs; 921/921 and 28/28 manifests; all 448 ledger rows and raw-log hashes; boundary/census postflight; packaged source equal to the branch; owner census computed both statically and from routing, agreeing row for row; row16/17 source paths. |
| Non-vacuity checked | Direction inversion would give `Q=1≠3`. The atlas assertion is tautological (corrected). Row17's untampered control holds via the private-ctor/`make` invariant. The certificate check is direction-agnostic by design. Translation is nonzero plus consistent, not independently valued. |
| Prior obligations discharged/carried | Upheld: R6-OBS, CP2-OBS and R15-R1-OBS discharged; both nonzero-Z4 debts discharged; `M5-DEFN-REV-OBS-01` carried to TB2-REV. |
| Stable accounting | **51 / 14 / 37**; project debt **1** (M6). Accepted package `10763242885 / a8b33cb7...` under selector430 430/430. |
| New candidates/obligations recorded | `M5-CP3-TB1-R16-REV-OBS-01/-02/-03`, all in the tracker. No regression candidate. |
| ORIENTATION currency line | `M5-CP3-TB1-R16-REV` (reviewing-agent addendum), 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 unchanged (state is correct). §4 unchanged. §7 gains OBS-01 and OBS-02. §8 `RP-01` bullet's superseded clause edited, and the atlas overstatement in the storage entry edited. |
| CHANGELOG | The agent changelog's R16-REV entry is amended. No second entry was added. |
| ROADMAP | n/a — checkpoint status did not move; the delegated update is correct. |
| Selector manifest | Updated — R16-REV package promotion under selector430 (G2). |
| LESSONS | Cited 64r (the assertion that cannot fail), 171 (discriminating twin / pinned inverse storage) and 33 (circular oracle, guard honored). No new lesson. |
| Consolidation under CLEAN_UP_POLICY | Nothing to fold: the R16 report and review are current and the CB20 plan is live. The pre-existing numbering defect is carried as OBS-03. |
| Successor frozen | Exactly `M5-CP3-CB20`. Falsifiers are in the CB20 plan §4, with the §6 clarifications, and in frozen §17. |
| Turn boundary held | Yes. Runtime-free, and no product/test/fixture/CMake/benchmark/selector bytes changed. Artifact downloads were read-only, and no Directional binary was executed. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** with `--expect-selector 430=1c4128500cb2...9db6` on the addendum's 10-file documentation diff (9 documents plus the selector manifest, which the tool excludes from its document list). No product/test/fixture/build or selector mutation. Durable markers preserved (handoff 1→1, ORIENTATION 2→2). |
| `STATUS` lifecycle maintained | Resume beacon `IN_PROGRESS` published first (`Resumed at` = review handoff `2026-09-23T18:52:24Z`, `Started at` preserved). The final `COMPLETE → M5-CP3-CB20` beacon is the last write. |
| Pushed to origin, branch in sync | Confirmed with `git status -sb` after the final push (no ahead/behind). |

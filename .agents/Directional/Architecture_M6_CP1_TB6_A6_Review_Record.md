# M6-CP1-TB6-A6 Review Record

**Turn:** `M6-CP1-TB6-A6-REV`
**Date:** 2026-09-29 UTC
**Boundary:** runtime-free independent Review
**Disposition:** **CANDIDATE REJECTED / TWO ACCEPTED-PREFIX REGRESSIONS / R3 HOLONOMY FALLBACK INVOKED / BOUNDED A6 RECOVERY AUTHORIZED**
**Exact successor:** `M6-CP1-CB7-A6`

## 1. Evidence boundary

Review used exact repository snapshot run/artifact `36598460532 / 11047936711`, event/source `b291e620a20fbf9fa85ea0cf23a90d2b8b81e3e5`, artifact provider digest `sha256:f195aa88dd2d2fbac5467bbc14f09c13ec3690daf7cb9bebd8f0aa0ed0675cc4`, and source archive SHA-256 `8789125fee2679ca921d93ddd519fe8a84ad05e3617c7c971ac8a6ed8769d73f`. The snapshot self-manifest verifies 5,326/5,326 files and is runtime-free.

No Directional executable was run in Review. Product, test, fixture, selector, benchmark and build source are unchanged by this turn.

## 2. EXEC report correction: an authoritative complete runtime exists

The retained EXEC report said no authoritative runtime was established. Independent workflow reconciliation disproves that statement. Two TB6-A6 executor runs exist:

1. `36362470435`, event SHA `b91280f58fc5e80942b1c2d3fbf59c4dfce1bf0c`, runtime job `108742278782`, **failure**. It produced only log artifact `10945963561`. This attempt is orchestration-invalid and receives no semantic credit.
2. `36362570974`, event SHA `bcca1196ab69a68c62794715b3fbee8b1ae520ab`, runtime job `108742561290`, **success**. Result/log artifacts are `10947080007 / 10946089412`, provider digests `sha256:ebce7715d3952fb5b9b449073724ff9d2fc007de29a81f505b206400d3e1531d / sha256:1dee2d1755b0231f9ea882398854cb82f38ba01aafd24f6831145268f1a57c71`.

The second run is the authoritative mechanically valid TB6-A6 execution. Its result self-manifest independently verifies **946/946** and its execution boundary reports:

- `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`;
- `orchestration_failure=false`, `selection_integrity=true`;
- focused executed `11`, selector executed `449`, total `460`;
- benchmark/configure/compile/relink/discovery/package-repair/mode-repair/source-test-fixture-selector-mutation all false;
- `retry_after_runtime_start=false`, `script_exit=0`.

The first failed orchestration remains useful process evidence only. The second run supersedes the EXEC report's claim that no valid runtime gate existed.

## 3. Immutable candidate and accepted-prefix controls

Candidate artifact/source remains `10896307843 / a532f803bd2f0ef92342652ea3f1a9b64945ba69`:

- candidate ZIP SHA-256 `54eb770889822ef265053494e55e25af79616f77305d1ac6900f2f8969f56b7e`;
- packaged source archive SHA-256 `e48ad4a919e450ccd9809083af0c02e2260b7c040d40ee94741aa79428fc9a45`;
- root package manifest **28/28**;
- packaged test executables retain mode `0755`;
- GMP/GMPXX and `runtimeExecution=false` remain compile-package authority.

Independent selector/routing re-hash:

- selector449 = **449 rows**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- selector448 = **448 rows**, SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`;
- selector449 rows 1-448 are byte-identical to selector448;
- routing449 = **449 rows**, SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owner census exactly **32 / 301 / 75 / 41**.

Accepted prior runtime authority is CB5/TB5 package/source `10879581622 / 82b86a285292379cfd92cdc4e10d74181b38f1e8`. Accepted TB5 result artifact `10880392759` independently shows focused row6 and selector rows139/142/446 PASS inside the complete 456/456 gate. Therefore the TB6 losses below are accepted-green losses, not newly introduced ungated tests.

## 4. Authoritative TB6-A6 result

Run `36362570974` executes exactly the frozen 11 focused identities followed by selector449 as 460 fresh exact-filter processes. Every process selects exactly one test with zero skips.

| Surface | PASS | RED |
|---|---:|---:|
| focused | 10 | 1 |
| selector449 | 446 | 3 |
| **total** | **456** | **4** |

The four RED identities are exactly:

- focused 6 `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection` → `QuotientHolonomyConflict`;
- selector139 `SurfaceCellAuthorityContractCutover.HardRailPairChangedRouteContentRejectsStrictTransport` → unexpected success, expected `InvalidHardRailTransport`;
- selector142 `SurfaceCellAuthorityContractCutover.HardRailPairSameOrientationRejectsStrictTransport` → unexpected success, expected `InvalidHardRailTransport`;
- selector446 `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` → `QuotientHolonomyConflict`.

All four new A6 focused identities 8-11 PASS. Registered controls/falsifiers are: selector140 PASS, 232 PASS, 444 PASS, 448 PASS, 449 PASS, focused5 PASS, focused7 PASS; raw `QuotientHolonomyConflict` count is two. Immutable postflight is clean.

## 5. Finding A — HardRail reciprocal route validation was dropped at the A5 -> A6 authority cutover

**Candidate:** `M6-CP1-TB6-A6-REV-CAND-02`
**Classification:** **STABLE / recurrence of existing singleton `VALIDATION_ORDER_SHADOWING`**
**Accepted selector losses:** rows **139 and 142**
**Accounting:** one shared root mechanism = **one stable event + one recurrence**, no new category.

### Independent source derivation

Accepted CB5 materialization rejects a reciprocal HardRail pair when either:

- both sides claim the same `sourceTopologyRegion`, or
- `first.route != second.route.reversed()`.

That exact guard returns `InvalidHardRailTransport` before constructing the HardRail equivalence.

CB6-A6 moves relation authority into A5. The new A5 HardRail publisher validates only that the two boundary sides carry the same explicit `HardRailId`, then publishes `sharedEquivalence.route = first.route` and `storageTransport = first.route.composed_transport()`. It does **not** validate opposite-region ownership or reciprocal reversed route content before freezing A5 relation evidence.

A6 then validates its certificate against that already-published A5 evidence. It can prove internal self-consistency, but it cannot recover the omitted reciprocal relation check because the bad evidence has already become A5 authority. Rows139/142 therefore return success instead of the accepted typed rejection.

This is the same family as the prior row140 `VALIDATION_ORDER_SHADOWING` event: semantic authority moved earlier, and an accepted specific HardRail validation became unreachable at the new authority boundary. Existing `LESSONS.md` 22f applies. Row140 staying PASS proves the explicit owner-ID mismatch path remains live; rows139/142 isolate the missing route reciprocity/content predicate rather than a general HardRail failure.

### Required recovery

`M6-CP1-CB7-A6` must restore the accepted HardRail reciprocal semantic gate **at A5 publication**, before relation evidence becomes immutable. It must require distinct source topology regions and exact reversed routes, preserving `InvalidHardRailTransport`. It may not duplicate semantic authority downstream, weaken rows139/142, or infer route compatibility from IDs alone.

## 6. Finding B — universal identity residual is false for the accepted nonzero-Z4 periodic witness

**Candidate:** `M6-CP1-TB6-A6-REV-CAND-01`
**Classification:** **STABLE / recurrence of existing `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION`**
**Accepted selector loss:** row **446**
**Corroborating focused loss:** focused row6 (not separately priced)
**Accounting:** **one stable event + one recurrence**, no new category.

### Independent evidence

Frozen R3/RA-4 required a cycle-closing relation's direct canonical transport to equal the composed transport of one deterministic selected-forest path. It explicitly pre-registered cylinder232 and torus444/446/448/449 as runtime falsifiers and reserved an evidence-only residual fallback for this mandatory Review.

TB6 activates that falsifier exactly:

- cylinder232 PASS;
- torus444 PASS;
- torus446 RED at `QuotientHolonomyConflict`;
- torus448 PASS;
- torus449 PASS;
- focused pair-swap row6 independently REDs at the same `QuotientHolonomyConflict`.

Accepted row446 is not an arbitrary malformed cycle. It independently proves a produced torus periodic relation whose semantic rotation is nonzero (`Q=3`), whose semantic action agrees with the independent atlas/source authority, whose storage may be inverse-oriented, and whose lattice shift is nonzero. The same identity passed under the accepted CB5/TB5 authority. The first new A6 rule rejects it solely because a direct noncontractible periodic relation differs from the chosen spanning-forest path.

That makes the strict universal equality an overconstraint. A selected forest is a linearization of the quotient relation graph; on a periodic/noncontractible cycle, the direct relation may carry legitimate residual deck-transform holonomy relative to that path. Requiring the residual to be identity is the existing `RP-07` pattern: cyclic topology is being forced through one incidental cut/linearization.

### R3 fallback is now invoked

For canonical direct relation transport `D : a -> b` and canonical selected-path transport `P : a -> b`, cycle-closing consumption must publish the exact residual

`H = compose(P.inverse(), D)`.

`H == identity` remains a valid observed case, not a universal acceptance precondition. A non-identity `H` is evidence and must be preserved exactly. `QuotientHolonomyConflict` is reserved for algebraically inconsistent direct/path/residual evidence or violation of a separately frozen zero-holonomy obligation; general produced periodic torus relations have no such zero-residual obligation in CP1.

This does **not** authorize permissive relation synthesis. Each constituent relation certificate must still match immutable A5-owned relation evidence in canonical direction. A7 may consume/project the A6 result but may not use residual holonomy to alter quotient class identity/topology.

`Architecture_M6_Frozen_Definitions.md` is amended in this Review because the runtime falsifier disproves its previous universal equality claim.

## 7. Non-vacuity and prior obligations

- The four new A6 focused identities 8-11 all execute and PASS; the product extraction is not bypassed.
- Focused row4 PASS confirms the `lattice -> placement.lattice` test migration is value/meaning preserving in runtime.
- Row139/142 tamper route content/orientation and fail only because the intended guard disappeared; row140 still PASSes its independent owner-ID mismatch negative.
- Row446/focused6 prove the cycle-closing periodic path is actually reached. Rows232/444/448/449 staying green distinguish the nonzero-Z4 residual case from a general periodic/forest failure.
- R3's pre-registered holonomy obligation is **DISCHARGED BY FALSIFICATION**: the fallback condition fired and this Review amends the definition.
- A7, `M6-DEFN-R4`, the exact `G4-B002` A6 stage boundary, `G4-B001`, and `G4-B004` representative-consumption half remain carried and are not advanced here.

## 8. Accounting and promotion

Two distinct accepted-prefix root mechanisms are proven:

1. rows139+142: one `VALIDATION_ORDER_SHADOWING` event/recurrence;
2. row446: one `RP-07 / CYCLIC_TOPOLOGY_LINEARIZATION` event/recurrence.

Stable accounting therefore advances from **55 / 16 / 39** to **57 events / 16 categories / 41 recurrences**. Produced-witness debt remains **1**, M6-owned.

Candidate `10896307843 / a532f803...` is **rejected/unpromoted**. Current reviewed runtime authority remains `10879581622 / 82b86a28...` under selector449 **449/449**.

## 9. Exact successor: `M6-CP1-CB7-A6`

One bounded relation-validation recovery turn is authorized. It may change only the A5/A6 relation-validation and cycle-residual surfaces required by Findings A/B plus the existing focused assertions needed to falsify those corrections.

Predeclared falsifiers and stop rules are in `Architecture_M6_CP1_CB7_A6_Relation_Validation_Recovery_Code_Build_Plan.md`:

- rows139/142 must remain exact accepted `InvalidHardRailTransport` negatives;
- row140 must remain green;
- cycle-closing certificates must remain exact A5-authority-bound and exact-once;
- a nonidentity periodic residual must be recorded rather than rejected;
- tampering a certificate away from A5 authority must still reject typed;
- selector449/routing449 and all fixture/product identities remain byte-stable;
- no A7/R4/G4 work and no runtime in CB7-A6.

Compile-green CB7-A6 advances to a fresh immutable `M6-CP1-TB7-A6-EXEC` over the same **11 focused + selector449 = 460** process shape, then mandatory `M6-CP1-TB7-A6-REV`. The focused identity count stays 11: the prior strict-holonomy negative is replaced by a residual-recording identity, and the existing certificate-conflict identity is strengthened rather than adding a twelfth test.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; selector448 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`; rows1-448 byte-identical. Routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owners 32/301/75/41. |
| Decisive claims independently re-derived | Reconciled both Actions runs; verified run2 946/946 result manifest and 460-process boundary; compared TB6 RED identities against accepted TB5 evidence; audited pre/post A6 HardRail semantics and R3 cycle rule from source. |
| Non-vacuity checked | A6 focused8-11 PASS; row4 PASS; row140/232/444/448/449 controls PASS; row139/142 isolate reciprocal-route loss; row446 + focused6 reach the periodic cycle-closing residual path. |
| Prior obligations discharged/carried | R3 holonomy falsifier DISCHARGED BY FALSIFICATION and fallback invoked; row4 migration DISCHARGED runtime-green; A7/R4/G4-B001/B002/B004 obligations carried. |
| Stable accounting | **57 / 16 / 41**, debt **1**; accepted runtime remains `10879581622 / 82b86a28...`, selector449 449/449. |
| New candidates/obligations recorded | `M6-CP1-TB6-A6-REV-CAND-01` (RP-07), `M6-CP1-TB6-A6-REV-CAND-02` (VALIDATION_ORDER_SHADOWING); tracker updated. |
| ORIENTATION currency line | `M6-CP1-TB6-A6-REV` / 2026-09-29 UTC written. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 accounting/authority/successor updated; §4 torus A6 state updated; §7 reprioritized to CB7-A6 before R4; §8 records both existing-pattern recurrences and removes superseded TB6 orchestration-only framing as current authority. |
| CHANGELOG | Turn entry added; superseded EXEC-only interpretation corrected by Review authority. |
| ROADMAP | M6 CP1 A6 runtime gate marked reviewed RED; CB7-A6 recovery inserted before R4/A7. |
| Selector manifest | n/a — selector449 bytes and accepted manifest are unchanged; independently re-hashed above. |
| LESSONS | No new lesson: existing lesson 22f covers validation-order shadowing; existing RP-07 catalog covers cyclic linearization. |
| Consolidation under CLEAN_UP_POLICY | CB6-A6 plan/report and TB6-A6 plan/report folded into `M6_Consolidated_Record.md` and retired; current Review + CB7 plan retained. |
| Successor frozen | Exactly one: `M6-CP1-CB7-A6`; falsifiers and stop rules are in its Code + Build plan. |
| Turn boundary held | Runtime-free Review; no product/test/fixture/selector/benchmark/build source mutated. |
| review_check.py boundary | **PASS** on the prepared Review tree; selector counts/hashes and durable boundaries unchanged. |
| `STATUS` lifecycle maintained | `M6-CP1-TB6-A6-REV` entered IN_PROGRESS with start timestamp; final COMPLETE beacon names `M6-CP1-CB7-A6` and is the final repository write. |
| Pushed to origin, branch in sync | Final documentation patch is pushed to the working branch through exact-base CAS; closeout re-reads branch authority and leaves the prepared local tree clean. No commit hash is embedded here. |

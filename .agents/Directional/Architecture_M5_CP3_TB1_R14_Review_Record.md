# M5-CP3-TB1-R14 Independent Review Record

**Turn:** `M5-CP3-TB1-R14-REV`
**Boundary:** runtime-free Review; no product/test/fixture/selector/build-source mutation
**Reviewed runtime:** `M5-CP3-TB1-R14-EXEC` run/job `35824161895 / 107062198724`
**Reviewed candidate:** artifact/source `10733058003 / 6bad9eb5626e77a234ffb2c14f621195105e4ba1`
**Verdict:** **SEMANTIC RED UPHELD / CB16 FOCUSED CONTRACT GREEN / PRODUCTION RECOVERY FAILED / SAME-REGION NONZERO-Z4 GAUGE MODEL UNDER-SPECIFIED / EXISTING RP-01 / +0**
**Exact successor:** `M5-CP3-DEFN-R1`

## 1. Independent evidence re-open

Review re-opened the immutable R14 result bytes rather than accepting the EXEC report as self-proving. Result artifact `10734153401` re-hashes to `ba6ab62396ff572aabb6850643e2d460cbfa0b5b196813bb3b8a91e6a31e3088`; log artifact `10734178551` re-hashes to `2e32386ee9e9ad67391f31227d2ddac1504f67f321e94c6296e62cb055b29b7f`. The result `SHA256SUMS` re-hashes to `db2ccb2a5e1821018a71032ca9bdcf34e5c0a97fee6ae384d3710656320fd5ce` and independently verifies exactly **916/916** non-manifest files.

The four runtime ledgers independently yield branch+semantic+mechanism **11/11**, focused atlas **1/1**, produced **4/6**, selector430 **430/430**, for **446 PASS / 2 RED** across all **448** planned fresh exact-filter processes. Every row selected exactly one test and skipped zero. Produced rows4/5 are the only REDs; protected selector ordinals **191/192/247/408** are PASS. Benchmark execution and every prohibited-operation counter are zero. Package/source/execution-view before/after censuses compare byte-for-byte equal.

Candidate ZIP `10733058003` independently hashes to `96e313e822bea8ebc6b7478c75c99d4c9245c7d88913b0d14d449a0ec73013f0`; its root `SHA256SUMS` hashes to `f77684128606428a82fe236b749b2d8357948e610745db55f98775a6b4217629` and verifies **28/28**. The packaged semantic source archive hashes to `45bb6ccaba68772e998ebd41d75334041b54e5eadb36e4f3c0cd68b46b9b988b`.

Review also re-opened routing artifact `10592987234`: ZIP `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`, identity map `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, exactly 430 unique ordinals/identities, owner census **31 / 283 / 75 / 41**, and identity order exactly equal to selector430. Selector430 independently re-hashes to `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; its first427 prefix re-hashes to `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Runtime-free source snapshot run `35827620496` materializes branch authority `98a65c9ddd09bcf02aad027379464f32006ca66b`, **5299** files, archive SHA-256 `94df9762775254ab1f2ccc90ec251855c003622afa1c6561d0eebbececb2e8fc`, `runtimeExecution=false`. GitHub comparison from tested semantic source `6bad9eb5626e77a234ffb2c14f621195105e4ba1` through Review entry shows no changes under `src/`, `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt` or `cmake`; intervening changes are documentation/control only. Static inspection of the Review snapshot is therefore valid evidence about the tested code.

## 2. CB16 focused branch-authority correction is genuinely exercised, but only at helper scope

`M5CP3.PeriodicRelationEndpointBranchUsesAcceptedOccurrenceAuthority` PASSes. The test is non-vacuous for the helper contract: it deliberately gives the local face and accepted occurrence-carrier face different +U branch gauges, derives

```text
C     = B_local - B_face_local
B_rel = B_face_occ + C
```

and proves that `make_periodic_relation_endpoint_state(...)` publishes `B_rel`, not the old raw local branch. Its `R == 0` control also preserves raw cell coordinates exactly.

The same tested source uses this helper on the produced path. Before `PeriodicActionFirstBranchMismatch` can fire, all four endpoint states must exist and the earlier orientation, generator-rotation, source-chart, boundary-occurrence and reciprocal-scale predicates must pass. The R14 RED is therefore not an endpoint-state-unavailable fallback and not evidence that the CB16 helper was dead code.

The focused test nevertheless does **not** prove the production seam's gauge relationship. It hand-authors `localFaceBranchRotation` and `occurrenceCarrierFaceBranchRotation` values that already satisfy the intended correspondence. It does not derive those values from the accepted cut-open phase-front gauge used by production.

## 3. Production discrepancy: raw generator transport and cut-domain branch gauge are separate authority domains

Static inspection explains why a helper-level PASS and production-level first-branch RED can coexist without contradiction.

The bounded-disk producer constructs `faceBranchRotation` by propagating branch state over the **cut-open dual graph**. When accepted-cut-domain mode is active, every accepted cut edge is explicitly omitted from that dual propagation. The two occurrence-carrier faces on opposite copies of a periodic cut are therefore assigned branch gauges through the cut-open domain, not by enforcing the direct transition across the removed carrier.

Later, same-region periodic promotion obtains `generatorRotation` independently from `FieldTransportAtlas::transition_value(...)` on the exact accepted A3 generator carrier in Forward-occurrence-face -> Reverse-occurrence-face direction. CB16 then re-expresses each local endpoint branch at its occurrence-carrier face using the cut-domain `faceBranchRotation` values and asks the raw generator rotation to satisfy

```text
compose(R, firstFrom.branchRotation) == secondTo.branchRotation
```

and the reciprocal second-branch equation.

No frozen M5 definition currently specifies the exact change of gauge between those two representations: A1's directed source-face transition on the removed carrier, and the cut-open phase-front trivialization used to author relation endpoint branch/lattice coordinates. Because the cut carrier is deliberately absent from the propagation that defines `faceBranchRotation`, the equality is not a consequence of the current producer construction. R14's real produced subject falsifies the implicit assumption that the two representations already coincide.

This is stronger than merely observing the repeated reason string, but it does **not** justify a guessed replacement formula. The result contains no numeric endpoint operands, and Review does not infer an inverted generator direction, free translation, partner-fitted endpoint, or a specific conjugation/change-of-basis formula. Those are definition questions owned by the successor turn.

## 4. Candidate, observations and debt disposition

`M5-CP3-TB1-R14-CAND-01` is reclassified **CAUSE PROVED / DEFINITION AUTHORITY / EXISTING `RP-01 AUTHORITY_DOMAIN_CONFLATION` CONTINUATION / SAME-REGION NONZERO-Z4 RAW-TRANSPORT VS CUT-DOMAIN-GAUGE MODEL UNDER-SPECIFIED / NON-STABLE / OWNER `M5-CP3-DEFN-R1` / +0**.

CB16's focused correction is accepted as a correct implementation of its stated helper formula, but **production recovery is not proved**. `M5-CP3-TB1-R13-CAND-01` therefore remains inside the broader open endpoint-gauge recovery chain rather than closing recovery-proved. `M5-CP3-TB1-R11-R1-CAND-01` remains OPEN as the broad relation-endpoint gauge chain, now owned by definition reconciliation before any further Code + Build turn.

`M5-CP3-TB1-R13-REV-OBS-01` is **DISCHARGED AS TRIGGERED**: CB16 did not bring produced rows4 and row5 both green, so the precommitted stop rule applies and `CB17` is prohibited. Its required action is fulfilled by freezing `M5-CP3-DEFN-R1` as the sole successor.

`M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN** because row4 still stops before the independent Forward -> Reverse comparator and inverted-pair rejection. `M5-CP2-TB1-REV-OBS-01` remains **OPEN** because the corrected CP3 pre-publication gate is still semantic RED even though selector430 is 430/430. `M5-DEFN-REV-OBS-01` remains carried to final M5 closure. The two M5 nonzero-Z4 produced debts remain open; the separate closed-complex debt remains M6-owned.

There is no accepted-prefix PASS -> RED transition. Stable accounting therefore remains **51 events / 14 categories / 37 recurrences**, produced-witness debt **3**. Candidate `10733058003 / 6bad9eb5626e77a234ffb2c14f621195105e4ba1` remains unpromoted. Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

## 5. Frozen-definition impact

R14 does not authorize an implementation-side patch. It proves that §§16/16.1 are insufficient as implementation authority for the same-region nonzero-Z4 seam because they require one directed `R` and independently authored endpoint states but do not freeze the change of gauge connecting A1 source-face transport to the cut-open relation endpoint frame.

`Architecture_M5_Frozen_Definitions.md` therefore gains a narrow R14 stop amendment: existing §16 equations and all prohibitions remain obligations, but no further same-region nonzero-Z4 semantic implementation may proceed until `M5-CP3-DEFN-R1` assigns one explicit authority domain to the generator rotation, endpoint branch component, endpoint lattice coordinates and canonical storage/value representation, and defines every allowed change-of-gauge read.

No selector, fixture, field, A3 route, relation identity or failure contract changes in this Review.

## 6. Exact successor — `M5-CP3-DEFN-R1`

Exactly one successor is authorized: runtime-free definition reconciliation **`M5-CP3-DEFN-R1`** under `Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Plan.md`.

The turn must derive a coherent same-region nonzero-Z4 relation gauge before any further implementation. It must explicitly distinguish raw A1 source-face transport from cut-domain/endpoint relation coordinates; define the exact deterministic change of gauge in both Forward and Reverse semantic directions; define how translation transforms with rotation; preserve orientation-neutral relation identity and deterministic canonical storage; prove the `R == 0` reduction; and state a non-vacuous produced nonzero-Z4 witness criterion in the **relation gauge**, not merely a nonzero raw source-edge matching.

If the definition cannot derive one unique relation action from existing producer-owned facts without partner fitting, inverse retry, search, fixture tuning or new downstream authority, the turn must stop with a definition blocker rather than authorize another Code + Build correction.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; routing owner census **31/283/75/41**. |
| Decisive claims independently re-derived | R14 ZIPs and self-manifest, **916/916**, exact 448-process ledger **446/2**, candidate **28/28**, selector/routing bytes, immutable censuses, no code drift, and source ownership split between cut-open `faceBranchRotation` and raw carrier `transition_value(...)`. |
| Non-vacuity checked | CB16 focus deliberately separates local and occurrence face gauges and passes; produced rows4/5 execute the endpoint-state path and alone RED while rows1/2/3/6 and selector430 stay green. The focus does not derive production cut-domain gauge values, so its PASS cannot substitute for the produced falsifier. |
| Prior obligations discharged/carried | `R13-REV-OBS-01` discharged as triggered -> DEFN-R1; `R6-REV-OBS-01`, `M5-CP2-TB1-REV-OBS-01`, `M5-DEFN-REV-OBS-01`, both nonzero-Z4 debts and the broader endpoint-gauge chain carried. |
| Stable accounting | **51 events / 14 categories / 37 recurrences**, debt **3**; accepted package/source `10601978228 / 0798547d...`, selector430 430/430; R14 candidate unpromoted. |
| New candidates/obligations recorded | `M5-CP3-TB1-R14-CAND-01` cause-proved as existing RP-01 definition-authority continuation; tracker updated; no new stable category/event. |
| ORIENTATION currency line | `M5-CP3-TB1-R14-REV`, 2026-09-23 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for R14 Review, torus witness state, definition-reconciliation priority, carried observations/debts and the raw-transport/cut-domain-gauge RP-01 instance. |
| CHANGELOG | Root and Directional changelogs updated with R14 Review adjudication and DEFN-R1 successor. |
| ROADMAP | M5-CP3 updated to R14 Review complete / definition reconciliation next. |
| Selector manifest | n/a — no selector added, changed, precommitted or accepted. |
| LESSONS | Existing authority-domain/gauge lessons cited; no new lesson number because this is another `RP-01` instance. |
| Consolidation under CLEAN_UP_POLICY | Superseded R13 report/Review, consumed CB16 plan/report and consumed R14 EXEC plan folded/indexed into `M5_Consolidated_Record.md`; current R14 runtime report + this Review + one DEFN-R1 plan retained. |
| Successor frozen | Exactly one successor: `M5-CP3-DEFN-R1`; static falsifiers and stop rules are frozen in `Architecture_M5_CP3_DEFN_R1_Same_Region_Nonzero_Z4_Gauge_Reconciliation_Plan.md`. |
| Turn boundary held | Yes — runtime-free Review; no product/test/fixture/benchmark/build/selector byte changed and no Directional runtime executed. |
| review_check.py boundary | **PASS / ALL CHECKS PASSED** with selector430/first427 declarations after the documentation patch. |
| `STATUS` lifecycle maintained | Entry/resume beacon maintained; terminal COMPLETE with successor `M5-CP3-DEFN-R1` is reserved for the final repository mutation. |
| Pushed to origin, branch in sync | Durable Review/plan/docs are transported to the working branch; final branch-head verification is performed after cleanup before the terminal `STATUS` write. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** The trigger was honoured, the corrected accounting was adopted, and the successor is a
genuine definition turn rather than a relabelled Code + Build. Accounting holds at **51 events / 14 categories /
37 recurrences**, debt **3**. One gap in the freeze criteria is recorded.

### V1 — the trigger fired and was honoured on its terms

`M5-CP3-TB1-R13-REV-OBS-01` pre-committed that if CB16 did not bring produced rows 4 and 5 green, the successor
must be a definition reconciliation and **`CB17` is prohibited**. CB16 did not, and §61 discharges the
observation **as triggered**, with `CB17` explicitly barred and `M5-CP3-DEFN-R1` frozen instead. Stating that
trigger while CB16 might still have succeeded is what made it a rule rather than a retrospective judgement.

The corrected accounting from R13 — **51 / 14 / 37** — is carried at §§65 and 91 without re-litigation. R14 is
correctly not a further event: selector430 is **430/430**, so no accepted-prefix ordinal transitioned PASS → RED.
Rows 1/2/3/6 and ordinal 408 are PASS, so the two debts discharged at R7 and §16's `R = 0` reduction remain
intact; debt stays **3** with no credit taken for CB16's two added mechanism identities.

### V2 — the diagnosis vindicates the structural reading, and says so plainly

§51 is the sentence that settles the argument I raised at R13: **"No frozen M5 definition currently specifies the
exact change of gauge between those two representations"** — A1's directed source-face transition on the removed
carrier, and the cut-open endpoint representation. That is not a fourteenth bug. It is the missing model whose
absence produced six consecutive distinct gauge defects, each fix relocating the inconsistency rather than
removing it.

`M5-CP3-TB1-R6-REV-OBS-01` also correctly remains **OPEN** (§63): row 4 still stops before the Forward → Reverse
comparator and inverted-pair rejection. That observation has now survived two opportunities to be closed on
by-construction grounds, which is the outcome I reopened it for.

### V3 — DEFN-R1 is a real definition turn

The plan is runtime-free with no product, test, fixture, selector, benchmark or build mutation, and its stop
rules bar precisely the shortcuts that failed repeatedly here: free gauge choice, minimum/stable-region
heuristics, pair insertion order, floating search, downstream output inspection. Two falsifiers deserve specific
credit:

- **Direction uniqueness** — "reversing semantic roles yields exactly its **inverse**, not a second candidate
  selected by success" — directly forecloses the failure mode behind my reopened observation: an ordering that is
  merely self-consistent rather than correct.
- **Zero-rotation reduction** — the model must reproduce accepted `R == 0` behaviour, protecting the four green
  produced rows and the two discharged debts.

Requiring the turn to *adjudicate whether the current row4/5 witness is even valid* for relation-gauge nonzero-Z4
credit is also right: after CB9's inadmissible chart, the witness should not be assumed sound merely because it
now runs.

### V4 — GAP: every freeze criterion is internal; none checks the model against an independent derivation

All seven falsifiers test the model against **itself** — closure, uniqueness, storage invariance, `R = 0`
reduction, non-vacuity, translation consistency, stage ownership. A model can satisfy every one of them and still
assign the wrong action in the nonzero case, because internal coherence is not correctness. Nothing in §5 or §6
requires the model to reproduce an **independently derived expected value for a concrete instance**.

Two facts make that gap matter more here than it normally would.

First, this checkpoint's record: thirteen corrections were internally plausible and wrong. What finally worked
was independent derivation — R6's instrumentation localizing the branch from runtime rather than argument, and
R9's `(family, sign)` Z4 algebra proving the old rule admitted only `R = 0`. Internal plausibility has a
thirteen-for-thirteen losing record in this seam.

Second, and more important: **this artefact gets frozen.** Every previous wrong answer cost one Code + Build
turn. A wrong frozen gauge model costs a full amendment sequence to unwind — §16 needed an entire review turn to
establish, and it was a *correct* amendment. The asymmetry argues for one more check before freezing, not after.

**The check is cheap.** Derive, from A3/source authority alone and without reference to the model, the expected
relation action for the existing nonzero-Z4 witness; then require the frozen model to reproduce it. One worked
instance turns "unambiguous" from *self-consistent* into *self-consistent and right at least once*. If the model
cannot be evaluated against even one independently computed instance, that is itself a finding worth stopping on.

Recorded as `M5-CP3-TB1-R14-REV-OBS-01`. This does not block DEFN-R1 from proceeding; it is a condition on the
freeze, in the same form as the pre-commitment discipline that has now held six consecutive times.

### V5 — verification limits

Re-derived from repository bytes: selector430's rows, hash and 427-row prefix; the DEFN-R1 plan's boundary,
falsifier set, stop rules and deliverables. Accepted as reported: R14 artifact hashes, the four-ledger tallies
(11/11, 1/1, 4/6, 430/430 for 446 PASS / 2 RED), routing digests and manifest coverage.

# M5-CP3-TB1-R7 Independent Review Record

**Turn:** `M5-CP3-TB1-R7-REV`
**Boundary:** **runtime-free independent Review**
**Verdict:** **R7 EVIDENCE UPHELD / R1 `RP-01` RECOVERY PROVED / TWO M5 DEBTS DISCHARGED / PRODUCED-WITNESS AUTHORITY DEFECTS PROVED / DIRECTION OBSERVATION CARRIED / CB9 TEST-ONLY CORRECTION FROZEN**
**Exact successor:** `M5-CP3-CB9`

## 1. Reviewed authority and independent evidence

Review re-opened the R7 execution evidence and repository bytes rather than treating the EXEC report as self-proving.
The immutable runtime subject is CB8 candidate artifact `10651055588` / packaged source
`baae6307d189639fdf7d8a0011f5ba5f30de1631`. Candidate ZIP SHA-256 is
`376f61120b4a71dd9747daae8c248fe766bbf899faac0e2f336fc97e57acda96`; root `SHA256SUMS` is **28/28** at
`06f7e6f068a6b390d212da07928b7088918ee675ccd1968355497b8143f598cd`; packaged source archive SHA-256 is
`f75528fe7c9349d76430bbe06ca67e4593cce452107071405ed2c6c7d848143f`.

Authoritative runtime run/job is `35628318067 / 106428116133`, event SHA
`476bd2c9d903aec19b5a2380b158ef01cbc15e95`. Original result/log artifacts are
`10653532089 / 10653437216`, SHA-256
`30f90ab0dce7fc289ade9fd1d079652c61913e663060559e91c1f5975868d33a /
bbc60db8c3c3855d7e68dc97ebd5e23ff3a58f91a47fd534e4c659a5c7f39b65`.
Runtime-free evidence-finalization run/job `35630259806 / 106434543859` published finalized result/log artifacts
`10653953037 / 10654192933`, SHA-256
`45a6c7c3809ad4068119b58ec061e30832202f6880e7a26ba517500a23b457d2 /
594edca8030333303ec64c6099cae9e23f8a733f82fb9b3c2d3783a17849f4a5`.
Review independently verifies the finalized recursive self-manifest **918/918** at SHA-256
`3318a61ee993a9022141457fe0efacf8334013e0d6a9708a8537ec1358c39fb5` and confirms that the finalizer executed
no candidate runtime.

The Review source/document snapshot is run/job `35636934158 / 106456604121`, artifact `10656048772`, exact
event/source `70fcc68b88238b76ee263b88b79c60bbd79e219a`, provider SHA-256
`c00425b8f3becda5705dcaaff7f7e424f9b26f60f82cbbb40b0e43af2d5a5e59`, source archive SHA-256
`f65a298bd9d18d1eab9699a96a18a3592ab299e64c707b51c95e9f72f08b9573`, **5299/5299** snapshot entries and
`runtimeExecution=false`.

## 2. Mechanical gate and immutable postflight are upheld

Review independently re-parses all four ledgers and raw-result hashes. All **446/446** planned exact-filter
processes executed organically with selected count exactly one and skip count zero:

| Gate | PASS | RED | Review disposition |
|---|---:|---:|---|
| reviewed mechanism | **9/9** | 0 | upheld |
| focused retained-value atlas control | **1/1** | 0 | upheld |
| produced torus | **3/6** | 3 (4/5/6) | upheld; causes re-derived below |
| selector430 | **430/430** | 0 | upheld |

Benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-
mutation counters are all zero. Package, packaged-source and execution-view byte+mode censuses are identical
before/after; candidate manifest remains **28/28** after runtime.

Review re-hashes selector430 directly from repository bytes as 430 unique LF-terminated rows at
`1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 is
`f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. Independent source-owner parsing gives
**31 authority / 283 producer / 75 completion / 41 validation = 430** with one owner per identity. Protected
ordinals 191, 192, 247 and recovered ordinal408 are all PASS. Routing identity-map authority remains
`7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`.

## 3. The CB8 recovery is proved and the stable R1 event closes recovery-proved

The pre-committed CB8 falsifier is satisfied exactly: **zero** produced rows report
`PeriodicGeneratorRouteUnavailable`. Produced rows 1–3 now reach relation publication/ownership, storage-order
permutation, and typed missing-owner rejection; accepted selector ordinal408 returns to PASS in the same complete
runtime gate. The earlier accepted-prefix PASS→RED event therefore has fresh full-gate recovery evidence and
independent Review adjudication.

`M5-CP3-TB1-R1-CAND-01 / RP-01 AUTHORITY_DOMAIN_CONFLATION` is now **CLOSED / RECOVERY PROVED**. The event remains
in the stable historical ledger; closure does not decrement accounting. R2/R3/R4/R5/R6 remain continuations of
that one event, not additional stable recurrences. Stable totals stay **50 events / 14 categories / 36
recurrences**.

`M5-CP3-TB1-R5-REV-OBS-01` is correspondingly closed as recovery-proved. `M5-CP3-TB1-R2-REV-OBS-01` is also
**DISCHARGED**: R7 proves successful production consumption of the atlas-owned hard-feature transition value on
rows 1–3 while the focused atlas control simultaneously re-proves that the hard feature has a retained directed
value without becoming traversal adjacency.

## 4. Produced rows 4–6 are test-authority defects, not evidence for another production edit

R7 advances beyond the generator-route defect, but its remaining three RED rows do not establish a product defect.
Review re-derives two independent witness-precondition failures.

### 4.1 Rows 4/5 assume a nonzero-Z4 source transition that the committed torus field does not contain

Rows 4 and 5 search the **produced relation table itself** for any action having both nonzero quarter-turn rotation
and nonzero translation, then fail before their intended materialization/tamper discriminators when no such
relation exists (`tests/SurfaceCellTransitionQuotientTests.cpp` lines 2083–2150 in the reviewed snapshot).
That search is not an independent source oracle for the §8.2 `G4-B003` precondition.

Review independently re-derives the field transition authority from the committed fixture bytes:

- `benchmarks/fixtures/milestone-g/torus.obj`: SHA-256
  `8a6e0b63382a5eab8b02dc6e07f35e1611c736bf9c5744533fcee573de84c1d8`, topology **72 / 216 / 144**;
- `benchmarks/fixtures/milestone-g/torus.rawfield`: SHA-256
  `25dddeb56f19122833643d6092b862e6777e9e2be9aa2853dfa445c36fd02dbe`;
- raw directions are projected into the exact per-face tangent frames and matched with the same discrete
  `principal_matching` rule used by cross-field finalization;
- all **216/216** closed-torus interior source edges resolve to matching/Z4 value **0**;
- all **18/18** row408 hard-feature edges named by the retained minor/major cycles are therefore also Z4 **0**.

`FieldTransportAtlas` publishes the validated interior-edge transition from that exact matching by
`QuarterTurn::from_integer(raw.matching)`. Reversing edge/face orientation cannot turn zero into a nonzero quarter
turn. Consequently the current row408 torus/rawfield subject contains no genuine nonzero-Z4 transition for
production to carry. Row4's missing relation and row5's failure to reach tamper are therefore
**`RP-02 / TEST_AUTHORITY_COVERAGE_GAP / WITNESS-PRECONDITION / NON-STABLE / +0`**, not proof that production
silently zeroed an existing nonzero source transition.

### 4.2 Row6's purported unused relation is already a produced relation

Row6 constructs `r_unused` by swapping the first produced owner's `route()` and `cutRoute()` and then asserts the
resulting semantic ID is absent before insertion (`tests/SurfaceCellTransitionQuotientTests.cpp` lines
2152–2186). R7 fails exactly at that absence assertion. The direct CP1 helper happened to make the same transform
produce an absent ID; the produced torus table does not guarantee that property and in R7 it already owns the
swapped semantic relation.

Frozen §7 requires an **independently valid relation that is not referenced by the selected certificate**. It does
not authorize “swap the first owner” as an absence oracle. This is a second
**`RP-02 / TEST_AUTHORITY_COVERAGE_GAP / NON-VACUOUS UNUSED-WITNESS PRECONDITION / NON-STABLE / +0`**. The product
factory permits valid unreferenced relations; the test must first construct and prove one whose semantic ID is
absent and unowned rather than weakening the invariant.

No new stable event/category/recurrence is recorded for rows 4–6 because all three are newly authored candidate
witnesses outside the accepted selector and no accepted selector identity regressed.

## 5. `M5-CP3-TB1-R6-REV-OBS-01` remains open: R7 cannot falsify face-direction inversion

CB8 correctly retains exact A3 occurrence-owned `sourceFace` authority and validates that the two resolved faces
are exactly the carrier's incident pair. However, the reviewed source still determines the generator route's
`TransitionStep::orientation` from the canonical source-path parameter direction while the directed atlas query
uses the independent `fromOccurrence -> toOccurrence` order passed by the hard-rail pair. The membership check is
explicitly unordered. Nothing in that block proves that pair storage order is the direction corresponding to the
canonical source-path step.

That is exactly the R6 Review observation: membership is necessary but does not prove direction. R7 cannot close
it dynamically because the committed torus field has Z4 zero on every edge, so forward and inverse quarter-turn
are identical at the rotation level. Successful relation publication therefore does not discriminate correct
from inverted face direction.

`M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN / FALSIFIER NOT SATISFIED / NON-STABLE**. This Review does not guess a
product correction. CB9 must first create a source-authoritative, genuinely nonzero-Z4 produced witness and an
independent A3/source-path direction oracle. If fresh runtime then proves an inversion, only the following Review
may authorize a production edit.

## 6. Debt credit, promotion and publication

Frozen §8.2 debts 1 and 2 are now discharged on direct production authority:

1. **`PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` — DISCHARGED.** R7 produced row1
   independently proves at least **2 distinct canonical produced relations** and at least **2 owned periodic
   edges**; row2 proves relation-table storage permutation preserves the selected certificate/materialized output.
2. **`MissingPeriodicRelationOwnerIsRejected` — DISCHARGED.** The same row408-class produced authority is
   established by row1 and row3 removes exactly one owner from a produced periodic edge and receives the frozen
   typed `MissingPeriodicRelationOwner` rejection.
3. **`FullPeriodicRotationAndTranslationMaterialize` — OPEN.** R7 row4 lacks the required genuine nonzero-Z4
   source witness.
4. **`TamperedFullPeriodicTransformIsRejected` — OPEN.** R7 row5 shares the missing nonzero-Z4 precondition and
   never reaches the tamper discriminator.

The separate M6 closed-complex debt remains open. Project produced-witness debt therefore changes **5 → 3**:
**2 M5-owned + 1 M6-owned**. This is debt credit, not candidate promotion. The two credited identities must remain
green in every later cumulative M5 gate; a future regression can reopen evidence but the historical proof is not
erased.

Candidate `10651055588` remains **unpromoted** because the pre-publication gate is semantic RED. Accepted runtime
authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430
**430/430**. `M5-CP2-TB1-REV-OBS-01` remains **CARRIED**: frozen §13.3 forbids selector precommitment until one
complete corrected pre-publication gate is independently accepted green. R7 is not that gate.

No frozen-definition amendment is required. The definitions already require a genuine nonzero-Z4 produced
subject, an independently unused relation, and the publication sequence that blocks precommitment on semantic
RED. No new `LESSONS.md` item is required: both R7 candidate defects are concrete instances of existing
independent-oracle/non-vacuity rules and `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`.

## 7. Bounded successor frozen for `M5-CP3-CB9`

Exact successor is runtime-free **`M5-CP3-CB9`**, test-authority only. The complete scope and stop rules are in
`Architecture_M5_CP3_CB9_Produced_Witness_Authority_Correction_Plan.md`.

CB9 may change only `tests/SurfaceCellTransitionQuotientTests.cpp`. It must:

1. replace rows4/5's product-table search precondition with a deterministic torus source-field witness whose
   finalized source transition authority proves at least one exact row408-class generator carrier has genuine
   nonzero Z4 **before** product relation inspection;
2. derive the expected directed quarter-turn from exact A3 occurrence/source-path orientation, so R8 can falsify
   the still-open direction observation rather than merely check unordered incidence;
3. make rows4/5 consume that preselected witness, with row5 reaching the stable-ID transform tamper and exact
   `NonReciprocalPeriodicRelation` rejection;
4. replace row6's swapped-owner assumption with a deterministically constructed valid relation whose semantic ID
   is independently proved absent, unowned and unselected before insertion;
5. preserve product source, committed fixture bytes, selector430, frozen definitions, CMake target membership and
   all accepted test expectations.

Mandatory GMP/GMPXX compile/package remains runtime-free. Compile-green routes to a fresh immutable R8 gate over
the same **446** identities. CB9 must stop rather than edit product code if a genuine nonzero source transition or
independent unused relation cannot be proved from source authority.

## 8. Consolidation disposition

R7 Review folds the now-superseded R6 runtime/Review, consumed CB8 plan/report, and consumed R7 execution
plan/report into `M5_Consolidated_Record.md`. Their durable runtime identities, causal chain, observations,
accounting, debt disposition and successor falsifiers are retained in that consolidated record, this Review,
tracker/changelog and git history. Byte-frozen selectors and frozen definitions are not consolidated or edited.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector430 is 430 unique LF-only rows at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; exact first427 is `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`. |
| Decisive claims independently re-derived | Recomputed selector owner census `31 / 283 / 75 / 41 = 430` with one owner per identity; verified finalized result manifest **918/918**; re-counted 446 ledger rows and outcome vector; recomputed torus topology **72/216/144**, fixture hashes, and the exact `principal_matching` construction over all 216 source edges, obtaining Z4 **0 on 216/216** and on all 18 row408 hard edges; inspected rows4-6 source preconditions and CB8 directed-incidence code path. |
| Non-vacuity checked | Rows1-3 reach their intended production contracts. Rows4/5 are not accepted as product evidence because their required genuine nonzero-Z4 source precondition is false. Row6 is not accepted because its purported unused semantic ID is already present before insertion. The carried direction observation remains open because zero Z4 cannot distinguish forward from inverse. |
| Prior obligations discharged/carried | `M5-CP3-TB1-R5-REV-OBS-01` closed recovery-proved; `M5-CP3-TB1-R2-REV-OBS-01` discharged; `M5-CP3-TB1-R6-REV-OBS-01` carried to CB9 -> R8 Review; `M5-CP2-TB1-REV-OBS-01` carried until an independently all-green corrected CP3 pre-publication Review. |
| Stable accounting | **50 events / 14 categories / 36 recurrences**; project debt **3**; accepted package/source stays `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**; candidate `10651055588` remains unpromoted. |
| New candidates/obligations recorded | `M5-CP3-TB1-R7-CAND-02` and `M5-CP3-TB1-R7-CAND-03` recorded as non-stable `RP-02 / TEST_AUTHORITY_COVERAGE_GAP` witness work; tracker updated. No new stable event/category/recurrence. |
| ORIENTATION currency line | Updated to `M5-CP3-TB1-R7-REV`, 2026-09-21 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated current M5 state and debt/accounting (§3), torus witness disposition (§4), reordered open work with CB9 first and discharged items removed/marked (§7), and added the two R7 RP-02 recurring-pattern instances (§8). |
| CHANGELOG | Added one newest-first R7 Review entry with runtime authority, recovery, debt, witness classifications, carried direction observation and exact successor. |
| ROADMAP | Updated both the top milestone table and detailed M5 checkpoint state to R7 Review complete / CB9 next, debt **3**. |
| Selector manifest | n/a — Review neither added nor accepted a selector; selector430 remains byte-frozen authority. |
| LESSONS | No new lesson: existing independent-oracle, non-vacuity, authority-domain and test-authority rules cover both findings. |
| Consolidation under CLEAN_UP_POLICY | Folded and indexed six superseded/consumed M5-CP3 per-turn documents into `M5_Consolidated_Record.md`; retained current R7 Review, exact CB9 plan, frozen definitions and all selector files. |
| Successor frozen | Exactly `M5-CP3-CB9`; its test-only scope, static/source falsifiers, mandatory GMP compile gate, stop rules and exact R8 gate are frozen in `Architecture_M5_CP3_CB9_Produced_Witness_Authority_Correction_Plan.md`. |
| Turn boundary held | Yes — runtime-free Review; no product, test, fixture, selector, benchmark or build-source mutation. |
| review_check.py boundary | **PASS** on the final local documentation/consolidation worktree before publication. |
| `STATUS` lifecycle maintained | Entry and resume beacons maintained for `M5-CP3-TB1-R7-REV`; final COMPLETE beacon with successor `M5-CP3-CB9` is the terminal control write after publication and cleanup. |
| Pushed to origin, branch in sync | **CONFIRMED.** Durable Review/consolidation bytes were published to the configured working branch; post-cleanup branch/tree verification found only the seven durable workflows and no connector-trigger, workflow-observation or turn-payload state. The late duplicate closeout caller/trigger was diagnosed as stale against already-published intended paths and removed without semantic mutation. |

## Independent verification addendum (reviewing agent)

The decisive Review result is not that R7 has “three remaining product failures.” It has one completed product
recovery plus three candidate test rows whose own prerequisites are false or unproved. The committed torus field
is especially discriminating: exact source re-derivation shows every edge transition is Z4 zero, so no downstream
product assertion can establish a missing nonzero-Z4 relation from this subject. That simultaneously explains why
rows4/5 cannot earn debt credit and why R7 cannot close the R6 face-direction observation.

Likewise, row6's failure is at its own absence assertion, before insertion/materialization. Treating either result
as permission to edit production would repeat the exact test-authority error class already tracked as RP-02.
The bounded next step therefore repairs only the witness/oracle surface and deliberately leaves the product bytes
unchanged until a discriminating runtime can say whether a product direction correction is actually necessary.

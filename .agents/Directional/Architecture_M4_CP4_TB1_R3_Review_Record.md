# M4-CP4-TB1-R3-REV — independent Review record

**Turn:** `M4-CP4-TB1-R3-REV`
**Decision:** **APPROVED WITH AMENDMENTS / R3 EVIDENCE TRUSTWORTHY / CANDIDATE NOT PROMOTED / DEFINITION RECONCILIATION REQUIRED**
**Reviewed candidate:** artifact `10578784752`, exact compiled source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`
**R3 runtime:** run/job `35427068822 / 105854843699`, result/log artifacts `10579672178 / 10579602228`
**Accepted M4 authority retained:** package `10565723112`, source `6fe075f7d9397a561fe50b79517b4f714fb9eeef`, selector427 `427/427`
**Reviewer independence:** primary runtime bytes, focused source, frozen definitions and accepted authority were independently reopened/re-derived; no generated Directional runtime was executed in Review.

## 1. Evidence reviewed

- R3 immutable result/log artifacts and complete 433-row ledger/raw logs.
- Candidate package/source/control identity from the R3 report and package receipts.
- Exact selector427 bytes, 427 LF rows, owner partition `30 / 281 / 75 / 41`, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
- `Architecture_M4_CP4_Frozen_Definitions.md`, especially §§3.1-3.3, §6 and §8.
- R2 Review findings, CB4 corrections, R3 runtime report and the current production/test source at a source snapshot whose semantic source/test surfaces are unchanged from candidate source `c2224f6...`.
- Product periodic-authority construction in `src/geometry/SurfaceCellTracing.cpp`, field-atlas validation order in `src/authority/FieldTransportAtlas.cpp`, and the three corrected CP4 focused tests.

## 2. Independent runtime-evidence verification

R3 is mechanically trustworthy. It consumed the declared immutable package without rebuild/repair and completed all **433** planned fresh exact-filter processes:

- focus: **2 PASS / 4 RED**;
- selector427: **427/427 PASS**;
- total: **429 PASS / 4 RED**;
- exactly one selected identity per executed row, zero skips;
- benchmark count `0`;
- configure/compile/relink/discovery/package-repair/mode-repair/source/test/fixture/selector mutation counters all `0`;
- mandatory package/source/execution-view postflight completed byte-identically;
- `stop_reason=semantic_red_focus_2` correctly preserves the first semantic non-green while all six focused rows still executed.

This accepted-prefix result establishes **no accepted-green loss**. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

## 3. Focused adjudication

### 3.1 Row1 — work/boundedness receipt

**PASS / reviewed credit retained.** No new finding. The focused identity executes the already frozen work-receipt/independent-validator contract and does not affect the four remaining REDs.

### 3.2 Row2 — produced closed-complex candidate extraction

**R2 parser defect closed; R3 reachability finding remains OPEN / TEST-AUTHORITY WITNESS REACHABILITY / NON-STABLE.**

CB4's `(degree, faceCount)` rawfield correction is runtime-proved: the old `Invalid rawfield fixture header` stop is gone. The current test-local `produced_closed_torus_arrangement()` then runs a generic fail-closed/recovery-disabled/retain-intermediates torus and stops at `NotProductionReady/tracing` before retained arrangement authority exists.

Frozen §3.1 requires *a* closed source that reaches a retained incidence-valid arrangement without fallback/recovery; it does not freeze this generic torus setup as the unique subject and it already says to stop rather than substitute a synthetic complex when the chosen subject does not reach. Static review therefore does **not** establish a product defect. The current fixture/test authority has not yet proved the required production precondition. `M4-CP4-TB1-R3-CAND-01` remains open for the first post-definition Code + Build turn, which may align only the test-local production precondition to already accepted production authority while preserving the independent candidate oracle/tamper and all fail-closed/no-recovery rules.

The first `G4-B002` debt remains open.

### 3.3 Rows3/4 — produced periodic relation ownership

**R2 generic-torus precondition defect closed; R3 finding is OPEN / ARCHITECTURE-DEFINITION / SAME-SHEET PERIODIC-BASIS REPRESENTATION / NON-STABLE.**

CB4 faithfully applies the accepted row408 hard-rail setup. R3 proves both focused subjects reach `SurfaceCellProducerDisposition::Produced`, so the original R2 test-precondition diagnosis is resolved. The tests then independently inspect the *produced* relation table, not the two injected cut cycles, and find **zero** `periodicHolonomies`; `M4-CP4-TB1-R2-REV-OBS-02` is therefore discharged rather than violated by a self-authorizing oracle.

The deeper failure is definition/architecture sequencing, not another fixture alias:

1. `build_periodic_annulus_phase_front_for_faces(...)` explicitly defers to the bounded curved producer when the immutable A3 plan and hard rails are present; that row408-aligned path therefore does not publish periodic-annulus relation authority.
2. The periodic-annulus producer itself constructs one `PeriodicRelationId::from_index(0, 1)` for its annular subject.
3. `insert_periodic_holonomy(...)` intentionally returns `AmbiguousBasis` for a second distinct relation in the same `sourceTopologyRegion`, with the source comment that distinct same-sheet cycles require a later topology-basis solver rather than discovery-order ownership.
4. The design treats HardRail/shared-boundary authority and explicit periodic relation authority as distinct relation kinds; a hard rail cannot silently be renamed a periodic relation to satisfy the test.
5. M5 already owns certificate-carrying chart/quotient relation work, while the current CP4 definition assigns two periodic `G4-B002` debts to M4.

That is a real ownership/expressibility conflict. Frozen §3.2's explicit stop-to-Review/DEFN clause has fired. Review does **not** weaken the `>=2` produced-relation requirement, does not infer multiplicity from two authored cycles, does not substitute direct/draft authority, and does not re-home debt by fiat. `M4-CP4-DEFN-R1` must reconcile whether a bounded M4 same-sheet two-generator basis/owner representation can be defined without stealing broader M5 semantics, or whether those debts must be explicitly re-owned by M5 with the M4 exit theorem amended. Until that definition decision, both periodic `G4-B002` debts remain open and M4-CP4 remains open.

### 3.4 Row5 — produced same-region multiplicity-2

**PASS / reviewed credit retained.** `M4-CP3-TB1-R1-REV-OBS-01` remains discharged. No duplicate obligation is created.

### 3.5 Row6 — zero-transport non-flat precondition

**R2 planar-witness defect closed; R3 finding remains OPEN / TEST-AUTHORITY TYPED-EXPECTATION / NON-STABLE.**

CB4's replacement fan is genuinely non-flat: R3 independently reaches the nonzero apex-angle-defect assertion, flat zero-transport succeeds, and the non-flat zero-transport subject rejects. The original `M4-CP-SCALE-TB2-REV-OBS-02` contract was a precondition audit; it did **not** freeze `CycleTransportMismatch` as the only legal code. That carried observation is therefore **DISCHARGED** by R3 runtime plus this Review.

Static source establishes the typed ordering: `FieldTransportAtlas::make(...)` computes exact cycle lifts and returns `NonIntegralCycleLift` when a lift is non-integral **before** composing quarter-turn transport and checking `CycleTransportMismatch`. The current zero-effort non-flat witness reaches that earlier, more specific failure. The focused test's expected `CycleTransportMismatch` is thus too specific for the witness it constructs, not evidence of a product validation-order defect.

The later Code + Build correction must preserve a precise typed assertion: expect `NonIntegralCycleLift` for this exact witness. It must not weaken to “any failure.” A distinct integral-lift-but-composition-mismatch subject would be appropriate only if a future contract specifically needs to exercise `CycleTransportMismatch`.

## 4. Prior obligations and candidate disposition

| ID | Review disposition |
|---|---|
| `M4-CP4-TB1-R2-REV-CAND-01` | **CLOSED / CORRECTION RUNTIME-PROVED / NON-STABLE.** Parser-format defect is gone; separate R3 reachability candidate remains. |
| `M4-CP4-TB1-R2-REV-CAND-02` | **CLOSED / CORRECTION RUNTIME-PROVED / NON-STABLE.** Row408-aligned setup reaches `Produced`; separate architecture-definition candidate remains. |
| `M4-CP4-TB1-R2-REV-CAND-03` | **CLOSED / CORRECTION RUNTIME-PROVED / NON-STABLE.** Genuinely non-flat prerequisite is proved; separate typed-expectation candidate remains. |
| `M4-CP4-TB1-R2-REV-OBS-01` | **DISCHARGED.** R3 records the first semantic RED as `semantic_red_focus_2` while still executing all six focus rows. |
| `M4-CP4-TB1-R2-REV-OBS-02` | **DISCHARGED.** R3 derives relation multiplicity from the produced table and reports zero; no multiplicity is inferred from injected cycles. |
| `M4-CP-SCALE-TB2-REV-OBS-02` | **DISCHARGED.** Flat success, genuine non-flat geometry and non-flat typed rejection are all proved; the remaining error-code assertion is a separate test-authority issue. |
| `M4-CP3-TB1-R1-REV-OBS-01` | **DISCHARGED, unchanged.** Row5 remains reviewed green. |
| three `G4-B002` debts | **OPEN.** One produced closed-complex witness and two periodic-authority debts remain unproved. |
| two `G4-B003` debts | **M5-owned, unchanged.** |

## 5. Promotion and checkpoint decision

Candidate package `10578784752` is **not promoted** and CP4 does **not** close. R3 validates CB4's three narrow test-authority corrections but does not satisfy any of the three remaining `G4-B002` produced-witness debts. The accepted M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**.

The Review decision is **approved with amendments**: the R3 evidence and CB4 mechanical corrections are accepted, while the R2 diagnosis is amended to distinguish the newly exposed definition/representation conflict from the two remaining test-authority issues.

## 6. Authoritative successor — `M4-CP4-DEFN-R1`

Exactly one successor is authorized: runtime-free definition reconciliation under `Architecture_M4_CP4_DEFN_R1_Produced_Periodic_Authority_Reconciliation_Plan.md`.

It must decide the periodic produced-authority ownership question before any further corrective Code + Build. It may amend normative definitions, roadmap/ownership records and planning only. It may not edit product/test/fixture/selector/benchmark/build source, compile, or execute generated runtime.

Key falsifiers are frozen in the successor plan: no discovery/container-order basis; no HardRail-by-name substitution for periodic relation authority; no silent weakening of produced multiplicity; no debt deletion/re-homing without an explicit exit-theorem/owner amendment; no expansion into general M5 certificate work if a bounded M4 basis cannot be separated cleanly.

## 7. Engineering-guideline review

- **Material assumptions challenged:** the assumption that a row408 hard-rail `Produced` product should necessarily contain explicit periodic holonomies is false in current product architecture; the assumption that row6 must reach `CycleTransportMismatch` is also false for its non-integral lift.
- **Simpler alternatives considered:** row2 remains a test-witness reachability repair; row6 remains a one-expectation typed test repair. Neither justifies product changes. Rows3/4 cannot be repaired by fixture renaming or assertion weakening because the required representation itself is not currently expressible on one source region.
- **Unrelated/speculative work removed:** no M5 implementation, selector publication, broad periodic refactor, field-atlas product change or new runtime is authorized.
- **Surgical scope confirmed:** successor is definition-only and exists solely to resolve ownership/expressibility before a later bounded Code + Build.
- **Verifiable success criteria confirmed:** the successor must leave exactly one explicit debt owner/representation contract, preserve accepted selector427/runtime authority and publish falsifiers before implementation.

## 8. Consolidation

Durable facts from the superseded/consumed CP4 turn documents listed in `M4_Consolidated_Record.md` are preserved here, in the R3 runtime report, tracker, frozen definitions, ORIENTATION, TODO, ROADMAP and changelogs before those documents are folded. Current retained CP4 roles are: normative frozen definitions; current R3 runtime report; this Review record; exactly one successor DEFN-R1 plan; M4 consolidated record; selectors and durable trackers/policies.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector427 independently re-hashed as `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, 427 LF rows; no new selector is proposed or accepted. |
| Decisive claims independently re-derived | Re-derived the 433-row `429 PASS / 4 RED` partition; row2 helper reachability; row408 hard-rail versus explicit periodic-relation production paths; same-sheet `AmbiguousBasis` limitation; row6 `NonIntegralCycleLift`-before-`CycleTransportMismatch` validation order. |
| Non-vacuity checked | Rows3/4 reach `Produced` and fail on the actual produced relation table, not injected-cycle count; row6 proves nonzero angle defect and typed rejection; row2 fails before its independent oracle and therefore receives no debt credit. |
| Prior obligations discharged/carried | R2 CAND-01/02/03 original defects closed runtime-proved; R2 OBS-01/02 discharged; `M4-CP-SCALE-TB2-REV-OBS-02` discharged; same-region OBS remains discharged; three `G4-B002` remain open; two `G4-B003` remain M5-owned. |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. |
| New candidates/obligations recorded | `M4-CP4-TB1-R3-CAND-01` retained as test-witness reachability; `CAND-02` reclassified architecture-definition/same-sheet periodic-basis representation; `CAND-03` reclassified test-authority typed-expectation. Tracker updated. |
| ORIENTATION currency line | `M4-CP4-TB1-R3-REV`, 2026-09-19 UTC written. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated for R3 Review authority, torus zero-periodic-relation state, DEFN-R1 priority, discharged zero-transport observation and existing representation-capability pattern; superseded R2/CB4-next bullets removed. |
| CHANGELOG | Root and agent changelogs updated with this Review disposition. |
| ROADMAP | CP4 updated to R3 Review complete / definition reconciliation required; M5 ownership remains unchanged pending DEFN-R1. |
| Selector manifest | n/a — selector427 remains byte-frozen and no selector is added or accepted in this Review. |
| LESSONS | Existing `LESSONS.md` lesson 22d applies: verify that the product representation can express the required answer before debugging the algorithm. No new recurring pattern requires a new lesson. |
| Consolidation under CLEAN_UP_POLICY | Folded/indexed five superseded/consumed CP4 per-turn documents: CB4 plan/report, R2 runtime report/Review, and R3 runtime plan. Current R3 runtime report is retained. |
| Successor frozen | Exactly one: `M4-CP4-DEFN-R1`; falsifiers and stop rules are stated in `Architecture_M4_CP4_DEFN_R1_Produced_Periodic_Authority_Reconciliation_Plan.md`. |
| Turn boundary held | Yes — Review is runtime-free; no Directional binary executed and no product/test/fixture/selector/benchmark/build source is changed. |
| review_check.py boundary | **PASS** — `python3 .agents/Directional/tools/review_check.py boundary` reports all Review-boundary, selector-hash and durable-marker checks PASS; no product/test/fixture/build/selector mutation. |
| `STATUS` lifecycle maintained | `Turn=M4-CP4-TB1-R3-REV`; entry/resume state is maintained in root `STATUS`; final COMPLETE / `Successor=M4-CP4-DEFN-R1` / Ended timestamp is reserved for the final direct closeout mutation. Started `2026-09-19T07:32:17Z`; latest attempt resumed `2026-09-19T08:30:37Z`. |
| Pushed to origin, branch in sync | Web/connector equivalent: coherent documentation patch is pushed to the configured branch through verified Drive transport, then branch authority is re-read after workflow-first cleanup; no self-referential commit hash is embedded in this record. |

---

## Independent verification addendum (reviewing agent)

Runtime-free. **Upheld.** The architecture-definition finding is confirmed from product bytes and is correct;
the definition stop is the right call. Accounting holds at **49 / 14 / 35**, debt **5**; selector427 re-hashes
byte-exact at 427 rows. One substantive amendment is recorded for `M4-CP4-DEFN-R1`.

### V1 — the three-part architecture finding is confirmed verbatim

All three links of §3.3 re-derived from `src/geometry/SurfaceCellTracing.cpp`:

1. **Deferral.** `build_periodic_annulus_phase_front_for_faces(...)` (`:12423`) carries the comment "When hard
   rails are governed by the immutable A3 plan, defer to the bounded curved producer instead of recreating
   shared …", guarded on non-empty `options.hardFeatureEdges` and source-edge incidence. Row408's path supplies
   exactly those hard rails, so it never reaches the periodic-annulus producer.
2. **Single relation.** The annulus producer allocates `PeriodicRelationId::from_index(0, 1)` (`:13406`). With
   `from_index(value, extent)` requiring `value < extent` (`include/directional/authority/AuthorityIds.h:179-191`),
   `(0, 1)` is a domain of exactly **one** relation.
3. **Same-sheet refusal.** `insert_periodic_holonomy(...)` (`:6302-6326`) computes
   `sameScope = existing.sourceTopologyRegion() == relation.sourceTopologyRegion()` and returns `AmbiguousBasis`
   for a second distinct same-scope relation, under the comment "This G4 slice intentionally does not guess a
   basis inside one source sheet. Distinct same-sheet cycles require a later topology-basis solver; retaining one
   by discovery order would be unsound."

**Independent corroboration worth recording:** the deferral in (1) *statically predicts* the zero
`periodicHolonomies` that R3 observed at runtime. Two independent derivations — product control flow read
here, and the produced relation table read by the focused tests — agree. That is much stronger than either alone,
and it is why the "not another fixture alias" conclusion holds.

`M4-CP4-TB1-R2-REV-OBS-02` is correctly **discharged**: the tests read multiplicity off the produced table and
report zero, rather than inferring two relations from the two injected cycles. The hazard I recorded last turn
did not materialise.

### V2 — row6's typed ordering is confirmed

In `src/authority/FieldTransportAtlas.cpp`, `NonIntegralCycleLift` is returned at `:2457`, ahead of both
`CycleTransportMismatch` sites at `:2520` and `:2630`. A witness whose lift is non-integral therefore stops at
the earlier, more specific code. The Review's instruction is right and must be kept precise: the corrected test
expects **`NonIntegralCycleLift`** for this exact witness and must not weaken to "any failure".

Discharging `M4-CP-SCALE-TB2-REV-OBS-02` is also correct — that obligation was a *precondition* audit, and R3
proves flat success, genuine non-flat geometry and typed non-flat rejection. The residual error-code assertion is
a separate, narrower test-authority item. This closes the audit I first raised at CP-SCALE-TB2.

### V3 — AMENDMENT FOR `M4-CP4-DEFN-R1`: the A/B binary omits a path the product already supports

§2 of the successor plan offers exactly two readings — **A**, freeze a bounded M4 *same-sheet* two-generator
basis; **B**, re-home both debts to M5 and amend the M4 exit theorem. Reading A is titled "same-sheet", and
Reading B fires "if same-sheet basis identity cannot be defined". **Both presuppose that the two generators must
live in one `sourceTopologyRegion`.**

The product does not require that, and says so explicitly at `SurfaceCellTracing.cpp:6325`: *"Multiple relations
on distinct authoritative sheets/components remain valid and are kept."* The mechanism is present and verified —
when `!sameScope` the loop `continue`s rather than refusing, and `:6328-6349` then allocates a **distinct** id
from the occupied typed-ID set (`ownerExtent = relations.size() + 1U`, first unoccupied index wins), with
existing owners explicitly stable under container reordering.

Frozen §3.2 requires "at least two distinct periodic relation IDs and at least two periodic edges resolving
through typed ownership" on the produced torus. As written it does **not** demand one region. So a third reading
exists:

> **Reading C — two relations on distinct authoritative sheets.** If the produced torus phase-front decomposes
> into two or more distinct `sourceTopologyRegion`s, each carrying one relation, §3.2's `>=2` is satisfiable in
> current architecture with **no** basis solver, **no** weakening, and **no** re-homing. The remaining blocker
> would be only the hard-rail deferral in (1) — a narrower, bounded question than either A or B.

I cannot settle runtime-free whether a produced torus actually yields `>=2` such regions; a two-generator torus
basis is *naturally* same-sheet, so Reading C may well fail on the facts. That is exactly why it must be
**determined and recorded, not assumed away**. Reading B is the heaviest and least reversible option on the
table — it re-homes two produced-witness debts across a milestone boundary and amends a frozen exit theorem — and
it should not be reached while a cheaper path the product's own source advertises remains unexamined.

**Required of `M4-CP4-DEFN-R1`:** before selecting A or B, explicitly determine and record whether the produced
torus phase-front yields two or more distinct `sourceTopologyRegion`s capable of carrying one periodic relation
each. If yes, evaluate Reading C on its merits. If no, say so with the evidence — and then A/B is the correct
binary. Recorded as `M4-CP4-TB1-R3-REV-OBS-01`.

This does not weaken any prohibition in §3 of the plan: Reading C derives multiplicity from produced sheet
decomposition, never from the two authored hard-rail cycles, never from discovery or container order, and never
by renaming a `HardRailMerge` a periodic relation.

### V4 — verification limits, stated

Re-derived independently from repository bytes: all three architecture links and their comments; the
`from_index` extent contract; the distinct-id allocation loop; the `NonIntegralCycleLift` /
`CycleTransportMismatch` ordering; selector427's 427 rows and SHA-256.

Accepted as reported, not re-derivable runtime-free: the 433-row `429 PASS / 4 RED` partition, run/job and
artifact identifiers, package receipts, postflight byte-identity, and `stop_reason=semantic_red_focus_2`. The
`stop_reason` fix discharging `R2-REV-OBS-01` is consistent with what CB4 was authorized to change.

The closeout block is complete and every row is answered — including the honest "n/a" on the selector manifest.

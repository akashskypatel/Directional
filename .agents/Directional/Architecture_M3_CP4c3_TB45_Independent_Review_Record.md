# M3-CP4c-3-TB45 Independent Review Record

**Status:** COMPLETE / TB45 PROMOTED / TWO TEST-AUTHORITY CORRECTIONS + ONE DIAGNOSTIC FOLLOW-UP / CB51 FROZEN
**Turn:** `M3-CP4c-3-TB45-REV`
**Review boundary:** evidence/static-review + planning only; no compile, runtime, benchmark, fixture execution, selector mutation, or product/test semantic mutation in this turn.

## EG0 — evidence integrity and promotion

TB45 is mechanically valid artifact-only evidence for immutable package110:

- exact source `46554ef2bc1b36fff100e4de0a274a0fb6d3f26d`;
- package artifact `10095738820`, provider SHA-256 `7edc47632dbd863508c97d5716dd9df5e469671e0b327a133848ff3c37142000`;
- packaged source archive SHA-256 `8ae8fcd115c5b150642ad090272a001de89520d28ba69c2564cd476473374e80`;
- selector409 SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- run/job `34357709483 / 102486495110`;
- result/log artifacts `10106632656 / 10106633518`, provider digests
  `15327d9f3211f9b28b358e380b9b19917813362982f0b8cb94422b4518eff18a` /
  `2d4a0b0dd975f8f50a3b7e9161f67a71ccf2de5c46494c8c7715228dd3e23db8`;
- **399 PASS / 10 RED / 0 SKIP**, accepted **365/365**, RED
  `[367,368,369,370,374,390,393,398,406,407]`;
- zero selection mismatch and timeout; all 409 identities ran exactly once in fresh processes;
- package/source/execution-view byte+mode censuses are equal pre/post;
- no configure, compile, relink, regeneration, repair, mutation, or benchmark occurred.

**Verdict:** promote **TB45/package110/selector409** as current semantic runtime authority. Promotion means this is
the latest valid semantic ledger; it does **not** convert its ten REDs into acceptance and does not claim that
390/393/406/407 re-proved Part XII. Accepted 1–365 remains the gate floor at 365/365 and every RED remains explicitly
owned.

Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**, packages
**110**, certified ownership **300 established / 0 unavailable / 0 conflicting**.

## EG1 — ordinal366 proves the CB50 source-corner fan correction reached its intended old locus

TB44's `FragmentCornerSourceCornerMismatch` surface disappears. TB45 ordinal366 is PASS, and ordinal367 contains
none of the old mismatch/duplicate-ordinal/orbit-chain failure tokens. This is positive evidence that CB50 stopped
treating all carrierless rays on one source face as one source-corner fan without weakening the accepted prefix.

`M3-CP4c3-TB44-EXEC-CAND-01` therefore advances as intended. No new stable event is created: this is continuation
of the already-owned fragment-corner projection correction above the accepted prefix.

## EG2 — ordinal367 is a stale independent-oracle predicate, not a new product regression

Ordinal367 now reaches the independent rotation/face-walk oracle and stops at
`partition.has_value()==false / FragmentPartition`.

Static review establishes the disagreement:

1. `independent_fragment_partition()` independently derives forward/reverse face-walk owners for every trace arc.
2. It nevertheless drops **every** final no-barrier trace segment solely because it is a syntactic terminal slit.
3. The frozen product contract no longer does that. `build_regions()` retains a terminal segment when its two
   independently walked sides have different certified-face orbits and skips it only when it is non-separating.
4. The CB49/CB50 fragment-corner path follows the same separation distinction.
5. The independent oracle's unconditional skip therefore encodes the retired over-broad terminal-slit rule. Its
   `FragmentPartition` failure is expected oracle drift after the product correction, not proof of a new product
   failure.

**Classification:** `M3-CP4c3-TB45-EXEC-CAND-01` is **CLOSED / TEST-AUTHORITY ORACLE DRIFT /
INCORRECT EXPECTATION / NON-STABLE** with high confidence.

The correction must preserve independence: the test may use the orbit IDs it already derives independently and
skip the final no-barrier segment only when those independently derived forward/reverse orbits are equal. It may
not call a product-owned convenience predicate or copy a product result merely to agree.

This is an instance of the already-recorded authority lesson: an independent oracle is independent in derivation,
not exempt from the current normative contract.

## EG3 — 390/393/406/407 fail on an obsolete failure-required fixture precondition

All four protected identities now stop at:

`ASSERT_FALSE(mechanical.plan.has_value())` → actual `true`.

The assertion was a transport mechanism for reaching failure-envelope diagnostics, not a Part XII invariant. Part
XII R8.4 requires the real producer census, the same-domain corruption negative, and the typed subject relation; it
does **not** require a production plan to fail.

CB50 lawfully advanced the mechanical witness to a successful `GlobalTopologyPlan`. Requiring failure after that
progression is an incorrect expectation. Forcing a new failure, weakening the plan, or selecting a deliberately
broken fixture would invert the test's purpose.

**Classification:** `M3-CP4c3-TB45-EXEC-CAND-02` is **CLOSED / TEST-AUTHORITY FIXTURE-PRECONDITION +
OBSERVABILITY TRANSITION / INCORRECT EXPECTATION / NON-STABLE** with high confidence.

The four identities remain RED in TB45 and therefore **TB45 does not re-prove their Part XII receipts**. Historical
TB43 remains the most recent runtime proof that 390/393/406/407 execute the producer census and reject same-domain
corruption. That historical proof remains valid; it is not silently attributed to package110.

## EG4 — successful-plan observability is the smallest generalized correction for the protected identities

The producer already constructs `RegionBuildSuccess.frontier` before region certification and carries a persistent
`fragment_owner_evidence()` census into a successful plan. The detailed region-frontier correspondence rows are
currently materialized only while annotating a failure locus.

That makes the protected tests accidentally depend on failure chronology. The correct successor is not another
fixture failure. CB51 must make the already-computed producer frontier evidence observable from a successful plan,
using one shared producer-side row-construction path for success and failure.

Constraints:

- no new partition, owner election, topology decision, fallback, or repair;
- no duplicate reimplementation of `P_U`;
- the successful-plan evidence must be derived from the same `RegionBuildSuccess.frontier` and cut-graph certificate
  that failure annotation already uses;
- failure-path diagnostics remain semantically unchanged;
- 390/393/406/407 consume successful-plan producer data, execute their existing real predicates, mutate a
  same-domain copy, and prove the mutation is rejected;
- a test must not pass merely because `plan.has_value()` changed.

This is diagnostic publication, not a new semantic authority.

## EG5 — TB44 EG10.3 was not discharged by CB50; one site needs correction and one does not

The TB44 verification addendum required explicit adjudication of every consumer of the over-broad
`is_terminal_slit` predicate. CB50's report did not discharge that obligation.

Static review now settles the two previously unadjudicated uses:

- `TraceTerminalSlitCensusDiagnostic{trace.id, terminalSlit}` is a **syntactic trace-termination census**. It does
  not decide fragment count, ownership, partition membership, or separation. The same owner evidence separately
  publishes each arc's forward/reverse orbit and `sharesOrbit`. The narrow syntactic label is therefore intentional
  and remains unchanged.
- The failure-only `fragmentIncidences` builder for `TraceCutFaceFragmentCountMismatch` unconditionally skips a
  terminal slit even though the authoritative `tracePieceCount` includes a terminal segment when
  `forwardOrbit != reverseOrbit`. This diagnostic can therefore omit a real separating incidence from the very
  evidence intended to explain the count. **CB51 must apply the same independently available separation conjunct:
  skip only the non-separating terminal slit.**

This is a bounded diagnostic-consistency correction. It changes no count or control-flow decision.

**Process finding:** CB50's silence on a mandatory static-audit item was a review-contract miss. It is preserved
here and corrected forward; it is not a semantic runtime event.

## EG6 — carried REDs remain independently owned and unchanged

TB45 gives no evidence to merge or reprice the five carried REDs:

| Ordinal | Existing owner | TB45 disposition |
|---:|---|---|
| 368 | prescribed-sphere A2a′ localization / `M3-CP4c2-TB-X2-CAND-04` | unchanged `TraceEventPositionInvalid` chain; no sphere semantic fix authorized |
| 369 | ordinary proposal reachability / `M3-CP4c2-TB-X2-R10-CAND-01` | unchanged saturation-selected path |
| 370 | closed-surface empty-network typed-error owner / `M3-CP4c2-TB-X2-R8-CAND-02` | unchanged |
| 374 | folded-cone invalid field fixture / `M3-CP4c3-TB7-CAND-02` | unchanged, test-only correction remains deferred |
| 398 | prescribed-sphere production cellularity owner | unchanged |

No stable event/category/recurrence change is justified.

## EG7 — frozen CB51 scope and future TB46 falsifiers

The exact successor is **`M3-CP4c-3-CB51`**, Code + Build, runtime-free, under
`Architecture_M3_CP4c3_CB51_Code_Build_Plan.md`.

CB51 owns only:

1. the independent ordinal367 terminal-slit/separation oracle correction;
2. successful-plan publication/consumption of the existing producer-owned Part XII frontier evidence for
   390/393/406/407;
3. the failure-evidence terminal-slit separation correction from EG5.

Future TB46 must use the immutable CB51 package and unchanged selector409. It must not assume a green aggregate.
Required falsifiers are the exact corrected contracts:

- 367 must reach and execute the independent partition/disc oracle without the retired unconditional terminal-slit
  skip; a later independent failure remains reviewable;
- 390/393/406/407 must execute the real producer-owned `P_U` predicates from successful-plan evidence, reject
  same-domain corruption, and publish a non-vacuous receipt;
- accepted 1–365 remains 365/365;
- carried 368/369/370/374/398 retain their owners unless raw evidence genuinely changes them;
- controls 311/312/314/315/356/357/404/408/409 remain PASS, ownership remains 300/0/0, and retired-code silence
  remains.

## EG8 — document consolidation

This REVIEW folds the superseded per-turn documents only after their durable facts are preserved here,
`M3_CP4c_Consolidated_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md`, `TODO.md` and `CHANGELOG.md`.

Folded/indexed:

- `Architecture_M3_CP4c3_TB44_EXEC_Report.md` — superseded runtime report;
- `Architecture_M3_CP4c3_TB44_Independent_Review_Record.md` — superseded review authority;
- `Architecture_M3_CP4c3_CB50_Code_Build_Plan.md` — consumed plan;
- `Architecture_M3_CP4c3_CB50_Code_Build_Report.md` — consumed compile/package report;
- `Architecture_M3_CP4c3_TB45_Artifact_Only_Test_Benchmark_Plan.md` — consumed artifact-only evidence contract.

Retained current per-turn roles are exactly TB45 EXEC report, this TB45 review record, and the CB51 plan, plus
durable project records, normative definitions, and all byte-frozen selector files.

## EG9 — operational review notes

`READ_MODE=snapshot` was selected for this cross-file review and the exact snapshot run was
`34361409282`, artifact `10107990645`, provider SHA-256
`50e6dd50b26d2155e894976df02c37387561485f52e2ee8218179c5fd7739c74`, snapshot source
`438dbd406f70f596ca378fb918e3494f032c6b15`. Local checksum verification was 5221/5221.

The explicit READ_MODE declaration occurred after initial handoff/policy connector reads rather than before the
first repository read. This is a process-order miss, recorded rather than hidden. It has no semantic effect on the
snapshot evidence and creates no regression event.

Publishing the turn-cleanup manifest again auto-triggered the known cleanup workflow trigger-safety defect. That
known deferred hygiene item remains open; it is not repriced as a semantic event.

## Exact successor

**`M3-CP4c-3-CB51` — Code + Build / runtime-free.** No runtime, benchmark, selector change, or unrelated carried
owner work is authorized until CB51 compiles/packages and freezes the next artifact-only TB46 plan.

---

## EG10 — verification-pass addenda (static, appended after adjudication)

A verification pass re-derived EG0–EG9 from source. **The adjudication stands and every load-bearing claim
verifies.**

### EG10.1 — the three decisive claims, confirmed

- **EG5** — `tracePieceCount` is incremented at `GlobalTopologyPlan.cpp:1212`, **after** the `:1194` skip. A
  *separating* terminal slit therefore passes the skip and **does** increment the authoritative count, while the
  `:1417` `fragmentIncidences` builder omits it unconditionally. The inconsistency is real: the evidence intended to
  explain `TraceCutFaceFragmentCountMismatch` can omit an incidence the count includes. CB51's conjunct is correct.
- **EG2** — `independent_fragment_partition()` skips every syntactic terminal slit at
  `tests/FieldAlignedCurveNetworkTests.cpp:2119–2126`, and its comment states the retired rule verbatim: *"the final
  no-barrier continuation is hypothetical and is not one of the k real chords."* Oracle drift, not a product
  regression, is the correct classification.
- **EG3** — `ASSERT_FALSE(mechanical.plan.has_value())` occurs exactly **four** times in the corpus, matching the
  four protected identities precisely.

### EG10.2 — TB44 EG10.3 is discharged, and discharged well

CB50 was silent on it; **this review settled it instead**, with reasoning rather than assertion: `:1336` is a
syntactic trace-termination label whose sibling evidence separately publishes forward/reverse orbit and
`sharesOrbit`, so the narrow reading is intentional; `:1417` is inconsistent with the count it explains and is
corrected. That is the outcome the obligation asked for — *adjudicate, don't inherit* — and the process finding
about CB50's silence is correctly kept non-stable.

### EG10.3 — the canonical consumer table needs a fifth row: the independent oracle

TB44 EG10.3's table enumerated **product** consumers of the over-broad `is_terminal_slit` predicate. EG2 has now
found a **fifth** consumer outside that scope — the test oracle's own re-derivation at
`tests/FieldAlignedCurveNetworkTests.cpp:2119–2126`, which reimplements the predicate syntactically and skips
unconditionally.

That the oracle re-derives the predicate independently is exactly why it drifted: **an oracle is independent in
derivation, not exempt from the current normative contract**, so a change to a normative predicate silently
invalidates every oracle that reimplements it. The canonical table in `Regression_Root_Cause_Tracker.md` is extended
to five rows so the next turn inherits a complete list rather than discovering the sixth the same way.
`LESSONS.md` 165.

### EG10.4 — two dispositions worth preserving explicitly

- **EG3's caveat is right and must not be lost.** TB45 does **not** re-prove the Part XII receipts for
  390/393/406/407; **TB43 remains the most recent runtime proof** that they execute the producer census and reject
  same-domain corruption. Refusing to attribute that proof to package110 is the correct call, and precisely the kind
  of attribution that goes silently wrong later.
- **EG4's constraint is the right shape.** Making already-computed `RegionBuildSuccess.frontier` evidence observable
  from a *successful* plan — rather than manufacturing a failure to reach the diagnostics — removes the tests'
  accidental dependence on failure chronology without inventing a second authority.

### EG10.5 — accounting and promotion confirmed

Accepted prefix held at **365/365** and ordinal **366 cleared**, so **no stable event** is correct; totals remain
**47 / 14 / 33**. Promotion of TB45 / package110 follows the operative rule and is consistent with TB39 onward.

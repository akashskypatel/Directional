# M3-CP4c-1 TB-R4 Independent Review and Plan

## Verdict

`M3-CP4c-1-TB-R4-REVIEW-PLAN` is **COMPLETE / REVIEW GREEN**.

The C5 red is **test-side in both clauses**. The product satisfies the frozen C5 contract on every witness that
produced a trace; nothing in the red is evidence against Directional. `M3-CP4c1-TB-R4-CAND-01` is adjudicated
**RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE**, and a bounded corrective Code + Build,
`M3-CP4c-1-CB4`, is **AUTHORIZED** under measures **W0–W7**.

The interpretive tension the TB turn correctly refused to resolve is resolved here: **the completion wording at
plan line 131 is normative; the "exactly the required terminal event-kind set" phrasing at plan line 101 is a
reporting instruction and is not a cardinality requirement.**

One finding outranks the rest in importance: **clause 1 is a recurrence of `M3-CP4c0b-DG-CAND-02`**, adjudicated
one checkpoint ago as test-side torus over-specification. The lesson did not propagate into the next
checkpoint's test authoring.

No runtime, build, configure, compile, or package operation was executed in this turn. No product, test,
fixture, selector, or build file was modified.

## 1. Evidence independently verified

Verified against the immutable report and the materialized source, not accepted on assertion:

- required selector **355** lines; ordinals 354/355 are exactly C4 and C5, in that order, at the selector tail.
- the accepted prefixes are intact and re-proved **in the same immutable run**: 316/316, 346/346, **353/353**.
  The accepted 353 hash `51ff96d7…ac6a5` and the 346 prefix `20d3b0b1…3e46a` match the values this reviewer
  computed independently in the CP4c-0b arc.
- first red is ordinal **355**; C4 (ordinal 354) is **PASS**; zero/multiple-selected **0**; zero escaping C++
  exceptions; immutable pre/postflight byte-and-mode equal.

**Therefore no accepted authority regressed**, and the red is confined to a never-accepted checkpoint-local
identity. `+0` stable events, `+0` recurrences; totals remain **42 / 14 / 28**, debt **5**, M3 packages **56**.

Terminal-kind enum authority, confirmed from the frozen `static_assert` block in the test source
(`tests/FieldAlignedCurveNetworkTests.cpp:6862-6869`):

| value | kind |
|---:|---|
| 0 | `SingularityPortOrigin` |
| 1 | `FirstContact` |
| 2 | `TraceIntersection` |
| 3 | `MandatoryBarrierTermination` |
| 4 | `SingularityTermination` |
| 5 | `SingularityPortJunction` |
| 6 | `TraceSelfClosure` |

The observed union is `{2, 3, 4}`: sphere contributes `{2, 4}`, two-ring contributes `{3}`. Both are correct —
the sphere is closed and carries no mandatory barriers, so it cannot contribute kind 3; the two-ring terminates
on its mandatory barrier. Nothing anomalous appears in the union.

## 2. Adjudicating the authority tension — line 131 is normative

The two candidate readings, quoted exactly:

- **Plan line 131 (definition section):** "C5: every trace terminates at an actually produced typed terminal
  event kind, with both `TraceIntersection` and `MandatoryBarrierTermination` non-vacuously represented."
- **Plan line 101 (TB verification instructions):** "verify C5 observed exactly the required terminal
  event-kind set, including both `TraceIntersection` and `MandatoryBarrierTermination`."

Line 131 governs, on six independent grounds:

1. **Section authority.** Line 131 sits in the definition of what C5 *means*; line 101 sits in the list of what
   the TB turn should *check and report*. A reporting instruction cannot enlarge a frozen definition.
2. **"Including" is membership language, not exhaustion.** A set described as "including A and B" is not
   thereby limited to A and B. Had a two-element set been meant, the natural phrasing was "exactly
   `{TraceIntersection, MandatoryBarrierTermination}`".
3. **"Exactly the required set" resolves against line 131**, which states the requirement as a *property* —
   every trace terminates at a produced kind, and two named kinds are non-vacuous — with no cardinality at all.
   "Exactly the required set" therefore means "precisely the set that property requires", which is satisfied.
4. **The assertion contradicts its own failure message.** `tests/FieldAlignedCurveNetworkTests.cpp:6701-6702`
   reads `ASSERT_EQ(2U, producedTerminalKinds.size()) << "terminal-kind witness union must be non-vacuous; …"`.
   **Non-vacuous means non-empty, not exactly two.** The author wrote a cardinality equality to express a
   non-vacuity requirement. The message is the author's own statement of intent and it does not match the code.
5. **The two named kinds already have their own checks.** Lines 6712 and 6717 assert
   `producedTerminalKinds.count(TraceIntersection) == 1` and `… count(MandatoryBarrierTermination) == 1`. These
   are the actual non-vacuity requirements of line 131. Line 6701 adds nothing to them except a prohibition on
   any third kind.
6. **The two-cardinality reading forbids correct product behavior.** `SingularityTermination` is a frozen member
   of the terminal vocabulary and a required outcome of the CP4c-0/0b termination contract. Under the
   two-cardinality reading, C5 goes red *precisely because* a trace correctly terminated at a singularity. A
   criterion that a correct implementation cannot satisfy is a defective criterion — `LESSONS.md` lesson 60.

Ground 6 has a specific history that makes it decisive. `LESSONS.md` lesson **64e** records:
`FieldAlignedNetworkEventKind::SingularityTermination` "has existed since CP3b, is required by an acceptance
criterion, and is emitted nowhere — a repository search finds only its declaration." **The third kind in this
union is that defect being repaired.** The enumerator finally has a producer and a witness that reaches it.
Asserting `size() == 2` would re-freeze the exact gap 64e was written to prevent.

## 3. Clause 1 — the torus precondition is a recurrence of `DG-CAND-02`

`record_terminal_event_contract` at `tests/FieldAlignedCurveNetworkTests.cpp:4713` asserts
`ASSERT_FALSE(witness.network->candidate_traces().empty())` for **every** supplied witness. The torus network is
valid, published, and has `networkTraceCount=0` / `networkEventCount=0`.

That the pipeline-authoritative torus publishes zero traces and zero events is **measured, accepted fact**, not
a surprise: it was established by T1 in `M3-CP4c-0b-CB2` (48 `HardFeature` mandatory edges, 0 singularities, 48
structural endpoint nodes, 0 traces, 0 events, zero contact provenance), and it is asserted by accepted identity
`TraceTerminationCorrection.TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded`, which is **inside the
green 353 prefix of this very run**. C5 and an accepted identity in the same run therefore demand opposite
things of the same witness. When an accepted identity and a never-accepted one conflict, the never-accepted one
yields.

**This is the second time this defect has been written.** `M3-CP4c0b-DG-CAND-02` was raised when a new torus
identity asserted `torus.network->nodes().empty()`, and was adjudicated **RESOLVED / TEST-SIDE
OVER-SPECIFICATION / NON-STABLE** for the same underlying reason: zero trace publication does not imply
emptiness of everything else, and the frozen authority never stated the stronger invariant. One checkpoint later
the same witness is over-specified again, in the opposite direction — then it was "must be empty", now it is
"must be non-empty".

The line 131 contract is **universally quantified over produced traces**. A witness with zero traces satisfies it
vacuously and correctly. The helper's own body already handles this properly: the per-trace loop at 4727-4740
simply does not execute, and contributes nothing to the union. **Line 4713 is pure additive over-specification
and is the whole of clause 1.**

Note also the design inconsistency it creates with C5's own call sites. Lines 6680, 6686 and 6693 guard each
optional witness with `if (…sourceAuthority && …atlas && …network)` — a **reachability** guard. The helper then
imposes a **productivity** requirement. The torus falls exactly in the gap: reachable, published, unproductive.
The guard admits it; the assert rejects it.

## 4. What C5 actually proved — the product passed the part that matters

This is the finding most at risk of being lost, so it is stated plainly.

The genuine semantic content of C5 lives in the helper at lines 4727-4740:

```
ASSERT_EQ(1U, terminals.size())      // every produced trace has exactly one typed terminal event
EXPECT_EQ(1U, producedKinds.count(terminals.front()->kind))  // that kind was actually published
```

That is line 131's first clause, verbatim. The run reported **exactly two assertion failures** — the torus
precondition and the cardinality. Had any per-trace assertion failed on any witness, there would have been more.
Because `ASSERT_*` inside a `void` helper returns from the helper rather than the test, the torus failure did not
prevent the sphere from being processed: the union carries the sphere's `{2,4}` and the contributor map names
`TraceIntersection=prescribed sphere`, which is only possible if the sphere's helper invocation ran to
completion.

**Therefore: every produced trace on two-ring and on the prescribed sphere terminated at exactly one typed
terminal event whose kind was actually published.** C5's frozen requirement is met by the product. Only the
test's two extra constraints failed.

## 5. What is hidden behind the correction — the checks that never ran

`ASSERT_EQ` at line 6701 is **fatal**. It returned from the test body before lines 6712 and 6717 executed.

**The two assertions that carry line 131's named-kind requirement have never been executed.** They are unproven,
not passed. The corrective turn must not assume them. Predicted green (the union demonstrably contains both 2
and 3), but predicted is not measured, and W3 requires them reported individually.

Two further consequences of the same fatal-abort:

- `mechanical feature` was guarded out entirely — the report records it stopping in A1 with
  `IncompleteCycleBasis`, so `mechanical.network` is empty. It contributed nothing and proves nothing. **That is
  a pre-existing A1 reachability limitation, not a C5 defect**, and it must not be swept into this correction.
- No witness other than two-ring and sphere has ever exercised the per-trace terminal contract.

## 6. The five non-gating diagnostics — two have inverted

All five returned red with zero gate credit, which is correct and blocks nothing. But two are no longer merely
report-only:

- `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`
- `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`

Both **expect sphere network construction to fail** and assert `sphere.network.has_value() == false`. Accepted
authority now produces the sphere network. These are the exact case named in `LESSONS.md`: *"A test that asserts
a witness currently fails will invert the day you fix it."* It has now inverted. Their red no longer carries the
information it was written to carry, and a future reader will reasonably misread it as a product failure.

The other three (`…StageReachabilityIsObservable` × 3) unconditionally `FAIL()` in order to publish a report.
That pattern predates the CB3-INSTR observability work, which established the correct idiom — publish to stdout
from a non-gating identity that passes. They are not urgent.

Guidance is in W5: correct the two inverted ones, migrate the three publishers only if it costs nothing. Neither
is permitted to grow this CB beyond its bound.

## 7. Measures **W0–W7** for `M3-CP4c-1-CB4`

- **W0 — baseline and boundary.** Start from semantic/test source `66a065b5e07910568a317e24f0fc6b93d890d104`,
  package `9673249952`. **`src/` and `include/` are frozen: this correction is test-side only.** Compile under
  `GMP_COMPILE_POLICY.md` with GMP/GMPXX linked; `runtimeExecution=false`. Record the 355 selector SHA-256
  before and after — `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` — and the 316/346/353
  prefix hashes; **all four must be byte-identical afterward.** C5 is corrected in place at its existing
  ordinal 355; it is **not** renamed, renumbered, demoted, split, or moved to the non-gating selector.
- **W1 — clause 1.** Delete the witness-level productivity precondition at
  `tests/FieldAlignedCurveNetworkTests.cpp:4713`. Do not replace it with a weaker assert, a skip, a
  `GTEST_SKIP`, or a witness-name special case for the torus — a zero-trace witness must pass **vacuously and
  silently**, contributing nothing to the union, because that is what line 131 requires. Leave the per-trace
  loop at 4727-4740 exactly as it is; it is the identity's real content and it is correct.
- **W2 — clause 2.** Replace the cardinality assertion at line 6701 with the requirement its own message
  states: **`ASSERT_FALSE(producedTerminalKinds.empty())`**, keeping the existing diagnostic `<<` chain intact
  so the contributor map and the three reachability reports still print on failure. Do **not** change 2 to 3 —
  that repeats the defect one value later and would go red the first time a witness legitimately terminates on
  `TraceSelfClosure` or a barrier the sphere does not have.
- **W3 — prove what the fatal abort hid.** The successor TB must report, individually and by name, that lines
  6712 and 6717 executed and passed, and must publish the observed terminal-kind union with its contributor
  map. **"C5 green" alone is not an acceptable report for this identity**, because the named-kind checks have
  never once executed.
- **W4 — optional strengthening, and its limit.** If, and only if, the allowed terminal vocabulary can be
  derived from **frozen authority** rather than from current observation, C5 may additionally assert that the
  produced union is a **subset** of that allowed set. This preserves the legitimate intent behind "exactly the
  required set" without freezing a count. **If the allowed set cannot be established from frozen authority,
  do not invent it** — implement W2 alone and record why. Deriving the allowed set from what this run happened
  to produce would reproduce the original defect exactly.
- **W5 — the inverted diagnostics.** Correct `BranchBoundaryPairingContinuationIsUnique` and
  `PrescribedSphereCandidateTraceTransportFailureSiteIsObservable` so they assert the current accepted reality
  — the sphere network **is** produced — or retire them with a written rationale. They stay non-gating either
  way; **they may not be added to the 355.** The three `…StageReachabilityIsObservable` publishers may be
  migrated to the pass-and-publish idiom if it is mechanical; if it is not, leave them and say so.
- **W6 — accounting.** Record `M3-CP4c1-TB-R4-CAND-01` as **RESOLVED / TEST-SIDE OVER-SPECIFICATION /
  NON-STABLE**, `+0` events and `+0` recurrences, citing this review. `CAND-02` remains resolved
  process-order/non-stable. Totals stay **42 / 14 / 28**, debt **5**; increment the M3 package count. Produce
  one immutable eight-target GMP package and record its ID, ZIP SHA-256 and manifest result.
- **W7 — prohibited.** Any production semantic change; any edit to an accepted identity or to the first 353
  ordinals; changing the 355 selector's contents, order, or hash; demoting, skipping, or weakening C5 or C4;
  adding a tolerance, timeout, or guard widening; special-casing a witness by name; and entering CP4c-2/3.

## 8. Falsifiable successor prediction

Stated so the next turn can prove this review wrong rather than merely agree with it:

1. C5 goes **green**, and the full gate is **355/355**.
2. The produced terminal-kind union is **exactly `{TraceIntersection(2), MandatoryBarrierTermination(3),
   SingularityTermination(4)}`** — three kinds, not two and not four.
3. Contributors are **`TraceIntersection` = prescribed sphere**, **`MandatoryBarrierTermination` = two-ring**,
   **`SingularityTermination` = prescribed sphere**.
4. The torus contributes **zero** kinds and passes vacuously; the mechanical witness remains guarded out at A1
   with `IncompleteCycleBasis`.
5. Lines 6712 and 6717 execute and **pass**.
6. The accepted prefixes re-prove **316/316, 346/346, 353/353**, and C4 stays **PASS**.

**Any deviation is material.** In particular: if the union contains a kind outside `{2,3,4}`, or if the torus
contributes a kind, or if any per-trace terminal assertion fails on a witness that previously passed, that is
**not** a test defect — it is new product evidence, and it routes back to review rather than to another
correction.

## 9. What this review did not do

It did not execute anything, did not adjudicate the mechanical witness's A1 `IncompleteCycleBasis` limitation
(pre-existing, out of scope), and did not reopen the CP4c-0b closure. `M3-CP4c1-TB-R4-CAND-02` (the
process-order miss) is accepted as already resolved by the TB turn; its own guidance — that the mandatory policy
reads and `READ_MODE` selection precede the first repository inspection — stands and is not restated here.

## 10. Stop / successor

The exact next turn is **`M3-CP4c-1-CB4`**, Code + Build, runtime-free, test-side only, under measures
**W0–W7**. Its successor is `M3-CP4c-1-TB-R5`, the full 355 gate. **CP4c-1 closes on 355/355 with the §8
prediction met**; anything less routes to independent review, not to a retry.

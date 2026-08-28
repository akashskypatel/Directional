# M3-CP4c-0b TB-T5 Preflight Independent Review Record

## Verdict

`M3-CP4c-0b-TB-T5-PREFLIGHT-REV` is **COMPLETE / REVIEW GREEN**.

A narrowly bounded instrumentation Code + Build package is **AUTHORIZED**, under measures **V0–V7**, as
`M3-CP4c-0b-CB3-INSTR`, with a hard boundary: **test-side and non-gating-selector-side only, zero production
semantic change, and the 353 required-green selector and its SHA-256 must not change.**

The authorization rests on a correction to this reviewer's own prior work. **U3 and U4, as frozen in
`M3-CP4c-0b-DG-T4-REV`, are not satisfiable by an artifact-only T5 on package `9668492827`.** The defect is in
the measures, not in the package. Two lawful repairs existed; the cheaper-looking one is rejected below with
reasons.

No runtime, build, configure, compile or package operation was executed in this turn. No product, test,
fixture, selector or build file was modified.

## 0. Relationship to the blocker report — upheld, with two additions

`Architecture_M3_CP4c0b_TB_T5_Preflight_Blocker_Report.md` was authored concurrently with this review, on the
same branch, and reached the same core conclusion independently: U3 is a **before-gate** measure, immutable
package `9668492827` cannot publish it, U7 forbids fixing it inside T5, and therefore the only lawful outcome was
to fail closed at **0/353** without inference, retry, or silent weakening. **That judgment is upheld in full.**
Its U0 static verification matches this reviewer's independently computed hashes exactly, including the
first-346 prefix `20d3b0b1…3e46a`.

Its sharpest framing is adopted: **U3 was introduced by the T4 review after package `9668492827` had already
been built.** That is the cleanest statement of the defect and it belongs in the record.

This review adds two findings the blocker's audit did not reach, both of which change the plan:

1. **§2 — the fan is built twice inside the 353 and observed zero times.** The blocker correctly notes that
   ordinal 13 asserts the eight-node contract, but did not find that the two identities which actually
   *construct* the fan under CP4c-0b semantics discard their results.
2. **§3 — six of the seven compiled census identities are selected by nothing.** The blocker treats
   `ContactPredicateCensusIsPublishedNonGating` as the compiled non-gating surface. There are seven, and one of
   the unselected six already computes ordinal 13's second term. **Part of the gap is therefore recoverable by
   selector alone, at no code cost** — see V1.

The blocker's recorded process-control miss (repository inspection before the mandatory policy read and
`READ_MODE` selection) was self-caught, the conservation-policy fail-safe was applied, and no runtime or
semantic mutation preceded the correction. No further action is required, and it does not weaken the blocker's
evidence.

**Candidate adjudication.** `M3-CP4c0b-T5-CAND-01` is **real, EVIDENCE-CAPABILITY, NON-STABLE, ACTIVE**, owned
by measures V1–V3. It is not evidence that product semantics are wrong, and it is closed by a T5 retry that
publishes U3/U4 — not by any product change. `M3-CP4c0b-T5-CAND-02` is agreed **RESOLVED / ORCHESTRATION /
NON-STABLE**. Stable accounting is unchanged at **42 / 14 / 28**, debt **5**, M3 packages **54**.

## 1. What the premise got right, and what it got wrong

The turn request describes "missing U3/U4 observability" in the package. The observability gap is real, but it is
**not where the premise puts it**. The production producer already carries an in-band observation channel:
`diagnose_field_aligned_contact_census` threads a `FieldAlignedContactCensus *contactCensus` through the same
tracing pass the producer uses, and populates it from the producer's own candidate
(`src/geometry/SurfaceCellTracing.cpp:2890`, `contactCensus->nodeCount = candidate.nodes.size()`).

So **no new production instrumentation is needed, and none is authorized.** What is missing is that almost
nothing *selects* that channel, and the two identities that do build the fan throw the result away.

## 2. Finding 1 — the fan is built twice inside the 353 and observed zero times

Two identities in the 353 construct a `FieldAlignedCurveNetwork` on `make_four_triangle_fan()` and discard it:

| where | identity | line | what it does with the build |
|---|---|---:|---|
| accepted prefix | `ResolvedBranchCorrection.FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness` | 6348–6353 | `EXPECT_NO_THROW({ … (void)build; })` |
| DG seven | `TraceTerminationCorrection.TorusPublishesNoTraceAndNoContactNodeAndFanRemainsExcluded` | 7044–7047 | `(void)fanBuild;` then unconditional `SUCCEED()` |

Both are lawful for their own stated purpose — the first asserts closure (A2a never throws), the second
deliberately withholds acceptance credit from an excluded witness. **Neither observes anything.** A fan build
that failed closed with `N1`, `N2` or `N4` passes both identities unchanged.

Consequence: **the fan's node count, per-trace terminal kinds, barrier-termination count and guard status are
unobservable from the 353 selector.** U3's fan census and U4's fan guard-silence census cannot be produced by
any T5 run on the current package.

## 3. Finding 2 — the census family exists but is almost entirely unselected

`tests/FieldAlignedCurveNetworkTests.cpp` defines **seven** non-gating census identities:

```
ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating              5622
ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating        5632
ResolvedBranchCorrection.MatchingVersusGeometryCensusIsPublishedNonGating        5643
ResolvedBranchCorrection.GrazingEdgeTraceMultiplicityIsPublishedNonGating        5654
ResolvedBranchCorrection.VertexFanHolonomyCensusIsPublishedNonGating             5665
ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating   5676
ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating    5684
```

`Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt` contains **exactly one** of them
(`ContactPredicateCensusIsPublishedNonGating`). None is in the 353. The remaining six are dead code in every
CP4c-0b run.

This matters twice over:

- `PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating` (5684–5726) already computes and prints
  `terminalEventSummary` — a five-bin terminal-event-by-kind histogram, including
  `MandatoryBarrierTermination`, which is **exactly ordinal 13's second term** — but only for the sphere, and it
  is selected by nothing.
- `ContactPredicateCensusIsPublishedNonGating` **does** cover the fan and the two-ring:
  `for_each_cp4c_census_witness` (3385–3443) enumerates two-ring, four-triangle-fan, `sphere_prescribed` and
  `torus`, and the report publishes `nodeCount`, `siteCounts`, `eventKindHistogram`, per-contact
  `properCrossing` and `priorTerminalKind`, and the typed error on `status=unreached`
  (5521–5618). Under `rails_from_atlas`, labelled `railAuthority=AtlasDerived`.

So a meaningful fraction of U3 and U4 is already *implemented*; it is one selector line away from being
*observed*. That is the cheapest correction available and it is the core of the authorization below.

## 4. Finding 3 — several U3/U4 items are already satisfied and already green

The T4 review over-stated what was unmeasured. These are asserted by identities **inside the 353** and passed in
the T4 run:

| U3 / U4 item | covered by | line | status |
|---|---|---:|---|
| exactly-one terminal kind per trace | DG#5 `PrescribedSpherePublishes…` | 6912 | green, sphere |
| mutual termination actually fires | DG#5, `EXPECT_TRUE(hasMutualTermination)` | 6939 | green, sphere |
| two-ring node count = 9 | DG#4 `SiteVocabularyIsDisjoint…` | 6874 | green |
| two-ring zero contact termini | DG#4 | 6890–6892 | green |
| two-ring zero `TraceIntersection` / `TraceSelfClosure` | DG#4 | 6880–6889 | green |
| sphere guard silence (N1/N2/N4) | DG#5 `ASSERT_TRUE(network.has_value())` + 24 traces | 6902–6904 | green, implied |
| torus per-node provenance incl. `railAuthority` | DG#7 | 7008–7018 | green |

**Correction to `M3-CP4c-0b-DG-T4-REV`.** That review called mutual termination "the least-exercised path in the
checkpoint" and made it the residual risk behind ordinal 13. That is wrong. DG#5 line 6939 does not merely
permit mutual termination on the sphere — it **requires** it, and T4 measured it green. The tie policy is among
the better-exercised paths, not the worst. The residual-risk argument for ordinal 13 must be rebuilt on
something else; §5 does that.

U4's residue is therefore only: **the fan** (unobservable, §2) and the two-ring, which is covered.

## 5. Finding 4 — the risk ranking inverts: ordinal 12 is the greater risk, not 13

Ordinal 12, `FieldAlignedCurveNetwork.PublishesTypedFirstContactAndTerminationEvents` (1304–1343), builds
`build_cp3b_event_fixture()` — two-ring, `rails_from_atlas` (1293), the **same authority and same fixture** as
DG#4 and ordinal 13. It requires three things:

1. at least one `MandatoryBarrierTermination` event whose `sourceEdge` resolves via `find_mandatory_edge`;
2. for every such event, the event node differs from **both** endpoint nodes of its mandatory edge — the
   termination lands in the barrier's interior, not at an endpoint;
3. a **paired `FirstContact` event at the identical node, sourceFace and sourceEdge** (1333–1341).

Requirement 3 is the exposure. **Nothing in the DG seven asserts the FirstContact ↔ MandatoryBarrierTermination
pairing.** DG#4 shares the fixture but asserts only node count, three event-kind counts and terminal-contact
absence — it would pass unchanged if S2's vocabulary change or S5's relocation of the termination stage broke
the pairing or moved the node identity. That pairing is precisely the kind of invariant a stage relocation
breaks.

Ordinal 13, by contrast, is better supported than the T4 review argued, and for a stronger reason than the one
given there. `contactCensus->nodeCount = candidate.nodes.size()` (`SurfaceCellTracing.cpp:2890`) shows the census
is an **in-band observer on the producer's own candidate**, not a parallel diagnostic path. S1's measurement of
the fan at 8 nodes was therefore the producer's own node count, under the same `rails_from_atlas` authority
ordinal 13 uses. The prediction "ordinal 13 green at 8" rests on producer-internal evidence, not on an analogy.
The one caveat that remains: the census reads `candidate.nodes` *before* the sort at 2896 and before
`make_from_candidate` validation, so a node added or rejected during validation would not appear in it. That is
a narrow, nameable gap, not a general doubt.

**Revised ranking, highest exposure first: ordinal 12, then ordinal 13.** Both remain **STOP** on red.

## 6. The decision, and the option that was rejected

Two lawful repairs existed for the U3/U4 defect.

**Option A — bounded instrumentation CB, then T5.** One runtime-free turn adds test-side census coverage and
extends the *non-gating* selector, producing a new package; T5 then runs the unchanged 353 plus an enriched
non-gating selector.

**Option B — amend U3/U4 down to what package `9668492827` can answer, run T5 now, defer the fan census to
CP4c-1.** Cheaper if T5 is green.

**Option A is authorized. Option B is rejected**, for two reasons that survive the fact that B is cheaper when
T5 passes:

1. **The cost asymmetry runs the other way once §5 is priced in.** Ordinal 12's pairing requirement is
   genuinely unverified under S2/S5, and it is a STOP. A red at 12 with no event dump for the two-ring costs a
   review turn *plus* an instrumentation CB *plus* a re-run — which is Option A, arrived at later and after
   spending a T5. Option A pays that cost once, before it is needed.
2. **Amending a frozen measure because the artifact cannot meet it is the precise habit this project has been
   burned by.** `LESSONS.md` §6 exists because of it. If U3/U4 are to be narrowed, that is a definition
   decision made on its merits, not a convenience taken under gate pressure.

The user's standing direction from the checkpoint split applies and points the same way: resolve it now rather
than carry it forward as debt.

## 7. The boundary — what CB3-INSTR may and may not touch

**The 353 required-green selector `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` must not
change, by even one byte.** U0.2 verifies it, and the 346-line ordered accepted prefix
(`20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`) is what keeps `first_red_ordinal`
comparable with every prior CP4c-0 run. Adding a census identity to the 353 would destroy both properties and
would also grant gate credit to a diagnostic — twice prohibited.

All new observability is **non-gating**: new or newly-selected identities go in
`Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt` only.

## 8. Measures **V0–V7** for `M3-CP4c-0b-CB3-INSTR`

- **V0 — baseline.** Start from semantic source `b2629040450c12507367c232f68a4d972b46450f`, package
  `9668492827`. Record the 353 selector SHA-256 before and after; they must be identical. Compile under
  `GMP_COMPILE_POLICY.md` with GMP/GMPXX linked; `runtimeExecution=false`.
- **V1 — select what already exists, first.** The six unselected census identities are **compiled into the
  package already** — same translation unit, same target as the one selected census — so adding them to the
  non-gating selector is a control-plane change, not a code change. Before writing any new identity, add
  `PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`, which already publishes the terminal-event-by-kind
  histogram that is ordinal 13's second term. Report which U3 items this alone satisfies. **Prefer selection
  over authorship wherever an existing identity covers the item.** Select deliberately, not wholesale:
  `PrescribedSphereGrazingCostCensusIsPublishedNonGating` walks traces with the retired Cartesian carrier lookup
  under open candidate `M3-CP4c0-DEFN2-CAND-01` and should be selected only with that stated. The T5 retry must
  report the **zero-selected count**; a non-zero value means a selected identity is not in the binary and is a
  stop.
- **V2 — the fan census.** Author one non-gating identity that builds the fan under `rails_from_atlas` and
  publishes, without asserting a value: `nodes().size()`; per-node provenance via the existing
  `cp4c_node_provenance` (6973) in T3 format including `railAuthority=AtlasDerived`; per-trace terminal kind with
  the exactly-one count reported as an observation; the `MandatoryBarrierTermination` terminal-event count; the
  event-kind histogram; the count of events carrying two `Terminal` incidences (mutual termination); and the
  typed error, in full, if the build fails. **It must publish the typed error rather than pass silently — that
  is the specific defect in §2 and it must not be reproduced.**
- **V3 — the two-ring pairing census.** Author one non-gating identity that, for the
  `build_cp3b_event_fixture()` two-ring, dumps every event as `{kind, node, sourceFace, sourceEdge, incidence
  roles}`, and reports for each `MandatoryBarrierTermination` whether a `FirstContact` exists at the identical
  node/face/edge. This is ordinal 12's requirement 3, published as an observation. **Do not assert it** — CB3 is
  instrumentation; ordinal 12 is the identity that adjudicates it.
- **V4 — no production change.** `src/` and `include/` are frozen. The census channel already exists; do not
  extend `FieldAlignedContactCensus`, do not add a new production observation hook, do not touch the guards,
  the magnitude policy, any error bound, or any enum value. If an item in V2/V3 provably cannot be observed
  test-side from the published product surface, **stop and report it** rather than reaching into `src/`.
- **V5 — selector integrity.** Re-hash the 353 selector and confirm it is unchanged. Publish the new non-gating
  selector's contents and SHA-256. Confirm no identity was added to, removed from, or reordered within the 353,
  and that no new identity name collides with an existing one.
- **V6 — package and accounting.** Produce one immutable eight-target GMP package; record its ID, ZIP SHA-256
  and manifest result. Confirm no Directional runtime/test/benchmark/discovery/CLI/fuzzer executed. Carry
  stable accounting **42 / 14 / 28**, debt **5**, and increment the M3 package count.
- **V7 — prohibited.** Any production semantic change; any edit to the 353 selector or to any accepted
  identity, **including ordinals 7 and 9** — their authorized re-authoring belongs to T5, not to this CB;
  asserting any predicted value in a new census; granting gate credit to any diagnostic; widening a guard
  allowance, tolerance or error bound; adding a timeout; entering CP4c-1/2/3.

**CB3-INSTR closes** on a green build with V5 clean. Its successor is `M3-CP4c-0b-TB-T5` on the new package,
running the unchanged 353 under U0–U7 plus the enriched non-gating selector, with U3/U4 now answerable and the
§5 risk ranking in force.

## 9. Corrections carried into the record

1. **Mutual termination is not the least-exercised path.** DG#5 requires it on the sphere and T4 measured it
   green. The T4 review's residual-risk argument for ordinal 13 is withdrawn and replaced by §5's.
2. **Ordinal 12 outranks ordinal 13 in exposure.** The T4 review grouped them and predicted only for 13.
3. **U3 and U4 were issued unsatisfiable.** They named observations no selected identity produces. The measures
   were written from the design intent rather than from the selector, which is the same class of error as
   writing a gate criterion no witness can reach.

## 10. Stop / successor

The exact next turn is **`M3-CP4c-0b-CB3-INSTR`**, Code + Build, runtime-free, under measures **V0–V7**.
**Do not run T5 in that turn**, and do not run it on package `9668492827`.

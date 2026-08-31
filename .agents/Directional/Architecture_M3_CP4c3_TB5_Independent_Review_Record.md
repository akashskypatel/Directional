# M3-CP4c-3 TB5 Independent Review Record

## Status

**REVIEW COMPLETE / TB5 EXECUTION VALID / VERTEX-11 FAILURE IS A SILENT SEED-DROP, NOT A SECTOR ELECTION /
AMENDMENT 17'S CORRECTION INTRODUCED FLOATING POINT INTO AN EXACT TOPOLOGICAL DECISION / AMENDMENT 17 NEITHER
CLEARED NOR FALSIFIED — MASKED / AMENDMENTS 18 AND 19 DECLARED / ADVERSARIAL ARCHITECTURE REVIEW ADJUDICATED /
MEASURES AU0–AU9**

This record executes `Architecture_M3_CP4c3_TB5_Independent_Review_Plan.md` (**AT0–AT7**) against `M3-CP4c-3-TB5`
(run/job `33448925069 / 99674216849`, immutable package **74**, semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`, frozen gate selector **373**), and additionally adjudicates the
user-supplied adversarial architecture review (§9) with the amendments and roadmap changes it justifies.

Review, definition and planning only: nothing executed, compiled, packaged or benchmarked, no gate selected or run,
and **no product, test, fixture, selector or build-logic byte changed**. Measures issued here are **AU0–AU9**.

---

## AT0 — the evidence boundary, re-verified

Working tree byte-identical to the packaged semantic source; selector **373** recomputed from committed bytes with
all six byte-prefix predecessors (355, 357, 361, 365, 367, 370) reproducing exactly. Preflight and postflight both
passed, the package stayed byte/mode/source/fixture/selector immutable, and every configure/compile/relink/repair/
generated-discovery/benchmark/mutation flag was false. One identity per fresh process from ordinal 1, first-red hard
stop, **accepted 365 prefix green**, AP6 pass run afterwards with zero gate credit.

**Both pre-runtime attempts are correctly closed as control-plane only.** The permission-union failure ran no
Directional process. The second stopped on an **over-strong** lineage assertion — selector **358 is not a byte
prefix of 373**, and never was: 358 is the *withdrawn* fork retained for history, whose identity set is a subset of
373, while 361 restores byte-prefix continuity. That is exactly what `ORIENTATION.md` §3 has recorded since R7-REV,
so the corrected preflight (strict byte-prefix for 357/361/365/367/370; hash + cardinality + set-subset for 358) is
right and **no selector byte changed**. The TB's own process note about a late `READ_MODE` selection is retained and
does not touch runtime evidence.

**TB5 is admissible semantic evidence and a valid semantic red at ordinal 366.**

---

## AT1 / AT2 — the vertex-11 failure is a silent seed-drop, and that is why the diagnostic vector is empty

### 1.1 What CB6 changed

Amendment 17 required the election to test **one datum**. CB6 implemented that by carrying the incoming direction
as a **world-space `Eigen::RowVector3d`** through the fan walk. The BFS was restructured so the seed is pushed
**conditionally** (`src/geometry/SurfaceCellTracing.cpp:659-667`):

```cpp
std::vector<TransitState> pending;                       // starts EMPTY
if (currentPairing != nullptr) {
  const auto incomingDirection =
      field_direction_world(sourceMesh, currentFace, currentPairing->direction);
  if (incomingDirection.has_value()) {
    pending.push_back(TransitState{currentFace, currentBranch, *incomingDirection, {}, 0});
  }
}
```

`diagnostics` is populated **only inside the walk loop** (`:703`). Therefore, if `pending` is empty at entry, the
loop body never executes, `diagnostics` stays empty, `candidates` stays empty, and control falls through to
`candidates.size() != 1U` → `VertexTransitSectorUnresolved` with `publishedFaceCount=0` **and zero
`vertexTransitState` rows**.

**That is exactly TB5's measurement.** The empty diagnostic vector is not a serialization defect and not "ordinary
zero-sector membership" — it is the signature of a walk that never started.

### 1.2 The two ways the seed drops, and two more that drop states silently

| # | site | condition | records a diagnostic? |
|---|---|---|---|
| 1 | `:660` | `currentPairing == nullptr` — no frame, component/region mismatch, or **two** pairings for the branch (the ambiguity guard nulls it) | **no** |
| 2 | `:661-663` | `field_direction_world` returns `nullopt` — direction not barycentric, non-finite, or **`squaredNorm() == 0.0`** after conversion to `double` | **no** |
| 3 | `:695` | `field_direction_from_world` returns `nullopt` — the `double → exact` round trip fails | **no** (the `continue` precedes `diagnostics.push_back`) |
| 4 | `:731-735` | transported direction non-finite or zero-norm during expansion | **no** |

**Four unreportable exits**, all newly reachable or newly silent after CB6, all funnelling into one typed name that
asserts something else. The failure says *"the sector election was unresolved"*; the truth at vertex 11 is *"no
state was ever examined"*. This is the fifth consecutive turn in which a typed name has misdescribed its own cause.

### 1.3 Vertex 11 is structurally ordinary — which is what makes the seed-drop reading conclusive

Reproduced from the committed fixture, vertex 11 has **six** incident faces forming a single **closed,
consistently oriented** fan — row 8 `(8,10,11)` (the arrival face) → row 9 → row 18 → row 119 → row 108 → row 109
→ back to row 8. It is not barrier-incident, not barrier-absorbed, and — like vertex 30 — is not among the eight
prescribed singularities, so it is a **regular** interior vertex with trivial holonomy.

Nothing about vertex 11's geometry distinguishes it from vertex 30 or from the dozens of vertices the trace crossed
successfully before it. **A structurally ordinary vertex producing zero examined states is a defect in the seeding
path, not in the geometry.** Between causes 1 and 2 the review does not choose: both are unreportable today, and
**AU1** publishes which fired.

---

## AT3 — Amendment 17 is **masked**, neither cleared nor falsified

The vertex-11 stop occurs **before any election runs**. An unseeded walk elects nothing regardless of how the
election is written, so TB5 exercised **none** of Amendment 17's substance at this locus. Vertex 30's two-candidate
defect is therefore **not proved fixed and not proved broken** — it is simply not reached.

Two further consequences must be stated, because both are easy to misread:

- **AS1's falsifier never ran.** AS1 required CB6 to publish, per candidate, the transported branch label and the
  **exact barycentric direction vector**, with the instruction to **stop and route to review if the two elected
  vectors were equal**. With zero states recorded, the measurement that was supposed to confirm or destroy M4/M5
  produced nothing. The TB4 reconstruction stands untested.
- **This is not a regression of accepted authority** — ordinals 1–365 are green — but it *is* a new defect at
  ordinal 366 introduced by CB6: before CB6 the seed was pushed unconditionally
  (`std::vector<State> pending{{currentFace, currentBranch}}`), so the walk always started. CB6 made starting
  conditional and made the conditions silent.

---

## AT6 — the CB6 assumption surface: exactness was broken to satisfy Amendment 17

This is the most consequential finding of the turn, and it is a **violation of the project's foundational
commitment**, not a stylistic objection.

`DESIGN.md` and `ORIENTATION.md` §1 both state: *exact arithmetic, no tolerances in topological decisions; a
predicate that needs an epsilon is a design defect.* CB6's implementation of Amendment 17:

- converts the exact barycentric direction to **`double`** (`field_direction_world`, `to_double()`),
- carries it across the fan as a normalized **world-space double vector**, transporting it face to face with
  `transport_direction_between_faces` (double arithmetic),
- converts it **back** to exact rationals per face (`field_direction_from_world`, `from_double_exact`),
- and feeds that reconstructed value into `direction_in_vertex_sector`, whose comparison is exact.

**The comparison stayed exact; the datum did not.** An exact comparison on a float-derived operand is not an exact
decision — it is a floating-point decision with an exact final rounding step. Worse, the conversion has silent
failure modes (`squaredNorm() == 0.0`, non-finite, `from_double_exact` failure) that are precisely the four
unreportable exits of §1.2. The very first place this project relaxed exactness produced, in one turn, a silent,
unreportable, mis-named failure.

**AS9 prohibited "any tolerance in the predicate."** CB6 did not add a tolerance to the predicate — it changed the
*provenance of the predicate's inputs*. The measure was satisfied to the letter and defeated in substance. That is
the **fifth** consecutive turn in which a scope of mine was one level too narrow (§10), and it is why **Amendment
18** below is written about the *derivation chain*, not about the comparison.

Amendment 17 itself is **not** at fault and is not reopened: electing from a single datum is right. What was wrong
was choosing world-space doubles as the way to carry that datum, when the exact machinery to transport a barycentric
direction between faces already exists in the atlas's `FieldBranchTransportAdjacency` composition.

---

## AT4 — topology semantics reconciled

Nothing in TB5 disturbs Amendments 12–17, the P2 decision, barrier non-traversability, the exactness of
`direction_in_incident_vertex_sector` itself (still `FieldExactRational`, still half-open, still no tolerance), the
`FaceInterior` exclusion, error-enum numbering, first-red semantics, or the frozen selector. Ordinals 1–365 are
green. The AP6 pass remains zero-credit.

---

## AT5 — report-only diagnostics, disposed without widening scope

- **367 / 371 / 372 — RED, blocked upstream** by the vertex-11 stop. Amendment 15's Euler-cut identity and
  barrier-exclusion contracts remain **unmeasured, not falsified**, for the third consecutive run.
- **368 — the sphere is finally one level deeper.** `TraceEventPositionInvalid` now resolves to
  **`NoCarrierMatch / SourceEdgeUnavailable`** at trace 2 / event 30. **AL3's discriminator is answered: it is
  `NoCarrierMatch`, not `AmbiguousCarrierMatch`.** The ambiguity suspicion carried since TB1 is **dead**, and with
  it the "trace crosses the same edge twice" hypothesis. The live reading is a network/event **binding** defect —
  the event's `sourceEdge` is unavailable on the trace it claims — which is upstream in A2a, exactly as
  `Architecture_M3_CP4c3_TB1_Independent_Review_Record.md` §4 predicted for the empty branch. **AL4 still forbids
  designing the sphere's fix**, but the blocking condition AL4 was written against — *"the two candidate causes
  need opposite fixes and the evidence does not choose"* — **is now discharged**. §AU6 schedules the sphere
  explicitly rather than leaving it deferred by inertia.
- **369 — `saturationUsed=true`**, reconfirmed. Deferred behind the mechanical gate; unchanged.
- **370 — classified.** The atlas now publishes **`NonIntegralCycleLift; topologyRegion=0`**, so the constant
  ambient `make_zero_transport_field` torus witness **violates the atlas precondition** and the atlas's fail-closed
  rejection is **legitimate product behaviour**. `M3-CP4c3-TB4-DIAG-CAND-01` is therefore an **invalid diagnostic
  witness**, not a product defect — the third of AQ5's three options, decided on published evidence exactly as AS3
  required. The intended empty-network contract (`R8-CAND-02`) remains **unmeasured**; repairing the witness is
  **not** authorized in a review turn and is scheduled by **AU7**.
- **373 — PASS on a synthetic contract only.** `M3-CP4c3-DEFN-R1-CAND-01` stays **partial**; the mechanical
  witness's `unboundSingularityCount=0` is still owed.

---

## AT7 → **AU0–AU9**, one bounded successor

Next turn: **`M3-CP4c-3-CB7`** — Code + Build, runtime-free, GMP/GMPXX linked.

**AU0 — preconditions.** Gate **373**, `b47c269851…4834`; recompute it and all six byte-prefix predecessors from
committed bytes, and check 358 by hash/cardinality/**set-subset**, not byte prefix. No selector byte may change.
`selected_gate=NONE`, `gate_execution_authorized=false`.

**AU1 — make every exit reportable before changing anything else.** Every early `continue`/return in
`resolve_field_vertex_transit` that can end in a typed failure must record a typed reason: the four sites in §1.2
plus any found by search. Publish, for the ordinal-366 failure, **which** exit fired and at which state. A failure
that reports "sector unresolved" when no state was examined is prohibited: give the empty-seed and empty-walk cases
their own appended reason codes.

**AU2 — remove floating point from the transit datum (Amendment 18).** Carry the continuation direction **exactly**.
The atlas already publishes exact per-edge branch transport (`FieldBranchTransportAdjacency`, `signedLift`,
`FieldExactRational` directions); compose that instead of round-tripping through world-space `double`. Delete
`field_direction_world` / `field_direction_from_world` from the decision path, or demote them to a
diagnostic-only leaf that no predicate consumes. **State in the CB report that no value reaching
`direction_in_vertex_sector` has passed through a `double`.**

**AU3 — only then re-run Amendment 17's measurement.** With AU1 and AU2 landed, publish AS1's original payload: per
state, the transported branch label, the **exact** direction vector, the transport path, the composed quarter-turn,
and the three booleans. The **falsifier stands**: if the elected directions at a multi-candidate locus are equal,
stop and route to review.

**AU4 — do not redesign the election in CB7.** AU1 and AU2 are prerequisites, not the correction. Amendment 17's
substance has still never been exercised, so CB7 restores measurability and exactness; the election's final shape
is decided when AU3 reports.

**AU5 — audit by assumption.** Predicates for the search, both required, with findings listed: *"this code lets a
value reach a topological decision after passing through floating point"* and *"this code can exit a producer
without recording a typed reason."* Name at least one site per predicate **outside** `resolve_field_vertex_transit`.

**AU6 — schedule the sphere.** AL4's blocking condition is discharged by 368's `NoCarrierMatch / SourceEdgeUnavailable`.
CB7 does **not** fix the sphere, but it must publish the event's claimed trace, its `sourceEdge`, that edge's
availability on the trace's segments, and **which pass** produced the result, so the successor DEFN can settle the
binding contract. The sphere is now the **only** CP4c-3 witness whose cause is measured and whose fix is unscheduled.

**AU7 — repair the ordinal-370 witness, and only the witness.** `make_zero_transport_field`'s constant ambient
field is not a valid atlas input on a closed torus (`NonIntegralCycleLift`). Replace it with a field the atlas
accepts, keeping the *intent* — an empty rail set and empty network on a closed surface — so `R8-CAND-02`'s typed
rejection becomes measurable. The atlas's rejection is correct and must not be weakened.

**AU8 — cadence and scope changes (see §10).** Extend the AP6 report-only pass from ordinals 367–373 to **every
remaining ordinal after the first red**, zero gate credit. Add the minimal transit witness required by §10.2.

**AU9 — prohibited.** Letting any float-derived value reach a topological decision (Amendment 18). Leaving any
producer exit unreportable (Amendment 19). Redesigning the election before AU3 reports. Forcing
`candidates.size() == 1` by picking first, ordering faces, changing the sector convention or the `FaceInterior`
rule, or adding a tolerance. Crossing or closing a barrier. Weakening the atlas's `NonIntegralCycleLift` rejection
to make ordinal 370 pass. Designing the sphere's fix in CB7. Reopening Amendments 12–19 or the P2 decision.
Renumbering or removing any error-enum value. Changing any frozen selector byte. Treating AP6 results as gate
credit. Executing Directional runtime, running a gate, or benchmarking in a CB turn.

---

## 9. The adversarial architecture review — adjudicated item by item

Evaluated against measured evidence from this checkpoint. Four items are **valid and adopted** (two as amendments,
two as roadmap items); one is **valid in general and already answered better**; three are **contradicted by
measurement** and are recorded as prohibited so they are not re-proposed.

### 9.1 Valid and adopted

**#1 (part) — filtered/adaptive predicate evaluation. ADOPTED as Amendment 18's permitted form.** Shewchuk-style
adaptive predicates are **exactness-preserving**: the filter either returns the provably-correct sign or defers to
the exact path, so the *decision* is identical and only the *cost* changes. This is a legitimate performance
architecture and the review is right that a blanket "always full rational" mandate leaves performance on the table.
It is admitted **only** in that certified form.

**#1 (part) — expression swell. VALID CONCERN, UNMEASURED, SCHEDULED.** Propagating exact barycentric parameters
face-to-face does grow numerator/denominator bit-width, and this project has never measured it. Note the code
already shows awareness — `field_aligned_trace_step_budget`'s comment says *"exact continuation values grow with
every step, so that budget could never be reached."* That is an unquantified claim about the very quantity at
issue. **Scheduled as a measurement (`ROADMAP` M4 scale item)**: instrument maximum and mean bit-width per trace
step on all four witnesses before any mitigation is designed. **The proposed cure — "bounded lattice snapping" — is
REJECTED**: snapping a coordinate to a bounded denominator *changes the value*, which is precisely the
"introduce error into a topological decision" the project forbids, and would silently invalidate every downstream
exactness claim. If swell proves real, the corrective is representational (reduce fractions to lowest terms each
step; recompute the parameter in the destination face from exact source data rather than composing) — not
truncation.

**#5 — limit cycles versus a step budget. VALID, ADOPTED IN CORRECTED FORM (M4).** The critique is right that a
step budget is a heuristic and that budget-termination would create an unjustified boundary. The proposed cure
depends on the rejected lattice snapping, but a **corrected** version is sound and exactness-preserving: the
dynamics are deterministic, so a trace that revisits an **exact** state `(face, branch, exact entry point)` is
provably periodic. Detect that, terminate with a typed `LimitCycleTermination`, and close the loop as a real
topological feature. The state space is not finite, so this does not *replace* the budget — but it converts most
budget hits into typed findings and makes any remaining budget hit a reportable anomaly rather than a silent
truncation. **Scheduled M4**; CP4c-0b's frozen termination contract is not reopened by adding a new typed terminal
reason.

**#7 — post-mortem disc proof. PARTIALLY VALID, ADOPTED AS AN OPTIMIZATION (M8/M4-scale).** Growing a region to
thousands of faces before testing `χ = 1` is wasteful, and incremental Betti tracking via union-find would localize
and cheapen the failure. This weakens no guarantee — it fails **earlier**, never differently — so it is admitted as
a performance item. **The backtracking half is REJECTED**: "backtrack and adjust the local cut graph" has A2b
mutating A2a′'s output, which is exactly `RP-01 AUTHORITY_DOMAIN_CONFLATION`, the pattern that has bitten this
project five times.

**#8 — residue only. The ILP proposal is rejected (§9.3), but it exposes a real coverage gap.** Handle-generator
cycles (`2g` of them) have only ever been exercised at **genus 1** (the torus). No genus ≥ 2 witness exists.
**Scheduled as a ROADMAP coverage item.**

**#4 — reframed and adopted as a property, not a predicate change (§9.3 rejects the predicate change).** The
review's underlying observation is genuine and sharp: the field is produced by a floating-point optimizer, so an
exact predicate answers a question whose *premise* carries noise. The sound response is not to fuzz the predicate
but to make **stability under input perturbation a measurable product property**. **Scheduled**: a perturbation
witness that re-runs a witness with the field perturbed at the last significant bits and asserts the *topological*
output is unchanged. That converts an architectural worry into a falsifiable test.

### 9.2 Valid in general, already answered better

**#6 — index versus geometric branch count.** The general phenomenon is real in the literature. But the review's
evidence is **factually wrong about this codebase**: `MissingSingularityBranchTransport` was not "geometry found 3
branches, index demanded 4". `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md` §3 established by elimination
that the fan walk demanded a branch transport across a **hard-feature barrier**, and CB3's census found **8**
prescribed singularities with the expected branch classes — no missing branch anywhere.

The project already has a principled answer to the real phenomenon, arrived at from measurement: **Amendment 16
policy P2**, where a barrier-incident singularity emits **no** ports and its index is absorbed into the slit
boundary cycle, with Gauss–Bonnet accounting preserved. That is strictly better than "phantom ports", which would
inject fictitious topology and violate *derived, not assumed*. **Phantom ports are recorded as prohibited.**

### 9.3 Contradicted by measurement — recorded as prohibited

**#2 — "delta authority" / `TopologicalCorrectionDelta`. REJECTED.** The premise is wrong twice over. The cited
`χ = 6` was a **pre-cut measurement of the sphere's non-cellularity** (`V/E/F = 18/30/18`), not damage a cut graph
inflicted; and Amendment 12 already distinguishes *establishing a precondition before a product is derived* from
*repairing a product after*. The project has met the genuine need for "healing" twice, correctly, by **deriving a
new view** rather than patching an old one: Amendment 14's derived arrangement and Amendment 15's cut transport
domain. A composed `(Stage A output + Stage B delta)` working state would create **two authorities for one datum**
— `RP-01`, five recorded instances — and would make every digest ambiguous about which composition it attests.
**Prohibited.**

**#3 — regularization policy with a lexicographic tie-break for vertex transit. REJECTED, AND FALSIFIED BY PROOF.**
The review asserts the vertex-30 two-candidate state is "inherent to piecewise-linear interpolation".
`Architecture_M3_CP4c3_TB4_Independent_Review_Record.md` §AQ2 **proves otherwise**: the sector predicate is an exact
half-open partition of the full turn — adjacent wedges share exactly one ray, owned by the face where it is `next`,
no overlap and no gap — so a single direction elects **at most one** face. Two elections therefore prove **two
distinct directions were tested**, i.e. an artifact of testing one representative *per cell*, not a geometric
ambiguity. A lexicographic or minimal-angular-deviation tie-break would silently select one of two answers to a
malformed question and hard-code a wrong continuation into the quad layout. **Amendment 17 already prohibits
exactly this**, and the review's proposal is the prohibited fix by name.

The *taxonomy* half has modest merit — distinguishing corrupted input from discrete degeneracy is reasonable — but
this project already models genuine degeneracies explicitly and exactly (grazing as edge transit on a continuity
argument; mutual termination on an exact tie; `MandatoryBarrierTermination`). No refactor is scheduled: the
concrete cases the review cites are not degeneracies.

**#4 — "thickened"/epsilon-tube predicates. REJECTED.** An epsilon tube does not remove the discontinuity, it
relocates it to the tube boundary and makes the outcome depend on a tuning constant — the exact defect
`ORIENTATION.md` §7 already tracks as an open audit item (`kBranchTopologyTolerance` compared against a Gram
determinant). **Interval arithmetic used as a certified *filter* is admitted** under Amendment 18 (§9.1, #1);
interval arithmetic used to *change the answer* is prohibited. TB5 is the empirical case against the review here:
the one place exactness was relaxed produced a silent, unreportable, mis-named failure within a single turn.

**#8 — global ILP for chart-transition holonomy. REJECTED as a misreading.** The atlas does **not** choose branch
transitions greedily. `build_branch_transports` derives them from the **input** cross field's `matching`/`effort`
(`CrossFieldEdgeTransition`), which the upstream MIQ-style solver produced; A1 then **verifies** global
consistency — it builds the cycle basis, computes exact lifts, and enforces `interiorIndexSum == 4χ`
(Gauss–Bonnet/Poincaré–Hopf) plus per-cycle `CycleTransportMismatch`. The ILP the review proposes is field
*generation*, which is upstream and out of this pipeline's scope. What survives is the genus ≥ 2 coverage gap
(§9.1).

### 9.4 The review's central thesis, assessed

The closing claim is that Directional must evolve from "a strict immutable compiler" into "a robust topologically-
aware solver", chiefly by relaxing exactness and admitting repair. **The measured evidence of this checkpoint
points the other way on both counts.**

Exactness has not been the source of a single defect in CP4c-3. The defects were: a barrier edge left interior to
its region (Amendment 15), a port derivation walking a global closed fan (Amendment 16), an election testing one
representative per cell (Amendment 17), a diagnostic funnel discarding loci (AP1), and now a float round-trip with
four silent exits (Amendment 18). Every one is a **representation or reporting** defect. And the strict
immutability the review would relax is what made each of them *findable*: because the 365-identity accepted prefix
is re-proved green in every run, each of five invasive changes to A1 and A2a was demonstrated to regress nothing.

Where the review is right, it is right about **cost and coverage** — swell, limit cycles, post-mortem verification,
higher-genus, input-noise stability — and those are adopted above. Where it is wrong, it is wrong because it
diagnosed this codebase's specific failures from their *names* rather than their causes, which is the exact error
`LESSONS.md` 57 exists to prevent.

---

## 10. Progress, honestly assessed — and the cadence changes that follow

The user's observation that CP4c has not made satisfactory progress in several turns is **correct**, and it
deserves a direct answer rather than a defence.

**What did progress.** A1 is clear end to end: the mechanical witness went from failing in the cycle basis, to
failing in port attachment, to clearing A1 entirely. The accepted **365 prefix stayed green through five invasive
changes**. The sphere moved from a 36-way collapsed name to `NoCarrierMatch / SourceEdgeUnavailable`. Two inherited
CP4c-2 debts are now runtime-measured rather than statically argued.

**What did not.** Ordinal 366 has been red for **six** consecutive TB runs, and the failure has moved four times
without closing. The throughput is roughly **one defect per three turns** (CB, TB, review).

**Four causes, from the record rather than from impression.**

1. **A runtime-free CB cannot validate its own correction.** Every semantic mistake costs a full CB+TB+review
   cycle to discover. CB6's silent seed-drop would have been visible in seconds of execution.
2. **First-red stops buy one defect per run.** AP6 partially fixed this and immediately produced four findings in
   one run — but it covered only ordinals 367–373.
3. **Every defect has been debugged on a 152-vertex, 300-face production witness** with 8 singularities and a
   barrier forest. There is no minimal witness for the transit election, so every diagnosis needs a full pipeline
   run and a fixture reconstruction.
4. **Five consecutive measures of mine were scoped one level too narrow** — by symbol, by enum, by stage, by
   mechanism enumeration, and now by "predicate" when the defect was in the input's provenance. Each was satisfied
   exactly and defeated in substance.

**Three changes, all cheap and none weakening the gate** (issued as **AU8**, recorded in `ROADMAP.md`):

- **Full report-only pass.** After the first red fixes the verdict, execute **every remaining ordinal** report-only
  with zero gate credit. The gate semantics, the selector and `first_red_ordinal` are untouched; one run then buys
  every independently-reachable defect instead of one.
- **Minimal witnesses for active defects.** Each active gating defect gets a small constructed witness that
  reproduces it — for the transit election, a single interior vertex with a known fan and an exact synthetic field.
  Cheap to run, fast to reason about, and it becomes a permanent regression identity. This is `LESSONS.md` §2
  applied to debugging rather than to acceptance.
- **Measures written as predicates, with a named falsifier.** Every corrective measure states the assumption in
  words and names the observation that would fall outside it. `LESSONS.md` 68 and 70 are the rule; **AU5** is the
  first application that requires the implementer to name a site the reviewer did not.

---

## 11. Amendments declared

Both are forced by measured evidence from this turn and are recorded normatively in `DESIGN.md` §7.2.1.

**Amendment 18 — exactness is a property of the derivation chain, not of the final comparison.** A value that
reaches a topological decision may not have passed through floating point at **any** point in its derivation, even
when the comparison itself is exact. Converting an exact quantity to `double` and back — for transport, for
normalization, or for convenience — destroys the guarantee regardless of the comparison's type, and introduces
silent failure modes (underflow to zero, non-finite results, failed reconstruction) exactly where the decision is
least observable. Where performance requires it, a **certified filter** is admitted: a floating-point or interval
evaluation that either returns the provably-correct result or **defers to the exact computation**, never an
approximation of it. A filter that can return a different answer than the exact path is not a filter.

**Amendment 19 — a producer may not have an unreportable exit.** Every control-flow path that can end in a typed
failure must record a typed reason. An early `continue`, a `nullopt` return on a conversion, or a guard that skips
a state must leave evidence; a producer that reports a typed name describing a decision it never made is worse than
one that reports nothing, because the name is believed. Where a producer publishes per-state diagnostics, the
diagnostic must be recorded **before** any conditional that can skip the state, and an empty diagnostic set must
itself be a distinguishable, named condition.

---

## 12. Accounting and dispositions

Accepted 365 prefix green; CP4c-3 already open; all findings on unaccepted or report-only surfaces.
**44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic packages **72**,
**+0 events / +0 recurrences.**

- **`M3-CP4c3-TB5-CAND-01`** — **CAUSE ESTABLISHED**: silent seed-drop with four unreportable exits; the typed name
  misdescribes it. Owners **AU1** (report), **AU2** (exactness).
- **`M3-CP4c3-TB3-R1-CAND-01`** (vertex 30 / Amendment 17) — **MASKED, NOT RESOLVED.** Untested; AS1's falsifier
  never ran. Reopened for AU3.
- **`M3-CP4c3-TB4-DIAG-CAND-01`** — **CLASSIFIED: invalid diagnostic witness.** The atlas's `NonIntegralCycleLift`
  rejection of a constant ambient field on a closed torus is legitimate. Witness repair owned by **AU7**.
- **`M3-CP4c2-TB-X2-CAND-04`** (sphere) — **ONE LEVEL DEEPER AND NO LONGER AMBIGUOUS**:
  `NoCarrierMatch / SourceEdgeUnavailable`. AL4's blocking condition is discharged; **AU6** schedules it.
- **`M3-CP4c2-TB-X2-R10-CAND-01`** — reconfirmed `saturationUsed=true`; deferred.
- **`M3-CP4c2-TB-X2-R8-CAND-02`** — still unmeasured, blocked on AU7's witness repair.
- **`M3-CP4c3-DEFN-R1-CAND-01`** — partial; mechanical zero-unbound still owed.
- **New: `M3-CP4c3-TB5-REV-CAND-01`** — floating point in the transit decision path (Amendment 18). Owner **AU2**.

## 13. Falsifiable predictions

1. **AU1 will report the empty-seed exit** (§1.2 cause 1 or 2) at vertex 11, not an empty sector membership. Any
   other exit falsifies §1.
2. **AU2 will find no exact path is lost** by removing the double round-trip: the atlas's exact branch transport is
   sufficient to carry the datum. If it is not, the single-datum choice must be revisited, not the exactness.
3. **Once AU1/AU2 land, ordinal 366 will fail at or beyond vertex 30** — earlier failures were masking it. A
   failure at a *third* vertex would mean the seeding defect has more instances than §1.2 enumerates.
4. **Ordinals 1–365 will remain green** through AU1 and AU2, which are additive and remove float, not behaviour.
5. **The sphere's `SourceEdgeUnavailable` will localize to an event whose `sourceEdge` is absent from its claimed
   trace's segment carriers** — the binding defect, not an ambiguity.

## 14. Exact next turn

**`M3-CP4c-3-CB7`** — Code + Build, runtime-free, GMP/GMPXX linked, under **AU0–AU9**. It makes every transit exit
reportable (AU1), removes floating point from the transit datum (AU2), restores AS1's measurement (AU3), repairs the
ordinal-370 witness (AU7), publishes the sphere's binding evidence (AU6), and lands the cadence changes (AU8).

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; gate **373** stays frozen and unselected.

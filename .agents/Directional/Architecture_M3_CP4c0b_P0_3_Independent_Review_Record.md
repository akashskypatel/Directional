# Architecture M3 CP4c-0b — P0.3 Independent Review and Plan Correction

**Turn:** `M3-CP4c-0b-P0.3-REVIEW-PLAN`
**Type:** Independent review / planning only — no product, test, fixture, selector, build, package, or runtime mutation. Source was read and reasoned over; nothing was executed and nothing was modified.
**Trigger:** `M3-CP4c-0b-CB1` stopped at binding precondition **P0.3** before any implementation.
**Source inspected:** semantic head `49831e30433d72504a69b5a8c817aa6fa00f953c`; preflight record `Architecture_M3_CP4c0b_CB1_P0_Preflight_Record.md`.
**Incoming accepted authority:** **M3-CP4c-0 CLOSED / ACCEPTED 346/346**, GMP package `9649395432`, run/job `33079817998 / 98543736213`.

---

## 0. Verdict

**P0.3 is false, the stop was correct, and the stop rule did its job.** CB1 was right to refuse to reinterpret a frozen precondition inside a Code + Build turn. Nothing about the preflight's conduct needs correcting.

But the correction is **not** the narrow one the preflight offered as a possibility ("that may be the intended corrected baseline: no proper-crossing contact terminus yet"). P0.3 was wrong because **the premise of the whole CP4c-0b definition was wrong**:

> `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` §2 and §7 assert that A2a does not implement crash-on-contact and that CP4c-0b must add it.

**A2a already implements crash-on-contact.** It is accepted authority, it has been since CP3b, and it is **defective in four independent ways**. CP4c-0b is therefore a **correction and relocation of accepted authority**, not a greenfield addition, and its re-proof surface is materially larger than §7 estimated.

This review states the four defects from source, replaces P0, adds a mandatory measurement that must precede any semantic change, and issues corrective measures **S0–S8** superseding P0–P9.

**CB1 may resume** under the corrected plan. No DEFN re-freeze beyond Amendment A1 (§7) is required.

---

## 1. My error, and how it survived four documents

**What I asserted, in the frozen CP4c-0b DEFN:**

- §2: *"A2a does not implement crash-on-contact."*
- §7: *"`TraceIntersection` **becomes producible** for the first time."*
- §10 P0.3: *"`FieldAlignedNetworkEventKind::TraceIntersection` is still declared and produced by nothing."*

**All three are false.** Three production emission sites exist in `finalize_field_aligned_events`
(`src/geometry/SurfaceCellTracing.cpp:1391`, `:1433`, `:1512`), the contact truncation has been there since CP3b, and accepted identities depend on it.

**Where the false belief came from, precisely.** `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` §0 records a *true* fact about a *different* event kind:

> *"`FieldAlignedNetworkEventKind::SingularityTermination` — declared since CP3b and, per CP4-DEFN §3.3, **never produced by anything** — finally acquires its producer."*

I carried that shape across to `TraceIntersection` without checking it. Q8 criterion 3's own wording reinforced it — *"that would mean crash-on-contact still has no witness"* — and each subsequent document inherited the claim from the one before it rather than from source.

**The mechanical reason it was never caught.** The CB9 investigation read `canonical_field_aligned_traces` — the tracing loop — in detail, and stopped at its boundary. **Crash-on-contact is not in the tracing loop.** It is in `finalize_field_aligned_events`, the next function in the same file, which runs *after* tracing completes. I audited the stage where I expected the mechanism to live and concluded from its absence there that it was absent everywhere.

**The lesson, recorded in `LESSONS.md`:** an absence is only evidence when the search space was bounded first. Before writing "X is produced by nothing", grep for X.

---

## 2. What the accepted implementation actually does

Three sites emit `TraceIntersection`, and they mean **three different things**.

### Site A — multi-trace junction at a shared singularity origin (`:1391`)

When more than one trace shares a singularity port node, a `TraceIntersection` is emitted at that node with every trace incident as `Interior`. The traces do not cross there — they **originate** there and diverge. The code's own comment says so: *"the companion intersection record declares the multi-trace junction without consuming the ports again."*

**This is the site the accepted identity `FieldAlignedCurveNetwork.DeclaresTraceIntersectionsAsTypedNetworkEvents` (`tests/FieldAlignedCurveNetworkTests.cpp:1345`) asserts**, and its own message confirms the intent: *"multi-port singularity must be an explicit exact trace junction"*. That identity has nothing to do with crash-on-contact.

### Site B — first-contact truncation (`:1433`) — **this is the crash-on-contact**

```cpp
const auto contact = field_aligned_first_trace_contact(candidate.candidateTraces, traceIndex);
if (contact.has_value()) {
  trace.segments.erase(trace.segments.begin() + (contact->segmentIndex + 1U), trace.segments.end());
  trace.terminalBarrier.reset();
  trace.terminalPoint.reset();
  trace.terminalSingularity.reset();
  const auto contactNode = field_aligned_append_contact_node(candidate, contact->sourceFace);
  ...
```

A later trace is truncated at its first contact with an earlier one, its terminus is cleared, a contact node is created, and `FirstContact` + `TraceIntersection` are emitted with the earlier trace `Interior` and the later trace `Terminal`.

### Site C — self-closure on a revisited face (`:1512`)

A trace that ends with no singularity, no barrier and no contact is checked for `closesOnEarlierState` — whether the face it would enter next is one it has already visited. If so, a `TraceIntersection` is emitted with the trace itself `Terminal`. If not, the build fails with `InvalidNetworkTerminalOwnership`.

---

## 3. The four defects, each verified from source

### D1 — the contact predicate is "the two segments are in the same face"

`field_aligned_first_trace_contact` (`src/geometry/SurfaceCellTracing.cpp:1278-1307`). The entire geometric content is one line:

```cpp
if (segment.sourceFace != existingSegment.sourceFace) continue;
```

Everything after it returns a contact. There is **no crossing test, no position, no geometry at all**. Two traces that merely pass through the same triangle — on parallel, non-crossing, arbitrarily distant paths — are declared to be in contact, and the later one is truncated.

This is strictly coarser than the frozen CP4c-0b §3.2 predicate, and it is coarse in the direction that **destroys** traces rather than preserving them. `field_aligned_common_carrier` (`:1243`) is then used only to *label* the contact with a shared edge if one happens to exist; it does not gate the contact.

### D2 — priority is trace index order

```cpp
for (std::size_t existingIndex = 0U; existingIndex < traceIndex; ++existingIndex)
```

The trace with the lower index always wins. That is precisely `TraceSeniority`, the option CP4c-0b §4.2 ranks **worst** and §5 forbids as the production algorithm: order-dependent, non-canonical, and visibly symmetry-breaking on symmetric inputs. It is currently the shipped behaviour.

### D3 — the contact node is placed at an arbitrary corner of the face

`field_aligned_append_contact_node` (`:1310-1318`):

```cpp
candidate.nodes.emplace_back(node.value(), sourceFace.vertices().front());
```

`sourceFace.vertices()` is the **sorted** key, so `.front()` is the lowest-numbered vertex of the triangle. The node's `sourceVertex` is therefore unrelated to where the traces actually meet. Every contact node in a given face lands on the same corner regardless of geometry. The same helper is used for barrier terminations (`:1461`) and self-closures (`:1498`).

### D4 — it runs after tracing completes, so it cannot prevent non-termination

`canonical_field_aligned_candidate` (`:1804-1817`) calls `canonical_field_aligned_traces` first and **returns its error immediately** if tracing fails; only on success does it call `finalize_field_aligned_events`.

**Therefore the contact pass is unreachable for any trace that does not finish building.** The six circulating prescribed-sphere traces are rejected inside the tracing loop — by N1 today, by the step budget if N1 were removed, by the exact-arithmetic blowup before CB9 — and never reach the pass that would have truncated them. This is the mechanism behind TB-R8's 853 seconds, and it is why *"crash-on-contact exists"* and *"the sphere circulates forever"* are both true at once.

It is also the shape `DESIGN.md` §4.6 explicitly disclaims: *"the non-crossing guarantee is structural rather than a post-hoc repair."* A truncation pass applied to finished traces is a post-hoc repair.

### D5 — `TraceIntersection` is overloaded across three distinct meanings

Origin junction (A), crash-on-contact (B), and self-closure (C) all emit the same kind. `LESSONS.md` §2 records exactly what this costs: `RegionCutComponentCountDeficit` at 18 sites made the torus failure unlocalizable, and splitting it is what made TB-R3 informative. The event vocabulary has the same defect, and it is why a reader of the event stream cannot tell a divergence from a collision.

### D6 — truncation erases a legitimate terminus

`trace.terminalBarrier.reset(); trace.terminalPoint.reset(); trace.terminalSingularity.reset();`

A trace that legitimately reached a singularity or a hard rail **loses that fact** if any lower-indexed trace happens to share one of its faces. Under D1's predicate that is not a rare event, and the erased terminus is the datum CP4c-0b §3.4 requires to be exhaustive.

---

## 4. What this changes about CP4c-0b

| Frozen statement | Status | Correction |
|---|---|---|
| §2 "A2a does not implement crash-on-contact" | **False** | It implements it defectively, post-hoc, in `finalize_field_aligned_events` |
| §3.2 contact predicate is new work | **Partly false** | The call site and control flow exist; the *predicate* must be replaced |
| §3.3 the node and event are new | **False** | `NetworkNodeId`, `FirstContact`, `TraceIntersection` and both incidence roles exist and are accepted |
| §3.3 "the struck trace is not split" | **Holds** | Current code does not split the struck trace either |
| §4 arrival priority is an open choice | **Holds, and is now also a correction** | Seniority is the shipped behaviour and must be replaced, not merely chosen against |
| §5 simultaneity | **Holds, and is the main structural change** | Contact must move from the finalize pass into the trace loop |
| §7 re-proof surface | **Materially understated** | CP3b and CP4ab identities assert the *current* contact behaviour; see §5 |
| §10 P0.2 / P0.3 | **P0.2 holds, P0.3 false** | Replaced by S0 |
| Q8 criterion 3 | **Re-read required** | A *terminal* `TraceIntersection` is already producible at sites B and C; the criterion must name the sphere and the corrected predicate, or it is satisfiable by the defect |

**Q8 criterion 3 deserves particular care.** As frozen it reads "at least one terminal `TraceIntersection`". Sites B and C both produce `Terminal` incidences today, so on the current code the criterion could be reported satisfied by a shared-face truncation that is not a crossing at all. **It must be re-stated to require a contact produced by the corrected predicate on the prescribed sphere.** That is a clarification of intent, not a weakening: it names the outcome the criterion always meant.

---

## 5. The re-proof surface, re-derived

This is the part §7 got wrong, and it is the reason S1 (§6) must run before any semantic change.

Changing the predicate from **shared face** to **proper crossing** strictly *reduces* the set of contacts. Every accepted trace that is currently truncated by a non-crossing shared-face contact would, under the corrected predicate, **continue** — changing its segments, its terminus, its events, the node set, and every digest downstream.

| Accepted authority | Exposure |
|---|---|
| **M3-CP3b** — `DeclaresTraceIntersectionsAsTypedNetworkEvents` | **Low.** It asserts site A, the origin junction, which the correction does not touch — but it must be re-read, because splitting the event vocabulary (S2) changes which kind that site emits |
| **M3-CP3b** — `PublishesTypedFirstContactAndTerminationEvents`, and the identity at `tests/FieldAlignedCurveNetworkTests.cpp:1196-1216` requiring a declared `FirstContact` per terminal trace | **High.** These assert the current contact behaviour on the two-ring |
| **M3-CP3a** — trace content and digests | **High if any accepted trace is currently truncated by a non-crossing contact** |
| **M3-CP4ab** — node counts, arcs, regions, `network_digest`, and `EXPECT_EQ(8U, network.nodes().size())` | **High.** Node identity comes from `field_aligned_append_contact_node`; both the count and the `sourceVertex` of every contact node are in scope |
| **M3-CP4c-0 (346)** | **Low** — continuation identities are untouched — but the whole gate must be re-proved |

**None of this can be estimated. It must be measured**, and that measurement is cheap because it requires no semantic change at all.

---

## 6. Corrective measures — series **S**, superseding P0–P9

`M3-CP4c-0b-CB1` resumes under these. Code + Build only; runtime forbidden; GMP linkage mandatory per `GMP_COMPILE_POLICY.md`; all eight standard targets compiled.

### S0 — corrected binding preconditions

Replaces P0 in full. Stop and return to review if any fails.

- **S0.1** CP4c-0 is **ACCEPTED at 346/346** with selector SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.
- **S0.2** `FieldAlignedCandidateTrace` still has exactly `terminalSingularity` and `terminalBarrier` and **no** contact datum. *(P0.2, unchanged, verified true.)*
- **S0.3 — replaces the false P0.3.** `FieldAlignedNetworkEventKind::TraceIntersection` is **produced at exactly three sites** in `finalize_field_aligned_events` — the singularity junction, the first-contact truncation, and the self-closure — and `field_aligned_first_trace_contact` still gates contact on `segment.sourceFace != existingSegment.sourceFace` alone. **If any of that is no longer true, the source has moved and this plan is stale.**
- **S0.4** `field_aligned_append_contact_node` still places the node at `sourceFace.vertices().front()`.
- **S0.5** `canonical_field_aligned_candidate` still calls `canonical_field_aligned_traces` before `finalize_field_aligned_events` and returns the tracing error without reaching finalize.
- **S0.6** N1, N2 and N4 are present and unmodified.
- **S0.7** The compile is GMP-backed and the package records `exactArithmeticBackend=GMP`.

### S1 — the contact census, **before any semantic change**

**This is the first measure and nothing else may precede it.** Add a non-gating census that changes no production behaviour and publishes, per witness that reaches A2a:

1. every contact the **current shared-face** predicate fires, with the two trace ids, the segment indices, the face, and the labelled shared carrier if any;
2. for each, whether the two segments **properly cross** under an exact barycentric orientation test — computed in the census only, consuming nothing;
3. for each truncated trace, the terminal kind it held **before** truncation (`terminalSingularity`, `terminalBarrier`, or none);
4. total node count, the `sourceVertex` of every contact node, and the event-kind histogram;
5. how many contacts are attributable to site A, site B and site C respectively.

**Falsifiable predictions.** On the two-ring and the fan: if **every** current contact is also a proper crossing, the predicate correction is behaviour-preserving on accepted authority and S3 is safe. **If any current contact is not a proper crossing, changing the predicate changes accepted networks**, and that is a plan decision, not a CB decision — **stop and return to review with the census**.

The prescribed sphere will publish nothing for this census while N1 rejects it during tracing; record that explicitly rather than reporting zero contacts.

### S2 — split the overloaded event vocabulary

`TraceIntersection` currently means three things (D5). Split it so an event stream is readable:

- **origin junction** (site A) — a new kind, e.g. `SingularityPortJunction`, for traces that share an origin and diverge;
- **trace contact** (site B) — `TraceIntersection` keeps this meaning, which is the one its name asserts;
- **self-closure** (site C) — a new kind, e.g. `TraceSelfClosure`, for a trace that closes on its own earlier state.

Every existing enum value is **retained and never reused**. Adding kinds re-opens CP3b's terminal-kind exhaustivity assumption exactly as DEFN-1 §6.4 warned for `SingularityTermination`; **every accepted identity asserting event-kind or terminal-kind exhaustivity must be re-read and named in the CB report**.

### S3 — the exact proper-crossing predicate

Replace the shared-face test in `field_aligned_first_trace_contact` with CP4c-0b §3.2: proper transversal crossing of the two segments in exact rational barycentric arithmetic, all four orientation determinants non-zero with disagreeing sign pairs. Shared singularity origins remain excluded — the existing guard at `:1296-1301` already does this and must be preserved. Endpoint touches and collinear overlaps become **typed observations**, not contacts.

`field_aligned_common_carrier` is demoted to what it already is: a diagnostic label, never a gate.

### S4 — arrival priority replaces seniority

Implement CP4c-0b §4.3's `ArcLengthFiltered` with the **computed** forward error bound; a literal epsilon anywhere in that path is a stop condition. Inconclusive comparisons and exact ties resolve to **mutual termination** (§4.4–§4.5). The `existingIndex < traceIndex` loop bound is **removed** — it is the seniority metric, and it must not survive as a tiebreak.

Implement §4.6's alternatives harness, with `ArcLengthFiltered` the only value the production entry path can produce.

### S5 — relocate contact into the trace loop

**The structural change, and the one that fixes the sphere.** Contact detection moves from `finalize_field_aligned_events` into the tracing advance, under §5's global priority queue, so a trace terminates *when* it crashes rather than being truncated after it has already run forever. D4 proves the post-hoc pass can never terminate a circulating trace, so no amount of predicate correction alone reaches Q8 criterion 2.

`finalize_field_aligned_events` keeps event publication and node allocation; it loses the truncation and the terminus reset (D6).

### S6 — node position and the terminal datum

The contact node's `sourceVertex` currently ignores geometry (D3). Publish the contact's exact `FieldBoundaryPoint`-equivalent position on `FieldAlignedCandidateTrace::terminalContact` per §3.3, and record in the CB report whether `NetworkNode::sourceVertex` can remain a face corner without misleading A2b. **Do not give `NetworkNodeId` positional meaning** — CP4ab Amendment 11 and CP4c-0 §12 both forbid it; the position rides on the trace, not on the node.

Assert exhaustivity: every completed trace sets **exactly one** of `terminalSingularity`, `terminalBarrier`, `terminalContact`.

### S7 — migration and re-proof

Re-run accepted **316** and CP4c-0's **346**. Name in the CB report every identity re-authored and why. **An accepted identity requiring an expectation edit is a stop**, unless S1's census proved in advance that the correction changes that witness and the plan authorised it.

### S8 — prohibited

No A1 change. No tolerance, literal epsilon, or tuned constant in the contact predicate or the priority comparison. No production-reachable priority argument. No length-based termination. No sequential tracing in production. No reuse of a retired enum value. No change to the CP4c-1 **318** selector. No runtime execution.

---

## 7. Amendment A1 to the CP4c-0b frozen definitions

> **AMENDMENT A1 — crash-on-contact already exists, defectively, in accepted authority.**
> §2's statement that A2a does not implement crash-on-contact, §7's statement that `TraceIntersection`
> becomes producible for the first time, and precondition **P0.3** are **withdrawn as false**.
> `finalize_field_aligned_events` has produced `TraceIntersection` since CP3b at three sites, and
> truncates a trace at its first contact with an earlier one.
>
> **The mechanism is defective in six respects, each verified from source:** the contact predicate is
> *"the two segments are in the same face"* with no crossing test; priority is trace index order, which
> is the `TraceSeniority` metric §4.2 ranks worst; the contact node is placed at the face's
> lowest-numbered vertex rather than at the contact; the pass runs **after** tracing completes and is
> therefore unreachable for a trace that never finishes, which is why the prescribed sphere circulates;
> `TraceIntersection` is overloaded across origin junction, crash-on-contact and self-closure; and
> truncation **erases** a legitimate `terminalSingularity` or `terminalBarrier`.
>
> **CP4c-0b is therefore a correction and relocation of accepted authority, not a greenfield addition.**
> §7's re-proof matrix is superseded by `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md` §5,
> and measures **P0–P9** are superseded by **S0–S8** in §6 of that record. **Q8 criterion 3 must be
> re-stated to require a contact produced by the corrected predicate on the prescribed sphere**, because
> a *terminal* `TraceIntersection` is already producible by the defect.
>
> **No semantic change may precede measure S1**, the contact census, which decides whether correcting
> the predicate changes accepted authority.

---

## 8. Standing stop conditions, extended

The CP4c-0b §11 list stands. Added:

- S1's census shows a current contact that is **not** a proper crossing on an accepted witness, and the response proposed is to change the predicate anyway rather than return to review;
- a retired event-kind value is reused for a new meaning;
- the seniority loop bound survives as a tiebreak under any name;
- `NetworkNodeId` acquires positional meaning;
- a trace ends with zero or more than one terminal kind set;
- contact detection remains in `finalize_field_aligned_events` after S5.

---

## 9. Durable lessons

- **An absence is only evidence when the search space was bounded first.** "Declared but produced by nothing" is a claim about the whole codebase, and it was written after auditing one function. One `grep` for the enum value would have falsified it. Before asserting that something is never produced, search for it and record the search.
- **A true fact about one enum value is not a fact about its neighbour.** `SingularityTermination` genuinely was produced by nothing; `TraceIntersection` never was. The shape of the first claim was carried onto the second across four documents without re-derivation.
- **When a mechanism seems missing, check the next stage before concluding it does not exist.** Crash-on-contact was one function further down the same file, in the finalize pass rather than the tracing loop. The investigation stopped at the boundary of the stage where the mechanism was expected.
- **A mechanism that exists but runs at the wrong stage is worse than one that is absent**, because its presence suppresses the search. The contact pass, the contact node and the event vocabulary all existed, were accepted, and were cited in a closure record — and none of it could terminate a trace, because it ran after the traces were already built.
- **A binding precondition that fails is the plan working, not the turn failing.** CB1 spent no build, no runtime and no product change discovering a false premise that had survived four documents and one accepted checkpoint. That is exactly what P0 is for.

---

## 10. Accounting and exact successor

- accepted runtime authority: **M3-CP4c-0 346/346**, GMP package `9649395432`, run/job `33079817998 / 98543736213`; M3-CP4ab **316/316** beneath it
- CP4c-0b gate: still to be frozen by CB1 as `346 + n`
- CP4c-1 selector **318**, unchanged
- stable regression accounting **42 / 14 / 28**, produced-witness debt **5** — unchanged; this turn executed nothing and the defects it names are in accepted authority rather than new regressions
- **new candidate `M3-CP4c0b-P03-CAND-01`** — the accepted contact mechanism's six defects (D1–D6). Product semantics, pre-existing, latent behind small accepted witnesses. Owned by S1–S6; not resolved until CP4c-0b's TB is green.

**Exact next: `M3-CP4c-0b-CB1`, resumed under S0–S8**, beginning with S0's corrected preconditions and then S1's census. **S1 must complete and be reviewed before S2–S6 change any semantics** if its census shows a current contact that is not a proper crossing on an accepted witness.

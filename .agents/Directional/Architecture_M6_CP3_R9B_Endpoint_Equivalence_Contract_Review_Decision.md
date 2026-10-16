# Architecture Review Decision — M6 CP3 R9B endpoint equivalence contract (rung 19b)

**Review turn:** `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (rung 19b)
**Frozen amendment:** RA-79
**Verdict:** **ACCEPTED.** The strongest Definition turn in this ladder. It **narrows my own
RA-78.3**, refuses two relaxations I did not ask about, and declines to claim the one thing
that would have been convenient. Two charges, one of them partly mine.
**Review window:** 2026-10-16T13:01:40Z — 2026-10-16T13:52:14Z
**Semantic source:** unchanged at `f0d7240455b10237af47de58c035cd4c576d889a`

---

## RA-79.1 Provenance and boundary

| check | result |
|---|---|
| snapshot artifact `12047105604` (run `38901551349`) | digest `74a2ea191e777cd186ceeb0d272e4b7ccae6e2112477a95934b9b04f90abbc57`, matches; `conclusion=success` |
| `src`/`include`/`tests` at `6eda761dd`, `f0d724045`, `HEAD` | **tree-identical** — `b65cb9b2c7…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |
| `ledgers --base 87b770b6d` | **ALL CHECKS PASSED** |

The Drive transport failure (`container_session_unavailable`) was disclosed with the
explicit instruction "do not represent it as a successful Drive application."

## RA-79.2 It narrows RA-78.3, and the narrowing is correct

I wrote at RA-78.3 that the repair is "**a precedent to apply consistently, not an
invention**." The specification accepts the precedent and then refuses the inference I
drew from it:

> "The existence of this valid *contract shape* is not a proof that any of the 21 observed
> failing endpoint pairs satisfies all its conjuncts."

That is right, and it matters. The vertex branch does not accept *same vertex, different
face*. It accepts that **only when** a published open-rail terminal contact exists and
agrees on component; **and** both points decode the same `SourceVertexId` with bit-exact
one-hot barycentrics; **and** a unique admissible non-hard-feature A3 star path runs from
each side's actual attachment face to the correspondingly oriented carrier face; **and**
the two directed-side face sets are disjoint; **and** exactly one carrier orientation is
admissible. **Whether the measured 21 satisfy that conjunction is unmeasured.** My framing
collapsed a five-part conjunct into "a precedent." **RA-78.3 is NARROWED accordingly.**

## RA-79.3 It specifies against both checkers, as required

§3 is an explicit correspondence table over six obligations — source contact and face
attachments, carrier orientation, vertex-star path, side separation, interior position,
closed chains — each with its anchors in **both** the A4 endpoint certificate and the
checked-product verifier. And it states the residual honestly:

> "The implementations are not literally identical… **Pass/fail equivalence is a goal
> subject to implementation Review and independent tamper oracles, not an asserted fact.**
> Preserve the verifier as an independent oracle; do not make it accept merely because a
> certificate constructor returned non-null."

That last sentence is the right instinct about a two-oracle design and was not asked for.

## RA-79.4 It refuses two relaxations I did not ask about

I required only that the contract not weaken admission. The specification goes further and
**declines to extend itself** into two branches where extension would have been easy:

- **Branch I (interior), deliberately NOT relaxed.** Exact `FieldExactRational` equality is
  retained, and the measured one-ULP population is named and refused: "This specification
  **does not** authorize accepting those pairs, a tolerance, rounding, moving points, or
  canonicalization from near equality… The 21 currently localized cases are vertex
  observations, not evidence to relax the interior gate."
- **Branch C (closed rail), deliberately NOT promoted.** "**Do not invent terminal-vertex
  authority for a closed rail.** A future closed-chain attachment generalization requires
  separately published cyclic-sector authority and a separate review."

It also rejects, by name, selecting "a carrier orientation, star route or corner
representative by minimum face index alone" as "**inadmissible, may weaken
`Missing`/`Ambiguous`**" — refusing as a *repair mechanism* the very rule RA-72.6
identified as the producer's selection discipline. That is a sharp distinction correctly
drawn.

And it honours RA-78.4's boundary exactly: "**no synthetic producer-side vertex-star
certificate is introduced.**"

## RA-79.5 The non-weakening obligation is met, including the concrete case

§4 gives ten counterexample classes with required dispositions — `Missing` and `Ambiguous`
both still excluded, overlapping sectors still excluded, two admissible orientations still
excluded, inferred or near-corner terminals still excluded.

I asked specifically for **at least one endpoint the current rule rejects that the new rule
also rejects, drawn from the fixture or the measured population**. The specification
supplies it without labelling it as such: the row *"Interior points on same canonical edge
but rational parameters differ by one ULP → Reject under I until a separately reviewed
exact authority exists; no epsilon"* is exactly that — **324 measured instances**
(RA-76.1), currently rejected by `same_interior_carrier_point`, and still rejected under
branch I. The obligation is **met**; only the labelling is missing.

Five falsifiers F1–F5 are stated, with "Any F1/F2/F4/F5 defeats this contract shape; do not
implement as a blanket rule."

## RA-79.6 CHARGE — the beacon is self-referential again, and now contradicts its own document

`STATUS` reads `Turn: M6-CP3-DEFN-R9B-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`,
`Status: IN_PROGRESS`, `Successor:` naming that same turn. **Seven consecutive NEXT_TURN
blocks have required `Successor` be left EMPTY while in progress and never self-naming
(RA-67.11).** It was correct for three rungs and has recurred.

What makes this worse than the previous instances: the specification's own closing says
"**successor remains `UNKNOWN`**." The machine-read field therefore **contradicts the prose
of the document it belongs to**. A successor reading the beacon is handed a cycle; a
successor reading the document is told `UNKNOWN`. The document is right.

## RA-79.7 CHARGE — gates still unreported, and the instruction conflict is mine

No gate output appears anywhere in the turn's additions. That is the **seventh** mandate,
and the first since I reduced the ask to pasting two lines.

**But my instruction was self-contradictory and I own that.** I wrote both "If either says
FAILED, STOP AND SAY SO rather than pushing" and "ledgers with any base earlier than
`b2b6e6541` FAILS PERMANENTLY… hence the base above." A turn that ran a wider base would
see `FAILED` and, obeying the first clause, stop — which is what the commit
`a86c91e86` ("preserve R9B turn pending historical ledger closeout verification") and the
open beacon suggest happened. **Stopping rather than pushing past a FAILED gate is the
behaviour I want**; the conflict that triggered it is my drafting.

**Resolved once, unambiguously, and frozen here:**

> The mandated base is **always the last Review commit**, and nothing else. The historical
> failure at `b2b6e6541` is **permanent, expected, and never a reason to hold a turn**. The
> "stop on FAILED" rule applies **only** to a run at the mandated base. Do not run `ledgers`
> against any earlier base as a closeout check.

With that resolved, the residue of the charge is narrow: the `boundary` gate was also
unreported, and it has no such ambiguity.

## RA-79.8 NOTE — the tracker and frozen definitions were not written

`Regression_Root_Cause_Tracker.md` (fifth omission) and
`Architecture_M6_Frozen_Definitions.md` were not touched; `ORIENTATION.md` **was** written
this time. Not charged — the Review writes the authoritative sections regardless.

## RA-79.9 `RP-01` state and what it now requires

The contract shape is **admissible**: branch V is expressible entirely from witnesses that
already exist — `SurfaceTracePoint` faces and one-hot barycentrics, typed terminal
contacts, the published carrier and field atlas, source incidence and hard-edge maps, with
`unique_terminal_star_path` already computed consumer-side at `:8452` and already enforced
at `:8685-8699`. **RA-65.5 is satisfied without a new producer.**

What is **not** established is whether the measured 21 satisfy V's conjunction. That is an
empirical question with an existing instrument, and it is the spec's own **F1** and **F2**.
**Code remains NOT authorized** until it is answered: implementing a contract and then
discovering the target population fails one of its conjuncts would cost a full
code-plus-measurement cycle to learn what one probe can settle. `RP-02` **UNREACHED**.

## RA-79.10 LESSON — a precedent is a conjunction, and the reviewer collapsed it

RA-78.3 reported that the product verifier "already accepts same vertex, different face,
reconciled by a unique star path," and treated that as licensing the repair. The verifier
accepts a **five-part conjunction** of which the star path is one part. **When citing
existing behaviour as precedent for a change, enumerate every conjunct that behaviour
requires, and say which of them the target population is known to satisfy.** An
under-stated precedent is an over-stated licence.

---

## Rung 20 — scope

`M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE`, **compile-only, rejection-only**, in the rung 12
and 17 pattern. The question is the spec's own F1/F2: **do the measured 21 satisfy branch
V's conjuncts?** For each rejected endpoint pair, emit:

1. whether a published `hardRailTerminalContacts[rail]` exists, its component, and whether
   the decoded vertex is one of its published endpoints and an endpoint of the carrier's
   canonical source edge;
2. whether **both** points decode the same `SourceVertexId` with **bit-exact one-hot**
   barycentrics in their own faces;
3. the result of `unique_terminal_star_path(vertex, attachment, carrierFace)` — `Unique`,
   `Missing`, `Ambiguous` or `Invalid` — **for each side and for both carrier
   orientations**, by calling the existing function, not reimplementing it;
4. whether the two directed-side face sets are disjoint, and how many carrier orientations
   are admissible.

Rung 21 harvests; rung 22 implements only if the conjunction holds. If it does not, the
contract is sound and the 21 are outside it, which is equally a result (RA-68.12).

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by rung 19b or by this Review. PR #8
draft/open.

`R4-VIN-01` remains armed at `f0d724045` with **no new semantic source**; every earlier
artifact through `12040008801` and `12047105604` is a **baseline, never a comparand**. The
44 RED remain the baseline for `f0d724045` alone, candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED and CONFIRMED. RA-76.8
AMENDED. RA-78.3 NARROWED (this decision). Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for
`RP-01` (RA-70.11), boundary per RA-78.4.** `PROCESS-01` discharged. **`RP-03` satisfied a
fourteenth turn** — it refused the inference the reviewer had drawn from its own census.
The historical `ledgers` failure at `b2b6e6541` remains permanent for any earlier base, is
correct, must not be suppressed, and **must never hold a turn open** (RA-79.7).

**Successor:** `M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE` (rung 20).

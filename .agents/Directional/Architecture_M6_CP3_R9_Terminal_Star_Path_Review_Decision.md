# Architecture Review Decision — M6 CP3 R9 terminal star path (rungs 20 and 21)

**Review turn:** `M6-CP3-R9-TERMINAL-STAR-PATH-REV`
**Adjudicated:** `M6-CP3-CB9-R9-TERMINAL-STAR-PATH-PROBE` (rung 20) and
`M6-CP3-TB9-R9-TERMINAL-STAR-PATH-HARVEST` (rung 21)
**Frozen amendment:** RA-80
**Verdict:** both **ACCEPTED**. **Branch V is measured NOT APPLICABLE to the 21 — 0/21** —
and the star path, the part everyone expected to fail, **passes**. One charge, one
persistent note.
**Review window:** 2026-10-16T16:30:08Z — 2026-10-16T17:24:51Z
**Semantic source:** `18cc4da5e2bc41138c5363a74de4e2db1e28ef23` (new — `R4-VIN-01` re-arms)

---

## RA-80.1 THE RESULT — 0/21, and the failing conjunct is not the one under investigation

Re-derived independently from the raw logs inside result artifact `12055460315`, by literal
field scan — not from the harness summary and not from the turn's own cross-check. **44 log
files, 48 `a3Probe` records, 21 with `a3ProbeSameExactOneHotVertex=1`, 27 without.** Across
all 21, every field is invariant:

| conjunct | all 21 |
|---|---|
| `a3ProbeContactPublished` | `1` |
| `a3ProbeComponentMatches` | `1` |
| `a3ProbeSameExactOneHotVertex` | `1` |
| **`a3ProbePublishedCarrierEndpoint`** | **`0`** |
| `a3ProbeOrientation0First` / `Second` | **`Unique` / `Unique`** |
| `a3ProbeOrientation0Disjoint` / `CarrierA3` | **`1` / `1`** |
| `a3ProbeOrientation1First` / `Second` | `Missing` / `Missing` |
| `a3ProbeOrientation1Disjoint` / `CarrierA3` | `0` / `1` |
| **`a3ProbeAdmissibleOrientationCount`** | **`0`** |

Conjunction satisfied: **0 of 21**.

**The star path passes.** Under orientation 0 both sides return `Unique`, the directed-side
face sets are **disjoint**, and the carrier A3 transport validates. That is the relation
nine rungs of this investigation converged on, and it holds. What fails is
`a3ProbePublishedCarrierEndpoint` — a membership test nobody had examined.

The turn is right that orientation 1's `Missing/Missing` does not invalidate orientation 0,
and right to note that `a3ProbePublishedCarrierEndpoint` is a **composite** of
published-contact endpoint membership and canonical carrier-edge endpoint membership —
and right to refuse to guess which half fails: "**this probe does not resolve which
subcondition fails. Avoid inventing that subclassification.**"

**Branch V is therefore not applicable to the measured 21. This does not make the contract
unsound**, and the turn draws that distinction correctly.

## RA-80.2 The hoist is semantics-preserving — verified by expansion, not accepted

Rung 20 changed 270 lines and **deleted the production predicate
`unique_terminal_star_path`** from the checked-product verifier. A diff that removes an
active admission predicate inside a turn mandated decision-neutral is the most serious
shape available, so each difference was checked individually.

The lambda was promoted to a free function at `src/geometry/SurfaceCellTracing.cpp:8166`,
with a capture-binding wrapper `unique_terminal_star_path_checked` at `:8520` called at
`:8727` where the original call stood. One clause changed:

```cpp
// before
if (!forward || !matchesA3(spoke, incident[0], incident[1], forward->transport))
// after
if (!forward || !reverse || reverse->transport != forward->transport.inverse())
```

`matchesA3(edge, from, to, expected)` (`:8254-8267`) returns
`forward && reverse && forward->transport == expected && reverse->transport == expected.inverse()`.
Here `expected` **is bound to `forward->transport` itself**, so `forward->transport == expected`
is a self-comparison and vacuous; and its row lookups duplicate `firstRow`/`secondRow`,
whose inequality is already enforced two lines above in both versions. The predicate
therefore reduces **exactly** to `forward && reverse && reverse->transport ==
forward->transport.inverse()`. **The substitution is an exact inlining, not a change.**

Three residuals, each checked:

- the added `|| fieldTransportAtlas == nullptr` guard is **unreachable in production** — the
  verifier already rejects a null atlas at `:8245`, before `:8520`;
- `uniquePathFaces` defaults to `nullptr` and the production wrapper passes nothing, so
  `clear()` and the assignment never execute on the production path;
- the call site at `:8724-8737` is structurally unchanged — same two attachment/carrier
  pairs, `Unique → continue`, and the same `MissingTerminalA3Path` /
  `AmbiguousTerminalA3Path` detail codes on `InvalidSourceAuthority`.

**No production admission change.** And the probe **calls the hoisted function** rather than
reimplementing it, which is the RA-73.10 discipline honoured exactly.

## RA-80.3 CHARGE — the inlining was not named, and that is where review time went

The record says the turn "factored the independent checked-product verifier's A3 path
algorithm into an exact shared evaluation routine" and that there is "**no change to
matching, source/topology authority, predicate results, acceptance, rejection messages or
route selection**." Both statements are **true**, and the second is the right claim to
make. But neither mentions that **`matchesA3` was removed from the predicate and replaced
by its inlined equivalent**.

A reviewer confronting a 270-line diff that deletes an active admission predicate cannot
take "no change to predicate results" on trust — that is precisely the claim under test. I
had to reconstruct the equivalence from `matchesA3`'s body and observe that its `expected`
argument was bound to `forward->transport`, making one conjunct vacuous. **One sentence in
the record** — *"`matchesA3` is inlined here; its `expected` conjunct was self-comparing and
drops out"* — **would have replaced that derivation.**

**When a refactor substitutes a predicate call for its inlined equivalent, name the
substitution and state why it is equivalent.** The obligation is heaviest exactly where the
claim is "nothing changed."

## RA-80.4 Credits

- **It cross-checked its own instrument.** The harness verifies execution and the 2,628
  older `a2bProbe` records but "**does not aggregate `a3Probe` directly**," so the turn ran a
  separate literal-field scan of all 44 raw logs and said so. My own independent scan
  reproduces its table **exactly**. An agent noticing that its summary path does not cover
  its new fields, and closing that gap before reporting, is new behaviour in this ladder.
- **It named the deciding conjunct and refused to subclassify it**, warning explicitly
  against inventing the split. That is RP-03 and RA-68.12 together.
- **It distinguished "not applicable to the 21" from "contract unsound."**
- **Four disclosed failures, all independently `conclusion=failure`:** `38911565252`
  (targets as a string, not an array), `38914058261` (forbidden `retention_days`),
  `38914322511` and `38915195172` (compile errors: a missing `probeCarrier` declaration and
  a ternary mixing `DomainResult<SourceVertexId>` with `std::nullopt`). Each named with its
  run id and corrected minimally.
- **Durable discipline improved:** `Regression_Root_Cause_Tracker.md` and `ORIENTATION.md`
  were both written, after five and three consecutive omissions respectively (RA-79.8
  absorbed). The beacon is `COMPLETE` with `Successor: UNKNOWN` and reasoning in the owning
  document — **RA-79.6 absorbed**.
- Artifacts verified: snapshot `12049916826` `6ec4ad5429…`, compile `12052388003`
  `ed250e970a…`, result `12055460315` ZIP **recomputed** `fa729d87b7…`, manifest **49 OK /
  0 BAD**, boundary `planned=44 executed=44 red=44 missing=0 postflight=True exit=0`. Probe
  blob `0bcf462a0e…` **= HEAD**; `include` and `tests` byte-identical.

**`RP-03` satisfied a fifteenth turn.**

## RA-80.5 NOTE — gates still unreported, eighth mandate

No `ALL CHECKS PASSED` line appears in either record. Both pass — I ran them. This is now
persistent enough that repeating it is not useful; it is recorded and carried, and the
durable-document discipline it sits beside has visibly improved.

## RA-80.6 `RP-01` state

Branch V is **measured not applicable** to the 21. The contract stands; it does not cover
them. The frontier is now the composite `a3ProbePublishedCarrierEndpoint`, whose two halves
have never been measured separately. **Code remains NOT authorized.** `RP-02`
**UNREACHED**.

## RA-80.7 A prediction for rung 22, with its falsifier and observation rung named

From the fixture (`tests/SurfaceCellsPhase10Tests.cpp:223-273`) the carrier edge measured
at RA-70 is `{1,4}` and the decoded vertex is `4` — so *vertex is an endpoint of the
carrier's canonical source edge* should hold, which points at the **published terminal
contact's endpoint set** as the failing half.

**Falsifier:** if the carrier reaching the endpoint certificate differs from the one RA-70
measured, or the decoded vertex is not an endpoint of it, the other half fails instead.
**Observation rung: 22.** Recorded as a prediction with provenance (RA-61.5) and its rung
named (RA-64.12) — **not** as the subclassification rung 21 warned against inventing,
because rung 22 *measures* it rather than asserting it.

## RA-80.8 LESSON — the conjunct that fails is rarely the one under investigation

Nine rungs converged on the star-path relation, and the star path **passes**: `Unique` on
both sides, disjoint sectors, valid A3 transport, on the admissible orientation. The
conjunct that fails is a membership test no rung had examined. **When a multi-part
predicate rejects, measure every conjunct, not the interesting one** — the interesting one
is where attention has already been spent, and therefore the least likely to be the
unexamined defect.

---

## Rung 22 — scope

`M6-CP3-CB10-R9-CARRIER-ENDPOINT-SUBCONDITION-PROBE`, **compile-only, rejection-only**.
Split the composite into its two named halves and emit both sides' raw identities so the
comparison is readable rather than inferred:

1. is the decoded `SourceVertexId` a member of the published terminal contact's endpoint
   set? Emit that set's vertex ids;
2. is it an endpoint of the carrier's canonical `SourceEdgeTopologyKey`? Emit that edge's
   two vertex ids;
3. the decoded vertex id itself, and the carrier edge and rail id the certificate actually
   used at the point of the test.

Rung 23 harvests. Rung 24 — repair or a further definition — is **not authorized** and its
shape depends on which half fails.

---

## Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed by this
Review. No source, test, selector, binary, harness or workflow change by this Review. PR #8
draft/open.

**`R4-VIN-01` re-arms at `18cc4da5e`.** Every earlier artifact through `12047105604`,
`12049916826` and `12052388003` is a **baseline, never a comparand**. The 44 RED are the
baseline for `18cc4da5e` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED and CONFIRMED. RA-76.8
AMENDED. RA-78.3 NARROWED. Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01`
(RA-70.11), boundary per RA-78.4.** `PROCESS-01` discharged. The historical `ledgers`
failure at `b2b6e6541` remains permanent for any earlier base, is correct, must not be
suppressed, and must never hold a turn open (RA-79.7).

**Successor:** `M6-CP3-CB10-R9-CARRIER-ENDPOINT-SUBCONDITION-PROBE` (rung 22).

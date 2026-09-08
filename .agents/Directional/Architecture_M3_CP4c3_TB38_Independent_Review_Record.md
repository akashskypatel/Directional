# M3-CP4c-3-TB38 — Independent Review Record

**Turn:** `M3-CP4c-3-TB38-REV` — independent review (absorbs REVIEW + PLAN).
**Status:** STATIC / EVIDENCE-ONLY / NO RUNTIME / NO COMPILE / **STABLE — ONE NEW EVENT**.
**Measures:** **DA0–DA7**.
**Adjudicated evidence:** `Architecture_M3_CP4c3_TB38_EXEC_Report.md`, immutable package103 `10034608071` /
source `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`, selector409 run `34169783183`.
**Static-authority gate:** `review_check.py authority 2fcde465b1de2e42a348d224f5165ce8b87e4fbe`.

---

## DA0 — TB38 is mechanically valid, semantically RED, and is **NOT** promoted

The artifact-only boundary is clean: `script_exit=0`, `runtime_started/completed=true`,
`execution_view_verified=true`, `orchestration_failure=false`, `selection_integrity=true`, `timeout_count=0`, every
mutation/build/benchmark flag false; 409 identities executed exactly once; package, source and execution-view
censuses identical pre/post; selector409 byte-frozen at `eea6d8c2…`.

**Result: 395 PASS / 14 RED, accepted 1–365 = 362/365**, RED
`[356,357,362,366,367,368,369,370,374,390,393,398,406,407]`.

**The accepted prefix is broken.** TB38 is **not** promoted. **`M3-CP4c-3-TB37` remains the current valid semantic
runtime authority.** Package count advances to 103 as a build fact only.

---

## DA1 — CB43 is not at fault; the defect is in DEFN-R6

This must be stated first, because the natural reading of a regression is implementation error, and that reading is
wrong here.

CB43 implemented Part X **exactly as frozen**, including the parts that were easy to skip:

- it hoisted the sub-mesh accumulation out of the failure branch (CZ7.1);
- it added `totalVertexCount` / `totalEdgeCount` and computed χ from them (CZ7.2);
- it deleted **both** premise comments — `GlobalTopologyPlan.cpp` and the `vertexCount` comment in
  `GlobalTopologyPlan.h` (CZ7.3), which was the obligation Part X added over TB37-REV;
- it did **not** repurpose `vertexCount` or `edgeCount` (R6.6);
- it did **not** change region construction (CZ7.6);
- it extended `candidate_semantic_digest` for the new fields (CZ7.5).

**`DEFN-R6.4` — my definition — is what cost the accepted prefix.** Part X chose the whole-face source sub-mesh as
the certified complex and `χ = V_total − E_total + F = 1` as the criterion. On the torus fixture that criterion is
false.

---

## DA2 — the measurement, and why neither formula is correct

The regression's four accepted/protected surfaces reduce to **two** failure-detail bytes, and the deciding one is
the torus region shared by 356/357/362 and 367 (`d976514d…`):

```text
torus region:   X = 24   E_one = 24   B_int = 1
                V_total / E_total / F = 24 / 48 / 24      chiFull    = 0
                V_int   / E_int   / F =  0 / 23 / 24      chiReduced = 1
```

Cross-checks close: `E_both = 48 − 24 = 24`, `E_int = 24 − 1 = 23` ✓, and
`2·E_both + E_one = 48 + 24 = 72 = 3F` ✓. The region is 24 triangles with 24 vertices, 48 edges, 24 boundary
edges and **zero interior vertices** — a one-triangle-wide closed band. **χ_full = 0: an annulus.**

Now place it beside the mechanical region that motivated the correction:

| Fixture | `X` | `E_one` | `B_int` | `X − E_one − B_int` | χ_reduced | χ_full |
|---|---:|---:|---:|---:|---:|---:|
| mechanical (TB37, ordinals 366/367) | 36 | 20 | 12 | **+4** | −3 | **1** |
| torus (TB38, ordinals 356/357/362/367) | 24 | 24 | 1 | **−1** | **1** | 0 |

> **The discrepancy has opposite sign on the two fixtures. Neither formula is correct on both.**

The reduced form is right on the torus and wrong on the mechanical fixture; the full form is right on the
mechanical fixture and wrong on the torus. **A single measurement on a single fixture could not have distinguished
"this formula is correct" from "this formula happens to agree here"** — and DEFN-R6 had exactly one fixture's
numbers.

### DA2.1 — why the reduced form wins on the torus, stated structurally

The torus region has `B_int = 1`: **one** barrier edge with both incident faces inside the region. The reduced form
drops that edge from `E_int`; removing one edge from a complex raises χ by exactly 1, taking the annulus's `χ = 0`
to `χ = 1`. **Cutting the band along that one barrier edge opens the annulus into a disc — which is topologically
what the trace along that edge does.**

So the reduced form is not merely "the old formula". Where it drops interior barrier edges, it is **modelling the
cut**, and on the torus that is the right thing to model. Where it additionally drops vertices through the
`allOwned` test (16 of them on the mechanical fixture, against only 12 dropped edges), it over-removes and the
count goes wrong in the other direction.

---

## DA3 — the real defect: the certificate has never counted one object

`certificate.faceCount = fragments.size()`, and `fragments` is `{(face, owningOrbit)}` with one entry per element
of `region.sourceFaces` — so **F counts whole faces**, always, even where a trace splits one. Meanwhile `V_int`
excludes vertices whose corners in an incident face are owned by **another** orbit — an exclusion that only has
meaning if that face is **split**. And `E_int` excludes barrier edges, which is the cut.

> **The certificate mixes two notions of "the region": `F` is the whole-face rounding, while `V_int` and `E_int`
> are partial models of the traced, split region. It has always been a mixture, and neither DEFN-R6 nor any
> predecessor noticed.**

**Part X resolved that mixture toward whole faces.** That was the available choice given one fixture — `V_int`,
`E_int` and `F` are all whole-face-derived quantities in the trivial sense that they range over
`region.sourceFaces` — but it was the wrong half. The `allOwned` test and `fragmentCorners` exist precisely to
describe **split** faces; DEFN-R4 established `FragmentCornerIncidence` as the ownership map for exactly that. The
machinery for the split reading is already built and the certificate does not use it for `F`.

**A third complex has never been computed**: the traced region, with cut faces counted as fragments, corners
attributed by `fragmentCorners`, and cut edges counted on the side that owns them. That is the candidate neither
formula represents, and it is the one the rest of the plan is built around.

**`DEFN-R6.4` is withdrawn. `DEFN-R6.3` — the counted complex — is the live question**, exactly as Part X §9's own
falsifier stated it would be:

> *"If a region elsewhere newly fails Euler, DEFN-R6.4 is too strong for some region the reduced form happened to
> pass, and the counted complex — DEFN-R6.3 — becomes the live question."*

The falsifier fired as written. That is the one thing this turn got right in advance, and it does not offset the
cost.

---

## DA4 — the DEFN-R6.7 proof obligation was discharged over an empty set

Part X required CB43 to establish, **per region on every accepted fixture**, either `X = E_one + B_int` or an
unchanged verdict, and explicitly refused *"accepted fixtures have no slits"* as a discharge. That obligation was
the single safeguard against this regression.

**It produced zero rows, and the verifier reported success anyway.**

- CB43 emits `record=euler_certificate` from `emit_region_euler_certificate_diagnostics`, correctly placed **before**
  the χ test.
- But the call is guarded by `if (diagnostics != nullptr)`, and `diagnostics` is non-null only when
  `fragment_diagnostics_enabled()` — i.e. only when the environment variable
  `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1` is set (`GlobalTopologyPlan.cpp:86–89`, `:2460–2462`). The accepted
  identities do not run under it.
- `accepted-region-euler-certificates.tsv` therefore contains only its header, and the verifier's
  `accepted_euler_arithmetic_ok=true` is **vacuous**.

> **A proof obligation with no non-emptiness condition discharges itself over the empty set.** Part X named the
> per-region check, the four identities it had to satisfy, and the inadmissible excuse — and never said **how many
> rows must exist**. `LESSONS.md` 155.

This is the same shape as `GTEST_FAIL_IF_NO_TEST_SELECTED` (exit 0 with nothing run) and as CH8's conflict census
over an all-`Unavailable` map (`LESSONS.md` 122). It is the third instance in this checkpoint, and the first where
the vacuous check was one **this project wrote specifically to prevent the failure that then occurred**.

**It also blocks diagnosis now.** Ordinal 366's move to `RegionInteriorDisconnected` cannot be attributed to a
region, because the certificate rows that would name it are behind the same gate.

---

## DA5 — the fourteen RED identities, classified

| Ordinal(s) | Classification | Detail |
|---|---|---|
| **356, 357, 362** | **ACCEPTED-GREEN LOSS — the stable event.** Torus region certified as an annulus under DEFN-R6.4. | shared detail `d976514d…`, `chiFull=0` |
| **390, 393, 406, 407** | **Protected-green loss, same root cause.** All four fail the frozen `regionFrontierComponentCount > 0` assertion at `FieldAlignedCurveNetworkTests.cpp:4364`, actual **0** — the plan now fails at a stage that carries no frontier annotation. Recurrence of the **DEFN-R4** pattern: frontier evidence hanging off which failure code was raised. | shared detail `104512bc…` |
| **367** | Frontier, moved. Now reports the **torus** region (`chiFull=0`), not the TB37 mechanical row. | `d976514d…` |
| **366** | **Predicted advance, not a regression.** Moves off Euler to `RegionInteriorDisconnected` — the mechanical region now passes χ and certification reaches a stage never previously executed. Part X's falsifier called this "a new frontier, not a regression of this one". **Which region is disconnected cannot be named**, because of DA4. | — |
| 368, 369, 370, 374, 398 | Carried, **byte-identical to TB37**, prior owners unchanged. | — |

Preserved: ordinals 312, 404, 408, 409 PASS; ownership `300 / 0 / 0`; ordinal 398 still publishes
`sourceFaceCount=300; ownerMapCount=300; provesCellularity=true`; both retired codes silent.

---

## DA6 — accounting: one new stable event

**Accepted green was lost, so this is a stable event.** Accepted ordinals 356/357/362 were PASS at TB37 and are RED
at TB38.

- **Events 45 → 46.**
- **Category: `RP-01 / AUTHORITY_DOMAIN_CONFLATION`** — the certificate mixes the whole-face rounding with the
  traced region, and DEFN-R6 resolved that mixture toward one side without checking the terms on the other.
  Existing category; **categories remain 14**.
- **Recurrences 31 → 32.**

**Totals: 46 events / 14 categories / 32 recurrences.** Produced-witness debt remains **5**. Package count **103**
(build fact only). Accepted authority remains **TB37 at 365/365**; TB38 is not promoted. CP4c-3 remains **OPEN**.

The DEFN-R6.7 vacuity (DA4) is **not** counted as a second event: it caused no separate accepted-green loss, and
inflating one regression into two would corrupt the ledger. It is recorded as a finding and as `LESSONS.md` 155.

**Candidate dispositions.**

- `M3-CP4c3-TB38-EXEC-CAND-01` → **OWNED / STABLE**. Root cause is DEFN-R6.4, not CB43.
- `M3-CP4c3-TB38-EXEC-CAND-02` → **OWNED / NON-STABLE**. Emission gated behind
  `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`; obligation undischarged.
- `M3-CP4c3-TB37-REV-CAND-01` (whole-face rounding vs traced region) → **PROMOTED TO GATING**. It was recorded as
  non-blocking; TB38 proves it blocking.
- `M3-CP4c3-TB36-REV-CAND-01` → **REOPENED**. "The region is a disc" holds for the mechanical region under the
  whole-face reading only, and that reading is now refuted as a general criterion.

---

## DA7 — exact successor: `M3-CP4c-3-CB44`

**Code + Build**, runtime-free, GMP/GMPXX linked, `runtimeExecution=false`. **Restore first, measure second, decide
nothing.**

- **DA7.1 — restore the accepted prefix.** Revert `certificate.eulerCharacteristic` to the reduced form
  `V_int − E_int + F`. This is a **restoration to a known-wrong formula**, done because the accepted baseline is
  the stop condition and the correct complex is not established. It returns 356/357/362 and 390/393/406/407 to
  PASS and returns 366/367 to their TB37 surfaces. **Do not revert anything else.**
- **DA7.2 — keep every diagnostic CB43 added.** `totalVertexCount`, `totalEdgeCount`, the `euler_certificate`
  record and the extended digest all stay. They are the evidence the next definition needs; only the **criterion**
  reverts.
- **DA7.3 — ungate the certificate emission, and require rows.** The accepted-fixture proof must not depend on
  `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS`. Either emit the `euler_certificate` record unconditionally on the
  certification path, or have the harness set the variable for every identity — and **publish the row count**. Any
  verifier over this table must **fail on zero rows**.
- **DA7.4 — measure the third complex.** For every region, additionally publish the **traced/split** reading:
  the number of the region's faces that are trace-cut; the fragment count under the split reading; the count of
  corners attributed to this region by `fragmentCorners`; and the interior barrier edges separated into those the
  region owns one side of and both sides of. **Publish, do not certify.**
- **DA7.5 — publish `fullMinusReduced` on every region, not only failing ones**, so the sign of the discrepancy is
  observable across both fixtures at once. It is `+4` on the mechanical region and `−1` on the torus region; a
  third fixture may show a third sign.
- **DA7.6 — protected surface.** Ordinals **312/409** byte-identical; selector **409** byte-frozen; accepted
  **1–365** must return to **365/365**; ordinals **390/393/406/407** must return to PASS; no work on
  368/369/370/374/398; **no change to region construction**, ownership, or any retired guard.
- **DA7.7 — `M3-CP4c-3-TB39` re-executes**, and the successor definition turn `DEFN-R7` decides the counted
  complex **only with rows from both fixtures in hand**.

**Falsification, stated before the build.**

- **Accepted prefix must be 365/365 and 390/393/406/407 must be PASS.** Anything less means the revert is
  incomplete and the turn halts.
- **The euler_certificate table must contain at least one row per certified region on every accepted fixture.**
  Zero rows, or a verifier that passes on zero rows, is a **failed turn**, not a passed one.
- If 366/367 do **not** return to their TB37 surfaces, something other than the criterion changed and the revert is
  not clean.
- If the torus region's published split-reading fragment count equals its whole-face count, the two readings
  coincide there and DA3's hypothesis is wrong for it.
- If `fullMinusReduced` is zero on every accepted region, then the accepted corpus cannot discriminate the three
  complexes at all, and `DEFN-R7` needs a new fixture before it can decide anything.

**Prohibited:** choosing a counted complex in CB44; correcting region construction; changing ownership or
`fragmentCorners`; weakening `proves_disc_topology()`, `sourceFacesConnected`, `boundaryWalkCount` or the
`regionFrontierComponentCount` assertion at `:4364`; editing ordinals 312/409 or any accepted identity; any
selector byte change; any Directional runtime in CB44.

**Exact next turn: `M3-CP4c-3-CB44` — Code + Build, runtime-free, GMP/GMPXX linked, under DA7.1–DA7.7.**

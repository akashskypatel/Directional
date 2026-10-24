# RA-68 — `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` Review Decision

**Turn reviewed:** `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` (definition only)
**Verdict:** **ACCEPTED.** One understated-scope charge, minor. No open REVIEW_BLOCKER. No promotion,
no stable event, no regression recurrence, no gate credit. **Neither repair shape is admitted; the
turn reached the strongest outcome available to it by refusing to pick one.**
**Date:** 2026-10-15

Everything below was re-derived from repository bytes and immutable artifacts.

---

## RA-68.1 — The specification read the measured bytes, and that is verifiable by tree object

The spec reasons about source read at HEAD while citing a measurement taken at `5be5e123e`. That is
only sound if the bytes did not move. They did not: `src`, `include` and `tests` are **tree-identical
at `5be5e123e`, at the entry commit `825a04bc8` and at HEAD** —
`src=fd09300ba38b10dfea728c8c3f7c4ed6b732c89c`,
`include=790328c2bcffe29db5366ea1193cf0ab6d8cba58`,
`tests=cbef8d5ec448edb4c048b9058c7a0bd10a32b8af`. The spec's own phrasing ("GitHub commit
comparison") understates what is true; the tree objects settle it outright.

The R5 snapshot is also real. Artifact `12010485442` at `3d1b413a8` (run `38814059292`): **outer ZIP
SHA-256 recomputed on the downloaded bytes as
`020bc02980fb661d4b4bdc0f26de3b74c91887a6dad43a100ab3391bea4dc62e`, matching the provider digest;
`SHA256SUMS` carries 5,648 entries; `shasum -a 256 -c` over the extracted tree returns 5,648 OK, 0
BAD.** The RA-67.10 practice — snapshot the pre-image, verify the edit against it — was carried
forward without being told to. Recorded as credit.

## RA-68.2 — Mandate 1 discharged: the derivation is independent and it confirms

The spec re-derives RA-67.6 from the premises rather than adopting it, and states the confirmation
with the correct narrow scope: the **first rejection** for the 21 measured junction identities, not
an explanation of all 44 REDs and not a repair. Every cite checks out against the bytes:

- `tests/SurfaceCellsPhase10Tests.cpp:266-273` inserts the two hard edges `(1,4)` and `(4,7)`
  sharing vertex 4 — verified.
- The face table at `:223-263` gives edge `(1,4)` faces `{0,3}` and edge `(4,7)` faces `{4,7}` —
  verified.
- `SurfaceHardRailFieldTransition` at `include/directional/geometry/SurfaceCellTracing.h:1481-1489`
  is edge-keyed with exactly two face keys and one `QuarterTurn` — verified (the spec's `:1481`
  correctly includes the doc comment; my own earlier `:1482` omitted it).
- The producer at `src/geometry/SurfaceCellTracing.cpp:18939-18973` publishes one edge and that
  edge's two incident faces into `hardRailFieldTransitions` — verified.
- `find_carrier` at `:19097-19105` selects by `item.edge == edge`; `oriented_carrier` at
  `:19106-19114` matches the complete face pair in either order — verified.

The spec also states the distinction that matters: the first-reject mechanism is established, while
**neither the intended sector, nor a truncated route, nor a valid correction** is. **RA-64.6 remains
withdrawn** and the spec says so in its own text, unprompted.

## RA-68.3 — Mandate 2 discharged, and the producer test is applied with real teeth

The census at §2 names, for each required fact, the existing published contract, its producer and the
limit that bears on admissibility. The entries check out. The decisive one is new and it is better
than my own argument:

**`SurfaceHardRailRouteJunctionCertificate` exists — and is ordered too late to authorize
admission.** The type is real (`SurfaceCellTracing.h:1512-1516`: `SourceVertexId junction` and two
`sectorPaths`), and it is a member of `SurfaceHardRailRouteCertificate` (`:1518-1526`). But the
construction at `src/geometry/SurfaceCellTracing.cpp:19525-19530` opens with
`auto previous = firstEndpoint->terminalCarrier;` and the publication at `:19728-19731` dereferences
`*firstEndpoint, *secondEndpoint` — both reachable only past the rejection branch at
`:19352-19360`, where `if (!firstEndpoint || !secondEndpoint)` returns. **The nearest candidate
witness for gate C is produced only after the admission it would have to authorize.**

At RA-65.5 I suspended gate C on the ground that no producer publishes a vertex-star witness. The
spec finds the nearer and sharper statement: a producer of something very like it *does* exist, and
it is unusable because of its position in the order. That is a stronger objection than mine and it
survives the obvious rebuttal that someone will eventually make — "but the junction certificate
already exists." **Gate C stays SUSPENDED, now on ordering as well as nonexistence.**

## RA-68.4 — Mandate 3 discharged: the falsifiers are concrete and the populations are exact

The spec names the separating population by TSV index and the controls by TSV index. I re-derived
both from the immutable `endpoint-chart-harvest.tsv` and they are **exactly right**:

- junction (`carrier-orientation`): `12-25, 34, 35, 36, 39, 40, 42, 43` — **21**
- interior (`not-same-interior-carrier-point`): `1-11, 26-33, 37, 38, 41, 44` — **23**

The historical-ordinal list (`115-117, 122, 130, 132, 134, 137, 139-143, 150, 404, 406, 407` plus
four supplemental) is 17 + 4 = 21, consistent with the 17 historical and 4 supplemental junction rows
I measured at RA-67.

**The `routeLength=1` obstruction is real.** I verified it against the raw logs: `routeLength=1` in
every log, with no other value anywhere. A one-step route carries a single carrier, so a mechanical
split of that route at its endpoint cannot manufacture a second carrier. The naive split-only
variant of shape A is **falsified by measurement**, not by argument.

## RA-68.5 (CHARGE, minor — understated scope) — `routeLength=1` holds for all 44, not only the 21

The spec writes "In all 21 raw logs `routeLength=1`". It is true, and it is true of **all 44**,
including the 23 controls. Two consequences the spec does not draw:

1. **The obstruction is stronger than claimed.** Every measured identity, junction and interior
   alike, carries a one-step route. The naive split is impossible across the whole measured
   population, not only where the carrier mismatches.
2. **The 23 do not control for this property.** They remain valid negative controls for the
   attachment-membership partition — that is what they were nominated for — but a control that
   shares the property under test cannot discriminate on it. A later turn must not cite the 23 as
   evidence that `routeLength=1` is junction-specific, because it is not.

Charged as understatement, not error. Corrected here rather than returned.

## RA-68.6 (NEW) — A boundary hard rail publishes no carrier at all

The census does not surface this, and it bears directly on shape B. The producer at
`src/geometry/SurfaceCellTracing.cpp:18939-18941` reads

```
const auto incident = sourceEdges.find(edge);
if (authoritativeOptions.fieldTransportAtlas == nullptr ||
    incident->second[1] < 0) continue;
```

so **any hard edge with only one incident face is skipped entirely** — no
`SurfaceHardRailFieldTransition` is published for it. A hard rail running along the mesh boundary
therefore has no carrier record, and `find_carrier` returns `nullptr` for it rather than returning a
record that fails to match.

For shape B this is load-bearing: a vertex-star certificate at a junction on the mesh boundary would
have a spoke with **no carrier to attest**, so any vertex-aware admission must handle carrier
*absence* as a distinct case from carrier *mismatch*. The measured 21 are all interior junctions, so
nothing in the harvest exercises it. Recorded as a locus; **no repair authorized.**

## RA-68.7 (NEW) — The published face pair is canonically ordered, which closes an obvious objection

`src/geometry/SurfaceCellTracing.cpp:18968-18970` computes `const bool reverseCanonical = to < from;`
and pushes the smaller key first. So `record.firstFace` is always the lexicographically smaller of
the two face keys. Two things follow, both favourable to the derivation:

- `oriented_carrier`'s two-branch test is **complete** — it tries both orders, and the stored order
  is canonical, so no orientation case is unreachable. There is no hidden ordering bug behind the
  refusal.
- The measurement is consistent with the canonical form: `CarrierFirstFace=(0,1,4)` is indeed less
  than `CarrierSecondFace=(1,4,5)`. The record read in the harvest is the real published record.

This removes the cheapest available rebuttal to RA-67.6 — that the comparison merely got the
orientation wrong — and it removes it from the bytes rather than by assertion.

## RA-68.8 — Mandate 4 discharged, and the non-decisions are stated without hedging

§4 declines to select A or B, to define a type, to approve a route extension, to authorize splitting,
to modify any predicate, or to classify sectors from row numbers. It explicitly declines to
resurrect RA-64.6 or RA-61.9, to resume gate C, to treat the 21 as two mechanisms, to promote `RP-01`
to repaired, or to claim `RP-02` reached. **The turn was asked to apply a test that could make both
candidates inadmissible, and when the test did exactly that, it reported the result instead of
softening it.** That is the fourth mandate working as intended and the **fifth** consecutive turn
satisfying `RP-03`.

The spec also absorbed RA-67.9 — my charge that the previous turn harvested the interval fields and
left them unexamined — into its own §1: "All 44 have reciprocal exact interval ordinals, proving that
this condition does not distinguish the failures." Charge answered one rung after it was made, in
the turn's own analysis rather than in a reply.

## RA-68.9 — What the next measurement must settle, and why it is not a definition question

Both repair shapes are inadmissible for want of a producer, so the obvious next move is a
producer-definition turn. **It is the wrong next move, because one measurement can still change which
producer is needed, and it is cheap.**

Put RA-68.4 beside RA-65.10. The route has **one** step, and by RA-65's reading of
`assign_open_front_boundary_authority` (`:12481-12692`) the publisher cannot shorten a route — at a
topology change it either publishes a second step (`:12642`) or hard-rejects (`:12645`,
`:12669`). So a one-step route means the traced path crossed exactly one source-edge topology:
edge `(1,4)`. But the endpoints are not taken from the path. They are taken from the corner array —
`edge.from = cell.corners[side]`, `edge.to = cell.corners[(side+1)%4]` at `:13034-13035`,
`:14774-14775`, `:17345-17346` — and **nothing reconciles the corner array against the path's face
set** (RA-65.10, recorded and never since touched).

The measurement puts `to` in face 7, which is incident to edges `(4,7)`, `(7,8)` and `(4,8)` and
**not** to `(1,4)`. If the route's single step is `(1,4)`, then the endpoint the certificate is being
asked about lies off the path the route describes. That would make this a **corner/path
reconciliation defect at A4**, upstream of the consumer, and neither shape A nor shape B would be the
right family: no vertex-star certificate is needed to admit an endpoint the route should never have
been paired with.

**This is a prediction, and it is falsifiable at a named rung.** The prediction: the route's step
edge set will contain no edge incident to the `to` endpoint face. The falsifier: if the route's step
edge set *does* contain an edge of face 7, the reconciliation hypothesis is wrong, the corner array
and the path agree, and the producer-definition turn becomes the right next move after all. Either
outcome is decisive, and the observation costs a handful of rejection-only fields in a probe that
already exists.

**Nothing here revives RA-64.6.** That claim was that the publisher *truncated* a route; this says
the publisher may have published a correct route for its path and been handed an endpoint from
somewhere else. Different producer, different defect, and still unmeasured. It is recorded as a
prediction with its provenance stated (RA-61.5) and its observation rung named (RA-64.12), not as a
finding.

## RA-68.10 — Beacon, documents and scope

Documents only: `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` and every selector are
untouched. All five documents the turn edited are **pure insertions, zero deletions** — handoff +12,
`TODO.md` +8, `ORIENTATION.md` +6, root `CHANGELOG.md` +4, `.agents/Directional/CHANGELOG.md` +4.
Floors clear before this Review's prepends: tracker 13,620 / 657 / 13 occurrences; handoff 4,639 /
312; root changelog 1,874 / 239; orientation 3,416 / 111.

Beacon `Status: COMPLETE`, six fields, `Resumed at:` and `Ended at:` populated, `Successor: UNKNOWN`
**with reasoning carried in the owning document** — "no successor ID is manufactured" at spec line 60,
repeated in `TODO.md`. The RA-63.13 shape, **no defect**. `Successor:` was not self-named while the
turn was in progress, which is the RA-67.11 correction applied.

**The tracker was not updated, and that is correct** — a definition turn produces no regression
evidence. It is updated by this Review.

## RA-68.11 — Accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector
**30+12+449+6 = 497** — unchanged. No ledger credit, no promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no binary executed. `R4-VIN-01` stays armed:
`5be5e123e` is the semantic source; `11976790988` and `11967601999` are **baselines, never
comparands**; the 44 RED remain the baseline for `16c3134c0` alone, **candidate / non-stable**.

`RP-01` **measured, mechanistically derived, and now bounded on both repair families — code still
unauthorized**; `RP-02` **UNREACHED**; `RP-03` satisfied a **fifth** consecutive turn; `PROCESS-01`
discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED (RA-65.5), now on
ordering as well as nonexistence (RA-68.3).**

## RA-68.12 (LESSON) — An inadmissible answer is a result

The turn was asked to apply a test that both candidates could fail, and both failed it. The value of
the rung is precisely that it closed two doors without opening a third, and said so plainly instead
of promoting the less-bad option. A definition turn that returns "neither, and here is the witness
each one lacks" has advanced the work further than one that picks a winner it cannot justify.

## Disposition

`M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` — **ACCEPTED**. Successor:
**`M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE`**, a compile-only, rejection-only diagnostic turn.
The producer-definition turn the spec points to is **deferred behind it**, because RA-68.9's
observation can still change which producer is needed.

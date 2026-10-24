# M6-CP3-R4 — RA-46.5 `ambiguous-terminal-contact` feasibility: Review decision (RA-49)

**Turn:** `M6-CP3-R4-AMBIGUOUS-TERMINAL-CONTACT-ARCH-REV` (independent Review).
**Adjudicates:** `Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`.
**Verdict:** the retirement request is **REJECTED**. The branch is **REACHABLE**; the RA-46.5 obligation
**STANDS**, with the witness named exactly. One *different* RA-46.5 negative —
`nonmanifold-terminal-star-spoke` — **is** unrealizable and is retired in its place under RA-48's existing
guards. New finding **R4-CTC-01** (validate-after-use ordering).
**Method:** re-derived from repository bytes at `2756c2323`. No binary built, no test executed, no runtime credit.

---

## 1. The STOP's conditional claim is true; its premise does not hold on the live path

The request's deduction is: *"the `if (terminalVertex) return reject("ambiguous-terminal-contact")` branch is
unreachable **for a valid factory-admissible producer receipt**."* Read with that qualifier, it is correct. The
error is in the sentence that follows it: *"A malicious duplicate terminal pair is rejected **earlier** by the
checked factory."*

**The checked factory runs later, not earlier.**

- `endpoint_certificate` is a lambda defined at `src/geometry/SurfaceCellTracing.cpp:18999` and **invoked** at
  `:19167` and `:19170`, inside the per-rail loop of `build_surface_cell_network`.
- The contact it consumes is read **unvalidated** at `:18997`:
  `authoritativeOptions.hardRailTerminalContacts.find(*first.railId)`.
- `publish_phase_front_result` — the only route to `SurfacePhaseFrontProduct::make`, and hence to the
  distinctness check at `:8295-8299` — is called at **`:19446`**, after that loop closes, and is handed the
  *same* `authoritativeOptions.hardRailTerminalContacts`.

So on the live path the ordering is **consumer first, factory second**. `:19052` is the **first** rejecting
predicate for a duplicated endpoint pair, which is precisely what RA-46.5 requires. Nothing upstream enforces
factory-admissibility before `endpoint_certificate` reads the contact.

This is a **stage-locus error** — a guard cited as protecting a predicate that in fact executes before it. It
is the same class as the error corrected in RA-43.2 (an owner named in the wrong pipeline stage), and it is
why the request's conclusion inverts.

---

## 2. The impossibility the STOP found is real, sharper than stated, and about something else

Two **distinct** vertices genuinely cannot both qualify. The reason is narrower and stronger than the request's
argument, and worth recording because it determines what the witness must be.

Qualification at `:19049-19051` is a **conjunction**, and one conjunct settles it alone:

```cpp
for (const auto vertex : contact->second.endpoints) {
  if ((edge.first() != vertex && edge.second() != vertex) ||
      !exact_corner(fromPoint, vertex) ||
      !exact_corner(toPoint, vertex)) continue;
  if (terminalVertex) return reject("ambiguous-terminal-contact");
  terminalVertex = vertex;
}
```

For a **fixed** `fromPoint`, `exact_corner(fromPoint, ·)` (`:19034-19046`) is a **function**, not merely a
restrictive test. `corner` is assigned only where `faces(point.face, i) == vertex.index()`; the subsequent
bit-exact one-hot test then forces `i` to be the single position `c` at which `barycentric[c] == 1.0`.
Therefore the only vertex that can pass is `faces(fromPoint.face, c)` — exactly one. The conjunct admits at
most one vertex **regardless** of `toPoint`, of the carrier-membership conjunct, of `contact.component`, and of
the checked factory.

**Consequence:** the branch has exactly **one** reachable route — the same vertex qualifying **twice** — and
that requires `endpoints` to hold a duplicate. The request located a true impossibility (two distinct vertices)
and then attributed its guard to the factory, when the impossibility needs no guard at all and the reachable
route has one that fires too late.

---

## 3. The witness, named exactly

`endpoints` is `std::array<authority::SourceVertexId, 2>`
(`include/directional/geometry/SurfaceCellTracing.h:1532`). A duplicate is **representable by type** — the
array has no distinctness invariant, and the only distinctness check anywhere is the factory's at `:8296`,
which runs at `:19446`.

A source-valid first-rejection witness is therefore:

1. `authoritativeOptions.hardRailTerminalContacts[railId] = {component, {v, v}}` — the same typed
   `SourceVertexId` in both slots.
2. `v` is an endpoint of the carrier `edge` (satisfies the first conjunct).
3. `fromPoint` and `toPoint` are each bit-exact one-hot at a corner holding `v` (satisfies both
   `exact_corner` conjuncts).

Iteration 1 passes the conjunction and sets `terminalVertex = v`. Iteration 2 passes the **identical**
conjunction, finds `terminalVertex` set, and returns `reject("ambiguous-terminal-contact")` at `:19052`.

Nothing is fabricated: the vertex genuinely exists, the barycentrics are genuinely one-hot, the carrier
membership genuinely holds. No tolerance is relaxed, no guard weakened, no approximation introduced, and no
non-source object is constructed. The request's own refutation criterion asked for "two unequal typed terminal
IDs"; that criterion was too narrow — it excluded by assumption the only route the code admits.

---

## 4. R4-CTC-01 — validate-after-use, and why the obligation cannot be retired

`build_surface_cell_network` **uses** caller-supplied `hardRailTerminalContacts` for routing and certificate
decisions from `:18997` onward, and only asks the checked factory to validate them at `:19446`. The duplicate-
endpoint condition is consequently checked **twice, with different strictness and different reporting**:

| Site | Order | Form |
|---|---|---|
| `:19052` consumer | **first** | string predicate `ambiguous-terminal-contact` |
| `:8295-8299` factory | second | typed `InvalidSourceAuthority` |

The upstream check is the one that actually fires, and it is the weaker of the two in reporting. So the
consumer's guards here — `ambiguous-terminal-contact`, `no-exact-terminal-corner`, and the spoke guards — are
**load-bearing**, not redundant defence in depth. Retiring the `ambiguous-terminal-contact` negative would
remove coverage from the only check that runs *before* the data is consumed, leaving the condition covered
solely by a check that executes after the routing decisions it was supposed to authorise.

This also means the request's proposed substitute — "require a reachable factory-first duplicate-contact
negative" — is not a substitute at all: a factory-first negative cannot exist for this condition on this path,
because the consumer rejects first. Any fixture written to that description would either fail at `:19052` (and
so *be* the RA-46.5 negative) or reach the factory only by bypassing `build_surface_cell_network` entirely,
which tests a path the pipeline does not take.

---

## 5. What *is* unrealizable: `nonmanifold-terminal-star-spoke`

The request's item 3 asked that the other RA-46.5 negatives be examined for feasibility. One of them is
unrealizable, and it is not the one asked about.

`:19066-19068` rejects `nonmanifold-terminal-star-spoke` when `sourceEdgeFaceCounts` shows an incidence `> 2`,
which requires a nonmanifold `faces`. But reaching that loop requires a non-null atlas (`:19056-19057`), and
the network-level gate at `:18749-18757` requires
`fieldTransportAtlas->matches_source_faces(faces, *network.sourceTopologyRegions, vertexCount)` whenever the
atlas is non-null. `matches_source_faces` ties the atlas's stored `rowTopology_` to the exact face triples of
`faces` (`src/authority/FieldTransportAtlas.cpp:3090-3109`), so the atlas must have been built on **that**
nonmanifold mesh — which throws, by the RA-48.0 chain (G1-G4: `set_mesh` runs `compute_edge_quantities`, which
throws when `dcel.check_consistency` fails, and DCEL check 5 rejects the repeated directed halfedge that three
triangles on one undirected edge must produce by pigeonhole).

So this consumer-side spoke guard inherits RA-48's unreachability, under RA-48's **already frozen** guards and
no new ones. It is retired on that basis. Note the inversion: the request sought to retire the reachable
predicate while leaving the unreachable one in force.

**Status of the remaining four.** `no-exact-terminal-corner` (`:19055`) is plainly reachable — any contact
whose endpoints are not on the carrier, or whose trace points are not bit-exact one-hot, falls through the loop.
`missing-terminal-A3-path` is reachable and keeps its obligation by RA-46.4, which retained the `pathCount == 0`
branch as reachable from a foreign component. `overlapping-terminal-sectors` and
`missing-or-nonreciprocal-terminal-A3` were **not examined** by this review and keep their obligations
unadjudicated; they are not to be reported as either confirmed or retired.

---

## 6. RA-49 — FROZEN

**RA-49.1.** The retirement request for `ambiguous-terminal-contact` is **REJECTED**. The branch at
`src/geometry/SurfaceCellTracing.cpp:19052` is **reachable** on the live path, and RA-46.5's requirement for a
negative at that actual first rejecting predicate **stands unamended**. RA-46.5 is not modified by this
decision.

**RA-49.2.** The required fixture is the §3 witness: a duplicated typed endpoint pair `{v, v}` in
`hardRailTerminalContacts`, `v` on the carrier edge, both trace points bit-exact one-hot at `v`. It must be
verified to reject at `:19052` and **not** at `:19055`, `:8296`, or any earlier predicate.

**RA-49.3.** The two-distinct-vertices route is **not** available and must not be attempted:
`exact_corner(fromPoint, ·)` is functional, admitting only `faces(fromPoint.face, c)` for the unique one-hot
position `c`. A fixture that tries to make two distinct vertices qualify is not a defect in the code and will
not produce this predicate.

**RA-49.4.** Prohibited routes to the witness: relaxing the one-hot comparison at `:19043` (RA-46.7 already
forbids adding a tolerance to the equivalent factory-side predicate, and the same prohibition applies here);
removing or weakening the factory distinctness check at `:8295-8299`; removing the carrier-membership conjunct
at `:19049`; or constructing the contact outside `build_surface_cell_network`. The witness requires none of
these.

**RA-49.5 — R4-CTC-01 is a defect.** `build_surface_cell_network` consumes caller-supplied
`hardRailTerminalContacts` at `:18997` and validates them only at `:19446`. The consumer's guards are therefore
load-bearing and must be **kept**. The architectural repair — validating the contacts against the factory's
own admissibility rules **before** first use, or routing the consumer through the factory-validated product —
is **not** authorized in a Code + Build turn and is referred to a later Definition turn. Until then the
duplicate condition keeps **both** checks, and neither may be removed as redundant.

**RA-49.6.** `nonmanifold-terminal-star-spoke` (`:19066-19068`) is **RETIRED** as unrealizable, on RA-48's
guards G1-G4 and the network atlas gate at `:18749-18757`, with the guard **kept fail-closed**. No fixture is
to be built for it, and none may be synthesized by relaxing manifold rules or by passing a null atlas (which
rejects earlier at `:19056-19057` with `missing-source-A3`, a different predicate). If any of G1-G4 or the
network gate weakens, this retirement lapses with RA-48.1's.

**RA-49.7.** `no-exact-terminal-corner` and `missing-terminal-A3-path` keep their RA-46.5 obligations and are
confirmed reachable. `overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3` keep their
obligations **unadjudicated** — this review did not examine them, and their feasibility may not be asserted in
either direction on the strength of this decision.

**RA-49.8 — the general rule, third application.** A predicate's obligation is settled by what it can
separate **on the path it actually sits on**, not by what a downstream guard would have prevented. RA-46 asked
this of a graph-theoretic condition, RA-48 of a source-construction condition, and RA-49 of an **ordering**
condition — and here the answer inverted the request, because the guard invoked to prove unreachability runs
after the predicate it was said to protect. A feasibility argument must therefore establish **execution order**,
not merely the existence of a stricter check elsewhere.

**RA-49.9 — no credit.** No binary built, no test executed. R4-CTC-01 is a source-level review finding, **not**
a counted stable regression: ledger stays **66 events / 17 categories / 49 recurrences**, debt **1**. CP2
**491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses. RA-48, RA-47, RA-46, RA-45,
RA-44 (less .2), RA-43 (less .5 and less the superseded `sourceEdges` row), RA-42 as corrected, RA-41 frozen
scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand unchanged. RA-47 remains **unimplemented**.

---

## 7. Beacon

`STATUS` read `BLOCKED` with `Successor: M6-CP3-CB1-ENTRY-R4`. The review it waited on is complete; there is no
open `REVIEW_BLOCKER`. Per RA-48.8, a `BLOCKED` beacon requires a committed record naming the finding — this
one had that record, so the block was properly raised even though its conclusion does not survive review.
Raising it was correct; the deduction was not.

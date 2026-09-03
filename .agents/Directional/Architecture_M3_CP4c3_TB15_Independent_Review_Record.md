# M3-CP4c-3-TB15 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB15-REV`
**Date:** 2026-09-03 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB15_Independent_Review_Plan.md`, measures **BO0–BO8**.
**Verdict:** TB15 is a **valid semantic red** and CB17's diagnostics resolve it. The incidence is **valid**; the
defect is that the edge-locus fallback binds its rank to **`trace.sourceVertex`** — the trace's *origin*
singularity — instead of the segment's own far-end vertex in this face. A **second, latent** defect is proved by
derivation in the same helper. One bounded product successor is frozen: **`M3-CP4c-3-CB18`** under **BP0–BP9**.

---

## 1. Executive adjudication

TB15 keeps ordinal 366 at `EdgeTraceSecondaryRankInvalid`, edge `25-31`, face `(25,30,31)`, attempt 0 / zero cut
edges — now with the typed branch **`SourceVertexFallbackUnbound`** and the full incidence: source vertex **35**,
arc **19**, trace **5**, **Reverse**, segments `[0,5)`, incoming carrier **none**, outgoing **`25-31`**, contact
index **2**, other carrier **none**, face corners **{25,30,31}**, census **3 rays, untruncated**.

That confirms the conditional this review recorded one turn early, and adds the mechanism.

1. **The ray reaches the fallback because its segment entered the face through a vertex.**
   `proposal.nextIncomingCarrier` is assigned at exactly **one** place — `SurfaceCellTracing.cpp:3122`, on the
   **edge-exit** continuation. The `VertexHit` continuation block sets `nextFace`, `nextBranch`, `nextEntryPoint`
   and `endArrival` and **never sets it**, so it stays `std::nullopt`. Segment 4 of trace 5 is *not* the trace's
   first segment (the arc is `[0,5)`, so segment 0 is), which leaves exactly one reading: **it was entered by an
   Amendment-3 vertex transit.**

2. **The fallback then asks the wrong question.** With `other` unbound it searches the face's corners for
   `trace.sourceVertex` — the singularity the trace *originated* from. That is vertex **35**, one of the four
   port-emitting corners, in a different part of the part; row 41's corners are `{25,30,31}`. No match, so
   `SourceVertexFallbackUnbound`.

3. **The incidence is valid and the correct datum is available.** Every other ray at this locus is ranked by its
   **far end within the face** — the end opposite the contact edge. For this ray that far end is the corner it
   entered through, recoverable exactly from the segment's own entry point via
   `FieldBoundaryPoint::source_support()` — the same primitive CB16 already uses. `trace.sourceVertex` is merely
   the special case where the trace's *first* segment starts at a singularity in this face; there the two
   coincide, which is why the rule has worked until now.

4. **A second defect is proved by derivation, not by this run.** The carrier branch returns
   `2·((otherIndex + 3 − contactIndex) mod 3)` — measured **relative** to the contact edge. The fallback returns
   `1 + 2·corner` — **absolute** in the face's corner numbering. Walking the face boundary shows the correct value
   is `1 + 2·((corner + 2 − contactIndex) mod 3)`. The two agree **only when `contactIndex == 2`** — which is
   exactly this failure's value, so the run cannot see it.

This is the third appearance of one defect class: an identifier used outside the scope that makes it correct
(`port->ordinal` at TB12-REV, the missing vertex-exit case at TB13-REV, `trace.sourceVertex` here).

---

## 2. BO0 — immutable evidence authority

Verified this turn with `.agents/Directional/tools/review_check.py` and `selector_probe.py`:

| Datum | Declared | Verified |
|---|---|---|
| semantic/package source | `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4` | exists, `M3-CP4c-3-CB17: declare edge-rank diagnostic type before use`, ancestor of HEAD |
| code drift source→HEAD | — | **empty** over `src include tests benchmarks CMakeLists.txt cmake` |
| selector 381 | `af667aae…cdd38d90` | LF-blob SHA-256 = `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90` |
| selector 381 cardinality | 381 identities | 381 |
| selector 380 frozen prefix | `1a95d328…d852a0e4e` | `head -380` reproduces it |
| accepted 365 prefix | `6b5b6555…cfc14b8a1` | `head -365` reproduces it |

Accepted as reported: 381 fresh-process selections, **372 PASS / 9 RED**, ordinals 1–365 at 365/365, first red 366,
selector-381 typed-production witness PASS, selector 380 RED, the non-gating mechanical diagnostic RED with the same
upstream reason/trace/edge, and the byte/mode-identical 58-file pre/post census
`3235eb99…a8af6295`.

### 2.1 The package metadata mismatch is inert, and this is provable

Package 85's contract names a diagnostic `GlobalTopologyPlan.EdgeTraceSecondaryRankUnavailableIsTypedAndObservable`;
the frozen TB15 plan named and executed `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`. Three
checks settle it without touching the package:

- **The contract-named identity does not exist.** A search of `tests/` finds **zero** occurrences of
  `EdgeTraceSecondaryRankUnavailableIsTypedAndObservable`. It names no test.
- **The executed identity does exist**, at `tests/FieldAlignedCurveNetworkTests.cpp:8209`.
- **Neither appears in selector 381** — confirmed by searching the verified selector file.

Gate selection reads the selector, whose bytes hash to the declared value; the non-gating diagnostic was chosen by
the frozen plan, which named the one that exists. A contract string that matches no test *and* is absent from the
selector cannot select, deselect, or reorder anything. It is **package-authoring metadata only**:
`M3-CP4c3-TB15-PKG-01` is a non-stable authoring candidate, and **no semantic rerun or package-85 repair is
authorized or needed**.

---

## 3. BO1 — the exact `SourceVertexFallbackUnbound` control path

`edge_locus_secondary_rank` reaches the fallback only after every earlier gate passes:

```cpp
faceKey  = trace_ray_face(arc, Reverse, trace)     → (25,30,31)          [caller also required it in sideRank]
faceIt   = topology.faces.find(faceKey)            → found
contactIndex = local_edge_index(face, 25-31)       → 2
segment  = trace.segments[arc.onePastLastSegment-1]→ segments[4]
// Reverse: bind `other` only if the segment leaves through the locus
else if (segment.outgoingCarrier == locus) other = segment.incomingCarrier;   // 25-31 == locus ✓
// → other = segments[4].incomingCarrier = std::nullopt
if (other.has_value()) { ... }                     // skipped
for (corner : 0..2) if (face.vertices[corner] == trace.sourceVertex) return 1 + 2*corner;
return fail(SourceVertexFallbackUnbound);          // 35 ∉ {25,30,31}
```

Every retained value is internally consistent, and one of them independently corroborates the evidence:
`face.edges[i] = (vertices[i], vertices[i+1])` — the convention `face_orients_edge_forward` uses — gives
`edges[2] = (31,25) = 25-31`, reproducing the retained **contactIndex 2** exactly.

CB17's typed result flows through a single emitter (`EdgeTraceSecondaryRankInvalid`) and one rendering path; the
subreason is set only at the `return fail(...)` sites inside the helper. **No translation layer can fabricate it.**

---

## 4. BO2 — the failing incidence, reconstructed

### 4.1 Why `incomingCarrier` is absent

`nextIncomingCarrier` is declared `std::optional<...>` (`SurfaceCellTracing.cpp:2851`) and assigned at exactly one
site — `:3122`, `proposal.nextIncomingCarrier = decision.outgoingCarrier;` — on the **edge-exit** continuation,
after the `VertexHit` and barrier branches have returned. The `VertexHit` branch returns having set only
`nextFace`, `nextBranch`, `nextEntryPoint` and `endArrival`.

> **A segment entered by a vertex transit carries `incomingCarrier == std::nullopt`.**

The arc is `[0,5)`, so segment 4 is the arc's last segment and *not* the trace's first. The only other producer of
an absent incoming carrier — a port origin — applies to segment 0. Therefore **segment 4 entered face `(25,30,31)`
through a vertex**, and the ray's far end inside that face is that corner.

### 4.2 The two namespaces are not interchangeable

| Datum | What it denotes | Value here |
|---|---|---|
| the segment's entry support | the corner **this ray actually enters through**, in **this** face | a corner of `{25,30,31}` |
| `trace.sourceVertex` | the singularity the **whole trace** originated from, anywhere on the mesh | **35** |

Vertex 35 is one of the four port-emitting index-`¼` corners. It is a correct fact about trace 5 and an irrelevant
one for ranking a ray inside row 41. The fallback's own comment states its intended case — *"A first/last segment
can connect the contact carrier directly to its singularity source vertex"* — which is the situation where the two
coincide. This ray is not that situation.

The 3-ray untruncated census is consistent: the failing trace ray carries `primary 3` with secondary unavailable,
so it is the only ray at this locus that reaches the fallback.

---

## 5. BO3 — semantic validity and the canonical binding datum

**The incidence is valid and a secondary rank must exist.** Nothing in the rotation contract forbids a trace from
entering a face through a vertex and leaving through an edge; that is Amendment 3's ordinary continuation, and the
rotation system must be able to order such a ray. Rejecting it upstream would reject valid networks, so this is not
the invalid-provenance case BO3's second horn describes.

**Canonical datum.** Every rank at an edge locus measures the ray's **far end inside the face — the end opposite
the contact edge**:

- **Reverse** (the arc *ends* at this locus): the far end is the segment's **entry** side.
- **Forward** (the arc *starts* here): the far end is the segment's **exit** side.

When that far end is an edge, it is the other carrier (already handled). When it is a **vertex**, it must be taken
from **the segment's own boundary point on that side**, via `FieldBoundaryPoint::source_support()` — parameter 0 →
`edge.first()`, parameter 1 → `edge.second()` — the identical primitive CB16 used for the vertex-exit case in
`vertex_trace_ray_second_point`.

This rule is:

- **orientation-correct** — it reads the entry side for Reverse and the exit side for Forward, matching how
  `trace_ray_face` already selects the segment;
- **enumeration-invariant** — it names a topological support, never a vertex id or a fixture ordering;
- **strictly more general** — for a trace's first segment beginning at a singularity in this face, the entry
  support *is* `trace.sourceVertex`, so the present rule is recovered as a special case rather than discarded.

---

## 6. BO4 — auditing the whole fallback contract

### 6.1 A latent ordering defect, proved by derivation

The carrier branch returns `2·((otherIndex + 3 − contactIndex) mod 3)` — **relative** to the contact edge. The
fallback returns `1 + 2·corner` — **absolute**. Walk the face boundary away from contact edge `c`, whose endpoints
are corners `c` and `c+1`:

| position | target | rank the carrier branch implies |
|---|---|---|
| 1 | corner `c+1` | — |
| 2 | edge `c+1` | `2·((c+1+3−c) mod 3) = 2` |
| 3 | corner `c+2` | — |
| 4 | edge `c+2` | `2·((c+2+3−c) mod 3) = 4` |
| 5 | corner `c` | — |

So corners must take **1, 3, 5** in that order, i.e.

> `rank = 1 + 2·((corner + 2 − contactIndex) mod 3)`

The current `1 + 2·corner` equals that **only when `contactIndex == 2`**. This failure has `contactIndex = 2`, so
the run cannot expose it — but for `contactIndex ∈ {0,1}` the fallback ranks interleave in the wrong order relative
to the carrier ranks. It must be corrected in the same turn, because a correction that fixes only the datum would
leave a wrong-order rule newly reachable on many more inputs.

### 6.2 Composition and fail-closed behaviour

- Carrier ranks occupy `{2,4}` (delta 0 is rejected as `CoincidentLocalEdgeIndex`); corner ranks occupy `{1,3,5}`.
  The two families interleave without collision, and both stay below any `primary` distinction, so composition with
  `key.primary = sideRank` (or `2·sideRank + 1` when mandatory/cut edge rays are present) is unchanged.
- Both incident face sides keep their own `sideRank`, so the two sides never share a `(primary, secondary)` pair.
- Canonical edge reversal does not enter the computation: `contactIndex` and the corner index are both face-local.
- **Fail closed is preserved.** If the far-end support is neither a carrier nor a corner of this face, the helper
  must still return a typed failure — the successor keeps `SourceVertexFallbackUnbound` for that genuinely
  unbindable case rather than inventing a rank.

---

## 7. BO5 — generalization and accepted-boundary safety

**This correction is *not* purely additive, and that must be stated plainly rather than assumed.** Two classes
change:

1. **Datum.** A ray currently *succeeding* through the fallback has `trace.sourceVertex` among the face's corners.
   If its segment's far-end support is a **different** corner — a trace that transits one corner of a face while
   its origin singularity happens to be another corner of the same face — the rank changes.
2. **Formula.** Every currently-succeeding fallback ray with `contactIndex ≠ 2` gets a different rank.

Unlike the last three successors, the structural "it only runs where the helper errors today" argument does **not**
apply. And the exposure is real: the edge locus was never reached on the *mechanical* witness before TB14, but the
torus reaches A2b end to end, so accepted identities plausibly exercise this helper already.

Therefore BP5 requires the safety to be **demonstrated, not argued**: witnesses must pin the rank returned for
every currently-succeeding fallback shape on the accepted witnesses, before and after, and the accepted 365 must
re-pass in the next TB as the discriminator. If any accepted rank changes, the successor stops and the review
reopens — a changed rotation on an accepted witness is a semantic event, not a detail.

**Selector 381's PASS is diagnostic-contract evidence only.** It proves the typed reason and retained incidence
survive the production renderer. It is not evidence for any product correction, and BP0 forbids citing it as such.

---

## 8. BO6 / BO7 — obligations and carried surfaces

**The v47 obligation stays open.** Selector 380 remains **RED** at the upstream edge-locus stop, so the full
five-ray v47 rotation with distinct secondary ranks for the former pair (arc 20 / trace 6 / Forward and
arc 23 / trace 9 / Reverse) is still unpublished. `M3-CP4c3-TB11-CAND-01` remains **OPEN** and
`M3-CP4c3-TB12-REV-CAND-01` remains **PARTIALLY DISCRIMINATED**. Neither selector 381's PASS nor the absence of
`RotationRayOrderKeyCollision` closes them. **There is still no vertex-30 discriminator**, and
`M3-CP4c3-TB6-CAND-01` stays ACTIVE.

**Candidate dispositions.**

- `M3-CP4c3-TB14-CAND-01` — **CLOSED / RUNTIME DISCRIMINATED.** Its subject was the collapsed five-way `nullopt`;
  CB17 typed it and TB15 names `SourceVertexFallbackUnbound` with the full incidence.
- **New `M3-CP4c3-TB15-CAND-01`** — **ACTIVE / GATING / PRODUCT**: the edge-locus fallback binds its rank to the
  trace's origin singularity instead of the segment's far-end support, and ranks corners absolutely rather than
  relative to the contact edge. Owner: **BP1–BP5** of `M3-CP4c-3-CB18`.
- **`M3-CP4c3-TB15-PKG-01`** — **RESOLVED / AUTHORING METADATA / NON-STABLE** (§2.1). Not a product owner.

**Carried surfaces keep their owners**, and the new branch owner absorbs none of them: 368 prescribed-sphere
`TraceEventPositionInvalid / NoCarrierMatch` (`M3-CP4c2-TB-X2-CAND-04`); 369 saturation
(`M3-CP4c2-TB-X2-R10-CAND-01`); 370 empty-network typed code/locus (`M3-CP4c2-TB-X2-R8-CAND-02`, **no correction
authorized**); 371/372 shared mechanical-fixture coupling only (`M3-CP4c3-TB10-REV-CAND-01`, **DEFERRED**); 374
folded cone (`M3-CP4c3-TB7-CAND-02`); vertex 30 and the finalize/contact fall-through separate and ACTIVE.

**Accounting.** TB15 loses no accepted-green behaviour and this review executes nothing. **+0 stable events / +0
recurrences**; totals remain **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic
package count **82**.

---

## 9. BO8 — the single frozen successor: `M3-CP4c-3-CB18`

**Type:** Code + Build. **Product correction**, bounded to `edge_locus_secondary_rank`'s fallback. **Owner:**
`src/geometry/EmbeddedGraphTopology.cpp::edge_locus_secondary_rank`.

- **BP0** — accepted 365 untouched; **selector 381 byte-frozen** at `af667aae…cdd38d90`, republished unchanged;
  **eight standard compile targets with mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed; selector
  381's PASS may **not** be cited as evidence for this correction.
- **BP1** — bind the fallback to **the segment's far-end vertex support in this face**, not `trace.sourceVertex`:
  Reverse takes the **entry** side, Forward the **exit** side, resolved through
  `FieldBoundaryPoint::source_support()`. The present rule must remain recovered as the special case where the
  trace's first segment begins at a singularity in this face.
- **BP2** — make the corner rank **relative to the contact edge**:
  `1 + 2·((corner + 2 − contactIndex) mod 3)`, per §6.1. State in the report that this changes nothing when
  `contactIndex == 2` and everything otherwise.
- **BP3** — keep the helper **fail-closed**: a far end that is neither a carrier nor a corner of this face still
  returns a typed failure. Do not invent a rank, and do not suppress or rename `SourceVertexFallbackUnbound`.
- **BP4** — leave untouched: the carrier branch, `local_edge_index`, `face_orients_edge_forward`,
  `trace_ray_face`, `sideRank`, `key.primary`, collision detection, `build_node_loci`, contact-node construction,
  and the entire vertex-locus path CB15/CB16 settled. Do not revert CB12, CB14, CB15, CB16 or CB17.
- **BP5** — **demonstrate accepted-boundary safety, do not argue it** (§7). Add witnesses pinning the rank for
  every currently-succeeding fallback shape on the accepted witnesses — first segment at a singularity in the face,
  and `contactIndex ∈ {0,1,2}` — asserting the value before and after. If any accepted rank changes, stop and
  report rather than proceeding.
- **BP6** — witnesses. *Positive:* a Reverse ray whose segment entered through a vertex ranks from that corner, and
  its rotation publishes. *Negative:* a far end bindable to neither a carrier nor a corner still fails typed.
  *Ordering:* a fallback ray and a carrier ray in one face interleave correctly for `contactIndex ∈ {0,1,2}`.
  *Regression:* an ordinary two-carrier crossing returns a byte-identical rank.
- **BP7** — append **selector 382** only on demonstrated falsification; no reordering of any existing ordinal. No
  fixture special case, no vertex-id rule, no identity or enumeration-order tie-break, no tolerance or float, no
  accepted-boundary weakening, no finalize/contact repair, no 371/372 decoupling, no sphere, saturation,
  ordinal-370 or folded-cone correction, no package-85 repair.
- **BP8** — audit by assumption; state for each of BP1–BP5 the assumption and the evidence falsifying the nearest
  alternative, and report the complete class of inputs whose rank changes.
- **BP9** — publish six `M3-CP4c-3-TB16` discriminators in advance:
  1. ordinals **1–365 remain 365/365** — this is the load-bearing check, not a formality (§7);
  2. ordinal 366 no longer reports `EdgeTraceSecondaryRankInvalid` at edge `25-31`;
  3. if a rotation red remains, it carries a **different** typed branch, locus or incidence;
  4. **the v47 conjunction is re-proved** — selector 380 passes with the full five-ray v47 rotation and distinct
     former-pair secondary ranks;
  5. `M3-CP4c3-TB11-CAND-01`, `M3-CP4c3-TB12-REV-CAND-01` and `M3-CP4c3-TB15-CAND-01` close only on 1, 2 and 4
     together;
  6. certification may for the first time proceed past rotation construction into the face walk, where
     `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` can legitimately appear.

**No vertex-30 discriminator is published.**

---

## 10. Assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review describes package 85. | `review_check.py authority 1e671ef7` — ancestor of HEAD, **empty** code drift. |
| §2.1 | The metadata mismatch is inert. | The contract-named identity occurs **zero** times in `tests/`; the executed one exists at `:8209`; **neither** is in the verified selector 381. Selection cannot depend on a string that names no test and is not in the selector. |
| §4.1 | The segment entered through a vertex. | `nextIncomingCarrier` is assigned only at `:3122` on the edge-exit path; the `VertexHit` branch returns without setting it; the arc is `[0,5)` so segment 4 is not the trace's first. |
| §4.2 | The two vertices are different namespaces. | v35 is a port-emitting singularity elsewhere on the part; row 41's corners are `{25,30,31}`. The retained `contactIndex = 2` independently reproduces from `edges[i] = (v[i], v[i+1])`. |
| §5 | The incidence is valid. | Vertex-transit entry is Amendment 3's ordinary continuation; rejecting it upstream would reject valid networks. |
| §5 | The datum generalizes rather than replaces. | For a first segment starting at a singularity in this face, the entry support **is** `trace.sourceVertex`. |
| **§6.1** | **The absolute corner rank is wrong for `contactIndex ≠ 2`.** | Boundary walk from contact edge `c` orders targets `c+1, e(c+1), c+2, e(c+2), c`; the carrier branch already pins `e(c+1)→2`, `e(c+2)→4`; corners must therefore be `1+2·((corner+2−c) mod 3)`, which equals `1+2·corner` only at `c = 2`. |
| **§7** | **The correction is not accepted-safe by construction.** | It changes rays that currently *succeed*, in two named classes; the torus reaches A2b, so accepted identities plausibly exercise the helper. Hence BP5 demands demonstration. |
| BP9.1 | 1–365 re-passing is the real gate. | It is the only check that covers the behavioural-change classes of §7. |

---

## 11. Lessons

- **93 (new).** *An absent optional means whatever its producer's last branch chose to leave unset.*
  `incomingCarrier` is `nullopt` for two entirely different reasons — a port origin and a vertex transit — because
  the `VertexHit` continuation simply returns without assigning it. Consumers then read one absence as the other.
  When an optional is set on some producer paths and skipped on others, the skip is a value with meaning, and it
  belongs in the type: a named alternative, not a hole.
- **94 (new).** *A rank derived relative to a locus must be derived relative to it in every branch.* One branch of
  this helper measures from `contactIndex` and the other from the face's absolute corner numbering. They agree on
  exactly one of three possible contact indices — so the disagreement is invisible two thirds of the time and
  entirely invisible on the witness that exposed the neighbouring bug. When two branches feed one ordering, check
  that they share an origin, not merely a range.
- **85 / 87 confirmed, third instance.** `port->ordinal` (TB12-REV), the missing vertex-exit case (TB13-REV), and
  now `trace.sourceVertex` are the same defect: a value correct in the scope that produced it, used in a scope that
  does not make it unique. The class is worth a standing check at every locus-relative computation, not a third
  individual fix.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB18`** under **BP0–BP9**.

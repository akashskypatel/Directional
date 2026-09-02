# M3-CP4c-3-TB14 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB14-REV`
**Date:** 2026-09-02 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB14_Independent_Review_Plan.md`, measures **BM0–BM8**.
**Verdict:** TB14 is a **valid semantic red**. CB16's correction worked and pushed the rotation past **every vertex
locus for the first time**, reaching the **first edge (contact) locus in the project's history on this witness**.
The failing branch inside `edge_locus_secondary_rank` is **not determined by the retained evidence**, and the
missing datum is named precisely. Per BM8 the successor is **diagnostic-only**: **`M3-CP4c-3-CB17`** under
**BN0–BN9**.

---

## 1. Executive adjudication

Ordinal 366 is now `RotationSystemInconsistent → EdgeTraceSecondaryRankInvalid`, source edge `25-31`, source face
`(25,30,31)`, attempt 0 / zero cut edges / 450 candidates.

Four results decide this turn.

1. **This is newly reachable code, not a regression.** Vertex nodes are created first, from the sorted
   `nodeVertices` set; **contact nodes are appended afterwards** (`field_aligned_append_contact_node` takes
   `nodeIndex = candidate.nodes.size()`). Since `build_rotation_system` iterates `incidences` in node-id order,
   **every vertex locus is processed before any edge locus**. TB13 failed at a *vertex* locus (v10), so no edge
   locus had ever been reached. CB16 cleared the vertex loci, and the edge-locus branch is being exercised on the
   mechanical witness **for the first time**.

2. **The locus is a contact node, and zero cut edges is consistent.** An edge locus is assigned either from
   `cutNodes.syntheticCrossings` or — in the events loop of `build_node_loci` — to **any node that has no vertex
   locus and carries an event with a `sourceEdge`**. Nodes acquire a *vertex* locus only from singularity ports and
   mandatory-edge endpoints, so the remaining nodes are **contact nodes**. With `certificationCutEdges = 0` the
   crossing path contributes nothing, and the failing node is a contact node whose event names edge `25-31`.

3. **Three of the five `nullopt` branches are excluded; the remaining two are not separable.** Edge `25-31` **is**
   an edge of face `(25,30,31)` — mesh row **41**, confirmed with `tools/fixture_probe.py` — and the caller already
   resolved the face and found it in `sideRank`. So the failure is either the *opposite-carrier* branch or the
   *source-vertex fallback* branch. **The emitter retains only `sourceEdge`, `sourceFace` and the reason** — no
   arc, trace, orientation, segment interval or carrier — so nothing in TB14 separates them.

4. **CB16 already built the fix pattern, one helper over.** CB16 discharged BL3 by giving the *vertex* helper a
   typed `VertexTraceSecondaryParameterFailureReason` (`SecondPointUnavailable`, `InvalidDenominator`) with a
   projected field and a name function. `edge_locus_secondary_rank` keeps five untyped `return std::nullopt`
   statements. The successor applies the existing in-tree pattern; it invents nothing.

Under BM8 — *"If evidence is insufficient, freeze the minimum diagnostic CB necessary to make the missing incidence
observable rather than speculating"* — no product correction is authorized.

---

## 2. BM0 — immutable and corrected evidence authority

Verified this turn with `.agents/Directional/tools/review_check.py` and `selector_probe.py`:

| Datum | Declared | Verified |
|---|---|---|
| semantic/package source | `6808c090f2dd229a48550d758f459bfd156da4b6` | exists, `M3-CP4c-3-CB16: fix mechanical witness helper type`, ancestor of HEAD |
| code drift source→HEAD | — | **empty** over `src include tests benchmarks CMakeLists.txt cmake` |
| selector 380 | `1a95d328…d852a0e4e` | LF-blob SHA-256 = `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e` |
| selector 380 cardinality | 380 identities | 380 |
| selector 379 prefix | `ef51298f…842594b7` | `head -379` reproduces it |
| accepted 365 prefix | `6b5b6555…cfc14b8a1` | `head -365` reproduces it |

CB16 therefore appended exactly one identity and reordered nothing, and the empty code drift licenses §3–§6 as
static evidence about immutable package 84.

**The exact-line `[ OK ]` parser defect was reporting-only, and this is provable rather than asserted.** The
corrected ledger was derived from *per-process exit codes and terminal GoogleTest logs*, which are produced by the
runtime and captured before any parsing. The parser consumed those artifacts to produce labels; it could not feed
back into execution order, exit codes, log bytes, or the package tree. The 58-file byte/mode postflight equals
preflight, and every mutation flag is false. **No semantic rerun is authorized or needed** — reruns are for
changed semantics, and nothing semantic changed.

`M3-CP4c3-TB14-ORCH-01` (local-host interruption, superseded by the complete replacement run) and
`M3-CP4c3-TB14-ORCH-02` (the reporting-only parser defect) are **resolved non-stable orchestration candidates and
are not product owners**. The earlier interruption is infrastructure history only.

Accepted as reported: 380 exact fresh-process selections, **371 PASS / 9 RED**, ordinals **1–365 = 365/365**, first
red 366, selector 379 PASS, selector 380 RED at its final production assertion, the non-gating mechanical
diagnostic RED at the same edge/reason with zero gate credit.

---

## 3. BM1 — every producer and projection of the reason

`EdgeTraceSecondaryRankInvalid` appears at exactly three places in package 84: the enum declaration
(`GlobalTopologyPlan.h:163`), the name mapping (`GlobalTopologyPlan.cpp:2164-2165`), and **one emission site**,
`EmbeddedGraphTopology.cpp:1440`, in the edge-locus branch of `build_rotation_system`:

```cpp
const auto secondary = edge_locus_secondary_rank(
    topology, *locusIt->second.edge, arc, incidence.orientation, *trace);
if (!secondary.has_value()) {
  GlobalTopologyPlanError result = error(RotationSystemInconsistent);
  result.sourceEdge = locusIt->second.edge;
  result.sourceFace = face;
  result.rotationSystemInconsistencyReason = EdgeTraceSecondaryRankInvalid;
  return result;
}
```

**One emitter, no collapse at the reason level** — unlike TB13's two-emitter ambiguity. No downstream translation
can fabricate or collapse the reason; the string is produced from the enum by a single `switch` arm.

The collapse is one layer down. `edge_locus_secondary_rank` has **five distinct `return std::nullopt` sites** and no
typed reason, and the emitter retains **no** arc, trace, orientation, segment interval or carrier. `CB16` did not
touch this helper (verified by diffing the TB13 and TB14 package sources), so the gap predates it.

---

## 4. BM2 — tracing the failing edge incidence

### 4.1 The five `nullopt` branches

```
(1) trace_ray_face(arc, orientation, trace) has no value
(2) topology.faces has no record for that face
(3) local_edge_index(face, locus) has no value              -- locus edge not an edge of the ray's face
(4) other.has_value() && (local_edge_index(face, *other) missing || *otherIndex == *contactIndex)
(5) fall-through: other absent AND no corner of face equals trace.sourceVertex
```

### 4.2 Branches 1–3 are excluded

The caller resolves `face = trace_ray_face(...)` and requires `sideRank.count(*face) != 0` immediately before,
emitting `EdgeTraceFaceSideInvalid` otherwise. So the face resolved, exists in `topology.faces`, and is incident to
the locus edge — branches 1 and 2 cannot fire.

Branch 3 is excluded by the fixture: face `(25,30,31)` is **mesh row 41**, and edge `25-31` is one of its three
edges (`fixture_probe.py edge 25 31` → interior, incident rows **41** `(25,30,31)` and **198** `(115,25,31)`,
dihedral **91.302°**). `local_edge_index` therefore returns a value.

### 4.3 Branches 4 and 5 are both live, and TB14 cannot separate them

`other` is bound only under a strict carrier match:

```cpp
if (orientation == Forward) {
  if (segment.incomingCarrier.has_value() && *segment.incomingCarrier == locus)
    other = segment.outgoingCarrier;
} else if (segment.outgoingCarrier == locus) {
  other = segment.incomingCarrier;
}
```

At a **contact** node this match is not guaranteed. A contact node's event edge is a *common carrier* label
(`field_aligned_common_carrier`) or a terminal barrier; the contact **point** generally lies in the face interior.
So the arc's first/last segment at that node may well have entered or left through a different edge than the locus,
leaving `other` unbound and dropping into branch 5 — or bound to a carrier that is not an edge of this face,
firing branch 4.

**The retained evidence names neither.** The emitter carries no arc, trace, orientation, segment bounds,
`incomingCarrier`, `outgoingCarrier` or `trace.sourceVertex`. This is the exact missing datum.

### 4.4 A conditional finding, recorded but not asserted

**If** branch 5 fires, its failure is structurally guaranteed on this witness rather than incidental. The fallback
searches the face's corners for `trace.sourceVertex` — the vertex the trace **originated** from. Row 41's corners
are `{25, 30, 31}`, and the mechanical fixture's port-emitting singularities are **{10, 35, 47, 71}**. No trace can
originate at a corner of row 41, so the fallback can never succeed for *any* ray whose face is row 41.

That is origin-namespace reasoning of exactly the kind already recorded as `LESSONS.md` §4 85 and 87 — a value that
is only correct when the trace happens to start in the face being ranked. It is stated here as a conditional, not
as the cause, because branch 4 remains open.

---

## 5. BM3 / BM4 — the contract, audited whole

The intended edge-locus contract is legible from the code and its comment: rank a ray **relative to the locus
edge**, topologically, "*without using geometry*". For an ordinary through-ray the rank is
`2·((otherIndex + 3 − contactIndex) mod 3)` — the ray's destination carrier measured from the contact carrier in the
face's own corner ordering, giving even ranks; the source-vertex fallback yields odd ranks `1 + 2·corner`,
interleaving rays that terminate at a corner between the carrier-to-carrier cases. Both are exact, enumeration-
invariant, and orientation-aware, and both integrate with `key.primary = sideRank` (or `2·sideRank + 1` when
mandatory/cut edge rays are present) so that trace rays interleave with edge rays on each side.

**Whether the rejected incidence is semantically valid cannot be decided without knowing its branch**, which is
precisely why BM3 must not be answered by guessing:

- if **branch 4** fired, a segment's other carrier is not an edge of its own face — an *upstream* provenance
  question, and the owner would be the producer, not the rank helper;
- if **branch 5** fired, the incidence is likely valid and the *fallback* is under-specified for contact-node rays
  — the owner would be the rank contract itself, and the correction would need a locus-relative rank that does not
  depend on where the trace originated.

These have **different owners and opposite corrections**. Choosing now would repeat the failure mode this project
has recorded four times.

One structural observation for the successor, offered as scope guidance rather than a finding: the fallback's odd
ranks `1 + 2·corner` are indexed by the face's **corner** ordering while the carrier ranks are indexed by
**edge** ordering. Any correction must show the two remain mutually consistent and collision-free, per BM4.

---

## 6. BM5 — accepted-boundary and generalization safety

The frozen successor is **diagnostic-only**, so accepted-boundary safety is structural rather than argued:
typed reasons, retained fields and a projected diagnostic add information at a site that **already returns an
error**. No control-flow decision, rank value, ordering, or acceptance changes, so ordinals **1–365 cannot be
affected** and their observed outputs are preserved by construction.

Explicitly **not** authorized: weakening any assertion to make ordinal 366 green; any fixture-index special case;
any id- or enumeration-order tie-breaker; any change to the rank formulas, `sideRank`, `key.primary`, collision
detection, or the vertex-locus path CB15/CB16 settled.

---

## 7. BM6 — the v47 obligation, and candidate dispositions

**`M3-CP4c3-TB11-CAND-01` remains OPEN.** Selector 380 — the identity carrying the v47 five-ray/distinct-rank
production assertion — **RED**s at its final production assertion precisely because attempt-0 rotation returns
`EdgeTraceSecondaryRankInvalid`. The full five-ray v47 rotation with distinct secondary ranks for the former pair
(arc 20 / trace 6 / Forward and arc 23 / trace 9 / Reverse) is **again not published**. Selector-379 PASS and the
absence of `RotationRayOrderKeyCollision` remain necessary but insufficient, exactly as BM6 states.

- **`M3-CP4c3-TB12-REV-CAND-01`** — remains **PARTIALLY RUNTIME DISCRIMINATED**. The origin-namespace rank defect
  is corrected in source and the collision is gone, but the production five-ray proof is still unreached.
- **`M3-CP4c3-TB13-CAND-01`** — **CLOSES**. Its subject was the collapsed `VertexTracePortOrdinalInvalid` reason;
  CB16 split it via `VertexTraceSecondaryParameterFailureReason`, and TB14 shows the vertex loci are now all
  cleared, so the ambiguity is both fixed and no longer reachable.
- **`M3-CP4c3-TB13-REV-CAND-01`** — **CLOSES / RUNTIME PROVED**. Its subject was the missing vertex-exit case in
  `vertex_trace_ray_second_point`; TB14 proves the rotation now passes **every** vertex locus, including v10, which
  is only possible if that case resolves.
- **`M3-CP4c3-TB14-ORCH-01` / `-ORCH-02`** — resolved non-stable orchestration candidates, not product owners.
- **New `M3-CP4c3-TB14-CAND-01`** — **ACTIVE / GATING**: the edge-locus rank helper collapses five failure
  conditions into one untyped `nullopt` and its emitter retains no incidence identity. Owner: **BN1–BN4** of
  `M3-CP4c-3-CB17`.

**There is still no vertex-30 discriminator**, and `M3-CP4c3-TB6-CAND-01` stays ACTIVE. Note that the failing face
is row **41** `(25,30,31)`, which `DEFN-R2` proved is **unreachable as a vertex-30 continuation owner** — that
proof concerns continuation ownership at vertex 30 and is **not** contradicted by a trace having a segment in row
41 reached through ordinary transits. No vertex-30 conclusion may be drawn from this red.

---

## 8. BM7 — carried surfaces stay independently owned

- **368** — prescribed-sphere `TraceEventPositionInvalid` / `NoCarrierMatch`: `M3-CP4c2-TB-X2-CAND-04`, unchanged.
- **369** — saturation / ordinary-proposal coverage: `M3-CP4c2-TB-X2-R10-CAND-01`, unchanged.
- **370** — empty-network typed-code/locus surface: `M3-CP4c2-TB-X2-R8-CAND-02`, unchanged; **no correction
  authorized**.
- **371 / 372** — test-coupled through the shared mechanical fixture, inheriting the ordinal-366 upstream stop
  only; `M3-CP4c3-TB10-REV-CAND-01` stays **DEFERRED**.
- **374** — pre-classified folded-cone `atlasBuild=false` fixture surface: `M3-CP4c3-TB7-CAND-02`, unchanged.
- **finalize/contact fall-through** and **vertex 30** remain separate and ACTIVE.

**No duplicate stable event** is recorded for the shared upstream stop. **+0 stable events / +0 recurrences**;
totals remain **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, packages **81**.

---

## 9. BM8 — the single frozen successor: `M3-CP4c-3-CB17`

**Type:** Code + Build. **Diagnostic-only**, under BM8's insufficiency clause. **Owner:**
`src/geometry/EmbeddedGraphTopology.cpp::edge_locus_secondary_rank` and its single emitter.

- **BN0** — accepted 365 untouched; **selector 380 byte-frozen** at `1a95d328…d852a0e4e`, republished unchanged;
  **eight standard compile targets with mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BN1** — give `edge_locus_secondary_rank` a **typed failure reason**, mirroring CB16's
  `VertexTraceSecondaryParameterFailureReason` exactly in shape: one enum value per `nullopt` site —
  ray-face unavailable, source-face record missing, contact edge not in face, opposite carrier missing/not in
  face, coincident local edge index, and source-vertex fallback unbound. Return it instead of a bare `nullopt`.
- **BN2** — retain the incidence on the error: **arc, trace, orientation, segment interval
  (`firstSegment`/`onePastLastSegment`), the segment's `incomingCarrier` and `outgoingCarrier`, the resolved
  `contactIndex`, the candidate `other` carrier, `trace.sourceVertex`, and the face's three corners.** Project and
  render each. This is the exact set §4.3 shows is missing; do not broaden past it.
- **BN3** — reuse CB16's projection pattern: a typed field on `GlobalTopologyPlanError`, a name function beside
  `vertex_trace_secondary_parameter_failure_reason_name`, and the `RemeshPipeline` locus projection, so the reason
  survives to the production renderer rather than a test-local one.
- **BN4** — publish, at the failing edge locus, a **bounded** census of that node's rays (kind, `primary`,
  `secondary` where available, arc, trace, orientation, face) with an explicit truncation marker — the same shape
  CB14 added for the vertex locus, which is what made TB12 decisive.
- **BN5** — witnesses: a compile-time/unit witness per new typed reason proving each is reachable and renders
  through the **production** path, plus a regression witness that a successful edge-locus rank returns the
  byte-identical value and rotation before and after.
- **BN6** — append **selector 381** only on demonstrated falsification; no reordering of any existing ordinal.
- **BN7** — prohibitions: **no semantic change whatsoever** — no change to the rank formulas, the fallback,
  `sideRank`, `key.primary`, collision detection, `build_node_loci`, contact-node construction, or the
  vertex-locus path; no identity or enumeration-order tie-break; no tolerance or float; no accepted-boundary
  weakening; no fixture special case; no revert of CB12/CB14/CB15/CB16; no finalize/contact repair; no 371/372
  decoupling; no sphere, saturation, ordinal-370 or folded-cone correction.
- **BN8** — audit by assumption; prove that no control-flow decision, rank value or rotation changes, and that
  ordinals 1–365 are unaffected by construction.
- **BN9** — publish six `M3-CP4c-3-TB15` discriminators in advance:
  1. ordinals **1–365 remain 365/365**;
  2. ordinal 366 still reds at `EdgeTraceSecondaryRankInvalid`, still at edge `25-31` / face `(25,30,31)`, attempt
     0 / 0 cut edges — **any movement falsifies BN7**;
  3. the line now names **which** of the enumerated `nullopt` conditions fired;
  4. the line carries the arc, trace, orientation, segment interval and both carriers, so the next review can
     decide validity;
  5. the bounded edge-locus ray census is present;
  6. **the v47 conjunction remains owed** — selector 380's production assertion is expected to stay RED until the
     edge-locus owner is corrected, so `M3-CP4c3-TB11-CAND-01` and `M3-CP4c3-TB12-REV-CAND-01` do **not** close.

**No product correction and no vertex-30 discriminator are authorized until TB15 names the branch.**

---

## 10. Assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review describes package 84. | `review_check.py authority 6808c090` — ancestor of HEAD, **empty** code drift. |
| §2 | The parser defect was reporting-only. | The corrected ledger derives from per-process exit codes and terminal logs, which precede parsing; postflight equals preflight byte-for-byte and all mutation flags are false. |
| §1.1 | This is newly reachable code. | Contact nodes take `nodeIndex = candidate.nodes.size()` after all vertex nodes, and `incidences` is a node-id map — so every vertex locus precedes every edge locus, and TB13 failed at a vertex locus. |
| §1.2 | Zero cut edges is consistent with an edge locus. | `build_node_loci`'s events loop assigns an edge locus to any node lacking a vertex locus, not only to `syntheticCrossings`. |
| §4.2 | Branches 1–3 cannot fire. | The caller resolves the face and requires `sideRank.count(face) != 0` first; edge `25-31` is an edge of row 41 by the fixture. |
| §4.3 | Branches 4 and 5 are not separable. | The emitter sets only `sourceEdge`, `sourceFace` and the reason; the helper returns a bare `nullopt` from five sites. |
| §4.4 | The fallback would fail on this face **if** reached. | Row 41's corners are `{25,30,31}`; the port-emitting singularities are `{10,35,47,71}`. Stated as a conditional only. |
| §7 | `TB13-CAND-01` and `TB13-REV-CAND-01` may close. | TB14 clears every vertex locus, which requires the vertex-exit case to resolve; and CB16 split the collapsed reason. |
| §6 | The successor cannot affect accepted ordinals. | It adds typed reasons, retained fields and rendering at a site that already errors; no decision changes. |
| BN9.2 | Ordinal 366 will not move. | CB17 changes no semantics. If the locus or reason moves, BN7 was violated and the turn is invalid. |

---

## 11. Lessons

- **91 (new).** *Clearing a stage exposes the next stage's untested contract.* CB16 fixed the last vertex-locus
  defect and the very next node the rotation reached was the **first contact node ever processed on this witness** —
  whose edge-locus rank helper had never run here. Neither the helper nor its diagnostics were wrong *for the
  inputs they had previously seen*; they had simply never been exercised. When a correction unblocks a traversal,
  expect the newly reachable code to have the diagnostic maturity of code that has never failed, and budget for it.
- **92 (new).** *A typed-reason split is a pattern, not a patch.* CB16 correctly applied BL3 to the vertex helper
  and left the structurally identical edge helper with five untyped `nullopt` returns — so the next failure was
  again unattributable, for the same reason, one helper over. When a turn fixes a diagnostic-collapse defect, the
  measure should name the **class** (every helper returning bare `nullopt` into a single typed reason), not the one
  instance the current red exposed.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB17`** under **BN0–BN9**.

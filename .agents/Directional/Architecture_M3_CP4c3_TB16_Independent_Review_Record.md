# M3-CP4c-3-TB16 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB16-REV`
**Type:** independent REVIEW + PLAN. Static only.
**Governing scope:** `Architecture_M3_CP4c3_TB16_Independent_Review_Plan.md`, measures **BQ0–BQ8**.
**Boundary honoured:** no Directional runtime, benchmark, configure, compile, link, package, or
product/test/fixture/selector mutation. Every derivation is a static reading of the exact packaged source
`a01016ca59314232526c8b1222c96235856ace6d` and of committed fixture bytes, using the read-only helpers in
`.agents/Directional/tools/`.

---

## 1. Executive adjudication

**The new frontier is a product region-builder defect, and it is proved without needing the data TB16 did not
retain.** `build_regions` and `build_fragment_corner_incidence` contain the **same** carrier-less trace-segment
predicate, written twice, on the **same** trace-global datum. The copy diverged in **two** places, and both are
defects:

1. **The datum is wrong for every non-first segment.** The branch treats `incomingCarrier == nullopt` as a
   source-port incidence and searches the face for **`trace->sourceVertex`** — the vertex the *whole trace*
   originated from. But `SurfaceCellTracing.cpp` calls `incomingCarrier.reset()` at both vertex-transit
   continuations (`:2335`, `:2432`), so a carrier-less segment is *ordinarily* an Amendment-3 vertex continuation,
   not a port origin. This is the **fourth** instance of the class CB18 just corrected one stage earlier — and BQ3
   is right that it may not be imported blindly, because §5 shows the region path also diverges in a second way.
2. **The region path consumes a segment its sibling documents as hypothetical.**
   `build_fragment_corner_incidence` skips the trace's final segment when the trace has no `terminalBarrier`,
   with the recorded reason that *"the retained outgoing carrier is only a hypothetical continuation."*
   `build_regions` has no such skip: it counts that segment in `tracePieceCount`, inserts its `outgoingCarrier`
   into `traceTouchedEdges`, and derives orbit evidence from it.

**And the evidence decides which divergence pulled the trigger.** `build_fragment_corner_incidence` runs **first**
(`:1492` vs `:1660`), over the same arcs and the same segment ranges, with a textually identical predicate — and it
**passed**. The only path in that loop that skips a carrier-less segment is the terminal-slit `continue`. Therefore
**the failing segment is the trace's last segment on a trace with no terminal barrier**, and the region path failed
it only because it does not skip what the sibling skips.

**Proved from the committed fixture, with no unretained datum:** face `(9,11,17)` is mesh **row 18**, in vertex
**11**'s closed six-face fan. The four port-emitting singularities are **v10, v35, v47, v71**; the corners of row 18
are `{9, 11, 17}`. The two sets are disjoint. A trace's *first* segment always sits in a face containing
`trace->sourceVertex` — construction requires `field_boundary_point_at_vertex(startFace, port.sourceVertex)` to
succeed or the network build fails `InvalidCandidateTraceBinding`. So **the failing segment is not any trace's
first segment**, whichever trace it belongs to, and the failing disjunct is **`sourceCorner` not found**, never the
outgoing-rank test.

**BQ5 owner: product region-builder defect — established.** Not a witness precondition, not stale provenance, not
insufficient evidence. The successor must reconcile **both** divergences: fixing only the datum scopes the repair
to the symptom and leaves `build_regions` consuming a hypothetical carrier; fixing only the skip leaves the datum
defect latent until a witness produces a *non-terminal* carrier-less segment.

**Accepted authority remains 365/365; v47 and CB18 closure preserved; stable accounting unchanged at 44 / 14 / 30,
debt 5, semantic packages 83.** This review is static: **+0 events / +0 recurrences**.

---

## 2. BQ0 — immutable evidence authority re-established

### 2.1 Source and drift

`tools/review_check.py authority a01016ca59314232526c8b1222c96235856ace6d` — **ALL CHECKS PASSED**:

- the commit exists (`M3 CP4c-3 CB18: correct edge-locus segment endpoint rank`, 2026-09-03 02:02:37 +0000);
- it is an ancestor of `HEAD`;
- **no code drift `source..HEAD`** — so static reading of the working tree is valid evidence about package 86.

### 2.2 Selector identity

`tools/selector_probe.py hash 382 --prefix 365 380 381`, over LF-normalized bytes:

| quantity | recomputed | agrees with the plan |
|---|---|---|
| selector 382 | `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a` | yes |
| identities in 382 | 382 | yes |
| prefix 381 | `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90` | yes |
| prefix 380 | `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e` | yes |
| prefix 365 (accepted) | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` | yes |

### 2.3 The corrected ledger is arithmetically closed

**374 PASS + 8 RED = 382**, exactly the selector cardinality. The eight true reds — 366, 367, 368, 369, 370, 371,
372, 374 — resolve through `selector_probe.py ordinal` to the mechanical entry path, rotation/face-walk agreement,
the prescribed sphere, saturation, empty-network, the two `FieldTransportAtlas` contracts, and the folded cone;
**373 passes**, which is its long-standing synthetic-only result. Every red is `≥ 366`, consistent with accepted
**365/365** and first red **366**. No ordinal is both counted and listed.

### 2.4 `M3-CP4c3-TB16-ORCH-01` cannot alter the semantic disposition

The runner's exact-`[ OK ]` parser bug rewrites **generated summary fields**. It runs *after* per-identity process
exit and cannot reach execution order, exit codes, package bytes, or which identity a filter selected. The
independent corrections above — cardinality closure, red-list coherence, prefix continuity, and the unchanged
pre/post byte+mode census `606d193e…be10db` — are derived from the immutable ledger and the package census, not
from the generated summary. **The reconstruction stands without a rerun, and no rerun is authorized.**

---

## 3. BQ1 — the exact control path, and how it differs from its siblings

`RegionTraceSourcePortCarrierNotAdmissible` has **exactly one** emitter: `src/geometry/GlobalTopologyPlan.cpp:665`,
inside `build_regions` (defined `:409`, called from `GlobalTopologyPlan::make` at `:1660`).

**Guards required to reach it.** Per trace arc: `arc.kind == Trace`, `arc.trace` present, the trace resolvable with
`firstSegment < onePastLastSegment <= segments.size()`, both darts in range, then per segment the face must resolve
in `topology.faces`. The branch is entered when **`segment.incomingCarrier == nullopt`**. It then fails when
either

- `sourceCorner` is not found — no corner of the segment's face equals `trace->sourceVertex`; or
- `*outgoing != (*sourceCorner + 1U) % 3U` — the outgoing carrier is not the edge one step after that corner.

It publishes **only `failure.sourceFace`**.

**Distinguished from its siblings:**

| code | where | why it is not this failure |
|---|---|---|
| `RegionTraceSegmentCarriersCoincide` (`:634`) | same loop, `incomingCarrier.has_value()` branch | the two branches are mutually exclusive on `incomingCarrier` |
| `RegionTraceSegmentTurnNotAdmissible` (`:640`) | same, chord-turn test | same exclusivity |
| `TraceSourcePortCarrierNotAdmissible` (`:348`) | `build_fragment_corner_incidence`, called **earlier** at `:1492` | **textually identical predicate on the identical datum** — see §5. It ran first and passed, which is the discriminating fact of this review. |

---

## 4. BQ2 — the failing incidence, reconstructed to the limit of evidence

### 4.1 What the fixture fixes (`tools/fixture_probe.py`)

- `rows 9,11,17` → **mesh row 18** = `(9, 11, 17)`. (Per the tools README, a locus face key is a canonical sorted
  *set*; row 18's actual corner order is also `(9, 11, 17)`.)
- `fan 11` → vertex 11 has a **closed six-face fan**: rows 8 `(8,10,11)`, 109 `(10,11,79)`, 108 `(11,78,79)`,
  119 `(11,17,78)`, **18 `(9,11,17)`** at slot 9, and 9 `(8,9,11)`. So the failing face is an ordinary interior
  face of a regular vertex's fan — `vertex 11` reports `angleDefect = +0.000000000`.
- `singular` → the four clean index-`+1` vertices are **v10, v35, v47, v71**, matching the project's recorded four
  port-emitting singularities. (Corroboration only, per the README's first caveat; here it agrees with the product
  fact already in `ORIENTATION.md`.)

### 4.2 Three things the evidence proves outright

**(a) The failing segment is carrier-less.** It is the branch's entry condition.

**(b) It is not any trace's first segment.** A trace is constructed with `sourceVertex = port.sourceVertex`, and
its first segment's face is `attachment->startFace` with entry point
`field_boundary_point_at_vertex(currentFace, port.sourceVertex)` — which must succeed or the build fails
`InvalidCandidateTraceBinding` (`SurfaceCellTracing.cpp:2221-2251`). So **a first segment's face always contains
that trace's `sourceVertex`.** Port vertices ⊆ `{10, 35, 47, 71}`; corners of row 18 are `{9, 11, 17}`; disjoint.
Note this holds for *every* trace, so it does not depend on identifying which one failed.

**(c) The failing disjunct is `sourceCorner` not found**, never the outgoing-rank test — by the same disjointness.
`build_fragment_corner_incidence` independently guarantees `port->sourceVertex == trace->sourceVertex` for every
trace arc (`:207-212`) and it passed, so `trace->sourceVertex` is provably a port vertex here.

**(d) It is the trace's last segment, on a trace with no `terminalBarrier`.** See §5.2 — this follows from the
earlier identical predicate having passed.

### 4.3 Named unknowns — data TB16 did not retain

Recorded rather than guessed, as BQ2 requires. The emitter publishes only `sourceFace`, and the runtime published
`cutCandidateCount=0` alongside it. Not retained: the **trace id**, the **arc id**, the arc **orientation**, the
**segment index** and `[firstSegment, onePastLastSegment)` range, the concrete value of `trace->sourceVertex`, the
entry and exit `FieldBoundaryPoint` supports, the **source port / singularity id**, the outgoing carrier, and the
neighbouring region/orbit evidence. None of §4.2's conclusions depends on any of them; the successor's diagnostic
obligation (BR4) exists so the next TB confirms this reconstruction rather than re-deriving it.

---

## 5. BQ3 + BQ4 — the region contract, adjudicated on its own terms

### 5.1 A later carrier-less segment is legitimate, and the producer says so

`incomingCarrier.reset()` appears at exactly two sites in `SurfaceCellTracing.cpp` — `:2335` and `:2432` — the
`VertexHit` and edge-transit **vertex-transit continuations**. Both then push a segment whose entry point is
`field_boundary_point_at_vertex(nextFace, transitVertex)`. So a carrier-less segment is *ordinarily* an
Amendment-3 vertex continuation, and its entry vertex is the **transit** vertex, carried on the segment itself.

**Therefore `incomingCarrier == nullopt` does not mean "source port".** It means "entered through a corner". Source
port is the special case where that corner is the trace's origin — i.e. the first segment. The region fallback's
identification of the two is correct exactly on segment 0 and wrong on every other carrier-less segment. The
producer's provenance is **not** stale or invalid; the consumer's inference is.

This is the **fourth** instance of the class recorded as lessons 85/87 and corrected by CB18 one stage earlier —
but, as BQ3 anticipated, importing CB18's answer alone would be scoping by symptom, because of §5.2.

### 5.2 The two paths are duplicates that diverged twice

Both loops iterate the **same** `arcs`, filter `arc.kind == Trace`, and walk `arc.firstSegment ..
arc.onePastLastSegment`, so they see an identical segment set. The carrier-less predicate is textually identical in
both. The divergences are:

| | `build_fragment_corner_incidence` (`:180`, runs `:1492`) | `build_regions` (`:409`, runs `:1660`) |
|---|---|---|
| terminal segment, no `terminalBarrier` | **skipped** (`:242-249`), because "the retained outgoing carrier is only a hypothetical continuation" | **processed** — counted in `tracePieceCount`, its `outgoingCarrier` added to `traceTouchedEdges`, orbit evidence derived from it |
| carrier-less datum | `trace->sourceVertex` | `trace->sourceVertex` — same defect |
| `forwardOrbit == reverseOrbit` | rejected `TraceArcDoesNotSeparateItsSides` | not checked |

**This is what makes the failing segment identifiable.** The earlier loop evaluated every carrier-less segment
except terminal slits and returned success. Its predicate is identical, so any carrier-less segment it accepted,
the region loop would also accept. The region loop rejected one. The only path by which a carrier-less segment
escapes the earlier predicate is the terminal-slit `continue`. **Hence the failing segment is a terminal slit** —
proved, not assumed.

### 5.3 What a correction would change among currently-succeeding inputs

BQ4 asks this explicitly, and the answer is why the successor is **not** accepted-safe by construction — the same
caution TB15-REV raised before CB18:

- **Every terminal-slit segment `build_regions` currently consumes.** Skipping them changes `tracePieceCount`,
  which feeds the fragment-count invariant `expected = tracePieceCount[face] + 1` (`:685-695`); it changes
  `traceTouchedEdges`, which gates the untouched-source-edge equivalence; and it removes their orbit evidence.
  **None of this is a no-op and none may be assumed benign.**
- **Every non-first carrier-less segment's corner binding**, in both loops, once the datum is corrected.
- Forward/Reverse both matter: the branch derives `forwardEdge = edges[(corner+2)%3]` and
  `reverseEdge = edges[corner]` from the bound corner, so re-binding the corner moves both orbit-evidence
  insertions.

The torus reaches A2b end to end, so accepted identities plausibly exercise `build_regions`. **Accepted-boundary
safety must be demonstrated by pinned before/after values, not argued.**

---

## 6. BQ5 — owner classification

**Product region-builder datum/namespace defect.** Established, with two divergences under one root cause: the
region loop was written by copying the fragment-corner loop and diverged in the terminal-slit contract while
inheriting the trace-global datum.

Rejected alternatives:

| class | verdict |
|---|---|
| upstream network/provenance defect | **falsified.** The producer sets `incomingCarrier = nullopt` deliberately at both vertex-transit continuations, and the segment carries its own entry support. Nothing upstream is stale. |
| witness/test-precondition defect | **not supported.** Face `(9,11,17)` is an ordinary interior face in a regular vertex's closed fan; ordinals 1–365 are green in the same run; the fixture is the committed production witness. |
| insufficient evidence → diagnostic-only | **rejected, narrowly.** The unretained data of §4.3 are real, but the owner, both defects, and the failing disjunct are all proved without them. A diagnostic-only turn would spend a cycle confirming a conclusion already established. The successor therefore carries the diagnostic obligation *alongside* the correction rather than instead of it. |

---

## 7. BQ6 + BQ7 — closures preserved and surfaces kept separate

**Preserved as settled runtime evidence; nothing here contradicts them.** Accepted **365/365**; selector 382 PASS;
the old edge-`25-31` `EdgeTraceSecondaryRankInvalid` failure cleared; mechanical attempt-0 rotation publishes
completely; `M3-CP4c3-TB11-CAND-01`, `M3-CP4c3-TB12-REV-CAND-01` and `M3-CP4c3-TB15-CAND-01` remain **CLOSED /
RUNTIME PROVED**. Reaching a later error is not evidence against an earlier closure — and §5 shows the new failure
sits in a *different function*, at a *later* call site, on a contract CB18 never touched.

**Kept independently owned, with no new evidence folding them in:** prescribed sphere 368; saturation 369;
empty-network 370; the 371/372 fixture coupling; folded-cone 374; vertex 30 (`M3-CP4c3-TB6-CAND-01` — **no
vertex-30 discriminator is published by TB16**); the `finalize_field_aligned_events` contact fall-through; and
package/reporting hygiene including `M3-CP4c3-TB16-ORCH-01` and `M3-CP4c3-TB15-PKG-01`.

Ordinals **367, 371, 372** remain upstream-blocked by ordinal 366 through the shared `cp4c_mechanical_fixture()`
constructor — one cause, not three, exactly as adjudicated at TB10-REV; 371/372's separable coupling remains
`M3-CP4c3-TB10-REV-CAND-01`.

---

## 8. BQ8 — one bounded successor: `M3-CP4c-3-CB19`, measures **BR0–BR9**

**Type:** product correction, Code + Build, runtime-free, GMP/GMPXX linked.
**Owner:** `src/geometry/GlobalTopologyPlan.cpp` — `build_regions` (`:409`) and `build_fragment_corner_incidence`
(`:180`), reconciled together. One owner: the two loops encode one obligation.
**Permitted mutation surface:** those two functions, the typed codes they emit, their diagnostics, and the tests
that witness them. Nothing else.

### BR0 — preconditions

Selectors **380, 381, 382** byte-frozen and recomputed at authoring and preflight (LF-normalized — a naive
`sha256sum` on a CRLF checkout will not reproduce them); accepted 365 prefix untouched; `selected_gate=NONE`;
`gate_execution_authorized=false`; no runtime, gate, benchmark, or package repair; GMP/GMPXX linkage proved per
`GMP_COMPILE_POLICY.md`.

### BR1 — bind the carrier-less branch to the segment's own datum, in **both** loops

A carrier-less segment entered its face **through a corner**; that corner is the segment's own entry support, not
`trace->sourceVertex`. Bind it through `FieldBoundaryPoint::source_support()` on `segment.entryPoint` — the
primitive CB16 and CB18 already use — and derive the orbit-evidence edges from *that* corner. Keep the branch
fail-closed: if the entry support is not a vertex of this face, that is a typed rejection, not a fallback.
The trace-origin rule must survive **only** as the special case it is: the trace's first segment.

### BR2 — decide the terminal-slit contract once, and apply it in both loops

`build_fragment_corner_incidence` skips a trace's final segment when the trace has no `terminalBarrier`;
`build_regions` consumes it. **State which is correct and make both agree.** If the segment's outgoing carrier is
hypothetical, the region loop must not count it in `tracePieceCount`, must not insert it into `traceTouchedEdges`,
and must not derive orbit evidence from it. If it is real, the fragment-corner skip must be removed and justified.
Silence on this point is not an option: the divergence, not the datum, is what fired at TB16.

### BR3 — re-derive the fragment-count invariant, do not assume it

`expected = tracePieceCount[face] + 1` (`:685-695`) changes if BR2 removes terminal slits from the count. Derive
the corrected invariant from the geometry — *a face with k real trace chords has k+1 fragments* — and state
explicitly what a terminal slit contributes. A green fragment count that silently absorbed a changed operand is a
weakened check, not a passing one.

### BR4 — publish the incidence at the emitter

Both codes must carry what §4.3 lists as unretained: trace, arc, orientation, segment index and range, the
first-segment flag, `trace->sourceVertex`, the bound corner and its provenance, the entry/exit supports, and the
outgoing carrier. **Extend the projection in the same change** so the next TB can confirm §4.2/§5.2 rather than
re-derive them. Name the carrier: ordinal 366's own failure message.

### BR5 — demonstrate accepted-boundary safety, do not argue it

**This correction is not accepted-safe by construction.** Before/after, pin every currently-succeeding input in the
two classes of §5.3 — terminal-slit segments consumed by `build_regions`, and non-first carrier-less segments in
both loops — for the torus, the two-ring and the mechanical witness, and show the fragment counts, touched-edge
sets, and orbit-evidence sets that change and those that must not. Ordinals **1–365 must stay green**, and that is
a required outcome, not a hoped-for one.

### BR6 — witnesses

One **positive**: a carrier-less non-first segment whose entry corner differs from its trace's origin corner,
electing the entry corner and producing the expected orbit evidence. One **boundary/negative**: a terminal slit,
asserting the BR2 contract explicitly — including its contribution, or non-contribution, to the fragment count.
Selector **382 keeps every byte**; ordinal 383 may be appended **only** if a witness is shown to fail under
package-86 semantics and pass under the correction.

### BR7 — prohibited

Importing CB18's datum fix without settling BR2; scoping the repair to the source-port branch alone; changing any
rotation-system, cellularity, cut-proposal or admissibility decision; touching the prescribed sphere, ordinal 370,
saturation, the folded-cone witness, vertex 30, the finalize/contact fall-through, or the 371/372 fixture coupling;
any tolerance or float-derived topological decision; and any selector byte change other than the conditional BR6
append.

### BR8 — audit by assumption

Two predicates, each discharged by search, each naming at least one site **outside** those this record names:

- *"a per-segment or per-element decision is bound to a datum owned by the whole trace or the whole object"* — the
  class of lessons 85/87, now at its fourth instance;
- *"two loops iterate the same collection and apply the same predicate, but one skips a case the other does not."*

### BR9 — expected discriminators for artifact-only `M3-CP4c-3-TB17`

1. **Ordinal 366 clears `RegionTraceSourcePortCarrierNotAdmissible` at face `(9,11,17)`**, and either passes or
   first-reds at a *different* locus. A repeat at the same face means BR1/BR2 missed the branch.
2. **The next region failure, if any, publishes the full incidence** of BR4. A failure that again publishes only
   `sourceFace` is a failure of BR4.
3. **Accepted ordinals 1–365 stay green** — the required outcome of BR5, and the one most at risk.
4. **Ordinals 367, 371 and 372 either clear with 366 or produce their own first independent loci.**
5. **368, 369, 370, 374 reproduce their pre-classified surfaces unchanged.** Any movement means the correction
   reached beyond its permitted surface.
6. **§5.2's terminal-slit conclusion is testable:** the BR6 boundary witness either confirms that a terminal slit
   reaches the region loop and is now handled per BR2, or falsifies the reconstruction — a legitimate outcome that
   would return the question to review.

**Compile targets:** the eight standard targets, GMP/GMPXX linked, `runtimeExecution=false`, one package;
successor is artifact-only `M3-CP4c-3-TB17` executing selector 382 from ordinal 1, one identity per fresh process,
plus the retained non-gating mechanical diagnostic, with every mutation/build/repair/benchmark flag false.

---

## 9. Lessons retained

- **A predicate copied into a second consumer inherits its defects and then diverges — and the divergence, not the
  defect, decides which one fires.** Both loops carry the identical wrong datum; only the region loop lacks the
  terminal-slit skip, and that is the single reason TB16 shows one code and not the other. Diagnosing the shared
  defect alone would have produced a correction scoped to the symptom.
- **Two consumers of one obligation that disagree about which inputs they consume are a contract question, not a
  bug in the stricter one.** The fragment-corner loop documents *why* it skips a terminal segment. The region loop
  is silent. Whichever is right, they cannot both be.
- **An earlier identical check that passed is evidence about the input, not noise.** The whole reconstruction of
  §5.2 rests on `build_fragment_corner_incidence` having run first, seen the same segment, and accepted it.
- **The fourth instance of a class is a signal about the audit, not the code.** `trace->sourceVertex` bound to a
  per-segment decision has now been found in the vertex-locus helper, the edge-locus fallback, the rotation
  fallback and the region builder. Each was fixed at its own site. BR8's first predicate is the search that should
  have found all four at once.

# M3-CP4c-3-TB17 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB17-REV`
**Date:** 2026-09-03 UTC
**Type:** independent REVIEW + PLAN. Static only — no Directional runtime, compile, link, package, benchmark, or
product/test/fixture/selector mutation occurred in this turn.
**Governing plan:** `Architecture_M3_CP4c3_TB17_Independent_Review_Plan.md`, measures **BRQ0–BRQ8**.
**Verdict:** TB17 is a **valid semantic red**. The invariant behind `TraceCutFaceFragmentCountMismatch` is
**proved wrong as an equality** — the code compares a *local* fragment count against the cardinality of a set of
*global* orbit owners — but the direction and magnitude at face `(0,1,102)` are **not retained**, so BRQ6's
condition is not met. One **diagnostic-only** successor is frozen: **`M3-CP4c-3-CB20`** under **BS0–BS9**, and its
content is unusually cheap because the missing numbers are already computed.

---

## 1. Executive adjudication

CB19 cleared the `(9,11,17)` source-port stop and the frontier advanced to a new stage. Ordinal 366 is now
`TraceCutFaceFragmentCountMismatch` at source face **`(0,1,102)`**, published with **`sourceFace` and nothing
else**.

Four results decide this turn.

1. **One emitter, one comparison.** `src/geometry/GlobalTopologyPlan.cpp:779` is the sole emission site:

   ```cpp
   const std::size_t expected = tracePieceCount[faceKey] + 1U;
   if (found->second.size() != expected) { … TraceCutFaceFragmentCountMismatch; failure.sourceFace = faceKey; return failure; }
   ```

   `found->second` is `fragmentOrbits[faceKey]` — a **`std::set` of global orbit ids**. The comment above it states
   the geometric rule, "a face with k real trace chords has k+1 fragments".

2. **The geometric rule is right; the equality it is used to enforce is not.** Per real chord the loop does
   `++tracePieceCount[face]` **once** and `add_fragment_orbit(face, forwardOrbit)` / `(face, reverseOrbit)` —
   **two** insertions into a set. For `k` chords that is `2k` insertions required to collapse to exactly `k+1`
   distinct ids. That holds only if the local-fragment → global-owner map is **injective**, which nothing in the
   code establishes and which is **false in general on a closed surface**: two locally separated fragments of one
   triangle may belong to one globally connected region and therefore to one orbit id.

3. **A second, independent way to fail low.** `add_fragment_orbit` silently **drops** any orbit in
   `exteriorOrbits`, so a face touching the exterior can never reach `k+1` regardless of its geometry. (On the
   mechanical witness this is expected to contribute nothing — the fixture is closed with 0 boundary edges — but
   the filter is unconditional in the code and applies to every witness.)

4. **The numbers that would settle it already exist, and the failure returns before they are published.** The same
   function, at `:894-920`, fills `diagnostics->fragmentOrbits`, `diagnostics->tracePieceCount` and
   `diagnostics->edgeOrbitEvidence`, and then prints, **for every face**:

   ```
   M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation source_face=… fragment_orbit_count=…
     trace_piece_count=… expected_fragment_count=…
   ```

   Those are precisely the three values BRQ3 asks for. The validation loop's `return failure;` at `:779` occurs
   **before** that block, so on the failing run the diagnostic is **never emitted**.

The owner class is therefore *nameable* — a product local-fragment/orbit **representation** defect — while the
corrective contract is not yet demonstrable, because both failure directions remain open and the actual values are
discarded.

---

## 2. BRQ0 — immutable evidence authority

Verified this turn with `.agents/Directional/tools/review_check.py` and `selector_probe.py`:

| Datum | Declared | Verified |
|---|---|---|
| semantic/package source | `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e` | exists, `M3-CP4c-3-CB19: restore source support diagnostics projection`, ancestor of HEAD |
| code drift source→HEAD | — | **empty** over `src include tests benchmarks CMakeLists.txt cmake` |
| selector 382 | `f30d5d56…50d665a1a` | LF-blob SHA-256 = `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a` |
| selector 382 cardinality | 382 identities | 382 |
| accepted 365 prefix | `6b5b6555…cfc14b8a1` | `head -365` reproduces it |

Accepted as reported: the exact ledger `7c446413…aa36b6fd` at **374 PASS / 8 RED**, accepted **1–365 = 365/365**,
first red 366, the red set {366, 367, 368, 369, 370, 371, 372, 374}, the non-gating diagnostic RED, and the
identical pre/post byte+mode census `0438202b…3dbcd518`.

**The control-plane runner and the recorded `READ_MODE` process miss cannot have altered the semantic result.**
Package bytes are pinned by the artifact and inner-tar digests and re-verified identical after execution; selector
membership and order are pinned by the selector file, whose LF hash and 365-prefix both recompute here; each
identity ran in its own fresh process, so per-identity exit codes are produced by the packaged binaries and not by
the runner's bookkeeping. A read-order or reporting miss can misdescribe that evidence but cannot change it. **No
rerun is authorized or needed.**

---

## 3. BRQ1 — CB19's proved facts, preserved

The following are carried forward unchanged; nothing in TB17 contradicts them, and the new invariant failure is
downstream of all of them:

- the old `RegionTraceSourcePortCarrierNotAdmissible` at `(9,11,17)` is **cleared**;
- the independent network observation finds **48** non-first carrier-less segments, and **all 48** have entry
  support distinct from the trace origin;
- the positive witness uses **`SegmentEntrySupport`**;
- there are **10** terminal slits;
- the retained terminal witness has **`realChordContribution = 0`**.

The corrected source-port datum and the terminal-slit classification are **not reopened**. Their correctness is in
fact reinforced here: `is_terminal_slit` is what makes a slit contribute zero to `k`, and the fragment loop
`continue`s on it before touching either `tracePieceCount` or the orbit set — so terminal slits are excluded from
both sides of the comparison consistently.

---

## 4. BRQ2 — the exact control path to the emitter

Reaching `:779` requires, in order: a trace/arc whose segment's `sourceFace` resolves in `topology.faces`; the
segment surviving the `is_terminal_slit` skip; the per-segment orbit and carrier work at `:695-765` completing
without emitting `RegionTraceSourcePortCarrierNotAdmissible`; and then the validation loop finding, for some face,
a non-empty `fragmentOrbits` entry whose size differs from `tracePieceCount + 1`.

The quantities at that point mean:

| Symbol | Meaning |
|---|---|
| `tracePieceCount[face]` | count of **real chords** — one per non-terminal-slit segment in the face |
| `fragmentOrbits[face]` | **set of distinct global face-walk orbit ids** contributed by those segments' forward and reverse darts, minus any orbit in `exteriorOrbits` |
| `exteriorOrbits` | orbits identified as exterior via boundary-edge evidence; members are silently dropped by `add_fragment_orbit` |
| forward / reverse orbit | the two dart orbits of one directed segment — the two *sides* of one chord |
| `edgeOrbitEvidence` | per (face, edge) orbit witnesses, accumulated but not consulted by this check |

Faces with an empty or absent `fragmentOrbits` entry are skipped (`continue`), so the check applies only to
directly cut faces.

**The distinction BRQ2 demands, stated plainly:** `tracePieceCount + 1` is a **local, geometric** quantity — how
many pieces the chords cut this one triangle into. `fragmentOrbits.size()` is a **global, topological** quantity —
how many distinct region owners those pieces happen to belong to. The code asserts they are equal. They are equal
only under an injectivity assumption that is never established.

---

## 5. BRQ3 — face `(0,1,102)`, to the limit of retained evidence

**Recovered.** The face key `(0,1,102)` is the canonical sorted vertex set; the mesh row is **259**, whose stored
corner order is `(102, 1, 0)` — reproduced with `tools/fixture_probe.py rows 0,1,102`. Vertex **0** is a chamfered
box corner of the mechanical fixture: degree 4, angle defect **1.767801150**, with edge `0-1` a **90.000000°**
sharp edge shared by rows **0** and **259**. So the failing face lies on the part's sharp silhouette, in the same
family as the corners earlier turns adjudicated.

**Not recovered, and not statically recoverable.** Every quantity the adjudication actually needs is absent from
the error, which sets `sourceFace` alone:

- `fragmentOrbits[(0,1,102)].size()` — the **actual** count;
- `tracePieceCount[(0,1,102)]` — hence the **expected** count, and the **direction** of the mismatch;
- the real trace segments in the face, their trace/arc ids, segment ranges and orientation;
- their incoming/outgoing carriers;
- their forward and reverse orbit ids, and which of those ids repeat;
- whether any contributing orbit was dropped as exterior;
- the accumulated `edgeOrbitEvidence` for the face's three edges.

These are **runtime** facts about this network. They cannot be derived from committed source and fixture bytes,
because they depend on which traces reached this face and how the global face walk labelled their sides.

**They are, however, already computed.** §1.4 shows the same function assembles all of them into `diagnostics` and
formats three of them for stderr — after the early return. This is not a missing measurement; it is a measurement
that exists, is formatted for exactly this question, and is unreachable on the path that needs it.

---

## 6. BRQ4 — adjudicating the invariant itself

> **Falsified.** It is not true that every real chord in one source triangle must add one distinct global
> face-walk orbit id.

The geometric statement — *k* real chords cut a triangle into *k+1* fragments — is correct and is not weakened
here. What fails is its identification with `|fragmentOrbits[face]|`. Three independent mechanisms break the
equality, and the retained evidence excludes none of them:

1. **Shared global owner (fails low).** Two fragments separated *inside* this triangle may be joined *outside* it,
   so they carry one orbit id. On a closed surface before any cut is applied this is ordinary, not pathological.
2. **Exterior filtering (fails low).** `add_fragment_orbit` drops orbits in `exteriorOrbits` unconditionally, so a
   face adjacent to exterior evidence cannot reach `k+1`. Expected to be inert on the closed mechanical fixture,
   but it is a property of the code, not of the witness.
3. **Non-collapsing sides (fails high).** For `k ≥ 2` the `2k` inserted ids must collapse to exactly `k+1`; if the
   chords do not separate in the assumed adjacency pattern, or if orbit evidence is duplicated or inconsistent,
   the set can exceed `k+1`.

For `k = 1` the check is trivially satisfiable (2 insertions, expected 2), so the first face that can expose this
is one with **two or more chords** — consistent with a face on the sharp silhouette where several traces run.

**The correct representation, stated for the successor's benefit and not implemented here:** local fragment
cardinality must be derived from the **local** arrangement of chords in the triangle, and orbit ids must be used
only for **ownership**. A check that wants both must compare like with like — either count fragments locally and
separately assert that ownership is well-defined, or assert an inequality that is actually implied
(`|orbits| ≤ k+1` under the exterior filter). Replacing the equality with `≤` alone would silence a real check
without restoring the missing one; that is explicitly **not** authorized.

---

## 7. BRQ5 — the two reconciled CB19 loops at this face

`build_fragment_corner_incidence` and `build_regions` share the terminal-slit predicate and the carrier-less
binding CB19 reconciled, so they classify the same material segments by construction: both skip on
`is_terminal_slit`, and both resolve carrier-less segments through `resolve_carrierless_corner_binding`.

**Whether they derive equivalent fragment/orbit evidence at `(0,1,102)` cannot be decided from retained
evidence.** The failure returns from the `build_regions` side before any per-face evidence is published, and no
retained TB17 datum reports the other loop's view of this face. Per BRQ5's own instruction, ownership therefore
moves to the **shared invariant and representation** (§6) rather than to a third copied-loop reconciliation. The
successor's instrumentation must make the two loops' views of the same face comparable, so the next review can
settle divergence or agreement on evidence instead of inference.

---

## 8. BRQ6 — owner classification

**Class: insufficient evidence requiring diagnostic-only instrumentation.**

BRQ6 permits a semantic correction only if BRQ2–BRQ5 statically prove the semantic owner **and the corrective
contract** without the omitted counts. Half of that is met and half is not:

- **Proved:** the check conflates a local geometric count with a global owner cardinality (§6). The owner class is
  the local-fragment/orbit representation, not trace/arc incidence, not upstream provenance, and not the witness —
  the mechanical fixture is a closed manifold whose face `(0,1,102)` is an ordinary sharp-silhouette triangle.
- **Not proved:** the corrective contract. The three mechanisms of §6 fail in **opposite directions** and imply
  different corrections; choosing between them without the actual and expected counts would be exactly the
  guess this project has recorded four times.

Additionally, no accepted-boundary safety argument is available: this stage passes today for the torus and the
sphere, so any change to fragment cardinality is a change to a check those witnesses currently satisfy. That is the
TB15-REV situation again, but without even the direction of the error in hand.

**Diagnostic-only is therefore mandatory**, and — unusually — nearly free: the required evidence is already
assembled a few lines below the failure.

---

## 9. BRQ7 — carried surfaces stay independently owned

- **368** — prescribed sphere `TraceEventPositionInvalid / NoCarrierMatch / SourceEdgeUnavailable`: unchanged owner.
- **369** — saturation: unchanged owner.
- **370** — empty-network typed code/locus: unchanged owner, **no correction authorized**.
- **374** — folded-cone `atlasBuild=false`: unchanged owner.
- **367 / 371 / 372** — co-reachers of the same mechanical fragment stop. Their retained logs show the same
  upstream exception, so they are **not** independent evidence for the new owner and create **no duplicate stable
  event**.
- **PASS ordinals 373 and 375–382** are preserved, including the BR5 and diagnostic-projection witnesses. Selector
  382's PASS ordinals are **diagnostic-contract evidence only** and may not be cited as proof of any product
  correction.
- **No vertex-30 and no finalize/contact work is imported.** Both remain separate and ACTIVE.

**Accounting.** TB17 loses no accepted-green behaviour and this review executes nothing. **+0 stable events / +0
recurrences**; totals remain **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic
M3 package count **84**.

**Candidate dispositions.** The TB16 source-port candidate **CLOSES** — CB19's correction is runtime-proved by the
`(9,11,17)` stop clearing. **`M3-CP4c3-TB17-CAND-01`**, opened by the TB17 turn as *owner unadjudicated*,
**transitions to owner class named**: a product local-fragment/orbit **representation** defect — the check compares
a face-local chord count against the cardinality of a set of global face-walk orbit owners, and publishes neither.
Its **corrective contract remains unadjudicated** pending the direction and the contributing incidences. Owner:
**BS1–BS4** of `M3-CP4c-3-CB20`, then `M3-CP4c-3-TB18-REV` for the semantic contract.

`M3-CP4c3-TB11-CAND-01`, `M3-CP4c3-TB12-REV-CAND-01` and `M3-CP4c3-TB15-CAND-01` stay **CLOSED** as TB16-REV left
them; the v47 five-ray re-proof and CB18 closure are **not** reopened by this turn.

---

## 10. BRQ8 — the single frozen successor: `M3-CP4c-3-CB20`

**Type:** Code + Build. **Diagnostic-only**, under BRQ6's mandate. **Owner:**
`src/geometry/GlobalTopologyPlan.cpp`, the fragment-count validation loop and the error it emits.

- **BS0** — accepted 365 untouched; **selector 382 byte-frozen** at `f30d5d56…50d665a1a`, republished unchanged;
  **eight standard compile targets with mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed. Selector
  382's PASS ordinals may **not** be cited as evidence for any product correction.
- **BS1** — put the counts **on the error**: add typed fields carrying `fragmentOrbits[face].size()` (actual),
  `tracePieceCount[face]` and the derived `expected`, and populate them at the emission site before returning.
  Render them through the production locus path. This is the datum §5 proves is missing and §1.4 proves already
  exists a few lines away.
- **BS2** — retain the face's **contributing incidences**: for each real chord in the failing face, the trace and
  arc ids, the segment index, orientation, incoming and outgoing carriers, and **both** forward and reverse orbit
  ids — plus a flag for any orbit dropped by the `exteriorOrbits` filter. A **bounded** list with an explicit
  truncation marker. This is what distinguishes §6's three mechanisms in one observation.
- **BS3** — publish the accumulated `edgeOrbitEvidence` for the failing face's three edges, bounded the same way.
- **BS4** — make the existing reconciliation diagnostic reachable on the failing path. It currently sits after the
  early return; emit the failing face's `fragment_reconciliation` record before returning, or hoist the block. Do
  **not** delete or weaken the existing all-faces diagnostic.
- **BS5** — witnesses: one per new retained field proving it renders through the **production** path, plus a
  regression witness that a face satisfying the check produces a byte-identical plan and no new output.
- **BS6** — append **selector 383** only on demonstrated falsification; no reordering of any existing ordinal.
- **BS7** — **no semantic change whatsoever.** Do not alter the comparison, relax the equality to an inequality,
  change `tracePieceCount`, `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`,
  `resolve_carrierless_corner_binding`, `build_fragment_corner_incidence`, `build_regions`, or any orbit/region
  construction. Do not revert CB19. No fixture mutation, no tolerance, no float-derived topological decision, no
  accepted-boundary weakening, no sphere / saturation / ordinal-370 / folded-cone correction, no vertex-30 or
  finalize/contact work.
- **BS8** — audit by assumption; prove that no control-flow decision, count, orbit, region or plan changes, and
  that accepted ordinals 1–365 are unaffected by construction.
- **BS9** — publish six `M3-CP4c-3-TB18` discriminators in advance:
  1. ordinals **1–365 remain 365/365**;
  2. ordinal 366 still reds at `TraceCutFaceFragmentCountMismatch`, still at face `(0,1,102)` — **any movement
     falsifies BS7**;
  3. the line now carries **actual**, **expected** and `tracePieceCount` for that face, so the **direction** of the
     mismatch is finally known;
  4. it carries the bounded per-chord incidence list with both orbit ids per chord, and any exterior-drop flag;
  5. the `fragment_reconciliation` record for the failing face is present in the retained log;
  6. the carried surfaces 368, 369, 370, 374 and the 367/371/372 co-reachers are unchanged.

**No product correction is authorized until TB18 supplies the direction and the contributing incidences.** The
successor after TB18 is an independent `M3-CP4c-3-TB18-REV`, which will own the representation decision of §6.

---

## 11. Assumption audit

| Measure | Assumption | Evidence falsifying the nearest alternative |
|---|---|---|
| §2 | Static review describes package 87. | `review_check.py authority bf971a6c` — ancestor of HEAD, **empty** code drift. |
| §2 | The runner/`READ_MODE` miss is inert. | Package bytes, selector membership and per-identity exit codes are each pinned by an independently verified digest or by fresh-process execution; a reporting miss can misdescribe them but not change them. |
| §4 | One emitter, one comparison. | `TraceCutFaceFragmentCountMismatch` appears at the enum, the name mapping and exactly one `return`. |
| **§6** | **The equality is unsound.** | Each real chord contributes **one** to `tracePieceCount` and **two** insertions to a set of global orbit ids; equality with `k+1` requires an injectivity the code never establishes, and `add_fragment_orbit` additionally drops exterior orbits unconditionally. |
| §5 | The counts are not statically recoverable. | They depend on which traces reached this face and how the global walk labelled their sides — runtime facts, absent from an error that sets only `sourceFace`. |
| §1.4 | The evidence already exists. | `:894-920` fills `diagnostics->fragmentOrbits` / `tracePieceCount` and prints `fragment_orbit_count`, `trace_piece_count`, `expected_fragment_count` for every face — after the `:779` return. |
| §8 | Diagnostic-only is mandatory. | The owner class is proved but the corrective contract is not: §6's mechanisms fail in opposite directions and imply different fixes, and no accepted-boundary argument exists for a stage the torus and sphere currently pass. |
| BS9.2 | Ordinal 366 will not move. | CB20 changes no semantics. If the locus or code moves, BS7 was violated and the turn is invalid. |

---

## 12. Lessons

- **95 (new).** *A diagnostic that is unreachable on the failing path is not a diagnostic.* This function computes
  the actual count, the expected count and the piece count for **every** face, and formats all three into a
  `fragment_reconciliation` record — thirty lines below a `return failure;` that fires precisely when those three
  numbers are the question. The instrumentation was written for this failure and cannot be reached by it. When
  adding diagnostics to a function with early returns, place them where the errors are raised, not where the
  successful path ends.
- **96 (new).** *Counting a local quantity with a global identifier silently assumes injectivity.* "k chords make
  k+1 fragments" is a statement about one triangle; `|set of orbit ids|` is a statement about the whole surface.
  Equating them assumes distinct local pieces never share a global owner — true often enough to ship, false on a
  closed surface, and invisible until a face has two chords. When a check compares a count to a set's cardinality,
  name the map between them and say why it is injective.

---

**End of record.** This turn executed no runtime, no compile, no package, and mutated no product, test, fixture, or
selector byte. The exact next turn is **`M3-CP4c-3-CB20`** under **BS0–BS9**.

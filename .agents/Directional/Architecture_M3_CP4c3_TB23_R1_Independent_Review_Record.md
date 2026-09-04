# M3 CP4c-3 TB23-R1 — Independent Review + Plan Record

Date: 2026-09-04 UTC
Turn: `M3-CP4c-3-TB23-R1-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / HARNESS CORRECTION CONFIRMED / BOTH NEW REDS ARE THE NEW WITNESSES WORKING / OWNERSHIP QUESTION PROVED UNANSWERABLE FROM THE PUBLISHED CERTIFICATE / DEFN FROZEN / NON-STABLE**

No Directional runtime, configure, compile, link, package, package repair, benchmark, or
product/test/fixture/selector mutation occurred in this turn. Measures discharged: **CE0–CE8**. Successor frozen:
exactly one — **`M3-CP4c-3-DEFN-R3`** under **CF0–CF9**.

**Headline.** CB25's diagnostics did not fail to run; they ran and proved something stronger than they were asked
to. `SurfaceCutGraphFaceCertificate` publishes only `orbit`, `boundaryWalkCount`, `boundaryArcCount` and
`discTopologyEstablished` — **no source-face membership and no boundary arc list**. The certificate therefore
cannot answer "which certified face contains this source triangle", which is exactly the question the seed guard's
correctness depends on. Three successive diagnostic contracts collapsed for one reason: each had to *reconstruct*
that answer from `walk.orbitByDart`, and every such reconstruction funnels through the same
"exactly-one-element-or-nothing" rule. **No Code + Build turn can read data the certificate does not publish**, so
this is a definition gap, not a further measurement gap.

---

## 1. CE0 — authority and immutability

| Check | Result |
|---|---|
| Semantic source `e12396d471c0754b112a40272a7992020ff49ced` | **PASS** — exists, ancestor of HEAD, **no code drift** |
| Selector 397 | **PASS** — `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`, **397 identities**, name and count agree |
| Immutable package | **`9921914679`**, `sha256:db346ad9…f444a4fe7` — the **same** package TB23-EXEC consumed, reused unchanged as CD0 required |
| Ledger arithmetic | **PASS** — 389 PASS + 8 RED = 397; ledger `81224170…dedef314` |
| Accepted prefix | **PASS** — ordinals **1–365 = 365/365** |
| Censuses | package, source and execution-view pre/post all **equal** |
| Prohibited operations | **PASS** — no benchmark, configure, compile, relink, discovery, package repair, mode repair or mutation |

The first caller attempt `33839600920` was a pre-job Actions startup failure from a permission ceiling and produced
no runtime; it is orchestration provenance only. The formal run `33839673886 / 100919253449` is the semantic
authority.

**The run is semantically authoritative** — CD2's precondition was satisfied before runtime, which is the property
TB23-EXEC lacked.

---

## 2. CE1 — CB26's orchestration correction is confirmed

The corrected harness (`fdc335dd…80cc16d7`) staged the execution view and verified it through the consumer's own
resolution rule, then ran. Accepted **1–365 = 365/365** — the 38 accepted-prefix failures of the invalid attempt
are gone, which is the direct confirmation that they were fixture-open failures and never semantic.

**`M3-CP4c3-TB23-REV-CAND-02` CLOSES / RUNTIME PROVED.** The first application of the new orchestration-failure
routing worked end to end: `TB (orchestration-invalid) → CB (control-plane correction) → TB (re-execute)`, with the
immutable package reused unchanged so the re-executed gate stayed comparable to its frozen plan.

`M3-CP4c3-TB23-REV-CAND-01` — the fail-open `test_data_root()` — **remains ACTIVE and unfixed**, correctly, since
CB26 was control-plane-only. It is still owned by the next source-changing CB.

---

## 3. CE2 — ordinals 393 and 397 are the new witnesses working, not product regressions

Both new REDs were introduced by CB25's own witnesses, and both fired for the reason they were written.

**Ordinal 393 — `MechanicalProjectionEvidencePublishesMinorityRowsAndFaithfulnessResidual` — RED.** It asserts a
non-zero differing count and that a certified face differs from its seed. Production reports:

```
m3Cp4c3CA3;examined=273;differing=0;witnessCount=64;truncated=true
m3Cp4c3CA2;sourceEdge=10-79;seed=3;seedRule=edgeOrbitEvidence;componentFace=10,79,151;labeledFace=10,11,79;componentCertifiedFace=unavailable;labeledCertifiedFace=3
m3Cp4c3CA2;sourceEdge=29-35;seed=1;seedRule=edgeOrbitEvidence;componentFace=28,29,35;labeledFace=29,35,91;componentCertifiedFace=unavailable;labeledCertifiedFace=1
m3Cp4c3CA4;observed=0;unavailable=191;distinct=0;multiset=;truncated=false
```

This is a **diagnostic-contract RED**, not a product regression: the production path cannot produce the evidence
the contract requires. **CA6 did exactly its job.** Ordinal 396 — the *unit* witness that the pair measurement
*can* report a non-zero differing count — **PASSES**, while ordinal 393 — the *production* witness — REDs. That
separation is precisely what CA6 was written to create, and without it this turn would have recorded a green
measurement that measures nothing, as CB24's did.

**Ordinal 397 — `UnrelatedTopologyErrorLocusRemainsByteIdenticalAfterCertificateDiagnostics` — RED.** Expected
`;sourceFace=2,4,6`, received `;sourceFace=2,4,6;cutCandidateCount=0`. **This is a real defect**: CB25's
diagnostic work appended a field to the rendered locus of an **unrelated** error. It is small and contained, but it
is exactly the class the byte-identical regression witness exists to catch, and it must be corrected rather than
absorbed by relaxing the expectation. Recorded as `M3-CP4c3-TB23-R1-REV-CAND-01`.

**CA1 and CA2 are partially discharged, and the residue matters.** CA2's independence requirement **is** met — the
two sides are filled by separate `certified_face_on_source_edge_side` calls on their own faces
(`GlobalTopologyPlan.cpp:1365–1370`), so CB24's aliasing is genuinely gone. But **CA1 is not met on the edge-side
path**: `add_direct(segment.sourceFace, thirdEdge, sideOrbit)` and the carrier-less
`add_direct(…, forwardEdge/reverseEdge, forwardOrbit/reverseOrbit)` (`:487`, `:502–503`) write
`walk.orbitByDart[dart]` — **the same quantity `edgeOrbitEvidence` records for the seed** — filtered only by
membership in `certificateFaceOrbits`. That is why every available labeled certified face **equals its seed**, and
why 393's `certifiedFaceDiffersFromSeed` expectation cannot be met.

---

## 4. CE3 — why every component-side certified face is `unavailable`

191 of 191 component faces report `unavailable`, so CA4's multiset is empty and the frozen one-versus-several
branch discriminator **did not fire**. The mechanism is static and exact.

`resolve_certificate_face_projection` assigns a face's certified owner **only when** its union-find component's
collected certified-face set has **exactly one element**
(`GlobalTopologyCertificateDiagnostics.h:134–138`); otherwise the face stays `nullopt`. Its components are built by
uniting eligible (non-trace-cut) faces across every edge **not** in `embeddedGraphSourceEdges`
(`:93–101`) — and `embeddedGraphSourceEdges` contains only **mandatory and cut** source edges (`GlobalTopologyPlan.cpp:427`).

**That barrier set is strictly weaker than the seed construction's.** `componentBarriers` is
`mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`; this projection omits `traceTouchedEdges` entirely, so it merges
*across* trace-crossed edges. Its components are therefore **at least as coarse** as the seed guard's 191-face
component, and a component that coarse collects certified faces from several regions — giving a set of size ≥ 2 and
so `nullopt` for every member.

**The projection reproduces the very collapse it was built to adjudicate**, on an even coarser partition. That is
the third consecutive contract to fail this way:

| Turn | Intended measurement | Why it reported nothing |
|---|---|---|
| CB24 | projection faithfulness residual | predicate **unsatisfiable by construction** |
| CB24 | per-side certificate faces | **aliased to the seed** |
| CB25 | certified-face ownership | edge-side path **re-derives the seed's dart orbit**; whole-face path collapses on "exactly one element" over a **coarser** partition |

`differing=0` is consequently **conditionally vacuous**: `differingPairCount` increments only when *both* sides
hold values, and essentially every uncut face is `unavailable`, so it could not have been non-zero. `examined=273`
is genuine — the loop does run, satisfying the letter of CA3 — but the differing count carries no information.

---

## 5. CE4 — the ownership question is unanswerable from the published certificate

This is the finding that ends the diagnostic sequence.

```cpp
struct SurfaceCutGraphFaceCertificate {
  std::size_t orbit = 0U;
  std::size_t boundaryWalkCount = 0U;
  std::size_t boundaryArcCount = 0U;
  bool discTopologyEstablished = false;
};
```

The certificate publishes, per certified face, **an orbit id and three counts**. It carries **no source-face
membership, no boundary arc list, and no mapping from a certified face to the region of the surface it occupies.**
`certificateFaceOrbits` — the only "certificate" content any of these diagnostics consumes — is just the *set of
those orbit ids*, used as a membership filter.

Therefore:

- **No amount of diagnostic work inside `GlobalTopologyPlan` can read certified ownership**, because the datum does
  not exist in the published contract. Every attempt must reconstruct it from the plan's own `walk.orbitByDart`,
  which is the seed quantity — and that is what has happened three times.
- **The seed guard's correctness premise is therefore unverifiable as the system currently publishes.** The guard
  requires each uncut component to have one owner; whether that is true is a statement about certified faces, and
  certified faces do not say which source faces they contain.

**This is a representation/definition gap, and it is the correct stopping boundary.** TB22-REV's prohibition —
*no further diagnostic turn on this surface* — stands and is honoured: the successor is **not** a diagnostic turn.
A Code + Build turn cannot fix this, because it would have to invent the certificate's contract, which is a
definition decision.

---

## 6. CE5 — carried surfaces, candidates and accounting

Carried REDs unchanged and independently owned: **367** co-reaches 366; **368** prescribed sphere; **369**
saturation; **370** typed error `<04>` with no locus; **374** folded-cone. **371/372/391/392 remain PASS.**
Vertex-30 and the finalize/contact fall-through remain separate. **There is still no vertex-30 discriminator.**

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / GATING / BOTH BRANCHES STILL LIVE — and now proved undecidable from published data.** CA4's multiset is empty, so neither branch fired. Owner: **`M3-CP4c-3-DEFN-R3`**, which must decide what the certificate publishes before any correction is possible. |
| `M3-CP4c3-TB23-R1-REV-CAND-01` | **NEW / ACTIVE / PRODUCT / NON-STABLE** — CB25 appended `;cutCandidateCount=0` to the rendered locus of an **unrelated** topology error, caught by ordinal 397. Must be corrected, **not** absorbed by relaxing the expectation. Owner: the DEFN's successor CB. |
| `M3-CP4c3-TB23-R1-REV-CAND-02` | **NEW / ACTIVE / DIAGNOSTIC CONTRACT / NON-STABLE** — ordinal 393 encodes an expectation the production path cannot satisfy while certified ownership is underivable. **Do not delete or weaken it**; `CF7` decides its disposition once the certificate's contract is settled. |
| `M3-CP4c3-TB22-REV-CAND-01` | **ACTIVE** — evidence integrity. CA2's aliasing is fixed; **CA1's edge-side path still re-derives the seed**, so the candidate does not close. |
| `M3-CP4c3-TB23-REV-CAND-02` | **CLOSED / RUNTIME PROVED** — the corrected harness ran and accepted returned to 365/365. |
| `M3-CP4c3-TB23-REV-CAND-01` | **ACTIVE** — `test_data_root()` still fails open; owned by the next source-changing CB. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / FORMAL ONLY** — CB21 not reverted; Parts IV/V's prohibition unlifted. **Fold into `M3-CP4c-3-DEFN-R3`**, which is the definition turn that can lift or restore it. |
| `M3-CP4c3-TB19-CAND-01`, `M3-CP4c3-TB18-REV-CAND-01`, `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact | **ACTIVE**, unchanged. |

**Accounting.** Both new REDs are on **unaccepted** ordinals, both were introduced by this checkpoint's own
diagnostic scaffolding within the same checkpoint, and neither reflects a change in product behaviour on any
accepted identity: 393 is a diagnostic-contract expectation the production path cannot meet, and 397 is a
locus-rendering defect in newly added diagnostics. Neither is a **stable** regression event under the project's
criteria. **+0 events / +0 recurrences.** Totals remain **44 events / 14 categories / 30 recurrences**;
produced-witness debt **5**; semantic M3 package count **88**. Accepted authority remains **365/365**. CP4c-3
remains **OPEN**.

### Lessons recorded

- **115.** *If three independent measurement attempts collapse the same way, stop measuring and check whether the
  datum exists.* The residual was unsatisfiable, the certificate columns were aliased, and the certified-face
  projection re-derived the seed — all because `SurfaceCutGraphFaceCertificate` publishes an orbit id and three
  counts and no source-face membership. The question was never measurable; each contract was a new way of
  reconstructing an answer the system does not record.
- **116.** *A falsifiability witness earns its keep by splitting "can" from "does".* Ordinal 396 (unit) proves the
  pair measurement *can* report a non-zero differing count; ordinal 393 (production) proves it *does not* here.
  Without that pair, `differing=0` would have been reported as a clean result, exactly as CB24's structural zero
  was. Require both a mechanism witness and a production witness.
- **117.** *A derived partition must be at least as fine as the one whose property it is testing.* The
  certified-face projection united faces across everything except mandatory and cut edges, omitting
  `traceTouchedEdges`, so its components were strictly coarser than the seed guard's — guaranteeing multi-owner
  sets and `unavailable` for every face. A projection built to adjudicate a partition must not be coarser than it.

---

## 7. CE6 — consolidation

Seventh application of the standing REVIEW-turn rule, including retrospective indexing of the **five** documents
TB23-R1's stale-evidence cleanup retired between reviews: the TB22 report (112 lines), CB25 report (115), CB26
report (111), consumed TB23 plan (200) and invalid TB23-EXEC report (100). The superseded TB23 review record is
folded by this review. Retained: the TB23-R1 report, this record, and the durable set.

---

## 8. CE7 / CE8 — frozen successor: `M3-CP4c-3-DEFN-R3`, `CF0–CF9`

**A DEFN, not a CB and not another diagnostic turn.** Under the turn workflow, **`DEFN` absorbs `REVIEW + PLAN`**,
so this turn freezes definitions, adjudicates the inherited candidates and issues its successor's measures in one
turn. It is the correct boundary because §5 proves the blocking datum is absent from a published contract, which no
implementation turn may unilaterally invent.

- **CF0** — accepted 365 untouched; selector **397** byte-frozen; **no runtime, no compile, no package**. DEFN
  freezes definitions and measures only.
- **CF1** — **decide what a certified face must publish.** State whether `SurfaceCutGraphFaceCertificate` must
  carry source-face membership, a boundary arc list, or another representation sufficient to answer *"which
  certified face contains this source triangle"* — and if it must not, state what else answers that question and
  which component owns it.
- **CF2** — **decide whether the seed guard's premise is checkable at all.** The guard requires each uncut
  component to have exactly one owner. Either define the evidence that makes that decidable, or replace the
  invariant with one that is — but **do not** weaken `UncutFaceComponentOrbitSeedNotUnique` without a stated
  replacement, per Parts IV/V.
- **CF3** — **fix the partition mismatch in the definition, not only in code.** Any certified-face projection must
  be at least as fine as the partition whose property it adjudicates; state the required barrier set explicitly so
  a successor cannot omit `traceTouchedEdges` again.
- **CF4** — **adjudicate `M3-CP4c3-TB20-REV-CAND-02`.** Parts IV and V prohibit weakening the fragment-count
  invariant, which CB21 weakened with a sound accepted-boundary proof. Either lift the prohibition with reasons —
  the invariant is false on cellular complexes containing bridges — or require restoration. This is the only turn
  type that may resolve it.
- **CF5** — carry forward, unweakened: `proves_cellularity()`, the accepted 1–365 boundary, the certified
  cellularity evidence (`V=22, E=26, F=6, componentCount=1, χ=2, residual=0`), CB21's correction, 371/372/391/392
  closure, and separate ownership of 367/368/369/370/374.
- **CF6** — record that **both branches of `M3-CP4c3-TB21-CAND-01` were never discriminated** and say precisely
  what evidence would discriminate them under CF1's decision.
- **CF7** — **disposition ordinals 393 and 397 explicitly.** 393 encodes an expectation the production path cannot
  currently satisfy: decide whether it is corrected, re-scoped, or declared non-gating **with a written rationale
  and an owning measure** — never silently deleted. 397 is a genuine defect and must be **fixed**, not relaxed.
- **CF8** — freeze the successor Code + Build's measures, including the two carried debts that belong to a
  source-changing turn: `M3-CP4c3-TB23-REV-CAND-01` (fail-open `test_data_root()`) and
  `M3-CP4c3-TB23-R1-REV-CAND-01` (the unrelated-locus regression).
- **CF9** — **prohibited:** inventing a certificate field without stating its producer and its proof obligation;
  weakening `proves_cellularity()`, the fragment-count invariant or the seed guard without a stated replacement;
  relaxing ordinal 397's expectation; deleting ordinal 393; any fixture-specific branch; any tolerance or
  float-derived topological decision; any accepted-boundary relaxation; any sphere / saturation / ordinal-370 /
  folded-cone / vertex-30 / finalize-contact work.

---

## 9. What a successor must not reopen

- **The certificate publishes no source-face membership** — only an orbit id and three counts. Certified ownership
  is not derivable inside `GlobalTopologyPlan` today, and three diagnostic contracts have already proved it.
- **Ordinals 393 and 397 are the new witnesses working**, not product regressions; 397 is nonetheless a genuine
  defect that must be fixed rather than absorbed.
- **The harness correction is confirmed** and accepted returned to 365/365; the invalid attempt's 38
  accepted-prefix failures were fixture-open failures.
- **CA2's aliasing is fixed; CA1's edge-side path still re-derives the seed.**
- **Both branches of `M3-CP4c3-TB21-CAND-01` remain live and were never discriminated.**
- Everything TB22-REV and TB21-REV settled remains settled: the mechanical complex is cellular, Part I §3 is an
  implication with a premise, and CB21 is not reverted.
- Accepted ordinals **1–365** remain the load-bearing boundary.

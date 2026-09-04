# M3 CP4c-3 TB21 — Independent Review + Plan Record

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB21-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / TB20-REV's NON-CELLULARITY CONCLUSION FALSIFIED / THE TWO TOPOLOGIES ARE A PROJECTION, NOT AN EQUIVALENCE / DECIDING ROWS EXIST BUT WERE SUMMARIZED AWAY / DIAGNOSTIC-ONLY SUCCESSOR FROZEN / NON-STABLE**

No Directional runtime, configure, compile, link, package, benchmark, or product/test/fixture/selector mutation
occurred in this turn. Measures discharged: **BX0–BX8** per
`Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md`. Successor frozen: exactly one —
**`M3-CP4c-3-CB24`** under **BY0–BY9**, diagnostic-only.

---

## 0. The correction this review owes, stated first

**`M3-CP4c-3-TB20-REV` concluded that the mechanical field-aligned network is not a cut graph of its surface. The
Euler census that review ordered proves the opposite: `V=22, E=26, F=6, componentCount=1, χ=2, residual=0`, every
face certified a disc. The actual embedded complex is cellular. That conclusion is withdrawn.**

The error was not arithmetic; it was scope. `M3_CP4c_Frozen_Definitions.md` Part I §3 states that a component
collecting several seeds means "the network is not a cut graph" — but Part I proves that for the **torus**, where
the same section independently establishes non-cellularity from `V = E = 48, χ = 0 ⇒ F = 0`. Part I's inference has
a premise, and TB20-REV applied the conclusion without carrying the premise. On a witness whose complex is
*certified cellular*, the same symptom means something different. That is precisely lesson 105 — "an architectural
theorem proved on one witness bounds its own scope" — recorded at TB20-REV and then not applied to that same
turn's own reasoning.

`M3-CP4c3-TB20-REV-CAND-01` is therefore **withdrawn**, not merely reclassified. What survives is a sharper
question, adjudicated below.

---

## 1. BX0 — authority and immutability

| Check | Result |
|---|---|
| Semantic source `fa5646106ccaa23770b84a935c6d1d6007928640` exists | **PASS** — `code: add CB23 Euler census diagnostics`, 2026-09-03 22:57:00 +0000 |
| Source is an ancestor of branch HEAD | **PASS** |
| No code drift `source..HEAD` | **PASS** — static review of the working tree is valid evidence about the package |
| Selector 391 hash `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0` | **PASS**, **391 identities** — name and count agree again, per BW6 |
| Selector 385-file (388 identities) is an exact prefix | **PASS**, prefix digest `164a8b25…6e1d0fca` |
| Accepted 365-prefix authority | **PASS** — `6b5b6555…cfc14b8a1`, unchanged |
| Appended identities | **PASS** — exactly the three CB23 witnesses, ordinals 389–391, no reordering |
| Ledger arithmetic | **PASS** — 384 PASS + 7 RED = 391 |
| Pre/post package byte+mode census | **IDENTICAL**, `e15a8aba…f80161897` |
| Execution boundary | **PASS** — no configure, compile, relink, repair, discovery, benchmark or mutation |

**Ordinal 391 is a new diagnostic RED, not an accepted-prefix regression** — accepted 1–365 remain 365/365 and the
RED set moved from eight to seven by clearing 371 and 372 and adding 391.

**No rerun is authorized by this review.**

---

## 2. BX1 — the two constructions count different objects, and are a projection, not an equivalence

This is the measure the turn turns on. Traced statically from the packaged source:

**(1) The `SurfaceCutGraph` actual-complex certificate.**
`SurfaceCutGraph.cpp:451` calls `certify_actual_embedded_graph(sourceFaces, sourceVertexCount, sourceAuthority,
network, cuts, evidence)` and accepts only when `proves_cellularity()` holds. That predicate
(`SurfaceCutGraph.cpp:478`) requires `complex == ActualEmbeddedGraph`, `faceCount > 0`,
`graphComponentCount == sourceComponentCount`, `eulerCharacteristic == sourceEulerCharacteristic`, the boundary-orbit
accounting to balance, and **every face to satisfy `proves_disc_topology()`**. Its `V`, `E`, `F` are the nodes,
arcs and face-walk orbits of the **embedded graph on the surface** — network arcs plus cut edges, with trace
subdivision. Its faces are **regions of the surface**, bounded by arcs that run through triangle interiors.

**(2) The `GlobalTopologyPlan` uncut-face component construction.**
`GlobalTopologyPlan.cpp:1102–1165` collects source faces with no `fragmentOrbits` entry, joins them across source
edges not in `componentBarriers = mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges`, and requires each resulting
component to collect exactly one seed orbit from its labeled neighbours. Its objects are **whole source
triangles**, and its adjacency relation is **source-edge membership in an edge set**.

**These are not the same object and are not required to be equivalent.** The relation is a projection: a source
triangle that carries no chord lies entirely inside one certificate face, so the component construction is a
*coarsening* of the certificate's face partition. The projection is faithful only under an additional condition
that neither construction states or checks:

> Every pair of adjacent uncut source triangles that lie in **different** certificate faces must be separated by an
> edge in `componentBarriers`.

**Cellularity does not imply that condition.** `proves_cellularity()` asserts that the complement components are
discs; it says nothing about whether an edge-based barrier set captures every arc-based separation. The two
properties are logically independent, and the certificate cannot validate the projection because it never examines
it.

So the TB21 contradiction is not a contradiction between two measurements. It is two constructions answering two
different questions, one of which — the projection's faithfulness — has never been stated as a contract, let alone
proved. **That is the real finding of this turn.**

---

## 3. BX2 — normative scope, stated precisely

Part I §3's sentence — *"The error code is correct and the producer is behaving correctly. There is no bug at that
line. It is reporting a missing input"* — is about the **actual embedded graph**, because the argument that
reaches it is the Euler computation `V − E + F = χ` over that graph. Read in place, Part I §3 asserts:

> *non-cellular actual complex* ⟹ some complement component is not a disc ⟹ a source-face component collects
> several seeds.

It does **not** assert the converse, and the converse is what TB20-REV used. On the mechanical witness the
antecedent is now measured false, so Part I §3 licenses no conclusion here at all.

**Recorded normative conflict:** none between documents. The conflict was between Part I §3 and a misreading of it.
`DESIGN.md` Amendments 13–14's later actual-complex authority is consistent with Part I once the direction of the
implication is respected: both speak about the actual complex; neither speaks about the source-face projection.

**`proves_cellularity()`, the fragment-count invariant and `UncutFaceComponentOrbitSeedNotUnique` are not weakened
by this review, and the successor does not weaken them.** What the successor does is measure the projection that
the seed guard silently depends on.

---

## 4. BX3 — the three seeds, and where the deciding rows already are

Complete and untruncated attribution over component 0's **97** boundary edges:

| Orbit | Attributed boundary edges |
|---:|---:|
| 0 | **81** |
| 1 | **1** |
| 3 | **1** |
| — | 14 barrier / no-seed |

81 + 1 + 1 + 14 = 97. The distribution is not a spread across three regions; it is **one dominant orbit and two
single-edge outliers**. Under §2's projection framing there are exactly two candidate readings, and they call for
opposite corrections:

- **(a) The projection loses a separation at two places.** Those two edges genuinely separate certificate faces,
  and `componentBarriers` does not contain them. The fix is to the barrier set — the projection's contract.
- **(b) Two seed reads are wrong.** The edges are ordinary, but the labeled neighbour's orbit was read as an orbit
  that does not face the component. The fix is to the seed rule at `:1130–1140`.

**The rows that decide this already exist in the immutable evidence.** TB20's retained first-64 window reported
44 × orbit 0, 1 × orbit 1, 1 × orbit 3; TB21's complete census reports 81 / 1 / 1. **The two minority rows are
therefore inside the retained 64-row window in both runs**, with their edge key, `otherSideLabeled`, neighbour
owner count, barrier class and contributed seed all captured. They were summarized into counts by the report and
never printed individually.

**No new measurement is required — only that the retention and projection keep the rows that differ.** That is
BY1–BY3 below, and it is why this successor is small.

**The 64/97 raw-row cap is not the blocker**, exactly as the frozen plan anticipated. Raising it would be the wrong
fix: the failure mode is that a *first-N* window is chosen by position while the question is about *distinctness*.
A window that retains the first N rows systematically preserves the majority and can drop precisely the outliers a
"not unique" failure exists to report. Recorded as lesson 106.

---

## 5. BX4 — the TB20-REV governance candidates

**`M3-CP4c3-TB20-REV-CAND-01` — WITHDRAWN.** Its load-bearing claim (non-cellularity of the mechanical actual
complex) is measured false. Superseded by `M3-CP4c3-TB21-CAND-01`, which states the surviving question correctly:
the source-face projection's faithfulness is an unstated, unchecked contract.

**`M3-CP4c3-TB20-REV-CAND-02` — DOWNGRADED to a formal-only conflict, and its substantive concern withdrawn.**
That candidate recorded that CB21 relaxed the fragment-count invariant while Parts IV and V prohibit relaxing it,
and TB20-REV argued the relaxation had *suppressed a detector of a missing input*. **That argument rested on
non-cellularity and does not survive.** On a certified cellular complex with bridges present — and TB18 measured
one directly, `arc 15` with `forwardOrbit = reverseOrbit = 0` — the equality `|owners| = k+1` is genuinely not an
invariant, so CB21 corrected a real unsoundness. TB18-REV's mathematics and its accepted-boundary proof stand
unqualified.

What remains is narrow and real: **Parts IV and V prohibit the weakening in writing, and no turn has lifted that
prohibition.** That is a documentation-authority gap, not a product defect. Owner: a DEFN turn, which should lift
the prohibition with the reason now available — the invariant is false on cellular complexes containing bridges —
rather than restore a check that TB18-REV proved unsound. **CB21 is not reverted and no successor may revert it on
this record.**

---

## 6. BX5 — the reached test-coupling surface closes

TB21 confirms ordinals **371 and 372 each selected exactly once, reached their existing assertions, and passed**:

- **371** `FieldTransportAtlas.NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` — the mechanical atlas
  publishes the non-separating barrier and excludes it from cycle-basis steps;
- **372** `FieldTransportAtlas.CutTransportDomainSatisfiesTheEulerCutIdentity` — the reported transport region
  satisfies the frozen cut-Euler identity plus its barrier-component and barrier-singularity assertions.

**`M3-CP4c3-TB10-REV-CAND-01` is CLOSED / RUNTIME PROVED.** Both contracts had been unmeasured for eleven turns
behind a shared fixture constructor; the TB20-REV authorization was test-only, assertions stayed byte-unchanged,
selector membership and ordering were unchanged, and no product semantics moved to obtain the result. **The
test-only atlas accessor does not become product authority**, and no successor may cite it as such.

---

## 7. BX6 — ordinal 391, and my own measure that caused it

391 is RED because its prescribed-sphere half requires `sphere.cutGraph`, which is `NotProductionReady` on the
already-owned **368** `CellularityNotEstablished` surface. It fails *before* its comparison print. It is a
**diagnostic dependency and co-reacher of 368**, not a new product mechanism, and it creates no new stable category
or recurrence.

**It exists because TB20-REV's BW4 required the Euler census to be carried to the torus and prescribed-sphere
paths.** That measure was written without checking that the sphere path is blocked by a known-red surface, so a
cross-witness witness inherited a known blocker and turned into a self-inflicted RED. The evidence value was
delivered anyway — 389 and 390 pass and publish the census on the mechanical path, which is what the turn needed.
Recorded as lesson 107.

**No sphere, saturation, ordinal-370, folded-cone, vertex-30 or finalize/contact change is authorized by this
review.** BY7 requires 391 to be re-scoped so the mechanical and torus halves report independently of the sphere
half, which removes the self-inflicted RED without touching the 368 surface.

---

## 8. BX7 — carried surfaces, candidates and accounting

Carried REDs, unchanged and separately owned: **367** co-reaches the mechanical seed frontier and carries the same
`22/26/6/1/2/0` census; **368** prescribed sphere; **369** saturation; **370** typed error `<04>` with no locus;
**374** folded-cone `atlasBuild=false`. **Vertex 30 is still not reached**; finalize/contact remains untouched.

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **NEW / ACTIVE / ARCHITECTURAL / GATING** — the source-face component construction is an **unvalidated projection** of the certified actual complex. Its faithfulness condition (§2) is stated by neither construction and checked by neither. Owner: BY1–BY4, then TB22-REV. |
| `M3-CP4c3-TB21-CAND-02` | **ACTIVE / DIAGNOSTIC DEPENDENCY** — ordinal 391's sphere half blocked by 368. Owner: BY7 re-scoping. Not a stable category. |
| `M3-CP4c3-TB20-REV-CAND-01` | **WITHDRAWN** — load-bearing non-cellularity claim measured false (§0). |
| `M3-CP4c3-TB20-REV-CAND-02` | **DOWNGRADED / FORMAL ONLY** — substantive concern withdrawn; documentation-authority gap remains for a DEFN turn (§5). |
| `M3-CP4c3-TB10-REV-CAND-01` | **CLOSED / RUNTIME PROVED** (§6). |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** — folded under `M3-CP4c3-TB21-CAND-01`; the guard is not relaxed. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**, unchanged; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact | **ACTIVE**, unchanged. |
| Historical torus occurrence | **Separate**, and now understood: it is the genuine non-cellular case Part I proved. |

**Accounting.** The RED set moved 8 → 7 by clearing 371/372 and adding 391; a diagnostic co-reacher of an owned
surface is not a new stable event, and clearing a test-coupling blocker is not an accepted-green change. **+0
events / +0 recurrences.** Totals remain **44 events / 14 categories / 30 recurrences**; produced-witness debt
**5**; semantic M3 package count **86**. Accepted authority remains **365/365**. CP4c-3 remains **OPEN**.

### Lessons recorded

- **106.** *Bounded evidence must be retained by distinctness, not by position.* A first-N window preserves the
  majority and can drop exactly the outliers that a "not unique" failure exists to report. Component 0's boundary
  census is 81 / 1 / 1 across three orbits; the two rows that decide the defect are single rows among 97. When
  capping evidence for a uniqueness failure, retain at least one row per distinct value **before** filling the
  remaining budget in order.
- **107.** *A cross-witness diagnostic identity inherits the blockers of every witness it spans.* Requiring one
  census witness to cover mechanical, torus and prescribed sphere turned a known-red sphere surface into a new RED
  in an otherwise clean diagnostic turn. Scope a diagnostic per witness, or make each witness's half report
  independently.
- **108.** *Carry the premise, not just the conclusion.* A frozen finding of the form "X implies Y" gets cited as
  "Y" once it is a turn or two old. TB20-REV applied Part I §3's conclusion to a witness whose antecedent it had
  not checked — and the check it ordered in the same breath disproved the antecedent. When citing a frozen
  finding, restate its premise and verify it holds for the witness in hand.

---

## 9. Mandatory review closeout — document consolidation

Fourth application of the standing rule (`CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn").
Durable facts verified present in this record, the tracker, `ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md`
before folding; anything a CB or TB turn retired between reviews is indexed retrospectively.

Folded: `Architecture_M3_CP4c3_TB20_Artifact_Only_Test_Benchmark_Report.md`,
`Architecture_M3_CP4c3_TB20_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md`, plus any CB23/TB21 per-turn document already retired.
Retained: the TB21 report, this record, `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`,
`Required_Green_Selector_Manifest.md`, the consolidated record, and every selector file. **No selector file,
normative definition, policy, lesson, stable ID, artifact identity or unresolved blocker was removed or weakened.**

---

## 10. BX8 — frozen successor: `M3-CP4c-3-CB24`, Code + Build, DIAGNOSTIC-ONLY, `BY0–BY9`

**Not a DEFN turn.** BX8 permits a DEFN only if the contradiction is a normative conflict statable precisely;
§2–§3 show it is not a normative conflict at all but an **unvalidated projection**, and the two readings of it
imply opposite corrections. **Not a product correction**, for the same reason. One indispensable relation is
absent from *reported* evidence — which of the two minority boundary edges is which — and BX3 shows it is already
captured in the artifact, so the successor is small.

- **BY0** — accepted 365 untouched; **selector 391 byte-frozen** at `f60638a5…cf6086c0` and republished unchanged;
  the eight standard compile targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **BY1** — **retain boundary rows by distinctness, not position.** Before filling the row budget in order, retain
  at least one row per distinct contributed seed orbit and at least one per distinct `noSeedReason`. Keep the
  existing cap and truncation marker. This is lesson 106 made mechanical.
- **BY2** — project the **minority-orbit rows in full**: for each seed orbit attributed by fewer rows than the
  modal orbit, publish every contributing row — edge key, `otherSideLabeled`, the labeled neighbour's face key and
  owner count, the edge's barrier class, which rule produced the seed (owner-shortcut at `:1131` versus
  `edgeOrbitEvidence` at `:1134`), and the seed value.
- **BY3** — for each such edge, publish **which certificate face each side lies in**, so reading (a) and reading
  (b) of §4 are separated by measurement rather than by argument.
- **BY4** — publish the projection's faithfulness residual: the count of adjacent uncut source-triangle pairs whose
  two sides lie in different certificate faces while their shared edge is **not** in `componentBarriers`. Zero
  means the projection is faithful and the defect is in the seed read; non-zero names the barrier set. Bounded,
  with a truncation marker.
- **BY5** — one witness per new field through the **production** path, plus a byte-identical unrelated-error
  regression witness.
- **BY6** — append the next selector **named by its resulting identity count**; 391 stays an exact prefix; no
  reordering. Regenerate `Required_Green_Selector_Manifest.md` with `tools/selector_manifest.py`.
- **BY7** — **re-scope ordinal 391** so its mechanical and torus halves assert and report independently of the
  prescribed-sphere half, and the sphere half is skipped-with-reason while 368 is open. This removes a
  self-inflicted RED. **It touches no sphere product surface and does not weaken 368's ownership.**
- **BY8** — **no product semantic change whatsoever**: `UncutFaceComponentOrbitSeedNotUnique` and its predicate,
  `componentBarriers`, the component partition, `seedOrbits`, the seed rule, `edgeOrbitEvidence`,
  `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`, the face walk, the rotation system,
  region drafts, CB21's comparison, `proves_cellularity()` and the certificate are untouched;
  `localFragmentCount` stays non-fatal. No fixture geometry mutation, tolerance, float-derived decision or
  accepted-boundary relaxation; no sphere / saturation / ordinal-370 / folded-cone / vertex-30 / finalize-contact
  product work; **no revert of CB21**.
- **BY9** — six `M3-CP4c-3-TB22` discriminators:
  1. ordinals **1–365 stay 365/365**;
  2. ordinal 366 **still** reds at `UncutFaceComponentOrbitSeedNotUnique`, component 0, `seedState=Multiple`,
     orbits `[0,1,3]`, 191 faces — any movement falsifies BY8;
  3. both **minority-orbit boundary rows are published in full**, so the two readings of §4 are separated;
  4. each minority edge's two sides are attributed to certificate faces;
  5. the projection faithfulness residual is published, **zero or non-zero decides the owner**;
  6. **391 is no longer RED**, 371/372 stay PASS, and carried surfaces 367/368/369/370/374 are unchanged.

The successor after TB22 is an independent **`M3-CP4c-3-TB22-REV`**, which owns the correction once BY4's residual
names the owner. **A DEFN turn becomes correct only if that residual is non-zero and the barrier-set contract must
be restated**; it is not scheduled in advance.

---

## 11. What a successor must not reopen

- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs. Do not
  re-derive non-cellularity from the seed error.
- **Part I §3 is an implication with a premise.** It licenses "not a cut graph" only where the complex is
  independently shown non-cellular, as on the torus. It says nothing about the source-face projection.
- **The certificate and the seed guard test different objects** (§2); neither validates the other.
- **CB21 is not reverted**, and TB20-REV's argument against it is withdrawn; only the formal Parts IV/V gap
  remains, owned by a DEFN turn.
- **371/372 are closed and their fixture accessor is test-only** — never product authority.
- **Ordinal 391's RED is a dependency on the owned 368 surface**, not a new mechanism.
- Accepted ordinals **1–365** remain the load-bearing boundary. Any change those identities exercise must
  demonstrate safety, not argue it.

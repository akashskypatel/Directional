# M3 CP4c-3 TB22 — Independent Review + Plan Record

Date: 2026-09-04 UTC
Turn: `M3-CP4c-3-TB22-REV`
Type: **independent REVIEW + PLAN — STATIC ONLY**
Status: **COMPLETE / BOTH CB24 MEASUREMENTS PROVED VACUOUS / NEITHER BRANCH ELIMINATED / NO CORRECTION AUTHORIZED / SUCCESSOR FROZEN / NON-STABLE**

No Directional runtime, configure, compile, link, package, benchmark, or product/test/fixture/selector mutation
occurred in this turn. Measures discharged: **BZ0–BZ8** per
`Architecture_M3_CP4c3_TB22_Independent_Review_Plan.md`. Successor frozen: exactly one —
**`M3-CP4c-3-CB25`** under **CA0–CA9**.

**Headline.** BZ2 instructed me not to accept a diagnostic's name as its proof. Neither CB24 diagnostic measures
what its name says. `projectionFaithfulnessResidual` is computed over a predicate that is **unsatisfiable by
construction** — it is `0` on every mesh, always. The minority rows' "certificate face" columns are **the seed
value re-printed** — the same number, computed once, displayed three times. Both branches of
`M3-CP4c3-TB21-CAND-01` therefore remain live, and no correction can be authorized.

---

## 1. BZ0 — authority and immutability

| Check | Result |
|---|---|
| Semantic source `d69729a69a40b020968ed6ef1fbc1bc788284518` exists | **PASS** — `M3-CP4c-3-CB24 publish projection diagnostics`, 2026-09-04 00:51:17 +0000 |
| Source is an ancestor of branch HEAD | **PASS** |
| No code drift `source..HEAD` | **PASS** — later orchestration/documentation commits did not alter the semantic source under review; static reading of the working tree is valid evidence about the package |
| Selector 393 hash `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d` | **PASS**, **393 identities** — name and count agree |
| Selector 391 is an exact prefix | **PASS**, prefix digest `f60638a5…cf6086c0` |
| Accepted 365-prefix authority | **PASS** — `6b5b6555…cfc14b8a1`, unchanged |
| Appended identities | **PASS** — exactly ordinals 392 and 393, no reordering |
| Ledger arithmetic | **PASS** — 387 PASS + 6 RED = 393 |
| Pre/post package byte+mode census | **IDENTICAL**, `7e0c552c…9258fa2b74` |
| Execution boundary | **PASS** — no configure, compile, relink, regeneration, repair, discovery, benchmark or mutation |

The early cleanup failure is accepted as **orchestration-only**: the package census is byte-identical across
execution and no removal or comment step touched product, test, fixture, selector or package bytes.

**No rerun is authorized by this review.**

---

## 2. BZ1 — the gate and ordinal 391

Six REDs — **366, 367, 368, 369, 370, 374** — with accepted **365/365**. Ordinals **371, 372, 391, 392 and 393**
each selected exactly once and PASS.

Ordinal **391** now executes its mechanical and torus assertions independently and reports the sphere half as
`status=SKIPPED, reason=ordinal368-open, terminalFailureCode=NotProductionReady`. The torus census is
`V=72, E=76, F=4, componentCount=1, sourceChi=0, residual=0` — and `72 − 76 + 4 = 0 = χ`, so the torus complex is
cellular once its cut edges are present, which is the cut graph doing its job.

**`M3-CP4c3-TB21-CAND-02` CLOSES / RUNTIME PROVED / NON-STABLE.** The self-inflicted RED that BW4 introduced is
gone, and BY7's re-scoping is confirmed correct. Stable accounting is unchanged.

---

## 3. BZ2 — `projectionFaithfulnessResidual = 0` proves nothing: the predicate is unsatisfiable

The residual is computed at `GlobalTopologyPlan.cpp:1362–1389`:

```cpp
for (const auto &[edge, incident] : topology.incidentFaces) {
  if (incident.size() != 2U ||
      unlabeledIndex.find(incident[0]) == unlabeledIndex.end() ||
      unlabeledIndex.find(incident[1]) == unlabeledIndex.end() ||
      certificateSeparatingSourceEdges.count(edge) == 0U ||   // (A)
      componentBarriers.count(edge) != 0U) {                  // (B)
    continue;
  }
  ++residual;
  …
}
```

**(A) and (B) cannot both hold.** Proof, entirely from committed bytes:

1. `certificateSeparatingSourceEdges` is populated at exactly one site, `:1200`, inside a loop over `arcs` whose
   guard admits only two cases (`:1191–1199`):
   - `arc.kind == Mandatory` → `sourceEdge = mandatory->sourceEdge`, where `mandatory` is found in
     `network.mandatory_edges()`;
   - `arc.kind == Cut` → `sourceEdge = arc.cutEdge`.
2. `mandatoryEdges` is populated at `:674` by iterating **the same** `network.mandatory_edges()` and inserting
   `mandatory.sourceEdge`. So every Mandatory-derived member of `certificateSeparatingSourceEdges` lies in
   `mandatoryEdges`.
3. `arc.cutEdge` is assigned at `EmbeddedGraphTopology.cpp:598–599` to the loop variable of
   `for (const auto &cutEdge : cutEdges)` (`:559`), whose argument is `cutGraph.cut_edges()`
   (`GlobalTopologyPlan.cpp:2364–2366`). `cutEdges` in `build_regions` is constructed from
   `cutGraph.cut_edges()` (`:649–650`). **Identical source.** So every Cut-derived member lies in `cutEdges`.
4. `componentBarriers = mandatoryEdges ∪ traceTouchedEdges ∪ cutEdges` (`:1114–1116`).

Therefore

> **`certificateSeparatingSourceEdges ⊆ mandatoryEdges ∪ cutEdges ⊆ componentBarriers`**

and the conjunction of (A) and (B) is empty. **The loop body is unreachable. `residual` is `0` and
`witnessCount` is `0` for every input, on every mesh, unconditionally.** `truncated=false` follows trivially.

This is a **structural zero**, not a measurement. It rules nothing out. Specifically it does **not** establish that
adjacent uncut source-triangle pairs lie in the same certificate face, because it never examines a single pair.

**Consequence for BZ5.** BZ5 forbids authorizing a barrier-set change "if BZ2 confirms faithful same-certificate
projection with residual zero." **BZ2 does not confirm it** — the antecedent fails, so that prohibition does not
bind, and the missing-barrier branch of `M3-CP4c3-TB21-CAND-01` is **not eliminated**.

---

## 4. BZ3 — the minority rows print one number three times

For edges `10-79` (seed 3) and `29-35` (seed 1), both `seedRule=edgeOrbitEvidence`, `otherSideLabeled=true`,
`labeledFaceOwnerCount=2`, `barrierClass=none`, the report shows component and labeled certificate faces `3/3` and
`1/1`. That agreement is a tautology.

**The "certificate face" is not the certificate.** `certificate_side_orbit` (`:1172–1184`) is:

```cpp
const auto exact = edgeOrbitEvidence.find(std::make_pair(face, edge));
if (exact != edgeOrbitEvidence.end() && exact->second.size() == 1U)
  return *exact->second.begin();
const auto owners = fragmentOrbits.find(face);
if (owners != fragmentOrbits.end() && owners->second.size() == 1U)
  return *owners->second.begin();
return std::nullopt;
```

Those are **the same two lookups, in the same order, that the seed rule itself uses** (`:1284–1299`). The helper
never consults `certificateSideOrbitsByEdge`, the `SurfaceCutGraph` certificate, `proves_cellularity()`, or any
certificate face. Despite its name it returns the seed.

**The component side is copied, not measured** (`:1272–1278`):

```cpp
row.labeledSideCertificateFace = certificate_side_orbit(otherFace, edge);
if (row.barrierClass == UncutFaceComponentBarrierClass::None &&
    row.labeledSideCertificateFace.has_value()) {
  row.componentSideCertificateFace = row.labeledSideCertificateFace;
}
```

So for each minority row, with `labeledFaceOwnerCount = 2` forcing the `edgeOrbitEvidence` branch throughout:

| Reported column | Actually computed as |
|---|---|
| `contributedSeed` = 3 | `edgeOrbitEvidence[(10,11,79), 10-79]`, unique |
| `labeledSideCertificateFace` = 3 | **the same lookup**, via `certificate_side_orbit` |
| `componentSideCertificateFace` = 3 | **assigned equal to the previous column** |

Three columns, one value, computed once. The table's apparent cross-confirmation carries **no information**, and
the comment asserting "both source-triangle sides lie in the same certificate face" is an **unverified claim
written as a fact** — it is the conclusion the diagnostic was supposed to test.

**There are two mechanisms in this file and both miss.** `certificateSideOrbitsByEdge` (`:1204–1212`) *is*
genuinely certificate-derived — it reads `walk.orbitByDart` for the arc on a mandatory or cut edge — but it is
consulted **only** inside the unreachable residual loop, and only for edges that carry such an arc. The rows,
which are reachable, use the seed-derived helper instead. The certificate-derived path has an empty domain; the
reachable path is circular.

---

## 5. BZ4 — the seed-selection contract, derived independently

From the frozen invariants rather than current output:

- An **uncut** source triangle carries no chord, so it lies entirely within one certificate face. Its region owner
  is that face — a well-defined, single value.
- A connected component of uncut triangles joined across non-barrier edges lies within one certificate face **iff**
  no arc separates any adjacent pair in it. That is the faithfulness premise, and it is a property of the
  **barrier set**, not of any seed.
- To attach such a component to the certified region structure it is therefore **necessary and sufficient** to
  know the certificate face of **one** of its triangles. Reading many boundary edges is redundant when the
  component is faithful, and unsound when it is not — which is exactly the situation under adjudication.
- **An edge-level face-walk orbit may legitimately differ from the certificate face of the triangle on that side.**
  `edgeOrbitEvidence` records the orbit of a *dart side of a chord in the labeled neighbour*; that is evidence
  about the labeled triangle's interior arrangement, not about which certified face the **uncut** triangle across
  the edge belongs to. Using it as the component's seed silently substitutes a neighbour-interior quantity for a
  component-ownership quantity.

**The uniqueness guard is preserved as a safety property.** Nothing derived here justifies collapsing multiple
seeds, and the `[0,1,3]` observation is fixture-specific evidence that must not drive a general rule. What the
derivation does establish is that **the current seed representation is answering a different question than the one
component ownership asks** — which is a reason to measure the right quantity, not yet a licence to change the rule.

---

## 6. BZ5 — no correction is authorized; neither branch is eliminated

| Option | Disposition |
|---|---|
| Code + Build seed-rule correction | **Not authorized.** BZ4 shows `edgeOrbitEvidence` is answering the wrong question, but "wrong representation" is not yet "demonstrably the cause here" — that requires the certificate attribution BZ3 shows was never measured. |
| **DEFN** | **Not authorized.** The frozen definitions are not ambiguous about which certified object owns an uncut component; the code simply never asks the certificate. This is a measurement defect, not a definition gap. |
| Barrier-set change | **Not authorized** — and note BZ5's guard against it does not apply, because §3 shows BZ2 confirms nothing. |

**Both branches of `M3-CP4c3-TB21-CAND-01` remain live**, exactly as they were before CB24 ran.

### My own measures are why this turn produced no discrimination

BY3 said "attribute each minority edge's two sides to certificate faces" and BY4 said "publish the projection
faithfulness residual." **Neither named its source of truth, and neither stated a falsifiability condition.** CB24
implemented fields with those names, backed by a helper that reads the seed machinery and a predicate that cannot
fire, and its own required-green witness (ordinal 393) passes because the fields are *published* — never because
they could have differed. A measure specified by output field rather than by source and by what would falsify it
is a measure that can be satisfied without measuring. Recorded as lessons 109 and 110.

---

## 7. BZ6 — unrelated REDs and debts

Unchanged and independently owned: **368** prescribed sphere `CellularityNotEstablished`; **369** saturation;
**370** typed error `<04>` with no source-face locus; **374** folded-cone `atlasBuild=false`. **367** co-reaches
366 and is **not** used to infer a broader common root — no source or evidence proof of one exists. Vertex-30 and
the finalize/contact fall-through remain separate and untouched. **There is still no vertex-30 discriminator.**

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; no
debt was independently discharged this turn. Semantic M3 package count **87**. Accepted authority **365/365**.
CP4c-3 remains **OPEN**. **+0 events / +0 recurrences.**

### Candidates

| Candidate | Transition |
|---|---|
| `M3-CP4c3-TB21-CAND-01` | **ACTIVE / GATING / BOTH BRANCHES LIVE.** CB24's evidence is vacuous (§3, §4); neither the missing-barrier nor the seed-read branch is eliminated. Owner: CA1–CA4, then TB23-REV. |
| `M3-CP4c3-TB22-REV-CAND-01` | **NEW / ACTIVE / EVIDENCE-INTEGRITY.** Two production diagnostics report values that cannot vary: `projectionFaithfulnessResidual` over an unsatisfiable predicate, and `*CertificateFace` columns aliased to the seed. Ordinal 393 pins the vacuous contract as required-green. Owner: CA1–CA3 and CA6. |
| `M3-CP4c3-TB21-CAND-02` | **CLOSED / RUNTIME PROVED** — ordinal 391 passes with the sphere half explicitly skipped. |
| `M3-CP4c3-TB20-REV-CAND-02` | **ACTIVE / FORMAL ONLY** — unchanged; CB21 not reverted; owned by a DEFN turn. |
| `M3-CP4c3-TB19-CAND-01` | **ACTIVE / SYMPTOM RECORD** under `M3-CP4c3-TB21-CAND-01`. |
| `M3-CP4c3-TB18-REV-CAND-01` | **ACTIVE / SCOPE REFUTED / DERIVATION REQUIRED**; `localFragmentCount` stays non-fatal. |
| `M3-CP4c3-TB7-CAND-02`, `M3-CP4c3-DEFN-R2-CAND-01`, `M3-CP4c3-TB6-CAND-01`, `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, finalize/contact | **ACTIVE**, unchanged. |

### Lessons recorded

- **109.** *A diagnostic measure must name its source of truth, not just its output field.* "Attribute each edge's
  sides to certificate faces" was implemented by a helper called `certificate_side_orbit` that reads
  `edgeOrbitEvidence` and `fragmentOrbits` — the seed machinery — and never touches the certificate. The field name
  matched the request; the value answered a different question. Specify **which authority** a diagnostic must read
  from, and require the witness to prove it read from there.
- **110.** *A measurement that cannot vary is not evidence — state what would falsify it.* The faithfulness
  residual quantifies over `certificateSeparatingSourceEdges ∩ complement(componentBarriers)`, and the first set
  is a subset of the second's complement's complement: the intersection is empty by construction, so the residual
  is `0` on every mesh forever. Its required-green witness passes because the field is published, not because it
  could have been non-zero. Every diagnostic contract should state the condition under which it would report a
  different value, and the witness should exercise it.
- **111.** *Two mechanisms for one quantity means the reachable one is probably the wrong one.* This file computes
  certificate side orbits twice: `certificateSideOrbitsByEdge`, genuinely derived from `walk.orbitByDart` on
  mandatory/cut arcs, and `certificate_side_orbit`, derived from the seed lookups. The genuine one is consulted
  only inside unreachable code; the circular one feeds every published row. When a value has two producers, check
  which one the shipped path actually calls.

---

## 8. BZ7 / BZ8 — closeout and the one frozen successor

Preserved by any authorized work: accepted **1–365 = 365/365**; the seed-uniqueness safety invariant;
the certified actual-complex cellularity evidence; 371/372 closure; ordinal 391's dependency decoupling; separate
ownership of 368/369/370/374. Ordinal **392's** contract is preserved. **Ordinal 393's contract is explicitly
superseded** under BZ7's escape clause, because §3–§4 prove it pins a vacuous measurement — CA6 replaces it with a
stronger, non-fixture-specific obligation.

Document consolidation ran under `CLEAN_UP_POLICY.md`, including retrospective indexing of anything the CB24/TB22
turns retired between reviews.

### `M3-CP4c-3-CB25` — Code + Build, DIAGNOSTIC-ONLY, `CA0–CA9`

- **CA0** — accepted 365 untouched; **selector 393 byte-frozen** at `ee8cc033…27644c4d`, republished unchanged;
  the eight standard compile targets with **mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **CA1** — **derive certificate face ownership from the certificate.** For a source triangle, its certified face
  must be obtained from the `SurfaceCutGraph` certificate's face structure — the same authority
  `proves_cellularity()` validates — and **not** from `edgeOrbitEvidence`, `fragmentOrbits`, `seedOrbits` or any
  seed-side lookup. Publish it as a distinctly named field; **do not reuse the name `certificate_side_orbit` for a
  seed-derived value**, and retire or rename that helper so the two cannot be confused again.
- **CA2** — **measure each minority edge's two sides independently.** Both the component-side and labeled-side
  certified faces are computed from CA1's authority. **Neither may be assigned from the other**, and the row must
  record when a side's certified face is unavailable rather than inheriting a value.
- **CA3** — **replace the faithfulness residual with a satisfiable one.** Quantify over adjacent **uncut**
  source-triangle pairs whose shared edge is **not** in `componentBarriers`, and count the pair when the two
  triangles' CA1 certified faces **differ**. Publish the examined-pair count separately from the differing-pair
  count, so a zero result is distinguishable from an empty domain.
- **CA4** — publish, for the failing component, the multiset of CA1 certified faces over its member triangles,
  bounded with a truncation marker. If the component spans several certified faces the missing-barrier branch is
  live; if it spans one, the seed-read branch is.
- **CA5** — one witness per new field through the **production** path, plus a byte-identical unrelated-error
  regression witness.
- **CA6** — **every new diagnostic must be falsifiable, and its witness must exercise the variation.** For CA3,
  include a witness whose input makes the differing-pair count **non-zero**; for CA1/CA2, a witness where the
  certified face and the seed orbit **differ**. A witness that only asserts a field is published does not satisfy
  CA6. This supersedes ordinal 393's contract.
- **CA7** — append the next selector **named by its resulting identity count**; 393 stays an exact prefix; no
  reordering; regenerate `Required_Green_Selector_Manifest.md` with `tools/selector_manifest.py`.
- **CA8** — **no product semantic change whatsoever**: the seed rule, `UncutFaceComponentOrbitSeedNotUnique` and
  its predicate, `componentBarriers`, the component partition, `seedOrbits`, `edgeOrbitEvidence`,
  `add_fragment_orbit`, the `exteriorOrbits` filter, `is_terminal_slit`, the face walk, the rotation system,
  region drafts, CB21's comparison, `proves_cellularity()` and the certificate stay untouched;
  `localFragmentCount` stays non-fatal. No barrier-set change. **No revert of CB21.** No fixture geometry
  mutation, tolerance, float-derived decision or accepted-boundary relaxation; no sphere / saturation /
  ordinal-370 / folded-cone / vertex-30 / finalize-contact product work.
- **CA9** — six `M3-CP4c-3-TB23` discriminators:
  1. ordinals **1–365 stay 365/365**;
  2. ordinal 366 **still** reds at `UncutFaceComponentOrbitSeedNotUnique`, component 0, `Multiple`, orbits
     `[0,1,3]`, 191 faces — any movement falsifies CA8;
  3. the CA3 residual publishes **both** an examined-pair count and a differing-pair count, and the examined count
     is **non-zero**;
  4. the minority rows carry **independently computed** certified faces for both sides, with the seed shown
     alongside so agreement or disagreement is visible;
  5. the failing component's certified-face multiset is published — **spanning several faces or one decides the
     owner**;
  6. carried surfaces 367/368/369/370/374 unchanged; 371/372/391/392 still PASS.

The successor after TB23 is an independent **`M3-CP4c-3-TB23-REV`**, which owns the correction once CA3/CA4 name
the live branch. **No further diagnostic turn is authorized on this surface after TB23** — CA6 exists precisely so
that this one produces a discriminating result.

---

## 9. What a successor must not reopen

- **`projectionFaithfulnessResidual = 0` is a structural zero** (§3). It never ruled anything out and must not be
  cited as evidence.
- **The minority rows' certificate-face columns are the seed value re-printed** (§4). Their agreement is a
  tautology.
- **Both branches of `M3-CP4c3-TB21-CAND-01` are live.**
- **The mechanical actual embedded complex is cellular** — `22 − 26 + 6 − 2 = 0`, all faces certified discs.
- **Part I §3 is an implication with a premise**; it says nothing about the source-face projection.
- **CB21 is not reverted**; only the formal Parts IV/V gap remains, owned by a DEFN turn.
- **371/372 and ordinal 391 are closed**; the atlas accessor is test-only and never product authority.
- Accepted ordinals **1–365** remain the load-bearing boundary. Any change those identities exercise must
  demonstrate safety, not argue it.

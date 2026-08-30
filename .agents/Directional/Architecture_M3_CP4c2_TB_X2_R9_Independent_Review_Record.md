# M3-CP4c-2 TB-X2-R9 Independent Review Record

## Status

**REVIEW COMPLETE / ORDINAL 363 IS A GENUINE PRODUCT DEFECT AND THE FIRST ONE IN THIS ARC / `R8-CAND-01` CLOSED /
`AD3` RESOLVED / CRITERION C3 GREEN / CORRECTIVE `M3-CP4c-2-CB9` AUTHORIZED UNDER AI0–AI9**

This record adjudicates `M3-CP4c-2-TB-X2-R9-EXEC` (run/job `33319911575 / 99279955697`, immutable CB8 package
`9726295440`, semantic/test source `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`, gate selector **365**). Review and
planning only: nothing executed, compiled, packaged or benchmarked, and no product, test, fixture, selector or
build-logic byte changed.

Measures issued here are **AI0–AI9**.

## 0. What this review verified independently

The working tree is **byte-identical** to the packaged semantic source R9 executed:

```
git diff --stat 05f9ef299ee54f8c9d50318fc9a37e5a5503740d HEAD -- tests/ src/ include/ benchmarks/   →  empty
```

Selector authority recomputed from committed bytes: whole-365
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, accepted-prefix 355
`e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` — both match R9 and CB7. Every claim about
mechanism below was read out of the packaged source, not inferred from the report.

---

## 1. R9 closed four long-running items. Record them before the red.

- **`M3-CP4c2-TB-X2-R8-CAND-01` — CLOSED.** Its frozen condition was *ordinals 359 and 361 both green in a run
  reaching at least 361*. R9 satisfies it exactly. **AH2 was the right correction**: rebuilding both identities on
  one production feature authority — rails, hard-feature edges, component labels, sheet labels — made the closed
  torus witness constructible, and the vacuous-rail-set diagnosis is confirmed by the fix working.
- **Measure `AD3` — RESOLVED.** Ordinal 359 `IsInvariantToSourceFaceAndEdgeEnumeration` reached and passed its
  comparison for the first time. That is the only falsifier of the rationale for consuming the raw `face.orbit`
  index in `candidate_semantic_hash`, and it holds under source face/edge reordering on a closed genus-1 witness.
  The rationale at `SurfaceCutGraph.cpp:293-297` may now be recorded as **proved by test**, citing ordinal 359.
  After three turns on a code comment, it has a falsifier that runs.
- **Criterion `C3` — GREEN.** Ordinal 362 `RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` passes. C3 had been
  deferred **seven** times; DEFN-R2 §7.3's decision to split it — torus half gated, mechanical half to CP4c-3 —
  is vindicated. Of CP4c-2's criteria, **C1, C3 and C6 are now green on the produced torus**.
- **`PR8-R044`'s fix is now proved on two witnesses.** Ordinal 360 (two-ring, bounded) and ordinal 361 (torus,
  closed genus 1) both pass, so the semantic/provenance split holds on a disc *and* a closed surface. The
  single-witness residual recorded at R7-REV §3 is discharged.

Also green: the accepted prefix **355/355** again, ordinals 356–358 again, immutable pre/postflight with every
mutation and benchmark flag false, 366 fresh processes with zero zero-selected, and selector ownership reproduced
(`219 / 30 / 75 / 41`). The three frozen non-gating diagnostics each selected exactly once — **AF6 honoured again**.

---

## 2. Ordinal 363 — the first genuine product defect in this arc

R9 stopped at ordinal 363 `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` with typed
`InvalidCutGraphBinding`. This is **not** a witness defect. The witness worked: it proved an exact trace/source-edge
crossing exists, built a cellular `SurfaceCutGraph`, and selected a cut candidate classified
`TraceInteriorCrossing`. A2a′ did its job. A2b then rejected the result.

### 2.1 The producer is correct — verified line by line

`EmbeddedGraphTopology.cpp:503-545` implements DEFN-R2 §§4.1–4.2 exactly:

```cpp
orderedPoints = { (0, node(cutEdge.first())) }
              ∪ { (crossing.parameter, crossing.node) : key.sourceEdge == cutEdge }
              ∪ { (1, node(cutEdge.second())) }
sort by exact ExactUnitParameter
for i in 1..n:  if !(p[i-1] < p[i]) or same node → InvalidCutGraphBinding    // coincident crossings rejected
                emit ArcDraft(p[i-1].node, p[i].node), kind = Cut, cutEdge = cutEdge
```

Three properties matter downstream and all three hold:

1. **Ordering is exact**, by `ExactUnitParameter` comparison — no tolerance, as Amendment 14 §3.5 requires.
2. **Coincident crossings are rejected, not merged** — DEFN-R2 §4.1's requirement, implemented.
3. **Every sub-arc runs in the canonical `cutEdge.first() → cutEdge.second()` direction**, because the points are
   sorted ascending and `ArcDraft(first, second)` stores endpoints verbatim (`:175-178`, no canonicalization or
   swap). This is the property §2.3 depends on, and it is why the corrective is small.

So a trace-crossed selected source edge owns **`n+1` collinear Cut arcs by design**. That is Amendment 14.

### 2.2 The consumer is stale

`GlobalTopologyPlan.cpp:479-516`:

```cpp
for (const auto &cutEdge : cutGraph.cut_edges()) {
  ...
  std::vector<std::size_t> arcIndices;                       // all Cut arcs carrying this cutEdge
  ...
  if (arcIndices.size() != 1U) → InvalidCutGraphBinding;     // ← the stale assumption
  const GlobalTopologyArc &arc = arcs[arcIndices.front()];
  for (faceKey : incident) {
    forward = face_orients_edge_forward(face, cutEdge);
    interiorDart = 2*arc.id.index() + (forward ? 0 : 1);
    fragmentOrbits[faceKey].insert(walk.orbitByDart[interiorDart]);
    edgeOrbitEvidence[{faceKey, cutEdge}].insert(...);
  }
}
```

The `== 1` requirement encodes **one source cut edge ⇒ one derived Cut arc**, which was true before Amendment 14
and is false after it. The block's own comment still describes cuts as *"ordinary embedded source-edge barriers"* —
whole-edge thinking — while the trace block eighteen lines below already reasons in **chords and fragments**
(`:534-537`: *"a chord … the two darts of its graph arc are the two sides … k chords produce k+1 fragments"*).

**Amendment 14 made cut arcs chord-like, and A2b's cut block still treats them as whole-edge barriers.** That is,
recognisably, the same whole-edge-versus-arrangement error that `PR8-R043` and Amendment 13 corrected one layer up.
`RP-01`, again, now at the cut/region seam.

### 2.3 Why the correction is small, and provably so

For each sub-arc, `forward` is computed from the **source edge**, not the arc — and §2.1's property 3 guarantees
every sub-arc runs in that same canonical direction. So the existing `interiorDart = 2·id + (forward ? 0 : 1)`
formula stays valid **per sub-arc, unchanged**. The correction is to run the existing body once per sub-arc instead
of once per edge.

**The fragment-count invariant survives, and here is why.** `:670-683` requires
`fragmentOrbits[face].size() == tracePieceCount[face] + 1`, counting **trace chords only** — correctly, since a cut
edge lies on a face's boundary rather than through its interior. Take source edge `e` shared by faces `A` and `B`,
crossed by one trace at interior point `p`. Promoting `e` yields sub-arcs `e₁ = (v₁ → p)` and `e₂ = (p → v₂)`. Inside
`A`, the trace chord ends at `p` on `e`, so `e₁` and `e₂` lie on **opposite sides of that chord** and therefore
border **different fragments** of `A`. `fragmentOrbits[A]` gains exactly two orbits — and `tracePieceCount[A] + 1 =
2`. The counts reconcile. The same holds for `B`, and inductively for `n` crossings on one edge.

So the sub-arcs do not over- or under-populate `fragmentOrbits`; they populate it **exactly right**, which is
precisely what one expects if Amendment 14's representation is sound. **AI2 requires this be verified at runtime on
the AG5 witness rather than taken from this argument.**

### 2.4 `edgeOrbitEvidence` needs no change, but must be checked not assumed

`edgeOrbitEvidence[{face, cutEdge}]` becomes a multi-orbit set for a crossed edge. Its only consumer,
`:719-728`, uses it as a **seeding hint** and takes a seed only when the set has exactly one element:

```cpp
if (edgeEvidence != end && edgeEvidence->second.size() == 1U) seed = *begin;
```

A multi-orbit set therefore declines to seed rather than erroring — tolerant by construction. The downstream
`UncutFaceComponentOrbitSeedNotUnique` guard still fires loudly if a component ends with no unique seed, so nothing
degrades silently here. **No change required; AI2 requires it confirmed by evidence, not by this paragraph.**

---

## 3. A second stale consumer, which EXEC did not reach — and it fails *quietly*

Fixing only §2.2 would be worse than fixing nothing there, because it converts a loud red into a silent weakening.

`GlobalTopologyPlan.cpp:1239-1242`, inside `build_region_certificate`:

```cpp
if (found->second->cutEdge.has_value()) {
  boundaryVertices.insert(found->second->cutEdge->first());
  boundaryVertices.insert(found->second->cutEdge->second());
}
```

For a **sub-arc**, this inserts the **whole source edge's two endpoints**, even when the sub-arc spans only part of
the edge and its own endpoints are a source vertex and a crossing node — or two crossing nodes, in which case it
touches **no** source vertex at all.

`boundaryVertices` is a **skip list**, not an assertion set. At `:1341-1344`:

```cpp
for (vertex : candidateVertices)
  if (meshBoundaryVertices.count(vertex) || boundaryVertices.count(vertex)) continue;   // ← skipped
  … interior-vertex ownership validation …
```

So over-inserting **suppresses** the interior-vertex ownership check for vertices that were never on this region's
boundary. There is no error, no diagnostic, and no observable symptom — just a region certificate that validated
less than it claims. Contrast §2.2, which fails loudly with a typed code and a source-edge locus.

This is exactly the failure mode this project ranks worst: **a permissive consumer of a changed representation
degrades a certificate silently, while a strict consumer of the same change fails loudly and gets fixed.** The loud
one was found in one runtime; the quiet one would have survived indefinitely.

**Correct rule:** a Cut sub-arc contributes to `boundaryVertices` exactly those source vertices that are endpoints
**of that sub-arc**. The authority for "does this node correspond to a source vertex" already exists and must be
reused rather than reinvented: `build_node_loci` produces `NodeLocus{vertex, edge}` — a node with a `vertex` locus
contributes that source vertex; a node with only an `edge` locus (a crossing node, or a mandatory-barrier terminal)
contributes none. `build_region_certificate` does not currently receive that map, so it must be threaded in from
`build_regions`, where the embedded topology is already in scope. **Do not add a second node→vertex lookup** —
`LESSONS.md` 22e and measure AC1.

---

## 4. Consumer audit — the complete set, because a partial conversion is what caused this

DEFN-R1 **AC2** and DEFN-R2 **AG1** both require *"convert every consumer in one package"*. This review therefore
enumerates every reader of `arc.cutEdge` / `cut_edges()` in the product, so CB9 cannot be partial:

| site | what it does | verdict |
|---|---|---|
| `EmbeddedGraphTopology.cpp:503-545` | emits `n+1` ordered Cut sub-arcs | **correct — the producer, leave alone** |
| `EmbeddedGraphTopology.cpp:815-828` `edge_ray_points_to_second_endpoint` | orders a Cut ray by exact `cut_node_parameter` of its **own** endpoints | **already sub-arc-correct**; CB7's AG2 generalization got this right |
| `EmbeddedGraphTopology.cpp:951`, `:1070` | edge-locus rotation, resolves `arc.cutEdge` for slot/locus matching | uses the arc's own endpoints via the above; **verify, expect no change** |
| `GlobalTopologyPlan.cpp:479-516` | one-arc-per-cut-edge binding + orbit attribution | **STALE — fails loudly** (§2.2) |
| `GlobalTopologyPlan.cpp:1239-1242` | source-endpoint insertion into `boundaryVertices` | **STALE — fails silently** (§3) |
| `GlobalTopologyPlan.cpp:702, 708, 1152-1155` | `cutEdges` as a *source-edge* barrier set for component partition / seeding | **correct** — these are edge-keyed by intent, not arc-keyed |
| `GlobalTopologyPlan.cpp:1531-1532` | plan digest consumes `arc.cutEdge` | sub-arcs share `cutEdge` but differ in `id`/`firstNode`/`secondNode`, which are also consumed; **verify no collision, expect none** |
| `RemeshPipeline.cpp:6669` | counts `cut_edges().size()` for a resource metric | **correct** — counts source edges, not arcs |

Two stale sites, one loud and one quiet. **AI1 requires this audit be re-derived by the implementer from the
packaged source and published**, not copied from this table — the point of the exercise is that the enumeration be
complete, and a copied list inherits my omissions rather than correcting them.

---

## 5. The omission was mine, and it is the same shape as the last one

DEFN-R2 §4 enumerated the Amendment 14 work as five items — crossing nodes, exact ordering, trace-arc subdivision,
the degree-four rotation, and the proposal filter — under the heading *"What must actually be built, itemized"*, and
AG1 said *"land §§4.1–4.5 as one conversion"*. **§4 did not list A2b's cut-arc binding**, even though Amendment 14
necessarily invalidates it, and even though AG1's own sentence — "a partial conversion is the defect this checkpoint
is correcting" — was aimed at exactly this risk.

CB7 and CB8 implemented §§4.1–4.5 correctly and completely. The gap was in the itemization, not the execution.

This is the second consecutive turn where an *enumeration inside a measure* was read as exhaustive when it was
illustrative — R8-REV owned the same failure for AF3, recorded as `LESSONS.md` 59. The strengthened rule is
recorded as **`LESSONS.md` 61**: when a measure says "convert every consumer", the measure must **contain the
enumeration**, produced by search over the codebase, or explicitly say that the implementer must produce and publish
it. A numbered list adjacent to the words "every consumer" reads as that enumeration whether or not it was meant to
be, and the reader is not wrong to read it that way.

**AI1 is written to be self-correcting for exactly this reason:** it requires the implementer to produce the audit
by search and publish it, rather than to trust §4 of this record.

---

## 6. Test-helper hygiene — lesson 60, second instance

`tests/FieldAlignedCurveNetworkTests.cpp:1702-1714` `build_topology_plan` does:

```cpp
EXPECT_TRUE(built) << global_topology_plan_error_code_name(built.error().code);   // non-fatal, prints the code
return built.value();                                                            // throws std::get on failure
```

The typed code **was** printed — that is the AF0/AH5 discipline working, and it is why R9's localization was
possible at all. But the unconditional `built.value()` then throws `std::get: wrong index for variant`, which EXEC
correctly identified as secondary fallout. `LESSONS.md` 60 named this pattern one turn ago in a different helper: a
helper that cannot use `ASSERT_*` must not proceed as though it succeeded. **AI5** converts these helpers; it is
small, and it stops the next red arriving wrapped in an exception that looks like a crash.

---

## 7. What remains unmeasured

Ordinals **364** (`CutCrossingNodeRotationIsDerivedAtDegreeFour`) and **365**
(`CutSetSaturationProvesCellularityWhenSearchIsExhausted`) were **NOT RUN**. So:

- the **degree-four two-Cut/two-Trace edge-locus rotation** — the single genuine code gap DEFN-R2 identified — is
  still unexecuted, for the third turn running. §2.1 and §4 give strong static reason to believe CB7's
  generalization is right; that is not evidence.
- the **saturation last resort** is unexecuted, so `saturationUsed`, `saturationLocus` and
  `saturationPromotedEdgeCount` have never been observed.
- **`AH6` remains not-applicable** and carries forward unchanged: it can only be adjudicated when 363–365 all run.

Ordinal 363 *did* reach and pass its `SurfaceCutGraph` stage before A2b rejected the plan, so Amendment 14's
**producer** side — crossing insertion, exact ordering, `TraceInteriorCrossing` selection, and a cellular
certificate — is runtime-proved. Only the A2b consumer side is outstanding.

The prescribed sphere's non-gating publisher is still red with
`originatingTopologyError=RotationSystemInconsistent`. `M3-CP4c2-TB-X2-CAND-04` is unchanged in substance and
ownership, and remains outside the gate by recorded decision.

---

## 8. Measures **AI0–AI9** for `M3-CP4c-2-CB9`

The next turn is **`M3-CP4c-2-CB9`**, a Code + Build correcting **A2b's two stale cut-arc consumers**, plus small
test-helper hygiene. It is a **product** change — the first authorized in this arc since CB7 — and it is bounded.

**AI0 — preconditions and frozen authority.** Gate authority remains selector **365**, whole-file
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. Recompute it and the 355/357/361 prefixes from
committed bytes at authoring and preflight; validate each as exactly 64 lowercase hex; **no selector byte may
change**. Accepted runtime predecessor remains 355/355. Compile under `GMP_COMPILE_POLICY.md` with GMP/GMPXX,
`runtimeExecution=false`. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

**AI1 — produce and publish the consumer audit yourself; do not copy §4.** Before writing code, search the packaged
source for every reader of `arc.cutEdge`, `GlobalTopologyArcKind::Cut`, and `cutGraph.cut_edges()`, and publish the
complete list in the CB report with a per-site verdict: *edge-keyed by intent (correct)*, *arc-keyed and already
sub-arc-correct*, or *arc-keyed and stale*. §4 of this record is a cross-check to compare against **after** you have
produced your own, and any site in one list and not the other must be explained. This measure exists because §5's
omission is the direct cause of this red.

**AI2 — convert `GlobalTopologyPlan.cpp:479-516` to the arrangement model.** Iterate **all** Cut arcs carrying each
`cutEdge` rather than requiring exactly one; run the existing per-face body once per sub-arc. The
`face_orients_edge_forward` + `interiorDart = 2·id + (forward ? 0 : 1)` formula stays valid per sub-arc **because**
every sub-arc is emitted in the canonical `cutEdge.first() → cutEdge.second()` direction (`EmbeddedGraphTopology.cpp:531-544`,
sorted ascending, `ArcDraft` stores endpoints verbatim) — **state that dependency explicitly in the code comment**,
so a future change to the emission order cannot silently invalidate the dart formula.
Keep the `incident->second.size() != 2U` guard: a cut edge still must have exactly two incident faces.
Retain a typed failure for the genuinely invalid case — **zero** Cut arcs for a listed cut edge is still
`InvalidCutGraphBinding` — and replace the block's stale *"ordinary embedded source-edge barriers"* comment with
one that says cut arcs are chords of the arrangement, like trace arcs.
Publish, per witness, `fragmentOrbits[face].size()` against `tracePieceCount[face] + 1` and the per-(face, cutEdge)
`edgeOrbitEvidence` cardinalities, so §2.3's reconciliation argument and §2.4's tolerance are **verified by
evidence, not adopted from this record**.

**AI3 — fix the silent one at `GlobalTopologyPlan.cpp:1239-1242`.** A Cut sub-arc contributes to `boundaryVertices`
only the source vertices that are endpoints **of that sub-arc**. Resolve node → source vertex through
`build_node_loci`'s existing `NodeLocus{vertex, edge}`, threaded into `build_region_certificate` from
`build_regions`; a node with only an `edge` locus contributes nothing. **Do not add a second node→vertex lookup.**
Because `boundaryVertices` is a skip list, this change **tightens** a check that has been loose — so expect the
possibility of a new, legitimate red elsewhere, and treat such a red as a finding rather than as a regression from
this measure.

**AI4 — record the three closures with their evidence.** `M3-CP4c2-TB-X2-R8-CAND-01` **CLOSED** (359 and 361 green
in a run reaching 361). Measure **`AD3` RESOLVED** — annotate the rationale comment at `SurfaceCutGraph.cpp:293-297`
with "proved by ordinal 359" so the next reader finds the falsifier next to the claim. Criterion **C3 GREEN** at
ordinal 362. `PR8-R044`'s two-witness residual **discharged** by 360 and 361.

**AI5 — test-helper hygiene (`LESSONS.md` 60, second instance).** Convert `build_topology_plan` and
`build_surface_cut_graph` (`tests/FieldAlignedCurveNetworkTests.cpp:~1690-1714`) so a failed build does not fall
through to `built.value()`. Keep the typed-code printing — it worked. This is test-side only and changes no gated
assertion's meaning.

**AI6 — carry `AH6` forward unchanged.** When ordinals 363–365 all run, publish whether the AG5 witness's
trace-crossed edges were selected by the ordinary tree–cotree proposal or only after `saturationUsed` became true.
If only under saturation, Amendment 14's primary selection path is ungated and a second witness is owed. Do not
pre-emptively add that witness in CB9.

**AI7 — the bounded widening rule.** If AI1's audit finds a stale site outside §4's table, fix it **in the same
package** — that is AC2/AG1's whole point and the reason this red exists. If it finds a stale site that requires a
representation change rather than a per-arc loop, **stop and return to definition** rather than improvising:
Amendment 14 is frozen, and a consumer that cannot be converted by iteration is evidence the amendment needs a
DEFN revision, not a workaround.

**AI8 — what CB9 must not absorb.** No fix for the sphere's `RotationSystemInconsistent`. No new gate identity, no
selector byte, no change to any error enum value or to `topology_error`'s mapping. No change to
`EmbeddedGraphTopology.cpp`'s crossing emission (§2.1 verifies it correct; changing it would invalidate AI2's
canonical-direction dependency). No relaxation of `proves_cellularity()`, of the fragment-count invariant, or of
`UncutFaceComponentOrbitSeedNotUnique`. No benchmark, no gate execution, no `gate_execution_authorized=true`.

**AI9 — bookkeeping.** Open `M3-CP4c2-TB-X2-R9-CAND-01` as adjudicated here, with closure condition *ordinals 363,
364 and 365 all green in a run reaching 365*. Close `R8-CAND-01`. Record `AD3` and C3. `CAND-04` unchanged.
**Stable totals are unchanged at 44 / 14 / 30**, debt **5**, M3 packages **66**: ordinal 363 is a newly gated
identity that has never been accepted, and the inherited 355 is green in this very run, so no accepted-green
behaviour was lost. The TB after CB9 re-runs gate 365 **from ordinal 1** and still honours the frozen non-gating
selector.

---

## 9. Stable accounting

Unchanged: **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3 packages
**66**. **+0 events / +0 recurrences.**

Noted for the record, since it bears on how this red should be read: ordinal 363 is a **product** defect, unlike
R8's ordinal 359 which was a witness defect. It is non-stable only because CP4c-2 has never been runtime-accepted.
Had A2a′'s crossing subdivision landed in an accepted checkpoint, this would have been a stable event.

## 10. Exact next turn

**`M3-CP4c-2-CB9`** — Code + Build under **AI0–AI9**, converting A2b's two stale cut-arc consumers plus test-helper
hygiene. **AI1 runs first and requires no build.** Its successor is a fresh artifact-only TB executing gate 365 from
ordinal 1.

CP4c-2 remains **open and runtime-unaccepted**. CP4c-3 remains blocked.

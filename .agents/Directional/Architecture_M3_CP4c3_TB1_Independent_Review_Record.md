# M3-CP4c-3 TB1 Phase-1 Independent Review Record

## Status

**REVIEW COMPLETE / TB1 EXECUTION VALID / MECHANICAL CAUSE ESTABLISHED / SPHERE CAUSE IS ONE LEVEL SHORT /
PHASE 2 AUTHORIZED FOR THE MECHANICAL WITNESS ONLY, UNDER AL0–AL9**

This record adjudicates `M3-CP4c-3-TB1` (run/job `33340448381 / 99335020672`, immutable CB1 package `9739919234`,
semantic source `48dd011c4aa689a245b74527ed9df0900ada9bf3`, frozen gate selector **367**). Review and planning only:
nothing executed, compiled, packaged or benchmarked, and no product, test, fixture, selector or build-logic byte
changed.

Measures issued here are **AL0–AL9**.

---

## 0. What this review verified independently

The working tree is **byte-identical** to the packaged semantic source TB1 executed:

```
git diff --stat 48dd011c4aa689a245b74527ed9df0900ada9bf3 HEAD -- tests/ src/ include/   →  empty
```

so every source claim below describes exactly what ran. Selector 367 and all four of its prefixes were recomputed
from committed bytes and match the DEFN freeze and TB1's preflight.

## 1. TB1 execution validity — ACCEPTED

Immutable package consumed directly; preflight and postflight both PASS; `packageImmutable=true`,
`sourceImmutable=true`, `zeroSelected=0`; `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`,
`benchmarkExecution` and `mutationOccurred` all false; one identity per fresh process from ordinal 1 with a
first-red hard stop. The **accepted 365 prefix is re-proved green on package 68**, so CP4c-2's closure is
undisturbed by CP4c-3's instrumentation.

The single escaping C++ exception at ordinal 366 is correctly classified as semantic evidence rather than
orchestration failure: it is the test body's own failure carrying the AK1/AK2 diagnostic. The three pre-runtime
control failures executed no Directional process and are correctly closed as orchestration-only. One of them —
"packaged-source archive SHA-256 transcribed as a malformed 63-hex value" — is the **third** occurrence of the
`R7-ORCH-01` defect that `LESSONS.md` 22n and measure AE4 exist to prevent; §7's AL9 addresses it.

**TB1 is a valid semantic red at ordinal 366.**

## 2. CB1 delivered AK1–AK3 as specified

Audited at source:

- **AK1** added `IncompleteCycleBasisReason` — an **enumerated reason** with eight values, *not* line numbers, which
  is what the measure required and what `LESSONS.md` 62's stale `419/437/474` labels are the counter-example to. It
  is populated at all eight sites (`:1668, :1686, :1748, :1759, :1767, :1781, :1834, :1903`) and is **additive**: no
  mapping changed, no enum value was renumbered, no new `FieldAtlasBuildErrorCode` was introduced.
- **AK2** publishes the full per-region row, including every count the check compares.
- **AK3** extended the same pattern to the rotation-system collapse, resolving nine sites to one reason.

The measures were followed exactly. What follows is about what the measurements *mean*, not about their delivery.

---

## 3. The mechanical witness — cause ESTABLISHED, and it is an architectural disagreement

Measured: `IncompleteCycleBasis → CycleTransportAdjacencyMissing`, region `0`, source edge `0-3`,
`fieldTransportAdjacencyExists=false`, `globalEF=1,158`, `localEF=1,158`, local boundary edges `0`, and the sole
region row `V/E/F = 152/450/300, χ=2, boundaryLoops=0, genus=0, interiorLocalVertices=152, expectedCycles=152,
cycleRows=152, cycleCurvatures=152, innerAdjacencies=450`.

### 3.1 Edge `0-3` is a `HardFeature` barrier — by elimination, not by guess

`FieldTransportAtlas::make`'s adjacency loop routes every source edge into exactly one of four buckets, and three
of them are excluded by the measurement:

| classification | condition | excluded because |
|---|---|---|
| `SourceBoundary` | `secondRaw < 0` | `globalEF=1,158` — the edge has **two** incident faces |
| `NonTraversable` | `rowRegions[first] != rowRegions[second]` or components differ | region count is **1** over all 300 faces, so both incidences are region 0 and share a component (region flood-fill requires it) |
| `adjacencies` | otherwise | measured `fieldTransportAdjacencyExists=false` |
| **`HardFeature`** | `hardFeatureEdges.count(edge) != 0` | **the only remaining bucket** |

The loop iterates every row of `mesh.EV`, so the edge was certainly classified. **Edge `0-3` is a hard-feature
barrier**, and the atlas deliberately did not create an adjacency for it. Nothing is missing by accident.

### 3.2 Why it is nevertheless in the cycle basis

`build_source_topology_regions` (`src/geometry/SurfaceCellTracing.cpp:6655-6737`) builds the face-adjacency graph
and **skips** any edge in `options.hardFeatureEdges`, so regions are flood-filled without crossing hard features.
But skipping an adjacency **disconnects nothing** unless the removed edges actually separate the graph. Here they
did not: region 0 is all 300 faces with `boundaryLoops=0`.

`make_local_region_mesh` (`src/authority/FieldTransportAtlas.cpp:850-895`) then builds the local mesh from the
region's faces plus all their vertices. Because both incident faces of edge `0-3` are in region 0, the edge is an
**interior** edge of the local mesh — confirmed by `localEF=1,158` and local boundary edges `0`. So
`PCFaceTangentBundle` includes it among the 450 inner adjacencies, the cycle basis spans it, and the transport walk
asks `find_adjacency_in(adjacencies, edge)` for an adjacency that by design does not exist.

**The region decomposition and the traversability classification disagree about the same edge.** A2's cycle-basis
machinery assumes region boundaries and non-traversable edges coincide. That assumption is true for source
boundaries and for *separating* feature curves, and false for features that do not separate.

### 3.3 Why the torus succeeds and the mechanical does not — and why this is forced, not incidental

The torus carries 48 hard-feature edges and builds its atlas fine. The difference is separation, and it is provable
rather than observed:

- The torus's 48 hard-feature edges form four closed loops that **do** separate it into four annuli. Each region's
  hard-feature edges therefore lie on that region's **boundary**, are not inner edges of its local mesh, and never
  enter its cycle basis. No adjacency is ever demanded for them.
- Region 0 of the mechanical witness has `χ=2`, `genus=0` and `boundaryLoops=0` — it is a **sphere**. **Every closed
  curve on a sphere separates it.** Since the hard-feature edges demonstrably did *not* separate (one region, no
  boundary loops), they cannot consist only of closed curves: **the mechanical witness's feature set necessarily
  contains at least one open arc.**

That last step is a topological argument, not a measurement, and it means the case is not exotic: **the first
witness with an open feature arc was always going to hit this.** The mechanical feature witness is named for exactly
that property, and `ROADMAP.md`'s framing of CP4c-3 as "the closed-surface missing field-transport adjacency in A1"
was pointing at this site all along — now confirmed at ordinal 366 rather than assumed.

### 3.4 What the fix must decide, with costs

This is a **definition** question, not only an implementation one, because it changes what a topology region is when
a feature does not separate.

| option | what it does | cost |
|---|---|---|
| **A — cut the local region mesh along non-separating barrier edges** so the arc becomes real boundary | the region becomes a disc-with-slit; `isBoundaryVertex`, `boundaryLoops`, `χ` and `expectedCycleCount` all become self-consistent, and barrier edges leave the inner set | requires duplicating vertices along the slit and handling the arc's **endpoints**, where the cut surface touches itself. Non-trivial but local to `make_local_region_mesh` |
| **B — build the cycle basis over the traversable sub-complex only** | exclude barrier edges from `innerAdjacencies` before the basis is built | `PCFaceTangentBundle::init` takes a mesh, not a barrier set, so this means constructing the cut mesh anyway — it converges on A |
| **C — give barrier edges a transport adjacency** | makes the walk succeed | **PROHIBITED.** It destroys the barrier semantics that hard features exist to express, and would silently let transport cross a feature |
| **D — fail closed with a precise typed error** | keep the current behaviour, but name it: "a non-separating barrier edge remains interior to its region" | not a fix; but it is the correct *interim* if A proves larger than CP4c-3 |

**Recommendation: A**, with **D as the frozen fallback** if A cannot be delivered within CP4c-3. Do not take C.
The decision belongs to a DEFN — see §6.

---

## 4. The prescribed sphere — the measurement is one level short

Measured: `CellularityNotEstablished → RotationSystemInconsistent → TraceEventPositionInvalid`, with source topology
available (1 region), atlas available, network available at 24 traces / 56 events, 10 terminal trace intersections,
furthest stage `field-aligned-network`.

AK3 did what it was asked and collapsed nine sites to one reason. **But `TraceEventPositionInvalid` is itself a
two-way collapse**, and the two ways need opposite fixes.

`trace_event_position` (`src/geometry/EmbeddedGraphTopology.cpp:138-173`) resolves an event to a segment position
by matching its `sourceEdge` against segment carriers, then:

```cpp
if (positions.size() != 1U) return std::nullopt;   // ← both failures land here
```

- **`positions.empty()`** — the event's source edge is not a carrier of any segment of this trace. That is a
  network/event **binding** defect: the event does not belong to the trace it claims, or its `sourceEdge` is wrong.
- **`positions.size() > 1`** — the event's source edge is a carrier at **more than one** position on the same trace.
  That is an **ambiguity**: the position simply is not determined by `sourceEdge` alone.

There is also a two-pass structure worth naming, because it can *manufacture* the second case. The first pass
restricts to segments whose `sourceFace == event.sourceFace`; only if that finds nothing does a fallback pass run
over all segments **ignoring the face**. A widening fallback that runs after a precise pass found nothing can turn
"no match in the right face" into "several matches across the trace" — so an `empty` first pass can be reported as
an `ambiguous` failure.

**Why ambiguity is the live suspicion, stated as a suspicion.** The sphere is the trace-dense witness: 24 traces,
56 events, 10 terminal trace intersections, and `ORIENTATION.md` §10 records that six directed trace ends "once
circulated forever". A trace that crosses the same source edge twice yields exactly `positions.size() == 2`. That is
a hypothesis, **not a finding**, and it is not promoted here — the R2 discipline, and the reason this checkpoint has
moved quickly for four turns.

**The fixes diverge completely.** If empty: repair the event/trace binding upstream in A2a. If ambiguous: the
position needs a stronger key than `sourceEdge` — and CP4c-2 established that the exact crossing point is already
published, as `segment.entryPoint` / `edgeTransitExit` (`FieldBoundaryPoint`), so the discriminator exists and costs
nothing to consult. Choosing between those without the measurement is the mistake that cost eight turns at this
same witness.

**This is `LESSONS.md` 57 for the third time in this project, one level deeper each time.** `topology_error`
collapsed 36 codes; AF0 resolved it to `RotationSystemInconsistent`. Nine sites shared that name; AK3 resolved it to
`TraceEventPositionInvalid`. That name covers two conditions. Each layer was worth resolving, and the pattern is now
predictable enough to state as a rule: **when instrumenting a collapsed error, check whether the reason you are
adding is itself a collapse before declaring the layer done.** Recorded as `LESSONS.md` **64**.

---

## 5. Do the two causes share a locus? No — and that unblocks parallel work

The DEFN left phase-2 ordering open precisely because the causes might share a locus, as the torus and sphere once
did. They do not:

| | mechanical | sphere |
|---|---|---|
| stage | **A1** `FieldTransportAtlas` | **A2a′** `SurfaceCutGraph` via `EmbeddedGraphTopology` |
| file | `src/authority/FieldTransportAtlas.cpp` | `src/geometry/EmbeddedGraphTopology.cpp` |
| function | cycle-basis construction over a region's local mesh | `trace_event_position` / `build_arcs` |
| datum | a barrier edge that stayed interior to its region | an event position that is not uniquely determined |

No shared code, no shared datum, no ordering dependency. **They may be worked independently**, and the mechanical
one is ready now while the sphere one is not.

---

## 6. Disposition — phase 2 opens for the mechanical witness only

**Phase 2 is authorized for the mechanical witness**, because §3 establishes its cause by elimination plus a
topological argument that needs no further measurement, and because the corrective options and their costs are
enumerable now (§3.4).

**Phase 2 is NOT authorized for the sphere.** Its cause is one resolution short, and the two candidate causes need
opposite fixes. **AL3** closes that gap with the same additive-provenance pattern that has now worked three times;
it is one enumerated value and costs a single CB.

**A DEFN revision is required before the mechanical fix lands**, because option A changes what a topology region is
when a feature does not separate — a normative question that `DESIGN.md` §7.2/§7.2.1 owns and that a CB may not
settle by implementation. Under the standing cadence that DEFN is also its own review turn. **AL2** scopes it.

**Nothing in TB1 disturbs CP4c-2.** The accepted 365 prefix is green on package 68, the torus still publishes
`cutEdgeCount=28`, actual graph `V/E/F = 72/76/4` and four χ=1 regions, and selector 367 is byte-identical to its
freeze. Gate 367 stays frozen; `gate_execution_authorized=false`.

---

## 7. Measures **AL0–AL9**

The next turn is **`M3-CP4c-3-DEFN-R1`**, a combined definition + review turn under the standing cadence, followed
by `M3-CP4c-3-CB2`.

**AL0 — preconditions and frozen authority.** Accepted runtime predecessor remains CP4c-2 at **365/365**, source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`. CP4c-3's gate is **367**, whole-file
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; recompute it and all four prefixes from
committed bytes at authoring and preflight, validate each as exactly 64 lowercase hex, never transcribe. No existing
selector byte may change. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

**AL1 — publish the mechanical feature set, and confirm the elimination.** §3.1 concludes edge `0-3` is a
`HardFeature` by elimination. Confirm it directly by publishing, for the mechanical witness: the hard-feature edge
count, whether edge `0-3` is a member, and the connected-arc decomposition of the feature set (how many components,
how many are closed loops, how many are open arcs, and each arc's endpoint vertices). §3.3 proves at least one open
arc must exist on a `χ=2` region; this measures how many and where. Cheap, and it sizes option A directly.

**AL2 — the DEFN revision.** `M3-CP4c-3-DEFN-R1` must settle, normatively:
1. what a topology region **is** when a barrier does not separate — option A (cut the local mesh along the arc so it
   becomes boundary) versus option D (fail closed with a precise typed error), with **C explicitly prohibited**;
2. if A: the exact treatment of an **open arc's endpoints**, where the cut surface touches itself — this is the hard
   part and it must be written down with its derivation, not left to the implementation, exactly as DEFN-R1 §5
   required for the boundary-orbit and disconnected-graph conventions;
3. whether the resulting `χ`, `boundaryLoops` and `expectedCycleCount` remain consistent for a slit region, shown
   rather than asserted;
4. recorded as an amendment in `DESIGN.md` §7.2.1 alongside 12, 13 and 14, since those are where the durable record
   of such decisions now lives.

**AL3 — resolve `TraceEventPositionInvalid` one level further.** Add an enumerated sub-reason distinguishing
`NoCarrierMatch` (`positions.empty()`) from `AmbiguousCarrierMatch` (`positions.size() > 1`), and publish, for the
sphere, the trace id, the event id, the event's `sourceEdge` and `sourceFace`, and — in the ambiguous case — **every
candidate position** with the segment index and carrier that produced it. Additive only: no change to
`trace_event_position`'s return contract, no re-mapping, no enum renumbering. Also publish **which pass** produced
the result, since the face-restricted pass and the widening fallback can report different failures for the same
event (§4).

**AL4 — do not design the sphere's fix until AL3 reports.** The two candidate causes need opposite corrections and
the evidence does not yet choose. A fix whose report cannot name the measured sub-reason is not authorized. This is
the same rule as AK6 and it is restated because the temptation is strongest when a plausible mechanism is already in
view.

**AL5 — the mechanical fix, phase 2.** Implement AL2's decision. If option A: the corrective is local to
`make_local_region_mesh` and its callers' expectations; state in the CB report which of §3.4's options was taken and
why. If option D: add a **new, appended** `IncompleteCycleBasisReason` (or a distinct error code) that names the
condition precisely — "non-separating barrier edge remains interior to its region" — and record explicitly that
CP4c-3 cannot then close on criterion **C2**, so the checkpoint's gate expectations must be revisited before any TB.

**AL6 — carry the untouched inherited items.** `R10-CAND-01` (AK4, per-face-chord proposal heuristic) and
`R8-CAND-02` (AK5, typed empty-network rejection) are unchanged by TB1 and remain phase-2 work. Neither shares a
locus with §3 or §4, so neither blocks nor is blocked. Their measures stand as written in the DEFN.

**AL7 — AK7's append still stands.** The three identities named in the DEFN §6.2 —
`PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`,
`OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`, `EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError` —
are appended to selector 367 producing gate **370**, with all five earlier prefixes re-verified. Omission requires a
written rationale.

**AL8 — orchestration hygiene, third occurrence.** TB1's third rejected control transcribed a packaged-source
SHA-256 as a **malformed 63-hex value** — the identical defect as `R7-ORCH-01`, which `LESSONS.md` 22n and measure
**AE4** were written to prevent, and which cost a whole turn once already. AE4's rule is that every expected digest
is validated as exactly 64 lowercase hex **at authoring time**. Add that validation to the orchestration payload
authoring path itself, so the check runs where the value is written rather than depending on an author remembering
it. A rule that has now failed to prevent its own defect twice needs a mechanism, not another reminder.

**AL9 — prohibited.** Giving a barrier edge a transport adjacency (§3.4 option C). Designing the sphere's fix before
AL3 reports. Renumbering or removing any existing error-enum value, or changing any existing mapping — new reasons
and codes are appended only. Reopening Amendments 12, 13 or 14. Changing accepted selector 365's bytes, or 357 /
358 / 361, or 367 other than by AL7's append. Weakening `proves_cellularity()`, the fragment-count invariant, or
`UncutFaceComponentOrbitSeedNotUnique`. Introducing any tolerance into a topological decision. Removing CP4c-2's or
CB1's diagnostic surface. Compiling, packaging, executing runtime, running a gate or benchmarking in a DEFN turn.

---

## 8. Accounting

Unchanged: **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3 packages
**68**. Ordinal 366 belongs to a gate that has never been accepted, and the accepted 365 prefix is green in this
very run, so no accepted-green behaviour was lost: **+0 events / +0 recurrences**.

Tracker dispositions this review sets:

- `M3-CP4c3-DEFN-CAND-01` — **CAUSE ESTABLISHED** (§3): a non-separating hard-feature edge remains interior to its
  topology region, so the cycle basis spans an edge the atlas deliberately gave no adjacency. Closes on ordinal 366
  green in a run reaching at least 366.
- `M3-CP4c2-TB-X2-CAND-04` — **ACTIVE / ONE LEVEL SHORT** (§4): localized to `TraceEventPositionInvalid`, which is
  itself a two-way collapse. AL3 owns the next resolution; AL4 forbids designing across it.
- `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02` — unchanged, phase-2, no shared locus.
- `M3-CP4c3-TB1-ORCH-01` — closed, but its third instance is escalated to a mechanism by **AL8**.

## 9. Exact next turn

**`M3-CP4c-3-DEFN-R1`** — combined definition and review under the standing cadence, settling AL2's normative
question, then **`M3-CP4c-3-CB2`** under AL3 and AL5.

CP4c-2 remains **CLOSED / ACCEPTED at 365/365**. CP4c-3 is **open**; gate **367** stays frozen and unselected.

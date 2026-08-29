# M3-CP4c-2 DEFN-R2 — Frozen Definitions: trace-crossed cut admissibility, and CP4c-2 gate membership

## 0. Turn type and verdict

`M3-CP4c-2-DEFN-R2` is **COMPLETE / DEFINITION AND PLANNING ONLY**.

No Directional runtime, build, compile, package, benchmark, product, test, or fixture change was made or is
authorized by this turn. One **selector authority file was created**, which is this turn type's proper output and
was explicitly deferred to it by measure **AF5**; no existing selector byte was modified.

This document supersedes `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` **§6 case 2** and **§8** only.
Everything else in DEFN-R1 — Amendment 13, §§4, 5, 7, 9 — **stands unchanged and remains binding**, as does
Amendment 12.

**Two decisions.**

1. **Amendment 14.** A source edge crossed by a trace at an interior point **is an admissible cut.** DEFN-R1 §6
   case 2 excluded it on the ground that promoting it would subdivide an immutable trace. That ground is
   **factually wrong about the product**: the producer already subdivides every trace into one arc per event, and
   already subdivides a mandatory source edge at a trace terminal. Arcs are a derived representation; the
   `FieldAlignedCurveNetwork` is untouched either way. With the exclusion removed, **cut-set completeness is
   proved outright** (§5) and DEFN-R1 §8.2's open case closes.
2. **AF5 gate membership is resolved per identity** (§7). Candidate **357 is superseded** and candidate **358 is
   withdrawn**; the CP4c-2 required-green gate is the newly frozen **selector 361**, whose 355- and 357-prefixes
   are byte-identical to the accepted and previously frozen authorities.

Measures issued here are **AG0–AG9**.

---

## 1. Why DEFN-R1 §8.2 is live, stated exactly

DEFN-R1 §8.3 made the trace-crossed case conditional: *"The case in 8.2 arises only for a witness that is both
non-cellular and trace-crossed… the prescribed sphere is trace-dense and, on the standing prediction, already
cellular and needing no cuts at all. If the sphere turns out to be non-cellular, 8.2 becomes live."*

**The trigger has now fired on measured evidence.** `M3-CP4c-2-CB6` obeyed measure `AF1` — extract the sphere's
independent oracle row from retained result artifact `9721564203` before planning any new runtime — and read:

```
m3Cp4c2ActualGraphOracle  witness=prescribed-sphere  complex=actualEmbeddedGraph
V=18  E=30  F=18  c=1  chi=6  sourceChi=2  excludedBoundaryOrbits=0
surfaceCutGraphCallsInsideOracle=0     producerStatus=error / CellularityNotEstablished
```

`18 − 30 + 18 = 6 ≠ 2`. For any embedded graph `V − E + F ≥ χ`, with equality exactly when the embedding is
cellular, so **the prescribed sphere's pre-cut network graph is not a cellular embedding**, independently of the
producer. The standing prediction — carried unadjudicated since DEFN §8.5 — is **REFUTED**, and the sphere carries
24 traces. That is precisely DEFN-R1 §8.3's stated condition, so §8.2 is live on evidence rather than on an
argument about evidence, and CB6 correctly stopped before implementing anything.

**Two facts that must not be conflated, because they are both true.** R7-REV established that the *producer's*
`CellularityNotEstablished` is `topology_error`'s `default:` bucket for 36 distinct `GlobalTopologyPlanErrorCode`
values, raised at `SurfaceCutGraph.cpp:240/243` **with the cut set still empty** — upstream of any cut proposal and
upstream of any cellularity decision. CB6's oracle bypasses the producer entirely
(`surfaceCutGraphCallsInsideOracle=0`) and measures the graph directly. So the sphere has **two independent
problems**: a producer that fails early through a lossy error translation, *and* a network that genuinely needs
cuts. Neither finding weakens the other, and fixing one does not fix the other.

**A derived reading, offered as such and not as measurement.** The excess `6 − 2 = 4` is the standard defect term:
a sphere has no genus, so every non-disc complement component contributes one unit per boundary walk beyond its
first. Four excess units therefore indicate roughly four extra boundary circles — for example four annular
components, or one component with five boundary circles. **AG3 should verify this against the per-component
records rather than adopting it**; it is a prediction about what the cut search will face, not a result.

DEFN-R1 §8.3 also carried a second cost that only became visible once the trigger fired: it made the checkpoint's
**contingency** (§10 Option B, decoupling A2a′ from the accepted path) fire on the same condition. A contract and
its rollback plan hinging on one fact is a single point of failure. DEFN-R2 therefore resolves the contract
**unconditionally**, so that no further measurement of any witness can reopen the definition.

**What this turn does not claim.** It does not solve the sphere's *producer* failure. That failure occurs with zero
cuts, before cut selection runs at all, and nothing in Amendment 14 touches that path. `AF0`'s printed code remains
the prerequisite for any product fix there, and DEFN-R2 changes neither `M3-CP4c2-TB-X2-CAND-04` nor its ownership.
What DEFN-R2 does supply is the contract under which the sphere's *measured* non-cellularity can be resolved once
the producer reaches cut selection at all — and §5 proves a sufficient cut set exists for it.

---

## 2. The finding that resolves the contract

DEFN-R1 §6 case 2 reads:

> *"The source edge is a carrier that a trace crosses at an interior point. Promoting it creates an intersection
> with an immutable trace arc. That would subdivide the trace — mutating an immutable upstream product, which
> Amendment 12 forbids. Such an edge is therefore not an admissible cut."*

Three verified facts falsify the premise. All are in `src/geometry/EmbeddedGraphTopology.cpp`, at source bytes
identical to the packaged semantic source `755485865a7cf9c485d754f22b82a41ee151824b`.

**2.1 There is no "immutable trace arc". A trace is already many arcs.** `build_arcs` (`:344-408`) collects, for
each trace, every network event incident on it, keyed by **segment position**, then emits one `Trace` arc per
consecutive pair. A trace with `k` interior events becomes `k + 1` arcs, each carrying `trace.id`, `firstSegment`,
`onePastLastSegment` and its own `sourceFaces` span. **Subdividing a trace in the derived arrangement is the
established, accepted representation**, and it is how the accepted 355 gate has been green for the whole arc.

**2.2 The producer already subdivides a source edge at a trace contact.** `build_arcs` (`:281-329`) splits a
`Mandatory` source edge into `ArcDraft(firstNode, terminal)` and `ArcDraft(terminal, secondNode)` when a trace
terminates on it. One `NetworkEdgeId`, two arcs, a shared node interior to the source edge. The immutable
mandatory edge is unchanged; only the arrangement has two arcs.

**2.3 The crossing point is already published exactly, and already indexed.** A
`FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:246-269`) is one source-face
traversal carrying `incomingCarrier`, `outgoingCarrier`, and an exact `entryPoint` of type
`authority::FieldBoundaryPoint`. Segment `i`'s exit through its outgoing carrier **is** segment `i+1`'s entry, at
`segments[i+1].entryPoint` — an exact point on that source edge, with no tolerance. `trace_crossed_source_edges`
(`SurfaceCutGraph.cpp:78-120`) already reads exactly these points and already tests strict interiority exactly
(`exact_interior_parameter`).

**Conclusion.** A trace crossing a source edge is a point that the network itself publishes exactly, at a segment
boundary the arc-subdivision machinery already keys on. Promoting that edge requires no new geometry, no
tolerance, no predicate, and no mutation of any upstream product. Amendment 12 forbids A2a′ **repairing** an
upstream product; it does not forbid A2a′'s own arrangement from placing a node where the network already says two
curves meet.

**The reviewer error this repeats, named so it is not repeated a third time.** DEFN-R1 §6 reasoned from a property
of the *product* ("the trace is immutable") to a constraint on the *representation* ("therefore it cannot be
subdivided"), without checking what the representation already did. That is the same shape as the R2 error owned in
DEFN-R1 §1 — a true statement about one authority applied to a different one. The control is `LESSONS.md` 22e:
before ruling a representation out, read what the existing consumers of that representation actually do.

---

## 3. Amendment 14 — normative, supersedes DEFN-R1 §6 case 2 and §8

Recorded against `DESIGN.md` §7.2 alongside Amendments 12 and 13.

1. **A source edge crossed by one or more traces at interior points is an admissible cut.** Promoting it adds one
   graph arc per sub-interval between consecutive crossing points, and one graph node per crossing point.
2. **Crossing nodes are cut-created nodes.** Amendment 13 §1 already defines the vertex set as "network nodes plus
   any node created by a cut". A crossing node is such a node. It is **not** a network node, carries no
   `NetworkEdgeId` or event, and must never be published back into the `FieldAlignedCurveNetwork`.
3. **The trace is subdivided in the arrangement, not in the product.** The trace arc spanning the crossing is split
   at the same segment position the crossing occupies. `trace.id`, its segments, its events and its digests are
   unchanged. This is exactly what §2.1 shows the producer already does at every event.
4. **The admissible cut set is exactly those source edges that are not already graph arcs** — that is, every source
   edge that is neither a mandatory edge nor an already-selected cut. `SurfaceCutCandidateClass::TraceInteriorCrossing`
   is **retained as published provenance** and **removed as an exclusion**: it now records *how* an edge was
   promoted, not *whether* it may be.
5. **All admissibility and ordering decisions remain exact.** Crossing positions come from published
   `FieldBoundaryPoint` parameters; interiority uses the existing exact predicate; ordering along an edge uses
   exact comparison. **No tolerance may be introduced anywhere in this path**, and no crossing may be inferred from
   geometry rather than read from the network.
6. **DEFN-R1 §6 cases 1 and 3 stand unchanged.** An untouched source edge becomes one arc; a source edge that is
   already a mandatory edge is already an arc and must not be double-counted.
7. **DEFN-R1 §§4, 5, 7 and 9 stand unchanged.** The complex, the four conventions, the certification rules and the
   independent-oracle bar are unaffected. The oracle must now additionally reconstruct crossing nodes by its own
   construction (§9 measure **AG6**).

---

## 4. What must actually be built, itemized

This is the real cost of Amendment 14. It is bounded, and every piece has an existing template in the codebase.
**None of it may be invented where a template exists** — `LESSONS.md` 22e.

**4.1 An edge-interior synthetic node kind.** `CutNodeBindings`
(`src/geometry/EmbeddedGraphTopology.h:44-48`) today maps `SourceVertexId → NetworkNodeId` plus a reverse map and a
`combinedNodeExtent`. It must gain a second synthetic-node kind keyed by the crossing's exact identity. **The key
must be semantic, not positional:** the crossing of trace `t` at segment position `p` on source edge `e` is
identified by `(SourceEdgeTopologyKey e, TraceId t, std::size_t p)`. Two traces crossing the same edge at the same
exact parameter is a distinct case and must be rejected with a typed error, not merged — coincident crossings are
a network-level fact A2a′ has no authority to adjudicate.

**4.2 Exact ordering along a promoted edge.** Multiple traces may cross one source edge. The promoted edge becomes
`n + 1` arcs for `n` crossings, and they must be emitted in order along the edge. **Freeze the orientation
convention**: order by the `FieldBoundaryPoint` parameter measured along the canonical
`SourceEdgeTopologyKey::first() → second()` direction, compared exactly. State the convention in the CB report with
its derivation; do not infer it from a passing witness.

**4.3 Trace-arc subdivision at crossings.** `build_arcs` builds each trace's `TraceCut` set exclusively from
`network.events()` (`:357-378`). It must additionally admit crossing cuts, at the segment position of the crossing,
bound to the §4.1 synthetic node. The existing `cuts.emplace(position, node)` structure already expresses this;
what changes is the source of the entries, and the conflict check (`inserted.first->second != event.node`) must be
extended to cover an event and a crossing claiming the same position.

**4.4 The degree-four edge-locus rotation — the one genuine gap.** At an edge-locus node,
`build_rotation_system` (`:833-935`) handles exactly two arc kinds: `Mandatory`, gated by
`mandatoryRayCount == 2 && outgoing.size() == 3`, and everything else, which is **required** to be a `Trace`
(`if (!arc.trace.has_value()) → RotationSystemInconsistent`). **A `Cut` arc incident to an edge-locus node is an
unhandled shape today**, and a crossing node is exactly that: two collinear `Cut` rays plus two `Trace` rays,
degree four.

The template is already there and is the correct one. The mandatory branch uses a four-sector cyclic model around
the canonical edge direction: `key.primary = towardSecond ? 0 : 2` for the two collinear rays, with trace rays
placed in the complementary odd sectors by the `sideRank` of the source face they enter (`:846-855`). The extension
is to admit `Cut` rays into the collinear slots on the same rule, by the same
`mandatory_ray_points_to_second_endpoint` logic (`EmbeddedGraphTopology.cpp:651`, called at `:897`) generalized to a
cut arc's endpoints. **Generalize that function; do not write a second one.**

Note also `LESSONS.md` 53: the existing degree-three edge-locus rotation was written for a trace ending inside a
mandatory edge and *has never once executed*. Extending unexecuted code is not a reason to rewrite it, but it **is**
a reason to require an identity that executes both the degree-three and the degree-four shape (§7.4).

**4.5 The proposal layer must stop excluding trace-crossed edges.** Two places, both in
`src/geometry/SurfaceCutGraph.cpp:324-326`: `barriers` is built as `mandatory ∪ traceCrossed ∪ cuts`, and proposed
edges are filtered by `if (mandatory.count(edge) || traceCrossed.count(edge)) continue;`. Under Amendment 14 the
filter is simply wrong — it removes exactly the edges that are now admissible, and it is the mechanism by which a
false `NoAdmissibleCutForNonDiscComponent` would be produced.

The `barriers` set is a subtler matter and must be reasoned about, not patched. A trace crossing source edge `e`
does **not** separate `e`'s two incident triangles — the trace passes through both. Treating `e` as a barrier is a
**conservative over-approximation** that over-separates the proposal partition. Because the authoritative verdict
is always the actual-complex certificate (Amendment 13 §3: the barrier partition is a proposal heuristic and
diagnostic provenance only), over-separation costs extra cuts, never correctness. **CB may keep the conservative
`barriers` set, but must state that it is conservative and publish the resulting over-separation count**; it may not
keep the proposal *filter*.

---

## 5. Cut-set completeness — PROVED

DEFN-R1 §8 split completeness into a provable trace-free case and an unproved trace-crossed case. With Amendment 14
the split disappears.

**5.1 Theorem (cellularity of the saturated graph).** Let `S` be the source surface with triangulation `M` and
1-skeleton `M¹`, and let `N` be the embedded arc set of the `FieldAlignedCurveNetwork`. Then `N ∪ M¹` is a
cellular embedding in `S`.

*Proof.* The complement of `M¹` in `S` is the disjoint union of the open source triangles, each an open disc.
Fix one triangle `T`. The arcs of `N` meeting `T`'s interior are trace sub-arcs. Each such arc has both endpoints
on the already-cut structure of `T`: a crossing point on `∂T` (a carrier edge, by the definition of
`incomingCarrier` / `outgoingCarrier`), a corner of `T` at a singularity port, or a node interior to `T` lying on
another trace sub-arc that itself reaches `∂T`. Cutting an open disc along a finite family of embedded arcs whose
endpoints lie on the boundary or on previously added arcs yields open discs. Hence every complement component of
`N ∪ M¹` is an open disc. ∎

**5.2 The two conditions, stated rather than assumed.** The proof needs (a) every trace sub-arc's endpoints attach
to the boundary or to already-attached structure, and (b) no node of the graph has degree 0. Both are properties
the producer already enforces or can check: crash-on-contact termination gives (a) — every trace ends at a
singularity, a mandatory barrier, or another trace — and `build_rotation_system` already rejects degree 0 outright
(`:737-741`). **AG3 requires both to be verified and published, not assumed.** A trace terminating at an
unattached interior point would leave a slit rather than a subdivision; a slit disc still satisfies
`boundaryWalkCount == 1` and `χ == 1`, so it is admitted, but it must be *observed* if it occurs.

**5.3 Corollary (existence and termination bound).** For any cut set `C ⊆ M¹`, `N ∪ C` can always be extended to a
cellular embedding by promoting further source edges, since promoting all of them yields `N ∪ M¹`, cellular by
§5.1. **A sufficient cut set therefore always exists, and at most `|E(M)|` promotions are ever required.**
DEFN-R1 §8.2's open case is closed.

**5.4 What the theorem does not give, and the error-code split it forces.** §5.3 proves a cut set *exists*. It does
not prove the greedy tree–cotree proposal *finds* one. These are different failures and the current single code
`NoAdmissibleCutForNonDiscComponent` conflates them — which is precisely the `LESSONS.md` 57 defect this
checkpoint just paid eight turns for. Frozen:

- **`NoAdmissibleCutForNonDiscComponent` is retired as a possible outcome.** Under Amendment 14 it can only fire
  when every source edge of a non-disc component is already a graph arc, and §5.1 shows that configuration is
  cellular. If it fires, the producer's own admissibility classification disagrees with the theorem — a **defect**,
  and it must be reported as one under a distinct code, not as a definition gap.
- **`CutSearchExhaustedBeforeCellularity` (new, name may be improved but must be equally explicit)** is the honest
  code for "the proposal heuristic made no progress". It carries the component locus and the counts.
- **Saturation is the defined last resort, and it is reported, never silent.** On search exhaustion the producer
  promotes the remaining admissible source edges of the offending component and re-certifies. §5.1 guarantees this
  succeeds. It **must** publish `saturationUsed=true` with the component locus and the number of edges promoted.
  A2a′ does not assign a disposition — A8 does — so this is a published fact, not a self-declared degradation.
- **Saturation firing on any of the three witnesses is a red flag, not an outcome.** AG4 predicts it never fires;
  if it does, the proposal heuristic is inadequate and that is a finding to report, not to absorb.

**5.5 DEFN-R1 §10's contingency loses its trigger.** Option B — decoupling A2a′ from the accepted path — was
retained with exactly one trigger: "if §8.2 goes live — the sphere proves non-cellular and no admissible cut set
exists". §5.3 proves the second clause can never hold. **Option B is therefore withdrawn**, and the accepted path
stays wired to A2a′. This is a strengthening: the accepted 355 keeps its detector, which is what caught `PR8-R043`
in the first place. Nothing else in DEFN-R1 §10 changes; Option A remains the plan and is now unconditional.

---

## 6. Prohibited — things that will look like solutions

- **Introducing any tolerance** into crossing detection, interiority, or ordering along an edge. Every quantity in
  this path is published exactly by the network. An epsilon here is a design defect, not a tuning problem.
- **Inferring a crossing from geometry** rather than reading it from `segments[i].entryPoint` /
  `edgeTransitExit` / `terminalPoint`. A recomputed intersection is a second authority for a datum the network
  already owns — `RP-01`.
- **Publishing a crossing node back into `FieldAlignedCurveNetwork`**, or altering any trace's segments, events, or
  digests. Amendment 12 stands.
- **Writing a second rotation-ordering routine** for degree four instead of generalizing the existing edge-locus
  four-sector model. A second implementation is how this checkpoint arrived here.
- **Merging two coincident crossings** on one edge instead of rejecting them with a typed error.
- **Keeping `NoAdmissibleCutForNonDiscComponent` as a live outcome** with its current meaning, or letting
  saturation fire silently.
- **Relaxing `proves_cellularity()`**, mixing any barrier-partition quantity into a certificate, or changing the
  global certificate to the proxy's `10/11/2`. DEFN-R1 §7 and AC9 stand in full.
- **Treating Amendment 14 as an explanation of the prescribed sphere's failure.** The sphere fails with zero cuts,
  upstream of every line of this. Conflating them would be exactly the mistake §1 exists to prevent.

---

## 7. AF5 — gate membership, decided per identity

The `AF5` hole was that **no `SurfaceCutGraph.*` identity appeared in the accepted 355, in candidate 357, or in
candidate 358** — CP4c-2 would have accepted a new pipeline stage while requiring none of that stage's own
witnesses. This section closes it. "It was never added" is not a rationale, and neither is "it passes today".

### 7.1 The four existing A2a′ identities

| identity | contract it holds | decision | rationale |
|---|---|---|---|
| `SurfaceCutGraph.AlreadyCellularNetworkPublishesEmptyCertifiedCutSet` | **idempotence** — an already-cellular network receives zero cuts, and the certificate carries `complex = ActualEmbeddedGraph` with one face and one boundary walk | **GATING** | It is CP4c-2's most basic contract and the only identity asserting the complex *label* Amendment 13 §3 requires. Its witness is `make_square_mesh` — planar, 4 vertices, 2 faces, no interior vertex — so its zero-transport atlas lift is trivially integral and it carries none of the risk in §7.2. |
| `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` | **representation-independent identity** under source face/edge reordering | **GATING** | It is the **only** falsifier of live measure `AD3`, which currently defends hashing the raw `face.orbit` index into a *semantic* digest with a comment rather than a test. `RP-05` is a stable regression pattern with two prior events; leaving its guard ungated is not acceptable. Enters the gate red until `AF3`/`AF4` give it a viable witness. |
| `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTwoRingWitness` | **semantic/provenance separation at the A2a′ boundary** | **GATING** | This is what measure `AD5` was for: check the split where it lives, not two stages downstream at ordinal 310. Green in R7-2. |
| `SurfaceCutGraph.SemanticDigestIgnoresGaugeRelabelingForTorusWitness` | the same contract on a **closed genus-1** witness | **GATING** | `PR8-R044` is runtime-proved on one witness only. A closed-surface witness is not redundant with a disc. Enters the gate red until `AF3` rebuilds it on the production `torus.rawfield` authority. |

**Two of the four enter the gate red. That is correct.** A required-green selector states what must be true for the
checkpoint to close; it is not a record of what happens to pass today. `gate_execution_authorized` remains `false`,
so nothing is executed on this basis yet.

### 7.2 Candidate 357 — superseded

357 = accepted 355 + `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` +
`GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation`. Both identities are correct, both
bind the torus through the production entry path, and both are **retained**. 357 is superseded only because it is
incomplete, not because anything in it is wrong. Its 357 bytes are a byte-exact prefix of the new gate.

### 7.3 Candidate 358 — withdrawn

358's sole addition is `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses`, which binds the
torus **and** `cp4c_mechanical_fixture()`. `build_cp4c_production_fixture` throws when the pipeline did not retain
atlas/network/cut-graph/plan, and the mechanical witness has no atlas — it stops in A1 at `IncompleteCycleBasis`
and is explicitly owned by CP4c-3 / C2. **A gate may not bind a witness its own checkpoint declares out of scope.**

358 is withdrawn as a gate candidate. Its file is retained as historical authority and must not be deleted.

**Criterion C3 is not withdrawn with it.** Rotation-system / face-walk agreement is a real CP4c-2 criterion and has
now been deferred six times. §7.4 splits it so the in-scope half enters the gate and the out-of-scope half moves to
the checkpoint that owns it.

### 7.4 New identities that must be created and appended

These do not exist yet, so they are not in the frozen selector below. **AG7 makes their append mandatory and
named**, rather than leaving them to be silently omitted the way the four in §7.1 were.

| identity to create | contract | owner |
|---|---|---|
| `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness` | criterion **C3**, torus half only — the mechanical half moves to CP4c-3 / C2 | CB6 |
| `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs` | Amendment 14 §§3.1–3.3: promotion yields `n+1` cut arcs and `n` crossing nodes, trace arcs split at the same segment positions, network digests unchanged | CB7 |
| `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour` | §4.4: the four-sector edge-locus rotation admits `Cut` rays; **must execute the degree-three shape too**, which `LESSONS.md` 53 records has never run | CB7 |
| `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted` | §5.4: saturation terminates in cellularity and publishes `saturationUsed` with locus and count | CB7 |

The resulting gate is **365**. Its bytes are frozen by the turn that creates the identities, under AG7.

### 7.5 The frozen CP4c-2 gate — selector 361

Created this turn as `.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_361.txt`. It is candidate
357 with the four §7.1 identities appended in the order listed.

| authority | source file | derivation | SHA-256 |
|---|---|---|---|
| accepted 355 prefix | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | `head -n 355 <file> \| sha256sum` | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| candidate 357 prefix | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | `head -n 357 <file> \| sha256sum` | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| **CP4c-2 gate 361** | `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` | whole file: `sha256sum <file>` | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |

Verified at authoring, per `AE4` and `AE5`: every value is exactly 64 lowercase hex; each was **computed from the
committed bytes**, not transcribed; the 355-prefix hash equals the accepted authority in `ORIENTATION.md` §3 and the
357-prefix hash equals the previously frozen candidate 357, so **prefix comparability of `first_red_ordinal` across
the whole CP4c arc is preserved**. All 361 lines are unique, and each of the four appended identities resolves to
exactly one `TEST(...)` definition in `tests/FieldAlignedCurveNetworkTests.cpp`.

`selected_gate` remains **NONE** and `gate_execution_authorized` remains **false**. Freezing a gate's bytes is not
selecting it; selection happens at a TB with an explicit authorization.

---

## 8. Falsifiable predictions

1. Every source edge in the torus is admissible under Amendment 14 — the torus has zero traces, so §4.1–§4.4 add
   **no** crossing nodes there, and the torus's `V/E/F = 72/76/4`, `χ = 0` is **unchanged** by this amendment.
2. The two-ring's actual embedded graph `9 / 11 / 3`, `χ = 1` is likewise unchanged; it has three traces but no
   promoted trace-crossed cut, because it is already cellular and receives zero cuts.
3. Amendment 14 changes no accepted identity's result. If any ordinal in the accepted 355 moves, the change was not
   confined to the arrangement and must stop.
4. `NoAdmissibleCutForNonDiscComponent` never fires again on any witness, because under §5.3 the configuration it
   reports cannot exist.
5. `CutSetSaturationProvesCellularityWhenSearchIsExhausted`'s `saturationUsed` is **false** on all three witnesses.
   If it is true anywhere, the tree–cotree proposal is inadequate and that is a finding.
6. **The prescribed sphere will require cuts, and at least one will be trace-crossed.** CB6 measured its pre-cut
   graph non-cellular with excess 4 and it carries 24 traces over a mesh with zero mandatory edges, so the cut
   search has no trace-free source edges to prefer. This is the production witness Amendment 14 exists for.
7. **It is nevertheless not yet reachable**, because the sphere's producer fails at `SurfaceCutGraph.cpp:240/243`
   before cut selection. So the degree-four edge-locus rotation is first exercised only by a **constructed**
   witness — the torus promotes cuts but has zero traces, and the two-ring needs none. **AG5 therefore requires a
   purpose-built witness even though the sphere is the eventual real one**; without it the amendment can ship
   unexecuted, which is the `AF5` failure repeating one level down.
8. The excess-4 reading of §1 resolves into per-component records showing roughly four extra boundary circles. If
   the components instead show something else, §1's derived reading was wrong and only the reading — not the
   non-cellularity, and not Amendment 14 — is affected.

Prediction 7 is the load-bearing one. Prediction 3 is the one that must be checked first and hardest.

---

## 9. Measures **AG0–AG9**

**AG0 — selector and gate authority.** The CP4c-2 required-green gate is **361**, whole-file SHA-256
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`, with 355- and 357-prefix hashes as in §7.5.
Candidate 357 is superseded and candidate 358 is withdrawn; **both files are retained** as historical authority and
must not be deleted. Recompute all three 361 values from committed bytes at every preflight; never transcribe.
`selected_gate=NONE`, `gate_execution_authorized=false`, `selected_r2_branch=NONE` remain unchanged.

**AG1 — implement Amendment 14 as one conversion.** §4.1 through §4.5 land **together**. A partial conversion —
crossing nodes without the rotation extension, or the proposal filter removed without the arc subdivision — is the
defect this checkpoint has already corrected twice. Enumerate every touched site in the CB report and state, for
each, that it was converted.

**AG2 — generalize, do not duplicate.** The degree-four edge-locus rotation extends the existing four-sector model
and generalizes `mandatory_ray_points_to_second_endpoint` to cut arcs. A second ordering routine is prohibited.
Report the exact symbol that now owns it and every call site.

**AG3 — publish the theorem's conditions, and the sphere's component structure.** Verify and publish, per witness: that every trace sub-arc's endpoints
attach to the boundary or to already-attached structure, and that no graph node has degree 0. State §5.1's proof
and §4.2's edge-orientation convention as prose plus code, with derivations shown, not asserted. Additionally
publish the prescribed sphere's per-component records behind its `chi=6` excess and check them against §1's derived
excess-4 reading, adopting or refuting it explicitly.

**AG4 — the error-code split.** Replace `NoAdmissibleCutForNonDiscComponent`'s meaning per §5.4: add
`CutSearchExhaustedBeforeCellularity` with component locus and counts, implement saturation as the defined last
resort, and publish `saturationUsed`, its locus, and the promoted-edge count on every run. Saturation may never be
silent. **Verified in this review: `NoAdmissibleCutForNonDiscComponent` is consumed by no test in the repository**
— its only occurrences are the raise site (`SurfaceCutGraph.cpp:326`), the name function (`:339`) and the enum
declaration (`SurfaceCutGraph.h:86`) — so no accepted identity depends on it and the enum value may be repurposed
or retired freely. Re-verify before editing rather than trusting this line.

**AG5 — a witness that actually exercises the crossing.** Predictions 6-7: the prescribed sphere is the eventual
real witness but is unreachable behind its producer failure, and no *reachable* committed witness promotes a
trace-crossed edge. Construct one — a small closed or bounded fixture with a trace crossing a source edge that a
tree–cotree cut must promote — and assert its precondition **at runtime inside the fixture**, in the CP3a style
`LESSONS.md` §2 requires. Without this, Amendment 14 ships unexecuted.

**AG6 — extend the independent oracle.** DEFN-R1 §9 stands, plus: the oracle reconstructs crossing nodes by its own
construction and publishes, per promoted edge, its crossing count and the resulting arc count, compared term by
term against the producer.

**AG7 — the four new identities enter the gate, by name.** §7.4's four identities are created and **appended** to
selector 361 in the listed order, producing gate **365**. The turn that creates them recomputes and records the
365 whole-file hash and re-verifies the 355 / 357 / 361 prefix hashes. Omitting any of them requires an explicit
written rationale in that turn's report — silence is not a decision.

**AG8 — sequencing, and the one condition under which it collapses.** `M3-CP4c-2-CB6` under **AF0–AF4** remains the
exact next turn and is **not** widened by this document. Reason: AF0 makes the sphere's collapsed error readable and
AF1 may change what is needed, and building Amendment 14 on an unreadable failure is how R2 went wrong. AG1–AG6
belong to **`M3-CP4c-2-CB7`**. **Single merge condition:** if AF0's printed code localizes the sphere's
`RotationSystemInconsistent` to `build_rotation_system`'s edge-locus branch (`EmbeddedGraphTopology.cpp:833-935`),
then it and §4.4 are the same code and CB6 may absorb AG2 — and only AG2. Any other locus keeps the split.

**AG9 — prohibited.** Everything in §6, plus: changing any byte of selectors 316/346/353/355/357/358; changing
selector 361 other than by the AG7 append; selecting a gate or setting `gate_execution_authorized=true`; executing
any gate, cumulative gate, or benchmark; reverting AA1; executing DEFN-R1 §10 Option B, whose trigger §5.5
withdraws; treating Amendment 14 as an account of the sphere's failure; and compiling without GMP/GMPXX per
`GMP_COMPILE_POLICY.md`.

---

## 10. Stop / successor

The exact next turn is **`M3-CP4c-2-CB6`**, Code + Build, runtime-free, under **AF0–AF4** with the **AF9**
prohibitions — unchanged by this document except for AG8's single merge condition. Its successor TB carries
**AF6**, **AF7** and **AF8**. `M3-CP4c-2-CB7` then implements Amendment 14 under **AG1–AG6**, and the turn that
creates §7.4's identities carries **AG7**.

CP4c-2's required-green gate is **selector 361**, frozen. `selected_r2_branch` remains **NONE**, `selected_gate`
remains **NONE**, `gate_execution_authorized` remains **false**. CP4c-2 is open and runtime-unaccepted; CP4c-3
remains blocked.

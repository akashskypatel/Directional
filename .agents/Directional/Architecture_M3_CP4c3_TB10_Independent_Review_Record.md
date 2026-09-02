# M3-CP4c-3-TB10 — Independent Review + Plan Record

**Turn:** `M3-CP4c-3-TB10-REV`
**Type:** independent REVIEW + PLAN. Static only.
**Governing scope:** `Architecture_M3_CP4c3_TB10_Independent_Review_Plan.md`, measures **BE0–BE7**.
**Boundary honoured:** no Directional runtime, benchmark, configure, compile, link, package, or
product/test/fixture/selector mutation. Every derivation below is a static reading of the exact packaged source
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15` and of committed bytes.

---

## 1. Executive adjudication

**The exact ordinal-366 condition is NOT recoverable at the current instrumentation, and this review proves that
rather than assuming it.** The proof is constructive and narrows the answer sharply:

1. `EmbeddedGraphTopology.cpp` emits `RotationSystemInconsistent` from **46 distinct sites**, all of them reachable
   from `SurfaceCutGraph::make`. Only **9** publish a `RotationSystemInconsistencyReason`.
2. **Every one of those 9 also sets `sourceEdge` and/or `sourceFace`.** TB10 rendered neither, and the mechanical
   identity's message renderer prints both when present. So the firing site is one of the **28** that publish
   *neither* a reason nor an edge/face locus.
3. Therefore **the discriminator that exists cannot discriminate this failure.** The reason field was added only to
   sites that already carried a locus; the 28 that carry nothing are exactly the ones it does not cover.

**This corrects the TB10 report's localization, which is half of the story.** The projection loss is real — and
there are in fact **three** sequential losses of the same datum, not one — but for this failure **there is nothing
to project**: 23 of the 28 candidate sites populate no field at all, and the other 5 populate only `sourceVertex`,
which `SurfaceCutGraph::topology_error` does not even copy. **Repairing the projection alone would change ordinal
366's output by nothing.** The earliest actionable owner is the **producer**, not the renderer.

**BE2 classification: diagnostic insufficiency, producer-side.** No product semantic correction is authorized, and
none is inferable — the 28 candidates span `build_arcs`, `build_node_loci`, `build_rotation_system`,
`walk_graph_faces` and `exterior_boundary_orbits`, i.e. **before, during and after** vertex/fan ray ordering, so
BE5's ordering question is provably undecidable from present evidence.

**BE3:** ordinals 367, 371 and 372 are **strictly upstream-blocked by one cause** — they abort inside the shared
`cp4c_mechanical_fixture()` constructor, before their own assertions. One candidate, not three. But §5 records a
separate finding: **371 and 372 need only the A1 atlas**, which is available and already proved good, and are held
hostage by a fixture helper that demands the whole downstream chain.

**BE6 successor: `M3-CP4c-3-CB13` under BF0–BF9, diagnostic-only Code + Build.** Resolve the producer-side
collapse, carry `sourceVertex` through the mapper, and extend the pipeline projection — three boundaries, one
datum. The carrier is named: **ordinal 366's own failure message.**

**Accepted authority remains 365/365. Stable accounting remains 44 / 14 / 30, debt 5, semantic packages 77.**
This review is static and loses no accepted-green behaviour: **+0 events / +0 recurrences**.

---

## 2. BE0 — immutable authority and scope re-established

### 2.1 Recomputed from committed bytes

| quantity | recomputed | agrees |
|---|---|---|
| selector 377 SHA-256 | `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1` | yes |
| selector 377 lines / unique identities | 377 / 377 | yes |
| `head -365` (accepted) | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` | yes |
| `head -367` | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` | yes |
| `head -370` | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` | yes |
| `head -373` | `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` | yes |
| `head -374` (gate) | `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` | yes |
| `head -375` | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` | yes |
| `head -376` | `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8` | yes |

All values are exactly 64 lowercase hex characters, recomputed from the file rather than transcribed. Selector 377
appends to 376 and reorders nothing; the accepted 365 prefix is byte-identical throughout.

### 2.2 Semantic-source scope

`git diff` between package-80 semantic source `a3b6f1a41feaa8a115faf11de52f85ce4cc42a15` and the reviewed branch
head is **empty** across `src/`, `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt` and the selector-377 file.
The 42 intervening commits are control-plane and documentation only. **No later commit is used as semantic
evidence**, as BE0 requires, and every static derivation below reads the bytes TB10 executed.

### 2.3 TB10 runtime facts consumed as evidence only

Package 80 `9828786744`; run/job `33584653692 / 100106147126`; result `9829700900`
(`2e7d978d…63572`); log `9829701136` (`89f445c5…ce17d`). 377 fresh processes, **369 PASS / 8 RED**; ordinals
**1–365 PASS**; first red **366** at
`NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`;
`oldOrdinal366ConditionSeedPair=false`; identity 377 PASS at terminal v36 / singularity 4 / `BarrierAbsorbed` /
node 7; immutable postflight PASS with every mutation and benchmark flag false.

---

## 3. BE1 — recovering the exact rotation-system failure

### 3.1 The producer surface, counted

Every `RotationSystemInconsistent` emission site in `EmbeddedGraphTopology.cpp` was enumerated and classified by
what it publishes. All 46 are reachable from `SurfaceCutGraph::make`, which calls
`build_embedded_graph_topology` (→ `build_cut_node_bindings`, `build_arcs`, `build_rotation_system`,
`walk_graph_faces`) and then `exterior_boundary_orbits`.

| producing function | sites | publish a reason | publish `sourceEdge`/`sourceFace` | publish only `sourceVertex` | publish nothing at all |
|---|---:|---:|---:|---:|---:|
| `build_arcs` | 4 | 2 | 2 | 2 | 0 |
| `build_node_loci` | 5 | 3 | 3 | 2 | 0 |
| `build_rotation_system` | 27 | 4 | 13 | 1 | 13 |
| `walk_graph_faces` | 9 | 0 | 0 | 0 | 9 |
| `exterior_boundary_orbits` | 1 | 0 | 0 | 0 | 1 |
| **total** | **46** | **9** | **18** | **5** | **23** |

The last two columns sum to the **28** candidate sites of §3.2.

**The load-bearing fact: the set of sites that publish a reason and the set that publish no locus are disjoint.**
All 9 reasoned sites also set an edge and/or a face.

### 3.2 The elimination

The ordinal-366 identity renders its failure through `build_cp4c_production_fixture`, which throws a
`std::runtime_error` built from `terminalFailureCode/Stage/DetailCode` plus
`append_cp4c_failure_locus(terminalFailureLocus)`. That renderer **does** print `;sourceEdge=` and `;sourceFace=`
whenever the locus carries them.

TB10 recorded no reason, no source vertex, no edge, no face, no trace and no event. Therefore:

- the firing site is **not** one of the 9 reasoned sites (each would have set an edge or a face);
- the firing site is **not** any of the 18 that set an edge or a face;
- **the firing site is one of the 28 that set neither** — 14 in `build_rotation_system`, 9 in `walk_graph_faces`,
  2 in `build_arcs`, 2 in `build_node_loci`, 1 in `exterior_boundary_orbits`.

Of those 28, five set `sourceVertex` and 23 set nothing whatsoever.

### 3.3 Three sequential losses of one datum

| # | boundary | what is lost |
|---|---|---|
| 1 | **the 28 producer sites** | the identity of the failing condition itself — no reason, and for 23 of them no locus of any kind |
| 2 | `SurfaceCutGraph::topology_error` | **`sourceVertex`** — `SurfaceCutGraphError` has no such field, so the only datum the remaining 5 candidates publish is discarded one layer before the pipeline |
| 3 | `RemeshPipeline::cut_graph_failure_locus` | everything except `sourceEdge`/`sourceFace`: the reason, `trace`, `traceEventIndex`, `traceEventPositionFailureReason`, `traceEventPositionPass`, `traceEventPositionCandidates`, `cutCandidates`, `nonDiscComponentCount`, `remainingAdmissibleEdgeCount` |

Loss 3 is the one the TB10 report names, and it is real. **It is not the one on the critical path.** Repairing 3
alone leaves ordinal 366 printing exactly what it prints today, because losses 1 and 2 have already emptied the
error before the pipeline ever sees it.

Worth recording next to loss 3: the **same file, forty lines earlier**, renders the *atlas* failure with a rich
`stage` string carrying `incompleteCycleBasisReason` and full per-region cycle-basis and transport diagnostic rows.
One stage boundary in `RemeshPipeline.cpp` publishes everything it holds; the neighbouring one publishes two
fields.

### 3.4 Is an existing product snapshot or identity sufficient? — BE1's explicit question

**No, and both candidate routes were checked.**

- **Product snapshot.** `SurfaceCellDiagnosticProductSnapshots` carries `fieldTransportAtlasError` but has **no**
  `surfaceCutGraphError` and no `globalTopologyPlanError`. `productSnapshots.surfaceCutGraph` is assigned only on
  success, so on this failure the typed `SurfaceCutGraphError` is destroyed at the pipeline boundary with nothing
  retained.
- **An existing richer identity.** `observe_cp4c_witness` calls `SurfaceCutGraph::make` **directly** from the
  retained production inputs and therefore holds the typed error; it already renders `originatingTopologyError`,
  `originatingRotationSystemReason`, `trace`, `traceEvent`, `traceEventClaimedSourceEdge`, carrier-match counts and
  the trace-event position failure/pass. That is exactly how ordinal 368 publishes the sphere's
  `TraceEventPositionInvalid`, trace 2 / event 30, `NoCarrierMatch / SourceEdgeUnavailable` chain — and it explains
  why the sphere is legible while the mechanical witness is not: **the two identities use different observation
  idioms**, and ordinal 366 uses the one that throws.
  `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` already applies that idiom to the mechanical
  witness, is compiled into package 80, and is **not in selector 377**, so it did not run in TB10.

  **But it would not resolve this failure either.** It reads the same `SurfaceCutGraphError`, which for the 28
  candidate sites carries no reason and — having no `sourceVertex` field — no locus at all. It would print
  `originatingRotationSystemReason=none;traceEventClaimedSourceEdge=none` and thereby *confirm by observation* what
  §3.2 establishes by elimination, plus useful stage/terminal-event context. That is worth having and costs
  nothing, but it names no producer.

**Conclusion for BE1's completion criterion: the exact condition is explicitly proved unavailable at the current
projection boundary, and the unavailability is producer-side.** No runtime value is invented here.

### 3.5 One further dimension the evidence cannot resolve

`SurfaceCutGraph::make` runs `certify_actual_embedded_graph` inside a `while(true)` proposal loop and returns the
**first** failure it meets. Nothing published says whether that was the initial certification over the uncut
network or a later certification after cut edges were proposed. Those are materially different findings — the
first means the network alone cannot be embedded; the second means a proposed cut broke an embedding that worked.
The successor must publish which.

---

## 4. BE2 — classification, with the alternatives falsified (BE5)

**Classification: diagnostic insufficiency, producer-side.** Not a proved product defect, not a proved witness
precondition problem, and not merely a rendering loss.

| alternative | verdict | why |
|---|---|---|
| **production-rendering loss** (the TB10 report's localization) | **falsified as the critical-path cause** | §3.3: the error is already empty before the renderer. Loss 3 is real and must still be repaired, but repairing it alone changes ordinal 366's output by nothing. |
| **rotation-system construction defect** | **possible, unproved, and deliberately not assigned** | 14 of the 28 candidates are in `build_rotation_system`, but 9 are in `walk_graph_faces` (after the rotation system is built) and 4 are before it. BE2 forbids inferring a fix from the producer list, and this review does not. |
| **before / during / after fan ray ordering** | **provably undecidable now** | the 28 candidates straddle all three phases. This is the sharpest statement the evidence supports. |
| **the same CB12 ownership failure under a new string** | **falsified** | the failing stage moved from `field-aligned-network` to `surface-cut-graph`, a different producer with a different error family; `SurfaceCutGraph::make` cannot even be called unless the network *built*; TB10 published `oldOrdinal366ConditionSeedPair=false`; and identity 377 PASSes at terminal v36 / `BarrierAbsorbed` / node 7. CB12's correction is runtime-proved and `M3-CP4c3-TB9-REV-CAND-01` is correctly **CLOSED**. |
| **invalid or stale mechanical witness** | **not supported by any present evidence** | the witness is the committed production fixture, it clears A0, A1 and A2a, and ordinals 1–365 are green on the same run. Nothing observed indicates a precondition violation, and no such claim may be made without the subreason. |
| **accepted ordinals 1–365 disturbed** | **falsified** | TB10 executed them green in the same run, one identity per fresh process. |

### 4.1 A ranked hypothesis, recorded as a measurement target and not as an owner

The mechanical witness is the **first closed witness that simultaneously carries traces and non-separating hard
features**: the torus has 48 mandatory edges and **zero** traces, the prescribed sphere has 24 traces and **zero**
mandatory edges, and the two-ring is a disc. The mechanical feature set does not separate (§10 of `ORIENTATION.md`),
so it must contain at least one **open arc**, whose tip is a degree-1 mandatory node — and CB12 has only just made
its port traces terminate correctly. So `build_rotation_system` is, on this witness, meeting a combination of
`Mandatory`, `Trace` and `Cut` rays at one vertex fan for the first time in the project's history.

That makes `build_rotation_system` the *a priori* likeliest of the five candidate functions. **It is written down
here as the hypothesis the next measurement must discriminate, explicitly not as an assignment of ownership**, and
the successor must be able to falsify it — the measurement must name the producing site whatever it turns out to
be, including the nine `walk_graph_faces` sites that would refute this hypothesis outright.

---

## 5. BE3 — 367 / 371 / 372, one cause, and a second finding

All three call `cp4c_mechanical_fixture()`, a function-local `static` initialised by
`build_cp4c_production_fixture`, which **throws** unless *all five* of `sourceAuthority`, `atlas`, `network`,
`cutGraph` and `plan` are retained. Each identity runs in a fresh process, so the throw happens inside the shared
fixture constructor, before any assertion of their own executes.

**They are strictly upstream-blocked by ordinal 366's cause. One candidate, not three; no double counting.**

**The second finding, which BE3's question exposes and which is not the same thing.** Ordinals **371**
(`NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis`) and **372**
(`CutTransportDomainSatisfiesTheEulerCutIdentity`) read **only `fixture.atlas`** — an A1 product that is available,
built successfully in this very run, and whose correctness is not in question. Their contracts are **independently
reachable today**; they are blocked by a *fixture helper's* precondition, three stages downstream of anything they
assert.

Amendment 15's barrier-cycle and Euler-cut contracts have therefore been "unmeasured, not falsified" since TB2 —
across TB2, TB3-R1, TB4, TB5, TB6, TB7, TB8, TB9 and TB10 — for a reason that has nothing to do with either
contract. Ordinal **367** is different: it genuinely needs `plan`, so it is legitimately blocked.

This is recorded as a new candidate with a named test-only corrective. It is **deliberately not folded into the
successor**: BE6 forbids combining surfaces that merely co-occur in one TB result, and the deferral is close to
free, because clearing ordinal 366 unblocks 371 and 372 automatically. The candidate exists so that if the next
turn does *not* clear 366, the cost of this coupling is visible rather than rediscovered.

---

## 6. BE4 — carried candidates preserved without opportunistic correction

| candidate | status after this review |
|---|---|
| `M3-CP4c3-TB9-REV-CAND-01` | **CLOSED / RUNTIME PROVED** by TB10's BD9 discriminators; independently re-checked in §4 and upheld. |
| `M3-CP4c3-TB6-CAND-01` | **ACTIVE.** TB10 publishes no vertex-30 discriminator; the frozen row-209/row-208 election still has no runtime acceptance. |
| `M3-CP4c2-TB-X2-CAND-04` | **ACTIVE, unchanged.** Sphere remains `TraceEventPositionInvalid → NoCarrierMatch / SourceEdgeUnavailable`, trace 2 / event 30. No sphere correction authorized. |
| `M3-CP4c2-TB-X2-R10-CAND-01` | **ACTIVE, unchanged.** `saturationUsed=true` at ordinal 369. |
| `M3-CP4c2-TB-X2-R8-CAND-02` | **ACTIVE, unchanged.** Ordinal 370 still reports `CellularityNotEstablished` (4) where `EmptyNetworkOnClosedSurface` (6) is required, with no source-face locus. |
| `M3-CP4c3-TB7-CAND-02` | **ACTIVE, unchanged.** Folded-cone witness still fails its `atlasBuild` precondition; pre-classified, no product inference. |
| `M3-CP4c3-DEFN-R2-CAND-01` and the finalize/contact fall-through | **ACTIVE, unchanged.** No new evidence proves shared ownership with the ordinal-366 cause. |

Ordinal **370** deserves one explicit note, because its surface *looks* like ordinal 366's: both render
`CellularityNotEstablished`. They are unrelated. Ordinal 370's is a **direct** `cut_error(...)` from
`SurfaceCutGraph` with no `originatingTopologyError`, whereas ordinal 366's arrives through `topology_error` with
`origin=RotationSystemInconsistent`. Shared string, different producer — do not merge them.

**Accounting.** TB10 supplies no accepted-green loss and this review executes nothing. Stable totals remain
**44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, semantic package count **77**.

---

## 7. BE6 — one bounded successor: `M3-CP4c-3-CB13`, measures **BF0–BF9**

**Type:** diagnostic-only Code + Build, runtime-free, GMP/GMPXX linked.
**Owner:** the `RotationSystemInconsistent` reporting chain — the emission sites in
`src/geometry/EmbeddedGraphTopology.cpp`, the mapper `src/geometry/SurfaceCutGraph.cpp::topology_error` and its
`SurfaceCutGraphError`, and the projection `src/pipeline/RemeshPipeline.cpp::cut_graph_failure_locus`. One datum,
three boundaries, one owner.

**It changes no topology decision.** Every measure below is additive reporting. If any measure cannot be done
without altering a decision, it must be dropped and reported, not weakened.

### BF0 — preconditions

Selectors **374, 375, 376 and 377** byte-frozen and recomputed at authoring and at preflight; accepted 365 prefix
untouched; `selected_gate=NONE`; `gate_execution_authorized=false`; no runtime, no gate, no benchmark, no package
repair; GMP/GMPXX linkage proved in the link evidence per `GMP_COMPILE_POLICY.md`.

### BF1 — one typed name per condition, at the producer

Give **every** `RotationSystemInconsistent` emission site that does not already set one a distinct enumerated
`RotationSystemInconsistencyReason`. Scope the work **by the predicate — "any site constructing a
`GlobalTopologyPlanErrorCode::RotationSystemInconsistent` error without assigning
`rotationSystemInconsistencyReason`" — found by search, not by copying this record's list.** This review counts
**28** such sites reachable from `SurfaceCutGraph::make` (14 `build_rotation_system`, 9 `walk_graph_faces`,
2 `build_arcs`, 2 `build_node_loci`, 1 `exterior_boundary_orbits`), and **46 sites in total** in that file; the
implementer must re-derive both counts independently and **reconcile any difference in the report**. Sites outside
`EmbeddedGraphTopology.cpp` that emit the same code — `GlobalTopologyPlan.cpp` has eight — are in scope for the
same predicate even though they are not on this failure's path.

Each new reason must name the **condition**, not the line: two sites that fail for the same reason may share a
name, and one site that can fail for two reasons needs two. Report the distinct-condition count per site.

### BF2 — stop losing `sourceVertex` at the mapper

`SurfaceCutGraphError` has no `sourceVertex`, so the only locus five of the candidate sites publish is discarded by
`topology_error`. Add it and copy it. While there, audit `topology_error` against `GlobalTopologyPlanError` field
by field and report any other field silently dropped.

### BF3 — project what the error holds

Extend `cut_graph_failure_locus` to publish the reason, `sourceVertex`, `trace`, `traceEventIndex`,
`traceEventPositionFailureReason`, `traceEventPositionPass`, and the cut-attempt shape (`cutCandidates.size()`,
`nonDiscComponentCount`, `remainingAdmissibleEdgeCount`). Find every consumer of
`SurfaceCellFailureLocusDiagnostics` **by search** and name in the report at least one this measure did not name.

### BF4 — say which certification attempt failed

Publish the proposal-loop iteration index and the cut-edge count in force when `certify_actual_embedded_graph`
returned the error, so an initial-network failure is distinguishable from a proposal-induced one (§3.5).

### BF5 — name the carrier

The evidence carrier is **ordinal 366's own failure message**, which is built from `terminalFailureLocus` through
`append_cp4c_failure_locus`. BF1–BF4 are dischargeable only if that message names the producing condition. Extend
`append_cp4c_failure_locus` to render the new fields in the same change. **No new gate ordinal is required and none
may be added**; the existing first red becomes informative.

Additionally, declare `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` as a **non-gating
diagnostic identity** for the successor TB, with the written rationale that it re-derives the cut-graph error from
production inputs and adds stage/terminal-event context. It is already compiled and requires no code change. It is
excluded from the gate count and earns no credit.

### BF6 — audit by assumption

Two predicates, each discharged by search, each with at least one site named **outside** those this record names:

- *"a typed error code is emitted from more than one site and at least one of them publishes no discriminating
  field"*;
- *"a mapper or projection between two stages copies a subset of the fields its source carries."*

### BF7 — prohibited

Changing any topology decision, ray ordering, cellularity test, cut proposal, or admissibility rule; adding or
removing a gate ordinal; altering any selector byte; adding a tolerance or a float-derived topological decision;
repairing the sphere, ordinal 370, saturation, the folded-cone witness, vertex 30, or the finalize/contact
fall-through; decoupling ordinals 371/372 from the mechanical fixture (deferred by §5 on purpose); inferring and
"fixing" a rotation-system producer before the measurement names it.

### BF8 — report obligations

State the re-derived site counts and their reconciliation with §3.1; the per-site distinct-condition counts; the
`topology_error` field-by-field audit result; the consumer search result for BF3; and an explicit statement that
no topology decision changed.

### BF9 — expected discriminators for artifact-only `M3-CP4c-3-TB11`

Falsifiable in advance:

1. **Ordinal 366 names its producing condition.** Its message carries a `RotationSystemInconsistencyReason` other
   than the nine already-reachable ones, plus whatever locus that site holds. A repeat of TB10's bare
   `origin=RotationSystemInconsistent` is a failure of BF1/BF5, not new evidence.
2. **The failing phase becomes decidable.** The published reason places the failure in exactly one of
   `build_arcs`, `build_node_loci`, `build_rotation_system`, `walk_graph_faces` or `exterior_boundary_orbits`,
   settling BE5's before/during/after question that §4 proves undecidable today.
3. **The certification attempt is identified** — initial uncut network, or proposal *n* with *k* cut edges.
4. **Accepted ordinals 1–365 stay green**, and the first red stays at 366. A diagnostic-only change that moves the
   first red is a defect in the change.
5. **Ordinals 367, 371, 372 stay red at the same upstream stop**, and 368, 369, 370, 374 reproduce their existing
   pre-classified surfaces. Any of them moving means BF1–BF4 changed a decision and must be reverted.
6. **§4.1's hypothesis is tested, not assumed.** A reason inside `walk_graph_faces` or `exterior_boundary_orbits`
   falsifies it, and that is a legitimate and valuable outcome.

**Compile targets:** the eight standard targets, GMP/GMPXX linked, `runtimeExecution=false`, one package; successor
is artifact-only `M3-CP4c-3-TB11` executing selector 377 from ordinal 1, one identity per fresh process, plus the
declared non-gating diagnostic identity, with every mutation/build/repair/benchmark flag false.

---

## 8. Lessons and prohibited shortcuts retained

- **A discriminator added to the sites that already had a locus discriminates nothing new.** Nine of forty-six
  sites gained a `RotationSystemInconsistencyReason`, and all nine already published an edge or a face — so the
  cases that were already legible got more legible, and the twenty-eight that published nothing stayed silent.
  When resolving a collapsed error code, **enumerate the sites that publish nothing and start there**; the ones you
  can already localise are the ones that least need a name.
- **Count the losses before repairing one.** The TB10 report localised a real projection loss and named it the
  cause. There were three losses of the same datum in series, and the reported one was the *last*. Repairing it
  alone would have produced a full turn of no new evidence. Before proposing a diagnostic fix, walk the datum from
  its producer to its reader and count every boundary that drops it.
- **Two identities on the same witness class can have very different eyesight.** The sphere's failure is legible
  because ordinal 368 uses `observe_cp4c_witness`, which holds the typed error; the mechanical failure is opaque
  because ordinal 366 uses `build_cp4c_production_fixture`, which throws a string. The idiom, not the stage,
  decided how much the project could see.
- **A shared fixture helper's precondition is a coupling, and it can silence contracts for many turns.** Ordinals
  371 and 372 read only the A1 atlas, and have been unmeasurable since TB2 because the helper that hands it to
  them also demands four downstream products.
- **Shared error strings are not shared causes.** Ordinals 366 and 370 both render `CellularityNotEstablished`;
  one arrives through `topology_error` with an origin code and one is a direct `cut_error`. Check the producer
  before merging two reds.

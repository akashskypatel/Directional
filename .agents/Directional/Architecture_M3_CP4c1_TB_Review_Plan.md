# Architecture M3 CP4c-1 — TB Review + Plan

**Turn:** `M3-CP4c-1-TB-REVIEW-PLAN`
**Type:** Review + Plan only — no product, test, fixture, selector, or build mutation; no compile, package, or runtime
**Evidence under review:** TB run/job `32800374361 / 97659929298` on immutable package `9545473837`, semantic source `18101c05d3d5fd982a61446c0b9df9f97e6ceed5`
**Result under review:** **VALID RED 316/318** — accepted prefix 316/316 PASS, C4 and C5 FAIL
**Binding workflow:** `CB → TB → (red) → REVIEW+PLAN → CB`. This red consumes nothing.

---

## 0. Dispositions

| # | Subject | Disposition |
|---|---|---|
| **E1** | X1 (rejection-code split) | **Delivered and vindicated.** One code became 18; the torus failure localized immediately to a code that did not previously exist. |
| **E2** | X3 (C4/C5 witness union) | **Delivered correctly.** The tests are right; they fail for the intended reason. Do not touch their logic. |
| **E3** | My torus prediction | **WRONG, and the evidence is better than the prediction.** §2.2. |
| **E4** | My mechanical cycle-count hypothesis | **WITHDRAWN — not supported by the locus.** §4. |
| **E5** | Torus: 0 traces / 0 events | **Correct A2a behaviour on a singularity-free closed surface.** The gap is that `DESIGN.md` §7.2's normative derivation has no cut-graph bootstrap for such a surface. §3. |
| **E6** | The actual CP4c-1 blocker | **No committed witness exercises crash-on-contact at all** — the primitive `DESIGN.md` §4.6 calls the region-decomposition guarantee. §5. |
| **E7** | The fix | **`sphere_prescribed` is the witness**, it is DESIGN-named and committed, and it is *structurally forced* to produce terminal `TraceIntersection`. §6. |
| **E8** | Escalation | `DESIGN.md` §7.2 needs a closed-surface clause. Owned by `M3-CP4c-2-DEFN`, not by CP4c-1. §8. |

Accepted authority is untouched: **316/316 PASS in the same immutable run.** Stable accounting stays **42 / 14 / 28**; produced-witness debt stays **5**.

---

## 1. Evidence — independently verified

Verified against the GitHub Actions API, not accepted from the report:

| Check | Result |
|---|---|
| Run `32800374361`, head `e678b98c3b855a4a602fbb18ccaf6b6732a1748b` | matches the report exactly |
| Result artifact `9546334088` | `sha256:9d1d918bb6694f7f76e3c58d3da483d2f5d4e4c487f896b991d707f1d5172ca4` — exact |
| Execution log `9546334491` | `sha256:7fbf5d0ec2ea4d68282baee713b2bcc90a6983381c10e21d2898cc863d4c7ca0` — exact |
| Control log `9546334936` | `sha256:268ded1d05636d60a1927725ada9a23da57fa4c637a7a9c6ba7f2e547905a394` — exact |
| Schema-validation job present and green | `97659892741` SUCCESS |

**320 fresh processes** — 318 required plus 2 non-gating — one identity each, zero orchestration errors, zero disabled, every configure/build/relink/repair/discovery and every mutation flag `false`, package/source/selector digests identical pre/post, `SHA256SUMS` 27/27 both times, postflight source diff empty. **This is a clean VALID RED.**

The non-gating mechanism introduced by the workflow change worked exactly as intended on its first use: two diagnostic identities executed, reported, failed, and were excluded from the gate count. No turn type and no budget was needed to obtain that evidence.

---

## 2. What the corrective measures delivered, and where I was wrong

### 2.1 X1 — the code split is the reason this turn produced knowledge

`GlobalTopologyPlanErrorCode` went from one overloaded `RegionCutComponentCountDeficit` to **eighteen** condition-specific codes (values 20–37). The torus's first A2b rejection is now
`UncutFaceComponentOrbitSeedNotUnique` with locus `sourceFace=0-1-2` — a code that **did not exist before this turn**.

Last turn the same failure was reported as `RegionCutComponentCountDeficit` and could have been any of eighteen conditions. It is now one. **X1 is exactly what a first corrective measure should be**: it changed no behaviour, cost nothing, and converted an 18-way ambiguity into a fact.

### 2.2 E3 — my torus prediction was wrong

I predicted `TraceArcDoesNotSeparateItsSides` with an arc + source-face locus, on the reasoning that a non-separating cycle on a genus-1 surface would trip the same-orbit check at `GlobalTopologyPlan.cpp:1267`.

**Observed instead:** `UncutFaceComponentOrbitSeedNotUnique`, and the reason is now obvious and better:

> The torus network publishes **`networkTraceCount=0`, `networkEventCount=0`.**

The check at `:1267` lives inside a loop over **trace arcs**. With zero trace arcs the loop body never executes, so my predicted code is unreachable on this witness. My prediction assumed traces existed; it did not check. The falsifiable prediction did its job — it was falsified, and the correction is a deeper finding than the hypothesis.

### 2.3 X3 — the C4/C5 restructure is correct and must not be touched

X3 was implemented as specified: a witness union with contributor tracking, a graceful skip when a witness does not reach A2a, and a failure message that names the reachability of each witness. C5's assertion is intact:

```cpp
ASSERT_EQ(2U, producedTerminalKinds.size())
    << "terminal-kind witness union must be non-vacuous; TraceIntersection=" …
```

It fails because the union genuinely contains only `MandatoryBarrierTermination`. **The test is right and the witness set is wrong.** Do not weaken, delete, or relax C4 or C5.

---

## 3. E5 — the torus, and the `DESIGN.md` §7.2 gap

### 3.1 Why the torus network is empty — mechanism, not conjecture

Measured by the non-gating diagnostic: source Euler **0**, boundary loops **0**, genus **1**, 72 interior vertices; **A1 atlas established**; A2a network established with **0 traces and 0 events**.

The chain is forced:

1. Poincaré–Hopf on a closed surface: Σ singularity index = χ = **0**. A cross field on a torus can be, and this one is, **singularity-free**.
2. A2a builds ports one per singularity (`SurfaceCellTracing.cpp:922-940`) and one trace per port (`:316`). **Zero singularities → zero ports → zero traces → zero events.**
3. Mandatory edges come only from barriers — `SourceBoundary` or hard feature. The torus is **closed** (0 boundary edges) and carries no hard features. **Zero mandatory edges.**

So the entire field-aligned curve network is empty: no nodes, no ports, no traces, no mandatory edges, no events.

### 3.2 Why A2b then rejects, and why the locus is `0-1-2`

A2b's ownership algorithm (`GlobalTopologyPlan.cpp:1695-1747`) works in two phases:

- faces touched by a trace arc or bounded by a mandatory edge are **labeled** with orbits;
- **unlabeled** faces are union-found across non-mandatory, non-trace-touched edges, and each resulting component takes its orbit by **seeding from an adjacent labeled face**:

```cpp
for (std::size_t index = 0U; index < unlabeledFaces.size(); ++index) {
  const std::size_t root = findRoot(findRoot, index);
  const auto seeds = seedOrbits.find(root);
  if (seeds == seedOrbits.end() || seeds->second.size() != 1U) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique);
    failure.sourceFace = unlabeledFaces[index];
    return failure;
  }
```

On the torus **no face is labeled**, so all 144 faces unite into a single unlabeled component, `seedOrbits` is empty, the lookup misses, and the rejection fires on the first unlabeled face in order — `0-1-2`. **The observed locus is exactly what this mechanism predicts.**

### 3.3 The finding, stated at the right level

> **A2b's region ownership is seeded exclusively by labeled faces, and faces are labeled only by trace arcs and mandatory edges. On a closed surface whose field is singularity-free and which carries no features, both are empty, so nothing seeds anything and no region is derivable. There is no cut-graph bootstrap.**

This is not an implementation slip. `DESIGN.md` §7.2's normative derivation is:

> 1. create ports from every cross-field singularity …
> 2. create mandatory graph edges from hard features and source boundaries …
> 3. trace the designated field branch from every singularity port …
> 8. extract the faces of the embedded graph;
> 9. emit those faces as topology regions.

On this witness steps 1–3 produce nothing and step 8 extracts nothing. And `DESIGN.md` §4.6 is explicit that the motorcycle graph's size is *"`O(n)` in the number of extraordinary nodes"* — with **zero** extraordinary nodes the graph is empty and there are no cells. This is the classical degenerate case: a singularity-free torus needs a **seam / cut graph** that singularities cannot supply.

**`DESIGN.md` §7.2 has no clause for it.** That is a normative gap, and it is **not CP4c-1's to fix** — see §8.

---

## 4. E4 — the mechanical A1 failure: my hypothesis withdrawn, localization corrected

Measured: source Euler **2**, boundary loops **0**, genus **0**, **152** interior local vertices, one source topology region; A1 rejects **`IncompleteCycleBasis`** with **topology region `0`** and **source edge `0-3`**.

Last turn I hypothesised the cardinality check
`expectedCycleCount = interiorVertices + boundaryLoops + 2·genus` (`FieldTransportAtlas.cpp:1556-1562`).

**That hypothesis is withdrawn.** It does not survive the evidence: that site calls `fail(..., std::nullopt, ...)` and carries **no edge locus**. The observation carries `source edge 0-3`, so the rejection came from one of the sites inside the per-cycle directed-edge loop that *do* pass an edge:

| Site | Condition |
|---|---|
| `FieldTransportAtlas.cpp:1628-1630` | the cycle references an edge with **no `FieldTransportAdjacency`** |
| `FieldTransportAtlas.cpp:1633-1637` | `local->mesh.EF(localEdge, 0) < 0` or `EF(localEdge, 1) < 0` — the **local** mesh sees this edge as a boundary edge |

The second is the more interesting candidate: the source mesh is **closed** (0 boundary edges, confirmed by direct computation), so a local chart reporting a boundary edge would mean the local extraction produced a bounded sub-mesh where the source has none.

**Corollary that matters for planning:** because the locus is edge-specific rather than a cardinality mismatch, this failure may be **mesh-specific rather than closed-surface-class-wide**. That materially improves the outlook for §6's proposal. It is a hypothesis with a named discriminator (Y2), not a conclusion.

The torus **passed** A1 despite being closed and genus 1, which independently argues against "closed surfaces break A1" as a class statement.

---

## 5. E6 — the real CP4c-1 blocker

C4 and C5 need a terminal `TraceIntersection`: a trace that stops because it ran into another trace. Current authorized union:

| Witness | Reaches | Terminal kinds contributed |
|---|---|---|
| two-ring skew disc | A2b | `MandatoryBarrierTermination` only — all three traces hit the outer ring |
| torus | A2a, empty network | **none** — 0 traces |
| mechanical feature | fails at A1 | **none** |

So the union is `{MandatoryBarrierTermination}` and C5's `ASSERT_EQ(2U, …)` fails truthfully.

**The significance is larger than CP4c-1.** `DESIGN.md` §4.6 names crash-on-contact as the mechanism that delivers *"termination and cleanliness by construction"* and *"disc topology by construction"*, and §7.2 invariant 4 requires trace intersections to create explicit graph nodes. On the evidence in front of us, **no committed witness has ever exercised a terminal trace/trace contact.**

Note the distinction precisely, because it is easy to get wrong: `TraceIntersection` events **are** produced on the two-ring witness — `finalize_field_aligned_events` emits one at a multi-port singularity node with all incidences `Interior`. What has never been produced is a `TraceIntersection` carrying a **`Terminal`** incidence. C4 searches for exactly that, which is why it fails before it can tamper anything. The `field_aligned_first_trace_contact` branch of `finalize_field_aligned_events` is, on present evidence, **unexercised by any accepted witness**.

C4/C5 are therefore doing precisely their job: they are the first identities to demand that the architecture's central primitive be witnessed.

---

## 6. E7 — the witness, derived from a full census

I computed topology directly from every committed `.obj`:

| Fixture | V | E | F | χ | boundary edges | class |
|---|---:|---:|---:|---:|---:|---|
| `plane` | 20 | 43 | 24 | 1 | 14 | disc |
| `multi_face_seam` | 25 | 56 | 32 | 1 | 16 | disc |
| `close_sheets` | 32 | 66 | 36 | 2 | 24 | two discs |
| `cylinder` | 80 | 208 | 128 | 0 | 32 | annulus |
| `thin_bent_tube` | 132 | 372 | 240 | 0 | 24 | annulus |
| `torus` | 72 | 216 | 144 | 0 | 0 | **closed genus 1** |
| `mechanical_feature` | 152 | 450 | 300 | 2 | 0 | **closed genus 0** |
| `bunny_1k_random` | 502 | 1500 | 1000 | 2 | 0 | **closed genus 0** |
| **`sphere_prescribed`** | **98** | **288** | **192** | **2** | **0** | **closed genus 0** |

### 6.1 `sphere_prescribed` is structurally forced to satisfy C4 and C5

`benchmarks/fixtures/milestone-g/sphere_prescribed.fieldmeta.json` declares:

```json
"singular_indices":  [1,1,1,1,1,1,1,1],
"singular_vertices": [0,8,21,24,25,34,45,49]
```

- **8 singularities, each index numerator 1.** Σ index = 8 quarter-turns = **2 = χ(sphere)** — Poincaré–Hopf satisfied exactly, so the declared field is consistent and the singularities are real.
- Port count per singularity is `4 − index = 3`, so **24 ports and 24 traces**.
- The mesh is **closed**: no source boundary, therefore **no `Boundary` mandatory edges**, and a smooth sphere carries no hard features.

`finalize_field_aligned_events` has exactly three terminal branches: trace/trace contact, mandatory-barrier termination, and loop closure. **With no barriers, the barrier branch is unreachable**, so every one of the 24 traces *must* terminate by contact or loop closure. With 24 traces on 192 faces, contact is essentially forced.

**This is not a hopeful witness choice. It is a structural guarantee**, and it is the first witness in the repository that makes crash-on-contact unavoidable.

### 6.2 It is reuse, not authoring

`DESIGN.md` §12's verification matrix names *"cylinder, torus, **prescribed sphere**"* as representative witnesses for the periodic/singularity-transport row. `sphere_prescribed` is DESIGN-named and committed with mesh, rawfield, and declared field metadata. DEFN §8.1's *"reuse; do not author"* is satisfied.

### 6.3 The one real risk, and how it is handled

`sphere_prescribed` is closed genus 0 — the **same class** as `mechanical_feature`, which fails A1. It may fail identically.

**That must be measured before anything is asserted on it, not assumed.** §4 gives grounds for optimism (edge-specific locus, and the closed genus-1 torus passes A1), but grounds for optimism are not evidence. Y1 measures it with a non-gating identity **in the same CB turn** that adds it, so one TB settles both questions.

---

## 7. Corrective measures — series **Y**

### Y0 — binding preconditions

Each is a stop condition. If one does not hold, stop and return to review; do not adapt in place.

- **Y0.1** Confirm the four `sphere_prescribed` facts independently before relying on them: the mesh is closed with **0 boundary edges** and χ = **2**; `sphere_prescribed.fieldmeta.json` declares **8** singular vertices each with index numerator **1**; the sum 8 × 1 quarter-turns equals **2 = χ**; `sphere_prescribed.obj` and `sphere_prescribed.rawfield` are both committed under `benchmarks/fixtures/milestone-g/`. If any differs, **stop**.
- **Y0.2** Do **not** modify C4 or C5's assertion logic, the witness-union mechanism, `record_terminal_event_contract`, or `terminal_kind_contributors`. X3 is correct.
- **Y0.3** Do **not** modify `SurfaceCellTracing.cpp`, `GlobalTopologyPlan.cpp`, `FieldTransportAtlas.cpp`, `RemeshPipeline.cpp`, or any accepted expectation. Y1–Y3 are **test-side only**.
- **Y0.4** Do **not** hand-author a mesh or a field, do not synthesise a trace contact, and do not construct a `FieldAlignedCurveNetwork` by hand to satisfy C4/C5. The union must be fed by a real production witness.
- **Y0.5** Do **not** attempt the torus or mechanical fixes. They belong to `M3-CP4c-2-DEFN` and `M3-CP4c-3-DEFN`, which remain blocked.

### Y1 — add `sphere_prescribed` as a non-gating reachability observation

Add one **non-gating** identity, alongside the two that already exist:

- `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable`

Implement it by calling the existing generic helper — `observe_cp4c_witness("sphere_prescribed", "prescribed sphere")` — which already reports, without asserting success: source Euler / boundary-loop count / genus / interior vertex count; whether `sourceTopologyRegions`, `fieldTransportAtlas`, `fieldAlignedCurveNetwork`, and `globalTopologyPlan` were published; the exact typed rejection and locus at the first stage that fails; and, when A2a is reached, `networkTraceCount` and `networkEventCount`.

**Extend the observation** — for this witness and the existing two — with the two facts C4/C5 actually depend on, which the current report does not print:

- the count of events whose kind is `TraceIntersection` **and** which carry at least one `Terminal` incidence;
- the set of produced terminal event kinds, with the trace ids that contributed each.

Register it in the non-gating selector. It is expected to fail (it reports by failing); its failure is excluded from the gate count.

### Y2 — extend the mechanical observation to discriminate the two A1 candidates

The mechanical diagnostic currently reports `IncompleteCycleBasis` with `source edge 0-3`. Extend it so the next run distinguishes §4's two candidate sites without guessing:

- report whether a `FieldTransportAdjacency` exists for the failing source edge (`:1628` candidate);
- report the local mesh's `EF` row for that edge, i.e. whether either incident face index is negative (`:1633` candidate);
- report the local sub-mesh's vertex/face/boundary-edge counts, so a bounded local chart on a closed source is visible directly.

Non-gating, same as Y1. **Do not fix anything in `FieldTransportAtlas.cpp`** — this is measurement for `M3-CP4c-3-DEFN`.

### Y3 — admit `sphere_prescribed` to the C4/C5 witness union

In `EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced` and `RejectsTamperedTraceIntersectionCrossing`, add the prescribed sphere to the union using the **same guarded pattern** already there:

```cpp
const Cp4cReachabilityObservation sphere =
    observe_cp4c_witness("sphere_prescribed", "prescribed sphere");
…
if (sphere.sourceAuthority && sphere.atlas && sphere.network) {
  record_terminal_event_contract(
      EventWitnessView{"prescribed sphere", &sphere.mesh, &*sphere.sourceAuthority,
                       &*sphere.atlas, &sphere.rails, &*sphere.network},
      producedTerminalKinds, contributors);
}
```

and include `sphere.report` in the failure message beside `torusReachability` and `mechanicalReachability`.

For **C4** specifically: the tamper must be applied to the witness that actually produced the terminal `TraceIntersection`. Select the contributing witness by searching the union rather than assuming the two-ring fixture, and tamper that witness's `validation_candidate()`. The expected rejection remains `InvalidNetworkEventIncidence` — **do not change it**.

**Add a self-asserted precondition** on the sphere witness, in the DEFN §8.2 style, before its contribution is credited: the published network has **≥ 1 singularity port**, **≥ 2 traces**, and **zero mandatory edges** (the last is what makes contact-termination structurally forced). If the precondition fails, the identity must fail with that message rather than silently skipping.

### Y4 — the gate is unchanged

`M3-CP4c-1` still gates at **318 = accepted 316 + C4 + C5**. The accepted 316 prefix must remain byte-identical and must not be regenerated. Non-gating identities go to **three**: torus, mechanical, sphere. Report both counts separately, as this TB already does correctly.

### Y5 — falsifiable predictions

State these in the CB report and check them at TB. If a prediction fails, the next turn is another review, not a fix.

1. `sphere_prescribed` reaches **A1** — `fieldTransportAtlas` is published. *If it fails with `IncompleteCycleBasis`, §4's "mesh-specific" reading is wrong, the failure is closed-genus-0-class-wide, and C4/C5 have no available witness — escalate to §8.*
2. `sphere_prescribed` reaches **A2a** with `networkTraceCount` = **24** and `networkEventCount` > 0.
3. Its network publishes **zero** mandatory edges.
4. At least one event is a `TraceIntersection` carrying a `Terminal` incidence.
5. Therefore **C4 and C5 pass**, and `M3-CP4c-1-TB` returns **318/318**.
6. The accepted 316 prefix remains **316/316**.
7. The torus and mechanical non-gating observations are **unchanged** from this run — `UncutFaceComponentOrbitSeedNotUnique` at `sourceFace=0-1-2`, and `IncompleteCycleBasis` at `source edge 0-3`. *A change here would mean Y1–Y3 perturbed something they must not touch.*

Prediction 2's exact count of 24 follows from 8 singularities × (4 − 1) ports. If the observed port count differs, the declared metadata and the atlas disagree, which is itself a finding — **report it, do not adjust the expectation.**

---

## 8. E8 — the escalation that CP4c-1 must not absorb

Two questions are now open at a level above this checkpoint. Both are recorded here and **owned elsewhere**:

**8.1 — `DESIGN.md` §7.2 has no closed-surface cut-graph clause.** §7.2 derives the network from singularities, features, and boundaries. On a closed surface with an index-free field there are none of the three, and §4.6's motorcycle graph is empty because it is `O(n)` in extraordinary nodes. Quad-remeshing a torus requires a seam that the current derivation cannot produce. **Owner: `M3-CP4c-2-DEFN`.** It must decide whether to add a cut-graph/seam step to §7.2, whether the torus witness should instead carry a field with cancelling singularities, or both — and it must answer before any code is written against genus > 0.

**8.2 — the crash-on-contact primitive has no accepted witness.** `field_aligned_first_trace_contact` and the contact branch of `finalize_field_aligned_events` appear to be unexercised by every witness in the accepted 316. If Y1–Y3 succeed, CP4c-1 closes that hole and it becomes a historical note. **If prediction 1 fails, this becomes the dominant open risk in M3** and must be escalated in the next review rather than worked around.

Neither may be used to widen CP4c-1. Its scope stays exactly: diagnosability, witness observability, event non-vacuity.

---

## 9. Accounting and exact successor

- accepted runtime authority: **M3 CP4ab 316/316**, source/package `157bf784… / 9527801615`
- CP4c-1 gate: **318 = 316 + C4 + C5**, unchanged
- non-gating diagnostics: 2 → **3** under Y1
- budgets: **none** — abolished 2026-08-25; this red consumed nothing
- stable regression accounting: **42 events / 14 categories / 28 recurrences** — unchanged, no accepted identity regressed
- produced-witness debt: **5**
- M3 package count: **37** after the CP4c-1 CB
- `M3-CP4c-2-DEFN` and `M3-CP4c-3-DEFN`: **blocked** until CP4c-1 closes

**Exact next: `M3-CP4c-1-CB2`** — Code + Build only, runtime forbidden. Execute Y0's preconditions and obey every stop condition, then Y1, Y2, Y3, Y4, and record Y5's predictions. Test-side only: no production translation unit may change. Compile and package; execute nothing. Then `M3-CP4c-1-TB-R2` on the **318** gate plus three non-gating identities.

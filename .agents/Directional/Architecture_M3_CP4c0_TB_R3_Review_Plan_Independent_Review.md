# M3-CP4c-0-TB-R3 — Independent Review and Corrective Plan

Turn: `M3-CP4c-0-TB-R3-REVIEW-PLAN`. Review and planning only.
**No product source, test source, fixture, selector, build configuration, or runtime was modified or
executed in this turn.** Evidence was read; nothing was run.

Brief: the TB-R3 review brief, retired into `M3_CP4c_Consolidated_Record.md`.
Evidence: the CB3 build report (retired into `M3_CP4c_Consolidated_Record.md` §3) and TB-R3 run
`32921851098 / 98036868098`.
Contract: `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` (as amended, Amendments 1–6).

---

## 0. Verdict, stated first

**Both red identities are test-side defects. Neither is a production defect. Production is correct at
both sites, and I can prove it from source rather than infer it.**

1. **Ordinal 333** (`ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`) throws
   `"compute_edge_quantities(): DCEL consistency check failed"` **before the predicate under test ever
   runs**. The cause is not near-degenerate coordinates — it is that the fixture builds a
   **single-triangle mesh**, and `DCEL::check_consistency`'s `checkPureBoundary` rejects any face with
   no interior edge. **Every candidate in that search family is DCEL-invalid**, which is why it failed
   at 0 ms on the first one. §2.
2. **Ordinal 334** (`ExactVertexSectorPartitionsAcceptedInteriorFans`) is an **oracle defect, and the
   oracle is mine.** A numeric `FieldBranch` does **not** name the same physical direction across
   faces: `build_face_branch_frame` assigns each face its own **gauge** against that face's canonical
   reference edge. My E8 spec said "for every `(vertex, branch)` fan, assert the exact predicate admits
   exactly one face", which embedded a false cross-face identity premise. §3.
3. **Production already handles the gauge correctly**, and `build_branch_transports` proves it: it
   corrects every lift by `rawGauge[first] − rawGauge[second]`. Cross-face branch comparison in
   production always goes through that corrected `signedLift`. **No production change is warranted by
   either failure.** §4.
4. **My P2 prediction was wrong and I own it.** I predicted 330–337 all green. 333 and 334 went red.
   Both premises that failed are identified in §5, and both are the same species of error: I audited
   the *assertions* without auditing the *preconditions the fixture needs to reach them*.
5. **The most important finding is not either red identity.** The supplemental falsifier
   `TracingPathNeverPublishesSeedIdentityAsFailureLocus` contains `ASSERT_FALSE(networkBuild)` and it
   **passed** — which is direct runtime proof that **the prescribed sphere still does not publish a
   network**. Q8 will therefore fail on the next TB even if all 338 go green. Nothing in the TB report
   or the brief surfaces this. §7.
6. And **nothing in the frozen gate publishes the sphere's current rejection code**, so we still cannot
   name it. That gap is now avoidable and §8 closes it.

Corrective series **G0–G8** in §11.

---

## 1. Independent verification of the evidence — CONFIRMED

Re-verified against the GitHub API, the runner's own log, and git during this turn.

| Claim | Verified |
|---|---|
| run `32921851098`, head SHA `faf84aff4e7a64a3771e863199b82bd00425c318` | ✅ |
| result artifact `9590143527` SHA-256 `af4f5b28…d216604` | ✅ exact, API **and** runner-computed |
| log artifact `9590143871` SHA-256 `ec9c29b7…2b08f5b7` | ✅ exact, API **and** runner-computed |
| package `9589508430` SHA-256 `7bb4bd1a…97693015` | ✅ as env in the job |
| semantic source `b135e219ee9269a73eaee32992d80c3921318011` | ✅ exists, ancestor of `HEAD` |
| selector **338**, SHA-256 `d588cae0…` | ✅ **recomputed locally** |
| 316-prefix `601ce2b6…`, 328-prefix `cf93622e…` | ✅ **recomputed locally**, both byte-identical to accepted authority |
| all mutation/build flags false | ✅ read from the job log |

**The four files this review audits — `FieldTransportAtlas.cpp`, `FieldAlignedCurveNetworkTests.cpp`,
`TriMesh.h`, `DCEL.h` — are byte-identical (SHA-256) between my working tree and the packaged semantic
source.** Every source finding below is a finding about the immutable package.

**Runtime facts, read from the job log directly rather than from the report:**

```
gate=SEMANTIC_RED   executed=338   passed=336
prefix316_passed=316   prefix328_passed=328   correction10_passed=8
failure_kind=test-failure   failure_ordinal=333
supplemental_gate=PASS   supplemental_executed=2   supplemental_passed=2
q8_creditable=false   q8=NOT_RUN
```

**F6 is runtime-proved.** All 338 executed despite a red at 333 — the continue-and-observe change I
prescribed last turn worked exactly as intended, and it is the only reason we know 334 is also red and
that 335–338 pass. Had F6 not landed, this cycle would have returned one bit of information instead of
the complete picture below.

**F1 and F2 are runtime-proved** (R3's second question): ordinals 329–332 green, both supplementals
green. The `std::uint8_t` defect and the seed back-fill class are closed.

---

## 2. R1 — ordinal 333, fully diagnosed from primary evidence

### What actually happened

From the job log, verbatim:

```
[ RUN      ] ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip
unknown file: Failure
C++ exception with description "compute_edge_quantities(): DCEL consistency check failed" thrown in the test body.
[  FAILED  ] ...AcrossLossyRoundTrip (0 ms)
```

An **uncaught C++ exception**, at **0 ms**. Not an assertion failure. The predicate under test never ran.

### Why

The test's search loop builds, per candidate:

```cpp
Eigen::MatrixXd vertices(3, 3);   // three vertices
Eigen::MatrixXi faces(1, 3);      // ONE face
faces << 0, 1, 2;
TriMesh mesh;
mesh.set_mesh(vertices, faces);           // ← throws here
...
if (!std::isfinite(det) || det <= 1.0e-10) continue;   // ← screen is AFTER
```

`TriMesh::set_mesh` → `compute_edge_quantities()` (`include/directional/core/TriMesh.h:145-163`):

```cpp
dcel.init(V, F);
if (!dcel.check_consistency(verbose, true, true, true)) {
  throw std::runtime_error("compute_edge_quantities(): DCEL consistency check failed");
}
```

Only four arguments are passed, so `checkGeometricDegenerates` and `checkTwinAdjacency` take their
`true` defaults, and `checkPureBoundary` is explicitly `true`. That check
(`include/directional/core/DCEL.h:1546-1565`) is:

```cpp
if (!hasInteriorEdge)
  return fail("face is composed entirely of boundary edges", faceIndex);
```

**A single-triangle mesh has exactly one face and all three of its halfedges are boundary
(`twin == -1`). It therefore has no interior edge, and `set_mesh` throws — always, for every
coordinate choice.**

### The sharpest correction to the brief's hypothesis

R1 asked whether "the near-degenerate search family includes DCEL-invalid candidates." That is *true
but understates it*: **every** candidate is DCEL-invalid, because they are all one-face meshes. The
near-degenerate coordinates are a **red herring**. This matters directly for the fix — changing `base`,
`spacing`, or the epsilon family would repair nothing. The 0 ms timing is independent confirmation: the
throw happens on the very first candidate, before any search has occurred.

### Classification

**Test fixture/harness defect. Not production.** `direction_in_vertex_sector` was never reached, so this
identity currently provides **zero evidence either way** about the lossy-round-trip property it was
written to falsify. That property remains **unproven**, not disproven — an important distinction, since
the round trip it guards against is the mechanism the previous review identified as the widened `β`
band.

### What the corrected fixture must satisfy

- **At least one interior edge.** The minimum is two triangles sharing an edge. The predicate under test
  (`direction_in_incident_vertex_sector`) evaluates a *single* face, so a full fan is not required —
  only DCEL validity.
- **Screen before constructing.** Compute the Gram determinant from the raw coordinates and `continue`
  *before* calling `set_mesh`, so no invalid candidate is ever handed to the mesh constructor.
- **Preserve the original falsification.** The witness must still be one where the `double`
  round-trip recovers `β > 0` while the published exact `d[prev] < 0`, and must still assert
  `EXPECT_FALSE(direction_in_vertex_sector(...))`.
- **Do not** catch the exception, weaken the expectation, or introduce a tolerance.

---

## 3. R2 — ordinal 334, and the gauge

### What actually happened

Three sub-failures, from the job log:

| branch | expected admitted | actual admitted |
|---|---|---|
| 0 | 1 | **0** |
| 1 | 1 | 1 (pass) |
| 2 | 1 | **0** |
| 3 | 1 | **3** |

### The mechanism — `FieldBranch` is gauged per face

`build_face_branch_frame` (`src/authority/FieldTransportAtlas.cpp:190-270`) does this, per face:

```cpp
const auto reference = normalized_projected(p1 - p0, normal);   // p0,p1 = canonical topology key
const std::array<Eigen::Vector3d, 4> rawDirections{*primary, *secondary, -*primary, -*secondary};
// gauge = argmin over raw of positive_oriented_angle(reference, raw, normal)
...
const int raw = normalized_quarter_turn(gauge + semantic);
```

So **semantic branch `s` maps to the raw direction `(gauge + s) mod 4`, where `gauge` is chosen relative
to that face's own canonical reference edge and its own canonical-order normal.** Two faces with
different reference edges get different gauges, and the *same numeric branch is then a different
physical direction on each*.

Note also that `normal` is computed from the **canonical (sorted)** vertex order, which does not
preserve mesh orientation — one of the fan's four faces genuinely gets an anti-parallel normal. So the
gauge varies with two independent per-face quantities.

### The model, verified exactly against the runtime numbers

`make_four_triangle_fan` is the square `[−1,1]²` with centre vertex 4 at the origin;
`make_zero_transport_field` sets primary `= +X`, secondary `= +Y`, so `rawDirections = {+X, +Y, −X, −Y}`
on every face. Working the reference edge and normal for each canonical key:

| Face (canonical key) | reference | normal | gauge | sector at v4 admits |
|---|---|---|---|---|
| `(0,1,4)` | `+X` | `+Z` | **0** | `−Y` |
| `(1,2,4)` | `+Y` | `+Z` | **1** | `+X` |
| `(2,3,4)` | `−X` | `+Z` | **2** | `+Y` |
| `(0,3,4)` | `+Y` | **`−Z`** | **1** | `−X` |

Semantic branch `s` on face `F` is `raw[(gauge_F + s) mod 4]`. Counting admissions:

| s | face `(0,1,4)` | `(1,2,4)` | `(2,3,4)` | `(0,3,4)` | admitted |
|---|---|---|---|---|---|
| 0 | `+X` ✗ | `+Y` ✗ | `−X` ✗ | `+Y` ✗ | **0** |
| 1 | `+Y` ✗ | `−X` ✗ | `−Y` ✗ | `−X` ✓ | **1** |
| 2 | `−X` ✗ | `−Y` ✗ | `+X` ✗ | `−Y` ✗ | **0** |
| 3 | `−Y` ✓ | `+X` ✓ | `+Y` ✓ | `+X` ✗ | **3** |

**`0, 1, 0, 3` — matching the observed runtime exactly on all four branches.** The model is confirmed,
including the anti-parallel normal on `(0,3,4)`: had that face's gauge been `3` instead of `1`, branch 3
would have admitted 4 rather than the observed 3.

### Classification

**Oracle defect, and the false premise is in my own E8 specification.** The identity iterates
`branchValue = 0..3` and asks every face about *that same numeric label*, which is four different
physical directions. Counting "exactly one admitted" across them is not a fan-partition test at all.
Branch 1 passing was coincidence.

Ordinal 332 (`ExactVertexSectorRejectsToleranceBandAndSelectsUniqueFace`) passed because it constructs
`FieldBranchDirection` values **by hand per face** and never consults the atlas, so no gauge is
involved. The contrast between 332 green and 334 red is itself evidence for the diagnosis.

### The correct oracle

A fan-partition test must compare **one transported physical direction**. The atlas already publishes
what is needed: walk the fan from a chosen `(startFace, branch)` applying
`FieldBranchTransportAdjacency::signedLift` at each step — which is exactly what
`resolve_field_vertex_transit` does in production — and assert exactly one face admits its transported
branch.

Because that reuses production's own transport, it should be paired with an **independent** check on the
gauge correction so the test is not circular. The natural one is local holonomy: **the composed
`signedLift` around a complete vertex fan must be `≡ 0 (mod 4)` at a regular vertex and `≡ index` at a
singularity.** That is Poincaré–Hopf stated locally, it uses no geometry, and a broken gauge correction
would break it.

---

## 4. Production is correct — and the source proves it

Before prescribing anything, the obvious worry: if numeric branches are not comparable across faces,
does production ever compare them without transporting?

**No.** `build_branch_transports` (`src/authority/FieldTransportAtlas.cpp:305-320`) explicitly corrects
for the gauge when publishing every adjacency:

```cpp
const int canonicalLift =
    adjacency.forwardLift + rawGaugeByRow[adjacency.firstFace.index()] -
    rawGaugeByRow[adjacency.secondFace.index()];
```

The published `signedLift` is therefore a **semantic** lift that already accounts for both faces'
gauges. And every cross-face branch step in production goes through it:

- the trace loop: `currentBranch.rotated(directed->signedLift)`;
- `resolve_field_vertex_transit`: `state.second.rotated(directed->signedLift)`;
- the singularity fan partition: `incidences[sourceIndex].branch.rotated(directed->signedLift)`.

Nowhere does production assume a bare numeric branch is portable. **The gauge correction existing at all
is itself source-level proof that branch labels are per-face**, which is precisely the fact my oracle
spec overlooked.

**Conclusion: no production measure is authorized by ordinal 333 or ordinal 334.** Both corrections are
test-side.

---

## 5. R3 — my falsified P2 prediction, owned

Last turn I predicted: *"Identities 330–337 go green in the same run."* Runtime falsified that at 333 and
334. The premises that were wrong:

**Premise 1 (ordinal 333): "333 will pass; its only caveat is that it *searches* for its witness rather
than constructing one."** I identified the right identity as the fragile one and then drew the wrong
conclusion from it. I reasoned about whether the search would *find* a witness, and never asked whether
the candidate meshes were **constructible at all**. The failure is one layer below where I was looking:
not the search, the mesh.

**Premise 2 (ordinal 334): "the four faces' directions for a fixed branch are the same world vector."**
I verified the *geometry* of the fan by exact hand computation — correctly; the ±1/2 barycentric values
in my previous review are right — but I verified it for a **single physical direction `+X`**, and then
assumed identity 334 was asking that question. It was not. I never read `build_face_branch_frame`, so I
never learned that branch numbering is gauged.

**The common root, and it is the same one this project keeps paying for:** I audited what each identity
*asserts* and did not audit the *authority the identity consumes to get there*. A prediction about a
test is a prediction about its whole precondition chain, not about its `EXPECT` line. Both misses were
one `grep` away.

**Why the accepted predecessor prefix is unaffected.** Both defects are confined to two identities added
by the correction series. Ordinal 333 throws inside its own fixture; ordinal 334's oracle consults the
atlas read-only. Neither touches production code paths, and the runtime confirms it:
`prefix316_passed=316` and `prefix328_passed=328` in the same run. Nothing accepted regressed.

**Correctly predicted last turn, for the record:** 330, 331, 332, 335, 336, 337 green; both supplementals
green; the accepted prefixes green; identity 338 green (P3); and that a red 338 would not be
`BranchContinuationDegenerateEntry` (moot — 338 passed).

---

## 6. R4 — identity 338, read precisely

Identity 338 (`AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections`) **passed** as a
non-crediting observation.

**What it re-proves:** on the two-ring fixture, the four-triangle fan, and the prescribed sphere, A2a
publishes neither `BranchContinuationDegenerateEntry` nor `BranchContinuationOutsideOutflowSet`. That is
the direct machine statement of the previous review's Theorems 1–3, and it means the **E2–E5
exactification genuinely removed the failure family that blocked `M3-CP4c-0-TB`**. The sphere's original
`BranchContinuationDegenerateEntry` at edge `6-8` is gone. This is real progress and should be recorded
as such.

**What it does not prove, and must not be read as:** it is written
`if (!sphereNetwork) { EXPECT_NE(...); }`, so it is green whenever the sphere fails with **any other
code**. It says nothing about whether a network is published. It is **not** gate credit (it ran after a
red) and it is **not** Q8.

---

## 7. The finding that outranks both red identities

The supplemental falsifier `TracingPathNeverPublishesSeedIdentityAsFailureLocus` — which **passed** —
contains:

```cpp
const auto networkBuild = FieldAlignedCurveNetwork::make(
    sphere.mesh, *sphere.sourceAuthority, *sphere.atlas, sphere.rails);
ASSERT_FALSE(networkBuild);
```

A passing `ASSERT_FALSE(networkBuild)` is **direct runtime proof that the prescribed sphere still fails
to publish a `FieldAlignedCurveNetwork`** at the CB3 package.

Two consequences, neither of which appears in the TB report or the brief:

**(a) Q8 will fail on the next TB even if all 338 go green.** Q8 requires the sphere to publish 24
traces with a terminal `TraceIntersection` and the crossover flip. Fixing ordinals 333 and 334 turns the
gate green and then Q8 stops immediately. **Planning the successor as "fix the two tests and Q8 closes"
would be wrong**, and that is the natural reading of the current TB report.

**(b) A required supplemental falsifier now encodes current production output as an expectation.**
`ASSERT_FALSE(networkBuild)` will go **red at exactly the moment CP4c-0 succeeds**. That is the
"encode current production output" anti-pattern the project prohibits, sitting inside a mandatory
corrective falsifier. It must be restructured *before* the sphere is fixed, or it will block acceptance
for precisely the wrong reason.

This is partly my F3 spec's fault: I asked for a falsifier that "drives the tracing path to each
reachable typed rejection", and CB3 reasonably implemented that against the sphere's live failure. The
spec should have required the seed-provenance property to be proved on a **constructed** failure whose
existence the test controls, not on whichever failure production currently happens to produce.

---

## 8. The missing datum, and it is now avoidable

**Nothing in the frozen 338 gate or either supplemental publishes the sphere's current A2a rejection
code.** Identity 338 and the supplemental both print `network_error_locus` only *on failure*, and both
passed. So after a full 338-identity run we still cannot name why the sphere fails.

We know only what it is **not**: not `BranchContinuationDegenerateEntry`, not
`BranchContinuationOutsideOutflowSet` (338), not `InvalidCandidateTraceBinding` (supplemental) — and
that it carries `traceSeedVertex`/`traceSeedSingularity`, so F2's provenance is working.

This is the **third consecutive cycle** in which the sphere's decisive datum was computed at runtime and
not published — first the entry parameter, then the branch locus, now the rejection code itself. The
observability probe that would publish it,
`GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable`, **exists** but is
deliberately excluded from the selector because it contains an unconditional `FAIL()`.

The project already has the right instrument for this: the **non-gating diagnostic identity** — executed
and reported, excluded from the gate count, carrying a written rationale. Measure **G5** applies it.

---

## 9. Normative amendment 7 to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`

**Added to §9 (ownership) and §4.4, normative.**

> **`FieldBranch` is a per-face gauged label, not a portable direction identifier.**
>
> `build_face_branch_frame` assigns each face a `gauge` by choosing, among
> `{primary, secondary, −primary, −secondary}`, the raw direction with the smallest positive oriented
> angle from that face's **canonical reference edge** (`v0→v1` of its canonical topology key), measured
> about a normal computed from the **canonical vertex order** — which need not agree with mesh
> orientation. Semantic branch `s` then denotes `raw[(gauge + s) mod 4]`.
>
> **Consequences, all normative:**
>
> 1. The same numeric `FieldBranch` on two faces is **not** the same physical direction in general.
> 2. The only sanctioned way to relate branches across faces is the published
>    `FieldBranchTransportAdjacency::signedLift`, which `build_branch_transports` has already corrected
>    by `rawGauge[first] − rawGauge[second]`. Production is compliant at every site.
> 3. **Any test, oracle, or diagnostic that compares, aggregates, or iterates a branch label across more
>    than one face without applying that lift is ill-formed**, regardless of whether it currently passes.
>    Ordinal 334 is the worked example: it produced `0, 1, 0, 3` admitted faces where a partition would
>    give `1, 1, 1, 1`, and its branch-1 pass was coincidence.
> 4. A cross-face oracle built on the published lift must be paired with an **independent** check on the
>    gauge correction, so it is not merely consistent with the mechanism it is testing. The sanctioned
>    one is local holonomy: composed `signedLift` around a full vertex fan `≡ 0 (mod 4)` at a regular
>    vertex, `≡ index` at a singularity.
>
> **Also added, to §10's proof rules:** a required falsifier may not assert the *existence* of a current
> production failure. Asserting that a witness fails to build encodes current output as an expectation
> and inverts the gate at the moment the defect is fixed. Prove such properties on a **constructed**
> failure the test controls; where a production witness is also exercised, its branch must be
> conditional.

---

## 10. Falsifiable predictions

- **P1.** Giving ordinal 333 a DCEL-valid witness (≥ 1 interior edge) and screening before `set_mesh`
  turns it green, and the lossy-round-trip property it asserts will then hold — the exact rule follows
  `pairing.direction`, so `EXPECT_FALSE` is satisfied by construction once the predicate is reached.
- **P2.** Rewriting ordinal 334 to walk the fan through `signedLift` turns it green **without any
  production change**, and the holonomy check added alongside it passes on the four-triangle fan
  (regular centre vertex ⇒ composed lift `≡ 0 mod 4`).
- **P3.** With G1–G3 landed, the next TB reaches **338/338 green** and supplemental **green**.
- **P4.** **Q8 then fails**, because the sphere does not publish a network (§7). This is a *prediction of
  failure* and is the reason G5 exists: the next TB must at minimum tell us the rejection code.
- **P5.** The sphere's current code will be one of the typed rejections downstream of continuation —
  most plausibly `VertexTransitSectorUnresolved` (with an empty or ≥2 candidate set),
  `BranchTransportFlowDisagreement`, `TraceStepBudgetExhausted`/`TraceStateCycleDetected`, or a network
  event/terminal-ownership code. It is **not** the three already excluded. G5 settles it in one run
  instead of another review cycle.
- **P6.** The accepted **316** stay green — G1–G5 touch only test source and add one non-gating
  identity. Any accepted red is a stop condition and a finding for review.

---

## 11. Corrective measures — series **G**, one Code + Build turn (`M3-CP4c-0-CB4`)

**G0 — binding preconditions.**
Branch `agent/surface_cell_quad/p5-recover-bridge-healing`. Code + Build only; compile all eight
standard targets; **execute nothing**. **No production source change is authorized by this review** —
§4 establishes production is correct at both failure sites. Do not weaken T6, Q8, any accepted
expectation, or the sphere fixture. Do not retune `kBranchTopologyTolerance`. Do not change E2–E6
semantics. Do not reorder or shrink the frozen 338 selector; its three hashes must be unchanged and
republished.

**G1 — repair ordinal 333's witness construction.**
- Build a **DCEL-valid** candidate: at least two triangles sharing an interior edge. A single-triangle
  mesh can never pass `checkPureBoundary` (`DCEL.h:1546-1565`), so no coordinate choice fixes this.
- **Screen before constructing**: compute the Gram determinant from raw coordinates and `continue`
  before calling `set_mesh`, so no rejected candidate reaches the mesh constructor.
- Evaluate `direction_in_vertex_sector` on the triangle carrying the constructed direction, at the
  vertex the original test used.
- **Preserve the falsification exactly**: the witness must still be one where the `double` round trip
  recovers `β > 0` while published exact `d[prev] < 0`, and the assertion stays `EXPECT_FALSE`.
- Prefer a **deterministically constructed** witness over a search. If a search is retained, it must
  `ASSERT` that a witness was found, and every candidate it constructs must be DCEL-valid by
  construction.
- **Do not** catch the exception, weaken the expectation, or add a tolerance.

**G2 — replace ordinal 334's oracle (Amendment 7).**
- Choose one `(startFace, branch)` at the fan's centre vertex. Walk the incident fan, composing
  `FieldBranchTransportAdjacency::signedLift` at each step to obtain each face's **corresponding**
  branch — mirroring `resolve_field_vertex_transit`.
- Assert **exactly one** face admits its corresponding branch, and assert it for **each** of the four
  starting branches.
- **Do not** special-case the four-triangle fan, and **do not** touch production to satisfy the oracle.

**G3 — add the independent gauge check (Amendment 7 clause 4).**
A new identity asserting **local holonomy**: the composed `signedLift` around a complete vertex fan is
`≡ 0 (mod 4)` at a regular vertex and `≡ index (mod 4)` at a singularity. Exercise it on the
four-triangle fan and on the prescribed sphere's eight singularities (each of stored index 1). This is
what keeps G2 from being circular, and it would independently catch a broken gauge correction.

**G4 — de-encode the supplemental falsifier (§7).**
`TracingPathNeverPublishesSeedIdentityAsFailureLocus` must stop asserting that the sphere fails.
- Prove the seed-provenance property on a **constructed** failure whose existence the test controls, so
  the assertions are guaranteed to execute.
- If the sphere path is retained, make it **conditional** (`if (!networkBuild) { … }`) and add a
  separate constructed case that unconditionally exercises the property.
- **This must land before the sphere is fixed**, or it inverts and blocks acceptance at the moment
  CP4c-0 succeeds.

**G5 — publish the sphere's current A2a outcome as a non-gating diagnostic identity (§8).**
Add one identity that runs `FieldAlignedCurveNetwork::make` on the prescribed sphere and **emits**
`network_error_locus(error)` — code and every published locus — **or**, on success, the trace count and
terminal-event summary. It must:
- **always report**, never conditionally, so the datum appears whether the sphere passes or fails;
- be **non-gating**: excluded from the 338 count, conferring no credit, carrying a written rationale and
  this measure as its owning corrective measure;
- **not** contain an unconditional `FAIL()`, so it can safely live in the TB plan's non-gating set.
*Rationale:* this is the third consecutive cycle in which the sphere's decisive datum was computed and
not published. One non-gating identity ends that pattern permanently.

**G6 — reachability note for the retired premise.**
Annotate ordinal 334's replacement with a one-line comment recording *why* the naive per-branch loop was
wrong (per-face gauge), so the false premise is not reintroduced by a future edit.

**G7 — evidence recording.**
Record semantic source SHA **and** workflow control SHA, package id and SHA-256, and all three selector
hashes. Confirm the 316-prefix still equals `601ce2b6…`. (F7 is working — CB3 recorded both and
retroactively corrected CB2. Keep it.)

**G8 — successor TB-R4 plan.**
Rerun the **unchanged** 338 frozen selector in exact order, fresh process per identity, retaining F6
continue-and-observe after any first red. Then the two F3 supplementals, separately. Then the G5
non-gating diagnostic, reported but not counted. Q8 becomes creditable only at exact package integrity
**and** 338/338 **and** supplemental 2/2. **State in the plan that Q8 is expected to fail (P4)** and that
its value this cycle is the rejection code G5 publishes — so a red Q8 is read as planned progress, not
as a new defect.

---

## 12. Risk register

| # | Risk | Mitigation |
|---|---|---|
| 1 | G1 changes the witness enough to lose the round-trip falsification | G1 states the property that must survive; P1 is the check. If no DCEL-valid witness exhibits it, that is a finding for review, not grounds to weaken `EXPECT_FALSE` |
| 2 | G2 is circular — it tests transport using transport | G3 is the independent holonomy check, added for exactly this reason |
| 3 | Ordinal 334's red is mistaken for a production defect and A1 is "fixed" | §4 proves production is correct; G0 prohibits production change. The gauge correction at `FieldTransportAtlas.cpp:316-317` is the evidence |
| 4 | G4 deferred until "after the sphere works" | Then it inverts and blocks acceptance at the worst moment. G4 must land in CB4 |
| 5 | A green 338 read as CP4c-0 nearly closed | §7: the sphere still does not publish. P4 predicts Q8 red; G8 puts that in the plan up front |
| 6 | G5's identity drifts into the gate | G5 fixes it as non-gating with a written rationale and an owning measure, per the project's existing non-gating convention |

---

## 13. Review record

- **R1 — ordinal 333:** test fixture defect. **Single-triangle mesh** fails `DCEL::check_consistency`'s
  `checkPureBoundary`; `set_mesh` throws before the predicate runs and before the determinant screen.
  Coordinate-independent, confirmed by the 0 ms failure. The identity provides **no evidence** on its
  target property. **Confidence: high** (uncaught-exception text + both source sites read).
- **R2 — ordinal 334:** oracle defect, false cross-face branch-identity premise, **originating in this
  reviewer's E8 specification**. Gauge model derived from source and **verified exactly** against the
  observed `0, 1, 0, 3`. **Confidence: high.**
- **Production:** correct at both sites; `build_branch_transports` corrects every lift by the gauge
  difference, and all three cross-face branch steps in production use it. **No production measure
  authorized.**
- **R3 — falsified P2:** owned in §5. Both misses share one root — auditing what an identity asserts
  without auditing the authority it consumes to get there.
- **R4 — identity 338:** confirms E2–E5 removed the degenerate-entry family from the sphere. **Not** gate
  credit, **not** Q8, and **not** proof the sphere publishes.
- **Highest-value finding:** a passing `ASSERT_FALSE(networkBuild)` proves the sphere still does not
  publish a network, so **Q8 will fail next cycle regardless of the gate**; and that assertion will
  invert the moment CP4c-0 succeeds.
- **Standing gap closed:** G5 makes the sphere's rejection code observable on every run.
- **Successor:** `M3-CP4c-0-CB4`, measures **G0–G8**, Code + Build only, **test-side only**.
- **Mutation statement:** this review executed **no** runtime, **no** build, **no** benchmark, and made
  **no** change to product source, test source, fixtures, the selector, or build configuration. Its only
  writes are to durable documentation under `.agents/Directional/`.

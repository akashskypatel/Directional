# Architecture M3 CP4c TB-R1 — Independent Review

**Turn:** `M3-CP4c-TB-R1-INDEPENDENT-REVIEW`
**Type:** Independent Review / planning / evidence only — no product, test, fixture, selector, or build mutation; no compile, package, or runtime
**Evidence under review:** TB-R1 run/job `32791027809 / 97632461750` on immutable CB2 package `9541369624`, semantic source `a5edb1a31c315d51df216f3bb51470989ff64e33`
**Result under review:** **VALID RED 316/322** — accepted prefix 316/316 PASS, CP4c C1–C6 **0/6**

---

## 0. Dispositions

| # | Subject | Disposition |
|---|---|---|
| **D1** | Does DG execute a different runtime surface than TB? | **No.** DG's surface is a strict *subset* of TB's, under identical rules, producing identical evidence. The distinction was pure budget bookkeeping. §1. |
| **D2** | Attempt budget and DG turn type | **Both abolished.** Workflow becomes `CB → TB → (red) → REVIEW+PLAN → CB`. §2. |
| **D3** | C1 / C3 / C6 — torus | **Frozen-definition scope gap in accepted A2b authority.** Not a witness defect. A2b assumes every trace arc separates its two sides; that is a genus-0, bounded-surface assumption. The torus is **closed, χ = 0, genus 1**. §4. |
| **D4** | C2 — mechanical | **Accepted A1 authority fails on a surface class it has never been driven with.** `FieldTransportAtlas::make` rejects `IncompleteCycleBasis` — upstream of A2a entirely. Not CP4c-scope. §5. |
| **D5** | C4 / C5 | **Authored against a witness that provably cannot satisfy them**, and the proof was already in the durable record before CB2 ran. §6. |
| **D6** | CP4c as frozen | **Not executable.** The frozen `322 = 316 + C1–C6` must be reopened and CP4c split. §9. |
| **D7** | Blame | The plan is at fault, not CB2. CB2 implemented §7.1 correctly, including reading the new `globalTopologyPlan` slot rather than the legacy `traceNetwork`. §7. |

Stable accounting is unchanged at **42 / 14 / 28**; the six reds are first-acceptance candidates, not regressions. All 316 accepted identities are green **in the same immutable run**, which is the strongest possible evidence that CB1's production wiring did not regress accepted authority.

---

## 1. D1 — DG does not execute a different runtime surface than TB

This was asked directly, so it is answered from the two runs' own recorded evidence rather than from intent.

### 1.1 The selectors

| | DG1 (`32776212123`) | TB-R1 (`32791027809`) |
|---|---|---|
| predecessor 304 | `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666` | same |
| CP4ab 12 | `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec` | same |
| accepted 316 | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` | same, and TB-R1 §2 records *"the cumulative selector's first 316 entries are byte-identical to accepted authority"* |
| CP4c 6 | — | `c187acbadf238992d85e9dcfb0f5bf96916bbb37402449803e6714622c7c4276` |
| total executed | 316 | 322 |

**DG1's identity set is a strict subset of TB-R1's.**

### 1.2 The execution discipline

Both runs record, in their own machine evidence: immutable package consumed; one exact identity per **fresh process**; `runtimeExecution=true`; `configure`, `build`, `relink`, `repair`, `generatedDiscovery` all `false`; `sourceMutation`, `testMutation`, `fixtureMutation`, `selectorMutation`, `packageMutation` all `false`; package and source-archive SHA-256 identical pre/post; manifest 27/27; identity-scoped stdout/stderr/raw streams retained; `orchestration-errors` empty; post-cleanup material absent.

**Every operational property is identical.** Same binaries, same isolation, same immutability boundary, same evidence shape.

### 1.3 What actually differed

Two things, and only two:

1. **Which identities were selected.**
2. **The label attached to the result** — DG1's runner emitted a diagnostic annotation, TB-R1's emitted `boundary=immutable-artifact-only-acceptance-attempt-1-of-3` and `acceptanceAttemptConsumed=1`.

The second is bookkeeping. It changes no bit of what the machine did.

### 1.4 The empirical case is stronger than the structural one

DG1's own plan states its purpose: *"Measure the sole new CB1 risk: fail-closed production A2b construction can reject an identity that was accepted before the wiring existed."*

DG1 returned **316/316 green** and was independently re-verified as VERIFIED GREEN in a second turn.

**The risk it existed to catch then materialized anyway.** The torus witness fails through exactly that fail-closed path — `NotProductionReady/global-topology-plan/RegionCutComponentCountDeficit` — because CB1's W1.4 policy (a) is what converts an A2b construction failure into a pipeline failure. DG1 could not see it, because the identity that exercises it did not exist yet and by construction could never be in DG1's selector.

So DG1 cost **two turns** (DG-EXEC plus a separate DG-REV), consumed a budget slot, and returned a green that was *true but not informative about the hazard it was scoped to measure*. It also required a whole orchestration correction of its own (`32775399340`'s 26 spurious reds from fixture-path materialization).

**Conclusion.** DG is not a different kind of measurement. It is TB with fewer identities and a different accounting label. Under a regime with no attempt budget it has **no remaining purpose whatsoever**, and even under the old regime it bought a false assurance here.

---

## 2. D2 — the workflow change, as instructed

### 2.1 What is removed

**Effective immediately and for all future work:**

- the **per-checkpoint 3-attempt acceptance budget**, in full;
- the definition "one attempt = one complete CB→TB pair";
- attempt **counters, ratchets, resets, and reset windows**;
- the **mandatory-review-on-third-red** trigger;
- the **diagnostic gate budget** (the "2 diagnostics per checkpoint" cap);
- the **`DG` turn type** itself, together with its `DG-EXEC` / `DG-REV` split.

The reasoning is the user's and it is correct: an attempt budget exists to give the implementation agent room to self-correct *before* an external reviewer intervenes. If a single red already triggers a mandatory independent review, the budget grants no room and only adds ceremony — plus a reset ritual that has now been performed four times.

### 2.2 The workflow going forward

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

Binding rules:

1. **`CB`** — Code + Build. Authors semantics, compiles, packages. Executes no Directional runtime. Unchanged.
2. **`TB`** — artifact-only Test + Benchmark on the immutable package. Executes **the full current gate**, one identity per fresh process. Unchanged in mechanics.
3. **Green TB closes the checkpoint.** No separate acceptance ceremony.
4. **Red TB mandatorily routes to `REVIEW+PLAN`.** No retry, no patch, no "one more CB" without an intervening review. This is the *only* control, and it is now the whole control.
5. **A red TB is information, not a debit.** Nothing is consumed. Nothing is reset. The review adjudicates and re-plans.
6. **Package count remains reported, never gated.**
7. **Anything DG used to do** is now either part of TB (if it needs runtime) or part of a CB/Review static survey (if it does not). There is no third turn type.

### 2.3 The one capability DG had that must be preserved

DG's *legitimate* residual value was running identities whose redness was expected and informative without that redness being an accounting event. Under D2 that is preserved directly and more honestly:

> **Non-gating diagnostic identities.** A checkpoint may declare identities that TB executes and reports but that are **excluded from the gate count**, each with a written rationale and an owning corrective measure. This is not a new mechanism — it is the existing "inherited baseline-red / non-gating" register already used in `TODO.md`. A non-gating identity may **never** be promoted to gating without a review that records why its precondition is now independently established.

### 2.4 Where this must be propagated

`Future_Chat_Session_Handoff.md` (durable policy), `Architecture_M3_CP4_DEFN_Frozen_Definitions.md` §10, `Architecture_M3_CP4c_Code_Build_Plan.md` §2, `Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md` §4A.4, `REORIENTATION_PLAN.md`, `ROADMAP.md`, `TODO.md`, `LESSONS.md` §7. All are updated in this turn.

---

## 3. TB-R1 evidence — independently verified

Not accepted from the report. Verified against the GitHub Actions API:

| Check | Result |
|---|---|
| Run `32791027809`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, head `21eee9af…` | matches the report's event SHA exactly |
| Result artifact `9543166006` | `sha256:53686b44d055a9188ba92008c74b27d08c7daa6ed53611f1490b6c104908d2b9` — exact match |
| Execution log `9543166360` | `sha256:ad7f15c292b2d646763ad8e7b51460e93ac1d51e4aeec7dc79b7ef80ecb451dc` — exact match |
| Control log `9543166725` | `sha256:356b40bb2464269ff1a93a14036ec3e8c96941d594b4a389f135809ff455c479` — exact match |

**The run is VALID RED, not INVALID.** 322 processes, 322 tests, zero orchestration errors, zero disabled, all mutation flags false, digests stable pre/post. The report's §8 note about the trigger text labelling the run `acceptance_attempt=0/3` while the runner emitted `…attempt-1-of-3` is a control-plane annotation defect with no semantic effect — and under D2 the whole distinction disappears.

**The accepted 316 are green in the same run.** That is the single most valuable fact in this evidence: CB1's production A2b wiring, including its fail-closed policy, did **not** regress any accepted identity. W1.4's chosen policy (a) is vindicated for the accepted surface.

---

## 4. D3 — the torus failures (C1, C3, C6) are a frozen-definition scope gap

### 4.1 What the witnesses actually are — computed, not assumed

I computed Euler characteristics and boundary-edge counts directly from the committed `.obj` files:

| Fixture | V | E | F | χ | boundary edges | topology |
|---|---:|---:|---:|---:|---:|---|
| `milestone-g/torus.obj` | 72 | 216 | 144 | **0** | **0** | closed, **genus 1** |
| `milestone-g/mechanical_feature.obj` | 152 | 450 | 300 | **2** | **0** | closed, **genus 0 — a sphere** |
| `milestone-g/plane.obj` | 20 | 43 | 24 | 1 | 14 | bounded disc |

Now compare against every witness that has ever validated A2b:

- `make_cp3a_two_ring_skew_disc()` — **bounded disc**, χ = 1, 5 boundary edges;
- `make_four_triangle_fan()` — **bounded disc**, χ = 1, 4 boundary edges.

**Every A2b contract accepted to date — the disc proof, the Euler reduction `χ = V_int − E_int + F`, fragment adjacency, pinch rejection, the exterior-orbit exclusion in B4 — was defined, corrected, and frozen exclusively on bounded genus-0 surfaces.** CP4c is the first time that authority meets a closed surface, and the first time it meets genus > 0.

### 4.2 The specific assumption that breaks

`build_fragment_corner_incidence(...)`, `src/geometry/GlobalTopologyPlan.cpp:1267-1273`:

```cpp
if (forwardOrbit == reverseOrbit) {
  GlobalTopologyPlanError failure =
      error(GlobalTopologyPlanErrorCode::RegionCutComponentCountDeficit);
  failure.arc = arc.id;
  failure.sourceFace = segment.sourceFace;
  return failure;
}
```

This rejects any trace arc whose two darts lie in the **same** face-walk orbit — i.e. any arc that does not separate its two sides.

On a bounded disc, every arc of a connected cut graph separates, so the condition never fires and was never exercised. On a **closed** surface it fires for any arc that is a bridge of the current graph, and on **genus 1** it fires for any **non-separating** cycle — which a torus cut graph *must* contain, by definition of genus. A non-separating cycle having the same face on both sides is not a defect; **it is what makes the surface a torus.**

So the leading hypothesis is: **A2b's corner-incidence stage encodes a genus-0 separating-arc assumption, and the torus violates it lawfully.**

### 4.3 Why that is a hypothesis and not a fact — and why that itself is a defect

`RegionCutComponentCountDeficit` is emitted at **18 distinct sites** in `GlobalTopologyPlan.cpp` (lines 1269, 1280, 1291, 1299, 1316, 1326, 1348, 1364, 1378, 1598, 1605, 1631, 1658, 1741, 1754, 1762, 2316, 2361). Four of them are in the single loop quoted above and mean four different things: same-orbit arc; a face already carrying a chord or rays; incoming carrier equal to outgoing; a turn that is neither 1 nor 2.

The TB evidence therefore localizes the torus failure to **one enum shared by eighteen conditions**. It is not possible to say which fired.

This is precisely the failure DEFN amendment 3 froze a rule against, in this project's own words:

> *"CP4b emitted `RegionCoversNoSourceFace` at seven sites for seven distinct conditions and three immutable gates consequently localized nothing."*

Eighteen is worse than seven. **Splitting this code is corrective measure X1 and is a precondition of attempting any torus fix**, because otherwise the next CB is guesswork against an 18-way ambiguity.

### 4.4 Scope — is genus even in scope?

Yes, and normatively. `DESIGN.md` §12's verification matrix, the **curve network** row, names its representative witnesses as **"torus, feature-bearing mechanical part"**. The torus is a *required* M3 witness, not an optional stretch. CP4c's intent is correct.

But nothing in `DESIGN.md` and nothing in the frozen CP4 DEFN states how region authority behaves on a closed or higher-genus surface. **That is a genuine definitional hole, not an implementation slip**, and it is the reason CP4c cannot proceed as a fixture-authoring task.

---

## 5. D4 — the mechanical failure (C2) is upstream of everything CP4c owns

The observed failure is:

```
InvalidFieldTransportAtlas/field-transport-atlas/IncompleteCycleBasis
```

That is `authority::FieldTransportAtlas::make(...)` — **A1 authority, accepted since CP1/CP2** — failing before A2a is ever reached, let alone A2b.

The relevant construction, `src/authority/FieldTransportAtlas.cpp`:

```cpp
const int expectedHandleCount = 2 * genus;
const int expectedCycleCount =
    static_cast<int>(interiorLocalVertices.size()) + boundaryLoopCount +
    expectedHandleCount;
if (bundle.cycles.rows() != expectedCycleCount || …) {
  return fail(FieldAtlasBuildErrorCode::IncompleteCycleBasis, …);
}
```

with a preceding guard at `:1544` that maps a `PCFaceTangentBundle::init` throw onto the same code. So `IncompleteCycleBasis` means either the tangent-bundle build threw, or the produced cycle basis has a different cardinality than `interior vertices + boundary loops + 2·genus`.

**The mechanical mesh is a closed χ = 2 surface with zero boundary loops.** For it, `boundaryLoopCount = 0` and `genus = 0`, so `expectedCycleCount = interiorLocalVertices.size()` — and on a closed mesh *every* vertex is interior. A cycle basis of exactly V independent cycles on a closed surface is one dependent cycle too many (on a closed genus-0 surface the independent vertex-cycle count is V − 1, since the product of all vertex cycles is trivial). **That is a concrete, testable reason the identity can never hold on a closed mesh**, and it would be equally wrong on the torus but for the `+2·genus` term.

I state that as the leading hypothesis with its own falsification (X2 below), not as fact, because I have not executed it.

Two consequences either way:

1. **This is not CP4c-scope.** Repairing accepted A1 authority for closed surfaces is its own semantic domain, with its own DEFN and its own checkpoint. CP4c must not absorb it.
2. **`mechanical_feature` has never been driven through A1 by any test.** Searching the repository, it appears only in `MilestoneGP26Tests.cpp`, `MilestoneGP27Tests.cpp`, `SourceGridRecoveryAuthorityTests.cpp`, and the benchmark manifests — none of which construct a `FieldTransportAtlas`. Its first contact with A1 was CP4c's C2.

---

## 6. D5 — C4 and C5 were authored against a witness that cannot satisfy them

Both identities use `build_cp3b_event_fixture()`, which is `make_cp3a_two_ring_skew_disc()`.

C5 asserts, at `tests/FieldAlignedCurveNetworkTests.cpp`:

```cpp
ASSERT_EQ(2U, producedTerminalKinds.size());
EXPECT_EQ(1U, producedTerminalKinds.count(FieldAlignedNetworkEventKind::TraceIntersection));
EXPECT_EQ(1U, producedTerminalKinds.count(FieldAlignedNetworkEventKind::MandatoryBarrierTermination));
```

C4 requires an event that is a `TraceIntersection` carrying a `Terminal` incidence, and asserts its own non-vacuity before tampering.

**On the two-ring witness, neither can hold, and this was already established in the durable record.** The `M3-CP4ab-CB-R9` report's T0 derivation records that all three of that witness's traces terminate on mandatory barriers — `(6,7)`, `(8,9)`, `(6,10)`, each with `k = 1`. `finalize_field_aligned_events` has exactly three terminal cases (`SurfaceCellTracing.cpp:604-707`): trace/trace contact, barrier termination, loop closure. If all three traces take the barrier branch then there are **no** trace/trace contacts and **no** loop closures, so:

- the only produced terminal kind is `MandatoryBarrierTermination` → `producedTerminalKinds.size() == 1`, and C5's `ASSERT_EQ(2U, …)` fails;
- no `TraceIntersection` carries a `Terminal` incidence, and C4's non-vacuity assertion fails.

That is exactly what TB-R1 observed. **The tests are correct in intent and simply have the wrong witness.**

Note also that C5's per-trace loop — *every trace has exactly one typed terminal event whose kind is actually published* — is the part that matches the identity's name and `DESIGN.md` §14 M3's criterion (*"every trace terminates at a typed network event; no silent interior termination is representable"*). The `ASSERT_EQ(2U, …)` prefix is an **additional non-vacuity demand**, stronger than both. It should be preserved but **relocated to a witness set that can satisfy it**, not weakened and not deleted.

---

## 7. D7 — the common root cause, and where the fault lies

All three families reduce to one thing:

> **The CP4c witness-adequacy claim was never verified against the stage the witnesses must reach.**

DEFN §8.1 says *"Both representative witnesses **already exist as committed fixtures, verified this turn**"* and points at `make_torus_pipeline_fixture()`. What was actually verified was:

- that the four files exist, and
- that `make_torus_pipeline_fixture()` drives the torus through `remesh_from_raw_cross_field` and gets `hasTraceNetwork`.

But `hasTraceNetwork` refers to the **legacy** trace network. **Neither witness had ever been proven to reach A1, A2a, or A2b.** File existence and a legacy-product call were mistaken for stage reachability.

**And my own CP4c plan repeated the error.** Its W0.4 required only *"Confirm the four witness fixtures exist and are committed"*. It never required proving that each witness reaches the frozen proof point before six identities were authored against it. CB2 then did exactly what the plan said — correctly, including the one thing the plan flagged as the trap (reading the new `globalTopologyPlan` slot rather than `productSnapshots.traceNetwork`). **The plan is at fault; CB2 is not.**

This is the **fifth** instance of the class `LESSONS.md` §2 already names — CP1, CP2, CP2b, CP3a, and now CP4c. The lesson said *"re-derive capability against **this** checkpoint's contract, and encode the result as a runtime assertion."* The runtime assertion was required (DEFN §8.2, my plan's W8) — but only **after** the fixture had already been built and thrown, which is too late to be a control.

---

## 8. Corrective measures — series **X**

### X0 — binding preconditions for the next Code + Build turn

Each is a stop condition. If one does not hold, stop and return to review.

- **X0.1** Do **not** attempt any torus or mechanical semantic fix in the next CB. The next CB's only jobs are X1, X2, X3 and X4.
- **X0.2** Do **not** weaken, delete, or relax C1–C6, any accepted CP4ab/CP3b expectation, the disc proof, the Euler reduction, or any DEFN §8.2 precondition to obtain green.
- **X0.3** Do **not** substitute a different mesh for the torus or the mechanical witness. `DESIGN.md` §12 names both normatively.
- **X0.4** Confirm the three Euler computations in §4.1 independently before relying on them: torus χ = 0 / 0 boundary edges; mechanical χ = 2 / 0 boundary edges; two-ring χ = 1 / 5 boundary edges. If any differs, stop — this review's structural argument depends on them.

### X1 — split `RegionCutComponentCountDeficit` (diagnosability, no semantics)

**This is the highest-value single action available and must land first.**

Split the 18 emission sites in `src/geometry/GlobalTopologyPlan.cpp` into distinct typed codes, each naming exactly one condition and carrying its own locus fields. At minimum the four in `build_fragment_corner_incidence`'s per-segment loop must become separable:

| Site | Condition | Suggested code |
|---|---|---|
| `:1267` | trace arc's two darts share one face-walk orbit | `TraceArcDoesNotSeparateItsSides` |
| `:1277` | face already carries a full chord or rays | `SourceFaceCarriesMultipleTraceCuts` |
| `:1288` | incoming carrier equals outgoing carrier | `TraceSegmentCarriersCoincide` |
| `:1296` | corner turn is neither 1 nor 2 | `TraceSegmentTurnNotAdmissible` |

Enumerate and classify all 18 before writing any code; report the full mapping in the CB report. Reuse an existing code only where its frozen meaning and locus already match exactly (DEFN amendment 3's rule).

**No behaviour changes.** Every site that rejected before still rejects, with the same locus payload plus a truthful code. All 316 accepted identities must stay green — this is a pure renaming of rejections that accepted witnesses never trigger.

### X2 — make both witnesses' reachability observable, as non-gating identities

Add exactly two identities, both declared **non-gating** under §2.3 and both expected red at first execution:

- `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable`
- `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`

Each drives its committed fixture through `remesh_from_raw_cross_field` with the CB2 options and reports, **without asserting success**, the furthest stage reached and the exact typed rejection at the first stage that fails:

1. `sourceTopologyRegions` published?
2. `fieldTransportAtlas` published? if not, the exact `FieldAtlasBuildErrorCode` name and its region locus;
3. `fieldAlignedCurveNetwork` published? if not, the exact `FieldAlignedCurveNetworkErrorCode` name;
4. `globalTopologyPlan` published? if not, the exact `GlobalTopologyPlanErrorCode` name **after X1's split**, plus `arc` and `sourceFace` loci;
5. if published: region count, arc count, node count, and per-region `V_int`/`E_int`/`F`/`χ`.

The identity **fails with that report as its message** so the evidence lands in the identity-scoped raw stream. This replaces what a diagnostic turn used to do, inside the workflow that now exists.

**Falsifiable predictions to check against X2's output.** If either is contradicted, this review's disposition is wrong and the next turn is another review, not a fix:

- the torus reaches stage 4 and fails with the split code for `:1267` (`TraceArcDoesNotSeparateItsSides`);
- the mechanical witness fails at stage 2 with `IncompleteCycleBasis`;
- the mechanical mesh reports `boundaryLoopCount = 0`, `genus = 0`, and `interiorLocalVertices.size() = 152`.

### X3 — move C4/C5's non-vacuity demand to a witness set that can satisfy it

Do **not** delete `ASSERT_EQ(2U, producedTerminalKinds.size())` and do not weaken the per-trace claim.

Restructure so that:

- the **per-trace** claim — every trace has exactly one typed terminal event, of a kind actually published — is asserted **per witness**, on the two-ring witness and on every CP4c production witness that reaches A2a;
- the **non-vacuity** claim — both `TraceIntersection` and `MandatoryBarrierTermination` occur as terminal kinds — is asserted on the **union** across that witness set, with an explicit runtime assertion naming which witness contributed each kind.

Until at least one witness reaches A2a and produces a terminal `TraceIntersection`, C4 and C5 are **non-gating** with the rationale recorded. They become gating only when a review records that a witness demonstrably produces one.

If no available witness can produce a terminal trace/trace contact, **stop and return to review** — that would mean `DESIGN.md` §14 M3's crossing obligation has no witness at all, which is a finding, not something to code around.

### X4 — record the workflow change in code-adjacent authority

Update the documents listed in §2.4 so no future turn re-derives an attempt budget or a DG turn. This is documentation work and belongs in the same CB turn as X1–X3 or in this review turn; it is done in this review turn.

### X5 — what the next CB must NOT contain

No change to: `SurfaceCellTracing.cpp`; `build_arcs`; the disc-certificate construction; the Euler reduction; `FieldTransportAtlas.cpp`; the production wiring from CB1; the accepted 316 selector; any accepted expectation. X1 is a rename; X2 and X3 are test-side.

---

## 9. D6 — CP4c must be split, and the frozen gate reopened

The frozen `322 = 316 + C1–C6` presupposes that both witnesses reach A2b. Neither does, for reasons that are **not** CP4c-scope defects. Holding the arithmetic frozen would force CP4c to absorb two new semantic domains — closed/higher-genus region authority, and closed-surface cycle-basis authority in accepted A1 — which is exactly the oversizing that §4A.3 split the original CP4 to avoid.

Proposed re-decomposition. Identity names are preserved; only their allocation changes.

| Checkpoint | Domain | Gate | Owns |
|---|---|---|---|
| **`M3-CP4c-1`** | diagnosability + witness observability + event non-vacuity | **318 = 316 + C4 + C5** | X1, X2 (non-gating), X3 |
| **`M3-CP4c-2`** | closed / higher-genus region authority in A2b | **321 = 318 + C1 + C3 + C6** | needs its own `-DEFN` first |
| **`M3-CP4c-3`** | closed-surface cycle basis in accepted A1, then the mechanical witness | **322 = 321 + C2** | needs its own `-DEFN` first |

`M3-CP4c-2-DEFN` and `M3-CP4c-3-DEFN` are planning turns and must freeze, before any code:

- **for CP4c-2** — what a region *is* on a closed surface and on genus > 0; whether a non-separating arc is admissible and what replaces the separating assumption; how `χ = V_int − E_int + F` generalises when the cut graph does not cut every handle; what the typed rejection is when a handle is uncut; and how B4's bounded-surface identity `V_g − E_g + F_g^interior = χ(S)` reads when `b = 0` (it reduces to the all-orbits form, which DEFN amendment 12(b) already covers — confirm, do not re-derive);
- **for CP4c-3** — whether `expectedCycleCount = interiorVertices + boundaryLoops + 2·genus` is correct for a closed mesh, what the correct relation is, and whether repairing it reopens any accepted CP1/CP2 identity.

**Note for the CP4c-2 DEFN:** the torus's field must be characterised before its region authority is designed. On a closed genus-1 surface Poincaré–Hopf forces the singularity indices to sum to **0**, so the network may legitimately have few or no ports; the fact that TB-R1 reached a *per-arc* loop proves at least one trace arc exists, so the field is not singularity-free. Establish the actual port and trace counts through X2 before designing anything.

---

## 10. Accounting and exact successor

- attempt budget: **ABOLISHED** (D2). No counter is carried forward. CP4c's historical `1/3` is now a historical cost only.
- diagnostic budget and the `DG` turn type: **ABOLISHED** (D1, D2).
- latest accepted runtime authority: **M3 CP4ab 316/316**, source/package `157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`
- CB1's production A2b wiring is **not** implicated: all 316 accepted identities are green in TB-R1's own run
- stable regression accounting: **42 events / 14 categories / 28 recurrences** — unchanged; the six reds are first-acceptance candidates
- produced-witness debt: **5**
- M3 package count: **36**

**Exact next: `M3-CP4c-1-CB`** — Code + Build only, runtime forbidden. Execute X0's preconditions, then X1 (split the 18-way overloaded rejection code), X2 (two non-gating witness-reachability identities), X3 (relocate C4/C5's non-vacuity to a satisfiable witness set), X5's prohibitions. Compile and package; execute nothing. Then `M3-CP4c-1-TB` on the full **318** gate plus the two non-gating identities.

`M3-CP4c-2` and `M3-CP4c-3` remain blocked pending their own `-DEFN` turns.

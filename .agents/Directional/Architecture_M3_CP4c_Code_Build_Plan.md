# Architecture M3 CP4c — Code + Build Plan (the M3 exit gate)

> **SUPERSEDED AS ROUTING, 2026-08-25.** CB1, DG1 and CB2 completed against this plan and TB-R1 returned
> **VALID RED 316/322**. `Architecture_M3_CP4c_TB_R1_Independent_Review.md` is now the binding authority:
> it splits CP4c into `M3-CP4c-1` (**318**), `-2` (**321**) and `-3` (**322**), supplies corrective
> measures **X0–X5**, and records the user's abolition of the attempt/diagnostic budgets and of the
> `DG` turn type. **This document is retained for the parts that remain true and useful** — §0's
> production-wiring finding, §4's wiring recipe (implemented and vindicated: the accepted 316 stayed
> green), §7.1's fixture recipe (implemented correctly by CB2), and DEFN §8.2's preconditions. Its §2
> turn sequence, its budget language, and its W0 precondition set are **withdrawn**.
>
> **The defect in this plan, stated plainly:** W0.4 required only that the witness *files exist*. It
> never required proving that either witness **reaches the product stage the identities assert on**
> before six identities were authored against them. Neither witness had ever been through A1, A2a or
> A2b. That is the fifth instance of the class `LESSONS.md` §2 names, and it is this plan's fault, not
> CB2's.

**Status:** SUPERSEDED — see above. CB1 and CB2 are COMPLETE / BUILD GREEN; DG1 was VERIFIED GREEN and
was the last diagnostic turn this project will run; TB-R1 is **VALID RED 316/322** (accepted 316/316
PASS, C1–C6 0/6). CB2 source/package: `a5edb1a31c315d51df216f3bb51470989ff64e33 / 9541369624`.
**Supersedes:** the routing pointer "section 4A.3c". **No section 4A.3c ever existed** in
`Architecture_M3_Field_Aligned_Curve_Network_Code_Build_Plan.md`.
**Does not supersede:** `Architecture_M3_CP4_DEFN_Frozen_Definitions.md` §7.3, §7.5, §8, §9, §11.

Incoming accepted authority: **M3-CP4ab, 316/316**, source/package
`157bf784a9cdd2765018206ae0ac26729ed7a584 / 9527801615`, immutable TB-R3 `32758293793 / 97530833220`.

---

## 0. Read this first — the finding that resizes CP4c

Identities **C1** and **C2** are named
`…DerivesRegionsThroughProductionEntryPath`. That phrase is load-bearing and it is not currently
satisfiable, for a reason no existing plan document records:

> **`GlobalTopologyPlan` is never constructed by the production pipeline.**

Verified in the accepted source, not assumed:

- `grep -n "GlobalTopologyPlan" src/pipeline/RemeshPipeline.cpp` returns **nothing**.
- The pipeline *does* build A2a: `geometry::FieldAlignedCurveNetwork::make(...)` at
  `src/pipeline/RemeshPipeline.cpp:6587`, stored at `:6598`, published to
  `result.surfaceCellContext.productSnapshots.fieldAlignedCurveNetwork` at `:6604-6605`, and copied
  into per-component stage products at `:8603`.
- The product slots that exist are `SurfaceCellDiagnosticProductSnapshots::fieldAlignedCurveNetwork`
  (`include/directional/pipeline/RemeshPipeline.h:306`) and
  `SurfaceCellComponentStageProducts::fieldAlignedCurveNetwork` (`:1165`). **There is no
  `globalTopologyPlan` slot in either.**

So CP4c is not "write two fixtures and six tests". It is **production wiring of A2b, then two
representative witnesses, then the cumulative exit gate.** DEFN §8.1's advice to copy
`make_torus_pipeline_fixture()` remains correct and useful, but that helper reads
`result.surfaceCellContext.productSnapshots.traceNetwork` — the **legacy** trace network, a different
product from `FieldAlignedCurveNetwork` and from `GlobalTopologyPlan`. Copying it verbatim will not
give you a plan to assert on.

**Sizing decision.** The frozen gate **322 = 316 + C1–C6** and the frozen identity names in DEFN §7.3
are **not reopened**. Instead CP4c is executed as an ordered four-turn sequence (§2) with the wiring
isolated in its own Code + Build turn and its own diagnostic. If W3's static survey (§3) shows the
wiring is larger than the bound stated there, **stop and return to Review for a checkpoint split**
rather than absorbing it.

---

## 1. What CP4c must deliver

From DEFN §7.3, frozen and unchanged:

| Identity | Name |
|---|---|
| C1 | `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` |
| C2 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` |
| C3 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` |
| C4 | `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing` |
| C5 | `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced` |
| C6 | `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` |

Gate: **322 = accepted 316 + 6.** C3, C4, C5 are the obligations carried from CP3b (plan §4A.3 items
D3 and D6). C4 and C5 are named on `FieldAlignedCurveNetwork` deliberately — DEFN §7.3 states this is
not a scope violation because CP4c is the cumulative exit gate.

---

## 2. Turn sequence — four turns, in this order

| # | Turn | Type | Deliverable | Budget |
|---|---|---|---|---|
| 1 | `M3-CP4c-CB1` | Code + Build | W0–W5: production A2b wiring only. **No CP4c identity authored.** | no attempt |
| 2 | `M3-CP4c-DG1` | artifact-only diagnostic | W6: prove the wiring on committed production witnesses without spending an attempt | diagnostic **1/2** |
| 3 | `M3-CP4c-CB2` | Code + Build | W7–W9: the two witnesses and identities C1–C6, plus the 322 selector | no attempt |
| 4 | `M3-CP4c-TB` | artifact-only Test + Benchmark | the cumulative **322** gate | acceptance **1/3** |

> **WITHDRAWN 2026-08-25.** Attempt and diagnostic budgets and the `DG` turn type are abolished. The
> table above is history: CB1, DG1 and CB2 ran, and TB-R1 was red. The successor sequence is in
> `Architecture_M3_CP4c_TB_R1_Independent_Review.md` §9.

Rationale for spending a diagnostic before acceptance: W1 introduces a **new fail-closed production
path**. If A2b legitimately fails to derive a plan on any mesh exercised by the accepted 304
predecessor surface, that mesh's production test goes from green to red and the acceptance attempt is
lost to a discovery that a diagnostic would have made for free. This is the exact hazard §4 names.

---

## 3. W0 — binding static precondition, before any mutation

Perform and record all of the following **before** editing production code. Each is a stop condition:
if it does not hold, **stop and return to Review**; do not adapt the plan in place.

- **W0.1** Confirm `grep -n "GlobalTopologyPlan" src/pipeline/RemeshPipeline.cpp` is still empty. If
  A2b is already wired, this plan's §0 finding is stale — stop.
- **W0.2** Confirm `geometry::global_topology_plan_hash(const GlobalTopologyPlan &)` is declared
  (`include/directional/geometry/GlobalTopologyPlan.h:273`) and that
  `GlobalTopologyPlan::make(sourceFaces, sourceVertexCount, sourceAuthority, network)` is the public
  four-argument constructor (`:175`). The wiring depends on both.
- **W0.3** Enumerate every accepted-predecessor test identity that drives
  `directional::pipeline::remesh_from_raw_cross_field(...)` with
  `surfaceCells.enabled = true` and `fallbackPolicy = Fail`. These are the identities W1 can regress.
  Record the list and its cardinality in the CB1 report. **If that list is empty, stop** — it would
  mean no accepted identity exercises the path W1 modifies, and W6's diagnostic would be vacuous.
- **W0.4** Confirm the four witness fixtures exist and are committed:
  `benchmarks/fixtures/milestone-g/torus.obj`, `torus.rawfield`, `mechanical_feature.obj`,
  `mechanical_feature.rawfield`. All four were verified present at CP4ab closure.
- **W0.5** Confirm `tests/FieldAlignedCurveNetworkTests.cpp` and
  `tests/SurfaceCellTransitionQuotientTests.cpp` are both members of
  `DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES` (`cmake/DirectionalTests.cmake:69-83`). They are, as
  of the accepted source. This matters only for target placement — the helper itself must be
  re-authored, not linked (§7.1).
- **W0.6** Bound the wiring: the W1 change must be **confined to** `src/pipeline/RemeshPipeline.cpp`
  and `include/directional/pipeline/RemeshPipeline.h`. If any other production translation unit needs
  to change, **stop and return to Review** — that is the signal that CP4c needs a checkpoint split
  rather than an internal decomposition.

---

## 4. W1 — wire A2b into the production entry path

Copy the shape of the A2a site at `src/pipeline/RemeshPipeline.cpp:6587-6629` exactly. That block is
the established pattern and it has five parts: build, typed fail-closed, store in a local
`std::optional`, publish to `productSnapshots`, and `record_surface_cell_context_product(...)` with an
identity hash and an element count.

**W1.1 — construct.** Immediately after `tracingOptions.fieldAlignedNetwork = &*fieldAlignedNetworkProduct;`
(`:6599`), build the plan from the same inputs the network was built from:

```
geometry::GlobalTopologyPlan::make(
    meshWhole.F, static_cast<std::size_t>(meshWhole.V.rows()),
    *sourceTopologyRegionsProduct, *fieldAlignedNetworkProduct)
```

**W1.2 — publish.** Add `std::optional<geometry::GlobalTopologyPlan> globalTopologyPlan;` to
**both** `SurfaceCellDiagnosticProductSnapshots` (beside `fieldAlignedCurveNetwork`,
`include/directional/pipeline/RemeshPipeline.h:306`) and `SurfaceCellComponentStageProducts` (`:1165`),
and assign both, mirroring `:6604-6605` and `:8603`.

**W1.3 — record the product identity.** Add a `record_surface_cell_context_product(...)` call named
`"global-topology-plan"`, using `geometry::global_topology_plan_hash(*globalTopologyPlanProduct)` and
an element count of `arcs().size() + regions().size() + rotation_system().size()`. Mirror the
`"field-aligned-network"` call at `:6618-6628`.

**W1.4 — failure policy. Read this before choosing.** There are two admissible policies and they are
not equivalent:

- **(a) Fail-closed**, mirroring A2a at `:6591-6597`: return
  `fail_surface_cells(SurfaceCellFailureCode::NotProductionReady, "global-topology-plan/" + global_topology_plan_error_code_name(...))`.
- **(b) Publish-or-omit**: on failure leave the optional empty, record the product as absent, and let
  the pipeline continue.

**Choose (a).** DESIGN §7.3 single-writer authority and §15's stop conditions do not permit a consumer
to proceed past a product that failed to construct, and (b) would make "no plan" indistinguishable from
"plan not reached" at every downstream reader. **But (a) is exactly what can regress the accepted 304**,
which is why W6 measures it before an attempt is spent.

If W6 shows (a) regresses any accepted identity, **stop and return to Review**. Do not switch to (b) to
recover green — that decision changes a product contract and is not the implementation agent's to make.

**W1.5 — prohibited in W1.** No change to `GlobalTopologyPlan.cpp`, `SurfaceCellTracing.cpp`, any
fixture, any selector, any existing test expectation, or any DEFN definition. No new error code. No
second construction site. No caching, no memoization, no reuse of a plan across components.

---

## 5. W2–W5 — CB1 completion

- **W2** Compile the changed owner target, then the authoritative six-target package. Record both
  run/job ids, both artifact ids and SHA-256 digests, the exact semantic commit, the source-archive
  SHA-256, manifest `27/27`, and all five source-status snapshots empty.
- **W3** Assert `runtimeExecution=false`. No generated Directional test, benchmark, discovery, CLI,
  help/version, fuzzer, or custom input may execute in CB1.
- **W4** Record in the CB1 report: the W0.3 identity list, the W1.4 policy chosen and why, and the
  exact diff scope (which must be the two files named in W0.6).
- **W5** Stop. Do not author any CP4c identity in CB1. Do not run W6.

---

## 6. W6 — the CB1 diagnostic (`M3-CP4c-DG1`)

Artifact-only on the CB1 package. No configure, rebuild, relink, repair, generated discovery, or
source/test/fixture/selector mutation. Consumes diagnostic **1/2** and **no acceptance attempt**.

Execute, one identity per process:

1. **the full accepted 304 predecessor selector** at its frozen SHA-256
   `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666`;
2. **the frozen CP4ab twelve** at `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec`.

That is the accepted **316** surface, unchanged, run against the newly wired package.

**Pass condition: 316/316.** Anything less means W1 regressed accepted authority and CB2 must not
start. Report the first typed rejection per red identity from the identity-scoped raw stream — **not**
by grepping assertion prose for enum names, which reports the *expected* enum (see `LESSONS.md` §1,
"Structured diagnostic fields outrank grep over assertion prose").

Do **not** widen this selector with speculative telemetry. If a red appears, the raw stream plus the
typed failure payload is the evidence; a second diagnostic is available but is the reserve.

---

## 7. W7–W9 — CB2, the witnesses and the six identities

### 7.1 W7 — the two production-path witnesses

Author both helpers **inside `tests/FieldAlignedCurveNetworkTests.cpp`**, in its existing anonymous
namespace. `make_torus_pipeline_fixture()` lives in an anonymous namespace in a different translation
unit (`tests/SurfaceCellTransitionQuotientTests.cpp:512`); same CMake target does **not** make it
callable. Re-author it; do not attempt to link it or move it to a shared header.

Copy from `tests/SurfaceCellTransitionQuotientTests.cpp:512-541`:

- `directional::tests::benchmark_fixture_path("milestone-g/torus.obj")` and `".../torus.rawfield"`
  (helper in `tests/TestFixturePaths.h`);
- the `read_rawfield(path, mesh.F.rows())` helper at `tests/SurfaceCellTransitionQuotientTests.cpp:261`
  — re-author it too, same reason;
- the exact `RemeshOptions`: `lengthRatio = 0.2`, `integralSeamless = false`, `roundSeams = false`,
  `backend = RemeshBackend::SurfaceCells`, `surfaceCells.enabled = true`,
  `surfaceCells.fallbackPolicy = SurfaceCellFallbackPolicy::Fail`,
  `surfaceCells.allowSourceGridRecovery = false`, `surfaceCells.retainIntermediateGeometry = true`.

**Change exactly one thing:** read
`result.surfaceCellContext.productSnapshots.fieldAlignedCurveNetwork` and the **new**
`…productSnapshots.globalTopologyPlan` from W1.2, **not** `productSnapshots.traceNetwork`. The legacy
`traceNetwork` is a different product and asserting on it proves nothing about A2a/A2b.

Repeat for `milestone-g/mechanical_feature.obj` / `.rawfield`.

Throw with the pipeline's terminal failure code and stage on any failure, as the copied helper does at
`:531-535` — a witness that silently yields an empty product is the degenerate-fixture failure this
project has paid for four times (`LESSONS.md` §2).

### 7.2 W8 — the five self-asserted preconditions, per witness

Binding, from DEFN §8.2. Each must be asserted **at runtime, before any target assertion becomes
required-green evidence**, on each of the two witnesses:

1. at least one published region covers **more than one** source face;
2. at least **two distinct** regions exist;
3. **torus only** — genus is actually 1, derived from the source Euler characteristic, and at least one
   region boundary uses a non-trivial cycle;
4. **mechanical only** — at least one `SurfaceCellRailKind::HardFeature` mandatory edge exists **and
   lies on a region boundary**;
5. the quadrangulability certificate is `established()`.

Model: `make_cp3a_two_ring_index_one_field(...)` at `tests/FieldAlignedCurveNetworkTests.cpp:304-330`,
which asserts its own capability rather than trusting the author's mesh choice.

**If a precondition cannot be satisfied by the committed fixture, stop and return to Review.** Do not
weaken the precondition, do not substitute a different mesh, and do not hand-author a torus — DEFN §8.1
prohibits it explicitly.

### 7.3 W9 — the six identities and the 322 selector

Author C1–C6 under the exact frozen names in §1. Then:

- compose the cumulative selector as accepted **316** ∪ CP4c **6** = **322**;
- record all three SHA-256 values and assert **322 non-empty / 322 unique**;
- the accepted 316 portion must be carried **byte-identically**; do not regenerate it, and do not run a
  discovery command to produce it. TB-R3's method is the precedent: the accepted result artifact
  supplies the frozen predecessor selector.

**Scope limits, binding:**

- witnesses assert regions and disc proofs and **stop there**. They must not run to final quad
  emission, and CP4c must claim **no `G4-B001` progress** (DEFN §9, plan §4A.3). Record that reasoning
  in the CP4c report so it is not re-litigated.
- `G4-B002`'s three produced-witness debts stay with M4; `G4-B003`'s two stay with M5. M3 discharges
  neither. Produced-witness debt remains **5** unless CP4c independently proves otherwise.
- not in CP4c: M4 rail scheduling, M5 quotient/chart work, any production-quality or resource claim.

---

## 8. Standing stop conditions for CP4c

DEFN §11 applies unchanged. In addition, stop and return to Review rather than patching around any of:

- W0.6 is violated — the wiring needs a production file beyond the two named;
- W6 returns anything other than 316/316;
- a DEFN §8.2 precondition is unsatisfiable on a committed fixture;
- satisfying an identity would require changing an accepted CP4ab or CP3b expectation;
- the torus or mechanical witness reaches the completion/materializer stage;
- A2b acquires a second construction site, or the plan is cached/shared across components.

---

## 9. Falsifiable expectations

State these in the CB2 report and check them at TB, so a wrong plan is visible rather than absorbed:

1. W6 returns **316/316**.
2. Both witnesses publish a non-empty `globalTopologyPlan` with **≥2 regions**, each carrying a disc
   certificate with `boundaryWalkCount == 1`, `sourceFacesConnected`, `eulerCharacteristic == 1`.
3. The torus witness's source Euler characteristic is **0** (genus 1, closed) — if it is not, DEFN
   §8.2(3) is unsatisfiable on this fixture and W8 must stop.
4. The mechanical witness exposes **≥1** `HardFeature` mandatory edge on a region boundary.
5. TB returns **322/322** with zero orchestration errors and all mutation flags false.

If (1) fails, W1's failure policy is the subject. If (2)–(4) fail, the witness is the subject. Never
adjust a constant to match an observation.

---

## 10. Accounting at CP4c entry

- accepted runtime authority: **M3 CP4ab 316/316**
- CP4c acceptance attempts: **0/3** (untouched)
- CP4c diagnostics: **0/2** (one allocated to W6)
- M3 packages: **34**
- stable regression accounting: **42 events / 14 categories / 28 recurrences**
- produced-witness debt: **5**
- open product blockers not owned by M3: `G4-B001` (completion/materializer), `G4-B002` (M4),
  `G4-B003`, `G4-B004`

**CB1 W0–W5: COMPLETE / BUILD GREEN. DG1: COMPLETE / independently VERIFIED GREEN. CB2 W7–W9: COMPLETE / BUILD GREEN. TB-R1: COMPLETE / VALID RED 316/322. Exact next: `M3-CP4c-TB-R1-INDEPENDENT-REVIEW`.** CB2 source/package is `a5edb1a31c315d51df216f3bb51470989ff64e33 / 9541369624`; cumulative selector is frozen 322. Authoritative TB-R1 `32791027809 / 97632461750` re-proved accepted 316/316 and failed all six CP4c first-acceptance witnesses with zero orchestration errors. Acceptance is 1/3 consumed; diagnostics remain 1/2. Per §8/§9, failed witness/non-vacuity expectations route to review rather than constant/assertion weakening; no retry or reserve diagnostic is authorized before review.

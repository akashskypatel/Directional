# `M6-DEFN-R5-REV` — Independent Review of the CP3-Entry Definition

**Turn:** `M6-DEFN-R5-REV` (runtime-free Review)

**Reviewed:**
- `Architecture_M6_DEFN_R5_CP3_Entry_Definition_Record.md` (D1–D9);
- RA-30;
- the held `Architecture_M6_CP3_CB1_Entry_Authority_Code_Build_Plan.md`;
- against the R5 plan, frozen §10, RA-16/17/20/26/27a/28b and exact source.

**Source authority.** Branch HEAD. Its `src/`, `include/`, `tests/` and `cmake/` are unchanged since CP2 closure; reviewed runtime is `11391685901 / 5ce3132e` (491/491).

**Disposition: ACCEPTED WITH BINDING AMENDMENTS (RA-30a).**
- D1–D9 are all addressed, and the structure is sound:
  - entry gates come before direct production;
  - the CB1/CB2 split is right;
  - the 497 entry gate and 507 final gate are correct as counted.
- **Four decisions have defects that would cause another false-rejection or vacuity cycle, or an unrunnable gate:**
  - **V1:** D4 has no authority source or API, and its fail-closed rule would break direct A5 callers;
  - **V2:** D2's reachability claim cites the wrong evidence;
  - **V3:** D3 weakens A6 instead of certifying the branch across seams;
  - **V4:** two of D9's three G4-B001 rows are not in any built target.
- Four more are underspecified for CB2 (V5–V8).
- RA-30a fixes all of these. **`M6-CP3-CB1-ENTRY` is released** under RA-30 + RA-30a.
- Gates unchanged: **497** entry, **507** final.
- Accounting **60 / 16 / 44**, debt 1.

## 1. Verified

- **D1** (`SurfaceCellTracing.cpp:7925-7965`; `RemeshPipeline.cpp:4543-4614`, `:4869-4874`). Removing only the face-gauged final branch comparison, while keeping the endpoint-state recomputation, both conjugations and an independent relation-gauge check, is correct.
- **D4's diagnosis.** A5 builds its chart-barrier set from HardRail front routes only (`RemeshPipeline.cpp:3785-3795`), and the produced torus carries 18 hard edges on PeriodicCut relations.
- **D7** relation-kind dispatch (HardRail never compares global sheet IDs; OrdinaryFront and Periodic stay within one region; a cross-region Periodic case is a stop).
- **D8**'s conjunct-to-identity table, and the requirement that G4-B004 be bound continuously as one chain.
- **D9 arithmetic.** None of the three named G4-B001 rows is in selector449, so 491 + 13 + 3 = **507** does not double-count. The entry gate is 491 + 6 = **497**.
- **The P27 parameterized ownership row is correctly excluded**, since it does not require production.

## 2. Findings

### V1 (High) — D4 names no authority source or API, and its fail-closed rule breaks direct A5 callers

D4 says A5 must "receive the same immutable typed source hard-feature edge authority" and must "fail closed" when a HardRail carrier is not in it. But:
- `SurfacePhaseFrontProduct` publishes no hard-feature authority (`SurfaceCellTracing.h:1749+`);
- A5's signature is `produce(V, F, phaseFront)`, with **38** direct test call sites, many in accepted focused-30 and selector449 rows.

Any extra parameter with an "absent" default either keeps a HardRail-route fallback (the CB1 plan forbids legacy fallbacks) or makes every direct A5 HardRail call fail closed. Either way, accepted gate behavior would change.

The single writer already exists: `SurfaceCellTracingOptions::hardFeatureEdges` (`SurfaceCellTracing.h:2089`) is the typed set the tracer consumed.

**Fix (RA-30a §1):**
- A4 publishes that set immutably;
- A5 reads it from the product;
- the adapter asserts it equals the pipeline's `hardFeatureRailEdges`;
- A5's signature does not change;
- no accepted test body changes.

### V2 (High) — D2's reachability claim cites the wrong evidence

D2 requires a produced cross-region HardRail with a nonzero selected-face gauge. As evidence it cites TB7 `:264-267`, but that passage concerns the **torus's periodic carriers**, which belong to a single region. The same TB7 analysis says every HardRail fixture uses a constant field (`constant_xy_field`), so F = 0 everywhere.

With F = 0, stripping is the identity. Any stripping formula passes, including the wrong-direction `F ∘ B` in place of `F⁻¹ ∘ B`. RA-16 deferred this item precisely because no such fixture existed. The "alter only F" negative kills an implementation that ignores F, but nothing proves that correct stripping **accepts** valid data whose gauge is nonzero.

**Fix (RA-30a §2):** specify the produced construction and its non-vacuity conditions; detail is in RA-30a.

### V3 (Medium–High) — D3 weakens A6 instead of certifying the branch across a seam

A6 accepts an OrdinaryFront relation only if `sourceChart`, `branchRotation`, coordinate and scale are all equal and phase is within `1e-10` (`RemeshPipeline.cpp:5229-5236`). D3/RA-30 §3 lets chart and branch "differ only with the exact reciprocal checked isolation transition", and puts no constraint on the branch difference. It also says the phase comparison "must not" be relied on, without saying whether CB1 removes it.

The A4 `SurfaceIsolationSeamTransportCertificate` publishes the seam's exact `forward()` / `reverse()` quarter-turns (`SurfaceCellTracing.h:1341-1365`), and A5 validates those certificates. So the branch across a seam is **certifiable**, exactly as D2 certifies HardRail branches. Dropping it accepts frame-misaligned OrdinaryFront relations across seams. That is a validator weakening, which the CB1 stop rules forbid.

**Fix (RA-30a §3).**

### V4 (High) — two of D9's three G4-B001 rows are in no built target

`MilestoneGP26Tests.cpp` and `MilestoneGP27Tests.cpp` compile **only** into `directional_surface_cell_historical_tests`, which is built only under `DIRECTIONAL_BUILD_HISTORICAL_TESTS` (`cmake/DirectionalTests.cmake:554-578`). That target is not among the standard eight compile targets (`.github/workflows/agent-compile-reusable.yml:12`). `SurfaceCellsPhase10` is in the producer target. So the frozen 507 gate cannot be executed by the frozen compile-and-TB pipeline.

**Fix (RA-30a §4):** CB2 decides at compile time. It does not affect CB1 or the 497 gate.

### V5 (Medium; CB2) — D6's exact equality ignores floating-point accumulation order

D6 requires an **exact** optimizer accept/iteration/line-search decision sequence, and positions within `1e-12 · max(1, bbox)`, under source-row, output-row and corner permutations. The optimizer accumulates energy and gradients in row order, and floating-point addition is not associative, so permuted inputs change rounding. Armijo decisions near their threshold can then flip. That would be a RED with no semantic defect behind it.

The output-row permutation also needs a defined injection seam, which D6 does not give.

**Fix (RA-30a §5).**

### V6 (Medium; CB2) — "scheduler permutation" is undefined

Frozen §10 and D8 require scheduler-permutation invariance (`DirectProductionSchedulerPermutationIsSemanticNoOp`), but never say what is permuted or how.

**Fix (RA-30a §6).**

### V7 (Medium) — D1 names no produced fixture and doesn't kill the wrong-direction conjugation

D1 requires a produced exact-A3 pair with unequal `localFaceBranchRotation`, but names no fixture. The produced nonzero-Z4 torus already has to search for carriers with nonzero matching (`SurfaceCellTransitionQuotientTests.cpp:1351-1363`), which makes it the natural candidate.

An unequal pair that differs by 180° is self-inverse, so it cannot kill an implementation using `Γ` in place of `Γ⁻¹`.

**Fix (RA-30a §7).**

### V8 (Low) — D2 failure diagnosability

D2 maps to the existing external `InvalidHardRailTransport`.

**Fix:** add a distinct site suffix such as `:branch-certificate`, so it stays distinguishable from coordinate-rigidity failures (lesson 181).

## 3. Closeout

| Duty | Result |
|---|---|
| D1–D9 re-derived against source | D1, D7, D8 verified; D4 diagnosis verified. V1–V4 are defects; V5–V8 are underspecified. |
| Gate arithmetic | 497 / 507 verified; the G4-B001 rows are not in selector449. V4: GP26/GP27 are not in any built target. |
| Disposition | ACCEPTED WITH RA-30a; CB1 released. CB2 amendments V4–V6 are binding when CB2 is planned. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 206. |
| Successor | `M6-CP3-CB1-ENTRY` → `M6-CP3-TB1-ENTRY-EXEC` (497) → `M6-CP3-TB1-ENTRY-REV`. |

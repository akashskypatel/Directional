# `M6-CP2-CB1-VERIFIER-REV` — Review of the CB1 RA-28a §7 Stop

**Turn:** `M6-CP2-CB1-VERIFIER-REV` (runtime-free Review of a Code + Build stop)

**Reviewed:**
- `Architecture_M6_CP2_CB1_Verifier_Code_Build_Report.md` (stop report);
- RA-26 §5(iii), RA-28 §8 and RA-28a §7;
- exact source. HEAD `src/`, `include/` and `tests/` are byte-identical to the reviewed runtime `3f40f04a`; CB1 applied nothing.

**Disposition: STOP DISCHARGED. RA-28a §7 is WITHDRAWN and replaced by RA-28b.**
- The stop was correct: the precondition RA-28a §7 demanded is not published by A5 or A7.
- **The fault is in RA-28a §7 itself** (review-agent error, owned).
- The adjudication **neither** adds an A5 invariant **nor** introduces the class-wide optimizer check. On the authoritative path, the optimizer cannot move a provenance outside its seed's own scope, so any optimizer-side scope check only re-tests a static lineage property that the frozen completion guard already certifies.
- RA-26 §5(iii) is resolved by **non-authoritative retention**: no optimizer source change in CP2.
- Identity 12 is **re-specified, not removed**: same position, new name, now a confinement falsifier. The gate stays **491**.
- Successor: **`M6-CP2-CB1-VERIFIER-R1`**.
- Accounting **60 / 16 / 44**, debt 1.

## 1. The stop report is accurate

- **`selectedFace`** is the canonical corner's source face (`RemeshPipeline.cpp:4265-4280`).
- **Wedge bindings** come from side spans and, for vertex supports, from wedge traversal (`:4282-4423`). Nothing makes `selectedFace` a member.
- **Face-interior supports are safe**: the bindings must equal the face (`:4298-4307`). Edge and vertex supports have no such invariant.
- **A7 `sourceCharts`** are built only from member bindings (`:6800-6873`).
- **Phase-front closure is geometric only**: `SurfaceCellTracing.cpp:7152-7171` compares positions, not faces.

## 2. Root cause — RA-28a §7 strengthened the reviewed predicate without checking its precondition

| Rule | Predicate | Precondition published? |
|---|---|---|
| RA-26 §5(iii) | Membership in the class's `vertexChartAuthority` **sheets** | — |
| RA-28 §8 (Definition) | Membership of the projected source **chart** | — |
| RA-28a §7 (review agent) | Projected **face** ∈ `sourceCharts` faces, plus a proof that `selectedFace` ∈ `cornerWedgeBindings` | **No** |

The A5/A7 contracts do not publish the face-level fact, and frozen RA-22b item 2 says the representative face "never decides destination, component, chart or lineage". **Review-agent error, owned (lesson 202).**

## 3. Adjudication

### 3.1 Rejected: an A5 `selectedFace ∈ cornerWedgeBindings` invariant

The representative face is representation-only (RA-22b §2). Making it a binding member would mean one of two things:
- **re-selecting `selectedFace`**: this changes the A7 representative, and through RA-26's reference-selecting consumers it changes optimizer and validation outcomes across selector449;
- **rejecting** corners whose canonical face lies outside their wedge: this could reject accepted rows.

Both are A5 semantic changes. Neither is needed.

### 3.2 Rejected: a class-wide optimizer membership check

On the authoritative path (`constrainVerticesToProvenanceEntities = true`, `RemeshPipeline.cpp:12801-12803`), `project_vertices` **confines every projected provenance to its seed's own scope**:
- vertex and edge supports keep `seed.face`, moving only barycentrics on the support simplex (`SurfaceMeshOptimizer.cpp:714-750`);
- face-interior supports project only onto `{seed.face}` (`:710-712`);
- the degenerate fallback searches only within the seed's own `(component, sheet)` scope (`:786`, `:797`).

So the projected scope is always the representative's scope. **Any** optimizer scope check, anchor-based or class-wide, evaluates a static property of the lineage and never detects anything about movement.

That static property is **already certified** by the frozen completion guard, which runs before the optimizer (`PureQuadCompletion.cpp:895-941`):
- RA-22b requires `region_for_row(sourcePoint.face)` ∈ the retained regions and `sheet_for_row(sourcePoint.face)` ∈ the retained sheets (`:901-912`);
- every retained chart face must be support-incident and region/sheet-retained, and the retained charts must form a single component (`:913-941`).

In addition:
- A5 sets each binding's sheet to the A0 sheet of its face (`RemeshPipeline.cpp:3899-3912`);
- RA-28a §3 makes the CP2 verifier certify `cornerWedgeSheets` == binding sheets against A0;
- **post-movement** class-wide chart compatibility belongs to final validation (`SourceAuthoritativeMeshValidator.cpp:1232-1262`, `LocalSheetMismatch`, with `vertexChartAuthority`), which runs after the optimizer and gates acceptance.

A new optimizer check would add a precondition proof burden and no detection power.

### 3.3 Decision (RA-28b)

**RA-26 §5(iii) resolution.** Keep the existing optimizer component/sheet self-check **unchanged**, classified as a non-authoritative tautology on the authoritative path. Its outputs (`projectionStayedOnComponents/Sheets`) also feed existing acceptance flags, so removing it would be a behavior change.
- Class-wide authority before movement: the A8 verifier (RA-28a §3) plus the completion guard.
- Class-wide authority after movement: final validation.
- **No `SurfaceMeshOptimizer` source change in CP2.**

**Identity 12, re-specified.** `M6CP2.AuthoritativeOptimizerProjectionStaysOnRepresentativeScope` replaces `M6CP2.OptimizerProjectionUsesClassWideChartAuthority` at the same position. It pins the confinement property that makes this retention sound:
- **Setup:** authoritative-path optimization constraints (retained `vertexChartAuthority`, `constrainVerticesToProvenanceEntities = true`) from a produced fixture. Non-vacuity requires at least one vertex-support and one edge-support seed (the cases where the representative face can lie outside the bindings). Face-interior seeds are asserted if present but not required: their confinement is trivial, and small produced grids may have none.
- **Action:** call `surface_optimizer_detail::project_vertices` (declared at `SurfaceMeshOptimizer.h:567-573`) with perturbed candidate positions.
- **Assertions:**
  1. for every vertex with a valid seed, the projected `face` equals the seed `face`;
  2. `componentsOk` and `sheetsOk` are both true;
  3. for every retained vertex, `sheet_for_row(seed.face)` ∈ {`sheet_for_row(f)` : f ∈ `vertexChartAuthority[v].sourceCharts` faces}. This pins the RA-22b premise on that fixture.

If a later change lets projection leave the seed scope, this identity fails, and the retention must be re-reviewed.

**The exploratory CB1 WIP's optimizer membership change is void.** R1 must not apply it.

## 4. Consequence for later owners

The representative face can lie outside the occurrence's wedge bindings for edge and vertex supports. RA-26 §5(i) (optimizer energy and gradient reference) and §5(ii) (validation field-metric fallback) read that face's normal and field. **`M6-DEFN-R5` must not assume `selectedFace` ∈ the class's chart faces** when it defines the class-wide reference. This is recorded as an RA-26 §5 note.

## 5. Closeout

| Duty | Result |
|---|---|
| Stop report | Verified accurate (5 points). |
| Root cause | RA-28a §7 over-tightened RA-26 §5(iii); review-agent error, owned. |
| Adjudication | No A5 invariant; no optimizer check; RA-26 §5(iii) → non-authoritative retention; identity 12 re-specified (confinement falsifier). |
| Gate | Unchanged: 30 + 12 + 449 = **491**. The focused-12 list is not yet published, so the rename costs nothing. |
| Accounting | +0 → 60 / 16 / 44, debt 1. |
| Lesson | 202. |
| Successor | `M6-CP2-CB1-VERIFIER-R1`. |

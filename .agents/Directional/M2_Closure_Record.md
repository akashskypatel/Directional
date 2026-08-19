# M2 Closure Record — Closed Stage Products and Single Writers

**Status:** **CLOSED** on the immutable `M2-CP4-TB-R2` gate.
**Accepted exact source / package:** `9fda64e88ddc885ce993ff8da3ad6a51765724a4` / `9340456431`
**Accepting runtime:** run/job `32183306224 / 95861164621` — **275 / 275 required-green PASS**
**Runtime evidence:** result `9341623741` SHA-256 `a3a2beb4fec4d9576c2539e166c4a268d4e723624ed3ff5b183efbf4d77f7ab1`; log `9341624025` SHA-256 `75097ec6cca7c00cacb25904d6aca2c28921dc1b413b9903ae3c63f56cbc2174`
**Frozen selector:** 275 identities, SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`
**Stable regression totals at closure:** **37 events / 14 categories / 23 recurrences**
**Produced-witness debt carried forward:** **5** (`G4-B002` = 3 → M4; `G4-B003` = 2 → M5)
**Cost:** **11 immutable packages** across five checkpoints, including two explicitly authorized ceiling reopenings.

This is the single durable historical record for M2. It supersedes the M2 plan, per-checkpoint reports, and the fixture-authority inventory.

## 1. What M2 required

`REORIENTATION_PLAN.md` section 6 / `DESIGN.md` 6.5, 7.3: one immutable output type per stage; one semantic writer per fact; **no mutable cross-stage context as semantic authority**; typed `NotApplicable` / `Produced` / `Rejected` preserved through consumers; consumers depending only on declared products plus exact source inputs.

**M2 did not introduce the closed-outcome pattern.** `ProducerOutcome<T>` already existed from R-C. M2 propagated it to the stages still publishing open `bool success` results and eliminated the mutable cross-stage context. That correction was made before CP1 started — the original draft claimed the tracing header reconstructed producer state from `attempted`/`succeeded` aliases, which was false: `attempted` belongs to a diagnostic counter struct and `succeeded` appears in no geometry header.

## 2. Frozen CP0 census — the sizing authority

`M2-CP0-CB` inspected source `79f078cd33db031269ed47d779872da24712f4e5`; `M2-CP0-TB` independently reconstructed and accepted it:

- **stage-result family: 33 found / 33 classified / K=8** cross-stage products requiring change. Eleven structs contain literal `bool success`; three are stage-local adapters excluded from cross-stage K.
- **context mutation family: 290 found / 290 classified / K=62** cross-stage semantic mutation sites, covering 23 top-level fields of the 181-field `SurfaceCellPipelineContext`. Non-K: 226 declared product/diagnostic publications plus 2 stage-local whole-context resets.
- Deferred-blocker exposure: **none**.

The earlier 331-site figure was a review sizing estimate, superseded by this census.

## 3. Checkpoint trajectory

| Checkpoint | Surface | Accepted source / package | Runtime | Result |
|---|---|---|---|---|
| **CP0** | census | `79f078cd…` | accepted | 33/33/K=8, 290/290/K=62 |
| **CP1** | repair/feasibility stage products | `65183336d092d8fe165b6ed4709c4759a0b7fe33 / 9309981828` | `32101777174 / 95603538759` | **239/239** |
| **CP2** | completion stage products | `61273efa3f2f2e6bbfb1592f40a29e3f7b7f4cef / 9316462253` | `32119584283 / 95656737849` | **273/273** |
| **CP3** | cross-stage context **reads** | `0a06127555405abef474af501e2bd09de3320c1b / 9328335558` | `32150796184 / 95755876548` | **273/273** |
| **CP4** | context **writes** + terminal product closure | `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431` | `32183306224 / 95861164621` | **275/275** |

Final static M2 closure is **K=0**: eight scheduled products closed over typed `ProducerOutcome<Product, Failure>`; 23 diagnostic snapshot fields contained under `SurfaceCellDiagnosticProductSnapshots`; 62 lexical snapshot refs; **direct semantic context refs 0**; **CP3 forbidden reads 0**.

## 4. Independently verified closure evidence

- Branch head is byte-identical to accepted source `9fda64e8…` across `src`, `include`, `tests`.
- **The CP4 diagnostic correction landed exactly**, including an ordering subtlety: `RemeshPipeline.cpp:11532` now uses `std::find_if`, and `surfaceCellFirstInvalidProducerCell` is published *after* `reject_merge_authority`, which resets diagnostics — setting it before would have been silently wiped. `componentProducts` remains authoritative; no context read was restored.
- **The rail witness repair is stronger than specified.** It uses the proven `make_rectangular_internal_hard_feature_grid()` substrate, retains `edge.incidentFaces = {-1}` as the mutation, and asserts both the typed `InvalidFeatureEdge` kind *and* `failedEdgeIndex == 0` — pinning the seam rather than merely proving rejection.

## 5. Recorded caveats

1. **Reads and writes were split across CP3/CP4 deliberately.** The semantic violation was consumers treating mutable context as authority; CP3 removed that, leaving CP4 a largely mechanical write reduction. Pairing a semantic cutover with a 62-site sweep in one gate is the shape that cost unit-2 Batch C three attempts.
2. **`surfaceCellContext` still exists** as a declared diagnostic surface with 23 snapshot fields. It carries **no** semantic authority — that is the closure claim, and it is what static `K=0` proves. It is not claimed to be removed.
3. **The fixture-authority omission class is partially closed.** See section 6.

## 6. Fixture-authority omission class — status at M2 closure

The class is an options-struct member carrying mandatory authority defaulted to `nullptr`, reached through an API that defaults the whole options struct. It is the **struct-member form** of the class closed at M1 as `R-C-CB-01b`, which closed the function-parameter form and deferred this one as "a different and weaker shape." It was not weaker: it cost two CP1 checkpoints.

**Closed by M2:** the CP1 live instance (`PatchDescriptorMilestoneETests.cpp:826`).

**Still open, carried into M3+ and tracked in `TODO.md`:**

- **3 latent sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options asserting success, passing only because their complexes never reach boundary-ownership resolution, and **none in the frozen selector**, so no gate protects them.
- **The generator itself** — `complete_surface_cell_complex(..., options = {})` at `PatchDescriptor.h:427`, with `SurfaceCellComplexCompletionOptions::sourceAuthority = nullptr` at `:271`. Removing the default is the class-closing fix and remains unscheduled.
- **The idiom** — `SurfaceCellComplexCompletionOptions` is **8/8 authority-unset** across all tests, and only 3 of `PatchDescriptorMilestoneE`'s contracts are gated, none of them completion tests. A file whose contracts are mostly ungated develops idioms nothing validates, and new gated contracts authored there inherit them.

Ten defaulted authority members exist across six options structs. Tracing, arrangement, optimizer and validator families were assessed and are **not** defects — `SurfaceCellTracingOptions` documents `sourceFaceComponents`/`sourceFaceSheets` as the ingress path from which `sourceAuthority` is built. **Re-run the scan for a family only if a checkpoint adds a strict authority guard to its consumer.**

## 7. Durable lessons

- **When a cutover moves a guard earlier, the earlier guard inherits the later one's diagnostic obligations.** CP4 correctly replaced a context-shadow read with a declared-product precheck, but the superseded site published a failing patch index the new one did not. Static closure proved `K=0` while an accepted diagnostic silently degraded to `-1`. Enumerate what the superseded site *published*, not only what it *decided*.
- **A deferred "weaker shape" of a closed defect class is still the defect class.** Describing a variant as weaker is not a disposition — close it or give it a named owner.
- **A test file whose contracts are mostly outside required-green develops idioms nothing validates.** Check gate coverage of the *file*, not just the new contract.
- **Split a semantic cutover from a mechanical sweep even when they touch the same field.** Reads and writes of one context are two checkpoints, not one.
- **A plan naming authority that does not exist in the form claimed costs a full cycle.** M2's first draft would have "closed" a diagnostic counter; verify every named symbol before opening a checkpoint.

## 8. Superseded by this record

`Architecture_M2_Closed_Products_Single_Writers_Code_Build_Plan.md`, `Architecture_M2_CP4_R2_Artifact_Only_Test_Benchmark_Report.md`, and `M2_Fixture_Authority_Omission_Inventory.md` are retired into this record; the live remainder of the inventory is section 6 above plus the `TODO.md` entries it names. Raw per-turn evidence remains in `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`, and immutable GitHub artifact history.

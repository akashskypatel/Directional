# Architecture M3 CP4c-2 — TB-X2-R2 Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-2`
- Turn: `M3-CP4c-2-TB-X2-R2`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular Test + Benchmark (`TB-X2-R2-EXEC` -> evidence review)
- Validated source commit: `232ac459b13657529e064272a75c5583770a5963`
- Build artifact: `9702321260`, `sha256:05237f108a65c73df81b6b125d6fcecad10ad9b5af4104ecce3c6bb9f6642035`
- Build run/job: `33212932401 / 98990159075`
- Test + Benchmark plan: `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md`
- Runtime run/job: `33215632118 / 98998526420`
- Result artifact: `9703233161`, `sha256:6b13e0bcddc3ffeba93077b6b1115bc8a400b9b9a6051d83df01ac11bec191f7`
- Runtime log artifact: `9703233545`, `sha256:19975ef0fc0e154e02326827287fd60a3a7813b10cda1fe20840e60a072d3c1b`
- Environment: GitHub-hosted Ubuntu 24.04.4, runner `2.336.0`

## Verdict

**COMPLETE / PLANNED CONTROL STOP / R2 INVALID FOR Y5 / NO GATE SELECTED.**

The immutable package and fixture-root preflight passed, D1 executed exactly once in one fresh process, and it
published all three required `m3Cp4c2Y1` witness records without calling `SurfaceCutGraph`. The fixed torus
control then failed: D1 published `networkV=0`, `networkE=0`, `sourceChi=0`, `networkOnlyCellular=false`, while
R2 requires `V=48`, `E=48`, `chi=0`, non-cellular. The plan therefore required an immediate stop. D2 was
correctly not executed. Y2/Y3 are unavailable, Y5 is `NONE`, and `selected_gate=NONE` remains binding.

This is **not product acceptance or product-root-cause evidence** for CP4c-2. Static review identifies a
high-confidence test-authority/fixture mismatch: D1 reconstructs rails from `FieldTransportAtlas` barriers via
`rails_from_atlas(...)`, whereas the frozen torus theorem and the production witness use the pipeline's
`AdaptiveFeatureMapBuilder` -> `build_authoritative_surface_cell_rails(...)` product. The frozen DEFN records
that production torus authority as 48 `HardFeature` mandatory edges / 48 structural nodes. D1 therefore did not
instantiate the control whose counts it was required to reproduce.

## Plan Execution

- Completed:
  - exact artifact digest and `SHA256SUMS` verification;
  - source commit, GMP/GMPXX, command-boundary, eight-target and clean-source metadata verification;
  - accepted selector 355 plus prefix 316/346/353 hashes and frozen 357/358 hashes;
  - source archive materialization at the binary's compiled fixture root;
  - immutable package/source pre-hashes;
  - D1 one-process execution with exactly one selected identity and exactly three Y1 publications;
  - torus fixed-control comparison;
  - immutable package/source post-hashes.
- Blocked/skipped by the declared stop rule:
  - D2 `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`;
  - Y2 exact 419/437/474 localization;
  - Y3 coarsening/unit-mismatch adjudication;
  - any Y5 Branch A/B/C selection.
- Deviations from plan: none. D2 was intentionally skipped because Y4 failed.
- Stop condition: torus control mismatch (`V/E = 0/0`, required `48/48`).

## Runtime Commands

D1, one fresh process:

```text
./bin/directional_surface_cell_producer_tests --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable
```

D2 was not invoked.

No benchmark, generated discovery, configure, compile, relink, source/test/fixture mutation, or package repair
occurred. Result metadata records `runtimeExecution=true`, `rebuild=false`, `relink=false`,
`fixtureMutation=false`, `generatedDiscovery=false`, and `benchmarkExecution=false`.

## D1 Raw Results — Y1

### Prescribed sphere — raw, control-invalid evidence only

- source: `V=98`, `E=288`, `F=192`, `chi=2`;
- D1 network terms: `V=18`, `E=30`, complement-component `F=18`, reported network `chi=6`;
- 24 traces / 56 events;
- 18 complement components; every component individually reports `chi=1`, one valid boundary cycle, disc=true;
- `networkOnlyCellular=false` because the reported global equation is `18 - 30 + 18 = 6`, not source `2`.

The per-component disc reports and the global Euler mismatch are retained as **raw observations only**. Because
Y4 invalidated D1 before Y5, this turn does not use them to conclude that the sphere is cellular/non-cellular or
to confirm/refute the producer-coarsening hypothesis. Independent review must also check whether D1's global
`V/E` and complement `F` belong to one Euler complex before a corrected diagnostic is authorized.

### Torus — fixed control FAIL

- source: `V=72`, `E=216`, `F=144`, `chi=0`;
- D1 network terms: `V=0`, `E=0`, complement-component `F=1`, reported network `chi=1`;
- 0 traces / 0 events;
- one non-disc component with source-topology `chi=0`;
- `networkOnlyCellular=false`.

The topology/non-cellular verdict agrees with the frozen qualitative theorem, but its controlling network counts
do not: **`0/0 != 48/48`**. R2 therefore fails Y4 exactly as the plan specified.

### Two-ring — raw control observation

- source: `V=11`, `E=25`, `F=15`, `chi=1`;
- D1 network terms: `V=9`, `E=11`, complement-component `F=3`, network `chi=1`;
- 3 traces / 8 events;
- 3 disc components;
- `networkOnlyCellular=true`.

This does not rescue R2 after the torus control fails.

## TB-REVIEW Findings

### Finding 1 — D1 torus fixture does not instantiate the frozen product rail authority

- Acceptance criterion: torus must reproduce `networkV=48`, `networkE=48`, `sourceChi=0`,
  `networkOnlyCellular=false`; otherwise STOP.
- Actual result: `networkV=0`, `networkE=0`, `sourceChi=0`, `networkOnlyCellular=false`.
- Classification: **test-authority / structurally invalid fixture / non-stable**.
- Evidence:
  - D1 helper `cp4c_network_only_fixture(...)` builds the atlas and then calls
    `rails_from_atlas(mesh, atlas)` before `FieldAlignedCurveNetwork::make`;
  - `rails_from_atlas` only converts atlas `SourceBoundary`/`HardFeature` non-traversable edges to rails;
  - production builds `AdaptiveFeatureMapBuilder::build(...)` and then
    `build_authoritative_surface_cell_rails(...)` before A2a;
  - the pre-existing product observer consumes `products.authoritativeRails` when reconstructing the A2a network;
  - frozen DEFN §2/X1 records the production torus as 48 `HardFeature` mandatory edges / 48 structural nodes.
- Contract: D1 may be independent of `SurfaceCutGraph`, but its immutable A2a input must still be the same named
  network/witness authority whose frozen theorem it is validating.
- Root cause: the diagnostic substituted a different rail producer while retaining the production witness name and
  frozen expected counts. This repeats the durable lesson that two differently produced objects are two witnesses
  until equivalence is proven.
- Confidence: **high**.
- Evidence gap: no corrected D1 package/runtime exists yet; this turn may not repair the test.

### Finding 2 — sphere Y1 is not admissible for branch selection after the control failure

- Acceptance criterion: Y1-Y4 must all be complete and internally consistent before Y5.
- Actual result: the sphere publishes all components as discs but publishes a global Euler value `6` versus source
  `2`; independently, Y4 already invalidates D1.
- Classification: **evidence insufficient / possible second test-oracle accounting mismatch; not a product finding**.
- Evidence: result artifact `9703233161` and D1 source definitions.
- Contract: D1 must independently establish cellularity from one coherent topology authority, not merely publish
  component and aggregate terms that may belong to different complexes.
- Confidence: **high** that Y5 is unavailable; **not adjudicated** as to the exact second-oracle root cause.
- Evidence gap: static independent review of the D1 global Euler count authority is required before correction.

### Finding 3 — prior product candidate remains unlocalized

`M3-CP4c2-TB-X2-CAND-04` remains **ACTIVE / PRODUCT FAILURE CANDIDATE / UNLOCALIZED / NON-STABLE**. R2 did
not execute D2 and therefore produced no new 419/437/474 localization evidence. The previous
`SurfaceCutGraph::CellularityNotEstablished` observation must not be reinterpreted from this control-invalid run.

## Y1-Y5 Adjudication

| Measure | R2 result |
|---|---|
| Y1 | **NOT ADJUDICATED** — raw publications preserved; D1 invalidated by Y4 before branch use. |
| Y2 | **NOT RUN / UNAVAILABLE** — D2 skipped by required stop rule. |
| Y3 | **NOT ADJUDICATED** — no D2 term-by-term evidence. |
| Y4 | **FAIL / CONTROL INVALID** — torus `V/E=0/0`, required `48/48`; chi=0/non-cellular only partially agree. |
| Y5 | **`selected_r2_branch=NONE`** — Branch A/B/C selection is forbidden on incomplete/inconsistent Y1-Y4. |

`selected_gate=NONE`; `gate_execution_authorized=false`. No 355/357/358 cumulative gate runtime occurred.

## Regression / Accounting Disposition

New candidate:

- `M3-CP4c2-TB-X2-R2-CAND-01` — D1 torus control reconstructs atlas-barrier rails instead of the
  product-authoritative rail witness; **ACTIVE / TEST-AUTHORITY / STRUCTURALLY INVALID FIXTURE / NON-STABLE**.

Existing records:

- X2 CAND-03 remains resolved as the defect of the old X2 measurement design; R2 exposed a new fixture-authority
  defect rather than restoring the old observer.
- X2 CAND-04 remains active/unlocalized because D2 was not reached.

Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**;
M3 package count remains **59** because this Test + Benchmark turn built no package.

## Phase Status

**BLOCKED / diagnostic-control invalid.** Accepted runtime authority remains CP4c-1 TB-R5 **355/355**. CP4c-2
is not accepted and no corrective Y5 branch is selected.

## TB-PLAN — Proposed Bounded Correction, Pending Independent Review

Status: **`proposed_pending_review`**.

If independent review confirms that frozen X1's `48/48` torus numbers are still product-authoritative and that
R2's mismatch is solely diagnostic authority, the smallest next Code + Build should be
`M3-CP4c-2-CB2-DIAG-R1`, test/diagnostic source only:

1. Rebuild the loaded production witnesses' pre-A2a rail input through the same product-authoritative feature-map
   and rail-builder authority used by production, without executing/calling/reusing `SurfaceCutGraph`.
2. Publish the rail-authority identity and mandatory-rail count beside every D1 record so the witness/count
   authority cannot silently diverge again.
3. Independently audit/fix D1's global Euler `V/E/F` terms so the equation uses one explicitly named embedded
   complex; do not encode `48/48` or the sphere outcome merely to satisfy the control.
4. Preserve the two-ring control's explicit intended authority rather than mechanically replacing it with a
   production feature-map path if that changes the scenario being tested.
5. Do not alter production source, `SurfaceCutGraph`, selectors 355/357/358, C1/C3/C6, or any frozen branch rule.
6. Compile/package under GMP/GMPXX with no runtime. A future artifact-only R2 retry must first reproduce the fixed
   torus control from the corrected authority, then execute D2 only if D1 remains valid.

Because the active R2 plan explicitly says a torus control disagreement requires re-adjudication rather than a
workaround, this proposal is **not authorized for implementation by this report alone**. Independent review is
requested.

## Optional Review Decision

- Review: **request**.
- Exact next turn: `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN`, review/planning only.
- Reason: the fixed X1/Y4 theorem authority and the diagnostic fixture authority disagree, and the raw sphere
  publication may expose a second mixed-complex Euler issue. The reviewer must settle those authorities before any
  diagnostic correction or rerun.

## Live Handoff

- Handoff: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `232ac459b13657529e064272a75c5583770a5963`
- Runtime evidence: run/job `33215632118 / 98998526420`, artifacts `9703233161 / 9703233545`
- Accepted predecessor: CP4c-1 TB-R5 355/355
- Current plan status: `selected_r2_branch=NONE`, `selected_gate=NONE`
- Next canonical turn: `M3-CP4c-2-TB-X2-R2-REVIEW-PLAN`
- Successor context: independent Review; no runtime, build, source/test mutation, CB3, or cumulative gate.

# M3-CP4c-2-TB-X2-R8 Artifact-Only Test + Benchmark Report

Date: 2026-08-29 UTC
Status: **SEMANTIC RED / REVIEW + PLAN REQUIRED**

## 1. Verdict

R8 executed the frozen CP4c-2 required-green selector **365** against immutable CB7 package artifact `9724864897` and stopped at the first new-gate red, ordinal **359**:

`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`

The inherited accepted prefix is intact: **355/355 PASS**. New ordinals **356-358 PASS**. Ordinal **359** selected exactly once and failed before its enumeration-invariance comparison because its baseline `SurfaceCutGraph::make(...)` result was false. The frozen hard stop therefore left ordinals **360-365 NOT RUN**. No benchmark ran.

This is not evidence of a product enumeration-invariance regression. Static localization shows the failing identity still constructs rails with the test-local `rails_from_atlas(...)` helper, while the production torus path uses the pipeline-published `authoritativeRails` snapshot. R8's passing ordinal 356 proves that the production torus reaches the real cut-graph/plan path with `networkV=48`, `networkE=48`, `cutEdgeCount=28`, and `torusRegionCount=4`. The red occurs before ordinal 359 compares reordered products.

Per the standing workflow, R8 does **not** retry and does **not** authorize corrective source/test work. Exact successor is independent **`M3-CP4c-2-TB-X2-R8-REV`**.

## 2. Immutable authority and preflight

- semantic product/test source: `4f0f3ca74a88ba260a20c019437bc4995f2056e0`
- build-transport source: `1230621baff6d04fb20df3b1bf48903cd65b5d69`
- package artifact: `9724864897`
- package ZIP SHA-256: `a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`
- packaged source archive SHA-256: `3b4decd367a3fdb932754c3c6e420b536fa7607755e8ff2541f137f1589d5544`
- exact Eigen gitlink: `769c72fd8019e389810d1de1e7c243521a43b594`
- exact arithmetic: GMP/GMPXX
- selector 365 SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- first-361 / first-357 / first-355 hashes re-derived from packaged bytes and matched `61918d9f...0288b / b896d0db...64dc70 / e9d88f11...5afeaa`
- selector cardinality/uniqueness: **365 / 365**
- ordinals 356-365: each resolves to exactly one `TEST(...)` definition
- package internal manifest: **28/28 PASS**
- packaged source status records: clean
- executable mode checks: PASS
- build boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`

The turn explicitly selected gate 365 and authorized exactly this immutable execution before any Directional process ran.

## 3. Authoritative execution

Authoritative run/job: **`33288495471 / 99195869180`**.

Artifacts:

- result `9725240893`, ZIP SHA-256 `056a3597183d6bb40d84038db164c0b8e0d2daea1f05468afc270dcd464a5229`
- log `9725241013`, ZIP SHA-256 `04887ac7727f6f6ae9920366893e6e5da0f34e3e0259f553d7e6b703f086b23f`
- raw evidence tarball SHA-256 `9da936add8204f35832acd0646a395b17bb71b58c56820dd5d1e52f8dcda7aa3`

Execution ledger: **362 fresh processes**, every process with `run_count=1`:

- frozen non-gating: 1
- explicit AF2/AG3 diagnostics: 2
- inherited accepted prefix: **355/355 PASS**
- CP4c-2 tail: 356 PASS, 357 PASS, 358 PASS, **359 FAIL**
- 360-365: NOT RUN by frozen first-red stop

Unconditional postflight: **PASS**. Package and materialized source inventories are byte/mode identical pre/post; manifest re-verifies; all configure/compile/relink/repair/generated-discovery/source/test/fixture/selector/package mutation flags are false. Benchmark execution is false.

### Pre-runtime control attempt

Run `33288435250` failed in the payload-binding step because the caller contained a stale expected Git blob SHA for `m3-cp4c2-r8-exec.sh`. The exact binding check stopped before the execution step; no Directional runtime occurred. The caller hash was corrected, schema validation passed again, and the authoritative run above is the only R8 semantic execution. This is **R8-ORCH-01**, closed orchestration/non-stable evidence and not a semantic attempt.

## 4. First-red localization — ordinal 359

`tests/FieldAlignedCurveNetworkTests.cpp:2335-2408` builds the torus from the committed `torus.obj` + `torus.rawfield`, but then creates rails with:

`rails_from_atlas(mesh, atlas.value())`

and fails at line 2381:

`ASSERT_TRUE(baselineCutGraph);`

No reordered cut graph, cut-edge equality, semantic-digest equality, Euler equality, or face-count equality is reached.

This is the residual of `M3-CP4c2-TB-X2-R7-CAND-01`: CB7 AF3 replaced the synthetic zero-transport field with the production raw field, but did **not** replace the test-local rail reconstruction with the pipeline's production `authoritativeRails` product. The same local construction is also present in ordinal 361, which correctly remained unexecuted after the hard stop.

**Classification:** `M3-CP4c2-TB-X2-R8-CAND-01` — **WITNESS-CONSTRUCTION / AUTHORITY-SURFACE MISMATCH / GATING-IDENTITY / NON-STABLE**. It is a recurrence/continuation of R7-CAND-01, now exposed by the first execution of the newly gated falsifier. No accepted-green behavior was lost, so stable totals do not change.

The independent review must decide the bounded corrective contract. EXEC does not authorize or implement it.

## 5. Required diagnostic findings

### AF0 — originating sphere failure is now visible

The frozen non-gating sphere publisher reports:

`surfaceCutGraphError=CellularityNotEstablished; originatingTopologyError=RotationSystemInconsistent`

with the failure still at `surface-cut-graph`, 24 retained traces, zero mandatory network edges, and no `GlobalTopologyPlan` snapshot. D2 further localizes `errorSourceFace=25-27-28` and reports `producerCutEdgeCount=0`. Therefore the sphere still fails before cut selection; Amendment 14 is not an explanation of this producer failure. The existing prescribed-sphere candidate remains open.

### AF2 — repaired D2 diagnostic executes

`GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable` passes and explicitly publishes `oracleComplex=sourceEdgeBarrier`, `oracleIsCellularityOracle=false`, and `withdrawnBarrierProxySite=proposal-global-certificate`, alongside the real producer error/origin. The withdrawn barrier proxy is diagnostic only.

### AG3 — independent actual embedded graph conditions

`ResolvedBranchCorrection.ActualEmbeddedGraphCellularityOracleIsPublishedNonGating` passes and reconstructs without calling `SurfaceCutGraph`:

- two-ring: `V/E/F=9/11/3`, `chi=1`, `sourceChi=1`, `traceEndpointsAttached=true`, `noDegreeZeroNodes=true`
- torus: `V/E/F=72/76/4`, `chi=0`, `sourceChi=0`, `traceEndpointsAttached=true`, `noDegreeZeroNodes=true`
- prescribed sphere: `V/E/F=18/30/18`, `chi=6`, `sourceChi=2`, `traceEndpointsAttached=true`, `noDegreeZeroNodes=true`, producer still `CellularityNotEstablished`

The sphere's independent non-cellularity finding therefore remains intact.

### AF4 / AD3 and AG5 / AG6 / AG4

AF4's live enumeration falsifier is ordinal 359. Because it fails at witness construction before the semantic comparison, **AD3 remains unresolved**.

The hard stop also prevents the required runtime evidence for:

- ordinal 360 two-ring semantic/provenance gate continuation beyond 359,
- ordinal 361 production-torus semantic/provenance check,
- ordinal 362 torus rotation/face-walk agreement,
- ordinal 363 trace-crossed cut subdivision witness (AG5/AG6),
- ordinal 364 degree-four cut-crossing rotation plus degree-three shape,
- ordinal 365 explicit saturation positive.

No inference from compiled code substitutes for these unexecuted gates.

## 6. Regression/candidate accounting

- `M3-CP4c2-TB-X2-R8-CAND-01`: new non-stable gating-witness failure; continuation/recurrence of R7-CAND-01; active for R8 review.
- `M3-CP4c2-TB-X2-R8-ORCH-01`: pre-runtime stale payload-hash binding; corrected before semantic execution; closed non-stable orchestration.
- accepted inherited 355 remains 355/355; no accepted regression observed.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count remains **65**.

## 7. Stop / successor

CP4c-2 remains **OPEN / RUNTIME-UNACCEPTED**. R8 consumed one immutable gate execution and ended semantic red at ordinal 359. No retry is authorized. `selected_r2_branch=NONE`; gate 365 is the executed frozen authority; `gate_execution_authorized=false` at closeout.

Exact next turn: **`M3-CP4c-2-TB-X2-R8-REV`**, independent Review + Plan only. It must review R8-CAND-01, the incomplete AF3 authority migration, the still-live sphere `RotationSystemInconsistent` origin, and the unexecuted 360-365 tail before authorizing any corrective CB.

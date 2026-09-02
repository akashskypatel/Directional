# M3-CP4c-3-TB11 Artifact-Only Test + Benchmark Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB11`
Status: **COMPLETE / VALID SEMANTIC RED / NON-STABLE**

## 1. Immutable authority and execution boundary

TB11 consumed immutable package **81** only. Semantic/package source is `3070173894ee097f631b96c1c6d29f276df89a66`; package artifact `9834661539` has Actions SHA-256 `10e18bc81c2f850a1e7bc3d4ce16830a5d5ebe7d1992cd728c1bb043dc71cb2f`, inner `package81.tar.gz` SHA-256 `4f49b3de157e51aff05736f9ac4b210372eb4bfb4dec3ddc793869071b2f9d88`, and packaged source tar SHA-256 `752cb9da86dbae5fd4d0122f5a5538c8e6431be4c8e02c302a8a93e05c25a1bf`.

Selector **377** remained byte-frozen at `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`; its first 365 identities reproduce `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. The non-gating diagnostic `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` is not in selector 377 and received zero gate credit.

Authoritative run/job: **`33611378451 / 100187075757`**, workflow conclusion success. Result artifact **`9839236420`**, SHA-256 `1f803fc725ecf5bcfd66891cdd70e1746e1cb28faf7bfebc5284f38c988e734a`; log artifact **`9839236880`**, SHA-256 `fb9350c7b8e1d464f6802cdb1da59c34dab5e264925fccd1c63b6ed8e255ab74`.

Boundary flags: `runtimeExecution=true`; `configureExecution=false`; `compileExecution=false`; `relinkExecution=false`; `packageRepair=false`; `generatedDiscovery=false`; product/test/fixture/selector mutation all false; `benchmarkExecution=false`.

## 2. Gate result

All 377 selector identities ran in exactly one fresh process each: **369 PASS / 8 RED**. Ordinals **1–365 are 365/365 PASS**. First red remains ordinal **366**, so accepted authority does not advance. Report-only reds are 367, 368, 369, 370, 371, 372 and 374. Ordinal **377 PASS**. The old CB12 ownership condition/seed pair did not recur.

The non-gating diagnostic ran once in its own fresh process and returned RED solely because that diagnostic deliberately emits its observation with a failing assertion; it carries **zero gate credit**.

## 3. BF9 discriminator — ordinal 366 is now localized

Ordinal 366 reports:

`NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent;detailCode=CellularityNotEstablished;sourceVertex=47;rotationSystemReason=RotationRayOrderKeyCollision;cutCandidateCount=450;nonDiscComponentCount=0;remainingAdmissibleEdgeCount=0;certificationAttempt=0;certificationCutEdges=0`

This discharges the CB13 diagnostic owner. The formerly hidden producer condition is **`RotationRayOrderKeyCollision`**, at **source vertex 47**, on **certification attempt 0** with **0 cut edges**. The cut-candidate inventory contains 450 candidates; non-disc component count is 0 and remaining admissible edge count is 0.

Static package-81 source maps this reason to exactly one producer phase: **`build_rotation_system`**. The error is emitted after outgoing `RayOrderKey` records are constructed and sorted, while validating adjacent sorted trace-ray keys for an equal `primary` and `secondary` pair, and before the final counter-clockwise rotation is published. Therefore it is **after fan/ray keys are constructed and after their sort, during post-sort collision validation**. A `walk_graph_faces` or exterior-boundary failure did not occur; the prior fan/ray-ordering hypothesis is supported as a localization hypothesis, but no semantic correction is authorized by this TB result.

The non-gating diagnostic independently re-derived the same stage and reason from production inputs: furthest retained stage `field-aligned-network`, failed stage `surface-cut-graph`, cut-graph error `CellularityNotEstablished`, originating topology error `RotationSystemInconsistent`, and originating reason `RotationRayOrderKeyCollision`.

## 4. Red categorization

| Ordinal | Result | Disposition |
|---:|---|---|
| 366 | `RotationRayOrderKeyCollision`, sourceVertex 47, cert attempt 0 / 0 cut edges | **GATING / NEWLY DISCRIMINATED SEMANTIC CONDITION / ROOT CAUSE UNADJUDICATED.** Open `M3-CP4c3-TB11-CAND-01`; independent review must determine whether the collision is a product-key defect, duplicated/stale incidence, genuine coincident trace rays, or witness/precondition issue before any fix. |
| 367 | same exact mechanical exception as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED by TB11-CAND-01.** No duplicate event. |
| 368 | `TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable` | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-CAND-04`, unchanged.** |
| 369 | `saturationUsed=true`, expected false | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-R10-CAND-01`, unchanged.** |
| 370 | actual code `CellularityNotEstablished` (4), expected `EmptyNetworkOnClosedSurface` (6); source-face absent | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-R8-CAND-02`, unchanged.** |
| 371 | same exact mechanical exception as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED by TB11-CAND-01.** Existing test-coupling candidate remains deferred. |
| 372 | same exact mechanical exception as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED by TB11-CAND-01.** Existing test-coupling candidate remains deferred. |
| 374 | `atlasBuild=false` | **REPORT-ONLY / EXISTING `M3-CP4c3-TB7-CAND-02`, unchanged.** |

The diagnostic-only gap `M3-CP4c3-TB10-CAND-01` is **CLOSED / RUNTIME DISCRIMINATED** by TB11. The newly observed semantic condition is tracked separately as `M3-CP4c3-TB11-CAND-01`; this is a continuation of the same unaccepted first-red surface and adds **+0 stable events / +0 recurrences**.

## 5. Immutable postflight

The complete package-tree byte/mode census is identical before and after all 377 selector processes plus the one non-gating diagnostic process. The internal `SHA256SUMS` manifest verifies after execution. No package repair, rebuild, relink, discovery, source/test/fixture/selector mutation, or benchmark occurred.

## 6. Accounting and exact successor

Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable regression accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3 package count remains **78**.

Exact successor: **`M3-CP4c-3-TB11-REV` — independent REVIEW + PLAN only**, under `Architecture_M3_CP4c3_TB11_Independent_Review_Plan.md`. No runtime, compile, package, product/test/fixture/selector mutation, or unchanged TB retry belongs in that review.

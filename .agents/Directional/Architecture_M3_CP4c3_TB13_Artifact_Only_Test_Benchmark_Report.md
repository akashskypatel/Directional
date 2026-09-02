# M3-CP4c-3-TB13 Artifact-Only Test + Benchmark Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB13`
Status: **COMPLETE / VALID SEMANTIC RED / NON-STABLE**

## Immutable authority and execution boundary

TB13 consumed immutable package **83** only. Semantic/package source is
`a2fd98eaa015ff5872890bb1945cf4e9e9493615`; package artifact `9861269273` has Actions SHA-256
`1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4`, inner `package83.tar.gz` SHA-256
`c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff`, and packaged source tar SHA-256
`55305976488edc1edc13432e953787555c5ef5d4dcaff041617c0ae568d922c2`.

Selector **379** remained byte-frozen at `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`;
selector 378 is its exact first-378 prefix at `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`,
and the first 365 identities reproduce accepted authority
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. The separate diagnostic
`GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` is not in selector 379 and received zero gate
credit.

Authoritative run/job: **`33671968437 / 100387569925`**, workflow conclusion success. Result artifact
**`9862995609`**, Actions SHA-256 `d7da71ea122a20225e6e3e7b9f2534fd3a7d8c1b1401ebc64b5f1191eb21bb8b`;
log artifact **`9862996106`**, Actions SHA-256
`b9a6288472f0ec204f93aa0f209b457c365e4c8ecf98e166c100c99bb3f6caf4`. Environment: GitHub-hosted Ubuntu
24.04.4 / runner image `ubuntu-24.04` version `20260831.293.1`.

Boundary flags: `runtimeExecution=true`; `configureExecution=false`; `compileExecution=false`;
`relinkExecution=false`; `packageRepair=false`; `generatedDiscovery=false`; product/test/fixture/selector mutation
all false; `benchmarkExecution=false`.

Control-plane process note: the turn ultimately selected mandatory **`READ_MODE=snapshot`** and used source-snapshot
run `33670596596` / artifact `9862348183` for consolidated inspection. Two repository documents were fetched before
the mandatory read-mode declaration even though the checklist already implied more than three repository files.
That is a `TOOL_USE_CONSERVATION_POLICY.md` Step-2 process-order deviation. Piecemeal inspection stopped
immediately, snapshot mode was adopted, and the deviation changed no package, selector, runtime, product, or gate
evidence.

## Gate result

All 379 selector identities ran in exactly one fresh process each: **371 PASS / 8 RED**. Ordinals **1-365 are
365/365 PASS**. First red remains ordinal **366**, so accepted authority does not advance. Report-only reds are 367,
368, 369, 370, 371, 372 and 374. Ordinals 373, 375, 376, 377, 378 and the new CB15 witness **379 PASS**. The separate
non-gating mechanical diagnostic ran once in its own fresh process and returned RED because that identity
intentionally emits its retained stage observation with a failing assertion; it carries zero gate credit.

## BJ9 discriminator result

1. **PASS — accepted boundary preserved.** Ordinals 1-365 remain 365/365.
2. **PASS — old v47 rejection is absent.** Ordinal 366 no longer reports `RotationRayOrderKeyCollision` at source
   vertex 47.
3. **NOT PROVED — production did not reach the required v47 census.** Ordinal 366 now fails earlier at source
   vertex 10. Therefore the artifact contains no v47 five-ray rotation census and no retained `secondary` values for
   arc 20 / trace 6 / Forward / origin 47 or arc 23 / trace 9 / Reverse / origin 71. This is not evidence that those
   two rays still tie; it is a reachability/evidence gap caused by the new earlier red.
4. **PASS — moved residual red preserved exactly.** Ordinal 366 reports:

   `NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent;detailCode=CellularityNotEstablished;sourceVertex=10;sourceFace=8,10,11;rotationSystemReason=VertexTracePortOrdinalInvalid;cutCandidateCount=450;certificationAttempt=0;certificationCutEdges=0`

   `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are absent and therefore remain legitimately
   unmeasured on this path.
5. **NOT SATISFIED — TB11 candidate remains open.** The required 1+2+3 conjunction is false because discriminator
   3 is unavailable. `M3-CP4c3-TB11-CAND-01` therefore does not close in TB13.

The appended selector-379 witness
`GlobalTopologyPlan.VertexLocusSecondaryRankUsesExactWithinWedgeGeometry` **PASSes**, proving the compiled helper
contract itself executes successfully. It does not substitute for the missing production-path v47 discriminator.
There remains **no vertex-30 discriminator**.

## New first-red classification

The new production failure is at the vertex-locus trace-ray construction path, but TB13 does **not** establish the
semantic root cause. Package source assigns the same reason `VertexTracePortOrdinalInvalid` to two different
conditions in `build_rotation_system`:

- missing singularity port or negative origin-port ordinal; and
- failure of the new exact `vertex_locus_secondary_parameter(...)` computation.

The second helper can fail for several distinct structural reasons: unavailable ray face/face record/locus corner,
unavailable second point, or an invalid exact opposite-edge denominator. The retained ordinal-366 error identifies
source vertex 10 and face `(8,10,11)` but does not retain the failing arc, trace, orientation, or which of those
conditions fired. The exact cause is therefore **underdetermined by current runtime evidence**. Treating the
semantic-sounding reason as proof of an origin-port defect would repeat the project's documented collapsed-reason
failure mode.

This opens non-stable gating candidate **`M3-CP4c3-TB13-CAND-01`**: **PRODUCT / DIAGNOSTIC AMBIGUITY / FIRST-RED
MOVED TO V10**. Independent `M3-CP4c-3-TB13-REV` owns adjudication before any correction is authorized.

The separate mechanical diagnostic independently confirms the new reachability boundary: furthest stage
`field-aligned-network`, failed stage `surface-cut-graph`, `surfaceCutGraphError=CellularityNotEstablished`,
`originatingTopologyError=RotationSystemInconsistent`, and
`originatingRotationSystemReason=VertexTracePortOrdinalInvalid`; no `GlobalTopologyPlan` snapshot is published.

## Red categorization

| Ordinal | Result | Disposition |
|---:|---|---|
| 366 | `VertexTracePortOrdinalInvalid`, source vertex 10, face `(8,10,11)`, attempt 0 / 0 cut edges | **GATING / NEW NON-STABLE PRODUCT-DIAGNOSTIC AMBIGUITY.** `M3-CP4c3-TB13-CAND-01`; exact emitter condition underdetermined. |
| 367 | same exact mechanical exception as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED by TB13-CAND-01.** No duplicate event. |
| 368 | `TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable` | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-CAND-04`, unchanged.** |
| 369 | `saturationUsed=true`, expected false | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-R10-CAND-01`, unchanged.** |
| 370 | actual typed code 4 vs expected `EmptyNetworkOnClosedSurface` code 6; source face absent | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-R8-CAND-02`, unchanged.** |
| 371 | same exact mechanical exception as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED.** Existing 371/372 coupling candidate remains deferred. |
| 372 | same exact mechanical exception as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED.** Existing 371/372 coupling candidate remains deferred. |
| 374 | `atlasBuild=false` | **REPORT-ONLY / EXISTING `M3-CP4c3-TB7-CAND-02`, unchanged.** |

`M3-CP4c3-TB12-REV-CAND-01` is **PARTIALLY RUNTIME DISCRIMINATED / BLOCKED BY EARLIER NEW RED**: accepted 365/365
and the selector-379 focused witness pass, and the old v47 collision is absent at ordinal 366, but the production
five-ray/distinct-rank proof was not reached. `M3-CP4c3-TB11-CAND-01` remains active for the same reason. Stable
accounting changes by **+0 events / +0 recurrences** because CP4c-3 is still unaccepted and the new datum is a
non-stable successor on the same gating surface.

## Immutable postflight

The complete package-tree byte/mode census is identical before and after all 379 selector processes plus the one
non-gating diagnostic process. The internal `SHA256SUMS` manifest verifies identically before and after execution.
No package repair, rebuild, relink, configure, generated discovery, source/test/fixture/selector mutation, or
benchmark occurred.

## Phase status and exact successor

TB13 is **complete / valid semantic red / regressed relative to the intended v47 re-proof**, with no accepted-green
loss. Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable regression accounting remains **44
events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3 package count remains
**80**.

Optional independent Review is **required** by the red-TB workflow. Exact successor:
**`M3-CP4c-3-TB13-REV` — independent REVIEW + PLAN only**, under
`Architecture_M3_CP4c3_TB13_Independent_Review_Plan.md`. Do not rerun TB13, patch the product, append a selector
identity, or infer the failing secondary-parameter subcondition before that review.

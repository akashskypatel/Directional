# M3-CP4c-1 TB-R4 Artifact-Only Test + Benchmark Report

## Verdict

`M3-CP4c-1-TB-R4` is **COMPLETE / VALID SEMANTIC RED 354/355 / CHECKPOINT OPEN**.

Authoritative artifact-only run/job `33141046678 / 98751794167` consumed immutable CB3 GMP package
`9673249952` from semantic/test source `66a065b5e07910568a317e24f0fc6b93d890d104`. The accepted
CP4c-0b prefix re-proved **353/353 green**. C4, ordinal 354, passed. C5, ordinal 355,
`FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`, selected exactly
once and returned a valid semantic red. The five historical diagnostics all selected exactly once and
remained trustworthy report-only observations with zero gate credit. Immutable preflight/postflight passed.

Per the binding workflow, a red TB routes directly to **`REVIEW + PLAN`**. There is no retry and no
correction inside this turn. `M3-CP4c-1` remains open, CP4c-2/3 remain blocked, and exact successor is
**`M3-CP4c-1-TB-R4-REVIEW-PLAN`**.

## Authority

- run/job: `33141046678 / 98751794167`
- immutable package artifact: `9673249952`, `m3-cp4c1-cb3-compile-result-33139188595`
- package ZIP / GitHub artifact SHA-256: `17a3f8da793fc20562e5ec2f0ab441d39f795dd146171e989fb952e6f942d2ea`
- semantic/test source: `66a065b5e07910568a317e24f0fc6b93d890d104`
- source archive SHA-256: `3ba7e745a25dddbacd0e18b79672ebac5a8e94a944ed45c60174216f2770c628`
- exact arithmetic backend: **GMP**, with GMP/GMPXX runtime dependencies present
- required selector: **355**, SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- accepted 353 prefix: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- accepted 346 prefix: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
- accepted 316 prefix: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- non-gating selector: **5**, SHA-256 `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`
- result artifact: `9674006723`, digest `sha256:d8c02733475e93f10b0868507e0ce2d4398b93d24bdec6a5076febbd6fd0a514`
- persistent log artifact: `9674006927`, digest `sha256:19e9a0398bc400dfaf16f4601d181389940c2de8438240b7cb3a5e25c0aec5c8`

## Immutable preflight and postflight

Preflight is **PASS**. The workflow verified the exact artifact ID/name/digest, all **28/28** package
manifest entries, semantic-source metadata, zero preflight/build exit codes, clean packaged source-status
snapshots, `runtimeExecution=false` build boundary, GMP/GMPXX evidence and runtime dependencies, six
packaged executable modes, source-archive hash, both selector hashes/cardinalities, the 316/346/353 prefix
hashes, and exact C4/C5 ordinals.

The pre-runtime byte-and-mode inventory covered package files, extracted source, fixtures, selectors, and
executables. Postflight is **PASS** and the post-runtime inventory is byte-for-byte equal to preflight.
The run records `configureOccurred=false`, `compileOccurred=false`, `relinkOccurred=false`,
`repairOccurred=false`, `generatedDiscoveryOccurred=false`, and `mutationOccurred=false`. No repository
or per-identity timeout was imposed on the complete gate.

## Required 355-identity gate

Every required identity executed in frozen selector order in a fresh process with an exact filter.

- ordinals 1–316: **316/316 PASS**
- ordinals 1–346: **346/346 PASS**
- ordinals 1–353: **353/353 PASS**
- ordinal 354 / C4: **PASS**, selected 1, exit 0, failures 0, 4,907 ms
- ordinal 355 / C5: **RED**, selected 1, exit 1, failures 1, 4,255 ms
- full required gate: **354/355 PASS**
- zero/multiple-selected: **0**
- escaping `C++ exception with description`: **0**
- first red: ordinal **355**, C5
- slowest required identity: **28,841 ms**
- performance acceptance benchmark: **not applicable**

The accepted 353 prefix therefore did not regress. CP4c-1 remains open solely on checkpoint-local C5 in
this run.

## C4 result

`FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing` is **PASS**. The identity selected an
actually produced terminal `TraceIntersection`, changed the terminal incidence to `Interior`, submitted
the tampered validation candidate, and observed fail-closed rejection with
`InvalidNetworkEventIncidence`. C4 is satisfied without test or product re-authoring.

## C5 result and review candidate

`M3-CP4c1-TB-R4-CAND-01` is **ACTIVE / REVIEW REQUIRED / NON-STABLE**.

C5 produced two independent assertion failures:

1. helper `record_terminal_event_contract`, `tests/FieldAlignedCurveNetworkTests.cpp:4713`, asserts every
   supplied witness network has non-empty `candidate_traces()`. The torus network is valid but has
   `networkTraceCount=0`, `networkEventCount=0`, and no produced terminal-event kinds; its later
   `GlobalTopologyPlan` attempt rejects `UncutFaceComponentOrbitSeedNotUnique`.
2. C5 at `tests/FieldAlignedCurveNetworkTests.cpp:6701` asserts
   `producedTerminalKinds.size() == 2`; runtime produced **3** terminal kinds. Its failure message proves
   the required named contributors are both present — `TraceIntersection=prescribed sphere` and
   `MandatoryBarrierTermination=two-ring` — while the prescribed sphere additionally publishes terminal
   kinds `2,4`. Source enum authority maps kind `4` to `SingularityTermination`.

The evidence supports an **authority tension, not an in-TB fix**. The frozen plan's completion wording
requires every trace to terminate at an actually produced typed kind and both `TraceIntersection` and
`MandatoryBarrierTermination` to be represented non-vacuously; that wording does not by itself require
every witness to produce a trace. The same plan also says C5 should observe “exactly the required
terminal event-kind set,” which may be read as an intentional two-kind cardinality. The mandatory review
must re-derive which reading is normative and determine whether the torus precondition and/or exact
cardinality are stale test authority or whether the extra produced `SingularityTermination` is a real
C5 contract violation. This TB does not adjudicate, weaken, demote, edit, or rerun C5.

Because C5 has never been accepted and the accepted 353 prefix is green in the same immutable run, this
red establishes **no accepted-green regression** and adds **+0 stable events / +0 recurrences** pending
review.

## Five non-gating diagnostics

All five selected exactly once; all five returned red; none escaped a C++ exception; all grant **zero
gate credit**. Their red state is trustworthy and consistent with their historical report-only role.

| # | Identity | ms | Classification |
|---:|---|---:|---|
| 1 | `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable` | 46 | expected report-only red; source unconditionally `FAIL()`s with the reachability report; torus reaches A2a/network with 0 traces/events, then A2b fails `UncutFaceComponentOrbitSeedNotUnique` |
| 2 | `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` | 79 | expected report-only red; source unconditionally `FAIL()`s; mechanical stops in A1 with `IncompleteCycleBasis` |
| 3 | `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` | 4,115 | expected report-only red; source validates sphere preconditions then unconditionally `FAIL()`s; sphere publishes 24 traces / 56 events, then A2b fails `RotationSystemInconsistent` |
| 4 | `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique` | 6,308 | stale historical failure-precondition diagnostic; it expects sphere network construction to fail, but current accepted authority now produces the sphere network |
| 5 | `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable` | 4,182 | stale historical failure-precondition diagnostic; it expects `sphere.network.has_value()==false`, while current accepted authority produces the network |

These observations are not candidate regressions and do not change gate arithmetic.

## Process-order control candidate

`M3-CP4c1-TB-R4-CAND-02` is **RESOLVED / PROCESS-ORDER / NON-STABLE**. This ChatGPT Web turn began
repository source/document inspection before performing the mandatory per-turn policy read and before
declaring `READ_MODE=snapshot`. That violated `TOOL_USE_CONSERVATION_POLICY.md` Step 2. The miss was
recognized during closeout; piecemeal inspection stopped, the turn switched to snapshot mode, and durable
source-snapshot run `33141471428` captured exact control head
`7e5d30854e0d776bae5bad282c5aad1a45bbae45`. Snapshot artifact `9674093771` has digest
`sha256:36957a482d62913a6ca1ec694b43d85e8772c1d1c2d77c7c8e8aa4422404850e`; its metadata records archive
SHA-256 `b68e2e178fc51982d4c99edf1c263c9e1ea08405eb9c9fc63ffb7c1a16b5b55d`. Subsequent static inspection
used that local snapshot.

This is a process/control-order defect, not semantic evidence against Directional. It changed no package,
selector, fixture, source, runtime command, or gate result. Stable counts do not change. Do not repeat the
miss in the successor review: the mandatory policy reads and `READ_MODE` choice must precede its first
repository source/document inspection.

## Regression accounting

`M3-CP4c1-TB-R4-CAND-01` is the sole semantic red candidate and remains **ACTIVE / REVIEW REQUIRED**.
`CAND-02` is resolved process-order/non-stable. No accepted-green identity regressed: the predecessor
authority is **353/353 green in this same run**. Stable accounting remains **42 events / 14 categories /
28 recurrences**, produced-witness debt remains **5**, and M3 package count remains **56**.

## Disposition and successor

TB-R4 is valid semantic evidence but not acceptance: **354/355** is red. Under the binding cadence,
`M3-CP4c-1` stays open and no retry or correction is permitted before independent review and planning.

Exact next turn: **`M3-CP4c-1-TB-R4-REVIEW-PLAN`**. It must re-derive C5 from source and frozen authority,
adjudicate `M3-CP4c1-TB-R4-CAND-01`, check the witness preconditions, state a falsifiable successor
prediction, and enumerate checks hidden behind any authorized correction. CP4c-2/3 remain blocked.

# M3-CP4c-1 TB-R5 Artifact-Only Test + Benchmark Report

## Verdict

`M3-CP4c-1-TB-R5` is **COMPLETE / GATE GREEN 355/355 / CHECKPOINT CLOSED / ACCEPTED**.

The authoritative artifact-only run consumed immutable CB4 GMP package `9675666067` from semantic/test source
`b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. The complete ordered 355-identity gate passed, W3's two
previously masked named-kind checks were proved reached and passing, the frozen terminal-kind prediction matched
exactly, the three remaining historical diagnostics stayed report-only with zero gate credit, the W3 two-ring
report identity passed, both W5-retired identities were absent, and immutable package/source postflight passed.
No configure, compile, relink, repair, generated discovery, source/test/fixture/selector mutation, or benchmark
acceptance run occurred.

A green TB closes the checkpoint under the durable workflow. **`M3-CP4c-1` is CLOSED / ACCEPTED.** Exact
successor is definition-only **`M3-CP4c-2-DEFN`**. This report does not enter that turn.

## Authority

- authoritative run/job: `33161644741 / 98817323175` — **PASS**
- workflow schema-validation job: `98817274792` — **PASS**
- control head executing the frozen plan: `f9ec304c692a73f1630c80618510acd672fe5a8a`
- semantic/test source under validation: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`
- immutable GMP package artifact: `9675666067`
- package artifact digest: `sha256:63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`
- packaged source archive SHA-256: `baead768e6f05acc7b09177a1571139262a514056cfc4fa281b8933135b6fc84`
- required selector: **355**, SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- frozen prefixes: **316** `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; **346** `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; **353** `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- non-gating selector: **3**, SHA-256 `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`
- result artifact: `9681960334`, digest `sha256:b8be035ed728b5d6f8efe65e260f9557a9aa8cad0e82b94d11107aab44187a5d`
- persistent log artifact: `9681960615`, digest `sha256:55ad320aaf810bb5b02fbfccdd7662f4a47333586bdb30397d624d701710439b`
- exact arithmetic backend: **GMP**

## Plan execution

The frozen CB4 TB-R5 plan was executed without semantic deviation.

- plan items completed: immutable preflight; ordered 355 gate; W3 named-check proof; three selector diagnostics;
  explicit W3 two-ring report identity; retired-identity absence check; immutable postflight
- blocked/skipped plan items: none
- stop conditions encountered: none
- retries: none; no unchanged deterministic rerun was performed
- performance benchmark: not applicable to this correctness checkpoint

## Immutable preflight

Preflight is **PASS**. The workflow verified the exact package digest, all **28** packaged `SHA256SUMS` entries,
semantic source identity, build/preflight exit codes, clean source-status snapshots, `runtimeExecution=false`, GMP
runtime evidence, packaged source archive digest, the 355 required-selector count/hash, all three frozen prefix
hashes, C4/C5 at ordinals 354/355, the three-entry non-gating selector, and absence of the two W5-retired
identities before executing any Directional binary.

## Full ordered gate

Every required identity executed in its own fresh process and selected exactly once.

- first 316: **316/316 PASS**
- first 346: **346/346 PASS**
- first 353: **353/353 PASS**
- C4 ordinal 354, `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`: **PASS**
- C5 ordinal 355, `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`: **PASS**
- full gate: **355/355 PASS**
- zero-selected identities: **0**
- first red ordinal: **none**
- escaping C++ exceptions: **0**

This is the first immutable whole-gate authority in which the accepted 353 predecessor, C4, and the corrected C5
are all green together.

## W3 — named terminal-kind proof and exact contributor map

W3 is **PASS**. CB4 removed the fatal over-specifications that previously prevented C5's named membership checks
from executing. The frozen source control flow contains the two named checks, and C5 now runs through them to a
passing test result. The TB control therefore records both individually:

- `TraceIntersection` membership check: **executed and passed**
- `MandatoryBarrierTermination` membership check: **executed and passed**

The observed terminal-kind union exactly matches the independent review's falsifiable prediction:

| Kind | Enum value | Contributor(s) |
|---|---:|---|
| `TraceIntersection` | 2 | prescribed sphere |
| `MandatoryBarrierTermination` | 3 | two-ring |
| `SingularityTermination` | 4 | prescribed sphere |

No additional kind was observed. The pipeline-authoritative torus contributes **zero** terminal kinds. The
mechanical witness remains guarded out upstream at `field-transport-atlas/IncompleteCycleBasis`, exactly as
predicted. The explicit report-only identity
`ResolvedBranchCorrection.TwoRingContactPairingCensusIsPublishedNonGating` also **PASS**es and publishes three
traces, each with exactly one terminal kind, all three barrier-terminating, with the existing two-ring contact/
barrier pairing evidence intact.

`predictionMet=true` is therefore evidence-backed rather than inferred from gate count alone.

## Report-only diagnostics and W5 retirement

The three frozen selector diagnostics each selected exactly once and returned their intentional publisher reds.
They receive **zero gate credit** and do not alter the 355/355 result:

1. `GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable` — report-only RED; A2a network present with
   zero traces/events; later A2b failure `UncutFaceComponentOrbitSeedNotUnique` remains observable.
2. `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` — report-only RED; fails upstream at
   `field-transport-atlas/IncompleteCycleBasis` as predicted.
3. `GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable` — report-only RED; publishes the
   prescribed-sphere reachability/network evidence used by W3.

The two W5-retired inverted diagnostics are absent from the non-gating selector and did not execute:

- `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`
- `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`

That satisfies the runtime closure condition for `M3-CP4c1-TB-R4-CAND-03`.

## Immutable postflight

Postflight is **PASS**. Package and extracted-source byte/mode inventories match their pre-runtime inventories.
The result records:

- `configureOccurred=false`
- `compileOccurred=false`
- `relinkOccurred=false`
- `repairOccurred=false`
- `generatedDiscoveryOccurred=false`
- `mutationOccurred=false`
- `immutablePostflight.packageMatch=true`
- `immutablePostflight.sourceMatch=true`

No package, source, test, fixture, selector, or executable byte was repaired or changed to obtain the green gate.

## TB-REVIEW findings

### C5 authority after the CB4 correction

- acceptance criterion: C4/C5 remain gating and CP4c-1 closes only on 355/355 with the independent review's §8
  prediction met
- actual result: **355/355**, exact predicted union/contributors, both named checks passed
- classification: **accepted behavior / no defect**
- root cause of prior TB-R4 red: already adjudicated test-side over-specification; no new evidence reopens it
- confidence: high; full predecessor and checkpoint-local gate passed in one immutable run

`M3-CP4c1-TB-R4-CAND-01` remains **RESOLVED / TEST-SIDE OVER-SPECIFICATION / NON-STABLE**.

### Retired inverted diagnostics

- acceptance criterion: neither W5-retired identity survives as an unexplained red
- actual result: both are absent; surviving report-only coverage executed as planned
- classification: **RESOLVED / TEST-SIDE INVERTED PRECONDITION / NON-STABLE**
- candidate: `M3-CP4c1-TB-R4-CAND-03`

No accepted-green identity regressed. No evidence justifies a new stable event/category/recurrence.

## Accounting

Stable regression accounting remains **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains
**5**. TB-R5 creates no build package, so M3 packages remain **57**.

## Phase status and successor

**Complete. `M3-CP4c-1` is CLOSED / ACCEPTED.** No corrective Code + Build plan is required and no optional
independent review is requested: the green result exactly matches the pre-committed falsifiable prediction.

The next checkpoint is **`M3-CP4c-2`**, and its required first turn is definition-only
**`M3-CP4c-2-DEFN`**. The historical parent allocation gives CP4c-2 C1/C3/C6; rebased on the accepted 355 prefix,
its prospective cumulative gate is **358 = 355 + C1 + C3 + C6**. That arithmetic is trajectory information only:
`M3-CP4c-2-DEFN` must settle the closed/higher-genus A2b contract before any implementation, selector refreeze, or
runtime is authorized.

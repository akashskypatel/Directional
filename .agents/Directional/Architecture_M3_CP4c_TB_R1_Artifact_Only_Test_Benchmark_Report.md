# Architecture M3 CP4c TB-R1 — Artifact-Only Test + Benchmark Report

**Date:** 2026-08-24 UTC  
**Turn:** `M3-CP4c-TB-R1`  
**Status:** **COMPLETE / VALID RED — independent review required**

## 1. Boundary and authority

This turn consumed the immutable CB2 package only. No configure, build, relink, repair, generated test discovery, source/test/fixture/selector mutation, or package mutation was permitted or observed.

- semantic source: `a5edb1a31c315d51df216f3bb51470989ff64e33`
- immutable package artifact: `9541369624`
- package ZIP SHA-256: `bb636eac863475ce41c336713ce7344c11d4a4ed6cd85a6b04634d083a03a778`
- packaged source archive SHA-256: `03e7c09d45715de96f1c58ec6cf21b32ca1b542078cfe196ea359c98dea8de66`
- accepted 316 evidence artifact: `9531769503`, SHA-256 `1b4b3784d55f398d113b18c5bc84543cad9f03c48d329d91005598d63ed801fc`
- authoritative run/job: `32791027809 / 97632461750`
- event SHA: `21eee9afe77029aae8ec88f03e0c13d3335b4d64`
- runner: Ubuntu 24.04.4 / `ubuntu-24.04` image `20260816.277.1`
- exact reconstructed TB runner SHA-256: `8cf42c19bd2dd73d6fcae8860b825920c0b1479dcda917b978de67dbcb16930a`

## 2. Frozen selector authority

The gate reconstructed only previously frozen identities; no discovery/list command was used.

| Surface | Count | SHA-256 |
|---|---:|---|
| accepted predecessor | 304 | `c05a4c4329d7e01a47fd1ecb094be438595533bf90585b24b94a3c4221ffb666` |
| CP4ab | 12 | `7e7e32f147a2e865d75b1882542e0295527aa4f709bbc4bd1cf6974416d234ec` |
| accepted prefix | 316 | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| CP4c C1–C6 | 6 | `c187acbadf238992d85e9dcfb0f5bf96916bbb37402449803e6714622c7c4276` |
| cumulative gate | 322 | `981511637bfe17b4ed1f359305e285f618f14c006b9d78a76a83c0795eb899cd` |

The cumulative selector's first 316 entries are byte-identical to accepted authority.

## 3. Gate result

The run is **VALID RED**, not INVALID:

- exactly **322 processes**
- exactly **322 tests executed**
- accepted prefix: **316/316 PASS**
- CP4c C1–C6: **0/6 PASS**
- cumulative: **316/322**, six failures
- orchestration errors: **0**
- disabled tests: **0**
- acceptance attempt **1/3 consumed**
- diagnostics remain **1/2**
- `runtimeExecution=true`
- configure/build/relink/repair/generatedDiscovery: all `false`
- source/test/fixture/selector/package mutation: all `false`
- post-cleanup runtime material absent: `true`

Because all 316 accepted identities are green in the same immutable run, TB-R1 does not establish any accepted-behavior regression.

## 4. Exact CP4c failures

| ID | Frozen identity | Observed first failure |
|---|---|---|
| C1 | `GlobalTopologyPlan.TorusWitnessDerivesRegionsThroughProductionEntryPath` | torus production witness throws: `NotProductionReady/global-topology-plan/RegionCutComponentCountDeficit` |
| C2 | `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` | mechanical witness throws: `InvalidFieldTransportAtlas/field-transport-atlas/IncompleteCycleBasis` |
| C3 | `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` | same torus `RegionCutComponentCountDeficit` before assertion |
| C4 | `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing` | no actually produced terminal `TraceIntersection`; test requires one for non-vacuous tamper |
| C5 | `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced` | expected two produced terminal event kinds; observed one |
| C6 | `GlobalTopologyPlan.ProducedWitnessRegionsCarryDiscProofAndMandatoryPreservation` | same torus `RegionCutComponentCountDeficit` before assertion |

`firstStructuredTypedRejection` is null in the generic extractor because these failures are surfaced through C++ exceptions/assertions rather than one of the extractor's structured key patterns; the per-identity stdout/stderr/raw records preserve the exact messages above.

## 5. Review disposition

The reds divide into two first-acceptance candidate families.

**Production-witness capability / precondition seam (C1/C2/C3/C6).** The committed witnesses do not reach the frozen CP4c proof point: torus cannot retain a global topology plan and mechanical cannot establish the transport atlas. The binding plan §9 states that when witness expectations fail, the witness is the subject and constants must not be adjusted to match observation.

**Event non-vacuity seam (C4/C5).** The accepted CP3b event fixture still satisfies its accepted contracts, but it does not produce the stronger terminal-`TraceIntersection` witness demanded by CP4c C4/C5. This is a witness/non-vacuity mismatch, not a regression of accepted CP3b behavior.

The binding stop condition therefore fired. Exact successor is `M3-CP4c-TB-R1-INDEPENDENT-REVIEW`. Review must decide whether the committed witnesses are replaceable/repairable within frozen semantics or whether a DEFN §8.2 / terminal-event precondition is unsatisfiable as authored. It must not weaken an identity or accepted CP4ab/CP3b expectation to force green.

No acceptance attempt 2/3 and no reserve diagnostic 2/2 is authorized before that review.

## 6. Immutable evidence

- result artifact `9543166006` — SHA-256 `53686b44d055a9188ba92008c74b27d08c7daa6ed53611f1490b6c104908d2b9`
- execution log artifact `9543166360` — SHA-256 `ad7f15c292b2d646763ad8e7b51460e93ac1d51e4aeec7dc79b7ef80ecb451dc`
- control log artifact `9543166725` — SHA-256 `356b40bb2464269ff1a93a14036ec3e8c96941d594b4a389f135809ff455c479`
- result artifact contains **1,959 files**, including 322 process records and each identity's stdout/stderr/raw/GTest JSON evidence
- package manifest preflight: **27 entries, 0 duplicates, 0 missing, 0 extra**, all hashes valid
- package, accepted-evidence ZIP, and source archive SHA-256 values are identical pre/post
- materialized source equals the independent fresh extraction pre/post
- `orchestration-errors.txt` is empty
- `post-cleanup.txt` records `post_cleanup_absent=true`

## 7. Accounting

- latest accepted runtime remains CP4ab **316/316**
- CP4c acceptance: **1/3 consumed**
- CP4c diagnostics: **1/2 consumed**
- stable regression accounting: **42 events / 14 categories / 28 recurrences**
- produced-witness debt: **5**
- M3 package count: **36**
- CP4c remains the only open M3 checkpoint

The six CP4c reds are first-acceptance candidates and therefore add no stable event or recurrence.

## 8. Control-plane process notes

Several earlier TB callers failed before Directional runtime because the temporary runner transport was not byte-preserving. Those runs are attempt-free orchestration evidence only. The final multipart text transport was schema-validated by run `32790852453`, reconstructed the exact locked runner SHA-256, and then produced the authoritative semantic run above.

The trigger text for `32791027809` was labeled as a hash preflight and said `acceptance_attempt=0/3`; once the exact locked runner reconstructed successfully, the workflow continued into the full gate. The runner itself emitted `boundary=immutable-artifact-only-acceptance-attempt-1-of-3`, executed all 322 processes, and produced a valid structured result with `acceptanceAttemptConsumed=1`. That semantic result is authoritative; the trigger label mismatch is a control-plane annotation defect only.

## 9. Exact successor

`M3-CP4c-TB-R1-INDEPENDENT-REVIEW` — independent review/planning only. No runtime, build/configure/relink/repair, semantic mutation, acceptance retry, or reserve diagnostic.

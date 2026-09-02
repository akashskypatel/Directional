# M3-CP4c-3-TB12 Artifact-Only Test + Benchmark Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB12`
Status: **COMPLETE / VALID SEMANTIC RED / NON-STABLE**

## 1. Immutable authority and execution boundary

TB12 consumed immutable package **82** only. Semantic/package source is
`71ece3ca184e90858d9222fb014b37c16d292294`; package artifact `9855841174` has Actions SHA-256
`4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`, inner `package82.tar.gz` SHA-256
`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`, and packaged source tar SHA-256
`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`.

Selector **378** remained byte-frozen at `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`;
selector 377 is its exact first-377 prefix at `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`,
and the first 365 identities reproduce accepted authority
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. The separate diagnostic
`GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` is not in selector 378 and received zero gate
credit.

Authoritative run/job: **`33657062615 / 100338185825`**, workflow conclusion success. Result artifact
**`9857275334`**, Actions SHA-256 `085b3de9ebf5a9a29cbcf883e4058c97855e11a1a7b2bc53f961c809dace9145`;
log artifact **`9857276091`**, Actions SHA-256
`89cac6cb1ea6444b8204d8b5ca9233daed7e0ff88986d8592af576e319cb4120`.

Boundary flags: `runtimeExecution=true`; `configureExecution=false`; `compileExecution=false`;
`relinkExecution=false`; `packageRepair=false`; `generatedDiscovery=false`; product/test/fixture/selector mutation
all false; `benchmarkExecution=false`.

Control-plane process note: the turn selected **`READ_MODE=snapshot`** and used source-snapshot run `33655963398` / artifact `9856727349` (event/source-control SHA `b43085c3869145e86ae14f310de09de02fb96c34`) for consolidated repository inspection. One handoff file was fetched before the read-mode declaration; this is recorded as a process-order deviation. The mandatory checklist was then completed from the exact snapshot before semantic adjudication, and the deviation changed no package, selector, runtime, or product evidence.

## 2. Gate result

All 378 selector identities ran in exactly one fresh process each: **370 PASS / 8 RED**. Ordinals **1-365 are
365/365 PASS**. First red remains ordinal **366**, so accepted authority does not advance. Report-only reds are
367, 368, 369, 370, 371, 372 and 374. Ordinals 373, 375, 376, 377 and the new diagnostic identity **378 PASS**.
The separate non-gating mechanical diagnostic ran once in its own fresh process and returned RED because that
identity deliberately emits its retained stage observation with a failing assertion; it carries zero gate credit.

## 3. BH9 runtime discrimination — the collision is between two distinct rays

Ordinal 366 remains at the frozen frontier:

`RotationRayOrderKeyCollision;sourceVertex=47;certificationAttempt=0;certificationCutEdges=0`

The now-retained operands are:

- previous: `primary=3`, `secondary=0`, arc **20**, trace **6**, `Forward`, face `(45,46,47)`, fan slot **1**,
  origin port ordinal **0**, origin port source vertex **47**;
- current: `primary=3`, `secondary=0`, arc **23**, trace **9**, `Reverse`, face `(45,46,47)`, fan slot **1**,
  origin port ordinal **0**, origin port source vertex **71**.

This runtime evidence falsifies the simplest **duplicate-incidence identity** explanation: the two rejected records
have different arc IDs, different trace IDs, opposite orientation, and different origin-port source vertices. It
also proves the review's locality concern in the failing production witness: at locus vertex 47, the second ray's
`secondary=0` comes from a port whose source vertex is **71**, not 47.

The evidence therefore discriminates the prior diagnostic ambiguity to a **distinct-ray same-sector collision**.
The collision guard treats the rays as equal because it compares only `primary`/`secondary`, even though the full
retained/sorted records distinguish them. That is direct evidence for an under-discriminating collision-equivalence
contract. It is **not yet a license to change the predicate**: both rays also occupy the same source face and fan
slot, so independent review must still decide whether they are valid coincident rays requiring explicit tie/
equivalence semantics, invalid/stale provenance, or a witness/precondition violation. No stale provenance or invalid
witness is proved by TB12 itself.

The complete bounded census contains **5** rays and is **not truncated**:

1. `(primary,secondary)=(3,0)`, arc 20 / trace 6 / Forward / face `(45,46,47)` / slot 1 / origin vertex 47;
2. `(3,0)`, arc 23 / trace 9 / Reverse / face `(45,46,47)` / slot 1 / origin vertex 71;
3. `(7,1)`, arc 21 / trace 7 / Forward / face `(46,47,72)` / slot 3 / origin vertex 47;
4. `(11,2)`, arc 16 / trace 2 / Reverse / face `(47,72,73)` / slot 5 / origin vertex 10;
5. `(15,2)`, arc 22 / trace 8 / Forward / face `(45,47,73)` / slot 7 / origin vertex 47.

`cutCandidateCount=450`, `certificationAttempt=0`, and `certificationCutEdges=0` remain measured. Crucially,
`nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are **absent** from this failure rather than rendering
unmeasured zero defaults. BH4 is therefore runtime-validated.

The selector-378 production-projection witness passes, proving the two-ray/key/fan-census diagnostics survive the
production failure projection. The separate mechanical diagnostic independently re-derives furthest stage
`field-aligned-network`, failed stage `surface-cut-graph`, originating error `RotationSystemInconsistent`, and
originating reason `RotationRayOrderKeyCollision`.

## 4. Red categorization

| Ordinal | Result | Disposition |
|---:|---|---|
| 366 | distinct-ray `RotationRayOrderKeyCollision`, vertex 47, attempt 0 / 0 cut edges | **GATING / RUNTIME-DISCRIMINATED / SEMANTIC POLICY UNADJUDICATED.** Existing `M3-CP4c3-TB11-CAND-01` remains active but is no longer underdetermined by missing operands; exact owner moves to `M3-CP4c-3-TB12-REV`. |
| 367 | same exact mechanical exception and ray census as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED by the same candidate.** No duplicate event. |
| 368 | `TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable` | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-CAND-04`, unchanged.** |
| 369 | `saturationUsed=true`, expected false | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-R10-CAND-01`, unchanged.** |
| 370 | actual typed code 4 vs expected `EmptyNetworkOnClosedSurface` code 6; source face absent | **REPORT-ONLY / EXISTING `M3-CP4c2-TB-X2-R8-CAND-02`, unchanged.** |
| 371 | same exact mechanical exception and ray census as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED.** Existing 371/372 coupling candidate remains deferred. |
| 372 | same exact mechanical exception and ray census as 366 | **REPORT-ONLY / UPSTREAM-BLOCKED.** Existing 371/372 coupling candidate remains deferred. |
| 374 | `atlasBuild=false` | **REPORT-ONLY / EXISTING `M3-CP4c3-TB7-CAND-02`, unchanged.** |

`M3-CP4c3-TB11-REV-CAND-01` is **CLOSED / RUNTIME DISCRIMINATED**: CB14 retained both operands and TB12 proved
that projection works and that unmeasured certification counters are absent. `M3-CP4c3-TB11-CAND-01` remains the
single gating semantic candidate, transitioned to **DISTINCT-RAY SAME-SECTOR COLLISION / SEMANTIC POLICY
UNADJUDICATED**. This is the same unaccepted first-red surface and adds **+0 stable events / +0 recurrences**.

## 5. Immutable postflight

The complete package-tree byte/mode census is identical before and after all 378 selector processes plus the one
non-gating diagnostic process. The internal `SHA256SUMS` manifest verifies identically before and after execution.
No package repair, rebuild, relink, configure, generated discovery, source/test/fixture/selector mutation, or
benchmark occurred.

## 6. Accounting and exact successor

Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable regression accounting remains
**44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3 package count
remains **79**.

Exact successor: **`M3-CP4c-3-TB12-REV` — independent REVIEW + PLAN only**, under
`Architecture_M3_CP4c3_TB12_Independent_Review_Plan.md`. Do not rerun TB12 or implement a collision fix before that
review adjudicates whether the two same-sector rays are valid, invalid/stale, or subject to a missing deterministic
equivalence rule.

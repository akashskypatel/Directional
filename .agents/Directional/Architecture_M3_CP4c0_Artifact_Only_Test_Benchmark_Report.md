# M3-CP4c-0 Artifact-Only Test + Benchmark Report

- Phase: `M3-CP4c-0`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular Test + Benchmark (`TB-EXEC` → `TB-REVIEW` → `TB-PLAN`)
- Validated source commit: `e784e44ce86e458b250b04689288f5f365ca507b`
- Immutable build artifact: `9577900736`
- Immutable package SHA-256: `b9c597584177f31fd2d923b622a4b20fbb243c7bd007b37cced8ff128e349f31`
- Environment: GitHub Actions `ubuntu-24.04`; artifact-only execution; no configure/build/relink/repair
- Status: **COMPLETE / VALID RED — required 328/328 gate GREEN, binding Q8 sphere reachability RED**

## Plan Execution

The frozen selector contained exactly **328 unique required identities**: accepted predecessor identities
1–316 followed by the 12 CP4c-0 falsifying/rejection identities. Selector SHA-256:
`cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`; first-316 prefix SHA-256:
`601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`.

Authoritative semantic execution is retry 1:

- workflow run: `32891161394`;
- schema-validation job: `97943166744` — PASS;
- Test + Benchmark job: `97943220460`;
- event/control SHA: `9779f2233eafc716ae4dd7e0dce0c484fe7b68a9`;
- result artifact: `9579600371`, SHA-256 `fe472587aba74c2face26a2f65c0706439232bec2e5cc594d81711a26773b399`;
- diagnostic-log artifact: `9579600958`, SHA-256 `7ddfe4c8e48b1b618c7a60ad6cf900a767ff954309a1c3cc52a8896306d98039`.

Retry 0, run `32890863928` at event SHA `2ceb90e4d09d935051c5d120a2c6b3894ce6784c`, is an
**infrastructure-only failed transfer**. It stopped before immutable-package verification and before any
semantic identity executed. The frozen plan permitted one diagnosed infrastructure retry with the same
package, selector, and commands; retry 1 is that retry. Retry 0 contributes zero semantic evidence.

No semantic retry is authorized after retry 1. The workload completed the frozen execution step and
uploaded result evidence successfully; the workflow failed only at the deliberate final fail-closed check
because Q8 was red.

## Integrity / Artifact-Only Boundary

Preflight passed against package SHA-256 `b9c597584177f31fd2d923b622a4b20fbb243c7bd007b37cced8ff128e349f31`,
source `e784e44ce86e458b250b04689288f5f365ca507b`, and the selector hash above. Pre/post package and
runtime-input inventories are identical, selector pre/post hashes are identical, and source status remained
clean. Every prohibited mutation/build flag is false: `packageMutation`, `sourceMutation`, `testMutation`,
`fixtureMutation`, `selectorMutation`, `configure`, `compile`, `relink`, `repair`, `generatedDiscovery`,
and `performanceBenchmark`.

## Tests Executed / Results

The required semantic gate ran in declared order, one identity per fresh process.

- Required / executed / passed: **328 / 328 / 328**
- Failed: **0**
- Accepted predecessor prefix: **316/316 PASS**
- CP4c-0 additions: **12/12 PASS**
- First semantic gate failure: none

D3's accepted-prefix non-regression obligation is therefore re-proved by runtime: no previously accepted
identity regressed under the exact-position/exact-continuation implementation.

## Binding Q8 Observation — VALID RED

The frozen plan required the prescribed sphere, after a green 328 gate, to publish exactly **24 traces**,
at least one terminal `TraceIntersection`, and resolve face `1-2-5` / incoming `1-2` to one of
`{1-5, 2-5}` with the frozen crossover flip.

That observation is **RED** before those values exist. The prescribed sphere reaches source topology and
A1, but A2a rejects:

- `failedStage=field-aligned-network`;
- `networkError=BranchContinuationDegenerateEntry`;
- `sourceVertex=0`; `sourceEdge=6-8`; `singularity=0`;
- `fieldAlignedCurveNetwork=false`; `globalTopologyPlanSnapshot=no`.

Preceding topology diagnostics remain coherent: `sourceEuler=2`, `sourceBoundaryLoopCount=0`,
`sourceGenus=0`, `interiorLocalVertices=98`, `sourceTopologyRegions=true`,
`sourceTopologyRegionCount=1`, and `fieldTransportAtlas=true`.

Because no network is published, Q8 records `trace_count=none`, `terminal_trace_intersections=none`, and
`face_1_2_5_incoming_1_2_crossover=NOT_OBSERVED`. This is a binding stop condition, not a skipped test and
not permission to weaken the Q8 oracle.

## Benchmarks Executed

None. CP4c-0 has no performance benchmark criterion and `performanceBenchmark=false` remained frozen.

## TB-REVIEW Findings

### Finding 1 — the frozen 328 semantic gate is trustworthy and green

- Acceptance criterion: accepted 316 unchanged and all 12 CP4c-0 identities green.
- Actual result: **328/328 PASS**.
- Classification: valid tests; no accepted regression.
- Confidence: high.
- Consequence: the previous Cartesian `connections` gap is no longer the current first sphere failure;
  CP4c-0's dedicated exact-continuation falsifiers are green.

### Finding 2 — binding prescribed-sphere Q8 is valid red

- Acceptance criterion: A2a publishes the prescribed sphere network with 24 traces, terminal
  `TraceIntersection` reachability, and the frozen crossover observation.
- Actual result: A2a rejects `BranchContinuationDegenerateEntry` at singularity 0 / source vertex 0 /
  edge 6-8 before publishing a network.
- Classification: **unresolved production-integration versus frozen-contract conflict**; not infrastructure
  and not presently justified as an invalid fixture or incorrect expectation.
- Contract tension: frozen T6 requires exact `t*=0` to fail closed as `BranchContinuationDegenerateEntry`,
  while frozen Q8 requires the prescribed sphere to traverse A2a.
- Plausible static seam requiring independent adjudication: A1's established regular-vertex sector
  membership uses its existing half-open tolerance-based sector rule, while A2a's new exit/minimizer
  decisions are exact. A2a re-enters exact continuation after start, edge transport, and T2 regular-vertex
  transit. This is **not a proven root cause**.
- Evidence gap: runtime does not publish the failing source face, branch, exact entry parameter, exact
  minimizer set, or predecessor transition that produced the zero-time continuation.
- Confidence: high that Q8 is genuinely red; insufficient for a final root-cause class.

## Regression / Candidate Accounting

- `M3-CP4c0-TB-CAND-01` — **ACTIVE / NON-STABLE / PENDING INDEPENDENT REVIEW**: sphere blocked by
  `BranchContinuationDegenerateEntry` after the 328 gate is green.
- `M3-CP4c0-TB-CAND-02` — **RESOLVED INFRASTRUCTURE / NON-STABLE**: retry-0 artifact transfer failed
  before package verification and before any semantic identity.
- Prior `M3-CP4c-TB-R1-CAND-02` is superseded as the active failure site: CP4c-0 removed Cartesian
  continuation authority and all 12 new identities pass, while the sphere now reaches the typed zero-time
  rejection above.

Stable accounting remains **42 events / 14 categories / 28 recurrences** because CP4c-0 has never been
accepted and all accepted 316 identities remain green. Produced-witness debt remains **5**. M3 package
count remains **40**; TB consumed the existing immutable CB package and created no build package.

## Phase Status / TB-PLAN

**Complete / valid red.** The required gate is green, but binding Q8 is red, so `M3-CP4c-0` does not
close and does not become accepted runtime authority. Latest accepted runtime remains CP4ab **316/316**.

Status: **`proposed_pending_review`**. Exact next is independent
**`M3-CP4c-0-TB-REVIEW-PLAN`**, review/planning only, using
`Architecture_M3_CP4c0_TB_Review_Plan.md`. No semantic rerun, Code + Build, fixture edit, expectation
edit, or implementation change is authorized before review adjudicates the T6/Q8 conflict.

## Live Handoff

- Evidence commit: `e784e44ce86e458b250b04689288f5f365ca507b`
- Runtime control SHA: `9779f2233eafc716ae4dd7e0dce0c484fe7b68a9`
- Runtime result artifact: `9579600371`
- Next canonical turn: independent Review
- Exact next state: `M3-CP4c-0-TB-REVIEW-PLAN`

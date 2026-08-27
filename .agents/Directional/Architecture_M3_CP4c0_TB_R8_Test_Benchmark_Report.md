# M3-CP4c-0-TB-R8 Test + Benchmark Report

- Phase: `M3-CP4c-0`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular `TB-EXEC -> TB-REVIEW -> TB-PLAN`
- Validated semantic source: `19ba8e9c5e58f9c33c14b309841165d3f0401db5`
- Workflow control / trigger: `078aac03923c0badc42d150397065fe5b33212c6`
- Immutable CB8 package: artifact `9628445643`, ZIP SHA-256 `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`
- TB-R8 run / workload job: `33028238313 / 98374531360`
- Test + Benchmark plan: `Architecture_M3_CP4c0_TB_R8_Artifact_Only_Test_Benchmark_Plan.md`
- Environment: GitHub Actions `ubuntu-24.04`; ordinary `unzip` + `tar`; no package repair

## Plan Execution

- P0 immutable-package preflight completed before any test process and the ordered gate began.
- P1 completed **342/343** fresh selector processes before the user cancelled the workflow because the last process had stalled for an unreasonably long time.
- P2-P8 were **not reached** because P1 never completed.
- No configure, compile, relink, regeneration, fixture mutation, selector mutation, source mutation, or permission repair was authorized or performed by the TB payload.
- The workflow cancellation is not acceptance evidence. The completed failure at ordinal 338 is independently preserved runtime evidence.

## Tests Executed

- Selector ordinals `1..342` executed as fresh GoogleTest processes.
- Ordinal `343`, `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport`, was the only missing selector result when cancellation occurred; because the payload runs selector order synchronously, the workflow was inside that process at cancellation.
- Supplemental F3 and P3-P7 diagnostics did not execute.

## Test Results

- Completed selector processes: **342/343**.
- Passed: **341**.
- Failed: **1**.
- Missing/incomplete: **1** (ordinal 343).
- Accepted prefix: **316/316 PASS**.
- Prior first-328 prefix: **328/328 PASS**.
- First red: ordinal **338**, `ResolvedBranchCorrection.AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections`.
- Ordinal 338 runtime: **853.437 s** before failing with `C++ exception with description "gcd(): while running too long!"`.
- Last deterministic atlas locus before that exception:
  `FieldTransportAtlas.partition adjacency singularity=7 fanIndex=3 nextFanIndex=0 sourceEdge=(43,49) signedLift=-1`.
- Ordinals 339-342 subsequently passed in fresh processes.
- Ordinal 343 then failed to return a result before user cancellation roughly one additional long-running interval later.

Raw evidence:

- partial result artifact `9629797616`, ZIP SHA-256 `50462c5023a5cab817859eefb00b3f523e6cfe1e6d601188cd7c1e14a149c287`;
- diagnostic log artifact `9629798008`, ZIP SHA-256 `217523d273a844c6f3c8f8a3e4c6d0314352d7620c8af24760b239a4d989977a`;
- workflow conclusion: `cancelled` by explicit user intervention after observed stall.

## Benchmarks Executed

None. The semantic gate did not complete and the plan never reached any later diagnostic/benchmark section.

## TB-REVIEW Findings

### Finding 1 — deterministic production termination/performance defect

- Acceptance criterion: P1 requires every selected identity to complete organically and the complete gate to be 343/343 green.
- Actual result: ordinal 338 completed only after 853.437 s and failed inside production exact arithmetic; ordinal 343 did not complete before cancellation.
- Classification: **production implementation / performance-termination defect**, not a fixture defect and not a test-expectation defect.
- Evidence: prior TB-R7 had the old 338 gate green; CB8 changed the grazing transit semantics. The same prescribed-sphere production path now enters a pathological exact-arithmetic/traversal regime.
- Proximal source localization: `src/numerics/BigInteger.cpp::gcd` has a 10,000-iteration emergency guard and threw it. `ENumber::simplify()` invokes this GCD during exact-rational normalization.
- Existing traversal protection is insufficient as an operational guard. `FieldAlignedTraceTraversalGuard` detects exact repeated states and has a step budget, but the sphere's current budget computes to **1,775,616** steps (`192 faces * 4 branches * (288 transports + 1) * 8`). A budget that large does not prevent unreasonable wall-clock work when exact-rational operands grow.
- The traversal state's equality includes the exact boundary point. A topologically cycling path whose exact parameter changes can therefore evade exact-state recurrence until much later.
- Confidence: **high** that the current product has an inadequate practical termination bound; **medium** on the exact first algorithmic step that causes operand growth because cancellation evidence contains no stack trace or operand census.
- Evidence gap: determine whether the dominant root is repeated grazing/vertex transit, non-progressing rational parameter evolution, or another exact-arithmetic growth path before choosing a correction.

### Finding 2 — TB-R8 is incomplete and receives no acceptance credit

- The full 343 gate did not complete, P2-P8 did not run, and the payload never generated its final `result.json` or immutable postflight comparison.
- Therefore CB8 runtime semantics remain **unaccepted** and latest accepted runtime remains CP4ab 316/316.
- The ordinal-338 failure remains valid raw evidence even though the overall run was cancelled later.

## Phase Status

**INCOMPLETE / BLOCKED BY VALID PRODUCTION TERMINATION FAILURE.**

Stable regression accounting remains **42 events / 14 categories / 28 recurrences** and produced-witness debt remains **5** because CP4c-0 has never been accepted. M3 package count remains **47**.

## TB-PLAN / Proposed Next Code + Build Plan

Status: **proposed_pending_review**.

The user has frozen an explicit stop rule: **do not re-run TB-R8 until a deterministic product-level guard exists for infinite or unreasonably long-running loops.** A workflow timeout, per-test timeout, or CI watchdog is not a substitute.

Proposed bounded successor after independent review:

1. Establish the smallest generalized termination contract for field-aligned candidate tracing.
   - Reconstruct the ordinal-338/343 sphere path statically from CB8 source and preserved loci.
   - Determine which state/progress invariant can prove forward progress without depending on an ever-changing exact parameter.
   - Choose a deterministic finite-work bound that is practical on the prescribed sphere and scales from reachable topology, not a million-step permissive ceiling.
2. Make exhaustion/cycle failure typed and diagnostic.
   - Preserve seed, face, branch, carrier, exact entry point, steps, budget, and the last bounded history.
   - Do not convert the failure into success and do not hide it behind test/workflow timeout handling.
3. Add/retain compile-time regression coverage in the next Code + Build turn.
   - The existing ordinal-338 and ordinal-343 witnesses remain required.
   - Add only the minimum direct guard falsifier required by the reviewed invariant.
4. Compile all affected targets only; do not execute runtime in Code + Build.
5. Future TB validation may re-run TB-R8 only after the guard implementation is compile-green and immutable-package evidence exists.

## Optional Review Decision

- Review: **request**.
- Reason: the evidence proves an inadequate termination bound but does not yet prove which progress invariant is semantically correct. A guard that merely lowers an iteration count could mask a real tracing cycle or reject valid traces.
- Exact next: `M3-CP4c-0-TB-R8-REVIEW-PLAN`, independent review/planning only.

## Live Handoff

- Evidence source: semantic commit `19ba8e9c5e58f9c33c14b309841165d3f0401db5`, package `9628445643`.
- TB evidence control: `078aac03923c0badc42d150397065fe5b33212c6`, run/job `33028238313 / 98374531360`.
- Handoff/planning commit: filled by the documentation closeout commit.
- Next canonical boundary: independent Review + Plan, then a bounded Code + Build guard correction if approved.
- **No TB-R8 retry is authorized before the guard lands.**

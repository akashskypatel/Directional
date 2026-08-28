# M3-CP4c-0b TB-T5 Preflight Blocker Report

## Verdict

`M3-CP4c-0b-TB-T5` is **BLOCKED / PRE-GATE OBSERVABILITY GAP / 353 NOT RUN**.

The independent T4 review correctly authorized T5 under measures U0-U7, but U3 is itself a binding **before-gate** measurement. The immutable CB2 package `9668492827` does not contain compiled telemetry capable of publishing all fields U3 requires for the four-triangle fan and two-ring witnesses. U7 simultaneously forbids changing test instrumentation, compiling, relinking, repairing, replacing the package, or executing generated discovery during T5. Therefore no lawful T5 execution can both preserve immutable authority and satisfy U3. The turn fails closed before the first gate identity.

No Directional binary, benchmark, gate identity, or acceptance process was executed. No source, test, fixture, selector, package, production code, or build configuration was changed.

## U0 static preflight

The immutable authority itself is valid:

- semantic source: `b2629040450c12507367c232f68a4d972b46450f`
- immutable GMP package artifact: `9668492827`
- package ZIP SHA-256: `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`
- package internal `SHA256SUMS`: **28/28 PASS**
- package command boundary: `runtimeExecution=false`, `exactArithmeticBackend=GMP`
- full required selector: **353 identities**, SHA-256 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`
- first 346 selector lines: SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`
- T4 diagnostic selector remains `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`

The local package copy was independently hashed to the recorded ZIP digest and its internal manifest verified before the pre-gate decision. No package binary was run.

## Exact source-snapshot authority

The turn selected `READ_MODE=snapshot` and materialized a single exact repository authority before the T5 pre-gate audit:

- source-snapshot run/job: `33130565916 / 98718854457`
- snapshot event/source control SHA: `640a35ae08a3a624ac3799b42c9ddf6c31300be0`
- snapshot artifact: `9670081197`
- artifact ZIP SHA-256: `58403bc8052a87f6359d809872a6e7ea7e61e3807b6dca104f38983e3023a284`
- contained `source.tar.gz` SHA-256: `a82a2882a5dda7440949a29933b566f808c6ae334036dcb790622dab4852f849`
- snapshot inventory: **5,181 files / 90,231,986 bytes**
- recursive submodules: **yes**
- snapshot `SHA256SUMS`: independently verified locally
- snapshot workflow boundary: `runtimeExecution=false`

The snapshot SHA is a control-plane continuation of independent-review head `63533f8bc0f2c33affba630248ae73b4e449128c`; it does not replace semantic package source `b2629040...`.

## U3 observability audit — blocking

U3 requires, **before the 353 gate and even if the eventual gate would be green**, a non-gating fan/two-ring census publishing:

1. every trace's terminal kind (`terminalSingularity`, `terminalBarrier`, `terminalContact`) plus an exactly-one assertion;
2. barrier-terminating trace count;
3. total node count plus **per-node provenance in T3 format including `railAuthority`**;
4. event-kind histogram;
5. whether any arrival comparison was inconclusive;
6. whether the mutual-termination tie policy fired.

The immutable package cannot publish that complete observation surface:

- `FieldAlignedContactCensus` in `include/directional/geometry/SurfaceCellTracing.h:659` stores shared-face contacts, contact-provenance nodes, event histogram, node count, and site A/B/C counts. It has no per-trace terminal ledger, barrier-termination count, arrival-comparison result, or mutual-tie counter.
- compiled non-gating identity `ResolvedBranchCorrection.ContactPredicateCensusIsPublishedNonGating` uses `cp4c0b_contact_census_report` (`tests/FieldAlignedCurveNetworkTests.cpp:5521`). It publishes rail authority, mandatory-edge/singularity counts, contact census, total node count, contact-node provenance, and event histogram, but **not** the missing U3 fields above and not provenance for every node.
- `cp4c_node_provenance` exists at `tests/FieldAlignedCurveNetworkTests.cpp:6973`, but the CB2 tests use it for assertions; it is not a fan/two-ring U3 publisher.
- `append_cp4c_terminal_event_report` at `tests/FieldAlignedCurveNetworkTests.cpp:2609` publishes terminal event information, not the required per-trace terminus ledger or arrival-comparator/tie-policy outcome.
- accepted fan identity `FieldAlignedCurveNetwork.PublishesTypedSingularityPortsAndMandatoryGraph` (`:510`) does assert the absolute eight-node contract whose comment decomposes into structural nodes plus three barrier-terminating traces, but it does not publish U3's required census.
- the two-ring termination identity asserts absence of contact termini and the expected node count, but likewise does not expose the complete U3 observation surface.

String inspection of the immutable producer-test executable was used only to confirm which diagnostic labels/error strings are compiled in; the binary was not executed. No compiled U3-specific publisher exists because U3 was introduced by the independent review after package `9668492827` had already been built.

**Binding consequence:** running the 353 identities first and trying to infer U3 afterward would violate the review's ordering and measurement contract. Adding the missing publisher would violate U7 and destroy the immutable-package premise of this T5 turn. Therefore **gate processes executed = 0/353**.

## U4 observability note

The package contains accepted guard and closed-producer assertions and the guard failure vocabulary, but there is no dedicated compiled per-witness U4 publisher that reports N1 (`TraceCombinatorialRecurrenceExceeded`), N2 (`BranchContinuationExactMagnitudeExceeded`), and N4 step-budget silence in the exact census shape the review requests. This is a secondary evidence-capability gap. U3 alone is sufficient to block T5 before runtime, so no attempt was made to weaken U4 into an inference.

## U5 / integrity boundary

- Directional runtime executions: **0**
- 353 gate identities executed: **0/353**
- configure / compile / relink / repair / generated discovery: **none**
- source/test/fixture/selector/package mutation: **none**
- timeout added: **no**
- guard/error-bound widening: **no**
- package replacement: **no**
- CP4c-1/2/3 entered: **no**

A process-control miss did occur at turn start: initial repository inspection preceded the mandatory current-turn policy-read and explicit `READ_MODE` selection. The conservation policy's fail-safe was then applied: piecemeal source/document reading stopped, the miss was recorded, `READ_MODE=snapshot` was selected, and the exact snapshot above became the sole repository-read authority before this semantic/pre-gate decision. No Directional runtime or semantic repository mutation occurred before that correction.

The first cleanup-manifest write also triggered the durable cleanup workflow before the snapshot marker commit. Cleanup run `33130560363` failed safely: its event SHA was `28f02117f2162418a90a843a83edcd7f4b5c268d`, while the branch had advanced to `640a35ae08a3a624ac3799b42c9ddf6c31300be0`; the workflow's remote-head equality guard stopped before commit/push. No cleanup mutation, PR-comment deletion, or runtime execution occurred in that failed run.

## Regression and candidate accounting

No product regression was executed or observed in this turn. Stable historical accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**, M3 package count **54**.

Two non-stable process/evidence candidates are recorded:

- `M3-CP4c0b-T5-CAND-01` — **ACTIVE / EVIDENCE-CAPABILITY / NON-STABLE**: immutable package `9668492827` cannot publish the complete U3/U4 pre-gate census newly required by T4 independent review. This is not evidence that product semantics are wrong; it is a blocker to measuring them under the prescribed acceptance contract.
- `M3-CP4c0b-T5-CAND-02` — **RESOLVED / ORCHESTRATION / NON-STABLE**: the cleanup manifest's path trigger raced the subsequently-created snapshot marker. The cleanup workflow's branch-head guard prevented any stale cleanup commit. The final cleanup must update the complete manifest only after all temporary paths are known and all other branch writes are complete.

`M3-CP4c0b-P03-CAND-01` remains **ACTIVE / unmeasured against accepted authority** because the 353 gate did not run.

## Stale-evidence audit

Nothing is eligible for retirement in this pre-gate blocker turn. The T4 execution report, T4 independent review, CB2 package provenance, and selectors remain live inputs to the next adjudication and must be retained.

## Stop / successor

Exact next turn is **`M3-CP4c-0b-TB-T5-PREFLIGHT-REV`**, independent review only. It must adjudicate the U3/U4 evidence-capability conflict and decide whether to authorize a narrowly bounded instrumentation-only Code+Build package before any T5 retry. It must not reinterpret the absent telemetry as a pass, execute the 353 gate, widen a guard, or silently weaken U3/U4.

The full **353-identity T5 acceptance remains BLOCKED / NOT RUN**.

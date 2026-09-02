# M3-CP4c-3-TB12 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN successor plan from `M3-CP4c-3-CB14`.
**Turn boundary:** Test + Benchmark only; package 82 is immutable. No product/test/fixture/selector/build-logic edit or replacement compile is permitted.

## Validation identity

- phase: `M3-CP4c-3-TB12`;
- working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`;
- evidence source: **`71ece3ca184e90858d9222fb014b37c16d292294`**;
- compile run/job: `33653092570 / 100324843819`;
- compile result artifact `9855741844`, Actions SHA-256 `b4b98c3f8ee0ad0a777f69f591591303e37c99d136dc028d511967b746e7fb16`;
- immutable package artifact **`9855841174`**, Actions SHA-256 `4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`;
- inner `package82.tar.gz` SHA-256 **`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`**;
- packaged source archive SHA-256 **`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`**;
- package log artifact `9855841773`, Actions SHA-256 `434e5c4457281ff75dc4e9855aa86f609d28a2751c783d9191b88fecdd186e59`;
- selector **378** SHA-256 **`86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`**;
- frozen selector 377 SHA-256 `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`;
- inherited accepted authority: **365/365**.

## Validation objective

TB12 does **not** test a semantic correction. It tests whether CB14's diagnostic-only instrumentation makes the ordinal-366 `RotationRayOrderKeyCollision` decidable without moving any accepted or gating behavior. The evidence must discriminate duplicate/stale incidence, insufficient order key, valid coincident rays requiring defined tie semantics, or a witness/precondition alternative before any semantic fix is planned.

## Immutable preflight — before any Directional runtime

1. Download package artifact `9855841174` directly and verify the Actions digest and inner tar digest above.
2. Extract with ordinary `unzip`/`tar` semantics that preserve archived executable modes. Do not `chmod`, repair, rebuild, regenerate, relink, or repack the package.
3. Verify every internal `SHA256SUMS` entry; exact source commit/archive digest; clean source-status records; preflight/build exit codes `0`; `runtimeExecution=false`; `packageRepair=false`; `exactArithmeticBackend=GMP`; and link evidence containing both GMPXX and GMP.
4. Require exactly 27 package-relative fixture files and exactly six packaged `directional_*` executables with executable mode intact.
5. Recompute selectors 373-378 from packaged source and require their exact hashes, cardinalities, uniqueness, and every prefix relation. In particular selector 377 must remain `7255ac86...26cbec1`, selector 378 must be `86259d91...6440b8`, and selector 377 must be the exact first 377 lines of 378.
6. Map every selector-378 identity to exactly one packaged executable before runtime. A zero-selected or duplicate-selected identity is orchestration failure, never semantic evidence.
7. Record a package-tree byte/mode census for postflight comparison.
8. No configure, compile, relink, generated discovery, source/test/fixture/selector mutation, package repair, or benchmark execution is permitted.

Any mismatch stops before runtime and is orchestration failure.

## Ordered execution — selector 378 from ordinal 1

Execute selector **378 from ordinal 1**, **one exact identity per fresh process**. Gate credit stops at the first semantic red. After the first red, execute every remaining identity through 378 exactly once as report-only evidence with zero gate credit. Do not impose a repository elapsed-time watchdog on the complete selector execution and do not partition/retry/stitch continuations to manufacture completion.

Then execute **exactly once**, separately and with **zero gate credit**, the existing diagnostic identity:
`GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`.
It re-derives the mechanical cut-graph failure from production inputs. It is diagnostic-only and must never alter accepted count, first-red ordinal, or selector membership.

## Mandatory CB14 / BH9 discriminators

1. **Accepted prefix remains fixed.** Ordinals **1-365 must remain 365/365**. Any red in the accepted prefix is a new gating regression and falsifies the diagnostic-only assumption.
2. **The gating frontier remains fixed.** Ordinal **366** must remain red at `RotationRayOrderKeyCollision`, `sourceVertex=47`, `certificationAttempt=0`, `certificationCutEdges=0`. Any movement of the first red, reason, source vertex, attempt, or cut-edge count is evidence that CB14 changed semantics and must route to review without a TB-side patch.
3. **Both rays become identifiable.** Preserve the exact ordinal-366 line and require both arcs, both traces, both source faces when available, both orientations, both origin-port ordinals and their source vertices, plus previous/current typed ray payloads containing `primary`, `secondary`, and fan slots. Missing data is a diagnostic result; do not infer or synthesize it.
4. **The keyed fan becomes inspectable.** Preserve the bounded fan census at source vertex 47, including total count and truncation state. Use the actual census to determine whether the colliding pair is duplicate/stale incidence, a valid coincident pair, or distinct rays collapsed by the current key. Do not alter ordering semantics in TB12.
5. **Certification counters are honest.** `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` must either carry measurements made on this failure path or be absent. A fabricated default `0` is a CB14 diagnostic failure.

## Diagnostic interpretation table

Classify the retained evidence without prescribing a fix:

- same arc/trace/orientation/fan-slot identity duplicated in the census -> duplicate/stale incidence is supported;
- distinct ray identities with the same `primary`/`secondary` but different retained order-relevant data -> insufficient order-key hypothesis is supported;
- distinct valid rays that are geometrically/order-equivalent under the currently defined key and incidence is not duplicated -> valid coincident rays / undefined tie semantics remains supported;
- the synthetic diagnostic identity passes but ordinal 366 cannot supply equivalent data because the mechanical witness fails before the expected producer or violates its precondition -> witness/precondition alternative is supported.

If evidence does not uniquely select one row, record the ambiguity. TB12 must not choose a semantic fix by preference.

## Related/report-only validation

After first-red classification, execute ordinals 367-378 under the same report-only rule. Preserve prior dispositions unless exact new evidence demonstrates movement. In particular 371/372 fixture coupling, prescribed sphere 368, saturation 369, ordinal 370, and folded-cone 374 remain separately owned/deferred. The new ordinal 378 is diagnostic only and earns zero accepted-prefix credit.

## Regression/accounting review

Before TB12 closes, update `Regression_Root_Cause_Tracker.md` for every observed regression/candidate. Keep `M3-CP4c3-TB11-REV-CAND-01` non-stable unless TB12 evidence justifies a stable identity/count change. Preserve stable totals **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, and accepted authority **365/365** unless tracker criteria are actually met. Package count is **79** and does not change during TB12.

## Immutable postflight

After all authorized runtime, rerun the internal manifest; recheck source archive, selector hashes, binary hashes and executable modes; compare the package byte/mode census; and prove configure/compile/relink/repair/generated-discovery/product/test/fixture/selector mutation and benchmark flags remain false. Any mismatch invalidates semantic authority.

## Stop and blocker conditions

- Any package/source/hash/mode/precondition mismatch stops before runtime as orchestration failure.
- Any red in ordinals 1-365 is a new gating regression: preserve it, stop gate credit, continue only report-only work already authorized, and route to review.
- Any movement of ordinal 366's frontier/reason/sourceVertex/certification-attempt identity is semantic movement from CB14; preserve it and route to review without rebuilding or patching in TB12.
- Missing CB14 diagnostic fields are a diagnostic failure/result; do not fill them from source inspection as substitute runtime evidence.
- A typed fan census that falsifies the favored hypothesis is valid evidence. Do not reinterpret it to preserve the hypothesis.
- Continuing is forbidden if it would require configure, compile, relink, package repair, selector/test/fixture/source mutation, or generated discovery.

## Plan-defined reruns

No deterministic semantic identity is rerun merely to see whether it passes. An orchestration-only failure may be retried only after its exact control defect is diagnosed, using **unchanged package 82**. Fresh-process execution is required for each selector identity; it is not a retry.

## Benchmark plan

**Not applicable.** `directional_benchmarks` is packaged only because it belongs to the standard compile/package authority. TB12 executes no benchmark; `benchmarkExecution=false` remains required.

## Completion criteria

TB12 is complete only after immutable pre/postflight PASS, all 378 selector identities run under the gate/report-only rules, the non-gating diagnostic identity runs once, all five BH9 discriminators are recorded, the fan evidence is classified against the diagnostic interpretation table without prescribing an unsupported semantic fix, and the regression tracker is updated. TB12 itself does not mutate source or build a replacement artifact.

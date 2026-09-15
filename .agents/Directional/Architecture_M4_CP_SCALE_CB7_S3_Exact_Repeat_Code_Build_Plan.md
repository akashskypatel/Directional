# M4-CP-SCALE-CB7 — S3 Exact Full-State Repeat / Typed Limit-Cycle Code + Build Plan

**Frozen by:** `M4-CP-SCALE-TB5-REV`
**Turn:** `M4-CP-SCALE-CB7`
**Boundary:** Code + Build only; **no Directional runtime**.
**Entering accepted runtime authority:** package `10407605295`, source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`, selector424 **424/424**, SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.
**Single variable:** S3 exact traversal-state repetition becomes a typed semantic `LimitCycleTermination` outcome and receives one dedicated focused gate identity.
**Required successor after GREEN compile/package:** `M4-CP-SCALE-TB6-EXEC`, then mandatory `M4-CP-SCALE-TB6-REV`.

## 1. Frozen semantic authority

`Architecture_M4_CP_SCALE_Frozen_Definitions.md` §4 is unchanged and binding. The semantic repeat key is exactly:

`FieldAlignedTraceTraversalState = (sourceFace, branch, incomingCarrier, exact FieldBoundaryPoint entryPoint)`.

Only equality of that complete exact state may authorize S3 limit-cycle credit. The current guard already distinguishes:

- exact full-state repeat -> `FieldAlignedTraceTraversalStatus::CycleDetected`;
- position-free/combinatorial recurrence -> `CombinatorialRecurrenceExceeded`;
- step bound -> `StepBudgetExhausted`.

CB7 must preserve those distinctions. It is not authorized to reinterpret a budget, elapsed time, geometric proximity, face/branch/carrier-only recurrence, or floating-point near-equality as a cycle.

## 2. Current source seam and defect

The exact traversal guard already detects a repeated full state, and existing unit coverage constructs `entryPoint=1/3`, then `2/3`, then exact `1/3` again and observes `CycleDetected`. Production tracing currently projects every non-`Advanced` traversal status to `FieldAlignedCurveNetworkError`; helper `field_aligned_trace_traversal_error` maps exact-repeat `CycleDetected` to `TraceStateCycleDetected`. Therefore the semantic full-state repeat is recognized but still published as failure rather than the frozen typed S3 terminal outcome.

CB7 owns only this projection/publication seam. It may not redesign traversal topology, alter entry-point equality, or add a repair path.

## 3. Required implementation

Implement the smallest typed product surface that makes exact repeat a semantic trace terminal while keeping the other two guards fail-closed.

Required properties:

1. A candidate trace can publish a typed **`LimitCycleTermination`** terminal outcome (or an equivalently explicit enum/field whose public meaning is exactly that name/contract).
2. Only `FieldAlignedTraceTraversalStatus::CycleDetected` may produce it.
3. The published terminal must retain enough exact locus/state authority to prove which complete traversal state repeated; do not reduce it to a boolean with no auditable state/locus.
4. `CombinatorialRecurrenceExceeded` remains a typed error/backstop and cannot be projected to `LimitCycleTermination`.
5. `StepBudgetExhausted` remains a typed error/backstop and cannot be projected to `LimitCycleTermination`.
6. Existing barrier/contact/singularity/ordinary trace terminals retain their semantics.
7. No length threshold, wall-clock threshold, epsilon, floating-point proximity, or unordered/position-free key may enter the S3 semantic decision.
8. Do not add A2a/A2a′ repair, change cut selection, change A3/A4 semantics, or weaken accepted failure projection.

If the existing `FieldAlignedCandidateTrace` terminal representation cannot encode this without ambiguity, a narrowly scoped typed terminal enum/variant is authorized. A generic success boolean is not.

## 4. Required focused gate

Author exactly the frozen identity:

`M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`

Owner: **producer** (`directional_surface_cell_producer_tests`). The gate must traverse the production/named-stage seam that publishes the trace terminal; a guard-only unit test is insufficient.

The test must independently construct and prove all of:

- one exact state `(face, branch, carrier, entryPoint)` occurs, a distinct exact entry state intervenes, and the first full state occurs again;
- the repeat is exact in all four key fields, including exact `FieldBoundaryPoint` data;
- production publishes typed `LimitCycleTermination` on that repeat;
- the same face/branch/carrier with a **different exact entry point** does **not** publish `LimitCycleTermination`;
- a forced position-free/combinatorial recurrence reaches `CombinatorialRecurrenceExceeded`, not the S3 terminal;
- a forced step-bound case reaches `StepBudgetExhausted`, not the S3 terminal;
- one tamper to any load-bearing key field prevents exact-repeat credit until the complete state actually repeats;
- the gate fails if the typed terminal is removed or if either backstop is incorrectly reclassified as the terminal.

The existing `ResolvedBranchCorrection.TraceTraversalDistinguishesExactEntryPositionsAndFailsClosedOnBounds` is supporting guard-level evidence only. It may be reused as a control but cannot replace the new production-seam gate.

## 5. Selector and control rules

- **Do not modify selector424.** It remains byte-frozen at `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.
- **Do not publish selector425 in CB7.** The new S3 identity remains focused/outside the accepted selector until a fresh runtime TB proves it and Review authorizes publication, mirroring the successful S2 control sequence.
- Preserve all 424 accepted test identities byte-for-byte unless a compile break requires a mechanically necessary signature adaptation; any accepted semantic assertion change is a STOP back to Review.
- S1, S2 vertex-star, S2 arrival, S4, S5 and CP4 debt semantics are out of scope.

## 6. Compile/package requirements

Use only `.github/workflows/agent-compile-reusable.yml` with the durable cache namespace and mandatory GMP/GMPXX backend. Compile the default eight approved targets unless changed-owner preflight proves a smaller required set and policy still requires the full package target set.

Required compile evidence:

- exact source SHA/archive and clean source status;
- GMP/GMPXX linked and `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`;
- changed-owner/source inventory proving changes are confined to the S3 product/test surface plus durable docs;
- all approved package binaries required by the successor TB;
- recursive self-excluding package manifest and normal compile receipts.

**Forbidden in CB7:** every Directional test, benchmark, discovery/list/help/version command, produced executable invocation, `ctest`, custom runtime input, or semantic acceptance attempt.

## 7. Static falsifiers before compile

CB7 is invalid and must STOP rather than compile/package if any of the following is true:

1. the implementation recognizes a cycle without exact equality of all four frozen traversal-state fields;
2. `CombinatorialRecurrenceExceeded` or `StepBudgetExhausted` can produce `LimitCycleTermination`;
3. the typed terminal has no retained exact repeated-state/locus authority and is therefore not auditable;
4. the focused test reaches only the guard helper and never the production/named-stage publication seam;
5. the different-entry-point negative does not discriminate the terminal;
6. a timeout, length threshold, epsilon/proximity, hash collision assumption, container iteration order, or step count becomes semantic cycle authority;
7. selector424 changes by one byte or selector425 is authored/published;
8. S1/S2/S4/S5, cut selection, A3/A4, fixtures unrelated to the dedicated S3 witness, or reusable-workflow permissions change;
9. compile/package is not authoritative GMP/GMPXX or any Directional runtime is executed.

## 8. Successor TB6 contract frozen now

On static + compile GREEN, exact next is **`M4-CP-SCALE-TB6-EXEC`** against the immutable CB7 package. TB6 must begin from process zero and execute:

1. focused `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination` in a fresh exact-filter process;
2. accepted selector424 **424/424** in exact file order, one fresh process per row;
3. exact immutable package/source/execution-view postflight with zero repair/mutation.

TB6 must preserve raw receipts for the exact-repeat terminal, different-entry tamper, combinatorial-recurrence control and step-budget control. Focused S3 PASS is **not** selector425 credit. Mandatory successor after EXEC is `M4-CP-SCALE-TB6-REV`; only that Review may accept the S3 focused contract for selector publication or reject the candidate.

No benchmark is required for this semantic S3 control slice unless CB7 changes resource-sensitive behavior beyond the frozen single variable; such broadening is itself a STOP condition.

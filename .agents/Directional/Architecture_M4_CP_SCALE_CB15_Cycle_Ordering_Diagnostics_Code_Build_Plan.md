# M4-CP-SCALE-CB15 — Cycle-Ordering Diagnostics Code + Build Plan

**Turn:** `M4-CP-SCALE-CB15`
**Owner:** Code + Build
**Cause:** `M4-CP-SCALE-TB12-R1-EXEC-CAND-01`
**Scope:** decision-neutral diagnostics only
**Runtime:** forbidden (`runtimeExecution=false`)
**Accepted runtime authority on entry:** package `10473134357` / selector426 **426/426**
**Expected successor if compile/package evidence is valid:** `M4-CP-SCALE-TB12-R2-EXEC`

## 1. Purpose

TB12-R1 Review proves that the observed `CycleOrderingFailed` is produced by the topology/cycle-basis linearization path, not by raw-field values: `FieldTransportAtlas` asks one algebraic `PCFaceTangentBundle::cycles` support row to become a single closed directed face loop before transport composition. The retained receipt does not identify the failing row or which structural predicate inside `order_cycle_steps` rejected it. A semantic repair is therefore premature.

CB15 adds only enough structured diagnostics to identify that exact failure on a later immutable focus run. It does not repair the cycle, change admissibility, alter the genus-two fixture/field, broaden/narrow the focus, or publish selector427.

## 2. Frozen source/runtime boundary

Allowed source surface is limited to the existing diagnostic/error path needed to publish the failure locus, expected to be:

- `include/directional/authority/FieldTransportAtlas.h` — additive diagnostic enum/fields only if needed;
- `src/authority/FieldTransportAtlas.cpp` — classify the existing `order_cycle_steps` failure without changing its decision;
- `tests/FieldAlignedCurveNetworkTests.cpp` — additive receipt printing only; all existing semantic assertions stay unchanged.

No other production/test/fixture/CMake/benchmark/selector change is authorized unless Review is reopened first.

Generated Directional runtime is forbidden in this turn: no test, benchmark, `ctest`, discovery/list/help/version command, CLI, fuzzer or custom input. Compilation must use `.github/workflows/agent-compile-reusable.yml` under mandatory GMP/GMPXX and package `runtimeExecution=false` evidence.

## 3. Required diagnostic contract

For every path that currently returns `IncompleteCycleBasisReason::CycleOrderingFailed`, retain the same outer error code and reason and publish additive diagnostic state sufficient to distinguish the structural cause.

Minimum receipt fields:

1. `topologyRegion` — already present and unchanged;
2. `cycleRowIndex` — exact zero-based `bundle.cycles` row that could not be ordered;
3. `cycleKind` — derived from the same existing row partition: `LocalVertex`, `BoundaryLoop`, or `HandleGenerator`; deriving it for diagnostics may occur before successful ordering, but must not change the later successful witness classification;
4. `supportEdgeCount` — count of nonzero semantic cycle coefficients after the existing explicit-zero and coefficient-validity rules;
5. `uniqueFromFaceCount` and, where bounded/available, the failing current/source face and source edge;
6. one `CycleOrderingFailureReason` (or equivalent diagnostic-only enum) with at least:
   - `DuplicateFromFace`;
   - `MissingSuccessorFromFace`;
   - `SupportEdgeReused`;
   - `DirectedAdjacencyFaceMismatch`;
   - `OpenOrUnconsumedSupport`.

The helper may return a diagnostic result object instead of bare `optional` if that is the smallest implementation, but the success path's ordered `FieldTransportStep` sequence must remain byte/semantic-equivalent. No diagnostic field may participate in production branching outside the pre-existing failure return.

## 4. Decision-neutrality invariants

All are STOP conditions:

- `FieldAtlasBuildErrorCode::IncompleteCycleBasis` changes for the frozen failing path;
- `IncompleteCycleBasisReason::CycleOrderingFailed` changes for the frozen failing path;
- the set/order/content of successful `FieldTransportStep` cycles changes;
- any field transport, quadrangulability witness, topology-region, A2/A3 product, semantic digest, or source-binding value changes;
- genus-two OBJ/rawfield/metadata bytes change;
- the S5 focus changes any existing assertion or precondition rather than only printing additive diagnostics;
- selector426 changes from 426 LF rows / SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, or selector427 appears;
- any generated Directional runtime executes during CB15.

If diagnostics cannot be added without crossing one of these boundaries, stop and return to Review rather than implementing a semantic workaround.

## 5. Static checks before compile

Before publishing the compile candidate:

- source-review the old and new ordering helper side-by-side and prove every pre-existing success/failure predicate remains present with the same ordering;
- prove additive diagnostics are written only from data already computed at the failure boundary;
- prove the existing focused assertions are byte-identical except permitted additive receipt formatting;
- re-hash the genus-two fixture trio and selector426;
- run repository static/lint/diff checks required by policy; do not execute a Directional binary.

## 6. Compile/package gate

Use the durable reusable compile workflow for the standard eight targets under Release/static/Ninja/PRE_TEST and mandatory GMP/GMPXX. Accept CB15 compile evidence only if:

- configure/preflight/build exits are zero;
- all required targets compile/link;
- authoritative link evidence contains both `gmpxx` and `gmp`;
- exact source SHA and clean source-status snapshots are packaged;
- recursive self-excluding `SHA256SUMS` verifies;
- source archive and diagnostic source are present;
- `runtimeExecution=false` is explicit;
- selector426 and genus-two fixture bytes match the frozen inputs.

No compile result grants S5 credit and no package is promoted as runtime authority inside CB15.

## 7. Exact successor contract

If the compile/package gate is valid, exact successor is `M4-CP-SCALE-TB12-R2-EXEC`, artifact-only.

That turn must consume the exact CB15 package unchanged, preserve archived executable modes, verify package/source/fixture/selector hashes, and execute `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` in exactly one fresh producer process. The purpose is to capture the new row/subreason receipt. The focus is expected to remain RED because CB15 is decision-neutral; frozen fail-fast therefore continues to withhold selector426 runtime and benchmark execution on RED.

If the focus unexpectedly PASSes, if the old error/reason changes, if zero tests are selected, or if immutable postflight changes, treat it as orchestration/diagnostic-nonneutral evidence and route to mandatory Review. Do not claim S5 credit or publish selector427.

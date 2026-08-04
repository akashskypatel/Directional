# Milestone G P5-R1C Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-TB24 artifact-only R1C validation

## Authority

Execute artifact `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`, directly.

- exact compiled source: `f4cce52006d21a248473e327ada1d66183af54e6`;
- workflow event commit: `f652e518152b2944b176464b2ea8cfd99d09ccda`;
- applied source-diff SHA-256: `b41f4a6ffc517d1547a6da777fe01fc55e18e0b09aad47db83843333f6bea99c`;
- artifact SHA-256: `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`;
- workflow-log artifact: `8904836090`;
- workflow-log SHA-256: `c8ef21410b17971ff7a4d6366c5da5a4b8df157be7fab3068e4c4efa021d7db3`.

Do not configure, build, relink, patch, regenerate, or modify source in P5-TB24.

## 1. Package authority

Before executing either packaged binary, verify:

- archive SHA-256;
- exact source commit and ancestry;
- empty source status;
- recursive checksum manifest **40/40**;
- **42** packaged files;
- **26** fixture files;
- **9** recursive submodule records;
- all four packaged target hashes;
- source archive contains:
  - the corrected opposite-traversal predicate;
  - the whole-mesh orientation reversal contract;
  - `SourceAuthoritativeMeshValidatorPhase22Tests.cpp` in `directional_phase1_tests`.

Any authority mismatch terminates the turn before runtime execution.

## 2. Source-chart orientation contracts

Run all `SourceChartTransitionsR1.*` tests first.

Require:

- valid opposite shared-edge traversal creates a usable graph;
- same-direction traversal fails closed;
- forward and reverse transitions are exact inverses;
- endpoint and barycentric maps remain exact;
- global source orientation reversal remains valid;
- reversing only one incident face remains invalid;
- face-row permutation preserves canonical component and transition hashes;
- hard-rail, component, sheet, source-boundary, disconnected-sheet, and nonmanifold barriers remain effective.

Any failure remains an R1 blocker. Do not advance to arrangement or production conclusions by excluding a failed orientation contract.

## 3. Newly packaged source-authoritative validator contracts

Run `SourceAuthoritativeMeshValidatorPhase22.*` from `directional_phase1_tests`.

Require that intended valid cases pass and intended invalid cases fail for their documented source-authoritative reason. Record:

- test count;
- pass/fail list;
- earliest typed validator failure;
- whether the source-chart graph was available;
- component, sheet, hard-rail, and source-entity evidence.

Do not weaken or reinterpret a validator contract merely because it becomes visible in the packaged target for the first time.

## 4. R0 recovery authority

Run the focused recovery contracts, including the explicit planar end-to-end case.

Require:

- recovery remains default-off;
- direct fallback `Fail` never executes legacy output;
- explicit recovery requires opt-in;
- successful explicit recovery reports `SourceGridRecovery`, not `CompletedSurfaceCells`;
- recovery output passes the strict source-authoritative validator;
- failure retains the earliest typed reason and exact rollback.

The R1C change does not authorize recovery to substitute for direct surface paving.

## 5. Graph-dependent arrangement and completion contracts

Run the P5-TB23 failures that depended on a valid transition graph:

- adjacent per-face canonical ownership;
- unlabelled ownership registry;
- repeated-cell class membership;
- curved multi-face stitched topology and Euler characteristic;
- bunny singularity-fan intrinsic rotation;
- boundary source-vertex/source-edge completion aliases.

Require that no call site uses position, source-triangle pairing, insertion order, or ownership frequency as identity.

When a failure remains, record whether the transition graph is now available and identify the earliest subsequent producer rather than attributing all failures to R1C.

## 6. Phase 14–18 regression gate

Run the complete Phase 14–18 aggregate and Phase 16 independently.

Reference points:

- P5-TB22: **236/236** before R1 tests were added;
- P5-TB23: **233/242** with the inverted predicate;
- P5-TB24 includes the new whole-mesh orientation contract and packaged validator sources.

Acceptance requires all pre-existing Phase 14–18 tests to return to at least the P5-TB22 behavior and all intended new R1C contracts to pass. Report exact numerator and denominator rather than comparing only percentages.

## 7. Analytic direct production

Run independently with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

1. plane;
2. multi-face seam;
3. close sheets;
4. disconnected close sheets, when an existing packaged direct-production entry is available.

Record:

- success and output origin;
- completed quad count;
- transition graph availability and structural hashes;
- canonical source-entity evidence;
- validation failure count and earliest typed failure;
- fallback/recovery/legacy execution flags;
- wall time and peak working set.

R1C closes its specific defect only when these cases are no longer rejected because valid opposite source-edge winding invalidates the graph. Direct geometric completion may expose a later producer; report it without masking it through recovery.

## 8. Phase 20 and pipeline regression

Run the focused Phase 20 cases affected in P5-TB23, then the complete Phase 20 scope.

Require:

- no recovery origin is reported as direct completion;
- fail-closed fallback semantics remain intact;
- stage-lineage tests are not bypassed;
- component scheduling and validation receive the corrected graph;
- later-stage failures are not rewritten as source-chart success.

## 9. Complete-suite termination

Run the complete packaged test suite once with a process watchdog used only as a safety mechanism.

Requirements:

- report total discovered tests;
- record the last test and marker when a timeout occurs;
- treat timeout as a termination failure;
- compare against P5-TB22 terminating behavior and the P5-TB23 GP26 stall.

Do not run the full direct bunny benchmark matrix solely for R1C. The complete-suite GP26 contract is sufficient to determine whether the prior termination regression remains.

## 10. Runtime decision

Advance to R2 only when:

- all `SourceChartTransitionsR1.*` tests pass;
- packaged Phase 22 validator contracts behave as intended;
- explicit recovery authority passes;
- graph-dependent Phase 14–18 regressions are closed;
- analytic cases are not blocked by the corrected winding predicate;
- the complete suite terminates.

When a later analytic producer remains after these conditions, document whether it belongs to R2 and prepare a focused R2 plan. Otherwise remain on R1 and prepare the smallest causally necessary correction.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

# M4-CP4-CB1 — produced-debt and production-work evidence Code + Build plan

**Turn:** `M4-CP4-CB1`
**Type:** Code + Build; compile/package only
**Predecessor:** `M4-CP4-DEFN`
**Normative authority:** `Architecture_M4_CP4_Frozen_Definitions.md`
**Accepted runtime authority entering turn:** package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**
**Selector rule:** selector427 is byte-frozen in CB1; no append/publication in this turn.

## 1. Goal

Make the smallest implementation/test-authority changes required to make CP4's focused evidence executable without changing accepted A3 scheduling semantics:

1. add auditable production-baseline work/bit-width/progress receipts and independent validation;
2. add the three **produced** `G4-B002` focused identities;
3. add the produced same-region multiplicity-2 binder/oracle/tamper identity;
4. complete the dedicated `make_zero_transport_field` upstream-precondition audit for CP4-relevant semantic-success uses;
5. compile/package the exact affected owners with mandatory GMP; execute no Directional runtime.

This is not selector publication and not cumulative acceptance.

## 2. Surgical implementation scope

### CB1-A — current production A3 work receipt

Touch only the current family/sign-free baseline surfaces required to carry and validate the CP4 receipt, expected primarily:

- `include/directional/geometry/GlobalConformityBaseline.h`;
- `src/geometry/GlobalConformityBaseline.cpp`;
- `src/geometry/GlobalConformityBaselineValidator.cpp`;
- `src/geometry/GlobalConformityParityGraph.cpp` and its private interface only if needed to return per-call dimensions;
- focused baseline tests.

Do **not** route production back through historical framed `GlobalConformityWorkLedger` and do not add a second solver.

The successful baseline must expose enough immutable evidence for the validator to prove:

- producer T-join calls = `1 + 2E`;
- validator T-join calls = `1 + 2E`;
- aggregate = `2 + 4E`;
- ordered initial/trial/selected invocation identity and canonical prefix length;
- each call's `T_j`, matching nodes/edges and matching-executed flag;
- `matchingEdges <= T_j(T_j-1)/2`;
- zero retries/resets;
- monotone producer and validator progress from `(1,E)` to `(0,0)`;
- independently recomputed category/overall EInt magnitude widths from the baseline-owned exact values frozen in CP4 definitions.

The validator must reject at least one independent tamper for count/order/progress and one for dimension/bit-width evidence. Recomputing the producer's stored number from another stored number is not independent.

No absolute bit-width threshold is added.

### CB1-B — focused produced `G4-B002` tests

Add new tests; do not rewrite the accepted historical rows:

- `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`;
- `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering`;
- `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected`.

Every subject must use production pipeline authority with fallback `Fail`, source-grid recovery disabled where applicable, and retained intermediate products. Direct draft helpers may be used only as negative controls, never as the credited subject.

For the torus identities, use the production torus pipeline already exercised by `torus_fixture()` rather than cloning a new torus product.

For candidate extraction, first prove the chosen closed source and retained complex satisfy the precondition. If no existing fixture reaches a candidate-bearing produced complex, add no synthetic substitute: compile an identity that reports/preconditions the exact missing stage only if that remains a valid test shape; otherwise STOP to Review before broadening product semantics.

### CB1-C — produced same-region multiplicity-2 binder proof

Add:

`M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder`.

The test must derive the two A2b boundary occurrences independently from the produced topology plan, then compare them to production baseline incidences and separately tamper one incidence. The existing synthetic parity self-loop unit test is supporting coverage only.

If no existing produced topology plan contains the required same-region double occurrence, STOP and record the witness/producer precondition blocker. Do not author a hand-made `GlobalTopologyPlan` and call it produced.

### CB1-D — zero-transport helper precondition audit

Audit `make_zero_transport_field` semantic-success uses in the CP4-relevant owner/test surfaces. The bounded correction is test-authority only:

- each semantic-success use must assert the upstream field/atlas/topology precondition it relies on before claiming downstream route reachability;
- intentional rejection/negative uses must be marked as such and are not required to satisfy the success precondition;
- do not change production validation to accommodate an inadmissible helper;
- do not add another helper that merely hides the same invalid topology.

If the audit proves a production semantic change is required, STOP to Review; CB1 is not authorized to make that change.

## 3. Explicit non-goals

- no selector427 edit or new selector publication;
- no Directional runtime, test execution, benchmark, discovery, list/help/version invocation, or `ctest`;
- no S1 numeric calibration;
- no S2-arrival exact-fallback implementation;
- no row399 path/`sourceFaces` tamper unless CB1 independently proves it must legitimately touch row399's owning contract; default is no touch;
- no G4-B003 work;
- no A3 semantic objective/parity/tie-break change;
- no A4/local completion change;
- no performance refactor unrelated to work evidence.

## 4. Build boundary

Use the mandatory `agent-compile-reusable.yml` workflow with GMP/GMPXX authoritative linkage. Compile only the directly affected test owner(s) plus `directional_core` and any mandatory package owner set required by the frozen next TB. Package source/evidence with `runtimeExecution=false`.

Do not execute generated binaries in CB1.

## 5. Verification before closeout

Static/compile verification must establish:

1. selector427 bytes and SHA remain exactly unchanged;
2. accepted production A3 schedule semantics are unchanged;
3. work receipt fields are certificate-owned/immutable and independently validated;
4. exact source compiles with mandatory GMP;
5. every new focused identity has exactly one compiled owner and no duplicate name;
6. no production test subject enables fallback/recovery for credited produced authority;
7. helper audit classifications are explicit and no success precondition is silently assumed;
8. package reports `runtimeExecution=false`.

## 6. Stop/falsifier rules

STOP to Review before broadening scope if:

- a produced debt witness does not reach its required stage;
- same-region multiplicity-2 cannot be found on production authority;
- work accounting cannot include the self-validator's second `1+2E` schedule;
- matching receipt dimensions require changing the solver semantics;
- a proposed receipt feeds a semantic decision;
- helper audit needs production semantics changed;
- selector427 would need modification;
- compile exposes a second semantic dependency outside this plan.

## 7. Successor

On compile/package GREEN, exact successor is an artifact-only `M4-CP4-TB1-EXEC` plan authored from CB1 evidence. TB1 must run focused CP4 identities as fresh processes and re-prove the exact accepted selector427 prefix as frozen by the eventual TB plan. No publication row is accepted merely because CB1 compiles.

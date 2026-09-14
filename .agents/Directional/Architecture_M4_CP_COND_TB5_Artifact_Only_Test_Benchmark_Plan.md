# M4-CP-COND-TB5-EXEC — Artifact-Only Test + Benchmark Plan

**Turn:** `M4-CP-COND-TB5-EXEC`
**Type:** immutable artifact-only runtime execution
**Predecessor:** `M4-CP-COND-CB5` compile/package GREEN
**Mandatory successor:** `M4-CP-COND-TB5-REV`

## Frozen authority

TB5-EXEC consumes exactly the CB5 package and selector candidate:

- artifact ID: `10331193451`;
- artifact ZIP/digest SHA-256: `3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b`;
- packaged source: `07984711db59eaa228820e7d44e5552a652edadf`;
- selector423: `.agents/Directional/Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt`;
- selector423 SHA-256: `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- accepted prefix selector422 SHA-256: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- expected owner census: **30 authority-kernel / 277 producer / 75 completion / 41 validation = 423**.

The accepted runtime authority remains package `10327643907` / selector422 until TB5 Review says otherwise.

## Hard artifact-only boundary

TB5 may extract/copy the immutable package into a runner-temporary execution view and execute packaged binaries. It must not:

- configure, compile, link, relink, regenerate, or discover tests by executing binaries;
- mutate or repair package/source/test/fixture/selector bytes;
- fetch replacement binaries or source;
- alter permissions except preserving the packaged file modes during extraction/copy;
- synthesize pass/skip or weaken an assertion/tolerance;
- use any report-only identity as a substitute for selector credit.

Any required package/input absent or inconsistent at preflight is orchestration failure, not semantic evidence.

## Immutable preflight

Before the first Directional process:

1. Verify the downloaded artifact SHA-256 equals `3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b`.
2. Verify packaged `SHA256SUMS` **27/27** with the manifest excluded from itself.
3. Require packaged source commit `07984711db59eaa228820e7d44e5552a652edadf`.
4. Require preflight/build exit codes `0`, all source-status receipts empty, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`.
5. Require GMP/GMPXX evidence and the runtime libraries needed by the packaged dynamically linked test executables.
6. Hash selector423 and require exactly 423 LF identities.
7. Hash rows 1-422 independently and require exact accepted selector422 prefix `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`.
8. Require row423 exactly `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`.
9. Resolve every identity statically to exactly one packaged owner binary; require owner census **30/277/75/41** with zero missing/ambiguous identities.
10. Freeze byte+mode censuses for the package, extracted packaged source, and execution view for postflight comparison.

A failed preflight launches **zero** selector tests and receives no semantic ledger.

## Runtime gate

Execute selector423 in file order as **423 fresh processes**, one exact identity per process, using its statically resolved packaged owner binary.

For ordinal `N` / identity `I`, invoke the packaged binary with exact gtest filtering equivalent to:

```text
<owner-binary> --gtest_filter=I --gtest_color=no
```

Use the already accepted per-process guard `timeout -k 5s 180s` where supported. Do not impose an outer workflow/job timeout whose purpose is to truncate the complete 423-process gate.

For every process record at minimum:

- selector ordinal and identity;
- owner binary;
- exact command;
- start/end UTC and elapsed time;
- exit status / timeout status;
- actual selected/executed test identity/count;
- PASS/RED classification and complete stdout/stderr.

A semantic PASS requires exit `0`, exactly one selected/executed test matching the requested identity, and no framework failure. Any assertion/test failure is RED. Zero-selected or wrong-selected is orchestration failure. A timeout is orchestration/infrastructure failure and never semantic pass/skip.

There is no report-only 424th process in TB5. The former boundary placeholder has been replaced by the gating row423.

## Required result partitions

The execution summary must report independently:

- cumulative selector423: **423 expected**;
- inherited accepted prefix rows 1-422: **422 expected**;
- appended CB5 row423: **1 expected**;
- PASS / RED / SKIP / timeout / selection-mismatch counts and exact ordinals/identities for every non-PASS outcome.

A complete mechanically green attempt therefore requires **423/423 PASS**, inherited **422/422**, appended **1/1**, zero RED, zero SKIP, zero timeout, and zero selection mismatch.

If an infrastructure/orchestration interruption prevents a complete attempt, do not stitch partial executions into acceptance. Preserve invalid-attempt evidence, correct only through the authorized cadence, and restart a later valid attempt from ordinal 1.

## Exact immutable postflight

After the final selector process, recompute byte+mode censuses for:

- immutable package;
- extracted packaged source;
- execution view.

They must exactly equal preflight. Record explicit booleans proving:

- `immutability=true`;
- `configure_execution=false`;
- `compile_execution=false`;
- `relink_execution=false`;
- `generated_discovery=false`;
- `package_repair=false`;
- `source_test_fixture_selector_mutation=false`.

Any postflight mismatch invalidates the attempt as orchestration/evidence failure.

## Evidence package

Persist a result artifact and an always-uploaded diagnostic log containing:

- frozen authority and preflight receipts;
- 423-row process ledger with raw outputs;
- partition summary and exact non-PASS census;
- pre/post byte+mode census comparison;
- commands/environment/runtime-library evidence;
- exact run/job/source/artifact identities;
- a non-self-referential `EVIDENCE_SHA256SUMS` produced only after substantive evidence files are final, with `sha256sum -c` verification.

Do not delete the immutable CB5 package artifact. It remains the candidate authority through Review.

## Review handoff

`M4-CP-COND-TB5-EXEC` never promotes selector423 or closes CP-COND itself. Its mandatory successor is `M4-CP-COND-TB5-REV`, which must reopen primary evidence, independently verify selector/prefix and row423 authority, adjudicate any non-PASS result, and decide whether the frozen boundary raw-precondition conjunct is satisfied and CP-COND can close.

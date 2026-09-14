# M4-CP-COND-TB5-EXEC — Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-COND-TB5-EXEC`
**Disposition:** **MECHANICALLY GREEN / REVIEW REQUIRED / NO PROMOTION**
**Mandatory successor:** `M4-CP-COND-TB5-REV`

## Authority

TB5-EXEC consumed only the immutable CB5 compile/package candidate. No configure, compile, link, relink, generated discovery, package repair, source/test/fixture/selector mutation, or benchmark execution occurred inside the immutable gate.

- candidate package artifact: `10331193451`;
- candidate package ZIP SHA-256: `3f23572a4869e469a6f3ba1082af8a7836c29d9566d143e1a395950d8a94230b`;
- packaged semantic source: `07984711db59eaa228820e7d44e5552a652edadf`;
- selector423 SHA-256: `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- accepted selector422 prefix SHA-256: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- authoritative runtime workflow run/job: `34805164109 / 103855521990`;
- result artifact: `10333057375`, SHA-256 `240d22578a48570b8ecab26c158d24ccc70f4e5a5c79a53d4bdd9359e1c78bb3`;
- diagnostic log artifact: `10332819388`, SHA-256 `e2b3262b5188149a8bfe3664e7473c44feeb73ad119216081d1d0889c9d66499`.

Accepted runtime authority remains package `10327643907` / selector422 **422/422** until mandatory Review independently adjudicates TB5 evidence and any promotion/CP-COND closure.

## Immutable preflight

Preflight completed before the first selector process and established:

- downloaded candidate artifact SHA-256 exactly matched the frozen package digest;
- packaged self-excluding `SHA256SUMS` verified **27/27**;
- packaged source commit was exactly `07984711db59eaa228820e7d44e5552a652edadf`;
- compile/preflight exits were zero, all packaged source-status receipts were empty, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- packaged runtime linkage resolved GMP/GMPXX for all four owner executables;
- selector423 contained exactly **423 LF identities** at the frozen hash;
- rows 1-422 independently reproduced the accepted selector422 hash;
- row423 was exactly `InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`;
- static ownership was exactly **30 authority-kernel / 277 producer / 75 completion / 41 validation = 423**, with zero missing or ambiguous identities;
- package, extracted packaged source, and execution-view byte+mode censuses were frozen before runtime.

Preflight evidence records `preflight=PASS`.

## Runtime result

The complete gate executed **423 fresh exact-filter processes in selector order**, one identity per process.

- selector423 cumulative gate: **423/423 PASS**;
- inherited accepted prefix rows 1-422: **422/422 PASS**;
- appended CB5 row423: **1/1 PASS**;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**;
- total Directional processes executed: **423**.

Row423 selected exactly one test and passed:

`InputConditionerCPCondCB5.BoundaryTruncatedSeparatrixRawPreconditionIsIndependentAndPreserved`

The runtime ledger contains 423 data rows plus its header, and the non-PASS ledger contains only its header. All 423 raw per-process logs are present.

## Exact immutable postflight

Postflight re-censused the package, extracted packaged source, and execution view. Every pre/post byte+mode census is byte-identical.

Recorded boundary receipts are:

- `immutability=true`;
- `configure_execution=false`;
- `compile_execution=false`;
- `relink_execution=false`;
- `generated_discovery=false`;
- `package_repair=false`;
- `source_test_fixture_selector_mutation=false`.

## Evidence integrity

The result evidence contains a non-self-referential `EVIDENCE_SHA256SUMS` with **440** entries. Independent local verification of every listed entry passes. The result archive itself re-hashes to the published artifact digest.

No interrupted/partial execution is stitched into this result. Run `34805164109` is the complete authoritative attempt.

## Regression disposition

TB5-EXEC observes no RED, SKIP, timeout, selection mismatch, immutable-postflight mismatch, or other semantic regression candidate. No new stable regression/event/category/recurrence is assigned. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

`M4-CP-COND-TB4-REV-CAND-01` remains **OPEN / REVIEW REQUIRED / NON-STABLE** through this EXEC turn. Its prescribed runtime falsifier is mechanically satisfied, but EXEC does not independently adjudicate the raw-oracle authority or close the candidate.

## Stop boundary

TB5-EXEC is mechanical artifact-only evidence. It does **not** promote selector423, replace accepted runtime authority, close `M4-CP-COND`, or unblock CP-SCALE.

Mandatory successor: **`M4-CP-COND-TB5-REV`** under `Architecture_M4_CP_COND_TB5_Review_Plan.md`.

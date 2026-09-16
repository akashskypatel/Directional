# M4-CP-SCALE-TB11 — Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M4-CP-SCALE-TB11-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`
- Build artifact: `10473134357` (`m4-cp-scale-cb12-result-35163156552`)
- Provider artifact SHA-256: `aa503e4be2aa1904172c9a3710f41e7cf0ccd352575b39078ece61b7d5d660b9`
- Packaged source archive SHA-256: `190233bd050a2d1a6c042217f11294f38fc29fdc62d9c6b124a84fefb914d570`
- Package `SHA256SUMS` SHA-256: `2dbacc439ed714d9c8dfd5c3be5e2d9942a0fe99737aa1f9a0281632d21cf0c8`
- Selector426: `.agents/Directional/Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt`
- Selector426 SHA-256: `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`
- Exact first425 prefix SHA-256: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`
- Planned environment/platform: hosted Ubuntu runner; artifact-only execution, no rebuild.

## Validation Objective

Prove that the newly published selector426 is cumulatively green on the immutable CB12 package. This is the runtime half of `M4-CP-SCALE-TB10-REV-OBS-01`; it does not by itself grant cumulative S4 credit because `M4-CP-SCALE-TB11-REV` remains mandatory.

The only selector delta is producer row426:

`M4CPScaleS4.IncrementalTopologyRejectorNeverDisagreesWithFinalDiscCertificate`

TB11 must measure the exact cumulative gate, not import TB10's focused PASS as row426 credit.

## Preconditions

Before any Directional runtime:

1. download artifact `10473134357` directly; do not rebuild, reconfigure, relink or repair it;
2. verify provider artifact identity where available;
3. verify package `SHA256SUMS` 28/28;
4. verify `metadata/source-commit.txt` equals `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`;
5. verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
6. verify packaged selector426 has exactly 426 LF-terminated rows, 426 unique identities, full SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, and first425 prefix hash `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
7. map every selector identity to exactly one packaged owner binary; require owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**;
8. pre-initialize the complete 426-row result ledger as UNEXECUTED before the first process.

Any precondition failure stops runtime and preserves evidence as orchestration/mechanical failure, not semantic RED.

## Ordered Execution Plan

### 1. Exact cumulative selector execution

Execute selector426 in exact file order as **426 fresh processes**, one exact gtest filter per process against its mapped packaged owner binary.

For every row preserve at minimum:

- ordinal and exact identity;
- owner binary;
- process command/filter;
- selected/executed test count;
- exit code;
- PASS/RED/SKIP classification;
- raw stdout/stderr;
- wall time and timeout classification.

Require each row to select and execute exactly one identity. No process may execute a second test.

### 2. Row426 receipt

Row426 must execute as a fresh producer-process result, not be copied from TB10. Preserve its raw output and exact selected/executed count as the cumulative S4 publication receipt.

No new semantic expectations are added in TB11 beyond the test's compiled assertions; the independent safety theorem and focused non-vacuity were already adjudicated by TB10 Review.

### 3. Cumulative result and ownership census

Require:

- **426/426 PASS**;
- zero RED;
- zero SKIP;
- zero crash;
- zero timeout;
- zero selection mismatch;
- zero unexecuted selector rows;
- exact owner census **30/280/75/41**.

The prior selector425 425/425 result is provenance only. TB11 must freshly re-execute all 425 prefix identities plus row426.

### 4. Immutable postflight

After all processes, re-hash and compare every package/source/execution-view item covered by the harness. Require exact pre/post equality and explicit false/zero mutation flags for:

- configure/build/relink;
- source/test/fixture/selector repair;
- benchmark execution;
- package repair;
- mode/input mutation.

## Benchmark Plan

- Applicable: **no**.
- Rationale: CB12 is publication-only and TB10 already measured the S4 product behavior. TB11 exists only to establish fresh cumulative selector426 runtime authority.
- No `directional_benchmarks` execution is authorized.

## Stop and Blocker Conditions

Stop and preserve evidence if any of the following occurs:

1. artifact/source/provider identity or package checksum mismatch;
2. selector426 count/uniqueness/full hash/prefix hash mismatch;
3. owner census differs from 30/280/75/41 or any identity maps to zero/multiple owner binaries;
4. any rebuild, configure, relink, source/test/fixture/selector mutation or repair becomes necessary;
5. any row has selection count other than one, execution count other than one, RED, SKIP, crash or timeout;
6. postflight differs from preflight;
7. the harness cannot prove fresh-process isolation for every row.

A runtime RED is semantic evidence and routes to mandatory Review + Plan. A pre-runtime orchestration/mechanical failure produces no semantic ledger and routes according to `Turn_Cadence.md`.

## Plan-Defined Reruns

- Normal retries: none.
- A semantic RED may not be retried before Review.
- An orchestration-only failure may be corrected only in a bounded control-plane CB and then re-executed fresh on the unchanged immutable package.
- No subset rerun can substitute for the complete 426-process cumulative gate.

## Completion Criteria

TB11-EXEC is complete when:

- all 426 selector rows have explicit fresh-process results;
- the cumulative ledger and owner census are complete;
- immutable pre/post evidence is preserved;
- raw evidence is sufficient for `M4-CP-SCALE-TB11-REV` to independently re-hash, re-map owners and re-derive acceptance without chat context.

Even if 426/426 is green, cumulative S4 selector credit is withheld until mandatory `M4-CP-SCALE-TB11-REV`.

# M6-CP1-TB6-A6 Artifact-Only Test + Benchmark Report

**Turn:** `M6-CP1-TB6-A6-EXEC`
**Disposition:** COMPLETE / ORCHESTRATION INVALID / NO SEMANTIC CREDIT / REVIEW REQUIRED
**Candidate:** artifact/source `10896307843 / a532f803bd2f0ef92342652ea3f1a9b64945ba69`
**Authoritative runtime result/log artifacts:** none — the attempted execution was local and invalid before an authoritative runtime gate was established
**Exact successor:** `M6-CP1-TB6-A6-REV`

## 1. Immutable candidate preflight

The CB6-A6 candidate itself re-verifies exactly:

- candidate ZIP SHA-256: `54eb770889822ef265053494e55e25af79616f77305d1ac6900f2f8969f56b7e`;
- packaged source archive SHA-256: `e48ad4a919e450ccd9809083af0c02e2260b7c040d40ee94741aa79428fc9a45`;
- exact semantic source: `a532f803bd2f0ef92342652ea3f1a9b64945ba69`;
- root `SHA256SUMS`: **28/28** before the attempt and again after the aborted attempt;
- selector449: **449 LF rows**, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: **449 rows**, SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`, owner census **32 / 301 / 75 / 41**;
- packaged test binaries retained archived mode `0755`; no `chmod` or package repair occurred;
- package and packaged-source byte/mode censuses are unchanged after the abort.

The resume used verified runtime-free source snapshot run/artifact `36361700237 / 10945667717`, event/source `a9a79a9150214ded2250d7f19d82be3599b12b67`, with **5322/5322** source-manifest rows and `runtimeExecution=false`. That snapshot was used only for repository authority/static inspection.

## 2. Orchestration defect

The local executor made a process error before the frozen gate could become authoritative: it ran the packaged binaries directly from the immutable package instead of first constructing the standard separate **execution view** with the packaged source fixture tree at `test-data/benchmarks/fixtures` adjacent to the copied binaries.

The repository's `TestFixturePaths.h` intentionally requires that adjacent test-data package. Focused row 6 therefore failed with the deterministic exception:

```text
Directional test-data package not found adjacent to test executable: .../package/bin
```

The same exception later appeared on selector ordinals **41, 42, 43, 44, and 46**. This is an execution-environment/orchestration failure, not candidate product evidence and not a PASS-to-RED semantic regression.

No source, test, fixture, selector, routing, manifest, packaged binary, or executable mode was changed. No configure, compile, relink, benchmark, discovery, or retry occurred.

## 3. Partial invalid attempt

The invalid attempt completed **149** exact-filter processes before it was manually stopped once the common orchestration root was proven:

| phase | completed | PASS-like process exit | fixture-root failure |
|---|---:|---:|---:|
| focused | 11 | 10 | 1 |
| selector449 | 138 | 133 | 5 |
| **partial total** | **149** | **143** | **6** |

All 149 completed processes selected exactly one test and skipped zero. The six nonzero exits are all the same missing-test-data orchestration defect. The partial execution-ledger SHA-256 is `9a416b653c08834089756895af7f9d13f46d10b6781c74dbfbedf3e8c872e32f`; the partial red-ledger SHA-256 is `ff7a6e4ab2806adeefb4592bc6afd8a899fc8feb32208685e8dfac0d4581f46e`.

Selector ordinal 139 was in flight when the invalid attempt was stopped and receives no result. Frozen selector row140 and the pre-registered holonomy falsifiers row232 and rows444/446/448/449 were **not reached**. No partial log contains `OccurrenceInvalidCornerAuthority` or `QuotientHolonomyConflict`, but that absence has no acceptance value because the gate is incomplete and invalid.

## 4. Regression categorization and accounting

This turn creates **no product regression candidate and no stable-history increment**. The observed failure is classified as a non-stable **orchestration/execution-view construction defect** owned by this EXEC attempt.

Stable accounting remains **55 events / 16 categories / 39 recurrences** and project debt remains **1**, M6-owned. Candidate `10896307843 / a532f803...` remains unpromoted. Reviewed runtime authority remains `10879581622 / 82b86a28...` under selector449 **449/449**.

The frozen plan explicitly forbids retry after runtime starts. Therefore this EXEC turn does not create a corrected second execution attempt. It preserves the invalid evidence and advances only to mandatory Review.

## 5. Review obligations

`M6-CP1-TB6-A6-REV` must:

1. confirm the failure is orchestration-only and carries zero semantic credit;
2. decide whether a fresh successor runtime attempt is authorized and, if so, assign a distinct retry turn rather than silently rerunning this EXEC;
3. require the standard immutable execution-view construction before any future runtime starts: copied package binaries with byte/mode equality plus `test-data/benchmarks/fixtures` sourced from the already packaged source archive;
4. preserve the original 460-process order and the row232 / 444 / 446 / 448 / 449 holonomy falsifiers if a fresh attempt is authorized;
5. keep `M6-DEFN-R4`, A7, and `G4-B002` held until a valid runtime gate and Review authorize advancement.

## 6. Stop rule

No semantic promotion, CP1 closure, regression recovery, stable-event change, debt credit, or A6 acceptance is claimed. Exact successor is **`M6-CP1-TB6-A6-REV`**.

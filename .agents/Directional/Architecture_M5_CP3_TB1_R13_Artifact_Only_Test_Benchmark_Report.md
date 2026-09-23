# M5-CP3-TB1-R13 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R13-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on CB15 candidate `10730261023 / 4dfe392d28d60b448e2f32253f7d170221ac57ec`
**Disposition:** **MECHANICALLY COMPLETE / SEMANTIC RED / 445 PASS + 2 RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R13-REV`

## 1. Immutable authority

R13 consumed only the compile-green CB15 candidate and frozen routing/selector authority:

- semantic source `4dfe392d28d60b448e2f32253f7d170221ac57ec`;
- compile run/job `35811645725 / 107024364608`;
- candidate result artifact `10730261023`, ZIP SHA-256 `d124bf4456c11cc7d7eb2022a94391d9a8c6f1ebd368ad04403f1dc46d3f521d`;
- root package manifest SHA-256 `29e900f4a8e0d6ba814f9ed4efe3d9a3b2f0f499690c3562b51a28873efa2e6b`, **28/28**;
- packaged source archive SHA-256 `9bb73290f341101f5b7009df52ff085ec256ac9702a6da5765aa330a5118a81d`;
- routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Preflight verified provider/download digest equality, package manifest, exact source archive, executable modes, clean source receipts, GMP/GMPXX evidence, `runtimeExecution=false`, routing identity-map equality, selector430/first427 identity, and exact owner census. No repair or mutation was performed.

## 2. Runtime and complete evidence contract

R13 run/job is `35814092644 / 107031820541`, event SHA `c673cc36abff860be35360d2e948ab6e2080cf05`. Workflow schema validation and runtime both conclude success; runtime-job success means orchestration completed, not semantic green.

Result/log artifacts are:

- result `10730508643`, ZIP SHA-256 `0c93f72b3a73752002567dd1a39e19a30ff5c5be352a15cb6e4318f519ab6c01`;
- log `10731102663`, ZIP SHA-256 `aeddb30487479d8324f3ef6797ea068061dc8da000b56d494c7149110025c777`.

The result contains exactly **914 actual non-manifest evidence files** and **914 manifest rows**; every row verifies. Result `SHA256SUMS` SHA-256 is `29cebe48a81c4bd243dc3949f9caf11baed6d991c3e96a34078bd8729bc440a7`. Driver authority records template SHA-256 `0e9b4626be4abc9a21cbd928d7c9dced54075b2de65ea311fa17b0c92c7b0002`, writer SHA-256 `d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, and rendered-driver SHA-256 `b83ecad3f6749f2e532ae5ecd34dbcb71fdb85453f45934eb17b6fa500ee07cb`.

Execution boundary: `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`; benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters are all **0**.

## 3. Fresh 447-process semantic ledger

All **447/447** planned processes executed freshly. Every process selected exactly one test and skipped zero tests.

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| CB15 semantic-orientation identity + nine mechanism identities | 10 | 0 | 10 |
| focused atlas identity | 1 | 0 | 1 |
| produced identities | 4 | 2 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **445** | **2** | **447** |

Benchmark count is **0**. Protected selector ordinals **191, 192, 247 and 408 all PASS**.

### 3.1 CB15 ordinary-torus recovery is runtime-observed

`M5CP3.StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse` PASSes as the first process. Produced rows **1/2/3/6** all recover from R12 `InvalidFinalCellState` to PASS, and selector ordinal **408** recovers from R12 RED to PASS. This runtime evidence supports CB15's deterministic storage-canonical-to-semantic Forward -> Reverse conversion and removes the R12 ordinary-torus failure front from the candidate.

EXEC does not promote the candidate or close the R12 candidate/observation; mandatory Review owns those dispositions.

### 3.2 Nonzero-Z4 rows localize to the first branch predicate

Produced rows **4/5** are the only RED identities. Both fail while constructing the nonzero-Z4 source witness with the new typed reason:

```text
PeriodicActionFirstBranchMismatch
```

This satisfies CB15's diagnostic-authority requirement: the old generic `PeriodicActionCorrespondenceMismatch` collapse is gone and the first false predicate is now observable. Row4 still does not reach relation materialization, selected-certificate consumption, `consumedPeriodicHolonomies > 0`, or the independent direction comparator. Row5 still does not reach its transform-only tamper or typed `NonReciprocalPeriodicRelation` assertion.

This is bounded evidence for mandatory Review, not an EXEC root-cause verdict. `M5-CP3-TB1-R11-R1-CAND-01` remains open pending review of why the relation-owned endpoint state's first branch correspondence disagrees on the real produced witness.

## 4. Accounting and observations

Stable accounting remains **50 events / 14 categories / 36 recurrences** and produced-witness debt remains **3**. Candidate `10730261023 / 4dfe392d28d60b448e2f32253f7d170221ac57ec` remains unpromoted.

`M5-CP3-TB1-R6-REV-OBS-01` remains **OPEN** because row4 still stops before the independently-derived Forward -> Reverse comparator and inverted-pair rejection. `M5-CP2-TB1-REV-OBS-01` now has fresh selector430 **430/430** evidence, including ordinal408 PASS, but EXEC does not close observations or authorize publication; mandatory Review owns that disposition.

The two nonzero-Z4 M5 debts remain open. No debt discharge or selector publication is authorized in EXEC.

## 5. Immutable postflight

Postflight is exact:

- candidate package byte/mode census unchanged;
- packaged-source census unchanged;
- execution-view census unchanged;
- candidate manifest still **28/28**;
- selector430 and first427 unchanged;
- routing identity map unchanged;
- all prohibited-operation counters remain **0**.

No rebuild, configure, relink, generated discovery, source/test/fixture/selector mutation, package mutation, permission repair, retry, or evidence stitching occurred.

## 6. Authority and successor

Accepted runtime authority remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. R13 candidate remains unpromoted and no debt/observation is closed in EXEC.

The mandatory runtime-free successor is **`M5-CP3-TB1-R13-REV`**. Review must independently reopen R13 evidence, adjudicate CB15 recovery of the R12 storage/semantic-direction defect, localize `PeriodicActionFirstBranchMismatch` without guessing, decide stable accounting/observation disposition, and issue exactly one bounded successor.

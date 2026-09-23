# M5-CP3-TB1-R14 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R14-EXEC`
**Boundary:** immutable artifact-only Test + Benchmark on CB16 candidate `10733058003 / 6bad9eb5626e77a234ffb2c14f621195105e4ba1`
**Disposition:** **MECHANICALLY COMPLETE / SEMANTIC RED / 446 PASS + 2 RED / REVIEW REQUIRED**
**Exact successor:** `M5-CP3-TB1-R14-REV`

## 1. Immutable authority

R14 consumed only the compile-green CB16 candidate and frozen routing/selector authority:

- semantic source `6bad9eb5626e77a234ffb2c14f621195105e4ba1`;
- compile run/job `35820794471 / 107052021973`;
- candidate result artifact `10733058003`, ZIP SHA-256 `96e313e822bea8ebc6b7478c75c99d4c9245c7d88913b0d14d449a0ec73013f0`;
- compile log artifact `10732709067`, ZIP SHA-256 `3cfde85027f85bbb21f22c87918bbb911879f17bdc03014618c819a04343eeaa`;
- root package manifest SHA-256 `f77684128606428a82fe236b749b2d8357948e610745db55f98775a6b4217629`, **28/28**;
- packaged source archive SHA-256 `45bb6ccaba68772e998ebd41d75334041b54e5eadb36e4f3c0cd68b46b9b988b`;
- routing artifact `10592987234`, ZIP SHA-256 `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`;
- routing identity-map SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- first427 SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Preflight verified provider/download digest equality for candidate and compile-log artifacts, root manifest **28/28**, exact source archive, archived executable modes, clean source receipts, GMP/GMPXX link evidence, `runtimeExecution=false`, routing identity-map equality, selector430/first427 identity, and exact owner census. Ordinary archive extraction preserved mode bits; no permission or package repair occurred.

## 2. Runtime and complete evidence contract

R14 run/job is `35824161895 / 107062198724`, event SHA `27f7f3f5e0b50717f8e7407f72e3bf2c6e584e77`. Workflow schema validation and runtime both conclude success; runtime-job success means orchestration completed, not semantic green.

Result/log artifacts are:

- result `10734153401`, ZIP SHA-256 `ba6ab62396ff572aabb6850643e2d460cbfa0b5b196813bb3b8a91e6a31e3088`;
- log `10734178551`, ZIP SHA-256 `2e32386ee9e9ad67391f31227d2ddac1504f67f321e94c6296e62cb055b29b7f`.

The result contains exactly **916 actual non-manifest evidence files** and **916 manifest rows**; every row verifies. Result `SHA256SUMS` SHA-256 is `db2ccb2a5e1821018a71032ca9bdcf34e5c0a97fee6ae384d3710656320fd5ce`. Driver authority records template SHA-256 `c88cea8d0b806fecc938c5fce61fd7811ca89f5f089dfbed7922b8ea42708c23`, writer SHA-256 `d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, and rendered-driver SHA-256 `f82f0abb9cf9d1da0c35a2f9c84803548dc02f2f92e2d73d3bfc555bcaf5b3b9`.

Execution boundary: `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`; benchmark/configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation counters are all **0**.

## 3. Fresh 448-process semantic ledger

All **448/448** planned processes executed freshly. Every process selected exactly one test and skipped zero tests.

| Phase | PASS | RED | Total |
|---|---:|---:|---:|
| CB16 branch-authority identity + CB15 semantic-orientation identity + nine mechanism identities | 11 | 0 | 11 |
| focused atlas identity | 1 | 0 | 1 |
| produced identities | 4 | 2 | 6 |
| selector430 | 430 | 0 | 430 |
| **total** | **446** | **2** | **448** |

Benchmark count is **0**. Protected selector ordinals **191, 192, 247 and 408 all PASS**.

### 3.1 CB16 focused branch authority passes

`M5CP3.PeriodicRelationEndpointBranchUsesAcceptedOccurrenceAuthority` PASSes as process 1. The CB15 semantic-orientation identity also remains PASS. Produced rows **1/2/3/6** remain PASS and selector430 remains **430/430**.

This is direct runtime evidence that the focused CB16 authority contract itself is executable and green. EXEC does not infer from this focused PASS that the produced nonzero-Z4 seam is correct; the production rows below are the binding falsifier for that claim.

### 3.2 Produced rows4/5 remain at the same first-branch mismatch

Produced rows **4/5** are the only RED identities. Both fail while constructing the genuine nonzero-Z4 source witness with the unchanged typed reason:

```text
PeriodicActionFirstBranchMismatch
```

Row4 therefore still does not reach relation materialization, selected-certificate consumption, the independent Forward -> Reverse direction comparator, or inverted-pair rejection. Row5 still does not reach its transform-only tamper or typed `NonReciprocalPeriodicRelation` assertion.

The frozen R13 convergence condition is now observed: **rows4 and row5 are not both green after CB16**. Per the R14 plan, mandatory Review must therefore route the next semantic turn to a same-region nonzero-Z4 **gauge-definition reconciliation**, not to `CB17`. EXEC does not diagnose why the focused branch-authority identity passes while the real produced witness still fails, and it does not author or adjudicate that definition turn.

## 4. Regression accounting and observations

`M5-CP3-TB1-R14-CAND-01` is recorded as **OPEN / FAILED CB16 RECOVERY / EXISTING `RP-01` ENDPOINT-GAUGE CHAIN / NON-STABLE / REVIEW REQUIRED / +0**. There is no accepted-selector regression: selector430 is **430/430**, so stable accounting remains **51 events / 14 categories / 37 recurrences**. Produced-witness debt remains **3**.

`M5-CP3-TB1-R13-REV-OBS-01` has met its runtime trigger condition but remains Review-owned for formal disposition and successor freezing. `M5-CP3-TB1-R6-REV-OBS-01` remains OPEN because row4 never reaches the independent direction comparator/inverted-pair rejection. `M5-CP2-TB1-REV-OBS-01` remains OPEN because the corrected CP3 gate is still semantic RED despite selector430 **430/430**. Both nonzero-Z4 M5 debts remain open.

Candidate `10733058003 / 6bad9eb5626e77a234ffb2c14f621195105e4ba1` remains unpromoted. Accepted runtime authority remains `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. EXEC grants no promotion, debt credit, observation closure, selector publication, or post-Review definition authority.

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

R14 is mechanically complete semantic RED at **446/448 PASS** with complete **916/916** evidence. The candidate remains unpromoted and accepted runtime authority remains unchanged.

The mandatory runtime-free successor is **`M5-CP3-TB1-R14-REV`**. Review must independently reopen the R14 evidence, adjudicate the failed CB16 recovery without inferring from the reason name alone, apply the already-fired convergence rule, decide regression/observation/debt disposition, and freeze exactly one definition-reconciliation successor consistent with the R13/R14 contract.

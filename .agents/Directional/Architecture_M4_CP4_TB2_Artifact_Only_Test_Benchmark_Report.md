# M4-CP4-TB2-EXEC — artifact-only execution report

**Turn:** `M4-CP4-TB2-EXEC`
**Result:** **COMPLETE / ORCHESTRATION INVALID / NO SEMANTIC LEDGER**
**Immutable inputs:** CB4 artifact `10578784752` / source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`; CB5 delta artifact `10582435470` / source `4e9ff5003c8dd165dd614c25dd95f0308403719b`
**Accepted authority remains:** package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 `427/427`

## 1. Immutable preflight was valid

Before generated runtime, the turn independently verified the exact frozen composite inputs:

- CB4 provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`, package manifest **28/28**, packaged-source archive SHA-256 `dd7dd3351ad3ea10f56ef9ce2021fc8ea84e10d682560b93f70ca1d79b089175`;
- CB5 provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`, package manifest **24/24**, manifest SHA-256 `f5239fa4cb8fb31551599d6f836ca16e44ab203056dc262eb5c26141ed62d270`, packaged-source archive SHA-256 `b904ba5fec938d74d432501396f94de0c015072de6d9009c6213e6d547c19c81`;
- all source-status receipts are empty, both packages declare `runtimeExecution=false` and `exactArithmeticBackend=GMP`, and GMPXX+GMP linkage is present;
- selector427 is exactly **427 LF rows / 34,783 bytes / mode 0644 / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`**;
- independent static source-to-target mapping resolves every selector identity exactly once with owner census **30 authority-kernel / 281 producer / 75 completion / 41 validation**;
- the composite execution view uses hard-linked producer/validation binaries from CB4 and authority-kernel/completion binaries from CB5, all mode `0755`, with immutable packaged-source fixtures materialized at sibling `test-data/benchmarks/fixtures`;
- CB4, CB5, and execution-view fixture censuses are identical.

No configure, compile, relink, generated discovery/list/help/version, chmod/permission repair, package repair, fixture mutation, selector mutation, or benchmark command occurred.

## 2. First execution attempt is orchestration-invalid

The complete frozen gate was launched through a foreground container-tool invocation that imposed an external **300-second tool timeout**. That is incompatible with `GitHub_Workflow_Policy.md`'s full-suite rule requiring the complete acceptance gate to run uninterrupted to an organic process result without a repository/job/watchdog elapsed-time cutoff.

The external tool timeout terminated the run after **118 completed processes**: all four focus rows plus selector ordinals 1–114 had returned. Selector ordinal 115 was in flight. Because the complete 431-process gate and mandatory postflight did not organically complete, **none of those observations has semantic credit**. They are audit-only provenance.

The package trees, both packaged-source trees, and the composite execution view were independently re-censused after interruption and were byte+mode identical to preflight; both package manifests re-verified. The immutable packages therefore remain reusable unchanged.

## 3. Same-turn restart is also quarantined

A second local execution was started after the first orchestration failure. `Turn_Cadence.md` was then re-opened and its binding edge was re-applied: **TB orchestration failure routes to a runtime-free orchestration-correction CB, not to a same-turn retry**. The second attempt was immediately terminated and quarantined with **zero semantic credit**.

At termination it had **146 completed processes** (all four focus rows plus selector ordinals 1–142). Its package/source/view postflight is also exact and both manifests re-verify. Audit-only observations from either invalid attempt, including focused PASS/RED output, must not be used to close or reopen any semantic candidate.

The preserved invalid-attempt evidence archive is SHA-256 `b99b177a328ef8add9754622d8390693355da835a240fa8b4ddd1514d1bb3300`.

## 4. Classification and accounting

`M4-CP4-TB2-EXEC-CAND-01` is **OPEN / ORCHESTRATION / NON-STABLE**. Root cause is the execution control plane: the full frozen gate was hosted inside a tool call with a finite external execution deadline. The semantic packages, selector, owner map, fixtures, and composite view are not implicated.

Because this turn is orchestration-invalid, it produces **no semantic ledger** and no candidate runtime adjudication:

- `M4-CP4-TB1-R3-CAND-01` remains **CORRECTED IN CB5 / RUNTIME RE-PROOF PENDING / NON-STABLE**;
- `M4-CP4-TB1-R3-CAND-03` remains **CORRECTED IN CB5 / RUNTIME RE-PROOF PENDING / NON-STABLE**;
- the M4-owned produced closed-complex `G4-B002` debt remains open;
- the two periodic `G4-B002` debts remain M5-owned and unchanged;
- stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**;
- accepted M4 runtime authority remains package `10565723112` / selector427 **427/427**.

## 5. Required correction and successor

Per `Turn_Cadence.md`, exact successor is runtime-free control-plane-only **`M4-CP4-CB6`** under `Architecture_M4_CP4_CB6_Orchestration_Correction_Plan.md`.

CB6 must preserve both immutable packages and the frozen TB2 semantic gate byte-for-byte, move execution to a control plane that does not impose a repository/job/tool full-suite timeout, statically prove the corrected harness/caller, and execute **no Directional runtime**. Its successful successor is a fresh from-scratch `M4-CP4-TB2-R1-EXEC`; the invalid TB2 attempts contribute no process rows to R1.

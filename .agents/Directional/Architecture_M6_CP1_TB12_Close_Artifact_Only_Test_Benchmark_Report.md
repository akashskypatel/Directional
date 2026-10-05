# `M6-CP1-TB12-CLOSE-EXEC` — Artifact-Only Test + Benchmark Report

## Disposition

**COMPLETE MECHANICAL EVIDENCE / 478/479 / ONE NON-STABLE REVIEW-OWNED CANDIDATE / CANDIDATE UNPROMOTED.**

- Candidate package/source: `11324028392 / 02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.
- Compile authority: `37259524323 / 111603703243`; package manifest **28/28**; GMP/GMPXX; `runtimeExecution=false`.
- Runtime run/job: `37266239234 / 111623615471` — terminal SUCCESS.
- Result/log artifacts: `11326949864 / 11328055226`, ZIP digests `sha256:da42bf2a115761a14f6313d2e650d0daa1bc560f3f942819c01d9944c08bc4e3 / sha256:70880747559e69359f0a10bf07f2297eb86dd431d6816ef9fc01d327d347d7e2`.
- Result self-manifest: **979/979**, SHA-256 `61499c93b109b16bc9e4120674e388fd32f1ce5cf01b110a56a4967dd6fe4e97`.
- Outcome: focused **29/30**, selector449 **449/449**, aggregate **478/479**; exact-one, zero skips, benchmark 0.
- Sole RED: focused ordinal29 `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition`.
- Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**. Candidate remains unpromoted.
- Exact successor: mandatory runtime-free `M6-CP1-TB12-CLOSE-REV`.

## 1. Immutable candidate and gate authority

Candidate provider/download SHA-256 matched `4e6b208acd328036d849a8d71f12804a6d9e6a34d804e3129953ce7a7e3afba1`; packaged `SHA256SUMS` remains **28/28** and source is exactly `02149f1518fc6a753acf3235f7dcdc6fcdf59f24`.

Frozen authorities remained byte-identical: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d` as exact prefix; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Frozen harness SHA-256 was `611b874379f02be99b27e28cc5beb8522d2b73bee55a2cc1cd9960304d811723`.

## 2. Exact runtime result

Exactly **479** fresh exact-filter processes executed in frozen order. Every process selected exactly one test; skips are zero. Focused **29 PASS / 1 RED**, selector **449 PASS / 0 RED**, aggregate **478 PASS / 1 RED**.

Ledger SHA-256: focused `602ed88271fee42d490abef6fe79e96c269bb662517c8368cf774adf3bf9e321`; selector `7185cff57c058cec8b139e0f9329e220d96b639cafbd349eb23d4a0e6f9f3be9`; RED `71a547b5506e2a8a50822e75691973462892146f2cbd0dc053ce492166ab8690`. Sole RED raw log SHA-256 is `3f03a96cf7b5322846a4286afd5fe1b4aaaa9413f9283d66f066fb93949c4166`.

## 3. `M6-CP1-TB12-CLOSE-EXEC-CAND-01` — non-stable witness non-vacuity failure

Ordinal29 fails before its transition-disconnection tamper: `ASSERT_NE(crossSheetEdge, nullptr)`. Baseline A7 materialization succeeds, but `a6->selected_forest()` contains no selected relation whose endpoint `cornerWedgeSheets` sets are disjoint. Therefore the test exits before rewriting any isolation transition and does **not** exercise the intended C1 falsifier.

EXEC can prove missing witness non-vacuity, but cannot safely distinguish fixture/oracle authority from production-selection behavior that Review may decide is defective. Because identity29 is new gate authority and no previously accepted-green row became RED, stable-history criteria are not met.

Disposition: **ACTIVE / NON-STABLE / REVIEW-OWNED / witness non-vacuity not established**; **+0 events / +0 categories / +0 recurrences / +0 debt**. Identity30, focused1-28 and selector449 are green.

## 4. Immutability and orchestration boundary

Postflight proves package/source/execution-view censuses equal; focused30/focused28/selector449/routing449 unchanged; package manifest **28/28**. Runtime boundary records runtime complete, orchestration failure false, selection integrity true, 479 executions, and no configure/compile/relink/discovery/benchmark/repair/mutation or retry after runtime start.

Earlier run `37264751953` was invalid-workflow/startup failure with zero jobs because an unquoted colon made the temporary caller YAML invalid. It started no Directional runtime. The caller was corrected at `f521d9c1fca8b8754f051171167edba665e628ad`, schema-validated, then retry trigger `5301f51a3aae3a1286c6c8fb6fb9f24690c35a20` produced the sole semantic runtime.

## 5. Successor

EXEC grants no promotion and does not close CP1. Reviewed runtime remains `11316716869 / 8dd958217d8cbda2d403f7a5c4c7dce242dde1c0` at 477/477. Exact successor is runtime-free **`M6-CP1-TB12-CLOSE-REV`**, which must independently re-derive the evidence and adjudicate CAND-01 before any recovery or promotion routing toward `M6-CP1-CLOSE-REV`.

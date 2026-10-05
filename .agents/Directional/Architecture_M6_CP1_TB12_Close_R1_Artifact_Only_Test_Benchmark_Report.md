# `M6-CP1-TB12-CLOSE-R1-EXEC` — Artifact-Only Test + Benchmark Report

## Disposition

**COMPLETE MECHANICAL EVIDENCE / 479/479 GREEN / +0 NEW REGRESSIONS / CANDIDATE UNPROMOTED.**

- Candidate package/source: `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`.
- Compile authority: run/job `37278068286 / 111659540374`; package manifest **28/28**; GMP/GMPXX; `runtimeExecution=false`.
- Runtime run/job: `37280517630 / 111667316992` — terminal SUCCESS.
- Result/log artifacts: `11333591947 / 11333547162`.
- Result/log provider ZIP SHA-256: `ef5dba1131f25025bc536ba160475191629cc8bffed0465a087dd72fc4d1474b / dd78296134b6e71d2080ab2b1b6623841f75725e6a43deffe6ec2ad50dd46e53`.
- Result self-manifest: **497/497 PASS**, SHA-256 `9d7f244f4996d06db10db756c3bf25e1495d9628b9bb3e92af8cfeb089a4bd67`.
- Outcome: focused **30/30**, selector449 **449/449**, aggregate **479/479 PASS**; exact-one, zero skips, benchmark 0.
- Stable accounting remains **60 events / 16 categories / 44 recurrences**, debt **1**. No R1 regression candidate/event was created.
- Candidate remains unpromoted. Exact successor: mandatory runtime-free `M6-CP1-TB12-CLOSE-R1-REV`.

## 1. Immutable candidate and gate authority

The runtime downloaded immutable artifact `11330703256` once and verified its ZIP SHA-256 as `0c50b034e80595514f4891d964360151339a31fe5d870aa83eade85587721524`, packaged `SHA256SUMS` **28/28**, source `3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`, package-manifest SHA-256 `cb17574a31fe6afcbf56325022f452fd649fad4b58d0996727cada9fe92b199b`, source-archive SHA-256 `80d5a02e2394f00051e6c537715df9efbe8d0aaf8acc69bb68ca11bb8026deca`, clean source receipts, `runtimeExecution=false`, and GMP/GMPXX evidence.

Frozen authorities remained byte-identical: focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`; focused28 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d` as the exact focused30 prefix; selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## 2. Exact runtime result

Exactly **479** fresh exact-filter processes executed in frozen order: **30** focused and **449** selector processes. Every ledger row selected exactly one test, skipped zero tests, and passed exactly one test.

- focused ledger: 30 rows, 30 PASS, SHA-256 `296bc32f9ed1fc017c1ae7c5e48c67056a962a9c8f376333f1ca400bfde61e0a`;
- selector ledger: 449 rows, 449 PASS, SHA-256 `d5298b2aaaf55c1a458b1ec6e79954cbddc17dbf33be7baf0998f397d4a2908f`;
- RED ledger: header only / zero RED rows, SHA-256 `dc5496d37ad6939dc28d5b6c2b2eb9a670066d4a6cf3268c443fef6ffb27ecf7`.

Recovery-sensitive focused identity29 `M6CP1.A7CrossSheetBindingRequiresConnectingIsolationTransition` is GREEN under the RA-27a consistent-chain witness, and identity30 remains GREEN. Selector449 is unchanged and fully GREEN.

## 3. Immutability and orchestration boundary

Postflight records package census equal, execution-view census equal, focused30/focused28/selector449/routing449 unchanged, and package manifest still **28/28**. The execution boundary records runtime complete, orchestration failure false, selection integrity true, benchmark/configure/compile/relink/discovery false, no package or mode repair, no source/test/fixture/selector mutation, and no retry after runtime start.

The runtime ran uninterrupted to organic completion. No generated test result was retried or repaired.

## 4. Regression disposition and successor

The complete gate observed **zero RED processes**. Therefore there is no R1 regression to categorize and no candidate/non-stable tracker entry to create. Stable accounting remains **60 / 16 / 44**, debt **1**.

EXEC grants no promotion and does not close CP1. Candidate `11330703256 / 3f40f04a...` remains unpromoted until mandatory runtime-free **`M6-CP1-TB12-CLOSE-R1-REV`** independently verifies the evidence and adjudicates promotion/recovery. Only after that Review may routing proceed toward `M6-CP1-CLOSE-REV`.

## 5. Process note

This continuation resumed with direct reads of three repository documents before the mandatory start-of-turn `READ_MODE` gate was re-established. That was a tool-conservation process miss. No semantic conclusion depended on those reads: the current durable-document blobs were independently matched to the retained local exact copies before closeout work, and runtime evidence came from the immutable workflow artifacts. No stable regression/accounting effect follows from this process observation.

# M6-CP2-TB1-VERIFIER-R2-EXEC — Artifact-Only Test + Benchmark Report

**Disposition:** COMPLETE / MECHANICALLY GREEN / **491/491** / CANDIDATE UNPROMOTED / MANDATORY REVIEW NEXT.

This turn consumed immutable package `11385836615` / semantic source `c64baacd6c767c4ba053b6963651c0aa6eceed20` without rebuild, relink, configure, generated discovery, package or mode repair, source/test/fixture/selector mutation, or retry after runtime start. The frozen gate was exactly focused30 + CP2-focused12 + selector449 = **491 fresh exact-filter processes**. Semantic promotion remains Review-owned.

## Immutable candidate authority

- compile/result artifact: `11385836615`;
- semantic source: `c64baacd6c767c4ba053b6963651c0aa6eceed20`;
- candidate ZIP SHA-256: `40ea2966011865090ce49382300885ee132e82655fba4f98575f326b53ca2ea4`;
- candidate root `SHA256SUMS` SHA-256: `ccf16684d4184f7c18a3d10d0383ca3058869de6ab3a2c77292fcaf02bcadda8`;
- source archive SHA-256: `fb7f08f193aa335944c5a3ff460ef481ec9f1dec6cefba676a563d374305bce9`;
- package root manifest: **28/28** before runtime;
- exact arithmetic: GMP/GMPXX;
- entering Code + Build boundary: `runtimeExecution=false`.

Frozen gate authority remained byte-identical:
- focused30: 30 rows, `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`;
- CP2-focused12: 12 rows, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`;
- selector449: 449 rows, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: 449 rows, `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Runtime authority and immutable evidence

Workflow run `37403703032`, trigger SHA `c72618821a5ce0ab676c46abcc078ba3ed0908b2`:
- schema validation job `112076410067`: SUCCESS;
- runtime job `112076464024`: SUCCESS;
- mailbox job `112085191472`: SUCCESS;
- authoritative mailbox: `.workflow-mailbox/m6-cp2-tb1-verifier-r2-exec/latest.json`;
- result artifact `11387562709`, provider/downloaded ZIP SHA-256 `dada6a755d4ec6d695ab2b11b13c6d92452d4b1599e9ebda0e6bee751b23fdcf`;
- execution-log artifact `11387233341`, provider/downloaded ZIP SHA-256 `5a6950535ec39f20e776759b0c0f1d241ee5228c346ea4d2afc3fe9fcf0b3c39`;
- result self-manifest: **1005/1005** verified, SHA-256 `82943861e169fcdc8589bf13f0e068a663b837997792c454d7a6efb6b5788d7f`.

The harness began runtime at `2026-10-06T02:21:30Z` and completed organically at `2026-10-06T02:55:34Z`. No repository timeout, cancellation, partitioning, or runtime retry was used.

## Mechanical gate

- focused30: **30/30 PASS**;
- CP2-focused12: **12/12 PASS**;
- selector449: **449/449 PASS**;
- aggregate: **491/491 PASS**;
- exact-one selection: **491/491**;
- skips: **0**;
- benchmark executions: **0**;
- RED ledger: header only / **0 RED**.

Ledger SHA-256 values:
- focused30: `3a64a730be3c982c663c567b423217e178b484702faa6f8a2410a469a45ea556`;
- focused12: `fdc604b1db6e52830433eddcde312f3100f31e387ecf65fa51db43db6c655677`;
- selector449: `8574b0f86a31d29d8d9bce0cff7f93e48ea1b6dbe6a8d7b4973580fe6206167c`;
- combined 491-row ledger: `e1c274db99560863b7b8dc35800547449edb106292fbe54fc3c2e921caca367f`;
- empty RED ledger: `dc5496d37ad6939dc28d5b6c2b2eb9a670066d4a6cf3268c443fef6ffb27ecf7`.

Execution boundary is fully clean: `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `orchestration_failure=false`, `selection_integrity=true`; configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector-mutation/retry-after-runtime-start are all false.

Postflight proves `package_census_equal=true`, `source_census_equal=true`, `execution_view_census_equal=true`, all four gate files unchanged, and candidate manifest **28/28** again after runtime.

## Regression/accounting classification

No RED row or orchestration defect occurred. This EXEC therefore adds **+0** regression events, **+0** categories, and **+0** recurrences. Stable accounting remains **60 events / 16 categories / 44 recurrences**, architecture debt **1**.

Mechanically, R2 recovered every prior R1 RED surface, including the RA-29c three-hop binding and removal of the invalid component-adjacency rule. That observation is evidence for Review, not an EXEC promotion decision. The candidate remains unpromoted until independent `M6-CP2-TB1-VERIFIER-R2-REV` adjudicates the recovery and prior review observations.

## Boundary and mandatory successor

Candidate package `11385836615 / c64baacd6c767c4ba053b6963651c0aa6eceed20` remains **unpromoted**. Previously reviewed runtime authority remains `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05` (479/479) until Review explicitly promotes a successor.

The exact next turn is mandatory independent `M6-CP2-TB1-VERIFIER-R2-REV`. It must independently re-derive the 491/491 result and immutable evidence, adjudicate RA-29c/R3 recovery against the R1 findings and frozen contract, decide candidate promotion/rejection, and freeze subsequent routing. EXEC authorizes no source/test repair, no duplicate runtime, and no direct advance to `M6-DEFN-R5`.

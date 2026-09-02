# M3-CP4c-3-TB14 Artifact-Only Test + Benchmark Report

Date: 2026-09-02 UTC
Turn: `M3-CP4c-3-TB14`
Status: **TURN TERMINATED / ORCHESTRATION INVALID / SELECTOR INCOMPLETE / NO SEMANTIC DISPOSITION**

## Immutable authority and execution boundary

TB14 consumed immutable package **84** only. Semantic/package source is
`6808c090f2dd229a48550d758f459bfd156da4b6`; package artifact `9867334959` has Actions SHA-256
`67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`, inner `package84.tar.gz` SHA-256
`8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`, and packaged source tar SHA-256
`ca898abdf3e5a4d01429048f13a2a6f09dd6bc70dabd3b866209533f9e43db95`.

Selector **380** verified at `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e` with 380 unique
identities; selector 379 is its exact first-379 prefix at
`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`, and the first 365 identities reproduce
accepted authority `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

Preflight verified the internal `SHA256SUMS`, exact source commit, `runtimeExecution=false`, `packageRepair=false`,
`exactArithmeticBackend=GMP`, GMPXX/GMP link evidence, all 27 package-relative fixtures, all six executable modes,
and the append-only selector lineage through 380. The 58-file byte/mode census SHA-256 is
`95ba3950267a1e145be427b2e1c896204aef7d86bd079d039a63bc0834e8a3e2`.

Boundary flags: `runtimeExecution=true`; `configureExecution=false`; `compileExecution=false`;
`relinkExecution=false`; `packageRepair=false`; `generatedDiscovery=false`; product/test/fixture/selector mutation
all false; `benchmarkExecution=false`.

## Orchestration failure

TB14 did **not** reach a valid selector result. The local execution host terminated two fresh-process invocations
because the surrounding tool call exceeded its wall-clock allowance; neither binary produced an organic process
result:

1. ordinals **1-129** completed organically and all PASSed. Ordinal **130**
   `SurfaceCellAuthorityContractCutover.FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority`
   started and reached GoogleTest `[ RUN ]`, but the host terminated the enclosing call before `[ OK ]`, a final
   GoogleTest summary, or an exit status could be recorded. Its partial log SHA-256 is
   `cb179f3e3a6c3a519122f49f01aeb5382a7e0c54d748cb550cfc229ed4488846`.
2. TB14 then resumed **without rerunning ordinal 130**. Ordinals **131-136** completed organically and all PASSed.
   Ordinal **137**
   `SurfaceCellAuthorityContractCutover.FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority`
   likewise reached `[ RUN ]` but no organic result before the host terminated the call. Its partial log SHA-256 is
   `8498d801cb2c7fc226287274c8b7ac1baf4cf268409d2d8f08c00bc6c9bc5dbc`.

The retained raw orchestration-evidence archive has SHA-256 `66e2b7c204be16dec6e95317c273b0654fb15bac8f468e1dbe1493e65c25107e` and contains the completed ledger, per-ordinal logs, identity map, run metadata, and pre/postflight census.

The completed-result ledger contains **135 organic PASS / 0 semantic RED** observations for ordinals
`1-129,131-136`; SHA-256
`61e616cd54b6289ade99b53d111398df857f395ec633658f2bddd502ac933952`. These are retained observations, but they
cannot establish the selector gate because ordinal 130 is inside the accepted 1-365 prefix and has no organic
result. After the second interrupted process, execution stopped rather than risk another partial identity or an
unauthorized retry.

This is an **orchestration/infrastructure failure, not a semantic red**. No product, test, fixture, selector, or
package defect is inferred from either interrupted process. The frozen TB14 rule permits a rerun only for an
orchestration failure that executed no creditable semantic identity; this attempt already contains completed
semantic identities and two identities that began execution without an organic result. TB14 therefore does not
self-authorize a restart, retry of 130/137, or continuation past 137.

## BL9 discriminator disposition

1. **NOT MEASURED — accepted boundary.** TB14 observed PASS through 129 and again at 131-136, but ordinal 130 has no
   organic result and ordinals 138-365 were never attempted. The prior accepted authority remains **365/365** from
   TB13; TB14 neither re-proves nor falsifies it.
2. **NOT REACHED — vertex-10 correction.** Ordinal 366 was not attempted.
3. **NOT REACHED — reason separation.** No production secondary-parameter red was reached.
4. **NOT REACHED — BK7/v47 conjunction.** No v47 production census was reached; both inherited candidates remain
   open.
5. **NOT SATISFIED — candidate closure.** None of the four runtime-open CB15/CB16 candidates closes from TB14.
6. **NOT REACHED — downstream face-walk evidence.** No new `nonDiscComponentCount` or
   `remainingAdmissibleEdgeCount` evidence exists.

Selector-380 witness ordinal **380** and the separate non-gating
`GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` diagnostic were **not attempted**. No benchmark
was executed.

## Regression/candidate categorization

New non-stable infrastructure candidate **`M3-CP4c3-TB14-ORCH-01`** records the execution-host interruption. It is
not a product regression and changes stable accounting by **+0 events / +0 recurrences**. The existing product
candidates remain exactly where CB16 left them:

- `M3-CP4c3-TB13-REV-CAND-01` — build corrected, runtime confirmation still absent;
- `M3-CP4c3-TB13-CAND-01` — build corrected, runtime confirmation still absent;
- `M3-CP4c3-TB12-REV-CAND-01` — partially runtime discriminated, v47 conjunction still absent;
- `M3-CP4c3-TB11-CAND-01` — active, full v47 conjunction still absent.

No carried 368/369/370/371/372/374 surface was reached in this attempt, so none acquires new evidence or changes
owner. There remains no vertex-30 discriminator.

## Immutable postflight

After execution stopped, the complete 58-file package-tree byte/mode census is exactly identical to preflight,
SHA-256 `95ba3950267a1e145be427b2e1c896204aef7d86bd079d039a63bc0834e8a3e2`, and the internal `SHA256SUMS` manifest
re-verifies. No package repair, rebuild, relink, configure, generated discovery, source/test/fixture/selector
mutation, or benchmark occurred.

## Phase status and exact successor

TB14 is **terminated but not semantically complete**. It is neither green nor a valid semantic red, so it does not
advance or reduce accepted authority. The latest valid runtime authority remains **TB13 / package 83 / selector
379** at accepted **365/365** and first red 366. CB16/package84 remains current build/package authority. Stable
accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; semantic M3
package count remains **81**.

The frozen plan cannot itself authorize a retry after this partial execution. Exact successor is therefore
**`M3-CP4c-3-TB14-REV` — independent REVIEW + PLAN only**, under
`Architecture_M3_CP4c3_TB14_Independent_Review_Plan.md`. That review must adjudicate recovery from the two
non-organic identity terminations without treating them as semantic failures or silently duplicating runtime. No
product correction, selector change, compile, package, or additional TB14 identity execution is authorized before
that review.

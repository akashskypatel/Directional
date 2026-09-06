# M3-CP4c-3-TB31-EXEC — artifact-only execution report

**Status:** EXEC COMPLETE / MECHANICALLY VALID / RAW EVIDENCE PRESERVED / SEMANTIC REVIEW REQUIRED.

This record closes only the runtime-execution half of the frozen TB31 plan. It does not promote the raw ledger to
semantic authority, adjudicate any candidate or regression, authorize a product correction, or change stable
regression accounting. The required successor is `M3-CP4c-3-TB31-REV`, which must review this immutable evidence
without new runtime work.

## Immutable execution authority

- immutable CB36 package: artifact **`9982174864`** / `m3-cp4c3-cb36-result-34010011172`;
- exact built source: **`90bf8430f54c8b81fb90a6bda820cf8edebce6e9`**;
- package/provider SHA-256: `8bbc10da2372730a4fd644250a420f0ba7e6dd73f59e93364b2b1ccacfbcf43b`;
- packaged source archive SHA-256: `f909864226b07a4cd89a9a51669792e8cdd63206c5b2a23d2e0b179476d78cae`;
- selector: **408** identities, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- authoritative EXEC R2 workflow run/job: **`34011402843 / 101427791582`**;
- result artifact: **`9982618043`**, provider digest
  `sha256:d640ee7c7c65d992de996b9cfef81269b4833a97411ec136742828032b73fc57`;
- diagnostic log artifact: **`9982618174`**, provider digest
  `sha256:8c4cd61801e64f2f8d33856a2675542315165b561349640fcef3309e44337c06`;
- execution harness SHA-256: `1f4ed91cb8ac055632b574a6b08a4aa0fb45b9e07c125b9f08f30d7baaef47bb`.

The package's root `SHA256SUMS` verified every packaged file before runtime. Package, packaged-source, and stripped
execution-view byte/mode censuses are identical before and after execution. No package repair or mode repair ran.

## Execution contract and mechanical validity

All **408/408** selector identities executed exactly once, in ordinal order, one fresh process and disposable
execution view per identity. Every row selected exactly one test, accepted rows 1–365 all completed, and there were
zero timeouts. The artifact-only boundary reports:

- `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`;
- `selection_integrity=true`, `timeout_count=0`;
- `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`;
- `generated_discovery=false`, `package_repair=false`, `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`.

The immutable census hashes are:

- package before/after: `e4e77f38d8fc3d55bace4e15d54c8f5c746af4573c6cf4b15a0f1fa0f039875f`;
- packaged source before/after: `7445fd9ee61d0ee6ae64e2e6b5e0208ecaab5a5207f27234501c9d6ac292daff`;
- execution view before/after: `73b50fa753494504717a7ee64b5b40b0d95ce6aa325823d5ce5846bb7bb71e05`;
- runtime executable census: `83e99ae2ed52d7aac52f46f2994a3b100918053a316d007aad6bfd529a1b7d22`;
- identity map: `06c3a5a69078b4ce0dec23d29a9f96e10e0f6e94c42ea00675541c89a70d262a`;
- resource summary: `997f0af250856b7608f4dcdcb8854c88017d92562331b9fb440754ceaa87012e`.

`directional_benchmarks` remained census-only and was never executed.

## Raw selector result — review intake only

The harness mechanically emitted **397 PASS / 11 RED** with RED ordinals
`[366,367,368,369,370,374,390,393,398,406,407]`. Accepted rows **1–365 = 365/365 PASS**. Ledger SHA-256 is
`6632f428243788c98c816571f47ef0cf98df25a57274b2df75612674d563250b`.

Relative to the current accepted TB30 semantic authority, all seven TB30 RED ordinals remain mechanically RED and
four previously-PASS rows are newly RED in the raw TB31 ledger: **390, 393, 406, 407**. Rows 404 and 408 remain
mechanically PASS. This comparison is descriptive only; it is not regression classification or semantic promotion.

The frozen required-raw index contains 366,367,368,369,370,374,390,398,404,408. The unanticipated newly-RED rows
393, 406, and 407 are not in that pre-authored index, but their complete per-ordinal raw logs are present in the
result artifact with all other 408 raw logs. No rerun was performed.

## Frozen frontier observations retained for REV

The frozen TB31 falsifier requiring the old 366/367 fingerprint did **not** reproduce. Neither ordinal retains the
old `component 0 / 191 faces / Multiple seeds [0,1,3]` surface. Instead both terminate with typed detail
`TraceArcDoesNotSeparateItsSides`; the retained exception names `sourceFace=8,10,151` and `arc=15`. Its published
fragment-owner component 0 is now `faceCount=189`, `seedCount=1`, `seedState=Unique`, `seedOrbits=[0]`.

No `TraceCutFaceFragmentCountMismatch` appears in any TB31 per-ordinal raw log. Because 366/367 now terminate at the
earlier/different `TraceArcDoesNotSeparateItsSides` detail, the frozen plan-side face-set digest and
`censusCorrespondence` fields are not emitted on those rows. Their absence is preserved as evidence; EXEC does not
reinterpret it or infer candidate disposition.

The mechanically published certified-owner census remains:
`sourceFaceCount=300; established=300; unavailable=0; conflicting=0; conflictRowCount=0`.

The four newly-RED raw rows 390, 393, 406, and 407 all fail assertions that expected
`UncutFaceComponentOrbitSeedNotUnique` but received `TraceArcDoesNotSeparateItsSides`. TB31-REV must determine
whether these are test-authority consequences, product regressions, evidence-surface invalidations, or another
classification. EXEC makes none of those decisions.

Frontier diagnostic extract SHA-256 is
`f945904621fedfda43007d07ea85027ed389bed2943c7bb2fc33d8eeac412927`.

## Orchestration provenance

The first TB31 trigger never entered semantic runtime because the temporary caller's top-level permission ceiling
was narrower than the statically required union of the durable observer reusable workflow graph. The caller alone
was corrected from `contents: read` to `contents: write`; **no reusable-workflow permission was changed**. The R2
trigger then produced the authoritative run above. The pre-runtime R1 control-plane failure carries no semantic
ledger and is not a TB RED.

Start-of-turn control-plane deviation: source-snapshot orchestration began after the mandatory full
`TOOL_USE_CONSERVATION_POLICY.md` read but before the mandatory full project `GitHub_Workflow_Policy.md` read had
completed. The workflow policy was fully reviewed before semantic/runtime execution, Drive application, or any
package use. No source/package/runtime evidence was affected.

## Semantic authority and accounting

**TB31-EXEC does not change semantic authority.** Until TB31-REV adjudicates this evidence, the current accepted
runtime authority remains **TB30**: selector 408, **401 PASS / 7 RED**, accepted **365/365**, RED
`[366,367,368,369,370,374,398]`, certified ownership **300 / 0 / 0**.

`Regression_Root_Cause_Tracker.md` is intentionally not semantically edited in EXEC. Stable accounting therefore
remains **44 / 14 / 30**, produced-witness debt **5**, and semantic package count **96**. The separate TB31-REV is
responsible for classifying every raw RED/change and updating the tracker before any later product correction is
authorized.

## Exact successor

**`M3-CP4c-3-TB31-REV` — evidence-only semantic review.** It must consume immutable artifacts `9982618043` and
`9982618174`, perform no new runtime or compile, verify all 408 execution/provenance invariants, classify all eleven
raw RED ordinals including newly-RED 390/393/406/407, adjudicate the changed 366/367 frontier and the absence of the
frozen plan-side digest/correspondence evidence, update `Regression_Root_Cause_Tracker.md` and `ORIENTATION.md`,
perform mandatory REVIEW document consolidation, and freeze only the next step justified by that review.

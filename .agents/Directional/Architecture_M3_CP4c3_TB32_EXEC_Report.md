# M3-CP4c-3-TB32-EXEC — artifact-only execution report

**Status:** EXEC COMPLETE / MECHANICALLY VALID / RAW EVIDENCE PRESERVED / SEMANTIC REVIEW REQUIRED.

This record closes only the runtime-execution half of the frozen TB32 plan. It does not promote the raw ledger to
semantic authority, diagnose the remaining RED rows, change stable regression accounting, or authorize a product,
test, fixture, selector, build, or benchmark correction. The required successor is `M3-CP4c-3-TB32-REV`, which
must review this immutable evidence without new runtime or compilation.

## Immutable execution authority

- immutable CB37 package: artifact **`9983643195`** / `cb37-package-result-34014992328`;
- exact built source: **`7f63b5f41a0ca72f0b984ec4ee42d11f74775719`**;
- package/provider SHA-256: `75fcebb299c02b3a10525d935973a8cfca5bf119e3cfc4e54b5591f3cf8f699f`;
- packaged source archive SHA-256: `cae8e29946c5e9dfea1a49070e0d8721bc17fb53dba54bb6c66188347560d3fa`;
- selector: **408** identities, LF SHA-256
  `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- authoritative EXEC workflow run/job: **`34024893763 / 101464028080`**;
- trigger/control SHA: `a96fa4a9ce1140941ba9174e7a5224280a11c49e`;
- result artifact: **`9986786215`**, provider/download digest
  `sha256:be70cc9fa0531a3438d13a31425545b61f13336baa6f1bdbb0ca3526b0f8fd6f`;
- diagnostic log artifact: **`9986786399`**, provider/download digest
  `sha256:3fbcba8f76982590f9a79935844f20ff63b68bfe4446faa7ecd1a1e551a7e092`;
- deterministic TB32 harness SHA-256:
  `a7f76cfaf520a74537f72d5d86e0ced850fcc77357ef36e925a162cb5de8b699`.

The TB32 harness was materialized in runner temporary storage from the preserved TB31 harness blob
`cfea4a0e468fa84b17c31445f9b13115f5035547`, after verifying its frozen SHA-256
`1f4ed91cb8ac055632b574a6b08a4aa0fb45b9e07c125b9f08f30d7baaef47bb`, then applying only deterministic
orchestration updates for the CB37 package/source identities, TB32 labels, and the pre-authored focused raw-log
index. No packaged source, test, fixture, selector, binary, or build product was modified.

## Execution contract and mechanical validity

All **408/408** selector identities executed exactly once, in ordinal order, one fresh process and working directory
per identity. Every row selected exactly one test, accepted rows 1–365 all completed, and there were zero timeouts.
The artifact-only boundary reports:

- `runtime_started=true`, `runtime_completed=true`, `orchestration_failure=false`;
- `selection_integrity=true`, `timeout_count=0`;
- `benchmark_execution=false`, `configure_execution=false`, `compile_execution=false`, `relink_execution=false`;
- `generated_discovery=false`, `package_repair=false`, `mode_repair=false`;
- `source_test_fixture_selector_mutation=false`.

The package's root `SHA256SUMS` passed before runtime. Package, packaged-source, and execution-view byte/mode censuses
are exactly identical before and after execution. Their retained hashes are:

- package before/after: `b63b88df851c086a334e2920322150789a53d6ba7818e7c9c7a54fb8714f35bb`;
- packaged source before/after: `797c8935670ffcda3520db00ece1593795701513f52df2b05858e7c74b4b22c2`;
- execution view before/after: `0d4ed16ec944346a87ac9df6a619887b8a6c636b9829805446a5c662868f1985`;
- runtime executable census: `6160da56eaff579acebe36d0b820e5a7f916896d31b86457800680506bc80fc1`;
- identity map: `06c3a5a69078b4ce0dec23d29a9f96e10e0f6e94c42ea00675541c89a70d262a`;
- resource summary: `af0a199d24eb053a8e11e1db9dfd80d73b9d60605995bfd17b86f0eb0a7a38f2`.

`directional_benchmarks` remained census-only and was never executed.

## Raw selector result — review intake only

The harness mechanically emitted **397 PASS / 11 RED** with RED ordinals
`[366,367,368,369,370,374,390,393,398,406,407]`. Accepted rows **1–365 = 365/365 PASS**. Ledger SHA-256 is
`6632f428243788c98c816571f47ef0cf98df25a57274b2df75612674d563250b`; all 408 raw per-ordinal logs are retained.

The complete plan-required focused raw index contains **366, 367, 368, 369, 370, 374, 390, 393, 398, 406, 407**.
Mechanically observed row states are:

- 366 RED;
- 367 RED;
- 368/369/370/374/398 RED;
- 390/393/406/407 RED.

The four identities the frozen plan required to return green therefore remain raw RED. EXEC preserves that result
without classifying its cause or changing any owner/contract.

## Frozen R4 evidence retained for REV

A complete search of all 408 raw logs finds **zero** emissions of `TraceArcDoesNotSeparateItsSides` and **zero**
emissions of `UncutFaceComponentOrbitSeedNotUnique`. In particular, neither 366 nor 367 reproduces the prior
189-face / seedCount 1 / `[0]` seed stop. Both 366 and 367 mechanically terminate at typed detail
`RegionBoundaryNotSingleWalk`.

The retained fragment-owner evidence still includes component 0 with `faceCount=189`, `seedCount=1`,
`seedState=Unique`, and `seedOrbits=[0]`; EXEC does not infer semantic meaning from that publication. Certified
owner publication is independently retained in ordinal 385 as
`sourceFaceCount=300; established=300; unavailable=0; conflicting=0; conflictRowCount=0`.

The focused frontier extract SHA-256 is
`3195b227353f990a087185bc3bd5c15b7ae978328fab0d551e0e9b252ca3cae0`. Complete raw logs, not that extract, are
the authority for TB32-REV.

## Non-semantic orchestration-label note

`baseline-authority.txt` contains the text label `TB32 run=34011402843` because the deterministic harness
materialization renamed historical `TB31` orchestration labels globally. The numeric run `34011402843`, selector
result `397/11`, RED list, accepted prefix and ownership values are the carried TB31 semantic baseline; the current
TB32 EXEC run is independently and correctly recorded as `34024893763` throughout wrapper/environment evidence.
The raw artifact is preserved unchanged. This label-only defect is not one of the frozen TB32 orchestration-stop
conditions and does not alter package identity, selector execution, row results, raw logs, or byte/mode censuses.
TB32-REV must nevertheless account for it when checking provenance.

## Semantic authority and accounting

**TB32-EXEC does not change semantic authority.** Until TB32-REV adjudicates this evidence, the current semantic
runtime authority remains **TB31**: selector 408, **397 PASS / 11 RED**, accepted **365/365**, RED
`[366,367,368,369,370,374,390,393,398,406,407]`, certified ownership **300 / 0 / 0**.

`Regression_Root_Cause_Tracker.md` is intentionally not semantically edited in EXEC. Stable accounting therefore
remains **44 / 14 / 30**, produced-witness debt **5**, and reported semantic M3 package count **97**. TB32-REV owns
classification of every raw RED/change and the required tracker update before any later correction can be
authorized.

## Exact successor

**`M3-CP4c-3-TB32-REV` — evidence-only semantic review.** It must consume immutable artifacts `9986786215` and
`9986786399`, execute no new runtime or compile, independently verify the 408-row/provenance/census contract,
adjudicate both R4 falsifiers and the raw failure of required-green 390/393/406/407, classify the new 366/367 locus,
verify the carried credibility rows, update `Regression_Root_Cause_Tracker.md` and `ORIENTATION.md`, perform the
mandatory REVIEW document consolidation, and freeze only the next boundary justified by the immutable evidence.

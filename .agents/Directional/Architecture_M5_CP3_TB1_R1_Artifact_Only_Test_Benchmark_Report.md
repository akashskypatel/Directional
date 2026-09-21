# M5-CP3-TB1-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R1-EXEC`
**State:** **COMPLETE / MECHANICALLY COMPLETE / SEMANTIC RED / REVIEW REQUIRED**
**Date:** 2026-09-21 UTC
**Candidate:** artifact `10615252806` / source `fc2aa5fa68cac890051614c2104979aef4a60d21`
**Accepted runtime authority remains:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Authorized successor:** `M5-CP3-TB1-R1-REV`

## Outcome

Corrected R1 executed the frozen artifact-only gate from process 1 through all **445** required exact-filter processes without rebuild, repair, source/fixture/selector mutation, discovery generation, or benchmark execution.

| Gate | PASS | RED | SKIP | INVALID |
|---|---:|---:|---:|---:|
| 9 reviewed mechanism identities | **9** | 0 | 0 | 0 |
| 6 `M5CP3.Produced...` identities | 0 | **6** | 0 | 0 |
| selector430 | **429** | **1** | 0 | 0 |
| **Total** | **438** | **7** | **0** | **0** |

Every process selected exactly one test and skipped zero tests. All semantic REDs were preserved and execution continued exactly as the frozen plan requires.

The six produced-torus identities all terminate before their relation-specific assertions with the same producer diagnostic:

```text
PeriodicHolonomyMismatch
```

Selector ordinal **408**, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, is the sole selector RED. It expected `SurfaceCellProducerDisposition::Produced` but received `Rejected` with `NotProductionReady/tracing/None` at `tests/FieldAlignedCurveNetworkTests.cpp:17063`; the CB2 final-kind assertion is therefore not reached.

This runtime localizes one shared torus-production reachability surface. It does **not** by itself prove which internal guard is wrong or whether the correction belongs to implementation versus test/expectation authority. That adjudication belongs to the independent runtime-free Review.

## Frozen candidate and routing authority

R1 consumed the same frozen semantic candidate as the blocked predecessor and changed only the independently reviewed routing ZIP digest literal and R1 turn names:

- Candidate artifact: `10615252806`
- Candidate ZIP SHA-256: `1e32fa2b55f84b9097b0d617bcfc1b5f7ad1ab7e5ffc2bdb8e0cde8ea715bf20`
- Candidate source: `fc2aa5fa68cac890051614c2104979aef4a60d21`
- Root `SHA256SUMS`: `322b04df9767a80bc246b4b0a03886cc6abb118b8e13147ed8fa1126de74a7c1`, **28/28** verified before and after runtime
- Packaged source archive: `6fe16061079b01079bc53006f102575a5452a950b663807b4f278949ff3ef967`
- Routing artifact: `10592987234`
- Correct routing ZIP SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
- Routing `identity-map.tsv`: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`
- Selector first427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- Routing owner census: **31 / 283 / 75 / 41** across authority-kernel / producer / completion / validation executables

## Runtime authority and evidence

- Workflow run: `35548642817`
- Runtime job: `106179163233`
- Event SHA: `8d4a87c7cb8148998e60bee36f056447d6512765`
- Frozen R1 driver SHA-256: `fa48d472891d8a6c38e38b2800acae571662b24cc055abb90b4d17f95587934b`
- Result artifact: `10617583137`, provider/download SHA-256 `264f1cc1428e4b91c388aa3281df471730dd84dc621b4e87a0b3c0bad5ef3f37`
- Diagnostic-log artifact: `10616998978`, provider/download SHA-256 `1970c9f24c1f00a2f165b85dc28daaec831d6b8d92f707e7a5aa69bca5163790`
- Result self-manifest: **908/908** verified
- First semantic process started `2026-09-21T00:44:48Z`; final selector process ended `2026-09-21T00:53:04Z`; execution boundary closed at `2026-09-21T00:53:05Z`.

Required evidence hashes:

| Evidence | SHA-256 |
|---|---|
| mechanism ledger | `4c1825481f4711eba54c94318a27cc497ee4a2465ed505b46d82f8f313c6f440` |
| produced ledger | `4d93fb6c21461ee4cae7df92240f407b58f4c24452e61e0f641ae47e24c52067` |
| selector ledger | `59a5e84c4f430588111b1e06985226ce270ba9999c3fb28a6ef59ddfdf713074` |
| semantic summary | `1ba52250e80700b680d44b46dfce26201808473d132ac86f2f92f074de1d9d86` |
| execution boundary | `fd9f6be2d29eacfbb67e71f542166d088defd0a8dd0f0902c868818cccba7438` |
| immutability receipt | `41aece7634f1d0667902a6080573e1fd7624b8e2bd4e79d74e2e8f660fe70f85` |
| focused routing | `34d0e8e19a040d3e598ed24e385a8727e315c13c3971fa2dc2f3438e47f1e528` |
| package census before | `d7ba2816996508f80d3f43096b40f3edd4943aa1498358cd6dcbdf5ce7ea3545` |
| source census before | `7db59b6026051cc86f26352b70b99daf6ce1e5cf53954790dfa79e77f9cf3f9b` |
| execution-view census before | `b1f3ce783acd730ddd5761e4fff9f29dac4f07f59da64fad6929294d6eb6e999` |
| candidate manifest check before/after | `edb83ff8b31333243011249ca54d30f86afe7d731893b9910f98e848c6899df2` |

Resource receipts exist for all **9 + 6 + 430** semantic processes.

## Mechanism gate

All nine reviewed mechanism identities PASS. This preserves the already-reviewed certificate/relation machinery independently of the produced torus failure.

## Produced-torus gate

All six frozen produced identities are exact-one/zero-skip semantic REDs with the shared `PeriodicHolonomyMismatch` producer failure:

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

The common precondition failure means none of the four M5 produced-witness debts receives credit in this execution.

## Selector430 gate

Selector430 executes **430/430** exact processes with **429 PASS / 1 RED**, no skips and no invalid selection. The sole RED is ordinal408 described above. All other accepted selector identities remain green on the candidate.

## Immutable postflight and command boundary

R1 proves:

- package byte/mode census unchanged;
- packaged source byte/mode census unchanged;
- execution-view byte/mode census unchanged;
- root manifest still **28/28**;
- selector430 and first427 hashes unchanged;
- routing map unchanged;
- `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`;
- `orchestration_failure=false`;
- configure / compile / relink / generated discovery / package repair / mode repair / source-test-fixture-selector mutation / benchmark execution are all **0**.

No same-turn semantic repair was attempted.

## Regression classification

Record `M5-CP3-TB1-R1-CAND-01` as **ACTIVE / SEMANTIC RED / SHARED TORUS PRODUCTION-REACHABILITY FAILURE / REVIEW PENDING / NON-STABLE**.

The discriminating runtime facts are:

- the nine mechanism rows are green;
- every produced-torus row fails at the same producer precondition before relation-specific assertions;
- accepted selector ordinal408 independently fails on the same torus production path by receiving `Rejected` instead of `Produced`;
- all other selector rows remain green;
- the package/source/view surfaces are immutable.

The changed semantic surface relative to accepted runtime authority is the reviewed CB2 same-region A3 `PeriodicCut` / periodic-relation seam, but this Test + Benchmark turn does not infer the exact faulty guard from endpoint diagnostics alone. Independent Review must classify implementation authority versus test/expectation authority before any corrective turn is authorized.

Stable accounting therefore remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. Candidate `10615252806` is **not promoted**. The four M5 produced debts remain open, and `M5-CP2-TB1-REV-OBS-01` remains open.

## Closeout transport exception

The verified work-preservation patch was emitted as a user-visible/Library backup before repository mutation. Standard Google Drive raw-file staging was attempted, but the available Drive upload surface rejected the generated ChatGPT File/Library reference because it requires a connector-native file-reference object that the Files surface cannot provide. No Drive staging file was created. To avoid repository-staged patch payloads while preserving one coherent mutation, the six documentation/report paths are applied through one compare-and-swap Git Data commit from the verified patch against the current branch head. This control-plane exception does not alter runtime evidence or semantic authority.

## Successor boundary

The mechanically complete semantic-RED result routes directly to independent runtime-free **`M5-CP3-TB1-R1-REV`** under the frozen plan. That Review must independently reopen this evidence, classify `M5-CP3-TB1-R1-CAND-01`, adjudicate candidate/debt authority, and determine the next authorized correction or publication path.

Do **not** implement, compile, rebuild, rerun, publish a selector, promote the candidate, or discharge produced-witness debt before that Review.

# M5-CP3-TB1-R2 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R2-EXEC`
**State:** **COMPLETE / MECHANICALLY COMPLETE / SEMANTIC RED / REVIEW REQUIRED**
**Date:** 2026-09-21 UTC
**Candidate:** artifact `10620415471` / source `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`
**Accepted runtime authority remains:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Authorized successor:** `M5-CP3-TB1-R2-REV`

## Outcome

R2 executed the frozen corrected-candidate artifact-only gate from process 1 through all **445** required exact-filter processes without rebuild, repair, source/fixture/selector mutation, generated discovery, or benchmark execution.

| Gate | PASS | RED | SKIP | INVALID |
|---|---:|---:|---:|---:|
| 9 reviewed mechanism identities | **9** | 0 | 0 | 0 |
| 6 `M5CP3.Produced...` identities | 0 | **6** | 0 | 0 |
| selector430 | **429** | **1** | 0 | 0 |
| **Total** | **438** | **7** | **0** | **0** |

Every process selected exactly one test and skipped zero tests. All semantic REDs were preserved and the complete frozen sweep continued as required.

The six produced-torus identities again terminate while establishing the real production fixture with the same producer diagnostic:

```text
PeriodicHolonomyMismatch
```

Selector ordinal **408**, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, is again the sole selector RED. It expected `SurfaceCellProducerDisposition::Produced` and received `Rejected` with `NotProductionReady/tracing/None` at `tests/FieldAlignedCurveNetworkTests.cpp:17063`; the later final-kind assertions are therefore not reached.

R2 therefore falsifies the recovery expectation that the CB3 exact-span correction alone would restore the frozen torus production gate. This execution does **not** independently classify the remaining internal failure branch, change test/expectation authority, or authorize another correction. Those judgments belong to `M5-CP3-TB1-R2-REV`.

## Frozen candidate and routing authority

- Candidate artifact: `10620415471`
- Candidate ZIP SHA-256: `700b605167427d21823b90d942dd5bb40d1690f162285d22a20da5ad7898a1cd`
- Candidate source: `279efa03471f1e0d6c32f57c8b395dd1cb1a93f5`
- Root `SHA256SUMS`: `ea12d6fc6ab6752f8ef10f46f1900423e9074e62c25edba48bde5b4526623d24`, **28/28** verified before and after runtime
- Packaged source archive: `198a6454bb3171a863be571b91ec861d1161dbab608d3114a86032ee40dc2f00`
- Routing artifact: `10592987234`
- Routing ZIP SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
- Routing `identity-map.tsv`: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`
- Selector first427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- Selector owner census: **31 / 283 / 75 / 41** across authority-kernel / producer / completion / validation executables

## Runtime authority and evidence

- Successful workflow run: `35557990692`
- Runtime job: `106205308600`
- Event SHA: `064a948de8fa1ca0789819945e0ef628c0ff04c7`
- Driver template SHA-256: `574a60970b28bac78413f65865d8be5e46e1b7f4cf93fb636916de23d7512a2e`
- Frozen R2 plan SHA-256: `f69fa829c9541464f80da03fa562132d2eae2cee5cb76211827291a416ccfad6`
- Payload writer SHA-256: `d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`
- Rendered runtime driver SHA-256: `e9f15c9643b6c8c7c69982b99c172183ed8a4db610442571aa6f83e124fb5320`
- Result artifact: `10621351075`, provider/download SHA-256 `793de57785f058e8a16a9d95c084d6e593b7d0e552586756b3fa0c021b85e66f`
- Diagnostic-log artifact: `10621154456`, provider/download SHA-256 `65e4ba46c7bd5c6cd45e91cd35a35fc9aaec1e7c0b4bd61a3aac9d171e0daf02`
- Result self-manifest: **908/908** verified
- First semantic process started `2026-09-21T03:35:06Z`; final selector process ended `2026-09-21T03:48:15Z`; execution boundary closed at `2026-09-21T03:48:15Z`.

Required evidence hashes:

| Evidence | SHA-256 |
|---|---|
| mechanism ledger | `09610556b4c75fd3c07908ff3fb9b9bd0eee7e2756893186a89f63f56bb12dfc` |
| produced ledger | `d43a35c61b2d8f4ee62304a97ba3c01312d3971e5bb88b2c4baac00b71d81d0c` |
| selector ledger | `b1d15091a44fdb3d902cdc7b3bf733d360772580a99a274a22fe1905a3b4f7d7` |
| semantic summary | `1ba52250e80700b680d44b46dfce26201808473d132ac86f2f92f074de1d9d86` |
| execution boundary | `c9d36728e3aafb94b79d988902bd95d1b1431fd22e62c138d2adb84cab70f32b` |
| immutability receipt | `41aece7634f1d0667902a6080573e1fd7624b8e2bd4e79d74e2e8f660fe70f85` |
| focused routing | `34d0e8e19a040d3e598ed24e385a8727e315c13c3971fa2dc2f3438e47f1e528` |
| package census before | `2c9a69af67443c21e651eed85b99d85314b780b3b9c955141d0cd5b028a4f75e` |
| source census before | `187d915bd3d6048855b35f36791fddac5a5e3d84cce2c492a1c75953f6ef7dae` |
| execution-view census before | `004d5a5571afb34aeaf4bac168e4f6c82a556583c43f9fe4a5d852e0d3f7b851` |
| candidate manifest check before/after | `ba40394bb4ecd4f1122e6d0ed70bbd2815a6a76bb3ca84076aff1d0dedc2a674` |
| driver authority receipt | `f13813cbb4a87e87432934124e22d19ad31b011f4b976a6ab51ee4b536fe436e` |

Resource receipts exist for all **9 + 6 + 430** semantic processes.

## Mechanism gate

All nine reviewed mechanism identities PASS. The already-reviewed CP1/CP2 certificate and typed relation machinery remains green independently of the produced torus failure.

## Produced-torus gate

All six frozen produced identities are exact-one/zero-skip semantic REDs with the shared `PeriodicHolonomyMismatch` producer failure:

1. `M5CP3.ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges`
2. `M5CP3.ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate`
3. `M5CP3.ProducedTorusMissingPeriodicRelationOwnerRejectsTyped`
4. `M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes`
5. `M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped`
6. `M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate`

The common precondition failure means none of the four M5 produced-witness debts receives execution credit.

## Selector430 gate

Selector430 executes **430/430** exact processes with **429 PASS / 1 RED**, no skips and no invalid selection. Ordinal408 is the sole RED. Every other accepted selector identity remains green on the corrected candidate.

Because ordinal408 is inside the accepted selector prefix and is RED relative to accepted runtime authority, R2 is recovery-failure evidence for the already-open accepted-prefix regression. This EXEC turn does not decide whether Review should treat that observation as continuation of `M5-CP3-TB1-R1-CAND-01` or as any distinct accounting event/category.

## Immutable postflight and command boundary

R2 proves:

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

## Orchestration-only attempts before the successful sweep

Three earlier R2 control-plane attempts earned zero semantic credit:

- runs `35557784603` and `35557876607` failed at workflow construction before any job was created;
- run `35557920887` reached the runtime job but rejected driver materialization before the execution step because one durable plan digest appeared twice with the same value.

The caller was corrected only at the orchestration boundary. Final run `35557990692` then restarted from process **1** and is the sole semantic authority for R2.

## Regression / recovery disposition

Record `M5-CP3-TB1-R2-CAND-01` as **SEMANTIC RED / RECOVERY FALSIFIER / REVIEW PENDING**.

The discriminating runtime facts are:

- the nine mechanism rows remain green;
- every produced-torus row still fails at the same producer precondition before relation-specific assertions;
- accepted selector ordinal408 still receives `Rejected` instead of `Produced`;
- all other selector rows remain green;
- the candidate, source, execution view, selector and routing map remain immutable.

CB3's exact-span change therefore did not recover the endpoint behavior under the frozen gate. EXEC does not infer a new internal cause from the collapsed `PeriodicHolonomyMismatch`, does not change stable accounting, and does not authorize implementation or test mutation. Current durable accounting remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**, pending independent Review adjudication.

Candidate `10620415471` is **not promoted**. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. All four M5 produced debts remain open, and `M5-CP2-TB1-REV-OBS-01` remains carried.

## Successor boundary

The mechanically complete semantic-RED result routes directly to independent runtime-free **`M5-CP3-TB1-R2-REV`**. Review must independently reopen the R2 result/log evidence, compare the corrected candidate with the frozen §14 authority and accepted runtime baseline, adjudicate the failed recovery, decide stable-event/accounting disposition, and determine the next authorized implementation or definition path.

Do **not** implement, compile, rebuild, rerun, publish a selector, promote the candidate, discharge produced-witness debt, or mutate test authority before that Review.

# M5-CP3-TB1-R3 Artifact-Only Test + Benchmark Report

**Turn:** `M5-CP3-TB1-R3-EXEC`
**State:** **COMPLETE / MECHANICALLY COMPLETE / SEMANTIC RED / REVIEW REQUIRED**
**Date:** 2026-09-21 UTC
**Candidate:** artifact `10624020011` / source `6dd0e5179686a4ea2ca4aacda0577855948864df`
**Accepted runtime authority remains:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**Authorized successor:** `M5-CP3-TB1-R3-REV`

## Outcome

R3 consumed the CB4 correction package exactly and completed the frozen artifact-only gate from process 1 through all **445** required exact-filter processes. No rebuild, configure, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation, or benchmark execution occurred.

| Gate | PASS | RED | SKIP | INVALID |
|---|---:|---:|---:|---:|
| 9 reviewed mechanism identities | **9** | 0 | 0 | 0 |
| 6 `M5CP3.Produced...` identities | 0 | **6** | 0 | 0 |
| selector430 | **429** | **1** | 0 | 0 |
| **Total** | **438** | **7** | **0** | **0** |

Every process selected exactly one test and skipped zero tests. All seven semantic REDs were preserved and the complete frozen sweep continued as required.

All six produced-torus identities terminate while establishing the real production fixture with the same producer diagnostic:

```text
PeriodicHolonomyMismatch
```

Selector ordinal **408**, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, is again the sole selector RED. It expected `SurfaceCellProducerDisposition::Produced` and received `Rejected` with `NotProductionReady/tracing/None` at `tests/FieldAlignedCurveNetworkTests.cpp:17063`; later final-kind assertions are therefore not reached.

R3 therefore falsifies the recovery expectation that the CB4 exact hard-feature transition-value and exact-parameter orientation correction restores the frozen torus production endpoint. This EXEC turn does **not** infer the remaining internal cause from the collapsed `PeriodicHolonomyMismatch`, change test/expectation authority, or authorize another correction. Those judgments belong to independent `M5-CP3-TB1-R3-REV`.

## Frozen candidate and routing authority

- Candidate artifact: `10624020011`
- Candidate ZIP SHA-256: `eeba51295d20082c8f20840b3f3b280d6b6012a1178eef2bd3eb5afbfd1a0ed6`
- Candidate source: `6dd0e5179686a4ea2ca4aacda0577855948864df`
- Root `SHA256SUMS`: `a9ccee0d830768e1d91239741bba67f4912fe86efe12cca8ddd3a13cf50f4177`, **28/28** verified before and after runtime
- Packaged source archive: `643ce57f4b23d2237d8be0d856b6e8b49229f12dc99c49ab0ff514e39bd39253`
- Routing artifact: `10592987234`
- Routing ZIP SHA-256: `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`
- Routing `identity-map.tsv`: `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`
- Selector430 SHA-256: `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`
- Selector first427 SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`
- Selector owner census: **31 / 283 / 75 / 41** across authority-kernel / producer / completion / validation executables

## Runtime authority and evidence

- Successful workflow run: `35565176454`
- Runtime job: `106225476682`
- Event SHA: `71204f320d8151d8bf324e7a04ca3618d948790a`
- Driver template SHA-256: `58a24e52c7ccc92a4be568c766db0049be38481b6bccb5a19edf840394a6f85a`
- Frozen R3 plan SHA-256: `d77e20c803320c7831b9a51cce9779011ae81c26ebfe4f1bf208000ffd948dc5`
- Payload writer SHA-256: `d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`
- Rendered runtime driver SHA-256: `c411f7cd33838a4c8458cd082520e7e8ac54c538919765017a85558da986fd01`
- Result artifact: `10623878370`, provider/download SHA-256 `6e3c4dcdfeb379268a6b43480c2b5569f49359bb699466527b1e57ccd8faafaa`
- Diagnostic-log artifact: `10624252516`, provider/download SHA-256 `0589830ae95f800f088e0f7392d9daa9edf3c18ddced319b88a9549369132b65`
- Result self-manifest: **908/908** verified
- First semantic process started `2026-09-21T05:36:58Z`; final selector process ended `2026-09-21T05:49:29Z`; execution boundary closed at `2026-09-21T05:49:29Z`; runtime job finished at `2026-09-21T05:49:31Z`.

Required evidence hashes:

| Evidence | SHA-256 |
|---|---|
| mechanism ledger | `0c5cbb697453bd53f9a5389569bdd9d56e4f76a02634009d82ffd8bdf3f053f2` |
| produced ledger | `7b957f36f0b825b3c4e2545457f2730310bcb1807915ab998405b1ef4452b582` |
| selector ledger | `909b37c0b22c63cc97db6be63a29a49d659b6bc1a287443e1e17825dc9026f63` |
| semantic summary | `1ba52250e80700b680d44b46dfce26201808473d132ac86f2f92f074de1d9d86` |
| execution boundary | `444c168707bde33a0c70a5d15dd84703f8f6b0779fc391d29f4b05d4de840f08` |
| immutability receipt | `41aece7634f1d0667902a6080573e1fd7624b8e2bd4e79d74e2e8f660fe70f85` |
| focused routing | `34d0e8e19a040d3e598ed24e385a8727e315c13c3971fa2dc2f3438e47f1e528` |
| package census before | `15df9d475ea2ff646aebe0f7b003baa7b697c8138712f073b9303c62226d6ffd` |
| source census before | `c75ae9095a9fb9a1f9398fe33549c3af96e3995be756afe31c9c51181f987af0` |
| execution-view census before | `7213788ec23c74ad87c7411002ce38702c7647a2a6d8ae22791ce3f80a81ff5a` |
| candidate manifest check before/after | `b11730f454b4d250aed4426cfb5db46cb1384fcc0eae325f423d2d1aeb616bbe` |
| driver authority receipt | `5a5a0e8f545f1175977761d65972b9745226f4944a23ab9d1a3505eefa65b4ad` |

Resource receipts exist for all **9 + 6 + 430** semantic processes.

## Immutable postflight and command boundary

R3 proves:

- package byte/mode census unchanged;
- packaged source byte/mode census unchanged;
- execution-view byte/mode census unchanged;
- root candidate manifest still **28/28**;
- selector430 and first427 hashes unchanged;
- routing identity map unchanged;
- `preflight_completed=true`, `runtime_started=true`, `runtime_completed=true`;
- `orchestration_failure=false`;
- configure / compile / relink / generated discovery / package repair / mode repair / source-test-fixture-selector mutation / benchmark execution are all **0**.

No same-turn semantic repair or rerun was attempted.

## Regression / recovery disposition

Record `M5-CP3-TB1-R3-CAND-01` as **SEMANTIC RED / RECOVERY FALSIFIER / REVIEW PENDING**.

The discriminating runtime facts are:

- all nine reviewed mechanism rows remain green;
- every produced-torus row still fails at the same producer precondition with `PeriodicHolonomyMismatch`;
- accepted selector ordinal408 still receives `Rejected` instead of required `Produced`;
- all other selector rows remain green;
- candidate/package/source/execution-view/selector/routing authority remains immutable.

CB4's hard-feature transition-domain correction therefore does not recover the endpoint behavior under the frozen gate. EXEC does not classify whether the remaining fault is another instance of the already-open R1 stable event or a distinct cause. Stable accounting remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**, pending independent Review adjudication.

Candidate `10624020011` is **not promoted**. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. All four M5 produced debts remain open, `M5-CP2-TB1-REV-OBS-01` remains carried, and selector publication remains prohibited.

## Successor boundary

The mechanically complete semantic-RED result routes directly to independent runtime-free **`M5-CP3-TB1-R3-REV`**. Review must independently reopen the R3 result/log evidence, re-derive the complete outcome and immutable boundary, compare CB4 source `6dd0e517...` against frozen §14 authority and the accepted runtime baseline, adjudicate why the exact hard-feature transport correction still does not restore production, decide stable-event/accounting disposition, and freeze the next bounded authority.

Do **not** implement, compile, rebuild, rerun, publish a selector, promote the candidate, discharge produced-witness debt, or mutate test authority before that Review.

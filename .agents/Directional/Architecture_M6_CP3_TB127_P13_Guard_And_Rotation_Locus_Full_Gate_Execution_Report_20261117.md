# TB127 — guard and rotation-locus full gate (2026-11-17 UTC)

**Canonical turn:** `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC`. **MISMATCH** under [RA-246 §5](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md#5-tb127-frozen): full gate MATCH, census has four changed assertion-line records. Both executions succeeded at the orchestration level. No new source, test, fixture, manifest, selector or build mutation, configure, compile, relink, benchmark or successor work. PR #8 remains open/draft.

## Immutable authority and preflight

- CB146 semantic source `48e6f97d278b2226036f658ce9060a38b8a374b5`; package `14301616031`, [compile run 44022151247](https://github.com/akashskypatel/Directional/actions/runs/44022151247). ZIP SHA-256 `457a9d061cbfe290baa1cad0b3df29b085f81f639dd8ea7e829e38aea6458984`; all 28 internal hashes pass; GMP, runtime-free compile boundary, archived executable modes preserved.
- Executor snapshot `21309c49bb7fba212fdfa1ec27e923404916e131`, [snapshot run 44024046070](https://github.com/akashskypatel/Directional/actions/runs/44024046070), artifact `14302187146`; ZIP SHA-256 `3466a2af85c2ceebff31c69e2a5165692131150b3b4326734fd1a2c5179b077a`; 5,512/5,512 file hashes pass. Compare to semantic source shows only documentation/control changes. Both CB144B and CB146 exact changes and postimages verified.
- Frozen gate `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f` (951 rows), membership ledger `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred), census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 rows). Existing harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Both manifest self-checks pass.
- TB126 comparison authority: gate artifact `14294372593`, ZIP SHA-256 `c13a0f5e29ab961a6c6d7a31c2883cfaafbdc577d5727f291eb127e9cc8ea55e`, 1,910/1,910 hashes; census artifact `14294313207`, ZIP SHA-256 `79acdba05b737e6987a39d3908ce7bf3f9375f4c051b5c4a35566670b63eb95f`, 9/9 hashes. Raw ledger hash, selected-case binding, execution boundaries independently verified. TB126 gate 950/951, row 951 exception; census Cylinder PASS 288, BunnyRandom and Vase RED.

## Execution identity

| Work | Request event SHA | Actions run / runtime job | Mailbox key (attempt 1, success) |
|---|---|---|---|
| Full gate | `f5e23873d5ebccb83687388dd78330aa2c162802` | [44024527625](https://github.com/akashskypatel/Directional/actions/runs/44024527625) / `133841749525` | `m6-cp3-tb127-gate-v1` |
| Census | `91ad92da0476dfda290ee8fe877488556f7dcb81` | [44024687415](https://github.com/akashskypatel/Directional/actions/runs/44024687415) / `133845742752` | `m6-cp3-tb127-census-v1` |

Both immutable mailbox records bind the exact events and CB146 semantic source. Gate request SHA-256 `013b457bfe75c3c69d62894ff42a1c4d71b351e792d2c37675ccce3706aec0b4`; census `15bd6f0bbfad0eaf08a520b70762b6ad0418fe4f9d3e043c509d8efcb14414c9`. Schema validation, parse, checkout and harness checks passed. Both runs finished organically; no duplicate execution.

## Full gate — MATCH

Result artifact `14302887671`, ZIP SHA-256 `017ad5589ae533d4f428312bc59d92409906544f6cd1add1a3db0ccc80383050`; 1,910/1,910 internal checksums, all 951 raw log bindings, exact manifest identities. Gate log artifact `14302982488`. 951/951 PASS, zero RED/skipped/missing/duplicate/abnormal, membership 1,032 (951 gated/81 deferred), postflight true, exit 0. Row951 PASS without exception; no gate inventory lines. All 950 inherited substantive ledger rows match TB126; raw differences only permitted newline framing after elapsed-time normalization in rows 156/168/173/175/190/191/477/705.

## Census — MISMATCH (exact comparison)

Result artifact `14302668940`, ZIP SHA-256 `4edf0fe64c45fac424eb0c8ef9ed4e9eaae675373e32f06724df9ea4724f3cc5`; 9/9 internal checksums and all three raw log bindings pass. Census log artifact `14303760529`. All three cases executed once: one PASS, two registered RED, no skips/abnormal/missing/duplicate; postflight true, harness exit 0.

| Case | Result | Recorded terminal |
|---|---|---|
| Cylinder | PASS, 288 quads | No terminal failure. All normalized lines match. |
| BunnyRandom | RED, zero output faces | `RotationSystemInconsistent` / `CellularityNotEstablished`, face (5,104,359); exact prior terminal prefix, four identical mandatory-edge inventory lines. |
| Vase | RED, zero output faces | `AggregateCompletionValidationFailure`, 189462 segments, 26817 arrangement cells, 67750 internal quads; exact prior terminal (no suffix). |

BunnyRandom suffix (verbatim, including leading space):

```text
 rotationReason=TraceEventPositionInvalid trace=0 eventIndex=18 eventPositionReason=NoCarrierMatch eventPositionPass=SourceEdgeUnavailable
```

RA-246 F3's registered face-locus prediction includes `TraceEventPositionInvalid`. This is measured, not adjudicated in this TB. Preserve the existing inventory: edges (241,251) and (251,278) each have two distinct parameters, across traces 107/38 and 92/41, nodes 149/178 and 184/162 respectively.

The only normalized non-terminal log differences are the GoogleTest assertion source line numbers. In BunnyRandom and Vase, `tests/SurfaceCellDesignAcceptanceTests.cpp:432: Failure` becomes `:493: Failure`, and `:434: Failure` becomes `:495: Failure`. Two lines per RED case, four total. The two corresponding census ledger `first_failure` fields also change from 432 to 493. All other substantive census ledger fields match (excluding raw log hashes). The frozen CB146 diff adds 61 lines in `failure_locus` before these assertions; unchanged assertion text appears at 493 (independent oracle) and 495 (produced result). RA-246 §5 permits only elapsed times, GetParam byte dumps and the appended terminal text. It does not permit assertion-line relocation. Do not amend that criterion retrospectively. This is a comparison-contract mismatch, not evidence of a newly introduced production regression.

## Classification and route

Keep C3 and C5 open for independent adjudication. O42/O43 open; O44/C1 closed. Stable totals unchanged: 66 events / 17 categories / 49 recurrences, debt 1, deferred 81. Accepted CP2 491/491; CP3/selector497 and D0 not promoted; `chainRimSchedules=false`; D11=A, D12=A, D10 deferred, D6 pending. The earlier guard exception no longer occurs. Vase remains unchanged. No new stable regression ID or accepted-green loss is justified.

Exactly next per the frozen mismatch route: `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV`. Review only: adjudicate the four line-number differences, the guard and the printed locus against RA-246. Do not execute a new gate, change source, or start the MATCH-only outcome turn or CB145 here.

## Continuation reconciliation

The earlier interrupted response preserved an unapplied handoff/TODO patch (base `21309c49bb7fba212fdfa1ec27e923404916e131`, full SHA-256 `7b126ff10643f006b4946a1853415c8ccb3bbb4aa17c1152ff4ce2cd12ce299e`, diff body `33fe0a43877b9a7f3357809027c0eceb24141bf87dfe9600e7de09aeda903c9e`, Drive File ID `1amMuHSmPce0KjirLQ-X63qq2dmmKwYcD`). Both hashes match. It is superseded by the result-dependent documentation delta, not applied as stale in-progress state. No replacement runtime executed. Prior attempt's tool ledger is incomplete; do not invent total. The first attempt had late timer/policy loading. This does not alter the immutable evidence.

## Durable closeout verification

The six-file documentation patch (base `21309c49bb7fba212fdfa1ec27e923404916e131`, SHA-256 `61a2d980b2cca344bf0dd1383b18c949bb45a66e5e9101ac207eecc022bd14cb`) passed local apply and whitespace checks. [Apply run 44027628991](https://github.com/akashskypatel/Directional/actions/runs/44027628991) succeeded; result artifact `14304270928` verified. Applied commit `9ccd4a9aa523967a044bc87a1421322af2c928c6`; all six resulting file blob hashes independently match. Drift audit: zero errors, three protected-document currency warnings; durable sections retained. Final evidence bundle in File Library `/Directional/Evidence/Directional_TB127_verified_evidence.zip`, SHA-256 `e0b5c4641e812680ce5fedfa4f4d3703aa39ce9c1b0a87adc3601b3668e2f6ca`. The final Drive patch and earlier superseded patch were both deleted after successful application. [Cleanup run 44027872780](https://github.com/akashskypatel/Directional/actions/runs/44027872780) succeeded; result artifact `14303428163` verified; cleanup commit `8a5d781b3dec01e5220a6984ed534800d25126d6`. TB127 marker and cleanup manifest absent; ten durable workflows and request slot intact; 37 pre-existing legacy controls left outside this turn's scope. No implementation or acceptance promotion.

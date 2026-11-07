# M6-CP3-TB52-RP01-FULL-GATE-EXEC — immutable five-binary gate evidence (2026-10-30)

**Scope:** artifact-only TB-EXEC on the frozen CB52 binary package, with the P8 membership preflight over all five packaged binaries. This reports native execution only; independent review and any selector/CP3 acceptance are outside this turn.

## Frozen inputs and control-plane provenance

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8. Semantic source `7cf0857b4818186638ce77e4859adacbeebd288f`, immutable package artifact **`12918290481`** (candidate ZIP SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`; package root SHA256SUMS `6ae4eb5bf9552912fe068d9a9d3a90d76e2e27b9bd99896f83c216fd27fbc21f`; packaged source archive SHA-256 `c02a0be4b25d64eca2c10e5681cd8721a465a848a3d17044275370eac132553b`). No rebuilt package or repair.
- Gate: `Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv`, **853** ordered GATED cases, SHA-256 `95a7af662fd94306c92145050eff18fa0cc57de4eed19d1e4704938fc5532211`; off-gate `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv`, **86** DEFERRED cases, SHA-256 `77c1d33b25f65837aa24c446b99657bfc1932fb8ab7636cc9c3ded598c38c78d`. Deferred classes: 50 FIXTURE, 7 PRODUCT, 24 OPEN, 5 RETIRE.
- Harness `tools/m6_cp3_targeted_artifact_harness.sh`, P8 SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; executor SHA `02cd62d0972430769ddedda61a6137f48235fe82`. Dispatcher request event SHA `4a54e9ede4069be2c80dee012721d5d99f7522fb`, request ID / mailbox key `m6-cp3-tb52-rp01-full-gate-20261030-v1`, request SHA-256 `a6a1663123783b8e1d3d5b1eb14aafe74ead76b7a9f7bf90337c596ccbec5d51`.
- [GitHub Actions run 41100261157](https://github.com/akashskypatel/Directional/actions/runs/41100261157), attempt 1: validation, parse, `test_benchmark / runtime`, and mailbox publication all succeeded. Mailbox published `2026-10-30T19:11:27Z`, pins the request/event/source and `result=success` on orphan `workflow-mailbox`.
- Result artifact **`13004891149`**: outer ZIP SHA-256 **`ba18016515e810f8cecdd4da500a6026eefe973a11f9afe55879fd1ae948f684`**, independently matched to provider digest. Separate native-harness diagnostic log artifact **`13003329462`**: provider-listed outer ZIP SHA-256 `7dedbb1a20a331b29797380529e7df1c6761d6d6d8479cb34666b7e5be42464f` (digest not independently rechecked in this report).

## Native evidence, exact joins, integrity

| Measure | Verified result |
|---|---:|
| Planned / executed / passed | **853 / 853 / 853** |
| RED / ABNORMAL / missing / skipped / duplicate / control_bad | **0 / 0 / 0 / 0 / 0 / 0** |
| Unexpected PASS / later-positive RED / red-site bad | **0 / 0 / 0** |
| Membership preflight (five packaged binaries) | **939** distinct binary/test pairs |
| GATED / DEFERRED membership census | **853 / 86**, exact match, zero collision/extra/missing |
| Result `SHA256SUMS` entries independently verified | **1,714 / 1,714** |
| GATED ledger↔manifest row/key joins and raw log SHA joins | **853 / 853** |
| Per-native-log GoogleTest RUN and OK markers | **853 / 853**, no FAILED markers |
| `postflight` / final harness exit | **true / 0** |

- Independent audit verified all 853 ordered ledger rows match frozen manifest `row`, `kind`, `identity`, `test`, `binary`; each native log SHA matches its ledger record; `exit=0`, `run=1`, `passed=1`, `skipped=0`, `verdict=PASS` for every test. The 939 membership rows exactly join all 853 gated plus 86 deferred binary/test pairs; none of the deferred cases was run or accepted by this TB turn.
- `execution-boundary.json` pins package `12918290481`, semantic source `7cf0857b…`, all counters above, `postflight=true`, `exit=0`, and explicitly `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. No native executable ran in the ChatGPT container; only artifact-independent checksum and text/log verification ran locally.
- Source snapshot for the inspection authority: run `41100106803`, executor/event SHA `02cd62d…`, **5,997** file members checked in the prior turn; snapshot has `runtimeExecution=false`. It does not change build or native runtime authority.

## Regression and acceptance boundary

**No selected-gate non-PASS**, hence no newly observed gated regression and no justified stable-regression increment. Stable totals remain **66 events / 17 categories / 49 recurrences**, debt **1**. The 86 deferred cases remain non-gating, non-executed and unresolved, with the RA-176 O15 cross-platform A3 exactness issue and RP-01 223/225/261 plus O9 unchanged. **CP2 491/491** remains the last accepted semantic runtime; TB51 831/0 was the previous reviewed candidate. TB52 **853/0 is a new TB-EXEC candidate, pending independent Review**, not selector497 or CP3 acceptance.

## Successor

RA-176.4 authorizes only **`M6-CP3-TB52-RP01-FULL-GATE-REV`** after 853/853 green, full postflight and membership=939. Independent TB52-REV must re-open the primary artifact and independently determine candidate disposition; do not start that review inside TB52-EXEC.

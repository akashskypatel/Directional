# M6-CP3-TB51-RP01-FULL-GATE-EXEC — immutable full-gate evidence (2026-10-30)

**Scope:** artifact-only Test + Benchmark execution on the unchanged CB52 package. This is a TB-EXEC result report, not an independent TB-REV, acceptance decision, repair authorization, or CP3/selector promotion.

## Exact authority and execution

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft and unmerged at turn entry.
- Immutable semantic source: `7cf0857b4818186638ce77e4859adacbeebd288f` (CB52).
- Candidate package: GitHub Actions artifact `12918290481` (outer ZIP SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`; root SHA256SUMS `6ae4eb5bf9552912fe068d9a9d3a90d76e2e27b9bd99896f83c216fd27fbc21f`; packaged source archive `c02a0be4b25d64eca2c10e5681cd8721a465a848a3d17044275370eac132553b`). No rebuild or package repair.
- Manifest: `Architecture_M6_CP3_TB51_Full_Gate_Case_Manifest.tsv`, SHA-256 `d6961b598a450dd17b818f316249ecacd0fdc73a91d8a1e4e7dca2fa537eb7b4`, 831 ordered GATED rows. Harness: `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `600c6455203519e79736e501288e4777921390bf365a9d3ee5e0141aa49275f8`.
- Exact dispatcher request commit/event: `650fdfbe81a52ffa9b214768af6556df8f25c859`; request ID and mailbox key `m6-cp3-tb51-rp01-full-gate-20261030-v1`; dispatcher request SHA-256 `a066cdb84e850a23ce09f470540ae01d8448bc42052657b73c24058bd5464e9c`. Executor checkout `4812d228a4e7f494ac56b0347d4058bbc065d42e`.
- [GitHub Actions run 41021857497](https://github.com/akashskypatel/Directional/actions/runs/41021857497), attempt 1; runtime job `123950895954` succeeded; mailbox `workflow-mailbox/.workflow-mailbox/m6-cp3-tb51-rp01-full-gate-20261030-v1/latest.json` published `2026-10-30T08:39:57Z`. Mailbox source/event/request identities match the frozen execution request.
- Result artifact `12963899691`: GitHub outer ZIP SHA-256 `e6339e127fd923c9785ef9be5d07402af94bbe2dcc535c29ff4a45ef3d2cf1c7`; log artifact `12964417597` ZIP SHA-256 `4ceeefa4edd6a5b5ed0f6c44de2848ae4647d24e0a7ffd47badc6c298f27be3b`. Both ZIP byte hashes independently matched the provider-listed digests.

## Native result and independent checks

| Measure | Observed |
|---|---:|
| Planned/executed | 831/831 |
| PASS | 831 |
| RED / ABNORMAL / INVALID | 0 / 0 / 0 |
| Missing / skipped / duplicate / control_bad | 0 / 0 / 0 / 0 |
| Unexpected PASS / later positive RED / red-site bad | 0 / 0 / 0 |
| GUARD / POSITIVE | 822 / 9, all PASS |
| Postflight | `true` |
| Final harness exit | 0 |

- All 831 ordered `row`, `kind`, `identity`, `test`, and `binary` keys join exactly from the frozen manifest to `ledger.tsv`; all rows have `run=1`, `passed=1`, `skipped=0`, `exit=0`, `verdict=PASS`. There are 831 distinct native log files, each independently SHA-256-matched to its ledger row. No non-PASS `first_failure` exists; the literal `failure-line-not-observed` in every PASS row denotes no observed failure line, not a failing condition. No `typed_reason` is populated.
- Result `SHA256SUMS`: **1,668/1,668 OK**, including ledger, boundary, raw logs and resources. Snapshot artifact `12960949567` has outer ZIP SHA-256 `4d043ce5080b937e77770c6b40e3c17ab87cc4725e5937d91a7640dfe646a67c`; `source.tar.gz` matches its listed hash, and the 5,987 file-member checks pass. Snapshot metadata pins event/source `4812d228a4e7f494ac56b0347d4058bbc065d42e` and `runtimeExecution=false` (snapshot inspection authority only).
- `execution-boundary.json` names package `12918290481`, source `7cf0857b…`, `postflight=true`, exit 0, and explicitly records `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Runner job's immutable-artifact step completed; no Directional executable was executed locally in this ChatGPT session.
- The manifest and existing deferred ledger are disjoint: 831 unique GATED test names plus 85 unique DEFERRED test names = 916 unique inventoried tests. Deferred classes remain FIXTURE 49, PRODUCT 7, OPEN 24, RETIRE 5. The 85 deferred rows were **not executed** by this 831-row gate and are not asserted to pass.

## Regression and acceptance boundary

There are **no selected-gate RED or ABNORMAL rows**, hence no newly observed selected-gate regression and no justified stable-regression increment. Stable totals **66 events / 17 categories / 49 recurrences**, debt **1** remain unchanged. The deferred 85 are independently recorded in `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv`; TB51 does not reclassify or resolve them. CP2 **491/491** remains last accepted semantic runtime; TB50-R2 **508/0** is the prior independently reviewed candidate. This **831/0 TB-EXEC result is only a candidate pending independent Review**. Do not promote frozen selector 497, assert CP3 acceptance, or start RP-01 repair.

## Next authority

Per [RA-172.7](Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md) and the verified `postflight=true`/831-row outcome, the only authorized successor is **`M6-CP3-TB51-RP01-FULL-GATE-REV`** (independent TB-REV, Review track). The successor must independently verify this artifact, assess the unchanged 85-row deferred ledger and 916-row union, and decide candidate-gate disposition; it must not be executed inside TB51-EXEC.

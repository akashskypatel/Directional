# TB52C — API binary census execution (2026-10-30)

**Turn:** `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-EXEC` (TB-EXEC, implementation track). Exact authority: RA-174.5/.6; previous CB53 P8 harness. **No semantic classification or acceptance decision in this turn.**

## Immutable authority

- Repository `akashskypatel/Directional`, working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft at entry.
- Source package: CB52 SHA `7cf0857b4818186638ce77e4859adacbeebd288f`, artifact `12918290481`; outer ZIP SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`, root manifest SHA-256 `6ae4eb5bf9552912fe068d9a9d3a90d76e2e27b9bd99896f83c216fd27fbc21f`, archived source SHA-256 `c02a0be4b25d64eca2c10e5681cd8721a465a848a3d17044275370eac132553b`.
- Executor checkout: `f9625d7d1cd1f1a072ffc02e126f266696736895`, harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Frozen manifest: `Architecture_M6_CP3_TB52C_API_Binary_Census_Case_Manifest.tsv` SHA-256 `81395065279e6ae6590c6feea30b719d661a328ecd90bea7ad8ef0f3a3a474ed`, 23 `OBSERVE` rows exclusively in `directional_compiled_api_tests`; deliberately **no** `MEMBERSHIP_LEDGER`.
- Dispatch event `555b5cd34ee361c72e4caaa9f2cbbf8af36d917f`; request/mailbox `m6-cp3-tb52c-api-binary-census-20261030-v1`; [run 41064596683](https://github.com/akashskypatel/Directional/actions/runs/41064596683), runtime job `124092773852` success. Result artifact `12981972265`, ZIP SHA-256 `bab1be73ce6ad4718fe2b4dc0c2a16d6ada43faf167737414fb6f7294605d845`; log artifact `12982352433`, ZIP SHA-256 `b482fc2ecf06c101596fc3dbd5bcb9a0dca7985bc0759a7ad02f0db81bf68b0a`.
- Executor source snapshot: run `41064162933`, artifact `12981797129`, ZIP SHA-256 `63bf549771dae94645380205a40988fb718ce19ef4fbf3277ef0cba844186b22`; `5992/5992` file checksums verified.

## Observed census (no classification)

- 23/23 fresh single-filter processes; **22 PASS / 1 RED / 0 ABNORMAL / 0 INVALID**; postflight `true`; result 49/49 checksum members verified. RED `apicensus:19`, `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported`, exit 1, first failure `tests/SurfaceCellTracingDisplayTests.cpp:107` (`vertexLocus.sourceVertex.has_value()` false, expected true). Observation only; independent Review decides disposition.
- Row 19 native assertion: `Value of: vertexLocus.sourceVertex.has_value()` / `Actual: false` / `Expected: true`, followed by `tracing`. Raw log `raw/19.log`, SHA-256 `c1ff3c3e0e681b630cc9d33577bb3965dd2e46f32e4f2909c76e837939ff3354`.
- Other 22 rows: PASS, exit 0, one selected run and one successful test each. All 23 rows have `run=1`, `skipped=0`, unique identity and a raw log SHA-256; no missing, duplicate, or control violation.
- `execution-boundary.json`: `planned=23`, `executed=23`, `passed=22`, `red=1`, `abnormal=0`, `control_bad=0`, `postflight=true`, `exit=0`; `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Result `SHA256SUMS`: **49/49 PASS**, including 23 raw test logs and 23 resource files.
- All 23 ordered manifest `row/kind/identity/test/binary` columns join exactly to `ledger.tsv`. The RED is permitted by observational `OBSERVE` contract; an exit-0 harness does not imply the test passed.

## Boundary and disposition

No native build, relink, configure, benchmark, source/test/fixture/manifest/ledger change, retry, gate promotion, or CP3 acceptance. No new stable regression classification claimed; existing totals **66/17/49**, debt **1**, CP2 **491/491** accepted and TB51 **831/0** reviewed candidate are unchanged pending the independent review. The 85 deferred rows are unaffected.

Postflight is true with all 23 rows, so the authorized **separate next turn** is `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-REV` (TB-REV). That review must independently classify the RED and freeze the five-binary gate/ledger v2. Do not start it in this TB-EXEC turn.

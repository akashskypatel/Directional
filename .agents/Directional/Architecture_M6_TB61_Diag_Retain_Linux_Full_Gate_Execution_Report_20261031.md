# M6 TB61 — DIAG-RETAIN Linux full-gate execution (2026-10-31)

**Turn:** `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC` (TB-EXEC; implementation agent). The separately authorized independent review is `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV`. This is execution evidence, **not** independent semantic acceptance or promotion of CP3.

## Immutable authority

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft/unmerged.
- CB62 Linux Release/static GMP/GMPXX package artifact: `13034987618`; semantic source/executor SHA: `e7c27b0a5f53788569109c85a028e3be44035aaf`.
- CB62 package outer ZIP SHA-256: `81c66418420b64c466e4b6c89d79129ef8ba4adbe6981469624d781644d91de5`; root `SHA256SUMS` SHA-256: `48d4bf626737980e2deb4f37c4b1bfee47a1644a06a034186198be70454d4870`; source-archive SHA-256: `88653f43f67cd413c38b63cbebed376dca78405de2c0c22dc21d4a0143a72fce` (CB62 record).
- Harness: `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Frozen manifest: `Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`, 863 rows, SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`.
- Frozen deferred ledger: `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv`, 82 rows, SHA-256 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`.
- Dispatcher request commit: `87f39c25556d13658bb0921c430d485d9bd76563`; request ID/mailbox key `m6-tb61-diag-retain-linux-full-gate-20261031-v1`.
- [GitHub Actions run 41182654107](https://github.com/akashskypatel/Directional/actions/runs/41182654107), attempt 1; workload job `124483123828`; Ubuntu 24.04 Linux. Workload start `2026-10-31T07:58:22Z`; finish `2026-10-31T09:09:22Z`. All validation, runtime and mailbox publication jobs succeeded; compile, drive_apply and noop branches were skipped.

## Execution and result

| Metric | Measured |
|---|---:|
| Planned/executed/pass | **863 / 863 / 863** |
| RED / abnormal / missing / skipped / duplicate | **0 / 0 / 0 / 0 / 0** |
| Unexpected pass / later-positive-red / red-site-bad / bad controls | **0 / 0 / 0 / 0** |
| Gated membership | **863** |
| Deferred membership | **82** |
| Total exact membership | **945** |
| Gated GUARD / POSITIVE | **854 / 9** |
| Postflight / harness exit | **true / 0** |

The frozen 863-case gate ran to its organic completion. No compilation, configuration, relinking, benchmark, source/test/fixture mutation, or fallback repair occurred inside the TB run; see `execution-boundary.json` (`compile=false`, `relink=false`, `configure=false`, `benchmark=false`). Execution evidence is specific to the five packaged test binaries and cannot establish CLI/GUI build portability or manual GUI presentation.

The local independent evidence audit verified: all 1,734 archived result-file checksums, all 863 case identities/order/verdicts against the frozen manifest, each case's recorded raw-log SHA-256 and `[  PASSED  ] 1 test.` receipt, absence of `[  FAILED  ]`, and exact disjoint 863 GATED + 82 DEFERRED membership. The zipped result/log artifacts match the mailbox outer digests.

### Required comparator observations

- **Row 283 / `selector:241`** (`SurfaceCellsPhase10.LegacySyntheticOutputHashIsStableAcrossTenRuns`) PASS on Linux. The macOS TB60 report records this as the sole RED at `segment_arrangement(): surviving twin has invalid next` (O16). This platform difference remains owned by the separately carried macOS O16 issue; it is **not** proof the defect was fixed, nor grounds for changing the stable regression accounting.
- **Rows 854–863:** all ten PASS, respectively RP-01 (854–855), O15 (856–857), census row 935 (858), O2 (859), A5–A7 snapshot preservation (860–861), and retained/absent display adapter products (862–863).
- Against TB60's reported 862/863, every row of the Linux gate is PASS and the only differing reported outcome is row 283; complete TB60 raw result bytes were not independently downloaded in this turn. The comparison is limited to the TB60 report's authority.

## Evidence artifacts

- Result ZIP: `13037097822`, outer SHA-256 `5e62807c270d9124688dd280a0af718900f5bbabd4ec678107745ca1a648acc8` (includes `ledger.tsv`, `membership.tsv`, `execution-boundary.json`, raw per-case logs, `SHA256SUMS`).
- Harness diagnostic log ZIP: `13037416966`, outer SHA-256 `ac72010d7d1499e2f2259718e553fd5d142d9e72f37aac5a7e269639f603c135`.
- Reusable wrapper diagnostic log ZIP: `13037536687`, outer SHA-256 `8a94bcac79bd0455e99406542b951fb791fa7d6046f5ee41700c8b6a08dd333d`.
- Mailbox: `.workflow-mailbox/m6-tb61-diag-retain-linux-full-gate-20261031-v1/latest.json` **on ref `workflow-mailbox` only**, `run_id=41182654107`, `event_sha=87f39c...`, `source_sha=e7c27...`, result success; authoritative records preserved.

## Disposition / review boundary

The pre-registered Linux TB61 gate outcome is satisfied (**863/863 PASS**). The TB-EXEC turn may close to the **existing authorized successor** `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV`; the successor independently examines rows 854–863, the TB60 platform comparison, package/evidence completeness, and whether separate Linux CLI/GUI compile evidence is owed before authorizing `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`. Existing stable **66/17/49**, debt **1**, and last accepted CP2 **491/491** remain unchanged pending review. No new regression or candidate arose on the Linux run; the historical macOS O16 issue remains open. PR #8 remains draft and unmerged. No P13 work was started.

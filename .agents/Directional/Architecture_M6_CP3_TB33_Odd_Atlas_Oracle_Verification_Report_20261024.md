# M6 CP3 TB33 — immutable odd-atlas oracle verification (2026-10-24)

**Canonical turn:** `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION`. **Disposition:** artifact-only Test + Benchmark COMPLETE as measured; **candidate/non-stable** until a separate independent TB33 Review. No product or M6-CP3 gate acceptance.

## Immutable authority

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft; immutable compiled semantic source `30e46b9aabc44925643f46bab20db40962a5e494`.
- CB32 compile-only package: artifact `12541198172`, archive SHA-256 `17a121aac12d288892853a2455d3f72411a5538eeda512a7d2c9c096a7d47651`. Package contents verified **28/28** SHA256SUMS; source archive `9e0e0d7dfcfb6a0694da90bd162a58e94f3df9e912564c2dd800609db46ccf8b`; root manifest `a0f22243571ce3a1ed6de752895633275eba64f01b40dd9d5527f1ddb8c92354`. Packaged metadata records eight-target GMP/GMPXX compile and `runtimeExecution=false`.
- Selector manifest: `.agents/Directional/Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Cases.tsv`, SHA-256 `09c0d0650803397d80868b289faff14f1d068863e00dfe06311d1e77d69ef872`, exactly six independently prescribed identities. Reused targeted artifact harness SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`; built-in synthetic self-tests 12/12 and manifest self-check 6/6 (no Directional runtime locally).
- Immutable GitHub Actions [run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120), executor dispatch commit `00b721672fcf104abcca6ffdd655e41b6fbd01f8`, source/package SHA pinned separately; exact positive/negative/guard selectors executed from packaged `directional_surface_cell_producer_tests`. Reusable workload and mailbox jobs completed successfully.
- Result artifact **`12543546779`**, ZIP digest **`217f6b214707b4165252a23537284f5aa6ebf242e2de1d8b691774d35272c09d`**, **15/15** result SHA256SUMS verified; separate diagnostic log artifact `12543202991`, ZIP digest `03771da4fa9f2463af42f0853f271b33122fef66473b3b8ede8c53ff3d519528`.

## Measured six-process result

| Case | Exact frozen identity | Result |
|---|---|---|
| Odd raw signed transport, row/corner permutations | `TB33:odd-signed-transport` | PASS |
| Stale face-gauge vector rejection | `TB33:stale-face-gauge` | PASS |
| Wrong directed inverse rejection | `TB33:wrong-directed-inverse` | PASS |
| Missing gauge factory control | `TB33:missing-gauge-control` | PASS |
| One-face tampered-gauge control | `TB33:one-face-gauge-tamper-control` | PASS |
| Uniform gauge shift invariance control | `TB33:uniform-gauge-shift-control` | PASS |

Machine `execution-boundary.json`: `planned=6`, `executed=6`, `passed=6`, `red=0`, `missing=0`, `skipped=0`, `duplicate=0`, `control_bad=0`, `unexpected_pass=0`, `postflight=true`, `exit=0`, `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. Every independent GTest log selects exactly one named test, reports one `[ RUN ]`, one `[ OK ]`, and one `[ PASSED ]`; all per-log SHA-256 values independently checked against the immutable result manifest and `ledger.tsv`.

The tests include assertion sites for raw odd branch `3/1`, topology-keyed gauge remapping, and expected negative canonical rejection at `gauge-pin-consistency;edge=0,2`; the passing raw logs report test outcomes but **do not independently print per-assertion guard-site measurements**. Independent Review must confirm source-to-log non-vacuity and resist treating ledger `first_failure=failure-line-not-observed` on a passing test as a measured negative first-failure site.

## Scope and regression classification

- This is runtime evidence for **synthetic odd-atlas/checked-factory oracle scope** only, not a pipeline-produced periodic front/holonomy, A5/A6, G4-B002, D0 production, or full CP3 acceptance. No six previously recovered `selector:220,221,296,302,304,439` runs repeated; TB32's 481/500 candidate remains distinct.
- **Zero observed TB33 regression/invalid case** in these six identities; no basis for new stable regression ID or event totals. Frozen `497` selector, TB32 reviewed 481/500 candidate / 19 inherited RED, CP2 **491/491 accepted**, stable **66 events / 17 categories / 49 recurrences**, debt **1**, CP3 unaccepted, RP-01 open and RP-02 unreached all unchanged. Prior 19 REDs were not executed by TB33 and cannot be reported as recovered.
- No target/product/test-source/fixture/frozen-selector edits, package repairs, compilation, relinking, configuration, benchmark or direct production execution in this turn; only the new **TB33 case-manifest control file** and dispatcher request were committed to trigger artifact-only execution. The manifest neither changes existing test code nor binary.
- Required next boundary is an **independent TB33 Review**; its exact canonical identifier is not assigned by existing authority, therefore `UNKNOWN`. Do not start Review during TB33.

## Evidence and falsifiers

Independent reviewer should reproduce the 15 packaged result hashes and six `ledger.tsv` ↔ `raw/N.log` joins, examine the unchanged CB32 source and source-derived expected signed transport, verify negative guard path actually reached, and confirm the `postflight` unchanged package. A missing, duplicate, vacuous or misclassified test, a mismatched checksum/source/manifest, unobserved required guard reachability, or any change in prior 19 RED ownership falsifies a stronger claim. The next Review alone may decide promotion.

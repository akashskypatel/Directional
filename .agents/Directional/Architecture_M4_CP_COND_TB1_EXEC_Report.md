# M4-CP-COND-TB1 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-COND-TB1-EXEC`
**Disposition:** COMPLETE / PACKAGE PREFLIGHT RED / ZERO SEMANTIC TEST CREDIT / SEMANTICALLY UNADJUDICATED
**Mandatory successor:** `M4-CP-COND-TB1-REV`
**Runtime authority after this EXEC:** unchanged; accepted M4 runtime authority remains CP3 CB10 artifact `10307919492` / selector408 `408/408` pending Review.

## 1. Frozen candidate authority

TB1 consumed only the immutable CP-COND-CB1 compile package:

- semantic source: `b576d061e23873b7b4193b158138d2097c75a728`
- compile run/job: `34740201494 / 103678514188`
- immutable candidate package artifact: `10312168742` (`m4-cp-cond-cb1-result-34740201494`)
- package/provider/download ZIP SHA-256: `90c5e4c8bd41ced2311d11e1cb1e03cfd6dc71542c862981363aa31df2c03265`
- packaged source archive SHA-256: `31e667a6891f9f9d2c938da98c7d23d048c3d60f6960e139e379631e7aa70c10`
- root `SHA256SUMS`: 24 entries, SHA-256 `fdaf919a29eb77a99fea6f672f158010f664ec2580f4f62f04729c0217648f89`, all verified
- compile preflight/build exit: `0 / 0`
- source-status snapshots: empty
- exact-arithmetic evidence: GMP/GMPXX present
- compile boundary: `runtimeExecution=false`

The accepted selector remained byte-frozen at 408 LF rows with SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.

## 2. Authoritative execution attempt

The authoritative bounded TB1 attempt is:

- workflow run: `34757021728`
- execution job: `103723061754`
- event/control SHA: `95ad8b2fcecb621b34643694e1e9b64cc4bf66cd`
- result artifact: `10317417085` (`m4-cp-cond-tb1-result-34757021728`), provider/download SHA-256 `2886414c821790721a64c0a026444772e3eee44bf983f30b1d787c385cfcfb74`
- log artifact: `10317147479` (`m4-cp-cond-tb1-log-34757021728`), provider/download SHA-256 `80b38896305af1df6bd6602351733a0899b6a01bdcc9dd52ab72f0b41fac8668`
- harness SHA-256: `34d0445e9575ffa0a68009017cee8521699afd8bcfacaf7fa4da9ec9249cca84`

Schema validation for the corrected caller completed GREEN in run/job `34756988581 / 103722948338` before the retry caller was published.

The earlier attempt `34756902324 / 103722735152` is excluded from semantic evidence. Its payload was created through the Contents API with mode `0644`, while the caller attempted direct execution. It therefore stopped before the harness started with exit `126 / Permission denied`; no Directional process ran and no result artifact was created. Its log artifact is `10317083888` with ZIP SHA-256 `e86488d65ceae04f07247d56df8f265dc5f8ecb5a949ab001a856365f62effd8`. The bounded correction changed only the caller invocation to `bash "$harness"`; it did not alter or repair immutable package permissions.

## 3. Package preflight result

The authoritative retry verified the immutable artifact identity, root checksums, semantic source, empty source status, GMP/GMPXX evidence, compile `runtimeExecution=false`, source archive, and selector408 before any Directional process.

Static ownership resolution from the packaged source maps the 408 accepted selector identities as follows:

| Required owner executable | Accepted selector identities | Packaged? |
|---|---:|---|
| `directional_surface_cell_authority_kernel_tests` | 30 | **NO** |
| `directional_surface_cell_producer_tests` | 262 | YES |
| `directional_surface_cell_completion_tests` | 75 | **NO** |
| `directional_surface_cell_validation_tests` | 41 | **NO** |
| **Total** | **408** | 262 identities have a packaged owner binary |

The immutable CB1 package therefore omits three required selector408 owner executables covering **146 accepted identities**. The TB1 plan requires the complete accepted selector408 census and explicitly makes any package/preflight mismatch a fail-closed package RED with zero semantic test credit. No package repair, rebuild, relink, generated discovery, or subset substitution is authorized in TB1.

Focused ownership itself is internally coherent: all 14 focused prospective CP-COND gates plus the one report-only boundary identity resolve uniquely to `directional_surface_cell_producer_tests`. That does **not** permit their execution after the complete-package preflight has failed.

## 4. Frozen execution boundary

The authoritative result records:

```text
script_exit=91
runtime_started=false
runtime_completed=false
preflight_completed=false
postflight_completed=false
package_preflight_red=true
orchestration_failure=false
selection_integrity=true
expected_focused_gates=14
expected_report_only=1
expected_selector_gates=408
processes_executed=0
pass_count=0
red_count=0
skip_count=0
crash_count=0
selection_mismatch_count=0
stop_kind=PACKAGE_PREFLIGHT_RED
stop_detail=immutable CB1 package omits 3 required selector408 owner executable(s)
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
source_test_fixture_selector_mutation=false
```

Accordingly, TB1 yields **0/422 semantic gating processes executed**: none of the 14 focused prospective gates and none of the 408 accepted selector identities ran. The report-only boundary identity also did not execute. There is no PASS, RED, SKIP, crash, or selection result for any Directional identity in this turn; the only authoritative outcome is package preflight RED.

## 5. Immutability

The result artifact records exact equality across the package, packaged source, and copied execution view even on the fail-closed path:

```text
package_census_equal=true
source_census_equal=true
execution_view_census_equal=true
```

No immutable package/source/test/fixture/selector byte was changed, and no configure, compile, relink, benchmark, generated discovery, or package repair occurred.

## 6. Regression/root-cause routing

`M4-CP-COND-TB1-EXEC-CAND-01` is opened mechanically as **PACKAGE-COMPLETENESS PREFLIGHT / NON-STABLE / REVIEW REQUIRED**. The directly observed defect is limited to evidence packaging: CB1 compiled/packaged only `directional_surface_cell_producer_tests` and `directional_compiled_api_tests`, while its frozen TB1 plan requires all four selector408 owner executables to perform the accepted 408/408 census.

No Directional identity executed, so there is no accepted-prefix PASS→RED transition and no evidence for a new stable event. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**, until Review independently adjudicates the candidate. EXEC does not assign a permanent root-cause category, promote/reject product semantics, or alter selector authority.

## 7. EXEC boundary and mandatory successor

`M4-CP-COND-TB1-EXEC` is mechanically **COMPLETE / PACKAGE PREFLIGHT RED** and semantically unadjudicated. The frozen plan forbids repairing or rebuilding the candidate package inside TB1. Exact next is therefore mandatory `M4-CP-COND-TB1-REV`.

Review must independently re-open the immutable result/log artifacts, adjudicate `M4-CP-COND-TB1-EXEC-CAND-01`, and decide the minimum corrective Code + Build scope. CP-COND remains OPEN. Accepted CP3 runtime authority, selector408, A3/A4 semantics, stable accounting, and carried debt remain unchanged.

## 8. Tool-use ledger note

The turn-local exact tool-call counter was not preserved through conversation-state compaction. Per `TOOL_USE_CONSERVATION_POLICY.md`, it is reported as **partial/unknown rather than reconstructed or guessed**. No additional tool calls are authorized solely to recover that count. Material extra calls arose from the excluded pre-runtime mode-bit orchestration failure and its schema-validated bounded correction.

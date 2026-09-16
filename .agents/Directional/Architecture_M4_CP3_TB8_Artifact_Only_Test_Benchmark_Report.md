# M4-CP3-TB8 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP3-TB8-EXEC`
**Disposition:** COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED
**Successor:** `M4-CP3-TB8-REV`
**Runtime authority after this EXEC:** unchanged pending Review; corrected R4 artifact `10289601000` / selector403 `403/403` remains accepted.

## 1. Frozen candidate authority

TB8 consumed the immutable CB10 candidate package only:

- semantic source: `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`
- compile run/job: `34727247774 / 103643462175`
- candidate package artifact: `10307919492` (`m4-cp3-cb10-result-34727247774`)
- candidate package/provider ZIP SHA-256: `8988a12fa8b2e6476bf3fd91a6a6936eaef8a9ab7c73837b74ea2e980d29b2ec`
- packaged source archive SHA-256: `1ff187c6c08d13f5be5e6481f5323541e48fc93e6ffc0ada78af73a7926c205d`
- package root `SHA256SUMS`: 28/28 entries verified
- source status: empty
- exact arithmetic backend evidence: GMP/GMPXX present
- compile package boundary: `runtimeExecution=false`

The byte-frozen selectors were unchanged:

- selector403: 403 rows, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`
- selector408: 408 rows, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
- selector408 first 403 rows: exact match to selector403

The static owner map resolved all 408 identities with distribution:

| Owner executable | selector408 | first403 |
|---|---:|---:|
| `directional_surface_cell_authority_kernel_tests` | 30 | 30 |
| `directional_surface_cell_producer_tests` | 262 | 257 |
| `directional_surface_cell_completion_tests` | 75 | 75 |
| `directional_surface_cell_validation_tests` | 41 | 41 |

## 2. Execution authority

Authoritative execution:

- workflow run: `34729562893`
- execution job: `103649745950`
- event/control SHA: `7fa6af1f18bc5c804e974231234c1c23760f8490`
- result artifact: `10309365777` (`m4-cp3-tb8-result-34729562893`)
- result artifact provider/download SHA-256: `a8d91cd62cb2c633ed46ab963a13060e903a5043d3941fdea6aaec9c77091c04`
- log artifact: `10309009858` (`m4-cp3-tb8-log-34729562893`)
- log artifact provider SHA-256: `c7a7cf9e32269b85afde621c18799f49f9ad815ed9b7fb2eedd066f102275772`
- process ledger SHA-256: `2700e511a12505dbaf87b87d00bed7f2d2b73e65dd38adb1934682cb72abf63d`

The bounded TB8 harness used by the authoritative run had SHA-256 `600d48029adbce345b10867b1cec0b4377e1783a2624de76ada648c535bdca23`. It did not wrap individual runtime processes in a repository/job timeout. Every identity was invoked as an exact-filter fresh process.

Three earlier orchestration attempts are excluded from semantic/runtime evidence because they failed before Directional runtime with a generated-shell unmatched-quote error:

- `34729051005 / 103648364992`
- `34729138219 / 103648603187`
- `34729277163 / 103649042249`

They carry **no test credit** and are not stitched into the authoritative ledger.

## 3. Frozen execution boundary

The authoritative result records:

```text
script_exit=0
runtime_started=true
runtime_completed=true
preflight_completed=true
postflight_completed=true
orchestration_failure=false
selection_integrity=true
processes_executed=835
pass_count=835
red_count=0
skip_count=0
crash_count=0
selection_mismatch_count=0
stop_kind=NONE
benchmark_execution=false
configure_execution=false
compile_execution=false
relink_execution=false
generated_discovery=false
package_repair=false
source_test_fixture_selector_mutation=false
```

No compile, configure, relink, package repair, generated discovery, benchmark execution, or source/test/fixture/selector mutation occurred in the authoritative TB8 runtime.

## 4. Mechanical runtime result

All prescribed phases completed:

| Phase | Scope | Processes | Mechanical result |
|---|---|---:|---:|
| A-shared-A | six corrected shared-fixture identities, pass A | 6 | 6/6 PASS |
| A-shared-B | same six identities, pass B | 6 | 6/6 PASS |
| B-ordinal138-A | accepted ordinal138, pass A | 1 | 1/1 PASS |
| B-ordinal138-B | accepted ordinal138, pass B | 1 | 1/1 PASS |
| C-row408-A | candidate row408, pass A | 1 | 1/1 PASS |
| C-row408-B | candidate row408, pass B | 1 | 1/1 PASS |
| D-controls-A | rows404-407, pass A | 4 | 4/4 PASS |
| D-controls-B | rows404-407, pass B | 4 | 4/4 PASS |
| E-selector403 | accepted selector403 to completion, semantic fail-fast disabled | 403 | 403/403 PASS |
| F-selector408 | cumulative selector408 | 408 | 408/408 PASS |
| **Total** |  | **835** | **835/835 PASS** |

The complete accepted selector403 RED census is empty. The result artifact's `semantic-red-census.tsv` contains only its header. No process was skipped, crashed, or selection-mismatched.

The six corrected shared-fixture identities are mechanically green in both A/B passes:

1. `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`
2. `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`
3. `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected`
4. `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed`
5. `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed`
6. `SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity`

The candidate tail rows 404-408 are also mechanically green in the dedicated A/B discriminator phases and again in cumulative selector408 execution.

## 5. Immutability

Postflight records exact equality for every frozen execution surface:

```text
package_census_equal=true
source_census_equal=true
execution_view_census_equal=true
```

The package, packaged source, and copied execution view remained byte-identical and executable-mode-identical across runtime. No mutation is admitted by TB8 evidence.

## 6. EXEC boundary and mandatory successor

`M4-CP3-TB8-EXEC` is **mechanically green**. It does not classify root cause, close candidates, alter stable-event accounting, or promote the CB10 package. Those decisions are explicitly reserved for `M4-CP3-TB8-REV`.

Until Review adjudicates the immutable TB8 evidence:

- corrected R4 artifact `10289601000` / selector403 **403/403** remains accepted M4-CP3 runtime authority;
- CB10 package `10307919492` remains candidate/unpromoted despite the mechanically green TB8 execution;
- stable accounting remains **49 events / 14 categories / 35 recurrences**;
- produced-witness debt remains **5**;
- CP3 and `G4-B002` remain OPEN.

**Exact next turn:** `M4-CP3-TB8-REV`.

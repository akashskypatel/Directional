# M4-CP3-TB6 Artifact-Only Test + Benchmark Report — VALID RED at accepted selector403 ordinal 138

**Turn:** `M4-CP3-TB6-EXEC`
**Status:** COMPLETE / VALID RED / REVIEW REQUIRED
**Turn type:** Test + Benchmark / immutable artifact-only
**Candidate semantic source:** `6934d9edfb56b44f956fbc64a89a501aaed042af`
**Candidate package:** artifact `10303165017`, SHA-256 `d601e5efc4d6a3cafc34d4a5ead0a5a44040e3026d31b3f75afad59c71b68112`
**Accepted entering authority:** R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Mandatory successor:** `M4-CP3-TB6-REV`

## 1. Execution disposition

The authoritative execution is retry run/job `34711826087 / 103601868455`. Immutable preflight completed before generated Directional runtime and postflight completed after fail-fast termination.

- focused row408 recovery: **2/2 PASS** in two fresh exact-filter processes;
- rows404-407 controls: **8/8 PASS** in eight fresh exact-filter processes;
- selector403: ordinals **1-137 PASS**, ordinal **138 RED**;
- selector408 cumulative phase: **not reached** by the frozen fail-fast rule;
- total generated semantic processes: **148** = 147 PASS / 1 RED / 0 SKIP / 0 crash / 0 timeout / 0 selection mismatch;
- every generated process selected exactly one expected identity;
- `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `benchmark_execution=false`, `generated_discovery=false`, `package_repair=false`, `source_test_fixture_selector_mutation=false`.

The first execution attempt `34711705866 / 103601564723` has **no semantic credit**. It ran zero generated Directional processes and stopped during preflight because the reused TB5 harness expected `metadata/preflight-target.txt=directional_surface_cell_producer_tests`, while the frozen CB8 full-package artifact correctly records `directional_core`. The control-only retry changed only that metadata expectation; package/source/test/fixture/selector bytes were untouched.

## 2. Immutable package and selector authority

Preflight re-proved the exact package and execution controls:

- downloaded artifact SHA-256 exactly `d601e5efc4d6a3cafc34d4a5ead0a5a44040e3026d31b3f75afad59c71b68112`;
- root `SHA256SUMS` **28/28 PASS**;
- packaged source commit exactly `6934d9edfb56b44f956fbc64a89a501aaed042af`;
- source archive SHA-256 exactly `7b906b0ad1560d3cb158178ae224d2d391e8fee66d7268f78ba2ed172a0ec5eb`;
- all packaged source-status snapshots empty;
- GMP/GMPXX evidence present and compile metadata remains `runtimeExecution=false`;
- selector403 remains 403 LF identities at `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- selector408 remains 408 LF identities at `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`, first403 byte-identical;
- owner partition remains **30 authority-kernel / 262 producer / 75 completion / 41 validation**.

Postflight re-proved `package_census_equal=true`, `source_census_equal=true`, and `execution_view_census_equal=true`.

## 3. Focused CB8 recovery is runtime-proved

Both fresh executions of

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

PASS. The frozen row408 contract therefore now reaches A4 `Produced` under the exact 18-edge effective HardFeature witness while retaining the A1/A2a/A2b/A3 topology/baseline authority and exact A3 shared-boundary interval contract. Rows404-407 also pass twice, so the immediate CB8 recovery discriminator and its four predecessor controls are green.

This is runtime evidence only. EXEC does not promote candidate selector408, close `M4-CP3-TB5-REV-CAND-01`, or close CP3 / `G4-B002`.

## 4. Earliest cumulative RED

The first cumulative failure is accepted selector403 ordinal **138**:

`SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`

The process selected exactly one identity and exited normally with GTest failure. The unchanged test expected the historical all-producers-declined contract:

- `surfaceCellFirstInvalidProducerReason == "UnsupportedSourceSheetTopology"`;
- `surfaceCellUniformPhaseFrontProducerDeclined == true`;
- `surfaceCellPeriodicPhaseFrontProducerDeclined == true`;
- `surfaceCellBoundedDiskPhaseFrontProducerDeclined == true`.

The CB8 candidate instead reports:

- `surfaceCellFirstInvalidProducerReason == "InvalidFrontBoundaryAuthority"`;
- all three producer-declined flags are `false`.

The failing fixture's region-support diagnostics remain finite and deterministic. TB6-EXEC does **not** decide whether ordinal138 is a stale accepted negative contract made obsolete by the typed occurrence-domain correction, a compatibility regression in fail-closed producer disposition, or evidence that CB8 widened its applicability beyond the reviewed seam. That classification belongs to Review.

## 5. Evidence artifacts

Authoritative run `34711826087` produced:

- result artifact `10303393457`, SHA-256 `db5770d212befb593d9dd3003c7a399432f4fed4d43aa4b306c117274c21d1d1`;
- diagnostic log artifact `10303657623`, SHA-256 `a3297a070dfd340a177287a59efc9f717210425659cf06c539b6321bccc33239`.

The result contains the 148-row process ledger, immutable pre/postflight censuses, selector/owner authority, artifact authority, raw per-process logs, resource logs, and the exact fail-fast boundary. The ledger SHA is preserved inside the result bundle.

The zero-runtime orchestration attempt `34711705866` produced result/log artifacts `10303730596 / 10303915027`; it is retained only as control-plane history and has no semantic authority.

## 6. EXEC disposition and mandatory Review questions

`M4-CP3-TB6-EXEC` is **COMPLETE / VALID RED**. No package or selector is promoted. Accepted runtime authority remains corrected R4 artifact `10289601000` / selector403 **403/403**. Stable accounting remains **47 events / 14 categories / 33 recurrences**, produced-witness debt **5**; CP3 and `G4-B002` remain OPEN.

`M4-CP3-TB6-REV` must independently re-open the immutable evidence and source, then:

1. confirm row408 **2/2** and rows404-407 **8/8** really prove the intended CB8 occurrence-domain recovery;
2. re-derive ordinal138's historical premise and determine whether the negative contract is stale, product semantics regressed, or CB8 exceeded its reviewed applicability seam;
3. decide the disposition of `M4-CP3-TB5-REV-CAND-01` and whether a bounded successor CB is authorized;
4. preserve selector403 accepted authority unless Review has sufficient evidence to explicitly adjudicate otherwise;
5. do not spend selector408 continuation processes or promote the candidate from this partial cumulative gate.

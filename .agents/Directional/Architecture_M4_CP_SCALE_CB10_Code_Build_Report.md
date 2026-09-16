# M4-CP-SCALE-CB10 — S4 Test-Authority Correction Code + Build Report

**Turn boundary:** Code + Build only. No Directional runtime, test, benchmark, discovery, help, list, or version command was executed.

## Outcome

`M4-CP-SCALE-CB10` is **COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME UNADJUDICATED**.

The semantic evidence source is `bebb14e32a0ac53dd420acf46bfa34410cf759a1`. Its only semantic file change is `tests/FieldAlignedCurveNetworkTests.cpp`; product source, A2a' cut selection, final certificate semantics, fixtures, CMake semantics, and selector425 remain unchanged.

The corrected prerequisite now binds the production-reachable empty-cut negative to the retained torus authority instead of the prescribed-sphere counts:

- empty-cut raw graph: `V=48`, `E=48`, independently observed complement components `F=4`, graph components `c=4`, source components `s=1`, source `chi=0`;
- each of the four complement components is an annulus (`boundaryWalkCount=2`, component Euler characteristic `0`), not a disc;
- `b1 = E - V + c = 4`, so the necessary cellular face count is `F_required = chi - s + b1 = 3`; observed `F=4`, therefore the early oracle rejects;
- the invalid off-domain equality between independent complement-component count and product face-walk-orbit `faceCount` was removed;
- the final-authority relation is one-way: when the early necessary-condition oracle rejects, the unchanged final certificate must also reject.

The known-good accepted-cut control remains `V=72`, `E=76`, `F=4`, `c=1`, `s=1`, `b1=5`, `F_required=4`, non-rejecting, with a cellular final certificate. The deterministic one-edge adversarial subject uses the same one-way implication. Reversed accepted-cut enumeration must preserve the canonical topology state, and a fresh production rerun after all diagnostics must reproduce cuts, certificate, semantic digest, and provenance digest.

Subject failures are no longer allowed to hide later controls merely through assertion ordering. Subject availability and outcomes are emitted in one terminal `m4CpScaleS4Prereq` receipt; subject assertions are nonfatal where later controls must remain observable. Setup failures still fail the test and absence of the final receipt is itself visible runtime evidence.

## Compile evidence

### Changed-owner preflight

- run/job: `35114377792 / 104856007410`;
- exact semantic source: `bebb14e32a0ac53dd420acf46bfa34410cf759a1`;
- preflight target: `directional_surface_cell_producer_tests`;
- result artifact: `10453409035` / `m4-cp-scale-cb10-preflight-result-35114377792` / provider SHA-256 `6c751dc1b9cf715b9cf9b54447ac969f8c2b853278e241b770d54b06f1adc672`;
- log artifact: `10453568143` / provider SHA-256 `45c9070a324e7aff8c1fbd8051efc5f94b5f522e79036d4d3f30bb9df4705c9d`;
- compile/link succeeded; `runtimeExecution=false`; source-status receipts are clean; GMP and GMPXX are linked.

### Full standard package

- run/job: `35116725106 / 104863990686`;
- exact semantic source: `bebb14e32a0ac53dd420acf46bfa34410cf759a1`;
- result artifact: `10455353524` / `m4-cp-scale-cb10-package-result-35116725106` / provider SHA-256 `b891318511ef6db2f6317abac99a4b7e1511fe6d4ebc58bdd048cdc49a757de9`;
- compile log artifact: `10454998700` / provider SHA-256 `f348ece1953033d95e2bafa1517d56d2a12ca420b07f0b0a6ba30ffbc80248d6`;
- packaged source archive SHA-256: `884ff6703f290df8b3479e35945cb3dc29b0732e3810eb66528759721d8366ae`;
- package root `SHA256SUMS`: fully verified;
- compile and preflight exit codes: `0 / 0`;
- source-status receipts: empty before configure, after configure, after build, and final;
- exact backend: GMP with generated link evidence containing both `libgmpxx.so` and `libgmp.so`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

Compiled targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No packaged executable was run during this turn.

## Frozen selector and accepted runtime authority

Selector425 remains exactly 425 unique LF rows at SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, with the exact first-424 prefix SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`. Owner census remains **30 authority-kernel / 279 producer / 75 completion / 41 validation**. No selector426 exists or is authorized by CB10.

CB10 supplies compile evidence only. Accepted runtime authority therefore remains TB7 package `10425344367` / semantic source `01b1124af094044e32d6887ff0615881333d12ce` / selector425 **425/425 PASS**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

`M4-CP-SCALE-DEFN-OBS-03` is now **TEST AUTHORITY CORRECTED + COMPILE GREEN / FRESH RUNTIME + REVIEW OWED / NON-STABLE**.

## Successor

The exact next boundary is `M4-CP-SCALE-TB9-EXEC`, governed by `Architecture_M4_CP_SCALE_TB9_Artifact_Only_Test_Benchmark_Plan.md`. It must consume immutable artifact `10455353524` without rebuild or repair, execute the focused S4 prerequisite first, fail fast on any focused defect, and only then execute selector425 in 425 fresh exact-filter processes. `M4-CP-SCALE-TB9-REV` is mandatory after execution before any S4 prerequisite credit, observation discharge, production semantic change, or selector426 publication.

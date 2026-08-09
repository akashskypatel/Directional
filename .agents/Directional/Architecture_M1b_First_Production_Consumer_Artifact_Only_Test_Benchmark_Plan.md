# M1b First Production Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** Test + Benchmark only  
**Architecture milestone:** M1 — first production consumer migration  
**Implementation under test:** `0340addf21473854856266ff00cb68915ce24ef0`  
**Production behavior delta intended by Code + Build:** none  
**Review policy:** `never`

## 1. Objective

Accept or reject the first real production adoption of the M1 authority kernel using only the immutable M1b compile artifact. The migrated seam is:

`RemeshPipeline -> fill_surface_optimization_rail_constraints -> surface_optimization_rail_detail::provenance_supports_interval_sheet`.

This turn must prove that source-face/source-vertex identity is typed without changing the consumer's existing same-sheet, cross-sheet source-incidence, component/sheet, rail-assignment, product, M1a, or T1 semantics.

No implementation, test, fixture, CMake, validator, benchmark, manifest, workflow, or production source may be edited or rebuilt. Any failure returns to a later Code + Build.

## 2. Immutable authority

Use exactly:

| Evidence | Value |
|---|---|
| M1b base | `9a4131f9655567ffc60c2c513db1c73826165bb2` |
| M1b implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| Build/event commit | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| Workflow run/job | `31330737703 / 93288453677` |
| Result artifact | `9042940168` |
| Result SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| Log artifact | `9042940336` |
| Log SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Recursive manifest | **53/53**, SHA-256 `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| Package regular files | **54** including manifest |
| Compile closure | Release/static/Ninja **120/120** |
| Code + Build boundary | `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

Accepted comparison authority:

- M1a result artifact `9041930767`;
- T1 result artifact `9041289209`;
- production G4 artifact `9031804178` only for unchanged known-red gate context.

## 3. Preflight

Before executing any packaged binary:

1. verify both original ZIP SHA-256 digests exactly;
2. reject absolute, `..`, or escaping archive paths;
3. extract into an isolated runtime directory;
4. verify all **53/53** `SHA256SUMS` entries and manifest digest;
5. verify inventory: seven ELF executables, two static libraries, 27 fixtures, source patch/archive/compile DB, source blobs, static focused/M1a/T1 manifests, build/command metadata;
6. require `runtimeExecution=false` and every generated-binary/test/discovery/benchmark flag false in the Code + Build command-boundary record;
7. verify implementation/event commits and all source blobs from the Code + Build report;
8. verify static focused manifest exactly six names, M1a manifest exactly 14, and T1 manifest exactly 29;
9. verify the packaged source diff from M1b base contains only the five approved build/header/rail/test paths;
10. if fixture lookup requires it, add only a non-regular runtime locator such as `bin/test-data -> ../test-data`; mutate no packaged regular file.

Any mismatch is a stop condition.

## 4. M1b focused discovery

Execute the validation binary's `--gtest_list_tests` **exactly once**.

The full validation target must discover exactly **77** tests: the accepted T1 validation baseline of 71 plus the six M1b contracts. Within suite `SurfaceOptimizationRailAuthorityMigration`, require exactly these six names and no extra member:

1. `SameSheetRailAssignmentRemainsAccepted`;
2. `CrossSheetExactVertexAndEdgeIncidenceRemainAccepted`;
3. `CrossSheetInteriorProvenanceRemainsRejected`;
4. `InvalidLegacySourceFacesRemainRejected`;
5. `WrongSourceFaceWithoutTypedSupportRemainsRejected`;
6. `SourceFaceComponentAndSheetAuthorityMismatchRemainRejected`.

The source-derived static manifest is unprefixed GoogleTest authority. CMake's `Validation.` CTest prefix is not part of the executable's native GoogleTest name.

## 5. M1b focused semantic execution

Run all six focused tests individually in fresh processes and require **6/6**.

The six contracts must prove the following intended relations, not merely no-crash/status/count mechanics:

- a real `fill_surface_optimization_rail_constraints` same-sheet case still assigns the expected feature vertex, curve ID, and rail ID;
- exact shared source-vertex incidence remains legal across two sheets;
- exact shared source-edge incidence remains legal across two sheets;
- three-corner/interior support remains confined to its authoritative sheet;
- negative and out-of-range legacy source faces still fail closed;
- a source face that does not contain the typed support vertex still rejects;
- source-face component and sheet authority-vector mismatches still reject.

Source inspection packaged in the artifact must also confirm the compile-time helper-signature assertions remain present: `SourceFaceId` and `SourceVertexId` cannot be swapped at the migrated helper boundary.

Do not infer semantic success from compilation alone.

## 6. Validation preservation

After the six individual contracts, execute the full packaged validation binary normally and require **77/77**.

This aggregate is downstream preservation evidence, not a substitute for the six individual semantic contracts. Record exact failures, timing, and exit status if any test fails.

At minimum retain explicit visibility for these pre-M1b rail/provenance contracts within the 77-test result:

- `SurfaceMeshOptimizerPhase22.ProvenanceComponentSheetAndFaceCompatibilityAreEnforced`;
- `SurfaceMeshOptimizerPhase22.RailConstraintBuilderUsesOutputVertexSequencesForBoundaryAndFeatures`;
- `SurfaceMeshOptimizerPhase22.HardRailChartAuthorityNeverMasksScalarProvenanceFailures`.

## 7. M1a authority preservation

Execute `directional_surface_cell_authority_kernel_tests --gtest_list_tests` **exactly once** and require exact match to the immutable 14-name manifest.

Run all 14 contracts individually in fresh processes and require **14/14**. Preserve the accepted interpretation:

- static non-convertibility is compile-time evidence packaged in source;
- runtime contracts exercise typed failures, exact source-edge identity, tagged support, exact Z4/lattice algebra, route reversal, representation perturbation, adapter round trip, and cross-domain misuse.

Any M1a failure blocks M1b acceptance.

## 8. T1 independent-oracle preservation

Execute `directional_surface_cell_oracle_tests --gtest_list_tests` **exactly once** and require exact match to the immutable 29-name manifest.

Run all 29 contracts individually in fresh processes and require **29/29**.

M1b may not replace this independent authority with its focused helper tests, validation result, production success flag, or compile success.

## 9. Direct product comparison

Run the six existing direct acceptance cases in fresh processes from the immutable producer executable:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder;
- BunnyRandom;
- Vase.

Required interpretation:

- Plane, MultiFaceSeam, CloseSheets, Cylinder remain green and independent-oracle clean;
- BunnyRandom remains explicit known-red unless the actual immutable result proves otherwise; if it returns, the independent oracle must still execute before the unchanged fatal product-success assertion and the case must not be counted green;
- Vase receives the same bounded 60-second process guard; a timeout/nonreturn is runtime-safety evidence only, never correctness or proof of nontermination;
- no case may be disabled, expected-failure converted, substituted, or omitted.

Because M1b changes a real production-linked rail consumer, any drift in these direct dispositions is a stop condition and must be investigated as a possible M1b regression without source edits in this turn.

## 10. Regression-pattern validation

| Pattern | M1b state to validate | Required immutable evidence |
|---|---|---|
| `RP-01` | first production adoption of strong source-face/source-vertex domains | helper signature source proof + 6/6 typed consumer contracts |
| `RP-02` | independent authority preserved | exact 14 + exact 29 discovery; 14/14 + 29/29; direct oracle integration |
| `RP-05` | semantic ID remains separate from representation row | source boundary inspection + source-incidence counterexamples + direct preservation |
| `RP-03/04/06/07/08/09` | not migrated by M1b | full validation/direct comparison and bounded source diff |

A focused M1b pass cannot close the higher G4 representative product gate. `PR8-R034 / G4-R007` remains separate unless direct immutable evidence actually changes it.

## 11. Postflight

After all runtime execution:

1. re-hash both original ZIP files and require exact outer digests;
2. re-run all 53 package checksums;
3. prove no packaged regular file was altered or added;
4. record any runtime-only symlink separately;
5. retain exact stdout/stderr, exit status, elapsed time, executable hash, and selected filter for every process;
6. record discovery outputs and hashes;
7. separate required-green results from Bunny/Vase known-red evidence.

## 12. Acceptance

M1b is accepted only if all conditions hold:

1. artifact/source/dependency/package authority exact;
2. validation discovery exactly **77**, with exact focused suite membership of six;
3. focused migration contracts **6/6** individually;
4. complete validation target **77/77**;
5. M1a authority discovery exact 14 and **14/14** individually;
6. T1 oracle discovery exact 29 and **29/29** individually;
7. Plane/MultiFaceSeam/CloseSheets/Cylinder remain green/oracle-clean;
8. Bunny/Vase remain explicit and are not synthetically promoted;
9. no product-result drift attributable to the migration;
10. no package mutation, test weakening, source substitution, or expected-failure conversion.

## 13. Following turn

If accepted, stop and create a **new bounded Code + Build plan** before migrating any second consumer. Select exactly one next consumer from the M1 roadmap and define its compatibility rollback boundary and counterexamples first.

If any acceptance condition fails, remain at M1b and create a corrective **Code + Build** plan. Do not repair source during this Test + Benchmark turn.

# M4-CP3-CB5 Code + Build Record — exact A3→A4 shared-boundary cutover

**Turn:** `M4-CP3-CB5`
**Status:** BUILD GREEN / RUNTIME-FREE
**Semantic source:** `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`
**Compile run/job:** `34670989680 / 103492183626`
**Package artifact:** `10290933668`
**Compile-log artifact:** `10290429543`

## Guard

The mandatory pre-mutation guard passed and is preserved in `Architecture_M4_CP3_CB5_Derivation_Guard_Record.md`. Every shared bounded A4 hard-rail segment changed by this turn derives from accepted A2b/A3 authority as one accepted arc/span plus exact consecutive A3 breakpoint ordinals and exact chart orientation. No tolerance, rounded barycentric geometry, target/grid count, synthetic-node order or post-hoc agreement is shared-boundary authority.

## Implemented cutover

CB5 threads the independently validated `GlobalTopologyPlan` and `GlobalConformityBaselinePlan` from `RemeshPipeline` into A4 through an immutable typed interface. The A4 phase-front product now:

- records the exact topology/baseline digests and schedule-entry count it consumed;
- materializes accepted A3 hard-rail breakpoints from the baseline schedule and exact source support;
- publishes typed shared-boundary span/ordinal/orientation identity on hard-rail front edges;
- pairs hard-rail chart copies by exact span + consecutive ordinals + canonical route rather than `support_key` tolerance/quantization;
- preserves A4-local `family` / `advanceSign` derivation and opposite compatibility checks;
- rejects missing, contradictory, nonconsecutive or orientation-inconsistent shared-boundary authority;
- defers uniform/periodic regional producers when accepted hard-rail A3 authority requires the bounded producer that can publish the typed interval.

The accepted A3 schedule, A2b exact-path semantics, selector403 rows, legacy fallback rules and unrelated product stages are unchanged.

## Focused compile-owned coverage

Five producer-owned required-green identities were appended after accepted selector403:

404. `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt`
405. `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals`
406. `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback`
407. `SurfaceCellAuthorityContractCutover.A3SharedBoundaryCutoverPreservesA4LocalFamilyAndAdvanceSign`
408. `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

Candidate selector408 is 408 LF rows at `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`. Its first403 is byte-identical to accepted selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`. Static owner partition is **30 authority-kernel / 262 producer / 75 completion / 41 validation** with zero missing/ambiguous packaged identities.

## Compile correction history

Two non-authoritative compile-orchestration attempts preceded the final green package and are retained as evidence rather than hidden:

- `34670541648` was an orchestration-only **startup failure with zero jobs**. The temporary caller declared a `contents` permission ceiling below the already-durable observer reusable workflow requirement. Only the temporary caller was corrected; no reusable workflow permission was changed and no semantic source was compiled or executed in that run.
- `34670596365 / 103491097271` configured successfully with GMP/GMPXX and began the required producer-owned preflight at semantic source `3c9350d6604b815655baeefca48034e44656c2f5`, but compilation stopped in `FieldAlignedCurveNetworkTests.cpp` because the newly added CB5 fixture read `products.hasTraceNetwork`, while the existing authoritative boolean is `result.surfaceCellContext.hasTraceNetwork`. Log artifact `10290683505` has SHA-256 `94842e8b7688c2a15a4448947df4137e2b3f88397a3b33b5fc8710df5141263a`. The bounded correction changed only that fixture accessor and produced semantic source `4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e`. No product semantics, selector rows, owner mapping, target set or runtime behavior changed. That failed preflight records `runtimeExecution=false`; full target compilation was skipped after the producer preflight failed.

Neither attempt has package or acceptance authority. The final green compile below is the sole CB5 package authority.

## Compile/package evidence

The mandatory reusable compile workflow used GMP/GMPXX and executed no Directional runtime.

```text
semantic source         = 4dfd0d9a681be0eec8b9fc6a7ea2bea5c419223e
run / job               = 34670989680 / 103492183626
package artifact        = 10290933668
package artifact SHA256 = 3c73ce15c626b9811a0122cccaaa9615f76f1a6b5d6e93692a05fef524a36571
compile log artifact    = 10290429543
compile log SHA256      = ac749b2fbf663aabca566cc0d98f7d531a3eef0f3a94e5a295e41bd26c6f4d7a
source archive SHA256   = f8c3db60c74a7c415fd362e3b9c72d1b9e5f0edd9a49bf86cfce53cb0d474415
manifest SHA256         = 4f571387dc6ae86ac46161b3072c08e7d5ed7529a677506fe6355b71978bd831
manifest entries        = 28
preflight target        = directional_surface_cell_producer_tests
runtimeExecution        = false
```

The full packaged target set is:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

No GTest discovery/listing, `ctest`, test, benchmark, produced executable, CLI/help/version command, fuzzer or custom-input Directional runtime executed in CB5.

## Disposition

Compilation alone does not accept selector408, promote this package, close `G4-B002`, or close CP3. Accepted runtime authority remains corrected R4 artifact `10289601000` / selector403 **403/403** until the frozen successor artifact-only gate is executed and independently reviewed.

**Exact successor:** `M4-CP3-TB3-EXEC` under `Architecture_M4_CP3_TB3_Artifact_Only_Test_Benchmark_Plan.md`, followed by mandatory `M4-CP3-TB3-REV`.

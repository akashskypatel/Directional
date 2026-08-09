# Gate 4 Torus Hard-Rail Face-Chart Authority — Artifact-Only Test + Benchmark Plan

Status: **completed; face-chart projection rejected with a direct-torus regression**
Turn type: **Test + Benchmark only**
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Immutable entering authority

Consume exactly the package produced by the completed face-chart Code + Build turn. Do not configure, compile, rebuild, relink, regenerate discovery, edit source/tests/fixtures/validators, or substitute another artifact.

| Authority | Value |
|---|---|
| Compile artifact | `9030700527` |
| Artifact name | `g4-torus-hard-rail-face-chart-authority-code-build` |
| Artifact URL | [workflow artifact](https://github.com/akashskypatel/Directional/actions/runs/31288505364/artifacts/9030700527) |
| Outer SHA-256 | `6eb42943aa8b27c88fa2afa45e22c5fbc9aa16da2d5cc52748de6e3e45474adf` |
| Recursive `SHA256SUMS` | **49/49**, digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97` |
| Log artifact | `9030700699`, `g4-torus-hard-rail-face-chart-authority-code-build-logs` |
| Log outer SHA-256 | `a3d327bd6d98091e4f4394970aab1823a53324f0106c380cde37a31e99d61263` |
| Workflow run/job | `31288505364 / 93181547076` |
| Implementation | `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Build/event commit | `872ae0eebb90ad31738169687f7b8c1895708076` |
| Entering branch head | `62fc5e6fd2fb0a28817b8a67974389ac3cc466e7` |
| Runtime execution during build | `false` |
| Artifact retention | through **2026-08-23 UTC** |

Expected source/CMake blobs:

- optimizer header `2e97d962d652ecca5e67e0d57f2f6ff71253c4c7`;
- validator header `31525023686ae568f28810f57902d0a6b7e7b1eb`;
- optimizer implementation `0cc46b2c02df28a12c93fb01d768154cc87d8011`;
- pipeline implementation `af09d3305c3f76c0611eb82d681237ea33ad573e`;
- validator implementation `86090487391086caf97ce2f9e16c59662d6ae942`;
- focused tests `336a441f88c427e5f8d01b7613bc11345a5c27d2`;
- test CMake `e82e3088e11f215f030b58be7fb6531a5dbaa99a`.

Expected toolchain/submodules are CMake `3.31.6`, GCC `13.3.0`, Ninja `1.13.2`, Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, and polyscope `59da72df6517cab8379865899bdffdbc96171301`.

## 1. Artifact preflight

Before any packaged runtime:

1. Download artifact `9030700527` and log artifact `9030700699`.
2. Verify both outer SHA-256 values exactly and reject unsafe archive paths.
3. Extract into a new isolated directory.
4. Require `SHA256SUMS` digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97` and verify all **49/49** entries.
5. Require exactly 50 package files, five ELF executables, two static libraries, and 27 fixtures.
6. Recompute all seven source/CMake Git blobs.
7. Require patch SHA-256 `99f82a2faf6ae16c713936db5e77a1b2fc85ba6adc48fd76b4321c55051d48e5` and exactly the six implementation/test paths.
8. Require source archive SHA-256 `df412a3883560c26d45f268cddd9935a7db1221e66bef8a3af88459fe685fbfa`, compile database SHA-256 `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508`, exact metadata/targets/toolchain/submodules/fixtures, and `runtimeExecution=false`.
9. Require the source archive to contain only `.github/workflows/agent-source-snapshot.yml` and no connector trigger/payload.
10. Require the compile log to end at `113/113`, have zero failure markers, and every logged shell exit code to be zero.

Any mismatch stops the turn. Do not repair, rebuild, replace, or mix artifacts.

After preflight only, the isolated extraction may add the previously documented runtime locator symlink `bin/test-data -> ../test-data`. Do not alter any packaged regular file. Reverify the original archive and every manifest member after runtime.

## 2. Runtime environment and discovery

Run from the isolated package's `bin` directory with `LC_ALL=C` and `TZ=UTC`.

Invoke `--gtest_list_tests` exactly once for each of:

- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_compiled_api_tests`.

Preserve raw discovery output and report exact discovered counts. Do not predict the validation total merely by adding seven; discovery is authority. Do not pass Google Benchmark flags to `directional_benchmarks`; it is the repository manifest runner.

Use one exact GoogleTest filter per focused process, for example:

```bash
./directional_surface_cell_validation_tests \
  --gtest_filter='SurfaceMeshOptimizerPhase22.ReciprocalHardRailAuthorityResolvesOneExactChartSidePerQuad'
```

## 3. New focused face-chart acceptance

Run each in one fresh `directional_surface_cell_validation_tests` process:

1. `SurfaceMeshOptimizerPhase22.ReciprocalHardRailAuthorityResolvesOneExactChartSidePerQuad`;
2. `SurfaceMeshOptimizerPhase22.MissingOrMisalignedHardRailChartAuthorityFailsClosed`;
3. `SurfaceMeshOptimizerPhase22.TamperedHardRailIdentityRouteAndChartAuthorityFailClosed`;
4. `SurfaceMeshOptimizerPhase22.AmbiguousHardRailChartSidesAreRejectedInsteadOfOrdered`;
5. `SurfaceMeshOptimizerPhase22.DisconnectedCloseSheetsRejectInjectedChartAuthority`;
6. `SurfaceMeshOptimizerPhase22.HardRailChartResolutionIsInvariantToSourceFaceRows`;
7. `SurfaceMeshOptimizerPhase22.HardRailChartAuthorityNeverMasksScalarProvenanceFailures`.

Acceptance requires:

- opposite-side quads resolve distinct semantic chart sides and pass only with complete reciprocal authority;
- missing/misaligned, wrong-rail, wrong-route, nonreciprocal, unsupported, ambiguous, and disconnected authority fail `LocalSheetMismatch`;
- source face-row reversal preserves acceptance and semantic side;
- invalid scalar barycentric, position, component, and sheet retain their exact typed failures;
- optimizer reference projection and final validation agree on the selected side.

A crash, helper exception, alternate failure, existence-only check, or weakened assertion does not satisfy acceptance.

## 4. Retain the seven canonical contracts

Run individually through `directional_surface_cell_producer_tests`:

1. `SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
2. `SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
3. `SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
7. `SurfaceCellTransitionQuotient.DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

All prior exact semantic and typed-failure assertions remain required.

## 5. Exact torus GoogleTest

Run individually:

`SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`

Acceptance remains unchanged: direct success, no fallback/recovery, complete topology-region/isolation-seam/periodic-relation consumption, one component, zero boundary loops, Euler zero, pure quads, complete output lineage, and `CompletedSurfaceCells` origin.

## 6. Retained regression and bounded suites

After focused results are preserved, run and report:

- producer with the established `-*BunnyRandom*:*Vase*` filter, while recording its exact selected denominator;
- complete completion/simplification;
- complete validation;
- complete compiled API.

Also preserve independent focused groups for transition quotient, topology/isolation/hard rail, polygonal/curved/mixed, periodic/torus/cylinder, remaining Phase10, and direct G0-G3.

Entering runtime authority from artifact `9029584083` was producer **154/163**, completion **154/164**, validation **60/60**, API **8/8**, aggregate **376/395**. Those totals use the prior artifact's discovered denominator and are comparison evidence only. Report every movement by exact test name and earliest typed failure. Historical completion ten and strict-validator timing remain explicit.

## 7. Ordered direct fixture matrix

Only after focused, exact torus GoogleTest, and retained evidence are preserved, run three fresh processes per case in this order:

1. `plane__surface_cells`;
2. `multi_face_seam__surface_cells`;
3. `close_sheets__surface_cells`;
4. `cylinder__surface_cells`;
5. `torus__surface_cells`;
6. `sphere_prescribed__surface_cells` only if torus reaches direct strict-valid final output and its full evidence is recorded first.

Use the immutable manifest, `--warmup 0 --runs 1`, and `--disable-surface-cell-source-grid-recovery`. Preserve command, environment, working directory, stdout/stderr, exit status, elapsed time, and artifact identity for every process.

```bash
./directional_benchmarks \
  --manifest test-data/benchmarks/fixtures/milestone_g_manifest.json \
  --case <case> --warmup 0 --runs 1 \
  --disable-surface-cell-source-grid-recovery
```

Prior same-artifact authority is plane, seam, close sheets, and cylinder direct strict-valid **3/3**; torus **0/3** at 74 `LocalSheetMismatch` issues after 192 materialized quads, complete `4/8/4` authority consumption, and `1/0/0` topology. The new artifact must establish its own result.

Torus acceptance requires direct strict-valid **3/3**, no fallback/recovery, complete `4/8/4` consumption, final one component/zero boundary loops/Euler zero, pure quads, and complete lineage. Torus precedes and gates sphere.

## 8. Decision rule

If all 14 focused contracts and the exact torus GoogleTest pass, prior-green behavior is retained, and torus is direct strict-valid **3/3**, accept the face-chart projection and proceed to prescribed sphere in the same artifact-only turn.

If the new focused tests fail, classify the earliest exact authority defect without rebuilding. If focused tests pass but torus remains blocked, record the earliest typed production failure and keep sphere deferred. If a previously green case regresses, classify that regression before downstream work.

G4 is not complete until the required topology/singularity fixtures produce direct strict-valid pure quads with complete provenance.

## 9. Prohibitions

- no source, test, fixture, manifest, validator, CMake, workflow, or benchmark-acceptance edit;
- no configure, compile, rebuild, relink, or discovery regeneration;
- no artifact substitution or mixing;
- no fallback/recovery or generic-producer substitution;
- no fixture/ID special case, predicted count, or new golden;
- no ownership by count, order, frequency, hash, proximity, row, or numeric-domain coincidence;
- no global union across hard-feature chart components;
- no arbitrary subset search, positional sheet merge, synthetic topology correction, Euclidean periodic weld, post-hoc cycle decomposition, or cell merge;
- no validator relaxation or timeout-as-correctness.

## 10. Closeout

Write an artifact-only report with immutable preflight/postflight, exact discovery, every command/exit status, raw-log checksum authority, focused results, bounded comparison, direct matrix, earliest failures, semantic evidence, and remaining blockers.

Review policy is `never`. Keep PR #8 open, draft, and unmerged. After all branch-file and PR-body writes, the final repository write is one new top-level PR #8 conversation comment.

## Completion record

Artifact `9030700527` was consumed exactly without configure, rebuild,
relink, source/test/fixture/validator/workflow edit, or artifact mixing.
Preflight and postflight passed both outer digests, all **49/49** manifest
entries, 50 original package files, seven source/CMake blobs, five
executables, two libraries, and 27 fixtures.

Discovery found producer 166, completion 164, validation 67, and API 8. The
seven new face-chart tests and seven retained canonical tests all pass
individually. The exact committed torus GoogleTest retains its historical
`InvalidHardRailPairing` failure. Bounded suites are producer **154/163**,
completion **154/164**, validation **67/67**, and API **8/8**. All retained
focused groups match the entering artifact.

Plane, multi-face seam, close sheets, and cylinder remain direct strict-valid
**3/3** without fallback/recovery. Direct torus remains deterministic **0/3**
after complete `4/8/4` consumption, 192 completed quads with complete
lineage, and `1/0/0` topology. Final validation reports 165
`LocalSheetMismatch` issues, versus 74 under artifact `9029584083`.
Prescribed sphere was correctly not run.

This historical plan is no longer next-turn authority. See
`.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Report.md`.
The authoritative next turn is Code + Build under
`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Plan.md`.

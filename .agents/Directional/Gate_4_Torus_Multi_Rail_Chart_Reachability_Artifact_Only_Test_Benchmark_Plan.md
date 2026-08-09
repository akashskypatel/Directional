# Gate 4 Torus Multi-Rail Chart Reachability — Artifact-Only Test + Benchmark Plan

Status: **authoritative next turn**
Turn type: **Test + Benchmark only**
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Immutable entering authority

Consume exactly the package produced by the completed multi-rail
chart-reachability Code + Build turn. Do not configure, compile, rebuild,
relink, regenerate discovery, edit source/tests/fixtures/validators, or
substitute another artifact.

| Authority | Value |
|---|---|
| Compile artifact | `9031804178` |
| Artifact name | `g4-torus-multi-rail-chart-reachability-code-build` |
| Artifact URL | [workflow artifact](https://github.com/akashskypatel/Directional/actions/runs/31292116792/artifacts/9031804178) |
| Outer SHA-256 | `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` |
| Recursive `SHA256SUMS` | **49/49**, digest `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2` |
| Log artifact | `9031804382`, `g4-torus-multi-rail-chart-reachability-code-build-logs` |
| Log outer SHA-256 | `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905` |
| Workflow run/job | `31292116792 / 93190952157` |
| Implementation | `6af23d9aeca29e63aa13c4ae49f50d1748939c49` |
| Build/event commit | `32e97ea89cdc4bca629abde38f31eb943f3f11ad` |
| Entering branch head | `1be301b5786881e0459c814491be8be66ae18a0d` |
| Runtime execution during build | `false` |
| Artifact retention | through **2026-08-23 UTC** |

Expected source/CMake blobs:

- optimizer header `7e6414ba63ab93f29ea1b68ab21a45bdc4a06eb0`;
- validator header `06c6491d545b578fd579235a7c9073dfe1a27a0a`;
- optimizer implementation `d087ceefbdadcbbce82e7bdbe7fba4a3abee3c65`;
- unchanged pipeline implementation
  `af09d3305c3f76c0611eb82d681237ea33ad573e`;
- validator implementation `96f2f512df7f0457891581e7a15eda5a43232bdb`;
- focused tests `ecb28a1cc97875457a343b766fcb67004269df4b`;
- unchanged test CMake `e82e3088e11f215f030b58be7fb6531a5dbaa99a`.

Expected toolchain/submodules are CMake `3.31.6`, GCC `13.3.0`, Ninja
`1.13.2`, Eigen
`769c72fd8019e389810d1de1e7c243521a43b594`, googletest
`3940de91897160fea4815998e08d0fa3c2fb077e`, and polyscope
`59da72df6517cab8379865899bdffdbc96171301`.

## 1. Artifact preflight

Before any packaged runtime:

1. Download result artifact `9031804178` and log artifact `9031804382`.
2. Verify both outer SHA-256 values exactly and reject unsafe archive paths.
3. Extract into a new isolated directory.
4. Require `SHA256SUMS` digest
   `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2`
   and verify all **49/49** entries.
5. Require exactly 50 package files, five ELF
   executables, two static libraries, and 27 fixtures.
6. Recompute all seven source/CMake Git blobs.
7. Require patch SHA-256
   `b7490fabd6d7490e1f8f24d47126b26d07866939fc8142e8c4ef8edd4b89d300`
   and exactly the five
   implementation/test paths.
8. Require source archive SHA-256
   `df6e14e60679ccb25fa832d762fe7d31fdf40de746a5659e20998b72e7232900`,
   compile database SHA-256
   `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508`,
   exact
   metadata/targets/toolchain/submodules/fixtures, and
   `runtimeExecution=false`.
9. Require the source archive to contain only
   `.github/workflows/agent-source-snapshot.yml` and no connector
   trigger/payload.
10. Require the compile log to end at `113/113`, have zero
    failure markers, and every logged shell exit code to be zero.

Any mismatch stops the turn. Do not repair, rebuild, replace, or mix
artifacts.

After preflight only, the isolated extraction may add the previously
documented runtime locator symlink `bin/test-data -> ../test-data`. Do not
alter any packaged regular file. Reverify the original archive and every
manifest member after runtime.

## 2. Runtime environment and discovery

Run from the isolated package's `bin` directory with `LC_ALL=C` and
`TZ=UTC`.

Invoke `--gtest_list_tests` exactly once for each of:

- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_compiled_api_tests`.

Preserve raw discovery output and report exact discovered counts. Do not
predict the validation total by adding four; discovery is authority. Do not
pass Google Benchmark flags to `directional_benchmarks`; it is the
repository manifest runner.

Use one exact GoogleTest filter per focused process.

## 3. New multi-rail reachability acceptance

Run each in one fresh `directional_surface_cell_validation_tests` process:

1. `SurfaceMeshOptimizerPhase22.MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation`;
2. `SurfaceMeshOptimizerPhase22.MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace`;
3. `SurfaceMeshOptimizerPhase22.MissingMultiRailGraphLinkLeavesSelectedChartUnreachable`;
4. `SurfaceMeshOptimizerPhase22.MultiRailChartReachabilityIsInvariantToSourceFaceRows`.

Acceptance requires:

- a scalar-rooted multi-edge relation chain reaches the selected exact chart;
- another valid retained relation may remain unused by that face;
- the exact reciprocal peer may be carried outside the selected face;
- removing one graph link leaves the target unreachable and fails
  `LocalSheetMismatch`;
- source face-row reversal preserves both acceptance and semantic selection.

A crash, helper exception, alternate failure, existence-only check, or
weakened assertion does not satisfy acceptance.

## 4. Retain the seven face-chart contracts

Run individually through `directional_surface_cell_validation_tests`:

1. `SurfaceMeshOptimizerPhase22.ReciprocalHardRailAuthorityResolvesOneExactChartSidePerQuad`;
2. `SurfaceMeshOptimizerPhase22.MissingOrMisalignedHardRailChartAuthorityFailsClosed`;
3. `SurfaceMeshOptimizerPhase22.TamperedHardRailIdentityRouteAndChartAuthorityFailClosed`;
4. `SurfaceMeshOptimizerPhase22.AmbiguousHardRailChartSidesAreRejectedInsteadOfOrdered`;
5. `SurfaceMeshOptimizerPhase22.DisconnectedCloseSheetsRejectInjectedChartAuthority`;
6. `SurfaceMeshOptimizerPhase22.HardRailChartResolutionIsInvariantToSourceFaceRows`;
7. `SurfaceMeshOptimizerPhase22.HardRailChartAuthorityNeverMasksScalarProvenanceFailures`.

All prior exact semantic and typed-failure assertions remain required.

## 5. Retain the seven canonical contracts

Run individually through `directional_surface_cell_producer_tests`:

1. `SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
2. `SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
3. `SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
7. `SurfaceCellTransitionQuotient.DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

## 6. Historical exact torus GoogleTest

Run individually:

`SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`

Record its exact result. Entering authority is the upstream
`InvalidHardRailPairing` scheduling failure. This Code + Build slice did not
change scheduling or this test, so the same typed result is retained
historical authority, not acceptance for direct torus and not a chart
regression. A different result must be classified before downstream work.

## 7. Retained regression and bounded suites

After focused results are preserved, run and report:

- producer with the established `-*BunnyRandom*:*Vase*` filter and exact
  selected denominator;
- complete completion/simplification;
- complete validation;
- complete compiled API.

Also preserve independent focused groups for transition quotient,
topology/isolation/hard rail, polygonal/curved/mixed,
periodic/torus/cylinder, remaining Phase10, and direct G0-G3.

Entering runtime authority from artifact `9030700527` is producer
**154/163**, completion **154/164**, validation **67/67**, API **8/8**,
aggregate **383/402**. Retained groups are **29/36**, **10/10**, **12/12**,
**6/7**, **38/39**, and **4/4**. Report every movement by exact test name and
earliest typed failure. Historical completion ten and strict-validator
timing remain explicit.

## 8. Ordered direct fixture matrix

Only after focused, historical exact-torus, and retained evidence is
preserved, run three fresh processes per case in this order:

1. `plane__surface_cells`;
2. `multi_face_seam__surface_cells`;
3. `close_sheets__surface_cells`;
4. `cylinder__surface_cells`;
5. `torus__surface_cells`.

Do not run prescribed sphere in this turn. Even a passing direct torus leaves
the independent exact-torus `InvalidHardRailPairing` scheduling contract
unresolved.

Use the immutable manifest, `--warmup 0 --runs 1`, and
`--disable-surface-cell-source-grid-recovery`. Preserve command,
environment, working directory, stdout/stderr, exit status, elapsed time, and
artifact identity for every process.

```bash
./directional_benchmarks \
  --manifest test-data/benchmarks/fixtures/milestone_g_manifest.json \
  --case <case> --warmup 0 --runs 1 \
  --disable-surface-cell-source-grid-recovery
```

Entering authority is plane, seam, close sheets, and cylinder direct
strict-valid **3/3**; torus **0/3** at 165 `LocalSheetMismatch` issues after
192 materialized quads, complete `4/8/4` authority consumption, and
`1/0/0` topology. Artifact `9029584083` is the pre-regression reference at
74 issues. The new artifact must establish its own result.

Torus acceptance requires direct strict-valid **3/3**, no fallback/recovery,
complete `4/8/4` consumption, final one component/zero boundary loops/Euler
zero, pure quads, and complete lineage. Reduced mismatch count is not
acceptance.

## 9. Regression and architecture decision rule

If all 18 focused contracts pass, prior-green behavior is retained, and
direct torus is strict-valid **3/3**, accept the multi-rail chart-reachability
correction and mark `G4-R007` `resolved`.

If a previously green case regresses, update the existing root-cause entry
when it is recurrence or add one stable ID when it is genuinely new. Record
the earliest exact cause and affected baseline before downstream work. If
focused tests pass but torus remains blocked, record the earliest typed
production failure and leave `G4-R007` active.

Regardless of outcome, the next architectural review must examine
`AUTHORITY_DOMAIN_CONFLATION` and
`LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY`, which already meet the tracker
recurrence trigger. Do not add another untyped numeric authority or local
consumer of complete global authority without recording that review.

Passing this turn does not complete G4: the historical exact-torus scheduling
contract still gates prescribed sphere.

## 10. Prohibitions

- no source, test, fixture, manifest, validator, CMake, workflow, or
  benchmark-acceptance edit;
- no configure, compile, rebuild, relink, or discovery regeneration;
- no artifact substitution or mixing;
- no fallback/recovery or generic-producer substitution;
- no fixture/ID special case, predicted count, or new golden;
- no ownership by count, order, frequency, hash, proximity, row, or
  numeric-domain coincidence;
- no global union across hard-feature chart components;
- no arbitrary subset search, positional sheet merge, synthetic topology
  correction, Euclidean periodic weld, post-hoc cycle decomposition, or cell
  merge;
- no validator relaxation or timeout-as-correctness.

## 11. Closeout

Write an artifact-only report with immutable preflight/postflight, exact
discovery, every command/exit status, raw-log checksum authority, focused
results, bounded comparison, direct matrix, earliest failures, semantic
evidence, regression-tracker updates, and remaining blockers.

Review policy is `never`. Keep PR #8 open, draft, and unmerged. After all
branch-file and PR-body writes, the final repository write is one new
top-level PR #8 conversation comment.

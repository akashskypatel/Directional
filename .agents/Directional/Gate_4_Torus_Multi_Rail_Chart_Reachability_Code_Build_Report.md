# Gate 4 Torus Multi-Rail Chart Reachability — Code + Build Report

Status: **completed**
Turn type: **Code + Build only**
Active design gate: **G4 topology-distinct completion and singularities**
Date: **2026-08-09 UTC**
Review policy: `never`

## Outcome

The exact vertex-local multi-rail chart-reachability correction compiled
successfully in the required Release/static/Ninja configuration. Exactly the
seven approved targets compiled. The implementation changes five of the six
allowlisted optimizer, validator, and focused-test paths; the conditionally
allowlisted pipeline file remains byte-identical.

No generated Directional binary, GoogleTest discovery/list command, test,
benchmark, `ctest`, CLI/GUI command, help/version command, or custom input was
executed. `runtimeExecution=false`; this report makes no runtime-correctness
or benchmark claim.

## Source authority

| Authority | Value |
|---|---|
| Entering branch head | `1be301b5786881e0459c814491be8be66ae18a0d` |
| Regression tracker commit | `1be301b5786881e0459c814491be8be66ae18a0d` |
| Implementation | `6af23d9aeca29e63aa13c4ae49f50d1748939c49` |
| Workflow commit | `9922548a765a91eec1a2550a05113cb7cd0fc95e` |
| Build/event commit | `32e97ea89cdc4bca629abde38f31eb943f3f11ad` |
| Workflow cleanup commit | `d1ec061edda528ee2cae6bf6e189aa0807a2e57f` |
| Trigger cleanup commit | `01b80ac65968906a9d871cee81f154653f452270` |
| Optimizer header blob | `7e6414ba63ab93f29ea1b68ab21a45bdc4a06eb0` |
| Validator header blob | `06c6491d545b578fd579235a7c9073dfe1a27a0a` |
| Optimizer implementation blob | `d087ceefbdadcbbce82e7bdbe7fba4a3abee3c65` |
| Unchanged pipeline implementation blob | `af09d3305c3f76c0611eb82d681237ea33ad573e` |
| Validator implementation blob | `96f2f512df7f0457891581e7a15eda5a43232bdb` |
| Focused-test blob | `ecb28a1cc97875457a343b766fcb67004269df4b` |
| Unchanged test CMake blob | `e82e3088e11f215f030b58be7fb6531a5dbaa99a` |

The entering-to-implementation comparison is exactly one implementation
commit ahead and modifies only:

- `include/directional/geometry/SurfaceMeshOptimizer.h`;
- `include/directional/validation/SourceAuthoritativeMeshValidator.h`;
- `src/geometry/SurfaceMeshOptimizer.cpp`;
- `src/validation/SourceAuthoritativeMeshValidator.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

Every remote blob reproduces the locally reviewed content exactly.
`src/pipeline/RemeshPipeline.cpp`, quotient formation, tracing, scheduling,
fixtures, manifests, CMake, benchmark acceptance, and the committed exact
torus test remain unchanged.

## Implemented contract

The shared resolver now treats each projected output vertex's retained
source-chart authority as an exact graph:

- nodes are sorted, unique retained chart components validated against the
  scalar source entity, source topology, component, and sheet;
- edges are structurally valid retained `HardRail` relations whose
  direction-canonical routes consist of exact authoritative hard-feature
  edges separating the same two chart components;
- scalar-compatible components are roots, and deterministic graph traversal
  derives all reachable components and selected witness paths;
- every retained relation is validated independently of a face choice, while
  only the selected alternate chart must carry a witness;
- reciprocity is validated against complete projected output authority, with
  exactly two distinct owner vertices per relation, rather than requiring the
  peer on the selected face;
- a face resolves only when its corners have one unique reachable-component
  intersection.

Unused but valid retained relations no longer invalidate an unrelated
incident face. Missing graph links, malformed rail/route/front identity,
unsupported charts, one-sided relations, disconnected sheets, and genuinely
ambiguous face intersections still fail closed as `LocalSheetMismatch`.
Scalar barycentric, position, component, sheet, and source-entity authority
remains exact.

Optimizer labels, centroid/reference projection, projection-cache labels,
final sampling, final validation, and edge authority consume the same
complete provenance and chart-authority collections. No global chart union or
selection by source-face row, numeric ID, count, order, frequency, hash, or
proximity was added.

## Focused compile coverage

`tests/SurfaceMeshOptimizerPhase22Tests.cpp` adds four named contracts:

1. `MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation`;
2. `MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace`;
3. `MissingMultiRailGraphLinkLeavesSelectedChartUnreachable`;
4. `MultiRailChartReachabilityIsInvariantToSourceFaceRows`.

The fixture uses a four-sector planar fan with a central quotient-style
authority set, a scalar-rooted multi-edge relation chain, one unused valid
relation, and reciprocal peers outside the selected quad. Existing
single-relation positive/negative, tamper, ambiguity, disconnected
close-sheet, row-invariance, and scalar typed-failure contracts remain
present.

Before the remote build, the changed translation units, focused tests,
unchanged pipeline translation unit, and retained validator-test translation
unit passed local C++20 syntax compilation against the exact Eigen and
GoogleTest revisions. A warning pass reported only pre-existing mesh/DCEL
warnings, and `git diff --check` passed. These checks compiled only; no
executable was linked or run locally.

## Compile authority

| Evidence | Value |
|---|---|
| Workflow run/job | [`31292116792 / 93190952157`](https://github.com/akashskypatel/Directional/actions/runs/31292116792) |
| Result artifact | [`9031804178`](https://github.com/akashskypatel/Directional/actions/runs/31292116792/artifacts/9031804178), `g4-torus-multi-rail-chart-reachability-code-build` |
| Result artifact SHA-256 | `27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e` |
| Log artifact | `9031804382`, `g4-torus-multi-rail-chart-reachability-code-build-logs` |
| Log artifact SHA-256 | `5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905` |
| Recursive manifest | **49/49**, digest `2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2` |
| Implementation patch SHA-256 | `b7490fabd6d7490e1f8f24d47126b26d07866939fc8142e8c4ef8edd4b89d300` |
| Source archive SHA-256 | `df6e14e60679ccb25fa832d762fe7d31fdf40de746a5659e20998b72e7232900` |
| Compile database SHA-256 | `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508` |
| Retention | through **2026-08-23 UTC** |

Configuration and dependencies:

- Release, `BUILD_SHARED_LIBS=OFF`, Ninja, GoogleTest `PRE_TEST`;
- CMake `3.31.6`, GCC `13.3.0`, Ninja `1.13.2`;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope `59da72df6517cab8379865899bdffdbc96171301`.

Compiled targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Ninja completed **113/113**. The compile step used **7:37.11** wall time,
exited zero, and peaked at **1,836,112 KiB** resident memory.

## Artifact verification

Independent post-download verification established:

- both outer ZIP digests match GitHub and both ZIPs pass integrity checks;
- all **49/49** recursive checksum entries pass;
- the package contains 50 files, five valid ELF
  executables, two valid static libraries, and all 27 exact fixture files;
- the source archive reproduces all seven recorded source/CMake Git blobs;
- the archived patch names exactly the five implementation/test paths and
  reverses cleanly against the archived implementation;
- packaged fixtures are byte-identical to the archived committed fixtures;
- the archived implementation tree contains only
  `.github/workflows/agent-source-snapshot.yml` and no connector trigger or
  payload;
- the build log ends at `113/113`, has zero compiler/build
  failure markers, and every logged shell step exits zero;
- command-boundary inspection finds zero generated project-runtime
  invocations and records `runtimeExecution=false`.

Compile success establishes only that the bounded source and tests compile
and link.

## Regression tracking and next authority

`G4-R007` is now `fix_pending_runtime`: the correction compiles, but the
affected direct torus acceptance gate has not run. It must not become
`resolved` until a later immutable artifact establishes direct strict-valid
torus **3/3** without regressing the accepted matrix.

The root-cause tracker preserves the repeated families
`AUTHORITY_DOMAIN_CONFLATION` and
`LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` as mandatory architectural-review
inputs. Compile success does not clear either review trigger.

The bounded workflow was deleted before its trigger. Final cleanup reproduces
the implementation tree exactly and retains only
`.github/workflows/agent-source-snapshot.yml`.

The authoritative next turn is artifact-only Test + Benchmark under:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md`

It must consume artifact `9031804178` exactly without rebuilding
or editing implementation, tests, fixtures, validators, manifests, CMake,
workflows, or benchmark acceptance. The historical exact-torus
`InvalidHardRailPairing` scheduling blocker remains separate and continues
to gate prescribed sphere. PR #8 remains open, draft, and unmerged.

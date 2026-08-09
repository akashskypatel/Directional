# Gate 4 Torus Hard-Rail Face-Chart Authority — Artifact-Only Test + Benchmark Report

Status: **completed; face-chart projection rejected with a direct-torus regression**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Date: **2026-08-09 UTC**  
Review policy: `never`

## Outcome

The seven new face-chart contracts and the seven retained canonical
transition/periodic/retention contracts all pass individually. Previously
green plane, multi-face seam, close-sheets, cylinder, focused groups, and
bounded suites remain stable.

The production acceptance failed. Direct torus remains deterministic
**0/3** after complete `4/8/4` region/seam/relation consumption, 192
completed quads with complete lineage, and materialized `1/0/0` topology.
Final validation now reports **165** `LocalSheetMismatch` issues, versus 74
under entering artifact `9029584083`. This is a regression of 91 additional
rejected faces at the same validation boundary. Prescribed sphere was
correctly not run.

No source, test, fixture, manifest, validator, CMake, workflow, or benchmark
acceptance changed. No configure, compile, rebuild, relink, or discovery
regeneration occurred.

## Immutable artifact authority

| Authority | Value |
|---|---|
| Implementation | `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Build/event commit | `872ae0eebb90ad31738169687f7b8c1895708076` |
| Workflow run/job | [`31288505364 / 93181547076`](https://github.com/akashskypatel/Directional/actions/runs/31288505364) |
| Runtime artifact | [`9030700527`](https://github.com/akashskypatel/Directional/actions/runs/31288505364/artifacts/9030700527) |
| Artifact outer SHA-256 | `6eb42943aa8b27c88fa2afa45e22c5fbc9aa16da2d5cc52748de6e3e45474adf` |
| Recursive manifest | **49/49**, digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97` |
| Log artifact / SHA-256 | `9030700699` / `a3d327bd6d98091e4f4394970aab1823a53324f0106c380cde37a31e99d61263` |
| Patch SHA-256 | `99f82a2faf6ae16c713936db5e77a1b2fc85ba6adc48fd76b4321c55051d48e5` |
| Source archive SHA-256 | `df412a3883560c26d45f268cddd9935a7db1221e66bef8a3af88459fe685fbfa` |
| Compile database SHA-256 | `60fd05acc3e68a369aacacfa3c24b5582687f7ee6d6b959b9267639dd37fc508` |
| Artifact retention | through **2026-08-23 UTC** |

Preflight independently verified both outer ZIPs, safe archive paths, all 49
recursive members, 50 package files, five ELF executables, two static
libraries, 27 fixtures, all seven source/CMake blobs, the exact six-path
patch, source archive, compile database, metadata, toolchain, submodules,
fixture closure, permanent-workflow-only closure, `113/113` build
completion, zero logged shell failures, and `runtimeExecution=false`.

## Runtime boundary and evidence

Every packaged command ran from the isolated artifact's `bin` directory
with `LC_ALL=C` and `TZ=UTC`. The only package-tree mutation before
runtime was the authorized symlink `bin/test-data -> ../test-data`.

The connector's first local transfer session closed before receiving its
URLs, so it produced no usable artifact. A subsequent echo-disabled transfer
produced the exact two outer digests above. The host lacked
`/usr/bin/time`; its external harness self-test failed before invoking any
project binary. The corrected Python process wrapper was validated against
`/usr/bin/true` before native discovery. Each GoogleTest executable then
ran `--gtest_list_tests` exactly once.

The wrapper preserved command, working directory, environment, timestamps,
stdout, stderr, exit status, elapsed time, peak child RSS, result JSON, and
generated artifact checksums. The final evidence ledger contains **268**
files, all verified; its SHA-256 is
`1d97272a7f1571d0833bb42d819d4cbf5a1b96e52ce600fa5c9d0dd4067448fb`.

## Discovery

| Executable | Suites | Tests | Exit |
|---|---:|---:|---:|
| `directional_surface_cell_producer_tests` | 11 | 166 | 0 |
| `directional_surface_cell_completion_tests` | 4 | 164 | 0 |
| `directional_surface_cell_validation_tests` | 5 | 67 | 0 |
| `directional_compiled_api_tests` | 1 | 8 | 0 |

All 15 required focused names were present. The validation denominator is
seven larger than the entering artifact because all seven new compiled tests
are independently discoverable.

## Focused acceptance

The seven new face-chart tests passed individually, exit zero:

1. `ReciprocalHardRailAuthorityResolvesOneExactChartSidePerQuad`;
2. `MissingOrMisalignedHardRailChartAuthorityFailsClosed`;
3. `TamperedHardRailIdentityRouteAndChartAuthorityFailClosed`;
4. `AmbiguousHardRailChartSidesAreRejectedInsteadOfOrdered`;
5. `DisconnectedCloseSheetsRejectInjectedChartAuthority`;
6. `HardRailChartResolutionIsInvariantToSourceFaceRows`;
7. `HardRailChartAuthorityNeverMasksScalarProvenanceFailures`.

The seven retained canonical contracts also passed individually, exit zero:

1. `SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
2. `FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
3. `RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
4. `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
7. `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

The exact committed torus GoogleTest ran individually and exited 1 at the
historical upstream
`NotProductionReady:tracing/phase-front/InvalidHardRailPairing`. It
reported four regions, eight seams, and four relations available, with
`0/0/0` consumed and no materialized component. This remains the known
target-size-dependent hard-rail scheduling blocker; it is not a new
face-chart failure.

## Retained groups

These filters overlap and are reported independently:

| Group | Result | Exit | Movement |
|---|---:|---:|---|
| Transition quotient | **29/36** | 1 | unchanged seven deferred contracts |
| Topology / isolation / hard rail | **10/10** | 0 | unchanged |
| Polygonal / curved / mixed | **12/12** | 0 | unchanged |
| Periodic / torus / cylinder | **6/7** | 1 | unchanged exact-torus hard-rail failure |
| Remaining non-overlap Phase10 | **38/39** | 1 | unchanged timing assertion |
| Direct G0-G3 GoogleTests | **4/4** | 0 | unchanged |

The timing assertion observed validation `0.000235443` seconds against a
five-percent bound of `0.00012942095` seconds. It remains explicit and does
not override semantic authority.

## Bounded suites

| Suite | Result | Exit |
|---|---:|---:|
| Producer, literal `-*BunnyRandom*:*Vase*` filter | **154/163** | 1 |
| Completion / simplification | **154/164** | 1 |
| Validation | **67/67** | 0 |
| Compiled API | **8/8** | 0 |
| Aggregate | **383/402** | — |

The nine producer failures are the same seven transition-quotient contracts,
the exact committed torus hard-rail case, and strict-validator timing. The
completion suite retains the same historical ten failures. The aggregate
increase from `376/395` is exactly the seven new passing validation tests;
no existing bounded test moved.

## Ordered direct fixture matrix

Every benchmark process itself exited zero and produced one case-matched
JSON. Semantic success is determined from that JSON, not process exit.
Fallback policy was `Fail`, source-grid recovery was disabled, requested
and executed backend were `SurfaceCells`, and no fallback or recovery was
used.

| Case | Result | Stable output / topology | Wall seconds | Peak owned bytes |
|---|---:|---|---|---:|
| Plane | **3/3** | 81 V / 64 Q; structural `b243fb3f5f3a3bc4`; semantic `922456fe29a63ba1`; `1/1/1` topology | 0.523626–0.566104 | 672460 |
| Multi-face seam | **3/3** | 81 V / 64 Q; structural `48661113839528d4`; semantic `99c8be7159d05c2f`; `1/1/1` topology | 0.811430–0.821354 | 548900 |
| Close sheets | **3/3** | 242 V / 200 Q; two components; structural `f01bcf687285ee72`; semantic `f40e1aa5f2eb3f92`; `2/2/2` topology | 4.499317–4.540231 | 2104888 |
| Cylinder | **3/3** | 320 V / 288 Q; structural `81b3763254afc476`; semantic `98da73e60a564998`; one component / two loops / Euler 0 | 4.459343–4.515102 | 3217244 |
| Torus | **0/3** | 192 completed quads; complete lineage; `4/8/4` consumed; one component / zero loops / Euler 0; 165 `LocalSheetMismatch` issues | 0.525342–0.583323 | 2355172 |

All four successes are strict-valid pure quads with complete provenance,
`CompletedSurfaceCells` origin, and deterministic hashes. Torus remains
`Produced` through quotient/completion and fails at
`completion/output-validation / LocalSheetMismatch`; output origin remains
`None` because final validation rejects it. Sphere was prohibited.

## Regression diagnosis

The following diagnosis is an inference from the exact source patch,
quotient lineage construction, passing focused tests, and the 74-to-165
production movement.

Quotient materialization accumulates every chart and every equivalence from
all occurrence members of one union-find quotient class. A legitimate output
vertex may therefore retain several hard-rail relations, including relations
that connect chart components transitively and relations not used by a
particular incident output face.

The new resolver models that complete authority as a direct star around the
single scalar representative:

- every retained non-scalar chart must be connected directly from a scalar
  chart by one relation;
- every retained relation must be marked used while resolving each face;
- an alternate selection requires the same relation on another corner of
  that same face.

Those rules are stronger than quotient authority. A face consumes one unique
chart choice; it is not required to consume every valid relation retained by
each of its vertices. A scalar representative may also reach a face's chart
through a chain of exact quotient relations. The current two-quad focused
fixture gives each shared vertex exactly one relation, so it cannot expose
either unused valid authority or multi-relation reachability. The additional
91 torus failures are consistent with that coverage gap.

The next invariant is:

- structurally validate the complete projected relation set once;
- construct an exact vertex-local graph whose nodes are retained source-chart
  components and whose edges are well-formed, reciprocal hard-rail relations
  at that exact source support;
- derive components reachable from the scalar representative through that
  graph;
- resolve a face by the unique intersection of its corners' reachable exact
  components;
- require only the selected witness path, not every retained relation, to
  justify alternate use;
- validate relation reciprocity against the complete projected authority,
  rather than requiring every peer to lie on the currently selected face;
- preserve scalar barycentric, position, source-component, source-sheet, and
  source-entity checks;
- fail closed on malformed, missing, disconnected, unsupported, nonreciprocal,
  or genuinely ambiguous authority;
- never globally union hard-feature chart components or infer ownership from
  proximity, IDs, order, count, frequency, or fixture identity.

## Postflight

After runtime:

- both original outer ZIP digests remained exact;
- all **50/50** original extracted files and all **49/49** manifest entries
  reverified;
- all seven source/CMake blobs remained exact;
- the package added only nine benchmark artifacts under
  `bin/benchmark-results/artifacts` and the authorized locator symlink;
- every per-process `baseline.json` was moved into external evidence before
  the next process, so no stale baseline remained;
- no packaged regular file was altered.

## Decision and next authority

The hard-rail face-chart projection is not accepted. G4 remains active and is
regressed relative to artifact `9029584083` at direct torus validation.
Review policy is `never`, so the authoritative next turn is **Code + Build
only** under:

`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Plan.md`

That turn may correct only exact multi-relation chart reachability and its
focused coverage, then compile/package approved targets without running a
project binary. Hard-rail breakpoint scheduling for the historical exact
torus GoogleTest, nonzero periodic `Z4` rotation, positive multi-isolation
lineage, historical completion/timing failures, sphere, G5/G6,
fallback/recovery, and optimization quality remain separate blockers.

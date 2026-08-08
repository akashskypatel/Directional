# Gate 4 Canonical Transition Index and Failure Retention — Artifact-Only Test + Benchmark Report

Status: **blocked with material progress**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Date: **2026-08-08**  
Review policy: `never`

## Decision

Artifact `9028103772` is exact and executable. The source correction produces substantial direct behavior improvement:

- plane, multi-face seam, close sheets, and cylinder complete directly and deterministically **3/3** each;
- the direct G0-G3 GoogleTest group moves from **1/4** to **4/4**;
- retain/release now reaches identical `InjectedStageFailure / tracing` and exposes trace authority iff requested;
- cylinder incidence remains correct;
- direct torus moves past numeric `InvalidPeriodicCutAuthority`, consumes all `4/8/4` topology-region/isolation-seam/periodic-relation authority, and materializes one component with zero boundary loops and Euler zero.

G4 is not complete. Torus fails downstream at `completion/output-validation / LocalSheetMismatch` with 74 strict-validation issues and no final output. Three new canonical-domain tests do not reach their intended materialization/tamper assertions because their synthetic witness is not present in any serialized cell route. Two previously green Phase10 tests also encode the old numeric-domain meaning and therefore no longer exercise their stated contracts.

This is material progress under `DESIGN.md`: three active direct fixtures are restored and exact torus advances through complete quotient-authority consumption. The mandatory no-progress review guard is not active. Because review policy is `never`, the test-authority remediation plan named below is the authoritative next Code + Build turn.

## Immutable authority and preflight

Runtime consumed exactly:

| Authority | Value |
|---|---|
| Compile artifact | `9028103772`, `g4-canonical-transition-index-code-build` |
| Outer SHA-256 | `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a` |
| Recursive manifest | `06123ea4c2507ed673e1a4885c4e463a6c05ed43b7a27146b3dc2722a7631a1f`, **48/48** |
| Implementation | `edc14d38f862b94941b249f564050e2e1f8f5287` |
| Build/event commit | `b0f8f039856aa1d0c7ff6be017cd5d3121a8efe0` |
| Workflow run/job | `31279574458 / 93158612245` |
| Entering branch documentation head | `4dc7cc4e23dcd961d1bc9be5b9ac7439df4c17f0` |
| Raw runtime-log checksum manifest | 120 files; SHA-256 `ecbccb599114e1f40d5bd0efea48cb17270e7170fb134671684648cf640cd137` |

Preflight passed before discovery:

- outer ZIP digest exact and ZIP paths safe;
- 49 package files including `SHA256SUMS`;
- five valid ELF executables, two valid static libraries, and 27 exact fixture copies;
- Release/static/Ninja, GoogleTest `PRE_TEST`, seven approved targets, and `runtimeExecution=false` metadata exact;
- CMake `3.31.6`, GCC `13.3.0`, Ninja `1.13.2`, and all three submodule revisions exact;
- four-path implementation patch exact and reverse-checks against the source closure;
- six source/CMake Git blobs exact;
- source closure contains only `.github/workflows/agent-source-snapshot.yml` under workflows and no connector trigger/payload;
- compile log ends at `113/113` with no failure marker.

The sixth recorded blob is `cmake/DirectionalTests.cmake` at `e82e3088e11f215f030b58be7fb6531a5dbaa99a`. Earlier handoff text incorrectly labeled that path `tests/CMakeLists.txt`; the artifact metadata and blob were correct.

After all runtime commands, the original archive digest and all **48/48** packaged manifest entries still passed. Runtime added only the extracted-copy symlink `bin/test-data -> ../test-data` and generated `bin/benchmark-results/**`; no original artifact byte changed.

## Discovery and command boundary

All commands ran from the isolated package's `bin` directory with `LC_ALL=C` and `TZ=UTC`.

Native GoogleTest discovery ran exactly once per test executable:

| Executable | Suites | Tests |
|---|---:|---:|
| producer | 11 | 166 |
| completion/simplification | 4 | 164 |
| validation | 5 | 60 |
| compiled API | 1 | 8 |

Producer discovery contains **36/36** independently named `SurfaceCellTransitionQuotient.*` cases: the prior 33 plus the three canonical-domain cases.

`directional_benchmarks` is a repository-specific manifest runner, not Google Benchmark. The exploratory `--benchmark_list_tests=true` invocation exited 1 with `Unknown benchmark option`; it executed no fixture. The immutable manifest was then read directly and contains 20 cases. All authoritative benchmark executions used:

```text
./directional_benchmarks \
  --manifest test-data/benchmarks/fixtures/milestone_g_manifest.json \
  --case <case> --warmup 0 --runs 1 \
  --disable-surface-cell-source-grid-recovery
```

Each direct fixture used three separate processes in the required order.

No configure, compile, relink, regenerated discovery file, source/test/fixture/validator edit, fallback, recovery, or artifact substitution occurred.

## Focused canonical-domain and retention acceptance

Each required test ran individually.

| Test | Result | Classification |
|---|---:|---|
| `SourceWideCompactTransitionIndexIsIndependentOfRegionPartition` | fail | structurally invalid test witness |
| `FullEfTransitionRowCannotReplaceSourceWideCompactIndex` | fail | structurally invalid test witness |
| `RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex` | fail | structurally invalid test witness |
| `ComponentBoundaryAndEulerFactsAreComputedFromIncidence` | pass | accepted |
| `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested` | pass | accepted |

The positive canonical test computes a pairwise-distinct topology from a region-local table, but never establishes that topology occurs in a produced cell's `transitionSourceTopology`. It fails only at `observedWitness == false`. Both tamper tests reuse that off-route topology and fail because `replace_transition_index(...)` cannot find it. Materialization and the intended typed rejection are never reached. This is not evidence against the production normalization, and the assertions must not be weakened.

The retention test proves both branches terminate as `InjectedStageFailure / tracing`; retained authority is nonempty only for `retain=true`, while `retain=false` exposes neither trace-network presence nor phase-front cells.

## Focused and retained regression groups

Groups overlap and are not summed independently.

| Group | Result | Previous | Disposition |
|---|---:|---:|---|
| transition quotient | **26/36** | 24/33 | incidence and retention fixed; three new invalid witnesses |
| topology/isolation/hard rail | **10/10** | 10/10 | retained |
| polygonal/curved/mixed | **12/12** | 12/12 | retained |
| periodic/torus/cylinder | **5/7** | 5/7 | one real hard-rail blocker; one invalid old-domain tamper |
| remaining non-overlap Phase10 | **37/39** | 35/39 | three prior route failures fixed; timing plus old-domain expectation fail |
| direct G0-G3 GoogleTests | **4/4** | 1/4 | plane/close-sheets/cylinder restored |

Every previously green certificate-negative, genuine-boundary, semantic-digest, topology/isolation, polygonal/curved/mixed, validation, API, and multi-face-seam contract remains green after classifying the two old-domain test errors below.

### Old-domain Phase10 test errors

`PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` interprets each `sourceRouteEdges` and `cutSourceEdges` value as a `mesh.EV` row. The corrected contract defines those values as source-wide compact interior-transition indices. The test must compare the parallel canonical topology sequences and independently verify each numeric/topology pair against each reordered mesh's source-wide compact map.

`PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` takes a compact `sourceRouteEdges` value and searches `CrossFieldEdgeTransition.sourceEdge`, whose meaning remains the full `EF` row used for validation. It mutates an unrelated transition and the producer truthfully remains `Produced`. The test must select the transition by `sourceRouteTopology` plus reciprocal incident-face authority, then mutate its matching and retain the exact `Rejected / PeriodicHolonomyMismatch / no proposals` assertions.

These are incorrect test setup/expectation errors caused by the previous domain conflation; they are not permission to change production semantics.

## Ordered direct fixture matrix

Every successful row is direct `CompletedSurfaceCells`, strict-valid, pure quad, complete-lineage, fallback/recovery-free, and deterministic across all three processes.

| Fixture | Result | Output `V/Q` | Topology `regions/seams/relations -> consumed` | Structural / semantic | Internal wall seconds | Peak owned bytes |
|---|---:|---:|---|---|---:|---:|
| plane | **3/3** | `81/64` | `1/0/0 -> 1/0/0` | `b243fb3f5f3a3bc4` / `922456fe29a63ba1` | `0.491565–0.513944` | `672,460` |
| multi-face seam | **3/3** | `81/64` | `1/0/0 -> 1/0/0` | `48661113839528d4` / `99c8be7159d05c2f` | `0.730418–0.743840` | `548,900` |
| close sheets | **3/3** | `242/200` | `2/0/0 -> 2/0/0` | `f01bcf687285ee72` / `f40e1aa5f2eb3f92` | `4.077513–4.208042` | `2,104,888` |
| cylinder | **3/3** | `320/288` | `1/0/1 -> 1/0/1` | `81b3763254afc476` / `98da73e60a564998` | `3.970448–4.094417` | `3,217,244` |
| torus | **0/3** | none | `4/8/4 -> 4/8/4` | none | `0.520487–0.540477` | `2,355,172` |

Plane and close sheets no longer report `InvalidAuthoritativeTransitionSourceEdge`. Cylinder and torus no longer report numeric `InvalidPeriodicCutAuthority`. Multi-face seam preserves the required same-artifact semantic digest `99c8be7159d05c2f`.

Torus is deterministic in all three processes:

```text
terminal: NotProductionReady / completion
first invalid: completion/output-validation / LocalSheetMismatch
authority: output face 0
strict-validation issue count: 74
producer disposition: Produced
consumed regions/seams/relations: 4/8/4
materialized components/boundary loops/Euler: 1/0/0
completed quads before rejection: 192
output origin: None
fallback/recovery: false/false
```

The direct torus manifest case therefore passes transition serialization, periodic quotient consumption, and its `1/0/0` incidence target, but final local-chart compatibility remains invalid. Sphere was not run because the design explicitly defers it until torus reaches direct strict-valid final output. Bunny, vase, and the broader manifest were also deferred because focused and torus acceptance did not pass.

## Bounded suites

The producer suite excluded only the two documented long `BunnyRandom` and `Vase` design-acceptance parameters.

| Suite | Result | Previous | Classification |
|---|---:|---:|---|
| producer | **150/164** | 143/161 | +3 tests, +7 passing total |
| completion/simplification | **154/164** | 154/164 | exact same historical ten failures |
| validation | **60/60** | 60/60 | retained |
| compiled API | **8/8** | 8/8 | retained |
| aggregate bounded | **372/396** | 365/393 | 24 failures versus 28 |

The producer's 14 failures are:

- three invalid canonical-domain witnesses;
- two known multi-isolation/equivalence-lineage positive-witness failures;
- two nonzero periodic-rotation failures at `PeriodicHolonomyMismatch`;
- three torus relation-owner tests and the exact target-size torus test blocked by `InvalidHardRailPairing`;
- the invalid malformed-holonomy full-`EF` lookup;
- the invalid face-row compact-index interpretation;
- the historical scheduler-sensitive validator timing assertion.

The timing assertion observed `0.000170808 s` validation against a `0.0001103381 s` five-percent limit. It remains non-authoritative for semantic acceptance and is not hidden or reclassified as pass.

## Failure classification and next invariant

### Test-authority failures to repair first

1. Build the canonical-domain witness from an **actually serialized** two-face route and prove the source-wide compact, region-local compact, and full-`EF` values are pairwise distinct before positive or negative assertions.
2. Compare periodic route/cut authority through parallel canonical topology and source-wide maps, never `mesh.EV[compactIndex]`.
3. Select a CrossField transition for malformed-holonomy mutation by canonical topology and reciprocal faces, never by comparing a compact route index with a full-`EF` row.

### Production failures intentionally deferred from that repair

1. direct torus strict validation rejects 74 faces at `LocalSheetMismatch` after complete `4/8/4` quotient consumption;
2. nonzero periodic `Z4` rotation remains unsupported;
3. exact torus at the focused target size still lacks a shared conforming hard-rail breakpoint schedule;
4. the multi-isolation positive fixture still does not demonstrate a quotient class spanning multiple local sheets;
5. the historical completion/simplification ten and timing threshold remain open.

The smallest safe next slice is test-authority-only. Mixing a torus validator/lineage correction into the same turn would make canonical normalization acceptance ambiguous.

## Next authority

The authoritative next turn is Code + Build only under:

`.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Code_Build_Plan.md`

It may edit only the two focused test sources, must preserve every semantic assertion, and may compile/package but execute no generated project binary. PR #8 remains open, draft, and unmerged.

# Gate 4 Canonical Transition Index and Failure Retention — Artifact-Only Test + Benchmark Plan

Status: **completed by artifact-only report**
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Completion authority

Artifact `9028103772` was consumed exactly. Its outcome is recorded in `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`: four direct fixtures pass, torus advances to downstream `LocalSheetMismatch`, and five test-authority errors require the completed remediation turn. This historical plan is no longer next-turn authority.

## Immutable entering authority

Consume exactly the compile package produced by the completed Code + Build turn. Do not configure, compile, rebuild, relink, regenerate discovery, edit source/tests/fixtures/validators, or substitute another artifact.

| Authority | Value |
|---|---|
| Compile artifact | `9028103772` |
| Artifact name | `g4-canonical-transition-index-code-build` |
| Artifact URL | [workflow artifact](https://github.com/akashskypatel/Directional/actions/runs/31279574458/artifacts/9028103772) |
| Outer SHA-256 | `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a` |
| Recursive `SHA256SUMS` digest | `06123ea4c2507ed673e1a4885c4e463a6c05ed43b7a27146b3dc2722a7631a1f` |
| Log artifact | `9028103932` |
| Log outer SHA-256 | `1ff42b2176db5c4f9194957d744dc5f31ff3096b06526f723db0c659636544c6` |
| Workflow run/job | `31279574458 / 93158612245` |
| Implementation | `edc14d38f862b94941b249f564050e2e1f8f5287` |
| Build/event commit | `b0f8f039856aa1d0c7ff6be017cd5d3121a8efe0` |
| Entering implementation | `6210522950a7167bd24c4e8ae11eb68f4f32ecca` |
| Runtime execution during build | `false` |

Expected source authority:

- header `b87e37676a980162e7ef3ac1fa9d954ce2199ad2`;
- tracing implementation `4809e66bb6e797001ffc22b3f2da6d3613cfdef0`;
- pipeline implementation `0a55429fc83d429ae2176ce3bbaac573682c48eb`;
- transition quotient tests `7644327ffbe30c2a6e5bda3ec977f12a3a47c922`;
- unchanged Phase10 tests `d34b5f097cf39ac72f060616a37d360e382af168`;
- unchanged test CMake `e82e3088e11f215f030b58be7fb6531a5dbaa99a`.

Expected toolchain and dependencies:

- CMake `3.31.6`;
- Ubuntu GCC `13.3.0`;
- Ninja `1.13.2`;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope `59da72df6517cab8379865899bdffdbc96171301`.

## 1. Artifact preflight

Before executing any packaged runtime:

1. Download artifact `9028103772` through the GitHub artifact endpoint.
2. Verify the outer ZIP SHA-256 exactly.
3. Extract to a new isolated directory.
4. Verify the recursive `SHA256SUMS` file itself and all **48/48** listed entries.
5. Require exactly the expected metadata, source closure, patch, logs, compile database, five executables, two static libraries, and 27 fixtures.
6. Recompute and require all six expected source/CMake blob identities.
7. Require the patch to name exactly the four implementation paths from the completed Code + Build report.
8. Require metadata to match the implementation, build/event, entering authority, toolchain, submodules, target list, and `runtimeExecution=false`.
9. Require the archived workflow tree to contain only `.github/workflows/agent-source-snapshot.yml`.

Any mismatch stops the turn. Do not repair, rebuild, or replace the artifact.

## 2. Runtime discovery boundary

Only after preflight succeeds, use the packaged test executables’ native discovery mechanism to record exact test names and counts. Discovery is runtime and therefore belongs only to this turn. Preserve raw discovery output.

Run tests from the isolated immutable package. Do not copy in repository binaries, fixtures, manifests, libraries, generated discovery files, or source-built substitutes.

## 3. Focused canonical-domain and retention acceptance

Run and report individually:

- `SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
- `FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
- `RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
- `ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
- `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

Acceptance is exact:

- the valid general witness carries source-wide compact indices paired with canonical topology independent of topology-region partition;
- materialization accepts every valid pair;
- full-`EF` and region-local substitutions each fail as `InvalidAuthoritativeTransitionSourceEdge`;
- genuine one-face boundaries remain topology-only;
- the cylinder incidence test passes;
- retain true and false reach the same `InjectedStageFailure / tracing`;
- retained trace authority is present and nonempty only for `retain=true`;
- `retain=false` exposes no trace network or cells.

Do not weaken equality, iff, topology, or typed-failure assertions.

## 4. Regression suites

Run the previously green certificate, boundary, semantic-digest, topology/isolation, polygonal/curved/mixed, validation, and compiled-API tests. At minimum preserve the exact focused grouping and bounded-suite totals from artifact `9026181778` so regressions are attributable.

Required prior-green authority includes:

- transition quotient certificate and malformed-authority families;
- genuine-boundary and direct multi-face-seam cases;
- topology/isolation/hard-rail tests;
- polygonal, curved, and mixed tracing;
- validation **60/60**;
- compiled API **8/8**;
- all previously green completion/simplification cases.

The previous bounded baselines were producer **143/161**, completion/simplification **154/164**, validation **60/60**, compiled API **8/8**, aggregate **365/393**. These are comparison authority, not predicted success counts for the new artifact. Report every movement by exact test name and earliest typed failure.

## 5. Ordered direct-fixture classification

Use the packaged committed fixtures and existing authoritative harness only. Do not synthesize, mutate, relabel, or substitute inputs.

Run in this order:

1. plane;
2. multi-face seam;
3. close sheets;
4. winding cylinder;
5. direct torus;
6. sphere only after torus evidence is fully recorded.

For each attempted fixture, perform three fresh-process repetitions and report terminal code/stage, earliest typed failure and authority coordinates, output validation facts, topology facts, consumed authority, deterministic semantic digest, and timing as observational evidence.

Exact movement requirements:

- plane and close sheets must not report `InvalidAuthoritativeTransitionSourceEdge`;
- cylinder and torus must not report numeric route/index `InvalidPeriodicCutAuthority`;
- direct multi-face seam must remain deterministic and preserve same-artifact semantic digest `99c8be7159d05c2f`.

The seam digest is same-artifact semantic evidence only, not a cross-version raw-output golden. A new truthful downstream failure may be reported. An unchanged canonical-domain failure does not satisfy material progress.

Torus must precede sphere. If torus remains blocked, record its direct producer/topology authority before deciding whether the existing plan permits sphere execution; do not let a sphere observation preempt the earlier torus invariant.

## 6. Benchmark and semantic evidence

Use only the packaged benchmark executable, committed manifest, and committed fixtures after focused correctness classification. Preserve raw outputs and record command, working directory, environment, exit status, elapsed time, and artifact identity.

Timing is diagnostic unless an existing authoritative threshold says otherwise. A timeout is not correctness. Do not add or infer predicted output counts.

A semantic digest must be computed through the existing packaged authority. Do not compare raw file bytes or introduce a new cross-version golden.

## 7. Prohibitions

- no source, test, fixture, manifest, validator, CMake, workflow, or benchmark-acceptance edit;
- no configure, compile, rebuild, relink, or discovery regeneration;
- no artifact substitution or mixing;
- no fallback, recovery, generic-producer substitution, or best-effort continuation after authoritative rejection;
- no fixture/ID special case;
- no ownership by count, order, frequency, hash, observed length, or analytical fixture parameter;
- no arbitrary subset search;
- no positional sheet merging, synthetic topology correction, Euclidean periodic welding, post-hoc cycle decomposition, or cell merging;
- no validator relaxation;
- no predicted success counts;
- no timeout-as-correctness.

## 8. Closeout and cadence

Write an artifact-only Test + Benchmark report that records immutable preflight, exact discovery, every command, raw-log artifact identity, focused results, bounded-suite comparison, direct-fixture matrix, earliest failures, semantic evidence, and remaining blockers.

Nonzero periodic rotation, shared hard-rail breakpoint scheduling, and the positive multi-isolation lineage witness remain separate blockers unless this exact artifact proves them resolved. G4 remains active until direct exact torus produces strict-valid pure quads with complete lineage, one component, zero boundary loops, Euler zero, and all `4/8/4` authority consumed.

The turn after this one must be selected from the earliest truthful failing invariant and obey the separated cadence. Keep PR #8 open, draft, and unmerged. Remove any bounded runtime workflow/trigger/payload in safe order and retain only `.github/workflows/agent-source-snapshot.yml`.

After all repository and PR-body writes, the final repository write is one new top-level PR #8 conversation comment. Perform no GitHub write after it.

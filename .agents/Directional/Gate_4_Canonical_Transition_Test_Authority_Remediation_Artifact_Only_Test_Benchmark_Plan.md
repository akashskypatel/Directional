# Gate 4 Canonical Transition Test Authority Remediation — Artifact-Only Test + Benchmark Plan

Status: **completed by artifact-only validation; see `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md`**
Turn type: **Test + Benchmark only**
Active design gate: **G4 topology-distinct completion and singularities**
Review policy: `never`

## Immutable entering authority

Consume exactly the package produced by the completed test-authority Code + Build turn. Do not configure, compile, rebuild, relink, regenerate discovery, edit source/tests/fixtures/validators, or substitute another artifact.

| Authority | Value |
|---|---|
| Compile artifact | `9029584083` |
| Artifact name | `g4-canonical-transition-test-authority-code-build` |
| Artifact URL | [workflow artifact](https://github.com/akashskypatel/Directional/actions/runs/31284957305/artifacts/9029584083) |
| Outer SHA-256 | `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad` |
| Recursive `SHA256SUMS` | **49/49**, digest `ee65be615bcf59516f5c0e05f98e56b7d9095d48d41cb1675cb5e3938ad7ce26` |
| Log artifact | `9029584200`, `g4-canonical-transition-test-authority-code-build-logs` |
| Log outer SHA-256 | `b2c147a691caaafc6591106ebb59f50f2956c17722f88bff1857c94d33f3da9b` |
| Workflow run/job | `31284957305 / 93172020467` |
| Implementation | `de5261c7185aef71807b0b4140c8f023a44874fd` |
| Build/event commit | `5bf9b0efc665e0a940aa4e74b168171651685f7d` |
| Entering branch head | `2703f2f94e77afa4c7ed397200ddd456413c7125` |
| Runtime execution during build | `false` |
| Artifact retention | through `2026-08-23 UTC` |

Expected source/CMake blobs:

- transition quotient tests `42111d1de51baa6cca85171aeab339813cae3b50`;
- Phase10 tests `552a3d98ec8f9280b960fb9bbff9a1c7596a0778`;
- tracing header `b87e37676a980162e7ef3ac1fa9d954ce2199ad2`;
- tracing implementation `4809e66bb6e797001ffc22b3f2da6d3613cfdef0`;
- pipeline implementation `0a55429fc83d429ae2176ce3bbaac573682c48eb`;
- test CMake `e82e3088e11f215f030b58be7fb6531a5dbaa99a`.

Expected toolchain and submodules:

- CMake `3.31.6`, GCC `13.3.0`, Ninja `1.13.2`;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope `59da72df6517cab8379865899bdffdbc96171301`.

## 1. Artifact preflight

Before any packaged runtime:

1. Download artifact `9029584083` and log artifact `9029584200` through the GitHub artifact endpoint.
2. Verify both outer SHA-256 values exactly.
3. Reject unsafe archive paths and extract into a new isolated directory.
4. Verify the `SHA256SUMS` file digest and all **49/49** listed package entries.
5. Require exactly 50 package files, five ELF test/benchmark executables, two static libraries, and 27 fixture files.
6. Recompute all six source/CMake Git blob identities.
7. Require the archived patch SHA-256 `96e96f3a2bb4492f208600359aefec59c70a0a138b0ccfcf0dca03e40b5650ef` and exactly the two test paths from the Code + Build report.
8. Require the source archive SHA-256 `b3d1848ac9710044104e4be5382f2d1af3adf00314ed7b22a566aead8469d376`, exact implementation metadata, target list, toolchain, submodules, fixture list, and `runtimeExecution=false`.
9. Require the source archive to contain only `.github/workflows/agent-source-snapshot.yml` and no connector trigger/payload.
10. Require the compile log to end at `113/113` with zero failure markers and all logged shell exit codes to be zero.

Any mismatch stops the turn. Do not repair, rebuild, replace, or mix artifacts.

After preflight only, the extracted working copy may add the previously documented locator symlink `bin/test-data -> ../test-data`. Do not alter any packaged regular file. Record the symlink and reverify the original archive plus all packaged manifest entries after runtime.

## 2. Runtime environment and discovery

Run from the isolated package's `bin` directory with:

```bash
export LC_ALL=C
export TZ=UTC
```

Use each GoogleTest executable's native `--gtest_list_tests` exactly once and preserve raw output. Do not pass Google Benchmark flags to `directional_benchmarks`; it is the repository's manifest runner, and its cases are already enumerated by the immutable manifest.

Discovery must show all seven focused test names below. Record exact suite/test counts for producer, completion/simplification, validation, and compiled API.

## 3. Focused acceptance — one fresh process each

Run these individually through `directional_surface_cell_producer_tests`:

1. `SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
2. `SurfaceCellTransitionQuotient.FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
3. `SurfaceCellTransitionQuotient.RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
7. `SurfaceCellTransitionQuotient.DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

Use one exact filter per process, for example:

```bash
./directional_surface_cell_producer_tests \
  --gtest_filter='SurfaceCellTransitionQuotient.SourceWideCompactTransitionIndexIsIndependentOfRegionPartition'
```

Acceptance is exact:

- the positive canonical test selects an actually serialized later-region route whose source-wide compact, region-local compact, and full-`EF` values are pairwise distinct;
- every serialized numeric/topology pair matches the source-wide map;
- genuine one-face boundaries remain topology-only and valid materialization succeeds;
- full-`EF` and region-local substitutions both reach `InvalidAuthoritativeTransitionSourceEdge`;
- face-row reversal preserves grid, rotation, translation, ordered route topology, ordered cut topology, and each per-mesh compact mapping;
- malformed holonomy reaches exactly `Rejected / PeriodicHolonomyMismatch` with empty seeds, traces, and proposals;
- incidence facts remain exact;
- retain true and false reach the same `InjectedStageFailure / tracing`, with public authority present iff requested.

No helper exception, missing witness, alternate failure, existence-only check, or weakened assertion satisfies acceptance.

## 4. Retained regression and bounded suites

After focused acceptance, run and report:

```bash
./directional_surface_cell_producer_tests \
  --gtest_filter='-*BunnyRandom*:*Vase*'
./directional_surface_cell_completion_tests
./directional_surface_cell_validation_tests
./directional_compiled_api_tests
```

Also report the independently overlapping focused groups used by the entering runtime report:

- transition quotient;
- topology/isolation/hard rail;
- polygonal/curved/mixed;
- periodic/torus/cylinder;
- remaining non-overlap Phase10;
- direct G0-G3 GoogleTests.

Entering runtime authority from artifact `9028103772` was producer **150/164**, completion/simplification **154/164**, validation **60/60**, compiled API **8/8**, aggregate **372/396**. These totals are comparison evidence, not predicted counts.

All previously green certificate, genuine-boundary, isolation-seam, semantic-digest, topology/isolation, hard-rail, polygonal/curved/mixed, direct G0-G3, validation, API, and completion/simplification cases must remain green. Report every movement by exact test name and earliest typed failure. The historical completion ten and scheduler-sensitive timing assertion remain explicit; do not hide or reinterpret them.

## 5. Ordered direct fixture matrix

Only after focused and retained regression evidence is preserved, run three fresh processes per case in this order:

1. `plane__surface_cells`;
2. `multi_face_seam__surface_cells`;
3. `close_sheets__surface_cells`;
4. `cylinder__surface_cells`;
5. `torus__surface_cells`;
6. `sphere_prescribed__surface_cells` only if torus reaches direct strict-valid final output and its full evidence is recorded first.

Use exactly:

```bash
./directional_benchmarks \
  --manifest test-data/benchmarks/fixtures/milestone_g_manifest.json \
  --case <case> --warmup 0 --runs 1 \
  --disable-surface-cell-source-grid-recovery
```

Each process must request/exercise `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no fallback/recovery. Preserve raw stdout/stderr, command, working directory, environment, exit status, elapsed time, and artifact identity.

Because production blobs are unchanged, retain the entering artifact's direct authority unless this exact artifact proves a real regression:

- plane, multi-face seam, close sheets, and cylinder were direct strict-valid pure-quad **3/3** successes;
- multi-face seam's same-artifact semantic digest was `99c8be7159d05c2f`;
- torus consumed all `4/8/4` region/seam/relation authority, materialized `1/0/0` topology, then failed at `completion/output-validation / LocalSheetMismatch` with 74 issues.

The seam digest is same-artifact semantic evidence only, not a cross-version raw-output golden. Torus must precede sphere. If torus remains blocked, sphere and the broader manifest remain deferred.

## 6. Decision rule

If all seven focused contracts pass and prior-green/direct behavior is retained, canonical transition test authority is accepted. The earliest production blocker then remains torus local-chart compatibility after complete quotient consumption; the next Code + Build plan may target that invariant only.

If any canonical witness or periodic authority test still fails before its intended assertion, classify the exact fixture/setup defect and keep production changes prohibited. If a previously green or direct case regresses, classify that regression before any downstream torus work.

Do not infer completion from aggregate improvement. G4 remains active until exact torus directly produces strict-valid pure quads with complete lineage, one component, zero boundary loops, Euler zero, and all `4/8/4` authority consumed.

## 7. Prohibitions

- no source, test, fixture, manifest, validator, CMake, workflow, or benchmark-acceptance edit;
- no configure, compile, rebuild, relink, or discovery regeneration;
- no artifact substitution or mixing;
- no fallback, recovery, generic-producer substitution, or best-effort continuation after authoritative rejection;
- no fixture/ID special case, predicted count, or new golden;
- no ownership by count, order, frequency, hash, observed length, or analytical fixture parameter;
- no arbitrary subset search, positional sheet merge, synthetic topology correction, Euclidean periodic weld, post-hoc cycle decomposition, or cell merge;
- no validator relaxation or timeout-as-correctness.

## 8. Closeout

Write an artifact-only Test + Benchmark report containing immutable preflight/postflight, exact discovery, every command and exit status, raw-log checksum authority, focused results, bounded-suite comparison, direct matrix, earliest failures, semantic evidence, and remaining blockers.

Review policy is `never`, so a materially progressing validation turn's next-action plan becomes authoritative without an optional Review turn. Keep PR #8 open, draft, and unmerged. After all branch-file and PR-body writes, the final repository write is one new top-level PR #8 conversation comment.

## Completion record

Artifact `9029584083` was consumed exactly with no rebuild or repository-source edit. All seven focused contracts passed individually; prior-green direct plane, multi-face seam, close sheets, and cylinder behavior remained strict-valid **3/3**; and exact torus remained deterministic **0/3** at downstream `completion/output-validation / LocalSheetMismatch` after complete `4/8/4` authority consumption and materialized `1/0/0` topology.

The exact preflight, discovery, focused/group/bounded results, three-process direct matrix, postflight, and earliest production diagnosis are recorded in `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md`. This historical plan is no longer next-turn authority. The authoritative next turn is Code + Build under `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Code_Build_Plan.md`.

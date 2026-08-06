# Gate 1 Uniform Phase-Front Artifact-Only Test + Benchmark Plan

Date: 2026-08-06

## Turn boundary

This is the next **Test + Benchmark** turn. It must execute the packaged local artifact without configuring, compiling, relinking, regenerating, or editing source, tests, fixtures, build logic, or validators.

## Artifact authority

- archive: `directional-g1-local-build-artifact.zip`;
- archive SHA-256: `7e520acda5d402300711d1803a666e505ce4a03c0b92d969f5ae2ba3ca2d1f28`;
- source composition: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9` plus repository patch blob `aa18d454877ccf40d16f71f173fdaf765f5f1086`;
- uncompressed patch SHA-256: `48a01a37b038c59af18f2fca8904642f23bf8ea54f8ff8c3c784191dc99b8bf7`;
- executables: 5;
- static libraries: 2;
- fixtures: 26;
- internal checksummed files: 47;
- compile result: 112/112;
- tests and benchmarks executed during build: none.

The archive is currently available only in the active ChatGPT sandbox. A future session must use a user-provided re-upload or a recovered GitHub Actions artifact.

## Mandatory preflight

1. Verify the outer archive SHA-256.
2. Extract to a new arbitrary directory.
3. Run `sha256sum -c SHA256SUMS` from the artifact root.
4. Verify `metadata/source-authority.json` exactly names the base commit, branch checkpoint, repository patch blob, and patch SHA-256 values above.
5. Verify `metadata/implementation-git-blobs.txt` contains:

```text
a1ff3fa4c97af4f1fe55baa475c7e83c48f655f9  include/directional/geometry/SurfaceCellTracing.h
6e635768487321efd724e26d4c4f0bbf0140100b  src/geometry/SurfaceCellTracing.cpp
9f9ac145ccacf17a8d2c10e13771cf1ee22c5f61  include/directional/geometry/SurfaceArrangement.h
a2eaa6008a0fbb4ad9dc12d16ce0820ee940ac67  src/geometry/SurfaceArrangement.cpp
a4a06dc214e4a567b90ea6d87e4fef2d62a4de62  src/pipeline/RemeshPipeline.cpp
```

6. Verify 5 executable files, 2 static libraries, and 26 fixture/input files.
7. Verify the compile log contains 112 successful compile/link steps and no GoogleTest execution/discovery markers.
8. Do not continue if any identity, count, or checksum differs.

## Required direct acceptance order

Run every case in a fresh process and preserve raw stdout, stderr, exit code, wall time, and machine-readable output:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder.

Acceptance configuration remains:

- requested backend: `SurfaceCells`;
- executed backend must be `SurfaceCells`;
- fallback policy: `Fail`;
- source-grid recovery: disabled;
- paired-source-triangle boundary output: rejected;
- optional skeleton/debug paths: disabled;
- success origin: `CompletedSurfaceCells` only.

## Gate 1 material-progress test

The primary question is whether the new phase-front path advances the plane materially.

A Gate 1 pass requires:

- success;
- output origin `CompletedSurfaceCells`;
- non-empty output;
- pure quads;
- strict source-authoritative validation;
- no fallback or recovery;
- authoritative proposal-cycle arrangement path used;
- no fan-sector inference, positional merge, or post-hoc cycle decomposition.

If the plane still fails, record:

- whether the phase front was attempted and succeeded;
- grid dimensions, cell count, edge count, event count, and structural hash;
- proposal and arrangement counts;
- earliest invalid producer stage and exact invariant;
- whether failure occurs before or after arrangement materialization;
- whether the first invalid stage advanced relative to `completion/output-validation:AggregateCompletionValidationFailure`.

A new diagnostic string or counter without a later constructive stage is not material progress.

## Remaining default suites

After all four direct cases, run packaged suites without rebuilding:

1. `directional_surface_cell_producer_tests` excluding no tests unless a separate direct run already covers the same exact test cases;
2. `directional_surface_cell_completion_tests`;
3. `directional_surface_cell_validation_tests`;
4. `directional_compiled_api_tests`.

Report direct gate results before aggregate totals. Aggregate improvements do not offset a failed plane gate.

## Bounded benchmark

Run only the plane, seam, close-sheets, and cylinder benchmark cases:

- warmup: 0;
- measured runs: 1 per process;
- three independent processes per fixture;
- source-grid recovery disabled;
- no torus, sphere, thin tube, mechanical, or bunny run while the direct sequence fails.

Compare structural hashes, phase-front counts, terminal state, output origin, and timing across processes. Determinism is required; runtime speed is secondary while Gate 1 is red.

## Required outputs

- raw per-process logs and exit codes;
- machine-readable direct and benchmark results;
- artifact verification record;
- concise Test + Benchmark report;
- updated runtime summary;
- next Code + Build plan tied to the earliest missing Gate 1 contract;
- updated TODO, Milestone G TODO, handoff, and PR body;
- final top-level PR #8 handoff comment as the last repository write.

## Prohibitions

- no rebuild;
- no source, test, fixture, validator, or build edit;
- no fallback/recovery substitution;
- no fixture-specific acceptance weakening;
- no timeout-as-correctness;
- no expansion to blocked gates.
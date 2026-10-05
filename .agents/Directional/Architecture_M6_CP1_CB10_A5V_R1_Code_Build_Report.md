# M6-CP1-CB10-A5V-R1 Code + Build Report

**Turn:** `M6-CP1-CB10-A5V-R1`  
**Boundary:** Code + Build only; no Directional runtime.  
**Semantic source:** `96b456f925be00e00bad6645e6eb905a804c14ea`  
**Outcome:** COMPLETE / COMPILE+PACKAGE GREEN / CANDIDATE ONLY.

## Implementation

The bounded RA-19a recovery changes only:
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

R1 restores validation precedence by publishing the A5 `SurfaceOccurrenceComplex` first, returning any pre-existing A5 publication error unchanged, then running `validate_phase_front_authority_after_a5(...)` against that published complex. The helper consumes `complex.occurrences()`, `complex.certificate().directedSideCount`, and `complex.cells()`; the rejected A4/input-side rebinding is removed.

R2 strengthens `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` into the exact field-table oracle frozen by TB10 Review §J3. Expected mesh/result/lineage values are reconstructed test-side from A5/A6/A7 products, A4 isolation-certificate count, fixed compatibility constants, and value-initialized defaults. The adapter helper is not reused to construct expected output.

R3 static checks preserve the frozen authorities:
- focused24: `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`;
- focused20: `15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`;
- selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449: `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

No CB11 / RA-20 / RA-21 work was introduced.

## Patch transport

Work-preservation patch SHA-256:
`d1880a5512126e42026f4b515cc9094f0bd151e7a8b42171480bb20d7731faeb`

Patch apply run/job:
`37192632740 / 111407894004`

The reusable verified base `603d587d99536dd7a8314f326a00417da9086c43`, exact intended paths, full/diff-body hashes, `git apply --check`, changed-path equality, and `git diff --check`, then pushed semantic commit `96b456f925be00e00bad6645e6eb905a804c14ea`. It recorded `runtimeExecution=false`. The workflow identity could not trash the staged Drive object, so owner-authorized Google Drive deletion was performed successfully after the push.

## Mandatory compile/package gate

Compile run/job:
`37192727051 / 111408174395`

Result artifact:
`11299078582` — `sha256:142bac1bb485ff1f2b8017a08c8457053659867716c7b44edcceb117dca75afd`

Log artifact:
`11299068422` — `sha256:1ede0d090b85638a22b6aca19bfe5c7086cd0b35696ec1c7753e2744e77b6c50`

Evidence:
- exact source `96b456f925be00e00bad6645e6eb905a804c14ea`;
- preflight exit `0`;
- build exit `0`;
- all eight standard targets compiled and linked;
- GMP enabled and the authoritative link command contains both `libgmpxx.so` and `libgmp.so`;
- root package manifest **28/28** verified;
- all source-status receipts empty;
- `runtimeExecution=false`;
- no test, test discovery, benchmark, CLI, generated binary, ctest, fuzzer, help/version command, or custom input executed.

## Disposition

Candidate artifact/source `11299078582 / 96b456f925be00e00bad6645e6eb905a804c14ea` is compile authority only and remains unpromoted. Exact successor is immutable artifact-only `M6-CP1-TB10-A5V-R1-EXEC`, executing focused24 + selector449 = **473** fresh exact-filter processes, then mandatory `M6-CP1-TB10-A5V-R1-REV`. CB11 remains held.

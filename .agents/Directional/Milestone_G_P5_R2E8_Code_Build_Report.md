# Milestone G P5-R2E8 Code + Build Report

**Date:** 2026-08-05  
**Turn type:** Code + Build, compile-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged

## Result

P5-R2E8 compiled successfully from exact source commit:

- source commit: `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`;
- `SurfaceArrangement.cpp` blob: `76e57fef36f9322598387b6b5e968a14b885b755`;
- workflow run: `31041383154`;
- workflow event commit: `89423d0a49d7e1c2020cda87ee2333f35a3abe98`;
- configuration: Release, `-O2 -DNDEBUG`;
- compile/link actions: **132/132** completed;
- recursive submodules: **9**.

No test, benchmark, help/list/discovery command, CLI, GUI, or generated project binary was executed.

## Implementation

The higher-valence source-boundary path now constructs its local successor cover directly from canonical cyclic R1 corner pairs rather than treating the generic intrinsic successor arrays as complete boundary-sector authority.

The implementation:

1. inventories cyclic adjacent corner pairs from authoritative R1 wedges;
2. derives exact directed incoming/target sector records;
3. identifies and excludes the independently proven exterior continuation;
4. requires a complete one-to-one local incoming/target cover before publication;
5. preserves the degree-two and genuine four-disk paths;
6. derives hard-rail side chart roots from incident source-face corner evidence;
7. audits common chart ownership over predicted bounded rail-side orbits;
8. retains `leftScore` only as a consistency check after chart authority is established;
9. leaves all downstream validators unchanged.

Focused Milestone D assertions were strengthened to require two distinct incident hard-rail chart roots and the expected endpoint side-pair evidence. No fixture-specific IDs, validator weakening, fallback substitution, arbitrary subset search, positional merging, or post-hoc cycle repair was added.

## Compile-only verification

The bounded workflow configured and built exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

The final artifact contains the two packaged binaries, both static libraries, source snapshot, configure/build logs, submodule records, execution policy, build summary, and recursive checksum manifest. Every entry in the internal `SHA256SUMS` manifest passed verification.

## Artifacts

### Compiled checkpoint

- artifact ID: `8944910920`;
- name: `surface-cell-p5-r2e8-github-source-linux-release`;
- size: `12,234,549` bytes;
- archive SHA-256: `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`.

### Detailed workflow logs

- artifact ID: `8944911389`;
- name: `surface-cell-p5-r2e8-workflow-logs-31041383154`;
- archive SHA-256: `0c80533378c1b578a43d58739147b08cdb1c27c054b0c16ea585ac2bedd494ca`.

## Corrected orchestration attempts

Three bounded workflow attempts failed before the final successful compile:

1. run `31040645299` exposed one duplicated closing brace in the generated source transformation; logs artifact `8944487405`, SHA-256 `25ad51d7cd6b60640024d3c9aa4ef66d06a936443b5b28f7bcec7b4209f2802c`;
2. run `31041178219` failed before source modification because the staged base64 payload checksum did not match; logs artifact `8944613660`, SHA-256 `0d8ab86365765fd8d8f25f253ea5a732e12d9d7d7878cdfd324e018b8b7cd816`;
3. run `31041277215` failed before source modification because the copied base64 payload was malformed; logs artifact `8944654281`, SHA-256 `55094299cbce1807b1ea118304e7cd99d4a4bc654049529d5d66fd35a693c9c7`.

The transformation scope was then corrected exactly and compiled successfully. These failures do not provide runtime acceptance evidence.

## Hygiene

The successful source commit removed the temporary correction payloads. The bounded P5-R2E8 workflow was removed after artifact publication. No generated build artifact remains committed to the branch.

## Acceptance status

P5-R2E8 is **compile-valid but runtime-unvalidated**. No claim is made that the planar or hard-rail runtime failures are closed until the packaged artifact is executed in P5-TB36.

R2 remains open. Do not advance to R2F or R3.

## Next turn

Execute **P5-TB36 artifact-only R2E8 Test + Benchmark** against artifact `8944910920` and exact source `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`, with no rebuild or repository source modification.

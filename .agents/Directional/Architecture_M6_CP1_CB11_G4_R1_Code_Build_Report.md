# `M6-CP1-CB11-G4-R1` — Recovery Code + Build Report

## Result

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY.**

The RA-24 / RA-21d recovery is implemented and compiled. No Directional binary, test, benchmark, discovery command, or generated runtime was executed in this Code + Build turn.

## Semantic changes

- `src/pipeline/RemeshPipeline.cpp`: R1-0 replaces quad-opposite rung-set strip closure with RA-24 edge-loop closure. At each interior valence-4 quotient vertex, each incident edge continues to the unique incident edge sharing no classed quad. Boundary and non-valence-4 vertices are not joined; the canonical strip ordinal rule remains the smallest `SurfaceQuotientEdgeId`.
- `tests/SurfaceCellTransitionQuotientTests.cpp`, identity 25: uses per-occurrence arrangement-node witnesses, reciprocal phase-front side ownership, and exact A5 relation evidence. Exact chain/node equality is retained for Ordinary non-isolation edges and relaxed only for HardRail, Periodic, or isolation seams.
- Identity 28: independently reconstructs the RA-24 edge-loop partition on the produced torus, checks every emitted candidate against independently derived edge/vertex/cell/protection/degree facts, requires an eligible `ClosedLoop`, and retains the hard-feature tamper rejection.
- A pre-apply static pass found one compile-contract omission in the WIP patch (`std::iota` without `<numeric>`); it was corrected before any repository patch application. No production behavior beyond R1-0 changed.

## Patch authority

Final staged patch SHA-256: `49eb272c5433de5520fadced9615347d93f158f58e6e4ba627b0a549ccddd8ca`.
Diff-body SHA-256: `4a13bc081b94335c83e7affcaff1d774a05498677f981247c45f79e53880ad9b`.
Patch base: `d8b1aff8c12364ed587e61fddb8b3716dd9a57c3`.
Intended paths were exactly:

- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`

Drive apply run/job `37238821980 / 111543246587` succeeded and produced semantic commit `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`. Apply result artifact `11316508369` records the exact patch/base, `runtimeExecution=false`, and `drive_file_retirement_required=true`; owner-side Drive deletion then succeeded.

Control-plane note: the connector still has no direct reusable-workflow dispatch action, so the temporary caller could not be SchemaStore-validated before first publication. The exact active caller was fail-closed behind `agent-workflow-schema-validator-reusable.yml`, and that validation passed before patch application. This is procedural evidence only and grants no semantic credit.

## Mandatory compile/package evidence

Compile run/job: `37238936105 / 111543578349`.

All eight standard GMP/GMPXX targets compiled and linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Candidate result artifact: `11316716869`, provider digest `sha256:35f865b1016a0ec6f0d30b80dd0c33d7a01f9fbfcbb420ee43225398cf75415c`.
Diagnostic log artifact: `11316583672`, provider digest `sha256:8dae18c6538946a2e604178ca7d56a9142e05c3e58da9814f1e880964a562807`.

Verified locally from the result artifact:

- package manifest **28/28**;
- exact source `8dd958217d8cbda2d403f7a5c4c7dce242dde1c0`;
- preflight and build exit codes `0 / 0`;
- all source-status receipts empty;
- `exactArithmeticBackend=GMP` with both `gmpxx` and `gmp` on the authoritative link command;
- `runtimeExecution=false` and `turnBoundary=Code+Build-only`.

Frozen gate authority is unchanged by the two-file semantic patch: focused28 SHA-256 `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`; selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.

## Disposition

The candidate remains unpromoted. Stable accounting remains **60 events / 16 categories / 44 recurrences**, project debt **1**. No runtime acceptance or CP1 closure is claimed.

Exact successor: `M6-CP1-TB11-G4-R1-EXEC`, immutable artifact-only focused28 + selector449 = **477** fresh exact-filter processes, then mandatory `M6-CP1-TB11-G4-R1-REV`. `M6-CP1-CLOSE-REV` remains held.

# Gate 1 Phase-Front Orientation — Artifact-Only Test + Benchmark Plan

## Turn type

Artifact-only Test + Benchmark. Do not configure, compile, relink, regenerate, or edit source, tests, fixtures, build logic, or validators.

## Active gate

**Gate 1 — Uniform phase-front plane**

## Exact artifact authority

- archive: `directional-g1-orientation-local-build-artifact.zip`;
- archive SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- internal checksums: **45/45**;
- source commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- payload cleanup commit: `54a79a17f48bd3974367c3e043507d0550fb8daa`;
- package closure: five executables, two static libraries, 26 fixtures.

Expected source blobs are recorded in `.agents/Directional/Gate_1_Phase_Front_Orientation_Local_Code_Build_Report.md` and must be verified before execution.

## Required order

1. Verify the outer archive SHA-256.
2. Verify all 45 internal checksums.
3. Verify five executables, two libraries, 26 fixtures, source authority, and all five final source blobs.
4. Run the plane direct acceptance case in a fresh process.
5. Record the plane result before running any other fixture.
6. Run multi-face seam, close sheets, and cylinder in separate fresh processes, in that order.
7. Run the non-overlapping default suites only after direct evidence is recorded.
8. Run three independent bounded benchmark processes for each of the four analytic fixtures.
9. Do not expand acceptance to sphere, torus, thin tube, mechanical feature, or bunny while earlier gates remain red.

## Direct acceptance contract

Every case must use:

- requested and executed backend `SurfaceCells`;
- fallback policy `Fail`;
- no fallback attempt;
- source-grid recovery disabled;
- strict source-authoritative validation;
- output origin `CompletedSurfaceCells` for success;
- non-empty pure-quad output for success.

Fallback, recovery, input return, partial output, timeout, or legacy output cannot satisfy the gate.

## Plane observations

Report:

- terminal stage and reason;
- trace count;
- accepted phase-front cell count;
- arrangement/simplified cell count;
- completed/output quad count;
- validation-failure count and first invalid record;
- whether generic completion was bypassed;
- whether each accepted four-sided phase-front cell maps to one output quad-domain cell;
- orientation/incidence failure stage when direct materialization fails;
- fallback, recovery, and output origin;
- structural hashes across three processes.

## Material-progress classification

Gate 1 passes only with valid direct `CompletedSurfaceCells` output.

The turn still demonstrates material progress when the plane does not pass but one of these is proven:

- invalid winding/incidence fails closed at `tracing/phase-front-materialization`, before generic completion;
- valid cells preserve one-to-one direct materialization and reach a later strict-validation stage;
- `FlippedFace` and 65-to-409 generic expansion are eliminated under a general invariant.

A new diagnostic string, different count alone, faster failure, or aggregate suite change is not sufficient.

## Default suites

Run exactly:

- `directional_surface_cell_producer_tests` excluding the four direct cases already counted separately;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_compiled_api_tests`.

Report direct acceptance separately from aggregate totals.

## Integrity rules

- no source/test/fixture/validator edits;
- no rebuild or discovery regeneration;
- no assertion weakening;
- no synthetic counters or topology corrections;
- no fallback/recovery substitution;
- no timeout-as-correctness;
- every process must execute the packaged artifact directly.

## Exit products

- authoritative Test + Benchmark report;
- machine-readable runtime summary;
- raw per-process logs;
- exact command inventory and exit codes;
- next Code + Build plan only when Gate 1 remains red;
- updated TODO, milestone, handoff, and PR metadata;
- final top-level PR #8 handoff comment as the last repository write.

# Gate 2 Close-Sheet Authoritative Producer — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact ID: `8994541137`;
- artifact name: `g2-close-sheet-code-build`;
- artifact SHA-256: `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- source commit: `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- expected recursive checksum entries: **45/45**;
- successful build run/job: `31179899458` / `92870408341`;
- successful log artifact: `8994539982`, SHA-256 `c7d67285ca6b980111a53fe017b3de5800abccb2a3146352135c0d674ca0acc8`.

Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic. Runtime-only fixture symlinks are allowed only when needed to expose packaged paths without modifying packaged bytes.

Timeout is failure, never correctness evidence.

## Pre-execution integrity

Before running any project binary:

1. verify the outer artifact SHA-256 exactly;
2. extract into a fresh arbitrary directory;
3. verify all 45 recursive checksums;
4. verify five executables, two project libraries, and 27 fixture/input files;
5. verify source authority is `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
6. verify changed blobs:
   - `SurfaceCellTracing.cpp` `c9570ecb4a9557eebaf0e30b751e2ccca90b2973`;
   - `RemeshPipeline.cpp` `55af3205fd7cdb8f21357ac69516ffa29cf8a6d3`;
   - `SurfaceCellsPhase10Tests.cpp` `7151077d7d4e0a10dad388dd008479f96fc1aae8`;
7. verify the packaged command-boundary metadata says `runtimeExecution=false` for the Code + Build turn;
8. verify exact close-sheet, plane, seam, cylinder, bunny, and vase production fixtures are present before acceptance execution.

If integrity fails, classify the artifact as invalid infrastructure and stop. Do not repair packaged source or inputs.

## Explicit producer contracts first

Run these focused tests directly from the packaged producer-test executable:

1. `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`
2. `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`
3. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
4. existing ordered source-vertex-fan regression;
5. existing source-face-row-order phase-front regression;
6. existing duplicate-transition fail-closed regression;
7. mandatory bunny/vase topology guard.

Record each exact result. Do not weaken or replace a failing contract.

## Direct acceptance order

Run each in a fresh bounded process with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane — mandatory G1 regression;
2. multi-face seam — mandatory G2 cross-chart regression;
3. close sheets — active G2 acceptance fixture;
4. cylinder — later G3 observation only;
5. randomized bunny — later production observation only;
6. vase — later production observation only.

Later fixtures cannot make G2 pass if close sheets fails.

## G2 close-sheet acceptance

G2 closes only if the exact production close-sheet case demonstrates all of the following:

- authoritative producer disposition `Produced`;
- direct `CompletedSurfaceCells` output;
- non-empty pure-quadrilateral output, with the expected two independently paved sheets unless production target sizing legitimately changes the exact count;
- zero strict source-authoritative validation failures;
- no fallback attempt/use;
- source-grid recovery disabled/unused;
- complete source provenance;
- at least two distinct source `(component, localSheet)` groups represented in output provenance;
- no output vertex, edge, twin, cell, route, or ownership identity merges unrelated sheet groups;
- no world-space proximity coupling between the two spatially close sheets;
- deterministic structural/output hashes across independent processes.

Plane and seam must remain their already proven direct valid successes. A close-sheet improvement that regresses either passed fixture does not close G2.

## Required observations per direct case

Record at minimum:

- producer disposition;
- terminal stage and reason;
- requested/executed backend;
- phase-front attempted/succeeded and typed failure context;
- authoritative phase-front cell count;
- trace count;
- source component/local-sheet group counts;
- route/chart/transition provenance counts when available;
- arrangement, simplification, direct, completion, and output counts;
- output vertices, quads, and non-quads;
- connected output component count when available;
- strict validation failure count and first invalid reason;
- fallback/recovery state;
- output origin;
- producer/stage/structural/output hashes;
- wall time and exit code.

For `Rejected`, verify generic producer substitution does not occur. For `NotApplicable`, record that separately; do not reinterpret it as success.

## Determinism

After first-pass direct acceptance:

- plane: 3 independent processes;
- seam: 3;
- close sheets: 3;
- cylinder: 2 or 3 as bounded resources permit;
- bunny: at least 1 bounded process, second if reasonable;
- vase: at least 1 bounded process, second only if the first completes within the runtime budget.

Compare producer dispositions, source-sheet counts, stage counts, typed failure identities, structural hashes, and output hashes. Timeout remains failure only.

## Default suites

After the focused contracts and direct cases:

1. run the remaining producer suite excluding explicitly executed tests;
2. run completion/simplification suite;
3. run validation suite;
4. run compiled API suite.

Report direct gate acceptance separately from aggregate totals. Scheduler-sensitive timing checks remain closeout evidence and cannot override functional gate results.

## Decision hierarchy

### G2 closure

Close sheets is direct deterministic valid `Produced` output with strict sheet isolation, and plane/seam regressions remain valid. Next Code + Build gate becomes **G3 periodic cylinder/holonomy**.

### Material progress, G2 still open

The producer becomes applicable to the correct disconnected-sheet domain and advances to a new authoritative typed `Rejected` state or otherwise removes the prior structural ambiguity without cross-sheet coupling, while plane/seam remain valid. The next Code + Build turn addresses that exact general rejection.

### No material progress or regression

Close sheets remains on the same generic `NotApplicable` path without a justified new structural contract, authoritative output cross-merges sheets, `Rejected` falls through to generic substitution, or plane/seam regress. Keep G2 active and apply the no-progress rule if this is the second consecutive non-material Code + Build attempt.

## Required evidence

Preserve exact commands, raw stdout/stderr, fixture integrity, artifact digest/checksum verification, test results, benchmark JSON, determinism comparisons, machine-readable summary, and evidence archive SHA-256/recursive checksums.

## Prohibitions

- no rebuild or relink;
- no source/test/fixture/manifest/validator edits;
- no validator weakening;
- no fixture/ID special cases;
- no positional merging across unrelated sheets;
- no fallback/recovery substitution;
- no arbitrary subset search;
- no synthetic counters/Euler correction;
- no post-hoc cell merging;
- no timeout-as-correctness.

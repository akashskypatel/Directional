# Milestone G P5-R2E2 Test/Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Artifact-only Test + Benchmark

## Purpose

Validate whether authoritative pre-audit boundary-exterior successor construction closes the planar, interior-hard-rail, and open-cylinder arrangement producers without regressing R0/R1 authority, bridge/support ownership, explicit multi-boundary representation, or structural Euler accounting.

Use artifact `8916209271` directly. Do not configure, rebuild, relink, patch, regenerate, or modify implementation, test, benchmark, or build logic.

## Package authority gate

Before executing any packaged binary, require:

- artifact `8916209271`, `surface-cell-p5-r2e2-github-source-linux-release`;
- archive SHA-256 `2117cc2b99bc82a197bb7ee94f3e21a9c8f71b48f735c15c878515dabd4915df`;
- exact compiled source `f5305ade5bf5360df36b681d135e5299322f5fdb`;
- workflow event commit `517735a53e4554d74cab14845cb8e26edb90de37`;
- reviewed and applied source diff SHA-256 `526c01714d6d11ca8c4e60458b176f0057d386a6d163e406bb89fb04c86a83ec`;
- empty source status;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes match the Code + Build report;
- cleaned validation source contains only `agent-source-snapshot.yml` and zero temporary payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e2.yml`.

Reject the artifact if any authority check fails.

## Execution boundary

Run only the packaged binaries and packaged fixtures. Preserve raw stdout/stderr, GoogleTest XML, benchmark JSON, commands, wall time, process exit status, and memory evidence.

Do not:

- configure or compile;
- modify source, tests, fixtures, benchmarks, or scripts;
- use fallback, source-grid recovery, legacy output, or input substitution;
- accept an earlier failure stage as correctness progress;
- treat a timeout as a semantic result.

## Required focused scopes

Run independently and record exact pass/fail counts:

1. Source-chart R1 authority — require **11/11**.
2. Phase 22 source validator — require **6/6**.
3. Recovery authority — require **9/9**.
4. Feature/barrier authority — require **8/8**.
5. Graph-dependent contracts — preserve all non-bunny authority; classify the singularity-fan case separately.
6. All R2, R2C, R2D, R2E, and R2E2 arrangement contracts.
7. Milestone D closure contracts.
8. Phase 14–18 aggregate scope.
9. Phase 16 independently.
10. Phase 17 independently after arrangement inputs are observed.
11. Phase 18 independently — require **57/57**.
12. Phase 20 independently.

## R2E2 acceptance contracts

### Ordered source-boundary topology

Require:

- deterministic ordered source vertices and edges for every source boundary loop;
- one canonical orientation-insensitive identity per loop;
- source-face row permutation and whole-orientation reversal preserve loop identity and relevant hashes;
- closed source components publish zero source-boundary loops.

### Exact boundary coverage

Require focused coverage that proves:

- multiple subsegments on one source edge are ordered by exact parameter;
- complete exterior and interior interval coverage is accepted;
- gaps fail closed as `BoundaryCoverageGap`;
- overlaps and duplicates fail closed as `BoundaryCoverageOverlap`;
- endpoint mismatches fail closed as `BoundaryContinuationDiscontinuity`;
- contradictory side witnesses remain typed and fail closed.

### Exterior successor construction

Require:

- exterior `next` pointers follow authoritative source-loop order before orbit audit;
- every exterior cycle is endpoint-continuous;
- every exterior successor remains within the same committed exterior cell;
- interior hard rails do not split source-boundary exterior continuation;
- no runtime-valid halfedge has `cell == -1` after successful publication;
- exactly one exterior cell publishes per authoritative source boundary loop.

### Structural topology

Require:

- planar disk: one exterior cell, full bounded area coverage, Euler one, valid topology;
- interior hard rail: one exterior cell, intended bounded partition, complete ownership, valid topology;
- open cylinder: two exterior cells, nonzero bounded inventory, Euler zero, complete ownership, valid topology;
- nested annular bounded cell retains Euler zero and `NonDisk` classification;
- disconnected components preserve source component count and Euler without cross-component merging.

## Prior closure preservation

Require the following to remain clean:

- typed nonmanifold source-edge rejection;
- nested explicit multi-boundary representation;
- dangling bridge ownership;
- isolated support-only ownership;
- exact source ownership registry;
- orientation-reversal determinism;
- complete transactional orbit and cell ownership.

Any regression blocks the turn even when a new exterior contract closes.

## Direct analytic cases

Execute direct packaged benchmark cases with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

- plane;
- multi-face seam;
- close sheets;
- disconnected close sheets when available in the packaged matrix;
- cylinder.

For each case record:

- success/failure and earliest failure stage;
- arrangement, simplified, and completed inventories;
- quad count;
- topology/embedding/area diagnostics;
- fallback, recovery, and legacy flags;
- wall time and peak working set.

Seam, close sheets, and cylinder must retain nonzero valid arrangement inventories. Zero cells or earlier rejection is not progress.

## Complete suite and performance

Run the complete GoogleTest suite exactly once after focused scopes.

Record:

- discovered, passed, and failed counts;
- exact failure list and comparison with P5-TB29;
- normal termination or watchdog result;
- wall time;
- exact maximum RSS when the execution wrapper can preserve it, otherwise sampled RSS with the limitation stated;
- dominant long-running cases.

P5-TB29 baseline:

- **595/623**;
- 28 failures;
- **200.707 seconds**;
- sampled RSS at least **204,108 KiB**.

Do not characterize performance while correctness remains invalid. Do not accept runtime reduction caused by earlier failure.

## Decision rules

- Advance to intrinsic-fan R2F only when all source-boundary exterior, owner-cardinality, incidence, structural Euler, planar, hard-rail, and cylinder gates close independently and the bunny fan remains the only demonstrated R2 producer.
- Advance to R3 only after all R2 incidence, ownership, topology, and embedding gates close.
- If authoritative exterior construction remains invalid, identify the earliest producer and prepare the smallest next Code + Build plan.
- Do not patch Phase 17 or completion independently while their arrangement inputs remain invalid.

## Required outputs

Produce and commit:

- `.agents/Directional/Milestone_G_P5_TB30_Artifact_Only_R2E2_Test_Benchmark_Report.md`;
- `benchmark-results/p5-tb30-summary.json`;
- any bounded evidence bundle needed to reproduce the exact commands and results;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- one authoritative next Code + Build plan when R2 remains open.

Preserve all prohibitions: no validator weakening, frequency/count/order ownership selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.

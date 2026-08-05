# Milestone G P5-R2E3 Test/Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Artifact-only Test + Benchmark

## Purpose

Validate whether transactional boundary-node permutation splicing closes planar, interior-hard-rail, and open-cylinder incidence while restoring whole-orientation hash invariance and preserving all prior R0/R1/R2C/R2D/R2E authority.

Use artifact `8918054686` directly. Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, benchmarks, fixtures, or build logic.

## Package authority gate

Before executing any packaged binary, require:

- artifact `8918054686`, `surface-cell-p5-r2e3-github-source-linux-release`;
- archive SHA-256 `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`;
- exact compiled source `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`;
- workflow event commit `2d1d616eaf6e5be025e1a190b995172954d3f102`;
- reviewed and applied source diff SHA-256 `f7a26c3b3869a59247532e86f4468e0d17bce7caa72cf31a5c315b620fac1ff3`;
- empty source status;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes match the Code + Build report;
- cleaned validation source contains only `agent-source-snapshot.yml` and zero temporary payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e3.yml`.

Reject the artifact if any authority check fails.

## Execution boundary

Run only the packaged binaries and packaged fixtures. Preserve raw stdout/stderr, GoogleTest XML, benchmark JSON, commands, wall time, process exit status, and memory evidence.

Do not configure or compile. Do not modify source or validation inputs. Do not use fallback, source-grid recovery, legacy output, fixture substitution, validator weakening, or earlier failure as evidence of progress.

## Required focused scopes

Run independently and record exact pass/fail counts:

1. Source-chart R1 authority — require **11/11**.
2. Phase 22 source validator — require **6/6**.
3. Recovery authority — require **9/9**.
4. Feature/barrier authority — require **8/8**.
5. Graph-dependent contracts — preserve every non-bunny contract and classify bunny singularity-fan embedding separately.
6. All R2, R2C, R2D, R2E, R2E2, and R2E3 arrangement contracts.
7. Milestone D closure contracts.
8. Phase 14–18 aggregate scope.
9. Phase 16 independently.
10. Phase 17 independently only after arrangement validity is observed.
11. Phase 18 independently — require **57/57**.
12. Phase 20 independently.

## R2E3 acceptance contracts

### Canonical boundary-node classes

Require:

- one raw arrangement node per authoritative manifold source-boundary vertex and fan class;
- hard-rail endpoints do not duplicate that node across adjacent charts;
- pinched source-vertex fans remain distinct;
- close sheets and distinct components remain distinct despite positional coincidence;
- incompatible loop or fan aliases fail closed as `BoundaryAliasConflict`;
- source-face row permutation and whole orientation reversal preserve canonical classes.

### Complete node-local permutation

For every affected boundary node require:

- every incoming halfedge has exactly one successor;
- every outgoing halfedge has exactly one predecessor;
- every successor is endpoint-continuous;
- the authoritative exterior incoming follows ordered source-loop continuation;
- the complementary interior incoming receives the displaced intrinsic target;
- hard rails split bounded interior wedges without splitting exterior continuation;
- malformed local mappings fail closed as `BoundaryLocalPermutationConflict`;
- no partial successor state or cell publication survives failure.

### Canonical subsegment identity and hashing

Require:

- exact canonical low/high source-edge intervals are unchanged by orientation reversal;
- exterior/interior boundary twins share one canonical physical-subsegment identity;
- whole-orientation reversal restores equal directed-incidence hashes;
- source-face row order preserves incidence, orbit, and topology hashes;
- boundary incidence remains represented rather than omitted from hashing.

### Structural topology

Require:

- planar disk: complete permutation, one exterior cell, full bounded area, Euler one, valid topology;
- interior hard rail: one exterior cell, intended bounded partition, complete ownership, valid topology;
- open cylinder: two exterior cells, nonzero bounded cells, Euler zero, no `cell == -1`;
- nested annular bounded cell retains Euler zero and `NonDisk` classification;
- disconnected and close-sheet cases preserve component and ownership separation.

## Prior closure preservation

Require no regression in:

- typed nonmanifold source-edge rejection;
- explicit nested multi-boundary representation;
- dangling bridge ownership;
- isolated support-only ownership;
- exact source ownership registry;
- transactional halfedge/cell ownership;
- recovery and feature/barrier authority;
- Phase 18 **57/57**.

Any regression blocks the turn even when a new boundary contract closes.

## Direct analytic cases

Execute packaged direct cases with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

- plane;
- multi-face seam;
- close sheets;
- disconnected close sheets when available;
- cylinder.

For each case record success/failure, earliest failure, arrangement/simplified/completed inventories, quad count, topology/embedding/area diagnostics, fallback/recovery/legacy flags, wall time, and peak memory.

Seam, close sheets, and cylinder must retain nonzero valid arrangement inventories. Zero cells or earlier rejection is not progress.

## Complete suite and performance

Run the complete GoogleTest suite exactly once after focused scopes. Record discovered/passed/failed counts, exact failure list versus P5-TB30, normal termination, wall time, exact maximum RSS when available, otherwise sampled RSS with the limitation stated, and dominant long-running cases.

P5-TB30 baseline:

- **594/623**;
- 29 failures;
- **77.761 seconds**;
- one new orientation-reversal regression.

Do not characterize a shorter runtime as improvement when invalid incidence causes earlier termination.

## Decision rules

- Advance to R2F only when all source-boundary alias, local permutation, exterior ownership, structural Euler, planar, hard-rail, cylinder, and orientation-hash gates close independently and bunny remains the sole demonstrated R2 producer.
- Advance to R3 only after every R2 incidence, ownership, topology, and embedding gate closes.
- If R2E3 remains invalid, identify the earliest producer and prepare one smallest coherent Code + Build plan.
- Do not patch Phase 17 or completion independently while their arrangement inputs remain invalid.

## Required outputs

Produce and commit:

- `.agents/Directional/Milestone_G_P5_TB31_Artifact_Only_R2E3_Test_Benchmark_Report.md`;
- `benchmark-results/p5-tb31-summary.json`;
- bounded raw evidence sufficient to reproduce every command and result;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- one authoritative next Code + Build plan when R2 remains open.

After all documentation commits, post the required final handoff comment on PR #8. It must be the final repository write of the turn.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.

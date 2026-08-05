# Milestone G P5-R2E4 Test/Benchmark Plan

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Artifact-only Test + Benchmark

## Purpose

Validate whether direct canonical boundary-node rotational-system construction closes planar repeated-edge cycles, hard-rail local permutation conflicts, and open-cylinder non-disk publication while preserving the passing R2E3 orientation-invariant boundary identity and every prior R0/R1/R2C/R2D/R2E contract.

Use artifact `8929111021` directly. Do not configure, rebuild, relink, patch, regenerate, or modify implementation, tests, benchmarks, fixtures, or build logic.

## Package authority gate

Before executing any packaged binary, require:

- artifact `8929111021`, `surface-cell-p5-r2e4-github-source-linux-release`;
- archive SHA-256 `dcb3dcca095a62efde3bc534a8eafca1a5a3976f3e98b649845c6ca47c682450`;
- exact compiled source `ec44ab7570f258f800a27086fca053c573878a13`;
- workflow event commit `d81351aeb6bb7b728ceaf5bf468f924383167eb9`;
- reviewed and applied source diff SHA-256 `33ee4e40c7e5146abd732796b771d74ed28b7808bae6b0ed14bd327fd902aa01`;
- empty source status;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes match the Code + Build report;
- cleaned validation source contains only `agent-source-snapshot.yml` and zero temporary payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e4.yml`.

Reject the artifact if any authority check fails.

## Execution boundary

Run only packaged binaries and packaged fixtures. Preserve raw stdout/stderr, GoogleTest XML, benchmark JSON, commands, wall time, process exit status, and memory evidence.

Do not configure or compile. Do not modify source or validation inputs. Do not use fallback, source-grid recovery, legacy output, fixture substitution, validator weakening, or earlier failure as evidence of progress.

## Required focused scopes

Run independently and record exact pass/fail counts:

1. Source-chart R1 authority — require **11/11**.
2. Phase 22 source validator — require **6/6**.
3. Recovery authority — require **9/9**.
4. Feature/barrier authority — require **8/8**.
5. Graph-dependent contracts — preserve every non-bunny contract and classify bunny singularity-fan embedding separately.
6. All R2, R2C, R2D, R2E, R2E2, R2E3, and R2E4 arrangement contracts.
7. Milestone D closure contracts.
8. Phase 14–18 aggregate scope.
9. Phase 16 independently.
10. Phase 17 independently only after arrangement validity is observed.
11. Phase 18 independently — require **57/57**.
12. Phase 20 independently.

## R2E4 acceptance contracts

### Canonical rotational inventory

For every authoritative boundary node require:

- exactly one canonical SourceVertex or SourceEdge wedge contains every local outgoing ray;
- every outgoing ray appears once and its twin contributes one incoming ray;
- ray order is independent of source-face row order and whole-mesh orientation reversal;
- hard-rail, trace, component, sheet, and pinched-fan separation is preserved;
- incomplete or contradictory evidence fails closed as `BoundaryRotationalSystemConflict`;
- `boundaryRotationalNodeCount` is positive for boundary fixtures and derived from actual reconstructed nodes.

### Complete local rotation

Require:

- the authoritative exterior incoming maps to the authoritative exterior outgoing;
- every other incoming maps to the adjacent outgoing ray in the canonical interior rotation;
- every incoming is assigned once;
- every outgoing is targeted once;
- every mapping is endpoint-continuous;
- hard rails create distinct adjacent bounded sectors rather than crossing or joining sectors;
- no local map is implemented or observed as a two-target swap.

### Exterior-cycle prepublication audit

Require:

- exactly one exterior cycle per authoritative source-boundary loop;
- every exterior successor matches exact ordered-loop continuation;
- exterior cycles contain no interior rays;
- all exterior halfedges are visited exactly once;
- no partial successors or cells survive typed failure.

### Structural topology

Require:

- planar disk: no `RepeatedEdgeCycle`, one exterior cell, complete bounded coverage, Euler one, valid topology;
- multiple rays at one boundary vertex: one bounded sector per adjacent interior ray pair, complete local bijection, no repeated edge/node;
- interior hard rail: no `BoundaryLocalPermutationConflict` or rotational conflict, one exterior cell, two bounded cells, complete ownership;
- open cylinder: two exterior cycles, bounded cells all disks, Euler zero, no `cell == -1`;
- nested annular bounded cell remains Euler zero and `NonDisk` only where mathematically expected;
- disconnected, close-sheet, and pinched-fan cases remain separate.

### Canonical incidence identity

Require continued passing of:

- whole-orientation directed-incidence hash equality;
- source-face-row hash invariance;
- canonical low/high boundary interval identity;
- paired boundary-twin incidence representation.

## Prior closure preservation

Require no regression in typed nonmanifold rejection, nested multi-boundary representation, dangling bridge ownership, isolated support-only ownership, exact ownership registry, transactional halfedge/cell ownership, recovery and feature/barrier authority, and Phase 18 **57/57**.

Any regression blocks the turn even when a boundary case closes.

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

Run the complete GoogleTest suite exactly once after focused scopes. Record discovered/passed/failed counts, exact failure list versus P5-TB31, normal termination, wall time, exact maximum RSS when available, otherwise sampled RSS with the limitation stated, and dominant long-running cases.

P5-TB31 baseline:

- **595/623**;
- 28 failures;
- **142.550 seconds**;
- sampled RSS lower bound **169,268 KiB**.

Do not characterize runtime change as improvement while incidence remains invalid or execution terminates at different producer stages.

## Decision rules

- Advance to R2F only when all boundary rotational-system, exterior ownership, repeated-edge/node, disk, Euler, planar, hard-rail, cylinder, and orientation-hash gates close independently and bunny remains the sole demonstrated R2 producer.
- Advance to R3 only after every R2 incidence, ownership, topology, and embedding gate closes.
- If R2E4 remains invalid, identify the earliest producer and prepare one smallest coherent Code + Build plan.
- Do not patch Phase 17 or completion independently while arrangement inputs remain invalid.

## Required outputs

Produce and commit:

- `.agents/Directional/Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`;
- `benchmark-results/p5-tb32-summary.json`;
- bounded raw evidence sufficient to reproduce every command and result;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- one authoritative next Code + Build plan when R2 remains open.

After all documentation commits, post the required final handoff comment on PR #8. It must be the final repository write of the turn.

Preserve all prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.

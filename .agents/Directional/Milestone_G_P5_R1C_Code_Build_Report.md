# Milestone G P5-R1C Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

The P5-R1C source-chart orientation correction and exact four-target compile/package gate are complete. Runtime acceptance remains open because no packaged test, benchmark, mesh, or other project binary was executed in this turn.

Exact checkpoint:

- P5-TB23 tested source: `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- successful workflow event commit: `f652e518152b2944b176464b2ea8cfd99d09ccda`;
- R1C implementation and exact compiled source: `f4cce52006d21a248473e327ada1d66183af54e6`;
- applied source-diff SHA-256: `b41f4a6ffc517d1547a6da777fe01fc55e18e0b09aad47db83843333f6bea99c`;
- successful compile-only run: `30939748719`;
- job: `92094837803`;
- compiled artifact: `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`;
- artifact SHA-256: `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`;
- workflow-log artifact: `8904836090`, `surface-cell-p5-r1c-direct-workflow-logs-30939748719`;
- workflow-log SHA-256: `c8ef21410b17971ff7a4d6366c5da5a4b8df157be7fab3068e4c4efa021d7db3`.

Package verification:

- source status empty;
- recursive checksum manifest **40/40** verified;
- package contains **42** files total;
- fixture files **26**;
- recursive submodule records **9**;
- source archive contains the exact R1C implementation;
- all **132/132** Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable was run.

## Implementation

### Correct shared-edge orientation classification

`SourceChartTransitionGraph::edge_orientation` now treats a consistently oriented manifold source edge correctly:

```text
opposite directed traversal by the two incident faces -> accepted
same directed traversal by the two incident faces     -> rejected
```

The corrected implementation is:

```cpp
return firstDirection == -secondDirection ? -1 : 1;
```

This changes the earliest topology predicate exposed by P5-TB23. It does not weaken validation, bypass source-chart identity, or add fallback behavior.

### Whole-mesh orientation reversal contract

Added `SourceChartTransitionsR1.WholeMeshOrientationReversalPreservesCanonicalTransitions`.

The contract requires that globally reversing both incident face windings:

- leaves both transition graphs available;
- produces two inverse transitions in each graph;
- preserves canonical chart-component identity;
- preserves transition structural hashes.

The existing invalid single-face reversal contract remains unchanged and must still fail closed.

### Package Phase 22 validator contracts

Added `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` to the existing `directional_phase1_tests` source list.

This does not add a fifth target or remove the dedicated Milestone F validator targets. It makes the requested source-authoritative validator contracts available in the exact packaged test executable for P5-TB24.

## Build history

Three preliminary workflow attempts failed before source modification because repository file transport normalized or truncated staged patch payloads while the workflow checksum covered the original transport bytes:

- run `30939174809`;
- run `30939339160`;
- run `30939519904`.

Each failed before applying a source patch, and none executed a project binary. The final workflow replaced transport-byte assumptions with three exact, single-occurrence source transformations. Each transformation failed closed unless its expected source text occurred exactly once. The resulting source diff was hashed before commit as `b41f4a6ffc517d1547a6da777fe01fc55e18e0b09aad47db83843333f6bea99c`.

## Built-target hashes

- `directional_phase1_tests`: `c0b9f4f42439648a8310808035add730271eb63637e1eb1c16f55986cd20d67d`;
- `directional_benchmarks`: `34c9bd8456c6bd34c2ae9976650b90585985122fe3792b2a4c24bd982b03d833`;
- `libdirectional_core.a`: `98e807fc34a21f1b56520444a2345a3acfab75b1e351cd9090cfb2db91211ea9`;
- `libdirectional_pipeline.a`: `a25317b1dd713da2add62c7bde904d6c9e54dcd7160cef2767224a0a6d76fef8`.

The clean Ninja Release configuration used Ubuntu 24.04, GNU 13.3, `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional solver backends disabled.

## Runtime acceptance boundary

Compilation does not establish that:

- all `SourceChartTransitionsR1.*` contracts pass;
- all newly packaged Phase 22 validator contracts pass;
- intrinsic source-vertex fan construction is restored in runtime behavior;
- explicit planar recovery succeeds with `SourceGridRecovery` origin;
- Phase 14–18 returns to the P5-TB22 baseline;
- plane, seam, or close sheets complete directly;
- the complete suite terminates.

The next authoritative turn is **P5-TB24 artifact-only R1C validation** using artifact `8904835304` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Remain on R1 until the runtime gate is complete. Do not advance to R2 based on compile evidence.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

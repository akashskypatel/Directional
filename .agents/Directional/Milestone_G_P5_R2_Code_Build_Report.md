# Milestone G P5-R2 Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

P5-R2 directed source-chart wedge incidence implementation and the exact four-target compile/package gate are complete.

Runtime acceptance remains open. No packaged project binary, test, benchmark, custom mesh, help/list, or discovery command executed in this turn.

## Exact checkpoint

- P5-TB25 tested source: `a1fec970297739cfe23ade339b6a7b57071b7300`;
- R2 implementation commit: `9ca13956e8872f5221bcaf51142ef3474232495b`;
- reviewed R2 source-patch SHA-256: `e4da79427d33a5fd7bf29b707ec0765974faf0bc67c2dc18e6f2e6e6dd9a8658`;
- rollback identity typing commit: `eadfcd198adcbc6e960b89b3932510dcf71b15aa`;
- formatting-normalization commit and exact compiled source: `306fab5d440199cb090e1aa343fadb6112663edc`;
- formatting-fix SHA-256: `d0696338ecdf5cf9af57b9dca3d56260192c8fe12cf0122a98c45e8b31734522`;
- successful workflow event commit: `b332bb3119a133b957b2f573a5bd447d4ca62d4e`;
- successful compile-only run: `30949473754`;
- job: `92127660105`;
- artifact: `8908691591`, `surface-cell-p5-r2-final-github-source-linux-release`;
- artifact SHA-256: `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`;
- workflow-log artifact: `8908692488`, `surface-cell-p5-r2-final-workflow-logs-30949473754`;
- workflow-log SHA-256: `1f3cc3630d89f4aacf419d60ece84f9f5c8d5a4e8fa2e59cbb314c79421b97f6`.

Package authority was independently verified after download:

- exact source commit matches `source-commit.txt`;
- workflow event commit matches `workflow-event-commit.txt`;
- clean source status: empty;
- recursive checksum manifest: **41/41**;
- package files: **43**;
- fixture files: **26**;
- recursive submodule records: **9**;
- source archive contains the R2 incidence types, implementation, and focused contracts;
- all **132/132** Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No project binary executed.

## Implemented R2 semantics

### Typed directed-incidence authority

Added `SurfaceArrangementIncidenceFailure` with typed producer outcomes for:

- missing or ambiguous wedges;
- ambiguous intrinsic ray order;
- invalid twins;
- missing successors;
- duplicate predecessors;
- endpoint discontinuity;
- incomplete permutation coverage;
- repeated halfedge, node, or edge cycles;
- short cycles;
- unavailable source transitions.

Added diagnostics for directed wedge count, successor and predecessor failures, repeated-cycle counts, first typed incidence evidence, incidence validity, and a canonical `directedIncidenceHash`.

### Source-chart wedges before successor assignment

`SurfaceArrangement.cpp` now builds and validates the R1 source-chart transition graph before radial successor construction.

For each arrangement node it derives deterministic wedge witnesses from:

- source component;
- canonical R1 source entity and source-vertex fan identity;
- exact source-face transition reachability;
- source boundary and hard-rail sectors;
- nonmanifold and disconnected intrinsic fan barriers.

Local-sheet labels remain authoritative provenance but raw local-sheet equality is not reintroduced as an exact-adjacency gate.

### Intrinsic ordering within one admissible wedge

Outgoing halfedges are grouped and ordered only within one canonical wedge. Cross-chart ownership is derived from R1 source topology and transition maps rather than world-space angular proximity.

Geometric angular order remains available only where no cross-chart topology decision is required. Ambiguous authoritative source-vertex placement fails closed.

### One-to-one successor/predecessor permutation

Before enumerating cells, R2 now audits that:

- every directed halfedge has a valid symmetric twin;
- every halfedge receives exactly one successor;
- every successor receives exactly one predecessor;
- successor endpoints are continuous;
- no successor crosses a wedge barrier;
- the successor permutation covers the complete halfedge inventory exactly once.

Failure is transactional and records the first typed node, halfedge, twin, and successor evidence.

### Simple cycles before cell IDs

The prior post-hoc repeated-node cycle splitting was removed.

Successor cycles are enumerated only after the global permutation audit. Each accepted cycle must be:

- closed;
- halfedge-simple;
- edge-simple;
- node-simple;
- long enough to define a bounded face.

Repeated-node or repeated-edge cycles now fail the producer audit instead of being decomposed by occurrence, order, length, or position.

Exterior-cycle classification occurs before bounded cell IDs are assigned. Interior hard rails remain wedge barriers but are not treated as source exterior boundaries.

### Immediate consumer propagation

The new incidence authority and canonical hash are propagated into:

- arrangement diagnostics and structural hashes;
- simplification incidence validation;
- feasibility-repair rollback identity;
- pipeline diagnostics and failure messages;
- patch descriptor entry assumptions receiving arrangement cells.

Stale incidence failure evidence is cleared only after a later transactional simplification or repair produces a valid replacement arrangement.

No R3 topology catalog, R4 splice alternatives, R5 lattice state, R6 torus descriptor work, R7 adaptivity, R9 cache reuse, R10 lineage fixture work, or R11 memory telemetry was implemented.

## Compile-valid contracts

Added or strengthened contracts for:

1. complete directed-wedge successor/predecessor permutation;
2. adjacent local-sheet charts sharing an admissible intrinsic wedge through R1;
3. nonmanifold source-edge sectors failing closed with typed evidence;
4. whole-mesh orientation reversal preserving directed incidence;
5. source-face row ordering preserving `directedIncidenceHash`;
6. interior hard rails remaining non-exterior boundaries;
7. cylindrical periodic topology requiring valid incidence before commit.

These tests compiled into `directional_phase1_tests` but were not executed in this turn.

## Build history

The first compile run, `30948906671`, reached the new arrangement source and failed in rollback serialization because a braced initializer mixed 32-bit diagnostics with the 64-bit incidence hash. No project binary executed.

A first transport-only correction run, `30949268532`, failed before source modification because YAML heredoc indentation prevented the exact source match. No project binary executed.

The correction was then applied by marker-bounded source surgery, normalized with explicitly encoded indentation, and compiled from exact source `306fab5d440199cb090e1aa343fadb6112663edc`.

## Built-target hashes

- `directional_phase1_tests`: `41b97e7a1bbd1af67ba8a199bcfbd81158d3197498399b654b8da15d29e748ed`;
- `directional_benchmarks`: `1c2197ab4f54df674bd323aa80eefd615595cfc3620b00822246eebdf3e9f95a`;
- `libdirectional_core.a`: `05faf5ca18cfa63bd57f823f275684a921c72124d709fa67e92c2c46d2c5af23`;
- `libdirectional_pipeline.a`: `2d08351ee31f8ed22a95ab2983bdfc0689a968019d9b72da216276f5c0fc6bca`.

The clean Ninja Release configuration used Ubuntu 24.04, GNU 13.3, `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional solver backends disabled.

## Runtime acceptance boundary

Compilation does not establish that:

- all R1 gates remain clean;
- the new directed-incidence contracts pass;
- both Milestone D failures close;
- cylinder incidence is valid before completion;
- plane, seam, and close-sheet manifold/valence failures improve;
- Phase 14–18 and Phase 20 remain stable;
- the complete suite terminates;
- P5-TB25 bunny time and memory regressions improve.

The next authoritative turn is **P5-TB26 artifact-only R2 validation** using artifact `8908691591` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Remain on R2 until runtime proves a globally valid directed halfedge permutation and simple cycle inventory. Do not advance to R3 from compilation or from merely moving failures downstream.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

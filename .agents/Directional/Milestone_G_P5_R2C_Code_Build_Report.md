# Milestone G P5-R2C Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

P5-R2C directed boundary-sector and cycle-inventory implementation and the exact four-target compile/package gate are complete. Runtime acceptance remains open because no packaged test, benchmark, mesh, help/list/discovery command, or other project binary executed in this turn.

Exact checkpoint:

- P5-TB26 tested source: `306fab5d440199cb090e1aa343fadb6112663edc`;
- successful workflow event commit: `69e7486ad59bdec64e95bd1c6a5c3ac0289bf244`;
- P5-R2C implementation and exact compiled source: `94b86c50c38a849a744f40b0a21c86ed19551769`;
- reviewed source patch SHA-256: `7ed8df0b92da7719395a50fb8f4d93485e163345d7f11c82c5866bd7adabf79a`;
- applied commit-diff SHA-256, including temporary workflow/payload retirement: `ddb5a8ae90ac227afd3ce5f1deccecfb8f676314d0638e7b295c49a390fc0ec3`;
- successful compile-only run: `30959111826`;
- job: `92158870810`;
- compiled artifact: `8912374007`, `surface-cell-p5-r2c-github-source-linux-release`;
- artifact SHA-256: `ffe30c89655b60f5f7e90e509388c44b5a6c2c830508648348a4d01189ebb689`;
- workflow-log artifact: `8912374385`, `surface-cell-p5-r2c-fix-workflow-logs-30959111826`;
- workflow-log SHA-256: `e1f4ccd6d218b6505f6e97d04eef9533d71adb987cbca7ad4daf1f7357a66d6f`.

Package verification:

- source status empty;
- recursive checksum manifest **41/41** verified;
- package contains **43** files total;
- fixture files **26**;
- recursive submodule records **9**;
- source archive contains the exact R2C implementation and focused contracts;
- all **132/132** Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No project binary executed.

## Implementation

### Complete directed graph inventory

The R2 strict simple-cycle-only audit is replaced by deterministic graph-theoretic classification of each successor orbit:

- Tarjan bridge discovery identifies undirected cut edges;
- each bridge must appear exactly as its two authoritative twin halfedges;
- removing bridges yields non-bridge components that must each form one directed node-simple and edge-simple cycle;
- bridge components must form a forest with valid core attachment;
- every halfedge remains covered exactly once by the audited orbit and one published cell.

This preserves fail-closed rejection for malformed permutations while allowing valid source-boundary cuts and required support excursions to remain represented instead of being dropped.

### Explicit cycle/cell classes

`SurfaceArrangementCell` now records three explicit structural states:

- `cutCellDisk`: two or more valid simple boundary cores joined by an authoritative bridge forest;
- `bridgeExcursion`: a valid cycle core with a dangling bridge support excursion, retained as an explicit non-disk candidate;
- `supportOnlyCycle`: a bridge-only authoritative twin orbit with no area-bearing core, retained for topology/support ownership while excluded from area and Euler accounting.

These states are structural results of the audited halfedge graph. They are not selected by position, count voting, fixture identity, or post-hoc cycle decomposition.

### Boundary classification

Exterior classification now depends on authoritative source-boundary orientation evidence after incidence is complete. A negative geometric projection does not independently classify an interior hard rail as an exterior source boundary.

A valid cut-cell disk may use exact source-face support area only when the complete directed incidence audit succeeds but a single projected polygon is unavailable. Support-only cycles remain excluded from extracted-area and Euler accounting.

### Transactional cell publication

Cell publication now requires:

- every valid halfedge belongs to one audited orbit;
- every orbit receives one bounded cell ID;
- every halfedge in the orbit receives that cell ID;
- no valid halfedge remains `cell == -1`;
- a publication failure clears the cell inventory and resets halfedge cell ownership rather than returning a partially assigned valid-looking complex.

### Immediate consumers

The new structural states are included in:

- arrangement structural hashing;
- feasibility-repair rollback identity;
- simplification structural hashing and incidence validation.

Simplification accepts only the exact two-halfedge twin form for a support-only cycle. Support-only cycles are excluded from area/Euler totals, and rebuilt cells reset the structural flags before reclassification.

No completion-template, repeated-node splice, advancing-front, torus, adaptivity, cache, stage-lineage, or memory-telemetry work is included.

## Focused compile-valid contracts

Added or strengthened contracts for:

1. dangling bridge ownership without cycle decomposition;
2. isolated support bridge transactional ownership;
3. every valid hard-rail and cylinder halfedge receiving a cell ID;
4. interior hard rail remaining non-exterior;
5. cylinder producing no support-only cycles;
6. preservation of the existing directed-incidence, row-order, orientation, nonmanifold, and R1 contracts.

The tests compiled but did not execute in this turn.

## Build history

The first workflow run, `30959037906`, failed before source commit because its explicit `git add` named the ignored `.agents` payload deletion. The reviewed patch decoded, hashed, and applied cleanly, but no source was pushed and no project binary executed. The corrected workflow used tracked-file staging (`git add -u`) with the same reviewed source patch and compile boundary.

## Built-target hashes

- `directional_phase1_tests`: `c220bb8410e57433ba1b5006f51f24b04727990895d2de4d706a98740475239d`;
- `directional_benchmarks`: `31e223e528a0736f54a29d9821329049e22cbb35805295aa3e4545304f15a6b8`;
- `libdirectional_core.a`: `158368e563d681289e5426b2cec9e8f7e470a24d47a0239ec96f0811488bd94b`;
- `libdirectional_pipeline.a`: `ff87bcd4738b2f560cf35469471ff825e844b8c01e4826f35816edd283580fa1`.

The clean Ninja Release configuration used Ubuntu 24.04, GNU 13.3, `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional solver backends disabled.

## Runtime acceptance boundary

Compilation does not establish that:

- all R1 and R2 authority remains clean;
- every new R2C contract passes;
- Milestone D reaches **7/7**;
- Phase 16 and Phase 17 regressions are repaired;
- seam, close sheets, and cylinder retain nonzero valid arrangement inventories;
- no runtime-valid halfedge remains unassigned;
- Phase 14–18 or Phase 20 remains stable;
- the complete suite terminates;
- bunny duration and memory represent valid production progress.

The next authoritative turn is **P5-TB27 artifact-only R2C validation** using artifact `8912374007` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Remain on R2 until the runtime gate is complete. Do not advance to R3 based on compilation.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.

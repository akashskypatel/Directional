# Milestone G P5-CB135 through P5-CB142 Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

The P5-CB135 through P5-CB142 source checkpoint and exact four-target compile/package gate are complete. Runtime acceptance remains open because no packaged project binary, test, benchmark, or custom mesh was executed during this turn.

Exact checkpoint:

- prior tested source: `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- workflow event commit: `b7f8a9978764b77931ba6d299fdcbc65639235de`;
- implementation commit and exact compiled source: `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- reviewed patch SHA-256: `890dd621cf549f32c55d44f52b85050bfdfa5ce15df5f2bda2f8ba3e33c8ed70`;
- successful compile-only run: `30912858764`;
- job: `92003602916`;
- compiled artifact: `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`;
- artifact SHA-256: `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`;
- mandatory workflow-log artifact: `8894035556`;
- workflow-log SHA-256: `b7b84ba230c873702ec548318a5cad6b43fe4e1ccaf5d437bcd535201020ab1b`.

Package verification:

- source status empty before configure, build, and package;
- archive digest verified locally;
- internal recursive manifest **40/40** verified locally;
- package contains **42** files total, including the manifest and built-target hash file generated after the manifest;
- fixture files **26**;
- recursive submodule records **9**;
- source archive contains the P5-CB135–P5-CB142 changes;
- all **131/131** Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable was run.

## Built target hashes

- `directional_phase1_tests`: `e475dd7f64650254fc65ec0b3a32ca5093b1693403fc29c2356c38aec7eb0696`;
- `directional_benchmarks`: `fbe28f7dd1d7e583ce87af4ff11f11515e767915f685fd0c67cbb4e7b469d2e1`;
- `libdirectional_core.a`: `e69739744abbff3fe27335a9da3fa84f254a3eb01d7222afa06797c609d9f0c0`;
- `libdirectional_pipeline.a`: `9be7f7dc0c7f01ad573eb5502abb0848ce69b5d35fdc0600888593d87a195e5d`.

The clean Ninja Release configuration used GNU 13.3, `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional external solver backends disabled.

## Implementation summary

The implementation commit modifies ten production/header files with 631 insertions and 172 deletions. No production logic selects by fixture ID, input order, frequency, elapsed time, or geometric coincidence alone.

### P5-CB135 — canonical bounded alternative-state execution

Parity alternative repair now records a typed disposition and topology-derived execution evidence:

- candidate budget;
- attempted candidate count;
- visited canonical state count;
- selected excluded interface;
- deterministic sequence hash;
- per-state hashes;
- `Committed`, `NoCandidate`, `CycleDetected`, `BudgetExhausted`, or `AllInvalid` disposition.

The retry frontier is the finite canonical set of dual interfaces incident to the typed failing cell. Each canonical state is visited at most once, and replacement-boundary validation results are memoized. The earliest typed domain failure and exact rollback remain authoritative when no candidate commits.

This removes the previous operationally unbounded retry behavior without using wall time as correctness.

### P5-CB136 — broader repeated-node alternative frontier

The replacement producer no longer restricts alternatives to the first small prefix. It derives candidates from canonical incident DCEL interfaces, preserves edge-disjoint simple-cycle and ownership checks, and evaluates each bounded state through the same transaction audits.

Compilation does not establish that sphere, mechanical, or face-edge bunny obtains a valid alternative. P5-TB22 must verify successful commit or deterministic typed exhaustion with exact rollback.

### P5-CB137 — periodic successor-cycle decomposition

Arrangement repair now evaluates all repeated-node occurrences in a pinched successor cycle and selects a deterministic valid split only when both resulting directed cycles contain at least three edges. Cell assignment remains derived from directed adjacency and twin ownership.

Cylinder disk-cell closure, Euler characteristic, boundary-loop count, orientation, and rail preservation remain runtime gates.

### P5-CB138 — expanded bounded completion variants

Completion candidate generation now includes cyclic rotations and reversed orientation of the existing templates. Transition completion exposes six deterministic variants, while pattern and bounded-combinatorial completion expose a finite `2 * boundaryCount` catalog.

Every candidate remains subject to typed local embedding validation before authority. The earliest typed failure is preserved when all bounded variants reject. No invalid quad is accepted and no validator was weakened.

### P5-CB139 — separate semantic overlap and stitch separation

Same-corner repair now distinguishes semantic source-route overlap from stitch separation. Individual stitch-separation candidates are considered before coupled refinement. Completion-cache lookup uses its canonical dependency hash and then a finite exact-dependency comparison; a cached completion is counted as reused only after topology, ownership, lineage, and retarget validation pass.

Recompute and reuse counters remain operation-derived. P5-TB22 must prove valid annular completion, absence of duplicate stitched output, and genuine positive reuse/recompute.

### P5-CB140 — global intrinsic source-chart reconciliation

Stitching now receives source faces, components, and sheets. Shared output vertices preserve all candidate provenance. The global resolver intersects exact intrinsic source support, selects a canonical common source face, rebinds barycentric coordinates only under proven source-entity equivalence, and updates component/sheet ownership while preserving lineage.

Position and source-triangle pairing are not used as identity. Plane, seam, close-sheets, and disconnected-sheet behavior remain runtime gates.

### P5-CB141 — pipeline parity evidence propagation

Pipeline and patch contexts now retain the alternative-repair disposition, budgets, attempts, visited-state count, selected interface, sequence hash, and canonical state hashes. This allows stage-lineage tests to distinguish real completion failure, deterministic alternative exhaustion, and later injected failures without bypassing completion.

GP23, GP24, and Phase20 stage-entry/fallback lineage remain runtime-open.

### P5-CB142 — typed inventory and same-sample telemetry

Public incomplete-completion diagnostics now emit a stable typed reason name while retaining an explicit numeric reason code for machine compatibility.

Benchmark telemetry now records working-set bytes and categorized owned bytes at the same sample sequence, plus availability and reconciliation remainder. The JSON separates same-sample coverage from the legacy peak-owned/peak-working-set ratio. It does not sum unrelated phase maxima or claim unavailable coverage.

Torus completion and the 75% same-sample reconciliation gate remain runtime-open.

## Runtime acceptance boundary

Compilation does not establish:

- terminating full suite;
- clean focused or aggregate scopes;
- production **8/8**;
- valid cylinder topology;
- a committed repeated-node alternative;
- valid annular parallel-route completion;
- genuine positive reuse/recompute;
- globally source-sheet-consistent output;
- valid local variants for cylinder, thin tube, and bunny;
- GP23/GP24/Phase20 stage lineage;
- torus completion;
- bunny determinism and resource limits;
- at least 75% same-sample memory reconciliation.

The next authoritative turn is **P5-TB22 artifact-only test and benchmark** using artifact `8894034755` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

# Milestone G P5-CB126 through P5-CB134 Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

The P5-CB126 through P5-CB134 source checkpoint and exact four-target compile/package gate are complete. P5 remains open because no runtime test or benchmark was executed for this checkpoint.

Exact checkpoint:

- implementation commit: `01788193457e60bb8817a40b2c1551e672c4de5c`;
- compile-fix commit and exact compiled source: `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`;
- reviewed implementation patch SHA-256: `cb6b02838c08f68bb272b14a13b218572fcae88a58c9d3a73badbafd26b5421f`;
- test-only compile-fix patch SHA-256: `49ee91640fced0bf21a50fd614a40937ff5b261d4adee8e828262ba2d3e2dd29`;
- successful compile-only run: `30903283158`;
- job: `91972369451`;
- compiled artifact: `8890167812`, `surface-cell-p5-cb134-github-source-linux-release`;
- artifact SHA-256: `34a4da9a9c9e3374ed861c41b72493beefc90afbc85743fd25979484f3222bf1`;
- mandatory workflow-log artifact: `8890168646`;
- workflow-log SHA-256: `34da4a27f77c8e55e8a1369b535cf5230b8d3879dfa1da8f3768226943034191`.

Package verification:

- empty source status;
- recursive checksums **41/41**;
- fixture files **26**;
- recursive submodule records **9**;
- source archive contains the implementation and compile-fix commits;
- all 131 Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No test, benchmark, custom mesh, help/list/discovery command, or compiled project binary was executed.

## Built target hashes

- `directional_phase1_tests`: `144d1f4aa4e53c5b5704137c16bbfd8bc51decb85342bf2845c07f591ee65fce`;
- `directional_benchmarks`: `a2b4ef5f7eff8281a51ec8267f497d8fd9c27305d9bd715dc80f95a5a6dfec28`;
- `libdirectional_core.a`: `8bf7a7c8b41feab4c7bbb70321c0f5117e19a069d1c1e4fe6bc5fde89eb1935e`;
- `libdirectional_pipeline.a`: `ba337cea2a5cbc378bdab7ab69575969d9124d3aa049fe15fdb55359f39a36e4`.

The clean Ninja Release configuration used `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional external solver backends disabled.

## Implementation summary

The implementation commit changes 11 source/test files with 666 insertions and 179 deletions. The follow-up compile fix changes only two namespace qualifications in one regression source.

### P5-CB126 — valid provenance fixture and negative embedding regression

`CompletionVerticesCarrySourceProvenance` now uses a simple regular polygon embedded on `z=1` while preserving the intended source face, component, sheet, barycentric, and position assertions. A separate `ZigZagBoundaryFailsEmbeddingValidation` regression retains the old non-simple zig-zag geometry and requires typed `InvalidCompletionQuadEmbedding` rejection.

The production embedding validator was not weakened. Runtime closure of Phase 14–18 remains a P5-TB21 gate.

### P5-CB127 — typed shared-parity baseline and transaction preference

The two-odd-cell fixture now assigns explicit component/sheet ownership to node occurrences and interior source charts, then performs a typed incidence audit before parity repair. Parity dual-edge cost now deterministically prefers bounded-to-bounded interior interfaces over boundary/exterior interfaces while retaining hard-feature penalties.

Compilation does not establish that the fixture is valid or that the conforming transaction succeeds. Runtime must verify the initial audit, atomic shared-interface split, topology refresh, and rollback identity.

### P5-CB128 — topology-only pinched-cycle decomposition

Surface arrangement construction now detects successor cycles that revisit a `from` node and decomposes the affected directed edge set into edge-disjoint simple cycles. It rewires `next` pointers before cell assignment using directed DCEL adjacency only.

No position, face-row order, fixture ID, or source-triangle pairing is used. Cylinder Euler characteristic, boundary loops, disk cells, orientation, and protected rail preservation remain runtime gates.

### P5-CB129 — bounded deterministic alternate parity routes

Parity repair now computes a deterministic initial T-join and, when typed replacement-boundary validation fails, evaluates only bounded single-edge exclusions incident to the typed failing cell. Each candidate recomputes the T-join and must pass incidence, domain, ownership, and rollback checks before commit. The first typed failure remains authoritative when every bounded alternative fails.

This is not arbitrary subset search and does not select by frequency, count, fixture ID, or input order. Runtime must establish whether mechanical, sphere, and face-edge cases obtain a valid alternative.

### P5-CB130 — two-layer same-corner route ownership

Same-corner arbitration now treats equal embedded geometric/source-route identity as semantic overlap even when raw rail or curve identifiers differ. Genuinely distinct routes use canonical boundary occurrence and source-route identity, and only one canonical route is refined to preserve unaffected completion-cache entries.

The change is intended to reject renamed semantic duplicates, permit a valid annular route, prevent duplicate stitched output, and expose real cache reuse. Positive `reused > 0` and `recomputed > 0` remain runtime requirements; counters were not synthesized.

### P5-CB131 — original-failure preservation

`fail_surface_cells` now preserves an already-recorded original surface-cell failure instead of overwriting it during later failure propagation. Completion validation and fallback selection were not bypassed.

The wider GP23/GP24/Phase20 declared-stage injection and fallback-lineage contracts remain runtime-open because this compile-only checkpoint cannot prove that fixtures reach their intended later stages.

### P5-CB132 — typed local embedding evidence

`PureQuadCompletionResult` now carries `PureQuadEmbeddingFailure` with:

- failure classification;
- owning patch/cell;
- backend and bounded variant;
- local quad and corner vertices;
- component and sheet;
- supporting source faces.

Typed classifications include duplicate mesh vertex, invalid cardinality, repeated quad vertex, missing or nonfinite position, degenerate normal, zero projected area, and bow-tie crossing. Completion and pipeline contexts propagate the first embedding failure, and benchmark JSON exports it.

Runtime must identify the exact producer for general fallback, cylinder, thin tube, and smooth bunny and establish whether bounded variants repair them.

### P5-CB133 — source-sheet-consistent completion ownership

Completion-domain ownership validation now receives the source face matrix and resolves multi-face boundary support using canonical intrinsic source-vertex identity. It rebinds source-vertex and source-edge barycentric coordinates to a compatible owning component/sheet chart while preserving geometry and lineage.

Incomplete-complex diagnostics now include descriptor, cell, reason, attempted/failed/total inventory counts. Runtime must verify removal of `LocalSheetMismatch`, cross-patch chart agreement, valid global output, and torus completion inventory.

### P5-CB134 — telemetry and compile/package gate

Benchmark output now distinguishes categorized peak owned bytes, whether same-sample ownership measurement is available, and explicit peak reconciliation remainder. It does not claim same-sample coverage when the measurement is unavailable.

The requested 75% reconciliation threshold remains open. The checkpoint does not synthesize ownership categories or sum phase maxima.

## Compile correction

Initial run `30902693111` applied and pushed the full implementation as commit `01788193457e60bb8817a40b2c1551e672c4de5c`, then failed while compiling `PatchDescriptorMilestoneETests.cpp` because the new incidence audit was referenced from `directional::geometry` instead of `directional::geometry::surface_simplification_detail`.

That failed run executed no project binary and uploaded mandatory log artifact `8889884342` with SHA-256 `b3f41643b614ff4caaf3f5973524663ea7f2c1933fe0518c0f4c891f00a71171`.

The follow-up commit `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f` corrects only those two test namespace qualifications. Run `30903283158` then compiled and packaged the exact corrected branch head successfully.

## Runtime gates still open

Compilation does not establish:

- Phase 14–18 restoration to **235/235**;
- full-suite improvement from P5-TB20's **581/599**;
- a valid shared-parity baseline or conforming repair;
- canonical open-cylinder DCEL closure;
- a successful bounded alternative after repeated-node rejection;
- semantic duplicate rejection plus valid annular-route completion;
- genuine positive reuse/recomputation;
- GP23/GP24/Phase20 stage, injection, fallback, and original-failure lineage;
- valid local completion variants;
- source-sheet-consistent nonempty manifold pure-quad production output;
- torus/thin-tube completion;
- successful random-bunny output, resource limits, or determinism;
- at least 75% same-sample memory reconciliation.

## Required next turn

Proceed with **P5-TB21 artifact-only test and benchmark** using artifact `8890167812` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Follow `.agents/Directional/Milestone_G_P5_CB134_Test_Benchmark_Plan.md`.

P5 remains open. PR #8 remains open, draft, and unmerged.

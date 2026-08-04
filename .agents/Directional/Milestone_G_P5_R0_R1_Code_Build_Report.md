# Milestone G P5 R0–R1 Code/Build Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** code changes plus compile-only build

## Disposition

The reoriented P5-R0/R1 implementation and exact four-target compile/package gate are complete. Runtime acceptance remains open because no packaged test, benchmark, custom mesh, or other project binary was executed in this turn.

Exact checkpoint:

- P5-TB22 runtime baseline source: `aa2917e280fabd2272911a39cd0ecc327cce1cf3`;
- successful workflow event commit: `233466e5b02c3762a3f2648518f5860a2a2fb014`;
- R0/R1 implementation commit: `ae0c09ed1290df75d1d2cc1d5af039fc1feb83a3`;
- compile-propagation fix and exact compiled source: `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- reviewed R0/R1 patch SHA-256: `a3898a847c6722a1f2d9b0de48e71ae71f08fcc0bc82b3d9396d8c842d9cad61`;
- compile-fix patch SHA-256: `92162aa709134c86a355253416dc614817fecabebaeb60c58555061958d12162`;
- successful compile-only run: `30932812460`;
- job: `92071429858`;
- compiled artifact: `8902050372`, `surface-cell-p5-r1-github-source-linux-release`;
- artifact SHA-256: `5d1e5ca4fa8bc74e0a30615725c79a8b491830ab1f4407152cf79bfe56f8880f`;
- workflow-log artifact: `8902051026`, `surface-cell-p5-r1-fix-workflow-logs-30932812460`;
- workflow-log SHA-256: `dee5e429cb9a57ee9b45db42d27b512c7b096aed875147a01364e5a757f4b5a6`.

Package verification:

- source status empty;
- recursive checksum manifest **41/41** verified;
- package contains **43** files total;
- fixture files **26**;
- recursive submodule records **9**;
- source archive contains the R0/R1 implementation and compile fix;
- all **131/131** Ninja actions completed.

The workflow compiled exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

No project binary, test, benchmark, custom mesh, help/list/discovery command, or generated executable was run.

## Build history

The first compile-only run, `30932407728`, correctly failed closed after applying and committing the reviewed implementation. It exposed two mechanical propagation omissions in `PureQuadCompletion.cpp`:

1. one ownership-label call did not pass the newly required hard-feature transition barrier set;
2. the source definition of `stitch_pure_quad_patches` did not include the new parameter already declared in its header.

The follow-up commit only corrected those signature and call-site omissions. It did not change the R0/R1 algorithm. Run `30932812460` then completed the clean four-target build and package gate.

## Built-target hashes

- `directional_phase1_tests`: `2f89e48eccd301eb6adbe904898e4b4196064e61fb564545082148ac457d0f39`;
- `directional_benchmarks`: `78a1130b1961ee0ec66e27191de3746a292933352033a983fd4924d04069f282`;
- `libdirectional_core.a`: `ea33a700b418fdd3714c7791d55fbbd9b7445cd69291f2fc80fe9a7dc9fbf833`;
- `libdirectional_pipeline.a`: `a25317b1dd713da2add62c7bde904d6c9e54dcd7160cef2767224a0a6d76fef8`.

The clean Ninja Release configuration used GNU 13.3, `-O2 -DNDEBUG`, static libraries, tests and benchmarks enabled, CLI/GUI disabled, and optional external solver backends disabled.

## R0 — repair freeze and recovery authority

Implemented:

- `allowSourceGridRecovery` now defaults to `false`;
- successful source-grid recovery reports `SurfaceCellOutputOrigin::SourceGridRecovery`, distinct from `CompletedSurfaceCells`;
- direct `SurfaceCells` requests remain fail-closed under fallback policy `Fail`;
- tests that intentionally exercise recovery must opt in explicitly;
- no new downstream cache, memory, lineage, FlowRep, or completion-search work was introduced.

This prevents recovery from silently satisfying direct surface-paving acceptance.

## R1 — canonical source-entity chart transitions

Added `SourceChartTransitions.h` with explicit source-authoritative concepts for:

- chart identity `(component, localSheet, sourceFace)`;
- source entity kind and canonical identity;
- orientation-aware source-edge transitions;
- exact barycentric edge and vertex rebinding;
- intrinsic source-vertex fan partitioning;
- component, sheet, boundary, nonmanifold, and hard-feature barriers;
- deterministic canonical chart/entity representatives;
- inverse-transition and inconsistent-winding validation.

Integrated the transition graph into:

- arrangement-node source-chart identity and missing-face occurrence rebinding;
- completion generated-vertex ownership and provenance validation;
- shared completion vertex and edge stitching;
- optimizer and pipeline propagation of hard-feature edge barriers;
- source-authoritative validation and source-chart disagreement diagnostics.

World-space proximity and source-triangle pairing are not used as identity.

## Compile-valid contracts added or updated

The source now contains contracts for:

- exact adjacent-source-edge transition and inverse rebinding;
- source-vertex reconciliation within one intrinsic fan;
- hard-feature rail separation;
- disconnected, opposite-sheet, and nonmanifold fan separation;
- source-face row permutation invariance;
- source orientation reversal and canonical inverse transitions;
- inconsistent edge winding rejection;
- validator behavior across hard-feature barriers;
- exact default-off recovery and distinct recovery origin;
- rollback/fail-closed behavior when chart reconciliation is unavailable.

These tests compiled but were not executed.

## Runtime acceptance boundary

Compilation does not establish that:

- the new focused transition contracts pass;
- plane, multi-face seam, or close sheets complete directly;
- disconnected close sheets remain distinct under full production assembly;
- all previous Phase 14–18, validation, and pipeline scopes remain clean;
- `LocalSheetMismatch` is eliminated from the three analytic producers;
- the full suite remains **585/600** or improves;
- direct production improves from **0/8**.

The next authoritative turn is **P5-TB23 artifact-only R0/R1 validation** using artifact `8902050372` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

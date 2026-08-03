# Milestone G P5 — Rollback Integrity and Successful-Path Memory Code + Build Plan

**Next turn:** code changes + compile-only build  
**Input artifact:** P5-TB12 artifact `8852049639`  
**Exact tested source:** `0980c0912a2538314bb6bbb77dc7d4dbbcea5bc5`  
**Review policy:** `never`

## Objective

Restore authoritative topology rollback and descriptor production, eliminate the two deterministic production-matrix segmentation faults, complete exact product reuse, and preserve the substantial memory reduction without relying on an early failure path.

This is a code changes + compile-only build turn. Compile the four required targets and execute no binary.

## P5-CB59 — Restore authoritative side-repair rollback ownership

The current completion pass moves the parity-repaired complex into side repair and, on a permitted side-repair failure, treats the returned `sideRepair.complex` as an unmodified rollback complex. P5-TB12 instead fails deterministically with `InvalidArrangementDomainIdentity;firstPatch=2;secondPatch=-1` before producing descriptors.

Implement an explicit transaction contract:

- A failed side-repair transaction must return the exact last committed canonical complex, not its partially mutated candidate.
- Represent rollback ownership without keeping two full complexes alive concurrently. Acceptable designs include in-place transactional mutation with an inverse/undo log, copy-on-write only for touched cells and halfedges, or ownership transfer that retains the committed base until commit.
- Do not reconstruct rollback topology from local IDs, source triangles, geometric proximity, or final-face deduplication.
- Validate the canonical arrangement-domain identities immediately before and after side repair; record a typed failure if the transaction violates rollback equivalence.
- Preserve the successful side-repair fast path and move semantics.
- Add regression sources that force a permitted side-repair failure after tentative insertions and prove bit-for-bit canonical domain, boundary, source-support, rail, component, and sheet identity equality with the pre-transaction complex.

## P5-CB60 — Restore descriptor and fail-closed completion contracts

After rollback integrity is restored:

- Ensure authoritative descriptors are derived for every valid retained arrangement cell and exterior/non-authoritative cycles remain excluded.
- Restore the intended shared-edge parity and Milestone E entry-point fixtures without weakening topology validation.
- Require the typed `SameCornerDistinctBoundaryOverlap:` rejection to remain visible before candidate expansion.
- Preserve empty final output on all failures, but do not erase valid intermediate descriptor diagnostics needed to identify the responsible stage.
- Add precondition assertions to every corrected fixture so a test cannot pass or fail vacuously.

Target regressions:

- `SharedEdgeParityRepairConforminglyCompletesTwoOddCells`;
- `CompletesAuthoritativeComplexThroughMilestoneEEntryPoint`;
- `ExteriorArrangementCyclesAreNotAuthoritativeCompletionPatches`;
- `SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion`.

## P5-CB61 — Complete exact reusable-product semantics

P5-TB12 still reports zero reused patch completions in fixtures with genuinely unaffected patches.

- Define one canonical dependency identity for a completed patch using arrangement-domain identity, canonical boundary and rail support, source support, component/sheet identity, completion backend, and variant.
- Exclude allocation-local row, cell, vertex, halfedge, and patch numbering from equality unless it is itself semantically authoritative.
- Keep collision-safe exact equality behind hashes.
- Separate cache ownership from rollback ownership so extracting or moving reusable products cannot empty the authoritative result.
- Record deterministic reuse/mismatch reasons in test/debug diagnostics.
- Require unaffected products to reuse and affected products to recompute exactly once.
- Preserve bounded cache memory and release superseded entries after transaction commit or rejection.

Target regressions:

- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
- `OneCandidateBudgetIsExactAndDoesNotRecurse`.

## P5-CB62 — Isolate and eliminate production-matrix segmentation faults

Two packaged tests independently exit with signal 11:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`;
- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`.

Implement compile-time instrumentation and regression structure that allows the next test turn to identify the active manifest case before entering and after leaving each pipeline invocation.

- Make each matrix case independently executable through parameterized or uniquely named tests while preserving the aggregate matrix contract.
- Audit lifetimes of moved `SurfaceCellContext`, retained debug artifacts, completion products, output lineage, and diagnostic string/vector views.
- Remove dangling references, references into moved-from containers, and pointers/spans surviving stage release.
- Ensure failed and successful results own every diagnostic payload they expose.
- Do not suppress the crash, skip production cases, catch access violations, or reduce manifest coverage.
- Add a regression source that destroys the pipeline context immediately after result return and then reads all retained public diagnostics/output, proving independent ownership.

## P5-CB63 — Restore Phase 20 and Milestone D provenance contracts

Correct the regressions without changing expectations to match broken output:

Phase 20:

- `LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails`;
- `PairedBoundaryProofGateIsExplicit`;
- `PairedBoundaryOutputFailsClosedWhenRecoveryIsDisabled`.

Milestone D:

- `PartialMultiEdgeInterfaceFailsClosed`;
- `CompleteInterfaceCommitsAndPreservesProtectedRails`;
- `CylindricalOpenStrandCommitsWithTopologyPreserved`.

Required behavior:

- authoritative rails remain available until every consumer has materialized its own compact identity/proof;
- production intermediate release must not erase the proof before diagnostics/result transfer;
- interface discovery and topology validation use canonical graph identities, not moved-from vectors;
- paired-boundary failures retain their typed lineage reason while final output remains empty;
- no recovery or legacy fallback is introduced.

## P5-CB64 — Preserve memory reduction on the successful completion path

The P5-TB12 maximum was `158,949,376 B`, but completion stopped before descriptors. Retain the lifetime improvements while restoring full production progress.

- Keep `retainIntermediateGeometry = false` as the production default.
- Keep one canonical rollback complex and at most one mutable candidate through transactional ownership, not through duplicate full complexes.
- Keep compact ownership records and deferred final output allocation.
- Release descriptor and completion-product capacity incrementally once it cannot be reused or returned.
- Avoid retaining both pre- and post-transaction complete patch vectors; use a sparse replacement set and stable immutable products.
- Extend owned-byte diagnostics to include trace, FlowRep, arrangement, simplification, descriptor, completion-product, assembly, provenance, and final-output categories.
- Add deterministic peak-live-object counters and an estimated peak-owned-byte total.
- Do not weaken exact diagnostics merely to reduce memory; store compact canonical identities and materialize bounded verbose records on demand.

The next test turn must measure a successful zero-conflict output. Early-failure memory is not an acceptance result.

## P5-CB65 — Deterministic successful-path integration coverage

Add or correct regression sources that establish:

- a permitted side-repair failure resumes from the exact canonical rollback complex and completes descriptors;
- reusable unaffected products are observed;
- a successful completion-template batch reaches zero conflicts;
- result diagnostics remain valid after all source contexts are destroyed;
- each production manifest case can run independently;
- random-bunny reaches descriptor derivation and ownership inventory rather than failing domain validation;
- success implies nonempty pure-quad output, valid lineage, and no fallback/recovery.

Do not execute these tests in this turn.

## P5-CB66 — Compile-only gate

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Use a clean optimized static Ninja build with shallow submodules. Package:

- exact pushed source and empty source status;
- both executables and both static libraries;
- complete executable-relative fixture closure;
- configure/build logs and recursive submodule revisions;
- checksum manifest;
- no patch-materializer or workflow source payload.

Execute no test, benchmark, custom mesh, compiled binary, help/list command, or discovery command.

## Following artifact-only gates

The following P5-TB13 turn must require:

- all twelve P5-TB12 assertion regressions pass;
- both former matrix crashes pass independently and in aggregate;
- full packaged binary completes from an arbitrary path;
- four random-bunny processes produce deterministic nonempty pure-quad output with zero ownership conflicts;
- no fallback or recovery;
- wall `<= 39.228299 s` in every process;
- peak RSS `<= 1,115,394,560 B` in every process;
- report successful-path memory versus both P5-TB11 `936,484,864 B` and P5-TB12 early-failure `158,949,376 B`;
- reconcile process RSS with expanded stage-owned byte diagnostics.

P5 may close only after these gates pass without synthetic tests or prohibited recovery behavior.

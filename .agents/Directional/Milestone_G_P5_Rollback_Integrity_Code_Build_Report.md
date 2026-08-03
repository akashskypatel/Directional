# Milestone G P5 — Rollback Integrity Code + Build Report

**Turn:** P5-CB59 through P5-CB66 code changes + compile-only build  
**Review policy:** `never`  
**Runtime status:** unverified; P5 remains open

## Exact checkpoint

- Implementation commit: `4dcba533915aad116824f5e47e91a47a440e7718`.
- Exact compiled source: `074ec5d125b531db03fcfbda9d6d3654bfc696b7`.
- Compile-only run / job: `30824384650` / `91722103206` — **success**.
- Artifact: `8860409984` (`surface-cell-p5-cb66-rollback-integrity-linux-release`).
- Artifact digest: `sha256:37c04eaa694a87ed9ab4f48b2123b54f52c0a0d16d8fb9672d367ebdfdbfcee3`.
- Build: **131/131 steps completed**.
- Source status: empty.
- Packaged checksums: **36/36 verified** after normalizing the archive-time `artifact/` prefix.
- Packaged benchmark fixture files: **26**.
- Tests, benchmarks, custom meshes, help/list commands, test discovery, and compiled binaries executed: **none**.

## Implemented scope

### P5-CB59 — exact rollback ownership

- Added an exact rollback identity over arrangement nodes and occurrences, halfedges and provenance, cells, logical-side metadata, source component/sheet identity, rails, and topology diagnostics.
- Added before/after rollback hashes and an explicit `rollbackEquivalent` proof to subdivision, side repair, pipeline diagnostics, and benchmark JSON.
- Reworked subdivision rejection around one committed complex and a compact undo log for mutated cells plus appended-node truncation. Rejected transactions restore the committed topology rather than returning a partially mutated candidate.
- Permitted handoff from side repair to the general completion backend now requires a successful exact rollback proof.
- Inserted subdivision nodes derive source-face support from both endpoints and both halfedge directions while preserving source component, sheet, and hard-barrier identity.

This design avoids restoring the P5-CB50 behavior of keeping two complete complexes alive simultaneously.

### P5-CB60 — result and typed failure contracts

- An initially successful pure-quad assembly now finalizes immediately instead of entering the structural-exhaustion epilogue.
- Failed completion preserves compact authoritative descriptors and typed diagnostics while releasing heavy prepared-complex and output-mesh payloads.
- `SameCornerDistinctBoundaryOverlap:` remains the terminal typed failure rather than being overwritten by a generic exhaustion wrapper.
- Added a regression source that forces failure after tentative subdivision mutation and requires exact rollback equivalence.
- Strengthened the already-successful completion regression to require descriptors, completed patches, assembled quads, and an empty failure.

### P5-CB61 — exact reusable-product semantics

- Exact patch dependency comparison no longer treats allocation-local compact registry IDs as semantic dependencies.
- Boundary, rail, source-support, component/sheet, backend, variant, logical-side, and canonical ownership data remain authoritative.
- The change is intended to permit reuse of genuinely unaffected completion products after unrelated local renumbering while retaining collision-safe exact comparisons.

Actual reuse counts remain a P5-TB13 runtime gate.

### P5-CB62 — production-matrix lifetime isolation

- Added explicit per-case markers and scoped traces to the P26 and P27 production matrices.
- Added independently parameterized P27 surface-cell manifest cases that destroy mesh, field, options, and temporary pipeline state before reading the returned public result and diagnostics.
- This makes the prior two deterministic signal-11 failures independently attributable without reducing matrix coverage.

Elimination of the segmentation faults is not claimed until the packaged tests run.

### P5-CB63 — Milestone D and simplification contracts

- Corrected the Milestone D internal-interface fixture to select its actual shared interface independently of field-family labeling.
- Protected-rail setup now modifies the selected authoritative interface directly and symmetrically.
- The explicit simplification-candidate API now executes exactly the caller-supplied transaction; it no longer appends unrelated recomputed candidates. Production topology-healing mode retains its live fixed-point candidate refresh.

### P5-CB64–P5-CB65 — memory and integration coverage

- Rollback uses a compact undo log and one mutable transaction rather than a second full rollback complex.
- Heavy failure payloads remain released; compact descriptors and rollback proofs remain observable.
- Added compile-only regression sources for rollback integrity, successful-result invariants, exact candidate scope, matrix isolation, and returned-result ownership.

The P5-TB12 peak of `158,949,376 B` was measured on an early failure path. Successful-path RSS preservation is not claimed by this compile-only turn.

## Compile and artifact evidence

The clean optimized static build compiled and linked only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

The artifact contains both expected x86-64 ELF executables, both static libraries, the executable-relative fixture closure, exact source archive, empty source-status record, recursive submodule revisions, configure/build logs, and checksum manifest. The packaged `bunny_1k_random.obj` contains exactly 1,000 faces.

The temporary source-transfer workflow and all source-transfer payloads were removed before the exact compiled checkpoint. The source archive contains only the final compile-only workflow for this turn.

## Disposition

Compilation establishes source validity and package completeness only. It does not establish rollback behavior, descriptor restoration, product reuse, crash elimination, zero-conflict output, output quality, wall-time compliance, or successful-path memory usage.

The next authoritative turn is **P5-TB13 artifact-only test and benchmark** using artifact `8860409984` directly without rebuilding.

PR #8 remains open, draft, and unmerged. P5 remains open.

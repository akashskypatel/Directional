# M6-CP3-CB1-ENTRY-R4 — Phase14 typed-rail negative first-rejection incremental Code + Build (2026-10-12)

**Boundary:** canonical `M6-CP3-CB1-ENTRY-R4`, Code + Build only, still IN_PROGRESS, successor UNKNOWN. No runtime, Test + Benchmark, frozen TB497 execution, or acceptance promotion.

## Source and patch authority

- Verified exact inspection snapshot `5f8458b48bc63aa32bee3eaf4e95d073609748bf`, workflow `38196813028`, artifact `11723034402`, ZIP SHA-256 `e1fb7b4b0220b56404f34e3414d5dc2b6db17397da9a3f364c3ece767e2bff8f`, manifest **6316/6316**; branch was unchanged in source since snapshot.
- Semantic commit **`4d51805d79994f1d718d71332be06f504d6312cf`**, Drive apply workflow **`38198898409`**, result artifact `11724511878` ZIP SHA-256 `daf8f10d34efe618623a42a31dbb51aee923bc0efc55c8f8ab590958d44bcc93`, success; patch full SHA-256 `cc819992da00acd005904c69a8203f457aff116d749ab00161ce4156c404fb42`, body `249ffd4827f89bcc9def819840d48a87753336d92098eb792e83699046ea7643`; exact-base apply, reverse and whitespace checks passed. One source path `tests/SurfaceCellTracingPhase14Tests.cpp`, +9/-0. Staged Google Drive File ID `1mc0iFVUjZyfMMNMpD9n4T9Nu2CCYRvge` **owner permanently deleted** after verified push.
- No production source, workflow YAML, PR metadata, frozen test identity, or existing assertion was changed.

## Fixture-level first-rejection preservation

In `SurfaceCellTracingPhase14.MalformedAuthoritativeRailsFailBeforeTracingAndSideDiscontinuityIsTyped`:
- Publish valid fixture's genuine chain `(0, 3)` from `make_grid(1)` face 0 `(0,1,3)`, local edge 1.
- The repeated-edge negative publishes `(0, 3, 0)` and still reaches `DuplicateInterval`; after substituting the actual second edge `(3,1)` (local edge 0), update the final chain vertex to `1` so the `Valid` baseline and `SideDiscontinuity` diagnostic are not hidden by a prior typed mismatch.

In `SurfaceCellTracingPhase14.RailValidationRejectsDisconnectedGeometryParametersAndSharedEdges`:
- Publish genuine first interval `(0, 4)` from `make_grid(2)` face 0, and assert that one-interval baseline is `RailBuildStatus::Valid`.
- Publish `(0, 4, 7)` in the copied parameter-gap case, retaining the source-authentic second edge and its `NonContiguousIntervals` check.
- Explicitly clear the chain only for the disconnected interval fixture, whose second starting source vertex does not equal the first interval's ending vertex. An impossible contiguous typed chain would otherwise cause a prior `TypedAuthorityMismatch` and mask the existing `DisconnectedIntervals` negative. This is **intentional remaining legacy-negative coverage**, not evidence that all RA-43.4 legacy acceptance paths are retired.
- `InvalidSampleGeometry`, `InvalidRailParameters`, and duplicate-edge checks retain their original test identities and assertions.

## Mandatory compile/package evidence

- Exact compile request event `249fe84f77a6f81b8db3a8a76bf9bf7c5225d512`, mailbox `.workflow-mailbox/m6-cp3-r4-phase14-first-rejection-compile/latest.json`.
- **GREEN**, run `38198996718`, job `114648012662`, immutable source `4d51805d79994f1d718d71332be06f504d6312cf`. Result artifact `11723819181`, ZIP SHA-256 `23ee086aaeef3fec3ff9b04dc200e8de2fb54c9350f33f7925458dda9ab63d73` independently verified; package `SHA256SUMS` **28/28**, CMake preflight/build exits `0/0`, eight required targets, `DIRECTIONAL_ENABLE_GMP=ON`, actual generated link command includes both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`, `exactArithmeticBackend=GMP`, source status receipts empty before/after.
- `runtimeExecution=false` and `turnBoundary=Code+Build-only` from package. **No Directional binary/test/benchmark was run**; no runtime success is asserted.
- The prior compilation `38196555564` applies to predecessor semantic source `9709bd8e` and is not reused for this source.

## Remaining R4 authority

The independent overfull hard-rail/A3 reachability review remains open, and RA-43.4 global legacy fallback retirement is not claimed. The 39 endpoint, 34 Phase10, seven DCEL, 88 accepted-CP2 losses, six CP3 positives, real multi-carrier odd-τ and the separately authorized immutable TB497 gate remain OPEN. Prior accepted CP2 **491/491** and rejected R3 **403/497**, 94 RED / 88 CP2 accepted-prefix losses, stable 66/17/49 debt1 are unchanged by compile-only work. No Directional binaries, tests, benchmarks or selectors were executed or modified in this increment.

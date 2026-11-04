# CB84 Linux Vase diagnostic timing — work preservation (2026-11-04)

Canonical turn: `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING`; **IN PROGRESS, not compiled**.

## Frozen inspection authority

- Source SHA: `38b73b90562d008893776592dbb102d3452a08d1` (source-snapshot run `41771191076`, artifact `13295001604`, archive SHA-256 `856397e22c2f0ef34045e8610ff7ec99c4b39f6d76f68881e0ed8e5d031fe5dc`). All archived source checksums passed.
- Source file intended for modification: `src/pipeline/RemeshPipeline.cpp` only; original blob `aa5798bdde68e0c6e24b008a7f67eebb8653c113`, intended new blob `47ca858c4b3a8a823cd05a8f172add73313b0d9e`.
- Exact local patch basename: `Directional__M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING__base-38b73b90562d__work-preservation.patch`. The patch was emitted as a downloadable chat artifact in the CB84 conversation; **it is not committed or present on Drive**.
- Full patch SHA-256: `786ff2803fba01de6fd2688d20e37efd854499675cb4880b57cc5c1cc3d5513d`; diff-body SHA-256: `0b5ea1ad4805793157e35c07b2052486f0fe48639b70c666c9c676a3eab938fc`.

## Implemented locally, pending application

A single local `StageBoundaryTrace` inside `remesh_from_raw_cross_field_impl_with_stage_products` reports `SURFACE_CELL_STAGE event=enter|exit stage=... elapsed_ms=... duration_ms=...` to stderr using `RemeshPipelineClock` (steady clock), with an immediate flush. It records constant stage names at cross-field, feature, metric, relief, tracing, strands, embedding, arrangement, simplification, completion, optimizer preparation, pre-optimization validation, optimizer and final validation boundaries. An active stage gets an exit receipt on normal/early return; an OS timeout retains the last flushed entry. No semantic data, tests, selectors, fixtures, workflows, or validator decisions were modified. Exactly 52 inserted lines in one existing C++ file.

Local static checks: `git diff --check`, `git apply --check` against the exact extracted baseline and reverse applicability against the edited version all passed. **No compile, tests, or runtime execution occurred**. No semantic acceptance is claimed.

## Transport issue and next same-turn actions

The required `files__manage_library` container-path upload failed with `container_session_unavailable` for both `/Directional` preservation and `/Google Drive/Directional-CI` staging. It was retried after activating Python execution, with the same result. An exported `file_...` reference for the local patch was not exposed, so the Google Drive `upload_file(file_uri=...)` fallback could not be called without misrepresenting a local path as a connector reference. This is a recoverable **transport failure**, not a verified GitHub outage or a design blocker. Do not mark CB84 BLOCKED for this alone.

On resumption: obtain the exact patch bytes from this conversation, stage by an authentic file reference to `My Drive/Directional-CI`, verify metadata and full SHA, submit one `drive_apply` dispatcher request pinned to the source SHA above, verify resulting source blob, then execute a separate **compile-only** dispatcher request for the eight GMP/GMPXX targets. Execute no binaries. Only after independently verifying artifact/source/compile evidence, update the normal CB84 durable report, handoff, task ledger and final STATUS; preserve CP2 491/491, 66/17/49, debt 1 and the unpromoted CP3 boundary. Do not start the later TB during this turn.

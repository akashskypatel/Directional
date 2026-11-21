# CB-174 — later entry into a committed slide: exact Code + Build plan

**Proposed successor:** `M6-CP3-CB-174-P13-LATER-ENTRY-SLIDE-STOP-HELPER`.
**Type:** Code + Build; compile and package only. Do not execute Directional runtime. This plan is conditional on TB-REV-157 explicitly separating the impossible pre-wiring graph-reaching clause from its helper requirement. Do not start CB-174 while the current review is open.
**Source authority:** `47a874ee8baa86284eeee11b4a28f9cca06d73f9` (CB-173 compiled package). The repository `src/`, `include/`, `tests/`, `benchmarks/`, build paths, and selectors must remain unchanged since that commit before applying the patch.

## Frozen prospective source patch

An unapplied three-file unified diff is retained in the [Directional-CI patch store](https://drive.google.com/file/d/1ZssZep4xVhe6l3AXEHyaEIaiU57Q2nwJ/view): SHA-256 `684d53d681f1e1ba82730e52239042a6947d6f5a6f035b70d0f252c41807d238`, 13,342 bytes. `git apply --check` and `git diff --check` passed on the exact CB-173 snapshot. The patch is frozen as bytes; do not generate an equivalent-looking replacement.

| File | SHA-256 before | SHA-256 after |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `bab90bdcd0f566a89b06fa464a9cd5fdc5e005fbfb153926dda26c0d37778fbc` | `5808e54155344aad1224ed2b6af3c86a95a210c52bb5b3a366f7b2fa352dab71` |
| `src/geometry/SurfaceCellTracing.cpp` | `69b448ea4c4869ff4e327c36fb0ae045fd7a24852a9b550392509d4d12ec6c66` | `15a5d0f00926e8a26b198d967d670ad83bca395a857739a7f43b3ddaec2f63c0` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `20a11166bb1a29a3689baf2e1c6aa8bb0a230d9b94e627b9200a56e276a8824c` | `944015751090fea39c893750881ac82a62d175d60e3aeb868b65b62248cba4a3` |

The proposed helper is `surface_cell_tracing_detail::later_entry_stop_on_committed_slide`. It only returns the exact pending-entry terminal contact and struck wall segment if the wall already has a committed slide and its arrival comes first under the existing priority policy. It retains source-component and topology-region identity and strict interior tests. It does not change published trace events or graph arc ownership. The test `FieldAlignedCarrierOccupancy.LaterEntryOnCommittedSlideReturnsExactUnwiredStopAndCutPosition` checks the exact carrier parameter 1/2, wall split fraction 4/9, opposite oriented edge pieces, and negative contact cases. The negative component/region tests use metadata changes, not a full two-sheet fixture; do not claim otherwise. The revised exact test also rejects equal arrival, same-trace identity, absent committed moving segment, endpoint-only slide contact, inconsistent previous carrier and out-of-range wall segment index. Each is a separate negative control; these tests are proposed, not executed. Local Clang `-fsyntax-only` returned exit 0 with six existing warning cases, and `git apply --check` plus `git diff --check` returned exit 0 after restoring an accidentally overwritten local snapshot file to its artifact-verified SHA-256.

## Required Code + Build checks and STOP rules

1. STOP if branch source drifts on any protected code, test or selector path, or if any file preimage differs from the table.
2. STOP if the exact patch SHA differs, `git apply --check` fails, `git diff --check` fails, or any postimage differs from the table. Do not silently rebase or regenerate the patch.
3. Compile with required GMP and GMPXX targets via the authorized GitHub compile workflow. STOP on failure; preserve full compiler logs and the immutable artifact with input and source hashes.
4. The test is *compile-only* at this step. A build PASS is not a test PASS. No tests, fixtures, benchmarks, selectors, cut candidates, event publication or production consumers change beyond the three exact patch paths.
5. The helper must reject early or equal moving arrival, same trace, absent or endpoint wall slide, mismatched component/region, missing continued segment, and inconsistent entry carrier. A later full gate must execute meaningful positive and negative tests; do not remove guards to obtain a green result.
6. STOP if the patch changes current production rotation behavior or claims that a full `(0,2)` builder node was published. This Code + Build is explicitly *unwired*. Do not promote CP3, selector497, D0 or H4.

## Separate mandatory integrated reach contract — V3b, not discharged

The subsequent stop-switch **wiring** Code + Build and its artifact-only full gate must publish a source-edge contact node and wall-division arcs from the canonical producer. It must then call `build_rotation_system` on the actual graph and assert a `(0,2)` composition with distinct directions (primaries 0 and 2), valid face rays, and full source support. A same-direction mutation must produce `RotationTraceRaysAlongSharedEdge`; a removed contact must fail the reach test. Neither calling pure classification helpers nor changing a candidate passed to `make_from_candidate` is an acceptable substitute, because that factory reconstructs the canonical product. This obligation stays open until the wiring gate proves it.

**No changes are authorized to the frozen test rules, M6 CP2 acceptance or the current production STOP conditions.** Next Code + Build work must begin only after TB-REV-157 completes and names this exact successor in `STATUS`.
# TB101A field-corner stop-node focused execution — 2026-11-11 UTC

## Situation

**MATCH, focused test only.** The exact immutable CB120A package passed the single authorized stop-node test. No full-gate, production or CP3 acceptance is asserted.

## Background

- Canonical turn: `M6-CP3-TB101A-P13-A3-FIELD-CORNER-STOP-NODES-EXEC`.
- Compiled source: `47afc84ec1104a7457324a967b9362deff549624`; [CB120A compile run](https://github.com/akashskypatel/Directional/actions/runs/42993845258), immutable artifact `13843326855`, package ZIP SHA-256 `a515a41813a4409a69df1a93501c1a40654718547de5814d2901c410979d6eba`.
- Executor trigger `bb365d72894fcd279256c1e13a3d166b9101d512`; [artifact-only workflow run](https://github.com/akashskypatel/Directional/actions/runs/42998151385), single-case OBSERVE manifest `.agents/Directional/gates/Architecture_M6_TB101A_Field_Corner_Stop_Nodes_Focused_Manifest.tsv`, selected existing test `GlobalConformityBaseline.StopNodesReadBoundaryFieldCorners`.
- Result artifact `13845480844`, ZIP SHA-256 `f1b476ae453ecc98921affe374d548117dc1ff3abf2a88782a10da3add9b9c5d`; all five internal package SHA256SUMS records verified.

## Assessment

- Planned/executed/passed: **1/1/1**. RED, abnormal, missing, skipped, duplicate, control error and unexpected pass: **all zero**. Exit 0; postflight true.
- Workflow jobs: dispatcher validation, test workflow validation, request parse, runtime and mailbox all success; compile, Drive apply, and noop skipped.
- `compile=false`, `configure=false`, `relink=false`, `benchmark=false`. No build or binary execution was performed in the local analysis container.
- The focused test exercises declared field-corner stop nodes (including a pass-through rim corner), unrelated source vertices, duplicate and permuted input. Static source inspection confirms existing hard-feature endpoints are retained in the shared stop-node helper. This is a **narrow** test; it does not independently prove all possible topology, source-chart or production outcomes.
- Earlier corrected TB100B **938/938** and CP2 **491/491** acceptance remain historical, not rerun or promoted here. Stable regression accounting **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81** remain unchanged. No new stable regression is supported by this result.
- No compiled code, test source, selector, existing full-gate manifest, factory forwarding, census or production switch was changed in TB101A. A new one-case execution-control manifest was created; the retained dispatcher slot was updated. PR #8 remains draft and unmerged.

## Recommendation

Only after durable closeout, the authorized successor is `M6-CP3-CB120B-P13-A3-FIELD-CORNER-FACTORY-FORWARDING`: one factory-forwarding concern, compile only. Its separate test is TB101B. Do not start that successor during TB101A. O39 exact branch authority must be established before O36; CP3/selector497 stays unpromoted.

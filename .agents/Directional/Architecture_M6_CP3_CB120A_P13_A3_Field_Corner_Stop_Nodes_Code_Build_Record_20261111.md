# CB120A field-corner stop nodes — Code + Build record (2026-11-11)

## Situation

The stop-node helper change compiled successfully. The separately authorized TB101A has not started.

## Background

- Canonical turn: `M6-CP3-CB120A-P13-A3-FIELD-CORNER-STOP-NODES`. Source baseline `46d6e001d4824a91c43598a6f3e845897148ac70`.
- Applied source commit [`47afc84ec1104a7457324a967b9362deff549624`](https://github.com/akashskypatel/Directional/commit/47afc84ec1104a7457324a967b9362deff549624). Only `src/geometry/GlobalConformityBaselineSupport.cpp`, `src/geometry/GlobalConformityBaselineSupport.h`, and `tests/GlobalConformityBaselineTests.cpp` changed (+43/−8).
- Patch SHA-256 `917b08f2966efad34c5c2e989caa0328470691463f3989cac37ae744e10bd4a1`. Applied through [Drive workflow](https://github.com/akashskypatel/Directional/actions/runs/42993541959), verified in result artifact `13843046826`.

## Assessment

- The helper takes a source-vertex corner list, adds matching network-node IDs to the existing stop set, and uses a set to make duplicate/order inputs deterministic. Existing singularity ports, feature corners/junctions, and hard-feature endpoints are unchanged.
- Focused regression checks declare a pass-through boundary corner, shuffle and duplicate inputs, and confirm an unrelated source vertex cannot add a stop. Existing hard-feature endpoint regressions remain.
- [GMP/GMPXX compile run](https://github.com/akashskypatel/Directional/actions/runs/42993845258); [package](https://github.com/akashskypatel/Directional/actions/runs/42993845258/artifacts/13843326855), ZIP SHA-256 `a515a41813a4409a69df1a93501c1a40654718547de5814d2901c410979d6eba`. Eight required targets compiled with the mandatory exact arithmetic backend. `runtimeExecution=false`; no test or benchmark was executed in this turn.
- Factory forwarding, producer wiring, census, full-gate manifests, selectors and production switches remain unchanged. No TB101A runtime verdict is claimed. CP2 491/491 accepted; stable 66/17/49, debt1, deferred81 unchanged; CP3/selector497 unpromoted. O39 exact branch authority remains mandatory before O36.

## Recommendation

Next: `M6-CP3-TB101A-P13-A3-FIELD-CORNER-STOP-NODES-EXEC`. Execute only the immutable package's focused helper test without a rebuild. If it fails semantically, route to independent Review, not to CB120B.

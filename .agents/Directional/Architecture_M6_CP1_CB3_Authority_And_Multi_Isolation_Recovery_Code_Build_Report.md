# M6-CP1-CB3 Code + Build Report

**Turn:** `M6-CP1-CB3`
**Type:** Code + Build, runtime-free
**Semantic source:** `660015f2f15359fd426e2c855aea9f4201c70216`
**Predecessor:** `M6-CP1-TB2-REV`
**Successor if compile/package green:** `M6-CP1-TB3-EXEC`, then mandatory `M6-CP1-TB3-REV`

## Result

`M6-CP1-CB3` is **COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / CANDIDATE ONLY**.

The final semantic correction is bounded to `src/pipeline/RemeshPipeline.cpp`; the earlier A5-specific error enum remains `HardRailOwnerMismatch` in `RemeshPipeline.h` and maps externally to the accepted `InvalidHardRailTransport` contract.

### HardRail precedence

- A5 remains fail-closed for explicit reciprocal HardRail owner mismatch.
- The A5-specific typed error maps to `InvalidHardRailTransport`.
- The later materializer no longer duplicates the rail-ID mismatch predicate; route/region transport checks remain downstream-owned.

### Split-isolation occurrence authority

- Each canonical occurrence keeps its frozen `CellId + canonicalCornerRole` identity and frozen lattice state.
- The occurrence's projection face/sheet is taken from the start of its authoritative outgoing directed side, because a region-global geometric corner representative may select a different incident source face at an isolation seam.
- Canonical-corner and side-attached points must resolve to the same exact `SourceSupport`; otherwise A5 fails closed.
- Quotient union remains relation-owned only. No position/lattice/support/chart coincidence welding is introduced.
- Final lineage sheet sets remain derived from actual quotient members. The transitional materializer no longer augments equivalence seam evidence merely because a relation happens to span sheets.

The first implementation attempt in this turn re-derived occurrence branch/source-chart state from the outgoing side and added certificate-based seam augmentation in the materializer. Static reconciliation against the frozen A5/A6 authority showed those changes were broader than required. The final source preserves the frozen lattice state and removes that certificate augmentation before compilation.

## Frozen validation surface

- selector449 remains exactly 449 LF rows, SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`;
- routing449 remains SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
- tests, fixtures, selector and routing bytes are unchanged;
- known by-value accessor split-range scan: `0` hits;
- no Directional runtime was executed in this turn.

## Compile/package evidence

- workflow run/job: `36077715921 / 107892575831`
- exact compiled source: `660015f2f15359fd426e2c855aea9f4201c70216`
- result artifact: `10840014758` (`sha256:b1117c6efe2cdc8a04e46647fd1bb5af79094234a03348df8ffd6e6ae5ed5c66`)
- log artifact: `10840034587` (`sha256:eb2504f3824c6626ab37f2cc5e5e39c869187b93615e7f94346e7a7124ace077`)
- root manifest: `28/28 verified; self-excluding manifest check PASS`
- exact arithmetic backend: GMP; generated link command verifies `gmpxx` + `gmp`
- compiled targets: all eight standard CP1 targets
- source receipts: clean
- packaged source archive SHA-256: `90c6305132ceca1bcd5f12dfd03a7a3b818fe3e9462128dedb5c3f5788f67ecc`
- configure step: PASS; build/preflight exit codes: `0 / 0`
- `runtimeExecution=false`

CB3 grants no runtime credit, candidate promotion, CP1 closure, or debt discharge. Stable accounting remains **53 / 16 / 37**, produced-witness debt remains **1**, M6-owned. TB3 owns the fresh 455-process recovery gate.

## Process corrections

Two orchestration attempts were rejected before the final compile authority was created:

1. a stale-base Drive apply correctly refused to proceed after detecting that the intended semantic paths had already changed;
2. the first reconciliation patch metadata listed the unchanged header as an intended path, and the reusable apply workflow correctly rejected the expected/actual path-set mismatch.

The corrected reconciliation patch listed only `src/pipeline/RemeshPipeline.cpp`, passed `git apply --check`/`git diff --check`, was applied as semantic commit `660015f2f15359fd426e2c855aea9f4201c70216`, and its transient Drive payload was retired. Neither rejected attempt produced compile or runtime evidence.

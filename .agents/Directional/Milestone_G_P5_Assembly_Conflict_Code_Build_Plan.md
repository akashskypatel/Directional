# Milestone G P5 — Same-Corner Assembly Conflict Code + Build Plan

**Turn type:** Code changes + compile-only build  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base branch:** `surface_cell_quad`  
**Input artifact:** `8841726806`  
**Review policy:** `never`

## Completion status

This plan was implemented by source commits:

- `4b7e02b0e8248a8093959147e27cc1ee9440d35a` — production, diagnostics, and regression-source implementation;
- `1f4c3c2a014f0bc945b50f1bb5a837c438cec992` — minimal backend enum compile correction.

Compile-only run `30776779114` succeeded and produced artifact `8842377256`, digest `sha256:669bf5d6f3e9b3738298b5985b6bb715668bce0715b0a68d880eb4aa0e80d6bc`.

All work packages P5-CB21 through P5-CB26 are source-complete and compile-valid. Runtime acceptance is deferred to P5-TB8 using artifact `8842377256` without rebuilding.

## 1. Authoritative evidence

Artifact `8841726806` removed the earlier source-support gate and reached assembly deterministically. Both random-bunny runs completed all 21,297 descriptors and failed with the same terminal conflict:

```text
DuplicateStitchedQuad:firstPatch=8595;firstLocalQuad=0;
secondPatch=8573;secondLocalQuad=2;
classification=completion-template
```

The owners had different domain and boundary identities, equal source support, equal canonical stitch corners, equal canonical authoritative corners, the same component/sheet, and closed-form backend variant zero.

## 2. Non-negotiable constraints

- Do not delete or deduplicate final faces.
- Do not merge vertices by position.
- Do not special-case patch IDs.
- Do not use source-triangle pairing, source-grid recovery, legacy fallback, or validator weakening.
- Preserve transactional assembly and exact ownership identities.
- Correct invalid tests for their stated scenarios.
- Compile only; execute no test, benchmark, or custom mesh binary.

## 3. Implemented work packages

### P5-CB21 — Correct invalid regression fixtures

- Generated-interior escape now uses a valid source face outside patch support.
- Added positive controls for generated interiors on both allowed patch faces.
- Parity fixture now supplies authoritative embedding, orientation, area, Euler, component, and boundary-loop evidence before recomputation.

### P5-CB22 — Exact same-corner claim evidence

- Added `SameCornerDistinctBoundaryClaim`.
- Claims record canonical stitch/authoritative corners, source patch/local quad, backend/variant, complete domain and boundary identity, source scope, boundary counts, and side counts.
- Added deterministic typed attempt records for variant and structural actions.

### P5-CB23 — Upstream transactional repair

- Distinguishes same-corner claims by exact complete identities.
- Selects candidate intervals from canonical boundary symmetric difference.
- Applies bounded twin-aware boundary-sector subdivision through existing complex machinery.
- Reruns parity, coupled side repair, descriptor derivation, and completion transactionally.
- Commits only when the original exact claim is removed and all validators pass.
- Fails closed when overlap or conforming repair cannot be proven.
- Closed-form patches do not consume nonexistent rotation variants.

### P5-CB24 — Regression sources

Compiled sources cover corrected fixtures, exact classification/routing, closed-form handling, and final duplicate validation.

### P5-CB25 — Bounded performance

- Reuses compact identities.
- Uses deterministic hard limits for attempts and inserted intervals.
- Releases superseded transactional state on failure/commit boundaries.

### P5-CB26 — Compile-only gate

- GCC 13.3.0 optimized static Release.
- 131/131 build steps completed.
- `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks` linked.
- Exact source `1f4c3c2a014f0bc945b50f1bb5a837c438cec992` packaged with empty source status and ten passing checksums.
- No test or benchmark executable ran.

## 4. P5-TB8 handoff

Use artifact `8842377256` directly without rebuilding. Run corrected fixtures, focused same-corner regressions, the required broader suites, and at least two direct random-bunny processes. Record exact repair attempts, inserted intervals, assembly disposition, determinism, runtime, and peak memory.

P5 remains open and PR #8 remains draft/unmerged until runtime validation closes the production gates.

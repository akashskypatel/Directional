# TB46A orchestration correction — bounded continuation (2026-10-27)

**Canonical turn:** `M6-CP3-TB46A-ORCH` (Code + Build; not a TB or Review). **Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`. **Next gate remains conditional.**

## Authority and immutable evidence
- TB46 original run `40448739180`, semantic source `c05d52dd7c710d1ca32922f6cfe1f6b61a29db99`, package `12708707491`, frozen 504-case manifest SHA-256 `717f4f0fb9b520ec9c0281bfa71f11b2edae98b16a1f18ffc17366fb076bb087`, 504/504 raw processes, 497 PASS / 7 RED, five pinned REDs, two failing POSITIVE controls. This remains **invalid S5 gate evidence**, not accepted semantic runtime.
- Exact snapshot base `e5b0a69664f1d0f382ce902a89c3e5aef62dd61b`; source snapshot run `40454900498`, artifact `12712217084`; archive and 5,938 source checksums checked locally.
- Harness-only patch `Directional__M6-CP3-TB46A-ORCH__base-e5b0a69664f1__work-preservation.patch`, SHA-256 `2c446818cd4dd2338bb9f5e31c845830850bc325ddc4d84c1c28065965e0ee2f`, diff-body `013f5b79b3dd2221def1d021dea07a883ce58f112e93845096e887b43256e0da`. The clean-base `git apply --check`, `git diff --check` and Python inline syntax validation succeeded; no binary tests or benchmarks executed.
- Drive patch apply run `40455841215`, result artifact `12712327000`, succeeded and pushed **source commit `5e6de03fadd88cc4f9bbe749b32ea012264fe73e`**. Staged Drive object `1tQNEtiV7y2Zm2nHeCopaylWTZe6BBAS9` was owner-deleted after commit; chat/File-Library patch is preserved.
- Compile-only dispatcher request commit `5da4157f099cce6abe0421cdb18f963702317113`, request ID `m6-cp3-tb46a-compile-20261027-r1`, mailbox `m6-cp3-tb46a-compile`; source `5e6de03fadd88cc4f9bbe749b32ea012264fe73e`. Eight standard targets and mandatory GMP/GMPXX. **Compile result not yet verified at this writing.** No TB is authorized in this CB.

## Corrected control-plane interpretation
- The harness now verifies the exact first failure for each of the five pinned RED cases, with source line and discriminating witness; all raw RED results remain RED.
- For POSITIVE controls, only independently located later first failures are tolerated as **RED with evidence**. `cp3entry:4` is source-located at `SurfaceCellTransitionQuotientTests.cpp:4063`; `selector:174` remains ineligible, because original GTest reports `unknown file` and an uncaught DCEL exception.
- GUARD regressions and unknown/earlier POSITIVE failure remain hard control failures. No assertions, fixtures, product code, manifest, or reusable workflow were changed.

## New static diagnosis requiring independent disposition
`selector:174` constructs `incidenceVertices(5,3)` but its *manifold* two-face source uses only vertices 0–3 (`SurfaceCellREPackageTests.cpp:433–439`); vertex 4 is isolated. `DCEL::Vertex` defaults `valid=true`, `halfedge=-1` (`DCEL.h:50–57`); `DCEL::init` does not assign an outgoing halfedge to isolated vertex 4 (`:2993+`), whereas `check_consistency` rejects valid vertices with invalid halfedges (`:1255–1265`). Therefore the unguarded `manifoldHardSource.set_mesh(...)` at `REPackageTests.cpp:439` appears to throw **before** the intended `EXPECT_THROW` at `:449`. This is a strong source-level diagnosis, *not* an independently runtime-attributed result. Do not whitelist this exception as a later failure or synthetically mark it PASS. Correcting the fixture requires separate review/authorization outside this orchestration-only CB scope.

## Resume / stop instructions
1. Resolve the compile mailbox `workflow-mailbox:.workflow-mailbox/m6-cp3-tb46a-compile/latest.json`, verify run/job/artifact, exact source, eight targets, GMP+GMPXX, `runtimeExecution=false`. Do not claim compile success until verified.
2. Independently review the `selector:174` fixture-precondition finding and authorize a separate narrow fixture Code + Build correction, or record another evidence-grounded decision. **Do not dispatch TB46 while the unlocalized earlier exception remains a known hard control failure.**
3. Update the current handoff/TODO/tracker/changelog under repository retention and review policies. Preserve the frozen package/manifest and stable 66/17/49, debt 1, CP2 491/491; no semantic promotion.
4. Clean the temporary source snapshot trigger `.agents/connector-triggers/source-snapshot/m6-cp3-tb46a-orch-20261027.txt` (unless already removed) using the repository cleanup rules.

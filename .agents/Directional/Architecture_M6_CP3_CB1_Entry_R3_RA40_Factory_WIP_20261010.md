# M6-CP3-CB1-ENTRY-R3 — RA-40 source-bound factory WIP (2026-10-10)

**Turn:** `M6-CP3-CB1-ENTRY-R3`, IN_PROGRESS. This is a bounded Code + Build checkpoint; no new successor or test turn has begun.

## Authority and exact source

- Independent A/B/C Review completed as `M6-CP3-R3-ABC-ARCH-REV`; apply RA-40 frozen requirements in `Architecture_M6_CP3_R3_ABC_Review_Decision.md`.
- Exact snapshot `b61acce407d2e0887c8712ba9838df3cac62b53a`, workflow run `38022333747`, artifact `11658753507`, provider SHA256 `75ceead7d3e6a8736699225fd597eeadb907ca3bc86dca6bd1ee1591c5669eb5`; 5801/5801 internal file checksums verified.
- No Directional executables, tests, benchmarks, or local compiler were run. Preexisting green GMP compile of semantic source `089779c15eae27a2bb3b798ef9c8085950e92def` predates this WIP and does NOT validate it.

## Preserved but unapplied code

Exactly two production files edited locally: `include/directional/geometry/SurfaceCellTracing.h` and `src/geometry/SurfaceCellTracing.cpp` (42 insertions, 3 deletions).

The intended RA-40 A2 implementation requires source faces, vertex count, and a source-bound `FieldTransportAtlas` at `SurfacePhaseFrontProduct::make`; it fail-closes on missing/mismatched atlas, compares nonrail sector φ and HardRail carrier/terminal χ against independent A3 `transition_value`, and checks forward/reverse reciprocity. The producer forwards original source/options to the public factory.

**Not compile-ready:** Eleven direct test callers of this public factory still need migration. Do not push the current source patch alone.

- Exact work-preservation patch base: `b61acce407d2e0887c8712ba9838df3cac62b53a`.
- Full patch SHA256: `ed56b76932b0193b4be2fb33592b7b6b9763e0ba4a4495c066bcbd5fe4e21dcb`.
- Diff-body SHA256: `5df02a00313380b322936e152e27ebb8edc29c86187ec3d0dc142fbc0fb154bb`.
- Checks: `git diff --check`, `git apply --cached --check` against exact local base, and `git apply --reverse --check` all passed.
- ChatGPT Library: `/Directional/Evidence/Directional__M6-CP3-CB1-ENTRY-R3__base-b61acce4__RA40-factory-A3-WIP.patch` (stable Library ID `libfile_ec020f7e322081918fceca3f74f44d43`).
- Google Drive staging: `My Drive/Directional-CI`, file ID `1ITOvLaWcAk3BCoNNIs6DqeMY7O5QDCkr`; this is backup-only staging, NOT a dispatched or applied patch.
- Portable full handoff: ChatGPT Library `/Directional/Evidence/Directional_RA40_R3_Continuation_20261010_v2.md`.

## Continuation checklist

1. Resume the SAME Code + Build turn. Use RA-40 A2 binding; migrate 11 test factory callers in `SurfaceCellTransitionQuotientTests.cpp`, `SurfaceCellsPhase10Tests.cpp`, `FlowRepStrandsPhase15Tests.cpp`, and source-bound atlas for genuine produced network fixtures. Never solve by copying untrusted φ/χ into the oracle.
2. Add source-authentication negative/positive **compiled** assertions and check frozen selectors: `497=30+12+449+6` remain unchanged; four RA-40 supplemental test identities are outside this frozen gate.
3. Once complete and source-checked, generate one **new complete verified** multi-file patch at exact then-current GitHub source authority; apply through Drive dispatcher. Do not replay the staged partial WIP directly. Use GMP/GMPXX eight-target compile reusable only, `runtimeExecution=false`; no test/benchmark execution in this turn.
4. Retire consumed/stale Drive staging after successful push. Finish durable closeout and name the authorized artifact-only TB successor only when Code + Build is truly complete.
5. Temporary source snapshot marker `.agents/connector-triggers/source-snapshot/r3-ra40-20261010T0357Z.txt` awaits approved manifest cleanup, not manual trigger-inducing deletion.

No design/architecture gate remains unresolved; outstanding work is implementation, compile/package and closeout, not a new Review blocker.

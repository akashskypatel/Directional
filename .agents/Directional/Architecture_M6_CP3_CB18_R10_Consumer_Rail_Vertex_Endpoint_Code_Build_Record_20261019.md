# CB18 — consumer R endpoint Code + Build (2026-10-19)

- **Turn:** `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` (RA-103.4), compile-only candidate; no runtime acceptance.
- **Semantic source:** `3bd24682c5e18eece541ab4d1f38f781a2230e41`.
- **Compile workflow:** [run 39337458721](https://github.com/akashskypatel/Directional/actions/runs/39337458721); compile job `118350531857` succeeded; Test + Benchmark skipped.
- **Immutable package:** artifact `12227516380`; ZIP SHA-256 `d09c32d6e7c06e280b3f9888008cde2ebb4738c3e6273f7a661903f2d231cdc4`.
- **Package checksums:** 28/28 SHA256SUMS verified. Source archive and affected tracing/header/test files match the verified current source snapshot bit-for-bit.
- **Build:** all eight required GMP/GMPXX targets built; `build-exit-code=0`, source worktree clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- **Implementation:** A4 emits source-attested interior open-rail `railVertex` as R with unchanged T/I fallback rejection, checked star and orientation parity, sixth certificate member and R-aware route interval. Test #9 excludes R; compiled forged-tag positive/negative control added.
- **Runtime:** not executed. Existing selector 497, census 425/497, stable regression 66/17/49 and debt 1 remain unchanged and unpromoted.
- **Next:** `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` (RA-103.5), immutable artifact-only focused 14-gate run, conditional census, then mandatory Review.

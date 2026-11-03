# P13-j — scoped boundary-key V2 scratch verification (2026-11-03)

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`, **IN_PROGRESS**. This is diagnostic evidence, not accepted production code, gate promotion, or a successor authorization.

## Exact source and patch

- Immutable CB78 baseline source: `afd72107d3213a396ed7f35b53f67dceeea7e7ca`.
- V2 work-preservation patch in ChatGPT Library `/Directional/Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__compatible-occurrences-v2.patch`; full SHA256 `d38339902844fcb8ed902a5ed877f2d0a59464bbc7b83a246380460d945c1ff5`, diff-body SHA256 `74bcf11cf2b91023df67f911440904a208b7603c1024e6ed78e745c72b846a0d`. Applies forward and reverse against exact CB78 source, whitespace check PASS.
- Scratch branch **`agent/p13j-compatible-boundary-scratch-20261103`** created from CB78. Source commit **`36fb5349aebb96a0b5b0d30d5c5265a110c5df8c`** changed only `include/directional/geometry/PatchDescriptor.h` (Git blob `e23724eb27c5e7098d1f4cf2dd5bb915f4d6ed3e`) and `src/geometry/PatchDescriptor.cpp` (Git blob `9c24c984e604f85fa58822f3821c91ec13b0446e`); both exact hashes independently verified against locally patched CB78 source. The production working branch contains **no** semantic source mutation.

## Isolated GMP build evidence

- First exact source compile request commit **`7ae917c69c1fffe405c82b8f84ad99facee7aa4c`**, run **41581341497**, failed at `ninja: error: unknown target 'directional_tests'`. All 107 steps including `directional_benchmarks` compiled, preflight target was green, but the overall build **FAILED**; this is an assistant-selected invalid target, not a source compiler error. No unit tests ran. Error log artifact **13205842583**.
- Corrected compile request commit **`f056bf363d3664194cf9ce8169a8d14665414230`**, valid target `directional_benchmarks` only, run **[41581676195](https://github.com/akashskypatel/Directional/actions/runs/41581676195)**: **SUCCESS**. Immutable package artifact **13205668125**, outer SHA256 **`ba5fda366227e4e2e5f5856853e1344aae4b14e7cb2b1b86660e190daa1cd07e`**; 23/23 internal SHA256SUMS match, source commit matches scratch exact SHA, configure `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, link evidence includes both gmpxx and gmp, preflight/build exit 0, compile workflow `runtimeExecution=false`. Log artifact **13206511928**.

## Exact evaluation boundary

- Candidate has no accepted runtime or test result at time of initial report write; the independently verified CI binary is executing the immutable Vase benchmark `vase__surface_cells` from `milestone_g_manifest.json`, warmup 0, runs 1, with **420 s timeout**. Case-level `runs[0].success` and terminal reason, not executable exit code, will determine the diagnostic verdict. The initial direct CB78 Vase failure was `AssemblyRejected/NonManifoldStitchedVertex` (first global row 3, three disconnected two-face fans).
- The source uses existing `SourceChartTransitionGraph::rebind` and `resolve_entity` and only the boundary-key producer; source domain and halfedge identities, original edge/vertex manifold validation, and accepted selector are unchanged. Critical unproven safety: rebound barycentric tolerance **1e-8** and potential false equivalence if **distinct arrangement nodes** have equal sets of source occurrences. Do not freeze V2 as an exact corrective patch without negative tests.
- Required negative tests: separate chart components behind hard rails; distinct source-vertex fans; coincident source support from independent arrangement nodes; distinct points separated below 1e-8 (within barycentric rebound tolerance); nonmanifold source-edge contacts; face-row and patch-order permutation. A negative test must detect the unsafe merge, not just pass the existing native graph tests. Tests may be added only in an authorized Code + Build turn; no test source changed here. Exact positive: two boundary keys at each of 5356/5357/5359 should become equal and geometry must progress past first Vase stitched vertex; a different failure elsewhere is not a pass.
- Established accounting unchanged: accepted CP2 491/491; stable 66/17/49, debt 1; TB72A 883/883 candidate unpromoted and selector497 unpromoted. No other pipeline stage and no Code + Build successor launched.

## Continuation requirements

Append case-level runtime status and checksummed evidence when the currently running bounded replay finishes. If the replay fails, do not adapt tests or suppress validators. Fix only evidenced root cause, and retain V2 as an unaccepted scratch proposal. The canonical Review remains incomplete until exact negative/positive falsifiers, proof of no improper topology quotient, authenticated ancestry-backed `review_check.py boundary`, mandatory REVIEW_TURN_POLICY documentation closeout/consolidation, and one separately authorized successor are established.

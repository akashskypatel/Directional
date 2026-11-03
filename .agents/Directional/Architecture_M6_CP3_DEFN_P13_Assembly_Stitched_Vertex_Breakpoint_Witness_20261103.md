# P13-j — exact CB78 read-only stitched-vertex breakpoint witness

**Canonical turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` — INCOMPLETE. This is a first failing-vertex runtime observation, not a completed DEFN, fix, production acceptance, or Code + Build successor.

## Immutable evidence

- CB78 semantic source: `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; compiled artifact `13181887585`, outer SHA-256 `076a19de16db5b0d7be3fb7d133c0324383dde319467afb22b3edc99922658e4`.
- Packaged `directional_benchmarks` executable SHA-256 **before and after**: `78c00bbd95b9a25651389d2077463d24bab9e8bd2cc9e6c0743287e95e453d77`.
- Command: `--manifest milestone_g_manifest.json --case vase__surface_cells --warmup 0 --runs 1` from the exact snapshot's benchmarks/fixtures.
- A read-only Python ptrace debugger set a *memory-only* INT3 breakpoint at ELF virtual address `0x4ff2eb`, which disassembly proves is the branch assigning literal `NonManifoldStitchedVertex` (string at `0x7bdaaa`). No local build, modified executable, production source edit, new fixture or accepted gate.
- Reached the breakpoint after **283.1 seconds**, 2026-11-03 02:39:14 UTC.
- **First failing stitched global vertex row = 3** (32-bit `[rbp-0x2e00]`, not source vertex ID); **incident quad count = 6** (`[rbp-0x2ac8]`); **reachable through vertex-incident shared edges = 2** (`[rbp-0x2a88]`). Independent reading of the saved stack bytes confirms all three. `r12d=4` reflects incrementing the vertex iterator immediately before rejection.
- The other **four incident quads are unvisited** by the initial fan BFS. They are not proved to comprise one component. The debugger stops before assigning the failure string; it terminates the child, so this is **not** a completed benchmark result.

## Unresolved root-cause ownership

The evidence proves an edge-disconnected fan at the first rejected global vertex, but **does not** identify its canonical source support, contributing patch/cell owners or full fan partition. It cannot yet distinguish a false assembly stitch merge, mismatched completion-boundary subdivision/edge identity, or an invalid upstream arrangement sector.

The previously emitted **scratch-only** diagnostic patch `Directional__M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX__base-afd72107d321__scratch-diagnostic.patch` (full SHA-256 `461b95dedfd5f8a66ef2e8662eb0a588387eb53f82c6779597501f146e9b7145`) is statically applicable to exact CB78 source; it is **not compiled or executed** and **must not** be applied to the production working branch.

**Same-turn next action:** isolate an approved GMP/GMPXX scratch build of exact CB78 plus diagnostic patch and capture `P13J_BEGIN`–`P13J_END` including exact identity, provenance candidates, patch/cell owners, incident face/edge lists, complete fan components and source-chart sectors. Verify no validator weakening and retain fail-closed rejection. Adjudicate owner from that evidence before authorizing an exact corrective CB successor. Preserve CP2 491/491, stable 66/17/49, debt 1, selector497 unpromoted; no CP3 promotion.

This evidence supplements, but does not supersede, `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Preflight_20261102.md`. The raw JSON and reproducible probe script were preserved as downloadable ChatGPT continuation artifacts; do not treat their absence from the repository as new source authority.

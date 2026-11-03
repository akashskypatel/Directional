# P13-j — exact CB78 Vase three-fan stitched-vertex witness (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`; Review/Definition remains **INCOMPLETE**. This is an observed scratch diagnostic, not a production correction or candidate promotion. It supplements the preflight and the read-only breakpoint record; the root-cause producing stage is **not yet adjudicated**.

## Immutable/diagnostic execution authority

- Baseline **CB78** source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; independently verified baseline failure `AssemblyRejected/NonManifoldStitchedVertex`.
- Necessary **isolated temporary diagnostic branch** `agent/p13j-diagnostic-first-vertex-20261103` at `42126c14ff530c4ccfd3768f93e4b95c2ae3bfc7`, based exactly on CB78. A single source file `src/geometry/PureQuadCompletion.cpp` was changed to print the first rejected vertex, identities, owners, edge incidences and all fan components when `DIRECTIONAL_P13J_SCRATCH_WITNESS` is set. The original `NonManifoldStitchedVertex` rejection remains. This branch is isolated because compiling an instrumented diagnostic must not mutate production work or the accepted immutable package.
- Mandatory reusable GMP compile via durable dispatcher request commit `6f905a0e2cced5cd5e152d34a096d8493ba76400`, run **41569099988** (successful); compiled single target `directional_benchmarks`; package artifact **13199469869**, SHA-256 `268a33a0508dd6c444e5f0df01ff0ad9ab176e9f103105a69506944011d1de3c`; log artifact **13201085244**, SHA-256 `b379d36ab78204084624f3e419bc36cae01911a58dba13ef4ce9ec9761d4b0b0`. Verified all package SHA256SUMS; `DIRECTIONAL_ENABLE_GMP=ON`, generated link line includes **gmpxx** and **gmp**, metadata says `exactArithmeticBackend=GMP`, source SHA matches, build/preflight exit codes zero, compile-only boundary preserved.
- Executed the packaged binary **without rebuilding** against the exact `milestone_g_manifest.json` source fixture `vase__surface_cells`, one run, no warmup, diagnostic environment flag set. Elapsed **294.149 s**, process exit code **0** (benchmark reporting status only), benchmark's `cases[0].runs[0].success=false` and terminal `NotProductionReady` / `NonManifoldStitchedVertex`. One complete `P13J_BEGIN`/`P13J_END` marker pair. Binary SHA-256 before and after identical: `e220eb2e1f572d5ae3a50dc3442c7b34b8dbe39c49b6c9985c0937d7fc855782`. The diagnostic did **not** turn Vase green.

## First rejected stitched vertex and provenance

- Global stitched vertex row **3**, six incident quads, only two edge-connected from the initial seed, precisely **three disjoint two-quad fans**. Global row is an assembly-local ordinal; it is **not** source vertex 3.
- Shared canonical arrangement-node identity: kind **1** (`ArrangementBoundaryNode`), hash **7413753397690851829**, values `1,56731`; each patch-local occurrence has local vertex ID **5355** and boundary=true. Full canonical source-support values include source face corners `(0,255,1248)`. Resolved authoritative identity kind 1/hash **1278380862843572727** and source face `(0,255,1248)`, topology region 0, sheet 0, chart 0. Canonical provenance `face=155; component=0; sheet=0; bary=(0.197288,0.416768,0.385944)`; exact source-support incident face 155.
- Four contributing patch-local occurrences (patchIndex, sourcePatch, localRow, domainHash):
  - `(0,26569,3,13477175895117145574)`, source side edges `1,1,1,1`
  - `(10942,3,3,2797002078942487011)`, source side edges `2,1,2,1,1,1`
  - `(22042,26570,2,7840118678002363504)`, source side edges `2,1,2,1,2`
  - `(24674,0,10,7710101604013126795)`, source side edges `5,3,2,2`
- Fan 0: faces **0** (patch 0/localQuad 0) and **15320** (patch 10942/localQuad 0), connected by stitched edge `(3,0)`.
- Fan 1: faces **44813** and **44815** (patch 22042/localQuads 0,2), connected by stitched edge `(3,10)`.
- Fan 2: faces **55549** and **55551** (patch 24674/localQuads 2,4), connected by stitched edge `(3,76283)`.
- The six outward vertex-incident edges `(3,2)`, `(3,29991)`, `(3,63568)`, `(3,63567)`, `(3,76289)`, `(3,76288)` each have only one incident quad in the assembled result. Thus the one globally merged row has **six unmatched fan ends**, not the boundary vertex's ordinary two.
- Patch-lineage `ownerAuthority` fields printed `kind=0/valid=0`, but the *resolved* global authoritative identity is valid; do not mistake the optional incoming lineage representation for proof that typed authority was absent.

## Negative and positive controls (same scratch binary, unchanged fixtures)

- `cylinder__surface_cells`: process returned 0, benchmark `success=true`, 320 vertices, 288 faces; no P13-j witness.
- `bunny_1k_random__surface_cells`: process returned 0 but benchmark `success=false`, `SingularityPortClassCountMismatch;sourceVertex=49`; no P13-j witness. Benchmark process exit codes alone are **not** acceptance evidence.
- Accepted CP2 491/491, stable 66/17/49 debt 1, and selector497 unpromoted remain unchanged; no CP3 promotion or new stable event.

## Exact remaining discrimination (same Review turn)

**Proved:** multiple completed patch sectors share one arrangement-node key and one valid source support but have three disconnected stitched edge-link components. **Not yet proved:** the earliest stage that introduced invalid fan incidence. Preserve all three explanations until upstream comparisons:
1. Compare arrangement's ordered incident arcs/cell sectors at node `5355` (canonical `1,56731`) with the four source patches `26569,3,26570,0`. Determine whether three disconnected sectors are already present in the incoming authoritative arrangement (**arrangement owner**) or arise later.
2. Compare, per incident patch, exact boundary-node sequence and ordered side-edge subdivisions, matching neighboring patch interfaces and typed sheet/chart sectors. If the arrangement is correct but these interfaces disagree, **completion-boundary sharing owner**.
3. If completed patch boundaries genuinely match a single connected source fan, but the stitching key collapses separate vertex-link sectors, **assembly owner**. Do not infer this from equal position/provenance alone.
4. Require a falsifiable corrective patch with a negative case that would fail without the fix, retain original fail-closed validation, and separately authorize a Code + Build successor. No production semantic change is permitted in this Review.

**Preserved evidence:** complete stderr marker block, parsed JSON result, three benchmark JSON results, scratch patch (full SHA-256 `6e5ec0614084f1524cb6800955a85468ba392e0887e285a8f71b2917b14c38cb`), CI package/logs and exact replay script are downloadable continuation assets. The isolated scratch branch must be retired after its evidence is consumed and any necessary follow-up probes are complete; no workflow YAML or reusable-workflow permissions were changed. The authenticated Git-ancestry `review_check.py boundary` and full Review closeout remain outstanding.

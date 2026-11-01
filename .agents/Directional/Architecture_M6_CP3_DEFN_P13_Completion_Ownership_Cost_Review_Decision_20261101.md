# P13-f completion source-chart ownership-cost Review / Definition — 2026-11-01

**Canonical turn:** `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST`. **Decision:** approved with a narrowed, bounded and falsifiable Code + Build successor; direct Vase acceptance remains unproved.

## Primary evidence and independent attribution

1. TB67, immutable CB70 source `9754500b2058229b7f0a6268838953650690b031`, package `13087332886`: Linux gate 871/871 PASS, membership 952, no unexpected regression. Independent census ZIP `fb80af756d9a740d1393c7f12b66bcf4f8f399544056b467c4207fe89487621e`: 9/9 internal hashes independently re-verified, Cylinder PASS, BunnyRandom P13-e `SingularityPortClassCountMismatch` at vertex 49, Vase abnormal exit 124 at **600-second harness timeout**, without a terminal stage verdict. The Vase TB67 log **does not by itself prove arrangement completion or identify the currently executing operation**. [TB67 execution report](Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md).
2. Separate [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md) **scratch-probe** evidence on both corrected wedge rotations reports 26,827 completed arrangement cells and later completion >600 seconds. Its independent CPU samples attribute 3,179/3,807 to per-vertex lineage closure and 2,755/3,840 after that change to per-patch ownership validation. Those samples diagnose a plausible cost chain; they are **not** immutable TB67 end-to-end acceptance.
3. Independently re-opened the exact snapshot at `8d557342594f6d08a64e1f9c9a519f3baad17cf7` (source archive and all 6,073 file hashes verified). In `src/geometry/PureQuadCompletion.cpp`, `close_completion_lineage_source_authority` (near lines 850–877) calls `matches_source_faces` and **constructs** `SourceChartTransitionGraph` each time. Both `validate_materialized_completion_domain_ownership` (near line 1282) and `validate_completion_domain_ownership` (near line 1582) call it per output vertex. The latter also constructs its own graph near line 1322 and scans all source faces for vertex extent; it is called from `complete_pure_quad_patch` near line 2234 and reuse validation in `src/geometry/PatchDescriptor.cpp` near 2842.
4. `SourceChartTransitionGraph` constructor in `include/directional/geometry/SourceChartTransitions.h` (near 188–214) eagerly invokes `build()`, which checks the full face binding and builds face topology (near line 598). `PatchDescriptor.cpp` around lines 2717–2740 passes source matrices/authority/hard edges to each descriptor via `PureQuadCompletionOptions` but no reusable transition graph. Assembly's graph at `PureQuadCompletion.cpp:3003` is a **different already-reused stage**; it is not the correction target.
5. With source faces count F, patch count P and output-vertex visits V, the currently repeated source-wide work includes at least O((P+V)F) checks/build work in the successfully reached path, aside from the one necessary topology construction. It is finite, not an infinite loop, but can exceed the 600-second bound. The independent original samples support this attribution but cannot establish the actual first active stack during the TB67 timeout; that remains a falsifier in TB.

## Adjudication and invariants

**Root cause candidate P13-f:** immutable source-chart topology and source-authority binding are reconstructed at per-patch and per-vertex granularity, although F, source authority and hard-feature barriers are constant throughout one completion batch. The appropriate correction is **reuse of a once-validated immutable graph**, not removal of ownership validation, position-based stitching, accepting invalid sheets, or caching mutable completion results. No source/test/benchmark/build code is changed in this Review.

**Prohibited:** a matrix- or fixture-specific fast path; skipping `matches_source_faces` without equivalent binding proof; weakening invalid-source, hard-rail, local-sheet or topology rejection; introducing a global mutable cache or implicit pointer-identity acceptance; changing source atlas, arrangement wedge decisions, gate/selector, TB67 evidence or 600-second timeout; broad premature performance redesign.

**Open uncertainty:** caller-graph lifecycle across all public standalone and patch-cache APIs, and whether the Vase path exposes a subsequent semantic failure once repeated work is eliminated. No promised Vase PASS. Retain independent P13-e vertex-49 Review, O16/O17/O19/O6/O9, DR1/DR3 and DR2/DR4.

## Frozen successor

**Exactly one successor:** `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` (Code + Build, compile only), governed by [Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md](Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md). It must establish graph lifetime/source binding, remove per-vertex and per-patch full-source reconstructions without reducing checks, add discriminating source-authority and chart tests, and compile/package only under GMP/GMPXX. It must not execute runtime tests or benchmarks. After compile, an **independently authorized** artifact-only TB successor will check the full 871/952 gate, deferred membership, Cylinder/Bunny unchanged, and a fresh bounded Vase process; no semantic result can be presumed here.

**Hard falsifiers:** any changed accepted case/ownership error, cross-sheet or hard-feature merge, graph reused against changed F/authority/barriers, noncanonical standalone behavior, nonconstant per-batch graph builds, or nonterminating/untyped Vase at 600s. A failed causal premise returns to Review, not synthetic acceptance.

## Consolidation

Reviewed current P13 TB67/RA-193/RA-194 documents and the consolidated family. They are active evidence/decision/closure owners; no independently disposable superseded historical document was proved safe to fold. Folded document index unchanged, no deletion or citation rewrite attempted. Do not delete current authority to meet a cleanup target.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB67 manifest locally SHA-256 `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b`; selector unchanged; no new selector accepted. Independent prefix hash against TB65 remains pending. |
| Decisive claims independently re-derived | 9/9 census hashes; 6,073/6,073 snapshot file hashes; `SourceChartTransitionGraph` constructor/calls inspected in source, distinct from RA-193 CPU attribution. |
| Non-vacuity checked | Timeout lacks a terminal verdict; next TB must distinguish no-graph-rebuild from merely changed diagnostics and verify independent positive and invalid-authority paths. |
| Prior obligations discharged/carried | O18 typed terminal and CB70 wedge guards 870–871 established in TB67; P13-e, P13-f and O16/O17/O19/O6/O9, DR1/DR3/DR2/DR4 carried. |
| Stable accounting | 66/17/49, debt 1, accepted CP2 491/491, selector497 frozen; TB67 candidate 871/871 membership952, no promotion. |
| New candidates/obligations recorded | P13-f bounded graph reuse and its falsifiers in this report/CB71 plan; tracker current entry updated. |
| ORIENTATION currency line | Updated to P13-f Review, 2026-11-01. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 witness state unchanged (Vase timeout still unaccepted); §8 source-wide rebuild pattern added. |
| CHANGELOG | This Review entry recorded. |
| ROADMAP | M6-CP3 current boundary updated; no milestone promoted. |
| Selector manifest | n/a: no selector mutation or acceptance in Review. |
| LESSONS | Existing source/identity/evidence lessons §§1,3,5,6,7 reused; no new general policy needed. |
| Consolidation under CLEAN_UP_POLICY | No safely foldable active decision/evidence files identified; consolidated index preserved. |
| Successor frozen | `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` and exact falsifiers in this record and its plan. |
| Turn boundary held | Static source/evidence review only, no local build, code/test/selector change or runtime. |
| review_check.py boundary | Attempted on verified history-free source snapshot; fails due missing authentic Git ancestry for durable rewrite baseline. No falsely claimed passing check. |
| STATUS lifecycle maintained | Entry beacon published; completion beacon must follow successful remote documentation closeout as final write. |
| Pushed to origin, branch in sync | Pending remote Drive patch transport, pushed-commit verification and final beacon; no fabricated local `git status -sb` against origin. |

# P13-k optimizer source-query cost — static preflight (INCOMPLETE)

**Canonical turn:** `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (Review/Definition, P13-k).  
**Status:** Static source preflight only. **This is not RA-201, a completed DEFN, an approved CB patch, or a runtime verdict.**  
**Source inspected:** Verified immutable source snapshot 41702924049 / artifact 13264691897 / SHA `9d5ab4333e94c527a8d56b11d1ac689632e96eba`; source/test tree was unchanged through the inspected STATUS head `3c100ab78a22ce67ece25658f6af692dc52fe59c`. CB79 semantic source is `3feb2a4182a5a12c2a9f306272756f8333a44b59`.  
**Prior primary evidence:** RA-200, `Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md`, §RA-200.2a. Latest immutable TB73: 886/886 gate, membership 967; independent census Cylinder PASS, BunnyRandom P13-e RED, Vase expected ABNORMAL timeout (600 s). No runtime was executed in this preflight.

## Independently inspected source sites

1. **Repeated source topology validation.** `src/geometry/SurfaceOptimizationRailConstraints.cpp` has a private `source_face_scope` that calls `SourceTopologyRegions::matches_source_faces` on each invocation. `provenance_supports_interval_sheet` calls it for both provenance and interval faces; `fill_surface_optimization_rail_constraints` iterates output vertices and rail intervals. The general `source_face_scope` in `include/directional/geometry/SurfaceMeshOptimizer.h` must also be audited. Separately, `source_optimization_has_complete_authority` in `src/geometry/SurfaceMeshOptimizer.cpp` verifies the full input and face vertices. **Required:** validate immutable source authority at the correct invocation boundary and pass a verifiably source-bound result to inner queries, preserving standalone invalid-input rejection. Do not globally remove the validating public helper or equate array dimensions with source binding. RA-200 measured the rail fill at ~3 minutes before its two-site scratch change versus 0.1 seconds after.

2. **Unconditional projection BVH construction.** `src/geometry/SurfaceMeshOptimizer.cpp` constructs `SourceProjectionCache localCache(constraints)` before deciding whether to use the lent `projectionCache` in `nearest_source_point`, `project_vertices`, and `quad_reference_surface_point`. The cache constructor in `include/directional/geometry/SurfaceMeshOptimizer.h` builds `SurfaceProjectionBvh` for nonempty valid source dimensions. **Required:** construct a local fallback only when no compatible lent cache is available; preserve exact face restrictions, component/sheet filtering, and no-cache standalone behavior. Audit lifetime and source ownership of the lent object. This is not permission to drop complete-authority checks.

3. **Per-quad chart graph rebuild.** `consistent_source_scope` and `quad_reference_surface_point` in `src/geometry/SurfaceMeshOptimizer.cpp` each construct `validation::source_authoritative_detail::SourcePointLabelSupport`, whose constructor owns `SourceChartTransitionGraph` construction (`include/directional/validation/SourceAuthoritativeMeshValidator.h`). `OutputProjectionCache` invokes the first across output quads. A different validation path in `SurfaceMeshOptimizer.cpp` already creates `sourceLabelSupport` once for its containing function. **Required:** one source-labelled support per immutable stage scope; lend by `const` reference only on exact `SourceChartTransitionGraph::borrows`-compatible face matrix, authority, hard-edge set, and tolerance (DESIGN Amendment 27). Preserve the existing zero/ambiguous/no-common-chart rejection semantics. Do not convert the graph into a global mutable cache. RA-200 measured ~20 minutes at this third site across 67,829 Vase quads.

## Prospective three-step CB boundary (NOT YET AUTHORIZED)

The owning DEFN must first make and measure a scratch change for **all three** sites on CB79 and prove unchanged output/verdict. Only afterward freeze exact independently applicable code patches and non-vacuous cost GUARDs, **one separate Code + Build turn per site**, as RA-200 directs. Potential GUARDs must fail if a loop-bound matcher, unnecessary BVH construction with lent cache, or per-quad graph construction reappears; they must also reject invalid source identity, mismatched lent data, cross-component/sheet leakage, and unsupported charts. Avoid timing-only thresholds and avoid weakening the full validation oracle. Subsequent TB is separately artifact-only.

RA-200's earlier scratch `PROBE_K` removed sites 1–2, not site 3. It reached `terminal=NotProductionReady:completion` after 1,521 seconds, with `detail=None` and an empty completion code. That is **not** a diagnosed P13-l cause. The scratch reviewer must first measure the full three-site correction, confirm the same semantic verdict significantly faster, then identify the exact rejecting check and restore the required typed detail/completion code. Only the completed DEFN can assign the rejection to its next authorized owner.

## Outstanding review/authority gate

This turn's authoritative owner in RA-200 is a scratch-capable **Claude Review**. The ChatGPT Web DEFN execution contract is runtime-free; this session has not executed a C++ scratch binary, assembled the exact three patches, measured the full correction, verified GUARD mutations, or identified the terminal rejecting check. Therefore **the Review/Definition is not complete**; no CB successor or source mutation is authorized by this preflight. The canonical successor remains UNKNOWN pending the required scratch adjudication.

Accepted CP2 remains 491/491; stable regression accounting remains 66/17/49, debt 1; selector497 and CP3 remain unpromoted. No claims of test, build, benchmark, acceptance promotion, or resolved Vase production are made.

## Review closeout (incomplete; explicitly open)

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Pending; no selector mutation or promotion |
| Decisive claims independently re-derived | Source call sites inspected; RA-200 timings attributed to prior scratch, not independently reproduced |
| Non-vacuity checked | Planned GUARD falsifiers identified; no actual mutation run |
| Prior obligations discharged/carried | P13-k all three sites + typed terminal reason carried; P13-e remains parallel |
| Stable accounting | CP2 491/491; 66/17/49, debt 1; TB73 886/886, membership 967, 81 deferred |
| New candidates/obligations recorded | No new stable ID; P13-l retained as undiagnosed downstream condition |
| ORIENTATION currency line | Unchanged; review not closed |
| ORIENTATION §3 / §4 / §7 / §8 | Unchanged; review not closed |
| CHANGELOG | Unchanged; review not closed |
| ROADMAP | Unchanged; no milestone transition |
| Selector manifest | Unchanged; no promotion |
| LESSONS | Existing Amendment 27 source-binding/lending rule applies; no new rule established |
| Consolidation under CLEAN_UP_POLICY | Pending full completed REVIEW, with preserved source authority |
| Successor frozen | UNKNOWN pending full P13-k scratch adjudication |
| Turn boundary held | Yes: runtime-free; no source, test, build, selector, or acceptance mutation |
| review_check.py boundary | Not executed as authoritative branch check; immutable tarball lacks git history |
| STATUS lifecycle maintained | Entry beacon published for current turn; final beacon remains to be set |
| Pushed to origin, branch in sync | This static preflight committed via GitHub connector; no local git branch or push check claimed |

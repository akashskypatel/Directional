# M4-CP3-CB4 Code + Build Plan — production A3→A4 exact shared-breakpoint cutover

**Status:** FROZEN / READY
**Turn:** `M4-CP3-CB4`
**Execution mode:** canonical Code + Build / runtime-free
**Normative contract:** `Architecture_M4_DEFN_Frozen_Definitions.md` §17
**Accepted runtime predecessor:** package119 / selector394 **394/394**
**Reviewed baseline semantic source:** `fd532c2f768d0ff6493260deb670cb34b6757712`
**Successor after a green package:** artifact-only `M4-CP3-TB2-EXEC` under a CB4-closeout-frozen TB2 plan

## 1. Objective

Complete the production authority handoff that §17 intentionally deferred after baseline semantic acceptance. A3 must be constructed once from bound A0/A2a/A2a′/A2b authority, independently validated, and passed immutably to A4. A4 must consume the A3 shared subdivision/breakpoint identity unchanged. Floating `support_key` grouping and regional target-derived grid decisions may no longer own shared-boundary subdivision or pairing.

This turn may edit production, tests, build integration and documentation, then compile approved targets. It must not execute generated Directional tests, benchmarks, CLIs, discovery/listing commands, custom meshes, help/version commands, or any other produced binary. Runtime proof belongs to TB2.

## 2. Pre-mutation derivation guard — mandatory

Before editing, enumerate and record a complete site set for:

1. production construction/publication of A2a, A2a′ and A2b products in `RemeshPipeline.cpp`;
2. every production API/options/product field capable of carrying A2b/A3 authority into `SurfaceCellTracing`;
3. every A4 shared-boundary subdivision selector, including target-derived `gridU/gridV`, strip subdivision and breakpoint/materialization paths;
4. every `HardRailPairKey`, `support_key`, hard-rail grouping/pairing consumer and `InvalidHardRailPairing` predicate;
5. all region-domain crossings between `SourceTopologyRegions` / `TopologyRegionId` and `GlobalTopologyPlan` / `NetworkRegionId`;
6. all constructors/factories that can create or validate `GlobalConformityBaselineInput`, `GlobalConformityBaselinePlan`, `ConformitySpanId`, and exact breakpoint locations.

The census must state `N sites found / N classified / K require change` per class. Stop before mutation if any shared-boundary consumer or region-domain mapping remains unclassified.

## 3. Production A3 input authority

Construct `GlobalConformityBaselineInput` from production-owned exact authority, not from test helpers or floating reconstruction:

- `sourceVertices` from the exact current source mesh binding;
- `targetSize` from the bound A0 target-size field;
- exactly one `ConformitySpanInput` per canonical full A2b arc;
- each span's ordered support pieces from the bound exact A2a/A2a′ path authority required by §17.3/§17.4.

Boundary incidences remain producer-rebuilt from `GlobalTopologyPlan` region boundary walks. Do not add caller-supplied family/sign incidence fields, compare raw cross-face `FieldBranch` values, infer support from floating geometry, or treat `GlobalTopologyArc::sourceFaces` alone as an exact path.

If existing A2a/A2a′ products do not expose enough exact ordered path authority for one arc kind, fail the derivation guard and return to Review; do not invent a convention in CB4.

## 4. One production A3 writer and validation boundary

Immediately after the accepted `GlobalTopologyPlan` is constructed and before A4 regional production:

1. build one `GlobalConformityBaselinePlan` with `build_global_conformity_baseline`;
2. independently validate it with the baseline validator before publication/consumption;
3. preserve exact source/network/cut/topology/target-metric bindings and semantic digest;
4. publish/store the immutable A3 product in the pipeline's product snapshot/context authority;
5. pass A4 only a const/immutable reference or closed product handle.

No A4 code may rebuild the plan, choose an alternate plan, alter counts, insert/remove/reorder shared breakpoints, or reinterpret the target metric for shared seams.

## 5. Region-domain cutover

The current phase-front path is organized around `SourceTopologyRegions` / `TopologyRegionId`; A3 is defined over A2b `GlobalTopologyPlan` / `NetworkRegionId`. CB4 must establish one explicit authority-preserving bridge before regional construction:

- preferred: make A2b `NetworkRegionId` the production regional work identity where the cutover permits it;
- acceptable only with proof: an explicit deterministic checked mapping from each A2b region to the older A4 work record, with total coverage, no ambiguity, and digest/source binding.

Container position, source-face overlap, geometric proximity, or first-match selection is forbidden as the mapping authority. A missing/ambiguous mapping is a typed fail-closed condition.

## 6. Exact shared-boundary materialization

A4 boundary construction must consume the accepted schedule exactly:

- shared segment identity derives from `ConformitySpanId` plus exact endpoint ordinals / `ConformityBreakpointId`;
- opposite incidences consume reversed exact ordinal intervals of the same span;
- exact `breakpoint_location(...)` is the source-location authority for materialized endpoints;
- both sides of a shared A2b span must therefore name the same semantic breakpoints before any local chart geometry is considered.

A4 may choose local interior topology/quality strategy under §17.8 after its boundary is fixed. Target-derived `gridU/gridV` or local strip counts may survive only when demonstrably interior/local and incapable of changing an A3-owned shared boundary.

## 7. Retire post-hoc hard-rail pairing authority

Delete or demote `HardRailPairKey` plus floating/tolerance `support_key` from **semantic pairing authority**. The exact shared-boundary key is the A3 span + exact ordinal interval and incidence orientation. Pairing must be determined from that exact identity, not rounded barycentric coordinates or Euclidean coincidence.

Preserve independently owned A4-local checks:

- route/topology consistency where still contractually required;
- `SurfaceFrontEdge::family` and `advanceSign` local field-frame relation from §17.11;
- typed source/component/sheet isolation and all existing fail-closed product rules.

Do not misread family/sign-free A3 as authorization to delete A4-local field-frame semantics.

## 8. Required Code + Build test contracts

Add focused tests that compile into the immutable package and are runtime-executed only in TB2. They must cover at least:

1. production pipeline constructs and publishes exactly one validated baseline plan after A2b;
2. all `Mandatory`, `Trace`, and `Cut` span kinds bind through exact A3 support authority without invented family/sign;
3. fixed A3 plan + changed A4/local target settings cannot change shared breakpoint IDs or shared boundary segmentation;
4. opposite A4 incidences consume exact reversed ordinal intervals of one span;
5. hard-rail pairing succeeds from exact span/ordinal identity even when floating support representations differ within a way that would have challenged the old rounded key;
6. tampered/mismatched A2b/A3 binding fails closed before regional commit;
7. source audit proves no production semantic pairing decision still depends on the old floating `support_key` key path;
8. the exact-torus production witness reaches beyond the historical `InvalidHardRailPairing` stop when executed later in TB2.

Test fixtures must establish their preconditions independently and remain behavior-focused. Do not weaken the accepted selector394 identities. New identities append after the accepted selector394 prefix; their exact count/order/hash is frozen in CB4 closeout before packaging/TB2.

## 9. Generalization and non-regression requirements

The change must enforce the semantic invariant for every shared A2b arc, not only the torus fixture. In particular:

- no name/index/fixture-specific path;
- no tolerance in topological/shared-boundary identity;
- no post-hoc merge/repair after regional output;
- no arbitrary subset search or fallback producer to evade a typed rejection;
- deterministic identity independent of source-face row order, container order, output emission order and thread scheduling;
- accepted selector394 definitions/order remain unchanged as the frozen predecessor prefix.

## 10. Build boundary and compile requirements

Before any package compile:

1. commit/push the exact intended semantic source;
2. perform the mandatory exact-source changed-owner/pre-package compile through `.github/workflows/agent-compile-reusable.yml` with `runtimeExecution=false` and GMP/GMPXX required;
3. if green, compile/package the complete approved runtime-owner surface, including at minimum the four selector owner executables plus `directional_core`, `directional_pipeline`, `directional_compiled_api_tests`, and `directional_benchmarks` as compile evidence;
4. package the exact source archive, selector, fixtures/test-data needed by the frozen TB2 plan, clean source status, command-boundary evidence, GMP evidence and self-excluding manifest.

No local compile is authoritative. No runtime command is permitted in CB4. A compile-green package remains unaccepted until TB2.

## 11. Work preservation and connector discipline

Before any remote semantic mutation, emit a `Directional-Work-Preservation-Patch-v1` patch over the exact current branch head, verify `git diff --check`, exact intended path set, diff-body SHA-256 and expected blob SHAs, upload it to `My Drive/Directional-CI`, and apply it through the existing `agent-google-drive-reusable.yml` workflow. Do not widen reusable workflow permissions. Permanently remove the consumed Drive patch after successful application.

Temporary caller workflows are control plane only and must be removed workflow-first before turn cleanup. Use the durable cleanup manifest/workflow at formal closeout.

## 12. CB4 completion and TB2 plan

CB4 is complete only when:

- derivation guard/site census is recorded;
- production A3 is one validated writer between A2b and A4;
- shared boundaries consume exact span/ordinal authority;
- floating `support_key` no longer owns hard-rail pairing;
- A4-local field semantics remain intact;
- focused cutover tests are authored and all affected/approved targets compile with mandatory GMP/GMPXX;
- source/package status is clean and immutable package evidence is preserved;
- a frozen artifact-only `Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md` is published.

The TB2 plan must at minimum re-run accepted selector394 as an immutable predecessor, execute the new cutover identities with any required success-visible receipts, exercise the exact-torus production path and prove `InvalidHardRailPairing` is no longer the stop, check fixed-plan target-variation invariance, and require immutable package/source/execution-view postflight. Only later TB/Review may decide CP3 closure or advancement toward CP4.

**Exact successor after CB4 closeout: `M4-CP3-TB2-EXEC`.**

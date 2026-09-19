# M5-CP1 Code + Build Plan — Canonical Relation IDs and Selected Path Certificates

**Turn:** `M5-CP1-CB1`
**Milestone/checkpoint:** M5 / CP1
**Mode:** Code + Build / runtime-free
**Definition authority:** `Architecture_M5_Frozen_Definitions.md`
**Accepted entering runtime authority:** package `10591801825` / semantic source `aa6cab176f4f7297c1f9ab20a7a49bf6a00a7431` / selector430 **430/430**

## 1. Goal

Implement the smallest producer-to-consumer slice that makes periodic relation identity independent of storage order and carries the exact relation path selected by the producer into quotient/materialized lineage. Compile the changed production and test targets. Do **not** execute generated Directional binaries, tests, discovery, or benchmarks.

## 2. Assumptions fixed by M5-DEFN

- `PeriodicRelationId` is semantic path content, not an ordinal or sorted rank.
- Transport/action is relation value and is excluded from identity.
- Multiple same-region relations are valid when their canonical carrier identities differ.
- Producer-selected path certificates are authority; downstream graph search is forbidden as a semantic substitute.
- M6 occurrence-complex/stage-product work is out of scope.
- CP2 owns complete typed negative acceptance. CP1 may add only the minimum construction errors needed to reject malformed identity/path data while building the new representation.

## 3. Surgical implementation steps

### Step 1 — introduce canonical carrier/relation identity

**Primary owners:**
- `include/directional/authority/AuthorityIds.h`
- `include/directional/authority/CanonicalRoute.h` or one narrowly scoped authority header if required to avoid include cycles
- `include/directional/geometry/SurfaceCellTracing.h`

Required change:

1. replace index-backed `PeriodicRelationId` semantics with a non-ordinal composite identity derived from `TopologyRegionId` plus canonical generator/cut carrier paths;
2. expose an exact carrier identity for `CanonicalRoute` that excludes transport but retains semantic step kind, source-edge topology, and checked transition identity;
3. make `SurfacePeriodicHolonomy::make(...)` verify/derive the canonical relation identity from the relation's authoritative routes;
4. remove production authority to relabel a relation through `with_id(...)` or equivalent unchecked ordinal mutation.

**Verify by compile/static source checks:** no production `PeriodicRelationId::from_index(...)` remains; relation equality/order is content-derived; no hash/front-edge/container position is part of the identity.

### Step 2 — remove storage/aggregation renumbering

**Primary owner:** `src/pipeline/RemeshPipeline.cpp`

Required change:

- delete periodic relation offset/local-to-global ordinal remapping;
- preserve canonical relation IDs unchanged when component products are aggregated;
- reject a true canonical-ID collision with unequal value rather than inventing a replacement ID.

Occurrence/quotient-class remapping is not part of this step and must remain unchanged unless the compiler requires a purely mechanical adjacent edit.

**Verify:** static audit finds no `periodicRelationOffset`-style semantic renumbering; component permutation cannot change an existing relation ID.

### Step 3 — allow topology-distinct same-region relation insertion

**Primary owner:** `src/geometry/SurfaceCellTracing.cpp`

Required change:

- key relation equivalence by canonical relation ID plus exact value;
- exact duplicate -> existing equivalent/duplicate handling;
- same canonical ID with differing value -> fail closed for CP2 to classify precisely;
- distinct canonical IDs in the same topology region may coexist;
- remove the current “second same-scope relation => `AmbiguousBasis`” shortcut when the new canonical identities distinguish them.

Do not add a basis search or discovery-order election. The relation path itself is the identity.

### Step 4 — publish selected relation-path certificates

**Primary owners:**
- `include/directional/geometry/PureQuadCompletion.h`
- `src/pipeline/RemeshPipeline.cpp`
- any immediately adjacent phase-front materialization helper required by the existing ownership flow

Required change:

- add the `SelectedRelationPathCertificate` / ordered step representation frozen in `Architecture_M5_Frozen_Definitions.md` §4;
- publish it from the exact equivalence chain actually used to form the materialized lineage;
- bind endpoints with existing row-order-independent `SourceChartComponentIdentity` plus exact `SourceProjectionChart` where the current seam already has one;
- record step direction, typed relation ID, applied exact transform, and recomputed composed transform;
- keep front-edge indices diagnostic-only if removing them would broaden scope.

Do not add a generic path-search framework.

### Step 5 — cut the known reachability consumer over to validation

**Primary owner:** `src/geometry/PureQuadCompletion.cpp`

Required change:

- replace the hard-rail adjacency/BFS semantic reconstruction in `close_completion_lineage_source_authority(...)` with validation of producer-carried selected certificates;
- independently recompute endpoint/source-support membership, relation existence, step direction, per-step transform/inverse, continuity, and composed transport;
- retain `SourceChartTransitionGraph` only for elementary source-chart/component/rebind facts;
- fail closed when the certificate is missing or invalid; never search for an alternate valid route.

### Step 6 — author focused CP1 regression definitions

**Primary test owners:** existing surface-cell transition/quotient and completion-lineage test files; avoid a new test binary unless current ownership makes that unavoidable.

Add focused identities that will be executed only in the later TB turn:

1. two topology-distinct same-region periodic relations receive stable unequal canonical IDs independent of insertion/storage order;
2. reversing both carrier paths preserves the same relation ID;
3. changing only transport/action preserves the expected canonical locus ID so the value conflict is observable rather than silently renamed;
4. component aggregation preserves relation IDs without offset remapping;
5. producer-selected ordered path certificate survives relation-container permutation;
6. inserting an unused valid relation leaves the selected certificate and materialized semantic lineage unchanged;
7. a certificate with one altered step direction/transform fails validation rather than causing alternate-path search;
8. the existing `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` mechanism keeps its **`>=2` relation / `>=2` periodic-edge** discriminator.

Independent expected IDs/path content must be derived from semantic carriers on the test side; do not call the production relation-ID factory to calculate the expected identity.

## 4. Non-goals / forbidden changes

- no M6 occurrence-complex or embedding-stage split;
- no CP2 full five-class selector/acceptance claim;
- no weakening of existing accepted selector430 identities;
- no source-grid recovery/fallback substitution;
- no front-edge index promoted to semantic identity;
- no sorted-rank relation IDs;
- no new graph search that chooses relation paths downstream;
- no unrelated refactor, formatting sweep, cache/performance work, or diagnostic taxonomy expansion.

## 5. Compile-only verification

The Code + Build turn must:

1. apply the complete source/test patch to one exact pushed semantic source;
2. run `git diff --check` / source-only audits;
3. compile through the mandatory GMP reusable workflow with `DIRECTIONAL_ENABLE_GMP=ON` and verified `gmpxx` + `gmp` linkage;
4. compile at minimum the production owner target plus every test target whose source changed; if repository dependency closure requires the standard package target set, compile/package that exact set rather than executing anything;
5. package immutable evidence with exact source SHA and `runtimeExecution=false`.

No generated executable may be invoked for discovery, `--help`, listing, tests, benchmarks, or custom inputs.

## 6. Future Test + Benchmark acceptance contract

A successful compile closes only Code + Build. The successor TB plan must consume the immutable package without rebuilding and must, in fresh processes:

- run the accepted selector430 predecessor unchanged;
- run the new focused CP1 identities;
- require exact-one selection, zero skip/timeout/crash/orchestration error, and immutable pre/postflight;
- independently inspect that the relation-order mechanism remains non-vacuous (`>=2` distinct canonical relation IDs and `>=2` owned periodic edges in the focused mechanism fixture);
- treat direct/helper mechanism green as CP1 mechanism credit only — **no M5 production debt closes until CP3 direct-production evidence**.

CP1 acceptance additionally requires source review showing no production `PeriodicRelationId::from_index(...)`, no component-offset relation renumbering, and no consumer-side BFS/DFS path selection in `close_completion_lineage_source_authority(...)`.

## 7. Stop conditions

Stop to Review before compilation if implementation would require:

- rank/hash/position identity;
- transport/action inside canonical relation identity;
- a second semantic relation writer;
- M6 occurrence authority;
- a downstream alternate-path search;
- weakening the accepted M4 gate or the original M5 debt discriminators.

Compile failure returns to Code + Build correction on the same semantic objective. No runtime is authorized in this turn.

## 8. Expected successor on green compile

`M5-CP1-TB1-EXEC`, artifact-only, with the exact package/source/selector identities frozen by the CB closeout.

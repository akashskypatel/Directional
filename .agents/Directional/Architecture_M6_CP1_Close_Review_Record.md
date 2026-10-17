# `M6-CP1-CLOSE-REV` — CP1 Closure Review Record

**Turn:** `M6-CP1-CLOSE-REV` (runtime-free Review)
**Disposition:** **ACCEPTED — M6 CP1 CLOSED, mechanism-only**
**Reviewed runtime authority:** `11330703256 / 3f40f04a0e9d382b2ec82cf37a03c18ad405eb05`
**Reviewed gate:** focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6` + selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` = **479/479 PASS**
**Accounting:** **60 events / 16 categories / 44 recurrences; debt 1**
**Successor:** `M6-CP2-DEFN`

No product, test, fixture, selector, benchmark, build, optimizer, validator, or runtime source is changed by this Review.

## 1. Source authority and review boundary

The close Review re-opened exact current branch source through source-snapshot run `37299472823`, artifact `11341120397`, source/event SHA `910eb6b10ba21237d70ff4b87a2ad291e7bc530a`. The artifact verified its archive SHA before inspection. A fresh GitHub compare from promoted source `3f40f04a...` to current branch HEAD shows only documentation/control/mailbox/`STATUS`/snapshot-trigger changes; there is **no** `src/`, `include/`, `tests/`, `benchmarks/`, CMake, or fixture-source advance. Therefore the static current-HEAD review below applies to the exact semantic bytes that produced the promoted 479/479 runtime.

The frozen exit list is taken verbatim from `Architecture_M6_Frozen_Definitions.md` §"CP1 exit scope — restated". RA-27b §3 is binding: defensive/static-only branches are classified with later owners, `G4-B002` remains open, and successful closure routes to `M6-CP2-DEFN`.

## 2. Six frozen CP1 exit items — verbatim adjudication

The six frozen items are:

1. **"The A5 product is conformant (§3), including retirement of the unread legacy `SurfaceOccurrence` `isolationSheet` / `chart` / `lattice`."**
2. **"The A6 `SurfaceQuotientProduct` exists with member-set `QuotientClassId` (§4.3), one `QuotientRelationCertificate` and one ledger row per owned relation (§4.4), and `QuotientCertificate` / `MaterializationCertificate` (§4.6)."**
3. **"The A7 `SourceAttachedGeometryProduct` exists with its certificates (§5)."**
4. **"`build_authoritative_phase_front_mesh` is a thin adapter with no semantic decision (§10)."**
5. **"The `G4-B002` A6 stage boundary exists (§8.1)."**
6. **"There is no coordinate/position weld, and the focused multi-isolation identity is green (§10)."**

| Item | Result | Exact current-source evidence | Focused-30 evidence ordinals |
|---|---|---|---|
| 1 — A5 conformant / legacy fields retired | **PASS** | `SurfaceOccurrence` carries semantic occurrence ID, exact `SurfacePoint`/`SourceSupport`, chart component, topology region, complete wedge sheets/bindings, placement provenance and wedge-isolation evidence; there are no standalone legacy `isolationSheet`, `chart`, or `lattice` members (`include/directional/pipeline/RemeshPipeline.h:814-841`). A5 publishes `validatedIsolationCertificateCount` (`:893-904`; `src/pipeline/RemeshPipeline.cpp:4958-4966`). | **1, 2, 3, 7, 21, 22, 23, 30** |
| 2 — A6 member-set quotient + exact-once ledger/certificates | **PASS** | `SurfaceQuotientClassId` is the complete member vector (`RemeshPipeline.h:1023-1027`); relation certificate/consumption types are explicit (`:1029-1064`); `QuotientCertificate` and `MaterializationCertificate` carry exactness flags (`:1187-1207`); the product exposes those certificates (`:1258-1290`). Validation recomputes published class sets and populates exact-bijection/transitive-partition flags (`src/pipeline/RemeshPipeline.cpp:5879-6030`). | **8, 9, 10, 11, 12** |
| 3 — A7 geometry product + certificates | **PASS** | `SourceSupportCertificate`, `SourceAttachedGeometryVertex`, `GeometryEmbeddingCertificate`, and `SourceAttachedGeometryProduct` are explicit immutable surfaces (`RemeshPipeline.h:1339-1455`). A7's RA-27a wedge rule performs fixed-point connectivity over each occurrence's own retained wedge sheets and rejects disconnected cases at `cross-sheet:wedge` (`src/pipeline/RemeshPipeline.cpp:6884-6914`). The materialized product is returned only after source support/topology validation (`:7351`). | **13–20, 29** |
| 4 — thin adapter | **PASS** | The adapter consumes A5 → A6 → A7 products, maps A7 classes to output vertices/quads by semantic IDs, and copies certificate-derived result values (`src/pipeline/RemeshPipeline.cpp:7357-7613`). Public `build_authoritative_phase_front_mesh` is only a wrapper calling the hard-feature form with `nullptr` (`:7616-7622`). C3 is sourced from A5 exactly at `validatedIsolationCertificateCount` (`:7607-7608`). | **24** |
| 5 — `G4-B002` A6 stage boundary | **PASS for mechanism boundary; debt remains open** | A6 owns and exposes `closed_complex_view()` (`RemeshPipeline.h:1295-1298`). The closed-complex builder is A6-local (`src/pipeline/RemeshPipeline.cpp:6074-6379`) and simplification candidates consume the A6 closed-complex view directly (`:6385-6475`). This satisfies CP1's mechanism boundary only; frozen §8.1 still assigns direct produced-witness debt to CP3. | **25, 26, 27, 28** |
| 6 — no coordinate/position weld + multi-isolation green | **PASS** | No coordinate/position weld exists in A5/A6/A7/adapter. Materialization allocates one output vertex per `SurfaceQuotientClassId` and maps cell corners by class identity (`src/pipeline/RemeshPipeline.cpp:7490-7555`), never by geometric coincidence. The reviewed 479/479 gate keeps coincident-unrelated occurrences distinct, exercises the same-simplex point guard, and proves multi-isolation materialization. | **4, 15, 5** |

All six frozen exit items pass. Item 5 does **not** discharge `G4-B002`; project debt remains **1** exactly as RA-27b requires.

## 3. RA-26 current-HEAD provenance-consumer census

RA-26 distinguishes **authority-deciding** reads (an anchor decides destination/component/sheet/chart membership, lineage, topology, certificate content, or a consistency verdict) from **reference/reconstruction** reads (an anchor supplies a geometric representation or continuous reference without changing semantic authority). The close Review repeated the searchable current-HEAD census rather than relying on the old line-anchor list.

### 3.1 A7 and adapter reconstruction uses

A7 chooses one deterministic occurrence representative only after quotient membership is fixed (`src/pipeline/RemeshPipeline.cpp:6744-6756`). Uses of that representative at `:6757-6848` reconstruct/check the published common source support, finite coordinates, edge parameter or face barycentrics. They cannot union classes, choose a sheet/chart authority, or alter topology. Complete class-wide `sourceCharts`, `sourceTopologyRegions`, and `sourceIsolationSheets` are accumulated from all members before cross-component/cross-sheet checks (`:6870-6877`); the exact wedge connectivity rule then acts on each member's own semantic wedge evidence (`:6884-6914`). A7 therefore contains **no authority-deciding provenance-face consumer**.

The adapter copies `embedded.sourcePoint` into legacy vertex provenance (`:7496-7523`) and uses quotient class identity for output indexing/connectivity (`:7490-7555`). This is compatibility projection, not semantic authority.

### 3.2 Class-wide consumers

- `project_surface_cell_vertex_chart_authority` projects complete lineage chart authority, not one provenance face (`src/pipeline/RemeshPipeline.cpp:8124-...`).
- Final-validator face chart/local-sheet resolution calls `resolve_compatible_chart` with the per-vertex class-wide chart authority (`src/validation/SourceAuthoritativeMeshValidator.cpp:1232-1262`).
- Final-validation coverage/normal authority remains class-wide or source-face exact as recorded by RA-26; no source change occurred after that audit.

### 3.3 Representation-only and reference-selecting consumers

- `project_vertices` seeds projection from `vertexProvenance` (`src/geometry/SurfaceMeshOptimizer.cpp:781-798`). With provenance-entity projection enabled, a class-common vertex/edge/face support constrains the position to the same semantic support. Its component/sheet comparisons at `:819-878` compare the anchor-derived required scope with the projected anchor scope and are therefore vacuous on the authoritative path. This is **not authority-deciding**; RA-26 §5(iii) routes retirement/replacement to `M6-CP2-DEFN`.
- Optimizer energy uses the first quad corner's provenance as normal/field reference (`SurfaceMeshOptimizer.cpp:1470-1509`); the gradient uses the same kind of reference. These are **reference-selecting** and remain RA-26 §5(i), owner `M6-DEFN-R5` → CP3.
- Final-validation field alignment is class-wide when endpoint compatible charts intersect and has only the frozen first-endpoint-scope fallback; that fallback is **reference-selecting**, RA-26 §5(ii), owner `M6-DEFN-R5` → CP3.
- `make_surface_optimization_overlay` source-row selection is test-only and does not read A7 provenance; `M6-CP1-CB12-REV-OBS-01` remains M8-CP2.

**RA-26 §3 result: PASS. No authority-deciding provenance-face consumer exists at current HEAD.** The known reference-selection/permutation obligations remain explicitly later-owned; they are not silently treated as closed.

## 4. Defensive/static-only branch classification required by RA-27b

| Branch | CP1 classification | Later owner |
|---|---|---|
| C2 empty-front A5 defensive branch | **ACCEPTED DEFENSIVE / unreachable through accepted A4 authority / fail-closed** | none required |
| C4 `QuotientClosedComplexStripContinuationMismatch` | **ACCEPTED DEFENSIVE / fail-closed; executed witness still absent** | `M6-CP2-DEFN` defines weld-pinched malformed-authority witness + verifier manifoldness recompute |
| RA-27a wedge region filter | **STATICALLY VERIFIED / non-blocking** | first M6-CP2 Code + Build, appended tamper |
| RA-27a connectivity-vs-"touches" | **STATICALLY VERIFIED / non-blocking** | first M6-CP2 Code + Build, appended tamper |
| RA-27a three-sheet partial connectivity | **STATICALLY VERIFIED / non-blocking** | first M6-CP2 Code + Build, appended tamper |
| RA-27a §6 seam-collinear edge rule falsifier | **CARRIED / non-blocking; production rule unchanged** | `M6-DEFN-R5` → CP3 |
| `M6-CP1-TB12-REV-OBS-01` A6→A5 / A7→A6,A5 certificate binding | **CARRIED** | `M6-CP2-DEFN` / CP2 |
| `M6-CP1-TB12-R1-REV-OBS-02` adapter drops A7 cross-sheet site | **CARRIED diagnostics only** | M8-CP2 |

No carried item belongs to the CP1 product-separation exit contract. No Review-source repair is required or authorized.

## 5. Non-vacuity and evidence limits

The promoted runtime proves focused30 **30/30** + selector449 **449/449**. Identity 29 proves one runtime dimension of the wedge rule only: a non-empty transition list whose transitions are all outside the retained sheet set is rejected. The region filter, one-endpoint/touches distinction, and multi-sheet partial-connectivity cases remain static-only and are intentionally assigned to the first CP2 Code + Build. This record does not overclaim those as runtime-proved.

Likewise, the A6 closed-complex boundary is mechanism-only evidence. `G4-B002` direct-produced-witness debt is still open and must be re-proved in CP3 after A8 exists.

## 6. Closure adjudication

`M6-CP1-CLOSE-REV` finds no frozen CP1 blocker. The six verbatim exit items pass, RA-26 §3 passes at current semantic HEAD, carried diagnostics/counters remain exact, and every defensive/static-only branch has an explicit disposition.

**M6 CP1 is CLOSED / ACCEPTED, mechanism-only.** Stable accounting remains **60 / 16 / 44** and project debt remains **1**. The exact successor is **`M6-CP2-DEFN`**; `M6-DEFN-R5` remains after CP2 as the CP3-entry definition gate.

## 7. Mandatory Review closeout table

| Duty | Result |
|---|---|
| Exact current semantic source | PASS — no semantic-source advance from promoted `3f40f04a...`; source snapshot `37299472823 / 11341120397` reviewed |
| Frozen item 1 / A5 | PASS — ordinals 1,2,3,7,21,22,23,30 |
| Frozen item 2 / A6 | PASS — ordinals 8–12 |
| Frozen item 3 / A7 | PASS — ordinals 13–20,29 |
| Frozen item 4 / thin adapter | PASS — ordinal 24 |
| Frozen item 5 / `G4-B002` boundary | PASS mechanism-only — ordinals 25–28; debt stays 1 |
| Frozen item 6 / no weld + multi-isolation | PASS — ordinals 4,15,5 |
| RA-26 §3 provenance-face census | PASS — zero authority-deciding consumers; reference/reconstruction obligations retained |
| Defensive/static-only classification | PASS — explicit owners in §4 |
| Runtime claim | 479/479 promoted; static-only wedge conjuncts not overclaimed |
| Stable accounting | +0 → **60 / 16 / 44**, debt **1** |
| CP1 disposition | **CLOSED / ACCEPTED, mechanism-only** |
| Exact successor | **`M6-CP2-DEFN`** |

**Final boundary check:** `python3 .agents/Directional/tools/review_check.py boundary --expect-selector 449=d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` → **ALL CHECKS PASSED**. No product/test/fixture/build or selector mutation was detected.

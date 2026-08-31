# M3 CP4c-3 CB2 — Code + Build Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-CB2`
Status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**

- Phase: M3 / CP4c-3, Amendment 15 implementation
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Starting semantic authority: `d260f6a9c0bc60946b1c4d30ed77f9e838552ab6`
- Built evidence commit: `005512f20ed56edc793f4d6505f3d2b4c2999c71`
- Remote synchronization verified: yes; the reusable compiler checked out the exact pushed semantic commit

## Implemented

- **AM1:** derives and publishes each region's interior hard-feature barrier set `B(R)` and its connected-component shape before the transport cut.
- **AM2 / Amendment 15 option A′:** `make_local_region_mesh` rewrites the derived local face array by splitting vertex fans along `B(R)`. Region-product topology is unchanged. The now many-to-one `globalVertexByLocal` mapping was audited at every A1 consumer.
- **AM3:** the stale equality between the uncut region Euler characteristic and the derived local mesh is replaced by the cut identity `χ(R_cut) = χ(R) − χ(B) + ∂`, with appended typed error `CutTransportDomainIdentityMismatch`.
- **AM4:** prescribed interior singularities must bind to a local-vertex or slit-boundary cycle; an unbound prescribed singularity fails closed. Per-region diagnostics publish local/slit/unbound counts.
- **AM5:** AM2–AM4 landed together. The chosen implementation is frozen **option A′**, not fallback D.
- **AM6:** per-region diagnostics publish transport-domain/cycle/index shape, witness kind, and boundary correction rather than silently weakening the closed-surface index equality.
- **AM7:** the prescribed-sphere topology failure now distinguishes `NoCarrierMatch` from `AmbiguousCarrierMatch` and identifies precise/widened-pass provenance. No sphere corrective was designed in this turn.
- **AM8:** selector lineage is frozen through **373**. Ordinals 368–370 carry the inherited sphere/R10/R8 identities; ordinals 371–373 carry Amendment 15's three identities.
- **AL8 orchestration control:** digest authoring gained a reusable 64-lowercase-hex validator. This is control-plane support only.

The inherited `R10-CAND-01` proposal-heuristic correction and `R8-CAND-02` empty-network product correction are **not claimed implemented or accepted** by this CB. Their identities are compiled and gated at ordinals 369 and 370 so TB can expose their current product behavior. The canonical proposal still treats trace-crossed edges as proposal barriers, and the new empty-network error surface is not runtime evidence by itself.

## Engineering-Guideline Review

- Material assumptions surfaced: the cut is a derived A1 transport view, not a mutation of the A0/A2 region product; isolation seams remain traversable and are not barriers.
- Simplest sufficient approach chosen: face-array rewrite in the already-derived local mesh, with existing `TriMesh::set_mesh` re-deriving topology.
- No smaller approach satisfies the contract because merely skipping missing adjacencies would weaken the cycle basis without representing the required slit topology.
- Unrelated refactors/style drift avoided: yes.
- Every changed line traces to Amendment 15, AM1–AM8 diagnostics/gate support, or the diagnosed compile correction.

## Files Changed

Semantic source changes span the A1 transport authority, A2a′ diagnostic provenance, public diagnostic/error surfaces, the frozen selectors 370/373, the six compiled gate identities, and the orchestration digest-authoring helper. No unrelated product subsystem was refactored.

## Domain Invariants

- `SourceTopologyRegion` face membership, published Euler characteristic, and boundary-loop count remain facts about the **uncut** source complex.
- `B(R)` contains only `HardFeature` edges with both incident faces in the region; source-boundary, region-crossing, component-crossing, traversable, and isolation-seam edges are not silently reclassified.
- Barrier cuts affect only A1's local transport mesh; no geometry moves.
- Every cut edge becomes local boundary and therefore cannot be an inner-edge cycle-basis column.
- Every prescribed singularity participating in the cut transport domain must remain cycle-bound or fail closed.

## Generalization Review

The implementation derives the cut from topology and barrier incidence, not source edge `0-3` or any fixture index. It applies to arbitrary connected region complexes carrying non-separating hard-feature trees/arcs. Risks retained for TB are fan splitting at high-valence barrier vertices, singularities on barrier endpoints/branches, the switch to `RelativeBoundary` index accounting, and the inherited sphere/R10/R8 product questions.

## Build

- Corrected authoritative workflow/run/job: `33347935915 / 99355596358` using mandatory `.github/workflows/agent-compile-reusable.yml`.
- Exact source: `005512f20ed56edc793f4d6505f3d2b4c2999c71`.
- Result/package **69**: artifact `9742715856`, Actions SHA-256 `2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`.
- Diagnostic log artifact: `9742715997`, SHA-256 `f0f94864be943658bc4d461bdafc312b1d40333e7eca9d2dd4ae88cacdfb218b`.
- Packaged source archive SHA-256: `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`.
- Internal package manifest: **28/28 PASS**; source-status snapshots clean; preflight exit `0`; build exit `0`.
- Standard targets: all **8/8** compiled/linked (`directional_core`, `directional_pipeline`, four surface-cell test executables, compiled API tests, benchmarks).
- Exact arithmetic: `DIRECTIONAL_ENABLE_GMP=ON`; authoritative link command contains both `libgmpxx` and `libgmp`; `exactArithmeticBackend=GMP`.
- ccache: 116 cacheable compilations, 76 hits / 40 misses.
- Tests or benchmarks executed: **none**. `runtimeExecution=false`, `semanticContracts=compiled-not-executed`.

### Compile corrective loop

The first compile attempt `33347423799 / 99354145677` stopped at compile time because adding non-default-constructible `TopologyRegionId` to `FieldTransportRegionDiagnostics` implicitly deleted default construction of that diagnostics object and `LocalRegionMesh`. No Directional runtime executed. The sole corrective initialized those objects explicitly with the owning region id; commit `005512f20ed56edc793f4d6505f3d2b4c2999c71` then compiled green. This compile-only defect does not create a stable semantic regression.

## Frozen selector authority

| Selector | SHA-256 |
|---|---|
| 355 prefix | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| 365 | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |
| 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` |
| **373** | **`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`** |

Every file has cardinality equal to unique-cardinality and every adjacent predecessor is a byte-exact prefix. No gate identity executed in CB2.

## Known Risks

- Runtime has not yet proved the mechanical witness's `B(R)` decomposition or the Euler-cut arithmetic; a measured barrier cycle would falsify Amendment 15's theorem and must route to review.
- `M3-CP4c3-DEFN-R1-CAND-01` remains non-stable until ordinal 373 proves zero unbound prescribed singularities.
- The prescribed sphere remains one level short until AM7 runtime provenance distinguishes no-match from ambiguity; AL4 still forbids designing across that uncertainty.
- `R10-CAND-01` and `R8-CAND-02` remain open product questions; their newly gated identities are not compile-time proof of their corrections.

## Mandatory Test + Benchmark Plan

Plan: `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Plan.md`. Consume package 69 / artifact `9742715856` exactly; no rebuild, repair, relink, generated discovery, or package mutation. Execute selector 373 one identity per fresh process with first-red hard stop and all mutation flags false. A green 373/373 closes CP4c-3; any semantic red routes to `REVIEW + PLAN`.

## Next Turn

Type: **Test + Benchmark**
Exact successor: **`M3-CP4c-3-TB2` artifact-only**, consuming immutable package 69.

## Live Handoff

`Future_Chat_Session_Handoff.md`, `TODO.md`, `ROADMAP.md`, the regression tracker, changelog, and CP4c consolidated record are updated in the documentation-only closeout commit. Evidence commit remains `005512f20ed56edc793f4d6505f3d2b4c2999c71` independently of that later handoff commit.

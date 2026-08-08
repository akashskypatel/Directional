# Gate 4 Topology-Region Independent Design Review Report

- Phase: G4 topology-distinct completion and singularities
- Validated source commit: `3ca89ab55efff461b050fb12033174be70e7464f`
- Reviewed proposed plan: topology-region materialization and regression-corrections proposal at planning head `14627b6d9f5038f085a3a128e9c870f8c999f54a`
- Reviewer independence confirmed: yes; this review did not author the implementation or its artifact-only runtime report and independently inspected exact source, immutable artifacts, tests, public option contracts, and supplied research/reference material
- Planning commit, when applicable: `PLANNING_COMMIT_RECORDED_BY_REVIEW_TRANSITION`

## Evidence Reviewed

- Source diff: exact implementation `3ca89ab5...` and its six changed production/test files, plus the unchanged production state through planning head `14627b6...`.
- Build evidence: artifact `9022061741`, outer SHA-256 `df23a89f26d0769fa3433bf8996d2d090eaa82770ddc52a52018e51286087306`; recursive manifest **48/48**; log artifact `9022061947`, SHA-256 `8a7c5271791a1e8182d4ff2b0d5d32ebfe6e47f6e36661ba5b431f00f898256d`; compile-only boundary and seven linked targets confirmed.
- Test evidence: artifact-only report for topology-region **9/9**, retained G0-G3 **16/17**, producer **124/127**, completion/simplification **154/164**, validation **60/60**, API **8/8**, plus exact direct plane/seam/close-sheets/cylinder/torus observations.
- Benchmark evidence: exact raw hashes and 3/3 determinism records; close-sheets geometry, topology, and per-component geometry multisets compared across accepted/candidate artifacts.
- Architecture/contracts: `DESIGN.md`, public `SurfaceCellOptions::retainIntermediateGeometry` documentation, producer disposition contract, phase-front/front-edge/periodic structures, materializer, completion handoff, source-support and ownership/provenance types.
- Research: supplied MIQ, QEx, Directional Fields STAR, Instant Meshes, QuadWild, FlowRep, AutoRemesher source, ideation notes, and topology references. MIQ establishes exact integer grid-automorphism transitions; QEx establishes that integer grid coordinates are not in one-to-one correspondence with output vertices when charts overlap and extracts through transition-aware local connectivity.
- Historical diagnostics: prior bounded-disk torus failure, current four annular regions/eight internal isolation seams/four periodic relations, embedded-relief regression, and close-sheets order reversal.

## Findings

| ID | Severity | Finding | Evidence and impact |
|---|---|---|---|
| F1 | Blocker | The producer and materializer have incompatible ownership models. | Multi-isolation cells correctly normalize to `sourceSheet=-1`, but [`build_authoritative_phase_front_mesh()` rejects them](https://github.com/akashskypatel/Directional/blob/3ca89ab55efff461b050fb12033174be70e7464f/src/pipeline/RemeshPipeline.cpp#L1880-L1886). It keys vertices by `(component, sheet, u, v)`, accepts duplicates using a world-position tolerance, supports only `r=0,t=(+U,0)`, and requires a full rectangular sheet grid. The producer's first-class topology-region, Z4/Z2 holonomy, polygonal, multi-relation, and multi-isolation contracts are therefore not consumable in general. |
| F2 | Blocker | A global lattice coordinate is not sufficient vertex identity. | QEx explicitly distinguishes q-vertices from integer grid points because charts may overlap. The current [`SheetLatticeKey`](https://github.com/akashskypatel/Directional/blob/3ca89ab55efff461b050fb12033174be70e7464f/src/pipeline/RemeshPipeline.cpp#L1790-L1801) can merge unrelated chart occurrences and uses Euclidean agreement as the final acceptance test. Correct identity must be the equivalence class of cell-corner occurrences induced by reciprocal front ownership, explicit periodic transforms, and exact rail pairing—not coordinate or position coincidence. |
| F3 | High | The phase-front does not expose enough exact connectivity for sound extraction. | `SurfaceFrontEdge` records `filledCell` but not the owning cell side, periodic-relation identity, or an explicit boundary/rail kind. The materializer can validate reciprocal edge indices but cannot reconstruct which cell corners a pair identifies without inference. This also leaves cross-region hard rails at risk of becoming output boundaries even though cells must stop at the rail while the final mesh remains conforming across it. |
| F4 | High | Direct phase-front completion fabricates topology metadata. | The direct path sets [`connectedComponents = 1` and `eulerCharacteristic = 1`](https://github.com/akashskypatel/Directional/blob/3ca89ab55efff461b050fb12033174be70e7464f/src/pipeline/RemeshPipeline.cpp#L5584-L5595) instead of deriving them from incidence. A closed torus must be one component, zero boundary loops, and Euler characteristic zero. This violates the explicit no-synthetic-topology rule even if later validators recompute some facts. |
| F5 | High | Embedded relief is modeled at the wrong layer, and non-embedded relief can still block vertex-fan continuation. | [`build_source_topology_regions()` splits on embedded relief](https://github.com/akashskypatel/Directional/blob/3ca89ab55efff461b050fb12033174be70e7464f/src/geometry/SurfaceCellTracing.cpp#L2339-L2345), allowing all resulting subregions to return `NotApplicable` and generic tracing to run. Separately, [`resolve_vertex_continuation()` checks `reliefBarrierEdges` without the embedded flag](https://github.com/akashskypatel/Directional/blob/3ca89ab55efff461b050fb12033174be70e7464f/src/geometry/SurfaceCellTracing.cpp#L1493-L1503), although the production pipeline sets `reliefBarriersEmbedded=false`. Non-embedded relief is therefore not reliably guidance-only. |
| F6 | High | Failure-path intermediate retention is a documented contract, not merely a test implementation detail. | The public option promises to retain heavyweight trace geometry in `SurfaceCellPipelineContext`, but materialization returns at lines 5035-5045 before the network is moved into retained context at lines 5085-5087. The torus assertion is contractually justified, but its fatal placement masks the topology assertions. Retention needs a focused failure-path test; the torus topology test should assert its semantic diagnostics before any fatal context dereference. |
| F7 | Medium | The accepted close-sheets raw hash encoded serialization order, not product semantics. | Candidate output is deterministic 3/3, strict-valid, source-disconnected into two components, and geometry/topology-equivalent; only component emission order changes. No public contract promises cross-version byte/row ordering. The old raw hash remains useful for same-artifact repeatability but is not a valid semantic acceptance gate. A component-order-independent provenance/topology digest is required before changing any semantic baseline. |
| F8 | Medium | `SurfaceTopologyRegion` is sound, but its boundary definition needs one amendment. | Exact source adjacency is the right continuity authority; local isolation is the right proximity/capture authority; internal isolation seams correctly retain reciprocal transport. Embedded relief should be first-class internal cut/transport authority under the parent topology region, not a source-topology separator. Hard rails split producer domains but require exact counterpart stitching unless they coincide with a genuine source boundary. |

## Unit-Test Review

| Test / scenario | Classification | Evidence | Smallest correction | Verification |
|---|---|---|---|---|
| `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` | valid fixture and contract; weak fatal-assertion ordering | Exact runtime diagnostics already prove four annuli, eight internal seams, no old boundary-turn failure; public retention docs justify retained network expectation | Assert public topology/seam diagnostics first; move retention to a separate focused failure-path test; require direct strict-valid torus success after quotient materialization | Focused producer test plus three independent direct torus processes |
| `UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded` | valid test exposing two production defects | Embedded mode falls through to generic tracing; non-embedded vertex continuation has an unconditional barrier check | Keep fixture and strengthen or add a vertex-fan witness so guidance-only behavior is exercised outside the planar fast path | Retained G0-G3 **17/17** and no generic fallback after embedded ownership begins |
| Close-sheets exact raw hash gate | incorrect expectation / weak semantic oracle | Geometry, topology, source separation, and deterministic behavior are unchanged while only component serialization order changes | Retain raw hash as repeatability evidence; gate cross-version equivalence on a component-order-independent exact provenance/topology digest | Baseline/candidate canonical digest equality plus 3/3 raw repeatability |
| Periodic materializer tests | missing scenario coverage | Producer accepts full Z4/Z2 relations and multiple topology regions; materializer tests cover the legacy positive-U translation case | Add explicit ordinary, periodic, hard-rail, malformed-transform, overlap-without-connectivity, and multi-isolation quotient cases | Focused tests must catch coordinate-only and position-only mergers |

Counterfactual broken implementations the revised tests must catch:

1. Replacing `sourceSheet=-1` with the smallest local sheet while retaining the lattice-key materializer.
2. Merging every equal `(region,u,v)` occurrence even when two charts overlap without reciprocal front connectivity.
3. Pairing a hard rail or periodic cut by position, count, discovery order, or the first relation.
4. Letting all embedded-relief producer domains return `NotApplicable` and launching generic tracing.
5. Emitting a torus with artificial rail boundaries while hard-coding Euler/component metadata.

## Challenge to Existing Diagnosis

The existing diagnosis correctly identifies the first visible torus failure (`sourceSheet=-1`) but proposes `(component, topologyRegion, lattice)` as the likely replacement key. That replacement is still incomplete and can be wrong: equal lattice coordinates do not prove that two chart occurrences are the same output vertex. It also does not solve cross-region rail stitching, full Z4/Z2 relation consumption, non-rectangular coverage, or fabricated output topology.

The smallest complete correction is a transition-aware quotient over explicit cell-corner occurrences. Lattice coordinates remain validation state; reciprocal front/rail/periodic connectivity establishes equivalence. This follows the supplied QEx/MIQ extraction model without importing their global parameterization solver.

The close-sheets difference is not a product regression on the available contract evidence. It is a deficient acceptance oracle. Conversely, `retainIntermediateGeometry` is documented and the missing failure-path retention is a production defect, not an over-coupled test expectation.

## Decision

**Approved with amendments.**

Retain `SurfaceTopologyRegion` and the topology-region/local-isolation split. Replace the pending proposal with one authoritative Code + Build plan that:

- treats embedded relief as internal authoritative cut/transport state under a parent topology region;
- fixes every relief check to honor the embedded flag and preserves terminal `Rejected` behavior once authority is claimed;
- exposes exact side, boundary/rail, and periodic relation ownership on front edges;
- materializes a quotient of explicit cell-corner occurrences from reciprocal connectivity, never a global lattice/position key;
- retains scalar `SurfacePoint` as one exact projection chart while adding the full chart/isolation/topology-region set to lineage;
- stitches hard rails exactly while leaving genuine source boundaries exterior;
- derives component, boundary-loop, and Euler facts from output incidence;
- honors failure-path intermediate retention;
- replaces the close-sheets cross-version raw-hash oracle with a canonical semantic digest while retaining raw repeatability checks.

## Authoritative Next Code + Build Plan

Execute only `.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Code_Build_Plan.md`.

## Superseded Plan

The prior topology-region materialization/regression proposal is **superseded and removed by this review transition**. It correctly preserved topology-region tracing but was replaced because `(component, topologyRegion,lattice)` is not sufficient vertex identity, it did not require exact cross-region rail stitching or computed output topology, it misclassified the close-sheets raw hash as product authority, and it treated failure-path retention as optional.

The completed mandatory review plan is also removed after this report and successor plan become live; Git history and PR #8 retain the audit trail.

## Risks and Merge Implications

- PR #8 remains open, draft, unmerged. This review does not authorize merge.
- G4 remains active. The current artifact remains runtime evidence, not an accepted production closure.
- The successor is a bounded contract migration, but it touches the producer/materializer seam and lineage. Compile success alone cannot accept it; the following artifact-only Test + Benchmark is mandatory.
- Sphere, G5/G6, historical completion/simplification failures, validator thresholds, fallback/recovery, and unrelated optimization remain deferred.

## Integrity Confirmation

- Production code changed: no
- Test or benchmark logic changed: no
- Build configuration changed: no
- Tests or benchmarks executed: no

Static source inspection, checksum verification, PDF extraction/rendering, and artifact/log inspection were performed. No packaged executable or generated project runtime was executed.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `3ca89ab55efff461b050fb12033174be70e7464f`
- Handoff commit: `HANDOFF_COMMIT_RECORDED_BY_REVIEW_TRANSITION`
- Updated or verified unchanged: `TODO`, `MILESTONE_G_TODO.md`, `DESIGN.md`, runtime summary, workflow hygiene, PR #8 draft/open/unmerged state
- Review-approved plan reference: `.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Code_Build_Plan.md`
- Agent entry-point links verified: yes
- New review lesson recorded: lattice values validate transitions; explicit reciprocal connectivity owns output vertex equivalence

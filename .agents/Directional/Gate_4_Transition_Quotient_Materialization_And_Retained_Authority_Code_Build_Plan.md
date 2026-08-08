# Gate 4 Transition-Quotient Materialization and Retained Authority — Code + Build Plan

Status: **authoritative next turn**
Turn type: **Code + Build only**
Active design gate: **G4 topology-distinct completion and singularities**
Controlling review: `.agents/Directional/Gate_4_Topology_Region_Independent_Design_Review_Report.md`

## Design declaration

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing retained contract: embedded relief can lose terminal authority and non-embedded relief can block a vertex-fan continuation; retainIntermediateGeometry also loses the trace network on pre-retention materialization failure
Earliest active G4 fixture blocker: exact torus produces four annular topology regions and four periodic relations, then the single-sheet rectangular lattice materializer rejects the first multi-isolation cell
Missing design contract: output vertex/edge identity is not the lattice coordinate; it is the exact equivalence relation induced over cell-corner occurrences by reciprocal front ownership, source rails, and explicit periodic transforms
Smallest general implementation change: retain topology regions, expose exact side/rail/relation ownership, build a transition-aware corner quotient with full chart lineage, compute output topology from incidence, and restore retained relief/diagnostic authority
Observable material-progress condition: the compile-only artifact packages the complete quotient contract; the following artifact-only turn restores all retained contracts and produces a connected, closed, Euler-zero, strict-valid direct torus with every region/relation consumed and no fallback/recovery
Explicitly deferred: prescribed sphere until torus closes, G5/G6, historical completion/simplification failures, validator-threshold changes, fallback/recovery, source-grid recovery, global parameterization, adaptive templates, and unrelated optimization
```

## 1. Preserve the topology-region layer; move embedded relief beneath it

`SurfaceTopologyRegion` remains the parent exact-source-adjacency authority.

- Split parent regions only at different source components, genuine source boundaries, and hard feature rails.
- Do not split parent topology regions at embedded relief edges.
- Retain embedded relief as sorted first-class internal barrier/cut topology on the parent region (or on a named `ProducerDomain` child when a local producer needs cut domains).
- Non-embedded relief is guidance everywhere. Audit every `reliefBarrierEdges` read, including vertex-fan continuation, and require `reliefBarriersEmbedded` before it blocks transport.
- Once an embedded barrier is consumed or encountered by an applicable producer, unsupported coverage is typed `Rejected`. All-`NotApplicable` child domains may not return the parent to generic tracing.
- Do not manufacture topology boundaries, exterior loops, or Euler changes from an embedded rail.

Focused compile-only tests must cover:

- non-embedded relief through an ordered source-vertex fan;
- embedded relief blocking that same route;
- all child domains unsupported after embedded ownership begins yields terminal `Rejected` and zero generic seeds/traces/proposals;
- topology-region Euler/boundary facts do not change merely because relief becomes embedded.

## 2. Make phase-front connectivity sufficient for extraction

Add only the smallest first-class fields needed to remove materializer inference:

- owning cell side (`filledSide`) on every `SurfaceFrontEdge`;
- explicit boundary authority distinguishing ordinary interior, genuine source boundary, hard rail, embedded rail/cut, and periodic artificial cut;
- exact ordered source route/topology for a rail side when not already recoverable without ambiguity;
- explicit stable periodic-relation ownership on periodic pairs—never “first relation for this sheet/region”;
- reciprocal cross-region hard-rail pairing after local region aggregation, validated through exact source support and field/phase transport.

Every emitted cell side must have exactly one owning front-edge record. Every non-exterior pair must be reciprocal and identify the two directed cell sides. Genuine source boundaries alone remain exterior. Hard rails stop cell traversal but pair the output edge across producer regions; ambiguity or missing counterpart is typed `Rejected`.

Do not infer an owning side by vector order, coordinate coincidence, position, nearest edge, relation count, discovery order, or raw ID preference.

## 3. Replace sheet-lattice materialization with a corner-occurrence quotient

Rework `build_authoritative_phase_front_mesh()` as a topology-first extractor:

1. Create four provisional occurrences `(cell id, corner)` per authoritative cell.
2. Validate each occurrence's component, topology region, actual local isolation sheet from its exact source face, lattice state, source chart, and source support.
3. Union occurrences only through:
   - the two endpoints of an ordinary reciprocal front-edge pair;
   - an exact reciprocal hard-rail pair;
   - a periodic pair whose explicitly owned relation maps endpoint lattice/branch state by the full `R^r p + t`, with `r in Z4` and `t in Z2`.
4. Do not union equal lattice coordinates in the absence of one of those relations. Do not use world-space distance to create equivalence.
5. Require each equivalence class to be intrinsically compatible through `SurfacePointSourceSupportResolver` / source transition authority. Position may be a post-authority consistency diagnostic, never a merge predicate.
6. Emit one output vertex per equivalence class and one output quad per accepted cell. Reject repeated corners, duplicate cells, nonmanifold edge incidence, contradictory pairing, unconsumed relation authority, or incomplete region coverage.
7. Derive exterior halfedges and ordered boundary loops from unpaired genuine source-boundary sides. The torus must have none.

Remove the assumptions that a cell has one representative `sourceSheet`, that each sheet is a full origin-based rectangle, that periodicity is positive U translation only, or that `maxU*maxV` proves coverage.

All retained periodic relations must be referenced and consumed by at least one exact periodic pair. A relation shape that cannot be consumed must cause producer/materializer `Rejected`; it may not coexist with `Produced` authority.

## 4. Preserve exact provenance without overloading `SurfacePoint`

Keep `SurfacePoint` as one exact source-face projection chart with scalar component/local sheet. Do not turn it into a multi-sheet aggregate.

Augment phase-front output lineage with:

- parent source topology-region identity;
- sorted unique `SurfaceCellSourceChart` records for all equivalent occurrences;
- sorted local isolation-sheet set;
- canonical intrinsic source-support identity;
- periodic/rail equivalence provenance where applicable.

Use one deterministic exact chart as `sourcePoint` only after the full equivalence class is validated; retain every other chart in lineage. Never choose provenance by minimum ID, frequency, position, or discovery order. Reuse existing `SurfaceCellSourceChart`, ownership, and source-support concepts rather than creating a parallel ambiguous identity system.

Update compiled API tests for the added lineage/front fields and hash/diagnostic consumption.

## 5. Compute direct-output topology; never synthesize it

After quotient assembly, compute from exact quad incidence:

- connected component count;
- unique edge count and Euler characteristic `V-E+F`;
- boundary halfedges and manifold boundary loops;
- vertex-fan manifoldness.

Populate `PureQuadAssemblyResult` from those facts. Remove hard-coded `connectedComponents=1` and `eulerCharacteristic=1`. Reject inconsistency between front boundary authority and assembled incidence.

Expected topology is fixture-independent production logic. The following Test + Benchmark may assert exact torus facts (one connected component, no boundary loops, Euler zero) because those are independently derived from its source topology; production code may not key behavior on the fixture.

## 6. Honor intermediate-retention and improve torus test separation

Refactor trace-network ownership so `retainIntermediateGeometry=true` retains the completed trace/phase-front network before any materialization return, without making a second heavyweight copy.

- Failure after tracing must leave `hasTraceNetwork=true` and the exact typed phase-front state available.
- `retainIntermediateGeometry=false` must preserve current release behavior and scalar diagnostics.
- Add a focused deterministic materialization-failure test for the public retention option.
- In the torus topology regression, assert public topology-region/isolation-seam diagnostics and absence of the former failures before any fatal context dereference.
- Once the quotient implementation is present, the torus integration test must require direct success; do not preserve a permissive “Rejected is acceptable” branch.

This is assertion separation, not weakening.

## 7. Replace the close-sheets semantic oracle; preserve repeatability

Do not restore the old raw hash by raw source-ID ordering. Do not accept the candidate merely by changing a golden hash.

Add a canonical output semantic digest that:

- builds exact per-output-component records from connectivity plus source-authoritative vertex/face lineage;
- canonicalizes cyclic quad identity and sorts vertices/faces/components;
- is invariant to output row order and connected-component emission order;
- does not merge geometry or establish ownership by tolerance;
- remains sensitive to changed connectivity, source support, component separation, winding, or provenance.

Keep the existing raw serialization hash as a same-artifact determinism signal. Add a focused test that swaps component/row emission order: raw hashes may differ; semantic digests must match. A real source-ownership or connectivity mutation must change the semantic digest.

Following runtime acceptance compares the canonical digest from accepted artifact `9021175280` with the candidate. Until that digest exists, neither raw close-sheets hash is a cross-version semantic baseline.

## 8. Test sources to add or strengthen (compile only this turn)

At minimum cover these counterfactuals:

- multi-isolation cell succeeds without selecting one representative sheet;
- two overlapping chart occurrences with equal `(region,u,v)` but no reciprocal connection remain different vertices;
- ordinary reciprocal pair unions endpoints with correct orientation;
- periodic pair consumes a named Z4/Z2 relation and rejects the wrong transform;
- multiple relations are consumed by explicit ownership, not order/count;
- hard-rail counterparts stitch exactly while a genuine source boundary remains exterior;
- missing/ambiguous rail counterpart rejects;
- scalar `SurfacePoint` plus multi-chart lineage is complete and deterministic;
- assembled topology detects nonmanifold edge/fan, artificial boundary, wrong Euler, and repeated cell corner;
- failure-path retention obeys the public option;
- relief guidance/embedded semantics and close-sheets semantic digest behave as specified;
- plane, seam, close-sheets, cylinder, and exact torus paths compile with no fixture-specific production branch.

No validator expectation, tolerance, or source fixture may be weakened to make these compile.

## 9. Code + Build scope boundary

Allowed source scope is limited to the phase-front/topology-region representation and producer aggregation, direct phase-front materialization/topology derivation, exact lineage/diagnostics/hash plumbing, and focused tests/API checks required by this plan. Prefer existing files and types. Do not change unrelated completion/simplification behavior.

Explicitly prohibited:

- executing any generated Directional binary, GoogleTest executable, benchmark, `ctest`, discovery, CLI/GUI, help/list, or custom-input command;
- fallback or source-grid recovery;
- positional/nearest/proximity welding;
- `(component,region,lattice)` as unconditional vertex identity;
- selecting a sheet/relation/owner by ID, order, count, or frequency;
- hard-feature demotion;
- arbitrary subset search;
- post-hoc cell merging or synthetic topology correction;
- validator/tolerance weakening;
- fixture-specific branches;
- sphere/G5/G6 or historical completion/simplification repair.

## 10. Approved build-only boundary

Configure Release/static/Ninja with GoogleTest discovery `PRE_TEST`. Compile/link exactly these seven established targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_benchmarks`
4. `directional_compiled_api_tests`
5. `directional_surface_cell_producer_tests`
6. `directional_surface_cell_completion_tests`
7. `directional_surface_cell_validation_tests`

Do not add a workflow merely to execute runtime. Package exact source, final blobs, logs, toolchain/submodule metadata, fixtures, manifest, and checksums with `runtimeExecution=false`. Record implementation and cleanup commits. Remove the bounded workflow/trigger/payload only after artifact/source authority is verified.

## 11. Mandatory following artifact-only Test + Benchmark acceptance

The next Test + Benchmark must execute only the immutable artifact produced by this plan and require all of the following:

### Retained authority

- topology-region / isolation-seam semantics **9/9** retained;
- polygonal boundary phase **5/5** retained;
- non-torus curved-disk and sheet-coverage contracts retained;
- retained G0-G3 restored to **17/17**, including embedded relief terminal behavior and non-embedded vertex-fan guidance;
- G4 periodic relation tests **5/5** retained plus the new explicit relation-consumption cases;
- validation **60/60** and API **8/8** retained; historical unrelated failures neither repaired nor increased.

### Direct fixtures

- plane, seam, and cylinder preserve their accepted raw hashes (`730caeae49ec872c`, `5bdf34d7802e9fb0`, `32135be51d7a0a26`) and are deterministic **3/3**;
- close sheets remains 200 quads / 242 vertices / exactly two source-disconnected components, raw hash repeatable **3/3**, and canonical semantic digest equal to the accepted artifact's digest regardless of component emission order;
- cylinder retains one consumed `r=0,t=(32,0)` relation, route 32, cut 4, and exactly two genuine source-boundary loops;
- exact torus runs in at least three independent processes and succeeds directly with strict validation, pure quads only, one connected component, zero boundary loops, Euler characteristic zero, complete provenance, four topology regions, eight internal isolation seams, and every one of the four periodic relations consumed;
- no direct case uses fallback or source-grid recovery.

Do not predict or golden-file torus quad/vertex counts. If torus fails, report the first truthful invariant and exact retained structural state; do not continue to sphere.

### Determinism and retention

- raw and semantic hashes are repeatable in three independent processes;
- focused row/component permutation proves semantic-digest invariance;
- focused provenance/connectivity mutation proves semantic-digest sensitivity;
- focused pre-retention materialization failure preserves trace-network context exactly when requested and does not retain it when disabled.

## 12. Exit and handoff

The Code + Build turn ends after compile/package/source verification, documentation transition, workflow cleanup, and a new top-level PR #8 comment as the final repository write. PR #8 remains open, draft, unmerged. The next turn is artifact-only Test + Benchmark; no runtime claim may be made during Code + Build.

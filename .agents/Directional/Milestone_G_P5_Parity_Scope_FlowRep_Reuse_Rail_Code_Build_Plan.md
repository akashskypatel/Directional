# Milestone G P5 — Parity Scope, FlowRep Safety, Reuse, and Rail Code + Build Plan

**Turn:** P5-CB83 through P5-CB90 code changes + compile-only build  
**Input artifact:** P5-TB15 artifact `8866222973`  
**Exact tested source:** `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`  
**Review policy:** `never`

## Objective

Close the remaining direct `SurfaceCells` producer defects without weakening validation or adding fallback behavior:

- prevent generated-smooth-field signal 11 in the FlowRep strands stage;
- make boundary parity subdivision preserve one exact source scope per cell and oriented replacement edge;
- produce positive exact reuse for unaffected completed patches;
- preserve authoritative rail identity to final arrangement halfedges;
- correct invalid regression fixtures;
- advance plane, cylinder, seam, torus, and mechanical-feature production completion;
- retain bounded memory and compile/package only.

## Prohibitions

Do not introduce:

- final-face deduplication;
- positional vertex merge;
- source-triangle pairing;
- source-grid recovery or legacy fallback;
- validator weakening;
- arbitrary subset search;
- hard-coded production IDs;
- a timeout as a correctness mechanism;
- a test expectation change that hides a real producer defect.

## P5-CB83 — Eliminate high-cardinality FlowRep strands signal 11

The exact production case reaches a deterministic `80,862`-segment trace network and crashes between the tracing stage-3 marker and strands stage-4 marker. The same mesh with `face_edges` returns normally; debug retention is not causal.

Required work:

1. Add stage-internal ownership and progress diagnostics around:
   - `build_flow_rep_selection_input`;
   - sparse candidate graph construction;
   - component/cycle evidence formation;
   - `select_sparse_flow_rep_network`;
   - endpoint completion;
   - move/clear handoff into embedding.
2. Replace references, pointers, iterators, and spans that can survive vector/map growth or move operations with stable indices or immutable snapshots.
3. Audit recursion and DFS/BFS stack usage on the 80,862-segment graph; use explicit bounded work queues where graph depth can scale with input size.
4. Make every high-cardinality temporary single-owner and release superseded buffers only after no live reference remains.
5. Fail closed with a typed FlowRep code on malformed graph state; never crash or return partial output.
6. Add a focused high-cardinality synthetic graph regression that exercises the same ownership pattern without depending on a production ID.

Acceptance source assertions:

- stage-3 output can be consumed repeatedly by strands without stale references;
- both `retainIntermediateGeometry=true` and `false` use valid ownership paths;
- no recursive depth proportional to total trace-segment count;
- no mutable container element address is retained across insertions or moves.

## P5-CB84 — Replace dominant-frequency parity scope with authoritative cell scope

Current parity subdivision counts provenance scopes, selects the most frequent `(component, sheet)`, and rejects edges that cannot supply it. This detects the problem but does not construct correct source ownership.

Required work:

1. Derive the cell's authoritative source scope before mutation from:
   - the cell's canonical source-domain identity;
   - every oriented boundary halfedge's selected provenance;
   - the pre-transaction cell component/sheet contract.
2. Reject a mixed pre-transaction cell before parity mutation with a typed producer failure identifying cell, halfedge, available scopes, and missing scope.
3. For a valid cell, require every replacement piece and inserted occurrence to inherit the exact pre-transaction scope.
4. Build forward and reverse twin provenance independently while preserving source face, interval direction, rail/curve interval, family, strand, proposal, and hard-feature state.
5. Remove frequency voting from authoritative scope selection.
6. Prove rollback exactness for every scope-related rejection.
7. Add regressions for:
   - one cell with multiple geometric charts but one exact local sheet;
   - twins on different local sheets;
   - a truly mixed input cell that fails before mutation;
   - parity repair that reaches zero odd cells and commits with exact scope.

## P5-CB85 — Define authoritative completion dependency identity

The two reuse regressions still report zero reused completions. The existing dependency key includes regenerated representation details such as bit-exact world positions, squared distances, and ordered source-face vectors.

Required work:

1. Add field-level mismatch diagnostics for every exact equality field and semantic-hash bucket miss.
2. Separate authoritative dependencies from derived/cache-local representation:
   - include canonical oriented source-domain identity;
   - include ordered boundary source coordinates in canonical face/barycentric form;
   - include component/sheet, side subdivision signature, rail/curve support, feature constraints, singularity requirements, and completion variant;
   - exclude allocation IDs, world positions derivable from source coordinates, squared-distance cache values, incidental source-face ordering, and rebuilt local container order.
3. Canonicalize cyclic/reversed boundary representation before hashing and equality.
4. Retain multiple products per semantic bucket and consume each exact product once.
5. Classify patches as affected or unaffected from the structural repair dependency frontier, not cell IDs.
6. Require positive reuse and one recomputation in both targeted route-repair regressions.

## P5-CB86 — Complete authoritative rail/provenance propagation

Required work:

1. Trace a rail record from authoritative feature rail through:
   - trace segment;
   - FlowRep arc;
   - arrangement arc;
   - node occurrence;
   - split halfedge and twin;
   - stitched final halfedge;
   - descriptor side and final lineage.
2. Preserve full provenance vectors through split and stitch; select the primary record deterministically without discarding alternatives.
3. Reverse source and rail intervals exactly on twin orientation.
4. Never infer rail identity from position or nearest source edge.
5. Add a focused split-across-two-source-triangles regression that asserts final halfedge rail ID, curve ID, interval orientation, component, sheet, classification, and complete provenance.

## P5-CB87 — Correct invalid rollback and cylinder fixtures

### Invalid midpoint fixture

`FailedSubdivisionReturnsBitExactCommittedComplex` currently removes common chart support, so `MissingCommonSourceChart` is correct.

- Keep a separate test for missing common chart.
- Rebuild the invalid-midpoint test so both endpoints declare one compatible common face/component/sheet but contain malformed barycentric data that makes interpolation invalid after an earlier tentative insertion.
- Continue to require bit-exact rollback and original node/halfedge/cell counts.

### Cylinder simplification fixture

The current fixture duplicates coincident source-edge arcs independently in every incident triangle and is topology-invalid before simplification.

- Rebuild it from nonoverlapping cross-face strand segments that meet canonically at shared source edges, or from one canonical source-edge entity carrying all incident provenance.
- Assert twin symmetry, incidence, embedding, orientation, disk cells, Euler characteristic `0`, one component, and two boundary loops before extracting candidates.
- Only then test the intended open-strip commit.

Do not weaken topology preconditions to make either test pass.

## P5-CB88 — Repair production output contracts

After CB83–CB87, re-evaluate the source implementation paths responsible for:

- plane and multi-face seam validation failures;
- cylinder sheet/geometry/orientation/manifold failures;
- torus and mechanical-feature completion failures;
- Phase 20 cylinder failure.

Required work:

1. Classify each failure by earliest invalid producer stage.
2. Preserve topology, source sheet, orientation, and manifold invariants before optimization.
3. Do not rely on the optimizer to repair invalid connectivity.
4. Ensure completion emits only nondegenerate pure quads with valid source lineage.
5. Keep validation strict and report each remaining failure category explicitly.

## P5-CB89 — Complete memory ownership telemetry

The face-edge path peaks near 137 MB while completion-owned telemetry reports only 2.2 KB. Add stage-owned accounting for:

- trace network and proposal payloads;
- FlowRep input, arcs, sparse graph, endpoint state, and queues;
- arrangement arcs and DCEL payloads;
- simplification candidates, queues, transactions, and output complex;
- completion descriptors, products, rollback undo, assembly, and deferred output.

Requirements:

- report current and peak owned bytes per stage;
- report maximum simultaneous live complexes and large graphs;
- distinguish logical payload from allocator capacity estimates;
- avoid double counting moved buffers;
- preserve the one-committed-complex/one-mutable-transaction discipline;
- make the smooth-field strands failure path measurable before and after the fix.

## P5-CB90 — Regression sources and compile/package gate

Add or correct tests for every implemented contract, but execute none in this turn.

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Package:

- exact source commit and empty status;
- binaries and static libraries;
- complete executable-relative fixtures;
- source archive and recursive submodule status;
- configure/build logs;
- checksum manifest.

The workflow must execute no test, benchmark, custom mesh, compiled binary, help/list command, or discovery command.

## Next test-turn gates

The subsequent P5-TB16 artifact-only turn must require:

1. all current 10 assertion failures pass;
2. all three signal-11 tests terminate normally alone and in the full suite;
3. exact generated-smooth-field benchmark processes return normally;
4. four face-edge and four smooth-field bunny processes are structurally deterministic;
5. both field paths produce nonempty valid pure-quad output without fallback or recovery;
6. positive exact completion reuse is observed;
7. final halfedges retain authoritative rail identity;
8. wall `<= 39.228299 s` and peak memory `<= 1,115,394,560 B` on every process;
9. stage-owned memory telemetry reconciles the dominant RSS contributors;
10. P5 remains open unless every correctness, liveness, output, timing, and memory gate passes.

PR #8 must remain open, draft, and unmerged throughout this code/build turn.

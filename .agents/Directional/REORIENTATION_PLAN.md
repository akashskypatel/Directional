# Implementation review

## Verdict

**The implementation is pointed toward the intended architecture, but the current P5 effort has drifted into downstream repair, ownership diagnostics, and bounded failure handling before the core constructive producers are strong enough.**

A rewrite is not justified. The existing provenance, validation, pipeline staging, and deterministic diagnostics are valuable. The implementation should be **reoriented around producer correctness**:

1. Construct correct source-chart-aware directed incidence.
2. Generate topology-distinct patch completions.
3. Make phase, collision, and adaptive transitions explicit.
4. Only then resume cache, memory, and diagnostic hardening.

The decisive evidence is that the full suite now terminates, but only **585/600 tests pass and direct production remains 0/8**. Plane, seam, and close-sheet fixtures generate partial quad output and then fail with `LocalSheetMismatch`; the cylinder remains non-disk; several completion cases end in bow-tie or degenerate geometry; repeated-node alternatives deterministically exhaust without committing a valid result.

This review is based on the current branch, PR #8, the current project records, the core tracing/arrangement/completion interfaces, and the P5-TB22 evidence. I did not execute the binaries.

---

# 1. What is headed in the right direction

## 1.1 The overall pipeline matches the intended concept

The remediation architecture correctly models a typed dataflow through:

* Cross-field data.
* Feature and boundary rails.
* Adaptive metric.
* Relief guidance.
* Intrinsic tracing.
* FlowRep network selection.
* Global surface arrangement.
* Complex simplification.
* Patch completion.
* Optimization.
* Source-authoritative validation.

It also correctly prohibits source-triangle pairing or input-mesh return from masquerading as successful `SurfaceCells` output.

That is consistent with the central research concept: construct a conforming cell complex directly on the source surface and replace global MIQ coordinate integration with local construction plus explicit topology reconciliation. 

## 1.2 Source provenance is treated as authoritative

The reviewed data contracts retain:

* Source face and barycentric coordinates.
* Component and local-sheet labels.
* Per-node source-chart occurrences.
* Per-halfedge provenance.
* Patch domain identity.
* Boundary-node identity.
* Generated-vertex lineage.
* Separate stitch and authoritative identities.

`SurfaceArrangementCell` also records source charts, source faces, side families, subdivision counts, disk state, Euler characteristic, and ownership class.

This is the right foundation for close-sheet safety and deterministic stitching. It avoids treating world-space proximity as topological identity.

## 1.3 Cross-field tracing is substantially more rigorous than the original prototype

The tracing layer now includes:

* Matching-aware state.
* Source face and entry edge.
* Field family and sign.
* Quantized intrinsic position.
* Singularity separatrices.
* Four-corner closed-cell proposals.
* Four ordered boundary paths.
* Explicit failure classifications.
* Hard rails and source-sheet constraints.

That aligns with the directional-field literature’s separation of representation, transport, matching, and topology. 

## 1.4 FlowRep is being used in a conceptually appropriate way

The implementation carries:

* Intrinsic endpoint identities.
* Mandatory feature and boundary rails.
* Flowline strands.
* Coverage samples.
* Cycle evidence.
* Patch feasibility evaluation.
* Transactional sparse selection.

This matches the useful part of FlowRep: build a dense curve network, identify coherent strands and cycles, then simplify while preserving descriptive coverage. 

## 1.5 Validation and failure semantics are strong

The backend is fail-closed, keeps the legacy integration backend out of failed direct `SurfaceCells` requests, and records the actual terminal stage. The current project also explicitly prohibits validator weakening, positional merging, fixture-specific conditions, arbitrary subset searches, and synthetic counters.

QEx demonstrates why this level of extraction and connectivity rigor is necessary: materializing a quad mesh is not a trivial post-process, even when the preceding representation appears valid. 

---

# 2. Critical conceptual gaps

## Critical 1 — Patch completion does not yet generate genuinely different topology

The strongest immediate problem is completion.

The completion layer has good supporting structures:

* Side subdivisions.
* Singularity metadata.
* Domain ownership.
* Multiple backend types.
* Embedding checks.
* Pole and loop rewrite types.
* Source-supported generated vertices.

However, the current runtime evidence and implementation plan explicitly acknowledge that the active variants are mostly rotations and reversals of the same connectivity. They terminate at variants 47, 51, and 43 with the same classes of degenerate or bow-tie embeddings.

Rotating an invalid topology does not create a topology-distinct candidate.

This conflicts with the patch-layout part of the overall concept. QuadWild permits flexible nonrectangular patches only because it subsequently solves a globally consistent pure-quad tessellation problem with additional irregular vertices where required. 

### Required correction

Completion candidates must vary in:

* Strip connectivity.
* Diagonal or separator graph.
* Interior pole placement.
* Number and pairing of interior singularities.
* Generated source-supported positions.
* Boundary-to-interior routing.

They must not vary only in starting corner or orientation.

---

## Critical 2 — Directed incidence is being repaired after construction rather than built correctly

The cylinder remains:

```text
non-disk-cell cell=0 halfedge=43 twin=42 next=29
```

The branch currently attempts to repair pinched successor walks by detecting repeated nodes and splitting the resulting closed walk into smaller cycles. The project’s own handoff concludes that this occurrence-splitting heuristic does not repair periodic incidence.

This is the wrong abstraction layer.

A DCEL cell should be produced from:

* Correctly partitioned local wedges.
* Directed halfedge incidence.
* Twin-side ownership.
* Source-chart transitions.
* Boundary/exterior classification.

Only after those are correct should cell IDs be assigned.

Post-hoc splitting of an invalid successor walk cannot reliably infer which local sectors were intended to be connected.

---

## Critical 3 — Grid phase is not a first-class construction value

The conceptual design requires more than cross directions. A cross field provides orientation, but not grid phase or connectivity. MIQ addresses this globally through integer parameterization; the surface-paving proposal was intended to address it locally through lattice phase and explicit collision reconciliation. MIQ’s own formulation emphasizes that global structure and singularity placement have long-range consequences. 

In the reviewed public tracing contracts, I found first-class values for:

* Field family.
* Direction sign.
* Matching.
* Target size.
* Capture.
* Source sheet.
* Trace state.

I did **not** find first-class values for:

* Local two-dimensional lattice phase.
* Integer lattice offset across an adjacency.
* Phase holonomy around a cycle.
* Front edge ownership.
* Phase-compatible versus phase-incompatible collision.
* Dyadic scale level.

As a result, incompatible local grid choices appear later as:

* Duplicate completed faces.
* Same-corner/distinct-boundary ownership.
* Repeated-node cycles.
* Closure parity mutations.
* Stitch equivalence disputes.

Those are not merely ownership problems. Some are symptoms of missing phase decisions upstream.

---

## Critical 4 — The implementation is not yet an advancing-front surface paving system

The current tracing layer creates seeds, traces, separatrices, and closed proposals. That is useful, but it is not yet the complete event-driven surface front described in the design.

A true front needs explicit objects such as:

```cpp
struct SurfaceFrontEdge {
    int from;
    int to;

    int fieldFamily;
    int advanceSign;

    Vec2 latticePhase;
    int scaleLevel;

    SourceRouteIdentity route;
    int unfilledSide;
};
```

It also needs typed events:

```text
CompatibleFrontMerge
PhaseMismatch
TwoToOneScaleTransition
SingularityTermination
HardRailCapture
BoundedClosurePatch
```

Without these, the arrangement receives an overlaid network and must infer connectivity after the fact.

The current method can still become a valid surface-paving implementation, but the front/phase layer must become explicit before the backend can claim to realize the full concept.

---

## High — Source-chart equivalence is still incomplete

The current simple production failures are especially revealing:

* Plane: 12 quads, then `LocalSheetMismatch`.
* Multi-face seam: 24 quads, then `LocalSheetMismatch`.
* Close sheets: 34 quads, then `LocalSheetMismatch`.

The current resolver intersects literal source-face support. That is insufficient because one intrinsic source vertex or source edge can be represented in different adjacent triangle charts.

The current P5-CB147 proposal is the correct remedy: an orientation-aware source-entity transition graph, rather than source-face intersection or world-space matching.

This task should be moved to the front of the critical path.

---

## High — Recovery remains too close to the authoritative backend

`SurfaceCellOptions` currently exposes `allowSourceGridRecovery`, with a default of `true`. The recovery identifies source triangle pairs and subdivides them into four new quads. Although it produces new geometry and the current direct benchmarks disable recovery, it remains conceptually distinct from the intended surface-paving algorithm.

This creates two risks:

1. A nominal `SurfaceCells` success may be produced by recovery rather than the intended trace/arrangement/completion path.
2. Recovery success can conceal regressions in the primary direct producer.

### Required correction

Use one of these policies:

* Default `allowSourceGridRecovery=false`; or
* Expose it as a distinct `SurfaceCellRecovery` backend/output origin.

It must not count toward direct surface-paving production acceptance.

---

## High — Too much effort is allocated to operational hardening before validity

PR #8 contains 545 commits, 164 changed files, approximately 34,500 additions, and remains draft.

The implementation now has extensive machinery for:

* Ownership conflict inventories.
* Exact rollback serialization.
* Candidate-state hashes.
* Cache mismatch diagnostics.
* Per-category capacity estimates.
* Memory ownership timelines.
* Alternative exhaustion classifications.
* Incremental completion reuse.

These systems are useful eventually. But the direct backend still has no successful production fixture.

The project has reached the point where adding more observability produces diminishing returns. The earliest producer failures are already sufficiently identified.

---

## Medium — General FlowRep simplification is not yet production-authoritative

The simplification API includes redundant strands, open strips, closed loops, parallel merges, pole relocation, and transition removal. However, its own production comment says `topologyHealingOnly` restricts it to optional support bridges until general FlowRep edit operators have independent fidelity gates.

That is a reasonable temporary restriction, but it means the intended dense-to-sparse network simplification is only partially realized.

This should remain deferred until the arrangement and completion producers are valid.

---

## Medium — Numerical identity still relies heavily on quantization and tolerances

The arrangement uses canonical source entities, which is good, but it also retains quantized barycentric or edge parameters and epsilon-based intersection handling.

This is not the current reason for 0/8 production, so it should not block immediate progress. Before default-on, however, the pipeline needs a QEx-style policy:

1. Sanitize canonical source representations.
2. Use filtered predicates.
3. Fall back to exact predicates for topology-changing decisions.
4. Never let an epsilon independently choose connectivity.

---

# 3. Assessment of the current P5-CB143–P5-CB150 plan

The current post-TB22 plan has correctly diagnosed most immediate failures.

### Keep on the critical path

* **CB143:** topology-distinct repeated-node wedge/splice producer.
* **CB144:** periodic cell reconstruction from directed incidence.
* **CB145:** topology-distinct completion candidates.
* **CB147:** source-entity chart-transition graph.
* **CB149:** torus descriptor support or valid decomposition.

### Defer until direct geometry succeeds

* **CB146:** incremental cache reuse.
* **CB148:** later-stage injected lineage fixtures.
* **CB150:** categorized memory coverage.

These are valid tasks, but they do not create a correct quad mesh. They should resume only after the direct producer succeeds on a substantial subset of the analytic matrix.

---

# 4. Reorientation plan

## R0 — Freeze the repair surface

**Goal:** stop expanding diagnostics while preserving the currently useful evidence.

Actions:

1. Preserve the current TB22 checkpoint as the regression baseline.
2. Add no new ownership classifications unless an existing failure cannot be represented.
3. Set direct production tests to:

   * `fallbackPolicy=Fail`
   * source-grid recovery disabled
   * no legacy execution.
4. Change source-grid recovery to default-off or a distinct backend.
5. Limit current work to the earliest invalid producer for each fixture.

**Verify:**

* Existing deterministic failure hashes remain stable.
* Full suite still terminates.
* No recovery output can satisfy direct `SurfaceCells` acceptance.

---

## R1 — Implement a canonical source-entity transition graph

Move current **CB147** to the first implementation task.

```text
BUILD_SOURCE_ENTITY_TRANSITIONS(mesh, labels):
    create one chart node for each
        (component, localSheet, sourceFace)

    for each manifold source edge:
        create orientation-aware transitions between incident face charts
        record corner permutation and barycentric edge mapping

    for each source vertex:
        partition incident charts into connected intrinsic fans
        respect component, sheet, boundary, and hard-rail barriers

    for each connected chart class:
        choose canonical source entity representation
        validate every transition cycle for consistency

    return transition graph
```

All arrangement nodes, completion vertices, and stitched output vertices should resolve through this graph.

**Verify:**

1. Plane completes directly.
2. Multi-face seam completes directly.
3. Close sheets complete without cross-sheet leakage.
4. Disconnected close sheets remain separate.
5. Face-row and orientation permutations produce the same structural hash.
6. No `LocalSheetMismatch` remains on these fixtures.

---

## R2 — Rebuild directed incidence before assigning cells

Combine the conceptual core of **CB143 and CB144**.

```text
BUILD_DIRECTED_CELLS(arcs, transitionGraph):
    construct canonical intrinsic nodes
    construct twin halfedges

    for each node:
        partition outgoing halfedges into source-chart wedges
        split wedges at:
            component boundaries
            sheet boundaries
            hard rails
            source boundary sectors

        sort each wedge intrinsically
        assign successor of each incoming twin
            within the same admissible wedge

    audit:
        every directed halfedge has one predecessor
        every directed halfedge has one successor
        twin relation is symmetric

    enumerate all successor cycles
    require each directed halfedge belongs to exactly one cycle

    classify exterior cycles before assigning bounded cell IDs

    reject repeated-node or repeated-edge cycles
    assign cells only after complete inventory passes
```

Do not repair a bad cycle by splitting repeated occurrences after cell construction. A repeated-node cycle should identify a bad wedge pairing and cause reconstruction at that node.

**Verify:**

* Cylinder cells are simple disks.
* Cylinder seam-start, orientation, and source-row permutations agree.
* Every halfedge is visited exactly once.
* Predecessor multiplicity is exactly one.
* Boundary-loop and Euler invariants match the source.
* No downstream parity operation is needed to repair periodic incidence.

---

## R3 — Replace completion variants with a topology catalog

Implement current **CB145** as a distinct module, not another expansion of `completionVariant`.

Suggested separation:

```text
PatchTopologySolver
PatchTopologyEmbedding
CompletedPatchValidator
CompletedPatchAssembler
```

Core algorithm:

```text
ENUMERATE_PATCH_TOPOLOGIES(descriptor):
    canonicalize logical side cycle
    compute side subdivision equations
    compute required singularity/index budget

    generate finite topology graphs from:
        strip pairings
        admissible internal diagonals
        one-pole patterns
        compatible 3/5-pole pairs
        supported transition templates

    quotient candidates by cyclic and reflection symmetry

    for each topology graph:
        derive generated vertices and arcs
        assign source-supported barycentric positions
        validate:
            disk topology
            boundary preservation
            pure quads
            singularity budget
            no repeated vertices
            no bow-tie
            positive area
            no hard-feature crossing

        emit only genuinely distinct connectivity
```

A topology candidate identity should include:

* Quad adjacency graph.
* Boundary-to-interior incidence.
* Pole valences.
* Strip routing.
* Generated source-support construction.

It must not be identified by only an integer rotation variant.

**Verify:**

* Focused variant 47 succeeds.
* Cylinder variant 51 succeeds.
* Thin-tube variant 43 succeeds.
* Smooth patch 9181 succeeds.
* Candidate topology hashes differ before embedding.
* Reversing or rotating one topology canonicalizes to the same identity instead of consuming another variant.
* No center-fan fallback is used.

The topology references support this direction: edge loops should carry intended flow, while poles redirect or terminate loops and should be intentionally placed rather than emerging from a generic fan.  

---

## R4 — Implement repeated-node wedge/splice alternatives at the producer

Once directed incidence is authoritative, implement the remaining part of **CB143**.

```text
ENUMERATE_REPEATED_NODE_SPLICES(node, failedCycle):
    identify the two visits to node
    identify incoming/outgoing halfedges for each visit
    identify canonical admissible wedges

    enumerate finite cross-wedge continuation pairings
    reject pairings that:
        cross cyclic order
        reuse a directed edge
        cross a hard rail
        mix source-chart classes
        change protected boundary ownership

    rebuild the complete affected cycle inventory
    accept only strict topology-valid progress
```

This is a finite local topology problem. It is not a search over arbitrary interface subsets.

**Verify:**

* At least one sphere reduced case commits.
* At least one mechanical reduced case commits.
* At least one face-edge bunny reduced case commits.
* All-invalid cases terminate with deterministic exhaustion.
* Candidate identity is invariant to insertion and face-row order.

---

## R5 — Add explicit local lattice phase and front state

This is the largest conceptual item missing from the current roadmap.

Introduce:

```cpp
struct SurfaceLatticeState {
    int sourceFace;
    Vec3 barycentric;

    int family;
    int sign;

    Vec2 phase;
    Int2 latticeOffset;
    int scaleLevel;

    int component;
    int sheet;
};
```

And:

```cpp
struct SurfaceFrontEdge {
    int firstNode;
    int secondNode;

    SurfaceLatticeState firstState;
    SurfaceLatticeState secondState;

    int openSide;
    SourceRouteIdentity route;
};
```

Across adjacent faces:

[
\phi_j = R_{k_{ij}}\phi_i + t_{ij},
\qquad
k_{ij}\in\mathbb Z_4,\quad t_{ij}\in\mathbb Z^2.
]

Initially support only:

* Uniform target size.
* Plane.
* Cylinder.
* Torus.
* One scale level.

Record phase holonomy around noncontractible cycles explicitly rather than allowing it to emerge as an ownership conflict.

**Verify:**

* Plane front closes with zero phase residual.
* Cylinder records and reconciles periodic phase.
* Torus reports its two independent cycle holonomies.
* Compatible front collisions merge without later duplicate-face repair.
* Incompatible collisions produce a typed topology event.
* Repeated runs have identical event sequences.

This is the main addition needed to make the implementation fully embody “local surface construction plus explicit topology reconciliation,” rather than merely producing and repairing an embedded curve overlay.

---

## R6 — Add adaptive scale transitions

Only after uniform paving works:

1. Quantize target size to dyadic levels.
2. Enforce adjacent levels differing by at most one.
3. Detect scale mismatch as a front event.
4. Apply a validated 2:1 pure-quad transition template.
5. Preserve singularity-index budget.

**Verify:**

* Thin bent tube retains thin regions.
* No final T-junctions.
* Every scale transition is represented by a named template.
* Reversing the transition direction produces the canonical inverse.
* Uniform regions contain no unnecessary transition poles.

---

## R7 — Resume the production fixture matrix

Suggested gate order:

1. Plane.
2. Multi-face seam.
3. Close sheets.
4. Cylinder.
5. Thin tube.
6. Prescribed sphere.
7. Mechanical fixture.
8. Torus.
9. Bunny face-edge field.
10. Bunny smooth field.

Each gate requires:

* `CompletedSurfaceCells` origin.
* No fallback.
* No recovery.
* Pure quads.
* Manifold incidence.
* Correct boundary loops and Euler characteristic.
* No T-junctions or self-intersections.
* Complete source provenance.
* Hard-rail preservation.
* Deterministic structural hash.

Do not run the entire bunny matrix after every local change. Advance through reduced causal fixtures first, then run the production matrix in a separate test/benchmark turn.

---

## R8 — Resume operational hardening

Only after the analytic direct matrix is substantially green:

1. **CB146:** real completion-cache reuse.
2. **CB148:** later-stage lineage injection fixtures.
3. **CB150:** synchronized memory accounting.
4. General FlowRep simplification.
5. Exact-predicate hardening.
6. Performance work.

Suggested entry gate:

```text
analytic direct production >= 6/8
plane + seam + close sheets + cylinder all valid
at least one repeated-node case valid
at least one topology-distinct completion case valid
```

---

# 5. Revised task ordering

The existing next turn should be reordered from:

```text
CB143, CB144, CB145, CB146, CB147, CB148, CB149, CB150
```

to:

```text
R1  Source-entity chart transitions          [current CB147]
R2  Directed wedge/incidence reconstruction  [current CB144 + part CB143]
R3  Topology-distinct completion engine      [current CB145]
R4  Repeated-node wedge/splice producer      [remaining CB143]
R5  Explicit phase/front state               [new critical concept task]
R6  Torus decomposition/descriptor           [current CB149]
R7  Adaptive 2:1 transitions                 [new critical concept task]
R8  Direct production validation
R9  Cache reuse                              [current CB146]
R10 Stage-lineage fixtures                   [current CB148]
R11 Memory telemetry                         [current CB150]
```

---

# 6. Final disposition

## Continue

Preserve and continue using:

* Typed pipeline context.
* Source provenance.
* Rail authority.
* Matching-aware traces.
* Closed-cell proposals.
* FlowRep evidence.
* DCEL representation.
* Transactional rollback.
* Ownership inventory.
* Strict source-authoritative validator.
* Fail-closed backend semantics.

## Stop expanding for now

Temporarily stop work on:

* More completion rotations or reversals.
* More single-interface exclusions.
* More ownership classifications.
* More cache diagnostics.
* More memory categories.
* More injected later-stage fixtures.
* Performance optimization of failing producers.

## Replace or elevate

* Replace post-hoc repeated-cycle splitting with directed wedge construction.
* Replace rotation-based completion variants with topology-distinct patch graphs.
* Elevate source-entity transitions to a shared core service.
* Add local lattice phase and advancing-front events as first-class concepts.
* Make recovery explicitly non-authoritative and default-off.

**Conclusion:** the implementation has the right skeleton, but the constructive heart is currently underdeveloped relative to the repair infrastructure. The current P5 diagnosis is accurate; the project should now narrow its scope and fix the earliest topology producers before investing further in ownership, reuse, memory, or performance.

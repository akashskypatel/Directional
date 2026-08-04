# Adaptive cross-field-aligned surface-cell quadrangulation

## 1. Consolidated design thesis

The proposed backend should be described as **adaptive cross-field-aligned surface paving**, not surface voxels.

The algorithm should construct a conforming cell complex directly on the source triangulation. Every generated point, curve, cell, and topology edit remains intrinsically attached to a source triangle. The backend may use volumetric structures to estimate thickness, but it must not reconstruct the output by intersecting the source with a volumetric grid. This preserves the central idea in the notes while avoiding the overlap, gap, and manifoldness problems caused by independently stamping oriented squares. 

The core architectural claim should be:

> Replace global mixed-integer coordinate integration with local surface construction plus explicit topology reconciliation.

This is not an integer-free method. The discrete choices move from global parameter coordinates into:

* 4-RoSy branch matching.
* Local lattice offsets and phase.
* Front collision ownership.
* Adaptive-resolution transitions.
* Patch parity and subdivision counts.
* Extraordinary-vertex placement.
* Hole and non-disk closure.

A cross field provides orientation and singularity information, but it does not uniquely determine grid phase or valid quad connectivity. Recent theoretical work explicitly shows that cross-field singularity configurations and realizable quad-mesh singularities are not equivalent. ([ScienceDirect][1])

---

## 2. Required pipeline

```text
Source triangle mesh
  ↓
Input validation and bounded preconditioning
  ↓
Cross-field normalization, matching, and singularity analysis
  ↓
Shared adaptive feature map
  ↓
Curvature-, feature-, variation-, and thickness-aware size field
  ↓
Optional relief and curve-skeleton guidance
  ↓
Locally compatible tangent-lattice phase field
  ↓
Boundary, feature, singularity, and regular front seeds
  ↓
Intrinsic closed-cell tracing and advancing-front construction
  ↓
Collision, phase, scale, and singularity reconciliation
  ↓
Globally stitched surface arrangement
  ↓
FlowRep-style strand and cycle simplification
  ↓
Patch feasibility, subdivision assignment, and pure-quad completion
  ↓
Pole, strip, and loop topology optimization
  ↓
Source-constrained geometric optimization
  ↓
Strict final validation
```

MIQ identifies the fundamental output criteria that remain applicable: element shape, orientation, feature alignment, global singularity structure, and optional semantic constraints. It also demonstrates why global structure cannot be treated as merely a local geometric-quality problem. 

---

# 3. Core data contracts

All intermediate geometry needs authoritative source provenance.

```cpp
struct SurfacePoint {
    int sourceFace;
    Vec3 barycentric;

    int componentId;
    int localSheetId;
};

struct FieldSample {
    Complex q4;             // exp(i * 4 * theta)
    double confidence;
};

struct TangentLatticeSample {
    SurfacePoint point;

    Vec3 normal;
    Vec3 axisU;
    Vec3 axisV;

    Vec2 phase;
    double targetSize;
    int scaleLevel;
    double confidence;
};

struct EmbeddedArc {
    SurfacePoint start;
    SurfacePoint end;

    std::vector<SurfacePoint> polyline;
    int fieldFamily;        // U or V
    int sign;               // + or -
    int strandId;

    bool hardRail;
    Provenance provenance;
};

struct SurfaceCell {
    std::array<int, 4> cornerIds;
    std::array<std::vector<int>, 4> orderedBoundaryArcs;

    int scaleLevel;
    bool disk;
    Provenance provenance;
};
```

Never treat a world-space position as authoritative identity. Two nearby points may lie on opposing sheets, and two representations of one point may lie in adjacent source triangles.

---

# 4. Cross-field preparation

A 4-RoSy field must be manipulated modulo quarter turns. Ordinary averaging of one selected cross arm is incorrect.

The Directional Fields survey distinguishes representation, discretization, transport, matching, and topology as separate design concerns. It also derives singularities from accumulated rotations around discrete cycles. 

## 4.1 Normalize the field

Represent each cross by:

[
q_f=e^{i4\theta_f}.
]

This makes all four equivalent branches share one representation.

```text
NORMALIZE_CROSS_FIELD(mesh, rawField):
    for each source face f:
        project raw directions into tangent plane of f
        orthogonalize the two primary axes
        choose angle theta relative to deterministic face basis
        q4[f] = normalize(exp(i * 4 * theta))
        confidence[f] = estimateFromInputOrCurvatureFit()

    for each adjacent face pair (f, g):
        transport basis of g into tangent plane of f
        matching[f,g] = quarterTurn k in {0,1,2,3}
                        minimizing transported angular difference

    for each source vertex v:
        index[v] = accumulatedTransportAndMatchingRotation(v) / (2*pi)

    return q4, matching, confidence, index
```

The matching must be applied whenever a trace crosses a source edge. Storing only a locally selected direction is insufficient because the selected U and V families may rotate or swap across that edge.

## 4.2 Treat field topology as a budget

For an interior pure-quad mesh vertex of valence (v), the corresponding index convention is:

[
I=\frac{4-v}{4}.
]

Thus:

* (I=+1/4) corresponds to a valence-3 vertex.
* (I=-1/4) corresponds to a valence-5 vertex.

The pipeline must track:

```text
required field index
existing cell-complex index
index introduced or removed by each topology template
remaining unresolved index
```

A local edit may move or cancel singularities, but it must not silently change the global index budget.

---

# 5. Shared adaptive feature map

Feature classification must be centralized. Preconditioning, cross-field constraints, sizing, rails, support loops, completion, and final validation should consume the same result.

QuadWild makes input feature curves part of patch boundaries by construction rather than attempting to recover them through late snapping. It allows a more flexible intermediate layout while requiring the final mesh to be conforming and pure quad. 

## 5.1 Feature detection

```text
BUILD_FEATURE_MAP(mesh, curvature, userFeatures):
    for each edge e:
        if e is a source boundary:
            classify e as BoundaryHard
            continue

        if e has incidentFaceCount != 2:
            classify e as NonManifoldHard
            continue

        dihedral     = normalizedDihedralAngle(e)
        normalChange = multiscaleNormalVariation(e)
        curvatureMag = robustPrincipalCurvatureMagnitude(e)
        anisotropy   = curvatureAnisotropy(e)
        fitQuality   = curvatureFitConfidence(e)

        strength[e] =
            wd * dihedral +
            wn * normalChange +
            wk * curvatureMag +
            wa * anisotropy * fitQuality

        if e is user marked:
            classify e as UserHard

    strong = edgesAboveHighThreshold(strength)
    weak   = edgesAboveLowThreshold(strength)

    curves = hysteresisTrace(
        seeds = strong,
        candidates = weak,
        continuationCost =
            tangentTurn +
            strengthDrop +
            confidencePenalty)

    classify curves as:
        closed loops
        open chains
        corners
        junction graphs

    return edge classifications, curves, tangents, strengths
```

Use stable edge IDs and deterministic tie-breaking. Equivalent geometry with different source triangulations should produce approximately equivalent feature curves.

## 5.2 Intrinsic influence and density

Do not use unrestricted Euclidean point-to-feature distance. That can transfer feature influence through thin walls.

For repeated distance queries, the heat method computes multiple-source geodesic distance using two factorizable sparse systems; an intrinsic Laplacian is recommended for poor triangulations. ([CMU School of Computer Science][2])

```text
COMPUTE_FEATURE_INFLUENCE(mesh, featureCurves):
    sources = all vertices and samples on feature curves

    distance = HEAT_DISTANCE(mesh, sources)
        or exact/intrinsic Dijkstra as correctness fallback

    for each vertex v:
        influence[v] = exp(-distance[v]^2 / sigma[v]^2)

        density[v] =
            weighted geodesic curve length
            inside radius rho * localBaseSize(v)

    return distance, influence, density
```

Feature strength and feature density are distinct:

* Strength answers how important the nearest feature is.
* Density answers how many important feature curves occupy the neighborhood.

---

# 6. Adaptive target-size field

The size field should preserve curvature, narrow gaps, dense feature regions, and rapid field variation.

Persson’s mesh-size construction combines curvature, medial-axis-derived local feature size, and an explicit grading constraint limiting changes between neighboring element sizes. ([Per-Olof Persson][3])

Use:

[
h_{\text{raw}}(p)=\min
\left(
h_0,
h_\kappa,
h_\tau,
h_f,
h_\theta
\right),
]

where:

[
h_0 \approx \sqrt{\frac{A}{N_q}},
]

[
h_\kappa =
\sqrt{
\frac{8\epsilon_{\text{geom}}}
{|\kappa_{\max}|+\epsilon}
},
]

[
h_\tau=\eta,\tau(p),
]

[
h_f =
\frac{h_0}
{1+\alpha S(p)+\beta D(p)},
]

and (h_\theta) decreases where transported cross directions vary rapidly.

## 6.1 Thickness

Estimate (\tau) with one or more of:

* Opposing-normal ray casts.
* Filtered Voronoi poles.
* Signed-distance or medial approximation.
* Optional curve-skeleton radius.

Candidates must be rejected when the opposing hit:

* Belongs to the same local surface neighborhood.
* Has an incompatible normal.
* Crosses a hard barrier.
* Lies on a different disconnected component.

## 6.2 Grading and dyadic quantization

```text
BUILD_ADAPTIVE_SIZE_FIELD(mesh, featureMap, curvature, thickness, field):
    for each sample p:
        hRaw[p] = min(
            hBase,
            curvatureLimit(p),
            thicknessLimit(p),
            featureLimit(p),
            fieldVariationLimit(p))

        hRaw[p] = clamp(hRaw[p], hMin, hMax)

    hSmooth = smoothLogSizeBarrierAware(log(hRaw))

    hGraded = enforceGradientBound(hSmooth, maxSlope)

    for each sample p:
        level[p] = round(log2(exp(hGraded[p]) / hMin))
        h[p] = hMin * 2^level[p]

    repeat until stable:
        for every adjacent pair (p, q):
            if abs(level[p] - level[q]) > 1:
                refine the coarser level deterministically

    return h, level
```

Dyadic levels convert arbitrary scale drift into a finite set of explicit 2:1 topology transitions.

---

# 7. Tangent-lattice phase field

Instant Meshes separates an orientation field, which controls edge directions, from a position field, which controls vertex placement. It computes these fields with local smoothing, but its extraction is not a guarantee of a production pure-quad result. ([Interactive Geometry Lab][4])

QuadriFlow builds on this architecture but adds global network-flow and Boolean consistency constraints to reduce singularities. This is evidence that a purely local position field still needs a bounded global topology-consistency stage. 

## 7.1 Local phase compatibility

For adjacent samples (i,j), select:

* Quarter-turn (r_{ij}\in\mathbb{Z}_4).
* Lattice offset (t_{ij}\in\mathbb{Z}^2).

```text
OPTIMIZE_LOCAL_PHASE(samples, adjacency):
    initialize phase from boundary rails, features, and deterministic seeds

    repeat fixedIterationCount:
        for sample i in stable ID order:
            proposals = []

            for neighbor j:
                transportedBasis = transport(j.basis, j.face → i.face)

                for rotation r in {0,1,2,3}:
                    rotatedPhase = rotate90(j.phase, r)

                    offset = nearestIntegerVector(
                        i.phase - scaleCompatible(rotatedPhase))

                    residual =
                        norm(i.phase -
                             scaleCompatible(rotatedPhase + offset))

                    proposals.add(
                        weight(j.confidence, residual),
                        rotatedPhase + offset)

            phase[i] = weightedAverage(proposals)
            phase[i] = applyFeatureAndBoundaryConstraints(phase[i])

    return phase
```

This retains small local integer choices but does not construct global mixed-integer scalar coordinates.

At noncontractible cycles, record phase holonomy explicitly. Do not distribute the residual invisibly over the surface.

---

# 8. Optional intrinsic relief and skeleton guidance

## 8.1 Topographic relief

Construct an artificial scalar relief:

[
R(v)=
w_fS(v)
+w_kA_\kappa(v)
+w_dD(v)
+w_t\frac{h_0}{\tau(v)+\epsilon}
+w_eE_{\text{approx}}(v).
]

Use robust percentile normalization for each channel.

```text
BUILD_RELIEF_GUIDANCE(mesh, channels):
    normalize each channel robustly
    R = weighted sum

    simplify insignificant extrema using persistence
    compute minima, maxima, saddles, ridges, and watersheds

    use:
        ridges       → optional hard or soft rails
        basins       → candidate macro-patches
        saddles      → transition or pole candidates
        contours     → support-loop candidates
        minima       → deterministic sampling or simplification roots

    return guidance only
```

Relief topology is a guide, not authority. A watershed cell is not automatically a quadrangulatable surface cell.

## 8.2 Curve skeleton

For articulated or tubular objects, a curve skeleton can provide:

* Longitudinal limb orientation.
* Circumferential ring-loop seeds.
* Branch-junction patch anchors.
* Thickness estimates.

Curve-skeleton-guided layouts create branching boxes and quadrangular tubes aligned with limbs, but they capture coarse object structure rather than fine surface features. 

Keep this component optional and default-off.

## 8.3 Three-dimensional straight skeleton

An exact 3D straight skeleton is not appropriate as the general core mechanism. General nonconvex polyhedra have ambiguity issues, and worst-case straight-skeleton complexity is superquadratic. ([arXiv][5])

It may be evaluated only for:

* Polycube-like hard-surface decomposition.
* Mitered offset structure.
* Collapse-distance hints.
* Large planar-shell junctions.

---

# 9. Intrinsic surface walking

Every proposed corner and curve sample must be generated by walking across the source triangulation.

```text
WALK_ON_SURFACE(startPoint, tangentDisplacement):
    p = startPoint
    remaining = tangentDisplacement

    while norm(remaining) > tolerance:
        f = p.sourceFace

        express remaining in 2D basis of f
        compute barycentric endpoint candidate

        if candidate lies inside f:
            p.barycentric = candidate
            return p

        crossedEdge, alpha =
            first barycentric boundary crossed

        p = exact point on crossedEdge
        consume alpha fraction of remaining

        if crossedEdge is source boundary:
            return BoundaryHit(p)

        g = adjacent face across crossedEdge

        remaining =
            unfold or parallel-transport remaining from f to g

        p.sourceFace = g
        p.barycentric = orientationCorrectedEdgeCoordinates(g)

        preserve componentId and localSheetId

    return p
```

Nearest-point projection may be used only as a bounded correction with provenance restrictions. It must not be used to discover the next sheet or source face.

---

# 10. Seeding and advancing the surface front

Q-Morph demonstrates the usefulness of an advancing front whose processing order determines where quadrilaterals are formed, while local transformations and inserted nodes resolve difficult configurations. ([CS UW Pages][6])

Frontal Delaunay work similarly uses a local cross-field-aligned (L_\infty) metric to place points that are suitable for later quadrilateral formation. 

## 10.1 Seed order

1. Source boundaries.
2. Hard feature curves.
3. Feature corners and junctions.
4. Required singularity ports.
5. Optional skeleton or relief rails.
6. Regular coverage seeds.

```text
INITIALIZE_FRONT(mesh, featureMap, field, size):
    discretize source boundaries at local target size
    discretize hard feature curves with shared endpoint ownership

    for each field singularity:
        valence = 4 - 4 * singularityIndex
        create valence ordered ports
        align ports to transported field branches

    insert regular seeds using deterministic intrinsic farthest sampling

    enqueue all open front edges with priority:
        smaller target size first
        hard features before soft regions
        singularity ports before regular fronts
        stable identity as final tie-break
```

## 10.2 Closed-cell proposal

A valid proposal consists of four corners and four ordered boundary arcs. Four independent half-traces from a center are not a cell.

```text
PROPOSE_CELL(frontEdge AB):
    h = compatibleTargetSize(A, B)

    familyTangent = field family aligned with AB
    advanceDirection = orthogonal family on unfilled side

    D = WALK_ON_SURFACE(A, h * advanceDirectionAt(A))
    C = WALK_ON_SURFACE(B, h * advanceDirectionAt(B))

    arc0 = existing front arc A → B
    arc1 = TRACE_FIELD_ARC(B → C)
    arc2 = TRACE_FIELD_ARC(C → D, opposite family)
    arc3 = TRACE_FIELD_ARC(D → A)

    proposal = ordered cycle(A, B, C, D, arcs)

    reject if:
        any corner is duplicated
        cycle does not close
        boundary self-intersects intrinsically
        orientation is negative
        local size error exceeds bound
        field-alignment error exceeds bound
        proposal crosses a hard rail
        provenance changes component or sheet
        cycle encloses a non-disk region unexpectedly

    return proposal
```

Trace state should include:

```text
(sourceFace,
 entryEdge,
 fieldFamily,
 sign,
 quantizedBarycentricPosition)
```

This prevents ambiguous revisits and makes deterministic loop detection possible.

---

# 11. Front collision and topology reconciliation

A collision is not just a geometric proximity event. It must compare:

* Source component and local sheet.
* Position.
* Tangent direction.
* Field family.
* Scale level.
* Lattice phase.
* Existing ownership.
* Singular-index consequences.

```text
RESOLVE_FRONT_EVENT(frontA, frontB):
    if different component or local sheet:
        reject capture

    if positions and phases are compatible:
        snap to one canonical embedded node
        merge ownership and provenance
        close affected cycles
        return

    if scale levels differ by exactly one:
        apply validated 2:1 transition template
        return

    if phase mismatch can terminate at required singularity:
        route mismatch to that singularity
        return

    if inserting a valence-3/5 pair:
        trial topology edit
        require:
            net index change = 0
            acceptable feature distance
            acceptable quality
            no new non-disk cell
        commit only after validation
        return

    defer into bounded local closure patch
```

QuadriFlow’s use of a global network-flow consistency problem motivates a final **global reconciliation pass over conflicts**, even though the geometry was constructed locally. That pass should optimize conflict resolution and singularity count, not global integer coordinates. 

---

# 12. Global surface arrangement

Each source triangle can host local segment intersections, but the resulting arrangement must be canonically stitched across source edges and vertices.

QEx shows that extraction robustness requires sanitizing shared representations and making topological decisions consistently rather than relying on broad epsilon neighborhoods. It also introduces outgoing “ports” as explicit connectivity entities. 

## 12.1 Canonical embedded identities

```text
CANONICAL_POINT_KEY(surfacePoint):
    if point coincides with source vertex v:
        return (SourceVertex, globalVertexId(v))

    if point lies on source edge (a,b):
        lo, hi = sorted(globalId(a), globalId(b))
        t = parameter measured from lo toward hi
        return (SourceEdge, lo, hi, exactOrFiltered(t))

    return (
        FaceInterior,
        sourceFace,
        robustLocalCoordinates(surfacePoint))
```

## 12.2 Arrangement construction

```text
BUILD_GLOBAL_ARRANGEMENT(embeddedArcs):
    for each source face:
        collect arc segments embedded in that face
        intersect using filtered predicates with exact fallback
        split segments at all ordered events

    canonicalize every endpoint and intersection

    merge:
        adjacent-face copies of source-edge points
        source-vertex copies
        coincident segments with compatible geometry

    preserve all provenance:
        arc IDs
        strand IDs
        rail IDs
        proposal IDs
        source support
        field family
        ownership

    construct halfedges and cycles

    validate:
        twin incidence
        cycle closure
        orientation
        disk or non-disk classification
        source-component consistency
        Euler characteristic
```

Topology must not depend on coordinate rounding such as “multiply by (10^{10}) and cast.”

---

# 13. FlowRep-inspired network simplification

FlowRep is already deterministic. Its main transferable structure is:

1. Extract coherent flowline strands.
2. Construct a dense descriptive network.
3. Remove or substitute redundant curves.
4. Re-evaluate affected cycles.
5. Smooth surviving curves. 

For quadrangulation, replace perceptual projectivity with geometric and topological feasibility.

```text
SIMPLIFY_EMBEDDED_NETWORK(complex):
    strands = extractMaximalNonbranchingStrands(complex)

    priorityQueue = []

    for strand s:
        priorityQueue.push(
            candidateRemovalOrSubstitution(s),
            deterministicCost(s))

    while queue not empty:
        candidate = queue.pop()

        affectedPatch = extractCompleteAffectedDisk(candidate)

        trial = copyOrJournal(affectedPatch)
        apply candidate to trial
        rebuild incidence and affected cycles

        if loses hard rail:
            reject

        if intrinsicCoverageError(trial) > limit:
            reject

        if normalOrHausdorffError(trial) > limit:
            reject

        if any merged patch is non-disk:
            reject

        if boundary parity or patch feasibility fails:
            reject

        if unresolved T-junction is introduced:
            reject

        if topology or provenance validation fails:
            reject

        commit trial
        recompute all overlapping candidates
```

Coverage must be measured intrinsically and normalized by local (h). One source-triangle split of a logical curve must not be counted as an independent patch side.

---

# 14. Patch feasibility and pure-quad completion

QuadWild permits nonrectangular patches and temporary coarse-layout T-junctions, but only under conditions that permit a globally consistent, T-junction-free final tessellation. It uses 3–6-sided patch feasibility and introduces internal irregular vertices when required. 

For side edge counts (e_i), the simple closed-form conditions used in that work include:

[
\begin{aligned}
n=3 &: \quad e_i \le e_{i+1}+e_{i+2},\
n=4 &: \quad e_i=e_{i+2},\
n=5 &: \quad e_i+e_{i+1}+e_{i+4}
\ge e_{i+2}+e_{i+3},\
n=6 &: \quad e_i\le e_{i+2}+e_{i+4}.
\end{aligned}
]

Tarini derives necessary and sufficient closed-form conditions for maximally regular (N)-sided patch quadrangulations with one internal irregular vertex, or none for four sides. ([arXiv][7])

Takayama et al. provide a pattern-based fallback guaranteed for valid 2–6-sided boundary subdivisions through canonical simplification and a finite pattern set. ([Interactive Geometry Lab][8])

```text
COMPLETE_PATCH(boundaryLoop):
    require boundaryLoop is simple and disk-homeomorphic

    sides = segmentBoundaryAt:
        corners
        feature junctions
        significant turns
        prescribed transition points

    reject left-turn or U-turn configurations
    edgeCounts = assignGloballyConsistentSubdivisions(sides)

    if closedFormFeasible(sides, edgeCounts):
        quads = constructClosedFormPatch(sides, edgeCounts)
    else if patternFallbackSupports(sides, edgeCounts):
        quads = constructPatternPatch(sides, edgeCounts)
    else:
        modify boundary through bounded transition search
        retry
        or fail closed

    place every generated vertex intrinsically on source patch

    validate:
        all faces are quads
        boundary subdivisions match neighbors exactly
        no T-junctions
        positive orientation
        correct net index
        no degenerate or concave quads
        feature boundary unchanged

    return quads
```

Even boundary parity is necessary but not sufficient.

---

# 15. Quad-topology rewrite library

The topology references should be converted into guarded local transformations rather than subjective cleanup heuristics.

The Pushing Points workbook visually demonstrates repeated **edge spinning** to redirect flow on pages 51–66 and **moving, creating, and removing poles** on pages 68–78. 

The accompanying topology guides emphasize that loops should follow intended shape details, poles redirect loops, unnecessary loops should remain localized, and high-valence poles often create pinching or poor flow.

Required operations:

```text
RotateQuadEdge
MovePole
CancelCompatiblePolePair
SplitHighValencePole
InsertStrip
RemoveRegularStrip
ApplyTwoToOneTransition
ApplyThreeToTwoTransition
ApplyFourToTwoTransition
ApplyRadialTransition
InsertFeatureSupportLoop
```

Every operation must define:

```cpp
struct TopologyTemplate {
    CanonicalBoundarySignature boundary;
    ValenceSignature before;
    ValenceSignature after;

    int netIndexChange;

    ProtectedEdgeRequirements protectedEdges;
    QualityThresholds quality;
};
```

```text
TRY_TOPOLOGY_TEMPLATE(complex, match, template):
    verify canonical preconditions
    verify no protected feature would move or disappear

    trial = copy affected disk
    apply template

    rebuild incidence, strips, loops, and provenance

    require trial.netIndexChange == template.netIndexChange
    require topology valid
    require signed scaled Jacobian above threshold
    require field and feature cost does not exceed limit
    require no new self-intersection or T-junction

    commit only if objective decreases monotonically
```

Do not use a generic center fan for arbitrary patches. It creates unnecessary high-valence poles and cannot represent controlled strip transitions.

---

# 16. Geometric optimization

Topology should be fixed before final continuous optimization.

Use an energy such as:

[
E =
w_HE_{\text{surface}}
+w_NE_{\text{normal}}
+w_AE_{\text{field}}
+w_OE_{\text{orthogonality}}
+w_SE_{\text{size}}
+w_PE_{\text{planarity}}
+w_FE_{\text{feature}}.
]

```text
OPTIMIZE_OUTPUT_MESH(mesh, source):
    repeat fixed outer iterations:
        for output vertex v in stable order:
            if v is fixed feature corner:
                continue

            gradient =
                sourceDistanceGradient(v) +
                normalErrorGradient(v) +
                fieldAlignmentGradient(v) +
                orthogonalityGradient(v) +
                localSizeGradient(v) +
                planarityGradient(v)

            direction = project gradient into allowed tangent space

            if v lies on feature curve:
                direction = project direction onto feature tangent

            line search:
                trial = intrinsicMove(v, -step * direction)

                reject if:
                    source component or sheet changes
                    feature interval order changes
                    any adjacent quad inverts
                    signed scaled Jacobian falls below threshold
                    global energy does not decrease

            commit accepted trial
```

Cross-field alignment for an edge direction (\phi) may be measured without selecting one cross arm:

[
E_{\text{field}} =
1-\cos(4(\phi-\theta)).
]

This respects 4-RoSy symmetry.

---

# 17. Robust final validation

QEx’s central lesson applies even though the new backend has no integer-grid map: explicit geometry extraction and connectivity assembly are numerically and topologically nontrivial, and ambiguous local cases must be sanitized before connectivity is trusted. 

```text
VALIDATE_FINAL_MESH(output, source, field, features):
    require every face has exactly four distinct vertices

    require each interior edge has exactly two oppositely oriented faces
    require each boundary edge has exactly one face
    require no duplicate face ownership

    require all face orientations are positive
    require no degenerate or concave quads
    require signed scaled Jacobian >= threshold

    require connected-component count matches policy
    require boundary loops match source boundary contract
    require Euler characteristic matches source topology

    require no embedded T-junctions
    require no nonmanifold vertices or edges
    require no self-intersections

    require every output vertex has source provenance
    require no cross-component or cross-sheet projection
    require sampled quad-to-source error <= limit

    require all hard feature curves are represented by ordered output edges
    require feature corners and junctions are preserved

    require extraordinary-valence index sum matches required budget

    require field alignment, size error, and normal error within bounds

    require deterministic structural hash across repeated runs
```

The pipeline must fail closed. It must not return:

* A triangle input as a successful quad-dominant result.
* A partial surface-cell complex as a successful mesh.
* A mesh whose provenance or feature ownership is incomplete.
* A nominally pure-quad mesh with unresolved embedded T-junctions.

---

# 18. What should be core versus optional

## Core production requirements

* 4-RoSy-safe transport and matching.
* Shared feature map.
* Thickness-aware graded sizing.
* Intrinsic source-surface movement.
* Tangent-lattice phase compatibility.
* Closed-cell proposals.
* Explicit collision and 2:1 transition handling.
* Canonical multi-triangle arrangement stitching.
* Transactional strand simplification.
* Proven patch feasibility and pure-quad completion.
* Guarded pole and strip templates.
* Source-constrained optimization.
* Strict fail-closed validation.

## Optional or experimental guidance

* Morse-Smale or topographic relief decomposition.
* Curve-skeleton limb and branch guidance.
* Semantic/user-authored support loops.
* Exact three-dimensional straight skeletons.
* Subdivision-specific hold-edge generation.

These optional systems may improve layout, but none should be required for geometric correctness.

---

# 19. Critical implementation invariants

The following invariants should hold after every committed stage:

1. **Intrinsic ownership:** every geometric entity has source-face and barycentric provenance.
2. **Same-sheet safety:** no proximity or projection operation crosses components or local sheets.
3. **Field consistency:** every source-edge crossing applies authoritative principal matching.
4. **Rail preservation:** boundaries and hard features cannot be silently dropped.
5. **Cycle completeness:** every accepted cell or patch has a complete ordered boundary.
6. **Transactional topology:** no topology mutation is committed before full local validation.
7. **Global index conservation:** every rewrite records its singularity-index effect.
8. **No final T-junctions:** temporary layout T-junctions must be resolved during completion.
9. **Determinism:** stable IDs, traversal orders, priority ties, and stopping rules are mandatory.
10. **No synthetic success:** missing evidence or unresolved topology produces a typed failure.

The distilled novel contribution is therefore:

> A source-attached adaptive tangent lattice that creates and simplifies a cross-field-aligned surface curve network, reconciles its local phase and topology through index-preserving events, and completes the resulting disk patches into a validated pure-quad complex without constructing a global integer parameterization.

[1]: https://www.sciencedirect.com/science/article/abs/pii/S0045782523005662?utm_source=chatgpt.com "Why cross fields are not equivalent to quadrilateral meshes"
[2]: https://www.cs.cmu.edu/~kmcrane/Projects/HeatMethod/ "Keenan Crane - The Heat Method for Distance Computation"
[3]: https://persson.berkeley.edu/pub/persson05sizefunc.pdf "sizefunc.dvi"
[4]: https://igl.ethz.ch/projects/instant-meshes/instant-meshes-SA-2015-jakob-et-al-compressed.pdf?utm_source=chatgpt.com "Instant Field-Aligned Meshes"
[5]: https://arxiv.org/abs/0805.0022?utm_source=chatgpt.com "Straight Skeletons of Three-Dimensional Polyhedra"
[6]: https://pages.cs.wisc.edu/~csverma/CS899_09/qmorph.pdf "Q-Morph: an indirect approach to advancing front quad meshing"
[7]: https://arxiv.org/abs/2101.11569?utm_source=chatgpt.com "Closed-form Quadrangulation of N-Sided Patches"
[8]: https://igl.ethz.ch/projects/patch-quad/ "igl | Interactive Geometry Lab | ETH Zurich | Pattern-Based Quadrangulation for <i>N</i>-Sided Patches"

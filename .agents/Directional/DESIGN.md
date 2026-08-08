# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed high-level gate. Every implementation turn declares:

```text
Active design gate:
Earliest failing fixture/contract:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. Diagnostics/counters/hashes, equivalent failure movement, aggregate gains, performance changes, fallback/recovery, or fixture-specific behavior are not material progress alone.

## Producer authority model

An authoritative producer returns one of:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: this producer does not represent the source topology yet; another explicitly selected producer may run.
- `Produced`: authoritative cells/fronts are complete and materialize directly one cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; retain the typed reason and stop the backend request. Do not silently launch generic seeds/traces/proposals.

Applicability derives from general topology/field state before authoritative metadata execution, never fixture identity or failure recovery.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, ordered route, feature, ownership, and periodic state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact component/sheet ownership, complete route provenance, and any required periodic quotient identity. One accepted cell maps to one quad.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** passed.
3. **G2 — Cross-chart and close-sheet propagation:** passed.
4. **G3 — Periodic closure and holonomy:** **passed** by exact artifact `9013161456` with 17/17 retained contracts and direct deterministic strict-valid cylinder output.
5. **G4 — Topology-distinct completion and singularities:** **active**. First slice: closed-genus-one/multi-periodic authority on exact torus; prescribed singular sphere follows after the earlier torus contract.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed G0-G3 runtime authority

Exact artifact `9013161456` preserves:

| Fixture | Producer | Direct output | Determinism |
|---|---|---|---|
| plane | `Produced` | 81 V / 64 strict-valid quads, hash `730caeae49ec872c` | 3/3 |
| seam | `Produced` | 81 V / 64 strict-valid quads, hash `5bdf34d7802e9fb0` | 3/3 |
| close sheets | `Produced` | 242 V / 200 strict-valid quads / 2 isolated components, hash `89b052762f52a5af` | 3/3 |
| cylinder | `Produced` | 320 V / 288 strict-valid quads, hash `32135be51d7a0a26` | 3/3 |

Cylinder periodic authority is `r=0`, `t=(32,0)`, route 32, cut 4; field P95 is `8.537736463e-7°`; validation failures are zero; exactly two genuine annulus exterior loops remain and the artificial cut is not exterior. No passing case uses fallback or source-grid recovery.

Focused/retained G0-G3 contracts are **17/17** after the subdivision-independent field-correspondence witness correction in evidence commit `117620ec2da2083ce11b205835e58fa404f163ef`. Production tracing blobs remain those of runtime-proven source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

## G2 source-sheet invariant

Authoritative state is partitioned by `(source component, local sheet)` before front construction. World-space distance, nearest projection, or overlap may not join unrelated sheets. Phase, ownership, route, capture, collision, boundary loops, and materialization identity remain sheet-local unless exact source topology establishes a connection.

## G3 periodic invariant

A connected singularity-free annulus has first-class periodic authority:

```text
periodic holonomy =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route
```

Required invariants:

- applicability derives from source topology, never fixture identity;
- one deterministic intrinsic source cut joins the two genuine annulus boundaries;
- cut-open chart construction does not require global world-space planarity;
- chart duplicates retain authoritative underlying source identity;
- periodic transport is reciprocal, integral, branch-compatible and source-routed;
- invalid periodic state is typed `Rejected` and cannot fall through to generic tracing;
- artificial-cut counterparts pair through exact source/phase/lattice authority, never Euclidean welding;
- the artificial cut is not an exterior output boundary;
- the two genuine annulus boundaries remain exterior;
- direct materialization quotients periodic duplicates exactly;
- every canonical source-ring strip boundary is an intrinsic periodic lattice breakpoint;
- one accepted phase-front cell maps directly to one output quad.

## Field-authoritative adjacent-ring correspondence

A triangulated annulus strip may admit multiple source-topologically valid bijections between adjacent canonical rings. Source vertex numbering, lexicographic order, candidate count, discovery order/frequency, or proximity are not authority.

Required contract:

> Enumerate topology-compatible correspondences, propagate reciprocal 4-RoSy family/sign authority across the complete source strip, and consume exactly one field-authoritative optimum. Zero valid field candidates or genuinely field-equivalent best candidates fail closed with typed periodic authority.

The production implementation at `0279946920dfca6e9ac44b7ea31b38e929d1f5fc` satisfies this contract at runtime. The obsolete diagonal candidate is approximately `37.9671°` from the axial field and must not be restored.

## Canonical periodic chart geometry

Coverage tolerance may determine source-triangle ownership, but emitted geometry must be exact canonical source-simplex geometry. Exact simplex crossings define emitted breakpoints; barycentrics near exact boundaries are canonicalized/renormalized; source vertices use exact one-hot barycentrics; tolerance-only collapsed segments are omitted; genuine overlap remains rejected by the unchanged strict validator.

## Test-witness invariant for field correspondence

A semantic field-authority regression test must not depend on one particular target subdivision. The cylinder source inter-ring spacing is 0.5 while the active test target is 0.25; therefore each source inter-ring connection is legitimately subdivided into multiple V-family phase-front edges.

Required test contract:

> Observe nonzero source-attached V-family phase-front boundary-path segments, reconstruct their source geometry from authoritative `(face, barycentric)` provenance, verify finite normalized source-simplex endpoints, discard only genuine zero-length segments, and require each observed segment to align with the local authoritative V field family. The witness must remain nonempty and subdivision-independent.

Evidence commit `117620ec2da2083ce11b205835e58fa404f163ef` implements only this test correction; artifact `9013161456` proves it passes together with the other 16 retained contracts and unchanged direct cylinder output.

## G4 closed-topology progression and current boundary-phase authority

The exact torus is connected, closed, and genus one: 72 vertices, 144 triangles, 216 edges, zero boundary edges, Euler characteristic 0. G4 has advanced through several first-class sub-contracts while retaining G0-G3 authority.

### Multi-relation periodic authority — implemented and runtime-live

A topology/component may expose multiple compatible periodic relations. Every retained relation derives from exact source topology and reciprocal 4-RoSy transport, has canonical route/cut/lattice identity, is deterministic independent of face-row or producer discovery order, and is consumed by structural hashing, diagnostics, provenance, and exact lattice quotient materialization. Equivalent/reversed descriptions canonicalize; conflicting or genuinely ambiguous/dependent relation authority fails closed with a typed reason.

Important constraints remain:

- a second relation is not accepted merely because it exists;
- relation ownership/basis selection may not use source numeric ID alone, discovery order, count/frequency, arbitrary subset search, or Euclidean proximity;
- multiple local-sheet relations do not weaken G2 sheet isolation;
- hard-feature/source-sheet barriers are not removed merely to avoid multi-relation topology;
- exact quotient remains source/phase/lattice-based, never Euclidean seam welding;
- a stored relation that is not consumed by materialization/hashing is not first-class progress;
- the single-annulus G3 behavior remains semantically unchanged.

### Curved bounded-disk producer — implemented and runtime-live

The producer recognizes connected source-sheet disks with Euler characteristic 1 and one manifold boundary, propagates reciprocal 4-RoSy branch gauge across the source-face dual graph, and builds an intrinsic source-attached chart/front. Topology, transport, boundary phase, chart and front-pairing failures are typed and fail closed. The planar bounded and periodic-annulus producers remain separate first-class paths and exact-once source-sheet aggregation remains authoritative.

### Source-sheet boundary authority — runtime-proven

Artifact `9019024467` proves that local curved-disk boundary authority is not synonymous with hard-feature membership. A local edge is authoritative when it is a genuine source boundary, a hard-feature internal boundary, or a non-hard internal edge whose opposite source face belongs to a different authoritative `(component, sheet)`. A non-hard internal edge whose incident faces share the same authoritative component/sheet remains an invalid hidden cut.

This contract is runtime-proven by 3/3 focused boundary cases while the combined curved-disk group is 9/9, sheet coverage 3/3, G4 periodic relations 5/5, retained G0-G3 17/17, and all direct G0-G3 hashes remain unchanged.

### Current G4 blocker — field-authoritative disk boundary phase

Exact torus now deterministically reaches `Rejected / InvalidBoundedDiskBoundaryPhase` at `tracing/phase-front`, first invalid face `-1`, with periodic authority still live and no fallback/recovery. The current curved-disk boundary stage classifies ordered boundary edges against transported branch/family/sign state, groups equal labels into runs, then globally requires exactly four runs in a rectangular `U+`, `V+`, `U-`, `V-` cycle before mapping the disk to a rectangle. Existing runtime diagnostics do not expose which global four-run/canonical-order check fired, so no unobserved torus run count or branch sequence is authority.

Required current contract:

> Ordered source-attached boundary runs/corners and their transported 4-RoSy turn/index closure are first-class phase authority. Preserve the exact four-run rectangle as a fast path, but support a valid non-rectangular field-compatible orthogonal/polygonal disk through a deterministic intrinsic polygonal/singularity-compatible chart. Ambiguous boundary phase, invalid cyclic turn/index closure, chart fold, or front pairing fails closed with a typed reason.

The generalized representation may not manufacture four sides by arbitrary run merge/split, lower alignment thresholds to fit a fixture, demote features/source-sheet rails, select corners by raw IDs/count/frequency/order/proximity, create synthetic Euler corrections, or use Euclidean welding/post-hoc cell merging. One accepted authoritative cell still maps directly to one quad.

G4 itself is not passed until the required torus topology and prescribed-singularity fixtures complete directly.

## G4 prescribed-singularity observation

The prescribed sphere currently reaches completion: producer `NotApplicable`, 766 traces, 30 arrangement/simplified cells, zero completed output, terminal `NotProductionReady:completion`. The first detailed completion failure is `repeated-boundary-node` followed by parity-alternative budget exhaustion (68/68). This is downstream of the torus tracing/phase-front blocker and therefore deferred until the torus topology slice is closed.

## Next authority

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Plan.md` as **Code + Build only**. No generated project binary may execute. The following artifact-only turn must retain source-sheet-boundary 3/3, combined curved-disk authority, sheet coverage 3/3, G4 periodic relations 5/5, retained G0-G3 17/17 and exact direct hashes, then prove exact torus advances beyond `InvalidBoundedDiskBoundaryPhase` through a real consumed generalized boundary-phase representation or reaches direct strict-valid production.

## Non-negotiable prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.

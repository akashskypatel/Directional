# Surface-Cell Backend Remediation Plan

## Production objective

Produce deterministic, direct, source-authoritative cross-field-aligned quad meshes for arbitrary triangle meshes. Production success must come directly from the requested `SurfaceCells` backend. Fallback, source-grid recovery, synthetic topology repair, or validator relaxation cannot satisfy acceptance.

## Gate policy

Remediation follows the ordered design gates in `.agents/Directional/DESIGN.md`. Only the earliest incomplete gate may be the principal implementation objective.

- G0 truthful authority — passed.
- G1 uniform phase-front plane — passed.
- G2 cross-chart and close-sheet propagation — **active**.
- G3 periodic closure and holonomy — blocked.
- G4 topology-distinct completion and singularities — blocked.
- G5 adaptive scale and hard features — blocked.
- G6 general production geometry — blocked.
- G7 operational hardening — blocked.

## Closed Gate 1 state

The producer now has runtime-validated first-class phase/lattice state, directed front ownership, source-normal winding, transactional whole-cycle reversal, component/sheet/edge-incidence validation, deterministic direct vertex canonicalization, one-cell-to-one-quad materialization, and pure-quad plane success with strict validation and no fallback/recovery.

Gate 1 remains protected while remediation advances.

## Current Gate 2 state

Artifact evidence:

- multi-face seam: 137 traces, zero arrangement cells, zero quads, `SideSubdivisionRepair:InvalidInputIncidence`;
- close sheets: 158 traces, zero arrangement cells, zero quads, the same failure;
- stage hashes are stable across three processes;
- no fallback or source-grid recovery is used.

The producer still falls back from the planar phase-front attempt to the older trace/proposal path on multi-chart inputs. The remediation target is authoritative cross-chart phase-front transport, not another completion repair.

## Required Gate 2 remediation

### 1. Authoritative chart identity

Carry `SourceChartId` or an equivalent exact chart identity in lattice/front/cell state. Include component, local sheet, source face, and transition witness in deterministic hashes.

### 2. Transition transport

Use `SourceChartTransitionGraph`, exact source topology, hard-feature barriers, and cross-field edge matching/transition data. Transport barycentric support and route, selected branch and quarter-turn rotation, phase and integer lattice coordinate, family/sign, component, and local-sheet provenance.

Require an exact inverse transition. Missing, ambiguous, or inconsistent state fails closed.

### 3. Multi-chart front construction

Advance each front side intrinsically through adjacent source faces. Construct cells from transported chart state rather than a global planar projection. The multi-face seam fixture must exercise the general path.

### 4. Compatible cross-chart merge

Merge only when reciprocal route, canonical transition, phase/lattice coordinate, branch/family/sign, component, sheet, and directed ownership agree. Do not select by distance, count, order, or frequency.

### 5. Close-sheet isolation

Retain local-sheet identity through every transition and merge. Exact manifold adjacency may cross face boundaries, but geometrically close unrelated sheets must never canonicalize, capture, or merge by position.

### 6. Preserve direct materialization

Accepted four-sided cross-chart cells use the Gate 1 orientation/incidence and one-cell-to-one-quad path. Generic completion cannot invent or expand their topology.

## Next compile gate

Use `.agents/Directional/Gate_2_Cross_Chart_Close_Sheet_Code_Build_Plan.md`. Compile the approved seven targets only. Do not execute generated binaries, tests, benchmarks, discovery, CLI, GUI, or help/list commands.

## Material progress

Progress requires seam success or nonzero deterministic authoritative cross-chart cells that reach a new first-class transport/materialization boundary. Unchanged zero-cell completion failure, diagnostics, counters, hashes, or unrelated passes are insufficient.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.

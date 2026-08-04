# Milestone G P5 Post-TB19 Completion, Topology, Reuse, and Output Code/Build Plan

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Next turn:** P5-CB117 through P5-CB125 code changes plus compile-only build

## Purpose

Convert P5-TB19's typed runtime evidence into focused producer corrections.
Preserve the compact exact ownership registry and all Phase 14–18 closures.
Do not weaken validation, substitute fallback/recovery, synthesize counters, or
special-case fixture IDs.

The code/build turn may modify source and regression fixtures, but must execute
no test, benchmark, custom mesh, help/list/discovery command, or compiled
project binary. Compile exactly the four required targets and package the exact
pushed source with mandatory workflow logs.

## Authority

1. `.agents/Directional/Milestone_G_P5_TB19_Ownership_Compaction_Topology_Output_Test_Benchmark_Report.md`
2. `benchmark-results/p5-tb19-summary.json`
3. `.agents/Directional/Milestone_G_P5_CB108_CB116_Code_Build_Report.md`
4. `TODO`
5. `MILESTONE_G_TODO.md`
6. `.agents/Directional/Future_Chat_Session_Handoff.md`
7. `.agents/Directional/GitHub_Workflow_Policy.md`

## Preserved closures

The next implementation must retain:

- Phase 14–18 **235/235**;
- Phase 16 **39/39** and Phase 17 **26/26**;
- compact one-per-complex exact ownership registry;
- intrinsic unlabeled source components and default charts;
- face-row-independent ownership identity;
- typed domain failure evidence;
- malformed midpoint mutation and bit-exact rollback;
- full-suite termination and bunny resource limits;
- no fallback or source-grid recovery.

## P5-CB117 — normalize transactional rollback authority

### Defect

`MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed` records the structural
hash of a manual legacy complex before ownership canonicalization. Production
canonicalizes the working complex before the attempted transaction, so a
correct rollback returns the canonical committed baseline rather than the
pre-canonical fixture bytes.

### Implementation

- define one explicit transaction-entry canonicalization boundary;
- expose or reuse a helper that returns the canonical committed baseline before
  proposal mutation;
- ensure rollback restores that exact canonical baseline, including ownership
  registry, cell keys, charts, rail lineage, and diagnostics;
- update the fixture to canonicalize before its baseline hash, or construct it
  canonically from the start;
- retain a separate assertion proving the rejected mutation made no committed
  change.

### Acceptance source

Compile-valid regression source must prove rejection, unchanged canonical
identity, unchanged protected rails, and unchanged diagnostics. Do not weaken
hashing or compare only selected fields.

## P5-CB118 — add typed incidence audit and repair the open-cylinder DCEL

### Defect

The cylinder fails `validate_complex_incidence` before candidate extraction.
The boolean validator hides the first malformed entity.

### Implementation

- introduce a typed `SurfaceCellIncidenceAudit` with first invalid cell,
  halfedge, node, twin, next/previous, and failure kind;
- audit halfedge endpoint range, twin symmetry, next/previous symmetry, closed
  cell cycles, unique directed incidence, boundary-loop termination, and source
  chart ownership;
- invoke the audit before simplification candidate extraction;
- repair periodic seam canonicalization and open-cylinder cell/boundary cycle
  construction from topology, not position or face order;
- keep the cylinder open: Euler characteristic 0, one connected component, two
  boundary loops, consistent orientation, disk interior cells, and protected
  strand/rail support.

### Prohibition

Do not skip the incidence gate, delete the protected strand, collapse the
periodic seam, or special-case the cylinder fixture name.

## P5-CB119 — repair shared-edge parity topology transactionally

### Defect

`SharedEdgeParityRepairConforminglyCompletesTwoOddCells` becomes topology-invalid
following registry-backed parity mutation.

### Implementation

- run typed incidence/domain audits on the prepared complex before and after the
  parity transaction;
- derive the shared split edge and both affected cell cycles from DCEL adjacency;
- create one conforming midpoint/edge representation shared by the two cells;
- rebuild next/previous/twin and cell halfedge lists atomically;
- propagate compact ownership keys and exact incident charts through both
  children;
- recompute topology diagnostics only after successful commit;
- roll back the exact canonical baseline on any failure.

## P5-CB120 — fix repeated boundary nodes after successful subdivision

### Defect

Mechanical feature, prescribed sphere, and face-edge bunny all report
`SuccessfulSubdivisionDomainIdentity` with `repeated-boundary-node`.

### Implementation

- trace the typed failing cell/halfedge/node through side-subdivision proposal,
  insertion, and cycle rebuild;
- reject a proposal before commit when its replacement path revisits a boundary
  node or halfedge;
- canonicalize replacement path orientation relative to the owning cell;
- splice each replacement path exactly once and prove simple closed boundary
  before marking subdivision successful;
- preserve exact source chart and ownership registry references;
- emit typed proposal rejection rather than committing a non-simple cell.

### Regression sources

Add generalized fixtures for repeated node through different edge ordering and
source-face row permutations. Do not key behavior to cell 2/24, node 13/20/67,
or bunny/sphere/mechanical names.

## P5-CB121 — repair same-corner routes and enable genuine exact reuse

### Defect

`same-corner-distinct-boundary` rejects the positive route before cache lookup;
all guaranteed reuse scenarios remain `0/0`.

### Implementation

- define route identity from canonical boundary halfedges, corner occurrence
  identity, orientation, and source chart—not node position alone;
- permit distinct boundary occurrences that meet at one geometric corner when
  their topological route ownership is unambiguous;
- retain fail-closed rejection for self-crossing, duplicated, ambiguous, or
  ownership-incompatible routes;
- make affected-patch discovery and dependency vectors use compact ownership
  keys plus exact incident charts;
- rebind cached completion output to current canonical node/halfedge identities
  and validate it before counting reuse;
- increment reused/recomputed counters only from actual cache outcomes.

### Acceptance source

Both guaranteed reuse fixtures must be capable of producing real
`reused > 0` and `recomputed > 0` at runtime. No synthetic increments or
scenario-specific bypasses.

## P5-CB122 — restore pipeline stage, injection, and fallback lineage

### Defect

Pre-optimization completion validation now preempts expected injected
optimization/validation failures and changes GP23/GP24/Phase20 terminal lineage.

### Implementation

- establish explicit stage ordering and checkpoint ownership:
  completion producer -> completion validation -> optimization -> optimized
  validation -> output selection;
- preserve injected-stage semantics by applying injection at its declared stage
  after all preceding stages legitimately complete;
- retain the earliest real validation defect when no injection applies;
- preserve fallback policy: `Fail`, `ReturnInputMesh`, and legacy integration
  must behave exactly as configured without hidden source-grid recovery;
- ensure `CompletedSurfaceCells` is reported only for a valid selected completed
  checkpoint;
- preserve last-valid-stage artifacts and original failure diagnostics.

### Prohibition

Do not skip completion validation to satisfy lineage tests. Correct the producer
or test fixture when completion is genuinely invalid.

## P5-CB123 — make completed quad output source-valid and non-self-intersecting

### Defect

Plane, cylinder, multi-face seam, and close-sheets completed buffers are already
self-intersecting before optimization.

### Implementation

- inspect the first invalid completed face and its owning patch/template;
- verify corner order, boundary orientation, local embedding, and source-face
  projection before global stitch insertion;
- validate each completed face incrementally against existing adjacent output;
- distinguish duplicate face, reversed duplicate, bow-tie quad, non-adjacent
  transverse intersection, and source-sheet leakage;
- reject or choose a different bounded deterministic completion template based
  on topology/embedding validity, not fixture identity or arbitrary search;
- retain a completed checkpoint only after full source-authoritative validation;
- make output rollback select the last valid checkpoint, never an invalid
  nonempty buffer.

## P5-CB124 — resolve remaining completion inventory defects

### Smooth duplicate

The smooth bunny deterministically reports a completion-template
`DuplicateStitchedQuad` between bounded-combinatorial and pattern completions.
Use exact canonical completed-face identity and domain ownership to prevent two
patches/templates from emitting the same global quad. Repair the producer or
bounded template arbitration; do not delete a duplicate after assembly without
proving which domain owns it.

### Incomplete torus and thin tube

- report the exact first unresolved patch, boundary parity, endpoint, and
  completion inventory reason;
- repair missing bounded template coverage or invalid dependency construction;
- keep arbitrary subset search prohibited;
- preserve hard rails, thin-feature source sheets, and canonical ownership.

## P5-CB125 — close telemetry and compile/package the checkpoint

### Memory telemetry

Extend same-sample categorized ownership to include:

- active/rollback/prepared complexes;
- descriptors and domain identities;
- completion inventories, cache entries, and temporary template products;
- Eigen/vector retained capacities;
- allocator/runtime and mapped-file categories where measurable;
- explicitly labeled unexplained remainder.

Use simultaneous live ownership from the same sample as peak RSS. Do not sum
phase maxima. Target at least 75% coverage without hiding unexplained bytes.

### Regression source

Add compile-valid tests for:

- typed incidence failures and valid open-cylinder DCEL;
- canonical rollback baseline;
- shared-edge parity topology;
- repeated-node proposal rejection/repair;
- same-corner route ownership and real reuse accounting;
- stage injection/fallback lineage;
- completion self-intersection classification and valid checkpoint selection;
- duplicate completion ownership arbitration;
- memory category accounting invariants.

### Compile/package gate

- shallow-initialize recursive submodules;
- configure clean Ninja Release with the established options;
- compile exactly:
  - `directional_core`;
  - `directional_pipeline`;
  - `directional_phase1_tests`;
  - `directional_benchmarks`;
- execute no compiled project binary;
- require a clean exact source status before packaging;
- package source archive, binaries/libraries, fixtures, submodule state,
  checksums, configure/build logs, and exact source commit;
- initialize detailed workflow logging before fallible work and always upload a
  separate workflow-log artifact under `if: always()`.

## Required handoff from the code/build turn

Record:

- exact implementation and compiled source commit;
- reviewed patch identity when transport is required;
- compile-only workflow run and artifact IDs/digests;
- source cleanliness, fixture count, checksum count, and target hashes;
- implemented versus runtime-gated items;
- exact next artifact-only test order;
- any compile failure and the precise correction applied;
- confirmation that PR #8 remains open, draft, and unmerged.

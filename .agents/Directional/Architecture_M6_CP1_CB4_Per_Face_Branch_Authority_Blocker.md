# M6-CP1-CB4 implementation blocker — per-face branch authority is not present in A4

**Turn:** `M6-CP1-CB4`  
**Type:** Code + Build static derivation stop record  
**Date:** 2026-09-25  
**Runtime executed:** none

## Disposition

CB4 must stop before production/test mutation. The accepted D6/R2 contract requires each ordered `CornerWedgeFaceBinding` to carry the exact source-face topology, isolation sheet, projection chart, and **branch rotation for that face**. The current immutable A4 `SurfacePhaseFrontProduct` does not publish enough authority to derive that final field value for every face in a corner wedge.

Implementing the missing value in CB4 would require either changing the A4 product, consuming raw field transport outside the frozen A5 input boundary, or inventing/choosing a representative branch. All three exceed the authorized CB4 contract.

## Static proof from the frozen source snapshot

Exact inspection snapshot:

- run: `36104814370`
- source/event SHA: `a304bd0b36011f2c100b8a6c127d8ba3c11810cf`
- artifact: `10850013454`
- provider digest: `sha256:ff39ad5104fbfadbb245c4e406428588b5c8142d4b84d723c876c2b7704ebb12`
- embedded source archive SHA-256: `bb5d91e6aca68fd491ad9c643d406e8273a520a96b1f5a814ac8b896baac8d2e`
- source manifest: 5314/5314 verified
- `runtimeExecution=false`

The following source facts are jointly decisive.

1. **D6 makes branch authority face-dependent.**  
   `Architecture_M6_DEFN_R1_Seam_Incident_Occurrence_Sheet_Authority_Definition_Record.md` says that `sourceChart` and `branchRotation` must be moved or repeated per wedge binding and that the semantic record may not mix them across faces. R2 keeps the canonical binding signature `(sourceFaceTopology, IsolationSheetId, SourceProjectionChart, branchRotation)`.

2. **A4 publishes only corner-selected lattice branch state.**  
   `SurfacePhaseFrontCell::lattice[4]` carries one `LocalLatticeState.branchRotation` per cell corner. That state belongs to the corner's selected source face. `SurfacePhaseFrontProduct` publishes source regions, isolation-seam certificates, periodic holonomies, bounded-disk boundary phases, front edges/events, and cells; it does not publish a per-source-face branch table or the field-transport atlas.

3. **The builders already compute face-local branch authority, then discard it at the product boundary.**  
   The uniform and bounded-disk producers compute `faceBranchRotation` for their active source faces. Boundary-path `SurfaceTraceSegment.family/sign` records the branch only for faces actually traversed by that side. The complete per-face table is not retained in `SurfacePhaseFrontProduct`.

4. **A corner wedge can contain source faces not traversed by either near-endpoint side span.**  
   RA-8 defines the wedge as the source-winding fan arc from the outgoing interior face to the incoming interior face. For a source-vertex support this arc may contain intermediate faces. Those intermediate faces require bindings under D6, but no boundary segment necessarily exists on them.

5. **`SourceChartTransitionGraph` cannot reconstruct the missing field branch.**  
   It establishes source-chart components and source-face topology identities. Its transitions encode chart/simplex adjacency, not cross-field quarter-turn transport. One `FieldChartId` is assigned per admissible component while field branch orientation remains separate.

6. **Isolation certificates are insufficient for ordinary fan edges.**  
   `SurfaceIsolationSeamTransportCertificate` gives exact quarter-turn transport only for internal isolation seams. A wedge may also cross ordinary same-sheet manifold edges. `source_faces_compatible` checks only source component and isolation sheet, so same-sheet adjacency does not imply zero branch rotation.

Therefore two different per-face branch assignments can agree on all A4 data visible to A5 for an intermediate same-sheet wedge face. CB4 cannot select the required binding branch without authority outside its frozen input.

## Why the obvious workarounds are not authorized

- **Repeat the corner's scalar `LocalLatticeState.branchRotation` for every binding:** violates D6's face-dependent provenance and can silently mix the branch of one source face with another.
- **Infer from `SourceProjectionChart` / chart component:** invalid; chart-component identity does not encode cross-field branch transport.
- **Search other boundary paths for a matching face transition:** incomplete and creates a global reconstruction/representative search not frozen by R2.
- **Pass the raw field transport atlas into A5:** changes A5's frozen typed input boundary.
- **Add a per-face branch table to `SurfacePhaseFrontProduct` inside CB4:** changes an A4 product, explicitly outside CB4's immutable boundary.

## Required definition decision

A bounded Definition amendment must choose and prove an authoritative source for `CornerWedgeFaceBinding.branchRotation`. The two viable design directions are:

1. **Preserve A4-computed per-face branch authority in the A4 product** and let A5 consume it directly. This is the narrowest way to retain information the builders already prove, but it is an A4 product-schema change and therefore requires explicit authorization.
2. **Redefine the binding branch value so it is derivable from existing A4 products** without a representative choice, with a proof covering uniform, periodic-chart, and bounded-disk builders.

Consuming raw field inputs in A5 is not recommended because it breaks the frozen stage-separation contract.

Until that decision is frozen and reviewed, no CB4 source/test patch or compile candidate is authoritative.

## Accounting

This is a static definition/authority gap, not a runtime regression. It adds no stable event/category/recurrence and does not alter the accepted M5 runtime authority, selector449, routing449, or produced-witness debt.

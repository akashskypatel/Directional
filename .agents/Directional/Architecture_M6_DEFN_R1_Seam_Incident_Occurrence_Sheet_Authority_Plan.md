# M6-DEFN-R1 Seam-Incident Occurrence Sheet Authority — Definition Plan

**Turn:** `M6-DEFN-R1`
**Type:** Definition amendment, runtime-free
**Predecessor:** `M6-CP1-TB3-REV`, review-agent addendum (`Architecture_M6_CP1_TB3_Review_Record.md` §A2-A7)
**Successor:** mandatory `M6-DEFN-R1-REV`, then the re-scoped `M6-CP1-CB4`
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`

## 1. Why a definition turn

The TB3 REDs, all `MissingIsolationSeamEquivalenceAuthority`, happen only at lattice nodes whose exact source support is a seam edge or seam vertex. At such a node a cell's corner wedge can span two isolation sheets. The frozen M6 definitions leave three things undecided:

- **§3.2/§3.3:** an occurrence carries exactly one `IsolationSheetId`, but no rule says which sheet a seam-incident corner gets. Every single-sheet rule picks a representative: the shared node face (pre-CB3 and M5) or the start face of the outgoing side (CB3).
- **§3.2:** `OrdinaryFront` has no isolation owner or certificate type.
- **§5 A7:** a multi-sheet class needs relation certificates and must never select a representative sheet. The split-square witness already contradicts this at single-occurrence seam vertices v0 and v2.

The CB4 plan's own stop rule applies. This turn decides the semantics; it does not implement them.

## 2. Decisions to freeze

Record the chosen option, the rejected option and the reason for each item.

1. **Occurrence sheet authority at seam-incident corners.** *Recommended:* a sorted, non-empty **corner-wedge sheet set** per occurrence. It is the sheets of the source faces covered by the cell's corner wedge between the last positive-length segment of the incoming side and the first positive-length segment of the outgoing side, around the exact support. An edge support covers at most two faces; a vertex support covers the contiguous fan arc on the cell's interior side. At every corner not on a seam it is a singleton, so current behaviour there is unchanged. *Alternative:* keep one sheet and justify completeness some other way.
2. **Where the certificate lives.** *Recommended:* on the occurrence wedge. The wedge's certificates are exactly the `(region, seam edge)` certificates of the seam edges the wedge fan crosses, each with a sheet pair equal to the sheets of the two faces it separates. This is unique by key, needs no search and picks no representative, including at interior seam vertices where two seam edges share a sheet pair. A crossed seam edge with no certificate is a typed A5 failure. *Alternative (relation-owned, the original CB4 model):* then freeze the owner type, whether it enters `OccurrenceRelationId`, and the vertex-support rule, and explain why assigning the certificate to a relation that does not cross the seam is authority rather than convention.
3. **A6 relation check.** *Recommended:* `OrdinaryFront` stays owner-less and `OccurrenceRelationId` is unchanged. For each endpoint pair, the sheet of the relation side's near-endpoint face must belong to **both** endpoints' wedge sets. This replaces the endpoint-sheet equality in `crossesSheets`. Mid-side seam crossings keep their current front-edge certificate evidence.
4. **Sides collinear with a seam edge.** `bounded_disk_chart_segment` breaks ties by the lexicographically smallest triangle (`SurfaceCellTracing.cpp:12648`), which is a representative face. Define the side's sheet per incident cell, or declare the case unsupported with a typed failure.
5. **A7 lineage completeness.** `sourceIsolationSheets` = union of member wedge sets; equivalence evidence = the wedge certificates. Amend the A7 sentence "relation certificates explicitly establish that equivalence" to name the actual certificate carrier.
6. **Single-face occurrence record.** An occurrence's point, support, chart, branch rotation and sheet provenance must come from one declared face, or be defined per wedge. Today (`660015f2`), sheet and support come from the outgoing face while `lattice.sourceChart` and `branchRotation` come from the node face (`RemeshPipeline.cpp:3330-3382`, `SurfaceCellTracing.cpp:16308-16335`).
7. **Row140 follow-ups.** Decide whether the M5 failure-string mapping for `HardRailOwnerMismatch` moves to the adapter (`RemeshPipeline.cpp:3749-3753`) and the A5 name becomes `Occurrence*`. Also set a policy for the three M5 checks A5 has made unreachable: `MissingHardRailRelationOwner`, the owner half of `InvalidPeriodicRelationOwner`, and the boundary-kind half of `IncompatibleAuthoritativeFrontPair` (delete, or keep as commented defence-in-depth).
8. **CB4/TB4 re-scope.** Rewrite the CB4 plan against the frozen rule. *Recommended:* pre-register one new focused identity asserting that split-square seam-endpoint vertices v0 and v2 record both sheets with wedge-certificate evidence. The gate becomes 7 focused + selector449 = 456 processes. The six existing focused identities and the selector449/routing449 bytes stay unchanged.

## 3. Required worked example (analytic, runtime-free)

Re-derive this table independently rather than copying it. State the assumptions: split-square chart uv = xy on [0,1]², 2×2 lattice (`SurfaceCellTracing.cpp:16222`), corner order BL, BR, TR, TL, side *s* running from corner *s* to *s*+1.

Setup: face 0 = (v0,v1,v2), below the diagonal, sheet 0. Face 1 = (v0,v2,v3), above the diagonal, sheet 1. The seam is edge e = (v0,v2).

Wedge sets under the recommended option, with the sheets of the incoming → outgoing faces:

| cell | corner 0 | corner 1 | corner 2 | corner 3 |
|---|---|---|---|---|
| c00 = [0,½]² | v0: {0,1}, cert e (1→0) | (½,0): {0} | (½,½): {0,1}, cert e (0→1) | (0,½): {1} |
| c10 = [½,1]×[0,½] | (½,0): {0} | v1: {0} | (1,½): {0} | (½,½): {0} |
| c01 = [0,½]×[½,1] | (0,½): {1} | (½,½): {1} | (½,1): {1} | v3: {1} |
| c11 = [½,1]² | (½,½): {0,1}, cert e (1→0) | (1,½): {0} | v2: {0,1}, cert e (0→1) | (½,1): {1} |

Expected lineage:

- multi-sheet {0,1}: v0 = {c00.0}, (½,½) = {c00.2, c10.3, c11.0, c01.1}, v2 = {c11.2};
- all other vertices single-sheet.

All eight endpoint pairs of the four interior relations must satisfy §2.3; for example (c00.2, c10.3) along the face-0 side has 0 ∈ {0,1} ∩ {0}.

Also give one interior seam-vertex example (a seam chain v_a–v–v_b separating sheets s|t) showing the wedge's certificate set is unique by key whether the wedge crosses one or both seam edges.

## 4. Must not change

`OccurrenceId = (CellId, canonicalCornerRole)`, `CellId`, `QuotientClassId`, relation-only quotient equality, HardRail/Periodic owners, the no-geometric-welding rule, selector449 (`d4a0d1b7...d6414`, 449 LF rows), routing449 (`9c88a5ed...c5707`), and all existing tests and fixtures. No source edits, compile, or Directional runtime in this turn.

## 5. Exit criteria (checked by `M6-DEFN-R1-REV`)

- Each of §2.1-§2.8 is decided with a reason. The amended text is in `Architecture_M6_Frozen_Definitions.md`, and the relevant parts of §3.2, §3.3, §3.4, §4 and §5 are updated consistently.
- The §3 worked example is reproduced independently, and any disagreement with this table is explained.
- The chosen rule is unique at edge **and** vertex supports and never selects a representative sheet.
- The CB4 plan is rewritten, with TB4 pre-registration and recovery-green shape.
- Stable accounting is unchanged at **54 / 16 / 38**, debt 1. No selector is published or accepted.

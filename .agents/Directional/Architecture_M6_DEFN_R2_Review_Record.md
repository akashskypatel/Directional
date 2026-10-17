# M6-DEFN-R2 Independent Review Record

**Turn:** `M6-DEFN-R2-REV`
**Type:** mandatory runtime-free independent Review (review agent)
**Disposition:** **ACCEPTED WITH REVIEW AMENDMENTS RA-1 – RA-10 / CB4 AUTHORIZED UNDER THE AMENDED PLAN / EXACT NEXT `M6-CP1-CB4`**
**Reviewed definition:** `Architecture_M6_DEFN_R2_Seam_Incident_Authority_Amendment_Definition_Record.md` plus the `M6-DEFN-R2` edits to `Architecture_M6_Frozen_Definitions.md` (commit `6ac2b339`)
**Accepted runtime authority (unchanged):** `10814505512 / e284fea7c101eb86650d1c87c92d0fefa66050e7`, selector449 **449/449 PASS**
**Candidate basis (unpromoted):** `10840014758 / 660015f2f15359fd426e2c855aea9f4201c70216`

## 1. Evidence re-opened

- **Definition snapshot:** run/artifact `36095854118 / 10847467936` has provider digest and download SHA-256 `a19261e0...75c2`. Its embedded `source.tar.gz` is `c0ca5581...ab1c` with **5,312** files. `RemeshPipeline.cpp`, `SurfaceCellTracing.cpp`, `PureQuadCompletion.h` and `SurfaceCellTransitionQuotientTests.cpp` are byte-identical to `660015f2`, and `git diff 660015f2 342a306e -- src include tests` is empty.
- **Selector/routing and focused tests:** selector449 `d4a0d1b7...d6414` and routing449 `9c88a5ed...c5707` are unchanged. The seventh identity is still absent from `tests/`.
- **Accounting:** stable accounting stays **54 / 16 / 38**, debt 1. This Review creates no runtime event.

## 2. What is upheld (independently re-derived)

- **B1 carrier.** `CornerWedgeIsolation` is evidence-only and carries ordered `(region, seam, fromSheet, toSheet)` transitions. Every existing equivalence consumer is kind-gated to HardRail/Periodic (`PureQuadCompletion.cpp:801/925/1019/1059`, `RemeshPipeline.cpp:5556/5624`, `SourceAuthoritativeMeshValidator.cpp:680`). Component aggregation guards negative front edges (`RemeshPipeline.cpp:14114/14123`). A `firstFrontEdge = secondFrontEdge = -1` entry is therefore safe, and row5 becomes satisfiable at v0 and v2.
- **B2 rules.** Each face-dependent consumer now has one declared rule: complete binding signatures for class keys, the representative key and `sourceCharts`; relation-side interior-face bindings for selected steps; path start/end from the first/last step. `chartComponent` is constant across an admissible wedge because isolation seams are not chart barriers, so `SelectedRelationStep` components are unchanged.
- **B3 orientation premise, proved in all three builders.**
  - Uniform: `SurfaceCellTracing.cpp:11834-11855` orients against `frame.normal`, which is the reference face's own normal (`build_planar_phase_frame`, `face_normal(vertices, faces, referenceFace)`).
  - Periodic (`:13799-13821`) and bounded-disk (`:16367-16392`) orient against the summed `face_normal` of the corner faces.
  - Source winding is globally consistent (`classify_source_surface_labels` rejects inconsistent winding, `:7388-7391`).

  The winding-selected interior face is therefore sound.
- **B4 split.** A5's relation failures become one-to-one and are mapped at the adapter.
- **P1/P2.** Ordered span evidence and reciprocal-agreement checks are sound.

## 3. Review amendments (normative; frozen into `Architecture_M6_Frozen_Definitions.md`)

Each amendment closes a gap where a literal CB4 implementation would fail a frozen gate, fail the witness fixture, or reintroduce ambiguity. None needs a new design choice or an unproved premise, so they are frozen here rather than routed to another Definition turn.

**RA-1 — boundary and region-boundary edges.** R2 §5.2 is written only for "an internal manifold source edge; require exactly two incident source faces". All eight perimeter sides of the split square are collinear with **source boundary edges** that have one incident face. Taken literally, the rule fails closed on the witness fixture.

*Amendment:* for a collinear span on
- an internal edge, the interior face is the incident face whose source winding contains the side's directed edge;
- a source boundary edge, the interior face is the single incident face, which must satisfy the same winding test;
- a hard-rail or topology-region-boundary edge, the interior face is the winding-selected incident face, which must also lie in the cell's `TopologyRegionId`.

Any failed test is a typed A5 failure.

**RA-2 — P3 must not key on vertex category.** In the codebase's own vocabulary, "excluded source vertices" means barrier vertices. `GlobalTopologyPlan.cpp:2343-2344` computes `total − interior`; on the produced torus that is 72 − 55 = **17** = 6 + 12 − 1 rail vertices, and rail vertices are lattice nodes there. A P3 keyed on "singular/excluded" vertices would fail the torus rows (444, 446, 448 and focused row6).

*Amendment:* `OccurrenceUnsupportedSingularWedge` fires only when the winding-order fan arc (RA-8) cannot be computed. That means a nonmanifold vertex fan, or an arc that is not contained in one `TopologyRegionId` and one chart component. It never fires because a vertex is on a boundary, barrier or hard rail. `OccurrenceUnsupportedSingularityPort` fires only for an A4 corner that participates in a SingularityPort relation; A5 currently produces none.

**RA-3 — P4 predicate.** "Unresolved seam-at-hard-rail corner" is undefined. *Amendment:* `OccurrenceUnsupportedHardRailSeamWedge` is exactly the case where the RA-8 arc would have to cross a hard-rail edge to connect the incoming and outgoing interior faces. For a validated cell this is unreachable, so it is a fail-closed assertion. A seam edge that ends at a rail vertex inside an admissible arc is ordinary wedge evidence.

**RA-4 — "structural hash" in the seventh identity.** `hash_completion` hashes `SurfacePoint::face` (a source-face row; `hash_surface_point`, `RemeshPipeline.cpp:1913-1923`, applied at `:2655/:2683`) and equivalence front-edge indices (`:2711-2712`). It is not invariant to face-row permutation, so asserting that it is invariant fails by construction.

*Amendment:* the permutation clause compares only row-invariant semantic data:
- `OccurrenceId`s;
- per-`OccurrenceId` `CornerWedgeSheetSet` and ordered `CornerWedgeIsolation` transition tuples;
- per class (keyed by sorted member `OccurrenceId`s): lineage `sourceIsolationSheets` and the `CornerWedgeIsolation` transition tuples.

CB4 may add **one test-local split-square fixture helper with reversed face rows**, sheet labels permuted with the rows, used only by the seventh identity. Existing fixtures stay byte-unchanged.

**RA-5 — the `OccurrenceUnownedRelation` name, and frozen focused row3.**
- R2 §6 maps `OccurrenceUnownedRelation → "UnownedRelation"`, but no such M5 string exists (accepted `e284fea7` has none). The current external name is `OccurrenceUnownedRelation` (`RemeshPipeline.cpp:3051`, `:4099`). *Amendment:* keep `OccurrenceUnownedRelation` as its external name; there is no legacy remap.
- Frozen focused row3 (not covered by the R2 audit) pins enum `UnownedRelation` for a malformed relation identity: `id.first` rewritten, detected by `relation.id != expectedId` at `:3190` (test at `SurfaceCellTransitionQuotientTests.cpp:2092-2103`). *Amendment:* the enum member `UnownedRelation` is kept. It continues to cover relation-identity/owner-encoding mismatch in `publish_records_for_validation`. The new owner/kind codes apply only to the producer-side conditions R2 §6 names. The out-of-range opposite edge becomes `RelationEndpointMissing`.

**RA-6 — lineage sheets are the wedge union only.** R2 §4.5 says `sourceIsolationSheets` is derived from binding tuples "plus already-verified side/wedge transitions". Frozen §5 says it is the union of member `CornerWedgeSheetSet`s. The two disagree whenever a side crosses a seam mid-span: that side's `fromSheet`/`toSheet` would widen the lineage of endpoint vertices whose own wedges are single-sheet.

*Amendment:* frozen §5 governs. Side transitions are `equivalences` evidence only and add no sheets.

**RA-7 — retire the M5 endpoint-equality guard explicitly.** The transitional `crossesSheets` guard (`RemeshPipeline.cpp:4180-4191`) compares single occurrence sheets. It must be removed and replaced by the RA/R2 span-membership validation, not adapted to a representative sheet.

Under R2's own B4 principle, the A6 failure that replaces it maps at the adapter to the legacy name it supersedes:
- missing seam evidence for a cross-sheet step → `MissingIsolationSeamEquivalenceAuthority`;
- a named certificate absent or wrong → `InvalidIsolationSeamEquivalenceAuthority`;
- reciprocal disagreement (`QuotientReciprocalSideAuthorityMismatch`) keeps its new name. It has no M5 predecessor.

**RA-8 — wedge fan endpoints and direction.** Frozen §3.2 still says the wedge spans "between the last positive-length incoming side segment and first positive-length outgoing side segment".

*Amendment:* the arc endpoints are the **interior faces** of the incoming side's last support span and the outgoing side's first support span. For a collinear span that face comes from RA-1; otherwise it is the face containing the span's open interior. The arc runs in source-winding (counter-clockwise) order from the outgoing interior face to the incoming interior face around the corner support, which is the side containing the cell interior for a validated cell. The recorded transition orientation stays incoming → outgoing as in the DEFN-R1 table (v0 `1→0`, v2 `0→1`).

**RA-9 — "exact" support is resolver-defined.** Span and occurrence supports are resolved by `SurfacePointSourceSupportResolver`, with default barycentric tolerance `1e-8` (`SurfacePointSupport.h`). R2's "no tolerance participates" is inaccurate. *Amendment:* the support-span rule is defined **by that resolver, applied to each span's open-interior midpoint and both endpoints**. The span is edge-collinear iff all three resolve to the same `SourceEdgeSupport`, or the endpoints resolve to that edge's closure. The builder's own tie-break tolerance is irrelevant.

**RA-10 — the transitional `QuotientClassId` stays as it is in CB4.** The semantic `QuotientClassId` is the sorted member set (frozen §4.3). CB4 keeps today's transitional ordinal in `lineage.quotientClass`, and in its hash, unchanged in representation. Only the class-key tuple feeding the ordinal changes (complete binding signatures). Realizing the member-set identity as a product type belongs to A6 extraction, not CB4.

**Accuracy note (no amendment).** R2 §8 says row444's selected certificate is "unchanged signature/hash". Relation-local `startChart` changes certificate content relative to M5. Rows 444/448 compare within one candidate, so they remain satisfiable, but the certificate is not byte-identical to M5.

## 4. Frozen-test audit extension

The R2 audit omitted focused rows 1-4.
- Row 1 (four semantic corners, square fixture) and row 4 (coincident unrelated occurrences, overlap fixture) assert only identity, count and distinctness. Wedge sets are singletons on those fixtures, so both stay satisfiable.
- Row 2 compares semantic IDs only, so it stays satisfiable.
- Row 3 stays satisfiable only under RA-5.

With RA-1 – RA-10 the audit covers all seven focused identities and selector rows 140, 186, 214, 239, 444, 446 and 448.

## 5. Successor

Exact next: runtime-free **`M6-CP1-CB4`**, under the amended CB4 plan authority now folded into `M6_Consolidated_Record.md` §§12-18. Compile-green → immutable `M6-CP1-TB4-EXEC` (7 + 449 = **456**) → mandatory `M6-CP1-TB4-REV`.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector449 `d4a0d1b7...d6414`; routing449 `9c88a5ed...c5707` |
| Decisive claims independently re-derived | snapshot `10847467936` digest/archive/5,312 files and byte-identity to `660015f2`; kind-gated consumers and front-edge guards; orientation premise in all three builders; row3 malformed-ID path; `hash_completion` row dependence; excluded-vertex semantics (72 − 55 = 17 rail vertices); resolver tolerance; absence of an M5 `"UnownedRelation"` string |
| Non-vacuity checked | RA-1 (8 perimeter sides), RA-2 (torus rail nodes), RA-4 (face-row hash) and RA-5 (row3) each name a frozen gate that a literal implementation would fail |
| Prior obligations discharged/carried | DEFN-R1-REV B1-B4 and P1-P4: discharged by R2 as amended by RA-1 – RA-10 |
| Stable accounting | **54 / 16 / 38**, debt 1; +0 |
| New candidates/obligations recorded | RA-1 – RA-10 frozen; CB4 plan amended; tracker +0 entry |
| ORIENTATION currency line | `M6-DEFN-R2-REV`, 2026-09-25 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 and §8 updated; §4 n/a |
| CHANGELOG | root and Directional prepended |
| ROADMAP | status line and M6-CP1 row updated |
| Selector manifest | n/a |
| LESSONS | existing 179/180 apply; no new lesson |
| Consolidation under CLEAN_UP_POLICY | consumed `Architecture_M6_DEFN_R2_Amendment_Plan.md` folded into `M6_Consolidated_Record.md` and removed; DEFN-R1/R2 records and the DEFN-R1 review retained as the definition chain; CB4 plan is the single live successor plan |
| Successor frozen | exactly `M6-CP1-CB4` (amended) |
| Turn boundary held | runtime-free; no source/test/fixture/selector/benchmark/build mutation; no compile or Directional runtime |
| review_check.py boundary / ledgers | recorded in the review commit message |
| `STATUS` lifecycle maintained | entry `M6-DEFN-R2-REV / IN_PROGRESS` (operator handoff `2026-09-25T05:33:36Z`) → docs → COMPLETE last |
| Pushed to origin, branch in sync | verified after the final push |

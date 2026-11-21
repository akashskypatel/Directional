# TB-REV-156 adversarial review — CB-173 frozen exactly (2026-11-21 UTC)

**Turn:** `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE`, continued after handover to the review agent. Runtime-free: only `-fsyntax-only`, `git apply --check` and reading immutable records.

## Situation — the gate verdict stands; the successor plan is withdrawn and replaced by an exact diff

The [TB156 independent review](Architecture_M6_CP3_TB156_P13_Slide_Carrier_Cut_Admissibility_Full_Gate_Independent_Review_20261121.md) correctly qualifies TB156 GREEN. TB156 met every one of RA-280's STOP criteria and predictions:
- 972/972 PASS.
- 960/960 rows outside the allowance MATCH TB154.
- Rows 644/645/669/686/698/858 MATCH TB154. Row 966 differs only by its oracle line.
- Row 972 printed exactly `carriers=10 classified=10 selected=0 outcome=CutSearchExhaustedBeforeCellularity`.
- Census 3/3 MATCH. No guard reason names appear in any log.

CB-172B's source on HEAD equals its frozen postimages. The successor it froze, the [CB-173 plan](Architecture_M6_CP3_CB173_P13_Stop_Switch_Ray_Helpers_Code_Build_Plan_20261121.md), is not a frozen turn. It is **withdrawn** and replaced by the exact CB-173 diff below.

## Findings

**V1 — The successor is a prose plan (design, major).** RA-281 required TB-REV-156 to "freeze the stop-switch helper CB exactly". The plan has no diff, no function name, no test body and no preimage. It leaves the decisive convention open ("subject to the actual existing orientation conventions"). It also adds scope that has nothing to do with a rotation key: chart/sheet isolation, hard rails, endpoint reversal. Its falsifier F3 contradicts the required arithmetic. Adding two edge rays *must* move each into-face primary from `side` to `2·side+1`, and F3 would STOP on exactly that change.

**V2 — The plan would build a parallel helper for geometry that already exists (architecture, major).**
- `edge_piece_ray` (`EmbeddedGraphTopology.cpp:2575`) already classifies a piece along the locus edge exactly, as `EdgePieceRayAlongLocusEdge{towardSecondEndpoint}`. CB-169 tests cover it (`FieldAlignedCarrierOccupancy` rows 968/971).
- The only missing part is the key rule. Today the edge-locus branch fails such a ray closed with `RayRunsAlongLocusEdge` (`:3172`). No TB156 log contains that reason.
- An "unwired helper" would duplicate the edge-arc slot arithmetic (`:3138`) and the into-face arithmetic (`:3209`, `:3060`), and a second switch CB would then be needed to wire it.
- The correct turn routes every site through the same three pure helpers and replaces the fail-closed branch in one diff.

**V3 — The stop switch itself is still undefined (forward sequence, major).**
- TB-REV-156 names "a separate stop-switch CB" with no definition. The only description is TB149's prose: the moving trace ends at its entry with `carrierLocus`, and the wall is split via `carrier_contact_slide_position`.
- That definition is the critical path to χ+4. TB-REV-157 must freeze it exactly as an unwired helper with a test that reaches it, and without TB149's cut-binding clause (RA-281 F3).

**V4 — Neutrality is claimed only for the gate (accuracy, minor).**
- The new pre-pass and composition check run before the existing per-ray checks on the edge-locus path.
- A row that currently fails at an edge locus could therefore report a different reason, even though no current log names `RayRunsAlongLocusEdge`.
- The TB157 rule "rows 1–972 MATCH TB156 with an empty allowance" is the falsifier. Any difference is a STOP for Review, not a waiver.

**Upheld:** TB156 GREEN in scope; RA-279-C1/C2 narrowly discharged; RA-281 F1/F2 (Amendment 14 interim restriction) carried; no CP3/497/D0/H4 promotion.

## Frozen CB-173 — edge-locus along-edge ray key

`M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS` (Code + Build, compile only). Apply exactly [`Architecture_M6_CP3_CB173_P13_Edge_Locus_Along_Edge_Ray_Key_Exact.diff`](Architecture_M6_CP3_CB173_P13_Edge_Locus_Along_Edge_Ray_Key_Exact.diff), SHA-256 `83adf365f6b9924294ce71c238628edd5fa155860f96239b00fcb92df7eb0a59`.

| File | numstat | Preimage (HEAD) | Postimage |
|---|---|---|---|
| `src/geometry/EmbeddedGraphTopology.h` | 24/0 | `68b6c5048cb193f3788d42649144866c0858f17b947a4a47eab83155f05eb287` | `592daad7b202ff866f9f0175b790b5d71262d9f447a4895860237d4a8d899da5` |
| `src/geometry/EmbeddedGraphTopology.cpp` | 87/13 | `f0599d1ac45d006899f03190efdc01c47fdcb0f9ce281dbc4502513876179a0b` | `1ef094afe1a0917c07a67c2d95fcb53f00330e8fc240a8b40c8547110bf64de7` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | 41/0 | `4accff96f83183f5d0bf1ba745a65c61063d0470745c701fe8ea59befbc11af0` | `20a11166bb1a29a3689baf2e1c6aa8bb0a230d9b94e627b9200a56e276a8824c` |

**Rule.** At an edge locus, a trace ray along the locus edge is an edge ray:
- **Slot:** it takes the edge-arc slot of its direction, `edge_locus_edge_ray_primary`: 0 toward the second endpoint, 2 toward the first.
- **Count:** it counts in `edgeRayCount`, so into-face rays take `edge_locus_into_face_primary` = `2·side+1`.
- **Composition:** (arc edge rays, along-edge trace rays) must be (0,0), (2,0) or (0,2) (`edge_locus_edge_ray_composition_valid`); anything else fails with the existing `RotationEdgeRayCountInvalid`.
- **Same direction:** two along-edge trace rays in one direction fail with the existing `RotationTraceRaysAlongSharedEdge`.
- **Failure paths:** every other path is unchanged. `RayRunsAlongLocusEdge` stays declared, but this path no longer produces it.
- **Untouched branches:** vertex-locus and face-contact branches are unchanged.

**Tests** (`directional_surface_cell_producer_tests`):
- `EmbeddedGraphTopology.EdgeLocusAlongEdgeTraceRaysTakeEdgeArcSlots`
- `EmbeddedGraphTopology.EdgeLocusIntoFaceRaysInterleaveWithEdgeRays`: the four-ray order 0..3, plus the collision the count prevents.
- `EmbeddedGraphTopology.EdgeLocusEdgeRayCompositionAdmitsOnlyThroughPairs`: the full 3×3 table.

**Unwitnessed:** no current gate fixture places an edge-locus node on a slide, so the wired branch has no witness. The stop switch is its first witness, and its TB must reach it.

**Checks:** `git apply --check` passes on HEAD. `-fsyntax-only` (Homebrew clang 23, CMake-derived flags with the GMP defines) gives 0 errors before and after on both translation units, with identical warning sets (3 and 9).

## TB-EXEC-157 STOP criteria (frozen)

`M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` on the CB-173 package, manifest [TB157](gates/Architecture_M6_TB157_P13_Edge_Locus_Along_Edge_Ray_Key_Full_Gate_Case_Manifest.tsv) (SHA-256 `92eb18e8aaf2881d933c88dfde1a86b957334fe6785fd88f404459812cdc50c7`, 975 rows): the TB156 manifest bytes plus rows 973–975. STOP unless all of the following hold:
1. 975/975 PASS, and CP2 491/491.
2. Rows 1–972 MATCH TB156 (artifact `14715014772`) under N1–N3, with an **empty** allowance; this includes row 972's receipt verbatim.
3. Census 3/3 MATCH TB156 (`14716036015`) under N1–N4, including `platform-digest`.
4. No `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge` or `FirstPieceNotLeavingLocusIntoFace` in any log.

## Turn sequence

| Step | Turn | Scope |
|---|---|---|
| NEXT | `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS` | Exact diff `83adf365…0a59`; compile only. |
| then | `M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` | TB157 manifest; the STOP criteria above. |
| then | `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` | If green: freeze the stop-switch helper CB exactly (V3). It is unwired: the moving trace ends at the wall contact with `carrierLocus` and the wall splits at `carrier_contact_slide_position`. It needs a test that reaches the composition-(0,2) edge-locus node, and drops TB149's cut-binding clause. |
| prospective | stop-switch helper CB → stop-switch wiring CB → TB/REV → slide-start subdivision CB (R1; deletes the Amendment 14 interim restriction) → TB/REV → slide-plan conformity (RA-275 S4a) → O48 carrier turns | χ+4 closes with the stop switch; O49 held. |

## Lessons

- Before scoping a helper, grep for the geometry classifier the missing rule would consume. If it exists and is tested, freeze only the key rule and route every site through it.
- A Review that is told to freeze a CB exactly has not finished until a diff with hashes exists. Withdraw a prose successor rather than forwarding it.
- When a change moves a check earlier on a failing path, a "no log names the old reason" argument does not prove neutrality. Give the TB an empty allowance.

## Review closeout

| Duty | Answer |
|---|---|
| Decisive claims re-derived | TB156 predictions vs. the report; CB-172B postimages on HEAD; `edge_piece_ray` along-edge classification and its tests; edge-locus key sites `:3016/:3060/:3138/:3172/:3209`; apply-check and syntax-check of CB-173. |
| Prior obligations | RA-281 F3 discharged by CB-173 (rule) and pending witness; F1/F2, RA-275 S4a, O47/C5/O48/O49, χ+4 carried; V3 assigned to TB-REV-157. |
| Stable accounting | 66/17/49; debt 1; deferred 81; CP2 491/491; no promotion. |
| Turn boundary | Runtime-free; documents, diff and manifest only. |
| Successor | CB-173 (exact). |

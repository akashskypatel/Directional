# TB-REV-171 — adversarial continuation (2026-11-23 UTC)

Continues turn `M6-CP3-TB-REV-171-P13-ALONG-EDGE-FACE-PIECE-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_171_Along_Edge_Face_Piece_Independent_Review_20261123.md). Runtime-free: source reading, an SHA-checked read of the TB169/TB170/TB171 artifact logs (Haiku extraction), and `clang++ -fsyntax-only`. No product binary was built or run.

## Verdict

- **Upheld:**
  - TB171 rejection: 987/994, the same seven mechanical controls RED; accounting 67/17/50.
  - CB-192's classification: an along-edge face piece is not a chord.
- **Mechanism located (B1–B3):**
  - CB-192 removed 52 false chords, which also removed the far-side orbit those chords had credited to 38 faces.
  - Orbits 1, 3, 4 and 5 are thin "lens" regions, each bounded only by two trace arcs. At least one of them now owns no source face, so `RegionElectedCutComponentEmpty`.
  - What remains undecided is whether those lenses have area. That decides the repair (B4).
- **Withdrawn:** the independent review's prose CB-193 (field wish-list, no diff).
- **Replaced by:** exact test-only receipt **CB-193** that prints the deciding datum (B5), then TB-EXEC-172 on the unchanged 994-row manifest.
- **Corrected in the record:** my TB-REV-170 adversarial A3 said the repair leaves the owner set unchanged. It does not (B2).

## Findings

**B1 — The empty draft must be a trace-bounded lens orbit.**
- From the row-652 exception (TB171 artifact `14799346720`, ZIP SHA verified):
  - There are 6 orbits, none exterior.
  - Unlabeled components seed only orbits **0** and **2**: 9 components, 224 faces.
  - The arc orbit pairs are 14 (0|1), 17 (2|1), 22 (0|3), 16 (2|3), 18 (0|4), 25 (2|4), 23 (0|5) and 21 (2|5).
- So each of orbits 1/3/4/5 is bounded by exactly two trace arcs: one facing orbit 0 and one facing orbit 2. The pairs are traces 0/3, 8/2, 4/11 and 9/7.
- None of these orbits can receive a face from an unlabeled component. They own faces only through trace-visit fragment orbits. `owned[draft]` is built only from `fragmentOrbits` (`GlobalTopologyPlan.cpp:1594–1614`).

**B2 — How CB-192 removed their faces.**
- Per-face diff of row 652's exception records, TB170 against TB171:
  - 52 faces lost chords: 48 went 1→0 and 4 went 2→0.
  - On 38 of them the owner count fell, 34 from 2→1 and 4 from 3→1.
  - Total owners went 114→76.
- The false chord credited **both** arc orbits to the visited face. The along-edge visit credits only `edgeSideOrbit`, the visited face's side.
- Every visited face here is on the 0/2 side, so the lens orbit lost its last face.
- My A3 claim "owner set unchanged" held only for arc 15, whose two orbits are equal. It was false for every arc with distinct orbits.

**B3 — The design gap is one-sided crediting, and the code already has the two-sided rule.**
- For cut-graph arcs on a source edge, `GlobalTopologyPlan.cpp:1061–1098` credits **each** incident face with the dart on its own side.
- The CB-187/188 slide model, and CB-192 with it, credits only the face the trace segment names. The face across the edge is never credited.
- Before CB-192 the false chords hid this, by putting the far orbit on the wrong face. **TB169's green for the seven controls rested on that misreading.** It must not be restored by reverting CB-192.

**B4 — Two hypotheses lead to different repairs.**
- **H-strip:** the two bounding traces run along *different* source edges, with source triangles between them.
  - Repair: credit the face across each along-edge visit's edge with the other orbit, mirroring the B3 rule.
  - Exact CB, with a falsifier test.
- **H-lens:** the two bounding traces run along the *same* source edges (co-traced arrivals, K5). The lens has zero area and no source face can belong to it.
  - Then the fix is upstream: merge co-traced arcs, or make region election not create a draft for a sourceless orbit. That is a region-contract decision, so take it to Review and, if it changes a user-owned contract, to the user.
- The current logs cannot separate the two:
  - TB169 prints only `region_support_projection` counts, with no orbit or face lists.
  - TB171 prints per-face counts, not edges.

**B5 — CB-193, exact test-only receipt.**
- When the mechanical fixture fails with `RegionElectedCutComponentEmpty`, `build_cp4c_production_fixture` appends `append_along_edge_visit_receipt`.
- That receipt rebuilds the same embedded graph (`build_embedded_graph_topology` with the cut graph's `cut_edges()`) and runs the same classifier (`arc_face_visits`) with the face-walk orbits.
- For every trace-arc visit without a cut, it prints `trace`, `arc`, `visit`, `face`, the source `edge` both piece ends lie on, `sideOrbit`, both arc orbits, and the `oppositeFace` across that edge. There is a cap of 160 visits plus a count.
- It is read-only and appends only to an exception that is already thrown, so no verdict can change.
- Negative check: the receipt runs only on that detail code, so all other rows keep their transcripts.

**B6 — Not a cause: faces `0-1-102` and `25-30-31`, still deficit 1.**
- These are the last segments of traces 1 and 5, both `terminalSlit=false`. The deficit is the existing observational ceiling (TB-REV-167), not part of the empty draft.

## TB-EXEC-172 rules (frozen)

1. Use the unchanged TB171 manifest `704dcf6c…09c6` (994 rows). Membership is 1075. The same 7 rows are RED (445, 652, 653, 656, 658, 660, 786); 987 PASS.
2. Every row equals TB171 `14799346720` under N1–N3 with zero allowance, except **appended `alongEdgeVisit*` fields** at the end of exceptions whose `detailCode=RegionElectedCutComponentEmpty`. Any other difference → STOP and return to Review.
3. Report row 652's receipt verbatim. `alongEdgeVisitsTruncated=false` is expected; if it is true, report that.
4. No census, no repair, no rebuild.

## TB-REV-172 decision rule (frozen)

For each lens orbit o ∈ {1, 3, 4, 5}, take the receipt rows of its two bounding arcs:
- **Different edges** (H-strip): freeze an exact repair that credits `oppositeFace` with the visit's non-side orbit, mirroring `:1061–1098`. Check the per-face ceiling (`fragmentOrbits ≤ pieces+1`) against every receipt row before freezing. This is a narrow repair, with no receipt in the same CB.
- **Same edges** (H-lens): no region-reader repair. Freeze the upstream co-traced-arc decision. Ask the user if it changes the region contract (RA-233).
- Mixed: decide per orbit; no blanket rule.

## Turn sequence

1. **CB-193**: exact receipt, compile only.
2. **TB-EXEC-172**: rules above.
3. **TB-REV-172**: decision rule above → exact repair CB → TB.
4. After the mechanical controls are green again: row 979 `RegionContainsInteriorSingularity` (vertex 8). Read its printed locus first. Then Branch A only after the staged plan builds.
5. **CB-190** stays off the critical path.

## Lessons

- When a repair removes a misreading, list what the misreading supplied by accident (here, far-side orbit evidence) before predicting the gate (RA-220).
- An edge-coincident arc separates two faces. Credit it the way the code already credits cut arcs on edges: both incident faces, each with its own side.
- A receipt for a region failure should print the datum that separates the competing repairs, not every field near the failure.

# TB-REV-165 — adversarial continuation after handover (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-165-P13-NEAREST-CHORD-SEED-FULL-GATE` after the [review record](Architecture_M6_CP3_TB_REV_165_Nearest_Chord_Seed_Full_Gate_Review_20261122.md) (G1–G5). Runtime-free: source reading, DESIGN, the TB163–TB165 receipts, Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **Upheld:**
  - the acceptance of the nearest-chord seed switch;
  - the F1a/F1b oracle correction;
  - G1 (Z6 closed);
  - G5 (activation waits until the staged plan builds).
- **Corrected:** G2's reading of the singular corner (K2).
- **Withdrawn:** G4's plan to classify faces and freeze one corner helper per class. One boundary-walk partition replaces it (K3).
- **Withdrawn before any implementation:** CB-185 v1. It cannot support that partition or decide the singular-arrival question (K4, K5). An exact v2 replaces it. No implementation turn had started, since STATUS was held by this Review.

## Findings

**K1 — the F1 adjudication is upheld.**
- A component census is Established only when its owner set is a singleton.
- Components 0, 2, 3 and 4 already had a non-nearest seed, and the branch order leaves those seeds unchanged. So each of the 21 extra seeds agrees with them.
- Every seed in TB165 also passed CB-183's unordered-face exclusion, which the helper requires before it seeds.

**K2 — G2 misread `end=point`.**
- The row-979 printer tests `terminalPoint` before `terminalSingularity` (`tests/FieldAlignedCurveNetworkTests.cpp`, `SphereStagedTrace` block).
- Every site that sets `terminalSingularity` also sets `terminalPoint`. The sites are `SurfaceCellTracing.cpp:2689–2697` and `:2787–2794` (vertex hit and edge slide), `:3623–3631` and `:3805–3812` (proposal path), and `:4831–4832` (commit).
- So `end=point` cannot tell a point stop from a singularity termination.
- Ten traces print `slides=1 end=point` and have a last arc ending at a singularity node: traces 0, 1, 9, 10, 11, 12, 13, 14, 21 and 22. Read with DESIGN §7.2 step 5 and DESIGN :152 ("transits along the edge to the endpoint … terminating if that vertex is a singularity"), these are designed singularity terminations reached by an edge slide. They are not an anomaly.
- Corrected picture of face `6-8-9`:
  - two face pieces, from traces 0 and 9, each ending on an edge at the singular corner and continuing as an edge slide into node 1;
  - two port rays, from traces 3 and 4, leaving that corner;
  - trace 0's edge-only piece (arc 1), which cuts no face interior.

**K3 — one decomposition, not a list of classes (RA-217).**
- G2 and G4 planned to classify faces (nested chords, corner fan, edge-only, mixed) and freeze a helper per class. Those classes are symptoms, not a design.
- Each face piece of a trace arc is a non-crossing cut through the triangle, with two boundary endpoints: an exact point on an edge, or a corner. Edge pieces cut nothing (G3).
- Ordered cyclically along the triangle's boundary, the endpoints form a laminar structure. Each boundary interval between consecutive endpoints lies in one region, whose orbit is the side orbit of the cut bounding it. A corner owns the orbits of the intervals next to it.
- The existing one-chord rule and the ray-fan rule are both instances (`GlobalTopologyPlan.cpp:588–596`, `:648–653`), and so are nested chords and mixed faces.
- Ties, crossings and missing placements stay typed rejections.
- This is the rule TB-REV-166 must freeze, as one pure exact helper (CB-186) plus a stacked reader switch (CB-187). Its side convention must be reconciled with the existing `turn`-based convention (RA-274).

**K4 — CB-185 v1 measured too little.**
- It printed only entries. With no exit point, no position along each edge, and no singular-node data, TB-REV-166 could neither predict the boundary-walk result per face nor decide K5.
- v2 adds:
  - each visit's exit support;
  - the edge parameter of entry and exit, rounded and labelled for ordering by eye only (the decision itself is exact, in the helper);
  - each port's departing first segment;
  - each arrival, with an explicit `terminalSingularity` flag;
  - a per-node valence line.
- Orbits per arc are already published by the plan locus `fragmentOwnerArc` records in row 979.

**K5 — a new open question: valence and co-traced arrivals.**
- The published arc table gives singular-node arc ends 4, 5, 5, 3, 3, 5, 5, 4 at nodes 0–7, against 3 ports each (index +1). That is 10 arrivals.
- DESIGN permits arrivals at a singularity (§7.2 step 5). No stage checks arcs at a singular node against port count (Haiku: `GlobalTopologyPlan.cpp` has no such check; `SurfaceCellTracing.cpp:5351` only range-checks `4 − index`).
- One configuration would be a real A2a defect that the plan reader must not hide: an arrival sliding into the vertex along the same radial edge on which a port departs (an edge-supported port). The two would overlap along that edge, the overlapping traces DESIGN :152 says must be counted and published, and they would bound a zero-area region.
- v2 publishes both slide edges side by side.
- Decision for TB-REV-166:
  - **no overlap:** arrivals are ordinary cuts for K3;
  - **any overlap:** typed STOP, routed to A2a (network producer), and no plan-reader change for that face.

**K6 — G1 and G5 hold.**
- G1 is sound. Each of nodes 0–7 starts exactly 3 traces, and the vertex-12/37 stars report `interiorArcs=0` and `vertexTransits=0`.
- G5 is sound. Activating before the staged plan builds would only move the production failure.

## Frozen artifacts

| Artifact | SHA-256 | Content |
|---|---|---|
| `Architecture_M6_CP3_CB185_P13_Staged_Multi_Cut_Face_Receipt_Exact.diff` (**v2, replaces v1 `77e025a8…159d`**) | `a7a5922b791ab57d473fc0a8004785977110e8c74922eff39e73df14fcb9935a` | 7,830 B, +156/−0, test-only (row 979) plus `#include <iomanip>`. Prints `SphereStagedMultiCutVisit` (pieces, carriers, slide, `entry=`/`exit=` as `v<id>` or `edge@t`, `last=`), `SphereStagedMultiCutFaces`, `SphereStagedSingularPort` (node, vertex, index, ordinal, trace, first face, outgoing, slide), `SphereStagedSingularArrival` (node, trace, arc, last face, slide, `terminalSingularity=`) and `SphereStagedSingularValence` (ports, arrivals, arcEnds). Test `fea486ed…68e27` → `c62c51b0d549b4a41cce5e7e1b9d087d968b5881a794fb4c460950c8d143ffe2`. |
| Gate manifest | `8d56ee1d911daa1bd3cab9f824e79131ce9f75bd7a57b31b5882d3f4f52b1e69` | The TB165 984-row manifest, unchanged. |

Checks (Haiku, worktree at `7432ce8f3`): the preimage matches. `git apply --check` and `git apply` pass, and the postimage hash was recomputed. `-fsyntax-only` (clang, C++20, `-Wall -Wextra`, GMP defines) gives 0 errors and 42 warnings before and after, with identical normalized warning multisets. Nothing was built or run.

## TB166 rules (replace the TB-REV-165 record's rules; STOP unless all hold)

1. 984/984 PASS; CP2 491/491; membership 1065.
2. Rows 1–978 and 980–984 equal TB165 artifact `14762295772` under N1–N3, with zero allowance.
3. Row 979 equals TB165 row 979 under N1–N3 after deleting only the `SphereStagedMultiCutVisit`, `SphereStagedMultiCutFaces`, `SphereStagedSingularPort`, `SphereStagedSingularArrival` and `SphereStagedSingularValence` lines.
4. Publish every new line verbatim. Predictions:
   - face `6-8-9` appears with visits from arcs 0 (`FE`), 1 (`E`), 5, 6 and 12 (`FE`);
   - each of the 16 component-1/5 opposite faces (listed in the review record) has at least two visits;
   - 24 `SphereStagedSingularPort` lines;
   - `SphereStagedSingularValence` for nodes 0–7: `ports=3`, `arrivals=` 1, 2, 2, 0, 0, 2, 2, 1, `arcEnds=` 4, 5, 5, 3, 3, 5, 5, 4;
   - 10 `SphereStagedSingularArrival` lines, for traces 0, 1, 9, 10, 11, 12, 13, 14, 21 and 22, each with `terminalSingularity=1`.
5. No census: product source is unchanged.
6. Any failure means STATUS BLOCKED and a return to Review. A `terminalSingularity=0` arrival is reported verbatim, not repaired: it would be a trace bound to a singular node without a singular termination.

## TB-REV-166 decision map

| Signature | Decision |
|---|---|
| Rule 4 holds and no arrival shares a slide edge with a departing port | Freeze CB-186, the boundary-walk corner partition helper (pure, exact, with positive and negative tests, including the 6-8-9 and nested-chord configurations). Freeze CB-187, which switches `build_fragment_corner_incidence` to read arc face pieces through it. |
| An arrival shares a slide edge with a departing port | Co-traced overlap (K5): typed STOP, route to A2a. No plan-reader change for that face. |
| `terminalSingularity=0` on an arrival, or a valence mismatch | Node binding without a singular termination: route to A2a. |
| A face whose cuts cross or tie | The typed rejection stays; the receipt names it. |

## Turn sequence

1. CB-185 v2: test-only receipt (compile only).
2. TB-EXEC-166: 984 rows; no census.
3. TB-REV-166: decision map above.
4. CB-186: boundary-walk helper.
5. CB-187: reader switch (compile only).
6. TB-EXEC/REV-167: staged plan built, or the next stage.
7. CB-188: activation (V3/V4/V5/V10/V11).
8. TB-EXEC/REV-168.
9. CB-189: V3b.
10. R1, then O48.

## Lessons

- A printer that tests fields in a fixed order can hide one state behind another. Read the printer before you read its label.
- When a reader fails on several configurations, look for the single decomposition they share before you freeze per-class rules.
- An arrival at a singular node adds valence the index does not supply. Before admitting it downstream, check that it does not overlap a departing port.

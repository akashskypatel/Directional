# RA-232 — Completed-mesh gate, O41 (step 64E.6)

Turn `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE`, Review agent only, runtime-free. Input: [TB113](Architecture_M6_CP3_TB113_P13_A4_Completed_Mesh_Gate_Census_Full_Gate_Execution_Report_20261112.md) (945/945, scoped MATCH; 46/46 earlier receipt lines unchanged; ten `switch-validation` lines). RA-231 §6.

## 1. What TB113 showed

Gate limits (`SurfaceMeshOptimizer.cpp:2933`):
- field median ≤ 7.5° and p95 ≤ 15°;
- size between 0.5 (p5) and 2.0 (p95);
- angle p5 ≥ 35° and p95 ≤ 145°;
- scaled Jacobian p5 ≥ 0.20;
- the rest as listed there.

| Run | Failing measures | Everything else |
|---|---|---|
| MultiFaceSeam chained | **size p5 = 0.434** | passes (field 0/0, angles 90/90, Jacobian 1/1) |
| SmoothRimDisc per-arc and chained, identical | **field = 16.52°/29.20°**, **size p5 = 0.292**, **Jacobian p5 = 0.19509** | angle 45.35°/135.44° and aspect 1.82 pass |
| Plane chained (passes) | size p5 = 0.534, close to the 0.5 limit | per-arc size range 0.658–1.300, chained 0.534–1.038 |

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **O41 is two problems with different causes.** The disc fails three measures, identically under both schedules. MultiFaceSeam fails only size p5, and only under chains | TB113 lines |
| F2 | **The disc fails because of the fixture, not the producers.** Three facts, each derived independently: | |
| | (a) The bounded-disk producer cuts the round rim into four sides at the field corners, and each corner cell takes the rim's interior angle there, 180° − 360°/32 = 168.75°. Its scaled Jacobian is sin 168.75° = sin 11.25° = 0.19509, exactly the measured min and p5. Four corner cells out of about 64 are more than 5%, so p5 equals the minimum | |
| | (b) The field is constant and the rim turns 360°. With every boundary edge on the rim and no interior singularity (a 4-cornered disc needs none), the mesh frame must turn with the rim. A median misalignment of about 16° is the cost of spreading that turn over a single patch | |
| | (c) Size p5 0.29 comes from the same squeezed corner cells | |
| | The gate correctly rejects such a mesh. A field aligned to the rim would need four interior singularities, which the bounded-disk producer refuses by design. **Neither the producer nor the gate is wrong.** The disc's real use stands: under the chained run the field corners cut the rim into exactly four sides (`a3=4/4/0/0/0`), and the phase front is produced. That is the O38 pipeline receipt RA-226 owed | TB112/TB113 disc lines; `SurfaceCellTracing.cpp` bounded-disk runs |
| F3 | **The gate counts a fixed rail edge as on target.** `effective_edge_target_size` returns the rail edge's own length when its mismatch is bounded, so boundary edges score 1. A size p5 of 0.434 must therefore come from interior edges at about 0.43 of their local target | `SurfaceMeshOptimizer.cpp`, `effective_edge_target_size`; gate target `constraints.localTargetSize = targetSize.targetSize` (`RemeshPipeline.cpp:14834`) |
| F4 | **Chained counts follow the boundary's metric.** On Plane, per-arc rounds each short source edge to one cell (8×8, size p95 1.30), while the chain counts the whole side (10×10, p95 1.04). The spread ratio stays about 2 in both, so the target field varies about 2× over the region. Two hypotheses could explain MultiFaceSeam: | TB112 face counts; TB113 size pairs |
| | **H1:** the target is larger in the interior than along the boundary. The boundary metric then sets more rows and columns than the interior needs, and one uniform lattice makes interior cells too small. No spacing fixes that; it needs fewer cells inside, which means a transition (irregular vertices) the single-patch producer cannot build | |
| | **H2:** the parity solve raised a short span's count | |
| | Which one holds decides the owner: H1 is an A4 construction limit, H2 an A3 rounding effect | |

## 3. Decision

1. **The disc is settled.** O41 no longer includes it (F2). Its completion failure is expected and recorded here. Row 945 remains as the O38 pipeline receipt. No producer, gate or fixture change.
2. **O41 is narrowed** to MultiFaceSeam chained, size p5 below 0.5, interior edges, with Plane chained close to the limit. Measure before deciding: CB133 → TB114.
3. **Activation remains held.** The gate's thresholds stay as they are; relaxing them would be a quality-policy decision for the user, not a Review.

## 4. CB133 — completed-mesh size receipt (compile only, test only)

[Exact patch](Architecture_M6_CP3_CB133_P13_A4_Completed_Mesh_Size_Census_Exact.diff): SHA-256 `874773240cc5934854915a0f7ed8076c10dc5073100c41030859c32f44e570ee`, 129 lines, keep 5 single-space context lines. Numstat: `97 4` `tests/SurfaceCellDesignAcceptanceTests.cpp`. Base: HEAD `b2ae6d7c9` (CB132 source `196f61176` plus documentation).

The census rows (932–935) print two new kinds of line:
- After each per-arc and chained run:
  `switch-size case=<name> schedule=<…> quads=Q boundary=n:p5/p50/p95 interior=n:p5/p50/p95 interiorBelowHalf=k target=min/median/max`
  It comes from the mesh the gate measured (its `optimizationResult` snapshot), with each undirected edge's length divided by the target interpolated at its endpoints' provenance. That is the gate's target, without the rail exception.
- One line per case, showing how the parity solve moved each field-corner-stopped span from its preferred count:
  `switch-spans case=<name> schedule=stopped spans=S raised=R lowered=L moved=p->c,…`

The `switch-run` and `switch-validation` calls are unchanged. The chained result is now kept in a named variable. No product source changes.

Mismatch → `M6-CP3-PLAN-P13-A4-COMPLETED-MESH-SIZE-CENSUS-STOP`; infrastructure → `M6-CP3-CB133A-P13-A4-COMPLETED-MESH-SIZE-CENSUS-ORCH`.

## 5. TB114 — full gate

`M6-CP3-TB114-P13-A4-COMPLETED-MESH-SIZE-CENSUS-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB114_P13_A4_Completed_Mesh_Size_Census_Full_Gate_Case_Manifest.tsv`: TB113's byte for byte, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026, `SELF_CHECK_PASS cases=945 deferred=81`.

**MATCH needs all of:**
- 945/945.
- Every receipt line TB113 recorded byte-identical, including the ten `switch-run` and ten `switch-validation` lines.
- The four `switch-spans` lines and every `switch-size` line recorded verbatim.
- A `switch-size` line present for MultiFaceSeam chained.

**Reading the result (evidence, not pass conditions):**
- H1 predicts, on MultiFaceSeam chained: boundary p50 near 1, interior p5 below 0.5 with `interiorBelowHalf` > 0, and a target max/min of at least about 2.
- H2 predicts that MultiFaceSeam's `switch-spans` shows a raised span with a small preferred count.

Mismatch → `M6-CP3-TB114-P13-A4-COMPLETED-MESH-SIZE-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB114A-P13-A4-COMPLETED-MESH-SIZE-CENSUS-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING`.

## 6. Follow-on — `M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING` (Review agent only)

It reads the `switch-size` and `switch-spans` lines and names O41's owner.
- **H1:** an A4 construction with size transitions inside a region (65C). If that is out of reach before activation, put the choice to the user: keep per-arc counts, or accept the gate's size band only on the chained path.
- **H2:** an A3 rounding rule.

It then freezes the fix and its receipt, and re-defines activation.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64E.6 **COMPLETE** | `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE` (this record) | Review |
| 64E.7 | `M6-CP3-CB133-P13-A4-COMPLETED-MESH-SIZE-CENSUS` (§4) | implementation agent |
| 64E.8 | `M6-CP3-TB114-P13-A4-COMPLETED-MESH-SIZE-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64E.9 | `M6-CP3-DEFN-P13-A4-INTERIOR-SIZE-GRADING` (§6) | **Review agent only** |
| later | Activation, after O41 | Review, then implementation |

**Gaps, stated.**
- The receipt's ratios count each undirected edge once, while the gate counts each quad side. Percentiles can differ slightly from the gate's.
- For produced runs the measured mesh is the optimized one; for the failing run it is the completed checkpoint.
- Vase's registered RED (same failure code) is not measured here. Whether it fails size, field or something else is left to 64E.9.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB114 = TB113 manifest byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | The gate's acceptance expression, `effective_edge_target_size`, `local_target_size`, the pipeline's gate target, and sin 168.75° = 0.195090 (matches the measured Jacobian to five digits) were checked by me |
| Runtime-free checks | `-fsyntax-only` returns 0 on `SurfaceCellDesignAcceptanceTests.cpp` with CB133; CB133 applies at HEAD; manifest self-check passes |
| Non-vacuity | A `switch-size` line for MultiFaceSeam chained is a MATCH condition; H1 and H2 make opposite predictions on recorded values |
| Obligations carried | 64E.7–64E.9; O41 (narrowed); activation; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB113 945/945, membership 1,026 |
| Turn boundary | No product or test source changed in the repository |

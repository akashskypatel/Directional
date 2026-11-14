# RA-236 — Singularity port owner, P13-e (BunnyRandom vertex 49)

Turn `M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER`, Review agent only, runtime-free. Input: [TB116](Architecture_M6_CP3_TB116_P13_Singularity_Port_Direction_Census_Full_Gate_Execution_Report_20261112.md) (945/945, scoped MATCH). It recorded 32 `partition direction` lines for singularity 6, with `inSector=1` exactly at the four known incidences. RA-235 §6.

## 1. Model

`rev236/fan49.py` (scratch) unfolds vertex 49's eight-face fan. It reads the repository fixture `benchmarks/fixtures/milestone-g/bunny_1k_random.obj` (the field is the generated smooth field; "random" refers to the triangulation) and the 32 TB116 direction lines. Each direction is `Σ w_k (P_k − V)` over the wedge's two far vertices.

| Result | Value |
|---|---|
| Wedge angles (degrees) | 137.35, 56.60, 34.21, 29.05, 51.50, 18.66, 59.25, 15.23; total 401.86 (a saddle-shaped cone) |
| In-sector branches | (0,2), (2,0), (4,0), (6,0), identical to the atlas's incidences |
| Field turning minus total wedge angle | −450.001° = −(4 − k)·90° with k = −1, so the singularity index is confirmed |
| Jumps across radial edges | all under 20°. The +3 lift across (49,109) is a −7.8° jump; a lift of +3 and of −1 permute branches identically |
| **Straddle** | **at the ray to vertex 48 (fan 0 → 1): branch 1 in face 0 points 10.8° past the ray, and its transported branch in face 1 points 7.4° short of it** |
| Count | in-face 4 = 5 − 1 (one straddle) + 0 (no double count) |

## 2. Findings

| # | Finding |
|---|---|
| F1 | **The owner is A1's sector rule.** The lift representative is cleared: the class union uses the branch permutation, which is the same for +3 and −1, and every jump is small. The field is valid. The fifth separatrix of vertex 49 runs along mesh edge (49,48), because each face's constant field points into the other face's wedge. No per-face wedge can hold a separatrix that lies on an edge |
| F2 | **An identity makes edge ports safe.** Write `classes` for the atlas's union count and `edgePorts` for the straddles. A separatrix counted in both faces next to a ray is merged by the union, so for any valid fan `classes + edgePorts = 4 − index`. Every singularity that passes today therefore has no straddle, and counting edge ports changes nothing for them |
| F3 | **The straddle is decidable exactly from the atlas's own data.** At the ray shared by faces i and i+1, branch b straddles it when face i's direction has a positive weight on the shared vertex and a negative weight on face i's previous vertex, and the transported branch in face i+1 has a positive weight on the shared vertex and a negative weight on face i+1's next vertex. These are exact signs on exact rational directions. Applied to the 32 TB116 lines, the predicate finds exactly (fan 0, branch 1, edge 48–49) |

## 3. Decision (D11, answered by the user on 2026-11-12: **A, edge-sliding ports**)

A1 records a port for a separatrix that straddles a radial edge, and A2a traces it along that edge until the field leaves it. This changes the port and trace contracts. It is staged:

1. **CB136 (report only):** the exact straddle detector inside the atlas. It prints one `partition edgePorts` line per singularity with the identity check, on every run. The atlas's behaviour is unchanged.
2. **TB117:** proves the identity on every singularity in the gate and the census. Every line has `identity=1`, and BunnyRandom's singularity 6 shows exactly the predicted straddle.
3. **Review-only `M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE`.** It reads how A2a consumes ports (`FieldAlignedCurveNetwork`) and defines both halves:
   - the A1 edge-port attachment: start face = the face whose next ray is the edge, by the existing half-open convention; first carrier = the radial edge itself;
   - the A2a edge-supported trace start.

   It freezes the wiring CB/TB, and BunnyRandom is expected to pass the atlas afterwards.

## 4. CB136 — edge-port straddle census (compile only)

[Exact patch](Architecture_M6_CP3_CB136_P13_Edge_Port_Straddle_Census_Exact.diff): SHA-256 `cca1ce4cc55aa3e9173ba548cf2d0faaa4bda42c1aad72978daf8a6356740dc4`, 70 lines, keep 1 single-space context line. Numstat: `59 0` `src/authority/FieldTransportAtlas.cpp`. Base: HEAD `3ad99427f` (CB135 source `40f979d20` plus documentation).

Line format, printed after the existing partition lines and before the count check:

`FieldTransportAtlas.partition edgePorts singularity=S sourceVertex=V classes=C edgePorts=K expectedClasses=E identity=<0|1> straddles=<" -" | " (fan,branch,a-b)…">`

It writes stderr only, with no behaviour, digest or receipt change.

Mismatch → `M6-CP3-PLAN-P13-EDGE-PORT-STRADDLE-CENSUS-STOP`; infrastructure → `M6-CP3-CB136A-P13-EDGE-PORT-STRADDLE-CENSUS-ORCH`.

## 5. TB117 — full gate and census

`M6-CP3-TB117-P13-EDGE-PORT-STRADDLE-CENSUS-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB117_P13_Edge_Port_Straddle_Census_Full_Gate_Case_Manifest.tsv`: TB116's byte for byte, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026, `SELF_CHECK_PASS cases=945 deferred=81`. The production census runs as before.

**MATCH needs all of:**
- 945/945.
- Census verdicts unchanged.
- Every TB116 receipt line byte-identical, including the 216 `partition direction` lines.
- **Every** `partition edgePorts` line in every gate and census log has `identity=1`.
- BunnyRandom's census log contains exactly `FieldTransportAtlas.partition edgePorts singularity=6 sourceVertex=49 classes=4 edgePorts=1 expectedClasses=5 identity=1 straddles= (0,1,48-49)`.
- Every other `edgePorts` line has `edgePorts=0`.
- A count of `edgePorts` lines per log is recorded.

A line with `identity=0` falsifies F2 and goes to REV.

Mismatch → `M6-CP3-TB117-P13-EDGE-PORT-STRADDLE-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB117A-P13-EDGE-PORT-STRADDLE-CENSUS-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE`.

## 6. Sequence

| Step | Turn | Owner |
|---|---|---|
| P13-e.3 **COMPLETE** | `M6-CP3-DEFN-P13-SINGULARITY-PORT-OWNER` (this record; D11 = A) | Review |
| P13-e.4 | `M6-CP3-CB136-P13-EDGE-PORT-STRADDLE-CENSUS` (§4) | implementation agent |
| P13-e.5 | `M6-CP3-TB117-P13-EDGE-PORT-STRADDLE-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| P13-e.6 | `M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE` (A1 edge-port attachment and A2a edge-supported trace start) | **Review agent only** |
| then | Wiring CB/TB frozen by P13-e.6; then 65A → 65D (O41, switch activation in 65C); O31/O32 | Review, then implementation |

**Gaps, stated.**
- The model uses the directions as printed (about 6 significant digits). The detector uses the exact rationals, and its verdict on vertex 49 agrees with the model's.
- What A2a does after the slide reaches vertex 48 is P13-e.6's question.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB117 = TB116 manifest byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | Unfolding model and exact sign predicate on all 32 TB116 lines (both find only the edge-48 straddle); identity F2 derived from the union rule (`FieldTransportAtlas.cpp`, class union by transported branch) |
| User decision | D11 answered: A, edge-sliding ports (2026-11-12) |
| Runtime-free checks | `-fsyntax-only` returns 0 on `FieldTransportAtlas.cpp` with CB136; CB136 applies at HEAD; manifest self-check passes |
| Non-vacuity | `identity=1` on every singularity of every run, and the exact vertex-49 line, are MATCH conditions |
| Obligations carried | P13-e.4–P13-e.6; 65A–65D (O41 and activation in 65C); O31; O32b–e; O33; D6 user decision pending; O34 (narrowed); O30b |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB116 945/945, membership 1,026 |
| Turn boundary | No product or test source changed in the repository |

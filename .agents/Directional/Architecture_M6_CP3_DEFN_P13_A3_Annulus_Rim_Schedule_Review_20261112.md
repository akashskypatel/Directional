# RA-228 — Annulus rim schedule (step 64D.3)

Turn `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-SCHEDULE`, Review agent only, runtime-free. Inputs: RA-227 (step 64D), TB108 (943/943, scoped MATCH, 12 `annulus-rim` lines).

## 1. What TB108 showed

- **Cylinder, per-arc:** `periodic=1 rimEdges=32 split=0 vertexBreaks=32 equalOutput=32 evenSplit=32`. Under the production schedule every rim edge reads, and its interval count equals the output the annulus builds there today.
- **Cylinder, chained and stopped:** identical apart from `schedule=`, at 28/32. The recorded TB98 `d4-rim` line (`sides=30`, two sides `2:4/4/4/0`) shows why. Nearly every rim vertex is already a chain stop. Only two chains of two arcs pass a rim vertex. Each has count 4 over two runs whose binary64 lengths are not exactly equal, so ordinal 2 misses the shared vertex by a rounding unit and both edges bridge it (RA-227 F4, now on a fixture).
- **The other three fixtures** have no annulus (`periodic=0`); their values are evidence only.

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **The bounded-disk side reader has two parts.** The first reads one Mandatory arc on its source edge: its bound span, and the span breakpoints that lie on it as edge parameters. The second joins arcs along a side with a cursor, which allows bridging. The annulus needs the first part and forbids the second. Only the first is shared | `SurfaceCellTracing.cpp:17544–17650` (arc assembly), `:17749–17849` (locate, then join) |
| F2 | **Exact-split placement keeps the lattice bit-identical.** When a strip's breakpoints are exactly `k/n`, the annulus's own coordinate `stripStart + (stripEnd − stripStart)·(k/n)` already is the plan's point. Taking `n` from the plan changes no coordinate wherever `n` is unchanged. An uneven split would need a non-uniform strip and a rational-to-double conversion with no exactness guarantee (`FieldExactRational::to_double` goes through decimal digits) | `:14949–14972`; `FieldTransportAtlas.h:519` |
| F3 | **Only the tracing digest reads the record.** In the pipeline, intervals are read by the tracing hash (`RemeshPipeline.cpp:2285`), by the product validator (genuine-boundary intervals allowed on exterior, unpaired edges, `:9383`), by the report-only A3 coverage summary, and by PeriodicCut and HardRail pairing code that never sees a rim edge | `RemeshPipeline.cpp:2285, 4832, 5109`; `SurfaceCellTracing.cpp:8252, 9383, 9666, 19232, 20118` |
| F4 | **Row 729 runs the annulus under a plan at a length ratio no census covered.** `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary` (gate row 729) uses `lengthRatio = 0.2`. If A3's parity solve gives paired rim edges different counts there, the reader rejects and the row turns red. That must be measured before the switch (RA-222) | `tests/SurfaceCellsPhase10Tests.cpp:5625` |
| F5 | **A flipped binding orientation never reaches the rim reader.** `bound_arc_schedule` compares the arc's path, reversed for a Reverse binding, with the span's support slice; a flipped binding fails that check and the arc does not read. The rim reader's own test covers walking against the span (Reverse, descending ordinals), as RA-227 §3.6 asks | `:13282–13302` |

## 3. Definition

1. **One shared arc reader.** `edge_arc_schedule` reads one Mandatory arc on its source edge and lists the breakpoints on it, ends included, as edge parameters in ascending ordinal. `mandatory_edge_arc_schedules` reads every arc on a network edge and checks that at most two of them tile the edge. The bounded-disk producer calls both and keeps its cursor join. `source_edge_arc_breakpoints` is the header-declared form, for tests.
2. **Annulus rim edge.** `read_annulus_rim_edge` walks a rim edge in strip order. It reads only when every arc starts and ends on a breakpoint, consecutive breakpoints are consecutive ordinals, and the split is exactly `k/n`. It returns `n` unit intervals, each with its span and its start and end ordinals.
3. **Readable strip** (narrows RA-227 §3.3 from "same split" to "same even split", F2). Both rim edges read with equal `n`. That `n` replaces the strip's own count, and `gridU = Σn` (RA-227 §3.5).
4. **Record.** Each rim cell edge records its interval in its own direction (Forward when the ordinal rises), with no boundary occurrence. As in the bounded-disk producer, an edge must hold an interval exactly when it is HardRail or GenuineSourceBoundary.
5. **Unreadable.** One unreadable strip, a missing network, or a rim edge with no Mandatory arc rejects the region: `InvalidFrontBoundaryAuthority` (RA-227 §3.4). This applies under a plan only.
6. **Unchanged:** the ring scoring (RA-227 F6), `gridV`, the interior lattice, the hard-feature decline.

**O36 annulus clause (decided).** The switch schedule must not chain across an annulus rim vertex. The switch definition passes every rim vertex of a region the annulus producer takes into the chained factory's stop list (`make_chained_global_conformity_baseline_input`'s vertex stops, as the field corners are passed). On Cylinder that splits the two two-arc chains, so chained equals per-arc on the rims (prediction: the Cylinder line reads 32/32). The alternative, leaving chained rims unread, was rejected: it would bring back the per-region counts that A3 replaces. O36 precondition "annulus rims readable under the switch schedule" becomes: readable under per-arc (TB109/TB110) **and** this clause.

## 4. CB128 — shared arc reader and unwired rim reader (compile only)

[Exact patch](Architecture_M6_CP3_CB128_P13_A3_Annulus_Rim_Edge_Schedule_Exact.diff): SHA-256 `eb7e63e262dfd6a030aa1bba375a3a6fbccb1ceeae3901e7ee4479dd3bbeec0b`, 709 lines, keep 15 single-space context lines. Numstat: `44 0 include/directional/geometry/SurfaceCellTracing.h`, `262 148 src/geometry/SurfaceCellTracing.cpp`, `130 0 tests/SurfaceCellsPhase10Tests.cpp`. Base: HEAD `35969200f` (CB127 source plus documentation).

- Product: definition items 1 and 2. The bounded-disk producer keeps every check, its failure reason and the order of its checks. No producer reads `read_annulus_rim_edge` yet.
- Test (new gate row 944) `SurfaceCellAuthorityContractCutover.D4AnnulusRimEdgeReadsEvenSplitsInWalkOrder`: walks with and against the span, two arcs meeting mid-edge, the reversed walk, and five rejections (bridged far vertex, uneven split, skipped ordinal, uncovered start, no arc). All ten expectations come from the exact model `rev228/model.py`.
- Receipt on row 729: `annulus-read case=CommittedCylinder rimEdges=R readable=… equalOutput=… outputRimEdges=O recorded=…`.

Mismatch → `M6-CP3-PLAN-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-STOP`; infrastructure → `M6-CP3-CB128A-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-ORCH`.

## 5. TB109 — full gate

`M6-CP3-TB109-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB109_P13_A3_Annulus_Rim_Edge_Schedule_Full_Gate_Case_Manifest.tsv`: TB108's 943 rows plus row 944; SHA-256 `46e5c8a8ffb1a8d6337d782bef44fa852d3b17870e2f06ab037d55a8ea201f61`, membership 1,025, `SELF_CHECK_PASS cases=944 deferred=81`.

**MATCH needs all of:**
- 944/944.
- Every receipt line TB108 recorded byte-identical: 25 inherited, 4 `rim-branch`, 12 `annulus-rim`.
- Census unchanged, including every platform-digest field.
- The row 729 `annulus-read` line recorded verbatim with `recorded=0` and `outputRimEdges` > 0.

Mismatch → `M6-CP3-TB109-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-FULL-GATE-REV`; infrastructure → `M6-CP3-TB109A-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-ORCH`.

**Route after MATCH, decided by the row 729 line:**
- If `readable` = `equalOutput` = `rimEdges`, the successor is CB129.
- Otherwise the successor is the Review-only `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-PAIRING`, which must decide how A3 keeps paired rim counts equal. CB129 must not be applied in that case.

## 6. CB129 — the annulus reads its rims (compile only)

[Exact patch](Architecture_M6_CP3_CB129_P13_A3_Annulus_Rim_Consumption_Exact.diff): SHA-256 `ce80f25e99da49806e7f576609e7a81edcc98491654ededb0bb7b441f7878991`, 166 lines, keep 4 single-space context lines. Numstat: `105 2 src/geometry/SurfaceCellTracing.cpp`, `8 0 tests/SurfaceCellDesignAcceptanceTests.cpp`, `4 0 tests/SurfaceCellsPhase10Tests.cpp`. Base: the CB128 source; it applies on CB128.

- Product: definition items 3, 4 and 5 in `build_periodic_annulus_phase_front_for_faces`. The strip's own count runs first, so its input checks keep their reasons. The plan's count then replaces it.
- Tests that fail without the switch:
  - Rim census (rows 932–935): when the phase front has a periodic holonomy, `unresolved = 0` and every output rim edge is recorded.
  - Row 729: `outputRimEdges` > 0 and every one is recorded.

Mismatch → `M6-CP3-PLAN-P13-A3-ANNULUS-RIM-CONSUMPTION-STOP`; infrastructure → `M6-CP3-CB129A-P13-A3-ANNULUS-RIM-CONSUMPTION-ORCH`.

## 7. TB110 — switch gate (changes registered now)

`M6-CP3-TB110-P13-A3-ANNULUS-RIM-CONSUMPTION-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB110_P13_A3_Annulus_Rim_Consumption_Full_Gate_Case_Manifest.tsv`, identical to TB109's (944 rows, `46e5c8a8…`).

**MATCH needs all of:**
- 944/944.
- The Cylinder `d4-rim` line exactly: `d4-rim case=Cylinder inputs=own phaseFront=Produced rimArcs=32 sides=30 perArcTotal=64 outputRimEdges=64 unresolved=0 arcs:perArc/chained/output/recorded=` followed by TB108's list with each side's last field set to its output field (28 sides `1:2/2/2/2`, two `2:4/4/4/4`, in TB108's order).
- The row 729 line equal to TB109's except `recorded=` equal to `outputRimEdges`.
- Every other full-gate receipt line byte-identical to TB109, including all 12 `annulus-rim` lines.
- Census:
  - BunnyRandom and Vase unchanged.
  - Cylinder PASS. Its platform-digest line is identical to TB108 except the `tracing=` hash; the `/1728` count and every later stage are unchanged (F2, F3).
  - Its `a3-coverage` line has `covered` +32 and `unrecorded` −32 relative to TB108, with `partial` and `foreign` unchanged.

Every other change → `M6-CP3-TB110-P13-A3-ANNULUS-RIM-CONSUMPTION-FULL-GATE-REV`; infrastructure → `M6-CP3-TB110A-P13-A3-ANNULUS-RIM-CONSUMPTION-ORCH`. On MATCH, the successor is the O36 switch definition (Review).

## 8. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64D.3 **COMPLETE** | `M6-CP3-DEFN-P13-A3-ANNULUS-RIM-SCHEDULE` (this record) | Review |
| 64D.4 | `M6-CP3-CB128-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE` (§4) | implementation agent |
| 64D.5 | `M6-CP3-TB109-P13-A3-ANNULUS-RIM-EDGE-SCHEDULE-FULL-GATE-EXEC` (§5) | implementation agent |
| 64D.6 | `M6-CP3-CB129-P13-A3-ANNULUS-RIM-CONSUMPTION` (§6), only on the §5 route | implementation agent |
| 64D.7 | `M6-CP3-TB110-P13-A3-ANNULUS-RIM-CONSUMPTION-FULL-GATE-EXEC` (§7) | implementation agent |
| later | O36 switch definition, carrying the annulus clause (§3) | Review |

**Gaps, stated.**
- No fixture has rims of different length, or a rim edge with a mid-edge network node. Both are now rejected under a plan instead of produced without A3.
- Gate rows other than 729 and 935 that run the annulus under a plan were looked for by name only. TB110's REV route covers one that was missed.
- The `a3-coverage` +32 assumes one baseline incidence per rim span.
- RA-227 F6 (ring scoring) stands.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB109/TB110 = TB108's 943 rows byte for byte plus row 944; selector497/CP3 unpromoted |
| Decisive claims re-derived | Bounded-disk side reader, annulus count/placement/open-edge code, `bound_arc_schedule`, every `sharedBoundaryInterval` reader, the tracing hash and row 729 were read by me |
| Runtime-free checks | `-fsyntax-only` returns 0 on `SurfaceCellTracing.cpp` and `SurfaceCellsPhase10Tests.cpp` at CB128, and on those plus `SurfaceCellDesignAcceptanceTests.cpp` at CB129. CB128 applies at HEAD, CB129 on CB128. Both manifests pass the self-check. The model gives all ten unit-test expectations |
| Non-vacuity | Row 944 rejects bridging, an uneven split and a skipped ordinal; CB129's two assertions fail if the annulus records nothing; TB110 pins the Cylinder `d4-rim` line exactly |
| Obligations carried | 64D.4–64D.7; O36 (plus the annulus clause); D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); O35; O37; O38; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB108 943/943, membership 1024 |
| Turn boundary | No product or test source changed in the repository |

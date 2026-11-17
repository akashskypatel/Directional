# RA-238 — P13-e edge-port trace outcome: obtuse start face at BunnyRandom vertex 367 (2026-11-16 UTC)

**Turn:** `M6-CP3-DEFN-P13-EDGE-PORT-TRACE-OUTCOME` (Review only, P13-e.9). **Authority read:** [TB118 report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb118_p13_edge_supported_port_trace_full_gate_execution_report_20261116md), [RA-237](Architecture_M6_CP3_DEFN_P13_Edge_Sliding_Separatrix_Trace_Review_20261116.md), compiled CB137 source `4a63be7a17b5784f0fa742883bbf99e4fe546360` (identical to HEAD for the touched files). Runtime-free: no build, test or probe was run.

## 1. TB118 accepted

TB118 is accepted as a **scoped MATCH**, with the qualification as written: 946/946, membership 1,027, 1,900/1,900 hashes, census 9/9, and row 946 attached `(4,6)`. Vertex 49's terminal is gone. The five inherited raw logs (rows 168, 173, 177, 190, 705) differ only in the legacy `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` line, which is sometimes printed twice. That is pre-existing text nondeterminism with no verdict or receipt effect. Later MATCH conditions therefore compare receipt lines, not whole raw logs.

## 2. Evidence (TB118 census artifact `14192370504`, SHA-256 `317e3623…f7fb` re-verified)

Singularity 32, at vertex 367 (index −1, 5-face fan), has 3 face classes and 2 straddles: `(1,0,170-367)` was not attached and `(3,1,366-367)` was attached. That gives 3 + 1 = 4, against 5 expected. The census `partition direction` lines give both faces' barycentric weights for each straddle. With these and the repository mesh `benchmarks/fixtures/milestone-g/bunny_1k_random.obj` (502 vertices, 1,000 faces), I checked all 11 census straddles in a Python model:

| Straddle | wS face i, face i+1 | Along-edge rate (away from S), both faces | CB137 rule | Exact rule | Grazing proxy |
|---|---|---|---|---|---|
| s6 (48,49) … s30 (261,354), 9 lines | all < 0 | all > 0 | attach | attach | slides away |
| s32 (366,367) | −94.07, −90.57 | 0.00992, 0.01004 | attach | attach | 366 |
| **s32 (170,367)** | **+8.771**, −134.41 | **0.005438, 0.005415** | **refuse** | attach | **undecided** |

The model reproduces the logged `attached` bit on 11 of 11 lines, so it is a faithful reading of A1.

## 3. Findings

- **F1: root cause.** A1's attach test (weight on S < 0 in both faces) stands in for the slide direction, and it only works when the face is not obtuse at S. In face (162,170,367), vertex 162 projects onto the edge axis at r = −1.23 behind S (the angle at 367 is obtuse). The rate along the edge is w₁₇₀ + r·w₁₆₂ = 67.84 + 1.23·76.61 > 0, so the separatrix leaves S, yet w₃₆₇ = +8.77. The port exists: the count identity holds and the exact slide leaves the vertex in both faces. A1 refused it on a proxy.
- **F2: A2a has the same flaw.** `resolve_field_branch_grazing_transit` decides the slide from the two faces' rates on `carrier.second()`. For (170,367) that vertex is 367, with rates +8.77 and −134.41. CB137's departure would therefore stop with `BranchGrazingSlideDirectionAmbiguous` on its first slide, even after A1 is fixed.
- **F3: the exact rule.** The rate at which face k's branch advances along the radial edge is T_k = d_k·(x_A − x_S), with d_k = Σ_v w_v x_v. It is exact on the stored doubles, with no square root. A straddle has both faces pushing into the edge, so the sliding (Filippov) vector is a positive mix of d₁ and d₂. When T₁ and T₂ are both positive, its component along the edge is positive. The rule is independent of vertex numbering by construction.
- **F4: gate neutral.** TB118 has exactly one `partition edgePort` line across rows 1–946 (row 946). Under the exact rule, row 946's straddle still attaches (model T = 1.190 and 1.190). No other row has a straddle or an edge-port trace, so rows 1–945 cannot change.
- **F5: O43 (new).** For ordinary grazing (not edge ports) the endpoint-rate proxy can, in principle, disagree with the exact rule even where it decides. Algebraically, both endpoint rates can be positive while T < 0. Accepted rows run grazing (the CP4c grazing census tests), so switching it needs a per-row measurement first. It is not changed here.
- **F6.** BunnyRandom singularities after 32 have never been evaluated. Its next blocker is unknown.

## 4. Frozen CB138: `M6-CP3-CB138-P13-OBTUSE-EDGE-PORT-SLIDE` (compile only)

[Exact patch](Architecture_M6_CP3_CB138_P13_Obtuse_Edge_Port_Slide_Exact.diff): SHA-256 `53985fef66e2e7262d4624c79f5b037e58e4760f4db18403d37c683a4e0e5d60`, 334 lines (keep 5 single-space context lines). Numstat: `16 2` `include/directional/geometry/SurfaceCellTracing.h`; `36 9` `src/authority/FieldTransportAtlas.cpp`; `22 6` `src/geometry/SurfaceCellTracing.cpp`; `137 8` `tests/FieldTransportAtlasTests.cpp`. Base: HEAD `c8bd85e5c`, or any descendant that changes only documentation.

- **A1:** `alongRadial` computes T exactly with the existing `exact_vector`, `exact_difference` and `exact_dot`. An edge port is attached iff T > 0 in both faces. The receipt lines are unchanged.
- **A2a:** new `resolve_field_edge_port_slide(carrier, singularVertex)` returns `EdgeTransit` to the carrier's other vertex. `field_aligned_next_trace_proposal` uses it in place of the grazing transit for an edge-port departure, so A1's exact decision is the only one made. The guard against a slide ending at the source vertex is removed, because it can no longer fire. The guard that the target face is `Outflow` stays. Ordinary grazing is unchanged.
- **New test `FieldTransportAtlas.PublishesEdgeSupportedPortFromFaceObtuseAtVertex`.** The planar index −1 fan helpers gain defaulted ray and radius parameters. Rays are 10, 55, 100, 145, 190 and 330 degrees, so face (4,5,6) spans 140°; radii are 1.10, 1.05, 1.15, 1.00, 1.30 and 0.80; the offset is 54.5. This reproduces vertex 367's shape. Model predictions:
  - Wedge ports at 46.375, 113.875 and 259.5 degrees.
  - Straddle on ray 4: past 20.5°, short 2.625°, wS (+0.282, −0.739). CB137 refuses it.
  - Straddle on ray 5: past 3.0°, short 19.5°, wS (−1.252, −0.282).
  - Expected slots 0–4: carriers (0,1), (2,3), (4,6), (4,5), (5,6); start faces (0,1,6), (2,3,6), (4,5,6), (4,5,6), (0,5,6).
  - On (4,6) the grazing transit returns `BranchGrazingSlideDirectionAmbiguous` while the slide ends at vertex 4. On (5,6) both agree on vertex 5.
  - The ±0.5° offset scan keeps the same topology.
  - **Falsifier:** on CB137 the atlas fails with `SingularityPortClassCountMismatch`, so `ASSERT_TRUE(built)` fails.
- Runtime-free checks: `-fsyntax-only` returns 0 on all three translation units under `-Wall -Wextra`, and the warning set is identical to HEAD. `git apply --check` passes at HEAD.

## 5. TB119: `M6-CP3-TB119-P13-OBTUSE-EDGE-PORT-SLIDE-FULL-GATE-EXEC` (artifact only)

Manifest `gates/Architecture_M6_TB119_P13_Obtuse_Edge_Port_Slide_Full_Gate_Case_Manifest.tsv`: TB118's 946 rows byte for byte, plus row 947 `GUARD ra238:obtuse-edge-port-slide`. SHA-256 `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b`; `SELF_CHECK_PASS cases=947 deferred=81`; expected membership 1,028. Plus the same three-case census.

**MATCH** requires all of:

1. 947/947 PASS, membership 1,028, deferred 81.
2. Rows 1–945: the ledger verdicts and required receipt lines match TB118, allowing the known duplicated legacy `M3_CP4AB_FRAGMENT_DIAG` text. There are no `partition edgePort ` or `edgePortDeparture` lines.
3. Row 946: the same `edgePort singularity=0 fanIndex=2 branch=2 carrier=(4,6) attached=1` and `identity=1` as TB118.
4. Row 947: exactly two `partition edgePort` lines, `singularity=0 fanIndex=1 … carrier=(5,6) attached=1` then `fanIndex=2 … carrier=(4,6) attached=1`, and the summary `classes=3 edgePorts=2 expectedClasses=5 identity=1`.
5. Cylinder PASS and Vase registered RED, with receipts unchanged.
6. BunnyRandom:
   - The ten TB118 `attached=1` lines are unchanged.
   - `FieldTransportAtlas.partition edgePort singularity=32 fanIndex=1 branch=0 carrier=(170,367) attached=1` appears.
   - Every `identity=1` holds.
   - There is no `SingularityPortClassCountMismatch;sourceVertex=367`.
   - If the trace network runs, every `edgePortDeparture` line has `slideEnd` equal to its carrier's non-singular vertex (for example `carrier=(170,367) slideEnd=170`), and no `BranchGrazingSlideDirectionAmbiguous` names an edge-port departure.
   - Record the new first terminal verbatim, with counts of `partition edgePort`, `attached=0` and `edgePortDeparture`.

Routes:
- CB138 mismatch → `M6-CP3-PLAN-P13-OBTUSE-EDGE-PORT-SLIDE-STOP`; infrastructure → `M6-CP3-CB138A-P13-OBTUSE-EDGE-PORT-SLIDE-ORCH`.
- TB119 mismatch → `M6-CP3-TB119-P13-OBTUSE-EDGE-PORT-SLIDE-FULL-GATE-REV`; infrastructure → `M6-CP3-TB119A-P13-OBTUSE-EDGE-PORT-SLIDE-ORCH`.
- On MATCH → Review-only `M6-CP3-DEFN-P13-OBTUSE-EDGE-PORT-OUTCOME` (P13-e.12).

## 6. Gaps and carry

- **Untested wiring:** the A2a wiring has no network-level unit test, as in RA-237. The new test checks the slide function, and BunnyRandom's receipt checks the wiring only if the network is reached.
- **Unrun fixture:** the fixture's predictions come from the model, not a run. A wrong prediction fails row 947 and routes to REV.
- **Not modelled:** the Filippov argument assumes constant per-face fields, which is A1's representation. Opposite-signed T values are refused, not decided.
- **Open obligations:** O42 and the new O43.
- **Carry:** CP2 491/491; stable 66/17/49; debt 1; deferred 81; `chainRimSchedules=false`; CP3/selector497 unpromoted; D10 defer; D11 = A; D6 pending; O41 in 65C; O31/O32 open.

**Closeout:** RA-238 COMPLETE. No repository source changed. The successor `M6-CP3-CB138-P13-OBTUSE-EDGE-PORT-SLIDE` was not started.

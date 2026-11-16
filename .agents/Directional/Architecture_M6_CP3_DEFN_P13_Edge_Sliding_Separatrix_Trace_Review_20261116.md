# RA-237 — Edge-sliding separatrix trace, P13-e.6 (BunnyRandom vertex 49)

Turn `M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE`, Review agent only, runtime-free. Input: [TB117](Architecture_M6_CP3_TB117_P13_Edge_Port_Straddle_Census_Full_Gate_Execution_Report_20261115.md) MATCH (945/945; 470/470 `identity=1`; the only straddle is BunnyRandom `(0,1,48-49)`). Decision D11 = A (edge-sliding ports, [RA-236 §3](Architecture_M6_CP3_DEFN_P13_Singularity_Port_Owner_Review_20261112.md)).

## 1. How A2a consumes a port (read from the code)

| Step | Code | Fact |
|---|---|---|
| Binding | `canonical_field_aligned_traces_and_events` (`SurfaceCellTracing.cpp`) | One port per `4 − index` ordinal, bound to the attachment with the same `localSlot`; the runtime starts at `startFace`, `branch`, entry at the singular vertex |
| First step | `field_aligned_next_trace_proposal` → `resolve_field_branch_continuation` | From the vertex, a branch that points out of the face across the radial edge has exit time 0, so it returns `BranchContinuationDegenerateEntry`. An edge port cannot use the face start |
| Sliding already exists | `classify_field_branch_transport_flow` / `resolve_field_branch_grazing_transit` | When a trace leaves face i across edge e and the next face's branch pushes back (`Outflow`), A2a slides along e to the endpoint chosen by the rate signs on `e.second()`, sets `edgeTransitExit`, then runs vertex transit in `EdgeTransit` mode |
| Downstream | `SurfaceCutGraph`, `EmbeddedGraphTopology` (`exact_trace_path`, `vertex_trace_ray_second_point`), `GlobalTopologyPlan`, polylines | All read a sliding segment as entry → `edgeTransitExit`. At a vertex, rays order by face slot, then by the second point's opposite-edge parameter; an edge port's second point is S, parameter 0 |
| Legacy tracer | `legacy_canonical_field_aligned_traces` | Diagnostic only (contact census, "frozen observation of the predecessor mechanism"). Left unchanged; it would reject an edge port with `BranchContinuationDegenerateEntry`. No gate row gives it one |

## 2. Findings

| # | Finding |
|---|---|
| F1 | **The straddle is the grazing precondition at the vertex end of the edge.** CB136's predicate (face i weight on its previous vertex < 0 → the radial edge is an outflow carrier; face i+1 weight on its next vertex < 0 → `Outflow`) is exactly what `resolve_field_branch_grazing_transit` asserts. No new transit is needed: the departure is a zero-length in-face exit at the vertex on the radial carrier, and the existing grazing path does the slide |
| F2 | **Slide direction must leave the vertex, under either edge orientation.** The accepted grazing rule reads rates on `carrier.second()`, so it depends on vertex numbering. A1 attaches an edge port only when the weight on the singular vertex is negative in both faces. With the straddle's positive weight on the far vertex S, the slide goes to S whichever endpoint is `second()`, so the attachment is relabel-invariant. BunnyRandom: w49 = −102.8 (face 0, branch 1) and −141.0 (face 1, branch 2), from TB117's census log (artifact `14186002854`, ZIP SHA-256 re-checked) |
| F3 | **No new field.** An edge port is the attachment whose `firstOutgoingCarrier` contains the singular vertex (a face port's carrier never does). Its start face is face i, whose next-vertex ray is the edge (half-open rule). In slot order its angle ratio is exactly 0, at that ray; a face port on the same ray ties and fails closed (`AmbiguousBranchTopology`). The digest already hashes the carrier. Predicted BunnyRandom slot 0 (before the face port (0,2)) |
| F4 | **Inert everywhere TB117 measured.** TB117 found no straddle in any of the 945 gate rows, nor in Cylinder or Vase. Their attachments, digests and receipts therefore cannot change, and the departure branch runs only for an edge port |
| F5 | **What is new downstream.** A trace path along a source edge (V→S) has not been produced before. Contact classification ignores the slide part of any grazing segment (pre-existing, now **O42**). The census decides whether the arrangement accepts it |

## 3. CB137 — edge-supported port and departure (compile only)

`M6-CP3-CB137-P13-EDGE-SUPPORTED-PORT-TRACE`. [Exact patch](Architecture_M6_CP3_CB137_P13_Edge_Supported_Port_Trace_Exact.diff): SHA-256 `0d3f2374a3260da70ea529c873b409187a0005f76f405d4791c3a10e35f0996e`, 470 lines, keep its 9 single-space context lines. Base HEAD `95fe03fee` (CB136 source `1d5c9514b` plus documentation). Numstat:

```
9   0  include/directional/authority/FieldTransportAtlas.h
15  0  include/directional/geometry/SurfaceCellTracing.h
38  5  src/authority/FieldTransportAtlas.cpp
68  3  src/geometry/SurfaceCellTracing.cpp
181 0  tests/FieldTransportAtlasTests.cpp
```

- **A1** (`build_singularity_attachments`):
  - Inside CB136's straddle block, a straddle with negative weight on the vertex in both faces becomes an attachment of face i, with `firstOutgoingCarrier` = the radial edge.
  - Each straddle prints `FieldTransportAtlas.partition edgePort singularity=S fanIndex=i branch=b carrier=(a,b) attached=<0|1>`. CB136's `partition edgePorts` line is unchanged.
  - The count check becomes `classes + edgePorts == 4 − index`. Edge ports join the representatives and order with ratio 0.
  - The header documents both port kinds on `FieldSingularityPortAttachment`.
- **A2a**:
  - New public `resolve_field_edge_port_departure(startFace, pairing, carrier, singularVertex)` returns an `EdgeExit` at the vertex on the carrier. It fails closed (`BranchContinuationOutsideOutflowSet`) unless the carrier is radial, an edge of the start face, and an outflow carrier of the branch.
  - The production runtime records the carrier of an edge port, and the first proposal uses the departure.
  - Fails closed if the carrier is a barrier, the next face is not `Outflow`, or the slide ends at the source vertex.
  - Prints `FieldAlignedCurveNetwork.edgePortDeparture singularity=S sourceVertex=V startFace=(…) branch=b carrier=(a,b) slideEnd=E`.
- **Test** `FieldTransportAtlas.PublishesEdgeSupportedPortForRadialStraddle` uses a planar six-face index −1 fan (centre 6) with field angle `offset − mid/4` per face:
  - At offset 63° (control) there are 5 face ports and none radial.
  - At offset 38.5° there are 5 ports and exactly one radial: carrier (4,6), start face (4,5,6), `localSlot` 3.
  - The departure exits at vertex 6 on (4,6). The next face (3,4,6) is `Outflow`, and the grazing transit ends at vertex 4.
  - Each face port is refused by the departure.
  - On the pre-CB137 atlas the 38.5° field fails with `SingularityPortClassCountMismatch`, so the test fails without the change.
  - The fixture comes from a Python model (scratch `rev237/fan_model.py`). Straddle 7.25° past and 7.375° short; in-wedge margin ≥ 7.1°; slide-away weights −0.765 / −0.746. Control margin 2.875°. The model also confirms `classes + straddles = 5` at every offset scanned.
- Mismatch → `M6-CP3-PLAN-P13-EDGE-SUPPORTED-PORT-TRACE-STOP`; infrastructure → `M6-CP3-CB137A-P13-EDGE-SUPPORTED-PORT-TRACE-ORCH`.

## 4. TB118 — full gate and census

`M6-CP3-TB118-P13-EDGE-SUPPORTED-PORT-TRACE-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB118_P13_Edge_Supported_Port_Trace_Full_Gate_Case_Manifest.tsv`:
- TB117's 945 rows byte for byte, plus row 946 `GUARD ra237:edge-supported-port FieldTransportAtlas.PublishesEdgeSupportedPortForRadialStraddle directional_surface_cell_authority_kernel_tests PASS`.
- 946 cases, SHA-256 `5fee837d7760c8e60a8dc47e8734576465adfd67c44ebebb33789c675ee39d00`, `SELF_CHECK_PASS cases=946 deferred=81`, membership expected 1,027.
- The production census runs as before.

**MATCH needs all of:**
- 946/946.
- Rows 1–945: verdicts unchanged, and every TB117 receipt byte-identical. No `partition edgePort` and no `edgePortDeparture` line in their logs.
- Row 946 log: every `partition edgePorts` line has `identity=1`, and exactly one `partition edgePort … fanIndex=2 … carrier=(4,6) attached=1`.
- Cylinder and Vase: verdicts and every TB117 receipt unchanged.
- BunnyRandom:
  - Every `partition edgePorts` line has `identity=1`, and singularity 6's line is byte-identical to TB117's.
  - Each atlas build that reaches singularity 6 prints `FieldTransportAtlas.partition edgePort singularity=6 fanIndex=0 branch=1 carrier=(48,49) attached=1`.
  - No `SingularityPortClassCountMismatch` at vertex 49.
  - If the curve network runs, exactly `FieldAlignedCurveNetwork.edgePortDeparture singularity=6 sourceVertex=49 startFace=(25,48,49) branch=1 carrier=(48,49) slideEnd=48`.
- Record BunnyRandom's terminal (stage, code, every printed diagnostic), including any later singularity's `edgePorts`/`edgePort` lines, as the next blocker. A RED verdict there is allowed.
- Count `partition edgePorts`, `partition edgePort` and `edgePortDeparture` lines per log.

A change to any inherited row or receipt, an `identity=0` line, vertex 49 unattached or mismatched, a wrong departure line, or a failing row 946 → `M6-CP3-TB118-P13-EDGE-SUPPORTED-PORT-TRACE-FULL-GATE-REV`. Infrastructure → `M6-CP3-TB118A-P13-EDGE-SUPPORTED-PORT-TRACE-ORCH`. On MATCH, close with `Successor: M6-CP3-DEFN-P13-EDGE-PORT-TRACE-OUTCOME`.

## 5. Sequence

| Step | Turn | Owner |
|---|---|---|
| P13-e.5 **COMPLETE** | `M6-CP3-TB117-P13-EDGE-PORT-STRADDLE-CENSUS-FULL-GATE-EXEC` (MATCH) | implementation agent |
| P13-e.6 **COMPLETE** | `M6-CP3-DEFN-P13-EDGE-SLIDING-SEPARATRIX-TRACE` (this record) | Review |
| P13-e.7 **NEXT** | `M6-CP3-CB137-P13-EDGE-SUPPORTED-PORT-TRACE` (§3) | implementation agent (compile only) |
| P13-e.8 | `M6-CP3-TB118-P13-EDGE-SUPPORTED-PORT-TRACE-FULL-GATE-EXEC` (§4) | implementation agent (artifact only) |
| P13-e.9 | `M6-CP3-DEFN-P13-EDGE-PORT-TRACE-OUTCOME`: reads TB118's BunnyRandom terminal and names its owner, or routes to 65A if BunnyRandom passes | **Review agent only** |
| then | 65A → 65D (O41 and switch activation in 65C); O31/O32 | Review, then implementation |

**Gaps, stated.**
- The production departure wiring has no network-level unit test. A synthetic fan's slide ends at a boundary vertex, where vertex transit was not predicted without running. The unit test covers the departure and grazing contract through public functions; the census receipt covers the wiring.
- The fixture's predictions come from the model, not a run. A wrong prediction fails row 946 and routes to REV.
- New downstream path along a source edge, and O42 (§2 F5).
- The macOS `-fsyntax-only` check needed `-include iterator`. `SourceChartTransitions.h:529` uses `std::inserter` without `<iterator>`; this predates the turn and does not affect Linux CI.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB118 rows 1–945 = TB117 byte for byte (`16a909bd…`); selector497/CP3 unpromoted |
| Decisive claims re-derived | Straddle ⇔ grazing precondition (code read); slide-away signs on BunnyRandom from the SHA-checked TB117 artifact; fixture model with identity check |
| User decision | D11 = A applied; D10 defer; D6 pending |
| Runtime-free checks | `-fsyntax-only` returns 0 on `FieldTransportAtlas.cpp`, `SurfaceCellTracing.cpp`, `FieldTransportAtlasTests.cpp` with CB137 (no new warnings under `-Wall -Wextra`); CB137 applies at HEAD; TB118 manifest self-check passes |
| Non-vacuity | Row 946 fails on the pre-CB137 atlas (count mismatch); BunnyRandom's exact `attached=1` and departure lines are MATCH conditions |
| Obligations carried | P13-e.7–P13-e.9; O42 (new); 65A–65D (O41 and activation in 65C); O31; O32b–e; O33; D6; O34 (narrowed); O30b |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB117 945/945, membership 1,026 |
| Turn boundary | No product or test source changed in the repository; the patch is a frozen file |

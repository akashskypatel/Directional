# RA-239 — P13-e obtuse edge-port outcome: BunnyRandom's first network terminal (2026-11-16 UTC)

**Turn:** `M6-CP3-DEFN-P13-OBTUSE-EDGE-PORT-OUTCOME` (Review only, P13-e.12).

**Authority read:**
- the [TB119 report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb119_p13_obtuse_edge_port_slide_full_gate_execution_report_20261116md);
- the [CB138 record](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_cb138_p13_obtuse_edge_port_slide_code_build_record_20261116md);
- [RA-238](Architecture_M6_CP3_DEFN_P13_Edge_Port_Trace_Outcome_Review_20261116.md);
- DESIGN Amendments 17 and 22, and `M3_Closure_Record.md` AX1.

HEAD's `src`, `include` and `tests` are identical to the CB138 source `2e551bdd9ac72ccf3cd65326d58aa7911adee36f` (`git diff` is empty). No runtime was used.

## 1. TB119 accepted

TB119 is accepted as a **scoped MATCH**. Both artifacts were re-downloaded into their own directories and SHA-checked:
- gate `14196801557` (`e5ace69f…`): 1,902/1,902 internal hashes and 947 PASS ledger rows.
- census `14197506256` (`7c28e33d…`): 9/9 internal hashes.

Raw log 947 has exactly the RA-238 §5 receipts, in this order:
- `fanIndex=1 branch=2 carrier=(5,6) attached=1`;
- `fanIndex=2 branch=1 carrier=(4,6) attached=1`;
- then `classes=3 edgePorts=2 identity=1`.

Raw log 946 is unchanged. Rows 946 and 947 are the only gate rows with a `partition edgePort` line. No gate log contains an `edgePortDeparture` line.

## 2. Evidence (census raw log 2, BunnyRandom)

- **Atlas complete.**
  - Every singularity's `edgePorts` line has `identity=1`.
  - 16 edge ports are attached at 14 singularities, including both ports at vertex 367.
  - All 16 `edgePortDeparture` lines reach their carrier's far vertex.
- **Terminal.** `NotProductionReady:field-aligned-network`, detail `BranchContinuationDegenerateEntry`, with zero trace segments.
- **Nothing else printed.** The network prints only the 16 departure lines. The acceptance test prints the error code but not the failure locus. The locus is in `RemeshDiagnostics::terminalFailureLocus` (face, branch, entry edge and parameter, trace seed, history), so this is the first time BunnyRandom's network has run with nothing logged about where it stopped. Every earlier BunnyRandom run stopped in the atlas.

## 3. Findings

- **F1: only one route reaches the code.** `resolve_field_branch_continuation` returns `BranchContinuationDegenerateEntry` when the minimizing exit time is 0. That needs the entry barycentric weight to be 0 on a corner where the direction is negative. Each kind of entry was checked:
  - **Interior edge entry: impossible.** The only zero weight is on the opposite corner. A negative direction there is `Outflow`, which `classify_field_branch_transport_flow` sends to grazing before the crossing. Edge exits are published on the dyadic grid strictly inside (0,1).
  - **First step of an ordinary port: impossible.** The atlas's half-open sector test (next > 0, previous ≥ 0) forces w_S < 0 and no negative elsewhere.
  - **First step of an edge port: does not apply.** It uses `resolve_field_edge_port_departure`.
  - **Entry at a vertex after `resolve_field_vertex_transit`: the only route.** This covers a `VertexHit`, the end of a grazing slide, and the end of an edge-port slide. The weights are (1,0,0), so a negative direction on either other corner gives time 0.
  - So the terminal means some vertex transit elected an owner face whose own field has a negative weight on a corner other than the vertex: the field does not leave the vertex in that face.
- **F2: the election never looks at the owner's field, by design.** Amendment 22 elects the owner from geometry alone (the straightest geodesic, β = α + Θ/2). Amendment 17 forbids deciding from any face's own field. Nothing checks that the owner's field leaves the vertex. The accepted test `AcceptedWitnessesNeverPublishDegenerateOrOutsideOutflowRejections` treats this error as never occurring on accepted witnesses. BunnyRandom's random field is the first input where it does.
- **F3: hypothesis H1, edge-transit seed.** AX1 defines `arrivalRay` as the ray "from the vertex back along the incoming trace". `resolve_field_vertex_transit` sets it to the arrival face's negated field direction in both arrival modes.
  - For `FaceInterior` that is exactly back along the trace.
  - For `EdgeTransit` (a grazing or edge-port slide), the trace arrives along the carrier edge, but the face's field crosses that edge. The seed is then not on the carrier ray, and the elected sector moves with it.
  - All 16 edge-port slides end in `EdgeTransit` arrivals. On BunnyRandom these are the most likely sources.
- **F4: hypothesis H2, a gap in the design.** Even with a seed that follows AX1, the straightest-geodesic owner of a piecewise-constant field need not have an outgoing field. Amendment 22 names three residual cases, and this is not one of them. Repairing it would change Amendment 22's contract, so it would be a named user decision, as with D10 (RA-233).
- **F5: the cause is not yet located.** The log names neither the trace nor the vertex. Of the 16 slide-end vertices, 411 and 344 are singular vertices with atlas summaries, so those slides end as terminals. Singularities 13 and 19 print no summary, so their vertices are unknown. That leaves up to 14 candidates, plus any grazing or vertex hit on ordinary traces. A repair now would guess between H1 and H2 and would change accepted rows' grazing transits (RA-228). Measure first (RA-222, RA-235).

## 4. Frozen CB139: `M6-CP3-CB139-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT` (compile only)

- **Patch:** [exact diff](Architecture_M6_CP3_CB139_P13_Vertex_Transit_Outflow_Receipt_Exact.diff).
  - SHA-256 `bd0d7afeaf7c0a3e196907fcba6b8230ec7955d269b75cfb833b6ea15bd05eb7`.
  - 175 lines, standard 3-line context.
  - Numstat `103 0` `src/geometry/SurfaceCellTracing.cpp` and `28 1` `tests/SurfaceCellDesignAcceptanceTests.cpp` (+131 −1).
- **Base:** HEAD at this record's commit, or any descendant that changes only documentation. Precheck: `git diff --quiet 2e551bdd9ac72ccf3cd65326d58aa7911adee36f HEAD -- src include tests`.
- **R1 (source, diagnostic only).** `report_field_vertex_transit_without_outflow` runs after each successful `resolve_field_vertex_transit` in `field_aligned_next_trace_proposal`, on both the `VertexHit` and the slide-end paths.
  - It prints only when the owner's direction is negative on a corner other than the vertex. By F1, that is exactly when the next step's exit time is 0.
  - First line, `FieldAlignedCurveNetwork.vertexTransitWithoutOutflow`, gives:
    - the trace's seed singularity and vertex, trace id, step (segments so far), and vertex;
    - the arrival mode, arrival face and branch, and carrier;
    - the owner face, branch and its three weights (`w<vertex>=`);
    - `onRadialRay`, `closedFan` and the sector count.
  - Then one `FieldAlignedCurveNetwork.vertexTransitSector` line per fan sector, giving its face, branch, next and previous radial vertices, `owner`, `inOwnSector` and three weights.
  - The decision is unchanged.
- **R2 (test only).** `failure_context` appends ` locus face=(…) branch=… edge=(…) parameter=… exact=… seedVertex=… seedSingularity=… history=N` from `terminalFailureLocus`. Fields that are absent are omitted. `history` is always printed.
- **Checks.**
  - `git apply --check` passes at HEAD.
  - `-fsyntax-only -Wall -Wextra` (Homebrew clang++, CI defines) returns 0 on both files. The warning sets are identical to HEAD's: 43 and 27.
  - No test is added, so membership stays 1,028.
- **Routes.**
  - Mismatch: `M6-CP3-PLAN-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT-STOP`.
  - Infrastructure: `M6-CP3-CB139A-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT-ORCH`.

## 5. TB120: `M6-CP3-TB120-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT-FULL-GATE-EXEC` (artifact only)

- **Gate.** The TB119 manifest is reused unchanged: 947 rows, `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b`, membership 1,028.
- **Census.** The three-case manifest `3af1dc0d…`.
- **MATCH requires all of these:**
  - **Gate:** 947/947 PASS.
  - **Receipts:** every TB119 receipt line in rows 1–947 is unchanged (`platform-digest`, `a3-coverage`, `switch-*`, `annulus-*`, `partition edgePort`/`edgePorts`).
  - **Cylinder:** PASS, with unchanged receipts.
  - **Vase:** RED `NotProductionReady:completion`, `AggregateCompletionValidationFailure`, 189,462 / 26,817 / 67,750, plus a ` locus` suffix.
  - **BunnyRandom terminal:** RED `NotProductionReady:field-aligned-network`, `BranchContinuationDegenerateEntry`, plus a ` locus` suffix.
  - **BunnyRandom receipts:** its 16 `partition edgePort` and 16 `edgePortDeparture` lines are unchanged.
- **Record verbatim, as measurements rather than criteria:**
  - BunnyRandom's locus;
  - every R1 and sector line, in any row or case;
  - the count of R1 lines per row.
- **Predictions (F1).** A miss is a finding, not a mismatch:
  - (P1) the locus parameter is `0/1` or `1/1` (a vertex entry), with `exact=0/1`;
  - (P2) exactly one R1 line has the locus seed, `step = history − 2`, and owner and owner branch equal to the locus face and branch;
  - (P3) no gate row and no Cylinder log has an R1 line.
- **Routes.**
  - Mismatch: `M6-CP3-TB120-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT-FULL-GATE-REV`.
  - Infrastructure: `M6-CP3-TB120A-P13-VERTEX-TRANSIT-OUTFLOW-RECEIPT-ORCH`.
  - MATCH: Review-only `M6-CP3-DEFN-P13-VERTEX-TRANSIT-OUTFLOW-OUTCOME` (P13-e.15). It uses the R1 sectors and the repository mesh to compute:
    - the H1 owner (seed on the carrier ray, for `EdgeTransit`);
    - whether that owner's field leaves the vertex.
  - **What the Review decides from that:**
    - H1 fixes it: an AX1-conformance CB, after a per-row census of `EdgeTransit` arrivals in accepted rows.
    - H2 remains: a named user decision on Amendment 22.

## 6. Gaps and carry

- **R1 has no unit test.** A test that expects `BranchContinuationDegenerateEntry` would pin the defect. R1's evidence is TB120's receipts, and R2 is the fallback if F1 is wrong.
- **R2 history is truncated.** It keeps only the first eight history steps (the projection's limit). For a long trace, the arrival step comes from R1, not from R2.
- **H1 and H2 are both hypotheses.** Neither is asserted.
- **Carried unchanged:**
  - O42 and O43;
  - D11=A, with D10 deferred;
  - CP2 491/491;
  - stable 66/17/49, debt 1, deferred 81;
  - CP3/selector497 unpromoted, with `chainRimSchedules=false`;
  - then 65A–65D.
- **Candidate status.** The terminal stays a **non-stable P13-e candidate**, with its owner stage named (the A2a vertex transit, Amendment 22) but its cause not yet established.

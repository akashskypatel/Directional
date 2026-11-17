# DEFN — carrier-contact node switch (RA-252, 2026-11-17 UTC)

`M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH` — Review, runtime-free (`-fsyntax-only` and offline reads of published artifacts only). Authority: [TB130 report](Architecture_M6_CP3_TB130_P13_Carrier_Proxy_Contact_Full_Gate_Execution_Report_20261117.md) (MATCH), [RA-251](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md#ra-251--adversarial-re-review-of-this-review-2026-11-17-utc), [RA-248 FC contract](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md), DESIGN Amendment 13. Freezes **FC-7′**, the exact CB154 switch diff and the TB131 criteria. Implements nothing.

## 1. Evidence re-opened

- **TB130 gate result** `14338844806`: ZIP SHA-256 `d93a644f800e2c4e641fdc31051556d62f4a55541ef74009c2b86aaedf927fcc`, which matches the published digest; 1,915 members. **Census result** `14339793522`: ZIP SHA-256 `c21ce302c41839542015b03bb6c18618798ed1e8dde74b40925c1693785532ca`, also matching. Both were downloaded into isolated scratch directories and read with `python3 -I`. No binary ran.
- **Census-to-receipt pairing.** In every raw log, the `carrierProxyContacts`/`terminalCutBeforeEnd` sequence is a concatenation of `C R R`: 14 gate logs are `CRRCRR`, 5 gate logs and BunnyRandom are `CRR`.
  - Each topology build that has a proxy contact node is therefore rejected at A2a′ by an H1 receipt; the second R is the failure replay.
  - **No accepted output contains a proxy contact node.** The outgoing proxies (198 in the gate, 39 in BunnyRandom) never reached rotation or output; each such build also had incoming proxies (2 per sphere build, 49 in BunnyRandom).
- **Exact binding.** It was `ok` in all 34 dry runs (`contactNodes` 12 per sphere build, 150 for BunnyRandom). `neither=0`, `unresolved=0` and `exactRecords=terminals` everywhere. The S1/S2 static model holds on every observation.
- **Cylinder and Vase** have no proxy node.

## 2. Correcting my RA-251 §S6 staging condition

§S6 said "unstaged only if no accepted row prints `lastOutgoing>0`". Read literally it fires: 19 PASS rows print outgoing proxies. Its premise was **accepted output** that carries an edge-locus contact, and §1 shows there is none. Those rows pass because their tests are neutral to the sphere rejection, not because a proxy contact was accepted.

An off-by-default option would leave every gate row unchanged. The only way to measure it would be to plumb the option through `RemeshPipeline`, `SurfaceCutGraph` and `GlobalTopologyPlan`, or to add tests, and it would still protect no accepted output.

**Decision:** ship the switch unstaged. This replaces the literal §S6 trigger with its stated purpose (RA-249: argue the switch changes only failing inputs). The TB131 criteria below make that argument falsifiable.

## 3. FC-7′ (normative; replaces FC-7)

**FC-7′.** A non-port network node that carries a `TraceIntersection` or `TraceSelfClosure` event is a face-contact node, whether or not its events carry a source edge. Its contact events are bound only from the terminating traces' exact `terminalContact` records (FC-1–FC-5, CB149 collector):
- the terminating trace's cut lies at its end;
- each struck trace's cut is its exact interior parameter.

A common-carrier `sourceEdge` on such an event is producer metadata, not a locus. It never resolves a cut position or a node locus.

Unchanged:
- Edgeless `FirstContact` nodes stay face-contact nodes, as before.
- An edge-carrying `FirstContact` without a trace-trace event (barrier termination, `SurfaceCellTracing.cpp:3925`), and every port node (`:2349`, `:4620`), keep the edge/vertex path.
- The A2a′ end-cut guard, its CB151 receipt, and every validator are unchanged.

The producer still publishes the proxy edge. Removing it would change `field_aligned_candidate_digest` (`:5309–5316`) and the validator's regenerated-candidate equality (`:5486–5490`) across the gate. It is not needed for correctness. **O45** is the consumer's use of the proxy; it is resolved by FC-7′ once TB131 matches.

## 4. CB154 exact diff

`Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Exact.diff`: SHA-256 `98e14bfe3fb030a691eed5d181f8e427e28072c2b00e96e47b2372ed214430b9`, 230 lines, numstat `30 105 src/geometry/EmbeddedGraphTopology.cpp`, `6 9 src/geometry/EmbeddedGraphTopology.h`. Precheck `git diff --quiet 95f082b144f2bbe145d764cbf6b3d10d123a6514 HEAD -- src include tests` (the CB153 source).
- `face_contact_nodes(network)` returns the non-port nodes with a `TraceIntersection` or `TraceSelfClosure` event, or with an edgeless `FirstContact`.
- `is_face_contact_event(event, nodes)` = node in that set and event of a contact kind. It is the single predicate for `collect_face_contact_nodes`, which serves both `build_arcs` and `build_rotation_system`, and for `build_node_loci`.
- The CB153 dry-run census (`carrier_proxy_contact_nodes`, the `includeCarrierProxyContacts` parameter, `report_carrier_proxy_contacts`, `<sstream>`) is removed. The header comments are updated.
- **Syntax check:** `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` rc 0 for EmbeddedGraphTopology/SurfaceCutGraph/GlobalTopologyPlan/FieldAlignedCurveNetworkTests, with warnings 22/27/24/42, the same as HEAD.
- **Locality argument.** When a network has no edge-carrying trace-trace event at a non-port node, the new predicate equals the old one event for event. The only difference would be an edge-carrying `FirstContact` sharing a node with an edgeless trace-trace event, which no producer creates: `field_aligned_publish_contact` gives both events one `sourceEdge`, and barrier nodes carry no trace-trace event. TB130 shows that set is empty in every topology build of the 934 rows without a census line, and in Cylinder and Vase.
- **Test gap.** There is no new unit test, because hand-built networks are impossible (RA-248) and a new row would change the frozen gate. The witnesses are TB131 criteria 3–6.

## 5. Gate rows that run the sphere (Haiku audits, verified at the cited lines)

| Rows | Verdict |
|---|---|
| 380, 388, 393, 394, 396, 397, 644, 645, 669, 686, 691, 694, 698, 699, 700, 843, 844 | Neutral. They assert network-stage facts or only print the cut-graph/A2a outcome. CB154 touches only EmbeddedGraphTopology, so the network is unchanged. |
| 648 `EmbeddedGraphEulerCensusCarriesAcrossTorusAndPrescribedSphereProductionPaths` | Passes today only through the `!sphere.cutGraph` SKIP return (`FieldAlignedCurveNetworkTests.cpp:13928–13938`). If the sphere cut graph now certifies, `:13941–13962` require **no plan** and a complete embedded-graph Euler locus. That expectation was written for a sphere that fails after the cut graph. |
| 858 `StopLocationShowsWhatEachStageReported` | `SurfaceCellTracingDisplayTests.cpp:153–172` uses the sphere as a failing example: it requires a `sourceFace` locus (`:155`, `:167`, `:169`), a stop location (`:171`) and `cellCount==0` (`:172`). |

## 6. TB131 frozen — `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-EXEC`

Run on the CB154 package with the same gate `941287fa…` (953 rows), census `3af1dc0d…`, deferred `fd433f54…` and harness `78b8002c…`. The comparator is TB130 (gate `14338844806`, census `14339793522`). **MATCH** requires all of the following:
1. **Unaffected rows.** The 934 gate rows without a TB130 census line have raw logs and substantive ledger records equal to TB130, under the TB129 normalizations (elapsed time, row164 complete-line multiset, newline framing). Cylinder (PASS, 288 quads) and Vase census logs are equal to TB130.
2. **Retired lines.** No log contains `EmbeddedGraphTopology.carrierProxyContacts`, and no `terminalCutBeforeEnd` line has `kind=TraceIntersection` or `kind=TraceSelfClosure`.
3. **Neutral rows.** Rows 380, 388, 393, 394, 396, 397, 644, 645, 669, 686, 691, 694, 698, 699, 700, 843 and 844 PASS.
4. **Premise rows.** Rows 648 and 858 PASS, or are RED only at the §5 assertion sites. Such a RED means the test's premise (the sphere is rejected before this point) is contradicted. It goes to Review and is not a switch regression.
5. **BunnyRandom.** It has no H1 receipt. Its terminal is data.
6. **Everything else.** Any other changed row, RED or log is a MISMATCH, which falsifies the locality argument.

**Data, not criteria:**
- The sphere's new outcome per row: stage, reason and locus, from the 644/698 printouts and the 648 log.
- BunnyRandom's new terminal.
- Any new rotation or face-contact reason.
- Whether row 648's assertions engaged.

**Routes:** MATCH → Review of TB131 (test-premise correction for 648/858 if they went RED; the next blocker for the sphere and BunnyRandom). MISMATCH → independent Review.

## 7. Turn sequence

1. This DEFN — COMPLETE.
2. `M6-CP3-CB154-P13-CARRIER-CONTACT-NODE-SWITCH` (compile only). Compile defect → `M6-CP3-PLAN-P13-CARRIER-CONTACT-SWITCH-STOP`; infrastructure → `M6-CP3-CB154A-P13-CARRIER-CONTACT-SWITCH-ORCH`.
3. `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-EXEC`.
4. `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-REV`.
5. Then `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, then `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6).

**Carried and parked:**
- H2 is not observed and is carried; so are O46, FC-1/FC-4 producer proof, the middle-piece direction witness and C5/O42/O43.
- CB145 parked.
- D11=A, D12=A, D10 deferred, D6 pending; `chainRimSchedules=false`.
- Stable 66/17/49, debt 1, deferred 81; CP2 491/491; CP3/selector497 unpromoted.

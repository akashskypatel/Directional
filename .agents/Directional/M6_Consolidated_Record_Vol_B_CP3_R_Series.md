# M6 consolidated record, volume B: CP3 R-series Review, specification and audit records (R2–R10)

This volume holds **45** former standalone `Architecture_M6*` records, moved here on 2026-11-09 by user instruction ("consolidate these records and prune if the content from each is already documented elsewhere"). No record's content was already documented elsewhere: verbatim-line coverage in the permanent documents was at most 27%. So each record is kept **verbatim** as one section below, and nothing is summarized. Only two things changed: heading levels are demoted by two, and links to other moved records point to their sections. Each original file existed standalone at commit `7a460a5e41c4a77a51b69db672e69f910532718c` (`git show 7a460a5e41c4a77a51b69db672e69f910532718c:.agents/Directional/<name>`). Anchors inside a record (`#…`) may resolve to an earlier record in this volume that has the same heading text. The [moved-record map](M6_Consolidated_Record.md#m6-moved-record-map-2026-11-09) lists every record and its volume.

| Original file | Title |
|---|---|
| [`Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md`](#architecture_m6_cp3_r10b_endpoint_rule_review_decisionmd) | RA-84 — R10B endpoint rule reviewed: accepted with amendments; four Code + Build units |
| [`Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md`](#architecture_m6_cp3_r2p3_hardrail_route_transport_review_decisionmd) | M6-CP3 R2-P3 — HardRail route transport: independent Review decision |
| [`Architecture_M6_CP3_R3_ABC_Review_Decision.md`](#architecture_m6_cp3_r3_abc_review_decisionmd) | M6-CP3 R3 — Decisions A, B, C: independent Review verdict |
| [`Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md`](#architecture_m6_cp3_r3_endpoint_attachment_review_decisionmd) | M6-CP3 R3 — P0/P1 endpoint-local attachment and transport: independent producer Design Review decision |
| [`Architecture_M6_CP3_R3_Sector_Derivation_Review_Decision.md`](#architecture_m6_cp3_r3_sector_derivation_review_decisionmd) | M6-CP3 R3 — source-topology sector derivation: independent producer Design Review decision |
| [`Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md`](#architecture_m6_cp3_r4_ambiguous_terminal_contact_feasibility_review_decisionmd) | M6-CP3-R4 — RA-46.5 ambiguous-terminal-contact feasibility: Review decision (RA-49) |
| [`Architecture_M6_CP3_R4_Authoring_Closeout_And_TB_Authorization_Review_Decision.md`](#architecture_m6_cp3_r4_authoring_closeout_and_tb_authorization_review_decisionmd) | RA-55 — R4 Code + Build authoring CLOSED; Test + Benchmark authorized, narrowly |
| [`Architecture_M6_CP3_R4_Carrier_Review_Decision.md`](#architecture_m6_cp3_r4_carrier_review_decisionmd) | Independent Review — the 39-identity endpoint census, and selection of the certificate model (RA-59) |
| [`Architecture_M6_CP3_R4_Contact_Binding_And_Gauge_Witness_Review_Decision.md`](#architecture_m6_cp3_r4_contact_binding_and_gauge_witness_review_decisionmd) | M6-CP3-CB1-ENTRY-R4 — terminal rail-contact binding and +U gauge witness: Review decision |
| [`Architecture_M6_CP3_R4_Edge_Index_Namespace_Review_Decision.md`](#architecture_m6_cp3_r4_edge_index_namespace_review_decisionmd) | M6-CP3-R4 — source-edge index namespace: Review decision (RA-47) |
| [`Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md`](#architecture_m6_cp3_r4_endpoint_authority_spec_review_decisionmd) | Architecture Review Decision — M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV |
| [`Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Review_Decision.md`](#architecture_m6_cp3_r4_endpoint_chart_harvest_review_decisionmd) | RA-67 — M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST Review Decision |
| [`Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Review_Decision.md`](#architecture_m6_cp3_r4_endpoint_chart_probe_review_decisionmd) | Architecture Review Decision — M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE-REV |
| [`Architecture_M6_CP3_R4_First_RED_Carrier_Reclassification_Review_Decision.md`](#architecture_m6_cp3_r4_first_red_carrier_reclassification_review_decisionmd) | RA-56 — the first RED is not a new candidate; it is a live reproducer of the 39-identity A4_ROUTE_CERTIFICATE_ |
| [`Architecture_M6_CP3_R4_Gauge_Consumption_Review_Decision.md`](#architecture_m6_cp3_r4_gauge_consumption_review_decisionmd) | M6-CP3-CB1-ENTRY-R4 — the +U gauge has no absolute consumer: Review decision |
| [`Architecture_M6_CP3_R4_Interior_Endpoint_Repair_Review_Decision.md`](#architecture_m6_cp3_r4_interior_endpoint_repair_review_decisionmd) | Independent Review — the interior-endpoint repair, its encoding collapse, and the pre-registered TB (RA-60) |
| [`Architecture_M6_CP3_R4_Interior_Witness_Measurement_Review_Decision.md`](#architecture_m6_cp3_r4_interior_witness_measurement_review_decisionmd) | RA-61 — M6-CP3-TB1-R4-INTERIOR-WITNESS measurement review decision (2026-10-15) |
| [`Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md`](#architecture_m6_cp3_r4_oriented_terminal_side_authority_review_decisionmd) | M6-CP3-R4 — oriented terminal source-face germ and front-filled-side ownership: REVIEW DECISION |
| [`Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Decision.md`](#architecture_m6_cp3_r4_overfull_a3_feasibility_review_decisionmd) | M6-CP3-R4 — overfull-A3 feasibility, and the authority seam beneath it: Review decision (RA-48) |
| [`Architecture_M6_CP3_R4_Predicate_Separation_Review_Decision.md`](#architecture_m6_cp3_r4_predicate_separation_review_decisionmd) | Architecture Review Decision — M6-CP3-CB2-R4-PREDICATE-SEPARATION |
| [`Architecture_M6_CP3_R4_Probe_Harvest_Review_Decision.md`](#architecture_m6_cp3_r4_probe_harvest_review_decisionmd) | Architecture Review Decision — M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR + M6-CP3-TB3-R4-PROBE-HARVEST |
| [`Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`](#architecture_m6_cp3_r4_producer_locus_review_decisionmd) | M6-DEFN-R5-R4-REV — producer locus for terminal contact, germ and face gauge: Review decision |
| [`Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`](#architecture_m6_cp3_r4_selected_branch_and_diagnostic_optout_review_decisionmd) | M6-CP3-R4 — selected-branch / filled-side provenance and the RA-43.4 opt-out policy |
| [`Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md`](#architecture_m6_cp3_r4_terminal_a3_first_rejection_review_decisionmd) | M6-CP3-R4 — terminal-A3 and terminal-sector first-rejection reachability: REVIEW DECISION |
| [`Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Review_Decision.md`](#architecture_m6_cp3_r4_terminal_a3_uniqueness_review_decisionmd) | M6-CP3-CB1-ENTRY-R4 — terminal A3 dual-path feasibility: Review decision |
| [`Architecture_M6_CP3_R4_Terminal_Conjunct_Extraction_Review_Decision.md`](#architecture_m6_cp3_r4_terminal_conjunct_extraction_review_decisionmd) | RA-62 — M6-CP3-TB2-R4-CONJUNCT-EXTRACT review decision (2026-10-15) |
| [`Architecture_M6_CP3_R4_Terminal_Contact_And_Gauge_Review_Decision.md`](#architecture_m6_cp3_r4_terminal_contact_and_gauge_review_decisionmd) | M6-DEFN-R5-R4-REV — terminal contact ownership and A3/source-gauge trust boundary: Review decision |
| [`Architecture_M6_CP3_R4_True_Control_Review_Decision.md`](#architecture_m6_cp3_r4_true_control_review_decisionmd) | Review decision — the true control answers the question, and it answers it more strongly than reported |
| [`Architecture_M6_CP3_R4_Witness_Breadth_Measurement_Review_Decision.md`](#architecture_m6_cp3_r4_witness_breadth_measurement_review_decisionmd) | Review decision — the breadth measurement, the carrier it measured, and the control it did not provide |
| [`Architecture_M6_CP3_R5_Junction_Carrier_Authority_Spec_Review_Decision.md`](#architecture_m6_cp3_r5_junction_carrier_authority_spec_review_decisionmd) | RA-68 — M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC Review Decision |
| [`Architecture_M6_CP3_R5_Route_Path_Reconciliation_Review_Decision.md`](#architecture_m6_cp3_r5_route_path_reconciliation_review_decisionmd) | Architecture Review Decision — M6 CP3 R5 route/path reconciliation (rungs 8 and 9) |
| [`Architecture_M6_CP3_R6_Corner_Assignment_Authority_Spec_Review_Decision.md`](#architecture_m6_cp3_r6_corner_assignment_authority_spec_review_decisionmd) | Architecture Review Decision — M6 CP3 R6 corner-assignment authority (rung 10) |
| [`Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md`](#architecture_m6_cp3_r7_corner_face_selection_repair_spec_review_decisionmd) | Architecture Review Decision — M6 CP3 R7 corner-face selection repair (rung 11) |
| [`Architecture_M6_CP3_R7_Lattice_UV_Candidate_Review_Decision.md`](#architecture_m6_cp3_r7_lattice_uv_candidate_review_decisionmd) | Architecture Review Decision — M6 CP3 R7 pre-snap lattice-UV candidates (rungs 14 and 15) |
| [`Architecture_M6_CP3_R7_Node_Admissible_Face_Set_Review_Decision.md`](#architecture_m6_cp3_r7_node_admissible_face_set_review_decisionmd) | Architecture Review Decision — M6 CP3 R7 node admissible-face set (rungs 12 and 13) |
| [`Architecture_M6_CP3_R8_Boundary_Override_Authority_Spec_Review_Decision.md`](#architecture_m6_cp3_r8_boundary_override_authority_spec_review_decisionmd) | Architecture Review Decision — M6 CP3 R8 boundary-override authority (rung 16) |
| [`Architecture_M6_CP3_R8_Source_Entity_Equivalence_Review_Decision.md`](#architecture_m6_cp3_r8_source_entity_equivalence_review_decisionmd) | Architecture Review Decision — M6 CP3 R8 source-entity equivalence (rungs 17 and 18) |
| [`Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md`](#architecture_m6_cp3_r4_factory_incidence_oracle_source_validity_static_audit_20261011md) | M6-CP3-CB1-ENTRY-R4 — hard-rail incidence oracle and frozen DCEL fixture source-validity audit |
| [`Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md`](#architecture_m6_cp3_r4_terminal_a3_uniqueness_design_review_request_20261011md) | R4 source-vertex terminal A3 dual-path expectation — independent Review request (2026-10-11) |
| [`Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`](#architecture_m6_cp3_r4_edge_index_namespace_conflict_review_stop_20261012md) | M6-CP3-CB1-ENTRY-R4 — source-edge index namespace collision (review stop) |
| [`Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`](#architecture_m6_cp3_r4_ra465_ambiguous_terminal_contact_review_stop_20261012md) | M6-CP3-CB1-ENTRY-R4 — RA-46.5 ambiguous terminal-contact feasibility REVIEW STOP |
| [`Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`](#architecture_m6_cp3_r4_ra432_oriented_germ_producer_boundary_review_request_20261013md) | M6-CP3-CB1-ENTRY-R4 — RA-43.2 oriented terminal germ producer-boundary review request (2026-10-13 UTC) |
| [`Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md`](#architecture_m6_cp3_r4_ra465_terminal_a3_first_rejection_review_stop_20261013md) | R4-TA3-01 — RA-46.5 terminal-A3 first-rejection feasibility: independent Review requested |
| [`Architecture_M6_CP3_R4_SID02_Produced_Cell_Reachability_Probe_20261014.md`](#architecture_m6_cp3_r4_sid02_produced_cell_reachability_probe_20261014md) | M6-CP3-CB1-R4-SID02-PROBE — source-only equal-opposite-corner reachability |
| [`Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`](#architecture_m6_cp3_r4_source_current_review_gate_20261014md) | R4 Code + Build source-current review gate (2026-10-14 18:30 UTC) |

## `Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md`; moved verbatim.

### RA-84 — R10B endpoint rule reviewed: accepted with amendments; four Code + Build units

**Turn:** `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV` (Review). **Subject:** `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md` at `000949084`. **S** = `src/geometry/SurfaceCellTracing.cpp`, **H** = `include/directional/geometry/SurfaceCellTracing.h`, **P** = `src/pipeline/RemeshPipeline.cpp`; lines at HEAD.

#### Gates (full clone)

- `review_check.py authority df37ffc19` PASS (ancestor of HEAD, no code drift); `boundary` PASS; `ledgers --base 43d5fd512` PASS; `document_drift_audit.py --root . --base 43d5fd512` 0 errors, 1 routine protected-change warning (handoff).
- `git diff d938ecb57..HEAD -- src include tests` is empty: the R10B snapshot is the TB10 source.

#### RA-84.1 Accepted

- Witness source (b): the ordered open-rail chain from `build_authoritative_surface_cell_rails`, carried to the factory alongside the existing terminal pair. Two-spoke inference (a) is correctly refused: without a T end nothing ties an I–R or R–R route to the named rail.
- Classification: authority plumbing at the verifier boundary (RA-72.5), not a Gate C producer-authored vertex-star certificate (RA-65.5/68.3/78.4). Gate C stays suspended.
- Per-endpoint R conjunction (§2), typed R distinct from `terminalVertex`, route anchor (§3), six-shape matrix (§4), I–I rejected by both checkers, T–T/T–I/C/I unchanged, `Missing`/`Ambiguous` never accepted.

#### RA-84.2 Correction — one trust root, not an independent witness

`hardFeatureEdges` is `hard_feature_edge_keys_from_rails(authoritativeRails)` (P:12348-12350, passed at P:12485), and the terminal pair is the same rails' first/last vertex (P:9756-9765). Re-checking the chain against `hardFeatureEdges` or the terminal pair is a **consistency check between projections of one rail product** (P:12335-12336, built from mesh + feature map before A4), not independent evidence. Only the source-face/component check (as the factory does for closed chains, S:8397-8433) is independent of that product. This is sufficient: T admission already trusts the same product, so R gets T's trust root, no stronger. Tests must not claim to detect a chain forged consistently with its `hardFeatureEdges`; they may claim detection only through source faces, component, or terminal mismatch.

#### RA-84.3 Correction — the factory has no shared-boundary interval

§2 lists "shared-boundary interval" among clauses both checkers derive. The factory never receives `sharedBoundaryInterval`; it is consumer-only (S:19413-19421), as for I today. On the factory side the corresponding authority is the route's contiguity on the projected chain.

#### RA-84.4 Required clauses added to the R rule

1. **Exactly two hard spokes.** The hard-feature edges incident to R are exactly its two chain edges and nothing else, mirroring the junction check (S:8800-8812: `hardSpokes == 2`, no foreign hard edge).
2. **R is the outer vertex of its end step.** For endpoint 0, R lies on `steps[0]` and not on `steps[1]`; for endpoint 1, symmetrically on the last step. On a one-step route R is the step vertex not claimed by the other endpoint. Two vertex endpoints are distinct. The matched chain interval fixes the orientation.
3. **Chain validity vs. R eligibility.** Projection and factory-entry validation accept every open chain with ≥2 vertices; "≥3 vertices" applies only to R eligibility. Applying it at entry would reject every single-edge open rail.
4. **Vacuous negative replaced.** "Internal chain vertex with only one hard spoke" cannot occur: a chain-internal vertex has two chain edges by construction. Replace it with two cases: one chain edge missing from `hardFeatureEdges` is rejected at factory entry (U2), and a third hard edge at R rejects the R endpoint (U3).

#### RA-84.5 Unit split and order (supersedes R10B §5 groups)

Each unit carries its own tests; R10B group E is not a separate unit. The order never creates a consumer-admits / factory-rejects state.

| Unit | Turn | Scope | Behaviour change |
|---|---|---|---|
| U1 | `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` | Move the factory's open-rail route rule (S:8576-8615) into one pure helper. The factory and the consumer both call it, the consumer just before its push at S:20243. | Consumer rejects what publication already rejects (closes RA-83.2). No `Produced` result changes. |
| U2 | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Add an open-chain map to the projection (P:9732-9767), the options (H:2246-2248), the publish call (S:20248-20253), `publish_phase_front_result` (S:12832-12869), `make` and a product accessor (H:1916-1917, 1965-1967, 1984-2018). Each chain is validated at entry like a closed chain (S:8397-8433). Its ends equal its rail's terminal pair, and its rail ids are one-to-one with the terminal contacts. | None. No cross-rail edge-uniqueness or coverage clause. |
| U3 | `M6-CP3-CB13-R10-FACTORY-RAIL-VERTEX-ENDPOINT` | Typed R field (H:1492-1509). The helper gains an R anchor and chain-interval contiguity for routes with an R end. Factory R branch (S:8699-8765), with star incidence for R (S:8495-8519). | The factory admits R. The consumer still never emits R; this factory-only admission is safe and lasts until U4. |
| U4 | `M6-CP3-CB14-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` | The consumer emits R (S:19397-19425) and uses the extended helper. End-to-end agreement test over the six shapes. | Full agreement. |

Each `CB` compiles only and is followed by its `TB` (`M6-CP3-TB11…TB14`, same suffix). A red `TB` routes to Review (Turn_Cadence rule 4). After TB14, a Review measures every conjunct on the 21 RP-01 records (RA-80.8) before any claim about RP-01. Only U1 is authorized now. U2–U4 are frozen in this order, and each is authorized only after the previous TB has been reviewed and is green.

#### RA-84.6 Observation (no action)

The factory's I branch does not check interval ordinals (consumer-only at S:19413-19421). The factory is weaker than the consumer here, which cannot break publication. Out of scope; unchanged.

#### RA-84.7 Documentation

- R10B §5 group A omitted the publish call site S:20248-20253; added in U2.
- The Definition opened a second `CURRENT` section in `TODO.md`; the Review merged it into the top section.
- RA-83's record is folded into `M6_Consolidated_Record.md`. The R10A census and the R10B rule stay live for U1–U4.

**Next:** `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR`. Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497; `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

## `Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R2P3_HardRail_Route_Transport_Review_Decision.md`; moved verbatim.

### M6-CP3 R2-P3 — HardRail route transport: independent Review decision

**Type:** runtime-free independent producer-owned architecture Review, resolving the `M6-CP3-CB1-ENTRY-R2` stop.
**Decision:** **Option (b) APPROVED — A4-owned ordered route transport certificate, with singleton as the
degenerate case. Option (a), a singleton-only route contract, is REJECTED as unsound.**
**Frozen as RA-36.** No runtime credit is granted; every RA-34.3 organic stop gate stands.

#### 1. The four decisive claims are confirmed from source

The review request's static findings were re-derived rather than accepted:

1. **A5's predicate is structurally singleton-only.** `rail_tau(fromFace, toFace)`
   (`src/pipeline/RemeshPipeline.cpp:4916-4957`) loops over **every** step of `first.route.steps()`, locates the
   `hardRailFieldTransitions()` record for `step.topology()`, and requires
   `record->firstFace == fromFace && record->secondFace == toFace` (or the swap); otherwise it returns
   `std::nullopt`. It is called as
   `rail_tau(from->…->placement.selectedFace, to->…->placement.selectedFace)`.
2. **A4 publishes per-edge records with no path.** `SurfaceHardRailFieldTransition`
   (`include/directional/geometry/SurfaceCellTracing.h:1477-1484`) is
   `{ edge, firstFace, secondFace, firstToSecond }` — one record per hard edge with its two *incident* faces and
   the oriented A3 τ. Nothing links records of distinct route edges, and there is no route-level τ.
3. **A4 has no one-step cap.** `observedSteps.push_back(step.value())`
   (`src/geometry/SurfaceCellTracing.cpp:11712`) appends one step per distinct retained source-edge topology with
   no cardinality bound, so A4 can emit multi-step routes.
4. **A5 selects endpoint faces from the trace, not the carrier.** `RemeshPipeline.cpp:4319-4337` takes each
   occurrence `selectedFace` from `canonicalTrace.face`.

**The consequence is a topological impossibility.** In a proper non-duplicate triangle mesh two distinct
triangles share at most one edge, so no two distinct source edges carry the same unordered incident-face pair.
A route with ≥2 distinct edges therefore cannot satisfy claim 1's predicate for more than one of its steps, and
deterministically yields `HardRailTransportMismatch` — a code asserting a **transport disagreement that was never
evaluated**.

#### 2. Why option (a) is rejected

- **The invariant it needs does not exist.** A singleton-only contract must *prove* the producer emits only
  singleton paired cross-region HardRail routes in the supported domain. Claim 3 shows no cap. Option (a) would
  therefore not be documenting an invariant; it would be **adding a producer restriction** that narrows the
  supported domain.
- **The domain it would narrow is legitimate.** Two consecutive hard-feature edges `(1,4)` and `(4,7)` already
  exist as a real bounded producer input (`tests/SurfaceCellTransitionQuotientTests.cpp:694-759`). Polyline hard
  features are ordinary CAD geometry, not a pathology. Declaring them unsupported is a capability regression
  presented as a contract.
- **Decisively, it does not avoid the work.** Even under a singleton-only contract, the miscoded failure in §1
  must be fixed: a multi-edge route must reject with a typed *unsupported-route* code rather than claim a
  transport mismatch it never tested. Once A4/A5 are obliged to distinguish "multi-edge route" from "τ
  disagrees", publishing the route is strictly more informative than refusing to.

#### 3. The actual architectural error, and the contract that follows

`rail_tau` conflates two different obligations and applies both to every step:

- **endpoint attachment** — the relation's two selected faces must attach to the route's ends;
- **transport agreement** — τ must be correct along the route.

Applying attachment at *every* step is what makes ≥2 steps impossible, and demanding equal τ at every carrier is
wrong in principle: τ along a path **composes**, it does not repeat. The correct decomposition is **attachment at
the two ends, composition through the interior** — under which a singleton route is simply the degenerate fold of
length 1. That yields one contract, not two.

##### RA-36 (frozen by this Review)

**A4 publishes, per paired cross-region HardRail route, an ordered oriented transport certificate:**

1. the ordered sequence of `SourceEdgeTopologyKey` steps in canonical route orientation;
2. for each step, its two typed incident `SourceFaceTopologyKey` values and the exact oriented A3
   `firstToSecond` quarter-turn, copied/validated against `FieldTransportAtlas::transition_value`;
3. **endpoint attachment**: which face of the first step the `a` endpoint attaches to, and which face of the last
   step the `b` endpoint attaches to;
4. **path connectivity**: consecutive steps must share exactly one typed source face.

**A5 consumes only that published certificate.** It composes `τ_ab` as a typed fold along the published path
(`Z4` addition with per-step orientation; reversed steps negate), verifies that the relation's two
`placement.selectedFace` values equal the published endpoint attachment faces, and then applies the already
frozen `(B_b − B_a − R_coord − τ_ab) mod 4 = 0` at **both** endpoint pairs. The reverse relation must invert
coordinate, branch and τ orientations together; orientations may not be mixed.

**Consistency obligations.** For consecutive carriers both side transports come from A3 source-face transition
authority, and the cross-rail square `χ_(i+1) ∘ φ_a = φ_b ∘ χ_i` must hold. Compose as a typed path — **never**
average, never demand equal τ per carrier, never select the first step. A4 rejects, typed and fail-closed, on:
absent or ambiguous path, disconnected face star, nontrivial singular holonomy, nonreciprocal A3 transitions, or
a mismatching hard-feature owner. A5 must **not** infer path, attachment or τ from regional `F` gauges, sheet
labels, geometric proximity, arbitrary graph traversal, first-step selection, fabricated records, or any new
unreviewed configuration switch.

**Singleton is the degenerate case and must not regress.** Path length 1; attachment faces are that edge's two
incident faces; composed τ is its `firstToSecond`. Existing singleton behaviour must be preserved exactly — the
frozen `497 = 30 + 12 + 449 + 6` gate and every currently green identity are the regression guard.

**Honest failure codes.** A route A4 cannot certify must reject with a typed code naming *that* cause. Reusing
`HardRailTransportMismatch` for an uncertifiable or unsupported route is prohibited: it asserts an evaluation
that did not happen.

#### 4. What this decision does not establish

It settles which contract governs; it does not assert that any produced multi-edge HardRail route exists. No
such route has been demonstrated — the two-hard-edge fixture declares inputs, it does not prove A4 emits a
spanning reciprocal route. **If the bounded search yields no multi-edge produced positive, the multi-edge path
code is unexercised and must not be cited as validated**; the same discipline that governed the degenerate
nonzero-Z4 witness at `M5-CP3-DEFN-R1` applies here.

All RA-34.3 R2-P3 stop gates remain mandatory and are unaffected by this decision: an independently generated
baseline-green HardRail witness with **odd τ ∈ {1,3}**, `F_b − F_a ≠ τ`, a sign-inversion negative, and
reciprocal/face-permutation invariance. If the bounded real-producer search yields none, **stop for Review**.

#### 5. Verification limits

Re-derived from repository bytes: `rail_tau`'s per-step predicate and its call with selected faces; the
`SurfaceHardRailFieldTransition` record shape; the uncapped `observedSteps.push_back`; the trace-derived
`selectedFace`; and the two-hard-edge fixture's existence. The topological argument (two distinct triangles share
at most one edge) is a property of proper non-duplicate triangle meshes, assumed as the supported input domain.
Not established: existence of any produced multi-edge HardRail route, or of a qualifying odd-τ witness.

## `Architecture_M6_CP3_R3_ABC_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R3_ABC_Review_Decision.md`; moved verbatim.

### M6-CP3 R3 — Decisions A, B, C: independent Review verdict

**Type:** runtime-free independent producer Design Review resolving the `M6-CP3-CB1-ENTRY-R3` A/B/C block.
**Verdicts:** **A → factory-bound atlas re-derivation (option A2, minimal form). A1 rejected.**
**B → CB may close on authoring + compile, with conditions. C → yes: separately authorized, separately counted,
diagnostic weight only.** Frozen as **RA-40**. No runtime credit; all RA-34.3 / RA-36.4-.6 / RA-38 / RA-39 gates
stand.

#### Decision A — who attests A3 nonrail step values?

##### Verdict: A2 in its minimal form. A1 is rejected as insufficient.

**1. The square cannot close this hole, structurally.** A balanced `+1 mod 4` on the first A3 step of *both*
paths leaves `χ_next ∘ φ_A == φ_B ∘ χ_prev` satisfied. That is not a defect in the square — a consistency
relation is invariant under a gauge shift applied to both sides. No amount of consistency checking can
substitute for authenticating the values, which is the same structural fact recorded for `Z4` at
`M5-CP3-DEFN-R1` (composition order is numerically inert; only values and signs are testable).

**2. A1 leaves `make` accepting manufactured certificates.** `make`'s signature
(`src/geometry/SurfaceCellTracing.cpp:7969-7982`) takes `hardRailFieldTransitions` and
`hardRailRouteCertificates` as **data**, with no atlas and therefore no means of authentication. Under A1, any
test or consumer that constructs or rebuilds a certificate obtains a passing A4 product. That is the
self-authorizing-oracle family this project has repeatedly been bitten by — the mechanism-versus-produced
boundary of M5 frozen §8.1, and the circular-oracle guard recorded at `M5-CP3-TB1-R15-R1-REV`. A1 would have to
impose that prohibition by decree anyway.

**3. A2 needs no new attestation schema — the authority is already reachable.** This is the decisive point.

- `SurfaceCellTracingOptions::fieldTransportAtlas` is already `const authority::FieldTransportAtlas *`
  (`include/directional/geometry/SurfaceCellTracing.h:2186`).
- A4's junction authoring already derives each value through
  `authoritativeOptions.fieldTransportAtlas->transition_value`.
- `FieldTransportAtlas::matches_source_faces` already exists
  (`include/directional/authority/FieldTransportAtlas.h:893`) and already requires exact source matrix,
  authority and vertex count.

The **only** gap is that `SurfacePhaseFrontBuildState` does not carry the atlas and `make`'s signature lacks it.
So A2-minimal is: bind the already-available atlas at the factory boundary, require `matches_source_faces`
against the same source, and have `make` **re-derive each value from `transition_value` and require exact
equality**. Checking each value individually against ground truth rejects balanced tampering, which pairwise
consistency cannot.

This is the **fourth** occurrence of one pattern in this milestone — RA-34.3 (τ retained before the
nontraversable marking), RA-35 (per-wedge bindings retained before the sort/unique collapse), RA-38 (the star is
traversed; only the carrier cut was missing), and now the atlas reachable in options but not bound at the
factory boundary. The cure is the same every time: **reach or publish what the producer already holds.**

**4. The hole is wider than the question stated.** Decision A asks about *nonrail* step values, but `make` also
accepts `hardRailFieldTransitions` — the per-carrier χ values — as unauthenticated data, with the same balanced
tampering exposure. One atlas binding authenticates **both** χ and φ. Scoping the fix to φ alone would leave the
same defect one field over.

**5. The migration is a feature, not only a cost.** Eleven of the twelve public factory invocations are tests
(production at `:12195`; tests across three files). A test that cannot supply a source-bound atlas **should not
be manufacturing route certificates for `make`** — so the migration pressure enforces exactly the discipline A1
would have had to add as a prohibition.

##### Binding conditions

- `make` requires an atlas bound by `matches_source_faces` to the same source matrix, authority and vertex
  count. A mismatched atlas is a typed fail-closed error, never a permissive path.
- `make` re-derives **every** A3-sourced value it is handed — each nonrail φ and each carrier χ — via
  `transition_value`, and requires exact equality including reverse orientation and reciprocity.
- **Absent atlas → typed fail-closed.** There is no "unauthenticated but accepted" mode.
- A global per-face branch-gauge difference across cuts or holonomy may **not** substitute for true A3 values
  (already withdrawn at RA-31a).
- All twelve call sites migrate explicitly and exhaustively; no default-null convenience overload.
- RA-39 endpoint-local single-terminal-carrier χ is unchanged. This is **not** a licence to reintroduce RA-37a
  fan detours.

#### Decision B — CB versus TB evidence sequencing

##### Verdict: option 1. R3 CB may close on complete authoring plus exact eight-target compile/package evidence.

The binding plan forbids running Directional binaries in CB and places the **497** execution in a distinct TB.
A CB closure gate that simultaneously demands "actually produced, nonvacuous D1/D2/D3/D5 and A6/A7 witness
outcomes" and "recovery of 47 prior accepted regressions" is therefore **unsatisfiable** — no compiler can supply
it. This is the identical self-conflicting precondition resolved at `M6-CP3-CB1-ENTRY-R2` precondition 2, and the
same resolution applies: author and verify **statically**; prove existence at the gate that can run.

##### Binding conditions

- CB's closeout claims **no** produced positive, and says so explicitly.
- Nonvacuity must be enforced **in compiled assertions**, not asserted in prose.
- The authorized TB successor is **named before** root `STATUS` becomes `COMPLETE`.
- The 497 gate, every organic D1/D2/D3/D5 and A6/A7 witness, the odd-τ witness, and the 47 accepted→RED
  recoveries remain **TB** obligations, not CB claims.
- Each TB RED is investigated individually and returned to a **new** authorized repair turn; no blanket
  reclassification.
- Tool or time exhaustion is **not** `BLOCKED`. `BLOCKED` is reserved for a genuine authority or evidence gap.

#### Decision C — the four excluded source-defined tests

##### Verdict: yes — a separately authorized, separately counted artifact-only focused diagnostic run, carrying diagnostic weight only.

The four tests are `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`,
`M6CP3.HardRailPublishedTauRequiresIncidentSourceFaces`,
`M6CP3.A6SeamDirectionRejectsForeignFaceAndWedgeBindings`, and
`M6CP3.A7TypedWedgeSheetMismatchRejectsCachedMembership`.

Both alternatives are unacceptable. **Folding them into 497** mutates a frozen, single-owned gate — prohibited,
and it would also silently imply they had run. **Leaving them unrun** makes four authored contract tests
zero-evidence, which is "structural presence is not behavioural coverage" (`LESSONS.md` 171) — the same error as
an authored-but-unexercised witness.

So: run them in a **separate** artifact-only focused diagnostic turn, **counted separately** from 497, with
results carrying **diagnostic weight only — no acceptance credit** — until a Review folds them into a successor
gate under the established pre-commitment discipline (declare the successor gate's exact composition and census
**before** the publishing turn builds it, as has now held for four consecutive selector publications).

#### Non-claims

This decision settles trust ownership, evidence sequencing and the status of four excluded tests. It establishes
**no** runtime result. Existence of a produced multi-carrier paired HardRail front, the organic D1/D2/D3/D5 and
A6/A7 witnesses, the odd-τ witness, and the 47 accepted→RED recoveries all remain unproven and stop-gated. The
stable ledger stays **64 / 17 / 47**, debt **1**.

#### Verification limits

Re-read from source: `make`'s full signature and its absence of an atlas parameter; the options atlas pointer at
`SurfaceCellTracing.h:2186`; `matches_source_faces` at `FieldTransportAtlas.h:893`. Accepted as reported: the
balanced-tamper algebra, the twelve call-site census, the eight-target GREEN compile receipts, and the frozen
497 composition.

## `Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R3_Endpoint_Attachment_Review_Decision.md`; moved verbatim.

### M6-CP3 R3 — P0/P1 endpoint-local attachment and transport: independent producer Design Review decision

**Type:** runtime-free independent producer Design Review resolving the remaining `M6-CP3-CB1-ENTRY-R3` STOP.
**Decision:** **BLOCK RESOLVED — frozen as RA-39.** Endpoint-local **attachment** requires **no new authority**;
the **transport paths** require one new published field whose content is derivable from RA-38's sector cut.
The current `endpoint_certificate` is categorically wrong in shape, and the fix makes it *smaller*, not larger.
No runtime credit; all RA-34.3 and RA-36.4/.5/.6 gates stand.

#### 1. What the endpoint pairs actually are

`src/geometry/SurfaceCellTracing.cpp:18271-18285` requires `first.route == second.route.reversed()` for the
reciprocal pair. Therefore `first.from` and `second.to` lie at the **same spatial end** of the rail polyline, and
`first.to`/`second.from` at the other. The two calls
`endpoint_certificate(first.from.face, second.to.face)` and
`endpoint_certificate(first.to.face, second.from.face)` are consequently **cross-rail pairs, one per spatial
end** — each pair holding one face on each side of the rail at that end.

This is the fact the current implementation does not use. At `:18297-18330` it sets `current = firstAttachment`
and then walks **every** route carrier accumulating τ, attempting to travel from one side's face at one end,
across the whole polyline, to the other side's face. That is neither a local crossing nor a well-defined path.
It is the same end-to-end "walk along one side" shape that produced the superseded RA-36.1 defect, now visible at
the endpoint level.

#### 2. Endpoint-local attachment is derivable with no new authority

For endpoint pair `j`, the **terminal carrier** is the route's first (`j = 0`) or last (`j = 1`) oriented step —
well defined because `CanonicalRoute::oriented_steps()` is ordered. Attachment is then:

```text
valid(j)  ⟺  { from_j , to_j }  ==  { C_j.firstFace , C_j.secondFace }   (as an unordered pair)
χ_j       =   C_j.firstToSecond, oriented by which of the two faces is from_j
```

where `C_j` is that terminal carrier's already-published `SurfaceHardRailFieldTransition`
(`include/directional/geometry/SurfaceCellTracing.h:1477-1484`). **No path walk, no threading, no new producer
input.** If the pair is not the terminal carrier's incident pair, there is **no local attachment** and the
certificate fails closed — which is precisely RA-37a's prohibition on "treating a path reaching the opposite
spatial endpoint as a local attachment."

Consistency with RA-38 on the reviewed 3×3 fixture: route `[(1,4), (4,7)]` gives terminal carriers `(1,4)` with
faces `{0,3}` and `(4,7)` with faces `{4,7}`. RA-38's sector cut places `0, 4 ∈ A` and `3, 7 ∈ B`, so **each
endpoint pair holds exactly one face per sector** — one per side of the rail, as a cross-rail pair must.

#### 3. The transport paths belong to the square, not to the crossing

The within-sector radial chains are **not** needed for an endpoint crossing — that is a single carrier. They are
needed only for RA-37a's along-rail square, which *compares* the two endpoint mappings after explicit transport:

```text
χ_1 ∘ φ_A  =  φ_B ∘ χ_0
```

with `φ_A` transporting the side-A face from carrier `C_0` to carrier `C_1` **within sector A**, and `φ_B`
likewise within sector B, along **non-rail** A3 transitions. On the fixture: `φ_A : 0 → 1 → 4` and
`φ_B : 3 → 6 → 7` — exactly RA-38's two arcs. Path-independence across admissible chains within a sector, and
rejection on nontrivial holonomy, carry over from RA-38 unchanged.

#### 4. The schema gap is real, and the correction shrinks the certificate

`SurfaceHardRailRouteEndpointCertificate`
(`include/directional/geometry/SurfaceCellTracing.h:1488-1493`) is
`{ firstAttachment, secondAttachment, orientedSteps, composedTurn }`, where `orientedSteps` is a vector of
**carrier crossings only** and `composedTurn` is a single end-to-end fold. Two things follow:

- **`orientedSteps` and `composedTurn` are the wrong shape.** An endpoint certificate concerns **one** terminal
  carrier, so it needs that carrier and its oriented crossing `χ_j` — not every carrier and not an end-to-end
  composition. The correction *removes* state.
- **There is nowhere to publish the radial witnesses.** The struct has no field for per-junction, per-sector
  ordered **non-rail** A2b source-edge transitions. This is the genuine gap the STOP record identified, and it
  is correctly described there as "not fixed by renaming the existing fields."

#### 5. RA-39 (frozen by this Review)

- **RA-39.1 — attachment.** For endpoint pair `j`, the terminal carrier `C_j` is the route's first/last oriented
  step. The certificate is valid only if `{from_j, to_j}` equals `{C_j.firstFace, C_j.secondFace}` as an
  unordered pair, and `χ_j` is `C_j.firstToSecond` oriented by which face is `from_j`. Any other pair → typed
  fail-closed "no local attachment". No path walk is performed at an endpoint.
- **RA-39.2 — sector agreement.** Each endpoint pair must hold exactly **one face per RA-38 sector**. A pair with
  both faces in one sector, or either face outside the junction star when a junction exists, fails closed.
- **RA-39.3 — transport.** A4 publishes, per junction and per sector, the **ordered non-rail A2b source-edge
  witnesses** of the within-sector radial chain joining consecutive carriers' same-side faces. These exist only
  to serve the square; they are never used as an endpoint crossing.
- **RA-39.4 — the square compares.** Validation applies `χ_1 ∘ φ_A = φ_B ∘ χ_0` as a **comparison after explicit
  transport**. Blind composition of χ across carriers remains prohibited, as does any end-to-end `composedTurn`.
- **RA-39.5 — schema.** Replace the endpoint certificate's `orientedSteps`/`composedTurn` with the single
  terminal carrier and its oriented `χ_j`, and add the RA-39.3 radial witnesses. A5 consumes only this published
  immutable certificate — no path search, no sheet/region label inference, no first-step selection.
- **RA-39.6 — singleton degenerates correctly.** For a one-carrier route both endpoint pairs share that carrier,
  there is no junction, `φ_A`/`φ_B` are identity and the square is trivially the reciprocity already required.
  Existing singleton behaviour must not change.

#### 6. What this decision does not establish

It settles attachment, transport ownership and the certificate's shape. It does **not** establish that A4
produces a paired HardRail front over a multi-carrier route; a hand-authored input fixture is not a produced
certificate. If the bounded real-producer search finds none, the multi-carrier path stays **unexercised and must
not be cited as validated**. All RA-34.3 R2-P3 stop gates stand — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`, a
sign-inversion negative, reciprocal/face-permutation invariance — and an empty search **stops for Review**.
Diagnostic-first-locus inside `invalid_route()` is still required before any corrective semantic edit.

#### 7. Verification limits

Re-read from source: the reciprocal `route == route.reversed()` requirement and both `endpoint_certificate`
call sites; the walk-all-carriers accumulation at `:18297-18330`; the endpoint and carrier struct definitions;
`CanonicalRoute::oriented_steps()` ordering. Carried from RA-38: the mechanically derived star cycle and sector
arcs for the reviewed fixture. Not established: existence of a produced multi-carrier paired front.

## `Architecture_M6_CP3_R3_Sector_Derivation_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R3_Sector_Derivation_Review_Decision.md`; moved verbatim.

### M6-CP3 R3 — source-topology sector derivation: independent producer Design Review decision

**Type:** runtime-free independent producer Design Review resolving the `M6-CP3-CB1-ENTRY-R3` preflight STOP.
**Decision:** **BLOCK RESOLVED — the two oriented sectors are well-defined and derivable from authority A4
already holds. Frozen as RA-38, implementing RA-37a correction (1); RA-37a is not replaced.**
**Two unsound validators are identified and must be corrected; they are distinct defects.**
No runtime credit; all RA-34.3 and RA-36.4/.5/.6 gates stand.

#### 1. The STOP was correct and the preflight discipline held

`M6-CP3-CB1-ENTRY-R3` refused to proceed rather than guess a sector, a global face-star potential, a
first-by-row face, or a new τ. It changed no production source and attempted no compile. That was right: RA-37a
asserts the *existence* of two unique oriented sectors without giving the construction, and an implementation
turn must not invent one. This Review supplies the construction.

#### 2. The sectors are the two arcs of the vertex-star cycle cut by the incident hard carriers

At a rail junction vertex `v` on an interior orientable manifold link, the faces of `v`'s star form a **cycle**
under the "share a spoke edge at `v`" relation. Exactly two hard carriers are incident to `v` on a
non-branching rail. **Cutting the cycle at those two carriers yields exactly two arcs — the two unique oriented
sectors — and each incident carrier contributes exactly one face to each arc.**

Derived mechanically on the reviewed 3×3 fixture
(`tests/SurfaceCellTransitionQuotientTests.cpp:694-740`), faces
`0=(0,1,4), 1=(0,4,3), 2=(1,2,5), 3=(1,5,4), 4=(3,4,7), 5=(3,7,6), 6=(4,5,8), 7=(4,8,7)`:

```text
star(v=4) faces          : {0, 1, 3, 4, 6, 7}
star cycle               : 0 → 1 → 4 → 7 → 6 → 3 → 0
cut at carriers (1,4),(4,7)
  sector A               : {0, 1, 4}
  sector B               : {3, 6, 7}
carrier (1,4) faces {0,3}: 0 ∈ A, 3 ∈ B      (exactly one per sector)
carrier (4,7) faces {4,7}: 4 ∈ A, 7 ∈ B      (exactly one per sector)
```

This reproduces exactly the two oriented radial chains the STOP record observed (`0→1→4`, `3→6→7`) and shows
they are not an artefact of the fixture: they are the two arcs of the cut star. **Each sector is therefore a
well-defined *side* of the rail polyline**, and within one sector the consecutive carriers' faces are connected
by a radial chain of **non-rail** A3 transitions. No carrier-to-carrier face identity is involved, which is why
the superseded RA-36.1 premise failed.

**Fail-closed cases, which coincide exactly with RA-37a's already-frozen domain:**

- **boundary vertex** — the star is a path, not a cycle; cutting at two carriers yields three arcs. Ambiguous →
  STOP.
- **more than two incident hard carriers** (rail branch/junction point) — more than two arcs; no unique pair →
  STOP.
- **exactly one incident carrier** — the rail terminates at `v`; there is no through-transport to certify.
- **non-manifold or singular star** — not a cycle → STOP.
- **foreign barrier inside an arc** — that sector is not a valid transport path → STOP.

RA-37a already restricts sectors to "connected orientable two-manifold links without foreign barriers, otherwise
fail closed." The construction above lives inside that domain; RA-37a needs no amendment.

#### 3. Two distinct unsound validators, not one bug

`src/geometry/SurfaceCellTracing.cpp:8019-8118` contains **two independent** errors:

1. **Face-chaining across carriers** (~`:8078`): `previous.secondFace != transition.firstFace` → reject. This is
   the same primal/dual category error as the superseded RA-36.1, at a second site. For the reviewed rails it
   always fires, because `{0,3} ∩ {4,7} = ∅`. It must be replaced by **within-sector radial chaining**.
2. **Endpoint-path cardinality** (~`:8063`): `endpoint.orientedSteps.size() != expectedSteps.size()` ties the
   endpoint path length to the number of route carriers. That is unsound in general: the local path length is
   set by **fan valence at each junction**, not by carrier count.

**The second defect is hidden by the fixture.** The 3×3 case has two carriers and a radial chain of length two,
so the cardinality rule is satisfied *by coincidence*. A correction that fixes only the chaining and validates on
3×3 will pass while this rule remains wrong, and will fail on the first fixture whose fan valence differs. Both
must be corrected together.

A third ordering defect carries over: the A4-side gate at `:18312-18330` must not precede the sector/junction
logic, or the corrected path remains unreachable — the same reachability trap as `M5-CP3-TB1-R3-REV`.

#### 4. Publish, do not invent — the third instance of this pattern

A4 already holds everything the construction needs. `railFanPotentials` already traverses the **whole** vertex
star (`:18120-18206`), and A4 already knows the hard carriers because it builds `hardRailFieldTransitions`. The
only missing step is the **cut** of the star cycle at those carriers, which is a local derivation over data A4
already owns.

That makes this the third occurrence of one shape in this milestone: **RA-34.3** (τ retained before the
nontraversable marking destroyed access), **RA-35** (per-wedge bindings retained before the sort/unique collapse),
and now **RA-38** (the star is already traversed; only the carrier cut is missing). In every case the cure is to
publish or reach authority the producer already computes — never to add new input or let a consumer infer.

**Explicitly forbidden:** a guessed sector; a global face-star potential used as ownership rather than as a
post-ownership cross-check; first-by-row face selection; a new τ definition; any A5-side path search or
inference from sheet/region labels. A5 consumes only the published immutable certificate.

#### 5. What this decision does not establish

It settles that the sector decomposition is sound, derivable and within RA-37a's domain, and it names two
validator defects. It does **not** establish that a real A4-produced multi-carrier paired HardRail front exists —
the STOP record is right that a hand-authored input fixture is not a produced certificate. If the bounded
real-producer search yields no multi-carrier positive, the multi-carrier path remains **unexercised and must not
be cited as validated**, exactly as at `M5-CP3-DEFN-R1`.

All RA-34.3 R2-P3 stop gates stand unchanged — odd `τ ∈ {1,3}`, `F_b − F_a ≠ τ`, a sign-inversion negative,
reciprocal/face-permutation invariance — and an empty bounded search **stops for Review**. RA-36.4/.5/.6 remain:
singleton must not regress, uncertifiable routes reject with a typed code naming that cause, and no runtime
credit accrues.

#### 6. Verification limits

Derived mechanically from repository bytes: the fixture triangulation; the star of vertex 4 and its cycle; the
sector arcs after cutting the two carriers; the one-face-per-sector split of each carrier. Re-read from source:
both validator defects at `:8019-8118`, the A4-side gate at `:18312-18330`, and `railFanPotentials`' whole-star
traversal at `:18120-18206`. Accepted as reported: the R2 artifact tallies and the source-snapshot hashes in the
STOP record.

## `Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Ambiguous_Terminal_Contact_Feasibility_Review_Decision.md`; moved verbatim.

### M6-CP3-R4 — RA-46.5 `ambiguous-terminal-contact` feasibility: Review decision (RA-49)

**Turn:** `M6-CP3-R4-AMBIGUOUS-TERMINAL-CONTACT-ARCH-REV` (independent Review).
**Adjudicates:** `Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`.
**Verdict:** the retirement request is **REJECTED**. The branch is **REACHABLE**; the RA-46.5 obligation
**STANDS**, with the witness named exactly. One *different* RA-46.5 negative —
`nonmanifold-terminal-star-spoke` — **is** unrealizable and is retired in its place under RA-48's existing
guards. New finding **R4-CTC-01** (validate-after-use ordering).
**Method:** re-derived from repository bytes at `2756c2323`. No binary built, no test executed, no runtime credit.

---

#### 1. The STOP's conditional claim is true; its premise does not hold on the live path

The request's deduction is: *"the `if (terminalVertex) return reject("ambiguous-terminal-contact")` branch is
unreachable **for a valid factory-admissible producer receipt**."* Read with that qualifier, it is correct. The
error is in the sentence that follows it: *"A malicious duplicate terminal pair is rejected **earlier** by the
checked factory."*

**The checked factory runs later, not earlier.**

- `endpoint_certificate` is a lambda defined at `src/geometry/SurfaceCellTracing.cpp:18999` and **invoked** at
  `:19167` and `:19170`, inside the per-rail loop of `build_surface_cell_network`.
- The contact it consumes is read **unvalidated** at `:18997`:
  `authoritativeOptions.hardRailTerminalContacts.find(*first.railId)`.
- `publish_phase_front_result` — the only route to `SurfacePhaseFrontProduct::make`, and hence to the
  distinctness check at `:8295-8299` — is called at **`:19446`**, after that loop closes, and is handed the
  *same* `authoritativeOptions.hardRailTerminalContacts`.

So on the live path the ordering is **consumer first, factory second**. `:19052` is the **first** rejecting
predicate for a duplicated endpoint pair, which is precisely what RA-46.5 requires. Nothing upstream enforces
factory-admissibility before `endpoint_certificate` reads the contact.

This is a **stage-locus error** — a guard cited as protecting a predicate that in fact executes before it. It
is the same class as the error corrected in RA-43.2 (an owner named in the wrong pipeline stage), and it is
why the request's conclusion inverts.

---

#### 2. The impossibility the STOP found is real, sharper than stated, and about something else

Two **distinct** vertices genuinely cannot both qualify. The reason is narrower and stronger than the request's
argument, and worth recording because it determines what the witness must be.

Qualification at `:19049-19051` is a **conjunction**, and one conjunct settles it alone:

```cpp
for (const auto vertex : contact->second.endpoints) {
  if ((edge.first() != vertex && edge.second() != vertex) ||
      !exact_corner(fromPoint, vertex) ||
      !exact_corner(toPoint, vertex)) continue;
  if (terminalVertex) return reject("ambiguous-terminal-contact");
  terminalVertex = vertex;
}
```

For a **fixed** `fromPoint`, `exact_corner(fromPoint, ·)` (`:19034-19046`) is a **function**, not merely a
restrictive test. `corner` is assigned only where `faces(point.face, i) == vertex.index()`; the subsequent
bit-exact one-hot test then forces `i` to be the single position `c` at which `barycentric[c] == 1.0`.
Therefore the only vertex that can pass is `faces(fromPoint.face, c)` — exactly one. The conjunct admits at
most one vertex **regardless** of `toPoint`, of the carrier-membership conjunct, of `contact.component`, and of
the checked factory.

**Consequence:** the branch has exactly **one** reachable route — the same vertex qualifying **twice** — and
that requires `endpoints` to hold a duplicate. The request located a true impossibility (two distinct vertices)
and then attributed its guard to the factory, when the impossibility needs no guard at all and the reachable
route has one that fires too late.

---

#### 3. The witness, named exactly

`endpoints` is `std::array<authority::SourceVertexId, 2>`
(`include/directional/geometry/SurfaceCellTracing.h:1532`). A duplicate is **representable by type** — the
array has no distinctness invariant, and the only distinctness check anywhere is the factory's at `:8296`,
which runs at `:19446`.

A source-valid first-rejection witness is therefore:

1. `authoritativeOptions.hardRailTerminalContacts[railId] = {component, {v, v}}` — the same typed
   `SourceVertexId` in both slots.
2. `v` is an endpoint of the carrier `edge` (satisfies the first conjunct).
3. `fromPoint` and `toPoint` are each bit-exact one-hot at a corner holding `v` (satisfies both
   `exact_corner` conjuncts).

Iteration 1 passes the conjunction and sets `terminalVertex = v`. Iteration 2 passes the **identical**
conjunction, finds `terminalVertex` set, and returns `reject("ambiguous-terminal-contact")` at `:19052`.

Nothing is fabricated: the vertex genuinely exists, the barycentrics are genuinely one-hot, the carrier
membership genuinely holds. No tolerance is relaxed, no guard weakened, no approximation introduced, and no
non-source object is constructed. The request's own refutation criterion asked for "two unequal typed terminal
IDs"; that criterion was too narrow — it excluded by assumption the only route the code admits.

---

#### 4. R4-CTC-01 — validate-after-use, and why the obligation cannot be retired

`build_surface_cell_network` **uses** caller-supplied `hardRailTerminalContacts` for routing and certificate
decisions from `:18997` onward, and only asks the checked factory to validate them at `:19446`. The duplicate-
endpoint condition is consequently checked **twice, with different strictness and different reporting**:

| Site | Order | Form |
|---|---|---|
| `:19052` consumer | **first** | string predicate `ambiguous-terminal-contact` |
| `:8295-8299` factory | second | typed `InvalidSourceAuthority` |

The upstream check is the one that actually fires, and it is the weaker of the two in reporting. So the
consumer's guards here — `ambiguous-terminal-contact`, `no-exact-terminal-corner`, and the spoke guards — are
**load-bearing**, not redundant defence in depth. Retiring the `ambiguous-terminal-contact` negative would
remove coverage from the only check that runs *before* the data is consumed, leaving the condition covered
solely by a check that executes after the routing decisions it was supposed to authorise.

This also means the request's proposed substitute — "require a reachable factory-first duplicate-contact
negative" — is not a substitute at all: a factory-first negative cannot exist for this condition on this path,
because the consumer rejects first. Any fixture written to that description would either fail at `:19052` (and
so *be* the RA-46.5 negative) or reach the factory only by bypassing `build_surface_cell_network` entirely,
which tests a path the pipeline does not take.

---

#### 5. What *is* unrealizable: `nonmanifold-terminal-star-spoke`

The request's item 3 asked that the other RA-46.5 negatives be examined for feasibility. One of them is
unrealizable, and it is not the one asked about.

`:19066-19068` rejects `nonmanifold-terminal-star-spoke` when `sourceEdgeFaceCounts` shows an incidence `> 2`,
which requires a nonmanifold `faces`. But reaching that loop requires a non-null atlas (`:19056-19057`), and
the network-level gate at `:18749-18757` requires
`fieldTransportAtlas->matches_source_faces(faces, *network.sourceTopologyRegions, vertexCount)` whenever the
atlas is non-null. `matches_source_faces` ties the atlas's stored `rowTopology_` to the exact face triples of
`faces` (`src/authority/FieldTransportAtlas.cpp:3090-3109`), so the atlas must have been built on **that**
nonmanifold mesh — which throws, by the RA-48.0 chain (G1-G4: `set_mesh` runs `compute_edge_quantities`, which
throws when `dcel.check_consistency` fails, and DCEL check 5 rejects the repeated directed halfedge that three
triangles on one undirected edge must produce by pigeonhole).

So this consumer-side spoke guard inherits RA-48's unreachability, under RA-48's **already frozen** guards and
no new ones. It is retired on that basis. Note the inversion: the request sought to retire the reachable
predicate while leaving the unreachable one in force.

**Status of the remaining four.** `no-exact-terminal-corner` (`:19055`) is plainly reachable — any contact
whose endpoints are not on the carrier, or whose trace points are not bit-exact one-hot, falls through the loop.
`missing-terminal-A3-path` is reachable and keeps its obligation by RA-46.4, which retained the `pathCount == 0`
branch as reachable from a foreign component. `overlapping-terminal-sectors` and
`missing-or-nonreciprocal-terminal-A3` were **not examined** by this review and keep their obligations
unadjudicated; they are not to be reported as either confirmed or retired.

---

#### 6. RA-49 — FROZEN

**RA-49.1.** The retirement request for `ambiguous-terminal-contact` is **REJECTED**. The branch at
`src/geometry/SurfaceCellTracing.cpp:19052` is **reachable** on the live path, and RA-46.5's requirement for a
negative at that actual first rejecting predicate **stands unamended**. RA-46.5 is not modified by this
decision.

**RA-49.2.** The required fixture is the §3 witness: a duplicated typed endpoint pair `{v, v}` in
`hardRailTerminalContacts`, `v` on the carrier edge, both trace points bit-exact one-hot at `v`. It must be
verified to reject at `:19052` and **not** at `:19055`, `:8296`, or any earlier predicate.

**RA-49.3.** The two-distinct-vertices route is **not** available and must not be attempted:
`exact_corner(fromPoint, ·)` is functional, admitting only `faces(fromPoint.face, c)` for the unique one-hot
position `c`. A fixture that tries to make two distinct vertices qualify is not a defect in the code and will
not produce this predicate.

**RA-49.4.** Prohibited routes to the witness: relaxing the one-hot comparison at `:19043` (RA-46.7 already
forbids adding a tolerance to the equivalent factory-side predicate, and the same prohibition applies here);
removing or weakening the factory distinctness check at `:8295-8299`; removing the carrier-membership conjunct
at `:19049`; or constructing the contact outside `build_surface_cell_network`. The witness requires none of
these.

**RA-49.5 — R4-CTC-01 is a defect.** `build_surface_cell_network` consumes caller-supplied
`hardRailTerminalContacts` at `:18997` and validates them only at `:19446`. The consumer's guards are therefore
load-bearing and must be **kept**. The architectural repair — validating the contacts against the factory's
own admissibility rules **before** first use, or routing the consumer through the factory-validated product —
is **not** authorized in a Code + Build turn and is referred to a later Definition turn. Until then the
duplicate condition keeps **both** checks, and neither may be removed as redundant.

**RA-49.6.** `nonmanifold-terminal-star-spoke` (`:19066-19068`) is **RETIRED** as unrealizable, on RA-48's
guards G1-G4 and the network atlas gate at `:18749-18757`, with the guard **kept fail-closed**. No fixture is
to be built for it, and none may be synthesized by relaxing manifold rules or by passing a null atlas (which
rejects earlier at `:19056-19057` with `missing-source-A3`, a different predicate). If any of G1-G4 or the
network gate weakens, this retirement lapses with RA-48.1's.

**RA-49.7.** `no-exact-terminal-corner` and `missing-terminal-A3-path` keep their RA-46.5 obligations and are
confirmed reachable. `overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3` keep their
obligations **unadjudicated** — this review did not examine them, and their feasibility may not be asserted in
either direction on the strength of this decision.

**RA-49.8 — the general rule, third application.** A predicate's obligation is settled by what it can
separate **on the path it actually sits on**, not by what a downstream guard would have prevented. RA-46 asked
this of a graph-theoretic condition, RA-48 of a source-construction condition, and RA-49 of an **ordering**
condition — and here the answer inverted the request, because the guard invoked to prove unreachability runs
after the predicate it was said to protect. A feasibility argument must therefore establish **execution order**,
not merely the existence of a stricter check elsewhere.

**RA-49.9 — no credit.** No binary built, no test executed. R4-CTC-01 is a source-level review finding, **not**
a counted stable regression: ledger stays **66 events / 17 categories / 49 recurrences**, debt **1**. CP2
**491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses. RA-48, RA-47, RA-46, RA-45,
RA-44 (less .2), RA-43 (less .5 and less the superseded `sourceEdges` row), RA-42 as corrected, RA-41 frozen
scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates stand unchanged. RA-47 remains **unimplemented**.

---

#### 7. Beacon

`STATUS` read `BLOCKED` with `Successor: M6-CP3-CB1-ENTRY-R4`. The review it waited on is complete; there is no
open `REVIEW_BLOCKER`. Per RA-48.8, a `BLOCKED` beacon requires a committed record naming the finding — this
one had that record, so the block was properly raised even though its conclusion does not survive review.
Raising it was correct; the deduction was not.

## `Architecture_M6_CP3_R4_Authoring_Closeout_And_TB_Authorization_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Authoring_Closeout_And_TB_Authorization_Review_Decision.md`; moved verbatim.

### RA-55 — R4 Code + Build authoring CLOSED; Test + Benchmark authorized, narrowly

**Turn:** `M6-CP3-R4-AUTHORING-CLOSEOUT-ARCH-REV` (Architecture Review only).
**Adjudicates:** `M6-CP3-CB1-R4-OHF01-PROBE` and `M6-CP3-CB1-R4-RP02-WITNESS`.
**Disposition:** both **ACCEPTED**. Every decisive claim re-derived from repository bytes at `1e0e13a38`;
no report taken on trust. **No runtime credit is conferred by this Review.**

The interval's entire diff is one test file (`tests/SurfaceCellsPhase10Tests.cpp`, +89/-2), two evidence
documents, and the handoff / CHANGELOG / TODO / STATUS beacons. No production source, no header, no
selector, no harness, no ledger. That is exactly the authorized scope.

---

#### RA-55.1 — OHF-01's answer (b) is CONFIRMED on the checked construction path

The probe answers **(b) UNREACHABLE**, which is the answer I warned must not be fabricated. It was not.
Each link was re-derived:

- **G1 — `set_mesh` cannot skip derivation.** `include/directional/core/TriMesh.h:331-350`:
  `compute_edge_quantities(verbose)` is called **unconditionally** at `:339`, before the injected-table
  comparison at `:340-350`, which throws `"set_mesh(): injected edge topology disagrees with faces"` on any
  mismatch. Supplied `_EV/_FE/_EF` are therefore a *claim to be checked*, never an input that is trusted.
- **G2 — the repeated-directed-halfedge check is enabled, and the pigeonhole is exact.**
  `compute_edge_quantities` calls `dcel.check_consistency(verbose, true, true, true)` at
  `TriMesh.h:159-163`, throwing on failure. The signature at `include/directional/core/DCEL.h:1164-1169`
  places **`checkHalfedgeRepetition` second**, so that call enables it; the two omitted trailing
  parameters also default to `true`. Section 5 at `DCEL.h:1453-1492`, guarded by `if (checkHalfedgeRepetition)` at `:1456`, keys a `std::map` on
  `(source, target)` and returns `false` on the second appearance. Three triangles incident to one
  undirected edge contribute three directed halfedges across only two possible directions, so two must
  coincide. The rejection is orientation-independent. **Sound.**
- **G4 — the atlas pin genuinely precedes the census.** `SurfacePhaseFrontProduct::make` rejects with
  `AtlasSourceMismatch` at `src/geometry/SurfaceCellTracing.cpp:8137-8145`; the `railIncidenceCounts`
  construction is at `:8243-8266` and the overfull/absent emission at `:8270-8277`. Ordering confirmed.
  `FieldTransportAtlas::matches_source_faces` (`src/authority/FieldTransportAtlas.cpp:3090-3110`) requires
  `sourceAuthority.matches_source_faces(sourceFaces, sourceVertexCount)` **and** compares `rowTopology_`,
  `rowRegions_` and `rowComponents_` row-by-row against that authority, so `sourceFaces` must be the
  atlas's own construction faces. A foreign-mesh atlas cannot authenticate the input.

**G5 is correctly demoted.** The report explicitly declines to rest on `build_surface_cell_network`'s
own `sourceIncidences > 2` rejection, on the ground that the factory is independently callable. That is
the right reasoning and it is the distinction I asked for.

#### RA-55.2 — the retirement is CONDITIONAL, and the condition is sharper than the report states: `R4-OHF-02 / UNCHECKED_MESH_PROVENANCE`

The probe's own caveat — *"public `TriMesh` matrices are mutable, so this source-only conclusion covers
the documented checked construction path"* — is honest and is the reason the answer is accepted rather
than disputed. I record the condition precisely, because the retirement is coupled to it:

**G3 is the soft link, not G1/G2.** `FieldTransportAtlas::make`
(`src/authority/FieldTransportAtlas.cpp:1893-1912`) accepts a `const TriMesh &` and validates the edge
tables **by shape only** — `EV.cols() != 2 || EF.cols() != 2 || EV.rows() != EF.rows()`. It never re-runs
`DCEL::check_consistency`, and it consumes `sourceMesh.EF(edgeIndex, 0..1)` as the adjacency authority,
so a third incident face is not *rejected* at that read — it is simply absent from a two-column table.
Whether the downstream `MissingAdjacency` / `NonReciprocalAdjacency` checks would then catch such a mesh
is **not established by this Review and must not be asserted**.

Therefore the unreachability of `OverfullHardFeatureIncidence` rests on the convention that every
production `TriMesh` is built through `set_mesh`, not on a type-level invariant: `V`, `F`, `EV`, `EF` are
public and mutable, and no constructor forbids assembling one directly.

**Consequences, all binding:**

1. The requirement to author a factory negative for `OverfullHardFeatureIncidence` is **RETIRED**,
   coupled to G1, G2, G4 **and** to `R4-OHF-02`.
2. The guard at `SurfaceCellTracing.cpp:8270-8277` and the `OverfullHardFeatureIncidence` sub-code are
   **RETAINED** unchanged. The guard is the only thing standing between `R4-OHF-02` and a silently
   accepted non-manifold carrier, and it is fail-closed.
3. `R4-OHF-02` is **recorded, not chased.** Probing it would be a seventh Code rung invented to avoid the
   execution boundary, which RA-54.7 forbids. The risk is contained by (2).
4. Any change that makes a `TriMesh` reachable by production code without `set_mesh`, or that relaxes
   G1/G2/G4, **reopens reachability** and requires a non-vacuous witness before merge.

#### RA-55.3 — the RP-02 witness MEETS the anti-vacuity bar; here is the decisive byte

The bar I set was: *the assertion must fail if the whole consumer is skipped.* It does, and the reason is
structural rather than circumstantial:

**Exactly one site in the entire file assigns a `HardRail` boundary kind.** `edge.boundaryKind = *kind`
and `edge.railId = railId` at `src/geometry/SurfaceCellTracing.cpp:12619-12620` sit inside
`assign_open_front_boundary_authority` (`:12414-12625`). The only other two `boundaryKind` assignments in
the translation unit — `:14745-14746` and `:18629-18630` — write `PeriodicCut` and nothing else. Reaching
`:12619` requires surviving the network-bound `rail_interval_refs` call at `:12425-12428`
(`options.fieldAlignedNetwork`, `RailIntervalAuthorityMode::RequireTypedSource`), which returns
`InvalidFrontBoundaryAuthority` at `:12429-12431` on any non-`Valid` status.

So a published `SurfaceFrontEdge` with `boundaryKind == HardRail` **is itself the consumer's receipt**.
`ASSERT_NE(consumedRail, nullptr)` cannot pass if the consumer is skipped, and it is not an A2a
publication assertion, not a call the test makes itself, not a stage-injected run, and not a factory-only
rejection. All four prohibited shapes are avoided.

The test strengthens this beyond the minimum: every consumed `sourceEdges` key is independently resolved
through `fixture.fieldNetwork->find_mandatory_edge(key)` with `EXPECT_EQ(rail->id, mandatory->rail)`, and
`edge.filledCell` is required to resolve to a published cell. That binds the receipt to the *real*
network rather than to the edge's own self-report.

#### RA-55.4 — the negative's anchor is genuinely discriminating, and I quantified it

`InvalidFrontBoundaryAuthority` is a heavily shared reason code, so `EXPECT_EQ` on it alone would prove
almost nothing. The test does not rely on it alone. A full scan of
`src/geometry/SurfaceCellTracing.cpp` finds **66** `set_phase_front_failure` sites naming that reason, of
which **only 4** supply a cell/side (`:13052`, `:14784`, `:17439`, `:17448`); `set_phase_front_failure`
defaults `cell = -1, side = -1` (`:11330-11335`) and is first-failure-wins (`:11336-11338`).

The test's `EXPECT_GE(failure->cell, 0)` with `side ∈ [0,4)` therefore **excludes 62 of the 66** literal
sites outright. Of the four anchored ones, `:13052` and its siblings test owner-cell lookup and
`filledSide` range — conditions a `sourceEdges` substitution does not perturb — leaving the consumer's
own propagation (`:13063-13067`, and the matching wrappers at `:14790`, `:17412`) as the live locus. The
anchor is doing real work.

**Caveat, stated rather than hidden:** the negative's expectation is *authored and compiled, never
executed*. If at runtime the forgery is caught by an earlier stage, this test fails — which is the
correct failure direction, and is a TB finding, not an authoring defect.

#### RA-55.5 — the test-helper override is minimal and weakens nothing

`build_fixed_plan_rectangular_hard_rail_network` gains one defaulted trailing parameter
(`const std::vector<SurfaceCellRail> *rails = nullptr`) and one line
(`options.authoritativeRails = rails != nullptr ? *rails : fixture.rails;`). Every pre-existing call site
is byte-identical in behaviour. No guard was weakened, no counter added, no production API touched. Under
RA-52.6 read forward — *a retained guard needs a retained attempt* — a test-side affordance whose only
purpose is to feed the guard a forgery is exactly the right construction.

#### RA-55.6 — CORRECTION to RA-54.2 (my own prior acceptance)

In RA-54.2 I wrote that `SurfacePhaseFrontSourceAuthorityDetail`'s seven values "cover exactly the
reachable predicates." With OHF-01 answered **(b)**, that is now one value too generous:
`OverfullHardFeatureIncidence` is **not reachable on the checked construction path**. The correct
statement is **six reachable predicates and one fail-closed-only sub-code**.

This does **not** reopen RA-51.7, which forbids *minting* a sub-code for a disjunct already known dead.
When RA-46.6 minted this one, its reachability was an open question — the question OHF-01 was
commissioned to answer. The sub-code stays, for the reason in RA-55.2(2). The correction is recorded
rather than quietly amended, per `RP-03`.

#### RA-55.7 — R4 Code + Build authoring is CLOSED, verified rather than reported

RA-54.7 left exactly two authoring items. Both are discharged: OHF-01 by a coupled retirement, RP-02 by a
witness that meets its bar. I confirmed by inspection that no third item was left open and that nothing
outside the authorized scope moved. **The Implementation Agent's refusal to invent a further Code rung is
correct and is accepted.**

#### RA-55.8 — Test + Benchmark is AUTHORIZED, in two rungs, narrowly

The source-only vein is exhausted and the authoring vein is now exhausted too. Continuing to withhold
execution would convert a boundary into a stall, so execution is authorized — but not as one monolith.

**TB-A, first and small — `M6-CP3-TB1-R4-WITNESS-EXEC`.** Execute **only** the authored-but-never-executed
witnesses, as a named supplemental run **outside** the frozen 497, exactly as the four RA-40(C)
supplementals sit outside it. The frozen selector files stay byte-identical; the harness pins their
hashes at `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh:211-217` and re-checks
them at `:270-272`. This rung answers one question: **does roughly ten turns of authoring survive first
contact with a running binary?** Nothing larger is worth measuring until it does.

**TB-B, only after TB-A — `M6-CP3-TB1-R4-497-EXEC`.** Re-measure the frozen `30 + 12 + 449 + 6 = 497`
gate against current HEAD, to establish whether R3's 94 RED has moved. This is the milestone-bearing
measurement and it must not be folded into TB-A: a mixed run makes a supplemental failure
indistinguishable from a selector regression.

**Neither rung may edit source to obtain green.** A RED in TB-A is a finding to report, not a defect to
patch inside the same turn; the fix is a separately authorized CB turn under Review. A RED in TB-B is the
R4 recovery measurement and is expected to be nonzero.

#### RA-55.9 — no credit conferred

No source, test, header, selector, harness, fixture, benchmark or ledger changed in this Review. Ledger
**66 / 17 / 49**, M6 debt **1**, selector **497** untouched, CP2 **491/491** accepted, R3 **403/497**
rejected with 94 RED and 88 carried CP2 losses, PR #8 draft/open — all unchanged. A compile is not a
restoration (LESSONS 160); a census is not a witness (LESSONS 171); an authored expectation is not a PASS.

## `Architecture_M6_CP3_R4_Carrier_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Carrier_Review_Decision.md`; moved verbatim.

### Independent Review — the 39-identity endpoint census, and selection of the certificate model (RA-59)

**Turn:** `M6-CP3-TB1-R4-CARRIER-REV` (Review only). **Disposition:** the census **measurement is ACCEPTED**; its **interpretation is AMENDED and then CLOSED**. Two of the three RA-57.7 hypotheses are **ELIMINATED from the source bytes**, not from the measurement, and the certificate model is **SELECTED**. No source, test, selector, binary, harness, workflow or ledger change was made in this Review. Ledger **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector **30+12+449+6=497** — all unchanged. No promotion, no stable event, no new recurrence, no 497 execution, no gate credit.

#### RA-59.1 — The measurement is valid and the execution boundary is clean

Independently re-derived. `M6-CP3-TB1-R4-ENDPOINT39-CENSUS` executed **39/39** identities on the same immutable package (compile run `38664036225`, package artifact `11939982141`, semantic source `953f812ff1f431e3ad3af3b68a92284a7831c94a`), workflow [38687783618](https://github.com/akashskypatel/Directional/actions/runs/38687783618), result artifact `11950303475` (ZIP SHA-256 `3bce344f3a13403a830a2800fea4c47d1e7cdd53f6f3eac6629de57d70788b32`). `executed=39 red=39 missing=0 postflight=true exit=0`; 28/28 manifest checksums before and after; package, source, execution-view and selector bytes identical across execution. No configure, compile, relink, benchmark, or frozen-497 run. The four frozen selector files still hash to their pinned values (`1e815443…`, `2aa57aac…`, `d4a0d1b7…`, `9c88a5ed…`) in the working tree.

Re-derived set membership rather than accepting it: every one of the 39 executed identities is a member of the **94-row R3 RED register** (`Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`), intersection **39/39**, zero census identities outside it. Cross-validating the census TSV's `R3_CP2_ACCEPTED`, `R3_R2_RED` and `R3_original_first_observable` columns against that register field-by-field yields **zero mismatches** in 117 comparisons. The R3 `phase` distribution of the 39 is `focused30=9, focused12=2, selector=26, cp3entry=2`, matching the TSV's three selector columns exactly.

#### RA-59.2 — The harness is the best instrument built in this family, and it fixed a defect class I did not raise

`tools/m6_cp3_r4_endpoint39_census_harness.sh` (SHA-256 `4dd5c605710c65317b2f524d0d3bed83602b7922ceec4bab87062374407c40f6`, 92 lines) is **RA-57.8 compliant**: `:71-74` records `NOT_SELECTED` and `continue`s instead of aborting the loop, `:91` derives the verdict from `executed`/`missing`/`postflight` **only** with no RED-count test, and `:92` is a bare `exit 0`. Four expected REDs can no longer suppress a turn's report.

Beyond the mandate, `:45-51` **derives the census scope from a SHA-256-pinned artifact** rather than transcribing it: `inventory=…Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv`, pinned at `de05a7bd5ca27eb243156ecd38434fbc69d06f4b791bdd3dbcfc5982c273a865` (verified identical in the working tree), then `mapfile` with `[[ "${#tests[@]}" == 39 ]]` and a duplicate check. The executed set equals the pinned inventory set exactly. This eliminates silent census shrinkage — a failure mode the earlier harnesses permitted and that no amendment had named. **Recorded as the correct instrument shape for every future census rung.**

#### RA-59.3 — `routeLength` and `step` are not measurements, and `step` is arithmetically forced

RA-57.12 holds: *a signal that never varies is not a measurement.* Across all 39 identities the census reports `routeLength=1`, `step=0`, `closedChainPresent=0`, `locus=3` — four constants — with only `rail` (33×2, 6×1) and `chi` (37×0, 2×3) varying. Two of those constants are now shown to be **non-data**:

- `step` is emitted at `src/geometry/SurfaceCellTracing.cpp:19329-19332` as `firstMissing ? 0 : static_cast<int>(routeSteps.size() - 1U)`. With `routeSteps.size() == 1`, **both** branches yield `0`. `step` is `routeLength-1` here, a derived echo of `routeLength` in the same class as `faceEnds` (RA-56.1). It corroborates nothing.
- `locus=3` is `SurfaceHardRailRouteFailureLocus::EndpointAttachment` (`include/directional/geometry/SurfaceCellTracing.h:1800-1811`). It is implied by the predicate name, not independent of it.

The census TSV is nonetheless correct to have recorded them: a field must be measured before it can be shown to be uninformative. The defect is only in reading them as breadth.

#### RA-59.4 — `routeLength=1` is the CORRECT value, and hypothesis (c) route truncation is WITHDRAWN

My own `NEXT_TURN` promoted *route truncation* to a live hypothesis on the strength of `routeLength=1, step=0`. That was wrong, and the source says so.

`first.route` is produced at `src/geometry/SurfaceCellTracing.cpp:12617` by `authority::CanonicalRoute::from_observed_steps(std::move(observedSteps))`, where `observedSteps` is assembled at `:12574-12579` as **one step per contiguous run of the front edge's own retained geometry on one source-edge topology**, with `seenTopology.insert(topology)` forbidding revisits. `CanonicalRoute` (`include/directional/authority/CanonicalRoute.h:64-98`) carries no whole-rail contract; `oriented_steps()` at `:79` returns exactly those steps.

So `routeLength` measures **the front edge's own carrier extent**, not the rail's length. A front edge that crosses one source edge yields `routeLength=1` *correctly*. `routeLength > 1` is representable (a front spanning two topologies publishes two runs), so the field is not a tautology — it is simply **constant at 1 in this census because every measured front lies on a single carrier edge**. Nothing is truncated. **Hypothesis (c) is withdrawn.** This is the third error of this family I have owned — RA-57.3 (a non-discriminating control), RA-58.8 (a grid conditioned on the verdict), and now a hypothesis built on a field whose expected value I never established. The standing rule from RA-58.8 generalizes: **a measured value without its expected value is not a discriminator.**

#### RA-59.5 — Hypothesis (b) incorrect pairing is ELIMINATED by the predicate name in all 39 logs

The pairing precondition is checked first, at `:19022-19025`:

```cpp
if (!first.railId.has_value() || first.railId != second.railId ||
    first.route.empty() || first.route != second.route.reversed()) {
  invalid_route(SurfaceHardRailRouteFailureLocus::Pairing, -1, -1, "nonreciprocal-pair");
  return network;
}
```

It returns immediately on failure with predicate `nonreciprocal-pair` and locus `Pairing = 1`. Every one of the 39 reports predicate `endpoint-0`/`endpoint-1` and locus `EndpointAttachment = 3`, emitted later at `:19329-19332`. Therefore in all 39 measurements the rail ids matched, the route was non-empty, and `first.route == second.route.reversed()` — **reciprocal pairing held**. Two independent fields (predicate name and locus enum) agree. **Hypothesis (b) is eliminated.**

#### RA-59.6 — What the 38 `endpoint-1` identities actually measured: a half-terminal front

Both certificates are evaluated on the pair's two spatial ends, at `:19264-19269`:

```cpp
const auto firstEndpoint  = endpoint_certificate(first.from, second.to,  routeSteps.front().topology(), &firstEndpointPredicate);
const auto secondEndpoint = endpoint_certificate(first.to,  second.from, routeSteps.back().topology(),  &secondEndpointPredicate);
```

`endpoint-1` means `firstMissing == false`, i.e. **`firstEndpoint` returned a value**. So for 38 of the 39 identities, one end of the paired front — `(first.from, second.to)` — **was certified**: both of its trace points are exact one-hot source corners at a shared vertex of the rail's terminal contact set that also lies on the crossed carrier edge. The other end, `(first.to, second.from)`, failed at `:19152` `no-exact-terminal-corner`, with the retained evidence `corner[1]=0,0;railEnd[1]=1;corner[7]=0,0;railEnd[7]=0` — vertex 1 is an endpoint of the crossed carrier edge but neither trace point sits exactly on it.

**The measured object is a half-terminal front pair: one end exactly at a rail terminal source vertex, the other at an interior parameter of the same carrier edge.** This is reproduced identically across 39 identities, 5 distinct fixture builders, 2 rail ids, two field regimes (`chi=0` and `chi=3`), and both `remesh_from_raw_cross_field` full-pipeline entries. Per RA-56.8 this is now a **measured carrier**, not one measured identity.

#### RA-59.7 — The certificate has no admissible shape for an interior endpoint; this is a DOMAIN GAP, not a strictness dial

`endpoint_certificate` (`:19049`) admits exactly two shapes for a hard-rail endpoint:

1. **Open rail with a published terminal contact.** `:19144-19152` loops the rail's terminal endpoints and requires, for one and the same vertex, that it be an endpoint of the crossed carrier edge **and** that **both** paired trace points be exact one-hot barycentric corners at it; otherwise `no-exact-terminal-corner`.
2. **Contact-free rail with an independently published typed closed chain.** `:19072-19079`; absent both, `missing-terminal-or-closed-rail-provenance`.

A front end at an **interior point of the carrier edge of an open rail** satisfies neither. There is no third branch. Consequently:

- **Hypothesis (a) is SELECTED, in an amended form.** The defect is not that the predicate is too strict — it is correct and must stay fail-closed for anything claiming to be a terminal. The defect is that the certificate's **domain is missing the interior-endpoint shape** that the front publisher demonstrably produces. "Contract granularity mismatch" (RA-55) is confirmed and sharpened to a domain gap located at `:19049-19152`.
- **This independently re-explains RA-58.5.** The torus passes because its chain is **closed**, so it takes branch 2 at `:19077-19079` and never reaches `:19152`. The square and cylinder pass because they never enter this block. The open-rail fixtures fail because they are the only ones that reach branch 1 with an interior end. One mechanism now accounts for all four control outcomes and all 39 census outcomes.

#### RA-59.8 — The positive acceptance branch has never been reached by any test, green or red

`grep` over the whole test corpus finds **five** identities that assert a published hard-rail route certificate: `SurfaceCellAuthorityContractCutover.{MissingOpenRailTerminalContactRejectsBeforeClosedRailFallback, ForeignOpenRailComponentRejectsAtFirstA4ConsumerPredicate, DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate, ForeignSourceTerminalContactRejectsAtFirstA4ConsumerPredicate, MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate}` (`tests/SurfaceCellsPhase10Tests.cpp:6922, :7104, :7148, :7189, :7248`). Each is a **tamper/negative** test whose first assertion demands real production, e.g. `:7150-7152`:

```cpp
const auto fixture = build_rectangular_hard_rail_phase_front();
ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
          fixture.network.phaseFront.disposition()) << hard_rail_first_failure_detail(fixture.network);
const auto &front = fixture.network.phaseFront.product();
ASSERT_FALSE(front.hardRailRouteCertificates().empty());
const auto &firstRoute = front.hardRailRouteCertificates().front();
ASSERT_TRUE(firstRoute.endpoints[0].terminalVertex.has_value());
```

They all fail at the `Produced` gate. **No test anywhere — accepted, frozen, or RED — has ever observed the producer publish an open-hard-rail route certificate from real source geometry.** Therefore the entire positive path downstream of `:19152` is unwitnessed, including the junction loop at `:19335-19338`:

```cpp
junctions.reserve(routeSteps.size() - 1U);
auto previous = firstEndpoint->terminalCarrier;
for (std::size_t index = 1U; index < routeSteps.size(); ++index) {
```

With `routeSteps.size() == 1` this loop body **cannot execute**. This is the mechanical root of RA-41's junction/sector clauses standing frozen UNEXERCISED, and it means **no number of additional `routeLength=1` measurements can ever exercise them.** Exercising them requires a fixture whose front's retained geometry spans **two** rail topologies — i.e. a front crossing both `(1,4)` and `(4,7)`. That is the first actionable construction recipe for those guards; it is **recorded, not authorized** (RA-54.7), and the guards are **not retired** (RA-52.6: a retained guard needs a retained attempt).

It also localizes `RP-02 TEST_AUTHORITY_COVERAGE_GAP` precisely: the gap is not merely that the network-bound consumer was never reached, but that **the acceptance half of the hard-rail certificate model has no witness at all**, so a repair cannot be validated by making existing REDs green.

#### RA-59.9 — Selected certificate model, and the one falsifier that would overturn it

**SELECTED (RA-59.9).** The open hard-rail route certificate gains a **second admissible endpoint shape — a source-attested interior carrier endpoint** — authenticated by: the typed carrier key; **both incident source faces of that carrier edge (across-rail, per RA-57.5 — not along-rail interval or face-side ownership)**; the canonical exact intrinsic parameter on the **same** carrier edge, shared by both paired trace points, with equivalent opposite-side barycentric representatives and **no** world-coordinate epsilon merging; source component/sheet agreement; the matching A2a mandatory network edge/rail identity; and the directed A3 transport between those two incident faces.

Constraints that are part of the selection, not commentary:

- `exact_corner` and `no-exact-terminal-corner` at `:19131-19152` are **unchanged and fail-closed**. Any endpoint claiming to be a rail terminal is still held to exact one-hot corner identity on both paired points.
- The closed-chain branch at `:19072-19079` is **unchanged**, preserving the RA-58.5 torus PASS.
- An open rail must still publish **at least one certified terminal endpoint** — satisfied in 38/39 by `firstEndpoint` — so a contact-less open rail and a forged closed-chain token both remain impossible.
- `firstRoute.endpoints[0].terminalVertex.has_value()` (`tests/SurfaceCellsPhase10Tests.cpp:7157`) stays satisfiable, so **no existing test contract is weakened** by this model. Checked before selecting it.
- The single `endpoint-0` identity, `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` (historical ordinal **405**, `a2bProbeFailure=missing-terminal-or-closed-rail-provenance`), is a **separate A2b provenance defect** at `:19072-19079` — the rail has neither a published terminal contact nor a closed chain. It must **not** be repaired by the interior-endpoint model, and it must not be merged into the 38. The census was right to refuse the merge; the mechanism is now named.

**The falsifier, which the Code + Build turn must check FIRST and STOP on.** This selection assumes a hard-rail front's extent is determined by where the field-aligned phase front meets the rail, so a front end may legitimately fall interior to a carrier edge. If instead the front publisher is contracted to cut hard-rail fronts **only** at rail terminals, then the half-terminal front is itself the defect, the repair belongs upstream of `:19264`, and this model is wrong. The comment at `:18908-18909` — *"A4 owns the paired-route topology, endpoint attachment and A3 transport. Publish one terminal crossing per spatial endpoint; A5 must not search."* — is evidence for the stricter reading and must be reconciled before any edit. **If the publisher's contract cannot be established from source, STOP and return to Review.** Do not resolve it by whichever choice makes the 38 green.

#### RA-59.10 — Classification correction: 37 carried CP2 losses + 2 in-gate R3 REDs, and all 39 are INSIDE the 497

The census TSV sets `reproduced_carried_loss=true` for all 39 and the report describes all 39 as reproducing *"previously observed, **unaccepted** failures."* Both flatten the distinction RA-58.6 exists to keep. On the authoritative register:

| class | count | evidence |
|---|---:|---|
| reproduced **carried CP2 loss** (CP2-accepted, now RED) | **37** | `R3_CP2_ACCEPTED=true`; phases `focused30`/`focused12`/`selector` |
| reproduced **in-gate R3 RED with no accepted CP2 baseline** | **2** | `R3_CP2_ACCEPTED=false`; phase `cp3entry` |
| **baseline-free first measurement** (the RA-58.6 identity-4 class) | **0** | `baseline_free_first_measurement=false` for all 39 |

The two in the second class are `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` and `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` — and they are the **same two** that are the only `chi=3` rows and the only `nonconstant_hard_rail_fixture` singleton rows. The report calls them *"in no selector"*, which is true of the three selector **files** but materially misleading: both are `cp3entry`, i.e. members of the **"+6" CP3 group of the frozen 497**. **All 39 census identities are inside the frozen 497.** "In no selector" is the exact phrase under which RA-58.6 classified a baseline-free identity, and it must not be reused for an in-gate one. The TSV's own `baseline_free_first_measurement=false` column already says the right thing; only the prose and the `reproduced_carried_loss` column semantics are wrong. Corrected here, not silently.

#### RA-59.11 — RA-58.9 arithmetic, stated as the report declined to

The report states the RA-58.9 merge rule and does not apply it. Applied: `fixture_construction=false — constructor threw` for **19** identities — 17 on the `hard_rail_fixture` singleton (`tests/SurfaceCellTransitionQuotientTests.cpp:585, :771-772`) and 2 on `nonconstant_hard_rail_fixture` (`:776, :855-856`). A throwing singleton means the test body never ran, so those 19 REDs are **2 fixture-construction measurements**, not 19 observations. The upper bound on independent loci in this census is therefore **22**, not 39:

| locus group | identities | independent loci |
|---|---:|---:|
| `hard_rail_fixture` singleton threw | 17 | **1** |
| `nonconstant_hard_rail_fixture` singleton threw | 2 | **1** |
| `build_rectangular_hard_rail_phase_front` per-test helper | 12 | 12 |
| `remesh_from_raw_cross_field` per-test pipeline | 2 | 2 |
| direct test construction | 6 | 6 |
| | **39** | **≤ 22** |

This does not weaken RA-59.6: the carrier still spans 5 builders, 2 rails and 2 field regimes, which is what RA-56.8 requires. It does mean **"39 REDs" must never be cited as 39 corroborations**, and the two singleton rows must never be counted toward breadth.

#### RA-59.12 — The fixtures' authored rail is two edges, and that is why the interior end exists

Read from the bytes, not inferred. `make_hard_rail_fixture` (`tests/SurfaceCellTransitionQuotientTests.cpp:585`) inserts `userHardEdges` `{1,4}` at `:617` and `{4,7}` at `:618`. `make_nonconstant_hard_rail_fixture` (`:776`) does the same at `:830-831`. `build_rectangular_hard_rail_phase_front` (`tests/SurfaceCellsPhase10Tests.cpp:6298`) inserts `{offset+1, offset+4}` and `{offset+4, offset+7}` per component at `:6315-6322`. Every measured fixture therefore authors a **two-edge open rail chain `1→4→7`** with interior junction vertex **4** and terminals **{1,7}**, and the measured front lies on the first edge `(1,4)` only.

Two consequences. First, the interior endpoint is not an artifact of a degenerate fixture — it is what a field-determined front does to a rail with interior structure, which is precisely the topology the pipeline must support. Second, **repairing this by changing the fixtures is forbidden** and would be self-defeating: the retained plan already prohibits result-specific fixture filtering, and a one-edge rail would retire the only fixtures that can ever exercise the junction clauses.

#### Obligations carried, not retired

`RP-01`, `RP-02` (now localized per RA-59.8, **still open**), `RP-03`; the RA-58.7 A5/A6/A7 loci (recorded, guards retained, **no probe**); `R4-OHF-02` (recorded, guard retained, no probe); the two RA-57.9 guards and RA-41's junction/sector clauses (frozen **UNEXERCISED**, construction recipe now known, **not retired**); the 34 Phase10 / seven DCEL / six CP3 identities; the CP2 restorations outside the 37; organic D1/D2/D3/D5 and A6/A7 witnesses; the odd-τ witness; the two `SurfaceCellTracingPhase14` identities requiring a separately packaged historical executable (`cmake/DirectionalTests.cmake:554-572`), which must **not** be bundled into a measurement rung. The `SurfaceCellPipelinePhase20` suite-name collision across two targets stands; cite tests by fully qualified `Suite.Name`, never a bare `Suite.*` filter (RA-57.10).

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | All four frozen selectors match pinned values in the working tree; no selector added, changed or accepted, so no new prefix comparison applies |
| Decisive claims independently re-derived | 39/39 ∈ 94-row R3 register by set intersection; 117 field comparisons against the register, zero mismatches; inventory SHA-256 re-hashed and matched; harness read line by line; all source and test anchors read from bytes |
| Non-vacuity checked | RA-59.8: the acceptance half of the certificate model has **no** witness, green or red; the junction loop is unreachable at `routeLength=1` |
| Prior obligations discharged / carried | RA-57.7 hypothesis set **closed**: (b) and (c) eliminated, (a) selected and amended; RA-58.9 arithmetic applied; all other obligations carried above |
| Stable accounting | 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497, no promotion, no stable event, no recurrence |
| New candidates / obligations recorded | `R4-TB-A-RP02-01` carrier mechanism now selected (RA-59.9) and its falsifier frozen; ordinal-405 `endpoint-0` separated as a distinct A2b provenance defect; junction-clause construction recipe recorded |
| ORIENTATION currency line | `M6-CP3-TB1-R4-CARRIER-REV`, 2026-10-15 |
| CHANGELOG | 2026-10-15 root entry; root `CHANGELOG.md` is canonical |
| LESSONS | RA-59.4 mints **a measured value without its expected value is not a discriminator**; LESSONS 160, 171, RA-56.8, RA-57.12 and RA-58.8 all cited and still in force |
| Successor frozen | `M6-CP3-CB1-R4-WITNESS-REPAIR` (Code + Build, compile-only), re-entered under RA-59.9 with its RA-57.5 vocabulary amendment and the RA-59.9 falsifier checked first |
| Turn boundary held | Review only: no source, test, selector, harness, workflow, binary, benchmark or ledger change; no Directional binary executed |
| `review_check.py boundary` | Run after document commit; result recorded with the commit |
| `STATUS` lifecycle maintained | Six fields set, `COMPLETE`, named `Successor` |

## `Architecture_M6_CP3_R4_Contact_Binding_And_Gauge_Witness_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Contact_Binding_And_Gauge_Witness_Review_Decision.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — terminal rail-contact binding and +U gauge witness: Review decision

**Type:** runtime-free Review adjudication of the R4 source-authority binding STOP.
**Disposition:** **Finding 1 ACCEPTED as a specification gap, resolved by option (C) below — neither (A) nor
(B).** **Finding 2 ACCEPTED as a refutation: RA-43.5's oracle was vacuous and is WITHDRAWN**, replaced by a
two-part witness. Frozen as **RA-44**. The R4 Code + Build turn is released to continue.

Read at HEAD `de0f9d4c1`. Every claim is a direct byte read re-derived in this turn.

---

#### 1. RA-43.5 is withdrawn: the oracle I named cannot discriminate

`FieldFaceBranchFrame` (`include/directional/authority/FieldTransportAtlas.h:728-734`) holds
`std::vector<FieldBranchBoundaryPairing> branches` — **all four** branches, each with its own
`FieldBranchDirection`. There is no distinguished +U. So `find_frame(face)` offers four equally valid values
and comparing `sourceFaceBranchRotations[face]` against it decides nothing. That is a vacuous check of
exactly the kind LESSONS 171 names, and I froze it. Withdrawn.

The STOP is also right that the factory cannot re-derive the value: `make`
(`src/geometry/SurfaceCellTracing.cpp:7969-7984`) receives `sourceFaces` and `sourceVertexCount` but **no
vertices and no frame axes**, while the gauge's producer at `:11029-11054` selects `bestBranch` from
`project_tangent(axis_for_family(faceAxisX, faceAxisY, face, family, sign), normal).dot(frame.axisU)` under a
hard gate `bestAlignment >= 1.0 - 1e-8`, then cross-checks branch+1 against `frame.axisV` at `:11050-11054`.
The gauge is therefore a **pure function of (faceAxisX, faceAxisY, axisU, axisV, normal)** — none of which
crosses the factory boundary.

#### 2. The non-vacuous witness needs two independent parts, and neither suffices alone

- **Absolute pin (geometric).** Per face, the asserted branch's family/sign axis, projected to the face
  normal, aligns with the certificate's own `axisU` under the identical `1 - 1e-8` gate A4 uses at
  `:11034-11043`, with the `axisV` cross-check at `:11050-11054`. This pins the **value**, because alignment
  is an absolute condition, not a relation. It requires `faceAxisX`/`faceAxisY` and the frame axes, so they
  **travel with the gauge**: the certificate carries its own derivation inputs.
- **Relational pin (A3).** Across each interior edge, the two faces' asserted branches differ by the atlas
  transport: `rotation[to] == rotation[from].rotated(transition_value(edge, from, to)->transport)`, reusing
  the accessor already written at `:7996-8009`.

**Why both.** The relational pin alone is **gauge-invariant** — a balanced `+1 mod 4` on every face satisfies
every edge relation, which is precisely the balanced tamper the STOP demands be covered, and precisely the
RA-40 reasoning that forbade using a commuting square as an authenticator. The absolute pin alone ignores A3
entirely and would accept a frame coherent with geometry but incoherent with the field. Together they are
non-vacuous: the balanced tamper is caught by the absolute pin, and an axis-aligned but field-incoherent
assignment is caught by the relational pin.

**Residual, recorded not blocked.** A4 selects an exact Z4 value with a `double` alignment predicate. The
factory must use the **identical** predicate or it would reject what A4 accepted, so this cannot be tightened
inside R4 without changing accepted CP2 behaviour. Logged as a tracked item; the hard `>= 1 - 1e-8` gate
makes it fail-closed, which is the correct structure even though the predicate is floating-point.

**Scope answers the STOP asked for.** Keyed by `SourceFaceTopologyKey`, so **row permutations** cannot
launder it. **Presence is mandatory whenever A6 seam logic consumes the gauge**; the only legal absence is
**total** absence — no gauge and no consumer — so this does not reopen the RA-40 conditional hole, which was
about the atlas. Periodic and isolation transformations are covered because the relational pin runs on the
atlas's own transitions, which already carry them.

---

#### 3. Finding 1: the dataflow already exists. Option (C).

The STOP offers (A) pass the rail chain through the boundary, or (B) author a new A4 terminal-contact
certificate. Both are heavier than the facts require, because **the rails already reach this boundary**:

- `hard_feature_edge_keys_from_rails` (`src/pipeline/RemeshPipeline.cpp:9576-9599`) consumes
  `rail.sourceVertices` directly, converting each consecutive pair to a typed `SourceEdgeTopologyKey` via
  `surface_cell_source_edge_key` (`:3064`). The typed conversion RA-43.3 demanded **already exists and is
  already in use**.
- Its result is what becomes A4's `hardFeatureEdges`. At `:12173-12177` the pipeline takes
  `authoritativeRails = railProduct->rails`, reduces them to `hardFeatureRailEdges`, and at `:12178-12179`
  stores `productSnapshots.authoritativeRails = authoritativeRails` — **the rails are already carried in the
  surface-cell context.** Same shape at `:17031` and `:17715-17723`.

So the terminal contact is not missing authority and not a missing dataflow. It is the one datum the existing
reduction **discards**: `hard_feature_edge_keys_from_rails` keeps consecutive *interior* pairs and throws away
(i) which vertex is terminal and (ii) the `HardRailId -> endpoint vertex` association.

**Option (C), ruled:** publish a sibling reduction beside the existing one —
`hard_rail_terminal_contacts_from_rails(rails, vertexExtent)` — emitting, per `HardRailId`, the typed terminal
`SourceVertexId` pair taken from `rail.sourceVertices.front()` and `.back()`, skipping `closed` rails (which
have no terminal), carrying `rail.component`, and using the same existing typed conversion. Thread it to
`make` at the same three call sites that already thread the edge keys. This is the **seventh** publish/reach
instance and the strongest form yet: producer and consumer are already joined by a live call, so the change
widens a reduction rather than inventing a channel.

The contact is keyed by `HardRailId` and carries `component`, which answers the STOP's "front endpoint,
correct component/sheet" without any raw-int namespace equality and without geometric closeness.

**Fixture consequence, ruled.** The archived rail patch was held because hand-authored fixtures omit exact
chains. Under (C) that resolves itself: a fixture supplying hard features **through rails** gets contacts for
free, and a fixture hand-authoring `hardFeatureEdges` with no rail is asserting hard features with no
producer and must **fail closed**. That is the same ruling RA-40 made for tests manufacturing route
certificates without a source-bound atlas. The archived patch stays unapplied; (C) supersedes it.

`rail_sample_source_vertex` (`src/geometry/SurfaceCellTracing.cpp:5820-5844`) becomes deletable at the
endpoint use, because `front()`/`back()` are exact. RA-43.4 stands.

---

#### 4. Code accepted this turn

`publish_phase_front_result` (`src/geometry/SurfaceCellTracing.cpp:12240-12250`) now reports
`PublishedProductRejected` and carries `publishedProductError`, ending the collapse of every factory
rejection into `InvalidFinalCellState`. **Accepted** — it discharges RA-42.3 at this locus.

Two soundness checks, both clean: `enum class SurfacePhaseFrontProductErrorCode : int;`
(`include/directional/geometry/SurfaceCellTracing.h:1689`) is an opaque declaration with a **fixed** underlying
type, so the type is complete and `std::optional` over it is well-formed, matching the definition at `:1809`;
and `std::get<SurfacePhaseFrontProductError>` cannot throw because the variant has exactly two alternatives
(`:1846`) and the `get_if` at `:12240` returns early on the other.

The seven two-face DCEL fixture repairs compiled but **were not executed**, so no restoration is claimed.

---

#### 5. Disposition

Release R4 Code + Build to continue with RA-44 as its specification. No runtime ran, selector 497 untouched.
CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2 losses. Stable ledger **66 / 17 / 49**,
debt **1** — unchanged: a vacuous check frozen in a review document is a review defect, not a runtime
regression. RA-41's junction/sector clauses remain frozen **UNEXERCISED** and the multi-carrier STOP stands.

## `Architecture_M6_CP3_R4_Edge_Index_Namespace_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Edge_Index_Namespace_Review_Decision.md`; moved verbatim.

### M6-CP3-R4 — source-edge index namespace: Review decision (RA-47)

**Turn:** `M6-CP3-R4-EDGE-INDEX-NAMESPACE-ARCH-REV` (independent Review).
**Request adjudicated:** `Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`.
**Verdict:** finding **R4-IDX-01 CONFIRMED**; **both** proposed repairs **REJECTED**; **RA-47 FROZEN** in their place.
**Method:** every decisive claim re-derived from repository bytes at `fdeb06b3f`. No binary built, no test executed, no runtime credit.

---

#### 1. R4-IDX-01 is confirmed, and its counterexample is sound

The reported conflation is real and the ordering table is correct.

- **Producer publishes a `featureMap.edges` position.** `src/pipeline/RemeshPipeline.cpp:9349-9359` indexes
  `featureMap.edges[entry.edgeIndex]` and pushes **that same integer** into `rail.sourceEdges` in the same
  iteration. The standalone path at `:9502-9503` does likewise. Decisive: the index-use and the store are the
  same expression, so no reinterpretation is available.
- **`featureMap.edges` is lexically ordered.** `include/directional/geometry/AdaptiveFeatureMap.h:181-207`
  builds `std::map<std::pair<int,int>, std::vector<int>> edgeFaces` keyed on `canonical_edge(a,b)` and emits
  `map.edges` by iterating that map — i.e. ascending `(min,max)` vertex pairs.
- **`TriMesh::EV` is halfedge-traversal ordered.** `include/directional/core/TriMesh.h:160-172`: `EV.row(i)` is
  taken from `dcel.edges[i]`, in DCEL first-encounter order, and is **oriented** `(halfedge.vertex,
  halfedge.next.vertex)` rather than canonical.
- **Counterexample stands.** For one face `(0,1,2)`: `featureMap.edges` = `(0,1), (0,2), (1,2)`; `EV` =
  `(0,1), (1,2), (2,0)`. A genuine rail on `(0,2)` is published as `1` and read back as `(1,2)`.
- **Consumer reads it as an EV row.** `src/geometry/SurfaceCellTracing.cpp:4233-4245` bounds-checks
  `declaredEdge` against `sourceMesh.EV.rows()` and compares `EV(declaredEdge,*)` to the typed key.

The request was right to stop. It was right not to convert silently inside Code + Build. It was also right that
a fixture using only `(0,1)` — where the two orders coincide — proves nothing.

---

#### 2. Two findings the request did not make

##### R4-IDX-02 — the field carries **three** namespaces, not two; the digest hashes whichever is present

`RemeshPipeline.cpp:17471-17476` builds `globalEdgeByVertices` mapping a typed key to a **global
`sourceMesh.EV` row**. `:17579-17593` builds `globalEdgeByLocal` indexed by **component-local `EV` row** and
valued with that global row. `:18106-18114` then rewrites `rail.sourceEdges` through it.

So the same field means **featureMap position** at the producer, is **read as a component-local EV row**, and is
**written as a global EV row** — and `:2043` and `:10005` feed it to the rail provenance digest
(`hash_vector(seed, rail.sourceEdges)`, immediately after `hash_vector(seed, rail.sourceVertices)`).

**Consequence that decides this review:** the request's own preferred repair — "an EV-index contract is a
plausible repair because field-aligned validation and component remap already use EV" — is **insufficient as
stated**. The component remap does not *use* one EV namespace; it *changes* namespace. Freezing "EV" leaves the
field's meaning dependent on whether component decomposition ran, and leaves the digest hashing a
path-dependent integer. A single frozen contract repairs the instance and preserves the class.

##### R4-IDX-03 — the two structural checks on this field are vacuous

`SurfaceCellTracing.cpp:4209-4212` and `:5937-5938` constrain only `sourceEdges.size()` against
`sourceVertices.size()`. The §1 counterexample satisfies both: a wholly foreign index vector of the right
length passes. These validate the **duplicate's length**, never its referent — LESSONS-171, "structural
presence is not behavioural coverage." They are not a defence and must not be cited as one.

---

#### 3. The decisive fact: `sourceEdges` has no genuine index consumer

Complete census of `SurfaceCellRail::sourceEdges` (all uses in `src/`, `include/`, `tests/`):

| Site | Use of the value |
|---|---|
| `SurfaceCellTracing.cpp:4233-4245` | **only** value consumer: derives the typed key from `sourceVertices`, then asks the raw index to agree |
| `SurfaceCellTracing.cpp:4209-4212`, `:5937-5938` | cardinality only (R4-IDX-03) |
| `RemeshPipeline.cpp:2043`, `:10005` | hashed into the provenance digest |
| `RemeshPipeline.cpp:9907` | compared against itself for determinism |
| `RemeshPipeline.cpp:9365`, `:9534-9536` | **diagnostic** `failedEdgeIndex`, feature-map namespace |
| `RemeshPipeline.cpp:18106-18114` | namespace translation (R4-IDX-02) |

No site consumes it as an index into a table it needs. The one value consumer performs a **round trip**: the
typed key is already in hand at `:4223-4225`, the raw index is dereferenced, and the result is compared back to
that same key. The round trip adds exactly one failure mode and zero information.

Three further bytes make this conclusive:

1. **Every hand-authored fixture derives the field from the typed key.** `tests/GlobalConformityBaselineTests.cpp:170`
   and `tests/GlobalConformityPlanTests.cpp:171` call `source_edge_index(mesh, barrier.sourceEdge)`, which
   linearly scans `mesh.EV` for the row matching the key it already holds. `tests/FieldAlignedCurveNetworkTests.cpp:492-494`
   does the same, having just written `rail.sourceVertices` from the two endpoints of that key.
2. **A namespace-free path already exists and works.** `RemeshPipeline.cpp:9588-9599`
   `hard_feature_edge_keys_from_rails` derives typed `SourceEdgeTopologyKey` values from `rail.sourceVertices`
   and **ignores `sourceEdges` entirely**. A4's `hardFeatureEdges` has always been fed this way.
3. **The digest already covers the authoritative datum.** `:2042` hashes `sourceVertices` on the line before
   `:2043` hashes `sourceEdges`.

**`sourceEdges` is a derived raw-int duplicate of `sourceVertices`, maintained in three namespaces, validated
only by length, and re-converted to the typed form at its single point of use.** That is RP-01
`AUTHORITY_DOMAIN_CONFLATION` in its pure form. RA-43 §4's inventory was an accurate description of a defect,
not a contract worth preserving.

---

#### 4. Why both offered options are rejected

- **Option "freeze EV, convert the producer through a `(vertex pair) -> EV row` map":** adds a conversion table
  to manufacture a value that is then converted back at `:4233`. Leaves R4-IDX-02 (the remap still translates
  local to global), leaves R4-IDX-03, and leaves a raw int whose correctness must be independently maintained in
  three places. Rejected.
- **Option "keep the feature contract, give both EV consumers authenticated feature-map lookup evidence":**
  strictly more machinery around the same duplicate, and it would push feature-map identity into A4, which holds
  no feature map. Rejected — and note it repeats the RA-42.1 stage-locus error.

Neither option can be made non-vacuous, because there is no predicate either can run that `sourceVertices`
does not already decide.

---

#### 5. RA-47 — FROZEN

**RA-47.1.** `SurfaceCellRail::sourceEdges` (`include/directional/geometry/SurfaceCellTracing.h:113`) becomes
`std::vector<authority::SourceEdgeTopologyKey>`. The raw-int edge namespace is **abolished** for this field.
RA-43 §4's row for `SurfaceCellRail::sourceEdges` is **superseded**: it recorded an observed defect, and the
other three rows of that table stand unchanged.

**RA-47.2.** The producer builds each entry from the endpoints it already validated —
`entry.startVertex`/`entry.endVertex` at `:9356-9360`, `edge.vertices.first`/`.second` at `:9502-9503` — via the
existing `surface_cell_source_edge_key` (`RemeshPipeline.cpp:3064`). No feature-map lookup, no EV scan. The
`sourceVertices` continuity check at `:9346` remains the sole authority for chain validity.

**RA-47.3.** `failedEdgeIndex` and `coveredEdges` **stay** feature-map indices and are sourced from
`entry.edgeIndex` directly. `:9365`'s `fail_edge(rail.sourceEdges.back())` must be rewritten to carry the last
feature index explicitly; it must **not** be reconstructed from a typed key. Diagnostic and topological index
spaces are never merged.

**RA-47.4.** `:18106-18114` is **deleted**, not converted. `:18093-18104` already remaps `rail.sourceVertices`
through `component.originalVertices`; the typed keys are rebuilt from the remapped chain immediately after. The
rails' dependence on `globalEdgeByLocal` ends with it. This is what closes R4-IDX-02 — the field acquires no
namespace to be translated between.

**RA-47.5.** `:4233-4245` collapses to a typed equality against the key derived at `:4223-4225`. The
`EV.rows()` bounds check and the `EV` dereference are removed. `InvalidRailGeometry` is retained and must not
be weakened; it now fires on a genuine topological disagreement rather than on a namespace artefact.

**RA-47.6.** The digest terms at `:2043` and `:10005` hash `first().index()` then `second().index()` per key,
matching the existing barriers pattern at `:9576-9580`. **The digest value changes.** No test pins a literal
digest (verified: no `railDigest`/`provenanceDigest` literal in `tests/`), and `:9907`/`:10005` compare
in-run products against each other, so no frozen identity depends on the old bits. Any future comparison
against a stored baseline must be re-derived, never back-fitted.

**RA-47.7 — the obligation that makes this non-vacuous.** A positive fixture on a mesh where the lexical
feature order and the DCEL EV order **differ**, carrying a rail on an edge whose two indices are unequal. The
single face `(0,1,2)` with a rail on `(0,2)` is sufficient and is hereby named as the minimum. A fixture
confined to `(0,1)` is explicitly disallowed as evidence. Required negatives, each verified at its **first
rejecting predicate**: a foreign typed key with correct cardinality (must reach `InvalidRailGeometry`, which
R4-IDX-03 shows the current code cannot do); a key whose endpoints are not an edge of the source mesh; a
closed rail whose final key does not close the chain; and a component-decomposed run whose remapped keys must
equal the single-component run's keys for identical geometry (the direct R4-IDX-02 falsifier).

**RA-47.8.** `tests/SurfaceCellREPackageTests.cpp:292-298` becomes a typed equality and thereby becomes
non-vacuous for the first time. `tests/MilestoneBClosureTests.cpp:142`'s literal `{0,1,2,3}` must be re-derived
from the fixture mesh's own vertex pairs; the test **identity** is preserved, the literal is not evidence. The
`source_edge_index` helper in `GlobalConformityBaselineTests.cpp` / `GlobalConformityPlanTests.cpp` is deleted
as an orphan of this change — the fixtures already hold `barrier.sourceEdge` and pass it directly.

**RA-47.9.** This is the eighth M6 instance of the publish-don't-invent family and its **dual**: the first seven
(RA-34.3, RA-35, RA-38, RA-40, RA-42, RA-44.1, and RA-43 as relocated) say *reach or publish what the producer
already holds*; RA-47 says *do not carry a second encoding of what you already publish*. Both reduce to one
test — can the added datum separate anything the authoritative datum cannot? Here, demonstrably not.

**RA-47.10 — no credit.** Nothing here is a runtime claim. The first observable failure, its count and the
affected frozen identities remain **unmeasured**. R4-IDX-01/02/03 are source-level review candidates, **not**
counted stable regressions: ledger stays **66 events / 17 categories / 49 recurrences**, debt **1**. Baselines
unchanged: CP2 **491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses.

---

#### 6. Liveness is an open question, not a defence

Whether `:4233-4245` currently rejects producer-built rails on the default path is **not established** by this
review and was not established by the request. Two readings remain open: the consumer is not reached with
producer-built rails, or it is reached and rejects. Either way RA-47 is correct, so the adjudication does not
wait on it — but the implementing turn must **report which**, because a consumer that has never seen a
producer-built rail is itself an RP-02 `TEST_AUTHORITY_COVERAGE_GAP` and would be a separate finding.

---

#### 7. Separate finding: destruction of the durable tracker

`0e1909d31` replaced `.agents/Directional/Regression_Root_Cause_Tracker.md` **in full** — 12,147 lines reduced
to 11 — with a single R4-IDX-01 entry. The tracker is the append-only durable ledger that every frozen RA
decision cites for its evidence base; replacing it severs those citations. The content was recoverable from
`497064965` and has been restored, with the R4-IDX-01 entry preserved and prepended as `0e1909d31` intended.
Recorded here as an architectural finding because the ledger is itself a durable artefact of the design, not
because of how the commit was made.

## `Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV`

**Date:** 2026-10-15 · **Reviewer turn:** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC-REV`
**Adjudicates:** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` (commits `db0b44a25`, `e87b7a3ad`,
`fbbbbf972`, `f3a9f38f2`, `11a601e76`)
**Subject document:** `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Authority_Specification_20261015.md`
**Verdict:** **ACCEPTED WITH AMENDMENT.** Gate C suspended; gate A's reciprocity conjunct struck;
**RA-64.6 withdrawn in full**; RA-64.4's illustration withdrawn, its conclusion retained.
No open REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no gate credit.

---

#### RA-65.1 — Authority re-derived from the provider and from tree objects, not accepted

Run `38765685488` (`Agent Source Snapshot`) is `success` with `headSha e87b7a3ad7a31577bfe758f6b00f3cdcd4f8ab3e`,
matching the spec's cited snapshot commit exactly. Artifact `11989475541`
(`agent-source-snapshot-38765685488`) is present at 24,087,190 bytes and unexpired. The snapshot log
(artifact `11989755474`) records `event_sha = snapshot_sha = final_sha = e87b7a3ad…`,
`snapshot_file_count=5640`, `snapshot_byte_count=102008557`,
`archive_sha256=5195b468af2fe726f3f526d73a831d3d20813bd52b5635dda5ec7a972d0aaf8b`.

**Tree identity — the decisive check.** `src` `76a12d4053a5c0798adcb0dce6d5eb8bf4e29623`, `include`
`790328c2bcffe29db5366ea1193cf0ab6d8cba58`, `tests` `cbef8d5ec448edb4c048b9058c7a0bd10a32b8af`, and the
decisive blob `src/geometry/SurfaceCellTracing.cpp` `6605c9f9ee8d7fc7859260b389f7fa2de755306f`, are
**byte-identical at the packaged semantic source `16c3134c0`, at the snapshot `e87b7a3ad`, and at HEAD**.
The specification therefore read exactly the bytes that were compiled into package `11976790988` and
measured by the 44-identity harvest. Every line citation below applies to the measured package.

Two files changed across the whole turn — the specification document and `STATUS`. No source, test,
selector, binary, harness, workflow, benchmark or ledger-count change; no Directional binary executed.

**Minor correction, charged under RA-61.5.** The spec's evidence line reads "**5640/5640 source
hashes**". The log records `snapshot_file_count=5640` — a **file count** — and verifies **no hashes at
all**. A count was dressed as a verification ratio in the one line that establishes the turn's
authority. The count itself is real and confirmed.

#### RA-65.2 — ACCEPTED: the RA-64.6 answer is correct, and the bytes say it more strongly than the spec does

The spec's central publisher claim — that `assign_open_front_boundary_authority` cannot silently omit a
carrier — is **CONFIRMED** from `src/geometry/SurfaceCellTracing.cpp`:

- `:12570` iterates **every** segment of the supplied `path`;
- `:12576-12591` derives the carrier topology from that segment's own face and its unsupported corner;
- `:12594-12597` **requires the segment's face to be one of that carrier's two incident faces**;
- `:12641-12644` flushes the open run the moment the carrier topology changes;
- `:12645-12647` rejects a nonconsecutive repetition of a carrier already seen;
- `:12669` flushes the tail run after the loop;
- and **every** failure path returns `SurfacePhaseFrontFailureReason::InvalidFrontBoundaryAuthority`.

A path carrying two carriers therefore yields **two** observed steps or **no front at all**. There is no
code path that shortens a route. `routeLength = 1` does mean this front side's supplied segment path has
one carrier run, and the spec's refusal to settle whether the *path itself* was complete — "static
inspection of this loop does not prove the preceding chart-path producer generated every intended
segment" — is the correct residue to leave open.

**Credit:** the spec answered the half the bytes decide and declined the half they do not, and it did so
without reclassifying a single RED.

#### RA-65.3 (PRINCIPAL) — the endpoint faces `{0,7}` were never measured; RA-64.6 is withdrawn in full

The probe emits exactly these scalar families, and no other:
`a2bProbeCarrierPresent`, `a2bProbeFailure`, `a2bProbeFirstFailedCondition`,
`a2bProbeFromSourceVertex`, `a2bProbeToSourceVertex`, plus the two `append_interval` blocks.
**No face is emitted anywhere in the diagnostic block at `:19395-19477`.**

`{0,7}` was the reviewer's inference, not a measurement. In the fixture, source vertex 4 belongs to
**six** faces — `0=(0,1,4)`, `1=(0,4,3)`, `3=(1,5,4)`, `4=(3,4,7)`, `6=(4,5,8)`, `7=(4,8,7)` — and
`carrier-orientation` fails for **any** attachment pair other than `(0,3)` or `(3,0)`. `{0,7}` was one
admissible reading among many, selected without warrant and then reported as measured.

Consequences, stated exactly:

- **RA-64.6 is WITHDRAWN in full.** "The route under-reports the front's extent" rested entirely on the
  invented pair: with the faces unknown, nothing says two carrier edges are required. Both of its
  readings (i) and (ii) are vacated along with the question itself.
- **RA-64.4's conclusion survives; its illustration does not.** That a face-pair mismatch fires first
  for all 21 is not an inference — it is what `carrier-orientation` *means*, and it was measured. The
  narrative that face 7 belongs to the rail's other edge and that "the geometry already spans the
  junction" is withdrawn.
- **The spec caught this and said so** at its line 15: *"the two-carrier inference drawn in RA-64.6
  solely from endpoint faces `{0,7}` and a one-step carrier `(1,4)` is unsound… No additional route step
  may be invented from endpoint face IDs alone."* Correct, and credited. This is the second consecutive
  turn to correct the reviewer on the record.

#### RA-65.4 (new lesson) — an explanatory instance is not a measurement

**A mechanism that *would* produce the observed value is not the mechanism that *did*.** Fifth member of
the family: provenance (RA-61.5), satisfiability (RA-61.7), event counting (RA-63.10), reachability
(RA-64.12), and now **uniqueness**. RA-61.5 required a prediction to state where its value came from;
this requires an explanation to state that **no other explanation fits the same evidence**, and to name
the measurement that would separate them when others do.

#### RA-65.5 (DEFECT) — gate C names a witness that no producer publishes

Gate C admits a chart not incident to the carrier edge "only through a **source-attested, uniquely
admissible vertex-star route** at that same vertex." The A3 authority product is
`SurfaceHardRailFieldTransition` (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`):

```cpp
struct SurfaceHardRailFieldTransition {
  authority::SourceEdgeTopologyKey edge;
  authority::SourceFaceTopologyKey firstFace;
  authority::SourceFaceTopologyKey secondFace;
  authority::QuarterTurn firstToSecond;
  auto operator<=>(const SurfaceHardRailFieldTransition &) const = default;
};
```

One source **edge**, its two faces, one quarter turn. There is **no vertex-keyed transition record
anywhere in `include/` or `src/`**: every `vertexStar*` symbol in the tree is a *diagnostics* field
(`include/directional/diagnostics/RemeshDiagnostics.h:459-477`), never an authority product.

Gate C therefore proposes a predicate whose attesting producer does not exist — the RA-61.7
satisfiability failure one level up, and precisely what RA-64.11 bound this rung to avoid. **Gate C is
SUSPENDED** until a successor either names the producer that would publish such a route or withdraws the
gate. **Gates A, B and D stand.**

#### RA-65.6 (DEFECT) — two vacuous conjuncts, immediately after RA-64.5 condemned exactly that pattern

**(a) Gate A's "exactly reciprocal endpoint ordinals" cannot be false.** The ordinals are *minted, not
measured*. `:17073-17079` writes the forward interval as
`from_integer(ordinal)` / `from_integer(ordinal + 1U)`; `:17095-17101` writes the reverse interval as
`from_integer(ordinal)` / `from_integer(ordinal - 1U)`. Reciprocity between a paired forward and reverse
arc is a **construction identity**. This is strictly stronger than RA-64.5, which found the conjunct
satisfied 44/44 by measurement: it is satisfied 44/44 **by construction**, and would be satisfied by any
population whatever.

**(b) "Identical … support piece" (spec line 28) carries no information.** `:17051` rejects outright any
`location->supportPieceIndex != 0U`. The support piece is therefore **0 in every record that survives to
be compared**.

The spec warns against this at line 28 — *"This is not withdrawn RA-61.9 under a new label"* — and then
commits it twice. The **one** conjunct that does work is independent per-endpoint exact parameter
resolution, which is genuinely new and is exactly what RA-63.5 showed the per-edge interval cannot do.
Keep it; strike the two decorations. A conjunct that cannot be false is not a gate.

#### RA-65.7 — the "exposure" the contract asks for is a type change, and no published type can receive it

The producer computes precisely the product the contract wants. At `:17047-17060`, `location_parameter`
resolves an exact `authority::FieldExactRational` edge parameter from
`baseline.breakpoint_location(span, exactOrdinal)` — and the spec's citation of
`GlobalConformityBaselinePlan::breakpoint_location` is **accurate**
(`include/directional/geometry/GlobalConformityBaseline.h:181` and `:216`).

That exact value is then destroyed twice:

1. `:16791-16792` — `boundary_trace_point` casts it: `const double canonical = static_cast<double>(canonicalParameter.to_double());`
   Its destination `SurfaceTracePoint` is, in its entirety,
   `{ int face = -1; Eigen::RowVector3d barycentric = …; }` (`SurfaceCellTracing.h:90-93`) and
   **structurally cannot hold an exact parameter**.
2. The published `SurfaceSharedBoundaryInterval` (`SurfaceCellTracing.h:1418-1428`) carries `span`,
   `firstOrdinal`, `secondOrdinal`, `orientation`, `boundaryOccurrence` — the **breakpoint index**,
   never the parameter.

So "a later implementation should expose **that same checked producer product**" (spec line 26) is not
an exposure: **no published type has a field that can receive it.** Recorded, not escalated — the spec's
line 19 deliberately declines to name a new type in a DEFN turn, and that restraint was correct. The
successor that implements this must budget for the type change as the substance of the work, not as
incidental plumbing.

#### RA-65.8 — reopened: the spec read past a truncation mechanism inside the range it cited

The spec declared interpretation (i) "not established" and required a future claim to exhibit a specific
missing segment carrier. A **mechanism** exists, in the very range the spec cites (16990–17120):

```cpp
if (!subdivision.points.empty() &&
    (subdivision.uv.back() - uv).norm() <=
        1.0e-10 * std::max({1.0, width, height})) {
  return true;                                          // :17032-17036 — point dropped, success returned
}
```

`append_point` **silently drops** a point on a `1e-10` UV-proximity test and returns `true`, while the
interval for that ordinal is pushed **unconditionally** (`:17081`, `:17103`). Points and intervals can
therefore desynchronize, and a dropped breakpoint can collapse a carrier run out of the path **before**
`assign_open_front_boundary_authority` ever sees it — upstream of the publisher RA-65.2 cleared.

**Not demonstrated for the measured 44**: their ordinals are exact integers on a unit grid, where a
sub-1e-10 UV coincidence between distinct breakpoints is implausible. The spec's conclusion for the 44
therefore stands. Its *general* claim that a second carrier "cannot be silently omitted" is correct only
of the A4 publisher, not of the pipeline. Backlog locus, not this rung's work.

#### RA-65.9 (scoped correction) — `routeLength = 1` is exact only up to 1e-9

`assign_open_front_boundary_authority` carries `constexpr double tolerance = 1.0e-9` (`:12507`) and
decides, entirely in doubles: which corner is unsupported and hence **which edge is the carrier**
(`:12578-12579`); whether a run's parameter delta is large enough to publish at all (`:12539`); and
whether consecutive segments connect (`:12655`). `canonical_retained_edge_parameter` (`:12509-12531`)
returns a clamped `double`. The spec's "**precisely**" at line 9 should read "up to that tolerance".

Harmless for the measured 44 — their barycentrics are exact 0/1 — but it undercuts the document's
framing, in which the route is treated as reliable exact authority while only the endpoint half needs
exactness. Recorded as a backlog locus.

#### RA-65.10 (NEW structural locus) — the endpoint points are not drawn from the front's own path

```cpp
edge.from = cell.corners[static_cast<std::size_t>(side)];
edge.to   = cell.corners[static_cast<std::size_t>((side + 1) % 4)];
```

at `:13034-13035`, `:14774-14775` and `:17345-17346`. The certificate's endpoint trace points come from
the **cell corner array**; the route comes from `cell.boundaryPaths[side]`. Every path segment is forced
incident to its carrier at `:12594-12597`. **Nothing anywhere reconciles the corner array against the
path's face set.** That absent invariant — not the terminal-contact vocabulary — is where gate D's phrase
"endpoint incidence" must actually bite: at **corner-to-path** incidence.

#### RA-65.11 — the decisive measurement costs five integers, and it now outranks the RA-63.11 deferral

Whether `oriented_carrier`'s refusal is a granularity defect or a **correct refusal** turns on *which*
faces the two corners are charted in — the one fact never measured. Both outcomes are live:

- if the two charts lie in the **same** rail sector of the shared vertex, gate C has something it could
  admit and `RP-01`'s third expression is real;
- if they lie in **opposite** sectors, the endpoint is charted across the very feature the rail protects,
  `oriented_carrier` was right all along, and the defect is **chart selection**, not vocabulary.

Every value needed is already in scope inside the existing post-decision block: `fromPoint`, `toPoint`,
`probeCarrier`, and the two derived attachment keys the predicate actually compares. The RA-63.11 ladder
reorder was deferred to avoid invalidating the packaged compile at `16c3134c0`; that package's central
narrative has just been withdrawn, so the preservation argument no longer outweighs the measurement.

#### RA-65.12 — beacon

`Status: COMPLETE`, all six fields present, `Ended at:` populated, `Successor: UNKNOWN` **with reasoning
carried in the document**: *"An implementation or independent Review successor requires separate explicit
turn authority; no successor ID is invented here."* That is the RA-63.13 shape, not the RA-64.10
self-reference. **No defect.**

#### RA-65 — accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried
CP2 losses), frozen selector **30+12+449+6 = 497** — unchanged. The 44 RED remain the `R4-VIN-01`
baseline for `16c3134c0`, never a comparand against `11967601999`. No accepted-green loss, no ledger
credit, no promotion, no stable event, no regression recurrence, no 497 execution, no gate credit.
PR #8 draft/open.

`RP-01` **located, three expressions, one of them now in question** (RA-65.11) — not repaired;
specification delivered and amended; **code still not authorized beyond the diagnostic probe**.
`RP-02` **UNREACHED**. `RP-03` satisfied and exemplified a second consecutive turn.
`PROCESS-01` tooling residual discharged for every observed failure mode.
**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final.**

Both gates run and reported: `review_check.py boundary` → ALL CHECKS PASSED (0 documents changed by the
adjudicated turn); `review_check.py ledgers --base 0cabf1ebd` → ALL CHECKS PASSED.

Successor: **`M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`**.

## `Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Harvest_Review_Decision.md`; moved verbatim.

### RA-67 — `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` Review Decision

**Turn reviewed:** `M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` (artifact-only Test + Benchmark)
**Verdict:** **ACCEPTED.** One latent instrument defect recorded, verified harmless for this
measurement. One reporting omission. No open REVIEW_BLOCKER. No promotion, no stable event, no
regression recurrence, no gate credit.
**Date:** 2026-10-15

Everything below was re-derived from repository bytes and immutable artifacts. Nothing is accepted on
the turn's report.

---

#### RA-67.1 — The result package is closed by bytes

Run [38782417387](https://github.com/akashskypatel/Directional/actions/runs/38782417387) `success`,
`headSha 8e8cf1cfa` (the dispatch commit). Result artifact `11996317553`, 80,281 bytes. **The ZIP
SHA-256 was recomputed on the downloaded bytes —
`44df6e2fc1bdba1e15f81e11ddec7bbb6cc90e2d43adcda4f334d875d1dbd9c9` — and matches both the provider
digest and the report.** The manifest was **re-verified rather than read**: `shasum -a 256 -c
SHA256SUMS` over the extracted archive returns **51 OK, 0 BAD** across 52 files.

`execution-boundary.txt`: `artifact_id=11994726341`, `source_sha=5be5e123e…`, `planned=44`,
`executed=44`, `red=44`, `missing=0`, `postflight=true`, `compile=false`, `relink=false`,
`benchmarks=false`, `selector497=false`, `exit=0`. `ledger.tsv` carries **44 RED**, no
`NOT_SELECTED`, no `NOT_EXECUTED`. `manifest-before.txt` and `manifest-after.txt` are **byte-identical
at 28 OK each**, so the immutable package was not mutated across execution.

One precision about the boundary file: `planned=44` is a **literal** in the `finish` printf
(`m6_cp3_r4_endpoint_chart_harvest_harness.sh:11`), not the computed counter. It is nevertheless
true, because `:120` asserts `[[ "$planned" == 44 ]] || die` and the recorded `exit=0` can only be
reached past that assertion. A reader must therefore read `exit` before `planned`; on a die the file
would still print `planned=44`. Recorded as an instrument note, not a defect.

#### RA-67.2 — The harness pins the new package, and the old harness was not reused

Harness SHA-256 independently recomputed as
`5b13f121bd678ec975e9c4d00df3685e79893eff8f7f9f42f980402b9b955fab`, identical to the value pinned in
`agent-dispatch-request.json` and reported. It pins artifact **`11994726341`** and source
`5be5e123e…` (`:17-21`, `:27`); artifact `11976790988` does not appear anywhere in the file. The
RA-66.11 hazard was therefore avoided in fact, not only in words.

RA-61-standard pinning is intact and fail-closed throughout: provider digest (`:19`), recomputed ZIP
digest (`:21`), manifest hash and 28-count (`:24-26`), source identity (`:27`), `GMP` /
`runtimeExecution=false` (`:28-29`), packaged source archive hash (`:31`), four frozen selector
hashes (`:33-39`), three before/after byte inventories with `cmp` (`:40-44`, `:199-204`), postflight
manifest (`:205`), and a closing `executed==44 && missing==0 && postflight` assertion (`:209`). The
census inventory is pinned by SHA with a duplicate assertion (`:45-51`); I re-verified its hash
(`de05a7bd…`), its 39 rows and its single ordinal `405`, giving 38 + 6 = 44.

**The harness never asserts the verdict.** `red` is counted, never required. The population is
fail-closed; the outcome is not. That is the correct shape for a measuring instrument and is recorded
as credit.

The two `SurfaceCellTracingPhase14` identities are **not** bundled: `Phase14` appears once in the
harness, in the comment at `:83-84` declaring them deliberately out of scope, and zero times in the
ledger.

#### RA-67.3 — The partition table re-derived independently, and it holds

I re-derived the table from `endpoint-chart-harvest.tsv` without reference to `chart-summary.txt` or
the report, grouping on the full tuple of condition, both face rows, both attachment keys, both
carrier keys, the computed edge, membership, swap and verdict. **Exactly three distinct tuples exist,
with counts 23 / 15 / 6, all `RED`, all `COMPLETE`:**

| n | first failure | rows | attachments | carrier pair | edge | membership |
|---:|---|---|---|---|---|---|
| 23 | `not-same-interior-carrier-point` | 0 → 3 | (0,1,4) → (1,4,5) | (0,1,4)/(1,4,5) | (1,4) | **both**, not swapped |
| 15 | `carrier-orientation` | 0 → 7 | (0,1,4) → (4,7,8) | (0,1,4)/(1,4,5) | (1,4) | **one** (the *from*) |
| 6 | `carrier-orientation` | 0 → 7 | (0,1,2) → (2,6,8) | (0,1,2)/(1,2,5) | (1,2) | **one** (the *from*) |

The uniformity the report presents is real: every one of the 15 and every one of the 6 is identical
in all measured fields. The intersections check by hand — `(0,1,4) ∩ (1,4,5) = {1,4}` and
`(0,1,2) ∩ (1,2,5) = {1,2}` — and membership is exact key equality, never a row comparison. The
first-order partition RA-66.7 scoped is therefore **settled: 21/21 exactly one, always the *from*
attachment; zero neither, zero both, zero swapped, zero missing keys.**

#### RA-67.4 — RA-66.4 is discharged in the right way

The carrier edge is computed by a genuine two-element set intersection
(`:172 edge = sorted(set(c) & set(d))`), guarded on cardinality exactly two (`:173`), and the
instrument **says in its own output** that the value is derived: `chart-summary.txt` line 1 reads
`carrier_edge_derivation=two-element set intersection of CarrierFirstFace and CarrierSecondFace
canonical vertex triples; not an emitted field`. The report repeats it at its line 19. No edge is
printed as though the probe had emitted one. The evidence is fail-closed: any `carrier-orientation`
case with an unresolvable key or a missing face row appends to `missing` and raises `SystemExit`
(`:181-182`, `:196-197`), so "zero missing keys" is enforced rather than asserted.

#### RA-67.5 (NEW) — The two junction groups are one phenomenon in two vertex-index domains

The report prints the 15 and the 6 as two rows of one table, with plain integer triples and no domain
column. They are not two findings. They are **the same measurement under two different vertex
labellings**, and the relabelling is recoverable exactly.

`make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-263`)
builds two disconnected 3×3 grids. For a component at vertex offset `k` the face rows are emitted in
this order:

```
f0=(k+0,k+1,k+4)  f1=(k+0,k+4,k+3)  f2=(k+1,k+2,k+5)  f3=(k+1,k+5,k+4)
f4=(k+3,k+4,k+7)  f5=(k+3,k+7,k+6)  f6=(k+4,k+5,k+8)  f7=(k+4,k+8,k+7)
```

Canonically sorted, component 0 gives `f0=(0,1,4)`, `f3=(1,4,5)`, `f7=(4,7,8)` — **exactly the
Junction-A keys.** Component 1 gives `(9,10,13)`, `(10,13,14)`, `(13,16,17)` — not the Junction-B
keys either. But relabel the component's vertices by **order of first appearance in its face list** —
`0,1,4,3,2,5,7,6,8 → 0,1,2,3,4,5,6,7,8`, i.e. `4→2`, `2→4`, `7→6`, `6→7` — and:

| component-local face | global key | compacted key | measured as |
|---|---|---|---|
| f0 | (0,1,4) | **(0,1,2)** | `CarrierFirstFace`, `FromAttachment` |
| f3 | (1,4,5) | **(1,2,5)** | `CarrierSecondFace` |
| f7 | (4,7,8) | **(2,6,8)** | `ToAttachment` |

Six independent confirmations of one mapping: three face keys, the carrier edge (`(1,4) → (1,2)`,
matching the measured Junction-B edge), and both source-terminal vertices (`4 → 2`, matching the
measured `fromV=2, toV=2` against Junction A's `fromV=4, toV=4`). The face **rows** `0 → 7` coincide
across both groups because the compaction relabels vertices and leaves face order untouched.

**Consequence.** The 21 junction identities are a single uniform phenomenon, observed twice in two
index domains, and the apparent two-row structure of the table is an artifact of vertex relabelling.
The report's framing is not wrong per identity — membership is computed inside a row and is therefore
domain-consistent — but the sentence treating `0 → 7` as one measured fact spans two domains, and the
table offers no column that would let a reader notice. **A probe that prints a `SourceVertexId`
without naming its domain makes one object look like two.** That is `RP-01
AUTHORITY_DOMAIN_CONFLATION` reproducing itself inside the instrument built to measure it.

#### RA-67.6 (DECISIVE) — The mechanism, exhibited from bytes line by line

RA-65.11 asked which rail sector owns the endpoint and RA-66.7 ruled that the answer must be
exhibited from the fixture's bytes, never asserted. It can now be exhibited, and it does not require
a sector.

1. The fixture declares **two** hard edges per component, and they **share a vertex**:
   `add_rectangular_midline_hard_feature` (`tests/SurfaceCellsPhase10Tests.cpp:266-273`) inserts
   `{offset+1, offset+4}` and `{offset+4, offset+7}`. In component-local terms: edge **(1,4)** and
   edge **(4,7)**, meeting at vertex **4**.
2. From the face table above, edge **(1,4)** lies in faces **{0, 3}** (`f0=(0,1,4)`, `f3=(1,4,5)`),
   and edge **(4,7)** lies in faces **{4, 7}** (`f4=(3,4,7)`, `f7=(4,7,8)`).
3. The measurement puts the front edge's two endpoints at **face 0 and face 7** — one face of the
   first hard edge and one face of the **second**. Both endpoints sit at vertex 4
   (`fromV=4, toV=4`), the vertex the two hard edges share.
4. A carrier record is **edge-keyed by construction**: `SurfaceHardRailFieldTransition`
   (`include/directional/geometry/SurfaceCellTracing.h:1482-1489`) holds one
   `SourceEdgeTopologyKey` and exactly two `SourceFaceTopologyKey`s — the two faces of **that one
   edge**.
5. `oriented_carrier` (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) returns a record only when
   `{record.firstFace, record.secondFace}` equals `{from, to}` in one order or the other.

Therefore: **when a front edge's two endpoint faces are drawn from two different hard edges, no
carrier record can contain both, and `oriented_carrier` cannot match in either orientation.** The
refusal is structural, not numerical, and not a tolerance. Every premise is a repository byte; the
only measured input is the endpoint face pair, which the harvest supplies.

This is `RP-01`'s third expression, no longer merely located but **demonstrated**: an edge-keyed
authority is being asked a question that is about a vertex. It is also why **gate C stays suspended**
rather than being revived — the measurement confirms the *shape* gate C was reaching for (both
endpoints at one source vertex, 15× at v4 and 6× at the same vertex relabelled v2), and changes
nothing about RA-65.5, because a witness with no producer remains unimplementable. Confirming that a
witness would be apt is not the same as finding its publisher.

**What this does not establish.** It does not say what the repair is. Two shapes are admissible on
the face of it — the A4 publisher splitting a front edge at a junction vertex so each piece has one
carrier, or the consumer predicate becoming vertex-aware — and they differ in which authority gains a
new obligation. Choosing between them is a definition question, not a measurement, and no code is
authorized by this decision.

#### RA-67.7 — The row pair `{0,7}` does not vindicate the withdrawn RA-64.6

The rows I invented at RA-64.4 and withdrew at RA-65.3 appear in the measurement. **The withdrawal
stands and the inference is not rehabilitated.** Three reasons, each from the data above: the same
row pair arises in two different index domains (RA-67.5), so it is not one object; the rows are the
*least* informative field measured, since the predicate compares keys and never rows; and RA-64.6's
actual claim was that a publisher had **truncated a route**, which nothing here shows — the
publisher cannot shorten a route at all, only reject (established from
`assign_open_front_boundary_authority`, `:12481-12692`). A number that happens to coincide is exactly
what **RA-65.4** warns about, and the coincidence is evidence for that lesson, not against it.
**RA-64.6 remains withdrawn, final.**

#### RA-67.8 (DEFECT, latent — verified harmless here) — the first-match probe parse

The harvester extracts each field with `re.search(name + r'=([^;\r\n"]+)')` over the whole log
(`:164`), which takes the **first** emission and records no occurrence count. The probe fires once
per rejected edge, so a test that rejects several edges contributes only its first chart, silently.

I checked rather than assumed. Two of the 44 raw logs — `27.log` and `41.log` — emit the probe
**three** times; the other 42 emit it once. In both multi-emission logs all three emissions are
**byte-identical** in every field, and both belong to the interior-shaped 23, so none of the 21
junction rows is affected and nothing in RA-67.3 changes. The loss is nil for this measurement; the
**narrowing is undisclosed**, and a future divergent case would be hidden the same way while the run
still looked clean. Remedy for the successor instrument: record the per-log emission count in the
TSV and assert uniformity, or emit one row per emission.

#### RA-67.9 — Harvested but unanalyzed, and it confirms a struck conjunct

The TSV carries eight interval fields the report never discusses. They are uniform per group: both
intervals present in all 44; `FirstSpan == SecondSpan` in all 44 (span 3 for the 23 and the 15, span
2 for the 6); and the ordinal pairs are **reciprocal and reversed** — `(0/1, 1/1)` against
`(1/1, 0/1)` for the 23, `(3/1, 4/1)` against `(4/1, 3/1)` for the 21.

That is **RA-65.6a measured**. I struck the reciprocal-ordinal conjunct from the gate A specification
on the argument that reciprocity is a construction identity of `append_arc`
(`src/geometry/SurfaceCellTracing.cpp:17043-17107`, ordinals minted as `ordinal` and `ordinal + 1`).
The harvest shows it holding for all 44 cases **including every one of the 44 RED** — a conjunct that
is satisfied by every rejected case cannot discriminate, which is what vacuous means. The strike is
confirmed by measurement, not only by argument. The integer ordinals also re-confirm the RA-65.7
locus: the published object is the **index**, never the parameter.

Charged lightly against the turn as **under-reporting**: the fields were harvested voluntarily, which
is good, and then left unexamined, which left a confirmation on the floor.

#### RA-67.10 — The long-file mutation was verified against an immutable pre-image

The closeout did something new and right. Rather than editing a 13,512-line protected document on
trust, the turn took an exact source snapshot first — run
[38805395498](https://github.com/akashskypatel/Directional/actions/runs/38805395498) `success` at
`393d6c548`, artifact `12005034654` — and patched against it.

I re-verified the whole chain. The outer ZIP SHA-256 recomputed on the downloaded bytes is
`09a865c0e7b6398a2b1dcc6cc3ed839449dd1de0486e81dfb56b2bc6d759e96e`, matching the provider digest; the
inner `source.tar.gz` hashes to `adbc497359822d338a2831aade5e752a70907455f48932accb0783440fbd0225`,
matching both its sidecar and `snapshot-metadata.json`; and `shasum -a 256 -c SHA256SUMS` over the
extracted source tree returns **5,647 OK, 0 BAD**.

**This is the RA-65.1 defect structurally eliminated, not merely reworded.** At RA-65 the evidence
line said "5640/5640 source hashes" when the snapshot recorded only `snapshot_file_count` and
verified nothing; at RA-66 the wording was corrected in the turn's own words; here the snapshot
package **contains a 5,647-line per-file manifest** and the ratio is a real checksum verification. A
provenance charge answered first in language and then in the instrument is the best available
outcome, and it is recorded as credit.

The preservation claim itself also verifies. The snapshot's pre-image of the tracker is **exactly
13,512 lines** — the floor on record — HEAD's is **13,524**, the diff is **+12 / −0**, and the
trailing 13,512 lines of HEAD are **byte-identical** to the pre-image. Append-only is proven against
an immutable artifact rather than asserted.

#### RA-67.11 — Beacon and documents

The beacon closed correctly: `Status: COMPLETE`, all six fields, `Resumed at:` and `Ended at:`
populated, `Successor: UNKNOWN` **with reasoning carried in both the handoff and `TODO.md`** — the
RA-63.13 shape, **no defect**. The self-referential `Successor` that stood while the turn was
`IN_PROGRESS` was removed at closeout and never appeared on a `COMPLETE` beacon, so **RA-64.10 is not
charged**; it is noted only because a continuation beacon that names itself cannot be distinguished
from a stalled one, and the next long turn should write `Successor:` empty rather than self-naming
while in progress.

All four documents the turn touched are **pure insertions, zero deletions**, prepended with prior
sections intact: tracker +12, handoff +8, root `CHANGELOG.md` +7, `.agents/Directional/CHANGELOG.md`
+4. Floors clear before this Review's own prepends: tracker 13,524 lines / 656 `## ` / 13 marker
occurrences; handoff 4,601 / 310; root changelog 1,854 / 237.

#### RA-67.12 — Prohibitions honored, accounting unchanged

No C++, no compile, no relink, no new semantic source, no selector change, no 497, no benchmark, no
fixture change — `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` and every selector are
untouched across the whole turn. No sector, mechanism, repair or root cause was asserted by the turn:
the report states at its line 29 that the measurement "does **not** establish which upstream rail
segment, front sector, or publisher continuation should own the endpoint", and
`chart-summary.txt` records `sector_classification=NOT_INFERRED`. Ordinal 405 excluded with its
reason. `R4-VIN-01` correctly recorded as **candidate / non-stable** — the 44 RED are the baseline
for `16c3134c0` alone, and `5be5e123e` is a new semantic source, so `11976790988` and `11967601999`
stay **baselines, never comparands**.

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector
**30+12+449+6 = 497** — unchanged. No ledger credit, no promotion, no stable event, no regression
recurrence, no gate credit. `RP-01` **measured and mechanistically derived (RA-67.6), code still
unauthorized**; `RP-02` **UNREACHED**; `RP-03` satisfied a **fourth** consecutive turn; `PROCESS-01`
discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED (RA-65.5).**

#### RA-67.13 (LESSON) — Two labels for one object are not two observations

An identifier printed without its domain turns one phenomenon into two rows of a table, and the
duplicate then reads as corroboration. The 21 junction identities looked like two groups with
different keys and different carrier edges; they are one group seen twice. A measurement must name
the index domain of every identifier it prints, or it manufactures the appearance of independent
confirmation — the failure the instrument was built to detect, committed by the instrument.

#### Disposition

`M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST` — **ACCEPTED**. Successor:
**`M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC`**, a definition turn, no code.

## `Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE-REV`

**Date:** 2026-10-15 · **Reviewer turn:** `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE-REV`
**Adjudicates:** `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE` (commits `83b74252f`, `4c114b248`,
`5be5e123e`, `243a9feb7`, `b0dc97e86`, `cdb8b5bb4`, `a7eca7372`, `44fd97fc6`, `3d4b13292`)
**Subject record:** `.agents/Directional/Architecture_M6_CP3_R4_Endpoint_Chart_Probe_Code_Build_Record_20261015.md`
**Verdict:** **ACCEPTED.** One silent mandate deviation charged and recoverable. No open
REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no gate credit.

---

#### RA-66.1 — the compile chain is closed by bytes, end to end

Nothing here is taken on report.

- **Snapshot** run `38775481890` (`Agent Source Snapshot`) `success`, `headSha 4c114b248…` — the pin
  commit. Artifact `11993616345` present at 24,114,547 bytes.
- **Compile** run `38776964197` (`Agent Durable Operation Dispatcher`) `success`,
  `headSha 243a9feb7…` — the dispatcher request commit. Result artifact `11994726341` present at
  39,026,791 bytes.
- **ZIP SHA-256 recomputed on the downloaded bytes:**
  `b59dc16f4417693c4aec79025160da2054cfbca3a1589ef051ee3a171d3185bb` — **identical to the reported
  value**.
- **Manifest re-verified, not read:** `shasum -a 256 -c SHA256SUMS` over the extracted package gives
  **28 entries, 28 OK, 0 BAD**, matching the claimed 28/28.
- **Eight targets**, exactly as claimed: `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`.
- `preflight-exit-code.txt` = **0**, `build-exit-code.txt` = **0**; package records
  `exactArithmeticBackend=GMP` and `runtimeExecution=false`; `source-commit.txt` =
  `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`.
- **The decisive link.** `src/geometry/SurfaceCellTracing.cpp` *inside the manifest-verified package*
  hashes to `3833d8f4e204f6c202b1e9faa9b3e88da5c1e30a81ccd2b11f24d31408c3f91f`, which is
  **byte-identical to HEAD's**. The `src` tree is `fd09300ba38b10dfea728c8c3f7c4ed6b732c89c` at both
  the semantic source `5be5e123e` and HEAD, and `5be5e123e`'s parent is the pin commit `4c114b248`.

The package therefore contains exactly the probe code that is in the branch, with no gap anywhere in
the chain from pin to artifact.

`include`, `tests`, `benchmarks`, `cmake`, `.github` and every selector are **untouched**. No
Directional binary, test, benchmark or frozen-497 selector was executed.

#### RA-66.2 — decision-neutral by construction, verified structurally rather than asserted

The 23 added lines sit at `:19439-19461`, inside the block opened at
`:19360 if (!firstEndpoint || !secondEndpoint) {`, immediately after the pre-existing
`:19438 const auto *probeCarrier = find_carrier(endpointEdge);`. Every added line either declares a
local (`append_face_key`, the two scoped `face` bindings) or streams into `endpointEvidence`. No
acceptance path can observe any of it, because the block is only entered once both certificates have
already returned. The ladder, the predicates, `endpoint_certificate` itself and every rejection string
are unchanged.

#### RA-66.3 — the turn improved on the mandate, in the right direction

The mandate asked for raw face rows. The turn emitted the raw rows **and** the canonical attachment
keys — `a2bProbeFromAttachment` and `a2bProbeToAttachment`, each a three-vertex
`SourceFaceTopologyKey` triple — alongside `a2bProbeCarrierFirstFace` and
`a2bProbeCarrierSecondFace`.

That is better than what was asked, because `oriented_carrier` (`:19106-19114`) compares
`record.firstFace == from && record.secondFace == to` on exactly these keys. The failing comparison is
now observable **field against field**, with no row→key re-derivation needed at review time and no
opportunity for the reviewer to supply the missing half from imagination. Given RA-65.3, that is the
correct instinct.

#### RA-66.4 (DEFECT, recoverable) — a mandated field is absent and the omission is unacknowledged

`a2bProbeCarrierEdge` was item 3 of five. `grep -c a2bProbeCarrierEdge src/geometry/SurfaceCellTracing.cpp`
returns **0**. Neither the record nor the handoff notes the deviation; the record lists its six fields
as though six were what was asked.

**The information is not lost.** `SourceFaceTopologyKey::vertices()` returns
`std::array<SourceVertexId, 3>` (`include/directional/authority/AuthorityIds.h:442`), and the carrier
edge is the two-element **intersection** of the `CarrierFirstFace` and `CarrierSecondFace` triples.
The substantive loss is nil; the **silence** is the defect. The Test + Benchmark successor must compute
the intersection and state that it computed it rather than printing a carrier edge as though it had
been emitted.

#### RA-66.5 — a new dereference, raised and discharged

The probe adds `network.sourceTopologyRegions->topology_for_row(...)`, which the RA-63 probe did not
contain. The enclosing function already dereferences that pointer unguarded at `:18967`, `:18968`,
`:19048`, `:19050`, `:19076`, `:19136`, `:19138`, `:19154` and `:19196` — and `:19076` lies on every
path that reaches the probe. **No new crash surface.**

One divergence from the real path exists and it is an improvement: `:19134` requires **both** source
faces to resolve before either is dereferenced, whereas the probe guards each independently. A case in
which exactly one face resolves now reports the half that does, instead of reporting nothing.

#### RA-66.6 — the bounds idiom matches the surrounding code, and that idiom is unguarded

`topology_for_row` is not bounds-safe; elsewhere callers test `face_count()` first (`:8941`). The probe
bounds its row through `source_face_id(point.face, faces.rows())`, exactly as `:19130-19133` does —
`faces.rows()`, not `sourceTopologyRegions->face_count()`. The probe therefore introduces **no new
hazard**, but the pre-existing asymmetry between the two extents is recorded as a backlog locus. It is
not this rung's work and must not be repaired opportunistically.

#### RA-66.7 — what the measurement will decide, and what it will not

The emitted set decides the **first-order partition** directly and without inference: whether neither,
exactly one, or both of `FromAttachment`/`ToAttachment` lie in
`{CarrierFirstFace, CarrierSecondFace}`, and if both, whether they are swapped. That is enough to say
where the mismatch sits.

It does **not** by itself decide the sector refinement RA-65.11 named, because the rail's *other*
incident edges at the shared vertex are not emitted. For these 21 identities the rail edge set is
byte-fixed in `tests/SurfaceCellsPhase10Tests.cpp:223-264`, so the refinement is derivable from
repository bytes — but the derivation must be **exhibited from those bytes**, not asserted. Asserting
a sector from a consistent reading is precisely RA-65.4 one level down.

#### RA-66.8 — the previous charge was absorbed in the turn's own words

Record line 7 reads "5642 source files (**file count, not a checksum-verification ratio**)". RA-65.1
charged exactly that misdescription one rung earlier, and the correction appears unprompted inside the
new turn's own evidence line rather than in a reply. That is the shortest possible loop from charge to
uptake.

#### RA-66.9 — documents

The handoff was **prepended**: two new sections sit above the RA-65 section, which is intact below,
and the top section states that the one beneath it is "preserved as historic pending state." Two
CURRENT sections for a single turn — a pending one and a completion one — is a readability cost rather
than a defect, since the supersession is declared in text. `TODO.md` was likewise prepended. The three
commits sharing the message "close endpoint chart compile checkpoint with verified GMP evidence" touch
**three different files** (record, handoff, `TODO.md`), so this is not the RA-64.9 retry pattern.

#### RA-66.10 — beacon

`Status: COMPLETE`, six fields, `Ended at:` populated, `Successor: UNKNOWN` **with reasoning carried in
the record** — *"Next artifact-only probe execution and independent Review require separate
authorization; there is no authorized named successor at closeout"* — and reinforced in the handoff
(*"do not invent a successor"*). The RA-63.13 shape. **No defect.**

#### RA-66.11 — `R4-VIN-01` re-arms, and the old harness must not be pointed at the new fields

`5be5e123e` is a **new semantic source** and `11994726341` a **new package**. Artifacts `11976790988`
and `11967601999` are now baselines, never comparands. The 44 RED remain the baseline **for
`16c3134c0`**; nothing measured against the new package may be differenced against them without
re-establishing the selector view first.

The record states this hazard about its own instrument before being asked: the pinned 44-case harness
**pins the old immutable package** and "must not be run against it to claim these new fields."
Correct, and load-bearing — a harness that silently measured the old package would report every new
field as absent and look like a clean negative.

#### RA-66 — accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried
CP2 losses), frozen selector **30+12+449+6 = 497** — unchanged. No accepted-green loss, no ledger
credit, no promotion, no stable event, no regression recurrence, no 497 execution, no gate credit.
PR #8 draft/open.

`RP-01` located, three expressions, **one in question pending this measurement** — not repaired.
`RP-02` **UNREACHED**. `RP-03` satisfied a third consecutive turn. `PROCESS-01` discharged.
**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED (RA-65.5).**

Both gates run and reported: `review_check.py boundary` → ALL CHECKS PASSED;
`review_check.py ledgers --base ec7670973` → ALL CHECKS PASSED.

Successor: **`M6-CP3-TB4-R4-ENDPOINT-CHART-HARVEST`**.

## `Architecture_M6_CP3_R4_First_RED_Carrier_Reclassification_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_First_RED_Carrier_Reclassification_Review_Decision.md`; moved verbatim.

### RA-56 — the first RED is not a new candidate; it is a live reproducer of the 39-identity `A4_ROUTE_CERTIFICATE_REJECTION` carrier

**Turn:** `M6-CP3-R4-WITNESS-REV-ARCH-REV` (Architecture Review only).
**Adjudicates:** `M6-CP3-TB1-R4-WITNESS-EXEC` and `M6-CP3-TB1-R4-WITNESS-REV`.
**Disposition:** the execution and its root-cause localization are **ACCEPTED and independently
re-derived**. The **classification is REJECTED and corrected**. The proposed repair turn
`M6-CP3-CB1-R4-WITNESS-REPAIR` is **RETAINED but DEFERRED** behind two measurement rungs.
**No runtime credit beyond the single executed identity.**

---

#### RA-56.1 — the execution held every boundary, and the root cause is CONFIRMED from bytes and geometry

No source, test, fixture, guard, selector or harness changed; first-RED stop honoured; frozen selector
hashes matched; no promotion. The RED was reported with its verbatim assertion rather than smoothed.

I re-derived the localization rather than accepting it. **It is exactly right:**

- `exact_corner` (`src/geometry/SurfaceCellTracing.cpp:19131-19143`) requires a bit-exact one-hot
  barycentric at the corner of `vertex`, for **both** `fromPoint` and `toPoint`, at the **same** terminal
  vertex drawn from `contact->second.endpoints`; otherwise `no-exact-terminal-corner` at `:19152`.
- The fixture mesh (`tests/SurfaceCellsPhase10Tests.cpp:223-264`) is a 3×3 planar grid per component:
  `v1 = (1,0,0)`, `v4 = (1,1,0)`, `v7 = (1,2,0)`, face `0 = (0,1,4)`, face `3 = (1,5,4)`. The hard feature
  is `{1,4} ∪ {4,7}` (`:266-272`), so the rail chain is `1 → 4 → 7` with terminals `{1,7}`.
- The reported probes therefore resolve to **the same 3D point**:
  `face 0, bary (0, 0.75, 0.25) = 0.75·v1 + 0.25·v4 = (1, 0.25, 0)` and
  `face 3, bary (0.75, 0, 0.25) = 0.75·v1 + 0.25·v4 = (1, 0.25, 0)`.
  That point lies at parameter `0.25` **interior to source edge `(1,4)`** and is neither terminal `v1` nor
  terminal `v7`. `corner[1]=0,0; corner[7]=0,0` is correct behaviour, not a defect in the predicate.

**And a co-signal that must not start a false hunt.** `currentFace=0; expectedFace=2` looks like a route
face mismatch. It is not: `failure.face` and `failure.targetFace` (`:18939-18940`) fall back to
`first.from.face` and `second.to.face`, which `faceEnds=0,2|0,3` prints as exactly those values
(`:18948`, `:18951-18952`). The two fields carry **no independent signal**, and in particular this is
**not** an `RP-01` edge/face-namespace recurrence. The report attributed the whole failure to the
exact-corner predicate and was right to.

#### RA-56.2 — the classification is WRONG: this is not a new candidate without a baseline

The review records `R4-TB-A-RP02-01` as a new candidate and states *"No comparable accepted runtime
baseline exists for this identity."* That is true of the **new test's own name** and false of the
**failure**. The blast radius was never measured. From the repository:

- **All 21 other uses** of `build_rectangular_hard_rail_phase_front` in `SurfaceCellsPhase10Tests.cpp`
  also open with an assertion that the disposition is `Produced`. If the fixture does not produce, that
  whole family is RED — this is not one witness's precondition failing.
- Two of those identities — `ProductionA4PublishesAcceptedA2bA3ConformityReceipt` and
  `HardRailPairingIsFaceRowOrderInvariant` — are **inside the frozen `selector449`**
  (`.agents/Directional/selectors/Architecture_M5_CP4_CB2_Required_Green_Selector_449.txt`, the file the 497 harness
  pins at `tools/m6_cp3_entry_497_artifact_only_harness.sh:16`).
- `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` already carries this failure. The 94 R3 RED
  decompose into eight carriers, and the largest is **`A4_ROUTE_CERTIFICATE_REJECTION` at 39**, of which
  **37 are `CP2_ACCEPTED = true`**.
- That set of 39 is **exactly** the long-carried "39 endpoint" backlog item: its identities match
  `Architecture_M6_CP3_R4_Historical_R3_A4_39_Current_Source_Inventory_20261013.tsv` **39/39, with no
  element on either side unmatched**.
- **37 of the 39 lie inside the frozen 497** (26 in `selector449`, 9 in `focused30`, 2 in `focused12`) —
  the same 37 that are CP2-accepted. They are therefore **37 of the 88 carried CP2 losses**.

**Corrected classification.** `R4-TB-A-RP02-01` is **not a new carrier and not baseline-free**. It is a
**new, cheap entry point into the existing `A4_ROUTE_CERTIFICATE_REJECTION` carrier**, which has an
accepted CP2 baseline. Read correctly, this is the most valuable result TB-A could have produced: an 8 ms,
single-test, fully typed reproducer of the carrier that accounts for **~42% of the carried CP2 losses and
~41% of the 94 R3 RED**. The review undersold its own finding.

#### RA-56.3 — the carrier is measurable **now**, with no rebuild, and must be measured before any repair

All **39** carrier identities are owned by `directional_surface_cell_producer_tests` — the binary already
inside the immutable package that ran TB-A — and split
`SurfaceCellTransitionQuotientTests.cpp` 19 / `SurfaceCellsPhase10Tests.cpp` 18 /
`SurfaceCellREPackageTests.cpp` 2. Every one of the 39 carries
`status = "STATIC ONLY — current result unknown"`.

**38 of the 39 carry the first-predicate hint `endpoint-0`. TB-A observed `endpoint-1`.**

So the single observation now driving a proposed producer change is the *minority* endpoint of its own
carrier, while 38 majority instances sit unmeasured and reachable for the cost of one artifact-only run.
Repairing the shared producer on that basis is how the wrong thing gets fixed confidently. **Measure the
carrier first.**

#### RA-56.4 — my stop-at-first-RED rule was wrong for a triage run; that is my error, and it is amended

RA-55.8 told the executor to stop at the first RED. That rule is correct **inside a repair loop**, where
its purpose is to stop mass-patching. It is **wrong for a first measurement**, where breadth is the whole
point. The executor followed the instruction exactly and should not be marked down for it; the cost is
mine:

- The **control** — `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm`, which uses a *different*
  fixture — was not run. Its result is the single most informative bit available: it separates "the
  rectangular hard-rail fixture family is down" from "A4 production is down generally."
- Three further identities executable from the **same artifact with no rebuild** were skipped.

**Amended rule, in force from now on:** stop at the first RED only **within a dependent chain**, where a
later identity cannot be interpreted without the earlier one. **Independent identities are all run**, and
every RED is reported with its verbatim first predicate. A triage run is not a repair loop.

#### RA-56.5 — an architectural risk the repair plan does not consider: a third reading

The plan offers two readings — an interior interval needing its own certificate, or a pairing rule that
manufactures a false terminal obligation — and correctly refuses to choose between them. But the dump
admits a **third**, and the plan's prescribed data model would silently exclude it.

`faceEnds = 0,2 | 0,3` decodes (`:18948`) as `first.from.face = 0`, `second.to.face = 2`,
`first.to.face = 0`, `second.from.face = 3`. The first front therefore lies **entirely inside face 0**,
and the second spans faces 3 → 2. Both meet at `(1, 0.25, 0)` on the rail. That is the signature of two
fronts meeting **transversally across** the rail, not of two intervals running **along** it.

The plan prescribes authenticating the admitted case with *"canonical intrinsic parameter on the same
source edge, ordered rail interval/face-side ownership."* That vocabulary presumes along-rail intervals.
**If the event is a transversal crossing, that is the wrong abstraction**, and adopting it would freeze a
mis-shaped certificate into the producer — the same class of mistake as RA-45.2's category error and the
"publish, don't invent" family. **Do not choose the certificate model before the carrier census says
which shape dominates.** The census answers it directly: every failing pair prints its own `faceEnds`.

#### RA-56.6 — the repair plan is otherwise sound and is RETAINED, not discarded

It refuses to pick a fix merely to satisfy the assertion, keeps `no-exact-terminal-corner` and the
duplicate-contact, barrier, closed-chain and missing-contact guards fail-closed for genuine terminals,
forbids weakening the RP-02 test's `Produced` precondition or its consumer receipt, forbids fallback and
source-grid recovery, and carries real stop conditions. That is the right shape for a repair turn. It is
deferred, not rewritten, and it must be re-entered **with the census in hand** and with RA-56.5 answered.

#### RA-56.7 — what remains true

`RP-02 TEST_AUTHORITY_COVERAGE_GAP` is **still open**: the run died before
`assign_open_front_boundary_authority`, so no consumer receipt exists and the tamper half never ran.
RA-55.3's source-level non-vacuity finding is undisturbed — the positive would still fail if the consumer
were bypassed — but non-vacuity is not liveness. `R4-OHF-02` stays recorded with its guard retained and no
probe. The two Phase14 identities need `DIRECTIONAL_BUILD_HISTORICAL_TESTS`
(`cmake/DirectionalTests.cmake:556-574`) and must be handled by a separate packaging turn, not bundled
into a measurement rung.

#### RA-56.8 — accounting

Ledger **66 / 17 / 49**, M6 debt **1**, selector **497** untouched, CP2 **491/491** accepted, R3
**403/497** rejected with 94 RED and 88 carried CP2 losses, PR #8 draft/open — **all unchanged**.
`R4-TB-A-RP02-01` is reclassified as an entry point into the existing `A4_ROUTE_CERTIFICATE_REJECTION`
carrier rather than a new candidate; **no new stable event, category or recurrence is minted**, because a
recurrence requires a reviewed runtime adjudication the census has not yet supplied. No promotion.
A compile is not a restoration (LESSONS 160); a census is not a witness (LESSONS 171); **and one measured
identity is not a measured carrier.**

## `Architecture_M6_CP3_R4_Gauge_Consumption_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Gauge_Consumption_Review_Decision.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — the +U gauge has no absolute consumer: Review decision

**Type:** runtime-free independent Review of the RA-44.2 producer-compatibility STOP.
**Disposition:** the STOP is **ACCEPTED and upheld on its facts**, and it is resolved by **withdrawing the
requirement**, not by constructing a pin. **RA-44.2's absolute geometric pin is WITHDRAWN.** Frozen as
**RA-45**. The R4 Code + Build turn is released to continue; the three producers are all admissible.

Read at HEAD `7f4a643d2`. Every claim is a direct byte read re-derived in this turn.

---

#### 1. The STOP's facts are correct

Three gauge producers reach one checked factory, and only one of them has the structure RA-44.2 assumed:

- **Planar** — `build_planar_phase_frame` (`src/geometry/SurfaceCellTracing.cpp:11143-11260`) builds
  `frame.axisU`/`axisV` and selects per face under `bestAlignment >= 1 - 1e-8`, with the `axisV` cross-check.
  RA-44.2's axes and predicate exist here.
- **Annular** — `score_ring_candidate` (`:13510-13691`) scores candidate seeds by averaging squared
  `acos(clamp(dot))`, selects the lowest finite score (`:13694-13704`) and publishes transported per-face
  branches (`:13804-13832`). A **best-fit minimisation**, not a zero-angle gate. No global `axisU`/`axisV`.
- **Curved bounded disk** — a deterministic face is chosen (`:15392-15433`), initialised to branch **0**
  (`:15488-15494`), and branches propagate by field-transport BFS (`:15495-15556`). No geometric gate at all;
  the root value is a **convention**.

The STOP is also right on the two traps it refuses to walk into: constructing `axisU` from the asserted
branch would pass trivially — the exact reason RA-43.5 was withdrawn — and the relational pin alone does not
reject a balanced global `+1`.

#### 2. Why no construction exists: the requirement was a category error

I looked for what consumes the gauge. **Nothing consumes it absolutely.**

- `RemeshPipeline.cpp:4605-4622` reads the gauge at an occurrence's `placement.selectedFace` and wraps it as
  `SurfaceOccurrenceEndpointFaceGaugeAuthority{face, QuarterTurn::from_integer(gauge)}`.
- It is stored only as a **pair** on `SurfaceOccurrenceRelationEvidence`
  (`include/directional/pipeline/RemeshPipeline.h:865-869`), assigned at `RemeshPipeline.cpp:5172-5173`.
- `:7300-7301` reads **presence only** (`has_value()`), never the value.
- `:5613-5630` reads presence and the **face identity** (`firstGauge.face != ...placement.selectedFace`),
  never the rotation against anything absolute.
- The only use of the value is the **difference**:
  `compose(second->localFaceBranchRotation, first->localFaceBranchRotation.inverse())`
  (`tests/SurfaceCellTransitionQuotientTests.cpp:3152-3153`).

`QuarterTurn` is Z4 and Z4 is abelian, so a uniform `+1 mod 4` on every face cancels in every such
difference: `(g+1) ∘ (g'+1)^-1 = g ∘ g'^-1`. **A balanced global rotation changes no consumer's decision.**

So RA-44.2 demanded absolute authentication of a quantity that is only ever consumed relationally. That is
why no construction exists for the annular and curved producers: there is nothing absolute there to
authenticate. The planar producer's `axisU` gate is *that producer's own convention-selection rule* — an
artifact of how it picks a gauge, not a property the gauge is required to have. Freezing one producer's
selection rule as a universal authentication requirement was my error. Withdrawn.

#### 3. What the authentication actually is

The relational A3 pin, **already implemented and compiled green** at `src/geometry/SurfaceCellTracing.cpp:8038-8080`:
it builds typed `SourceEdgeTopologyKey` incidence from `topology_for_row`, skips single-incidence open
boundary, and rejects unless `reverse->transport == forward->transport.inverse()` **and**
`compose(forward->transport, first) == second`. Together with mandatory presence (`:8020`) and
`SourceFaceTopologyKey`-derived keying, this rejects **every alteration a consumer could observe**:

| Perturbation | Outcome | Why |
|---|---|---|
| one face changed | **REJECT** | breaks the relation on that face's edges |
| any subset changed | **REJECT** | breaks the relation at the subset boundary |
| gauge vector permuted | **REJECT** | the relation is checked against `topology_for_row`, not the vector's order |
| A3 transport mismatch | **REJECT** | `compose(forward->transport, first) != second` |
| gauge absent while consumed | **REJECT** | the presence gate at `:8020` |
| **uniform `+1 mod 4` on every face** | **ACCEPT** | a gauge transformation, inert in every difference |

The last row is the reclassification. My pre-committed negative — "a balanced `+1 mod 4` on every face must be
REJECTED" — is **withdrawn**. Rejecting it would reject a legitimate convention, and it is unimplementable
without a pin that does not exist. Its replacement is a strictly stronger **positive** obligation: a uniform
rotation must be **accepted** and must produce a **bit-identical A6 relation outcome**. That tests
gauge-invariance as a property rather than asserting a value no one reads.

#### 4. One real constraint this exposes: do not normalise

`RemeshPipeline.cpp:2134-2144` folds the gauge into a provenance digest. So a uniform rotation is
**semantically inert but not digest-inert**. The factory must therefore **validate and never rewrite** — it
may not canonicalise the gauge (for instance by rotating it so some root face reads 0), because that would
change accepted CP2 provenance digests. Accept as produced.

This also dissolves RA-44.5's residual for authentication purposes: A4's floating-point alignment predicate is
no longer load-bearing for any check. It remains the planar producer's own selection rule and stays untouched.

#### 5. Answers to the STOP's three questions

1. **No** chart-U/V derivation for all three producers is required, because none is needed. Question 1 is
   moot.
2. **No** producer-specific absolute pin is authorised, and none is needed. RA-44.2 **is** formally amended —
   by this decision, which is the Review verdict the STOP correctly declined to make itself.
3. The witness schema is frozen in RA-45.3/.4/.5 below, with its coverage matrix in §3.

#### 6. Disposition

R4 Code + Build continues. RA-44.1's terminal-contact binding has landed
(`SurfaceHardRailTerminalContacts` as `std::map<HardRailId, SurfaceHardRailTerminalContact>`, header `:1512-1517`,
threaded into `make` at `:1882`) and is **accepted in shape**; its germ and endpoint duties remain open. No
runtime ran. Selector 497 untouched. CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2
losses. Stable ledger **66 / 17 / 49**, debt **1** — unchanged: an over-strong requirement frozen in a review
document is a review defect, not a runtime regression. RA-41's junction/sector clauses remain frozen
**UNEXERCISED** and the multi-carrier STOP stands.

## `Architecture_M6_CP3_R4_Interior_Endpoint_Repair_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Interior_Endpoint_Repair_Review_Decision.md`; moved verbatim.

### Independent Review — the interior-endpoint repair, its encoding collapse, and the pre-registered TB (RA-60)

**Turn:** `M6-CP3-TB1-R4-REPAIR-REV` (Review only). **Disposition:** the **compile is ACCEPTED**; the **implementation is ACCEPTED as faithful to RA-59.9** on every authentication requirement, verified line by line against the bytes; the **Step 0 falsifier CLEARS**, but on this Review's derivation rather than the turn's; and **four defects plus one principal design finding are recorded**, one of which must be fixed before any re-measurement if a specific branch occurs. No source, test, selector, binary, harness, workflow or ledger change was made in this Review, and no Directional binary was executed. Ledger **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** — unchanged. No promotion, no stable event, no new recurrence, no 497 run, no gate credit. **No runtime outcome has been observed and none is claimed** (LESSON 160: a compile is not a restoration).

#### RA-60.1 — Compile accepted; the turn boundary held

Eight-target GMP/GMPXX compile **GREEN**: run [38720128740](https://github.com/akashskypatel/Directional/actions/runs/38720128740) on exact semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, result artifact `11964478813` (outer SHA-256 `0e1e87a48ef090588c8675bd87bc8c7560a1ade5dbe44cac391c78e0cbe21ae5`), log artifact `11964676618`. 28/28 packaged checksums, eight target names, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, real `gmpxx`/`gmp` linkage, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No test binary, benchmark, artifact-only harness or 497.

Independently confirmed the change surface: exactly **two** files — `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. The test change is **purely additive** (zero deleted lines). `tests/SurfaceCellTransitionQuotientTests.cpp`, `tests/SurfaceCellREPackageTests.cpp`, `cmake/`, `benchmarks/` and every selector file are **untouched**. No fixture geometry was changed, which the retained plan and RA-59.12 both required.

#### RA-60.2 — The implementation is faithful to the selected model, and strengthens it

Checked against each RA-59.9 requirement at the new site (`src/geometry/SurfaceCellTracing.cpp:19221-19241`):

| RA-59.9 requirement | implementation | verdict |
|---|---|---|
| typed carrier key | `find_carrier(edge)` → `oriented_carrier(*carrier, …)`; `edge` passed to the parameter check | ✔ |
| both incident source faces, **across-rail** per RA-57.5 | `firstAttachment`/`secondAttachment` are `topology_for_row(source_face_id(fromPoint.face))` / `(toPoint.face)` (`:19130-19138`); `oriented_carrier` requires the carrier record's faces to equal that pair | ✔ |
| canonical exact intrinsic parameter on the **same** carrier edge, shared by both points | `same_interior_carrier_point(fromPoint, toPoint, faces, edge)` | ✔ |
| equivalent opposite-side barycentric representatives, **no** epsilon merging | `FieldExactRational::from_double_exact`, exact `==`, no tolerance anywhere in the new helpers | ✔ |
| source component/sheet agreement | carried by the topology-region keys and tied to the published carrier record by `oriented_carrier` | ✔ |
| directed A3 transport between the two incident faces | `*oriented` carries `firstToSecond`, verified when the transition record was built (`:18963-18975`, `reverse->transport == forward->transport.inverse()`) | ✔ |

`interior_carrier_parameter` (`:61-89`) is sound by construction: it locates the edge's two corners in the published chart, requires the third barycentric to be **exactly** `0.0`, converts both weights exactly, and admits only `second ∈ (0,1)` **strictly** with `first + second == 1` exactly. Three properties follow and matter:

- **A forged terminal cannot be laundered through the interior branch.** Strict interiority excludes one-hot corners, so a point at an exact corner returns `nullopt`.
- **The parameter is canonically oriented.** It returns the weight at `edge.second()`, and the edge key is canonical, so comparing the two charts compares the weight at the *same* vertex. An along-rail parameterization would have had an orientation bug here; this does not.
- **A front ending exactly at the rail's interior junction vertex 4 is rejected, not absorbed.** At vertex 4 the weight is exactly `1`, failing `second < one`. The junction case therefore remains outside this repair, consistent with RA-41's clauses standing UNEXERCISED. This was not required and is correct.

Beyond the specification, the new branch also requires **`sharedBoundaryInterval` reciprocity** — equal `span` with cross-matched `firstOrdinal`/`secondOrdinal` — which ties the interior certificate to a published shared boundary interval rather than to any two coincident points. **Recorded as a strengthening of RA-59.9, adopted.** And no parallel certificate model was introduced: absence of a terminal is expressed through the existing `std::optional` member, not a new type.

#### RA-60.3 — Every prohibited invariant verified intact

- `exact_corner` and `no-exact-terminal-corner` (`:19214-19241`): the terminal loop and the exactness predicate are **unchanged**, and the new code is reachable **only** when `!terminalVertex`. Fail-closed for any endpoint claiming terminal status.
- The closed-chain branch (`:19140-19147`, `missing-terminal-or-closed-rail-provenance`): **untouched**, so the RA-58.5 torus PASS is preserved.
- **At least one certified terminal endpoint on an open rail: preserved.** At `:8572-8576`, `!bothTerminal` requires `singleTerminalValid(firstVertex, …) || singleTerminalValid(lastVertex, …)`. If **both** endpoints are interior, both disjuncts are false and the certificate is rejected. A contact-less open rail remains impossible.
- `tests/SurfaceCellsPhase10Tests.cpp:7205` (`endpoints[0].terminalVertex.has_value()`, cited as `:7157` in RA-59.9 and shifted by this turn’s additive insertion) is **untouched** and still satisfiable: the half-terminal certificate puts the terminal at `endpoints[0]`.
- Ordinal **405**'s `endpoint-0` branch is untouched; it remains a separate A2b provenance defect.
- No `Produced` precondition was weakened anywhere.

#### RA-60.4 — Step 0 CLEARS, but this Review derived it; the turn did not evidence it

The record states *"the required front-publisher falsifier was checked against the exact source before editing, as recorded in the continuation artifact."* **It states no finding and cites no anchor**, and the artifact is not in the repository. The only visible trace in the source is a **rewritten contract comment** at `:18975-18978`, where *"Publish one terminal crossing per spatial endpoint"* became *"Publish one cross-rail certificate per spatial endpoint … A field-determined front end may be inside a source carrier."* A claim of having checked is not a finding (LESSON 171), and amending the statement of a contract is not a derivation of it.

Derived here instead, from the publisher. Front extent is produced in `assign_open_front_boundary_authority` (`:12481`): runs are accumulated from **traced segment barycentrics** through `canonical_retained_edge_parameter` (`:12509-12530`), and a run is published when `lastTopology != topology` (`:12574-12579`) — i.e. **cut at source-edge topology changes, never at rail terminals**. The extent is therefore field-determined, and a front end interior to a carrier edge is a legitimate product of the publisher's contract. **The falsifier CLEARS and RA-59.9 stands.**

**The amended comment is a consequence of the RA-59.9 selection, not evidence for it.** It must never be cited as authority for the model; doing so would be circular and is an `RP-01` shape. The derivation above is the authority.

#### RA-60.5 — DEFECT: the new rejection is diagnostically indistinguishable from the old one

Both the unchanged terminal loop and the new interior branch end at the **same** `reject("no-exact-terminal-corner")` (`:19241`). If the next measurement reports that predicate again, nothing in the diagnostic distinguishes *"the interior branch was never reached"* from *"the interior branch refused"* — and those have opposite consequences for the model. This is the RA-57.12 / RA-59.4 failure mode designed into the instrument before the instrument runs.

**Required fix, if and only if branch (C) of RA-60.10 occurs:** a distinct predicate string for the interior refusal — e.g. `no-interior-carrier-agreement` — emitted on the existing diagnostic-only path, after rejection has already been decided, changing no decision. It is **not** authorized pre-emptively: on the RA-60.10 prediction, branch (C) is the unlikely one, and inserting a rung on speculation is the RA-54.7 defect. This is a conditional obligation, pre-registered so that a (C) result is not misread.

#### RA-60.6 — The per-certificate terminal-coverage invariant was dropped, necessarily, with no aggregate replacement

The original check at `:8572` required `forward || reverse`, where (`:8544-8553`)

```cpp
const bool forward = touches(certificate.endpoints[0].terminalCarrier.edge, contact->second.endpoints[0]) &&
                    touches(certificate.endpoints[1].terminalCarrier.edge, contact->second.endpoints[1]);
```

i.e. **each accepted certificate's two endpoint carriers had to touch both of the rail's published terminals** — a whole-rail span condition. In the measured topology `routeLength=1`, so both endpoints share carrier `(1,4)`, which touches terminal **1** but not **7**; therefore `forward == reverse == false` and the original code rejected unconditionally. The repair **had** to drop that condition for the interior case; it is not gratuitous. But nothing replaces it, per rail or in aggregate, and no downstream aggregate coverage check exists.

**Consequence, stated as a prediction and not a speculation:** in these fixtures no front crosses `(4,7)`, so **terminal 7 can never be attached by any certificate.** The repair therefore necessarily produces open rails with one published terminal left unattached. Whether A5/A6/A7 tolerate that is unknown and unmeasured; it is the most likely place for the failure to reappear downstream. Pre-registered in RA-60.10 as branch (B).

#### RA-60.7 — PRINCIPAL DESIGN FINDING: the interior endpoint collapses onto the closed-chain encoding

The new interior certificate is constructed as `{firstAttachment, secondAttachment, *oriented, std::nullopt, {}}` (`:19239-19241`). The closed-chain / no-contact branch of the checked factory requires precisely that shape (`:8729-8733`):

```cpp
} else if (endpoint.terminalVertex || !endpoint.contactPaths[0].empty() ||
           !endpoint.contactPaths[1].empty() ||
           carrier.firstFace != endpoint.firstAttachment ||
           carrier.secondFace != endpoint.secondAttachment) { … reject }
```

**An interior open-rail endpoint and a closed-chain endpoint are now structurally identical** — same `terminalVertex == nullopt`, same empty `contactPaths`, same carrier-equals-attachments. The only separator is which branch of `if (contact != hardRailTerminalContacts.end())` the **rail** falls into, which is a property of the rail, not of the certificate. The inference *"no terminal vertex ⇒ closed chain"*, previously sound, is now **false**.

Severity, stated honestly: **latent, not active.** The only consumer outside this file is the structural fingerprint `hash_trace_network` (`src/pipeline/RemeshPipeline.cpp:2123-2124`), which hashes `terminalVertex.has_value() ? index : -1` — so both states alias to `-1`, but a fingerprint is not an authority and the hash carries the attachments and carrier separately. Nothing infers closed-chain-ness semantically today. It is nevertheless an `RP-01 AUTHORITY_DOMAIN_CONFLATION` shape: two distinct topologies sharing one encoding, waiting for the first consumer that reads it. **Required before anything reads it semantically:** a **positive discriminator** on the endpoint — the attested interior parameter itself, or an explicit kind tag — so that *"no terminal"* and *"interior carrier attested at parameter p"* are different states rather than the same one. Recorded, **not** authorized in a measurement rung.

#### RA-60.8 — DEFECT: a comment asserts an invariant its own site does not enforce

At `:8662-8675` the new branch is introduced by *"Open-rail interior carrier: the opposite endpoint must already carry an independently checked whole-rail terminal witness."* The code at that site checks contact-path emptiness, carrier/attachment equality and interior-point agreement — **it never inspects the opposite endpoint.** The invariant is real and is enforced, but at `:8572-8576`. A reader auditing `:8662` will believe a guard exists there that does not. Fix the comment to point at the enforcing site, or move the check.

#### RA-60.9 — Test coverage: the first positive witness in this family, and four untested negatives

`SurfaceCellAuthorityContractCutover.ProducedOpenRailInteriorEndpointPreservesExactTerminalGuard` (`tests/SurfaceCellsPhase10Tests.cpp:7148-7191`) is **nonvacuous and significant**: its first assertion demands real production from `build_rectangular_hard_rail_phase_front()`, and it then requires the producer to witness **one terminal and one interior** endpoint. Per RA-59.8 this is the **first positive witness of the acceptance half ever authored** — subject to actually passing at runtime, which is unmeasured.

Its negative half forges a terminal vertex onto the interior endpoint and requires `InvalidSourceAuthority`. That rejection is real, but it is attributable to the **retained** `(!forward && !reverse)` condition rather than to the new predicate, so the test's name over-claims: it guards the retained span condition, not corner exactness — which does not live in the factory at all. Substance stands; the name misleads.

Four negatives on the new predicate itself are **untested**, although the code rejects all four:

1. the two paired points at **different** interior parameters (`same_interior_carrier_point`);
2. an interior endpoint with **non-empty** `contactPaths` (`:8662-8675`);
3. an interior endpoint whose carrier faces disagree with its attachments (`:8662-8675`);
4. **both** endpoints interior — the contact-less-open-rail forgery the retained plan explicitly prohibits (`:8553`).

(4) is the one that matters most and is the cheapest to author. Required in the next Code + Build that touches this area; **not** authorized inside a measurement rung.

#### RA-60.10 — PRE-REGISTERED PREDICTION AND DECISION RULE for the next Test + Benchmark

Registered **before** the measurement so the result cannot be reinterpreted after the fact. The measured probes were `a2bProbeFrom=0:0x0p+0,0x1.8p-1,0x1p-2` and `a2bProbeTo=3:0x1.8p-1,0x0p+0,0x1p-2` — `0.75` and `0.25`, both exactly representable, the third weight exactly `0.0`, and `0.75 + 0.25 == 1.0` exactly in **both** charts. Therefore `interior_carrier_parameter` succeeds on both points and yields the same exact rational, `same_interior_carrier_point` returns **true**, `singleTerminalValid(terminal 1, carrier (1,4))` holds, and `:8662`'s attachment equality holds by construction of `oriented_carrier`.

**Prediction: the 38 `endpoint-1` identities clear `:19241` and A4 accepts.** The three admissible outcomes and their binding interpretations:

- **(A) `Produced`, and the network-bound consumer is reached.** The repair works and `RP-02` becomes measurable for the first time. Its positive **and** negative halves must both run before any claim about `RP-02`.
- **(B) A new first failure strictly downstream — A5/A6/A7, most likely terminal coverage.** This **does NOT falsify RA-59.9.** It confirms RA-60.6 and locates the next rung. Record it; do not chase it in the same turn (RA-54.7), and do not fold it into the hard-rail carrier.
- **(C) The same `no-exact-terminal-corner` at `:19241`.** **Ambiguous**, because of RA-60.5. A (C) result mandates the diagnostic-only fix of RA-60.5 before any re-measurement, and only the distinguished predicate can separate *branch not reached* from *interior agreement refused* — the one-ULP hazard at the RA-60.11 seam. A (C) result is **not** grounds to weaken any predicate.

A persisting RED is therefore interpretable only through this table. **"Still RED" is not evidence against the model**, and nothing in branches (B) or (C) authorizes relaxing `exact_corner`, `no-exact-terminal-corner`, the closed-chain branch, or any `Produced` precondition.

#### RA-60.11 — Residual: two arithmetic régimes meet at the same endpoint

The publisher admits run endpoints through `canonical_retained_edge_parameter` with `constexpr double tolerance = 1.0e-9`, an interval test on `[−tolerance, 1 + tolerance]` and `std::clamp(parameter, 0.0, 1.0)` (`:12509-12530`), and stitches runs under `std::abs(*runEndParameter - *startParameter) > tolerance` (`:12655`). The new certificate demands **exact** rational equality and **strict** interiority. Soundness is preserved — the certificate is exact, epsilon-free and fail-closed, so no false acceptance can pass — but the pairing of a tolerant producer with an exact consumer is exactly where a one-ULP cross-chart disagreement would surface, as a refusal rather than a false accept. Recorded as a bounded residual, with its observable consequence pre-registered as RA-60.10 branch (C). No epsilon may be introduced into the certificate to close it.

#### RA-60.12 — Correction: the handoff reinstated a retired stop rule

The turn's handoff section directs the next TB to run *"remaining six supplemental identities **only until first RED**."* That is the pre-RA-57 rule, retired by RA-57.8 and RA-58: an early stop is what left the breadth turn unreported, and a measurement rung must execute **all** its identities regardless of RED, taking its verdict from `executed`/`missing`/`postflight` only. **Corrected:** no first-RED stop in any measurement rung. Given the RA-60.10 prediction, a first-RED stop would also discard almost everything the run could establish.

#### Obligations carried, not retired

`RP-01` (and RA-60.7 is a new instance of its shape, recorded), `RP-02` (**open**; localized by RA-59.8 and now potentially reachable for the first time), `RP-03`; the RA-58.7 A5/A6/A7 loci and `R4-OHF-02` (recorded, guards retained, **no probe**); the two RA-57.9 guards and RA-41's junction/sector clauses (frozen **UNEXERCISED**, construction recipe known per RA-59.8, **not retired**, and explicitly outside this repair per RA-60.2); ordinal **405**'s separate A2b provenance defect; the 34 Phase10 / seven DCEL / six CP3 identities; the CP2 restorations outside the 37; organic D1/D2/D3/D5 and A6/A7 witnesses; the odd-τ witness; the two `SurfaceCellTracingPhase14` identities requiring a separately packaged historical executable (`cmake/DirectionalTests.cmake:554-572`), **not** to be bundled into a measurement rung. `R4-VIN-01` applies with force: the repaired package is a **new** semantic source (`570c5173…`), so every prior measurement is a baseline, never a comparand.

#### Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | All frozen selectors untouched and matching; no selector added, changed or accepted |
| Decisive claims independently re-derived | Change surface confirmed as two files with zero test deletions; all six RA-59.9 requirements checked at the new site; every prohibited invariant checked at its own anchor; the Step 0 falsifier derived from the publisher at `:12481`/`:12509-12530`/`:12574-12579`; the closed-chain shape at `:8729-8733` compared field-by-field against the new certificate; the sole downstream `terminalVertex` consumer located |
| Non-vacuity checked | The new test demands real production before asserting; its negative half traced to the condition that actually rejects (the retained span check, not the new predicate); four negatives on the new predicate found untested |
| Prior obligations discharged / carried | RA-59.9 implemented and accepted; Step 0 cleared; all other obligations carried above; nothing retired |
| Stable accounting | 66/17/49, debt 1, CP2 491/491, R3 403/497, frozen selector 497; no promotion, no stable event, no recurrence |
| New candidates / obligations recorded | RA-60.5 conditional diagnostic fix; RA-60.6 terminal-coverage gap; RA-60.7 encoding collapse needing a positive discriminator; RA-60.8 comment/code mismatch; RA-60.9 four untested negatives; RA-60.11 arithmetic-régime seam |
| ORIENTATION currency line | `M6-CP3-TB1-R4-REPAIR-REV`, 2026-10-15 |
| CHANGELOG | 2026-10-15 root entry; root `CHANGELOG.md` is canonical |
| LESSONS | LESSON 160 cited against the compile-green status; 171 cited against the unevidenced falsifier claim; RA-56.8, RA-57.12, RA-58.8 and RA-59.4 in force |
| Successor frozen | `M6-CP3-TB1-R4-INTERIOR-WITNESS` (artifact-only Test + Benchmark on the **new** package), governed by the RA-60.10 pre-registration |
| Turn boundary held | Review only: no source, test, selector, harness, workflow, binary, benchmark or ledger change; no Directional binary executed |
| `review_check.py boundary` | Run after document commit; result recorded with the commit |
| `STATUS` lifecycle maintained | Six fields set, `COMPLETE`, named `Successor` — replacing the `Successor: UNKNOWN` the repair turn left |

## `Architecture_M6_CP3_R4_Interior_Witness_Measurement_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Interior_Witness_Measurement_Review_Decision.md`; moved verbatim.

### RA-61 — `M6-CP3-TB1-R4-INTERIOR-WITNESS` measurement review decision (2026-10-15)

Reviewer turn `M6-CP3-TB1-R4-INTERIOR-WITNESS-REV`. Adjudicates the interior-witness
artifact-only measurement, repairs a destroyed append-only ledger, and
**falsifies the reviewer's own RA-60.10 prediction and RA-59.9's mechanism
breadth from exact arithmetic on the measured bits**.

Candidate/non-stable throughout. No promotion, no stable event, no recurrence,
no frozen-497 execution, no gate credit. No source, test, selector, binary,
harness, workflow or benchmark change in this Review.

---

#### RA-61.1 — The measurement is ACCEPTED as execution evidence

Run [38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279),
result artifact `11967601999` (ZIP SHA-256
`8b52373eebc7bda574f1fed2914dec4577ff70c670396f2ea3b19383d0fd25f1`), semantic
source `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, harness
`.agents/Directional/tools/m6_cp3_r4_interior_witness_harness.sh` SHA-256
`13a7e73ea17bff8c7b6a14bb2e3bc35712e05b8914a1546668108354fdb02e21`.
`execution-boundary.txt`: `planned=45 executed=45 red=45 missing=0
postflight=true exit=0 compile=false relink=false benchmarks=false
selector497=false`. `immutability.txt`: `package=true source=true
execution_view=true selector=true`.

The instrument is compliant with the shape RA-59.2 and RA-57.8 require: the
39-identity inventory is SHA-256-pinned (`de05a7bd…`) and `mapfile`-read, a
duplicate-identity assertion is present (`:51`), non-selection is recorded and
`continue`d rather than silently passed (`:72-74`, `:110-111`), the breadth
assertion is on the counters alone (`:128` `executed == 45 && missing == 0 &&
postflight == true`), and package/source/execution-view immutability is
`cmp`-verified before and after (`:121-124`).

Three disciplines were honored without prompting and are recorded as such:
**RA-60.12 was obeyed** — all 45 identities ran after the first RED, and the
verdict is taken from the counters, not the RED count; **no predicate was
relaxed and no epsilon introduced** to manufacture green; and the turn
**refused to invent the successor identifier**, leaving it to repository
authority rather than fabricating one. The report also correctly keeps ordinal
**405** distinct and correctly declines to call the result a restoration.

---

#### RA-61.2 — REVIEW_BLOCKER, now repaired: the append-only ledger was destroyed

Commit `b90c0f84e` reduced `.agents/Directional/Regression_Root_Cause_Tracker.md`
from **12,949 lines to 6**, deleting **12,944 lines** of root-cause history —
the full stable ledger narrative behind 66 events / 17 categories / 49
recurrences. The standing NEXT_TURN prohibited exactly this ("tracker
append-only"). The 5-line section prepended in its place is legitimate content;
the deletion beneath it is not.

**Repaired in this turn.** The ledger is restored from the last good blob
`cef55bdd0`, with the measurement section retained on top and the RA-61 section
prepended above it. Nothing is discarded in either direction.

**High-water floor, recorded as data so it is auditable without the tool:** the
tracker must never fall below **12,949 lines**, **13 durable-marker occurrences**, or
**648 `## ` sections**. Any future state below any of these three is a
destruction, whatever a gate reports.

This is the **third** occurrence of durable-ledger destruction in this project,
not a novel defect: `.agents/Directional/tools/review_check.py:52-53` records
whole-file overwrites at `ce9bf3cb` / `0043dd4c` on 2026-09-22, restored at
`M5-CP3-TB2-REV`. A failure mode that has now recurred three times is a
property of the workflow, not of one agent.

---

#### RA-61.3 — The reviewer was running the wrong gate; the adequate gate existed

`review_check.py boundary` reported **ALL CHECKS PASSED** over the 12,944-line
deletion, printing `durable markers preserved in
Regression_Root_Cause_Tracker.md 0 -> 0`.

The mechanism, read from `:184-196`: `live` is the marker count in the working
tree and `was` is the count in **`HEAD:<rel>`**, and the test is `live >= was`.
It is a within-turn ratchet against the reviewer's own uncommitted edits. Once a
truncation is committed, `HEAD` *is* the truncated file, so the check compares
`0` to `0` and passes — permanently. **A check whose comparand is its own
current state is not a check.**

The tool says so itself at `:48`: *"Protects only against the reviewer's own
uncommitted edits; see `ledgers` for committed overwrites."* The `ledgers`
subcommand exists and names the damage exactly:

```
review_check.py ledgers --base cef55bdd0
  [FAIL] no >10% shrink of .agents/Directional/Regression_Root_Cause_Tracker.md b90c0f84 12949->6
```

So this is a **reviewer defect, not a tooling gap**. The instrument was
adequate, documented its own limitation in a comment, and pointed at its
companion; the standing per-turn procedure invoked only `boundary`.

**Standing rule, in force from this turn:** every Review turn runs **both**
`review_check.py boundary` **and** `review_check.py ledgers --base <prior
review commit>`. `boundary` alone may never again be reported as the gate.

**Both of these lessons were already written down, and both recurred anyway.**
`ORIENTATION.md:1719` records `LESSONS.md` **176** — *"An append-only durable
ledger was replaced by a whole-file write, and nothing noticed for ~20 turns"* —
for `ce9bf3cb`, which cut the same file from 9,837 lines to 21.
`ORIENTATION.md:1799` records *"A guard that counts markers does not protect
content"*, naming the `1 -> 1` pass mode exactly. So RA-61.2 and RA-61.3 are not
discoveries; they are **recurrences of documented lessons**, and the prose
remedy has now failed twice.

The conclusion follows directly: **a written lesson is not a control.** The
floor in RA-61.2 is therefore recorded as three countable numbers rather than as
an instruction to be careful, and the mechanical fix below is mandatory rather
than advisory — a monotone high-water floor that cannot decrease, instead of a
self-relative comparison. Until that fix lands, the floor is verified by
counting, by whoever closes a turn.

---

#### RA-61.4 — RA-60.10's prediction is FALSIFIED; its decision rule held

Pre-registered: the 38 `endpoint-1` identities **clear** `:19241` and A4
accepts. Observed: **none cleared.** 44 of 45 report
`a2bProbeFailure=no-exact-terminal-corner`; ordinal 405 reports
`missing-terminal-or-closed-rail-provenance`. Outcome is **branch (C)**.
Branch (B) — a new failure strictly downstream — was not observed.

The premise was wrong, and the error is the reviewer's: RA-60.10 asserted the
probes were `0x1.8p-1` and `0x1p-2` (0.75 / 0.25), *"exactly representable …
sum exactly `1.0` in both charts."* The fixture's `lengthRatio = 0.2`
(`tests/SurfaceCellsPhase10Tests.cpp:6312`, inside the fixture builder at `:6298-6323`), and the measured probes are
0.8 / ≈0.2 — **neither binary-exact**.

The distinction that matters: the **prediction** failed, the **decision rule**
worked. Branch (C) was anticipated, was classified correctly by the measuring
turn, and mandated precisely the response taken — diagnostic separation, no
relaxation. A pre-registration earns its keep by being falsifiable; this one was
falsified cleanly and cheaply, which is the intended outcome of registering it
rather than reasoning after the fact.

---

#### RA-61.5 — LESSON: pre-register the *provenance* of the expected value, not only the value

Fourth of one family — RA-57.3 (a non-discriminating control), RA-58.8 (an
instrument conditioned on the verdict), RA-59.4 (*a measured value without its
expected value is not a discriminator*), and now: **an expected value whose
provenance is unstated is not a prediction.** The deciding fact — `lengthRatio
= 0.2`, hence weights 0.8 and 0.2, hence no binary-exact closure — sat in a file
RA-59 had already cited by anchor, and needed no run at all.

---

#### RA-61.6 — Principal finding: the acceptance path is unsatisfiable, and for `fromPoint` this is assumption-free

The measured paired probes in 23 identities, from the published source-face
barycentrics (`src/geometry/SurfaceCellTracing.cpp:19389-19397`, lossless
hexfloat of the stored doubles):

```
0: 0x0p+0,              0x1.999999999999ap-1, 0x1.9999999999999p-3
3: 0x1.999999999999ap-1, 0x0p+0,              0x1.9999999999998p-3
```

Exact rational arithmetic on those bits:

| quantity | exact result |
|---|---|
| face 0, nonzero pair sum | `1 + 2^-55` — **not** 1 |
| face 3, nonzero pair sum | **exactly 1** |
| cross-chart ≈0.2 weights | differ by `2^-55` (1 ULP and 2 ULP below nearest-0.2) |

`interior_carrier_parameter` (`:64-89`) requires the third weight exactly `0.0`,
`second` strictly in `(0,1)`, and `first + second == one` over
`FieldExactRational::from_double_exact`. For **face 0 this returns `nullopt`
under every possible corner assignment**:

- zero at `other` → `first + second = 1 + 2^-55 ≠ 1`;
- zero at `low` → `first = 0`, so closure requires `second == 1`, but `second`
  is 0.8 or ≈0.2;
- zero at `high` → `second = 0`, failing `second > zero`.

Therefore `same_interior_carrier_point` is false at the **first** chart in all
23 cases, and cross-chart equality is never consulted. Face 3, by contrast, *can*
yield a value. The two charts disagree not about the parameter's value but about
whether the point is **admissible at all**.

The measuring turn named only the cross-chart one-ULP difference and framed it
as a deviation from the reviewer's assumed probe form. The single-chart closure
failure — the decisive one, and the first to fire — went unnamed, though both
facts are in the bytes the report itself quoted.

---

#### RA-61.7 — The defect is the reviewer's specification, and RA-60 verified the wrong property

`first + second == one` over a traced barycentric demands a closure property the
producer never promises and double arithmetic cannot deliver: an exact
mathematical edge point `(0, 1-t, t)` has each component independently rounded,
and `fl(1-t) + fl(t) == 1` is a coincidence, not an invariant.
`from_double_exact` is exact about the **double** — precisely the wrong object.
It faithfully preserves a rounding error and then tests it for equality.

RA-60.2 praised the absence of any epsilon as a virtue and verified the
implementation's **faithfulness** to RA-59.9. It never asked whether the
predicate could be **true** for a legitimate traced point. It cannot, except by
luck, and the acceptance branch is therefore **effectively unreachable** — which
makes RA-60's "ACCEPTED as faithful" true but hollow: faithful to a
specification that was itself unsatisfiable. The implementation is not at fault
and is not being re-judged.

**RULE: verify a predicate for satisfiability, not only for faithfulness.** A
specification can be implemented perfectly and still be dead on arrival.
"Fail-closed" is a virtue only when the closed state is reachable by legitimate
input. This was derivable at RA-59 time from four lines of header, with no run.

---

#### RA-61.8 — An exact witness already exists, and the agent had already wired it

`SurfaceTracePoint` (`include/directional/geometry/SurfaceCellTracing.h:90-93`)
carries **only** `int face` and `Eigen::RowVector3d barycentric` — three
doubles. There is **no exact parameter to read**, so RA-59.9's "exact shared
intrinsic parameter" cannot be obtained from the trace point by any
implementation. The information is destroyed at tracing time.

But `SurfaceSharedBoundaryInterval` (`:1418-1428`) carries
`authority::FieldExactRational firstOrdinal` and `secondOrdinal` — **exact
rationals, not doubles** — and the repair **already** requires equal `span`,
reciprocal ordinals (`firstOrdinal == other.secondOrdinal` and conversely) and
equal `railId` (`:19231-19238`).

**That is the exact shared-point witness RA-59.9 asked for.** The unrequested
check RA-60.2 merely "adopted as a strengthening" is in fact the load-bearing
one, while the part the reviewer specified is the dead one. The implementing
agent's instinct was better than the specification it was given, and that is
recorded as such rather than absorbed silently.

---

#### RA-61.9 — Candidate remedy, explicitly NOT yet authorized (RA-54.7)

Decompose the predicate rather than loosen it:

1. **Keep** strict-interiority *classification* per chart — "this endpoint is
   not a corner." One-hot versus ≈0.2 is not a close call and is robust to ULP
   error, and this is what blocks laundering a forged terminal (RA-60.2).
2. **Drop** the `first + second == one` admission gate — a representation
   artifact, not a soundness property (RA-61.7).
3. **Drop** cross-chart double parameter equality.
4. **Rest point identity** on the already-present exact-rational
   `sharedBoundaryInterval` reciprocity.

This introduces **no epsilon**: RA-60.11's prohibition is honored in letter and
in spirit, and the identity claim *moves onto* exact rationals instead of being
weakened. The resulting predicate is smaller **and** more exact than today's.

Two falsifiers must be measured before any of this is authorized, and neither is
settled here: **(i)** is `sharedBoundaryInterval` even **set** for these
fixtures — it is `std::optional`, and `:1423-1425` states that
physical-boundary producers may leave it unset; **(ii)** do equal span plus
reciprocal ordinals pin the **point** rather than merely the interval, to be
derived from the producer's own code and not inferred from the type. **No repair
is authorized until the diagnostic measurement names the deciding conjunct.**

---

#### RA-61.10 — RA-59.9's single-mechanism claim is PARTIALLY FALSIFIED: ≥2 shapes, 23 + 21

Twenty-one of the 44 probe **one-hot**: `0:0,0,1` against `7:1,0,0`. That is a
**mesh vertex**, not an interior point. For these, `interior_carrier_parameter`
returns `nullopt` correctly (strict interiority, as RA-60.2 established), and
the terminal loop also refused — so `terminalVertex` is absent **although the
endpoint is an exact corner**.

The interior model does not apply to these 21 at all. RA-59.9 claimed one
mechanism re-explaining all 39 identities; there are at least two, and the
repair addressed only one of them. The 21 are a **separate, undiagnosed family**
that RA-60 never covered and that no part of the repair could have fixed.

This simultaneously **corroborates** RA-59.11 — which bounded independent loci
at **≤22, not 39**, against the report's 39-corroboration framing — since the
realized 23/21 split straddles that bound, and **refutes** the breadth of
RA-59.9's mechanism claim. The bound was right; the mechanism was over-general.

---

#### RA-61.11 — The deciding conjunct for the 21 is already captured and was not reported

The terminal loop (`:19213-19220`) is a **three-way conjunction** requiring the
**same** vertex to satisfy all of:

```cpp
(edge.first() == vertex || edge.second() == vertex)
&& exact_corner(fromPoint, vertex)
&& exact_corner(toPoint, vertex)
```

So a one-hot endpoint still fails if the two charts name **different** vertices,
or if the vertex is **not on the carrier edge**, or if it is **not a published
rail terminal**. These are three distinct defects with three distinct repairs.

The probe block already emits exactly the discriminator, per published terminal
(`:19409-19416`): `corner[v]=<from>,<to>` and `railEnd[v]=<bool>`, alongside
`a2bProbeCarrierPresent`, `a2bProbeA3Present`, `a2bProbeContactPresent` and
`a2bProbeClosedChainPresent`. The report quoted only `a2bProbeFrom/To`.

**No re-measurement is required.** The evidence is already inside immutable
artifact `11967601999`. `RP-03` applies at instrument level: name the deciding
conjunct, never the verdict.

---

#### RA-61.12 — Accounting, carried obligations, and the next rungs

Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, CP2
**491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses),
frozen selector **30 + 12 + 449 + 6 = 497** — all unchanged. All 39 census
identities were already RED under the prior semantic source and the six
supplementals have no accepted-GREEN baseline, so **no accepted-green loss and
no ledger credit** arises. PR #8 draft/open. The ledger destruction in RA-61.2
is an **integrity** recurrence and does **not** increment the regression
recurrence counter.

`R4-VIN-01` continues to apply: `570c5173…` is a new semantic source, so every
prior measurement is a baseline, never a comparand.

Carried without probe: `RP-01`; `RP-02` (open, unreached — neither the
network-bound consumer nor its tamper half was executed); `RP-03`; RA-60.5
(**now triggered** by branch (C)); RA-60.6 terminal-coverage with no aggregate
replacement; RA-60.7 encoding collapse needing a positive discriminator;
RA-60.8 comment mismatch; RA-60.9's four untested negatives; the RA-58.7
A5/A6/A7 loci and `R4-OHF-02`; the two RA-57.9 guards and RA-41's
junction/sector clauses (frozen UNEXERCISED, recipe known, not retired); ordinal
**405**'s separate A2b provenance defect; 34 Phase10 / seven DCEL / six CP3
identities; CP2 restorations outside the 37; organic D1/D2/D3/D5 and A6/A7
witnesses; the odd-τ witness; the two `SurfaceCellTracingPhase14` identities
needing a separately packaged historical executable
(`cmake/DirectionalTests.cmake:554-572`), not to be bundled into a measurement
rung.

**Next rung — `M6-CP3-TB2-R4-CONJUNCT-EXTRACT`,** artifact-only extraction from
the **existing** immutable artifact `11967601999`. No dispatch, no compile, no
new run, no code. Partition the 44 into the 23 interior-shape and 21 one-hot
families **from bytes**, and for the 21 name which of the three RA-61.11
terminal conjuncts fails.

**Rung after that — `M6-CP3-CB2-R4-PREDICATE-SEPARATION`,** diagnostic-only,
**now authorized** because branch (C) occurred: give each rejection cause a
distinct string so a repeat is interpretable, strictly decision-neutral, and
emit `sharedBoundaryInterval` presence and ordinals so RA-61.9 falsifier (i)
becomes measurable. Acceptance behaviour must not change by one identity.

The RA-61.9 remedy is **not** authorized in either rung.

## `Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Oriented_Terminal_Side_Authority_Review_Decision.md`; moved verbatim.

### M6-CP3-R4 — oriented terminal source-face germ and front-filled-side ownership: REVIEW DECISION

**Adjudicates:** `Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`
(and the earlier `Architecture_M6_CP3_R4_RA432_Terminal_Attachment_Source_Audit_20261012.md` it supersedes).

**Disposition: the REVIEW_BLOCKER is DISSOLVED. RA-43.2 is DISCHARGED. The requested producer receipt is
REFUSED as a namespace category error.** No runtime credit. Ledger **66 / 17 / 49**, M6 debt **1**, unchanged.
Selector **497 = 30 + 12 + 449 + 6** untouched; CP2 **491/491** accepted; R3 **403/497** rejected with 94 RED
and 88 accepted CP2 losses.

---

#### 1. The request answers a question RA-43.2 does not ask

RA-43.2 (`Architecture_M6_Frozen_Definitions.md:440-447`) has exactly two operative sentences. It names the
owner of `SurfaceCellRail::sourceVertices` (the pipeline curve-network producer), relocates RA-42.1 so that
**the typed terminal contact is a required input bound at the A4 factory boundary**, and closes with the
scope limit, quoted verbatim:

> the endpoint certificate still stops reading `from.face`/`to.face` **for contact purposes**.

"For contact purposes" is the clause's own boundary. The *contact* is the typed terminal **vertex pair**. The
request's subject — an *oriented source-face germ pair* plus a *front-filled-side owner* — appears nowhere in
RA-43.2, nowhere in RA-43.1/.3/.4/.6/.7, and nowhere in RA-44, RA-45, RA-46, RA-47, RA-48 or RA-49. RA-45.7
states the residue precisely: "the endpoint-certificate **consumption** (RA-43.2) … remain[s] open." Not a
new publisher. A consumption.

**That consumption has landed.** `src/geometry/SurfaceCellTracing.cpp:19013-19014` looks the contact up by
`*first.railId`; `:19064-19069` iterates `contact->second.endpoints` and selects the terminal vertex from the
producer's typed pair; `from.face`/`to.face` no longer reach any contact decision. Absence is fail-closed at
`:19038-19043` (`missing-terminal-or-closed-rail-provenance`, with a typed closed chain as the only
contact-free route) and ambiguity at `:19068`. The factory re-validates the same contact at `:8308-8325`
(component against `SourceTopologyRegions`) and `:8474-8497` (endpoints against the carrier's first/last
vertex). RA-43.2 is **DISCHARGED** by these bytes.

The request therefore inflated a frozen clause's scope, declared the inflated version unsatisfiable, and
stopped the turn on it. The scope inflation is the blocker; removing it removes the blocker.

#### 2. The requested receipt cannot exist, and the reason is RA-43.3

The request asks for a source-authored receipt binding
`(rail, terminal, source interval, oriented source-face germ, **filled-side owner**)`.

`filledCell` is an `authority::CellId` and `filledSide` is "counter-clockwise side of `filledCell`"
(`include/directional/geometry/SurfaceCellTracing.h:1555-1557`), a side index in `[0,4)` of an **A4 quad
cell**. Quad cells do not exist in the source domain; they are minted by A4's own tracing. A source-domain
producer asked to attest a `CellId` must therefore **invent** the right-hand side of the binding — which is
the prohibition the whole publish/don't-invent family exists to enforce, and it is the **fifth namespace**
alongside RA-43.3's four. The request half-sees this when it concedes "triangle winding cannot by itself
attest which A4 `filledCell/filledSide` is bound to which producer-side germ." Correct — and no producer
output repairs it, because the deficiency is not missing data upstream. **The named entity is created
downstream.** `REFUSED`; a "minimal new producer output" may not be specified, because any such output would
be fabricated authority.

#### 3. The authority the request says is missing is already implemented, in three stages

The request's decisive factual claim is:

> `SurfacePhaseFrontProduct::make` checks certificate attachments against the **same** front trace-face rows.
> This does not create independent side authority.

That describes `src/geometry/SurfaceCellTracing.cpp:8450-8467` **and stops there**. `make` continues at
`:8588-8634`, under a comment that states the opposite of the request's conclusion: *"A2b uniqueness is
checked from source topology, not asserted by the paths in the certificate being validated."* The omitted
block re-derives, inside the factory, from source topology and A3 only:

- `unique_terminal_star_path(*vertex, endpoint.firstAttachment, carrier.firstFace)` and the same for
  `secondAttachment`/`carrier.secondFace`, each required **Unique** (`:8596-8608`), with typed
  `MissingTerminalA3Path` / `AmbiguousTerminalA3Path` detail;
- every `contactPaths[side]` step re-validated (`:8613-8626`): not in `hardFeatureEdges`, incident to the
  terminal vertex, chained (`step.firstFace != at` rejects), both faces incident to the edge, `matchesA3`
  against the atlas, and no repeated face;
- each walk required to **terminate** exactly at `carrier.firstFace` / `carrier.secondFace` (`:8628-8632`);
- the two sectors required **disjoint** (`:8632-8637`).

Upstream, the consumer does not read a side off the trace either. `:19137-19173` loops over **both** carrier
orientations and keeps the one for which both attachment walks exist with disjoint sectors, rejecting
`ambiguous-carrier-orientation` if both succeed (`:19166`). The oriented side is therefore **selected by
source topology and A3**, not copied from A4.

Downstream, the absolute binding is closed twice:

- `make` pins the attachment pair to the two front edges' own trace points in the pairing order already fixed
  at `:8438-8447` (`:8458-8466`), so swapping the certificate's two attachments is rejected there;
- A5 pins them to occurrence placement: `src/pipeline/RemeshPipeline.cpp:5003-5004` requires
  `from->placement.selectedFace == published.firstAttachment` and
  `to->placement.selectedFace == published.secondAttachment`, and `:5008-5012` requires
  `QuarterTurn::from_integer(toLattice.branchRotation - fromLattice.branchRotation) ==
  compose(*rigidRotation, published.attachmentTransport())`, where `attachmentTransport()` is
  `phi[1]^-1 ∘ carrier ∘ phi[0]` over the **authenticated** star walks
  (`include/directional/geometry/SurfaceCellTracing.h:1501-1509`).

**That is the front-filled-side ownership.** It is established where the filled side exists — at the A5
occurrence — against a certificate whose orientation was chosen in the source domain and whose transport is
A3. The chain is: producer owns the terminal vertex; source topology + A3 own the orientation; the trace owns
the attachment identity; A5 owns the filled side; and all four must agree or the product is rejected. There
is no seam.

#### 4. The one real residual, named

**`R4-SID-01 / SIDE_AUTHORITY_LOCUS` (architectural, no runtime credit).** The certificate **alone** does not
pin which side is "first": a simultaneous swap of `firstAttachment`/`secondAttachment` with the carrier
reversed is internally consistent, since the orientation loop at `:19137` accepts whichever orientation the
sectors support. What breaks the symmetry is external — `make :8458-8466` against the fixed front-edge
pairing, and A5 `:5003-5004` against occurrence placement. Note that `attachmentTransport()` inverts under
that swap, so A5's transport check at `:5008-5012` catches it **only when the composed τ is not
self-inverse**; for τ ∈ {0, 2} the inverse equals itself and `:5003-5004` is the sole discriminator. That
check is therefore **load-bearing and must not be weakened or reordered**, and the two sites may not be
described as redundant with each other.

Consequence for test design: **any regression asserting that the certificate by itself determines the filled
side is vacuous** and may not be written or counted. A side negative must tamper at one of the two external
pins and name which one rejected.

#### 5. The request's correct points, accepted

1. **The RA-46.5 double-counting warning is correct and is ACCEPTED.**
   `tests/SurfaceCellTransitionQuotientTests.cpp:9052-9071` is a genuine, non-vacuous **factory** negative:
   it takes a real produced non-hard spoke from `contactPaths[side]`, inserts that exact edge into the source
   hard-feature barriers, and asserts the factory's typed `MissingTerminalA3Path` detail. It is **not** the
   A4 **consumer** first-rejection predicate `missing-terminal-A3-path` at `:19175`. The two stages are
   distinct and the factory test may **not** be counted toward consumer first-rejection coverage.
2. **The `append_edge_interval` observation is factually correct and architecturally inert.**
   `src/pipeline/RemeshPipeline.cpp:9289-9295` does take the first in-range `edge.incidentFaces` row, but that
   face is consumed only by `make_surface_cell_rail_sample` for `SurfaceCellRailSample` geometry
   (`:9309-9316`), guarded by the corner-membership check at `:9301-9307`. It is never read as a side
   credential by the certificate, the factory or A5. No repair is owed.
3. **RA-49.5 / `R4-CTC-01` is correctly preserved as a deferred Definition issue.** The consumer reads the
   contact at `:19013` and the factory validates it at `:8308`; validate-after-use stands, both checks stay,
   and its repair is not an R4 change.

#### 6. Line-citation drift (procedural hazard, recorded once)

The RA-43.4 named-mode and network-override patches shifted `SurfaceCellTracing.cpp` by roughly +16 lines.
RA-49's frozen citations `:18999`, `:19052`, `:19055`, `:19167`, `:19170`, `:19446` now read `:19015`,
`:19068`, `:19071`, `:19183`, `:19186`, `:19462`. **The ordering RA-49.0 established is unchanged** —
consumer at `:19183`/`:19186`, factory route at `:19462` — and no RA-49 conclusion moves. Future citations
must re-anchor by symbol, not by remembered line.

#### 7. What the request got right about method, and what it got wrong

Right: it refused to consume trace-face rows as authority without checking, and it declined to fabricate a
passing route. That instinct is correct and is why this ends in a discharge rather than a defect.

Wrong, twice. It read a frozen clause past its own stated scope limit, and it cited one of two contiguous
blocks of the factory check while concluding from the absence of the other. An unsatisfiability finding must
be derived from the **whole** predicate set on the path, not from a prefix of it — the same discipline RA-49.0
imposed for execution order, applied now to **extent of inspection**.

## `Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Overfull_A3_Feasibility_Review_Decision.md`; moved verbatim.

### M6-CP3-R4 — overfull-A3 feasibility, and the authority seam beneath it: Review decision (RA-48)

**Turn:** `M6-CP3-R4-OVERFULL-A3-FEASIBILITY-ARCH-REV` (independent Review).
**Adjudicates:** the carried "independent overfull-A3 feasibility Review" gate, raised in
`Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md` and restated in
`Architecture_M6_CP3_R3_A3_Trust_CB_TB_Gate_Review_Request.md` §§ on the `overfull-hard-feature-edge` guard.
**Also resolves:** the beacon/durable authority inconsistency over the already-frozen RA-47.
**Verdict:** the witness is **unconstructible through every existing call site**; the obligation is
**CONDITIONALLY RETIRED** coupled to named guards; the A4 guard is **KEPT fail-closed**; and two new findings
are frozen — **R4-OVF-01** (an unvalidated authority seam beneath the atlas's documented "only validation
seam") and **R4-OVF-02** (the oracle cannot separate the predicate it is supposed to exercise).
**Method:** re-derived from repository bytes at `6692ce457`. No binary built, no test executed, no runtime credit.

---

#### 1. What the obligation actually requires

`SurfacePhaseFrontProduct::make` counts, for every published hard-feature edge, the **actual** source-face
incidences taken from the A2b product — `sourceTopologyRegions.regions()` → `region.faces()` →
`member.topology.vertices()` (`src/geometry/SurfaceCellTracing.cpp:8177-8198`) — and rejects
`count == 0 || count > 2` (`:8202-8207`). The guard deliberately does **not** consult the lossy two-face
adjacency cache, so it is the one place in the stack that can observe a third incident triangle.

To discharge the `> 2` branch non-vacuously a fixture must reach `:8202` with a count of 3. The gate it must
first pass is the RA-40 atlas binding at `:8072-8079`: a **non-null** `FieldTransportAtlas` that satisfies
`matches_source_faces(sourceFaces, sourceTopologyRegions, sourceVertexCount)`.

---

#### 2. The witness is unconstructible through every existing call site

The chain is closed and does not depend on orientation choices:

1. **The atlas has exactly one construction seam, and it takes a `TriMesh`.**
   `include/directional/authority/FieldTransportAtlas.h:837-841` — `static FieldTransportAtlasBuildResult
   make(const TriMesh &sourceMesh, ...)`. There is no other constructor, no friend, no test seam. Its own
   class comment (`:830-834`) states "Construction is the only validation seam."
2. **The atlas's edge table is read from `sourceMesh.EV`/`EF`.** `src/authority/FieldTransportAtlas.cpp:1016-1023`
   builds `sourceEdgeRow` by scanning `EV` rows, and `:1029-1030` reads `EF(sourceEdge, 0)`/`(.,1)`.
   `EF` is **2-column by construction** (`include/directional/core/TriMesh.h:165`), so the overfull condition
   has no representation in the atlas at all.
3. **`TriMesh` construction throws on a three-face edge.** `set_mesh` calls `compute_edge_quantities`
   (`core/TriMesh.h:339-340`), which runs `dcel.check_consistency(verbose, true, true, true)` and **throws
   `std::runtime_error`** on failure (`:160-163`). The second argument is `checkHalfedgeRepetition`.
4. **Check 5 rejects it, by pigeonhole.** `core/DCEL.h:1453-1492` fails on any repeated **directed** halfedge.
   Three triangles sharing one undirected edge contribute three halfedges along it, each directed one of two
   ways; at least two therefore coincide in direction. The rejection is independent of how the three faces are
   oriented.
5. **The DCEL could not have represented it either.** `core/DCEL.h:3029-3048` finds twins through a
   `std::set` keyed on the directed pair, and an equivalent-key insert is a no-op, so a third halfedge never
   acquires a twin and would receive its own `edges` entry — the overfull edge would appear as *two or three
   distinct edge rows*, not one row with three faces. The atlas's `sourceEdgeRow.emplace` (`:1022`) would then
   silently keep the first and drop the rest.
6. **The atlas cannot be built elsewhere and swapped in.** `matches_source_faces`
   (`src/authority/FieldTransportAtlas.cpp:3090-3109`) ties `rowTopology_.size()` to `sourceFaces.rows()` and
   each `rowTopology_[row]` to `sourceAuthority.topology_for_row(face)`. The stored row topologies *are* the
   face vertex triples, so an atlas built on a manifold mesh cannot match an overfull `sourceFaces`; and an
   identical triple set is the identical mesh, with identical incidences.

**Therefore the `> 2` branch at `:8204` is unreachable with a non-null source-matched atlas, through every one
of the 116 existing `set_mesh` call sites.** This is the RA-46 shape: a negative-test obligation carried for a
condition that is structurally unrealizable. It is **retired** — conditionally, per §4.

**Corollary, and a correction to the prior audit's framing.** The static audit worried that the fixture "may
still pass at the wrong first predicate" or that `set_mesh` "throws for this nonmanifold source," and called
both unobserved. The second is not a risk to be measured — it is a **theorem** of checks 3-5 above. And the
existing `AdaptiveFeatureMapPhase11.BoundaryAndNonManifoldAreClassified` three-triangle edge is not a latent
witness: `AdaptiveFeatureMap` works on raw `V`/`F` and records `hasNonManifold` (`AdaptiveFeatureMap.h:220-224`)
without ever constructing a `TriMesh`, which is exactly why that source can be classified yet can never reach
A3 or A4.

---

#### 3. R4-OVF-01 — the unvalidated authority seam beneath the "only validation seam"

`set_mesh` does **not** always validate. `include/directional/core/TriMesh.h:331-345`:

```
if (_EV.rows() == 0) { compute_edge_quantities(verbose); }
else { EV = _EV; FE = _FE; EF = _EF; }
```

When a caller supplies an edge table, `compute_edge_quantities` — and with it `dcel.init` and
`check_consistency` — is **skipped entirely**. Nothing then checks that the injected `EV`/`FE`/`EF` correspond
to `F`. `FieldTransportAtlas::make` consumes that `TriMesh` as authoritative A1 source topology.

Two consequences:

- **The atlas's documented invariant is inaccurate as written.** "Construction is the only validation seam"
  (`FieldTransportAtlas.h:830-834`) holds only for a `TriMesh` whose edge table it also derived. Handed an
  injected one, the atlas validates adjacency, cycles and singularities against a **fabricated** edge table,
  and `matches_source_faces` cannot detect it because it compares face rows only (`:3094-3108`).
- **§2's unreachability rests on a guard one argument away from being disabled.** The entire proof above runs
  through step 3, and step 3 is conditional on the 2-argument form.

**No current caller uses the injection form.** All 116 `set_mesh` call sites across `src/`, `include/` and
`tests/` pass `(V, F)` only — which is precisely why this seam has never been noticed, and why it must be named
now rather than discovered by the first fixture that reaches for it to build the §2 witness.

This is RP-01 `AUTHORITY_DOMAIN_CONFLATION` at the bottom of the stack: a derived table accepted as authority
without validation against the datum it is derived from. It is also the eighth-family pattern again — the atlas
*reaches for* `EV`/`EF` rather than deriving what it needs from `F`, so it inherits whatever the caller put
there.

---

#### 4. RA-48 — FROZEN

**RA-48.1 — the obligation is RETIRED as unrealizable, conditionally.** No fixture is to be built for the
`count > 2` branch at `src/geometry/SurfaceCellTracing.cpp:8204`, and none may be synthesized by relaxing
manifold or incidence rules. Retirement is **coupled** to four guards; if any is weakened the obligation
revives automatically and this clause lapses:
  - **G1** `set_mesh` runs `compute_edge_quantities` on the 2-argument form (`core/TriMesh.h:339-340`);
  - **G2** `compute_edge_quantities` passes `checkHalfedgeRepetition = true` and **throws** on failure
    (`core/TriMesh.h:160-163`);
  - **G3** DCEL check 5 rejects repeated directed halfedges (`core/DCEL.h:1453-1492`);
  - **G4** `FieldTransportAtlas::make` is the only construction seam and takes a `TriMesh`
    (`FieldTransportAtlas.h:837-841`).

**RA-48.2 — the guard itself is KEPT, fail-closed.** `:8202-8207` is **not** dead code to be removed. It is
the only check in the stack that can observe an incidence the atlas's 2-column `EF` cannot represent, and under
R4-OVF-01 it is the sole backstop for an injected edge table. Removing it, or demoting it to a comment, is
prohibited. Its **`count == 0` branch keeps its obligation in full** — that branch is reachable and is a
different predicate.

**RA-48.3 — R4-OVF-01 is a defect, and the seam must be closed.** `set_mesh`'s injection branch must either
validate the supplied `EV`/`FE`/`EF` against `F`, or be removed. Until one of those lands, the injection form
must not be used to construct any source handed to `FieldTransportAtlas::make`. The atlas's "only validation
seam" comment must be corrected in the same change — a doc comment asserting an invariant the code does not
enforce is itself a defect, because later review will rely on it (this review nearly did).

**RA-48.4 — R4-OVF-02: the oracle cannot separate the predicate.** Four distinct predicates in `make` return
the identical bare `InvalidSourceAuthority`: the RA-40 atlas gate (`:8077`), the malformed-edge-key branch
(`:8190`), the incidence guard — **both** `count == 0` and `count > 2` collapsed into one site (`:8204`) — and
the terminal-contact presence check (`:8210`). An `InvalidSourceAuthority` result therefore proves nothing
about *which* check fired. Even had the §2 witness been constructible, the obligation could **not** have been
discharged non-vacuously. LESSONS-160, "passed versus did not run."

**RA-48.5 — the diagnostic collapse is now a PATTERN, not an instance.** This is the third site after
R4-A3U-01's two (`unique_terminal_star_path`'s bare `bool` at `:8352`, collapsed at `:8527-8528`). The
consumer side already demonstrates the correct shape, with three separated diagnostics at `:19071-19074`.
**RA-46.6's typed factory sub-code is hereby a PREREQUISITE** for any future incidence-guard coverage, not an
independent item: a sub-code is required to distinguish atlas-gate, bad-key, zero-incidence, overfull-incidence
and missing-contact rejections before any of them can be claimed as exercised. Extending it to the `:8204`
and `:8210` sites is added to that work.

**RA-48.6 — what may and may not be claimed.** It may be said that the overfull condition is unrealizable at
the A4 factory under G1-G4, and that the guard is retained as a fail-closed backstop. It may **not** be said
that the guard was exercised, that nonmanifold source handling was verified, or that A2b rejects malformed
source first — A2b's behaviour was not examined by this review and remains unestablished. The
`overfull-nonmanifold-spoke` guard at `:19232` and the `overfull-hard-feature-edge` predicate at `:18768` are
**separate** code paths on the producer side and are **not** adjudicated here; they keep whatever obligations
they already carry.

**RA-48.7 — no credit.** No binary built, no test executed. R4-OVF-01 and R4-OVF-02 are source-level review
findings, **not** counted stable regressions: ledger stays **66 events / 17 categories / 49 recurrences**,
debt **1**. CP2 **491/491** accepted, R3 **403/497** rejected, 94 RED, 88 accepted CP2 losses. RA-47, RA-46,
RA-45, RA-44 (less .2), RA-43 (less .5 and less the superseded `sourceEdges` row), RA-42 as corrected, RA-41
frozen scoped, RA-40, RA-39, RA-38, RA-37a and the RA-34.3 stop gates all stand unchanged.

---

#### 5. Authority reconciliation: the beacon had no recorded basis

The second half of the reported block is a straightforward contradiction, resolved on the evidence:

- Every durable document says RA-47 is adjudicated and `M6-CP3-CB1-ENTRY-R4` may resume with successor
  `M6-CP3-TB1-ENTRY-R4` — `Architecture_M6_Frozen_Definitions.md` (RA-47 head), `Future_Chat_Session_Handoff.md`,
  `ORIENTATION.md`, and the RA-47 decision, all frozen at `1350a2a79`.
- `STATUS` said `BLOCKED / Successor: UNKNOWN`, set by `6692ce457` ("record R4 transport blocker and preserved
  WIP"). That commit changed **`STATUS` only** — one line. It records no blocker, preserves no WIP, and cites
  no finding; no accompanying document exists.
- The four commits since the RA-47 freeze (`74170c022`, `4b5dc2c74`, `06a36e7e6`, `6692ce457`) contain **no
  source change and no decision record**: a STATUS flip, a snapshot trigger file, a mailbox report, and a
  second STATUS flip.
- The "transport blocker" is contradicted by its own receipt: `.workflow-mailbox/repo-source-snapshot/latest.json`
  records run `38249080586` with `"result": "success"` at `2026-10-12T12:27:47Z`, **before** the beacon was set
  to `BLOCKED`.

A beacon that contradicts durable authority **without a recorded basis is not authority**; the frozen
documents are. The beacon is corrected to `COMPLETE` for this review turn with successor
`M6-CP3-CB1-ENTRY-R4`, and RA-47 implementation resumes unblocked. Nothing in the reported external incident
bears on this: no evidence connects it to any repository state, and the one transport receipt in evidence is a
success.

## `Architecture_M6_CP3_R4_Predicate_Separation_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Predicate_Separation_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — `M6-CP3-CB2-R4-PREDICATE-SEPARATION`

**Review turn:** `M6-CP3-CB2-R4-PREDICATE-SEPARATION-REV`
**Date:** 2026-10-15
**Amendments frozen:** RA-63.1 … RA-63.14
**Adjudicated commits:** `e8313283a` … `78a4b4060` (eleven commits; `700d6418f..HEAD`)
**Verdict:** **ACCEPTED.** Both mandated diagnostic payloads are correct and lossless, and the
source edit is decision-neutral by construction. The RA-62.2 integrity fix is a **real and
substantive improvement that still fails the one test it was mandated to pass**; the exact
remedy and its satisfiability proof are frozen here. No open REVIEW_BLOCKER. No promotion,
no stable event, no regression recurrence, no gate credit.

---

#### RA-63.1 — Execution authority re-derived from object hashes, not from the report

The report claims a compile at semantic source `16c3134c02ab3872eee77a6b9dcc9d3fc6e01b7b`
while the workflow run's `headSha` is `276fc267cddbc9ad3f4212be8e048e58785cee7a`. That
discrepancy is **benign and now proven so**, by tree identity rather than by narrative:

| object | `16c3134c0` | `276fc267c` (run head) | `HEAD` (`78a4b4060`) |
|---|---|---|---|
| `src` tree | `76a12d4053a5c0798adcb0dce6d5eb8bf4e29623` | *identical* | *identical* |
| `include` tree | `790328c2bcffe29db5366ea1193cf0ab6d8cba58` | — | *identical* |

`git diff --stat 16c3134c0 276fc267c` touches exactly one file,
`.agents/Directional/agent-dispatch-request.json`. **The compile therefore covered byte-for-byte
the source that is live at HEAD.**

Run [38743048456](https://github.com/akashskypatel/Directional/actions/runs/38743048456) is
`conclusion: success`, `status: completed`. Result artifact **`11976790988`**
(`directional-m6-cp3-r4-predicate-compile-result-38743048456`, 38,939,446 bytes) exists and its
name matches the claim. Eight targets, `DIRECTIONAL_ENABLE_GMP=ON`, `libgmpxx`/`libgmp` in the
generated link command, `runtimeExecution=false`, preflight/build `0/0`.

Non-mutation re-derived against `700d6418f` by tree hash: `tests`, `benchmarks`, `cmake`,
`.github`, `include` **all byte-unchanged**. No selector file and no `CMakeLists.txt` in the
diff. Exactly two non-document files changed: `src/geometry/SurfaceCellTracing.cpp` and
`.agents/Directional/tools/review_check.py`.

**LESSON 160 holds and the turn states it itself** ("Compiler success is not runtime
acceptance"). No Directional binary, test, benchmark or frozen-497 selector executed. Nothing
runtime is claimed and nothing runtime is credited.

#### RA-63.2 — Decision-neutrality verified at the source level, by construction

Every added line sits inside the already-entered post-decision block
`if (!firstEndpoint || !secondEndpoint)` (`src/geometry/SurfaceCellTracing.cpp:19360`), after
**both** `endpoint_certificate` calls have returned (`:19354-19359`). Each added statement either
declares a block-local (`exact_source_vertex`, `fromVertex`, `toVertex`, `append_interval`,
`probeCarrier`, `firstInterval`, `secondInterval`, `firstFailedCondition`) or streams into
`endpointEvidence`. There is no `return`, no assignment to `firstEndpointPredicate` or
`secondEndpointPredicate`, no mutation of any captured state, no epsilon, and no relaxation of
`exact_corner`, `no-exact-terminal-corner`, the closed-chain branch or any `Produced`
precondition. The helper lambdas it reuses — `find_carrier`, `oriented_carrier`,
`source_face_id` — are pure reads returning by value (`:19097-19114`).

**Not one acceptance or rejection decision can change.** This is the strongest form the mandate
asked for and it is satisfied.

One null-dereference concern was raised and **discharged**: the ladder calls
`network.sourceTopologyRegions->topology_for_row(...)`, but the real certificate dereferences the
same pointer unconditionally at `:19135-19138` immediately after its `!from || !to` guard, so any
path that reaches the probe with valid source faces has already dereferenced it successfully. The
ladder's `invalid-source-face` rung guards the nullopt case before dereferencing. **No new crash
surface.**

#### RA-63.3 — Item (b) correctly implemented; the RA-62.3 hand derivation is retired permanently

`exact_source_vertex` tests the barycentric for exact one-hotness against `1.0`/`0.0` with no
tolerance and returns `faces(point.face, corner)`, or `none` when the point is not one-hot. At
most one corner can satisfy the test, so the first-match loop is unambiguous. The probe now
states **what the point is**, not merely whether it matches a published terminal — which is
precisely the omission that forced a by-hand derivation of the fixture's face table at RA-62.3.

**Prediction, with its provenance stated (RA-61.5).** For subset A the emission will be
`a2bProbeFromSourceVertex=4;a2bProbeToSourceVertex=4`. Provenance: RA-62.3's derivation from
`make_disconnected_rectangular_feature_pair_mesh` (`tests/SurfaceCellsPhase10Tests.cpp:223-264`),
giving face 0 = `(0,1,4)` and face 7 = `(4,8,7)`, against the measured probes `0:(0,0,1)` and
`7:(1,0,0)`. This is a prediction from the fixture, not an expectation from the report.

#### RA-63.4 — Item (a) correctly implemented and lossless

`exact_numerator()` / `exact_denominator()` exist at
`include/directional/authority/FieldTransportAtlas.h:516-517`, returning `EInt`
(`include/directional/numerics/ExactNumber.h:24`). `EInt::to_string()` exists on **both**
backends — `include/directional/numerics/ENumberGMP.h:61` (`value.get_str()`) and
`include/directional/numerics/BigInteger.h:401` — so the emission is exact and
backend-portable. **No double, no rounded decimal, no reconstruction.**

`append_interval` is called **unconditionally** for both records, outside the ladder, so the
presence flags and ordinals are emitted even though the ladder can never reach its own interval
rungs (RA-61.6: `same_interior_carrier_point` is unsatisfiable for a traced barycentric, so the
ladder stops at or before that rung). That placement is a correct design call and not an
accident.

#### RA-63.5 — PRINCIPAL: RA-61.9 falsifier (ii) is answered from bytes, negatively. **RA-61.9 is WITHDRAWN.**

The front-edge record `SurfaceFrontEdge` that supplies `first` and `second`
(`include/directional/geometry/SurfaceCellTracing.h:1545-1579`) carries:

- **two** endpoints — `SurfaceTracePoint from;` and `SurfaceTracePoint to;` (`:1549-1550`)
- **one** `std::optional<SurfaceSharedBoundaryInterval> sharedBoundaryInterval;` (`:1572`)
- **one** `std::optional<authority::HardRailId> railId;` (`:1568`)

`endpoint_certificate` is invoked twice (`:19354-19359`) with `first` and `second` captured by
reference and **identical in both calls**; only `fromPoint`, `toPoint` and `edge` differ.
Therefore the interior branch's interval conjunct —

```cpp
first.sharedBoundaryInterval->span      == second.sharedBoundaryInterval->span      &&
first.sharedBoundaryInterval->firstOrdinal  == second.sharedBoundaryInterval->secondOrdinal &&
first.sharedBoundaryInterval->secondOrdinal == second.sharedBoundaryInterval->firstOrdinal  &&
first.railId == second.railId
```

— **evaluates to the same value at endpoint 1 and endpoint 2.** If it is true it is true for
both; if false, false for both. **It pins the edge pair. It can never pin the point.**

RA-61.9 proposed keeping strict interiority, dropping the dead closure gate and the cross-chart
double equality, and **resting endpoint identity on exactly this witness**. With the closure gate
removed, the interior branch's only remaining endpoint-sensitive conjunct is `oriented_carrier`,
which depends on `fromPoint.face` / `toPoint.face` — **face-level, not point-level**. RA-61.9 as
specified would therefore admit an endpoint certificate carrying **no point-level exact evidence
at all**.

The asymmetry is the whole point: **the dead gate fails closed; RA-61.9 would fail open.** An
unsatisfiable gate rejects 44 valid identities, which is a visible defect. An endpoint-blind gate
would accept them on edge-level evidence, which is an invisible one. **RA-61.9 is withdrawn, not
merely left unauthorized.** No successor may implement it. Falsifier (ii) needed no run; it needed
the record's field list.

This is the fourth self-correction in the RA-57.3 / RA-58.8 / RA-59.4 / RA-61.5 / RA-61.7 family
and the second candidate remedy of mine to die on inspection.

#### RA-63.6 — `RP-01` is a pattern, and its second instance is in the same conjunction

Two granularity mismatches now sit inside the single `if (!terminalVertex)` branch:

1. **rail-level → carrier-level** (RA-62.5): `SurfaceHardRailTerminalContacts` publishes two
   endpoints per *rail* (`SurfaceCellTracing.h:1530-1535`), consulted to answer a question about
   one *carrier edge* (`:19213-19220`). Structurally unsatisfiable at a multi-edge rail's
   junction end.
2. **edge-record-level → endpoint-level** (RA-63.5, new): one `sharedBoundaryInterval` per front
   record, consulted to answer a question about one of that record's *two* endpoints.

`RP-01 AUTHORITY_DOMAIN_CONFLATION` is therefore **not one site but a recurring construction
habit**, and both instances are in the predicate this family has been circling for six rungs. The
consequence for any future repair is concrete: **widening an existing published set cannot fix
either instance.** The repair must introduce vocabulary at the granularity the question is asked
at — per-interval terminal contacts (rail intervals already exist and are already consulted by
the publisher at `:12610`) and per-endpoint exact parameters. **No repair is authorized here;**
this amendment constrains the eventual specification, it does not license code.

#### RA-63.7 — The PROCESS-01 gate fix is a real improvement **and fails the test it was mandated to pass**

What genuinely improved, and it matters: the floor is now `max` over `rev-list HEAD -- <rel>`
(`review_check.py:196-202`), so `boundary` **now detects a committed overwrite**, which was the
entire RA-62.2 hole — the previous `live >= was` against `HEAD` was inert once the overwrite was
in HEAD. `Future_Chat_Session_Handoff.md` and `ORIENTATION.md` are added to
`APPEND_ONLY_LEDGERS` (`:60-61`). `_line_count` and the live count both use `.count("\n")`, so
the two metrics agree and there is no off-by-one. Both gates pass at HEAD with floors
`4468 >= 4468`, `3108 >= 3108`, `13003 >= 13003` — the tracker floor now exceeds the RA-61
frozen floor of ≥12,949. Measured runtime 3.8 s over 424 `git show` invocations: acceptable.

Both shapes were then tested in an isolated detached worktree, never in the live tree:

| simulated defect | result |
|---|---|
| truncate handoff 4,468 → 21 lines | **`[FAIL] durable high-water … 21 >= 4468`** — caught |
| whole-file overwrite to 4,468 lines of filler, marker retained, `## ` sections 302 → 1 | **`ALL CHECKS PASSED`** — not caught |

The second row is the mandate's own acceptance criterion, quoted from `ORIENTATION.md:1853`:
*"If deleting the protected content leaves the check green, the check does not cover that
content."* Every section of authorizing history was destroyed and the gate reported green.

**The lesson generalized one level and the fix instantiated it one level too low. A guard that
counts lines does not protect content, for exactly the reason a guard that counts markers does
not.** The marker check was also weakened from a count to a presence test (`:203-204`) — correct
in itself, since it removes the prose-pollution false positive that bit this reviewer twice, but
it means *no* committed check now examines content at all. Not a blocker: the turn delivered a
strict improvement, it passes its stated claim, and the residual is specified below with proof.

#### RA-63.8 — The remedy, with its satisfiability **proven** before being mandated (RA-61.7)

Add a `## `-heading high-water floor to `boundary`, **exactly symmetric** with the line floor
already written — same `max` over `rev-list HEAD -- <rel>`, same comparison direction. Measured
evidence, all three claims verified:

- **Satisfiable today.** live == high-water for every protected file: handoff **302/302**,
  ORIENTATION **105/105**, tracker **651/651**. The gate goes green on the current tree
  immediately.
- **Catches the uncaught shape.** The equal-size overwrite above drops 302 → 1.
- **Catches every historical destruction.** `f7add683` 611→1, `0e1909d3` 629→1, `b90c0f84`
  648→1.

**Rejected alternative, with its reason recorded so it is not re-proposed.** Heading-*set*
inclusion over all history is **unsatisfiable**: 24 handoff, 3 ORIENTATION and 1 tracker headings
differ across history, because superseded `## CURRENT …` headings are legitimately reworded as
they are demoted. Per-step inclusion against the immediately preceding commit is satisfiable
today (0 missing on all three files) but is **not robust** — the next legitimate rewording turns
it red, which would train a successor to disable the gate. A **count** floor tolerates rewording,
rises on every prepend, and cannot be lowered. That is the correct predicate and this is why.

The tracker's one apparently-lost heading was chased to ground and is **not a loss**:
`## 2026-10-08 — M6-CP3-TB1-ENTRY-R2-REV …` survives at
`Regression_Root_Cause_Tracker.md:1332` with reworded trailing text. **The RA-61 restoration is
intact.**

#### RA-63.9 — The tracker's exemption from zero-tolerance is unjustified and inverted

`review_check.py:224` reads:

```python
protected_history = path in DURABLE_FILES and path != ".agents/Directional/Regression_Root_Cause_Tracker.md"
```

So handoff and ORIENTATION get zero-tolerance while the tracker keeps the 10 % rule — leaving
**the one file that has actually been destroyed three times** as the single protected file that
still permits a silent ~1,300-line deletion, which is exactly the scale of the `0043dd4c`-class
partial overwrite. No rationale is given in the code or the report.

**Measured: the tracker has had zero shrinks in the 0–10 % band across its entire history.** All
three of its shrinks are >10 % (`f7add683` 11,683→8, `0e1909d3` 12,147→11, `b90c0f84`
12,949→6). The exemption is therefore **pure slack with no historical justification** and removing
it is satisfiable immediately. Remove it; an append-only ledger tolerates no shrink, and a
genuine consolidation should fail loudly and be justified in the open rather than pass silently.

#### RA-63.10 — My RA-62 integrity count was wrong, and the undercount is mine

RA-62 recorded the handoff overwrite as the **fourth** integrity event. The bytes show at least
**six**:

| commit | date | effect | recorded in any durable document? |
|---|---|---|---|
| `ce9bf3cb` | 2026-09-22 | tracker 9,837 → 21 | yes (9 docs) |
| `0043dd4c` | 2026-09-22 | agent CHANGELOG 13,317 → 14 | yes (8 docs) |
| `f7add683` | 2026-10-08 | tracker 11,683 → 8 | **NO — zero documents** |
| `0e1909d3` | 2026-10-12 | tracker 12,147 → 11 | cited for content, not flagged as a destruction |
| `b90c0f84` | 2026-10-15 | tracker 12,949 → 6 | yes (RA-61) |
| RA-62's overwrite | 2026-10-15 | handoff 4,419 → 4,411 | yes (RA-62) |

**`f7add683` is an entirely unrecorded whole-file destruction of the append-only tracker.** It was
repaired by a later commit — the tracker stands at 13,003 — but it was never adjudicated and never
counted.

The mechanism of my error is clean and worth freezing: **I counted the integrity events that had
been written down, not the integrity events in the bytes.** That is LESSON 171 — *"a census is not
a witness"* — turned on my own ledger, by me, while mandating a content guard for everyone else.

**RA-63.10 (new lesson): a count of recorded events is not a count of events.** The remedy is not
prose. The RA-63.8 heading high-water would have surfaced all three tracker destructions
mechanically, the moment each landed. Prose lessons have now failed four times in this lineage;
the instrument has failed twice. Filed against the pre-existing **`PROCESS-01`**; it does **not**
increment the regression recurrence counter.

#### RA-63.11 — Ladder faithfulness: one ordering divergence, low severity, and the structural hazard behind it

The real conjunction order is `missing-source-face` (`:19134`) → `missing-carrier` (`:19140`) →
the interior conjunction. The probe ladder checks `carrier-absent` **before**
`invalid-source-face`. The two therefore disagree about which condition is "first" when **both**
fail. Narrow, and mitigated by construction: `a2bProbeFailure` carries the real predicate on the
same line, so the log cross-checks itself and no measurement can be silently misread.

The structural point is larger than the bug. **The ladder is an independent second transcription
of the acceptance conjunction.** If the acceptance predicate is ever edited and the ladder is not,
the instrument reports confidently about a reconstruction rather than about the decision — the
same class as RP-03, aimed at the diagnostic instead of the reviewer. Verified faithful today,
condition by condition, including that `firstAttachment` / `secondAttachment` are exactly
`topology_for_row(*source_face_id(point.face, faces.rows()))` (`:19135-19138`), which the ladder
reproduces exactly. **Deferred deliberately:** reordering is a C++ edit and would cost a fresh
eight-target compile and a new semantic source, invalidating the compile that is already packaged
at `16c3134c0`. Information per turn is higher if the harvest runs first.

#### RA-63.12 — `one-hot-carrier-junction` is a good call

The ladder distinguishes `one-hot-carrier-junction` from `not-same-interior-carrier-point` when
`!same_interior_carrier_point` and both endpoints resolve to the **same** source vertex. That
names the RA-62 mechanism — a junction-terminated front — inside the instrument itself, rather
than leaving it to be re-derived by a reviewer. Unrequested, correct, and in the right direction.
Subset A is predicted to report it.

#### RA-63.13 — `Successor: UNKNOWN`, this time with a reasoned defence, and the reasoning is accepted

The beacon again closed `UNKNOWN`, against an explicit mandate to close with a named successor.
But this instance is **not** the earlier defect. The two earlier occurrences left the field blank
with no reasoning; this one states a position: *"repository authority currently supplies no
successor identifier, so `Successor: UNKNOWN` is correct and no successor work may begin merely
because this Code + Build completed."*

That reasoning is sound, conservative, and correctly refuses to self-authorize. Naming the next
turn is the Review Agent's prerogative in this cadence, not the Implementation Agent's. **No
defect is recorded.** The successor is named here, and the mandate is amended: when no identifier
has been authorized, state that in the handoff — as this turn did — rather than inventing one.

#### RA-63.14 — Dispatch-channel hygiene, one line

A **consumed** `drive_apply` descriptor remains committed at
`.agents/Directional/agent-dispatch-request.json` with `base_sha 2d52eeb04` and a live Drive
`file_id`. A request channel whose descriptor stays live after consumption is not idempotent: a
re-read would attempt to re-apply a spent patch against a base that is no longer HEAD. `97965edd2`
retired the *source-snapshot* trigger and left the *closeout* trigger behind. Clear it in the next
turn. Not an architecture finding and not a blocker.

---

#### Accounting

No source, test, selector, binary, harness, workflow, benchmark or ledger-count change in this
**Review**; no Directional binary executed. Stable ledger **66 events / 17 categories / 49
recurrences**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88
carried CP2 losses), frozen selector **30+12+449+6=497** — all unchanged. No accepted-green loss
and no ledger credit. No promotion, no stable event, no regression recurrence, no 497 execution,
no gate credit. PR #8 draft/open. `R4-VIN-01` applies: `16c3134c0` is a **new semantic source**,
so every prior measurement — including artifact `11967601999` — is a **baseline, never a
comparand**.

**Open:** `RP-01` **located, now known to be a pattern with two instances, not repaired, repair
not authorized**; `RP-02` **UNREACHED**; `RP-03` satisfied; **`PROCESS-01` open with a proven
remedy specified (RA-63.8, RA-63.9)**.

**Withdrawn:** **RA-61.9** (both the remedy and falsifier (ii), the latter answered negatively
from bytes).

**Successor:** `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` — instrument-only, Python-only, no C++ and
therefore no compile. Then `M6-CP3-TB3-R4-PROBE-HARVEST` at semantic source `16c3134c0`.

## `Architecture_M6_CP3_R4_Probe_Harvest_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Probe_Harvest_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — `M6-CP3-CB3-R4-LEDGER-CONTENT-FLOOR` + `M6-CP3-TB3-R4-PROBE-HARVEST`

**Review turn:** `M6-CP3-TB3-R4-PROBE-HARVEST-REV`
**Date:** 2026-10-15
**Amendments frozen:** RA-64.1 … RA-64.12
**Adjudicated commits:** `5932d5937` … `1663e8527` (nineteen commits; `6a0587580..HEAD`)
**Verdict:** **BOTH ACCEPTED.** The content-floor fix is verified by independent simulation and
closes RA-63.7. The harvest is a clean, complete, immutable measurement that **falsified half of
this reviewer's recorded prediction** and reported the contradiction plainly. No open
REVIEW_BLOCKER. No promotion, no stable event, no regression recurrence, no gate credit.

---

#### RA-64.1 — Authority re-derived, not accepted

**Harvest.** Run [38756316813](https://github.com/akashskypatel/Directional/actions/runs/38756316813)
`conclusion: success`, `headSha d31a241af` (the dispatcher commit). Result artifact
**`11982824436`** present, 76,926 bytes, name matching. Harness SHA-256 recomputed on disk:

```
bec126c4b4fc835c92de2ae39c6e36295721227549aa6b4ca84178c88fea040a
```

— **byte-identical to the SHA the report claims**, so the harness that ran is the harness
committed. The measured package is the pre-existing immutable `11976790988` from the already
adjudicated compile `38743048456`, at semantic source `16c3134c0`, which RA-63.1 proved
byte-identical to HEAD's `src` tree. **No new compile, no relink, no selector change, no
benchmark, no 497.**

**Non-mutation.** `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` untouched across both
turns; only `tools/review_check.py`, the new harness, the dispatch descriptor and documents
changed. `TODO.md` and the agent CHANGELOG grew; the handoff grew 4,495 → 4,502 by **prepending**,
with history retained.

#### RA-64.2 — The content floor is implemented, and verified by simulation rather than by reading

RA-63.7 proved by simulation that the previous guard returned green on an equal-size overwrite.
The same discipline is applied here to the fix. Four simulations, each in a throwaway
`git worktree add --detach`, **nothing committed**:

| simulated defect | line floor | heading floor | gate |
|---|---|---|---|
| **A** equal-size whole-file overwrite, marker retained, sections 302 → 1 | `4502 >= 4502` PASS | **`1 >= 304` FAIL** | **caught** |
| **B** legitimate prepend | `4507 >= 4502` PASS | `305 >= 304` PASS | passes |
| **C** three headings replaced by body lines, **line count unchanged** | `4502 >= 4502` PASS | **`301 >= 304` FAIL** | **caught** |
| **D** line *and* heading counts preserved, every body line replaced | PASS | PASS | **not caught** |

**Shape A is the defect RA-63.7 recorded as uncaught; it is now caught.** Shape C shows the floor
catches a *partial* deletion that leaves the file the same length, which is stronger than
specified. The implementation also improved on the specification: one blob read per revision
supplies **both** floors, where the naive reading of RA-63.8 would have doubled the subprocess
count. Items 2–4 of the mandate all landed: the tracker's exemption is gone
(`protected_history = path in DURABLE_FILES`, `review_check.py:238`), both floors assert
`> 0` against `history_valid` so a total read failure can no longer pass vacuously
(`:206-211`), and the consumed Drive descriptor was reset to a no-op.

**Shape D is the honest residual and this Review declines to mandate more.** A rewrite that
preserves both counts *and* every heading's text, replacing only body prose, still passes.
Catching it needs per-section content hashing — a different and much heavier design. Every one of
the **six** observed integrity events (RA-63.10) collapsed the file and is now caught by shape A
or C. The turn's own report states this limit in its own words — *"these checks do not prove
arbitrary content integrity, only the explicitly authorized high-water properties"* — which is the
correct epistemic posture and the opposite of over-claiming. **`PROCESS-01`'s tooling residual is
discharged for every observed failure mode.** Escalating the guard further would be scope the
evidence does not support.

One behaviour change worth recording rather than fixing: a durable file with **no** committed
history now **fails** (`history_valid` requires a non-empty revision list) where it previously
reported `(new file)` and passed. For the three long-committed protected files this never fires,
and failing loudly on an unestablished floor is the right default.

#### RA-64.3 — This reviewer's recorded prediction was half right and half wrong

RA-63 put a prediction on record with its provenance: *subset A must emit
`a2bProbeFromSourceVertex=4` and `a2bProbeToSourceVertex=4`, and report
`one-hot-carrier-junction`.*

| claim | measured | verdict |
|---|---|---|
| subset A source vertex `4/4` | `4/4`, 15 cases | **CONFIRMED** |
| subset B vertex not to be assumed | **`2/2`, 6 cases — measured, not assumed** | discharged |
| first failed condition `one-hot-carrier-junction` | **`carrier-orientation`, all 21** | **FALSIFIED** |

**The vertex half is confirmed and the condition half is wrong, and the error is this
reviewer's.** `one-hot-carrier-junction` sits at rung 4 of the ladder; all 21 one-hot identities
stop at **rung 3**. The prediction named a *value* without checking that execution would ever
*reach* the rung that produces it — the same structural mistake as RA-61.7, one step along: there
the predicate was faithful but unsatisfiable, here the predicted label is correct but unreachable.

**RA-64.12 (new lesson): a prediction must name the rung at which it will be observed, not only
the value it will take.** Fourth member of the RA-61.5 (provenance) / RA-61.7 (satisfiability)
family: **reachability**.

The 23 interior identities report `not-same-interior-carrier-point`, so rung 3 **passed** for them.
The two subsets are therefore separated by exactly one conjunct — whether carrier orientation holds
— which independently corroborates the 23/21 partition from a direction RA-62 never used.

#### RA-64.4 — PRINCIPAL: the first gate to fail is a third expression of the same granularity error, re-derived from the fixture with no run

`oriented_carrier` (`src/geometry/SurfaceCellTracing.cpp:19106-19114`) returns a value only when
`{from, to}` **is** the carrier record's own face pair:

```cpp
if (record.firstFace == from && record.secondFace == to) return record;
if (record.firstFace == to && record.secondFace == from) return <flipped>;
return std::nullopt;
```

Recomputing `make_disconnected_rectangular_feature_pair_mesh`
(`tests/SurfaceCellsPhase10Tests.cpp:223-264`) gives, for one component:

```
face 0 = (0,1,4)   face 1 = (0,4,3)   face 2 = (1,2,5)   face 3 = (1,5,4)
face 4 = (3,4,7)   face 5 = (3,7,6)   face 6 = (4,5,8)   face 7 = (4,8,7)
edge (1,4) -> faces {0,3}        edge (4,7) -> faces {4,7}
```

The measured endpoint faces are **{0, 7}**. The carrier is edge **(1,4)**, whose face pair is
**{0, 3}**. **Face 7 is not incident to the carrier edge at all** — it belongs to the rail's
*other* edge (4,7). So `oriented_carrier` is **structurally unsatisfiable** for subset A, by the
fixture's own face table, with no execution.

**Three expressions of one granularity error now sit in the same rejecting conjunction, and this
is the one that fires first:**

1. **rail-level terminal set ← carrier-edge question** (RA-62.5) — never reached for the 21.
2. **edge-record interval ← endpoint question** (RA-63.5) — reached, and satisfied by everything
   (RA-64.5).
3. **single-carrier-edge face pair ← junction-straddling endpoint faces** (new) — **the actual
   first failure for 21 of 44.**

The practical consequence reorders the repair entirely: **the terminal-contact set is not the
first thing to fix.** The certificate's prior premise — that a front's two endpoint trace points
lie in the two faces of *one* carrier edge — is false for every junction-terminated front, and no
terminal vocabulary rescues a conjunction that has already returned `nullopt`.

#### RA-64.5 — The interval witness is satisfied 44/44, which is stronger than the type argument

Measured: **both** shared-boundary intervals present in all 44, **equal spans** (span `3` in 38,
span `2` in 6), and **exactly reciprocal ordinals** throughout — `0/1 → 1/1` against `1/1 → 0/1`
for the 23 interior identities, `3/1 → 4/1` against `4/1 → 3/1` for the 21 one-hot. Lossless
exact rationals, as RA-63.4 required.

So the conjunct RA-61.9 proposed to rest endpoint identity on is **true for every single rejected
identity in the population**. RA-63.5 argued from the record's field list that it *cannot* pin the
point; the measurement shows it *does not* discriminate anything at all.

The precise consequence, stated without inflation: RA-61.9 retained strict interiority, which the
21 one-hot identities fail, so it would not have admitted those. It would have admitted **the 23**
— on a warrant that is equally true of the 21 it still rejects. The work would have been done by
**interiority, a double comparison**, while an **exact rational** was presented as the
justification. That is worse than the dead gate it replaced, which at least failed closed and
visibly. **The withdrawal of RA-61.9 is confirmed by measurement and is final.** The report reaches
the same conclusion in its own words — *"the edge-record interval relationship is not an endpoint
identity certificate"* — and correctly declines to treat its own data as authorization.

#### RA-64.6 — NEW: the route under-reports the front's extent, and the measurement does not say why

RA-62.8 established that `observedSteps` accumulates one step per run across the whole front path,
so `routeLength = 2` is representable, and concluded that the observed `routeLength = 1` is "a fact
about the traced front". That conclusion now needs refinement, because the **geometry already
spans the junction**: the route reports **one** step (carrier `(1,4)`) while the endpoint faces
`{0, 7}` require **two** carrier edges, `(1,4)` and `(4,7)`.

Two readings remain open and **this measurement decides between neither**:

- **(i)** the A4 publisher cut a run that should have been a single route of two steps, so the
  route is wrong and the trace points are right; or
- **(ii)** a single-step route may legitimately carry endpoint trace points in faces outside its
  carrier, in which case the certificate's face-pair premise is simply the wrong question.

Under **(i)** the RA-59 two-topology recipe may already be **latently satisfied by the geometry**
while the route disagrees. Under **(ii)** RA-64.4 is the whole defect. Distinguishing them is the
first question the specification rung must answer, and it must be answered **from the publisher's
own bytes**, not inferred from the type — the discipline RA-63.5 earned. **Neither reading is
authorized as a conclusion here.**

#### RA-64.7 — Harness compliance verified against the standard applied at RA-61

156 lines. Pinned artifact id and source SHA (`:11`); provider digest and artifact digest checks
(`:19`, `:21`); manifest SHA pinned with a `28`-OK count assertion (`:24-26`);
`source-commit.txt` identity (`:27`); `exactArithmeticBackend=GMP` and `runtimeExecution=false`
assertions (`:28-29`); packaged source hash pinned (`:31`); frozen selector hashes (`:38`);
pre-snapshots `p0`/`s0`/`v0` (`:40-44`); census inventory pinned by SHA with **39 identities and
an explicit duplicate assertion** (`:46-51`); ordinal **405** excluded by an explicit `continue`
with the reason in the comment (`:56`); `NOT_SELECTED` paths increment `missing` and `continue`
(`:74-76`, `:112-113`); `planned == 44` assertion (`:120`); post-snapshots with three `cmp`
immutability checks and a postflight manifest (`:145-151`); and the closing
`[[ "$executed" == 44 && "$missing" == 0 && "$postflight" == true ]] || die` with `exit 0`
(`:155-156`). 39 census − 405 + 6 supplemental = **44**, matching the table's 23 + 21.

The extraction parser deserves specific credit: it regex-matches each field per raw log, writes an
**empty string** when a field is absent, and sets `probe_emitted = int(any(values))`, so a missing
probe is **visible rather than synthesized** — the comment says exactly that. One cosmetic
residual: the final `die` message still reads `'incomplete interior-witness measurement'`, a label
copied from the RA-61 harness. Zero impact; not worth a turn.

#### RA-64.8 — Reporting conduct: a contradicted prediction was reported plainly

RA-63's mandate said: *"If it does not, say so plainly — do not reconcile it."* The harvest
reported `carrier-orientation` for all 21, which contradicts the reviewer's recorded prediction,
**without reconciling, hedging or relabelling it**, and without claiming the vertex result
licensed anything it did not. It also kept 405 out of the 44 with its reason stated, called its own
RED set an `R4-VIN-01` **baseline** rather than a regression, and wrote *"independent Review
required before deciding an implementation successor."* **This is the standard of reporting the
family has been asking for since RP-03 was opened, and drawing the consequence of the
contradiction is this Review's job, not the measuring turn's.**

#### RA-64.9 — A disclosed transport failure, with its byte-divergence caveat volunteered

The content-floor turn's authorized Google Drive transport failed with
`container_session_unavailable`; the turn fell back to direct repository writes **and said so**,
volunteering that the downloadable patch's documentation bytes may differ from the written records.
Three identical `Record R4 Python heading-floor verification…` commits (`af81e3624`,
`add0f44c7`, `0c4a2b369`) are that retry sequence and are harmless. Disclosing a transport
substitution and its exact consequence, unprompted, is the behaviour this process depends on.

#### RA-64.10 — Beacon defect: a self-referential successor

The beacon closed `Status: IN_PROGRESS` with `Ended at:` blank and
`Successor: M6-CP3-TB3-R4-PROBE-HARVEST` — **the turn naming itself as its own successor**. RA-64.1
establishes the measurement actually completed, so `IN_PROGRESS` is stale. A self-referential
successor is **worse than the reasoned `UNKNOWN` accepted at RA-63.13**, because `UNKNOWN` signals
absence while this asserts a successor that cannot be executed. The report's own prose has the
correct content — *"independent Review required before deciding an implementation successor"* —
so this is an encoding failure, not a reasoning failure. Closed here with a named successor.

#### RA-64.11 — Next rung: the specification is authorized; the code still is not

Through RA-62 and RA-63 the repair was withheld because no specification existed. Three measured
expressions of one granularity error, a 44/44 population, two exactly-characterised subsets and
one named open question are now enough to write one. **`M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` is
authorized to produce a specification and nothing else** — no C++, no compile, no tests, no
instrument change. Its binding obligation, carried from RA-61.7 and sharpened by RA-64.12: **every
proposed predicate must be accompanied by its satisfiability witness and its reachability witness
against the measured 44**, stating which identities it would admit, which it would still reject,
and at which rung each is decided. A predicate whose admitting set is not exhibited against this
population is not a specification.

---

#### Accounting

No source, test, selector, binary, harness, workflow or benchmark change in this **Review**; no
Directional binary executed. Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt
**1**, CP2 **491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses), frozen
selector **30+12+449+6=497** — all unchanged. The 44 RED are the **`R4-VIN-01` baseline** for
semantic source `16c3134c0`, **never a comparand** against artifact `11967601999` or any earlier
measurement. No accepted-green loss, no ledger credit, no promotion, no stable event, no regression
recurrence, no 497 execution, no gate credit. PR #8 draft/open.

**Open:** `RP-01` located, **three expressions**, not repaired — **specification now authorized,
code still not**; `RP-02` **UNREACHED**; `RP-03` satisfied and exemplified (RA-64.8);
**`PROCESS-01` tooling residual discharged for every observed failure mode** (RA-64.2), with the
shape-D residual recorded and deliberately not escalated.

**Confirmed by measurement:** subset A vertex **4**; subset B vertex **2** (measured, not assumed —
backlog item discharged); RA-63.5's edge-level witness is satisfied **44/44**; **RA-61.9 withdrawn,
final**.

**Falsified:** RA-63's `one-hot-carrier-junction` prediction (RA-64.3). **Refined:** RA-62.8's
`routeLength = 1` conclusion (RA-64.6).

**Successor:** `M6-CP3-DEFN-R4-ENDPOINT-AUTHORITY-SPEC` — specification only.

## `Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`; moved verbatim.

### M6-DEFN-R5-R4-REV — producer locus for terminal contact, germ and face gauge: Review decision

**Type:** runtime-free Review adjudication discharging `R4-REV-01A`, `R4-REV-01B`, `R4-REV-02A`.
**Disposition:** the three independent-review findings are **ACCEPTED**; the remedy they demand
("name the exact producer symbol and source-line path") is **DISCHARGED HERE** from repository bytes.
**Consequence:** RA-41 freezes, scoped to the singleton terminal contact. Junction/sector clauses stay
unexercised and uncredited. No runtime, no promotion, no Code + Build in this turn.

Read at HEAD `fe372dded`. Every claim below is a direct byte read, re-derived in this turn.

---

#### 1. Accepted against my own prior review

**R4-REV-01A accepted.** `include/directional/geometry/SurfaceCellTracing.h:95-116` declares
`SurfaceCellRailSample::sourceFace`/`sourceEdge` as raw `int` and `SurfaceCellRail::sourceVertices`/
`sourceEdges` as `std::vector<int>`. My word "typed" in RA-42.1 was wrong. Sharper than the finding
states: `sourceEdge` is a **local corner index in [0,3)**, proved by its own guard
`sample.sourceEdge >= 3 → -1` (`src/geometry/SurfaceCellTracing.cpp:5824`) and by
`vertexCorner == sample.sourceEdge → -1` (`:5841`), which only type-checks if both are corner indices.

**R4-REV-01B accepted, and it is worse than a stale citation.** `railFanPotentials` **does not exist
anywhere in `src/` or `include/`**, and `git log -S` finds it only in my own architecture documents. It
was never a symbol. RA-38.5 and RA-42.4 cited a function that never existed. Struck, not relocated.

**R4-REV-02A accepted.** `SurfacePhaseFrontProduct::make` (`src/geometry/SurfaceCellTracing.cpp:8015-8020`)
checks `sourceFaceBranchRotations` for cardinality against `face_count()` and for values in `[0,4)`. That
is a range check, not provenance. One defect beyond the finding: the leading `!sourceFaceBranchRotations.empty() &&`
means an **empty** gauge passes unchecked — absent-is-accepted, the exact optionality RA-40.1 just removed
for the atlas.

**"Never use a caller's own gauge as an independent gauge oracle"** is correct and is adopted verbatim.

---

#### 2. Rejected in part: a false citation is not a false claim

The re-review rewrote RA-38.5 to "a valid vertex-star producer must be identified and demonstrated" and
annotated RA-42.4 likewise. Accepting the citation defect does not warrant deleting the architectural
claim, and the claim is **true**. The producer exists, is typed, and is named here.

- `resolve_field_vertex_transit` — `src/geometry/SurfaceCellTracing.cpp:1257`.
- Its star loop — `:1452-1476`: iterates `topology.transports()`, **filtered to adjacencies incident to
  `sourceVertex`** (`:1453-1454`); steps face→face across `adjacency.sourceEdge` (`:1456-1462`); appends
  the typed `SourceEdgeTopologyKey` to `transportPath` and accumulates
  `composedSignedLift += directed->signedLift` (`:1473-1476`), i.e. τ mod 4 along the walk.
- Frontier — `pending` seeded at `:1376`, advanced by cursor at `:1382`, extended at `:1516`: a BFS over
  `(face, branch)` states around the vertex.
- Per-face sector — `vertex_star_sector` at `:1053`, returning `VertexStarSector` (`:1042-1051`) with
  `SourceFaceTopologyKey sourceFace` and typed `nextRadialVertex`/`previousRadialVertex`.

So RA-38.5's substance stands exactly as frozen: **only the carrier cut is missing**, and the cut is a
`continue` on carrier membership inside the loop at `:1452` — no new state, no new τ definition, no A5-side
search. The germ is BFS reachability in that loop with the incident carriers cut.

---

#### 3. The decisive new finding: the terminal-contact owner is in the wrong stage

`SurfaceCellRail::sourceVertices` is **not** authored in A4 at all. It is authored in the pipeline layer:

- `src/pipeline/RemeshPipeline.cpp:9328-9356` — seeds from `ordered[run.front()].startVertex`, then for each
  `OrderedCurveEdge entry` pushes `entry.endVertex`, **enforcing continuity** with
  `rail.sourceVertices.back() != entry.startVertex → fail_edge(...)` (`:9335`) and closure with
  `front() != back() → fail_edge(...)` (`:9353`).
- `OrderedCurveEdge::startVertex` is a plain exact `int` (`:9306`), assigned at `:9401`.
- Single-edge rails: `rail.sourceVertices = {edge.vertices.first, edge.vertices.second}` (`:9491`).

Two consequences, both load-bearing:

1. **The chain is exact, not epsilon-derived.** The worry that the rail's own vertex chain might be
   reconstructed geometrically is refuted: it comes from the curve network's own edge endpoints and is
   continuity-checked. So an authenticated terminal contact *is* constructible.
2. **RA-42.1 named the owner in the wrong place.** A4's endpoint certificate cannot reach
   `SurfaceCellRail` — the rail is built by the pipeline from `featureMap.edges`, downstream of and lateral
   to `SurfacePhaseFrontProduct`. "Publish, don't invent" therefore resolves here as **bind at the factory
   boundary**, on the finished RA-40 precedent, not as "A4 reads the rail".

This is why the contact was "unproven": the owner was misidentified, so no dataflow could be shown.

---

#### 4. Namespace inventory — four, not one

A raw `int` equality across any two of these is not a topological claim:

| Value | Namespace | Evidence |
|---|---|---|
| `SurfaceTracePoint::face` | raw source-face row | header `:90-93` |
| `SurfaceCellRailSample::sourceEdge` | **local corner index [0,3)** | `:5824`, `:5841` |
| `SurfaceCellRail::sourceEdges` | **feature-edge index into `featureMap.edges`** | `RemeshPipeline.cpp:9348` |
| component mesh rows | component-local renumbering | `MeshComponents.cpp:72-116` |

`rail_sample_source_vertex` (`src/geometry/SurfaceCellTracing.cpp:5820-5844`) crosses the first two by
`std::abs(value - 1.0) <= 1.0e-8` on barycentric coordinates and is live at `:5868` and `:5937-5938`. Under
RA-42.2 that is prohibited; it is therefore an existing **defect**, not merely a pattern to avoid.

---

#### 5. Gauge authentication is constructible inside the RA-40.1 boundary

The oracle is already bound. `FieldTransportAtlas::branch_topology()`
(`include/directional/authority/FieldTransportAtlas.h:874`) exposes `FieldBranchTopology`, whose
`find_frame(const SourceFaceTopologyKey &)` is public at `:800` and yields the canonical per-face branch
frame — "gauge-invariant Z4 branch value in a canonical source-face frame" (`:52`). So per-face
authentication of `sourceFaceBranchRotations` needs **no new input**: it is the `matchesA3` shape already
written at `:7996-8009`, applied per face instead of per transition. Sixth occurrence of publish/reach.

---

#### 6. Disposition

RA-41's review gate asked Review to "either accept a source-exact implementable authority path or return
this candidate as an architectural blocker." A source-exact path now exists for both clauses — RA-41.1 via
§5, RA-41.2 via §3 and §2 — so the gate is discharged and RA-41 freezes **restricted to the singleton
terminal contact**. Its junction/sector clauses have zero produced instances (38 printed rows are one
physical singleton carrier; the 39th is receiptless) and are frozen as **unexercised**: they may not be
cited as validated, and R4's multi-carrier STOP stands undischarged.

No runtime ran. Selector 497 untouched. CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2
losses. Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1** — unchanged, because a
review-evidence defect in my own documents is not a runtime regression.

## `Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`; moved verbatim.

### M6-CP3-R4 — selected-branch / filled-side provenance and the RA-43.4 opt-out policy

**Review Agent decision.** Adjudicates `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`.
Snapshot: `cddb0b8f8` (`STATUS` BLOCKED). No runtime credit. No ledger movement. R3 stays rejected
403/497; CP2 stays accepted 491/491; ledger 66/17/49; M6 debt 1.

**Verdict: the REVIEW_BLOCKER is DISSOLVED. Both offered options are REFUSED.** The stop asks Review to
decide two questions that are already frozen-decided and one whose only outstanding element has already
landed. One genuine, bounded finding is recorded (`R4-SID-02`), one comment correction, and one policy
disposition (RA-43.4: PRESERVE, scoped).

---

#### 1. What the stop asked, and its vintage

The gate demands "Independent RA-43.1 / RA-43.2 Review must decide either **(A)** a source-checked existing
join from one exact A4 directed occurrence and front-side to the uniquely selected A1 `FieldBranch`/arrival
mode and source chart, or **(B)** authorize a minimal typed upstream producer receipt `(HardRailId, directed
occurrence, junction SourceVertexId, source face/chart, FieldBranch, arrival mode, filled cell/side)` with
first-consumer checks."

Three facts about the state it adjudicates against:

- **RA-43.2 is DISCHARGED.** RA-50.1 discharged it by bytes on 2026-10-13 (`SurfaceCellTracing.cpp`
  `:19013-19014`, `:19064-19069`, fail-closed `:19038-19043` / `:19068`; factory re-validation `:8308-8325`,
  `:8474-8497`). The gate neither cites RA-50 nor argues against it.
- **Option (B) ends in `filled cell/side`** — the exact object RA-50.2 **REFUSED** as a fifth-namespace
  category error, on the ground that a source-authored receipt naming an A4 quad-cell side must invent the
  right-hand side of its own binding. Re-proposing a refused construction verbatim, without engaging the
  refusal, is not an architectural question.
- **RA-43.1's only outstanding element has landed.** RA-43.1 states "only the carrier **cut** is missing,
  and it is a `continue` on carrier membership inside the `:1452` loop: no new state, no new tau definition,
  no A5-side search." That `continue` is present at `src/geometry/SurfaceCellTracing.cpp:1457-1467`, inside
  the `topology.transports()` loop at `:1454-1456`, cutting `FieldTransportBarrierKind::HardFeature` and
  explicitly distinguishing `SourceBoundary`. It carries the comment "RA-43.1: the terminal germ is a
  connected component of the vertex star after cutting certified incident hard-rail carriers."

##### R4-VIN-01 / STALE_FROZEN_VINTAGE — the third graded failure of a feasibility STOP

The family now reads: **RA-49.0 — wrong stage** (a guard cited as protecting a predicate that executes
before it); **RA-50.0 — wrong extent** (a frozen clause read past its own stated limit); **RA-51.0 —
neither**, the reusable correct shape; and now **RA-52.0 — wrong vintage**: a stop adjudicated against a
frozen state that has since moved, re-opening a discharged clause without citing its discharge and
re-proposing a refused construction without engaging the refusal. The diagnostic is cheap and belongs in
every future stop: **before raising RA-N as a blocker, cite RA-N's most recent disposition and say why it
does not apply.**

---

#### 2. Review A — answered: the join does not exist because no consumer needs it

The stop's factual claims about the two structures are **correct** and independently re-derived:

- A2a `FieldAlignedCandidateTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:401-423`)
  carries `authority::FieldBranch branch` — a gauge-invariant Z4 value in a canonical source-face frame
  (`include/directional/authority/FieldTransportAtlas.h:51-74`).
- A4 `SurfaceTraceSegment` (`:1211-1233`) carries `int family` / `int sign`, minted inside A4's own tracing
  from the supplied face frame (`src/geometry/SurfaceCellTracing.cpp:10805`, `:12120`, `:13398`, `:13525`),
  plus `sourceChart`, `entryRoute`, `railId`, interval fields. There is no `FieldBranch` member.

Both namespaces exist. The stop then concludes that a join is owed. **It is not**, for a reason neither
option contemplates.

##### 2.1 `family`/`sign` is consumed relationally and as digest material only

Every use of `.family` in `src/pipeline/RemeshPipeline.cpp` is enumerable and was enumerated:

| site | use |
| --- | --- |
| `:1989`, `:2204`, `:2264`, `:2350`, `:2473`, `:2574`, `:2631` | `hash_combine_i64` — digest input |
| `:10749` | `arrangementArc.family = arc.family` — copy-through |

**Seven digest inputs and one copy. Not one decision.** Inside A4 the only reads that gate anything are
run-merge tests in a single frame — `segments.back().family == family && segments.back().sign == sign`
(`src/geometry/SurfaceCellTracing.cpp:12111`, `:13533`) — i.e. equality against the immediately preceding
segment, never against a source authority.

A digest cannot separate a correct branch selection from an incorrect one: a wrong-but-consistent `family`
hashes consistently. Any regression that asserted "the digest pins the selected branch" would be **vacuous**
in the LESSONS 171 sense — structural presence, not behavioural coverage.

##### 2.2 This is RA-45.2's category error, third instance

RA-45.2 withdrew RA-44.2 because it "demanded absolute authentication of a relationally-consumed quantity."
RA-50.2 refused the oriented-germ receipt for the adjacent reason. The present request demands absolute
authentication of `FieldBranch` at an A4 occurrence, where the A4-side quantity is consumed only as digest
material and same-frame run continuity. **Option (A) is REFUSED** — the join it asks Review to find would
have no consumer, so finding it would prove nothing and constraining it would constrain nothing.
**Option (B) is REFUSED** — minting the receipt would *manufacture* the consumer, creating a fresh
unsatisfiable obligation of exactly the kind RA-45, RA-50 and RA-51 have now retired three times.

The discriminating question stands unchanged: **what can this predicate actually separate — on the path it
actually sits on?** Here: nothing, because there is no path.

##### 2.3 A4 never consumes A2a trace segments at all — the sixth namespace

The census of `options.fieldAlignedNetwork` in `src/geometry/SurfaceCellTracing.cpp` is complete:
singularity ports / vertices / index / port count (`:5374-5375`, `:5382-5387`, `:5393-5399`, `:9955-9957`);
mandatory edges (`:6137-6139`, `:6230-6232`); and the newly landed digest binding (`:5668-5674`).
`FieldAlignedCandidateTraceSegment` — the sole carrier of `FieldBranch` on the A2a side — is **never read by
A4**. The A2a network's authority over A4 is *mandatory edges and singularities*; trace identity is not part
of that contract and never was.

So the proposed join is between an A2a object A4 does not read and an A4 field A4 mints itself. Freeze as the
**sixth namespace**, beside RA-43.3's four and RA-50.2's fifth: *A2a candidate trace identity is not an A4
segment identity, and no stage converts one into the other.*

Tenth instance of the publish/don't-invent family, and its third structural variant: **do not demand a join
between two namespaces that have no data path, when neither side's consumer reads the quantity absolutely.**

---

#### 3. Review B — filled-side provenance has a second, independent closure

RA-50.4 closed the filled side at `src/pipeline/RemeshPipeline.cpp:5003-5004` / `:5008-5012`. There is a
**separate and stronger** closure the stop does not cite, at `:3562-3596`:

- `edge.filledCell` must resolve in `cellById`, `edge.filledSide ∈ [0,4)`, `edge.unfilledSide == 0`;
- `(filledCell, filledSide)` must be **unique** across all front edges (`edgeByCellSide`);
- `edge.sourceTopologyRegion == owner.sourceTopologyRegion`, region resolvable;
- `trace_equal(edge.from, owner.corners[filledSide])` **and** `trace_equal(edge.to,
  owner.corners[(filledSide+1)%4])`;
- `lattice_equal(edge.fromLattice, owner.lattice[filledSide])` **and** the same for `toLattice`;
- `isolation_sheets_connected(...)`.

A wrong `filledSide` cannot survive this: it must index the corner pair whose trace points and lattice states
are bit-equal to the edge's own. **Two independent closures now stand** where the stop asserts none, and
neither is a producer receipt. RA-50.4's "there is no seam" is re-confirmed on bytes RA-50 did not read.

##### R4-SID-02 / LATE_DEGENERACY_LOCUS — one real, bounded residue

`:3562-3596` is blind to exactly one configuration: a cell with `corners[0] == corners[2]` **and**
`corners[1] == corners[3]`, where sides 0 and 2 present the identical corner pair. A6's collapsed-edge guard
tests **adjacent** corners only (`:8446-8449`, `a6:collapsed-edge`), so it does not catch it. The case does
die — at A7 materialization, `:7482-7486`, `std::set<int>(certified.vertices).size() != 4U` →
`quad-degenerate`.

So the configuration is **closed, but at the wrong locus**: a side-authority defect surfaces as an A7
geometry degeneracy, three stages downstream of the authority it violates. This is a **diagnostic-locus
finding, not a correctness hole**, and it is not the blocker. A narrow turn may add the opposite-corner
distinctness test at the A5 locus so the first rejection names the right authority. **No new producer, no new
receipt, no new namespace.** If the implementation agent cannot construct a produced cell with equal opposite
corners, it must say so and the finding is recorded as unreachable rather than fixed — the RA-51 discipline.

---

#### 4. RA-43.4 — the opt-out is PRESERVED, scoped and census-bound

##### 4.1 The census

`rail_interval_refs` has exactly three non-test callers, and **all three pass `RequireTypedSource`
explicitly**:

| caller | network argument | mode |
| --- | --- | --- |
| `src/geometry/SurfaceCellTracing.cpp:10498-10502` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/geometry/SurfaceCellTracing.cpp:12426-12428` | `options.fieldAlignedNetwork` | `RequireTypedSource` |
| `src/pipeline/RemeshPipeline.cpp:9630-9634` | `nullptr` | `RequireTypedSource` |

The declared default is also `RequireTypedSource`
(`include/directional/geometry/SurfaceCellTracing.h:2497-2510`), so **omission is safe** and the exception
must be *named* to be taken. Inside the function, `fieldAlignedNetwork != nullptr` forces typed vertices and
a published edge list regardless of mode (`:5975-5985`), and `:6137-6147` independently checks mandatory
edge / rail / kind / **component** against the network record.

##### 4.2 The decision: keep it

**Removing the opt-out would make the network-override claim vacuous.** The Phase10 negative
(`tests/SurfaceCellsPhase10Tests.cpp:6502-6595`,
`StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress`) is the only artifact that shows the
override is load-bearing, and it can only be authored *through* the opt-out: a guard is demonstrably live
only if something can attempt the bypass it refuses. This is the guard-coupled-retirement principle
(RA-46.3, RA-48.1's G1–G4, RA-49.6, RA-51.3's H1–H6, RA-51.4's K1–K5) read **forward**: a retained guard
needs a retained attempt.

**Add no machinery.** No tag type, no builder, no attribute, no separate header. The named-mode migration
already converted the hazard from an unnamed trailing `false` into an exception that announces itself in
source, which was RA-43.4's entire purpose. Adding confinement scaffolding now would be speculative
hardening against a bypass nobody has exhibited — the stop itself says so, and it is right.

**The standing obligation is a one-line census, not code:** whenever a `rail_interval_refs` caller is added,
removed or has its mode changed, the turn's record must restate the table in §4.1. If a production caller
ever appears with `LegacyStandaloneDiagnostic`, that is a REVIEW_BLOCKER on sight.

**RA-43.4 is now narrowed to its true residue:** the *other* untyped standalone geometry diagnostics beyond
`rail_interval_refs`. The mode migration did not dispose of those and did not claim to.

---

#### 5. Comment / code scope mismatch at the landed carrier cut

`src/geometry/SurfaceCellTracing.cpp:1457-1459` reads "the terminal germ is a connected component of the
vertex star after cutting **certified incident hard-rail carriers**." The code at `:1460-1467` cuts **every**
`FieldTransportBarrierKind::HardFeature` barrier incident to the vertex, whether or not it carries the route
under construction.

**The code is correct and the comment is narrower than it.** A3 transport cannot cross a hard feature at all,
so every hard feature is a genuine barrier to the germ; cutting only the route's own carriers would produce a
germ the field cannot actually traverse. The hazard is that a future reader "repairs" the code to match the
comment and silently widens the germ. One-line comment correction; **no behaviour change**, and the fix must
not touch the `continue`.

---

#### 6. Credit: what landed and verified since RA-51

Verified against bytes, not against the agent's reports:

- **RA-49.2's duplicated-endpoint witness is AUTHORED and correctly shaped.**
  `tests/SurfaceCellsPhase10Tests.cpp:7061-7095`
  (`DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate`) takes the **actual** produced
  `firstRoute.endpoints[0].terminalVertex`, asserts it is genuinely one of the contact endpoints, sets
  `contact->second.endpoints = {vertex, vertex}`, and requires rejection at
  `a2bProbeFailure=ambiguous-terminal-contact` with an `EXPECT_EQ(npos, ...)` excluding
  `no-exact-terminal-corner`. That is exactly the specified shape, including the negative anti-assertion.
  **Compiled, not executed.**
- **RA-46.9 landed:** `src/geometry/SurfaceCellTracing.cpp:18848-18857` fails closed with
  `firstPredicate=missing-hard-feature-source-incidence` instead of throwing.
- **RA-43.1's carrier cut landed** (§1).
- **Two new first-consumer component guards landed**, both correctly placed *before* the checked factory:
  `closed-rail-component-mismatch` and `terminal-contact-component-mismatch`, each requiring the claimed
  component to equal `component_for_row` of **both** actual attachments; plus closed-chain simplicity
  (`closed-rail-chain-not-simple`), carrier ownership (`closed-rail-endpoint-edge-not-owned`) and all-hard
  cyclic edges (`closed-rail-chain-non-hard-edge`). These close a real gap: a closed-chain token previously
  substituted for a terminal contact without proving the chain owns the endpoint carrier.
- **`field_aligned_network_binding_valid` landed** (`:5666-5676`, gated at `:18800-18807`): the network's
  `source_digest`/`atlas_digest` must match the supplied atlas. The comment is right that equal network
  semantics do not imply equal atlas provenance.
- **`append_edge_interval` is no longer architecturally inert.** `src/pipeline/RemeshPipeline.cpp` now
  re-derives source components from shared-edge face connectivity independently of all feature-map metadata,
  and rejects alias records, nonmanifold (`>2`) claimed incidence and boundary-class edges with other than
  one face. Previously it took the first in-range `incidentFaces` row on trust.

##### R4-JCT-01 — the multi-carrier junction witness is AUTHORED, not executed

`tests/SurfaceCellREPackageTests.cpp` now asserts `EXPECT_GT(authenticatedJunctions, 0U)` with
"this fixture must reach an actual produced multi-carrier junction", alongside
`EXPECT_GT(authenticatedContactSteps, 0U)` and `EXPECT_GT(authenticatedJunctionSteps, 0U)`, over
`certificate.junctions` of a **produced** phase front, and checks A1's commuting square on each junction
step. These are real non-vacuity guards on the previously-empty loop.

**Status moves from UNEXERCISED to AUTHORED / COMPILED / NOT EXECUTED.** RA-41's junction and sector clauses
stay **frozen UNEXERCISED** at runtime. No runtime credit accrues from a compile (LESSONS 160). The witness
is only discharged when that `EXPECT_GT` is **observed** to pass in an authorized Test + Benchmark turn.

The stop's own evidentiary reading of `:736-766` is **accurate**: the loop over `frame->branches` establishes
*existence* of an admitting germ, not *selection*. That reading is correct and is the reason it cannot be
used as a selected-branch join — but per §2 no such join is owed, so the observation closes the question
rather than opening one.

---

#### 7. Disposition

- **REVIEW_BLOCKER DISSOLVED.** Options (A) and (B) both REFUSED. RA-43.2 stays DISCHARGED; RA-43.1's carrier
  cut is LANDED; no selected-branch receipt is owed or permitted.
- **RA-43.4: opt-out PRESERVED, scoped, census-bound.** Residue narrowed to the non-`rail_interval_refs`
  standalone geometry diagnostics.
- **One new bounded finding:** `R4-SID-02 / LATE_DEGENERACY_LOCUS`, A5 locus repair, reachability to be
  established first.
- **One comment correction** at `:1457-1459`.
- **No credit.** No runtime. No ledger movement. No selector mutation. `review_check.py boundary` must pass.

## `Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Terminal_A3_First_Rejection_Review_Decision.md`; moved verbatim.

### M6-CP3-R4 — terminal-A3 and terminal-sector first-rejection reachability: REVIEW DECISION

**Adjudicates:** `Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md` (`R4-TA3-01`).

**Disposition: the REVIEW STOP is DISSOLVED. Both of RA-49.7's remaining unadjudicated negatives are now
adjudicated and BOTH are RETIRED, coupled to named guards.** `missing-or-nonreciprocal-terminal-A3` is
unreachable (Review A/B). `overlapping-terminal-sectors` is **also** unreachable, by a different and
independent argument (Review C). Both guards are **kept fail-closed**. No runtime credit. Ledger
**66 / 17 / 49**, M6 debt **1**, unchanged. Selector **497** untouched; CP2 **491/491** accepted; R3
**403/497** rejected with 94 RED and 88 accepted CP2 losses.

**The request is the best-constructed stop of this series.** It states a *conditional* inference, explicitly
refuses to claim universal unreachability, names its own counterexample class, and asks the one question that
decides the matter. That is the correct shape for a feasibility stop. Both of its provisional inferences are
confirmed, and its one framing error is minor and stated in §6.

---

#### 1. Review A — the ingress census, and the distinction that decides it

**There are exactly two public A4 ingress variants.** The primary
`build_surface_cell_network(vertices, faces, faceAxisX, faceAxisY, targetSize, options, …)` at
`src/geometry/SurfaceCellTracing.cpp:18743`, and the convenience overload at `:20011`, which computes axes
from the cross field and **delegates to the primary** on both of its branches. The gate therefore dominates
every path to the terminal loop.

**No atlas built for a distinct source can pass the gate.** The chain is a two-sided row-by-row pin:

- **Build side.** `FieldTransportAtlas::make` (`src/authority/FieldTransportAtlas.cpp:1893`) requires
  `sourceAuthority.matches_source_faces(sourceMesh.F, |V|)` at `:1909-1910` before anything else, and then
  fills `rowTopology_[row] = sourceAuthority.topology_for_row(row)` at `:1926`. So `rowTopology_[row]` **is**
  the `SourceFaceTopologyKey` of `sourceMesh.F.row(row)`.
- **Consume side.** `:18756-18764` sets `network.sourceTopologyRegions` to an authority that **always**
  satisfies `matches_source_faces(faces, …)`: a supplied authority that does not match is silently **replaced**
  by one built from `faces`, so no path carries regions inconsistent with `faces`. Then `:18771-18774`
  requires `atlas.matches_source_faces(faces, regions, |V|)`, which requires
  `rowTopology_[row] == regions.topology_for_row(row)` for **every** row
  (`FieldTransportAtlas.cpp:3101-3108`), and `SourceTopologyRegions::matches_source_faces`
  (`include/directional/geometry/SourceTopologyRegions.h:151-188`) requires `regions.topology_for_row(row)` to
  equal the key of `faces.row(row)` for every row.

Composing: **`key(faces.row(r)) == key(sourceMesh.F.row(r))` for every `r`.** A `SourceFaceTopologyKey`
determines the triangle's three vertex IDs, hence its three undirected edges, so `faces` and `sourceMesh.F`
induce the **same undirected edge set with the same per-edge face incidence**. There is no "same regions,
different edges" atlas.

**The distinction the request asked for: non-traversable ≠ missing value.** In `make`'s edge loop, a one-face
edge is recorded `SourceBoundary` and `continue`s **before** any value is published (`:2008-2013`); a two-face
edge with no cross-field transition fails `MissingAdjacency` (`:2016-2018`); wrong face ownership fails
`NonReciprocalAdjacency` (`:2020-2027`); and only then
`transitionValues.push_back(FieldTransportTransitionValue{…})` runs at **`:2039-2042`**, which is **before**
the `HardFeature` (`:2043-2047`) and region/component `NonTraversable` (`:2048-2054`) categorizations. A
barrier classification therefore **never withholds a transition value**. `nontraversableEdges` is a separate
list; `transitionValues` is complete for every two-face edge.

#### 2. Review B — `missing-or-nonreciprocal-terminal-A3` is UNREACHABLE

The predicate (`src/geometry/SurfaceCellTracing.cpp:19099-19105`) is a three-way disjunction: `!forward`,
`!reverse`, or `reverse->transport != forward->transport.inverse()`. Six links close all three.

- **H1 — build-time pin.** `FieldTransportAtlas.cpp:1909-1910` and `:1926` (above).
- **H2 — consume-time pin.** `SurfaceCellTracing.cpp:18756-18764` and `:18771-18774` (above). On every path to
  `:19105` the atlas is non-null; a null atlas rejects earlier and differently at `:19079`
  (`missing-source-A3`).
- **H3 — the edge table is a function of `F`.** RA-48.3 has **landed** (commit `785dd7398`, 2026-10-12
  16:07Z) and is **stronger than specified**: `TriMesh::set_mesh`
  (`include/directional/core/TriMesh.h:331-351`) now calls `compute_edge_quantities(verbose)`
  **unconditionally**, then, if any of `_EV`/`_FE`/`_EF` was supplied, requires it to be **bit-identical** to
  the derived table or **throws** `"set_mesh(): injected edge topology disagrees with faces"`. R4-OVF-01 is
  closed. **Consequence for RA-48.1: guard G1 is now unconditional, so the overfull obligation does NOT
  revive — it is held strictly more tightly than when RA-48 froze.** The DCEL throw is intact at
  `TriMesh.h:160-163`.
- **H4 — every two-face edge has a value, unconditionally** (`:2039-2042` before categorization, with
  `MissingAdjacency` at `:2016-2018`). H1∧H2∧H3 ⟹ every two-face spoke `edge_faces(faces)` yields is a row of
  `sourceMesh.EV`; H4 ⟹ it has a value. The consumer has already skipped the only two exceptions —
  boundary spokes (`incident[0] < 0 || incident[1] < 0 → continue`) and hard-feature spokes
  (`hardFeatureEdges.contains(spoke) → continue`). **`!forward` and `!reverse` cannot fire.**
- **H5 — `reverse` is computed, never supplied.** `FieldTransportAtlas.cpp:2033-2034`:
  `const QuarterTurn reverse = forward.inverse();`. One immutable record holds both, and
  `directed_transition_value` (`:910-922`) returns `value.forward` for `(first,second)` and `value.reverse`
  for `(second,first)`. The consumer's third disjunct therefore compares `value.reverse` against
  `value.forward.inverse()` — **equal by construction**. Not unobserved: **unrepresentable**.
- **H6 — one seam, no mutators.** `FieldTransportAtlas`
  (`include/directional/authority/FieldTransportAtlas.h:837-900`) exposes `make` as its only producer, no
  public constructor and no mutator, only a defaulted `operator<=>`. There is no copy-and-remove path.

**Verdict: RETIRE the `missing-or-nonreciprocal-terminal-A3` fixture obligation, coupled to H1–H6.** If any of
H1–H6 is weakened the obligation **revives**. The guard at `:19099-19105` is **kept fail-closed** — it is the
only backstop should a future route obtain an atlas other than through `make`.

#### 3. Review C — `overlapping-terminal-sectors` is ALSO UNREACHABLE

Adjudicated separately, as the request correctly demanded, and by an unrelated argument.

- **K1 — the paired front edges are in different A2b regions.** `:18892`
  (`if (first.sourceTopologyRegion == second.sourceTopologyRegion) continue;`) dominates the certificate call.
- **K2 — a front edge's trace faces lie in its own region.** All three front-edge constructors take the
  enclosing traced region (`:12946`, `:14686`, `:17257`: `SurfaceFrontEdge edge(region.id(), cell.id)`), and
  the per-region tracers enforce face membership explicitly (`:12380`, `:14920`, `:17538-17539`:
  `region_for_row(row) != region.id()` rejects). K1∧K2 ⟹ **`firstAttachment != secondAttachment`**.
- **K3 — every face has degree ≤ 2 in the local star.** The star is built only from spokes with exactly two
  incident faces: `> 2` rejects at `:19091` (`nonmanifold-terminal-star-spoke`, itself retired by RA-49.6) and
  `< 2` (boundary) `continue`s. Each face at the vertex carries exactly two spokes at that vertex, so its
  degree in `localStar` is at most 2. **A graph of maximum degree 2 is a disjoint union of paths and cycles.**
- **K4 — a cycle component yields ambiguity, not overlap.** `path_to` requires `count == 1`
  (`:19137`); on a cycle there are two simple paths, so it returns `nullopt` with `pathCount > 1` and the loop
  ends at `ambiguous-terminal-A3-path`, never at overlap.
- **K5 — both orientations are tried** (`:19143`).

**Proof.** Work in a path component with the carrier's two faces at its ends, ordered `F1 … F2`. Write
`p = firstAttachment`, `q = secondAttachment`. The un-reversed orientation walks `p → F1` and `q → F2`; these
closed intervals intersect **iff `p` is at or after `q`** in the `F1 → F2` order. The reversed orientation
walks `p → F2` and `q → F1`; these intersect **iff `p` is at or before `q`**. Both overlap **iff `p == q`**,
which K1∧K2 exclude. If `p` and `q` lie in different components, at least one target is unreachable and the
loop ends at `missing-terminal-A3-path`. **No input yields `overlapping-terminal-sectors`.**

**Verdict: RETIRE the `overlapping-terminal-sectors` fixture obligation, coupled to K1–K5.** Guard **kept
fail-closed**. Weakening K1 (the pairing region-distinctness) or K3 (the incidence bound) **revives** it.

Note the structural echo of RA-50.5: the mis-ordered-attachment case is absorbed by the second orientation,
exactly as the global attachment swap is absorbed there. The certificate's side symmetry is the same symmetry
in both results.

#### 4. One hypothesis checked, no defect reported

The consumer's `localStar` (`:19081-19110`) excludes only `hardFeatureEdges` and so **admits** steps across
region/component seams the atlas classified `NonTraversable` (`FieldTransportAtlas.cpp:2048-2054`). If the
factory re-derivation used a different rule, a certificate the consumer accepted would be rejected by
`make` — a producer/validator disagreement. **It does not.** `unique_terminal_star_path`
(`SurfaceCellTracing.cpp:8395-8430`) applies the same rule: `incident.size() > 2` invalid,
`hardFeatureEdges.contains(spoke)` skipped, `incident.size() != 2` skipped, then `transition_value` plus
`matchesA3`. Consumer and factory **agree**: the terminal star is cut by **rails only**. This is recorded as a
deliberate design, not a finding, so it is not re-raised as one.

#### 5. New finding — `R4-TA3-02 / DEAD_DISJUNCT` (architectural, no runtime credit)

Two reciprocity tests are dead by construction, and naming them is a forward constraint, not a cleanup
request:

- `reverse->transport != forward->transport.inverse()` (`SurfaceCellTracing.cpp:19103-19104`) — dead by H5.
- `compose(forward, reverse) != QuarterTurn{}` (`FieldTransportAtlas.cpp:2035-2038`) — dead for any correct
  `QuarterTurn::inverse`.

Both are harmless as fail-closed guards and **stay**. The constraint is on RA-46.6: **a typed sub-code may not
be minted for a disjunct that cannot fire.** Splitting `missing-or-nonreciprocal-terminal-A3` into a "missing"
and a "nonreciprocal" sub-code would manufacture a fresh unsatisfiable fixture obligation of exactly the kind
this decision just retired twice. Sub-code work must separate **reachable** predicates only.

#### 6. The request's one framing error

Step 4 groups RA-48.3 with RA-49.7's unadjudicated list. RA-49.7 left two **feasibility** questions open —
`overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3`. RA-48.3 was never one of them: it
is an **implementation** obligation, and it had already **landed** at the request's own snapshot (ancestor
`785dd7398` of `0240d0f00`). Its landing is not a parallel open item; it is the link (H3) that closes the
forged-edge-table route the request was right to worry about. The distinction matters because an
implementation obligation discharges by code, while a feasibility question discharges only by review.

Its line citations also predate RA-50's prepend: `Architecture_M6_Frozen_Definitions.md:157-163` no longer
points at RA-49.7. Cite frozen clauses by RA number, never by line — RA-50.8 already required this for source.

## `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Review_Decision.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — terminal A3 dual-path feasibility: Review decision

**Type:** runtime-free independent Definition/Review adjudication of the terminal A3 uniqueness request.
**Verdict:** the lemma is **CONFIRMED**, and **strengthened** — unreachability does not depend on the RA-37a
manifold premise. The impossible two-admissible-path fixture obligation is **RETIRED** as **RA-46**, coupled to
four guard conditions. R4 Code + Build continues.

Read at HEAD `d8b565c9e`. The proof below is re-derived from bytes, not from the request's prose.

---

#### 1. The lemma, re-derived from the two implementations

Both path counters build the same object. Consumer side, `endpoint_certificate`
(`src/geometry/SurfaceCellTracing.cpp:18979-19031`): `std::map<Face, std::vector<Transition>> localStar`,
populated only from `sourceEdges` filtered to spokes containing `*terminalVertex` (`:18981-18982`), rejecting
`sourceEdgeFaceCounts.at(spoke) > 2U` (`:18983`), skipping `hardFeatureEdges` spokes (`:18984`), skipping
spokes without two incident faces (`:18985`), and requiring reciprocal A3 (`:18996-18998`). Checked-factory
side, `unique_terminal_star_path` (`:8318-8352`): `std::map<StarFace, std::set<StarFace>> adjacency`, the same
filters at `:8325-8326`, plus `*firstRow == *secondRow → return false` (`:8330`) and `matchesA3` (`:8333`).

**(a) Maximum degree is 2.** Adjacency arises only from spokes at `v`. A face incident to such a spoke
contains both its endpoints, hence contains `v` as a corner; a triangle has **exactly two** edges at a given
corner. So each face-node has degree at most two. (On the factory side `std::set` additionally collapses any
duplicate, so the bound is strict there.) Every component is therefore a simple path or a simple cycle.

**(b) The carrier's component is acyclic.** The terminal carrier is a hard-feature edge containing `v`, and
hard-feature spokes are excluded at `:8326` and `:18984`. So the carrier edge is absent from the graph, and
the component holding the carrier's incident faces has lost at least one of its edges. A path minus an edge is
a forest; a cycle minus an edge is a path. Either way: **acyclic**.

**(c) The target is always carrier-incident.** `:8523-8526` targets `carrier.firstFace` and
`carrier.secondFace`; `:19044-19047` targets `oriented.firstFace` and `oriented.secondFace`. There is no call
site with any other target.

**(d) Conclusion.** In an acyclic graph there is at most one simple path between an ordered pair of nodes; if
`from` lies in a different component there are zero. By (b) and (c) the target always lies in an acyclic
component. Therefore **`pathCount >= 2` is unreachable for every input the preceding guards admit.**

#### 2. Why this is stronger than the request's argument

The request conditions the lemma on RA-37a's connected oriented two-manifold link and on distinct triangles.
Neither premise is needed, and both of the gaps those premises were papering over are closed by (b)+(c):

- **Pinch / bowtie vertex** — two fans meeting only at `v`. Every edge incidence is still 2, so the `> 2U`
  guard does **not** catch it, and the link is disconnected with an untouched cycle. It still cannot yield two
  paths: the untouched cycle contains no carrier-incident face, so a target there is unreachable (zero paths),
  and a target in the cut component sits in an acyclic component (at most one).
- **Doubled triangle ("pillow")** — the only structure that could give the consumer-side multigraph a
  2-cycle. Two faces joined by two distinct spokes at `v` must share both edges at `v`, so they span the same
  vertex set; their only two spokes at `v` are exactly those two, and the carrier — being a hard edge
  containing `v` — is necessarily one of them. Cutting it leaves a single edge: one path.

So the lemma does not rest on the accepted manifold contract, and retiring the obligation does not borrow
authority from RA-37a. **A counterexample is not merely absent from the fixtures; it does not exist.**

#### 3. The retirement is coupled to four conditions

Unreachability is a theorem **relative to its guards**. A dead negative is dead only while they hold, so
RA-46 binds the retirement to all four, and any weakening of any one revives the obligation:

1. source faces are **triangles**, giving exactly two edges at a corner — this is the degree bound;
2. hard-feature spokes are **excluded** from the star graph (`:8326`, `:18984`);
3. the terminal carrier **is** a hard-feature edge containing the terminal vertex;
4. the DFS target **is** a carrier-incident face (`:8523-8526`, `:19044-19047`).

#### 4. Findings on the landed code

**Accepted — the diagnostics are already correctly separated.** `:19048-19053` sets `ambiguousTerminalPath`
only when `firstPathCount > 1 || secondPathCount > 1`, and `:19071-19074` selects among
`overlapping-terminal-sectors`, `ambiguous-terminal-A3-path` and `missing-terminal-A3-path`. The unreachable
condition does **not** share a message with the reachable zero-path case. No defect here.

**Finding R4-A3U-01 — the checked-factory side conflates zero with ambiguous.**
`unique_terminal_star_path` returns `bool` (`:8352`) and both call sites collapse into a bare
`InvalidSourceAuthority` (`:8527-8528`) with no sub-code. The factory is the **authoritative** check, so under
RA-42.3 it is the side that most needs typed diagnostics: a genuine no-path rejection is today
indistinguishable from the unreachable ambiguity branch. Required: a typed sub-code distinguishing them, so
that the zero-path negative can be verified at its actual first rejecting predicate. Not a block.

**Clarified — `exact_corner` is a confirming predicate and does not violate RA-42.2.** `:18957-18963` tests
`point.barycentric[i] != (i == corner ? 1.0 : 0.0)` bit-exactly, with **no tolerance**. The vertex identity is
taken from the typed published contact `contact->second.endpoints` (`:18966`, RA-44.1); the barycentric test
only confirms it. RA-42.2 forbids **deriving** incidence from geometry, not confirming it, and this predicate
can only false-reject, never false-accept. Recorded so it is not later mistaken for a violation — and so it is
not "fixed" by introducing a tolerance, which **would** be the violation.

**Accepted — sector disjointness is enforced at the factory.** `:8552-8556` requires `used[0]` and `used[1]`
to be disjoint, and `:19055-19064` does the same consumer-side via `overlappingSectors`. This is RA-38's
boundary-germ separation enforced where it counts, and it is the structural reason the two contact walks
cannot collude.

**Hardening, not a block.** `sourceEdgeFaceCounts.at(spoke)` (`:18983`) throws if the two maps are ever built
from different sources; prefer a bounds-safe lookup that fails closed.

#### 5. Answers to the request's four items

1. **Confirmed**, by §1, and strengthened by §2. No counterexample is required or possible.
2. **Granted** as RA-46: the literal two-admissible-path source-witness demand is retired. The
   `pathCount != 1` guard is **retained** as a fail-closed defence with **no fixture obligation** on its
   `>= 2` branch. Note the guard is not dead overall — its `== 0` branch is reachable and keeps its obligation.
3. **Approved** as specified, targeting the reachable first-rejection diagnostics that already exist:
   `missing-terminal-A3-path`, `overlapping-terminal-sectors`, `no-exact-terminal-corner`,
   `ambiguous-terminal-contact`, `missing-or-nonreciprocal-terminal-A3`, `nonmanifold-terminal-star-spoke`,
   plus the new factory sub-code from R4-A3U-01. No frozen test identity changes; no runtime assertion.
4. **Not applicable** — item 4's branch does not arise, since the lemma holds without the manifold premise.
   No new source topology class is defined and none is needed.

No runtime ran. Selector 497 untouched. CP2 491/491 accepted; R3 403/497 rejected, 94 RED, 88 accepted CP2
losses. Stable ledger **66 / 17 / 49**, debt **1** — unchanged: retiring an unrealizable obligation is a
definition correction, not a runtime regression.

## `Architecture_M6_CP3_R4_Terminal_Conjunct_Extraction_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Terminal_Conjunct_Extraction_Review_Decision.md`; moved verbatim.

### RA-62 — `M6-CP3-TB2-R4-CONJUNCT-EXTRACT` review decision (2026-10-15)

Reviewer turn `M6-CP3-TB2-R4-CONJUNCT-EXTRACT-REV`. Accepts the extraction,
**names the measured mechanism with full provenance from repository bytes**, and
**locates `RP-01` precisely for the first time**.

Candidate/non-stable throughout. No promotion, no stable event, no regression
recurrence, no 497 execution, no gate credit. No source, test, selector, binary,
harness, workflow or benchmark change in this Review.

---

#### RA-62.1 — The extraction is ACCEPTED, and it is the best-executed rung of this family

Artifact-only, from the pre-existing immutable artifact `11967601999` (provider
digest and independently re-verified ZIP SHA-256
`8b52373eebc7bda574f1fed2914dec4577ff70c670396f2ea3b19383d0fd25f1`, 50/50
manifest digests), original run
[38725063279](https://github.com/akashskypatel/Directional/actions/runs/38725063279),
semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`. No dispatch, no compile, no
test execution, no benchmark, no selector change, no new runtime claim.

The partition matches RA-61's prediction **exactly**:

| Family | Count | Artifact indices | First failure |
|---|---:|---|---|
| Interior-shaped paired barycentrics | **23** | 1–11, 26–33, 38–39, 42, 45 | `no-exact-terminal-corner` |
| One-hot paired vertex barycentrics | **21** | 12–25, 34, 36–37, 40–41, 43–44 | `no-exact-terminal-corner` |
| Ordinal 405 | **1** | 35 | `missing-terminal-or-closed-rail-provenance` |

Four disciplines are worth recording explicitly. The turn **delivered the
three-conjunct truth table per published candidate**, which is precisely what
`RP-03` demands and what the measuring turn had omitted. It **refused to
over-claim**: *"the logs do not prove a canonical source vertex shared between
charts"* is exactly right, and the restraint is correct rather than timid. It
**kept ordinal 405 separate** and reported its distinguishing fact
(`ContactPresent=0`). And it **named a successor in the beacon**, ending the
two-turn run of `Successor: UNKNOWN`.

---

#### RA-62.2 — DEFECT, repaired here: the handoff CURRENT section was overwritten in place

The handoff convention is accumulate-and-supersede — a new section is prepended
and says it supersedes the one *below*, which remains as authorizing history.
This turn's section correctly says *"Supersedes the previous CURRENT section
below"*, but the previous section — RA-61's, 23 lines — was **deleted** rather
than left below it. Net `4,419 → 4,411` lines.

**Neither gate catches this.** `Future_Chat_Session_Handoff.md` is not in the
`ledgers` coverage list (which carries the tracker, `.agents/CHANGELOG.md`,
`LESSONS.md` and root `CHANGELOG.md`), and `boundary`'s durable-marker check
reports `1 -> 1` because the durable-section heading
survives further down the file while the content above it is replaced.

**This is `ORIENTATION.md:1799` verbatim** — *"A guard that counts markers does
not protect content"*, recorded for `f6a784cf`, where a heading survived a
consolidation and `review_check.py` passed it as `durable markers preserved:
1 -> 1`. Fourth integrity event in this lineage, second in two turns, and on a
**different file** from the one protected last turn — which is the general
lesson: protecting one file by name does not protect the class.

**And the remedy was already named, in exactly the form adopted at RA-61.3.**
`ORIENTATION.md:1719` states that *"the effective guard is `review_check.py
ledgers --base <previous-review-commit>`, which scans committed history"* and
that the `boundary`-based guard *"was inert against committed overwrites"*. The
same entry records that `ce9bf3cb` also overwrote the agent CHANGELOG
(`0043dd4c`, 13,317 → 14 lines) and that **the first repair missed it**.
`:1799` already supplies the decisive test — ***if deleting the protected
content leaves the check green, the check does not cover that content*** — and
already tracks the residual as **`PROCESS-01`** (`LESSONS.md` 172). This turn's
handoff overwrite is a textbook instance, so the RA-62.2 mandate is filed
against `PROCESS-01` rather than opened as new.

**No RA-61 finding was lost.** The decision document,
`Architecture_M6_Frozen_Definitions.md`, `ORIENTATION.md`,
`Regression_Root_Cause_Tracker.md` and root `CHANGELOG.md` are all byte-unchanged
from `215698e0e` (verified). Only the handoff's resume chain was truncated, and
it is restored in this turn beneath the new section.

**Mandated for the next Code + Build rung, first item:** add
`Future_Chat_Session_Handoff.md` and `ORIENTATION.md` to the `ledgers` coverage
list, and replace `boundary`'s self-relative durable check with a **monotone
high-water floor**. Prose lessons have now failed three times.

---

#### RA-62.3 — The one-hot vertex is **4**, derived exactly, with every measured truth value reproduced

The extraction correctly declined to name the vertex. The fixture settles it
with no run.

`make_disconnected_rectangular_feature_pair_mesh`
(`tests/SurfaceCellsPhase10Tests.cpp:223-264`) builds one 3×3 planar grid per
component, vertex index `y*3 + x`, and emits two faces per cell as
`(lowerLeft, lowerRight, upperRight)` then `(lowerLeft, upperRight, upperLeft)`.
Therefore:

```
face 0 = (0, 1, 4)        face 7 = (4, 8, 7)
```

The measured one-hot probes are `from 0:(0,0,1)` and `to 7:(1,0,0)`, so:

```
faces(0, 2) = 4        faces(7, 0) = 4
```

**Both charts designate vertex 4.** The rail is the chain **1 – 4 – 7**
(`:6315-6318`, `userHardEdges {1,4}` and `{4,7}`), its published terminals are
`{1, 7}`, and its **interior junction vertex is 4**.

Recomputing the probe predicate from this face table reproduces all four
measured values for subset A exactly:

| candidate | `railEnd[v]` | `corner[v]` | measured |
|---|---|---|---|
| v = 1 | 1 (on carrier `(1,4)`) | 0,0 (point is at 4, not 1) | matches |
| v = 7 | 0 (not on carrier `(1,4)`) | 0,0 | matches |

`railEnd[7] = 0` is also the first **measured** confirmation of **RA-60.6**: at
`routeLength = 1` the carrier touches terminal 1 but not 7, so terminal 7 cannot
be attached in these fixtures. That was inferred at RA-60; it is now observed.

---

#### RA-62.4 — Mechanism named: a **junction-terminated front**, a third shape with no certificate at all

The front occupies exactly one carrier edge `(1,4)` and terminates at vertex 4.
It is **not** a terminal front — no exact corner at 1 or 7 — and **not** an
interior front — strictly one-hot, so not interior to the carrier. Both branches
of `endpoint_certificate` therefore refuse it, each correctly.

RA-60.2 recorded that *"a front ending exactly at the rail's interior junction
vertex 4 is rejected, not absorbed"* and offered it as reassurance that RA-41's
junction clauses stayed outside the repair's scope. The measurement shows that
same configuration is **the actual failure mode of 15 of 44 identities**, and on
the shared evidence shape almost certainly all 21. A clause filed as a dormant
backlog item is the live defect for roughly a third of the measured population.

---

#### RA-62.5 — PRINCIPAL: this is `RP-01` in its exact canonical form — rail-level authority answering a carrier-level question

`SurfaceHardRailTerminalContacts` is
`std::map<authority::HardRailId, SurfaceHardRailTerminalContact>` and each
contact carries exactly **two** endpoints **per rail**
(`include/directional/geometry/SurfaceCellTracing.h:1530-1535`). Terminal
authority is therefore **whole-rail**: rail 1–4–7 publishes `{1, 7}` and nothing
else.

`endpoint_certificate` then tests a **carrier-edge-level** endpoint against that
**rail-level** set (`src/geometry/SurfaceCellTracing.cpp:19214-19217`):

```cpp
for (const auto vertex : contact->second.endpoints) {        // rail-level {1,7}
  if ((edge.first() != vertex && edge.second() != vertex)   // carrier-level (1,4)
      || !exact_corner(fromPoint, vertex)
      || !exact_corner(toPoint, vertex)) continue;
```

The conjunction can succeed only when the carrier edge happens to contain a
whole-rail terminal **and** the front endpoint sits exactly on that same
terminal. For a **multi-edge rail**, a front occupying one carrier edge
**structurally cannot** satisfy it at the junction end — no input value can
rescue it, exactly as RA-61.6's closure gate could not be rescued.

There is no per-interval terminal vocabulary, although rail **intervals** exist
and are already consulted by the publisher (`find_rail_interval(railBuild.intervals, …)`
at `:12610`). **Two authority domains are conflated in one predicate.** This is
`RP-01 AUTHORITY_DOMAIN_CONFLATION`, located precisely and with a measured
population for the first time since it was opened.

---

#### RA-62.6 — RA-59.9 picked the wrong shape for half the population, and that is the reviewer's error

"Half-terminal front" was directionally right — one end at a terminal, one end
not — but RA-59.9 identified the non-terminal end as **interior to the carrier
edge**, when in 21 of 44 cases it sits **exactly at the carrier edge's other
vertex**. RA-60 then specified and verified a certificate for the 23-case shape,
whose gate is unsatisfiable (RA-61.6), while the 21-case shape received nothing
at all.

Three shapes, three distinct states:

1. **Interior-to-carrier** (23) — a certificate shape exists; its admission gate
   is dead (RA-61.6, RA-61.7).
2. **Junction-vertex** (21) — **no certificate shape exists**; the genuine
   domain gap (RA-62.5).
3. **Ordinal 405** (1) — no terminal contact published at all
   (`ContactPresent=0`); a separate A2b provenance defect, still not to be
   folded into either family.

---

#### RA-62.7 — The locus count collapses from ≤22 to **2**

All 23 interior-shaped cases record the **identical** probe pair, and all 21
one-hot cases record the **identical** probe pair. So 44 identities exhibit
**two** geometric configurations — not 44, and not the ≤22 RA-59.11 allowed.
RA-59.11's direction was right and the report's 39-corroboration framing was
wrong, but the bound itself was still an order of magnitude too generous.

Subset **B** (6 cases, carrier `(1,2)`, candidates 1/6, indices 15–19 and 25) is
the same junction mechanism in a different fixture, on the identical evidence
shape — `railEnd[first]=1, corner[first]=0,0`; `railEnd[second]=0,
corner[second]=0,0`. **Its vertex is not derived here and must not be assumed.**

---

#### RA-62.8 — A hypothesis formed and discarded before it entered the record

Because the front publisher cuts runs at source-edge topology changes, it was
momentarily plausible that a route could never carry ≥2 steps — which would make
RA-41's junction clauses permanently unexercisable and the RA-59 construction
recipe impossible.

Reading the accumulation refutes it. `observedSteps` is declared **once** before
the segment loop (`:12505`), pushed inside it (`:12546`, `:12566`), checked
non-empty after it (`:12672`), and assembled into a single route at
`:12684-12685`. It therefore collects **one step per run across the whole front
path**, so a front spanning both `(1,4)` and `(4,7)` **would** yield
`routeLength = 2` and **would** exercise the junction loop
(`routeSteps = first.route.oriented_steps()`, `:19096`).

**The RA-59 recipe stands.** The observed `routeLength = 1` is a fact about the
traced front, not a publisher limitation — which relocates the open question
upstream: why does the field-traced front stop at vertex 4 instead of continuing
along `(4,7)`? Recorded as the leading upstream question for A1/A2a. **Not
authorized for probing** (RA-54.7).

---

#### RA-62.9 — The predicate-separation rung survives, but its justification has shifted and its scope is re-prioritized

RA-60.5 authorized it because a *repeat* of `no-exact-terminal-corner` would be
uninterpretable. The extraction has now disambiguated the **entire** population
from logs that already existed, using `corner[]`/`railEnd[]`. String separation
therefore is no longer the rung's primary value.

Two fields that are **not** obtainable from existing logs now dominate:

- **(b) the actual one-hot vertex identity.** The probe emits `corner[v]` and
  `railEnd[v]` only for *published terminals*, so it never states which vertex
  the point actually is. That omission forced a hand derivation of the fixture's
  face table in this Review (RA-62.3). Emitting it is diagnostic-only and
  decision-neutral, and it would have made RA-62.3 unnecessary.
- **(a) `sharedBoundaryInterval` presence and exact rational ordinals** —
  RA-61.9 falsifier (i), unanswerable from any existing artifact.

The published name `M6-CP3-CB2-R4-PREDICATE-SEPARATION` is **kept** — renaming
for taste would churn a beacon already committed — but the scope is re-ordered
**(b), (a), then the string split**. Strictly decision-neutral: not one
acceptance or rejection decision may change.

---

#### RA-62.10 — Accounting, carried obligations, and the next rung

Stable ledger **66 events / 17 categories / 49 recurrences**, M6 debt **1**, CP2
**491/491** accepted, R3 **403/497** rejected (94 RED, 88 carried CP2 losses),
frozen selector **30 + 12 + 449 + 6 = 497** — all unchanged. No accepted-green
loss and no ledger credit: all 39 census identities were already RED under the
prior semantic source and the six supplementals have no accepted-GREEN baseline.
PR #8 draft/open. The handoff overwrite in RA-62.2 is an **integrity** defect and
does **not** increment the regression recurrence counter.

`R4-VIN-01` continues to apply: `570c5173…` is a new semantic source, so every
prior measurement is a baseline, never a comparand.

**`RP-01` is now located** (RA-62.5) but **not repaired** and not authorized for
repair. `RP-02` remains **unreached** — neither the network-bound consumer nor
its tamper half has executed. `RP-03` carried; this turn's extraction satisfied
it and the measuring turn before it did not.

Carried without probe: RA-60.5 (triggered, now re-scoped by RA-62.9); RA-60.6
(**confirmed by measurement**, RA-62.3); RA-60.7 encoding collapse needing a
positive discriminator; RA-60.8 comment mismatch; RA-60.9's four untested
negatives; RA-61.9's two falsifiers; the RA-58.7 A5/A6/A7 loci and `R4-OHF-02`;
the two RA-57.9 guards; **RA-41's junction/sector clauses — no longer dormant,
now the measured mechanism of 15–21 identities, recipe intact per RA-62.8**;
ordinal **405**; 34 Phase10 / seven DCEL / six CP3 identities; CP2 restorations
outside the 37; organic D1/D2/D3/D5 and A6/A7 witnesses; the odd-τ witness; the
two `SurfaceCellTracingPhase14` identities needing a separately packaged
historical executable (`cmake/DirectionalTests.cmake:554-572`).

**Next rung — `M6-CP3-CB2-R4-PREDICATE-SEPARATION`**, diagnostic-only Code +
Build, scope ordered by RA-62.9, plus the RA-62.2 gate-coverage fix as its first
item. **No acceptance behaviour may change, and neither the RA-61.9 remedy nor
any repair of `RP-01` is authorized in it.**

## `Architecture_M6_CP3_R4_Terminal_Contact_And_Gauge_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Terminal_Contact_And_Gauge_Review_Decision.md`; moved verbatim.

### M6-DEFN-R5-R4-REV — terminal contact ownership and A3/source-gauge trust boundary: Review decision

**Independent source-exact correction (M6-DEFN-R5-R4-REV):** The design choice in RA-42 is retained,
but two supporting factual claims below are superseded: `SurfaceCellRailSample::sourceFace/sourceEdge`
are raw integers, not typed source-topology credentials, and `SurfaceCellTracing.cpp:18120-18206` is
not the claimed vertex-star/rail-cut contact traversal. This Design Review does **not** by itself
prove an authenticated producer-to-front contact mapping or release R4 implementation. RA-40.1's
unconditional atlas decision remains binding; refer to the independent review record for stop gates.


**Type:** runtime-free independent producer Design Review resolving `R4-REV-01` and `R4-REV-02`.
**Verdicts:** **R4-REV-01 → the rail/front producer owns the terminal contact; `SurfaceTracePoint` cannot and
must not be used for it. R4-REV-02 → option (A): RA-40.1 stays unconditional and the legacy callers migrate.**
Frozen as **RA-42**. My earlier conditional-scoping pre-commitment is **withdrawn**. No runtime credit.

#### 1. The review's blocking findings are both correct, and its RA-38.3 ruling is accepted

The STOP was right. RA-41.2 named a witness without establishing a producer that can author it, and my Finding 3
proposed an exception to a frozen trust boundary. The review's **boundary-scope ruling is also accepted**:
RA-38.3's boundary-vertex and singleton STOP governs *multi-carrier through-junction sector transport*, which is
RA-38's subject, so it does **not** fire at a terminal contact vertex. That disposes of the hazard raised at
`M6-DEFN-R5-R4-DIAG-NEXT` without amending RA-38.

#### 2. R4-REV-01 — the trace point carries no incidence at all

This is decisive and it is not a matter of interpretation:

```cpp
struct SurfaceTracePoint {
  int face = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
};
```

(`include/directional/geometry/SurfaceCellTracing.h`.) There is **no source vertex, no source edge**, and `face`
is a **raw `int` row index**, not a `SourceFaceTopologyKey`. Two consequences:

- **The witness cannot be derived from a trace point.** Recovering "this endpoint is incident to source vertex 1"
  from `barycentric` means testing a `double` for exact zero. In a pipeline that exactifies binary64 inputs
  bit-for-bit (M4-CP-COND) and derives topology only from typed authority, inferring topological incidence from
  floating-point coordinates is an **RP-01 AUTHORITY_DOMAIN_CONFLATION**: typed authority derived from a
  non-authoritative representation. It is prohibited, not merely fragile.
- **The diagnostic is untyped.** `faceEnds=0,2|0,3` is a tuple of **raw row indices**. That is exactly why the
  component-local versus original numbering question arose at all, and why a contamination reading was plausible
  before `MeshComponents.cpp:72-116` settled it. The record must be re-emitted in typed
  `SourceFaceTopologyKey` terms.

**The authority already exists — on the rail producer, not the trace point.** `SurfaceCellRail` publishes
ordered `sourceVertices`, and `SurfaceCellRailSample` publishes `sourceFace`, `sourceEdge`, `parameter` and
`railParameter`. So the terminal source vertex (1 or 4 for carrier `(1,4)`) and the typed source incidence the
witness needs are **already computed and already published** one structure away from the consumer that cannot
see them.

This is the **fifth** occurrence of the same pattern — RA-34.3 (τ retained before the nontraversable marking),
RA-35 (per-wedge bindings before the sort/unique collapse), RA-38 (the star is traversed; only the cut was
missing), RA-40 (the atlas sits in options but not at the factory boundary), and now the rail's typed source
incidence sitting beside a consumer that reads an untyped trace point. The cure is the same: **publish or reach
what the producer already holds.** The germ itself needs no new input either: it is the arc of the A2b vertex
star after cutting the incident rails, and that star is already traversed at
`src/geometry/SurfaceCellTracing.cpp:18120-18206`.

#### 3. R4-REV-02 — option (A), and my conditional exception is withdrawn

I proposed scoping RA-40.1's atlas mandate to products carrying A3-derived values, on the premise that a product
with no rails has "nothing A3-derived to authenticate." That premise does not survive inspection of what `make`
actually receives:

- `sourceFaceBranchRotations` is a plain `std::vector<int>` — a **raw, unauthenticated gauge input**, consumed by
  A6 seam logic. I flagged it as needing explicit treatment; it in fact **refutes** the premise, because a
  rail-free product still carries unauthenticated gauge.
- `SurfaceIsolationSeamTransportCertificate` and `SurfacePeriodicHolonomy` are factory-validated **classes** with
  their own `make`, so they are not field-fabricable like the plain-aggregate `SurfaceHardRailFieldTransition`.
  That is a genuine distinction, but it establishes internal consistency, **not A3 provenance** — the same
  gauge-invariance gap one level down.

So "nothing A3-derived" is not established for an arbitrary product, and I asserted it without verifying the
surface. **Withdrawn.**

The decisive consideration is where the exception would actually apply. The 34 failures arise because a
**production** path permits null-atlas ingress (the `CrossFieldResult` overload's legacy/raw acceptance, with
`SurfaceCellTracingOptions::fieldTransportAtlas` defaulting `nullptr`). A conditional exception would let that
production path keep building phase-front products with **no A3 binding at all** whenever they happen to carry
no rails — preserving in production the exact hole RA-40 was created to close, in order to accommodate legacy
callers. Accommodating the defect is not a trust boundary.

**Option (A).** RA-40.1 stays unconditional: `make` requires a `matches_source_faces`-bound atlas always, and the
legacy callers migrate. The atlas is already available at the A4 options level and the check is cheap, so the
migration is mechanical. Two consequences are accepted deliberately rather than worked around:

- The seven DCEL failures are **fixture defects to fix, not cases to exempt.** A test fixture that is not a valid
  mesh is not a valid source authority, which is RA-40's whole point.
- `sourceFaceBranchRotations` comes **inside** the boundary: it must be validated against published source
  authority (at minimum, cardinality equal to the source face count, and values matching what the authority
  publishes). It may not remain a raw unchecked vector under a rule whose purpose is authenticating A3-derived
  input.

#### 4. RA-42 (frozen by this Review)

- **RA-42.1 — terminal contact ownership.** The terminal rail contact witness is authored by the **rail/front
  producer** from `SurfaceCellRail::sourceVertices` and the rail samples' typed `sourceFace`/`sourceEdge`, and
  published as typed authority on the endpoint certificate. The endpoint certificate must **stop reading**
  `from.face`/`to.face` for contact purposes.
- **RA-42.2 — no incidence from geometry.** Deriving source-vertex or source-edge incidence from
  `SurfaceTracePoint::barycentric`, or from any floating-point predicate, is **prohibited**. Absent typed
  incidence the certificate fails closed with a code naming that absence.
- **RA-42.3 — typed diagnostics.** Carrier, face and endpoint diagnostics are emitted in typed
  `SourceFaceTopologyKey` terms, never bare row indices. Raw-row records are not evidence of a topological claim.
- **RA-42.4 — germ derivation.** The germ is the arc of the A2b vertex star at the terminal vertex after cutting
  the incident hard rails, derived from the star traversal that already exists. Equality with the carrier's
  incident pair holds **at the contacts**, never at the trace endpoints — the exact locus of RA-39.1's error.
- **RA-42.5 — RA-40.1 unconditional.** The atlas mandate is **not** scoped or conditional. The prior conditional
  pre-commitment is withdrawn. Legacy and `CrossFieldResult` null-atlas ingress must be migrated, not exempted.
- **RA-42.6 — gauge inside the boundary.** `sourceFaceBranchRotations` must be validated against published
  source authority and may not remain unchecked.
- **RA-42.7 — RA-38.3 scope.** RA-38.3's boundary-vertex and singleton STOP governs multi-carrier
  through-junction sector transport only and does not fire at a terminal contact vertex.
- **RA-42.8 — no runtime credit.** Nothing here establishes a produced witness. The 39-row family remains one
  carrier configuration with **zero** multi-carrier instances, so RA-41.2's junction clauses stay unexercised,
  and R4's multi-carrier STOP is undischarged.

#### 5. Verification limits

Re-read from source: `SurfaceTracePoint`, `SurfaceCellRailSample` and `SurfaceCellRail` field sets;
`make`'s parameter list including `sourceFaceBranchRotations`; that
`SurfaceIsolationSeamTransportCertificate` and `SurfacePeriodicHolonomy` are factory-validated classes.
Carried from earlier turns, independently re-derived there: the component-local vertex mapping, the germ splits
at vertices 1 and 4, and the one-step `(1,5)` contact walk. **Not** established: whether those two factory
classes' own `make` binds A3 — they are therefore treated as unproven for provenance, not as authenticated.

## `Architecture_M6_CP3_R4_True_Control_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_True_Control_Review_Decision.md`; moved verbatim.

### Review decision — the true control answers the question, and it answers it more strongly than reported

**Turn adjudicated:** `M6-CP3-TB1-R4-TRUE-CONTROL` (Test + Benchmark, artifact-only).
**Disposition:** the **measurement is ACCEPTED**; **RA-57.8 is DISCHARGED**; the report's **interpretation
is AMENDED — it understated its own result**; its **classification of identity 3 is CORRECTED**; the
**carrier is now bounded to OPEN hard-rail terminal certification**; the census is **AUTHORIZED to
proceed** with one added column. Frozen as **RA-58**. No promotion, no new stable event, no 497 run, no
gate credit. Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, selector **497** —
unchanged.

Evidence frozen beside this record:
`Architecture_M6_CP3_R4_True_Control_Ledger_20261015.tsv`,
`Architecture_M6_CP3_R4_True_Control_Measured_Loci_20261015.tsv`.

#### RA-58.1 — accepted, re-derived from the artifact

Result artifact `11948572472`; the ZIP I downloaded hashes
`2b6ac34c34ea3f0dd384f5be7a55ca9c9028328639effed3c9cc3e3c9674917f`, matching the report. Receipts:
`executed=4 red=2 missing=0 postflight=true compile=false relink=false benchmarks=false selector497=false
exit=0`; `package=true source=true execution_view=true selector=true`; manifest **28 OK → 28 OK**;
harness SHA-256 `9d471c493b7d3c9c4fa5bf31916e37d9caa470a628da6c0e710f770f0c986162` matching the report
and the dispatch record. `git diff c2b3571bb..HEAD -- src include tests cmake benchmarks` is **empty**.
Each of the four logs contains **exactly one** `: Failure` line, which is what makes the locus analysis
below sound: gtest `ASSERT_*` is fatal, so every assertion preceding the reported one passed.

This turn reported its own result, closed `COMPLETE`, and named a successor. The RA-57.1 reconstruction
problem does not recur.

#### RA-58.2 — RA-57.8 is DISCHARGED, and discharged the right way

Verified in `.agents/Directional/tools/m6_cp3_r4_true_control_harness.sh`:

- non-selection now records `NOT_SELECTED`, increments `missing` and **`continue`s** — the `die` that
  aborted every later identity is gone (RA-57.8(ii));
- the final verdict is `[[ "$executed" == 4 && "$missing" == 0 && "$postflight" == true ]] || die` then
  `exit 0`. The bare `[[ "$red" == 0 ]]` tail is gone, so expected REDs no longer forge an orchestration
  failure (RA-57.8(i)), and `die 'incomplete breadth'` is retained exactly as required.

It was done in a **new one-off harness** rather than by editing the previously dispatched one, whose
SHA-256 is pinned in RA-57.8's own evidence. That is the correct call and I record it as such.

#### RA-58.3 — the decisive positive: A4 production is not universally down

Both no-interior-hard-rail identities **PASS**, and both are members of the **frozen `selector449`**:

- `SurfacePhaseFrontProductFactoryAuthority.ReorderedCellStoragePreservesTypedEdgeOwnershipAtCheckedFactory`
  — `square_fixture()`, whose builder inserts no `userHardEdges`; 0 ms.
- `SurfaceCellTypedTransportAuthority.ValidPeriodicCutRouteUsesTypedIdentity` — `cylinder_fixture()` →
  `make_committed_fixture("cylinder", false)`, no `userHardEdges`; **613 ms**, a substantial real pipeline
  run, exercising `PeriodicCut` boundary authority rather than `HardRail`.

Neither appears in the 94-row R3 RED classification, so both were among the 403 R3 PASS and **both are
still green on `953f812f`** — a positive `R4-VIN-01` datapoint. **No gate credit is claimed**: the frozen
497 did not run, and two members passing is not 497 acceptance.

#### RA-58.4 — the report understated its own result. The closed-chain arm is informative, and POSITIVE.

The report wrote: *"Both closed-chain torus identities fail, but neither raw log proves the previously
measured open-rail `no-exact-terminal-corner` predicate. Do not conflate these failure loci."* The refusal
to conflate is right, and I confirm the premise independently — **zero** occurrences of
`no-exact-terminal-corner`, `InvalidHardRailRouteCertificate` or `endpoint-1` in either torus log.

But stopping at "do not conflate" discards the finding. Read the loci against the source:

**Identity 3** (`tests/SurfaceCellTransitionQuotientTests.cpp:6018`): the sole failure is at `:6023`
`ASSERT_TRUE(run.surfaceCellContext.hasArrangement)`. The immediately preceding fatal assertion,
`:6022 ASSERT_TRUE(run.surfaceCellContext.hasTraceNetwork)`, **passed** — the trace network, which is
where the phase front and the hard-rail route certificates live, **was produced** on a torus carrying
closed-chain hard edges. The failure is downstream, at arrangement.

**Identity 4** (`:2773`): the sole failure is at `:2807` `ASSERT_NE(originalOccurrences, nullptr)`.
Everything before it passed, which includes `fixture.network.phaseFront.product()` being obtained and —
decisively — `:2795 ASSERT_NE(rotated, nullptr) << "uniform Z4 gauge rotation must be accepted"`. That
assertion guards a `SurfacePhaseFrontProduct::make` call fed `front.hardRailRouteCertificates()`,
`front.hardRailTerminalContacts()` (`:2791`) and `front.hardRailClosedChains()` (`:2792`). **The checked
factory ACCEPTED closed-chain hard-rail certificates and terminal contacts under a Z4 gauge rotation.**
The failure is downstream, in A5 `SurfaceOccurrenceComplexProducer::produce`.

So both torus identities **reached and cleared A4**, including its hard-rail certificate machinery. The
closed-chain arm did not come back negative or uninformative; it came back **green where it mattered**.

#### RA-58.5 — CONCLUSION: the carrier is bounded to OPEN hard-rail terminal certification

Assembling the measured record:

| path | hard rail | A4 production | result |
|---|---|---|---|
| square, cylinder (RA-58.3) | none | green | **PASS end-to-end**, frozen-497 members |
| torus ×2 (RA-58.4) | **closed chain** | **green, certificates accepted** | RED downstream, at A5 / arrangement |
| 3×3 midline ×4 (RA-57.2) | **open, interior terminals** | **REJECTED** | RED at `no-exact-terminal-corner` |

This is RA-57's reading-grid case 1, established: **the defect is confined to open hard-rail terminal
certification.** It also corroborates RA-57.5 from an independent direction — a **closed chain has no
terminals**, so `exact_corner` and the terminal-contact path are never taken on the torus, and the torus
A4 passes. The defect attaches specifically to the **terminal-closing requirement on an open rail**, which
is exactly the construct RA-57.5 showed is being applied to two fronts meeting **across** the rail at an
interior point.

The three RA-57.7 hypotheses — certificate too strict, pairing wrong, route truncated — all survive. **None
may be chosen.** The bound narrows *where* to look; it does not select *what* is wrong.

#### RA-58.6 — classification CORRECTED: one torus RED is already in the 94, the other has no baseline

The report tabulated both torus REDs as plain REDs. The repository says otherwise.

**Identity 3 is already one of the 94 R3 RED.** In
`Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`: `phase=focused30`, `ordinal=25`,
`first_observable=OTHER_FIRST_PREDICATE`, `R2_RED=true`, **`CP2_ACCEPTED=true`**, candidate
`R2-CAND-04`, and its recorded first diagnostic is
`tests/SurfaceCellTransitionQuotientTests.cpp:5775: Failure | Value of:
run.surfaceCellContext.hasArrangement | Actual: false | Expected: true` — **the same assertion on the
same value** as today's `:6023`, the line having shifted +248 with source evolution. It is the **single**
`OTHER_FIRST_PREDICATE` member of the 94. So this is a **reproduced carried loss inside the frozen 497**,
not news; and usefully, it is now re-measured on `953f812f` and still RED, so no vintage ambiguity
remains for it.

**Identity 4 is in no selector at all** — 0 hits in `focused30`, `focused12` and `selector449` — and 0
hits in the 94. **There is no accepted baseline, so it is not a regression**, is not ledger-eligible, and
is a first-ever measurement of an unselected identity. Recording it as an ordinary RED alongside identity
3 flattens two very different accounting states.

#### RA-58.7 — a new, separate obligation: recorded, not chased

Identity 4 shows **A5 `SurfaceOccurrenceComplexProducer::produce` returning its error alternative for a
front that A4 produced and the checked factory accepted** (`:2797-2799`, failing at `:2807`). Identity 3
shows arrangement absent on a produced torus trace network. Both belong to the **A5/A6/A7 backlog**, not
to the hard-rail carrier, and they must not be folded into it. No probe is authorized: chasing them now
would be an extra Code rung of exactly the kind RA-54.7 forbids. They are recorded here, their guards
untouched and fail-closed.

#### RA-58.8 — my reading grid was wrong, and it is the second instance of one error class

RA-57's grid read: *"Torus RED but square/cylinder PASS → the defect is **all** hard-rail routing, open
and closed."* Applied to this run — torus RED, square and cylinder PASS — it yields precisely the
**opposite** of the truth, because both torus REDs sit downstream of a **successful** hard-rail A4.

The grid conditioned on the **verdict**. The question was about the **locus**. This is the same error class
as RA-57.3, where I specified a "control" whose fixture could not discriminate: in both cases the
instrument's output did not answer the question the instrument was built to answer. Recorded under `RP-03`.

**LESSONS, minted:** *condition an instrument on the locus of failure, not on the verdict.* A pass/fail
grid over a staged pipeline is only valid if each branch also names the stage at which the verdict must
appear. The executor's instinct — refusing to conflate loci — was better than my grid, and is upheld.

#### RA-58.9 — RA-57.11's blast radius did NOT fire, and that changes the census column

Both torus REDs hang off the same `static` `torus_fixture()` singleton, which is the RA-57.11 shape. But
here **the singleton succeeds**, and the two tests then fail at genuinely different downstream loci. So a
census column recording merely *which* fixture singleton an identity hangs off would have merged these two
as one defect — wrongly. **The column must record whether the singleton itself succeeded, and the stage at
which the first failure appeared**, not just the singleton's name. RA-57.11's merge rule applies only to a
**throwing** singleton.

#### RA-58.10 — the census is authorized, scope unchanged, key extended

`M6-CP3-TB1-R4-ENDPOINT39-CENSUS` proceeds as frozen in RA-57.12, with one addition from RA-58.9: for each
identity record **the fixture singleton, whether it constructed successfully, and the pipeline stage of the
first failure** — alongside `routeLength`, `step`, `chi`, probe charts and parameters,
`closedChainPresent`, and the full `faceEnds` (kept for the record, never read as corroboration). Carrier
membership must be stated per identity against the 94-row R3 classification and against all three
selectors, so reproduced carried losses, in-gate REDs and baseline-free first measurements are never
tabulated as one kind of thing again.

#### Obligations carried, none retired

`RP-02` still open — the network-bound consumer has never been reached. `R4-OHF-02` recorded, guard
retained, no probe. `RP-01`, `RP-03` standing. RA-41's junction/sector clauses frozen **UNEXERCISED**,
together with the two guards of RA-57.9. The two Phase14 supplementals still need a separately packaged
historical executable (`cmake/DirectionalTests.cmake:554-572`). Backlog: the 39-identity carrier, 34
Phase10, seven DCEL, six CP3, the CP2 restorations outside the 37, organic D1/D2/D3/D5 and A6/A7, odd-τ,
and now the A5/A6/A7 loci of RA-58.7. The retained repair plan stands with the RA-57.5 vocabulary
amendment still outstanding.

Two process exceptions were disclosed by the executor — a bootstrap read-order violation, and a Drive
transport failure that forced direct connector writes with a retained-but-**unapplied** local patch. Both
are correctly excluded from evidence and the unapplied patch is correctly flagged as non-authoritative.
Neither bears on the measurement, which stands on its artifact hashes.

#### Successor

**`M6-CP3-TB1-R4-ENDPOINT39-CENSUS`** — unchanged, artifact-only, same package, outside the frozen 497,
with the RA-58.10 key.

## `Architecture_M6_CP3_R4_Witness_Breadth_Measurement_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Witness_Breadth_Measurement_Review_Decision.md`; moved verbatim.

### Review decision — the breadth measurement, the carrier it measured, and the control it did not provide

**Turn adjudicated:** `M6-CP3-TB1-R4-WITNESS-BREADTH` (Test + Benchmark, artifact-only).
**Disposition:** the **measurement is ACCEPTED**; its **reported turn state is CORRECTED** (the workflow
concluded `failure`, the measurement did not); the **control claim in my own prior `NEXT_TURN` is
WITHDRAWN as false on the bytes**; **RA-56.5 is RESOLVED**; the repair remains **DEFERRED** behind one
corrected control rung and the census. Frozen as **RA-57**. No promotion, no new stable event, no 497 run.
Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** — all unchanged.

Evidence files frozen beside this record:
`Architecture_M6_CP3_R4_Witness_Breadth_Ledger_20261015.tsv`,
`Architecture_M6_CP3_R4_Witness_Breadth_Measured_Predicates_20261015.tsv`,
`Architecture_M6_CP3_R4_Witness_Breadth_Execution_Boundary_20261015.txt`.

#### RA-57.1 — the measurement is accepted, and I re-derived it from the artifact rather than from a report

No TB report was written. The turn closed `IN_PROGRESS` with `Successor` pointing at itself
(`63388be98`, "pending documentation transport"). I therefore took the evidence from the immutable
result artifact directly, not from prose: run `38676433923`, artifact `11946622500` (not expired),
downloaded ZIP SHA-256 `127c77580a9e77dafb1889575b8d69bdbe0271f7a3fc8041fc6c904e9918c6a3`.

`execution-boundary.txt` reads `artifact_id=11939982141`, `source_sha=953f812f…`, `executed=4`,
`red=4`, `missing=0`, `postflight=true`, `compile=false`, `relink=false`, `benchmarks=false`,
`selector497=false`. `immutability.txt` reads `package=true source=true execution_view=true
selector=true`, and `manifest-before.txt` / `manifest-after.txt` are **28 OK / 28 OK**. The harness
(`.agents/Directional/tools/m6_cp3_r4_witness_breadth_harness.sh`, SHA-256
`db1aea68782f68196da0abf26be24f6648e9c565d305f3200ced09740aedd65a`, matching the dispatch record)
re-verifies the provider digest, the artifact digest, the package manifest, the packaged source hash
and **all four frozen selector hashes** before and after execution. `git diff a44bbf534..HEAD --
src include tests cmake` is **empty**. The prohibitions held: the measurement rung edited no source.

**The turn's product is therefore complete and valid.** What is missing is only the write-up, which
this Review supplies from the bytes.

#### RA-57.2 — 4/4 RED, four independent entry paths, one single carrier. The carrier is now MEASURED.

| # | identity | owning file | first predicate |
|---|---|---|---|
| 1 | `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` | `tests/SurfaceCellTransitionQuotientTests.cpp:9111` | `endpoint-1` |
| 2 | `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` | `tests/SurfaceCellREPackageTests.cpp:520` | `endpoint-1` |
| 3 | `SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate` | `tests/SurfaceCellsPhase10Tests.cpp:7148` | `endpoint-1` |
| 4 | `SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` | `tests/SurfaceCellsPhase10Tests.cpp:6503` | `endpoint-1` |

All four fail at `tracing/phase-front` with `InvalidHardRailRouteCertificate`, all four with
`a2bProbeFailure=no-exact-terminal-corner`, all four on source edge `(1,4)` with `faces=0,3`, all four
`locus=3`, `rail=2`, `routeLength=1`, `step=0`, `vertex=-1`, `faceEnds=0,2|0,3`,
`carrier=1 a3=1 contact=1 closedChain=0`.

Three distinct files, three distinct fixture builders, one focused-factory entry, two focused-producer
entries and **one full `remesh_from_raw_cross_field` pipeline entry**. **RA-56.8 is satisfied: this is no
longer one measured identity, it is a measured carrier.** The `A4_ROUTE_CERTIFICATE_REJECTION` reading of
RA-56.3 is confirmed by execution, not inferred from a static inventory.

#### RA-57.3 — my own control was not a control. WITHDRAWN.

My prior `NEXT_TURN` ordered identity 1 first and said, in terms: *"run this FIRST. It is THE CONTROL, on
a **different fixture**. It separates 'the rectangular hard-rail family is down' from 'A4 production is
down generally.'"* **That claim is false on the bytes and I withdraw it.**

`make_nonconstant_hard_rail_fixture` (`tests/SurfaceCellTransitionQuotientTests.cpp:776-853`) builds a
3×3 planar grid over `vertices(9,3)` / `faces(8,3)` by the same nested `y`/`x` loop as
`make_rectangular_internal_hard_feature_grid` (`tests/SurfaceCellREPackageTests.cpp:46-75`, `columns =
rows = 3`), and inserts `userHardEdges {1,4}` and `{4,7}` at `:830-831` — **the identical midline rail
chain `1→4→7` with the identical terminals `{1,7}`** that `build_rectangular_hard_rail_phase_front`
uses. It is a different *file*, a different *builder* and a different *field*. It is the **same mesh,
the same hard feature and the same rail**. It never had the discriminating power I assigned it.

This is a design error in the instrument I specified, not an execution defect: the executor ran exactly
what was ordered, ran all four as RA-56.4 required, and the harness proves it. The error is mine and is
recorded here rather than quietly amended, per `RP-03`.

#### RA-57.4 — what the rung therefore cannot establish

**All four identities run on the same 3×3 unit planar grid with the `x=1` midline hard feature.** The
breadth rung measured **one mesh through four entries**, not four meshes. It establishes that the defect
is not entry-path-specific, not fixture-helper-specific and not confined to the focused producer. It
establishes **nothing** about mesh generality, and it does **not** separate "all open hard-rail
production is down" from "A4 production is down generally." That question is still open and is now the
first thing the next rung must answer.

#### RA-57.5 — RA-56.5 is RESOLVED: the geometry is ACROSS-rail, not ALONG-rail

The emitter at `src/geometry/SurfaceCellTracing.cpp:18948` prints
`faceEnds = first.from.face, second.to.face | first.to.face, second.from.face`, and `:18939-18940` make
`currentFace` / `expectedFace` fallback echoes of the first two — RA-56.1 confirmed again. Reading the
measured `faceEnds=0,2|0,3` through that emitter:

- `first.from.face = 0`, `first.to.face = 0` — the first front begins and ends **inside face 0**;
- `second.from.face = 3`, `second.to.face = 2` — the second front begins **in face 3**.

On this mesh `face 0 = (0,1,4)` and `face 3 = (1,5,4)` are exactly the two faces incident to edge
`(1,4)` (`edge[0]=1,4:faces=0,3`), i.e. the two sides of the rail. The paired probes confirm it:
`a2bProbeFrom` is in face **0**, `a2bProbeTo` is in face **3**, and both resolve to the same point on
`(1,4)`.

**The two fronts approach the rail from opposite faces and meet at a shared interior point of it.** They
are not two collinear intervals running along the rail. The retained repair plan's prescription — *"ordered
rail interval/face-side ownership"* — presumes the along-rail frame and is therefore the wrong vocabulary.
**It must be amended before `M6-CP3-CB1-R4-WITNESS-REPAIR` is re-entered.** This was the RA-45.2 category
error RA-56.5 was raised to prevent; it is now caught before any code was written against it.

#### RA-57.6 — the failure is field-independent and transition-independent

Identity 1 runs a **non-constant** field (`constant_xy_field` with the `centerX > 1.0` patch rewriting
faces 2, 3, 6, 7 — face 3 is one of the two rail faces) and reports `edge[0]=1,4:faces=0,3:**chi=3**`.
Identities 2–4 run a constant field and report **`chi=0`** on the same edge. The A3 transition index
across the rail differs by 3 and **the failure is byte-identical**. Identities 1 and 2 pair at interior
parameter **0.2**; identities 3 and 4 at **0.25**. Same failure.

Two different fields, two different A3 transitions, two different interior parameters, identical
rejection. **The defect does not depend on the field, on the transition, or on where along the rail the
fronts meet — only on the fact that they meet anywhere other than a terminal corner.** Any repair
proposing a tolerance, a parameter special case or a transition-conditioned branch is already falsified.

**Second-order hazard, recorded not chased:** identity 1/2's two charts report the shared third
barycentric as `0x1.9999999999999p-3` and `0x1.9999999999998p-3` — **one ULP apart**. A replacement
certificate that demands bit-exact agreement of the two charts' coordinates would fail here exactly as
`exact_corner` does now. The correct instrument is the exact rational parameter on the shared source
edge, not a float comparison in either chart.

#### RA-57.7 — three live hypotheses remain, and `routeLength=1` promotes the third

`routeLength=1` with `step=0` in **all four** means every failing route is a **single step**. A genuine
route from an interior rail point to a whole-rail terminal would in general be longer. The hypothesis
set is therefore:

- **(a) the certificate is too strict** — the pairing is correct and an interior shared rail point ought
  to be certifiable by exact rational parameter rather than one-hot corner;
- **(b) the pairing is wrong** — these two fronts should never have been offered as a terminal-closing
  pair;
- **(c) the route is truncated** — the route should have continued to a terminal and stopped at step 0.

`routeLength=1` is evidence for (c) and it was not previously on the list. **None of the three may be
chosen now.** Choosing before the census is the RA-45.2 category error; RA-57.5 only removed a fourth,
wrong, frame.

#### RA-57.8 — two design defects in the measurement harness

**(i) A measurement rung must not fail its workflow on RED.** Line 85 is a bare `[[ "$red" == 0 ]]` as
the script's last statement, so four expected REDs set exit 1, the `test_benchmark / runtime` job
concluded `failure`, and the turn was left `IN_PROGRESS` with its product unreported even though
`executed=4 missing=0 postflight=true` and every immutability receipt passed. RED **is** the product of a
triage rung. The orchestration verdict must come from `executed`, `missing` and `postflight` only; the
RED count belongs in the ledger, which already carries it. Line 84's `die 'incomplete breadth'` is
correct and stays.

**(ii) `die` on non-selection re-introduces the early stop RA-56.4 removed.** Line 68 aborts the whole
loop with exit 90 if `picked != 1` for any identity, so one mistyped or retired identity would silently
cost every identity after it — the same failure mode as stop-at-first-RED, through a different door. It
must record `NOT_SELECTED` for that ordinal and `continue`.

#### RA-57.9 — RA-52.6 now has a measured violation

Identity 4 is the retained attempt that RA-52.6's forward reading — *a retained guard needs a retained
attempt* — kept alive. It is RED at its `Produced` precondition
(`tests/SurfaceCellsPhase10Tests.cpp:6506`), so the retained attempt **cannot presently run**, and the
guard it was retained to exercise is therefore unexercised at runtime. Identity 1 is the same shape: the
test body throws inside `nonconstant_hard_rail_fixture()` on its first line, so the forged-germ rejection
the test exists to prove is never reached. **Two guards are now known-unexercised for the same upstream
reason.** They stay retained and fail-closed; nothing is retired. This is recorded, not chased.

#### RA-57.10 — a gtest suite name is not unique across targets

`SurfaceCellPipelinePhase20` has members in **both** `tests/SurfaceCellREPackageTests.cpp` (in
`directional_surface_cell_producer_tests`, `cmake/DirectionalTests.cmake:83`) and
`tests/SurfaceCellPipelinePhase20Tests.cpp` (in the `DIRECTIONAL_BUILD_HISTORICAL_TESTS`-gated
`directional_surface_cell_historical_tests`, `cmake/DirectionalTests.cmake:571`). A bare `Suite.*`
filter denotes **different sets in different binaries**. The fully qualified `Suite.Name` citation rule
adopted after RA-56 held here and must continue to; a suite-level filter must never be used to name an
obligation.

#### RA-57.11 — a throwing fixture singleton has a blast radius

`nonconstant_hard_rail_fixture()` (`tests/SurfaceCellTransitionQuotientTests.cpp:855-858`) is a
`static` function-local singleton. It throws. **Every** consumer goes RED with it — at least
`:2837`, `:2863`, `:3890`, `:8813`, `:8858`, `:9112`, plus `make_nonconstant_hard_rail_fixture(true)` at
`:2935`. This is consistent with the carrier inventory's 19 Quotient-owned members and predicts that a
single upstream repair clears them together. It also means the census must report **which fixture
singleton** each failing identity hangs off, or it will count one defect many times and read it as many
defects.

#### RA-57.12 — the census design is amended

RA-56 prescribed deciding the along/across question "from `faceEnds`". RA-57.5 has now decided it, and in
doing so showed that `faceEnds` is **an echo set with low discriminating power**: it was byte-identical
across two mesh families, two fields, two transitions and two parameters. The census must therefore key
on fields that actually vary — `routeLength`, `step`, `chi`, the probe charts and parameters, the owning
fixture singleton, and whether `closedChainPresent` is 0 or 1 — and must not be read as corroboration
when `faceEnds` repeats.

**Lesson, minted:** *a signal that never varies is not a measurement.* Four identical `faceEnds` across
four entries looked like four confirmations and were one echo printed four times.

#### Obligations carried, none retired

`RP-02` still open — the network-bound consumer has still never been reached. `R4-OHF-02` recorded, guard
retained, no probe. `RP-01`, `RP-03` standing. RA-41's junction/sector clauses frozen **UNEXERCISED at
runtime**, now joined by the two guards of RA-57.9. The two Phase14 supplementals still require a
separately packaged historical executable (`cmake/DirectionalTests.cmake:554-572`) and must not be
bundled into a measurement rung. Backlog beyond the census: the 39-identity carrier, 34 Phase10, seven
DCEL, six CP3, the CP2 restorations outside the 37, organic D1/D2/D3/D5 and A6/A7, odd-τ. The retained
repair plan `Architecture_M6_CP3_R4_Witness_Interval_Terminal_Recovery_Code_Build_Plan.md` stands except
for the interval vocabulary RA-57.5 invalidates.

#### Successor

**`M6-CP3-TB1-R4-TRUE-CONTROL`** — artifact-only, no rebuild, same package. The control I failed to
specify, now specified from the bytes: identities whose fixtures carry **no interior midline hard rail**,
and one whose rail is a **closed chain** rather than an open one. All are already inside
`directional_surface_cell_producer_tests`, so the rung is free. Only after it may
`M6-CP3-TB1-R4-ENDPOINT39-CENSUS` be read correctly, then `M6-CP3-TB1-R4-CARRIER-REV`, then the retained
and amended `M6-CP3-CB1-R4-WITNESS-REPAIR`.

## `Architecture_M6_CP3_R5_Junction_Carrier_Authority_Spec_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R5_Junction_Carrier_Authority_Spec_Review_Decision.md`; moved verbatim.

### RA-68 — `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` Review Decision

**Turn reviewed:** `M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` (definition only)
**Verdict:** **ACCEPTED.** One understated-scope charge, minor. No open REVIEW_BLOCKER. No promotion,
no stable event, no regression recurrence, no gate credit. **Neither repair shape is admitted; the
turn reached the strongest outcome available to it by refusing to pick one.**
**Date:** 2026-10-15

Everything below was re-derived from repository bytes and immutable artifacts.

---

#### RA-68.1 — The specification read the measured bytes, and that is verifiable by tree object

The spec reasons about source read at HEAD while citing a measurement taken at `5be5e123e`. That is
only sound if the bytes did not move. They did not: `src`, `include` and `tests` are **tree-identical
at `5be5e123e`, at the entry commit `825a04bc8` and at HEAD** —
`src=fd09300ba38b10dfea728c8c3f7c4ed6b732c89c`,
`include=790328c2bcffe29db5366ea1193cf0ab6d8cba58`,
`tests=cbef8d5ec448edb4c048b9058c7a0bd10a32b8af`. The spec's own phrasing ("GitHub commit
comparison") understates what is true; the tree objects settle it outright.

The R5 snapshot is also real. Artifact `12010485442` at `3d1b413a8` (run `38814059292`): **outer ZIP
SHA-256 recomputed on the downloaded bytes as
`020bc02980fb661d4b4bdc0f26de3b74c91887a6dad43a100ab3391bea4dc62e`, matching the provider digest;
`SHA256SUMS` carries 5,648 entries; `shasum -a 256 -c` over the extracted tree returns 5,648 OK, 0
BAD.** The RA-67.10 practice — snapshot the pre-image, verify the edit against it — was carried
forward without being told to. Recorded as credit.

#### RA-68.2 — Mandate 1 discharged: the derivation is independent and it confirms

The spec re-derives RA-67.6 from the premises rather than adopting it, and states the confirmation
with the correct narrow scope: the **first rejection** for the 21 measured junction identities, not
an explanation of all 44 REDs and not a repair. Every cite checks out against the bytes:

- `tests/SurfaceCellsPhase10Tests.cpp:266-273` inserts the two hard edges `(1,4)` and `(4,7)`
  sharing vertex 4 — verified.
- The face table at `:223-263` gives edge `(1,4)` faces `{0,3}` and edge `(4,7)` faces `{4,7}` —
  verified.
- `SurfaceHardRailFieldTransition` at `include/directional/geometry/SurfaceCellTracing.h:1481-1489`
  is edge-keyed with exactly two face keys and one `QuarterTurn` — verified (the spec's `:1481`
  correctly includes the doc comment; my own earlier `:1482` omitted it).
- The producer at `src/geometry/SurfaceCellTracing.cpp:18939-18973` publishes one edge and that
  edge's two incident faces into `hardRailFieldTransitions` — verified.
- `find_carrier` at `:19097-19105` selects by `item.edge == edge`; `oriented_carrier` at
  `:19106-19114` matches the complete face pair in either order — verified.

The spec also states the distinction that matters: the first-reject mechanism is established, while
**neither the intended sector, nor a truncated route, nor a valid correction** is. **RA-64.6 remains
withdrawn** and the spec says so in its own text, unprompted.

#### RA-68.3 — Mandate 2 discharged, and the producer test is applied with real teeth

The census at §2 names, for each required fact, the existing published contract, its producer and the
limit that bears on admissibility. The entries check out. The decisive one is new and it is better
than my own argument:

**`SurfaceHardRailRouteJunctionCertificate` exists — and is ordered too late to authorize
admission.** The type is real (`SurfaceCellTracing.h:1512-1516`: `SourceVertexId junction` and two
`sectorPaths`), and it is a member of `SurfaceHardRailRouteCertificate` (`:1518-1526`). But the
construction at `src/geometry/SurfaceCellTracing.cpp:19525-19530` opens with
`auto previous = firstEndpoint->terminalCarrier;` and the publication at `:19728-19731` dereferences
`*firstEndpoint, *secondEndpoint` — both reachable only past the rejection branch at
`:19352-19360`, where `if (!firstEndpoint || !secondEndpoint)` returns. **The nearest candidate
witness for gate C is produced only after the admission it would have to authorize.**

At RA-65.5 I suspended gate C on the ground that no producer publishes a vertex-star witness. The
spec finds the nearer and sharper statement: a producer of something very like it *does* exist, and
it is unusable because of its position in the order. That is a stronger objection than mine and it
survives the obvious rebuttal that someone will eventually make — "but the junction certificate
already exists." **Gate C stays SUSPENDED, now on ordering as well as nonexistence.**

#### RA-68.4 — Mandate 3 discharged: the falsifiers are concrete and the populations are exact

The spec names the separating population by TSV index and the controls by TSV index. I re-derived
both from the immutable `endpoint-chart-harvest.tsv` and they are **exactly right**:

- junction (`carrier-orientation`): `12-25, 34, 35, 36, 39, 40, 42, 43` — **21**
- interior (`not-same-interior-carrier-point`): `1-11, 26-33, 37, 38, 41, 44` — **23**

The historical-ordinal list (`115-117, 122, 130, 132, 134, 137, 139-143, 150, 404, 406, 407` plus
four supplemental) is 17 + 4 = 21, consistent with the 17 historical and 4 supplemental junction rows
I measured at RA-67.

**The `routeLength=1` obstruction is real.** I verified it against the raw logs: `routeLength=1` in
every log, with no other value anywhere. A one-step route carries a single carrier, so a mechanical
split of that route at its endpoint cannot manufacture a second carrier. The naive split-only
variant of shape A is **falsified by measurement**, not by argument.

#### RA-68.5 (CHARGE, minor — understated scope) — `routeLength=1` holds for all 44, not only the 21

The spec writes "In all 21 raw logs `routeLength=1`". It is true, and it is true of **all 44**,
including the 23 controls. Two consequences the spec does not draw:

1. **The obstruction is stronger than claimed.** Every measured identity, junction and interior
   alike, carries a one-step route. The naive split is impossible across the whole measured
   population, not only where the carrier mismatches.
2. **The 23 do not control for this property.** They remain valid negative controls for the
   attachment-membership partition — that is what they were nominated for — but a control that
   shares the property under test cannot discriminate on it. A later turn must not cite the 23 as
   evidence that `routeLength=1` is junction-specific, because it is not.

Charged as understatement, not error. Corrected here rather than returned.

#### RA-68.6 (NEW) — A boundary hard rail publishes no carrier at all

The census does not surface this, and it bears directly on shape B. The producer at
`src/geometry/SurfaceCellTracing.cpp:18939-18941` reads

```
const auto incident = sourceEdges.find(edge);
if (authoritativeOptions.fieldTransportAtlas == nullptr ||
    incident->second[1] < 0) continue;
```

so **any hard edge with only one incident face is skipped entirely** — no
`SurfaceHardRailFieldTransition` is published for it. A hard rail running along the mesh boundary
therefore has no carrier record, and `find_carrier` returns `nullptr` for it rather than returning a
record that fails to match.

For shape B this is load-bearing: a vertex-star certificate at a junction on the mesh boundary would
have a spoke with **no carrier to attest**, so any vertex-aware admission must handle carrier
*absence* as a distinct case from carrier *mismatch*. The measured 21 are all interior junctions, so
nothing in the harvest exercises it. Recorded as a locus; **no repair authorized.**

#### RA-68.7 (NEW) — The published face pair is canonically ordered, which closes an obvious objection

`src/geometry/SurfaceCellTracing.cpp:18968-18970` computes `const bool reverseCanonical = to < from;`
and pushes the smaller key first. So `record.firstFace` is always the lexicographically smaller of
the two face keys. Two things follow, both favourable to the derivation:

- `oriented_carrier`'s two-branch test is **complete** — it tries both orders, and the stored order
  is canonical, so no orientation case is unreachable. There is no hidden ordering bug behind the
  refusal.
- The measurement is consistent with the canonical form: `CarrierFirstFace=(0,1,4)` is indeed less
  than `CarrierSecondFace=(1,4,5)`. The record read in the harvest is the real published record.

This removes the cheapest available rebuttal to RA-67.6 — that the comparison merely got the
orientation wrong — and it removes it from the bytes rather than by assertion.

#### RA-68.8 — Mandate 4 discharged, and the non-decisions are stated without hedging

§4 declines to select A or B, to define a type, to approve a route extension, to authorize splitting,
to modify any predicate, or to classify sectors from row numbers. It explicitly declines to
resurrect RA-64.6 or RA-61.9, to resume gate C, to treat the 21 as two mechanisms, to promote `RP-01`
to repaired, or to claim `RP-02` reached. **The turn was asked to apply a test that could make both
candidates inadmissible, and when the test did exactly that, it reported the result instead of
softening it.** That is the fourth mandate working as intended and the **fifth** consecutive turn
satisfying `RP-03`.

The spec also absorbed RA-67.9 — my charge that the previous turn harvested the interval fields and
left them unexamined — into its own §1: "All 44 have reciprocal exact interval ordinals, proving that
this condition does not distinguish the failures." Charge answered one rung after it was made, in
the turn's own analysis rather than in a reply.

#### RA-68.9 — What the next measurement must settle, and why it is not a definition question

Both repair shapes are inadmissible for want of a producer, so the obvious next move is a
producer-definition turn. **It is the wrong next move, because one measurement can still change which
producer is needed, and it is cheap.**

Put RA-68.4 beside RA-65.10. The route has **one** step, and by RA-65's reading of
`assign_open_front_boundary_authority` (`:12481-12692`) the publisher cannot shorten a route — at a
topology change it either publishes a second step (`:12642`) or hard-rejects (`:12645`,
`:12669`). So a one-step route means the traced path crossed exactly one source-edge topology:
edge `(1,4)`. But the endpoints are not taken from the path. They are taken from the corner array —
`edge.from = cell.corners[side]`, `edge.to = cell.corners[(side+1)%4]` at `:13034-13035`,
`:14774-14775`, `:17345-17346` — and **nothing reconciles the corner array against the path's face
set** (RA-65.10, recorded and never since touched).

The measurement puts `to` in face 7, which is incident to edges `(4,7)`, `(7,8)` and `(4,8)` and
**not** to `(1,4)`. If the route's single step is `(1,4)`, then the endpoint the certificate is being
asked about lies off the path the route describes. That would make this a **corner/path
reconciliation defect at A4**, upstream of the consumer, and neither shape A nor shape B would be the
right family: no vertex-star certificate is needed to admit an endpoint the route should never have
been paired with.

**This is a prediction, and it is falsifiable at a named rung.** The prediction: the route's step
edge set will contain no edge incident to the `to` endpoint face. The falsifier: if the route's step
edge set *does* contain an edge of face 7, the reconciliation hypothesis is wrong, the corner array
and the path agree, and the producer-definition turn becomes the right next move after all. Either
outcome is decisive, and the observation costs a handful of rejection-only fields in a probe that
already exists.

**Nothing here revives RA-64.6.** That claim was that the publisher *truncated* a route; this says
the publisher may have published a correct route for its path and been handed an endpoint from
somewhere else. Different producer, different defect, and still unmeasured. It is recorded as a
prediction with its provenance stated (RA-61.5) and its observation rung named (RA-64.12), not as a
finding.

#### RA-68.10 — Beacon, documents and scope

Documents only: `src`, `include`, `tests`, `benchmarks`, `cmake`, `.github` and every selector are
untouched. All five documents the turn edited are **pure insertions, zero deletions** — handoff +12,
`TODO.md` +8, `ORIENTATION.md` +6, root `CHANGELOG.md` +4, `.agents/Directional/CHANGELOG.md` +4.
Floors clear before this Review's prepends: tracker 13,620 / 657 / 13 occurrences; handoff 4,639 /
312; root changelog 1,874 / 239; orientation 3,416 / 111.

Beacon `Status: COMPLETE`, six fields, `Resumed at:` and `Ended at:` populated, `Successor: UNKNOWN`
**with reasoning carried in the owning document** — "no successor ID is manufactured" at spec line 60,
repeated in `TODO.md`. The RA-63.13 shape, **no defect**. `Successor:` was not self-named while the
turn was in progress, which is the RA-67.11 correction applied.

**The tracker was not updated, and that is correct** — a definition turn produces no regression
evidence. It is updated by this Review.

#### RA-68.11 — Accounting

Ledger **66/17/49**, debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected, frozen selector
**30+12+449+6 = 497** — unchanged. No ledger credit, no promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no binary executed. `R4-VIN-01` stays armed:
`5be5e123e` is the semantic source; `11976790988` and `11967601999` are **baselines, never
comparands**; the 44 RED remain the baseline for `16c3134c0` alone, **candidate / non-stable**.

`RP-01` **measured, mechanistically derived, and now bounded on both repair families — code still
unauthorized**; `RP-02` **UNREACHED**; `RP-03` satisfied a **fifth** consecutive turn; `PROCESS-01`
discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED (RA-65.5), now on
ordering as well as nonexistence (RA-68.3).**

#### RA-68.12 (LESSON) — An inadmissible answer is a result

The turn was asked to apply a test that both candidates could fail, and both failed it. The value of
the rung is precisely that it closed two doors without opening a third, and said so plainly instead
of promoting the less-bad option. A definition turn that returns "neither, and here is the witness
each one lacks" has advanced the work further than one that picks a winner it cannot justify.

#### Disposition

`M6-CP3-DEFN-R5-JUNCTION-CARRIER-AUTHORITY-SPEC` — **ACCEPTED**. Successor:
**`M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE`**, a compile-only, rejection-only diagnostic turn.
The producer-definition turn the spec points to is **deferred behind it**, because RA-68.9's
observation can still change which producer is needed.

## `Architecture_M6_CP3_R5_Route_Path_Reconciliation_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R5_Route_Path_Reconciliation_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R5 route/path reconciliation (rungs 8 and 9)

**Review turn:** `M6-CP3-R5-ROUTE-PATH-RECONCILIATION-REV`
**Adjudicated:** `M6-CP3-CB5-R5-ROUTE-PATH-RECONCILIATION-PROBE` (rung 8) and
`M6-CP3-TB5-R5-ROUTE-PATH-RECONCILIATION-HARVEST` (rung 9)
**Frozen amendments:** RA-69 (rung 8), RA-70 (rung 9)
**Verdicts:** both **ACCEPTED**. RA-69 carries one charge; RA-70 carries two.
**Review window:** 2026-10-16T01:00:12Z — 2026-10-16T01:48:30Z
**Semantic source:** `a143af264bc8b33f0e1b2f8def16b2479b53d5fc` (new — `R4-VIN-01` re-arms)

---

#### RA-69 — rung 8, the route/path probe

##### RA-69.1 Decision neutrality is verified structurally, not asserted

The requirement was that the emission sit inside the rejection branch and change nothing
reachable from acceptance. Verified by brace accounting over
`src/geometry/SurfaceCellTracing.cpp`, not by reading the patch's intent:

| anchor | depth | content |
|---|---|---|
| `:19360` | 1 | `if (!firstEndpoint \|\| !secondEndpoint) {` |
| `:19459` | 2 | last pre-existing probe line |
| `:19501` | 1 | end of the inserted lambda |
| `:19566` | 0 | rejection branch closes |
| `:19567` | 0 | `std::vector<SurfaceHardRailRouteJunctionCertificate> junctions;` |

The 42 inserted lines are strictly inside a branch that closes before the junction
certificate is constructed. `git show --numstat` reports `42 0` on one file. **No
acceptance path can observe the probe**, which is the property that makes the measurement
admissible at all.

##### RA-69.2 The only control flow in the insertion is lambda-local

`return item.id == edge.filledCell;` is the `std::find_if` predicate; `return;` exits
`append_traced_faces`. Neither leaves `build_surface_cell_network`. Nothing in the
insertion writes `phaseFrontState`, mutates a certificate, touches a predicate, or
constructs a rejection string.

##### RA-69.3 Absence is reported as absence

The turn was told that a field it could not reach must be emitted empty and named, never
synthesised as `0`. It emits three distinct sentinels — `missing-cell` when the owning
cell is not found, `missing-side` when `filledSide` is outside `[0,4)`, and `none` for an
empty traced set — and the harness treats each as non-numeric and therefore incomplete.
**RA-66.4's silent omission is not repeated.**

##### RA-69.4 The compile chain is closed by content

Every link re-derived independently, none accepted from the record:

| link | verified value |
|---|---|
| snapshot run `38828612903` | `conclusion=success`, `head_sha=48ba0b6b1` |
| snapshot artifact `12016346107` | digest `174cb54bb46b…`, matches |
| `48ba0b6b1` vs `5be5e123e` | `src`/`include`/`tests` **tree-identical** |
| probe commit `a143af264` | `src` changes, `include`/`tests` byte-identical |
| cpp blob at `a143af264` | `c12910dcc15a01e21d074039cc65d79c2234a5a6` |
| dispatcher commit `ffcaa5933`, run `38829147491` | `conclusion=success` |
| compile artifact `12015849679` | ZIP SHA-256 **recomputed** `92a014a6d0bc…`, matches |
| package manifest | **28 OK / 0 BAD** |
| `metadata/source-commit.txt` | `a143af264bc8b33f0e1b2f8def16b2479b53d5fc` |
| `metadata/command-boundary.txt` | `runtimeExecution=false`, `exactArithmeticBackend=GMP` |
| preflight / build exit codes | `0` / `0` |
| five `source-status-*` snapshots | all **empty** — clean tree at every stage |
| eight targets in `compiled-targets.txt` | present |
| GMP link line | links both `libgmpxx.so` and `libgmp.so` |

**The decisive link, done by bytes rather than by trust:** the packaged
`src/geometry/SurfaceCellTracing.cpp` hashes to
`16615b23581a7ab2e66199f52a8a2c9c1d4245549ff6f719a4c073dc06137b99`, which equals the
`a143af264` blob **and** the current `HEAD` blob. The packaged
`tests/SurfaceCellsPhase10Tests.cpp` hashes to `7c88a51373ca…`, equal to `HEAD`. The
binary rung 9 executed was therefore built from exactly the bytes now in the repository,
against the unmodified fixture.

##### RA-69.5 CHARGE — chat-retained evidence is not provenance

The record states that Google Drive patch staging failed twice with
`container_session_unavailable`, that a GitHub Git-objects API fallback pushed the blob by
expected-parent non-force ref update, and that "a downloadable preservation patch is
retained in this chat."

The transport irregularity itself is **settled harmless by content** at RA-69.4: whatever
route the bytes travelled, the bytes that landed are the bytes that compiled and the bytes
in the repository. That is the correct way to close a non-standard transport.

What is charged is the citation. Under RA-61.5 a claim is provenanced when it is
re-derivable from repository bytes or an immutable artifact. **A chat attachment is
neither.** It is not addressable, not hashable by a later reviewer, and not retrievable
from the repository or the artifact store. Offering it as a preservation store invites a
successor to accept a byte sequence that no longer has a referent. The sentence should
have read that the patch bytes were deliberately not committed and that the landed blob is
the preserved object — which is true, and sufficient.

##### RA-69.6 Informational, not charged

The probe performs a linear `std::find_if` over `phaseFrontState.cells` per rejected edge,
so its cost is O(rejections x cells). It is diagnostic-only code inside a rejection
branch and is not authorized for optimisation; recorded so a later turn does not inherit
it into a non-diagnostic path.

##### RA-69.7 The READ_MODE disclosure is credited, not charged

The record self-discloses that the first repository reads preceded an explicit
`READ_MODE=snapshot` selection, contrary to `TOOL_USE_CONSERVATION_POLICY.md`. This
Review adjudicates code, design and architecture, not procedure. The disclosure is noted
and **credited as disclosure**; no charge, and it establishes no semantic result either
way.

---

#### RA-70 — rung 9, the harvest

##### RA-70.1 The instrument is genuine and in the right identity domain

The incidence test is not a string comparison. `face()` admits only a three-element
vertex set; each route step becomes a two-element set; and the test is

```python
hit_to = sum(bool(t and e <= t) for e in edges)
```

a **subset test of the route edge's vertex pair against the ToAttachment face's vertex
triple** — which is exactly what "an edge is incident to this triangle" means. The path
faces are parsed separately by `rows()` as row indices and compared only against row
indices (`rt in pt`). Carrier edges are derived as `c & d` with `len(carrier)==2`
asserted. **Each comparison is made inside one index domain**, which is the RA-67.13
discipline applied correctly in the instrument.

##### RA-70.2 Fail-closed, and the RA-67.8 charge is genuinely discharged

`complete` requires `n>0`, `len(actual)==n`, contiguous step indices
`indices==list(range(n))`, every edge of size 2, all eight derived values present, and
`len(carrier)==2`; `if missing: raise SystemExit(...)` terminates the harvest. The
RA-67.8 charge — first-match parsing with no occurrence count — is closed on the route
fields by construction: `probe_lines` collects **every** emission, and
`occurrences_consistent` requires each one to agree with the first and the count to match
the step list. `probe_occurrences` is now a column.

**The charge was consequential.** Two identities emit three times, and the first harness
aggregated them into one route. That produced dispatch `38831159326`, independently
confirmed `conclusion=failure`, which the turn refused to accept and disclosed — when the
successful retry would have concealed it entirely. **RP-03 is satisfied a sixth
consecutive turn.**

##### RA-70.3 The residue, bounded and then measured

`get()` remains `re.search` — first match only — for the nine non-route fields, with no
cross-occurrence consistency check. `hit_to` therefore compares a first-match `t` against
a consistency-checked `edges`: mixed provenance.

Bounded, then measured rather than argued:

- `probe_multiplicity=[(1, 42), (3, 2)]` — only indices 27 and 41 emit more than once.
- Both are **controls** (`not-same-interior-carrier-point`, `hit_to=1`), so **no junction
  case is exposed to first-match parsing at all**.
- In both logs, `grep -o 'a2bProbe.*' | sort -u | wc -l` returns **1**: all three
  emissions are byte-identical across the **full** payload, not merely the route fields.

The residue is measured harmless. It remains open as a narrowing to close.

##### RA-70.4 Artifact integrity, re-derived

| check | result |
|---|---|
| result artifact `12017109271` | **recomputed** ZIP SHA-256 `e394c4deab99…`, matches provider digest; 81,938 bytes |
| internal manifest | **51 OK / 0 BAD** |
| `manifest-before` vs `manifest-after` | **byte-identical** |
| `raw/` log count | **44** |
| log artifact `12017213842` | digest `7218f11252…`, matches |
| `execution-boundary.txt` | `planned=44 executed=44 red=44 missing=0 postflight=true exit=0`, `compile=false relink=false benchmarks=false selector497=false` |
| `immutability.txt` | `package=true source=true execution_view=true selector=true` |
| harness SHA-256 | `64a6bb67a02e…`, equal at working tree and executor commit `c46615bcc` |
| run `38831615391` | `conclusion=success`, `head_sha=fab558a61` |

##### RA-70.5 The partition, re-derived from the TSV

Independently recomputed from `route-path-reconciliation.tsv` — exactly three tuples,
44 rows, all `COMPLETE`, `a2bProbeRouteStepCount=1` and
`a2bProbeFailure=no-exact-terminal-corner` universal:

| n | first failing condition | route step | fromFace | toFace | path1 | path2 | hit_to | hit_from |
|---:|---|---|---:|---:|---|---|---:|---:|
| 23 | `not-same-interior-carrier-point` | `1,4` | 0 | **3** | `0` | `3` | **1** | 1 |
| 15 | `carrier-orientation` | `1,4` | 0 | **7** | `0` | `3` | **0** | 1 |
| 6 | `carrier-orientation` | `1,2` | 0 | **7** | `0` | `3` | **0** | 1 |

`hit_to` separates the populations **perfectly and without exception**: 0 in all 21
junction cases, 1 in all 23 controls.

##### RA-70.6 RA-68.9 is CONFIRMED — the falsifier was not observed

The prediction was that the route's step edge set would contain no edge incident to the
`to` endpoint face. Measured: in **21 of 21** junction cases it does not, and in **23 of
23** controls it does. The named falsifier did not occur in any case.

##### RA-70.7 CHARGE — the result is under-claimed, and the discarded half is the half that localizes it

The report states that the second path traverses row 3 while the paired junction corner
lies in row 7. True, and incomplete. Two measured facts it does not state:

1. **`FirstPathFaces=0` and `SecondPathFaces=3` are identical in all 44 rows**, controls
   and failures alike.
2. **`hit_from=1` universally** — the `from` endpoint is correctly incident in every case.

Together these are the strongest available form of the finding. Because the traced path,
the route, the step count, the carrier edge and the `from` endpoint are **measurably
identical between the populations that pass incidence and the populations that fail it**,
the tracer, the route publisher, the carrier producer and the `from` corner are all
exonerated by the same measurement. The defect is isolated to **one field, on one side**:
the `to` corner's `face`. A report that gives only the difference and not the agreement
discards the half of its own evidence that performs the localization. This is the same
category as RA-67.9 and is therefore a **repeat**.

##### RA-70.8 CHARGE — one edge printed in two index domains, one rung after that lesson was frozen

The report's table presents three populations and two "One-step route topology key"
values, `(1,4)` and `(1,2)`, inviting the reading that two distinct route topologies are
in play. Its own instrument disagrees:

```
first_rejection_membership_to_incidence=[(('carrier-orientation','one',0), 21),
                                         (('not-same-interior-carrier-point','both',1), 23)]
```

**Two** tuples, with the 21 undivided. And the RA-67.5 first-appearance compaction
(`4→2, 2→4, 7→6, 6→7`) maps every measured triple of the 6-case onto the 15-case exactly:

| field | 15-case | 6-case | under compaction |
|---|---|---|---|
| `a2bProbeFromAttachment` | `0,1,4` | `0,1,2` | ✔ |
| `a2bProbeToAttachment` | `4,7,8` | `2,6,8` | ✔ |
| `carrier_edge` | `1,4` | `1,2` | ✔ |
| route step | `1,4` | `1,2` | ✔ |

All four map under one bijection; every other column already agreed, and both populations
are the same suite `SurfaceCellAuthorityContractCutover`. **One phenomenon, two vertex
index domains** — RA-67.5 confirmed a second time, now on fields that did not exist when
it was derived, which is independent corroboration rather than restatement. RA-70.8
charges that **RA-67.13, frozen one rung earlier, was not applied at the one place where
it changes a reader's count.** The report does add a careful row-versus-triple paragraph,
so the discipline was understood and then not carried to the table.

##### RA-70.9 The mechanism, re-derived from fixture bytes

From `tests/SurfaceCellsPhase10Tests.cpp:223-273`, for component 0 the emitted faces are
`f0=(0,1,4) f1=(0,4,3) f2=(1,2,5) f3=(1,5,4) f4=(3,4,7) f5=(3,7,6) f6=(4,5,8)
f7=(4,8,7)`, and the two user hard edges are `(1,4)` and `(4,7)`, sharing vertex 4.
Therefore edge `{1,4}` is incident to faces `{0,3}` and edge `{4,7}` to faces `{4,7}`.

- The route's single step is `{1,4}`; the traced boundary paths visit exactly `{0}` and
  `{3}` — **precisely the two faces of the crossed edge**. The tracing is correct and
  complete.
- The corner array declares the `to` endpoint in face 7 `= (4,8,7)`, which is incident to
  the **other** hard edge `{4,7}` and shares only the single vertex 4 with the crossed
  edge.
- So `oriented_carrier` is asked for a carrier spanning `((0,1,4),(4,8,7))`, a face pair
  whose intersection is the lone vertex `{4}` — not an edge. No edge-keyed carrier can
  exist for it (RA-67.6), and the first failing condition is `carrier-orientation` in all
  21, exactly as measured.
- In the controls `ToAttachment=1,4,5 = f3`, the genuine second face of edge `{1,4}`; the
  pair shares an edge, a carrier exists, and rejection falls through to the later
  `not-same-interior-carrier-point`, exactly as measured in all 23.

**The corner walked around the junction; the path did not.** The `to` corner is not merely
a different face — it is the far face of the adjacent hard edge across the shared junction
vertex.

##### RA-70.10 Both repair shapes are now the wrong family, not merely unbuildable

RA-68 disqualified shape A (publisher-side cut at an authenticated rail junction) and
shape B (consumer-side source-vertex-aware admission) for want of a producer. Rung 9
supersedes that reasoning with a stronger one: **there is nothing wrong at the publisher
or at the consumer.** The publisher published a correct single-step route for the edge its
path actually crossed; the consumer correctly refused a face pair that shares only a
vertex. The defect is upstream of both, in the assignment of the front edge's second
corner at A4.

A repair at either locus would make the pipeline accept an endpoint that is simply wrong.

##### RA-70.11 Gate C is now unnecessary for RP-01, as well as suspended

Gate C was suspended at RA-65.5 for want of a producer and re-grounded at RA-68.3 on
ordering. Rung 9 adds a third and more basic ground: a vertex-star sector certificate at
the consumer would authorize admission of a corner that names a face the traced path never
visited. **No consumer-side authority can repair a wrong corner.** Gate C remains
SUSPENDED and is additionally **moot for `RP-01`**. No vertex-star predicate may be
implemented.

##### RA-70.12 `RP-01` advances state without authorizing code

`RP-01 AUTHORITY_DOMAIN_CONFLATION` progresses from *measured, mechanistically derived and
bounded on both repair families* to **producer locus localized**: the defect lies in the
assignment of `SurfacePhaseFrontCell::corners[(side+1)%4].face`. `corners` is
`std::array<SurfaceTracePoint, 4>` (`include/directional/geometry/SurfaceCellTracing.h:1719`),
and `SurfaceTracePoint` carries its own `int face` (`:90-93`) — which is where
`a2bProbeToFace=7` originates, while `boundaryPaths` segments give `{3}`. **Code is still
NOT authorized.**

##### RA-70.13 LESSON — the controls' agreement is half the result

A perfectly separating measurement says two things: what differed, and what did not. The
second is what performs the localization, because every column that agrees across the
populations exonerates the producer behind it. **State the null half explicitly; a finding
that reports only the difference has thrown away the evidence that narrows it.**

---

#### Rung 10 — scope, and why the deferral was right

RA-68 deferred the producer-definition turn behind rung 9 on the stated ground that the
observation could still change *which* producer is needed. **It did exactly that.** Rung
10 is therefore re-scoped from carrier/vertex-star authority to corner-assignment
authority, and is a **documents-only Definition turn**.

The locus is bounded: `src/geometry/SurfaceCellTracing.cpp` contains exactly three
producers of a cell's corner array —

| anchor | form |
|---|---|
| `:10479` | `proposal.corners = {bottomLeft.point, bottomRight.point, topRight.point, …}` — primary aggregate from four traced points |
| `:11269` | `proposal.corners[corner] = xy.point;` — per-corner override from a two-way closure walk |
| `:19790` | `proposal.corners = cell.corners;` — propagation copy |

##### RA-70.14 A prediction for rung 10, with its falsifier and its observation rung named

At `:11258-11271` two independent walks reach the same corner. The code keeps
`xy.point`, discards `yx.point`, and reduces the disagreement to a scalar
`closureError = max(closureError, (xyPosition - yxPosition).norm())` tested against
`options.closureToleranceFactor * min(hx, hy)`.

**Prediction:** a face-index disagreement between the two walks is invisible to that test,
because a position on the shared junction vertex is representable in several faces with
zero positional error — so `closureError ≈ 0` while `xy.point.face` and `yx.point.face`
differ, and the corner silently takes the first walk's face. **Falsifier:** if the
rejected cells do not reach `:11269`, or if a face comparison guards it, the hypothesis is
wrong and `:10479` or `:19790` is the locus. **Observation rung:** rung 10, by static
reading — no new measurement is required, which is why rung 10 is a Definition turn and
not another probe.

This is recorded as a **prediction with provenance stated and its rung named** (RA-61.5,
RA-64.12), not a finding. It does **not** revive RA-64.6, which claimed publisher
truncation; the publisher is exonerated by RA-70.7.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **30+12+449+6 = 497** — all unchanged. No promotion, no stable event, no
regression recurrence, no gate credit, no ledger recomputation, no 497 execution, no
benchmark, no Directional binary executed by this Review. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `a143af264`.** It is the new semantic source. Every earlier
artifact — including compile package `11994726341`, TB4 result `11996317553`, and
snapshots `12005034654`, `12010485442` — is now a **baseline, never a comparand**. The 44
RED are the baseline for `a143af264` alone, **candidate / non-stable**, a diagnostic
vintage and not a new stable recurrence.

`RP-01` **producer locus localized**, code NOT authorized. `RP-02 TEST_AUTHORITY_COVERAGE_GAP`
still **UNREACHED**. `RP-03` satisfied a **sixth** consecutive turn. `PROCESS-01`
discharged. **RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. Gate C SUSPENDED
(RA-65.5, RA-68.3) and now additionally moot for `RP-01` (RA-70.11).**

**Successor:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (rung 10).

## `Architecture_M6_CP3_R6_Corner_Assignment_Authority_Spec_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R6_Corner_Assignment_Authority_Spec_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R6 corner-assignment authority (rung 10)

**Review turn:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (rung 10)
**Frozen amendment:** RA-71
**Verdict:** **ACCEPTED**, with two charges. It falsified a reviewer prediction **and** a
reviewer-supplied census, and both falsifications are correct.
**Review window:** 2026-10-16T02:10:04Z — 2026-10-16T02:52:18Z
**Semantic source:** unchanged at `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`

---

#### RA-71.1 Provenance, re-derived

| check | result |
|---|---|
| snapshot run `38837317846` | `conclusion=success`, `head_sha=c85bd3600` |
| snapshot artifact `12019178209` | ZIP SHA-256 **recomputed** `37dab2b2f1292e7f0a530042b90be1d9813ee4e7eb4e76df7cd50226c2e98bdb`, matches provider digest |
| snapshot manifest | **5,656 entries, 5,656 OK / 0 BAD** |
| `src`/`include`/`tests` at `c85bd3600`, `a143af264`, `HEAD` | **tree-identical** — `72c8fec8e8…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |

The tree-object identity is the stronger statement and it is the one that matters: the
specification read **exactly** the bytes that were compiled at rung 8 and measured at rung
9. No new semantic source.

---

#### RA-71.2 My prediction was falsified, and the falsification is correct

RA-70.14 predicted that `src/geometry/SurfaceCellTracing.cpp:11269` was the locus, on the
reasoning that it keeps `xy.point`, discards `yx.point`, and reduces the disagreement to a
positional `closureError`. **Named falsifier (a) holds.** Verified from source:

```cpp
:19781    if (network.phaseFront.is_produced()) {
:19790        proposal.corners = cell.corners;
              ...
:19801    if (network.phaseFront.is_rejected()) {
:19802      return network;
:19803    }
:19814    SurfaceCellProposal proposal = make_surface_cell_proposal(...);
```

The measured 44 are **rejections**. Control flow returns at `:19802` and never reaches
`:19814`, so `make_surface_cell_proposal` — and with it `:11269` and `:10479` — is
unreachable on the measured path. `:19790` sits inside the `is_produced()` branch and is
equally unreached.

**RA-70.14 is WITHDRAWN**, not merely unconfirmed. The reasoning about `:11269` discarding
a walk without comparing faces remains true of that fallback and explains nothing about
`RP-01`.

#### RA-71.3 My census was wrong, and the way it was wrong is the lesson

I supplied three writers and instructed the turn to "confirm this yourself and say so if
you find a fourth." It did, and the correction is structural, not a miscount.

`include/directional/geometry/SurfaceCellTracing.h` declares an identically-typed
`corners` member on **two different structs**:

| header line | owning struct | member |
|---|---|---|
| `:1719` | `SurfacePhaseFrontCell` | `std::array<SurfaceTracePoint, 4> corners;` |
| `:2160` | `SurfaceCellProposal` | `std::array<SurfaceTracePoint, 4> corners;` |

**All three writers I nominated — `:10479`, `:11269`, `:19790` — write
`proposal.corners`, i.e. `SurfaceCellProposal::corners`.** None of them writes
`SurfacePhaseFrontCell::corners`, which is the field A4 actually judges. My census
conflated two objects that share one identifier name and one type. **That is precisely
the error class I charged at RA-67.13 and again at RA-70.8, committed one rung after
freezing the lesson.**

The method was blind too, in two independent ways:

- my first census grep excluded `cell\.corners\[static_cast` in order to filter *reads*
  such as `edge.from = cell.corners[side]`, and that exclusion removes the real write;
- my second, "unfiltered", grep required `=[^=]`, a character after the equals sign —
  and the real write at `:12986` ends its line with `=`, continuing on `:12987`.

Neither grep could have found the target. The sole writer of
`SurfacePhaseFrontCell::corners` is:

```cpp
:12986      cell.corners[static_cast<std::size_t>(corner)] =
:12987          points[static_cast<std::size_t>(nodeIds[corner])];
```

confirmed by an unfiltered census returning exactly four `corners` assignments in the
file — `:10479`, `:11269`, `:19790` (all `proposal.corners`) and `:12986`.

##### RA-71.4 LESSON — an enumeration is only as bounded as the filter that produced it

A census presented as exhaustive ("exactly three producers") inherits every blind spot of
the query that produced it, and a reviewer who hands a successor a bounded list converts
their own filter into the successor's search space. State the query, not just its result,
so a successor can falsify the boundary rather than work inside it. The turn did exactly
that by reading the call graph instead of trusting the list.

---

#### RA-71.5 The named locus is correct, and verified line by line

**Named locus:** the planar phase-front lattice point-to-source-face selection in
`point_on_source` (`:11477-11509`), made authoritative for corner faces by
`build_uniform_phase_front_for_faces` at `:12949-12958` and `:12986-12987`, with no
reconciliation against `boundaryPaths`.

| step | anchor | verified content |
|---|---|---|
| producer chosen | `:17884-17890` | planar `build_uniform_phase_front_for_faces` is called first; `build_periodic_annulus_phase_front_for_faces` runs only on `NotApplicable`. The fixture is explicitly planar-and-rectangular. |
| face selected | `:11478-11509` | loops `for (const authority::SourceFaceId faceId : activeFaces)`, `continue`s on failed barycentric containment, and on the **first** success does `point.face = face; point.barycentric = barycentric; return true;` — no reference to side, path, cell or route |
| selected **per node** | `:12949-12958` | `points[node_index(u, v)]` is filled once per lattice node, so one face choice is shared by every side and every cell touching that node, made **before any path exists** |
| copied to the corner | `:12986-12987` | `cell.corners[corner] = points[nodeIds[corner]]` — sole writer |
| paths built separately | `:13012-13021` | `segment_on_source(...)` fills `cell.boundaryPaths[side]` independently |
| endpoints inherit it | `:13033-13035` | `edge.from = cell.corners[side]`, `edge.to = cell.corners[(side+1)%4]` |

This is a better answer than my hypothesis. It explains the RA-70.7 asymmetry directly:
`from` and `to` are **different lattice nodes**, each independently first-matched, and
only the node sitting on the shared junction vertex has more than one admissible face.

---

#### RA-71.6 Addition — this is an ordering dependency, not a tolerance defect

`:11483` sets `constexpr double tolerance = 1.0e-10`; containment admits
`[-tolerance, 1 + tolerance]`; and `:11495-11501` snaps `|b| <= tolerance` to exactly `0`
and `|b - 1| <= tolerance` to exactly `1`.

A lattice point lying **exactly on a shared source vertex** therefore satisfies the
containment test in **every incident face**. In the measured fixture vertex 4 is a corner
of `f0, f1, f3, f4, f6, f7`, and the point is at the vertex, so the barycentric test
passes in all six. **The winner is decided purely by `activeFaces` iteration order.**

Two consequences, both load-bearing:

1. **No epsilon change can repair this.** Tightening or loosening `tolerance` moves which
   *near*-vertex points are ambiguous; it cannot make an exact vertex unambiguous, because
   the vertex genuinely belongs to every incident face. Any repair that touches the
   tolerance is misdirected, and the first instinct of a later turn will be to touch it.
2. **The attribution is complete without identifying the winning face.** Since the
   selection is iteration-order-dependent and every incident face is admissible, *any*
   order-dependent corner face is the defect. Which face wins is a detail of
   `activeFaces` ordering, not a precondition for naming the producer.

#### RA-71.7 Addition — the reconciler exists, and it is blind; third instance of the pattern

The specification says nothing reconciles the corner against the boundary path. The
sharper truth: **the designated reconciler exists, is called twice, and compares the wrong
thing.**

`orient_and_validate_phase_front_cell` calls `validate_closed_boundary_paths` at `:12718`
and again at `:12736`. Inside it (`:7319-7357`):

```cpp
const auto valid = [&](const SurfaceTracePoint &point) {
  return point.face >= 0 && point.face < faces.rows() && ... };
const auto close = [&](const SurfaceTracePoint &a, const SurfaceTracePoint &b) {
  if (!valid(a) || !valid(b)) return false;
  return (point_position(vertices, faces, a) -
          point_position(vertices, faces, b)).norm() <= tolerance; };
...
if (!close(start, corners[side]) ||
    !close(end,   corners[(side + 1) % 4])) return CellRejectionReason::Closure;
```

`valid()` applies a **bounds** check to `point.face`, never an identity check, and `close()`
is a pure 3D distance test. A corner in `f7` and a path endpoint in `f3` that are the same
physical point at vertex 4 pass at distance **exactly 0**. The comparison that would have
caught `RP-01` is made, twice, and cannot see the defect.

**This is the RA-68.3 pattern for the third time.** At RA-68.3 the junction certificate
existed but was ordered after the admission it would authorize. Here the reconciler exists
but compares position where identity is required. **Record the generalization: when a
missing authority is sought in this pipeline, look first for it existing in a form that
cannot do the job.**

Informational: `valid()` uses `faces.rows()` rather than `face_count()` — the RA-66.6
asymmetry locus, unchanged and still not authorized for repair.

#### RA-71.8 Falsifiers (c) and (d) settled, not assumed

- **(c)** "a pre-A4 check already requires the selected corner's source face to belong to
  the oriented owning boundary path" — **does not hold**; RA-71.7 shows the only such check
  is positional.
- **(d)** "a later mutation between `:12987` and A4 changes that source face" — **does not
  hold**. `reverse_phase_front_cell_cycle(cell)` at `:12730` permutes the cycle and
  recomputes positions; it reorders corners without rewriting any corner's `face`. The
  unfiltered census confirms no other writer of `SurfacePhaseFrontCell::corners` exists.

The attribution therefore survives all four of its own named falsifiers.

---

#### RA-71.9 CHARGE — a mandated verification was omitted and not disclosed

The turn was instructed verbatim to run **both** gates and report both:

```
python3 -I .agents/Directional/tools/review_check.py boundary
python3 -I .agents/Directional/tools/review_check.py ledgers --base fa6495a7c
```

The closeout table carries a `review_check.py boundary` row and **no `ledgers` row**. The
append-only ledger gate was not reported, and its absence was not declared. This is the
**RA-66.4 category — a mandated item silently dropped — and therefore a repeat.** Both
gates have been run by this Review and both pass; the defect is the silence, not the
state. Minor and not charged separately: `review_check.py` was invoked without `-I`.

#### RA-71.10 CHARGE — the turn under-claims its own completed attribution, and this is now a pattern

The specification writes that "the exact per-vertex choice responsible for f7 remains the
**reviewable attribution**, not an executed new measurement", which reads as a confession
of incompleteness. Its own evidence completes the attribution: per RA-71.6 the selection
is iteration-order-dependent across six admissible faces, so the producer is named and the
defect established **without** identifying the winning face. The turn had the argument and
declined to draw it.

This is the **third consecutive turn** in the under-claim category — RA-67.9 (harvested
interval fields never examined), RA-70.7 (the path-identity and `hit_from` facts left
unstated), and now RA-71.10. **Recorded as a pattern rather than an isolated lapse:** the
Implementation Agent's measurements have repeatedly been stronger than its claims about
them. The failure mode is conservative, which is far preferable to the opposite, but it
costs a rung each time a reviewer has to extract the result.

#### RA-71.11 Credits

- **It falsified a reviewer prediction and a reviewer-supplied census in the same turn**,
  and did so on the merits with a reachability argument, explicitly declining to name
  `:11269` "merely because it discards one of two corner walks." **`RP-03` satisfied a
  seventh consecutive turn.**
- It stated **four explicit falsifiers** for its own attribution, all four of which this
  Review was able to settle from source — which is what makes the attribution reviewable.
- It refused to claim a push it could not verify from inside a snapshot
  ("Require GitHub remote commit/ref evidence; no local-origin claim from snapshot").
  Correct provenance discipline; the push did land, verified independently.
- Guidance, not a charge: the closeout `CHANGELOG` row names
  `.agents/Directional/CHANGELOG.md` while **root `CHANGELOG.md` is canonical**. This
  matches established practice — the Review writes the root ledger — but the row should
  name which file it means.

#### RA-71.12 `RP-01` state

`RP-01 AUTHORITY_DOMAIN_CONFLATION` advances from *producer locus localized* to **producer
locus NAMED AND VERIFIED**:

> the corner's source face is selected per **lattice node** by first-match over
> `activeFaces` in `point_on_source` (`:11477-11509`), made authoritative for
> `SurfacePhaseFrontCell::corners` at `:12949-12958` / `:12986-12987`, while the designated
> reconciler `validate_closed_boundary_paths` (`:12718`, `:12736` → `:7319-7357`) compares
> corner against path by 3D position and is blind to face identity.

**Code is still NOT authorized**, because the RA-65.5 producer test has not been applied to
the repair family. `RP-02` remains **UNREACHED**.

---

#### Rung 11 — scope

`M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC`, **documents only**. Three questions,
all answerable statically:

1. **Apply the RA-65.5 producer test to the repair family.** Enumerate every witness a
   repair needs and name its existing publisher. Candidates already published:
   `activeFaces` plus the barycentric containment test yields the *admissible* face set at
   a node; `boundaryPaths[side]` segments carry `segment.face`. This may be the first
   repair family whose witnesses all already exist — state the outcome either way.
2. **Settle per-node versus per-side.** A lattice node is shared by up to four sides and
   four cells, and `:12949-12958` makes **one** choice for all of them. If their traced
   paths lie in different faces, no single per-node face can satisfy every consumer, and
   the repair is structural — a per-side corner face or an explicit reconciliation pass —
   not a selection-order fix. Derive the answer from the source plus the RA-70 measurement.
3. **State what a face-identity check at `:12718` would and would not achieve.** It would
   **relocate** the failure from a late A4 `carrier-orientation` rejection to an honest
   cell-production rejection at the true producer. **It would not repair `RP-01`** — the
   cells would still be rejected. Do not let a later rung mistake relocation for repair.

No code, no compile, no runtime, no repair implementation. Naming the repair shape and its
blast radius is the deliverable.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **30+12+449+6 = 497** — all unchanged. No promotion, no stable event, no
regression recurrence, no gate credit, no ledger recomputation, no 497 execution, no
benchmark, no Directional binary executed. No source, test, selector, binary, harness or
workflow change by this Review. PR #8 draft/open.

`R4-VIN-01` remains armed at `a143af264` — the semantic source is unchanged by rung 10, and
artifacts `11994726341`, `11996317553`, `12005034654`, `12010485442` and `12019178209` are
**baselines, never comparands**. The 44 RED remain the baseline for `a143af264` alone,
candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN (this decision).
Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01` (RA-70.11).** `PROCESS-01`
discharged. `RP-03` satisfied a seventh consecutive turn.

**Successor:** `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` (rung 11).

## `Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R7 corner-face selection repair (rung 11)

**Review turn:** `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R7-CORNER-FACE-SELECTION-REPAIR-SPEC` (rung 11)
**Frozen amendment:** RA-72
**Verdict:** **ACCEPTED WITH AMENDMENT.** All three mandated questions answered; the repair
*shape* is admissible; its central *premise* is unverified and the evidence runs against it.
**This decision also amends my own RA-71.6**, which the source bytes contradict.
**Review window:** 2026-10-16T03:20:11Z — 2026-10-16T04:06:44Z
**Semantic source:** unchanged at `a143af264bc8b33f0e1b2f8def16b2479b53d5fc`

---

#### RA-72.1 Provenance, re-derived

| check | result |
|---|---|
| snapshot run `38843434916` | `conclusion=success`, `head_sha=491914f93` |
| snapshot artifact `12021892076` | digest `005211e882847639d563b74650da4f753a5b0023ed599d92520959a0cbf218bc`, matches |
| `src`/`include`/`tests` at `491914f93`, `a143af264`, `HEAD` | **tree-identical** — `72c8fec8e8…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |

The tree-object identity settles the decisive question outright: the specification read
exactly the bytes compiled at rung 8 and measured at rung 9. The turn volunteered that
"the local snapshot was not a Git clone" — a limitation disclosed rather than papered over.

#### RA-72.2 The deliverable is complete

All three mandated questions are answered, in order, with source citations. Verified
individually:

- **Q1, producer test** — answered with a six-row witness/publisher table and an explicit
  verdict.
- **Q2, per-node versus per-directed-side** — answered **per-directed-side**, structural.
- **Q3, relocation versus repair** — answered in §4, explicitly, and it goes further than
  asked by noting a global face-identity check would **over-reject** legitimate
  adjacent-face representations of a canonical source vertex.

Seven falsifiers (F1–F7) are stated for its own proposal.

#### RA-72.3 The producer test verdict is substantially right — and this is the first repair family to pass it

Verified from the header and the call order:

- `SurfaceTraceSegment` (`include/directional/geometry/SurfaceCellTracing.h:1211-1232`)
  carries `int face`, `startBarycentric`, `endBarycentric`, `family`, `sign`,
  `std::optional<FieldChartId> sourceChart`, a typed `authority::CanonicalRoute entryRoute`
  and `std::optional<HardRailId> railId`.
- `cell.boundaryPaths[side]` is filled by `segment_on_source` at `:13012-13021`, **before**
  `SurfaceFrontEdge` is constructed at `:13030-13035`.

So a face-valued, barycentric-exact, chart- and route-attributed endpoint **per directed
side** is already published before the edges are minted. Every prior repair family failed
RA-65.5 for want of a publisher; **this one does not.** That is a real advance and the
turn is right to say so.

The accompanying caution is also right: possessing the evidence is not the same as
propagating it as authoritative, and the implementation must fail closed where identity,
chart or transport cannot be certified.

#### RA-72.4 Per-directed-side is the correct structural answer

`point_on_source` chooses one face per `(u,v)` node at `:12949-12958`, before any boundary
segment exists; `:12986-12987` copies it into the corner; `:13033-13035` copies the corner
into the edge endpoints. Each of the four directed paths is built independently at
`:13012-13021` and may approach a shared node from a different incident triangle. A node
belongs to up to four cells, each contributing an incoming and an outgoing side incidence.
**One `SurfaceTracePoint::face` cannot be the authoritative face of all of them**, and the
turn's conclusion that a per-node fix works only under a *proved* special condition is
sound. Keeping one canonical geometric node while allowing several side-occurrence
representations is the right shape.

#### RA-72.5 §4 is correct: relocation is not repair

A literal `corner.face == boundaryPaths[side].front().face` test inside
`validate_closed_boundary_paths` would move the measured 7-vs-3 discrepancy to a
producer-stage closure rejection and make no cell succeed. The turn states this plainly
and refuses to count it as recovery. It also identifies the over-rejection risk
unprompted. **No later rung may count relocation as repair.**

---

#### RA-72.6 AMENDMENT — RA-71.6 is amended; both selectors are minimum-face-row, not arbitrary order

RA-71.6 states that the corner's face "is decided purely by `activeFaces` iteration
order". **The source contradicts this, and the clause is amended.** Verified chain:

| step | anchor | content |
|---|---|---|
| the list is sorted | `src/geometry/SurfaceCellTracing.cpp:17823` | `std::sort(work.sourceRows.begin(), work.sourceRows.end());` before it is passed as `activeFaces` at `:17887` |
| the sort key is the row | `include/directional/authority/AuthorityIds.h` | `using SourceFaceId = SemanticId<detail::SourceFaceTag>`; `SemanticId` holds one `std::size_t value_`, exposes `index()` returning it, and declares `auto operator<=>(const SemanticId &) const = default` |
| the row *is* the index | `SurfaceCellTracing.cpp:189-195` | `source_face_row` returns `faceId.index()` |

Therefore `activeFaces` is **ascending by face row**, and `point_on_source`'s first match is
the **minimum admissible face row**. Independently, `segment_on_source` selects by
`(selectedFace < 0 || interval.face < selectedFace)` at `:12124-12130` — also the
**minimum** covering face row.

**Both disambiguation rules are the same rule.** The "arbitrary iteration order"
characterization is **WITHDRAWN**.

What survives untouched is RA-71.6's operative conclusion, and it survives on better
grounds: `face_barycentric_from_uv` (`:11450-11474`) is a plain planar inverse affine map
through `phase_uv`, failing only when `|determinant| <= 1.0e-18`, so for a UV point lying
exactly on a shared source vertex **every incident active face yields a valid barycentric
inside tolerance**. The ambiguity is real, it is not numerical, **no epsilon change can
repair it**, and the selection is still made with no reference to the consuming side. The
defect is a **side-independent deterministic rule**, not an arbitrary one.

#### RA-72.7 CHARGE — the specification inherited the reviewer's premise instead of re-deriving it

The turn describes `point_on_source` as returning "the first face in `activeFaces`" in the
sense that made my clause wrong, and separately labels `segment_on_source`'s midpoint
choice "an independently order-sensitive *path-face* tie-break". Both characterizations
are off: `activeFaces` is sorted, and both selectors are minimum-row. The §1 "Limit on
determinism" paragraph therefore warns against an asymmetry that does not exist in the
form described, and spends its caution in the wrong place.

**Rung 10 refused a reviewer-supplied census and was credited for it (RA-71.2, RA-71.3).
Rung 11 accepted a reviewer-supplied mechanism unchecked.** The obligation is the same in
both directions.

#### RA-72.8 The repair contract's central premise is unverified, and the measurement runs against it

This is the substantive finding, and it is why the verdict is *with amendment*.

Both selectors take the minimum admissible row over a sorted, non-degenerate set. At a
node sitting exactly on a shared vertex, every incident active face is admissible. **A
minimum-row rule cannot return 7 from a set that contains 3.** Yet RA-70 measured, in all
21 junction cases, `toFace=7` on the corner and `{3}` on that side's traced path.

The only consistent reading is that **the two selections draw from different face sets** —
the node-level `activeFaces` for that region must exclude every row below 7 that the
side's interval set includes.

§3.2 of the contract instructs that "the end is `path.back().face/endBarycentric`". On
current evidence that would bind the corner to a face the **node-level containment test
never saw**. That may well be the correct repair; the specification does not establish
that it is legal, and does not notice the tension. **A repair whose premise is contradicted
by the measurement it cites must not be implemented before the premise is measured.**

Note this does not disturb RA-71.5 (the locus), RA-71.7 (the blind reconciler), RA-72.3
(the producer test) or RA-72.4 (per-directed-side). It disturbs only the step that assumes
the path's face is available to the corner.

#### RA-72.9 CHARGE — both mandated gates omitted, and the closeout table dropped

RA-71.9 charged, one rung ago, the omission of the `ledgers` gate from a closeout table
that at least reported `boundary`. This rung reports **neither gate**, and the duty table
that carried the row is gone entirely. That is escalation, not repetition. Both gates have
been run by this Review and both pass.

Also dropped: **`ORIENTATION.md` was not updated**, though both preceding Definition turns
updated it, leaving the orientation document describing RA-71 as current while `STATUS`
recorded rung 11 complete. This Review restores currency.

#### RA-72.10 Credits

- **Root `CHANGELOG.md` was written this turn**, correcting the RA-71.11 guidance within one
  rung.
- It **declined to authorize its own code successor**, writing "No code implementation is
  authorized by this record alone" and leaving `Successor: UNKNOWN` with reasoning in the
  owning document — the RA-63.13 shape. **`RP-03` satisfied an eighth consecutive turn.**
- It **rejected sorting `activeFaces` as a general repair** — the right conclusion, reached
  for a reason that turns out to be wrong, since the list is already sorted. The conclusion
  is in fact stronger than argued: changing that order would alter the corner face of
  **every** node in the pipeline, not only the junction ones.
- It disclosed that the local snapshot was not a Git clone, and stated seven falsifiers for
  its own proposal.

#### RA-72.11 LESSON — re-derive the premise you were handed, not only the question

A specification inherits the reviewer's premises unless it re-derives them. Rung 10
demonstrated the correct behaviour by refusing a census; rung 11 answered three
well-posed questions on top of a mechanism it never checked, and the mechanism was wrong.
**Check the ground you are asked to build on, not just the thing you are asked to build.**

#### RA-72.12 `RP-01` state

Repair **shape** admissible — per-directed-side endpoint binding, with the canonical
geometric node retained. Repair **premise unverified** — the node's admissible face set at
the failing corner has never been observed, and minimum-row selection implies it differs
from the side's covering set. **Code remains NOT authorized.** `RP-02` **UNREACHED**.

---

#### Rung 12 — scope

`M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE`, **compile-only, rejection-only**, in the
pattern that already worked at rungs 8–9. For a rejected edge only, extend the existing
post-decision probe block at `:19360` to emit:

1. the **full** admissible face set at each endpoint node — every active face passing the
   `point_on_source` containment test, not merely the first;
2. the region's `activeFaces` content as actually presented to the producer;
3. the side path's covering face set, already available, for direct comparison.

Then dispatch a compile package and stop. Rung 13 harvests; rung 14 implements only if the
premise holds. The question the probe settles is single and decisive: **does the node's
admissible set contain the path's face?** If yes, the §3.2 binding is legal and the repair
proceeds. If no, the defect is upstream in region face membership and the repair shape
changes again.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by this Review. PR #8 draft/open.

`R4-VIN-01` remains armed at `a143af264`; artifacts `11994726341`, `11996317553`,
`12005034654`, `12010485442`, `12019178209` and `12021892076` are **baselines, never
comparands**. The 44 RED remain the baseline for `a143af264` alone, candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-71.6 AMENDED
(this decision) — its "arbitrary iteration order" clause withdrawn, its no-epsilon
conclusion retained on firmer ground. Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for
`RP-01` (RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied an eighth consecutive turn.

**Successor:** `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` (rung 12).

## `Architecture_M6_CP3_R7_Lattice_UV_Candidate_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R7_Lattice_UV_Candidate_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R7 pre-snap lattice-UV candidates (rungs 14 and 15)

**Review turn:** `M6-CP3-R7-LATTICE-UV-CANDIDATE-REV`
**Adjudicated:** `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` (rung 14) and
`M6-CP3-TB7-R7-LATTICE-UV-CANDIDATE-HARVEST` (rung 15)
**Frozen amendment:** RA-74
**Verdicts:** both **ACCEPTED**. The measurement **exonerates the face selector entirely** and
relocates `RP-01` to a wholesale, unreconciled point substitution. One **hard** charge on
append-only ledger destruction, two lesser.
**Review window:** 2026-10-16T07:05:18Z — 2026-10-16T07:58:40Z
**Semantic source:** `cdd6dc4a9ba95a42aace6226194b38e712b53e4b` (new — `R4-VIN-01` re-arms)

---

#### RA-74.1 THE RESULT — the sampler is innocent; the point is replaced after it

Measured, then confirmed in the bytes. At
`src/geometry/SurfaceCellTracing.cpp:17256-17281`, inside the **bounded-disk** producer:

```cpp
if (!point_on_periodic_chart(chartTriangles, uv, faces.rows(),
        points[node_index(u, v)])) { /* reject */ }
const int sampledFace = points[node_index(u, v)].face;      // probe-added
if (useAcceptedConformity) {
  const SurfaceTracePoint *accepted = nullptr;
  if (v == 0)                 accepted = &acceptedBoundary[0].points[u];
  else if (u == result.gridU) accepted = &acceptedBoundary[1].points[v];
  else if (v == result.gridV) accepted = &acceptedBoundary[2].points[gridU - u];
  else if (u == 0)            accepted = &acceptedBoundary[3].points[gridV - v];
  if (accepted != nullptr) {
    points[node_index(u, v)] = *accepted;                   // WHOLESALE REPLACEMENT
  }
}
```

When the node lies on the bounded-disk **grid boundary**, the sampled `SurfaceTracePoint` is
**replaced in its entirety** by the accepted-conformity boundary point — a different point
with its own `face` and `barycentric`. There is **no face-admissibility check, no
source-entity comparison, and no agreement test against the chart sample.**

**Production does not even retain the discarded value.** `grep -n sampledFace` returns
exactly two lines — `:17264`, its declaration, and `:17305`, the probe's own emission — and
both were **added by the CB7 probe** (`git show cdd6dc4a9 | grep sampledFace` shows them as
`+` lines). Before this rung, the chart sample's face left no trace anywhere.

#### RA-74.2 The measurement, re-derived

Result artifact `12030150301`, ZIP SHA-256 **recomputed** `de79aed888a2…`, matching the
provider digest; internal manifest **51 OK / 0 BAD**;
`planned=44 executed=44 red=44 missing=0 postflight=true exit=0`,
`compile=false relink=false benchmarks=false selector497=false`. Re-derived independently
from `producer-presnap-candidates.tsv` — 96 rows, 0 errors, four categories:

| n | condition | endpoint | producer | sampled | published | published_is_min |
|---:|---|---|---|---:|---:|---|
| 21 | `carrier-orientation` | FirstTo | bounded-disk | 0 | 0 | **true** |
| 21 | `carrier-orientation` | SecondFrom | bounded-disk | **3** | **7** | **false** |
| 27 | `not-same-interior-carrier-point` | FirstTo | none | — | — | not measured |
| 27 | `not-same-interior-carrier-point` | SecondFrom | none | — | — | not measured |

The harness's own summary records `sampled-min` for **both** junction categories. So in all
21 `SecondFrom` endpoints the sampler chose **3, the minimum passing candidate**, and
publication reports **7**.

#### RA-74.3 What this settles, and what it overturns

- **RA-72.6 is CONFIRMED at the producer's own sample point** — `sampled_is_min` is true in
  all 21. The minimum-row rule holds. It is also now **irrelevant to the defect**, because
  the sample is discarded.
- **RA-73.5 is SUPERSEDED.** The "published the largest" framing described a *selection*
  asymmetry. There is none: it is a **sample/publication substitution**. The clause stands
  as a correct observation of published values and a wrong account of their cause.
- **RA-71.5 is AMENDED.** It named the planar `point_on_source` in
  `build_uniform_phase_front_for_faces` as the locus. The measured endpoints come from the
  **bounded-disk** producer via `point_on_periodic_chart`. `point_on_source` is **exonerated
  for these cells**.
- **My RA-73.6 charge is vindicated.** Sampling at the producer's own point rather than the
  published one changed the answer and relocated the locus. That is exactly what RA-73.10
  predicted would be at stake.

#### RA-74.4 The pattern, now in its strongest form

RA-68.3: the junction certificate existed but was **ordered after** the admission it would
authorize. RA-71.7: the corner/path reconciler existed but compared **position** where
identity was required. **RA-74.4: here no reconciliation exists at all** — one authority's
output is overwritten by another's, and the overwritten value is not even held in a
variable. The progression is worth freezing as a search order: *ordered too late → present
but comparing the wrong thing → absent entirely.*

#### RA-74.5 Rung 14 honoured the constraint it was given

RA-73.7 established that the producer's lattice UV is not reconstructible downstream because
`UniformPhaseFrame` carries no step. The instruction said: recover it and say how, or move
producer-side — and **do not substitute an approximate input**. The turn moved
producer-side and said why, in the record ("avoiding consumer-side reconstruction from an
incomplete `UniformPhaseFrame`") and in a source comment:

```cpp
// A bounded-disk chart has its own UV basis and canonical face-key
// selection. Do not substitute a planar face_barycentric_from_uv call:
// it would inspect a different sample from this producer's own chart.
```

That is **RA-73.10 applied one rung after it was frozen**, and it is the reason this
measurement is decisive where the last one was not. The singleton-`{face}` technique from
rung 12 was carried forward.

**Neutrality for a producer-side probe, verified by content rather than brace depth:** the
added lines assign only to probe-local `sourceVertex`, `raw`, `incidentCount` and the
emission stream. A scan for assignments to `points[`, `cell.`, `result.`, `proposal.` or
`frame.` among the added lines returns **none**. Chain closed by content: probe blob
`4a524d204ea2dc2a55111247fdfa03b2fc57e955` **= HEAD**; `include` and `tests`
**byte-identical** at `cdd6dc4a9` and HEAD.

| artifact / run | verified |
|---|---|
| snapshot `12027572751` (run `38857271030`) | digest `0ee9aeee80b7…`, success |
| patch-apply `12029085105` (run `38859325067`) | digest `df921d8e5edd…`, success |
| compile `12028682600` (run `38859497594`) | digest `54b7f5a73ae7…`, success |
| result `12030150301` (run `38861867717`) | ZIP recomputed `de79aed888a2…`, success |

---

#### RA-74.6 HARD CHARGE — the append-only ledger was destroyed and pushed

`Regression_Root_Cause_Tracker.md` went from **14,225 lines / 664 sections / 13 markers** to
**6 lines / 1 section / 0 markers** at commit `b2b6e6541`, and remained destroyed across
**four pushed commits** — `b2b6e6541`, `9b4061c59`, `e082128ac`, `0aca74462` — before being
restored at `9d0ed94e6`. The new section had been written as a **whole-file overwrite**
instead of a prepend.

**The restore is byte-faithful.** Verified: the restored file's tail from line 8 is
**byte-identical** to the tracker at the last good commit `7c83fb0ec` (`cmp` clean), and
counts reconcile exactly — 14,232 = 14,225 + 7, 665 = 664 + 1, markers 13 throughout. **No
content was permanently lost.**

What is charged is that it happened and was pushed. **The mandated gate catches it.**
`cmd_ledgers` walks every commit in the range (`rev-list --reverse base..HEAD -- path`) and
compares `rev~1` against `rev`, so it is sound — and it fails here:

```
[FAIL] no historical shrink of .../Regression_Root_Cause_Tracker.md  b2b6e654 14225->6
```

with a true exit code of **1** (confirmed separately; the tool is not at fault). **Five
consecutive NEXT_TURN blocks have required both gates be run and reported before closing.**
Had either been run, four commits carrying a destroyed durable ledger would not be on
`origin`. The append-only property is an architectural invariant of the ledger system, not a
bookkeeping convention, which is why this is a hard charge rather than a procedural note.

**Mitigation, stated plainly:** the agent detected the destruction itself, restored it
byte-perfectly, and named the restore in the commit subject rather than quietly amending.
That is the right recovery. The defect is the absent pre-push verification.

#### RA-74.7 CHARGE — the controls were not measured, so they cannot discriminate here

All 54 control endpoints record `producer=none` and no sampled or published face: the
ambiguous-node probe never fired for them. The report states this accurately ("Not
measured") but does not draw the consequence — **the 23 controls provide no control for the
override**, because nothing establishes whether the override fires in them and happens to
agree. No later turn may cite the controls as evidence that the substitution is
junction-specific. This is the RA-68.5 pattern recurring: a control population that does not
control for the property under test.

#### RA-74.8 CHARGE — `ORIENTATION.md` not updated, second consecutive rung

Rung 13 skipped it and this Review restored it; rung 15 skipped it again. This Review
restores it again.

#### RA-74.9 Credits

- **Claim calibration corrected in one rung.** RA-73.6 charged a headline that overstated;
  this report leads with "Runtime evidence complete; separate independent Review required"
  and states plainly that "the record does **not** independently prove that the subsequent
  boundary override is valid under the A2b endpoint/side-carrier authority." That is the
  calibration the charge asked for.
- **Beacon correct.** `Successor: UNKNOWN` with reasoning in the owning document — the
  RA-63.13 shape, **not** self-referential. The RA-73.8 charge was absorbed in one rung.
- **Two non-evidential failures disclosed** — a local exploratory run that exceeded a
  60-second allowance after 16 of 44 logs, and a local Python run that failed on file
  permissions — with both explicitly excluded from the result.
- **`RP-03` satisfied a tenth consecutive turn**: the measurement relocated the locus off the
  reviewer's named target and said so.

#### RA-74.10 `RP-01` state

**Locus relocated and fully specified**, for the third time: the unreconciled wholesale
substitution at `:17266-17281` in the bounded-disk producer, under
`useAcceptedConformity` (`:14993`), at grid-boundary nodes only. **Code remains NOT
authorized**, because the question is no longer *what happens* but *which authority is
right* — and that has never been adjudicated. `RP-02` **UNREACHED**.

#### RA-74.11 LESSON — when one producer overwrites another's output, the question is ownership, not correctness of either

Three rungs were spent asking whether the face selector picked correctly. It did. The defect
is that a second authority replaces its answer wholesale, and **nothing in the system records
that a replacement occurred**. Before fixing a value, establish which producer owns it; a
substitution with no reconciliation is an ownership defect wearing the costume of a
computation bug.

---

#### Rung 16 — scope

`M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC`, **documents only**. Four questions, all
statically answerable:

1. **What authority does `acceptedBoundary` carry?** Where is it produced (`:16822`,
   `:16867-16885`), what does `useAcceptedConformity` (`:14993`) and
   `useAcceptedCutDomain` (`:14998`) gate, and what — if anything — does it guarantee about
   `.face`?
2. **Is the override's boundary condition coextensive with the measured 21?** The guard is
   `v == 0 || u == gridU || v == gridV || u == 0`. Establish whether the 21 are exactly the
   grid-boundary nodes and the 23 exactly the interior ones, from source, not from the
   measurement.
3. **Which authority owns the corner's face at a conformity-baseline boundary node — the
   chart sample or the accepted boundary?** If the accepted boundary is authoritative, face
   7 is *correct* and `RP-01` is a downstream consumer defect; if the chart sample is, the
   override is the bug. **This reframes `RP-01` and must be settled before any code.**
4. **Apply RA-65.5 to each candidate repair** and state, for each, whether it is repair or
   merely **relocation** (RA-72.5): a face-admissibility check at the override would reject
   the 21 at producer stage and make no cell succeed.

No code, no compile, no runtime. Naming the owning authority is the deliverable.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `cdd6dc4a9`.** Every earlier artifact — through `12019178209`,
`12021892076`, `12024554349`, `12027572751`, `12028682600` — is a **baseline, never a
comparand**. The 44 RED are the baseline for `cdd6dc4a9` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED (this decision) — the planar selector is exonerated for the
measured cells. RA-73.5 SUPERSEDED (this decision) — a substitution, not a selection
asymmetry. RA-72.6 CONFIRMED at the sample point and now moot. Gate C SUSPENDED (RA-65.5,
RA-68.3) and moot for `RP-01` (RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied a
tenth consecutive turn.

**Successor:** `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` (rung 16).

## `Architecture_M6_CP3_R7_Node_Admissible_Face_Set_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R7_Node_Admissible_Face_Set_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R7 node admissible-face set (rungs 12 and 13)

**Review turn:** `M6-CP3-R7-NODE-ADMISSIBLE-FACE-SET-REV`
**Adjudicated:** `M6-CP3-CB6-R7-NODE-ADMISSIBLE-FACE-SET-PROBE` (rung 12) and
`M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` (rung 13)
**Frozen amendment:** RA-73
**Verdicts:** both **ACCEPTED**. **RA-72.8 is falsified and WITHDRAWN** — correctly, by the
turn. One charge on the census's measurement point, one on the beacon.
**Review window:** 2026-10-16T04:55:02Z — 2026-10-16T05:41:30Z
**Semantic source:** `4d64b7684ac7ec2d0655f96c88ecf05f2906bca7` (new — `R4-VIN-01` re-arms)

---

#### RA-73.1 Rung 12 — the probe is neutral, and it was built the right way

Structural neutrality verified by brace accounting, not asserted: the rejection branch opens
at `src/geometry/SurfaceCellTracing.cpp:19360`, the census insertion sits inside it at
`:19504-19576`, and the branch closes at `:19639`. `git show --numstat` reports `73 0` on
one file. No acceptance path can observe it.

**The technique is better than what I specified.** I offered a diagnostic re-implementation
of the containment test. The turn instead **calls `point_on_source` itself**, once per face
with a singleton `{face}` list:

```cpp
for (const auto face : activeFaces) {
  SurfaceTracePoint candidate;
  if (!point_on_source(vertices, faces, frame, {face}, uv, candidate)) continue;
  ...
}
```

The singleton defeats first-match-returns-early while leaving the production predicate
untouched, so the test is **faithful by construction** rather than by careful copying. That
removes an entire class of instrument error, and it is the correct reading of the
instruction's intent over its letter.

Absence is reported as absence throughout — `missing-region`, `invalid-region-face`,
`Frame=not-planar`, `none` — so RA-66.4 is not repeated.

#### RA-73.2 Chain and artifacts, re-derived

| check | result |
|---|---|
| probe commit `4d64b7684` cpp blob | `bfcc7f88ee0222752d4309d157becc3e480ad514` = **HEAD** |
| `include` / `tests` at `4d64b7684` and HEAD | **byte-identical** — no header, fixture or test change |
| compile artifact `12024554349` | digest `c824a6aa4361…`, matches report |
| result artifact `12025322701` | ZIP SHA-256 **recomputed** `cd7ebc41eb1e…`, matches provider digest |
| result manifest | **49 OK / 0 BAD** |
| `execution-boundary.txt` | `planned=44 executed=44 red=44 missing=0 postflight=true exit=0`, `compile=false relink=false benchmarks=false selector497=false` |
| run `38852145039` | `conclusion=success`, `head_sha=9eba29a39` |
| disclosed failure `38851813094` | independently **`conclusion=failure`** |
| disclosed failure `38851975506` | independently **`conclusion=failure`** |

Both orchestration failures are real and were disclosed when the successful third attempt
would have concealed them — one an invalid uniqueness assumption on a deliberately repeated
identity, one a ZIP extraction that dropped executable permissions so zero tests were
selected. Neither produced evidence and neither was accepted. **`RP-03` satisfied a ninth
consecutive turn.**

#### RA-73.3 The census, re-derived independently

96 side-occurrence rows, `evidence=COMPLETE` on every one, `frame` empty throughout (so
`Frame=not-planar` never fired), multiplicity `[(1,42),(3,2)]` as at RA-70. Exactly four
tuples:

| n | condition | side | active | from_admissible | to_admissible | path |
|---:|---|---|---|---|---|---|
| 27 | `not-same-interior-carrier-point` | First | `0,1,4,5` | `0` | `0` | `0` |
| 27 | `not-same-interior-carrier-point` | Second | `2,3,6,7` | `3` | `2,3` | `3` |
| 21 | `carrier-orientation` | First | `0,1,4,5` | `0` | `0,1,4` | `0` |
| 21 | `carrier-orientation` | Second | `2,3,6,7` | `3,6,7` | `3` | `3` |

#### RA-73.4 RA-72.8 is FALSIFIED and WITHDRAWN

I deduced at RA-72.8 that, since both selectors take the minimum admissible row, the node's
`activeFaces` "must exclude every row below 7 that the side's interval set includes." The
measurement contradicts this outright: the junction `Second` side's `from_admissible` is
`{3,6,7}` — **it contains 3**. The two selections are not drawing from sets that exclude the
path's face. **RA-72.8 is withdrawn**, and the turn is credited for falsifying it.

#### RA-73.5 But the measurement contradicts RA-72.6 at exactly one corner, and the asymmetry is the finding

`:19365-19366` fixes which points the older fields name:

```cpp
const auto &fromPoint = firstMissing ? first.from : first.to;
const auto &toPoint   = firstMissing ? second.to  : second.from;
```

On a second-certificate failure, RA-70's `FromFace=0` is `first.to` and `ToFace=7` is
`second.from`. Against the census:

| corner | published face | its admissible set | minimum | verdict |
|---|---:|---|---:|---|
| `first.to` | **0** | `{0,1,4}` | 0 | **obeys minimum-row** |
| `second.from` | **7** | `{3,6,7}` | 3 | **violates minimum-row** |

Same rejection, same source vertex, two cells in two regions — one corner takes the smallest
admissible face and the other takes the **largest**. **A single global minimum-row rule
cannot explain both**, so RA-72.6's conclusion does not survive as a universal account of the
published corner.

**And the discriminator is set cardinality.** In the 23 controls the `Second` side's
`from_admissible` is the **singleton** `{3}` — there is nothing to get wrong, and 3 is
published. In the 21 junction cases it has **three** members and the largest is published.
*The junction population is exactly the population where that corner sits where three faces
are admissible.* That is a complete separator, measured, with no exceptions.

#### RA-73.6 CHARGE — the census measures admissibility at the wrong UV, and the headline overstates what follows

The probe computes its sample point as

```cpp
const Eigen::Vector2d uv = phase_uv(frame, point_position(vertices, faces, point));
```

— the **published, post-snap** position of the corner. The producer sampled a **lattice** UV,
`(frame.minU + stepU*u, frame.minV + stepV*v)` at `:12951-12952`. These are not the same
point, and the difference is load-bearing: `point_on_source` snaps any barycentric within
`1.0e-10` to exactly `0` or `1` (`:11495-11501`), so a lattice UV lying *near* vertex 4 can
pass containment in only one face **before** snapping and then be published *at* the vertex,
where all three pass. **The set the census measured is therefore not the set the producer
chose from**, and RA-73.5's apparent violation of minimum-row may be entirely an artefact of
measuring after the snap.

The probe's comment discloses the choice and gives a reason (bounded-disk sides may use
separately prescribed conforming boundary subdivision positions), so this is a reasoned,
visible decision rather than an oversight. What is charged is that the consequence was not
drawn, and that the report's headline — "**Yes, for every measured rejected side**" and "the
previously suspected absence … **is falsified by this probe**" — states more than the
evidence supports for the decision it was built to enable. The report's own later sentence
is the accurate one: "the present census does **not** establish why the producer selected 7
despite the later independently measured admissible alternative 3." **That sentence should
have been the headline.** Fourth turn in the claim-calibration category (RA-67.9, RA-70.7,
RA-71.10, now RA-73.6) — though note this one errs toward *over*-claiming, where the prior
three under-claimed.

#### RA-73.7 The producer's lattice UV is not reconstructible from published state

Verified while scoping the next rung, and it constrains it. `UniformPhaseFrame`
(`:11421-11426`) carries `minU`, `maxU`, `minV`, `maxV`, `faceBranchRotation` and
`faceChart` — but **no `stepU`/`stepV` and no node counts**. `cell.lattice[k].latticeCoordinate`
is published at `:13005-13008` and reaches the consumer through
`SurfaceFrontEdge::fromLattice`/`toLattice`, but the lattice **coordinate** without the
**step** does not determine the UV. So a consumer-side probe at `:19360` cannot rebuild the
producer's sample point exactly. Rung 14 must either recover the step from published state —
and say how — or move the emission producer-side.

#### RA-73.8 CHARGE — the beacon was left `IN_PROGRESS` with a self-referential `Successor`

`STATUS` reads `Turn: M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST`,
`Status: IN_PROGRESS`, `Successor: M6-CP3-TB6-R7-NODE-ADMISSIBLE-FACE-SET-HARVEST` — the
turn naming itself as its own successor. **Four consecutive NEXT_TURN blocks have instructed
"leave `Successor` EMPTY while in progress, never self-naming (RA-67.11)."** This is a
machine-read state field, not prose, and a successor reading it is handed a cycle. The
durable closeout was also left incomplete: `Regression_Root_Cause_Tracker.md` and
`ORIENTATION.md` were not updated. This Review closes the beacon and restores both.

**Credited, separately:** the commit subject says "preserve TB6 R7 **incomplete**
durable-closeout beacon" — the turn declared the incompleteness rather than faking a close,
which is the right instinct and the reason this is one charge and not two.

#### RA-73.9 `RP-01` state

The repair premise is **sharper, not settled**. The question has moved from "does the node's
admissible set contain the path's face?" — answered **yes**, at the published position — to
"**what set did the producer choose from, and why did it take the largest member of it at
one corner and the smallest at the other?**" Until that is measured at the producer's own
sample point, the R7 §3.2 binding remains unauthorized. **Code remains NOT authorized.**
`RP-02` **UNREACHED**.

#### RA-73.10 LESSON — a faithful instrument at the wrong sample point is still the wrong measurement

Rung 12 eliminated instrument error completely by calling the production predicate instead
of copying it, and the result is still not decisive, because the *point* it sampled was not
the point the producer sampled. **Fidelity of the test and fidelity of the input are
separate obligations; satisfying one conspicuously well does not discharge the other.**
When a measurement is built to adjudicate a producer's choice, sample where the producer
sampled, and state explicitly which input you used and why.

---

#### Rung 14 — scope

`M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE`, **compile-only**. Emit, for the ambiguous corner
only, the **pre-snap** candidate evidence at the **producer's own lattice UV**: the sample UV
itself, and for each active face the raw unsnapped barycentric from `face_barycentric_from_uv`
together with the pass/fail of the containment test. The single decisive question: **at the
producer's sample point, is the published face the minimum admissible one?** If yes,
RA-72.6 stands and the snap explains RA-73.5; if no, the selection rule is something neither
document has identified and the repair shape changes again.

Rung 15 harvests; rung 16 implements only if the premise survives.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `4d64b7684`.** Every earlier artifact — `11994726341`,
`11996317553`, `12005034654`, `12010485442`, `12019178209`, `12021892076` and now
`12024554349` — is a **baseline, never a comparand**. The 44 RED are the baseline for
`4d64b7684` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-71.6 AMENDED
and now contradicted at one corner (RA-73.5) pending rung 15. RA-72.8 WITHDRAWN (this
decision). Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01` (RA-70.11).**
`PROCESS-01` discharged. `RP-03` satisfied a ninth consecutive turn.

**Successor:** `M6-CP3-CB7-R7-LATTICE-UV-CANDIDATE-PROBE` (rung 14).

## `Architecture_M6_CP3_R8_Boundary_Override_Authority_Spec_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R8_Boundary_Override_Authority_Spec_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R8 boundary-override authority (rung 16)

**Review turn:** `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC-REV`
**Adjudicated:** `M6-CP3-DEFN-R8-BOUNDARY-OVERRIDE-AUTHORITY-SPEC` (rung 16)
**Frozen amendment:** RA-75
**Verdict:** **ACCEPTED**, with one charge and one note. It answered all four questions,
and it **corrected this reviewer's framing of the override**.
**Review window:** 2026-10-16T08:10:44Z — 2026-10-16T08:51:02Z
**Semantic source:** unchanged at `cdd6dc4a9ba95a42aace6226194b38e712b53e4b`

---

#### RA-75.1 Provenance and boundary

| check | result |
|---|---|
| snapshot run `38868534647` | `conclusion=success`, `head_sha=e8db3859b` |
| snapshot artifact `12032341939` | digest `ae817b332a1fb8e862f036578c22211d8a9c194bfaf8d9796a5f94b1d638d0be`, matches |
| `src`/`include`/`tests` at `e8db3859b`, `cdd6dc4a9`, `HEAD` | **tree-identical** — `43a6494a27…`, `790328c2bc…`, `cbef8d5ec4…` |
| turn boundary | documents only; no `src/`, `tests/`, `include/`, `cmake/`, `benchmarks/`, `.github/` change |
| `ledgers --base 298b6779d` over the agent's range | **ALL CHECKS PASSED** — no shrink |

#### RA-75.2 Q1 answered, and the answer is decisive: face 7 is not a stray value

Verified at `src/geometry/SurfaceCellTracing.cpp:17117-17118` and `:17139-17140`, in both
the forward and reverse ordinal loops:

```cpp
!append_point(*firstParameter,  run.sourceFaces[edgeIndex]) ||
!append_point(*secondParameter, run.sourceFaces[edgeIndex])
```

**The accepted boundary point's face comes from `run.sourceFaces[edgeIndex]` — the source-edge
run's own face — never from a chart selector.** So the published face 7 carries genuine
accepted-conformity source-edge authority. It is not an error value, and the three rungs
spent suspecting the chooser were, in retrospect, looking at the wrong object entirely.

The flags are as stated: `useAcceptedConformity = hasTopologyPlan && hasBaselinePlan`
(`:14993`), while `useAcceptedCutDomain = useAcceptedConformity && regionHasHardFeature`
(`:14998`) — **not coextensive**, exactly as the specification says.

The authority is structural, not merely point-level: at `:17204-17215` the grid interval
counts themselves are taken from `acceptedBoundary[side].intervals.size()`, with
`bottom != top || right != left` rejected. The accepted boundary therefore sizes the
producer's lattice before any sampling happens.

What the specification correctly declines to claim is equally important: nothing proves the
accepted point's `.face` must equal the chart sample's, be the unique incident face, or be
correct for **both** directed-side carriers. And its warning not to replace `.face` without
transporting barycentrics is right — a face-relative coordinate is meaningless against a
different face.

#### RA-75.3 Q2 answered honestly, and it corrects me

The guard is `v == 0 || u == gridU || v == gridV || u == 0` under accepted conformity: it
selects **every** grid-boundary node and knows nothing about the failing or control cohorts.

The specification then makes a point I did not: **an unchanged `FirstTo` face 0 may also
have been replaced** — the measurement cannot distinguish "the override did not fire" from
"the override fired and produced the same face." My RA-74.1 framing implied the
substitution is what distinguishes the 21. **It does not, and that is not established.**
Credited, and RA-74.1 is narrowed accordingly: what is measured is that at `SecondFrom` the
published face differs from the sample, not that the override is junction-specific.

#### RA-75.4 CHARGE — the cohort "discrepancy" is one population counted in four domains

The specification writes that TB7 has "**27** `producer=none` control occurrences (54
endpoint records)" while "the older R5 controls numbered **23**", and concludes that
"without cross-vintage identity mapping, neither '21 exactly boundary' nor '23/27 exactly
interior' is established."

There is no cross-vintage discrepancy. Recomputed from `producer-presnap-candidates.tsv`:

| count | domain |
|---:|---|
| **54** | control **endpoint records** (two per occurrence) |
| **27** | control **occurrences** (54 ÷ 2) |
| **23** | control **ledger entries** (21 singles + 2 entries emitting 3× each) |
| **22** | control **distinct identity strings** (one entry is a deliberate duplicate) |

Measured directly: control rows 54, distinct identities **22**, and per-identity record
multiplicity `{2: 21, 12: 1}` — twenty-one identities contributing two records each and one
contributing twelve, which is the duplicated identity emitting three times on two ledger
entries. The duplication is deliberate and documented in the agent's own commit
`c4da30a37` ("preserve intentional **duplicate** TB identity").

So 23 and 27 are **the same population counted in two different index domains**, and no
identity mapping is required. **This is RA-67.13 recurring a third time** — derived at
RA-67.5, charged at RA-70.8, and charged again here: *name the index domain of every
identifier you print.*

The resulting caution — "do not code to these cohort counts" — is prudent and survives,
because the specification's **other** ground for it is sound: the override state at the
control nodes was never measured (RA-74.7). The conclusion stands on one good leg and one
bad one, and a successor reading the bad one would believe two vintages disagree when they
do not.

#### RA-75.5 Q3 — it declines to name a single owner, with a reason, and that is admissible

I asked for the owning authority, or an explicit statement that the source does not
determine one. The specification gives the latter, with the missing contract named:

- **accepted conformity** owns the published source-edge point and its face-relative
  location;
- **chart sampling** owns interior samples and the preliminary competing representation at
  a boundary;
- **neither face is a unique directed-side carrier certificate.**

That last clause is the substance, and it is consistent with RA-72.4's per-directed-side
necessity: a single corner face cannot be authoritative for both the incoming and outgoing
side, so the question "which face is the corner's" is malformed as posed. The reframing of
`RP-01` as **missing boundary-point-to-directed-side carrier reconciliation**, explicitly
**not** a proven downstream-only bug, is the right disposition on this evidence. An
inadmissible answer is a result (RA-68.12), and this one is argued rather than dodged.

The side paths it cites do carry the needed material: `cell.boundaryPaths[side]` is built by
`bounded_disk_chart_segment` at `:17383-17390`, and `SurfaceTraceSegment`
(`include/directional/geometry/SurfaceCellTracing.h:1211-1232`) carries `face`, both
barycentrics, `sourceChart` and a typed `entryRoute` — verified at RA-72.3 and unchanged.

#### RA-75.6 Q4 — a proper admissibility table

Six candidates, each adjudicated: two **admissible shapes only** (reconcile canonical
source-entity/sheet and side-specific face/chart/route while preserving accepted edge
placement; publish separate directed-side face/chart/route rather than one corner face),
one **relocation only** under RA-72.5 (raw face equality at the override or the consumer —
rejects the same 21 earlier and creates no successful cell), and three forbidden, including
inventing a vertex-star route, which is correctly refused under RA-65.5 with gate C
suspended. Seven falsifiers F1–F7 are stated and none is claimed as executed.

#### RA-75.7 Credits

- **Both RA-74 charges absorbed in one rung.** `ledgers --base 298b6779d` passes clean over
  the agent's range — the ledger was prepended, not overwritten — and `ORIENTATION.md` was
  written after two consecutive omissions.
- **Beacon correct**: `COMPLETE` with a named Successor, not self-referential.
- It corrected the reviewer on the override's scope (RA-75.3). **`RP-03` satisfied an
  eleventh consecutive turn.**

#### RA-75.8 NOTE — the tracker was not written

`Regression_Root_Cause_Tracker.md` is absent from the rung-16 diff, though rungs 10 and 11
wrote it. Not charged — the Review writes the authoritative tracker section regardless, and
the agent's three prior omissions were in documents where the gate floors could have been
threatened. Recorded so the pattern does not drift further.

#### RA-75.9 `RP-01` state

**Reframed, not resolved.** The defect is now *missing reconciliation between the accepted
boundary point and the directed-side carriers*, with two mutually exclusive branches:

- **(a)** the accepted and chart points denote **different source entities or sheets** → the
  override is invalid upstream and must be rejected;
- **(b)** they denote the **same** point and only raw face equality is being demanded → the
  consumer's representation contract is wrong.

**These branches imply opposite repairs.** Nothing yet distinguishes them. **Code remains
NOT authorized.** `RP-02` **UNREACHED**.

#### RA-75.10 LESSON — when a specification offers two branches with opposite repairs, the next rung measures the discriminator, not the branches

It is tempting to specify both repairs and pick later. The cheaper and safer move is to
measure the one fact that eliminates one branch. Here that fact is small, already
representable in published state, and obtainable from a probe that is a near-copy of one
that has already worked three times.

---

#### Rung 17 — scope

`M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE`, **compile-only, rejection-only**, in the
rung 14 producer-side pattern. For **every** grid-boundary node reached in a rejected case,
emit:

1. **whether the override fired** — the `accepted != nullptr` outcome at `:17278` — which
   settles RA-75.3's open question of whether `FirstTo` is also overridden;
2. the **exact source entity** of the chart sample, barycentric-exact: the source vertex id
   when a coordinate is exactly `1`, otherwise the source edge plus its exact parameter when
   a coordinate is exactly `0`, otherwise interior;
3. the **exact source entity** of the accepted boundary point, by the same classification.

One run then answers the branch discriminator: **do the two points denote the same source
entity?** Same entity → branch (b), the override is legitimate and the consumer contract is
at fault. Different entity or sheet → branch (a), the override is invalid upstream. This is
the specification's own F1 falsifier, measured.

Rung 18 harvests; rung 19 defines or implements the repair for whichever branch survives.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark, no binary executed. No source,
test, selector, binary, harness or workflow change by this Review. PR #8 draft/open.

`R4-VIN-01` remains armed at `cdd6dc4a9` — the semantic source is unchanged by rung 16, and
every earlier artifact through `12028682600`, `12030150301` and `12032341939` is a
**baseline, never a comparand**. The 44 RED remain the baseline for `cdd6dc4a9` alone,
candidate / non-stable.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED (this decision) — the
override is not shown to be junction-specific. Gate C SUSPENDED (RA-65.5, RA-68.3) and moot
for `RP-01` (RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied an eleventh
consecutive turn. The historical `ledgers` failure at `b2b6e6541` remains permanent for any
base earlier than it, is correct, and must not be suppressed.

**Successor:** `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` (rung 17).

## `Architecture_M6_CP3_R8_Source_Entity_Equivalence_Review_Decision.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R8_Source_Entity_Equivalence_Review_Decision.md`; moved verbatim.

### Architecture Review Decision — M6 CP3 R8 source-entity equivalence (rungs 17 and 18)

**Review turn:** `M6-CP3-R8-SOURCE-ENTITY-EQUIVALENCE-REV`
**Adjudicated:** `M6-CP3-CB8-R8-SOURCE-ENTITY-EQUIVALENCE-PROBE` (rung 17) and
`M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST` (rung 18)
**Frozen amendment:** RA-76
**Verdicts:** both **ACCEPTED**. **The branch is settled: (b).** Two charges.
**Review window:** 2026-10-16T09:40:07Z — 2026-10-16T10:31:55Z
**Semantic source:** `f0d7240455b10237af47de58c035cd4c576d889a` (new — `R4-VIN-01` re-arms)

---

#### RA-76.1 THE RESULT — branch (b), and no row anywhere denotes a different source entity

Re-derived independently from `source-entity-census.tsv`: **2,628 rows, 0 errors**, three
outcomes — `carrier-orientation` **1,008 SAME / 0 DIFFERENT**;
`not-same-interior-carrier-point` **1,296 SAME / 324 DIFFERENT**.

**The 48 decisive comparisons.** Every row with `sampled_face=3` and `accepted_face=7`
resolves to the **same canonical source vertex**: 42 × `vertex:4 ‖ vertex:4` and
6 × `vertex:2 ‖ vertex:2`, all 48 classified `SAME_ENTITY`. (The 4/2 split is the RA-67.5
first-appearance vertex compaction appearing yet again — one phenomenon in two index
domains, now at occurrence granularity.)

**The 324 are not a counterexample, and this is measured rather than characterised.** The
record describes them as "one-ULP-like hexfloat edge-parameter representations." Verified
exactly, by parsing every token and computing the integer ULP distance:

| check | result |
|---|---|
| rows classified `DIFFERENT_ENTITY` | 324 |
| of those, on the **same canonical edge** | **324 / 324** |
| ULP distance histogram | **`{1: 324}`** — every one is exactly one ULP |
| `DIFFERENT` rows involving a **vertex** entity | **0** |

So all 324 differ only in the final mantissa bit of an edge parameter **on an identical
canonical edge**. **No row in the census denotes a different source entity or sheet.**
Branch (a) — "the accepted and chart points denote different source entities, so the
override is invalid upstream" — has **zero support in the measurement**. **Branch (b)
stands: the override substitutes a different *representation* of the same source entity,
and the defect is the consumer's contract demanding raw face equality.**

#### RA-76.2 RA-75.3's open question is closed by measurement

`override` is `1` on **all 2,628 rows**. The substitution fires at **every** measured
grid-boundary node, including the `FirstTo` corner whose published face equals its sample.
So `FirstTo` *was* overridden and happened to agree. **RA-74.1's narrowing (RA-75.3) is
confirmed: the override is not junction-specific**, and the earlier appearance that it
distinguished the 21 was an artefact of only one corner's face changing.

#### RA-76.3 Rung 17 — the first probe with deletions, and they are correct

Three lines were deleted, which no prior probe did, so each was checked individually:

```cpp
-      const int sampledFace = points[node_index(u, v)].face;
+      const SurfaceTracePoint sampled = points[node_index(u, v)];
+      const int sampledFace = sampled.face;
+      const SurfaceTracePoint *accepted = nullptr;
       if (useAcceptedConformity) {
-        const SurfaceTracePoint *accepted = nullptr;
```

Both edits are **semantics-preserving**: `sampledFace` holds the same value, and the
`accepted` declaration is hoisted out of the `if` with its `nullptr` initialisation intact,
so it is `nullptr` exactly when the block does not run. The widened capture is what
instruction 2 required — the substitution at `:17279` overwrites in place, so the point had
to be copied before it was destroyed — and the hoist is the only way to observe the
`accepted != nullptr` outcome that instruction 1a demanded. **Minimal and necessary.**

**Neutrality verified.** The emission sits at depth 1 inside the rejection branch, which
opens at `src/geometry/SurfaceCellTracing.cpp:19507` and closes at `:19825`; the new
emission is at `:19743`. No added line assigns to `points[`, `cell.`, `proposal.` or
`frame.`; the only `result.*` writes are to the diagnostic map
`boundarySourceEntityProbes`, declared beside the existing `latticeUvCandidateProbes` and
propagated by a plain map merge at the region build. The consumer hunk is a read-only
iteration filtered to the two involved regions, emitting `none` when empty.

**The classifier is built in the right domain** — the RA-75.4 lesson applied one rung after
it was charged. `source_entity` tests `point.barycentric[i] == 1.0` and `!= 0.0`
**exactly**, with no tolerance, as instructed; it reports a vertex as a **source vertex id**
`faces(point.face, i)` and an edge as a **canonical `(lo, hi)` source-vertex pair** with the
parameter in hexfloat. That is what makes a point in face 3 and a point in face 7
comparable at all — the identity is expressed in a domain both faces share.

#### RA-76.4 Chain and artifacts, re-derived

| check | result |
|---|---|
| probe commit `f0d724045` cpp blob | `fd07f514dab95b5fa9ecde35c8b0eec294c729ee` = **HEAD** |
| `include` / `tests` at `f0d724045` and HEAD | **byte-identical** |
| snapshot `12035302774` (run `38876338945`) | digest `0577eedd0c31…`, success |
| patch-apply `12035488476` (run `38877023124`) | digest `2fb730bb1a4b…`, success |
| compile `12035788036` (run `38877282902`) | digest `1967771d10b7…`, success |
| result `12036818514` (run `38880040401`) | ZIP **recomputed** `4305035309ef…`, success |
| result manifest | **49 OK / 0 BAD** |
| `execution-boundary.txt` | `planned=44 executed=44 red=44 missing=0 postflight=True exit=0`, `compile=false relink=false benchmarks=false selector497=false` |
| disclosed failure `38879689539` | independently **`conclusion=failure`** |
| disclosed failure `38879850655` | independently **`conclusion=failure`** |
| `ledgers --base 7f5160cd8` | **ALL CHECKS PASSED** — no shrink; RA-74.6 not repeated |

Both dispatcher failures are real — an unsupported `environment_json` and an incorrect
copied selector digest, each rejecting before any test ran — and both were disclosed with
their run ids when only the third run carries evidence. **`RP-03` satisfied a twelfth
consecutive turn.**

#### RA-76.5 CHARGE — the result is hedged where it is actually total

The record writes that the 324 "**include** one-ULP-**like** hexfloat edge-parameter
representations, not proof of illegal topology." Measured: **all 324, exactly one ULP, on
an identical canonical edge, with no vertex entity involved.** The hedge understates a
clean and complete result, and leaving "324 DIFFERENT" unqualified in the same paragraph
invites a successor to believe branch (a) retains partial support. **It retains none.**

This is the fifth turn in the claim-calibration family — RA-67.9, RA-70.7, RA-71.10,
RA-73.6 and now RA-76.5 — though not monotone, since RA-74.9 credited a correction and
RA-75 was well-calibrated. The pattern is specifically that **a hedge is attached to a
measurement that the turn's own data already settle**.

#### RA-76.6 CHARGE — the beacon is `IN_PROGRESS` with a self-referential `Successor` again

`STATUS` reads `Turn: M6-CP3-TB8-R8-SOURCE-ENTITY-EQUIVALENCE-HARVEST`,
`Status: IN_PROGRESS`, `Successor:` naming that same turn. **Six consecutive NEXT_TURN
blocks have required `Successor` be left EMPTY while in progress and never self-naming
(RA-67.11).** RA-73.8 charged exactly this; it was then correct for two rungs and has now
recurred.

**Mitigation, and it is substantial.** The cause is a genuine transport failure — the
closeout patch could not be applied because "Files reported no active container session" —
and the record says plainly "**do not claim this patch pushed**" and "keep current TB8 turn
IN_PROGRESS until verified remote apply." Declaring an incomplete closeout rather than
faking one is the correct behaviour. The charge is narrow: the `Successor` field costs
nothing to leave empty, and a successor reading it is handed a cycle.

**Consequence:** `Regression_Root_Cause_Tracker.md` was again not written, its content
staged in an unapplied patch. This Review writes the authoritative tracker section and
closes the beacon.

#### RA-76.7 A latent locus the measurement exposes

The accepted boundary and the chart sample compute the **same** edge parameter to within
one ULP but **not bit-identically** — 324 instances. Any consumer that compares those
parameters by exact equality will fail on them. Nothing in the measured 44 turns on this
today, because the failures are vertex cases, but it is a real property of the two
producers and it bears directly on the contract rung 19 must specify. Recorded as backlog;
**not authorized for repair**, and specifically **no epsilon may be introduced to paper
over it** — the contract must say what equality is required, not loosen a comparison.

#### RA-76.8 `RP-01` state — every producer is now exonerated

For the first time, the chain is clear end to end:

| component | status |
|---|---|
| chart sampler (`point_on_periodic_chart`) | **exonerated** — RA-74 measured `sampled-min` in all 21 |
| planar selector (`point_on_source`) | **exonerated** for these cells — RA-71.5 amended |
| accepted-boundary producer | **exonerated** — RA-75.2, face from `run.sourceFaces[edgeIndex]` |
| the override itself | **exonerated** — RA-76.1, same source entity in every row |
| route publisher, carrier producer, tracer, `from` corner | **exonerated** — RA-70.7 |
| **consumer endpoint admission** | **the sole remaining candidate** |

`RP-01` is therefore **localized to the consumer's endpoint-equivalence contract**: the
admission test compares raw `SurfaceTracePoint::face` where the producers only ever
guaranteed *source-entity* identity. **Code remains NOT authorized** — the contract has to
be specified before it is changed, and the obvious weakening is exactly the kind of
predicate relaxation that has been prohibited throughout. `RP-02` **UNREACHED**.

#### RA-76.9 LESSON — a classifier stricter than the question answers a different question

`DIFFERENT_ENTITY` was reported 324 times and the entity was identical every time; the
classifier compared exact float tokens where the question asked about entities. **When a
measurement's verdict column disagrees with its own evidence columns, the verdict is the
thing to re-derive.** Had the 324 been taken at face value, branch (a) would have looked
partially alive and the next rung would have been scoped to adjudicate a difference that
does not exist.

---

#### Rung 19 — scope

`M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC`, **documents only**. Branch (b) is
settled, so the question is what the consumer's contract should be:

1. **Where exactly does admission demand raw face equality?** Name every comparison in the
   endpoint-certificate path that tests `SurfaceTracePoint::face` or a face-keyed lookup
   against a corner, with line anchors.
2. **What equality did the producers actually guarantee?** RA-75.2 and RA-76.1 establish
   source-entity identity, not face identity, and RA-76.7 shows edge parameters agree only
   to one ULP. State the guarantee precisely, including the ULP caveat.
3. **Specify the contract the consumer should require**, and prove it is not a weakening:
   show what it would *still* reject. The carrier is edge-keyed (RA-67.6) and the measured
   `to` endpoint is a vertex of the crossed edge, so an incidence-based test is the obvious
   candidate — and the obvious danger. **Gate C remains SUSPENDED (RA-65.5, RA-68.3) and no
   vertex-star predicate may be introduced**, so the contract must be expressible from
   already-published witnesses.
4. **Apply RA-65.5**, and say for each candidate whether it is repair or **relocation**
   (RA-72.5).

No code, no compile, no runtime. Specifying the contract and proving it does not weaken
admission is the deliverable.

---

#### Accounting

Ledger **66 / 17 / 49**, M6 debt **1**, CP2 **491/491** accepted, R3 **403/497** rejected,
frozen selector **497** — unchanged. No promotion, no stable event, no regression
recurrence, no gate credit, no 497 execution, no benchmark. No source, test, selector,
binary, harness or workflow change by this Review. PR #8 draft/open.

**`R4-VIN-01` re-arms at `f0d724045`.** Every earlier artifact — through `12030150301`,
`12032341939`, `12035302774`, `12035788036` — is a **baseline, never a comparand**. The 44
RED are the baseline for `f0d724045` alone, **candidate / non-stable**.

**RA-61.9 WITHDRAWN, final. RA-64.6 WITHDRAWN, final. RA-70.14 WITHDRAWN. RA-72.8
WITHDRAWN. RA-71.5 AMENDED. RA-73.5 SUPERSEDED. RA-74.1 NARROWED and now CONFIRMED by
measurement (RA-76.2). Gate C SUSPENDED (RA-65.5, RA-68.3) and moot for `RP-01`
(RA-70.11).** `PROCESS-01` discharged. `RP-03` satisfied a twelfth consecutive turn. The
historical `ledgers` failure at `b2b6e6541` remains permanent for any earlier base, is
correct, and must not be suppressed.

**Successor:** `M6-CP3-DEFN-R9-ENDPOINT-EQUIVALENCE-CONTRACT-SPEC` (rung 19).

## `Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Factory_Incidence_Oracle_Source_Validity_Static_Audit_20261011.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — hard-rail incidence oracle and frozen DCEL fixture source-validity audit

**Status:** Static source audit only, **not** a normative definition or runtime Test + Benchmark. Canonical R4 remains `IN_PROGRESS`, successor `UNKNOWN`. No source/test executable run; no accept/reject result is inferred.

#### Exact evidence

- Verified snapshot workflow [`38154965590`](https://github.com/akashskypatel/Directional/actions/runs/38154965590), job `114515978657`, event/source `57540deb13da2eb14bea9352f28670160026e780`, artifact `11708521074`, ZIP SHA-256 `ead51d98ff2a436c237067a22d2fa209e82297426ee36fd5e1e200fe236ccea5`.
- Inner `source.tar.gz` SHA-256 `923d97f6a3408a7fb6a13fed5f2f60dbbee060516d25025214370dd077278d70`; complete `SHA256SUMS` **6207/6207** entries pass, snapshot metadata `runtimeExecution=false`.
- Frozen historical first-failure source: `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`; current source is after multiple compile-only fixture repairs. No current R4 runtime failure evidence is available.

#### Specific uncovered risk: three-face rail-incidence oracle is potentially vacuous

`tests/SurfaceCellTransitionQuotientTests.cpp`, `SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences`, builds `attempt(count, reverseRows, publishTransition, absentRail)` and asserts a typed `InvalidSourceAuthority` result for `count=3`. All three synthetic triangles share the hard edge `{0,1}`. The fixture constructs `TriMesh` and `FieldTransportAtlas::make` from that three-incidence source. The factory invocation permits `sourceAtlas ? &sourceAtlas.value() : nullptr`, and the test expects `InvalidSourceAuthority` for `count=3` regardless of why that result occurs.

**Independent product code:** `SurfacePhaseFrontProduct::make` (`src/geometry/SurfaceCellTracing.cpp`, starting near line 8045) rejects a null A3 atlas and any A3/source mismatch **before** counting incidences; the actual `railIncidenceCounts` overfull-edge guard is later, around lines 8155–8187. Therefore, if the nonmanifold three-face atlas cannot be constructed, the test's expected enum may still pass at the *wrong first predicate*. If `TriMesh::set_mesh` throws for this nonmanifold source, the body instead fails before the checked factory. Neither outcome has been observed; this is a static oracle soundness risk, **not** a proven runtime failure.

**Non-vacuity requirement:** To count as a regression for the checked-factory >2 rail-incidence guard, the fixture must prove non-null exact source-bound A3 and a positive comparison that reaches the incidence gate. If the accepted two-manifold source/A3 contract makes that witness unrealizable, request an independent Definition/Review ruling and retain a separate producer-side nonmanifold-source negative. Do **not** treat an `InvalidSourceAuthority` enum produced by the earlier null/mismatched-A3 gate as proof that the later overfull-incidence guard was exercised. Do not fabricate a nonmanifold atlas or remove A3 matching to make this test pass.

#### Seven frozen R3 DCEL cases — current source inventory, not acceptance

Frozen RED ordinals **40, 220, 221, 296, 302, 304, 439** had `DCEL_FIXTURE_CONSISTENCY_EXCEPTION` in the rejected R3 run, including `compute_edge_quantities(): DCEL consistency check failed`.

- Ordinal **40**, `FlowRepStrandsPhase15.RailTruncatedGenericSupportDoesNotInheritLaterTerminalAnchor` in `tests/FlowRepStrandsPhase15Tests.cpp` around line 1448, now supplies two consistently oriented faces `(0,1,2)` and `(0,2,3)` to `attach_source_authority` (four vertices; face 0 geometry retained).
- Ordinals **220, 221, 296, 302, 304, 439** in `tests/SurfaceCellTransitionQuotientTests.cpp` share `direct_periodic_owner_fixture` (around line 244). This now builds a two-triangle source disk `(0,1,2)` and `(0,2,3)`, `SourceTopologyRegions`, independent `FieldTransportAtlas::make`, and a checked `SurfacePhaseFrontProduct`. The named negative tests subsequently mutate relation-owner/order/identity evidence; their frozen identities and expected error codes remain.

A static topology check finds the shared diagonal `(0,2)` has exactly two opposite-oriented incidences and boundary edges one each in both fixture source disks. This removes the obvious one-face or inconsistent-winding preflight weakness, but **does not prove** DCEL runtime construction, the checked factory's positive preflight for every case, or the intended first negative rejection. Earlier source fixture corrections compiled GREEN; no frozen 497-case execution is authorized in current Code + Build. Leave all **seven** RED obligations open pending a separate source-exact, artifact-only Test + Benchmark turn.

#### Targeted corrective work, without premature acceptance

1. Design/review the three-face A3 feasibility condition. If feasible, add an independently constructed exact source A3 and assert non-null/source matching **before** crediting overfull-incidence rejection; if impossible under manifold A3, split the nonmanifold producer negative from A4 checked factory tests without weakening either contract.
2. At the next *authorized* artifact-only runtime checkpoint, record whether the seven frozen DCEL identities still throw or now reach intended typed guards. For any changed first rejection, diagnose exact test fixture and factory independently. Do not mark a pass from these static observations.
3. Preserve historic accepted CP2 `491/491`, rejected R3 `403/497`/`94 RED`/`88 previously accepted losses`, and the untouched R4 39 endpoint / 34 Phase10 / six CP3 / genuine multi-carrier odd-τ / independent terminal two-path review obligations. Do not execute tests, discovery, CLI or benchmarks in this Code + Build turn; do not authorize its successor based on this audit.

## `Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Terminal_A3_Uniqueness_Design_Review_Request_20261011.md`; moved verbatim.

### R4 source-vertex terminal A3 dual-path expectation — independent Review request (2026-10-11)

**Classification:** bounded, **static topology deduction; not accepted Definition, runtime evidence, test pass, or authorization to change a frozen selector**. Canonical work remains `M6-CP3-CB1-ENTRY-R4` Code + Build, with `STATUS` incomplete. No Directional binary, discovery, tests, benchmark, or Test + Benchmark harness was run for this note. This document asks the independent producer/Definition Review to decide whether the historical *second admissible non-hard terminal path* negative is mathematically realizable under the accepted RA-37a source-manifold contract.

#### Exact source evidence

- Snapshot workflow `38139725760` captured event/source `5a7288c254f2b6d96320a5f645d3dcfb4bc4254b`, artifact `11702465829`, provider ZIP SHA-256 `579c09b95bd404644cd4f61b15e6dac0806c87a403c6072d9684c7e43009ad8d`; inner archive and **6,164/6,164** source manifest entries checked, `runtimeExecution=false`.
- Producer `src/geometry/SurfaceCellTracing.cpp` (`endpoint_certificate`, approximately lines 18915–19079) requires a *real contact terminal vertex* on the first/last hard carrier, exact trace-vertex barycentric attachments on both sides, and reciprocal non-hard A3 arcs. Its `path_to` counts simple paths and accepts exactly one. It excludes every spoke in `hardFeatureEdges` when building `localStar`, and its carrier is an incident hard-feature edge.
- Checked A4 `SurfacePhaseFrontProduct::make` (approximately lines 8160–8360, 8400–8555) independently reconstructs each terminal's source-star spoke/face adjacency, disallows spokes of incidence above two, excludes hard-feature spokes, and independently counts exactly-one simple non-hard path. It also checks terminal vertex, true carrier incidence, exact corner attachments, path edge/face continuity and A3 transport; a forged certificate is not sufficient.
- Accepted RA-37a Review (`Architecture_M6_DEFN_R5_R3_Review_Record.md` A1/A3) explicitly requires a connected oriented two-manifold source vertex link with owner hard rays. Broadening the admissible graph to nonmanifold branching is *not* authorized by the existing Review.

#### Why an admissible second simple path appears impossible

Let `v` be a genuine terminal vertex on a hard carrier `h`. Build the source-face link graph at `v`: each incident triangle is a vertex of this graph, and each source spoke with two incident source triangles is an adjacency edge. Every distinct source triangle has exactly two edges incident to its corner `v`, so each face-vertex of the link graph has degree at most two; the accepted oriented two-manifold link component is therefore a path (boundary fan) or a simple cycle (interior fan). Every terminal carrier `h` is a spoke incident to `v`, and `h` is *excluded* from the admissible non-hard graph. Cutting at least this one spoke converts its link cycle to a path, or removes an edge from a preexisting boundary path. The component of any carrier-side face is then acyclic. In a forest, any ordered pair of faces has **at most one simple path**, regardless of which reciprocal A3 quarter-turns are admitted. Additional hard-feature cuts or rejected A3 links only delete edges; they cannot create a second path. An attachment outside the carrier component has zero paths, not two.

The argument is conditional on source-valid distinct triangles and manifold fan ownership as accepted by RA-37a. It does not claim the current implementation proves global manifold validity for arbitrary hostile inputs. A nonmanifold/degenerate fabricated graph that yields two paths would **not** establish an admissible source witness, and checking that a generic DFS rejects multiple paths is not the same as producing a valid witness.

#### Required independent Review decision

1. **Confirm or refute the graph lemma** against the authoritative RA-37a source-domain rules, including boundary fans, source region component/sheet ownership, and valid open-rail contacts. A counterexample must provide exact source faces, source edges, terminal owner, and two complete distinct admissible simple paths without violating any current A2b/A3/manifold rule.
2. If the lemma holds, **retire only the impossible literal two-admissible-path source-witness demand** through an explicit independent Definition/Review amendment. Retain the fail-closed `pathCount != 1` guard as a defense against malformed input; its diagnostic `ambiguous-terminal-A3-path` need not be reachable for valid manifold fixtures.
3. Replace the impossible fixture obligation with bounded, source-valid first-rejection negatives: missing terminal walk, overlapping source-owner sectors, absent/reversed A3 transport, or wrong terminal/corner binding, each verified at its actual first rejecting A4 predicate. Do not change frozen test identities or assert a runtime outcome in this Code + Build turn.
4. If a second admissible path **must** remain required, stop before implementation and specify a *new* source topology class beyond the accepted two-manifold link. That is a Definition + independent Review gate, not permission to relax source incidence or synthesize a nonmanifold fixture.

**Other R4 obligations remain untouched:** all 39 endpoint, 34 Phase10, seven DCEL, 88 CP2 accepted losses, six CP3 positives and source-real multi-carrier/odd-τ witnesses require separately authorized runtime proof. Frozen CP2 `491/491` is the latest accepted baseline; rejected R3 `403/497` is not promoted. The present analysis changes neither A4 nor any runtime acceptance result.

## `Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Edge_Index_Namespace_Conflict_Review_Stop_20261012.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — source-edge index namespace collision (review stop)

**Classification:** `REVIEW_BLOCKER` on the *current* R4 Code + Build turn. The observed source contradicts a previously accepted Review namespace definition. This document is a **source-exact finding/request**, NOT a new accepted Definition, independent normative Review decision, run of a C++ executable, or authorization for TB497. Do not silently change `SurfaceCellRail::sourceEdges` semantics inside the blocked Code + Build turn.

#### Exact provenance and existing authority

- Independently extracted source from exact eight-target GMP/GMPXX compile artifact `11740652527`, run `38236639195`, source `dcf24e2c881b9ed67ec8f992d94d4b4e364fd4e2`. Rechecked ZIP SHA-256 `7af625c8ca0bcbc5f4f59d3793484280157e388db05a412b9d188d4cba1418a2` and packaged `metadata/source-commit.txt`. Earlier compile evidence verified `28/28` package checksums, 8/8 targets, GMPXX/GMP link, build/preflight `0/0`, `runtimeExecution=false`. The source was inspected without running, compiling, linking, or invoking any Directional executable.
- **Accepted RA-43 namespace inventory:** `.agents/Directional/Architecture_M6_CP3_R4_Producer_Locus_Review_Decision.md`, §4, explicitly defines `SurfaceCellRail::sourceEdges` as a **feature-edge index into `featureMap.edges`**. `SurfaceCellRailSample::sourceEdge` is instead the face-local corner index. This accepted decision is binding until a separately authoritative Review amends it.
- **Current producer, source `src/pipeline/RemeshPipeline.cpp`:** `build_authoritative_surface_cell_rails` indexes `featureMap.edges[entry.edgeIndex]` at :9350 and publishes `rail.sourceEdges.push_back(entry.edgeIndex)` at :9359; its single-edge path publishes `rail.sourceEdges = {edgeIndex}` at :9503. These are **feature-map vector positions**, not `TriMesh::EV` positions. Failure `failedEdgeIndex` currently uses the same feature index (:9259-9262, :9535-9537).
- **Current consumer contradicts producer and Review:** `src/geometry/SurfaceCellTracing.cpp:4233-4245` in `canonical_field_aligned_candidate` indexes `sourceMesh.EV(declaredEdge, *)` using `rail.sourceEdges[interval]`, then requires its topological pair equal the independently published typed vertex pair. That is an *unreviewed change of index namespace*, not merely a strengthened equality check.
- **A second consumer has the same inconsistency:** component aggregation in `RemeshPipeline.cpp:17577-17592` constructs `globalEdgeByLocal` indexed by component `TriMesh::EV` local edge. `RemeshPipeline.cpp:18106-18114` uses each rail's feature-map `sourceEdge` as that EV index for remapping, potentially publishing the wrong global index or `-1`.
- **Regression now encodes the opposite interpretation:** `tests/SurfaceCellREPackageTests.cpp:292-298` demands producer raw `rail.sourceEdges` refer to matching `sourceMesh.EV` rows. That test and later compile-only documents used EV semantics without amending the accepted RA-43 Review namespace.

#### Counterexample independently derived from constructors (not a runtime claim)

For a valid single oriented triangle with face vertex row `(0,1,2)`:

| Index | `featureMap.edges` (lexical `std::map` insertion at `AdaptiveFeatureMap.h:181-189, :204-244`) | `TriMesh::EV` (DCEL face/halfedge first encounter `DCEL.h:2993-3059` and `TriMesh.h:154-173`) |
|---|---|---|
| 0 | (0,1) | (0,1) |
| 1 | (0,2) | (1,2) |
| 2 | (1,2) | (0,2) |

The producer therefore emits raw `sourceEdges[interval] = 1` for a genuine rail on `(0,2)`; the current consumer indexes EV row 1 and obtains `(1,2)` and returns `InvalidRailGeometry` although the typed source-vertex chain is exactly `(0,2)`. This is a **structural counterexample to the purported index equivalence**. In a two-face/disconnected/component setting, edge ordering may diverge in still more ways. The counterexample derives solely from current source ordering. The actual default pipeline's first observable runtime error, counts and affected frozen identities remain **unexecuted and unproven**.

#### Required source-exact Definition/Review decision before changing semantics

**Proposed finding:** `R4-IDX-01 / AUTHORITY_DOMAIN_CONFLATION`; candidate repeat of existing RP-01 class. It is **not a newly counted stable regression** without accepted runtime evidence.

1. Independently confirm both indexing domains and all consumers, including component remap, failure diagnostics, rail provenance hashing, the source-built field-aligned candidate, and the already-landed Phase20 positive regression. Check the source of any manually constructed rails.
2. Freeze **one** `SurfaceCellRail::sourceEdges` contract. An EV-index contract is a plausible repair because field-aligned validation and component remap already use EV, but it **requires amending RA-43 §4 explicitly** and converting the producer's curve-run and standalone rails through a checked `(vertex pair) -> meshWhole.EV row` map. Retain feature-map indices in `coveredEdges` and `failedEdgeIndex` with an explicit conversion; do not conflate diagnostic index spaces. Alternatively keep the accepted feature-index contract and redesign both EV consumers to take authenticated feature-map lookup evidence, as well as correcting the test. The current mixed interpretation is impermissible.
3. Require source-valid **nonvacuous** regressions where lexical feature-map and DCEL EV orders differ (including a boundary/hard-feature rail, closed rail, component-local to global remap), plus negative foreign raw-index tests under the newly reviewed contract. A test of only an edge where both indices coincide (e.g. `(0,1)`) proves nothing.
4. Retain source-attested A3/A4, RA-43.4 typed vertex constraints, first rejecting predicate, original 497 selector identities, and independent overfull-A3 Review. No weakening `InvalidRailGeometry` / typed mismatch gates or inferring runtime PASS.
5. On Review acceptance, resume **this same canonical R4 Code + Build** under corrected instructions; then commit a bounded source patch, perform the standard eight-target GMP/GMPXX compile and preserve immutable evidence. Do not start `M6-CP3-TB1-ENTRY-R4-EXEC` beforehand.

#### Boundary and disposition

**REVIEW STOP — UNRESOLVED.** No production, tests, fixtures, selectors, benchmarks, workflow permissions, or frozen normative definitions changed by this finding. Do not treat earlier green compiles or a valid typed vertex chain as confirmation of raw index-domain consistency. Keep R4 stopped for the required source-exact adjudication; successor remains UNKNOWN while its repository-root beacon is blocked. Latest reviewed runtime baseline unchanged: accepted CP2 491/491, rejected R3 403/497, 94 RED/88 accepted CP2 losses, ledger 66/17/49 debt 1.

## `Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_RA465_Ambiguous_Terminal_Contact_Review_Stop_20261012.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — RA-46.5 ambiguous terminal-contact feasibility REVIEW STOP

**Classification:** `REVIEW_BLOCKER` within the *existing* R4 Code + Build turn. This is a source-exact, runtime-free request for independent normative review, **not** an accepted amendment to RA-46.5, not a test/benchmark, and not authorization for the R4 artifact-only 497-process TB or any successor. No code, frozen selector, test identities, validator, workflow permissions, or production semantics are changed here.

#### Immutable inspection authority

- Verified exact source-snapshot workflow `38301273941`, artifact `11770860615`, event/source `69649fda99508310ce93a9e2920da28fa966c578`; downloaded ZIP SHA-256 `4c907baef5ce9d81ed7cf699f9a743327ee76e12226b2bbf69c95627befbce79`; nested `source.tar.gz.sha256` and **6535/6535** source-manifest entries verified locally. PR #8 on `agent/surface_cell_quad/p5-recover-bridge-healing` is draft/open. Compare to entry branch head `0f34f7b170a9902628426aa1311cb3901fe654e8`: only `STATUS` and source-snapshot mailbox records changed; all inspected semantic source and frozen definitions are identical.
- The previous exact-source GMP/GMPXX eight-target **compile-only** proof remains run `38293645339`, immutable artifact `11767745994`, semantic `9c75f44dab79cd3b5ad014d918f15f808b6ac504`, 28/28 packaged checksums, build/preflight 0/0, `runtimeExecution=false` (per the existing RA-43.4 closeout). No new compile, binary execution, Test + Benchmark, or runtime PASS is claimed.

#### Conflict between frozen requirement and reachable consumer state

1. Frozen `.agents/Directional/Architecture_M6_Frozen_Definitions.md:201-205` (RA-46.5) explicitly requires a replacement negative at the **actual first rejecting predicate** `ambiguous-terminal-contact`, along with five other named predicates and typed factory subcodes. RA-46.4 previously retired a different mathematically unrealizable ambiguous-path witness only through independent Review; this new ambiguity is **not** thereby retired.
2. Pipeline `src/pipeline/RemeshPipeline.cpp:9649-9657` publishes an open-rail terminal pair only after checking **both typed vertices exist and differ**. Checked A4 factory `src/geometry/SurfaceCellTracing.cpp:8295-8300` rejects every contact with equal endpoint IDs, before accepting a product. Thus every factory-admissible contact has distinct endpoint IDs `v0 != v1`.
3. A4 route producer `src/geometry/SurfaceCellTracing.cpp:19034-19045` defines `exact_corner(point,vertex)` with a unique selected face corner and exact **one-hot** barycentrics, no tolerance. It checks both `fromPoint` and `toPoint` at `:19047-19051`, and returns `ambiguous-terminal-contact` only when **two different** `contact.endpoints` pass those checks (`:19052`).
4. Fix either `fromPoint` or `toPoint`. For a one-hot barycentric point, at most one selected local source corner can satisfy `exact_corner`. With two distinct typed vertices, both cannot satisfy it simultaneously. This is true even for different source faces at the two trace points, because *each point individually* can match at most one distinct source vertex. The carrier-membership and other predicates can only narrow the candidate set.

**Deduction:** the `if (terminalVertex) return reject("ambiguous-terminal-contact")` branch is unreachable for a valid factory-admissible producer receipt. A malicious duplicate terminal pair is rejected **earlier** by the checked factory; a fabricated geometric approximation is rejected at `no-exact-terminal-corner` (or still cannot match two vertices) and cannot count as the required first-rejection witness. Thus retaining RA-46.5 literally creates an unsatisfiable acceptance obligation.

This is a **static feasibility proof**, not proof of successful runtime and not permission to remove a defensive guard. The claim requires only distinct typed contact endpoints and bit-exact one-hot source-corner confirmation. If either invariant is intentionally relaxed by a later independently reviewed design, re-open the obligation.

#### Requested independent Definition/Review disposition

1. Verify the proof directly against these exact producer, A4 factory, and endpoint-certificate sites. A refutation requires an exact admissible contact, two unequal typed terminal IDs, source face rows/barycentrics, and a trace-point pair for which **both** IDs satisfy `exact_corner`; an arbitrary non-source witness does not qualify.
2. If confirmed, retire **only** the impossible literal `ambiguous-terminal-contact` negative through a separately accepted normative RA-46.5 amendment. Keep the branch as fail-closed defensive code. Require a reachable factory-first duplicate-contact negative, plus source-valid `no-exact-terminal-corner` and the other achievable first-predicate negatives; preserve their distinct diagnostic semantics. Do not rewrite any frozen selector identity or turn a failed premise into an artificial PASS.
3. Independently examine the *other* RA-46.5 negatives for producer/factory-first-rejection feasibility before freezing new fixtures. In particular, the overfull-incidence condition already has the separate RA-48 conditional retirement; do not conflate it with the present ambiguity.
4. If the requirement remains literal, explicitly define a **new** admissible contact domain and have it independently reviewed first; do not weaken one-hot corner checks or the checked factory merely to construct a witness.
5. On a completed Review, resume the **same** `M6-CP3-CB1-ENTRY-R4` Code + Build turn, then separately address RA-43.2 source-owned side/attachment, RA-43.4 opt-out disposition, RA-47.12 execution liveness, and historical first-rejection/restoration gates. Do **not** start `M6-CP3-TB1-ENTRY-R4-EXEC` before the canonical R4 turn closes.

#### State

**REVIEW STOP — unresolved.** Classify current canonical turn `BLOCKED` (`REVIEW_BLOCKER`) until the normative feasibility decision. The last accepted runtime authority remains CP2 **491/491**; R3 **403/497** rejected (94 RED, 88 accepted CP2 losses), stable ledger **66/17/49**, debt **1**. No runtime evidence or regression accounting changes result from this request. No local work should be mistaken for compiled source.

#### Patch publication and immutable evidence (2026-10-12 20:50Z)

The four-file source/documentation-only review-stop patch was applied at commit `6344c07e75c3038880026c11deee3d3e9a2c5633` via durable dispatcher [run 38306575006](https://github.com/akashskypatel/Directional/actions/runs/38306575006), Drive apply job `115002068619`. Verified result artifact `11772133866` has provider ZIP SHA-256 `7849bdb4edc310519027856e763ebc7774f3e1ed583569e68e687850d5ddad94`; verified log artifact `11772068941` has ZIP SHA-256 `be61b4dc06e17f301ba71919b2d476a820478a69516af41dfd8ad9a981b9263b`. Exact base `69649fda99508310ce93a9e2920da28fa966c578`, patch SHA-256 `dc392702f1c115e3bb96e2e0003b2ae3b59620d84fde545e9e7eb84f7bdc7f5b`, diff-body SHA-256 `79b017ee7bf59c3943ae9b7b69ef764aa3d3f77e8b11448053feedd04f7b2e28`; `download_verify_exit=0`, `apply_push_exit=0`, `job_status=success`, `runtimeExecution=false`. Independent commit comparison found exactly four intended documentation paths, 51 inserted lines and no removals. The consumed Drive stage `1Glt6fihGoN_IkDlYvXLrYLCDqM6K41oI` was permanently owner-deleted after result verification; WIP patch backup is preserved in ChatGPT Library `/Directional/Evidence/` and as downloadable chat artifact. No compiled code, tests or benchmarks were run; R4 remains blocked on Review, with no accepted runtime credit.

## `Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_RA432_Oriented_Germ_Producer_Boundary_Review_Request_20261013.md`; moved verbatim.

### M6-CP3-CB1-ENTRY-R4 — RA-43.2 oriented terminal germ producer-boundary review request (2026-10-13 UTC)

**Disposition:** source-exact architectural REVIEW REQUEST, not a frozen design, implementation patch, runtime PASS or successor authorization. The canonical R4 Code + Build turn cannot establish an independently source-owned *oriented front-filled-side* attachment from the producer fields inspected here. Do not invent that missing association from trace geometry or an A4-created certificate.

#### Immutable source evidence

- Repository `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`; source snapshot `d02b5d6d6422e8ccb5fd932f65ac19b14808f573`, workflow `38330910540`, artifact `11782477329`, ZIP SHA-256 `5657137534fa509487d5034638d65222215af4cb13ebb8c0f71f66d660bd4e26`, embedded source tar SHA-256 `0db23d6be8e46388dc581fa8e3ba59ecaa9123f31130525f1d3ab4cbc6f38dd5`; **5541/5541** source paths verified. Source inspection only; no Directional binaries/builds/tests/benchmarks run.
- `src/pipeline/RemeshPipeline.cpp::build_authoritative_surface_cell_rails` publishes ordered `sourceVertices`, verified typed interval `sourceEdges`, and `SurfaceCellRailSample` geometry. `append_edge_interval` takes the **first available** `AdaptiveFeatureEdge::incidentFaces` row for a sample, not an oriented terminal-side owner. `hard_rail_source_provenance_from_rails` (approximately 9626-9664) publishes only `{component, {firstVertex,lastVertex}}` for an open HardRail. Its input arguments are only rails and vertex extent; neither source-face winding nor a front-filled-side association is available to it.
- `include/directional/geometry/SurfaceCellTracing.h::FieldAlignedMandatoryEdge` owns typed rail/source edge, component and a vector of source topology regions, **not a left/right face or front-filled-side germ**. `canonical_field_aligned_candidate` verifies each `sourceEdges[i]` against the source-vertex interval, but does not publish an oriented terminal face/side occurrence.
- A4 `build_surface_cell_network::endpoint_certificate` (`src/geometry/SurfaceCellTracing.cpp`, approximately 19015-19177) derives its two `firstAttachment/secondAttachment` keys from `fromPoint.face/toPoint.face`. `exact_corner` confirms a producer-owned terminal *vertex*, but not independently sourced oriented side incidence. `SurfacePhaseFrontProduct::make` checks certificate attachments against the **same** front trace-face rows. This does not create independent side authority. The earlier `Architecture_M6_CP3_R4_RA432_Terminal_Attachment_Source_Audit_20261012.md` reached the same origin gap; this record pins the remaining producer-facing design decision and falsifiers rather than claiming it solved it.

#### Candidate independent producer data and unresolved seam

From a directed ordered source rail edge `u -> v`, the source mesh's triangle winding can independently classify the two carrier-incident source faces: one contains oriented edge `(u,v)` in its cyclic triangle order, the other `(v,u)`. A future **source-authored** immutable receipt could bind `(HardRailId, terminal SourceVertexId, outward directed terminal SourceEdgeTopologyKey, ordered pair of SourceFaceTopologyKey side germs, source component)`. It must fail closed on missing/duplicate/ambiguous side incidence, inconsistent component or atlas binding, reversed orientation not paired with reversed side order, and face keys not incident to the actual source carrier. The outward direction at the last rail endpoint reverses the rail-chain direction. This is a design **candidate only**; triangle winding cannot by itself attest which A4 `filledCell/filledSide` is bound to which producer-side germ.

**Independent design question:** identify an upstream typed front-side/endpoint occurrence producer that can authenticate `(rail, terminal, source interval, oriented source-face germ, filled-side owner)` before A4 reads `SurfaceTracePoint.face`. If none exists, specify the minimal new producer output and a checked factory input whose authority derives from source topology and the actual tracing event, not from a replay of A4's candidate faces/sector paths. Source-field A3 forward/reverse transport remains separately checked; no default, nullable A3 escape, inferred gauge, source-foreign row, geometric epsilon, or arbitrary rail sample face may become a side credential. Preserve RA-49.5 validate-after-use architectural repair as a separately deferred Definition issue, not a disguised R4 change.

#### Required discriminating implementation/test design before release

1. **Producer positive:** a real traced 3×3 rectangular hard rail with two attached front sides yields a unique pair of independently authenticated source face side germs; include both rail directions and a case where the trace attachment face differs from the carrier-incident face because of a nonhard A2b path. Verify the published winding-based carrier-side reference matches source-face topology, and prove filled-side incidence from an independent upstream event.
2. **Independent negatives:** swap left/right source face keys without reversing the directed rail; substitute another source-valid but foreign face; use a different rail's terminal edge; erase one oriented side; duplicate or ambiguously assign a side; reverse only one of rail direction / oriented pair; corrupt A3 reciprocal transport. Each must fail at the first actual source-authority rejecting predicate, not merely at a later generic factory error.
3. **Preservation:** keep consumer `exact_corner` as bit-exact geometry confirmation, the RA-46 source-star zero-path and two-sector disjointness guards, typed contact vertices, A3/chi/phi and carrier-square orientation, all original tests/497 frozen identities and mandatory GMP/GMPXX compile. Do not treat the already compiled-only regressions as executed.
4. **Decision gate:** independent source-domain Review must accept the exact producer-to-A4 ownership chain and source-negative falsifiers before a broad new oriented-side schema can be represented as completed RA-43.2. If none is authenticatable, classify the dependency as `REVIEW_BLOCKER`; do not fabricate a passing route or silently consume trace-face rows as authority.

#### Separate RA-46.5 finding (avoid redundant work)

`tests/SurfaceCellTransitionQuotientTests.cpp` around 9040-9071 already has a **checked-factory** `MissingTerminalA3Path` source-backed negative: it takes a real nonhard step from a produced contact path, inserts that exact spoke into the source hard-feature barriers, and checks the factory's typed `MissingTerminalA3Path` detail. It is **not** the earlier A4 `endpoint_certificate` consumer's required first rejecting predicate `missing-terminal-A3-path`; those stages remain distinct. `overlapping-terminal-sectors` and `missing-or-nonreciprocal-terminal-A3` feasibility remain unadjudicated per frozen RA-49.7. The factory test must not be double-counted as consumer first-rejection coverage.

The R4 turn remains unfinished: 39 endpoint / 34 Phase10 / 7 DCEL / 88 CP2-loss / 6 CP3 positive gates and true odd-tau multi-carrier witness are unverified. Historical CP2 491/491 accepted; R3 403/497 rejected, 94 RED / 88 CP2 losses; stable ledger 66/17/49 and debt 1 unchanged. No TB497 or successor permitted.

## `Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_RA465_Terminal_A3_First_Rejection_Review_Stop_20261013.md`; moved verbatim.

### R4-TA3-01 — RA-46.5 terminal-A3 first-rejection feasibility: independent Review requested

**Canonical turn:** `M6-CP3-CB1-ENTRY-R4` (still not complete). **Disposition:** REVIEW STOP for the *unadjudicated* `missing-or-nonreciprocal-terminal-A3` witness, not a normative retirement. No implementation, selector, runtime result, or new successor is authorized by this record.

**Immutable inspection basis:** `agent/surface_cell_quad/p5-recover-bridge-healing` source snapshot `0240d0f00d6e4f8f9ebaab7684e4c7c7859be21e`, workflow `38406898773`, artifact `11818323616`, ZIP SHA-256 `990aba5721c543081c4e02a578f61965ca479702016630cee140e49aabd16831`, source.tar.gz SHA-256 `7c0028fc81e8b1005e4faa1f8b39ac911452f5b0d7f217954c73a35e37433111`, all **5688/5688** file checksums verified; no compiled binary was executed. This is a static, conditional reachability analysis only.

#### Exact source chain

1. **Producer constructs reciprocal transitions for all source interior edges.** `FieldTransportAtlas::make` (`src/authority/FieldTransportAtlas.cpp:1893-2064`) loops over `TriMesh::EV/EF`, requires a matching cross-field transition for every two-face source edge (`:2016-2030`), rejects nonreciprocal face ownership, computes `forward` and `reverse=forward.inverse()` (`:2033-2037`), and unconditionally appends `FieldTransportTransitionValue` (`:2039-2042`) **before** categorizing the edge as `HardFeature`, `NonTraversable`, or traversable. Hence omitting a *nonhard* A3 record is not an output of the normal accepted producer.
2. **Accessor reads the same immutable record in both directions.** `directed_transition_value` (`:910-922`) returns `value.forward` or `value.reverse` according to the requested face pair, and `FieldTransportAtlas::transition_value` (`:3080-3087`) looks up the canonical source edge. Reciprocal transport is constructed, not independently supplied in two mutable maps.
3. **Consumer is source-bound before terminal certification.** `build_surface_cell_network` (`src/geometry/SurfaceCellTracing.cpp:18759-18783`) rejects a supplied A3 atlas that does not `matches_source_faces` prior to building the front. The terminal endpoint loop (`:19083-19112`) enumerates nonhard two-face spokes from `edge_faces(faces)` and `sourceEdgeFaceCounts`, then checks `forward`, `reverse` and inverse relation at `:19099-19105`; this is where RA-46.5 requires the *first* `missing-or-nonreciprocal-terminal-A3` rejection.
4. **Source edge-table injection is separately guarded.** RA-48.3 hardens `TriMesh::set_mesh` to reconstruct/check its DCEL and validate supplied `EV/FE/EF` rather than allowing a forged edge table to pass as the same source. RA-49.7 (`Architecture_M6_Frozen_Definitions.md:157-163`) explicitly left both this obligation and `overlapping-terminal-sectors` **unadjudicated**. RA-46.5 still lists the negative; compile evidence does not discharge it.

**Provisional inference:** For a valid source-built A1 atlas on the same checked source triangles, a missing or nonreciprocal terminal-spoke transition cannot be made the first rejecting A4 predicate by mutating only an otherwise admissible producer input: missing cross-field input fails A1 construction, wrong face ownership fails A1, and the normal A1 transition accessor supplies inverse pairs. A foreign or forged source table is not a valid substitute. This is *not* a proof over every accepted external A4 caller; that potential counterexample class is the first independent review task. Do not claim universal unreachability yet.

#### Required independent decision

- **Review A:** enumerate all public A4 ingress variants and determine whether a source-valid atlas built for a distinct source may pass `matches_source_faces` while lacking a terminal-spoke value. Produce an exact caller and first-failure trace if one exists; differentiate nontraversable A3 adjacency from a missing transition *value*.
- **Review B:** if reachable, specify the one minimal source-valid pre-A4 mutation, expected first predicate and test location, without changing the frozen 497 selector. If impossible under all admitted callers, decide whether to retire only this fixture obligation (retaining its fail-closed guard) or replace it with a reachable first-rejection case. The Code + Build agent must not amend RA-46.5 on its own.
- **Review C:** independently assess `overlapping-terminal-sectors` (also left open by RA-49.7), rather than silently grouping it with this case. Preserve RA-49's already adjudicated contact, zero-path and nonmanifold results, and RA-50's discharge of RA-43.2.

**Stop boundary:** do not add an impossible fixture, relax exact source/atlas guards, fabricate a transition map, edit frozen definitions, run TB497, or initiate a successor. Historic CP2 491/491 accepted and R3 403/497 rejected (94 RED, 88 former accepted RED); no new runtime credit. R4 remains pending independent normative review of this first-rejection obligation.

## `Architecture_M6_CP3_R4_SID02_Produced_Cell_Reachability_Probe_20261014.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_SID02_Produced_Cell_Reachability_Probe_20261014.md`; moved verbatim.

### M6-CP3-CB1-R4-SID02-PROBE — source-only equal-opposite-corner reachability

Authority: RA-52.5 / `R4-SID-02` in `Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`. Exact source snapshot `43e8a503baa1896fd133eecda5ce6a323b9229ed`; Actions run `38625280153`, artifact `11923063390`, outer SHA-256 `99a9b858868faea05480bc42d9c6e7bbc0019c8069bc4a025edc6f8559b68291`; source archive SHA-256 `aea5c4590518cbc62e0dc3153374da3aa67bfa967cb50a4bf9786f2cc85e6622`; **5596/5596 hashes verified**. Inspection only: no build, executable, test, benchmark, or source code mutation.

#### Answer and disposition

**The precise configuration `corners[0] == corners[2] && corners[1] == corners[3]` cannot be emitted by the currently implemented A4 source producers as an accepted `SurfacePhaseFrontCell`, when equality denotes the same geometric corner/point.** Retire **that exact** `R4-SID-02` proposed A5-locus repair as producer-unreachable; retain existing fail-closed validators. Do **not** add an A5 guard, a new receipt/producer/namespace, or runtime/acceptance credit in this turn.

#### Complete producer census and proof

1. `src/geometry/SurfaceCellTracing.cpp:12772` produces the uniform planar cells (`:12918-12965`). Every candidate goes through `orient_and_validate_phase_front_cell` (`:12627-12682`, call `:12957`). That function checks **all six** distinct corner-position pairs and rejects a separation no greater than `max(1e-12, 1e-9 * target)` before orientation validation. Thus identical opposite corners fail with `InvalidCellOrientation` before the cell is appended at `:13036`.
2. Periodic-annulus producer (`:13545`, cell at `:14629`) requires a finite, nonzero `phase_front_loop_normal` and positive orientation (`:14682-14709`) before appending at `:14761`. For a physical alternating two-point cycle A,B,A,B, the four directed cross-products are A×B + B×A + A×B + B×A = 0, so it cannot pass. Reversal at `:12364-12374` cannot change this.
3. Curved bounded-disk producer (`:14832`, cell at `:17188`) imposes the same nonzero, positively aligned loop-normal requirements (`:17230-17262`) before appending at `:17344`. The same cancellation holds.
4. These three variants are the complete dispatched region-build cases at `:17819-17832`; final aggregation at `:17950-18010` renumbers cells but does not alter corners. `publish_phase_front_result` (`:12721-12761`) is the only producer publication path, delegating to the checked `SurfacePhaseFrontProduct::make`. The legacy proposal tracer is not a produced phase-front cell (`:19543-19570`).

**Independent A5 discriminator:** Each producer assigns a quad's corner lattice coordinates `(u,v), (u+1,v), (u+1,v+1), (u,v+1)` (`:12935-12938`, `:14629-14644`, `:17188-17212`). Reversing orientation only permutes them. Front edges copy the corresponding per-corner lattice states and `filledSide` (`:12965-12994`, `:14711-14734`, `:17264-17290`). At A5, `lattice_equal` compares exact `latticeCoordinate` values as well as phase, chart, branch, scale (`src/pipeline/RemeshPipeline.cpp:3311-3321`, applied at `:3583-3588`). Sides 0 and 2 therefore **cannot** both authenticate one unchanged front-edge lattice-state pair even if their trace positions were identical. The proposed ambiguity is not established by coincident trace points alone.

#### Scope caveat: tolerance is not point identity

A5 `trace_equal` (`src/pipeline/RemeshPipeline.cpp:3307-3310`) accepts same-face barycentric differences of norm ≤ `1e-10`; this is **not** `operator==` and does not imply identical world-space positions on arbitrary-scale triangles. The strict equal-point result above should **not** be expanded into a universal proof that *near-equal under this tolerance* is impossible on all input scales. That broader numerical scenario is not the precise equal-corner configuration specified by RA-52.5, and A5's independent lattice discriminator remains in effect. No near-equality witness was constructed or executed.

#### Downstream guard and acceptance boundary

If quotient equivalence later merges corners, `SurfaceQuotientProducer::publish_records_for_validation` rejects a classed cell with fewer than four distinct corner classes as `DegenerateClassedQuad` (`src/pipeline/RemeshPipeline.cpp:6340-6351`); A6's adjacent-only check (`:8446-8449`) and A7's `quad-degenerate` check (`:7482-7486`) remain fail-closed. Those later checks are distinct from proving an A4-produced raw cell with equal opposite corners. RA-52 is preserved as historical review authority; this source-only probe refines its conditional reachability conclusion without changing frozen definitions.

**Next independent work:** the authorized single comment correction at `src/geometry/SurfaceCellTracing.cpp:1457-1459`; do not touch `:1460-1467`. Other RA-52 obligations remain as listed in the current handoff. There is no authorized canonical successor turn ID in this source-only probe; the turn beacon may use `Successor: UNKNOWN`.

## `Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`

> Former standalone record `.agents/Directional/Architecture_M6_CP3_R4_Source_Current_Review_Gate_20261014.md`; moved verbatim.

### R4 Code + Build source-current review gate (2026-10-14 18:30 UTC)

**Canonical turn:** `M6-CP3-CB1-ENTRY-R4`; no successor, frozen selector497 mutation, PR metadata edit, generated binary execution, test execution, or benchmark. This is a **source-only architectural review handoff**, not independent Review approval.

#### Verified source and compilation authority

- Dedicated orphan-branch mailbox `ref=workflow-mailbox`: pinned GMP compile [run 38613136344](https://github.com/akashskypatel/Directional/actions/runs/38613136344), job `116021476447`, semantic source `5ecaa2acbec9a03622e14e6afac4dfc71763778f`, immutable package `11919172109` SHA256 `3158307c79c5c6ea1fd1b553bcf2b8209e5811cbac7966d89d131634776ddab5`. Independently re-verified 28/28 package hash entries, 8/8 required targets, `GMP=ON` and actual GMPXX/GMP linker command, preflight/build exit 0/0, five clean source-status files and `runtimeExecution=false`. This is **compile success only**.
- Current exact source snapshot [run 38615232734](https://github.com/akashskypatel/Directional/actions/runs/38615232734), event/source `8f490bd7fb196bfb2a9d8b83cf9c65c5d6c001d0`, artifact `11919555806`, outer SHA256 `175bdfde0700ccfcf538b126afbf10515039921c1fcc5f5bbfe502fb29458b9f`, source TAR SHA256 `2645c4567f1a856873cea349106534253090e407dab81e0836396c3b62462140`, **5594/5594** source hashes passed, no runtime. Compare `5ecaa2ac..8f490bd` changes only handoff/report/request/STATUS and snapshot marker, **no further semantic source/test edits**.

#### Independent design decision still required

`include/directional/geometry/SurfaceCellTracing.h:402-423` stores typed A2a `FieldAlignedCandidateTraceSegment::branch` and source face. **Different producer namespace:** A4 `SurfaceTraceSegment` (`:1211-1234`) publishes `family/sign`, sourceChart, route, rail and interval but no checked A2a segment/branch join. A4 `SurfaceHardRailRouteJunctionCertificate` (`:1513-1523`) has the junction and two sector paths; enclosing route cert (`:1519-1526`) has paired front indices, rail, route, endpoints and junctions; producer in `src/geometry/SurfaceCellTracing.cpp:19538-19540` writes those fields, not selected `FieldBranch`, directed arrival mode, or independently authenticated filled-side association. `SurfaceFrontEdge` (`SurfaceCellTracing.h:1545-1580`) has filledCell/filledSide and lattice fields, but their mere coincidence with a junction sector is not the missing join.

Existing `tests/SurfaceCellREPackageTests.cpp:740-760` enumerates A1 face-frame branch pairings to find an admitted germ on a genuine A4-produced junction; that is *existence*, not proof that A4 selected that branch. The nonconstant odd-τ test (`:949+`) is an authored compile-only oracle; no runtime credit. **Independent RA-43.1 / RA-43.2 Review must decide** either (A) a source-checked existing join from one exact A4 directed occurrence and front-side to the uniquely selected A1 `FieldBranch`/arrival mode and source chart, or (B) authorize a minimal typed upstream producer receipt `(HardRailId, directed occurrence, junction SourceVertexId, source face/chart, FieldBranch, arrival mode, filled cell/side)` with first-consumer checks. Demand correct-face/wrong-branch, foreign-chart, rail-only reversal and swapped-filled-side first-identity negative oracles and one genuinely produced nonvacuous positive. Do not equate `LocalLatticeState.branchRotation` with the selected source branch or A2a and A4 trace identities.

#### RA-43.4 opt-out review boundary (no new source defect established)

In `src/geometry/SurfaceCellTracing.cpp:5941-5986` `rail_interval_refs` defaults to `RequireTypedSource`. Even when `LegacyStandaloneDiagnostic` is explicitly selected, the presence of `fieldAlignedNetwork` forces typed source vertices and keys, and `:6127-6150` independently checks mandatory edge/rail/kind/component. Production entry points explicitly request typed (`:10502`, `:12428`, `src/pipeline/RemeshPipeline.cpp:9634`); current `tests/SurfaceCellsPhase10Tests.cpp:6506-6595` covers stand-alone diagnostic vs network-forbidden opt-out and mismatched typed keys/component. **No unchecked production diagnostic bypass was proved in this snapshot.** Independent Review must decide whether to preserve the historical opt-out or remove/limit it without silently changing API/frozen tests. Do not implement broad changes from a speculative weakness.

#### Disposition and next permissible action

This source review found no additional well-attested, unimplemented Code+Build edit beyond already compile-green patches. Independent architectural Review for the selected source branch/filled-side is a **review prerequisite** to completing R4, and RA-43.4 diagnostic policy likewise needs explicit disposition. Stop on that scoped review gate rather than fabricating a receipt or reworking already repaired seven DCEL fixture sources. No TB497, no runtime acceptance and no automatic successor. RA-47.12 uninjected liveness; original 39 endpoint, 34 Phase10, 7 DCEL, 88 CP2 and six CP3 identities; organic D1/D2/D3/D5/A6/A7/odd-τ require a separately authorized immutable-artifact Test+Benchmark and independent acceptance Review after the design decision.

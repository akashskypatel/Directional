# RA-248: face-interior contact node definition (2026-11-17 UTC)

Canonical turn `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` (Review only), scoped by RA-247 §3.
- It defines how A2a′ handles a contact node strictly inside a source face (C5).
- It audits every consumer, finds a second stale contract downstream, and freezes CB147.
- No Directional binary was built or run. Source checks were `-fsyntax-only`, and the test logic was checked with an exact Python model.

## 1. Inputs taken as established (RA-247 G1–G5)

- **C5's event.** It is a trace–trace contact inside face `(5,104,359)`, involving trace 0, and its two segments share no carrier edge. A2a′ rejects it at `trace_event_position` (`EmbeddedGraphTopology.cpp:154–172`).
- **What A2a′ assumes.** Position, `NodeLocus`, rotation and the ten arc-range readers all assume a node lies on a vertex or an edge.
- **No user decision is needed.**
  - DESIGN §7.2 step 5 has traces terminate "on first contact with an existing trace".
  - Step 6 and invariant 4 say "trace intersections create explicit graph nodes".
  - Amendment 13 requires the actual embedded graph, and Amendment 14 lets A2a′ subdivide a trace in the derived arrangement only.

## 2. New finding: a second stale contract, downstream

I checked both of A2a′'s downstream consumers of trace segments.

**A2b `build_fragment_corner_incidence`** (`GlobalTopologyPlan.cpp:458–640`) implements the frozen M3 Amendment 7 taxonomy (`M3_Closure_Record.md:3606–3625`):
- a source face carries at most one full chord;
- rays are allowed only from a shared origin;
- terminal segments are slits that "never" separate.

That taxonomy is premised on the legacy face-level contact rule, where a later trace stops on entering an occupied face. The canonical tracer stops at the exact crossing point instead (`field_aligned_publish_contact`, `SurfaceCellTracing.cpp:4062–4210`). So a contact face holds two trace segments that meet inside it.

For C5's configuration this means:
- A2b rejects the face with `SourceFaceCarriesTraceChordAndRays` (one segment starts at a vertex: a ray) or `SourceFaceCarriesMultipleTraceCuts`. That holds whatever A2a′ does.
- Splitting the struck segment into two arcs would also visit segment k twice.

**SurfaceCutGraph `build_source_face_ownership`** (`SurfaceCutGraph.cpp:408–640`):
- It is an owner multimap, so it tolerates several segments in one face.
- But it treats a separating terminal slit as a full chord whose exit is the hypothetical `outgoingCarrier`. The frozen taxonomy itself forbids that ("its `outgoingCarrier` must never be treated as a chord exit").

**Consequence.** Fixing A2a′ is necessary but not enough for BunnyRandom to produce output. The next terminal will very likely sit at one of these two ownership stages.
- This is a Review-owned frozen definition (M3 Amendment 7), not a DESIGN contract, so the stop rule does not fire.
- The replacement rule is defined below as FC-6. It is implemented only after a measuring turn, because both stages run on every gate fixture.

## 3. Normative contract (FC-1 – FC-7)

**FC-1. Face-contact node.**
- **Which events qualify.** A FirstContact, TraceIntersection or TraceSelfClosure event that has no `sourceEdge` and whose node is not a singularity-port node is a face-contact node.
- **Its locus.** Face = `event.sourceFace`. Point P = the terminating trace's `terminalContact.barycentric`, mapped into the face's oriented corner order (the existing mapping is at `:1185–1205`).
  - A terminating trace is one with a Terminal incidence at that node, whose `terminalContact.sourceFace` equals the event's face.
- **Fail closed** when:
  - there is no terminating trace;
  - two terminating traces give different points (two traces that both terminate at the same point are allowed);
  - P is not strictly inside the face.

**FC-2. Positions on each trace, taken from the contact record, not from incidence roles.**
- **Terminating trace:** its end, `segments.size()`.
- **Struck trace** (`terminalContact.struckTrace`): an interior cut (k, t).
  - k = `struckSegmentIndex`.
  - Segment k must lie in the event's face and have no `edgeTransitExit`.
  - t = `face_chart_segment_parameter(entry_k, exit_k, P)` and must exist, so 0 < t < 1.
- **Self-closure:** the same trace takes both positions.
- **Fail closed** if any incidence names a trace that is neither terminating nor struck, or if a Terminal role falls on a struck-only trace.

**FC-3. Arcs.**
- A trace cut is either a segment boundary b or an interior cut (k, t). Interior cuts sort after boundary k and before k + 1, and among themselves by exact t.
- **Fail closed** when equal (k, t) appear with different nodes.
- An arc that starts or ends at an interior cut keeps segment k in its range: [i, k + 1) or [k, j).
  - Its exact `sourcePath` piece for k starts or ends at P.
  - Two contacts in the same segment give the one-piece arc [k, k + 1) from P₁ to P₂.
- This is sound for every A2a′ ray helper (`trace_ray_face`, `vertex_trace_ray_second_point`, `edge_locus_secondary_rank`): a segment is straight inside its face, so a ray from P along k has the direction of k.

**FC-4. Locus.** `NodeLocus` gains a face-contact alternative (face + oriented point). A node never carries both a face locus and a vertex or edge locus.

**FC-5. Rotation at a face-contact node.**
- Every ray must be a Trace ray. A Mandatory or Cut ray at such a node fails closed.
- Each ray's second point is the boundary point of its segment in that face: a Forward incidence uses segment k's exit, a Reverse incidence uses segment k's entry, and the terminating trace's ray uses its last segment's entry.
- The rotation is `face_chart_counter_clockwise_ray_order(P, secondPoints)`, which matches Amendment 26 (counter-clockwise in the source orientation; the face is the source entity). It is rotated so that the smallest (arc, orientation) comes first, for determinism.
- Two rays leaving in the same direction fail closed with a new typed reason.

**FC-6. Fragment and ownership rule for faces that contain a face-contact node.** This replaces M3 Amendment 7 there. Defined now, implemented later.
- Walk the face boundary counter-clockwise and order every trace boundary crossing by exact edge parameter.
- Each corner that is not a node is owned by the orbit on the counter-clockwise side of the last crossing before it.
- A stub that ends at a face-contact node has a single boundary crossing. It separates through its exact endpoint and never through its hypothetical `outgoingCarrier`.
- For a face with one chord or with rays from one corner origin, this rule gives exactly what the existing branches give. That is the equal-product obligation for the CB that implements it.

**FC-7. Contacts with a common carrier are unchanged.** They keep the proxy path (O45, deferred).

**Fixture limit (reported, not hidden).**
- `FieldAlignedCurveNetwork::make_from_candidate` rejects any candidate that differs from canonical tracing (`SurfaceCellTracing.cpp:5723–5743`), so no test can hand-build a contact network.
- So the wired paths (FC-1–FC-5) have only one runtime witness, the BunnyRandom census.
- Unit tests can reach only pure functions of exact inputs. CB147 provides these, and the CB that freezes FC-1–FC-5 must factor its arithmetic into pure functions too. A hand-built `FieldAlignedCandidateTrace` struct can be used for the path pieces.
- **Middle-piece direction witness (RA-244 gap).** For the same reason it cannot be a unit test. Its witness is BunnyRandom reaching rotation at nodes 149/178/184/162 without `RotationEdge*` failures, plus a successful face walk. That gap stays open until then.

## 4. CB147 frozen: pure exact face-chart helpers, not wired in

**Patch:** `Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff`.
- SHA-256 `5c3def45e8bdd713ca321b7cfca0f9f3a5935bdf54900afd5548efc55e5df7d1`.
- 257 lines.
- Numstat: `92 0` `src/geometry/EmbeddedGraphTopology.cpp`; `35 0` `src/geometry/EmbeddedGraphTopology.h`; `100 0` `tests/FieldAlignedCurveNetworkTests.cpp`.

**Header:**
- `FaceChartPoint`.
- `face_chart_orientation`: the exact sign of the 3×3 barycentric determinant.
- `face_chart_segment_parameter`: exact t strictly inside a straight segment, with an exact check that the point lies on the line.
- `face_chart_counter_clockwise_ray_order`: the reference ray, then the open counter-clockwise half, the opposite ray, and the open clockwise half, compared within each class by exact orientation. Same direction or origin coincidence returns empty.

Nothing calls these yet, so product behaviour is unchanged.

**Test `FaceChartExactGeometry.OrdersRaysAndContactsExactlyAroundAFaceInteriorPoint`** (future gate row 952, `directional_surface_cell_producer_tests`) covers:
- orientation signs, including a triple whose double coordinates equal those of a collinear triple but whose exact sign is −1;
- the segment parameter at 1/3 and 1/3 + 2⁻⁶⁰, which have the same doubles but strict exact order, plus rejection at the entry, the exit, beyond the segment, 2⁻⁶⁰ off the line, and for a degenerate segment;
- T-shaped and four-ray orders, the same cycle read from another start, and a near-coincident ray (same doubles) ordered exactly;
- rejection of same-direction rays and of a target equal to the origin, plus the empty and single-ray cases.

**Verification:**
- `git apply --check` passes at HEAD `276eba262`.
- Precheck `git diff --quiet 48e6f97d278b2226036f658ce9060a38b8a374b5 HEAD -- src include tests` passes; that is CB146, the last commit to touch those paths.
- `-fsyntax-only -Wall -Wextra -DUSE_GMP_ENABLED` returns 0, with warnings identical to HEAD (22 for the source, 42 for the test). `GlobalTopologyPlan.cpp` and `SurfaceCutGraph.cpp` have 0 errors.
- A faithful Python port of the three functions passes all 24 test assertions.
- Converting the perturbed coordinates to doubles gives the unperturbed values; this is the same pattern as row 951's double-equality assertion, which passed on CI.
- **The test has not been run.**

**Routes:**
- Mismatch → `M6-CP3-PLAN-P13-FACE-CONTACT-EXACT-HELPERS-STOP`.
- Infrastructure failure → `M6-CP3-CB147A-P13-FACE-CONTACT-EXACT-HELPERS-ORCH`.
- Package: the eight RA-245 GMP targets. Compile only.

## 5. Turn sequence

| # | Turn | Owner | Content |
|---|---|---|---|
| 1 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` (RA-248) | Review | COMPLETE |
| 2 | `M6-CP3-CB147-P13-FACE-CONTACT-EXACT-HELPERS` | Code + Build (compile only, exact diff) | NEXT |
| 3 | `M6-CP3-DEFN-P13-FACE-CONTACT-NODE-FREEZE` | Review (may run alongside 2) | Freezes CB148 exactly per FC-1–FC-5, with its arithmetic as pure unit-tested functions. Also freezes the TB128 gate manifest: the TB127 manifest plus rows 952 and 953. |
| 4 | `M6-CP3-CB148-P13-FACE-CONTACT-NODE-SWITCH` | Code + Build | FC-1–FC-5, only for contacts that have no shared carrier edge. |
| 5 | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | Test + Benchmark | Gate (rows 1–951 unchanged; 952 and 953 PASS) plus census. Predicted: BunnyRandom leaves `TraceEventPositionInvalid`, and its next terminal is an FC-6 ownership stage or a rotation or face-walk failure. |
| 6 | `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` | Review | Classifies TB128 and freezes CB149 (FC-6, not yet wired, with an equal-product test on the existing chord and ray shapes and a receipt counting faces that contain a face-contact node). |
| 7+ | CB149 → TB129 → CB150 (FC-6 switch) → TB130 | — | Each staged per RA-230. |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45 | — | — |

**Why this ordering:**
- **CB148 changes only networks that fail today, so the gate cannot change.** Its path applies only to no-edge contact events. Today every such network already fails at `build_arcs`, because their FirstContact incidences are Interior. Haiku's census found that no test names these failure reasons.
- **FC-6 must be measured before it is switched on.** It touches A2b and SurfaceCutGraph on every fixture.

## 6. Carried

- **Open:**
  - C5 (owner A2a′; definition complete, implementation from CB147);
  - O42, O43;
  - O45 (deferred);
  - O46 (new): the M3 Amendment 7 fragment taxonomy is stale for the canonical tracer; FC-6 replaces it in contact faces.
- **Still to do:** the middle-piece direction witness.
- **Closed:** narrow C3, O44, C1.
- **Decisions:** D11 = A, D12 = A, D10 deferred, D6 pending.
- **Counts:** stable 66/17/49, debt 1, deferred 81; CP2 491/491.
- **Unchanged:** CP3/selector497 unpromoted; `chainRimSchedules=false`; DESIGN.md unchanged (FC-1–FC-7 realise §7.2 steps 5–6 and Amendments 13, 14 and 26).

# Independent technical review of the TB101C audit revision — 2026-11-11

## Situation

**Decision: the previous audit revision found genuine defects but its correction sequence remains technically unsafe.** Its node-level resolver cannot prove fan-specific chain behavior. Keep the prior 940/940 result in its tested scope. Do not promote CP3, the 497-selector, or the O36 production switch. This review corrects design authority and work order only.

## Background

Reviewed snapshot `42fc1143d0e0ed5892b971e149f64e64899842eb`, GitHub Actions run `43033555258`, artifact `13862031974`. The downloaded ZIP SHA-256 is `dbfff3c97ad4b79f8d144f816c71c399824c2712df6e192d84f39851b962f0b3`. The source archive hash and all 5,465 entries in `SHA256SUMS` passed. This is a read-only review. No Directional compiled program, test, or benchmark was run.

The reviewed record is [TB101C audit adversarial review](Architecture_M6_CP3_TB101C_Audit_Adversarial_Review_20261111.md). Earlier immutable evidence records 940/940 gate cases, 1,021 membership, one direct production PASS and two registered RED results. This review did not rerun that gate. CP2 remains the accepted 491/491 baseline; stable 66 events, 17 categories, 49 recurrences, debt 1, and 81 deferred are unchanged.

A **source fan** is one connected source-face set around a vertex within the admissible chart. An **arc incidence** is one oriented arc end at a network node. A **join pair** is a verified continuation from one arc incidence to one other incidence. A **branch certificate** records the decided field branch and its exact source and chart authority.

## Assessment

### Critical F1 — the network has one node per source vertex, not one per fan

`src/geometry/SurfaceCellTracing.cpp:4445-4516` collects source vertices into `std::set<SourceVertexId> nodeVertices` and builds `std::map<SourceVertexId, NetworkNodeId> nodeByVertex`. It emits exactly one `FieldAlignedCurveNetworkNode` for each vertex in that set. If such a shared-vertex case is admitted by the upstream source topology, those separate fans still have **one network node**. This Review has not proved that every synthetic two-fan fixture is admitted to the full production graph. `FieldAlignedCurveNetworkNode` holds only node ID and vertex (`include/directional/geometry/SurfaceCellTracing.h:352-361`).

The previous Review calls for one resolved fan for the whole network node. Its requirement that all incident arcs give one fan would reject a shared-vertex case if it is admitted, instead of keeping its separate occurrences. The promised two-fan test is not satisfied by a node-only map.

**Required correction:** make the first resolver return fan/sheet identity **per oriented arc endpoint**. A shared node may have several distinct resolved occurrences. Keep A2b node identity unchanged. Use `GlobalTopologyArc::sourcePath`, `GlobalTopologyArc::sourceFaces`, the exact endpoint and the bound `SourceChartTransitionGraph`; a source-edge support without an unambiguous source face does not prove one fan. Reject missing, wrong or conflicting support, never select a first face by row order.

### Critical F2 — the present chain representation cannot join two fans at one node

`src/geometry/GlobalConformityBaselineSupport.cpp:369-455` stores joins in `std::map<NetworkNodeId, std::array<NetworkArcId, 2>>`. At lines 408-410 it skips a node unless its full `rotation.counterClockwise` has **exactly two** incidences. If the upstream graph admits two fans sharing that node and each has two arcs, the node has four incidences and **neither fan joins**, regardless of whether one fan has a field corner. Also, the existing stop set is keyed by `NetworkNodeId` and stops the whole node (`:482-511`).

The prior Review asks a test to split the intended fan while the other stays joined. That outcome cannot follow from the current node-degree-two join and node-global stop representation. A typed corner key by itself does not change the partition structure.

**Required correction:** hold the node/graph as stable authority. First freeze a separate decision on whether two admissible **incidence pairs** can continue at one shared node. Require distinct pairs, same rail, same canonical fan/sheet, compatible region sides, and no cross-pair joins. An endpoint orientation is part of the key. If the canonical A2b embedding cannot certify those relations, stop and define a separate A2b fan-instance correction. Do not add speculative per-fan network nodes in this Review.

### High F3 — the test order can accept a false field turn

`src/geometry/SurfaceCellTracing.cpp:21582-21654` sets `turns = !branch.has_value()` and also sets a turn when branch transport is invalid. The previous plan schedules a derived-corner positive test **before** its exact-arithmetic definition and certified branch owner. Such a test could pass because the current helper treated an undecided branch as a corner, even though no certified field turn took place.

**Required correction:** define exact inputs, directed chart gauge, threshold policy and undecided semantics before testing a derived positive. Then create one shared branch certificate. The corner producer must use it, and only then may a new positive test claim a real field change. An undecided input must not count as a certified field corner. Retain the old tests as historical evidence. Do not weaken them.

### High F4 — source support is not automatically a fan witness

`include/directional/authority/ExactSourcePath.h:31-44` defines a support piece with a carrier and exact first/second points. A carrier may be a vertex or edge, neither of which alone identifies its owning face fan. `SourceChartTransitionGraph::resolve_entity` (`include/directional/geometry/SourceChartTransitions.h:348-388`) needs a source face/chart to resolve the fan. A new resolver must validate any supplied face against the carrier, endpoint, source topology, chart and sheet. A face-row index is not an identity.

**Required correction:** return distinct, typed unresolved reasons for absent face authority, conflicting faces, wrong chart/sheet, or an endpoint that does not match the vertex. The independent Test + Benchmark must contain meaningful negative cases for these reasons.

### High F5 — do not infer new production behavior from a gate count

The prior Review correctly retained 940/940 only as an immutable test result. It did not prove that a certified corner splits a previously joined chain. A two-fan test where both fans were already split at a four-incidence node is vacuous. The new independent witness must first prove both pairs would join without the corner. Only one pair may stop after the certified change; the other must remain joined. Removing the corner must change the outcome.

### Decision and limits

The existing `SourceVertexEntityIdentity` and `SourceChartTransitionGraph` are suitable **identity sources**. They are not a replacement for the network's join representation. Reuse existing source-support, A2b embedding and chart authority. Do not add a parallel topology registry. The field-corner producer and A4 must consume one certified branch decision. The exact binary64 value of `0.7` and rational `7/10` are different; the dedicated definition must choose one before implementation. No Code + Build runtime is authorized. No O36 wiring, no D6 promotion, and no change to accepted selectors is authorized.

## Recommendation — exact conditional work order

Only the first row is the next authorized implementation turn. Every following row requires successful independent evidence from the earlier row. Any RED or unresolved design proof stops the route for a new Review. A Code + Build turn can compile only. A Test + Benchmark turn must execute only the verified immutable compiled package.

| Order | Turn | Bounded obligation |
|---|---|---|
| 1 NEXT | `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` | Code + Build. Add an unwired exact arc-endpoint occurrence resolver. Key its output by node ID, arc ID, and endpoint orientation. Use an exact source face carrier and the bound source-chart graph to return a typed component, vertex fan, and sheet. A network node may have several distinct fan results. Reject missing or conflicting supports. Do not change A2b topology, chain partition, or corner producer. |
| 2 | `M6-CP3-TB102A-P13-A3-FAN-STOP-IDENTITY-EXEC` | Test + Benchmark. First establish that the source authority admits a relevant two-fan shared-node witness. If it does, prove separate per-incidence identities. Check one-fan positive, edge-only support with no owning face, conflicting faces, sheet mismatch, and face-row/winding permutations. The test must fail if the resolver merges fan results into one node identity. |
| 3 | `M6-CP3-DEFN-P13-A3-FAN-INCIDENCE-CHAIN-JOINS` | Review definition only. Decide whether a shared node can support independent admissible arc-pair continuations without changing the certified A2b embedding. Prove pair uniqueness, rail ownership, source component/fan/sheet match, region-side compatibility, and cycle handling. If the current rotation cannot support this, stop this route and define a separate A2b fan-instance correction before the next Code + Build. |
| 4 | `M6-CP3-CB121B-P13-A3-INCIDENCE-JOIN-PAIRS` | Code + Build. Implement only the new unwired per-incidence join-pair representation authorized by the definition. Retain the old node-degree-two partition as the production path. Reject incompatible or unpaired incidences and preserve hard-feature and port stops. |
| 5 | `M6-CP3-TB102B-P13-A3-INCIDENCE-JOIN-PAIRS-EXEC` | Test + Benchmark. One shared node with two disjoint admissible fan pairs forms two independent joins. A stopped pair splits without changing the other. Reject crossed pairing, different rails, wrong region sides, conflicting sheets, duplicate endpoints, and cycles that violate the frozen definition. Compare old behavior on single-fan controls. |
| 6 | `M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC` | Review definition only. Freeze stored-double source/field input identity, exact normal and projection construction, branch gauge transport, exact tie handling, and binary64 0.7 versus rational 7/10 threshold. Resolve undecided versus changed semantics before any positive derived-corner test. |
| 7 | `M6-CP3-CB122A-P13-A3-EXACT-RIM-BRANCH-OWNER` | Code + Build. Publish one unwired directed-edge branch certificate keyed by verified source fan/sheet, with a selected branch or a typed Undecided status and explicit invalid-source/transport reason. Do not change either consumer. |
| 8 | `M6-CP3-TB103A-P13-A3-EXACT-RIM-BRANCH-EXEC` | Test + Benchmark. Prove certified branch decisions at exact ties, both threshold sides, opposite orientations, degenerate normals, changed atlas gauge, two fans, and face-row permutations. Removing the exact decision must fail a decisive assertion. |
| 9 | `M6-CP3-CB122B-P13-A3-FAN-KEYED-CORNER-PRODUCER` | Code + Build. Publish an unwired corner record with a verified component/vertex/fan/sheet key and one branch certificate for each rim traversal. Compare certified incoming and outgoing branches to label Changed or Unchanged. An Undecided input is not a certified stop. Preserve the legacy vertex-list API as historical only. |
| 10 | `M6-CP3-TB103B-P13-A3-FAN-KEYED-CORNER-EXEC` | Test + Benchmark. One of two source fans has a certified field change and the other does not. Verify two separate producer records, directed-transport agreement, no false corner for undecided, and invariance to source-row and winding changes. |
| 11 | `M6-CP3-CB121C-P13-A3-FAN-SCOPED-STOP-FILTER` | Code + Build. Connect only the unwired new corner product and per-incidence pair join map. Stop exactly the certified matching pair. Do not broaden port, feature, or hard-edge stops. Do not activate the production switch. |
| 12 | `M6-CP3-TB102C-P13-A3-FAN-SCOPED-STOP-EXEC` | Test + Benchmark. A certified stop splits one admissible fan pair; the other remains joined at the same shared network node. If the source support is unresolved, the factory refuses the new path. Prove the test fails under vertex-only or node-global stops. |
| 13 | `M6-CP3-CB121D-P13-A3-DERIVED-CORNER-WITNESS` | Code + Build, test-source only. Build one straight, non-feature, degree-two rim with an exact certified branch change and a paired no-change field. Supply the real producer output to the unwired chain consumer. No manual stop IDs. |
| 14 | `M6-CP3-TB102D-P13-A3-DERIVED-CORNER-EXEC` | Test + Benchmark. Check exactly one intended chain split, one untouched other fan, one no-turn control, and a negative mutation that removes the derived corner. Do not treat an undecided branch or an already-unjoined node as a positive result. |
| 15 | `M6-CP3-CB122C-P13-A3-RIM-BRANCH-A4-CONSUMER` | Code + Build. Make only the unwired A4 bounded-disk side classifier read the same certified directed-edge branch decisions. Preserve previous production routing and source-cut ownership. |
| 16 | `M6-CP3-TB103C-P13-A3-RIM-BRANCH-A4-EXEC` | Test + Benchmark. Check all admitted rim sides against branch and corner certificates, opposite-region side compatibility, hard features, and the complete immutable gate. Any mismatch requires a separate Review. No CP3 or 497-selector promotion. |


O34, O35 and O37 remain separate requirements before O36. O38 stays unpromoted. O39 is covered only as a conditional exact arithmetic and branch-owner track. D6 still needs owner acceptance criteria. These obligations do not authorize a production switch.

## Review closeout

| Requirement | Verified disposition |
|---|---|
| Source identity and counts | New source snapshot exact SHA and 5,465 hashes verified. Prior 940/940 and 491/491 retained as **prior immutable evidence**, not re-executed. |
| Non-vacuity | Node-per-vertex construction and node-degree-two join guard independently traced. Existing two-fan split can be vacuous; exact positive prerequisite specified. |
| Review defects addressed | F1-F5 above. Prior producer fan and exactness findings retained. No new stable regression ID. |
| Prior obligations | O34/O35/O36/O37/O38/O39 and D6 carried with limits. Exact arithmetic and fan-incidence proofs have separate owners. |
| Stable accounting | CP2 491/491; stable 66/17/49; debt 1; deferred 81; no promotion. |
| Normative design | Add a correction to `DESIGN.md` for incidence-based identity and conditional chain-join authority. |
| Handoff / TODO | Replace the current first-turn scope and prepend the 16-row conditional order. Old plan marked superseded, not erased. |
| ORIENTATION / CHANGELOG / tracker | Current next and new unpromoted cause recorded. No checkpoint moved; ROADMAP and selector manifest do not change. |
| Review boundary | Documents only. No project binary, tests, fixtures, selectors, or product source modified. `review_check.py boundary` cannot establish Git ancestry in the snapshot; local path and patch checks are recorded instead. |
| Next authorized turn | `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` for **arc-incidence** resolution only. Do not start a successor within this Review. |

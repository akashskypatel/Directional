# TB101C technical and architectural review audit — 2026-11-11

## Situation

**Review decision: PARTIAL ACCEPTANCE ONLY.** The prior TB101C Review correctly accepts the immutable 940/940 test result as a test result. It correctly keeps CP3 unpromoted. It does **not** establish that a field-derived corner stops exactly one intrinsic rim fan. Production use is not accepted. This audit completes the previously deferred fan-identity and branch-owner design decisions. It authorizes only the small, unwired implementation sequence below.

## Background — independent code and evidence

The reviewed production/test source is `e1e5b17e94f189c88c74172e12dfd6ac93cc532b`. It is contained unchanged in verified source snapshot `ca1d913427a409e6ed2518361cecc26657573581` (artifact `13857660739`, source SHA-256 manifest passed). Immutable test artifacts are `13853426731` (940/940, 1,021 membership) and `13853038984` (Cylinder PASS; BunnyRandom and Vase RED). This audit rechecked their ZIP SHA-256 values `b94d9c201720490e8651655218ebb9ade7f71f62396e25b45d31eef99e7285ee` and `ce0a4d256449e5aea6108044ddfe90b31634eefe394031922bb98c6482d0f05e`. No new program binary was executed. The prior 938 inherited rows remain accepted only at their tested scope. CP2 stays 491/491. Stable accounting stays 66/17/49, debt 1, deferred 81.

### Finding A — stop selection loses intrinsic identity (HIGH)

`src/geometry/GlobalConformityBaselineSupport.cpp` in `derive_mandatory_chain_stop_nodes` builds a set of vertex numbers, then adds **every** network node with the same source vertex. `FieldAlignedCurveNetworkNode` in `include/directional/geometry/SurfaceCellTracing.h` holds only `id` and `sourceVertex`. A source vertex can support disconnected local fans or sheets. A stop in one fan must not stop the other. Existing `SourceChartTransitionGraph` already resolves a point to `SourceVertexEntityIdentity` = `(source component, vertex, fan)` and provides `isolation_sheet`. See `include/directional/geometry/SourceChartTransitions.h`. Reuse these typed identities. A raw vertex ID is insufficient for a fan-specific corner.

**Decision:** the authoritative corner-stop unit is a **source-vertex occurrence in one connected admissible chart fan and sheet**, not one vertex index. Resolve a node from its incident source-supported arc endpoints and their exact source faces. Each resolved incident endpoint must identify the same vertex fan, component and sheet. When incident data is absent, inconsistent or spans two fans, return a typed unresolved result. Do not stop all nodes with that source vertex. Do not infer a fan using Euclidean distance, a face-row number, an unverified chart or a made-up default. An existing feature/hard-rail stop must still stop under its own independent rule. An exact corner product may contain multiple distinct fan records for one source vertex.

### Finding B — corner writer duplicates an approximate A4 decision (HIGH)

`src/geometry/SurfaceCellTracing.cpp` declares a separate `boundary_edge_field_branch` near line 21541. The bounded-disk producer has its own branch-selection loop near line 16685. Both use floating-point normalized vectors, a 0.7 alignment threshold, and a 256-ULP ambiguity threshold. The helper then walks a fan and returns only `SourceVertexId`. A producer-only comparison with local branch integers is not a certificate that the product and A4 select one shared branch. The current tests compare side starts only for selected degree-two rim nodes. They do not cover all fans or all boundary runs.

**Decision (O39):** one owner must publish the branch of each directed rim edge, its typed face/fan/sheet authority, and an explicit undecided state. Both the corner product and bounded-disk producer must consume that same product. The source is the finite stored double data, interpreted exactly. Use existing `FieldExactRational` and certified field-transport topology where applicable. Compare signed branch alignment in a scale-free form: exact dot products and squared norms, with sign preserved before squared comparisons. Compare each normalized score, including the 7/10 threshold, without an epsilon or non-certified floating tie break. Exact ties and invalid transport are **undecided**, not a guessed branch. Do not change alignment policy silently. Exact score arithmetic alone does not certify a transport: validate face gauge and directed atlas transport separately. The A4 side-start walk may use the product but must not recalculate it.

### Finding C — two new green tests lack a derived positive witness (HIGH)

`GlobalConformityBaseline.StopNodesReadBoundaryFieldCorners` selects synthetic vertex IDs 5 and 6. `SurfaceCellAuthorityContractCutover.ChainedInputStopsAtBoundaryFieldCorners` passes vertex 3 manually to split a chain. With fixture-derived corners, its chain partition remains unchanged. All four `d4-corner` observations also report identical before/after chain counts (Plane 4/4, Seam 4/4, CloseSheets 8/8, Cylinder 2/2). Therefore the tests prove **manual stop forwarding**, not a real derived pass-through corner that changes chain membership. The prior Review noted the limit but treated the helper/factory as accepted without a minimum producer-to-consumer positive gate.

**Decision:** require one independently constructed straight-rim, non-feature, degree-two pass-through vertex where transported field branch changes. Require a real field-derived corner to split the intended chain. Require the paired field variant with no turn to leave it joined. Removing the derived stop must make the positive test fail. Check source-face row and winding permutations. Confirm the other sheet/fan remains joined. Both current synthetic tests remain useful regression tests but cannot discharge this gate.

### Finding D — comparison scope and production status (MEDIUM)

The raw `FIELD_CORNER_RECEIPT` lines prove only the selected two rectangular test paths. The missing historical `FIELD_CORNER_STOP_RECEIPT` was part of superseded one-shot authority, so its absence is not itself a failed current gate. Cylinder reports scheduled 81 A3 intervals with 0 covered. BunnyRandom and Vase remain RED. No final A3/A4 binding or representative production acceptance follows from these tests. Avoid re-running broad production gates until a narrow causal witness changes behavior.

## Architecture decision and stop rules

1. Keep the existing A1 field atlas, `SourceChartTransitionGraph`, A2b arc provenance, and A3 mandatory-chain partition. Do **not** introduce another topology registry or infer fan/sheet from position.
2. Retain the original unwired `SourceVertexId` helper as provisional. No production call may treat it as fan-safe. A new scoped resolver must use `SourceVertexEntityIdentity` and source-sheet evidence. Unknown/ambiguous identity fails closed.
3. Keep field-corner and A4 branch semantics in one exact owner. Current floating selection remains visible historical behavior until the exact replacement passes an independent gate.
4. Do not modify or weaken accepted selectors, verification, hard-feature stops, or the A2b/A3 single-writer boundary. Do not wire O36, claim D6 success, or promote CP3/selector497.
5. Every new CB compiles only. Each subsequent TB runs a fresh immutable package. A mismatch requires its own Review and correction, not a combined repair/test turn.

## Bounded conditional turn sequence

| Order | Turn | Single change and proof obligation |
|---|---|---|
| **NEXT 1** | `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` | Code + Build. Add an **unwired** source-supported node-to-`SourceVertexEntityIdentity` resolver. Reuse `SourceChartTransitionGraph`. It must return a typed ambiguity rather than merge two fans. Add focused synthetic fixtures only. Compile approved targets, **no runtime**. |
| 2 | `M6-CP3-TB102A-P13-A3-FAN-STOP-IDENTITY-EXEC` | Test + Benchmark. Positive one-fan case, shared-source-vertex/different-fan case, same position/different-sheet case, face-row and winding permutations, and invalid provenance. Demand a negative case that fails if fan matching is replaced with vertex-only matching. |
| 3 | `M6-CP3-CB121B-P13-A3-FAN-SCOPED-STOP-FILTER` | Code + Build. Change only the **unwired** chained factory's corner-stop selection to use the resolved fan identity. Keep all existing feature/port stops unchanged. No boundary branch rewrite. |
| 4 | `M6-CP3-TB102B-P13-A3-FAN-SCOPED-STOP-EXEC` | Focused immutable test. The intended node stops; the node in the other fan or sheet does not. All pre-existing feature and port stops remain. |
| 5 | `M6-CP3-CB121C-P13-A3-DERIVED-CORNER-POSITIVE-ORACLE` | Code + Build, **test-source only**. Add a transported, non-feature, straight-rim positive/negative pair. Do not change production code. |
| 6 | `M6-CP3-TB102C-P13-A3-DERIVED-CORNER-POSITIVE-EXEC` | Focused immutable test. The derived corner must split one pass-through chain, unlike the zero-turn control. Removal of the product input must fail the positive test. If it fails on existing code, preserve RED as evidence for the next correction. |
| 7 | `M6-CP3-CB122A-P13-A3-EXACT-RIM-BRANCH-OWNER` | Code + Build. Add a **single unwired** exact branch-selection product and exact tie/threshold status. Do not change A4 or corner consumers. |
| 8 | `M6-CP3-TB103A-P13-A3-EXACT-RIM-BRANCH-EXEC` | Focused immutable test: tie, near-threshold finite double, orientation reversal, face-row order and hard-barrier failure. Test a mutation that changes selected branch. |
| 9 | `M6-CP3-CB122B-P13-A3-RIM-BRANCH-CORNER-CONSUMER` | Code + Build. Make the **unwired corner producer only** read the exact branch product. Preserve source-fan keys. |
| 10 | `M6-CP3-TB103B-P13-A3-RIM-BRANCH-CORNER-EXEC` | Focused immutable test: derived corners and fan keys match the exact branch product. No independent branch choice remains in the corner producer. |
| 11 | `M6-CP3-CB122C-P13-A3-RIM-BRANCH-A4-CONSUMER` | Code + Build. Make A4's boundary-side classification consume the same published branch product. Do not switch A3 chaining or general production routing. |
| 12 | `M6-CP3-TB103C-P13-A3-RIM-BRANCH-A4-EXEC` | Full immutable gate plus targeted cut/hard-rail and cross-sheet cases. Require agreement for **all** admitted rim nodes. Any changed gate digest requires independent Review before another CB. |
| Later, separate tracks | O34, O35, O37, O36, D6 | First resolve uncut closed rails (O34), hard-feature span routing (O35), and one-pass breakpoint location (O37) with separate CB/TB pairs. Only then define a narrowly gated O36 production switch. D6 representative Vase acceptance remains separate and requires owner approval for the expected exit. |

**Turn-selection rule:** only the first unfinished row is authorized. Each following row depends on the prior run's independent result and may need a correction turn. Do not assign all rows to one implementation agent execution. Do not skip the new positive field-derived stop gate. These are planning identifiers, not names to copy into code symbols.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | No new selector. The prior Review checked 938 inherited rows; this audit verified the immutable artifacts and left the accepted CP2 selector unchanged. Source-side test/selector SHA re-derivation is not claimed for this audit. |
| Decisive claims independently re-derived | Reviewed two decision loops, vertex-only stop mapping, existing typed source-fan resolver, synthetic tests, raw four-corner and A3 receipts, and the immutable ZIP digests. |
| Non-vacuity checked | Current derived census shows zero changed chain counts. Manual stop tests cannot prove a derived stop. A non-feature transported positive case is required. |
| Prior obligations discharged/carried | Fan identity design and O39 ownership defined here. Implementation and evidence remain open. O34/O35/O36/O37/D6 carried; O38 production promotion remains open. |
| Stable accounting | 66/17/49, debt 1, deferred 81; CP2 491/491, CP3 unpromoted. |
| New candidates/obligations recorded | Vertex-only fan leakage, duplicate floating branch decisions, derived-positive non-vacuity: carried with narrow CB/TB owners in this record and regression tracker. |
| ORIENTATION currency line | Update to this Review audit and first CB. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 update; §4 no new fixture result; §8 add recurring over-broad identity design risk. |
| CHANGELOG | This Review audit will be recorded. |
| ROADMAP | No checkpoint changed. Not modified. |
| Selector manifest | No selector added or promoted. Not modified. |
| LESSONS | Existing non-vacuity and single-writer requirements apply. No new general lesson required. |
| Consolidation under CLEAN_UP_POLICY | No historical files deleted. Old next Review marked superseded rather than removed. |
| Successor frozen | `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` only. Falsifiers and stop rules specified in the sequence above. |
| Turn boundary held | Review only. No source, test, selector, or build logic changed. No tests or builds run. |
| review_check.py boundary | Snapshot has no Git history; code/test boundary checked by changed-path inventory and diff. Full Git-history boundary run not claimed. |
| `STATUS` lifecycle maintained | Entry published; final beacon will be written last. |
| Pushed to origin, branch in sync | To be determined from remote patch-apply evidence; no local tracked upstream in the snapshot. |

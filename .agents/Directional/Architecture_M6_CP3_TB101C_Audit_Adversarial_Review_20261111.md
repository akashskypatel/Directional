# Independent review of TB101C technical audit — 2026-11-11

## Situation

**Verdict: correct diagnosis, incomplete remedy.** Keep the prior audit's three risk areas and the scoped 940/940 test result. Reject its claim that the first two resolver/filter turns can establish fan-scoped corner safety. The corner producer still publishes a bare source-vertex list. A correct node resolver cannot reconstruct an occurrence that the corner producer discarded. Freeze the corrected sequence below. No implementation, tests or build logic change in this Review.

## Background and source authority

Reviewed exact source snapshot `3303a1259791c310bbc55a2d7f69e0dbb69c79e8`, run `43030018814`, artifact `13859123708`. Outer ZIP SHA-256 `0159a6b8f06d5097e0860ab0da617a04b007ee32eff914cfd29317e4c70d9270`. `source.tar.gz` digest and all 5,463 per-file SHA-256 hashes matched its manifest. This snapshot contains the previous audit and no subsequent implementation. Prior immutable full-gate evidence recorded 940/940 PASS and 1,021 membership on source `e1e5b17e94f189c88c74172e12dfd6ac93cc532b`. Its production census recorded Cylinder PASS, BunnyRandom RED, Vase RED. We did not execute binaries or claim new production success.

**Terms:** A *fan* is one connected set of source faces around a vertex, separated by topology or a barrier. A *corner record* is a typed observation that the field changes branch on that fan. *A3* schedules shared rail segments. *A4* constructs region geometry. *Unwired* means not used by the active production path.

## Assessment: code and architecture

### Critical 1 — only half of the identity is resolved

`src/geometry/SurfaceCellTracing.cpp:21582-21654` publishes `std::vector<SourceVertexId>`. `src/geometry/GlobalConformityBaselineSupport.cpp:482-511` converts those IDs to every matching network node. The public factory in `src/geometry/GlobalConformityBaseline.cpp:799-813` also accepts only that vertex list. `FieldAlignedCurveNetworkNode` at `include/directional/geometry/SurfaceCellTracing.h:352-361` has only a node ID and source vertex. Therefore no edge carries a fan key between producer and consumer. The prior audit's proposed CB121A node resolver followed immediately by CB121B factory filter is **not sufficient**: a typed node matched to a raw vertex still has no evidence identifying which fan supplied the corner. This remains unsafe even if the node resolver itself is correct.

**Correction:** Keep CB121A only as an independently testable node resolver. Insert a separate fan-keyed corner-product CB/TB pair **before** the factory filter. Use `SourceVertexEntityIdentity` from `SourceChartTransitions.h:77-82` and source/sheet authority. The graph assigns a distinct `SourceVertexFanId` for each connected fan (`SourceChartTransitions.h:815-864`) and checks the backing source. Reuse it. A node's exact incident arc endpoints and carrier faces must identify one admissible fan. A corner must also retain that fan identity from the producer's rim traversal. When either side has incomplete or contradictory provenance, refuse the match with a typed reason. Do not infer it from position, ordering or a default fan.

### Critical 2 — exactness of the arithmetic inputs is missing

Both branch selectors use `project_tangent` (`SurfaceCellTracing.cpp:248-256`), which normalizes using floating-point square roots. `face_normal` (`:230-241`) also normalizes a floating-point cross product. The two callers are at `:16705-16762` and `:21541-21580`. The audit demands exact ranking but does not distinguish exact source arithmetic from a comparison made exact **after** these rounded computations. Amendment 18 of `DESIGN.md` prohibits that substitution. The float source literal `0.7` is also not the exact rational `7/10`; replacing it without an explicit policy choice changes boundary cases.

**Correction:** Put one narrow arithmetic DEFN before the exact-owner Code + Build. It must name authoritative conditioned source coordinates and the certified field frame. For an exact normal, compute the unnormalized face cross product from exact source values. Tangent projection can use a division-free numerator `(N·N)D - (D·N)N`. Compare the signs of exact dot products first. Compare squared values and positive norm products to rank normalized alignments without square roots. Define which exact threshold is authoritative: exact binary64 value of `0.7`, or a deliberate new `7/10` contract. Do not claim both are identical. The certified atlas must own quarter-turn gauge transport, not a second unoriented local comparison. Invalid normals, ambiguous maximizers and unavailable transport must have distinguishable typed outcomes.

### High 3 — ambiguous alignment currently becomes a corner

`derive_boundary_field_corner_vertices` marks `turns=true` if its starting branch is unavailable or if transport is invalid. The existing 45-degree test (`tests/SurfaceCellsPhase10Tests.cpp:8308-8340`) expects four corners from tied branches. That proves a diagnostic **stop-on-uncertainty** convention, not that four real field turns occurred. The previous audit calls exact ties undecided, but does not explicitly reconcile this with the accepted old test. A later implementation could silently change this behavior and report only a green count.

**Correction:** Distinguish `Changed`, `Unchanged`, and `Undecided` in the published result. `Undecided` must not be certified as a field turn. Preserve the old helper and its historical tests until an independently reviewed migration. A required but undecided rim decision fails closed before production chaining. A test-only gate may record RED if the new contract exposes a historic ambiguity. Do not weaken the existing test to obtain a pass.

### High 4 — positive proof is still absent

`GlobalConformityBaselineTests.cpp:1851-1880` uses supplied vertex IDs. The factory test at `SurfaceCellsPhase10Tests.cpp:8495+` also exercises a caller-supplied ID. The four case-level `d4-corner` records did not change chain counts. This proves manual forwarding only. The previous audit diagnosed the problem correctly. However, its suggested positive witness before a fan-keyed producer could still pass through the wrong fan.

**Correction:** Add the positive producer-to-consumer witness **after** both producer and factory carry the same typed fan. It needs a real straight rim, a field branch change at a non-feature degree-two node, and a paired no-change field. Require the intended chain to split and the other fan to remain joined. Removing the derived product must fail the positive test.

### Medium 5 — source and policy boundaries need explicit checks

`SourceChartTransitionGraph` requires `SourceTopologyRegions` and the hard-feature edge set. Its identity is only valid against its bound inputs. A3's exact arc path contains carrier support and exact endpoints (`GlobalTopologyPlan.h:44-56`, `ExactSourcePath.h:37-44`). A new resolver cannot assume every incident arc endpoint carries enough witness faces. It must reject missing, different or ambiguous fan evidence. The branch owner must also check that its atlas gauge belongs to the same conditioned source and field. An orientation or source-face row permutation must preserve the typed outcome, not merely the test count.

### Scope and acceptance

The previous audit was correct not to promote CP3 or the 497-selector. The immutable full-gate result is scoped evidence, not direct production success. The reported Cylinder PASS does not prove A3 interval consumption. No accepted-green loss was established. Keep the stable 66 events, 17 categories, 49 recurrences, debt 1 and 81 deferred unchanged. Carry O34, O35, O36, O37, O38, O39 and D6 separately. Do not implement the production switch in these turns.

## Recommendation: narrow conditional sequence

Only the first unfinished turn is authorized. Each Code + Build turn compiles without running generated binaries. The following Test + Benchmark turn runs only an immutable compiled package. A RED or altered accepted control needs its own independent Review before further implementation. Turn IDs are metadata, not code names.

| Order | Turn | Scope and acceptance |
|---|---|---|
| **1 NEXT** | `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` | Compile only. Create an unwired, source-supported network-node fan resolver using existing A2b exact arc endpoint carriers and the verified `SourceChartTransitionGraph`. Return typed unresolved when supports do not identify one component/fan/sheet. Do not guess from `sourceVertex` or position. No corner producer or factory changes. |
| 2 | `M6-CP3-TB102A-P13-A3-FAN-STOP-IDENTITY-EXEC` | Immutable focused test: one fan positive, shared vertex in separate fans/sheets negative, missing and conflicting endpoint carriers RED, row and winding invariance. Vertex-only replacement must fail. |
| 3 | `M6-CP3-CB121B-P13-A3-FAN-KEYED-CORNER-PRODUCT` | Compile only. Add an unwired **fan-keyed corner output** from each boundary-fan traversal, using the same verified graph and source authority. Preserve separate records when one source vertex has two fans. Retain the old vertex-list API as a non-authoritative historical path. Do not change A3 stops or A4. |
| 4 | `M6-CP3-TB102B-P13-A3-FAN-KEYED-CORNER-EXEC` | Immutable positive two-fan witness: one fan is a corner, one is not. Confirm no merging, no duplicated fan record, failure on missing graph or inconsistent transport, row/winding invariance. |
| 5 | `M6-CP3-CB121C-P13-A3-FAN-SCOPED-STOP-FILTER` | Compile only. Unwired chained-factory path accepts fan-keyed corners and resolved nodes. Compare exact identities, not raw vertex numbers. Keep port, feature and hard-edge endpoint stops under their existing independent rules. Reject unresolved corner matches. |
| 6 | `M6-CP3-TB102C-P13-A3-FAN-SCOPED-STOP-EXEC` | Immutable focused test: only intended fan chain splits. Other fan remains joined. Port and hard-edge stops remain. Negative replacement with vertex-only matching must fail. |
| 7 | `M6-CP3-CB121D-P13-A3-DERIVED-CORNER-WITNESS` | Compile only, test source only. Add a straight source-rim, degree-two, non-feature field-turn witness plus no-turn control. Test derived product-to-factory consumption without a manually supplied corner. No production changes. |
| 8 | `M6-CP3-TB102D-P13-A3-DERIVED-CORNER-EXEC` | Immutable focused test. Exactly one intended chain splits. Negative control does not split. Remove the derived product and the positive assertion must fail. If RED, open a separate review/correction. |
| 9 | `M6-CP3-DEFN-P13-A3-EXACT-RIM-ARITHMETIC` | Runtime-free Review. Freeze authoritative conditioned coordinates and field frame, exact normal/tangent construction, binary64-versus-7/10 threshold policy, atlas branch gauge, and undecided semantics. Do not implement before these choices are evidenced. |
| 10 | `M6-CP3-CB122A-P13-A3-EXACT-RIM-BRANCH-OWNER` | Compile only. Publish an unwired directed-edge branch decision with fan/sheet/source certificate or typed undecided reason. Use exact arithmetic from the frozen source, not rounded normals. No consumer changes. |
| 11 | `M6-CP3-TB103A-P13-A3-EXACT-RIM-BRANCH-EXEC` | Immutable tests: opposite directions, exact tie, either side of threshold, degenerate normal, gauge rotation, two fans, invalid transport, row/winding permutations. Prove mutation detection. |
| 12 | `M6-CP3-CB122B-P13-A3-RIM-BRANCH-CORNER-CONSUMER` | Compile only. Unwired corner producer reads the branch certificate and emits typed fan-keyed corners. Remove its independent floating branch selection on this path. |
| 13 | `M6-CP3-TB103B-P13-A3-RIM-BRANCH-CORNER-EXEC` | Immutable tests prove derived corner equivalence and typed undecided behavior. Re-check fan-scoped positive case and independent hard-feature stops. |
| 14 | `M6-CP3-CB122C-P13-A3-RIM-BRANCH-A4-CONSUMER` | Compile only. A4 boundary-side walk consumes the same certified branch values. No A3 chained production switch or general pipeline wiring. |
| 15 | `M6-CP3-TB103C-P13-A3-RIM-BRANCH-A4-EXEC` | Immutable full gate plus adversarial rim/fan/hard-edge tests. Require all admitted boundary segments to have one owner and compatible global-branch gauge. Differences require separate Review. |


The exact arithmetic DEFN is a Review turn, not an instruction to invent arithmetic in CB121A. These tasks do not approve source-grid recovery or weaken source provenance. O34, O35 and O37 need separate proof before an O36 switch. D6's Vase target still needs owner approval.

## Review closeout

| Duty | Result |
|---|---|
| Selector continuity | No selector changed. Old 940/940 evidence retained as scoped. No new selector re-hash claimed. |
| Source-derived findings | Verified raw vertex corner product, raw vertex factory, existing fan graph, exact path carrier, float-normalization sites, and ambiguous-branch fallback. |
| Independent non-vacuity | Required a derived fan-specific chain split and a mutation that removes its product. Existing raw 4-case census does not prove it. |
| Obligations | Corrected fan-product gap and O39 arithmetic gap. O34/O35/O36/O37/O38/D6 remain open and assigned to later tracks. |
| Stable accounting | 66/17/49, debt 1, deferred 81, accepted CP2 491/491. No CP3 promotion. |
| Normative correction | DESIGN's corner-stop amendment gains producer+consumer typed binding and pre-normalization exactness requirements. |
| Durable records | Audit, handoff, TODO, orientation, changelog and regression tracker updated for this corrected sequence. ROADMAP and selector manifest unchanged because milestone authority did not move. |
| Turn boundary | Review only. No source/test/fixture/selector/build edits and no test execution. |
| Runtime review check | Full checkout Git ancestry is unavailable in snapshot. Locally checked changed paths, patch applicability and whitespace. No full `review_check.py boundary` result claimed. |
| Successor | `M6-CP3-CB121A-P13-A3-FAN-STOP-IDENTITY-RESOLUTION` only, with the tightened node-resolver contract. Remaining turns conditional. |
| Remote push evidence | To be reconciled from the exact Drive apply result before final beacon. |

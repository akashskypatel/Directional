# RA-220 — D5 boundary-chain consumption (step 64B.8)

**Turn:** `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION` (64B.8, Review). **Disposition: COMPLETE.** One exact patch and one full-gate manifest are frozen: CB113 makes every A3 consumer chain-aware and adds the chained input factory, **without wiring it into production**; TB96 gates it. The production switch is **not** frozen: this Review found that the stage-1 switch is predicted to reject regions that are green today (§2). TB96 measures that prediction on the smallest product slice. Runtime-free: syntax checks and one model only; no product or test source changed in the repository.

## 1. What was read

Every consumer of the A3 schedule outside the baseline itself (`grep` over `src` and `include`):

| Site (`SurfaceCellTracing.cpp`, pre-patch lines) | Reads | Per-arc assumption |
|---|---|---|
| `:9690` `summarize_a3_span_coverage` | incidences, schedule | None: keyed by the span's identifying arc. Unchanged |
| `:15650–15690` cut-domain boundary | incidence at each walk ordinal, schedule of `from_network_arc(arc)` | One incidence per walk arc; support equals the arc's path |
| `:17461–17700` bounded-disk side walk | schedule and `breakpoint_location` per arc | Span = arc; all breakpoints on piece 0 |
| `:18433–18447` preflight | schedule size, schedule per arc | One entry per arc; support equals the arc's path |
| `:18849–19110` A4 hard-rail pairing | `generator_route_for_span`, `HardRailPairKey` | Span is a one-piece Mandatory arc. Unchanged (stage 1 never chains a hard-feature rail) |

`RemeshPipeline.cpp:1005` (factory) and `:13016` (its one production call) complete the list. The uniform planar and periodic producers do not read the schedule at all; that is D4 (64C), not this turn.

Two facts about the bounded-disk producer decide the design:

- **Side corners are field-branch changes** along the boundary cycle (`rebuild_run_starts`, `:16703`), not feature corners. A corner can therefore fall inside a chained span.
- **Opposite sides must have equal interval counts** (`:17746–17757`), and A3 is parity-only. Today's agreement comes from per-arc counting on source meshes whose opposite sides have the same number of edges.

## 2. Finding: the stage-1 switch is predicted to regress mixed regions

RA-219 stage 1 chains source-boundary rails and leaves hard-feature rails per arc. A region with a chained boundary side facing a per-arc hard rail then rounds the two sides separately. On the rectangular hard-rail fixture (two unit edges per side, base target about 0.69), per-arc gives 1 + 1 = 2 on the hard rail and the chain gives round(2 / 0.69) = 3 on the boundary. The producer rejects 3 against 2 with `InvalidFrontBoundaryAuthority`. That fixture backs several green GUARD rows.

Full chaining would be consistent (both sides 3), but chaining hard-feature rails needs the A4 pairing rewritten (`generator_route_for_span` requires a one-piece arc, the face-authority key and `HardRailPairKey` are per carrier). That is debt O35 and belongs with the A4 definition (65C).

The adaptive target size is not computable here, so this is a prediction, not a fact. **Decision:** land the consumers first, behaviour-neutral, and let TB96 measure the fixture (§5, test 2). The switch is placed afterwards (new obligation **O36**, §6).

## 3. Decisions

1. **A chained input factory in the geometry library.** `make_chained_global_conformity_baseline_input(V, h, topology, network, featureCurves)` derives the stops, partitions, and gives each chain one span whose support is its arcs' paths in chain orientation. It returns nothing when the plan and network disagree. The pipeline's per-arc factory stays and stays the production call.
2. **One helper resolves an arc.** `bound_arc_schedule(baseline, arc)` returns the arc's binding and schedule entry, and nothing unless the arc's path in chain orientation is the slice of the span's support that the binding names. Preflight, the cut domain and the side walk all use it.
3. **Preflight** requires that slice for every arc, and that the slices leave no support piece over. For a per-arc plan this accepts exactly what the old size-and-equality check accepted.
4. **Cut domain.** A span's side is read at its identifying arc. The walk meets that arc `chainOrdinal` arcs before the current one when it follows the chain, and as many after it otherwise (a chain crosses only two-incidence nodes, so the walk holds it consecutively). The incidence there must name the span, with orientation Forward exactly when the walk follows the chain.
5. **Side walk.** Each span's breakpoints are located once. On each arc the walk emits the breakpoints on that arc's piece, both ends included, in walk order. Two consecutive breakpoints of one span bound a unit interval wherever the arcs between them end; an arc with no breakpoint emits nothing. A side starts, and a span gives way to the next, only on a breakpoint at the vertex the walk is on; a side ends the same way. Anything else is the existing `InvalidFrontBoundaryAuthority`. An interval is labelled with the span's identifying arc and is Forward when ordinals ascend.
6. **A corner inside a span rejects** unless a breakpoint lies on it. Choosing corners per disc is D6, which is still a user decision.
7. **Hard-rail face-authority key unchanged.** It stays keyed by the arc. It is read only for two-sided carriers, which stage 1 never chains; re-key it by span under O35.

## 4. CB113, frozen

- [Patch](Architecture_M6_CP3_CB113_P13_A3_Chain_Aware_Consumers_Exact.diff): SHA-256 `af68344bfec46c0219833db8c41e0089e2e4d6f479cf79fec7a3910a1bee19f4`, 675 lines, 16 single-space context lines. Numstat `12 0` `GlobalConformityBaseline.h`; `32 0` `GlobalConformityBaseline.cpp`; `182 72` `SurfaceCellTracing.cpp`; `193 0` `SurfaceCellsPhase10Tests.cpp`. Base is product source CB112 `35912b11f…`; `git apply --check` is clean at HEAD.
- **Neutral for production**, because production still builds the per-arc input. For a per-arc plan: every binding is ordinal 0, Forward, piece 0, so the identifying-arc ordinal is the arc's own and the composed orientation is the walk's; the walk makes the same `append_point` calls up to repeats of an identical point, and pushes the same intervals in the same order; no new rejection can fire (the first breakpoint is at the arc's walk start and the last at its walk end).
- **Tests (GUARD 930–931)**, both on the rectangular hard-rail fixture, which now keeps its feature curves:

  | Test | Asserts |
  |---|---|
  | `D5ChainedBaselineAtUnitSizeReproducesThePerArcGrid` | At target size 1 the chained input has chains; each holds only source-boundary arcs; its support equals `derive_mandatory_chain_support`; spans + chained arcs = arcs. Per-arc counts are all 1 and each chain's count is its length. Both baselines produce, with equal grid, edge and cell counts and identical cell corners (face and barycentric). The chained product has no partial or foreign span, the same unrecorded spans, covers every chain span, and covers `chained arcs` fewer spans than the per-arc product |
  | `D5ChainedBaselineAtTheFixtureTargetBuildsAndReportsItsDisposition` | At the fixture's own target size the chained baseline builds, validates, and schedules arcs − chained arcs spans. A produced network must have no partial or foreign span. The disposition itself is **reported, not asserted** |

- **Receipts:** `D5_CONSUMER_RECEIPT case=unit …` and `D5_CONSUMER_RECEIPT case=fixtureTarget chains=… arcsToCount=… disposition=… reason=… covered=…`.
- **Why target size 1.** Every arc of the fixture is a unit source edge and both regions have an even boundary, so the counts are exact integers with no rounding and no flip. The chain's middle breakpoint then lies on the shared vertex, which exercises the junction rule (a breakpoint on a piece's far end is located at the start of the next piece) in both walk directions.
- **Checks:** `-fsyntax-only` returns 0 on `GlobalConformityBaseline.cpp`, `GlobalConformityBaselineSupport.cpp`, `GlobalConformityBaselineValidator.cpp`, `SurfaceCellTracing.cpp`, `RemeshPipeline.cpp`, `GlobalConformityBaselineTests.cpp` and `SurfaceCellsPhase10Tests.cpp`. An independent model of the side walk (`scratchpad/rev220/model_walk.py`) ran 4,000 random chained spans (1–6 pieces, either walk direction, arcs stored either way): 1,359 accepted with exactly the expected breakpoints and unit intervals, 2,641 rejected because a side end was not a breakpoint, 0 disagreements.
- **Non-vacuity:** ignoring the binding in the walk, the cut domain or preflight fails 930 (the chained product rejects or differs). Reading a side at every chain arc, dropping the junction rule, or labelling intervals by arc fails 930 through coverage. A factory that chains a hard-feature arc or builds a different support fails 930.
- **Registered gaps.** A plan cannot be forged from a test, so the new preflight and cut-domain rejections are unreachable from tests. No fixture has an interval that crosses several source edges with consistent opposite sides (every region of this fixture faces a hard rail), so the multi-edge boundary path of a cell edge is first exercised by the fixture-target receipt if it produces, and otherwise by the switch.

## 5. TB96, frozen

- [Manifest](gates/Architecture_M6_TB96_P13_A3_Chain_Aware_Consumers_Full_Gate_Case_Manifest.tsv): 931 rows, SHA-256 `ca7238a48d8f2cbc17b872feb7fd9502ac81891b1d094fe36f9a7e34cd4613ee`. It is TB95's 929 rows byte for byte, plus GUARD 930–931. `SELF_CHECK_PASS cases=931 deferred=81`; membership 1012; ledger v5 and harness `78b8002c…` unchanged.

| Outcome | Route |
|---|---|
| 931/931 PASS; all 7 platform-digest and 7 a3-coverage lines byte-identical to TB95; census Cylinder PASS, BunnyRandom and Vase registered RED unchanged; both `D5_CONSUMER_RECEIPT` lines recorded verbatim | MATCH → `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (64C, **Review agent only**), which also discharges O36 |
| Any failure in 930–931, any regression in 1–929, or any digest change | MISMATCH → `M6-CP3-TB96-P13-A3-CHAIN-AWARE-CONSUMERS-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB96A-P13-A3-CHAIN-AWARE-CONSUMERS-ORCH` |

**Registered prediction (not a pass condition):** `case=fixtureTarget` reports `disposition=Rejected reason=InvalidFrontBoundaryAuthority`, with chain counts that differ from twice the per-edge count.

## 6. Sequence and the switch (O36)

| Step | Turn | Owner |
|---|---|---|
| 64B.8 | `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION`: COMPLETE (this record) | Review |
| 64B.9 | `M6-CP3-CB113-P13-A3-CHAIN-AWARE-CONSUMERS`: exact patch §4, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-CHAIN-AWARE-CONSUMERS-STOP`; infrastructure → `M6-CP3-CB113A-P13-A3-CHAIN-AWARE-CONSUMERS-ORCH` | implementation agent |
| 64B.10 | `M6-CP3-TB96-P13-A3-CHAIN-AWARE-CONSUMERS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64C | `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (D4), and O36 | **Review agent only** |

**O36, the production switch.** It is one call-site change (`RemeshPipeline.cpp:13016` calls the chained factory with `featureMap.curves`, failing as `InvalidTopologyBinding` when it returns nothing) plus test amendments. 64C places it from the TB96 receipt:

- `fixtureTarget` **Rejected** (predicted): the switch waits for hard-feature chaining (O35) and is frozen with the A4 definition (65C). RA-218 §4's Vase prediction (145 Mandatory spans → 3 rim chains) carries to that TB.
- `fixtureTarget` **Produced** with full coverage: 64C may freeze the switch itself. Tests to amend then: `RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b` (validates the pipeline baseline against the per-arc input and asserts one entry per arc) and `A3SourceRimIntervalsAreRecordedSingleSidedAndValidated` (its `physical_carrier` requires a one-piece support and a one-step route). The switch TB must pre-register that closed surfaces keep their digests.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB96's rows 1–929 are TB95's manifest byte for byte. Selector497/CP3 is unpromoted, so there is no accepted-selector change |
| Decisive claims re-derived | Read every schedule consumer (§1), the side-run construction, the opposite-side check, the boundary-authority path walk (multi-carrier runs are supported), the product factory's interval checks, `derive_metric_breakpoint_location`, the feature-curve corner and junction producer, and the TB95 report |
| Non-vacuity | §4 |
| Obligations carried | 64B.9–64B.10; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34; O35; **new O36** (place the D5 production switch from the TB96 receipt); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB95 929/929, membership 1010; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |

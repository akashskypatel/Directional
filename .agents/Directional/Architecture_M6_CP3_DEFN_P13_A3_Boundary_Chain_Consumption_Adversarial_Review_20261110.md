# RA-221 — Adversarial re-review of the D5 boundary-chain consumption definition (step 64B.8)

**Turn:** `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION` (64B.8, re-entered). **Disposition: COMPLETE; [RA-220](Architecture_M6_CP3_DEFN_P13_A3_Boundary_Chain_Consumption_Review_20261110.md) is amended.** RA-220's analysis (§1–§3) stands with the corrections below. Its frozen CB113 and TB96 (§4–§6) are **withdrawn before use** and replaced by two narrower turns: CB113 (chained input factory) → TB96, then CB116 (chain-aware consumers) → TB97. Runtime-free. Four read-only audits were delegated to subagents; their findings are attributed in §1.

## 1. Findings against RA-220

| # | Finding | Kind | Action |
|---|---|---|---|
| F1 | **CB113 was monolithic.** One patch held an A3 input factory, three A4 consumer rewrites and two tests; a failure could not be attributed to a stage | Scope | Split (§3). The factory is testable without any consumer; the consumers are not separable from each other (§3.2) |
| F2 | **The factory re-implemented the accepted chain support** and dropped its canonical-path check, to avoid a linear arc search. That breaks RA-217's rule that agreeing code shares one decomposition | Design | `derive_mandatory_chain_support` now finds arcs by binary search (A2b publishes arcs sorted by id), and the factory calls it for every chain. Single arcs are copied verbatim, as the per-arc binder does |
| F3 | **RA-220 §6 let 64C freeze the production switch if one fixture produced.** One fixture is not evidence for Plane, Cylinder or Vase | Architecture | Withdrawn. O36 now lists what the switch needs (§4) |
| F4 | **The stage-1 finding was understated.** DESIGN §7.4 makes baseline A3 parity-only and gives A4 the "rectangular / general even-boundary constructibility question". Per-arc counts satisfy the rectangular producer by accident. Full chaining restores equality only where opposite sides have equal metric length; it does not on curved discs | Architecture | Recorded in DESIGN §7.4 and O36. D5 alone cannot turn Vase green; it needs an A4 producer for unequal opposite sides or a framed schedule |
| F5 | **The stop set does not contain disc corners.** A source-boundary loop is one closed rail; corners split neither curves nor rails (`tangent_compatible_at_vertex` accepts every Boundary–Boundary pair). A chain stops only where `is_corner` flags a vertex, at junctions, ports and hard-feature ends. Bounded-disk corners are field-branch changes, known only in A4. A smooth disc therefore has corners inside spans, and RA-220's walk rejects them | Architecture | New obligation **O38**: before the switch, either A3 learns the corner nodes from an upstream product or A4 moves corners to breakpoints. This was first labelled D6 in error; D6 is the Vase success criterion and is unrelated (see the addendum) |
| F6 | **Cost.** `breakpoint_location` recomputes every run's weight (a big-integer square root) on each call. Locating a chain's `count + 1` breakpoints costs `count × runs` roots; a 5,000-edge boundary with 2,500 intervals needs about 10⁷ | Performance | New obligation **O37**: a batch location function (one pass over the runs) before the switch. Not needed for CB116's tests |
| F7 | **RA-215 (D9) says a rim interval carries "the route's orientation".** Under D5 the label follows span ordinals, so an arc stored against its chain has a Forward interval on a Reverse route step | Contract | No production code compares the two (audit, §2). The RA-215 test does, and must be amended at the switch (O36) |
| F8 | RA-220's second test asserted nothing about the producer | Test | Folded into the consumer test as a receipt; the factory test now carries the firm assertions and reports both count vectors, so the side mismatch can be read arithmetically from TB96 without the producer |
| F9 | The preflight comment claimed an exact cover; the code compares total piece counts and relies on the baseline's bindings being disjoint. The helper also rejected an empty path, which the old check did not | Accuracy | Empty-path rejection removed (now exactly neutral). The reliance is stated in §3.2 |

No behavioural defect was found in the side walk. One reported defect (a multi-piece single arc losing breakpoints) is not reachable: `append_arc_schedule` still rejects any arc that is not one piece.

## 2. Delegated audits (Haiku subagents, read-only)

| Audit | Result used |
|---|---|
| Rail construction (`build_authoritative_surface_cell_rails`) | One rail per maximal same-kind run of a feature curve; a closed all-boundary curve is one closed rail; corners are recorded, not split; every edge of a rail shares its `HardRailId` (F5) |
| Readers of `sharedBoundaryInterval` (11 groups) | The product factory checks ordinals against orientation only. Route orientation, step count and span-versus-carrier are compared only for edges with an opposite edge or of kind HardRail. Multi-step rim routes are accepted (F7) |
| DESIGN on side equality and corners | Baseline is parity-only; the framed Bi-MDF is historical; no stage is named as owner of opposite-side equality except A4's constructibility clause; D6 is not defined in DESIGN (F4, F5) |
| Line-by-line review of the withdrawn CB113 diff | No per-arc divergence in emission, de-duplication, cursor continuity, wrap arithmetic or reference lifetimes. Raised F2, F8, F9 and the unreachable case above |

## 3. Frozen turns

### 3.1 CB113 — chained input factory (A3 only)

- [Patch](Architecture_M6_CP3_CB113_P13_A3_Chained_Input_Factory_Exact.diff): SHA-256 `2e9f4d348c505f34c5e799a5d1744748a41899af3f1dfafc9e383b8c44fb897d`, 265 lines, 8 single-space context lines. Numstat `13 0` `GlobalConformityBaseline.h`; `33 0` `GlobalConformityBaseline.cpp`; `6 4` `GlobalConformityBaselineSupport.cpp`; `1 0` `GlobalConformityBaselineSupport.h`; `129 0` `SurfaceCellsPhase10Tests.cpp`. Base is product source CB112 `35912b11f…`; `git apply --check` is clean at HEAD.
- **Adds** `make_chained_global_conformity_baseline_input` (stops → partition → one span per chain). Nothing calls it. **Changes** the arc lookup in `derive_mandatory_chain_support` from a linear search to a binary search; its accepted tests pass arcs in id order.
- **Test (GUARD 930)** `D5ChainedInputJoinsOnlySourceBoundaryRailsAndCountsEachChainOnce`, on the rectangular hard-rail fixture (which now keeps its feature curves):
  - chains exist; each has two or more arcs, none on a hard-feature edge;
  - every arc outside a chain keeps its own span with its verbatim path, and a chain's later arcs have no span;
  - at target size 1 the per-arc baseline counts every span 1, and the chained baseline counts each chain its length, with as many support pieces; it validates; each chain arc's binding has its ordinal as chain ordinal and piece offset;
  - at the fixture's own target size the chains are the same, and the chained baseline builds and validates.
- **Receipts:** `D5_FACTORY_RECEIPT case=unit …` and `case=fixtureTarget perArc=<pieces:count,…> chained=<pieces:count,…>`.
- **Non-vacuity:** chaining a hard-feature arc, dropping or duplicating a span, a wrong support, or a wrong binding offset each fail 930. A lookup that misses a sorted arc fails the accepted row 922 as well.

### 3.2 CB116 — chain-aware consumers (A4 only)

- [Patch](Architecture_M6_CP3_CB116_P13_A3_Chain_Aware_Consumers_Exact.diff): SHA-256 `954b11df326285b2aaa5a293d36ef1c82380628d8ea4209a13d8b8461562a7cf`, 527 lines, 8 single-space context lines. Numstat `184 72` `SurfaceCellTracing.cpp`; `137 0` `SurfaceCellsPhase10Tests.cpp`. It applies on top of CB113 (checked in a scratch worktree).
- **Content:** RA-220 §3 decisions 2–7 unchanged: `bound_arc_schedule`, preflight, the cut-domain identifying-arc rule, and the side walk. Preflight relies on the baseline's bindings naming disjoint slices; it checks each slice and the total.
- **Why it is one patch.** A chained plan must pass preflight, the cut domain and the walk before anything observable differs. Landing one site alone has no test that can tell it from the old code.
- **Neutral for production**, which still builds the per-arc input (RA-220 §4 argument; confirmed by the line-by-line audit).
- **Test (GUARD 931)** `D5ChainedBaselineAtUnitSizeReproducesThePerArcGrid`: at target size 1 both baselines produce; grid, edge and cell counts match; every cell corner has the same face and barycentric coordinates; edge for edge, both products record an interval or neither does, and the chained interval is labelled with the span that binds the per-arc interval's arc; the intervals on chain spans number chained arcs + chains; coverage has no partial or foreign span, the same unrecorded spans, and covers every chain span. The fixture-target disposition is printed, not asserted.
- **Receipts:** `D5_CONSUMER_RECEIPT case=unit …` and `case=fixtureTarget spans=… disposition=… reason=… covered=…`.
- **Checks for both patches:** `-fsyntax-only` returns 0 on all seven affected sources. The walk model of RA-220 (4,000 cases, 0 disagreements) covers the unchanged walk.
- **Registered gaps (unchanged):** a plan cannot be forged from a test, so the new rejections are unreachable from tests; no fixture has a multi-edge interval with consistent opposite sides.

### 3.3 TB96 and TB97

| | TB96 | TB97 |
|---|---|---|
| Manifest | [930 rows](gates/Architecture_M6_TB96_P13_A3_Chained_Input_Factory_Full_Gate_Case_Manifest.tsv) `227405f4e775717f7941fc1366fac41098e3dadd36b51eeb7b238e6feb633b26` | [931 rows](gates/Architecture_M6_TB97_P13_A3_Chain_Aware_Consumers_Full_Gate_Case_Manifest.tsv) `111afe9375f78ac12d5118f2af494fac87cf43f7ad79fe5ee274bada1aa16341` |
| Built from | TB95's 929 rows byte for byte + GUARD 930 | TB96's 930 rows byte for byte + GUARD 931 |
| Self-check | `SELF_CHECK_PASS cases=930 deferred=81`; membership 1011 | `SELF_CHECK_PASS cases=931 deferred=81`; membership 1012 |
| MATCH | 930/930; 7 + 7 digest lines byte-identical to TB95; census unchanged; both `D5_FACTORY_RECEIPT` lines recorded → `M6-CP3-CB116-P13-A3-CHAIN-AWARE-CONSUMERS` | 931/931; 7 + 7 lines byte-identical to TB95; census unchanged; both `D5_CONSUMER_RECEIPT` lines recorded → `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (64C, Review agent only) |
| MISMATCH (any new-row failure, regression or digest change) | `M6-CP3-TB96-P13-A3-CHAINED-INPUT-FACTORY-FULL-GATE-REV` | `M6-CP3-TB97-P13-A3-CHAIN-AWARE-CONSUMERS-FULL-GATE-REV` |
| Infrastructure | `M6-CP3-TB96A-P13-A3-CHAINED-INPUT-FACTORY-ORCH` | `M6-CP3-TB97A-P13-A3-CHAIN-AWARE-CONSUMERS-ORCH` |

**Registered predictions (not pass conditions).** TB96 `fixtureTarget`: the chained vector has two-piece spans whose count is not twice the per-arc count of a unit edge. TB97 `fixtureTarget`: `disposition=Rejected reason=InvalidFrontBoundaryAuthority`.

## 4. Sequence and obligations

| Step | Turn | Owner |
|---|---|---|
| 64B.8 | `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION`: COMPLETE (RA-220 as amended here) | Review |
| 64B.9 | `M6-CP3-CB113-P13-A3-CHAINED-INPUT-FACTORY`: exact patch §3.1, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-CHAINED-INPUT-FACTORY-STOP`; infrastructure → `M6-CP3-CB113A-P13-A3-CHAINED-INPUT-FACTORY-ORCH` | implementation agent |
| 64B.10 | `M6-CP3-TB96-P13-A3-CHAINED-INPUT-FACTORY-FULL-GATE-EXEC` | implementation agent |
| 64B.11 | `M6-CP3-CB116-P13-A3-CHAIN-AWARE-CONSUMERS`: exact patch §3.2 on top of CB113, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-CHAIN-AWARE-CONSUMERS-STOP`; infrastructure → `M6-CP3-CB116A-P13-A3-CHAIN-AWARE-CONSUMERS-ORCH` | implementation agent |
| 64B.12 | `M6-CP3-TB97-P13-A3-CHAIN-AWARE-CONSUMERS-FULL-GATE-EXEC` | implementation agent |
| 64C | `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (D4); records the TB96/TB97 receipts against O36 | **Review agent only** |

**O36 — the D5 production switch.** It is not scheduled. It is one call-site change plus test amendments, and it may be frozen only when all of these hold:

1. hard-feature rails chain too (O35, with the A4 definition 65C), or the TB97 receipt shows the mixed stage producing;
2. disc corners cannot fall inside a span (O38; decided, see the addendum);
3. breakpoints are located in one pass (O37);
4. its TB pre-registers which digests may change (closed surfaces may not), and amends `RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b` and `A3SourceRimIntervalsAreRecordedSingleSidedAndValidated` (one-piece support, one-step route, step orientation equal to interval orientation).

Even then, opposite sides agree only where their metric lengths do (F4). Regions where they do not stay rejected until A4 can construct them.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB96's rows 1–929 are TB95's manifest and TB97's rows 1–930 are TB96's, byte for byte. Selector497/CP3 is unpromoted |
| Decisive claims re-derived | §1–§2; additionally `exact_source_path_is_canonical`, `find_arc` ordering, and the feature-curve tangent rule were read directly |
| Non-vacuity | §3.1, §3.2 |
| Obligations carried | 64B.9–64B.12; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34; O35; O36 (amended); **new O37, O38**; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB95 929/929, membership 1010; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository. The withdrawn CB113 diff and TB96 manifest were never applied; they remain in history at `75ff2b9a3` |

## Addendum (2026-11-10): user decision on O38

**Correction.** F5 and §4 called O38 "the D6 decision". That was wrong. D6 is the Vase success criterion (RA-214: field-derived valence targets, expected tier D1, or a boundary-aligned field) and is **still pending**. O38 is a separate question and is the one decided here.

**Decision (user, 2026-11-10): the subdivision gives way.** Disc corners are chain stops. A chain always ends at a corner, so every side of a region is a whole number of spans and no span turns a corner. Corners stay where the field puts them; A4 does not move a corner to a breakpoint.

**What it requires.**

1. The corner nodes become a published upstream product: the boundary nodes where the field branch that follows the boundary changes. Today that test runs inside the bounded-disk producer (`rebuild_run_starts`), in floating point, per region.
2. `derive_mandatory_chain_stop_nodes` reads that product as a fourth source of stops.
3. The bounded-disk producer reads its side starts from the same product instead of deriving them again, so the scheduler and the producer cannot disagree. A corner that is not a stop then stays a typed rejection and marks a defect, not a normal outcome.

**Turn.** `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (step 64B.13, **Review agent only**). It defines the product and its determinism rule (DESIGN §10.1 row permutation), and freezes an unwired exact patch with tests and its full-gate TB. It does not block CB116, TB97 or 64C and may run alongside them. Exit: those frozen inputs, or `M6-CP3-PLAN-P13-A3-DISC-CORNER-STOPS-STOP` naming the blocking fact.

**TB96 evidence that changes §3.3's prediction.** TB96 closed MATCH. Its receipt reads `case=fixtureTarget perArc=1:4 ×20  chained=1:4 ×12, 2:8 ×4`: at the fixture's own target size a unit edge counts 4 and a two-edge chain counts 8. The registered prediction (a chain count that is not twice the per-edge count) is **false for this fixture**; the adaptive target is about 0.25, not 0.69. The mixed stage is consistent here, so TB97's `fixtureTarget` is now expected to produce. The general finding stands: a chain and the per-arc rail facing it round separately, and they agree only when the edge-to-target ratio is close to an integer.

**O36 after this decision.**

| Condition | State |
|---|---|
| Hard-feature rails chain (O35), or TB97 shows the mixed stage producing | Open; TB97 decides for the rectangular fixture only |
| Disc corners cannot fall inside a span (O38) | **Decided**; work scheduled as 64B.13 |
| Breakpoints located in one pass (O37) | Open; to be frozen with the switch definition |
| Switch TB pre-registers digest changes and amends the two named tests | Open |

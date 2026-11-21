# D5 mandatory-chain scheduling — Review takeover and definition (RA-218, 2026-11-09)

**Turn:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING` (step 64B, D5). **COMPLETE.** Runtime-free. The Review agent took this turn over from the implementation agent at the user's request. Before the takeover the turn had been open for 13 h 20 m (`Started at` 2026-11-09T02:08:19Z) and had left 11 WIP records without freezing a patch. Product source is unchanged since CB109 `3f64cbf2c79ab580bbf97509142df1d5415c4404`.

## 1. Verdict on the stalled attempt

The attempt found real facts but put D5 in the wrong layer, and every gate it added depended on the one before. It could not close.

**Stands (carried into §2):**
- `ConformitySpanId` names exactly one `NetworkArcId` (`GlobalConformityPlan.h:30–38`), and the baseline requires spans to be bijective with A2b arcs (`GlobalConformityBaseline.cpp:286–289`).
- Rails are not split at feature-curve corners. `emit_run` (`RemeshPipeline.cpp:9710–9757`) takes the whole run, and `SurfaceCellRail` carries no corner set. A rail plus a degree-2 node is therefore not enough to certify a join; corners must be stops.
- A closed rail opens only where a stop cuts it, and an uncut cycle stays separate.
- Vase's rim is one 142-edge boundary loop whose largest turn is 29.8454°, below the 45° corner threshold, so the rim has no corner stops.
- RA-214 forbids diagnostic-only slices.

**Withdrawn:**
- **W1, wrong layer and sidecar.** The attempt proposed a separate "certified chain partition" product, copied into `SurfaceCellDiagnosticProductSnapshots` and kept across rejection, alongside unchanged A3 spans. That is the diagnostic sidecar RA-214 forbids, and it duplicates A2b. D5 is a scheduling change: the span over which A3 counts becomes the chain (§2).
- **W2, re-deriving corners.** The attempt required the validator to recompute corners from `V` with the feature builder's floating `acos` predicate. Repeating a floating predicate is not independence. The feature map is upstream authority, like the rails built from it, and its `corners`/`junctions` are read as stops.
- **W3, a production Vase join before any CB.** A Review cannot measure that, and an unwired CB's TB cannot observe it. Vase non-vacuity belongs to the switch TB (§4).
- **W4, a new chain-unit identity type with occurrence-quotient migration.** It is not needed. The partition is a canonical function of A2b plus the stop set, so a chain can keep `ConformitySpanId` keyed by its first arc. The switch Review decides this (§3, 64B.3).
- **W5, A2b-level merging** (considered here, rejected). A2b assumes one source edge per Mandatory arc in about 30 places: `EmbeddedGraphTopology.cpp`, `GlobalTopologyPlan.cpp:2708`, `SurfaceCutGraph.cpp:476`, and `SurfaceCellTracing.cpp:17451` and `:18911`. Merging there would rewrite the region and fragment engine to change a scheduling quantity.
- Process: a DEFN was handed to the implementation agent, against the Review-track rule (RA-172). The next DEFN (64B.3) is assigned to the Review agent.

The 11 WIP records were folded on 2026-11-09; they are listed in the [M6 folded document index](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete).

## 2. D5 contract

1. **Layer.** A3 scheduling over an unchanged A2b. D7 counts and D7b placement already handle multi-piece spans.
2. **Partition** (`derive_mandatory_chain_partition`, CB110). Every A2b arc lies in exactly one chain. Two Mandatory arcs join at node v iff all of these hold:
   - v is not a stop;
   - v's rotation holds exactly two incidences, of two distinct arcs;
   - both arcs are Mandatory;
   - their network edges have the same `HardRailId`.

   Trace and Cut incidences, trace-terminal splits, a rail change or a rail end all leave v unjoined. Join cycles with no stop stay single. A chain is read from its lower-id end arc, and chains are ordered by first arc. Malformed input returns nullopt: an unknown or duplicate arc, edge or rotation node; an incidence at the wrong node; or an incomplete rotation.
3. **Stops.** Singularity-port nodes, plus every network node whose source vertex is a `corners` or `junctions` member of the stage-local `AdaptiveFeatureMap` curves. Deriving the stop set is CB111.
4. **Support** (`derive_mandatory_chain_support`, CB110). The children's exact paths in chain orientation, which must be a canonical continuous path.
5. **Scheduling, at the switch.**
   - The baseline's span set is the partition: Trace and Cut arcs stay single, and each Mandatory chain counts once with positivity per chain.
   - A pass-through node has degree 2, so every child of a chain borders the same regions. Region parity is unchanged in kind.
   - The validator re-derives the partition from the input through the same function (RA-217 rule).
6. **Uncut closed rails** (new debt **O34**). A closed rail with no stop keeps one span per arc. Opening it at a canonical node would need a count of at least 3 to avoid a degenerate loop. That is a new constraint, so it is deferred.

## 3. Sequence (each turn narrow and independently testable)

| Step | Turn | Owner |
|---|---|---|
| 64B | `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING`: COMPLETE (this record) | Review |
| 64B.1 | `M6-CP3-CB110-P13-A3-MANDATORY-CHAIN-PARTITION`: exact patch §5, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-MANDATORY-CHAIN-PARTITION-STOP`; infrastructure → `M6-CP3-CB110A-P13-A3-MANDATORY-CHAIN-PARTITION-ORCH` | implementation agent |
| 64B.2 | `M6-CP3-TB93-P13-A3-MANDATORY-CHAIN-PARTITION-FULL-GATE-EXEC` (§6) | implementation agent |
| 64B.3 | `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH`: freezes CB111 (unwired stop-set derivation), CB112 (curved-disk resolves an arc to its span and piece offset; behaviour-neutral while every span is one arc) and CB113 (baseline span set = partition, validator, pipeline wiring, DESIGN §7.4 effective), each with a full-gate TB. Exit: those frozen patches, or `M6-CP3-PLAN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH-STOP` | **Review agent** (runs in parallel with 64B.1–64B.2; needs only CB110's text) |
| 64C → 65D → 66+ | D4 uniform → D4 annulus → D9c → A2b trace → A4 disc → D8 → per-disc corners (D6 user decision) | Review DEFN, then CB, then TB each |

Deviation from RA-216's "freeze the whole chain in one Review": CB112 depends on the curved-disk walk (`SurfaceCellTracing.cpp:17380–17700`). That is a design task in its own right, and freezing it here would repeat this turn's stall. 64B.3 is therefore scheduled to run alongside the implementation agent's CB110 and TB93, so no one waits on a Review.

## 4. Predictions registered for the switch TB (not TB93)

Vase: 142 rim edges plus 3 trace terminals give 145 Mandatory arcs. The stops are the 3 terminal nodes, which have degree 3; there are no rim corners or ports. **Prediction:** 3 rim chains replace 145 Mandatory spans, and the rim count falls toward the D7 metric target (about 62). If no join occurs, the switch TB reports `NoCertifiedProductionJoin` and routes to Review. That outcome is not a pass.

## 5. CB110, frozen

- [Patch](Architecture_M6_CP3_CB110_P13_A3_Mandatory_Chain_Partition_Exact.diff):
  - SHA-256 `ff3fdf5f1a34ea942075f681a760cbec423df4a4800c2024992ceb77a05054f0`, 522 lines, 6 single-space context lines.
  - Numstat: `112 0` `src/geometry/GlobalConformityBaselineSupport.cpp`; `25 0` `src/geometry/GlobalConformityBaselineSupport.h`; `333 1` `tests/GlobalConformityBaselineTests.cpp`.
  - Base is product source CB109 `3f64cbf2…`; `git apply --check` is clean at HEAD.
- **Adds** `BaselineMandatoryChain`, `derive_mandatory_chain_partition` and `derive_mandatory_chain_support` in the baseline detail namespace. Nothing calls them, so production is unchanged. `TopologyFixture` gains `mandatoryEdges`.
- **Tests (GUARD 919–923):**

  | Test | Asserts |
  |---|---|
  | `D5ChainsJoinOnlyThroughUnprotectedSameRailNodes` | `0F,1R,2F\|3F\|4F\|5F` with stop 3; `0F,1R,2F,3F\|4F\|5F` with no stop; all single with stops {1,2,3}; reversed rows give the same result; a trace-terminal split stays `0F\|1F\|2F` |
  | `D5ChainsOpenAClosedRailOnlyAtAStop` | Uncut triangle stays single; stop 0 → `0F,1F,2F`; stop 1 → `0R,2R,1R`; stops {0,1} → `0F\|1F,2F`; parallel pair; a loop arc stays single |
  | `D5ChainPartitionRejectsInconsistentGraphs` | 9 malformed inputs → nullopt; an empty graph gives an empty partition |
  | `D5ChainSupportIsTheOrientedPathAndIsCountedOnce` | The chain support equals the three oriented unit pieces. D7 count at h = 2: the chain is 1 and each arc alone is 1 (three edges become one). 4 malformed chains are rejected |
  | `D5ChainPartitionCoversARealA2bPlanOnce` | On a real square A2b plan, per-edge rails all stay single. On one rail, with and without a stop, every arc is covered once, chains are continuous, multi-arc chains are Mandatory only and have a valid support. A `D5_CHAIN_RECEIPT case=square` line reports the counts; it is evidence, not an assertion |

- **Checks:** `-fsyntax-only` is clean on Support.cpp, Baseline.cpp, Validator.cpp and the test TU (the only warnings are the 5 pre-existing `PCFaceTangentBundle.h` ones). Every expected shape was confirmed by an independent model (`scratchpad/model218`). Metric values: an arc alone is 1/2 and the chain is 3/2, and with halves rounding down both counts are 1.
- **Non-vacuity:** never joining fails tests 919, 920 and 922. Ignoring stops, rails or degree fails 919 and 920. Not validating rotations fails 921. A wrong rotation convention on real data fails 923.

## 6. TB93, frozen

- [Manifest](gates/Architecture_M6_TB93_P13_A3_Mandatory_Chain_Partition_Full_Gate_Case_Manifest.tsv): 923 rows, SHA-256 `a8c4a59920ee22c8f3260de2d5b467f9ce3aa4a72526d1dcd593a3b063e9095a`. It is TB92's 918 rows byte for byte, plus GUARD 919–923.
  - `SELF_CHECK_PASS cases=923 deferred=81`; membership 1004; ledger v5 `fd433f54…`; harness `78b8002c…`.

| Outcome | Route |
|---|---|
| 923/923 PASS; all 7 platform-digest and 7 a3-coverage lines byte-identical to TB92; census Cylinder PASS, BunnyRandom and Vase registered RED unchanged; the 5 `D5_CHAIN_RECEIPT` lines recorded | MATCH → next CB from 64B.3, or wait for it |
| Any failure in 919–923, any regression in 1–918, or any digest change | MISMATCH → `M6-CP3-TB93-P13-A3-MANDATORY-CHAIN-PARTITION-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB93A-P13-A3-MANDATORY-CHAIN-PARTITION-ORCH` |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB93's rows 1–918 are byte-identical to TB92's manifest (`cmp`). Selector497/CP3 is unpromoted, so there is no accepted-selector change |
| Decisive claims re-derived | Read the rail builder, the feature-curve corner/junction producer, A2b `build_arcs`, the rotation construction (Forward at `firstNode`), the baseline span bijection, the curved-disk span consumer, and every Mandatory single-edge site |
| Non-vacuity | §5 |
| Obligations carried | 64B.1–64B.3; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; new O34; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB92 918/918, membership 999; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository; syntax checks and a model only |

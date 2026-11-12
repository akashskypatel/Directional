# RA-219 — D5 span switch: Review takeover of step 64B.3

**Turn:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH` (64B.3). **Disposition: COMPLETE.** Two exact patches and two full-gate manifests are frozen (CB111 → TB94, CB112 → TB95). The switch itself (CB113) moves to a Review-owned definition, `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION`, which runs while the implementation agent executes those four turns. Runtime-free: syntax checks and one model only; no product or test source changed in the repository.

## 1. Verdict on the stalled attempt

The implementation agent entered this turn after TB93, resumed it five times, wrote four working documents and froze no patch. Those documents are superseded (banner added, kept as provenance):

- [Working review](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Span_Switch_Working_Review_20261109.md)
- [CB111 candidate](Architecture_M6_CP3_DEFN_P13_A3_Span_Switch_CB111_Candidate_20261109.md)
- [Interval identity source review](Architecture_M6_CP3_DEFN_P13_A3_Span_Switch_Interval_Identity_Source_Review_20261109.md)
- [Logical sides candidate](Architecture_M6_CP3_DEFN_P13_A3_Span_Switch_Logical_Sides_Candidate_20261109.md)

Two causes. The turn should not have reached the implementation agent at all (RA-218 marked it Review-owned). And RA-218 asked one turn to freeze three patches, the third of which rewrites consumers that depend on an interface the second introduces. This record fixes the second cause by freezing what is decided and independent, and by naming the rest as its own turn with the rules already written (§4).

## 2. Decisions

These amend RA-218 §2 where stated. DESIGN §7.4 carries them.

1. **The baseline input carries chain membership.** `GlobalConformityBaselineInput::chains` lists, for each multi-arc span, its A2b arcs in order with the identifying arc first. The baseline and its validator check structure only: the spans and chains cover every A2b arc exactly once; each chain is led by a span's identifying arc; each chain is a head-to-tail path of two or more Mandatory arcs through nodes with exactly two incidences. Rail equality, stops and maximality are the pipeline factory's contract. *Amends RA-218*, which had the validator re-derive the partition; that would have pulled rails, ports and feature curves into the baseline.
2. **A chain's side is read once.** A chain crosses only two-incidence nodes, so every region walk that holds one of its arcs holds all of them consecutively. The baseline emits one incidence per walk occurrence of the identifying arc and skips the other arcs.
3. **Incidence orientation is composed.** It is Forward when the walk traverses the identifying arc in its chain orientation. For a per-arc span this is the walk orientation, as before.
4. **Consumers resolve an arc through the plan.** `find_arc_binding(arc)` returns the span, the arc's ordinal and orientation in the chain, and `firstSupportPiece` (the number of source-path pieces of the chain's earlier arcs).
5. **Digest.** The normalized-problem digest appends only bindings with a non-zero chain ordinal, so every per-arc problem keeps its digest.
6. **Stage 1 chains source-boundary rails only.** Both end nodes of every HardFeature edge are stops, so hard-feature rails stay per-arc. A4 requires a one-piece arc (`generator_route_for_span`) and groups rail pairs per carrier step (`HardRailPairKey`); chaining those rails waits for an A4 route decision (new debt **O35**).
7. **Uncut closed rails stay per-arc** (O34, unchanged). The baseline does not test whether a chain closes; the factory never emits one.

## 3. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64B.3 | `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH`: COMPLETE (this record) | Review |
| 64B.4 | `M6-CP3-CB111-P13-A3-CHAIN-STOP-NODES`: exact patch §5, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-CHAIN-STOP-NODES-STOP`; infrastructure → `M6-CP3-CB111A-P13-A3-CHAIN-STOP-NODES-ORCH` | implementation agent |
| 64B.5 | `M6-CP3-TB94-P13-A3-CHAIN-STOP-NODES-FULL-GATE-EXEC` (§6) | implementation agent |
| 64B.6 | `M6-CP3-CB112-P13-A3-CHAIN-ARC-BINDINGS`: exact patch §7 on top of CB111, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-CHAIN-ARC-BINDINGS-STOP`; infrastructure → `M6-CP3-CB112A-P13-A3-CHAIN-ARC-BINDINGS-ORCH` | implementation agent |
| 64B.7 | `M6-CP3-TB95-P13-A3-CHAIN-ARC-BINDINGS-FULL-GATE-EXEC` (§8) | implementation agent |
| 64B.8 | `M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION` (§4): freezes CB113 and TB96 | **Review agent only**, in parallel with 64B.4–64B.7 |
| 64C → 65D → 66+ | unchanged from RA-218 §3 | |

A green TB94 goes straight to CB112; no Review turn sits between them. After a green TB95 the implementation agent applies CB113 if 64B.8 has frozen it, and otherwise stops with `Successor: M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION`. It must not start that definition.

## 4. The follow-on definition (64B.8, Review-owned)

It freezes one exact patch, CB113, and its TB96. The rules are decided here; what remains is writing the patch over the sites below and pre-registering which tokens may change.

- **Factory** (`RemeshPipeline.cpp`, `make_global_conformity_baseline_input`, about `:1005`, call `:13016`): compute stops with `derive_mandatory_chain_stop_nodes`, partition with `derive_mandatory_chain_partition`, give each multi-arc chain one span whose support is `derive_mandatory_chain_support`, and fill `chains`.
- **Bounded-disk walk** (`SurfaceCellTracing.cpp`, about `:17403–17722`): resolve each side arc through `find_arc_binding`; place each breakpoint of the span on the piece `firstSupportPiece + local piece` of its arc; emit a unit interval when a breakpoint follows the previous ordinal of the same span; require the cursor to reach the span's last breakpoint when the span changes or the side ends, and otherwise reject with the existing `InvalidFrontBoundaryAuthority`. For single-arc spans this is today's behaviour.
- **Cut-domain and preflight sites** (`:15545–15720`, `:16060`, `:17011`, `:18431–18453`): replace `ConformitySpanId::from_network_arc(arc)` lookups with the binding's span. `:16060`, `:17011` and `:18431–18453` are not yet read; read them first.
- **A4 sites** (`:18849–18990`, `:19070–19110`): unchanged in stage 1, because no hard-feature rail is chained.
- **Tests to amend in the same patch:** `tests/FieldAlignedCurveNetworkTests.cpp:17212–17235` asserts one schedule entry per arc; the per-arc equalities become `arcs().size() == schedule().size() + chained arcs`. Grep the accepted selectors for other per-arc assertions before freezing.
- **Predictions carried from RA-218 §4:** on Vase, 3 rim chains replace 145 Mandatory spans and the rim count falls toward the D7 target. A switch TB with no join reports `NoCertifiedProductionJoin` and routes to Review. The bounded-disk producer rejects when opposite sides disagree on interval count, which is the likely cause of today's Vase rejection; TB96 must report that count before and after.
- **Exit:** the frozen CB113 and TB96, or `M6-CP3-PLAN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION-STOP` with the blocking site named.

## 5. CB111, frozen

- [Patch](Architecture_M6_CP3_CB111_P13_A3_Chain_Stop_Nodes_Exact.diff): SHA-256 `f71c1abad17ba1539d8fe869e86cb4e25d05fb31d7c96d6c2b4c2b284aef03f4`, 177 lines, 3 files, 140 insertions. Base is product source CB110 `3f81e804a…`; `git apply --check` is clean at HEAD.
- **Adds** `derive_mandatory_chain_stop_nodes(nodes, ports, mandatoryEdges, curves)` in the baseline detail namespace. A stop is a singularity-port node, a node on a corner or junction vertex of an upstream feature curve, or either end of a HardFeature edge. Nothing calls it, so production is unchanged.
- **Tests (GUARD 924–925):**

  | Test | Asserts |
  |---|---|
  | `D5StopNodesReadPortsFeatureCurvesAndHardFeatureEdges` | No sources → empty; ports → `4`; hard-feature edges → `2,3`; curves → `1,5`; all → `1,2,3,4,5`; reversed rows give the same set. Node k sits on vertex 7 − k, so reading a node index as a vertex fails |
  | `D5StopNodesKeepHardFeatureRailsPerArc` | Partition `0F,1F,2F\|3F,4F` with no stops; `0F,1F,2F\|3F\|4F` at stage 1; a corner at vertex 1 gives `0F\|1F,2F\|3F\|4F`; a port at node 2 gives `0F,1F\|2F\|3F\|4F` |

- **Non-vacuity:** dropping any one source fails 924; not stopping hard-feature ends fails 925.

## 6. TB94, frozen

- [Manifest](gates/Architecture_M6_TB94_P13_A3_Chain_Stop_Nodes_Full_Gate_Case_Manifest.tsv): 925 rows, SHA-256 `ebaf1972c824b0b6256e77c15c309d6a0595f46b26d365368eec8145333bfce9`. It is TB93's 923 rows byte for byte, plus GUARD 924–925. `SELF_CHECK_PASS cases=925 deferred=81`; membership 1006; ledger v5 and harness `78b8002c…` unchanged.

| Outcome | Route |
|---|---|
| 925/925 PASS; all 7 platform-digest and 7 a3-coverage lines byte-identical to TB93; census Cylinder PASS, BunnyRandom and Vase registered RED unchanged; the 2 `D5_STOP_RECEIPT` lines recorded | MATCH → `M6-CP3-CB112-P13-A3-CHAIN-ARC-BINDINGS` |
| Any failure in 924–925, any regression in 1–923, or any digest change | MISMATCH → `M6-CP3-TB94-P13-A3-CHAIN-STOP-NODES-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB94A-P13-A3-CHAIN-STOP-NODES-ORCH` |

## 7. CB112, frozen

- [Patch](Architecture_M6_CP3_CB112_P13_A3_Chain_Arc_Bindings_Exact.diff): SHA-256 `ae7da62fb0ca96bf51da6baed2a49084b992c4acd00baeecb175bbfe14d86ae9`, 703 lines, 6 files, 511 insertions and 17 deletions. It applies on top of CB111 (checked in a scratch worktree).
- **Adds** `BaselineConformityArcBinding`, the input field `chains`, the plan accessor `find_arc_binding`, and the shared `derive_span_arc_bindings`, which the producer and the validator both call. The producer and validator read incidences through the bindings and hash the chained bindings (§2.2–2.5).
- **Neutral for production.** The pipeline factory passes no chains. For such an input the first error and its order are the same, the binding derivation cannot fail once the earlier checks pass, and the incidences, region ends and digest are unchanged.
- **Tests (GUARD 926–929):**

  | Test | Asserts |
  |---|---|
  | `D5ArcBindingsFollowChainsAndKeepOtherSpansPerArc` | On a hand-built five-arc path: per-arc identity; a three-arc chain with a backwards arc and a two-piece head (`1=0.1R+2,2=0.2F+3`); the same chain led from the other end; two chains; span and chain order do not matter |
  | `D5ArcBindingsRejectWhatIsNotAPartitionIntoChains` | 15 rejections: one-arc chain, unknown arc, trace arc, gap, wrong direction, arc in two chains, span on a chained arc, chain led by its second arc, chain with no span, uncovered arc, unknown span arc, three duplicate-span cases, and a chain through a three-incidence node. A chain beside that node is accepted |
  | `D5ChainedSpansScheduleOnceAndReadTheirSideAtTheIdentifyingArc` | On the real square A2b plan: per-arc counts `1,1,1,1`; two arcs chained give three spans, counts `1,1,2` and one flip (the triangle problem); the same arcs led from the other end are read with the opposite orientation; two chains give counts `1,1` and no flip; permuting spans and chains keeps the semantic digest; the four problems have four digests; each candidate validates against its own input and is rejected against the other three (12 rejections) |
  | `D5BaselineRejectsChainsThatDoNotPartitionTheArcs` | `InvalidTopologyBinding` with the count message when a chained arc keeps its span, and with the partition message for non-adjacent arcs, arcs taken against their direction, a chain not led by its span, and a one-arc chain |

- **Checks:** `-fsyntax-only` returns 0 on `GlobalConformityBaselineSupport.cpp`, `GlobalConformityBaseline.cpp`, `GlobalConformityBaselineValidator.cpp` and the test file. Every hand-built expected shape, and the count of rejections, was reproduced by an independent model written from §2.1 (`scratchpad/rev219/model_bindings.py`).
- **Grounding of the real-plan values.** TB93's receipt `D5_CHAIN_RECEIPT case=square arcs=4 ownRails=4 oneRail=4 oneRailStop=1` shows that the square's four arcs are Mandatory and form one cycle through two-incidence nodes. The unit support at h = 1 has preferred count 1 (accepted triangle test: counts `1,1,2`, one flip). The exterior demand is the parity of the region demands, so an even region needs no flip.
- **Non-vacuity:** ignoring chains fails 926 and 928; not checking adjacency, degree, kind or leadership fails 927 and 929; omitting the duplicate-span check fails 927 (`{0,0,4}` would hide a chain with no span); reading a side at every chain arc fails 928 (incidence count); dropping the composed orientation fails 928.
- **Registered gap.** No fixture isolates the digest tail: on the square, two inputs with the same spans but different chains also differ in an incidence orientation. The tail is covered only through the four distinct digests. The bindings are not a tamperable candidate field; they are a function of the topology and the input.

## 8. TB95, frozen

- [Manifest](gates/Architecture_M6_TB95_P13_A3_Chain_Arc_Bindings_Full_Gate_Case_Manifest.tsv): 929 rows, SHA-256 `bcf9420d6ae0caee0d66100bb777946bd45c85dad609a7f9b648c67ea7345229`. It is TB94's 925 rows byte for byte, plus GUARD 926–929. `SELF_CHECK_PASS cases=929 deferred=81`; membership 1010.

| Outcome | Route |
|---|---|
| 929/929 PASS; all 7 platform-digest and 7 a3-coverage lines byte-identical to TB93; census unchanged; the 4 `D5_BINDING_RECEIPT` lines recorded | MATCH → CB113 if 64B.8 has frozen it; otherwise stop with `Successor: M6-CP3-DEFN-P13-A3-BOUNDARY-CHAIN-CONSUMPTION` |
| Any failure in 926–929, any regression in 1–925, or any digest change | MISMATCH → `M6-CP3-TB95-P13-A3-CHAIN-ARC-BINDINGS-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB95A-P13-A3-CHAIN-ARC-BINDINGS-ORCH` |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB94's rows 1–923 are TB93's manifest byte for byte, and TB95's rows 1–925 are TB94's. Selector497/CP3 is unpromoted, so there is no accepted-selector change |
| Decisive claims re-derived | Read the baseline normalization and validator rebuild, the A2b walk validation (`oriented_arc_nodes`, single boundary walk), the accepted baseline tests and the TB93 report |
| Non-vacuity | §5, §7 |
| Obligations carried | 64B.4–64B.8; D4 64C/64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34; new O35 (chain hard-feature rails after an A4 route decision); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB93 923/923, membership 1004; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |

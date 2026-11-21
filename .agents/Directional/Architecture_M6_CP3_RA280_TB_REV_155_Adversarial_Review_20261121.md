# RA-280 — adversarial review of TB-REV-155 (2026-11-21 UTC)

## Situation — STOP upheld; cause decided; CB-172A withdrawn and replaced

**TB-REV-155's evidence verdict and its STOP are upheld. Its causal finding ("second incidence and owning stage unknown") and its successor are not.** The second incidence is decidable from source and the immutable TB154/TB155 fields: a saturated **Cut** arc on source edge 0–69. Trace 14 slides along that edge. Its root cause is cut-candidate representability, not ray ordering. The CB-171 guard stopped an invalid embedding from being certified. CB-172A is a compile-only turn whose deciding step needs runtime evidence, so it is not executable. It is withdrawn and replaced by an exact, single-concern diff, CB-172B. RA-278's C3 claim that the sphere could not reach the guard was wrong; it is corrected below.

## Background — evidence used

- Source at review: HEAD after `905a33c81`. `GlobalTopologyPlan.h`, `EmbeddedGraphTopology.cpp`, `GlobalTopologyPlan.cpp` and `tests/FieldAlignedCurveNetworkTests.cpp` hash to the CB-170/CB-171 frozen postimages (`277cde20…`, `f0599d1a…`, `e1e18654…`, `c8e32186…`), so the CB turns landed exactly as frozen.
- Immutable artifacts were re-downloaded and re-hashed in isolated directories: TB155 gate `14704220616`, ZIP `e4e08a88…46358`; TB154 gate `14696380156`, ZIP `ce172d89…648c0`. Both match.
- TB155 row 669 line 1179: `surfaceCutGraphError=CellularityNotEstablished; originatingTopologyError=RotationSystemInconsistent; originatingRotationSystemReason=RotationTraceRaysAlongSharedEdge; trace=14; traceEventClaimedSourceEdge=0-69`.
- TB154 row 644: `surfaceCutGraphError=CutSearchExhaustedBeforeCellularity; errorSourceFace=0-1-2`. No log prints a certification attempt index or a cut-edge count.
- Runtime-free review: static source reading, artifact reading and `-fsyntax-only` / `git apply --check` only.

## A1 — TB-REV-155: what holds

- ZIP and internal checksums; 970/971; changed rows exactly {644, 645, 669, 686, 698, 858, 966}; all 960 non-A rows MATCH TB154; census 3/3 MATCH TB151; manifest prefix intact; CP2 491/491. Upheld.
- Keep the guard; do not invent an order; do not weaken row 858. Upheld.
- RA-277-NV1: CB-169S replaced row 971's print-only counters with a predeclared ten-slide table (`tests/FieldAlignedCurveNetworkTests.cpp:17851`) and exact assertions (`:18055–18061`). The review's statement that the test asserts the count is correct. The limit it states also holds: row 971 observes attempt 0, which has no cuts.
- RA-275 S4a is carried, with no positive witness. Upheld.

## A2 — TB-REV-155: defects

**D1 — The second incidence is decidable; it is a saturated Cut arc on 0–69.**
- At a vertex locus, only two kinds of incidence can take primary `2·slot(0–69)`: a Mandatory or Cut arc on that edge (`EmbeddedGraphTopology.cpp:2855`), or an along-edge trace ray on it (`:2903`).
- The sphere has no mandatory rails (`mandatoryRailCount=0`).
- Row 971 asserts that no two along-edge trace rays coincide. Cut nodes split trace arcs only at cut nodes, never at vertex 0, so no new trace ray appears there.
- Attempt 0 has no cuts (it is row 971's configuration), so the cut must enter at a later attempt.
- All 30 proposal components are discs (`producerInitialNonDiscComponents=0`), so tree-cotree proposals add nothing. Saturation then runs with `nonDiscFaces` empty and adds every non-mandatory source edge (`SurfaceCutGraph.cpp:1078–1088`), including all ten slid carriers: 6–8, 8–9, 16–21, 20–21, 32–34, 33–34, 40–45, 45–46, 49–62 and 0–69.
- TB154's terminal fields confirm that this path was reached: exhaustion at `blockedLocus = faces.begin()` = 0-1-2.

**D2 — The root cause is representability, not ordering.**
- `build_cut_node_bindings` puts cut nodes on a cut edge only at the next segment's entry point on its incoming carrier (`EmbeddedGraphTopology.cpp:465–500`). The slide start `edgeTransitEntry` (P) is never a node, and `trace_crossed_source_edges` never reads it.
- A cut on a slid carrier is therefore one Cut arc through P with no node there, and it overlaps the trace's slide piece on [P, vertex]. That embedding is invalid under every possible order at the vertex: the guard caught the vertex end, and nothing detects the P end.
- Before CB-169S, chord paths ran through the face and hid the overlap. TB154's exhaustion was therefore computed on a candidate whose true geometry overlapped ten traces.
- Saturation's own comment promises "every remaining source edge that is not already a graph arc". With piece paths, a slid carrier is already partly a graph arc.

**D3 — CB-172A is not executable as frozen.**
- It is a compile-only turn whose step 3 ("if both incidences have a proved single semantic owner …") depends on provenance that only a runtime run can show.
- Step 2 asks for a small reproduction, but only the prescribed sphere commits slides (23 gate rows), and a hand-built network is impossible (RA-248).
- It has no exact diff and no changed-row allowance (RA-261).
- It is withdrawn. The provenance capture it asked for is unnecessary given D1.

**Observation O1 — row 858's oracle is weak.** Its `sourceFace` is the placeholder `faces.begin()` used when no component is non-disc (`SurfaceCutGraph.cpp:1086`), not a located defect. It is accepted and stays unchanged; the existing held row-858 face-witness DEFN owns it.

## A3 — Correction of RA-278 (own error)

RA-278 C3 said "the sphere has none (`coincidentWithEdgeArc=0`)", called the C3 paths "unwitnessed", and froze the TB-EXEC-155 criterion that no log names `RotationTraceRaysAlongSharedEdge`. That was wrong: row 971 measures the network before any cut, and the saturation attempt puts Cut arcs on all ten slid carriers. The guard itself was right; it turned a silent invalid certification into a typed stop. RA-278's prediction was wrong because it did not list the stages that add incidences of the guarded kind. TB155's RED on rows 644, 669 and 698 is a falsified RA-278 prediction, not a defect in TB-EXEC-155.

## Ruling — slide carriers are not admissible cuts (R2)

A source edge that carries a trace slide is not an admissible cut edge. A slide is a segment with `edgeTransitEntry`, and its carrier is the segment's `outgoingCarrier`. The cut search classifies each such edge as `SurfaceCutCandidateClass::TraceSlideCarrier` and skips it at both add sites: the tree-cotree proposals and saturation.

- **Soundness:** excluding an edge never creates an invalid embedding.
- **Completeness:** the cells on either side of the uncovered part [far vertex, P] merge along one boundary arc. For distinct cells the merge is still a disc. The sphere search is non-cellular in any case, because of χ+4.
- **Guard kept:** a slide along a mandatory rail still fails closed. No fixture witnesses that case.

Rejected alternatives:
- Delete the guard or add a tie-break: this hides an invalid embedding.
- Treat rotation failures as candidate rejections: this changes the fatal meaning of every rotation reason.
- R1, a canonical sub-arc (a node at P, the covered cut sub-arc omitted, and an along-locus-edge order): it needs three new rules that no fixture witnesses. Define it only when a fixture needs a partial cut.

## Frozen CB-172B — exact diff

[Architecture_M6_CP3_CB172B_P13_Slide_Carrier_Cut_Admissibility_Exact.diff](Architecture_M6_CP3_CB172B_P13_Slide_Carrier_Cut_Admissibility_Exact.diff), SHA-256 `7d0e0f0a7765cf23ec22aa35894c54433caccf0bb31c7b7c72657c7d71b395ef`.

| File | numstat | Preimage SHA-256 (`905a33c81`) | Postimage SHA-256 |
|---|---|---|---|
| `include/directional/geometry/SurfaceCutGraph.h` | 4/0 | `b52ecf21e24afaff721e0aa0112faa14594480a7095f3917d29ed3a05d38a28b` | `7362e5acf5a818acd41f306b936cf7c02d16a6bc6b119ff8d8859ecbad68e1b4` |
| `src/geometry/SurfaceCutGraph.cpp` | 28/7 | `8533fa4e99c4e7f64237b90338829629d1a5939a680788ce8f46d2c16fb0a7c4` | `a57c24772dba243f7e5f2cb6f86be9206fbfa66ff66aea78f024a64450baf1eb` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | 65/0 | `c8e32186369854791cf4c42e39e50892fdf1cb3ab1997c55eaf0ce264bd7ea02` | `4accff96f83183f5d0bf1ba745a65c61063d0470745c701fe8ea59befbc11af0` |

- **Content:**
  - `trace_slide_carrier_source_edges(network)` returns the `outgoingCarrier` of every segment with `edgeTransitEntry` or `edgeTransitExit`. This is the same slide predicate row 971 uses.
  - `classify_cut_candidates` gains a `TraceSlideCarrier` class. Precedence: mandatory, then slide carrier, then trace crossing.
  - `canonical_candidate` skips slide carriers at the tree-cotree add site and in saturation.
  - The saturation comment is corrected.
  - The name table gains the new case.
- **New test:** `SurfaceCutGraph.PrescribedSphereSlideCarriersAreNeverCutCandidates`, which becomes gate row 972.
  - It builds the expected carrier set independently, from the sphere's published trace records, excluding mandatory edges, and requires that set to be non-empty.
  - It runs `SurfaceCutGraph::make` and requires that a failure does not originate in `RotationTraceRaysAlongSharedEdge`.
  - It requires exactly the expected edges to be classified `TraceSlideCarrier`, with none selected.
  - It prints `SlideCarrierCutReceipt carriers= classified= selected= outcome=`.
  - It fails if the skip is removed: saturation selects a carrier and the guard fires. It also fails if the classification is removed.
- **Neutral by construction:** for a network with no slide segment, `slideCarriers` is empty, every changed condition is false and the classification is unchanged. TB155's census matched TB151 with piece paths active, so no census plan carries a slide piece.
- **Checks (runtime-free):** `git apply --check` passes on `905a33c81`. `-fsyntax-only` with identical flags on `SurfaceCutGraph.cpp` and `FieldAlignedCurveNetworkTests.cpp`, GoogleTest headers included, gives 0 errors before and after, with identical warning sets. `surface_cut_candidate_class_name` is the only switch over the enum.
- **Unwitnessed (stated):**
  - The tree-cotree skip: the sphere has no non-disc component.
  - A slide along a mandatory rail: the guard still fails closed.
  - The R2 completeness argument: no fixture needs a partial cut.

## Frozen TB-EXEC-156 criteria

- **Package:** the CB-172B compile artifact, run without a rebuild.
- **Manifest:** [TB156](gates/Architecture_M6_TB156_P13_Slide_Carrier_Cut_Admissibility_Full_Gate_Case_Manifest.tsv), SHA-256 `cbba9e76fa436f1e2e6ef34d50bb377b931c19fc4780660412a9f6072128dc6a`, 145,695 bytes, 972 rows. Its first 145,526 bytes are TB154 `0f9c417c…f4e305`, and its added row is 972 `ra280:sphere-slide-carrier-cut-admissibility`. Membership is 972 required + 81 deferred.
- **Baselines:** TB154 gate `14696380156`; TB151 census `14621727104`.
- **STOP unless all of the following hold:**
  1. 972/972 PASS, including row 858.
  2. Every row from 1 to 971 outside allowance **A = {644, 645, 648, 669, 686, 698, 858, 963, 966, 968, 971}** MATCHES TB154 under N1–N3. A DIFF in an A row is a finding for TB-REV-156, not a STOP.
  3. Row 972's `SlideCarrierCutReceipt` line is published verbatim.
  4. The census is 3/3 MATCH TB151 under N1–N4, including every `platform-digest` field.
  5. CP2 is 491/491.
  6. No raw log names `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge` or `FirstPieceNotLeavingLocusIntoFace`.
- **Predictions (falsifiable, but not STOP rules):**
  - Rows 644, 645, 669, 686, 698 and 858 MATCH TB154: the sphere's terminal error returns to `CutSearchExhaustedBeforeCellularity` with `errorSourceFace=0-1-2`.
  - Row 966 differs from TB154 only by `SourcePieceCountOracle traceArcs=3 segments=9 transitSegments=0`.
  - Rows 648, 963, 968 and 971 MATCH.
  - Row 972 prints `carriers=10 classified=10 selected=0 outcome=CutSearchExhaustedBeforeCellularity`.
- **Falsifiers for R2:**
  - Row 972 is RED, or the guard is named anywhere.
  - The sphere stops at a different fatal error while row 858 is RED. That would mean a second invalid incidence after the carrier exclusion; return to Review.

## Turn sequence

| Step | Turn | Criterion |
|---|---|---|
| NEXT | `M6-CP3-CB-172B-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY` | Apply the exact diff above. Dispatcher compile, eight GMP/GMPXX targets, `runtimeExecution=false`. If the diff does not apply or the compile fails: BLOCKED, return to Review. |
| then | `M6-CP3-TB-EXEC-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` | The frozen criteria above. |
| then | `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` | Attribute every A-row DIFF; read row 686 against TB154's real-piece oracle; RA-275 S4a stays carried; freeze the stop-switch helper CB only if TB-EXEC-156 passes. |
| prospective | stop-switch helper CB → stop-switch CB → TB → slide-plan conformity → O48 carrier turns | χ+4, the four unowned slide contacts, is the next real blocker. O49 held. |
| withdrawn | `M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE` | D3. The plan file is kept, with a withdrawal banner. |

## Lessons

- A receipt measured before a stage cannot clear a guard that the stage feeds. List every stage that adds incidences of the guarded kind before predicting that the guard never fires.
- When a guard names only one side of a conflict, decide the other side by elimination over the code paths that can produce the key, before adding diagnostics.
- A compile-only turn cannot own a decision that needs runtime evidence.
- When a representation becomes exact, re-check every candidate generator for configurations the old approximation hid.

## Review closeout

| Duty | Answer |
|---|---|
| Decisive claims independently re-derived | Both gate ZIPs re-hashed; row 669/644 fields read from the raw logs; the second incidence proved by elimination (`EmbeddedGraphTopology.cpp:2855/2903/465–500`, `SurfaceCutGraph.cpp:1078–1088`); CB-170/CB-171 postimages re-hashed. |
| Non-vacuity checked | Row 972 fails if the skip or the classification is removed; row 858 stays exact. |
| Prior obligations | RA-279-C1/C2 attributed to CB-172B; RA-278 C3 prediction corrected; RA-275 S4a and row-858 face-witness DEFN carried; RA-277-NV1 discharged by CB-169S (row 971 exact table). |
| Stable accounting | 66/17/49; debt 1; deferred 81; CP2 491/491; no promotion. |
| Turn boundary | Runtime-free: source reading, artifact reading, `git apply --check`, `-fsyntax-only`. No product source, test or selector changed; the manifest is a new frozen file. |
| Successor frozen | CB-172B exact diff → TB-EXEC-156 → TB-REV-156. |
| `STATUS` | IN_PROGRESS pushed first (`e19ee28ce`); COMPLETE is the last write. |

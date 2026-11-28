# TB-REV-157 V3 reaching-test feasibility — 2026-11-21 UTC

## Situation

The TB157 artifact review independently upheld 975/975 PASS with the 972/972 prior gate retained under N1–N3 and census 3/3 under N1–N4. This does not prove a production node with two trace rays along a slide edge. The candidate stop helper remains unapplied.

## Background — source-level proof

1. `src/geometry/SurfaceCellTracing.cpp:6155+`: `FieldAlignedCurveNetwork::make_from_candidate` validates the supplied candidate, but then calls `canonical_field_aligned_candidate` and publishes that new canonical product. Mutating a test candidate cannot insert a retained slide-contact node.
2. `src/geometry/EmbeddedGraphTopology.cpp:2044+`: `build_node_loci` derives loci from the network's nodes/events and cut-node bindings. A standalone stop record or helper return value does not create a locus or an event.
3. `src/geometry/EmbeddedGraphTopology.cpp:2756+`: `build_rotation_system` consumes the immutable network, the bound nodes, and its arc collection. An edge-locus node with two along-edge trace rays needs two split trace arcs plus at least one valid face ray. At exactly two counted edge rays, valence must be 3 or 4 (`:3064+`).
4. `src/geometry/EmbeddedGraphTopology.cpp:3050+`: the composition permits `(arcEdgeRays, traceAlongEdgeRays)=(0,2)`, but that control branch is not reached by any reported TB157 gate fixture. Its pure helper tests do not constitute a production reach witness.
5. The prospective `later_entry_stop_on_committed_slide` helper only computes terminal-contact metadata and a wall split parameter; it does not publish an event or bind arcs. The independent test derives opposite edge pieces and slots but never calls `build_rotation_system` on a contact node.

**Conclusion:** The inherited V3 instruction combines an *unwired helper CB* with a test that requires the *later producer wiring CB*. Existing tested production interfaces cannot inject the missing node for an honest isolated helper test. A fake graph bypass, synthetic `const_cast`, or pure arithmetic-only call would not prove V3.

## Assessment — two separate, retained obligations

- **V3a (stop-helper mechanism):** define the later-arriving pending entry into the strict interior of an earlier committed slide; preserve exact carrier locus, struck trace and segment, correct barycentric point and wall-side split. Reject absent slide, wrong priority, unrelated component/region and invalid endpoint. The exact three-file unapplied candidate is SHA-256 `684d53d681f1e1ba82730e52239042a6947d6f5a6f035b70d0f252c41807d238`, 13,342 bytes, [Drive transport](https://drive.google.com/file/d/1ZssZep4xVhe6l3AXEHyaEIaiU57Q2nwJ/view). Its changes are only prospective; compilation and runtime of the guarded candidate are not established.
- **V3b (full reaching proof):** once the stop-switch producer publishes a source-edge `FieldAlignedNetworkEvent` and divides the wall at the exact slide contact, use the resulting *canonical* network to call `build_cut_node_bindings`, `build_arcs`, and `build_rotation_system`. Assert the affected node and full arc provenance, counted edge-ray composition `(0,2)`, distinct ordered primaries 0 and 2, one or two non-edge face rays, and the source-edge identity. Change one ray to the same direction and require `RotationTraceRaysAlongSharedEdge`. Remove the contact event and require the reaching test to fail. The test must fail if either arc is absent or if the builder is not called.

## Recommendation

Keep V3b mandatory for the wiring CB and its following artifact-only full gate; neither helper syntax nor pure arithmetic is an acceptance substitute. Do not change the accepted CP2 or frozen CP3 selectors. Do not assert source-level helper acceptance before an authorized Code + Build compile and independent Test + Benchmark gate. TB-REV-157 resolved the inherited V3 timing conflict: it froze the exact V3a helper CB-174 as the next separate Code + Build turn, while retaining the full V3b production-builder reaching proof for later canonical stop-switch wiring.

## Verification limits

This analysis is static and uses the immutable source snapshot (CB-173 semantic source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`). It is not a compiled or executed test. No source, test, selector, benchmark or workflow file was changed in the review.
# CB168K — exact source-edge slide-interior contact consumer (frozen scope, 2026-11-20 UTC)

> **WITHDRAWN by [RA-270](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md#ra-270--adversarial-re-review-of-this-review-2026-11-20-utc) S2.2.** This was a prose plan, not an exact diff. Its helper restates `first_field_aligned_carrier_contact`, it has no reader, and it defers the missing piece-aware cut position. The successor is `M6-CP3-CB168K-P13-SLIDE-CONTACT-ARRIVAL-RECEIPT`. The text below is kept for history only.

## Situation

Review-approved next **Code + Build only**: `M6-CP3-CB168K-P13-EXACT-SLIDE-INTERIOR-CONTACT-CONSUMER`. This is an **inert** consumer preparation, not a geometric repair. Exact immutable observations are in [TB148 independent Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md). No tests or benchmarks execute during this Code + Build turn.

## Background

Four committed moving-trace entries lie strictly inside four wall-trace edge slides, each on its own canonical source edge and exact rational parameter. None owns a shared trace event. `first_field_aligned_carrier_contact` already recognizes the geometry; the live loops log but ignore it. `EmbeddedGraphTopology.cpp::carrier_contact_struck_position` recognizes exact segment entry only. `TraceCutPosition` optional interior fraction maps onto a face chord; it cannot denote an edge-slide point by reusing an edge rational parameter.

## Assessment — bounded implementation contract

1. Create the **smallest non-wired** helper or value in the appropriate existing geometry source that recognizes a real struck trace's **exact open interval** on `SourceEdgeTopologyKey` from `edgeTransitEntry` to `edgeTransitExit`, with carrier edge, canonical exact unit parameter and struck segment index. Reuse `first_field_aligned_carrier_contact` and existing authority types; do not introduce a parallel tolerance key or duplicate source identity model. The result must have a name that describes slide-interior ownership, not this milestone number.
2. Preserve direction (ascending or descending), segment ID, face/source-support, component/sheet constraints and strict parameter bounds. Reject the slide's two endpoints, source-edge vertices, non-slide segments, mismatched carriers/charts, unrelated face chords and unsupported source paths. No proximity, epsilon, priority guess, or new shared-node ID.
3. Keep `carrier_contact_struck_position`, `TraceCutPosition`, `exact_trace_interior_point`, producer loops, graph builder, H4 oracle and all existing validation behavior unchanged. Do not append a real event or change a graph cut position. If a safe helper cannot be implemented without changing existing semantics, stop with a concrete design finding and remain in this CB (do not fabricate a PASS).
4. Introduce focused **independent positive and negative** compile-owned assertions: four exact sphere inputs (the four canonical carriers and rational parameters); explicit descending slide; strict-endpoint rejects; wrong-edge, wrong-segment and absent slide rejects. Assertions must fail if the new helper is deleted or always returns false/true. Use real trace/source support; do not derive expected output from the helper being checked. Keep existing row963 and selector byte-identical. Do not introduce unrelated fixture/probe work.
5. Compile/package all eight existing mandatory GMP/GMPXX targets with `runtimeExecution=false`, record exact source SHA, complete diff and immutable artifact; no runtime, benchmark, full matrix or selector promotion. Preserve accepted 491/491, deferred81 and stable66/17/49. Do not change workflow permissions.

## Recommendation — later held stages and falsifiers

Only after independent Review may a later Code + Build design a **piece-aware trace-cut position** (not an optional face-chord fraction), followed by a separate producer switch in the two contact loops with existing exact arrival-order measure, then separate immutable TB. Required eventual falsifiers are four exact shared node incidences at the four source-edge parameters, preservation of the existing reciprocal pair nodes, valid incoming/outgoing edge pieces and source charts, no new unsupported events, row686 `chi=2` under the correctly switched H4 oracle, and rows669/698 no longer exhausting. Any failure retains C5/O47 and all acceptance holds. **None of these held stages is authorized in CB168K or this Review.**

# D5 chain-span switch: source-derived logical-side review candidate (2026-11-09)

**Authority:** `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH`, 64B.3 Review, **unfinished**. This is a narrow **CB113 helper draft only**; it is **not the full CB113 patch**, **not frozen**, **not compiled or executed**, and **not authorized for application**. See [RA-218](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md) §3 and [the interval/identity source review](Architecture_M6_CP3_DEFN_P13_A3_Span_Switch_Interval_Identity_Source_Review_20261109.md).

## Exact preservation and static validation

- Source snapshot: `82d74f543d51803f92002f156a4250f32bf968a1`, run `42699570720`, artifact `13710408472`, SHA-256 `73ed73f3fd0862810344a7b6f13f799107fd306b44152b79094659b0f88e91d1`, 5,405 source checksums already verified. `source.tar.gz` hash rechecked in this attempt.
- Patch name `Directional_A3_CB113_Logical_Sides_Draft.patch`; 12,475 bytes, SHA-256 `027f2699b39794f4959dfb00d0f217b297156fafd63a4bd00ec98f2181c5f617`; Git full-index binary patch; three paths, +209/−0: `src/geometry/GlobalConformityBaselineSupport.cpp` (+100), `src/geometry/GlobalConformityBaselineSupport.h` (+19), `tests/GlobalConformityBaselineTests.cpp` (+90).
- Git pre/post blob identities match **all three** `index` records in this patch: Support.cpp `131662adb8b5e290f874db0bac99b8004c8120d7` → `cde200d07af2fd3c3e59139e53ee2766d01f6c12`; Support.h `3706eb9fac97cd32272007d5a4fef2e48e8bb75d` → `45b22345122a6a720cac82f0d6d5142080184e3a`; Tests.cpp `50c5aa169f1d32aa6655cdf974a57c255754fc5b` → `817aafc10de173f8e5fb2d32a8d298e2952ab762`.
- `git diff --check`, fresh-tree `git apply --check`, application, and `git apply --reverse --check` succeeded on only the three exact source paths. Local synthetic Git history was used solely to produce the binary diff, **not** as authentic repository history evidence.
- Independently preserved under ChatGPT Library `/Directional/Work-Preservation/Directional_A3_CB113_Logical_Sides_Draft.patch` and Google Drive `My Drive/Directional-CI`, raw ID `1Nlvqg7Q8p4lY6J_xdyLtRwU2rEHAerNM`. Google Drive metadata independently confirmed filename, `text/x-diff`, 12,475 bytes, and expected destination folder ID `1I_-EViWSpaxg69pbglfPPVnFRYb1s5O0`. **Staged for preservation, not dispatched.** Metadata does not verify remote content hash.

## What the draft actually defines

The helper `derive_chain_boundary_sides(regions, chains, arcs)` consumes existing `GlobalTopologyRegion.boundary`, CB110 `BaselineMandatoryChain` and unchanged A2b arcs. For each region, it recognizes maximal full-chain traversals around the **cyclic** raw boundary, in forward or reversed child order; validates ordered identities, orientation and exact cover; permits wraparound; rejects missing, duplicated, partial, misordered or foreign child arcs; checks chain-source continuity on multi-child chains and that a span has one or two true logical sides of opposite orientation. It returns `BaselineChainBoundarySide{span,region,orientation,occurrences[]}`, retaining each exact `ConformityBoundaryIncidenceId` and using the first child arc as the existing `ConformitySpanId` (no new chain identity).

The proposed GTest `GlobalConformityBaseline.ChainBoundarySidesPreserveRawIncidences` (authored **but not run**) covers a three-child chain `0F,1R,2F` owning both full forward/reverse runs of one region, cyclic rotation and wrap, two distinct regions, missing/misordered/wrong-orientation child, extra/duplicate side, duplicate orientation, incomplete partition, one-side exterior, and arc-row permutation. A 3-child chain with two opposite logical sides still has **six raw occurrences but only two logical sides**: parity and front coverage must use logical multiplicity, source provenance retains all six IDs.

This is a **shared source-derived helper**, not a solver switch. CB113 still must validate the upstream stop-set and Mandatory rails, use the helper in both producer and independent validator, switch parity/normalized-digest/component/graph/coverage logic, and preserve exact per-piece periodic and curved-disk authority. The helper assumes input chains were produced by CB110 (the caller/validator must re-derive them); it does not independently certify `HardRailId` ownership. The candidate may still contain C++ compilation defects or fail against real topology; only static application was checked.

## New review constraint: same-region self-loop

`GlobalConformityParityGraph.cpp:57–64` explicitly treats a parity graph self-loop differently: it does **not** toggle demand twice, and it excludes self-loop edges from connectivity adjacency. This supports retaining two opposing same-region sides of a joined span rather than collapsing by region ID. It does **not** establish full solver correctness after D5; producer and validator must re-derive the graph and compare exact certificates.

## Next same-turn work

1. Critically review and, if needed, correct the narrow helper against authentic source, particularly real cut-domain region walks, trace/cut singleton behavior and C++ compile diagnostics. No standalone CB113 implementation yet.
2. Freeze the still-missing **CB112 full producer bridge**: exact global breakpoint-to-piece path with full source-face route and raw occurrence/child-arc evidence; behavior-neutral on one-arc spans; typed decline when a chain crosses a rectangular chart corner without a scheduled breakpoint.
3. Freeze **CB113 atomic switch**: baseline input authority, validated CB111 stops, partition, logical sides, original raw incidences, matching/coverage/parity/face/periodic consumers, and an actual Vase non-vacuity gate. Do not weaken final unit-ordinal width or uncut closed-rail debt O34.
4. Only when all three exact patches and independent TB falsifiers are accepted, complete the Review closeout, auth-history `review_check.py boundary`, durable-document audit, and single authorized successor. Until then this DEFN remains **IN_PROGRESS**.

Historical baseline: accepted CP2 491/491; TB93 923/923, membership 1004, 7+7 raw lines matching TB92; stable 66/17/49, debt 1, deferred 81, selector497/CP3 not promoted. No product/test/fixture/selector/workflow mutation in this Review.

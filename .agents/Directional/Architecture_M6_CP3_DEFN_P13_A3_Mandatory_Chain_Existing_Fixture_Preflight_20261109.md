# D5 prospective non-vacuous positive fixture — static source preflight (2026-11-09)

Canonical turn: `M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SCHEDULING` (runtime-free Review). **Candidate only, not a proven legal join, test result, approved Code + Build diff, or production Vase witness.**

## Existing fixture, no duplicate scaffold

`tests/SurfaceCellsPhase10Tests.cpp:293-331` already builds `make_disconnected_rectangular_feature_pair_mesh()`: two disjoint planar 3x3-vertex components, each with a two-edge vertical hard feature along x=1. `build_rectangular_hard_rail_phase_front()` at `:7113-7182` submits exact userHardEdges `(1,4),(4,7)` and `(10,13),(13,16)`, with `SurfaceCells`, fail-closed fallback and recovery disabled. It retains stage A2b `topologyPlan`, `fieldNetwork`, `rails`, source authority, atlas and A3 baseline. Its existing tests exercise A2b/A3/typed-rail and produced phase-front ingress; **they are not D5 join tests**.

This is a better first independent synthetic-join candidate than adding an invented ID-only fixture: each pair traverses **two distinct source edges**, sharing a straight interior source vertex (4 or 13). The hard feature divides each component into two rectangular source-topology regions. A future checked test must establish that both adjacent original Mandatory A2b children bind to **different** `NetworkEdgeId` values and the same ordered `HardRailId`; a Trace split of one network edge is not acceptable.

## Required preflight and falsifiers, no shortcut

Before claiming a positive D5 chain, a future Code + Build test must independently assert: valid original A2b; two original Mandatory arcs on the above physical source-edge pair; distinct network-edge ancestry; exact contiguous canonical source paths; both left and right cyclic region occurrences; physical oriented source-face side; one legal endpoint-slot continuation in A2b rotation; same per-side region/component/sheet lineage; no Trace/Cut/port/contact; and no protected feature `curve.corners` or `curve.junctions` at shared vertex under **effective production options**. Do not assume these predicates merely from straight coordinates, prior fixture success or stage digest. If any fails, report the fixture **ineligible**, not a fabricated positive.

Source formula checked directly in `src/geometry/EmbeddedGraphTopology.cpp:1868-1919`: for directed `a,b`, `successor(a)==b` and `successor(reverse(b))==reverse(a)` are the two independent directed-face necessary checks. Match to actual ordered A2b region occurrences and oriented physical sides; retain separate exterior proof where applicable. Do not share the producer's unchecked join helper in the independent validator.

After establishing one eligible original-edge pair, compare an emitted two-child chain against an all-singleton proposed partition on the **same validated upstream tuple**. The latter must be rejected specifically as `NonMaximalPartition`. Fully reverse/invert the two-child sequence and require the same canonical identity. Rebuild a source-face-row-permuted version using the fixture's existing `reverseFaceRows` mode and require equivalent structural identity. A different-component forced pair will generally fail exact endpoint continuity first; do **not** falsely count it as an independently reached side-sheet test.

## Production gate still separate

The future immutable TB must **also** derive at least one valid real retained Vase chain spanning two distinct original Mandatory `NetworkEdgeId` values, with both physical sides and feature protection certified; otherwise it reports `NoCertifiedProductionJoin` RED. This synthetic fixture cannot replace that gate. This Review does not authorize source/test/selector/build edits, alter A2b/A3 per-original-arc positivity, amend DESIGN §7.4, run a binary, or start successor 64C.

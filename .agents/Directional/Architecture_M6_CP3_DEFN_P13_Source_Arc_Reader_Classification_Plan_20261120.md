# M6-CP3 — source-arc reader classification (EPO-1 definition-only successor)

## Situation
The independent TB151 gate preserved 966/966 and the three-case census without repairing the source-piece producer. This document defines **only** the next classification turn. No implementation, build or runtime is authorized by this definition task.

## Background
The existing production and row686 cut paths encode sliding edges as face chords. A `faceThenEdge` wall cannot be cut correctly by a face chord. RA-273 S4 owns the precise source reader inventory and RA-261 freezes synchronized path/ray consumers.

## Required classification
Review every source-arc reader named by RA-273 S4, including `SurfaceCellTracing.cpp` `bound_arc_schedule`, `edge_arc_schedule`, phase-front builders; `SurfaceCutGraph.cpp` `build_source_face_ownership`; `GlobalConformityBaselineSupport.cpp` support/certification consumers; `EmbeddedGraphTopology.cpp` `actual_complement_component_count`. For each reader, record its exact input, output, classification (traversal-sensitive, geometry-only, or both), its piece-count and source-support obligations, and a falsifiable before/after statement. Determine whether the reader interprets a face segment, a source-edge segment, or both. Do not infer support from world coordinates.

## Acceptance and stop rules
- Complete inventory of all readers and downstream certifiers; absence of an unclassified read demonstrated by source search and reviewed call sites.
- Explain each `faceThenEdge` and `edgeOnly` case, orientation reversal, endpoints and shared source-edge ownership. Show why the edge interior is not a face chord.
- Freeze an exact single next-turn scope **only after** proving the reader inventory; later EPO-6/O49 edge-only rule is unwired, the row686 oracle is test-only, and the coordinated production cutover handles paths, counts, rays, ranks and digest together.
- If any reader ownership or supporting source identity cannot be proved, record the exact conflicting source and stop for a bounded definition decision; do not invent behavior or pass the gate by altering a test.
- Preserve accepted CP2 491/491, 81 deferred, stable 66/17/49, `chainRimSchedules=false`, and the independent full-gate/census test requirements. No product, test, selector, build, fixture or runtime change in this definition turn.

## Deferred sequence — not part of this turn
EPO-1 definition → O49/EPO-6 unwired edge-only rule → row686 test oracle real-piece reader → EPO-2/3/4 coordinated Code + Build (path/count/ray/rank and count-digest) → independent TB → stop switch → independent TB for χ2 and four nodes → CB170 → CB171 → CB172/O48. This order is a dependency, not permission to combine turns.

# Milestone G P5 — Mixed-Sheet Identity and Pipeline Liveness Code + Build Plan

**Turn:** P5-CB75 through P5-CB82 code changes + compile-only build  
**Input artifact:** P5-TB14 artifact `8864496877`  
**Exact tested source:** `188baf35a13c02b20424cd72fb9c6d8fe81ec9fc`  
**Review policy:** `never`

## Completion status

Implemented by `1dab9a0e8915e7d9641c9b005bfa57eaefb4a8cc` and compiled from exact source `f4a6a392dc3d490efca4f94bd613aadaad2c1b01`.

Compile-only run `30839059634` succeeded and produced artifact `8866222973`, digest `sha256:c38649208b1586094f804895c39c1319b71eb0c5220e84d1d2514b04954c63fe`.

All P5-CB75 through P5-CB82 work packages are source-complete and compile-valid. Runtime acceptance is deferred to P5-TB15 using artifact `8866222973` without rebuilding.

## Objective

Correct the committed subdivision's mixed-sheet identity, restore truthful rollback and exact product reuse, finish rail propagation and valid Milestone D fixtures, eliminate in-pipeline bunny crashes and nonterminating simplification, and package a compile-only checkpoint without executing a binary.

## P5-CB75 — Preserve exact sheet identity through successful subdivision

- Treat source occurrences as exact face/barycentric/component/sheet/provenance records.
- Select compatible source occurrences independently for each oriented replacement halfedge and twin.
- Recompute each affected cell from one exact boundary component/sheet scope.
- Preserve rail, curve, proposal, family, hard-feature, and complete provenance identity.
- Audit every committed transaction and reject atomically on mixed identity.

## P5-CB76 — Make rollback proof structurally exact

- Restore every field mutated by tentative coupled insertion before proving equivalence.
- Compute exact hashes after rollback completes.
- Keep one committed complex plus compact undo state.
- Report undo-owned bytes separately.
- Preserve distinct missing-common-chart and invalid-midpoint failure scenarios.

## P5-CB77 — Produce exact reusable-product hits

- Pair descriptors and products without lossy `cellId` mapping.
- Retain multiple products per semantic hash.
- Accept only exact collision-safe dependency equality.
- Consume an unaffected product once and leave unmatched products intact.

## P5-CB78 — Finish rail propagation

- Carry rail/curve identity, intervals, classification, component/sheet, and complete provenance through node occurrences, halfedges, subdivision, and post-stitch rebinding.

## P5-CB79 — Rebuild valid fixtures

- Construct the Milestone D multi-edge fixture as an explicit valid DCEL.
- Emit cylinder source-edge arcs in every incident source-triangle chart.

## P5-CB80 — Make simplification live and deterministic

- Assign generation and semantic identity to candidates.
- Deduplicate each generation.
- Reject stale generations.
- Require monotone structural reduction for committed edits.
- Replace superseded frontier storage instead of appending indefinitely.
- Report generation and candidate counters.

## P5-CB81 — Eliminate in-pipeline lifetime hazards

- Avoid stale node charts, product payload moves, candidate references, and iterators across mutation or frontier replacement.

## P5-CB82 — Memory discipline and compile/package gate

- Report compact rollback undo ownership and bounded frontier/product state.
- Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Package source, binaries, libraries, fixtures, logs, submodules, clean status, and checksums.
- Execute no binary.

## P5-TB15 handoff

Use artifact `8866222973` directly without rebuilding. Validate all previously failing tests and crashes, the authoritative suites, the full binary, four fresh random-bunny processes, exact rollback, positive reuse, rail/fixture contracts, deterministic liveness, output quality, timing, and memory.

P5 remains open and PR #8 remains draft and unmerged until runtime validation closes the production gates.

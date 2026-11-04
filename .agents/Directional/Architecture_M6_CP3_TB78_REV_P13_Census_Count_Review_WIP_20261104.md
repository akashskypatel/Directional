# TB78 census-count discrepancy — independent Review work in progress (2026-11-04)

**Current turn:** `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV`. **NOT CLOSED / NO SUCCESSOR AUTHORIZED.** This record preserves independently checked evidence for same-turn continuation; it is not a final adjudication or an acceptance decision.

## Frozen authority

- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 (draft).
- Product/package: CB88 semantic source `6cc50f878ef829711e16262759afb3367bec2aff`, immutable artifact `13358062295`.
- Exact inspected snapshot: commit `e524214e3f40f35e20e6bd87cf87b72707782126`, workflow `41913555656`, ZIP artifact `13362694553`, ZIP SHA-256 `414b1050b5e7919d77153f8e91a942e6e2b622aa6f7a4818ecfe10a7cf1645cc`; inner source archive SHA-256 `77de3b3e8179ef87698e5d62d098275c120330668b7d78b81fe19a1f8327fdec`, matches snapshot metadata.
- Immutable TB78 gate run `41906228679`, artifact `13360412752`: independently rehashed ZIP `f81bb8dfe426ec7fcf37e2e4d932f0897451b02fd902f09bf14087c73b6cc2e5`, **1,806/1,806** manifest entries valid, **899 unique identities/899 PASS**. Local frozen manifest `Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv` SHA-256 `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`; exact TB77 896-row prefix matched byte-for-byte (including header).
- Immutable census run `41906541304`, artifact `13361996286`: independently rehashed ZIP `674a585cb0c838e6f420533b8dd5c78246524be4a72b8a7c6000c72add3ef161`, **9/9** manifest entries valid, exactly 3 distinct executions (1 PASS, 2 RED), clean execution boundary with configure/compile/relink/benchmark flags false.
- Vase raw log: `terminal=NotProductionReady:completion detail=SelfIntersectingFace traceSegments=192482 arrangementCells=26817 completedQuads=67784`; the frozen RA-202.9 registration prescribes `67829`. Delta = **-45**, not explained by the runtime verdict. Cylinder PASS and BunnyRandom P13-e `sourceVertex=49` RED match registration.

## Source-level narrowing (static; not a reproduction)

- `tests/SurfaceCellDesignAcceptanceTests.cpp` loads `vase__surface_cells` from `benchmarks/fixtures/milestone_g_manifest.json`, sets fallback `Fail` and recovery disabled. The manifest uses `milestone-g/vase.off`, `generated_field=smooth`, `length_ratio=0.05`.
- `src/bench/BenchmarkCases.cpp::generate_benchmark_field` calls `fields::extract_cross_field` when `generatedField == "smooth"`. Thus fixture input includes a runtime-generated field, not only fixed mesh bytes.
- `src/pipeline/RemeshPipeline.cpp` (around lines 14407–14475) obtains `aggregateLineageMesh` from `completionProduct.assembly.mesh` when the direct path is used, assigns `completedQuadCount = aggregateLineageMesh.quads.size()`, and records `surfaceCellCompletedQuadCount` before subsequent optimization/final validation.
- Therefore the differing count exists by completion assembly at the latest. Equal reported trace and arrangement **counts** do not prove byte-identical field inputs, matching trace topology, cell topology, or patch completion graphs.
- RA-202 macOS scratch report says 67,829 on its locally built state, including FMA-on/off equivalence there. The immutable Linux run says 67,784; no evidence yet shows which earlier stage diverges, whether repeated Linux runs reproduce 67,784, or whether the same generated field bytes were used on both platforms.

## Required continuation — Review only

1. Independently reproduce the RA-202.12 scratch probe on fixed source and identical fixture/options, recording complete mesh and raw-field hashes on each platform; do not treat old prose as its own oracle. Scratch scripts `scratchpad/tb76r/` were explicitly uncommitted and are not present in this snapshot; reconstruct and verify the minimal recipe first.
2. Repeat the Vase census on each platform with unchanged source and process isolation, retaining per-run stage hashes, failure code, counts, wall/RSS and deterministic seeds; distinguish within-platform nondeterminism from cross-platform variation.
3. Locate the **first** diverging stage (generated cross-field → transport/traces → selection → arrangement → completed-patch/assembly) via canonical source-ID/patch-ID hashes, not aggregate counts alone. When the first divergent stage is found, compare its exact producer decisions and inputs.
4. Adjudicate the registered count: semantic delta versus fixture field initialization/numerical dependence versus invalid preregistration. Preserve RA-202.9 as frozen until evidence justifies a correction; do not weaken tests, replace registration, retry TB78 unreviewed, or promote CP3/selector497.
5. Finish the full `REVIEW_TURN_POLICY.md` closeout including `ORIENTATION.md`, tracker, changelog, roadmap, consolidation, `review_check.py boundary`, and exactly one bounded successor with predeclared falsifiers. This WIP does not discharge those duties.

**Standing state:** CP2 accepted 491/491; stable 66 events / 17 categories / 49 recurrences; debt 1; 81 deferred; selector497/CP3 unpromoted; P13-l/P13-e and O27–O29 carried. No product, test, fixture, selector or build code was edited and no Directional runtime/build was executed in this Review attempt.

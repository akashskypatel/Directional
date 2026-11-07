# TB78 census-count discrepancy — independent Review work in progress (2026-11-04)

> **Closed by [RA-203](Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md)** (2026-11-04). Its rehashes and static narrowing are retained as evidence. Its blocker was RA-202.9's route, not the policy, and RA-203.1 resolves it. The count is the platform split O30. The successor is CB89, then TB79.

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

## Same-turn independent source audit (2026-11-04; not a runtime probe)

- A second exact working-branch source snapshot at `193079c1a42ecb98f7498ec8364e3cc8e45e4d12` was acquired through run `41917413627`, artifact `13365138271`; ZIP SHA-256 `086ea53ba4469771b2fa596262e571f3f607927ee92f290727112763a3f28772`, archive SHA-256 `685f0b4a38d966d24bbc1d4228561da7a126f40716f33d16a95071efe6530c26`. The source archive and all **6,167/6,167** file manifest entries verified locally. The additional files include the resumed STATUS and temporary snapshot trigger; no new semantic product claim is made.
- Independently hashed the frozen 899-row TB78 manifest (`9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44`) and rechecked **byte-for-byte prefix equality** with the 896-row TB77 manifest. Exactly three GUARD rows (897–899) follow it. The frozen Vase mesh bytes hash to SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`.
- `benchmarks/fixtures/milestone_g_manifest.json:196-204` prescribes `generated_field=smooth`, not a frozen raw-field input. `src/bench/BenchmarkCases.cpp:515-535` invokes `fields::extract_cross_field` with normalization, combing and matching. `src/fields/CrossField.cpp:359-421` solves a complex sparse system using `Eigen::SimplicialLDLT` and floating-point transport coefficients. This identifies a **numerically computed upstream input**, not a demonstrated platform difference. RA-202's FMA-on/off equivalence on macOS does **not** establish Linux/macOS raw-field equality.
- `src/pipeline/RemeshPipeline.cpp:14407-14482` confirms the reported completed-quad count is the size of the assembled `PureQuadMesh::quads` (or the alternate phase-front/recovery product if enabled), captured **before** output validation. Hence a different `SelfIntersectingFace` location cannot by itself change the reported completed count. Equal trace/arrangement counts alone cannot prove equal earlier topology.
- **First-falsifier order:** verify exact source/fixture/options and raw-field bytes per run; repeat Linux and macOS independently without changing inputs; compare canonical hash by stage in order of field → transport/traces → selection → arrangement cells → completed patch/assembly. Record raw field as face-major, 12 binary64 values per face with explicit byte order, alongside mesh vertex/face arrays; retain first divergent source IDs/patch IDs, timing/RSS and process exit. If raw-field bytes differ, investigate numerical field generation before blaming completion; if they match, proceed stage by stage. If outputs vary between same-platform runs, classify nondeterminism separately. No one of these outcomes is yet observed.

## Narrower existing probe surface (static audit 2026-11-04)

- Census ZIP `13361996286` reverified (outer digest, 9/9 entries). Vase raw log: 67,784 quads; no stage hashes. Census `ledger.tsv` reports `reason-not-observed` for both REDs, so typed/count verification requires **manual raw-log review**, not trusting summary ledger.
- `src/bench/DirectionalBenchmark.cpp:791-797` computes `record.fieldHash`, but its JSON writer at 3234–3256 **omits it for generated smooth fields**. Existing stage/context hashes are serialized on failure (benchmark 1322–1372), but **pipeline floating hashes quantize to 1e-9** (`RemeshPipeline.cpp:1673-1675`), so equal stage hashes do not prove bitwise field equality. Prefer the existing bit-exact `record.fieldHash` before new instrumentation.
- `directional_benchmarks` supports `--warmup 0 --runs 1 --disable-surface-cell-source-grid-recovery --output`; verify option parity with GTest (debug/retained-geometry and paired-boundary flags). Use fresh processes; main returns zero after writing JSON even on rejected runs, so inspect `runs[*].success` and terminal diagnostics.
- Compare exact mesh/options → raw generated field → composite cross-field → traces/selection → arrangement → completion. Matching **counts** or quantized structural hashes do not prove bitwise field identity.
- **Authority conflict:** Review policy §4.3 forbids runtime, but RA-202.9 asks this Review to re-run missing RA-202.12 scratch probes. No product execution belongs in Review; separately authorize diagnostic execution before adjudicating the count.

## Required continuation — Review only

1. RA-202.12 independent probe needs same source/mesh/options and raw-field hashes on macOS/Linux. Its scratch scripts were uncommitted/absent. Reconstruct the recipe in a separately authorized runtime turn; do not treat its prose as an oracle.
2. Repeat the Vase census on each platform with unchanged source and process isolation, retaining per-run stage hashes, failure code, counts, wall/RSS and deterministic seeds; distinguish within-platform nondeterminism from cross-platform variation.
3. Locate the **first** diverging stage (generated cross-field → transport/traces → selection → arrangement → completed-patch/assembly) via canonical source-ID/patch-ID hashes, not aggregate counts alone. When the first divergent stage is found, compare its exact producer decisions and inputs.
4. Adjudicate the registered count: semantic delta versus fixture field initialization/numerical dependence versus invalid preregistration. Preserve RA-202.9 as frozen until evidence justifies a correction; do not weaken tests, replace registration, retry TB78 unreviewed, or promote CP3/selector497.
5. Finish the full `REVIEW_TURN_POLICY.md` closeout including `ORIENTATION.md`, tracker, changelog, roadmap, consolidation, `review_check.py boundary`, and exactly one bounded successor with predeclared falsifiers. This WIP does not discharge those duties.

**Standing state:** CP2 accepted 491/491; stable 66 events / 17 categories / 49 recurrences; debt 1; 81 deferred; selector497/CP3 unpromoted; P13-l/P13-e and O27–O29 carried. No product, test, fixture, selector or build code was edited and no Directional runtime/build was executed in this Review attempt.

**Audits pending:** snapshot-only `review_check.py boundary` cannot verify Git ancestry (exit 1); `document_drift_audit.py`: handoff 43,478 B > 16,000 B ERROR; orientation 29,008 B > 24,000 B WARNING. Historic boundary and consolidation remain outstanding.

## Process / policy verification notes

Prior direct-read-before-snapshot policy miss is recorded. This continuation used a verified source snapshot. No runtime probe or historic Git-boundary check completed. Root cause unresolved; no CP3 promotion.

# M4-CP-SCALE-CB18 — Code + Build Report

**Turn:** `M4-CP-SCALE-CB18`
**Type:** Code + Build / runtime-free
**Status:** **COMPLETE / COMPILE+PACKAGE GREEN / UNPROMOTED CANDIDATE**
**Evidence source:** `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Candidate artifact:** `10532133889`
**Exact next:** `M4-CP-SCALE-TB12-R5-EXEC`

## 1. Scope and result

CB18 implements only the separating-hard-feature singularity ownership seam authorized by `Architecture_M4_CP_SCALE_CB18_Separating_Hard_Feature_Singularity_Ownership_Code_Build_Plan.md`.

The semantic patch changes exactly:

- `include/directional/authority/FieldTransportAtlas.h` — one diagnostic field distinguishing separating-feature boundary ownership from same-region slit ownership;
- `src/authority/FieldTransportAtlas.cpp` — source-region-boundary owner discovery, canonical owner selection and exclusive ownership accounting;
- `tests/FieldTransportAtlasTests.cpp` — one direct synthetic regression control with independent topology/index preconditions.

No source-topology partitioning, CB16 cycle ordering/`dual_cycles`, retained genus-two fixture/rawfield/metadata, S5 focus, selector426, CMake or benchmark semantics changed. No selector427 exists.

## 2. Implemented authority correction

For a prescribed globally-interior singularity incident to a hard feature whose two incident source faces belong to different topology regions, `FieldTransportAtlas` now treats that separating feature as an explicit absorbed-boundary ownership domain rather than relying on the same-region local `barrierVertices` set.

The implementation:

1. derives separating-feature incident regions from authoritative hard-feature edges whose adjacent faces have distinct `TopologyRegionId`s;
2. accepts only an incident `BoundaryLoop` whose turning lift matches the raw singularity numerator;
3. canonicalizes multiple valid candidates by minimum stable `(TopologyRegionId, FieldCycleId)` pair, making container/region visitation order non-authoritative;
4. keeps local interior-cycle, same-region slit and separating-feature boundary owner classes mutually exclusive;
5. publishes the selected singularity as `FieldSingularityFact::PortPolicy::BarrierAbsorbed` and relies on the already-authoritative branch-topology rule that absorbed singularities own zero origin port attachments;
6. records `separatingFeatureBoundaryBoundSingularityCount` separately from `slitBoundaryBoundSingularityCount` and subtracts both from `unboundSingularityCount` without relabelling one domain as the other.

The direct control `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` constructs a five-ring annulus, proves the target is globally interior, proves the selected hard edges separate source topology regions and therefore contribute zero pre-CB18 local barrier edges, independently derives nonzero singularity indices, and compiles assertions for exactly one boundary-cycle owner, matching lift, `BarrierAbsorbed`, zero origin attachments and zero unbound count. The test is **compiled, not executed**, in this turn.

## 3. Patch/source provenance

The verified source patch was applied by workflow run/job `35307892821 / 105483779016` from base `a4c29483b5f564f01245ca83dec0924f12c83352`.

- Patch SHA-256: `1926b311af46ca7205944744d10ca0947d4fe9301c5952cde1236ddf09a3a9c2`.
- Applied semantic commit: `079933f2ec31a9323218e73c7ae0d3ea1d11103c`.
- Patch result artifact: `10532581071`, SHA-256 `93a5b0aed50025d0926c689b0821715583ca7b08aba1181ef95cf79a9044cc64`.
- Patch log artifact: `10532815739`, SHA-256 `9465719b570313223f83de0789988da5927cb209a1c83cb3fb9a29eae0bb9e5a`.
- Patch result records `runtimeExecution=false` and `job_status=success`.

A later duplicate patch orchestration attempt (`35308712407`) and the resumed-session duplicate attempt (`35308929464`) both failed **before application** because all three intended semantic paths had already changed from the old base. They produced no source mutation and are invalid-attempt orchestration provenance only. The resumed-session staging file was retired through the owner-authorized Drive control plane; the original successful patch file is already inaccessible to that control plane and requires no rediscovery retry.

## 4. Compile/package evidence

Mandatory reusable compile run/job `35307991751 / 105484066744` is GREEN.

- Candidate result artifact: `10532133889` (`m4-cp-scale-cb18-result-35307991751`), SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`.
- Persistent compile log artifact: `10532393326`, SHA-256 `5d5d36c2010b92e915b98f85481aab83e1928c5b1654fee9af4e39b47c4a99c3`.
- Packaged exact semantic source: `079933f2ec31a9323218e73c7ae0d3ea1d11103c`.
- Source archive SHA-256: `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`.
- Root `SHA256SUMS`: **28/28 PASS**, manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd`.
- Preflight exit `0`; build exit `0`; final source status clean.
- Six executables are mode `0755`; two static libraries are `0644`.
- Command boundary records `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed` and `runtimeExecution=false`.
- GMP evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the authority-kernel test link command.

All standard eight targets compile/link:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The persistent log explicitly records that no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input executed.

## 5. Frozen-byte verification

The packaged source preserves:

- selector426: 426 LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- exact first425 prefix: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- `genus_two.obj`: `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
- `genus_two.rawfield`: `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
- `genus_two.fixturemeta.json`: `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`;
- no selector427.

## 6. Disposition

CB18 satisfies its **Code+Build** success condition only: the bounded source/test correction compiles and packages under mandatory GMP/GMPXX with frozen bytes intact and zero generated runtime.

It does **not** close or reprice `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01`, does not grant S5/A3 credit, does not promote candidate package `10532133889`, and does not change accepted runtime authority `10473134357` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

Exact next is immutable artifact-only `M4-CP-SCALE-TB12-R5-EXEC` under `Architecture_M4_CP_SCALE_TB12_R5_Artifact_Only_Test_Benchmark_Plan.md`.

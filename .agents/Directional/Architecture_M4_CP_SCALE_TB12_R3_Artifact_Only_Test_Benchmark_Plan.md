# M4-CP-SCALE-TB12-R3-EXEC — Artifact-Only Multi-Component Cycle-Support Test + Benchmark Plan

**Turn:** `M4-CP-SCALE-TB12-R3-EXEC`
**Type:** Test + Benchmark
**Immutable candidate:** artifact `10523132151` / compile source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`
**Authority:** `M4-CP-SCALE-CB16`
**Runtime boundary:** artifact-only execution; **no configure, compile, relink, repair or source/test/fixture mutation**

## 1. Goal

Determine whether CB16's all-closed-components representation works at runtime without borrowing authority from the producer oracle, then retry the unchanged S5 genus-two focus. This turn measures the immutable package only; it does not repair failures or publish selector427.

## 2. Immutable preflight

Before generated runtime, download artifact `10523132151` once and verify:

- provider/local ZIP SHA-256 `2962e2c0e4ea6dc9294d159c19c78543ddf173b5ff342436c9e89e26b4410f73`;
- root `SHA256SUMS` verifies **28/28**, manifest SHA-256 `61bf5fcabfb8a41f2de32b0ea7e1b3059579ecdd5ac07862cb657c46eedd3db5`;
- packaged source commit is exactly `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`, source archive SHA-256 `4be61bb45a1f925c4cff0cf5b6cc0b263948417b6271c43a919808f5c5133e99`;
- preflight/build exits are `0/0`, source-status snapshots are empty, `runtimeExecution=false`, `exactArithmeticBackend=GMP`, and link evidence contains both GMPXX and GMP;
- authority-kernel and producer executables retain mode `0755` and hashes `78fd5072420e5fa2b92c9d86aacf989cb2718c48e2f66550e14602f083efdb27` / `18a24349093397ac8ea7bd3074e98defda55a26bf602c359fa2716421da9d6ee`;
- selector426 is exactly 426 unique LF rows at `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owners `30/280/75/41`, with no selector427;
- genus-two fixture hashes are OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

Initialize byte+mode censuses for the package, packaged source and execution view before runtime. Do not use `--gtest_list_tests`, CTest, help/version/discovery commands, `chmod`, regeneration, fixture staging or package repair.

## 3. Gate A — direct CB16 controls

Run each identity below as a **fresh exact-filter process** against `bin/directional_surface_cell_authority_kernel_tests`, requiring exactly one selected/executed test and exit `0`:

1. `FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents`
2. `FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence`
3. `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper`
4. `FieldTransportAtlas.BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport`

Capture stdout/stderr, exit state, selected/executed count and per-process hash. If any identity is RED, SKIP, crashes, times out or selects anything other than exactly one body, **stop generated runtime** and route the evidence to mandatory Review. Selector426 and S5 are then unexecuted.

## 4. Gate B — unchanged S5 focus

Only after Gate A is 4/4 PASS, run exactly one fresh producer process:

`bin/directional_surface_cell_producer_tests --gtest_filter=M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`

Require exactly one selected/executed body. Preserve the complete semantic receipt, especially cross-field status, atlas establishment, cycle/witness counts, deepest stage, terminal error/reason, A3 production, topology certificate and any cycle-ordering discriminator.

- If the focus is RED, SKIP, crashes, times out or selects incorrectly, stop generated runtime. Do **not** run selector426 or benchmarks. The first semantic boundary becomes the next Review subject.
- If the focus PASSes, continue to Gate C. A focus PASS is still not S5 or selector publication authority until mandatory Review.

## 5. Gate C — cumulative selector426, conditional on A+B green

Only when Gate A is 4/4 PASS and Gate B is 1/1 PASS, execute selector426 in exact file order as **426 fresh exact-filter processes**, one identity per process against its statically mapped owner binary. Require:

- 426/426 PASS;
- zero RED, SKIP, crash, timeout, selection mismatch or unexecuted identity;
- owner census exactly **30 authority-kernel / 280 producer / 75 completion / 41 validation**;
- contiguous ordinals 1–426 and one selected/executed body per process.

No benchmark is authorized in TB12-R3. The change is correctness/topology representation, not a performance claim.

## 6. Immutable postflight

After the last authorized process, re-run only non-runtime integrity checks. Require package/source/execution-view/fixture byte+mode censuses, manifest, source archive, selector426/prefix and executable hashes/modes to match preflight exactly. Record `postflightComplete=true` and explicit false flags for configure, compile, relink, code generation, chmod, package repair, source/test/fixture mutation, selector mutation, benchmark execution and discovery/list/help/version activity.

## 7. Evidence and regression rules

Produce one result artifact and one workflow log artifact. Preserve raw process receipts and a machine-readable execution ledger. Update `Regression_Root_Cause_Tracker.md` for every observed RED/candidate before TB closeout.

`M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains non-stable until runtime + Review adjudicate it. Do not change the stable totals merely because CB16's direct controls pass. Accepted runtime authority remains package `10473134357` / selector426 **426/426** until Review explicitly promotes a later package.

## 8. Mandatory successor boundary

Every semantic outcome routes to an independent runtime-free Review before another Code + Build turn or any S5/selector publication. Name the Review from this execution turn as `M4-CP-SCALE-TB12-R3-REV`. Review must independently verify immutable package/source authority, Gate A independence/falsifiers, the S5 semantic receipt, any selector426 ledger, postflight equality and regression accounting.

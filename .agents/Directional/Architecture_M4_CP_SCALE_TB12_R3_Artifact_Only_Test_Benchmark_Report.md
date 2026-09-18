# M4-CP-SCALE-TB12-R3-EXEC — Artifact-Only Multi-Component Cycle-Support Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R3-EXEC`
**Disposition:** **COMPLETE / GATE-A SEMANTIC RED / FAIL-FAST STOP / REVIEW REQUIRED**
**Immutable candidate:** artifact `10523132151`, compile source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`
**Authoritative runtime run/job:** `35289133532 / 105427980925`
**Result/log artifacts:** `10526001047 / 10525856300`
**Mandatory successor:** `M4-CP-SCALE-TB12-R3-REV`

## 1. Immutable candidate preflight

TB12-R3 consumed CB16 artifact `10523132151` unchanged. Provider/local ZIP SHA-256 is `2962e2c0e4ea6dc9294d159c19c78543ddf173b5ff342436c9e89e26b4410f73`; the root self-manifest verifies **28/28** and hashes to `61bf5fcabfb8a41f2de32b0ea7e1b3059579ecdd5ac07862cb657c46eedd3db5`. Package metadata names exact compile source `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`; the packaged source archive hashes to `4be61bb45a1f925c4cff0cf5b6cc0b263948417b6271c43a919808f5c5133e99`; preflight/build are `0/0`; recorded source-status snapshots are clean; compile boundary is `runtimeExecution=false`; exact arithmetic/link evidence is GMP/GMPXX.

The authority-kernel and producer executables retain archived mode `0755` and SHA-256 `78fd5072420e5fa2b92c9d86aacf989cb2718c48e2f66550e14602f083efdb27 / 18a24349093397ac8ea7bd3074e98defda55a26bf602c359fa2716421da9d6ee`. Selector426 remains **426** unique LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, with exact first425 prefix `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b` and owner census **30 authority-kernel / 280 producer / 75 completion / 41 validation**. No selector427 exists. Retained genus-two fixture hashes remain OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`, rawfield `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`, metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No configure, compile, relink, regeneration, `chmod`, package repair, source/test/fixture/selector mutation, CTest, discovery/list/help/version command, or benchmark was executed in the authoritative artifact-only run.

## 2. Gate A — three direct controls PASS, synthetic genus-two control RED

The authoritative run is `35289133532` at event SHA `28a92be2f57226c0c047ab646d55762a4a4c6043`; execute job `105427980925` completed successfully as orchestration. Gate A ran fresh exact-filter processes in the frozen order, each with exactly one selected test and no skip:

1. `FieldTransportAtlas.IndependentCycleOrderingOracleHandlesMultipleClosedComponents` — **PASS**, exit `0`, stdout SHA-256 `64f28a1004c28570b3a1de89c5659d0b5f4a0cfa062d442c7871ee7f5ae51a33`.
2. `FieldTransportAtlas.PreservesSingleComponentCanonicalCycleSequence` — **PASS**, exit `0`, stdout SHA-256 `7c05d2ff10dd84e9bd8b9a6f971d04ccef39cdc710f9c84e4701ebca133d3350`.
3. `FieldTransportAtlas.IndependentOracleRejectsCycleOrderingTamper` — **PASS**, exit `0`, stdout SHA-256 `0e113347bcd71b23891fd60cd0b02c4b5ab6ad298ccfc00eba20c90e3a824c17`.
4. `FieldTransportAtlas.BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport` — **RED**, exit `1`, exactly one selected/failed test, stdout SHA-256 `2d07ff26f225a10af66221e7b09b7efa8a47742f1b7866d69e6c43544dc99c22`, empty stderr.

The fourth control fails at `FieldTransportAtlasTests.cpp:2144`: `built` is `false`, expected `true`, with receipt `code=CycleTransportMismatch;topologyRegion=0`. This is the mechanically observed boundary. EXEC does not infer whether the remaining mismatch is a production semantic defect, an incomplete CB16 correction, or a test-authority/precondition issue; mandatory independent Review owns that adjudication.

The execution ledger SHA-256 is `1330c5002dbc4aab900e518860c8f653cfcadb0910797caf1175828dc5cda290`.

## 3. Frozen fail-fast stop

Because Gate A is **3/4**, the frozen plan requires an immediate generated-runtime stop. Actual downstream counts are exactly Gate B `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` **0/1**, selector426 **0/426**, and benchmark **0**. No S5, selector426 or selector427 publication/acceptance credit is granted by this EXEC turn.

## 4. Immutable postflight and artifact authority

Package, packaged-source and derived execution-view byte+mode censuses are identical before/after Gate A. Retained fixture hashes remain exact. Runtime receipts exist outside the immutable package/source trees. The result artifact is `10526001047`, provider SHA-256 `50ca965d0f8bd8d94a17f5a15e95bee9817abc2f1804306ebdaa9db95072895d`; the log artifact is `10525856300`, provider SHA-256 `f7c83cf5590001c9dcbca64dd41ac806e2444541866aaabf7afc2ae3df38557a`.

One diagnosed orchestration attempt, run `35289012154`, is provenance only: immutable preflight completed, then the temporary runner failed with `stem: unbound variable` before any generated Directional runtime. Its result/log artifacts `10525886078 / 10525881217` do not carry semantic evidence. The corrected temporary runner hashes to `a794436ed37c06d600ee6adf3e61fae745036f03a36ee0317ae51e3378425054`; the fresh run above is the sole TB12-R3 semantic runtime authority.

## 5. Regression/accounting disposition

`M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains **OPEN / REVIEW REQUIRED / NON-STABLE**. TB12-R3 proves three CB16 ordering/oracle controls but falsifies the fourth frozen Gate-A acceptance control before the unchanged S5 focus can run. EXEC does not assign a new root-cause class or stable event because the failing control is newly authored correction authority and has no accepted-green baseline; independent Review must determine whether this is continuation/refinement of the existing `RP-07` candidate or a test-authority issue.

Accepted runtime authority remains package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. `M4-CP-SCALE-DEFN-OBS-04` remains open: genus-two topology is proved, while admissible atlas/A3 authority remains unproved.

Exact successor is runtime-free `M4-CP-SCALE-TB12-R3-REV`. No Code + Build correction, runtime retry, selector execution, benchmark, S5 credit or candidate promotion may precede Review.

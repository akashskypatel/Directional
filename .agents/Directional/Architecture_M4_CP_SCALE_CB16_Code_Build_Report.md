# M4-CP-SCALE-CB16 Code + Build Report

**Turn:** `M4-CP-SCALE-CB16`
**Disposition:** **COMPLETE / SEMANTIC CORRECTION COMPILED / RUNTIME-FREE / ARTIFACT-ONLY RETRY OWED**
**Semantic implementation commit:** `0b9e3e8706322fad0b1b3f3a678d208a086ba365`
**Compiled source:** `a8df4406ebd1a5252f0be20b1f1e65a2cb453ee9`
**Compile run/job:** `35283852353 / 105411733012`
**Candidate artifact:** `10523132151` (`m4-cp-scale-cb16-result-35283852353`)
**Mandatory successor:** `M4-CP-SCALE-TB12-R3-EXEC`

## 1. Scope and implementation

CB16 stayed within the reviewed semantic boundary. Commit `0b9e3e87...ba365` changes only:

- `src/authority/FieldTransportAtlas.cpp`
- `tests/FieldTransportAtlasTests.cpp`

`order_cycle_steps` still sorts directed support by `(fromFace,toFace,sourceEdge)` and rejects duplicate outgoing origins. It now keeps one global used-edge set, starts each component at the least unused directed edge, follows unique successors until that component closes, then repeats until every support edge is consumed exactly once. Missing successors, pre-closure reuse, invalid directed adjacency and unconsumed/open support remain fail-closed. Existing one-component rows retain the same start rule and step order.

The independent atlas validator no longer validates the producer's emitted contiguity as its expectation. It independently derives the canonical closed-component decomposition from sparse-row support and adjacency and compares the producer's flattened order to that derivation. Focused controls cover multiple closed components and component-order tamper, single-component sequence preservation, open/duplicate-origin/invalid-adjacency tamper, and the retained genus-two atlas.

Frozen surfaces were not changed: `dual_cycles`, cycle coefficients/kind/turning lifts, retained genus-two fixture/rawfield/metadata, the S5 focus, CMake/benchmark semantics and selector426. No selector427 was published.

## 2. Compile/package evidence

The mandatory reusable compile built all eight standard targets from exact source `a8df4406...53ee9` under Release/static/PRE_TEST with GMP/GMPXX and no generated runtime. Preflight and build exit codes are `0 / 0`; all recorded source-status snapshots are empty.

- artifact provider/local ZIP SHA-256: `2962e2c0e4ea6dc9294d159c19c78543ddf173b5ff342436c9e89e26b4410f73`
- self-manifest: **28/28 verified**, SHA-256 `61bf5fcabfb8a41f2de32b0ea7e1b3059579ecdd5ac07862cb657c46eedd3db5`
- packaged source archive SHA-256: `4be61bb45a1f925c4cff0cf5b6cc0b263948417b6271c43a919808f5c5133e99`
- command boundary: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`
- authoritative link evidence contains `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`
- authority-kernel executable: mode `0755`, SHA-256 `78fd5072420e5fa2b92c9d86aacf989cb2718c48e2f66550e14602f083efdb27`
- producer executable: mode `0755`, SHA-256 `18a24349093397ac8ea7bd3074e98defda55a26bf602c359fa2716421da9d6ee`

Compiled targets are exactly `directional_core`, `directional_pipeline`, the four surface-cell test binaries, `directional_compiled_api_tests`, and `directional_benchmarks`.

## 3. Frozen-authority verification

The exact packaged source re-hashes selector426 to **426 LF rows** at `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; its exact first425 prefix remains `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`. Retained S5 fixture hashes remain:

- OBJ `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`
- raw field `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`
- metadata `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`

No Directional binary was executed in CB16. The existing accepted runtime authority therefore remains package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

## 4. Disposition

CB16 corrects the reviewed representation owner of `M4-CP-SCALE-TB12-R1-EXEC-CAND-01` at build authority only. Runtime closure, S5 credit, candidate promotion and any selector publication remain unclaimed.

The successor name follows the existing TB12 retry chain: R1 validated retained-fixture recovery, R2 reproduced the diagnostic discriminator, and this correction is therefore consumed by **`M4-CP-SCALE-TB12-R3-EXEC`**. That Test + Benchmark turn must consume artifact `10523132151` unchanged, execute the new component-order controls first, then the unchanged S5 focus, and only if those gates are green execute selector426. Mandatory independent Review follows any semantic runtime result before S5/selector publication or candidate promotion.

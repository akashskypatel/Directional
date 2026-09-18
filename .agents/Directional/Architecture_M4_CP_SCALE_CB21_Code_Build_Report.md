# M4-CP-SCALE-CB21 — Code + Build Report

**Turn:** `M4-CP-SCALE-CB21`
**Type:** Code + Build only
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Predecessor:** `M4-CP-SCALE-TB12-R7-REV`
**Evidence source:** `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1`
**Runtime boundary:** **no generated Directional runtime executed**

## 1. Result

CB21 is **IMPLEMENTED / COMPILE+PACKAGE GREEN / RUNTIME UNEXECUTED**.

The bounded R7 correction is implemented in exactly the two authorized semantic files:

- `src/authority/FieldTransportAtlas.cpp`
- `tests/FieldTransportAtlasTests.cpp`

The production path no longer treats a per-region relative `BoundaryLoop.turningLift` as the numeric authority for the global source-vertex singularity. Separating-feature owner eligibility and final reconciliation retain source-topology incidence, actual `BoundaryLoop` ownership/containment and stable authority identity, while the independently derived raw numerator remains the singularity's numeric fact.

No source-topology partition, cycle-ordering, same-region slit, source-boundary, fixture, selector, CMake or benchmark semantic was changed.

## 2. Product correction

`FieldTransportAtlas.cpp` removes only the two CB18 cross-domain equality checks:

- candidate eligibility no longer requires `cycle.turningLift == rawSingularity[vertex]`;
- final separating-owner reconciliation no longer requires `cycle.turningLift == numerator`.

The existing checks remain authoritative:

- global-interior prescribed singularity;
- separating-feature incident-region membership;
- in-range `BoundaryLoop` owned by the same topology region;
- callback visitation of the actual local boundary-loop vertex;
- deterministic minimum stable `(TopologyRegionId, FieldCycleId)` owner;
- exact-one-owner reconciliation;
- `FieldSingularityFact.indexNumerator` remains the raw global numerator;
- `BarrierAbsorbed`, zero origin ports and separating-feature diagnostics remain unchanged.

## 3. Independent regression control

`FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` retains its source-authority five-ring annulus setup and independently derived global target singularity. It now constructs the expected owner-region submesh from source authority, derives that region's boundary-cycle facts through the existing independent test oracle, and establishes **before atlas construction** that the eligible region-relative boundary lift differs from the target global singularity numerator.

That discriminator is non-vacuous: restoring the deleted equality would reject the subject before the expected successful ownership result.

The test also reverses source-face row storage, rebuilds source authority and requires the same stable owner region/cycle, proving the selected owner is canonical authority identity rather than insertion/storage order.

The semantic diff is **2 files, 177 insertions / 8 deletions**. No unrelated refactor or formatting change was introduced.

## 4. Frozen-byte preflight

The built source reproduces the frozen CP-SCALE bytes:

- selector426: **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- first425 prefix: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- `genus_two.obj`: `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
- `genus_two.rawfield`: `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
- `genus_two.fixturemeta.json`: `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No selector427 is published.

## 5. Compile/package evidence

Mandatory reusable compile run/job:

- run `35334247422`;
- workload job `105565353324`;
- exact requested source `ea7b15f53e5e92cb034c855d52c17eaa2d8928d1`.

All eight standard targets compile/link successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Result package:

- artifact `10542249210`, `m4-cp-scale-cb21-result-35334247422`;
- provider/local ZIP SHA-256 `a64352a9524c4f114865948bb84226a317eaa1affa2e7a7fcfeea62352c7ef6c`;
- root manifest SHA-256 `88e3f454c963af481df96b5fea4b5450b904c707a6dc5ad1f9299d87ae55611c`, **28/28 verified**;
- source archive SHA-256 `7a8c8f9c866dfc51580975d64e6dda5001291780e666d1491a6aee2a39a858e7`;
- six packaged executables mode `0755`;
- all recorded source-status boundaries clean;
- preflight/build exit `0/0`;
- `exactArithmeticBackend=GMP`, with authoritative `gmpxx` + `gmp` link evidence;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

Persistent compile log:

- artifact `10542353674`, `m4-cp-scale-cb21-log-35334247422`;
- provider/local ZIP SHA-256 `fb5d9a65b823b90086bf5ea9a1992487a92bb8da3f22c8ccbfaf57bedebd87a8`.

No generated test, benchmark, discovery, help/version or other Directional binary executed in CB21.

## 6. Authority and accounting

Compile success does **not** promote CB21 as runtime authority and does not by itself close `RP-01`.

Accepted M4 runtime authority remains TB11 package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owners **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. S5/A3 remain uncredited pending fresh immutable runtime plus Review.

CB21 candidate `10542249210` is therefore **COMPILE-PROVED / RUNTIME PENDING / NON-STABLE**.

## 7. Successor

Exactly one successor plan is frozen:

`Architecture_M4_CP_SCALE_TB12_R8_Artifact_Only_Test_Benchmark_Plan.md`

R8 consumes artifact `10542249210` unchanged and executes:

```text
Gate A0 5 -> Gate A 4 -> S5 1 -> selector426 426 only if all ten focused rows are green
benchmark 0
exact immutable postflight required
```

R8 is a separate Test + Benchmark turn. It may not configure, compile, relink, repair or mutate the packaged source/tests/fixtures/selectors.

## 8. Recovery/process note

At resume, the retained local semantic worktree was based on an older snapshot and still appeared dirty in the two authorized files. A fresh verified source snapshot at current branch authority proved both local file bytes already matched the pushed branch; the preservation patch therefore correctly failed `git apply --check` against current source as already applied. No local-only semantic work remained to preserve or reapply.

The original turn-local tool-call ledger was lost across context compaction. Per policy, its exact total is **PARTIAL/UNKNOWN** rather than reconstructed by spending additional calls.

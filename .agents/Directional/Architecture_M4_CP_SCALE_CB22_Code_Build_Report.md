# M4-CP-SCALE-CB22 — Code + Build Report

**Turn:** `M4-CP-SCALE-CB22`
**Type:** Code + Build only
**Predecessor:** `M4-CP-SCALE-TB12-R8-REV`
**Semantic source:** `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`
**Result:** **IMPLEMENTED / COMPILE+PACKAGE GREEN / ZERO GENERATED DIRECTIONAL RUNTIME**

## 1. Scope and source correction

CB22 repairs only the invalid direct-test authority identified by R8 Review. The semantic commit changes exactly one file:

- `tests/FieldTransportAtlasTests.cpp` — 166 insertions / 184 deletions.

No production source, CMake, benchmark, selector, retained fixture, or frozen definition semantics changed.

`FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` now uses the accepted producer-consistent skew four-triangle fan rather than a constant planar field with a hand-authored transition and `+1/-1` singularity pair. The repaired control establishes before product construction:

- center source vertex `4` is globally interior and the sole interior producer-derived singularity with numerator `+1`;
- hard edges `(1,4)` and `(3,4)` partition the fan into exactly two source-topology regions with face sets `{0,3}` and `{1,2}`;
- both target hard edges are separating boundaries and zero are same-region slits;
- the stable minimum incident `TopologyRegionId` is the expected owner;
- the independently reconstructed two-triangle owner region has Euler characteristic `1`, zero local interior vertices, one boundary loop containing target vertex `4`, and independently derived `BoundaryLoop.turningLift == 4`;
- the decisive discriminator is therefore non-vacuous: relative owner lift `4 != +1` global singularity numerator;
- the product must publish the separating owner, `BarrierAbsorbed`, zero origin attachments, one separating-feature-bound diagnostic and zero slit-bound diagnostics.

The storage-order control reverses source-face rows, maps the baseline per-face cross directions by `SourceFaceTopologyKey`, re-runs the accepted cross-field producer to regenerate matching/effort/singularities, and requires the same stable owner/cycle identity and `4 != +1` behavior. No transition row or singularity is copied or hand-edited.

## 2. Frozen authority reverified

From the exact semantic source packaged by the compile:

- selector426 remains **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- its first425 prefix remains SHA-256 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- retained genus-two OBJ/rawfield/metadata remain respectively:
  - `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
  - `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
  - `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No selector427 exists or is authorized.

## 3. Compile/package evidence

Mandatory compile run/job:

- run `35351112557`;
- workload job `105619259327`;
- exact semantic source `ec348a1d13f96764da5674b66a3ce314a4a8c2cb`;
- result artifact `10548849094`, `m4-cp-scale-cb22-result-35351112557`;
- provider/local ZIP SHA-256 `f63c20ab184e78fa0cabcd89df7844a6fdaeacdba31691f3d51b39fec9bb1aa5`;
- compile-log artifact `10548709112`, provider SHA-256 `f66ef4ff03ed882f423835c196f1c2991de94d6b48058201cfda2c03ff86fb51`;
- packaged source archive SHA-256 `7f1639a93e7e7cec72b9150e7971363522fe7cbbf2db2a9e0d281a474f29accd`;
- root self-excluding 28-entry `SHA256SUMS` SHA-256 `01183587ecef192a1343d24692fc4cee749a023e6be8f6b89078f0c9f281b3c8`; all 28 entries verify.

All eight required targets compile/package GREEN:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Preflight and build exit codes are both `0`. Source status receipts before/after configure/build/final are empty. Package command-boundary metadata records:

- `runtimeExecution=false`;
- `turnBoundary=Code+Build-only`;
- `exactArithmeticBackend=GMP`;
- `semanticContracts=compiled-not-executed`.

GMP evidence names `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`, and the authoritative test link command contains both libraries. Six packaged executables retain mode `0755`; the two static libraries retain mode `0644`. No generated Directional test, benchmark, discovery/list/help/version, CLI, or custom-input process executed in CB22.

## 4. Disposition

CB22 satisfies its Code + Build acceptance boundary. The old hand-authored radial transition and companion singularity are removed from the direct owner control, the producer-consistent preconditions and independent `4 != 1` discriminator are present, the storage-order control preserves semantic field authority, and all required compile/package evidence is GREEN.

This is compile-time evidence only. `M4-CP-SCALE-TB12-R8-EXEC-CAND-01 / RP-02` is **CORRECTED IN SOURCE / RUNTIME RE-PROOF PENDING / NON-STABLE** until the corrected direct row executes in R9. The production genus-two `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` remains OPEN; S5/A3 remain uncredited.

Accepted runtime authority therefore remains TB11 package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owners **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt remains **5**.

## 5. Exact successor

Freeze candidate artifact `10548849094` and execute exactly `M4-CP-SCALE-TB12-R9-EXEC` under `Architecture_M4_CP_SCALE_TB12_R9_Artifact_Only_Test_Benchmark_Plan.md`:

```text
Gate A0 5 -> Gate A 4 -> S5 1 -> selector426 426 only if all ten focused rows are green
benchmark 0
exact immutable postflight required
```

R9 is immutable artifact-only. Any valid semantic result routes to mandatory `M4-CP-SCALE-TB12-R9-REV`; EXEC cannot promote the package, close/reprice product `RP-01`, grant S5/A3 credit, or publish selector427.

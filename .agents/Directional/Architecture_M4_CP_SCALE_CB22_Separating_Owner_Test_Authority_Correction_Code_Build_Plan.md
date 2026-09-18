# M4-CP-SCALE-CB22 — Separating-Owner Test-Authority Correction Code + Build Plan

**Turn:** `M4-CP-SCALE-CB22`
**Type:** Code + Build only
**Predecessor:** `M4-CP-SCALE-TB12-R8-REV`
**Root cause owned:** `M4-CP-SCALE-TB12-R8-EXEC-CAND-01 / RP-02 TEST_AUTHORITY_COVERAGE_GAP`
**Production semantics:** frozen
**Runtime boundary:** no generated Directional runtime

## 1. Objective

Repair only the direct regression fixture `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` so it exercises CB21's separating-owner contract with a producer-consistent `CrossFieldResult`.

R8 recovery-proved the CB21 target owner at source vertex 8, then failed on a different hand-authored companion vertex 16. The current test creates constant planar face directions but manually injects one nonzero edge matching/effort and manually declares a `+1/-1` singularity pair. That `CrossFieldResult` is not certified by the accepted field producer and its `-1` companion exposes four branch classes where its handwritten numerator demands five.

CB22 must remove that invalid test authority. It must **not** change `FieldTransportAtlas` or weaken the port-class validator.

## 2. Authorized semantic files

Exactly one file may change semantically:

1. `tests/FieldTransportAtlasTests.cpp`

`tests/support/SkewSingularFieldWitness.h` is reused unchanged. Production source, CMake, benchmarks, fixtures, selectors and frozen definitions are not authorized semantic edits.

## 3. Replacement fixture — exact construction

Replace the five-ring/manual-transition subject inside `SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` with the already accepted producer-consistent skew fan authority:

```text
mesh = make_skew_four_triangle_fan()
target source vertex = 4
hard features = {(1,4), (3,4)}
field = producer-derived from the skew per-face directions
```

### 3.1 Field authority

Use `make_skew_index_one_singularity_field(mesh, field)` or the exact accepted producer path it encapsulates:

- author only primary/secondary per-face cross directions;
- derive matching, effort and singularity rows through `CartesianField`, `make_raw_cross_field` and `finalize_cross_field_result`;
- retain the helper's independent transition measurement checks;
- retain its independent center-cycle proof;
- require exactly one interior singularity, source vertex `4`, numerator `+1`.

Delete the current test's manual radial-edge `matching/effort` mutation and the manual `[+1,-1]` singularity array. Do not replace them with a different handwritten singularity.

### 3.2 Separating-feature authority

The two hard radial edges `(1,4)` and `(3,4)` remove opposite face adjacencies in the four-face fan. The direct test must independently establish before atlas construction:

- exactly two source topology regions;
- the two region face sets are `{0,3}` and `{1,2}` modulo stable region-ID assignment;
- vertex `4` is globally interior;
- both hard edges are incident to vertex `4` and separate distinct topology regions;
- at least two incident regions compete for ownership;
- zero target hard edges are same-region local barriers/slits.

The expected owner is the minimum stable incident `TopologyRegionId`; no source-face storage order may select it.

### 3.3 Independent lift/index discriminator

Reconstruct the expected owner-region local mesh from `SourceTopologyRegions`, as CB21 already does, and derive its cycle facts through the existing independent test oracle.

For this two-triangle region the test must establish, before product construction:

- Euler characteristic `1`;
- zero local interior vertices;
- exactly one boundary loop;
- target vertex `4` lies on that loop;
- independently derived owner `BoundaryLoop.turningLift == 4`;
- producer-derived global target numerator is `+1`;
- therefore `turningLift != indexNumerator` non-vacuously.

If the independent oracle does not produce this exact `4 != 1` discriminator, **STOP**. Do not edit product code, relax the assertion or choose another handwritten value merely to get a mismatch.

## 4. Required product assertions

On the baseline subject, `FieldTransportAtlas::make(...)` must compile against assertions requiring:

- successful atlas construction;
- exactly one singularity fact for target vertex `4`;
- numerator `+1` retained from producer authority;
- one topology-region owner equal to the independently chosen stable minimum;
- one in-range `BoundaryLoop` local cycle owned by that region;
- owner cycle turning lift equals independently derived `4` and differs from global numerator `+1`;
- `PortPolicy::BarrierAbsorbed`;
- zero origin attachments for the target;
- separating-feature-bound diagnostic count exactly one for the owner region;
- slit-bound diagnostic count zero;
- no unbound target singularity.

Do not weaken `SingularityPortClassCountMismatch`, `4-index`, owner exclusivity, incidence validation or `BarrierAbsorbed` semantics.

## 5. Canonicalization control — preserve semantic field under face-row permutation

Retain the CB21 storage-order control, but make its field authority producer-consistent.

1. Reverse source face-row storage.
2. Rebuild source topology authority from the same hard-edge topology keys.
3. Map each baseline face's primary/secondary directions to the permuted row by `SourceFaceTopologyKey`, so the **same semantic cross field** is preserved.
4. Re-run the accepted cross-field producer on those remapped directions to regenerate matching, effort and singularities for the permuted mesh. Do not copy or hand-edit transition rows.
5. Independently require the same sole interior singularity at source vertex `4`, numerator `+1`.
6. Build the atlas and require the same stable owner region/cycle identity, `BoundaryLoop`, relative lift `4`, `BarrierAbsorbed` and zero origin ports.

Calling the row-index-driven skew helper unchanged after reversing rows is insufficient because it would assign different face directions to source-face topology and change the subject rather than only storage order.

## 6. Generalization and counterfactual checks

The repaired test must fail for each plausible regression class it is meant to guard:

- restoring CB18's `turningLift == global numerator` eligibility/reconciliation equality fails because `4 != 1`;
- choosing an incident owner by iteration/storage order fails the face-row permutation control;
- reverting to same-region-slit-only ownership leaves the separating target ownerless;
- emitting origin ports for the separating target violates `BarrierAbsorbed`/zero-attachment assertions;
- fabricating matching/effort/singularity rows instead of using the producer fails the fixture precondition assertions.

The test is not a negative-index port-class test. Do not add unrelated negative-singularity coverage in CB22.

## 7. Frozen semantics

Do not change:

- `src/authority/FieldTransportAtlas.cpp`;
- source-topology region partition semantics;
- cycle ordering / `dual_cycles`;
- same-region slit ownership;
- source-boundary singularity semantics;
- singularity port-class arithmetic or attachment partitioning;
- retained genus-two OBJ/rawfield/metadata;
- S5 production witness;
- selector426 or first425 bytes;
- CMake/benchmark semantics;
- accepted TB11 authority.

No selector427 publication is authorized.

## 8. Code + Build verification

Compile/package all standard targets using `.github/workflows/agent-compile-reusable.yml` with GMP/GMPXX and `runtimeExecution=false`:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Before compile/package re-prove unchanged bytes:

- selector426: 426 LF rows, `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- first425: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- genus-two OBJ/rawfield/metadata: `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3 / 7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e / 22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

Generated tests, benchmarks, discovery/list/help/version or any other Directional binary must not execute in CB22.

## 9. Fresh R9 Test + Benchmark plan required on GREEN

If compile/package succeeds, freeze one immutable candidate and author exactly one fresh `M4-CP-SCALE-TB12-R9-EXEC` artifact-only plan:

```text
Gate A0 5 -> Gate A 4 -> S5 1 -> selector426 426 only if all ten focused rows are green
benchmark 0
exact immutable postflight required
```

Gate A0 row1 remains the corrected separating-owner control. R9 may reach S5 only after A0 5/5 and Gate A 4/4. A semantic RED stops immediately and routes to mandatory `M4-CP-SCALE-TB12-R9-REV`; EXEC cannot repair, promote, grant S5/A3 credit or publish selector427.

## 10. STOP conditions

Stop and preserve evidence rather than broadening scope if:

- the producer-consistent skew field does not independently certify exactly one interior `+1` singularity at center vertex `4`;
- hard edges `(1,4)` and `(3,4)` do not independently establish the two-region separating-feature precondition;
- the independently reconstructed owner region does not yield the exact relative boundary lift `4 != +1`;
- preserving the semantic field under source-face-row permutation requires production changes;
- a compile failure requires editing production, CMake, benchmark, selector or retained fixture semantics;
- evidence shows `SingularityPortClassCountMismatch` or `4-index` is wrong for a producer-valid field rather than this invalid direct fixture.

Any such finding returns to Review/definition as appropriate. Do not convert it into an opportunistic product fix inside CB22.

## 11. Acceptance for Code + Build closeout

CB22 closes only when:

- semantic changes are test-only and confined to `tests/FieldTransportAtlasTests.cpp`;
- the old handwritten radial transition and companion singularity are absent;
- producer-consistent field preconditions, `4 != 1` discriminator and topology-preserving row-permutation control are present in source;
- all eight standard targets compile/package GREEN under GMP/GMPXX;
- package evidence says `runtimeExecution=false`;
- frozen selector/fixture hashes remain exact;
- one fresh R9 artifact-only plan is tied to the exact compiled package;
- accepted runtime authority remains TB11 package `10473134357` / selector426 **426/426** until R9 + Review say otherwise.

# M4-CP3-CB4-R2 Code + Build Plan — row400 canonical face-coordinate non-vacuity recovery

**Status:** AUTHORITATIVE / FROZEN BY `M4-CP3-TB2-PLAN` / TEST-AUTHORITY ONLY / RUNTIME-FREE PLAN
**Turn:** `M4-CP3-CB4-R2`
**Evidence reviewed:** `M4-CP3-TB2-REV`, finding `M4-CP3-TB2-REV-CAND-01`
**Accepted runtime authority:** package119 / selector394 **394/394**
**Blocked candidate:** package120 / selector403, mechanically **403/403** but unpromoted
**Normative authority:** `Architecture_M4_DEFN_Frozen_Definitions.md` §17.12
**Exact next after this plan:** `M4-CP3-CB4-R2`
**Future runtime boundary:** `M4-CP3-TB2-R1-EXEC`, then `M4-CP3-TB2-R1-REV`

## 1. Objective

Repair only the test-authority defect identified by TB2 review: selector row400 currently contains a noncanonical-looking `sourceRow` that does not participate in construction of the exact face point. The corrected identity must make source-row order behaviorally relevant and prove that a point originating from a real noncanonical source-face row reaches the published exact-path surface with barycentric components associated with canonical `SourceFaceTopologyKey::vertices()` order.

This turn is not permission to change production A2b/A3 semantics. No product defect was established. A3→A4 cutover remains deferred.

## 2. Frozen scope

### 2.1 Allowed semantic change

Change only the existing row400 definition in:

```text
tests/FieldAlignedCurveNetworkTests.cpp
```

A test-local helper in that same file is allowed only when needed to independently derive the expected canonical coordinate tuple from vertex identity. Such a helper is oracle/test setup; it must not construct the production subject or duplicate a production algorithm wholesale.

### 2.2 Forbidden changes

Do not change:

- `src/**`, `include/**`, production pipeline behavior or public API;
- CMake/test ownership;
- fixtures outside `tests/FieldAlignedCurveNetworkTests.cpp`;
- selector403 bytes, identity, order, name or hash;
- accepted selector394 bytes;
- A4 consumption, target-derived subdivision, `HardRailPairKey`, or shared-breakpoint cutover behavior;
- any assertion merely to accommodate current output.

Selector403 must remain exactly **403 rows** at SHA-256
`e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; its first394 must remain byte-identical to accepted selector394 at
`6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.

## 3. Mandatory derivation guard before mutation

Before editing test source, re-open the exact source and identify the existing production path that converts or carries a face-interior point from source-face-row-attached data into the canonical `ExactSourceFacePoint` representation consumed by A2b exact-path publication.

The guard must prove all of the following from current source:

1. an actual `Eigen::MatrixXi`/`TriMesh::F` source row can have vertex order different from its canonical `SourceFaceTopologyKey`;
2. the chosen production fixture/path reaches a face-interior exact point whose three exact barycentric components are all distinct;
3. the downstream published point binds those components to canonical topology-key vertex order rather than raw row positions;
4. the row400 test can observe that published point without adding a product-only testing API.

**STOP-GUARD:** if no existing production path/fixture can satisfy those four facts without changing product source, public API, selector identity, or unrelated fixtures, stop `M4-CP3-CB4-R2` before mutation and return to review. Do not invent a mapping helper in production merely to make the test possible.

## 4. Required row400 correction

Keep the exact identity:

```text
ExactSourcePath.FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
```

The corrected scenario must satisfy all of these criteria:

1. **Actual noncanonical row.** Build/use a real source mesh face row whose ordered vertex IDs differ from `SourceFaceTopologyKey::vertices()` for that face. The row must be consumed by the chosen production fixture/path, not stored only for an assertion.
2. **Distinct coordinate discriminator.** The face-interior point must have three distinct exact barycentric components. If explicit fixture values are used, values equivalent to `1/2, 1/3, 1/6` are suitable. Equal or symmetric components are forbidden because they hide permutation errors.
3. **Independent expected remap.** Derive the expected canonical tuple by matching each raw-row vertex identity to its position in the canonical topology key. For the illustrative raw row `[2,0,1]` with raw-row weights `[1/2,1/3,1/6]`, the canonical `[0,1,2]` tuple is `[1/3,1/6,1/2]`. The expected tuple must not be copied from the production result.
4. **Real production subject.** Obtain the observed exact face point from the existing production A2a/A2b path selected by the derivation guard. Do not call `canonical_exact_source_face_point(face, expectedCanonical)` as the subject under test; that only checks a representation helper after the remap has already happened.
5. **Falsifiability assertions.** Assert that raw row order differs from canonical order, raw coordinate tuple differs from expected canonical tuple, the published face key is canonical, and the published barycentric tuple equals the independently derived canonical tuple. A positional/no-remap or wrong-permutation implementation must fail.
6. **Canonical validity.** Retain the canonical exact-point/path validity assertion appropriate to the production output.

A detached `sourceRow`, a raw-vs-canonical inequality unrelated to construction, or comparing an already-canonical array to itself is an immediate plan violation.

## 5. Success-visible receipt

After all row400 semantic assertions pass, emit one deterministic live receipt derived from the actual fixture/output, for example:

```text
M4_CP3_EXACT_PATH_RECEIPT ordinal=400 sourceRow=<v0,v1,v2> canonicalFace=<v0,v1,v2> sourceWeights=<a,b,c> canonicalExpected=<a,b,c> observed=<a,b,c>
```

Requirements:

- values come from live fixture/result objects, not a hard-coded success string;
- all three source weights are distinct;
- source row and canonical face arrays differ;
- `canonicalExpected` differs positionally from `sourceWeights` for the chosen permutation;
- `observed == canonicalExpected` is already enforced by assertions before emission;
- formatting is deterministic across fresh processes.

This receipt is evidence support, not a substitute for the assertions.

## 6. Compile/package verification — Code + Build only

After the test-only correction is preserved as an exact patch and committed, compile only through the mandatory reusable GitHub Actions compile workflow with GMP/GMPXX authority. No local build and no Directional runtime is permitted.

Changed-owner preflight target:

```text
directional_surface_cell_producer_tests
```

Then compile/package the complete selector-owner surface without executing it:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

Require:

- changed-owner preflight compile exit `0`;
- complete package compile exit `0`;
- GMP/GMPXX verified on authoritative generated link command;
- clean source status;
- package-owned four selector-owner executables with archived executable mode preserved;
- recursive self-excluding manifest verifies completely;
- `runtimeExecution=false` and semantic contracts recorded as compiled-not-executed;
- selector403/first394 hashes remain exactly frozen.

Do not run GTest discovery/listing, any generated Directional binary, `ctest`, benchmark, CLI, fuzzer, help/version command or custom input during CB4-R2.

## 7. Future artifact-only validation — `M4-CP3-TB2-R1-EXEC`

The successor TB is not executed in CB4-R2. It must consume the immutable CB4-R2 package without rebuild or permission/content repair.

Frozen semantic process matrix:

```text
row400 focused pass A       1
row400 focused pass B       1
accepted selector394      394
cumulative selector403    403
-----------------------------
total                     799
```

Every row executes in a fresh exact-filter process. Required results:

- row400 pass A: **1/1 PASS** with exactly one live receipt;
- row400 pass B: **1/1 PASS**, same ordered verdict and byte-identical semantic receipt fields;
- accepted selector394: **394/394 PASS**;
- cumulative selector403: **403/403 PASS**;
- zero RED/SKIP/selection mismatch/timeout;
- selector403 owner totals remain **30 authority-kernel / 257 producer / 75 completion / 41 validation**;
- immutable package/source/execution-view pre/postflight and manifest verification pass.

TB must statically bind row400 to its packaged source definition and independently verify the receipt discriminator: actual source row != canonical key order, all source weights distinct, expected canonical tuple != raw tuple positionally, and observed tuple == independently derived canonical tuple.

No benchmark is applicable. Green execution alone does not promote the package; `M4-CP3-TB2-R1-REV` owns promotion/acceptance.

## 8. Carried obligation — do not confound this recovery

`M4-CP3-TB1-R1-REV-OBS-01` remains open. Region-incidence multiplicity weighting is structurally present but runtime evidence has only `[1,1,1]` multiplicities.

It is **not part of CB4-R2**. Assign it to the first test-authority turn after row400 recovery is independently accepted. The preferred owner is the later CP3 A3→A4 cutover test-source work if that turn already needs a suitable conformity fixture; otherwise schedule a dedicated bounded test-only turn before CP3 closure. It may not silently expire and may not be folded into CB4-R2 merely because both affect tests.

## 9. Stop conditions

Stop before or during CB4-R2 if:

- satisfying row400 requires production/public-API mutation;
- the chosen fixture does not organically produce a noncanonical raw row plus distinct interior barycentric components;
- the expected canonical tuple cannot be derived independently by vertex identity;
- row400 identity or selector403 bytes would need to change;
- a compile would require bypassing GMP, weakening assertions, changing unrelated fixtures, or running runtime work;
- any intended changed path falls outside `tests/FieldAlignedCurveNetworkTests.cpp` apart from turn documentation/control-plane files.

A stop is evidence for review, not permission to broaden the turn.

## 10. Planning disposition

No additional independent Review is requested before CB4-R2. TB2-REV already independently classified the defect and supplied the falsifier; this plan only freezes the smallest correction and its proof. The plan is therefore authoritative on completion of `M4-CP3-TB2-PLAN`.

Package119/selector394 remains accepted authority until a later reviewed candidate supersedes it. Package120 remains historical mechanically-green/unpromoted evidence. Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**.

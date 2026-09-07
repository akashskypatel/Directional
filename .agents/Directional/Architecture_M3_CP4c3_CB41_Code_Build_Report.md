# M3-CP4c-3-CB41 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 101 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Evidence source:** `14aa1368523580444929bc65cab0b65449240ec2`
**Authoritative compile run/job:** `34150409018 / 101831355500`
**Immutable result artifact:** `10029250324` / `cb41-result-34150409018`
**Result ZIP SHA-256:** `9af49dd6dd0278225e8373b76e68f74c2ec263129f2c18ed2229135d0c6a5c55`
**Persistent compile-log artifact:** `10029250820` / `cb41-log-34150409018`
**Compile-log SHA-256:** `8611ad75e51b037244f179739559f6cd2d42eb825543d143ebe5a619306f6e80`
**Packaged source archive SHA-256:** `f090d8f66d37f2d5f9c02e67a63a5c4c0c4db596a54341a9675c1b545052a6ec`

## 1. Scope and boundary

CB41 implements only Part IX / CX0-CX8 from `M3_CP4c_Frozen_Definitions.md`: derive exact region-boundary provenance from the existing face-walk orbit authority, scope `ClosedBeforeEnd` to unguaranteed boundaries, preserve the universal structural checks, and add measurement-only Euler multiplicity diagnostics. No Directional runtime, test, benchmark, discovery, CLI, help/version command, fuzzer, or custom input was executed in this turn.

TB35 remains the latest semantic runtime authority. CB41 establishes compiled package authority for the next artifact-only Test + Benchmark turn; it does not promote any runtime result.

## 2. Implementation result

### CX0-CX3 — one derived provenance authority

The implementation introduces typed `RegionBoundaryProvenance` with the only states needed by Part IX:

- `Unguaranteed`;
- `FaceWalkOrbit`.

`FaceWalkOrbit` is not stored as mutable region state. It is derived from the existing exact relation between the current ordered `region.boundary` and the authoritative `walk.orbits[orbit]`. This preserves the invariant that copying or mutating a region boundary cannot leave stale provenance behind.

Boundary validation now follows the frozen ordering:

1. resolve optional exact orbit provenance;
2. run the structural single-walk validator;
3. reject `ArcChainBroken` and `WalkNotClosed` for every boundary;
4. reject `ClosedBeforeEnd` only when provenance is `Unguaranteed`;
5. preserve the existing missing-orbit rejection after structural validation.

Therefore synthetic negative boundaries still exercise the structural oracle while a genuine face-walk orbit may revisit nodes without being falsely rejected merely because the walk revisits its start before the final occurrence.

### CX4 — protected tests and selector are unchanged

Static audit against frozen source `f0c56e4e6f6c33d2e266e575234d57b569562719`:

- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 prefix SHA-256: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- ordinal 312 test block SHA-256 before/after: `94724befba56ed27fe9e7fb08d73d6436bc4d95150e041bcda16fa87b48d0847` — byte-identical;
- ordinal 409 test block SHA-256 before/after: `ea574dab11f604fff1758c03c98d83604e8a0ce101e6a73ea9adb674230f004a` — byte-identical.

No selector, protected fixture, protected assertion, or test-order change was used to obtain compile success.

### CX5 — Euler evidence is measurement only

When production reaches `RegionEulerCharacteristicNotOne`, diagnostics now project the exact provenance and boundary multiplicity evidence required by Part IX:

- `regionBoundaryProvenance`;
- owning `regionBoundaryOrbit` when available;
- boundary arc occurrence count;
- distinct arc count;
- boundary node occurrence count;
- distinct node count;
- repeated-node occurrence count;
- start revisits before the final end occurrence;
- the existing `vertexCount`, `edgeCount`, `faceCount`, and `eulerCharacteristic`.

The Euler formula and disc acceptance are unchanged. CB41 makes no claim that the observed multiplicities imply a correction.

### CX6 — deferred surfaces untouched

CB41 does not alter the accepted 1-365 boundary, ordinal 398, carried 368/369/370/374 surfaces, source-face ownership semantics, partition authority, retired guards, or any other deferred product surface.

## 3. Exact semantic source change

Semantic commit: `14aa1368523580444929bc65cab0b65449240ec2` (`fix: derive region boundary certification from scoped orbit`).

The semantic commit changes exactly five intended files and no workflow file: **136 insertions / 14 deletions**. The change was staged and verified as an ordinary source patch before remote application; `git diff --check` passed and application against the exact frozen source succeeded cleanly.

## 4. Compile and package evidence

### 4.1 Invalid orchestration attempt — not evidence

Run `34150366902` ended in `startup_failure` before a compile job could establish evidence. The temporary caller granted `contents: read`, but the statically referenced reusable observer contains a nested branch-file job whose declared ceiling requires `contents: write` even when that job is skipped at runtime. This was a control-plane permission-ceiling defect, not a product/build result.

The correction changed only the **temporary caller's** permission ceiling to the union required by the reusable graph. No reusable-workflow permission or implementation was changed. The corrected marker was committed separately before the one diagnosed retry.

### 4.2 Authoritative compile

Authoritative run `34150409018` passed schema validation and invoked the durable `.github/workflows/agent-compile-reusable.yml` against the exact semantic source `14aa1368523580444929bc65cab0b65449240ec2`.

Compile contract and result:

- Release, static, out-of-tree, `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- GMP enabled and found from `/usr`;
- compile/link evidence contains both GMPXX and GMP;
- required preflight target `directional_core` returned exit `0`;
- full approved eight-target compile returned exit `0`;
- source status was clean before configure, after configure, after build, and at final packaging;
- `runtimeExecution=false` throughout.

Compiled/package targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_surface_cell_authority_kernel_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_compiled_api_tests`;
8. `directional_benchmarks`.

The package contains both static libraries and all six executable targets. `SHA256SUMS` contains 28 entries and independently verifies **28/28 PASS**. The package self-manifest excludes itself as required.

## 5. Accounting and authority after CB41

CB41 creates one new semantic package and no runtime event:

- runtime authority: unchanged at `M3-CP4c-3-TB35`;
- stable accounting: **45 events / 14 categories / 31 recurrences**;
- produced-witness debt: **5**;
- semantic package count: **101**;
- package101 evidence source: `14aa1368523580444929bc65cab0b65449240ec2`;
- package101 artifact: `10029250324`.

## 6. CX7-CX8 closeout and next boundary

Package101 is the immutable execution input for `M3-CP4c-3-TB36-EXEC`. The executable artifact-only plan is `Architecture_M3_CP4c3_TB36_Artifact_Only_Test_Benchmark_Plan.md`.

TB36 must fail closed on the frozen falsifiers: accepted 1-365 must remain 365/365 PASS; 312/409 and 390/393/404/406/407/408 must PASS; 368/369/370/374/398 remain carried RED; ownership remains 300/0/0. If 366/367 still fail `RegionBoundaryNotSingleWalk` with `ClosedBeforeEnd`, Part IX is falsified. If they advance to Euler, that confirms only the provenance correction and must publish the complete CX5 measurement set; it does not authorize an Euler fix.

**CB41 terminates here. TB36 is not executed in this turn.**

# M3-CP4c-3-CB42 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 102 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Evidence source:** `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`
**Authoritative compile run/job:** `34159743881 / 101858898702`
**Immutable result artifact:** `10032277517` / `m3-cp4c3-cb42-result-34159743881`
**Result ZIP SHA-256:** `ca33be401dba11b1007258bd127948e03168cf2cd42231307d54d506028dc5ee`
**Persistent compile-log artifact:** `10032277909` / `m3-cp4c3-cb42-log-34159743881`
**Compile-log SHA-256:** `f01f180730307e276d03be0b89fcae5e23a27ad2c083134af4a058136c7f3901`
**Packaged source archive SHA-256:** `84b2624f425d9870ff8079403a468bca41c584c139752e9f7e5e6b00758da42f`

## 1. Scope and boundary

CB42 implements only TB36-REV measures CY6.1-CY6.6: publish the source-submesh counts needed to discriminate the open Euler frontier, label the older boundary census as network-domain, flag its redundant node-occurrence count as derived, compile/package the exact source, and hand off to artifact-only TB37. It is **measurement only**. The Euler formula, region construction, disc acceptance, selector, ownership semantics, partition authority, deferred failures, and retired guards are unchanged.

No Directional runtime, unit test, benchmark, discovery/list/help/version command, fuzzer, produced binary, or custom input was executed in CB42. `M3-CP4c-3-TB36` remains the current valid semantic runtime authority until package102 is executed and adjudicated.

## 2. Implementation result

### CY6.1 — publish `B_int`, `X`, and the three exclusion causes

On the existing `RegionEulerCharacteristicNotOne` diagnostic path, production now publishes:

- `regionInteriorBarrierEdgeCount`: mandatory/cut source edges with exactly two incident faces and both faces in the region (`B_int`);
- `regionExcludedVertexCount`: all source-submesh vertices not present in `interiorVertices` (`X`);
- `regionExcludedMeshBoundaryVertexCount`;
- `regionExcludedBoundaryVertexCount`;
- `regionExcludedAllOwnedVertexCount`.

The exclusion split follows the same reasons that keep a source vertex out of `interiorVertices`: mesh boundary first, then `boundaryVertices`, with the remainder measuring failure of the `allOwned` condition. These values are diagnostic-only and do not participate in acceptance.

### CY6.2-CY6.3 — publish source-submesh boundary and full Euler census

CB42 derives the complete source-submesh vertex and edge sets from `region.sourceFaces` and publishes:

- `regionSubmeshBoundaryEdgeCount`: source edges with exactly one incident region face;
- `regionSubmeshBoundaryVertexCount`: distinct source vertices incident to those boundary edges;
- `regionVTotal`: total distinct source-submesh vertices;
- `regionETotal`: total distinct source-submesh edges;
- `regionChiFull = V_total - E_total + F`.

The existing reduced `vertexCount`, `edgeCount`, `faceCount`, `eulerCharacteristic`, and the formula that produces them are untouched. `regionChiFull` is observation only; no branch uses it to force χ to 1 or to accept/reject a region.

### CY6.4 — make the older census domain explicit

When the existing arc/node multiplicity census is present, the projected failure locus now emits:

- `regionBoundaryCensusDomain=NetworkGraph`;
- `regionBoundaryNodeOccurrenceCountDerived=true`.

The existing occurrence field is retained for compatibility but explicitly marked derived rather than presented as an independent source-submesh boundary measurement.

### CY6.5 — protected surfaces remain frozen

The required pre-implementation corpus grep found **no test-source assertion** of `RegionEulerCharacteristicNotOne`; occurrences were production/documentation authority only. No accepted test was changed to accommodate CB42.

Static protection checks remained byte-identical:

- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408-prefix SHA-256: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- ordinal 312 test block SHA-256: `94724befba56ed27fe9e7fb08d73d6436bc4d95150e041bcda16fa87b48d0847`;
- ordinal 409 test block SHA-256: `ea574dab11f604fff1758c03c98d83604e8a0ce101e6a73ea9adb674230f004a`.

CB42 does not alter 368/369/370/374/398, ownership, partition unification, sphere/saturation/folded-cone surfaces, finalize/contact logic, or any retired guard.

## 3. Exact semantic source change

Semantic/evidence commit: `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d` (`M3-CP4c-3-CB42: publish source-submesh Euler diagnostics`).

The semantic patch changes exactly five intended files and no workflow file: **148 insertions / 0 deletions**.

Work preservation preceded remote application:

- frozen source base `b7f7c651af597cae2d427157454c3c4d0bf78a69`;
- preserved patch SHA-256 `fac1c5bde17e6421f44a72c4d8841fc9fe568935374ffaef9ea127f18a21c85a`;
- diff-body SHA-256 `c50349b082282e518e84902151965f768066ed638fd3156be3f1df7a9b389db9`;
- Drive application run `34159647865` produced the exact semantic commit above.

`git apply --check` and `git diff --check` passed before application, and the resulting changed-path set was exactly the five intended files.

## 4. Compile and package evidence

Authoritative run `34159743881` passed caller/schema validation and invoked durable `.github/workflows/agent-compile-reusable.yml` against exact source `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`. The push event itself was a later temporary compile-trigger commit; package metadata independently records the semantic source and all source-status checkpoints are clean.

Compile contract and result:

- Release, static, out-of-tree, `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- GMP enabled and discovered from `/usr`;
- authoritative link evidence contains both `gmpxx` and `gmp`;
- preflight target `directional_core` exit `0`;
- full approved eight-target build exit `0`;
- clean source status before configure, after configure, after build, and at final packaging;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`.

Compiled/package targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_surface_cell_authority_kernel_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_compiled_api_tests`;
8. `directional_benchmarks`.

The package contains the two static libraries and six executable targets. `SHA256SUMS` verifies **28/28 PASS** and excludes itself.

## 5. Accounting and authority after CB42

CB42 creates one new semantic package and no runtime event:

- current semantic runtime authority: unchanged at `M3-CP4c-3-TB36`;
- stable accounting: **45 events / 14 categories / 31 recurrences**;
- produced-witness debt: **5**;
- semantic M3 package count: **102**;
- package102 evidence source: `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`;
- package102 artifact: `10032277517`.

No runtime result is promoted by this compile.

## 6. CY6.6 closeout and next boundary

Package102 is the immutable execution input for `M3-CP4c-3-TB37-EXEC`. The executable plan is `Architecture_M3_CP4c3_TB37_Artifact_Only_Test_Benchmark_Plan.md`.

Because CB42 is diagnostic-only, TB37's first hard requirement is **behavioral identity with TB36**: selector409 must remain 402 PASS / 7 RED with accepted 1-365 at 365/365, RED `[366,367,368,369,370,374,398]`, protected 312/390/393/404/406/407/408/409 PASS, and ownership 300/0/0. Ordinals 366/367 must remain at `RegionEulerCharacteristicNotOne` while publishing the complete CB42 measurement set.

TB37 then evaluates the already-frozen discriminator without correcting it:

- `X + B_int = 44` -> cancellation premise holds; χ=-3 is consistent with the full source submesh and the frontier moves to region construction;
- `X + B_int = 48` -> the region has χ=1 and the frontier is the certificate arithmetic/cancellation premise;
- any other value -> the new measurement split is internally inconsistent with the frozen derivation and requires review before a correction is planned.

**CB42 terminates here. TB37 is not executed in this turn.**

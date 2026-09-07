# M3-CP4c-3-CB43 Code + Build Report

**Status:** COMPLETE / COMPILE-GREEN / IMMUTABLE PACKAGE 103 / RUNTIME-FREE
**Canonical turn:** Code + Build
**Evidence source:** `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`
**Authoritative compile run/job:** `34167182718 / 101880462158`
**Immutable result artifact:** `10034608071` / `m3-cp4c3-cb43-result-34167182718`
**Result ZIP SHA-256:** `426622beb03208d2e6b0cc77479942a92f2aca9967e3bf6251f5034ac533008e`
**Persistent compile-log artifact:** `10034608470` / `m3-cp4c3-cb43-log-34167182718`
**Compile-log SHA-256:** `161bf115f8e8695527e7a9194c122024046b4a3f074f06a8490bfb50032a6bce`
**Packaged source archive SHA-256:** `1d4c59d8482ffc240f93119ea04e57541930241a73ff3bb8bdd4154f40fe5a28`

## 1. Scope and boundary

CB43 implements only DEFN-R6 Part X and the frozen **CZ7.1-CZ7.7** correction: certify each topology region from the whole-face source sub-mesh, preserve the older interior-only counts for their existing connectivity/diagnostic roles, publish the exact reduced-versus-full relationship needed by TB38, compile/package the exact semantic source, and hand the immutable package to artifact-only validation.

No Directional runtime, test, benchmark, generated discovery/list/help/version command, fuzzer, produced binary, or custom input was executed in CB43. `M3-CP4c-3-TB37` remains the current valid semantic runtime authority until package103 is executed and reviewed.

## 2. Implementation result

### CZ7.1-CZ7.2 — whole-source-submesh Euler certificate

The existing source-submesh accumulation is now performed before the Euler test. `GlobalTopologyRegionDiscCertificate` adds new `totalVertexCount` and `totalEdgeCount` fields, representing `V_total` and `E_total`, without repurposing `vertexCount` or `edgeCount`.

The region certificate now computes `chiFull = V_total - E_total + F` and stores that value in the existing `eulerCharacteristic`. The existing connectivity count and BFS inputs remain intact; `proves_disc_topology()` retains its contract.

### CZ7.3 — both withdrawn premise comments removed

Both DEFN-R6.5 sites were corrected: the header no longer states that boundary vertices cancel boundary edges, and the implementation no longer documents the withdrawn reduced-Euler premise. The replacement comments state what each count actually represents.

### CZ7.4 — per-region proof data is first-class and compiled

Before the Euler rejection branch, production emits one `M3_CP4AB_FRAGMENT_DIAG record=euler_certificate` record containing `X`, `E_one`, `B_int`, `fullMinusReduced`, `V_int`, `E_int`, `V_total`, `E_total`, `F`, `chiReduced`, and `chiFull`.

The implementation computes:

```text
fullMinusReduced = X - E_one - B_int
chiReduced = V_int - E_int + F
chiFull = V_total - E_total + F
```

This is the compiled observation surface required to discharge DEFN-R6.7 **per region**. CB43 does not claim the runtime discharge: `M3-CP4c-3-TB38-EXEC` must prove, for every emitted region on accepted ordinals 1-365, that the published equations hold and that either `fullMinusReduced == 0` or the identity remains accepted under the corrected certificate.

For the TB37 mechanical 366/367 region, the frozen prediction is `X=36`, `E_one=20`, `B_int=12`, `V_total/E_total/F=136/385/250`, hence `fullMinusReduced=4` and `chiFull=1`. TB38 owns the runtime check that the corrected branch actually advances past `RegionEulerCharacteristicNotOne`.

### CZ7.5 — ordering and semantic hash decision

The two new certificate fields are ordinary members of the defaulted certificate comparison, so certificate ordering intentionally includes `totalVertexCount` and `totalEdgeCount`. `global_topology_plan_hash` explicitly consumes both fields. This is intentional: the certificate's semantic identity includes the counted source-submesh cells, and corrected regions also publish a different `eulerCharacteristic`.

The required static grep found no test identity that pins a global-topology-plan hash literal. No compatibility bypass or legacy-hash preservation path was added.

### CZ7.6 — frozen selector/test surfaces and region construction

CB43 changes exactly two semantic source files and does not edit tests, fixtures, selectors, ownership/partition logic, region construction, 368/369/370/374/398 surfaces, or retired guards.

Static/package preservation checks:

- `tests/FieldAlignedCurveNetworkTests.cpp` SHA-256: `913752b8e869b310e2bcb4d0b81a06c4231acdf0470db4427952958de7b3583b` before and after;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- selector408 exact-prefix SHA-256: `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6`;
- artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- selector409 identity count: **409**.

Thus the accepted corpus and ordinal 312/409 test source are byte-identical at the Code + Build boundary. Runtime PASS is deliberately not claimed here.

## 3. Exact semantic source change

Semantic/evidence commit: `2fcde465b1de2e42a348d224f5165ce8b87e4fbe` (`fix: certify region Euler from full source submesh`).

The semantic patch changes exactly:

1. `include/directional/geometry/GlobalTopologyPlan.h` — **4 insertions / 2 deletions**;
2. `src/geometry/GlobalTopologyPlan.cpp` — **74 insertions / 45 deletions**.

Total: **78 insertions / 47 deletions**, with no workflow, test, fixture, selector, benchmark, or build-system semantic edit.

The preserved implementation patch was generated against pre-CB43 source `8038251fc04e041b9aceab4a9248d2fb394c4f26`, passed `git apply --check` and `git diff --check`, and has SHA-256 `bc84c2f642539f86c90d5bac89b6efcf987d5f7e9a5f1f8d26d5ff4d14e215fe`.

## 4. Compile and immutable package evidence

Authoritative compile run `34167182718` invoked durable `.github/workflows/agent-compile-reusable.yml` against exact semantic source `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`. The workflow event/head is later control-plane lineage; `metadata/source-commit.txt` inside package103 is the semantic build authority.

Compile/package contract: Release static out-of-tree PRE_TEST; GMP/GMPXX linked; `runtimeExecution=false`; `turnBoundary=Code+Build-only`; `exactArithmeticBackend=GMP`; `preflightCompile=true`; final source status clean.

Approved compile/link-green targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.

Package103 contains the two static libraries and six executable targets. Root `SHA256SUMS` verifies **28/28 PASS** and excludes itself; all six executables retain mode `0755`.

## 5. Accounting and authority after CB43

CB43 creates one new semantic package and no runtime event or recurrence:

- current valid semantic runtime authority: **unchanged at `M3-CP4c-3-TB37`**;
- TB37 result: selector409, **402 PASS / 7 RED**, accepted **365/365**, RED `[366,367,368,369,370,374,398]`;
- stable accounting: **45 events / 14 categories / 31 recurrences**;
- produced-witness debt: **5**;
- semantic M3 package count: **103**;
- package103 evidence source: `2fcde465b1de2e42a348d224f5165ce8b87e4fbe`;
- package103 artifact: `10034608071`.

No runtime result is promoted by this compile.

## 6. CZ7.7 closeout and next boundary

Package103 is the immutable execution input for `M3-CP4c-3-TB38-EXEC`. The executable plan is `Architecture_M3_CP4c3_TB38_Artifact_Only_Test_Benchmark_Plan.md`.

TB38 must execute all 409 identities, one fresh process per selector identity, with accepted ordinals 1-365 first and no benchmark execution. The hard stop conditions remain accepted **365/365** and ordinals **312/409 PASS**. It must also discharge the per-region DEFN-R6.7 equations from the new `euler_certificate` records.

For ordinals 366/367, remaining at `RegionEulerCharacteristicNotOne` under the full source-submesh count is a correction failure. Passing the Euler check and then failing at a later stage is a **new frontier**, not a CB43 regression. The separately owned 368/369/370/374/398 surfaces are not owned by this correction and must be reported separately if they move.

**CB43 terminates here. TB38 runtime is not executed in this turn.**

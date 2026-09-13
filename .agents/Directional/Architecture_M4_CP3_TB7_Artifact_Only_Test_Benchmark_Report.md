# M4-CP3-TB7 Artifact-Only Test + Benchmark Report — fail-fast RED at accepted selector403 ordinal 211

**Turn:** `M4-CP3-TB7-EXEC`
**Status:** COMPLETE / FAIL-FAST RED / REVIEW REQUIRED
**Turn type:** Test + Benchmark / immutable artifact-only execution
**Candidate semantic source:** `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`
**Candidate package:** artifact `10305678151`, SHA-256 `543fd253bf04bde38f16aac8c33a05447bf515f37027a077f6014ff13957a629`
**Accepted entering authority:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Mandatory successor:** `M4-CP3-TB7-REV`

## 1. Execution disposition

Authoritative artifact-only run/job `34721325716 / 103627645766` consumed the immutable CB9 package without rebuild, repair, discovery, fixture mutation, or selector mutation. Preflight completed before Directional runtime; frozen fail-fast terminated on the first cumulative RED; postflight then completed.

- ordinal138 compatibility discriminator: **2/2 PASS** in fresh exact-filter processes;
- row408 torus occurrence-domain discriminator: **2/2 PASS** in fresh exact-filter processes;
- rows404-407 controls: **8/8 PASS** in eight fresh exact-filter processes;
- selector403: ordinals **1-210 PASS**, ordinal **211 RED**;
- selector403 ordinals 212-403 and selector408 cumulative execution: **not reached** by the frozen fail-fast rule;
- total generated semantic processes: **223** = **222 PASS / 1 RED / 0 SKIP / 0 crash / 0 timeout / 0 selection mismatch**;
- every generated process selected exactly one expected identity;
- `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `benchmark_execution=false`, `generated_discovery=false`, `package_repair=false`, `source_test_fixture_selector_mutation=false`.

This EXEC turn records runtime facts only. It does not classify the ordinal211 failure, promote the candidate, change accepted runtime authority, update stable-event accounting, or prescribe a repair.

## 2. Immutable package and selector authority

Preflight and postflight preserved the frozen package boundary:

- artifact ID `10305678151`, provider/download digest exactly `543fd253bf04bde38f16aac8c33a05447bf515f37027a077f6014ff13957a629`;
- packaged semantic source exactly `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`;
- root package manifest remains **28/28 verified** from CB9 authority;
- packaged source-status snapshots remain empty;
- GMP/GMPXX evidence and compile metadata remain present with `runtimeExecution=false`;
- selector403 remains 403 LF identities at `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- selector408 remains 408 LF identities at `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`, with the frozen 403-row accepted prefix unchanged;
- postflight reports `package_census_equal=true`, `source_census_equal=true`, and `execution_view_census_equal=true`.

The result ledger SHA-256 is `d5116d08e4cc08be1d20877008963d04795d7c7dea23a55d725c6da1f22c690e`. The result bundle itself is SHA-256 `c9993798e8ce4d30db20beb8b96d219c4d48618cc50b4d8c18838ea76f682165`; the log bundle is SHA-256 `2ecd20e9b2e7eccffb20fd9c52c45b34579de274a57ec89c282ff582700b130e`.

## 3. CB9's two-sided compatibility obligation is mechanically green

Both fresh executions of accepted selector403 ordinal138

`SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`

PASS. The focused process logs retain the deterministic one-face-disc support receipts and complete normally. Mechanically, the CB9 candidate therefore no longer reproduces TB6's ordinal138 RED at the frozen exact-filter identity.

Both fresh executions of row408

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

also PASS. Each preserves the 144-face torus support receipt with the cut support Euler characteristic `1` versus whole-source Euler characteristic `0`. Rows404-407 PASS twice as well. Thus the exact focused discriminator set that CB9 was required to protect is **12/12 PASS**.

EXEC does not infer from these PASSes whether CB9 is promotable. The cumulative accepted selector remains controlling.

## 4. Earliest cumulative RED

The first cumulative failure is accepted selector403 ordinal **211**:

`SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`

The process selected exactly one expected identity and exited normally with a GTest failure. Its test body throws:

`internal-midline hard-rail rectangle producer failed: InvalidHardRailPairing`

The frozen harness classified that single process `RED`; no SKIP, crash, timeout, or selection mismatch occurred. Ordinals 1-210 had already passed in fresh exact-filter processes.

`M4-CP3-TB7-EXEC` does **not** decide whether this is a product-semantic compatibility regression, stale accepted test authority, an already-known latent incompatibility exposed after ordinal138 recovery, or another classification. That adjudication belongs exclusively to `M4-CP3-TB7-REV`.

## 5. Evidence artifacts

Authoritative run `34721325716` produced:

- result artifact `10306626902`, SHA-256 `c9993798e8ce4d30db20beb8b96d219c4d48618cc50b4d8c18838ea76f682165`;
- diagnostic log artifact `10306557117`, SHA-256 `2ecd20e9b2e7eccffb20fd9c52c45b34579de274a57ec89c282ff582700b130e`.

The result contains the 223-row process ledger, immutable pre/postflight censuses, selector/owner authority, artifact authority, raw per-process logs, resource logs, and exact fail-fast boundary. The execution wrapper used the reviewed TB5 harness as a frozen template (`ca01dd830cd8c8c867334e2ec8aa1748309ad8b360260b2a02ddf3d5da6d976d`) and materialized the TB7 harness at SHA-256 `4bf659eac5fe834eff71ea6d90e7b1447d86961f39be7d4201c37efd8940b483`.

## 6. EXEC disposition and mandatory Review questions

`M4-CP3-TB7-EXEC` is **COMPLETE / FAIL-FAST RED / REVIEW REQUIRED**. No package or selector is promoted. Accepted runtime authority remains corrected R4 artifact `10289601000` / selector403 **403/403**. Stable accounting remains **48 events / 14 categories / 34 recurrences**, produced-witness debt **5**; CP3 and `G4-B002` remain OPEN pending Review.

`M4-CP3-TB7-REV` must independently re-open the immutable result/log evidence and relevant exact source, then:

1. confirm ordinal138 **2/2**, row408 **2/2**, and rows404-407 **8/8** are valid fresh-process evidence for the frozen CB9 two-sided compatibility obligation;
2. re-derive accepted selector403 ordinal211's historical premise and determine why the CB9 candidate throws `InvalidHardRailPairing` before the fixture's expected ambiguous-counterpart rejection contract;
3. classify the ordinal211 RED without assuming it is caused by CB9 merely because it is the first newly exposed cumulative failure;
4. decide candidate `47ae78e1e46e7d2dcc230fc617291ca45f2e418e` / package `10305678151` disposition and whether any bounded successor CB is authorized;
5. preserve accepted R4 selector403 authority unless Review explicitly establishes sufficient evidence to change it;
6. do not spend the unreached selector403/408 continuation processes merely to obtain more failures before the first RED is adjudicated.

# M4-CP-SCALE-TB6 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB6-EXEC`
**Disposition:** **COMPLETE / MECHANICALLY GREEN / PROMOTED BY `M4-CP-SCALE-TB6-REV` UNDER UNCHANGED SELECTOR424; S3 SELECTOR425 PUBLICATION OWED**
**Authoritative execution run/job:** `35036993863 / 104608250744`
**Control/event SHA:** `4b613f2420de231c09c2aff97da25542f0641fd7`
**Immutable candidate artifact:** `10418328122` (`a9f33bce6029022495fccbc4680da9bdd25cf41aa5cc733b2c04335e156ac16e`)
**Semantic source:** `153047c3f92e9b9b784e11eaee1ede2de5628470`
**Selector authority under test:** `Architecture_M4_CP_SCALE_CB6_Required_Green_Selector_424.txt`, 424 rows, SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`
**Focused S3 identity:** `M4CPScaleS3.ExactTraversalStateRepeatPublishesLimitCycleTermination`
**Mandatory Review:** `M4-CP-SCALE-TB6-REV` — **COMPLETE / ACCEPTED**
**Current successor after Review:** `M4-CP-SCALE-CB8`

## 1. Boundary and immutable provenance

TB6 stayed within the artifact-only Test + Benchmark boundary. It consumed exact CB7 candidate artifact `10418328122` and did not configure, compile, relink, repair, regenerate, discover/list tests, mutate source/test/fixture/selector bytes, or run unrelated benchmarks. The package entered TB with `runtimeExecution=false`; runtime began only after immutable preflight completed.

Preflight re-verified:

- provider artifact SHA-256 `a9f33bce6029022495fccbc4680da9bdd25cf41aa5cc733b2c04335e156ac16e`;
- semantic source `153047c3f92e9b9b784e11eaee1ede2de5628470` and packaged source archive SHA-256 `703dcc22f18ed565b623ef4eb43e117cd8acfd5d982ed0bde111d5cfdd56e0ff`;
- package `SHA256SUMS` SHA-256 `d5e2e620f3e5a9e78f4b646be95f872dd78ab8cbee7fe726156abf8249d6d5ad`, **28/28** entries;
- selector424 exactly **424 unique nonblank rows**, SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`, with accepted selector423 prefix SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343` and row424 exactly `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`;
- focused S3 ownership as producer target `directional_surface_cell_producer_tests`, source `tests/FieldAlignedCurveNetworkTests.cpp`, and absence of that identity from selector424;
- exact owner census **30 authority-kernel / 278 producer / 75 completion / 41 validation**;
- package GMP/GMPXX compile evidence plus runtime-load availability for the producer binary.

## 2. Pre-runtime orchestration correction provenance

Initial TB6 attempt run/job `35036750841 / 104607489241` failed **before runtime started**. Its preflight required every owner binary to expose direct `libgmpxx.so` and `libgmp.so` entries through `ldd`, even though exact-arithmetic linkage is not a direct dynamic dependency of every test executable. The attempt stopped after immutable package/selector/owner preflight and published `status=BLOCKED_PRE_RUNTIME`, `runtimeStarted=false`; it produced no semantic runtime ledger.

The bounded control-plane correction changed only the temporary TB6 workflow preflight: all required owner binaries still had to exist, be executable, and have no unresolved dynamic dependencies; package GMP/GMPXX evidence remained mandatory; direct GMP/GMPXX runtime-load checks were scoped to the producer binary that owns the focused S3 test. Candidate artifact/source/test/fixture/selector bytes were not changed or rebuilt.

Fresh retry run `35036993863` is therefore the only TB6 semantic execution authority.

## 3. Focused S3 runtime result

The focused identity executed in exactly one fresh process and passed **1/1** with exit 0, exactly one selected test, exactly one PASS, zero SKIP, and the required structured receipt:

`m4CpScaleS3;exactRepeat=LimitCycleTermination;differentExactEntry=Advanced;loadBearingTamperCount=4;combinatorialRecurrence=TraceCombinatorialRecurrenceExceeded;stepBudget=TraceStepBudgetExhausted`

The receipt proves the frozen discriminators exercised by the focused test: complete exact traversal-state repetition publishes typed `LimitCycleTermination`; different exact entry remains `Advanced`; all four state fields are load-bearing; combinatorial recurrence remains `TraceCombinatorialRecurrenceExceeded`; step-budget exhaustion remains `TraceStepBudgetExhausted`.

Focused status is **PASS** and `focused_receipt_match=true`.

## 4. Selector424 cumulative runtime result

Accepted selector424 executed in exact file order as **424 fresh exact-filter processes**. Every row selected exactly one test and passed.

| Measure | Result |
|---|---:|
| Executed | **424 / 424** |
| PASS | **424** |
| RED | **0** |
| SKIP | **0** |
| Timeout | **0** |
| Crash | **0** |
| Selection mismatch | **0** |
| Unexecuted | **0** |
| Authority-kernel | **30 / 30** |
| Producer | **278 / 278** |
| Completion | **75 / 75** |
| Validation | **41 / 41** |

Row424 ran freshly and passed. The focused S3 process is separate from selector424; total runtime process count is exactly **425 = 1 focused + 424 selector**, not selector425. No selector425 was authored or inferred.

## 5. Immutable postflight

Postflight completed successfully:

- package census equal before/after;
- semantic-source census equal before/after;
- execution-view census equal before/after;
- package manifest re-verified **28/28**;
- selector424 re-hashed to `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`.

The execution-prohibition receipt records `configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `repairExecution=false`, `generatedDiscovery=false`, `mutationExecution=false`, and `benchmarkExecution=false`.

## 6. Evidence package

- result artifact `10423717019`, provider SHA-256 `239886ce2918ce97416d01b8e7e390210c284acfc608c53b7531fc99a8854e8d`;
- detailed log artifact `10424430214`, provider SHA-256 `b1b8353968a496ff6e7673dba7209971b04f7b205f8316855e91e8e6ea0fa935`;
- nested evidence ZIP SHA-256 `6e70e20405bb5d1ab605c0fb49636bffce15a970c10fe842bf9ce1a5759310e9`;
- non-self-referential nested evidence manifest SHA-256 `3b05c4105cbdbe120e105bc0ca120e3fc46e98e102c4b5151e7c42fab4c0dfe7`, **1302/1302** entries verified;
- focused process ledger: one producer-owned row, PASS;
- selector process ledger: exactly 424 rows in selector order with owner census **30/278/75/41**;
- raw stdout/stderr, resource receipts, package/source/execution censuses, and checksum receipts retained in the evidence ZIP.

Final runtime status is `status=GREEN`, `focused=PASS`, `selector424=424/424`, `runtime_processes_actual=425`, `postflightComplete=true`, `runtimeStarted=true`, `runtimeCompleted=true`.

## 7. Regression/accounting disposition

`M4-CP-SCALE-TB6-EXEC-CAND-01` is **CLOSED / ORCHESTRATION FALSIFIER PASSED / NON-STABLE**: the first attempt's over-broad direct-GMP `ldd` assertion was corrected without candidate mutation, and the fresh retry passed preflight and all runtime/postflight gates.

TB6 observed **no product-semantic regression and no accepted-green loss**. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. `M4-CP-SCALE-DEFN-OBS-02` advances to **FOCUSED RUNTIME SATISFIED / REVIEW OWED / NON-STABLE**; EXEC alone does not discharge it.

## 8. EXEC-time authority and mandatory Review boundary

At TB6-EXEC closeout, the execution turn correctly made no promotion claim: candidate artifact `10418328122` remained unpromoted and TB5 package `10407605295` remained accepted until mandatory `M4-CP-SCALE-TB6-REV`. The EXEC turn also correctly withheld selector425/cumulative S3 credit. That historical boundary is now superseded by the completed Review disposition in §9; it is retained here only to preserve turn provenance.

## 9. Mandatory Review disposition

`M4-CP-SCALE-TB6-REV` independently reopened candidate/result/log bytes, verified the 1302-entry evidence manifest, re-hashed selector424 and accepted selector423 prefix, rebuilt owner mapping from packaged source+CMake, reopened every one of the 424 selector raw outputs, re-derived focused S3 ownership/receipt/non-vacuity, and source-audited the exact-state publication seam. Review **PROMOTES** package `10418328122` / source `153047c3f92e9b9b784e11eaee1ede2de5628470` as current M4 runtime authority under unchanged selector424 **424/424** and accepts the focused S3 contract for publication.

This does **not** grant cumulative selector425 credit. `M4-CP-SCALE-TB6-REV-OBS-01` requires publication-only selector425 = exact selector424 prefix + S3 row425, then fresh immutable selector425 **425/425** runtime and Review. Exact next is `M4-CP-SCALE-CB8`. Stable accounting remains **49 / 14 / 35**, debt **5**.

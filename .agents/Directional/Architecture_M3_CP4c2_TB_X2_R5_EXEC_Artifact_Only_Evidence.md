# Architecture M3 CP4c-2 — TB-X2-R5-EXEC Artifact-Only Evidence

- Phase: `M3-CP4c-2-TB-X2-R5`
- Subturn: `M3-CP4c-2-TB-X2-R5-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic/test evidence source: `76d757aab0ce18df09ce2823302d2dc224965187`
- Immutable GMP package: `9708324052`, `sha256:48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`
- Packaged source archive: `sha256:f16141613e877c78746548596449ef494fb9f4b384736526d74eaaf54a0a9a2d`
- Runtime run/job: `33232106030 / 99046593525`
- Trigger/event SHA: `796e57db119ef34d73fcac3bd6f9ab0b42390136`
- Result artifact: `9708817991`, `sha256:bda50fcdaf2b89ccce9a9b1ed5ecb7f4cd656a4168583635e69251f03c2556e8`
- Runtime log artifact: `9708818239`, `sha256:b9e150dec9d47cec140f982650a65b5d8668d3c5d5b8f4074bae7e3d6f8c9688`
- Observer log artifact: `9708797491`, `sha256:0b0a9b2ff509e92678f873cc83a690e4c2edace9c8b5307d40a999e621712b20`
- Benchmark execution: **none**

## EXEC disposition

**COMPLETE AT THE FROZEN AA8 STOP / ACCEPTED-PREFIX SEMANTIC RED AT ORDINAL 305 / AA2, D1, D2, 357, 358 NOT RUN.**

R5 preflight passed, then AA8 began the mandatory accepted-prefix re-proof in fresh processes. Identities 1-304
selected exactly one GoogleTest each and passed. Ordinal 305,
`GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph`, selected exactly once and exited `1` after
`SurfaceCutGraph::make` returned `CellularityNotEstablished`; the helper's subsequent `std::get: wrong index for
variant` exception is secondary fallout from accessing the failed result. The frozen R5 rule says any accepted-prefix
regression stops before local CP4c-2 credit, so ordinals 306-355, AA2, D1, D2, and all candidate/cumulative gates
were not executed.

This EXEC record preserves raw evidence only. It does not adjudicate whether the accepted-prefix red is a product,
witness, or test-authority regression, does not select a Y5 branch, and does not authorize corrective code.
`selected_r2_branch=NONE`, `selected_gate=NONE`, and `gate_execution_authorized=false` remain binding. Independent
`M3-CP4c-2-TB-X2-R5-REV` owns admissibility and root-cause adjudication.

## Immutable preflight

Preflight verified before the first Directional process:

- provider package digest exactly `48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`;
- package `SHA256SUMS` passed and packaged executable modes were preserved;
- `metadata/source-commit.txt` exactly `76d757aab0ce18df09ce2823302d2dc224965187`;
- package command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- GMP/GMPXX link evidence and all eight standard compiled targets were present;
- packaged source archive SHA-256 exactly `f16141613e877c78746548596449ef494fb9f4b384736526d74eaaf54a0a9a2d`;
- all six frozen selector hashes recomputed exactly: first 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, 357 `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, and 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`;
- pre-runtime package/source inventories were captured: package `29` regular files and materialized source `539` regular files.

Static identity-to-owner mapping was derived from the frozen selector plus the exact built test source lists; no
`--gtest_list_tests`, generated discovery, configure, compile, relink, repair, or benchmark was used.

## AA8 raw evidence

The result artifact contains `305` per-identity raw logs and `305` process-result rows. Exactly `304` rows have
exit `0`; exactly one row is red:

```text
accepted\t305\tGlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph\tdirectional_surface_cell_producer_tests\t1\tSELECTED_ONE
```

The failing raw log records one GoogleTest selection and the first semantic failure:

```text
CellularityNotEstablished
```

at the `build_surface_cut_graph(...)` helper used by the accepted `GlobalTopologyPlan` witness. The same process then
throws `std::get: wrong index for variant` because the helper accesses `built.value()` after its non-fatal
`EXPECT_TRUE(built)` failed. That exception does not precede or replace the published cut-graph failure.

Therefore the first 316 accepted prefix is **RED before completion**: ordinals 1-304 PASS, ordinal 305 RED, and
306-316 are unexecuted. The 346/353/355 continuation is unexecuted. Under AA8 this is the planned semantic stop,
so no CP4c-2-local diagnostic receives credit.

## Downstream disposition

Because AA8 stopped first:

- AA2 prior-R4 duplicate-byte check: **NOT RUN**;
- D1 `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable`: **NOT RUN**;
- D2 `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`: **NOT RUN**;
- selector 357: **NOT RUN**;
- selector 358: **NOT RUN**;
- cumulative CP4c-2 gate: **NOT RUN**;
- benchmark: **NOT RUN**.

R4-CAND-01/02/03, R2-CAND-02, and X2 CAND-04 therefore receive no runtime disposition from this EXEC attempt.

## Control-plane deviation and postflight limitation

The Directional semantic stop was preserved, but the temporary shell harness has a control bug: `run_identity`
re-enabled `set -e` before returning the nonzero GoogleTest exit. The shell therefore terminated immediately after
ordinal 305 instead of returning control to the outer AA8 stop handler. As a result, `status.txt`, the planned
semantic summary, and the recursive post-runtime package/source inventories were not emitted. The GitHub job
correctly ended failure through its orchestration guard after uploading the raw result and diagnostic log.

This missing postflight record is **not silently repaired or treated as acceptance evidence**. The result artifact
still contains the complete immutable preflight inventories, and the executed binaries were copies under a separate
runtime directory; the package/source trees were only read after their inventories were captured. Independent R5-REV
must decide whether the preserved semantic red is admissible as-is or whether a bounded no-new-semantics recovery is
required. D1/D2 must not be inferred from this run.

A separate start-of-turn process deviation also occurred: repository reads began before the mandatory explicit
`READ_MODE` selection. The miss was detected, `READ_MODE=snapshot` was selected, and the source snapshot was acquired
before continuing cross-file repository analysis. Snapshot run/job `33231427983 / 99044841198`, artifact
`9708603791`, `sha256:e3febb5c1196b79b741f8db69d866eabdf918e84b390153c60e190776720a67a`, event SHA
`b9225958a0e8c173bc4fa8564b1cfbe93bccec49`.

The R5 temporary workload schema was validated before execution in run `33232063298`: self/workload schema jobs
`99046486439 / 99046486446` both passed; workload validation artifact `9708765948`,
`sha256:51397b944977344f74bd5d40e97c0e8ce53fca8c33f288734563f88dc2faf59e`.

## Regression/accounting state at EXEC close

New candidate `M3-CP4c2-TB-X2-R5-CAND-01` records the accepted-prefix red as **ACTIVE / ACCEPTED-PREFIX REGRESSION /
NON-STABLE / REVIEW REQUIRED**. Its observed locus is `SurfaceCutGraph::make` returning
`CellularityNotEstablished` inside the pre-existing CP3b event fixture used by ordinal 305; the later variant
exception is secondary. Root-cause category is intentionally unadjudicated pending independent review.

Because no independent review has classified this candidate as a stable event/category/recurrence, stable accounting
remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**; M3 package count remains
**62**. CP4c-2 remains runtime-unaccepted.

## Exact next state

`M3-CP4c-2-TB-X2-R5-REV` — independent evidence review only. It consumes this preserved R5 evidence and the frozen
R5 plan. It must run **no new Directional runtime**, must not infer AA2/D1/D2 results, must not select Y5/357/358,
must not execute a cumulative gate, and must not begin corrective CB or CP4c-3 unless the review durably authorizes
a later successor.

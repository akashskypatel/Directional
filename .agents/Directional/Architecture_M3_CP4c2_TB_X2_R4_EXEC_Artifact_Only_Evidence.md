# Architecture M3 CP4c-2 — TB-X2-R4-EXEC Artifact-Only Evidence

- Phase: `M3-CP4c-2-TB-X2-R4`
- Subturn: `M3-CP4c-2-TB-X2-R4-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Semantic/test evidence source: `5ad711e5d4ced95f38e103b993139a6307ba2cee`
- Immutable GMP package: `9707091209`, `sha256:e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63`
- Packaged source archive: `sha256:9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11`
- Authoritative runtime run/job: `33228460953 / 99036688477`
- Trigger/event SHA: `8a07028fc390e8c2d15a5e55b5efd73aaf070d83`
- Result artifact: `9707662462`, `sha256:36e5982c152317a56d98d13e58a2ec1233c71b65e9f8570aeabfed373228a76f`
- Runtime log artifact: `9707662682`, `sha256:594edbad06c849e12ad52787ec144f08da526c6f25c4449d21a222691daae0eb`
- Observer log artifact: `9707662666`, `sha256:56c456a4e3f0dea612c9e67314de6d3f09bb41b4898c943d47e61706d8f68aaf`
- Benchmark execution: **none**

## EXEC verdict

**COMPLETE / VALID DIAGNOSTIC SEMANTIC RED / D1 EVIDENCE-CONFLICT STOP / D2 NOT AUTHORIZED.**

Immutable package/source/GMP/selector preflight passed. D1 selected the one authorized GoogleTest and ran exactly
once. It exited `1`. The three witnesses were all reached, but the preserved stdout contains **four**
`m3Cp4c2Y1` lines because the prescribed-sphere failure record is emitted once in the witness loop and then
repeated byte-identically in the final GoogleTest assertion diagnostics. The frozen R4 contract requires exactly
one record per witness, so EXEC stops as `STOP_EVIDENCE_CONFLICT`; D2 is
`SKIPPED_DUE_TO_STOP_EVIDENCE_CONFLICT`.

This subturn makes **no Y5 branch inference**, closes no candidate by interpretation, gives no selector/gate
credit, and authorizes no corrective CB. `selected_r2_branch=NONE`, `selected_gate=NONE`, and
`gate_execution_authorized=false` remain binding.

## Immutable preflight and postflight

Preflight verified:

- provider ZIP digest exactly `e6852141847a23b77245887f66b11d411d7cffc414ae91c1a829eb93c8712f63`;
- internal `SHA256SUMS` passed for every package entry and the producer executable retained mode `755`;
- `metadata/source-commit.txt` exactly `5ad711e5d4ced95f38e103b993139a6307ba2cee`;
- `metadata/preflight-exit-code.txt=0`, `metadata/build-exit-code.txt=0`, and packaged source-status snapshots empty;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- GMP/GMPXX authoritative link evidence and exactly the eight standard compiled targets;
- packaged source archive SHA-256 exactly `9a9dbfb5c6aede1618d41323109cb336f978f75434bef216472557121df2fb11`;
- fixture source materialized read-only at the binary's compiled root `/home/runner/work/Directional/Directional`;
- frozen selector hashes unchanged: first 316 `601ce2b6…0193c`, first 346 `20d3b0b1…3e46a`, first 353
  `51ff96d7…ac6a5`, selector 355 `e9d88f11…afeaa`, 357 `b896d0db…64dc70`, 358 `6eda3aad…fbe62`.

Recursive package and source byte/mode inventories were captured before runtime and repeated after the stop:
package `29/29` regular-file records match exactly; materialized source `533/533` records match exactly. Final
`SHA256SUMS` and package metadata checks also pass. No configure, compile, relink, generated discovery, package
repair, fixture/source/test mutation, selector gate, or benchmark occurred.

## D1 raw evidence

Command, one fresh process:

```text
./bin/directional_surface_cell_producer_tests   --gtest_filter=GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable
```

Process exit: `1`.

The first torus publication is a successful pipeline-products witness. It reports:

- `pipelineAtlasAvailable=true`, `pipelineNetworkAvailable=true`, `pipelineCutGraphAvailable=true`,
  `pipelinePlanAvailable=true`;
- `complex=sourceEdgeBarrier`, `railAuthority=pipeline-authoritative`, `surfaceCutGraphCalls=0`;
- `sourceChi=0`, `barrierV=48`, `barrierE=48`, `barrierF=4`;
- `oracleSelfConsistent=true`, `networkOnlyCellular=false`;
- `terminalFailureCode=NotProductionReady`, `terminalFailureStage=tracing`.

The prescribed-sphere publication is a typed construction failure:

```text
witness=prescribed-sphere
witnessConstruction=pipelineProducts
constructionSucceeded=false
failureKind=fixture-construction
railAuthority=pipeline-authoritative
pipelineAtlasAvailable=false
pipelineNetworkAvailable=false
pipelineCutGraphAvailable=false
pipelinePlanAvailable=false
terminalFailureCode=NotProductionReady
terminalFailureStage=surface-cut-graph/CellularityNotEstablished
error=pipeline-source-topology-snapshot-unavailable
```

The two-ring publication succeeds with `witnessConstruction=constructed`, `railAuthority=atlas-derived`,
`complex=sourceEdgeBarrier`, `oracleSelfConsistent=true`, and `networkOnlyCellular=true`.

After the loop, `ASSERT_TRUE(allWitnessesValid) << failures.str()` fails at
`tests/FieldAlignedCurveNetworkTests.cpp:6071`. Its failure message repeats the same prescribed-sphere
`m3Cp4c2Y1` record already printed by the loop. Therefore the preserved publication counts are:
`torus=1`, `prescribed-sphere=2`, `two-ring=1`, total `4`.

The exact full records remain in `d1-records.txt`, `d1-records.json`, and `d1.log` inside result artifact
`9707662462`; this report intentionally does not rewrite those raw records.

## Stop and D2 disposition

The R4 plan requires exactly one `m3Cp4c2Y1` record for each witness and requires all three witnesses to construct
successfully before D2. Both prerequisites are unmet: the sphere construction is red and the stdout publication
contract contains a duplicate sphere record. EXEC therefore records:

```text
d1_exit=1
d1_decision=STOP_EVIDENCE_CONFLICT
d2_decision=SKIPPED_DUE_TO_STOP_EVIDENCE_CONFLICT
status=semantic-red
```

This is semantic evidence, not a retryable orchestration failure. Unchanged D1 must not be rerun. R4-REV owns
adjudication of Z13 witness isolation, the duplicate publication contract, torus 48/48, the sphere snapshot
precondition, and all candidate dispositions. D2/CAND-04 remains unmeasured.

## Orchestration/process precursors

Two non-semantic issues occurred before the authoritative evidence above and were corrected without changing the
immutable package or Directional runtime semantics.

1. **Start-of-turn READ_MODE ordering miss.** The handoff was fetched before the mandatory full policy read and
   explicit READ_MODE choice. The miss was detected immediately, `READ_MODE=snapshot` was selected, and the
   required start-of-turn source snapshot was acquired before continuing repository source/document analysis.
   Snapshot run/job `33227743188 / 99034637720`, artifact `9707441880`,
   `sha256:2a87dc92a07d3fb2a99a7e39c46ce8b61da8f2b48f04f9eac444d460775bdacf`, source archive
   `sha256:52c588478b14e8410ab86e4a6beb3b6714b414afdb0e735216257792db502f81`.
2. **First runtime control-path failure.** Run/job `33228330756 / 99036316061` verified the package outer digest
   and internal manifest, then stopped before D1 because the execution control script addressed package metadata
   at the archive root instead of `metadata/`. No Directional binary executed. Result/log artifacts
   `9707618205 / 9707618481`, digests
   `dd1940588a85e562ba4f61b8dc2f77ef3030390bd23c8a98b91b01c4bf520a25 /
   ca43943c4684586e704eb585ddd53245fe6d93644b8798c6d0174ed4045e3348`. The control path was corrected,
   schema-validated, and retried under the R4 orchestration-retry rule.

Schema validation for the final caller passed in run `33228412101`, report artifact `9707643944`,
`sha256:ad0a35e2553f142fb107805b3cf0d5a24dd0cc54c1e384fd6dff2649cd4019b2`.

## Candidate/accounting status at EXEC close

EXEC records raw evidence only; independent R4-REV owns closure/adjudication.

- `M3-CP4c2-TB-X2-R2-CAND-01`: **ACTIVE pending REV**. R4 now contains a product-authoritative torus network
  publication with the frozen 48/48 values, but EXEC does not close the candidate.
- `M3-CP4c2-TB-X2-R2-CAND-02`: **ACTIVE**. The prescribed sphere did not construct, so the existing all-three
  corrected/self-consistent closure condition was not reached.
- `M3-CP4c2-TB-X2-R3-CAND-01`: **ACTIVE pending REV disposition**. The torus now reaches the product-snapshot
  network and publishes 48/48; review owns closure.
- `M3-CP4c2-TB-X2-R3-CAND-02`: **ACTIVE pending REV disposition**. A failed sphere no longer suppresses torus or
  two-ring, but the strict exactly-once publication contract is independently red.
- `M3-CP4c2-TB-X2-CAND-04`: **ACTIVE / UNLOCALIZED**. D2 was not authorized and did not run.
- `M3-CP4c2-TB-X2-R4-CAND-01`: **ACTIVE / TEST-AUTHORITY / PUBLICATION-CONTRACT / NON-STABLE**. The final
  assertion re-emits a failure record already published by the loop, yielding four Y1 lines.
- `M3-CP4c2-TB-X2-R4-CAND-02`: **ACTIVE / DIAGNOSTIC-PRECONDITION / SNAPSHOT-AVAILABILITY / NON-STABLE**.
  Prescribed-sphere pipelineProducts construction cannot consume a source-topology snapshot and publishes all
  pipeline snapshot optionals unavailable. Cause/disposition is reserved to R4-REV.

Stable accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**;
M3 package count remains **61**. CP4c-2 remains runtime-unaccepted.

## Exact next state

`M3-CP4c-2-TB-X2-R4-REV` — independent evidence review only. It must consume the preserved R4 evidence and run
**no new Directional runtime**. It must not rerun D1, run D2/355/357/358, execute a cumulative gate, compile,
start CB3, touch mechanical/C2, or begin CP4c-3 unless the review itself durably authorizes a later successor.

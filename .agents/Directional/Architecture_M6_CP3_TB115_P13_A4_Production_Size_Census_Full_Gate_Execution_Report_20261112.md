# TB115 — Production-size census, immutable full-gate execution (2026-11-12 UTC)

## Situation

Canonical turn `M6-CP3-TB115-P13-A4-PRODUCTION-SIZE-CENSUS-FULL-GATE-EXEC` (64E.11) has a **scoped MATCH** under RA-233 §5. The full gate returned 945/945 PASS and the separate production census returned one PASS and two expected registered RED cases. This result does not promote the CP3 selector or authorize the production switch.

## Background

- Repository: `akashskypatel/Directional`; working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; draft PR #8, unmerged.
- Exact semantic source and execution revision: `c565a3ada13d4b785fb45182db80fd5adf665add`.
- Compile-only source package: [run 43244784978](https://github.com/akashskypatel/Directional/actions/runs/43244784978), artifact `13956118408`, ZIP SHA-256 `e1e4d67cee10be6001369ec8f7fc9e7e09225202dbd87fdbc51facf483dd88dd`, 28/28 manifest entries. Exact arithmetic uses GMP/GMPXX; compile record has `runtimeExecution=false`.
- Full-gate result: [run 43252819031](https://github.com/akashskypatel/Directional/actions/runs/43252819031), artifact `13960368135`, ZIP SHA-256 `6e2d8ec94b92db1428627e46496e61c84dea5b4c4a088d119eebe2f1fff2173f`.
- Three-case census: [run 43253370547](https://github.com/akashskypatel/Directional/actions/runs/43253370547), artifact `13960224847`, ZIP SHA-256 `51ddc7823fabb89c64ca86dd94252b83606d47e3945e0951c098dd1eea832ff7`.
- Full-case manifest: 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020` (same as TB114). Production census manifest: three cases, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Reference TB114: artifact `13950773589`, ZIP SHA-256 `ae08fb620b087ce7b05b177dd21d8b98f821f4817c3a217ece504bcf93073f3d`.

## Assessment — gate and census

| Check | Observed |
|---|---|
| Full-gate cases | 945 planned / 945 executed / 945 passed |
| Full-gate membership | 1,026; membership.tsv byte-identical to TB114 |
| Full-gate ZIP internal SHA-256 records | 1,898/1,898 PASS |
| Regression comparison | 945/945 verdicts match TB114; no semantic ledger mismatch |
| Earlier diagnostic records | All 48/48 selected TB114 receipt lines retained verbatim |
| New full-gate receipts | 12 `schedule=production` records for Plane, MultiFaceSeam, CloseSheets, Cylinder |
| Census | 3 planned / 3 executed; Cylinder PASS, BunnyRandom RED, Vase RED |
| Census ZIP internal SHA-256 records | 9/9 PASS |
| Execution boundary | No configure, compile, relink, benchmark; postflight success and no control/skip/duplicate/missing/unexpected-PASS cases |

**Cylinder:** production mode produced 288 quads. Final validation reports `accepted=1 strict=0`; no interior edge below half target; size p5 `0.641445`.

**BunnyRandom:** registered RED in `InvalidFieldTransportAtlas/field-transport-atlas/SingularityPortClassCountMismatch` (source vertex 49). It stops before completion. It emits only `switch-run`, as required, and no new size/validation record.

**Vase:** registered RED at `NotProductionReady/completion` and `completion/output-validation/AggregateCompletionValidationFailure`. `switch-validation` reports `accepted=0 strict=0`. Its 67,750 *candidate* quads do not constitute accepted output. The size census reports boundary ratio p5/p50/p95 `0.0207107/0.289034/1.20048`, interior ratio p5/p50/p95 `0.00346652/0.0449679/0.197897`, and `interiorBelowHalf=134598` of 135,290. The target range is `0.0335324/0.100597/0.100597`. Additional validation measures fail as well: angle `6.45948/180.765`, Jacobian `-1/-0.0133951`, nonconvex count `16808`, boundary-valence count `248/420`, and singularity-valence count `1/1`. A size correction alone is **not proven** to resolve these distinct validation failures.

**Regression classification:** No new gated RED or accepted-green loss. The two non-gating production RED cases have the same registered terminal classes as earlier production census turns. Vase adds diagnostic detail for existing O41 and the existing Vase completion obligation, not a newly established stable regression. Do not infer a new root cause from one shared failure code. The accepted CP2 prefix remains **491/491**, with **66 stable events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. CP3/selector497 remains unpromoted; `chainRimSchedules=false`. D10 remains a user choice and O41 remains open.

## Exact new full-gate production receipts

```text
switch-run case=CloseSheets schedule=production produced=1 faces=200 failure=None/ phaseFront=Produced invalid=/ a3=24/0/0/24/0
switch-validation case=CloseSheets schedule=production accepted=1 strict=0 quadToSource=1.15806e-15/2.59097e-15 sourceToOutput=1.03681e-15/1.30681e-15 normalP95=0 field=0.532768/1.65247 size=0.673214/1.15459 angle=86.8136/92.72 warpage=0/0 aspect=1.15805/1.16514 jacobian=0.998139/0.998239 nonConvex=0 boundaryValence=0/80 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-size case=CloseSheets schedule=production quads=200 boundary=80:1.07338/1.15459/1.2063 interior=360:0.673198/0.840811/1.08666 interiorBelowHalf=0 target=0.0849567/0.088046/0.161418
switch-run case=MultiFaceSeam schedule=production produced=1 faces=64 failure=None/ phaseFront=Produced invalid=/ a3=16/0/0/16/0
switch-validation case=MultiFaceSeam schedule=production accepted=1 strict=0 quadToSource=2.94392e-16/4.95405e-13 sourceToOutput=4.95405e-13/1.88959e-12 normalP95=0 field=2.09131e-06/3.50567e-05 size=0.531781/1.31388 angle=89.9999/90.0001 warpage=0/0 aspect=1/1 jacobian=1/1 nonConvex=0 boundaryValence=0/32 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-size case=MultiFaceSeam schedule=production quads=64 boundary=32:1.27931/1.27931/1.31388 interior=112:0.531781/0.794908/1.10919 interiorBelowHalf=4 target=0.0942809/0.0977093/0.282843
switch-run case=Plane schedule=production produced=1 faces=64 failure=None/ phaseFront=Produced invalid=/ a3=14/0/0/14/0
switch-validation case=Plane schedule=production accepted=1 strict=0 quadToSource=9.1669e-16/2.34286e-15 sourceToOutput=7.02879e-16/1.25164e-15 normalP95=0 field=2.41484e-06/3.11364e-05 size=0.658348/1.29965 angle=90/90 warpage=0/0 aspect=1/1 jacobian=1/1 nonConvex=0 boundaryValence=0/32 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-size case=Plane schedule=production quads=64 boundary=32:1.27345/1.28181/1.31231 interior=112:0.651854/0.881709/1.18862 interiorBelowHalf=0 target=0.0942809/0.0981658/0.195455
switch-run case=Cylinder schedule=production produced=1 faces=288 failure=None/ phaseFront=Produced invalid=/ a3=81/32/0/49/0
switch-validation case=Cylinder schedule=production accepted=1 strict=0 quadToSource=7.25387e-16/1.33266e-15 sourceToOutput=1.94925e-15/2.47418e-15 normalP95=0 field=0/8.53774e-07 size=0.641445/1.17049 angle=90/90 warpage=0/8.53774e-07 aspect=1.13907/1.13907 jacobian=1/1 nonConvex=0 boundaryValence=0/64 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-size case=Cylinder schedule=production quads=288 boundary=64:0.987618/1.04718/1.05596 interior=544:0.641445/0.983419/1.17049 interiorBelowHalf=0 target=0.184752/0.204594/0.383932
```

## Exact three-case production receipts

```text
switch-run case=Cylinder schedule=production produced=1 faces=288 failure=None/ phaseFront=Produced invalid=/ a3=81/32/0/49/0
switch-validation case=Cylinder schedule=production accepted=1 strict=0 quadToSource=7.25387e-16/1.33266e-15 sourceToOutput=1.94925e-15/2.47418e-15 normalP95=0 field=0/8.53774e-07 size=0.641445/1.17049 angle=90/90 warpage=0/8.53774e-07 aspect=1.13907/1.13907 jacobian=1/1 nonConvex=0 boundaryValence=0/64 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-size case=Cylinder schedule=production quads=288 boundary=64:0.987618/1.04718/1.05596 interior=544:0.641445/0.983419/1.17049 interiorBelowHalf=0 target=0.184752/0.204594/0.383932
switch-run case=BunnyRandom schedule=production produced=0 faces=0 failure=InvalidFieldTransportAtlas/field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49;topologyRegion=0;transportRegion[0]={topologyRegion=0,hardFeatureEdges=17,barrierEdges=17,barrierVertices=24,barrierComponents=7,barrierChi=7,boundaryBarrierVertices=0,barrierIncidentSingularities=2,uncutChi=2,cutChi=-5,uncutBoundaryLoops=0,cutBoundaryLoops=7};transportRegion[0].barrierSingularity[0]={sourceVertex=170,indexNumerator=1,barrierDegree=1,transportStarComponents=1};transportRegion[0].barrierSingularity[1]={sourceVertex=240,indexNumerator=1,barrierDegree=1,transportStarComponents=1} phaseFront= invalid=/ a3=0/0/0/0/0
switch-run case=Vase schedule=production produced=0 faces=0 failure=NotProductionReady/completion phaseFront=NotApplicable invalid=completion/output-validation/AggregateCompletionValidationFailure a3=0/0/0/0/0
switch-validation case=Vase schedule=production accepted=0 strict=0 quadToSource=0.000196061/0.0653743 sourceToOutput=0.00323443/0.0479265 normalP95=3.73581 field=0/36.4133 size=0.00347217/0.199514 angle=6.45948/180.765 warpage=81.792/166.181 aspect=60.6582/286.628 jacobian=-1/-0.0133951 nonConvex=16808 boundaryValence=248/420 singularityValence=1/1 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-size case=Vase schedule=production quads=67750 boundary=420:0.0207107/0.289034/1.20048 interior=135290:0.00346652/0.0449679/0.197897 interiorBelowHalf=134598 target=0.0335324/0.100597/0.100597
```

## Recommendation

The scoped TB115 gate is a MATCH. The next and only separate authorized turn is `M6-CP3-DEFN-P13-A4-SIZE-GRADING-DECISION` (Review-only, RA-233 §6). That review must consider Vase's size and geometry failures and ask the user to select D10 option A, B, or C if no answer exists. No D10 option is selected by this test turn. Do not change any implementation, fixture, selector, threshold, schedule, or acceptance gate within TB115.

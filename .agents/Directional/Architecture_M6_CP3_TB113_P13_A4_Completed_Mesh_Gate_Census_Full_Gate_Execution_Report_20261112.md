# TB113 — Completed-mesh gate census full-gate execution (2026-11-12 UTC)

## Situation

Canonical turn `M6-CP3-TB113-P13-A4-COMPLETED-MESH-GATE-CENSUS-FULL-GATE-EXEC` (step 64E.5) is **COMPLETE / scoped MATCH** under RA-231 §5. The 945-case immutable Test + Benchmark gate passes. The existing TB112 receipts are unchanged, and all ten new completed-mesh gate receipts are present. O41 remains open; this diagnostic turn did not resolve it.

## Background — fixed source and execution authority

- Original semantic source: [`196f611769ee738a86d4aa46903d0ed592384691`](https://github.com/akashskypatel/Directional/commit/196f611769ee738a86d4aa46903d0ed592384691), the CB132 test-only compile.
- Immutable compiled package: [artifact `13941286743`](https://github.com/akashskypatel/Directional/actions/runs/43210849945/artifacts/13941286743), ZIP SHA-256 `3964dde25c8005048e018f2927f2f7dd29c288eb2afcb2d43ddd9451288c3b5e`; 28/28 internal package SHA-256 records verified, with required GMP/GMPXX linkage and `runtimeExecution=false` from compile evidence.
- Frozen gate manifest: `.agents/Directional/gates/Architecture_M6_TB113_P13_A4_Completed_Mesh_Gate_Census_Full_Gate_Case_Manifest.tsv`, 945 cases, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, 1,026 memberships and 81 deferred.
- Existing request commit: [`5e3e0a67870e94f47e7b1286859e7ed3a602fb94`](https://github.com/akashskypatel/Directional/commit/5e3e0a67870e94f47e7b1286859e7ed3a602fb94). Executor SHA `e9390bd8133ea7dc224a726d07d808b615948e33`, harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Execution run `43213775926`](https://github.com/akashskypatel/Directional/actions/runs/43213775926), runtime job `131167893552` SUCCESS, mailbox `m6-cp3-tb113-completed-mesh-gate-full-20261112-v1` SUCCESS.
- [Exact result artifact `13944045361`](https://github.com/akashskypatel/Directional/actions/runs/43213775926/artifacts/13944045361), outer ZIP SHA-256 `c07047dab745cdb3b48eda699233982229ec5ce5b818f01fc82b96a7979c6223`; **1,898/1,898 internal SHA-256 entries verified**. Separate result/log artifacts retained in workflow; log `13944340020`.
- Prior TB112 comparison artifact `13935551687` from [run 43199861547](https://github.com/akashskypatel/Directional/actions/runs/43199861547), 1,898/1,898 entries independently verified and stable prior receipt authority.

## Assessment — execution boundary and deterministic comparison

| Invariant | Observed result |
|---|---|
| Cases planned / executed / passed | **945 / 945 / 945** |
| RED / abnormal / missing / skipped / duplicate | **0 / 0 / 0 / 0 / 0** |
| Invalid control / unexpected pass / later positive RED / RED-site mismatch | **0 / 0 / 0 / 0** |
| Membership | **1,026** |
| Gate postflight / exit | **true / 0** |
| Reconfigure / compile / relink / benchmark | **false / false / false / false** |
| Result internal file SHA-256 | **1,898/1,898 PASS** |
| TB112 vs TB113 ledger substantive differences | **0** (only log SHA-256 may differ) |
| Pre-existing matched receipt lines | **46/46 byte-identical** (including ten `switch-run` lines) |
| New `switch-validation` receipts | **10 exactly** (two per fixture) |
| Required failure rows | All three `accepted=0 strict=0` |

TB113 ran only packaged binaries in isolated processes. No local compiled executable was run, no rebuild or source/test/fixture repair occurred, and no gate membership/selection was changed. The test-only CB132 change added observations without altering product behavior.

### All ten exact new validation receipts

```text
switch-validation case=Plane schedule=perArc accepted=1 strict=0 quadToSource=9.1669e-16/2.34286e-15 sourceToOutput=7.02879e-16/1.25164e-15 normalP95=0 field=2.41484e-06/3.11364e-05 size=0.658348/1.29965 angle=90/90 warpage=0/0 aspect=1/1 jacobian=1/1 nonConvex=0 boundaryValence=0/32 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=Plane schedule=chained accepted=1 strict=0 quadToSource=9.05541e-16/1.39556e-15 sourceToOutput=7.95794e-16/1.98807e-15 normalP95=0 field=0.722597/2.9598 size=0.534213/1.03828 angle=84.8488/94.9746 warpage=0/0 aspect=1.18371/1.19871 jacobian=0.986921/0.993837 nonConvex=0 boundaryValence=0/40 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=MultiFaceSeam schedule=perArc accepted=1 strict=0 quadToSource=2.94392e-16/4.95405e-13 sourceToOutput=4.95405e-13/1.88959e-12 normalP95=0 field=2.09131e-06/3.50567e-05 size=0.531781/1.31388 angle=89.9999/90.0001 warpage=0/0 aspect=1/1 jacobian=1/1 nonConvex=0 boundaryValence=0/32 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=MultiFaceSeam schedule=chained accepted=0 strict=0 quadToSource=5.88785e-16/1.37734e-15 sourceToOutput=3.94252e-16/1.25758e-15 normalP95=0 field=0/0 size=0.43405/1.03068 angle=90/90 warpage=0/0 aspect=1/1 jacobian=1/1 nonConvex=0 boundaryValence=0/40 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=CloseSheets schedule=perArc accepted=1 strict=0 quadToSource=1.15806e-15/2.59097e-15 sourceToOutput=1.03681e-15/1.30681e-15 normalP95=0 field=0.532768/1.65247 size=0.673214/1.15459 angle=86.8136/92.72 warpage=0/0 aspect=1.15805/1.16514 jacobian=0.998139/0.998239 nonConvex=0 boundaryValence=0/80 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=CloseSheets schedule=chained accepted=1 strict=0 quadToSource=1.14238e-15/2.62593e-15 sourceToOutput=9.86836e-16/1.33334e-15 normalP95=0 field=0.484167/1.50312 size=0.598982/1.03836 angle=87.066/92.8561 warpage=0/0 aspect=1.14881/1.1568 jacobian=0.998358/0.998607 nonConvex=0 boundaryValence=0/88 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=Cylinder schedule=perArc accepted=1 strict=0 quadToSource=7.25387e-16/1.33266e-15 sourceToOutput=1.94925e-15/2.47418e-15 normalP95=0 field=0/8.53774e-07 size=0.641445/1.17049 angle=90/90 warpage=0/8.53774e-07 aspect=1.13907/1.13907 jacobian=1/1 nonConvex=0 boundaryValence=0/64 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=Cylinder schedule=chained accepted=1 strict=0 quadToSource=7.25387e-16/1.33266e-15 sourceToOutput=1.94925e-15/2.47418e-15 normalP95=0 field=0/8.53774e-07 size=0.641445/1.17049 angle=90/90 warpage=0/8.53774e-07 aspect=1.13907/1.13907 jacobian=1/1 nonConvex=0 boundaryValence=0/64 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=SmoothRimDisc schedule=perArc accepted=0 strict=0 quadToSource=3.31231e-16/6.58281e-16 sourceToOutput=3.00576e-16/3.77006e-15 normalP95=0 field=16.5247/29.2021 size=0.292237/1.06761 angle=45.3503/135.443 warpage=0/0 aspect=1.8152/1.81593 jacobian=0.19509/0.19509 nonConvex=0 boundaryValence=0/32 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
switch-validation case=SmoothRimDisc schedule=chained accepted=0 strict=0 quadToSource=8.32667e-16/2.89943e-15 sourceToOutput=3.59182e-16/2.89943e-15 normalP95=0 field=16.5247/29.2021 size=0.292237/1.06761 angle=45.3503/135.443 warpage=0/0 aspect=1.8152/1.81593 jacobian=0.19509/0.19509 nonConvex=0 boundaryValence=0/32 singularityValence=0/0 tJunctions=0 nonManifold=0 degenerate=0 inverted=0 selfIntersecting=0 topologyFixed=1 featureOrdered=1 onComponents=1
```

**Required three existing failures:** MultiFaceSeam `chained`, SmoothRimDisc `perArc`, and SmoothRimDisc `chained` each printed `accepted=0 strict=0`. The prior `switch-run` receipts for these three still report `NotProductionReady/completion` with `AggregateCompletionValidationFailure`. MultiFaceSeam's per-arc case is still accepted. The three rows are not new gate REDs and are not evidence that a specific acceptance threshold or producer error is the root cause.

**Provisional evidence for the Review:** SmoothRimDisc has `field=16.5247/29.2021`, `angle=45.3503/135.443`, `aspect=1.8152/1.81593`, and `jacobian=0.19509/0.19509` under both schedules; chained MultiFaceSeam has `field=0/0`, `angle=90/90`, `aspect=1/1`, `jacobian=1/1`, yet `accepted=0`. The Review must compare the exact acceptance expression and its thresholds against these measured values, including any measure not printed or threshold dependencies, before assigning O41's cause. No such cause is established by TB113 alone.

## Recommendation and disposition

**Scoped MATCH** satisfies all RA-231 §5 conditions. There is **no new stable regression**. Preserve accepted CP2 **491/491**, stable regression **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. CP3 and selector497 remain **unpromoted**. `chainRimSchedules=false` and the per-arc production default remain unchanged. O41 stays open. No production switch activation or repair is authorized in TB113.

The next separate turn, not begun here, is the **Review-only** `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE` (RA-231 §6), which owns the cause and correction of O41. The prior operational issue (tool-read mode selected after direct document inspection) was reported as a procedural miss; it does not modify execution results.

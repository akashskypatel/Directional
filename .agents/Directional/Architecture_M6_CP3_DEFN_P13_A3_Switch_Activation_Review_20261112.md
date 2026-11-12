# RA-231 — Switch activation (step 64E.3)

Turn `M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION`, Review agent only, runtime-free. Input: [TB112](Architecture_M6_CP3_TB112_P13_A3_Rim_Chain_Switch_Staging_Full_Gate_Execution_Report_20261112.md) (945/945, scoped MATCH; all TB110 receipts unchanged; ten `switch-run` lines). RA-230 §6.

## 1. What TB112 showed

| Case | per-arc | chained |
|---|---|---|
| Plane | produced, 64 faces, `a3=14/0/0/14/0` | produced, 100 faces, `a3=4/4/0/0/0` |
| MultiFaceSeam | produced, 64 faces | **not produced**: phase front Produced, then `completion/output-validation/AggregateCompletionValidationFailure`; `a3=4/4/0/0/0` |
| CloseSheets | produced, 200 faces | produced, 242 faces, `a3=8/8/0/0/0` |
| Cylinder | produced, 288 faces, `a3=81/32/0/49/0` | identical to per-arc |
| SmoothRimDisc | **not produced**, same completion failure, `a3=32/32/0/0/0` | **not produced**, same completion failure, `a3=4/4/0/0/0` |

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **Activation would lose an accepted green.** `SurfaceCellDesignAcceptance…/MultiFaceSeam` (gate row 796) passes only on the per-arc path. Flipping the option makes its default run the chained run, which fails at completion | TB112 row 933 `switch-run … chained produced=0` |
| F2 | **The switch's own stages work.** Under chains every fixture's phase front is produced and every scheduled span is covered (`partial=0`, `foreign=0`). On Cylinder the annulus rim stops (RA-228) make the chained run identical to per-arc. The failures come later, in the gate on the completed mesh | TB112 `switch-run` lines |
| F3 | **The failure does not depend on the schedule.** SmoothRimDisc fails the same way under per-arc as under chains. Under per-arc the uniform producer does not take a round domain, so the bounded-disk producer builds it in both runs. The common factor is the bounded-disk producer's output meeting the completed-mesh gate | TB112 row 945 |
| F4 | **The receipt hides which check failed.** `AggregateCompletionValidationFailure` is reported when the completed mesh, before optimization, fails `validate_source_authoritative_final_surface_mesh` with no strict issue and with the feature rails passing. The gate is the conjunction of strict validity and about twenty measures: distances to the source, normals, field alignment, size, angles, warpage, aspect, Jacobian, convexity, valence, topology flags. Only `accepted` reaches the receipt | `RemeshPipeline.cpp:14966–15018`; `SurfaceMeshOptimizer.cpp:2933–2950` |
| F5 | **Vase's registered RED has the same code.** Vase stops at `NotProductionReady:completion` with `AggregateCompletionValidationFailure`. A 352-face disc that fails the same way may be a cheap witness of that class. Whether the cause is the same is not known (RA-225: check a defect can occur before designing its cure) | Census Vase line (TB107–TB112) |

## 3. Decision

1. **Not activated.** `chainRimSchedules` stays off; production stays per-arc. CB131's staging is kept: it is inert with the option off and TB112 shows it byte-identical.
2. **New obligation O41:** a bounded-disk product whose completed mesh fails the final gate with no strict issue. Witnesses: SmoothRimDisc (both schedules) and MultiFaceSeam (chained). Possibly related: Vase. O41 is a precondition of activation.
3. **Measure first.** CB132 prints every input of the gate beside each `switch-run` line (F4). TB113 records them. Then the Review-only `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE` owns O41's cause and fix.
4. **Activation after O41.** After O41, a later Review freezes the flip: remove the option and the per-arc branch, amend the two `RemeshPipeline` tests named by RA-223 §5, and register each boundary fixture's default run as its TB112 `chained` line, with closed surfaces unchanged.

## 4. CB132 — completed-mesh gate receipt (compile only, test only)

[Exact patch](Architecture_M6_CP3_CB132_P13_A4_Completed_Mesh_Gate_Census_Exact.diff): SHA-256 `ccaed2b5ecd4b6c562fdaed313f547f063cbf047225778836bf1eb9683182d90`, 43 lines, keep 2 single-space context lines. Numstat: `32 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`. Base: HEAD `638bc767b` (CB131 source `240d2a19…` plus documentation).

`print_switch_receipt` keeps its `switch-run` line unchanged. When the run has a final validation report, it adds:

`switch-validation case=<name> schedule=<…> accepted=… strict=… quadToSource=p95/max sourceToOutput=p95/max normalP95=… field=median/p95 size=p5/p95 angle=p5/p95 warpage=p95/max aspect=p95/p99 jacobian=min/p5 nonConvex=… boundaryValence=mismatch/targets singularityValence=mismatch/targets tJunctions=… nonManifold=… degenerate=… inverted=… selfIntersecting=… topologyFixed=… featureOrdered=… onComponents=…`

No product source changes.

Mismatch → `M6-CP3-PLAN-P13-A4-COMPLETED-MESH-GATE-CENSUS-STOP`; infrastructure → `M6-CP3-CB132A-P13-A4-COMPLETED-MESH-GATE-CENSUS-ORCH`.

## 5. TB113 — full gate

`M6-CP3-TB113-P13-A4-COMPLETED-MESH-GATE-CENSUS-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB113_P13_A4_Completed_Mesh_Gate_Census_Full_Gate_Case_Manifest.tsv`: TB112's byte for byte, 945 rows, SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026, `SELF_CHECK_PASS cases=945 deferred=81`.

**MATCH needs all of:**
- 945/945.
- Every receipt line TB112 recorded byte-identical, including the ten `switch-run` lines.
- Every `switch-validation` line recorded verbatim.
- For the three failing runs (MultiFaceSeam chained, SmoothRimDisc per-arc and chained), a `switch-validation` line with `accepted=0 strict=0`.

Every other value is evidence.

Mismatch → `M6-CP3-TB113-P13-A4-COMPLETED-MESH-GATE-CENSUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB113A-P13-A4-COMPLETED-MESH-GATE-CENSUS-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE`.

## 6. Follow-on — `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE` (Review agent only)

It reads the failing measures and owns O41. Its tasks:
- Decide whether the bounded-disk lattice, completion, or the gate's thresholds on an unoptimized mesh is wrong.
- Check whether Vase fails the same measure, which needs a Vase receipt if none exists.
- Freeze the fix with its own measuring receipt.

Activation is re-defined only after O41 is met.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64E.3 **COMPLETE** | `M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION` (this record; not activated) | Review |
| 64E.4 | `M6-CP3-CB132-P13-A4-COMPLETED-MESH-GATE-CENSUS` (§4) | implementation agent |
| 64E.5 | `M6-CP3-TB113-P13-A4-COMPLETED-MESH-GATE-CENSUS-FULL-GATE-EXEC` (§5) | implementation agent |
| 64E.6 | `M6-CP3-DEFN-P13-A4-COMPLETED-MESH-GATE` (O41, §6) | **Review agent only** |
| later | Activation definition (flip), after O41 | Review, then implementation |

**Gaps, stated.**
- The receipt is printed only for runs that keep a validation report. The census runs keep it, and so does every completion failure.
- Thresholds are not printed; they live in `SurfaceMeshOptimizer.cpp:2933`.
- Floating values are printed at default precision, which is enough to see which measure is out of range but is not a bit-exact digest.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB113 = TB112 manifest byte for byte; selector497/CP3 unpromoted |
| Decisive claims re-derived | TB112 report, the completion-validation failure branch and the gate's acceptance expression were read by me |
| Runtime-free checks | `-fsyntax-only` returns 0 on `SurfaceCellDesignAcceptanceTests.cpp` with CB132; CB132 applies at HEAD; manifest self-check passes |
| Non-vacuity | `accepted=0 strict=0` on the three failing runs is a MATCH condition; a different failure path goes to REV |
| Obligations carried | 64E.4–64E.6; **new O41**; activation; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB112 945/945, membership 1,026; the two chained completion failures are non-stable candidate evidence only |
| Turn boundary | No product or test source changed in the repository |

# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB2-REV` COMPLETE / PACKAGE120 NOT PROMOTED / EXACT NEXT `M4-CP3-TB2-PLAN`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Test + Benchmark planning boundary, granular subturn `M4-CP3-TB2-PLAN`

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- Package119 / selector394 **394/394** is accepted M4 runtime authority.
- Candidate package120 artifact `10280703200` comes from semantic source `3f909a5a2cfd305d423faf7a260bc465c7b06892`; ZIP SHA-256 `3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4`.
- Selector403 has 403 rows, SHA-256 `e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802`; first394 is byte-identical to accepted selector394 at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`.
- TB2-EXEC run/job `34647838897 / 103422811636` mechanically measured package120 green: focused395-403 **9/9 twice**, prefix394 **394/394**, cumulative403 **403/403**, total **815/815 PASS**, zero RED/SKIP/selection mismatch/timeout, immutable postflight.
- TB2-REV independently upheld those mechanics but **did not promote package120** because row400 fails its frozen non-vacuity obligation.
- Stable accounting remains **47 events / 14 categories / 33 recurrences**; produced-witness debt remains **5**. CP3 is open and A3→A4 cutover is unauthorized.

## Review finding — `M4-CP3-TB2-REV-CAND-01`

R1 required face-barycentric coverage to use a source-face row whose vertex order differs from canonical topology-key order so coordinate remapping is actually exercised. Packaged row400 does this only syntactically:

```cpp
const std::array<int, 3> sourceRow{2, 0, 1};
ASSERT_NE(sourceRow[0], static_cast<int>(face.vertices()[0].index()));
...
canonical_exact_source_face_point(face, barycentric);
```

`sourceRow` never contributes to the source face, coordinate conversion or tested point. The helper receives an already-canonical face key and coordinate array. A missing/swapped source-row→canonical conversion therefore leaves the identity green. This is a structurally invalid fixture / missing scenario coverage finding, not a demonstrated production defect.

Rows395-399 and 401-403 were independently reviewed and satisfy their frozen non-vacuity obligations. Package120's mechanical evidence remains valid evidence about those contracts and about accepted-prefix compatibility; it is insufficient for selector403 acceptance because required row400 proof is missing.

## Exact next — `M4-CP3-TB2-PLAN`

Planning only. Freeze one bounded recovery for row400 with these constraints:

1. use an actual source-face row whose order differs from canonical topology-key order;
2. use distinct barycentric components so a permutation is observable;
3. derive the tested point through the real row→canonical mapping path and require failure if remapping is omitted/swapped;
4. preserve product source absent contradicting evidence;
5. preserve selector403 identity/name/order/hash unless planning proves a selector change unavoidable;
6. require a later immutable artifact-only rerun that re-proves corrected row400 plus accepted selector394 and cumulative selector403 before promotion;
7. do not begin A3→A4 materialization/cutover work.

`M4-CP3-TB1-R1-REV-OBS-01` is still open: region-incidence multiplicity weighting remains unexercised. It was not discharged by CB4-R1. Per `LESSONS.md` 170, do not automatically combine it with the row400 recovery and destroy the one-variable control; TB2-PLAN must assign it to the first later test-source turn where independent falsifiability is preserved.

## Review evidence

- review record: `.agents/Directional/Architecture_M4_CP3_TB2_Review_Record.md`
- consolidated history: `.agents/Directional/M4_Consolidated_Record.md` §§2.19-2.23
- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §§17, 17.12
- accepted runtime report retained: `.agents/Directional/Architecture_M4_CP3_TB1_R1_Test_Benchmark_Report.md`
- selector394: `.agents/Directional/Architecture_M4_CP3_Required_Green_Selector_394.txt`
- selector403: `.agents/Directional/Architecture_M4_CP3_CB4_R1_Required_Green_Selector_403.txt`
- package120 artifact: `10280703200`
- TB2 result artifact: `10283220925`, provider SHA-256 `314428caf9b240b992f56a48a471e210c0c8361331004d7a0a268ea9fbca4c6f`
- TB2 diagnostic artifact: `10283302336`
- review closeout patch apply: run `34653151816`, semantic closeout commit `842137328e66f140839747b625dcd2bb152a48eb`
- review cleanup: run `34653302681`, cleanup commit `bf6f4fc09e0fd5b0d1aee110c51341e887ca26f9`
- temporary closeout workflow and markers retired; exactly seven durable workflows remain; `.agents/connector-triggers` contains only the durable `source-snapshot` namespace
- consumed Google Drive review patch permanently deleted after successful application

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB-PLAN.md
conditional_modules:
  - trigger: test-scenario correction design
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB2_Review_Record.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/M4_Consolidated_Record.md
do_not_preload:
  - A3-to-A4 cutover implementation
  - unrelated historical M3 records
  - new runtime evidence; planning consumes the reviewed evidence already frozen
```

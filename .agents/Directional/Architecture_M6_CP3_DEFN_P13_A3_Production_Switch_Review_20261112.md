# RA-230 — Production switch definition, O36 (step 64E)

Turn `M6-CP3-DEFN-P13-A3-PRODUCTION-SWITCH`, Review agent only, runtime-free. RA-228 §7 authorized it on TB110 MATCH (944/944; the annulus reads its rims). Inputs: the O36 list in RA-226 §9 and RA-223 §5, the RA-228 annulus clause, and TB110.

## 1. What the switch is

Two changes, one definition:
- **D5:** the pipeline builds A3 from `make_chained_global_conformity_baseline_input` instead of one span per arc.
- **D4:** the uniform producer declines every region under a plan, so a producer that reads the plan builds it.

## 2. Findings

| # | Finding | Evidence |
|---|---|---|
| F1 | **D5 alone does not move every region off the uniform producer.** The uniform producer treats a plan as chained only when it has fewer spans than arcs. A fixture whose chained plan has no multi-arc chain would stay with a producer that reads no A3. D4 must be an explicit condition | `SurfaceCellTracing.cpp`, uniform producer's `chainedPlan` check (CB118) |
| F2 | **Everything the switch needs exists in the pipeline before A3.** The face axes (`faceAxisX/Y`), the field transport atlas, the A1 regions, the feature curves and the network are all built before `build_global_conformity_baseline`. The corner product and the chained factory need nothing new | `RemeshPipeline.cpp:12707–13043` |
| F3 | **The annulus rims can be named before A3.** The annulus producer takes A1 regions with Euler characteristic 0 and two boundary loops. Stopping chains at every boundary vertex of those regions is conservative: an extra stop only splits a chain. On Cylinder it breaks the two two-arc chains behind the 28/32 result | `SurfaceTopologyRegion::euler_characteristic`, `boundary_loop_count`; RA-228 §1 |
| F4 | **O37 is a cost item.** `breakpoint_location` validates the runs and recomputes every run weight (a big-integer square root) on each call. A span's `count + 1` breakpoints cost `count × runs` roots. One pass with a monotone run pointer gives the same values | `GlobalConformityBaselineSupport.cpp:299–360` |
| F5 | **The flip cannot be registered runtime-free.** It changes the plan of every fixture with a source boundary, moves Plane, MultiFaceSeam and CloseSheets off the uniform producer, and changes Cylinder's annulus spans. Where opposite sides differ in metric length (RA-223 F4), it may turn an accepted row red. No receipt yet shows what the chained pipeline builds on the real fixtures or on a smooth-rim disc | RA-223 F4; RA-226 §9 ("pipeline receipt on a smooth-rim disc owed") |

## 3. Definition

1. **The switch input.** Stops are the boundary field corners (`derive_boundary_field_corner_vertices`, O38) plus the annulus rim vertices (`derive_annulus_rim_stop_vertices`, F3). The schedule is the chained factory over those stops. A failed chained input fails the pipeline at `global-conformity-baseline/chained-input`.
2. **D4.** Under a plan the uniform producer declines every region (`SurfaceCellTracingOptions::declinePlannedUniformRegions`).
3. **O37.** `GlobalConformityBaselinePlan::breakpoint_locations(span)` returns ordinals 0..count in one pass, each equal to `breakpoint_location`. `edge_arc_schedule` uses it.
4. **Staged.** Items 1–2 are behind `SurfaceCellOptions::chainRimSchedules`, off by default. Production keeps per-arc schedules until the activation turn. That turn flips the option, removes it and the per-arc branch, and amends the tests RA-223 §5 named.
5. **O-list after this record.**
   - O34 is narrowed: a rim with no corner and no annulus stays per arc.
   - O35 is met on the rectangular fixture.
   - O38 is wired behind the option.
   - O39 is discharged.
   - O37 is defined here (CB131).
   - The smooth-rim disc receipt is defined here (CB131).
   - Still open, for activation: the digest and cell-count plan, and the two `RemeshPipeline` test amendments.

## 4. CB131 — switch staging (compile only)

[Exact patch](Architecture_M6_CP3_CB131_P13_A3_Rim_Chain_Switch_Staging_Exact.diff): SHA-256 `571ae1ef904420af6a2919379f8326d0d80b85c2390f02b4317c1c488b10021c`, 423 lines, keep 11 single-space context lines. Base: HEAD `4963dcba7` (CB129 source `4bef62be…` plus documentation).

| File | Numstat |
|---|---|
| `include/directional/geometry/GlobalConformityBaseline.h` | `4 0` |
| `include/directional/geometry/SurfaceCellTracing.h` | `13 0` |
| `include/directional/pipeline/RemeshPipeline.h` | `5 0` |
| `src/geometry/GlobalConformityBaseline.cpp` | `10 0` |
| `src/geometry/GlobalConformityBaselineSupport.cpp` | `55 0` |
| `src/geometry/GlobalConformityBaselineSupport.h` | `8 0` |
| `src/geometry/SurfaceCellTracing.cpp` | `28 11` |
| `src/pipeline/RemeshPipeline.cpp` | `31 4` |
| `tests/SurfaceCellDesignAcceptanceTests.cpp` | `113 0` |

- **Product (definition items 1–3):** with the option off, the only production-path change is O37 inside `edge_arc_schedule`, which must give identical values.
- **Census rows 932–935:**
  - Each fixture runs once more with `chainRimSchedules = true`. Both runs print `switch-run case=<name> schedule=<perArc|chained> produced=… faces=… failure=… phaseFront=… invalid=… a3=scheduled/covered/partial/unrecorded/foreign`.
  - Every span of the per-arc, chained and stopped plans is checked: batch locations equal per-ordinal locations (`EXPECT`).
- **New row 945,** `SurfaceCellDesignSwitchReceipt.SmoothRimDiscUnderBothRimSchedules`: a flat 32-segment, 6-ring disc with a constant field, run with the option off and on. Receipt only.

Mismatch → `M6-CP3-PLAN-P13-A3-RIM-CHAIN-SWITCH-STAGING-STOP`; infrastructure → `M6-CP3-CB131A-P13-A3-RIM-CHAIN-SWITCH-STAGING-ORCH`.

## 5. TB112 — full gate

`M6-CP3-TB112-P13-A3-RIM-CHAIN-SWITCH-STAGING-FULL-GATE-EXEC`. Manifest `gates/Architecture_M6_TB112_P13_A3_Rim_Chain_Switch_Staging_Full_Gate_Case_Manifest.tsv`: TB111's 944 rows plus row 945. SHA-256 `16a909bd6d3fe2b9ba37d263b89fb8ca16dcc3dd42214e4cabcae26c05c91020`, membership 1,026, `SELF_CHECK_PASS cases=945 deferred=81`.

**MATCH needs all of:**
- 945/945, so the O37 equality holds on all three schedules of four fixtures.
- Every receipt line TB110 recorded is byte-identical, with the option off. That includes the row 729 `annulus-read`/`annulus-pair` lines, the 12 `annulus-rim`, the 4 `d4-rim` and `rim-branch` lines, and the census platform-digest and `a3-coverage` lines.
- The ten new `switch-run` lines recorded verbatim: two per census case plus two for the disc.
- Each `schedule=perArc` line agrees with its fixture's existing evidence: `produced=1`, and its `a3` counts equal the same case's `a3-coverage` scheduled/covered/partial/unrecorded/foreign values. The disc's per-arc line is evidence only.

The `chained` lines are evidence, not pass conditions.

Mismatch → `M6-CP3-TB112-P13-A3-RIM-CHAIN-SWITCH-STAGING-FULL-GATE-REV`; infrastructure → `M6-CP3-TB112A-P13-A3-RIM-CHAIN-SWITCH-STAGING-ORCH`. On MATCH close with `Successor: M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION`.

## 6. Follow-on — `M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION` (Review agent only)

It reads the ten `switch-run` lines. If every fixture produces under `chained`, it freezes the flip:
- remove the option and the per-arc branch; the uniform producer always declines under a plan;
- amend `RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b` and `A3SourceRimIntervalsAreRecordedSingleSidedAndValidated`;
- register the digest changes: closed surfaces unchanged; every boundary fixture's default run equal to its TB112 `chained` line.

If a fixture fails under `chained`, it decides that fixture's owner first: an A4 construction for unequal opposite sides (RA-223 F4, 65C), or a narrower stop rule.

## 7. Sequence

| Step | Turn | Owner |
|---|---|---|
| 64E **COMPLETE** | `M6-CP3-DEFN-P13-A3-PRODUCTION-SWITCH` (this record) | Review |
| 64E.1 | `M6-CP3-CB131-P13-A3-RIM-CHAIN-SWITCH-STAGING` (§4) | implementation agent |
| 64E.2 | `M6-CP3-TB112-P13-A3-RIM-CHAIN-SWITCH-STAGING-FULL-GATE-EXEC` (§5) | implementation agent |
| 64E.3 | `M6-CP3-DEFN-P13-A3-SWITCH-ACTIVATION` (§6) | **Review agent only** |
| then | Activation CB → TB, frozen by 64E.3 | implementation agent |

**Gaps, stated.**
- Closed surfaces and the gate's other pipeline rows run only per-arc until activation.
- The `switch-run` receipt shows what was built, not why a run failed beyond the first invalid producer stage.
- The annulus stop rule also stops Euler-0 regions the annulus producer does not take, for example when the field has singularities. That only shortens chains.
- With the option on, the census test's per-arc comparison against its own inputs does not apply to the chained run, which is why that run prints a receipt only.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB112 = TB111's 944 rows byte for byte plus row 945; selector497/CP3 unpromoted |
| Decisive claims re-derived | Uniform producer decline, pipeline A3 site and the products before it, the chained factory, the corner product, `SurfaceTopologyRegion`, the locator and `edge_arc_schedule` were read by me |
| Runtime-free checks | `-fsyntax-only` returns 0 on `GlobalConformityBaselineSupport.cpp`, `GlobalConformityBaseline.cpp`, `SurfaceCellTracing.cpp`, `RemeshPipeline.cpp` and `SurfaceCellDesignAcceptanceTests.cpp` with CB131; CB131 applies at HEAD; manifest self-check passes |
| Non-vacuity | The O37 equality is an `EXPECT` over every span of three schedules on four fixtures; the per-arc `switch-run` lines must reproduce the existing coverage evidence, so a broken receipt goes to REV |
| Obligations carried | 64E.1–64E.3; activation; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (narrowed); P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, deferred 81; TB110 944/944, membership 1,025 |
| Turn boundary | No product or test source changed in the repository |

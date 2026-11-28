# RA-223 — Adversarial re-review of the D4 uniform plan consumption definition (step 64C)

**Turn:** `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION` (64C, re-entered). **Disposition: COMPLETE; [RA-222](Architecture_M6_CP3_DEFN_P13_A3_Uniform_Plan_Consumption_Review_20261110.md) is amended.** Its decision (the uniform producer declines under an A3 plan) and its CB117 and TB98 stand. One turn pair is added, CB118 → TB99, and TB98's MATCH route changes to CB118. Runtime-free. Three read-only audits were delegated to subagents (§2).

## 1. Findings against RA-222

| # | Finding | Kind | Action |
|---|---|---|---|
| F1 | **RA-222 decided a rule and froze nothing that executes it.** CB117 counts rim intervals. No frozen turn runs the bounded-disk producer on a region without a hard feature, which is the whole risk of the decision. The switch would have been frozen blind | Trajectory | New CB118 (§3): the uniform producer declines a **chained** plan. Production plans are not chained, so it is neutral; a test injects a chained plan on a plain square and observes which producer builds it |
| F2 | **"The bounded-disk producer handles plain regions" was asserted, not checked.** RA-222 cited the non-cut-domain branch without reading its entry conditions | Accuracy | Audited (§2): the region must be a disc (Euler characteristic 1) with at least 4 boundary edges and a simple boundary cycle; nothing requires a hard feature or curvature. Two helper predicates were not read to the end, so the outcome on a plain square stays a measurement (CB118 receipt), not a claim |
| F3 | **The annulus producer sits between the two.** After the uniform producer declines, the region is offered to the annulus producer first. RA-222 did not check that it passes a disc on instead of rejecting it | Accuracy | Audited: it returns `NotApplicable` at the Euler test (`euler != 0`, `:14333`), before any rejecting check that a valid disc can hit |
| F4 | **The "Plane: 4 sides" prediction rested on an unread predicate.** Sides exist only if the feature map flags the rim's corners | Accuracy | Audited: `is_corner` flags a vertex when the angle between its two curve edges, taken as lines, is at least 45°. A square's corners qualify. **Defect found for 64B.13:** the test uses the absolute value of the dot product, so a turn sharper than 135° reads as nearly straight and is not a corner |
| F5 | **Uncut closed rims were not considered.** A closed boundary rail with no stop stays per arc (O34), so its plan is not chained. A smooth disc's rim has no flagged corner at all | Design | The staged rule in CB118 does not cover such regions; the final rule ("any plan", with O36) does. O34 is now a named precondition of the D4 switch, to be closed by the corner product of 64B.13 (corners cut the rim) |
| F6 | **RA-222 §3's oracles had no home.** "Positive coverage, omission falsifier, row permutation" were listed for a future TB | Test | CB118's test carries the positive coverage implication and the row permutation now. The omission falsifier already exists on the rectangular fixture (RA-215) |

The CB117 patch itself was re-read: the retained-products flag does keep the trace network (`RemeshPipeline.cpp`, `retainForExecution` branches), the plan, baseline and network snapshots are assigned unconditionally, and the existing digest helper is untouched. No change to CB117.

## 2. Delegated audits (Haiku subagents, read-only)

| Audit | Result used |
|---|---|
| Feature-curve corner predicate (`AdaptiveFeatureMap.h:778–809`) | Line-angle test against `cornerAngleDegrees = 45`; evaluated at every two-edge vertex of a closed all-boundary curve; no class check; `finalize_curve` has no caller (F4) |
| Producer applicability on a flat disc with a plan and no hard feature | Annulus: `NotApplicable` at `:14333`. Bounded disk: passes its Euler and boundary-size gates and builds the boundary cycle from the single-incidence edges; `source_edge_is_authoritative_local_boundary` and the chart-availability check not fully read (F2, F3) |
| CB117 diff | No change needed. The plan, baseline and network snapshots are assigned unconditionally; the trace network is kept whenever products are retained; the input conditioner copies vertices unchanged, so `inputs=own` is expected; a rim edge's route is non-empty and made of boundary steps; the patch removes no line, so the existing digest lines are untouched. Its one reported defect (an unchecked `find_arc_binding`) is unreachable: a built baseline binds every arc |

## 3. CB118, frozen — the uniform producer declines a chained plan

- [Patch](Architecture_M6_CP3_CB118_P13_A3_Uniform_Declines_Chained_Plan_Exact.diff): SHA-256 `5e0837d07a2fc46e96cabd73ca0bab6c587f1bca0c6992c43c4245b81fc8976b`, 135 lines, 2 single-space context lines. Numstat `9 1` `SurfaceCellTracing.cpp`; `87 1` `SurfaceCellsPhase10Tests.cpp`. It applies at HEAD and after CB117 (the two touch different files).
- **Rule.** A chained plan schedules fewer spans than the topology has arcs. Under such a plan the uniform producer returns `NotApplicable` for every region. Under a per-arc plan it behaves as before (declines hard-feature regions only).
- **Why this is a stage and not a flag.** The uniform lattice cannot place a chain's breakpoints at all, so this half of the D4 rule is unconditional. The other half (decline per-arc plans too) is the production switch and stays with O36.
- **Neutral for production:** the pipeline builds the per-arc input, so span count equals arc count. The only accepted tests that inject a chained plan (rows 930–931) use a fixture whose regions all touch a hard rail and were already declined.
- **Test (GUARD 936)** `D4UniformProducerDeclinesAChainedPlan`, on the two plain 2×2 squares (the rectangular fixture built without its hard rail), for both face-row orders:
  - the chained input has chains and fewer spans than arcs;
  - **if the chained plan produces**, the product has bounded-disk boundary phases and every scheduled span is covered, with none unrecorded, partial or foreign.
  - The dispositions and coverage under both plans are printed: `D4_UNIFORM_RECEIPT plan=perArc|chained disposition=… reason=… cells=… discPhases=… scheduled=… covered=… unrecorded=…`.
- **Non-vacuity.** Without the rule the uniform producer builds the chained plan's regions, with no disc phase and every rim span unrecorded, and the test fails. If the bounded-disk producer rejects, the implication is vacuous and the receipt carries the reason; that is the evidence the switch needs either way.
- **Checks:** `-fsyntax-only` returns 0 on both files.

## 4. TB99, frozen

- [Manifest](gates/Architecture_M6_TB99_P13_A3_Uniform_Declines_Chained_Plan_Full_Gate_Case_Manifest.tsv): 936 rows, SHA-256 `c137e3f81c75e94ed9596c59b3065e535bd678c05de178501b60923563249d2d`. It is TB98's 935 rows byte for byte, plus GUARD 936. `SELF_CHECK_PASS cases=936 deferred=81`; membership 1017.

| Outcome | Route |
|---|---|
| 936/936 PASS; all 7 platform-digest and 7 a3-coverage lines byte-identical to TB97; census unchanged; both `D4_UNIFORM_RECEIPT` lines recorded verbatim | MATCH → `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (64B.13, **Review agent only**) |
| Row 936 fails, any regression in 1–935, or any digest change | MISMATCH → `M6-CP3-TB99-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN-FULL-GATE-REV` (Review) |
| Infrastructure | `M6-CP3-TB99A-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN-ORCH` |

**Registered predictions (not pass conditions).** `plan=perArc`: Produced by the uniform producer, `discPhases=0`, rim spans unrecorded. `plan=chained`: Produced, 4 cells per square (8 in all), every span covered.

**TB98 route amended:** MATCH → `M6-CP3-CB118-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN` (was 64B.13). Everything else in RA-222 §5 stands.

## 5. Sequence and obligations

| Step | Turn | Owner |
|---|---|---|
| 64C | `M6-CP3-DEFN-P13-A3-UNIFORM-PLAN-CONSUMPTION`: COMPLETE (RA-222 as amended here) | Review |
| 64C.1 | `M6-CP3-CB117-P13-A3-RIM-CENSUS-RECEIPT` (RA-222 §4; test only, compile only) | implementation agent |
| 64C.2 | `M6-CP3-TB98-P13-A3-RIM-CENSUS-RECEIPT-FULL-GATE-EXEC` (RA-222 §5; MATCH → 64C.3) | implementation agent |
| 64C.3 | `M6-CP3-CB118-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN`: exact patch §3, compile only. Mismatch → `M6-CP3-PLAN-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN-STOP`; infrastructure → `M6-CP3-CB118A-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN-ORCH` | implementation agent |
| 64C.4 | `M6-CP3-TB99-P13-A3-UNIFORM-DECLINES-CHAINED-PLAN-FULL-GATE-EXEC` (§4) | implementation agent |
| 64B.13 | `M6-CP3-DEFN-P13-A3-DISC-CORNER-STOPS` (O38); reads the `d4-rim` and `D4_UNIFORM_RECEIPT` lines, and F4's corner defect | **Review agent only** |
| 64D | `M6-CP3-DEFN-P13-A3-ANNULUS-PLAN-CONSUMPTION` | **Review agent only** |
| later | D5 switch, then D4 uniform switch (O36): one definition, two CBs | Review, then implementation |

**O36 preconditions, complete list.**

| Condition | State |
|---|---|
| Mixed stage produces, or hard-feature rails chain (O35) | Met on the rectangular fixture (TB97); other classes by the `d4-rim` lines |
| Disc corners are stops (O38) | Decided; 64B.13. Must also fix or bypass the 135° blind spot (F4) |
| Closed rims are cut (O34) | Open; the corner product of 64B.13 cuts them where corners exist. A rim with no corner at all stays per arc and stays with the uniform or annulus producer |
| Breakpoints located in one pass (O37) | Open |
| The bounded-disk producer builds plain regions | The TB99 receipt |
| Switch TB pre-registers digest changes and amends the named tests | Open |

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB99's rows 1–935 are TB98's manifest byte for byte. Selector497/CP3 is unpromoted |
| Decisive claims re-derived | §1–§2; the retention branches in `RemeshPipeline.cpp` and the uniform producer's decline site were read directly |
| Non-vacuity | §3 |
| Obligations carried | 64C.1–64C.4; 64B.13 (O38, with F4); 64D; D9c 65A; trace 65B; A4 65C; D8 65D; D6 user decision pending; O34 (now an O36 precondition); O35; O36; O37; P13-e, O30b, O31, O32b–e, O33 |
| Stable accounting | CP2 491/491, stable 66/17/49, debt 1, 81 deferred; TB97 931/931, membership 1012; selector497/CP3 unpromoted |
| ORIENTATION / CHANGELOG / LESSONS / tracker / DESIGN §7.4 / handoff / TODO | Updated |
| Turn boundary | No product or test source changed in the repository |

# M4-CP-SCALE-TB2-REV — Independent Review Record

**Turn:** `M4-CP-SCALE-TB2-REV`
**Decision:** **REJECT CANDIDATE / TEST-AUTHORITY PRECONDITION FAILURE / NON-STABLE**
**Accepted runtime authority remains:** package `10360085644`, semantic source `a359b981f9350139304bc5a654041dfba78609b6`, selector423 **423/423**
**Rejected candidate:** package `10367451675`, semantic source `63cb20d6ba5393058086c62c6422ac58b75c939e`
**Exact successor:** `M4-CP-SCALE-CB3`

## 1. Review boundary and evidence reopened

This was a runtime-free Review. Primary TB2 bytes were re-opened independently rather than accepted from the EXEC report: result artifact `10370015436`, diagnostic-log artifact `10369796116`, and candidate package artifact `10367451675`. The nested evidence archive re-verifies at SHA-256 `06e4db5b1701d90830dad4ddaa4f3015566b8a6ce75f38a71e94e4f06118cb61` with all **12/12** non-self manifest entries valid. Candidate package provenance remains semantic source `63cb20d6ba5393058086c62c6422ac58b75c939e`, provider ZIP SHA-256 `9a1b59bcbf6cbe14e1df180b0feaaeec6bf9e675d010f66303bc39cf4c83ddec`, packaged source SHA-256 `de4667b5677ba3b60ae1737299ae3edb111cefa453e6ac4cc3f7357fe3607f27`, and package manifest SHA-256 `b229f38237f3e3f00dfd70f5f4f28f8faae0af9a888609c2c397b6fb8af1e47b`.

The focused raw log independently proves exact selection of `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`: **1 selected / 0 OK / 0 skipped / exit 1**, no timeout and no crash. The first subject, `positive-strict-interior`, fails at `ASSERT_TRUE(atlasBuild)` before `resolve_field_vertex_transit(...)` and before any six-subject S2 receipt. Therefore the runtime contains **zero comparator-equivalence evidence**.

## 2. Accepted selector authority independently re-hashed

`Architecture_M4_CP_COND_CB5_Required_Green_Selector_423.txt` is independently re-hashed to **423 LF rows / `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`**. Its first 422 rows hash to accepted selector422 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`. TB2 never executed selector423, so TB2 adds no accepted-prefix runtime credit and cannot alter the accepted TB1 authority.

The historical M3 selector374 contains `ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection`, but that row is **not** in the current M4 selector423 lineage. It is nevertheless relevant static provenance because the project already classified the same folded-cone field helper as invalid test authority. No historical selector byte is changed by this Review.

## 3. Root cause independently re-derived from source

The TB2 failure is not a vertex-star filter defect. It is a recurrence of the already-durable `M3-CP4c3-TB7-CAND-02` witness-precondition defect recorded in `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md` §7/§8, `TODO.md`, and `LESSONS.md` 22r.

The derivation is exact and seed-independent:

1. `make_three_right_angle_cone_fan()` creates three faces meeting at the center with three exact right-angle sectors, so the total cone angle is `Theta = 3*pi/2` and the center angle defect is `K = pi/2`.
2. `make_folded_cone_vertex_field_with_seed(...)` begins from `make_zero_transport_field(mesh)`. That helper declares `effort == 0` on every edge and supplies no singularities.
3. The S2 helper changes only face-0 primary/secondary directions and then assigns the same radial matching pattern used by the historical folded-cone helper: two center-radial matchings of `2` and the third `0`. Around the center those quarter-turn lifts compose to `0 mod 4`, independent of the integer seed.
4. `FieldTransportAtlas::make` independently derives the cycle lift from `(cycles * effort + 4 * cycleCurvature) / 2*pi`. With zero effort and `K = pi/2`, the center cycle has exact lift `1`.
5. Atlas authority requires the composed quarter-turn transport to equal that turning lift modulo 4. Here `0 != 1`, so the legitimate product result is `FieldAtlasBuildErrorCode::CycleTransportMismatch`. A further `SingularityMismatch` would remain behind it because the helper supplies no center singularity despite nonzero lift.

This is exactly the already-recorded `make_zero_transport_field` silent precondition: it is valid only when every interior vertex is intrinsically flat. The S2 CB2 plan stated that Filter and ExactFallback were already reachable, but CB2 reused a known non-flat witness whose helper was already classified invalid. The new `(1,2)` subject merely exposed the first unreachable subject in array order; **all six CB2 S2 subjects inherit the same atlas-invalid field authority**, including the historical `(2,1)` and `(1,1)` seeds.

Therefore `M4-CP-SCALE-TB2-EXEC-CAND-01` is **CLOSED / CLASSIFIED TEST-AUTHORITY PRECONDITION FAILURE / DUPLICATE ROOT OF `M3-CP4c3-TB7-CAND-02` / NON-STABLE**. The atlas is correctly enforcing its existing consistency contract. No product `src/` or `include/` repair is authorized.

## 4. S2 non-vacuity adjudication

The frozen S2 semantic contract remains valid: certified Filter results must agree with independent exact authority, and inconclusive cases must defer to ExactFallback. What TB2 disproves is the earlier reachability premise, not that contract.

S2 therefore remains **UNPROVED / NON-SELECTOR**. Candidate package `10367451675` receives no S2 proof, selector, promotion, or gate credit. A corrective test must first establish atlas-admissible **regular** vertex-star subjects. In particular, merely logging the atlas error or reordering the six subjects would not repair non-vacuity; the comparator must actually execute on transport-consistent field authority.

The corrective owner is test authority. Production already exposes the accepted field producer (`make_raw_cross_field` + `finalize_cross_field_result`, which invokes `principal_matching` and derives matching/effort/singularities). CB3 must use that authority or an equivalently proven production derivation, independently assert the center is regular and the atlas builds, and only then test the vertex-star Filter/ExactFallback equivalence. It must not weaken atlas validation or repair the separate historical ordinal374 identity opportunistically.

## 5. TB2 execution-evidence defect

TB2's semantic fail-fast after the focused RED was correct, but its evidence harness did not satisfy the frozen plan's remainder requirement. Selector423 was **0/423 executed** and full post-runtime census was not reached, yet the evidence omitted an explicit 423-row `UNEXECUTED` remainder ledger.

This does not weaken the semantic RED and does not create a stable product regression. Record `M4-CP-SCALE-TB2-REV-OBS-01` as **OPEN / EXECUTION-EVIDENCE CONTROL / FAIL-FAST REMAINDER RECEIPT REQUIRED / NON-STABLE**. The next artifact-only harness must initialize the entire expected selector ledger before runtime so any focused fail-fast leaves every untouched row explicitly marked unexecuted, and it must still emit immutable package/source/execution-view census material on the failure path. Static harness review must verify that cleanup/finalization cannot bypass those receipts.

No runtime retry is authorized in Review.

## 6. Authority and accounting decision

**REJECT candidate `10367451675`.** Accepted runtime authority remains package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423**. No accepted selector identity changed from PASS to RED because selector423 did not execute in TB2 and S2 is outside it.

Stable accounting therefore remains **49 events / 14 categories / 35 recurrences**. Produced-witness debt remains **5**. The repeated helper mistake is a non-stable test-authority recurrence under existing `LESSONS.md` 22r, not a new accepted-regression event or stable recurrence.

## 7. Prior obligations

| Obligation | Review disposition |
|---|---|
| `M4-CP-SCALE-TB1-REV-OBS-01` — S1 calibration | **CARRY.** No numeric threshold becomes justified by TB2. |
| `M4-CP-SCALE-DEFN-OBS-01` — arrival-order exact fallback absent | **CARRY.** Separate from vertex-star S2. |
| `M4-CP-SCALE-DEFN-OBS-02` — S3 exact-repeat witness | **CARRY.** |
| `M4-CP-SCALE-DEFN-OBS-03` — S4 independent incremental oracle/reachability | **CARRY.** |
| `M4-CP-SCALE-DEFN-OBS-04` — S5 genus>=2 coverage | **CARRY.** |
| `M4-CP3-TB1-R1-REV-OBS-01` — multiplicity-2 oracle | **CARRY** before cumulative M4-CP4. |
| `M4-CP3-CB4-REV-OBS-02` — row399 divergence tamper | **CARRY** to next legitimate row399 touch. |
| row408 provenance warning | **CARRY / historical-bound.** |
| `M3-CP4c3-TB7-CAND-02` — historical ordinal374 invalid folded-cone witness | **CARRY / separate owner.** CB3 must not silently repair it; S2 may reuse the root-cause lesson but must isolate its own test authority. |
| `G4-B002` / `G4-B003` produced-witness debt | **CARRY 3 / 2**; total debt 5. |
| `M4-CP-SCALE-TB2-REV-OBS-01` — fail-fast remainder receipt | **NEW / CARRY** into the next artifact-only harness. |

## 8. Exactly one successor

Freeze **`M4-CP-SCALE-CB3`** under `Architecture_M4_CP_SCALE_CB3_Code_Build_Plan.md`.

CB3 is a bounded **test-authority correction + compile/package** turn. It may modify only `tests/FieldAlignedCurveNetworkTests.cpp` for S2 semantics, must construct a separate atlas-admissible regular folded-star field from production matching/effort authority, must prove the precondition before invoking the comparator, must retain the same independent exact-oracle obligations and both Filter/ExactFallback route non-vacuity, and must leave production/API/CMake/fixtures/selectors and historical ordinal374 authority unchanged. Any need for product semantics returns to Review.

If compile/package succeeds, CB3 may freeze an artifact-only `M4-CP-SCALE-TB3-EXEC` plan. That plan must also close `M4-CP-SCALE-TB2-REV-OBS-01` structurally by pre-initializing the selector remainder ledger and preserving failure-path census evidence. No runtime occurs in CB3.

## 9. Consolidation

Under `CLEAN_UP_POLICY.md`, this Review preserves all load-bearing CB2/TB2 facts in this record, `M4_Consolidated_Record.md` §2.50, the tracker/changelogs, handoff and roadmap, then folds the superseded TB1 Review, consumed CB2 plan/report, consumed TB2 plan and failed TB2 report. The retained CP-SCALE set is the normative frozen definitions, accepted TB1 runtime-authority report, this current TB2 Review, exactly one CB3 plan, `M4_Consolidated_Record.md`, selector files and durable trackers/changelogs. Full folded text remains recoverable from git history.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | PASS — selector423 **423 LF rows / `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`**; first422 `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`. |
| Decisive claims independently re-derived | PASS — primary TB2 result/log/package bytes reopened; 12/12 nested manifest verified; focused 1/1 RED reconstructed; exact folded-cone curvature/zero-effort/transport mismatch independently derived from source; prior durable root-cause record cross-checked. |
| Non-vacuity checked | FAIL for candidate, decisively — comparator never executes and every six-subject case inherits the same atlas-invalid field authority. This is the reason candidate promotion is rejected. |
| Prior obligations discharged/carried | All listed in §7; none silently discharged. New `M4-CP-SCALE-TB2-REV-OBS-01` owns failure-path evidence completeness. |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted package `10360085644`, selector423 **423/423**. |
| New candidates/obligations recorded | No new product regression. `M4-CP-SCALE-TB2-EXEC-CAND-01` closed as duplicate-root test-authority precondition; `M4-CP-SCALE-TB2-REV-OBS-01` added for fail-fast remainder evidence. Tracker updated. |
| ORIENTATION currency line | Updated to `M4-CP-SCALE-TB2-REV`, 2026-09-14; candidate rejected, exact next CB3. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 authority/status corrected; §4 witness table unchanged because no milestone witness state changed; §7 prioritizes CB3 and retains separate ordinal374 owner; §8 records this as another existing 22r helper-precondition instance plus the evidence-remainder control. |
| CHANGELOG | Root and Directional changelogs updated with rejection, exact root cause, evidence observation and successor. |
| ROADMAP | Updated to TB2 Review rejection and bounded CB3 next. |
| Selector manifest | n/a — no selector byte, selector role, or accepted selector/package lineage changed; selector423 remains the manifest's accepted current selector. |
| LESSONS | No new lesson. Existing **22r** already states this exact `make_zero_transport_field` non-flat-star failure mode; existing evidence-provenance lessons cover the fail-fast receipt issue. |
| Consolidation under CLEAN_UP_POLICY | Folded TB1 Review (132 lines), CB2 plan (128), CB2 report (103), TB2 plan (109), and TB2 report (52) after facts were preserved in this Review, §2.50, tracker/changelogs and handoff. |
| Successor frozen | Exactly `M4-CP-SCALE-CB3`; falsifiers/STOP rules are frozen in `Architecture_M4_CP_SCALE_CB3_Code_Build_Plan.md`. |
| Turn boundary held | PASS — runtime-free Review; no Directional runtime/build/package and no product/test/fixture/selector/benchmark/build-source mutation. |
| review_check.py boundary | **PASS** — `review_check.py boundary --expect-selector 423=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343` reports ALL CHECKS PASSED; no product/test/fixture/build or selector mutation. |
| Pushed to origin, branch in sync | **PASS AT TURN CLOSEOUT** — exact-base durable Review patch is applied, temporary workflow/connector state is removed workflow-first, branch/PR authority is re-read, and no local-only Review work remains before the final PR comment. |

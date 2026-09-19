# M4-CP4-TB1-R2-REV — mandatory runtime-free Review + Plan

**Turn:** `M4-CP4-TB1-R2-REV`
**Result:** **COMPLETE / R2 EVIDENCE TRUSTWORTHY / FOUR FOCUSED REDS CLASSIFIED TEST-AUTHORITY / BOUNDED CB4 REQUIRED**
**Reviewed runtime:** run/job `35417670510 / 105829346816`
**Reviewed candidate:** artifact `10575545321`, source `ad54c12774e10480fd3cef8138cacb8d5dec1529`
**Review boundary:** runtime-free

## 1. Independent evidence re-verification

Review re-opened the immutable R2 result/log evidence and exact source authority rather than accepting the EXEC report as an oracle. The runtime event SHA is `50b0fade072dd4cd938f7f2990ad0195dd4ff365`; frozen harness/caller receipts are 19,885 bytes / `78ab110f8ad851b66fcc331ef02b3a02388f51147efcd4672f2c9bfc7fd750dd` and 4,974 bytes / `e21b17f12b18b7e3a45d97dba322a063cc8a64cf911e040fb6bbe60f832e5a2d`. Candidate ZIP/source/source-archive identities remain `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00` / `ad54c12774e10480fd3cef8138cacb8d5dec1529` / `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed`; the 28-entry package manifest, five clean receipts, GMPXX+GMP evidence and archived owner executable modes are intact.

The full 433-row ledger independently parses as **429 PASS / 4 RED**: focus **2 PASS / 4 RED**, selector **427/427 PASS**. Every executed row selected exactly one test; skips are zero and benchmark count is zero. Selector427 re-hashes to `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` with owners **30 / 281 / 75 / 41**. Package/source/execution-view before/after census hashes are respectively `02e64671eaeeaeeade7925430d9164d35ba32bba23943bab26f886732c7ee0a4`, `da9332f2c6d0f38f6d49071ad6cac085f4bdc9643fc09159a664dc2e059ca742`, and `bafff98c84d712eb85ebb2074ba5038e29f2c7d319836bc0ccbfb668b1808f85`; each before/after pair is byte-identical. The recursive result manifest verifies. All configure/compile/relink/discovery/repair/mutation counters are zero.

Review source authority is source-snapshot run/job `35419817813 / 105835274383` at exact event SHA `2b82aa4c9e3a5dd1e2d3dc93e457d5eabc7a43dc`, artifact `10577556005`, provider SHA-256 `d13d9a6261342fa0d493ca28bcb93610c96a8d76a8ffb5817d3de671ed6ea965`. No generated Directional runtime executed during Review.

## 2. Focused adjudication

### 2.1 Row 1 — production-baseline work receipt: REVIEWED PASS

`M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` is non-vacuous. The test builds the production baseline, independently reconstructs the producer and validator schedules, and checks producer `1+2E`, validator `1+2E`, successful aggregate `2+4E`, canonical fixed-prefix progress, per-call terminal/matching dimensions, zero retries/resets, terminal pending/remaining counts and report-only exact-width evidence. Its tamper surface independently rejects count/order/progress/dimension/width disagreement. **CP4 work/boundedness evidence receives reviewed focused credit.** No produced-witness debt is discharged by this row.

### 2.2 Row 2 — closed-complex extraction: TEST-AUTHORITY rawfield-format mismatch

`M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` is RED before the intended produced-subject/oracle contract. `read_rawfield_fixture(...)` in `SurfaceComplexSimplificationPhase17Tests.cpp` reads the first two integers as `rows columns` and demands `rows == expectedFaces && columns == 12`. The committed/package `milestone-g/torus.rawfield` begins `4 144`, which is the repository's established **degree / face-count** format; the correct reader in `SurfaceCellTransitionQuotientTests.cpp` requires `degree == 4`, `faceCount == expectedFaces`, and reads `3 * degree` values per face.

Therefore `Invalid rawfield fixture header` is neither a package inconsistency nor a production parsing failure. It is **`M4-CP4-TB1-R2-REV-CAND-01` — OPEN / RP-02 TEST_AUTHORITY_COVERAGE_GAP / RAWFIELD-FORMAT HELPER MISMATCH / NON-STABLE**, owned by CB4. The committed fixture is correct and stays byte-frozen. The associated `G4-B002` produced closed-complex debt remains open because the intended produced candidate-bearing subject was never reached.

### 2.3 Rows 3/4 — periodic relation ownership: one shared produced-fixture precondition defect

Rows 3 and 4 both stop in the same helper before the intended periodic-relation discriminator: `make_torus_pipeline_fixture()`/`torus_fixture()` constructs generic fail-closed/recovery-disabled SurfaceCells options but supplies no explicit hard-feature cut-graph authority, and production returns `InvalidBoundedDiskBoundaryTurn`. Both REDs therefore share one cause/recurrence.

The accepted prefix itself supplies the decisive counterexample to a product-regression interpretation. Selector row408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, passes again in R2 and reaches a produced torus phase-front using `cp4c_torus_hard_rail_remesh_options()`: recovery remains disabled/fail-closed, while two explicit fundamental cycles contribute the accepted 18 hard-feature edges and the automatic hard-edge thresholds are suppressed at 179/180 degrees. Row408 requires retained source/network/plan/baseline/trace authority and a `Produced` phase front, and preserves the historical row408 truth constraint.

This falsifies the frozen §3.2 sentence that named generic `make_torus_pipeline_fixture()` / `torus_fixture()` as an already produced torus path. The **obligation itself remains valid**: CP4 still requires a produced torus phase-front with at least two distinct periodic relation IDs and typed periodic-edge ownership, with no fallback/direct/draft substitution. Normative §3.2 is corrected in this Review to identify row408's accepted hard-rail path as the relevant production precondition candidate and to require runtime proof of the periodic multiplicity rather than assume it.

Rows 3/4 are jointly **`M4-CP4-TB1-R2-REV-CAND-02` — OPEN / RP-02 TEST_AUTHORITY_COVERAGE_GAP / PRODUCED-TORUS FIXTURE-PRECONDITION + REACHABILITY DRIFT / NON-STABLE**, owned by CB4. They count as one recurrence, not two. Both periodic `G4-B002` debts remain open; neither intended relation-owner oracle/tamper was reached.

### 2.4 Row 5 — same-region multiplicity-2: REVIEWED PASS / obligation discharged

`M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` reaches production torus authority, independently finds one `NetworkArcId` twice in one A2b region boundary with distinct canonical occurrence ordinals/orientations, verifies exactly two corresponding baseline incidences, then removes one incidence and requires independent validation to reject. This is the exact non-vacuous production seam required by the frozen exit conjunct.

**`M4-CP3-TB1-R1-REV-OBS-01` is DISCHARGED / RUNTIME-PROVED / REVIEWED** by R2 row5. This grants the same-region multiplicity-2 CP4 exit credit; it does not discharge a `G4-B002` debt.

### 2.5 Row 6 — zero-transport prerequisite: TEST-AUTHORITY witness-precondition defect

`M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` expected `make_skew_four_triangle_fan()` to be a non-flat negative. Static source re-derivation shows every vertex in that helper has `z = 0.0`; the alleged non-flat fan is planar. A zero-transport field on that geometry is therefore not required to fail for nonzero intrinsic curvature, so `nonFlatAtlas == true` is not evidence of a product semantic disagreement.

This is **`M4-CP4-TB1-R2-REV-CAND-03` — OPEN / RP-02 TEST_AUTHORITY_COVERAGE_GAP / ZERO-TRANSPORT WITNESS-PRECONDITION ERROR / NON-STABLE**, owned by CB4. `M4-CP-SCALE-TB2-REV-OBS-02` remains **OPEN but narrowed**: the corrected identity must use a genuinely intrinsically non-flat subject and independently prove the nonzero interior angle defect/curvature condition before expecting typed `CycleTransportMismatch`. No product change is authorized.

## 3. Reporting-control observation

R2 boundary records `stop_reason=semantic_red_focus_6` because `run_one` overwrites `stop_reason` on each focused semantic non-green even though the harness comment says to retain the first. The full 433-row ledger and raw-log set are complete and unambiguous; immutable postflight is exact. This is therefore **evidence-neutral reporting-control drift**, not orchestration invalidity and not a stable regression. `M4-CP4-TB1-R2-REV-OBS-01` is owned by the next harness/control freeze: preserve the first semantic stop reason or make the field explicitly report last/summary semantics. It must not broaden CB4's semantic correction scope.

## 4. Regression, debt and package disposition

All four focused RED rows are test-authority/witness-precondition failures on an unpromoted candidate; none demonstrates accepted product behavior loss. `CAND-01`, `CAND-02`, and `CAND-03` are **NON-STABLE RP-02 instances**, so stable regression accounting remains **49 events / 14 categories / 35 recurrences**. Produced-witness debt remains **5**: all three `G4-B002` debts remain CP4-gating; the two `G4-B003` debts remain M5-owned.

Candidate artifact `10575545321` is **NOT PROMOTED**. Its product semantic source remains a valid basis for the bounded test-authority correction, but the package itself is superseded as an acceptance candidate because its focused evidence surface contains three test-authority defects. Accepted M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**.

Carried owners remain unchanged unless stated above: `M4-CP-SCALE-TB1-REV-OBS-01` stays M8-CP2; `M4-CP-SCALE-DEFN-OBS-01` stays M8-CP2 only while observationally equivalent and otherwise reopens A2a/M3; `M4-CP3-CB4-REV-OBS-02` stays with the first legitimate row399/path/`sourceFaces` binder touch; historical row408 provenance remains a truth constraint.

## 5. Successor decision

Exact successor is **`M4-CP4-CB4`**, a test-authority-only Code + Build under `Architecture_M4_CP4_CB4_Code_Build_Plan.md`. It may correct only:

1. the row2 test-local rawfield reader to the established degree/face-count format;
2. rows3/4 test authority so the focused produced-torus subject uses the already accepted row408 hard-rail production precondition, while independently proving rather than assuming the required periodic-relation multiplicity;
3. row6's negative subject so intrinsic non-flatness is independently proved before expecting zero-transport rejection; and
4. the evidence-neutral first/last semantic `stop_reason` reporting semantics when freezing the next harness, if that control is regenerated in CB4.

No product, committed fixture, selector427, benchmark or production semantic change is authorized. A fresh immutable R3 Test + Benchmark and mandatory Review remain required before any CP4 publication.

## 6. Consolidation and closeout provenance

This Review folds the consumed/superseded CP4 execution-chain documents into `M4_Consolidated_Record.md`: CB2 report (51 lines), CB3 report (85), original TB1 report (75), TB1-R1 report (63), and consumed R2 Review plan (70). Their exact filenames and decisive verdicts remain indexed there and in git history. Current retained CP4 authority is the frozen definitions, R2 runtime report, this Review record, exactly one CB4 successor plan, selectors, consolidated record, tracker/changelog and durable project authority.

Closeout transport and cleanup provenance: **PENDING_CLOSEOUT**.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | selector427 = `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, 427 LF rows, owners **30/281/75/41**; R2 cumulative result independently parsed as **427/427 PASS**. |
| Decisive claims independently re-derived | Re-derived 433-row totals/postflight; row1 `2+4E` work contract; row2 rawfield degree/count format; rows3/4 shared generic-torus precondition stop against accepted row408 hard-rail production authority; row5 produced multiplicity-2 binder path; row6 planar `make_skew_four_triangle_fan` geometry. |
| Non-vacuity checked | Row1 tamper/replay surface is load-bearing; row5 independently derives two distinct occurrences and rejects one-incidence deletion. Rows2/3/4/6 receive no semantic debt credit because their intended subjects/preconditions were not reached/proved. |
| Prior obligations discharged/carried | `M4-CP3-TB1-R1-REV-OBS-01` **DISCHARGED** by reviewed row5. Three `G4-B002` debts remain CP4-gating. `M4-CP-SCALE-TB2-REV-OBS-02` remains open/narrowed. S1/S2-arrival/row399/row408/G4-B003 owners remain as frozen. |
| Stable accounting | **49 events / 14 categories / 35 recurrences**, debt **5**; accepted authority package `10565723112` / selector427 **427/427**. Candidate `10575545321` unpromoted. |
| New candidates/obligations recorded | `M4-CP4-TB1-R2-REV-CAND-01` rawfield helper, `CAND-02` shared produced-torus precondition/reachability, `CAND-03` zero-transport witness, plus non-gating `OBS-01` stop-reason reporting semantics; tracker updated. |
| ORIENTATION currency line | `M4-CP4-TB1-R2-REV`, 2026-09-19 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Updated: §3 R2 reviewed state/CB4 next; §4 torus row408 remains accepted while focused generic helper is invalid; §7 same-region obligation removed/discharged and remaining CP4 blockers reordered; §8 records the new RP-02 test-authority instances without creating a category. |
| CHANGELOG | R2 Review adjudication and CB4 successor entry added. |
| ROADMAP | M4 CP4 state updated to reviewed semantic non-green with test-authority-only CB4 correction next. |
| Selector manifest | n/a — selector427 is byte-frozen and no selector row changed. |
| LESSONS | No new lesson number; this Review applies existing `LESSONS.md` 59 (name every product in a production authority), 112/113 (prove required preconditions at the consumer path), and existing RP-02 reachability/non-vacuity guidance. |
| Consolidation under CLEAN_UP_POLICY | CB2 report 51 lines, CB3 report 85, TB1 report 75, TB1-R1 report 63, and consumed R2 Review plan 70 folded/indexed into `M4_Consolidated_Record.md` and deleted; current R2 runtime report/Review/frozen definitions/CB4 plan retained. |
| Successor frozen | Exactly one successor: `M4-CP4-CB4`; scope and falsifiers are in `Architecture_M4_CP4_CB4_Code_Build_Plan.md`. |
| Turn boundary held | Yes — Review remained runtime-free and changed no product/test/fixture/selector/benchmark/CMake/runtime-control bytes. |
| review_check.py boundary | **ALL CHECKS PASSED**. |
| `STATUS` lifecycle maintained | `Turn=M4-CP4-TB1-R2-REV`; entry `IN_PROGRESS`; successor while active self; final `COMPLETE` / successor `M4-CP4-CB4`; Started `2026-09-19T03:40:00Z`; latest Resumed `2026-09-19T04:58:00Z`; Ended written by the final root `STATUS` mutation. |
| Pushed to origin, branch in sync | Closeout patch is pushed through the authorized origin control plane; final branch authority is re-read after cleanup. Local `git status -sb` is used for the review boundary worktree; origin synchronization is confirmed from branch authority because this Web turn has no persistent origin-tracking checkout. |

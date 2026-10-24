# CB35 periodic-monodromy witnesses — independent static Review (2026-10-24)

**Turn:** `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS-REV`. **Decision: NOT ACCEPTED / test-authority correction required.** No TB36 manifest is authorized. This review did not run any test, executable, benchmark or build. Source commits and immutable artifacts were audited read-only.

## Source and package provenance

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft. CB35 semantic commit `6c94c053e5d20331e06a93d26437aa864171031f` changes **only** `tests/SurfaceCellsPhase10Tests.cpp`, +161/-0 lines, according to the exact GitHub commit's file inventory and diff.
- Re-downloaded compiled artifact `12575180700` (run `40131078824`): ZIP SHA-256 `f94a7a3644d976cac44bf519afa383b4d94a99ca0663aa2608d68b681e8003bd`; all 28 internal SHA256SUMS entries verified. Metadata records source `6c94c053...`, eight compiled targets, preflight/build exit 0/0, real GMPXX/GMP link, clean source statuses, and `runtimeExecution=false`.
- Source snapshot run `40132872747`, commit `36513afd77c18e3891b86532f6048af815197ecf`, ZIP SHA-256 `992df72af42afee51781367e061d170979714fb8c0eb15cb5e132721d838cddd`; inner tar hash and all 5,856 file SHA256SUMS verified. The snapshot's `tests/SurfaceCellsPhase10Tests.cpp` is byte-identical to the compiled package source. Later beacon/trigger/documentation commits are not attributed to the semantic CB35 compile.
- Independently rehashed accepted selector449: `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. No selector mutation or acceptance promotion is authorized.

## Witness construction audit

**Supported statically:** `turning_periodic_route_field` obtains an unsigned cylinder axis from the least eigenvector of face-normal covariance, center from mesh vertices, azimuth from a radial basis, and applies Rodrigues' tangent rotation to each of four raw branches before invoking the production `finalize_surface_cell_raw_cross_field`. A3 derives interior transitions from the same finalized field; `FieldTransportAtlas::make` maps raw matchings to directed transitions (`FieldTransportAtlas.cpp:2015–2065`). Both k=1/k=2 preconditions check zero reported interior singularities, nonidentity ±k along the independently constructed route, and atlas make success **before** calling A4 with identical tracing/source fields. Their negative assertion sets reproduce the frozen 192 disposition, reason and seven unset location fields. The public finalizer and all three new test bodies compiled; no source/test execution is inferred.

**Product defect remains a candidate:** `SurfaceCellTracing.cpp:14905–15004` does not read `transitionLookup.atlas` in the periodic observed-step loop; with the atlas path's legacy matchings absent, emitted rotations are zero. RA-152 F1 remains open; this review does not promote it to an independently runtime-confirmed regression.

## Material finding R-1 — route-publication witness does not establish complete identity

The third test (`tests/SurfaceCellsPhase10Tests.cpp:4650–4690`) creates a `GridAutomorphism total`, composes each `step.transport()`, then checks **only** `EXPECT_EQ(identity, total.rotation)`. `GridAutomorphism` includes a 2D `shift`, so nonzero net translation can pass despite the CB35 plan's explicit **composition-is-identity** requirement. Moreover, it asserts only the step count and occurrence of two special topology keys, not equality of the entire 32-edge route to `fixture.expectedRoute`. A route containing the same special edges but incorrect/repeated other keys can satisfy the current assertions. This is a meaningful falsification gap, not an observed runtime failure.

**Required correction:** In a separate test-only Code + Build turn, assert `EXPECT_EQ(GridAutomorphism::identity(), total)` and exact ordered `route_topology(route) == periodic_route_topology(fixture)` before examining the two special steps. Assert individual `step.transport().shift == LatticeTranslation{0,0}` for the claimed rotation-only atlas transport as appropriate. Preserve existing ±1/inverse/identity and all negative assertions. An independent Review must then confirm non-vacuity and issue TB36's five-case exact manifest; do not silently weaken tests or execute TB36 now.

## Disposition / ownership

- **Review verdict:** NOT ACCEPTED on R-1. `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE` remains conditional/unreached; do not run it.
- **Next separately authorized corrective turn:** `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION`; [narrow plan](Architecture_M6_CP3_CB35_R1_Published_Route_Oracle_Correction_Plan_20261024.md). No source production fixes, benchmarks, runtime, frozen-192 edits, selector changes or acceptance promotions.
- **Accounting:** CP2 accepted 491/491; TB32 candidate 481/500 (19 inherited RED); TB35 focused 11 PASS/2 RED; stable 66 events/17 categories/49 recurrences, debt 1, selector497 frozen; RP-01 open, RP-02 unreached. No stable loss proven.
- **Carried:** RA-152 D1 single-writer, D2 F1 future owner, D3 pre-fix evidence, D4 frozen-body rehoming, RA-152.5 axis-binding, DIAG-RETAIN and other handoff debts. New R-1 test-authority obligation belongs to the corrective turn; falsifier is an independently checked complete route and automorphism identity oracle.

## Authoritative committed-history verification

- A one-use Review-only Actions caller checked out the actual repository with full Git history, without running any Directional executable. [Run 40134815841](https://github.com/akashskypatel/Directional/actions/runs/40134815841) completed both SchemaStore workflow validation and the read-only historical boundary.
- Event/source commit: `f8c815d01d0ac0ea9c531be9c3260f70ecad05cf`. The uploaded [evidence artifact](https://github.com/akashskypatel/Directional/actions/runs/40134815841/artifacts/12576287403) has exact ZIP SHA-256 `3f6bbeebb048567c023ecbbf88dfecedd81b4ebbd77f21dc8922a18ab2857003`.
- The independently re-read log shows `review_check.py boundary` **ALL CHECKS PASSED**: no working-tree code/test/fixture/build or selector mutation, all 49 present historical selector files matching their committed content, rewrite baseline `8b7299b43764a6ba3444e5bc774a2f1b65e99731` exists and is an ancestor, and preserved durable headings in handoff (4/4), orientation (1/1), tracker (0/0 under the script's heading pattern). A fresh `git status -sb` printed a clean branch tracking origin at the observed event commit.
- A separate exact GitHub compare from the compiled semantic CB35 commit to review entry found only documentation, dispatcher and `STATUS` modifications. The temporary history-check workflow caller was removed before its trigger marker, and neither is part of the durable product. Review non-acceptance R-1 and the separate corrective successor remain unchanged.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 449 hash `d4a0d1b7...d6414`; 497 unchanged; no prefix extension |
| Decisive claims independently re-derived | Exact GitHub diff, source/atlas call sites, mathematical transport shape, artifact checksums |
| Non-vacuity checked | Two negative preconditions are potentially discriminating; third admits route and translation false positives (R-1) |
| Prior obligations discharged/carried | RA-152 D1–D4 carried, D3 not yet accepted; RA-152.5 and DIAG-RETAIN carried |
| Stable accounting | 66/17/49, debt1; CP2 491/491; TB32 481/500; frozen 497 |
| New candidates/obligations recorded | R-1 test-authority defect; tracker updated, no stable event |
| ORIENTATION currency line | CB35-REV non-acceptance and corrective turn |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 next authority; §8 added partial-identity oracle pattern; §4 unchanged because representative witness state did not change |
| CHANGELOG | CB35-REV disposition recorded |
| ROADMAP | n/a: M6-CP3 remains active, no checkpoint moves |
| Selector manifest | n/a: no selector change or promotion |
| LESSONS | Existing non-vacuity and incomplete-case lessons apply; no new global principle |
| Consolidation under CLEAN_UP_POLICY | No historical material deleted; stale orientation next owner replaced |
| Successor frozen | `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION`, falsifiers in corrective plan |
| Turn boundary held | Static review, no test/runtime/benchmark/source-test edits |
| review_check.py boundary | **PASS on real Git history**: workflow 40134815841, exact artifact 12576287403 / SHA-256 `3f6bbe...85003`, full-depth origin-tracking checkout; required durable and selector gates passed |
| `STATUS` lifecycle maintained | Entry and 2026-10-24T21:30:51Z resume beacons committed; final COMPLETE beacon is the last repository write after review record verification |
| Pushed to origin, branch in sync | Review docs were applied by run 40133802551; actual full-history Actions checkout at event `f8c815d` reported a clean branch tracking `origin`; temporary workflow/trigger cleanup and this record update are direct branch commits |

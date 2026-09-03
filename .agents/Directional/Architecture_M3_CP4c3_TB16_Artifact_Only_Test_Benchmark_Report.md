# M3-CP4c-3-TB16 Artifact-Only Test + Benchmark Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB16`
Status: **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / V47 RE-PROVED / NON-STABLE**

## Immutable authority and execution boundary

TB16 consumed immutable package **86** only:

- semantic/package source **`a01016ca59314232526c8b1222c96235856ace6d`**;
- package artifact **`9875664940`**, Actions SHA-256 **`8c98b134a527db87b83852de175288a320a158405d22867d95ba986cf68cbef8`**;
- inner `package86.tar.gz` SHA-256 **`125d2851164d7af62f90a3ff6ad8f360076a651c8575b655acac59fb50b9e9e7`**;
- packaged source archive SHA-256 **`c96446f169959c56f3c536c7fe711df6f7741d679cbd1413cc7c464838a659e8`**;
- selector **382**, SHA-256 **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`**;
- selector 381 frozen prefix SHA-256 **`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`**;
- accepted selector-365 prefix SHA-256 **`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`**.

Authoritative execution:

- run/job **`33709721203 / 100506452813`**;
- orchestration event SHA `223822f9875336cd81c80218601c4a19b2f8e80d` — control-plane only, not semantic source;
- result artifact **`9876548209`**, SHA-256 **`573f8eacf7de1ac993cfd2a4ef440514e2acb3bd6d0a85f322ac280bfec0b89f`**;
- diagnostic-log artifact **`9876548556`**, SHA-256 **`2d0cd2ab4ff4068293d0a2bb8449d0119fa03014a93cb561575d1da7a55cb75b`**.

Preflight verified package/source hashes, recursive `SHA256SUMS`, exact source commit, GMP/GMPXX evidence, 27 package-relative fixtures, all six executable modes (`755`), selector 381/382 lineage and the accepted 365-prefix hash. Runtime flags were `runtimeExecution=true`, `benchmarkExecution=false`, `configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `packageRepair=false`, `generatedDiscovery=false`, and source/test/fixture/selector mutation all false.

## Reporting-parser correction — no semantic rerun

The temporary TB16 runner repeated the already-known TB14 exact-`[ OK ]` reporting defect: it required the complete success line to equal `[       OK ] <identity>`, while GoogleTest appends elapsed time. Consequently its generated `results.tsv`/`summary.env` mislabeled every completed process RED even though selection, process execution, exit-code capture, and raw logs were valid.

This is reporting-only. Each identity ran exactly once and its process exit code plus terminal GoogleTest line were already retained before the summary parser ran. Reconstructing those immutable rows yields corrected ledger SHA-256 **`7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`**. No identity was rerun, no package byte was changed, and no generated summary field fed back into execution.

`M3-CP4c3-TB16-ORCH-01` records this resolved non-stable recurrence. Future temporary TB runners must not use full-line equality for timed GoogleTest `[ OK ]` lines.

## Gate result

Selector **382** completed all 382 exact identities, one per fresh process, for authoritative **374 PASS / 8 RED**.

- ordinals **1-365: 365/365 PASS** — CB18 accepted-boundary safety is demonstrated;
- true RED ordinals: **366, 367, 368, 369, 370, 371, 372, 374**;
- first semantic red: **ordinal 366**;
- selector 380: **PASS**;
- selector 381: **PASS**;
- selector 382 appended witness `GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`: **PASS**;
- retained non-gating `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`: **RED**, exit 1, zero gate credit.

The prior edge-locus rotation frontier is cleared. Ordinal 366 no longer reports `RotationSystemInconsistent` or `EdgeTraceSecondaryRankInvalid`. It now reaches region construction and fails at:

`NotProductionReady/global-topology-plan/RegionTraceSourcePortCarrierNotAdmissible`, source face **`(9,11,17)`**, `cutCandidateCount=0`.

## BP9 discriminator disposition

1. **PASS — accepted boundary.** Ordinals 1-365 are again **365/365 PASS**.
2. **PASS — edge-rank frontier cleared.** Ordinal 366 no longer reports `EdgeTraceSecondaryRankInvalid` at edge `25-31` / face `(25,30,31)`.
3. **PASS — branch/locus moved.** The new typed frontier is `RegionTraceSourcePortCarrierNotAdmissible` at face `(9,11,17)`.
4. **PASS — v47 production obligation discharged.** The mechanical attempt-0 `build_rotation_system` now publishes completely under selector 380. CB18 did not change network/arc topology, so TB12's retained untruncated five-ray v47 census remains the same incidence set; complete rotation publication proves the former collision no longer exists. Selector 382 independently proves the local fallback/carrier ordering is collision-free `1,2,3,4,5` for every contact edge. The inherited v47 five-ray/distinct-secondary obligation is therefore re-proved.
5. **CLOSE inherited owners.** `M3-CP4c3-TB11-CAND-01`, `M3-CP4c3-TB12-REV-CAND-01`, and `M3-CP4c3-TB15-CAND-01` close at TB16.
6. **Face walk reached.** The new region-building red is downstream of successful attempt-0 rotation and becomes the next review owner. No unobserved non-disc/admissible counter is synthesized.

No vertex-30 discriminator was introduced or inferred.

## New ordinal-366 frontier

The retained production error is intentionally sparse: `RegionTraceSourcePortCarrierNotAdmissible`, source face `(9,11,17)`. Static package source maps that error to `GlobalTopologyPlan.cpp`'s region-fragment orbit-evidence path when a trace segment has no `incomingCarrier`: the fallback searches the current face corners for **trace-global `trace->sourceVertex`** and then requires the outgoing carrier to be the edge immediately following that corner.

That shape resembles the namespace assumption corrected by CB18, but TB16 does **not** adjudicate it. The region path has a different semantic purpose and must be reviewed independently. `M3-CP4c3-TB16-CAND-01` owns the new gating surface.

## Carried report-only surfaces

- 367 and 371/372 now inherit the new mechanical region-building stop at `(9,11,17)`;
- 368 remains prescribed-sphere `TraceEventPositionInvalid / NoCarrierMatch / SourceEdgeUnavailable`;
- 369 remains the saturation-versus-ordinary-proposal coverage surface (`saturationUsed=true`);
- 370 remains the empty-network typed-code/locus surface;
- 374 remains the pre-classified folded-cone `atlasBuild=false` fixture surface;
- vertex 30 and finalize/contact remain separately owned and untouched.

The retained non-gating mechanical diagnostic independently reports `furthestStage=field-aligned-network`, `failedStage=global-topology-plan`, `planError=RegionTraceSourcePortCarrierNotAdmissible`, source face `9-11-17`, network trace count 12, event count 32, cut edge count 0, and `networkAlreadyCellular=true`.

## Regression and candidate categorization

- **`M3-CP4c3-TB16-CAND-01` — ACTIVE / GATING / PRODUCT-OR-WITNESS OWNER UNADJUDICATED / NON-STABLE:** region construction rejects a carrier-less trace segment at source face `(9,11,17)` through `RegionTraceSourcePortCarrierNotAdmissible`. TB16-REV must reconstruct the exact trace/segment incidence and decide whether the region-source-port assumption is valid.
- **`M3-CP4c3-TB16-ORCH-01` — RESOLVED / REPORTING ORCHESTRATION / NON-STABLE:** the temporary exact-`[ OK ]` parser mislabeled successful timed GoogleTest lines. Immutable exit codes/logs reconstruct the authoritative ledger; no rerun is needed.
- **`M3-CP4c3-TB15-CAND-01` — CLOSED / RUNTIME PROVED AT TB16:** accepted prefix remains green, the old edge-rank frontier clears, selector 382 passes, and the attempt-0 mechanical rotation publishes.
- **`M3-CP4c3-TB11-CAND-01` and `M3-CP4c3-TB12-REV-CAND-01` — CLOSED / RUNTIME PROVED AT TB16:** the previously colliding v47 rotation now publishes as part of the complete attempt-0 rotation with unchanged network incidence and collision-free corrected ranking.

All new evidence remains on the still-unaccepted CP4c-3 surface or temporary reporting control. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; authoritative semantic M3 package count remains **83**.

## Immutable postflight

The complete 58-file package byte/mode census is exactly identical before and after runtime. Pre/post census SHA-256 is **`606d193e3641ec68114c5616d41bd0e8e43207756f79ae50356ce973c1be10db`**. No benchmark, configure, compile, relink, package repair, generated discovery, source/test/fixture/selector mutation, or product correction occurred.

## Phase status and exact successor

TB16 is **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / V47 RE-PROVED / NON-STABLE**. Current runtime authority is package 86/source `a01016ca...`, **374 PASS / 8 RED**, accepted **365/365**, first red ordinal 366 `RegionTraceSourcePortCarrierNotAdmissible` at face `(9,11,17)`.

Exact successor is **`M3-CP4c-3-TB16-REV` — independent REVIEW + PLAN only**, under `Architecture_M3_CP4c3_TB16_Independent_Review_Plan.md`. No runtime, benchmark, compile, package, or product/test/fixture/selector mutation is authorized in that review.

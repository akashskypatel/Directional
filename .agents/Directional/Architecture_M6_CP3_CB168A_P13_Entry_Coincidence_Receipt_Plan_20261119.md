# EC1 — entry-coincidence receipt (frozen Code + Build, revised by RA-264)

## Situation

`M6-CP3-CB168A-P13-ENTRY-COINCIDENCE-RECEIPT` applies **only** [Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Exact.diff](Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Exact.diff), SHA-256 `013e8d0701cfed054d33b9f4da1c9cb0cb2da051aaa9b690c0d7a670beab1e8e`, one path, numstat `40 0 src/geometry/SurfaceCellTracing.cpp`. RA-264 (in the [TB142 Review](Architecture_M6_CP3_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Independent_Review_20261119.md#ra-264--adversarial-re-review-of-this-review-2026-11-19-utc)) withdrew the earlier three-file patch (SHA `539fd774…bd7f4`); never apply it. Do not start EC2, EC3, CB168 or the H4 cutover.

Precheck: `git diff --quiet ecc67015cc4ff28ec15c086787a9450bd585bf94 HEAD -- src include tests` (product unchanged since CB167), patch SHA, `git apply --check`.

## Background — exact change

- `#include <set>`.
- In `canonical_field_aligned_traces_and_events`, a local receipt calls the accepted helper `first_field_aligned_carrier_contact(first, second)` and reports only when both returned flags are false (`movingInSlide`, `wallInSlide`): an entry crossing meeting an entry crossing at an interior parameter (the helper already rejects single-point meets at 0 and 1). This is the predicate RA-263 S3 named for the EC3 switch; it is covered by the accepted test `FieldAlignedCarrierOccupancy.FirstCarrierContactMeetsEntriesAndSlidesAcrossFaces` (the opposite-face (0,2) crossing at 1/3, a 1/100 near miss, and an end-point meeting).
- Called once per pair in the proposal-vs-proposal loop and the proposal-vs-wall loop, before the existing classifier; the same trace never counts; each unordered (trace, segment) pair prints once per producer run:
  `FieldAlignedCurveNetwork.entryCoincidence first=t:s second=t:s carrier=(a,b) parameter=num/den`.
- No queue, event, candidate, digest or test change. No new test: the predicate is the accepted helper, and the receipt's evidence is the TB143 census below.

## Assessment — compile falsifiers (this turn)

Compile only the eight RA-245 GMP/GMPXX targets; `runtimeExecution=false`. Review syntax check: 0 errors, 43 warnings (= base). Stop on any precheck, apply, compile or package-hash failure.

## Recommendation — frozen successor `M6-CP3-TB143-P13-ENTRY-COINCIDENCE-RECEIPT-FULL-GATE-EXEC`

- Manifest: unchanged TB142 manifest `gates/Architecture_M6_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Case_Manifest.tsv`, SHA-256 `2468d8baed76322bdda79072e54c287aa421fb627a819ba278c7f7ee77e12db0` (960 gated + 81 deferred), plus the 3-row census.
- Comparison to TB142: N1–N6 as frozen, plus **N7**: delete whole lines beginning `FieldAlignedCurveNetwork.entryCoincidence ` (nothing else). All 962 records must then match exactly, raw N5/N6 receipts included; 491/491 prefix; row 858 RED at `SurfaceCellTracingDisplayTests.cpp:155`; BunnyRandom first failure unchanged (trace 82, `TraceEventPositionNodeConflict`).
- Receipt census, raw: list every entryCoincidence line by row, fixture, pair, carrier and exact parameter, with per-fixture deduplicated counts.
- Positive witness (falsifiable): every sphere row that logs `EmbeddedGraphTopology.duplicateCutCrossing` on edge (0,2) must also log an entryCoincidence line with `carrier=(0,2)` whose exact parameter is that crossing's parameter (decimal 0.12749386848657163) (expected pair `4:7`/`6:7`: both traces cross (0,2) in opposite directions and enter segment 7 there, TB132/TB133; report the pair as printed). Any such row without a line on that carrier and parameter is a STOP routed to Review (the EC3 predicate misses the known case).
- Every non-sphere line is enumerated, not adjudicated: each is a fixture EC3 will change, and the EC3 freeze must predict its outcome.

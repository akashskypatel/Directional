# TB41 independent runtime-evidence review — 2026-10-26

**Turn:** `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV`. **Decision: ACCEPT the 18-case focused runtime candidate as measured; do not promote CP3 or selector497.** RA-155.3 A/B/C and the selector250 focused candidate receive runtime credit *only for the executed tests*. **RA-156 J3/O3 is partially verified:** selector251 and selector252 passed, but the third CB42 locus test `SurfaceCellsPhase10.PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase` was **not in the frozen manifest and was not executed**. Retain its runtime obligation; do not claim 3/3. No new stable regression.

## Independently re-derived immutable evidence

- Downloaded immutable CB42 compile artifact `12634151125` ([run 40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031)); full ZIP SHA256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`; all **28/28** packaged SHA256SUMS pass. It names semantic source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, eight required GMP/GMPXX targets, `runtimeExecution=false`, clean source-status receipts.
- Downloaded TB41 result `12638251384` ([run 40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299)); ZIP SHA256 `1817f8295709a88bb3a561734b345cc50e81da056684501d714aac08fb7dd854`; **39/39** inner checksums pass. Rejoined all **18/18** raw process logs to manifest identity, test name, one RUN, one matching terminal OK, one PASSED, exit 0, no skip, and the independently computed raw-log SHA256 recorded in ledger. 18 unique identities/tests, exactly eight POSITIVE and ten distinct GUARD, with zero omissions, duplicate, unexpected pass or control failure.
- Frozen manifest SHA256 **`659c52f08bf5e5cbef6d2f1e1255432a247eb50da77bd4323666dfac900b2959`**. Execution boundary names the correct package/source, 18 executed/18 passed, `postflight=true`, compile/configure/relink/benchmark all `false`, and exit 0. No Directional binary was executed in Review.
- Downloaded exact later source snapshot [run 40301161188](https://github.com/akashskypatel/Directional/actions/runs/40301161188), artifact `12639489687`, SHA256 **`eaf11a2929377eceafc104079f913603e7b00b456574fd9c2f35b5cc7fba76eb`**; source tar **`eedb3eac7eadb32d6db598088abb435d17f9d16ebb4155eedb4e13a063388703`**; **5905/5905** source checksum entries verified. Its compiled test source matches packaged CB42 bytes (SHA256 **`bf0b2f8afd7d8bd10289ec69890323032d7bdcec34f2c4c1ed3d14859916aabb`**); manifest exact SHA above. All **47/47** numbered/frozen Required_Green_Selector source files were byte-identical between the compiled source archive and the later verified snapshot. The frozen 449-row selector remains SHA256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; the CP2 focused12 file remains SHA256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`. No selector changes or acceptance promotion.

## Independent source and non-vacuity findings

1. **189** constructs distinct own-field A3 atlases for the baseline and ±4 relabeling, checks directed signed-lift differences of magnitude four with unchanged transport, then requires both A4 products and matching full periodic-holonomy snapshots. Its PASS is not the earlier shared-atlas vacuity.
2. **191/204** each require an untampered A3 atlas and existing valid source edge, mutate authoritative `sourceEdge=-1` on that edge, then require `FieldAtlasBuildErrorCode::NonReciprocalAdjacency` with exact tampered `sourceEdge`. These are A3 rejection oracles, not unreachable A4 negatives.
3. **192/247** verify an actual k=1/k=2 turning-field monodromy, nonzero normalized cycle, valid A3 atlas, and A4 `PeriodicHolonomyMismatch` fail-closed behavior; independent TB36 quarter/half and inverse-route guards passed.
4. **250** requires Produced with three nonempty distinct source-sheet cell groups and periodic holonomy bound to cylinder sheet, with hard rail supplied by the corrected test fixture; 199/235/236/249 continuity guards passed.
5. **251/252** require `InvalidBoundedDiskFrontPairing`, null product and typed `cell=-1, side=-1` locus. In compiled `SurfaceCellTracing.cpp`, polygonal/nonrectangular early rejection at 17186–17192 leaves those fields at defaults; the four other same-reason sites around 17888–18035 supply a cell and/or side. This makes the locus assertions discriminating for the executed tests. **The separate off-selector test at 2936–2956 also has these assertions but was not executed.** The TB41 report's claim that three CB42 locus tests ran is overbroad; only two did. Do not silently credit the third.
6. **GUARD completeness:** 199/235/236/249, three TB36 identities and 193/194/195 all appear exactly once. TB40 251/252 duplicates are represented by their primary POSITIVE rows, not silently omitted.

**Limits:** Individual raw GTest logs do not print intermediate assertion values on PASS; non-vacuity follows from exact compiled test source plus control-flow reachability and independent process exits, not invented runtime intermediate values. No full 497-case census, M6-CP3 acceptance, or direct production mesh validation occurred. Historical Git ancestry/boundary checking was previously completed with an authentic full-history checkout [run 40292894222](https://github.com/akashskypatel/Directional/actions/runs/40292894222) for exact CB42 source; this Review's downloaded source archives contain no `.git` history. The recent source snapshot was obtained after the entry beacon/temporary snapshot trigger, and is inspection authority rather than separate compile authority. Early direct repository document reads before choosing snapshot mode violated the conservation gate; after recognizing the miss, no piecemeal source review continued. The per-call ledger was not maintained precisely enough for an exact total; no guessed count is claimed.

## Disposition and next authority

**Discharged as focused candidate:** RA-155.3 A (191/204), B (192/247), C (189); RA-156 selector250 own-rail positive and ten continuity guards. **Partially discharged:** RA-156 J3/O3 for 251/252 only; separately execute `PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase` in a future authorized TB gate (after a suitable frozen manifest/review, not inside this Review). **Carried unchanged:** O1/O2/O4, 190/242 legacy-path and seam oracles, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002, DIAG-RETAIN, and RP-01's remaining 405 → 174/201 → focused30:12 → cp3entry:4 → selector442 → DEFN-T1 → census. Stable **66 events / 17 categories / 49 recurrences**, debt **1**, CP2 **491/491 accepted**, TB38 **490/504 candidate**, selector497 frozen/unpromoted; RP-01 open, RP-02 unreached. No test-source modification or new stable event.

**Exactly one successor:** `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` (Definition only) for selector190, selector242, O2/O4 legacy-path and seam witnesses. Its falsifiers: no actual consumer at A2–A4; an A4 negative cannot be forced by mutating a field that a checked A3 atlas never consumes; or a required witness lacks a separately observable producer/rejection site. Stop before code/build if route authority or discriminating fixture cannot be specified. Do not execute a later TB or promote CP3 while defining it. Off-selector O3 needs a separate future TB owner, not a backfilled PASS.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 47/47 Required_Green_Selector files byte-identical; 449 `d4a0d1b7…d6414`; CP2 focused12 `2aa57aac…c67374ed`; no new or promoted selector. |
| Decisive claims independently re-derived | 28/28 compile and 39/39 TB41 checksums; 18/18 identity↔raw-log joins, 5905/5905 snapshot, producer rejection sites and manifest membership. |
| Non-vacuity checked | Own-field A3 ±4, two exact A3 tamper error/key controls, turning-field monodromy A3-positive/A4-negative, three-sheet positive, polygonal reason+locus; off-selector not executed. |
| Prior obligations discharged/carried | RA-155.3 A/B/C focused; RA-156 J3/O3 partial, third off-selector open; 190/242/O2/O4 and other carried IDs stated above. |
| Stable accounting | 66/17/49 debt1; CP2 491/491 accepted; TB38 candidate 490/504; selector497 frozen/unpromoted, RP-01 open. |
| New candidates/obligations recorded | Partial O3 off-selector execution obligation explicitly carried; no stable regression. |
| ORIENTATION currency line | 2026-10-26 TB41-REV focused acceptance; DEFN successor. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 no representative direct-production witness changed; §8 no new recurring class. |
| CHANGELOG | Independent TB41-REV entry prepared. |
| ROADMAP | CP3 unchanged; current independent Review and DEFN successor updated. |
| Selector manifest | n/a — frozen selector unchanged. |
| LESSONS | Existing non-vacuity/immutable-artifact discipline; no new lesson category. |
| Consolidation under CLEAN_UP_POLICY | Reviewed current TB41/CB42 evidence; both remain uniquely cited for imminent DEFN and open O3. No safely obsolete source/evidence file identified for deletion. |
| Successor frozen | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES`; bounded Definition-only scope/falsifiers above and in handoff. |
| Turn boundary held | Read-only Review; no binaries compiled/run and no product/test/fixture/selector/build edits. |
| review_check.py boundary | Authentic prior CB42 check passed in run 40292894222; no authentic-history run newly executed for this Review; local snapshot alone cannot substantiate historical boundary. |
| `STATUS` lifecycle maintained | Entry initialized 2026-10-26T09:37:07Z; terminal beacon must be written after durable patch/cleanup as final repository mutation. |
| Pushed to origin, branch in sync | To be filled only after successful remote patch application and head verification; cannot assert local synthetic-Git sync. |

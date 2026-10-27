# CB45 independent static Review — selector242 source-adjacent isolation seam (2026-10-27)

**Turn:** `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME-REV`.
**Verdict:** ACCEPT the scoped Code + Build implementation as a **static, compile-only candidate**, **not** a runtime PASS. Freeze the three-row TB45 manifest, then separately execute `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY` on the immutable CB45 package. RA-163.3 governs this review.

## Independent source and package audit

- Actual GitHub commit `dfeb0751b1a42a0805aecf4ef4ffb6917f619c83` has parent `ac77baa853e40ba7880259e3fc194d9d85927ce9`, and changes **only** `tests/SurfaceCellsPhase10Tests.cpp` (+88/−20), entirely in the existing `NonReciprocalSourceAdjacentIsolationSeamFailsClosed` test. No production, other test, fixture, selector or workflow edits. The review source snapshot is `60acb735c6d998de254ef0cc46874e47825c779d` (run `40425692431`, artifact `12699532207`, outer ZIP SHA-256 `f0b33fb55dda3d8c6e36f9cb6497d7003b1e1acde18e41eab15d86b850d38f75`); 5,930/5,930 source checksums verified. The reviewed test file SHA-256 is `f11830157625e6b245bb8c5535b5aa3e0d4100c952fd1a9e3704395b29c06619` and agrees exactly with CB45 package source archive.
- Compile-only artifact `12697664329` from [run 40421241608](https://github.com/akashskypatel/Directional/actions/runs/40421241608), outer SHA-256 `ad30d61b82e0de541d703073dbdefb5a7b9ed3d250cbc1b726e8cbd8c8aa21fd`: 28/28 packaged SHA256SUMS validated; exact source metadata `dfeb0751...`; eight compiled targets listed; preflight/build exit `0/0`; `DIRECTIONAL_ENABLE_GMP=ON`, exact backend `GMP`, linked `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `libgmp.so`, clean source metadata, `runtimeExecution=false`.
- Rehashed independent accepted selector 365 (365 rows) to `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; selector 449 (449 rows) to `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. The first 365 rows match exactly; both stored selector files unchanged by CB45. Selector497 gate remains frozen/unpromoted.

## Re-derived oracle and falsifiability

- The source-adjacent witness uses one two-triangle disk with faces `(0,1,2)` and `(0,2,3)`, distinct source sheets `0/1`, one produced region/certificate and the original raw field/options. The existing selector239 positive independently exercises materialization and its one isolation seam; it was not edited.
- `SurfaceIsolationSeamTransportCertificate::make` verifies region/seam membership, canonical face order, sheet ownership and finally `compose(forward, reverse)==identity` (`SurfaceCellTracing.cpp:8090–8150`). On the valid, produced certificate, adding one quarter turn to either side yields a nonidentity composition, so each owner negative must return `NonReciprocalTransport` **at the exact certificate seam and region**. Failure of either typed negative or missing output fails the test. The reconstructed unmutated control must be a certificate with the same full certificate hash; this is not another rejection-only oracle.
- For A3 the test mutates the sole interior `CrossFieldEdgeTransition.matching += 1`, not an unconsumed legacy vector. `FieldTransportAtlas::make` explicitly constructs forward from `raw.matching` and reverse as its inverse (`FieldTransportAtlas.cpp:2033–2042`); `transition_value` publishes the directed value even for a cross-sheet seam. Both base and modified atlases must construct; both directed modified values must be present and inverse, and the modified forward must **differ** from the original. The latter comparison prevents an unconsumed mutation from passing; the two-sided factory checks prevent a one-direction-only false positive. The disk's single interior edge is absent from the aggregate boundary cycle (−1/+1 cancel), so a gauge-relabelling A3 acceptance is consistent with RA-163 R2, **not** a cycle-holonomy rejection. No A4 execution is performed on a fabricated nonreciprocal atlas.
- These are static predicates and compile evidence only. Whether the new fixture reaches all assertions and whether selector242 passes is **unmeasured** until TB45. Guard185 separately exercises the factory on `split_isolation_fixture`, unlike 242's source-adjacent seam; guard239 verifies valid production/materialization. Both are independently established accepted-selector identities, but their TB45 outcomes must still be observed.

## TB45 immutable manifest and stop rules

Freeze `Architecture_M6_CP3_TB45_Selector242_Seam_Rehome_Verification_Case_Manifest.tsv` (three exact rows, in listed order): positive `selector:242`, guards `selector:239` and `selector:185`. All must run exactly once in separately spawned fresh processes from source `dfeb0751...` artifact `12697664329`, without compile, configure, relink, repair or runtime fallback. Preserve independent per-case raw logs, exact source/package/result member checksums, baseline accepted selectors and immutable postflight. Expected GTest outcome is PASS for each. Any RED (including A3 rejection or unchanged mutated seam), missing/skipped/duplicate row, changed package, wrong source, or failure to reach intended locus **stops promotion**, preserves the first cause, and routes to the independent TB45 Review; never repair assertions or production within TB45. Three focused PASS results would remain candidate evidence pending Review and do not prove CP3 or full selector497.

**Carried obligations:** RA-163.4 `DEFN-SEAM-NZ` unverified hint; O1, O2/T2 post-RP-01, O4, O5/P1/C1, O6, DIAG-RETAIN, RA-152.5, RA-146.2/4, RA-45.4 and G4-B002 remain. No new stable event or accepted-prefix promotion. Accounting stays 66 events/17 categories/49 recurrences, debt1, accepted CP2 491/491. RP-01 open, RP-02 unreached.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 365 `6b5b6555…14b8a1`; 449 `d4a0d1b7…8d6414`, 365 exact prefix |
| Decisive claims independently re-derived | Actual GitHub semantic diff; certificate owner and two independently mutated rejects; A3 raw.matching transport dataflow; immutable 28/28 package; reviewed test source matched archive |
| Non-vacuity checked | Source-adjacent produced certificate; two failures on valid certificate, exact seam/region; control hash, reciprocal modified A3 and changed forward; all still runtime-unmeasured |
| Prior obligations discharged/carried | RA-163.3 statically discharged; RA-163.4 and all listed open RP-01 obligations carried with original owners; TB45 measures 242 |
| Stable accounting | 66/17/49 debt1; CP2 491/491 accepted; selector497 frozen; no CP3 promotion |
| New candidates/obligations recorded | No new evidence-backed event; existing 242 RED stays tracked until TB45; no tracker mutation |
| ORIENTATION currency line | Updated to CB45-REV static acceptance and TB45 pending (2026-10-27) |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7 updated; §4 n/a no representative witness state changed; §8 n/a no new recurring defect |
| CHANGELOG | CB45-REV entry added |
| ROADMAP | CP3 current-boundary language updated; checkpoint state unchanged |
| Selector manifest | n/a no selector added/accepted; separate TB45 three-case manifest frozen |
| LESSONS | Existing non-vacuity, single-writer, identity, artifact-boundary guidance reused; no new distinct lesson |
| Consolidation under CLEAN_UP_POLICY | CB45 code/build record remains current immutable package authority; no superseded current per-turn record safely foldable |
| Successor frozen | `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY`, three-case manifest above, falsifiers and stop rules in this record |
| Turn boundary held | No tests/benchmark/build/runtime, no product/test/fixture/selector/workflow source edited in Review |
| review_check.py boundary | Local snapshot invocation exited 1 because historical rewrite base `8b7299b43` is unavailable in synthetic Git; do NOT claim tool PASS. Independently, GitHub compare proves rewrite-base ancestry (1,909 commits); fetched rewrite-base headings agree with all 4 handoff and 1 orientation protected headings (tracker had none). GitHub source-to-head compare shows no code/test/fixture/selector drift. Historical full-ledger scan remains unexecuted. |
| `STATUS` lifecycle maintained | Entry beacon published; final beacon must be last GitHub repository action after documentation is durable |
| Pushed to origin, branch in sync | Drive apply result recorded successful push, the remote comparison independently showed exactly 7/7 intended paths, and PR head agreed with applied commit; snapshot is synthetic and cannot produce authentic `git status -sb`, so no local-sync claim is made. |

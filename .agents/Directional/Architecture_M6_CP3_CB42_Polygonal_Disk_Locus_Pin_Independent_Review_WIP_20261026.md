# CB42 independent review — polygonal-disk first-rejection locus (2026-10-26)

**Canonical turn:** `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN-REV`.
**Disposition:** static assertion and immutable compile evidence substantively reviewed; **review closeout remains IN_PROGRESS** pending a passing authentic-Git `review_check.py boundary` and publication of the required durable closeout updates. This is *not* a runtime test/benchmark pass or CP3 promotion.

## Independently inspected evidence

- Base `a82d1f6715d984e4ab4ef9880c96275c2e93eae6` to exact code commit `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`: GitHub compare lists only the dispatch request and `tests/SurfaceCellsPhase10Tests.cpp` (+12/−0). Commit patch independently inspected: 12 lines of `ASSERT_NE(rejection(),nullptr)` and `EXPECT_EQ(-1,cell/side)`, in three tests (one compares both face-row orders); no modified or removed assertions, fixture, production code, benchmark, selector, or build files.
- Compile [run 40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031), immutable artifact `12634151125`, ZIP SHA256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`; 28/28 inner checksums independently passed. Recorded source is `8dc8cde...`; preflight and compile exit 0; all eight mandated targets listed; both GMP and GMPXX link commands present; five source-status checks clean; `runtimeExecution=false`. No binary was executed here.
- Frozen source snapshot `08df04a2e9e06dc814accc676019aa340ea7898b`, [run 40289450475](https://github.com/akashskypatel/Directional/actions/runs/40289450475), artifact `12635680785`, outer ZIP SHA256 `7865900fbf81c61b8552c7a554cf01fdb58b1a7da1a21029566255233a70aa89`; source tar hash and 5902/5902 file SHA256 checks passed. The compiled test file bytes match snapshot SHA256 `bf0b2f8afd7d8bd10289ec69890323032d7bdcec34f2c4c1ed3d14859916aabb`. All 45 packaged numbered selector files match snapshot bytes. Snapshot is later documentation/control authority, not a separately compiled source.
- `InvalidBoundedDiskFrontPairing` has five production sites. The polygonal/nonrectangular case emits the first typed failure with defaults `cell=-1, side=-1`; the four other sites supply non-default cell and/or side. Tests preserve explicit reason checks and no partial-product checks. Consequently the new rejection-locus assertions reject the other four same-reason sites, not just a reason string. **Runtime reachability of these expectations is unverified** and belongs exclusively to TB41.

## Protected-history verification limitation

Ran `python3 .agents/Directional/tools/review_check.py boundary` in a synthetic Git repository initialized from the exact verified source snapshot. It passed the source/test/fixture/build and selector mutation checks, and 39 numbered committed selector hash checks. It **failed** four historical checks because the snapshot intentionally omits `.git`, and the synthetic history has no durable baseline `8b7299b43` or original durable blobs (handoff, orientation, regression tracker). This is an evidence-environment limitation, **not a passing authentic history check**. GitHub compare from compiled source to snapshot finds only documentation, control and the review's snapshot marker; it does not substitute for the mandatory full-history boundary proof. An authentic Git history environment must rerun and pass this gate before formal Review completion.

## Obligations and successor

RA-156 J3/O3: static pin design is supported; TB41 must establish runtime falsification. The existing frozen accounting stays CP2 491/491 accepted, TB38 490/504 candidate, 497 selector unpromoted, stable 66/17/49 and debt 1, RP-01 open; no new stable regression or candidate based on the compile-only evidence. O1/O2/O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and DIAG-RETAIN are carried to their existing owners. No product, test, fixture, selector, benchmark, workflow or build source was modified during this Review.

**Current action:** complete genuine-history boundary check, then publish durable Review closeout in the same turn. **Only if independently accepted:** successor `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY`, exact immutable artifact-only cases 189/191/192/204/247/250/251/252 plus preapproved TB40 guards. Stop on missing or invalid row, altered selector/source/package, unexpected rejection site or nonpublication, failed postflight, or guard regression; retain RED evidence and do not repair in TB41. Do not start successor while current turn remains incomplete.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 45/45 package↔snapshot numbered selectors byte-identical; 39 direct per-selector hash checks in synthetic boundary check passed. 491/491 accepted prefix was not rerun. |
| Decisive claims independently re-derived | Exact +12 assertion lines, other four rejection loci, compiled source byte identity, 28/28 compile hashes and 5902/5902 snapshot hashes. |
| Non-vacuity checked | Same-reason alternate production rejection sites would fail the additional cell/side assertions; actual reachability remains TB41-only. |
| Prior obligations discharged/carried | RA-156 J3/O3 statically addressed, runtime TB41; O1/O2/O4 and named carried tasks remain. |
| Stable accounting | 66/17/49, debt1; CP2 491/491 accepted, TB38 490/504 candidate; frozen selector497, no CP3 promotion. |
| New candidates/obligations recorded | Authentic-history boundary completion remains; no new runtime candidate. |
| ORIENTATION currency line | **Pending** — intentionally not advanced to review-complete. |
| ORIENTATION §3 / §4 / §7 / §8 | **Pending** §3 and §7 review-closeout updates; §4 no witness change, §8 no new pattern. |
| CHANGELOG | **Pending** final Review entry. |
| ROADMAP | **Pending** current turn state; CP3 milestone unchanged. |
| Selector manifest | n/a — no selector addition or acceptance. |
| LESSONS | Existing nonvacuity and source-identity obligations apply; no new lesson. |
| Consolidation under CLEAN_UP_POLICY | n/a — no superseded evidence found. |
| Successor frozen | Conditional TB41 only after authentic-history gate succeeds; no successor work initiated. |
| Turn boundary held | Runtime-free, no implementation/test/selector modifications in this Review. |
| review_check.py boundary | **FAIL in synthetic snapshot**: missing original Git history/baseline, four historical checks. Real-Git check remains pending. |
| `STATUS` lifecycle maintained | Entry beacon initialized at 2026-10-26T08:00:28Z; final same-turn beacon pending. |
| Pushed to origin, branch in sync | **Pending** until durable review closeout; no false in-sync claim. |
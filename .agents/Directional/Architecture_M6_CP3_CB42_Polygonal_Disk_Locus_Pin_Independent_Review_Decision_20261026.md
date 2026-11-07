# CB42 independent review — polygonal-disk first-rejection locus (2026-10-26)

**Canonical turn:** `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN-REV`.
**Disposition: APPROVED for the separate immutable-artifact TB41 Test + Benchmark turn, subject to its own preflight and fixed manifest.** Independent static assertion, source and immutable compile evidence accepted. This is **not** runtime execution, selector promotion, or M6-CP3 acceptance.

## Independently inspected evidence

- Base `a82d1f6715d984e4ab4ef9880c96275c2e93eae6` to exact code commit `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`: GitHub compare lists only the dispatch request and `tests/SurfaceCellsPhase10Tests.cpp` (+12/−0). Commit patch independently inspected: 12 lines of `ASSERT_NE(rejection(),nullptr)` and `EXPECT_EQ(-1,cell/side)`, in three tests (one compares both face-row orders); no modified or removed assertions, fixture, production code, benchmark, selector, or build files.
- Compile [run 40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031), immutable artifact `12634151125`, ZIP SHA256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`; 28/28 inner checksums independently passed. Recorded source is `8dc8cde...`; preflight and compile exit 0; all eight mandated targets listed; both GMP and GMPXX link commands present; five source-status checks clean; `runtimeExecution=false`. No binary was executed here.
- Frozen source snapshot `08df04a2e9e06dc814accc676019aa340ea7898b`, [run 40289450475](https://github.com/akashskypatel/Directional/actions/runs/40289450475), artifact `12635680785`, outer ZIP SHA256 `7865900fbf81c61b8552c7a554cf01fdb58b1a7da1a21029566255233a70aa89`; source tar hash and 5902/5902 file SHA256 checks passed. The compiled test file bytes match snapshot SHA256 `bf0b2f8afd7d8bd10289ec69890323032d7bdcec34f2c4c1ed3d14859916aabb`. All 45 packaged numbered selector files match snapshot bytes. Snapshot is later documentation/control authority, not a separately compiled source.
- `InvalidBoundedDiskFrontPairing` has five production sites. The polygonal/nonrectangular case emits the first typed failure with defaults `cell=-1, side=-1`; the four other sites supply non-default cell and/or side. Tests preserve explicit reason checks and no partial-product checks. Consequently the new rejection-locus assertions reject the other four same-reason sites, not just a reason string. **Runtime reachability of these expectations is unverified** and belongs exclusively to TB41.

## Authentic full-history verification

The earlier attempt ran the read-only checker against a **synthetic** snapshot Git history; four historical checks failed solely because that source archive excluded `.git`. That result was never counted as a pass. An independent repository-hosted authentic full-history checkout was then executed in [run 40292894222](https://github.com/akashskypatel/Directional/actions/runs/40292894222), artifact `12635749910`. The read-only `review_check.py authority 8dc8cde...`, `boundary` and `ledgers --base 8b7299b43` returned success on actual historical authority, verifying the immutable compiled commit is an ancestor without code drift, 39 numbered selector hashes match committed bytes, protected rewrite headings remain, and append-only ledgers do not shrink. The runner also confirmed a clean checkout and remote-source branch equality at its frozen event SHA. The audit workflow is temporary and was only permitted because the durable dispatcher does not expose an authentic-history review operation; no tests, benchmarks, compilation, or product changes were executed.

## Obligations and successor

RA-156 J3/O3: static pin design is supported; TB41 must establish runtime falsification. The existing frozen accounting stays CP2 491/491 accepted, TB38 490/504 candidate, 497 selector unpromoted, stable 66/17/49 and debt 1, RP-01 open; no new stable regression or candidate based on the compile-only evidence. O1/O2/O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and DIAG-RETAIN are carried to their existing owners. No product, test, fixture, selector, benchmark, workflow or build source was modified during this Review.

**Exactly one authorized successor:** `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY`, exact immutable artifact-only cases 189/191/192/204/247/250/251/252 plus preapproved TB40 guards. Stop on missing or invalid row, altered selector/source/package, unexpected rejection site or nonpublication, failed postflight, or guard regression; retain RED evidence and do not repair in TB41. Do not start successor while current turn remains incomplete.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 45/45 packaged numbered selectors match verified source snapshot; authentic full-history audit confirms 39/39 numbered selector hashes equal committed bytes. No selector added/changed; CP2 accepted 491/491 not re-executed. |
| Decisive claims independently re-derived | Exact +12 assertion lines across three tests; other four same-reason production rejection sites have distinct locus; 28/28 compile and 5902/5902 snapshot hashes; compiled test bytes unchanged. |
| Non-vacuity checked | Same-reason alternate sites violate added cell/side assertions; existing reason and null-product checks retained. Runtime reachability awaits TB41. |
| Prior obligations discharged/carried | RA-156 J3/O3 static review discharged; O3 runtime verification and other A/B/C assertions assigned to TB41; O1/O2/O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 and DIAG-RETAIN preserved. |
| Stable accounting | 66/17/49, debt 1; CP2 491/491 accepted, TB38 490/504 candidate; selector497 frozen but not accepted. |
| New candidates/obligations recorded | None: no runtime results or novel root-cause event. Tracker unchanged for this reason. |
| ORIENTATION currency line | Updated on 2026-10-26: CB42-REV static accepted, TB41 next. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 revised in place; §4 n/a unchanged witness states; §8 n/a existing unconsumed-rejection-site warning covers pattern. |
| CHANGELOG | Single dated CB42-REV independent static review entry added. |
| ROADMAP | M6-CP3 boundary text advanced to TB41, with milestone status unchanged. |
| Selector manifest | n/a — no selector addition/acceptance. |
| LESSONS | Existing witness non-vacuity, immutable evidence and authenticated Git history principles; no new generalizable lesson. |
| Consolidation under CLEAN_UP_POLICY | Existing CB39–CB42 records remain needed by upcoming TB41; no obsolete per-turn evidence safely foldable; prior WIP review superseded by this final decision. |
| Successor frozen | `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` only: exact immutable package, 189/191/192/204/247/250/251/252 + preapproved TB40 guards; reject omissions, identity drift, altered selector/package/source, expected-locus mismatch, guard loss and postflight failure. |
| Turn boundary held | Static Review only; no test, benchmark, compilation or source mutations. |
| review_check.py boundary | PASS via authentic Git-history [run 40292894222](https://github.com/akashskypatel/Directional/actions/runs/40292894222), artifact `12635749910`; `authority` and `ledgers` also PASS. |
| `STATUS` lifecycle maintained | Started at 2026-10-26T08:00:28Z; resumed 2026-10-26T08:25:47Z; final COMPLETE beacon follows documentation and cleanup, as last repository action. |
| Pushed to origin, branch in sync | Doc patch applied by durable GitHub/Drive transport; authentic audit verified clean HEAD and original remote at frozen run SHA. Further documentation/cleanup follow-up branch equality must be verified at final authority. |

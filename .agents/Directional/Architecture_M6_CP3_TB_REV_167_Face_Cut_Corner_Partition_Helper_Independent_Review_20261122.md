# TB-REV-167 — independent face-cut corner helper review (same-turn WIP)

## Situation

The independent evidence review accepts the **TB-EXEC-167 helper-only gate**. The new helper remains **unwired**. This record does not close the Review or authorize CB-187. No product, test, build, benchmark, selector, or manifest source was changed in this Review.

## Background

- Current turn: `M6-CP3-TB-REV-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open.
- CB-186 exact source `b500c425063dbc5c09f13cd08b811cacba0e3afe`, GMP package `14769469723` ZIP SHA-256 `1290d5ed50df98056b5eaed34f0d81ca4d156dbcd026589db10f9d271b985ddf`.
- TB166 result `14765434765`, ZIP SHA-256 `9826a9219fc73b691048cff02913ebd500dc842df73700aa39eaf3126316f044`.
- TB167 run `45063416334`, result `14770748728`, ZIP SHA-256 `446eff8a01b4895030a3c969896f97976b57dcb03624a03acf88a2308ad09f93`.
- Frozen 989-row manifest SHA-256 `5c0841993d9b9c5537a3b78a3f7df39e61ee82e09b1ce9b4be3f4510ff088c50`.

## Assessment — independently re-derived evidence

- Both outer ZIP hashes match. Rehashed `SHA256SUMS`: TB166 **1976/1976**, TB167 **1986/1986** correct, no unlisted files.
- TB167 ledger: **989/989 PASS**, each test executed once, CP2 accepted first **491/491 PASS**. No skipped, duplicate, abnormal, or control-bad tests. Every raw-log digest matches.
- Accepted CP2 first 491 test names are exactly `Focused_30 + Focused_12 + Selector_449` in order. Their SHA-256 values are `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`. Their canonical LF concatenation hashes to `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`.
- Membership contains **1070 unique pairs: 989 governed and 81 deferred**. All 1065 predecessor pairs remain, with exactly five new helper tests. First 984 manifest rows (header included) SHA-256 `8d56ee1d911daa1bd3cab9f824e79131ce9f75bd7a57b31b5882d3f4f52b1e69`.
- Every prior 984 ledger row agrees on every non-log-digest field. Raw logs under N1 (remove Google Test times), N2 (normalize line endings), and N3 (complete `M3_CP4AB_FRAGMENT_DIAG` record-multiset comparison): **984/984 equal**. Only row 164 differs with N1/N2 alone; N3 resolves it. No extra allowance.
- Rows **985–989** have verified raw Google Test PASS receipts. Tests cover turn-1/turn-2 corner assignment and rays; a nested corner-free strip; four cuts around one singular corner, including input-order/cyclic-renumber invariance; interior ends and equal-sided slit; ten malformed/unordered/crossing/inconsistent cases. The assertions compare concrete orbits and typed failures. All five use **synthetic pieces**, not a production sphere's `sourcePath`.
- GitHub Actions runtime job and `execution-boundary.json` confirm immutable source/package, no compile/relink/configure/benchmark, postflight success and all 989 cases.
- Exact source header `src/geometry/FaceCutCornerPartition.h` SHA-256 `cea681185d69a83001999360ea37d173b6780c2a7ed3adac3caa42e49016ce4e`; test source SHA-256 `8ccfc38b237322e65962644593a81308142bee9f963ab3330784c094a98c1e24`. The helper remains unwired.

## Reader-switch evidence and remaining exact work

The current `GlobalTopologyPlan.cpp` `build_fragment_corner_incidence` still uses whole trace segments and port ordinal rays, and still reports `SourceFaceCarriesMultipleTraceCuts` on sphere face `6-8-9`. CB-187 must get exact face-interior pieces from **each clipped `GlobalTopologyArc.sourcePath`** and its `sourcePieceCounts`, not from whole trace segment carriers; skip edge-only slide pieces. Convert canonical source vertices/edge parameters to the face's local oriented boundary order; map true interior endpoints to missing boundary ends. A non-separating equal-sided terminal slit must not create a spurious tie rejection. Key **all certified fragment orbits** per cut face, including corner-free strips, before inserting helper-derived corner sets. `build_region_certificate` requires both all orbit keys and appropriate corner ownership. Map each helper rejection to a distinct typed plan error and preserve arc/face locus.

**CB-187 candidate prepared but not frozen.** Independent source reading confirmed `EmbeddedGraphTopology.cpp:1167–1205` binds each trace arc's face to one face-interior piece plus an optional edge-only piece. `GlobalTopologyPlan.cpp:458–673` presently reads the whole trace instead. The locally preserved candidate replaces this reader, preserves the trace-port binding check, removes ordinal ray inference, and keys both orbit sides before mapping corners. It skips only an equal-orbit terminal slit. It adds six typed reader errors and strengthens the already governed sphere row 979. It also proposes a separate, strict disc-certified sphere test in a new **990-row** case manifest, whose first 989 rows are unchanged.

Candidate patch: `Architecture_M6_CP3_CB187_P13_Face_Cut_Corner_Reader_Switch_Candidate.diff`, SHA-256 `015c175be176ff9fd49485df9aede85f11a6c715307fcc0982dcc1d737a23bdc`, base source snapshot `76151f60ae0961cd0a7ab777918ff4ed4e080ef0`, four proposed paths (GlobalTopologyPlan.h, GlobalTopologyPlan.cpp, FieldAlignedCurveNetworkTests.cpp, new TB168 gate manifest). New manifest SHA-256 `02b833e2e86bd26040b6b9f52f59efeeef6db498b9bed715f34f34b0e692a946`. `git diff --check` and `git apply --check` on the independent snapshot passed. Read-only C++20 syntax checks with the GMP macro `USE_GMP_ENABLED=1` passed for both candidate files. `GlobalTopologyPlan.cpp` had 0 warnings and 0 errors. The test source had 6 baseline warnings and 0 errors, with the warning text identical before and after. No binary was linked or executed, and no full build or runtime test was run. The candidate is preserved in the ChatGPT Library `/Directional/Recovery/`, not applied to the working branch. **Do not treat it as an authorized exact diff.**

The complete independent reader-level check remains open. In particular, the staged sphere test is a *falsifier*, not execution evidence. Its full disc-certificate expectation may fail at another real stage even when the reader is correct. Before freezing, independently decide whether the next Test + Benchmark gate should require this strict success or instead record and classify a distinct downstream typed stage without relaxing the owner/corner obligations. Test changes must be made only in Code + Build.

## Regression and carried obligations

No new PASS-to-RED regression or stable event. Stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. TB-REV-166 K5 edge-supported overlap is discharged for this witness, but the general A2a guard remains. Carry G2/G3, RA-275 S4a and G5 (plan before activation), Y7, Z5, X4/H5, V3–V11, W3/W4/W6/W7, RA-281 F1–F3, Amendment 14, O47/C5/O48/O49 and sphere χ+4 with their existing owners. Staged sphere still stops at `SourceFaceCarriesMultipleTraceCuts`; production sphere still stops at `CutSearchExhaustedBeforeCellularity`.

## Recommendation

Continue **this same TB-REV-167**. Independently audit and either correct or reject the preserved CB-187 candidate, choose the non-vacuous full-gate exit rule, finish mandatory review closeout and consolidation. No CB-187 activation, build, product edit, or test execution in this Review.

## Review closeout — incomplete, must finish before COMPLETE

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Verified 30/12/449 source selectors, 491 order and hashes above |
| Decisive claims independently re-derived | 989 ledgers/logs; 984 N1–N3 pairs; 1070 membership; five new cases; both ZIP checksums |
| Non-vacuity checked | Five helper tests assert exact orbits and typed failures; proposed reader test unrun |
| Prior obligations discharged/carried | K5 specific witness discharged; remaining duties carried as above |
| Stable accounting | 66/17/49; debt1; deferred81; CP2 491/491 accepted; no CP3 promotion |
| New candidates/obligations recorded | Unverified exact reader candidate; no new stable failure |
| ORIENTATION currency line | Updated to TB-REV-167 in progress |
| ORIENTATION §3 / §4 / §7 / §8 | Prior WIP update applied; final review closeout remains pending |
| CHANGELOG | WIP entry applied |
| ROADMAP | n/a — milestone has not moved |
| Selector manifest | n/a — accepted selector unchanged; prospective TB168 manifest is uncommitted |
| LESSONS | Existing source authority and non-vacuity rules apply |
| Consolidation under CLEAN_UP_POLICY | Pending |
| Successor frozen | Not yet; CB-187 only prospective |
| Turn boundary held | Review runtime-free; no working-branch product/test/selector changes |
| review_check.py boundary | Pending; source snapshot has no git history |
| STATUS lifecycle maintained | Same-turn resumed beacon; final same-turn beacon required |
| Pushed to origin, branch in sync | Final confirmation pending |

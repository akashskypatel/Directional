# TB100 independent Review — boundary-field corner oracle (2026-11-11)

## Situation — verdict

**TB100 is MISMATCH, not accepted.** The one failed new guard (row 938) has an incorrect full-set expectation for a hard-feature barrier. The four added vertices are conservative field corners by the existing RA-224 C1 rule. This is an **unpromoted test-oracle/specification error**, not evidence that the producer generated an incorrect corner. The exact producer has not changed in this Review. The independent corrective Code + Build turn is `M6-CP3-CB119B-P13-A3-BOUNDARY-FIELD-CORNER-ORACLE`. Do not start CB120 or TB101 until its separate corrected full gate is verified and reviewed.

## Background — immutable measurements and source

- Frozen CB119 source `cd1d451b4190bdd6b88e07fafa7e6fe69ff5b3d2`, package `13815545121`. [TB100 gate](https://github.com/akashskypatel/Directional/actions/runs/42932637408) artifact `13817910944`, outer SHA-256 `11178b67745aa3130391eba69c1ef6c680343ace3d834dc2422e621a5cf58604`: independent 1,884/1,884 file hashes. Manifest SHA-256 `2df4bd96ee8a52323ffa4f07292e37a3b6e4aedd6424fb9dc68e805da2cbc24c`, 938 distinct executed, 937 PASS, 1 RED, no omissions, skips, duplicates or abnormal results; postflight true and no configure/compile/relink/benchmark.
- The first 936 manifest rows are byte-identical to TB99 manifest `c137e3f81c75e94ed9596c59b3065e535bd678c05de178501b60923563249d2d`. All inherited 936 passed. New row 937 passed. New row 938 failed in both face-row orders with hard-rail extra vertices `{1,7,10,16}`: eight expected square corners `{0,2,6,8,9,11,15,17}`, twelve observed `{0,1,2,6,7,8,9,10,11,15,16,17}`. Plain version returns eight. The pass-through rim-node equality remained true. Receipt: hard rail `corners=12 passThroughRimNodes=12 sideStarts=12 rimSideStarts=8`; plain `corners=8 passThroughRimNodes=16 sideStarts=8 rimSideStarts=8`.
- [Three-case census](https://github.com/akashskypatel/Directional/actions/runs/42932960676), artifact `13817628224`, outer SHA-256 `d1c6ef75300439e808d8a245f547a02f1bece4947e37b987f584c0864b4b9927`: 9/9 hashes, one Cylinder PASS, BunnyRandom and Vase RED with existing owners. Initial invalid TB100 request ran zero tests and is not semantic evidence.
- Independent source snapshot event `fa8f759306e9690913d5f122847b477f8f8b568b`, [run 42941102501](https://github.com/akashskypatel/Directional/actions/runs/42941102501), artifact `13821250460`, outer SHA-256 `816734bae035630116f4eeb8d9e353a7386d73e52eab678b811452aa28f7967b`, all 5,446 source hashes verified. Source inspection was static; no project test or executable ran in this Review.

## Assessment — contract and cause

1. **RA-224 §3 C1** includes a rim vertex if the boundary branch changes, either branch cannot be decided, **or the face fan cannot be crossed**. RA-224 §2 F2 and §3 C3 limit comparison with regional side starts to **pass-through rim nodes**; hard-rail/cut starts are explicitly separate. RA-224 §4 nevertheless froze a test that requires *exactly eight* geometric square corners even with the hard rail. This full-set expectation contradicts C1 at feature barriers.
2. `build_rectangular_hard_rail_phase_front` adds hard edges `(1,4),(4,7),(10,13),(13,16)` (`tests/SurfaceCellsPhase10Tests.cpp`, ~7114). The set of their boundary endpoints is exactly `{1,7,10,16}`. In `src/authority/FieldTransportAtlas.cpp` the hard-feature edge is stored as `FieldNonTraversableEdge` and omitted from atlas adjacencies. In `src/geometry/SurfaceCellTracing.cpp`, `derive_boundary_field_corner_vertices` visits a rim vertex's incident face fan; an invalid transition sets `turns=true` and adds that vertex. These boundaries are **defined conservative corner outputs**, not an accidental spatial join. Both face orders agree.
3. The two source-independent comparisons have different domains. The producer's rim-side starts match the product at the scoped pass-through nodes; the extra four are hard-rail endpoints outside that scope. The existing passing equality does not independently show what the full barrier-inclusive corner set should be. A test that simply changes the expected count to twelve would be weak: it must derive and assert the four barrier endpoints independently of the product.
4. **Classification:** TB100 gate assertion error and RA-224 §4 specification error (candidate/non-stable), not proven field-product defect. Do not label the gate MATCH, rebaseline inherited tests, or claim direct production. Stable CP2 491/491; 66 events / 17 categories / 49 recurrences; debt 1; deferred 81. CP3 and selector497 unpromoted. O34/O35/O36/O37/O39, D6, P13-e and Vase obligations remain open.

## Recommendation — exactly one frozen Code + Build successor

**`M6-CP3-CB119B-P13-A3-BOUNDARY-FIELD-CORNER-ORACLE`**. A code+build agent may correct only the test-938 full-set oracle in `tests/SurfaceCellsPhase10Tests.cpp`, with its own small independent negative guards if needed. No production, atlas, fixture, selector, benchmark, or reusable-workflow changes; use approved compile-only procedure, no tests in that turn. This supersedes *only* RA-224 §4 test-938's eight-corner hard-rail expectation, not C1 or the exact CB119 production patch. The corrected oracle must independently derive expected extra rim vertices from the source feature edge endpoints and attest those edges are barrier/non-traversable; it must verify `(0, 2, 6, 8, 9, 11, 15, 17)` without a rail and its union with `(1, 7, 10, 16)` with a rail, in both source-face orders. Preserve exact pass-through side-start equality, nonempty and non-corner controls, and every original test assertion unrelated to the false full-set rule. The later Test + Benchmark turn must execute the unchanged 936 inherited identities and corrected guards in distinct processes and independently check results. All assertions must fail for missing barrier corners, extra non-barrier corners, disabled rail recognition, and wrong pass-through starts.

**Stop conditions:** if a barrier endpoint is not actually source-boundary or non-traversable, if C1 does not require the four outputs, if any changed test has no independent falsifier, or if exact allowed change scope cannot be held, stop at Review/plan authority rather than weaken the test. CB120/TB101 and O36 are still not authorized until corrected TB100 independently MATCHES. No successor implementation was started here.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | CP2 frozen 491/491 is unchanged; TB99 936-row hash `c137e3f8…` matches TB100 first 936 rows. No selector update. |
| Decisive claims independently re-derived | Source hard-feature endpoints, atlas non-traversable rule and `turns` branch; 938 distinct runs and 1884/1884 evidence hashes. |
| Non-vacuity checked | Test 938 fails on four independently identifiable barrier endpoints; both face orders; pass-through comparison still passes. Correction falsifiers frozen above. |
| Prior obligations discharged/carried | Correct RA-224 §4 full-set claim; O34/O35/O36/O37/O39/D6, P13-e/Vase and CP3 acceptance carried. |
| Stable accounting | 66/17/49, debt 1, deferred 81; CP2 491/491; selector497/CP3 not promoted. |
| New candidates/obligations recorded | TB100 test-oracle/spec correction; regression tracker updated. |
| ORIENTATION currency line | Updated to TB100 Review 2026-11-11. |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7, §8 updated; §4 witness outcome unchanged, so no table state moved. |
| CHANGELOG | Independent TB100 Review entry added. |
| ROADMAP | M6 CP3 still in progress, no status move; not rewritten. |
| Selector manifest | No addition/promotion; unchanged by Review. |
| LESSONS | Existing independent-oracle and source-authority pattern; no new numbered lesson. |
| Consolidation under CLEAN_UP_POLICY | No stale file removed; prior evidence preserved. |
| Successor frozen | `M6-CP3-CB119B-P13-A3-BOUNDARY-FIELD-CORNER-ORACLE` with falsifiers and stop conditions above. |
| Turn boundary held | Review static only: no project binaries, build, tests, product, fixture or selector mutations. |
| review_check.py boundary | FAIL (history-sensitive): the verified snapshot lacks Git ancestry, so rewrite-baseline ancestor and source-history checks cannot pass locally; these are unverified, not accepted. |
| `STATUS` lifecycle maintained | Entry written for this Review; final beacon follows after durable documents and cleanup. |
| Pushed to origin, branch in sync | Repository push/clean state will require separate connector confirmation; Git history is absent from snapshot. |

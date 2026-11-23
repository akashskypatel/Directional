# TB-REV-168 — independent arc-face-visit adapter review (2026-11-23 UTC)

## Situation

**TB168 evidence independently upheld for its frozen scope.** 993/993 gated cases PASS; CB-187 adapter still unwired. This is not an accepted direct sphere result. The two subsequent source switches are frozen as **separate unapplied diffs**, not implemented in this Review.

## Background and exact evidence

- Immutable source `486704038a6bf659a253a2e2f99edde5d03c7ffe`; package `14781561211` (outer ZIP SHA-256 `fa9781a710f29c926c9fd60a39cf6868d15b8d3e50ea5b7989b17aebd59b67a6`).
- TB168 [run 45092627119](https://github.com/akashskypatel/Directional/actions/runs/45092627119), artifact `14781634158`, ZIP SHA-256 `db2f8f2981c7c2ac914f59598a1e40c553ea8b94b21a23e41b84e74dd1aafb09`.
- TB167 artifact `14770748728`, ZIP SHA-256 `446eff8a01b4895030a3c969896f97976b57dcb03624a03acf88a2308ad09f93`.
- 1,994/1,994 current artifact inner file hashes independently match. TB168 ledger has exactly 993 rows, all PASS, no duplicate/absent rows. Membership has 1,074 identities (993 gating and 81 deferred), including all TB167 1,070 and four new gated identities.
- The ledger's first 989 semantic rows are equal after excluding the run-specific log hash; the common canonical prefix SHA-256 is `6507a36c0a5e17a7eaca5ebd4163fd17cb5516b4f7d02c4eda0cc8e8549cfd41`.
- Independent N1–N3 raw-log audit: remove Google Test elapsed times, normalize line endings, and compare complete `region_support_projection` diagnostic records as a multiset. All **989/989** old rows match, with normalized aggregate SHA-256 `388f16a66e5fdf72fc2116658ff47ad70312bd59aaf9b38e41e6e3d6a58d6fca` for both archives. Only row164 needed the complete-record reorder allowance; no field was removed or changed. Raw bytes otherwise differ because of elapsed times.
- Four new adapter tests (990–993) PASS and have individual logs. Execution boundary: compile, relink, configure, and benchmark all false; result postflight true. No production census.

## Assessment and frozen changes

**CB-188: region reader.** [Exact diff](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Exact.diff) SHA-256 `5f06c14baca2c35874ae74d48ea98809fe7eeefb57276b0be94c918005d05944` (5171 bytes), [manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md). R1–R4 covered: one typed visit list per arc; exact visit/trace face binding; only a counted, separating face-interior cut adds a chord; edge-only visit contributes only its visited-face orbit. All existing segment diagnostics, touched-edge barriers, evidence replay and high-side fragment ceiling stay unchanged. No C1–C4 change in this diff.

**CB-189: corner reader.** [Exact diff](Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Exact.diff) SHA-256 `35044eca7c56125240efc21f42e5dc32b653428c9338852f84b1e38b5c5fa679` (18085 bytes), [manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md). C1–C4 covered: consume the existing classified visit lists; partition counted cuts per face, preserve corner-free orbit keys and test fragment orbit subset; map typed failure to the source face and never to an arbitrary arc. Remove old full-chord and ordinal-ray corner branches, leave zero-cut faces unkeyed. Includes reconstruction of exact ownership evidence in candidate validation; this avoids validating certificates against an empty visit list. **This extra reconstruction is a potential performance cost and needs TB170 evidence before acceptance.**

**Static evidence:** both exact diffs pass `git apply --check` against their own preimages and `git diff --check`. The stacked changes pass `clang++ -std=c++20 -fsyntax-only` with GMP enabled. No compiled binaries or test processes were executed in this Review. The independently frozen runtime changes, log prefixes and exact owner counts remain predictions, not observed results.

**No product acceptance:** CP2 491/491 is the accepted gate. CP3 selector 497, D0/H4 and production activation remain unpromoted. Production sphere still stops at `CutSearchExhaustedBeforeCellularity`; staged row979 at `SourceFaceCarriesMultipleTraceCuts` on face `6-8-9`. Stable event accounting stays 66/17/49, produced-witness debt1, deferred81. No new measured regression.

**Existing obligations:** R1–R4 are frozen for CB-188; C1–C4 are frozen for CB-189 (not discharged as runtime evidence). S4/S6/S7 remain with CB-190 diagnostics, off the critical path; G5 plan-before-activation, all pending stable/deferred obligations and the exact diagnostic evidence remain held. No authority to promote any gate or selector.

**Procedural deviation:** initial direct handoff/policy reads preceded the required snapshot-mode gate. The review switched to the exact source snapshot for all substantive code inspection. This process defect does not change the immutable test evidence.

## Recommendation — one next turn

`M6-CP3-CB-188-P13-REGION-VISIT-READER`: apply **only** the CB-188 exact diff after checking its preimage and manifest; compile-only through the mandatory GMP/GMPXX workflow, without running test binaries. Stop on a changed preimage, an unplanned edit, a compile failure or incomplete evidence. Then schedule separate `M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE` with the independent 993-row artifact-only oracle. **Do not start CB-189 during CB-188.**

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 989/989 TB167 semantic rows; common prefix SHA-256 `6507a36c…49cfd41`, raw N1–N3 `388f16a6…d6fca`. Accepted CP2 selector 491 unchanged. |
| Decisive claims independently re-derived | 1,994/1,994 inner hashes; 993 ledger PASS; 1,074 membership; 989/989 prior logs under N1–N3. |
| Non-vacuity checked | Four adapter tests have raw logs; helper remains unwired, so downstream repair not claimed. |
| Prior obligations discharged/carried | R1–R4 frozen CB-188; C1–C4 frozen CB-189; S4/S6/S7 CB-190; other existing obligations carried without promotion. |
| Stable accounting | 66 / 17 / 49, debt1, deferred81, CP2 491/491, CB-187 package 14781561211; CP3 497 held. |
| New candidates/obligations recorded | No new measured regression; validation recomputation cost in CB-189 manifest. |
| ORIENTATION currency line | Updated to TB-REV-168 and CB-188. |
| ORIENTATION §3 / §4 / §7 / §8 | Current gate and witness corrected; superseded CB-187 priority removed; old withdrawn S5/S7 claims marked historical. |
| CHANGELOG | Independent review entry prepended. |
| ROADMAP | No checkpoint state change, so no milestone edit. |
| Selector manifest | No selector added or accepted; unchanged. |
| LESSONS | Existing non-vacuity and single-source-reader lessons reused; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | No deletion or folding of fresh unconsumed TB168/CB187 evidence; retained for pending code and test turns. Historical consolidation remains a separate maintenance item. |
| Successor frozen | Exactly `M6-CP3-CB-188-P13-REGION-VISIT-READER`, with manifest stop rules. |
| Turn boundary held | Runtime-free; original product/tests/selectors/manifest/build source untouched; only deferred diff artifacts and documents. |
| review_check.py boundary | Local snapshot lacks Git ancestry; static no-live-code-change audit passed. Remote full-history boundary must be checked by normal workflow when available. |
| `STATUS` lifecycle maintained | Entry beacon written; final beacon must be written last after remote patch confirmation. |
| Pushed to origin, branch in sync | Pending Drive patch transport and remote verification. Must update this row with actual result before completion. |

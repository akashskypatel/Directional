# TB152 edge-piece face-side full-gate independent review — 2026-11-20 UTC

## Situation

**PASS at the frozen helper scope, no product promotion.** Independent inspection of both immutable result ZIP files and their member checksums re-derives the full TB152 gate. The next Code + Build owns only O49 source-face edge-only ownership wiring; the later row686 test-only real-piece oracle has a separate exact patch and must not be implemented in this Review.

## Background — exact authority

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open/unmerged.
- Compiled source `1df6a09ad386791a9befddd9658ddc4d5bb795f2`, CB168O artifact `14628449217` (`runtimeExecution=false`, GMP/GMPXX); TB152 run `44739657527`, result artifact `14630642490`, ZIP SHA-256 `5bfce8410e736c1fce63c4c6fa9b272b20ff91ceac8044bb339c814bfaa3cd04`.
- Reference TB151 artifact `14619414153`, ZIP SHA-256 `c28d6ecc128bf9994d3c5f5ba2e2c799c192176f11d8818ca08c70d65caf1dab`.
- Review source snapshot run `44745759896`, artifact `14632952390`, source SHA `ae7086ba47d1cce935694790d95616faf4c81852`. Source TAR and all 5,647 files independently hashed. The snapshot contains only the review-entry STATUS and a temporary snapshot marker beyond the retained semantic source.

## Assessment — independent results

- Both ZIP hashes match GitHub artifact digests; all **1,942/1,942** TB152 and **1,940/1,940** TB151 member checksums match.
- Manifest TB151 SHA-256 `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da` is an exact byte prefix of TB152 manifest SHA-256 `cab375d014112b6ab48fe468003b9a57b2918a717e6f56e7478f0417362c0204`, with one appended row 967; membership **967 GATED +81 DEFERRED =1048**.
- TB152 **967/967 PASS**, zero RED, skipped, abnormal, duplicate, missing, bad controls or unexpected PASS. First **491/491** remain accepted CP2. Row 967 reports one successful Google Test and process exit zero.
- First **966/966** ledger identities match TB151. **704/966** raw logs are exactly equal; the remainder match under frozen N1 (Google Test elapsed time), N2 (CRLF/LF) and N3 (complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records in a multiset, not fields or omissions). All **1,750** N3 records and **504** unmasked ordered slide-contact records match on both sides. No other line was normalized.
- `execution-boundary.json` independently reads `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `postflight=true`, `exit=0`. No census was run. The helper has only declaration, definition, and its focused test: no production caller.
- The row 967 test discriminates Forward vs Reverse, reversal, half-slide cuts and non-edge/invalid inputs. Removing the helper behavior would make the focused test fail. This is non-vacuous helper evidence, **not** O49 integration evidence.
- No new stable regression or candidate; retain **66 events / 17 categories / 49 recurrences**, one produced-witness debt, **81** deferred. CP2 **491/491** remains accepted. CP3, selector497, D0, H4, row686 and the four slide contacts remain unpromoted. Sphere row686 remains χ6 vs sourceχ2 (+4); rows669/698 still exhaust.

## Recommendation — frozen future patches and stop gates

**Successor 1 (only next turn):** `M6-CP3-CB168P-P13-EDGE-ONLY-SOURCE-FACE-OWNERSHIP` (Code + Build, compile-only). The exact proposed source patch is [`Architecture_M6_CP3_CB168P_O49_Edge_Only_Source_Face_Ownership_Exact.diff`](Architecture_M6_CP3_CB168P_O49_Edge_Only_Source_Face_Ownership_Exact.diff). It changes only `src/geometry/SurfaceCutGraph.cpp::build_source_face_ownership`: one edge-only piece uses `edge_piece_face_side` to select the incident face's oriented orbit; neither face becomes an interior `traceCutFaces` member; edge-side ownership is recorded, other owners skipped. Its unchanged faceThenEdge path, terminal-slit exception, certificate filters and cut barriers must remain valid. **STOP** on a missing/invalid carrier, wrong incident-face side, a new owner in another face, any accepted-row raw change beyond frozen N1–N3 or a new RED. Compile eight RA-245 GMP/GMPXX targets, `runtimeExecution=false`; no test or benchmark in CB. The separate TB must show strict prior-row MATCH, and no production census is claimed for unwired fixture conditions.

**Successor 2 (later, not started):** `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE` (Code + Build, compile-only), after CB168P and its independent TB/Review gate. Exact proposed test-only patch: [`Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_Exact.diff`](Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_Exact.diff). Only row686 selects the new independent face+edge piece interpretation; all other callers keep the chord oracle. This derives its geometry from trace transit points rather than querying the production `exact_trace_segment_pieces` helper. **STOP** if an edge interval is not a valid source-edge subset, if terminal contacts are wrongly extended into slides, if χ changes from 6 before the stop switch without an explained source-backed cause, if any prior selected identity changes, or if the new oracle is merely a second copy of the producer. It must not claim repaired χ2 until a subsequent stop-switch TB proves it.

Both proposed patches are planning artifacts, not implemented source. Each passed `git apply --unidiff-zero --check` on the snapshot; zero-context is used only for the stored diff documents to avoid whitespace-only context lines under the repository whitespace gate. No compile or runtime proof exists for either; the next Code + Build must independently check exact preimages and compile. Do not combine the two code turns, change the production switch, add counts to a digest, or activate H4 in this Review. RA-274 S5 conformity-reader and accepted-chord test inventory remains owned by the later producer-switch review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | TB151 manifest `2a902d36…` is byte prefix of TB152 `cab375d0…`; 491/491 accepted remain PASS; selector497 not promoted |
| Decisive claims independently re-derived | 967 outcomes, 966 normalized log comparisons, 1,750 N3 records, 504 unmasked slide records, package checksums and boundary flags |
| Non-vacuity checked | Row967 contains positive winding/reversal/split and negative inputs; source helper has no production caller |
| Prior obligations discharged/carried | RA-274 S4.2 gate/helper evidence discharged; O49 wiring and row686 oracle frozen as distinct future changes; RA-274 S5 carried to producer-switch Review |
| Stable accounting | 66/17/49; debt1; 81 deferred; CP2 491/491; no promotion |
| New candidates/obligations recorded | No new candidate; existing O47/C5/O49/H4/row686 carried, no tracker rewrite needed |
| ORIENTATION currency line | TB152 Review 2026-11-20 updated |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated; §4 no witness change; §8 no new pattern, prior lesson cited |
| CHANGELOG | Independent review entry added |
| ROADMAP | CP3 active state and current next-turn position updated |
| Selector manifest | n/a: selector is unchanged, no acceptance or new identity in Review |
| LESSONS | Existing evidence/oracle and source ownership rules apply; no new distinct pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: no newly superseded standalone Review artifacts eligible for safe folding; existing historical index preserved |
| Successor frozen | Exactly one next turn CB168P; falsifiers in Recommendation; CB168Q remains later conditional |
| Turn boundary held | Review-only documents and future diffs; no product, test, fixture, selector, build or runtime mutation |
| review_check.py boundary | Snapshot lacks Git history; exact selector hashes and source diff boundary checked separately; the script cannot prove history without a Git worktree |
| STATUS lifecycle maintained | Entry beacon and final beacon per policy; final state written only after documentation transport verification |
| Pushed to origin, branch in sync | Pending remote patch transport and post-apply authority check; do not claim success until observed |

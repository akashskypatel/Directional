# TB147 independent review — exact reciprocal endpoints, unchanged gate, unresolved sphere cut graph

**Turn:** `M6-CP3-TB147-P13-MUTUAL-CARRIER-END-ORACLE-FULL-GATE-REV`
**Date:** 2026-11-20 UTC
**Boundary:** independent REVIEW; no product, test, fixture, selector, build or benchmark edits and no runtime execution.

## Situation and verdict

**TB147's required gate is independently verified GREEN, but direct sphere cellularity remains unproved.** Exact reciprocal carrier-end evidence repairs the TB146 row393 test premise without promoting CP3, selector497, D0, or any new production fixture. The proposed *different-face slide* cause of the sphere Euler excess is contradicted by the observed sphere census; *vertex contact* is an unmeasured alternative, not an established cause. Stable accounting remains 66 events / 17 categories / 49 recurrences, one produced-witness debt, and 81 deferred identities. The historical accepted CP2 package remains 491/491; the current 491-row gate prefix passes but is not itself a new CP3 promotion.

## Background — immutable evidence reopened

- Exact semantic source `0f738b1c6d3971c1e414039623336d1baa7965d1`, CB168I package `14589748220`, ZIP SHA-256 `5c74512cdc1cef967ee2968a7055b3323722298259170cae3cc74b8755864bb0` (compile-only acceptance, not runtime proof).
- TB147 gate run `44651403984` result artifact `14590664543`. Re-downloaded ZIP SHA-256 `4fe8ddd8ab64669940fad176499cd77a739c798df7a931111fcd6ad5218ed372`, all indexed internal checksum entries verified.
- Three-case census run `44654270153`, result artifact `14591964172`. Re-downloaded ZIP SHA-256 `0c2e484363af24e297cf35b78117ca71befc0d490ae34e97972a049b102498ac`, all internal checksum entries verified.
- Prior TB146 gate artifact `14569832286` and TB145 census artifact `14510118951` were separately downloaded and rechecked; no earlier summary was treated as an oracle.
- Frozen 962-case manifest SHA-256 `aa9911870a7514ea5674f869e74d8681f1ad0fcc8a14f43096b8da4f5210b61f`; 81 deferred cases SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` according to TB147 package authority. Gate rows were independently indexed by test name, binary, row number, and log digest. Prefix membership and test outcomes were compared with the TB146 manifest. This check does not assert independent re-hashing of the historical CP2 accepted-selector file.
- Source snapshot artifact `14589668879` at executor commit `d47e79fecb63174886cfebad1957c9df53ff7df6`; archive SHA-256 `68e3acfa7aa715d6f25b66e13a6a8459dbc82c60b1e602b9287dd62f9c475a41` and 5,615/5,615 source-file entries verified. Snapshot predates the TB147 report and is code-inspection authority for the unchanged CB168I implementation, not current post-report documentation authority.

## Assessment — independently reproduced gate arithmetic

The manifest and ledger contain exactly 962 distinct selected rows: **962 executed, 962 PASS, zero RED, skipped, missing or duplicate**. All 962 raw log hashes matched their gate ledger, and the first 491 rows passed; the manifest order, test, and binary identifiers match the 962-row TB146 baseline. Only row393 changed verdict, from TB146 RED to TB147 PASS. Rows393,961,962 all pass. Every other 961 log outcome matches TB146 after deleting only the new `FieldAlignedCurveNetwork.slideCoincidence` diagnostics and replacing variable Google Test timing; 957 rows match byte for byte under this normalization, and four pre-existing asynchronous joined-record rows require complete-line multiset equality under the frozen N3 rule. **No other mismatches.** The normalizations cannot turn a failing test into PASS: row verdict, identity, entire remaining diagnostic record and digest were checked separately. No changes to test assertions or selector authority occurred during TB147 execution.

Row393 emits four and only four `SphereMutualCarrierEnd` records: `4→6` and `6→4` share node9, source carrier edge `(0,2)`, exact rational parameter `574181338608147/4503599627370496`; `15→19` and `19→15` share node10, carrier `(25,27)`, the same exact rational parameter. All have `segments=7`, `struckIndex=7` and `roles=Terminal,Terminal`. The reversed records use adjacent distinct face charts but the same source-edge locus. These are positive non-vacuous witnesses: omission of a reciprocal direction, inconsistent node/edge/parameter, a wrong end index, or nonterminal ownership fails the exact oracle, while unrelated strict `<` assertions remain in place. The recovery of row393 is a verified correction of a stale test-domain premise, not a new production cellularity proof.

## Assessment — slide census and residual

Twenty sphere gate rows emit 480 `slideCoincidence` records, exactly four distinct full records repeated 120 times each. All four have `movingInSlide=0`, `wallInSlide=1` and `faces=same`. None has `faces=different`; each per-row count and absence of different-face records was checked from raw files, not inferred from totals. One unchanged row686 independently reports `V=18, E=30, F=18, c=1, χ=18−30+18=6, sourceχ=2`, and all 18 face components are discs; **excess +4 remains**. The earlier TB145 sphere graph's excess was +6; this difference is consistent with the two newly registered mutual carrier-end contacts, but it does not prove the remaining four are vertex meetings or any one kind of geometric contact. Rows669/698 still fail with `CutSearchExhaustedBeforeCellularity`. Do not spend a repair turn on different-face slide stops for this sphere and do not silently promote row858 (which passes).

The frozen three-case census executes 3 cases: Cylinder `offgate:362` PASS; BunnyRandom `offgate:360` RED; Vase `offgate:365` RED. After removing the new slide diagnostic and variable duration/pointer formatting, all three complete per-process logs match TB145. The two REDs retain the same original failure location, and no direct-production acceptance follows. BunnyRandom contains some different-face slide observations: **they cannot be transferred to the sphere by analogy**. No new stable regression event is justified.

## Root-cause bounds, alternatives, and non-vacuity

Source examination of `SurfaceCellTracing.cpp` proves `first_field_aligned_carrier_contact` compares incoming-carrier and edge-slide occupancies and deliberately rejects isolated exact edge-end parameters 0 or 1. The current `reportEntryCoincidence` diagnostic then emits an entry or slide receipt only when that helper returns a contact. Thus zero different-face slide records cannot rule out a contact at a source vertex or an intersection represented only in one source face. More generally, the available diagnostic counts are not a complete incidence mapping from segment intersections to embedded cut-graph nodes, edges and directed face orbits. A count of four in the residual is not a count of four independently located missing nodes without an exact correspondence proof. Separate the following before a semantic repair: source-vertex endpoint meetings, same-face interior crossings, same-face slide/overlap contacts, and genuinely unmatched cut-graph incidence. Distinct face charts and duplicated segment-pair visits must not be counted as independent geometric points.

**Discharged:** TB146-ROW393-ORACLE's stale strict-bound premise by four exact reciprocal directed production witnesses; TB147 required-prefix stop; full 961-row baseline comparison; gated three-case census; RA-268 slide-receipt census. **Carried:** O47/C5 sphere χ+4 and rows669/698; O48 same-face BunnyRandom merge; O49 edge-only ownership, H4/FC-6/H2/terminal-cut restrictions; produced-witness debt1; 81 deferred; CP3 and selector497/D0 nonpromotion. Supersede the speculative RA-268 S3 claim that the remaining four are *different-face slides*; retain vertex and same-face possibilities as hypotheses only.

## Recommendation — one bounded successor; do not execute in this Review

**Frozen successor:** `M6-CP3-CB168J-P13-EXACT-TRACE-CONTACT-CENSUS` — **Code + Build, compile/package only**, a diagnostic read-only extension to the existing independently produced sphere/cut-graph evidence, not a product/topology switch. Prefer the existing independent row686 oracle/test helper over production mutation when it can measure the full committed traces and actual cut-graph node/edge incidence. Reuse exact source-face barycentric and source-edge/vertex identities; do not add rounding, positional coincidence, or another causal classifier that merely restates χ. If test-local data is insufficient, use one narrow diagnostic producer receipt at the earliest existing trace/cut-graph interface, with reason and unchanged behavior proved at compile/preimage review.

**Frozen discriminators and falsifiers, for later separately authorized immutable Test + Benchmark:**
1. For each distinct pair of different committed traces, record each **exact common source point** supported by the actual path (not its reconstructed unused chord). Classify source-vertex endpoint, source-edge interior, same-face proper intersection, or supported overlap/slide; report `unevaluable` explicitly when exact classification is unavailable. Preserve trace IDs, segment indices, intrinsic source entity, full rational parameters, both face charts, whether any cut-graph node owns the contact, and whether a corresponding split arc exists. Canonicalize duplicate visits and chart aliases before counting unique loci. Do not infer a contact solely from a shared source-vertex ID without checking both occupied path pieces.
2. Include an independent negative/control case (no common occupied locus) and a positive source-vertex/path-intersection case whose exact locus and expected graph-node state are established without sharing the diagnostic's decision helper. If no suitable real production fixture exists, the Code + Build turn must report that gap; it must not fabricate a positive oracle or weaken the result.
3. Record the exact unique unowned locus set for sphere and compare it with the row686 +4 Euler residual. **The hypothesis that exactly four missing graph vertices explain +4 is falsified** if the count, exact locations, arc incidences or directed orbit effects disagree. Zero vertex meetings falsifies the vertex-meeting explanation. A positive four-count alone does not prove causality; the later Review must show the resulting V/E/F accounting and which producer omitted each node.
4. Freeze all other source, schedule, manifest, 491 accepted-prefix authority and 81 deferred rows. No slide stop, vertex merge, graph repair, general O48, H4, or D0 promotion. Build all eight mandatory GMP/GMPXX targets and require `runtimeExecution=false` plus no new compiler warning/error or authority drift. Do not run tests in Code + Build. If a complete exact inventory cannot be provided without changing production semantics, stop and return to Review with the specific missing API/evidence rather than a speculative fix.

A later artifact-only gate, not this Review and not the Code + Build turn, must test the compiled package with the unchanged 962 manifest and three-case census. The Review successor is **only CB168J**; a later test turn must be named and authorized in its own correct boundary.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 962-row frozen manifest SHA-256 above; 491-prefix membership and PASS verified against TB146. Historical CP2 selector byte re-hash not claimed; separate source authority. |
| Decisive claims independently re-derived | All raw gate/census ledger hashes; 962/962, 491/491, 961/961 normalization, 4 directed contacts, 480 slide lines, χ+4, 3-case outcomes. |
| Non-vacuity checked | Positive reciprocal row393 records and unchanged strict negatives; future exact-contact oracle must provide true positive/negative source-supported cases. |
| Prior obligations discharged/carried | TB146 row393 premise discharged; O47/C5/O48/O49, H4, FC-6, H2, debt1/deferred81 and promotion holds carried above. |
| Stable accounting | 66/17/49; debt1; deferred81; CP2 accepted 491/491; no CP3/selector497/D0 promotion. |
| New candidates/obligations recorded | No new stable ID; O47 residual +4 exact-contact audit required, with the above falsifiers. |
| ORIENTATION currency line | Pending repository sync; do not claim completion before updated. |
| ORIENTATION §3 / §4 / §7 / §8 | Pending repository sync; TB147 corrections described above. |
| CHANGELOG | Pending repository sync. |
| ROADMAP | CP3 remains active; current evidence note pending repository sync. |
| Selector manifest | n/a; no selector added, changed or accepted. |
| LESSONS | Existing causal diagnosis, source-identity, and non-vacuity rules apply; no new rule proposed. |
| Consolidation under CLEAN_UP_POLICY | Pending; no prior documents deleted without retained fact/index audit. |
| Successor frozen | Only CB168J; scope, positive/negative oracle, exact-locus falsifiers, stop rules above. |
| Turn boundary held | Review-only local evidence inspection; no source, test, build, selector, or runtime mutation. |
| review_check.py boundary | Snapshot-only product/selector checks pass; history/ancestry checks unavailable without Git metadata. Full verification not claimed. |
| `STATUS` lifecycle maintained | Entry beacon published for this review, with 2026-11-20T01:53:02Z start; terminal beacon must be last repository mutation. |
| Pushed to origin, branch in sync | Pending connector write/verification; no local git ancestry; do not assert `git status -sb`. |

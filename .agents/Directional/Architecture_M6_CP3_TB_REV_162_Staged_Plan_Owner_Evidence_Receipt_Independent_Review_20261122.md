# M6-CP3-TB-REV-162-P13-STAGED-PLAN-OWNER-EVIDENCE-RECEIPT-FULL-GATE — independent review, 2026-11-22 UTC

## Situation

**The immutable TB162 full gate is verified PASS (979/979), but the staged sphere plan is still RED.** The certificate has no established owner for 16 source faces in two uncut components. This is **H1: unavailable source-face ownership**. H3 (competing owners) and H4 (only a plan-side multiple-seed error) are contradicted by the measured counts. H2 (domain mismatch) is **not observed in this fixture**, although the certificate and plan use distinct published domain-rule labels and barrier-flag contracts. The exact owner of corrective work is the `SurfaceCutGraph` source-face certificate producer, not the plan's rejection guard. No production activation, source edit, selector change, or acceptance promotion is authorized here.

## Background — independently checked immutable evidence

- Frozen TB161 selector/case manifest SHA-256: `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a` (**979** cases, unchanged). CP2 accepted prefix is **491/491**; the current CP3 **497** identities remain frozen and unpromoted. All 979 case identities and non-hash ledger fields agree between TB161 and TB162; membership agrees **1060/1060** with deferred **81**. No selector bytes were edited.
- Immutable compiled source `e7318b4ad1f8034f80f9665cf8f4b4a407b20719`, package `14746066992` (outer ZIP SHA-256 `71fee9687b09b9f15b36adac7bca70ea389bbe4604b97f110499a877ea9846a0`). TB162 run [45002897420](https://github.com/akashskypatel/Directional/actions/runs/45002897420); artifact `14746794132` (ZIP SHA-256 `92c4420abe82ed0dae8476de609454f89fcf8a86f2846bb219d53516f78e64e2`). Reference TB161 artifact `14743677304` (ZIP SHA-256 `a3adc1c1de4aca07aa34c2e937c50f57510408d0ae0861e270c071340f830ea0`). Each archive independently passed **1966/1966** internal SHA-256 entries.
- Independently processed both `ledger.tsv` files, their per-row SHA-256 raw log bindings and their `execution-boundary.json` data. Both gates executed/passed **979/979** with **zero** RED, skipped, missing, duplicate or abnormal cases; source/build/configure/relink/benchmark flags false and final postflight true. Of 979 paired raw logs, **566** are byte-equal without normalization. All **979** become equal under frozen N1 (test timing), N2 (newline), N3 (unordered whole diagnostic record multiset), and **only** the five permitted new row-979 receipt prefixes. Both have **1750** N3 records. First **978/978** rows require no extra receipt allowance.
- Row979 original **41/41** lines are unchanged verbatim. The **19** added lines comprise 1 plan locus, 16 owner violations, 1 plan-face-owner row and 1 summary. The fifth permitted prefix (`SphereStagedOwnerConflict`) has **zero** rows. Removal uses literal *starts-with*: `SphereStagedPlanLocus;` has a semicolon, not a space. Row979 reference raw SHA-256 `4b4160259a8e754b6d0dd6047eba95d0d3b1c80ad938a8f391063c4ec85b4cea`; current SHA-256 `957869ba929da7e5c8f184b03b6fc22a2ca50822ef9093e66d45e258d372498d`.
- The complete independent offline comparison and source study involved no Directional runtime tests, benchmarks or binaries. The original raw evidence is retained at [`evidence/Architecture_M6_CP3_TB162_P13_Staged_Plan_Owner_Evidence_Receipt_Raw_20261122.txt`](evidence/Architecture_M6_CP3_TB162_P13_Staged_Plan_Owner_Evidence_Receipt_Raw_20261122.txt). TB161's three production-census records remain the authority; TB162 did not execute a new census.

## Assessment — H1–H4 classification

| Hypothesis | Independent evidence | Disposition |
|---|---|---|
| H1 — missing direct owner | `sourceFaces=192`, `owners=192`, `established=176`, `unavailable=16`, `noOrbit=16`, `violations=16`; each violation `status=1`, `orbits=-`, `sides=-`. Uncut components 1 and 5 each contain eight faces with `seedCount=0`, `seedState=None`. | **Observed.** Absence of a producer proof, **not proof of an owner that may be guessed**. |
| H2 — differing source-face component domain | All six plan/certificate component matches and face-set digests agree, including the two seedless 8-face components. The two producers still publish different domain-rule names (`EmptyFragmentOrbits` / `NotTraceCut`) and barrier flags. | **Not established as the cause on this fixture.** Carry contract equivalence audit only; do not force a common label or change barriers without a counterexample. |
| H3 — two owners on one uncut face | `conflicting=0`, `multiUncrossed=0`, `conflictCensus=0`, and all 16 violations have empty orbit sets. | **Falsified for the measured failure.** Continue to reject real conflicts. |
| H4 — valid owners but plan component has multiple seeds | `violations=16`, both failing components have zero seeds, not multiple. | **Falsified as a stand-alone explanation.** No plan-side first-seed workaround. |

The other four uncut components have unique seeds. The two unseeded face sets are:

- Component 1: `2-5-12`, `2-10-12`, `5-7-13`, `5-12-13`, `10-12-17`, `10-15-17`, `12-13-18`, `12-17-18` (digest `16565728692188360304`).
- Component 5: `27-29-37`, `27-36-37`, `29-31-38`, `29-37-38`, `36-37-42`, `36-41-42`, `37-38-43`, `37-42-43`.

The cut graph reports embedded topology χ=2 but `sourceFaceCellularity=0`. `SurfaceCutGraph.cpp::build_source_face_ownership` is the single writer: it constructs `directOwners` from certified oriented arc/trace support, forms uncut components, and currently propagates a seed only when one is produced. With none, it leaves ownership unavailable; `SurfaceCutGraphCellularityCertificate::proves_cellularity()` correctly rejects it. `GlobalTopologyPlan` is a consumer of that certificate. Neither equal component hashes nor embedded χ=2 independently supplies an oriented face-orbit owner. The production sphere also still stops at `CutSearchExhaustedBeforeCellularity`. Thus this gate is non-vacuous for preservation and observation but **not** a passing positive example of the missing owner-construction algorithm.

## Recommendation — exactly one authorized successor

**M6-CP3-CB-180-P13-SOURCE-FACE-ORBIT-OWNER-CERTIFICATION** — Code + Build, compile-only, at the certificate producer. The source implementation must first trace the existing oriented topology, source-face incidence, genuine boundary-sector evidence, and exact face-walk orbit identities for every seedless uncut component. It must produce a unique owner **only if** a complete, independently checkable source-attached witness establishes exactly one certified interior orbit for every face in that component. A missing, inconsistent, cyclically invalid, competing or cross-component witness must remain typed and fail closed. A face-set hash, an Euler count, an arbitrary first/lowest orbit, positional proximity, or the plan's chosen seed is **not** a proof. Keep the observed 103 trace-crossed face ownership and all already established 73 single-orbit uncut owners unchanged. Do not modify `GlobalTopologyPlan` to accept missing ownership, do not loosen `proves_cellularity()`, and do not change cut-search acceptance or trace/barrier semantics without a separate independent measured cause.

### Required implementation oracles — must be independent and falsifiable

1. **Positive:** Construct a small exact source-attached uncut disk/component with no direct face or edge-side owner seed but an explicit, unique, admissible oriented boundary/face-walk orbit witness. The producer must derive that orbit and assign it to **each** corresponding source face; verify exact face list, orbit, orientation, certificate validity and plan consumption. Removing the new derivation must make this fixture fail. Do not derive the oracle's expected owner by calling the implementation under test.
2. **Negative ambiguous:** Use the same source topology with two admissible but distinct oriented orbit witnesses. It must remain `Conflicting` or a typed failure; never choose the lowest orbit. A second negative case with no admissible orbit must remain `Unavailable` or typed failure. These negatives must reach the new candidate selection and fail for the intended predicate, not an earlier unrelated guard.
3. **Negative source authority:** Reverse a side or put a witness on the wrong component/sheet/barrier side. The candidate must be rejected without moving ownership to another face. Preserve canonical face-row and orientation invariance for valid cases.
4. **Regression:** Existing CP2 accepted 491 cases, fixed CP3 frozen 979-case manifest, 41 unchanged row979 pre-existing receipts, and the three existing production-census results remain baseline conditions. In later TB-EXEC-163 on the exact compiled package, compare full raw logs under an **explicit prospective** allowance for only the owned repair and require the staged plan to reach `built` or publish the next exact stopping point. Do not silently claim success from a moved failure locus.
5. **Non-vacuity:** Require a test that fails if the new ownership derivation is deleted, and separate negative tests that fail if ambiguity checking or side/sheet checking is disabled. No fabricated accepted status or weakened assertion.

**Stop rules:** If the currently published graph contains no source-authoritative oriented proof that can distinguish one orbit, stop at the producer and publish its exact missing obligation; **do not invent a winner**. If a valid fix requires changing the shared domain or cut-search acceptance rules, demonstrate the precise mismatch first and return to independent review before expanding the change. CB-180 performs source/test changes only as needed for the proof, uses the existing GMP/GMPXX compile workflow and packages exact source; it runs **no** tests or benchmarks. Its successor, TB-EXEC-163, remains a separate turn.

### Carried obligations

- TB-REV-161 W1: owner producer located, **discharged as diagnosis**, not as fix; W2/W3/W4/W5: receipt route and H1 diagnosis **discharged**; W6 locus-kind naming still **carried** (CB-180 only if relevant without broad changes); W7 acceptance-predicate question **carried, no change without source evidence**; W8 carries V3/V4 (sphere rows 393,648), V5 (BunnyRandom stop-on), V6 (V3b node), V10 (row971 stop-on-red), V11 (single flag), RA-281 F1–F3, TB-REV-157 W3/W4 and RA-275 S4a beyond this one owner repair.
- TB162 is **not** an accepted-green loss, so regression accounting remains **66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred**. No new stable event. CP3/497/D0/H4 remain held.
- Review process note: an initial remote source/document read occurred before `READ_MODE=snapshot` was selected. This violated the conservative pre-read gate. Inspection was switched to a verified SHA-pinned source snapshot; no further piecemeal source review was used for this adjudication. The process mistake does not alter the immutable runtime results.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Frozen 979 manifest `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`; CP2 accepted 491/491, unaffected; no selector added or promoted. |
| Decisive claims independently re-derived | Both ZIPs 1966/1966, 979 row bindings each, 979/979 normalized logs, 41 old + 19 new row979 records, 1060 membership and six component/16 violation diagnosis. |
| Non-vacuity checked | Equality could fail on any existing receipt; owner diagnosis can detect missing versus competing; neither constitutes a positive repaired-owner test. CB-180 positive and negative tests specified above. |
| Prior obligations discharged/carried | W1–W5 diagnostic route discharged; W6/W7, V3–V11, RA-281, RA-275, TB-REV-157 and later gates carried as detailed above. |
| Stable accounting | 66 / 17 / 49; debt 1; deferred 81; accepted CP2 491, CP3/497 unpromoted. |
| New candidates/obligations recorded | H1-162 source-face owner witness and H2 comparison limit in regression tracker; owner CB-180, downstream stop gate TB-EXEC/REV-163. |
| ORIENTATION currency line | Updated to TB-REV-162 on 2026-11-22. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 new verification, §4 owner witness update, §7 next CB-180; §8 existing single-writer/evidence pattern referenced (no new rule). |
| CHANGELOG | One TB-REV-162 entry. |
| ROADMAP | M6-CP3 remains active and unaccepted; current text corrected for current turn, no milestone promotion. |
| Selector manifest | n/a: unchanged frozen selector and accepted prefix. |
| LESSONS | Existing single-writer evidence/independent-oracle rules reused; no new pattern. |
| Consolidation under CLEAN_UP_POLICY | Reviewed the TB161 report and predecessor reviews as active immutable comparison authority for TB162; no safe superseded candidate was found within this bounded review. Preserved retained facts and existing historical indexes. |
| Successor frozen | Exactly `M6-CP3-CB-180-P13-SOURCE-FACE-ORBIT-OWNER-CERTIFICATION`; positive, negative and stopping falsifiers above. |
| Turn boundary held | Review only: no Directional source, tests, selector, fixture, build, benchmark or runtime changes. |
| review_check.py boundary | Executed in a local synthetic checkout. Source/test/build/selector boundaries and selector-byte checks passed. Rewrite-baseline ancestry and three durable-source comparisons failed because the snapshot has no original Git history or rewrite commit `8b7299b43`; **real-history boundary gate remains unverified**. No PASS claimed. |
| `STATUS` lifecycle maintained | Entry beacon on review start; final beacon must match final turn state; no successor work started. |
| Pushed to origin, branch in sync | Documentation patch submitted through the approved GitHub dispatcher. Verify the workflow push and PR head; no local `git status -sb` claim because the source was obtained as a history-free snapshot. |

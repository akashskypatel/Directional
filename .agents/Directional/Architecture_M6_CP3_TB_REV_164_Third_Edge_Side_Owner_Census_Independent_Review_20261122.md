# TB-REV-164 — independent third-edge side-owner census review (2026-11-22)

> **Continued after handover:** the [adversarial record](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md) (Z1–Z6) withdraws the prose CB-183 below. It replaces it with exact CB-183 (helper) and CB-184 (switch), then TB-EXEC-165.

## Situation and decision

**TB-EXEC-164 evidence accepted for its defined diagnostic scope.** The independently measured full gate is **982/982 PASS**, accepted M6-CP2 **491/491 PASS**; the separate production census preserves **Cylinder PASS, BunnyRandom RED, Vase RED**. This does **not** prove the production sphere, source-face cellularity, CP3/497, or D0.

**Exactly one successor is frozen:** `M6-CP3-CB-183-P13-THIRD-EDGE-SIDE-OWNER-SEED` (Code + Build only). It may connect the already compiled `third_edge_side_owner` result to the *site-C* source-face ownership seed, under the strict contract below. It shall not change site-D vertex-fan ownership, the helper's exact ordering rule, test source, frozen manifest, required-green selector, production fallback, validators, or activation flags. Run only compile/package in CB-183; an independent TB-EXEC/REV-165 owns runtime proof.

## Background and independently checked authority

- Immutable semantic source `a8f7dc13a737487080095fa1aad1901b346ddacb`, compiled GMP/GMPXX package `14755496064` ([run 45023580643](https://github.com/akashskypatel/Directional/actions/runs/45023580643)); package hash as preserved in TB164 report. Review snapshot `8589cb76e419344cd105166b4c7b549548ee397d` verified 5,738/5,738 source-file SHA-256 entries. A control-only STATUS/snapshot-trigger change does not change the semantic producer.
- TB164 [full gate](https://github.com/akashskypatel/Directional/actions/runs/45026871528), artifact `14757020531`, ZIP SHA-256 `176ab6229182826ecf43d44346e63960c4a40007dde44d6661af9e891c192611`; predecessor TB163 `14750681733`, SHA-256 `ed9112f827ae22cea3f80fb32e32594d6a332da30946e0c6fded00e0ae56461e`.
- TB164 [census](https://github.com/akashskypatel/Directional/actions/runs/45026920896), artifact `14757007212`, SHA-256 `69ef085dae88be19d9737eee8e2b7b9c68f9dc00e8929383d6c29cbbaa05465f`; TB161 comparator `14741883606`, SHA-256 `cc3f200101168f5fd3ff1e0e0dca986adb750dcd7e107a0b03ecc786b4d50b59`.
- Each archive's outer digest matches its frozen value. All internal SHA256SUMS entries match: TB164 1972/1972; TB163 1966/1966; both census archives 9/9. All per-row ledger log digests match. All four execution boundaries report `configure=false`, `compile=false`, `relink=false`, `benchmark=false`, postflight true, process exit 0.
- Independently parsed 982/982 new, 979/979 old and 3/3 census logs; all 978 prior ledger rows' non-hash fields agree, and normalized N1–N3 content matches for all 978. N3 full record multiset matches. All 108 prior `SphereStaged*` row979 lines retained in order; deleting exactly 16 new `SphereStagedUncutSideOwner` lines restores its prior content modulo N1. No other outcome changed. All three production census records agree with TB161 under N1–N4 (N4 hides only opaque parameter-object text); outcomes remain PASS, RED, RED.
- The frozen 982-case manifest SHA-256 is `ed615c22e85cbdfa61bb304370ddde51aa68038b04b7139e73066f1e8dae517b`. Membership is 1063 = 982 GATED +81 DEFERRED, exactly preserving 1060 prior member records and adding three gate entries.
- Re-hashed independently: accepted-selector-449 exact LF/raw SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, 449 distinct identities, all present in the new gate. The earlier accepted selector-365 remained byte-frozen (hash independently checked by `review_check.py` hash walk). The 491 accepted CP2 rows all have PASS verdicts. No accepted selector is promoted.

## Independent Y1–Y7 adjudication

**Y1–Y4:** The current `build_source_face_ownership` site-C path adds the third-edge orbit for *each* nested chord. A nonempty map is not a unique owner. The new census does not alter this map or the seed and cannot repair it by itself. Source carrier evidence for uncut component 1 has 8 edges: edges 2-5, 2-10, 5-7, 10-15 have candidate set {0,6}; edges 7-13, 13-18, 15-17, 17-18 have {6,7}. All eight nearest-chord results are **6**. Component 5 has 8 edges: 27-29, 27-36, 29-31, 36-41 have {11,12}; 31-38, 38-43, 41-42, 42-43 have {12,13}. All eight nearest-chord results are **12**. Each printed `chordOrbits` set equals the `sideOrbits` set. No missing, tie or disagreement in these sixteen cases. The independent Y3 prediction is confirmed; H5 terminal-slit effect is excluded for these two components, not globally.

**Y5:** The exact helper in `src/geometry/ThirdEdgeSideOwner.h` compares the two carriers' distance from their shared apex. When order is missing, tied or disagrees, it returns the entire candidate set. The new test `ThirdEdgeSideOwnerTakesTheChordNearestTheThirdEdge` would fail if the helper always returned the union; its companion `KeepsUndecidedChordOrdersAmbiguous` would fail if the helper guessed a unique owner on tie/crossing/missing data. `CarrierApexDistanceMeasuresFromTheSharedApex` checks either carrier orientation and foreign apex. These tests establish the helper's narrow unit contract, not source-face production behavior.

**Y6:** Gate PASS at rows 662 `UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence`, 788 `UncutComponentArcIncidenceCensusPublishesOnOwnershipFailure` and 979 staged downstream receipt. **Important qualification:** `CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures` is **DEFERRED and known RED**, not a PASS in the 982-case gate. It must stay deferred and must be rechecked separately at the authorized TB after CB-183. Row 979 asserts the retained sphere cut failure and staged embedded χ2, not successful global plan production. Thus no current production or cellularity success can be inferred from Y6.

**Y7:** Site-D vertex-entry owner collection is separate from site-C chord order; several chords that leave one vertex require intrinsic angular-fan evidence, not the two-carrier distance rule. This is **not exercised** by components 1/5; retain Y7 as a separate unresolved obligation. Do not route site-D through the site-C helper in CB-183.

## CB-183 bounded contract and predeclared falsifiers

- Change the **single site-C producer/seed handoff only**, preserving exact source-face, edge, sheet and barrier ownership. On complete agreeing strict order, select `third_edge_side_owner`; on a singleton preserve it unchanged; on missing/tied/disagreeing order preserve all candidate orbits, with typed ambiguity or failure rather than a guessed seed. Never choose a lowest/default orbit.
- Every candidate set must be a subset of the already emitted site-C candidate owners, and any conflict with a previously certified unique owner must remain `Conflicting`. No silent overwrite and no bypass of `proves_cellularity()` or `GlobalTopologyPlan` checks.
- Expect component 1 all eight relevant sides and faces to establish orbit 6; component 5 all eight establish orbit 12. Expect the staged sphere cut graph to report `sourceFaceCellularity=1` **only after separate runtime proof**, while the embedded χ2 and all previous source provenance remain fixed. If owner does not establish as predicted, returns another orbit, shifts source entity, or a source-face owner conflict remains, **STOP**, do not call the change successful.
- Negative falsifiers: missing second carrier, equal distance, opposing carrier order, different sheet or component, site-D fan, and conflicting pre-existing seed must never force a unique site-C owner. The old known-RED deferred production cellularity test must not be counted green without its own independent observed result. All 982 frozen gate rows and prior production outcomes must be compared unchanged except the predeclared staged owner consequence; unexpected changes are a STOP, not a revised allowance.
- Next step after CB-183 compile success is separately frozen TB-EXEC-165 and independent TB-REV-165 under new exact manifests, not part of this turn. CB-184 later production activation and CB-185 V3b remain held. No runtime/compile in this REVIEW.

## Classification and carried obligations

- **No new stable regression:** 66 events /17 categories /49 recurrences; one produced-witness debt, 81 deferred. CP3/497/D0/H4 unchanged. Site-C nested-chord over-record remains a **non-stable producer defect** with owner CB-183; falsifier is exact source-face established orbit and cellularity in separate TB.
- REV163-O1 and Y3–Y4 are discharged for **these measured components** by exact oriented source-side candidates and all sixteen nearest predictions. Y1/Y2/Y5/Y6 remain constraints on implementation and new tests. Y7 site-D fan is carried, not solved.
- X4/H5 other-face lead remains open. Carried without change: TB-REV-159-U3, V3–V11, W6/W7, TB-REV-157-W3/W4, RA-281 F1–F3, RA-275 S4a, Amendment 14, O47/C5/O48/O49, sphere χ+4 and D0/CP3 acceptance. Do not change test selectors, source, production flags or downstream validators in this review.

## Review process and tool limitations

Independent artifact check: **45/45 passed** by `/mnt/data/tb_rev164_verify_independent.py`; JSON audit and exact evidence ZIPs retained in this chat. This review did not execute project binaries or benchmarks. A source-snapshot run produced a byte-verified tree, but no original Git commit graph; `review_check.py boundary` tested selectors and reported hash PASS records, then returned nonzero because the Git ancestor/durable-rewrite provenance could not be established from a snapshot without `.git`. **Do not claim that the boundary checker passed.** The first read-mode decision was late: five initial file reads were made through the connector before the mandatory snapshot choice. Snapshot mode was then used; no further source pagination was done. Neither issue changes the observed runtime evidence; both remain procedural verification limits for closeout.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | Selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` independently rehashed; 449/449 identities present; CP2 491/491 PASS. No selector mutation. |
| Decisive claims independently re-derived | Four immutable archives, 45/45 checks, 982/982, 3/3, 16/16, N1–N4, ledger and 1063 membership. |
| Non-vacuity checked | Positive nearest test fails under union-only; ambiguity negative tests fail under forced singleton; production still unswitched. |
| Prior obligations discharged/carried | REV163-O1/Y3/Y4 proved for 1/5; Y1/Y2/Y5/Y6 guarded; Y7, X4/H5, U3/V3–V11, RA-281, RA-275, W3/W4 and χ+4 carried. |
| Stable accounting | 66/17/49, debt1, deferred81; M6-CP2 491 accepted; M6-CP3/497/D0/H4 held. |
| New candidates/obligations recorded | No stable new event; site-C CB183 scope and separate Y7 owner in tracker. |
| ORIENTATION currency line | TB-REV-164, 2026-11-22; next CB-183. |
| ORIENTATION §3 / §4 / §7 / §8 | §3 current gate, §4 unchanged (no witness state change), §7 current priority without TB164 stale next, §8 existing ownership/causal lesson cited; no new pattern. |
| CHANGELOG | TB-REV-164 entry added. |
| ROADMAP | Currency/next refreshed; no milestone acceptance advanced. |
| Selector manifest | n/a: no selector added or accepted. |
| LESSONS | Existing source-authority / nonvacuity / stable-reporting lessons apply; no new lesson number. |
| Consolidation under CLEAN_UP_POLICY | n/a: no historical record was superseded/deleted during review. |
| Successor frozen | `M6-CP3-CB-183-P13-THIRD-EDGE-SIDE-OWNER-SEED`; exact boundaries and falsifiers above. |
| Turn boundary held | Review static analysis only, no binaries, test/benchmark, code/fixture/selector mutation. |
| review_check.py boundary | Partial: hash checks passed; ancestry/durable baseline check failed due snapshot absent `.git` (unresolved verification, not claimed PASS). |
| `STATUS` lifecycle maintained | Entry beacon on review; final status beacon written after all repo changes. |
| Pushed to origin, branch in sync | GitHub patch push and exact working-branch head must be verified at closeout; **not yet independently confirmed by local `git status -sb`** because snapshot does not contain Git history. |

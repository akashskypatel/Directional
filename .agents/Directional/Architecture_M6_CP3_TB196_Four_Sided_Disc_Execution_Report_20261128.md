# M6-CP3-TB-EXEC-196 — four-sided disc quadrangulation (2026-11-28 UTC)

## Situation

The immutable CB-221 test gate executed once. All 1019 cases pass. All 1015 inherited comparisons match TB195, including row858. The four new guard tests pass. Independent acceptance belongs to M6-CP3-TB-REV-196. Root STATUS governs formal closeout. No rebuild, repair, retry, V5 or production activation.

## Background — authority

- [Exact manifest](gates/Architecture_M6_CP3_CB221_TB196_Four_Sided_Disc_Exact_Manifest.md), [CB-221](Architecture_M6_CP3_CB221_P13_Four_Sided_Disc_Quadrangulation_Code_Build_Record_20261128.md), [unequal-side DEFN](Architecture_M6_CP3_DEFN_P13_A4_Unequal_Side_Construction_20261128.md), UC1–UC5.
- Candidate `15263941488`, source and executor `eb55a07a728037b3942dbe20871c37233e0364d2`, ZIP `218cc0cfc5ff0df5971f06e13b81fc4d389195122d5d2625f71857f0e79d63eb`, root manifest `2375616cdd9e220400d5cba7c146cfc13651f727c82f9e7942fd109328ad4adc`, source archive `d403b59a91e9025c0a664ee994c448979079543d38568ab803102eae25cf6f54`. CB-221 recorded 28/28 package checks, eight GMP/GMPXX targets and clean compile-only source. The runtime harness verifies the provider and archive digests, exact source, compile boundary, package manifest, executable modes, staged fixtures and dependencies before gate execution. Successful postflight checks the package and execution view again. No package repair.
- Harness `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. [1019-row manifest](gates/Architecture_M6_CP3_CB221_TB196_Four_Sided_Disc_Full_Gate_Case_Manifest.tsv), SHA-256 `6c8be9c29548a346d97bcd2fb82f1b30cdc6c72f18e4da1806c02865cb29833b`. Header and first 1015 rows are byte-identical to TB195 manifest `34a4e86406f043739c56eec6bc104615bee05fc08960be2dc6ae4a303b43b821`. [Deferred ledger](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv), SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 rows. All four authority files match the frozen hashes in the closeout snapshot. The five CB-221 source postimages also match the manifest.
- Dispatcher commit `c809fa0960dbf6dbd39eba749a92e93cc296569a`, request SHA-256 `977edbf08867f43f728782ae8db779169d878fa452ac3a0a62430cafb38b61bf`, request and mailbox key `m6-cp3-tb196-exec`. [Run 46148326661](https://github.com/akashskypatel/Directional/actions/runs/46148326661), attempt 1; validation jobs `140989151863`/`140989152245`, parse `140989237471`, runtime `140989281353`, mailbox `140993726351` all success. Compile, noop and drive_apply skipped. Mailbox source and event match. Publication 2026-11-28T13:28:57Z. Wrapper execution 13:11:33Z–13:28:28Z, harness exit 0. No repeat dispatch.

## Assessment — immutable execution evidence

| Artifact | ID | ZIP SHA-256 |
|---|---|---|
| TB196 result | 15265246492 | `ed16ec508923a3edd8448a040cc2b48cd5e5eaf7f8fd43ace40c775f23749a14` |
| Harness log | 15265585692 | `fe32afa20377ee55a9c593d1fe6546d49d36562a8f43dc094e9c43e1cff0421c` |
| Wrapper log | 15265042526 | `32109b8e5a112752fd9edaf8b33e2eef8550b83ba4b4e5aad054c795006cf722` |
| TB195 comparator | 15259492817 | `f2fb104ac182cc24f1f8d6f68116eeb0fcb6d0e95f166c73d6a322aadd8f2a4b` |

All four outer archive hashes match. Result size 1867928 B, expiry 2026-12-12T13:28:29Z. TB196 and TB195 internal manifests pass 2046/2046 and 2038/2038 checks respectively. No extra or uncovered files. Result root SHA256SUMS `254a088e2fb9088956e07f5ff14c93fc689af26bb8386249a9237fd57be523fb`, ledger `9736b3fa0552fba198f63c66f19253cc159b5c58790a30ff337d9dca7eb8d728`, membership `24c9957adf3b36451bac7196172b16bb344044a63bcc9ccfcaf3f6d9dbec5427`, boundary `70a2f03addc65b882f8d8df4d92cd52dd2f1991aee651fa407ac2ea5bb8a3657`.

- Ordered manifest and ledger identity, exact binary and test filters, one RUN/OK/PASSED per selected test, raw log hashes and resource exit receipts match for both artifacts. 1009 GUARD + 10 POSITIVE = 1019 PASS; membership 1019 GATED + 81 DEFERRED = 1100. No duplicate or missing membership. Deferred binary/test pairs match the frozen ledger.
- Planned/executed/passed 1019; all failure counters zero, postflight true, exit 0. Boundary records configure, compile, relink and benchmark false. Candidate and source match. All inherited non-hash ledger fields are equal.
- Rows 1–1015: 797 byte-identical, 218 N1 (only GoogleTest elapsed times), 0 additional N2 (CRLF), 0 N3 (complete fragment record reordering). Row858 is N1-only: TB195 raw `cdab60c113fdfa7ef6521b950b414c213f6d4285b8bc88268dc528a4cb646568`, TB196 raw `e3d26a46a095a64f34b93f1d7129d61e0b61c8c4df434b6c10a08b4df082d7bf`. No new receipt or other semantic difference.
- Sum of per-process wall receipts 1002.36 s (TB195 1002.51 s); peak RSS 91304 KiB (TB195 91336 KiB), both row899. This is not a controlled performance comparison. Four extra tests ran; V5 did not run.

### New guards

| Row | Frozen test | Verdict | Raw SHA-256 |
|---|---|---|---|
| 1016 | ExhaustiveBoxFillsTheConstructionDomainAndRejectsTheRest | PASS | `110dd20e0bf7a93871acf30d689d195c21ec50eea8b29a94632dd87128ae6110` |
| 1017 | SphereRegionSchedulesAreFilledInEverySymmetry | PASS | `9bb14098a7122cb9cae4949e436efe6f7a82397160d5ca13073e1ab90928c99a` |
| 1018 | RejectsUnfillableAndInvalidBoundaries | PASS | `80cbc2c11b4eb295d1e65ffa86d2212621046f098a88d2552e4931b58a906ed9` |
| 1019 | RepeatedCallsGiveIdenticalDiscs | PASS | `bf7cf2e6952589954ff931e3aad9d78e84f36b28b3d84a39a9db38b46321429d` |

The four tests ran in `directional_surface_cell_completion_tests`. The frozen test contract covers the 1–10 side-count box, including 5000 even inputs, 100 grids and 2200 unequal-side fills; sphere schedules in all eight symmetries; invalid and unfillable inputs; repeated calls. These are test assertions, not independently re-derived counts or a general proof. No UC4 falsifier fired in this gate. The four-sided construction has no production caller, and geometric embedding remains unproved. DD5 is not closed. CP2 491/491; last independently accepted test gate TB195 1015/1015. Stable 67/17/50, debt1/deferred81; O51 pinned witness accepted, D7 numeric oracle carried, O52 quality item, O50 open, B1 held, B2 unmeasured. No CP3/497/D0/H4 promotion. PR #8 draft/open/unmerged.

### Control provenance

Started 2026-11-28T13:10:11Z, resumed 2026-11-28T13:33:21Z. Resume beacon `31b2c85e55efc5563250c216799b2bac129524b7`. Closeout snapshot source `68a1d14e32199ecb560bd6841b4ae5484f817c23`, run `46150251661`, snapshot job `140995150249`, artifact `15265661462`, ZIP `2eb94fb3b78d43bab9deed575519539d1e933891f35c7f966c0d0ccbe7a4ede6`, source archive `b55540cca8e241de8a37c753a876ab00488607016ea23e5c1b2a2242ef729cff`; 5923/5923 file checks. No local Directional compile or runtime. The first response inspected documents and dispatched before a snapshot and full policy review; the resume obtained the exact closeout snapshot and checked the frozen source/hash/request and gate evidence. The full mandatory policy read order was not followed. This is a procedural miss, not a measured product regression. No gate input was changed to obtain a pass.

Snapshot marker cleanup: run `46150421915`, receipt `15265736549`, ZIP `d79479c08e2c9746b57681d7d1cf771cc864d4a19d05dc73d2ee789fcbbc7936`, commit `af3d6b62a5b118dd3e1f242b91eb8fcbe5423c81`; marker removed, zero PR comments deleted. Documentation drift audit: zero errors, existing orientation size warning and three protected navigation changes required by closeout. No protected policy, design, selector, harness or workflow change.

## Recommendation

Next `M6-CP3-TB-REV-196`. Independently reopen the candidate, both result archives and the frozen manifest. Verify all 1019 outcomes, 1015 inherited comparisons, all four guard assertions and UC1–UC5, including the domain, structural checker, symmetry cases, rejection sites and determinism. Keep UC2 subject to owner override. Only review may authorize the next embedding definition. No runtime, production wiring, A3 count change, corner ownership change, sliver deletion, fallback repair, dispatch/veto change or checkpoint promotion in the review.

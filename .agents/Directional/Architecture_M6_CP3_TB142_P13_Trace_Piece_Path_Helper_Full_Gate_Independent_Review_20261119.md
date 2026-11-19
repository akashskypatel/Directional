# TB142 trace-piece path helper — independent evidence Review (MATCH)

## Situation

`M6-CP3-TB142-P13-TRACE-PIECE-PATH-HELPER-FULL-GATE-REV` independently **accepts the narrow TB142 MATCH comparison**, not a CP3 or D0 product acceptance. All 962 prior gate/census records match TB141 after only N1–N4 normalization; N5 `slideProposal` and N6 `committedSlide` were compared raw, without deletion. Review is runtime-free; no project build, test, benchmark or implementation was executed or changed. The next bounded Code + Build turn is `M6-CP3-CB168A-P13-ENTRY-COINCIDENCE-RECEIPT`. This Review does not start it.

## Background — verified source and evidence

- Exact CB167 semantic source `ecc67015cc4ff28ec15c086787a9450bd585bf94`, immutable package `14481197196`, ZIP SHA-256 `274064da966f5a0257115c851cbc530c5f8fd9a3b1979b5d06844dab0ce1f04b`. All current branch product/fixture/test/build/selector paths match the prior snapshot at `fd14f41cd1e80ff35727cab57199a411758ea90e` in remote commit comparison (only documents and control files changed).
- Exact local review snapshot `0e79a4be5722967a1dce39885e9bf7448364d007`, run `44428054527`, artifact `14484483404`; source archive checksum and all 5,589 file checksums pass. It includes only reviewed source and prior documentation, not an executed build.
- TB141 gate/census result artifacts `14473040819` / `14473701160`; TB142 gate/census artifacts `14482831297` / `14482339143`. Independently checked all four ZIP SHA-256 and all **3,872 internal entries** (1,926 + 9 + 1,928 + 9), plus each ledger's raw-log SHA-256, row count and execution boundary. Offline comparator: `/mnt/data/tb142_independent_verify.py`; analysis output retained as downloadable evidence, not generated runtime results.

## Assessment — independent adjudication

- **962/962 prior records MATCH.** All 959 earlier gate rows and three census rows have identical identity, selected test, binary, outcome, exit, first failure, reason, and normalized complete log. N1 removes GoogleTest timing only; N2 normalizes line endings; N3 sorts only contiguous complete `region_support_projection` records; N4 masks only valid 16-byte opaque `GetParam()` values in census. No other normalized difference. N5/N6 receipts are compared raw and are unchanged.
- **491/491 accepted prefix PASS** in original order: selector SHA-256 focused30 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, focused12 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, selector449 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`; joined `452360f771daacb96f87697286ec7708832f63c876b9df9b1857e93433e5300b`.
- Gate manifest hash `2468d8baed76322bdda79072e54c287aa421fb627a819ba278c7f7ee77e12db0`, 960 gated + 81 deferred = 1,041 membership. The manifest expects PASS for row 858 but the retained explicit permitted RED remains at `tests/SurfaceCellTracingDisplayTests.cpp:155`. This is one known exception, **not a false manifest equality**. Row 648 remains PASS with the same raw record; no new sphere assertion reach is inferred. New row 960 `FieldAlignedCarrierOccupancy.TracePiecePathKeepsNonLastSlideAndCanonicalContactEndpoints` PASS (0 exit); gate 959 PASS/1 RED; census 1 PASS/2 RED.
- **Receipt inventory:** 1,200 gate + 66 census `slideProposal` and the same 1,266 `committedSlide` lines. For each of the prior 962 rows, both kinds match TB141 byte-for-byte and in order. A retained traversal is not a published graph; sphere C5/O47 still fails before arc publication, BunnyRandom still stops at trace 82, and Vase remains RED. Cylinder retains 288 quads.
- **Non-vacuity:** row 960 asserts an ordered multi-piece path, non-last slide, departure with no face chord, canonical edge/vertex contacts, clipping, and fail-closed invalid positions. Rotating a wrong chord or dropping an actual slide would violate those asserted path pieces. The legacy single-face chord cannot satisfy the distinct piece-path expectation. This is an independent static falsifier, not a claimed before/after runtime experiment. The read-only full-gate comparator is separately sensitive to added/deleted/changed ledger values, record bodies and raw slide receipts; row858's known RED is not accepted as green.
- No new stable regression or candidate was observed. **66 events / 17 categories / 49 recurrences**, one produced-witness debt, 81 deferred, CP2 accepted 491/491; selector497 unpromoted. C5/O42/O43/O46/O47/O48, H2/H4, O49 and FC-1/FC-4 remain open; FC-6 and terminal-cut held; CB145 parked. RA-263 S3 controls sequence EC1 → EC2 → EC3 → CB168 → O49 → CB169.

## Recommendation — exact EC1 freeze

Frozen successor `M6-CP3-CB168A-P13-ENTRY-COINCIDENCE-RECEIPT` applies **only** [Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Exact.diff](Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Exact.diff), SHA-256 `539fd774a2a90dc713eaa957bb48e82dc67dedb3cf35e048c3bcbc07595bd7f4`, to the verified unchanged product/test preimages; see [Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Plan_20261119.md](Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Plan_20261119.md). It adds inert optional `FieldAlignedTerminalContact::carrierLocus`, hashed only when actually present, and exact (entry, entry) interior-parameter diagnostic receipts without changing contact scheduling or graph geometry. Scope: three files, +74/-0; static patch applicability PASS. Neither the frozen patch nor the Review asserts a compiled or measured EC1 result.

EC1 falsifiers: old 962 prior records (including unchanged raw N5/N6 slide receipts) must remain identical; focused field/default/digest contract must reject mutation; count all deduplicated interior (entry, entry) receipts by fixture and trace-pair, with sphere 4/6 visible in every applicable sphere row; unexpected other-fixture encounters must be enumerated; endpoint 0/1, different carriers, distinct parameters, same trace and replays cannot count; no `carrierLocus` populated and no graph publication in EC1. Stop on any change in row858 site, BunnyRandom first failure, selector prefix, artifact authority, or source scope. Subsequent EC2/EC3 remain prospective and require separate turns and evidence.

Procedure evidence: direct document reads preceded the snapshot READ_MODE selection; this was a start-of-turn process miss. Review resumed with the correct exact snapshot. Source snapshots contain no Git history, so `review_check.py boundary` cannot prove historical rewrite-base ancestry locally. Remote protected-path comparison and local exact file checks are used as compensating evidence. This limitation is not a test result.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491/491, three SHA-256 above; joined `452360f7…e5300b` |
| Decisive claims independently re-derived | Four ZIP hashes, 3,872 internal checks, 962 normalized rows, 1,266 raw records of each type, ledger/manifest/prefix |
| Non-vacuity checked | Row 960 path/negative controls and complete log/receipt comparisons; no runtime mutant claim |
| Prior obligations discharged/carried | TB142 review adjudicated; carry C5/O47/O48/O49, H4, row858/648 premise, existing debt; EC1 scoped only |
| Stable accounting | 66/17/49; debt 1; deferred 81; CP2 491/491; selector497 not promoted |
| New candidates/obligations recorded | None stable; EC1 receipt and future contact obligations retained in tracker and TODO |
| ORIENTATION currency line | Updated to TB142-REV, 2026-11-19 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 status and §7 priority updated; §4 unchanged fixture evidence; §8 existing lesson, no new defect pattern |
| CHANGELOG | Review entry appended at top |
| ROADMAP | n/a: M6-CP3 not closed, no milestone promotion |
| Selector manifest | n/a: no selector edited or accepted |
| LESSONS | Existing exact-source identity, witness and non-vacuity lessons applied; no new pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: no historical duplicate records generated; transient snapshot marker removed after evidence collection |
| Successor frozen | `M6-CP3-CB168A-P13-ENTRY-COINCIDENCE-RECEIPT`; exact diff and falsifiers in [Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Plan_20261119.md](Architecture_M6_CP3_CB168A_P13_Entry_Coincidence_Receipt_Plan_20261119.md) |
| Turn boundary held | Yes; Review runtime-free, no live product/test/selector/fixture mutation |
| review_check.py boundary | Source-only snapshot has no rewrite-base Git history; history-dependent verification unavailable; remote code-surface and local diff checks used |
| `STATUS` lifecycle maintained | Entry beacon in repository, final COMPLETE beacon after publication and cleanup |
| Pushed to origin, branch in sync | GitHub Actions run 44430359926 confirmed the patch commit was pushed to the working branch; subsequent GitHub PR head confirmed remote advancement; local `git status -sb` unavailable without a checkout |

# CB29 independent review — A4 certificate / A5 association ownership (2026-10-23)

**Turn:** `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP-REV`.
**Verdict: ACCEPT STATIC CB29; AUTHORIZE THE NEXT TARGETED TB30 ONLY.** No runtime, full-selector promotion, or CP3 acceptance is inferred.

## Independent checks

- Source SHA `2602e7398cdc6f1281abe11a758de35166b6590c`; GitHub commit diff changes one file, `src/geometry/SurfaceCellTracing.cpp`, in the certificate-pair clause at about 8831. The removed check covered seven Boolean comparisons across four association groups: two opposite-edge comparisons, two rail-ID comparisons, two directed route comparisons, and one source-region inequality. The unchanged clause still rejects when either edge is not HardRail at `certificate-pair-binding`.
- A4 certificate identity/index checks precede the clause (`certificate-pair-indices`, 8813+). Downstream A4 authenticates attachments, route length and terminal interval/transition/junction/A3 data (8840–9205). Per-edge opposite-link validation at 9341–9349 emits `InvalidOppositeEdge` on any non-reciprocal nonnegative link. If one formerly paired side is set to -1, its surviving counterpart still fails this reciprocal check. This is a structural check, not an edge-to-certificate check.
- A5 preflight rejects HardRail sides without a linked opposite or marked exterior (`RemeshPipeline.cpp:3633,3673–3678`). Pair traversal then validates both routes before owner, distinct regions and reversal (`4869–4925`), and the certificate lookup requires exact first/second edge, owner rail and first route (`5040–5051`). A mismatched certificate therefore remains non-consumable to A6/A7; the route/owner rejection precedence belongs to A5. No evidence of alternate certificate consumer other than A5 lookup and hashing from the reviewed source. No new product state or fallback.
- The specific tests for `selector:211/219` expect `InvalidOppositeEdge` (TQ `9050–9085`), now no longer preempted by the certificate pair clause. The ten M1 rows have the necessary producer-owner order; actual success remains a TB30 falsifiable prediction, not a review-proven runtime fact.
- The source-commit diff is one file only. Comparison from exact verified review snapshot `7d97284b909821e89fdec919850c2a2f384f7da6` to resume HEAD `87e179ae17031141c8c5f4f49d7388ae7a865d84` changed **only `STATUS`**. Source snapshot archive SHA-256 `84eb77e2755eb69d0e9efa8216115671aa314a3598b90995786428c55d018289`; 5812/5812 source manifest hashes independently passed.
- CB29 compile package `12492950387`: outer SHA-256 `9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`; 28/28 internal hashes, source SHA matches, eight declared targets (six executables/two static libraries), compile and preflight 0/0; CMake `DIRECTIONAL_ENABLE_GMP=ON`, `GMP_ROOT=/usr`, actual gmpxx+gmp link command and `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No test or benchmark was run in this Review.

## TB30 authorization and falsifiers

**Authorize canonical successor:** `M6-CP3-TB30-RP01-CERTIFICATE-ASSOCIATION-OWNERSHIP-VERIFICATION`, artifact-only Test + Benchmark. Use exact existing CB29 package `12492950387` and source `2602e7398cdc6f1281abe11a758de35166b6590c`, existing targeted harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`, and `Architecture_M6_CP3_TB30_Targeted_Case_Manifest.tsv` SHA-256 `2b41ac11aad179770c5eb538876abcfb8fa0fd1d8df5315af0605ab35a7c59f6`, `EXPECTED_CASE_COUNT=29` (9 TB29 controls + 10 M1 expected PASS + 7 non-M1 expected unchanged RED + 3 certificate-authenticity guards expected PASS). Recheck artifact expiration/source at TB entry. Extract package preserving executable modes, never rebuild, configure, relink, repair, change selector, or run a benchmark. Each row executes once; zero runs, skipped, invalid or duplicate evidence fails. Preserve raw per-case logs and hashes; report first typed reasons for all seven expected RED; postflight and control verification mandatory.

**Falsify if** an M1 member is RED or rejects with non-frozen code; any control/authenticity guard RED; a non-M1 factory row changes its observed typed first reason (`face-gauge-missing` for six, `open-rail-chain` for `cp3entry:4`); any package/hash/source mismatch, unexpected PASS, invalid/zero-selected test or unbounded full suite. Do not treat expected RED as a regression. Require independent TB30-REV before next definition/implementation or selector promotion.

## History-sensitive boundary verification (2026-10-23 continuation)

The local `review_check.py boundary` was executed against the source-snapshot synthetic Git repository and **did not pass** because that synthetic history omits rewrite commit `8b7299b43764a6ba3444e5bc774a2f1b65e99731`. This is not a claim of a local history-aware script PASS. To adjudicate the failed history portion independently, the actual GitHub commit and file APIs were used, starting at the verified rewrite baseline (2026-10-17T00:59:26Z), with commit-by-commit file-specific additions/deletions checked against exact baseline and current contents.

- `CHANGELOG.md`: all 127 path-changing revisions inspected, **0 negative line deltas**, cumulative +2031; baseline 2134 lines, committed head 4165 (exact reconciliation).
- `.agents/Directional/LESSONS.md`: all 16 path-changing revisions inspected, **0 negative line deltas**, cumulative +58; baseline 325 lines, committed head 383 (exact reconciliation).
- The three rewrite-protected documents retain all baseline headings: handoff 4/4, orientation 1/1, regression tracker 0/0. The baseline is an ancestor of the reviewed head by GitHub comparison.
- Exact remote compare from compiled semantic source `2602e7398cdc6f1281abe11a758de35166b6590c` through this review's committed docs/status head found no changed production, test, fixture, build, or selector path. The local source snapshot staged only the seven intended documentation files. The verified Google Drive workflow applied exactly those seven paths; its staging object was retired.

**Qualification:** This is a remote-authoritative re-derivation of the history-dependent boundary and ledger predicates, **not** a successful execution of the exact helper against a complete local Git history. The synthetic checkout cannot independently establish `git status -sb` origin synchronization; exact remote PR head/commit and changed-path authority were checked via the GitHub connector instead. These tooling substitutions do not promote any runtime result or relax TB30's falsifiers.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a — no accepted selector change; TB29 44-row manifest unchanged, re-hashed `39fa5eb83e2da1b0668bc7368c5304011ec13de8804c54a2a3466f927c42d236`. |
| Decisive claims independently re-derived | One-file commit diff; A4 authenticity + structural reciprocity; A5 preflight/pair/lookup; 28 package hashes, SHA/GMP/boundary. |
| Non-vacuity checked | M1 10 owner-order probes, 7 non-M1 unchanged RED, 9 controls and 3 independent authenticity guards; TB30 runs them. Static review cannot claim runtime. |
| Prior obligations discharged/carried | RA-143.3 compile-only split statically accepted; RA-143.4 TB30 issued; RA-139.5 full-census harness flaw carried; face gauge/A3/A5, T1 and G4-B002 carried separately. |
| Stable accounting | 66/17/49, debt 1; CP2 491/491 accepted; R3 403/497 rejected, TB28 462/497 candidate only; CP3 not accepted. |
| New candidates/obligations recorded | No new stable regression; TB30 falsifiers in this decision, no tracker reclassification. |
| ORIENTATION currency line | Updated for CB29 Review/TB30, 2026-10-23. |
| ORIENTATION §3 / §4 / §7 / §8 | §3/§7 refresh; §4 n/a no witness state change; §8 n/a no new defect pattern. |
| CHANGELOG | CB29 Review entry added. |
| ROADMAP | CP3 still open, current boundary refreshed; no checkpoint promotion. |
| Selector manifest | n/a, 497 selector untouched; separate targeted TB30 case manifest added. |
| LESSONS | Existing stage-ownership / independent review lessons apply; no genuinely new pattern. |
| Consolidation under CLEAN_UP_POLICY | n/a: CB29 active record and predecessor evidence retained for pending TB30/REV. |
| Successor frozen | TB30 ID above, exact source/package/harness/manifest/count/falsifiers here. |
| Turn boundary held | No product/test/selector/build/workflow changes and no Directional runtime execution in Review. |
| review_check.py boundary | Synthetic-history command FAIL (rewrite baseline absent); independent real-GitHub commit-by-commit remote verification above passes corresponding history and no-code/selector-drift predicates. No literal script PASS claimed. |
| `STATUS` lifecycle maintained | Entry/resume beacon updated; final beacon written last. |
| Pushed to origin, branch in sync | Verified remote application is a post-record closeout duty; this record must not infer branch synchronization from a synthetic local source snapshot. |

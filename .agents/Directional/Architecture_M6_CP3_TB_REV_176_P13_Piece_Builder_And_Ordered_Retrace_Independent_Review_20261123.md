# M6-CP3-TB-REV-176 — independent TB176 review (2026-11-23 UTC)

## Situation

**REJECTED.** The complete immutable TB176 test gate executed **1,001/1,001**, with **994 PASS, seven RED**, zero missing, skipped, duplicated, or abnormal cases. The seven old mechanical failures remain at rows **445, 652, 653, 656, 658, 660, 786**. The new isolated ordered-retrace case at row 1001 passed. No production acceptance or selector promotion follows.

## Background — independent evidence and source authority

- Exact TB176 result ZIP artifact `14861444963`: independently verified outer SHA-256 `202cb81282d9e8a0bb6b711020af80450e407feb12b71de613b1be8cca110453` and **2,010/2,010** internal SHA256SUMS plus all 1,001 raw log digests. Immutable CB-197B packaged source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`, package `14859356205`; TB176 run `45263429563`.
- Independent TB175 comparator artifact `14849271506`: outer SHA-256 `be7a0f783d0afb025ccee2353921a765c340766340553f2d70b4b5c32992b347`, **2,008/2,008** internal files and all 1,000 raw logs verified. TB175 **993/1,000**, same seven RED; its exact source `f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5`.
- Source audit used exact snapshot commit `6240ea392114da3d8be5ae9a7cbe019a880a782e`, Actions run `45271096317`, artifact `14864921566`, outer SHA-256 `67c10c0ba03c3ee948773126594d33e97d081d527dca250cf19b3f5706953a70`. Snapshot source tar SHA-256 `ae0474c2e7a7072a8517569e0699309c646e9384a0e1a531350809e786951993`, verified **5,828/5,828** source-file digests.
- TB175 selector manifest SHA-256 `e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35`; TB176 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`. The first 1,000 TSV rows, **including the header**, match byte for byte. Independently rehashed first 491 accepted rows plus header: `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`.

## Assessment — comparison and non-vacuity

1. All **1,000/1,000** inherited ledger entries agree on identity, outcome, admission, reason and failure site, excluding the permitted per-run log hash. There are **778** byte-identical raw logs, **222** logs differing only by normalization N1/N2 (GoogleTest elapsed time or line endings), **zero** unauthorized differences, and **zero** records requiring N3 reordering. Row 179 falls within permitted normalization; its diagnostic order is unchanged. The inherited membership is the identical **1,081-item set**; TB176 includes one new test, producing **1,082** members. Membership display order changed at insertion and is not a byte-prefix; the frozen manifest *is* byte-prefix identical.
2. Row **1001** is a `GUARD`, `tb-rev-175:retrace-ordered-stretches`: `ExactSourcePathRetrace.PathRunningOverAStretchTwiceDoesNotRetrace`, **1/1 actually executed, PASS**. The test supplies multiple directed visits to an edge and a partial turnback. An old merged-coverage algorithm would incorrectly accept the repeated traversal; the revised exact ordered-stretch predicate rejects it. This is a real negative discriminator, not an empty selected filter.
3. The source inspection found `exact_source_retraced_traces` used by the isolated test and defined in `include/directional/authority/ExactSourcePath.h`, **not called by production A2a**. Thus the new guard does not establish mechanical production repair. The seven red controls retain their previous exact identities and reasons; row652 remains `RegionElectedCutComponentEmpty`, not a certified selected topological disc. Row979's staged `RegionContainsInteriorSingularity` at source vertex 8 is not production acceptance.
4. `execution-boundary.json` for both runs confirms immutable package execution (`configure=false`, `compile=false`, `relink=false`, `benchmark=false`, `postflight=true`) and no skipped cases. Both exit with failed full-gate status; no result is relabeled green.
5. Accepted TB169 **993/993** and CP2 **491/491** remain the only applicable accepted baselines. The seven TB170 accepted-green mechanical failures are **one carried regression recurrence**, not seven new events and not a new accepted-green loss in TB176. Stable count **67 events / 17 categories / 50 recurrences**, witness debt **1**, deferred **81**. CP3/497/D0/H4 promotion remains forbidden.

## Recommendation — exactly one successor and its falsifiers

Freeze **`M6-CP3-CB-198-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT`** as a **test-only Code + Build** turn. It must use the exact per-fixture `exact_trace_segment_pieces` path and the ordered `exact_source_retraced_traces` predicate to produce a deterministic admission and removal receipt for every mechanical fixture *without changing any production output*. Record each kept/removed trace pair, full source-entity and directed interval witnesses, and the first and last endpoint relation. Require an actual positive-length opposite traversal for a removal. Row652 currently predicts four candidate pair removals (lens orbits 1/3/4/5); record observed results without forcing the prediction. If any exact source path is absent, fail closed rather than treating it as a non-match or proof. If the predicted ownership cannot be established, return to Review before production wiring. Add only relevant tests/receipts; preserve production, fixture, selector, acceptance, and validator semantics. Compile the eight required GMP/GMPXX targets by the reusable compile-only workflow; **execute no compiled binary in CB-198**.

**Held for later turns:** CB-199 A2a production selection and all dependent `struckTrace`/incidence reference remaps (arrival owns `Y.port`), CB-200 port readers and region-face evidence, F1/F3/F4/F5, E5 collinear/contact authority, S4/S6/S7 CB-190 diagnostics, row979 and CP3 acceptance. A receipt is not permission to wire selection; after CB-198, the independently authorized TB-EXEC-177 must test the immutable artifact in its own turn. No successor work occurred here.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 491-row + header `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`; TB175/TB176 first 1,000 manifest rows byte equal |
| Decisive claims independently re-derived | ZIP digests, 2,008/2,010 internal hashes, 1,000 ledger rows, 1,000 raw pairs, pass/RED partitions, source call sites |
| Non-vacuity checked | Row1001 executed one actual selected negative and would fail old merged-coverage logic; it is not wired in production |
| Prior obligations discharged/carried | G1 ordered predicate discharged for isolated helper; G2 exact piece extraction verified; G3 same library no extra CMake; G4 1,000 prior cases unchanged; test-only per-fixture positive/negative receipt carried to CB-198; F1/F3/F4/F5/E5, S4/S6/S7 and row979 carried to later owners |
| Stable accounting | 67/17/50, debt1, deferred81; accepted TB169 993/993, CP2 491/491; candidate TB176 994/1001 rejected |
| New candidates/obligations recorded | Existing TB170 mechanical recurrence re-carried to tracker with exact CB-198 falsifiers; no new stable entry |
| ORIENTATION currency line | `M6-CP3-TB-REV-176` 2026-11-23 UTC, current state and successor |
| ORIENTATION §3 / §4 / §7 / §8 | §3 status updated; §4 witnesses unchanged; §7 replaced stale current priority and explicitly retained historical entries; §8 same unwired-helper pattern, no new category |
| CHANGELOG | Turn entry added |
| ROADMAP | M6 status and near-term routing updated; checkpoint not promoted |
| Selector manifest | n/a — no accepted selector was added or modified; independently rehashed existing prefix |
| LESSONS | n/a new — existing non-vacuity / producer-wiring pattern recurs, no new lesson proposed |
| Consolidation under CLEAN_UP_POLICY | n/a — one current review record; historical evidence preserved without deletion |
| Successor frozen | `M6-CP3-CB-198-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT`; pre-stated falsifiers and stop rules in Recommendation above |
| Turn boundary held | Review inspected source and archives; no product, test, fixture, selector, benchmark, build or runtime mutations |
| review_check.py boundary | Executed on verified source snapshot; selector-content checks pass, but `boundary` reports FAIL for Git ancestry baseline and three durable rewrite sources because downloaded source archive excludes `.git`; no claim of actual remote ancestry from synthetic tree |
| `STATUS` lifecycle maintained | Entry beacon `M6-CP3-TB-REV-176` opened 2026-11-23T21:33:33Z; final state to be set only after docs publication and cleanup |
| Pushed to origin, branch in sync | Apply and branch-head checks required after publication; synthetic snapshot has no real `origin` tracking, so cannot itself prove branch synchronization |

# Changelog

All notable completed changes and immutable acceptance checkpoints for the Directional surface-cell implementation are recorded here.

This is a durable historical record, maintained separately from `.agents/Directional/Future_Chat_Session_Handoff.md`. The handoff owns only the current resume state, mandatory next action, live blockers, current immutable authority, and durable operating policy.

The format is inspired by [Keep a Changelog](https://keepachangelog.com/): entries are newest first, completed work is separated from unreleased work, and changes are grouped by purpose rather than by commit dump. This project uses migration milestone identifiers instead of semantic-version releases. Dates are included only when they are directly established by authoritative records.

## Maintenance rules

- Keep entries newest first.
- Record completed, durable changes only; active next-turn instructions remain in the handoff.
- Prefer the categories `Added`, `Changed`, `Fixed`, `Validation`, `Known limitations`, and `Operational notes` as applicable.
- Preserve exact implementation commits, artifact IDs, run/job IDs, hashes, stable regression IDs, and failure classifications when they are part of immutable authority.
- Link to the authoritative report when available instead of duplicating every machine log.
- Do not rewrite or remove historical entries merely to shorten the file. Correct factual errors narrowly and preserve provenance.

## [Unreleased]

### Review — R-A closure after REV-17/REV-20 partial remediation

- Independently reviewed exact implementation/test source `1352f3d18eb3821ecda9d74ea5e439adb5bcb875` at branch authority `356a0bc2733af41e15fad056161e526865c147c5`. Six later commits change durable documents only.
- Rejected overall R-A. The implementation delta from the prior review contains substantive REV-17/REV-20 completion/optimizer changes but only two deletions in `RemeshPipeline.cpp`; REV-18 global aggregate authority and REV-19 transactional/final-oracle work are not implemented.
- Retained the bounded REV-17 owner-validated certificate/canonical-cache changes and REV-20 removal of named optimizer/verifier compatibility paths as authentic compile-valid progress, not independent acceptance. Their semantic contracts were not executed.
- Added `R-A-REV-21`: affected boundaries accept any `SourceTopologyRegions` with the same face count and never bind its stored row topology to the supplied source-face matrix. Require exact per-row topology binding and same-extent foreign-authority zero-publication contracts.
- Superseded the targeted runtime turn for partial artifacts `9149834162 / 9149834634`; the package is known source-incomplete and remains compile-only history. No generated runtime, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input executed in this Review turn.
- This Review changed durable planning/status documents only. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority; totals remain **34 events / 14 categories / 20 recurrences**.

### Fixed — R-A-REV-17 and R-A-REV-20 partial remediation

- Closed `R-A-REV-17` at the Code + Build boundary: completion/assembly now requires complete source topology/chart/support authority, validates incoming and intersected typed certificates against their owning region/sheet/chart/support incidence, derives absent authoritative identity canonically, rejects any present stale/partial/exact-only alias, and publishes collision ownership diagnostics only from the final owner-validated stitched authority intersection.
- Replaced fabricated collision authority with source-owned positive fixtures and fail-closed wrong-owner, sparse/unowned, wrong-sheet, wrong-face, exact-only, and stale-canonical zero-publication contracts.
- Closed `R-A-REV-20` at the Code + Build boundary: removed affected SurfaceCells optimizer raw source component/position mirrors, legacy feature-interval and point-cloud fallbacks, standalone projection fallback, and the alternate basic-validator branch; optimization/final verification now require complete source authority and fail closed when it is absent or incomplete.
- Migrated affected optimizer, rail, pipeline, benchmark, and completion/validation contract sources to the strict authority-owned API without reintroducing compatibility adapters or raw semantic mirrors.

### Validation — R-A-REV-17 and R-A-REV-20 partial remediation

- Exact compile-valid source: `1352f3d18eb3821ecda9d74ea5e439adb5bcb875`; final content delta from pre-turn head `7b10c1c3cde9769438991742594676ec75e4200a` is **12 implementation/test files**, 927 additions and 615 deletions.
- Compile-only run/job `31616904715 / 94181880684` completed Release/static/Ninja/PRE_TEST **118/118** with build exit `0`. Result artifact `9149834162`, outer SHA-256 `c5055df51d9b94605c27817e596a04983bddb33956727a2c47c494d42a0b2ee2`; log artifact `9149834634`, outer SHA-256 `04291253c21af768af9c35b61f12e327c0ec536642a2ddf8895781657b1261a7`.
- The source audit reported `R-A REV-17/20 source audit: closed`, confirmed mandatory owner-validated stitch authority/canonical cache equality for REV-17, and found the named optimizer/verifier compatibility branches and raw mirrors absent for REV-20.
- Independent artifact inspection verified exact packaged source, **22** regular files including `SHA256SUMS`, a self-excluding recursive manifest **21/21**, zero manifest self references, five empty source-status snapshots, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority; this partial package is not an M1 acceptance candidate.

### Operational notes — R-A-REV-17 and R-A-REV-20

- Initial compile-only run/job `31616096676 / 94179160869` exposed a genuine compile defect at `PureQuadCompletion.cpp`: three ownership-diagnostic helpers still called the pre-cutover two-argument authoritative-identity resolver after REV-17 made owner validation mandatory. The correction did not restore that compatibility signature; it defers duplicate-face conflict classification until all stitched occurrences have produced final owner-validated authority intersections and then uses those final global identities for ownership diagnostics and published lineage. No generated runtime executed in the failed compile attempt.

### Review — overall R-A and R-A-REV-14 through R-A-REV-16

- Independently reviewed exact implementation/test source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` at branch authority `fd96852d19defe70effd0dc6fbbaf07db8378e55`; later affected production/test blobs are unchanged. Rejected overall R-A and the requested REV-14-through-REV-16 checkpoint.
- Added `R-A-REV-17`: collision certificates are only checked for nonempty fields; the positive test fabricates unowned region/sheet/chart IDs, omits source authority, and compatibility identity aliases remain. Require source-owned certificates and canonical-only identity.
- Added `R-A-REV-18`: disconnected aggregation remaps typed authority but publishes no global owning `SourceTopologyRegions` and does not rebuild authoritative/stitch caches or face-cycle hashes. Publish the owner, validate final lineage, and regenerate all derived identity.
- Added `R-A-REV-19`: aggregation writes labels/rails before remap validation, rejection clears only a subset, and the REV-16 oracle compares cached component validation rather than actual post-merge validation. Make publication transactional and add complete final-product/zero-publication counterfactuals.
- Added `R-A-REV-20`: the complete inventory still finds affected raw optimizer mirrors, legacy point-cloud/feature-interval fallbacks, and an alternate basic-validator branch. Remove them from the SurfaceCells boundary or isolate generic behavior behind a separately typed implementation.
- This Review changed durable planning/review/status documents only. No production/test/build/workflow source was edited and no generated runtime, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input executed. M1l remains immutable runtime authority; totals remain **34 events / 14 categories / 20 recurrences**.


### Fixed — R-A-REV-14 through R-A-REV-16 partial remediation

- Closed `R-A-REV-14` for reviewed completion/assembly paths: collision publication now has one canonical post-intersection typed authority; derived `authoritativeIdentity` and canonical face-owner cycles are regenerated from that final authority. Compile-visible contracts cover overlapping-but-nonidentical compatible intersection publication and disjoint rejection.
- Closed `R-A-REV-15` for reviewed component aggregation paths: region/sheet/chart/support remap domains and owner relations are built from published source topology/chart authority; sparse, out-of-domain, wrong-owner, and wrong-face typed authority rejects before output publication.
- Closed `R-A-REV-16` at the Code + Build contract boundary: a production-owned pre-aggregation counterfactual exposes raw projection tamper to the real aggregation consumer and compares complete semantic/hash/downstream authority-validation output; malformed typed authority has a fail-closed zero-publication contract; the replacement audit classifies repository-wide affected reads/writes and checks the remap/collision/counterfactual bodies.

### Validation — R-A-REV-14 through R-A-REV-16

- Exact review-remediation source: `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e` (`7 files changed, 911 insertions, 241 deletions`).
- Compile-only run/job `31602025466 / 94131563590` completed Release/static/Ninja/PRE_TEST **118/118** with build exit `0`. Result artifact `9143819164`, outer SHA-256 `e3213d8ed94121e734b69ed17f64501a3a059b64ccfa3cbb6be48a1a98c83e13`; log artifact `9143819888`, outer SHA-256 `c2d0cbc28a296590f22a343aed9173a3e363e1cdb5a53ee198ae4a8dc5e44aa6`.
- Audit reported `R-A-REV-14 source/contract audit: closed`, `R-A-REV-15 source/contract audit: closed`, and `R-A-REV-16 counterfactual/read-write audit: closed`.
- Independent result inspection verified exact source `cb848e4dde30bcbe19dcd5d07a408edb2a47dd6e`, **22** regular files including `SHA256SUMS`, a self-excluding recursive manifest **21/21**, zero manifest self references, all five source-status snapshots empty, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority and regression totals remain **34 events / 14 categories / 20 recurrences**.

### Operational notes — R-A-REV-14 through R-A-REV-16

- Initial run/job `31601748377 / 94130625219` stopped before source application, audit, or compile because the connector-created final source/audit transfer chunks lacked a trailing newline and therefore failed the pinned concatenated-payload digest. Log artifact `9143393404`, SHA-256 `7da2e3c7ab3222349084926aad29e1233506f3d401d4987a51a4fea9647d070f`. The transfer chunks were corrected and the successful retry above followed. This was orchestration-only: no product patch or generated runtime executed and no regression event was assigned.


### Review — complete R-A closure gate after REV-11 through REV-13

- Reviewed PR #8 through branch head `344f996622606121a9567beaf1dad4001a5374f3`; exact implementation/test source remains `78056ba849fafad27eb55e8008fbc20a56300868`. Rejected R-A completion.
- Independently verified run/job `31584657331 / 94075568409`, Release/static/Ninja/PRE_TEST **118/118**, both outer artifact digests, exact packaged source, five empty source-status snapshots, and the self-excluding manifest **21/21**. This authentic partial compile package is not an M1 acceptance candidate; semantic contracts were compiled but not executed.
- Added `R-A-REV-14`: collision publication copies the intersected typed certificate but retains `authoritativeIdentity` from one selected pre-intersection candidate. Publish one canonical authority and add an overlapping-compatible collision contract that inspects the emitted authority.
- Added `R-A-REV-15`: component region/sheet/chart remap reconstructs IDs with bounds derived from the candidate values and advances offsets from observed maxima. Remap through independent authority domains/owners and add out-of-domain, sparse-ID, wrong-owner, and zero-publication contracts.
- Added `R-A-REV-16`: the production raw-tamper contract mutates only after aggregation and compares untouched typed fields, while the audit accepts substring and blanket-assignment proxies. Move tamper before the consumer and require a complete counterfactual read/remap/collision audit.
- This Review changed planning/status documents only and ran no generated Directional runtime. M1l remains immutable runtime authority; regression totals remain **34 events / 14 categories / 20 recurrences**.

### Changed — R-A-REV-11 through R-A-REV-13 partial remediation

- REV-11 added a per-key typed certificate, intersection, and incompatible-collision failure before positional merge. The later complete-gate review found that publication still retains a pre-intersection duplicate identity and records that remainder as REV-14.
- REV-12 added checked return paths, staged publication, face/support remap checks, and multi-component/malformed contract source. The later review found self-bounded region/sheet/chart IDs and non-counterfactual raw tamper, recorded as REV-15 and REV-16.
- REV-13 broadened the affected-symbol/read inventory and its required path list. Its successful Code + Build output is preserved below; the later review found that substring and blanket-assignment checks still miss the surviving defects.

### Validation — R-A-REV-11 through R-A-REV-13

- Exact review-remediation source: `78056ba849fafad27eb55e8008fbc20a56300868` (`6 files changed, 656 insertions, 216 deletions`).
- Compile-only run/job `31584657331 / 94075568409` completed Release/static/Ninja/PRE_TEST **118/118** with build exit `0`. Result artifact `9136856592`, outer SHA-256 `f6bd76caf0cb1a78b0faaedb04feaf157850d1e11336919efbf5cf698a07ce6d`; log artifact `9136857219`, outer SHA-256 `98353502b1cffa8f0f3e9233bddf8bf1c3d7909f48786e069bae1d3f5a4296f3`.
- The repository-wide audit reported `R-A-REV-11 source/contract audit: closed`, `R-A-REV-12 source/contract audit: closed`, and `R-A-REV-13 repository-wide affected-symbol/read inventory: clean`.
- Independent result inspection verified exact source, **22** regular files including `SHA256SUMS`, a self-excluding manifest **21/21**, zero manifest self references, all five source-status snapshots empty, `semanticContracts=compiled-not-executed`, and `runtimeExecution=false`.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority and regression totals remain **34 events / 14 categories / 20 recurrences**.

### Operational notes — R-A-REV-11 through R-A-REV-13

- Main compile runs `31583568437` and `31584101692` stopped before source application because the temporary patch payload was corrupted/truncated in repository transfer. Diagnostic run `31584275615` isolated the bad final chunk. Repair run `31584429133` reconstructed and hash-verified the exact payload but stopped when the ignored `.agents` path was not force-staged; retry `31584506399` repaired the payload successfully. These were orchestration-only failures: no product source patch was applied by the failed main runs, no generated runtime executed, and no regression event was assigned.

### Review — complete R-A closure gate

- Reviewed PR #8 through branch head `1c4f631ff4d0565f520796fb8fbfab854d5b8ad1`; implementation/test source ends at exact compiled commit `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e`. Rejected R-A completion.
- Independently verified run/job `31565756309 / 94017095695`, Release/static/Ninja/PRE_TEST **118/118**, exact packaged source, matching result/log outer digests, all five empty source-status snapshots, and a self-excluding recursive manifest **20/20**. The partial checkpoint is authentic build evidence, not an M1 acceptance candidate.
- Added `R-A-REV-11`: the stitch registry keys shared vertices by exact arrangement identity, checks the separately derived typed key only for validity, and compares only position on collision. Retain and validate compatible typed region/sheet/chart/support authority for every collision; add positive compatible and negative same-key/same-position incompatible-lineage contracts.
- Added `R-A-REV-12`: component aggregation validates typed lineage only before remap, while invalid chart/support remaps can be skipped/reset and published without a post-remap completeness check. Make remap checked and fail closed, validate the final lineage, and replace the helper-only extent contract with end-to-end multi-component raw-tamper and malformed-remap coverage.
- Added `R-A-REV-13`: the shipped REV-10 audit samples six implementation/header surfaces and selected test blocks, omits required affected consumers, and does not detect REV-11 or REV-12. Replace it with a complete failing affected-path/symbol/read inventory and semantic-body checks for exact-key collisions and production multi-component publication.
- This Review changed documentation only and executed no generated Directional runtime. M1l remains immutable runtime authority; regression totals remain **34 events / 14 categories / 20 recurrences**.

### Fixed

- Closed `R-A-REV-07` for the reviewed completion/assembly paths: exact arrangement-boundary identity is no longer sufficient by itself; published/stitch-authoritative vertices require complete typed topology-region/isolation-sheet/chart/support lineage, empty-source completion does not publish identity authority, and exact-only assembly fails `MissingTypedStitchIdentity`.
- Closed `R-A-REV-08` for SurfaceCells optimizer/verifier entry points: removed the optional source-authority flag, added fail-closed source-authoritative optimization/final-validation entry points, and removed raw component/sheet sheet-equivalence decisions from generic validation while retaining that generic API only for non-SurfaceCells use.
- Closed `R-A-REV-09` for multi-component aggregation: typed isolation-sheet extents/offsets now derive from complete typed lineage, incomplete coverage fails closed, typed remap occurs before raw projection/export, and raw labels no longer determine typed sheet identity.
- Closed the bounded `R-A-REV-10` script assertions at the Code + Build source/contract boundary. The later complete-gate review established that its claimed affected-path coverage was incomplete and records the remaining audit defect as `R-A-REV-13`.

- Closed `R-A-REV-03` for the reviewed completion/assembly paths: standalone and patch-local compatibility stitch synthesis is removed; exact boundary identities are validated; derived identities require complete typed topology-region/isolation-sheet/chart/support lineage; missing authority fails with `MissingTypedStitchIdentity`.
- Closed `R-A-REV-04` for the reviewed validator/optimizer/rail/hash/materializer paths: raw `SurfacePoint` component/sheet labels no longer accept, reject, scope, order, merge, hash, or route those semantic decisions.
- Closed `R-A-REV-05` at the Code + Build contract boundary: compiled sources now include exact/prebuilt identity mismatch, missing typed authority, distinct typed isolation-sheet, raw-projection-tamper, optimizer/rail tamper, and completion-hash tamper contracts. They were compiled but not executed.
- Closed the `R-A-REV-06` packaging defect for the partial review-remediation checkpoint: build output is out of tree, source provenance snapshots are clean, `SHA256SUMS` excludes itself, and the manifest is verified before upload. This does not make the partial package an M1 acceptance candidate; the final full R-A-through-R-G package must repeat these rules.

- Closed `R-A-REV-01`: materializer occurrences now own typed `IsolationSheetId`; reviewed cross-sheet equivalence, quotient-state, representative-ordering, and sheet-aggregation decisions no longer read `SurfacePoint::sheet` semantically.
- Corrected the exact `R-A-REV-02` encoding: the fallback stitch-key builder no longer inserts raw provenance component/sheet and now has a typed topology-region/isolation-sheet derivation. Closure review subsequently found that prebuilt compatibility identities bypass this derivation, so fail-closed R-A completion remains open as `R-A-REV-03`.

### Validation

- R-A-REV-07-through-10 review-remediation source: `d8d648a1521f2167320dbc372f1c5bcc9bedcf9e` (`10 files changed, 421 insertions, 102 deletions`).
- Compile-only run/job `31565756309 / 94017095695` completed Release/static/Ninja/PRE_TEST **118/118** with build exit `0`. Result artifact `9129549875`, outer SHA-256 `34f9d4a576ddfd79c2c35997ac95bdd91a0b549ac1bf519bc38a11d36d0559e5`; log artifact `9129550069`, outer SHA-256 `65fe62a061ab090f4929477997b28527d9511816e8c0518a136dac3604941bb0`.
- Independent result inspection verified exact source `d8d648a...`, **21** regular files including `SHA256SUMS`, a self-excluding manifest **20/20**, zero manifest self references, and all five recorded source-status snapshots empty.
- The shipped audit reported REV-07, REV-08, and REV-09 source/contract closure and REV-10 inventory clean for its sampled blocks. The later complete-gate review found that this sampling omitted required consumers and accepted proxy-only component evidence; `R-A-REV-13` preserves that correction.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. The new semantic contracts were compiled only. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority and regression totals remain **34 events / 14 categories / 20 recurrences**.

- Review-remediation source: core findings commit `e33a3c6be1db9c3e6f773a8deb2bebd870099536`; compile-corrected source `c62c99ffe5b7863820c91f4ff3a93645b22d3591`.
- Compile-only run/job `31561686903 / 94005144300` completed Release/static/Ninja/PRE_TEST **118/118** with build exit `0`. Result artifact `9127976318`, outer SHA-256 `f7bcf34579664f19cd5a73fd384b5ff020304c7b10a89c81ce35a89a92b38588`; log artifact `9127976660`, outer SHA-256 `3f4c5eef39aedbb06666edf3b09e5f2e5071209ba88a3d9ef0f9174083bd536a`.
- Focused source audit reports `R-A-REV-03 source audit: closed`, `R-A-REV-04 source audit: closed`, and `R-A-REV-05 compiled-contract inventory: present`. This is not the complete R-A closure inventory.
- Independent result inspection verified exact source `c62c99f...`, all five source-status snapshots empty, a self-excluding recursive manifest **22/22**, and the packaged six compiled test/benchmark executables plus `libdirectional_core.a` / `libdirectional_pipeline.a`.
- No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed. M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c` remains immutable runtime authority and regression totals remain **34 events / 14 categories / 20 recurrences**.

- Partial R-A review-closure source authority: `df386d1ad819879abbf9d7660c3d586778d7daee`.
- Compile-only run/job `31555887046 / 93988102158` completed Release/static/Ninja/PRE_TEST **118/118**. Result artifact `9125984929`, ZIP SHA-256 `23da519d16f59b3ba86d6defab185f51446700c6b6e405b88a5c735453ecdc81`; log artifact `9125985115`, ZIP SHA-256 `5a075c0ede75d79cb6b5ecc50d33c2e43a3f52d78b59bf5248bd33be14f7d051`.
- The focused source audit passed its two bounded textual checks, but did not cover compatibility identities or downstream validator/optimizer/rail read-backs and therefore did not establish the R-A closure gate. No generated Directional binary, discovery, test, benchmark, `ctest`, CLI, fuzzer, or custom input was executed.
- Independent download verified both outer ZIP digests. The result's internal `SHA256SUMS` fails 1/7 because it records its own empty-file digest; the other six metadata entries pass. `metadata/source-status.txt` records `?? build-m1-ra-rev/`. The artifact remains partial compile evidence and is ineligible for acceptance.
- M1 is not runtime accepted, immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`, and runtime regression totals remain **34 events / 14 categories / 20 recurrences**.

### Operational notes

- Initial R-A-REV-07-through-10 workflow run `31565569539` failed before job creation because a temporary embedded payload made the workflow YAML invalid. No source patch, compile, or generated runtime executed; the payload was moved to temporary repository files and the corrected workflow produced the successful compile checkpoint. This was orchestration-only and did not change regression state.

- Initial R-A-REV-03-through-06 compile run/job `31559713594 / 93999361586` reached link step 112/118 and failed because the new `stable_patch_owner` / `typed_lineage_stitch_identity` calls were forward-declared in `pure_quad_detail` while their definitions remained in the translation unit's anonymous `directional::geometry` namespace. Log artifact `9127433279`, SHA-256 `703ad2c1042ded9210ab37393e8b63fcd16fc7ad20c7d263ec66518c2900956f`. Commit `c62c99f...` corrects only that linkage; no generated runtime executed and no stable product regression was assigned.
- First retry run/job `31561631436 / 94004977538` stopped before source application/compile because the temporary linkage patch had an incorrect unified-diff hunk count. Log artifact `9127935690`, SHA-256 `595d140469768ecae959a3e5e2af5dc09eab3cee4daf3038bdf78901cdd2ddff`. The payload was corrected and retriggered; this was orchestration-only and did not change product/regression state.

- Initial partial-closure compile run/job `31555727064 / 93987628937` stopped at compile step 82/118 on one stale local `sheet` alias after the typed occurrence member was introduced. The correction was limited to that remaining aggregation read; no generated runtime executed and no stable product regression was assigned.

### Changed

- Replaced the normative architecture with the supplied Pipeline B-first `DESIGN.md`; Pipeline A is now optional future work gated on full Pipeline B Certified evidence.
- Revised architecture numbering to M0-M8: new M3 field-aligned curve network and M7 graded disposition; former M3/M4/M5/M6 map to M4/M5/M6/M8.
- Synchronized the M1 plans, roadmap, TODO, testing policy, test-redesign plan, regression tracker, historical-report status, and live handoff with the redesign.
- Retained both M1 Code + Build and Artifact-Only Test + Benchmark plans. The artifact-only plan is dormant until a fresh full R-A-through-R-G package exists.

### Review

- Reviewed the working branch through implementation baseline `5e023f1a8331c53182cfd296732c37cb7a889b88` against the complete R-A closure gate and rejected R-A completion.
- Verified the exact R-A-REV-01 materializer correction and the exact R-A-REV-02 raw fallback-encoding removal.
- Added `R-A-REV-03`: standalone/patch-local valid identities bypass typed fail-closed stitch derivation and can omit typed isolation-sheet authority.
- Added `R-A-REV-04`: source-authoritative validator, surface-optimizer, and rail-constraint decisions still read raw `SurfacePoint` component/sheet projections.
- Added `R-A-REV-05`: required typed positive, distinct-sheet, missing-authority, and raw-projection-tamper contracts are absent; existing fixtures still treat raw labels as authority.
- Added `R-A-REV-06`: the partial compile package is not internally self-verifying and does not have clean recorded source status.
- This was a static/documentation Review. No generated project runtime was executed, so no stable runtime regression event or recurrence was assigned.
- Independently reviewed R-A source `bebac907de814b07a55a770add4c897ab6d22ffd`.
- Verified compile-only evidence from run/job `31550744314 / 93972723960`, artifacts `9124167871 / 9124168143`, Release/static/Ninja/PRE_TEST **118/118**, with no generated runtime/discovery/test/benchmark execution.
- Accepted as substantial compile-valid progress: typed source region/member authority, private checked factories, exact row coverage, builder-only raw classifier ingress, `SourceEntityId` removal, and materializer API removal of parallel raw arrays.
- Rejected R-A closure on `R-A-REV-01` and `R-A-REV-02`: materializer sheet read-back and completion fallback identity still consume raw `SurfacePoint` component/sheet payload as semantic authority.
- No new stable runtime regression event or recurrence was assigned; runtime was not executed and totals remain **34 events / 14 categories / 20 recurrences**.

### Known limitations

- M1l `bd140cff...` remains the latest immutable runtime authority.
- Historical artifact `9105462679`, R-A compile artifact `9124167871`, earlier partial closure artifacts `9125984929` / `9127976318` / `9129549875`, and REV-17/REV-20 partial artifacts `9149834162 / 9149834634` are not M1 acceptance candidates.
- R-A-REV-01 through R-A-REV-16 are historical bounded compile checkpoints, not independent R-A acceptance. Bounded REV-17/REV-20 progress is retained; REV-18, REV-19, and REV-21 are open. R-A is not complete, and R-B through R-G plus the fresh full package remain pending.
- The supplied design retains five tracked clarification/evidence gates: D1 degradation-record wording, combined M3 tracing/decomposition proof, A1 quadrangulability certificate, M7 degraded producer proof, and calibrated D0/D1 quality thresholds.

Historical review baseline: `.agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`. Current closure authority: `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

## [M1l] Phase-Front Cell Topology-Region Consumer — Immutable accepted

### Changed

- Migrated persistent `SurfacePhaseFrontCell::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId` at `SurfaceTopologyRegion::id / normalize_scope -> SurfacePhaseFrontCell::sourceTopologyRegion -> still-raw materializer compatibility consumers`.
- Cell/edge topology-region agreement is direct typed equality; raw materializer, occurrence, hashing, map-key, and compatibility schemas receive legacy integers only through named typed-to-legacy boundaries.
- Topology-region discovery/partition/numbering, `SurfaceTopologyRegion::id`, raw face-to-region maps, certificate/periodic/bounded-disk/occurrence/lineage schemas, accepted component/sheet and edge-region authority, M2-M6, fallback/recovery, optimization, and G4 behavior remained outside M1l.
- Final semantic product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, `tests/SurfaceCellsPhase10Tests.cpp`, and compile-driven `tests/SurfaceCellTransitionQuotientTests.cpp`.

### Validation

- Implementation: `bd140cff4572412e6f4ecd70a6ce0fe85310932c`; semantic source base `d5a97953416196a8fc74c8d9790a1ae7b646ca2d`.
- Authoritative Code + Build run/job `31441661026 / 93627457924` completed Release/static/Ninja/PRE_TEST **121/121** in **8:38.45**, peak RSS **1,860,672 KiB**, with every generated-runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag false.
- Code + Build result artifact `9083262395`, ZIP SHA-256 `3d79b86dbda5e87134aef79330d02c227e0c1ba1f291f24bff6a3946c1aa895c`; build-log artifact `9083262833`, ZIP SHA-256 `a638cf52e9761ddead175aa32aa6824703c98c4553f97c0627e81baa82b3f1b8`.
- Recursive manifest **56/56**, SHA-256 `be8ec12bab5fc7cc76e6a36d2f833c76330593dada820a3b0c72c0e60fff0454`; package has 57 regular files including `SHA256SUMS`, seven executables, two static libraries, 27 fixtures including 21 milestone-G fixtures, zero symlinks; producer SHA-256 `fe7da9a182c785ae14ba24264682470cce7ceec119ce34251a4bee80c7113856`.
- Authoritative immutable runtime run/job: `31444022339 / 93634344918`. Runtime evidence artifact `9083913766`, ZIP SHA-256 `64ad28a3334dd3e73346a221e619873dbbc523e879cb31dda0843caa0214cccd`; runtime log artifact `9083913939`, ZIP SHA-256 `a4f9188b19fb9d21d6f7af39b54f9409cb7c3109669d3fddb0fb62fc999ea917`.
- Producer discovery **226**; M1l focused **6/6** individually; M1k-M1b focused preservation all green; M1d route counterexamples **3/3**; M1c transition counterexamples **3/3**; required-green producer **211/211**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean; remote elapsed times were **1.35 / 2.03 / 16.36 / 8.82 s** respectively.
- All eight historical/deferred red classifications remained unchanged. Exact immutable postflight preserved all **56/56** package checksums and zero symlinks.

### Known limitations

- Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect because accepted historical samples vary materially.
- Bunny preserved `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; authoritative remote elapsed time was **78.06 s**.
- Vase selected one test, reached `[ RUN ]`, and remained bounded safety-only at **60 seconds** with exit code 124.
- `PR8-R034 / G4-R007` remains active; G4 is unchanged.

### Operational notes

- First compile run/job `31440241452 / 93623230585` found one existing compatibility assertion still comparing integer zero directly with the typed optional cell region. The correction was limited to the named legacy helper; no generated runtime executed and no stable product regression was assigned.
- A corrected **121/121** compile run/job `31440985022 / 93625446238` then failed only during package provenance because the shallow checkout lacked semantic base `d5a979...`; log artifact `9083016010`, SHA-256 `946490f115398519aa2b3e5bcb9955eb12775ea496ca4c426bcf6be06a1c9991`. The final workflow fetched that exact base before producing the semantic diff.
- One local first-process Cylinder stall during corroborating artifact execution did not reproduce in the immediate bounded local retry or the authoritative remote run. It remains an execution-plane/harness transient; no product workaround was added.
- No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**.

Authoritative report: `.agents/Directional/Architecture_M1l_Phase_Front_Cell_Topology_Region_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

## [M1k] Phase-Front Edge Topology-Region Consumer — Immutable accepted

### Changed

- Migrated persistent `SurfaceFrontEdge::sourceTopologyRegion` from raw `int` to checked optional `TopologyRegionId` at the seam `SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`.
- Preserved topology-region discovery, partition, numbering, raw cell/region-by-face identity, periodic/bounded-disk/certificate topology-region schemas, accepted source component/sheet authority, M2-M6, fallback/recovery, optimization, and G4 product behavior.
- Final product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, and `tests/SurfaceCellsPhase10Tests.cpp`; source parent `38d6fc4c4042c5a0d200abf4e5594dcf325b8383`.

### Validation

- Implementation: `b9181364926cea840e9cb50da21fe721f33fd874`.
- Code + Build run/job: `31430898273 / 93593780187`.
- Result artifact: `9079318682`, SHA-256 `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d`.
- Build-log artifact: `9079319269`, SHA-256 `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381`.
- Recursive manifest: **68/68**, SHA-256 `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c`.
- Package: 69 regular files, seven executables, two static libraries, 27 fixtures, zero symlinks.
- Producer SHA-256: `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1`.
- Authoritative immutable runtime run/job: `31433794426 / 93603203081`.
- Runtime evidence/log artifacts: `9080245848 / 9080246452`.
- Producer discovery **220**; M1k focused **6/6**; M1j-M1b focused preservation green; M1d route witnesses **3/3**; M1c transition counterexamples **3/3**; required-green producer **205/205**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean.
- All eight historical/deferred red classifications remained unchanged.
- Exact immutable postflight preserved all **68/68** package checksums.

### Known limitations

- Strict-validator timing sampled **10/10 pass** in fresh processes but remains the existing nondeterministic sub-millisecond ratio/microbenchmark defect because accepted historical samples vary materially.
- Bunny remains `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remains bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remains active; G4 is unchanged.

### Operational notes

- Pre-authority Code + Build attempts exposed packaging/orchestration lessons without generated runtime execution: generated diffs may require `git apply --recount`; package cleanliness checks must exclude intentionally generated build/log directories; the fixture closure is 21 milestone-G files plus six root fixture files; checksum manifests must be generated after all package writes; and Bunny/Vase metadata must use the existing parameterized test names.
- A local Python `zipfile.extractall` attempt did not preserve packaged executable mode bits. Immutable runtime extraction must use the archive naturally, such as CLI `unzip`; `chmod` or package repair is not evidence-preserving.
- One local Cylinder harness stall did not reproduce in immediate bounded local execution or either controlled remote run; no product workaround was added.
- The first remote semantic run was green but its evidence upload used the wrong temporary-root path. Future workflows must use `${{ runner.temp }}` / `$RUNNER_TEMP` consistently.
- No stable product regression event or recurrence was created. Historical totals remain **34 events / 14 categories / 20 recurrences**.

The former M1k per-turn report was retired under `CLEAN_UP_POLICY.md` after its durable acceptance facts were consolidated here, in the regression tracker, and in immutable GitHub artifact history.

## [M1j] Phase-Front Edge Source-Scope Consumer — Immutable accepted

### Changed

- Preserved checked edge-owned source-component and isolation-sheet authority through the production path while keeping edge topology-region identity outside M1j.
- Final product/test delta was limited to `include/directional/geometry/SurfaceCellTracing.h`, `src/geometry/SurfaceCellTracing.cpp`, `src/pipeline/RemeshPipeline.cpp`, and `tests/SurfaceCellsPhase10Tests.cpp`; source parent `391271e253557b5c6b267befb3f2f33330c090c9`.

### Validation

- Implementation: `d5f681173600dc32dc7617de6105d9e584e593be`.
- Code + Build run/job: `31422691741 / 93566993166`, **120/120**, Release/static/Ninja/PRE_TEST.
- Result artifact `9076217893`, ZIP SHA-256 `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c`.
- Build-log artifact `9076218338`, ZIP SHA-256 `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`.
- Recursive manifest **67/67**, SHA-256 `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`; 68 regular files, seven executables, two static libraries, 27 fixtures; producer SHA-256 `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`.
- Producer discovery **214**; M1j focused **6/6**; required-green **199/199**; M1i-M1b focused preservation green; M1d route witnesses **3/3**; M1c transition counterexamples **3/3**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean without a fixture symlink.
- Remote validation run/job: `31425748772 / 93576908519`; evidence/log artifacts `9077128237 / 9077129029`.
- Heavy artifact-only run: `31425364955`.
- Bunny evidence/log artifacts: `9076993439 / 9076993713`.
- Vase evidence/log artifacts: `9076989920 / 9076990491`.
- Exact preflight/postflight preserved the immutable package and `fixtureSymlink=false`.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing remained deferred after fresh **0/10** characterization.
- Bunny retained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remained active.

### Operational notes

- Initial implementation `274b7ab88b581aa63e2e99c3abca2bc89eb742e2` exposed one incomplete raw/typed periodic-relation component comparison during compile. The final implementation corrected only that named compatibility boundary; no previously accepted runtime authority was lost.
- Earlier successful compile artifact `9075863759` was superseded because its manifest was generated before a final package log copy. The authoritative package computes and verifies the manifest only after all package writes are complete.
- No stable product regression event or recurrence was created; totals remained **34 / 14 / 20**.
- The superseded M1j Code + Build plan/report and artifact-only plan/report were removed under `CLEAN_UP_POLICY.md` after the durable implementation, validation, failure-class, and failed-attempt facts were consolidated here and in the regression tracker/GitHub artifact history.

## [M1i] Phase-Front Cell Source-Scope Consumer — Immutable accepted

### Changed

- Migrated persistent constructive-cell source component and isolation-sheet scope to checked typed authority while preserving existing source-label semantics and downstream compatibility boundaries.

### Validation

- Implementation: `b037157921094604f1b0c17f9c8b7076c7604b3b`.
- Source parent: `48614f383111c96fce1e69871b66199d94033d11`.
- Code + Build run/job: `31411770135 / 93531293415`.
- Result artifact `9072101943`, ZIP SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25`.
- Build-log artifact `9072102331`, ZIP SHA-256 `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`.
- Recursive manifest **72/72**, SHA-256 `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`; 73 regular files, seven executables, two static libraries, 27 fixtures; producer SHA-256 `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d`.
- Producer discovery **208**; M1i focused **6/6**; required-green **193/193**; M1h-M1b focused preservation green; M1d route witnesses **3/3**; M1c transition counterexamples **3/3**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean without a fixture symlink.
- Heavy artifact-only run: `31416928654`.
- Bunny evidence/log artifacts: `9073803244 / 9073803836`.
- Vase evidence/log artifacts: `9073801150 / 9073801757`.
- Local and remote postflight preserved the exact immutable package and `fixtureSymlink=false`.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing remained deferred after fresh **0/10** characterization.
- Bunny remained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remained active.

### Operational notes

- M1b focused names belong to the validation executable; a zero-selected filter is an orchestration error and never a semantic pass.
- Temporary Actions YAML must not use an unindented shell heredoc inside a block scalar; two pre-job heavy runs failed syntax validation before the corrected run. A committed helper payload or indentation-safe script is preferred.
- Historical regression totals remained **34 events / 14 categories / 20 recurrences**.
- The superseded M1i Code + Build plan and artifact-only report were removed under `CLEAN_UP_POLICY.md` after their durable implementation/test facts were consolidated here and in the regression tracker/GitHub artifact history.

## [M1h] Phase-Front Field-Chart Consumer — Immutable accepted after test-authority remediation

### Changed

- Adopted typed field-chart authority at the constructive-front consumer while preserving existing product behavior.
- Remediation corrected the focused test witness without changing the accepted production implementation.

### Validation

- Remediation implementation: `32b22d3ee8aa46ba2d1fd149ce04204a4206d0c0`.
- Unchanged production implementation: `de4e2ba7c19d2e49931655dc22d758f50656d054`.
- Build run/job: `31404102605 / 93506073062`.
- Result artifact `9069186973`, ZIP SHA-256 `d2b334f278f0281c5b3a5a5a6b33ba8bf085b7cf374376beb437e559646d9df8`.
- Build-log artifact `9069187317`, ZIP SHA-256 `56c0d0fb012b5d3b5fa4bb7284a496d700a4ebf408806b53c27f21f00311679a`.
- Recursive manifest **72/72**, SHA-256 `4b8839695369a114567a38fbcddc4dde7d1cea8b024940cb2071a256d9d594d8`; 73 regular files, seven executables, two static libraries, 27 fixtures; producer SHA-256 `937adceea641f372ee42eeb9a3b91c3bba2088847755cc234eaf0b3754f208ac`.
- Producer discovery **202**; M1h focused **6/6**; required-green **187/187**; M1g-M1b preservation green; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean without a fixture symlink.
- Heavy artifact-only run: `31407263138`.
- Bunny evidence/log artifacts: `9070146263 / 9070146878`.
- Vase evidence/log artifacts: `9070135665 / 9070135953`.
- Local and remote postflight preserved the exact immutable package with `fixtureSymlink=false`.

### Known limitations

- All eight historical/deferred red classes remained unchanged.
- Strict-validator timing remained deferred after fresh **0/10** characterization.
- Bunny remained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- `PR8-R034 / G4-R007` remained active.

### Operational notes

- The preceding immutable runtime from artifact `9066967620` was blocked at M1h **5/6** and required-green **186/187** because the focused witness conflated producer chart-domain coverage `{0,1,2}` with sampled lattice-occurrence coverage `{0,2}`. It was classified as a test-authority defect, not a product regression; the accepted remediation was test-only and preserved the production implementation.
- Historical regression totals remained **34 events / 14 categories / 20 recurrences**.
- The superseded M1h artifact-only report was removed under `CLEAN_UP_POLICY.md` after its durable implementation/test-authority facts were consolidated here and in the regression tracker/GitHub artifact history.

## [M1g] Periodic Holonomy Route Transport Consumer — Immutable accepted

### Changed

- Migrated the seam `periodic canonical face cycle -> ordered source-edge crossings -> whole-cycle holonomy decision` to checked source-step identity and typed route transport.
- Preserved the existing nonzero whole-cycle `PeriodicHolonomyMismatch`; M1g did not implement nonzero periodic Z4 support.

### Validation

- Implementation: `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2`.
- Build run/job: `31362470744 / 93373936472`.
- Result artifact: `9053047653`, SHA-256 `296f3ed13f2f09143a14f63555171d013939c2525052a56b807ea7f00cf1bd0c`.
- Log artifact: `9053048092`, SHA-256 `c5c3d964d9210982bfb08d0cf46900308a2498cee9ea2e54879dd35e61cacbd9`.
- Recursive manifest: **64/64**, SHA-256 `89beb0a12c1051a0fd4d55af6a8ee27e897c0f610045efa8b270a42dc09d51ae`.
- Producer discovery / required-green: **196 / 181/181**.
- M1g focused **6/6**; validation **77/77**; M1a **14/14**; T1 **29/29**.
- Plane, MultiFaceSeam, CloseSheets, and Cylinder remained independent-oracle clean.
- Remote heavy evidence run: `31394985769`.
- Bunny job `93475574330`, evidence/log artifacts `9065273769 / 9065273267`.
- Vase job `93475574119`, evidence/log artifacts `9065263527 / 9065262959`.
- Exact local and remote postflight preserved immutable package authority.

### Fixed

- The M1g package recorded the four exact parameterized direct-product names, correcting the stale nonexistent MultiFaceSeam and CloseSheets names previously found in M1f package metadata without changing product/test behavior.

### Known limitations

- `G4-B003` remained unresolved because nonzero periodic Z4 support was deliberately out of scope.
- All eight historical/deferred red classifications remained unchanged.
- Bunny remained `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.
- Vase remained bounded safety-only at 60 seconds.
- Strict-validator timing remained a deferred nondeterministic microbenchmark defect, with M1g characterization **1/10 pass, 9/10 fail**.

### Operational notes

- M1g exposed a non-product artifact-portability defect: `test_data_root()` searched `bin/test-data` while the immutable package stored sibling `../test-data`. Runtime-only fixture symlinks were used outside packaged content. M1h owned the minimal executable-relative lookup correction.
- The temporary runtime workflow was removed before its trigger; only `agent-source-snapshot.yml` remained durable.

## [M1f] Vertex-Continuation Route Transport Consumer — Immutable accepted

### Changed

- Migrated `surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.
- Replaced `PathState::matching` raw signed accumulation with checked source-step identity, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition in observed route order.
- Preserved fan/path discovery, branch resolution, ranking, failure semantics, public compatibility representation, the separate periodic whole-cycle holonomy accumulator, `FieldChartId`, M2-M6, and G4 behavior.

### Validation

- Implementation: `baed0f24831c476f45a1b742c12314e3fb03e10e`.
- Build run/job: `31356131866 / 93356062724`.
- Result artifact: `9050850344`, SHA-256 `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f`.
- Log artifact: `9050850513`, SHA-256 `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99`.
- Recursive manifest: **59/59**, SHA-256 `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e`.
- Package: **60** regular files including `SHA256SUMS`, seven executables, two static libraries, 27 fixtures.
- Build: **120/120**, Release/static/Ninja/PRE_TEST, **8:50.14**, peak RSS **1,848,704 KiB**; Code + Build runtime **false**.
- Exactly six `SurfaceCellVertexContinuationRouteTransportAuthorityMigration` contracts compiled for the immutable package.
- Exact artifact-only validation accepted producer discovery **190**, M1f **6/6**, required-green **175/175**, M1e/M1d/M1c/M1b preservation, validation **77/77**, M1a **14/14**, T1 **29/29**, and all four direct independent-oracle products.
- Remote heavy-case run: `31357556834`.
- Bunny job/artifact `93360001159 / 9051190671`, SHA-256 `04c1c9a74dd5c0d104006230180043d7d0eed6a22812379558138c4c4b7fcadf`.
- Vase job/artifact `93360001142 / 9051188086`, SHA-256 `84cf33ee9ef469c33b149a0e4a77620df13207d991a89f73ed5c6c2c9da06750`.

### Fixed

- The first compile attempt `17afbfd8baf0d369d9136534c0a11784ca0dca10` failed because a forward declaration crossed the existing anonymous-namespace helper ownership boundary. The surgical correction introduced a local continuation provenance helper without changing accepted M1e authority.

### Known limitations

- Bunny preserved `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0` after independent-oracle rejection.
- Vase reached `[ RUN ]` and remained bounded safety-only at 60 seconds.
- Strict-validator timing remained nondeterministic at **9/10 pass, 1/10 fail**.

### Operational notes

- A non-blocking package metadata defect was found: `metadata/direct-product-test-names.txt` contained stale nonexistent non-parameterized names for MultiFaceSeam and CloseSheets. Runtime authority used the accepted parameterized independent-oracle tests; M1g corrected the metadata.
- The temporary runtime workflow was removed before its trigger.

## [M1e] Segment Route Transport Consumer — Immutable accepted

### Changed

- Migrated `surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.
- Replaced legacy raw signed `transition.matching` accumulation across the ordered `std::vector<VertexPathStep>` with checked source-step identity, `TransitionStep`, `CanonicalRoute`, and typed `GridAutomorphism` composition.
- Production/test paths were `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`; no header or CMake change was required.
- Preserved route discovery, ordered vertex-fan choice, hard-feature/relief/topology checks, `resolve_branch_transition` behavior, matching effort, exact ordered raw provenance vectors, and the existing explicit `edgeTransitions`-absent legacy matching path.
- Decoded each step edge only at a compatibility boundary, established checked `SourceVertexId` plus canonical `SourceEdgeTopologyKey`, established checked `InteriorTransitionId` from existing `source_edge_provenance`, converted directed step matching to `QuarterTurn` / zero-shift `GridAutomorphism`, constructed a `CanonicalRoute` only after all steps validated, consumed `CanonicalRoute::oriented_steps()` to preserve observed route direction, and derived public/raw `current.matching` only at the compatibility output boundary.
- Deliberately excluded periodic-holonomy loop accumulation, `FieldChartId`, public schema retirement, topology/conformity/quotient work, validation, fallback/recovery, optimization, and G4 repair.

### Validation

- Implementation: `a0330d0107f7d7340e9f8644d26dd6c8b753ff10`.
- Build/event commit: `34036600128262e909c377006a056a2b9976f986`.
- Build run/job: `31351113129 / 93341993183`, **120/120**.
- Result artifact: `9049125645`, SHA-256 `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7`.
- Log artifact: `9049125905`, SHA-256 `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`.
- Recursive manifest: **61/61**, SHA-256 `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`.
- Package: **62** regular files, seven executables, two static libraries, 27 fixtures.
- Product/test blobs: `34372a48412213d3b4db6d0bc3e653e7d3225ef0 / f55d016db2c89710b79c711a0d5e780dcfb2bdfc`.
- Code + Build runtime: **false**.
- The production blob was byte-identical to the final reviewed production hunk at `bb9cb63`; tests were rewritten from scratch before `a0330d0`.
- Deterministic route witness: `2 -> 3 -> 10` through vertex `7`, with nonzero turns `3` and `2`, independent forward/reverse endpoint-label expectations `1/3`, independently enumerated compact IDs `2/9`, and sorted semantic route-keyed comparisons rather than positional pairing.
- Exactly six `SurfaceCellSegmentRouteTransportAuthorityMigration` production-path contracts passed **6/6** in fresh processes.
- Producer discovery **184**; required-green **169/169**; M1d/M1c/M1b preservation; validation **77/77**; M1a **14/14**; T1 **29/29**; all four direct products remained independent-oracle clean.

### Fixed

- The malformed contract was narrowed after Review: typed construction is unreachable as a distinct failure once derived topology/compact provenance validates, so the test targets the reachable `source_edge_provenance` predecessor and requires `MissingTransitionProvenance` without fallback. `CrossFieldEdgeTransition::sourceEdge` remains validation metadata, not semantic `InteriorTransitionId`.

### Known limitations

- Strict-validator 5% timing remained nondeterministic at **6/10 pass, 4/10 fail** and stayed deferred rather than becoming stable product evidence.

## [M1d] Authoritative Phase-Front Interior-Route Consumer — Immutable accepted

### Changed

- Migrated `pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid` for authoritative HardRail/PeriodicCut interior-route identity consumption only.
- At the accepted semantic boundary, packed route endpoints cross checked `SourceVertexId` adapters; canonical `SourceEdgeTopologyKey` owns semantic route-edge identity and uniqueness; packed keys are reconstructed only at compatibility lookups; supplied and authoritative compact route values cross checked `InteriorTransitionId` adapters and compare as typed IDs; malformed identity remains fail-closed through existing HardRail/PeriodicCut failure paths.
- Public `sourceRouteEdges/sourceRouteTopology`, route production/order, per-step transport, relation policy, diagnostics, and known-red dispositions remained unchanged.
- `RP-01` and `RP-05` were accepted at this consumer; M1c `RP-07` transport remained preserved.

### Validation

- Implementation: `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`.
- Build/event commit: `98a21f3d843533dcc44cb296711268e0ebb26fb6`.
- Build run/job: `31342400614 / 93318225812`.
- Result artifact: `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`.
- Log artifact: `9046308461`, SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`.
- Recursive manifest: **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`.
- Producer discovery exactly **178**; M1d focused **6/6**; route counterexamples **3/3**; M1c / transition counterexamples **6/6 / 3/3**; required-green producer **163/163**; M1b / validation **6/6 / 77/77**; M1a / T1 **14/14 / 29/29**.
- Direct product timings: Plane **1.325 s**, MultiFaceSeam **2.079 s**, CloseSheets **16.648 s**, Cylinder **9.267 s**; all remained independent-oracle clean.
- All nine historical/deferred producer reds retained their prior failure classes; no new regression or recurrence was created.
- Artifact-only Bunny/Vase comparison run: `31343763822`.
- Bunny job `93321764271`: exact one-test selection, rc=1 after **71.705 s**; independent oracle rejected first, followed by unchanged `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`. Evidence artifact `9046629209`, SHA-256 `6502efcdef8ed94051e571b81f8f9c7ae6c2e1d10d8e0b9804991a42a5cf65a3`.
- Vase job `93321764263`: exact one-test selection reached `[ RUN ]`, bounded rc=124 at **60.023 s**; safety-only evidence. Evidence artifact `9046626009`, SHA-256 `2a5ae0ae047f82ac909cf049aac03785863ee93d1506b10decb0c9507f5c4855`.
- Both heavy jobs downloaded exact artifact `9046308272`, verified the GitHub digest, build authority, all 59 checksums and producer hash before runtime, and reverified artifact/manifest/producer/60-regular-file authority postflight.

### Operational notes

- During M1d Test + Benchmark closeout, the temporary trigger marker was deleted before the temporary workflow, retriggering redundant Actions run `31343858635`. It is not acceptance authority and produced no product/regression state change.
- The durable cleanup rule established afterward is: remove or disable a temporary path-filtered workflow first, then delete its trigger marker/payload. This prevents cleanup itself from scheduling another run.

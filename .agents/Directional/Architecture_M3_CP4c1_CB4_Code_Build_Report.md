# M3-CP4c-1 CB4 Code + Build Report

- Phase: `M3-CP4c-1-CB4`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Starting semantic/test authority: `66a065b5e07910568a317e24f0fc6b93d890d104`
- Built evidence commit: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`
- Handoff/closeout commit: later documentation-only commit
- Remote synchronization verified: yes; the authoritative compile checked out the exact pushed evidence commit

## Implemented

CB4 implements the bounded test-side correction authorized by `Architecture_M3_CP4c1_TB_R4_Independent_Review_Record.md` measures **W0-W7**. Product code is unchanged.

- **W1:** removed the witness-level productivity precondition from C5. A valid witness with zero traces now satisfies the universally quantified per-trace contract vacuously and silently. The per-trace terminal-event assertions remain intact.
- **W2:** replaced the incorrect `producedTerminalKinds.size() == 2` cardinality assertion with `ASSERT_FALSE(producedTerminalKinds.empty())`, preserving the existing contributor/reachability diagnostic chain.
- **W3:** no runtime was executed in CB4. The successor TB-R5 plan explicitly requires the two named-kind checks to be reported individually and the observed terminal-kind union/contributor map to be published.
- **W4:** no optional subset assertion was added. The review did not establish a frozen allowed terminal-kind vocabulary independent of current observation, so inventing one from the current `{2,3,4}` result would reproduce the defect.
- **W5, mandatory — `FieldAlignedCurveNetwork.BranchBoundaryPairingContinuationIsUnique`: RETIRED.** The identity coupled a useful branch-boundary census/ambiguity question to the now-invalid premise that prescribed-sphere network construction must fail. The surviving accepted coverage is `FieldTransportAtlas.PublishesCanonicalBranchFramesAndBoundaryPairings`, `FieldTransportAtlas.IndependentOracleRejectsBranchPairingOrPortAttachmentTamper`, `FieldTransportAtlas.RejectsAmbiguousOrIncompleteBranchTopology`, plus the accepted candidate transport composition/binding identities. Retaining a failure-tied duplicate would invert accepted authority rather than add an independent invariant.
- **W5, mandatory — `FieldAlignedCurveNetwork.PrescribedSphereCandidateTraceTransportFailureSiteIsObservable`: RETIRED.** Its invariant was only the observability of an `InvalidCandidateTraceTransport` failure site while the sphere could not produce a network. That failure no longer exists in accepted authority. Positive surviving coverage is `TraceTerminationCorrection.PrescribedSpherePublishesTwentyFourTracesAndCorrectedContactEvents`, `ResolvedBranchCorrection.FieldAlignedCurveNetworkIsAClosedProducerOnEveryReachableWitness`, C5 itself, and the accepted candidate-trace transport checks. There is no valid current failure site left to localize.
- **W5b, optional:** the three `GlobalTopologyPlan.*StageReachabilityIsObservable` report-only publishers were left untouched. Migrating their historical unconditional-`FAIL()` publication idiom was not required for the bounded correction and would broaden the change without affecting gate semantics.

`M3-CP4c1-TB-R4-CAND-03` therefore has both mandatory CB4 dispositions recorded. Its final closure still requires the successor TB to confirm neither retired identity appears as an unexplained red.

## Engineering-Guideline Review

- Material assumptions surfaced: the review's normative C5 contract is a per-produced-trace property plus non-vacuous representation of the two named terminal kinds; it does not require every witness to produce a trace and does not freeze a terminal-kind cardinality.
- Simplest sufficient approach chosen: two C5 expectation/precondition edits plus retirement of the two inverted diagnostics and their now-unused helper/census support.
- Why no smaller approach satisfies the contract: W1 and W2 are independently required to remove both TB-R4 test-side failures; W5 is mandatory and explicitly forbids deferring either inverted diagnostic.
- Unrelated refactors/style drift avoided: yes.
- Every semantic changed line traces to W1, W2, W5, or removal made unused by W5: yes.

## Files Changed

Semantic/test authority only:

- `tests/FieldAlignedCurveNetworkTests.cpp` — W1/W2 correction of C5; retirement of the two W5 diagnostics and helper code used only by them.
- `.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt` — remove the two retired W5 identities; three report-only publishers remain.

Frozen product paths `src/` and `include/` are byte-unchanged by CB4.

## Domain Invariants

- Required selector remains **355 identities**, SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`.
- First 353 lines remain `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`.
- First 346 lines remain `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.
- First 316 lines remain `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`.
- C4/C5 remain ordinals **354/355**, gating, and neither is renamed, demoted, skipped, split, or moved to the non-gating selector.
- Non-gating selector is now **3 identities**, SHA-256 `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`.
- Stable regression accounting remains **42 events / 14 categories / 28 recurrences**, produced-witness debt **5**.
- M3 package count advances **56 -> 57** for the one successful immutable CB4 GMP package.
- CP4c-2/3 were not entered.
- No Directional runtime, test, benchmark, produced binary, discovery/list/help/version command, CLI, fuzzer, or custom input was executed during this turn.

## Generalization Review

- Why this is not fixture-specific: W1 removes an invalid productivity requirement for *all* witnesses and leaves the per-trace property universal; W2 changes a hard-coded cardinality into the independently justified non-vacuity property; neither recognizes the torus or sphere by name.
- Valid input classes affected: only test-oracle behavior for witnesses that legitimately produce zero traces or additional frozen terminal kinds. Product behavior is unaffected.
- Regression risks considered: accidental weakening of the per-trace contract, selector/order drift, accepted-prefix drift, C4/C5 demotion, replacement of `2` with another observed count, and retention of misleading permanently-red diagnostics. The frozen hashes and successor TB-R5 plan detect these.

## Build

- Exact built evidence source: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`.
- First compile-control run `33144909546`: **startup-only failure**, before any compile job or Directional runtime, because the caller's `contents: read` ceiling was below the current observer reusable's declared `contents: write` requirement.
- Control-plane correction only: caller permission raised to `contents: write`; a SchemaStore validation job was added as a prerequisite. No semantic/test source changed.
- Authoritative retry event SHA: `d33d19bc02edd40b1aa92deeb1bd17326816326b`.
- Authoritative workflow run: `33145657048`.
- Schema validation job: `98765978208` — PASS.
- Compile job: `98766007030` — PASS.
- Targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Configure: Release/static/PRE_TEST, out-of-tree, exact arithmetic backend GMP.
- GMP link evidence: `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` are present on the authoritative generated link command.
- Preflight/build exit codes: `0 / 0`.
- Internal package manifest: **28/28 PASS**.
- Packaged source archive SHA-256: `baead768e6f05acc7b09177a1571139262a514056cfc4fa281b8933135b6fc84`.
- Source-status snapshots: clean/empty.
- Compile result/package artifact: `9675666067` (`m3-cp4c1-cb4-compile-result-33145657048`), GitHub artifact/ZIP digest `sha256:63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`.
- Persistent compile log artifact: `9675666340`, digest `sha256:582791557b87d2be9ffcaf99fcca928a55b6aaf177de44654a235e05f58070c2`.
- Schema validation artifact: `9675637955`, digest `sha256:22a0dd4c3b2b8373519937ba897da7db1f4b62bb40d7055870d3b9a2e15b49a4`.
- `metadata/command-boundary.txt`: `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`.
- Tests or benchmarks executed: **none**.

Closeout transport note: first documentation-apply run `33146294107 / 98768001682` failed **before commit/push** because the preservation patch header encoded `intended_paths` with commas while the durable Drive reusable consumes a semicolon-separated list. Download/hash/base/body verification and workflow schema validation had already passed; no durable documentation changed and no runtime executed. The correction is header/transport-only: regenerate the same verified documentation diff with semicolon-separated `intended_paths`, refresh its full patch SHA-256, and perform one diagnosed retry.

## Known Risks

- The successor prediction has not been executed. Accepted runtime authority therefore remains CP4c-0b T5 **353/353** until TB-R5 proves the corrected C5 and C4 in the immutable 355 gate.
- The three remaining non-gating report publishers intentionally fail to print reports. They remain zero-credit diagnostics and are not evidence of a product regression by themselves.
- `M3-CP4c1-TB-R4-CAND-03` is not fully closed until TB-R5 confirms the two retired identities do not survive as unexplained reds.

## Mandatory Test + Benchmark Plan

- Plan reference: `.agents/Directional/Architecture_M3_CP4c1_CB4_Artifact_Only_Test_Benchmark_Plan.md`
- Evidence commit/artifact under test: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747 / 9675666067`
- Required gate: **355** identities, SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`.
- Non-gating selector: **3** identities, SHA-256 `537a8010033452a16be5f6a80926ea61c065f7f7f443b5b2950f73c8b8ffcd6a`.
- Acceptance: immutable preflight; 355/355 required green including accepted 353/353, C4 and C5; W3 named-kind checks individually proven; exact terminal-kind union/contributor map matches the review's falsifiable prediction; planned report-only diagnostics produce trustworthy evidence with zero gate credit; immutable postflight PASS.
- Stop/blocker conditions: artifact/source/hash mismatch; missing GMP runtime; zero-selected identity; package/source mutation; configure/compile/relink/repair attempt; or infrastructure failure that prevents trustworthy evidence. A semantic deviation from the review prediction routes back to independent review, not to another correction or deterministic retry.

## Next Turn

Type: Test + Benchmark

Exact next turn: **`M3-CP4c-1-TB-R5`**, immutable artifact-only. Do not enter CP4c-2/3 in this turn.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`
- Handoff commit: later documentation-only closeout commit
- Test plan linked: yes
- Updated: TODO, CHANGELOG, regression tracker, and live handoff
- Agent entry-point links verified: unchanged
- New lesson recorded: none; the review already captured the relevant anti-pattern and this turn did not establish a distinct new reusable lesson

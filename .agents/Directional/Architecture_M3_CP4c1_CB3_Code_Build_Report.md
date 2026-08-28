# M3-CP4c-1 CB3 Code + Build Report

- Phase: `M3-CP4c-1-CB3`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build
- Starting accepted branch authority: `4e3abd63ca00d1d01e9e2337f2186b7318e18963`
- Source-snapshot trigger commit: `b12fee5d962d64f3db7acb9c62a28f9b285fa8ab`
- Built evidence commit: `66a065b5e07910568a317e24f0fc6b93d890d104`
- Handoff/closeout commit: later documentation-only commit
- Remote synchronization verified: yes; the authoritative compile checked out the exact pushed evidence commit

## Implemented

CB3 performs only the post-CP4c-0b rebase that the handoff authorized.

- The CP4c-1 required selector is now the accepted CP4c-0b **353-line prefix, byte-for-byte and in the same order**, followed by the two checkpoint-local required identities C4 and C5.
- The cumulative required selector is therefore **355 identities**.
- Full selector SHA-256: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`.
- First 353 lines: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`.
- First 346 lines: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.
- First 316 lines: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`.
- Ordinal 354: `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`.
- Ordinal 355: `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`.
- Historical CP4c-1 non-gating selector remains **5 identities**, SHA-256 `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

No product implementation, unit-test body, fixture, accepted expectation, CP4c-0b selector, or non-gating selector was changed. Re-homed Q8 criterion 3 remains owned and accepted by CP4c-0b.

## Engineering-Guideline Review

- Material assumption: the accepted 353 and the historical CP4c-1 318 selector overlap in exactly the accepted 316 prefix plus older CP4c-0/0b authority, leaving only C4/C5 outside the accepted 353. This was verified by constructing and hashing the cumulative selector.
- Simplest sufficient approach: change one selector file only; no re-authoring of C4/C5 or product behavior.
- Why no smaller approach satisfies the contract: CP4c-1 cannot consume the old 318 selector after CP4c-0/0b acceptance because that would omit 37 already-accepted required identities. A cumulative selector is required to preserve accepted authority.
- Unrelated refactors/style drift avoided: yes.
- Every semantic changed line traces to the gate-rebase objective: yes.

## Files Changed

Semantic/test-gate authority:

- `.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt` — append the 37 accepted CP4c-0/0b identities needed to make the accepted 353 the ordered prefix before C4/C5; final length 355.

Control-plane-only files were created and retired to obtain the source snapshot, apply the selector patch, and run the compile-only reusable workflow. They are not semantic evidence.

## Domain Invariants

- Accepted CP4c-0b authority remains an exact ordered **353-line prefix**.
- Accepted CP4c-0 remains an exact ordered **346-line prefix**.
- Accepted CP4ab remains an exact ordered **316-line prefix**.
- C4/C5 remain gating and are not weakened, edited, skipped, or demoted.
- The five historical CP4c-1 diagnostics remain non-gating and grant zero acceptance credit.
- Q8 criteria 2/3 remain CP4c-0b authority; CP4c-1 does not reopen them.
- CP4c-2/3 were not entered.
- No Directional runtime, test, benchmark, produced binary, discovery command, CLI, fuzzer, or custom input was executed during this turn.

## Generalization Review

- This is not fixture-specific: the change is solely the cumulative gate definition after predecessor acceptance.
- Valid input classes affected: none in product behavior; only the acceptance set used by the next artifact-only TB.
- Regression risks considered: selector omission, selector reordering, accidental C4/C5 mutation, and loss of accepted-prefix provenance. The recorded prefix hashes detect each of these.

## Build

- Source snapshot: run `33138198414`, snapshot job `98742892909`; exact trigger/source authority `b12fee5d962d64f3db7acb9c62a28f9b285fa8ab`.
- Selector patch apply: run/job `33138991496 / 98745369305`; applied selector commit `a12a171e347d0c1c7cd88df604e907a603223d58`; result/log artifacts `9673159275 / 9673159457`, digests `sha256:eebdff60ef546db39dd93e7edc92b44b154cae441c278c0f9d4599b4739abffd / sha256:67a215b3f3b55f5ff668e68f38db462f77726e3e4ef61748059055d5448b7c92`.
- Exact built evidence source: `66a065b5e07910568a317e24f0fc6b93d890d104`.
- Authoritative compile run/job: `33139188595 / 98746005796` — PASS.
- Targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- Configure: Release/static/PRE_TEST, exact arithmetic backend GMP.
- GMP evidence: `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` are present in the link command.
- Preflight/build exit codes: `0 / 0`.
- Internal package manifest: **28/28** entries.
- Packaged source archive SHA-256: `3ba7e745a25dddbacd0e18b79672ebac5a8e94a944ed45c60174216f2770c628`.
- Source-status snapshots: clean/empty.
- Compile result/package artifact: `9673249952`, GitHub artifact digest `sha256:17a3f8da793fc20562e5ec2f0ab441d39f795dd146171e989fb952e6f942d2ea`.
- Persistent compile log artifact: `9673250286`, digest `sha256:cffa6fc4a72c0d60fa2199131cdd6073c7a8c7f15482a0e48af98cb3dadf32b9`.
- `runtimeExecution=false`.
- Tests or benchmarks executed: **none**.

A first compile caller run `33139114617` ended in `startup_failure` before a compile job could run because the caller's `contents: read` permission ceiling was below the reusable observer graph's declared requirement. Only the caller permission was corrected to `contents: write`; no semantic source changed. The corrected run above is authoritative.

## Known Risks

- The five non-gating diagnostic identities were authored before CP4c-0/0b closed and several deliberately emit diagnostic failure output. Their next-turn results are report-only and must not be converted into gate credit or used to weaken the 355 required selector.
- C4/C5 have never yet been observed green in the same immutable run as the accepted 353 prefix. That is exactly what the next TB must establish.
- Accepted runtime authority remains CP4c-0b T5 **353/353** until the next TB executes the new 355 gate.

## Mandatory Test + Benchmark Plan

- Plan reference: `.agents/Directional/Architecture_M3_CP4c1_CB3_Artifact_Only_Test_Benchmark_Plan.md`
- Evidence commit/artifact under test: `66a065b5e07910568a317e24f0fc6b93d890d104 / 9673249952`
- Required gate: 355 identities, selector SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- Non-gating diagnostics: 5 identities, selector SHA-256 `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`
- Acceptance: exact artifact preflight, 355/355 required green with accepted 353/353 prefix and C4/C5 both green, all planned diagnostics selected exactly once with zero gate credit, zero escaping C++ exceptions, and immutable postflight PASS.
- Stop/blocker conditions: artifact/source/hash mismatch; missing GMP runtime; zero-selected identity; package/source mutation; configure/compile/relink/repair attempt; or infrastructure failure that prevents a planned identity from producing a trustworthy result.

## Next Turn

Type: Test + Benchmark

Exact next turn: **`M3-CP4c-1-TB-R4`**, artifact-only. Do not enter CP4c-2/3 before CP4c-1 is adjudicated.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: `66a065b5e07910568a317e24f0fc6b93d890d104`
- Handoff commit: later documentation-only closeout commit
- Test plan linked: yes
- Updated: TODO, ROADMAP, consolidated CP4c record, CHANGELOG, and live handoff
- Agent entry-point links verified: unchanged
- New lesson recorded: none; no new reusable engineering lesson was established

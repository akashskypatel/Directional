# M6-CP3-CB1-ENTRY-R4 — RA-43.4 network-bound rail component first consumer (2026-10-14)

**Turn:** Same canonical `M6-CP3-CB1-ENTRY-R4`, Code + Build, **IN_PROGRESS**. PR #8 remains draft/unmerged. No successor or TB497.

## Exact authority

- Verified source snapshot: SHA `16f072b23a167351f039f8e29fe762c8a8756f26`; workflow [38527901524](https://github.com/akashskypatel/Directional/actions/runs/38527901524), immutable source ZIP `11876912141`, outer SHA-256 `d9e68913dbb918c64d54a766d0199578ead8f8b479b6dd889c37367fc90bab5f`, inner source.tar.gz SHA-256 `713ce555e788fcadd5306d2e82319a44f128ab23e499995df4035a8763095ed2`, **5858/5858** source checksums. Source comparison to this turn's entry head found only documentation and control changes.
- The exact two-file diff is preserved in the downloadable `Directional__M6-CP3-CB1-ENTRY-R4__base-16f072b23a16__work-preservation.patch`. SHA-256 `ca932f33dcbd05616dd744397a14bc9696e1b067b8509ad5e0e5e26e4b95b0cf`; diff-body SHA-256 `ee89bb874ea5f74e72ff1bddcdad25573b6423b24019ce66a890ec5a6a9284dd`; forward/reverse apply and whitespace checks passed.

## Specific correction

`src/geometry/SurfaceCellTracing.cpp::rail_interval_refs` previously required a real `FieldAlignedMandatoryEdge` to have the correct edge key, rail ID and kind but did not compare `SurfaceCellRail.component` to the mandatory edge's independently published `sourceComponent`. A rail retaining its exact source endpoints and keys could claim a different component at the first A2a consumer. The network-backed path now rejects negative or mismatched component values with its existing `TypedAuthorityMismatch` and interval locus. The standalone no-network diagnostic remains unchanged.

In the existing `SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` (`tests/SurfaceCellsPhase10Tests.cpp`), the positive produced rails remain intact and a negative now changes only the first rail's component to a different **real** source component. It invokes `LegacyStandaloneDiagnostic` with the genuine A2a network to prove that mode cannot bypass typed source-component ownership. It expects `TypedAuthorityMismatch` at interval zero with exact rail ID. No new test identity and no selector changes.

## Patch application and limits

- Staged to `My Drive/Directional-CI` with File ID `1Vu1fvSStg018cBTxSKHTVY00agCNiQqR`. Dispatcher request commit `b768090abe660208cd7dbb0fb5f5d0d3827d9bad`; mailbox `m6-cp3-r4-ra434-component-apply`.
- [Apply workflow 38534790657](https://github.com/akashskypatel/Directional/actions/runs/38534790657) success. Result artifact `11878774638`, independent outer ZIP SHA-256 `7a181f26aaab57370d89ebaed662b127afa396d596e524afe4dd028ab300b7ad`; exact `result.env` records `applied_commit_sha=f04eda9743e94e42cac9b19f6ada29ae7fde1a07`, `runtimeExecution=false`. Independent GitHub comparison between dispatch SHA and this applied commit proves **exactly** `src/geometry/SurfaceCellTracing.cpp` (4 changed lines) and `tests/SurfaceCellsPhase10Tests.cpp` (20 additions); no other changed paths.
- Workflow-side Drive deletion reported `owner-cleanup-required`; user-authorized Google Drive connector permanent `delete_file` then succeeded. Do **not** reapply or re-upload the consumed patch.

**Historical pre-compile note (now superseded by the verified checkpoint below):** the change had not been compiled as of the initial application. The older eight-target GMP/GMPXX compile [38526113617](https://github.com/akashskypatel/Directional/actions/runs/38526113617) remains valid **only** for earlier semantic source `d47b363682e449bb6525ec9fc4f6fd4d56c04d14`, not for `f04eda9`. No Directional binary, tests, CLI, benchmark, or TB497 executed in this response.

## R4 continuation obligations (after completed compile)

1. **COMPLETED:** Exact-source eight-target GMP/GMPXX compile, archive/manifest and no-runtime checks; all evidence is in the verified checkpoint below. Do not rerun unchanged source just to repeat successful compile evidence.
2. Keep the new negative as compiled-only until an independently authorized artifact-only Test + Benchmark turn. No TB497 in this R4 Code + Build.
3. Continue open RA-43.1 selected A4/A1 branch source attribution (independent Review), RA-43.4 broader consumer/test execution, RA-47.12 runtime liveness, original 39 endpoint / 34 Phase10 / seven DCEL / 88 CP2 / six CP3 and organic D1/D2/D3/D5/A6/A7. Frozen selector 497, historical accepted counts and PR state remain unchanged.

## Exact-source compile and immutable package verification — 2026-10-14 08:38 UTC

The post-patch source was compiled, **not executed**, through the durable compile dispatcher request `748b83492286f33157a3c34c90451b11fb933e5b`, pinned to semantic commit `f04eda9743e94e42cac9b19f6ada29ae7fde1a07`. [Workflow 38536008896](https://github.com/akashskypatel/Directional/actions/runs/38536008896) published matching `m6-cp3-r4-ra434-component-compile` mailbox, successful compile job `115759070843`, successful mailbox job `115760042096`, and skipped Test + Benchmark / Drive apply jobs. The immutable result ZIP is artifact `11879114903`, **SHA-256 `672efa0e70715eb9fdfd6085efa8e010c0870792dcb674a4c8eb52113bf175a8`**, expiring 2026-10-21; diagnostic log artifact `11879184776`, SHA-256 `9d33e461324a52ac2e89a11904312bf80d0b1c3b23e0ede29ee2bbfa5d1d9447`.

**Independent package verification:** all **28/28** manifest hashes pass; eight intended targets enumerated; source-commit file equals `f04eda9743e94e42cac9b19f6ada29ae7fde1a07`, preflight/build exits **0/0**, all **five** source-status files empty. `DIRECTIONAL_ENABLE_GMP=ON`, GMP CMake discovery present, and authoritative generated `directional_surface_cell_authority_kernel_tests` link command includes both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`. Boundary file records `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`. The packaged source tar was inspected for both the exact new network component comparison and the real-component negative regression; both are present. No Directional binary was invoked. **Do not credit the negative as runtime passed** and do not begin TB497 in R4.

**Remaining R4:** broader RA-43.1 selected A4-to-A1 source-branch attribution requires independent source-domain Review, source-consumer coverage, the historic acceptance recoveries, and artifact-only runtime once separately authorized. The frozen selector and accepted ledger are unchanged. Same canonical turn continues, no successor.

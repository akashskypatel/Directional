# Endpoint chart diagnostic — Code + Build record

**Current turn:** `M6-CP3-CB4-R4-ENDPOINT-CHART-PROBE`. Scope is a diagnostic-only extension after A4 route endpoint rejection, followed by exact-source eight-target GMP/GMPXX compilation. No runtime, benchmarks, selector edits, acceptance/predicate changes, or RP-01 repair are authorized.

## Source authority and rationale

- Frozen trigger/source commit `4c114b24811140a8b74e05570ae3e17e4f7e5197`; snapshot workflow [38775481890](https://github.com/akashskypatel/Directional/actions/runs/38775481890), snapshot artifact `11993616345`, outer SHA-256 `ac9694617c3ee648d703502f2dd0436961dd4d97c07d1f340b3d7afc7144bf5e`, source.tar.gz SHA-256 `4456493499d8913f8cd18281bc984f3d883df62b5e60f36746ee855a68ed5151`, 5642 source files (file count, not a checksum-verification ratio). Source manifest verified locally separately.
- Binding decision: `Architecture_M6_CP3_R4_Endpoint_Authority_Spec_Review_Decision.md` RA-65.3 and RA-65.11. The claimed endpoint face pair `{0,7}` was **not measured**; RA-64.6 was withdrawn. A concrete measurement of actual endpoint charts and A3 carrier face keys is required before any mechanism is inferred.
- In `src/geometry/SurfaceCellTracing.cpp`, after `endpoint_certificate` already rejects, extend `endpointEvidence` to emit `a2bProbeFromFace`, `a2bProbeToFace`, `a2bProbeFromAttachment`, `a2bProbeToAttachment`, `a2bProbeCarrierFirstFace`, and `a2bProbeCarrierSecondFace`. The latter four are canonical source-face vertex triples, not guessed row IDs; a key is absent when the corresponding source face or carrier is absent. This distinguishes the precise face charts and carrier-side eligibility without admitting a rejected route.
- The change is deliberately inside the existing `if (!firstEndpoint || !secondEndpoint)` path. It never changes `endpoint_certificate`, the first-rejection ladder, any branch selection, emitted topology, or validators. No test/benchmark executable is run in this Code + Build turn.

## Acceptance and continuation boundary

The existing probe parser and pinned 44-case artifact-only harness remain unchanged; that harness explicitly pins an old immutable package and must **not** be run against it to claim these new fields. A separately authorized Test + Benchmark turn must consume the new verified immutable GMP compile package, select an exact appropriate diagnostic harness, and report the actual face rows and face-key triples for the 21 previously `carrier-orientation` cases and controls. Only independent Review may judge same-sector versus cross-feature chart selection, acceptance, or repairs. No generic star-route gate is authorized: RA-65.5 suspended it because no producer publishes that witness. Ledger 66/17/49, debt 1; accepted CP2 491/491; rejected R3 403/497 and frozen selector 497 unchanged.

## Remote application and compilation

Pending verified patch application and exact-semantic-source eight-target GMP/GMPXX compile at authoring time. Do not claim compile GREEN or runtime evidence until immutable receipts and hashes have been verified.

## Applied source, compile request and transfer exception

- Local backup patch full SHA-256 `bbe79752d37f173a0e34b4343400ef262c16868e31e8c9a99c8b11206af37da4`; diff-body SHA-256 `541c1c630690b6f89d022682f1abd6635a8b0e3594f78ed398df71d6d7625c97`; forward/reverse application and `git diff --check` verified against exact source. Immutable extracted snapshot verified 5642/5642 manifest hashes when using unchanged snapshot bytes for the three locally edited paths.
- Standard Drive staging failed twice with `container_session_unavailable` (the file service could not read the active container file). Instead of leaving changes only locally, the authorized GitHub Git-object API created one four-file tree/commit atomically: semantic commit `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`, parent `4c114b24811140a8b74e05570ae3e17e4f7e5197`; all four new blob hashes exactly match the local prepared patch. Branch ref update succeeded without force. The exact patch is preserved as a downloadable recovery artifact; it was **not** uploaded to Drive.
- Compile-only dispatcher request commit `243a9feb7f982a2dfe5e1fb5a32a8a9ecc36fa84`, exact semantic source `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`, mailbox key `m6-cp3-cb4-r4-endpoint-chart-compile`, standard eight targets. At this record update, no terminal compile receipt has been verified. **Compilation pending**, no claims of GREEN, no binary execution, tests or benchmarks.

## Final exact-source compilation result (supersedes pending notation)

- Compile dispatcher request commit `243a9feb7f982a2dfe5e1fb5a32a8a9ecc36fa84`, semantic source `5be5e123e14e2ddab8bb8c0db2a354a0a900435a`.
- [Compile workflow 38776964197](https://github.com/akashskypatel/Directional/actions/runs/38776964197) succeeded. Mailbox confirms the exact event and semantic source, and the compile job succeeded; Test + Benchmark and Drive apply jobs were skipped.
- Immutable result artifact `11994726341`, outer ZIP SHA-256 `b59dc16f4417693c4aec79025160da2054cfbca3a1589ef051ee3a171d3185bb`. Independently verified all **28/28** packaged manifest checksums, the exact source-commit identity, and all **eight** required compile targets; preflight/build exit codes **0/0**.
- Generated linker evidence includes `libgmpxx.so` and `libgmp.so`. Package records `exactArithmeticBackend=GMP`, `runtimeExecution=false`, and five empty recorded source-status files. **Compile GREEN only; no Directional binary, tests, benchmark, or frozen 497 selector executed.**
- The current Code + Build diagnostic checkpoint is complete. Next artifact-only probe execution and independent Review require **separate authorization**; there is no authorized named successor at closeout. The source-chart values remain **unmeasured at runtime**. Stable ledger/selector untouched, PR #8 open draft.

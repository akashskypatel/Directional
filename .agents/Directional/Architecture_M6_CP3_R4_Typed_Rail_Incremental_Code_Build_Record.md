# M6-CP3-CB1-ENTRY-R4 — typed rail source-incidence incremental Code + Build

**Disposition: IN_PROGRESS; bounded source-authority improvement, NOT R4 completion.** Same turn `M6-CP3-CB1-ENTRY-R4`; no Test + Benchmark, no selector changes, no successor promotion. PR #8 remains open/draft/unmerged.

## Source and source-exact changes

- Source snapshot: `7230d9fb486a6f2b6a6e651bfba8ae35e294661c`; run `38076279092`, artifact `11679120767`, ZIP SHA256 `6e7da58f6b0e5bf47475297269a08d1d2d9f963139020f9653e84842e15aa6b9`, 5914/5914 manifest valid, `runtimeExecution=false`.
- Two edited paths: `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellTracingPhase14Tests.cpp`. `rail_interval_refs` verifies published ordered `rail.sourceVertices` count and each endpoint's typed `SourceVertexId`, `SourceEdgeTopologyKey`, and exact source-face corner representation. It uses the published typed endpoints as identity, disallowing a tolerance-close barycentric perturbation from declaring a different source vertex. The `FieldAlignedCurveNetwork` path rejects rails with missing typed source-vertex authority.
- Compile-visible regression `SurfaceCellTracingPhase14.ProducedRailEndpointsRequireExactSourceVertexIncidence` includes valid typed incidence, wrong source-edge identity and tolerance-close nonvertex perturbation. It **has not been executed**.
- `git diff --check`, exact-base `git apply --cached --check`, reverse check passed. Exact patch SHA256 `ad811b02bf55daa031cd91fc22534b99b48c96a04dc8f4e264698f770b3a1e4b`; diff-body SHA256 `64e3b8e10a0c881a9e412f801008749af4a69e89fafc85c043d1f5613016de00`. Downloadable chat backup is `Directional_M6_CP3_R4_Typed_Rail_Source_Incidence_WIP.patch`.
- Drive patch applied successfully: dispatcher run `38076758215`, workload job `114285314880`, artifact `11679251530` outer ZIP SHA256 `6059828753896afe18028e468d07fbafc71dd36216a4ae018155c5eb4287fec8`; exact semantic applied commit **`27a324c4f25c2f75d63b1f96d988cb3e4ad3474c`**, `runtimeExecution=false`. Exact staged Drive file `1JMPW_TnvlDCioI3V9_GQXeIIkutyKR9G` was permanently deleted by the owner connector after successful push.

## Compile/package evidence

- Eight-target standard GMP/GMPXX compile request source: `27a324c4f25c2f75d63b1f96d988cb3e4ad3474c`.
- Dispatcher request commit `8930ed495859d44b6b88255206934531829bf12d`, mailbox key `m6-cp3-r4-typed-rail-compile`.
- **Verified GREEN**: run `38077156162`, compile job `114286472537` success, result artifact `11679541934` ZIP SHA256 `363408f90420edcd7355dd5b6029d79002b698e8e6be1bda6e7f751b76ef7879`, dedicated log artifact `11679551811` SHA256 `37de6e630af7fcbf9679cbe304c3abc9d505fd24a5eda3adde2eccf70bfb3593`. Manifest **28/28 SHA256 passed**; preflight/build exit codes 0; 8 requested targets packaged, 5 source-status receipts clean; linked GMPXX and GMP; `exactArithmeticBackend=GMP`; `runtimeExecution=false`. **No Directional runtime/test/benchmark execution.**

## Unfinished requirements and exclusions

This patch is deliberately not a claim that `rail_sample_source_vertex` is fully retired. Legacy direct hand-authored rails with empty `sourceVertices` still take the historical epsilon inference; fixture migration and removal of that path remain necessary. The independently producer-authored A2b terminal source-star germ, A3 sector φ witnesses, reciprocal side contacts, multi-carrier/odd τ and all 88 CP2 accepted-green restorations remain unproven. Frozen RA-41 multi-carrier is UNEXERCISED. RA-45 relational gauge pin from the prior compiled incremental commit remains authoritative (no absolute geometric gauge pin, no normalization). Tests remain compile-only.

Frozen baseline: CP2 accepted `491/491`, R3 rejected `403/497`, `94` RED / `88` CP2 losses; stable ledger `66/17/49`, debt `1`. No claims of new runtime acceptance. No PR metadata, reusable workflow permissions, build/test boundary, product fallback, recovery, or selector was modified.

### Diagnosed compile-only correction

- First compile request event `8930ed495859d44b6b88255206934531829bf12d`, run `38076875551`, compile job `114285657241` **FAILED** during source compilation, before any target execution. Failure log artifact `11679451485` SHA256 `48912a40264f0edc4e6ce840e6623953ddeec5d71f704f3717b5668529751efc`; `runtimeExecution=false`.
- Specific diagnosis: `DomainResult<SourceVertexId>` is not pointer-like. `first->index()` and `second->index()` caused C++ compile errors at `SurfaceCellTracing.cpp:5989-5990`. No more speculative changes.
- Minimal correction: exactly two replacements with `first.value().index()` and `second.value().index()`; patch SHA256 `0d21ed621d509901a9e595d539ef2e93f89c58d244e46860e39b9d324d3fd36a`, diff-body SHA256 `00a560ab24c8a57c8432f53439e2987734c857c259c54d8d4f288448b98880bf`, exact base `27a324c4f25c2f75d63b1f96d988cb3e4ad3474c`; `git diff --check`, exact-base forward/reverse application checks passed.
- Drive staging ID `1xizDKVubli3iopivXajrCMzDEvWJEl73`, dispatcher correction trigger commit `c033f8e8868f0bd77678dbc7f1c64234d5fe63eb`, mailbox `m6-cp3-r4-typed-rail-fix-apply`. Correction apply and second compile evidence are **PENDING**; do not claim compiler success yet.
- Correction apply **GREEN**: dispatcher `38077056529`, workload `114286189396`, result artifact `11679227099`, ZIP sha256 `13f166ca6ebe75fe784f3ef6639e902c2f0ac2b77790d66c7c8c3319ec1211e1`. Applied semantic source **`aab8e22c1a997ffcca72cc42a13df51bf0e4d29b`**; `runtimeExecution=false`. Staged correction Drive file permanently deleted by owner after verification.
- Recompile source frozen `aab8e22c1a997ffcca72cc42a13df51bf0e4d29b`, dispatcher request event `1a6f90a0d9ed9e22dab4eb79b457fd932fd349d6`, mailbox key `m6-cp3-r4-typed-rail-recompile`. Run `38077156162` is compile/package GREEN (details above).

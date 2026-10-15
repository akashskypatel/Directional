# R4 open-hard-rail interior endpoint witness repair — compile checkpoint

**Canonical turn:** `M6-CP3-CB1-R4-WITNESS-REPAIR` remains IN_PROGRESS pending immutable compile evidence. This is a Code + Build turn; tests, test binaries, benchmarks, artifact-only harnesses, and the frozen 497 are not authorized.

## Source authority and implementation

- Review authority: RA-59.9 in `.agents/Directional/Architecture_M6_CP3_R4_Carrier_Review_Decision.md`; the required front-publisher falsifier was checked against the exact source before editing, as recorded in the continuation artifact.
- Verified frozen source: `d5a974e2cd3b799ee7e87327b7e7b49c56837f4a`, source snapshot run `38715859592`, artifact `11962038665` (all 5628 source hashes verified).
- Atomic non-forced GitHub source commit: `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`, exactly `src/geometry/SurfaceCellTracing.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. Full blob SHAs `d15b85af6a332d6e4dd15c0ec1015d790f22d299` and `7da6c6e1b1af0ac279639a7ddb3c487ab0edcbaf` independently matched after connector blob creation. Compared frozen source to last parent: only `STATUS` and snapshot-trigger lifecycle paths had changed, not these target files.
- Implementation adds a source-edge exact rational interior parameter from source-face barycentrics and validates equivalent coordinates on both paired across-rail faces, retaining required whole-rail terminal authority, exact terminal corner checks, A3 carrier publication/transport and unchanged closed-chain route handling. Focused source-authored regression requires a real half-terminal producer certificate and rejects forged whole-rail terminal identity. **No runtime outcome has been observed.**
- The previous preservation patch, SHA-256 `6c9ee4890934f5d730c694afaa735b84c89c8b6bdffc57083c933844b4af5c95`, exists in downloadable chat and Library. Corrected metadata-wrapped patch SHA-256 `d07255da873817dbffd137bb07cadaa6884aeae2e29c4636ee9993dd98194fc4` is in the Directional Library and passed exact clean-source `git apply --check`. Original unheaded patch was separately staged as Drive ID `1Rf3XRDmCNtJyYJ9E_UAHRr2RS-pBr72d`; **do not dispatch it for drive_apply**. The Google Drive connector rejected direct transfer of the corrected Library file, and Google Docs export mutated its bytes. As a bounded fallback, the two exact source blobs were committed atomically via GitHub Git objects. This deviation must not be normalized as the default transport.

## Exact compile request (pending verification)

- Durable dispatcher request commit `b198ea5c79d8075ac8976ebb8c5cdbdcfd1982c0`; `source_sha=570c51733761c17a198bda6c9aba7d8b1e7ae2dd`.
- Workflow `38720128740`, mailbox key `m6-cp3-r4-witness-repair-compile` (read only from `workflow-mailbox`). Schema checks and dispatcher parsing passed; eight-target compile job started.
- Eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.
- **Pending:** immutable artifact and log, source SHA, packaged manifest checksums, GMP enabled, real gmpxx/gmp linker evidence, clean status and `runtimeExecution=false`. No compile GREEN may be claimed before checking them. Do not duplicate an active run.

## Carried obligations

RA-59's remaining obligations are unchanged: RP-02 consumer acceptance witness, ordinal 405 distinct A2b, RA-41 junction/sector, the frozen 497, six CP3 and historical gates, ledger 66/17/49 debt 1, CP2 491/491, R3 403/497. PR #8 remains open/draft. Update the canonical handoff, TODO, root CHANGELOG and final STATUS once compile evidence is available. No successor work begins inside this turn.

## Immutable compile verification and closeout (2026-10-15)

Compile **GREEN**: run [38720128740](https://github.com/akashskypatel/Directional/actions/runs/38720128740), exact semantic `570c51733761c17a198bda6c9aba7d8b1e7ae2dd`. Result artifact `11964478813`, outer SHA-256 `0e1e87a48ef090588c8675bd87bc8c7560a1ade5dbe44cac391c78e0cbe21ae5`; log artifact `11964676618`, outer SHA-256 `2d44c022651e95550d6cfaabd5fda9d2f050312477a464edcfd2c97cf9b7c451`. Independently checked **28/28** packaged SHA256SUMS, eight target names/artifacts, preflight/build exits `0/0`, `DIRECTIONAL_ENABLE_GMP:BOOL=ON`, generated real gmpxx/gmp linker, five empty status records, `exactArithmeticBackend=GMP`, and `runtimeExecution=false`. No test binaries, benchmarks, 497, or artifact-only harness ran. The historical pending status above is superseded by this verified evidence; source acceptance remains **compile-only**. Next separately authorized supplemental TB/Review has no exact frozen turn ID; do not invent a successor or execute TB inside this turn. Ledger and all RP-02/ordinal 405/RA-41 obligations unchanged.

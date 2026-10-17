# M6-CP3-CB1-ENTRY-R4 — RA-45 A6 incremental Code + Build record (2026-10-10)

**Disposition: IN_PROGRESS / incremental compile GREEN / no runtime execution / R4 NOT complete.** Current turn remains `M6-CP3-CB1-ENTRY-R4`. PR #8 remains draft/unmerged. This is an intermediate receipt, not authorization for `M6-CP3-TB1-ENTRY-R4-EXEC`.

## Authority

The independent `Architecture_M6_CP3_R4_Gauge_Consumption_Review_Decision.md` freezes RA-45: RA-44.2 absolute geometric gauge authentication was withdrawn as a category error. An A3 relational consistency check and mandatory gauge presence remain; uniform per-face +1 in Z4 is a valid gauge transformation and must leave A6 relation decisions unchanged. The checked factory validates but never normalizes the input (provenance digest depends on it). Source-star terminal germ, RA-43.4, multi-carrier and 88 CP2 restorations remain open.

## Change and immutable evidence

- Source snapshot SHA `0dcd853761e869584f92de8eaa676b6afd39058a`; run `38074610530`, artifact `11677608471`, 5907/5907 SHA256 verified.
- Exact patch `5e1da300a24c2ff6fe81113c7c7bf91728f7cfd9d9e3ad754bd4d766bc5cb133`; diff-body `8cf7e8626f32b32e2571967e4fe51304ce92b9c20697f9138d96c27ea43a0256`, exact-base `git apply --cached --check` and `git diff --check` passed. Backup in ChatGPT Library `/Directional/Evidence/Directional_M6_CP3_R4_RA45_Gauge_A6_CompileOnly_WIP.patch`.
- Applied semantic source **`49c81c5e697f4b5a256dc6d3c928954434e5ae03`**, approved Drive patch run `38075182382`, result artifact `11677504132`; staged Drive object deleted by owner after success.
- Three files changed: (1) a new `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome` compile-visible test, (2) corrected RA45 source comment in `src/geometry/SurfaceCellTracing.cpp`, (3) revised stale R4 Code + Build plan entry status.
- **Eight-target GMP/GMPXX compile GREEN**: dispatcher event `d1a01a8b728306e5f7cb7d1f6c8c2706691d1fa2`, run `38075310350`, compile job `114281004190` success, result/package artifact **`11678348920`**, ZIP SHA-256 **`8797b4df76b43dbba97d8913420d881057eb4b4442471c528a4b0d72a1b8e083`**, log artifact `11678184016` SHA-256 `5c8bfe3c639645da017a7320295b80ae18ba8d456085bab68821eba42afb72d4`.
- Package independently verified: **28/28** `SHA256SUMS`; root manifest SHA-256 `3d08fba83529b699220509373e98c01fcfb321e88f83c468a2f982182817aa71`; embedded source SHA exact; preflight/build exits 0; five source-status receipts empty; all required compiled executables packaged; `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx.so` and `libgmp.so` in authoritative link command; `exactArithmeticBackend=GMP`; `runtimeExecution=false`, `turnBoundary=Code+Build-only`. **No binary/test/benchmark was executed.**
- User-recoverable continuation: ChatGPT Library `/Directional/Evidence/Directional_M6_CP3_R4_Continuation_20261010.md` (local initial backup; append the compile evidence above before next turn).

## Remaining same-turn requirements

1. Authenticated A2b source-star **terminal** contact path/germ from exact rail source vertices to front endpoints; no epsilon-based source-vertex recovery. Preserve source-sheet, A3 transport, reciprocal and singleton vs multi-carrier distinctions.
2. RA-43.4 `rail_sample_source_vertex` replacement and fixture migration, including all seven original synthetic oracles and source-row permutations.
3. Generated gauge source coverage and error precedence, all 34 Phase10 positives, 39 endpoint cases, 14 others, produced odd-τ/multi-carrier/D5 controls with non-vacuous preconditions.
4. Complete remaining producer/fixture tasks and repeat compile-only gate; **do not** start TB497 or promote R4 merely because this incremental compile was GREEN. Accepted CP2 491/491 and rejected R3 403/497 are unchanged; 94 RED, 88 CP2 losses, stable ledger 66/17/49 debt 1.
5. The initial mandatory snapshot-mode pre-read gate was selected late, after some direct repository guidance reads. The complete snapshot was then verified before further source inspection; future turns must select `READ_MODE=snapshot` *before* source reads.

No PR metadata, workflow YAML permissions, selector or validator was altered. Temp snapshot trigger retired. Preserve turn identity in the next session.

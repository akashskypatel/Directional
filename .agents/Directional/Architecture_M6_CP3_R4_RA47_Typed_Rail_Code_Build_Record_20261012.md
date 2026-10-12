# M6-CP3-CB1-ENTRY-R4 — RA-47 typed rail source-edge implementation WIP (2026-10-12)

**Boundary:** continuing Code + Build. This record describes source-only implementation; no test or benchmark was executed. Direct TB497 is forbidden until its own authorized turn.

## Exact source and work

Verified source snapshot `1bcc068cb3be7d994caa537307e61c5aabe2e646`, workflow `38270791118`, artifact `11756652418`, ZIP SHA-256 `b9d1b75358bd2a7d74c87d3cb3429982e6d61179efbf646586d268cf74312f5b`, 6,464 file checksums verified. PR #8 is draft; working branch `agent/surface_cell_quad/p5-recover-bridge-healing`.

RA-47 code changes (pending GitHub compile at time of patch preparation):

- `SurfaceCellRail::sourceEdges` is typed `SourceEdgeTopologyKey` rather than raw indices; authoritative producer uses validated interval endpoint pairs.
- Feature-map ordinals remain independent for `coveredEdges`, `failedEdgeIndex`, and producer-local diagnostic bookkeeping.
- Network consumer compares the typed key against the independently re-derived source-vertex-chain interval and retains `InvalidRailGeometry` first rejection.
- Rail hash uses typed edge endpoint IDs. Component aggregation regenerates global typed keys after vertex remapping and removes local/global EV-index conversion maps.
- Existing tests adopt typed keys; the one-triangle `(0,2)` rail producer regression explicitly distinguishes feature-map position 1 from DCEL EV position 2. Foreign and closing-key negatives remain.

## Outstanding before closing R4

Exact-source eight-target GMP/GMPXX compile and artifact evidence required before calling RA-47 compile-green; no binary tests/benchmarks run in this turn. A standalone source-level liveness question remains whether the field-aligned consumer is reached with producer-built rails on the default path (RA-47.12); it has not been proved here. Other R4 obligations include RA-48.3 closing TriMesh::set_mesh precomputed-EV injection validation, RA-48.5/RA-46.6 typed factory error details, RA-43.1/.2/.4, RA-46.5, and exact first-rejection coverage. Overfull-three-face A3 remains mathematically retired only under RA-48 guards, not runtime-passed. CP2 491/491 accepted, R3 403/497 rejected (94 RED / 88 losses), stable ledger 66/17/49, debt 1; no new runtime credit.

No successor is begun. `M6-CP3-CB1-ENTRY-R4` remains the canonical turn.

## Verified Drive patch application and continuation (2026-10-12)

- Patch SHA-256 `253870ff22192a4a0480427f5edf7746596cb196953f18512ad6fe949f0f15a2` was staged in `My Drive/Directional-CI` and applied by durable dispatcher run `38272156459`, apply job `114888926077`, at exact base `1bcc068cb3be7d994caa537307e61c5aabe2e646`.
- Semantic code/document commit `63891bbcce1c6daf5875c19221c3aa5245324f59` was independently fetched and its **12 changed paths** verified against patch intent. Apply-result artifact `11756927884`, outer ZIP SHA-256 `00b187861239fa26c7cbe9deadb27cdf49e610a7418d9bca4f3a35b4995e54f9`, recorded `job_status=success`, `runtimeExecution=false`. All dispatcher/schema/patch/mailbox jobs green. Owner-side permanent deletion of staging Drive ID `15o9hxztHH4TIZ_J9dhY4XX83KRFHgYTM` succeeded.
- This is **source apply success only, not compile-green**. Timer closeout began before a new compile could be launched. The next action in the **same** `M6-CP3-CB1-ENTRY-R4` Code + Build turn is to dispatch the existing exact-source eight-target GMP/GMPXX compile workflow pinned to semantic commit `63891bbcce1c6daf5875c19221c3aa5245324f59`. Collect exact-source artifact/checksum/link evidence; execute no tests/benchmarks. Preserve and investigate any compilation failures without inventing a successor.
- Static default-path call-site inspection shows `RemeshPipeline.cpp` builds rails at `12229` and calls `FieldAlignedCurveNetwork::make` with those rails at `12575`; whether real inputs reach that call and whether the former wrong-index predicate rejects is unproven without runtime evidence (RA-47.12 remains open). RA-48.3 and RA-46.6 still require implementation; no TB497 authorization.

## R4 RA-48.3 source-edge table injection guard (2026-10-12 continuation)

Source-only follow-up prepared from the exact `ac42e72db5bc838e32c466ceba3b82731fac9f4f` snapshot (run `38273545492`, 6,469/6,469 checksums verified). `TriMesh::set_mesh` now always runs `compute_edge_quantities()` and the DCEL consistency check, then rejects supplied optional EV/FE/EF tables unless **all three** exactly match the face-derived canonical matrices. It rejects partial or forged injections and prevents a fabricated two-column edge cache from bypassing the nonmanifold DCEL gate. Existing two-argument callers retain the same checked derivation; optional six-argument callers remain supported only with validated tables. The A1 atlas comment states the now-explicit set_mesh trust precondition instead of implying atlas construction is the only validator.

The existing authority-kernel test source `FieldTransportAtlasTests.cpp` adds one focused named regression: valid exact injection succeeds; independently forged EV, FE and EF tables each throw; a three-face overfull edge with injected tables still throws. The frozen A4 overfull-incidence guard remains untouched, and RA-48's conditional theoretical retirement is **not** presented as an exercised runtime branch.

Evidence boundary: exact-source eight-target RA-47 GMP/GMPXX compile dispatched by request commit `bd97502b1c140094fa3ea74586a17ccb992200b1` pinned to `63891bbcce1c6daf5875c19221c3aa5245324f59`, mailbox `m6-cp3-r4-ra47-typed-rail-compile`. RA-48.3 source patch compile is **pending**; no local build, binary test, benchmark, or TB497 executed. RA-46.6 typed factory sub-codes and remaining R4 predicates remain open; same `M6-CP3-CB1-ENTRY-R4`.

## Verified continuation closeout (2026-10-12 16:09Z)

**RA-47 exact-source compile GREEN:** dispatcher request commit `bd97502b1c140094fa3ea74586a17ccb992200b1`, workflow [38273807454](https://github.com/akashskypatel/Directional/actions/runs/38273807454), compile job `114894427336`, exact source `63891bbcce1c6daf5875c19221c3aa5245324f59`. Result artifact `11759120300`, outer ZIP SHA-256 `60ccb92913a2ec2b3b3de5687ffbd441a4b6922bf95f2b337e399c8679e0eb8d`; **28/28** package SHA256SUMS verified, preflight/build `0/0`, all eight targets present, generated linker contains both `libgmpxx.so` and `libgmp.so`, final source worktree clean, `exactArithmeticBackend=GMP`, `runtimeExecution=false`. No binary tests or TB497.

**RA-48.3 source applied, compile PENDING:** five-file patch (SHA-256 `d7fdae20d22505029ab727c4e297c44b117e2b1e6d4f01b953605e688aa3dbca`) applied at semantic commit `785dd73981683635e00142e6a5df2bf551875d47` through retry workflow [38275124286](https://github.com/akashskypatel/Directional/actions/runs/38275124286), result `11758338434` outer ZIP SHA-256 `bf532dcabb99dcbd842eb6b5bf208337cc9a652d05d9fcaafd0d856c52d06d86`. An initial run `38274573609` failed at Git push due to a concurrent mailbox non-fast-forward, not a patch integrity failure; retry succeeded without force. GitHub semantic commit independently verified to touch exactly the intended five files. Staged Drive File ID `1LPv0nX1jRbLpeu3OmU8tfrtjXFRGwAjh` permanently deleted successfully after commit/evidence verification; durable patch backup remains in the user's Directional Library.

**Resume same turn:** dispatch mandatory eight-target GMP/GMPXX compile pinned to `785dd73981683635e00142e6a5df2bf551875d47`, verify immutable artifact/checksums, then continue RA-46.6 typed A4 factory subcodes, RA-43/RA-46 and carried first-rejection obligations. No new Test + Benchmark turn or TB497 is authorized. R4 remains IN_PROGRESS, successor same turn.

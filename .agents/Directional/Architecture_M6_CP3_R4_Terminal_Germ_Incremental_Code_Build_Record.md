# M6-CP3-CB1-ENTRY-R4 — produced terminal A2b source-star germ (incremental)

**Disposition: R4 IN_PROGRESS / not an acceptance or TB authorization.** Source exact commit
`991f655199017375d0ad7ae3fc0b235ffa3de4f0`, applied through dispatcher run
`38079857890`, job `114294418457` GREEN, result artifact `11678989914`, digest
`c6839dbf014cc5af06bf00946a8b92a18e5b71897bccf40c1f66efb0e487d3d2`.
The user-visible exact-base patch `Directional_M6_CP3_R4_A2b_Terminal_Germ_WIP.patch`
was verified with `git apply --cached --check` and `git diff --check`, based on
`60b1dd439380a464159d98afdd7b32ddaf19e2c7` (snapshot workflow
`38079370341`, artifact `11680035872`, all 5935 source file hashes valid).
Patch full SHA256: `eff99246d0f56b1a220f9ee45db43b80388e761f64f6831f4eacf2ff6a313d1b`.
Google Drive staged File ID `1iPVLVepkDxIG_xgt4Dld0KSE_P3msJG6` permanently deleted
by owner after successful apply. No test, benchmark, or generated Directional binary executed.

## Implementation scope

1. `SurfaceHardRailRouteEndpointCertificate` now retains the authoritative typed
   terminal `SourceVertexId`, two separately authored non-hard-rail A3 paths from
   original trace attachments to the corresponding carrier faces, and a derived
   attachment-to-attachment quarter-turn. The transport composition is
   `φ_second^-1 ∘ χ_carrier ∘ φ_first`; neither source face gauges nor the
   source-matched A3 atlas is rewritten or normalized.
2. A4 `build_surface_cell_network` checks each terminal against the producer-owned
   endpoint map, verifies both original trace samples are exact corners of that
   typed vertex, and enumerates **only** cut non-rail links within its one-ring
   source-star. Missing, nonreciprocal, repeated or ambiguous paths fail closed;
   no global BFS or arbitrary detour/subset search is introduced. The closed-rail
   path remains distinct and does not forge terminal contacts.
3. `SurfacePhaseFrontProduct::make` rechecks typed vertex identity, actual source
   point/face attachment, endpoint reciprocity, path continuity, barrier exclusion,
   non-repeated paths, and each independently atlas-attested A3 link. The two
   endpoint side paths may start on faces other than the immediate rail carrier.
4. `SurfaceOccurrenceComplexProducer` consumes the attachment transport rather
   than the bare carrier χ. The provenance digest incorporates the typed terminal
   and both ordered path receipts.
5. Added `M6CP3.TerminalRailContactPathsUseTypedSourceStarA3`; it requires a
   real produced nonempty terminal germ and independently checks each edge
   against the pipeline A3 atlas. This test was **not executed** in Code + Build.

## Build evidence

- Compile request `fef6284e1e2808ec9684c8b20ef5324f84a5bec5`, pinned semantic source
  `991f655199017375d0ad7ae3fc0b235ffa3de4f0`.
- Eight-target GMP/GMPXX compile state: **GREEN**; workflow run **38080007254**, job
  **114294869088** (`compile / compile`, success), result artifact **11680003032**,
  ZIP SHA256 **993e5d602f399a19dbefa81f26e26dd260121a0a5b4e9659b86df20edd618906**.
  Exact `metadata/source-commit.txt` equals `991f655199017375d0ad7ae3fc0b235ffa3de4f0`;
  eight declared targets, both build/preflight exit codes 0, GMP/GMPXX linkage,
  28/28 archive manifest checksums, clean source status,
  `runtimeExecution=false`. No runtime semantic claims.

## Exclusions and remaining R4 gates

The source-star candidate is a **compile-only** producer change, not runtime proof
of the `(1,4)` boundary terminal witness or of all 39 carried endpoint cases.
It does **not** discharge RA-41 multi-carrier junction/sector clauses, odd-τ,
all 34 previously accepted Phase10 positives, the 88 CP2 losses, or seven
DCEL fixture oracles. The new test is part of the future frozen/test-governed
matrix only if its inclusion is independently authorized; do not alter the 497
selector in this Code + Build turn. No source-grid recovery, validator relaxation,
PR metadata or workflow-permission modification. Frozen authority stays CP2
491/491 accepted, R3 403/497 rejected, 94 RED, 88 CP2 regressions,
ledger 66/17/49 debt 1. PR #8 remains draft and unmerged. Exact successor remains
UNKNOWN until the whole R4 Code + Build requirement is satisfied.

## Durable handoff publication recovery (2026-10-10)

The first four-document patch attempt (dispatcher commit
`c5fbf31b9245a57cb3b8bf3f644581c3274f108d`, workflow
`38080352681`, result artifact `11680013277`, log artifact `11680317745`)
**FAILED** after successful patch download and detached worktree application:
`git push` was rejected as **non-fast-forward** because the branch had moved.
It did not publish these documentation changes. The original exact patch SHA256
`82d621c0d01f2f2ddc010ee4fd60d0dc14da57be100f18e2eb14c1028ddfe37d`
remained recoverable at Drive file `1GLXAi-O4EsUqtd4qmvFjBkGim5rFiefH`
until an authenticated replacement is committed. The correction must rebase on
current branch authority, avoid replaying the stale-base request, and only
retire the old staged Drive patch after the replacement is verified.

## Incremental checked-factory A2b uniqueness follow-up (2026-10-10 19:55Z)

A later source-exact patch extends `SurfacePhaseFrontProduct::make` to independently
reconstruct each typed terminal vertex's complete finite nonhard source star once
from `SourceTopologyRegions`, reject nonmanifold third-edge incidences and missing
reciprocal A3 transport, and count simple nonhard paths separately for both
attachment-to-carrier sides. Exactly one path is required on each side, so a
forged certificate cannot hide a second admissible A2b path. The previously
checked carried paths must still be contiguous, source-attested and disjoint.
One compile-only, nonempty-positive product reconstruction regression is added:
`M6CP3.CheckedFactoryReconstructsProducedTerminalA2bStarUniqueness`. This test
was not executed. No negative forged-multi-path witness has yet been produced.

Verified source snapshot `04935f582324a8eeb05aa930a0d1ed2acab2b1e8`,
workflow `38081108785`, artifact `11680452926`, ZIP SHA256
`d1eda256422ae9ad7b9959ec7910b153382694163ce41c9f3e819fa438b1a68c`,
all **5943/5943** source hashes valid. Exact two-path source patch
`Directional_M6_CP3_R4_A2b_Factory_Unique_Star_Incremental_WIP.patch`,
SHA256 `610b041dfbc07df3c2bf10c1c208928f10e7f9eea0574d787065bd6d6d295e02`,
base `4ba9ce0733f25662ad9b8bcb7c57666c882625fe`, body digest
`836d1e1a911bd4dbd51c9484d32ec1091ffcd6ee6260f6e1b885b2334d61c9c7`,
verified by `git apply --cached --check` and `git diff --check`; Drive apply
workflow `38081631821` / job `114299624739` success, exact semantic commit
`c28f1d241e6d84503e4ab38ce02b7200b8c9cfe5`; apply result artifact
`11681000083` (ZIP digest
`f674c23b02ac77398b03d0f874d92004da1396721c240d7072db3a2bc27e5ea0`).
Staging Drive File ID `1GXr_PjlcogHzjiQAlZX9FqwzGtraxBpY` owner-deleted.
Exact eight-target GMP/GMPXX compile **DISPATCHED**, request commit
`3f136c63c0e79b82ca7159938cff54a3c6f0d372`, request ID
`m6-cp3-r4-factory-unique-star-compile-20261010-a`, mailbox
`.workflow-mailbox/m6-cp3-r4-factory-unique-star-compile/latest.json`:
**PENDING**. Do not claim this incremental source compiles until verified.

R4 remains IN_PROGRESS. No runtime tests or benchmarks have been executed, and
no 497-case selector or Test + Benchmark successor is authorized. Remaining
obligations include actual 39 endpoint cases, synthetic ambiguous A2b negative,
RA-41 multi-carrier/odd-τ, seven DCEL negatives, 34 Phase10 positives, 88 CP2
restorations and independent Test + Benchmark gate.

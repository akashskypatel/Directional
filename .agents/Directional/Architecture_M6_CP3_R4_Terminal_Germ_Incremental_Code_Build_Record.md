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

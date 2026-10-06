# M6-CP3-CB1-ENTRY-R1 WIP handoff — 2026-10-06T17:16Z

Turn remains IN_PROGRESS. No compile/package or generated Directional runtime was executed in this attempt.

## Authority and verified source snapshot

- Entry STATUS for this attempt: `39d42815860b48bfaa2d4ed31d5458ccc8dddaca`.
- The previously pending source-snapshot trigger is now reconciled through mailbox run `37493944389`.
- Exact source/event SHA: `637eb6f217a839ec1f9a6d9871a45b67089736e7`.
- Source snapshot artifact: `11426961344` (`agent-source-snapshot-37493944389`).
- Provider artifact digest: `sha256:dcee2920ecec34c88dc074f5bdff982d09664d263d0855954538909efc761896`.
- Embedded source archive SHA-256: `8a96433c6681df765b9a55c133ff047acd191a288c45bcbd52b7826ffaf2df9f`.
- Source manifest: **5550/5550 verified**.
- Snapshot metadata records `runtimeExecution=false`.
- The earlier fallback-snapshot deviation is superseded for this continuation; all new static work used the exact triggered snapshot above.

## Preserved complete WIP patch for continuation

Google Drive staging:
- folder: `My Drive/Directional-CI`
- file: `M6-CP3-CB1-ENTRY-R1-WIP-20261006T1715Z.patch`
- file ID: `1g2_JTxKgLvDc9NATI_-2Hs5iCpAgz9zZ`
- SHA-256: `39ec76eb1b4e7609397b0a5ffaff6eab7f65364bd260e17ecb1197efa67ff925`
- patch base: `637eb6f217a839ec1f9a6d9871a45b67089736e7`
- exact changed paths:
  - `include/directional/pipeline/RemeshPipeline.h`
  - `src/geometry/SurfaceCellTracing.cpp`
  - `src/pipeline/RemeshPipeline.cpp`
  - `tests/SurfaceCellTransitionQuotientTests.cpp`
- `git diff --check`: clean.
- Fresh-base `git apply --check`: passed.
- Fresh-base application byte-compared equal to the staged working files on all four paths.
- The older `M6-CP3-CB1-ENTRY-R1-WIP-20261006T1626Z.patch` remains a superseded preservation artifact; do not apply it on top of this patch.

## Implemented in the current WIP

1. **P1 face-gauge publication**
   - uniform producer publishes `frame.faceBranchRotation`;
   - periodic producer retains the winning exact branch map, rejects conflicting/missing/non-Z4 gauges, and publishes complete regional face gauges;
   - curved bounded-disk publication remains the existing reference path.

2. **RA-31a HardRail correction**
   - removed `HardRailBranchCertificateMismatch` from the A5 error vocabulary;
   - removed the A5 HardRail branch-certificate rejection and legacy `:branch-certificate` mapping;
   - retained coordinate-rigid transport and endpoint face-gauge evidence.

3. **P2 OrdinaryFront isolation-evidence scope**
   - ordinary non-cross-sheet relations retain full representation/sheet/wedge checks without reciprocal isolation-side evidence;
   - reciprocal isolation evidence and certificate validation are required only in the certified cross-sheet collinear seam branch.

4. **T1 focused30 ordinal-12 migration**
   - the HardRail topology-region relabel now rotates every affected `sourceFaceBranchRotations` entry together with the other relabeled branch authority.

5. **T2 D1 witness audit**
   - the existing production torus fixture already uses `remesh_from_raw_cross_field`, requires an organic nonzero-Z4 exact-A3 pair, and asserts a 90/270 face-gauge delta before downstream authority checks; no source change was needed.

6. **Identity 2 / identity 6 RA-31a handling**
   - identity 2 requires baseline A5 production and the produced 90/270 HardRail gauge witness, removes the withdrawn error-code expectation, and leaves the certificate assertions as the pre-registered RED surface;
   - identities 2 and 6 now emit A5 rejection diagnostics before failing so any remaining producer rejection is Review-owned.

7. **T4 typed barrier oracle**
   - rewritten against `SourceChartTransitionGraph` and exact typed hard-feature carriers;
   - verifies hard carriers are blocked, a hard Periodic carrier is blocked, removing that typed carrier restores the directly governed transition, HardRail carriers are typed/blocked, and adding a typed barrier blocks an otherwise admissible ordinary transition;
   - no arbitrary endpoint `chartComponent` inequality remains.

## Static checks completed

- Regional `faceBranchRotation` assignment/publication census covers uniform, periodic and bounded-disk producers plus the source-wide merge.
- OrdinaryFront reciprocal isolation evidence is now queried only inside the certified cross-sheet seam path.
- Focused30 ordinal 12 explicitly transforms source-face gauges.
- D1 non-vacuity assertion precedes downstream A5 authority checks.
- T4 reads typed hard-feature/transition authority.
- Removed-code grep finds no `HardRailBranchCertificateMismatch` or legacy `InvalidHardRailTransport:branch-certificate`.
- Authorized path census is exactly the four paths listed above.

## Still required

- Before orchestration, re-open this patch and make any final diagnostic-only adjustment needed to print the exact relation identity, not merely relation kind, on unexpected A5 rejection.
- Apply the **complete** patch through standard Google Drive patch transport; do not direct-write source/test changes.
- Compile/package all eight mandated GMP/GMPXX targets through `.github/workflows/agent-compile-reusable.yml` only. No generated Directional runtime.
- If compile/package is green, write the Code + Build evidence/closeout, retire consumed Drive patch/control state, and set exact successor `M6-CP3-TB1-ENTRY-R1-EXEC`.
- Do not execute the 497-process runtime gate in this Code + Build turn.

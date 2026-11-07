# TB50 frozen 508-case preflight — deterministic harness/manifest mismatch

**Turn:** `M6-CP3-TB50-RP01-FULL-GATE-EXEC` (TB-EXEC). **Disposition:** closed at preflight as orchestration failure; no selected-gate execution or semantic acceptance. Recovery successor under RA-170.5: `M6-CP3-CB50A-RP01-ORCH`, followed by separately authorized `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2`.

## Exact immutable authority

- Branch `agent/surface_cell_quad/p5-recover-bridge-healing`; frozen trigger/executor source `2ecbe067bd4dec7c3be288683557479da7a2a33f`; immutable semantic package source `7cf0857b4818186638ce77e4859adacbeebd288f` (CB52).
- CB52 package artifact `12918290481`; ZIP SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`; root checksum manifest SHA-256 `6ae4eb5bf9552912fe068d9a9d3a90d76e2e27b9bd99896f83c216fd27fbc21f`; internal package checksums 28/28 verified; `exactArithmeticBackend=GMP`, `runtimeExecution=false` in package metadata.
- Exact frozen manifest `Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv`, SHA-256 `6d5b788671487fa298ff3a3e9656dfda1729612f02c976206d3960a413121149`; 508 ordered rows. Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d`. Harness self-test 12/12 (harness-only, no Directional binary execution).
- [Artifact-only attempt run 40934197625](https://github.com/akashskypatel/Directional/actions/runs/40934197625), dispatcher request/event commit `b335f5958d9472e1c26562ba41e8f6ee756d9402`; validate-dispatcher, validate-TB-reusable and parse succeeded; `test_benchmark / runtime` failed during manifest validation; mailbox published terminal result on `workflow-mailbox`.
- Result artifact `12923249192`, ZIP SHA-256 `49b4c59f44c02bfc3497a4abe0abb5a9b7ba69510b46cbcf79067b5c953ba695`; log artifact `12923448731`, ZIP SHA-256 `ad3484d745f8934feef3c27635ea85497da05b950b434f972a121dd5e3c8f6fe`.

## Root cause and exact first failure

The immutable manifest violates the unchanged harness `validate_cases` input contract:

| TSV row | identity | kind | frozen `asserted_site` | contract mismatch |
|---|---|---|---|---|
| 505 | `phase10:7414` | GUARD | `InvalidFrontBoundaryAuthority` | GUARD must use `-` |
| 506 | `phase10:7614` | GUARD | `EndpointAttachment/missing-terminal-or-closed-rail-provenance` | GUARD must use `-` |
| 507 | `ra169:c1-ingress` | POSITIVE | `InvalidFrontBoundaryAuthority/orphan-hard-feature-edge` | positive site must use `<file>.cpp:<line>\|<witness>` or `-` |
| 508 | `ra169:c1-factory` | POSITIVE | `InvalidSourceAuthority/open-rail-cover` | same contract |

These are the only four site-format violations found by independent static validation of the 508 rows. Actual CI raises `ValueError: row 505: unexpected asserted-site pin`, exits 90 before scheduling any native case. The machine evidence has `planned=0`, `executed=0`, `passed=0`, `red=0`, `postflight=false`; `configure=false`, `compile=false`, `relink=false`, `benchmark=false`. Do not claim **508/0**, nor call it a semantic RED: **0/508 executed**.

## Correction boundary — next turn only

`M6-CP3-CB50A-RP01-ORCH` must reconcile the four rows' authored assertions with the harness contract, without silently discarding source-locus evidence or weakening assertions. Determine whether the intended producer site belongs in native test assertions, an independently verified harness column, or a properly encoded site pin; preserve anti-vacuity and exact first-failure semantics. Correct the *orchestration contract* in a new Code + Build turn, re-freeze the manifest and harness SHA if changed, and trigger a *new* exact-source compilation/package only if the authorized fix changes code requiring compile. Then `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2` may run artifact-only. Do not change the frozen manifest or harness inside TB50; do not run TB50C or promote selector497 here.

## Ledger classification

S5 orchestration failure; candidate/non-stable, no native runtime or accepted-green loss, stable regression totals **66/17/49**, produced-witness debt **1** unchanged. CP2 491/491 remains last accepted; TB49 504/0 remains reviewed candidate; RP-01 open and RP-02 unreached. Native product correctness and the 508-case prediction remain **unverified**.

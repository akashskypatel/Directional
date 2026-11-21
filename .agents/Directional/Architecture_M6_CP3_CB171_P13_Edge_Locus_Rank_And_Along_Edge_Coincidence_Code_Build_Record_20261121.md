# CB-171 — edge-locus rank and along-edge coincidence (2026-11-21 UTC)

## Situation

Applied the frozen C2/C3 correction to the working branch for a Code + Build turn. No Directional tests or benchmarks were executed. Product acceptance is not claimed.

## Background

- Canonical turn: `M6-CP3-CB-171-P13-EDGE-LOCUS-RANK-AND-ALONG-EDGE-COINCIDENCE`.
- Frozen source authority: CB-170 semantic commit `9e4bd863a3e825371c6d4ce551dd7badd196ad4d`, with unchanged source files at snapshot `ea2ff7a4faadc12f4ea8d5cde04fa3bc6e5dcea3` (run `44893242097`, artifact `14702791941`, ZIP SHA-256 `73462fc7154f4d463a55e06c61f9a5bc001026d86a77431af90ff00f43e77187`).
- Exact patch: `Architecture_M6_CP3_CB171_P13_Edge_Locus_Rank_And_Along_Edge_Coincidence_Exact.diff`; diff body SHA-256 `d99e27b256fb99a658e01c4e2436e72e8f54fb467f71e59c4fac4e44457561c0`. Full work-preservation patch SHA-256 `a65e5d57ec09c6fcee103af690e7ba7943a90b9ad191c5bf6be2e78e28143f8e`; three intended source/include paths; all frozen preimage and postimage SHA-256 values confirmed.
- [Patch apply workflow](https://github.com/akashskypatel/Directional/actions/runs/44893530402): approved Google Drive patch applied and pushed as exact semantic source `65ae140e49db5bd04d202390e71b50f455ff152e`. No unrelated source/test edits.
- [GMP compile workflow](https://github.com/akashskypatel/Directional/actions/runs/44893723942): artifact `14702459291`, artifact ZIP SHA-256 `b6484dc9c88b33e2456d07f92019360999426fb02eff862950caa929cf5c88f6`, eight required targets, `runtimeExecution=false`. Verification: 28/28 internal SHA-256 checks PASS; GMP ON, gmpxx and gmp link; exact source commit; five empty source-status files; compile and preflight exit 0.

## Assessment

- C2: restored `edge_locus_secondary_rank` for ordinary into-face trace rays, with legacy edge-locus primary keys and diagnostics. Removed `edge_piece_into_face_rank`.
- C3: rejected an along-locus-edge trace ray with `EdgeTraceSecondaryRankInvalid` / `RayRunsAlongLocusEdge`. Rejected a vertex along-edge trace that shares a slot with an edge incidence using `RotationTraceRaysAlongSharedEdge`. Invalid or missing first source piece returns `FirstPieceNotLeavingLocusIntoFace`.
- Corrected source hashes: `GlobalTopologyPlan.h` `277cde20c20864e5d9e60d668aca5bf00ca37e41eeb9983e93ed8bdaafd38f19`; `EmbeddedGraphTopology.cpp` `f0599d1ac45d006899f03190efdc01c47fdcb0f9ce281dbc4502513876179a0b`; `GlobalTopologyPlan.cpp` `e1e186541960dceffb596fc484386eb3a8cdbe7ca8ebd8a66a37c5a48a3db459`.
- C3 rejection branches are not directly covered by new tests; testing was not authorized in CB-171. TB-EXEC-155 must test the source through the unchanged 971-row gate and separate 3-case census.
- Historical evidence remains TB154 971/971 and census 3/3; CP2 491/491. Stable accounting 66/17/49, one produced-witness debt and 81 deferred cases. No selector, manifest, stop switch, source recovery, or acceptance change. Sphere χ6 versus required χ2 and the four slide contacts remain open.

## Recommendation

Next independent turn only: `M6-CP3-TB-EXEC-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE`. Use this immutable CB-171 artifact, the unchanged TB154 manifest and the RA-278 allowance A. Do not start that successor in CB-171.

# TB76 CB83 immutable full-gate and production census — independent execution report (2026-11-04)

Canonical turn: `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC`. Artifact-only Test + Benchmark. **COMPLETE as execution; semantic census MISMATCH; no acceptance promotion.** RA-201.10 mandates Review successor `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`. No retry, repair, rebuild, source/test/fixture changes, or next-turn work performed.

## Frozen inputs

- Immutable CB83 GMP/GMPXX package `13289188434`, source `2278b8b649b4262fb70a522371ed282655383af5`, ZIP SHA-256 `c4ca145a987cffef1035c95e0febedbc8b8b387c72678ec41bc59139230288b9`, 28/28 internal hashes; compile-only run [41759757801](https://github.com/akashskypatel/Directional/actions/runs/41759757801), `runtimeExecution=false`.
- Gate manifest 893 SHA-256 `3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8`; deferred ledger v5 81; expected membership 974. Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- Executor source snapshot SHA `754373e1b860069da1c82c49966f47b02ce6c896`, [run 41761545100](https://github.com/akashskypatel/Directional/actions/runs/41761545100), artifact `13290631674`, ZIP SHA-256 `7c2d4ecca70525006326c7cb4e0c926aad8de09eeff3a810df6320c03a49324a`, 6149/6149 source-file checksums verified. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

## Independent evidence

- Full gate [run 41762112729](https://github.com/akashskypatel/Directional/actions/runs/41762112729), result artifact `13290723379`, ZIP SHA-256 `4ffdc80e722fdee601676cdb9556086798f2ed524d753e4915e64d565bfa4a61`: 1794/1794 packaged checksums verified; execution boundary planned/executed/passed **893/893/893**, membership 974, 81 deferred; zero red, abnormal, missing, skipped, duplicate, control failures, unexpected pass or red-site mismatch. Postflight true, exit 0. Configure/compile/relink/benchmark false.
- Production census [run 41762169855](https://github.com/akashskypatel/Directional/actions/runs/41762169855), result artifact `13291024099`, ZIP SHA-256 `fdca98df8919ddae205927884b845fb86ccb27590f790629266d4523598e47ba`: 9/9 packaged hashes independently verified, all three log hashes matched ledger. Execution boundary planned/executed 3/3, 1 PASS, 1 RED, 1 ABNORMAL, no missing/skipped/duplicates, postflight true, exit 0; configure/compile/relink/benchmark false.
- Cylinder: PASS exit 0, 6.33 seconds. BunnyRandom: RED exit 1, 0.59 seconds, exact existing P13-e `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49` (classes=4, expected=5). Both match registered expectations.
- **Vase: ABNORMAL exit 124, `HARNESS_TIMEOUT 600s`.** Raw log ends after three region-support projection diagnostic records; **no completed terminal, no `SelfIntersectingFace` detail, no `completedQuads=67829` evidence**. RA-201.10 required RED within 600 seconds with `terminal=NotProductionReady:completion detail=SelfIntersectingFace` and 67829 completed quads. **Mismatch**. Do not infer the exact hot spot or that CB82 failed from this timeout alone; the RA-201 diagnostic hypothesis is not independently verified by the timed-out log.

## Disposition

Full gate green but registered census mismatch; this is a **valid semantic TB result requiring Review**, not an orchestration failure (runtime executed all identities and postflight passed). Exact next separate turn: `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`. Review must independently diagnose Linux-versus-macOS Vase timing and identify the actual stage/cost owner using fresh evidence before any patch/retry. P13-l orientation and P13-e port count remain separate Review obligations. No new accepted stable regression event, selector promotion, or debt: CP2 accepted 491/491; stable 66/17/49, debt 1; selector497/CP3 unpromoted.

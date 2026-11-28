# CB-197B — exact ordered-stretch retrace (2026-11-23 UTC)

## Situation
The Code + Build turn `M6-CP3-CB-197B-P13-EXACT-SOURCE-RETRACE-ORDERED-STRETCHES` is complete. Its only authorized successor is `M6-CP3-TB-EXEC-176-P13-PIECE-BUILDER-AND-ORDERED-RETRACE-FULL-GATE` in a separate chat turn. No successor work began.

## Background
TB-REV-175 adversarial findings G1–G4 and `gates/Architecture_M6_CP3_CB197AB_P13_Exact_Manifest.md` authorize exactly `.agents/Directional/Architecture_M6_CP3_CB197B_P13_Exact_Source_Retrace_Ordered_Stretches_Exact.diff`, SHA-256 `1fe85e273a1c997fc976f4cbc7779f3a7711d19b511cfc6824a5809a2325be8d` (5,687 bytes, +57/−27). It changes `exact_source_paths_retrace_along_edges` to compare ordered directed stretches, not only accumulated edge coverage, and adds its approved test source. The helper remains unwired.

## Assessment
- Immutable source snapshot: [run 45254071247](https://github.com/akashskypatel/Directional/actions/runs/45254071247), source `17c8aa6114522297ecd991e08b51925ee6e949ee`; source archive `14855843772`, SHA-256 `ff5fd9d8a3a1c818b91c3a9ee4442b8c483e9088ff4f5a02bd88b2374703c344`; snapshot member checks verified.
- Exact source preimages: `include/directional/authority/ExactSourcePath.h` Git blob `fbae34c6472b708a46a2def2320ad7167c577f32`; `tests/FieldAlignedCurveNetworkTests.cpp` Git blob `92fe1c3858d3865448fb70343e35baa7a7b0219b`. Both match the approved manifest. `git apply --check` and `git diff --check` passed.
- Exact source postimages: header SHA-256 `8a7a9306b55627fe35bad25bca19b040de0e1b87e1f6630b207847625e761b34`; test SHA-256 `e0eb98956f09793c8e9676e6188e8d7163566793f7a92a6355772c2a1bdf259c`.
- Application: [run 45254780820](https://github.com/akashskypatel/Directional/actions/runs/45254780820) applied only these two files as commit `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`. Result artifact `14858615694` SHA-256 `44cebbce0e02b97e62d1e48d4a413b42c02fddb70ef4e50bc1c0a18a2ac6bb10`, `runtimeExecution=false`. The Drive transfer file was deleted after successful application. Verified preservation patch SHA-256 `857d9a66fc7ebf8cdb349c67a38a183f999f6d132a0759a00c8e08dc5d551a13` (6,379 bytes), with internal diff-body SHA-256 `2901fa3fbb8fbb72283aec18cbf45d51ec2cd4fb4346df523b87997318e87bef`.
- GMP/GMPXX compile-only: [run 45255304770](https://github.com/akashskypatel/Directional/actions/runs/45255304770), source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`, eight required targets including the source producer tests. Build artifact `14859356205` SHA-256 `e6111ff21530f107ab8b1db724155aa2c4fbbe4a2765342fbfabbd4a9c4fc664`; diagnostic log `14858416869` SHA-256 `724f34a99244c44b3b7fa1b613d64f395e18cd046e95a9c3dc564d9c1e36d860`; all 28/28 package checks verified. `runtimeExecution=false`, no Directional executable, test, or benchmark ran.
- The frozen 1001-row TB-EXEC-176 manifest was not executed. TB175 remains rejected, 993/1000, seven mechanical RED at 445/652/653/656/658/660/786. Accepted TB169 993/993, CP2 491/491, stable 67/17/50, debt1/deferred81 remain unchanged. No selector, manifest, producer wiring, validator, CMake, or CP3/497/D0/H4 activation changed.

## Recommendation
Start only `M6-CP3-TB-EXEC-176-P13-PIECE-BUILDER-AND-ORDERED-RETRACE-FULL-GATE` in a new turn. Use the exact immutable GMP package and the frozen 1001-row selector. Expect 994 PASS and seven known RED; report measured results, not predicted success. No rebuild or source change is authorized in that test turn.

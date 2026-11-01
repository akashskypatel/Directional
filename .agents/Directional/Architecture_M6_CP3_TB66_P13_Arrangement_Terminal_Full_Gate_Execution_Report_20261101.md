# TB66 — arrangement-terminal immutable Linux full gate and P13 census (2026-11-01)

**Canonical turn:** `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` (artifact-only Test + Benchmark). **RA-193.6's pre-registered outcomes matched.** The 869-case gate is **869/869 PASS**, with exact membership **950 = 869 GATED + 81 DEFERRED**. The independent three-case census reports Cylinder PASS, BunnyRandom expected RED and Vase expected RED at the earlier arrangement stage. This is neither a production acceptance nor a promotion of CP3 or selector497.

## Immutable inputs and execution boundaries

- Compiled CB69 semantic source: `5b08abe42f91f88fd6d09e225c7cf32d0aeb1ef3`, Linux Release/static GMP/GMPXX package artifact `13084749209` from compile-only run [41310503404](https://github.com/akashskypatel/Directional/actions/runs/41310503404). Package outer ZIP SHA-256 `dd00aa3590b584a72523aef8483faa928d806d816187c6bb6a91f5b19f9e648e`, root SHA256SUMS `93c21dcf1ad25aa7b6d560831d7fac9c7d69ecb9df3a0825dc79a7f78c22d123`, source archive `432bcc5a5b843c4ed1f21fe28467ee2ebefbded1fc4d4edb484c1eddc3714ed0`, 28/28 packaged checksums. No rebuilding in TB66.
- Unmodified artifact-only harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Unmodified 869-row TB65 gate manifest SHA-256 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`; 81-row deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; 950 unique `(binary,test)` identities with no cross-membership duplicates.
- Independent three-row TB63 P13 census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. Source snapshot for immutable dispatcher executor `1d32b9c5526ac7adfb5994e2494213af7f7cf0af` was verified (6070/6070 file hashes); harness remains unchanged.

## Run evidence

| Item | Full gate | Independent census |
|---|---|---|
| Dispatcher request | `m6-cp3-tb66-arrangement-gate-20261101-v1` | `m6-cp3-tb66-arrangement-census-20261101-v1` |
| Event SHA | `2480457f830fe85dd08786cb0c0190ffe6ab4aa0` | `b994e09005cdcd652d5cfac8b4f4f05789772b4a` |
| Workflow | [41312768151](https://github.com/akashskypatel/Directional/actions/runs/41312768151) SUCCESS | [41312834931](https://github.com/akashskypatel/Directional/actions/runs/41312834931) SUCCESS |
| Runtime job | `124866506845` SUCCESS | `124868874572` SUCCESS |
| Result artifact | `13086562028` | `13086079391` |
| Result ZIP SHA-256 | `c13447dcb20567fde1f818da761cacf4bbc124908b79bf51375f11fcd8bae733` | `8fdd9dd3c117df6510de9791e6df62e35a1ca8c1e6c42f3673522c523f9b2cd6` |
| Internal SHA256SUMS | **1746/1746 PASS** | **9/9 PASS** |
| Observed | **869 PASS, 0 RED/abnormal** | **1 PASS, 2 registered RED, 0 abnormal** |
| Boundary | `postflight=true`; exit 0; membership 950 | `postflight=true`; exit 0; membership 0 |

Independently downloaded each result ZIP once; verified ZIP SHA-256, every internal SHA256SUMS entry, every manifest-to-ledger identity and **each of 869+3 ledger-to-raw-log hashes**, one selected GTest per row, expected GTest verdicts and all individual resource receipts. Full gate: 859 GUARD + 10 POSITIVE; no missing, skipped, duplicated, unexpected PASS, control failure or later-positive RED. The membership table is exactly 869 GATED and 81 DEFERRED; deferred cases were not run. Both runs have `compile=false`, `relink=false`, `configure=false`, `benchmark=false`, and postflight success. Workflow compile and Drive-apply jobs were skipped; validator, runtime and publisher jobs succeeded. This is source-authenticated candidate evidence, not independent production acceptance.

## P13 direct-production census — registered signatures reproduced

1. **Cylinder** `offgate:362`: PASS, direct source-authoritative pure-quad acceptance test (~12.5 seconds GTest time).
2. **BunnyRandom** `offgate:360`: expected RED; `terminal=InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, region 0 `cutChi=-5`, `cutBoundaryLoops=7`, no produced output. P13-e remains separate Review/Definition; this is not a new gate regression.
3. **Vase** `offgate:365`: expected RED; `terminal=NotProductionReady:arrangement detail=RepeatedNodeCycle traceSegments=192482 arrangementCells=0 completedQuads=0 completion=`. The typed terminal is now attributed to the earliest invalid arrangement, as required by O18; this does **not** establish a valid arrangement or completion. P13-d's rotation repair (R1 + R2) belongs to later CB70. GTest runtime ~183.4 seconds.

The two RED cases are **OBSERVE-only** and exactly match the previously registered failure signatures. The CB69 terminal-stage fix is therefore verified, while the root defects remain. No unexpected previously accepted test turns RED. **Stable 66 events / 17 categories / 49 recurrences, debt 1**; last accepted CP2 **491/491**; selector497 frozen and CP3 design-acceptance unpromoted. O18 terminal attribution is discharged by TB66; P13-d (rotation), P13-e (port counts), P13-f (future completion cost), O16/O17/O19/O6/O9 and DR1/DR3/DR2/DR4 are carried per RA-193/194.

## Disposition / successor

No TB66-REV is triggered because the evidence matched RA-193.6; no TB66A orchestration retry is required because both immutable runs finished successfully. **Authorized successor, not started in this turn:** `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION`, exact RA-193.11 two-file patch, Code + Build compile-only. The 871-row TB67 gate belongs to a separate subsequent turn. No source, test, fixture, benchmark, selector, reusable workflow, or build logic was modified by TB66.

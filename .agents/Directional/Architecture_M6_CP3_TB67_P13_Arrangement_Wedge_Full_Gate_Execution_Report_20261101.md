# TB67 — immutable arrangement-wedge full gate and production census (2026-11-01)

**Canonical turn:** `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC`. Frozen RA-193.8 outcomes, as renumbered by RA-194, were reproduced. This is an artifact-only Linux Test + Benchmark turn, **not** CP3 or selector497 promotion. No source/test/fixture/build change or package rebuild was made.

## Immutable authority and registered boundaries

- **CB70 source:** `9754500b2058229b7f0a6268838953650690b031`; immutable eight-target GMP/GMPXX compile package `13087332886` from [run 41316990078](https://github.com/akashskypatel/Directional/actions/runs/41316990078), outer ZIP SHA-256 `7dcbcf7ee3a3e8929580e15f3eaae31cdbd31f6e52ad2889ee3089d4176e57c6`, package root manifest `69f3164f799a905bf464ab7da0f6157c9594d2ae7aeb4f094daea129e47495a6`, package source archive `b773d410b3d70e0bdd6b23b0882757b55f421d733ae7ccadbfe52cbb7b8c91f4`.
- **Executor:** verified snapshot `ca2de7da39a88183d2079f3086205cd2415f15b3` (run `41318291037`, artifact `13088122724`, 6072/6072 source hashes); the prior exact executor event `70a796738914652209737a8a5719fa10f3d9c914` was frozen in both test dispatcher requests. Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`, unchanged.
- **Frozen inputs:** 871-row TB67 gate manifest SHA-256 `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b`; 81-row deferred ledger v5 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; 952 unique membership identities. Three-case census manifest `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. Registered Gate: 871/871, Census: Cylinder PASS, BunnyRandom RED at port count, Vase ABNORMAL 600-second timeout.

## Independently verified execution

| Evidence | Full gate | Production census |
|---|---|---|
| Dispatch request | `m6-cp3-tb67-wedge-gate-20261101-v1` | `m6-cp3-tb67-wedge-census-20261101-v1` |
| Trigger event | `ba286c7235c5196a3e2651ba87902f8f65f91bbc` | `eb431875055ac59f5dce79486e10193d6e40d14a` |
| Run | [41318594024](https://github.com/akashskypatel/Directional/actions/runs/41318594024) SUCCESS | [41318624551](https://github.com/akashskypatel/Directional/actions/runs/41318624551) SUCCESS |
| Immutable result artifact | `13089225030` | `13089595542` |
| Outer ZIP SHA-256 | `cc3dd211d243081c8fc9861923fd1a01c332c9b8182692e8f1f7dad693642dce` | `fb80af756d9a740d1393c7f12b66bcf4f8f399544056b467c4207fe89487621e` |
| SHA256SUMS | **1750/1750** | **9/9** |
| Cases | **871 PASS; 0 RED / ABNORMAL** | **1 PASS / 1 expected RED / 1 expected ABNORMAL** |
| Postflight, execution boundary | true; exit 0 | true; exit 0 |

Each downloaded outer artifact ZIP matched its GitHub published digest and all internal hash receipts. Independently checked the full-gate ledger against **871/871 unmodified raw logs** by SHA-256, the exact selected GTest identities and one observed `[ RUN ]` and `[ OK ]` per identity; **861 GUARD + 10 POSITIVE**, and exact 952 unique membership entries (871 GATED, 81 DEFERRED). Three census ledger hashes matched all three raw logs; the resource receipts and explicit timeout marker were inspected. No cases missing/skipped/duplicated, no control errors or unexpected PASS. Both executions reported `compile=false`, `configure=false`, `relink=false`, `benchmark=false`; compile and Drive-apply workflow jobs were skipped.

## Registered production observations

1. **Cylinder** `offgate:362` — PASS; direct source-authoritative pure quad output acceptance, fresh process, ~9.08 s wall.
2. **BunnyRandom** `offgate:360` — expected RED (exit 1): `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, `cutChi=-5`, `cutBoundaryLoops=7`, zero traced/arranged/completed output. This repeats P13-e, not a new accepted-prefix regression.
3. **Vase** `offgate:365` — expected ABNORMAL (exit 124): raw record ends at **`HARNESS_TIMEOUT 600s`**. It never publishes a final terminal stage/verdict or completed quad output; the source-side RA-193 P13-f O(F) completion cost remains the investigation hypothesis, not a verified new completed-stage runtime outcome.

## Disposition and exact next boundary

**RA-193.8 outcomes match.** The arrangement-wedge focused guards 870–871 and all pre-existing 869 gate identities pass; off-gate BunnyRandom and Vase remain unresolved. No newly observed stable regression; stable **66 events / 17 categories / 49 recurrences**, produced-witness debt **1** unchanged. **Last accepted CP2 491/491**, selector497 frozen and unpromoted, CP3 direct-production matrix incomplete. O18 attribution verified by TB66; P13-d shared-wedge/rotation regression guards pass under TB67, but a successful Vase arrangement output is not demonstrated in this timed census. P13-e singularity-port-count remains a separate Review DEFN; P13-f ownership-cost Review DEFN is the authorized next sequential turn. Carry O16/O17/O19/O6/O9, DR1/DR3 and DR2/DR4. Do not enter a CB or run a new test before the next Review/Definition adjudication.

**Authorized successor, not started here:** `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (RA-193.9, P13-f), subject to repository authority; `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` remains an independently authorized parallel Review track. No TB67-REV was triggered (no pre-registered mismatch) and no TB67A orchestration correction was needed.

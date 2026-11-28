# TB-EXEC-174 — immutable retrace oracle full gate (2026-11-23 UTC)

## Situation

**The full 998-case Test + Benchmark gate is REJECTED:** **991 PASS / 7 RED**. All 998 cases executed, with zero missing, skipped, duplicate or abnormal executions. The seven existing mechanical failures remain at **445, 652, 653, 656, 658, 660, 786**. New retrace oracle cases **997/998 both PASS**; prior shared-edge cases 995/996 remain PASS. This is a completed semantic measurement, **not** an accepted production gate.

## Background — frozen execution authority

- Canonical turn: `M6-CP3-TB-EXEC-174-P13-RETRACE-ORACLE-FULL-GATE`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open.
- CB-195 exact source `29415df1ca8d76825a531092f65ff85e4ecd3b9d`; compile-only GMP/GMPXX run `45198338115`; immutable package `14832291155`, ZIP SHA-256 `7a06da51b899ba73f7e9b2375275be87dceeab86dba469cae5bad5be6cf6350c`, **28/28** package checksums verified, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- Frozen 998-row manifest `gates/Architecture_M6_TB174_P13_Retrace_Oracle_Full_Gate_Case_Manifest.tsv`, SHA-256 `f98436b2744dea6f9a0f1a490463d158ac657e9e7ed20343e0b89b188e9db8e7`; frozen deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred). Total membership **1,079**.
- Dispatcher request commit `069c2c185af05fecf21cebb1359df1adef076be4`, exact test harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. [Run `45206305297`](https://github.com/akashskypatel/Directional/actions/runs/45206305297); result artifact `14833644440` SHA-256 **`f77730c1896c346b15de704c90326a5a6543816a3e8ab553d4d8a70b9e11d5a3`**, **2,004/2,004** internal checksums valid. Dedicated log artifact `14834867504` ZIP SHA-256 `b434498ae1320132befce222bff5ca9aa313313d8c397066001d93578c866743`. Mailbox key `m6-cp3-tb174-retrace-oracle-full-gate` on orphan ref `workflow-mailbox`, source/event SHAs independently matched.
- TB173 comparison [run `45180338549`](https://github.com/akashskypatel/Directional/actions/runs/45180338549), result `14821438542`, ZIP SHA-256 `22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`, **2,000/2,000** checksums valid; 989/996 PASS, seven RED, membership 1,077.

## Assessment — verified gates and normalized comparison

| Measurement | TB173 | TB174 |
|---|---:|---:|
| Planned/executed | 996/996 | 998/998 |
| PASS / RED | 989 / 7 | **991 / 7** |
| Missing/skipped/duplicate/abnormal | 0 each | **0 each** |
| Required-control failures | 7 | **7** |
| Unexpected PASS / later-positive RED / wrong RED site | 0 each | **0 each** |
| Gated + deferred membership | 1,077 | **1,079** |
| Internal result checksums | 2,000/2,000 | **2,004/2,004** |

- **Complete inherited prefix:** All **996/996** previous ledger entries have identical identities, expected case data and outcomes (excluding per-run raw-log checksums). The **996** full raw logs compare as **741 byte-identical**, **254 different only by permitted Google Test elapsed time/line ending (N1/N2)**, and **one (row 179) differing only by a proven whole-record reorder (N3) and elapsed time**. Row 179 preserves exactly **24 complete** `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records (12 region=0 and 12 region=1); line positions, complete record multisets and all nondiagnostic text are identical after N1/N2. **No unapproved raw difference, assertion-site shift, missing record or semantic drift**. This row is not an added exception: it uses frozen N3.
- **New independent oracle cases:** 997 `ExactSourcePathRetrace.ChainRunBackOnOtherCarriersAndBreaksRetracesIt` PASS; 998 `ExactSourcePathRetrace.SameWayOtherEdgeOrFaceCrossingPathsDoNotRetrace` PASS. Both are isolated tests for the **unwired** `exact_source_paths_retrace_along_edges` helper. They do not show source-network repair. Cases 995/996 remain PASS.
- **Known mechanical regression:** The same seven accepted-green controls remain RED. Row 652 still reports `RegionElectedCutComponentEmpty` at `RegionConstruction`, with unresolved region ownership. Cases 445/653/656/658/660/786 do not restore a mechanical topology plan. Accepted CP2 **491/491** remains the baseline; this candidate is **490/491**. Row 979 passes its **diagnostic test** but still records staged `RegionContainsInteriorSingularity` at source vertex **8**, not a production-success output.
- **Fail-closed evidence:** `execution-boundary.json` identifies source `29415df1ca8d76825a531092f65ff85e4ecd3b9d`, artifact `14832291155`, `postflight=true`, error `ValueError: required controls failed`, exit **90**. `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. There was **no rebuild, code/test/fixture/selector/manifest mutation or production census** during TB174.
- **Regression classification:** **Continuation of the existing TB170 accepted-green mechanical regression**, not a new stable event, category or recurrence. The unchanged ledger/readouts and identical retained RED witnesses establish no new stable signature. Historical **67 events / 17 categories / 50 recurrences**, produced-witness debt **1**, deferred **81** remain unchanged, subject to independent TB-REV-174. No CP3/497/D0/H4/production promotion.

## Recommendation — independent review in the next turn only

Only `M6-CP3-TB-REV-174-P13-RETRACE-ORACLE-FULL-GATE` may re-open the artifact evidence and independently adjudicate this rejected gate. The scheduled subsequent CB-196 arrival-port receipt is review-controlled and remains **unstarted**. It must not treat isolated helper PASS as repair of A2a step-7 selection or the seven mechanical failures. Preserve the seven RED witnesses, source and selector authority, and held CP3/497/D0/H4 state. The current TB execution turn performed no successor work.

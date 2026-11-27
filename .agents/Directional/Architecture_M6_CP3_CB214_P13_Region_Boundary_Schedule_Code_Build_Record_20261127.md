# CB-214 — Region boundary schedules (2026-11-27 UTC)

## Situation

`M6-CP3-CB-214-P13-REGION-BOUNDARY-SCHEDULE` meets the compile-only gate. The exact frozen patch is committed and compiled. Runtime acceptance is not established. Only `M6-CP3-TB-EXEC-191` is authorized after the root STATUS beacon records completion.

## Background

The [exact manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md) and [DEFN-65C](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md) govern this turn. A4D1–A4D5 remain unchanged. The schedule binds each A2b region boundary-walk occurrence to its A3 span in plan order, records start/end nodes, incidence, chain ordinal and direction, span count and total boundary count, or returns one of three typed reasons (`TopologyPlanMismatch`, `ArcNotScheduled`, `IncidenceNotFound`). It is not called by the production pipeline. Two frozen guard tests and 16 additional predicted row858 receipt lines remain unexecuted. No existing assertion is changed.

## Assessment

| Evidence | Exact authority |
|---|---|
| Frozen diff | 17,530 B, SHA-256 `0fc97ddc4ac033281a1bc6c8ce9eafd379e89a888f5906ccf3c74a1f59b8c02b`; four paths, +316/−0. All four preimages and postimages match the manifest. `git apply --check`, exact replay and `git diff --check` passed. Remote postimage Git blob IDs match local replay: header `35941c2e308fc46de3687334c75c8d34e0d36995`, implementation `fb677d528efeeaea339fcf0ff056aa08b5dc0b38`, baseline tests `34448f5e3ca9d3502b0f9cdea819144669ec5763`, display tests `9e62bec215fc5221b757dfc2638fef2630751b88`. |
| Snapshot | [Run 45948857406](https://github.com/akashskypatel/Directional/actions/runs/45948857406), job `140339835801`, source `c4744396f6eeede24c8039071cea79478199d81b`, artifact `15175384004`, ZIP SHA-256 `1d09d261a5cadefc41b1f4d72d15076d42713fab668bbcead19b5ef4a9519ec0`, source archive SHA-256 `d929c9288eeb253bfc71214880e00be8bf4ac83c8733c159163660a73342ed0c`, 5882/5882 checks. |
| Apply | [Run 45949133311](https://github.com/akashskypatel/Directional/actions/runs/45949133311), job `140340799792`, request `5d121caaf954a36bb6c7343a717a9d163f4a437a`, source `9ed5560822ae435e55101206dcb6ecda59bca706`. Full patch SHA-256 `df2de13421f284216171cd6dab6ffc93c7c0fe8ebff7290275bd7306d0023a33`, diff body `dcb8295a6411dfb5d8118477349554888110c2f52f400900c69854f4c0d04027`; result `15175283425` ZIP `f12614998e3eed859e62c2be27645712788f6fd25c875bf898ece9e241981960`; log `15175937178` ZIP `65d81e7398a23594bbf27deaf80e2bb20e6f8b0e3d03d863beb7cddf05f86d11`. Download verification and apply/push exit 0. Owner connector retired consumed Drive file. |
| Compile | [Run 45949296543](https://github.com/akashskypatel/Directional/actions/runs/45949296543), job `140341297952`, request `9c17c3b32314fde1cd4bb8e40ac83b4af0e1461b`, source `9ed5560822ae435e55101206dcb6ecda59bca706`. Configure, preflight and build passed. |
| Candidate | [15175464398](https://github.com/akashskypatel/Directional/actions/runs/45949296543/artifacts/15175464398), ZIP SHA-256 `d53298314ab80c89e2fd9e8891b8883b798f4d6e9029acf5e3b177070eba108b`, root manifest SHA-256 `eafa93881c9bfb5e5add286d616a7ec3af1b2d181945a0fba35138109e04ebb9`, source archive SHA-256 `819b4dbf457c575430dc271edd2e3536ae957445c8ce4c4cd093bdf8e9c98236`. 28/28 checks. Expires 2026-12-04T06:10:49Z. |
| Compile log | [15175394422](https://github.com/akashskypatel/Directional/actions/runs/45949296543/artifacts/15175394422), ZIP SHA-256 `b18d9410f386c2afffc3078051012b17b44a81ed4bfc4ee351f437de26e8e6f6`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, five empty source-status files, preflight/build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`; `libgmpxx.so` and `libgmp.so` link evidence. Eight exact targets, two libraries, six executables; executable mode bits verified. |

All 1200 archived regular files were compared to the verified snapshot after local replay. Only the authorized four source postimages and dispatcher request differ from the preimage source. No local compilation, discovery, tests or benchmarks ran. No producer, dispatch, veto, fixture, selector, harness or workflow definition change. The accepted gate is still TB189 1006/1006, CP2 491/491, membership1087. Candidate gate membership1089 = 1008 + 81; it has no runtime credit. Stable 67/17/50, debt1/deferred81. V5 unaccepted. B1 held and B2 carried. No CP3/497/D0/H4 promotion.

### Closeout checks

- [Cleanup run 45949330372](https://github.com/akashskypatel/Directional/actions/runs/45949330372), job `140341322254`, result `15175593030` ZIP `69a3a017db42d115ff4c8f2524c39396866766eb5e8e255f6a151e392d5522bb`, log `15175642814` ZIP `bd562794ba47bd38a785b9fe17e8a9dd788242a6d353db7dbf9de6a772498740`, cleanup commit `e966f5130b22e6737cbddcf125e9b9008ba2b296`. The snapshot marker and cleanup manifest were removed. Ten durable workflows and the request slot were preserved; zero PR comments were removed. The candidate source was pinned before cleanup.
- Document drift audit: zero errors; existing ORIENTATION size warning. Explicit durable-heading comparison passed. No policy or normative edit.
- Process limitations: initial direct handoff/orientation inspection preceded the verified snapshot; corrected by snapshot-only source application. Full mandatory pre-work policy/LESSONS review and exact tool-call ledger are not established. External turn-based-coding-agent skill was reviewed after source application. Initial snapshot discovery required the exact request-SHA lookup; no duplicate trigger. No runtime or product acceptance is inferred.

## Recommendation — TB-EXEC-191 only, after CB-214 STATUS COMPLETE

Use the [frozen manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md) and unchanged harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Pin the executor checkout to `9ed5560822ae435e55101206dcb6ecda59bca706`: the older CB-208R executor `cc25a6402cdd3ca1a33a9a9778250176b182bb2a` has the same harness bytes but does not contain the new gate manifest. This is checkout authority only, not an executor-code change. Use the durable `test_benchmark` dispatcher, with `executor_sha` and `semantic_source_sha` both `9ed5560822ae435e55101206dcb6ecda59bca706`, the exact successor turn ID and these inputs. Do not use diagnostic mode or V5.

| Environment | Value |
|---|---|
| `CANDIDATE_ARTIFACT_ID` | `15175464398` |
| `EXPECTED_SOURCE_SHA` | `9ed5560822ae435e55101206dcb6ecda59bca706` |
| `EXPECTED_CANDIDATE_ZIP_SHA256` | `d53298314ab80c89e2fd9e8891b8883b798f4d6e9029acf5e3b177070eba108b` |
| `EXPECTED_ROOT_MANIFEST_SHA256` | `eafa93881c9bfb5e5add286d616a7ec3af1b2d181945a0fba35138109e04ebb9` |
| `EXPECTED_SOURCE_ARCHIVE_SHA256` | `819b4dbf457c575430dc271edd2e3536ae957445c8ce4c4cd093bdf8e9c98236` |
| `CASE_MANIFEST` | `.agents/Directional/gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Full_Gate_Case_Manifest.tsv` |
| `CASE_MANIFEST_SHA256` | `ca16b66da3cb52e77a3540c79f9357e3e9e59b211bae872f87d58f60c4434081` |
| `EXPECTED_CASE_COUNT` | `1008` |
| `MEMBERSHIP_LEDGER` | `.agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` |
| `MEMBERSHIP_LEDGER_SHA256` | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |

Verify exact artifact and source authority, 1089-member accounting, 81 deferred, CP2 491 and unchanged harness. Execute the 1008 cases once. Preserve all ordered ledgers and raw logs. Compare rows 1–1006 except row858 to TB189 result `15171482516` under frozen N1–N3; require both new GUARD rows to PASS. Row858: preserve every byte through the last of TB189's 45 receipt lines (`SphereAuditedBridge …`); require exactly the next 16 predicted receipt lines in order; compare the remaining suffix under N1/N2. Sphere prediction: 14 regions, 60 sides, 30 paired arcs, all even; each count ≥ 1, exact side-count vector per manifest. Genus_two must report built=1 and otherArcs=0, record totals. STOP on RED, invalid boundary, crash, missing receipt or prediction mismatch. Record all counts and typed failure data; do not repair or rerun. TB-REV-191 independently adjudicates. No producer activation, dispatch or veto change, B1/fallback repair, CB-207D, V5 or promotion.

# TB86 — immutable full-gate execution continuation (2026-11-08 UTC)

**Canonical turn:** `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-EXEC` (still in progress as of 2026-11-08T10:32Z). This is an artifact-only Test + Benchmark turn: no rebuild, semantic code/test mutation, or acceptance promotion.

## Exact input authority

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; executor source snapshot SHA `5fafaab293f5fd7df7652db15cfc7490a9740c25`, snapshot run [42471196693](https://github.com/akashskypatel/Directional/actions/runs/42471196693), result artifact `13613821373`, provider SHA-256 `dc18c503bf95c3b51cecd991728d3059ca48321563468e396898c8792603b712`. Nested archive SHA and 6,246/6,246 file checksums verified.
- Immutable CB103 source SHA `000752d896aad4e515bcffc23331c26692539830`, compile run [42468093355](https://github.com/akashskypatel/Directional/actions/runs/42468093355), binary artifact `13613225138`. Verified provider ZIP SHA-256 `b7fc883e27bd31f03e595e120aa685feba3bb769ce84837dc73da94e11ee13d2`, root `SHA256SUMS` SHA-256 `a9f1561c4c6d696f5af56af18edbfca96ccbcf1c72e788227c903092a4df98fb`, 28/28 package checksums, source TAR SHA-256 `16af3c8af1c771bc475bc9c47185b05670a93418c076d2baee9c07a44e5f2951`, compile-only GMP evidence.
- Durable harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; both manifest self-checks passed.
- Gate case manifest `Architecture_M6_TB86_P13_A3_Span_Coverage_Full_Gate_Case_Manifest.tsv` SHA-256 `3573ffbf6cba47592489c34f2177988c1b66871db4cd983577694dbb9dcabe76` (909 cases); deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred); expected membership 990. Census case manifest `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 cases).

## Executions already dispatched

| Workload | Dispatcher event commit | Run ID | Last observed state |
|---|---|---|---|
| 909-case gate | `385ec94e6f007ad3603c7ff88dacef81b4203369` | [42471488975](https://github.com/akashskypatel/Directional/actions/runs/42471488975) | In progress |
| 3-case production census | `6ec540ad698c8a31d36099a923caa16087b83a26` | [42471512649](https://github.com/akashskypatel/Directional/actions/runs/42471512649) | Pending (dispatcher concurrency) |

Both are `test_benchmark` dispatcher operations with `executor_sha=5fafaab293f5fd7df7652db15cfc7490a9740c25`, semantic source pinned to CB103, no package rebuild. Mailbox keys `m6-cp3-tb86-gate` and `m6-cp3-tb86-census`, respectively. Obtain artifacts from their per-key mailbox records on orphan ref `workflow-mailbox` (or exact run IDs). Do not redispatch unless evidence establishes an orchestration failure.

## Exact pending comparison

- Gate must execute 909/909 PASS, membership 990, postflight true, source/package integrity preserved; compare rows 795, 796, 797, 864 platform-digest lines byte-for-byte with TB85 immutable gate artifact `13603128508`.
- Census must cover Cylinder, BunnyRandom and Vase, compare every platform-digest line byte-for-byte with TB85 census artifact `13603685923`; record typed outcomes and timings, including pre-existing expected REDs.
- Every `a3-coverage` record: `partial=0`, `foreign=0`, `covered+unrecorded=scheduled`. Plane, MultiFaceSeam, CloseSheets, Cylinder: `observed=1`; Vase `observed=0`. Preserve the singularity veto and all existing independent oracles.
- Pre-registered mismatch successor `M6-CP3-TB86-P13-A3-SPAN-COVERAGE-FULL-GATE-REV` (runtime-free); infrastructure successor `M6-CP3-TB86A-P13-A3-SPAN-COVERAGE-ORCH`. On exact MATCH, determine the next step from RA-214 and current TODO/handoff, but **do not begin it in this turn**.
- Accepted CP2 491/491, stable 66/17/49 with debt 1, deferred 81, CP3/selector497 unpromoted. No test outcome or promotion asserted by this WIP.

## Cleanup and continuation

The one temporary source-snapshot trigger `.agents/connector-triggers/source-snapshot/tb86-20261108-1023.json` was submitted to durable turn-cleanup workflow [42471707712](https://github.com/akashskypatel/Directional/actions/runs/42471707712), which completed successfully, cleanup source SHA `dd08052623b03789aea3dea6ecd604059e0ffe60`. The durable `agent-dispatch-request.json` slot, reusable workflows and orphan mailbox remain preserved. No locally generated implementation patch exists.

# TB-EXEC-155 — producer-switch full gate (execution in progress)

## Situation

The canonical Test + Benchmark turn is `M6-CP3-TB-EXEC-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE`. The immutable CB-171 gate and census were dispatched. **This is a provisional execution record, not a completed test result or product acceptance.** Do not start TB-REV-155.

## Background — immutable inputs

- Exact semantic source: `65ae140e49db5bd04d202390e71b50f455ff152e`.
- Compiled artifact: `14702459291`, outer ZIP SHA-256 `b6484dc9c88b33e2456d07f92019360999426fb02eff862950caa929cf5c88f6`.
- Internal package checksum list SHA-256 `20bd2f53f77fd69348b011cf0f5f46213bc6207b5aad6201ee4b371725101d26`; embedded source TAR SHA-256 `2a55d1452d66142833e350ea9518445365814e37665ddae7579773efef5c851a`. The exact ZIP and all 28 internal checksums were verified independently before dispatch.
- Reused harness `tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Unchanged TB154 full gate manifest SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305`; 971 required and 81 deferred. Deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Census manifest SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`; three cases.
- Full gate baseline TB154 artifact `14696380156`, ZIP SHA-256 `ce172d892dbf3f52084eaf3a148ec03443bc19c06ec9e5262f89e35c89b648c0`.
- Direct census baseline TB151 artifact `14621727104`, ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`.

## Assessment — dispatch evidence, not runtime verdict

- Gate: request `m6-cp3-tb155-gate-20261121-v1`, event commit `3ab3c9844c837612f3e3bec920fc734f6243c860`, [run 44895154802](https://github.com/akashskypatel/Directional/actions/runs/44895154802), mailbox key `m6-cp3-tb155-gate`. Both workflow-schema validations and the parser passed. The artifact-only runtime job `136819221387` was running at the last observation. Compile and Drive-apply jobs were skipped.
- Census: request `m6-cp3-tb155-census-20261121-v1`, event commit `2f804ed801c936bb74370965dbe3eccb51e3ab77`, [run 44895169959](https://github.com/akashskypatel/Directional/actions/runs/44895169959), mailbox key `m6-cp3-tb155-census`. It was pending because the durable dispatcher serializes work on the same branch without cancellation.
- The latest durable dispatcher slot contains the census request. The gate request remains frozen in its earlier event commit; no second dispatch is needed.
- Independently compared TB154 census against TB151 baseline: each archive passed 9/9 hashes; all three normalized raw records and metadata matched under frozen N1–N4. This comparison is a baseline control, **not** TB155 runtime evidence.
- No direct source, test, fixture, selector, build or workflow logic changed in this turn. No CP3/selector497/D0/H4 promotion.

## Recommendation — resume this same turn

1. Obtain completed run records from ref `workflow-mailbox`: `.workflow-mailbox/m6-cp3-tb155-gate/latest.json` and `.workflow-mailbox/m6-cp3-tb155-census/latest.json`. If missing while a known run is active, use its recorded run ID and do not retrigger.
2. Verify terminal workload, artifacts, exact package/source, all internal checksums, resource limits and unchanged compile/relink/configure/benchmark flags. Retain raw logs.
3. Full gate requires 971/971 PASS, CP2 first 491 PASS, and all rows outside A = {644,645,648,669,686,698,858,963,966,968,971} MATCH TB154 N1–N3. Publish every A-row MATCH/DIFF and its first differing normalized line pair. Publish row 966 `SourcePieceCountOracle` verbatim.
4. Census requires 3/3 MATCH TB151 N1–N4, including `platform-digest`; no log may report `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge` or `FirstPieceNotLeavingLocusIntoFace`.
5. Replace this provisional record with actual verified evidence. Update tracker, handoff, TODO, changelog and cleanup under retention policy. Publish final STATUS as the **last repository action**. If the session time expires before evidence is complete, retain IN_PROGRESS with empty Ended at. Never start the authorized independent TB-REV-155 successor inside this turn.

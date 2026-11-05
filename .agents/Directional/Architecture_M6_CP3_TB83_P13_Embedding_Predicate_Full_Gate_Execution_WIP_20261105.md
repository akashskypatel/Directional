# TB83 — immutable execution continuation (2026-11-05)

**Canonical turn:** `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-EXEC`; Test + Benchmark, IN_PROGRESS. This is an execution/transport record, not runtime acceptance or promotion. Keep the existing `STATUS` start timestamp `2026-11-05T23:15:51Z` and current resumed timestamp. Follow RA-209.4, TODO step 48 and handoff. No build, relink, compile, source/test/fixture or selector change is authorized.

## Frozen authority

- Source: `11c8172ad467c6dc865f2f3352e75b78f5469a2b`, compile run [42124939141](https://github.com/akashskypatel/Directional/actions/runs/42124939141), package artifact `13460725846`, ZIP SHA-256 `3e4d356b1f7b25b388faa661db5ed67d28b23adbbda526cbbcbd2e0c0ef5cfdf`.
- Root manifest SHA-256 `a3ee1c064ada979a01c725bc2d2f8655b5fdb0ef9b7ddcf4c193305877790d61`, package `28/28` checksum preflight. **Verified actual** packaged source archive SHA-256: `6905e76eac60f9bfdeaf46cfd76ee5564847e7b1bde6d4efe49def8093713cd9`.
- Frozen executor `7bbefa88926dd329f38b7470c242f9c7c9514091`; harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Gate manifest `Architecture_M6_TB83_P13_Embedding_Predicate_Full_Gate_Case_Manifest.tsv`: 903, SHA-256 `61e9edbedee3731b04d7b6279b79a0fd0e0b651686638e9b832773f7aa0a36aa`; deferred ledger v5: 81, SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Membership target 984. Census manifest `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`: three fixtures; SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.

## Executions and preflight correction

1. Original gate request `m6-cp3-tb83-gate-20261105-v1` committed `43316f93689513812ceeff2da7c790246762bec0`. No terminal mailbox observed through the last check; do not equate missing publication with absent execution.
2. Original census request `m6-cp3-tb83-census-20261105-v1` committed `01d891d7a8d0474dd1e75cd2a381bd2a22ea9e96`; [run 42131377580](https://github.com/akashskypatel/Directional/actions/runs/42131377580) **failed infrastructure preflight** `ValueError: source archive mismatch`: 0/3 executed, exit 90, no runtime verdicts. Result artifact `13463890915`, dedicated logs `13464240367`, `13464115601`; checksummed output records the error. This is not a failing product test.
3. Cause verified against immutable package bytes: original `EXPECTED_SOURCE_ARCHIVE_SHA256` was mistyped `6905e76eac60b9bf…`; actual `6905e76eac60f9bf…` (character index 12, zero-based). Correcting the **request literal only** is authorized: no compiled bytes or gate expectations change.
4. Corrected gate request `m6-cp3-tb83-gate-20261105-v2` committed `24f2483d9e4a31ab17fb1d5f745aa17add090767`.
5. Corrected census request `m6-cp3-tb83-census-20261105-v2` committed `59ea0c45dee782d3b4047b65fe8defa968fcd3ce`.
6. Both v2 mailbox paths are on **ref `workflow-mailbox`** at `.workflow-mailbox/<request-id>/latest.json`. Neither had published a terminal record at the 2026-11-05 23:49 UTC observation. Do not blindly redispatch or infer success/failure from absence. The dispatcher has `concurrency: ... cancel-in-progress: false`; queued execution may be delayed.

## Required continuation

1. Obtain exact v2 run IDs and terminal jobs/artifacts using workflow-mailbox records. If absent, use the authorized bounded recent-runs fallback rather than duplicate unchanged runs.
2. For gate, verify 903/903, membership 984, internal hashes, individual raw logs, final postflight, and all RA-209.4 pinned digests. For census, verify Cylinder PASS; BunnyRandom expected P13-e vertex 49 RED; Vase RED under 600 seconds, zero `FlippedFace`, and exact prefix/suffix digest policy. Compare against TB82 authoritative artifacts `13429919548` (gate) and `13430164928` (census).
3. Record any mismatch/infrastructure cause independently; maintain stable CP2 491/491, 66/17/49 events/categories/recurrences, debt 1; selector497/CP3 unpromoted.
4. Only after runtime evidence: update owning TB83 report, regression tracker, TODO, handoff, CHANGELOG; run drift audit, permitted cleanup including temporary source-snapshot trigger `.agents/connector-triggers/source-snapshot/tb83-20261105-2317.txt`, and publish `STATUS` last. Semantic mismatch routes to `M6-CP3-TB83-P13-EMBEDDING-PREDICATE-FULL-GATE-REV`; infrastructure to `M6-CP3-TB83A-P13-EMBEDDING-PREDICATE-ORCH`. Do not begin successor work during TB83.

# TB137 P13 departure-chord crossing receipt — execution checkpoint (IN_PROGRESS)

## Situation

`M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-EXEC` remains the current turn. Entry beacon commit `442c0f1a4738fca93d259ee7152ee99ab030c0df`, first entered 2026-11-18T09:57:01Z. No successor work. PR #8 remains draft, open and unmerged.

## Background — verified immutable authority

[CB160 record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md) and [RA-258 S4](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc) govern this turn. Source and executor `66fb0c5ec42fa57614a504437724b18d7004cbb1`; package `14414860103`, ZIP `8b2277e9e5ac2fc71ffe4e61a6012e5ac892f2a92c0f03b24613d695437aaec2`, root manifest `2946a306b0f9d6d655188d5fcaf2ad9f7433d2a075e96ee85d818b82639e0b1e`, source archive `30dc5fad7dfb3f9eaf097c62d4eff8a0125faecb958461c52a7eee36e9671911`. 28/28 checksums, six archived executable modes, five empty source status files, eight targets and GMP/GMPXX verified. Snapshot run 44280817854, artifact 14416342764, source `a76e728b9aa2f15430051e7afb4a32e072af6a6c`, ZIP `248a14867359010f2adbb293af6686276b646d6f1768b0b8c6402810f4206712`: 5,556 checksum checks passed; 515/515 checked source/test/fixture/tool/workflow files agree with package. Frozen gate 955 (membership 1,036 including 81 deferred); census 3. Manifest-only checks and 16/16 offline comparator checks passed. No candidate binaries executed locally.

## Assessment — exact submitted requests (do not redispatch)

| Role | Event commit | Mailbox key |
|---|---|---|
| Gate | `6eb87284f2aef7cb53e9d9e7440de31152514f94` | `m6-cp3-tb137-gate-v1` |
| Census | `9c15ecec7045b6074c4fe95e45cd8acd13cece15` | `m6-cp3-tb137-census-v1` |

Both exact requests are committed, their content blob hashes match local generation, and the dispatcher serializes them on this branch. No source, test, fixture, harness, package or workflow definitions changed. Baseline TB136 gate `14406791564` and census `14406826878` verified against their digests, membership and all raw log bindings (957 rows, 1,925 checksums). Local comparator applies N1–N4 and N5 (strip only complete lines beginning `FieldAlignedCurveNetwork.departureChordCrossing `); verifies other receipt bytes, row 955 PASS, counts per row and distinct crossing records, and existing departure counts. No count is predicted. Offline checks do not establish runtime results.

Terminal gate publication was absent at the last check. No runtime verdict, regression disposition or candidate acceptance is established. No duplicate request.

## Recommendation — resume TB137 itself

Read `.workflow-mailbox/<key>/latest.json` on orphan ref `workflow-mailbox` only; verify event/source SHA, jobs, result and log artifact digests. Do not rerun requests solely because final publication is absent. Compare verified candidate archives against TB136 per RA-258 S4, report all crossing/departure counts and mismatches. Preserve fixture failure classifications and stable 66/17/49, debt 1, deferred 81, CP2 491/491 until measured authority changes them. No CP3/D0 promotion. Close only after terminal runtime evidence is recorded, tracker/TODO/changelog/handoff updated, and current snapshot marker `.agents/connector-triggers/source-snapshot/tb137-20261118.txt` cleaned. The Library file `Directional/Directional_TB137_resume_20261118.zip` (SHA-256 `bf5969c930b9bc10369f3fb9089e2fddbca34dd7ac8648b5501b2fdaeb232d9d`) contains exact requests, baseline archives, comparison code, input manifests and current evidence. Route per RA-258 S4 only after complete verification.

Procedure limitations: direct reads preceded explicit snapshot mode; full mandatory start policy/skill review not confirmed; skill fetch returned 404; deadline file started late and no timer callback demonstrated (absolute deadline used); tool-call ledger incomplete. No successor work, new stable regression claim, or runtime verdict based only on offline checks.

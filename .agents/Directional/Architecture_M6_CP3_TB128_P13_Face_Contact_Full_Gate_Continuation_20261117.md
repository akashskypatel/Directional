# TB128 — same-turn continuation (2026-11-17 UTC)

## Situation

Canonical turn `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` remains incomplete. Original start: 2026-11-17T09:40:14Z. Two artifact-only execution request commits exist. Gate completed with a verified mismatch at 09:54 UTC. Census completion mailbox is not yet available. Do not start successor work or duplicate either request before observing its matching event.

## Background — immutable authority

- RA-249 §4: [face-contact freeze](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md). Existing handoff and TODO authorize TB128. This continuation is supplementary, not a successor plan.
- Entry commit `345190f53ef836a136bd379b4dd4fe55c7b6d1c2`; executor `93f53bcd82e96e0e3163a75304e197191287999c`; snapshot run 44057997668, artifact 14315764471, ZIP SHA-256 `9b037e9d215d92969fd5b41cb7a863124658c75121c477d9320e44ce8f883d53`; 5,523/5,523 file checksums verified.
- CB149 immutable package 14315237769, source `85f9c703c5de86fb2b401cf83c03499a1ce73a27`, ZIP SHA-256 `39ce6f17ed010d26bf3e65dace9100646fc215a3a8050bb8cae6d621dfb23926`, root manifest `9d2953d707eeaf72323dc0b7db6d28a4889bf0381128b2f105ca66a7bca8c661`, source archive `b7a13ebccc299a3cb98bde7471c2e678b1a0ddd3e31e5d96e4f3e1d8e506fdf9`. All 28 listed hashes verified, five empty source-status receipts, six archived executable modes 0755, GMP/GMPXX linkage, runtimeExecution=false. Packaged src/include/tests/benchmarks fixtures match the executor tree. No local build or product runtime execution.
- Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- The frozen 953-row gate SHA-256 `941287fa96f3432eb1d67a9ae1e5dc7bc0ca2f3a1775cd5f9fb35482a4fa7962` contains the inherited 951-row manifest as a byte prefix. Census SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` (3 cases); deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 cases). Both harness manifest self-checks passed, not runtime results.
- TB127 comparison gate 14302887671, ZIP SHA-256 `017ad5589ae533d4f428312bc59d92409906544f6cd1add1a3db0ccc80383050`, 1910/1910 hashes. Census 14302668940, ZIP SHA-256 `4edf0fe64c45fac424eb0c8ef9ed4e9eaae675373e32f06724df9ea4724f3cc5`, 9/9 hashes. Baseline archive inventory, raw-log bindings, manifest and execution-boundary evidence verified independently. Package 14301616031, source `48e6f97d278b2226036f658ce9060a38b8a374b5`; gate 951/951, census Cylinder PASS 288, BunnyRandom and Vase RED.

## Assessment — remote dispatch

| Request | Event commit | Request blob | Mailbox key |
|---|---|---|---|
| Gate | `e30b44b8c3e4c973b7ed36362da5f62c896fd002` | `e6f3249575b76892c8e1a342e1b03897ddc1bb4e` | `m6-cp3-tb128-gate-v1` |
| Census | `244ce261ac99fdd14240186074e9316533ecb84b` | `a152c12bc96644b439d769641efba1e9d2bbbd3b` | `m6-cp3-tb128-census-v1` |

Both request postimages verified at their event commits. Census submitted second under serialized dispatcher concurrency; census run start/completion is not yet verified. Gate execution completed. Do not submit a third dispatcher request while either is pending. The direct collection query for push runs was unavailable; this is not a runtime verdict.

Cleanup run 44059234357 succeeded; trigger `f2fbeebcc15db911834c631b353fb4bf965481ea`, cleanup commit `f318f57eecfb948626fdfdcb69fe45e4bf6d2706`, result 14316553374, log 14316807941. The current snapshot trigger and cleanup manifest are absent; the census dispatcher slot is retained. Unrelated legacy trigger files remain. No source, test, fixture, selector or workflow change. Stable counts 66/17/49; debt 1, deferred 81; CP2 491/491 accepted; CP3/selector497 unpromoted. C5/O42/O43/O45/O46 open.

## Recommendation — resume this turn

1. Update entry STATUS for this same turn, preserve original Started at. Read both `.workflow-mailbox/<key>/latest.json` from the orphan ref `workflow-mailbox`; verify event commit. If absent, diagnose via approved observation path; do not assume failure/start or rerun blindly.
2. Retrieve completed jobs, result and log artifact IDs and exact digests. Verify each result archive, internal inventory, raw log checksums, source/package/manifest bindings, membership, execution boundaries and valid postflight. Gate result IDs are recorded below; census IDs remain unknown.
3. Apply RA-249 §4: 953/953 PASS, 0 skips; membership 1,034; inherited rows 1–951 ledger-identical, raw logs match except permitted time and fragment diagnostic newline framing. Cylinder PASS 288; Cylinder/Vase census logs identical except ms timing and gtest GetParam byte dumps; assertion line numbers unchanged. BunnyRandom receipts before terminal and all four inventory lines identical; record terminal verbatim. Forbidden reasons and rotation-edge falsifier are defined in RA-249 §4. No inferred outcome. The local continuation archive contains the verified baseline ZIPs, frozen manifests, request JSON and standalone read-only comparison helper; baseline-only helper execution passed, candidate evaluation remains unverified. Manually adjudicate the Bunny receipt diff using complete raw logs.
4. Finish owning execution report, tracker, handoff, TODO, CHANGELOG and document audit; dispatcher documentation patch only after both execution requests are terminal. The 13,508-byte handoff requires patch transport, so it is unchanged at interim yield rather than risk cancellation of a pending execution with a third dispatch request. No promotion.
5. Route only from verified evidence: MATCH => `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME`; mismatch => `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV`; infrastructure failure => `M6-CP3-TB128A-P13-FACE-CONTACT-FULL-GATE-ORCH`. End TB128 before any routed work.

## Gate completion evidence (09:56 UTC)

Gate mailbox matched event `e30b44b8c3e4c973b7ed36362da5f62c896fd002`, run [44058536482](https://github.com/akashskypatel/Directional/actions/runs/44058536482), runtime job 133954329592. Workflow concluded failure, both schema validations and request parsing succeeded. Result 14318100443, ZIP SHA-256 `e208416775f474f75d79ec76697ed19d643a121d8ad086cd37b8f3a330436e5d`; log 14317048253, ZIP SHA-256 `1b82c8da70be331f3753b5ae864d2a7b17cd04dc14771cad04fd42f64e1a780e`. Both ZIP digests match the mailbox. The result passed all 1,914 file hashes, all 953 row/log bindings and frozen membership 1,034 (953 gated/81 deferred); valid postflight, no compile/relink/configure/benchmark. 953 executed, 951 PASS, two RED, zero skipped/missing/abnormal/duplicate. Harness exit 90, required controls failed. This is a verified gate MISMATCH, not infrastructure failure.

- Row 858, inherited `SurfaceCellTracingDisplay.StopLocationShowsWhatEachStageReported`: previous PASS, now RED. `SurfaceCellTracingDisplayTests.cpp:155`, `faceLocus.sourceFace.has_value()` is false; surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent.
- Row 952, new `FaceChartExactGeometry.OrdersRaysAndContactsExactlyAroundAFaceInteriorPoint`: RED at `FieldAlignedCurveNetworkTests.cpp:18783`, `sameDoubles(towardB, nearB)` false. Row 953 new `FaceContactNode.SplitsAStruckSegmentAtAnExactInteriorContactPoint` PASS.
- Inherited ledger differs at row 858 only (950/951 substantive fields identical). Comparator found non-permitted normalized raw-log differences at rows 164, 644, 669, 698, 858. Permitted framing differences at 168, 173, 177, 195, 477, 705. Rows 644/669/698 report changed rotation reason from TraceEventPositionInvalid to ArcTraceTerminalCutPositionMismatch. Full comparison output and original logs are preserved; independent root-cause classification remains open. No tracker promotion or stable count change.

Do not repeat the gate. Retrieve census when terminal, then complete TB128 report/tracker and handoff closeout. Gate mismatch requires the frozen mismatch route after remaining evidence/closeout; do not start that Review until TB128 is formally complete.

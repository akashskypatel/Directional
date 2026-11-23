# TB-EXEC-176 — immutable full-gate execution (in progress)

## Situation

Canonical turn `M6-CP3-TB-EXEC-176-P13-PIECE-BUILDER-AND-ORDERED-RETRACE-FULL-GATE` is **IN PROGRESS**. The immutable test-and-benchmark operation was dispatched. As of 2026-11-23T20:54:00Z, the terminal workflow mailbox has not been published. **No TB176 runtime result, test count, accepted comparison, or pass/fail verdict is claimed.** Do not start the separate TB-REV-176 review until this turn is closed.

## Background — frozen evidence

- Repository: `akashskypatel/Directional`; source branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open and draft.
- Immutable semantic source: `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`.
- GMP/GMPXX compiled package: artifact `14859356205` from run `45255304770`; outer SHA-256 `e6111ff21530f107ab8b1db724155aa2c4fbbe4a2765342fbfabbd4a9c4fc664`. Independently downloaded and checked; 28/28 internal checksums valid. Package metadata: source archive SHA-256 `44f478b25abf63f79d77b2c84fd0e3b70bd61b259f3c6323a377daf93cab278f`; root manifest SHA-256 `4d6523cc38f6a5051f44589eae6a42016a61fe8b1f1831a6dc381ba414cc3c26`; compilation boundary `runtimeExecution=false`.
- Frozen 1,001-case gate manifest: `.agents/Directional/gates/Architecture_M6_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Case_Manifest.tsv`; SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`; first 1,000 entries byte-equivalent to TB175. Deferred membership ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; predicted 1,082 total members (1,001 gated plus 81 deferred).
- Immutable TB175 reference: run `45233825958`, result artifact `14849271506`, SHA-256 `be7a0f783d0afb025ccee2353921a765c340766340553f2d70b4b5c32992b347`. Downloaded and verified 2,008/2,008 checksum entries; recorded result 993/1,000 PASS plus seven known RED.
- Source-snapshot run `45262742839` fetched exact commit `a523df11e8a7b19b070aa0463df0df564d03994b`; ZIP artifact `14861835422`, SHA-256 `947af3ac4ced492ed108e06c429d3a9b0fac8f36a32790cd9d171353012c3459`; extracted source archive SHA-256 `c73e94c9aacd7efcee350ee5c08809c4db9cfc27605f2941b972d8d57529adca`.
- Test harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.

## Assessment — active operation

The validated `test_benchmark` request was written to the durable `.agents/Directional/agent-dispatch-request.json` at commit `a8ca498eaf18dd370d1e7eaec0332ab24a01da74`. Request ID `m6-cp3-tb176-exec-20261123-a`; mailbox key `m6-cp3-tb176-piece-builder-ordered-retrace-full-gate`; executor SHA `a523df11e8a7b19b070aa0463df0df564d03994b`. This request must not be dispatched a second time merely because the final mailbox is not yet present.

A source-read procedure miss occurred: repository files were read through the connector before the required snapshot-mode gate. This was recorded and corrected by taking one exact workflow snapshot. No semantic source, tests, selectors, fixtures, workflows, or binaries were changed in this test turn. The snapshot trigger and request file are control-plane changes only.

## Recommendation — resume the SAME turn

1. Read the authoritative terminal mailbox at `.workflow-mailbox/m6-cp3-tb176-piece-builder-ordered-retrace-full-gate/latest.json` on orphan ref `workflow-mailbox`. Validate the request event SHA `a8ca498eaf18dd370d1e7eaec0332ab24a01da74`, semantic source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`, and successful artifact publication. If not yet present, allow the existing workflow to complete; do not issue a duplicate request.
2. Use its run ID to fetch jobs and artifact inventory once; download the immutable result. Verify outer and all internal hashes, execution boundary, exact 1,001 executions, 1,082 membership, no rebuild/mutation, and all seven historical RED sites.
3. Compare every one of the first 1,000 raw process logs and ledger fields against TB175. Permit only N1/N2 timing and line-ending variation and N3 whole-record reorder of the exact 24 row-179 fragment records. Validate new row 1001 separately. The predicted 994 PASS and seven RED is not evidence.
4. Record actual result, historical regression classification, independent comparisons, artifacts and hashes in this report, `Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`, and `Future_Chat_Session_Handoff.md` as required. Carry out temporary trigger cleanup and the document-drift audit. Do not start TB-REV-176.
5. Direct-write repository-root `STATUS` as the final repository action, `COMPLETE` only once the execution and closeout evidence are verified; otherwise keep the same turn `IN_PROGRESS`.

## Verified workflow and temporary-state cleanup (same turn)

- [Run 45263429563](https://github.com/akashskypatel/Directional/actions/runs/45263429563) was confirmed **in progress**. Event SHA `a8ca498eaf18dd370d1e7eaec0332ab24a01da74` matches the request. Validator and parser jobs passed. Runtime job `138004160862` reached `Execute immutable artifact-only gate` and remains unverified until terminal output. Compile and Drive-apply jobs were skipped.
- Cleanup [run 45264413782](https://github.com/akashskypatel/Directional/actions/runs/45264413782) completed successfully at commit `1e1de5ba04e67b8c337dc483c7f9364369bad848`. Artifact `14862695525` confirms removal of the sole TB176 temporary snapshot marker and `runtimeExecution=false`; the durable dispatcher slot and orphan mailbox were not listed for deletion.
- Continue this SAME turn from its running process. Do not trigger the same test again merely because the terminal mailbox is pending. A response timer does not establish runtime success or failure.

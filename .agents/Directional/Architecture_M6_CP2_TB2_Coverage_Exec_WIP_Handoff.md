# M6-CP2-TB2-COVERAGE-EXEC WIP handoff

Turn remains **IN_PROGRESS** because the immutable artifact-only runtime is still executing.

## Fixed authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Candidate compile artifact: `11391685901`
- Candidate semantic source: `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`
- Candidate artifact provider SHA-256: `d2a3ef4f2bf40420fba21155bb264a8271c36ce18c41bc31a5e191af93739980`
- Required execution cardinality: focused30 + focused12 + selector449 = **491 fresh exact-filter processes**
- Benchmark execution: forbidden / expected count 0.
- No configure, compile, relink, discovery, package repair, mode repair, source/test/fixture/selector mutation, or local Directional runtime is authorized in this turn.

## Active execution

- Caller: `.github/workflows/m6-cp2-tb2-coverage-exec.yml`
- Harness: `.agents/Directional/turn-payloads/m6-cp2-tb2-coverage-exec-artifact-only-harness.sh`
- Trigger marker: `.agents/connector-triggers/m6-cp2-tb2-coverage-exec.txt`
- Trigger/event SHA: `5c136917d09c731515b94cd867a4aecec2f46c43`
- Workflow run ID: `37419256039`
- Runtime job ID: `112124748161`
- Validation job completed successfully.
- At the final observation of this attempt, runtime step `Execute immutable artifact-only gate` remained `in_progress`; result/log uploads had not started.
- Primary mailbox `.workflow-mailbox/m6-cp2-tb2-coverage-exec/latest.json` had not yet published. **Do not retrigger.**

Run discovery came from the authorized recent-runs fallback. Fallback run `37421131211` and artifact `11393391338` identified the exact primary run above. The temporary fallback caller and marker were retired after their evidence was verified. The primary caller/harness/marker are intentionally retained until the primary runtime terminates and its evidence is captured.

## Exact resume procedure

1. Read `.workflow-mailbox/m6-cp2-tb2-coverage-exec/latest.json` first.
2. If it has published, verify event SHA `5c136917d09c731515b94cd867a4aecec2f46c43` and source SHA `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`, then use its run/artifact IDs.
3. If the mailbox is still absent, query jobs for already-known run `37419256039`; do not launch another recent-runs fallback unless the known run becomes unavailable.
4. When terminal, fetch the runtime job log once and reconcile the run artifact inventory once. Download each required result/log artifact at most once.
5. Verify the result evidence: exact artifact/source authority, executable mode preservation, pre/post package and source immutability, frozen selector/routing hashes, exact-one selection with zero skips, 30 + 12 + 449 = 491 executed processes, benchmark count 0, and complete self-excluding result manifest.
6. Categorize every observed RED/regression in `Regression_Root_Cause_Tracker.md` before closing the Test + Benchmark turn. If no stable regression change is justified, record that explicitly.
7. Write the TB2 durable report/handoff/TODO/change records from verified evidence only.
8. Cleanup workflow-first: delete the temporary primary caller first, then remove its marker and temporary harness/control state while preserving mailbox history and immutable Actions artifacts.
9. Complete to the repository-authorized Review successor only after all TB2 evidence/documentation/cleanup gates pass. Otherwise remain in this same turn.

No local build, test, benchmark, or Directional binary execution occurred during this attempt.

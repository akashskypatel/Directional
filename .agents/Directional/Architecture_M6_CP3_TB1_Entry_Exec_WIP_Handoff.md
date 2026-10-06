# M6-CP3-TB1-ENTRY-EXEC WIP handoff

Turn remains **IN_PROGRESS** because the immutable artifact-only runtime is still executing.

## Fixed authority

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Candidate compile artifact: `11411137781`
- Candidate semantic source: `912760f1ffc785676f5d50717177b1cd8be69234`
- Candidate provider/download ZIP SHA-256: `704b1b70c9fd67aca95c78757c84433b97122fad6524f14326312131d3307234`
- Candidate root `SHA256SUMS` SHA-256: `f1e0fefb72df8f8e4175cda5d0cd1f05ab8fc94b29d8250a960e6de3d6f8b153`
- Packaged source archive SHA-256: `bf0f21a8899cc5a078a9c02761d18836be728df403b7d200226d7f39b4620e67`
- Required execution cardinality: focused30 30 + focused12 12 + selector449 449 + CP3-entry 6 = **497 fresh exact-filter processes**.
- Benchmark execution: forbidden / expected count 0.
- No configure, compile, relink, generated discovery, package repair, mode repair, source/test/fixture/selector mutation, or runtime retry is authorized.

Local preflight reused the already-downloaded immutable compile package, verified the provider ZIP digest, root manifest **28/28**, exact source, GMP/runtime boundary, source-archive digest, and archived executable mode 755 without executing any Directional binary.

Frozen inherited authorities remain:
- focused30 SHA-256 `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`
- focused12 SHA-256 `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`
- selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`
- routing449 SHA-256 `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`

The six CP3-entry identities execute last, in frozen RA-30 order, all through `directional_surface_cell_producer_tests`.

## Active execution

- Caller: `.github/workflows/m6-cp3-tb1-entry-exec.yml`
- Harness: `.agents/Directional/turn-payloads/m6-cp3-tb1-entry-exec-artifact-only-harness.sh`
- Harness Git blob: `9b3af54aae9b310d3385d572c5599c14f5c68c35`
- Trigger marker: `.agents/connector-triggers/m6-cp3-tb1-entry-exec.txt`
- Trigger/event SHA: `017304d1988471af3eba312cbdc6ac3c2cd78b1a`
- Workflow run ID: `37464309062`
- Validation job: `112271359585` — SUCCESS.
- Runtime job: `112271440079` — IN PROGRESS at bounded-response closeout.
- Runtime step `Execute immutable artifact-only gate` is in progress; result/log uploads and mailbox publication have not started.
- **Do not retrigger.**

Snapshot inspection authority for this attempt was run `37463558172`, exact snapshot SHA `d4afd48a97d3f686ccec34e92d6cde940d95fd50`, artifact `11413816630`, provider/download SHA-256 `e954599a7011b4305edfe62a1ea95f90246443354b339b66e7989ca305bd9894`.

## Exact resume procedure

1. Read `.workflow-mailbox/m6-cp3-tb1-entry-exec/latest.json` first.
2. If it has published, verify event SHA `017304d1988471af3eba312cbdc6ac3c2cd78b1a` and source SHA `912760f1ffc785676f5d50717177b1cd8be69234`, then use its run/artifact IDs.
3. If the mailbox is still absent, query jobs for already-known run `37464309062`; do not retrigger.
4. When terminal, fetch the runtime job log once and reconcile the run artifact inventory once. Download each required result/log artifact at most once.
5. Verify exact artifact/source authority, executable-mode preservation, pre/post package/source/execution-view immutability, all four inherited hashes, exact-one selection and zero skips, exactly 30 + 12 + 449 + 6 = 497 processes, benchmark count 0, and the complete self-excluding result manifest.
6. Categorize every RED/regression before closing EXEC. Mechanical GREEN remains unpromoted until mandatory Review.
7. Write the durable TB1 report/handoff/TODO/CHANGELOG from verified evidence only.
8. Cleanup workflow-first after terminal evidence is preserved: delete the temporary runtime caller first, then its marker and harness. Also retire the completed source-snapshot trigger marker. Preserve mailbox history and Actions artifacts.
9. Complete only to `M6-CP3-TB1-ENTRY-REV` after all execution/evidence/documentation/cleanup gates pass. Otherwise remain in this turn.

No local Directional runtime was executed during this bounded response.

# M6-CP3-TB1-ENTRY-R1-EXEC WIP handoff

Turn remains **IN_PROGRESS** because the immutable artifact-only runtime is still executing.

## Fixed authority

- Semantic package source: `68000a95a94b1d95f22694dc093dc6a538e1b7b4`.
- Compile package artifact: `11488700954`; provider/download SHA-256 `a26311563d92e9fce6932f034fc870bc285ca63482457bf8b39c359569f1496b`.
- Package root `SHA256SUMS` SHA-256: `b08171e974b3acb1871becf63cb554acfab505a7c1753014a7dd5bffc211d9f7`.
- Packaged source archive SHA-256: `54b46890f24a45f663c0180b2667349e68d6df22765a3883e8cc7f8dd386ce42`.
- Frozen focused30/focused12/selector449/routing449 SHA-256 remain `1e815443a03c7ef4a1b095e6ea973efa9c74bb0eae4e2f872510c97d057ea1d6`, `2aa57aac48ac8c41ea86ed459cdd1acd27eb17c8d3dbe1b4ac7b9c54c67374ed`, `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`.
- Required gate: exactly 497 fresh exact-filter processes = focused30 30 + focused12 12 + selector449 449 + six CP3-entry identities; exact-one selection, zero skips, benchmark 0.
- RA-31a acceptance target is 496 PASS plus only identity 2 RED at its withdrawn-certificate assertions; any other RED remains Review-owned evidence.

## Durable dispatcher execution

- Durable generic harness: `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh`.
- Harness installation commit/executor SHA: `0a402104d7d82166fbf451ae8df44301f46f31b3`.
- Harness SHA-256: `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`.
- Durable request commit/event SHA: `801ca2c70ed172c9d4e758833db411514cc5cd78`.
- Request SHA-256 before commit: `f63e36516f0d42e3862df420f1d906a91989d8135400eff081ce4e2401f3d1eb`.
- Dispatcher mailbox key: `m6-cp3-tb1-entry-r1-exec`.
- Actions run: `37645974118`; runtime job: `112876903729`.
- Dispatcher schema validation, TB reusable schema validation, and request parsing are GREEN.
- At bounded-response closeout, `test_benchmark / runtime` is still in `Execute immutable artifact-only gate`. Do not retrigger.

## Exact resume procedure

1. Read `.workflow-mailbox/m6-cp3-tb1-entry-r1-exec/latest.json` first.
2. If absent, query already-known run `37645974118`; do not retrigger.
3. When terminal, verify runtime job/artifacts and download result/log artifacts once.
4. Verify exact 497-process coverage, exact-one 497/497, zero skips, benchmark 0, immutable pre/post package/source/execution-view censuses, root manifest, frozen gate hashes, and no configure/compile/relink/discovery/repair/retry.
5. Categorize every RED in `Regression_Root_Cause_Tracker.md` before closing. Do not promote semantic acceptance in EXEC; mandatory Review owns adjudication.
6. Update the durable TB report/TODO/CHANGELOG/handoff from verified evidence only.
7. Cleanup the completed source-snapshot trigger `.agents/connector-triggers/source-snapshot/tb1-20261007-1532.txt` and any other temporary state while preserving dispatcher request/mailbox history and durable harness.
8. Complete only to `M6-CP3-TB1-ENTRY-R1-REV`; otherwise remain in this turn.

No local Directional runtime was executed.

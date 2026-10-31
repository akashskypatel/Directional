# M6 TB62 immutable Linux CLI/GUI full gate — execution continuation (2026-10-31)

**Canonical turn:** `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` — **IN_PROGRESS**. Entry `Started at: 2026-10-31T13:24:00Z`; latest `Resumed at: 2026-10-31T14:10:16Z` (preserve the original entry time on future resumptions). Remain on this turn; **do not start P13 or declare gate acceptance** until a terminal, authenticated, independently reconciled full-gate result is available.

## Verified immutable authority
- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open draft, unmerged.
- CB63 Linux ten-target immutable package: Actions artifact **13043004468** from run **41202931582**, exact source `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`, ZIP SHA-256 `14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`. This turn downloaded the exact artifact, verified the outer digest and all **30/30** inner checksums. CMake Release, static, GMP, CLI ON, GUI ON; both executables and generated GMP/GMPXX CLI/GUI links confirmed. GUI **not launched** and visible appearance **not certified**.
- Executor snapshot trigger `d34ed7b33754e5138db2310b248c6b2e449e422a`, snapshot run **41205433325**, artifact **13043757812**, ZIP SHA-256 `5ce140371baeac4ab8a3cc3824997981d373186a507d169015bd3c3f7f2a14c6`. Verified **6043/6043** source-tree checksums.
- Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`, `--self-check` 863 cases + 82 deferred passed, `--self-test` 30 cases passed. Frozen case manifest SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`; deferred ledger v4 SHA-256 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`; expected total membership **945**.

## Remote execution dispatched — pending result
- Updated durable `.agents/Directional/agent-dispatch-request.json` once, request id/mailbox `m6-tb62-linux-cli-gui-full-gate-20261031-v1`, trigger commit **7f05935047f3f1b5e7b5a134ac8d5b2e65dc7c43**. The request binds frozen source, executor, exact harness, package, hashes, manifest and ledger without mutation flags. No compilation, relink or CMake configuration requested.
- GitHub Actions run **41205693716**: https://github.com/akashskypatel/Directional/actions/runs/41205693716. Verified both reusable workflow schema jobs and request parse **SUCCESS**; runtime test/benchmark job **IN_PROGRESS** as of 2026-10-31T13:35Z; compile/drive_apply/noop **SKIPPED**. **No 863-case test pass/fail count or semantic acceptance can yet be claimed.**
- Final mailbox to read after completion: `.workflow-mailbox/m6-tb62-linux-cli-gui-full-gate-20261031-v1/latest.json` on ref **`workflow-mailbox` only**. Earlier read during active execution returned 404 (not published yet); do not duplicate-dispatch or treat it as a failure.

- **Additional continuation check at 2026-10-31T14:11Z:** run 41205693716 remains `in_progress` with the same `Execute immutable artifact-only gate` step active, and the final mailbox remains unpublished. This is still the same un-retried dispatch; no execution verdict or postflight is available. The prior comparable TB61 Linux full gate ran for approximately 71 minutes, so this duration alone is not a diagnosed orchestration failure. This update adds no semantic result or new regression. The exact current-session resume checklist is also emitted as a user-downloadable Markdown file.

## Supplementary Linux CLI runtime — independently executed without rebuild
- Existing registered three scenarios were executed directly in the local Linux container against the exact packaged `bin/directional`, separate from the 863-case remote gate:
  - A retention plus diagnostics prefix: exit 1 with *pre-existing DR4* triangle OBJ shape error; produced `out.obj`, `plane.degrees.dmat`, `plane.materialization.txt`.
  - B diagnostics prefix only: same known exit 1/DR4; `out.obj`, `plane.degrees.dmat`, no materialization file.
  - C retention only: exit 0, output mesh only.
- All **11/11** registered check assertions passed; the A materialization dump includes A5/A6/A7 headers and exact count tuple **256 occurrences / 224 relations / 81 classes / 81 vertices**, 645 lines. JSON report SHA-256 `9d0b5c87f122b4e3b4111579010951d148f32ef3146d025cb32425b888844313`; diagnostic dump SHA-256 `eb68e44bf5d69692dc79966431fdf3f391d843a3867d8dbe6f05e8feda46f83a`. Raw logs, sidecars and checker are preserved in the conversation download archive, not in this repository. This does not replace the mandatory remote gate or its postflight.
- No source, fixture, selector, test assertion, compiled artifact or build-logic mutation during this TB turn.

## Required exact continuation
1. Resume **same** canonical TB62 turn in `STATUS`, preserving `Started at` and setting fresh `Resumed at`. Re-read handoff, TB62 plan, workflow and cadence policies.
2. Fetch the expected **terminal** mailbox on orphan `workflow-mailbox` ref; verify request/event/executor/semantic SHA, numeric run id, conclusion and artifacts, then fetch relevant job metadata and artifact inventory once. If not terminal, continue this turn without duplicate dispatch.
3. Once terminal, download result and required logs once. Audit source + archive hashes, 863 distinct gated process results against frozen manifest, 82 deferred entries, membership945, row283, exit codes, mutability boundary and postflight. Preserve all RED/abnormal evidence and independent 11 CLI checks; distinguish known deferred DR4 from newly produced regression. GUI link evidence is **not** appearance validation.
4. If semantically RED, route per `Turn_Cadence.md` to independent Review + Plan; if orchestration failed, preserve invalid-attempt evidence and route to corrective control-plane CB. A successful TB still needs authoritative coverage adjudication before conditional P13. Do not promote CP3/selector497 from dispatch.
5. Update owning execution report, `TODO.md`, `CHANGELOG.md`, regression tracker as appropriate, live handoff and cleanup while preserving original evidence. Commit evidence/updates before **final** `STATUS` direct-write, which must be the last repository mutation.
6. Snapshot trigger marker `.agents/connector-triggers/source-snapshot/m6-tb62-20261031-1324.txt` remains for eventual policy-governed cleanup. Existing `agent-turn-cleanup.yml` comment-deletion risk is noted in `TODO.md`; do not run unsafe automatic cleanup just to remove this marker.

## Unchanged accepted state
CP2 **491/491**; previous independent Linux eight-target TB61 **863/863** is not TB62; macOS O16 remains separately unresolved; stable **66/17/49**, debt **1**, selector497 unpromoted; PR #8 remains draft. Tool-call accounting was not reliably recorded from the first invocation and is therefore **partial/unknown**, not an invented exact count.

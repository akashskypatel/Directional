# M6-CP3-TB1-ENTRY-R1-EXEC WIP handoff

Historical WIP/recovery record. `M6-CP3-TB1-ENTRY-R1-EXEC` is **COMPLETE**; authoritative semantic evidence is in `Architecture_M6_CP3_TB1_Entry_R1_Artifact_Only_Test_Benchmark_Report.md`, and the mandatory successor is `M6-CP3-TB1-ENTRY-R1-REV`.

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


## 2026-10-07T16:18Z execution terminal / evidence closeout retry

- Artifact-only dispatcher run `37645974118` is terminal SUCCESS. Runtime job `112876903729` completed all steps successfully and published mailbox key `m6-cp3-tb1-entry-r1-exec` with event SHA `801ca2c70ed172c9d4e758833db411514cc5cd78` and semantic source `68000a95a94b1d95f22694dc093dc6a538e1b7b4`.
- Result artifact `11495166428` provider/download SHA-256 is `5ee8380ee7bb557a58274ef0b7cefa47e1abf1ef549650afcb7fff1330f161a6`; harness log artifact `11495391140` digest is `4feb512e507caa9236c4250b8e400b116db98ab930ebf2241385d7c78f10311d`; reusable wrapper log `11495850652` digest is `9c7ecb48f4696baa573f49dee0a36ee56e5b6350be6230174ff60cb0d96baffc`. Downloaded result self-manifest verified 1019/1019.
- Mechanical result is 497 total / 482 PASS / 15 RED: focused30 23/30 (RED ordinals 6,20,24,25,26,27,28), focused12 12/12, selector449 446/449 (RED ordinals 444,446,448), CP3-entry 1/6 (RED ordinals 1-5; identity 6 PASS). Exact-one selection and zero skips hold; benchmark count is 0. Package/source/execution-view censuses are unchanged; configure/compile/relink/discovery/repair/retry flags are all false.
- The 15 REDs are classified as EXEC candidate evidence only; stable tracker accounting remains 63 events / 17 categories / 46 recurrences / debt 1 pending mandatory Review. The prepared evidence patch records six candidate groups, with the 10 produced-torus/A6 rows tentatively the same prior RP-01 recurrence and CP3 identities 1-5 treated as separate candidate reachability/non-vacuity groups pending Review.
- Evidence-closeout patch is preserved locally and in Google Drive: `Directional__M6-CP3-TB1-ENTRY-R1-EXEC__evidence-closeout.patch`, full SHA-256 `605cc2f953788ed42bd7b7ef479552c378f077f2c865734f4bd889fc14aef748`, diff-body SHA-256 `f0bd404d38649fd55f555b7eda352197598d8c00856bdf382767dcc4173067b0`, exact base `13c926152ee0a5fdaf18ef8ccdf49859fe257099`, five intended paths. Drive File ID `12RK-oi5jQNwZqFOJFGCLtOOI3TcuSv3Z`.
- First durable `drive_apply` closeout run `37649560315` failed before apply because the patch had been uploaded to My Drive root and the workflow service account received Drive `files.get` HTTP 404. No repository patch commit occurred, and the Drive file was not trashed.
- Diagnosed correction: the same exact Drive file was moved into the established shared `Directional-CI` folder ID `1I_-EViWSpaxg69pbglfPPVnFRYb1s5O0`; patch bytes and File ID were not changed. Request identity alone was advanced to `m6-cp3-tb1-entry-r1-exec-docs-2` and retry commit `13f0796bc2c14dfb8eb5f99f63e2d86e7697eeda` triggered dispatcher run `37650733121`.
- At bounded-response closeout, retry run `37650733121` has both schema validators and request parsing GREEN; `drive_apply / apply-drive-patch` job `112893250854` is still in checkout. **Do not retrigger.** Resume by reading mailbox `.workflow-mailbox/m6-cp3-tb1-entry-r1-exec-docs/latest.json` and require its event SHA to equal `13f0796bc2c14dfb8eb5f99f63e2d86e7697eeda` before using it.
- After successful retry: verify Drive result artifact/applied commit and exact five-path diff; permanently delete Drive File ID `12RK-oi5jQNwZqFOJFGCLtOOI3TcuSv3Z`; remove temporary source-snapshot trigger `.agents/connector-triggers/source-snapshot/tb1-20261007-1532.txt`; verify hygiene; then complete EXEC only to `M6-CP3-TB1-ENTRY-R1-REV`. Do not perform Review in the same turn.


## 2026-10-07T16:39Z evidence closeout applied; cleanup control-plane defect

- Diagnosed retry request `m6-cp3-tb1-entry-r1-exec-docs-3` committed as event SHA `13775e9bc48582ce11b1cebd8db52a364d085f07`; no branch mutation was made while its Drive workload was active.
- Dispatcher run `37652300659` is terminal for the Drive workload and mailbox. Both schema validators and request parsing are GREEN; `drive_apply / apply-drive-patch` job `112898635728` is SUCCESS; mailbox publication job `112898905522` is SUCCESS. Authoritative mailbox event SHA is `13775e9bc48582ce11b1cebd8db52a364d085f07`, result `success`.
- Drive result artifact `11496504494` digest `sha256:53ec25226c9a84b6c5f854458bc118fcb2c6703c1db2931af2be0eefd0eaf84f` records applied commit `f1c2974a55869fc61a4a5db9db1f5820b7c8596f`, exact patch SHA-256 `605cc2f953788ed42bd7b7ef479552c378f077f2c865734f4bd889fc14aef748`, exact base `13c926152ee0a5fdaf18ef8ccdf49859fe257099`, `runtimeExecution=false`, and successful job status. Log artifact `11496389657` digest is `sha256:fe6525c44ad964069dc1ce8d0d37423ed0705d1b96b5996d3916941f18a4abc1`.
- Independent compare `13775e9b..f1c2974a` is exactly one commit and exactly the five intended documentation paths: the TB report, Future handoff, regression tracker, root CHANGELOG, and root TODO; 71 insertions, zero deletions.
- Owner-side Google Drive retirement completed successfully for File ID `12RK-oi5jQNwZqFOJFGCLtOOI3TcuSv3Z` after the reusable correctly reported `drive_file_retirement_required=true`.
- EXEC cannot yet close because mandatory turn cleanup is not safely runnable: durable `.github/workflows/agent-turn-cleanup.yml` still hardcodes the pre-dispatcher eight-workflow inventory and would reject the now-authorized ten-workflow durable set because `agent-operation-dispatcher.yml` and `agent-test-benchmark-reusable.yml` are missing from its expected list. Do not trigger this cleanup workflow unchanged.
- Exact remaining cleanup state is the source-snapshot trigger directory containing `.agents/connector-triggers/source-snapshot/m6-cp3-cb1-entry-r1.txt` and `.agents/connector-triggers/source-snapshot/tb1-20261007-1532.txt`; no legacy workflow-observation or turn-payload directory exists. Dispatcher request slot, durable harness, and all mailbox history must be retained.
- Next continuation of this SAME EXEC turn: choose READ_MODE before document inspection; correct only the cleanup workflow durable inventory to include the two dispatcher workflows, SchemaStore-validate the exact resulting workflow before executing it, then run manifest-driven cleanup for the two source-snapshot triggers, verify final hygiene, and complete EXEC to `M6-CP3-TB1-ENTRY-R1-REV`. Do not begin Review in the same turn.
- Procedural note: this continuation did not declare READ_MODE before its first multi-document direct reads. The miss was detected after policy re-read; no semantic source inspection or mutation followed from those reads. The next continuation must satisfy the pre-read gate before further repository-document inspection.


## 2026-10-07T17:02Z cleanup workflow mutation platform blocker

- This continuation correctly selected `READ_MODE=snapshot` before repository-document inspection. Source-snapshot event `8afdcff40f1f7b62884a003c9c211cd7d0452918`, run `37655353179`, snapshot artifact `11498328016`, provider/download SHA-256 `bde2cb544b3c009d215694ecfcd064180b2e1e5bfde340f48fc34326ab29a59c`, internal archive SHA-256 `496f2aea5e63863c6e3e42080fedcfff5d33528a3186fe06c81df4a0c48a361e`. Snapshot and SchemaStore validator jobs succeeded; the snapshot mailbox publication itself failed, so the already-known run/artifact IDs are the fallback authority for this snapshot only.
- The exact cleanup correction is prepared locally. It adds `agent-operation-dispatcher.yml` and `agent-test-benchmark-reusable.yml` to the cleanup workflow's durable inventory, plus a first `validate` job using `agent-workflow-schema-validator-reusable.yml`; the destructive `cleanup` job is gated on `needs.validate.outputs.valid == 'true'`. Local YAML parse/structural checks passed. Corrected workflow SHA-256: `8c9d2897d578e1c80632d1b62473e922d12aafd08aca453c0b6fa809c08eeec1`.
- GitHub connector mutation is a Platform blocker in this attempt. Direct Contents API update of `.github/workflows/agent-turn-cleanup.yml` returned an internal tool failure. The Git-object fallback also failed at blob creation, including UTF-8 and Base64 blob forms. A non-workflow draft-file creation carrying the exact corrected bytes likewise returned an internal tool failure. No workflow mutation landed.
- Work-preservation patch: `Directional__M6-CP3-TB1-ENTRY-R1-EXEC__base-8afdcff40f1f__work-preservation.patch`; full SHA-256 `e3cd4fb74b8aaf9df61566a208a2b84465afcb390d03aad80cb350ed515a9f1b`; diff-body SHA-256 `872722d6dce5df876a17b6404a28517c52cb34b930ef73a301df820a3b17e0f0`; exact intended path count 1. Fresh local `git apply --check`, application, content comparison, and `git diff --check` passed against the exact snapshot base.
- Preservation crossed both required durable boundaries: File Library ID `libfile_7e894c6cb5988191a8f3cbdac9f7a001`, and Google Drive `Directional-CI` File ID `1WwvHHQ5SwZDVUYIVSuKSHglOaMLq-mbs`. This Drive file is preservation-only and must not be dispatched through `drive_apply` because the patch touches `.github/workflows/**`.
- No cleanup manifest was created, no source-snapshot trigger was deleted, and no cleanup workflow was triggered. The remaining temporary trigger files therefore remain `.agents/connector-triggers/source-snapshot/m6-cp3-cb1-entry-r1.txt` and `.agents/connector-triggers/source-snapshot/tb1-20261007-1532.txt` (the latter was refreshed for this exact snapshot).
- Resume this SAME EXEC turn only after the GitHub content-mutation plane works: install the exact preserved cleanup-workflow bytes, require SchemaStore self-validation GREEN before the cleanup job, then create one cleanup manifest for both source-snapshot triggers, execute cleanup once, verify durable ten-workflow/request/mailbox hygiene, retire the preservation Drive file after the workflow bytes are durably committed, and complete EXEC to `M6-CP3-TB1-ENTRY-R1-REV`. Do not begin Review in the blocked EXEC turn.


## 2026-10-07T20:55Z final cleanup and blocker resolution

- The previously blocked cleanup-workflow mutation later succeeded exactly: `.github/workflows/agent-turn-cleanup.yml` commit `a95f1ac423928722ca171d914ef51c9c582f8abb`, blob `fcc4e333b44c1dc749fd0ebbedec52aa58ee2c33`. The corrected workflow contains the ten-file durable workflow inventory and a mandatory self-SchemaStore validation job that gates destructive cleanup.
- Fresh resume snapshot event `d9c3600c004dcae5352efb7d76a3c9535c50e2cd`, run `37684774111`, artifact `11510134482`, outer digest `sha256:ae56d8a769e030d29d1d7407a243a9fb7c2a98b47bd39275585a08d8ae2f35b3`, archive SHA-256 `f84253fff1894f5fd5733734de2829e4a5ea15763d077b5e28038752ad71d2e2`, file count 5574, `runtimeExecution=false`; local archive and 5574-entry manifest verification passed. The run's snapshot and validator jobs were GREEN; mailbox publication was not required for authority because the exact run/artifact were already known and verified.
- Manifest commit `36dccd8944a46542ed13b708d2cc3d526db17018` triggered cleanup run `37685543454`. Self-SchemaStore validation job `113012287199` and cleanup job `113012350640` are SUCCESS; mailbox publication is SUCCESS.
- Cleanup result artifact `11510569341`, digest `sha256:45a74761e28246228328456c8a8a7cafd6cbd4b2567bf27a77584405961f175b`, records cleanup SHA `5b6fd0f47c54171ffe039eaeb56e00a2981529db`, `runtimeExecution=false`, and exactly two removed paths: `.agents/connector-triggers/source-snapshot/m6-cp3-cb1-entry-r1.txt` and `.agents/connector-triggers/source-snapshot/tb1-20261007-1532.txt`.
- Final hygiene verification at branch head found exactly the ten durable workflows, retained `.agents/Directional/agent-dispatch-request.json`, retained cleanup mailbox history, and no `.agents/connector-triggers`, `.agents/workflow-observation`, or `.agents/Directional/turn-payloads` directory.
- Semantic closeout remains unchanged: 497 fresh exact-filter processes, 482 PASS / 15 RED, exact-one 497/497, zero skips, benchmark 0, stable accounting 63 / 17 / 46, debt 1. No source/test repair or retry occurred. Review owns adjudication of the six non-stable candidate groups.
- Exact successor: `M6-CP3-TB1-ENTRY-R1-REV`. Do not perform Review work inside this EXEC turn.

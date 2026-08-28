# Future Chat Session Handoff

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical blockers/lessons required to continue safely. Architecture belongs in `DESIGN.md` and `REORIENTATION_PLAN.md`; tasks belong in `TODO.md`; completed history belongs in `CHANGELOG.md`; current exact runtime evidence belongs in the retained latest report/closure records and regression tracker.

This section is durable. It may be corrected or extended, but it must not be deleted, collapsed into another section, or replaced by a summary without explicit user authorization.

All instructions and sections prefixed with `[ChatGPT Web]` are mandatory for all `ChatGPT Web` sessions and must be followed exactly as written.
All non-`ChatGPT Web` agents, i.e. `ChatGPT Work`, `Codex`, `Claude`, etc., can safely ignore any instruction or section prefixed with `[ChatGPT Web]`.

## `[ChatGPT Web]` Patch Application Strategy — DURABLE, DO NOT DELETE

Historical Directional turns show a consistent empirical GitHub connector write limit of approximately 10 KB per individual write operation. Writes exceeding this size may be silently truncated without the connector returning an error. This is an observed connector behavior rather than a documented GitHub API limit.

Keep direct connector writes for genuinely minor changes when every individual content write is `<=10 KB`. Direct write remains the preferred path for an isolated small document/control change; modified workflow YAML must still satisfy `GitHub_Workflow_Policy.md` schema-validation requirements before execution.

For coherent code or documentation work that is not a genuinely minor direct write, use this standard transport and do not stage patch bytes, compressed Base64, or patch fragments in the repository:

1. **Snapshot** — obtain one exact source snapshot with `.github/workflows/agent-source-snapshot.yml` and download/verify that immutable snapshot once.
2. **Prepare + preserve locally** — edit the snapshot-derived source in the local container, generate one complete `git diff --binary --full-index --no-ext-diff` patch covering both source/code and documentation changes as applicable, verify `git apply --check` plus `git diff --check`, and emit that exact patch as a user-visible downloadable chat/File-Library backup under `RETENTION_POLICY.md`.
3. **Stage externally** — upload the exact verified patch with the Google Drive connector to `My Drive/Directional-CI`. Record the returned Google Drive **File ID** and the complete patch SHA-256. Google Drive is transport staging only; the chat/File-Library patch remains the interruption-recovery copy.
4. **Apply by File ID** — install only the minimal temporary caller/trigger control files required to invoke durable `.github/workflows/agent-google-drive-reusable.yml`. Pass the File ID, exact patch SHA-256, exact patch base SHA, target branch, and commit message. The reusable workflow must fetch the patch by File ID, verify full-patch and embedded diff-body hashes, verify the recorded base and that intended touched paths have not changed, run `git apply --check`, apply, run `git diff --check`, verify the exact changed-path set, commit, and push. Patch transport may not modify `.github/workflows/**`; workflow-file edits remain direct connector changes under the workflow policy.
5. **Move staged patch to trash after success** — only after the patch commit has pushed successfully, `agent-google-drive-reusable.yml` must inspect `capabilities.canTrash`. When true, move the Google Drive patch to trash using the same File ID and report `drive_file_trashed=true`; when false, skip the mutation request and report `drive_file_retirement_required=true` so the owner-authorized Drive control plane can retire it without a deterministic 403. If application/push fails, retain the Drive file and File ID for diagnosis/retry instead of retiring the only remote transport copy.
6. **Retire repository control state** — after result/log evidence and Drive retirement are verified, delete the temporary caller first, then retire its marker and any other temporary repository control files through the normal cleanup lifecycle. Do not leave turn-specific patch payloads or fragments under `.agents/Directional/turn-payloads/`.

Before any remote application, resolve current branch authority. If the branch advanced after the patch base, the reusable workflow must fail closed when any intended path changed; reconstruct/rebase the patch deliberately rather than force-pushing or applying blindly.

## Durable handoff policy — DURABLE, DO NOT DELETE

At the end of every turn:

1. replace stale next-turn/status text instead of appending chronological narrative;
2. keep unresolved, current-authority, and immediately resume-critical facts in this handoff;
3. move completed history to `CHANGELOG.md` and exact evidence to the owning report/tracker without deleting durable lessons or policies;
4. never treat a documentation/control-plane commit as implementation, build, test, benchmark, or runtime evidence;
5. preserve the mandatory start/end checklists and all other sections explicitly marked durable;
6. preserve every section explicitly marked durable in **any** durable document. Durable sections must not be deleted, collapsed, renamed away, replaced by a summary, or stripped of durable meaning unless the user explicitly authorizes that destructive edit and its exact scope;
7. `[ChatGPT Web]` perform work directly on the configured working branch. Do **not** create temporary, control, side, or staging branches unless doing so is absolutely necessary to circumvent a concrete procedural blocker that cannot safely be resolved on the working branch. If an exception is unavoidable, record the blocker and why the branch is necessary, keep it narrowly scoped, remove/reset it as soon as the blocker clears, return to the configured working branch, then proceed to the next turn;
8. every Test + Benchmark turn must categorize **every observed regression** in `.agents/Directional/Regression_Root_Cause_Tracker.md` and record root-cause analysis before the turn closes. If evidence does not justify a stable regression ID/count change, create or update a candidate/non-stable record and explicitly state why historical stable totals do or do not change, then proceed to the next turn;
9. `[ChatGPT Web]` `.github/workflows/agent-compile-reusable.yml` owns one durable compiler-cache namespace/schema. Turn-specific callers must not invent cache epochs, cache namespaces, or unrelated per-turn compatibility keys. Restore must always use the durable compatible namespace so prior ccache entries are reusable across turns.
10. work units 2 and 3, plus the exact M1 full-authority partial edges tasklisted in `TODO.md`, have the user-authorized partial-CB cadence exception: only those exact `P-CB` → `P-CB` edges may omit an intervening TB. Every partial remains runtime-free and semantically unaccepted; the final packaging partial must advance to its TB before later milestone work starts.
11. `[ChatGPT Web]` `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` is durable operating authority and a mandatory full read at the start of every turn. Apply it before selecting repository-read, workflow-observation, artifact-download, multi-file-write, cleanup, or PR-comment strategies.
12. `[ChatGPT Web]` `RETENTION_POLICY.md`'s **downloadable work-preservation durability barrier is mandatory**. Any coherent repository-applicable work that exists only in the local/container workspace must be emitted as a File-Library-backed downloadable `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` before entering tool-heavy remote orchestration or another interruption-risk phase. A local `/mnt/data` file alone is not durable. The patch is recovery material, not semantic/build/test authority.

Do not add transcripts, chronological tool history, copied superseded artifact tables, obsolete task selections, or generic procedure already owned by policy/skill files. Concision never authorizes deletion of durable information.

## Mandatory start-of-turn checklist — DURABLE, DO NOT DELETE

1. `[ChatGPT Web]` Review the [turn-based-coding-agent](https://github.com/akashskypatel/turn-based-coding-agent-skill) skill if not already reviewed for the current work session.
2. `[ChatGPT Web]` **Fully review `TOOL_USE_CONSERVATION_POLICY.md` and `GitHub_Workflow_Policy.md` at the start of every turn before choosing repository-access, workflow, monitoring, artifact, cleanup, or PR-comment operations. This is mandatory every turn and is not satisfied by having read it in a prior turn. Immediately after that read and before the first repository source/document inspection, explicitly choose one turn-local [`READ_MODE`](TOOL_USE_CONSERVATION_POLICY.md#2-start-of-turn-conservation-procedure) under policy Step 2. If the task/checklist already implies three or more repository documents/files, cross-file tracing, repository-wide search, iterative re-reading, or material uncertainty about crossing that threshold, `READ_MODE=snapshot` is mandatory. Do not perform starter connector reads first and decide later. If snapshot acquisition fails, follow Step 3's explicit fallback, record the blocker, and do not silently resume piecemeal range reads.**
3. `[ChatGPT Web]` Maintain a record of every temporary files created during the turn or files to be deleted at the end of the turn in `.agents/connector-triggers/turn-cleanup/manifest.txt`. This file is used by `.github/workflows/agent-turn-cleanup.yml` to clean up temporary files at the end of the turn.
4. Fully review this handoff, `RETENTION_POLICY.md`, and `CLEAN_UP_POLICY.md`.
   - `[ChatGPT Web]` If the preceding turn was interrupted or reported prepared-but-unapplied local work, search File Library for the newest matching `Directional__...__work-preservation.patch` **before re-deriving that work**; verify its embedded base SHA and diff-body SHA-256, then reconcile it with current branch authority under `RETENTION_POLICY.md`.
5. **Review `LESSONS.md` in full, and re-read the sections governing this turn's work before authoring any plan, fixture, gate criterion, or corrective measure.** This step is mandatory and is not satisfied by having read it in a prior turn.
   - Before every Code + Build turn, also review `.agents/Directional/GMP_COMPILE_POLICY.md`. GMP/GMPXX linkage is mandatory for every future compile; fallback exact arithmetic is not authoritative build evidence.
6. Review `TODO.md` (including exact completed/current partial-CB status), `DESIGN.md`, `REORIENTATION_PLAN.md`, `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, the active next-turn plan, and `Regression_Root_Cause_Tracker.md`.
7. Confirm the configured working branch, branch head, exact implementation/source authority, and requested turn type before any write.
8. Verify every explicitly durable section required by the documents being touched is present before editing; do not proceed with a destructive rewrite if a durable section would be removed.
9. `[ChatGPT Web]` For Code + Build workflow work, verify the reusable compile workflow still owns the durable cache namespace/schema and that the caller does not supply a per-turn cache epoch/key.
10. `[ChatGPT Web]` Inspect `.github/workflows`, `.agents/connector-triggers`, and `.agents/Directional/turn-payloads` for stale temporary state without deleting durable workflows or records.

## Turn workflow — DURABLE, DO NOT DELETE

**Authorized by the user on 2026-08-25 and binding for all future work.**

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

1. **`CB`** — Code + Build. Authors semantics, compiles, packages. Executes no Directional runtime.
2. **`TB`** — artifact-only Test + Benchmark on the immutable package. Executes **the full current
   gate**, one identity per fresh process, with every mutation flag false.
3. **A green TB closes the checkpoint.** There is no separate acceptance ceremony.
4. **A red TB mandatorily routes to `REVIEW + PLAN`.** No retry, no patch, and no further CB without
   an intervening review.
5. **A red TB is information, not a debit.** Nothing is consumed, nothing is reset.

**Non-gating diagnostic identities**: A checkpoint may declare
identities that TB executes and reports but that are **excluded from the gate count**, each with a
written rationale and an owning corrective measure. A non-gating identity may never be promoted to
gating without a review recording why its precondition is now independently established.

## Mandatory next turn — `M3-CP4c-0b-TB-T5-PREFLIGHT-REV` — independent pre-gate evidence review

`M3-CP4c-0b-DG-T4-REV` is complete and correctly authorized T5 under U0-U7, but `M3-CP4c-0b-TB-T5` is now **BLOCKED / PRE-GATE OBSERVABILITY GAP / 353 NOT RUN**. Record: `Architecture_M3_CP4c0b_TB_T5_Preflight_Blocker_Report.md`.

U0 static authority is intact: immutable GMP package `9668492827` / `e0661e66…dce0b8`, semantic source `b2629040...`, manifest 28/28, full 353 selector `51ff96d7…ac6a5`, and exact first-346 prefix `20d3b0b1…3e46a`. No Directional binary or gate identity ran in the T5 turn.

The blocker is U3's ordering plus U7's immutability rule. U3 requires a **before-gate** fan/two-ring census publishing every trace terminus, barrier-termination count, all-node provenance with `railAuthority`, event histogram, arrival-comparison inconclusive status, and mutual-tie-policy firing. Immutable package `9668492827` has only partial compiled census/reporting surfaces: its contact census lacks the per-trace terminus/barrier/arrival/tie fields and publishes provenance only for contact nodes. U4 likewise lacks a dedicated per-witness N1/N2/N4 silence publisher. Adding the missing telemetry would require a test/instrumentation change and compile, both prohibited by U7 inside T5. Running 353 without U3 first would violate the independent review. The correct outcome is therefore fail-closed before runtime, not inference or retry.

Exact source-snapshot authority for the pre-gate audit is run/job `33130565916 / 98718854457`, artifact `9670081197` / `58403bc8…3023a284`, source archive `a82a2882…52f849`, with local `SHA256SUMS` verification. A stale cleanup run `33130560363` was safely rejected by the branch-head guard after the branch advanced; it made no repository or runtime change.

Stable product accounting remains **42 / 14 / 28**, debt **5**, M3 packages **54**. New `M3-CP4c0b-T5-CAND-01` is active evidence-capability/non-stable; `M3-CP4c0b-T5-CAND-02` is resolved orchestration/non-stable. `M3-CP4c0b-P03-CAND-01` remains active because accepted authority is still unmeasured.

**The review boundary is strict:** `M3-CP4c-0b-TB-T5-PREFLIGHT-REV` must adjudicate whether to authorize a narrow instrumentation-only Code+Build package that can satisfy U3/U4 before a later T5 execution. It must not execute 353, weaken U3/U4, widen guards, or claim CP4c-0b acceptance.

## Current authority

### M3-CP4c-0b TB-T5 preflight — current turn authority

- status: **BLOCKED / PRE-GATE OBSERVABILITY GAP / 353 NOT RUN**;
- immutable package/source and selector hashes pass U0 static checks; package manifest 28/28;
- Directional runtime and gate identities executed: **0**;
- blocker: U3 requires pre-gate fan/two-ring telemetry absent from compiled package `9668492827`, while U7 forbids adding instrumentation/compiling inside T5;
- U4 also lacks a dedicated compiled per-witness N1/N2/N4 silence census; not weakened into inference;
- exact source-snapshot audit: `33130565916 / 98718854457`, artifact `9670081197` / `58403bc8052a87f6359d809872a6e7ea7e61e3807b6dca104f38983e3023a284`;
- stable accounting unchanged **42 / 14 / 28**, debt **5**, M3 packages **54**;
- exact next: independent `M3-CP4c-0b-TB-T5-PREFLIGHT-REV`.

### M3-CP4c-0b DG-T4 — current runtime authority

- status: **COMPLETE / EXECUTION GREEN 7/7**;
- semantic source / immutable GMP package: `b2629040450c12507367c232f68a4d972b46450f / 9668492827`; package ZIP `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`;
- selector: seven / `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`; full 353 remains `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
- run/job: `33128261911 / 98711506300`;
- result/log artifacts: `9669229181 / 364d5d546bca4c664be67e52b336a48cbc1f49b6bd672371ea6351e396dcc84c`; `9669229414 / 39c7530a70650702f4345fea9de558ea6139fecd715f8d9b504ef945a94447ef`;
- every identity selected exactly once and PASS; zero-selected 0; zero escaping C++ exceptions; no repository timeout;
- no configure/compile/relink/repair/generated discovery and no package/source/test/fixture/selector mutation; immutable byte-and-mode postflight PASS;
- no regression/candidate observed; stable accounting **42 / 14 / 28**, debt **5**, M3 packages **54**;
- successor status: T4 independent review is complete; T5 preflight is blocked before runtime on the U3/U4 observability gap; retained as current runtime authority.

### M3-CP4c-0b CB2 — current build authority

- status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**;
- semantic source: `b2629040450c12507367c232f68a4d972b46450f`;
- semantic changes: test/diagnostic-contract only; production `src/` and `include/` unchanged;
- T1 torus: atlas-derived `0 rails / 0 singularities / 0 nodes / 0 traces / 0 events`; pipeline-authoritative `48 HardFeature rails / 0 singularities / 48 structural endpoint nodes / 0 traces / 0 events`, zero contact provenance;
- candidate `M3-CP4c0b-DG-CAND-02`: **RESOLVED / NON-STABLE / TEST-SIDE**, +0 stable events / +0 recurrences;
- selectors: seven `d28bbeeb74ed8e07810b06d870bdaf470bab1f294bbfe810deaa4f63276e245c`; full 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
- compile run/jobs `33126178643 / 98704812754 / 98705144144` all green;
- immutable GMP package `9668492827` / `e0661e66cfc12ce8945962a18b8a8f6fc8aa5a1213b3ad4d2409054573dce0b8`; 28/28 manifest PASS; `runtimeExecution=false`;
- successor status: T4 execution is green 7/7; retained as current build authority.

### M3-CP4c-0b DG — retained pre-CB2 runtime evidence

- status: **COMPLETE / VALID SEMANTIC RED 6/7**; authoritative corrected run/job `33120730355 / 98686699036`;
- immutable authority: semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`, package `9664890562` / `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`, seven-identity selector `14570409facfb9c9072375cae3ad4319e383386380ee1060d4af75c6e61c5724`;
- ledger: **7 executed / 6 PASS / 1 RED**, every identity selected exactly once, zero escaping exceptions, no timeout/build/repair/mutation, immutable postflight PASS;
- sole red: `TraceTerminationCorrection.TorusRemainsZeroTraceAndFanRemainsExcludedFromCredit`; zero candidate traces passed, `torus.network->nodes().empty()` failed at line 6952, no separate zero-event failure reported;
- result/log: `9666352028 / 286f738f02315d72dea7cc03bed61bc12ef6b5345ddf15264a898b5bfa45db72`; `9666352544 / 651e9cb9fc78d109d725fdf725fd26b72c450f6bba44fd77e638780c0df2712e`;
- first run `33120437486 / 98685729035` is resolved orchestration-only, zero Directional identities executed; no semantic bytes changed by the harness correction;
- full 353 acceptance TB **NOT RUN**; stable accounting **42 / 14 / 28**, debt **5**, packages **53**;
- successor status: independent DG review and CB2 are complete; retained only as pre-CB2 runtime evidence.

### M3-CP4c-0b CB1-S2-S6 — retained predecessor build authority

- status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**; semantic source `737f93be10a73db950e2a7f823b96ffb0d59cf4d`;
- semantics: exact proper-crossing/contact classification, disjoint site vocabulary, fixed `ArcLengthFiltered` production priority with computed error bounds and no seniority fallback, globally ordered contact resolution, and exact durable `terminalContact`;
- selectors: predecessor **346** / `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; new-contract DG **7** / `14570409facfb9c9072375cae3ad4319e383386380ee1060d4af75c6e61c5724`; full **353** / `91371d5ab637447c31c0d25e829be0d58fa61f17245e69bd231dcaec94f21efb`; first 346 are byte-exact predecessor and last seven are byte-exact DG;
- Drive apply run/job `33115797114 / 98670027134`; applied semantic commit `737f93be10a73db950e2a7f823b96ffb0d59cf4d`; result/log `9664432556 / 9664432987`;
- changed-owner GMP precompile run/job `33116158072 / 98671267836`; result/log `9664729779 / 9664730426`; manifest 23/23;
- authoritative eight-target GMP package run/job `33116774891 / 98673348923`; immutable package `9664890562` / `94beb349763ff261d603839176a458d1f69e976192aafcd0c69d2617abd88273`; compile log `9664890910 / a528e66fc88191ad5e030f1821e8029871719514895041568bfea5b352e7fcf0`; manifest 28/28;
- all source-status snapshots clean; `runtimeExecution=false`; no Directional runtime/test/benchmark/discovery/CLI/fuzzer/custom input executed;
- stable accounting **42 / 14 / 28**, debt **5**, M3 packages **53**;
- retained predecessor package only; CB2 now supersedes build authority with package `9668492827`.

### M3-CP4c-0b TB-S1-REV — retained predecessor review evidence

- status: **COMPLETE / REVIEW GREEN**; no runtime/build/package/acceptance attempt;
- raw S1 artifact independently verified: `9656967036` / `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4`;
- reached included site-B contact count: **0** on two-ring and torus; no non-proper/unevaluated selected contact; S1 stop not triggered;
- sphere: **unreached at N1**, exactly as P0.3 predicted; no zero-contact inference;
- site-A migration: two-ring `A/B/C=1/0/0`, its sole `TraceIntersection` is the overloaded origin junction; two named CP3b identities are authorized for S2 re-authoring;
- S2-S6 semantics remain exactly the P0.3/frozen contract; no predicate widening, tolerance, seniority fallback, post-hoc truncation, enum-value reuse, or multiple terminal kinds;
- successor status: CB1-S2-S6, DG, independent DG review, and CB2 are complete; retained as predecessor review evidence;
- stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **52**.

### M3-CP4c-0b TB-S1-EXEC — retained predecessor runtime evidence

- semantic/evidence source / immutable GMP package: `4bb467806df99c70889394a323c17c13bc185ca3 / 9655632444`;
- artifact-only run/job: `33097182476 / 98605092984`;
- frozen gate: **346/346 PASS**, selector SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, one identity per fresh process;
- non-gating S1 identity: PASS, zero gate credit; reached included witnesses had zero non-proper/unevaluated contacts and `requiresReview=0`; prescribed sphere was unreached at expected N1 `TraceCombinatorialRecurrenceExceeded` and has no contact-count claim;
- raw result/log: `9656967036 / 9656967437`, SHA-256 `dd1f8aa8f2346612beb445d7e5d6a8768a438e36c543e0b4d407b444523d85a4 / 667b9c54ad24e9e33855d3fd47a322593c4522bde4984177dfa593a1df7f6bb8`;
- no configure/compile/relink/repair/generated discovery, no mutation, no repository timeout, zero escaping C++ exceptions, immutable postflight PASS;
- stable accounting remains **42 / 14 / 28**, debt **5**, M3 packages **52**; no new regression/candidate observed;
- successor status: TB-S1-REV and all later CB1/DG/CB2 work are complete; retained as predecessor runtime evidence.

### M3-CP4c-0b CB1-S1 — retained predecessor build authority

- semantic/evidence source: `4bb467806df99c70889394a323c17c13bc185ca3`;
- S1 is **diagnostic-only**: exact proper-crossing observation and contact census, with no production contact/event/node/trace/termination semantic change;
- first patch-transport run `33091855034` failed before commit because patch metadata used comma-delimited `intended_paths` while the durable apply workflow requires semicolons; corrected bytes preserved the identical diff body;
- corrected apply run/job `33092961074 / 98590434004` succeeded; result/log artifacts `9655159304 / 9655160089`; Drive staging retired after successful push;
- first compile-caller run `33093222009` was `startup_failure` before jobs because the caller omitted the reusable observer's required `contents: write` permission union; no build/runtime evidence came from it;
- authoritative compile run `33093440552`: GMP pre-package job `98592131066` succeeded for `directional_surface_cell_producer_tests`, then GMP package job `98593728046` succeeded for all eight standard targets on the **same** semantic SHA;
- immutable package `9655632444`, GitHub artifact SHA-256 `c22e9b020e533ca8fc558bcafc3e138a062702a59bee68a097958b432d70bc5f`; compile log `9655633229 / ad36b3523bd3843b3618bee8ff71aa4789be6381554d8e089d1f4469d44e4b9e`;
- pre-package result/log `9655528709 / 9655529401`, SHA-256 `cf179bae7d1897f66b286e5688afb8540760d289ecca6de598fdb1d0638ef3f6 / 68fa64caa92340251eeeed77236aaf90ff895a7202c253c0ab6f44d9308d6609`;
- `exactArithmeticBackend=GMP`; all source-status checks clean; `runtimeExecution=false`; no Directional binary/test/benchmark/discovery/CLI/fuzzer/custom input executed;
- successor status: S1 execution/review and later CB1/DG/CB2 work are complete; retained only as predecessor build evidence.

### M3-CP4c-0 CB8 — retained build authority

- semantic source / immutable package: `19ba8e9c5e58f9c33c14b309841165d3f0401db5 / 9628445643`;
- package ZIP SHA-256 `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`; source archive `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`;
- authoritative compile-only run/jobs: `33025705457 / 98366398970 / 98367264215`;
- compile log `9628446136 / 562bb275fccb61629a3a60bfd1f71c3cb8332a239674dab660ebcd1626f33d27`; preflight result `9628386576 / a9b66f29f9bb23927df9614066d43c7edaaeb70e5d1a01fd0551154d9a79778c`; preflight log `9628386953 / fb4ec9a4c041632cf7a3f5f14f0db9482b5c9c55b2c217654f42725c9872df90`;
- all eight standard targets compiled/linked; preflight/build exit 0; all source-status snapshots empty; recursive package hashes verified;
- `runtimeExecution=false`; no Directional runtime/test/benchmark/discovery/CLI/fuzzer/custom input executed;
- L0–L9 only; no A1/A2b/T6/CP4c-1 selector/tolerance/threshold/magnitude change;
- CP4c-0 selector **343** / `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`; first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` and first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600` preserved;
- exact next: artifact-only `M3-CP4c-0-TB-R8` on package `9628445643`.

### M3-CP4c-0 TB-R7 — COMPLETE / VALID SEMANTIC RED

- CB7 semantic source/package: `077462da156c3e2dfbbc6867fc10d3e4442d853c / 9625495708`;
- authoritative control/run/job: `3d1ef24d6bcccb7e4e821d713a21860bc0598bd0 / 33019554121 / 98346293968`;
- result `9626003625 / 61994abc1e67fc55bc1d48d38a521598b6b56e458972d948ebcae112fa27eaaa`;
- diagnostic log `9626004016 / 9f6307b90b93ba557af7643c5a2d4a021969708b2a77e74fc546ae4f263e441c`;
- mode-preserving extraction, 338/338 gate, 316/316 accepted prefix, 328/328 prior prefix, F3 2/2, postflight PASS;
- K1 near-tangency separation reproduced; K2 0/24 reaches grazing and is non-decisive; J3 legitimate 524/524; K3 176/176 complete fans / 0 mismatches;
- Q8 creditable RED criterion 2; no build/repair/mutation; exact next `M3-CP4c-0-DEFN-2`.

### M3-CP4c-0 CB7 — retained build authority

- semantic source / immutable package: `077462da156c3e2dfbbc6867fc10d3e4442d853c / 9625495708`;
- package ZIP SHA-256 `dc07d4288b9a529ca71c06f96e0277b168d2e5a28c5a9eeba3fdf7341a33237a`; source archive `6ecafbc5a5904568780e6518f39b9d4b1336c94e08a53f7fc0c31d8926e26344`;
- authoritative compile-only run/job: `33018117005 / 98341565781`;
- compile log `9625496280 / e42240c280738fd70e8eddc09bc9899537cac53f477e3d3f88d26f6b4a0a978f`;
- eight standard targets compiled/linked; preflight/build exit 0; all source-status snapshots empty;
- `runtimeExecution=false`; no Directional runtime/test/benchmark/discovery/CLI/fuzzer/custom input executed;
- K0–K7 diagnostic/contract-control only; no production semantics/fixture/selector/tolerance/T6/Q8 change.

### M3-CP4c-0 TB-R6 — COMPLETE / VALID SEMANTIC RED

- semantic source / immutable package: `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6 / 9619352525`;
- package ZIP SHA-256 `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672`; source archive `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093`;
- authoritative control/run/job: `a9ae307590b0cc23080452c4a5013674efc48fc2 / 33006282429 / 98300813772`;
- result `9620769314 / fe6a73175399b764f7cbb3ea2963a8deb40d6d0b5afcc3e9a603102ee4936684`;
- diagnostic `9620770049 / ce87da5a919e31f7e36a8d904dfaad7c7d9c92b9bebf36a494de096e7cb691cb`;
- gate 338/338; accepted 316/316; first-328 328/328; F3 2/2; G5/H1/J3 PASS non-gating; Q8 creditable RED criterion 2; postflight PASS;
- H1 legitimate 388 directed / 194 distinct; J3 legitimate 524/524 geometry agreement; fan excluded 2/1 H1 and 1 J3 mismatch;
- no configure/compile/relink/repair/generated discovery/performance benchmark and no package/source/test/fixture/selector mutation.

A prior control run `33006048971 / 98300014224` is resolved orchestration-only evidence: Python ZIP extraction lost executable modes and the first binary launch failed with `PermissionError` before any Directional binary executed. The authoritative retry used normal `unzip` without package repair.

### M3-CP4c-0 CB6 — retained build authority

CB6 semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`, compile-only run/job `33002848081 / 98288918300`, package `9619352525`, compile log `9619353059`. All eight standard targets compiled/linked with build/preflight exit 0, empty source-status snapshots, and `runtimeExecution=false`.

### Accepted runtime authority

Latest accepted runtime is the whole-gate TB-R9 re-proof **346/346**, run/job `33079817998 / 98543736213`, on fresh GMP package `9649395432` from semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed`. Result artifact `9649625534` has GitHub ZIP SHA-256 `6cd4e3c21dc46fd7e0d6df2209ee5a382531d768f50ae52d190302e05bec02af`; diagnostic artifact `9649626115` has SHA-256 `3ba381cd12ec1188bd9ae36020d35bdaa458271ea2c7b1163aac31a9a474d7f9`. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**. M3 package count is now **54** after the CB2 GMP package; accepted runtime authority itself is unchanged.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, and **CP4c-0 are accepted**.
- **CP4c-0 is CLOSED / ACCEPTED at 346/346.** The unchanged selector SHA-256 is `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; first-316 and first-328 prefixes remain 316/316 and 328/328. Q8 criteria 1/4/5 are PASS.
- Both TB-R9 candidates are **RESOLVED / NON-STABLE / TEST-SIDE**. CAND-01 is GMP-portability; CAND-02 is fixture-precondition. The skipped TB-R9 review remains skipped/not completed historically.
- **`M3-CP4c-0b` is OPEN** and owns trace termination plus Q8 criteria 2 and 3. CB2 is BUILD GREEN at semantic source `b2629040...` on GMP package `9668492827`; the prior torus zero-node red is resolved test-side/non-stable. T4 DG is **GREEN 7/7** on run/job `33128261911 / 98711506300`; T4 independent review is complete, but T5 stopped before runtime because immutable package `9668492827` cannot publish U3/U4's required pre-gate telemetry. Full 353 acceptance remains unmeasured.
- **`M3-CP4c0-TB-R8-CAND-01` transfers to CP4c-0b.** Six prescribed-sphere separatrices circulate; the CB9 guards bound the cost but do not make them terminate. It is resolved by a green CP4c-0b prediction 5, not before.
- `M3-CP4c0-DEFN2-CAND-01` remains open/non-stable — the K2 grazing-cost census walks traces with the retired Cartesian carrier lookup; owned by measure L8, no product impact.
- `M3-CP4c0-TB-R4-CAND-01` remains a historical/non-stable near-tangency diagnostic; the production grazing model was subsequently defined under DEFN-2.
- `M3-CP4c0-TB-R6-CAND-01` is resolved orchestration/non-stable.
- CP4c-1 remains blocked on **CP4c-0b**, and **no longer owns** re-homed Q8 criterion 3. CP4c-2/3 remain blocked for their own definition turns.
- Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **54**.
- **Exact next turn is `M3-CP4c-0b-TB-T5-PREFLIGHT-REV`, independent review only.** Adjudicate the immutable-package U3/U4 observability conflict; do not execute the 353 gate or new runtime in the review.

## Context Load Plan

`load_next`: turn-based-coding-agent `references/turns/TB-REVIEW.md`.

Minimum successor context after the mandatory durable policy/start checklist:

1. `.agents/Directional/Architecture_M3_CP4c0b_TB_T5_Preflight_Blocker_Report.md`
2. `.agents/Directional/Architecture_M3_CP4c0b_DG_T4_Independent_Review_Record.md`
3. `.agents/Directional/Architecture_M3_CP4c0b_DG_T4_EXEC_Artifact_Only_Test_Benchmark_Report.md`
4. `.agents/Directional/Architecture_M3_CP4c0b_CB2_Code_Build_Report.md` only for immutable package provenance
5. `.agents/Directional/Architecture_M3_CP4c0b_Required_Green_Selector.txt` only to verify U0 selector authority

## Resume-critical lessons — DURABLE, DO NOT DELETE

**The lessons formerly listed here now live in `.agents/Directional/LESSONS.md`,** by explicit user
authorization, deduplicated and organized into eight sections. That document is durable project
authority: it may be corrected or extended, never deleted, weakened, or summarized away without
explicit user authorization. This section remains durable and must continue to point to it.

**Reading `LESSONS.md` is mandatory start-of-turn step 5.** Do not resume work from this handoff
alone.

Sections, so the right one can be found without reading the whole document:

| Section                                            | Read it before                                                               |
| -------------------------------------------------- | ---------------------------------------------------------------------------- |
| 1. Evidence and acceptance                         | promoting any artifact, selector, or audit result                            |
| 2. Fixtures and witnesses                          | authoring or judging any fixture, helper, or witness                         |
| 3. Negatives and oracles                           | authoring a negative, a tamper test, or an oracle                            |
| 4. Single authority and representation             | adding a product, moving a guard, or typing a domain                         |
| 5. Cross-field, cycle, and orientation conventions | **any A1/A2 matching, effort, index, cycle, or transition-orientation work** |
| 6. Gate and criterion authoring                    | writing an exit criterion or freezing a gate                                 |
| 7. Budget, attempts, and stop rules                | planning a checkpoint or running a mandatory review                          |
| 8. Build, package, and workflow mechanics          | any Code + Build turn or connector workflow                                  |

New lessons are added to `LESSONS.md` in the section that governs them, not appended here.

**Standing note on repeat failures.** Section 2's opening lesson records that the same
degenerate/unusable-fixture class has now cost **four consecutive M3 checkpoints** — CP1's planar
`z = 0` A1 fixtures, CP2's single-edge open rails, CP2b's hard-coded face-pair orientation, and
CP3a's one-ring fan, where every edge opposite the singular vertex is a boundary edge so the
required multi-face traversal was unsatisfiable by construction. Section 5 records that transition
orientation is mesh-owned. All were written down before the failure that repeated them. Reading the
relevant section is the cheapest control this project has.

CP3a broke the streak's shape: its fixture now **asserts its own precondition at runtime** — every
singular-fan opposite carrier must be interior — so the next author cannot reintroduce the defect
silently. CP3b then carried that habit forward unprompted and closed on attempt 1 with no diagnostic
gate. Copy that pattern into CP4's witnesses.

## Mandatory end-of-turn checklist — DURABLE, DO NOT DELETE

1. Confirm the requested turn stayed within scope and no later-turn implementation leaked into it.
2. For Code + Build turns, confirm `runtimeExecution=false`; for Test + Benchmark turns, confirm no rebuild/repair/source/test/fixture mutation occurred inside the immutable gate.
3. For every Test + Benchmark turn, update `Regression_Root_Cause_Tracker.md` for every observed regression/candidate before advancing the handoff.
4. Confirm exact source/package/run/artifact identities and stable regression totals are recorded in the owning durable report/tracker.
5. `[ChatGPT Web]` **Confirm no meaningful repository-applicable work remains only in the local/container filesystem.** For each coherent local work unit not yet durable on the working branch, emit or refresh the mandatory File-Library-backed `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` and locally verify its declared base/hash/applicability **before** cleanup or final repository closeout. If all such bytes are already durably committed, no new preservation patch is required solely for duplication.
6. `[ChatGPT Web]` Make sure `.agents/connector-triggers/turn-cleanup/manifest.txt` is up to date and make sure it does not include any durable files or any other files that need to be retained. Execute `.github/workflows/agent-turn-cleanup.yml` workflow to process the manifest and clean up the repository, and trimp historical PR comments.
7. Confirm the handoff names exactly one next turn and the task index agrees with it.
8. `[ChatGPT Web]` Make the final repository write one summarized PR #8 conversation comment after all branch/PR-description writes. No downloadable-artifact/tool emission may occur after that final comment.


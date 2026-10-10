# `[ChatGPT Web]` Agent Tool Use Conservation Policy

## Status — DURABLE, DO NOT DELETE

This document is durable project authority under `RETENTION_POLICY.md`. It defines the mandatory strategy for minimizing GitHub connector, workflow-observation, artifact, and repository-maintenance tool calls without weakening source authority, turn boundaries, evidence requirements, or cleanup safety.

**Reading this file in full is a mandatory start-of-turn step for every turn.** It is not satisfied by having read it in a prior turn. The sole repository-operation exception is the `STATUS` bootstrap required by `Durable_Handoff_Policy.md` item 15: initialize the in-memory ledger, read repository-root `STATUS`, and immediately direct-write the entry/resume beacon before any other repository mutation; then read this policy and `GitHub_Workflow_Policy.md` before choosing any further repository-access, workflow, mailbox/monitoring, artifact, cleanup, or PR-comment-fallback operation.

Tool-use conservation is subordinate to correctness. Never save a tool call by weakening source identity, skipping a required policy read, merging Code + Build with Test + Benchmark, omitting required evidence, using stale branch authority, or bypassing a stop rule.

Any repeated action that requires generating the same file or performing the same operation should be turned into a reusable fixture (ex. reusable workflow files) or tool (ex. python scripts under `.agents/Directional/tools/`). If a file is already generated, do not regenerate it; use the reusable fixture or tool instead and tailor it to the specific needs of the current task.

## 1. Core operating rule

Use the cheapest authoritative access path that can answer the whole question once:

1. **GitHub connector = control plane.** Use it for branch/PR/ref authority, small metadata reads, single small-file reads/writes, Git object creation, workflow/job/artifact metadata, and final PR state.
2. **GitHub Actions = bounded batch execution plane.** Use reusable workflows when remote computation, packaging, repository-wide collection, source snapshots, or high-volume cleanup would otherwise require many connector calls.
3. **Downloaded artifacts/local container = analysis plane.** Once source, logs, or evidence are downloaded and verified, inspect them locally with normal filesystem tools instead of repeatedly asking GitHub for the same bytes.
4. **One authority read should feed many downstream decisions.** Do not repeatedly re-fetch unchanged state merely because a later sub-step needs the same fact.

The target is not the fewest possible calls in isolation. The target is the fewest calls that preserve deterministic authority and all required evidence.

## 2. Start-of-turn conservation procedure

Perform the following in order.

### Step 0 — initialize and maintain the in-memory tool-call ledger

Every turn maintains one zero-cost, turn-local tool-call ledger from the first invocation through closeout.

1. Initialize the ledger at zero before the first tool invocation of the turn. The mandatory `STATUS` bootstrap read/write and the subsequent policy-read invocation each count like any other tool call.
2. Increment the total exactly once for every actual tool invocation, including tool discovery, connector reads, connector writes, workflow/run/job/log queries, artifact transfers, local container/Python execution, web access, retries, and failed/erroring calls. Pure model reasoning and the user-facing final response do not increment it.
3. Maintain both the exact total and a mutually exclusive primary breakdown by invoked tool namespace/family. The default report families are `GitHub connector`, `API/tool discovery`, `workflow evidence/action`, `artifact transfer`, `local container/Python`, `web/external`, and `other`; when a call could fit more than one family, assign it to one primary family only so category totals equal the overall total.
4. Ledger maintenance is internal bookkeeping. **Never invoke a tool merely to increment, persist, inspect, or total the ledger.** Updating an in-memory counter is not a tool call and consumes no tool-call budget.
5. If turn state is compacted or summarized, carry the current total and category counters forward as resume-critical turn-local state. Do not reconstruct already-known calls from GitHub, Actions, logs, or another service after compaction.
6. If the ledger is genuinely lost or incomplete, report it as partial/unknown rather than guessing, and do not spend tool calls solely to reconstruct historical counts.
7. At closeout, report the total and category breakdown without making any additional call for accounting. If a final PR summary comment is required, that comment invocation is itself a tool call: compute the final count as including that last invocation and include that final count in the summary. No later tool call may be made merely to verify the count.
8. Tool-call totals are an efficiency metric, not an acceptance criterion. Never avoid a correctness-, evidence-, policy-, or race-preserving call just to keep the number low.

### Step 0A — publish the turn-entry/resume `STATUS` beacon

Before substantive work, read repository-root `STATUS` if present, determine whether this is a new successor turn or a resume of the same incomplete turn, and immediately direct-write the canonical beacon through the GitHub connector. Preserve/set `Started at`, `Resumed at`, and `Ended at` exactly as required by `Durable_Handoff_Policy.md` item 15. This write must precede every other repository mutation. Do not route the bootstrap beacon through patch transport or a workflow.

### Step 1 — resolve remote authority once

1. Read the PR or configured branch authority once at the beginning of the turn.
2. Record repository, branch, PR number, head SHA, base SHA, draft/open state, and requested turn type.
3. Treat that recorded head as the initial authority for reads and planning.
4. Do not repeatedly request PR metadata during the same unchanged phase, and do not write PR metadata at all (§10).
5. Re-read branch/PR authority only at a real compare-and-swap boundary: before a write based on a potentially stale parent, after a workflow-originated branch write, or before final closeout when external actors may have advanced the branch.

### Step 2 — choose the read mode before reading source

**This is a mandatory pre-read gate, not a preference. Before the first repository source/document inspection of the turn, explicitly choose and retain one turn-local `READ_MODE`: `direct` or `snapshot`. Do not begin with connector line/file reads and decide later.** The task statement, expected file count, known handoff/checklist obligations, and authority metadata are sufficient to make this choice before source inspection.

Choose **`READ_MODE=snapshot`** when any of these conditions holds:

- three or more repository files are likely to be inspected;
- one large file would otherwise require multiple line-range calls;
- repository-wide search/grep is required;
- iterative code review will revisit the same files/functions;
- source relationships, call sites, includes, tests, CMake ownership, or helper definitions must be traced across files;
- the turn requires repeated static analysis after edits;
- a later sub-step is likely to need context not known at the first read;
- the mandatory start-of-turn checklist itself requires three or more repository documents to be reviewed.

Choose **`READ_MODE=direct`** only when the task is genuinely small: one metadata object, one small file, one known line range, or a single exact blob that will not be revisited. If there is material uncertainty whether the task will cross the snapshot threshold, choose `snapshot`.

Once `READ_MODE=snapshot` is selected, **source/document connector reads are blocked until one exact snapshot is materialized and verified**, except for the minimum control-plane reads needed to obtain/observe that snapshot or to diagnose why snapshot acquisition failed. Do not use a few direct reads to "get started," "find the relevant helper," or "bootstrap context" while the snapshot is being arranged.

**Anti-pattern / policy violation:** fetching lines 1-200, then 201-400, then a helper in another file, then returning to lines 350-500. That is a snapshot case, and the violation occurs at the first piecemeal source read after the snapshot threshold was knowable — not only after the later calls make the waste obvious.

If this gate was violated, stop further piecemeal inspection, record the miss as material turn evidence, switch to snapshot mode immediately, and do not normalize the already-spent calls by continuing the same pattern.

### Step 3 — obtain one exact source snapshot when snapshot mode is selected

Use the durable `.github/workflows/agent-source-snapshot.yml` source-snapshot utility rather than reading source piecemeal.

1. Resolve and freeze the exact source SHA first.
2. Run the snapshot workflow for that exact source authority.
3. After the snapshot workflow publishes, fetch `.workflow-mailbox/repo-source-snapshot/latest.json` from the declared mailbox branch and use its `run_id` as the authoritative discovery handle after verifying its `source_sha`/`event_sha` against the frozen source authority.
4. If the mailbox is absent or stale, use the PR observer/recent-runs path only as fallback; do not treat a missing mailbox record as proof that no run exists or trigger a duplicate run.
5. Fetch the exact run's jobs once after the run is known.
6. Fetch its artifacts once after the snapshot job is terminal.
7. Download the source snapshot artifact once, preferring the artifact ID recorded by the mailbox.
8. Verify snapshot metadata and hashes against the requested source SHA before relying on it.
9. Extract the snapshot into a turn-local directory in the container.
10. Perform all subsequent static source inspection locally with `grep`, `rg`, `find`, `sed`, `awk`, Python, or other filesystem tools.
11. Reuse that extracted snapshot for the entire unchanged source phase.
12. Refresh the snapshot only when semantic/source authority actually changes and the next analysis depends on the changed source.

A control-plane cleanup commit, trigger-marker commit, comment, or workflow-only commit does not automatically invalidate a frozen semantic-source snapshot. Refresh only when the files relevant to the analysis changed or exact current-head inspection is required.

**Snapshot acquisition failure does not silently downgrade `READ_MODE` to piecemeal connector access.** If the snapshot workload is skipped, fails, cannot be observed, or cannot be downloaded:

1. record the exact failure/blocker;
2. first prefer a corrected invocation of the durable snapshot utility when the failure is orchestration-only and a retry is justified;
3. otherwise use one exact-authority bulk materialization/download path if an authorized connector/tool surface provides it, then inspect that local copy;
4. only when no bulk materialization path is available may direct connector reads be used as an explicit exception; in that case read whole exact files/blobs where possible, prohibit overlapping line-range pagination, reuse response resources instead of refetching, and record why the snapshot path was unavailable;
5. if the durable snapshot utility itself has a repeatable defect, tasklist/fix that control-plane defect rather than allowing future turns to treat the fallback as the normal path.

## 3. Local source inspection strategy

Once a verified snapshot exists:

1. Search the entire tree locally before asking GitHub where a symbol is defined.
2. Read whole files locally when context is useful; do not recreate remote line-range pagination in the container.
3. Build one local inventory of relevant symbols, rejection sites, call sites, target ownership, tests, and policy references.
4. Keep intermediate inventories in the container unless they are required durable evidence.
5. Use local diffs between materialized versions when comparing related edits.
6. Return to the connector only for remote authority, writes, or evidence that cannot be derived from the verified snapshot.

For a Code + Build turn, the source snapshot is **inspection authority only**. Compilation/package authority still comes from the exact GitHub Actions build source and its recorded evidence.

## 4. Batch repository reads

When a connector read is still appropriate:

1. Prefer one directory tree or recursive tree read over many existence checks.
2. Prefer one PR changed-file inventory over fetching individual file patches just to discover paths.
3. Prefer one `compare_commits` result over per-file historical queries when the question is "what changed between these authorities?"
4. Prefer one full small-file/blob fetch over several line-range fetches.
5. When multiple facts live in one response resource, reuse that response instead of calling the same endpoint again.
6. Do not fetch detailed workflow logs for every successful job. Fetch job summaries once, then detailed logs only for the workload job(s) whose evidence or failure diagnosis requires them.

## 5. Batch repository writes

Related file mutations should land in as few repository writes as safely possible.

### Preferred multi-file write

For coherent code/documentation changes that are not a genuinely isolated minor write:

1. Start from the verified exact source snapshot selected by `READ_MODE=snapshot`.
2. Materialize all final edits locally and generate one complete Git binary patch with exact base SHA, diff-body SHA-256, and intended-path metadata.
3. Verify `git apply --check` against the exact base and `git diff --check`; emit the same patch as the mandatory user-visible work-preservation backup.
4. Upload that patch once to `My Drive/Directional-CI` through the Google Drive connector and retain its File ID plus complete patch SHA-256.
5. Overwrite the durable `.agents/Directional/agent-dispatch-request.json` once with a validated `drive_apply` request. The request commit is the trigger and `agent-operation-dispatcher.yml` invokes `agent-google-drive-reusable.yml`; do not create a temporary caller or marker.
6. After the successful push and required evidence are verified, use the **user-authorized Google Drive connector** as the owner-side cleanup plane. If the staged patch remains addressable, permanently delete that exact File ID/URL with one `delete_file` call. Do not spend workflow retries on a service-account `DELETE` that lacks ownership permission. If workflow-side trash already made the file inaccessible to the connector, accept the recorded `drive_file_trashed=true` result rather than adding search/retry calls solely to locate a trashed object.
7. Retain the durable dispatcher/request slot and batch-clean only unrelated or legacy temporary control state. Patch bytes/fragments do not belong in the repository.

Use individual `update_file`/`create_file` operations for a genuinely isolated small file when every individual content write is within the handoff's direct-write ceiling. Workflow YAML changes follow `GitHub_Workflow_Policy.md` and are not applied by the Drive patch workflow.

### Prepare first, write once

Do not interleave discovery and mutation when it can be avoided. Finish the local census/plan, compute the complete intended diff, then write the coherent batch.

## 6. Workflow creation and schema validation batching

Workflow safety requirements remain unchanged, but validation can be batched.

1. For ordinary Drive apply, compile/package, and artifact-only Test + Benchmark work, do **not** draft a workflow. Materialize one strict dispatcher request and overwrite `.agents/Directional/agent-dispatch-request.json` once.
2. Reuse durable `agent-operation-dispatcher.yml`, `agent-test-benchmark-reusable.yml`, `agent-compile-reusable.yml`, `agent-google-drive-reusable.yml`, `workflow-mailbox-publisher.yml`, `agent-workflow-schema-validator-reusable.yml`, and source-snapshot/cleanup utilities. Treat `agent-run-observer-reusable.yml` and `agent-recent-workflow-runs-reusable.yml` as fallback discovery utilities, not the primary run-marker path.
3. The durable dispatcher validates its own workflow and the TB reusable before parsing each request; do not launch separate per-request schema-validation runs.
4. If the dispatcher cannot represent required event semantics or is broken, record the blocker before using the legacy temporary-caller fallback in `GitHub_Workflow_Policy.md`. Only that fallback retains the separate caller-install/marker-trigger boundary.
5. A diagnosed dispatcher-request correction overwrites the complete request once with a new request/retry identity. Do not replay unchanged deterministic failures.

## 7. Workflow observation without polling waste

After a workflow is triggered:

1. The authoritative completed-run rendezvous is `.workflow-mailbox/<workflow-key>/latest.json`. Fetch that stable path once when the workload has plausibly reached final publication, verify `source_sha`/`event_sha`, and use its numeric `run_id`.
2. Mailbox records normally publish after artifact-producing jobs complete. If live diagnosis is needed before that point, use a PR observer comment or `agent-recent-workflow-runs-reusable.yml` only as a provisional fallback. Do not repeatedly fetch PR comments and do not re-trigger merely because the final mailbox record is not present yet.
3. Once the run ID is known, fetch the run's jobs once to establish job IDs/status.
4. Avoid rapid polling. Re-query only when enough time has elapsed for the workload to plausibly change state or when an external event indicates completion.
5. When terminal, fetch the jobs once more if needed, then fetch detailed logs only for the workload/diagnostic jobs required for evidence or diagnosis.
6. Prefer artifact IDs already recorded in the mailbox, but fetch the run artifact inventory once when task evidence requires authoritative server-side reconciliation.
7. Download each required artifact once and inspect it locally thereafter.
8. If mailbox publication failed or is stale and the connector cannot locate the push run directly, invoke `agent-recent-workflow-runs-reusable.yml` once and inspect its packaged result instead of issuing repeated unsupported commit-run queries.
9. Once a valid mailbox record appears for the expected authority, it supersedes provisional PR-comment/recent-run discovery.

An absent result from a connector endpoint known not to enumerate push runs, or an as-yet-unpublished mailbox record, is not a reason to repeat the same call or launch a duplicate workflow.

## 8. Artifact conservation

Treat downloaded evidence as reusable local input.

1. Download a build package, source snapshot, log artifact, or result artifact once per immutable artifact ID.
2. Record the artifact ID and digest immediately.
3. Verify its outer digest and internal manifest once before use.
4. Extract into a stable turn-local directory.
5. Perform all subsequent searches, comparisons, hash checks, and report extraction locally.
6. Do not repeatedly call GitHub to inspect files already present in the verified artifact.
7. Re-download only if the local copy is missing/corrupt or a distinct artifact ID is required.

For immutable Test + Benchmark work, this conservation rule does not permit repair or mutation of the package; local inspection/execution must still obey the artifact-only boundary.

## 9. Temporary-file inventory and batched cleanup

Do not discover and delete temporary repository files one at a time at turn closeout.

### During the turn

1. Maintain one authoritative temporary-file inventory for the turn.
2. Add every temporary repository marker, legacy caller, legacy observation file, or generated control file when it is created. `.workflow-mailbox/**` records, durable dispatcher workflows, and `.agents/Directional/agent-dispatch-request.json` must **not** be added to the temporary-file ledger. Standard patch bytes live in Google Drive, not the repository; record their File ID separately until owner-side connector deletion or workflow-side trash is verified.
3. Classify legacy temporary workflow callers separately because workflow-first deletion rules still apply to fallback use.
4. Prefer a simple manifest under the approved cleanup trigger namespace when the durable cleanup workflow will consume it.

### At cleanup

1. Verify all required evidence has been captured first.
2. Retire the staged Google Drive patch according to `GitHub_Workflow_Policy.md`: use the user-authorized Google Drive connector `delete_file` when the file remains addressable after a successful push; otherwise retain verified workflow-side `drive_file_trashed=true` evidence.
3. If a legacy temporary caller fallback was used, delete/disable that caller **first** as required by `GitHub_Workflow_Policy.md`. The standard dispatcher/request slot is retained and never enters cleanup.
4. Then invoke the durable `.github/workflows/agent-turn-cleanup.yml` once with the manifest of remaining temporary non-workflow files when applicable.
5. The cleanup workflow should validate every manifest path, reject protected/durable/workflow paths, remove all authorized temporary files in one commit, and report what it removed.
6. Verify the temporary directories once after cleanup instead of issuing one existence check per deleted path.
7. Preserve remote immutable Actions artifacts unless retention policy authorizes deletion.

**Never** use the batch cleanup manifest to bypass workflow-first deletion or to remove durable records.

## 10. The PR is not a work surface

**Turn summaries are not posted to the PR.** A turn's closing record belongs in the durable handoff documents —
`Future_Chat_Session_Handoff.md`, the owning report/review record, `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`
and the top-level `STATUS` beacon. PR comments are not a turn-closing mechanism and no longer end a turn.
Authority: user instruction 2026-09-16.

1. Do not post turn-summary, progress, duplicate-evidence or "still running" comments.
2. Workflow run-observation comments from `github-actions[bot]` are **fallback-only** temporary operational state. `.workflow-mailbox/**` is the authoritative workflow-run rendezvous. The fallback observer may trim stale comments; comments never override a valid mailbox record and are never durable evidence.
3. Historical comments need not be preserved. The agent-turn-cleanup workflow is authorized to trim them.
4. If a fact matters, it goes in a durable document. A fact that exists only in a PR comment is not recorded.

**PR metadata, title and body are frozen.** The PR #8 title and body were set once, on 2026-09-16, to a durable
high-level description of the branch's work and a pointer to where current state actually lives. They are
**not** a status mirror and must not be updated again.

5. **Do not modify the PR title, body, labels, assignees, milestones or any other PR metadata.** Spending tool
   calls to restate turn state on the PR surface is waste: the state is already authoritative in
   `ORIENTATION.md`, `Future_Chat_Session_Handoff.md`, `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md` and the
   top-level `STATUS` beacon, and a second copy on the PR drifts within one turn.
6. Do not re-read unchanged PR metadata either. Read it once if genuinely needed for navigation, never per
   sub-step.
7. The only authorized future change to the PR title or body is an explicit user instruction to change it.
   Authority: user instruction 2026-09-16.

## 11. End-of-turn conservation procedure

Before final closeout:

1. Confirm all source/static analysis that could be done from the local snapshot has been completed locally.
2. Confirm workflow evidence was collected using run-level/job-level batch reads rather than repeated polling.
3. Confirm required artifacts were downloaded at most once unless a retry was justified.
4. Remove legacy temporary workflow callers first if the fallback path was used; never remove the durable dispatcher/reusables.
5. Run one manifest-driven cleanup for remaining temporary files when applicable.
6. Inspect `.github/workflows`, `.agents/Directional/agent-dispatch-request.json`, `.agents/connector-triggers`, `.agents/workflow-observation`, `.agents/Directional/turn-payloads`, and the relevant `.workflow-mailbox/<workflow-key>/` record once to verify final hygiene. Preserve the durable request slot and mailbox history.
7. Verify the branch head once after cleanup.
8. Update coherent durable documentation in one batch where practical.
9. Do not touch the PR title, body or metadata. They are frozen — see §10.
10. Finish and push durable documentation before the final beacon. No PR comment is posted.
11. Publish the final repository-root `STATUS` beacon by direct GitHub-connector write. For COMPLETE, set `Ended at` to the current UTC timestamp; for an incomplete yield, leave `Ended at` empty. The COMPLETE beacon is the final repository write of the turn.
12. Report the in-memory tool-call ledger total and category breakdown at closeout, without spending additional tool calls to do so.

## 12. Decision table

| Need | Default low-call strategy |
|---|---|
| Turn entry/resume beacon | Read root `STATUS` + immediate direct GitHub write before every other repository mutation |
| PR/branch identity | One `get_pr_info`/authority read after the bootstrap beacon; reuse until a real write/race boundary |
| One small known file | One direct connector fetch |
| Several files / large source / iterative review | **Mandatory `READ_MODE=snapshot` before first source/document read**; one exact source snapshot, then local inspection |
| Repo-wide symbol/search analysis | Snapshot + local `rg`/grep |
| Compare two source authorities | One commit comparison; snapshot locally if deeper inspection is needed |
| Change several related code/docs files | Snapshot -> local verified backup patch -> Google Drive File ID -> one `drive_apply` dispatcher request -> verify semantic commit -> Drive owner cleanup |
| Compile/package an exact source | One `compile` dispatcher request pinned to literal source SHA and approved targets |
| Execute artifact-only Test + Benchmark | One `test_benchmark` dispatcher request pinned to exact executor/harness/source authority; durable TB reusable only |
| Validate durable dispatcher workflows | Dispatcher self-validation jobs; separate validation only when modifying durable workflow YAML |
| Observe a push workflow | Read `.workflow-mailbox/<workflow-key>/latest.json` as authoritative completed-run discovery; use PR observer/recent-runs only as fallback; then query the exact run/jobs |
| Diagnose successful workflow | Job summary + required evidence only; no blanket log downloads |
| Diagnose failed workflow | One job inventory, then logs for failed/relevant job(s) |
| Inspect immutable artifact | Download once, verify once, inspect locally |
| Delete many temp files | One inventory + one cleanup workflow after workflow-first deletion |
| Workflow PR comments | Fallback-only temporary observations; never authoritative when a valid mailbox record exists; trim stale ones, post none routinely |
| Tool-call accounting | Maintain an in-memory ledger; report it without accounting-only tool calls |
| Turn summary | Durable handoff documents + `STATUS`; no PR comment |

## 13. Tool-call waste patterns that are prohibited unless justified

- Performing any repository mutation before the required entry/resume `STATUS` beacon write.
- Beginning source/document inspection before choosing `READ_MODE`.
- Choosing `direct` when the turn is already known to require three or more repository files/documents, cross-file tracing, repeated inspection, or repository-wide search.
- Re-reading the same unchanged PR metadata before every sub-step, or spending any tool call to rewrite the PR title, body or metadata.
- Fetching the same source file repeatedly by overlapping line ranges when a source snapshot is available or was required by Step 2.
- Continuing piecemeal connector reads after snapshot acquisition failed without recording and justifying the explicit Step-3 fallback.
- Searching GitHub separately for every symbol after the repository is already materialized locally.
- Fetching every successful workflow job's full log by default.
- Polling an Actions run in rapid succession without a plausible state-change interval.
- Treating a PR observer comment or `.agents/workflow-observation/**` file as the authoritative run marker when a valid matching `.workflow-mailbox/**` record exists.
- Re-triggering a workflow solely because final mailbox publication has not appeared while the workload may still be running.
- Deleting or adding `.workflow-mailbox/**` records to the temporary cleanup manifest.
- Re-fetching an artifact's remote contents after it has been downloaded and verified locally.
- Staging patch bytes/Base64/fragments in the repository instead of using the Google Drive File-ID transport for non-minor code/docs changes.
- Creating a temporary workflow YAML or trigger marker for Drive apply, compile/package, or artifact-only Test + Benchmark work that fits the durable dispatcher contract.
- Deleting or adding `.agents/Directional/agent-dispatch-request.json` to temporary cleanup; it is a retained mutable control slot.
- Deleting temporary files with one connector call per path when a safe manifest-driven cleanup is available.
- Posting PR comments at all as a turn-closing or evidence-recording mechanism; durable documents own that.
- Creating one schema-validation run per workflow when the files can be validated in one matrix run.
- Making multiple sequential repository commits for a coherent multi-file change when one atomic Git tree commit is practical.
- Making any repository mutation after the final COMPLETE `STATUS` beacon.
- Making any tool call solely to reconstruct, persist, or verify the in-memory tool-call ledger.

## 14. Exceptions and stop conditions

Use additional tool calls when they are required to preserve correctness. Examples include:

- branch authority changed and a write must be rebased/reconstructed;
- a downloaded artifact fails verification and must be re-fetched;
- a workflow job failed and detailed logs are required;
- current-source truth differs from the frozen snapshot authority;
- a connector response was truncated such that a required fact is genuinely unavailable;
- a policy requires independent verification from two distinct authorities;
- cleanup verification found unexpected temporary state;
- a mandatory stop rule requires returning to Review.

When an exception causes extra calls, record the reason in the turn evidence if it is material. Do not optimize away a required independent check.

## 15. Relationship to other policies

This policy changes **how efficiently** tools are used, not what work is allowed.

- `GitHub_Workflow_Policy.md` remains authoritative for workflow lifecycle, permissions, schema validation, execution boundaries, workflow-first cleanup, and evidence.
- `RETENTION_POLICY.md` remains authoritative for durable information and destructive-edit restrictions.
- `CLEAN_UP_POLICY.md` remains authoritative for stale repository evidence cleanup.
- `LESSONS.md` remains authoritative for accumulated failure-derived operating lessons.
- `Future_Chat_Session_Handoff.md` remains authoritative for the exact next turn and mandatory start/end checklists.

If conservation conflicts with any stronger safety, evidence, turn-boundary, retention, or user instruction, the stronger rule wins.

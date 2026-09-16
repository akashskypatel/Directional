# `[ChatGPT Web]` Agent Tool Use Conservation Policy

## Status — DURABLE, DO NOT DELETE

This document is durable project authority under `RETENTION_POLICY.md`. It defines the mandatory strategy for minimizing GitHub connector, workflow-observation, artifact, and repository-maintenance tool calls without weakening source authority, turn boundaries, evidence requirements, or cleanup safety.

**Reading this file in full is a mandatory start-of-turn step for every turn.** It is not satisfied by having read it in a prior turn. Apply it before choosing how to inspect repository source, create or monitor workflows, mutate multiple files, collect evidence, clean temporary state, or write PR comments.

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

1. Initialize the ledger at zero before the first tool invocation of the turn. The mandatory policy-read invocation counts like any other tool call.
2. Increment the total exactly once for every actual tool invocation, including tool discovery, connector reads, connector writes, workflow/run/job/log queries, artifact transfers, local container/Python execution, web access, retries, and failed/erroring calls. Pure model reasoning and the user-facing final response do not increment it.
3. Maintain both the exact total and a mutually exclusive primary breakdown by invoked tool namespace/family. The default report families are `GitHub connector`, `API/tool discovery`, `workflow evidence/action`, `artifact transfer`, `local container/Python`, `web/external`, and `other`; when a call could fit more than one family, assign it to one primary family only so category totals equal the overall total.
4. Ledger maintenance is internal bookkeeping. **Never invoke a tool merely to increment, persist, inspect, or total the ledger.** Updating an in-memory counter is not a tool call and consumes no tool-call budget.
5. If turn state is compacted or summarized, carry the current total and category counters forward as resume-critical turn-local state. Do not reconstruct already-known calls from GitHub, Actions, logs, or another service after compaction.
6. If the ledger is genuinely lost or incomplete, report it as partial/unknown rather than guessing, and do not spend tool calls solely to reconstruct historical counts.
7. At closeout, report the total and category breakdown without making any additional call for accounting. If a final PR summary comment is required, that comment invocation is itself a tool call: compute the final count as including that last invocation and include that final count in the summary. No later tool call may be made merely to verify the count.
8. Tool-call totals are an efficiency metric, not an acceptance criterion. Never avoid a correctness-, evidence-, policy-, or race-preserving call just to keep the number low.

### Step 1 — resolve remote authority once

1. Read the PR or configured branch authority once at the beginning of the turn.
2. Record repository, branch, PR number, head SHA, base SHA, draft/open state, and requested turn type.
3. Treat that recorded head as the initial authority for reads and planning.
4. Do not repeatedly request PR metadata during the same unchanged phase.
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
3. Capture the workflow run ID once through the normal observer/run-inventory path.
4. Fetch the run's jobs once after the run is known.
5. Fetch its artifacts once after the snapshot job is terminal.
6. Download the source snapshot artifact once.
7. Verify snapshot metadata and hashes against the requested source SHA before relying on it.
8. Extract the snapshot into a turn-local directory in the container.
9. Perform all subsequent static source inspection locally with `grep`, `rg`, `find`, `sed`, `awk`, Python, or other filesystem tools.
10. Reuse that extracted snapshot for the entire unchanged source phase.
11. Refresh the snapshot only when semantic/source authority actually changes and the next analysis depends on the changed source.

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
5. Use one minimal temporary caller/marker to invoke durable `agent-google-drive-reusable.yml`, which downloads by File ID, verifies/applies/commits/pushes, then may move the Drive file to trash after a successful push when its authenticated Drive identity has `capabilities.canTrash`; otherwise it reports that owner-authorized Drive retirement is required without issuing a known-failing mutation.
6. After the successful push and required evidence are verified, use the **user-authorized Google Drive connector** as the owner-side cleanup plane. If the staged patch remains addressable, permanently delete that exact File ID/URL with one `delete_file` call. Do not spend workflow retries on a service-account `DELETE` that lacks ownership permission. If workflow-side trash already made the file inaccessible to the connector, accept the recorded `drive_file_trashed=true` result rather than adding search/retry calls solely to locate a trashed object.
7. Retire the temporary caller first and batch-clean the remaining marker/control state. Patch bytes/fragments do not belong in the repository.

Use individual `update_file`/`create_file` operations for a genuinely isolated small file when every individual content write is within the handoff's direct-write ceiling. Workflow YAML changes follow `GitHub_Workflow_Policy.md` and are not applied by the Drive patch workflow.

### Prepare first, write once

Do not interleave discovery and mutation when it can be avoided. Finish the local census/plan, compute the complete intended diff, then write the coherent batch.

## 6. Workflow creation and schema validation batching

Workflow safety requirements remain unchanged, but validation can be batched.

1. Draft all workflows needed for the same orchestration phase before publishing them.
2. When several workflow files require SchemaStore validation, use one matrix/batch validation caller rather than one schema-validation workflow run per file.
3. Reuse durable reusable workflows (`agent-compile-reusable.yml`, `agent-google-drive-reusable.yml`, `agent-run-observer-reusable.yml`, `agent-recent-workflow-runs-reusable.yml`, `agent-workflow-schema-validator-reusable.yml`, and source-snapshot/cleanup utilities) instead of duplicating their logic in turn-specific callers.
4. Keep temporary caller installation and trigger-marker creation as separate commits where `GitHub_Workflow_Policy.md` requires it. Tool conservation never overrides this safety boundary.
5. A diagnosed workflow correction should update the caller once, then use one new trigger. Do not perform marker-only retries for an unchanged deterministic failure.

## 7. Workflow observation without polling waste

After a workflow is triggered:

1. Use the run observer or the durable recent-runs inventory to obtain the numeric run ID once.
2. Do not repeatedly fetch PR comments looking for the same run ID.
3. Once the run ID is known, fetch the run's jobs once to establish job IDs/status.
4. Avoid rapid polling. Re-query only when enough time has elapsed for the workload to plausibly change state or when an external event indicates completion.
5. When terminal, fetch the jobs once more if needed, then fetch detailed logs only for the workload/diagnostic jobs required for evidence or diagnosis.
6. Fetch the run artifact inventory once after terminal completion.
7. Download each required artifact once and inspect it locally thereafter.
8. If the connector cannot authoritatively locate a push run, invoke `agent-recent-workflow-runs-reusable.yml` once and inspect its packaged result instead of issuing repeated unsupported commit-run queries.

An absent result from a connector endpoint known not to enumerate push runs is not a reason to repeat the same call.

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
2. Add every temporary repository marker, caller, observation file, or generated control file when it is created. Standard patch bytes live in Google Drive, not the repository; record their File ID separately until owner-side connector deletion or workflow-side trash is verified.
3. Classify temporary workflow callers separately because workflow-first deletion rules apply.
4. Prefer a simple manifest under the approved cleanup trigger namespace when the durable cleanup workflow will consume it.

### At cleanup

1. Verify all required evidence has been captured first.
2. Retire the staged Google Drive patch according to `GitHub_Workflow_Policy.md`: use the user-authorized Google Drive connector `delete_file` when the file remains addressable after a successful push; otherwise retain verified workflow-side `drive_file_trashed=true` evidence.
3. Delete/disable temporary workflow callers **first**, as required by `GitHub_Workflow_Policy.md`.
4. Then invoke the durable `.github/workflows/agent-turn-cleanup.yml` once with the manifest of remaining temporary non-workflow files.
5. The cleanup workflow should validate every manifest path, reject protected/durable/workflow paths, remove all authorized temporary files in one commit, and report what it removed.
6. Verify the temporary directories once after cleanup instead of issuing one existence check per deleted path.
7. Preserve remote immutable Actions artifacts unless retention policy authorizes deletion.

**Never** use the batch cleanup manifest to bypass workflow-first deletion or to remove durable records.

## 10. PR comment conservation

PR comments are evidence/navigation aids, not a tool-call log.

1. Keep human/agent turn summaries to **one final summarized PR conversation comment per turn** unless a policy explicitly requires another durable comment.
2. Do not post per-step progress comments, duplicate evidence comments, or repeated "still running" comments.
3. Workflow run-observation comments are temporary operational state. The durable observer should trim stale `github-actions[bot]` observation comments before posting the current one, using the configured stale-comment deletion action or agent-turn-cleanup workflow.
4. The final turn-summary PR comment remains the final repository write/tool action of the turn when the handoff requires it. After that comment, perform no further repository/tool mutations.
5. Historical comments, not including the current end-of-turn summary, do not need to be preserved. Use of agent-turn-cleanup workflow is authorized to be used to trim historical comments.

## 11. End-of-turn conservation procedure

Before final closeout:

1. Confirm all source/static analysis that could be done from the local snapshot has been completed locally.
2. Confirm workflow evidence was collected using run-level/job-level batch reads rather than repeated polling.
3. Confirm required artifacts were downloaded at most once unless a retry was justified.
4. Remove temporary workflow callers first.
5. Run one manifest-driven cleanup for remaining temporary files when applicable.
6. Inspect `.github/workflows`, `.agents/connector-triggers`, `.agents/workflow-observation`, and `.agents/Directional/turn-payloads` once to verify final hygiene.
7. Verify the branch head once after cleanup.
8. Update coherent durable documentation in one batch where practical.
9. Update the PR body only if its durable current-state summary actually changed.
10. Post one final summarized PR comment as the final repository write when required.
11. Report the in-memory tool-call ledger total and category breakdown at closeout. When item 10 applies, include the item-10 comment invocation in the reported final total and make no subsequent tool call merely to recount or verify the ledger.

## 12. Decision table

| Need | Default low-call strategy |
|---|---|
| PR/branch identity | One `get_pr_info`/authority read; reuse until a real write/race boundary |
| One small known file | One direct connector fetch |
| Several files / large source / iterative review | **Mandatory `READ_MODE=snapshot` before first source/document read**; one exact source snapshot, then local inspection |
| Repo-wide symbol/search analysis | Snapshot + local `rg`/grep |
| Compare two source authorities | One commit comparison; snapshot locally if deeper inspection is needed |
| Change several related code/docs files | Snapshot -> local verified backup patch -> Google Drive File ID -> `agent-google-drive-reusable.yml` apply/push/delete -> retire temp caller/marker |
| Validate several workflow YAML files | One matrix schema-validation run |
| Observe a push workflow | One observer/recent-runs lookup; then run/job IDs |
| Diagnose successful workflow | Job summary + required evidence only; no blanket log downloads |
| Diagnose failed workflow | One job inventory, then logs for failed/relevant job(s) |
| Inspect immutable artifact | Download once, verify once, inspect locally |
| Delete many temp files | One inventory + one cleanup workflow after workflow-first deletion |
| Workflow PR comments | Trim stale bot observations; retain one current observation |
| Tool-call accounting | Maintain an in-memory ledger; report it without accounting-only tool calls |
| Turn summary | One final PR conversation comment |

## 13. Tool-call waste patterns that are prohibited unless justified

- Beginning source/document inspection before choosing `READ_MODE`.
- Choosing `direct` when the turn is already known to require three or more repository files/documents, cross-file tracing, repeated inspection, or repository-wide search.
- Re-reading the same unchanged PR metadata before every sub-step.
- Fetching the same source file repeatedly by overlapping line ranges when a source snapshot is available or was required by Step 2.
- Continuing piecemeal connector reads after snapshot acquisition failed without recording and justifying the explicit Step-3 fallback.
- Searching GitHub separately for every symbol after the repository is already materialized locally.
- Fetching every successful workflow job's full log by default.
- Polling an Actions run in rapid succession without a plausible state-change interval.
- Re-fetching an artifact's remote contents after it has been downloaded and verified locally.
- Staging patch bytes/Base64/fragments in the repository instead of using the Google Drive File-ID transport for non-minor code/docs changes.
- Deleting temporary files with one connector call per path when a safe manifest-driven cleanup is available.
- Posting a PR comment for every workflow phase, retry, cleanup step, or evidence item.
- Creating one schema-validation run per workflow when the files can be validated in one matrix run.
- Making multiple sequential repository commits for a coherent multi-file change when one atomic Git tree commit is practical.
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

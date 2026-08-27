# `[ChatGPT Web]` GitHub Workflow Policy

## Purpose

GitHub is the control plane; GitHub Actions is the bounded remote execution plane for computation the connector cannot perform. The turn-based cadence remains authoritative. Actions never relax Code + Build, Test + Benchmark, or Review boundaries.

Retention and destructive-mutation rules: `RETENTION_POLICY.md`. Repository cleanup: `CLEAN_UP_POLICY.md`.

## Working-branch policy

Perform agent work directly on the configured working branch. Do **not** create temporary, control, side, or staging branches unless doing so is absolutely necessary to circumvent a concrete procedural blocker that cannot safely be resolved on the working branch. When such an exception is unavoidable, record the blocker and why the branch is necessary, keep the branch narrowly scoped, and remove or reset it as soon as the blocker is cleared.

## Test + Benchmark regression documentation gate

Every Test + Benchmark turn MUST categorize every observed regression in `.agents/Directional/Regression_Root_Cause_Tracker.md` and record root-cause analysis before the turn closes. If the evidence does not justify a stable regression ID or historical-count change, record a candidate/non-stable entry and explicitly state why the stable totals remain unchanged. A Test + Benchmark turn with regression evidence is not durably complete until this tracker update is committed.

## Explicit Allowed use of Github Workflow

Github workflows may only be used for the following actions. Unauthorized use is explicitly DISALLOWED.

- Run long running compile/build jobs that would take too long or too much resources to run in local container
- Applying a verified non-minor code/documentation patch staged externally in `My Drive/Directional-CI` and addressed by Google Drive File ID, using durable `agent-google-drive-reusable.yml`.
  - Using workflows to apply small changes that are easily and safely done with the GitHub connector API is **explicitly unauthorized**. Keep direct write mode for genuinely minor changes within the observed connector write ceiling.
  - Repository-staged Base64 patch payloads/fragments are no longer the standard patch transport and must not be created for new turns.
- Generating repository code snapshot to download to local container
- Querying the repository-wide GitHub Actions runs API and packaging the result for monitoring/error diagnosis when the connector cannot directly list `repos/<owner>/<repo>/actions/runs`.
- Validating a GitHub Actions YAML draft against the current SchemaStore GitHub-workflow schema before publishing or updating `.github/workflows/**`.
- Any other special actions not available using Github connector API surface.

## Durable workflows

Retain these durable workflows on the working branch:

- `.github/workflows/agent-source-snapshot.yml` — historical/source-snapshot utility only; not an approved current compile/test entry point.
- `.github/workflows/agent-compile-reusable.yml` — **mandatory reusable compile implementation for every build/compile task**.
- `.github/workflows/agent-google-drive-reusable.yml` — mandatory reusable transport for non-minor source/documentation patches. It downloads the exact staged patch by Google Drive File ID, verifies full/diff-body hashes and base/touched-path authority, applies/commits/pushes it, and only after a successful push may move the staged file to Drive trash when its workflow identity is authorized. Final owner-side retirement is performed from the ChatGPT control plane with the user-authorized Google Drive connector. It must reject patches that modify `.github/workflows/**`.
- `.github/workflows/agent-run-observer-reusable.yml` — reusable run-ID observer for early PR-comment reporting and an optional temporary branch-file fallback.
- `.github/workflows/agent-recent-workflow-runs-reusable.yml` — reusable authenticated Actions-run inventory. It queries `repos/${GITHUB_REPOSITORY}/actions/runs` with `GH_TOKEN` falling back to `github.token`, and uploads raw, summarized, attention-only, TSV, and query-metadata artifacts for connector-side monitoring and error diagnosis.
- `.github/workflows/agent-workflow-schema-validator-reusable.yml` — mandatory reusable pre-publication GitHub-workflow schema validator. It validates YAML against SchemaStore's `github-workflow.json`, uploads a validation report and diagnostic log, and fails closed on schema or document validation errors.

Any workflow that compiles Directional must call `agent-compile-reusable.yml`. Do not duplicate its checkout, configure, compile, ccache, cache-pruning, packaging, or compile-evidence logic in a turn-specific workflow. A temporary caller may provide the exact source SHA, approved targets, artifact prefix, narrowly scoped trigger, and a separate call to `agent-run-observer-reusable.yml` for run observability. **A caller must not provide or invent a cache epoch, cache namespace, cache compatibility key, or per-turn cache lineage.** The reusable compile workflow alone owns cache compatibility/versioning.

## Mandatory GMP compile backend

`.agents/Directional/GMP_COMPILE_POLICY.md` is binding on every compile. For ChatGPT Web, `agent-compile-reusable.yml` is the mandatory implementation authority: it must provision GMP, configure `DIRECTIONAL_ENABLE_GMP=ON`, verify CMake discovery, verify both `gmpxx` and `gmp` on an authoritative generated link command, and package `exactArithmeticBackend=GMP` evidence. A missing GMP dependency, a disabled GMP option, failed link verification, or fallback `BigInteger`/`ExactNumber` selection is a **compile failure**, not a supported fallback. Turn-specific callers may not expose or supply an option that weakens this requirement.

Turn-specific callers, trigger markers, patch/payload files, generated workflow-observation files, and generated repository artifacts are temporary and must be removed after their result/log artifacts and exact source authority are verified.

## Mandatory workflow contract

Every agent workflow must:

1. initialize a persistent activity log before checkout or other fallible work;
2. record event/ref/source identity, tool versions, commands/output, exit context, final source status, and relevant resource/cache state;
3. stream task output to both console and the persistent log;
4. upload the dedicated diagnostic log under `if: always()` and `if-no-files-found: error`;
5. keep diagnostic logs separate from successful result artifacts;
6. use narrow triggers, `concurrency` where applicable, least privilege, and exact source/hash checks;
7. keep logs/evidence under the runner temporary directory, not the source tree;
8. never print secrets, credentials, authenticated URLs, or secret-bearing arguments;
9. never modify `.github/workflows/**` from inside a workflow;
10. use indentation-safe YAML/shell construction;
11. validate every new or modified GitHub workflow YAML against `.github/workflows/agent-workflow-schema-validator-reusable.yml` before it is treated as publishable workflow authority. Draft new workflows outside `.github/workflows/**` when practical, validate the draft first, then publish it. For an existing workflow that must be edited in place, validate the exact resulting file before triggering it. Schema validation complements but does not replace reusable-input and permission-ceiling checks.

## `[ChatGPT Web]` Standard Google Drive patch transport

For coherent source/code or documentation edits that are not a genuinely minor direct connector write, this is the required patch transport:

1. Obtain and verify one exact source snapshot with `agent-source-snapshot.yml`.
2. Edit only the local snapshot-derived tree. Generate one complete `git diff --binary --full-index --no-ext-diff` patch, including new/deleted/binary files as needed, with the retention-policy metadata header. Verify `git apply --check` against the exact base and `git diff --check`.
3. Emit the exact patch as a user-visible downloadable chat/File-Library backup **before** remote orchestration.
4. Upload those exact patch bytes with the Google Drive connector to `My Drive/Directional-CI`; retain the returned File ID and complete patch SHA-256. Do not create repository patch payloads, compressed Base64, or fragments.
5. Install a minimal temporary caller whose workload uses `./.github/workflows/agent-google-drive-reusable.yml` and passes `file_id`, `patch_sha256`, `base_sha`, target branch, and commit message with `secrets: inherit`. Keep caller installation and its push marker in separate commits.
6. The reusable must download by File ID, verify full patch SHA-256 and embedded `base_sha`/`diff_body_sha256`/`intended_paths`, prove no intended path changed between patch base and caller event SHA, run `git apply --check`, apply, run `git diff --check`, prove the actual changed-path set equals the intended set, commit, and push without force.
7. Patch transport is forbidden from changing `.github/workflows/**` because workflows may not modify workflow files from inside Actions. Workflow-file edits remain direct GitHub connector writes within the safe content ceiling and must be schema-validated before execution.
8. **Only after the patch commit pushes successfully** and required result/log evidence are verified, perform final staging cleanup from the ChatGPT control plane with the **user-authorized Google Drive connector**. If the staged patch is still addressable, call the connector's permanent `delete_file` action on that exact Drive File ID/URL and require a successful deletion result.
9. After Drive cleanup evidence is verified, delete the temporary caller first, then remove the marker and remaining temporary repository control state. The repository not Google Drive should contain no patch-transfer payload/fragments.

The chat/File-Library backup is durability/recovery material; Google Drive is transient remote transport; the pushed Git commit becomes repository authority.

## Run-ID observability

The connector's commit-to-workflow discovery surface is not authoritative for push-triggered workflows: `fetch_commit_workflow_runs` currently filters to `pull_request` events. An empty result from that wrapper must **never** be interpreted as proof that a push workflow did not run.

For turn-specific push callers, report the **workflow run ID** (the per-execution `github.run_id`, not the stable workflow-definition ID) through `.github/workflows/agent-run-observer-reusable.yml` as soon as the run starts. The run ID is an observation handle only; acceptance still requires the run/job/artifact/source evidence required by the active turn.

Authentication:

- `agent-run-observer-reusable.yml` accepts optional workflow-call secret `GH_TOKEN`. Same-repository callers should use `secrets: inherit` so the repository Actions secret named `GH_TOKEN` is available without copying it into workflow text.
- The observer prefers `secrets.GH_TOKEN` and falls back to `github.token` when the secret is absent. It records only the non-secret source label (`GH_TOKEN-secret` or `github-token`); it must never print or persist the token value.
- Use the fine-grained `GH_TOKEN` for workflow-originated repository writes that may need to trigger later workflows. Pushes authenticated with the default `GITHUB_TOKEN` are intentionally suppressed from recursively creating most new workflow runs, while a PAT-authenticated push is a normal authenticated repository event. Do not rely on the default token when a follow-up push-triggered workflow is part of the intended control flow.

Primary channel:

- PR conversation comment. Pass `pr_number: 8` for the active PR and give the caller `issues: write` and `pull-requests: write` permissions for the `github.token` fallback. The observer posts the run ID, exact run URL, event, event SHA, and non-secret token-source label. This channel does not mutate the branch and is the default.
- **Current reusable-observer permission caveat:** `agent-run-observer-reusable.yml` also contains the optional `branch-file` job, whose nested job requests `contents: write`. GitHub validates the permission ceiling of nested reusable-workflow jobs even when `commit_run_file: false` causes that job to skip. Therefore every caller of the current observer reusable must grant caller-level `contents: write`; `contents: read` makes the entire caller invalid at workflow-validation/startup time. Do not reduce this permission until the branch-file observer is split out or its reusable-workflow contract changes.

Optional fallback channel:

- Temporary branch file. Pass `commit_run_file: true` plus the exact `report_branch`, and give the caller `contents: write` permission. The observer writes `.agents/workflow-observation/run-<run-id>.txt` only after verifying that the remote branch still equals the workflow event SHA, then pushes one bot-authored observation commit. This is a fallback because it advances the branch head and therefore creates cleanup/race surface.
- If both channels are enabled, they run independently so failure of one does not suppress the other.
- Any generated `.agents/workflow-observation/run-*.txt` file is temporary control state and must be removed after the run ID has been captured and the triggering workflow has been removed/disabled.

## Exact procedure for drafting, executing, observing, and deleting a temporary workflow

Use this procedure for every agent-created GitHub Actions workflow whose run must be observed from the connector. The purpose is to make workflow execution deterministic and to prevent malformed callers, missed push runs, trigger races, permission failures, and cleanup debris. Do not improvise a different lifecycle unless the active task requires event semantics that cannot be represented by the standard push-marker pattern.

### Phase 0 — preflight and fixed decisions

Before writing any workflow file:

1. Re-read this policy and fetch the current versions of every reusable workflow the caller will invoke. At minimum, inspect `.github/workflows/agent-workflow-schema-validator-reusable.yml`; if observation is required, inspect `.github/workflows/agent-run-observer-reusable.yml`; if compilation is required, also inspect `.github/workflows/agent-compile-reusable.yml`; if repository-wide Actions monitoring is needed, inspect `.github/workflows/agent-recent-workflow-runs-reusable.yml`.
2. Inspect the working branch's `.github/workflows/`, `.agents/connector-triggers/`, `.agents/workflow-observation/`, and `.agents/Directional/turn-payloads/` directories. Do not reuse a stale temporary caller, marker, observation file, or payload from an earlier run.
3. Choose and record all control-plane names before drafting:
   - one unique temporary caller path under `.github/workflows/`;
   - one unique marker path under `.agents/connector-triggers/`;
   - one stable observer label for the run;
   - the exact working branch;
   - the exact PR number when a PR exists;
   - whether branch-file observation is disabled (default) or explicitly justified;
   - the Google Drive File ID/hash for patch transport when applicable; repository patch/payload paths are not used for standard patch transport.
4. Default to a narrowly scoped `push` trigger on the working branch plus the single unique marker path. Use another event only when the task specifically requires that event's semantics. An agent-controlled workflow must never use a broad branch-wide push trigger merely to make execution easier.
5. Compute caller permissions as the **union of permissions required by every called reusable workflow**, not only the jobs expected to execute. Reusable workflows cannot elevate beyond the caller's permission ceiling, and GitHub validates nested job permissions before runtime conditions are evaluated.
6. For the current observer reusable, caller permissions must include `contents: write`, `issues: write`, and `pull-requests: write`, even when `commit_run_file: false`. If the caller also invokes `agent-compile-reusable.yml` on a cache-write-capable event, include `actions: write` so the reusable compile workflow can refresh the compiler cache.
7. Decide the exact source identity the workload will consume. For a normal push-marker caller, `${{ github.sha }}` is the marker-trigger commit. Repository source/fixtures required by the workload must already exist before the marker-trigger commit. A standard patch itself is external Drive state referenced by immutable File ID/hash inputs, not a repository payload.

### Phase 1 — draft the caller without triggering it

Draft the temporary caller using this structure as the default shape:

```yaml
name: <unique descriptive name>

on:
  push:
    branches:
      - <exact working branch>
    paths:
      - .agents/connector-triggers/<unique-marker>.txt

permissions:
  contents: write
  issues: write
  pull-requests: write
  # Add actions: write when a called reusable workflow requires it.

concurrency:
  group: <unique stable caller group>
  cancel-in-progress: false

jobs:
  observe:
    uses: ./.github/workflows/agent-run-observer-reusable.yml
    with:
      pr_number: <PR number>
      label: <unique observer label>
      commit_run_file: false
    secrets: inherit

  <workload-job>:
    # Inline job OR reusable-workflow call, according to the task.
```

Apply these syntax rules before committing:

1. `observe:` is a **job ID under `jobs:`**. It is not a root-level workflow key and is not placed under `on:`.
2. A job that calls a reusable workflow with `uses:` must use reusable-call syntax. Do not add `runs-on:` or `steps:` to that same job.
3. Pass only inputs declared by the called workflow's `workflow_call.inputs`. Do not guess input names from an earlier caller.
4. Use `secrets: inherit` for same-repository reusable calls when repository secrets are required. Never copy secret values into YAML.
5. Keep the observer job independent of the workload job. Do not add `needs: observe` to the workload and do not make the observer depend on the workload. The observer should be able to publish the run ID immediately even when the workload fails.
6. Keep `commit_run_file: false` unless a second observation channel is specifically justified. The PR-comment channel is the default because it does not advance the branch head.
7. If branch-file observation is enabled, also pass the exact `report_branch`, retain `contents: write`, and plan to perform **no branch writes after the trigger commit until the branch-file observer either succeeds or fails**, because it requires the remote branch head to equal the event SHA.
8. For a compile workload, call `./.github/workflows/agent-compile-reusable.yml`; do not reproduce compile/cache/package steps in the temporary caller.
9. Before committing, compare the caller's permissions and inputs against the fetched reusable workflow files one final time. Permission validation is static; a nested job being skipped does not make its requested permission irrelevant.
10. Before publishing the caller as an active file under `.github/workflows/`, validate its exact YAML with `agent-workflow-schema-validator-reusable.yml`. Prefer storing the candidate under `.agents/Directional/turn-payloads/` (or another non-workflow draft path) for this pre-publication validation so malformed YAML never becomes an active workflow definition.

### Phase 2 — commit and verify caller installation

1. Commit **only the caller and any repository source/control files that must exist before execution**. Do not stage patch bytes/fragments in the repository, and do not create or modify the marker path in this commit.
2. Record the resulting caller-install commit SHA.
3. Re-fetch the caller from the working branch and confirm all of the following exactly:
   - branch name in `on.push.branches` is correct;
   - marker path in `on.push.paths` is correct and unique;
   - `jobs.observe` is under `jobs`;
   - observer `uses` points to `./.github/workflows/agent-run-observer-reusable.yml`;
   - observer `pr_number`, `label`, and `commit_run_file` are correct;
   - `secrets: inherit` is present;
   - caller permissions satisfy the union computed in Phase 0;
   - workload inputs and reusable path are correct;
   - no unintended broad trigger exists.
4. Re-fetch any repository source/control file required by the workload and verify it is present at branch authority before triggering. For Drive patch transport, verify the retained File ID and patch SHA-256 rather than a repository payload.
5. Do **not** treat the caller-install commit as an execution attempt. The marker has not changed, so the workflow should not be considered triggered.

### Phase 3 — trigger exactly once

1. Create or modify the exact marker file in `.agents/connector-triggers/` in a **separate later commit**. This marker commit is the execution trigger.
2. Put a short human-readable purpose, expected source/run boundary, and retry number in the marker text when useful. The marker content is control metadata only; it must not alter runtime semantics.
3. Record the marker-trigger commit SHA. For a standard push caller, this is the expected `github.sha` reported by the observer and normally the source SHA passed to the workload.
4. After the trigger commit, do not make another repository write until the observer has reported the run ID. If branch-file observation is enabled, do not advance the branch at all until that observer job completes or fails.
5. Trigger once. Do not edit the marker repeatedly because no run ID appeared immediately.

### Phase 4 — obtain the run ID through the observer

1. Read the PR conversation and locate the observer comment with the exact label. The expected shape is:

   `[agent-run] <label>: run_id=<id>; event=<event>; event_sha=<sha>; url=<run-url>; token_source=<source>`

2. Verify that `event_sha` equals the marker-trigger commit SHA. Reject a comment with the same label but a different event SHA as stale or unrelated.
3. Record the numeric **workflow run ID**. Do not confuse it with a workflow-definition ID, job ID, artifact ID, or commit SHA.
4. Do not use `fetch_commit_workflow_runs` as proof of presence or absence for push runs. Its connector behavior is not authoritative for push-triggered workflows.
5. If the expected observer comment is absent, do not trigger again yet. Use `.github/workflows/agent-recent-workflow-runs-reusable.yml` to query `repos/${GITHUB_REPOSITORY}/actions/runs` and inspect its artifact for the workflow filename plus branch/event SHA; also inspect the optional `.agents/workflow-observation/run-<run-id>.txt` fallback if it was explicitly enabled. Only after determining whether a run exists may a retry be considered.

### Phase 5 — observe execution and collect evidence

After the run ID is known:

1. Fetch the workflow run's jobs by that exact run ID.
2. Confirm the expected observer and workload jobs exist. A workflow with no runnable jobs or a `startup_failure` is an orchestration failure, not task evidence.
3. Wait for the workload job to reach a terminal conclusion. Do not infer completion from the observer job finishing; the observer is intentionally independent and usually finishes first.
4. Fetch the exact workload job logs after the job completes. Diagnose failures from detailed logs, not only the Actions summary.
5. Fetch the workflow run artifacts and verify expected result/log artifacts, IDs, names, and digests required by the active turn.
6. Verify source identity from both observer `event_sha` and workload/package metadata. For compile workflows, verify `runtimeExecution=false` and the exact compiled source/package authority required by the Code + Build turn.
7. Record the run ID, workload job ID, source SHA, result/log artifact IDs and digests, and terminal conclusion before cleanup begins.

### Phase 6 — deterministic retry rules

Do not use trial-and-error retries.

1. If GitHub reports the caller as an **invalid workflow** or `startup_failure`, do not change the marker first. Diagnose the caller YAML, reusable-workflow inputs, and caller permission ceiling against the current reusable workflow definitions.
2. A nested reusable job requesting a permission above the caller ceiling is a caller-validation error even if that nested job has an `if:` condition that would skip it. Fix the permission ceiling; do not attempt to work around validation with runtime conditions.
3. Commit the caller correction in a commit that does **not** touch the marker path. Re-fetch and verify the corrected caller using the Phase 2 checklist.
4. Only after the corrected caller is branch authority, modify the marker in another separate commit to create one diagnosed retry.
5. If the workflow started and the workload job failed, inspect its exact logs first. Change only the diagnosed workflow/payload/source defect. Then follow the same two-commit sequence: correction commit first, marker-trigger commit second.
6. Never combine caller installation/correction and marker triggering in the same commit.
7. Never rerun an unchanged deterministic failure merely to see whether it passes on the next attempt.

### Phase 7 — cleanup in workflow-first order

Cleanup begins only after the run, logs/artifacts, and source identity have been verified and all durable facts required by the active turn have been preserved.

1. Re-read the current working-branch head before cleanup. If a branch-file observer was enabled, account for any bot-authored observation commit before mutating files.
2. Fetch the temporary caller, marker, and observation/control files to obtain their current blob SHAs. Do not delete using stale SHAs. Standard patch bytes are external Drive state; after a successful push the reusable moves them to trash when its Drive identity has `capabilities.canTrash`, otherwise it reports that owner-authorized Drive retirement is still required.
3. **Delete the temporary workflow caller first.** Commit that deletion and verify the caller no longer exists on the working branch.
4. Only after the caller deletion is branch authority, delete the marker file. Deleting the marker after the caller is gone prevents cleanup from triggering the temporary workflow again.
5. For a successfully pushed Drive patch, verify either `drive_file_trashed=true` or `drive_file_retirement_required=true`. If retirement is required, use the owner-authorized Drive control plane to retire the file before turn closeout. If the workflow failed before push, retain the File ID until the retry/abandon decision is complete.
6. Delete any `.agents/workflow-observation/run-<run-id>.txt` file created by the branch-file fallback.
7. Re-inspect `.github/workflows/`, `.agents/connector-triggers/`, `.agents/workflow-observation/`, and `.agents/Directional/turn-payloads/` and verify there is no temporary state from the run. Only the durable workflows listed in this policy should remain unless another active turn has explicitly authorized temporary state.
8. Do not delete remote Actions result/log artifacts that remain authoritative evidence unless retention policy explicitly authorizes it.

### Phase 8 — final closeout

1. Verify the working branch head after cleanup.
2. Verify the temporary caller and marker return `not found`/are absent, and that no workflow-observation file for the completed run remains.
3. Verify durable workflow files are still present and unchanged except for explicitly authorized durable edits.
4. Update required durable handoff/TODO/report state for the active turn.
5. Make the final PR summary comment only after all repository mutations are complete. Per end-of-turn policy, that summary comment is the final repository write for the turn.

## Code + Build boundary

Code + Build workflows may checkout exact pushed source, apply a pre-verified source/test patch, initialize shallow submodules, configure with `PRE_TEST` or an equivalent compile-only discovery mode, compile/link approved targets, and package compile evidence.

They must not execute generated Directional binaries: no tests, benchmarks, discovery/list/help/version commands, CLI/GUI, `ctest`, fuzzers, or custom inputs. Every build package records `runtimeExecution=false`.

All compile/build execution must use `.github/workflows/agent-compile-reusable.yml`.

## Compile-cache policy

The reusable compile workflow owns compiler caching. This policy is durable. Required rules:

- Use `ccache`; do not cache an opaque CMake/Ninja build tree.
- The durable cache compatibility key is owned by `agent-compile-reusable.yml` and is derived only from stable compatibility facts: runner OS, compiler/toolchain version, build mode/configuration family, and an explicit **workflow-owned schema version**. The current key is `directional-ccache-<OS>-gcc-<compiler-version>-release-static-gmp-pretest-v2`.
- **Use exactly that fixed compatibility key for both restore and save. Do not append `github.run_id`, a turn name, source SHA, timestamp, retry number, or any other per-run/per-turn suffix.** Turn-specific workflows/callers cannot override the cache key or schema version.
- GitHub cache entries are immutable after creation. On trusted cache-write events, restore the fixed key first, finish compilation, then refresh that same key by deleting its existing branch/ref-scoped cache entry and saving the updated ccache directory under the identical key. Serialize compile-cache refreshes for a branch/ref so overlapping runs cannot race the delete/save sequence.
- Cache-write behavior is restricted to trusted events such as `push`, `workflow_dispatch`, `repository_dispatch`, and `schedule`. Other event types are restore-only and must not attempt a cache delete/save when their token is not cache-write capable.
- During migration from the former rolling-key scheme, an old `directional-ccache-...-v1-<run-id>` entry may be accepted as a one-time compatible restore through GitHub's primary-key prefix matching. After that restore, delete old rolling entries and legacy `m1-ra-*` entries for the active branch/ref and establish the fixed key.
- Source SHA is not part of the compatibility key. ccache itself validates source content and compiler command compatibility. Exact source SHA remains build/evidence authority, not cache compatibility authority.
- Cap ccache at **256 MiB** unless this policy is explicitly amended.
- Retain exactly one active fixed-key compiler cache for the compatible branch/ref. Do not accumulate per-run rolling caches.
- Save reusable compiler entries even after a compile failure when the event is cache-write capable, then propagate the original compile exit status.
- Cache object/compiler entries only. Never cache build/result artifacts, source archives, fixtures already in Git, immutable evidence, or packaged binaries.
- Log the exact fixed cache key, branch/ref scope, matched restore key/hit status, ccache statistics, configured size cap, every migration/refresh delete, and whether cache save was permitted or skipped.

A cache hit is only a performance optimization. Exact source SHA, toolchain, configure options, compile command, linked outputs, and clean source status remain build authority.

## Test + Benchmark boundary

Artifact-only Test + Benchmark turns must verify the declared immutable package before execution, extract it without repairing permissions/content, and execute only packaged binaries/inputs. Extraction must preserve archived executable mode bits (for example, ordinary `unzip`/`tar`); Python `zipfile.extractall` is prohibited for executable payloads unless the payload format explicitly restores and verifies those archived modes. A missing executable mode is an orchestration failure, not permission to `chmod` or otherwise repair the immutable package. Every artifact-only TB plan must repeat this extraction requirement in its preflight.

They must not configure, compile, relink, regenerate discovery/code, patch packaged source, or alter fixtures/manifests. A zero-selected filter is orchestration failure, never a pass.

### Full-suite timeout policy

A complete acceptance suite or full semantic gate must run uninterrupted to an organic process result. Repository workflows must not impose an elapsed-time cutoff on that execution: do not wrap the full-suite command in `timeout` or an equivalent watchdog, and do not set a workflow/job `timeout-minutes` value whose purpose is to terminate the full-suite run. Platform-level service limits remain external infrastructure constraints; the repository must not add a shorter automatic kill boundary.

Do not partition, retry, or stitch continuation results merely to evade elapsed runtime. If a complete suite appears hung, cancellation requires explicit human/user intervention or an external platform failure and is recorded as orchestration/infrastructure failure rather than semantic evidence.

Focused reproduction or diagnostic commands that are not themselves the complete acceptance/full-suite gate may use a justified bounded timeout. Any such timeout is reported as orchestration failure, never pass/skip, and cannot replace the required uninterrupted full-suite execution.

## Trigger and temporary control lifecycle

When connector dispatch is unavailable:

1. commit the temporary caller first, with one exact unique push-marker path and with that marker absent or unchanged in the caller-install commit;
2. only after the caller commit is branch authority, create or modify the exact temporary text marker under `.agents/connector-triggers/` in a **separate later commit**. This is the proven P1 pattern: first installed `.github/workflows/m2-cp1-tb-r1-closeout.yml`, then created `.agents/connector-triggers/m2-cp1-tb-r1-closeout-20260817.txt` and triggered the workflow;
3. do not combine temporary-caller installation and first marker creation in one commit, and do not treat the caller-install commit itself as the push trigger;
4. make compile callers invoke the durable reusable compile workflow and make turn-specific push callers invoke `agent-run-observer-reusable.yml` with PR-comment reporting enabled unless the active task has no PR;
5. when repository secret `GH_TOKEN` is available, pass it to reusable workflows with `secrets: inherit`; use it for workflow-originated pushes that must remain eligible to trigger later push workflows;
6. enable the branch-file observer only when a second/fallback observation channel is justified;
7. for standard non-minor code/docs patch application, keep patch bytes in Google Drive and create no repository patch/payload files; only minimal caller/marker control files are permitted;
8. trigger once unless a diagnosed retry is required;
9. discover push runs from the observer comment/file; when direct repository-wide run listing is needed, call `agent-recent-workflow-runs-reusable.yml` and use its artifact rather than guessing from absent connector results; then verify exact run, source, result/log artifacts, and outputs;
10. remove/disable the temporary caller before deleting its marker and any generated workflow-observation/control file;
11. verify final workflow, trigger, turn-payload, and workflow-observation directories, and verify the Drive patch was deleted after a successful push.

Never leave turn-specific workflow/trigger/observation debris on the long-lived branch.

## Evidence requirements

A Code + Build result should retain, as applicable: exact source SHA/archive, dependency revisions, compiled libraries/executables, configure/build logs, CMake cache, ccache/cache-prune metadata, clean source-status snapshots, command-boundary metadata, and a recursive self-excluding `SHA256SUMS` manifest.

Record run/job IDs, result/log artifact IDs and digests, exact compiled source, checks executed, and checks deliberately not executed.

## Failure rules

- Diagnose from the detailed log artifact, not only Actions summaries.
- Do not rerun deterministic malformed orchestration unchanged.
- Never synthesize success or weaken validation to obtain green output.
- A compile failure may be repaired in the same Code + Build turn when the fix is bounded and no generated runtime executes.
- Evidence-upload failure prevents acceptance even when compilation itself succeeded.
- Never force-push to bypass a race; re-read authority and retry deliberately.

## End-of-turn hygiene

At start and end of every turn inspect `.github/workflows`, `.agents/connector-triggers`, `.agents/workflow-observation`, and `.agents/Directional/turn-payloads`. Preserve durable workflows, remove stale temporary state in workflow-first order, apply `CLEAN_UP_POLICY.md`, and make the final PR #8 summary comment the final repository write.

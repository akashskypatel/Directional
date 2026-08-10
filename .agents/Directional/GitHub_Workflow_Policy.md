# GitHub Workflow Policy

## Scope

This policy governs all agent-authored GitHub Actions workflows, connector trigger files, helper payloads, and artifact-runtime workflows used while working on `akashskypatel/Directional`, especially draft PR #8 on `agent/surface_cell_quad/p5-recover-bridge-healing`.

It is durable process authority. The current turn, exact artifact, and next action are owned by `.agents/Directional/Future_Chat_Session_Handoff.md`.

## Repository-control rules

1. Keep PR #8 open, draft, and unmerged unless the user explicitly changes that instruction.
2. Review policy is `never` unless the user explicitly requests a review turn.
3. Fetch fresh PR/head state before a turn. Do not assume the branch has not moved externally.
4. Code + Build and Test + Benchmark remain separate turns. A Code + Build artifact must be immutable input to its following Test + Benchmark turn.
5. Every completed turn's **final repository write** is exactly one new top-level PR #8 conversation comment after all branch-file writes and PR metadata updates. No repository mutation follows that comment.

## Code + Build workflow rules

A Code + Build workflow may:

- apply the bounded approved source/test edits;
- install compile prerequisites;
- shallow-fetch required submodules;
- configure the approved build;
- compile/link explicitly approved targets;
- create an immutable package containing executables, libraries, fixtures, source patch/archive, source-blob metadata, toolchain/submodule data, static test manifests, command-boundary metadata, logs, and recursive checksums;
- upload result and detailed-log artifacts.

A Code + Build workflow must not execute a generated Directional binary. This prohibition includes:

- GoogleTest discovery (`--gtest_list_tests`);
- any test;
- any benchmark;
- `ctest`;
- CLI/GUI/help/version commands;
- fuzzers;
- custom input.

Record `runtimeExecution=false` and individual false flags for prohibited command classes in package metadata. `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST` is required so configure/build does not execute test binaries.

The workflow must initialize its activity log before fallible setup, preserve logs even on failure where possible, enforce the approved changed-path boundary, and push the implementation commit before build packaging so the artifact identifies one exact implementation.

## Immutable artifact rules

Every build package used by a Test + Benchmark turn must have:

- a stable workflow run/job identity;
- GitHub artifact ID and outer SHA-256 digest;
- recursive `SHA256SUMS` generated over every regular package file except the manifest itself;
- source/build authority metadata identifying base, implementation, build-event commit, workflow run/attempt, configuration, and `runtimeExecution=false`;
- exact source-blob metadata for touched and preserved authority files;
- executable content hashes;
- static focused/authority test manifests;
- fixture inventory;
- build logs and resource usage.

The following Test + Benchmark turn verifies this authority before executing any packaged binary and re-verifies it after runtime.

## Test + Benchmark workflow/runtime rules

A Test + Benchmark turn may execute only the exact immutable artifact selected by the authoritative plan. It must not configure, compile, link, regenerate, patch, substitute, or repair source/tests/fixtures/regular package content.

Before runtime:

1. verify GitHub artifact identity/digest and build-run identity;
2. reject unsafe archive paths;
3. verify the recursive manifest itself and every packaged checksum;
4. verify expected regular-file/fixture/library/executable inventory;
5. verify build authority and source blobs;
6. verify executable hashes;
7. reject zero-selection test success.

If artifact extraction strips executable permission, permission may be restored **only after content-hash verification**. Non-regular fixture locator symlinks may be created only when needed and must be recorded separately from packaged content.

Runtime classification comes from selected count, filter, stdout/stderr, return code, elapsed time, resource evidence, and the test/oracle contract—not from workflow-job success alone.

After runtime, reverify original outer ZIP hash, manifest, every package checksum, selected executable hashes, and regular-file count.

## Bunny/Vase long-runtime rule

The user authorizes ephemeral artifact-only GitHub Actions workflows for long-running Bunny/Vase comparisons when local execution limits make them impractical.

Such workflows must:

- download the exact already-built artifact by run/artifact identity;
- verify GitHub digest, complete package manifest, implementation/build authority, and selected executable hash before execution;
- configure/build/relink/regenerate nothing;
- restore executable mode only after content verification;
- run the exact existing requested test under an explicit time guard;
- retain raw runtime log, selected count, return code, elapsed time, resource usage, and postflight hashes as an evidence artifact;
- treat timeout only as bounded safety evidence, never correctness or proof of nontermination;
- remove temporary workflow/trigger/helper files before turn closeout.

## Temporary workflow lifecycle

Temporary connector workflows, trigger files, and apply scripts exist only to execute one bounded turn. Once their result/evidence artifacts have been captured:

1. verify the run/jobs/artifacts needed for the report;
2. delete the temporary trigger;
3. delete the temporary workflow;
4. delete a temporary apply script if one was committed solely for that run;
5. verify no temporary file remains in the durable workflow/agent entry points.

The durable `.github/workflows/agent-source-snapshot.yml` is not a temporary turn workflow and must not be removed by routine cleanup.

## Durable `.agents/Directional` evidence cleanup interlock

The authoritative detailed cleanup policy lives in `Future_Chat_Session_Handoff.md` and must remain there. Workflow closeout must respect it:

- every Test + Benchmark turn begins by cleaning stale prior checked-in evidence after its accepted facts are folded into durable/live authority;
- every Test + Benchmark turn ends with the newly authoritative report plus exactly one next Code + Build plan in addition to durable `.agents/Directional` documents;
- consumed Test + Benchmark plans, superseded preceding Code + Build plans/reports, old per-turn evidence indexes/machine summaries, and temporary workflow payloads are removed;
- immutable GitHub Actions artifacts remain governed by their retention settings and are not deleted merely because checked-in summaries are stale;
- retained durable docs are audited for stale live-file references and corrected before closeout.

## Failure discipline

- Infrastructure/package-authority failure before runtime is not product pass/fail. Stop before executing the package.
- A required-green runtime regression blocks advancement. Capture exact evidence and return to a corrective Code + Build plan; never patch inside the immutable turn.
- Persistence of an already-known red is not automatically a new regression recurrence. Use the stable-ID rules in `Regression_Root_Cause_Tracker.md`.
- Never make a test pass synthetically, weaken a validator, substitute generic output, or classify workflow success as product success.

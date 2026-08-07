# Directional GitHub Workflow Policy

## Purpose

GitHub Actions is a bounded remote execution plane for Directional agent work when the GitHub connector can manage repository state but cannot directly run compilers, tests, benchmarks, or other repository tools. It never relaxes the active turn boundary.

## Turn boundaries

### Code + Build

Allowed:

- apply an exact verified source/test patch;
- configure with compile-only-safe discovery such as `PRE_TEST`;
- compile/link only approved targets;
- package exact source authority, binaries/libraries, fixtures, logs, metadata, and checksums.

Forbidden:

- executing generated Directional binaries;
- running unit tests, benchmarks, custom meshes, CLI/GUI, help/list, or discovery commands;
- hiding runtime validation inside packaging or build scripts.

### Test + Benchmark

Use the exact immutable Code + Build artifact. Do not configure, compile, relink, regenerate discovery, or edit implementation/test/benchmark/fixture/validator/build logic.

### Review

Inspect source, PR, plans, logs, artifacts, and evidence. Do not modify production implementation or validation logic.

## Mandatory bounded-workflow properties

Every temporary/bounded workflow must:

1. initialize a persistent activity log before checkout or other fallible work;
2. record exact event/ref/source identity, tool versions, command output, and final repository status;
3. stream task output to both the Actions console and the persistent log;
4. upload the detailed log artifact under `if: always()` and `if-no-files-found: error`;
5. keep diagnostic logs separate from successful build/result artifacts;
6. use a narrow trigger path or explicit dispatch and a task-specific concurrency group;
7. use only required permissions and never expose secrets or authenticated URLs;
8. never modify its own `.github/workflows/**` file from inside the workflow;
9. verify expected source/blob/patch authority before applying changes or compiling;
10. preserve the turn boundary explicitly in packaged command metadata;
11. package exact source/fixture closure and recursive checksums for any artifact that will be executed later;
12. upload a result/build artifact only after successful completion of its declared task.

## Connector-first control plane

Use the GitHub connector to:

- resolve branch/PR/head authority;
- read and write source/plans/documentation;
- create and remove bounded workflows, payloads, and triggers;
- inspect workflow run/job/artifact metadata;
- download result and log artifacts;
- update PR metadata and post final handoff comments.

Actions should perform computation only where the connector cannot.

## Trigger discipline

When explicit workflow dispatch is unavailable, use one unique marker under `.agents/connector-triggers/` and make the workflow `push.paths` match only that exact marker. The workflow output commit must not modify the trigger marker, preventing loops.

Retain a turn payload only until:

- source commit is known;
- expected changed blobs are known;
- compile/build artifact and log artifact are verified;
- the payload digest and packaged source authority are confirmed.

Then remove the bounded workflow, trigger, and payload before turn closeout.

## Artifact verification

Before claiming Code + Build completion:

- verify workflow/job conclusion;
- verify exact compiled source commit;
- download build/result and detailed-log artifacts;
- verify outer artifact digests;
- verify recursive internal checksums;
- verify expected executables/libraries/fixtures/source metadata;
- verify packaged command-boundary metadata records that prohibited runtime execution did not occur.

Before Test + Benchmark execution, repeat artifact/source/checksum verification in a fresh extraction directory.

A successful Actions summary alone is never sufficient gate evidence.

## Repository hygiene

At the start and end of every turn:

- inspect `.github/workflows`;
- inspect `.agents/connector-triggers` and turn-payload directories;
- remove stale bounded workflows, markers, payloads, transfer files, and generated repository artifacts;
- retain only approved durable workflows and dependencies;
- never remove the latest executable next-turn plan or current evidence before replacements exist.

Git history and PR conversation are the historical archive; temporary execution mechanics do not remain in the active branch after their evidence is verified.

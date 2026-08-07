# GitHub Workflow Policy

## Purpose

Use GitHub Actions only as the bounded remote execution plane when the connected GitHub control plane cannot perform the required computation. The turn-based workflow remains authoritative: Actions never relax Code + Build, Test + Benchmark, or Review boundaries.

## Durable workflow state

The only approved durable workflow on `agent/surface_cell_quad/p5-recover-bridge-healing` is:

- `.github/workflows/agent-source-snapshot.yml`

Turn-specific build/test workflows, connector trigger markers, payload/patch transfer files, and generated repository artifacts are temporary. They must be removed after their result/log artifacts and exact source authority are verified.

At the G3 periodic output-validation Code + Build closeout on 2026-08-07, the branch was verified to contain only the durable workflow above; the bounded build workflow, trigger marker, and source payload were removed after artifact/log/source verification.

## Mandatory workflow requirements

Every workflow created or modified for agent work must:

1. initialize a persistent detailed activity log before checkout or any other fallible work;
2. capture event/ref/source identity, tool versions, commands/output, exit context, final repository status, and relevant resource information;
3. stream command output to both the Actions console and the persistent activity log;
4. use an `EXIT` trap or equivalent failure-safe logging where appropriate;
5. upload the dedicated diagnostic log artifact under `if: always()` with `if-no-files-found: error`;
6. keep the diagnostic log artifact separate from successful build/result artifacts;
7. avoid printing tokens, secrets, credentials, authenticated URLs, or secret-bearing arguments;
8. never modify `.github/workflows/**` from inside a workflow;
9. use narrow triggers and `concurrency` so unrelated commits cannot retrigger bounded work;
10. use least-privilege permissions;
11. preserve exact source authority and fail closed on unexpected input hashes.

## Code + Build execution boundary

Compile-only workflows may:

- checkout the exact bounded branch/source;
- apply a pre-verified source/test patch when required;
- install compile dependencies;
- initialize shallow submodules;
- configure with `PRE_TEST` or an equivalent compile-only-safe test-discovery mode;
- compile/link only explicitly approved targets;
- package binaries/libraries, fixtures, exact source closure, logs, metadata, and recursive checksums.

They may **not** execute any generated project binary, including tests, benchmarks, CLI/GUI programs, help/list commands, discovery commands, custom-mesh commands, or version/smoke execution.

Successful build artifacts must record `runtimeExecution=false` or equivalent command-boundary evidence.

## Test + Benchmark execution boundary

Artifact-only Test + Benchmark turns:

- download the exact declared successfully built artifact;
- verify outer digest, recursive checksums, source commit, changed blobs, source/dependency/fixture closure, and command-boundary metadata before runtime execution;
- extract into an arbitrary fresh directory;
- may create runtime-only symlinks solely to expose immutable packaged fixture paths expected by compiled binaries;
- execute validation only from packaged binaries and inputs;
- preserve raw logs, machine-readable results, determinism records, and evidence archives.

They may **not** configure, compile, relink, regenerate code/discovery, patch packaged source, modify fixtures/manifests, or edit implementation/test/benchmark/validator/build logic.

An invalid artifact is an infrastructure failure. Do not create a replacement build inside the Test + Benchmark turn.

## Trigger/payload lifecycle

When dispatch is unavailable and a temporary exact-path push trigger is required:

1. create one bounded workflow with an exact unique marker path;
2. create only the payload/patch files required by that workflow;
3. trigger it exactly once unless a diagnosed retry is required;
4. verify the source/result/log artifacts and exact output authority;
5. remove the bounded workflow, marker, and payload from the work branch;
6. verify the final workflow directory and temporary directories afterward.

Do not leave trigger-only debris or stale payloads in the long-lived PR branch.

## Artifact evidence requirements

A Code + Build artifact should contain, when applicable:

- exact source commit and changed blob IDs;
- source patch(es) and source archive;
- dependency/submodule authority;
- five required test/benchmark executables and project libraries for the surface-cell closure;
- production fixtures/input closure;
- configure/build/toolchain logs;
- compile database where useful;
- command-boundary metadata;
- recursive checksum manifest.

Record the GitHub workflow run/job IDs, artifact IDs/names/digests, log artifact IDs/digests, and retention metadata when available.

## Failure handling

- Diagnose failed workflows from the dedicated detailed log artifact, not only step summaries.
- Do not rerun a deterministic malformed workflow without fixing it first.
- Never synthesize success from a failed command.
- Never weaken tests/validators to obtain a green workflow.
- Never force-push merely to bypass a moving branch or stale content SHA.
- Compare exact blobs/hashes before deciding a patch is absent or already applied.

## End-of-turn hygiene

At both start and end of every turn:

- inspect `.github/workflows`;
- inspect temporary connector triggers and payload/patch directories;
- remove stale turn-specific workflow state;
- preserve the durable snapshot workflow;
- ensure retained documentation references only files that still exist;
- make the mandatory top-level PR #8 closeout comment the final repository write after all documentation and PR metadata updates.
# GitHub Workflow Policy

## Purpose

Use GitHub Actions only as the bounded remote execution plane when the connected GitHub control plane cannot perform the required computation. The turn-based workflow remains authoritative: Actions never relax Code + Build, Test + Benchmark, or Review boundaries.

Repository-side stale-evidence cleanup is governed by `CLEAN_UP_POLICY.md`. Durable record retention and destructive-mutation rules are governed by `RETENTION_POLICY.md`.

## Durable workflow state

The only approved durable workflow on `agent/surface_cell_quad/p5-recover-bridge-healing` is:

- `.github/workflows/agent-source-snapshot.yml`

Turn-specific build/test workflows, connector trigger markers, payload/patch transfer files, and generated repository artifacts are temporary. They must be removed after their result/log artifacts and exact source authority are verified.

At the G3 field-correspondence witness artifact-only Test + Benchmark closeout on 2026-08-08, final verification again showed only the durable workflow above; `.agents/connector-triggers` and `.agents/Directional/turn-payloads` were absent. No workflow or payload was created during that artifact-only validation turn.

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
11. preserve exact source authority and fail closed on unexpected input hashes;
12. use `${{ runner.temp }}` in workflow expressions and `$RUNNER_TEMP` in shell payloads consistently for temporary-root evidence paths so evidence generation and upload resolve to the same location;
13. avoid unindented shell heredocs inside YAML block scalars; use an indentation-safe script, committed helper payload, or equivalent construction that cannot invalidate workflow YAML before job execution.

## Code + Build execution boundary

Compile-only workflows may checkout exact bounded source, apply a pre-verified source/test patch, install compile dependencies, initialize shallow submodules, configure with `PRE_TEST` or equivalent compile-only-safe discovery, compile/link explicitly approved targets, and package binaries/libraries/fixtures/source/logs/metadata/checksums.

They may **not** execute any generated project binary, including tests, benchmarks, CLI/GUI programs, help/list commands, discovery commands, custom-mesh commands, or version/smoke execution. Successful build artifacts must record `runtimeExecution=false` or equivalent command-boundary evidence.

## Compile-cache policy

Compile-only GitHub Actions jobs should use GitHub Actions dependency caching when repeated rebuilds of nearby commits would otherwise recompile unchanged translation units. The cache is a performance aid only; exact source SHA, toolchain, configure options, and compile command remain authoritative, and a cache hit is never build evidence by itself. See GitHub's dependency-caching reference: https://docs.github.com/en/actions/reference/workflows-and-actions/dependency-caching#managing-caches.

For C/C++ work, prefer a compiler cache such as `ccache` over restoring an opaque whole build tree. A compiler cache safely reuses object results keyed by compiler/options/source content while allowing Ninja/CMake to rebuild changed units. Cache keys must include the runner OS, compiler/toolchain identity, build mode, and a deliberately versioned cache epoch. Restore keys may fall back only within that compatible toolchain/build-mode lineage.

When a compile fails after producing reusable objects, the workflow should preserve those compiler-cache entries before reporting the final compile failure, so the corrected re-trigger can reuse completed work without violating the Code + Build runtime boundary. The workflow must still fail closed on the original compile exit code after cache/evidence handling.

Keep compile caches lean. Do **not** create an unbounded per-commit cache lineage. Use one of these bounded strategies:

- reuse an existing compatible cache key/epoch whenever possible instead of minting a new cache for every source SHA; or
- if rolling keys are required to capture new partial-build entries, cap the compiler cache size aggressively and prune old runner-cache entries so only the smallest useful recent lineage is retained.

Repository cache storage must not become a second artifact archive. Cache generated object/compiler entries only; do not cache packaged build artifacts, immutable evidence archives, source snapshots, fixtures already in Git, or other durable records. Prefer a small bounded cache (for example a few hundred MiB for the active compile lineage) and rely on GitHub's cache eviction of entries not accessed for more than seven days as an additional backstop, not as the primary anti-bloat mechanism. If a workflow introduces rolling cache keys, it must document the retention/pruning mechanism in the workflow or turn record.

Cache restore/save operations must be logged, including cache key, hit/miss status when available, configured size cap, and whether pruning occurred. Cache contents must never contain secrets or credentials.

## Test + Benchmark execution boundary

Artifact-only Test + Benchmark turns download the exact declared build artifact, verify outer digest/recursive checksums/source/blobs/dependency/fixture closure/command-boundary metadata before runtime execution, extract into a fresh arbitrary directory, may create runtime-only symlinks only for immutable packaged fixture paths, and execute validation only from packaged binaries/inputs.

Artifact extraction must preserve the archive's natural executable attributes. If an extraction method does not preserve packaged executable mode bits, use an extraction method that does; never `chmod`, mutate, or otherwise repair the immutable package to make execution possible.

They may **not** configure, compile, relink, regenerate code/discovery, patch packaged source, modify fixtures/manifests, or edit implementation/test/benchmark/validator/build logic. An invalid artifact is an infrastructure failure; do not create a replacement build inside Test + Benchmark.

Long-running or resource-heavy tests and benchmarks are explicitly permitted on temporary, narrowly scoped GitHub Actions workflows when local or connector execution is impractical or would exceed interactive resource limits. They remain subject to the same Test + Benchmark artifact-only boundary, exact preflight/postflight authority, logging requirements, bounded time/resource controls, and temporary-workflow cleanup lifecycle; remote execution is an execution-plane choice, not permission to combine build and runtime validation.

A zero-selected test filter is an orchestration failure, never a semantic pass. Verify that focused test names belong to the intended packaged executable before treating a filtered run as evidence.

## Trigger/payload lifecycle

When dispatch is unavailable and a temporary exact-path push trigger is required:

1. create one bounded workflow with an exact unique marker path;
2. create only payload/patch files required by that workflow;
3. trigger exactly once unless a diagnosed retry is required;
4. verify source/result/log artifacts and exact output authority;
5. **remove or disable the bounded path-filtered workflow before deleting its trigger marker**, so marker cleanup cannot retrigger the same workflow;
6. remove marker/payload after the workflow is no longer triggerable;
7. verify final workflow and temporary directories afterward.

The workflow-first cleanup order is mandatory. During M1d cleanup, deleting the trigger marker first retriggered redundant run `31343858635`; that run is not acceptance authority and produced no product/regression state change.

Do not leave trigger-only debris or stale payloads in the long-lived PR branch.

## Artifact evidence requirements

A Code + Build artifact should contain, when applicable, exact source commit/blob IDs, source patches/archive, dependency/submodule authority, five required test/benchmark executables and project libraries, production fixture closure, configure/build/toolchain logs, compile database where useful, command-boundary metadata and recursive checksum manifest.

Record workflow run/job IDs, artifact IDs/names/digests, log artifact IDs/digests and retention metadata when available.

External immutable GitHub Actions artifacts remain governed by their retention settings and are not deleted merely because checked-in summaries become stale. Repository-side evidence cleanup is governed separately by `CLEAN_UP_POLICY.md` and `RETENTION_POLICY.md`.

## Failure handling

- Diagnose failed workflows from the dedicated detailed log artifact, not only step summaries.
- Do not rerun a deterministic malformed workflow without fixing it first.
- Never synthesize success from a failed command.
- Never weaken tests/validators to obtain a green workflow.
- Never force-push merely to bypass a moving branch or stale content SHA.
- Compare exact blobs/hashes before deciding a patch is absent or already applied.
- A compile-only failure may be corrected in the same Code + Build turn when the correction is bounded to the diagnosed compile/source issue and no generated project runtime is executed.
- A workflow whose semantic execution is green but whose evidence-upload step fails is an orchestration/evidence-retention failure, not semantic acceptance authority until the evidence path/lifecycle defect is corrected and authoritative evidence is retained.

## Cleanup and retention interlock

The detailed repository cleanup and retention policies no longer live in the handoff. Follow `CLEAN_UP_POLICY.md` and `RETENTION_POLICY.md` in addition to the workflow lifecycle above.

For workflow-related state specifically:

- inspect `.github/workflows`, temporary connector triggers, and payload/patch directories at both the start and end of every turn;
- remove stale turn-specific workflow state while preserving `.github/workflows/agent-source-snapshot.yml`;
- remove or disable a temporary path-filtered workflow before deleting its trigger marker or payload;
- verify final workflow and temporary directories after cleanup;
- preserve external immutable Actions artifacts according to retention settings even when repository-side summaries are retired.

## End-of-turn hygiene

At both start and end of every turn inspect `.github/workflows`, temporary connector triggers and payload/patch directories; remove stale turn-specific state; preserve the durable snapshot workflow; ensure retained documentation references only files that still exist (except explicitly historical commit-bound provenance); and make the mandatory top-level PR #8 closeout comment the final repository write after all documentation and PR metadata updates.

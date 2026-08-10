# GitHub Workflow Policy

## Purpose

Use GitHub Actions only as the bounded remote execution plane when the connected GitHub control plane cannot perform the required computation. The turn-based workflow remains authoritative: Actions never relax Code + Build, Test + Benchmark, or Review boundaries.

## Durable workflow state

The only approved durable workflow on `agent/surface_cell_quad/p5-recover-bridge-healing` is:

- `.github/workflows/agent-source-snapshot.yml`

Turn-specific build/test workflows, connector trigger markers, payload/patch transfer files, and generated repository artifacts are temporary. They must be removed after their result/log artifacts and exact source authority are verified.

## Mandatory workflow requirements

Every workflow created or modified for agent work must:

1. initialize a persistent detailed activity log before checkout or any other fallible work;
2. capture event/ref/source identity, tool versions, commands/output, exit context, final repository status, and relevant resource information;
3. stream command output to both the Actions console and persistent activity log;
4. use failure-safe logging where appropriate;
5. upload a dedicated diagnostic log artifact under `if: always()` with `if-no-files-found: error`;
6. keep diagnostic logs separate from successful result/build artifacts;
7. avoid printing tokens, secrets, credentials, authenticated URLs, or secret-bearing arguments;
8. never modify `.github/workflows/**` from inside a workflow;
9. use narrow triggers and `concurrency` so unrelated commits cannot retrigger bounded work;
10. use least-privilege permissions;
11. preserve exact source authority and fail closed on unexpected input hashes.

## Code + Build execution boundary

Compile-only workflows may checkout exact bounded source, apply a pre-verified source/test patch, install compile dependencies, initialize shallow submodules, configure with `PRE_TEST` or equivalent compile-only-safe discovery, compile/link explicitly approved targets, and package binaries/libraries/fixtures/source/logs/metadata/checksums.

They may **not** execute any generated project binary, including tests, benchmarks, CLI/GUI programs, help/list/version commands, discovery commands, custom-mesh commands, or fuzzers. Successful build artifacts must record `runtimeExecution=false` and explicit command-boundary evidence.

A compile error may be corrected within the same Code + Build turn if the correction remains inside the approved scope and no generated runtime has executed. The failure/correction must be retained in the turn report; compile failure alone is not a runtime regression event.

## Test + Benchmark execution boundary

Artifact-only Test + Benchmark turns download the exact declared build artifact, verify outer digest/recursive checksums/source/blobs/dependency/fixture closure/command-boundary metadata before runtime execution, extract into a fresh arbitrary directory, may create runtime-only symlinks only for immutable packaged fixture paths, and execute validation only from packaged binaries/inputs.

They may **not** configure, compile, relink, regenerate code/discovery, patch packaged source, modify fixtures/manifests, or edit implementation/test/benchmark/validator/build logic. An invalid artifact is an infrastructure failure; do not create a replacement build inside Test + Benchmark.

## Trigger/payload lifecycle — ordering is mandatory

When dispatch is unavailable and a temporary exact-path push trigger is required:

1. create one bounded workflow with an exact unique marker path;
2. create only payload/patch files required by that workflow;
3. trigger exactly once unless a diagnosed retry is required;
4. verify source/result/log artifacts and exact output authority;
5. **remove or disable every bounded path-filtered workflow before deleting its trigger marker**;
6. only after the workflow is no longer triggerable, remove marker/payload/helper files;
7. verify final workflow and temporary directories afterward.

Do not leave trigger-only debris or stale payloads in the long-lived PR branch.

The ordering in step 5 is mandatory because a previous M1d cleanup deleted the trigger while its workflow still existed and scheduled redundant non-authoritative run `31343858635`. M1e cleanup followed the corrected order: all temporary M1e workflows were removed first, then all trigger markers, then the temporary apply script.

## Artifact evidence requirements

A Code + Build artifact should contain, when applicable, exact source commit/blob IDs, source patches/archive, dependency/submodule authority, required test/benchmark executables and project libraries, production fixture closure, configure/build/toolchain logs, compile database where useful, command-boundary metadata and recursive checksum manifest.

Record workflow run/job IDs, artifact IDs/names/digests, log artifact IDs/digests and retention metadata when available.

## Failure handling

- Diagnose failed workflows from detailed logs, not only step summaries.
- Do not rerun deterministic malformed workflows without fixing them first.
- Workflow syntax events with no jobs are infrastructure failures, not product/runtime evidence.
- Never synthesize success from a failed command.
- Never weaken tests/validators to obtain a green workflow.
- Never force-push merely to bypass a moving branch or stale content SHA.
- Compare exact blobs/hashes before deciding a patch is absent or already applied.

## Durable `.agents/Directional` evidence cleanup interlock

The detailed cleanup policy lives in `Future_Chat_Session_Handoff.md` and must remain there.

- every Test + Benchmark turn begins by cleaning stale prior checked-in evidence after accepted facts, stable regression IDs, artifact identities, and unresolved blockers are folded into durable/live authority;
- every Test + Benchmark turn ends with the new authoritative Test + Benchmark report plus exactly one next Code + Build plan in addition to durable `.agents/Directional` documents;
- consumed TB plans, superseded preceding Code + Build plans/reports, old evidence indexes/machine summaries, and temporary workflow payloads are removed;
- external immutable Actions artifacts remain governed by retention settings and are not deleted merely because checked-in summaries become stale;
- retained durable/live documents are audited for references to deleted current-head files and corrected before closeout; explicitly historical commit-bound filenames may remain as provenance.

## End-of-turn hygiene

At both start and end of every turn inspect `.github/workflows`, temporary connector triggers and payload/helper directories; remove stale turn-specific state; preserve `agent-source-snapshot.yml`; ensure retained live documentation references current files; and make the mandatory top-level PR #8 closeout comment the final repository write after all documentation and PR metadata updates.

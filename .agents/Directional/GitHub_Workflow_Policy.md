# GitHub Workflow Policy

## Purpose

Use GitHub Actions only as the bounded remote execution plane when the connected GitHub control plane cannot perform the required computation. The turn-based workflow remains authoritative: Actions never relax Code + Build, Test + Benchmark, or Review boundaries.

## Durable workflow state

The only approved durable workflow on `agent/surface_cell_quad/p5-recover-bridge-healing` is `.github/workflows/agent-source-snapshot.yml`.

Turn-specific build/test workflows, connector trigger markers, payload/patch transfer files, and generated repository artifacts are temporary. They must be removed after their result/log artifacts and exact source authority are verified.

## Mandatory workflow requirements

Every workflow created or modified for agent work must initialize a persistent activity log before fallible work, capture source/event/tool/command/exit/resource evidence, stream command output to the console and log, upload diagnostic logs under `if: always()`, keep logs separate from successful result artifacts, never print secrets, never modify workflow files from inside a workflow, use narrow triggers/concurrency/least privilege, and fail closed on unexpected source hashes.

## Code + Build execution boundary

Compile-only workflows may checkout exact bounded source, apply a pre-verified bounded patch, install compile dependencies, initialize shallow submodules, configure with `PRE_TEST`, compile/link explicitly approved targets, and package binaries/libraries/fixtures/source/logs/metadata/checksums.

They may **not** execute any generated project binary, including tests, benchmarks, CLI/GUI/help/list/version commands, discovery commands, custom inputs, or fuzzers. Successful build artifacts record `runtimeExecution=false` and explicit command-boundary evidence.

A compile error may be corrected within the same Code + Build turn when the correction remains inside approved scope and no generated runtime executed. The turn report records the failed compile and correction; compile failure alone is not a runtime regression event.

## Test + Benchmark execution boundary

Artifact-only Test + Benchmark turns download the exact declared build artifact, verify outer digest/recursive checksums/source/blobs/dependency/fixture closure/command-boundary metadata before runtime, extract into a fresh arbitrary directory, may create runtime-only symlinks only for immutable packaged fixture paths, and execute only packaged binaries/inputs.

They may **not** configure, compile, relink, regenerate, patch source/tests, modify fixtures/manifests, or repair the artifact. An invalid artifact is infrastructure failure; never create a replacement build inside Test + Benchmark.

## Trigger/payload lifecycle — ordering is mandatory

When a temporary path-filtered push trigger is required:

1. create one bounded workflow with an exact unique marker path;
2. create only required payload/patch/helper files;
3. trigger exactly once unless a diagnosed retry is required;
4. verify source/result/log artifacts and exact output authority;
5. **remove or disable every bounded path-filtered workflow before deleting its trigger marker**;
6. only after the workflow is no longer triggerable, remove marker/payload/helper files;
7. verify final workflow and temporary directories afterward.

A previous M1d cleanup reversed step 5 and scheduled redundant non-authoritative run `31343858635`. M1e cleanup followed the corrected order: all temporary M1e workflows were removed first, then trigger markers, then the temporary apply script.

## Artifact evidence requirements

A Code + Build artifact should contain exact source commit/blob IDs, source patch/archive, dependency/submodule authority, required executables/libraries, fixture closure, configure/build/toolchain logs, compile database where useful, command-boundary metadata and recursive checksums. Record workflow run/job IDs, artifact IDs/names/digests and retention metadata.

## Failure handling

- Diagnose failed workflows from detailed logs, not only step summaries.
- Do not rerun deterministic malformed workflows without correction.
- Workflow syntax events with no jobs are infrastructure failures, not product/runtime evidence.
- Never synthesize success from a failed command.
- Never weaken tests/validators to obtain green.
- Never force-push merely to bypass moving branch/stale content SHA.
- Compare exact blobs/hashes before deciding a patch is absent or already applied.

## Durable `.agents/Directional` evidence cleanup interlock

The detailed cleanup policy lives in `Future_Chat_Session_Handoff.md` and must remain there.

- every Test + Benchmark turn begins by cleaning stale prior checked-in evidence after accepted facts, stable regression IDs, artifact identities, and unresolved blockers are folded into durable/live authority;
- every Test + Benchmark turn ends with the new authoritative TB report plus exactly one next Code + Build plan alongside durable `.agents/Directional` documents;
- consumed TB plans, superseded preceding Code + Build plans/reports, old evidence indexes/machine summaries, and temporary workflow payloads are removed;
- external immutable Actions artifacts remain governed by retention settings;
- retained durable/live documents are audited for references to deleted current-head files before closeout.

## End-of-turn hygiene

At start and end of every turn inspect `.github/workflows`, temporary connector triggers and payload/helper directories; remove stale turn-specific state; preserve `agent-source-snapshot.yml`; ensure retained live documentation references current files; and make the mandatory top-level PR #8 closeout comment the final repository write after all documentation and PR metadata updates.

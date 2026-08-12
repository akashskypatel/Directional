# GitHub Workflow Policy

## Purpose

GitHub is the control plane; GitHub Actions is the bounded remote execution plane for computation the connector cannot perform. The turn-based cadence remains authoritative. Actions never relax Code + Build, Test + Benchmark, or Review boundaries.

Retention and destructive-mutation rules: `RETENTION_POLICY.md`. Repository cleanup: `CLEAN_UP_POLICY.md`.

## Durable workflows

Retain these durable workflows on the working branch:

- `.github/workflows/agent-source-snapshot.yml` — historical/source-snapshot utility only; not an approved current compile/test entry point.
- `.github/workflows/agent-compile-reusable.yml` — **mandatory reusable compile implementation for every build/compile task**.

Any workflow that compiles Directional must call `agent-compile-reusable.yml`. Do not duplicate its checkout, configure, compile, ccache, cache-pruning, packaging, or compile-evidence logic in a turn-specific workflow. A temporary caller may only provide the exact source SHA, approved targets, artifact prefix, cache epoch, and narrowly scoped trigger.

Turn-specific callers, trigger markers, patch/payload files, and generated repository artifacts are temporary and must be removed after their result/log artifacts and exact source authority are verified.

## Mandatory workflow contract

Every agent workflow must:

1. initialize a persistent activity log before checkout or other fallible work;
2. record event/ref/source identity, tool versions, commands/output, exit context, final source status, and relevant resource/cache state;
3. stream task output to both console and the persistent log;
4. upload the dedicated diagnostic log under `if: always()` and `if-no-files-found: error`;
5. keep diagnostic logs separate from successful result artifacts;
6. use narrow triggers, `concurrency` where applicable, least privilege, and exact source/hash checks;
7. keep logs/evidence under `${{ runner.temp }}` / `$RUNNER_TEMP`, not the source tree;
8. never print secrets, credentials, authenticated URLs, or secret-bearing arguments;
9. never modify `.github/workflows/**` from inside a workflow;
10. use indentation-safe YAML/shell construction.

## Code + Build boundary

Code + Build workflows may checkout exact pushed source, apply a pre-verified source/test patch, initialize shallow submodules, configure with `PRE_TEST` or an equivalent compile-only discovery mode, compile/link approved targets, and package compile evidence.

They must not execute generated Directional binaries: no tests, benchmarks, discovery/list/help/version commands, CLI/GUI, `ctest`, fuzzers, or custom inputs. Every build package records `runtimeExecution=false`.

All compile/build execution must use `.github/workflows/agent-compile-reusable.yml`.

## Compile-cache policy

The reusable compile workflow owns compiler caching. Required rules:

- Use `ccache`; do not cache an opaque CMake/Ninja build tree.
- Key compatibility by runner OS, compiler/toolchain version, build mode, and an explicit cache epoch. Source SHA is not part of the compatibility prefix.
- Use rolling save keys only to persist newly produced compiler entries; restore from the compatible prefix.
- Cap ccache at **256 MiB** unless this policy is explicitly amended.
- Retain at most **two** compatible caches for the active lineage and delete older compatible entries.
- Delete legacy `m1-ra-*` rolling caches when the reusable workflow successfully establishes the current lineage.
- Save reusable compiler entries even after a compile failure, then propagate the original compile exit status.
- Cache object/compiler entries only. Never cache build/result artifacts, source archives, fixtures already in Git, immutable evidence, or packaged binaries.
- Log requested key, matched key/hit status, ccache statistics, configured size cap, and every prune/delete action.

A cache hit is only a performance optimization. Exact source SHA, toolchain, configure options, compile command, linked outputs, and clean source status remain build authority.

## Test + Benchmark boundary

Artifact-only Test + Benchmark turns must verify the declared immutable package before execution, extract it without repairing permissions/content, and execute only packaged binaries/inputs.

They must not configure, compile, relink, regenerate discovery/code, patch packaged source, or alter fixtures/manifests. A zero-selected filter is orchestration failure, never a pass.

## Trigger and payload lifecycle

When connector dispatch is unavailable:

1. use a temporary caller with one exact unique push-marker path;
2. make the caller invoke the durable reusable compile workflow for compile work;
3. create only required patch/payload files;
4. trigger once unless a diagnosed retry is required;
5. verify exact source, result/log artifacts, and outputs;
6. remove/disable the temporary caller before deleting its marker/payload;
7. verify final workflow, trigger, and payload directories.

Never leave turn-specific workflow/trigger debris on the long-lived branch.

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

At start and end of every turn inspect `.github/workflows`, `.agents/connector-triggers`, and `.agents/Directional/turn-payloads`. Preserve durable workflows, remove stale temporary state in workflow-first order, apply `CLEAN_UP_POLICY.md`, and make the final PR #8 summary comment the final repository write.

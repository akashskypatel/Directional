# GitHub Workflow Policy

## Purpose

Use GitHub Actions only when it materially helps an authorized turn and keep workflow state bounded, auditable, and removable.

## Current operational status

GitHub workflow operations are available normally again. Future **authorized Code + Build** turns may use GitHub Actions to configure/compile approved targets and publish immutable build artifacts. Test + Benchmark turns remain artifact-only and must not rebuild. Review turns do not compile unless a later explicitly authorized review plan requires evidence that cannot be obtained otherwise.

## Durable workflow policy

1. Keep only approved durable workflows on the working branch. The current durable workflow is `.github/workflows/agent-source-snapshot.yml`.
2. At the start and end of every turn, inspect `.github/workflows`, temporary triggers, payload/patch directories, and generated artifacts.
3. A Code + Build turn may add at most one bounded build/synchronization workflow at a time when needed.
4. Bounded workflows must use exact source authority, explicit approved targets, bounded timeouts, and artifact checksums.
5. Compile-only workflows may configure and compile/link approved targets but must not execute generated project binaries/tests/benchmarks/discovery/CLI/GUI/help/list commands.
6. Test + Benchmark turns must execute only the exact immutable build artifact selected by the plan and may not configure, compile, or relink.
7. Retain exact transfer payloads until their source commit, expected blobs, and build artifact authority are verified; then remove them.
8. After a bounded workflow completes and its artifact/logs are verified, remove the workflow, trigger marker, payload, and other turn-specific transfer files.
9. Final branch state must contain only approved durable workflows and no stale generated artifacts or payloads.
10. Do not remove a durable dependency consumed by an approved retained workflow.

## Build workflow requirements

An authorized build workflow must record or make recoverable:

- exact branch/base/source commit;
- configuration and generator;
- compiler/toolchain identity;
- approved build targets;
- compile/link result;
- no-runtime-execution policy;
- packaged executable/library/fixture closure;
- recursive artifact checksums and outer artifact digest;
- workflow run/job/artifact identifiers.

Use shallow checkout/submodule fetch where practical. Do not download unrelated Git history.

## Source synchronization

Prefer ordinary GitHub connector file/tree/commit operations when they can safely express the exact change. A temporary synchronization workflow is allowed for large immutable patches or other connector limitations, but it must:

- verify payload digests before application;
- verify exact expected changed paths and Git blobs;
- create a coherent source commit;
- remove the payload afterward;
- publish a small evidence artifact/log;
- perform no unrelated build or runtime execution unless the active Code + Build plan explicitly combines those operations.

## Cleanup and final-write rule

Repository cleanup and PR metadata updates occur before the final handoff comment. Every completed turn ends with a new top-level PR #8 comment as the **final repository write**.

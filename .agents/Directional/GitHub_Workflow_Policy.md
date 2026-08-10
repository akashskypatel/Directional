# GitHub Workflow Policy

Use GitHub Actions only as bounded remote execution. The turn-based workflow remains authoritative.

## Durable state

The only approved durable workflow is `.github/workflows/agent-source-snapshot.yml`. Turn-specific workflows, trigger markers, payloads and helpers are temporary and are removed after artifact/source authority is verified.

## Mandatory workflow controls

Every agent workflow must initialize persistent logs before fallible work, capture source/event/tool/command/exit/resource evidence, stream logs to console + artifact, upload diagnostic logs under `if: always()`, keep logs separate from result artifacts, avoid secrets, never self-modify workflow files, use narrow triggers/concurrency/least privilege, and fail closed on unexpected source hashes.

## Code + Build boundary

May checkout/apply bounded edits/install compile dependencies/shallow submodules/configure PRE_TEST/compile approved targets/package immutable evidence. May **not** execute generated Directional binaries: no discovery/tests/benchmarks/ctest/CLI/GUI/help/list/version/fuzzer/custom input. Record `runtimeExecution=false`.

Bounded compile errors may be corrected in the same Code + Build turn if scope stays approved and no generated runtime has executed. Compile failure alone is not a runtime regression event.

## Test + Benchmark boundary

Consume exact declared build artifact. Verify outer digest, recursive checksums, source blobs, dependencies, fixtures, command-boundary metadata and executable hashes before runtime. Do not configure/compile/relink/regenerate/patch/repair package content. Invalid artifacts are infrastructure failures.

## Trigger/payload lifecycle — mandatory order

1. Create one bounded workflow with exact unique marker path.
2. Create only required payload/helper files.
3. Trigger only as needed for diagnosed attempts.
4. Verify source/result/log authority.
5. **Remove/disable every path-filtered temporary workflow before deleting its trigger marker.**
6. Then remove markers/payload/helpers.
7. Verify final workflow/temp directories.

M1d once reversed step 5 and created redundant non-authoritative run `31343858635`. M1e cleanup followed the corrected order: workflows first, then triggers, then apply script.

## Artifact evidence

Code + Build artifacts should contain exact source commit/blobs, source patch/archive, dependency/submodule authority, executables/libraries, fixtures, configure/build/toolchain logs, compile database where useful, command-boundary metadata and recursive checksums. Record run/job IDs, artifact IDs/digests and retention.

## Failure handling

Workflow syntax/no-job failures are infrastructure-only. Do not synthesize success, weaken tests/validators, force-push around source authority, or rerun deterministic malformed workflows without diagnosis/correction.

## Durable evidence cleanup interlock

Detailed policy lives in `Future_Chat_Session_Handoff.md`. Every TB turn starts by cleaning stale checked-in evidence after necessary facts are captured durably and ends with the new TB report + exactly one next Code + Build plan alongside durable documents. External Actions artifacts follow retention policy. Audit retained live references after cleanup.

## End-of-turn hygiene

Inspect workflows/triggers/helpers at start/end, remove stale turn-specific state, preserve `agent-source-snapshot.yml`, and make one new top-level PR #8 comment the final repository write after all branch-file and PR metadata writes.

# GitHub Workflow Policy

All repository-local GitHub Actions workflows created or modified by coding agents must satisfy the following requirements.

1. Record detailed activity and command output for both successful and failed runs.
2. Initialize the persistent log before checkout or other fallible work so an early failure still leaves diagnostic evidence.
3. Capture command traces, tool versions, exact source/ref metadata, configure/build output, failure exit codes, final source status, and relevant resource usage.
4. Upload the detailed log with `actions/upload-artifact` under `if: always()` and `if-no-files-found: error`.
5. Keep the log artifact separate from any successful build/package artifact so failed runs remain diagnosable.
6. Use the uploaded log artifact as the primary debugging source for failed workflows; do not diagnose solely from abbreviated step summaries.
7. Preserve the turn boundary: compile-only workflows must not execute tests, benchmarks, custom meshes, help/list commands, discovery commands, or compiled project binaries.
8. Never expose tokens, secrets, credentials, or secret-bearing command arguments in traced output.
9. Never modify `.github/workflows/**` from inside a workflow.
10. When connector dispatch is unavailable, use one exact unique marker path; the workflow result must not modify that marker or its own workflow file.
11. During a declared GitHub Actions outage, do not create, trigger, retry, or rely on workflows for repository updates or builds. Use direct connector Git objects or an authenticated local client for source writes and local execution for builds.
12. Keep every unsynchronized source change as an ordered, immutable, versioned patch layer on the project TODO. Record each layer's base authority, digest, expected output blobs, build artifact, and logs.
13. After recovery, apply patch layers as separate coherent source commits in order and verify expected blobs after every layer. Remove a payload only after its corresponding commit is verified.
14. A local build or artifact establishes compile/runtime evidence only when exact source, ordered patch stack, dependency, fixture, log, and checksum authority is recorded. It does not replace a verified remote source commit.

This policy is mandatory for all future GitHub workflow work in this repository.

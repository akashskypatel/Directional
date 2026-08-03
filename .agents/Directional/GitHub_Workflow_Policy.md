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

This policy is mandatory for all future GitHub workflow work in this repository.

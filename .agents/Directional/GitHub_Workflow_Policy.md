# GitHub Workflow Policy

## Required behavior

GitHub workflows used by agents must log all activity and detailed output regardless of success or failure.

Every workflow must:

1. Initialize a persistent activity log before checkout or any other fallible step.
2. Capture exact source/ref metadata, commands, tool versions, command output, exit codes, final repository status, and relevant resource information.
3. Upload a dedicated diagnostic log artifact under `if: always()` with `if-no-files-found: error`.
4. Keep diagnostic logs separate from successful build, test, benchmark, or result artifacts.
5. Avoid exposing tokens, credentials, authenticated URLs, secrets, or secret-bearing arguments.
6. Keep Code + Build, Test + Benchmark, and optional Review boundaries intact.
7. Remove bounded turn-specific workflows, triggers, and transfer payloads after their artifact and logs are verified.
8. Retain only approved durable workflow files in the final branch state.

A successful workflow summary is not sufficient evidence. The detailed log artifact and output artifact must be inspected and their exact source authority verified.

# Dedicated orphan-branch workflow mailbox migration — 2026-10-14

**Source:** User-provided `github-connector-workflows.zip`, particularly
`references/WORKFLOW_MAILBOX.md` and `templates/workflow-mailbox-publisher.yml`.
This is workflow/control-plane maintenance within canonical
`M6-CP3-CB1-ENTRY-R4`, not an R4 implementation acceptance or successor.

## Required source isolation

The durable `.github/workflows/workflow-mailbox-publisher.yml` mirrors the
user-supplied isolated mailbox publisher: it writes only to `workflow-mailbox`;
if absent it creates the ref from an orphan root; if preexisting it removes
unrelated tracked paths on the mailbox ref only, in an ordinary nonforced
commit. No mailbox publisher may default to the invoking source branch.
Source refs are preserved solely in record `source_sha/source_ref`.

The `workflow-mailbox` tree is limited to global `latest.json`, per-key
`.workflow-mailbox/<key>/latest.json` and immutable run-attempt records
`.workflow-mailbox/<key>/runs/<run-id>-attempt-<attempt>.json`. Global and
per-key `latest.json` use numerical `(run_id,run_attempt)` ordering, not finish
order. Concurrent writers fetch/reconstruct/retry without force-pushing.
The publisher rejects any nonempty `mailbox_branch` override other than
`workflow-mailbox`. All three caller workflows pass the branch explicitly;
their permission ceilings are unmodified.

The user's previous working-branch `.workflow-mailbox/**` contents have
already been intentionally removed. Do not restore them on the working
branch, and do not use source-branch HEAD as a mailbox ref. Every connector
read must pin `ref=workflow-mailbox`; the optional global `latest.json` is
read from this same isolated branch. Mailbox HEAD is never code authority.
Retain GitHub run IDs and immutable artifact digests in durable records.

## Workflow and policy inventory

Active callers: `agent-operation-dispatcher.yml`,
`agent-source-snapshot.yml`, `agent-turn-cleanup.yml`; durable publisher:
`workflow-mailbox-publisher.yml`. The fallback run observer's comment is
clarified; other existing workflows do not directly publish a mailbox and
their build/test/execution/permission contracts remain untouched.

Updated durable authority: `GitHub_Workflow_Policy.md`,
`TOOL_USE_CONSERVATION_POLICY.md`, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`,
`GMP_COMPILE_POLICY.md`, `AGENT_POLICY.md`, `Durable_Handoff_Policy.md`,
`Mandatory_Start_Checklist.md`, `Mandatory_End_Checklist.md`.

## Verification and rollback boundaries

1. Parse every touched workflow YAML and compare all job/reusable permissions
   before and after (no permission changes).
2. Validate exact publisher parity with the attached template.
3. Trigger one authorised read-only source-snapshot run and confirm mailbox
   creation/publication at `workflow-mailbox` (not source ref), global/per-key
   pointers, isolated branch paths, exact event/source SHA, and artifact receipt.
4. Confirm source branch still has no `.workflow-mailbox/**` and no
   `.github/workflows/**` self-mutating workflow. Keep fallback run discovery
   when mailbox cannot publish. Do not claim runtime tests were executed.
5. Remove only temporary snapshot trigger; preserve mailbox run-attempt
   history on its orphan ref and immutable artifact evidence.

No R4 semantic source, frozen selector, acceptance totals, or Test +
Benchmark execution is changed by this migration.

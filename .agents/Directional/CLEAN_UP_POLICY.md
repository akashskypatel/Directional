# Cleanup Policy

## Purpose

Define the repository-side cleanup lifecycle for agent work without deleting or weakening durable project memory. This policy is maintained separately from `Future_Chat_Session_Handoff.md`.

Retention and destructive-mutation rules are defined in `RETENTION_POLICY.md`. GitHub Actions workflow, trigger, payload, and remote-artifact lifecycle rules are defined in `GitHub_Workflow_Policy.md`.

## Stale-evidence cleanup

Every Test + Benchmark turn must begin with stale-evidence cleanup:

- Remove prior Test + Benchmark evidence and other superseded turn documents only after verifying their accepted facts, stable regression IDs, artifact identities, unresolved blockers, and other durable information are already represented in the durable trackers, changelog, current authority, or other retained durable records.
- Do not treat raw machine-readable evidence as stale while it is still the sole authority for a claim. Fold the necessary facts into retained durable/current authority before removing a repository-side summary or evidence file.
- Cleanup never authorizes changes prohibited by `RETENTION_POLICY.md`.

Every Test + Benchmark turn must end by replacing stale evidence with current evidence:

- Retain the newly authoritative Test + Benchmark report plus exactly one next Code + Build plan in addition to the durable project documents defined by `RETENTION_POLICY.md`.
- Remove the consumed Test + Benchmark plan, the superseded preceding Code + Build report/plan, older superseded per-turn evidence, evidence indexes, machine summaries, and other records expressly classified as temporary after their durable facts have been preserved.
- Never delete the current immutable source/package authority until its necessary facts are captured in the new authoritative report and the retained durable records appropriate to that information.

## Cleanup verification

After cleanup:

- Audit retained documents for references to deleted stale current-head files and repair those references before turn closeout.
- Historical filenames tied to cited commits may remain as provenance when explicitly identified as historical.
- Verify that cleanup did not remove or weaken any durable document, policy, acceptance criterion, stable ID, artifact identity, unresolved blocker, failed-attempt lesson, or resume-critical state protected by `RETENTION_POLICY.md`.

## Scope boundary

Repository cleanup concerns checked-in stale documents, summaries, evidence, and temporary agent state. GitHub Actions workflows, connector trigger markers, payload/patch transfer files, generated repository artifacts, workflow cleanup ordering, and external Actions artifact retention are governed by `GitHub_Workflow_Policy.md`.

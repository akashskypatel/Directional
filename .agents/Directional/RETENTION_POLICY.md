# Retention Policy

## Purpose

Define which project records are durable, which turn records may be retired, and the authorization required before durable information may be removed, weakened, consolidated, or replaced. This policy is maintained separately from `Future_Chat_Session_Handoff.md`.

Repository cleanup mechanics are defined in `CLEAN_UP_POLICY.md`. GitHub Actions workflow and remote-artifact lifecycle rules are defined in `GitHub_Workflow_Policy.md`.

## Durable project authority

The following records are durable project authority and must be retained unless the user explicitly authorizes their removal or replacement:

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`
- `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `.agents/Directional/CLEAN_UP_POLICY.md`
- `.agents/Directional/RETENTION_POLICY.md`
- `.agents/Directional/Regression_Root_Cause_Tracker.md`
- `.agents/Directional/PR_8_Regression_Audit_Inventory.md`
- `.agents/Directional/CHANGELOG.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `TODO`
- `MILESTONE_G_TODO.md`
- `tests/TESTING_STRATEGY.md`

In addition to the durable set, retain only the current authoritative evidence/report and the single next-turn plan needed to resume work. Superseded per-turn Code + Build plans/reports, Test + Benchmark plans/reports, review plans/reports, evidence indexes, machine summaries, and temporary workflow payloads may be removed only after their necessary durable facts have been preserved according to this policy and `CLEAN_UP_POLICY.md`.

## Handoff and changelog ownership

`.agents/Directional/CHANGELOG.md` is the durable historical record for completed changes and immutable acceptance checkpoints. Maintain it separately from the handoff.

- `Future_Chat_Session_Handoff.md` contains only the mandatory next action, current immutable authority, live blockers, resume-critical lessons, and references needed by a new agent to continue correctly.
- Do not accumulate completed milestone narratives, old artifact tables, superseded turn summaries, historical acceptance logs, or durable policy bodies in the handoff.
- When a completed turn creates a durable implementation or acceptance change, add or update the corresponding newest-first entry in `CHANGELOG.md` using its documented style before removing historical detail from the handoff.
- Preserve exact implementation commits, artifact/run identities, stable regression IDs, failure classifications, and material operational lessons in the changelog when they cease to be resume-critical.
- Keep unresolved or immediately actionable information in the handoff until it is no longer needed to resume the next turn correctly.
- A changelog entry supplements authoritative per-turn reports; it does not replace the exact evidence report while that report is the current immutable authority.

## Evidence retention

- Raw machine-readable evidence that is still the sole authority for a claim is not stale and must be retained until its necessary facts have been folded into an appropriate durable/current record.
- Never remove the current immutable source/package authority until its necessary facts are captured in the succeeding authoritative report and durable/live records.
- External GitHub Actions artifact retention is governed by `GitHub_Workflow_Policy.md`; repository-side cleanup does not imply deletion of immutable external artifact history.

## Durable-information mutation prohibition — user authorization required

This policy is durable and must remain in force unless the user explicitly changes it.

- Destructive edits to durable information are prohibited unless they are within the approved documentation scope of a Review turn explicitly authorized by the user, or the user explicitly authorizes the destructive edit and its scope. No other turn type—and no general instruction to update, clean, condense, reconcile, keep concise/current, remove stale evidence, or reduce file count—grants that authority.
- A destructive edit includes deleting a durable document; removing findings, rationale, decisions, invariants, design or architecture detail, policies, acceptance criteria, historical evidence or provenance, stable IDs, artifact identities, failed-attempt lessons, unresolved blockers, or resume guidance; replacing detailed authority with a summary; weakening or obscuring prior meaning; or moving information without a durable, traceable replacement.
- Protected information includes design, architecture, policy, remediation and roadmaps, plans, audit/review findings, regression/root-cause history, testing strategy, workflow/process rules, TODO/handoff recovery state, and any other record whose purpose is durable project memory.
- Routine stale per-turn evidence cleanup applies only to records expressly classified as temporary after all necessary facts have been preserved. It never authorizes destructive edits to protected durable information.
- Never remove, weaken, consolidate, reinterpret, or replace a durable document or mandatory instruction merely to reduce file count.
- Without the required authorization, edits must be additive or narrowly corrective and must preserve all prior durable meaning. If classification or authority is uncertain, stop and ask the user before editing.
- Before an authorized destructive edit, inventory the information at risk, define the exact authorized scope, and verify the resulting diff against that scope.

## Policy maintenance

Policy content belongs in the dedicated policy documents rather than being duplicated into `Future_Chat_Session_Handoff.md`. The handoff should reference these policies and carry only resume-critical state. Moving policy text between these dedicated durable documents is permitted only when the destination preserves the full durable meaning and provenance of the moved rule.

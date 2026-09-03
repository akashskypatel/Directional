# Cleanup Policy

## Purpose

Define the repository-side cleanup lifecycle for agent work without deleting or weakening durable project memory. This policy is maintained separately from `Future_Chat_Session_Handoff.md`.

`[ChatGPT Web]` First, review tool use conservation policy for temporary file cleanup in [`TOOL_USE_CONSERVATION_POLICY.md](TOOL_USE_CONSERVATION_POLICY.md#9-temporary-file-inventory-and-batched-cleanup).

Retention and destructive-mutation rules are defined in `RETENTION_POLICY.md`. 

`[ChatGPT Web]` GitHub Actions workflow, trigger, Google Drive patch transport, and remote-artifact lifecycle rules are defined in `GitHub_Workflow_Policy.md`.

## `[ChatGPT Web]` Temporary File Ledger

Each turn must maintain a record of every temporary files created during the turn or files to be deleted at the end of the turn in `.agents/connector-triggers/turn-cleanup/manifest.txt`. \

Each turn must end with executing `.github/workflows/agent-turn-cleanup.yml` to clean up temporary files using the temporary file ledger.

## Stale-evidence cleanup

Every Test + Benchmark turn must begin with stale-evidence cleanup:

- Remove prior Test + Benchmark evidence and other superseded turn documents only after verifying their accepted facts, stable regression IDs, artifact identities, unresolved blockers, and other durable information are already represented in the durable trackers, changelog, current authority, or other retained durable records.
- Do not treat raw machine-readable evidence as stale while it is still the sole authority for a claim. Fold the necessary facts into retained durable/current authority before removing a repository-side summary or evidence file.
- Cleanup never authorizes changes prohibited by `RETENTION_POLICY.md`.

Every Test + Benchmark turn must end by replacing stale evidence with current evidence:

- Retain the newly authoritative Test + Benchmark report plus exactly one next Code + Build plan in addition to the durable project documents defined by `RETENTION_POLICY.md`.
- Remove the consumed Test + Benchmark plan, the superseded preceding Code + Build report/plan, older superseded per-turn evidence, evidence indexes, machine summaries, and other records expressly classified as temporary after their durable facts have been preserved.
- Never delete the current immutable source/package authority until its necessary facts are captured in the new authoritative report and the retained durable records appropriate to that information.

## Document consolidation — every REVIEW turn — DURABLE, DO NOT DELETE

**Authorized by the user on 2026-09-03 and binding for all future REVIEW turns.** First applied at
`M3-CP4c-3-TB18-REV`.

Every REVIEW turn must perform document consolidation before closeout, in addition to updating `ORIENTATION.md`.
Consolidation is a *retention* action, not a reduction target: its purpose is that a cold-start agent finds one
current document per role instead of an accumulating per-turn series.

### Mandatory procedure

1. **Preserve first, fold second.** Before any document is folded, verify that its durable facts already live in a
   retained record: findings and adjudications in the current review record, root causes/candidates/stable IDs in
   `Regression_Root_Cause_Tracker.md`, substance in `ORIENTATION.md`, generalizable rules in `LESSONS.md`, and
   exact source/run/artifact/selector identities in the owning report and `CHANGELOG.md`. If a fact has no
   retained home, create the home before folding.
2. **Fold, do not delete silently.** Every folded document's exact filename is appended to the **folded document
   index** of its family's consolidated record (`M3_CP4c_Consolidated_Record.md` for the CP4c family; the
   corresponding closure record for a closed checkpoint) together with the verdict or role it carried. The full
   text remains recoverable from git history; the index is what makes it findable.
3. **Index what other turns retired.** A Code + Build or Test + Benchmark turn's stale-evidence cleanup removes
   superseded per-turn documents without writing the folded document index. The next REVIEW turn must add an index
   entry for each such document — recovering its name and line count from git history — so a filename retired
   between reviews still resolves. First applied at `M3-CP4c-3-TB20-REV`.
4. **Retain one current document per role.** After consolidation the family retains: the current runtime-authority
   report, the current review record, exactly one next-turn plan, the consolidated historical record, the
   consolidated normative definitions, and every byte-frozen selector file. Nothing else from the per-turn series.
5. **Never fold current authority.** The current immutable source/package/runtime authority and the single frozen
   next-turn plan are retained until superseded by their successors.
6. **Repair references in the same turn.** After folding, rewrite live citations of the folded filenames to the
   consolidated record (and its part/section where one exists). Historical citations tied to a cited commit may
   remain as provenance when the retained record carries a resolver note naming the index that resolves them.
7. **Verify the diff against the authorized scope.** Inventory what is at risk before the edit and confirm
   afterwards that no durable document, explicitly durable section, policy, acceptance criterion, normative
   definition, selector file, stable ID, artifact identity, unresolved blocker, failed-attempt lesson or
   resume-critical state was removed or weakened.

### Authorization boundary

This section is the standing user authorization required by `RETENTION_POLICY.md` for consolidation performed
**within a REVIEW turn and within the scope defined above**. It authorizes nothing else:

- it does **not** authorize consolidating durable project authority, normative definitions, policies, closure
  records or selector files — those move only under a separate, explicit user instruction naming them;
- it does **not** authorize replacing detailed authority with a summary. Folding relocates findability; it never
  substitutes a précis for a record whose detail is still load-bearing;
- it does **not** extend to any other turn type. A CB or TB turn performs stale-evidence cleanup only.

If classification or authority is uncertain, stop and ask the user before editing.

## Cleanup verification

After cleanup:

- Audit retained documents for references to deleted stale current-head files and repair those references before turn closeout.
- Historical filenames tied to cited commits may remain as provenance when explicitly identified as historical.
- Verify that cleanup did not remove or weaken any durable document, policy, acceptance criterion, stable ID, artifact identity, unresolved blocker, failed-attempt lesson, or resume-critical state protected by `RETENTION_POLICY.md`.

## `[ChatGPT Web]` Google Drive patch cleanup

- Patch bytes are not staged in the repository. The standard non-minor transport is the raw verified patch in `My Drive/Directional-CI`, addressed by Google Drive File ID.
- `.github/workflows/agent-google-drive-reusable.yml` must never issue a permanent Drive `DELETE`. Only after the patch commit pushes successfully, it may move the staged file to trash when its workflow identity has `capabilities.canTrash`; otherwise it reports `drive_file_retirement_required=true` without issuing a known-failing mutation.
- After the successful patch commit and required result/log evidence are verified, the ChatGPT control plane performs final staging cleanup with the **user-authorized Google Drive connector**. If the patch is still addressable, call the connector's permanent `delete_file` action for that exact Drive File ID/URL and require a successful deletion result. This is the standard owner-side retirement path for `drive_file_retirement_required=true` and for any staged patch that remains visible after workflow-side cleanup.
- If workflow-side trash already made the file inaccessible to the user connector, `drive_file_trashed=true` is sufficient cleanup evidence; do not add search/retry calls solely to rediscover an inaccessible trashed object.
- If patch download, verification, apply, commit, or push fails, preserve the Drive file and its File ID for the bounded retry/diagnostic decision. Do not perform connector deletion until the failed attempt is adjudicated and the file is no longer needed.
- Repository cleanup still removes the temporary caller first and then the marker/other temporary control state. No patch Base64 payload or fragment files should exist to clean up under normal operation.

## Scope boundary

Repository cleanup concerns checked-in stale documents, summaries, evidence, and temporary agent state. GitHub Actions workflows, connector trigger markers, generated repository artifacts, workflow cleanup ordering, Google Drive staging lifecycle, and external Actions artifact retention are governed by `GitHub_Workflow_Policy.md`.

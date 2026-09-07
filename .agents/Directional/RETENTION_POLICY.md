# Retention Policy

## Purpose

Define which project records are durable, which turn records may be retired, and the authorization required before durable information may be removed, weakened, consolidated, or replaced. This policy is maintained separately from `Future_Chat_Session_Handoff.md`.

Repository cleanup mechanics are defined in `CLEAN_UP_POLICY.md`, including the mandatory **document consolidation performed by every REVIEW turn** (user-authorized 2026-09-03; first applied at `M3-CP4c-3-TB18-REV`). That section is the standing authorization this policy requires for consolidation inside a REVIEW turn, and it is bounded: it never reaches durable project authority, normative definitions, policies, closure records or selector files, and it never authorizes replacing detailed authority with a summary. GitHub Actions workflow and remote-artifact lifecycle rules are defined in `GitHub_Workflow_Policy.md`.

## Durable project authority

The following records are durable project authority and must be retained unless the user explicitly authorizes their removal or replacement:

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Architecture_Independent_Design_Review_Report.md`
- `.agents/Directional/Surface_Cell_Test_Suite_Independent_Audit_And_Redesign_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md`
- `.agents/Directional/CLEAN_UP_POLICY.md`
- `.agents/Directional/RETENTION_POLICY.md`
- `.agents/Directional/Regression_Root_Cause_Tracker.md`
- `.agents/Directional/PR_8_Regression_Audit_Inventory.md`
- `.agents/Directional/Required_Green_Selector_Manifest.md`
- `.agents/Directional/LESSONS.md`
- `.agents/Directional/M1_Closure_Record.md`
- `.agents/Directional/M2_Closure_Record.md`
- `.agents/Directional/M3_CP2_Closure_Record.md`
- `.agents/Directional/M3_CP2b_Closure_Record.md`
- `.agents/Directional/M3_CP3_Closure_Record.md`
- `.agents/Directional/Architecture_M3_CP4_DEFN_Frozen_Definitions.md`
- `.agents/Directional/CHANGELOG.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `.agents/Directional/AGENT_POLICY.md`
- `TODO.md`
- `tests/TESTING_STRATEGY.md`

`.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` is the durable operating authority for reducing connector/workflow/artifact/tool calls without weakening source identity, evidence, turn boundaries, or cleanup safety. It is a mandatory full read at the start of every turn.

`.agents/Directional/LESSONS.md` is the single durable lessons record; the handoff's "Resume-critical lessons" section was moved there by explicit user authorization and now points to it. New lessons are added to `LESSONS.md` in the section that governs them, never appended to the handoff.

`TODO.md` is the single durable task index. The former root `TODO` and `MILESTONE_G_TODO.md` were explicitly authorized for consolidation into it; their actionable tasks and the pending tasks from `REORIENTATION_PLAN.md` must remain represented in `TODO.md` or their owning authoritative plan until completed.

In addition to the durable set, retain only the current authoritative evidence/report and the single next-turn plan needed to resume work. Superseded per-turn Code + Build plans/reports, Test + Benchmark plans/reports, review plans/reports, evidence indexes, machine summaries, and temporary workflow payloads may be removed only after their necessary durable facts have been preserved according to this policy and `CLEAN_UP_POLICY.md`.

## Handoff, TODO, and changelog ownership

`.agents/Directional/CHANGELOG.md` is the durable historical record for completed changes and immutable acceptance checkpoints. `TODO.md` is the durable task index. Maintain both separately from the handoff.

- `Future_Chat_Session_Handoff.md` contains the mandatory next action, current immutable authority, live blockers, resume-critical lessons, durable operating sections/checklists, and references needed by a new agent to continue correctly.
- `TODO.md` contains active, pending, blocked, deferred, and completed task status needed to track the product, architecture, and testing roadmaps without duplicating detailed evidence.
- Do not accumulate completed milestone narratives, old artifact tables, superseded turn summaries, historical acceptance logs, or task backlogs in the handoff merely as chronological history; however, this cleanup rule never authorizes removal of sections or content explicitly marked durable.
- When a completed turn creates a durable implementation or acceptance change, add or update the corresponding newest-first entry in `CHANGELOG.md` using its documented style before removing non-durable historical detail from the handoff.
- Update `TODO.md` as tasks are completed, selected, blocked, unblocked, or newly deferred; preserve references to the authoritative plan when detailed requirements live elsewhere.
- Preserve exact implementation commits, artifact/run identities, stable regression IDs, failure classifications, and material operational lessons in the changelog when they cease to be resume-critical.
- Keep unresolved or immediately actionable information in the handoff until it is no longer needed to resume the next turn correctly.
- A changelog entry supplements authoritative per-turn reports; it does not replace the exact evidence report while that report is the current immutable authority.

## Selector files — never consolidated

Every `Required_Green_Selector_*.txt` is durable, byte-frozen authority. They are **not** subject to the REVIEW-turn
document consolidation in `CLEAN_UP_POLICY.md`, and no turn may consolidate, rename, merge or delete one without
explicit user authorization naming the exact files.

The apparent redundancy is the mechanism. Most of the chain are exact prefixes of their successor, but every turn
re-proves that the accepted selector is an exact prefix of the current gate, and **that check has force only
because the accepted bytes are stored independently of the gate file**. Collapsing the chain would make the check
compare a file against itself, so it could never fail. The off-chain files (a superseded or withdrawn branch) hold
unique bytes and are not reconstructible from the chain at all.

`Required_Green_Selector_Manifest.md` is the derived index of the whole set — counts, LF SHA-256, prefix parents,
appended identities and roles. It is additive and grants no authority: **where it disagrees with a selector file,
the selector file wins.** Regenerate it with `tools/selector_manifest.py` after any turn that appends a selector.
A selector filename is not an identity count — read the count from the manifest.

## Evidence retention

- Raw machine-readable evidence that is still the sole authority for a claim is not stale and must be retained until its necessary facts have been folded into an appropriate durable/current record.
- Never remove the current immutable source/package authority until its necessary facts are captured in the succeeding authoritative report and durable/live records.
- External GitHub Actions artifact retention is governed by `GitHub_Workflow_Policy.md`; repository-side cleanup does not imply deletion of immutable external artifact history.

## `[ChatGPT Web]` Downloadable work-preservation artifacts — mandatory durability barrier

A local container, scratch filesystem, or `/mnt/data` path is **not durable project storage**. Whenever a turn produces a coherent repository-applicable work product that is not yet durably represented on the configured GitHub working branch, the exact produced bytes must cross a durable boundary before the turn proceeds into tool-heavy orchestration or risks interruption.

### `[ChatGPT Web]` Mandatory emission rule

1. After each coherent local editing unit that would require meaningful re-derivation if lost, and **before** the next tool-heavy remote phase (workflow installation/validation/execution, artifact orchestration, multi-step repository cleanup, or comparable work), emit the complete unapplied repository delta as a **user-visible downloadable file** that is uploaded to the conversation/File Library. Merely writing a file under `/mnt/data`, a local checkout, or another ephemeral path does not satisfy this rule.
2. The default and preferred artifact is one self-contained UTF-8 **Git binary unified patch** with extension `.patch`. It must cover all intended added, modified, deleted, renamed, mode-changed, and binary repository files in that coherent work unit. Generate it with full Git blob indexes and binary support (equivalent to `git diff --binary --full-index --no-ext-diff`) against one exact recorded base commit.
3. New/untracked files must be included. If the active local source is a snapshot without `.git`, create a temporary local Git baseline from the exact source bytes, overlay the intended work, stage the intended paths, and generate the patch from that temporary baseline. Do not omit new files merely because they were untracked in the scratch workspace.
4. The patch must begin with comment metadata that `git apply` tolerates and that permits recovery without chat-history inference. At minimum record:
   - `format=Directional-Work-Preservation-Patch-v1`;
   - repository and configured working branch;
   - exact `base_sha` from which the local work was derived;
   - turn/work-unit identifier and UTC creation time;
   - `state=prepared-unapplied` (or another exact state if the bytes have already partially landed remotely);
   - SHA-256 of the **diff body** after the metadata header;
   - intended changed-path count/list or a path-manifest line when practical;
   - safe manual application commands.
5. Name the artifact predictably so File Library search does not depend on remembered prose: `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` (sanitize only characters that are unsafe in filenames).
6. Before emission, verify the patch locally with `git apply --check` against the exact base bytes and run `git diff --check` (or an equivalent whitespace/error check) on the prepared work. Record the diff-body SHA-256 in the header. A patch that does not apply cleanly to its declared base is not a valid preservation artifact.
7. If additional local edits materially change the unapplied work after emission, emit a new complete patch that supersedes the earlier one before entering another interruption-risk phase. The newest complete artifact is the recovery candidate; incremental fragments are not preferred.
8. Do not include credentials, authenticated URLs, secrets, caches, build trees, generated packages, or unrelated scratch data. Preserve only the intended repository work product. If an essential local output truly cannot be represented by a Git binary patch, emit it as a separate archive **and** emit a small searchable text manifest naming the archive, its SHA-256, base/source authority, and restore instructions.

### `[ChatGPT Web]` Google Drive transport staging

After the user-visible backup exists and a non-minor patch is ready for remote application:

1. Upload the **same verified patch bytes** with the Google Drive connector to `My Drive/Directional-CI`; do not re-encode, fragment, or stage the patch in the GitHub repository.
2. Retain the returned Google Drive File ID and complete patch SHA-256 in turn-local execution evidence until the patch is either successfully applied and deleted or deliberately abandoned.
3. Google Drive staging is transient transport, not durable project authority and not a replacement for the chat/File-Library work-preservation artifact.
4. Invoke `.github/workflows/agent-google-drive-reusable.yml` by File ID. The workflow must verify the patch, base SHA, intended path set, `git apply --check`, and `git diff --check` before commit/push.
5. After a successful push, that same workflow must delete the Drive patch and report `drive_file_deleted=true`. If download, verification, apply, commit, or push fails, the Drive file remains available for bounded diagnosis/retry.
6. Never put credentials, OAuth tokens, authenticated Drive URLs, or service-account material in the patch or repository. The File ID itself is a transport handle and may be recorded in turn evidence.

### `[ChatGPT Web]` Recovery and manual application contract

A preservation patch is loss-prevention material, **not semantic/build/test acceptance authority**. On recovery:

1. locate the newest matching `Directional__...__work-preservation.patch` in File Library;
2. read and verify its metadata and diff-body SHA-256;
3. resolve current GitHub branch authority before applying;
4. if the branch is still at the recorded base (or the touched base blobs are unchanged), run `git apply --check <patch>` and then `git apply <patch>`; use `git apply --index <patch>` when staging the exact result is desired;
5. if the branch advanced, do not blindly apply. Compare the touched paths/base blobs first. `git apply --3way <patch>` may be used only when its full-index blob authority is available and the resulting merge is reviewed; otherwise rebase/reconstruct the patch deliberately;
6. after application, run `git diff --check`, inspect the resulting diff, and continue the normal turn-specific compile/test/review policy. Applying a preserved patch does not inherit any acceptance claim from the interrupted turn.

The durability barrier is intentionally **earlier than final closeout**. Its purpose is to make completed local intellectual work recoverable even if tool-call exhaustion, context interruption, workflow troubleshooting, or another failure occurs before GitHub mutation succeeds. Once the same bytes are durably committed to the working branch, the downloadable patch remains recovery provenance but is no longer the authoritative repository state.

## Durable-information mutation prohibition — user authorization required

This policy is durable and must remain in force unless the user explicitly changes it.

- Destructive edits to durable information are prohibited unless they are within the approved documentation scope of a Review turn explicitly authorized by the user, or the user explicitly authorizes the destructive edit and its scope. No other turn type—and no general instruction to update, clean, condense, reconcile, keep concise/current, remove stale evidence, or reduce file count—grants that authority.
- A destructive edit includes deleting a durable document; removing findings, rationale, decisions, invariants, design or architecture detail, policies, acceptance criteria, historical evidence or provenance, stable IDs, artifact identities, failed-attempt lessons, unresolved blockers, or resume guidance; replacing detailed authority with a summary; weakening or obscuring prior meaning; or moving information without a durable, traceable replacement.
- **Any section explicitly marked durable in any durable document is itself protected durable authority. Such a section must not be deleted, collapsed into another section, renamed away, replaced with a summary, or stripped of its durable meaning unless the user explicitly authorizes that destructive edit and its exact scope.** Additive/corrective edits are allowed only when the section remains present and its prior durable meaning is preserved.
- Protected information includes design, architecture, policy, remediation and roadmaps, plans, audit/review findings, regression/root-cause history, testing strategy, workflow/process rules, TODO/handoff recovery state, and any other record whose purpose is durable project memory.
- Routine stale per-turn evidence cleanup applies only to records expressly classified as temporary after all necessary facts have been preserved. It never authorizes destructive edits to protected durable information.
- Never remove, weaken, consolidate, reinterpret, or replace a durable document or mandatory instruction merely to reduce file count.
- The REVIEW-turn document consolidation defined in `CLEAN_UP_POLICY.md` is the one standing exception to the authorization requirement above, and only within its written scope: superseded per-turn reports, review records, build reports and consumed plans, folded into their family's consolidated record with their exact filenames and verdicts indexed, after their durable facts are already retained elsewhere. It is a preservation procedure, not a reduction target, and it grants no authority over any document listed as durable project authority above.
- Without the required authorization, edits must be additive or narrowly corrective and must preserve all prior durable meaning. If classification or authority is uncertain, stop and ask the user before editing.
- Before an authorized destructive edit, inventory the information at risk, define the exact authorized scope, and verify the resulting diff against that scope.

## Policy maintenance

Policy content normally belongs in dedicated policy documents rather than being duplicated broadly. `Future_Chat_Session_Handoff.md` is an explicit exception for user-designated durable handoff sections, start/end checklists, resume-critical lessons, and resume-critical policy reminders. Moving policy text between dedicated durable documents is permitted only when the destination preserves the full durable meaning and provenance of the moved rule and no explicitly durable source section is deleted without authorization.

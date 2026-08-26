# Future Chat Session Handoff

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical blockers/lessons required to continue safely. Architecture belongs in `DESIGN.md` and `REORIENTATION_PLAN.md`; tasks belong in `TODO.md`; completed history belongs in `CHANGELOG.md`; current exact runtime evidence belongs in the retained latest report/closure records and regression tracker.

This section is durable. It may be corrected or extended, but it must not be deleted, collapsed into another section, or replaced by a summary without explicit user authorization.

All instructions and sections prefixed with `[ChatGPT Web]` are mandatory for all `ChatGPT Web` sessions and must be followed exactly as written.
All non-`ChatGPT Web` agents, i.e. `ChatGPT Work`, `Codex`, `Claude`, etc., can safely ignore any instruction or section prefixed with `[ChatGPT Web]`.

## `[ChatGPT Web]` Patch Application Strategy — DURABLE, DO NOT DELETE

Historical Directional turns show a consistent empirical GitHub connector write limit of approximately 10 KB per individual write operation. Writes exceeding this size may be silently truncated without the connector returning an error. This is an observed connector behavior rather than a documented GitHub API limit.

Keep direct connector writes for genuinely minor changes when every individual content write is `<=10 KB`. Direct write remains the preferred path for an isolated small document/control change; modified workflow YAML must still satisfy `GitHub_Workflow_Policy.md` schema-validation requirements before execution.

For coherent code or documentation work that is not a genuinely minor direct write, use this standard transport and do not stage patch bytes, compressed Base64, or patch fragments in the repository:

1. **Snapshot** — obtain one exact source snapshot with `.github/workflows/agent-source-snapshot.yml` and download/verify that immutable snapshot once.
2. **Prepare + preserve locally** — edit the snapshot-derived source in the local container, generate one complete `git diff --binary --full-index --no-ext-diff` patch covering both source/code and documentation changes as applicable, verify `git apply --check` plus `git diff --check`, and emit that exact patch as a user-visible downloadable chat/File-Library backup under `RETENTION_POLICY.md`.
3. **Stage externally** — upload the exact verified patch with the Google Drive connector to `My Drive/Directional-CI`. Record the returned Google Drive **File ID** and the complete patch SHA-256. Google Drive is transport staging only; the chat/File-Library patch remains the interruption-recovery copy.
4. **Apply by File ID** — install only the minimal temporary caller/trigger control files required to invoke durable `.github/workflows/agent-google-drive-reusable.yml`. Pass the File ID, exact patch SHA-256, exact patch base SHA, target branch, and commit message. The reusable workflow must fetch the patch by File ID, verify full-patch and embedded diff-body hashes, verify the recorded base and that intended touched paths have not changed, run `git apply --check`, apply, run `git diff --check`, verify the exact changed-path set, commit, and push. Patch transport may not modify `.github/workflows/**`; workflow-file edits remain direct connector changes under the workflow policy.
5. **Move staged patch to trash after success** — only after the patch commit has pushed successfully, `agent-google-drive-reusable.yml` must inspect `capabilities.canTrash`. When true, move the Google Drive patch to trash using the same File ID and report `drive_file_trashed=true`; when false, skip the mutation request and report `drive_file_retirement_required=true` so the owner-authorized Drive control plane can retire it without a deterministic 403. If application/push fails, retain the Drive file and File ID for diagnosis/retry instead of retiring the only remote transport copy.
6. **Retire repository control state** — after result/log evidence and Drive retirement are verified, delete the temporary caller first, then retire its marker and any other temporary repository control files through the normal cleanup lifecycle. Do not leave turn-specific patch payloads or fragments under `.agents/Directional/turn-payloads/`.

Before any remote application, resolve current branch authority. If the branch advanced after the patch base, the reusable workflow must fail closed when any intended path changed; reconstruct/rebase the patch deliberately rather than force-pushing or applying blindly.

## Durable handoff policy — DURABLE, DO NOT DELETE

At the end of every turn:

1. replace stale next-turn/status text instead of appending chronological narrative;
2. keep unresolved, current-authority, and immediately resume-critical facts in this handoff;
3. move completed history to `CHANGELOG.md` and exact evidence to the owning report/tracker without deleting durable lessons or policies;
4. never treat a documentation/control-plane commit as implementation, build, test, benchmark, or runtime evidence;
5. preserve the mandatory start/end checklists and all other sections explicitly marked durable;
6. preserve every section explicitly marked durable in **any** durable document. Durable sections must not be deleted, collapsed, renamed away, replaced by a summary, or stripped of durable meaning unless the user explicitly authorizes that destructive edit and its exact scope;
7. `[ChatGPT Web]` perform work directly on the configured working branch. Do **not** create temporary, control, side, or staging branches unless doing so is absolutely necessary to circumvent a concrete procedural blocker that cannot safely be resolved on the working branch. If an exception is unavoidable, record the blocker and why the branch is necessary, keep it narrowly scoped, remove/reset it as soon as the blocker clears, return to the configured working branch, then proceed to the next turn;
8. every Test + Benchmark turn must categorize **every observed regression** in `.agents/Directional/Regression_Root_Cause_Tracker.md` and record root-cause analysis before the turn closes. If evidence does not justify a stable regression ID/count change, create or update a candidate/non-stable record and explicitly state why historical stable totals do or do not change, then proceed to the next turn;
9. `[ChatGPT Web]` `.github/workflows/agent-compile-reusable.yml` owns one durable compiler-cache namespace/schema. Turn-specific callers must not invent cache epochs, cache namespaces, or unrelated per-turn compatibility keys. Restore must always use the durable compatible namespace so prior ccache entries are reusable across turns.
10. work units 2 and 3, plus the exact M1 full-authority partial edges tasklisted in `TODO.md`, have the user-authorized partial-CB cadence exception: only those exact `P-CB` → `P-CB` edges may omit an intervening TB. Every partial remains runtime-free and semantically unaccepted; the final packaging partial must advance to its TB before later milestone work starts.
11. `[ChatGPT Web]` `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` is durable operating authority and a mandatory full read at the start of every turn. Apply it before selecting repository-read, workflow-observation, artifact-download, multi-file-write, cleanup, or PR-comment strategies.
12. `[ChatGPT Web]` `RETENTION_POLICY.md`'s **downloadable work-preservation durability barrier is mandatory**. Any coherent repository-applicable work that exists only in the local/container workspace must be emitted as a File-Library-backed downloadable `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` before entering tool-heavy remote orchestration or another interruption-risk phase. A local `/mnt/data` file alone is not durable. The patch is recovery material, not semantic/build/test authority.

Do not add transcripts, chronological tool history, copied superseded artifact tables, obsolete task selections, or generic procedure already owned by policy/skill files. Concision never authorizes deletion of durable information.

## Mandatory start-of-turn checklist — DURABLE, DO NOT DELETE

1. `[ChatGPT Web]` Review the [turn-based-coding-agent](https://github.com/akashskypatel/turn-based-coding-agent-skill) skill if not already reviewed for the current work session.
2. `[ChatGPT Web]` **Fully review `TOOL_USE_CONSERVATION_POLICY.md` and `GitHub_Workflow_Policy.md` at the start of every turn before choosing repository-access, workflow, monitoring, artifact, cleanup, or PR-comment operations. This is mandatory every turn and is not satisfied by having read it in a prior turn. Immediately after that read and before the first repository source/document inspection, explicitly choose one turn-local [`READ_MODE`](TOOL_USE_CONSERVATION_POLICY.md#2-start-of-turn-conservation-procedure) under policy Step 2. If the task/checklist already implies three or more repository documents/files, cross-file tracing, repository-wide search, iterative re-reading, or material uncertainty about crossing that threshold, `READ_MODE=snapshot` is mandatory. Do not perform starter connector reads first and decide later. If snapshot acquisition fails, follow Step 3's explicit fallback, record the blocker, and do not silently resume piecemeal range reads.**
3. `[ChatGPT Web]` Maintain a record of every temporary files created during the turn or files to be deleted at the end of the turn in `.agents/connector-triggers/turn-cleanup/manifest.txt`. This file is used by `.github/workflows/agent-turn-cleanup.yml` to clean up temporary files at the end of the turn.
4. Fully review this handoff, `RETENTION_POLICY.md`, and `CLEAN_UP_POLICY.md`.
   - `[ChatGPT Web]` If the preceding turn was interrupted or reported prepared-but-unapplied local work, search File Library for the newest matching `Directional__...__work-preservation.patch` **before re-deriving that work**; verify its embedded base SHA and diff-body SHA-256, then reconcile it with current branch authority under `RETENTION_POLICY.md`.
5. **Review `LESSONS.md` in full, and re-read the sections governing this turn's work before authoring any plan, fixture, gate criterion, or corrective measure.** This step is mandatory and is not satisfied by having read it in a prior turn.
6. Review `TODO.md` (including exact completed/current partial-CB status), `DESIGN.md`, `REORIENTATION_PLAN.md`, `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, the active next-turn plan, and `Regression_Root_Cause_Tracker.md`.
7. Confirm the configured working branch, branch head, exact implementation/source authority, and requested turn type before any write.
8. Verify every explicitly durable section required by the documents being touched is present before editing; do not proceed with a destructive rewrite if a durable section would be removed.
9. `[ChatGPT Web]` For Code + Build workflow work, verify the reusable compile workflow still owns the durable cache namespace/schema and that the caller does not supply a per-turn cache epoch/key.
10. `[ChatGPT Web]` Inspect `.github/workflows`, `.agents/connector-triggers`, and `.agents/Directional/turn-payloads` for stale temporary state without deleting durable workflows or records.

## Turn workflow — DURABLE, DO NOT DELETE

**Authorized by the user on 2026-08-25 and binding for all future work.**

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

1. **`CB`** — Code + Build. Authors semantics, compiles, packages. Executes no Directional runtime.
2. **`TB`** — artifact-only Test + Benchmark on the immutable package. Executes **the full current
   gate**, one identity per fresh process, with every mutation flag false.
3. **A green TB closes the checkpoint.** There is no separate acceptance ceremony.
4. **A red TB mandatorily routes to `REVIEW + PLAN`.** No retry, no patch, and no further CB without
   an intervening review.
5. **A red TB is information, not a debit.** Nothing is consumed, nothing is reset.

**Non-gating diagnostic identities**: A checkpoint may declare
identities that TB executes and reports but that are **excluded from the gate count**, each with a
written rationale and an owning corrective measure. A non-gating identity may never be promoted to
gating without a review recording why its precondition is now independently established.

## Mandatory next turn — `M3-CP4c-0-TB-R4` — EXACT NEXT / artifact-only Test + Benchmark

`M3-CP4c-0-CB4` is **COMPLETE / BUILD GREEN**. Its durable report and successor plan are:

- `.agents/Directional/Architecture_M3_CP4c0_CB4_Code_Build_Report.md`
- `.agents/Directional/Architecture_M3_CP4c0_CB4_Artifact_Only_Test_Benchmark_Plan.md`

**Immutable CB4 authority:** semantic source `de291a17d5e9bfb6f54918660320ecfa1d521be4`; compile event/control
SHA `baf7ed2ea9381ad47b3ae807d00d61bee0f0dcfe`; run/job `32926004147 / 98048909565`; package
`9591540182`, ZIP SHA-256 `8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`;
internal manifest **27/27 PASS**; embedded source SHA-256 `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32`;
`runtimeExecution=false` and all source-status records clean.

CB4 implemented G1–G6 **test-side only**. No `src/` or `include/` source changed. Ordinal 333 now uses a
DCEL-valid two-triangle witness and screens before `set_mesh`; ordinal 334 transports branch labels through
published `signedLift`; local-holonomy coverage was added; the seed-provenance falsifier no longer asserts
that the sphere fails; and G5 adds
`ResolvedBranchCorrection.PrescribedSphereA2aOutcomeIsAlwaysPublishedNonGating`, which always publishes
sphere A2a rejection loci or success trace/event counts with `credit=none;owningMeasure=G5`.

The frozen selector remains **338** and byte-for-byte unchanged: full `d588cae09067de6914aa1cb917716b11bae01e9f3b45910dbe0faa7d0c7a8116`;
first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328
`cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. T6, Q8, accepted expectations,
the prescribed-sphere fixture, `kBranchTopologyTolerance`, and E2–E6 semantics are unchanged.

**TB-R4 execution order is binding:** verify immutable package/integrity first; run all 338 selector identities
in exact order and fresh processes while retaining F6 continue-and-observe after a first red; then run the two
F3 supplementals separately; then run the G5 diagnostic regardless of prior semantic red. Q8 is creditable
only at exact integrity + **338/338** + F3 **2/2**. The G5 identity never contributes gate credit.

**P4 remains explicit:** Q8 is expected to fail because TB-R3 proved the prescribed sphere still did not
publish a network. If the 338/F3 precondition is green and Q8 is red, preserve the exact Q8 failure together
with G5's A2a outcome/rejection code and route to independent REVIEW + PLAN. A predicted red is evidence,
not authorization to repair inside TB. If the gate or F3 is red, Q8 is NOT CREDITABLE / NOT RUN, but G5 still
runs for observability.

**Context Load Plan for the successor:**

```yaml
load_next:
  - references/turns/TB-EXEC.md
  - references/turns/TB-REV.md
conditional_modules:
  - trigger: GitHub connector or artifact evidence inspection is required
    path: modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M3_CP4c0_CB4_Artifact_Only_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M3_CP4c0_CB4_Code_Build_Report.md
  - .agents/Directional/Architecture_M3_CP4c0_TB_R3_Review_Plan_Independent_Review.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/LESSONS.md
  - TODO.md
  - .agents/Directional/Future_Chat_Session_Handoff.md
do_not_preload:
  - CP4c-1 / CP4c-2 / CP4c-3 implementation scope
  - any corrective CB implementation before TB-R4 evidence is independently reviewed
  - unrelated historical milestone reports
```

## Current authority

### M3-CP4c-0 CB4 — COMPLETE / BUILD GREEN; TB-R4 pending

- semantic source: `de291a17d5e9bfb6f54918660320ecfa1d521be4`;
- compile event/control SHA: `baf7ed2ea9381ad47b3ae807d00d61bee0f0dcfe`;
- authoritative compile run/job: `32926004147 / 98048909565`;
- immutable package: `9591540182`, SHA-256 `8a93b553df337bc8ad952e6a5b348a3eaac8b2304b50c1402f5184a8ce4c561f`, manifest **27/27 PASS**;
- source archive SHA-256: `6077902a83b88d1ef839ab6d2bc285050f0c059511a71c9125b0324383d69a32`;
- frozen selector: **338**, hashes `d588cae0… / 601ce2b6… / cf93622e…`;
- CB4 runtime: **none**; `runtimeExecution=false`;
- exact next: `M3-CP4c-0-TB-R4` on package `9591540182` only.

### Accepted runtime authority

Latest accepted runtime remains CP4ab **316/316**, run/job `32758293793 / 97530833220`. CP4c-0 remains
unaccepted until TB-R4 proves its frozen requirements. Stable regression accounting remains **42 / 14 / 28**,
produced-witness debt **5**, M3 package count **43**.

## Standing product state

- M1 and M2 CLOSED / ACCEPTED; M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab accepted.
- CP4ab remains latest accepted runtime authority at **316/316**.
- CP4c-0 remains **OPEN / unaccepted**. CB4 package `9591540182` is build-green; no CB4 runtime exists yet.
- TB-R3's 333/334 reds were independently adjudicated test-side; CB4 contains only the authorized test/oracle/diagnostic corrections.
- G5 is permanently non-gating for this plan and must always publish the prescribed sphere A2a outcome.
- Q8 is frozen and unconsumed; P4 predicts it remains red after a green 338/F3 precondition.
- CP4c-1 remains OPEN/blocked; C4/C5 stay gating and its 318 selector is unchanged.
- CP4c-2 and CP4c-3 remain blocked and require their own `-DEFN` turns.
- Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **43**; `PR8-R042` remains resolved stable.
- Exact next is **`M3-CP4c-0-TB-R4`**. No retry, repair, later-checkpoint implementation, or Q8 execution outside the frozen TB-R4 conditions.

## Resume-critical lessons — DURABLE, DO NOT DELETE

**The lessons formerly listed here now live in `.agents/Directional/LESSONS.md`,** by explicit user
authorization, deduplicated and organized into eight sections. That document is durable project
authority: it may be corrected or extended, never deleted, weakened, or summarized away without
explicit user authorization. This section remains durable and must continue to point to it.

**Reading `LESSONS.md` is mandatory start-of-turn step 5.** Do not resume work from this handoff
alone.

Sections, so the right one can be found without reading the whole document:

| Section                                            | Read it before                                                               |
| -------------------------------------------------- | ---------------------------------------------------------------------------- |
| 1. Evidence and acceptance                         | promoting any artifact, selector, or audit result                            |
| 2. Fixtures and witnesses                          | authoring or judging any fixture, helper, or witness                         |
| 3. Negatives and oracles                           | authoring a negative, a tamper test, or an oracle                            |
| 4. Single authority and representation             | adding a product, moving a guard, or typing a domain                         |
| 5. Cross-field, cycle, and orientation conventions | **any A1/A2 matching, effort, index, cycle, or transition-orientation work** |
| 6. Gate and criterion authoring                    | writing an exit criterion or freezing a gate                                 |
| 7. Budget, attempts, and stop rules                | planning a checkpoint or running a mandatory review                          |
| 8. Build, package, and workflow mechanics          | any Code + Build turn or connector workflow                                  |

New lessons are added to `LESSONS.md` in the section that governs them, not appended here.

**Standing note on repeat failures.** Section 2's opening lesson records that the same
degenerate/unusable-fixture class has now cost **four consecutive M3 checkpoints** — CP1's planar
`z = 0` A1 fixtures, CP2's single-edge open rails, CP2b's hard-coded face-pair orientation, and
CP3a's one-ring fan, where every edge opposite the singular vertex is a boundary edge so the
required multi-face traversal was unsatisfiable by construction. Section 5 records that transition
orientation is mesh-owned. All were written down before the failure that repeated them. Reading the
relevant section is the cheapest control this project has.

CP3a broke the streak's shape: its fixture now **asserts its own precondition at runtime** — every
singular-fan opposite carrier must be interior — so the next author cannot reintroduce the defect
silently. CP3b then carried that habit forward unprompted and closed on attempt 1 with no diagnostic
gate. Copy that pattern into CP4's witnesses.

## Mandatory end-of-turn checklist — DURABLE, DO NOT DELETE

1. Confirm the requested turn stayed within scope and no later-turn implementation leaked into it.
2. For Code + Build turns, confirm `runtimeExecution=false`; for Test + Benchmark turns, confirm no rebuild/repair/source/test/fixture mutation occurred inside the immutable gate.
3. For every Test + Benchmark turn, update `Regression_Root_Cause_Tracker.md` for every observed regression/candidate before advancing the handoff.
4. Confirm exact source/package/run/artifact identities and stable regression totals are recorded in the owning durable report/tracker.
5. `[ChatGPT Web]` **Confirm no meaningful repository-applicable work remains only in the local/container filesystem.** For each coherent local work unit not yet durable on the working branch, emit or refresh the mandatory File-Library-backed `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` and locally verify its declared base/hash/applicability **before** cleanup or final repository closeout. If all such bytes are already durably committed, no new preservation patch is required solely for duplication.
6. `[ChatGPT Web]` Make sure `.agents/connector-triggers/turn-cleanup/manifest.txt` is up to date and make sure it does not include any durable files or any other files that need to be retained. Execute `.github/workflows/agent-turn-cleanup.yml` workflow to process the manifest and clean up the repository, and trimp historical PR comments.
7. Confirm the handoff names exactly one next turn and the task index agrees with it.
8. `[ChatGPT Web]` Make the final repository write one summarized PR #8 conversation comment after all branch/PR-description writes. No downloadable-artifact/tool emission may occur after that final comment.


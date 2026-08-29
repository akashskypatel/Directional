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
12. **`.agents/Directional/ORIENTATION.md` is DURABLE and must be updated at every REVIEW turn.** It is the cold-start context document: architecture, current position, witnesses, open problems, recurring defect patterns and source pointers, deliberately **substance-only** with no procedural content. It may be corrected or extended; it must not be deleted, renamed away, collapsed into another document, or replaced by a summary without explicit user authorization. Every REVIEW turn updates its currency line, "where we are", the witness table if a witness changed, open problems in priority order, and the recurring-defect section if the turn found a new pattern or instance. Authority: user instruction, recorded in `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md` §8.
13. `[ChatGPT Web]` `RETENTION_POLICY.md`'s **downloadable work-preservation durability barrier is mandatory**. Any coherent repository-applicable work that exists only in the local/container workspace must be emitted as a File-Library-backed downloadable `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` before entering tool-heavy remote orchestration or another interruption-risk phase. A local `/mnt/data` file alone is not durable. The patch is recovery material, not semantic/build/test authority.

Do not add transcripts, chronological tool history, copied superseded artifact tables, obsolete task selections, or generic procedure already owned by policy/skill files. Concision never authorizes deletion of durable information.

## Mandatory start-of-turn checklist — DURABLE, DO NOT DELETE

1. `[ChatGPT Web]` Review the [turn-based-coding-agent](https://github.com/akashskypatel/turn-based-coding-agent-skill) skill if not already reviewed for the current work session.
2. `[ChatGPT Web]` **Fully review `TOOL_USE_CONSERVATION_POLICY.md` and `GitHub_Workflow_Policy.md` at the start of every turn before choosing repository-access, workflow, monitoring, artifact, cleanup, or PR-comment operations. This is mandatory every turn and is not satisfied by having read it in a prior turn. Immediately after that read and before the first repository source/document inspection, explicitly choose one turn-local [`READ_MODE`](TOOL_USE_CONSERVATION_POLICY.md#2-start-of-turn-conservation-procedure) under policy Step 2. If the task/checklist already implies three or more repository documents/files, cross-file tracing, repository-wide search, iterative re-reading, or material uncertainty about crossing that threshold, `READ_MODE=snapshot` is mandatory. Do not perform starter connector reads first and decide later. If snapshot acquisition fails, follow Step 3's explicit fallback, record the blocker, and do not silently resume piecemeal range reads.**
3. `[ChatGPT Web]` Maintain a record of every temporary files created during the turn or files to be deleted at the end of the turn in `.agents/connector-triggers/turn-cleanup/manifest.txt`. This file is used by `.github/workflows/agent-turn-cleanup.yml` to clean up temporary files at the end of the turn.
4. Fully review this handoff, `RETENTION_POLICY.md`, and `CLEAN_UP_POLICY.md`.
   - `[ChatGPT Web]` If the preceding turn was interrupted or reported prepared-but-unapplied local work, search File Library for the newest matching `Directional__...__work-preservation.patch` **before re-deriving that work**; verify its embedded base SHA and diff-body SHA-256, then reconcile it with current branch authority under `RETENTION_POLICY.md`.
5. **Review `LESSONS.md` in full, and re-read the sections governing this turn's work before authoring any plan, fixture, gate criterion, or corrective measure.** This step is mandatory and is not satisfied by having read it in a prior turn.
   - Before every Code + Build turn, also review `.agents/Directional/GMP_COMPILE_POLICY.md`. GMP/GMPXX linkage is mandatory for every future compile; fallback exact arithmetic is not authoritative build evidence.
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

## Mandatory next turn — `M3-CP4c-2-DOC-R1` — documentation-only hash correction, measures **AE0-AE9**

`M3-CP4c-2-TB-X2-R7-REV` is **COMPLETE / REVIEW GREEN**. Read
`Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`: §1 the recomputed authority, §2 the mechanism,
§4 the design point, §5 what to preserve, §7 measures AE0-AE9, §8 the ORIENTATION rule.

**R7-0's stop was correct.** It refused to substitute observed values for planned constants — which would have
silently rewritten executable authority mid-run — stopped before the first Directional process, and ran a
post-preflight integrity check even though runtime never started. **AE7 preserves all three; do not "fix" any
of them.**

**All six hashes were recomputed from bytes in review** and match the immutable package, R6-EXEC and
`ORIENTATION.md` exactly. **The selector bytes never changed and the accepted authority chain is intact.** The
authoritative values are in the review record §1 — but **AE0 requires you to derive them yourself** from
`Architecture_M3_CP4c1_Required_Green_Selector.txt` (`head -316`, `head -346`, `head -353`, whole file) and the
two CP4c-2 candidate files, **not to copy them from any prose, including that table.**

**The defect is fabricated constants, and the proof is arithmetic:** the R7 plan's expected value for selector
357 is **63 characters**. SHA-256 is 64, so a stale or wrong-file digest would still be 64 — this was assembled
by hand. Every failing constant shares the **first eight** and the **trailing** characters with the truth and
differs only in the middle: the signature of `PREFIX…SUFFIX` expanded back to full length.

**Part of the cause is the reviewer's.** R6-REV's AD0 wrote all six hashes abbreviated, inside a measures table
that reads like a value table. **Rule adopted (lesson 22n): a digest is written in full or replaced by a file
reference plus "recompute" — never abbreviated where a value is expected.** **AE4** adds mandatory
64-lowercase-hex validation at authoring time; that alone would have caught the malformed value a turn earlier.

**AE2 is not optional and its report must include counts.** Sweep `.agents/Directional/**` for any other
selector-hash-shaped string and verify each against recomputed truth. **Report the number checked and the number
corrected even if it is zero** — a silent sweep is not evidence a sweep happened.

**One narrow sequencing change (AE8).** After the correction R7 retries unchanged in content, except that the
**non-gating** diagnostics R7-2..R7-5 run **before** the accepted-prefix gate and publish regardless of its
outcome. They grant no credit and mutate nothing, so this reorders publication, not authority. It ends an
eight-turn drought: `CAND-04` has been scheduled and not run in R2, R3, R4, R5, R6 and R7 — every stop
individually correct, every one upstream of the measurement. **If you judge that this ordering would let a
diagnostic observe state the gate would have rejected, stop and say so** rather than proceeding.

**`ORIENTATION.md` is DURABLE and must be updated at every REVIEW turn** — see durable policy item 12 and
end-of-turn checklist item 7.

`PR8-R043` unchanged (RESOLVED AT LOCUS, closure pending a full 355/355). **`PR8-R044`'s CB5 correction is
compiled but runtime-unproved** — the semantic/provenance split, the orbit-index resolution and the AD5
diagnostic have never executed. Stable accounting **44 / 14 / 30**, debt **5**, M3 packages **64**.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

### Superseded — the R7 EXEC stop as reported (retained for provenance)

`M3-CP4c-2-TB-X2-R7-EXEC` is **COMPLETE AT R7-0 / HARD ORCHESTRATION STOP / NO DIRECTIONAL RUNTIME**. Immutable
CB5 package `9719216316` remains valid and unchanged: outer
`sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`, semantic source
`755485865a7cf9c485d754f22b82a41ee151824b`, source archive
`sha256:78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`, internal manifest **28/28 PASS**,
GMP/GMPXX proven, and all six runtime binaries executable.

R7-0 obeyed the frozen *mismatch = hard stop* rule. The R7 plan's exact expected hashes disagree with immutable
selector authority for 346, 353, 357, and 358; 316 and 355 match. The immutable values agree with `ORIENTATION.md`,
R6-EXEC's prior successful preflight, and direct hashes of the package selectors. The wrong full strings were
introduced in CB5 closeout report/plan text while selector bytes remained unchanged. Tracked as
`M3-CP4c2-TB-X2-R7-ORCH-01`, **ORCHESTRATION / DOCUMENT-AUTHORITY / NON-STABLE**.

No accepted identity, CB5 diagnostic, independent actual-complex oracle, retained barrier diagnostic, D2, 357/358,
cumulative gate, or benchmark ran. R043/R044 therefore receive no new runtime evidence. Raw R7 archive:
`Directional__M3-CP4c-2-TB-X2-R7-EXEC__raw-evidence.tar.gz`,
`sha256:b83172acc3519fc6fe3472e5844a48e0bfd938fe9e6a5d68d14e515371454cc7`.

R7-REV is review/planning only. It must independently recompute the six selector authorities, localize the
transcription boundary, decide whether CB5 report/R7 plan require a documentation-only correction, and explicitly
decide whether the same immutable package may be reused for a corrected R7 retry. It executes no Directional
runtime and makes no product/test/fixture/selector semantic change, compile/package, benchmark, 357/358/gate
selection, mechanical/C2, or CP4c-3 progress.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are **CLOSED / ACCEPTED**.
- CP4c-2 CB5 remains build-green/runtime-free; CP4c-2 remains runtime-unaccepted.
- Current build/package authority remains `755485865a7cf9c485d754f22b82a41ee151824b` / package `9719216316`.
- Latest semantic runtime evidence remains R6-EXEC: ordinal 305 PASS, ordinal 310 first RED. R7 executed no
  Directional process because preflight hard-stopped under `R7-ORCH-01`.
- R043 closure still requires ordinal 305 green within full 355; R044 closure still requires ordinal 310 green
  within the same full 355. `R5-ORCH-01` remains resolved by R6 unconditional postflight.
- `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`; 357/358/cumulative gate remain
  blocked pending reviewed R7 evidence.
- Stable accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3
  packages **64**.
- **Exact next is `M3-CP4c-2-DOC-R1`**, documentation-only, under measures AE0-AE9; then the R7 retry on unchanged package `9719216316`.

## Context Load Plan

`load_next`:
- turn-based-coding-agent documentation/planning references; **no Code + Build or runtime modules**

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — **read first**; cold-start substance and the exact selector table. **Durable; update it at every REVIEW turn.**
1. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md` — **the authorizing record**; §1 the recomputed authority, §2 the mechanism, §7 AE0-AE9, §8 the ORIENTATION rule.
2. `.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt` plus `Architecture_M3_CP4c2_Required_Green_Selector_{357,358}.txt` — **the only authority for AE0**; recompute, do not copy from prose.
3. `.agents/Directional/Architecture_M3_CP4c2_CB5_Code_Build_Report.md` (AD0 audit) and `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md` (preflight table) — the two documents AE1 corrects, and the only two it may touch.
4. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R7_EXEC_Artifact_Only_Evidence.md` — R7-0's hard-stop evidence and the mismatch table.
5. `.agents/Directional/Regression_Root_Cause_Tracker.md` — `R7-ORCH-01`, `PR8-R043`, `PR8-R044`, `CAND-04`.
6. `.agents/Directional/LESSONS.md` **22n** — the digest-abbreviation rule this turn adopts.
7. `TODO.md` / `CHANGELOG.md` — current state/accounting.

**This is a documentation-only turn.** Do not run any Directional runtime including the accepted prefix, 357,
358, D2 or a cumulative gate; do not configure, compile, relink, package, or repair; do not edit any selector
file, product, test, or fixture; do not retro-expand historical abbreviated digests; do not touch the mechanical
witness, C2, or CP4c-3.

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
7. **On every REVIEW turn, update `.agents/Directional/ORIENTATION.md` before closing** — currency line, "where we are" including selector authority and stable accounting, the witness table if a witness changed, open problems in priority order, and the recurring-defect section if the turn found a new pattern or a new instance. It is durable; keep it substance-only.
8. Confirm the handoff names exactly one next turn and the task index agrees with it.
9. `[ChatGPT Web]` Make the final repository write one summarized PR #8 conversation comment after all branch/PR-description writes. No downloadable-artifact/tool emission may occur after that final comment.


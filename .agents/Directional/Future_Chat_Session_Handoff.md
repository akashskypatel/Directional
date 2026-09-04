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
12. **`.agents/Directional/ORIENTATION.md` is DURABLE and must be updated at every REVIEW turn.** It is the cold-start context document: architecture, current position, witnesses, open problems, recurring defect patterns and source pointers, deliberately **substance-only** with no procedural content. It may be corrected or extended; it must not be deleted, renamed away, collapsed into another document, or replaced by a summary without explicit user authorization. Every REVIEW turn updates its currency line, "where we are", the witness table if a witness changed, open problems in priority order, and the recurring-defect section if the turn found a new pattern or instance. Authority: user instruction, preserved in `M3_CP4c_Consolidated_Record.md` §6.6 and the 2026-08-29 R7-REV/DOC-R1 changelog entries.
13. `[ChatGPT Web]` `RETENTION_POLICY.md`'s **downloadable work-preservation durability barrier is mandatory**. Any coherent repository-applicable work that exists only in the local/container workspace must be emitted as a File-Library-backed downloadable `Directional__<TURN-ID>__base-<12SHA>__work-preservation.patch` before entering tool-heavy remote orchestration or another interruption-risk phase. A local `/mnt/data` file alone is not durable. The patch is recovery material, not semantic/build/test authority.

14. **Every REVIEW turn must perform document consolidation before closing** — `CLEAN_UP_POLICY.md`
    §"Document consolidation — every REVIEW turn". Preserve each folded document's durable facts in a retained
    record first, append its exact filename and verdict to the family's **folded document index**, retain one
    current document per role plus every selector file, and repair live citations in the same turn. It is a
    preservation procedure, not a reduction target, and it never reaches durable project authority, normative
    definitions, policies, closure records or selector files. Authority: user instruction 2026-09-03, first
    applied at `M3-CP4c-3-TB18-REV`.

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
                ↓ semantic red
        REVIEW + PLAN  →  CB  →  …
                ↓ orchestration failure
        CB (orchestration fix)  →  TB (re-execute)  →  …
```

1. **`CB`** — Code + Build. Authors semantics, compiles, packages. Executes no Directional runtime.
2. **`TB`** — artifact-only Test + Benchmark on the immutable package. Executes **the full current
   gate**, one identity per fresh process, with every mutation flag false.
3. **A green TB closes the checkpoint.** There is no separate acceptance ceremony.
4. **A red TB mandatorily routes to `REVIEW + PLAN`.** No retry, no patch, and no further CB without
   an intervening review.
5. **Orchestration failure routes to `CB`, not to `REVIEW + PLAN` — user-authorized 2026-09-04.** An
   orchestration failure is **not** a `RED` turn failure and produces **no semantic ledger**: nothing about the
   product was measured, so there is nothing for a review to adjudicate. It routes directly to a **`CB`
   orchestration-correction turn** that fixes the harness, control plane, or execution contract, followed by a
   `TB` that re-executes the failed turn.
   - The orchestration-correction `CB` is **control-plane-only where possible** and then **reuses the existing
     immutable package unchanged**, so the re-executed `TB` remains comparable to the frozen plan it consumes. It
     compiles and repackages only when the fix genuinely requires a source change, and it says which case applies.
   - It must **preserve the failed attempt's evidence** as invalid-attempt provenance, and may **not** promote any
     of its process results to semantic authority.
   - Rule 4 is unchanged and independent: a **semantic** red still routes to `REVIEW + PLAN`, with no retry, patch
     or further `CB` without an intervening review. Only orchestration failures take this edge.
   - The latest authoritative semantic runtime is unchanged by an orchestration failure and remains whatever the
     last valid `TB` established.
6. **A red TB is information, not a debit.** Nothing is consumed, nothing is reset.

**Non-gating diagnostic identities**: A checkpoint may declare
identities that TB executes and reports but that are **excluded from the gate count**, each with a
written rationale and an owning corrective measure. A non-gating identity may never be promoted to
gating without a review recording why its precondition is now independently established.

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the
chain, it **is** the review-and-plan turn for its checkpoint: one turn freezes definitions, adjudicates
the inherited candidates, decides gate membership per identity, and issues the successor's measures. A
separate `REVIEW + PLAN` turn is no longer scheduled ahead of a `DEFN`. This collapses only the
`REVIEW+PLAN → DEFN` edge; every other edge above is unchanged, and a red TB that routes to
`REVIEW + PLAN` without a `DEFN` still gets its own review turn. First applied at
`M3-CP4c-3-DEFN`.

## Mandatory next turn — `M3-CP4c-3-CB26` — EXACT NEXT / Code + Build, ORCHESTRATION CORRECTION

`M3-CP4c-3-TB23-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` (measures **CC0–CC8** discharged, static only).

### Authority for the correction and the re-execution

- semantic/evidence source: **`e12396d471c0754b112a40272a7992020ff49ced`** — ancestor of HEAD, **no code drift**;
- immutable CB25 package: **`9921914679`**,
  `sha256:db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7` — **reused unchanged**;
- frozen selector **397**: `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`, **397 identities**,
  selector 393 and accepted 365 both exact prefixes;
- preserved invalid-attempt run/job: `33833497955 / 100901221113`; result/log artifacts `9922540133 / 9922540522`;
  raw ledger `839e95feea68bdff35c8c9b11ca22f486f3452413f82017888f17ffc76e85e8d` — **audit-only provenance**;
- package pre/post census `9c7b12f4beba6f64e4ab1af3980554ba7b9f46af535ec2d2f2a9650f0359a927` — equal.

**Authoritative semantic runtime remains `M3-CP4c-3-TB22`: 387 PASS / 6 RED, accepted 365/365.**

### What the review established

**The ORCHESTRATION-INVALID classification is upheld, and the defect is the harness - not CB25 and not the
package.**

- **The package never contains `test-data`.** `.github/workflows/agent-compile-reusable.yml` copies only the eight
  compiled targets to `$OUT/bin` and two libraries to `$OUT/lib`; **no workflow in the repository references
  `test-data`**. Fixtures reach the binaries only because the **execution harness stages them** into the layout
  `tests/TestFixturePaths.h:51-64` resolves. TB18-TB22 did that staging - TB21's report records binaries
  hard-linked into an execution view with fixtures extracted from the packaged source. **TB23's harness omitted
  it**, and verified the extracted source workspace, a path the executable never consults.
- **CB25 is not implicated.** Its diff touches `RemeshDiagnostics.h`, `GlobalTopologyPlan.h`, the new
  `GlobalTopologyCertificateDiagnostics.h`, `GlobalTopologyPlan.cpp`, `RemeshPipeline.cpp` and
  `FieldAlignedCurveNetworkTests.cpp` - **no CMake, no `TestFixturePaths.h`, no packaging**.
- **Why a slip became a pseudo-ledger:** `test_data_root()` **fails open** - when neither candidate path exists it
  returns the sibling path anyway - so a missing fixture tree surfaces as hundreds of file-open failures instead of
  one typed stop. The raw **342 PASS / 55 RED, accepted 327/365** are fixture-open failures, **audit-only, not
  regression authority**.
- **CB25 statically satisfies its contract, so re-execution is worth doing.** `certificate_side_orbit` is **gone**;
  `GlobalTopologyCertificateDiagnostics.h` derives `certifiedFaceBySourceFace` from certificate evidence and
  assigns an owner only when a component's certified-face set has exactly one element (`:135-137`); the CA3 pair
  loop (`:181-200`) quantifies over **uncut** adjacent pairs outside `componentBarriers` with **no**
  `certificateSeparatingSourceEdges` intersection and increments `examinedPairCount` for every qualifying edge -
  CB24's structural zero **cannot recur in this form**. Ordinal 396 is the CA6 variation witness, 395 the CA2
  independence witness.
- **Not credited:** the invalid run's ordinals 394-397 results. **CA2/CA4/CA5/CA6 remain runtime-unconfirmed.**

**Authoritative semantic runtime remains `M3-CP4c-3-TB22`: 387 PASS / 6 RED, accepted 365/365.** Carried surfaces
367/368/369/370/374 unchanged. **There is still no vertex-30 discriminator.**

### CB26 binding scope — `CD0–CD8`, in the review record §7

Under the **2026-09-04 routing rule** an orchestration failure routes to a `CB` that fixes the orchestration,
followed by a `TB` that re-executes. **CB26 is that correction turn**; its subject is the execution harness and
the control plane, not the product.

- **CD0 - control-plane-only, and say so.** The defect is in the harness, not in source, so CB26 **must not**
  change product/test/fixture/selector bytes and **must not** rebuild or repackage. It **reuses immutable package
  `9921914679`** (`sha256:db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`) from source
  `e12396d471c0754b112a40272a7992020ff49ced` with selector **397** (`d67e5fb7...9b4853ee5`) byte-frozen, so the
  re-executed gate stays comparable to the frozen TB23 plan.
- **CD1** - **construct the execution view explicitly.** Stage the packaged binaries and the fixture tree extracted
  from the packaged source archive into the layout `tests/TestFixturePaths.h` resolves - a `test-data` directory
  that is either a sibling of the executable's parent or a child of the executable's directory, containing
  `test-data/benchmarks/fixtures`. **Record the exact staged layout in the report.**
- **CD2** - **verify through the consumer's resolution rule.** Preflight must confirm a known committed fixture is
  readable at the path the packaged executable itself resolves, by reproducing `test_data_root()`'s two-candidate
  rule against the staged view - **not** by checking the source workspace.
- **CD3** - **fail closed.** If CD2 does not pass, **do not start Directional runtime**; terminate with the frozen
  stop reason and preserve the evidence. This is the rule TB23-EXEC's harness violated.
- **CD4 - document the required layout.** Write the staged-view contract into the frozen TB plan and the harness,
  with the resolution order spelled out, so it stops being an undocumented dependency five gates relied on.
- **CD5 - preserve the failed attempt** as invalid-attempt provenance (run/job `33833497955 / 100901221113`,
  artifacts `9922540133 / 9922540522`, ledger `839e95fe...7ffc76e85e8d`). Promote none of it; do not repair,
  relocate or re-launch it.
- **CD6 - no product change; the fail-open resolver stays out of scope.** `M3-CP4c3-TB23-REV-CAND-01` is a source
  change that would invalidate package reuse and force a rebuild, so it belongs to the next CB already changing
  source. CB26 executes no Directional runtime.
- **CD7 - audit by assumption**: no product/test/fixture/selector/package byte changed, the package census still
  matches `9c7b12f4...0359a927`, and the only edits are harness/control-plane.
- **CD8 - publish the successor TB's obligations.** `M3-CP4c-3-TB23-R1` re-executes the frozen TB23 plan on the
  same package and must publish: accepted **1-365 = 365/365**; ordinal 366's seed state unchanged (component 0,
  `Multiple`, orbits `[0,1,3]`, 191 faces); **`examinedPairCount` non-zero** alongside `differingPairCount`;
  independently measured certified faces on both sides of each minority edge with the seed shown alongside; **the
  failing component's certified-face multiset**; ordinals **394-397** results; carried surfaces
  **367/368/369/370/374** unchanged; and **371/372/391/392/393** still PASS.

**Then `M3-CP4c-3-TB23-R1`** - artifact-only re-execution of the frozen TB23 plan on the same immutable package,
one identity per fresh process across all 397, every mutation flag false, publishing CD8's discriminators and
stating explicitly whether the run is semantically authoritative.

CD8's certified-face multiset **names the live branch** of `M3-CP4c3-TB21-CAND-01`: several certified faces means
the missing-barrier branch, one means the seed-read branch. The successor after TB23-R1 is an independent
`M3-CP4c-3-TB23-R1-REV`, which owns the correction. TB22-REV's prohibition stands: **no further diagnostic turn is
authorized on that surface** - CB25's contract is the last one.

Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **88**.

**Document consolidation ran this turn** under the standing rule (`CLEAN_UP_POLICY.md`). No document was retired
between reviews, so nothing needed retrospective indexing; only the superseded TB22 review record was folded. The
TB22 report, the CB25 build report, the frozen TB23 plan and the TB23-EXEC report are all **retained** — each is
still live authority for the re-execution.

### Context Load Plan

`load_next`: turn-based-coding-agent CODE + BUILD guidance (orchestration correction; control-plane only).

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first.
1. `.agents/Directional/M3_CP4c_Current_And_Forward.md` — current state, frozen successor, candidate index.
2. `.agents/Directional/Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` — **frozen CB26 scope, §7 CD0–CD8**.
3. `.agents/Directional/Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` — the frozen TB23 plan
   the successor TB re-executes; CD4 writes the staged-layout contract into it.
4. `.agents/Directional/Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` — invalid-attempt
   provenance; **its ledger is not semantic authority**.
5. `.agents/Directional/Architecture_M3_CP4c3_CB25_Code_Build_Report.md` — the package under re-execution.
6. `.agents/Directional/Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` — **current
   authoritative semantic runtime**.
7. `.agents/Directional/Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
8. `.agents/Directional/Required_Green_Selector_Manifest.md` — selector counts, LF hashes, prefix parents, roles.
9. `.agents/Directional/M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed.

**Runtime layout the harness must produce** (this is the dependency TB23 missed):
`tests/TestFixturePaths.h` resolves `executableDirectory.parent_path()/test-data` first, then
`executableDirectory/test-data`, and **returns the first path even when neither exists**. Stage fixtures so that
one of those two candidates contains `benchmarks/fixtures`, and verify by that rule.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py`, `selector_manifest.py`, and `fixture_probe.py`.

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

**Standing note on believing an error's name (added at `M3-CP4c-2-TB-X2-R7-REV`, `LESSONS.md` 57).** The
single most expensive mistake in CP4c-2 was not a wrong fix — it was eight turns of correct reasoning aimed at
the wrong mechanism, because a `default:` case in an error-translation switch assigned a semantic-sounding name
to 36 distinct upstream errors. Before planning around any typed failure that crossed a stage boundary, find the
translation site and check whether the code you are reading is the code that was raised.

**Extended at `M3-CP4c-3-TB1-REV` (`LESSONS.md` 64): the reason you add may itself be a collapse.** The same
sphere failure has now been resolved three times, one layer per turn — 36 codes → `RotationSystemInconsistent`
(AF0), nine sites → `TraceEventPositionInvalid` (AK3), and that name still covers **two** conditions with opposite
fixes. Every layer was worth resolving; each was declared "the cause" one turn too early. **When instrumenting a
collapsed error, read the site that sets the reason you are adding and count the distinct conditions that reach it,
before declaring the layer done.** A check at authoring time replaces a whole turn.

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
10. **On every REVIEW turn, perform document consolidation before closing** — fold superseded per-turn reports/review records/build reports/consumed plans into the family's consolidated record, index each folded filename with the verdict it carried, and repair live citations. Verify first that every durable fact already has a retained home. See `CLEAN_UP_POLICY.md`.


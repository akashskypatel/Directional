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

## Mandatory next turn — `M3-CP4c-2-TB-X2-R8-REV` — independent review of ordinal-359 gating-witness red

R8 is **COMPLETE / SEMANTIC RED / POSTFLIGHT GREEN** on immutable CB7 package `9724864897`. Authoritative run/job
`33288495471 / 99195869180` re-proved the inherited **355/355**, passed 356-358, and stopped at ordinal **359**
`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`. The identity fails at its baseline
`ASSERT_TRUE(baselineCutGraph)` before any enumeration comparison; 360-365 were not run. Full evidence is in
`Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md`. No retry or corrective CB is authorized
before the independent review.

`M3-CP4c-2-CB7` remains the immutable **BUILD GREEN / RUNTIME-FREE** package authority used by R8.

**Immutable build authority**

- semantic product/test source: `4f0f3ca74a88ba260a20c019437bc4995f2056e0`
- build-transport source: `1230621baff6d04fb20df3b1bf48903cd65b5d69`
- run/job: `33287281975 / 99192562149`
- package artifact: `9724864897`
- package SHA-256: `a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`
- log artifact: `9724865018`
- log SHA-256: `462090e66648fc6db583b770a2518aca0a3f63ee2ae167d900070fb4ed5460bd`
- source archive SHA-256: `3b4decd367a3fdb932754c3c6e420b536fa7607755e8ff2541f137f1589d5544`
- exact Eigen gitlink: `769c72fd8019e389810d1de1e7c243521a43b594`

The build-transport source differs from semantic source only in temporary control files and `.gitmodules` remote
transport; `src/`, `include/`, `tests/`, fixtures, and selectors are byte-identical. The canonical Eigen remote was
restored after packaging. `runtimeExecution=false`; all eight standard targets compiled with GMP/GMPXX and clean
source status. Exact implementation/build disposition is in `Architecture_M3_CP4c2_CB7_Code_Build_Report.md`.

**Selector authority**

Selector **365** is frozen with whole-file SHA-256
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. Its prefixes recompute to:

- 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- 361: `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`

Ordinals 362–365 are, in order:
`GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness`,
`SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs`,
`SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour`,
`SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted`.

`selected_r2_branch=NONE`; selector 365 was selected and executed red in R8; `gate_execution_authorized=false`
at closeout. Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, M3 packages **65**.

### R8 execution plan — COMPLETED EVIDENCE, NOT A SUCCESSOR PLAN

1. **Immutable preflight before runtime.** Download package `9724864897` by exact artifact ID; verify its outer
   SHA-256, internal `SHA256SUMS`, source archive, source commit `1230621b…`, exact Eigen revision, clean source
   status, `runtimeExecution=false`, and GMP/GMPXX linkage. Verify that build-transport versus semantic source
   changes no semantic path.
2. **Selector preflight.** Recompute whole selector-365 and 355/357/361 prefix hashes from committed bytes. Confirm
   all 365 names are unique and each resolves to exactly one compiled identity. No hash may be copied from prose.
3. **Gate authorization boundary.** Do not execute selector 365 until the R8 turn explicitly selects that frozen
   selector and records `gate_execution_authorized=true` for this immutable package. If authority cannot be
   established, stop before runtime rather than silently running a candidate gate.
4. **Accepted prefix first.** Execute ordinals **1–355**, one identity per fresh process. Any red is an immediate
   accepted-prefix hard stop; record the exact first-red ordinal and do not continue into CB7 identities.
5. **Checkpoint identities.** If 1–355 are green, execute 356–365 in order. Record each identity's process exit,
   selected count, duration, and stdout/stderr evidence. In particular 362–365 must actually execute, not gain
   transitive credit.
6. **Frozen non-gating evidence / AF6.** Execute every current CP4c-2 non-gating identity that the immutable package
   contains. If one is intentionally skipped, record a per-identity rationale; silence is not a disposition.
7. **AF0.** On the prescribed sphere publish both the surface-cut error and preserved originating
   `GlobalTopologyPlanErrorCode`; confirm no mapping/enum semantic was changed merely to make the name convenient.
8. **AF2.** Run the repaired D2 diagnostic and require it to name the withdrawn barrier object as diagnostic-only;
   actual embedded-graph authority must remain the comparison oracle. Reject stale line-number localization as
   authority.
9. **AF3 / AF4.** Run production-authority torus diagnostics from committed `torus.rawfield`; run the enumeration
   permutation falsifier with mesh/raw-field rows permuted together. Publish the torus actual-graph certificate and
   semantic/provenance digest comparisons.
10. **AG3.** Publish the prescribed sphere's independently reconstructed component records behind pre-cut `chi=6`
    and explicitly adopt or refute DEFN-R2's excess-4 reading. For every exercised witness publish
    `traceEndpointsAttached` and `noDegreeZeroNodes`; either false value is a semantic red.
11. **AG5 / AG2.** The constructed trace-crossed witness must first prove its runtime precondition: a selected
    `TraceInteriorCrossing` cut exists. Then require the synthetic crossing node to carry exactly two Cut and two
    Trace rays and the derived four-sector rotation. Also exercise the pre-existing degree-three edge-locus shape
    required by DEFN-R2 §7.4.
12. **AG6.** Independently reconstruct crossing nodes from network segment entry points without calling
    `SurfaceCutGraph`; compare per promoted edge `crossingNodes=n` and `cutArcs=n+1` term-by-term against producer
    publication and verify immutable network digests.
13. **AG4 / saturation.** Production witnesses are expected to publish `saturationUsed=false`. The positive
    saturation identity must deliberately exhaust the conservative proposal, publish non-empty locus/promoted
    count, then independently prove cellularity. Saturation on an ordinary production witness is a finding, not a
    pass-through.
14. **Regression accounting.** Categorize every observed red/candidate in `Regression_Root_Cause_Tracker.md` before
    closing EXEC. Do not change stable totals without evidence satisfying the tracker contract.
15. **Unconditional postflight.** Re-hash package/source/selectors and confirm no configure, compile, relink, repair,
    discovery, source/test/fixture/selector mutation, or benchmark outside the frozen plan occurred. Preserve raw
    result/log artifacts and write the R8 report.
16. **Disposition.** Full 365 green under immutable pre/postflight closes CP4c-2 under the standing CB→TB workflow.
    Any semantic red routes to independent `REVIEW + PLAN`; no retry or corrective CB is allowed first.

### Context Load Plan

After the durable start-of-turn checklist, the R8 review must read:

1. `Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md` — immutable first-red and diagnostics.
2. `ORIENTATION.md`.
2. `Architecture_M3_CP4c2_CB7_Code_Build_Report.md` — exact package/build and measure disposition.
3. `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` — Amendment 14 and AG0–AG9.
4. `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` — only still-binding §§4/5/7/9 and Amendment 13.
5. `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md` — inherited 355 runtime baseline.
6. `Regression_Root_Cause_Tracker.md`.
7. `TODO.md`, `CHANGELOG.md`, and selector 365.

The exact next turn is independent `M3-CP4c-2-TB-X2-R8-REV`. It may review and plan only: no retry, corrective
source/test mutation, compile, package, benchmark, or new Directional runtime. It must adjudicate R8-CAND-01, the
incomplete AF3 rail-authority migration, the sphere `RotationSystemInconsistent` origin, and the unexecuted 360-365
tail before authorizing any CB.

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


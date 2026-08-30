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

## Mandatory next turn — `M3-CP4c-2-CB8` — correct exactly two test identities

`M3-CP4c-2-TB-X2-R8-REV` is **COMPLETE**:
`Architecture_M3_CP4c2_TB_X2_R8_Independent_Review_Record.md`. Measures **AH0–AH9**.

### What R8 proved — do not re-derive any of this

- Inherited accepted prefix **355/355 PASS** on immutable CB7 package `9724864897` (run/job
  `33288495471 / 99195869180`), plus ordinals 356, 357, 358. Postflight immutable-green, all mutation flags false.
- **The torus is done.** Ordinal 356: `networkV=48`, `networkE=48`, `cutEdgeCount=28`, `torusRegionCount=4`;
  independent oracle `V/E/F = 72/76/4`. `76 − 48 = 28` equals the producer's cut-edge count, so producer and oracle
  agree term for term. Criteria **C1** and **C6** hold on the produced torus.
- **AF0 printed the sphere's real origin:** `originatingTopologyError=RotationSystemInconsistent`, source face
  `25-27-28`, `producerCutEdgeCount=0`. The sphere fails **before** cut selection; Amendment 14 does not explain it.
- AF2's repaired D2 executes; AG3's `traceEndpointsAttached` and `noDegreeZeroNodes` hold on all three witnesses,
  so DEFN-R2 §5.2's completeness premises are runtime-verified; AF6 was honoured.

### The red, and why it is narrow

`SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration` (ordinal 359) fails at
`tests/FieldAlignedCurveNetworkTests.cpp:2381` before any comparison. `make_source_authority(mesh)` supplies **none**
of the four production feature products — no `authoritativeRails`, no hard-feature edges, all-zero
`sourceFaceComponents` and `sourceFaceSheets` — and `rails_from_atlas` then keeps only `SourceBoundary` and
`HardFeature` edges, of which a **closed** torus with no declared features has neither. The rail set is **empty by
construction**; the network is empty.

R8's own split is the proof: ordinal 358 uses the identical construction on the **bounded** `make_square_mesh` and
passes; 359 is the only one executed on a **closed** witness. Ordinal 361 shares it. **Scope is ordinals 359 and
361 only** — 356/357/362 use the production fixture, 363–365 thread features correctly. Record:
`M3-CP4c2-TB-X2-R8-CAND-01`, which **supersedes** `R7-CAND-01`.

`rails_from_atlas` is not the defect. It is correct when the atlas was built with the features first — exactly what
CB7's own `build_cp4c_trace_crossed_cut_fixture` (`:1426-1491`) and `observe_cp4c_witness` (`:4391-4403`) do.

### CB8 scope — AH0–AH9

1. **AH1 first, no build.** Read the ordinal-359 process stdout/stderr from retained result artifact `9725240893`
   and publish every `ADD_FAILURE` line verbatim. The lambda's non-fatal failures plus a **default-constructed**
   `SurfaceCutGraphError` sentinel funnel atlas / network / cut-graph failures into one fatal `ASSERT_TRUE`, so the
   reported locus identifies none of them. No new runtime.
2. **AH2** rebuild ordinals 359 and 361 on one production feature authority: take `products.authoritativeRails` and
   `hard_feature_edge_keys_from_rails(rails, |V|)`, set `SurfaceCellTracingOptions.authoritativeRails`,
   `.hardFeatureEdges`, and the **permuted** `.sourceFaceComponents` / `.sourceFaceSheets`, then
   `build_source_topology_regions` and `FieldTransportAtlas::make(..., hardFeatures, ...)`. Follow
   `observe_cp4c_witness`. `SourceEdgeTopologyKey` is vertex-keyed, so rails and hard features are **invariant**
   under face-row reordering — only the per-face label vectors need permuting, by the reversal the test already
   applies to `F` and the raw-field rows.
3. **AH3** do **not** re-run the whole pipeline per ordering. Considered and rejected: it would couple A2a′'s gate
   to upstream enumeration invariance and destroy the red's locality.
4. **AH4** add a closed-witness runtime precondition — `if (mesh.boundaryLoops.empty()) ASSERT_FALSE(rails.empty())`
   — to ordinals 358–361 and the AG5 fixture, in the CP3a style.
5. **AH5** remove the sentinel; return a typed result naming the failing stage with **that stage's own** error.
   **Prohibited:** printing `cutGraph.error().code` at line 2381 while the sentinel remains — a default-constructed
   error reads as `InvalidSourceBinding` and would emit a fabricated locus.
6. **AH6** binds the TB: when 363–365 first run, publish whether trace-crossed edges were selected by the ordinary
   tree–cotree path or only under saturation; if only under saturation, a second witness is owed.
7. **AH7** if AH1 shows the cut graph itself failed on an *empty* network, record a new candidate — do **not**
   widen CB8.
8. **AH8** CB8 must not absorb: the sphere's `RotationSystemInconsistent` fix, any new gate identity, any selector
   byte, any change to `topology_error`'s mapping or an error enum value, a whole-pipeline invariance identity, a
   benchmark, or `gate_execution_authorized=true`.
9. **AH9** bookkeeping; the TB after CB8 re-runs gate 365 **from ordinal 1** and still honours AF6.

### Still unexecuted after the hard stop

Ordinals 360 (two-ring digest split as a gate), 361 (closed-witness digest split — `PR8-R044`'s fix is runtime-proved
on **one** witness only), 362 (**criterion C3, deferred a seventh time**), 363–365 (Amendment 14's subdivision, the
degree-four edge-locus rotation, and the saturation last resort). **Measure `AD3` is unresolved for a third turn**;
ordinal 359 is its only falsifier. Compiled-but-unexecuted authority is debt wearing a green label.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are **CLOSED / ACCEPTED**.
- CP4c-2 is **OPEN / runtime-unaccepted**. CB7 package `9724864897` is current build authority; R8 is the latest
  semantic runtime evidence.
- **Gate authority is selector 365**, whole-file SHA-256
  `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; its `head -355`, `head -357` and `head -361`
  reproduce the accepted-355, candidate-357 and 361 hashes exactly. 357, 358 and 361 are retained lineage only.
- Open candidates: `M3-CP4c2-TB-X2-R8-CAND-01` (ordinals 359/361, vacuous rail set) and
  `M3-CP4c2-TB-X2-CAND-04` (the sphere: a producer `RotationSystemInconsistent` **and**, independently, a
  non-cellular pre-cut graph `V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`). `R7-CAND-01` is superseded;
  `R7-CAND-03` and `R8-ORCH-01` are closed. Live measure **AD3**.
- Stable accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3
  packages **65**. `selected_r2_branch=NONE`; `gate_execution_authorized=false`.
- **Exact next is `M3-CP4c-2-CB8`.**

## Context Load Plan

`load_next`:
- turn-based-coding-agent `references/turns/CODE_BUILD.md`, the GitHub/artifact capability module (AH1 must read
  retained result artifact `9725240893`), and `GMP_COMPILE_POLICY.md`

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — **read first**; current as of R8-REV. §6's closing paragraph explains the
   vacuous-rail trap that produced this red; §7 items 1-3 are the live problems.
1. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R8_Independent_Review_Record.md` — the authorizing review:
   the fourfold mechanism, the two-ordinal blast radius, and measures **AH0–AH9** with their prohibitions.
2. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md` — exact R8 runtime
   result and artifact identities (AH1's source).
3. `.agents/Directional/Architecture_M3_CP4c2_CB7_Code_Build_Report.md` — current immutable build/package authority
   and the AF/AG delivery record.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` — `R8-CAND-01`, `CAND-04`, superseded `R7-CAND-01`,
   live measure `AD3`.
5. `.agents/Directional/Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` — Amendment 14 and the completeness
   theorem; read `…DEFN_R1…` only alongside it, since its §6 case 2 and §8 are superseded.
6. `TODO.md` / `CHANGELOG.md` — current task and the lessons adopted at R8-REV (59, 60, 64z).

**This is a bounded CODE + BUILD over two test identities.** Honour AH8 exactly: no product source change is
authorized by this review, and a compile-green result is not semantic acceptance.

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


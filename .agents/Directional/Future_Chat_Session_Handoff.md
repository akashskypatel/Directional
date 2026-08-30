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

## Mandatory next turn — `M3-CP4c-2-CB9` — convert A2b's two stale cut-arc consumers

`M3-CP4c-2-TB-X2-R9-REV` is **COMPLETE**:
`Architecture_M3_CP4c2_TB_X2_R9_Independent_Review_Record.md`. Measures **AI0–AI9**.

### What R9 settled — do not re-derive any of this

Run/job `33319911575 / 99279955697` on immutable CB8 package `9726295440`: accepted prefix **355/355 PASS**,
ordinals **356–362 PASS**, ordinal **363 RED**, 364–365 NOT RUN; 366 fresh processes, zero zero-selected,
postflight immutable-green with every mutation and benchmark flag false, three frozen non-gating identities each
selected once.

- **`R8-CAND-01` CLOSED** — 359 and 361 both green in a run reaching 361. AH2 was correct.
- **Measure `AD3` RESOLVED** — ordinal 359 reached its comparison at last, so the raw `face.orbit` index in a
  semantic digest is proved by test, not by comment.
- **Criterion `C3` GREEN** at ordinal 362, after seven deferrals. **C1, C3 and C6 all hold on the produced torus.**
- **`PR8-R044`'s single-witness residual discharged** — 360 (bounded) and 361 (closed) both pass.

### The red at ordinal 363 — a genuine product defect

The witness is fine: it proved an exact trace/source-edge crossing, built a **cellular** `SurfaceCutGraph`, and
selected a `TraceInteriorCrossing` candidate. A2a′ did its job; `GlobalTopologyPlan::make` rejected the plan with
`InvalidCutGraphBinding`.

**The producer is correct** (`EmbeddedGraphTopology.cpp:503-545`): exact `ExactUnitParameter` ordering, coincident
crossings rejected not merged, and **every sub-arc emitted in the canonical `cutEdge.first() → cutEdge.second()`
direction** (`ArcDraft` `:175-178` stores endpoints verbatim, no canonicalization). That third property is what
makes the correction small — the existing `face_orients_edge_forward` + `interiorDart = 2·id + (forward ? 0 : 1)`
formula stays valid **per sub-arc**.

**Two consumers are stale, and they fail differently:**

1. **Loud** — `GlobalTopologyPlan.cpp:479-516` demands exactly one Cut arc per cut edge, and still calls cuts
   *"ordinary embedded source-edge barriers"* while the trace block eighteen lines below reasons in **chords and
   fragments**. Amendment 14 made cut arcs chord-like; A2b treats them as whole-edge barriers — the
   whole-edge-versus-arrangement error `PR8-R043` and Amendment 13 fixed one layer up.
2. **Silent** — `GlobalTopologyPlan.cpp:1239-1242` inserts the **whole source edge's two endpoints** into
   `boundaryVertices` for a sub-arc whose own endpoints may be a source vertex and a crossing node, or two crossing
   nodes touching no source vertex at all. `boundaryVertices` is a **skip list** (`:1341-1344`), so over-inserting
   **suppresses** the interior-vertex ownership check with no error and no diagnostic. **Fixing only site 1 would
   trade a red gate for a quiet weakening.**

**Cause of the omission:** DEFN-R2 §4 itemized five producer-side changes under "convert every consumer" and did
not list A2b's cut-arc binding. CB7 and CB8 implemented all five correctly. `LESSONS.md` **61**.

### CB9 scope — AI0–AI9

1. **AI1 first, no build.** Produce the consumer audit **yourself**, by search over `arc.cutEdge`,
   `GlobalTopologyArcKind::Cut` and `cutGraph.cut_edges()`, and publish it with a per-site verdict:
   *edge-keyed by intent (correct)* / *arc-keyed and already sub-arc-correct* / *arc-keyed and stale*. Compare with
   the review's §4 table **after**; explain any difference. A copied enumeration inherits the omission that caused
   this red.
2. **AI2** convert `:479-516` to iterate all sub-arcs; **state the canonical-direction dependency in the comment**
   so a later change to emission order cannot silently invalidate the dart formula; keep the two-incident-faces
   guard; keep a typed failure for **zero** arcs; replace the stale "source-edge barriers" comment. Publish
   `fragmentOrbits[face].size()` against `tracePieceCount[face] + 1` and the per-(face, cutEdge)
   `edgeOrbitEvidence` cardinalities — verify the reconciliation, do not adopt the review's argument.
3. **AI3** fix the silent `boundaryVertices` site: a sub-arc contributes only the source vertices that are its own
   endpoints, resolved through `build_node_loci`'s existing `NodeLocus{vertex, edge}` threaded in from
   `build_regions`. A node with only an `edge` locus contributes none. **No second node→vertex lookup.** This
   **tightens** a loose check, so a new legitimate red there is a finding, not a regression.
4. **AI4** record the four closures, and annotate `SurfaceCutGraph.cpp:293-297` with "proved by ordinal 359".
5. **AI5** test-helper hygiene: `build_topology_plan` / `build_surface_cut_graph`
   (`tests/FieldAlignedCurveNetworkTests.cpp:~1690-1714`) print the typed code and then throw on `built.value()`.
   Keep the printing; stop the fall-through. `LESSONS.md` 60, second instance.
6. **AI6** carry `AH6` forward unchanged — it needs 363–365 all reached.
7. **AI7** if the audit finds a site needing a **representation** change rather than a per-arc loop, **stop and
   return to definition**. Amendment 14 is frozen and must not be worked around.
8. **AI8** CB9 must not absorb: the sphere's `RotationSystemInconsistent` fix, any new gate identity, any selector
   byte, any error-enum or `topology_error` mapping change, any change to `EmbeddedGraphTopology.cpp`'s crossing
   emission (AI2 depends on its canonical direction), or any relaxation of `proves_cellularity()`, the
   fragment-count invariant, or `UncutFaceComponentOrbitSeedNotUnique`. No benchmark, no gate execution.
9. **AI9** bookkeeping; the TB after CB9 re-runs gate 365 **from ordinal 1** and still honours the frozen
   non-gating selector.

### Still unexecuted

Ordinals **364** (the degree-four two-Cut/two-Trace edge-locus rotation — the one code gap DEFN-R2 named) and
**365** (the saturation last resort), for a third turn. Static reading says CB7's generalization is sub-arc-correct;
that is not evidence.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are **CLOSED / ACCEPTED**.
- CP4c-2 is **OPEN / runtime-unaccepted**. CB8 package `9726295440` is current build authority; R9 is the latest
  semantic runtime evidence. **C1, C3 and C6 are green on the produced torus.**
- **Gate authority is selector 365**, whole-file SHA-256
  `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; its `head -355`, `head -357` and `head -361`
  reproduce the accepted-355, candidate-357 and 361 hashes exactly. 357, 358 and 361 are retained lineage only.
- Open candidates: `M3-CP4c2-TB-X2-R9-CAND-01` (A2b's two stale cut-arc consumers),
  `M3-CP4c2-TB-X2-CAND-04` (the sphere: a producer `RotationSystemInconsistent` **and**, independently, a
  non-cellular pre-cut graph `V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`), and `R8-CAND-02` (zero-node/zero-arc
  closed-surface behaviour, non-gating). `R8-CAND-01`, `R7-CAND-01`, `R7-CAND-03`, `R8-ORCH-01` and `R9-ORCH-01`
  are closed; measure `AD3` is resolved.
- Stable accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3
  packages **66**. `selected_r2_branch=NONE`; `gate_execution_authorized=false`.
- **Exact next is `M3-CP4c-2-CB9`.**

## Context Load Plan

`load_next`:
- turn-based-coding-agent `references/turns/CODE_BUILD.md` and `GMP_COMPILE_POLICY.md`

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — **read first**; current as of R9-REV. §7 items 1-2 are the live problems;
   §6's closing paragraphs carry the arrangement model and the witness-construction trap.
1. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R9_Independent_Review_Record.md` — the authorizing review: the
   producer/consumer split, the loud-and-silent consumer pair, the §4 audit table, measures **AI0–AI9**.
2. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Report.md` — exact R9 runtime
   result and artifact identities.
3. `.agents/Directional/Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` — Amendment 14 and the completeness
   theorem, **frozen**; read `…DEFN_R1…` only alongside it (its §6 case 2 and §8 are superseded).
4. `.agents/Directional/Architecture_M3_CP4c2_CB8_Code_Build_Report.md` — current immutable build/package authority.
5. `.agents/Directional/Regression_Root_Cause_Tracker.md` — `R9-CAND-01`, `CAND-04`, `R8-CAND-02`, and the closed
   `R8-CAND-01`.
6. `TODO.md` / `CHANGELOG.md` — current task and the lessons adopted at R9-REV (61, 62).

**This is a bounded CODE + BUILD over two A2b consumers plus test-helper hygiene.** Honour AI8 exactly, and treat a
compile-green result as build evidence only.

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


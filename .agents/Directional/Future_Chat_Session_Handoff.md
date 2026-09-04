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
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

1. **`CB`** — Code + Build. Authors semantics, compiles, packages. Executes no Directional runtime.
2. **`TB`** — artifact-only Test + Benchmark on the immutable package. Executes **the full current
   gate**, one identity per fresh process, with every mutation flag false.
3. **A green TB closes the checkpoint.** There is no separate acceptance ceremony.
4. **A red TB mandatorily routes to `REVIEW + PLAN`.** No retry, no patch, and no further CB without
   an intervening review.
5. **Orchestration Failure**: Orchestration failure is not a `RED` turn failure. Fix the orchestration issue as a revision turn and re-execute the failed turn.
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

## Mandatory next turn — `M3-CP4c-3-CB25` — EXACT NEXT / Code + Build, DIAGNOSTIC-ONLY

`M3-CP4c-3-TB22-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` (measures **BZ0–BZ8** discharged, static only).

### TB22 immutable runtime authority

- semantic/evidence source: **`d69729a69a40b020968ed6ef1fbc1bc788284518`** — ancestor of HEAD, **no code drift**;
- CB24 compile run/job: **`33823590494 / 100871347582`**; package artifact **`9919225745`**,
  `sha256:7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`;
- selector **393**: `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`, **393 identities**,
  selector 391 and accepted 365 both exact prefixes;
- TB22 run/job: **`33826248118 / 100879465830`**; result/log artifacts **`9920122224 / 9920122598`**;
- exact 393-row ledger: **`4998ca25b1477c2a32299bc3eb3d552e3ea9b0e2ccbf0eb4894393964f29dbbe`**;
- pre/post package byte+mode census: **IDENTICAL**, `7e0c552c79281f97b7553406acd44383ff867197f36da54cd306ac9258fa2b74`;
- selector result: **387 PASS / 6 RED**; accepted 1–365 **365/365 PASS**; reds 366/367/368/369/370/374.

### What the review established

**Both CB24 measurements are vacuous - proved statically, not inferred.** BZ2 said not to accept a diagnostic's
name as its proof; neither diagnostic measures what its name says.

- **The faithfulness residual is a structural zero.** `GlobalTopologyPlan.cpp:1362-1389` requires an edge to be in
  `certificateSeparatingSourceEdges` **and not** in `componentBarriers`. That first set is populated only from
  Mandatory and Cut arcs (`:1191-1200`), whose source edges are exactly `mandatoryEdges` (`:674`) and `cutEdges`
  (`:649`), and `componentBarriers = mandatoryEdges u traceTouchedEdges u cutEdges` (`:1114-1116`). **The subset
  relation makes the conjunction empty; the loop body never executes.** `residual=0, witnessCount=0` on every
  mesh, unconditionally.
- **The certificate columns are the seed, re-printed.** `certificate_side_orbit` (`:1172-1184`) returns
  `edgeOrbitEvidence[(face,edge)]` when unique, else `fragmentOrbits[face]` when size 1 - the same two lookups the
  seed rule uses - and the component side is **assigned equal** to the labeled side (`:1272-1278`). The `3/3` and
  `1/1` agreement is a **tautology**: one value, computed once, displayed three times.
- **Two producers; the shipped path calls the wrong one.** `certificateSideOrbitsByEdge` (`:1204-1212`) *is*
  genuinely certificate-derived from `walk.orbitByDart`, but it is consulted **only** inside the unreachable
  residual loop.
- **The seed asks the wrong question.** `edgeOrbitEvidence` records a dart side of a chord in the **labeled
  neighbour** - evidence about that triangle's interior arrangement, not about which certified face the **uncut**
  triangle across the edge belongs to. The uniqueness guard is **preserved** as a safety property; `[0,1,3]` is
  fixture-specific and must not drive a general rule.
- **No correction is authorized.** Not a seed-rule CB (the causal claim still needs the certificate attribution
  that was never measured), not a DEFN (the definitions are not ambiguous; the code never asks the certificate),
  not a barrier-set change. **Both branches of `M3-CP4c3-TB21-CAND-01` remain live.**

**These were my own measures.** BY3 said "attribute each minority edge's two sides to certificate faces" and BY4
said "publish the projection faithfulness residual". Neither named its source of truth or stated a falsifiability
condition, so both were satisfiable without measuring anything. CA1-CA3 and CA6 fix that.

**371/372/391/392/393 all pass**; `M3-CP4c3-TB21-CAND-02` **closes / runtime proved**. 368/369/370/374 unchanged
under their existing owners. **There is still no vertex-30 discriminator.**

### CB25 binding scope — `CA0–CA9`, in the review record §8

**Diagnostic-only, with falsifiability required.** No product semantic change.

- **CA0** - accepted 365 untouched; **selector 393 byte-frozen** at `ee8cc033...27644c4d`, republished unchanged;
  **eight standard compile targets with mandatory GMP/GMPXX linkage**; no runtime; no acceptance claimed.
- **CA1** - **derive certified face ownership from the certificate.** A source triangle's certified face must come
  from the `SurfaceCutGraph` certificate's face structure - the authority `proves_cellularity()` validates - and
  **not** from `edgeOrbitEvidence`, `fragmentOrbits`, `seedOrbits` or any seed-side lookup. Publish it under a
  distinct name, and **retire or rename `certificate_side_orbit`** so a seed-derived value can never again be read
  as certificate evidence.
- **CA2** - **measure each minority edge's two sides independently.** Both sides' certified faces come from CA1's
  authority; **neither may be assigned from the other**, and a row must record when a side's certified face is
  unavailable rather than inheriting a value.
- **CA3** - **replace the residual with a satisfiable one.** Quantify over adjacent **uncut** source-triangle pairs
  whose shared edge is **not** in `componentBarriers`, counting a pair when the two triangles' CA1 certified faces
  **differ**. Publish the **examined-pair count separately from the differing-pair count**, so a zero result is
  distinguishable from an empty domain.
- **CA4** - publish the failing component's **multiset of CA1 certified faces** over its member triangles, bounded
  with a truncation marker. Spanning several certified faces makes the missing-barrier branch live; spanning one
  makes the seed-read branch live.
- **CA5** - one witness per new field through the **production** path, plus a byte-identical unrelated-error
  regression witness.
- **CA6** - **every new diagnostic must be falsifiable and its witness must exercise the variation.** For CA3, a
  witness whose input makes the differing-pair count **non-zero**; for CA1/CA2, a witness where the certified face
  and the seed orbit **differ**. A witness that only asserts a field is published does not satisfy CA6. **This
  supersedes ordinal 393's contract** under BZ7's escape clause.
- **CA7** - append the next selector **named by its resulting identity count**; 393 stays an exact prefix; no
  reordering; regenerate `Required_Green_Selector_Manifest.md` with `tools/selector_manifest.py`.
- **CA8** - **no product semantic change whatsoever**: the seed rule, the guard and its predicate,
  `componentBarriers`, the component partition, `seedOrbits`, `edgeOrbitEvidence`, `add_fragment_orbit`, the
  `exteriorOrbits` filter, `is_terminal_slit`, the face walk, the rotation system, region drafts, CB21's
  comparison, `proves_cellularity()` and the certificate stay untouched; `localFragmentCount` stays non-fatal.
  **No barrier-set change. No revert of CB21.** No fixture geometry mutation, tolerance, float-derived decision or
  accepted-boundary relaxation; no sphere / saturation / ordinal-370 / folded-cone / vertex-30 / finalize-contact
  product work.
- **CA9** - six `M3-CP4c-3-TB23` discriminators: (1) 1-365 stay **365/365**; (2) ordinal 366 **still** reds at
  `UncutFaceComponentOrbitSeedNotUnique`, component 0, `Multiple`, orbits `[0,1,3]`, 191 faces - any movement
  falsifies CA8; (3) the CA3 residual publishes **both** an examined-pair count and a differing-pair count, and
  the **examined count is non-zero**; (4) the minority rows carry **independently computed** certified faces for
  both sides, with the seed shown alongside; (5) the failing component's certified-face multiset is published -
  **spanning several faces or one decides the owner**; (6) 367/368/369/370/374 unchanged and 371/372/391/392 still
  PASS.

**No further diagnostic turn is authorized on this surface after TB23** - CA6 exists precisely so this one
produces a discriminating result. The successor after TB23 is an independent `M3-CP4c-3-TB23-REV`, which owns the
correction once CA3/CA4 name the live branch.

Accepted authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **87**.

**Document consolidation ran this turn** under the standing rule (`CLEAN_UP_POLICY.md`), including retrospective
indexing of anything the CB24/TB22 turns retired between reviews. Current authority is the TB22 report plus the
TB22-REV record. No selector file, normative definition or policy was touched.

### Context Load Plan

`load_next`: turn-based-coding-agent CODE + BUILD guidance.

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first.
1. `.agents/Directional/M3_CP4c_Current_And_Forward.md` — current state, frozen successor, candidate index.
2. `.agents/Directional/Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` — **frozen CB25 scope, §8 CA0–CA9**.
3. `.agents/Directional/Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` — current runtime authority.
4. `.agents/Directional/M3_CP4c_Frozen_Definitions.md` — Part I §3 is an implication with a premise; Parts IV/V
   prohibited lists; Part VI for vertex-star definitions. **Read the prohibited lists before authorizing any
   correction, and carry each finding's premise, not just its conclusion.**
5. `.agents/Directional/GMP_COMPILE_POLICY.md` — mandatory for every compile.
6. `.agents/Directional/Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`.
7. `.agents/Directional/Required_Green_Selector_Manifest.md` — selector counts, LF hashes, prefix parents, roles.
8. `.agents/Directional/M3_CP4c_Consolidated_Record.md` — only when historical lineage is needed; its **folded
   document index** resolves every folded or retired per-turn plan, report and record.

Source surfaces CB25 will touch: `src/geometry/GlobalTopologyPlan.cpp` (certified-face derivation, the minority
rows and the residual only), `src/geometry/SurfaceCutGraph.*` read-only for the certificate's face structure, the
plan diagnostics headers for the added typed fields, and `tests/` for the CA5/CA6 witnesses.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py`, `selector_manifest.py`, and `fixture_probe.py`. See
`tools/README.md` for the caveats.

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


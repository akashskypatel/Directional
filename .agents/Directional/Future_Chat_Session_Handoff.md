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

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the
chain, it **is** the review-and-plan turn for its checkpoint: one turn freezes definitions, adjudicates
the inherited candidates, decides gate membership per identity, and issues the successor's measures. A
separate `REVIEW + PLAN` turn is no longer scheduled ahead of a `DEFN`. This collapses only the
`REVIEW+PLAN → DEFN` edge; every other edge above is unchanged, and a red TB that routes to
`REVIEW + PLAN` without a `DEFN` still gets its own review turn. First applied at
`M3-CP4c-3-DEFN`.

## Mandatory next turn — `M3-CP4c-3-CB9` (Code + Build, runtime-free)

`M3-CP4c-3-DEFN-R2` is **COMPLETE**. It discharged CB8-REV's **AX1–AX8**, froze the vertex-star continuation
semantics, proved the mechanical locus exactly, and authorized exactly one bounded successor. Record and measure
authority: `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md` (**AY0–AY9**). Nothing was executed, compiled,
packaged or mutated. Selector **373** stays byte-frozen at
`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; **selector 374 still does not exist.**

### What is now frozen

**Amendment 22 — continuation is the straightest geodesic of the intrinsic vertex star.** One exact
arrival-anchored ray (pointing *back* along the incoming trace, in the arrival face's chart), written once by A2a
branch continuation; the admissible fan (barrier and source-boundary truncation inherited) developed isometrically
into one chart, so the `k`-th radial ray sits at `A_k = Σ_{i<k} θ_i`; continuation at `β = α + Θ/2` with
`Θ = Σ_i θ_i`; the **unchanged** exact half-open convention applied to the developed sectors `[A_k, A_{k+1})`; one
typed certificate. `Θ/2` rather than `π` is the load-bearing choice — it makes a non-flat star's gap/overlap
**impossible** instead of adjudicated, and coincides with the ordinary straight line wherever `Θ = 2π`. A1 is not
redefined: `signedLift` maps a branch label and is never a ray transform. Every candidate-local direction is
demoted to audit data.

**Amendment 23 — publish the budget.** The exact election is the sign of a signed sum of arccosines
(`cos θ = D/√P`, `sin θ = √Q/√P`, `D`/`P`/`Q` exact rationals), degree up to `4^k` in fan length. Admissible only
with a **certified filter** (correct answer or defer, never an approximation), an **exact fallback that always
terminates and is actually implemented**, and a **declared budget** with a typed fail-closed state. The fallback is
load-bearing: it is the only path that can decide a continuation lying exactly on a radial ray.

**Typed states:** boundary-ray (decided by the existing convention, recorded as `onRadialRay`),
`VertexStarTruncatedBeforeContinuation` (open fan — reported, never restored by crossing a barrier), and
`VertexStarDegenerateSector` (an angle exactly `0` or `π` — reported at A2a with its locus, repaired only at the
conditioning stage, Amendment 20).

### The mechanical proof — vertex 30, exact

Rational identities over the committed `mechanical_feature.obj`; no factorization, no floating point. Rows 43 and
218 are exact right angles (`u·w = 0`); `θ₂₀₉ + θ₂₀₈ = π/2` and `θ₄₁ + θ₄₀ = π/2` exactly (`D₁D₂ ≥ 0` and
`(D₁D₂)² = Q₁Q₂`). Hence **`Θ(v30) = 2π` exactly** — CB8-REV's explicitly non-authoritative float observation is now
a proof, and the same test over the six other pairings is false, so it is the fixture's structure and not a fitted
coincidence. The developed sectors give `sector(209) ∪ sector(208) = [π, 3π/2)`, which contains the continuation of
every `FaceInterior` seed from arrival face `(24,30,32)` (`α ∈ (0, π/2)`).

> **Owner = row 209 `(30,119,123)` if `α < θ₂₀₉`, else row 208 `(30,31,119)`; `α = θ₂₀₉` is the exact boundary-ray
> case. Row 41 `(25,30,31)` — one of the two faces the current code elects — is unreachable by any continuation.**

The star is genuinely folded: hinges `43|218` and `208|41` have non-parallel normals.

### What CB9 must do — AY0–AY9

1. **AY0** selector 373 recomputed and byte-frozen at authoring and preflight; accepted 365 untouched;
   `selected_gate=NONE`; `gate_execution_authorized=false`; no runtime, no gate, no benchmark.
2. **AY1** implement the seed, one per arrival event, sign and chart exactly as frozen.
3. **AY2** implement the development and election with `direction_in_vertex_sector` **unchanged**, applied to
   developed sectors. Remove `incomingDirection = nextPairing->direction` and every per-candidate representative
   from the decision path; keep them as audit rows only.
4. **AY3** implement the certified filter, the exact fallback and the published budget (**≥ 16**), in that
   dependency order. The fallback must be reachable, not stubbed.
5. **AY4** implement the typed states, each recorded **before** any conditional that can skip a state
   (Amendment 19).
6. **AY5** derive and commit the falsifying folded-fan witness — exact coordinates, at least one non-coplanar
   hinge, angles certified by rational identities, cross representatives chosen so **more than one** candidate would
   accept its own representative, and a boundary-ray instance. **Vertex 30 cannot be the only witness**: it is
   intrinsically flat and cannot separate `β = α + Θ/2` from `β = α + π`, so a `Θ ≠ 2π` witness is required too.
   Prove in the report that the witness fails under the old mechanism and passes under the frozen authority.
7. **AY6** append ordinal **374** only if AY5 falsifies; otherwise report and stop. Selector 373 keeps every byte.
8. **AY7** implement the §AX8 audit contract **and extend the `RemeshDiagnostics` projection in the same change** —
   the closure of `M3-CP4c3-TB6-CAND-01`.
9. **AY8** audit by assumption: *"a value reaching a topological decision was re-expressed by its consumer"* and
   *"an exact computation has no declared bound on its input size"*, each with a site named outside the record's own
   list.

**AY9 prohibits:** any floating-point step in the decision chain, including `from_double_exact` of a transported
value (Amendment 18); treating `signedLift` as a ray transform; deciding from a candidate's own representative;
candidate ordering, nearest-angle, seams, or **any** tolerance; changing the half-open convention, the
`FaceInterior` rule, or barrier/boundary truncation; inventing a port or face (Amendment 21); repairing degenerate
input geometry at A2a (Amendment 20); publishing an owner without its certificate; stubbing the exact fallback or
shipping an unpublished budget; touching ordinal 370, the prescribed sphere or saturation; reopening
Amendments 12–23; changing any selector byte beyond the one authorized append; treating report-only results as gate
credit; and executing Directional runtime, running a gate, or benchmarking in a CB turn.

**Stop rule.** If the exact fallback cannot be implemented within the frozen semantics, CB9 stops and reports, as
CB8 correctly did. A second architectural stop is a valid outcome; a tolerance is not.

### Deferred and untouched by this turn

Ordinal 370's empty-network product red, the prescribed sphere's `NoCarrierMatch / SourceEdgeUnavailable`,
saturation coverage, and the mechanical zero-unbound proof all remain open and were untouched, as AX0 requires.
Stable accounting **44 / 14 / 30**; produced-witness debt **5**; semantic package count **73**. CP4c-3 remains
OPEN; CP4c-2 remains CLOSED / ACCEPTED at 365/365.

## Context Load Plan

`load_next`:
- turn-based-coding-agent Code + Build guidance

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first.
1. `.agents/Directional/Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md` — **the frozen AY0–AY9 scope, Amendments 22–23, the vertex-30 proof, and the AX8 audit contract.**
2. `DESIGN.md` §7.2 / §7.2.1 — Amendments 17, 18, 19, 20, 21, 22, 23.
3. `.agents/Directional/Architecture_M3_CP4c3_CB8_Independent_Review_Record.md` — the AX plan this record discharges, and the ownership split it froze.
4. `.agents/Directional/Architecture_M3_CP4c3_CB8_Code_Build_Report.md` — the exact source baseline and the stop CB9 is resuming from.
5. `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_373.txt` — byte-frozen; recompute, do not edit.
6. `benchmarks/fixtures/milestone-g/mechanical_feature.obj` — the fixture the vertex-30 proof is derived from.
7. `.agents/Directional/Regression_Root_Cause_Tracker.md`, `TODO.md`, `CHANGELOG.md`, `M3_CP4c_Consolidated_Record.md`, `GMP_COMPILE_POLICY.md`.

CB9 is **runtime-free**: no Directional runtime, no gate execution, no benchmarking, no acceptance attempt. Every
compile links **GMP/GMPXX** (`GMP_COMPILE_POLICY.md`). The successor after CB9 is an artifact-only TB on the new
immutable package against selector 373, or 374 if AY6 legitimately created it.

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


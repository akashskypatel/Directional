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

## Mandatory next turn — `M3-CP4c-2-CB1` — cut-graph authority for A2b, measures **X0-X9**

`M3-CP4c-2-DEFN` is **COMPLETE / DEFINITION-ONLY**. Read
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` in full before writing any code; §5 is the frozen contract,
§7 the measures, §8 the falsifiable predictions.

**CP4c-1's closure was independently re-verified before the definition was written** — all four selector hashes
recomputed identical, `src/` and `include/` frozen across CB4, W1/W2/W5 confirmed in source. The claim is upheld.

**The decision.** One new authority, **`SurfaceCutGraph` (stage A2a′)**, produced after A2a and consumed by
A2b, guaranteeing the curve network's complement is a disjoint union of open discs. **`DESIGN.md` §7.2 and
§4.6 are amended (Amendment 12).**

**Why, provably.** For a cellular embedding on the torus, `F = E − V + χ = E − V`. The measured torus network
has `V = 48`, `E = 48`, `χ = 0`, so `F = 0` — impossible, since the complement is non-empty. At least one
component is not a disc. Generalized: a disjoint union of closed curves always has `E = V`, so **no disjoint
union of closed curves can ever be a cut graph of the torus** — this is not a defect of the committed fixture
and cannot be fixed by choosing better feature curves. `UncutFaceComponentOrbitSeedNotUnique` at
`GlobalTopologyPlan.cpp:1741` is **correct behaviour reporting a missing input; there is no bug at that line.**

**The one boundary that must not be crossed.** §7.2's stop condition forbids *repairing* a produced region.
It does not forbid a separate earlier authority *supplying cuts as an input*. The test: if the cut decision can
be made without ever looking at a produced `GlobalTopologyPlan` region, it is a precondition and is permitted;
if it needs to see one, it is a repair and is a **stop**. A2a′ may not read a `GlobalTopologyPlan`.

**Scope.** CP4c-2 owns **C1** and **C6**. **C3 is deferred pending measure X2**: the sphere's
`RotationSystemInconsistent` is a different failure — `χ=2`, 24 traces, 56 events, a different code, and
unmeasured — and designing for it unmeasured would repeat the CP4c-0/0b dependency inversion. **The gate is
357 or 358; X2 decides, and this document does not freeze it.**

**Vacuity trap.** C3 and C6 are quantified over "produced witnesses", and today no witness produces a plan, so
both would pass vacuously. C1 is the non-vacuity anchor; **a green C6 over zero regions is a red result** (X7).

**Out of scope:** the mechanical witness and its A1 `IncompleteCycleBasis`, C2, CP4c-3, seam quality, and the
alternatives harness.

### Predecessor authority — `M3-CP4c-1`, CLOSED / ACCEPTED

`M3-CP4c-1` is **CLOSED / ACCEPTED**. Authoritative artifact-only TB-R5 run/job
`33161644741 / 98817323175` consumed immutable CB4 GMP package `9675666067` from semantic/test source
`b1ce8ad65952bd2bd76238f6dfc55523f6a24747` and returned **355/355 PASS**. Prefixes 316/346/353, C4 ordinal
354, and C5 ordinal 355 all pass in the same immutable run. All 355 identities selected exactly once; zero C++
exceptions escaped; package/source preflight and postflight passed.

W3 is fully discharged. The corrected C5 reaches and passes both named-kind checks, and the observed union is
exactly `{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}` with contributors
prescribed sphere / two-ring / prescribed sphere. Torus contributes zero terminal kinds. Mechanical remains
upstream at `field-transport-atlas/IncompleteCycleBasis`. The explicit two-ring report identity passes; three
historical diagnostics remain report-only with zero gate credit; both W5-retired inverted diagnostics are absent.
`M3-CP4c1-TB-R4-CAND-03` is **RESOLVED / TB CONFIRMED / TEST-SIDE / NON-STABLE**.

Result/log artifacts are `9681960334 / 9681960615`, digests
`b8be035ed728b5d6f8efe65e260f9557a9aa8cad0e82b94d11107aab44187a5d /
55ad320aaf810bb5b02fbfccdd7662f4a47333586bdb30397d624d701710439b`. Stable accounting remains
**42 / 14 / 28**, produced-witness debt **5**, M3 packages **57**.

The next turn is **definition-only** `M3-CP4c-2-DEFN`. It must settle the architecture gap already identified in
`ROADMAP.md`: on a closed index-free surface, singularity/feature/boundary seeds can all be absent, so the current
§4.6 network can be empty and A2b has no seam/cut graph from which region ownership can start. Do not author
product/test/fixture/selector code, compile, or execute runtime in the DEFN turn. The historical parent allocation
is C1/C3/C6; rebased trajectory arithmetic is **358 = accepted 355 + C1 + C3 + C6**, but the definition turn owns
whether/how that successor selector is frozen. CP4c-3 remains blocked.

## Current authority

### M3-CP4c-1 TB-R5 — accepted runtime authority

- status: **COMPLETE / GATE GREEN 355/355 / CP4c-1 CLOSED / ACCEPTED**;
- run/job: `33161644741 / 98817323175`;
- semantic/test source: `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`;
- immutable GMP package: `9675666067` / `63b66788…45ec17`;
- required selector: **355** / `e9d88f11…5afeaa`; prefixes 316/346/353 all green; C4/C5 green;
- W3 exact terminal-kind union/contributors: kinds 2/3/4, sphere/two-ring/sphere; torus none; mechanical `IncompleteCycleBasis`;
- three historical diagnostics report-only; explicit two-ring report PASS; W5-retired identities absent;
- immutable package/source postflight PASS; configure/compile/relink/repair/discovery/mutation all false;
- result/log: `9681960334 / 9681960615`, digests `b8be035e…7a5d / 55ad320a…439b`;
- retained report: `Architecture_M3_CP4c1_TB_R5_Artifact_Only_Test_Benchmark_Report.md`;
- closure authority: `M3_CP4c1_Closure_Record.md`.

### Accepted predecessor and build provenance

CP4c-0b remains accepted at 353/353 (`33136084757 / 98736295227`), and CB4 remains the exact build provenance
for the package TB-R5 consumed (`33145657048 / 98766007030`, source `b1ce8ad65952…a24747`, package
`9675666067`). No later documentation/control commit changes semantic or build evidence provenance.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, CP4c-0, CP4c-0b, and **CP4c-1 are CLOSED / ACCEPTED**.
- Current accepted runtime is CP4c-1 TB-R5 **355/355** on package `9675666067` / source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`.
- CP4c-1 C4/C5 are accepted at ordinals 354/355; exact 353/346/316 predecessor prefixes remain green.
- `M3-CP4c1-TB-R4-CAND-01` is resolved test-side over-specification/non-stable; `CAND-03` is resolved TB-confirmed test-side inverted-precondition/non-stable.
- `M3-CP4c0-DEFN2-CAND-01` remains open/non-stable and owned by its previously recorded future measure; no CP4c-1 result changes it.
- Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **57**.
- **Exact next turn is `M3-CP4c-2-CB1`, Code + Build, runtime-free, under measures X0-X9.** CP4c-3 remains blocked.

## Context Load Plan

`load_next`: turn-based-coding-agent `references/turns/CB.md`. `GMP_COMPILE_POLICY.md` is a mandatory read per start-checklist step 5.

Minimum successor context after the mandatory durable policy/start checklist:

1. `.agents/Directional/Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` — **the frozen contract.** §5 the product, §7 measures X0-X9, §8 predictions, §4 Amendment 12.
2. `src/geometry/GlobalTopologyPlan.cpp:1694-1746` — the complementary-component traversal to **reuse, not duplicate**, and the exact `UncutFaceComponentOrbitSeedNotUnique` site.
3. `DESIGN.md` §§4.6 and 7.2 — the text Amendment 12 replaces; read before editing.
4. `tests/FieldAlignedCurveNetworkTests.cpp` — `expect_cp4c_plan_disc_proofs` for the existing region-certificate shape (`boundaryWalkCount`, `sourceFacesConnected`, `eulerCharacteristic`, `proves_disc_topology`) that the cellularity certificate must mirror.
5. `.agents/Directional/Architecture_M3_CP4c_Required_Green_Selector.txt` lines 317-322 — the exact C1-C6 allocation; C1/C6 are in scope, C3 pends X2, C2 is CP4c-3.
6. `.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt` — the accepted 355 predecessor order/hash that X0 must re-verify unchanged.
7. `.agents/Directional/M3_CP4c1_Closure_Record.md` — accepted 355/355 authority, for provenance only.
8. `TODO.md`, `Regression_Root_Cause_Tracker.md`, `.agents/Directional/CHANGELOG.md` — current task/accounting/history.

`M3-CP4c-2-DEFN` is planning only: no implementation/test/fixture/selector mutation, compile, or runtime.

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


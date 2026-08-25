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
5. **Delete staged patch after success** — only after the patch commit has pushed successfully, `agent-google-drive-reusable.yml` must delete that Google Drive patch using the same File ID and report whether deletion succeeded. If application/push fails, retain the Drive file and File ID for diagnosis/retry instead of deleting the only remote transport copy.
6. **Retire repository control state** — after result/log evidence and Drive deletion are verified, delete the temporary caller first, then retire its marker and any other temporary repository control files through the normal cleanup lifecycle. Do not leave turn-specific patch payloads or fragments under `.agents/Directional/turn-payloads/`.

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

## Mandatory next turn — `M3-CP4c-0-CB2` — EXACT NEXT / Code + Build, measures E0–E10

`M3-CP4c-0-TB-REVIEW-PLAN` is **COMPLETE**. Its record is
`Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`, and it is the document to read first.

**Read this before touching anything.** The adjudicated root cause is *not* T6 and *not* Q8; both are
correct as frozen and **neither may be weakened**. A1 decides the **sign of a barycentric direction
coordinate** with a `double` tolerance (`kBranchTopologyTolerance = 1e-10`) in three separate places and
publishes those verdicts as topological ownership — carrier-set membership and vertex-sector membership
— while A2a's exact continuation rule re-decides the same sign exactly, on A1's own published datum.
Where they disagree, A1 hands A2a a state A2a is right to reject. The seam is proved algebraically in
review §4: in `direction_in_incident_vertex_sector`, `alpha = d[next]` and `beta = d[prev]` identically,
so `alpha > tol && beta >= -tol` **is** the exact entry predicate at `tol = 1e-10`.

Five amendments were issued to `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`; that file now opens
with an `AMENDED` banner and carries inline `SUPERSEDED` markers. **Read the banner before §4.**

The corrective series is **E0–E10** in review §10. Order matters: **E1 first** — it publishes loci that
already exist in the error struct and is what determines which of three candidate failure routes is
real. E2/E3 exactify A1's flow classification and vertex-sector rule and delete
`field_branch_world_direction`'s lossy round trip. E4/E5 close a T1 exhaustiveness hole and an entirely
unasserted cross-edge flow invariant. E6 replaces a position-blind cycle break that can publish a
spurious clean terminus. Review §7 proves that after E2–E5 T6 is **unreachable from any well-formed
production state**; §11 records six falsifiable predictions the CB/TB pair must confirm or refute.

**Standing prohibitions:** do not retune, widen, narrow, or delete `kBranchTopologyTolerance` — every
measure removes tolerance from topological decisions and none adds any. Do not edit the sphere fixture;
review §6 establishes fixture and oracle are both valid. No sphere-specific special case. Execute
nothing in CB. **Q8 is not creditable until E6 is in the package.**

E3's mandatory pre-check: it changes A1's `FieldSingularityPortAttachment` selection, which feeds the
atlas digest (`FieldTransportAtlas.cpp:1124-1127`). Enumerate every accepted identity asserting an atlas
digest and confirm each is relative, not an absolute constant. **An absolute-digest identity that must
change is a finding for review, not a CB edit.**

---

### TB evidence this review adjudicated — retained

`M3-CP4c-0-TB` is **COMPLETE / VALID RED**. Required semantic gate **328/328 PASS** but binding Q8 is
red, so the checkpoint does not close. Every digest below, both job ledgers, and the retry-0
characterization were re-verified against the GitHub API during review and **all matched exactly**.

Authoritative evidence: source `e784e44ce86e458b250b04689288f5f365ca507b`; immutable package
`9577900736` / `b9c597584177f31fd2d923b622a4b20fbb243c7bd007b37cced8ff128e349f31`; runtime run/job
`32891161394 / 97943220460`; result artifact `9579600371` /
`fe472587aba74c2face26a2f65c0706439232bec2e5cc594d81711a26773b399`; log artifact `9579600958` /
`7ddfe4c8e48b1b618c7a60ad6cf900a767ff954309a1c3cc52a8896306d98039`. Accepted prefix **316/316**
and CP4c-0 additions **12/12** pass.

Q8 is red because the prescribed sphere reaches A1 but A2a rejects `BranchContinuationDegenerateEntry`
at `sourceEdge=6-8`; no `FieldAlignedCurveNetwork` is published.

**Do not read `sourceVertex=0` / `singularity=0` as a locus.** They are the failing trace's **seed**,
back-filled at `SurfaceCellTracing.cpp:818-819` when the failure site leaves the field unset. The
failure is provably **not** the trace's first step (the start entry point is incident to vertex 0, and
edge `6-8` is not). Only `sourceEdge=6-8` is a genuine locus, and it alone cannot separate the three
candidate routes — an interior edge entry with a cross-face flow disagreement, the same with a
within-face tolerance disagreement, or a vertex entry after a mis-selected sector transit. The
discriminating datum is the exact entry parameter, which **was computed and then discarded** by
`append_network_error` in `tests/FieldAlignedCurveNetworkTests.cpp`. Measure E1 emits it.

**Context Load Plan for the successor:**

```yaml
load_next:
  - references/turns/CODE_BUILD.md
conditional_modules:
  - trigger: GitHub evidence/source inspection is required
    path: modules/github-connector/MODULE.md
  - trigger: authoring falsifying identities (measure E8)
    path: modules/unit-testing/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md
  - .agents/Directional/Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md
  - .agents/Directional/Architecture_M3_CP4c0_Artifact_Only_Test_Benchmark_Report.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - TODO.md
  - .agents/Directional/Future_Chat_Session_Handoff.md
  - .agents/Directional/LESSONS.md
source_of_record_for_the_measures:
  - src/authority/FieldTransportAtlas.cpp        # S1 flow classification :162-170; S2 port sector :546; sector rule :399-423
  - src/geometry/SurfaceCellTracing.cpp          # T6 :451-456; seed back-fill :818-819; T1 :482-493; transport :895-918; cycle guard :789-796, :905-911
  - include/directional/authority/FieldTransportAtlas.h   # is_barycentric :438; sector decl :514
  - tests/FieldAlignedCurveNetworkTests.cpp      # append_network_error — the dropped loci
do_not_preload:
  - sibling turn files
  - historical CP4c reports
  - CP4c-1 / CP4c-2 / CP4c-3 scope
```

## Current authority

### CP4c-0 TB — COMPLETE / VALID RED

- required gate **328/328 PASS** = accepted **316/316** + CP4c-0 **12/12**;
- binding Q8 **RED** at `field-aligned-network/BranchContinuationDegenerateEntry`, edge 6-8; network not
  published. (`singularity=0` / `sourceVertex=0` are the trace **seed**, not a locus — see above.)
- prohibited build/mutation flags all false;
- retry 0 `32890863928`: infrastructure-only before package verification/semantic runtime;
- retry 1 `32891161394`: authoritative; no further semantic retry;
- owning report: `Architecture_M3_CP4c0_Artifact_Only_Test_Benchmark_Report.md`;
- adjudicated by `Architecture_M3_CP4c0_TB_Review_Plan_Independent_Review.md`;
- exact next: `M3-CP4c-0-CB2`, Code + Build only, measures **E0–E10**.

### CP4c-0 CB1 provenance

- semantic source `e784e44ce86e458b250b04689288f5f365ca507b`;
- compile run/job `32886067534 / 97927044884`;
- immutable package `9577900736`; all eight standard targets compiled/linked; `runtimeExecution=false`;
- frozen selector **328 = 316 + 12**.

### Accepted runtime authority

Latest accepted runtime remains CP4ab **316/316**, run/job `32758293793 / 97530833220`. CP4c-0's
valid-red first-acceptance result does not supersede it because binding Q8 is red. Stable regression
accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 package count **40**.

## Standing product state

- M1 and M2 CLOSED / ACCEPTED; M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab accepted.
- CP4ab remains latest accepted runtime authority at **316/316**.
- CP4c-0 CB1 complete/build green; CP4c-0 TB complete/valid red: 328/328 identities pass, Q8 sphere
  reachability red at typed `BranchContinuationDegenerateEntry`.
- CP4c-0 remains OPEN/runtime-unaccepted. Independent review is **closed**; root cause adjudicated as
  A1's tolerant sign decisions feeding A2a's exact consumer. Corrective series **E0–E10** frozen for
  `M3-CP4c-0-CB2`; the CP4c-0 DEFN carries five normative amendments. T6 and Q8 unchanged.
- CP4c-1 remains OPEN/blocked; C4/C5 stay gating and 318 selector unchanged.
- CP4c-2 and CP4c-3 remain blocked and require their own `-DEFN` turns.
- Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **40**; `PR8-R042` remains resolved stable.
- Red TB routes through review/planning; attempt/diagnostic budgets remain abolished.

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


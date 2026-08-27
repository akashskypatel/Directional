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

## Mandatory next turn — `M3-CP4c-0-TB-R9`, then `M3-CP4c-0b-CB1` — CHECKPOINT SPLIT

`M3-CP4c-0` has been **split** by `M3-CP4c-0b-DEFN`. Read `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` first, then `Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md` for the evidence it consumes.

CP4c-0 was carrying two unrelated obligations under one gate: **how a trace continues** and **how a trace stops**. The first is finished and proved. The second was never scoped, was delegated to a citation whose assumptions do not hold here, and is what blocked TB-R8.

| | **CP4c-0** - continuation | **CP4c-0b** - termination |
|---|---|---|
| owns | exact minimum-ratio continuation, `FieldBoundaryPoint`, grazing classification and edge transit, vertex dispatch, the CB9 cost guards | trace/trace contact, arrival priority, the contact node and event, retirement of the CB9 stand-in guards |
| gate | **346**, `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, unchanged | frozen by `M3-CP4c-0b-CB1` as `346 + n` |
| Q8 | criteria **1, 4, 5** | criteria **2** and **3** |

**Amendment 11** moves Q8 criteria 2 and 3 to CP4c-0b **together and unweakened** - they are one piece of work, because the six circulating traces are simultaneously what blocks criterion 2 and what satisfies criterion 3. **CP4c-0 now closes on its own evidence; nothing green stays in limbo.** `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport`, made non-gating by CB9's N7, becomes gating again in CP4c-0b's selector rather than being a permanent exemption.

`DESIGN.md` §4.6 is amended: the motorcycle graph's termination guarantee assumes motorcycles walking edge chains of an existing quad mesh, where non-termination is impossible by counting. A2a is one stage earlier and admits limit cycles - one is exhibited on the sphere with an exactly contracting first-return map. Crash-on-contact still terminates it, but because the **perpendicular branch family** crosses it, not because the state space is finite.

### `M3-CP4c-0-TB-R9` - closes CP4c-0

Artifact-only Test + Benchmark on a fresh package, gate **346**, Q8 criteria 1, 4 and 5. Stop conditions in the CB9 record §8: accepted **316/316** byte-identical (a red here stops everything - N1 is the only change that could reject an accepted trace, and if it does the allowance is mis-calibrated and must be re-measured, never quietly raised); first-328 **328/328**; full gate **346/346**; **no process may exceed a small multiple of its historical time**; **no `C++ exception with description` anywhere in the log**. Independent of CB1 and does not block it.

### `M3-CP4c-0b-CB1` - the next CB target, measures **P0-P9**

Code + Build only; runtime forbidden; compile all eight standard targets.

- **Contact predicate (fixed, not a choice).** Proper transversal crossing of two segments in one face, exact rational barycentric arithmetic, same class as the continuation rule - **no new number type and no tolerance**. Tested against every segment already laid in that face by any trace **including the trace itself**. Shared singularity origins are excluded; endpoint touches and collinear overlaps are **typed observations, not contacts** (measured incidence on the sphere: zero).
- **Arrival priority: `ArcLengthFiltered`**, frozen as the production default. Double arc length with a **computed** forward error bound carried alongside the value. A literal epsilon anywhere in that path is a stop condition. Conclusive when `|L1 - L2| > B1 + B2`; **inconclusive or exactly tied arrivals both terminate at the crossing point**, which is canonical and needs no arbitrary tie-break.
- **Why ties matter more than they look:** the sphere's singularities are the eight corners of an inscribed cube, so exact ties are *systematic* on symmetric input, not rare. Arbitrary tie-breaks - port ID (vertex-numbering dependent), lexicographic world coordinates (frame dependent), branch index (meaningless across faces per Amendment 7), typed rejection (rejects symmetric models) - are all explicitly rejected.
- **Simultaneity:** global priority queue over pending arrivals. **Sequential tracing is not acceptable as the production algorithm** - it is `TraceSeniority` under another name.
- **Contact terminus:** the crossing point becomes a `NetworkNodeId` carrying a `TraceIntersection` event, crashing trace incident as `Terminal`, struck trace as `Interior`. **The struck trace is not split.** `FieldAlignedCandidateTrace` gains `terminalContact`, and exactly one of the three terminal kinds must be set on every completed trace.
- **N1/N2/N4 are demoted to backstops that must not fire.** An identity asserts this per witness. N1's allowance is calibrated on one witness and would trip on a mesh where a legitimate separatrix winds several times; it retires only when an identity proves no witness reaches it.

### Alternatives harness - required, and constrained

`FieldTraceArrivalPriority { ArcLengthFiltered, StepCount, BarycentricTime, TraceSeniority }` exists so performance and quality can be compared on future inputs. **`ArcLengthFiltered` is the only value the production entry path can produce.** The production path takes no priority argument; alternatives are reachable only from a separately named diagnostic entry point the pipeline never calls; an identity asserts production yields the default's result; and the selected priority is bound into the semantic digest. **A production-reachable priority argument is a second writer of network topology and a stop condition.** Changing the default is a plan update consuming a render comparison, not a code change.

### Operator prerequisite - outside the turn

**GMP is linkable in the current CMake configuration but is not fetched automatically on Linux.** It must be installed and its library root passed to CMake for link discovery. It makes every exact path substantially cheaper and would have prevented TB-R8's 853-second failure. **CB1 must record which backend the package was built against** (GMP or the fallback `BigInteger`), because it changes the cost profile of every P7 measurement and must not silently differ between CB and TB.

### Falsifiable predictions for `M3-CP4c-0b-TB`

1. Accepted **316/316** and CP4c-0 **346/346**, zero expectation edits.
2. The sphere publishes **24 traces** - Q8 criterion 2.
3. At least one terminal `TraceIntersection` - Q8 criterion 3. All six circulating traces have a crossing available at **step 0**.
4. **42 of 48 candidate ports still terminate at a singularity**; only the 6 circulating ones acquire a contact terminus.
5. **N1, N2 and N4 do not fire on any witness.** This is the one that matters - a guard firing after crash-on-contact exists means the termination contract is incomplete, and the turn returns to review rather than the allowance being raised.
6. Two-ring and fan acquire **no** contact terminus and their digests stay byte-identical.

## Current authority

### M3-CP4c-0 CB8 — current build authority

- semantic source / immutable package: `19ba8e9c5e58f9c33c14b309841165d3f0401db5 / 9628445643`;
- package ZIP SHA-256 `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`; source archive `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`;
- authoritative compile-only run/jobs: `33025705457 / 98366398970 / 98367264215`;
- compile log `9628446136 / 562bb275fccb61629a3a60bfd1f71c3cb8332a239674dab660ebcd1626f33d27`; preflight result `9628386576 / a9b66f29f9bb23927df9614066d43c7edaaeb70e5d1a01fd0551154d9a79778c`; preflight log `9628386953 / fb4ec9a4c041632cf7a3f5f14f0db9482b5c9c55b2c217654f42725c9872df90`;
- all eight standard targets compiled/linked; preflight/build exit 0; all source-status snapshots empty; recursive package hashes verified;
- `runtimeExecution=false`; no Directional runtime/test/benchmark/discovery/CLI/fuzzer/custom input executed;
- L0–L9 only; no A1/A2b/T6/CP4c-1 selector/tolerance/threshold/magnitude change;
- CP4c-0 selector **343** / `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`; first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` and first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600` preserved;
- exact next: artifact-only `M3-CP4c-0-TB-R8` on package `9628445643`.

### M3-CP4c-0 TB-R7 — COMPLETE / VALID SEMANTIC RED

- CB7 semantic source/package: `077462da156c3e2dfbbc6867fc10d3e4442d853c / 9625495708`;
- authoritative control/run/job: `3d1ef24d6bcccb7e4e821d713a21860bc0598bd0 / 33019554121 / 98346293968`;
- result `9626003625 / 61994abc1e67fc55bc1d48d38a521598b6b56e458972d948ebcae112fa27eaaa`;
- diagnostic log `9626004016 / 9f6307b90b93ba557af7643c5a2d4a021969708b2a77e74fc546ae4f263e441c`;
- mode-preserving extraction, 338/338 gate, 316/316 accepted prefix, 328/328 prior prefix, F3 2/2, postflight PASS;
- K1 near-tangency separation reproduced; K2 0/24 reaches grazing and is non-decisive; J3 legitimate 524/524; K3 176/176 complete fans / 0 mismatches;
- Q8 creditable RED criterion 2; no build/repair/mutation; exact next `M3-CP4c-0-DEFN-2`.

### M3-CP4c-0 CB7 — retained build authority

- semantic source / immutable package: `077462da156c3e2dfbbc6867fc10d3e4442d853c / 9625495708`;
- package ZIP SHA-256 `dc07d4288b9a529ca71c06f96e0277b168d2e5a28c5a9eeba3fdf7341a33237a`; source archive `6ecafbc5a5904568780e6518f39b9d4b1336c94e08a53f7fc0c31d8926e26344`;
- authoritative compile-only run/job: `33018117005 / 98341565781`;
- compile log `9625496280 / e42240c280738fd70e8eddc09bc9899537cac53f477e3d3f88d26f6b4a0a978f`;
- eight standard targets compiled/linked; preflight/build exit 0; all source-status snapshots empty;
- `runtimeExecution=false`; no Directional runtime/test/benchmark/discovery/CLI/fuzzer/custom input executed;
- K0–K7 diagnostic/contract-control only; no production semantics/fixture/selector/tolerance/T6/Q8 change.

### M3-CP4c-0 TB-R6 — COMPLETE / VALID SEMANTIC RED

- semantic source / immutable package: `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6 / 9619352525`;
- package ZIP SHA-256 `b45306c3c5b3b9ff094131be8073aed5c6180533fdbe0b04f220ca929b4dd672`; source archive `308e02580033b5a319e08d7916afc921693d2b15f645813c2cdbaed336320093`;
- authoritative control/run/job: `a9ae307590b0cc23080452c4a5013674efc48fc2 / 33006282429 / 98300813772`;
- result `9620769314 / fe6a73175399b764f7cbb3ea2963a8deb40d6d0b5afcc3e9a603102ee4936684`;
- diagnostic `9620770049 / ce87da5a919e31f7e36a8d904dfaad7c7d9c92b9bebf36a494de096e7cb691cb`;
- gate 338/338; accepted 316/316; first-328 328/328; F3 2/2; G5/H1/J3 PASS non-gating; Q8 creditable RED criterion 2; postflight PASS;
- H1 legitimate 388 directed / 194 distinct; J3 legitimate 524/524 geometry agreement; fan excluded 2/1 H1 and 1 J3 mismatch;
- no configure/compile/relink/repair/generated discovery/performance benchmark and no package/source/test/fixture/selector mutation.

A prior control run `33006048971 / 98300014224` is resolved orchestration-only evidence: Python ZIP extraction lost executable modes and the first binary launch failed with `PermissionError` before any Directional binary executed. The authoritative retry used normal `unzip` without package repair.

### M3-CP4c-0 CB6 — retained build authority

CB6 semantic source `8b8d189758d55d9f93ae595fbbe5d9fde0b4aee6`, compile-only run/job `33002848081 / 98288918300`, package `9619352525`, compile log `9619353059`. All eight standard targets compiled/linked with build/preflight exit 0, empty source-status snapshots, and `runtimeExecution=false`.

### Accepted runtime authority

Latest accepted runtime remains CP4ab **316/316**, run/job `32758293793 / 97530833220`. CB8 runtime semantics are not yet accepted; CP4c-0 remains OPEN pending TB-R8. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 package count **47**.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab accepted. CP4ab remains latest accepted runtime authority at **316/316**.
- **CP4c-0 is now scoped to continuation only** and closes on a green `M3-CP4c-0-TB-R9` at gate **346** against Q8 criteria 1, 4 and 5. Its contract is complete: DEFN froze the continuation rule, DEFN-2 froze the grazing model, CB8 implemented it, CB9 landed the deterministic cost guards and compiles.
- **`M3-CP4c-0b` is OPEN** and owns trace termination plus Q8 criteria 2 and 3. `M3-CP4c-0b-DEFN` is complete; `M3-CP4c-0b-CB1` under **P0–P9** is the next CB target.
- **`M3-CP4c0-TB-R8-CAND-01` transfers to CP4c-0b.** Six prescribed-sphere separatrices circulate; the CB9 guards bound the cost but do not make them terminate. It is resolved by a green CP4c-0b prediction 5, not before.
- `M3-CP4c0-DEFN2-CAND-01` remains open/non-stable — the K2 grazing-cost census walks traces with the retired Cartesian carrier lookup; owned by measure L8, no product impact.
- `M3-CP4c0-TB-R4-CAND-01` remains active/non-stable; the near-tangency regime is explained and defined, closable by the L2 census.
- `M3-CP4c0-TB-R6-CAND-01` is resolved orchestration/non-stable.
- CP4c-1 is now blocked on **CP4c-0b** rather than CP4c-0, and **no longer owns** re-homed Q8 criterion 3. CP4c-2/3 remain blocked for their own definition turns.
- Stable accounting **42 / 14 / 28**, debt **5**, M3 packages **47**.
- CP4c-0 gate **346**, SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; accepted first-316 and first-328 prefix hashes unchanged. CP4c-1's **318** selector unchanged.
- Exact next is **`M3-CP4c-0-TB-R9`**, then **`M3-CP4c-0b-CB1`**. The two are independent.

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


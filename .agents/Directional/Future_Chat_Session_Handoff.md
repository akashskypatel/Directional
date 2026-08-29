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

## Mandatory next turn — `M3-CP4c-2-DEFN-R2` — trace-crossed non-cellular cut completeness definition

`M3-CP4c-2-CB6` is **STOPPED AT A FROZEN DEFINITION TRIGGER**. Its first required measure, **AF1**, read retained
result artifact `9721564203` without new runtime and extracted the prescribed-sphere independent actual-graph row:

```text
witness=prescribed-sphere ; complex=actualEmbeddedGraph
V=18 ; E=30 ; F=18 ; c=1 ; chi=6 ; sourceChi=2 ; excludedBoundaryOrbits=0
producerStatus=error ; producerError=CellularityNotEstablished
```

**AF1 adjudication: the standing prediction “the sphere's network is already cellular pre-cut” is REFUTED.**
The independent oracle's actual embedded graph does not satisfy the source Euler identity. This does not convert the
producer's earlier collapsed `CellularityNotEstablished` into a cellularity verdict; AF0 still has not printed the
originating upstream typed code.

The AF1 result activates the explicit `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` §8.3 rule. DEFN-R1
proves cut completeness only for the trace-free case, leaves trace-crossed non-disc completeness unproved in §8.2,
and states that **if the sphere is non-cellular, §8.2 becomes live and CP4c-2 must return to definition**. The
sphere has 24 retained traces and AF1 now proves it non-cellular pre-cut. CB6 therefore stopped before any source
edit, compile, package, or runtime. Full closeout: `Architecture_M3_CP4c2_CB6_Code_Build_Report.md`.

**Exact next: `M3-CP4c-2-DEFN-R2`, definition/planning only.** It must:

1. define a complete admissible cut strategy for the now-live trace-crossed non-cellular case, or a sound typed-stop
   contract, without subdividing immutable trace arcs or repairing regions after A2b;
2. preserve Amendments 12/13, single-writer A2a′ authority, and the actual embedded graph as the sole cellularity
   complex;
3. discharge **AF5** explicitly, per `SurfaceCutGraph.*` identity, by naming which identities gate CP4c-2 and why
   any exclusion is non-gating;
4. decide whether **AF0/AF2/AF3/AF4** remain valid unchanged or require reordering/rescoping after the definition;
5. make **no** selector, fixture, product/test/build change and run **no** compile, package, Directional runtime,
   357/358 gate, cumulative gate, or benchmark.

AF0/AF2/AF3/AF4 are **deferred, not completed**. AF6/AF7/AF8 are also deferred because no TB follows a CB that
stopped before implementation. AF9 was satisfied: no prohibited semantic or runtime action occurred.

`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`. Stable accounting remains
**44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **64**.

## `M3-CP4c-2-DEFN-R2` outcome — this is the current definition authority

DEFN-R2 answered the stop CB6 raised. It supersedes `…DEFN_R1…` **§6 case 2** and **§8** only; Amendment 13 and
DEFN-R1 §§4, 5, 7, 9 stand, as does Amendment 12.

**Amendment 14 (normative, `DESIGN.md` §7.2.1).** A source edge crossed by a trace at an interior point **is** an
admissible cut. DEFN-R1 had excluded it because promoting one "would subdivide the trace — mutating an immutable
upstream product". The premise is false about this codebase: `build_arcs` already emits one trace arc per network
event, already splits a mandatory source edge at a trace terminal, and the crossing point is already published
exactly as `segments[i].entryPoint` at a segment position the subdivision machinery keys on. Arcs are a derived
representation; nothing upstream is mutated either way. The admissible cut set is now **every source edge that is
not already a graph arc**.

**Completeness is proved, so CB6's stop is discharged.** The complement of the source 1-skeleton is the open
triangles, each a disc, and trace sub-arcs cut discs into discs, so `network ∪ (source 1-skeleton)` is a cellular
embedding: a sufficient cut set **always exists**, within `|E_source|` promotions. This is exactly what the sphere
needs — CB6 measured its pre-cut graph non-cellular (`chi=6` vs `sourceChi=2`) with 24 traces, the case DEFN-R1
§8.2 could not cover. DEFN-R1 §10 Option B loses its only trigger and is **withdrawn**, so the accepted path keeps
A2a′ wired in and keeps the detector that caught `PR8-R043`.
`NoAdmissibleCutForNonDiscComponent` is retired as an outcome — verified: no test consumes it — and replaced by
`CutSearchExhaustedBeforeCellularity` plus a **published** saturation last resort that must never fire silently.

**The one code gap:** at an edge-locus node `build_rotation_system` (`EmbeddedGraphTopology.cpp:833-935`) handles
`Mandatory` rays only at exactly degree three and requires everything else to be a `Trace`. A `Cut` ray there is an
unhandled shape, and a crossing node is two collinear `Cut` rays plus two `Trace` rays. Generalize the existing
four-sector model and `mandatory_ray_points_to_second_endpoint` (`:651`); a second ordering routine is prohibited.

**CP4c-2 gate — selector 361, frozen (AF5 discharged).**
`.agents/Directional/Architecture_M3_CP4c2_Required_Green_Selector_361.txt`, whole-file SHA-256
`61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`. All four `SurfaceCutGraph.*` identities are
gating, two of them red pending AF3/AF4. 357 superseded, 358 withdrawn (its sole addition binds the out-of-scope
mechanical witness); **both files retained**. `head -355` and `head -357` reproduce the accepted-355 and
candidate-357 hashes exactly, so `first_red_ordinal` stays comparable across the arc. Criterion **C3** is split: a
torus-only identity is created and gated, the mechanical half moves to CP4c-3. `selected_gate=NONE`,
`gate_execution_authorized=false` — freezing bytes is not selecting. **AF7 is discharged**: 358 is withdrawn rather
than probed, so no probe is owed.

## Mandatory next turn — `M3-CP4c-2-CB7` — implement Amendment 14

CB6 stopped before AF0/AF2/AF3/AF4 and those measures are **deferred, not completed**; DEFN-R2 has now cleared the
definition stop that blocked them. CB7 carries the deferred AF work **and** AG1–AG6:

- **AF0** carry the originating `GlobalTopologyPlanErrorCode` through `topology_error` and print it. Additive only:
  no re-map of the switch, no new enum value — 355 accepted identities depend on the current mapping. **This is
  still the prerequisite for any sphere product fix**; do not propose one from an inferred code.
- **AF2** repair the D2 localization harness — rename `cp4c_producer_rederivation` (it models the withdrawn proxy),
  drop the stale `419-`/`437-`/`474-` line-number labels, and delete or redefine `localizationConsistent`.
- **AF3** rebuild `SemanticDigestIgnoresGaugeRelabelingForTorusWitness` on the production `torus.rawfield`
  authority and print `field_atlas_build_error_code_name(...)` instead of `ASSERT_TRUE`.
- **AF4** give `IsInvariantToSourceFaceAndEdgeEnumeration` the same treatment and settle measure **AD3** with it.
- **AG1** land DEFN-R2 §§4.1-4.5 as **one** conversion — edge-interior synthetic nodes keyed
  `(SourceEdgeTopologyKey, TraceId, segment position)`, exact ordering along the promoted edge, trace-arc
  subdivision at crossings, the rotation extension, and removal of the proposal filter that excludes trace-crossed
  edges. A partial conversion is the defect this checkpoint has already corrected twice.
- **AG2** the degree-four edge-locus rotation, by generalization not duplication.
- **AG3** publish the completeness theorem's two conditions and the edge-orientation convention with derivations.
- **AG4** the error-code split and published saturation.
- **AG5** construct a witness that actually promotes a trace-crossed edge, asserting its precondition at runtime in
  the CP3a style. The sphere may become such a witness once AF0/AG1 land, but it is blocked behind a producer fix,
  so a constructed witness is still required — without one the amendment could ship unexecuted.
- **AG6** extend the independent oracle to reconstruct crossing nodes by its own construction.
- **AG7** append the four new identities named in DEFN-R2 §7.4 to selector 361, producing gate **365**, and record
  its hash with the 355/357/361 prefixes re-verified.

**AG8's merge condition is now moot in one direction:** CB6 never printed the code, so if AF0's output localizes
the sphere's `RotationSystemInconsistent` to the edge-locus branch, AG2 and that fix are the same work. **AG9**
carries the prohibitions: no tolerance anywhere in the crossing path, no geometric inference of a crossing, no
publishing a crossing node back into the network, no second ordering routine, no relaxing `proves_cellularity()`,
no gate selection or execution, no benchmark, and GMP/GMPXX linkage per `GMP_COMPILE_POLICY.md`.

The TB after CB7 carries **AF6** (run every identity in the frozen non-gating selector or justify each skip per
identity) and **AF8** (regression bookkeeping).


## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are **CLOSED / ACCEPTED**.
- CP4c-2 CB5 remains build-green at `755485865a7cf9c485d754f22b82a41ee151824b`; inherited accepted authority is
  freshly re-proved **355/355** on package `9719216316`. **CP4c-2 itself remains unaccepted.**
- R7 remains the latest semantic runtime. CB6 executed no new runtime and produced no build artifact.
- **CB6 AF1 independently proved the prescribed sphere's pre-cut actual embedded graph non-cellular**
  (`V=18, E=30, F=18, c=1, chi=6, sourceChi=2`, `excludedBoundaryOrbits=0`, `complex=actualEmbeddedGraph`). The
  standing prediction is **REFUTED**. DEFN-R2 then discharged the §8.3 stop this triggered.
- The live producer still fails earlier through the collapsed upstream-error path — `topology_error`'s `default:`
  bucket for 36 codes, almost certainly `RotationSystemInconsistent`. AF0 has not printed the originating code and
  **no error-path product fix is authorized** until it does. This is separate from, and additional to, the
  non-cellularity above.
- Open candidates: `M3-CP4c2-TB-X2-CAND-04` (sphere producer error path), `R7-CAND-01` (torus diagnostic witness),
  `R7-CAND-03` (D2 harness domain conflation), and live measure **AD3**. `R7-CAND-04` is **resolved** by DEFN-R2.
- **Amendment 14 is defined and entirely unbuilt.** Its one code gap is the degree-four edge-locus rotation; AG5's
  constructed witness is what keeps it from shipping unexecuted.
- CP4c-2's gate is **selector 361**, frozen and unselected.
- Stable accounting **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative M3
  packages **64**.
- **Exact next is `M3-CP4c-2-DEFN-R2`.**

## Context Load Plan

`load_next`:
- turn-based-coding-agent `references/turns/REVIEW.md` — planning-only boundary for `M3-CP4c-2-DEFN-R2`

`conditional_modules`:
- engineering-guidelines module for definition/corrective planning
- GitHub connector module only if remote repository/control-plane operations are required

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — **read first**; durable cold-start substance, current as of DEFN-R2.
   §6 (cut admissibility) and §7 item 1 (the sphere) are the two facts that reframe the checkpoint.
1. `.agents/Directional/Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` — the authorizing definition:
   Amendment 14, the completeness theorem, the AF5 gate decision, measures **AG0–AG9**.
2. `.agents/Directional/Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` — Amendment 13 and the normative
   complex. **Its §6 case 2 and §8 are superseded** — never read it without DEFN-R2.
3. `.agents/Directional/Architecture_M3_CP4c2_CB6_Code_Build_Report.md` — the AF1 oracle row and the frozen-stop
   reasoning, plus the exact disposition of every deferred measure.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` — `CAND-04`, `R7-CAND-01`, `R7-CAND-03`, resolved
   `R7-CAND-04`, live measure `AD3`, and the closed `PR8-R043` / `PR8-R044` / `R7-ORCH-01` entries.
5. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md` — immutable R7
   runtime/artifact provenance.
6. `.agents/Directional/Architecture_M3_CP4c2_CB5_Code_Build_Report.md` — immutable package/build authority.
7. `TODO.md` / `CHANGELOG.md` — current task, run/artifact identities, and lessons adopted at R7-REV and DEFN-R2.

**This is definition/planning only.** It may revise frozen definitions/planning records but must not edit product,
test, fixture, selector, or build logic; must not compile; and must not execute Directional runtime, 357/358, a
cumulative gate, or benchmarks. The purpose is to make the trace-crossed non-cellular case implementable or
explicitly fail-closed before another CB is authorized.

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


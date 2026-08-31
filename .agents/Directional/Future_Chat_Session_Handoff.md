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

## Mandatory next turn — `M3-CP4c-3-CB3` (Code + Build, runtime-free)

`M3-CP4c-3-TB2-REV` is **COMPLETE**: it accepted TB2's execution, confirmed **Amendment 15** effective at runtime, established the ordinal-366 cause and proved it pre-existing, declared **Amendment 16** (`DESIGN.md` §7.2.1), and issued **AN0–AN9**. Record: `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md`.

`M3-CP4c-3-TB2` is **COMPLETE / RED — VALID SEMANTIC FIRST-RED AT ORDINAL 366**. The authoritative report is `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Report.md`.

### Immutable authority retained

- semantic/evidence source: `005512f20ed56edc793f4d6505f3d2b4c2999c71`
- immutable GMP semantic package **69**: artifact `9742715856`, SHA-256 `2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`
- user-authorized fixture-only execution package **70**: artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`; package-69 binaries are byte-identical and the sibling `test-data` fixture payload is copied from the immutable packaged source
- packaged source archive SHA-256: `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`
- selector **373**: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`; all 355/357/361/365/367/370 prefixes remain byte-exact
- exact static target map: SHA-256 `f73ea05bb146a7e4a71329b5bd4344898c7fc643094be4858ea8a17ab075d740`, producer 227 / authority-kernel 30 / completion 75 / validation 41
- authoritative execution: R4 run `33355714664`; result artifact `9745109157`; log artifact `9745109337`
- postflight: package/source/selector/mapping unchanged; compile/relink/repair/generated-discovery/benchmark flags false

### TB2 measured evidence

The original package-69 attempt exposed `M3-CP4c3-TB2-ORCH-01`: the packaged producer fell back to its missing compile-time source root at ordinal 41. The user explicitly authorized an orchestration/fixture-only correction and same-turn re-execution. Package 70 materialized the exact immutable fixture tree at the sibling `test-data` location selected before the compile-time fallback and proved the semantic binaries unchanged. R1–R3 were orchestration-invalid preflight/mapping trials and carry no gate authority.

R4 passed immutable package/source/GMP/selector/static-mapping/fixture preflight and executed one exact selector identity per fresh process. Ordinals **1–365** each selected exactly once and exited 0. Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected exactly once and exited 1 with:

`InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`.

This is a **valid semantic first-red**. Ordinals **367–373** were not executed. `M3-CP4c3-TB2-ORCH-01` is resolved as non-stable orchestration debt; the new semantic observation is tracked as `M3-CP4c3-TB2-CAND-01`. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic packages **69**. CP4c-3 remains **OPEN**.

### What the review concluded — the successor's starting facts

- **Execution ACCEPTED, one qualification recorded.** Selector 373 was recomputed from committed bytes (373 lines, 373 unique identities) and **all six** predecessor prefixes reproduce exactly; the working tree is byte-identical to packaged source `005512f20…`. The package-70 substitution is accepted as *relocation of already-immutable bytes* — the fixture tree came out of the source archive whose digest matched — but `semanticBinariesUnchanged=true` is **self-reported** and the manifests (28 vs 55 entries) are not comparable line for line. Opened as `M3-CP4c3-TB2-REV-CAND-01`, owned by **AN2**.
- **Amendment 15 is confirmed effective at runtime.** The mechanical witness advanced past `IncompleteCycleBasis`, and ordinals **1–365** are green, so the cut regressed nothing in the accepted gate. CB2 implemented the endpoint rule better than the amendment specified: `make_local_region_mesh` flood-fills `star(v) ∖ B(R)` and creates one copy per component, so tips, branch and boundary vertices need no special case.
- **Ordinal 366 is the same architectural disagreement one consumer later.** `build_singularity_attachments` (`:597-618`) demands a branch transport on **every** radial edge of a fan that `ordered_incident_fan` (`:351-402`) builds from the **global** `sourceMesh.F` and **requires to close**, while `branchTransports` (`:304-342`, built at `:1827` from `adjacencies`) **excludes every barrier by construction**. Established by the same elimination as TB1: the failing radial edge is not `SourceBoundary` (closed domain) and not `NonTraversable` (one region over 300 faces), so it is `HardFeature`.
- **Pre-existing and unmasked, not a regression.** Call order is `build_branch_transports` `:1827` → cycle loop `:1865` → `build_singularity_attachments` `:2384`, and CB2's diff to that file begins at old line **842**, leaving all three untouched.
- **A degree-1 tip is not exempt:** its star is not split, but the ring walk still straddles the single barrier ray.
- **CB2 already holds the contradiction Amendment 16 forbids:** AM4 binds a barrier-incident singularity to a **slit boundary cycle** while the port derivation still demands a **closed transportable ring** for the same vertex.
- **Still unproved:** ordinals 367–373 never executed, so Amendment 15's three self-checks and AM1's barrier decomposition are unmeasured and every DEFN-R1 prediction is unverified.

### Exact scope of `M3-CP4c-3-CB3`

**Code + Build.** Authors semantics, compiles, packages. **Executes no Directional runtime**; no gate execution, no benchmark. GMP/GMPXX linkage mandatory.

1. **AN1 — publish before designing.** Route `MissingSingularityBranchTransport`'s four existing locus fields (radial `sourceEdge`, `sourceFace`, `sourceVertex`, `topologyRegion`) into the reported diagnostic, and do the same for **every** `FieldAtlasBuildErrorCode` the mechanical and sphere witnesses can reach — fixing one code per turn is what produced this turn. Publish the **barrier-incident singularity census**: how many prescribed singularities are incident to `B(R)`, each one's `d_B(v)`, whether it is a tip / interior arc vertex / branch vertex, how many copies its star splits into, and its index. Publish AM1's barrier decomposition (`n`, `m`, `c`, `χ(B)`, `∂`, tree-or-cycle per component), which CB2 computes and TB2 did not report.
2. **AN2** — publish the four per-binary SHA-256 from packages **69** and **70** side by side and state whether they match.
3. **AN3** — fix fixture resolution **in the package**: the compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` fallback (`tests/TestFixturePaths.h:51-64`, `cmake/DirectionalTests.cmake:307,377,409`) must stop being an authority — ship the tree at a package-relative root the binary probes, or fail closed with a typed error naming the roots tried. Report whether package **68** shipped a fixture tree.
4. **AN4** — **do not design the port correction until AN1 reports.** P1 (per-sector ports) and P2 (no ports; the slit boundary cycle absorbs the index, so **no traces start there**) differ in product-visible behaviour.
5. **AN5** — implement Amendment 16 for `build_singularity_attachments` and its fan construction; state which policy was taken **and which measured fact chose it**; resolve the AM4-versus-port contradiction.
6. **AN6** — carry ordinals 367–373 unchanged; **AL4 still forbids designing the sphere's fix**.
7. **AN7** — correct the next TB plan's rerun rule: the restart test is **"produced no semantic verdict"**, not "executed no Directional runtime".
8. **AN8** — audit by **assumption** (*"this code assumes the transport neighbourhood is fully traversable"*), not by symbol, and name at least one consumer that holds the assumption **without** touching the cut data structures.

## Context Load Plan

`load_next`:
- turn-based-coding-agent Code + Build guidance

Minimum successor context after the mandatory durable policy/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first.
1. `.agents/Directional/Architecture_M3_CP4c3_TB2_Independent_Review_Record.md` — **AN0–AN9**, Amendment 16, the established cause, and the P1/P2 policy question AN4 blocks.
2. `DESIGN.md` §7.2 / §7.2.1 — Amendments 12–16, normative.
3. `.agents/Directional/Architecture_M3_CP4c3_DEFN_R1_Frozen_Definitions.md` — Amendment 15 and AM0–AM9; still binding.
4. `.agents/Directional/Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Report.md` — the valid R4 first-red authority.
5. `.agents/Directional/Architecture_M3_CP4c3_CB2_Code_Build_Report.md` — package-69 build authority and the implementation boundary.
6. `.agents/Directional/GMP_COMPILE_POLICY.md` — mandatory before any Code + Build turn.
7. `.agents/Directional/Regression_Root_Cause_Tracker.md` — `M3-CP4c3-TB2-CAND-01`, reopened `M3-CP4c3-TB2-ORCH-01`, new `M3-CP4c3-TB2-REV-CAND-01`, and inherited candidates.
8. `TODO.md` / `CHANGELOG.md` / `M3_CP4c_Consolidated_Record.md` — current status and retained lineage.

Source CB3 will change or must audit: `src/authority/FieldTransportAtlas.cpp` — `build_branch_transports` (`:304-342`), `ordered_incident_fan` (`:351-402`), `build_singularity_attachments` (`:480-...`, the failing site `:597-618`), the bucket classification (`:1456-1491`), and `make_local_region_mesh`'s cut (`:857-1190`). Also `tests/TestFixturePaths.h:51-64` and `cmake/DirectionalTests.cmake:307,377,409` for AN3, and `tests/FieldAlignedCurveNetworkTests.cpp:5273-5288` for the discarded locus.

**This is CODE + BUILD.** It compiles and packages and **executes no Directional runtime**; a gate may not be run. A red TB after it routes to `REVIEW + PLAN` as usual.

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


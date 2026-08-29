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

## Mandatory next turn — `M3-CP4c-2-CB4` — actual embedded-graph certification, measures **AC0-AC9**

`M3-CP4c-2-DEFN-R1` is **COMPLETE / DEFINITION-ONLY**. Read
`Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` in full: §3 Amendment 13, §4 the representation to lift,
§5 the two conventions that decide correctness, §6 admissible cuts, §8 the completeness split, §11 AC0-AC9.

**The normative complex is the actual embedded graph** of `FieldAlignedCurveNetwork ∪ cutEdges`: vertices are
network nodes plus cut-created nodes, edges are network arcs plus cut arcs, faces are the **dart orbits** under
the node rotation system. **Nothing new is invented.** `GlobalTopologyArc`, `GlobalTopologyOrientedArc`,
`GlobalTopologyNodeRotation` and `walk_graph_faces(arcs, rotations)` already exist in A2b and already compute
exactly this. **AC1 lifts them into one shared pre-region authority consumed by both A2a' and A2b; a second
implementation is prohibited** — that is `LESSONS.md` 22e, and a second implementation is how this checkpoint
arrived here.

**Amendment 13 withdraws DEFN §5.4's whole-source-face construction guidance** as cellularity authority; the
source-edge-barrier partition survives only as a cut-*proposal* heuristic and diagnostic provenance, and every
publication of it must carry a field saying it is not a cellularity oracle. **§§5.1-5.3 and Amendment 12 remain
binding**, and §3's torus theorem stands.

**The R2 normative-complex ruling was the reviewer's and it was wrong**; its three grounds were each true and
collectively wrong. `PR8-R042` had already adjudicated the same question on the same witness and `LESSONS.md`
22d/22e recorded the answer. New lessons **22k** and **22m** — cite the architecture that settles a
representation, not the code path that exhibits the symptom; and self-consistency inside a named complex is
never evidence that the complex is the right one.

**Two conventions will decide correctness and must be derived, not guessed (§5).** The **exterior-orbit
exclusion** on a surface with boundary — the accepted two-ring walks 4 orbits, exactly one exterior, giving
`F = 3` — and the **disconnected-graph correction term**, because the torus's 48 arcs over 48 degree-2 nodes
form **4 components** and unqualified `V - E + F = chi` is false there before any cut is considered. Mistaking
that for non-cellularity would be right for the wrong reason.

**New frozen constraint (§6):** a cut is a source edge promoted to a graph arc, so **a source edge crossed by a
trace at an interior point is not an admissible cut** — promoting it would subdivide an immutable trace, which
Amendment 12 forbids.

**§8 splits completeness honestly.** Provable for trace-free non-disc components, which covers the torus
entirely since it has zero traces. **Not proved** for trace-crossed ones: **AC5** requires a typed
`NoAdmissibleCutForNonDiscComponent` stop with a component locus, and **AC7** makes hitting it a **return to
definition**, never a judgement call, a widened admissibility, or a partial cut set.

**On the accepted regression** `PR8-R043 / M3-CP4c2-R001` at ordinal 305: **Option A is frozen** — fix the
certificate, because the accepted identity is correctly detecting a real defect. Decoupling A2a' from the
accepted path is retained only as a contingency with the single trigger of §8.2 going live.

**Do not revert AA1.** R5 §9 proves the regression predates it; `SurfaceCutGraph.cpp` is unchanged across that
interval. AA8's "reverts AA1" clause was overbroad and is withdrawn: **prefix re-proof is a detection boundary,
not a blame boundary.**

Stable accounting **43 / 14 / 29**, produced-witness debt **5**, M3 packages **62**.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

### Superseded — the R5 regression as reported (retained for provenance)

`M3-CP4c-2-TB-X2-R5-REV` is **COMPLETE / REVIEW GREEN / ACCEPTED PRODUCT REGRESSION CONFIRMED / REPLAN REQUIRED**. Read `Architecture_M3_CP4c2_TB_X2_R5_Independent_Review_Record.md` in full before planning.

R5 run/job `33232106030 / 99046593525` on immutable GMP package `9708324052` proved accepted ordinals 1-304 and failed accepted ordinal 305 `GlobalTopologyPlan.DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph` first at `SurfaceCutGraph::make(...)=CellularityNotEstablished`. The missing postflight is an orchestration defect, not acceptance evidence; no downstream AA2/D1/D2/357/358 outcome may be inferred.

Independent review promotes the failure to stable **`PR8-R043 / M3-CP4c2-R001`**, `AUTHORITY_DOMAIN_CONFLATION / RP-01`, ACTIVE. CP4c-2 reintroduced a whole-source-face/source-edge-barrier proxy that CP4ab had already proved cannot represent actual embedded graph faces when traces cross source-face interiors. On the exact accepted two-ring, actual embedded graph authority is `V/E/F=9/11/3`, while the self-consistent proxy is `10/11/2`; current `SurfaceCutGraph` mixes network `V/E=9/11` with proxy `F=2`, yielding `0 != source χ 1` at the final certificate. A one-line Euler repair is forbidden because it would certify the wrong object.

The prior R2 review statement that `sourceEdgeBarrier` is the normative cellularity complex is **withdrawn**. R2-CAND-02 is now ACTIVE / TEST-AUTHORITY / WRONG SEMANTIC COMPLEX. The independent diagnostic must measure the same actual embedded graph/fragment complement as the product through a different mechanism. R4 AA2 is independently confirmed byte-identical (two 468-byte sphere records, SHA-256 `84f9ca015ab63093086981cbd29256526159329c64537dfb52fba9e89d9fd078`), while AA5 runtime publication and AA1 sphere snapshot retention remain pending because R5 never reached D1. AA1 is not causal and must not be reverted.

Stable accounting is **43 events / 14 categories / 29 recurrences**, produced-witness debt **5**, M3 packages **62**. `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

At the close of R5-REV the next turn was definition-only `M3-CP4c-2-DEFN-R1`; **that turn is complete** and AB0-AB9 are discharged. Exact next is **`M3-CP4c-2-CB4`** under AC0-AC9.

## M3-CP4c-2 frozen definition context — cut-graph authority for A2b, measures **X0-X9**

`M3-CP4c-2-DEFN` is **COMPLETE / DEFINITION-ONLY**. Read
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` in full before writing any code; §5 is the frozen contract,
§7 the measures, §8 the falsifiable predictions.

**R5-REV correction:** §5.4.1 now withdraws the whole-source-face/source-edge-barrier construction as cellularity authority pending DEFN-R1. §§5.1–5.3 remain binding; do not implement the stale §5.4 proxy guidance.

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

`M3-CP4c-2-DEFN-R1` and CB4 are now complete. DEFN-R1 supersedes the withdrawn source-edge-barrier cellularity
authority with the actual embedded graph, and CB4 compiles that correction plus its independent non-gating oracle.
No CP4c-2 runtime acceptance has followed CB4 yet. CP4c-3 remains blocked until CP4c-2 closure.

## Current authority

### M3-CP4c-2 CB4 — current build authority, runtime unaccepted

- status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**;
- semantic/test source: `cebc12082c6dbe4830095df08169797b7dab0c5c`;
- changed-owner prepackage run/job: `33250503297 / 99095246849` — PASS;
- prepackage result/log: `9714212919 / 9714213161`;
- fresh authoritative full compile run/job: `33250547011 / 99095357374` — PASS;
- immutable full package: `9714226920` /
  `sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`;
- full compile log: `9714227128` /
  `sha256:95c8272db296dc0f74e4d33b389cbf51305bd042590420974111d9f63afe31da`;
- packaged source archive: `3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`;
- manifest 28/28 PASS; all eight targets present; source clean; exact GMP/GMPXX authority;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`;
- implementation: shared actual-embedded-graph owner, actual-complex certification, disconnected/boundary
  conventions, exact admissible cuts, typed no-admissible-cut stop, converted consumers, independent non-gating
  actual-complex oracle, retained barrier diagnostic explicitly non-cellularity;
- selectors unchanged; `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`;
- report: `Architecture_M3_CP4c2_CB4_Code_Build_Report.md`;
- TB plan: `Architecture_M3_CP4c2_TB_X2_R6_Artifact_Only_Test_Benchmark_Plan.md`.

Earlier full-package run `33246515627` compiled the same semantic source but preceded a distinct changed-owner
prepackage compile, so it is retained only as non-authoritative mechanics evidence. The sequence above re-proves
the exact source in the required order.

CB4 supplies compile/package authority only. It does not prove 355 at runtime, adjudicate the new oracle, execute
D2, select 357/358, run the cumulative gate, accept CP4c-2, or begin CP4c-3.

### M3-CP4c-2 TB-X2-R5 — current reviewed runtime evidence

- EXEC run/job `33232106030 / 99046593525` on source/package `76d757aab0ce18df09ce2823302d2dc224965187 / 9708324052`;
- immutable/GMP/six-selector preflight PASS; AA8 ordinals 1-304 PASS, accepted ordinal 305 RED with initiating `CellularityNotEstablished`; 306-355 and all local diagnostics/gates unexecuted;
- result/log `9708817991 / 9708818239`, SHA-256 `bda50fcd…2556e8 / b9e150de…8c9688`; missing postflight retained under R5-ORCH-01 and not inferred;
- independent review **admitted the semantic red**, promoted `PR8-R043 / M3-CP4c2-R001`, and statically localized the accepted two-ring failure to the final mixed-complex certificate;
- current root cause: actual embedded network authority `9/11/3` was conflated with whole-source-face `sourceEdgeBarrier` proxy `10/11/2`;
- review record: `Architecture_M3_CP4c2_TB_X2_R5_Independent_Review_Record.md`;
- historical successor was `M3-CP4c-2-DEFN-R1`; that definition and CB4 are now complete; this subsection remains the latest reviewed runtime evidence only;
- `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`.

### M3-CP4c-2 TB-X2-R4 — current reviewed runtime evidence

- authoritative EXEC run/job: `33228460953 / 99036688477` on source/package `5ad711e5d4ced95f38e103b993139a6307ba2cee / 9707091209`;
- torus publishes network-only 48/48, `networkOnlyCellular=false`, a retained cut graph and a retained GlobalTopologyPlan, then fails downstream at tracing;
- prescribed sphere fails at `surface-cut-graph/CellularityNotEstablished`, but pre-CB3 snapshot placement made its already-built atlas/network invisible;
- two-ring publishes successfully/self-consistently;
- duplicate sphere Y1 text is conditionally admissible only if AA2 proves the two prior lines byte-identical;
- R4 independent review authorizes AA0-AA9 and no gate; `selected_r2_branch=NONE`; `selected_gate=NONE`;
- review record: `Architecture_M3_CP4c2_TB_X2_R4_Independent_Review_Record.md`.

### M3-CP4c-2 CB2-DIAG-R1 — superseded build authority, runtime unaccepted

- status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**;
- semantic/test source: `c552a5a4a318063cde2564c40773ec7edaf064f6`;
- final GMP compile run/job: `33220315294 / 99012815358`;
- immutable package: `9704935112` / `sha256:dcb96ce4e37b2bc58ef69f2146723624575c32c090429ba00e6612b07938133f`;
- compile log artifact: `9704935373` / `sha256:1fc2250c00dd57e8cbd6385bde11857bc92126dfddfdf969ba188a67709651c0`;
- packaged source archive: `e533669daa7ac0219bc6ca6bd7d72db2901af32937848c3f37f02b772345ae02`;
- exact arithmetic backend: GMP with both gmpxx and gmp linked; all eight required targets PASS; manifest verified; source-status snapshots empty; `runtimeExecution=false`;
- changed semantic source: only `tests/FieldAlignedCurveNetworkTests.cpp`;
- D1: `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable`, ordered torus -> prescribed sphere -> two-ring;
- D2: `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`;
- explicit rail authority: torus/sphere `pipeline-authoritative`, two-ring `atlas-derived`;
- D1 complex: `sourceEdgeBarrier`; publishes barrier V/E/F definitions/provenance and fail-closed `oracleSelfConsistent`;
- accepted/frozen selector hashes unchanged; `selected_r2_branch=NONE`; `selected_gate=NONE`;
- report: `Architecture_M3_CP4c2_CB2_DIAG_R1_Code_Build_Report.md`;
- exact TB plan: `Architecture_M3_CP4c2_TB_X2_R3_Artifact_Only_Test_Benchmark_Plan.md`.

R1 supplies compiled diagnostic authority only. It does not resolve CAND-01/CAND-02/CAND-04 or accept CP4c-2.

### M3-CP4c-2 CB2-DIAG — superseded diagnostic build authority, runtime control-invalid

- status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**;
- semantic/test source: `232ac459b13657529e064272a75c5583770a5963`;
- source apply run/job: `33212827595 / 98989820033`;
- authoritative GMP compile run/job: `33212932401 / 98990159075`;
- immutable package: `9702321260` / `sha256:05237f108a65c73df81b6b125d6fcecad10ad9b5af4104ecce3c6bb9f6642035`;
- compile log artifact: `9702321551` / `sha256:236458a4146ebec93638065a0f55500e8bb77dbf216d1d7b942f667be4070ab3`;
- packaged source archive: `986db8b91d06eab4284f3a0e49c1d8c9ad2676df61fdfdd4a94e56ba34a5644f`;
- exact arithmetic backend: GMP with both gmpxx and gmp linked; preflight/full build exit `0`; package manifest verified; source-status snapshots empty; `runtimeExecution=false`;
- changed source: only `tests/FieldAlignedCurveNetworkTests.cpp`, +1,396 / -0;
- D1 identity: `GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable`;
- D2 identity: `GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`;
- selector hashes unchanged: accepted 355 and prefixes 316/346/353; frozen 357 `b896d0db…64dc70`, frozen 358 `6eda3aad…4fbe62`;
- `selected_gate=NONE`; no runtime evidence from CB2-DIAG;
- report: `Architecture_M3_CP4c2_CB2_DIAG_Code_Build_Report.md`;
- exact TB plan: `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md`.

CB2-DIAG supplies compiled diagnostic authority only. The R2 runtime interpretation and control stop are recorded in the current subsection above.


### M3-CP4c-2 CB1 — preceding build authority, runtime unaccepted

- status: **COMPLETE / BUILD GREEN / RUNTIME-FREE**;
- semantic/test source: `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`;
- compile run: `33196876096`;
- changed-owner precompile job: `98936191472` — PASS;
- immutable full-package job: `98936799976` — PASS;
- immutable GMP package: `9696201700` /
  `af3ebe2efaab66fed70de8d954cb5615abd9428f401ea974dffe1e14577c8097`;
- packaged source archive:
  `8694f0fb85d101e3c5862e5a6a8a8a3ed241c723fd229eb44f83844b30321687`;
- compile result/log artifacts:
  precompile `9696170230 / 9696170581`, package `9696201700 / 9696202046`;
- exact arithmetic backend: GMP; gmpxx and gmp linked; build/preflight exit 0; all source-status snapshots empty;
- package manifest verified; all eight required targets present; `runtimeExecution=false`;
- accepted predecessor selector 355 and prefixes 316/346/353 unchanged;
- frozen X2 candidates: 357 / `b896d0db…64dc70`, 358 / `6eda3aad…4fbe62`;
- frozen X2 report-only selector: 1 / `88af227b…dafc8`;
- report: `Architecture_M3_CP4c2_CB1_Code_Build_Report.md`;
- TB plan: `Architecture_M3_CP4c2_TB_Artifact_Only_Test_Benchmark_Plan.md`.

CB1 supplies compiled evidence only. It does **not** choose the 357/358 runtime gate and does not accept CP4c-2.

### M3-CP4c-2 TB-X2-EXEC — raw runtime evidence (reviewed below)

- status: **COMPLETE / RAW EVIDENCE PRESERVED / NO GATE DECISION**;
- authoritative run/job: `33199227974 / 98944212158`;
- immutable GMP package/source: `9696201700` /
  `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`;
- selected X2 identities: **1**, report publications: **1**, process exit: **1** as permitted for this report-only diagnostic;
- immutable preflight/postflight: PASS; configure/compile/relink/repair/generated-discovery/mutation all false;
- result/log artifacts: `9697052371 / 9697052810`;
- result/log digests:
  `524534f76d99500c91e921d81d9d38bc6f8607f379500cd976d0c9fa8600f22b /
  916fa2478d9bd3fc5ba42e3dd670c7373ed3e26a6fcc721a733063da42161719`;
- raw publication is retained verbatim in
  `Architecture_M3_CP4c2_TB_X2_EXEC_Artifact_Only_Evidence.md`;
- two preceding orchestration-only controls are recorded/resolved in the regression tracker; stable totals stay
  **42 / 14 / 28**.

This EXEC subturn does not interpret the X2 publication and does not choose 357 versus 358.

### M3-CP4c-2 TB-X2-REV — evidence fits neither frozen branch

- status: **COMPLETE / STOP / NO GATE SELECTED**;
- review record: `Architecture_M3_CP4c2_TB_X2_Review_Record.md`;
- frozen 357 predicate: **NOT ESTABLISHED** — no independent network-only cellularity proof and no
  post-certificate `RotationSystemInconsistent` observation;
- frozen 358 predicate: **NOT ESTABLISHED** — `CellularityNotEstablished` was observed, but causality and
  post-certificate disappearance of `RotationSystemInconsistent` were not measured;
- static re-derivation: the X2 observer emits `networkAlreadyCellular` only after successful cut-graph creation,
  defines it as an empty cut set, and returns before `GlobalTopologyPlan::make` when cut-graph production fails;
- exact-site requirement: unmet by the current publication because multiple product return sites share
  `CellularityNotEstablished` and the report does not serialize enough localization to distinguish them;
- `selected_gate=NONE`; `M3-CP4c-2-TB-GATE-EXEC` is **not authorized**;
- `M3-CP4c2-TB-X2-CAND-03` is resolved test-authority/measurement-incomplete/non-stable;
- `M3-CP4c2-TB-X2-CAND-04` tracks the real but unlocalized prescribed-sphere `SurfaceCutGraph` product failure;
- stable accounting remains **42 / 14 / 28**, debt **5**, packages **58**.

### Accepted runtime predecessor

`M3-CP4c-1-TB-R5` remains the current accepted runtime authority at **355/355**, run/job
`33161644741 / 98817323175`, immutable GMP package `9675666067`, semantic/test source
`b1ce8ad65952bd2bd76238f6dfc55523f6a24747`. No CP4c-2 build result changes that accepted runtime authority.

## Standing product state

- M1/M2 and M3 CP1, CP2, CP2b, CP3a, CP3b, CP4ab, CP4c-0, CP4c-0b, and CP4c-1 are **CLOSED / ACCEPTED**.
- CP4c-2 DEFN-R1 and CB4 are complete; CP4c-2 remains runtime-unaccepted.
- Accepted runtime predecessor remains CP4c-1 TB-R5 **355/355**.
- Current build/package authority is source `cebc12082c6dbe4830095df08169797b7dab0c5c` / GMP package `9714226920`.
- CB4 implements AC0–AC9 and compiles the independent actual-complex oracle; runtime predictions remain unadjudicated.
- `PR8-R043 / M3-CP4c2-R001` remains active pending R6 and independent review.
- `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`; 357/358/cumulative gate remain blocked.
- Stable accounting is **43 events / 14 categories / 29 recurrences**; produced-witness debt **5**; authoritative M3 packages **63**.
- **Exact next is `M3-CP4c-2-TB-X2-R6-EXEC`**, artifact-only on package `9714226920`.
- R6-EXEC must stop at independent `M3-CP4c-2-TB-X2-R6-REV`; CP4c-3 remains blocked.

## Context Load Plan

`load_next`:
- turn-based-coding-agent `references/turns/TB-EXEC.md`

Minimum successor context after the mandatory durable policy/start checklist:

1. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R6_Artifact_Only_Test_Benchmark_Plan.md` — executable R6 authority.
2. `.agents/Directional/Architecture_M3_CP4c2_CB4_Code_Build_Report.md` — source/package/build evidence and AC0–AC9 summary.
3. immutable package `9714226920` from source `cebc12082c6dbe4830095df08169797b7dab0c5c`; do not rebuild.
4. `.agents/Directional/Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` — §§5, 6, 8, 9 and predictions.
5. `.agents/Directional/Regression_Root_Cause_Tracker.md` — `PR8-R043 / M3-CP4c2-R001`, `R5-ORCH-01`, and remaining candidates.
6. 316/346/353/355 and frozen 357/358 selectors for byte/hash verification only; 357/358 are not runtime-authorized.
7. `TODO.md` / `CHANGELOG.md` — current state/accounting.

R6-EXEC is artifact-only. Do not configure, compile, relink, mutate product/tests/fixtures/selectors, run generated
discovery/list/help/version commands, run benchmarks, execute 357/358/cumulative gate, or begin CP4c-3. Postflight
is unconditional even after semantic red. After raw evidence and required tracker updates are durable, stop at
independent `M3-CP4c-2-TB-X2-R6-REV`.

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


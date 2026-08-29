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

## Mandatory next turn — `M3-CP4c-2-CB2-DIAG-R2` — consume published products, measures **Z10-Z19**

`M3-CP4c-2-TB-X2-R3-REV` is **COMPLETE / REVIEW GREEN**. Read
`Architecture_M3_CP4c2_TB_X2_R3_Independent_Review_Record.md` in full: §2 the root cause, §3 the gating defect,
§6 measures Z10-Z19, §7 predictions.

**Root cause, localized — test-side with high confidence.** `cp4c_build_rail_authority` under
`PipelineAuthoritative` diverges from production in two demonstrable ways. **A - the cross field:** the fixture
computes `finalize_surface_cell_raw_cross_field(mesh, raw)`, while production and the working observer
`observe_cp4c_witness` use the pipeline's published `products.crossField`. **B - the hard-feature edge set:**
the fixture recomputes it from a locally built feature map, while the working observer passes
`tracingOptions.hardFeatureEdges` from the pipeline. **The torus is the one witness whose rails originate in
the feature map**, so it is the one witness where that set is non-empty and the divergence can bite.
Divergences C and D remain plausible and unmeasured: production builds over `meshWhole` and via
`build_source_topology_regions` with `sourceFaceComponents`/`sourceFaceSheets` populated, while the fixture uses
the raw loaded OBJ and bare `make_source_authority`.

**Why test-side:** production reaches A2a on the torus — that is where the frozen `48/48` came from — so its
atlas construction succeeds. A reconstruction that fails where the original succeeds is a reconstruction defect.
**Z12 requires this confirmed by publication, not assumed:** if the pipeline's own torus atlas is also
unavailable, the classification flips to a product finding and the frozen theorem is re-adjudicated.

**Structural cause — a third idiom for one job.** `cp4c_production_fixture` consumes `products.*` and is
faithful; `observe_cp4c_witness` rebuilds but from pipeline inputs and works on the torus;
`cp4c_network_only_fixture` rebuilds field, feature map, rails and atlas locally and fails. Each new idiom has
introduced a defect — its first version used `rails_from_atlas` (R2 CAND-01), its second diverges on field and
feature map. **Fourth incident in one authority-divergence family.** Z4 fixed which authority is *named*;
**Z11** fixes how it is *obtained*: consume `productSnapshots` for loaded production witnesses and stop
reconstructing the pipeline.

**Critical detail, or Z11 fails immediately:** `cp4c_production_fixture` also requires
`products.surfaceCutGraph` and `products.globalTopologyPlan` and throws when absent — **the torus has neither**,
which is the whole open problem. Use a **relaxed variant** requiring only through `fieldAlignedCurveNetwork`.
**Do not weaken the strict `cp4c_production_fixture`**; accepted identities depend on its preconditions.

**The defect that cost R3 its evidence.** The D1 identity calls `ASSERT_TRUE` **inside** the witness loop and
the torus is element 0, so the identity ended after 14 ms with **zero** publications. The prescribed sphere —
the decision witness for Branch A and therefore for the 357/358 selector — was never measured despite nothing
being known to be wrong with it. **Third appearance of one anti-pattern:** X2 gated every publication behind
`SurfaceCutGraph::make`; `CellularityNotEstablished` collapsed three mechanisms behind one code with no locus;
now one witness suppresses all others. **Z13** requires one record per witness — including a typed failure
record — with a single assert after the loop; **Z17** makes per-witness publication unconditional.

**Also recorded:** the typed atlas error was flattened to the bare string `field-transport-atlas-unavailable`,
discarding `atlas.error().code`, when `append_atlas_error(...)` and `append_cp4c_atlas_failure_diagnosis(...)`
already exist in the same file. **Z14** forbids a bare string as evidence.

**Carry forward unchanged (Z16).** CB2-DIAG-R1 implemented Z2's named complex, Z3's self-consistency assertion,
Z4's explicit rail-authority argument with no default, Z5's no-encoded-answers rule and Z7's two-ring
re-derivation **correctly**. Do not re-litigate them.

**Unchanged:** the normative source-edge barrier complex; the frozen `48/48` theorem, untouched because R3 never
reached a torus network; R2 CAND-01/CAND-02 ACTIVE; **CAND-04 ACTIVE and unlocalized — D2 has never run on any
package**. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`. `src/`,
`include/`, `SurfaceCutGraph` and all selectors are frozen.

### Superseded — the R3 EXEC stop as reported (retained for provenance)

`M3-CP4c-2-TB-X2-R3-EXEC` is **COMPLETE / VALID DIAGNOSTIC SEMANTIC RED / PLANNED STOP** on immutable package
`9704935112` from source `c552a5a4a318063cde2564c40773ec7edaf064f6`. Authoritative runtime run/job
`33222551366 / 99019499929` passed immutable preflight, selected D1 exactly once, then exited `1` before any
`m3Cp4c2Y1` publication with the exact torus failure `witness=torus;error=field-transport-atlas-unavailable` at
`tests/FieldAlignedCurveNetworkTests.cpp:5946` (`fixture.network.has_value()` was false). D2 was correctly skipped
by the frozen stop rule. Package/source byte-and-mode postflight matched preflight exactly.

Raw evidence: `Architecture_M3_CP4c2_TB_X2_R3_EXEC_Artifact_Only_Evidence.md`; result artifact `9705692837` /
`sha256:ba989d0ddd3bd244f03c8242060ded9f9c58b33679893ab0ddf1cc5fb8d015f5`; log artifact `9705693025` /
`sha256:ab653c13ec7b0eec30f2736a17bbf44406afa7c828cb1fddbadea795aa6701a6`.

Because the stop occurred before the first torus publication, R3 EXEC did **not** adjudicate Z6's 48/48 control,
Z3 all-witness self-consistency, D2 localization, or Y5. `M3-CP4c2-TB-X2-R2-CAND-01` and `...CAND-02` remain
active; `M3-CP4c2-TB-X2-CAND-04` remains active/unlocalized. New non-stable
`M3-CP4c2-TB-X2-R3-CAND-01` records the diagnostic precondition failure; its exact cause is intentionally left to
REV rather than inferred from EXEC.

At the close of R3-EXEC the next turn was the evidence-only review named above; **that review is complete.**
The superseded text below consumed the preserved evidence only and ran no new Directional
runtime. Do not rerun unchanged D1, do not execute D2, selector 355/357/358, cumulative gate, CB3, mechanical/C2,
or CP4c-3 before the evidence review adjudicates this stop.

`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`. Stable accounting remains
**42 / 14 / 28**, produced-witness debt **5**, M3 packages **60**.

## M3-CP4c-2 frozen definition context — cut-graph authority for A2b, measures **X0-X9**

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

`M3-CP4c-2-DEFN`, CB1, TB-X2-EXEC, and TB-X2-REV are complete. The X2 review did **not** choose a gate: the
preserved evidence fits neither frozen branch because network-only cellularity was not independently measured and
the observation stopped at `SurfaceCutGraph::CellularityNotEstablished` before post-certificate A2b behavior.
CP4c-3 remains blocked until CP4c-2 closure.

## Current authority

### M3-CP4c-2 TB-X2-R2 — current runtime evidence, control-invalid

- status: **COMPLETE / PLANNED Y4 CONTROL STOP / NO BRANCH SELECTED**;
- evidence source/package: `232ac459b13657529e064272a75c5583770a5963 / 9702321260`;
- runtime run/job: `33215632118 / 98998526420`;
- result/log artifacts: `9703233161 / 9703233545`;
- result/log digests: `6b13e0bcddc3ffeba93077b6b1115bc8a400b9b9a6051d83df01ac11bec191f7 /
  19975ef0fc0e154e02326827287fd60a3a7813b10cda1fe20840e60a072d3c1b`;
- D1: one selected process, exit 0, three Y1 publications, zero `SurfaceCutGraph` calls;
- Y4: **FAIL** — torus `V/E=0/0`, required `48/48`; source chi 0 and non-cellular agree only qualitatively;
- D2/Y2/Y3: **NOT RUN / UNAVAILABLE** under the binding stop rule;
- Y5: `selected_r2_branch=NONE`;
- gate: `selected_gate=NONE`, `gate_execution_authorized=false`;
- report: `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Report.md`;
- next review plan: `Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Plan.md`.

### M3-CP4c-2 CB2-DIAG-R1 — current build authority, runtime unaccepted

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
- CP4c-2 DEFN, CB1, old X2 EXEC+REV+PLAN, CB2-DIAG, TB-X2-R2, R2 independent review, and **CB2-DIAG-R1** are complete.
- Accepted runtime predecessor remains CP4c-1 TB-R5 **355/355**. CB2-DIAG-R1 is compile evidence only.
- Current corrected build authority is `c552a5a4a318063cde2564c40773ec7edaf064f6` / package `9704935112`; R3 EXEC ran corrected D1 once but stopped before its first publication with `field-transport-atlas-unavailable`; D2 did not run.
- `M3-CP4c2-TB-X2-R2-CAND-01` and `...CAND-02` remain active because R3 D1 produced no publication; `M3-CP4c2-TB-X2-CAND-04` remains active/unlocalized because D2 was correctly skipped; `M3-CP4c2-TB-X2-R3-CAND-01` records the new pre-publication diagnostic stop pending REV.
- `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false`; cumulative CP4c-2 gate runtime has not begun. Frozen candidates remain 357 / `b896d0db…64dc70` and 358 / `6eda3aad…b64fbe62`.
- Stable regression accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt **5**; M3 packages **60**.
- **Exact next is `M3-CP4c-2-CB2-DIAG-R2`**, Code + Build, runtime-free, test/diagnostic source only under measures Z10-Z19.
- CP4c-3 remains blocked on CP4c-2 closure.

## Context Load Plan

`load_next`:
- turn-based-coding-agent `references/turns/CB.md`; `GMP_COMPILE_POLICY.md` is a mandatory read per start-checklist step 5

Minimum successor context after the mandatory durable policy/start checklist:

1. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R3_Independent_Review_Record.md` — **the authorizing record**; §2 root cause, §3 gating defect, §6 measures Z10-Z19.
2. `tests/FieldAlignedCurveNetworkTests.cpp` — the three witness idioms side by side: `cp4c_production_fixture` (~4425, faithful, but demands cut graph + plan), `observe_cp4c_witness` (~3957-3991, rebuilds from pipeline inputs, works on the torus), `cp4c_network_only_fixture` + `cp4c_build_rail_authority` (the failing reconstruction), and the D1 identity at ~5933-5957 whose in-loop `ASSERT_TRUE` Z13 removes.
3. `src/pipeline/RemeshPipeline.cpp:6560-6590` — production's own atlas construction, for comparison only.
4. `.agents/Directional/Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Record.md` — the normative source-edge barrier complex (§5) and Z0-Z9, which Z16 carries forward.
5. `.agents/Directional/Architecture_M3_CP4c2_CB2_DIAG_R1_Code_Build_Report.md` — what R1 implemented and its exact source/package.
6. `.agents/Directional/Regression_Root_Cause_Tracker.md` — R2 CAND-01/CAND-02, R3 CAND-01/CAND-02, X2 CAND-04.
7. `TODO.md` / `CHANGELOG.md` — current state and durable accounting.

Do not preload unrelated historical reports. Do not touch `src/`, `include/`, or `SurfaceCutGraph`; do not run selector 355/357/358; do not start CB3; do not execute cumulative gate work.

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


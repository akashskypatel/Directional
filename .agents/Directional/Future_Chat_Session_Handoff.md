# Future Chat Session Handoff

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical blockers/lessons required to continue safely. Architecture belongs in `DESIGN.md` and `REORIENTATION_PLAN.md`; tasks belong in `TODO.md`; completed history belongs in `CHANGELOG.md`; exact review/runtime evidence belongs in the retained independent-review/report documents and regression tracker.

This section is durable. It may be corrected or extended, but it must not be deleted, collapsed into another section, or replaced by a summary without explicit user authorization.

## Durable handoff policy — DURABLE, DO NOT DELETE

At the end of every turn:

1. replace stale next-turn/status text instead of appending chronological narrative;
2. keep unresolved, current-authority, and immediately resume-critical facts in this handoff;
3. move completed history to `CHANGELOG.md` and exact evidence to the owning report/tracker without deleting durable lessons or policies;
4. never treat a documentation/control-plane commit as implementation, build, test, benchmark, or runtime evidence;
5. preserve the mandatory start/end checklists and all other sections explicitly marked durable;
6. preserve every section explicitly marked durable in **any** durable document. Durable sections must not be deleted, collapsed, renamed away, replaced by a summary, or stripped of durable meaning unless the user explicitly authorizes that destructive edit and its exact scope;
7. perform work directly on the configured working branch. Do **not** create temporary, control, side, or staging branches unless doing so is absolutely necessary to circumvent a concrete procedural blocker that cannot safely be resolved on the working branch. If an exception is unavoidable, record the blocker and why the branch is necessary, keep it narrowly scoped, remove/reset it as soon as the blocker clears, return to the configured working branch, then proceed to the next turn;
8. every Test + Benchmark turn must categorize **every observed regression** in `.agents/Directional/Regression_Root_Cause_Tracker.md` and record root-cause analysis before the turn closes. If evidence does not justify a stable regression ID/count change, create or update a candidate/non-stable record and explicitly state why historical stable totals do or do not change, then proceed to the next turn;
9. `.github/workflows/agent-compile-reusable.yml` owns one durable compiler-cache namespace/schema. Turn-specific callers must not invent cache epochs, cache namespaces, or unrelated per-turn compatibility keys. Restore must always use the durable compatible namespace so prior ccache entries are reusable across turns.
10. work units 2 and 3, plus the exact M1 full-authority partial edges tasklisted in `TODO.md`, have the user-authorized partial-CB cadence exception: only those exact `P-CB` → `P-CB` edges may omit an intervening TB. Every partial remains runtime-free and semantically unaccepted; the final packaging partial must advance to its TB before later milestone work starts.

Do not add transcripts, chronological tool history, copied superseded artifact tables, obsolete task selections, or generic procedure already owned by policy/skill files. Concision never authorizes deletion of durable information.

## Mandatory start-of-turn checklist — DURABLE, DO NOT DELETE

1. Review the turn-based-coding-agent skill if not already reviewed for the current work session.
2. Fully review this handoff, `RETENTION_POLICY.md`, `CLEAN_UP_POLICY.md`, and `GitHub_Workflow_Policy.md`.
3. Review `TODO.md` (including exact completed/current partial-CB status), `DESIGN.md`, `REORIENTATION_PLAN.md`, `M1_Closure_Record.md`, `M2_Closure_Record.md`, the active next-turn plan, and `Regression_Root_Cause_Tracker.md`.
4. Confirm the configured working branch, branch head, exact implementation/source authority, and requested turn type before any write.
5. Verify every explicitly durable section required by the documents being touched is present before editing; do not proceed with a destructive rewrite if a durable section would be removed.
6. For Code + Build workflow work, verify the reusable compile workflow still owns the durable cache namespace/schema and that the caller does not supply a per-turn cache epoch/key.
7. Inspect `.github/workflows`, `.agents/connector-triggers`, and `.agents/Directional/turn-payloads` for stale temporary state without deleting durable workflows or records.

## Mandatory next turn — `M3-CP2-TB` (Test + Benchmark)

**M3 CP2 Code + Build is complete; package 9 is frozen, but CP2 is NOT yet accepted.**
Exact semantic source/package candidate: `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692`. Mandatory external
pre-package compile `32279124852 / 96153441513` was green on the literal source. Cumulative
package 9 `32279806492 / 96155630834` compiled and packaged the identical source with
`runtimeExecution=false`; package outer SHA-256 is `6f8865a3d3c28ea803a40cc9929f22de5a1d313f4810541f6474bbfba9b8ef79` and log artifact
`9375453342` has outer SHA-256
`d764d49de46c109061b3ad9f5e31aeb98293c7fee358ab2690e063a87a676f12`. Exact evidence is
retained in `Architecture_M3_CP2_Code_Build_Report.md`.

M3 consumption is **9/12**. Exact next is immutable `M3-CP2-TB`, consuming package
`9375452692` without rebuild/relink/repair/source-test-fixture mutation or generated discovery.
Frozen acceptance is accepted CP1 **281/281** + CP2 **6/6** = **287/287**. Any red stops for
Review; package 10 / CP3a remains blocked until CP2 acceptance. Latest accepted runtime
authority remains CP1 `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` at **281/281**.
No runtime executed in CP2 Code + Build, so stable accounting remains **38 / 14 / 24** and
produced-witness debt **5**.

`tmp-lowlevel-test` was audited: tip `dd4141a5add457b6017e776acabe327674e56606` is an
ancestor of the working branch with zero unique file differences. It is disposable residue;
the available connector exposes no branch-delete operation.

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
PR: #8 open, draft, unmerged

## Current authority

### M3 CP2 package 9 immutable candidate — NOT YET ACCEPTED

Exact candidate `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692` is compile/package green through
`32279806492 / 96155630834` after mandatory pre-package `32279124852 / 96153441513` on the
identical source. M3 is **9/12**. CP2 still requires immutable **287/287** acceptance. Exact
Code + Build evidence is in `Architecture_M3_CP2_Code_Build_Report.md`.

### M3 CP1 accepted runtime authority

**Latest accepted semantic runtime authority is M3 CP1:** source/package
`9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046`, accepted by immutable TB-R3
`32263614534 / 96102598799` at **281/281**. Result `9369359878` /
`829f51e1510ba6aab2eb6f6eed716bd736dcd662b1932b05a6fe16d6223917fd`; log `9369360425` /
`b624982cd6f5479cd167124c3897725533c6ce460fb6ce96751dfcfcfb18572c`. Frozen selectors are
retained M2 **275** `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`, A1 **6**
`bd00fc5d7840b398b76d834a65fbd30ed400c8ec4a1dab54eeeb554c8ae587ea`, combined **281**
`c73403ab665770282a924dd4534ca261fbdb249d8b832d6644d6a868b452fa83`. Package and
materialized source postflight were unchanged; `repositoryCheckout=false`,
rebuild/relink/repair/mutation/discovery/benchmark flags all false. Exact evidence is retained
in `Architecture_M3_CP1_Artifact_Only_Test_Benchmark_Report.md`.

`PR8-R038 / M3-CP1-R001` is resolved stable/recurrence and `M3-CP1-TB-CAND-01` is resolved
non-stable. Historical stable totals remain **38 / 14 / 24** and produced-witness debt **5**.

### M3 post-CP1 planning authority

`Architecture_M3_Post_CP1_Allocation_And_CP2_Code_Build_Plan.md` is the active M3 planning
overlay and the single next-turn plan. It supersedes stale post-CP1 package/status text in the
older M3 plan and the M3-specific package/status text in `REORIENTATION_PLAN.md`. Necessary
facts from superseded CP0/CP1 per-turn reports/plans are preserved in the durable changelog,
regression tracker, this handoff, the current immutable CP1 report, and the active M3/CP2
plan; those stale per-turn current-head files were retired under the retention/cleanup policy.

### M3 CP1 package 6 runtime-rejected historical evidence

At TB-R2, package 6 exact source/package
`95006048225df765b5b9c31e235fed82330a1469 / 9354456191` failed immutable
`M3-CP1-TB-R2` `32226787294 / 95987961593` at **258/281**: A1 **3/6**, retained M2
**255/275**, M1 producer **118/138**. Result/log `9355788148 / 9355788629` SHA-256
`0aa97b371e0081c094791ed568117685e1c8cfe79b8488fe8c0b28d3e6dd00b8 /
9097f7f3859676c6130ab1dc1c8015beae909008af90c325cfcd673292b6040e`. Its earliest
production rejection was `CycleTransportMismatch`. Package 6 is historical rejected runtime
evidence, not a candidate for reuse or repair.

### Normative architecture

`.agents/Directional/DESIGN.md` remains authoritative. Pipeline B is the only scheduled product path. The "strict fixtures require D0" rule is enforceable from M7 onward, where dispositions are implemented; earlier milestones use the equivalent stated in their own gate. Open design/evidence items remain in `TODO.md` and `REORIENTATION_PLAN.md`.

### Immutable runtime authority

**Latest accepted semantic runtime authority is M3 CP1:** source/package
`9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046`, accepted by
`M3-CP1-TB-R3` `32263614534 / 96102598799` at required-green **281/281**. Result
`9369359878` / `829f51e1510ba6aab2eb6f6eed716bd736dcd662b1932b05a6fe16d6223917fd`; log
`9369360425` / `b624982cd6f5479cd167124c3897725533c6ce460fb6ce96751dfcfcfb18572c`.
Retained M2 remains **275/275** within this gate, while A1 is **6/6**. Combined selector
SHA-256 is `c73403ab665770282a924dd4534ca261fbdb249d8b832d6644d6a868b452fa83`. Package and
materialized packaged source were byte-identical before/after runtime, with no
rebuild/relink/repair/source-test-fixture mutation, generated discovery, or benchmark
execution.

### Accepted M2 authority

M2 closes the verified eight-product surface over typed closed outcomes with exactly one outcome authority per product. Product-shaped context observations are diagnostic-only; direct semantic context refs are zero; the CP3 forbidden-read family is zero. The accepted runtime gate preserves frozen M1 **234/234**, CP1 **5/5**, CP2 **34/34**, and CP4 **2/2**. This accepted source is retained inside the accepted M3 CP1 gate.

## Standing product state

- **M1 and M2 are complete. M3 CP1 is ACCEPTED.** Exact accepted source/package `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` passed immutable TB-R3 `32263614534 / 96102598799` at **281/281**.
- Latest accepted semantic runtime authority is M3 CP1 `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046`; retained M2 is preserved **275/275** inside the accepted gate.
- `PR8-R038 / M3-CP1-R001` is **RESOLVED STABLE / RECURRENCE** and `M3-CP1-TB-CAND-01` is **RESOLVED NON-STABLE**. Historical totals remain **38 / 14 / 24**; produced-witness debt remains **5**.
- `M3-CP2-CB` is compile/package green on `6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff / 9375452692`. M3 is **9/12**; package 10 / CP3a is blocked until immutable CP2 acceptance. There is no automatic retry or package 13.
- Exact next is immutable `M3-CP2-TB` on package `9375452692` at frozen **287/287**. CP3a/CP3b/CP4 remain blocked on accepted predecessors.
- Existing G4/M7/deferred-hygiene/product-gate obligations retain their prior ownership; Pipeline A remains unscheduled.

## Resume-critical lessons — DURABLE, DO NOT DELETE

- **Package ceilings are risk controls, not permission to merge semantic domains.** When the remaining independently testable domains exceed the accounting slots, preserve the architecture/cadence and make the smallest explicit allocation amendment; do not hide the conflict by merging checkpoints, moving acceptance work to a later milestone, or inventing an unapproved partial-CB edge.
- **Adding a typed product does not complete a cutover if production immediately projects it back into raw semantic arrays.** The new product becomes authority only when production consumers read the typed owner and the raw representation is reduced to a one-way legacy/test/diagnostic leaf.
- **A derivation is not closed merely because its algebra is internally consistent.** If a fixed-orientation producer and an independently source-derived oracle still reject the same valid baseline, reopen the mapping from mathematical symbols to repository edge, cycle, curvature, index, matching, effort, and sparse-support conventions before any further semantic edit.
- **Independent cycle verification must recreate the semantic basis from source authority, not merely recompute transport over product-published cycle support.** A source-derived oracle owns its own cycle support/orientation, curvature, matching/effort, and exact lift before comparing the published witness.
- **For A1, the signed `dual_cycles` row is the one orientation authority.** Order already-directed steps without reversing semantic orientation; never mutate the expected lift to make the comparison pass. The exact cycle index's `Z4` class is compared to the signed matching composition only after both are proven to use the same canonical semantic cycle support.
- **Representation storage is not semantic cycle support.** Sparse-sparse aggregation may retain explicit algebraic zeros. Canonicalize exact-zero incidence before any iterator-based curvature/support semantics, and keep downstream zero-skips defensive rather than letting different consumers see different cycles.
- **A1 cannot be bypassed in a CP1 acceptance package.** The hard gate amplifies an A1 bug, but `DESIGN.md` §7.5 requires A1 before topology planning. Restore retained predecessor green by making valid inputs satisfy A1, not by postponing the gate to CP2+.
- **Exhausting a sign search does not by itself prove the invariant false.** It proves the searched sign family did not fix the implementation. Re-check the full producer equations, representation normalization, and source-to-symbol mapping before changing architecture.
- **A semantic owner and an independent consistency checker are not duplicate authorities.** The accepted producer owns the exact index; a read-only checker may independently derive a relation and reject inconsistent publication without becoming a second writer. Authority duplication begins when both paths can publish/drive semantic state.
- **A planar fixture is not automatically vacuous.** Name the exact precondition being exercised. The planar square has zero geometric field transport but nontrivial boundary-cycle aggregation and therefore exposes stored-zero support/curvature inconsistency directly.
- **Check the fixture's geometry and topology against the invariant's content.** Before crediting or dismissing a fixture, name every quantity the invariant depends on and confirm which are intentionally zero/nonzero.
- **A check that adjusts its own expected value until it agrees is not a check.** Searching over sign conventions converts a falsifiable invariant into a tautology that only fails when every candidate fails.
- **Never publish a guessed value as authority.** If an expected lift is searched or altered to satisfy composition and then hashed into a certificate, the certificate attests to the search's outcome rather than a derived fact.
- **A producer that forces a relation and an oracle that reads the forced value back are self-consistent by construction.** Rule 7 can be violated by the pair even when the oracle appears to recompute something; check both sides for independence.
- **Do not make a new invariant a hard precondition of an accepted path until the invariant and its source mapping have a non-vacuous independent witness.** Once the architecture requires that precondition, acceptance must restore the witness rather than bypass the gate.
- **Stage-local cycle algebra may compute A1 proof payload, but representation storage is not semantic support and representation validity is not source-topology validity.** Normalize explicit sparse zeros before support checks, bind every published fact back to checked source authority, and represent trivial relative-boundary regions directly when a generic local mesh container cannot express them. `PCFaceTangentBundle`/`dual_cycles` remains a valid non-owning computational ingredient for nontrivial regions.
- **A package attempt must not be the first compile of new code.** M3-CP1 spent package allocations on ordinary test-compilation mistakes. A first-target preflight *inside* the packaging workflow only shortens the failing package; it does not satisfy this rule. Compile the exact changed owner target in a separate pre-package run on the same fixed semantic source SHA before an allocation-consuming package begins.
- **A green pre-package compile artifact is mechanics evidence, not a TB package.** Its target set is intentionally incomplete. Only the later complete approved-target package may become immutable TB input.
- **Pre-package and package compiles must name the same fixed semantic source SHA explicitly.** Workflow caller/marker cleanup commits are control-plane history, not semantic source authority; if product/test/build source changes after the green pre-package compile, invalidate the preflight and do not package.
- **A compile-green package proves nothing about contract completeness.** M3-CP1 package 1 passed 123/123 and was still contract-incomplete. Re-run the closeout source audit before declaring any package an acceptance candidate.
- **When a cutover moves a guard earlier, the earlier guard inherits the later one's diagnostic obligations.** CP4 correctly replaced a context-shadow read with a declared-product precheck, but the superseded site published a failing patch index the new site did not. Static closure cannot see this — the audit proved `K=0` while an accepted diagnostic silently degraded to `-1`. Enumerate what the superseded site *published*, not only what it *decided*.
- Compile success is build evidence, not semantic acceptance.
- **Compile-green is not checkpoint-complete when closeout source audit proves the frozen contract was only partially implemented.** Do not freeze a TB selector or promote the artifact; retain the compile evidence, close the gap within budget, or invoke the declared stop-and-replan rule.
- **Arrangement-local typed scope is not proof that a downstream API received its independent source authority.** When a seam consumes `SourceTopologyRegions`/component-sheet authority explicitly, a fixture must construct and pass that authority from source inputs; a valid ownership registry cannot substitute for a null API authority pointer.
- A validator named source-authoritative must reject missing or mismatched typed source authority independently of optional sub-gates.
- A final oracle must receive independent remapped authority; disabling authority or deriving expected state from the output is not validation.
- Derived identity caches must be rebuilt by the same canonical constructor used by their consumers; copied cache kind or a second schema is authority duplication.
- Matching extent is not ownership; exact source-row topology pairing is required.
- A zero-selected test filter is orchestration failure, never a pass.
- **Changed-block coverage is a candidate set, not automatic required-green authority.** Before promoting a red changed-block test into a checkpoint gate, execute the exact identity against the accepted predecessor. If it is already red there, keep it visible as inherited/non-gating unless its precondition is independently repaired; never manufacture a regression by changing the selector without a differential.
- A negative test proves only the guard it actually reaches. Check which guard rejects before crediting a contract to the intended validator.
- A strict mutation negative is evidence only when the intended callback/seam is reached and the intended mutation actually occurs. `mutated=false` or an unreached callback is non-evidence.
- A non-null pointer is not a live object. After a container is moved from, pointers captured into it can still dereference and report the same variant alternative while reading moved-from/empty state. Verify the mechanism, not just the symptom, before writing a corrective measure.
- Never delete an "obsolete" negative before its replacement exists and fails closed for the intended reason.
- A test that permits both legacy and new outcomes while claiming a stricter authority invariant is not a migration test; it is a compatibility test. Tighten it before trusting it as a cutover gate.
- A fixture that copies legacy raw IDs into typed fields cannot prove typed authority independence; derive typed expected owners independently from canonical topology or use metamorphic renumbering.
- Raw row/index values may exist only at verified one-way container, serialization, or diagnostic leaves. Do not decode them back into semantic authority or reconstruct typed owners from arithmetic.
- **One member carrying two semantic domains is a single-authority violation, even inside a test fixture.** When a helper populates two members from two different inputs and the common caller passes the same input twice, the domains coincide by accident and the conflation stays invisible until some other fixture separates them. Name the domains and populate each explicitly.
- **When a typed migration turns a contract red, check whether the typed member means the same thing as the raw one it replaced.** Reverting to the raw member to restore green undoes the migration. The defect is usually that the typed member was populated from a different domain, not that typing was wrong.
- **An audit passing means the family was in scope, not that the family is closed.** Record out-of-scope projection families as explicit decisions; otherwise a passing audit is read as proof of absence.
- An acceptance fixture must establish its intended precondition independently before its assertion can become required-green evidence; an inherited baseline-red supplemental test stays visible but cannot be promoted by naming it part of a new gate.
- **One acceptance test must not require two mutually exclusive execution paths.** If a fast path returns before a later fallback seam, prove each real contract with a witness that actually reaches its owning path instead of weakening or conflating the assertions.
- **Checkpoint-static scanners are immutable historical evidence, not automatically current semantic truth.** When accepted later work legitimately changes package layout, source-list indirection, or typed representation counts, replay the old scanner against its exact accepted source and reconcile the current delta with a fresh fail-closed audit rather than weakening the historical baseline or treating name-only drift as a semantic regression.
- **Do not backfill a later architecture concept into an earlier gate by analogy.** If an exit criterion names verifier-assigned `Certified`/D0 but the frozen package exposes no disposition product, `Produced`, validator green, and exact counts are not substitutes. Treat the criterion as undecidable until an explicit mapping or authorized architecture amendment exists.
- **A gate criterion applied to a set of fixtures or components must be stated per member, at that member's own semantic stage.** A conjunction naming one stage's authority cannot be applied to members that never reach that stage. M1 criterion 5 demanded producer disposition of a directly-constructed simplification witness that has no producer — the second unsatisfiable-by-construction defect in the same criterion. Before freezing a gate, check every named concept exists for every named member.
- **Do not author a gate criterion in terms the gated milestone's implementation cannot express.** M1 criterion 5 demanded a disposition tier scheduled for M7, which made M1 unclosable by construction — the error was in writing the criterion, not in the implementation that failed it. When drafting an exit gate, check every named concept exists in the milestone being gated; state the milestone-available equivalent, and record the stronger later form as a forward obligation on the milestone that will own it.
- **A milestone-crossing obligation belongs to the milestone that can discharge it, as an exit criterion.** This is the same rule as the produced-witness debt ledgers: M4 owns the `G4-B002` re-proofs, M5 the `G4-B003` re-proofs, and M7 the criterion-5 disposition re-proof.
- **When semantic authority moves, counterfactual injection authority must move with it.** A test seam that mutates only a legacy diagnostic/shadow object after the production sidecar has been captured no longer proves the consumer contract. Migrate the seam to the declared product; never restore test reachability by reading the shadow back into production semantic authority.
- **An abstraction name is not proof of generic authority.** Before propagating a typed wrapper to a new semantic domain, inspect every template parameter and variant alternative: the accepted `ProducerOutcome<T>` was product-generic but hard-coded `SurfacePhaseFrontFailure`. Generalize the existing authority in place when required; do not force a new domain into the old failure type and do not create a parallel wrapper.
- **A compile-green package is not TB-runnable authority unless it contains every executable that owns the frozen selector.** Preflight completeness before discovery or test execution; a missing owner binary is pre-semantic package closure, never a partial pass.
- **Connector-written control payloads are not byte authority until hashed.** For executable or document-transform payloads, use exact binary-safe Git blob transport and verify the frozen SHA-256 before execution; also bound checkout history to the minimum needed for ancestry/source-drift checks, and remember `git diff --name-only` omits untracked files unless they are intent-to-add/staged.
- **For connector-driven push workflows, workflow installation and trigger are two distinct commits.** The proven P1 pattern is `ec64df6e7864aaa1ba4479b663d6e1a6113c6801`, which first installed the temporary workflow with a narrow `.agents/connector-triggers/...txt` `paths` filter, followed by `1db6ef3a52b90b0185b61db3e1cac73956d205cd`, which created the matching temporary text marker and triggered the already-present workflow. Use this two-commit sequence by default when connector dispatch is unavailable; do not combine first-time caller installation and marker creation in one commit, and do not rely on the workflow-install commit itself as the trigger.
- **When a product-shaped diagnostic mirror is relocated, migrate all literal build-contract markers and typed consumers in the same cutover.** A stale CMake source marker or test access to removed open result fields is build-contract drift, not justification for a compatibility alias. Update the marker/consumer to the declared diagnostic or closed product API and keep semantic authority one-way.
- **Moving semantic rejection earlier does not authorize dropping stage-owned diagnostic sub-invariants.** If an earlier declared-product guard subsumes a later canonical rebuild failure, preserve the same exact diagnostic owner/index or route through the canonical seam; matching only the reason string is not equivalent accepted behavior.

## Mandatory end-of-turn checklist — DURABLE, DO NOT DELETE

1. Confirm the requested turn stayed within scope and no later-turn implementation leaked into it.
2. For Code + Build turns, confirm `runtimeExecution=false`; for Test + Benchmark turns, confirm no rebuild/repair/source/test/fixture mutation occurred inside the immutable gate.
3. For every Test + Benchmark turn, update `Regression_Root_Cause_Tracker.md` for every observed regression/candidate before advancing the handoff.
4. Confirm exact source/package/run/artifact identities and stable regression totals are recorded in the owning durable report/tracker.
5. Remove temporary workflows first, then trigger markers/payloads; retain durable workflows and retained evidence.
6. Confirm the handoff names exactly one next turn and the task index agrees with it.
7. Make the final repository write one summarized PR #8 conversation comment after all branch/PR-description writes.
# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05
**Repository:** `akashskypatel/Directional`
**Base:** `surface_cell_quad`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Current checkpoint

P5-TB39 artifact-only R2E11 Test + Benchmark is complete. R2E11 is not accepted.

- exact tested source: `b3010a36f762bb7317f2201d94733226b418c2c0`;
- artifact: `8950709981`, SHA-256 `012a7782726b849ece1aa72286ae2ae9eb98b6a803106813b87caf348939a31c`;
- integrity: manifest **20/20**, package files **21**, submodules **9**, staged fixtures **26**;
- evidence: `directional-p5-tb39-8950709981-evidence.zip`, SHA-256 `ff423c6ebd77acfd16c9558f26f3dd08574c92e510fdc0eb815a7d34b8854803`, entries **169**, size **387,229 bytes**.

R2E11's derived diagnostic is valid and deterministic, but both target fixtures still reject before publication:

- planar: aggregate `BoundaryFanSectorCoverConflict`, derived `ExteriorPairMismatch`, tuple `3/11/10/9`;
- hard rail: same aggregate/derived failure, tuple `1/7/6/1`.

The complete split inventory is **597/625** with the same 28 failures as P5-TB38; Phase 17 remains **20/26**. Two single-process full-suite attempts stalled when P27 entered the bunny case after prior suite state. Preserve this as independent nontermination/performance evidence; never treat timeout as correctness.

The next turn is **P5-R2E12 normalized authoritative exterior-pair inventory Code + Build**. R2 remains open. Do not advance to R2F or R3.

## Current runtime authority

- source chart + validator **17/17**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- complete split inventory **597/625**, 28 failures.

All direct analytic and completed bunny runs report `success=false` under backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution. Completed repeated runs retain deterministic structural lineage.

## Retained authoritative documentation

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_TB39_Artifact_Only_R2E11_Test_Benchmark_Report.md` — latest runtime authority;
3. `Milestone_G_P5_R2E12_Normalized_Authoritative_Exterior_Pair_Code_Build_Plan.md` — next executable plan;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

## Retained benchmark results

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-tb39-summary.json` — current machine-readable runtime authority.

## Read first for P5-R2E12

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB39_Artifact_Only_R2E11_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E12_Normalized_Authoritative_Exterior_Pair_Code_Build_Plan.md`
6. `benchmark-results/p5-tb39-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E12 objective

Construct and reconcile the exact independently proven exterior triple as one normalized canonical pair before interior chart-corner witness resolution. Require exact boundary identity, normalized source entity, transition root, incoming/target coverage, and one exterior exclusion. Preserve transactional publication, genuine wrap evidence, hard-rail complete-orbit root validation, all unchanged validators, and the full prohibition set.

Do not include the independent P27/bunny nontermination investigation, Phase 17, cylinder, FlowRep, completion, fallback/recovery, or validator changes in R2E12.

## Lessons from P5-R2E8

- Generated whole-file transformations can hide a one-brace scope error even when the intended semantic change is narrow. Inspect the exact transformed hunk and compile before treating the source commit as authoritative.
- Large base64 workflow payloads are fragile when transferred through repository writes. Prefer a bounded inline transformation with exact pre-image blob checks, one-file scope verification, `git diff --check`, and a compile-only gate.
- Build-orchestration failures are not implementation acceptance evidence. Preserve their logs, correct the mechanism narrowly, and claim only the final verified source/artifact.
- The final successful workflow must push the exact compiled source commit before building, then package that same commit and record both workflow-event and source authority.

## Lessons from P5-TB36

- A producer can pass the typed local incidence gate while still publishing the wrong global cell topology. Planar must be judged by the derived cyclic-wrap inventory and Euler-one closure, not incidence validity alone.
- Enumerating consecutive rays after chart filtering is not equivalent to enumerating the authoritative cyclic R1 fan pairs. The wrap relation must exist in the canonical fan inventory before chart-corner resolution.
- Hard-rail provenance may legitimately contain both incident charts, while one bounded directed orbit requires one authoritative embedding root. Preserve full provenance and publish selected orbit support as distinct concepts.
- R2E8 restored all six Phase 17 failures without changing Phase 17. Preserve that upstream improvement and do not patch downstream tests or implementation.
- A green benchmark process exit only means the benchmark harness wrote a result; each direct case still reports `success=false` and must remain classified as failed production output.

## Lessons from P5-R2E9

- GitHub contents writes preserve exactly the supplied text; omitting one final newline changes the payload SHA-256 even when base64 decoding would yield identical bytes. Verify the repository blob's exact digest before triggering a bounded workflow.
- Canonical topology inventory and chart witness resolution must remain separate stages. Chart evidence can validate a canonical pair but must not decide which canonical pairs exist.
- A hard-rail root is authoritative only after the complete bounded orbit closes and every directed halfedge supports the same root. Do not publish partial-orbit evidence.

## Lessons from P5-TB37

- An unchanged focused failure count can conceal a producer regression. Compare the first typed failure and reached assertions, not only pass totals.
- Enumerating every per-identity cyclic pair and then unioning the records is not sufficient; the node-level directed pair cover must be normalized and proven unique before chart resolution can publish it.
- Canonical wrap adjacency needs a continuous exact chart-corner interval. A scalar angle-order check must not silently reject a valid wrap or accept a span containing an intervening ray.
- The six Phase 17 regressions are upstream-input regressions. Do not modify Phase 17 to compensate.

## Lessons from P5-R2E10

- Equivalent source-entity fan identities may describe one directed incidence relation. Collapse them only through exact canonical entity and transition-root agreement, while preserving all agreeing identities as provenance.
- The exterior boundary continuation must be matched against the normalized directed-key inventory, not counted independently within each fan identity.
- A wrap witness is an oriented interval problem. Lift angles into one continuous chart-corner interval and reject any span containing another canonical fan ray.
- Compile success proves only source/build validity. R2E10 cannot be accepted until artifact-only runtime evidence restores incidence, topology, hard-rail embedding, and Phase 17 authority.

## Lessons from P5-TB38

- Normalizing pair inventory ownership is insufficient when chart resolution later reintroduces exact provenance identity as an ownership gate. Use one normalization contract end to end.
- Reconcile witnesses at the canonical pair level before enforcing uniqueness. Fan identities are provenance and must not independently create or reject topology.
- Aggregate typed failures need derived subreasons. Preserve fail-closed behavior while recording whether rejection came from zero candidates, multiple candidates, entity mismatch, root mismatch, score conflict, interval invalidity, or cover incompleteness.
- Wrapper or orchestration interruption is not product timeout evidence. Retain raw attempts, run one authoritative process to normal completion, and report that process only for correctness, wall time, and RSS.
- The unchanged 597/625 total confirms no broad new regression, but also no target closure. Failure stage remains the deciding evidence.

## Lessons from P5-R2E11

- One normalization contract must govern both canonical pair construction and chart witness admission. Exact provenance variants cannot become a second ownership gate after normalized equivalence is proven.
- Witness uniqueness is meaningful only after all agreeing provenance contributions are reconciled at the canonical pair level.
- Derived failure subreasons improve diagnosis without weakening fail-closed semantics when recorded at the same rejection site as the aggregate failure.
- Compile-only package authority is not runtime acceptance evidence.

## Lessons from P5-TB39

- The independently proven exterior relation must be a first-class record in the normalized pair inventory; checking for it after generic fan-pair construction is too late when no generic identity creates that exact triple.
- Exterior authority and interior chart-corner authority are different. The unbounded side must be excluded exactly once without requiring an interior face-corner witness.
- A derived diagnostic is accepted only when it preserves the aggregate failure and deterministically identifies the exact rejected record; R2E11 satisfies this diagnostic requirement even though product topology remains failed.
- A complete split test inventory can establish the failure set, but it cannot erase a reproducible single-process nontermination regression. Record both independently.
- Intermittent or cumulative bunny stalls are performance/nontermination evidence, not correctness evidence; completed independent processes remain the authority for output and structural determinism.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the **start and end of every turn**, inspect `.github/workflows` and all temporary workflow-support locations, including temporary trigger files, transfer files, patch/payload directories, and generated build artifacts.
2. Remove stale bounded or turn-specific workflow files before beginning work so an old workflow cannot run, conflict with the current turn, or generate unrelated errors.
3. During a remote compile turn, retain only the approved durable base workflow files plus at most one bounded workflow and the exact temporary payloads required for the current turn.
4. Immediately after the current artifact and logs are published and verified, remove the bounded workflow, its trigger, and its temporary payload or transfer files.
5. The final branch state for every turn must contain only approved durable base workflows and no stale temporary workflow payloads or generated build artifacts.
6. Do not remove a durable base workflow dependency that is explicitly consumed by an approved retained workflow. Distinguish active base-workflow inputs from stale turn-specific payloads before deleting anything.

### Documentation and test-result cleanup

1. At the **end of every turn**, review `.agents` and `benchmark-results` and remove stale or superseded documents, plans, reports, closure notes, evidence indexes, test results, benchmark results, and machine summaries.
2. Retain only durable project authority and the minimum current turn chain required to resume expertly: the live handoff, the latest completed authoritative report, the next executable plan, current source/package authority, the latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Update every retained document so it references only files that still exist after cleanup.
4. Do not keep duplicate historical snapshots merely for provenance; Git history and the PR conversation are the historical archive.
5. Never delete the latest authoritative evidence or next-turn instructions before their replacement is committed and verified.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly instructs its removal or replacement.**
2. Handoff edits must be additive or narrowly corrective by default. Preserve all existing procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Before committing a handoff update, compare the new document with the previous version and verify that every pre-existing mandatory instruction remains present and materially unchanged.
4. When a new instruction appears to conflict with an existing mandatory instruction, preserve both, identify the conflict explicitly, and request user direction rather than deleting either instruction.
5. Documentation cleanup does not authorize removal of mandatory handoff rules. Mandatory rules remain even when older reports, plans, and results are deleted.

## End-of-turn requirement

Every completed Code + Build, Test + Benchmark, optional Review, or documentation-maintenance turn ends with a **new top-level PR #8 comment** after all documentation and PR metadata updates. That comment must be the final repository write.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.

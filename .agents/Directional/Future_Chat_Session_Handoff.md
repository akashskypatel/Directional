# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB38 artifact-only R2E10 Test + Benchmark is complete. R2E10 is not accepted.

- exact tested source: `bf33049157dfee51a1b6c48dff35a97ce980e49f`;
- workflow event commit: `4831349b3d8c996a44bbd804f12ad01be9e3446f`;
- workflow run/job: `31051610854` / `92459824013`;
- build artifact: `8948771075`;
- build artifact SHA-256: `d0815a8423cd71758eb4f1033c0d3f19fd34261df4ea5c32efcf80b2069c3210`;
- log artifact: `8948771526`;
- log artifact SHA-256: `e2a8b1ab9399952f3ffd029e747cc09271bb64906b5a8509e2ed6447e9f8bf20`;
- internal manifest: **19/19**; package files: **20**; staged fixtures: **26**; recursive submodules: **9**;
- evidence archive: `directional-p5-tb38-8948771075-evidence.zip`;
- evidence SHA-256: `e5991d8a3fd58a16e9b62366e6a83b1953f2164806f7de9952db2d38d3853b19`;
- evidence entries: **140**; evidence size: **438,425 bytes**;
- no configure, rebuild, relink, patch, regeneration, or repository source/test/fixture/validator/workflow modification occurred.

Runtime remains at the P5-TB37/R2E9 regression baseline:

- planar fails `BoundaryFanSectorCoverConflict` at its first incidence assertion before successor publication;
- interior hard rail fails the same typed failure before bounded-orbit root validation;
- Phase 17 remains **20/26**;
- complete suite remains **597/625**, 28 failures.

The next turn is **P5-R2E11 normalized chart-entity ownership and pair-first witness reconciliation Code + Build**. R2 remains open. Do not advance to R2F or R3.

## Latest runtime authority

P5-TB38 results:

- source chart + validator: **17/17**;
- recovery authority: **9/9**;
- feature/barrier: **8/8**;
- graph-dependent: **5/6**, bunny only;
- R2 focused: **13/16**;
- Milestone D: **5/7**;
- Phase 16: **45/47**;
- Phase 17: **20/26**;
- Phase 18: **57/57**;
- Phase 14–18: **235/244**;
- Phase 20: **46/48**;
- complete suite: **597/625**, 28 failures, XML **72.587 s**, wall **72.60 s**, maximum RSS **281,456 KiB**.

The six Phase 17 tests restored naturally by R2E8 still fail without Phase 17 changes. Treat them as upstream arrangement consequences and do not patch Phase 17.

Direct analytic production remains incomplete:

- plane: arrangement/simplified/quads `9/9/12`, fails `AggregateCompletionValidationFailure`;
- multi-face seam, close sheets, cylinder: `0/0/0`, fail `SideSubdivisionRepair:InvalidInputIncidence`;
- all measured runs report `success=false` and deterministic structural lineage.

Two independent bunny processes report `0` arrangement cells and `0` quads, fail `SideSubdivisionRepair:InvalidInputIncidence`, and have identical stage hashes/counts.

## Earliest current producer diagnosis

Current diagnostics expose only `BoundaryFanSectorCoverConflict`; the following is a source-supported inference.

R2E10 normalizes equivalent fan identities while creating `canonicalPairInventory`, but chart resolution later iterates each original fan identity and requires the chart-resolved canonical entity to equal that exact original identity. This is stricter than the normalized ownership contract and can reject an otherwise agreeing normalized entity/root witness. Candidate gathering also remains fan-identity-first rather than pair-first.

R2E11 must:

1. retain the node-level canonical pair inventory;
2. build chart evidence independently of one original provenance identity;
3. normalize chart-resolved entities with the same `canonical_entity_key` contract;
4. require normalized entity and transition-root agreement with the pair record;
5. preserve exact original identities only as provenance;
6. reconcile all agreeing provenance witnesses before requiring one authoritative chart/root witness per pair;
7. retain exact exterior exclusion, complete transactional cover publication, and hard-rail complete-orbit root audit;
8. add derived conflict subreasons without weakening `BoundaryFanSectorCoverConflict`;
9. restore planar/hard-rail incidence and Phase 17 **26/26** without Phase 17 changes;
10. leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, fixtures, and downstream validators unchanged.

## Retained authoritative documentation

Only current, durable documentation is retained under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_TB38_Artifact_Only_R2E10_Test_Benchmark_Report.md` — latest runtime authority;
3. `Milestone_G_P5_R2E11_Normalized_Chart_Entity_Pair_First_Witness_Code_Build_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and evidence indexes are removed after replacement. Their historical commit data remains available through Git history and PR #8.

## Retained benchmark results

Only current or durable result files are retained under `benchmark-results`:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-tb38-summary.json` — exact artifact/runtime authority and next-turn disposition.

Older P5 checkpoint summaries and superseded runtime snapshots are removed after their current conclusions are carried into this handoff and the active trackers.

## Read first for P5-R2E11

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB38_Artifact_Only_R2E10_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E11_Normalized_Chart_Entity_Pair_First_Witness_Code_Build_Plan.md`
6. `benchmark-results/p5-tb38-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E11 objective

1. Implement normalized chart-entity ownership and pair-first witness reconciliation in the boundary fan-cover producer.
2. Add derived, deterministic conflict subreasons while retaining the aggregate fail-closed typed failure.
3. Preserve exact exterior exclusion, complete incoming/target bijection, and hard-rail complete-orbit root authority.
4. Strengthen only focused Phase 16/Milestone D contracts when needed; do not modify Phase 17.
5. Leave all independent producers and downstream validators unchanged.
6. Push the exact source commit before compiling.
7. Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
8. Execute no test, benchmark, custom input, CLI, GUI, help/list/discovery command, or generated project binary.
9. Package source/binaries/libraries/fixtures/metadata/checksums and separately upload complete logs.
10. Produce the P5-TB39 artifact-only validation plan.

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

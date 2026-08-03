# Directional Surface-Cell Quadrangulation — Future Chat Session Handoff

**Snapshot date:** 2026-08-03  
**Repository:** `https://github.com/akashskypatel/Directional`  
**Base branch:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** `#8` — keep open, draft, and unmerged  
**Review policy:** `never`  
**Current phase:** Milestone G, P5 — global ownership-frontier remediation  
**Next authoritative turn:** **code changes + compile-only build**

This document is the fastest way to restore project context in a new chat session. It supplements the installed coding-agent skills with project-specific procedures, exact current evidence, prior mistakes, and behavioral rules learned during implementation.

---

## 1. One-minute status

The surface-cell backend now passes all authoritative tests exercised in P5-TB10:

- Corrected route-complete subset: **6/6**
- `PatchDescriptorMilestoneE.*`: **21/21**
- Phase 16 + Phase 18: **89/89**
- Phase 14–18 aggregate: **229/229**
- Milestone G P23 + Phase 20: **52/52**
- Authoritative non-overlapping total: **302/302**

The direct `bunny_1k_random.obj` production benchmark still fails closed at completion and emits no mesh.

The current route-complete implementation successfully derives and applies one deterministic eight-interval coupled boundary-sector transaction for the active `4956/4954` ownership claim. After that transaction, assembly reports another same-corner claim at `14137/14136`. Those patches are outside the transaction’s affected patch set, so the strongest supported explanation is that the second claim was already latent and hidden by first-conflict-only assembly.

The present blocker is therefore **not route incompleteness**. It is the **first-conflict progress model**:

1. assembly returns only the first ownership conflict;
2. repair expects one transaction to reach zero conflicts;
3. a different next conflict is labeled “introduced” without a complete before/after inventory;
4. independent latent claims cannot be resolved incrementally or batched;
5. full global recompletion makes wall time unacceptable.

The next code/build turn must implement a complete exact ownership-conflict inventory, exact conflict-set progress, deterministic independent-component batching or exact completion-product reuse, artifact-contained test fixtures, and wall-time recovery.

---

## 2. Authoritative repository state

### Current validated implementation

- Route-complete implementation commit:  
  `5dcc6da94977c733ada42967ecdafa566cbc5d0b`
- Exact compiled source:  
  `76cf884a6890a23a6db7d7bda9bc77b85ec4505c`
- Validated artifact:  
  `8844133680`
- Artifact name:  
  `surface-cell-p5-route-complete-linux-release`
- Artifact digest:  
  `sha256:1f32a4d3600d1a7be39e710d35273f80bed0c24850626d744ab15e7a748a34bb`
- Compile-only workflow run:  
  `30782277625`
- Compile job:  
  `91589158985`
- Build result:  
  **131/131 steps completed**
- Artifact source status:  
  empty
- Artifact checksum verification:  
  **10/10 passed**

The branch head may be newer than the exact compiled source because documentation and tracker commits continue after artifact creation. **Never treat the current branch head as the compiled checkpoint.** Use `source-commit.txt` inside the artifact as the authority.

### Pull request

PR #8:

- Title: `WIP: Milestone G P5 bridge and pinch topology healing`
- Base: `surface_cell_quad`
- Head: `agent/surface_cell_quad/p5-recover-bridge-healing`
- State: open
- Draft: yes
- Merged: no

Do not mark ready, enable auto-merge, or merge until P5, P6, P7, and P8 closure evidence is complete.

---

## 3. Required reading order for a new session

Read these files in this order before changing code:

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`
5. `benchmark-results/p5-tb10-summary.json`
6. `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Report.md`
7. Relevant implementation and test sources
8. Other `.agents/Directional/*.md` files only when needed for historical contracts

The next-turn plan is authoritative. Earlier plans explain why the current design exists, but they do not supersede the current plan.

---

## 4. Turn cadence and strict boundaries

The project uses separate turns. Do not blend them.

### A. Code changes + compile-only build turn

Allowed:

- Edit production implementation.
- Edit tests and benchmark source.
- Edit build and artifact-packaging logic.
- Configure and compile.
- Package exact source, binaries, libraries, fixtures, logs, submodule revisions, status, and checksums.
- Update plans, reports, trackers, result summaries, and PR state after compilation.

Required compile targets:

- `directional_core`
- `directional_pipeline`
- `directional_phase1_tests`
- `directional_benchmarks`

Forbidden:

- Running unit tests.
- Running benchmarks.
- Running custom mesh inputs.
- Running binary `--help`, `--list`, test discovery, or any other executable command.
- Claiming runtime correctness based on compilation.
- Mixing artifact execution into the same turn.

### B. Test + benchmark turn

Allowed:

- Download and verify the exact packaged artifact.
- Execute packaged test and benchmark binaries.
- Run independent benchmark processes.
- Update reports, trackers, result summaries, and PR text.
- Correct documentation based on observed results.

Forbidden:

- Rebuilding.
- Editing production implementation.
- Editing test source.
- Editing benchmark source.
- Editing build configuration.
- Silently staging source changes to make tests pass.
- Using a locally rebuilt binary instead of the packaged binary.

### C. Review turn

The generic skill allows a review turn, but this project’s `review_policy` is `never`. The test/benchmark report directly determines the next code/build plan.

---

## 5. Current production evidence

### Target fixture

Use:

`benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

Do not switch back to the simpler `bunny1k` fixture. The random triangulation and more complex geometry are intentional.

### Required direct benchmark configuration

Use:

- backend: `SurfaceCells`
- fallback: `Fail`
- source-grid recovery: disabled
- zero warmups
- one measured run per process
- independent fresh processes

The exact command line should be recovered from the prior result archive or `commands.txt`; do not guess flags when an authoritative command record is available.

### P5-TB10 production results

Four independent processes:

| Run | Role | Wall time | Peak working set | Completion stage | Result |
|---|---|---:|---:|---:|---|
| 1 | Formal | 66.704669 s | 1,094,594,560 B | 25.980217 s | Failed closed |
| 2 | Formal | 67.738376 s | 1,094,791,168 B | 25.623915 s | Failed closed |
| 3 | Supplementary | 66.756596 s | 1,094,737,920 B | 25.133695 s | Failed closed |
| 4 | Supplementary | 66.909710 s | 1,094,815,744 B | 25.683125 s | Failed closed |

Acceptance caps:

- Wall time: **≤ 39.228299 s in every process**
- Peak memory: **≤ 1,115,394,560 B in every process**

Disposition:

- All processes remained below the memory cap.
- The highest independent resident-set measurement left only **20,472,320 B** of margin.
- Every process exceeded the wall-time cap.
- No process produced a final output mesh.
- No fallback or source-grid recovery occurred.
- Results were deterministic.

### Exact route evidence

Original active ownership claim:

- patches: `4956 / 4954`
- classification: `same-corner-distinct-boundary`

Topology-derived coupled route candidate:

- route identity hash: `8326996045896577381`
- shared-corner hashes:
  - `1852193725494285512`
  - `13423692822468399424`
- exact interval count: `8`
- halfedges:
  - `22706`
  - `23112`
  - `22707`
  - `22710`
  - `22824`
  - `23924`
  - `23922`
  - `23932`
- affected patches:
  - `4952`
  - `4954`
  - `4955`
  - `4956`
  - `4957`
  - `4958`
  - `5184`
- inserted vertices: `8`
- split undirected edges: `8`
- full recomputation passes: `2`
- peak live candidate complexes: `1`
- peak structural-repair owned bytes: `210,773,020`

Post-transaction first reported claim:

- patches: `14137 / 14136`
- classification: `same-corner-distinct-boundary`
- both completions: closed-form
- source support: equal
- authoritative boundary identities: distinct

The `14137/14136` patches are not in the route candidate’s affected-patch set. This is evidence supporting a latent claim, but it is not proof until complete pre/post conflict inventories exist.

---

## 6. Exact next implementation scope: P5-CB42 through P5-CB50

Use the authoritative global ownership-frontier plan. The required work is:

### P5-CB42 — Self-contained artifact tests

Fix `BenchmarkManifestDispatchesBackends`.

Current defect:

- The packaged test binary contains an absolute CI source path:
  `/home/runner/work/Directional/Directional/benchmarks/fixtures/manifest.example.json`
- P5-TB10 had to stage the packaged source archive at that path.
- That staging was acceptable only as diagnostic evidence. It is not an acceptable product behavior.

Valid fixes:

- Package required fixture data beside the executable and resolve it relative to the executable.
- Add a deterministic runtime fixture-root override.
- Generate a temporary manifest using packaged fixture files.

The test must continue exercising real manifest parsing and backend dispatch.

### P5-CB43 — Complete compact conflict inventory

Assembly must scan all otherwise valid completed quads and return every exact ownership conflict, not stop after the first.

Each compact authoritative conflict record must include exact identity for:

- canonical authoritative corner cycle;
- canonical stitch cycle;
- both patch/domain identities;
- oriented boundary identity;
- undirected boundary-halfedge identity;
- source support;
- component and sheet;
- patch/local-quad/backend/variant lineage;
- conflict classification.

Rules:

- Hashes are diagnostic only.
- Exact identity controls equality and ordering.
- Preserve immediate hard failure for degenerate faces, invalid lineage, invalid domain ownership, inconsistent shared positions, and similar fatal validity failures.
- Sort and deduplicate conflict records deterministically.
- Bound verbose strings separately from compact authoritative records.
- Include inventory identity in repair-state equality and semantic hashes.

### P5-CB44 — Exact latent versus introduced classification

Compare complete pre-candidate and post-candidate inventories.

Required outcomes:

- `ResolvedAllClaims`
- `StrictConflictReduction`
- `LatentClaimExposed`
- `IntroducedOwnershipClaim`
- `NoProgress`
- `ConflictRegression`

Mutation locality may support diagnostics, but exact inventory membership is authoritative.

A different first conflict is **not** sufficient evidence of a newly introduced claim.

### P5-CB45 — Global ownership frontier

Use one invocation-owned, non-recursive frontier:

1. collect complete conflict inventory;
2. partition conflicts into connected components by exact dependency overlap;
3. derive one topology-complete route candidate per claim/component;
4. batch pairwise-independent components into one atomic subdivision transaction;
5. process overlapping components deterministically;
6. commit internal working state only on strict conflict-set reduction and no introduced claim;
7. emit final output only when inventory is empty and all validators pass.

Internal progress states remain private and transactional. Never expose partial output.

### P5-CB46 — Wall-time recovery

Do not add a sequence of full global recompletion passes. P5-TB10 already averages about 67 seconds.

Use one or both:

#### Independent repair batching

Union interval sets for pairwise-independent conflict components and perform one parity/side-repair/completion/assembly cycle.

#### Exact dependency-hash reuse

Reuse a descriptor or completion product only when every exact dependency matches, including:

- cell/domain identity;
- ordered boundary-node identity;
- undirected boundary-halfedge identity;
- side counts;
- feature constraints;
- source support;
- component/sheet;
- singularity ownership;
- completion options;
- backend selection.

Recompute only changed components and proven dependency closure. For small fixtures, compile debug-time equivalence checks against full recomputation.

Do not implement heuristic incremental reuse.

### P5-CB47 — Memory discipline

The remaining memory margin is small.

Required behavior:

- one authoritative working complex;
- at most one mutable candidate transaction;
- compact interned conflict identities;
- no duplicate full completed-patch vectors;
- release verbose diagnostics and rejected products promptly;
- preserve peak live candidate count of one;
- continue reporting owned bytes by category.

### P5-CB48 — Diagnostics and hashes

Expose:

- pre/post conflict counts;
- exact inventory hashes;
- retained/removed/latent/introduced counts;
- component identities and independence relationships;
- batched candidate interval sets;
- affected domains;
- reused/recomputed descriptor counts;
- reused/recomputed completion counts;
- dependency-closure size;
- full versus reused pass counts;
- frontier and cache owned bytes;
- typed progress outcomes.

Again, exact identities control behavior. Hashes support diagnostics and reproducibility.

### P5-CB49 — Regression sources

Compile, but do not run, tests for:

- two independent latent claims;
- complete inventory finding both;
- one batched transaction resolving both;
- different next first conflict classified as latent;
- genuinely new conflict rejected as introduced;
- equal inventory classified as no progress;
- overlapping components processed deterministically;
- patch/row/insertion-order invariance;
- exact reuse matching full recomputation;
- semantic hash mutation;
- artifact manifest dispatch from arbitrary extraction path;
- one-live-candidate and bounded-memory accounting.

Tests must not set final validity or conflict flags synthetically.

### P5-CB50 — Compile/package gate

Compile only the four required targets.

Package:

- exact pushed source;
- empty source status;
- binaries and libraries;
- executable-relative test fixtures;
- configure/build logs;
- recursive submodule revisions;
- checksums.

Execute no binary.

---

## 7. Production constraints that must not be weakened

Never “solve” P5 by:

- deleting or deduplicating final faces;
- accepting partial output;
- merging vertices by position;
- splitting vertices based only on position;
- matching by approximate geometry when exact identity exists;
- hard-coding production patch, halfedge, or vertex IDs;
- pairing source triangles to force quads;
- enabling source-grid recovery;
- using legacy fallback;
- increasing arbitrary search budgets;
- enumerating arbitrary interval subsets or powersets;
- weakening topology, provenance, lineage, support, disk, embedding, orientation, or duplicate validators;
- changing a test expectation to match broken production behavior;
- constructing a test that never reaches the path it claims to validate.

The backend must remain a direct, deterministic, cross-field-aligned, pure-quad surface-cell implementation for arbitrary triangle meshes.

---

## 8. Important implementation history

This history explains why current constraints exist.

### P5-TB7

Intrinsic source support was fixed. The pipeline reached assembly and completed all descriptors, but failed on a deterministic same-corner ownership claim. This established that source-support escape was no longer the blocker.

### P5-CB21–P5-CB26

Added exact same-corner classification and a first structural boundary-sector repair. Corrected invalid generated-interior and parity fixtures.

### P5-TB8

All broad suites passed, but random bunny timed out with roughly 2.74 GB memory. Root cause: recursive candidate expansion, depth-local budgets, repeated full-complex copies, and no global visited-state budget.

### P5-CB27–P5-CB33

Replaced recursion with a globally bounded non-recursive ledger, exact state deduplication, one live candidate, and typed outcomes.

### P5-TB9

Termination and memory became bounded. Two single-interval candidates each replaced one ownership claim with another. Three new tests were invalid because their fixtures completed before structural repair.

### P5-CB34–P5-CB41

Replaced single-halfedge candidates with exact maximal routes and topology-derived coupled sectors. Added atomic multi-interval subdivision, improved diagnostics, corrected structural fixtures, and added artifact-memory accounting.

### P5-TB10

All authoritative tests passed. The eight-interval coupled route worked mechanically, but the first-conflict model rejected progress when a different independent conflict appeared. Wall time doubled because the implementation still performed full global recompletion and could not batch or reuse products.

---

## 9. Learned behavior from mistakes

These are mandatory operating lessons, not optional style preferences.

### Test construction

1. **Assert the intended precondition before testing budgets or outcomes.**  
   A structural-repair test must first prove that initial completion produces a real `SameCornerDistinctBoundaryClaim`. Otherwise budget and ledger assertions are meaningless.

2. **Do not force production code to enter a repair path for an already valid fixture.**  
   Fix the fixture.

3. **Do not mutate a generated vertex to another face that is still inside the patch’s allowed source support.**  
   A source-support escape test requires a valid source face genuinely outside the patch support.

4. **Do not manually set final `topologyValid`, repair-success, or conflict flags.**  
   Populate authoritative geometry/topology inputs and let production recomputation derive validity.

5. **Passing tests may be vacuous.**  
   A zero-attempt order-invariance test proves nothing about repair-order invariance. Require a nonempty ledger where the test’s purpose demands it.

6. **Treat a failing test as potentially wrong.**  
   The user explicitly requires every test to implement and properly test its intended purpose. Correct invalid input data rather than weakening production.

### Ownership and progress

7. **A different first-reported conflict does not prove introduction.**  
   First-conflict scans hide latent claims. Use complete exact pre/post inventories.

8. **Patch IDs and hashes are diagnostic, not semantic authority.**  
   Exact canonical identity must control equality, ordering, deduplication, state membership, and progress.

9. **Closed-form completion has no rotation variants.**  
   Do not consume or report fake variant attempts.

10. **Final-face deduplication is prohibited.**  
    Repair the ownership/layout cause upstream or fail closed.

### Resource control

11. **Budgets must be invocation-global, not recursion-depth-local.**

12. **At most one mutable candidate complex may be live.**

13. **Do not retain multiple full complexes, completed-patch vectors, or verbose failure strings across candidates.**

14. **Full recomputation is authoritative unless exact incremental equivalence is proven.**  
    Reuse requires complete exact dependency identity and small-fixture equivalence checks.

15. **Do not add sequential global passes when the wall gate is already failing.**  
    Batch independent work or reuse unchanged exact products.

### Artifact and workflow handling

16. **Never include `files.sha256` in the set being hashed while writing it.**  
    Write the manifest outside the artifact tree, then move it into place.

17. **The packaged checksum manifest may contain an `artifact/` prefix.**  
    When verifying after extraction, either normalize that prefix or verify from the correct parent directory. Do not incorrectly report checksum failure.

18. **Verify `source-commit.txt` and `source-status.txt` before executing anything.**

19. **Artifact source may differ from the main implementation commit by workflow-restoration or packaging-only commits.**  
    Record both. Runtime authority is the exact packaged source.

20. **A successful workflow is not sufficient evidence.**  
    Download the artifact, inspect file types, verify every checksum, source commit, empty status, logs, source archive, and submodule status.

21. **Absolute compile-runner paths make artifacts non-portable.**  
    Package runtime fixtures and resolve them relative to executable or an explicit deterministic root.

22. **Avoid triggering expensive compile workflows for documentation-only commits.**  
    Preserve `paths-ignore`, `[skip ci]`, or equivalent behavior in the standard workflow.

23. **GitHub Contents API writes require the current blob SHA.**  
    After any intervening commit, refetch the file before updating. A stale SHA causes 409 conflicts.

24. **Do not update the same repository path concurrently.**  
    Sequentially fetch, update, and use the returned content SHA.

25. **Encoded patch transport can be corrupted.**  
    Store a strong expected checksum, decode to a temporary file, verify checksum, run `git apply --check`, and only then apply. Delete transient payloads before committing source.

26. **Workflow-file writes can fail due to missing workflow permission.**  
    Do not mix workflow restoration into a bot commit unless the token has the required permission. Keep production source commits independent from workflow maintenance when necessary.

27. **A failed materialization run must be confirmed not to have changed the branch.**  
    Do not assume a partial workflow committed nothing.

28. **Do not claim tests ran in a compile-only turn merely because test binaries linked.**

29. **Do not claim a runtime defect is fixed until the packaged artifact reproduces the intended result without rebuilding.**

### Reporting

30. **Use authoritative non-overlapping test totals.**  
    Avoid double-counting focused subsets that are contained in broader suites.

31. **Separate observed facts from inference.**  
    Example: `14137/14136` being latent is currently a strongly supported inference, not yet proven.

32. **Keep PR #8 draft and unmerged while P5 is incomplete.**

---

## 10. Standard artifact validation checklist

Before a test/benchmark turn:

1. Download the artifact by exact artifact ID.
2. Record artifact name, digest, size, workflow run, and job.
3. Extract to a fresh arbitrary path.
4. Verify `source-commit.txt`.
5. Verify `source-status.txt` is empty.
6. Verify all checksums.
7. Confirm binaries are expected ELF/PE executable types.
8. Confirm libraries are valid static/shared libraries.
9. Confirm source archive exists.
10. Confirm configure and build logs exist.
11. Confirm recursive submodule status exists.
12. Do not rebuild.
13. Do not stage source-path workarounds unless diagnosing an artifact defect; if used, report it explicitly and require a real packaging fix next turn.
14. Run focused tests first.
15. Run broader authoritative suites.
16. Run benchmark processes independently, one measured run per process.
17. Record wall time, benchmark peak working set, and independent OS maximum RSS.
18. Compare exact hashes and ledgers across runs.
19. Update report, summary JSON, `TODO`, `MILESTONE_G_TODO.md`, and PR #8.
20. Keep P5 open unless all closure gates pass.

---

## 11. Code/build completion checklist

A code/build turn is not complete until all are true:

- [ ] Required source changes implemented.
- [ ] Regression sources compile.
- [ ] No executable has run.
- [ ] Clean optimized static configuration completed.
- [ ] All four required targets linked.
- [ ] Exact source was pushed before packaging.
- [ ] `source-status.txt` is empty.
- [ ] Exact source archive packaged.
- [ ] Executable-relative test fixtures packaged.
- [ ] Recursive submodule revisions packaged.
- [ ] Configure/build logs packaged.
- [ ] Checksum manifest verifies completely.
- [ ] Artifact downloaded and independently inspected.
- [ ] Code/build report written.
- [ ] Plan marked implemented but runtime-unverified.
- [ ] `benchmark-results` summary written.
- [ ] `TODO` and `MILESTONE_G_TODO.md` updated.
- [ ] PR #8 body/comment updated.
- [ ] PR remains draft and unmerged.
- [ ] Next turn explicitly identified as artifact-only test and benchmark.

---

## 12. P5-TB11 preview

The next test/benchmark turn after P5-CB50 must:

- extract the artifact to an arbitrary path;
- require all packaged tests to pass without source-path staging;
- run global-frontier focused tests;
- run prior PatchDescriptor, Phase 16/18, Phase 14–18, and P23/Phase20 suites;
- run at least two formal and two supplementary independent bunny processes;
- require the complete ownership frontier to reach zero;
- require nonempty pure-quad output;
- require no fallback, recovery, timeout, or partial output;
- require deterministic exact conflict inventories, component partitioning, candidate batching, reuse counts, structural hashes, and final mesh hashes;
- require wall time ≤ `39.228299 s` for every process;
- require peak memory ≤ `1,115,394,560 B` for every process.

Compilation alone never closes P5.

---

## 13. Likely source areas for the next turn

Inspect current code before editing. The prior route-complete changes primarily touched:

- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/PatchDescriptor.h`
- `include/directional/pipeline/RemeshPipeline.h`
- `src/geometry/PatchDescriptor.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `src/bench/DirectionalBenchmark.cpp`
- `tests/PatchDescriptorMilestoneETests.cpp`

The global inventory and reuse implementation may also require changes to:

- assembly result structures;
- completed-patch product ownership;
- semantic hash computation;
- benchmark JSON serialization;
- CMake/package fixture-copy logic;
- manifest-dispatch test utilities.

Do not assume these are the only files. Search by exact diagnostics and structures before editing.

Useful search terms:

- `DuplicateStitchedQuad`
- `SameCornerDistinctBoundaryClaim`
- `introduced-ownership-claim`
- `BoundarySectorSubdivision`
- `structuralRepair`
- `complete_surface_cell_complex`
- completed-face assembly
- route candidate identity
- benchmark manifest fixture path
- semantic hash
- owned bytes

---

## 14. Milestone context

Milestones A through F were iteratively remediated before the current work. Do not reopen them based only on old documentation. The current authority is Milestone G and the active P5 plan.

After P5:

- **P6:** production topology, provenance, alignment, and quality validation.
- **P7:** focused and full regression closure.
- **P8:** final bunny benchmark and production disposition.

P5 must not be called complete merely because tests pass. It requires successful direct random-bunny output, deterministic zero conflict frontier, and performance compliance.

---

## 15. Available research and reference material

Project sources include literature and prior implementations such as:

- Directional Field Synthesis, Design, and Processing
- Mixed-Integer Quadrangulation
- QEx
- QuadWild
- FlowRep
- autoremesher source
- topology workbooks and guides
- Directional source snapshots

These are supporting references, not current implementation authority. Use them when a concrete design question requires comparison. Do not replace the repository’s exact production contracts with a paper’s assumptions without explicitly reconciling the difference.

---

## 16. Suggested bootstrap prompt for a new chat

Paste this after attaching or pointing the agent to this handoff:

> Read `.agents/Directional/Future_Chat_Session_Handoff.md`, `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Test_Benchmark_Report.md`, and `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`. Continue the next authoritative **code changes + compile-only build** turn on `agent/surface_cell_quad/p5-recover-bridge-healing`. Implement P5-CB42 through P5-CB50 exactly. Do not run tests, benchmarks, custom meshes, help commands, or test-list commands. Preserve all fail-closed validators and prohibited-fix constraints. Compile and package only the four required targets, verify the exact clean artifact, update the trackers/report/PR, and leave P5 open for P5-TB11.

---

## 17. Source-of-truth files

Current source-of-truth paths:

- `TODO`
- `MILESTONE_G_TODO.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_Global_Ownership_Frontier_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_Route_Complete_Structural_Repair_Code_Build_Report.md`
- `benchmark-results/p5-tb10-summary.json`
- PR #8

When these disagree, use the newest current-turn report and plan, then correct stale trackers. Do not silently reconcile contradictions.

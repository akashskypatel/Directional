# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Test + Benchmark — artifact-only G4 torus sheet-coverage validation**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest G4 artifact-only runtime report, the latest G4 Code + Build report, the authoritative artifact-only Test + Benchmark plan, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Test+Benchmark/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 is **active**. Current runtime artifact `9014730437` proves G4 periodic-relation semantics **5/5**, retained G0-G3 focused contracts **17/17**, and unchanged direct deterministic plane/seam/close-sheets/cylinder hashes. Exact torus retains two periodic relations but the aggregate phase-front remains `NotApplicable`, then reaches 670 generic traces / 113 embedded arcs / zero arrangement cells and `SideSubdivisionRepair:InvalidInputIncidence`. No fallback/recovery is used.

Latest detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Report.md`.

## Completed G4 sheet-coverage Code + Build candidate

Exact compile artifact: **`9015931928`** (`g4-sheet-coverage-code-build`)  
Workflow run/job: `31237248211 / 93051938159`  
Implementation commit: `856554ce648e5df09ac50f5c94e3e8f098181524`  
Final compile-source commit: `a647215b4993338b054f04d4c8e54e7ef5370001`  
Payload cleanup: `e46a6d99a45f22f31672c8e5a3367735427d827e`  
Log artifact: `9015932044`

Artifact authority:

- exact GitHub/downloaded ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- internal `SHA256SUMS` digest `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`;
- recursive checksums **47/47**;
- 48 files / 27 fixtures / five executables / two static libraries;
- seven approved targets built Release/static/Ninja **111/111**;
- artifact metadata `runtimeExecution=false`;
- no generated Directional executable/test/benchmark/ctest/CLI/GUI/help/list/custom-input command executed.

Final source blobs:

- `include/directional/geometry/SurfaceCellTracing.h` `6ebe8f3324be580fc4838b97e5fb449572709236`;
- `src/geometry/SurfaceCellTracing.cpp` `6b32b48141c16e2d51f1932462566083a7bc3355`;
- `src/pipeline/RemeshPipeline.cpp` `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
- `tests/SurfaceCellsPhase10Tests.cpp` `c038567898f0da7efd6519392c37cbace02b8c1c`.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Report.md`.

## Candidate implementation contract

`build_uniform_phase_front()` now evaluates every deterministic authoritative `(component, sheet)` work item before exposing whole-surface authority.

- existing bounded producer is tried first per sheet;
- existing periodic-annulus producer is tried second when bounded is `NotApplicable`;
- local typed rejection still propagates immediately;
- supported sheets retain canonical periodic-relation insertion during the evaluation pass;
- if every sheet succeeds, cells/edges/events are composed only after exact source component/sheet ownership and exact-once sheet coverage are verified;
- if **no** sheet is applicable, the generic whole-surface `NotApplicable` contract is preserved;
- if at least one sheet has produced authority but a later sheet is unsupported, the result is `Rejected / UnsupportedSourceSheetTopology` rather than partial `NotApplicable`;
- aggregate ownership/coverage mismatch rejects as `IncompleteSourceSheetCoverage`;
- no hard feature or source-sheet barrier is weakened.

Compile-only regressions cover mixed bounded+periodic composition, later unsupported-sheet fail-closed behavior under face-order reversal, and the exact torus producer boundary. They are not runtime authority until artifact `9015931928` executes.

## Exact next-turn execution declaration

Before runtime execution state:

```text
Turn type: Test + Benchmark only
Exact artifact: 9015931928 (g4-sheet-coverage-code-build), workflow run/job 31237248211 / 93051938159
Runtime candidate source authority: implementation 856554ce648e5df09ac50f5c94e3e8f098181524 plus final compile source a647215b4993338b054f04d4c8e54e7ef5370001
No-build boundary: do not edit source/tests/fixtures/validators/benchmarks/build files and do not configure, compile, link, or rebuild
First correctness check: run the new sheet-coverage semantic tests, then retain all five prior G4 periodic-relation tests and all 17 G0-G3 focused contracts
Direct regression gate: plane, seam, close sheets, cylinder must retain direct strict-valid deterministic prior authority and exact hashes with no fallback/recovery
Primary G4 observation: exact torus must no longer follow partial NotApplicable -> zero arrangement -> SideSubdivisionRepair; record Produced/materialization authority or the exact typed unsupported-sheet/materialization failure
Acceptable material progress: direct strict-valid torus output, or a deeper/earlier truthful typed producer failure only when canonical relation authority remains live and the old generic zero-cell path is eliminated
Deferred: prescribed sphere unless torus producer coverage closes; G5 adaptivity/features; G6 bunny/vase production; historical completion/simplification repair unrelated to the new earliest failure
```

Follow `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Plan.md` exactly.

## Lessons that must not be repeated

- A test expectation is not automatically production authority; verify that the fixture naturally creates the claimed witness.
- Raw DCEL/source numeric IDs are not stable semantic identities. Compare canonical source endpoint/route authority.
- A source-topologically valid periodic candidate is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint ownership tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- GitHub build workflows must use this repository's `DIRECTIONAL_BUILD_TESTS` / `DIRECTIONAL_BUILD_BENCHMARKS` options and enough fetch depth to verify/package the exact source parent.
- Packaged tests may retain Actions absolute fixture paths. Artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink; never rebuild or patch packaged source to solve that path issue.
- Timeout is failure only; do not infer a disposition from an incomplete run.
- Canonical periodic topology signatures are 64-bit and structural hashing must retain the `std::vector<std::uint64_t>` path introduced by the first G4 compile fix.
- Multiple current periodic relations may belong to distinct authoritative source sheets. Do not infer a generic same-sheet torus homology basis unless source topology proves it; unresolved same-sheet basis remains fail-closed.
- A partially accumulated phase-front result with real cells/relations is not whole-surface authority. Never repair that by flipping the aggregate disposition to `Produced`; first prove complete sheet coverage.
- A downstream completion failure is not automatically the next implementation target. The current runtime baseline proves the earlier producer coverage failure causes the generic zero-cell arrangement path.
- Connector-created text payloads must be verified by committed Git blob; do not assume a locally predicted text SHA-256 survives connector serialization. Record the runtime SHA-256 separately.
- GoogleTest macro arguments containing template commas require an extra parenthesized expression. The `a647215...` compile correction is test syntax only and does not alter production semantics.

## Turn boundary

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink a replacement.
- Review is optional. Review policy is currently `never`, so the Test + Benchmark plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. One Code + Build turn has occurred since the last runtime-proven material progress; artifact-only validation is now next, so the stop threshold is not reached.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when such a workflow is genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger, and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Current hygiene is clean: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent.

## Documentation cleanup — mandatory

1. remove stale/superseded plans, reports, and generated result documents at end of turn;
2. retain the live handoff, latest reports needed for current authority, next executable plan, current runtime summary, and durable design/remediation/workflow docs;
3. retained documentation may reference only files that exist;
4. Git history and PR conversation are the archive for superseded turn detail;
5. never delete the latest evidence or next-turn instructions before replacements exist.

## Instruction preservation — mandatory

1. never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction unless the user explicitly requests it;
2. handoff edits must be additive or narrowly corrective and preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements;
3. compare the prior handoff and verify every mandatory instruction remains present;
4. if instructions conflict, preserve both and request user direction rather than silently choosing one;
5. documentation cleanup does not grant authority to remove workflow or safety rules.

## End-of-turn repository write — mandatory

Every completed turn ends with a **new top-level PR #8 conversation comment** after all documentation, cleanup, and PR metadata updates. That comment is the **final repository write** for the turn. Do not perform any GitHub write after it.

## Prohibitions — mandatory

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters/Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition/cell merging;
- no timeout-as-correctness.

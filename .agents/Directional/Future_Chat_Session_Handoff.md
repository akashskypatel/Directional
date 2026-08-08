# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Code + Build — G4 torus complete phase-front sheet coverage**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest G4 artifact-only runtime report, the G4 Code + Build report, the authoritative next Code + Build plan, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Code+Build/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 is **active**. The first G4 multi-relation periodic-authority slice is runtime-proven material progress but does not close the gate.

Exact current runtime artifact: **`9014730437`** (`g4-holonomy-basis-code-build`)  
Workflow run/job: `31233594490 / 93042009574`  
Primary implementation: `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`  
Final compile-source commit: `6e754bdd64482582d39e71184805fbb053c99f86`  
Payload cleanup: `8304ba30b0f85bc69deebbf55922f05846d2d5b2`

Artifact authority:

- exact downloaded/GitHub ZIP SHA-256 `14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`;
- internal `SHA256SUMS` digest `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`;
- recursive checksums **46/46**;
- 47 files / 27 fixtures / five executables / two static libraries;
- final source blobs independently verified from packaged source;
- validation turn performed no configure/compile/link/rebuild and no source/test/fixture/validator/benchmark/build edit.

Focused/runtime authority:

- five G4 periodic-relation semantics **5/5**;
- G0-G3 retained focused contracts **17/17**;
- plane direct hash `730caeae49ec872c`, 3/3;
- seam direct hash `5bdf34d7802e9fb0`, 3/3;
- close sheets direct hash `89b052762f52a5af`, 3/3;
- cylinder direct `Produced / CompletedSurfaceCells`, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, field P95 `8.537736463e-7°`, exactly two genuine annulus exterior loops, output hash `32135be51d7a0a26`, deterministic 3/3, no fallback/recovery;
- bounded producer **105/106** with only the known timing-only validator-overhead failure;
- completion/simplification **154/164** with the same ten historical failures;
- validation **60/60**;
- API **8/8**;
- bounded aggregate **327/338**.

Latest detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Artifact_Only_Test_Benchmark_Report.md`.

Local evidence archive: `directional-g4-holonomy-basis-artifact-only-evidence.tar.gz`, SHA-256 `6c8f20252d7a616924b388e5643dba994dd5b26cf610794c21e602029c352cb2`.

## Active G4 torus evidence

The previous scalar representation blocker is removed. Exact torus no longer terminates at `InvalidPeriodicTopology` when another relation appears.

Three independent direct runs are deterministic:

- `surfaceCellAuthoritativeProducerDisposition = NotApplicable`;
- periodic relation count **2**;
- compatibility projection of the first relation `r=0`, `t=(24,0)`, route 24, cut 2;
- 670 trace segments;
- 113 retained strands;
- 113 embedded arrangement arcs;
- zero arrangement cells;
- terminal `NotProductionReady:completion`;
- completion failure `SideSubdivisionRepair:InvalidInputIncidence`;
- no output/fallback/legacy substitution/input return/source-grid recovery.

Stage hashes are stable 3/3: tracing `0539b306563dbe25`, strands `618d7ed18d1f3daa`, embedded network `33d00772feecc2f7`, arrangement `1ee6b9f9fd044d71`, completion `b4efe5193b9e5c27`.

The benchmark JSON exposes relation cardinality plus a compatibility projection of the first relation, but not the complete per-relation vector. Do not synthesize unexposed component/sheet/topology-signature details.

Torus feature authority reports 48 hard edges in four closed feature curves. They are real current producer barriers and must not be removed/demoted or Euclidean-welded to force a torus result.

## Exact source diagnosis

The earliest remaining contract is **complete aggregate phase-front coverage across authoritative source sheets**, not completion repair.

Packaged `build_uniform_phase_front()` behavior:

1. partition faces by `(source component, source sheet)`;
2. process sheet work in deterministic canonical order;
3. try bounded uniform phase-front for each sheet;
4. if local `NotApplicable`, try periodic-annulus phase-front;
5. append successful local cells/edges/events and canonical periodic relations;
6. if any later local sheet remains `NotApplicable`, return the partially accumulated aggregate immediately;
7. set aggregate `succeeded=true / Produced` only after every sheet finishes successfully.

Therefore torus can retain two valid periodic relations while the aggregate remains `NotApplicable`. The pipeline correctly refuses authoritative phase-front materialization. Generic tracing/FlowRep then advances, but its 113 embedded arcs produce zero arrangement cells; `SideSubdivisionRepair:InvalidInputIncidence` is a downstream symptom.

Do **not** fix this by marking partial coverage `Produced`.

## Exact next-turn design declaration

Before any source edit emit:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: torus__surface_cells now retains two periodic relations and advances to 670 traces, but aggregate authoritative phase-front disposition remains NotApplicable; generic arrangement then yields zero cells and completion fails SideSubdivisionRepair:InvalidInputIncidence
Missing design contract: build_uniform_phase_front is all-or-nothing across authoritative source sheets; when any later local sheet is NotApplicable it returns a partially accumulated aggregate without Produced status, so already-valid periodic sheet cells/relations cannot participate in complete authoritative materialization and the pipeline falls into a downstream zero-cell generic arrangement path
Smallest general implementation change: make phase-front construction cover every authoritative source sheet deterministically by composing supported bounded and periodic sheet charts under one complete aggregate contract; a sheet that truly cannot be represented must produce a typed first-invalid producer reason rather than silently downgrading the whole partially authoritative aggregate to NotApplicable
Observable material-progress condition: exact torus phase-front becomes fully Produced with complete source-sheet coverage and successful exact materialization, or fails earlier at the exact unsupported sheet with a typed structural reason; it must not return partial NotApplicable followed by zero arrangement cells, while all five G4 relation semantics, all 17 G0-G3 focused contracts, and direct plane/seam/close-sheets/cylinder behavior remain unchanged
Explicitly deferred work: prescribed-sphere singularity completion until torus producer coverage is closed, G5 adaptive scale/hard-feature expansion, G6 bunny/vase production, scheduler timing, historical completion/simplification failures unrelated to the active torus producer contract, validator changes, and unrelated optimization
```

## Next-turn execution

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Holonomy_Basis_Code_Build_Plan.md` as **Code + Build only**.

Required properties:

- complete source-sheet coverage is explicit authority; every produced aggregate covers every authoritative sheet exactly once;
- after any prior sheet has produced authoritative content, a later unsupported sheet must fail with a typed first-invalid phase-front reason rather than partial `NotApplicable`;
- compose existing bounded and periodic sheet producers where structurally valid; add only the smallest topology-derived producer if the missing torus sheet is a different class;
- do not assume every torus sheet is periodic and do not hardcode relation count, `(24,0)`, face IDs, sheet IDs, feature IDs, or process order;
- preserve the current first-class canonical periodic relation collection and all 5/5 G4 relation semantics;
- preserve G2 sheet isolation and all current hard-feature barriers;
- exact authoritative materialization must consume the complete aggregate without Euclidean seam welding, positional sheet merging, or artificial exterior cuts;
- do not modify SideSubdivisionRepair/generic completion/arrangement first; they are downstream under current evidence;
- add compile-only semantic regressions for mixed bounded+periodic aggregates, later unsupported-sheet typed rejection, enumeration invariance, exact-once sheet coverage, exact torus producer boundary, and all prior relation/G0-G3 contracts.

Compile/package the same seven approved Release/static/Ninja targets. **Execute no generated Directional binary/test/benchmark/ctest/CLI/GUI/help/list/discovery command.**

The following artifact-only Test + Benchmark turn must first retain the new sheet-coverage tests, all 5 G4 relation tests, all 17 G0-G3 focused contracts, and direct plane/seam/close-sheets/cylinder hashes. Then exact torus must no longer take the current partial `NotApplicable -> zero arrangement -> SideSubdivisionRepair` path.

Preferred next result is direct strict-valid closed torus production. A typed exact unsupported-sheet or phase-front-materialization failure is acceptable material progress if it replaces the opaque downstream failure without weakening prior authority.

## Lessons that must not be repeated

- A test expectation is not automatically production authority; verify that the fixture naturally creates the claimed witness. The G3 field witness originally failed only because 0.25 target subdivision made a whole 0.5 source inter-ring edge impossible as one front edge.
- Raw DCEL/source numeric IDs are not stable semantic identities. Compare canonical source endpoint/route authority.
- A source-topologically valid periodic candidate is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint ownership tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- GitHub build workflows must use this repository's `DIRECTIONAL_BUILD_TESTS` / `DIRECTIONAL_BUILD_BENCHMARKS` options and enough fetch depth to verify/package the exact source parent.
- Packaged tests may retain Actions absolute fixture paths. Artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink; never rebuild or patch packaged source to solve that path issue.
- Timeout is failure only; do not infer a disposition from an incomplete run.
- Canonical periodic topology signatures are 64-bit and structural hashing must retain the `std::vector<std::uint64_t>` path introduced by the G4 compile fix.
- Multiple current periodic relations may belong to distinct authoritative source sheets. Do not infer a generic same-sheet torus homology basis unless source topology proves it; unresolved same-sheet basis remains fail-closed.
- A partially accumulated phase-front result with real cells/relations is not whole-surface authority. Never repair that by flipping the aggregate disposition to `Produced`; first prove complete sheet coverage.
- A downstream completion failure is not automatically the next implementation target. Current torus evidence proves the earlier producer coverage failure causes the generic zero-cell arrangement path.

## Turn boundary

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink a replacement.
- Review is optional. Review policy is currently `never`, so the next Code + Build plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. The preceding G4 Code + Build plus artifact-only validation established material progress by removing the scalar periodic barrier, so the counter resets to 0.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when such a workflow is genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger, and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Current hygiene entering the next turn is clean: `.github/workflows` contains only `agent-source-snapshot.yml`; bounded G4 workflow/trigger/payloads are absent.

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

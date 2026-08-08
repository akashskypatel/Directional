# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Code + Build — source-topology-region / isolation-sheet decoupling**  
Authoritative next plan: `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest runtime report `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`, the latest compile report `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Report.md`, the authoritative next plan above, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the turn-based-coding-agent Code+Build/testing-integrity/recovery/handoff/GitHub-workflow references. Load the integrated unit-testing module before changing test source.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Exact runtime artifact: **`9021175280`** (`g4-polygonal-boundary-phase-code-build`)  
Workflow run/job: **`31254896323 / 93096734152`**  
Implementation: **`085db9ec23ffaa509b1f5a29e72968229efa103d`**  
Payload cleanup: **`c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`**

Artifact authority:

- ZIP SHA-256 `16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`;
- internal `SHA256SUMS` SHA-256 `a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two project static libraries;
- build metadata `runtimeExecution=false`;
- runtime-only fixture symlink: `/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_polygonal_runtime_9021175280/test-data/benchmarks/fixtures`.

Focused/runtime authority:

- generalized polygonal boundary phase **5/5**;
- source-sheet/isolation semantics **3/3**;
- retained non-torus curved-disk semantics **5/5**;
- strengthened exact-torus advancement contract **0/1**, so retained combined source-sheet/curved group **8/9**;
- sheet coverage **3/3**;
- G4 periodic relations **5/5**;
- retained G0-G3 **17/17**;
- direct plane hash `730caeae49ec872c`, 64 quads / 81 V, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, 64 quads / 81 V, deterministic 3/3;
- close sheets hash `89b052762f52a5af`, 200 quads / 242 V / two components, deterministic 3/3;
- cylinder hash `32135be51d7a0a26`, 288 pure quads / 320 V, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, exactly two genuine 32-edge exterior loops, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery.

Bounded suites:

- producer **119/121**: existing sub-millisecond validator-overhead threshold plus strengthened exact-torus advancement failure;
- completion/simplification **154/164**, exact same ten historical failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **341/353**.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`.

Local evidence archive: `directional-g4-polygonal-boundary-phase-artifact-only-evidence.tar.gz`, SHA-256 `3da110e6b8f4a0ef4759cacbcb5da109b65b85cb62607dcde4955e8203346f9b`.

## G4 decision — planned torus progress was not achieved

The new polygonal representation is runtime-live on its natural structural witnesses. The six-run reflex-corner fixture constructs the generalized phase/chart, invalid turns fail typed, row-order invariance holds, and the rectangular fast path is retained.

Exact torus nevertheless fails deterministically 3/3 before any first-class boundary phase is retained:

- producer `Rejected`;
- stage `tracing/phase-front`;
- reason **`InvalidBoundedDiskBoundaryTurn`**;
- first invalid face `-1`;
- diagnostic source vertex `32`;
- bounded-disk phase count 0;
- run count 0;
- polygonal phase count 0;
- constructed-chart count 0;
- phase hashes empty;
- periodic authority remains live before rejection;
- no downstream cells/output and no fallback/recovery.

A changed typed reason without retained phase/chart authority is not material progress under the controlling plan. The no-progress Code + Build count is now **1**.

**Diagnostic vertex 32, local sheet counts, edge counts, relation counts, analytical fixture parameters and boundary lengths are evidence only. Never use them for fixture recognition, ownership, ordering, branching, union selection, or success criteria.**

## Exact structural diagnosis — producer topology region is not local isolation sheet

Read-only reconstruction of the immutable torus fixture and the exact classifier/feature-map policy shows the upstream partition defect:

- the close/opposing-sheet classifier produces local geometric isolation labels;
- the source has 48 hard edges in four closed feature curves, matching runtime feature diagnostics;
- two classifier-local labels each appear as a disk when considered separately;
- restoring their non-hard exact shared-source adjacency produces one annular region with two genuine hard-feature boundary loops;
- their separating edges are classifier isolation cuts, not hard features or true source boundaries;
- the runtime turn failure occurs where one artificial classifier cut meets a true hard rail, so treating the cut as a bounded-disk exterior polygon side creates an invalid transported corner.

The turn validator is not the defect. **Do not relax `InvalidBoundedDiskBoundaryTurn`, index closure, or field alignment to make torus pass.**

Required architecture:

1. source-topological producer regions derive from exact source adjacency and split at true hard/barrier/source-boundary authority;
2. local isolation-sheet labels remain separate and continue protecting proximity/capture/projection operations;
3. a non-hard cross-sheet edge may be an internal isolation seam only through its exact shared source edge and valid reciprocal field transport;
4. unrelated/disconnected close sheets remain disconnected; no Euclidean/proximity merging;
5. both topology-region and local-sheet provenance remain first-class;
6. producer applicability/topology/coverage groups by topology region, not by local isolation label alone.

## Exact next-turn design declaration

Before source edits emit:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: exact torus under artifact 9021175280 deterministically rejects at tracing/phase-front as InvalidBoundedDiskBoundaryTurn before any bounded-disk phase record is retained; read-only structural reconstruction shows the failing local disk is created by close-sheet isolation labels splitting one exact source-adjacent annular hard-feature region
Missing design contract: sourceFaceSheets currently serves both proximity-isolation and producer-topology partitioning, but a geometric close-sheet isolation seam is not automatically a physical/topological chart boundary
Smallest general implementation change: introduce first-class source-topological producer regions derived from exact source adjacency and true barrier authority, retain local isolation-sheet labels separately for proximity/capture/projection safety, and allow exact reciprocal transport across non-hard source-adjacent isolation seams inside one topology region
Observable material-progress condition: compile/package structural topology-region regressions; the following exact artifact-only torus run no longer fails because an artificial isolation seam is treated as a bounded-disk exterior boundary and advances to the next truthful periodic/coverage/materialization invariant while every retained G0-G3 and isolation-safety contract remains exact
Explicitly deferred: relaxing boundary turn/index checks, generalized polygon front pairing unless runtime reaches it after correct topology partition, prescribed sphere until torus topology closes, G5/G6, historical completion/simplification failures, validator/performance threshold changes, fallback/recovery and unrelated optimization
```

Execute `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md` as **Code + Build only**.

The following artifact-only Test + Benchmark turn must prove topology-region authority is constructed and consumed, retain polygonal/isolation/periodic/G0-G3 contracts and exact direct hashes, then classify exact torus. If that validation also shows no material progress, mandatory design review or bounded producer-replacement proof is required before another ordinary Code + Build iteration.

Prescribed sphere remains deferred until torus reaches direct strict-valid production.

## Lessons that must not be repeated

- A test expectation is not production authority; verify that its fixture naturally creates the claimed structural witness.
- Raw source/DCEL numeric IDs are not stable semantic identities; use canonical topology and source ownership.
- A topologically plausible route is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- Connector-created text payload authority is the committed Git blob; verify transferred patch content/hash separately before application.
- Prefer independently verifiable raw text chunks over manually copied encoded streams for connector-mediated source transfer; prior encoded transfers corrupted bytes.
- GoogleTest macro expressions containing template commas require extra expression parentheses; do not confuse syntax failures with production semantics.
- Packaged tests may carry Actions absolute fixture paths; artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink, never by patching artifact bytes.
- Canonical periodic topology signatures are 64-bit; preserve the `std::vector<std::uint64_t>` structural-hash path.
- Multiple periodic relations can belong to distinct authoritative source regions; do not invent a same-sheet homology basis without topology evidence.
- A partially accumulated phase-front is not whole-surface authority; never flip disposition to `Produced` merely to satisfy coverage.
- Hard-feature rails are source-derived authority; do not demote them to simplify chart topology.
- Local isolation-sheet boundaries are not synonymous with hard-feature edges **or producer-topology boundaries**. Close/opposing-sheet classification may introduce artificial internal seams inside one source-topological region.
- Crossing different local isolation labels is allowed only through exact shared source adjacency plus reciprocal transport; it never authorizes proximity merging.
- Observed face IDs, vertex IDs, sheet counts, relation counts, run counts and boundary lengths are diagnostics, not implementation keys.
- A four-run rectangular chart is a special case, not permission to coerce arbitrary valid field boundaries into four sides.
- A changed failure reason is not material progress unless first-class state proving the intended architecture was constructed and consumed is present.
- Do not fix `InvalidBoundedDiskBoundaryTurn` by accepting 180-degree turns when the apparent corner is created by an artificial isolation cut.
- A valid polygonal chart does not authorize partial output; non-rectangular front pairing remains fail-closed until implemented structurally.
- Harmonic chart compilation and focused applicability are not proof of production chart success; follow the first runtime invariant.
- A downstream completion failure is not automatically the next target; follow the first truthful producer/materialization failure.
- Timeout is failure only; never infer correctness/disposition from incomplete execution.

## Turn boundary — mandatory

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink/regenerate a replacement.
- Review is optional. Review policy is currently `never`; after Test + Benchmark its next Code + Build plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. Current no-progress Code + Build count is **1**; if the next Code + Build's following runtime validation also lacks material progress, trigger that rule.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Expected final state: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent. Verify again before the final turn comment.

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
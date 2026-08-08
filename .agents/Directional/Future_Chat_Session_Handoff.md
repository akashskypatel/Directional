# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Configured optional review policy: `never`  
Process override: **mandatory independent Design Review required by two-no-progress guard**  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Review — mandatory G4 topology-region design review**  
Authoritative next plan: `.agents/Directional/Gate_4_Topology_Region_Mandatory_Design_Review_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest runtime report `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`, the latest compile report `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Report.md`, the authoritative mandatory review plan above, the pending proposal `.agents/Directional/Gate_4_Topology_Region_Materialization_And_Regressions_Code_Build_Proposal.md`, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the turn-based-coding-agent Review/testing-integrity/recovery/handoff/GitHub-workflow references. Load the integrated unit-testing module when reviewing the torus test expectation. The Review turn may edit planning/TODO/handoff documentation only; it must not edit production/tests/fixtures/validators/benchmarks/build files, configure, compile, or execute generated project runtime.

## Current tested authority

G0-G3 remain the accepted baseline, but artifact **`9022061741`** exposes two retained-authority regressions that prevent accepting the candidate as material-progress closure. G4 remains **active**.

Exact artifact-only runtime observation: **`9022061741`** (`g4-topology-region-code-build`)  
Workflow run/job: **`31258107220 / 93104542559`**  
Implementation: **`3ca89ab55efff461b050fb12033174be70e7464f`**  
Payload cleanup: **`b188dd37f01181ece2173879fc7e0accf23d1bad`**

Artifact authority:

- outer ZIP SHA-256 `df23a89f26d0769fa3433bf8996d2d090eaa82770ddc52a52018e51286087306`;
- internal manifest SHA-256 `d80559fab82a359f7ce5ccfe109069765d18f5d440824106d84d70c5b8822703`;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two project static libraries;
- build metadata `runtimeExecution=false`;
- runtime-only fixture symlink: `/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_topology_runtime_9022061741/test-data/benchmarks/fixtures`;
- local evidence archive `directional-g4-topology-region-artifact-only-evidence.tar.gz`, SHA-256 `8f9666620d4fe732bce3319bcaa1a6c47cb85fcc5f453fd52b495100cf952265`.

Focused/runtime authority on this artifact:

- topology-region / isolation-seam semantics **9/9**;
- generalized polygonal boundary phase **5/5**;
- retained non-torus curved-disk semantics **5/5**;
- non-torus sheet coverage **2/2**;
- G4 periodic relations **5/5**;
- retained G0-G3 **16/17** — embedded-relief fail-closed behavior regressed;
- plane hash `730caeae49ec872c`, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close-sheets candidate hash `aaec5574aa2e52f9`, deterministic 3/3, versus accepted `89b052762f52a5af`; geometry/topology identical but component order reversed;
- cylinder hash `32135be51d7a0a26`, deterministic 3/3, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, exactly two genuine 32-edge exterior loops;
- no passing direct case uses fallback or source-grid recovery;
- bounded suites producer **124/127**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **346/359**.

Detailed runtime record: `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`.

## Exact torus — topology architecture is live, materializer is now earliest blocker

Three independent direct processes deterministically report:

- phase-front authoritative disposition `Produced`;
- first invalid stage **`tracing/phase-front-materialization`**;
- reason **`InvalidAuthoritativePhaseFrontCell`**;
- first invalid cell diagnostic 128; first invalid face `-1`;
- topology-region count **4**;
- internal isolation-seam count **8**;
- region Euler characteristics `[0,0,0,0]` and genuine boundary-loop counts `[2,2,2,2]`;
- local-isolation cardinalities `[1,1,2,1]`, proving one annular region spans two local isolation labels;
- periodic relation count **4**; compatibility serialization `r=0`, `t=(24,0)`, route 24, cut 2;
- no bounded-disk phase state, downstream cells, output, fallback, or recovery.

This is real architectural advancement from `InvalidBoundedDiskBoundaryTurn`: the artificial classifier isolation seam is no longer interpreted as an exterior bounded-disk rail.

The deeper failure is also structural. `normalize_scope()` assigns `sourceSheet=-1` to a valid cell with multiple `sourceIsolationSheets`; `build_authoritative_phase_front_mesh()` still requires `sourceSheet >= 0` and keys lattice/periodic materialization by `(component, sheet, lattice)`. The mandatory reviewer must decide the complete topology-region-aware materialization/provenance contract. Do not implement a positional weld or choose one local sheet by ID/order/count.

## Retained-authority regressions that force review

### Embedded relief

The candidate currently splits topology regions at embedded relief barriers. If each resulting region is unsupported by the local producers, aggregation returns global `NotApplicable`, allowing generic seeds/traces/proposals. The established contract requires embedded relief to block authoritative traversal fail-closed; non-embedded relief remains guidance. This is a production implementation regression, not a fixture defect.

The reviewer must decide whether embedded relief is a topology-region separator with a terminal aggregate rule, or an internal authoritative transport barrier within a topology region. Do not select a rule solely to satisfy the fan fixture.

### Close-sheets deterministic identity

Candidate close-sheets geometry and face-geometry multisets are identical to the accepted output, but component order reverses. The prior worklist ordered canonical source geometry before sheet identity; the new region worklist orders `structuralHash` before canonical source geometry.

The accepted hash remains `89b052762f52a5af`; do not update it merely because the candidate differs. The reviewer must decide whether exact component ordering is product authority or whether acceptance should use a canonical component-order-independent structural identity.

### Exact torus contract test

`ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` currently fails first on `ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork)`. Materialization happens before the trace network is moved into retained context, so the assertion aborts before public topology/seam diagnostics that already prove the intended contract.

The reviewer must determine whether `retainIntermediateGeometry` promises trace-network retention on this failure path. If not, the future test may be corrected only by preserving/strengthening its intended topology/seam assertions; intermediate-retention behavior should be tested separately if it is a required contract.

## Mandatory review decision

No-progress Code + Build count is now **2** because accepted progress required both the new architecture and exact retained authority. Another ordinary Code + Build is prohibited until review completes.

Execute `.agents/Directional/Gate_4_Topology_Region_Mandatory_Design_Review_Plan.md`.

The file `.agents/Directional/Gate_4_Topology_Region_Materialization_And_Regressions_Code_Build_Proposal.md` is **`proposed_pending_review`** only. The independent reviewer must inspect primary source/diff/runtime evidence and publish exactly one decision:

1. approve topology-region architecture with amendments and one authoritative Code + Build plan;
2. reject/replace it with a bounded producer-replacement plan; or
3. declare insufficient evidence and authorize bounded instrumentation/evidence only.

The reviewer must resolve topology-region soundness, embedded-relief semantics, close-sheets deterministic identity, multi-isolation materialization/provenance, and torus test scope. Prescribed sphere remains deferred until torus reaches direct strict-valid production. G5/G6, historical completion/simplification failures, validator-threshold changes, fallback/recovery, and unrelated optimization remain deferred.

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
- Do not fix `InvalidBoundedDiskBoundaryTurn` by accepting invalid turns when the apparent corner is created by an artificial isolation cut.
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
- Review is normally optional and configured policy remains `never`; however the two-no-progress process guard has now activated a **mandatory independent Review** before another ordinary Code + Build. After that Review, only its approved/replacement plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without accepted material progress require mandatory design review or bounded producer-replacement proof. Current no-progress count is **2**; the rule is **active**, so no ordinary Code + Build is authorized until the mandatory Review completes.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

The successful topology-region Code + Build removed its six raw payload files in cleanup commit `b188dd37f01181ece2173879fc7e0accf23d1bad`, then removed the bounded workflow before its trigger after artifact verification. The artifact-only validation created no workflow/payload. Expected final state: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent. Verify again at the beginning and end of the mandatory Review turn.

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

# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Code + Build — G4 curved-disk source-sheet boundary authority**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the latest runtime report `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`, the latest compile report `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Report.md`, the authoritative source-sheet-boundary Code + Build plan above, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Code+Build/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Exact runtime artifact: **`9016834575`** (`g4-curved-disk-code-build`)  
Workflow run/job: `31240168780 / 93059691196`  
Implementation: `90046be649a0fd051e6c44eceec07198dc542c29`  
Payload cleanup: `508211936b790dfb40cdbece7900bb0522368b76`

Artifact authority:

- ZIP SHA-256 `6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`;
- internal `SHA256SUMS` SHA-256 `e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two static libraries;
- artifact-only validation made no configure/compile/link/rebuild/discovery or source/test/fixture/validator/benchmark/build edit;
- runtime-only fixture symlink used: `/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_curved_disk_runtime/test-data/benchmarks/fixtures`.

Focused/runtime authority:

- curved-disk semantics **6/6**;
- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- plane hash `730caeae49ec872c`, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close-sheets hash `89b052762f52a5af`, 200 quads / 242 vertices / two components, deterministic 3/3;
- cylinder `Produced / CompletedSurfaceCells`, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, exactly two genuine 32-edge exterior loops, hash `32135be51d7a0a26`, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery.

Bounded suites:

- producer **112/113**, only the existing sub-millisecond `StrictValidatorOverheadStaysBelowFivePercent` performance threshold fails;
- completion/simplification **154/164**, exact same ten historical failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **334/345**.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`.

Latest compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Report.md`.

Local evidence archive: `directional-g4-curved-disk-artifact-only-evidence.tar.gz`, SHA-256 `7e51df90e935f6e393808c1d47e1ad5570fa8125cbf3fb9f736ba90a17d13efd`.

## Exact current G4 torus evidence

The curved bounded disk producer is runtime-live. Three independent exact torus runs now deterministically report:

- `surfaceCellAuthoritativeProducerDisposition = Rejected`;
- first invalid stage `tracing/phase-front`;
- reason `InvalidBoundedDiskTopology`;
- first invalid source face 52;
- periodic relation count reached before rejection **2**;
- compatibility projection rotation `0`, translation `(24,0)`, route 24, cut 2;
- trace/arrangement/simplification/completion output counts 0 after authoritative rejection;
- terminal `NotProductionReady:tracing`;
- no output/fallback/legacy substitution/input return/source-grid recovery.

Stable stage identities: feature `f15e4f3be07d3c7f`, metric `34cb872327c9b0c6`, relief `8ccb10d25b69edb9`, source labels `e48c84177faf6e2c`, tracing `4e27fcfa18a602b1`.

This is material progress over artifact `9015931928`: the torus no longer terminates merely because curved disk topology has no producer.

**Face 52 and relation count 2 are diagnostic evidence only. Never use them for fixture recognition, ownership, ordering, branching, or success criteria.**

## Exact source diagnosis — missing source-sheet boundary authority

Read-only inspection of the immutable packaged source identifies the first failure contract.

`build_curved_bounded_disk_phase_front_for_faces()` builds the local disk boundary from edges with one local incident face. For a local boundary edge that has two incident faces in the full source mesh, the current implementation accepts it only when `options.hardFeatureEdges` contains that edge; otherwise it returns `InvalidBoundedDiskTopology`.

That is narrower than authoritative source-sheet classification.

`classify_source_surface_labels()` can split local sheets across an internal source edge because:

- the edge is an explicit barrier/hard feature;
- `traverseUnmarkedSharpBends` is disabled and adjacent normals violate `normalCompatibility`; or
- close/opposing-sheet conflict logic blocks traversal under the configured geodesic exclusion policy.

Therefore a local source-sheet boundary can be authoritative even when the underlying source edge is not a hard feature.

`SurfaceCellTracingOptions` already carries `sourceFaceComponents` and `sourceFaceSheets`, and the existing `source_faces_compatible()` helper already expresses whether two incident faces share the same authoritative component/sheet.

The current curved-disk source comment says that a local boundary may be a genuine source boundary or an authoritative hard-feature/source-sheet rail, but the implementation checks only hard-feature membership for an internal source edge. The next turn must correct this contract mismatch.

## Exact next-turn design declaration

Before any source edit emit:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: exact torus now reaches the curved bounded disk producer and deterministically fails at tracing/phase-front as Rejected / InvalidBoundedDiskTopology; immutable source inspection shows the rejected local boundary is an internal source edge that is not a hard feature even though source-sheet classification made it an authoritative cross-sheet boundary
Missing design contract: curved-disk local boundary validation currently accepts genuine source boundary edges and hard-feature internal edges, but does not recognize an internal edge between different authoritative source component/sheet labels as a valid source-sheet boundary
Smallest general implementation change: validate every internal curved-disk local boundary edge against existing source labels; accept it only when hard-feature authority applies or the opposite incident source face belongs to a different authoritative component/sheet, while continuing to reject hidden same-component/same-sheet cuts
Observable material-progress condition: exact torus advances beyond InvalidBoundedDiskTopology caused solely by non-hard source-sheet boundaries to Produced/materialization or the next deeper truthful typed invariant; curved-disk 6/6, sheet-coverage 3/3, G4 relation 5/5, G0-G3 17/17 and direct hashes remain unchanged
Explicitly deferred: harmonic chart/boundary-phase/front-pairing repair until runtime reaches those invariants, generic arrangement/completion repair, prescribed sphere until torus materialization closes, G5 adaptivity/features, G6 bunny/vase production, historical completion/simplification failures, validator changes, feature demotion, Euclidean welding and unrelated optimization
```

## Next-turn execution

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Plan.md` as **Code + Build only**.

Required properties:

- preserve genuine source-boundary and hard-feature internal boundary behavior;
- for a non-hard internal local boundary, use existing authoritative source component/sheet labels to distinguish a valid cross-sheet/cross-component boundary from an invalid hidden same-sheet cut;
- preserve exact source edge/face/component/sheet provenance;
- do not mutate the source classifier or hard-feature set to force acceptance;
- preserve existing planar bounded, periodic-annulus and curved-disk producer semantics;
- preserve complete exact-once source-sheet aggregation and canonical periodic relation authority;
- fail typed at the next genuine boundary-phase/chart/front-pairing/materialization invariant if encountered;
- add compile-only regressions for valid non-hard cross-sheet boundary authority, invalid same-sheet hidden cut, hard-boundary retention, row-order invariance, mixed producer composition and exact torus advancement;
- compile/package the same seven approved Release/static/Ninja targets;
- **execute no generated Directional binary/test/benchmark/ctest/CLI/GUI/help/list/discovery command**.

The following Test + Benchmark turn must first run the new boundary-authority semantics, then retain curved-disk 6/6, sheet-coverage 3/3, G4 relation 5/5, G0-G3 17/17 and direct hashes before exact torus decides progress.

Preferred torus result is complete authoritative phase-front `Produced`, exact materialization and strict-valid pure-quad closed output. A deeper deterministic typed boundary-phase/chart/front-pairing/materialization failure is acceptable material progress only when non-hard cross-sheet boundary authority is proven live and no generic fallback path substitutes for authority.

Prescribed sphere remains deferred until torus source-sheet coverage/materialization closes.

## Lessons that must not be repeated

- A test expectation is not production authority; verify that its fixture naturally creates the claimed structural witness.
- Raw source/DCEL numeric IDs are not stable semantic identities; use canonical topology and source ownership.
- A topologically plausible route is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- Connector-created text payload authority is the committed Git blob; verify decoded patch content/hash separately.
- GoogleTest macro expressions containing template commas require extra expression parentheses; do not confuse syntax failures with production semantics.
- Packaged tests may carry Actions absolute fixture paths; artifact-only validation may expose immutable packaged fixtures through a recorded runtime-only symlink, never by patching artifact bytes.
- Canonical periodic topology signatures are 64-bit; preserve the `std::vector<std::uint64_t>` structural-hash path.
- Multiple periodic relations can belong to distinct authoritative source sheets; do not invent a same-sheet homology basis without source-topology evidence.
- A partially accumulated phase-front is not whole-surface authority; never fix coverage by merely flipping disposition to `Produced`.
- The torus's hard-feature rails are source-derived authority; do not demote them to simplify chart topology.
- Source-sheet boundaries are not synonymous with hard-feature edges. The classifier can create authoritative sheet separation through normal compatibility and close/opposing-sheet logic.
- Observed face IDs, sheet counts, relation counts and boundary lengths are diagnostics, not implementation or acceptance keys.
- A focused hard-boundary test does not prove broader source-sheet boundary coverage; include a naturally non-hard cross-sheet boundary witness.
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
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. The just-completed artifact-only turn established material progress, so this counter resets to 0.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Current hygiene must be verified before the final turn comment. Expected state: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent.

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

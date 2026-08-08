# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Test + Benchmark — artifact-only G4 curved bounded disk-sheet validation**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the current runtime report `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`, the current compile report `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Report.md`, the authoritative artifact-only plan above, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Test+Benchmark/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Current runtime-proven artifact: **`9015931928`** (`g4-sheet-coverage-code-build`)  
Workflow run/job: `31237248211 / 93051938159`  
Implementation: `856554ce648e5df09ac50f5c94e3e8f098181524`  
Runtime-proven production source: `a647215b4993338b054f04d4c8e54e7ef5370001`

Runtime authority:

- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- plane hash `730caeae49ec872c`, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close-sheets hash `89b052762f52a5af`, 200 quads / 242 vertices / two components, deterministic 3/3;
- cylinder `Produced / CompletedSurfaceCells`, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, exactly two genuine 32-edge exterior loops, hash `32135be51d7a0a26`, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery;
- bounded suites: producer **107/108** (only existing sub-millisecond validator-overhead performance threshold), completion/simplification **154/164** (same ten historical failures), validation **60/60**, API **8/8**, aggregate **329/340**.

Exact torus under this runtime authority is deterministic 3/3:

- producer `Rejected` at `tracing/phase-front`;
- reason `UnsupportedSourceSheetTopology`;
- three retained periodic relations;
- zero downstream generic tracing/arrangement/completion after rejection;
- terminal `NotProductionReady:tracing`;
- no output/fallback/legacy substitution/input return/source-grid recovery.

Read-only topology analysis shows the authoritative torus partition contains three χ=0 periodic-annulus sheets and two non-planar χ=1 single-boundary disks. The torus's 48 hard edges / four closed feature curves remain authoritative. The observed failing face, sheet/relation counts and boundary lengths are diagnostic evidence only and may never become production ownership/branching keys.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`.

## Completed curved-disk Code + Build candidate

Exact compile artifact: **`9016834575`** (`g4-curved-disk-code-build`)  
Workflow run/job: **`31240168780 / 93059691196`**  
Implementation commit: **`90046be649a0fd051e6c44eceec07198dc542c29`**  
Payload cleanup: **`508211936b790dfb40cdbece7900bb0522368b76`**  
Entering runtime source: `a647215b4993338b054f04d4c8e54e7ef5370001`

Artifact authority:

- outer ZIP SHA-256 **`6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`**;
- internal `SHA256SUMS` SHA-256 **`e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`**;
- recursive checksums **48/48**;
- 49 total files / 27 fixtures / five executables / two project static libraries;
- seven approved Release/static/Ninja targets **111/111**;
- log artifact `9016834752`, SHA-256 `6e0ed0906bc9f935ac80b6d8fd40f0654f203020a7b7c6cde6d9a4e49b067db1`;
- `runtimeExecution=false`, review policy `never`.

Final packaged source blobs:

- `include/directional/geometry/SurfaceCellTracing.h` `998d8bc46faf6d590cb1674c4f5b2e290f94c48e`;
- `src/geometry/SurfaceCellTracing.cpp` `3363e20c33a6850c192249877e7cb4488fc36597`;
- `src/pipeline/RemeshPipeline.cpp` `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
- `tests/SurfaceCellsPhase10Tests.cpp` `fe7ce43466cc3bc852b36c0ea8b8de6aac0c5b64`.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Report.md`.

## Candidate implementation contract

The new sheet-local producer is structurally applicable to connected χ=1 source sheets with one genuine source/hard-feature boundary. It does not recognize torus IDs/counts.

It:

- validates reciprocal 4-RoSy transport over the simply connected sheet using existing edge-transition authority;
- classifies the single ordered boundary into cyclic U+/V+/U-/V- families from transported field alignment;
- maps boundary sides intrinsically by source-edge arc length;
- solves a harmonic/Tutte interior chart with Eigen sparse Cholesky and rejects invalid/inverted chart triangles;
- samples target-size lattice crossings in chart space and maps them to exact source triangles;
- derives segment family/sign from the propagated reciprocal gauge;
- preserves exact source component/sheet/hard-feature boundary ownership;
- pairs internal fronts structurally and permits exterior termination only on the authoritative local boundary;
- creates no periodic relation for a disk and preserves existing annulus relation authority;
- runs after the existing planar bounded and periodic-annulus producers and before aggregate unsupported-sheet classification.

New typed reasons are `InvalidBoundedDiskTopology`, `InvalidBoundedDiskTransport`, `InvalidBoundedDiskBoundaryPhase`, `InvalidBoundedDiskChart`, and `InvalidBoundedDiskFrontPairing`.

Compile-only tests were added for curved-disk applicability, face-row invariance, hard-boundary preservation, invalid reciprocal transport, planar+periodic+curved composition, and exact torus advancement. **None has run yet.**

## Exact next-turn execution declaration

Before runtime execution state:

```text
Turn type: Test + Benchmark only
Exact artifact: 9016834575 (g4-curved-disk-code-build), workflow run/job 31240168780 / 93059691196
Runtime candidate source authority: implementation 90046be649a0fd051e6c44eceec07198dc542c29, cleanup 508211936b790dfb40cdbece7900bb0522368b76
No-build boundary: do not edit production/tests/fixtures/validators/benchmarks/build files and do not configure, compile, link, regenerate discovery, or rebuild
First correctness check: verify artifact/source/blobs/checksums, then run new curved-disk semantic tests; retain sheet-coverage 3/3, G4 relation 5/5 and G0-G3 17/17
Direct regression gate: plane, seam, close sheets and cylinder must retain exact strict-valid deterministic prior hashes with no fallback/recovery
Primary G4 observation: exact torus must no longer fail merely as UnsupportedSourceSheetTopology; record Produced/materialization/output authority or the exact deeper typed bounded-disk/phase-front/materialization invariant
Acceptable material progress: direct strict-valid torus output, or a deeper truthful deterministic typed failure only when the curved-disk producer is demonstrably live, canonical periodic relation authority remains intact, and no generic/fallback path substitutes for authority
Deferred: prescribed sphere unless torus sheet coverage/materialization closes; G5 adaptivity/features; G6 bunny/vase production; historical unrelated completion/simplification repair
```

Follow `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Plan.md` exactly.

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
- Observed face IDs, sheet counts, relation counts and boundary lengths are diagnostics, not implementation or acceptance keys.
- Harmonic chart compilation is now proven, but its injectivity/boundary-phase behavior is a runtime question. Do not infer success from compilation.
- A downstream completion failure is not automatically the next target; follow the first truthful producer/materialization failure.
- Timeout is failure only; never infer correctness/disposition from incomplete execution.

## Turn boundary — mandatory

Authoritative cadence:

`Code + Build -> Test + Benchmark -> [Optional Review] -> Code + Build`.

Never combine turn types.

- Code + Build may edit/configure/compile/link approved targets, but may not execute generated project binaries/tests/benchmarks/ctest/CLI/GUI/help/list/discovery.
- Test + Benchmark executes the exact built artifact and may not edit production/test/fixture/validator/benchmark/build source or configure/compile/relink/regenerate a replacement.
- Review is optional. Review policy is currently `never`; after Test + Benchmark its next Code + Build plan becomes authoritative when G4 remains open.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. The preceding artifact-only turn established material progress; this is the first Code + Build since then.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

The current Code + Build removed its bounded workflow before its trigger, and its payload was removed after source authority was committed. Verify final hygiene again at the beginning of the Test + Benchmark turn.

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

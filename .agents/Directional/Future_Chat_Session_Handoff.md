# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Test + Benchmark — artifact-only G4 source-sheet-boundary authority validation**  
Authoritative next plan: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the current runtime report `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`, the current compile report `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Report.md`, the authoritative artifact-only plan above, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the relevant turn-based-coding-agent Test+Benchmark/testing-integrity/recovery/handoff/GitHub-workflow references.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Current runtime-proven artifact: **`9016834575`** (`g4-curved-disk-code-build`)  
Workflow run/job: `31240168780 / 93059691196`  
Implementation: `90046be649a0fd051e6c44eceec07198dc542c29`  
Cleanup: `508211936b790dfb40cdbece7900bb0522368b76`

Runtime authority:

- curved-disk semantics **6/6**;
- sheet-coverage semantics **3/3**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**;
- plane hash `730caeae49ec872c`, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close-sheets hash `89b052762f52a5af`, 200 quads / 242 vertices / two components, deterministic 3/3;
- cylinder `Produced / CompletedSurfaceCells`, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, 288 pure quads / 320 vertices, zero validation failures, exactly two genuine 32-edge exterior loops, hash `32135be51d7a0a26`, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery;
- bounded suites: producer **112/113** (only the existing sub-millisecond validator-overhead threshold), completion/simplification **154/164** (same ten historical failures), validation **60/60**, API **8/8**, aggregate **334/345**.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`.

Exact torus under this runtime authority is deterministic 3/3:

- producer `Rejected` at `tracing/phase-front`;
- reason `InvalidBoundedDiskTopology`;
- no downstream generic tracing/arrangement/completion after rejection;
- terminal `NotProductionReady:tracing`;
- no output/fallback/legacy substitution/input return/source-grid recovery.

Read-only source diagnosis proves the first blocker is not unsupported curved-disk topology anymore: the curved-disk producer currently accepts an internal local boundary only when it is hard, while authoritative source-sheet classification may create a valid local boundary across a non-hard internal source edge because the opposite face belongs to a different source component/sheet. Observed raw face IDs, relation counts, sheet counts, and boundary lengths are diagnostic evidence only and may never become production ownership/branching keys.

## Completed source-sheet-boundary Code + Build candidate

Exact compile artifact: **`9019024467`** (`g4-source-sheet-boundary-code-build`)  
Workflow run/job: **`31247546780 / 93078496378`**  
Event commit: `ccb9aa0db15a575f31b802a354ccf8b0aabe111c`  
Implementation commit: **`b425898fa7367406fa0c07e8f4441a37efc01315`**  
Payload cleanup: **`3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`**

Artifact authority:

- outer ZIP SHA-256 **`a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`**;
- internal `SHA256SUMS` SHA-256 **`7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`**;
- recursive checksums **48/48**;
- 49 total files / 27 fixtures / five executables / two project static libraries;
- seven approved Release/static/Ninja targets **111/111**;
- log artifact `9019024673`, SHA-256 `243943268324a24e5fd04a42fed706b274a8525f5c2f157bf246b5028e42f03c`;
- `runtimeExecution=false`, review policy `never`.

Final packaged source blobs:

- `include/directional/geometry/SurfaceCellTracing.h` `ddb8e211f073d15fcfcc6782f964f88c4dedfc5e`;
- `src/geometry/SurfaceCellTracing.cpp` `14cf7f3a3301e9e3f10ec48a480d3f6e5efee7ed`;
- `src/pipeline/RemeshPipeline.cpp` `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
- `tests/SurfaceCellsPhase10Tests.cpp` `31322acea5227a8e3692887fad1ec4a9e6d8c101`.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Report.md`.

## Candidate implementation contract

`source_edge_is_authoritative_local_boundary()` now validates curved-disk local source boundaries structurally:

- malformed incidence / invalid local-face identity fails closed;
- a genuine source boundary is valid;
- a hard-feature internal source edge is valid;
- a non-hard internal source edge requires valid source component/sheet labels and is valid only when the opposite incident source face is not `source_faces_compatible()` with the local face;
- a hidden non-hard same-component/same-sheet internal cut remains invalid.

The curved-disk producer uses this predicate for its local boundary. Source classifier behavior, hard-feature authority, planar/periodic producers, periodic relations, exact-once source-sheet aggregation, validators and fallback/recovery semantics remain unchanged.

Compile-only semantic additions:

1. `CurvedBoundedDiskAcceptsNonHardAuthoritativeSourceSheetBoundary`;
2. `CurvedBoundedDiskRejectsHiddenSameSheetBoundaryCut`;
3. `CurvedBoundedDiskCrossSheetBoundaryIsInvariantToFaceRowEnumeration`;
4. exact torus producer-boundary assertion also forbids terminal `InvalidBoundedDiskTopology` for this boundary class.

The positive and negative controls share the same physical source edge/topology; only existing authoritative source-sheet labels distinguish the valid cross-sheet rail from an invalid hidden same-sheet cut. **None has run yet.**

## Exact next-turn execution declaration

Before runtime execution state:

```text
Turn type: Test + Benchmark only
Exact artifact: 9019024467 (g4-source-sheet-boundary-code-build), workflow run/job 31247546780 / 93078496378
Runtime candidate source authority: implementation b425898fa7367406fa0c07e8f4441a37efc01315, cleanup 3fcfd2cf2996919eed5c951a9148d83deb5aa6f8
No-build boundary: do not edit production/tests/fixtures/validators/benchmarks/build files and do not configure, compile, link, regenerate discovery, or rebuild
First correctness check: verify artifact/source/blobs/checksums, then run the three new source-sheet-boundary semantic tests; retain prior curved-disk 6/6, sheet-coverage 3/3, G4 relation 5/5 and G0-G3 17/17
Direct regression gate: plane, seam, close sheets and cylinder must retain exact strict-valid deterministic prior hashes with no fallback/recovery
Primary G4 observation: exact torus must advance beyond InvalidBoundedDiskTopology caused solely by a non-hard authoritative cross-sheet boundary; record Produced/materialization/output authority or the exact deeper truthful typed bounded-disk/phase-front/materialization invariant
Acceptable material progress: direct strict-valid torus output, or a deeper truthful deterministic typed failure only when non-hard cross-sheet boundary authority is demonstrably live, canonical periodic relation authority remains intact, and no generic/fallback path substitutes for authority
Deferred: prescribed sphere unless torus materialization closes; G5 adaptivity/features; G6 bunny/vase production; historical unrelated completion/simplification repair
```

Follow `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Plan.md` exactly.

## Transport/build lesson from this turn

Two remote attempts failed before source modification or compilation because manually copied compressed/base64 transport did not preserve the intended byte stream. The successful path used six plain raw unified-patch text chunks; every part matched its expected Git blob and SHA-256, the concatenated raw patch matched `c96b3d73f16f4b9391505380bc3f2cf9ec95ff5783fe843b556e95a534a6e75b`, and only then was it applied. For connector-mediated source transfer, prefer independently verifiable raw text chunks rather than manually copied compressed/base64 payloads.

## Lessons that must not be repeated

- A test expectation is not production authority; verify that its fixture naturally creates the claimed structural witness.
- Raw source/DCEL numeric IDs are not stable semantic identities; use canonical topology and source ownership.
- A topologically plausible route is not field-authoritative merely because it is first/lexicographically minimal.
- Endpoint tolerance may not emit tolerance-expanded geometry; canonicalize to exact source-simplex geometry.
- Connector-created text payload authority is the committed Git blob; verify transferred patch content/hash separately before application.
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
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. The preceding artifact-only turn established material progress; this is the first Code + Build since then.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

Current successful Code + Build removed all patch payload files in cleanup commit `3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`, then removed bounded workflow before trigger after artifact verification. Verify final hygiene again at the beginning of the Test + Benchmark turn.

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

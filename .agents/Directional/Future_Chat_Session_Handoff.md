# Future Chat Session Handoff — Directional Surface Cells

## Resume here

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8 — keep **open, draft, unmerged**  
Review policy: `never`  
Active gate: **G4 topology-distinct completion and singularities**  
Next turn: **Test + Benchmark — source-topology-region / isolation-sheet decoupling artifact-only validation**  
Authoritative next plan: `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Plan.md`

Read this handoff first, then `TODO`, `MILESTONE_G_TODO.md`, `.agents/Directional/DESIGN.md`, the current runtime report `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`, the latest compile report `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Report.md`, the authoritative artifact-only plan above, `tests/TESTING_STRATEGY.md`, `.agents/Directional/GitHub_Workflow_Policy.md`, and the turn-based-coding-agent Test+Benchmark/testing-integrity/recovery/handoff/GitHub-workflow references. Load the integrated unit-testing module for diagnosis if a unit-test fixture/expectation fails; do not edit test source in the Test + Benchmark turn.

## Current tested authority

G0, G1, G2, and **G3 are passed**. G4 remains **active**.

Current runtime-proven artifact: **`9021175280`** (`g4-polygonal-boundary-phase-code-build`)  
Workflow run/job: **`31254896323 / 93096734152`**  
Implementation: **`085db9ec23ffaa509b1f5a29e72968229efa103d`**  
Payload cleanup: **`c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`**

Runtime authority:

- outer ZIP SHA-256 `16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`;
- internal manifest SHA-256 `a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`;
- recursive checksums **48/48**;
- generalized polygonal boundary phase **5/5**;
- preceding local-isolation/source-sheet semantics **3/3**;
- retained non-torus curved-disk semantics **5/5**;
- sheet coverage **3/3**;
- G4 periodic relations **5/5**;
- retained G0-G3 **17/17**;
- plane hash `730caeae49ec872c`, 64 quads / 81 V, deterministic 3/3;
- seam hash `5bdf34d7802e9fb0`, 64 quads / 81 V, deterministic 3/3;
- close sheets hash `89b052762f52a5af`, 200 quads / 242 V / two components, deterministic 3/3;
- cylinder hash `32135be51d7a0a26`, 288 pure quads / 320 V, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, exactly two genuine 32-edge exterior loops, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery;
- bounded suites producer **119/121**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **341/353**.

Exact torus under current runtime authority is deterministic 3/3:

- producer `Rejected`;
- stage `tracing/phase-front`;
- reason **`InvalidBoundedDiskBoundaryTurn`**;
- bounded-disk phase/run/polygon/chart counts all zero;
- phase hashes empty;
- periodic authority remains live;
- zero downstream cells/output;
- no fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Report.md`.

Runtime-only fixture symlink used by that prior turn:
`/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_polygonal_runtime_9021175280/test-data/benchmarks/fixtures`.

## New exact compile candidate — artifact 9022061741

Exact candidate artifact: **`9022061741`** (`g4-topology-region-code-build`)  
Workflow run/job: **`31258107220 / 93104542559`**  
Workflow event commit: `806a557c39170d12b172ef6930794711e00e63bc`  
Implementation commit: **`3ca89ab55efff461b050fb12033174be70e7464f`**  
Payload cleanup: **`b188dd37f01181ece2173879fc7e0accf23d1bad`**

Artifact authority:

- outer ZIP SHA-256 **`df23a89f26d0769fa3433bf8996d2d090eaa82770ddc52a52018e51286087306`**;
- internal `SHA256SUMS` SHA-256 **`d80559fab82a359f7ce5ccfe109069765d18f5d440824106d84d70c5b8822703`**;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two project static libraries;
- successful Release/static/Ninja build **111/111**;
- log artifact `9022061947`, SHA-256 **`8a7c5271791a1e8182d4ff2b0d5d32ebfe6e47f6e36661ba5b431f00f898256d`**;
- decoded raw patch SHA-256 **`1c3488b672e25c698451df46081fa951d8c4d883136ff30f88cece0dcadd194b`**;
- `runtimeExecution=false`, review policy `never`.

Final packaged source blobs:

- diagnostics header `ba33d8396bd26f8190f8d552aafd9c950e9a3842`;
- tracing header `e966a9ab9dc33f23de9cecb3fd9b61ddd75fde7f`;
- benchmark source `ba3eb47bfe9f3f78ce1dcbab32bfb3a773658cfc`;
- tracing source `b3f0ea3b82cf64f3a2ba312f9622172c64bc3e83`;
- pipeline source `97a20e41338b616d6bb5cafaa5f3d3851c52c583`;
- Phase 10 tests `441ba7fe2066355ce2a2239380f45029ea139346`.

Submodules: Eigen `769c72fd8019e389810d1de1e7c243521a43b594`, googletest `3940de91897160fea4815998e08d0fa3c2fb077e`, polyscope `59da72df6517cab8379865899bdffdbc96171301`.

Detailed compile record: `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Report.md`.

## Candidate implementation contract

The candidate decouples producer topology from local geometric isolation.

`SurfaceTopologyRegion` records exact source faces, source component, Euler characteristic, genuine boundary-loop count, exact boundary topology, internal isolation-seam topology, local isolation labels, and a structural hash.

Topology regions:

- traverse only exact source-face adjacency;
- do not cross different source components, hard features, or embedded relief barriers;
- do cross a non-hard exact shared edge even when local isolation labels differ;
- never derive connectivity from Euclidean proximity, nearest projection, counts, IDs, frequency, topology score, boundary length, or arbitrary subset search.

A non-hard exact-adjacent cross-sheet edge inside one region is an **internal isolation seam**. It is not an exterior bounded-disk rail. Phase transport across it still requires exact source routing and reciprocal transition authority; malformed/nonreciprocal transport fails typed `InvalidTopologyRegionTransport`.

Producer applicability/topology, Euler/boundary classification, periodic/disk selection, and exact-once aggregation now operate by topology region. Local isolation labels remain first-class provenance and still protect proximity/capture/projection operations. Source-disconnected close sheets remain separate regions.

Periodic relation identity, cells/fronts/phases, trace-network hashing, memory accounting, and diagnostics carry topology-region plus local-isolation provenance. Runtime diagnostics expose region count, internal seam count, region hashes, Euler characteristics, genuine boundary-loop counts, and isolation-label cardinalities.

Compile-only corrected/added regressions include:

1. `ExactAdjacentCrossSheetEdgeIsInternalTopologyRegionIsolationSeam`;
2. `SameSheetInternalEdgeIsNeitherBoundaryNorIsolationSeam`;
3. `TopologyRegionIsolationSeamIsInvariantToFaceRowEnumeration`;
4. `ClassifierSplitAnnulusRemainsOneSourceTopologyRegion`;
5. `ClassifierSplitAnnulusTopologyRegionIsRowOrderInvariant`;
6. `HardFeatureCannotBeReinterpretedAsInternalIsolationSeam`;
7. `SourceDisconnectedCloseSheetsRemainSeparateTopologyRegions`;
8. `ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`;
9. `NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
10. `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`.

**None has executed yet.** The prior cross-sheet fixture expectation was corrected because the exact shared non-hard edge is an internal isolation seam, not a physical exterior rail; this is not assertion weakening.

## Exact next-turn execution declaration

Before any packaged Directional binary executes state:

```text
Turn type: Test + Benchmark only
Exact artifact: 9022061741 (g4-topology-region-code-build), workflow run/job 31258107220 / 93104542559
Runtime candidate source authority: implementation 3ca89ab55efff461b050fb12033174be70e7464f, cleanup b188dd37f01181ece2173879fc7e0accf23d1bad
No-build boundary: do not edit production/tests/fixtures/validators/benchmarks/build files and do not configure, compile, link, regenerate discovery, or rebuild
First correctness check: verify artifact/source/blobs/checksums, then run topology-region / isolation-seam structural semantics first
Regression gate: retain polygonal boundary phase, valid curved-disk/isolation, sheet coverage, G4 periodic relations, retained G0-G3 and exact direct plane/seam/close-sheets/cylinder hashes with no fallback/recovery
Primary G4 observation: exact torus must prove topology-region authority is constructed and consumed and must no longer fail merely because a non-hard classifier isolation seam is treated as a bounded-disk exterior turn
Material-progress rule: compile success is not runtime progress; if this exact artifact also fails to establish material progress, no further ordinary Code + Build is authorized before mandatory design review or bounded producer-replacement proof
Deferred: prescribed sphere unless torus direct strict-valid production closes; G5/G6; historical completion/simplification repair; validator/performance threshold changes; fallback/recovery and unrelated optimization
```

Follow `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Plan.md` exactly.

## No-progress process state

The preceding artifact-only turn established **one** Code + Build without material runtime progress. This compile-only turn does not itself increment or reset runtime progress authority; the exact following validation decides the process transition.

- If artifact `9022061741` establishes material progress, review remains skipped (`never`) and the Test + Benchmark report's proposed next Code + Build plan becomes authoritative.
- If it does **not**, do not authorize another ordinary Code + Build. Mandatory design review or bounded producer-replacement proof is required before another ordinary implementation iteration.

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
- Review is optional. Review policy is currently `never`; after Test + Benchmark its next Code + Build plan is authoritative.
- Build and runtime claims require exact pushed/evidence commit and artifact authority.
- Direct mandatory fixture/gate evidence outranks aggregate totals.
- Two consecutive Code + Build turns without material progress require mandatory design review or bounded producer-replacement proof. Current runtime-proven no-progress count is **1**; artifact `9022061741` validation decides whether that rule activates.

## Workflow/temp cleanup — mandatory

1. inspect `.github/workflows`, `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` at start and end;
2. remove stale bounded workflows;
3. during remote execution retain the durable workflow plus at most one bounded workflow/payload when genuinely needed;
4. after artifact/log/source/blobs/build or runtime authority is verified remove the bounded workflow, trigger and payload;
5. final workflow state must contain only approved durable workflow state and no stale artifact/trigger debris;
6. do not remove a durable dependency required by normal repository operation;
7. retain payload/source-transfer data until its authority is verified, then remove it.

The successful topology-region Code + Build removed its six raw payload files in cleanup commit `b188dd37f01181ece2173879fc7e0accf23d1bad`, then removed the bounded workflow before its trigger after artifact verification. Expected final state: `.github/workflows` contains only `agent-source-snapshot.yml`; `.agents/connector-triggers`, `.github/agent-triggers`, and `.agents/Directional/turn-payloads` are absent. Verify again at the beginning and end of the Test + Benchmark turn.

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

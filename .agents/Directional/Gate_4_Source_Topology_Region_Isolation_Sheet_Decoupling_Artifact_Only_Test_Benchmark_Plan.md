# Gate 4 Source Topology Region / Isolation Sheet Decoupling — Artifact-Only Test + Benchmark Plan

Status: **authoritative next turn**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Exact artifact authority

Use only GitHub Actions artifact:

- artifact ID **`9022061741`**;
- name `g4-topology-region-code-build`;
- workflow run/job **`31258107220 / 93104542559`**;
- workflow event commit `806a557c39170d12b172ef6930794711e00e63bc`;
- implementation commit **`3ca89ab55efff461b050fb12033174be70e7464f`**;
- payload cleanup commit **`b188dd37f01181ece2173879fc7e0accf23d1bad`**;
- outer ZIP SHA-256 **`df23a89f26d0769fa3433bf8996d2d090eaa82770ddc52a52018e51286087306`**;
- internal `SHA256SUMS` SHA-256 **`d80559fab82a359f7ce5ccfe109069765d18f5d440824106d84d70c5b8822703`**;
- recursive checksums **48/48**;
- package **49 files / 27 fixtures / five executables / two project static libraries**;
- log artifact **`9022061947`**, SHA-256 **`8a7c5271791a1e8182d4ff2b0d5d32ebfe6e47f6e36661ba5b431f00f898256d`**;
- artifact metadata `runtimeExecution=false`, review policy `never`.

Final packaged source blobs:

- `include/directional/diagnostics/RemeshDiagnostics.h` `ba33d8396bd26f8190f8d552aafd9c950e9a3842`;
- `include/directional/geometry/SurfaceCellTracing.h` `e966a9ab9dc33f23de9cecb3fd9b61ddd75fde7f`;
- `src/bench/DirectionalBenchmark.cpp` `ba3eb47bfe9f3f78ce1dcbab32bfb3a773658cfc`;
- `src/geometry/SurfaceCellTracing.cpp` `b3f0ea3b82cf64f3a2ba312f9622172c64bc3e83`;
- `src/pipeline/RemeshPipeline.cpp` `97a20e41338b616d6bb5cafaa5f3d3851c52c583`;
- `tests/SurfaceCellsPhase10Tests.cpp` `441ba7fe2066355ce2a2239380f45029ea139346`.

Do **not** rebuild, configure, relink, regenerate discovery, patch packaged source, alter packaged fixtures, or substitute another artifact.

## Turn boundary

Allowed:

- download/unpack exact artifact `9022061741`;
- verify outer digest, recursive manifest, source blobs, dependencies, fixtures, and command-boundary metadata;
- execute only packaged binaries and immutable packaged inputs;
- create a recorded runtime-only fixture-path symlink if the packaged tests retain an Actions absolute fixture path;
- capture logs, diagnostics, structural hashes, output topology, wall time and peak memory;
- inspect immutable packaged source/fixtures read-only for diagnosis;
- update documentation and PR metadata after runtime evidence is complete.

Forbidden:

- production/test/fixture/validator/benchmark/build-system edits;
- configure/compile/link/rebuild/discovery regeneration;
- validator or threshold weakening;
- local-sheet unions by counts, IDs, frequency, topology score, boundary length, proximity, or arbitrary subsets;
- Euclidean/proximity connection of source-disconnected sheets;
- feature/barrier demotion;
- allowing cross-sheet transport without exact source adjacency and reciprocal transition authority;
- fallback/recovery or source-grid recovery as passing authority;
- synthetic topology/Euler/closing-edge correction;
- fixture-specific success branches;
- post-hoc topology/cell merging;
- timeout-as-correctness inference.

## Step 1 — static integrity before runtime

Before executing any packaged Directional binary verify:

1. exact artifact ID/name/run/job and outer ZIP digest;
2. internal manifest digest and **48/48** recursive checksums;
3. cardinality 49 files / 27 fixtures / five executables / two libraries;
4. metadata records implementation `3ca89ab5...`, cleanup `b188dd37...`, entering runtime artifact `9021175280`, raw patch digest `1c3488b6...`, `runtimeExecution=false`, and review `never`;
5. command-boundary evidence proves no generated Directional runtime executed during Code + Build;
6. all six packaged source blobs match the values above;
7. dependency revisions are Eigen `769c72fd...`, googletest `3940de91...`, polyscope `59da72df...`;
8. fixture closure is present.

If authority fails, classify infrastructure failure and stop. Do not create a replacement build.

## Step 2 — topology-region / isolation-seam semantics first

Run these newly corrected/added structural cases before retained groups:

1. `SurfaceCellsPhase10.ExactAdjacentCrossSheetEdgeIsInternalTopologyRegionIsolationSeam`;
2. `SurfaceCellsPhase10.SameSheetInternalEdgeIsNeitherBoundaryNorIsolationSeam`;
3. `SurfaceCellsPhase10.TopologyRegionIsolationSeamIsInvariantToFaceRowEnumeration`;
4. `SurfaceCellsPhase10.ClassifierSplitAnnulusRemainsOneSourceTopologyRegion`;
5. `SurfaceCellsPhase10.ClassifierSplitAnnulusTopologyRegionIsRowOrderInvariant`;
6. `SurfaceCellsPhase10.HardFeatureCannotBeReinterpretedAsInternalIsolationSeam`;
7. `SurfaceCellsPhase10.SourceDisconnectedCloseSheetsRemainSeparateTopologyRegions`;
8. `SurfaceCellsPhase10.ExactReciprocalTransportCrossesSourceAdjacentIsolationSeam`;
9. `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`.

Required semantics:

- exact non-hard source adjacency can connect different local isolation labels inside one producer topology region;
- that seam is not an exterior bounded-disk rail;
- same-sheet arbitrary internal cuts remain neither authoritative boundary nor isolation seam;
- a classifier-split annulus remains one topology region with Euler characteristic 0 and two genuine producer boundaries;
- region topology and structural identity are invariant to face-row re-enumeration;
- hard features split/terminate region transport and cannot become traversable isolation seams;
- source-disconnected close sheets remain separate regions;
- valid reciprocal cross-sheet transport preserves topology-region and local-isolation provenance;
- malformed/nonreciprocal cross-sheet transport fails typed `InvalidTopologyRegionTransport`.

The synthetic fixture's exact counts are justified only by its independently constructed topology; they are never torus/arbitrary-mesh production keys.

If a focused case fails, diagnose the actual fixture/contract but do not edit it in this turn.

## Step 3 — retain polygonal, curved-disk, periodic and G0-G3 authority

Rerun the five runtime-proven polygonal boundary-phase cases:

1. `ExistingRectangularCurvedDiskRetainsExactBoundaryPhaseFastPath`;
2. `PolygonalCurvedDiskBuildsFieldAuthoritativeSixRunPhaseAndChart`;
3. `PolygonalCurvedDiskInvalidCyclicFieldTurnFailsClosed`;
4. `PolygonalCurvedDiskBoundaryPhaseIsInvariantToFaceRowEnumeration`;
5. `PolygonalCurvedDiskRetainsPeriodicAuthorityWithoutPartialSheetCells`.

Entering baseline: **5/5**.

Also retain all non-overlapping prior curved-disk semantics whose contracts remain valid, including structural curved-disk applicability, row-order invariance, hard-boundary provenance, invalid reciprocal transport fail-closed behavior, and mixed planar/periodic/curved producer composition.

Then retain:

- sheet-coverage contracts **3/3** entering baseline;
- G4 periodic-relation contracts **5/5** entering baseline;
- retained G0-G3 focused contracts **17/17** entering baseline.

Do not require old test names that were intentionally corrected from “cross-sheet exterior boundary” to “internal isolation seam.” Compare semantic authority, not obsolete naming.

Any regression in prior valid authority blocks G4 progress regardless of torus movement.

## Step 4 — direct G0-G3 deterministic regression matrix

Use direct `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and the same source-authoritative options as the current runtime authority.

Run three independent processes per fixture and require exact established baselines:

| Fixture | Required result | Output | Required hash |
|---|---|---:|---|
| plane | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `730caeae49ec872c` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `5bdf34d7802e9fb0` |
| close sheets | `Produced / CompletedSurfaceCells` | 200 quads / 242 V / two components | `89b052762f52a5af` |
| cylinder | `Produced / CompletedSurfaceCells` | 288 pure quads / 320 V | `32135be51d7a0a26` |

Cylinder must retain one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4; 1,728 traces; 290 arrangement/simplified cells; zero validation failures; exactly two genuine exterior 32-edge annulus loops; no artificial-cut exterior seam; no fallback/recovery.

Close sheets must remain two source-disconnected output components. The new region architecture must not join them merely because they are geometrically near.

Do not update a baseline because the candidate differs.

## Step 5 — exact torus mandatory G4 decision

Run committed `milestone-g/torus.obj` + `torus.rawfield` through the direct production pipeline with `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled. Run at least three independent processes when each completes inside the bounded observation window.

Record all diagnostics actually exposed:

- producer disposition and first invalid stage/reason;
- topology-region count;
- internal isolation-seam count;
- topology-region structural hashes;
- per-region Euler characteristics;
- per-region boundary-loop counts;
- per-region isolation-sheet cardinalities;
- bounded-disk phase/run/polygon/chart counts and phase hashes;
- periodic relation cardinality and only relation details actually serialized;
- trace/embedding/arrangement/simplification/completion/output counts;
- output topology, strict validation, provenance and structural hash when output exists;
- fallback/recovery/output origin;
- stage hashes, determinism, wall time and peak memory.

Do not infer unreported source IDs, per-region membership, per-run labels, relation details, or chart state.

### Material-progress condition

Entering torus blocker under artifact `9021175280`:

`Rejected / InvalidBoundedDiskBoundaryTurn` because a non-hard classifier isolation seam is treated as a bounded-disk exterior corner; no first-class phase record is retained.

Material progress requires all of:

- runtime diagnostics prove source-topological region authority is constructed and consumed;
- at least one topology region containing multiple local isolation labels exposes real internal isolation-seam authority when structurally present;
- torus no longer fails because that non-hard exact-adjacent classifier seam is interpreted as an exterior bounded-disk turn;
- hard-feature and periodic authority remain live;
- no Euclidean/proximity merge, feature demotion, fallback/recovery, arbitrary sheet union, or synthetic topology correction occurs;
- retained focused/direct authority remains intact.

Preferred result is direct strict-valid pure-quad torus production.

A genuinely deeper periodic, region-coverage, boundary/chart/front-pairing, or materialization failure is acceptable material progress only when the new topology-region authority is runtime-visible and the failure is structurally truthful. Do not rename or weaken a later invariant merely to advance.

`InvalidTopologyRegion` or `InvalidTopologyRegionTransport` is not automatically a regression or progress. Inspect exact structural evidence. If it reveals malformed/nonreciprocal source transport, report it truthfully. If it merely re-expresses the same artificial-isolation-split defect without consumed region authority, planned progress failed.

The strengthened packaged test `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` is a regression contract, not license to force torus past a mathematically valid transport failure.

## Step 6 — prescribed sphere only after torus production closes

If exact torus reaches direct strict-valid production, observe the prescribed singular sphere next and classify its earliest current G4 blocker.

If torus stops at a deeper topology/periodic/chart/front/materialization invariant, keep sphere deferred and follow that earliest truthful blocker.

## Step 7 — bounded suite regression evidence

After focused/direct gate evidence, execute the packaged bounded suites under existing windows:

- producer suite excluding only the documented deliberately long BunnyRandom/Vase design-acceptance parameter cases;
- completion/simplification suite;
- validation suite;
- compiled API suite.

Entering artifact `9021175280` baseline:

- producer **119/121**, with the existing sub-millisecond validator-overhead threshold and exact-torus advancement contract as failures;
- completion/simplification **154/164**, same historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **341/353**.

Test names/cardinality changed in the new artifact. Record actual totals; do not predict or synthesize them. Direct mandatory gate evidence outranks aggregate counts.

## Step 8 — runtime and benchmark evidence

Capture bounded wall time and peak memory required by the testing strategy from packaged binaries. Bunny/vase remain G6 fixtures and do not decide this G4 region-isolation slice. Timeout is failure only and carries no inferred correctness.

## Mandatory no-progress decision

The preceding artifact-only turn established **one** Code + Build without material runtime progress.

After this artifact is tested:

- if material progress is established, review remains skipped (`never`) and the Test + Benchmark report's proposed next Code + Build plan becomes authoritative;
- if material progress is **not** established, do **not** authorize another ordinary Code + Build iteration. The process rule requires a mandatory design review or bounded producer-replacement proof before another ordinary implementation turn. Record that transition explicitly in TODO/handoff/PR.

Do not count compile success itself as material runtime progress.

## Completion record

At turn end create an artifact-only Test + Benchmark report containing:

- exact artifact/checksum/source/blob authority;
- any runtime-only fixture symlink;
- topology-region/isolation-seam focused results;
- retained polygonal/curved-disk/sheet-coverage/G4-periodic/G0-G3 authority;
- direct three-process plane/seam/close-sheets/cylinder evidence;
- exact torus region/isolation/periodic/phase/materialization evidence and determinism;
- strict validation/fallback/recovery evidence;
- bounded suite totals actually completed;
- runtime/memory evidence actually completed;
- explicit G4 and no-progress decision;
- exact next turn/plan permitted by that decision.

Update `TODO`, `MILESTONE_G_TODO.md`, live handoff, runtime summary, durable design/testing docs when current-state statements change, and PR #8 only after runtime evidence is complete. Keep PR #8 open, draft and unmerged.

End the completed turn with a **new top-level PR #8 conversation comment as the final repository write**. Do not perform any GitHub write afterward.

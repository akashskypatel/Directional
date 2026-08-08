# Gate 4 Closed-Genus-One Curved Disk Sheet — Artifact-Only Test + Benchmark Report

Date: 2026-08-08 UTC  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

Exact artifact **`9016834575`** is runtime-valid and establishes **material G4 progress, but G4 remains active**.

The generalized curved bounded disk-sheet producer is demonstrably live:

- new curved-disk focused semantics pass **6/6**;
- prior sheet-coverage semantics remain **3/3**;
- prior G4 periodic-relation semantics remain **5/5**;
- retained G0-G3 focused contracts remain **17/17**;
- direct plane, seam, close-sheets and cylinder authority remains exact and deterministic **3/3** with unchanged hashes and no fallback/recovery;
- exact torus no longer fails as `UnsupportedSourceSheetTopology`;
- instead it fails deterministically at `tracing/phase-front` as `Rejected / InvalidBoundedDiskTopology`;
- no generic tracing/arrangement/completion, fallback, legacy substitution, returned-input fallback, or source-grid recovery executes after the authoritative rejection.

Read-only inspection of the immutable packaged implementation identifies the new earliest blocker precisely: the curved-disk producer treats an internal local boundary edge as valid only when that edge is in `hardFeatureEdges`. The source-sheet classifier, however, can create an authoritative sheet boundary across a non-hard source edge through its normal-compatibility or close-sheet separation rules. The torus reaches exactly that case. The producer comment already describes a source-sheet rail as authoritative, but the implementation currently checks only hard-feature membership for internal local boundary edges.

The next Code + Build target is therefore **source-sheet boundary authority in the curved bounded disk producer**, not chart relaxation, feature demotion, annulus coercion, generic completion repair, or fixture-specific handling.

## Exact artifact authority

Artifact:

- ID **`9016834575`**;
- name `g4-curved-disk-code-build`;
- workflow run/job `31240168780 / 93059691196`;
- implementation `90046be649a0fd051e6c44eceec07198dc542c29`;
- payload cleanup `508211936b790dfb40cdbece7900bb0522368b76`;
- entering runtime source `a647215b4993338b054f04d4c8e54e7ef5370001`;
- GitHub/downloaded ZIP SHA-256 `6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`;
- internal `SHA256SUMS` SHA-256 `e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`;
- recursive checksums **48/48**;
- package **49 files**, **27 fixtures**, five executables, two project static libraries;
- log artifact `9016834752`, SHA-256 `6e0ed0906bc9f935ac80b6d8fd40f0654f203020a7b7c6cde6d9a4e49b067db1`;
- metadata records payload Git blob `2436d0fe3c1f8bad2e8614f118af70ecda2ac12d`, decoded payload SHA-256 `ae0b6efe3db697b22c36e2a348cb7be6a058f9e29bde5ac36231db8439f3eb91`, `runtimeExecution=false`, review policy `never`.

Final packaged source blobs were independently verified from the source archive:

| File | Git blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `998d8bc46faf6d590cb1674c4f5b2e290f94c48e` |
| `src/geometry/SurfaceCellTracing.cpp` | `3363e20c33a6850c192249877e7cb4488fc36597` |
| `src/pipeline/RemeshPipeline.cpp` | `b42681b61e2564fa55a2b67e7c7ae4890aa23d81` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `fe7ce43466cc3bc852b36c0ea8b8de6aac0c5b64` |

The validation turn performed **no configure, compile, link, rebuild, discovery regeneration, production edit, test edit, fixture edit, validator edit, benchmark edit, or build-system edit**.

The packaged tests retained an Actions absolute fixture path. A runtime-only symlink was created without modifying artifact bytes:

`/home/runner/work/Directional/Directional/benchmarks/fixtures -> /mnt/data/g4_curved_disk_runtime/test-data/benchmarks/fixtures`

## New curved-disk semantics — 6/6

All new/updated focused cases pass:

1. `SurfaceCellsPhase10.CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`;
2. `SurfaceCellsPhase10.CurvedBoundedDiskIsInvariantToFaceRowEnumeration`;
3. `SurfaceCellsPhase10.CurvedBoundedDiskPreservesAuthoritativeHardBoundary`;
4. `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
5. `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`;
6. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`.

This proves the producer is structurally reachable for a valid non-planar disk fixture, preserves row-order invariance and hard-boundary ownership in its focused domain, rejects intentionally invalid reciprocal transport with the typed transport reason, composes planar/periodic/curved classes in the synthetic mixed case, and advances the exact torus beyond the previous unsupported-producer classification.

The exact torus result below shows that focused hard-boundary coverage was incomplete for the production classifier's broader source-sheet boundary authority. The test result is retained as valid for its intended hard-boundary scenario; it does not prove that every source-sheet boundary is a hard-feature edge.

## Prior authority retained

- sheet-coverage semantics: **3/3**;
- G4 periodic-relation semantics: **5/5**;
- retained G0-G3 focused contracts: **17/17**.

The periodic relation tests still prove canonical reverse-description handling, distinct-sheet relation retention, typed same-sheet basis ambiguity, and conflicting transport rejection without ID/order/count/frequency/proximity ownership selection.

## Direct G0-G3 regression matrix — deterministic 3/3

All runs use direct `SurfaceCells`, fallback policy `Fail`, source-grid recovery disabled, and strict source-authoritative validation.

| Fixture | Result | Traces | Arrangement / simplified | Output | Validation | Hash | Internal wall seconds |
|---|---|---:|---:|---|---:|---|---|
| plane | `Produced / CompletedSurfaceCells` | 352 | 65 / 65 | 64 quads / 81 V | 0 | `730caeae49ec872c` | `0.417679 / 0.643571 / 0.481130` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 256 | 65 / 65 | 64 quads / 81 V | 0 | `5bdf34d7802e9fb0` | `0.632654 / 0.675839 / 0.697466` |
| close sheets | `Produced / CompletedSurfaceCells` | 1,104 | 202 / 202 | 200 quads / 242 V / 2 components | 0 | `89b052762f52a5af` | `4.824734 / 3.437435 / 3.486830` |
| cylinder | `Produced / CompletedSurfaceCells` | 1,728 | 290 / 290 | 288 quads / 320 V | 0 | `32135be51d7a0a26` | `3.744148 / 3.621149 / 3.760931` |

Peak working sets remained bounded at approximately 9.4–13.3 MB across these direct cases.

Cylinder retains exactly one periodic relation with quarter-turn rotation `0`, translation `(32,0)`, source route 32, cut 4, zero validation failures, and no fallback/recovery. Independent output-topology inspection again finds 64 exterior boundary edges arranged as exactly **two degree-2 loops of 32 vertices each**. The artificial periodic cut is not exterior.

## Exact torus — deeper typed producer failure, deterministic 3/3

Three independent direct processes complete with identical structural behavior:

| Run | Internal wall | Peak working set | Relations reached before rejection | Traces | Arrangement | Terminal |
|---|---:|---:|---:|---:|---:|---|
| 1 | `0.013927 s` | `8,654,848 B` | 2 | 0 | 0 | `NotProductionReady:tracing` |
| 2 | `0.009857 s` | `8,835,072 B` | 2 | 0 | 0 | `NotProductionReady:tracing` |
| 3 | `0.009618 s` | `8,699,904 B` | 2 | 0 | 0 | `NotProductionReady:tracing` |

Common diagnostics:

- `surfaceCellAuthoritativeProducerDisposition = Rejected`;
- `surfaceCellFirstInvalidProducerStage = tracing/phase-front`;
- `surfaceCellFirstInvalidProducerReason = InvalidBoundedDiskTopology`;
- first invalid source face = `52`;
- periodic relation count reached before rejection = **2**;
- compatibility projection remains rotation `0`, translation `(24,0)`, route 24, cut 2;
- trace count = 0;
- arrangement/simplification/completion output counts = 0;
- output origin = `None`;
- no fallback attempt/use, legacy substitution, returned-input fallback, or source-grid recovery.

The relation count is not an acceptance key. It is lower than the prior artifact's three because the now-applicable curved-disk producer rejects earlier in canonical sheet evaluation, before a later supported annular sheet is visited. The retained G4 relation semantics and direct cylinder relation authority remain green. Do not restore a count by evaluating or selecting sheets through fixture-specific ordering.

Stable structural identities across all three torus runs:

- feature `f15e4f3be07d3c7f`, count 216;
- metric `34cb872327c9b0c6`, count 72;
- relief `8ccb10d25b69edb9`, count 58;
- source labels `e48c84177faf6e2c`, count 144;
- tracing `4e27fcfa18a602b1`, count 0.

Feature authority remains 48 hard edges and four closed feature curves.

## Exact blocker diagnosis — source-sheet boundary authority

The torus is a valid closed manifold source mesh, and the local disk topology is constructed from a subset of valid source faces. In `build_curved_bounded_disk_phase_front_for_faces()` the face-specific `InvalidBoundedDiskTopology` paths before transport are limited to invalid input incidence and local boundary authority checks. For a valid manifold source subset, the observed face-specific rejection is the internal local-boundary check:

```text
if the local boundary edge has two source incident faces
and the edge is not in options.hardFeatureEdges
then reject InvalidBoundedDiskTopology
```

This check is too narrow for the actual source-sheet contract.

`classify_source_surface_labels()` creates local sheets by refusing traversal not only across `barrierEdges`, but also when:

- `traverseUnmarkedSharpBends` is disabled and adjacent face normals violate `normalCompatibility`; or
- a close/opposing-sheet conflict is detected within the configured geodesic exclusion policy.

Therefore an internal source edge can be an **authoritative source-sheet boundary even when it is not a hard-feature edge**. `SurfaceCellTracingOptions` already carries `sourceFaceComponents` and `sourceFaceSheets`, and `source_faces_compatible()` already expresses same-component/same-sheet compatibility.

The curved-disk producer's own comment says that a local boundary may be a genuine source boundary or an authoritative hard-feature/source-sheet rail, but its implementation currently verifies only hard-feature membership for an internal edge. That implementation/contract mismatch is now the earliest G4 blocker.

The next implementation must accept an internal local boundary only when it is structurally authoritative: hard feature **or** the opposite source face belongs to a different authoritative source component/sheet. It must continue to reject a hidden ordinary internal cut where both incident source faces have the same authoritative component/sheet.

Do not special-case face 52, the torus, sheet counts, relation counts, or loop sizes.

## Bounded suites

Producer suite excluding documented long BunnyRandom/Vase design-acceptance cases:

- **112/113** pass;
- sole failure remains `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- observed validation time `0.000152236 s` versus threshold `0.00009186355 s` in this run;
- classification remains the existing sub-millisecond performance threshold, not a G4 semantic regression.

Completion/simplification remains **154/164** with the exact same ten historical failures. Validation remains **60/60**. Compiled API remains **8/8**.

Bounded aggregate is **334/345**. The five-net-test increase versus the prior 329/340 aggregate comes from the new curved-disk coverage; the failure set is otherwise unchanged.

## G4 decision

**G4 remains active.** This artifact satisfies the curved-disk slice's material-progress condition:

- the curved-disk producer is runtime-live;
- the old `UnsupportedSourceSheetTopology` terminal classification is eliminated;
- the exact torus reaches a deeper deterministic typed producer invariant;
- prior focused and direct authority remains intact;
- no generic/fallback/recovery path substitutes for producer authority.

The exact next contract is **source-sheet boundary authority for curved bounded disk charts**.

Prescribed sphere remains deferred because torus does not yet reach complete authoritative materialization/direct strict-valid production.

## Next authoritative turn

**Code + Build — G4 curved-disk source-sheet boundary authority.**

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Plan.md`.

The implementation should make the smallest general correction to local disk boundary validation: distinguish a valid authoritative cross-sheet/cross-component boundary from a hidden same-sheet cut using existing source labels, while retaining hard-feature and genuine source-boundary authority. It must not relax disk topology generally, demote features, use raw IDs/order/counts, weld geometry, alter validators, or skip ahead to chart/completion repair.

Local evidence archive: `directional-g4-curved-disk-artifact-only-evidence.tar.gz`, SHA-256 `7e51df90e935f6e393808c1d47e1ad5570fa8125cbf3fb9f736ba90a17d13efd`.

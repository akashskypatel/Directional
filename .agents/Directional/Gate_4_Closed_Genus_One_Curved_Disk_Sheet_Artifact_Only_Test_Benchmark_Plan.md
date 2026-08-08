# Gate 4 Closed-Genus-One Curved Disk Sheet — Artifact-Only Test + Benchmark Plan

Status: **authoritative next turn**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Exact artifact authority

Use only GitHub Actions artifact:

- artifact ID: **`9016834575`**;
- name: `g4-curved-disk-code-build`;
- workflow run/job: `31240168780 / 93059691196`;
- implementation commit: `90046be649a0fd051e6c44eceec07198dc542c29`;
- cleanup commit: `508211936b790dfb40cdbece7900bb0522368b76`;
- GitHub/downloaded ZIP SHA-256: **`6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`**;
- internal `SHA256SUMS` SHA-256: **`e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`**;
- recursive checksums: **48/48**;
- package: **49 total files**, **27 fixture files**, five executables, two project static libraries;
- log artifact: `9016834752`, SHA-256 `6e0ed0906bc9f935ac80b6d8fd40f0654f203020a7b7c6cde6d9a4e49b067db1`;
- artifact metadata: `runtimeExecution=false`, review policy `never`.

Do **not** rebuild, reconfigure, relink, regenerate discovery, patch packaged source, replace fixtures, or substitute another artifact.

Final source blobs to verify from the packaged source archive:

- `include/directional/geometry/SurfaceCellTracing.h` `998d8bc46faf6d590cb1674c4f5b2e290f94c48e`;
- `src/geometry/SurfaceCellTracing.cpp` `3363e20c33a6850c192249877e7cb4488fc36597`;
- `src/pipeline/RemeshPipeline.cpp` `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
- `tests/SurfaceCellsPhase10Tests.cpp` `fe7ce43466cc3bc852b36c0ea8b8de6aac0c5b64`.

## Turn boundary

Allowed:

- download/unpack exact artifact `9016834575`;
- verify artifact/source/blob/checksum/dependency/fixture/command-boundary authority;
- execute only packaged test/benchmark binaries and packaged inputs;
- create runtime-only fixture-path directories/symlinks when immutable packaged tests retain an Actions absolute path;
- capture stdout/stderr, process status, wall time, memory, diagnostics, stage hashes, topology/output evidence;
- inspect immutable packaged source/fixtures read-only to classify a runtime failure;
- update documentation/PR metadata only after runtime evidence is complete.

Forbidden:

- production, test, fixture, validator, benchmark, or build-system edits;
- configure/compile/link/rebuild;
- validator weakening or threshold changes;
- fallback/recovery or source-grid recovery as passing authority;
- synthetic counters/topology/output/Euler corrections;
- ID/order/count/frequency/proximity ownership selection;
- arbitrary subset selection;
- positional sheet merging or Euclidean seam welding;
- fixture-specific success branches;
- post-hoc topology/cell merging to conceal producer failure;
- timeout-as-correctness inference.

If packaged tests reference `/home/runner/work/Directional/Directional/benchmarks/fixtures`, expose immutable `test-data/benchmarks/fixtures` through a recorded runtime-only symlink. Do not modify artifact bytes.

## Step 1 — static integrity before runtime

Before executing any packaged Directional binary, verify:

1. artifact ID/name/run/job and outer SHA-256 above;
2. downloaded ZIP SHA-256 equals `6bf7f897...28e67`;
3. internal `SHA256SUMS` SHA-256 equals `e0ec3737...f4736`;
4. recursive checksums are **48/48**;
5. package contains **49 total files**, **27 fixtures**, five executables and two project libraries;
6. `metadata/source-authority.json` records implementation `90046be...`, cleanup `5082119...`, entering runtime source `a647215...`, payload Git blob `2436d0...`, decoded patch SHA-256 `ae0b6e...`, `runtimeExecution=false`, review policy `never`;
7. `metadata/command-boundary.txt` proves no generated Directional runtime executed during Code + Build;
8. final source blobs equal the four values above.

If exact authority cannot be established, classify infrastructure failure and stop. Do not create a replacement build.

## Step 2 — new curved-disk semantic cases first

Run the packaged producer test binary with the new focused cases before broader suites:

1. `SurfaceCellsPhase10.CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`;
2. `SurfaceCellsPhase10.CurvedBoundedDiskIsInvariantToFaceRowEnumeration`;
3. `SurfaceCellsPhase10.CurvedBoundedDiskPreservesAuthoritativeHardBoundary`;
4. `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
5. `SurfaceCellsPhase10.PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`;
6. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`.

Required semantics:

- a valid non-planar χ=1 single-boundary disk is structurally handled by the new producer rather than `UnsupportedSourceSheetTopology`;
- equivalent face-row enumeration preserves structural result/hash or the same truthful typed failure;
- authoritative hard/source boundary ownership remains exact with no positional welding or feature demotion;
- intentionally inconsistent reciprocal transport rejects as `InvalidBoundedDiskTransport` rather than selecting another branch heuristically;
- planar + periodic + curved-disk sheet classes compose with exact source-sheet ownership and unchanged periodic authority;
- exact torus must no longer fail merely because curved-disk topology has no producer. Do not encode an unjustified torus output count.

A focused failure must be diagnosed against the intended contract and actual fixture state. Do not edit tests in this turn.

## Step 3 — retain prior authority

Rerun the three prior sheet-coverage semantic contracts and require **3/3** retention.

Rerun the five prior G4 periodic-relation semantics and require **5/5** retention. The exact-torus producer-boundary test may overlap with Step 2; report overlapping execution clearly rather than double-counting aggregate totals.

Rerun all **17/17** retained G0-G3 focused contracts from the latest runtime report. Any semantic regression blocks G4 progress even if torus advances.

## Step 4 — direct G0-G3 deterministic regression matrix

Use direct `SurfaceCells`, fallback policy `Fail`, source-grid recovery disabled, and the same strict source-authoritative validation/options as the current runtime authority.

Run three independent processes per fixture and require unchanged authority:

| Fixture | Required result | Output | Required hash |
|---|---|---:|---|
| plane | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `730caeae49ec872c` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `5bdf34d7802e9fb0` |
| close sheets | `Produced / CompletedSurfaceCells` | 200 quads / 242 V / 2 components | `89b052762f52a5af` |
| cylinder | `Produced / CompletedSurfaceCells` | 288 pure quads / 320 V | `32135be51d7a0a26` |

Cylinder must retain one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4; 1,728 traces; 290 arrangement/simplified cells; zero validation failures; exactly two genuine exterior 32-edge annulus loops; no artificial-cut exterior seam; no fallback/recovery.

Do not update a baseline because the candidate differs.

## Step 5 — exact torus mandatory decision

Run committed `milestone-g/torus.obj` + `torus.rawfield` using direct `SurfaceCells`, fallback `Fail`, recovery disabled. Run at least three independent processes when each completes within the bounded observation window.

Record all fields actually exposed by diagnostics:

- producer disposition and first invalid stage/reason;
- periodic relation cardinality and only per-relation fields actually serialized/exposed;
- phase-front cell/edge/event counts and source-sheet coverage if produced;
- trace/strand/embedding/arrangement/simplification/completion/output counts;
- output topology, strict validation, provenance and structural hash when output exists;
- fallback/recovery/origin;
- stage hashes and determinism;
- wall time and peak memory.

### Required progress classification

The prior terminal result is no longer sufficient:

`Rejected / UnsupportedSourceSheetTopology` solely because the χ=1 single-boundary curved sheet lacks a producer.

Preferred G4 closure for the torus slice:

- every authoritative source sheet is covered exactly once;
- aggregate phase-front becomes `Produced`;
- authoritative materialization succeeds;
- direct strict-valid closed pure-quad torus output is produced with complete source provenance;
- no fallback/recovery, feature demotion, artificial disk-as-annulus cut, positional merge, or Euclidean seam weld occurs.

Acceptable material progress if direct output is not yet reached:

- the curved-disk producer is demonstrably live on the exact torus and neither disk is rejected merely as unsupported topology;
- runtime reaches a deeper deterministic typed invariant such as `InvalidBoundedDiskTransport`, `InvalidBoundedDiskBoundaryPhase`, `InvalidBoundedDiskChart`, `InvalidBoundedDiskFrontPairing`, or an exact later phase-front/materialization structural reason;
- canonical periodic-relation authority remains live;
- no generic zero-cell/fallback path substitutes for authoritative producer failure;
- all prior focused/direct authority remains intact.

If a deeper failure occurs, identify its exact structural invariant from immutable packaged source/runtime evidence. Do not repair it in this Test + Benchmark turn.

Do not make face 48, five sheets, three relations, or the previously observed boundary lengths into acceptance conditions. Those values are diagnostic evidence only.

## Step 6 — prescribed sphere only after torus sheet coverage/materialization closes

If the exact torus reaches direct strict-valid production, observe the prescribed singular sphere next and classify its earliest current G4 blocker. Its older observation was 766 traces / 30 arrangement cells followed by repeated-boundary-node/parity-alternative exhaustion.

If torus instead exposes a deeper curved-disk or materialization invariant, stop the topology decision there and keep prescribed sphere deferred.

## Step 7 — bounded suite regression evidence

After focused/direct gate evidence, run packaged suites under the existing bounded windows:

- producer suite excluding documented deliberately long BunnyRandom/Vase design-acceptance cases;
- completion/simplification suite;
- validation suite;
- compiled API suite.

Entering baseline:

- producer **107/108**, sole existing failure `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` (sub-millisecond performance threshold);
- completion/simplification **154/164**, same historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **329/340**.

New test cardinality may change totals; record actual runtime totals instead of predicting them. Direct mandatory gate evidence outranks aggregate counts. Do not alter semantic expectations to improve totals.

## Step 8 — later production observations

After correctness evidence, use the packaged benchmark binary for any bounded wall-time/memory measurements required by the testing strategy. Bunny/vase remain later G6 production fixtures and do not decide the active G4 curved-disk contract. A bounded timeout is failure only and carries no inferred disposition/correctness.

## Completion record

At turn end create one artifact-only Test + Benchmark report containing:

- exact artifact/checksum/source/blob authority;
- any runtime-only fixture symlink;
- new curved-disk focused results;
- sheet-coverage 3/3, G4 relation 5/5, and G0-G3 17/17 retention;
- direct three-process plane/seam/close-sheets/cylinder evidence;
- exact torus producer/chart/materialization/output behavior and determinism;
- strict validation/fallback/recovery evidence;
- bounded suite totals actually completed;
- benchmark/runtime/memory evidence actually completed;
- explicit G4 decision and exact next Code + Build target if G4 remains open.

Update `TODO`, `MILESTONE_G_TODO.md`, the live handoff, runtime summary, and PR #8 only after runtime evidence is complete. Keep PR #8 open, draft, and unmerged. Review policy remains `never`, so if G4 remains open the Test + Benchmark turn's proposed Code + Build plan becomes authoritative.

End the completed turn with a **new top-level PR #8 conversation comment as the final repository write**. Do not perform any GitHub write afterward.

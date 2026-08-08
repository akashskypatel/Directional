# Gate 4 Closed-Genus-One Source-Sheet Boundary Authority — Artifact-Only Test + Benchmark Plan

Status: **authoritative next turn**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Exact artifact authority

Use only GitHub Actions artifact:

- artifact ID **`9019024467`**;
- name `g4-source-sheet-boundary-code-build`;
- workflow run/job `31247546780 / 93078496378`;
- event commit `ccb9aa0db15a575f31b802a354ccf8b0aabe111c`;
- implementation commit **`b425898fa7367406fa0c07e8f4441a37efc01315`**;
- payload cleanup commit **`3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`**;
- GitHub/downloaded ZIP SHA-256 **`a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`**;
- internal `SHA256SUMS` SHA-256 **`7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`**;
- recursive checksums **48/48**;
- package **49 total files**, **27 fixture files**, five executables, two project static libraries;
- log artifact `9019024673`, SHA-256 **`243943268324a24e5fd04a42fed706b274a8525f5c2f157bf246b5028e42f03c`**;
- artifact metadata `runtimeExecution=false`, review policy `never`.

Do **not** rebuild, reconfigure, relink, regenerate discovery, patch packaged source, replace fixtures, or substitute another artifact.

Final packaged source blobs:

- `include/directional/geometry/SurfaceCellTracing.h` `ddb8e211f073d15fcfcc6782f964f88c4dedfc5e`;
- `src/geometry/SurfaceCellTracing.cpp` `14cf7f3a3301e9e3f10ec48a480d3f6e5efee7ed`;
- `src/pipeline/RemeshPipeline.cpp` `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
- `tests/SurfaceCellsPhase10Tests.cpp` `31322acea5227a8e3692887fad1ec4a9e6d8c101`.

## Turn boundary

Allowed:

- download/unpack exact artifact `9019024467`;
- verify artifact/source/blob/checksum/dependency/fixture/command-boundary authority;
- execute only packaged test/benchmark binaries and packaged inputs;
- create a recorded runtime-only fixture-path symlink if immutable packaged tests retain an Actions absolute fixture path;
- capture stdout/stderr, process status, wall time, memory, diagnostics, stage hashes, topology/output evidence;
- inspect immutable packaged source/fixtures read-only to classify runtime behavior;
- update documentation/PR metadata after runtime evidence is complete.

Forbidden:

- production, test, fixture, validator, benchmark or build-system edits;
- configure/compile/link/rebuild/discovery regeneration;
- validator weakening or threshold changes;
- fallback/recovery or source-grid recovery as passing authority;
- synthetic counters/topology/output/Euler corrections;
- raw ID/order/count/frequency/proximity ownership selection;
- arbitrary subset selection;
- positional sheet merging or Euclidean seam welding;
- fixture-specific success branches;
- post-hoc topology/cell merging to conceal producer failure;
- timeout-as-correctness inference.

## Step 1 — static integrity before runtime

Before executing any packaged Directional binary verify:

1. exact artifact ID/name/run/job and outer ZIP SHA-256;
2. internal manifest SHA-256 and **48/48** recursive checksums;
3. package cardinality: 49 files / 27 fixtures / five executables / two libraries;
4. `metadata/source-authority.json` records implementation `b425898...`, cleanup `3fcfd2c...`, entering runtime artifact `9016834575`, raw patch SHA-256 `c96b3d73...`, `runtimeExecution=false`, review policy `never`;
5. `metadata/command-boundary.txt` proves no generated Directional runtime executed during Code + Build;
6. final source blobs equal the four values above;
7. dependency/submodule and fixture closure is present.

If exact authority cannot be established, classify infrastructure failure and stop. Do not create a replacement build.

## Step 2 — new source-sheet-boundary semantics first

Run these new focused cases from the packaged producer test binary:

1. `SurfaceCellsPhase10.CurvedBoundedDiskAcceptsNonHardAuthoritativeSourceSheetBoundary`;
2. `SurfaceCellsPhase10.CurvedBoundedDiskRejectsHiddenSameSheetBoundaryCut`;
3. `SurfaceCellsPhase10.CurvedBoundedDiskCrossSheetBoundaryIsInvariantToFaceRowEnumeration`.

Required semantics:

- a non-hard internal source edge between different authoritative source sheets is accepted as a local curved-disk boundary without modifying hard-feature authority;
- the same physical internal source edge with compatible same-component/same-sheet labels is rejected as a hidden local cut;
- face-row re-enumeration preserves the same produced structural geometry/source ownership;
- exact source edge/face/component/sheet provenance remains authoritative.

Diagnose any failing test against its actual structural fixture. Do not edit tests in this turn.

## Step 3 — retain prior curved-disk and producer authority

Rerun the prior curved-disk focused cases and the strengthened exact-torus producer-boundary case:

1. `CurvedBoundedDiskPhaseFrontIsStructurallyApplicable`;
2. `CurvedBoundedDiskIsInvariantToFaceRowEnumeration`;
3. `CurvedBoundedDiskPreservesAuthoritativeHardBoundary`;
4. `CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
5. `PhaseFrontComposesPlanarPeriodicAndCurvedDiskSheets`;
6. `ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`.

Together with Step 2, report the source-sheet-boundary + curved-disk focused group as **9 semantic cases** without double-counting overlapping executions elsewhere.

Then retain:

- prior sheet-coverage contracts **3/3**;
- G4 periodic-relation contracts **5/5**;
- retained G0-G3 focused contracts **17/17**.

Any regression in prior authoritative contracts blocks G4 progress even if torus advances.

## Step 4 — direct G0-G3 deterministic regression matrix

Use direct `SurfaceCells`, fallback `Fail`, source-grid recovery disabled and the same strict source-authoritative validation/options as current runtime authority.

Run three independent processes per fixture and require unchanged authority:

| Fixture | Required result | Output | Required hash |
|---|---|---:|---|
| plane | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `730caeae49ec872c` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `5bdf34d7802e9fb0` |
| close sheets | `Produced / CompletedSurfaceCells` | 200 quads / 242 V / 2 components | `89b052762f52a5af` |
| cylinder | `Produced / CompletedSurfaceCells` | 288 pure quads / 320 V | `32135be51d7a0a26` |

Cylinder must retain one relation `r=0`, `t=(32,0)`, route 32, cut 4; 1,728 traces; 290 arrangement/simplified cells; zero validation failures; exactly two genuine exterior 32-edge annulus loops; no artificial-cut exterior seam; no fallback/recovery.

Do not update a baseline because the candidate differs.

## Step 5 — exact torus mandatory G4 decision

Run committed `milestone-g/torus.obj` + `torus.rawfield` with direct `SurfaceCells`, fallback `Fail`, recovery disabled. Run at least three independent processes when each completes within the bounded observation window.

Record all diagnostics actually exposed:

- producer disposition and first invalid stage/reason;
- periodic relation cardinality and serialized per-relation authority;
- phase-front cell/edge/event/source-sheet coverage counts if produced;
- trace/strand/embedding/arrangement/simplification/completion/output counts;
- output topology, strict validation, provenance and structural hash if output exists;
- fallback/recovery/output origin;
- stage hashes and determinism;
- wall time and peak memory.

### Required progress classification

The prior terminal blocker is no longer sufficient:

`Rejected / InvalidBoundedDiskTopology` caused solely by treating a non-hard authoritative cross-sheet source edge as an invalid local boundary.

Preferred G4 result:

- every authoritative source sheet is covered exactly once;
- aggregate phase-front becomes `Produced`;
- materialization succeeds;
- direct strict-valid closed pure-quad torus output is produced with complete source provenance;
- no fallback/recovery, feature demotion, artificial disk-as-annulus cut, positional merge or Euclidean seam weld occurs.

Acceptable material progress if direct output is not yet reached:

- the non-hard cross-sheet boundary is accepted by the curved-disk producer;
- torus advances to a deeper deterministic truthful typed invariant such as `InvalidBoundedDiskTransport`, `InvalidBoundedDiskBoundaryPhase`, `InvalidBoundedDiskChart`, `InvalidBoundedDiskFrontPairing`, or an exact later phase-front/materialization reason;
- canonical periodic-relation authority remains live;
- no generic zero-cell/fallback path substitutes for authoritative producer failure;
- all prior focused/direct authority remains intact.

If a deeper failure appears, identify its structural invariant from immutable packaged source/runtime evidence. Do not repair it in this Test + Benchmark turn.

Raw source face IDs, observed relation counts, sheet counts or boundary lengths remain diagnostic evidence only and may not become acceptance criteria.

## Step 6 — prescribed sphere only after torus materialization closes

If exact torus reaches direct strict-valid production, observe the prescribed singular sphere next and classify its earliest current G4 blocker.

If torus instead exposes a deeper bounded-disk or materialization invariant, keep prescribed sphere deferred and make that earliest blocker the next Code + Build target.

## Step 7 — bounded suite regression evidence

After focused/direct gate evidence run packaged suites under the existing bounded windows:

- producer suite excluding documented deliberately long BunnyRandom/Vase design-acceptance cases;
- completion/simplification suite;
- validation suite;
- compiled API suite.

Entering runtime baseline from artifact `9016834575`:

- producer **112/113**, sole existing failure `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- completion/simplification **154/164**, same historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **334/345**.

Three new tests increase producer cardinality if they execute in the bounded suite; record actual totals, do not predict or synthesize them. Direct mandatory gate evidence outranks aggregate counts.

## Step 8 — runtime/benchmark evidence

Capture bounded wall-time/memory measurements required by the testing strategy from the packaged binaries. Bunny/vase remain later G6 fixtures and do not decide the current G4 source-sheet-boundary contract. Timeout is failure only and carries no inferred correctness.

## Completion record

At turn end create an artifact-only Test + Benchmark report containing:

- exact artifact/checksum/source/blob authority;
- any runtime-only fixture symlink;
- new source-sheet-boundary focused results;
- prior curved-disk, sheet-coverage, G4 relation and G0-G3 retention;
- direct three-process plane/seam/close-sheets/cylinder evidence;
- exact torus producer/materialization/output behavior and determinism;
- strict validation/fallback/recovery evidence;
- bounded suite totals actually completed;
- runtime/memory evidence actually completed;
- explicit G4 decision and exact next Code + Build target if G4 remains open.

Update `TODO`, `MILESTONE_G_TODO.md`, the live handoff, runtime summary and PR #8 only after runtime evidence is complete. Keep PR #8 open, draft and unmerged. Review policy remains `never`; if G4 remains open, the Test + Benchmark turn's proposed Code + Build plan becomes authoritative.

End the completed turn with a **new top-level PR #8 conversation comment as the final repository write**. Do not perform any GitHub write afterward.

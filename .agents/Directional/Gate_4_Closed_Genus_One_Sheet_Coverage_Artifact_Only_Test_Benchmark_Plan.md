# Gate 4 Closed-Genus-One Sheet Coverage — Artifact-Only Test + Benchmark Plan

Status: **authoritative next turn**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Exact artifact authority

Use only GitHub Actions artifact:

- artifact ID: **`9015931928`**
- name: `g4-sheet-coverage-code-build`
- workflow run/job: `31237248211 / 93051938159`
- GitHub/downloaded ZIP SHA-256: `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`
- internal `SHA256SUMS` digest: `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`
- implementation commit: `856554ce648e5df09ac50f5c94e3e8f098181524`
- final compile-source commit: `a647215b4993338b054f04d4c8e54e7ef5370001`
- payload cleanup commit: `e46a6d99a45f22f31672c8e5a3367735427d827e`
- log artifact: `9015932044`, SHA-256 `b05c1ef0bf7c5a52ff5dc8158d02c00d11d9cb7637c0a93b0c385a202ad46c50`
- artifact metadata: `runtimeExecution=false`

Do **not** rebuild, reconfigure, relink, regenerate, patch, or replace this artifact.

## Turn boundary

Allowed:

- download/unpack exact artifact `9015931928`;
- verify exact artifact/source/blob/checksum authority;
- execute only packaged test/benchmark binaries;
- create runtime-only fixture-path directories/symlinks when the immutable packaged tests retain an Actions build path;
- capture stdout/stderr, process exit, wall time, memory, diagnostics, structural hashes, topology/output evidence;
- update documentation/PR metadata only after runtime evidence is complete.

Forbidden:

- production, test, fixture, validator, benchmark, or build-system edits;
- configure/compile/link/rebuild;
- validator weakening;
- fallback/recovery substitution;
- source-grid recovery as a passing authority;
- synthetic counters/output/Euler fixes;
- arbitrary subset or order/count/frequency/ID/proximity ownership selection;
- positional merging or Euclidean seam welding;
- fixture-specific success paths;
- timeout-as-correctness inference.

If packaged tests reference `/home/runner/work/Directional/Directional/benchmarks/fixtures`, expose `test-data/benchmarks/fixtures` through the same recorded runtime-only symlink technique used by the previous artifact-only turns. Do not modify artifact bytes.

## Step 1 — static artifact integrity before runtime

Verify:

1. artifact ID/name/run/job and ZIP digest above;
2. downloaded ZIP SHA-256 equals `108580a2...f3cc4`;
3. internal `SHA256SUMS` SHA-256 equals `c801b0...03635`;
4. recursive checksum validation is **47/47**;
5. package contains **48 total files**, **27 fixture files**, five executables, and two project static libraries;
6. `metadata/source-authority.json` records implementation `856554c...`, final compile source `a647215...`, cleanup `e46a6d9...`, `runtimeExecution=false`, review policy `never`;
7. final source blobs are exactly:
   - `include/directional/geometry/SurfaceCellTracing.h` `6ebe8f3324be580fc4838b97e5fb449572709236`;
   - `src/geometry/SurfaceCellTracing.cpp` `6b32b48141c16e2d51f1932462566083a7bc3355`;
   - `src/pipeline/RemeshPipeline.cpp` `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
   - `tests/SurfaceCellsPhase10Tests.cpp` `c038567898f0da7efd6519392c37cbace02b8c1c`.

Stop if exact authority cannot be established. Do not substitute another build.

## Step 2 — new sheet-coverage semantics first

Run the packaged producer-test binary with the new/strengthened G4 cases before broader suites:

- `SurfaceCellsPhase10.PhaseFrontComposesBoundedAndPeriodicAuthoritativeSheets`
- `SurfaceCellsPhase10.PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority`
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`

Required semantics:

- mixed supported bounded + periodic authoritative sheets compose into one `Produced` aggregate with exact source-sheet ownership;
- once at least one sheet has produced authoritative content, a later unsupported sheet fails closed as typed `UnsupportedSourceSheetTopology` rather than returning partial `NotApplicable`;
- rejected partial coverage exposes no partial cells/edges/events as whole-surface authority;
- exact torus does not regress to scalar `InvalidPeriodicTopology` and does not retain the previous partial `NotApplicable` aggregate behavior.

Record natural producer behavior; do not hardcode the torus sheet ID, failing face ID, relation count beyond semantic collection liveness, or expected output count.

## Step 3 — retain prior G4 relation authority and G0-G3 contracts

Rerun all five previously passed G4 periodic-relation semantics. Expected **5/5**:

1. reverse relation description canonicalizes without duplicate generator;
2. distinct authoritative sheets retain every relation;
3. same-sheet dependent/ambiguous basis fails closed without order choice;
4. conflicting reciprocal transport fails closed;
5. exact committed torus does not reject solely because another periodic sheet exists.

Then rerun all **17/17** retained G0-G3 focused contracts from the prior runtime report. Any regression blocks G4 progress even if the torus changes stage.

## Step 4 — direct G0-G3 deterministic regression matrix

Use direct `SurfaceCells`, `fallbackPolicy=Fail`, source-grid recovery disabled, strict source-authoritative validation, and the same options used by the prior G4 runtime artifact.

Run three independent processes per fixture and require the existing authority unchanged:

| Fixture | Required result | Output | Required hash |
|---|---|---:|---|
| plane | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `730caeae49ec872c` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `5bdf34d7802e9fb0` |
| close sheets | `Produced / CompletedSurfaceCells` | 200 quads / 242 V / 2 components | `89b052762f52a5af` |
| cylinder | `Produced / CompletedSurfaceCells` | 288 pure quads / 320 V | `32135be51d7a0a26` |

Cylinder must retain the one-relation annulus contract: `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, exactly two genuine exterior annulus loops, no artificial-cut exterior seam, and no fallback/recovery.

Do not update a baseline merely because the candidate differs.

## Step 5 — exact torus mandatory decision

Run committed `milestone-g/torus.obj` + `torus.rawfield` with direct `SurfaceCells`, fallback `Fail`, recovery disabled. Run at least three independent processes if each completes within the bounded observation window.

Record:

- producer disposition and first invalid stage/reason;
- periodic relation count and every relation field actually exposed by diagnostics;
- phase-front cells/edges/events if produced;
- traces, strands, embedded arcs, arrangement/simplification/completion/output counts;
- output topology/validation/hash if output exists;
- fallback/recovery/origin;
- stage hashes and determinism;
- wall time / peak memory.

### Required material-progress classification

The old path is **not acceptable**:

`partial phase-front NotApplicable -> 670 generic traces -> 113 arcs -> 0 arrangement cells -> SideSubdivisionRepair:InvalidInputIncidence`

Preferred closure:

- aggregate phase-front `Produced` with every authoritative source sheet covered exactly once;
- exact materialization succeeds;
- direct strict-valid closed torus pure-quad output with complete provenance and no fallback/recovery.

Acceptable next-slice material progress:

- phase-front fails earlier and truthfully as typed `UnsupportedSourceSheetTopology` or another precise source-sheet/materialization structural invariant;
- canonical periodic relation authority remains live;
- the pipeline does **not** continue through the previous zero-cell generic arrangement/completion path;
- all prior G4 relation and G0-G3 regressions remain intact;
- no fallback/recovery or hard-feature weakening occurs.

If a new typed failure occurs, identify the exact unsupported sheet topology/producer invariant from immutable packaged source and runtime diagnostics. Do not repair a later stage in this turn.

## Step 6 — prescribed sphere only if torus producer coverage closes

If the torus reaches direct strict-valid production, observe the prescribed singular sphere next and classify its earliest current G4 failure. Prior authority was 766 traces / 30 arrangement cells followed by repeated-boundary-node / parity-alternative exhaustion.

If the torus instead exposes a typed unsupported-sheet/materialization blocker, stop the topology decision there and keep the sphere deferred.

## Step 7 — bounded suite regression evidence

After focused/direct gate evidence, run the packaged suites under the existing bounded windows:

- producer suite, excluding documented deliberately long design-acceptance cases;
- completion/simplification suite;
- validation suite;
- compiled API suite.

Previous baseline:

- producer **105/106**, sole known scheduler/environment-sensitive `StrictValidatorOverheadStaysBelowFivePercent` failure;
- completion/simplification **154/164**, same historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **327/338**.

Direct gate evidence outranks aggregate totals. Do not alter semantic expectations to improve counts.

## Step 8 — benchmark/later observations

Use the packaged benchmark binary only after correctness evidence. Capture bounded applicable wall-time/memory records. Bunny/vase may be observed only if required by the current testing strategy and time budget; they remain G6 and do not decide G4. A timeout is failure only.

## Completion record

At turn end create one artifact-only Test + Benchmark report including:

- exact artifact/checksum/source/blob authority;
- any runtime-only fixture symlink;
- new sheet-coverage cases;
- prior G4 relation 5/5 and G0-G3 17/17 retention;
- three-run direct plane/seam/close-sheets/cylinder regressions;
- exact torus producer disposition, relation authority, phase-front coverage/materialization state, earliest terminal behavior and determinism;
- strict validation/fallback/recovery evidence;
- bounded suite totals actually completed;
- benchmark/runtime/memory evidence actually completed;
- clear G4 decision and the exact next Code + Build target if G4 remains open.

Update `TODO`, `MILESTONE_G_TODO.md`, the live handoff, runtime summary, and PR #8 only after runtime evidence is complete. Keep PR #8 open, draft, unmerged. End with a **new top-level PR #8 conversation comment as the final repository write** for the turn.

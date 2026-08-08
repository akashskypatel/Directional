# Gate 4 Closed-Genus-One Holonomy Basis — Artifact-Only Test + Benchmark Plan

Status: **authoritative next turn**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Exact artifact authority

Use only GitHub Actions artifact:

- artifact ID: **`9014730437`**
- name: `g4-holonomy-basis-code-build`
- workflow run: `31233594490`
- workflow ZIP digest: `sha256:14ad61d02fc67d68267745f5efae4943d53420e34c4373366ff04a9a29fe1aec`
- internal `SHA256SUMS` digest: `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`
- primary implementation commit: `aa0f115c19fc8a5afd8487ebb561e2de2b8551ba`
- final compile-source commit: `6e754bdd64482582d39e71184805fbb053c99f86`
- payload cleanup commit: `8304ba30b0f85bc69deebbf55922f05846d2d5b2`
- artifact metadata: `runtimeExecution=false`

Detailed compile/log artifact: `9014730651`.

Do **not** rebuild, reconfigure, relink, regenerate, patch, or replace the artifact.

## Turn boundary

Allowed:

- download and unpack exact artifact `9014730437`;
- verify artifact/source/blob/checksum authority;
- execute packaged test and benchmark binaries;
- create runtime-only directories/symlinks needed to expose immutable packaged fixtures at a compiled absolute fixture path;
- capture stdout/stderr, process exit, wall time, memory, hashes, diagnostics, and evidence files;
- update documentation/PR metadata only after runtime evidence is complete.

Forbidden:

- production source edits;
- test/fixture/validator/benchmark/build-system edits;
- configure/compile/link/rebuild;
- synthetic output/counter/Euler fixes;
- fallback/recovery substitution;
- validator weakening;
- arbitrary subset search;
- count/order/frequency/ID/proximity ownership selection;
- timeout-as-correctness inference.

If the packaged tests retain the GitHub Actions absolute fixture path, expose the immutable packaged fixture tree through the same recorded runtime-only symlink technique used for G3. Do not modify packaged bytes.

## Step 1 — artifact integrity

Before any runtime execution:

1. verify GitHub artifact ID/name/run/digest;
2. compute the downloaded ZIP SHA-256 and record it separately from the GitHub digest if the transport representation differs;
3. verify internal `SHA256SUMS` digest `41064fa85fe4c68d43a44230b0aae9a8f456c961fb774c92dac5aab26a469b8f`;
4. run recursive checksum validation — expected **46/46** entries;
5. verify package structure — expected **47 files**, **27 fixture files**, five executables, two static libraries;
6. verify `metadata/source-authority.json` identifies implementation `aa0f115...`, source `6e754bdd...`, cleanup `8304ba30...`, `runtimeExecution=false`, and review policy `never`;
7. verify final source blobs:
   - diagnostics header `51f80393ecd60e32a9cddc1d60ff0d3a7e6de386`;
   - tracing header `00d849c21a5af9b871b4ad56bf31c4c74bd705b5`;
   - benchmark source `87e152f25bc2028c6f5293667712c61f21bc6a8f`;
   - tracing source `cf1d17d5966b3d6904c823046c7dbded017e35ad`;
   - pipeline source `b42681b61e2564fa55a2b67e7c7ae4890aa23d81`;
   - Phase10 tests `99976a4481bfa9daaf197e15a3b53b70336e8218`.

Stop if authority cannot be proven. Do not substitute another artifact.

## Step 2 — focused G4 relation semantics

Execute only the packaged `directional_surface_cell_producer_tests` binary with the new G4 semantic cases first:

- `SurfaceCellsPhase10.PeriodicHolonomyReverseDescriptionCanonicalizesWithoutDuplicateGenerator`
- `SurfaceCellsPhase10.PeriodicHolonomyDistinctAuthoritativeSheetsRetainEveryRelation`
- `SurfaceCellsPhase10.PeriodicHolonomySameSheetDependentBasisFailsClosedWithoutOrderChoice`
- `SurfaceCellsPhase10.PeriodicHolonomyConflictingTransportFailsClosed`
- `SurfaceCellsPhase10.ExactCommittedTorusDoesNotRejectOnlyBecauseAnotherPeriodicSheetExists`

Success criteria:

- reverse/equivalent relation descriptions collapse to one canonical generator;
- distinct authoritative sheet relations are retained without discovery-order ownership;
- unresolved same-sheet basis authority fails closed rather than selecting one;
- conflicting transport fails closed;
- exact torus does **not** terminate with the old scalar-only `InvalidPeriodicTopology` condition merely because another relation exists.

The torus test does not authorize hardcoding a relation count, translation, source route, or cut route. Record what the artifact naturally produces.

## Step 3 — retain all focused G0-G3 contracts

Execute the previously authoritative 17 focused/retained contracts. Their semantic groups are:

1. ordered authoritative source-vertex fan traversal;
2. face-row invariance of vertex fan traversal;
3. duplicate transition metadata typed rejection;
4. embedded-only relief blocking;
5. disconnected close-sheet partition;
6. close-sheet face-row invariance;
7. annulus topology derivation;
8. periodic cut/holonomy row-order invariance;
9. canonical boundary-strip breakpoints;
10. source-simplex endpoint canonicalization;
11. genuine overlap remains rejected after endpoint canonicalization;
12. field-authoritative adjacent-ring correspondence;
13. field-ambiguous ring correspondence typed failure;
14. exact artificial-cut pairing with no exterior seam;
15. malformed-holonomy typed rejection;
16. exact committed cylinder authoritative producer boundary;
17. exact committed plane authoritative producer boundary.

Expected result remains **17/17**. Any regression blocks G4 progress even if torus advances.

## Step 4 — direct G0-G3 regression matrix

Run direct `SurfaceCells` with:

- `fallbackPolicy=Fail`;
- source-grid recovery disabled;
- no legacy fallback;
- strict source-authoritative validation;
- same G3 fixture inputs/options.

For three independent processes per fixture, require deterministic output and preserve the G3 baselines:

| Fixture | Expected direct result | Output | G3 hash |
|---|---|---:|---|
| plane | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `730caeae49ec872c` |
| multi-face seam | `Produced / CompletedSurfaceCells` | 64 quads / 81 V | `5bdf34d7802e9fb0` |
| close sheets | `Produced / CompletedSurfaceCells` | 200 quads / 242 V / 2 components | `89b052762f52a5af` |
| cylinder | `Produced / CompletedSurfaceCells` | 288 pure quads / 320 V | `32135be51d7a0a26` |

Cylinder must retain:

- periodic relation `r=0`, `t=(32,0)`, route 32, cut 4 under the existing one-relation annulus contract;
- 1,728 traces;
- 290 arrangement/simplified cells;
- zero validation failures;
- exactly two genuine annulus exterior loops;
- no artificial-cut exterior seam;
- no fallback/recovery.

Treat a deterministic-hash change as a regression requiring explanation; do not update the baseline merely because the new artifact differs.

## Step 5 — exact torus mandatory observation

Use the committed `milestone-g/torus.obj` and `torus.rawfield` from the artifact, direct `SurfaceCells`, fallback `Fail`, recovery disabled.

Run at least three independent processes if the first completes within the bounded observation window.

Record:

- process exit and wall time;
- producer disposition and terminal stage;
- phase-front failure reason;
- `surfaceCellPeriodicHolonomyRelationCount`;
- every retained relation's component/sheet, `Z4` rotation, integral translation, route/cut cardinality and canonical topology signature/hash if exposed;
- trace/arrangement/simplification/completion/output counts;
- strict validation result;
- output structural hash if output exists;
- fallback/recovery counters/origin;
- deterministic equality across runs.

### Material-progress gate

The first G4 slice is material progress only when all of the following hold:

1. the torus no longer rejects solely because a second compatible periodic relation exists;
2. the relation collection is demonstrably live in diagnostics/structural authority rather than only stored transiently;
3. no relation was selected or discarded by source ID, discovery order, count/frequency, arbitrary subset, or Euclidean proximity;
4. G0-G3 focused and direct regressions remain intact;
5. no fallback/recovery is used.

Preferred result: direct strict-valid pure-quad torus production.

Acceptable first-slice progress: a **deeper truthful failure** after the canonical relation collection is retained and consumed. If that occurs, classify the earliest new failing producer/contract precisely and make it the next Code + Build target.

Not progress: merely changing a diagnostic subtype while still rejecting the same second relation, silently choosing one relation, collapsing distinct sheets, or synthesizing output through fallback/recovery.

Do not assert a torus relation count or `t=(24,0)` from the old partial diagnostic as the expected new answer. Those values are observations, not acceptance authority.

## Step 6 — prescribed sphere only after torus classification

The prescribed singular sphere is the next G4 slice, but do not let it obscure the earlier torus decision.

If torus reaches direct strict-valid production, execute a bounded sphere observation and confirm the current earliest sphere failure or success. Previous authority was:

- 766 traces;
- 30 arrangement/simplified cells;
- completion failure around repeated boundary node / parity-alternative exhaustion;
- no fallback/recovery.

If torus instead reveals a deeper G4 topology/periodic producer defect, stop after sufficient evidence to specify that defect; sphere work remains deferred.

## Step 7 — bounded default-suite regression evidence

After focused/direct gate evidence, execute the packaged suites within bounded windows:

- producer suite, excluding any deliberately long design-acceptance cases as documented;
- completion/simplification suite;
- validation suite;
- compiled API suite.

Previous G3 baseline:

- producer `100/101` with only `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` failing as scheduler/environment-sensitive timing evidence;
- completion/simplification `154/164` historical failures;
- validation `60/60`;
- compiled API `8/8`;
- bounded aggregate `322/333`.

Direct gate evidence outranks aggregate totals. Do not change semantic expectations to improve counts.

## Step 8 — benchmarks / later observations

Use the packaged `directional_benchmarks` binary only after correctness evidence.

Capture applicable wall-time and memory observations under the existing testing strategy. Later-gate bunny/vase observations may be recorded, but they do not decide G4:

- bunny's previous G3 observation was `NotApplicable`, 80,862 traces, zero output;
- vase previously exceeded a bounded 45-second observation and produced no complete record.

A timeout is failure only. Never synthesize a disposition/correctness claim from an incomplete process.

## Completion record

At turn end create one artifact-only Test + Benchmark report that includes:

- exact artifact/download/checksum/source/blob authority;
- any runtime-only fixture-path symlink with exact source and destination;
- focused G4 relation tests;
- 17/17 G0-G3 retention status;
- three-run plane/seam/close-sheets/cylinder regressions and hashes;
- exact torus relation inventory and earliest terminal behavior;
- strict validation/fallback/recovery evidence;
- bounded suite totals;
- benchmark/runtime/memory observations actually completed;
- clear G4 decision;
- exact next Code + Build plan based on the earliest remaining design contract.

Update `TODO`, `MILESTONE_G_TODO.md`, the live handoff, and PR #8 only after runtime evidence is complete. Keep PR #8 open, draft, unmerged. End with a new top-level PR #8 conversation comment as the **final repository write** for that turn.

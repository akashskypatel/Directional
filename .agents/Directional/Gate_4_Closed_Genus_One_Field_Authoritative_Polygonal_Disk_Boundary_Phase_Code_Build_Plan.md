# Gate 4 Closed-Genus-One Field-Authoritative Polygonal Disk Boundary Phase — Code + Build Plan

Status: **authoritative next turn**  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Design declaration

Before editing source, emit exactly this design state in the turn:

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: exact torus now accepts non-hard authoritative cross-sheet local boundaries and deterministically rejects at tracing/phase-front as Rejected / InvalidBoundedDiskBoundaryPhase with no source face attached to the failure
Missing design contract: the curved-disk producer currently models every field-compatible disk boundary as exactly four global runs in rectangular U+, V+, U-, V- order; a source-authoritative disk boundary may instead require a more general ordered field-labeled orthogonal/polygonal boundary and singularity-compatible corner phase
Smallest general implementation change: make ordered transported boundary runs/corners first-class, validate their cyclic 4-RoSy turning/closure intrinsically, preserve the existing four-run rectangular path exactly, and construct a deterministic source-authoritative polygonal disk phase chart for valid non-rectangular boundaries without arbitrary run coercion
Observable material-progress condition: generalized boundary-phase regressions compile and package; the following exact artifact-only torus run advances beyond InvalidBoundedDiskBoundaryPhase to Produced/materialization or the next genuinely deeper typed chart/front-pairing invariant while source-sheet-boundary 3/3, combined curved-disk 9/9, sheet coverage 3/3, G4 relation 5/5, retained G0-G3 17/17 and exact direct hashes remain unchanged
Explicitly deferred: repair of any later chart/front-pairing/materialization invariant until runtime reaches it, prescribed sphere until torus materialization closes, G5 adaptivity/features, G6 bunny/vase production, historical completion/simplification failures, validator/performance-threshold changes, fallback/recovery and unrelated optimization
```

## Runtime evidence that controls this turn

Exact runtime authority is artifact **`9019024467`** (`g4-source-sheet-boundary-code-build`), implementation `b425898fa7367406fa0c07e8f4441a37efc01315`.

The artifact proves:

- source-sheet-boundary semantics **3/3**;
- source-sheet-boundary + curved-disk group **9/9**;
- sheet coverage **3/3**;
- G4 periodic relations **5/5**;
- retained G0-G3 **17/17**;
- direct plane/seam/close-sheets/cylinder exact hashes remain `730caeae49ec872c`, `5bdf34d7802e9fb0`, `89b052762f52a5af`, `32135be51d7a0a26`, deterministic 3/3;
- exact torus is deterministic 3/3 as `Rejected / InvalidBoundedDiskBoundaryPhase` at `tracing/phase-front`, first invalid face `-1`, with periodic authority still live and no fallback/recovery;
- bounded suites are producer **115/116**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **337/348**.

Read `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Report.md` before source edits.

## Exact current boundary-phase limitation

In the curved bounded-disk producer, after topology and reciprocal transport succeed:

1. every ordered boundary edge is assigned its best transported branch/family/sign;
2. ambiguous/weak per-edge classification fails typed;
3. contiguous equal branch labels are grouped into ordered boundary runs;
4. production currently requires exactly four runs;
5. the first run is canonicalized geometrically;
6. the cyclic sequence must be one quarter-turn progression equivalent to `U+`, `V+`, `U-`, `V-`;
7. those four runs become the four sides of a rectangular harmonic chart.

Exact torus fails with no source face attached, which rules against claiming a specific per-edge alignment failure from current evidence. Existing diagnostics do not expose the rejected run count/sequence. Do not infer one.

## Required production contract

Introduce a reusable first-class boundary-phase representation, conceptually containing at least:

- ordered source boundary edge intervals/routes;
- transported global branch identity and family/sign for each run;
- canonical source-attached start/end corners;
- signed quarter-turn change between adjacent runs;
- cumulative intrinsic boundary length;
- exact source component/sheet ownership;
- hard-feature/source-boundary/source-sheet-rail provenance;
- cyclic closure / cross-field index evidence;
- canonical structural identity independent of source face-row enumeration.

The representation must be derived only from source topology, source geometry used for canonicalization, and reciprocal transported 4-RoSy state. Raw face/edge IDs may remain provenance but cannot select semantic ownership/order beyond exact source adjacency. Counts/frequency/proximity/discovery order cannot choose a boundary model.

### Boundary validity

A generalized disk boundary is acceptable only when:

- every edge is already an authoritative local boundary under existing source/hard-feature/sheet rules;
- every run has unambiguous transported field phase under the existing meaningful alignment contract;
- adjacent runs have a valid 4-RoSy corner turn;
- cyclic turn accumulation is compatible with the disk's field/singularity index contract;
- corner/source provenance is exact;
- canonicalization is deterministic under face-row re-enumeration and reversed equivalent descriptions;
- no run is inserted, removed, merged or split merely to reach a desired side count.

If closure, corner phase, or field authority is ambiguous/inconsistent, return a precise typed `Rejected` boundary-phase reason. Do not fall through to generic traces.

## Generalized chart target

Preserve the existing four-run rectangular implementation as a semantic fast path when the first-class boundary phase is exactly the current valid rectangular case.

For a valid non-rectangular boundary, construct an **intrinsic field-authoritative orthogonal/polygonal disk domain** from the ordered run/corner phase:

- side direction comes from transported family/sign, not world axes;
- side length comes from intrinsic source-boundary length;
- signed corner turns come from the transported branch transition;
- the polygon must close within the same numerical authority used for intrinsic chart construction, with no arbitrary corrective edge or Euler adjustment;
- concave/reflex corners are allowed only when justified by signed field turns;
- map source boundary vertices monotonically to their exact polygon side intervals;
- solve interior chart coordinates with a deterministic positive-weight disk parameterization compatible with the polygonal boundary;
- validate every source triangle for finite, nondegenerate, orientation-consistent chart geometry;
- preserve exact source-triangle/barycentric provenance when locating lattice/front geometry.

If the polygonal harmonic chart is mathematically valid but the existing positive-weight solve folds on a legitimate non-convex domain, fail typed as the next chart invariant rather than hiding the fold. A later Code + Build may then introduce a stronger bijective disk parameterization. Merely renaming the current boundary-phase failure to a chart failure without creating and consuming real boundary-phase authority is not material progress.

## Front/lattice behavior

Do not implement post-hoc cell merging to fit the polygon.

Instead:

- derive admissible integer phase/lattice lines from the generalized intrinsic chart and transported field families;
- clip/trace them against the source-authoritative polygonal chart domain;
- retain ordered exact source-triangle routes for emitted segments;
- pair cell sides through exact chart/lattice/source authority;
- leave genuine authoritative boundary sides exterior;
- reject ambiguous T-junction/front pairing through existing or new precise typed reasons;
- keep one accepted authoritative cell -> one output quad.

If this front construction is too large to close safely in one turn, it is acceptable for the implementation to create and validate the generalized boundary-phase/polygonal chart first and then fail at a **truthful deeper chart/front-pairing invariant**, provided the following Test + Benchmark proves the torus consumes the new first-class representation and advances beyond `InvalidBoundedDiskBoundaryPhase`. Do not synthesize advancement through reason relabeling.

## Required compile-only tests

Add behavioral regression coverage without executing it in this Code + Build turn.

At minimum compile:

1. **Existing rectangular curved disk remains exact** — current synthetic curved-disk geometry must produce the same structural geometry/hash semantics and source ownership through the preserved rectangular path.
2. **Non-rectangular field-authoritative disk boundary** — construct a natural disk mesh whose authoritative boundary forms a source-attached orthogonal polygon with more than four transported boundary runs (for example an L-shaped intrinsic domain with a genuine reflex corner); require boundary-phase extraction/producer progression without run coercion.
3. **Invalid cyclic field turn fails closed** — same or closely related topology with one incompatible transported boundary phase must reject typed, not normalize the run sequence to pass.
4. **Row-order invariance** — equivalent face-row re-enumeration of the generalized polygonal disk preserves canonical boundary phase and produced/progressed structural identity.
5. **Source-sheet-boundary composition** — the new polygonal representation must retain a non-hard authoritative cross-sheet local boundary and continue to reject the same-sheet hidden-cut control.
6. **Hard-feature retention** — hard-feature runs/corners remain authoritative; no feature demotion to obtain polygon closure.
7. **Mixed planar/periodic/curved composition** — complete exact-once source-sheet aggregation and every periodic relation remain unchanged when a polygonal curved disk is present.
8. **Exact torus advancement contract** — exact committed torus must no longer terminate at `InvalidBoundedDiskBoundaryPhase` once the generalized boundary phase is applicable. The test may accept a later truthful typed chart/front-pairing/materialization invariant until runtime validation decides the next gate.

Do not encode the exact torus's observed run count, source face IDs, relation count, feature count, or boundary lengths in production or test success logic unless a test independently establishes a general mathematical invariant.

## Regression invariants that must remain unchanged

- source-sheet-boundary semantics 3/3;
- combined source-sheet-boundary + curved-disk semantics 9/9;
- sheet-coverage semantics 3/3;
- G4 periodic-relation semantics 5/5;
- retained G0-G3 focused contracts 17/17;
- plane direct hash `730caeae49ec872c`;
- seam direct hash `5bdf34d7802e9fb0`;
- close-sheets direct hash `89b052762f52a5af`;
- cylinder direct hash `32135be51d7a0a26`, one relation `r=0`, `t=(32,0)`, route 32, cut 4, two true exterior loops;
- no passing direct fallback/recovery;
- exact-once source-sheet aggregation and first-class periodic-relation hashing/materialization;
- strict validators unchanged.

## Explicit prohibitions

Do **not**:

- change `runStarts.size() != 4` to generic success without a new consumed boundary representation;
- arbitrarily merge/split/delete boundary runs to manufacture four sides;
- lower or inflate the boundary alignment threshold merely to make a fixture pass;
- demote hard features or source-sheet rails;
- create artificial disk-to-annulus cuts to reuse periodic code;
- choose semantic corners by raw source IDs, count, order, frequency, discovery order, nearest point or proximity;
- perform arbitrary subset search over candidate corners/runs;
- add synthetic topology counters, Euler correction or closing edges;
- weld chart/output geometry in Euclidean space;
- merge cells post hoc to conceal a front failure;
- weaken validators;
- route authoritative rejection into fallback/recovery;
- special-case torus, fixture names, expected counts or exact IDs;
- treat timeout as correctness.

All existing project prohibitions in the handoff remain mandatory.

## Build-only execution

This is **Code + Build only**.

Allowed:

- edit production source/header/test source required by this contract;
- edit diagnostics/documentation/build packaging when necessary;
- configure Release/static/Ninja with GoogleTest discovery deferred to `PRE_TEST`;
- compile/link the approved targets;
- package exact source, binaries, immutable fixtures, metadata, logs and recursive checksums.

Forbidden:

- executing generated Directional test binaries;
- executing benchmarks;
- `ctest` or GoogleTest discovery execution;
- generated CLI/GUI/help/list/version/smoke/custom-input execution;
- any runtime correctness claim.

Compile/package the same seven approved targets:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Artifact metadata must record `runtimeExecution=false`. Preserve detailed logs on success/failure and package an exact recursive checksum manifest.

## Following Test + Benchmark decision

The next artifact-only Test + Benchmark turn must execute the exact new build artifact and, in order:

1. verify artifact/source/blob/checksum authority;
2. run new generalized boundary-phase semantics first;
3. retain source-sheet-boundary 3/3 and combined curved-disk authority;
4. retain sheet coverage 3/3, G4 relation 5/5 and G0-G3 17/17;
5. retain exact direct plane/seam/close-sheets/cylinder hashes in three independent processes;
6. run exact torus in at least three independent processes.

Preferred result is `Produced`, complete materialization, and strict-valid closed pure-quad torus output with complete provenance and no fallback/recovery.

Acceptable material progress is a deeper deterministic truthful typed `InvalidBoundedDiskChart`, `InvalidBoundedDiskFrontPairing`, or later materialization invariant **only if** the runtime evidence proves the generalized ordered boundary phase is valid and consumed and the old `InvalidBoundedDiskBoundaryPhase` result is eliminated for structural reasons rather than relabeling.

Prescribed sphere remains deferred unless torus reaches direct strict-valid production.

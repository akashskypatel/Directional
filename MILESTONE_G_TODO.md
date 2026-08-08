# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Runtime authority — artifact 9019024467

The current runtime-proven authority remains exact artifact **`9019024467`** until the polygonal boundary candidate executes:

- source-sheet-boundary semantics **3/3**;
- combined source-sheet-boundary + curved-disk semantics **9/9**;
- sheet coverage **3/3**;
- G4 relation semantics **5/5**;
- retained G0-G3 **17/17**;
- direct plane/seam/close-sheets/cylinder hashes unchanged and deterministic 3/3;
- no passing direct fallback/recovery;
- exact torus `Rejected / InvalidBoundedDiskBoundaryPhase` at `tracing/phase-front`, periodic authority live, no downstream cells/fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Report.md`.

## G4 polygonal boundary-phase Code + Build complete

Exact candidate **`9021175280`** (`g4-polygonal-boundary-phase-code-build`) is compile-valid and awaiting artifact-only runtime validation.

- implementation `085db9ec23ffaa509b1f5a29e72968229efa103d`;
- cleanup `c3b5dcbcd0c35ee421d5b44273c142aa9f874dcc`;
- workflow run/job `31254896323 / 93096734152`;
- ZIP SHA-256 `16191e84bcfcebb2cfc1401b4aae7d5d8de2a02444f189a54d68164c1327a646`;
- internal manifest SHA-256 `a8161eb579e1c06e63b5c7bc6203f610693f3e6259f56d8ce2c6ba78e424d3b5`;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two project static libraries;
- approved build **111/111**;
- log artifact `9021175444`, SHA-256 `170c8d869af4ec737250a1a5ce7dfb532ca76fbef972a696cea85a53c61b0f67`;
- `runtimeExecution=false`.

The candidate introduces first-class ordered bounded-disk boundary phases/runs carrying transported branch family/sign, signed quarter-turn corner changes, exact source boundary provenance, intrinsic lengths, chart coordinates, cyclic index evidence and deterministic phase hashes.

Required invariants implemented for the candidate:

1. authoritative boundary-edge classification remains unchanged;
2. per-edge field alignment threshold remains unchanged;
3. adjacent transported runs must differ by a reciprocal ±quarter-turn or fail `InvalidBoundedDiskBoundaryTurn`;
4. oriented cyclic disk index must close to the valid winding or fail `InvalidBoundedDiskBoundaryIndex`;
5. the existing four positive-turn rectangle remains the exact fast path;
6. valid non-rectangular phases develop from their real run sequence and intrinsic lengths into an orthogonal polygon with no inserted/deleted/merged/split/corrective runs or edges;
7. polygon closure, positive area, self-intersection, harmonic chart and triangle orientation are checked explicitly;
8. successfully constructed non-rectangular charts intentionally stop at the deeper `InvalidBoundedDiskFrontPairing` invariant because generalized polygon lattice clipping/pairing is not yet implemented;
9. phase/run/chart state is retained by aggregation, structural hashing and runtime diagnostics, so advancement cannot be established by reason relabeling alone;
10. no partial cells, fallback/recovery, feature demotion, positional welding, validator change or torus/ID/count special case is introduced.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Code_Build_Report.md`.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Field_Authoritative_Polygonal_Disk_Boundary_Phase_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against artifact `9021175280`.

Required decision order:

1. verify exact artifact/source/blob/checksum/command-boundary authority;
2. execute new generalized boundary-phase semantics first;
3. retain source-sheet-boundary, prior curved-disk, sheet coverage, G4 relation and G0-G3 focused authority;
4. retain exact deterministic direct plane/seam/close-sheets/cylinder baselines;
5. classify exact torus across at least three processes using the new phase/run/chart diagnostics.

Preferred result is direct strict-valid torus production. The intended bounded material-progress result is a genuinely constructed/consumed polygonal boundary phase/chart followed by truthful `InvalidBoundedDiskFrontPairing`; if reached, the next Code + Build target is generalized polygonal lattice clipping/front pairing. An earlier typed turn/index/chart failure must be diagnosed from actual first-class runtime evidence and must not be forced to pass.

## Bounded suite baseline

Entering baseline remains producer **115/116**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **337/348**. New tests change cardinality only after they actually execute; record observed totals, never predict them as evidence.

Prescribed sphere remains deferred until torus reaches authoritative materialization/direct strict-valid production. G5/G6 and historical completion/simplification repair remain deferred. Review policy remains `never`.

Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.

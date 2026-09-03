# M3-CP4c-3-CB22 Code + Build Report

## Turn identity

- Phase: `M3-CP4c-3-CB22`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: canonical Code + Build, diagnostic-only
- Starting semantic base: `9f6f3794add4f62c05d6c8726d199abd9e0a1872`
- Built evidence commit: **`c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`**
- Remote synchronization: verified before the authoritative build
- Runtime tests/benchmarks executed: **none**

## Implemented

CB22 discharges the frozen `BV0–BV9` diagnostic scope from
`Architecture_M3_CP4c3_TB19_Independent_Review_Record.md` §10 without changing the seeding decision.

The `UncutFaceComponentOrbitSeedNotUnique` failure now retains:

- component identity;
- exact seed count and typed `seedState ∈ {None, Multiple}`;
- component face count, bounded membership and explicit truncation;
- bounded component boundary-edge rows with edge key, labeled-side state, neighboring owner count, barrier class,
  contributed seed or exact non-contribution/skip reason, including non-unique `edgeOrbitEvidence`;
- explicit source-face locus kind identifying `sourceFace` as the first unlabeled face in iteration order.

The existing `TraceFragmentOwnerEvidenceDiagnostic` census is extended with bounded component-seed census rows.
Production-path tests cover each new evidence surface, and a byte-identical unrelated-error regression witness
guards the pre-existing projection. Selector 384 remains byte-identical; selector 385 appends only the four new
diagnostic witnesses.

## Engineering-guideline review

- Material assumption: zero seeds and multiple seeds require opposite future corrections, so this turn is
  observational only.
- Simplest sufficient approach: retain already-computed component/seed/boundary state at the existing failure and
  project it through the existing diagnostics path.
- No speculative product correction, new authority, fixture rewrite, tolerance change, or 371/372 decoupling was
  introduced.
- `localFragmentCount` remains non-fatal.
- Every changed production/test line traces to `BV1–BV7`; selector changes trace only to `BV6`.

## Files changed

Semantic evidence commit `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131` contains CB22 changes in:

- `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_385.txt`
- `include/directional/diagnostics/RemeshDiagnostics.h`
- `include/directional/geometry/GlobalTopologyPlan.h`
- `src/geometry/GlobalTopologyPlan.cpp`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldAlignedCurveNetworkTests.cpp`

A compile-only correction in the same evidence commit initializes
`UncutFaceComponentBoundaryEdgeDiagnostic` with its required `SourceEdgeTopologyKey` at construction rather than
default-constructing the non-default-constructible aggregate. This changes no runtime semantics.

## Frozen-selector audit

- accepted selector 365: 365 identities, SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- selector 384: 384 identities, SHA-256 `c9425b9309415d43d49e5791cc43fd5e5e3bf3ae50d02c329c65d3e632a05564` — **byte-identical to TB19 authority**;
- selector 385 file: **388 identities**, SHA-256 `164a8b25118a4d00fc9261e4645795ad396130b6d6ea4dd8784158b76e1d0fca`;
- selector 384 is an exact prefix of selector 385;
- appended identities, in order:
  385. `GlobalTopologyPlan.UncutFaceComponentSeedFailurePublishesProductionDecisionEvidence`
  386. `GlobalTopologyPlan.UncutFaceComponentSeedFailureProjectsDecisionAndBoundaryEvidence`
  387. `GlobalTopologyPlan.FragmentOwnerEvidenceProjectsUncutComponentSeedCensus`
  388. `GlobalTopologyPlan.UnrelatedFailureProjectionIsByteIdenticalWithoutUncutSeedDiagnostics`

Accepted semantic authority remains **365/365**. No CB22 runtime result exists yet.

## Build

First compile attempt on source `9f6f3794add4f62c05d6c8726d199abd9e0a1872` failed at
`GlobalTopologyPlan.cpp:1204` because `UncutFaceComponentBoundaryEdgeDiagnostic row;` attempted to invoke a deleted
default constructor inherited from `SourceEdgeTopologyKey`. The correction was the minimum compile-only aggregate
initialization change.

Authoritative corrected compile:

- run/job: **`33805683152 / 100815534364`**;
- source: **`c5d3c65936e14e1c3e2c8afcffbc4236f37aa131`**;
- result artifact: **`9912976409`**, ZIP SHA-256 **`b4cbcbf5304ff94bd815790264ac360fa1275f23b3af2080cffda381a698a851`**;
- diagnostic log artifact: **`9912977164`**, ZIP SHA-256 **`583621ab73e508fccafefddca3351f5ac1a3681761e33e4468800f50242287ff`**;
- packaged source archive SHA-256: **`cec7db850646ffc4c2de0ed1515afc42d544f989ec83ca20055c30accd9929d3`**;
- build/preflight exit codes: `0 / 0`;
- final source status: clean;
- exact arithmetic backend: **GMP**;
- generated link evidence contains both `libgmpxx.so` and `libgmp.so`;
- `runtimeExecution=false`.

All eight required targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional binary, test, benchmark, discovery command, CLI, fuzzer, help/version command, or custom
input was executed.

## Domain invariants / BV closure

- **BV0:** discharged statically/build-only; accepted 365 untouched, selector 384 byte-frozen, eight GMP targets
  compile.
- **BV1–BV5:** implemented as typed retained diagnostics/projection only.
- **BV6:** production witnesses plus unrelated-error byte-identity witness appended after selector 384.
- **BV7:** semantic seeding predicates/partition/barriers/seed construction and downstream topology logic unchanged.
- **BV8:** accepted 1–365 cannot observe the added diagnostics unless the new typed failure surface is reached;
  runtime confirmation is deferred to TB20.
- **BV9:** frozen into the TB20 plan below; no discriminator is claimed before runtime.

## Known risks

CB22 intentionally does not determine the mechanical witness's `seedState`; only TB20 may do so. If ordinal 366
moves away from `UncutFaceComponentOrbitSeedNotUnique`, the diagnostic-only assumption is falsified and TB20 must
record that as semantic red evidence rather than reinterpret it as success.

## Mandatory Test + Benchmark plan

Plan: `Architecture_M3_CP4c3_TB20_Artifact_Only_Test_Benchmark_Plan.md`.

Evidence under test is exactly source `c5d3c65936e14e1c3e2c8afcffbc4236f37aa131` from result artifact `9912976409`. TB20 must remain
artifact-only and execute selector 385 in full, one identity per fresh process, preserving the accepted 1–365
prefix and all six `BV9` discriminators.

## Next turn

**`M3-CP4c-3-TB20` — Test + Benchmark, artifact-only.**

No TB20 runtime was executed during CB22.

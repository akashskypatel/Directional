# Design-Aligned Uniform Phase-Front Code + Build Plan

## Turn type

Code changes plus compile-only build. Do not execute tests, benchmarks, CLI, GUI, discovery, or generated project binaries.

## Authority

- Runtime baseline: artifact `8974081923` test report.
- Exact tested source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`.
- Design authority: `.agents/Directional/DESIGN.md`.
- Remediation authority: `.agents/Directional/REORIENTATION_PLAN.md`.
- Testing authority: `tests/TESTING_STRATEGY.md`.

## Goal

Create the smallest general phase-labelled surface-front producer that can construct direct source-attached cells on the uniform plane fixture without fallback, source-grid recovery, post-hoc cycle decomposition, or pair-local fan interval inference.

The change must be general and source-chart based. No fixture names, vertex IDs, face IDs, expected counts, or geometry-specific thresholds may enter production code.

## Scope A — finish default-test hygiene

Make only the following surgical suite corrections:

1. Move `StrictValidatorOverheadStaysBelowFivePercent` out of the default correctness target into optional benchmark/closeout coverage.
2. Move the exact route-ledger and incremental-recomputation-counter tests out of the default completion target and into historical coverage:
   - `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
   - `OneCandidateBudgetIsExactAndDoesNotRecurse`.
3. Correct `PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion`:
   - preserve its exact rollback assertions;
   - use valid source-supported completion geometry when success is intended; otherwise assert deterministic fail-closed rejection.
4. Reconstruct the Phase 17 fixtures whose stated precondition is absent. Do not synthesize counters or weaken assertions. A fixture stays in the default target only when it creates a valid embedded complex and reaches the intended simplification behavior.

These edits must not reduce or weaken the four direct acceptance cases.

## Scope B — explicit uniform lattice state

Add first-class local phase state, independent of any global MIQ coordinate field:

```cpp
struct LocalLatticeState {
  Eigen::Vector2d phase;
  Eigen::Vector2i latticeCoordinate;
  int branchRotation = 0;
  int scaleLevel = 0;
};

struct SurfaceFrontEdge {
  SurfacePoint from;
  SurfacePoint to;
  int fieldFamily = 0;
  int advanceSign = 1;
  LocalLatticeState lattice;
  int unfilledSide = 0;
  SourceRouteIdentity route;
};
```

The concrete names may follow project conventions, but equivalent information must be authoritative and serializable for deterministic hashing.

## Scope C — source-chart phase transport

Reuse the existing source-chart transition graph and cross-field matching to transport:

- selected cross branch;
- quarter-turn rotation;
- local phase;
- integer lattice coordinate;
- route, sheet, and component provenance.

A transition is valid only when component, local sheet, source entity, and orientation agree. Missing or inconsistent transport fails closed.

## Scope D — bounded front construction

Implement only the uniform-size events required for the first proof:

```text
CompatibleFrontMerge
BoundaryTermination
HardRailCapture
PhaseMismatch
PeriodicHolonomyConflict
```

For the plane proof:

1. Tessellate and seed the authoritative boundary.
2. Advance front edges by one target size through intrinsic surface walking.
3. Create a quad only after all four source-attached corners and directed sides are phase compatible.
4. Give every directed front edge exactly one filled side or an explicit exterior classification.
5. Emit already-decided embedded cells or front cycles to arrangement.

Arrangement may canonicalize identities, split exact crossings, materialize halfedges, and validate. It must not choose fan-sector pairings to invent cell connectivity for this producer path.

## Scope E — bounded integration

- Preserve the current implementation behind an internal path while the proof is incomplete; do not delete validated provenance or extraction machinery.
- Route only the uniform proof path through the new producer under an explicit internal option or clearly delimited stage.
- Keep fallback `Fail` and source-grid recovery disabled in direct acceptance.
- Do not add adaptivity, 2:1 transitions, torus or sphere handling, general FlowRep simplification, general patch completion, or bunny work in this turn.

## Compile-only verification

Compile exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Use Release `-O2 -DNDEBUG`, static libraries, recursive shallow submodules, and `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`. Package the five executables, two libraries, fixture closure, exact source archive, source/event commits, compile database, logs, and checksums for the next artifact-only turn.

## Next runtime acceptance

The next Test + Benchmark turn must run in this order:

1. Plane direct acceptance.
2. Multi-face seam.
3. Close sheets.
4. Cylinder.
5. Remaining default suites.

Material progress requires the plane to produce non-empty source-authoritative pure-quad `CompletedSurfaceCells` output, or for its first invalid producer to advance with a general phase-front invariant. A different diagnostic string or fan-interval classification is not progress.

## Preserved prohibitions

- no validator weakening;
- no fallback or source-grid recovery substitution;
- no fixture or ID special cases;
- no arbitrary subset search;
- no count, order, or frequency ownership selection;
- no positional merging across unrelated sheets;
- no post-hoc cycle decomposition or cell merging;
- no synthetic counters or Euler correction;
- no timeout-as-correctness.

# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [accepted baseline; candidate regressed] → G1 uniform phase-front plane [accepted baseline; candidate regressed] → G2 cross-chart / close-sheet isolation [accepted baseline; candidate regressed] → G3 periodic closure / holonomy [accepted baseline; candidate regressed] → **G4 topology-distinct completion and singularities [active, blocked]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Completed artifact-only Test + Benchmark

Exact candidate artifact **`9024549134`**, implementation `7f486632b154a303789df6c4dd44f602c8c71281`:

- workflow run/job `31267020112 / 93126709005`;
- build/cleanup `718b978dcd0fab66da67810e00661468fc11038f`;
- outer SHA-256 `4d58454694668aecd30c394168dcceee9f01d5cb2999f111eefd1a720d2d80dd`;
- internal manifest `d882776c1f92543ff9d2ca8b6acd5d4662419e2f2f4316afc505579db6e29ef5`;
- recursive checksums **48/48**;
- Release/static/Ninja **111/111**, `runtimeExecution=false`;
- exact source/dependency/fixture/log authority verified before runtime;
- no source/test/build edit, configure, rebuild, or artifact substitution.

Runtime report:
`.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md`

## Runtime results

Focused/retained groups:

- transition quotient / retained authority **3/7**;
- topology-region/isolation **8/9**;
- polygonal boundary phase **3/5**;
- non-torus curved disk **2/5**;
- mixed sheet coverage **0/2**;
- periodic relations **4/5**;
- validation **60/60**;
- compiled API **8/8**.

Direct deterministic matrix, three processes each:

| Fixture | Result | First invalid authority |
|---|---|---|
| plane | failure 3/3 | `InvalidFrontBoundaryAuthority` |
| multi-face seam | failure 3/3 | `InvalidFrontBoundaryAuthority` |
| close sheets | failure 3/3 | `InvalidFrontBoundaryAuthority` |
| cylinder | failure 3/3 | `InvalidFrontBoundaryAuthority` |
| torus | failure 3/3 after phase-front `Produced` | `UnconsumedAuthoritativeIsolationSeam` |

No direct case produces output or uses fallback/recovery.

Bounded suites:

- producer **99/128**;
- completion/simplification **154/164**, unchanged historical ten;
- validation **60/60**;
- API **8/8**;
- aggregate **321/360**.

## Blocking design facts

### Genuine source boundary

`edge_matching_indices()` deliberately maps only two-face interior source edges. `assign_open_front_boundary_authority()` requires that index before it can classify a one-face edge as `GenuineSourceBoundary`. The representation therefore rejects valid source boundaries by construction.

Review must separate canonical source-edge topology identity from the optional interior transition/matching index without weakening interior transport provenance.

### Internal isolation-seam consumption

Exact torus retains four topology regions, eight internal isolation seams, and four periodic relations, but materialization records `0/0/0` consumed. Current code requires every retained seam topology to appear in cell-boundary `transitionSourceEdges`.

Review must define the exact first-class consumption witness and reject unconditional marking, representative-sheet selection, position/lattice welding, and count/order/ID/proximity inference.

### Executable counterfactual coverage

The semantic-digest invariance and mutation tests exist only in `tests/MilestoneGP27Tests.cpp`, under disabled `DIRECTIONAL_BUILD_HISTORICAL_TESTS`. They are absent from the package. Several other review-required counterfactuals are missing as independently discoverable default tests, including retain-true versus retain-false.

Compile success and source inspection cannot substitute for executing them from an immutable artifact.

## Mandatory next turn

**Independent Review only** under:

`.agents/Directional/Gate_4_Transition_Quotient_Runtime_Regression_And_Executable_Coverage_Mandatory_Design_Review_Plan.md`

The configured optional policy remains `never`; retained regression and zero quotient consumption activate the mandatory process-guard override.

Review must:

1. approve a general boundary topology/index representation;
2. approve an exact seam-consumption witness;
3. audit every quotient/topology/retention/digest counterfactual;
4. choose default packaged test targets that expose every active-gate case;
5. approve, amend, or replace the `proposed_pending_review` Code + Build scope in the runtime report.

## Acceptance after a future reviewed Code + Build

A future immutable artifact-only turn must require:

- every reviewed focused counterfactual discoverable and passing;
- retained topology/polygonal/curved/mixed/periodic/G0-G3 authority restored;
- validation **60/60** and API **8/8** retained;
- plane/seam/close-sheets/cylinder direct success and determinism 3/3;
- semantic-digest row/component invariance and connectivity/winding/source-support/component/lineage sensitivity;
- exact torus direct strict-valid pure quads, complete lineage, one component, zero boundary loops, Euler zero, and all four regions/eight seams/four relations consumed;
- no predicted/golden torus output count;
- no fallback/recovery or source-grid substitution.

Sphere remains deferred until torus closes. G5/G6, bunny/vase runtime, historical completion repairs, validator threshold changes, and unrelated optimization remain deferred.

Every completed turn ends with a new top-level PR #8 conversation comment as the final repository write. PR #8 remains open, draft, unmerged.

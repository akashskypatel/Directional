# Gate 1 Authoritative Producer Boundary — Code + Build Plan

## Turn declaration

```text
Active design gate: Gate 1 — uniform phase-front plane
Earliest failing fixture: plane__surface_cells
Missing design contract: authoritative producer applicability, production, and rejection must be distinct first-class outcomes; an applicable producer rejection may not silently substitute the generic tracing/completion producer
Smallest general implementation change: replace the implicit phaseFront.succeeded/fall-through selection with an explicit authoritative producer disposition and preserve immutable rejection authority
Observable material-progress condition: exact committed plane production coverage proves the authoritative producer outcome before generic stages, and a Rejected plane cannot generate the prior 106/9/12 generic completion path; preferred closure is direct plane success while preserving seam direct success
Explicitly deferred work: close-sheet completion, cylinder holonomy, singularities, adaptive later-gate topology, bunny/vase success, performance, cache/memory tuning, validator timing, historical completion cleanup
```

## Turn boundary

This is a **Code + Build** turn.

- Production source and valid producer-level regression tests may be edited only within the bounded producer-authority scope below.
- Do not execute generated project binaries, tests, benchmarks, discovery, CLI, GUI, help, or list commands.
- Compile exactly the approved seven targets.
- GitHub Actions may be used for configure/compile/link and immutable artifact production under `.agents/Directional/GitHub_Workflow_Policy.md`.
- Keep PR #8 open, draft, and unmerged.

## Architectural authority

Read first:

1. `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`;
2. `.agents/Directional/DESIGN.md`;
3. `.agents/Directional/Future_Chat_Session_Handoff.md`;
4. latest Test + Benchmark report;
5. `tests/TESTING_STRATEGY.md`.

The selected strategy is **Outcome B — bounded producer replacement proof**. Another isolated predicate patch is prohibited.

## Replacement boundary

Replace only the producer-selection/authoritative-phase-front boundary around `build_surface_cell_network()` / `build_uniform_phase_front()` and its pipeline consumption. Do not rewrite unrelated FlowRep, arrangement, generic completion, optimizer, validator, fallback, or recovery code.

Introduce a first-class disposition equivalent to:

```cpp
enum class SurfaceCellProducerDisposition {
  NotApplicable,
  Produced,
  Rejected
};
```

The exact type/name may follow repository conventions, but these three semantic states must remain distinct.

### Semantics

- `NotApplicable`: the authoritative phase-front representation does not yet cover this topology; a separately selected later producer may run.
- `Produced`: complete authoritative cells/fronts exist and are materialized directly one cell to one quad.
- `Rejected`: the producer was applicable and encountered a fail-closed invariant violation; preserve the typed reason and stop the `SurfaceCells` request at the producer boundary. **Do not generate generic seeds/traces/proposals.**

Do not encode rejection as `succeeded=false` followed by implicit fall-through.

## Applicability proof

Applicability must be explicit and deterministic before producer execution. It may use general topology/field properties, never fixture identity.

For this bounded proof:

- the uniform planar Gate 1 plane is applicable;
- the proven planar reciprocal-quarter-turn Gate 2 seam is applicable;
- later nonplanar, periodic, singular, or otherwise unsupported topology may remain `NotApplicable` until its authoritative producer extension is implemented.

An applicable input with malformed/inconsistent metadata is `Rejected`, not `NotApplicable`.

## First-class input contract

The authoritative producer must receive or consume explicitly:

- source `V/F` and canonical source-edge topology;
- finalized `CrossFieldResult`, including matching, effort, and edge transitions;
- production target-size vector;
- source component/local-sheet labels;
- hard-feature constraints;
- relief-barrier set **and `reliefBarriersEmbedded` state**;
- authoritative rails/features where already consumed;
- exact tracing and transport options.

Avoid parallel copies of semantically equivalent metadata whose authority cannot be determined.

## Transport contract retained from previous work

Preserve:

- exact per-face branch state;
- canonical source-edge transition identity;
- strict reciprocal forward/reverse quarter-turn transport;
- ordinary shared-edge crossings;
- ordered source-vertex fan crossings;
- complete ordered source-edge route provenance;
- exact source component/sheet ownership;
- source-normal-consistent cell orientation;
- one accepted authoritative cell → exactly one quad.

Correct the semantic barrier inconsistency generally: `reliefBarrierEdges` may veto authoritative phase transport only when `reliefBarriersEmbedded == true`, matching the documented tracing option contract. Hard-feature barriers remain authoritative constraints.

This is part of the producer-boundary replacement because the producer must consume the same authority semantics as the pipeline, not a fixture-specific plane fix.

## Immutable rejection authority

When disposition is `Rejected`:

- retain the typed phase-front rejection reason and source context;
- preserve it as the first-invalid producer authority;
- do not overwrite it with later completion/output-validation diagnostics because those stages must not execute for that producer attempt;
- ensure debug/runtime structural hashing includes the disposition and rejection identity;
- do not synthesize downstream stage counters.

## Required producer-level tests

Retain all existing narrow source-vertex tests unchanged in strength.

Add tests that exercise production contracts rather than recreated expected output:

### Exact committed plane production route

Load the committed `plane.obj` and `plane.rawfield` and use the same production preprocessing/input construction as the real pipeline, including:

- `finalize_surface_cell_raw_cross_field`;
- production adaptive target-size calculation;
- source component/sheet classification;
- feature/relief state;
- production tracing options.

Assert the authoritative producer disposition **before generic downstream stages**.

The test must not inject a convenient constant target, fabricated labels, fixture-specific edge IDs, or preconstructed matching/transitions.

### Producer rejection cannot substitute generic producer

Construct a valid applicable domain whose authoritative metadata is intentionally invalid under a real contract. Assert:

- disposition `Rejected`;
- typed reason retained;
- no generic seeds/traces/proposals are generated;
- no completion path becomes the first-invalid producer.

### Relief authority semantics

- non-embedded relief guidance does not veto an otherwise valid authoritative transition;
- the same edge marked embedded can block according to the existing relief contract;
- no validator or feature semantics are weakened.

### Seam mandatory regression

The existing multi-face seam direct acceptance must remain unchanged in strength and continue to require authoritative direct pure-quad output, reciprocal transport, no fallback/recovery, and deterministic provenance.

### Mandatory production fixtures

Keep bunny and vase integrity/topology and direct acceptance fixtures mandatory. Do not special-case or simplify them. They remain later-gate observations until earlier gates close.

## Compile-only verification

Configure/build Release static `PRE_TEST` and compile exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

No generated project binary may be executed in this turn.

Package:

- five executables;
- two project static libraries;
- all mandatory fixture/input files;
- exact source archive / changed-file blobs;
- build logs and compile database;
- authority metadata;
- recursive checksums.

## Following artifact-only acceptance

Run plane first, seam second, then the remaining mandatory matrix.

Material progress hierarchy:

1. **Gate 1 closure:** plane returns direct deterministic `CompletedSurfaceCells` pure-quads with strict validation, no fallback/recovery, and seam retains direct success.
2. **Minimum architecture proof:** if plane is still invalid, it terminates as explicit authoritative `Rejected` with immutable typed reason and the prior 106/9/12 generic substitution disappears. This is material architectural progress but does **not** pass Gate 1.
3. No progress: plane still silently reaches generic tracing/completion, typed rejection is overwritten, seam regresses, or acceptance is weakened.

## Prohibitions

- no third isolated predicate repair;
- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merge across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition/cell merging;
- no timeout-as-correctness.

## Exit products

A completed Code + Build turn must provide:

- exact source commit and changed-file blobs;
- compile success for all seven approved targets;
- immutable build artifact and SHA-256;
- Code + Build report explaining the producer-boundary implementation;
- one artifact-only plane-first Test + Benchmark plan;
- updated design/TODO/milestone/handoff/runtime authority;
- workflow/payload/document/result hygiene;
- final top-level PR #8 comment as the last repository write.

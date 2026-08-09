# M1d Phase-Front Route Identity Consumer — Code + Build Plan

**Status:** completed by implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`; superseded as next-step authority by immutable Test + Benchmark plan  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Product behavior delta intended:** none  
**Review policy:** `never`

This plan authorized the bounded M1d migration at:

`pipeline::build_authoritative_phase_front_mesh -> exact_interior_route_valid`

The completed turn is recorded in:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Code_Build_Report.md`.

The authoritative next turn is now:

`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

## Completed scope

Final product/test delta is exactly:

- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`.

The implementation preserves the legacy public route representation while making semantic consumption typed:

- packed source-route endpoint fields cross checked `SourceVertexId` adapters;
- canonical `SourceEdgeTopologyKey` owns semantic source-edge identity/uniqueness;
- compact route values cross checked `InteriorTransitionId` adapters;
- packed key/index values remain explicit compatibility representations only;
- existing route cardinality/interior-incidence checks and HardRail/PeriodicCut failure paths remain unchanged;
- route transport, `TransitionStep`, `CanonicalRoute`, public schemas, route production/order, topology/periodic policy, quotient behavior, diagnostics, fixtures, fallback, and recovery remain outside M1d.

Exactly six focused `SurfaceCellPhaseFrontRouteAuthorityMigration` contracts were added to the existing producer target as required by the original plan.

## Compile/package closure

- implementation: `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- build/event: `98a21f3d843533dcc44cb296711268e0ebb26fb6`;
- run/job: `31342400614 / 93318225812`;
- result artifact: `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- log artifact: `9046308461`, SHA-256 `4813676a45370644fce64854d430822b86a0e406e9446a7ea3159c8fb23d315c`;
- recursive manifest: **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- Release/static/Ninja compile: **120/120**;
- runtime execution: **false**.

No generated Directional binary, GoogleTest discovery/test, benchmark, `ctest`, CLI/help/version command, fuzzer, or custom input executed in this Code + Build turn.

## Original acceptance boundary retained

M1d is not semantically accepted from compile success. The following immutable turn must prove the exact six M1d contracts, existing route counterexamples, producer discovery/accounting, M1c/M1b/M1a/T1 preservation, required direct product cases, Bunny/Vase standing comparison, and postflight package immutability from artifact `9046308272` only.

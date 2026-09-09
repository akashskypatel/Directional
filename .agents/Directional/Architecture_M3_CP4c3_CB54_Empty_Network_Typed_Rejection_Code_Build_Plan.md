# M3-CP4c-3-CB54 Empty-Network Typed Rejection Code + Build Plan

**Status:** FROZEN / EXACT SUCCESSOR / RUNTIME-FREE
**Turn:** `M3-CP4c-3-CB54`
**Authority:** `M3-CP4c-3-TB47-REV`
**Runtime authority entering:** TB47/package112/selector409 — **404 PASS / 5 RED / 0 SKIP**, accepted **365/365**
**Stable accounting:** **47 events / 14 categories / 33 recurrences**, debt **5**, packages **112**

## 1. Objective

Implement the already-frozen AK5 product contract: `SurfaceCutGraph` must reject a truly empty field-aligned curve
network on a closed source surface with typed error `EmptyNetworkOnClosedSurface` and a source-face locus.

This is a product Code + Build turn. It compiles but executes no Directional runtime.

## 2. Root cause and frozen authority

TB47 ordinal370 reaches `SurfaceCutGraph` and returns `CellularityNotEstablished` (4) with no `sourceFace`; the gate
requires `EmptyNetworkOnClosedSurface` (6) with a locus.

`M3_CP4c_Frozen_Definitions.md` §2.2 / AK5 already decides the behavior: A2a' adds cuts to an existing network; an
empty network on a closed surface must fail closed rather than letting A2a' become producer of the entire embedded
graph. The error value is already appended as enum value 6 and already has a name mapping. Current
`canonical_candidate()` contains no branch that emits it.

## 3. Authorized semantic edit

Edit **only** `src/geometry/SurfaceCutGraph.cpp`.

Inside `canonical_candidate()`, after exact source/atlas/network binding checks and before mandatory-edge/trace
classification or certification:

1. recognize an empty network only when all three published surfaces are empty:
   - `network.nodes()`;
   - `network.mandatory_edges()`;
   - `network.candidate_traces()`;
2. for that case, use the existing source-topology boundary-loop authority to determine whether the source is
   closed;
3. if the boundary-loop predicate is malformed/unavailable, preserve fail-closed `NonManifoldSource` behavior;
4. if the source is closed (`boundaryLoopCount == 0`) and has a source face, return
   `EmptyNetworkOnClosedSurface` and set `failure.sourceFace` deterministically from the source-topology face map;
5. do not enter cut proposal, saturation, or actual-embedded-graph certification for that rejected case.

The implementation may be formatted to match the existing source style, but no helper abstraction or unrelated
refactor is authorized.

## 4. Frozen unchanged surface

CB54 must not change:

- any test source, including ordinal370's existing regression;
- selector409 or any selector/manifest bytes;
- fixtures, fields, rails, seeds, benchmark inputs or generated evidence;
- `SurfaceCutGraphErrorCode` numbering or header definitions;
- the actual-embedded-graph certifier, `proves_cellularity()`, cut-candidate classification, saturation behavior, or
  proposal heuristic;
- prescribed-sphere owners 368/398;
- ordinary-proposal owner 369;
- folded-cone owner 374;
- accepted/protected ordinal307 or the recovered ordinal367 independent oracle;
- protected 390/393/406/407 success-path behavior;
- normative frozen definitions or any reusable workflow permissions.

No assertion weakening, skip, fallback, selector growth, fixture recognition, tolerance, or special-case success is
authorized.

## 5. Required static verification before compile

From the exact pushed semantic source verify:

1. the only semantic file changed is `src/geometry/SurfaceCutGraph.cpp`;
2. the empty-network predicate requires all three published network surfaces to be empty;
3. source/atlas/network binding checks still precede the new semantic rejection;
4. closed-source detection uses existing exact source-topology authority, not mesh-specific or numeric inference;
5. the emitted code is exactly `EmptyNetworkOnClosedSurface` and the failure carries a deterministic `sourceFace`;
6. no enum value was renumbered and no test/selector byte changed;
7. all carried-owner source outside this exact branch is unchanged.

## 6. Compile boundary — changed owner first

Compile the exact pushed semantic source with durable `.github/workflows/agent-compile-reusable.yml` and mandatory
GMP/GMPXX backend.

First compile the changed owner's consuming target:

`directional_surface_cell_producer_tests`

This is compile/link evidence only. Do **not** execute the produced binary, test discovery, `ctest`, help/version
commands, benchmarks, CLI/GUI, fuzzers, or any custom input.

## 7. Complete package compile

Only after the changed-owner compile is green, compile/package the **same exact semantic source SHA** with the full
durable eight-target set:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

The accepted package must record exact source SHA, mandatory GMP/GMPXX discovery/link evidence,
`exactArithmeticBackend=GMP`, clean source status, recursive self-excluding manifest verification, and
`runtimeExecution=false`.

Package count advances **112 -> 113** only if a new immutable package is accepted. Stable event/category/recurrence
totals do not change in CB54.

## 8. Failure handling

If source application or compile fails, remain inside CB54 and correct only the diagnosed defect. Do not execute
Directional runtime and do not change the frozen test or selector to obtain green compilation.

If the new branch would require changing the public enum, certificate semantics, fixtures, or other carried-owner
logic, stop and return to review rather than silently expanding scope.

## 9. Closeout and later Test + Benchmark prediction

On accepted package113, CB54 closeout freezes one artifact-only Test + Benchmark plan tied to that exact package and
unchanged selector409. The full 409-identity gate is required; no focused-only substitute is sufficient.

Falsifiable prediction for that later TB, not an acceptance assumption:

- ordinal370 changes RED -> PASS with code 6 and non-empty `sourceFace`;
- accepted prefix stays 365/365;
- ordinal367 and protected 390/393/406/407 remain PASS;
- carried 368/369/374/398 preserve their current independently owned surfaces;
- aggregate would therefore be **405 PASS / 4 RED / 0 SKIP**, RED `[368,369,374,398]`, if and only if no other
  semantic surface changes.

A different result is evidence for review, not permission to weaken validation.

## 10. Exact successor after accepted package

The successor Test + Benchmark turn is authored only by CB54 closeout after immutable package acceptance.

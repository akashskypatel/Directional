# M1a Authority Kernel Core — Code + Build Plan

**Status:** authoritative next turn  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and compatibility boundary  
**Production behavior delta:** none intended  
**Review policy:** `never`  
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8

## 1. Objective

Begin M1 with a bounded strangler slice that introduces the canonical authority-domain kernel required by `.agents/Directional/DESIGN.md` without changing any existing production consumer or runtime decision.

M1a creates strong semantic types, exact transport algebra, route value objects, and a test-only compatibility boundary. It does **not** migrate producer state, global rail scheduling, chart selection, quotient materialization, validation, or product behavior. Those remain later M1/M2–M5 work.

T1 independent oracle/package authority is accepted and must remain intact.

## 2. Normative design contract

Implement the M1 definitions from `DESIGN.md` sections 6.1–6.4 and migration section 14:

- distinct strong IDs for source, transport, region, chart, rail, cell, occurrence, and quotient domains;
- named checked conversion returning a typed domain error; numeric coincidence is never conversion;
- semantic identity separated from representation handles;
- one tagged `SourceSupport` domain for source vertex, source edge, and source-face interior support;
- one `FieldChartId` domain;
- exact `QuarterTurn` (`Z4`) and integer-lattice translation algebra;
- `GridAutomorphism` composition and inverse;
- `TransitionStep` containing topology, optional interior transition, transport, and explicit orientation;
- `CanonicalRoute` containing ordered steps and canonical orientation;
- no parallel topology/transition vectors in new APIs.

## 3. Mandatory regression-pattern review

| Pattern | Touched? | M1a invariant | Following immutable evidence |
|---|---|---|---|
| `RP-01` | **yes, primary** | authority domains are non-interconvertible; every legacy conversion is named, checked, and typed | compile-time non-convertibility + invalid-domain tests + adapter round trips |
| `RP-02` | yes, evidence boundary | T1 oracle/package authority remains independent and discovered; M1a tests prove semantics rather than counts | exact packaged test names + mutation/counterexample contracts |
| `RP-03` | no | no producer-state flags/outcomes change | source diff excludes producer disposition |
| `RP-04` | no | no recursion/search/work-loop introduced | source inspection; bounded algebra only |
| `RP-05` | **yes** | equality/order uses semantic values only; orientation is explicit; representation handles are excluded | row/order/reversal metamorphic tests |
| `RP-06` | no | no shared authority tables or membership copying | source diff |
| `RP-07` | **yes** | `QuarterTurn` is modulo-4 algebra; route reversal/cycle composition is explicit | composition/inverse/cycle tests |
| `RP-08` | no | no producer fallback/disposition behavior changes | source diff |
| `RP-09` | no | no global/local relation-consumption policy changes | source diff |

A touched row without an executable counterexample is a stop condition.

## 4. Bounded scope

Preferred new production paths:

- `include/directional/authority/AuthorityIds.h`;
- `include/directional/authority/SourceSupport.h`;
- `include/directional/authority/GridAutomorphism.h`;
- `include/directional/authority/CanonicalRoute.h`;
- `include/directional/authority/LegacyAuthorityAdapters.h`;
- `src/authority/AuthorityKernel.cpp`.

Test path:

- `tests/SurfaceCellAuthorityKernelTests.cpp`.

Build registration only as required:

- `CMakeLists.txt`;
- `cmake/DirectionalTests.cmake`.

Truthful planning/status/report records may also change.

If the existing build architecture requires a slightly different file split, keep the same ownership boundary and document the exact deviation before coding. Do not spread M1a types across producer/validator files.

## 5. Required semantic types

At minimum introduce distinct non-implicitly-convertible domains for:

```text
SourceVertexId
SourceFaceId
SourceEdgeTopologyKey
InteriorTransitionId
SourceComponentId
IsolationSheetId
TopologyRegionId
FieldChartId
HardRailId
PeriodicRelationId
CellId
OccurrenceId
QuotientClassId
```

Requirements:

1. no implicit construction from another ID domain;
2. no implicit conversion to/from `int`, `size_t`, hashes, or row indices;
3. validity is explicit; negative/out-of-range legacy values fail through a typed `DomainError`;
4. ordering/equality operate only on the domain value;
5. representation handles, emitted rows, cache indices, and hashes are not semantic identity fields.

## 6. Source support

Introduce one tagged support value:

```text
SourceSupport = SourceVertexSupport | SourceEdgeSupport | SourceFaceInteriorSupport
```

M1a only establishes exact semantic representation and checked construction. It does not replace current production geometric support classifiers yet.

Required invariants:

- vertex support carries one valid `SourceVertexId`;
- edge support carries one canonical `SourceEdgeTopologyKey` plus any exact parameter representation explicitly required by the existing design;
- face-interior support carries one valid `SourceFaceId` and explicit local coordinate data if needed;
- different support alternatives cannot compare equal merely because raw integers coincide;
- canonical source-edge identity is orientation-independent while directed use carries orientation separately.

## 7. Exact grid-automorphism algebra

Implement exact integer algebra only; no floating tolerance participates.

```text
GridAutomorphism {
  QuarterTurn rotation;      // Z4
  LatticeTranslation shift;  // Z2
}
```

Required operations:

- normalized quarter-turn construction;
- identity;
- composition;
- inverse;
- applying a quarter turn to integer lattice translation;
- equality/order suitable for semantic keys.

Algebra must satisfy in tests:

- identity left/right;
- inverse left/right;
- associativity over representative values;
- four quarter turns equal identity;
- composition preserves exact integer lattice values;
- nonzero rotations are first-class and not special-cased away.

## 8. Transition and route values

Implement:

```text
TransitionStep {
  SourceEdgeTopologyKey topology;
  optional<InteriorTransitionId> interior;
  GridAutomorphism transport;
  Orientation orientation;
}

CanonicalRoute {
  vector<TransitionStep> steps;
  Orientation canonicalOrientation;
}
```

Required rules:

- genuine one-face source boundary may carry topology with no interior transition;
- two-face interior transport requires the named interior-transition domain;
- route reversal reverses step order and inverts directed transport/orientation exactly;
- canonicalization is representation-order independent;
- topology and transition identity are one object, not two parallel arrays.

## 9. Compatibility boundary

M1a compatibility adapters are one-way, named, and checked. New types may read legacy values only through `LegacyAuthorityAdapters`.

Do not modify existing production producers/consumers to use the new kernel in M1a. The purpose of this slice is to make the target domains compilable, testable, and ready for an explicit M1b consumer-migration slice without mixing scaffolding with behavioral migration.

No adapter may:

- guess a domain from numeric range;
- intersect unrelated raw IDs;
- synthesize missing topology from a transition row;
- treat a hash, row number, or local ordinal as semantic authority;
- silently clamp or wrap invalid legacy IDs.

## 10. Required tests added in Code + Build

Add a default-built authority-kernel test family with explicit labels such as `contract-required;authority-kernel`.

Compile/package tests must include at least:

1. compile-time `static_assert` non-convertibility between every high-risk pair (`SourceFaceId`/`FieldChartId`, compact transition/full-row analogs, region/sheet/chart domains);
2. checked conversion accepts valid legacy values and rejects negative/out-of-domain values with typed errors;
3. raw numeric coincidence across different domains remains unequal/unconvertible;
4. source-edge canonical key is endpoint-order invariant while directed orientation remains explicit;
5. support alternatives remain type-distinct;
6. quarter-turn normalization and four-turn identity;
7. automorphism identity, inverse, composition, and representative associativity;
8. nonzero `Z4` rotation with translation round trip;
9. boundary step without interior transition is valid;
10. interior step missing required transition fails typed construction;
11. route reversal round trip;
12. row/order/representation-handle perturbation preserves canonical semantic route;
13. adapter round trip preserves exact semantic values or returns a typed failure;
14. deliberate cross-domain adapter misuse is rejected.

Do not use exact counts, raw row order, hashes, compilation, or no-crash as the semantic oracle.

## 11. Code + Build rules

This turn may:

- edit the allowed M1a source/test/CMake paths;
- compile/link the touched default targets;
- create one bounded remote compile/package workflow under the established connector process;
- package immutable binaries, source authority, test-name manifest, toolchain/submodules, and `runtimeExecution=false` evidence.

This turn must **not**:

- execute generated Directional binaries;
- run GoogleTest discovery, tests, benchmarks, `ctest`, CLI/GUI, help/version, fuzzers, or custom input;
- change production SurfaceCells decision behavior;
- migrate existing producer/validator/tracing/arrangement/completion/optimizer consumers;
- change fixtures or benchmark acceptance;
- weaken or disable T1 tests;
- repair G4-R007, Bunny, Vase, or historical failures opportunistically.

## 12. Compile/package acceptance

M1a Code + Build succeeds only if:

1. implementation diff stays inside the declared M1a boundary;
2. existing SurfaceCells production behavior files are byte-identical;
3. all new ID domains are statically non-interconvertible;
4. no new bare integer crosses the new authority API boundary;
5. new authority-kernel tests compile and are present in static package authority;
6. T1 oracle executable/support and exact 29-name manifest remain packaged unchanged;
7. configured Release/static/Ninja targets compile/link successfully;
8. package records exact implementation/build commits and source blobs;
9. `runtimeExecution=false` is explicit;
10. one result artifact and one separate log artifact are handed to the following Test + Benchmark turn.

Compilation does not accept M1a semantics.

## 13. Following immutable Test + Benchmark

The next turn after M1a Code + Build must consume only its immutable artifact and:

- verify package/source/dependency authority and `runtimeExecution=false`;
- discover the authority-kernel tests exactly once and match the static manifest;
- execute every authority-kernel contract individually;
- rerun the accepted T1 29/29 oracle suite and direct four green cases as regression-preservation evidence;
- retain known-red Bunny/Vase visibility without counting them green;
- verify no existing production result changed relative to the accepted comparison boundary;
- report any failure without repairing source in that Test + Benchmark turn.

Only after that immutable artifact passes may M1b migrate the first real production consumer to the new authority types.

# M1f Vertex Continuation Route Transport Consumer — Code + Build Plan

**Status:** authoritative next turn  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Migrate the next real transport-owning production consumer from raw signed quarter-turn accumulation to the accepted typed route-transport authority without changing tracing path discovery, path selection, public compatibility representation, product behavior, or G4 capability.

Selected consumer:

`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`

The current implementation keeps cumulative route transport in `PathState::matching` and advances it through raw `transition.matching` while exploring the ordered continuation path. The selected candidate later exports that raw cumulative value as continuation/segment matching.

M1f must make the route transport semantic and typed at that exact owner while preserving every unrelated decision.

## 2. Entering immutable authority

M1e is accepted under:

`.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Entering immutable evidence:

| Evidence | Value |
|---|---|
| M1e implementation | `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` |
| build/event | `34036600128262e909c377006a056a2b9976f986` |
| build run/job | `31351113129 / 93341993183` |
| result artifact | `9049125645` |
| result SHA-256 | `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7` |
| log artifact | `9049125905` |
| log SHA-256 | `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be` |
| recursive manifest | **61/61**, `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5` |
| producer accounting | exactly **184** |
| required-green producer | **169/169** |
| M1e focused | **6/6** |
| M1d / M1c / M1b | **6/6 + 3/3**, **6/6 + 3/3**, **6/6** |
| validation / M1a / T1 | **77/77**, **14/14**, **29/29** |
| direct products | Plane / MultiFaceSeam / CloseSheets / Cylinder green and oracle-clean |

Historical regression totals remain **34 / 14 / 20** and `PR8-R034 / G4-R007` remains active.

## 3. Assumptions to verify before editing

Do not silently assume the inspected packaged source still matches the branch.

Before implementation:

1. fetch fresh PR #8 metadata and branch head;
2. verify the M1e implementation remains an ancestor;
3. fetch the current `src/geometry/SurfaceCellTracing.cpp` and identify the exact `resolve_vertex_continuation` implementation;
4. confirm the consumer still owns an ordered multi-step route and still performs cumulative raw signed matching;
5. inspect `Regression_Root_Cause_Tracker.md` patterns `RP-01` through `RP-09` and record which are touched;
6. synchronize `REORIENTATION_PLAN.md` and `Regression_Root_Cause_Tracker.md` with immutable M1e acceptance before source expansion if their status text still says runtime pending.

If the consumer has materially changed, stop and revise this plan rather than forcing the planned migration onto a different owner.

## 4. Scope

Expected production scope is surgical:

- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp` for new compile-only migration contracts;
- durable/current planning records required by the turn workflow.

No header or CMake change is expected. If a header/build change proves genuinely necessary, document why before making it and keep it minimal.

## 5. Production change

### 5.1 Preserve route discovery and ranking

Do not alter:

- source-vertex fan enumeration;
- admissible neighbor/face selection;
- hard-feature, relief, topology, or sheet checks;
- `resolve_branch_transition` semantics;
- path ordering;
- effort/cost accumulation or candidate ranking;
- route termination or failure classes;
- public trace/segment topology/provenance vectors.

M1f owns transport representation only.

### 5.2 Establish semantic step identity

For each observed continuation step, reuse the accepted M1e boundary pattern:

1. decode legacy/source edge representation only at an explicit compatibility boundary;
2. establish checked `SourceVertexId` values;
3. establish canonical `SourceEdgeTopologyKey`;
4. establish checked `InteriorTransitionId` from the existing authoritative compact provenance source;
5. do not promote `CrossFieldEdgeTransition::sourceEdge` into semantic transition identity;
6. fail closed at the earliest reachable authoritative provenance boundary when a required step identity is malformed.

### 5.3 Compose typed transport in observed order

Replace unrestricted cumulative signed arithmetic such as:

```text
next.matching += transition.matching
```

with semantic transport:

- `QuarterTurn::from_integer(...)` at the compatibility boundary;
- zero-shift `GridAutomorphism` for each directed step;
- one `TransitionStep` per observed route step;
- one `CanonicalRoute` only after all step identities validate;
- `CanonicalRoute::oriented_steps()` or equivalent accepted orientation mechanism so canonical storage cannot reverse the behaviorally observed route;
- algebraic composition/inverse in route order.

The selected candidate may expose the normalized raw matching integer only at the existing public compatibility output boundary.

### 5.4 Legacy transition-metadata absence

The existing `edgeTransitions`-absent legacy matching path must cross the same typed composition boundary. Do not maintain a second raw cumulative algorithm merely for legacy metadata.

### 5.5 Path state

Prefer the smallest representation change that makes semantic transport authoritative. Do not add speculative abstractions or duplicate route state.

If `PathState` needs to carry typed accumulated transport or semantic steps, store only what the continuation owner requires. Do not introduce a project-wide route object migration in this slice.

## 6. Compile-only test contracts

Add focused production-path contracts under a new suite such as:

`SurfaceCellVertexContinuationRouteTransportAuthorityMigration`.

Tests must exercise the real production path that reaches `resolve_vertex_continuation`; they must not reimplement route composition in a test helper as proof.

Required semantic scenarios:

1. **Multi-step continuation composes typed transport**
   - fixture forces at least two nonzero continuation turns;
   - expected final matching is independently hard-authored from fixture branch labels/topology, not production output.

2. **Reverse observed continuation is the exact inverse**
   - forward and reverse paths are independently selected by fixture state;
   - expected values are hard-authored and compose to identity modulo four.

3. **Equivalent signed representations are semantic equivalents**
   - perturb raw representations by `+4/-4` without changing quarter-turn semantics;
   - compare sorted semantic observations keyed by route topology/provenance, not positional vector equality.

4. **Route topology and compact provenance are unchanged**
   - expected source-edge topology and compact transition IDs are independently enumerated from fixture topology;
   - no expected value is read back from production route output.

5. **Malformed authoritative step provenance fails closed**
   - first prove the valid baseline multi-step continuation;
   - corrupt a predetermined route step at the real reachable provenance boundary;
   - require the existing typed failure category/metadata and no geometric/legacy fallback.

6. **Legacy metadata path uses the same typed composition**
   - remove explicit transition metadata where supported;
   - construct legacy compact matching independently from fixture topology;
   - require semantic equivalence to the explicit-metadata path.

If one proposed scenario is structurally unreachable at this consumer, do not fabricate it. Replace it with the nearest real predecessor contract and document the correction before build, preserving the intended invariant.

## 7. Unit-test integrity requirements

For each new test, verify before compilation:

- **Contract:** protects the continuation consumer's observable transport invariant;
- **Fixture:** actually creates the claimed multi-step path;
- **Oracle:** expected values are independent of the production composition algorithm;
- **Signal:** plausible defects such as ignoring one step, reversing order, treating `+4` as distinct, or using the wrong compact transition must fail;
- **Isolation:** no order/time/random/environment dependency;
- **Assertions:** narrow semantic values and typed failure metadata rather than broad snapshots.

Do not change pre-existing test thresholds or expectations merely because a runtime test is known red. In particular, the nondeterministic `StrictValidatorOverheadStaysBelowFivePercent` test is outside M1f source/test scope unless separately authorized by a future plan.

## 8. Explicit non-goals

M1f must not modify:

- periodic-annulus whole-cycle holonomy accumulation;
- nonzero periodic Z4 product capability;
- production `FieldChartId` adoption;
- public route/segment schemas beyond the existing compatibility write;
- topology-region planning;
- global hard-rail scheduling/conformity;
- quotient/materialization/certificate ownership;
- completion/singularity algorithms;
- validators or validator thresholds;
- source-grid recovery or fallback behavior;
- optimization/performance algorithms;
- G4 product repair;
- M2–M6 or T2–T6 scope.

The separate periodic holonomy accumulator was inspected after M1e and is deliberately deferred because it is a wider global cyclic owner adjacent to unresolved periodic/G4 capability.

## 9. Regression-pattern guardrails

Review and preserve:

- `RP-01`: no bare integer becomes semantic source/transition identity;
- `RP-02`: compile/focused helper state cannot become product acceptance;
- `RP-04`: no new retry/search loop or unbounded cumulative work;
- `RP-05`: canonical topology/typed ID, not row/traversal position, owns semantic identity;
- `RP-07`: no raw signed arithmetic remains authoritative for the selected continuation route;
- `RP-09`: do not consume global conformity authority locally.

No stable regression ID is created merely because a pre-existing known-red case remains red. A recurrence requires accepted behavior to have been restored and then lost.

## 10. Code + Build turn execution

This turn may edit and compile/package only. It must execute **no** generated Directional binary, GoogleTest discovery, test, benchmark, ctest, CLI/GUI/help/version command, fuzzer, or custom input.

Expected sequence:

1. resolve fresh branch/PR authority;
2. synchronize current durable status records if required;
3. inspect the selected consumer and nearby ownership boundaries;
4. make the smallest generalized production edit;
5. add the focused compile-only contracts;
6. statically review tests for independent oracles and real fixture preconditions;
7. commit and push the implementation/test revision;
8. run a compile/package-only workflow against the exact pushed commit using the repository workflow policy;
9. require unconditional detailed log artifact plus separate successful build/result artifact;
10. verify package source authority, manifest, hashes, fixture closure, and `runtimeExecution=false` without executing packaged binaries;
11. update Code + Build report, TODO, handoff, roadmap/tracker status, and PR body;
12. end with exactly one new top-level PR #8 conversation comment after all other repository writes.

## 11. Build success criteria

Code + Build succeeds only if:

- diff is limited to the selected continuation transport boundary, focused tests, and required planning records;
- no fixture-specific production condition is introduced;
- route discovery/ranking and public compatibility behavior are intentionally unchanged;
- focused tests compile against the real production path;
- exact pushed commit builds all required targets successfully;
- artifact contains the required producer/validation/M1a/T1 executables and fixtures needed for the next immutable validation turn;
- package has a recursive checksum manifest and source/build authority metadata;
- detailed activity log artifact is uploaded under `if: always()`;
- metadata proves no generated Directional runtime execution occurred.

Compile success alone does **not** accept M1f semantics.

## 12. Required next turn after successful build

The next turn is always **immutable Test + Benchmark only** against the exact M1f build artifact.

That plan must include:

- exact artifact preflight/postflight;
- exact focused M1f suite membership and fresh-process execution;
- M1e/M1d/M1c/M1b/M1a/T1 preservation;
- complete producer discovery/accounting with no silent exclusions;
- direct Plane/MultiFaceSeam/CloseSheets/Cylinder preservation;
- explicit known-red classification including the strict-validator timing nondeterminism;
- Bunny/Vase comparison under existing bounded rules;
- no rebuild/relink/regeneration/edit/substitution.

Any required-green failure remains at M1f and returns to corrective Code + Build. Do not advance to periodic holonomy, `FieldChartId`, M2, or G4 remediation until M1f is immutable accepted.

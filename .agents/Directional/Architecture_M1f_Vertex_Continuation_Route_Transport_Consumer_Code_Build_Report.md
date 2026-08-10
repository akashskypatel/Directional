# M1f Vertex Continuation Route Transport Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Result

M1f Code + Build is complete at the selected real transport owner:

`surface_cell_tracing_detail::resolve_vertex_continuation -> ordered source-vertex continuation route`.

Final implementation authority is:

`baed0f24831c476f45a1b742c12314e3fb03e10e`.

The Release/static/Ninja compile-only workflow completed all **120/120** build steps and produced an immutable result artifact. No generated Directional binary, GoogleTest discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input was executed. The packaged build authority explicitly records `runtimeExecution=false` and all runtime-boundary flags false.

M1f is **not accepted yet**. Runtime semantic acceptance belongs only to the next immutable Test + Benchmark turn against artifact `9050850344`.

## 2. Selected ownership boundary

Before editing, the branch still contained the exact raw accumulator described by the authoritative plan:

```text
PathState::matching = 0
next.matching += transition.matching
candidate.matching = next.matching
```

This was a genuine ordered continuation-route transport owner rather than a proxy/helper. M1f changes only transport representation at this boundary; path discovery and selection remain legacy behavior.

The final production path now:

1. validates transition metadata with the existing branch-transition resolution;
2. establishes source-edge provenance for the observed continuation step;
3. checks packed source endpoints through `SourceVertexId` adapters;
4. canonicalizes the observed edge with `SourceEdgeTopologyKey`;
5. checks the compact provenance domain as `InteriorTransitionId`;
6. creates `QuarterTurn` plus zero-shift `GridAutomorphism`;
7. creates one `TransitionStep` per observed crossing;
8. stores the ordered observed route in `PathState::routeSteps`;
9. creates `CanonicalRoute::from_observed_steps(...)` for the selected candidate;
10. consumes `CanonicalRoute::oriented_steps()` and composes algebraically in observed direction;
11. writes the normalized rotation integer only at the pre-existing `VertexContinuationResult::matching` compatibility boundary.

The explicit legacy `edgeTransitions == nullptr` path crosses the same typed route-composition boundary. The implementation does not reinterpret `CrossFieldEdgeTransition::sourceEdge` as semantic transition identity; semantic `InteriorTransitionId` continues to come from the independently enumerated compact source-edge provenance map.

## 3. Preserved behavior and explicit non-goals

M1f does not change:

- source-vertex fan enumeration;
- hard-feature, relief, component, or source-sheet rejection;
- `resolve_branch_transition` branch choice;
- candidate/path ordering or deterministic tie-breaking;
- geometric direction ranking;
- matching-effort accumulation or ranking;
- target-face termination;
- continuation status/failure categories;
- public trace/segment schemas or route provenance representation;
- the separate periodic whole-cycle holonomy accumulator;
- production `FieldChartId` adoption;
- topology/conformity/quotient ownership;
- validators;
- fallback/recovery expansion;
- optimization;
- G4 repair.

## 4. Focused test authority compiled, not executed

Exactly six new tests are compiled under:

`SurfaceCellVertexContinuationRouteTransportAuthorityMigration`.

They are deliberately direct tests of the package-visible production continuation consumer rather than a duplicated test-only transport helper:

1. `MultiStepContinuationComposesTypedTransport`
   - forced route faces `2 -> 1 -> 0`;
   - independently authored quarter turns `1`, then `2`;
   - expected normalized cumulative rotation `3`.
2. `ReverseObservedContinuationUsesExactTransportInverse`
   - exact reverse route `0 -> 1 -> 2`;
   - expected reverse rotation `1`;
   - forward/reverse rotations compose to identity modulo four.
3. `EquivalentSignedRepresentationsNormalizeSemantically`
   - independently mutates one authoritative step by `+4` and another by `-4`;
   - both must retain semantic matching `3`;
   - this specifically distinguishes typed modulo-four composition from the historical raw sums `7` and `-1`.
4. `ContinuationFacePathPreservesIndependentCompactRouteAuthority`
   - fixture independently enumerates topology `(0,3) -> (0,2)` and compact IDs `2 -> 1`;
   - observable continuation path must remain `2 -> 1 -> 0` with matching `3`.
   - `VertexContinuationResult` does not expose compact/source-edge provenance, so the test does not add a public schema merely to inspect implementation state.
5. `MalformedAuthoritativeStepProvenanceFailsClosedWithoutLegacyFallback`
   - explicit authoritative transition provenance is malformed while legacy matching data is still available;
   - requires `FieldMetadata`, no found continuation, and no legacy fallback substitution.
6. `LegacyMatchingPathUsesSameTypedRouteComposition`
   - executes the explicit metadata-absent compatibility path through the same production consumer;
   - requires the same face/family/sign/path and normalized matching `3`.

The package records the static suite counts: M1f **6**, M1e **6**, M1d **6**, M1c **6**, M1b **6**, M1a **14**, T1 **29**. These are compile/package facts only; none were executed during this turn.

## 5. Compile failure and surgical correction

The first compile-only attempt produced implementation `17afbfd8baf0d369d9136534c0a11784ca0dca10` and failed while compiling `SurfaceCellTracing.cpp` at build step 43/120. Run/job:

`31355799487 / 93355124156`.

Detailed failure-log artifact:

- artifact `9050634092`;
- ZIP SHA-256 `02938a32858e27017dc13fc40266379771094e0ac7b56e70a25a095d414ce5a7`.

Cause: the initial change forward-declared `source_edge_provenance` in the outer `surface_cell_tracing_detail` namespace, while the pre-existing helper is owned by an anonymous namespace later in the file. Existing unqualified calls therefore saw two candidates and became ambiguous. This was a compile-time namespace/ownership mistake, not runtime product evidence.

The correction was intentionally narrow: do **not** move or refactor the existing anonymous helper or its unrelated callers. M1f now owns a local `continuation_source_edge_provenance` helper before `resolve_vertex_continuation` with the same required provenance checks for this earlier consumer. Corrective commit `baed0f2...` changed only `src/geometry/SurfaceCellTracing.cpp` relative to its trigger and compiled successfully.

The failed attempt does not create a new stable regression event or recurrence: M1f had no accepted runtime baseline, accepted M1e remained an unchanged ancestor, and the defect was corrected inside the same Code + Build turn before artifact acceptance.

## 6. Final compile/package authority

| Evidence | Value |
|---|---|
| accepted M1e ancestor | `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` |
| initial failed M1f implementation | `17afbfd8baf0d369d9136534c0a11784ca0dca10` |
| final M1f implementation | `baed0f24831c476f45a1b742c12314e3fb03e10e` |
| corrective workflow run/job | `31356131866 / 93356062724` |
| result artifact | `9050850344` |
| result ZIP SHA-256 | `a2ac9f21cae7f3496a9ffd7cade8b550b5c8e1de57c91d693dde5ece4fcd499f` |
| detailed log artifact | `9050850513` |
| log ZIP SHA-256 | `3f5595a14d7c2b8c8931772fbdb770c9bc1944b211710ccc4939f2fc1dd54c99` |
| recursive content manifest | **59/59**, SHA-256 `3607c79873f45d035e6b1339288ed26582007a9068768da167abc603c376059e` |
| package regular files | **60** including `SHA256SUMS` |
| packaged executables | **7** |
| packaged static libraries | **2** |
| packaged benchmark fixtures | **27** |
| build | **120/120** |
| build wall time | **8:50.14** |
| peak RSS | **1,848,704 KiB** |
| runtime execution | **false** |

Final authoritative blobs:

- `src/geometry/SurfaceCellTracing.cpp`: `40f9b1812c08141cef7ffad924474abf3f346e46`;
- `tests/SurfaceCellsPhase10Tests.cpp`: `1a5d121316dc47462c7eb4f2fda4346f00fbec84`;
- `.agents/Directional/Future_Chat_Session_Handoff.md`: `f03a54bb62f5d7260d7ae5edec16b6bedcdd77c5`;
- `.agents/Directional/GitHub_Workflow_Policy.md`: `0e3feb065ea4313c491bc1e74379280af0eb65c0`.

Executable SHA-256 values:

- producer `996a032234ea3deca55f2d016dbaf789bd0470141a455d1f43f704db7d931a54`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `b9dd836182f3e07196d37510d92a2921fb661b47bf50aa75566adbb9161bbaad`;
- compiled API `7148e2f36c6379fe284dc080697221b037b18becc0ede07d70a528a554aab85e`;
- benchmark `fd8036892bb81339c8396431ee4c913171be79fe4547405c30c0d220caf614b1`.

Local artifact inspection after download independently revalidated all **59/59** entries in `SHA256SUMS`, the 60-file package count, seven executables, two static libraries, 27 fixtures, the build-authority JSON, and the artifact ZIP digests.

## 7. Durable GitHub resource-heavy-test policy update

At the user's direction, durable policy now explicitly permits long-running or resource-heavy tests and benchmarks to execute through narrowly scoped GitHub Actions workflows when interactive/local execution is impractical.

This changes the execution plane only. It does **not** weaken turn separation or immutable authority:

- runtime tests/benchmarks remain Test + Benchmark work;
- artifact-only turns must consume exact immutable build artifacts;
- no build/relink/regeneration/content mutation is allowed in such runtime workflows;
- exact preflight/postflight authority and bounded resource/time controls remain required;
- detailed diagnostic logs must be retained unconditionally;
- temporary workflow cleanup order remains workflow-disable/removal first, then trigger/payload cleanup.

The rule is durable in both `Future_Chat_Session_Handoff.md` and `GitHub_Workflow_Policy.md`.

## 8. Regression disposition

M1f remains compile-complete/runtime-pending:

- `RP-01`: checked continuation step domains compile-complete; runtime pending;
- `RP-05`: semantic continuation route identity and observed/canonical orientation compile-complete; runtime pending;
- `RP-07`: typed cumulative continuation-route transport compile-complete; runtime pending;
- `RP-02 / TA-05`: preservation awaits immutable artifact validation.

Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unchanged. The strict-validator 5% timing check remains a deferred nondeterministic performance-test defect, not an M1f acceptance gate.

## 9. Authoritative next turn

Run **M1f Vertex Continuation Route Transport Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only result/log artifacts `9050850344 / 9050850513`. Rebuild, relink, regeneration, source/test/build/fixture edits, repair, or artifact substitution are prohibited.

Expected native producer discovery after the six new focused tests is exactly **190**. The required-green producer segment is expected to be **175/175** after retaining the same four separately run direct product cases, nine historical/deferred cases, Bunny, and Vase dispositions used by M1e.

Any required-green semantic or preservation failure remains at M1f and returns to corrective Code + Build. Do not advance to periodic holonomy, production `FieldChartId`, M2, or G4 remediation until immutable M1f acceptance.

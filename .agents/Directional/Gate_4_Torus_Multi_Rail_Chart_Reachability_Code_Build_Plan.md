# Gate 4 Torus Multi-Rail Chart Reachability — Code + Build Plan

Status: **completed**  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Entering authority

| Authority | Value |
|---|---|
| Entering documentation head | `23c75d998bf0c8c4dadff37989023794590cffc1` |
| Regressed implementation | `8f37612148f34bac63cf294000c17c7de2e03b41` |
| Runtime artifact | `9030700527` |
| Runtime report | `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Report.md` |
| Entering direct baseline | artifact `9029584083`: 74 torus `LocalSheetMismatch` issues |
| Current direct result | artifact `9030700527`: 165 torus `LocalSheetMismatch` issues |

Artifact `9030700527` passed exact preflight and postflight. All seven new
face-chart contracts and all seven retained canonical contracts pass.
Plane, seam, close sheets, and cylinder remain strict-valid **3/3**.
Direct torus remains **0/3** after complete `4/8/4` consumption, 192
completed quads with complete lineage, and `1/0/0` topology. Sphere was not
run.

## Defect contract

One quotient vertex retains the complete union of charts and equivalences
from all members of its union-find class. That set may contain:

- more than two chart components;
- a chain or cycle of exact hard-rail relations;
- valid relations not used by one particular incident face;
- a reciprocal peer at another output vertex that is not a corner of the
  currently selected face.

The current resolver incorrectly requires every alternate chart to connect
directly to the scalar representative, every retained equivalence to be used
by each face, and every reciprocal peer to occur on that same face. The
single-relation two-quad fixture cannot exercise this production shape.

## Required implementation

Implement the smallest general correction:

1. Validate projection cardinality, sorted/unique retained charts, exact
   scalar source support, and every retained relation's rail/route/front
   structure independently of any one face choice.
2. Build exact vertex-local chart reachability:
   - nodes are retained transition-graph chart components supported by that
     exact source entity;
   - an edge exists only for a well-formed retained `HardRail` relation
     whose canonical route consists of authoritative hard-feature edges and
     separates the exact two chart components;
   - scalar-compatible chart components are graph roots;
   - reachable components are derived by deterministic graph traversal, not
     numeric ordering.
3. Validate relation reciprocity against the complete projected output
   authority. A tampered rail, route, or front identity must not gain a peer
   merely because another relation is nearby. Do not require the peer to be
   on the currently resolved face.
4. Resolve each output face by intersecting its corners' reachable exact
   chart components. Require exactly one component and return its semantic
   identity and per-corner exact faces.
5. Require a valid selected witness path for every corner that does not use a
   scalar-compatible component. Do not reject a face merely because a vertex
   retains another valid but unused relation.
6. Keep optimizer labels, centroid/reference projection, projection cache,
   final sampling, and source-authoritative validation on the same resolver
   result.
7. Preserve all scalar barycentric, position, component, sheet, and
   source-entity checks.

This is vertex-local exact reachability. It is not a global union of
hard-feature chart components.

## Focused coverage

Add or strengthen tests in
`tests/SurfaceMeshOptimizerPhase22Tests.cpp` to prove:

1. a three-or-more-chart quotient vertex can reach the selected face chart
   through a chain of exact hard-rail relations;
2. a valid unused retained relation does not invalidate a face on another
   chart side;
3. reciprocal relation authority may be carried by the correct global peer
   vertex outside the selected face;
4. removing one graph link makes the target chart unreachable and fails
   `LocalSheetMismatch`;
5. wrong rail, route, front identity, unsupported chart, or one-sided relation
   fails closed;
6. two distinct reachable face-wide components remain ambiguous and fail
   closed;
7. disconnected close sheets remain unreachable;
8. face-row re-enumeration preserves semantic selection;
9. the existing one-relation positive/negative cases and exact scalar typed
   failures remain unchanged.

Fixtures must model union-find quotient authority naturally. Do not encode an
expected production output, torus ID, face row, chart count, or selected
numeric component.

## Allowlist

Only these files may change:

- `include/directional/geometry/SurfaceMeshOptimizer.h`;
- `include/directional/validation/SourceAuthoritativeMeshValidator.h`;
- `src/geometry/SurfaceMeshOptimizer.cpp`;
- `src/pipeline/RemeshPipeline.cpp` only if complete-authority reciprocity
  must be indexed at projection time;
- `src/validation/SourceAuthoritativeMeshValidator.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

No quotient formation, tracing, scheduling, fixture, manifest, CMake,
benchmark, or acceptance change is allowed.

## Static and compile verification

Before the remote build:

- compare against the exact entering head and require only allowlisted paths;
- preserve existing public behavior when chart authority is absent;
- verify no source face row, numeric component, count, hash, frequency,
  proximity, or fixture identity chooses a chart;
- run formatting/whitespace and compile-only syntax checks;
- do not execute any generated Directional binary.

Commit and push the implementation before authoritative compilation. Compile
the same seven approved targets in Release/static/Ninja with GoogleTest
`PRE_TEST`:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

The bounded workflow must retain unconditional activity logging, exact source
and allowlist verification, separate result/log artifacts, source closure,
checksums, toolchain/submodule identity, and `runtimeExecution=false`.
Remove the temporary workflow before its one-shot trigger.

## Mandatory next artifact-only acceptance

The following Test + Benchmark turn must consume only the new immutable
artifact and:

1. discover each GoogleTest executable exactly once;
2. run every new multi-rail reachability contract individually;
3. run the existing seven face-chart and seven canonical contracts
   individually;
4. preserve the historical exact-torus
   `InvalidHardRailPairing` result unless a separately authorized scheduling
   slice changes it; do not alter that test in this turn;
5. preserve the six focused groups and bounded producer/completion/
   validation/API suites;
6. repeat plane → seam → close sheets → cylinder → torus in three fresh
   recovery-disabled processes;
7. require direct torus strict-valid **3/3**, complete lineage, no
   fallback/recovery, complete `4/8/4` consumption, pure quads, and final
   `1/0/0` topology.

Prescribed sphere remains gated even if direct torus passes, because the
historical exact-torus hard-rail scheduling contract is still unresolved.

## Prohibitions

- no direct or fixture-specific torus branch;
- no weakening or suppressing `LocalSheetMismatch`;
- no acceptance by reduced failure count;
- no global hard-feature component union;
- no arbitrary subset search or ownership by proximity/order/count/hash;
- no synthetic topology correction or post-hoc mesh merge;
- no fallback/recovery or generic-producer substitution;
- no source/test execution, GoogleTest discovery, CTest, benchmark, CLI,
  help/version, or custom input during this Code + Build turn;
- no merge of PR #8.

## Exit requirements

- one surgical implementation commit with exact allowlist evidence;
- all seven approved targets compile from the exact pushed commit;
- immutable result and log artifacts verify recursively;
- Code + Build report and artifact-only next plan are committed;
- TODO, design/testing records, and handoff identify one next authority;
- PR #8 remains open, draft, and unmerged;
- the final repository write is one new top-level PR #8 conversation comment.

## Completion record

Implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49`
changes exactly five allowlisted optimizer/validator/focused-test paths and
leaves the conditionally allowlisted pipeline path unchanged. It implements
exact scalar-rooted vertex-local chart reachability, complete global
relation reciprocity, one unique face-wide reachable intersection, and
selected-witness-only consumption. Four multi-relation counterfactuals were
added while all scalar typed checks and the existing face-chart contracts
remain present.

Workflow run/job `31292116792 / 93190952157` compiled all seven approved
targets at **113/113** using Release/static/Ninja and GoogleTest `PRE_TEST`.
Artifact `9031804178` has outer SHA-256
`27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e`;
all **49/49** recursive entries verify with manifest digest
`2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2`.
Log artifact `9031804382` has SHA-256
`5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905`.
`runtimeExecution=false`.

The temporary workflow was removed before its trigger; final cleanup at
`01b80ac65968906a9d871cee81f154653f452270` reproduces the implementation
tree exactly. `G4-R007` is `fix_pending_runtime`, not resolved.

This historical plan is no longer next-turn authority. See
`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Report.md`.
The authoritative next turn is artifact-only Test + Benchmark under
`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md`.

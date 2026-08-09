# Milestone G Production Readiness TODO

Last updated: 2026-08-09 UTC

## Current gate

G0 truthful authority [accepted baseline] → G1 uniform phase-front plane [accepted baseline] → G2 cross-chart / close-sheet isolation [accepted baseline] → G3 periodic closure / holonomy [accepted baseline] → **G4 topology-distinct completion and singularities [active; blocked with material progress]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Independent architecture review checkpoint

The user-requested documentation-only review is complete with decision
**changes required before architecture expansion**.

- `.agents/Directional/DESIGN.md` is now normative-only and defines the
  certificate-carrying A0–A9 pipeline plus M0–M6 staged migration.
- The review records twelve open structural findings, `AR-01` through
  `AR-12`, without changing historical regression counts.
- Immediate next evidence remains the immutable multi-rail artifact-only run;
  no source, test, fixture, validator, build, or workflow edit is authorized in
  that checkpoint.
- After artifact closeout, the first mutating slice is M1 authority kernel and
  adapters, compile-only and behavior-preserving.
- G4/G5 expansion on the legacy weakly typed, duplicated, consumer-reconstructed
  authority model is prohibited.


## Completed artifact-only Test + Benchmark

Exact artifact **`9026181778`**, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`:

- build/log artifacts `9026181778 / 9026181889`;
- workflow run/job `31272661747 / 93141125742`;
- cleanup/build `846b23a1175f541d86e880c993784715c995ef20`;
- outer SHA-256 `0682ae9fe6e98eefac8e4ddb2ccc8db8407326d7b872ec6da1d945aa8a59b79d` / `d53a060c2b3b20205ce71b3cf44f0fe9f14a2a207a176ec74faf9a8d57e9c890`;
- internal manifest `c63931f3cd9c6261710bd9db255a49aa03029a39d062fe21c714529c4b31fdb1`, recursive **48/48**;
- Release/static/Ninja **113/113**, five executables, two project libraries, 27 fixtures, `runtimeExecution=false`;
- exact source/dependency/fixture/log authority verified before execution;
- all **33/33** transition-quotient counterfactuals discovered;
- no source/test/build/fixture/validator edit, configure, rebuild, relink, or artifact substitution.

Runtime report:
`.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`

## Material progress retained

- topology-only genuine source boundaries now pass their positive and invented-index counterfactuals;
- reciprocal isolation-seam certificate positive, missing, duplicate, wrong-owner, wrong-sheet, and nonreciprocal cases pass;
- topology/isolation/hard-rail group **10/10**;
- polygonal/curved/mixed group **12/12**;
- semantic-digest permutation invariance and connectivity/winding/source-support/component/lineage sensitivity pass;
- multi-face seam completes directly **3/3** with 64 pure quads, complete lineage, stable structural `48661113839528d4`, stable semantic `99c8be7159d05c2f`, and no fallback/recovery;
- validation **60/60** and API **8/8** remain exact;
- completion/simplification remains **154/164** with the same historical ten failures.

This satisfies the repository's material-progress definition, so the mandatory no-progress Review guard is not active. Optional review policy remains `never`.

## Current direct blockers

| Fixture | Result, three processes | First invalid authority |
|---|---:|---|
| plane | **0/3** | `InvalidAuthoritativeTransitionSourceEdge`, `63/162` |
| close sheets | **0/3** | `InvalidAuthoritativeTransitionSourceEdge`, `199/12` |
| cylinder | **0/3** | `InvalidPeriodicCutAuthority`, `287/3` |
| torus | **0/3** | `InvalidPeriodicCutAuthority`, `191/0` |

Torus remains phase-front `Produced` with four topology regions, eight internal isolation seams, four periodic relations, and consumed authority `0/0/0`. Sphere is deferred.

Focused totals are transition quotient **24/33**, periodic/torus/cylinder **5/7**, remaining Phase10 **35/39**, and direct G0-G3 GoogleTests **1/4**. Producer bounded is **143/161**; bounded aggregate is **365/393**.

## Canonical transition-index blocker

The producer has two numeric edge domains:

- full `mesh.EF` rows in `CrossFieldEdgeTransition.sourceEdge`;
- one source-wide compact two-face interior domain from `edge_matching_indices(edge_faces(full source faces))`.

`source_edge_provenance()` writes the full `EF` meaning when CrossField transitions are present, while region producers may also rebuild a region-local compact numbering. Materialization always validates against the source-wide compact table. Canonical topology already travels beside the route and must remain exact; the numeric route must be normalized to the source-wide compact interior index after validating the supplied CrossField transition's topology and reciprocal faces. Genuine one-face boundaries retain topology-only authority and no invented interior index.

## Public failure-retention blocker

Failure injection currently forces `retainIntermediateGeometry` true internally and the same value controls returned context. Internal lifetime and public retention must be separated so identical injected failures expose trace authority iff the caller requested it.

## Explicit follow-on blockers

- nonzero periodic `Z4` holonomy is rejected before relation construction and rotation is hard-coded zero;
- independently produced exact hard-rail sides need one shared source-authoritative breakpoint schedule;
- the multi-isolation positive test needs a proven reciprocal cross-sheet quotient precondition before product lineage can be judged.

These are not included in the next narrow implementation slice.

## Historical canonical implementation turn (completed)

**Code + Build only** under:

`.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`

Allowed production/test files:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp` only if needed to expose the normalized integration contract.

CMake, fixtures, manifests, validators, benchmarks, completion/simplification, cross-field extraction, and unrelated tests remain unchanged. Compile/package only; no generated runtime command.

## Historical canonical artifact acceptance plan (completed)

The following immutable artifact-only turn must prove:

- valid routes whose full `EF` row and region-local compact value differ from the source-wide compact index materialize, while either substituted alternate is rejected;
- plane/close sheets move past `InvalidAuthoritativeTransitionSourceEdge`;
- cylinder/torus move past route-index `InvalidPeriodicCutAuthority`;
- the retain true/false test reaches identical `InjectedStageFailure / tracing` and exposes context iff requested;
- every previously green certificate, boundary, digest, topology/isolation, polygonal/curved/mixed, validation, API, and multi-face-seam contract remains green;
- no fallback/recovery, fixture-specific behavior, predicted count, or validator relaxation.

G4 remains active until exact torus directly produces strict-valid pure quads with complete lineage, one component, zero boundary loops, Euler zero, and all `4/8/4` authority consumed. PR #8 remains open, draft, and unmerged.

Every completed turn ends with a new top-level PR #8 conversation comment as the final repository write.

## 2026-08-08 Gate 4 canonical transition-index checkpoint

Code + Build is complete at implementation `edc14d38f862b94941b249f564050e2e1f8f5287`. The producer now serializes materializer-facing two-face routes in one source-wide compact transition-index domain while preserving canonical topology and fail-closed CrossField validation. The pipeline now exposes retained intermediate geometry iff the caller requested it, independent of temporary internal ownership used for execution or failure injection.

Exactly seven approved targets compiled in workflow run `31279574458` (`113/113`, Release/static/Ninja, `runtimeExecution=false`). Immutable compile artifact `9028103772` has outer SHA-256 `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a` and a verified 48-entry recursive manifest.

This does not complete G4 or establish runtime correctness. The mandatory next turn is artifact-only Test + Benchmark under `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Plan.md`. It must consume artifact `9028103772` unchanged, prove the focused canonical-index and retention contracts, preserve prior-green authority, and classify plane, multi-face seam, close sheets, cylinder, and torus in that order. Torus precedes sphere.

Nonzero periodic `Z4` rotation, shared hard-rail scheduling, and multi-isolation lineage remain separate blockers unless the immutable artifact proves otherwise. PR #8 remains open, draft, and unmerged.

## 2026-08-08 Canonical transition-index artifact-only result

Artifact `9028103772`, implementation `edc14d38f862b94941b249f564050e2e1f8f5287`, is now the latest runtime authority. Exact preflight and post-runtime checks pass: outer SHA-256 `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a`, recursive manifest **48/48**, five executables, two libraries, 27 fixtures, exact source/dependency/workflow closure, and no rebuild or artifact substitution.

Direct plane, multi-face seam, close sheets, and cylinder complete directly **3/3** each with strict-valid pure quads and no fallback/recovery. Seam retains semantic `99c8be7159d05c2f`. Torus advances past numeric route rejection, consumes all `4/8/4` region/seam/relation authority, and materializes one component / zero boundaries / Euler zero, then fails final validation **0/3** at `completion/output-validation / LocalSheetMismatch` with 74 issues.

Focused/retained results are transition quotient **26/36**, topology/isolation/hard rail **10/10**, polygonal/curved/mixed **12/12**, periodic/torus/cylinder **5/7**, remaining Phase10 **37/39**, and direct G0-G3 **4/4**. Bounded suites are producer **150/164**, completion **154/164**, validation **60/60**, API **8/8**, aggregate **372/396**.

Three new canonical-domain tests use an off-route synthetic witness and never reach materialization. The face-row periodic test interprets compact route values as `mesh.EV` rows, and malformed holonomy uses a compact route value to select a full-`EF` CrossField transition. These are test-authority failures, not permission to weaken contracts.

The mandatory next turn is Code + Build under `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Code_Build_Plan.md`, limited to `tests/SurfaceCellTransitionQuotientTests.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`. Torus local-chart validation, nonzero rotation, hard-rail scheduling, and multi-isolation lineage remain deferred production blockers. G4 stays active; sphere remains deferred; PR #8 stays open, draft, and unmerged.

## 2026-08-09 Canonical test-authority Code + Build checkpoint

The bounded test-only implementation is complete at `de5261c7185aef71807b0b4140c8f023a44874fd`. Exactly two test files changed; production, CMake, fixtures, manifests, validators, and benchmarks remain byte-identical.

The correction replaces the off-route three-domain witness with an exact serialized cell-route position from a deterministic unit-square plus 2-by-1-rectangle topology. Both tampers target that recorded position. Periodic face-row authority is compared through ordered topology plus per-mesh source-wide compact maps, and malformed holonomy selects one full-`EF` transition by canonical topology and reciprocal faces. No semantic or typed-failure assertion was weakened.

Workflow run `31284957305`, job `93172020467`, compiled all seven approved targets at **113/113** using Release/static/Ninja and `PRE_TEST`. Artifact `9029584083` has outer SHA-256 `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad`; all **49/49** recursive entries verify. Log artifact `9029584200` has SHA-256 `b2c147a691caaafc6591106ebb59f50f2956c17722f88bff1857c94d33f3da9b`. `runtimeExecution=false`.

The authoritative next turn is artifact-only Test + Benchmark under `.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Plan.md`. It must consume artifact `9029584083` unchanged, execute the seven focused contracts individually, preserve the previous `372/396` bounded comparison and direct 3/3 baselines, then repeat plane → seam → close sheets → cylinder → torus. Torus precedes and gates sphere.

If test authority is accepted, torus `completion/output-validation / LocalSheetMismatch` becomes the earliest production correction. Nonzero rotation, hard-rail scheduling, multi-isolation lineage, historical completion/timing, sphere, G5/G6, fallback/recovery, and optimization remain deferred. PR #8 stays open, draft, and unmerged.

## 2026-08-09 Canonical test-authority artifact acceptance checkpoint

Artifact `9029584083` passed exact preflight and postflight. All seven focused contracts pass individually. Retained groups are transition quotient **29/36**, topology/isolation/hard rail **10/10**, polygonal/curved/mixed **12/12**, periodic/torus/cylinder **6/7**, remaining Phase10 **38/39**, and direct G0-G3 **4/4**.

The plan's literal producer filter excludes three discovered tests, so exact bounded totals are producer **154/163**, completion **154/164**, validation **60/60**, API **8/8**, aggregate **376/395**. The previous `372/396` statement used a different denominator and is not a like-for-like comparison. Historical completion ten and strict-validator timing remain explicit.

Plane, multi-face seam, close sheets, and cylinder are direct strict-valid **3/3** each with no fallback/recovery. Torus is deterministic **0/3** after 192 materialized quads, complete `4/8/4` authority consumption, and computed `1/0/0` topology; final validation reports 74 `LocalSheetMismatch` issues. Sphere was correctly not run.

The quotient already retains complete per-vertex chart and hard-rail equivalence lineage. The downstream optimizer/validator receives scalar provenance only, so a rail vertex's one deterministic chart hides the exact opposite-side authority required by an adjacent output quad. The next production slice must project existing lineage into one unique fail-closed per-face chart choice; it may not relax the validator or globally join hard-feature charts.

The authoritative next turn is Code + Build under `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Code_Build_Plan.md`, limited to the optimizer/validator authority projection, focused positive/negative tests, and compile/package only. G4 stays active; PR #8 stays open, draft, and unmerged.

## 2026-08-09 Torus hard-rail face-chart Code + Build checkpoint

The six-file implementation is complete at `8f37612148f34bac63cf294000c17c7de2e03b41`. It projects exact per-vertex retained charts plus `HardRail` equivalence authority into optimization/final validation, requires one unique exact face chart side, preserves scalar provenance and hard-feature barriers, and fails closed on malformed or ambiguous authority. Seven focused positive/negative contracts were added without changing the committed torus success test.

Workflow run/job `31288505364 / 93181547076` compiled all seven approved targets at **113/113** using Release/static/Ninja and `PRE_TEST`. Artifact `9030700527` has outer SHA-256 `6eb42943aa8b27c88fa2afa45e22c5fbc9aa16da2d5cc52748de6e3e45474adf`; all **49/49** recursive entries verify with manifest digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97`. Log artifact `9030700699` has SHA-256 `a3d327bd6d98091e4f4394970aab1823a53324f0106c380cde37a31e99d61263`. `runtimeExecution=false`.

The bounded workflow was removed before its trigger and only `agent-source-snapshot.yml` remains. The mandatory next turn is artifact-only Test + Benchmark under `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Plan.md`. It must run the seven new tests, retain the seven accepted canonical contracts and prior-green suites, run exact torus, then repeat plane → seam → close sheets → cylinder → torus three times. Torus gates sphere. G4 remains active; PR #8 stays open, draft, and unmerged.

## 2026-08-09 Torus hard-rail face-chart artifact regression

Artifact `9030700527`, implementation
`8f37612148f34bac63cf294000c17c7de2e03b41`, passed exact preflight and
postflight. Discovery found producer 166, completion 164, validation 67, and
API 8. All seven new face-chart and seven retained canonical contracts pass.
Bounded suites are **154/163**, **154/164**, **67/67**, and **8/8**.

Plane, multi-face seam, close sheets, and cylinder remain direct strict-valid
**3/3** without fallback/recovery. Torus remains **0/3** after 192 completed
quads, complete lineage, complete `4/8/4` authority consumption, and
`1/0/0` topology. Final validation reports 165 `LocalSheetMismatch`
issues, versus 74 under entering artifact `9029584083`; prescribed sphere
was not run.

The projection is rejected. Quotient vertices retain complete multi-relation
authority, while the current resolver assumes every chart is directly
connected to the scalar representative, consumes every retained relation for
each face, and requires its peer on that same face. The passing two-quad
fixture has only one relation per shared vertex and does not model chained or
unused retained relations.

The mandatory next turn is Code + Build under
`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Code_Build_Plan.md`.
It must implement exact vertex-local relation-graph reachability and focused
multi-relation coverage, then compile/package only. The historical exact
torus `InvalidHardRailPairing` scheduling failure, rotation, multi-isolation,
completion/timing, sphere, and later gates remain separate blockers. G4 stays
active; PR #8 stays open, draft, and unmerged.

## 2026-08-09 Torus multi-rail chart-reachability Code + Build checkpoint

The five-path implementation is complete at
`6af23d9aeca29e63aa13c4ae49f50d1748939c49`. It validates complete
per-vertex retained chart/relation graphs and global relation reciprocity,
derives deterministic scalar-rooted chart reachability, selects the unique
face-wide reachable intersection, and requires witnesses only for selected
non-scalar charts. Scalar provenance and hard-feature/isolation barriers
remain exact. The conditionally allowlisted pipeline path is unchanged.

Four focused tests model a four-sector quotient vertex with a multi-edge
relation chain, an unused valid relation, reciprocal peers outside the
selected face, a missing-link counterfactual, and source-face-row invariance.
Existing one-relation positive/negative, tamper, ambiguity, close-sheet, and
scalar typed-failure contracts remain.

Workflow run/job `31292116792 / 93190952157` compiled all seven approved
targets at **113/113** using Release/static/Ninja and GoogleTest `PRE_TEST`.
Artifact `9031804178` has outer SHA-256
`27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e`;
all **49/49** recursive entries verify with manifest digest
`2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2`.
Log artifact `9031804382` has SHA-256
`5d0b8d0defa3fc371d71160e1db266d3df8037e14c87cf64181b51637cb8a905`.
`runtimeExecution=false`.

The bounded workflow was removed before its trigger. Cleanup head
`01b80ac65968906a9d871cee81f154653f452270` reproduces the implementation
tree exactly and retains only `agent-source-snapshot.yml`.

`G4-R007` is `fix_pending_runtime` in the permanent regression tracker.
The repeated `AUTHORITY_DOMAIN_CONFLATION` and
`LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` cause families remain mandatory
architectural-review inputs.

The authoritative next turn is artifact-only Test + Benchmark under
`.agents/Directional/Gate_4_Torus_Multi_Rail_Chart_Reachability_Artifact_Only_Test_Benchmark_Plan.md`.
It must consume artifact `9031804178` unchanged, run four new multi-rail,
seven existing face-chart, and seven canonical contracts individually,
preserve bounded/group authority, and repeat plane → seam → close sheets →
cylinder → torus three times. Direct torus must be strict-valid **3/3**;
reduced failure count is not acceptance. The separate exact-torus
`InvalidHardRailPairing` scheduling blocker continues to gate prescribed
sphere. G4 remains active; PR #8 stays open, draft, and unmerged.

## 2026-08-09 PR #8 repeated coding-pattern audit

The independent documentation-only Review turn expanded the regression audit
from branch head `8ef353034641c3a068095334ceea5e6ddb0c39c1`. It inspected exact
historical source, test, and CMake snapshots for the 34 stable regression
events; it did not change or execute production, test, fixture, build, or
workflow code.

Nine repeated coding patterns (`RP-01` through `RP-09`) account for **29
events** and all **20 recurrences**. The other five event categories remain
singletons and are monitored without being mislabeled as repeated patterns.
The permanent tracker now records each anti-pattern and required corrective
shape as pseudocode, with point-in-time code evidence and a concrete review
guard.

Every future turn must review all nine patterns, map the planned data flow,
and record whether each pattern is touched plus the exact invariant and
counterfactual/representative evidence. An incomplete touched row is a stop
condition. Work that resembles a recorded anti-pattern must be revised or
receive the required independent architectural Review before Code + Build;
the same mistake must not be repeated under a different symbol or test.

The authoritative next turn remains artifact-only Test + Benchmark and must
consume artifact `9031804178` and log artifact `9031804382` unchanged. It must
review `RP-09` and `RP-02` before interpreting the results. No configure,
compile, link, runtime, or workflow command was run by this audit.

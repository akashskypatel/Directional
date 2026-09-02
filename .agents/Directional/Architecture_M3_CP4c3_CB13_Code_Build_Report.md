# M3-CP4c-3-CB13 Code + Build Report

**Status:** COMPLETE / BUILD GREEN / DIAGNOSTIC-ONLY.
**Turn boundary:** Code + Build only; no Directional runtime test, gate, benchmark, generated discovery, CLI/help/version command, fuzzer, or custom runtime input executed.

## Objective and exact authority

CB13 discharges **BF0–BF9** from `Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` §7 without changing any topology decision. The implementation commit is `3e3411bdc63f1fb841bf223e6e5971284e3770ab`; the exact compile/package source is **`3070173894ee097f631b96c1c6d29f276df89a66`**. The later difference is control-plane only. The preserved implementation patch is SHA-256 `2b8aaa4f12b247356c8617ad1eb01b33e69f1830bb2c8923a108c3ea65c4b385` with diff-body SHA-256 `f48ac751648870a8b2ee35ce9371cad8eed3efe7837b0185713fbe03717f69b0`, touching exactly eight intended files.

Snapshot run `33588931746` produced artifact `9831062525`; its exact snapshot archive SHA-256 is `a8f6c217ac055495047058ca6d3b940d3e7576ab7e004aece2e297d6a4d5e9cb` and `runtimeExecution=false`.

## BF0 — frozen gate and compile boundary

Selectors were independently recomputed before implementation and remained byte-identical through package creation:

| selector | SHA-256 | lines / unique |
|---|---|---|
| 374 | `d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f` | 374 / 374 |
| 375 | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` | 375 / 375 |
| 376 | `6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8` | 376 / 376 |
| 377 | `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1` | 377 / 377 |

The 374→375→376→377 prefix relations are exact, and the accepted first-365 prefix remains `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`. No selector byte and no gate ordinal changed. `selected_gate=NONE`; no gate execution was authorized in CB13.

## BF1 — producer census and typed conditions

The review's two numbers referred to different predicates. Independent re-derivation found **46** `RotationSystemInconsistent` construction sites in `EmbeddedGraphTopology.cpp`. Of those, **37** lacked `rotationSystemInconsistencyReason`; the review's **28** was the narrower subset that lacked both a reason **and** `sourceEdge`/`sourceFace`. The other 9 silent sites carried edge/face locus but still met BF1's actual predicate. Therefore CB13 correctly typed all **37**, not only the 28. The 37 sites are: 23 `build_rotation_system`, 9 `walk_graph_faces`, 2 `build_arcs`, 2 `build_node_loci`, and 1 `exterior_boundary_orbits`. The review's 28-locus-free distribution remains 14/9/2/2/1.

BF1 also explicitly scopes same-code emitters outside that file. `GlobalTopologyPlan.cpp` contained **8** additional reasonless sites, all typed. In total CB13 converts **45 formerly reasonless sites** into typed failures and appends **53 condition names** (enum values 9–61) while preserving existing values 0–8.

Per-site condition accounting is one condition per site except four two-condition sites in `EmbeddedGraphTopology.cpp` (`ArcTraceOriginPortMissing`/`ArcTraceSegmentsEmpty`, `ArcTraceTerminalEventMissing`/`ArcTraceTerminalCutPositionMismatch`, `RotationEdgeIncidentFacesMissing`/`RotationEdgeIncidentFacesEmpty`, `FaceWalkIncidenceCountInvalid`/`FaceWalkSuccessorMissing`) and three multi-condition sites in `GlobalTopologyPlan.cpp` (2, 3, and 2 conditions respectively). Thus `EmbeddedGraphTopology.cpp` has **37 sites / 41 conditions**, `GlobalTopologyPlan.cpp` **8 sites / 12 conditions**, total **45 sites / 53 conditions**. Every name describes the failed condition rather than a source line.

## BF2 — `topology_error` field audit

`SurfaceCutGraphError` now carries `sourceVertex`, and `topology_error` copies it. Field-by-field comparison against `GlobalTopologyPlanError` shows the mapper now preserves: `sourceVertex`, `sourceEdge`, `sourceFace`, `trace`, `rotationSystemInconsistencyReason`, `traceEventIndex`, `traceEventPositionFailureReason`, `traceEventPositionPass`, and converted `traceEventPositionCandidates`, plus the originating error code.

The following **11 source payload fields remain silently absent from `SurfaceCutGraphError`** and therefore cannot be copied by this mapper: `region`, `secondRegion`, `arc`, `networkEdge`, `secondTrace`, `secondSourceFace`, `singularity`, `eulerCharacteristic`, `vertexCount`, `edgeCount`, `faceCount`. BF2 required the audit, not a broad DTO redesign; none is needed to discriminate the TB10 ordinal-366 candidate.

## BF3 — production projection and consumer search

`cut_graph_failure_locus` now publishes `sourceVertex`, the rotation-system reason, `trace`, event index, event-position failure/pass, `cutCandidates.size()`, `nonDiscComponentCount`, and `remainingAdmissibleEdgeCount` in addition to source edge/face. It also carries BF4's certification fields. The existing typed candidate-row vector itself is not serialized into `SurfaceCellFailureLocusDiagnostics`; only its count is projected, matching BF3's frozen scope.

A source-tree search found the production/test consumer chain rather than assuming it: `fail_surface_cells` stores the DTO into both `RemeshDiagnostics::terminalFailureLocus` and the first/original failure locus; `Cp4cProductionFixture` retains the terminal locus; and `append_cp4c_failure_locus` renders it. **`fail_surface_cells` is a consumer BF3 did not name.** The search also finds the independent network projection seam in `RemeshPipeline.h/.cpp`, which produces the same DTO type but is not the cut-graph path.

## BF4 — certification attempt identity

`canonical_candidate` now starts `certificationAttemptIndex` at 0, records the current index and `cuts.size()` whenever `certify_actual_embedded_graph` returns a typed error, and increments only after a non-cellular successful certificate before the next proposal/saturation cycle. Consequently TB11 can distinguish the **initial uncut certification** (`attempt=0`) from proposal-induced certification `n` with exactly `k` cut edges in force.

## BF5 — existing carrier, no gate growth

`append_cp4c_failure_locus` renders the new fields into **ordinal 366's existing failure message**, including `rotationSystemReason`, source vertex/edge/face, trace/event, position reason/pass, cut-candidate counts, and certification attempt/cut-edge count. No selector or gate identity was added. `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` is declared **non-gating diagnostic-only** for TB11 because it re-derives the cut-graph error from production inputs and adds stage/terminal-event context; it earns no gate credit.

## BF6 — audit by assumption

Both frozen audit predicates have independent examples outside the sites named by the review:

1. **Repeated typed code with a bare emitter:** `GlobalTopologyPlanErrorCode::InvalidSourceBinding` is emitted repeatedly; for example `GlobalTopologyPlan.cpp` has a bare return when a topology face lookup fails (the site corresponding to the source-tree line near 368) while other sites attach `arc` and/or `sourceFace`. This satisfies “one code, multiple sites, at least one with no discriminating field.”
2. **Subset projection:** `RemeshPipeline.cpp::topology_plan_failure_locus` copies only `sourceVertex`, `sourceEdge`, and `sourceFace` from `GlobalTopologyPlanError`, despite the source carrying substantially more payload. This is outside the BF2 `topology_error` and BF3 `cut_graph_failure_locus` pair.

These are audit findings only; CB13 does not broaden into unrelated repairs.

## BF7/BF8 — prohibitions and semantic non-change

CB13 changes diagnostics only. It does **not** change ray ordering, topology construction decisions, cellularity predicates, cut proposals, admissibility, tolerance policy, any float-derived topological decision, the sphere path, ordinal 370, saturation semantics, folded-cone behavior, vertex 30, finalize/contact fall-through, or 371/372 fixture coupling. No gate ordinal is added or removed and no selector byte moves. The eight-file diff is limited to error enums/fields, error propagation/projection, and failure-message rendering.

## Compile evidence — GREEN

Compile workflow run/job **`33598896270 / 100148036281`** compiled and linked exactly these eight required targets:
`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

- exact compile source: `3070173894ee097f631b96c1c6d29f276df89a66`;
- result artifact **`9834487605`**, Actions SHA-256 `3546a2795741f16aed374f49c666a8323de04a2605745fd1f83f5b8d52e820b8`;
- log artifact **`9834487931`**, Actions SHA-256 `e64116b211ebe5180b6d12424eda0388c04bd2b9f32c5402860dc676637cd58e`;
- preflight/build exit codes `0`; final source status clean; internal `SHA256SUMS` verified;
- authoritative link evidence contains both `libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`.

## Immutable package 81

Package workflow run/job **`33599637764 / 100150255983`** consumed compile artifact `9834487605` without replacement compilation and without executing a Directional binary. It reverified source identity, compile manifest, GMP evidence, clean source status, selectors 373–377, 27 package-relative fixtures, six executable-mode binaries, and package manifests before and after deterministic extraction.

- package artifact **`9834661539`**, Actions SHA-256 `10e18bc81c2f850a1e7bc3d4ce16830a5d5ebe7d1992cd728c1bb043dc71cb2f`;
- package log artifact **`9834661871`**, Actions SHA-256 `b730ee97e1df872305b872e5a631226a71044dc240efe65a84fbf296ce0f0a76`;
- inner deterministic `package81.tar.gz` SHA-256 **`4f49b3de157e51aff05736f9ac4b210372eb4bfb4dec3ddc793869071b2f9d88`**;
- packaged source archive SHA-256 **`752cb9da86dbae5fd4d0122f5a5538c8e6431be4c8e02c302a8a93e05c25a1bf`**;
- metadata: `package=81`, selector 377 hash above, `runtimeExecution=false`, `packageRepair=false`, `exactArithmeticBackend=GMP`, `modePreservingEnvelope=true`.

Temporary compile/package/schema callers were retired workflow-first. Cleanup run **`33599839031`** succeeded and produced cleanup head `d36540bbad7debba4ec660f4efc268e16a470896`; its result/log artifacts are `9834737992` (`bc8759e75384ca155c430688e76a0570011ecace2a0f4e21fa9e61cdaa7a86c4`) and `9834738526` (`444c65fb5bceae720b7345ed99258f420c9fa0ce72b1a14d064880e04bf249eb`).

## BF9 — frozen TB11 discriminators

Artifact-only `M3-CP4c-3-TB11` must establish all of the following without rebuilding package 81:

1. ordinal 366's message carries a `RotationSystemInconsistencyReason` **other than the nine pre-CB13 reasons**, plus whatever locus the producing site holds; a bare `origin=RotationSystemInconsistent` is a BF1/BF5 diagnostic failure;
2. that reason places the failure in exactly one of `build_arcs`, `build_node_loci`, `build_rotation_system`, `walk_graph_faces`, `exterior_boundary_orbits`;
3. certification attempt/cut-edge count identifies the initial uncut or proposal-induced certificate;
4. accepted ordinals 1–365 remain green and the first red remains 366;
5. 367/371/372 remain at the same upstream stop, while 368/369/370/374 reproduce their existing pre-classified surfaces;
6. a reason in `walk_graph_faces` or `exterior_boundary_orbits` legitimately falsifies the review's ranked fan-order hypothesis.

## Accounting and exact successor

CB13 is build-complete, not runtime acceptance. Accepted semantic authority remains **365/365** and CP4c-3 remains **OPEN**. Stable regression accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**. Creation of package 81 advances authoritative semantic M3 package count **77 → 78**. `M3-CP4c3-TB10-CAND-01` remains active/non-stable until TB11 names the actual producing condition.

**Exact successor:** `M3-CP4c-3-TB11` — artifact-only Test + Benchmark on immutable package 81, selector 377 from ordinal 1, one identity per fresh process, plus the explicitly non-gating diagnostic identity. This report does not begin TB11.

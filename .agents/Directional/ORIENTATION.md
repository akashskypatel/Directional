# Directional — Project Orientation

>This rewrite was expressly requested on 2026-10-16.

**Currency:** 2026-10-28 · [TB47](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md) measured **500 PASS / 4 registered RED** on 504 immutable cases (candidate, not accepted). The active [DEFN-G independent Review](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md) rechecked 491 accepted-prefix identities, found the original selector442 source-boundary component split invalid, ruled out a sheet-only substitute, and derived a synthetic 10-face seam candidate, then R20 proved it cannot arise from the current direct producer’s connected-component/region writers; native A3 acceptance remains unproved. Focused30:12 does not establish an A5 product defect (A3 certificates were not consistently regenerated); R21 proves the original A5 equality is gauge-covariant when both A3 carrier/contact transport and endpoint branches transform together (model, not native admission). cp3entry:1 still lacks a produced odd-gauge witness. R22 independently verifies the face-1 +1 raw-arm metamorph preserves canonical torus chart boundary runs, alignment and signed turn in a source model; R23 withdraws its independent **closure** claim because the frozen test oracle/model uses four-run lengths `{M,m,M,m}` that cancel by construction; R24 confirms **native A4 is different**, independently measuring four run lengths and averaging opposite sides to construct its rectangle, so unequal intrinsic opposite lengths are not alone an invalid torus chart. R25 fixes an older misleading A4 root=face0 claim (native geometric root=133 on full torus) and identifies seven callers of the frozen strict torus singleton. Its face1 cyclic relabel needs a separate D1 metamorphic factory and native accepted-cut-domain evidence; the original shared factory must not change. The separate ingress oracle and native producer admission remain open. R26 further reclassifies the D1 single-face gauge tamper as an early A3 `gauge-pin-consistency` negative, not an independent native periodic/A5 first-consumer negative; the isolated D1 witness needs a separate periodic signed tamper with A3 and source gauges intact. R27 confirms A5 selected-face attachment guards precede G2 branch comparison; R28–R29 identify masked selector442 HardFeature row-order assertions and preserve an unapplied test-rehome preview. R30 finds an existing raw-source right-half +1 cyclic arm fixture paired against the constant-field 3×3 hard rail; source-only, no paired native A3/A4/A5/A6 admission. R31 independently localizes its source-input gauge jump to exactly the two hard carriers, not the six other interior edges; native signed rail/route/action evidence remains open. R32 independently derives unchanged gauge-normalized transport on all eight source interior edges and distinguishes A3 hard-edge transition values from branch-adjacency publication; native proof remains open. R33 pins the complementary raw hard A3 values and checks A4/A5 first-owner ordering: the external gauge-normalized physical proxy is **not** native A3 hard branch-adjacency, and A5 selected-face/rigid guards must be reached before signed branch credit. No native paired proof. R34 independently verifies existing immutable TB47 `cp3entry:6` PASS: the shifted raw-source fixture is already individually admitted through A4/A5/A6/A7 and a selected cross-region HardRail. The separate E2 `cp3entry:2` RED expects a nonexistent combined two-carrier rail and masks later row-order assertions; neither proves constant-versus-shifted G2 covariance. CP2 491/491 remains accepted; selector497 is frozen/unpromoted, stable 66/17/49 debt1, RP-01 open. R38 separately exposes false-green cases in the history-check *helper*, not actual history loss; authentic historical review remains pending. R39 additionally attests an executed A7 **missing-endpoint-gauge** negative within the native shifted `cp3entry:6` PASS; it is not the signed A5 branch negative or paired G2 covariance.
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing` (experimental, PR #8).
**Purpose:** Help a fresh contributor understand the product, architecture, fixtures, project records, cadence, current status and outlook **in minutes**—without reading a turn-by-turn journal.

**Start here →** this page → [ROADMAP.md](ROADMAP.md) (milestones) → [DESIGN.md](DESIGN.md) §§2, 5, 14 (normative architecture) → [Future_Chat_Session_Handoff.md](Future_Chat_Session_Handoff.md) (exact current authority/next turn). Read the relevant frozen definitions and policies before touching implementation.

## 1. What the project is

Directional is a C++ directional-field library with a Python interface ([README](../../README.md)). This branch develops a **direct surface-cell quadrangulation backend**: given a source triangle mesh, tangent cross field, source features and target size, produce a deterministic, source-attached, manifold **pure-quad mesh** with independently verifiable guarantees.

The chosen architecture is **Pipeline B**: field-aligned combinatorial tracing **without global coordinate integration**. Its central ideas are:

- **Single-writer authority:** one producer owns each semantic fact; downstream stages consume immutable, typed products and never repair earlier results.
- **Exact source and topology:** field transport, incidence, region ownership and quotient identity are certified—not inferred from position, container order, a hash or an epsilon.
- **Global-before-local conformity:** choose shared-rail counts/breakpoints once, before independently constructing regional quads.
- **Typed outcomes and real evidence:** fail with an owning reason; prove the intended stage was reached using independent oracles, positive cases, mutations and invariance tests.
- **Verified disposition:** `D0 Certified` through `D4 DiagnosticOnly` describe the *eventual* independently assigned guarantees. M7 has not yet implemented the full ladder.

The objective is **production-ready Pipeline B at M8-CP3**, not merely passing internal contract tests. An optional coordinate-integration **Pipeline A** is documented but unscheduled.

## 2. Pipeline at a glance

| Stage | Owns |
|---|---|
| **Conditioning → A0** | Certified raw→conditioned correspondence; `SourceAuthoritySnapshot` with exact source support, barriers, components, sheets and typed identities. |
| **A1** | `FieldTransportAtlas`: field frames, transport, singularities and holonomy. |
| **A2a → A2a′ → A2b** | `FieldAlignedCurveNetwork` traces; `SurfaceCutGraph` cellularity; `GlobalTopologyPlan` regions with disc proofs. |
| **A3 → A4** | One `GlobalConformityPlan` for shared rails; conforming `RegionCellComplex` products per region. |
| **A5 → A6 → A7** | Explicit corner/side occurrences; only certified quotient merges; source-attached vertex geometry. |
| **A8 → A9** | Independent verification; eventual M7 verifier-assigned disposition; derived diagnostics and export. |

Each arrow denotes a checked, immutable producer-to-consumer boundary. Details and stop conditions belong to [DESIGN.md](DESIGN.md#5-normative-pipeline--pipeline-b), not this map.

## 3. Where we are

**M0–M5 are complete/closed; M6 is active at CP3.** Closure means the checkpoint's frozen criteria passed, **not** that representative output is production-ready.

| Milestone | Achievement / status |
|---|---|
| **M0–M2 — complete** | Preserved baseline; M1 typed single-authority cutover (**234/234**); M2 closed stage products (**275/275**). |
| **M3 — closed** | Field-aligned tracing, typed network events, cellular cut graph and disc-region authority; required-green **365/365**. |
| **M4 — closed** | Exact global rail schedules, production cutover, conditioning and scale contracts; **430/430**. |
| **M5 — closed** | Canonical periodic/quotient identities, certificates and direct producer evidence; **449/449**. |
| **M6-CP1 — closed** | Occurrence, quotient and embedding separation; **479/479** (mechanism-only). |
| **M6-CP2 — closed** | Independent `SurfaceProductVerifier`; accepted cumulative **491/491**. |
| **M6-CP3 — active** | Direct-production and M6 exit re-proof **not accepted**. Frozen 497-row entry selector; reviewed R3 candidate **403 PASS / 94 RED**. |
| **M7–M8 — planned** | Verifier-assigned disposition/degradation, then production hardening. |

**Current independent Review:** [DEFN-G](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md) is **in progress**, not a frozen CB48 authorization. The prior [RA-166](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md) F6/F7 scratch-oracle and source-authority requirements remain binding; G1 requires re-homing because a produced non-hard interior `NonTraversable` carrier is impossible with the current component/region writers, G2 R21 requires a raw-source/A3/A4-coupled relabel positive plus independent signed negatives (do not one-sided strip A5), G3 needs a produced odd face-gauge witness. E2 cp3entry:2 remains separately owned.

**Current test authority:** TB47 manifest v2 (`488a20b6…5955`), exact immutable artifact-only 504/504, **500 PASS / 4 registered RED**, 1,014/1,014 checksums, all 497 selector guards PASS. [TB47 report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md). This candidate supersedes TB46 498/6 for current diagnosis, **not** accepted CP2 491/491; CP3 and selector497 remain unpromoted.

**Prior TB35 independent Review:** CB34 three-edge gauge remains statically/compile accepted. TB35 mechanically verifies 11 PASS / 2 RED; 191/192 retain valid original negative expectations but their mutations do not reach atlas-owned A4 ingress. The passing 189/190 legacy-path claims are not independently discriminating in the presence of an unchanged atlas. [TB35-REV decision](Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Independent_Review_Decision_20261024.md) authorizes only a separate Definition of ingress and negative-oracle ownership; no product or selector promotion.

**Historical evidence (RA-148 and CB31-REV):** Independent TB32 Review rechecked 1,006/1,006 artifact checksums and 500 distinct raw logs. Its original 497-case selector measured **478 PASS / 19 inherited RED** (six RED→PASS over TB31's 472/497, zero regressions), plus three PASS factory controls for **481/500**. The six recovered cases prove synthetic checked-factory fixture/owner assertions, not real odd atlas transport, periodic topology or produced A6 behavior. The 19 REDs remain at unchanged first sites, including seven A3 unavailable-route fixture exceptions and seven untyped cases. CB31 lacked independent raw signed-inverse and topology-keyed gauge expectations. **CB32-REV** verifies the corrected expected (3/1) from signed raw arms, semantic source-face mapping and guarded false-gauge negatives; eight-target GMP compile source is verified. Static sufficiency only: `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION` must execute the immutable artifact before runtime credit; no M6-CP3 acceptance. Prior TB28/TB30/TB31 reports remain historical comparison baselines.

Stable accounting remains **66 events / 17 categories / 49 recurrences** with **one** produced-witness debt. Accepted M6 CP2 is **491/491**; CP3's 497 identities are frozen, not accepted. See the [handoff](Future_Chat_Session_Handoff.md), [RA-124 Review](Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md) and [regression tracker](Regression_Root_Cause_Tracker.md).

## 4. Fixtures and witnesses

The **ten-case representative direct matrix** is defined by [tests/TESTING_STRATEGY.md §4](../../tests/TESTING_STRATEGY.md#4-mandatory-committed-direct-matrix), using [benchmarks/fixtures/milestone-g/](../../benchmarks/fixtures/milestone-g/) and the [fixture matrix manifest](../../benchmarks/fixtures/milestone_g_manifest.json).

| Representative fixture | Intended coverage |
|---|---|
| `plane`, `cylinder` | Basic open/bounded surfaces and boundary topology. |
| `multi_face_seam` | Cross-face seam and field-transport behavior. |
| `close_sheets` | Near-coincident but distinct source sheets. |
| `torus` | Closed, periodic and noncontractible topology. |
| `thin_bent_tube` | Curvature, thinness and approximation stress. |
| `sphere_prescribed` | Prescribed field, singularities and closed-surface tracing. |
| `mechanical_feature` | Hard-feature and trace/rail preservation. |
| `bunny_1k_random` (Bunny) | Representative mesh with generated smooth field. |
| `vase` | Representative mesh with generated smooth field. |

**Native focused G2 evidence boundary (R39):** TB47 `cp3entry:6` also executes an A7 cross-region HardRail missing-gauge **presence** negative after its produced A7 positive. A7 does not inspect signed quarter-turn values in this hard-rail guard; first-owner A5 signed branch wrong/restore and paired raw-source covariance remain unwitnessed. [Exact Review](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md).

**Other focused witness:** `genus_two` tests higher-genus behavior but is **not an eleventh case** in the mandatory ten-case direct matrix. Synthetic test-local witnesses prove narrow contracts; they cannot substitute for pipeline-produced representative evidence.

Fixture generation, provenance, licenses and checksums are recorded in [generate_milestone_g_fixtures.py](../../benchmarks/fixtures/generate_milestone_g_fixtures.py) and [asset-manifest.json](../../benchmarks/fixtures/milestone-g/asset-manifest.json). The matrix also contains legacy-backend comparisons; **strict direct** testing selects `SurfaceCells`, `SurfaceCellFallbackPolicy::Fail`, with source-grid recovery disabled. **A present fixture or focused green gate does not establish D0 acceptance across the full matrix.**

## 5. Document layout — choose by question

| Need | Read |
|---|---|
| Product/algorithm/contract | [DESIGN.md](DESIGN.md) (normative); [README.md](../../README.md) for build/public API. |
| Achievements and future milestone/checkpoint scope | [ROADMAP.md](ROADMAP.md); [M1](M1_Closure_Record.md), [M2](M2_Closure_Record.md), [M3](M3_Closure_Record.md), [M4](M4_Closure_Record.md), [M5](M5_Closure_Record.md) milestone closure records for accepted evidence and preserved historical definitions. |
| Current work, evidence and authorization | [Future_Chat_Session_Handoff.md](Future_Chat_Session_Handoff.md); [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md) and current review/turn plan. Root [STATUS](../../STATUS) is only a lifecycle beacon. |
| Tasks, blocked issues, regression classification | Root [TODO.md](../../TODO.md), [Regression_Root_Cause_Tracker.md](Regression_Root_Cause_Tracker.md). |
| Change history and reusable lessons | [CHANGELOG.md](../../CHANGELOG.md), [LESSONS.md](LESSONS.md). |
| Tests and execution rules | [TESTING_STRATEGY.md](../../tests/TESTING_STRATEGY.md), [REVIEW_TURN_POLICY.md](REVIEW_TURN_POLICY.md), [GMP_COMPILE_POLICY.md](GMP_COMPILE_POLICY.md), [GitHub_Workflow_Policy.md](GitHub_Workflow_Policy.md) (ChatGPT Web), [RETENTION_POLICY.md](RETENTION_POLICY.md), [CLEAN_UP_POLICY.md](CLEAN_UP_POLICY.md). |

**Repository map:** `include/directional/` contracts/types; `src/geometry/` geometry and topology; `src/pipeline/` producer wiring; `tests/` tests and independent oracles; `benchmarks/fixtures/` datasets; `.agents/Directional/` architecture/policies/status/evidence; `.github/workflows/` remote execution.

## 6. Development and evidence cadence

| Turn | Responsibility and boundary |
|---|---|
| **DEFN / Plan** | Freeze scoped semantics, admissible witnesses, acceptance and owner; **no** compile/runtime. |
| **CB — Code + Build** | Implement authorized changes and compile/package exact source; mandatory **GMP and GMPXX** linkage. Compile success is not runtime acceptance. |
| **TB — Test + Benchmark** | Fresh tests against immutable package with exact selector; **no** rebuild, repair, semantic mutation or invented discovery. Publish PASS **and RED** evidence. |
| **REV — independent Review** | Re-open primary evidence, re-derive decisive facts, test non-vacuity, accept/reject promotion and assign unresolved obligations. Same agent is permitted; independence is of **evidence**, not personnel. |

The separation is deliberate: accepted selector continuity and frozen invariants are not negotiable fixes for a RED; diagnostics are not acceptance; representative production claims require production-path witnesses. See the [review policy](REVIEW_TURN_POLICY.md), [testing strategy](../../tests/TESTING_STRATEGY.md) and [workflow policy](GitHub_Workflow_Policy.md) for actual requirements, repository operation, artifact transport and mailbox behavior.

## 7. Open problems — priority, not a task ledger

**Immediate:** Continue **`M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER`** (source-authenticated G1/G2/G3 Review) after measured TB47 500/4. Do not enter E2-PATCH, CB48 or TB48 until the Review freezes exact probe-backed G hunks and the TB48 manifest. R30 identifies an existing physically identical, raw-arm-reindexed 3×3 hard-rail factory pair. R37 independently confirms **both** the constant-field (`focused30:14` and supporting 15/17/18) and reindexed (`cp3entry:6`) hard-rail inputs separately reach A5/A6/A7 with native PASS; their **paired** gauge-covariance, signed A3/A4 correspondence and first-owner negative remain unproved. R39 credits a native A7 missing-gauge negative only; no numeric sign test or A5 branch first-guard negative is executed by it. Use actual A4 single-carrier records, not E2-invalid combined rail. RA-166.6 F6/F7 remain binding.

| Priority | Missing outcome | Owner |
|---|---|---|
| **1** | **DEFN-G currently open**: G1 re-home to a source-producible signed-inverse positive and independently owned invalid-authority negative, G2 native paired check on the already existing constant/right-half raw-arm-reindexed 3×3 source factories, G3 producer-authenticated torus odd-gauge pair. Then separately E2-PATCH (cp3entry:2 R-adjacency) → exact CB48/CB48E → TB48 → O4/O5 Review/CB49/TB49 → RP-01 Review. No missing producer witness may be replaced with synthetic assertions. | [DEFN-G Review](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md), [RA-166](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md) |
| **2** | Restore accepted-prefix execution and the direct-production positive and tamper paths. Fixture debt follows TB19-REV: 242 → 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R test assumptions. Preserve the accepted 491/491 and the frozen 497 identities. | M6-CP3; [tracker](Regression_Root_Cause_Tracker.md) |
| **3** | Discharge the final **`G4-B002`** closed-complex candidate-extraction witness on real produced authority. | M6-CP3 exit |
| **4** | Implement verified D0–D4 degradation/disposition and representative production quality/resource acceptance. | M7 → M8; [roadmap](ROADMAP.md) |

## 8. Recurring defect patterns

- **Review evidence tool cannot certify committed history by itself (R38):** Isolated, reversible Git falsifiers show `review_check.py boundary` sees uncommitted changes but misses already-committed code drift; `ledgers` only checks line-count drops and misses equal-line old-entry replacement; protected-heading presence does not preserve the body’s meaning. `authority` given the original source SHA detects committed code drift. Require full authentic-history checks and content-aware evidence before Review closeout; the synthetic example is NOT a claim of real repository corruption. Owner: [TB47 DEFN-G Review](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md).

- **Presence-only guard mistaken for signed transport witness (R39):** A7 `cross-sheet:hard-rail` tests typed cross-region relation and optional endpoint gauge **presence**, so clearing one optional is a meaningful native A7 negative but cannot establish correctness of the numeric Z4 gauge, A5 signed branch equality, or paired raw-source covariance. Test a signed value at its actual first consuming producer and demand wrong/restore with upstream authority unchanged. Owner: [DEFN-G Review](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md).

- **Gauge-cluster test authority versus source producer:** TB47 G1's two-face seam labels contradict the original boundary-cycle component invariant; a sheet-only replacement is traversable, not a substitute. R5–R9 derive a lower-level combinatorially valid ring/disk seam, but R20 proves its component partition is not direct-producer-authenticated; no non-hard interior barrier positive is reachable under current component/region writers. G2's one-region A4-only relabel keeps its A3 rail transport unchanged; never weaken A5's transport check on that synthetic basis. R30 identifies a distinct existing raw-source-reindexed 3×3 hard-rail fixture pair as a native proof candidate, not yet an accepted relation oracle. G3 requires an actual A4-produced odd face-gauge pair. [Active Review](Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md). No stable count changed.

- **Cross-test fixture authority collision (R25):** Seven tests consume the frozen strict torus singleton across M6CP3/M6CP1/M5CP3. Altering the singleton to get D1 odd gauge would silently replace six other test inputs. Keep it immutable; use a separate source-authored metamorphic fixture and verify native A4 accepted-cut-domain authority rather than inferring it from hard-edge-only scratch transport.

- **Vacuous or contract-incompatible chart oracle (R23/R24):** The frozen torus test repeats cycle lengths to force closure and derives +4 after demanding canonical `[0,1,2,3]` branches. Native A4 instead maps four measured runs onto an opposite-average rectangle; rejecting unequal side lengths would add a new, unapproved semantic constraint. Require independently produced odd-gauge/occurrence/periodic evidence and guard-reaching signed negatives at their actual producer/consumer boundaries. No native G3 positive yet.

- **Witness definition contradicts producer/consumer invariants ([RA-166](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md)):** RA-33.5 demanded a route on `OrdinaryInterior` sides, which A5 forbids, and D2 demanded an intra-certificate junction, which A4's R-split never produces. Check a witness definition against the invariants of the field it reads, and probe its existence before freezing it. Interior-rail-vertex continuity is witnessed by R-adjacency (two same-rail certificates with R at v, and commuting A3 sectors).

- **Masked off-gate negative and nondiscriminating network guard (TB44-REV):** 8219 omits terminal provenance and fails before its intended A3 predicate; 7414 forges a typed source-edge key that is invalid even without A2a network binding. Positive front-side reachability is real but cannot establish network-specific dependency. O5 owns RA-161 P1; see [TB44-REV](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Independent_Review_Decision_20261026.md). RA-162: supplying provenance alone would make 8219 pass on a torn input (non-rail spoke in `hardFeatureEdges`); a negative must be production-reachable.

- **Atlas-versus-atlas vacuity with an unconsumed legacy stimulus (190/O2):** A fixture mutates raw compact matching but builds checked A3 from a separate authoritative field; the atlas-present wrapper nulls every legacy container, so identical A4 outputs prove nothing. A3 `MissingAdjacency` alone duplicates `selector:28`; the discriminating home also pins the no-atlas A4 ingress locus (`"atlas-binding"`). The re-homed selector190 now passes its A3 negative/restored-positive and A4 exact-site assertions in focused TB43 Review; the historical vacuity is not retroactively cured. No-atlas ingress on NotApplicable inputs still publishes legacy-decided seed-fallback outputs. [RA-160](Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md).

- **Positive fixture missing independently published source-rail provenance (TB39-REV; focused 250 owner discharged by TB40-REV):** adding hard-feature edge keys does not publish their source-owned open contacts or closed chains. Checked A4 rejects this under `InvalidSourceAuthority(0)` / `MissingRailTerminalContact(6)` even when its upstream A2/A3 atlas was built. Correct the fixture authority at its originating producer; do not relax the validator or interpret its wrapper as an A4 periodic-action mismatch. [Review](Architecture_M6_CP3_TB39_Selector250_Factory_Site_Independent_Review_20261025.md). RA-156: a composed fixture must carry the component fixture's full rail authority (`authoritativeRails` plus provenance), not only the hard-edge keys. [RA-156](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md).

- **Producer step authority omitted under atlas ingress (RA-152 F1; TB36-REV):** branch propagation reads `FieldTransportAtlas` but A4 periodic observed-step publication historically used null legacy containers and inserted zero rotations; CB36-REV accepted its atlas-first correction and TB37-REV now confirms three focused runtime witnesses; full 497-row census remains unmeasured. A checked factory rejection after A4 is not an A4 guard success; preserve its underlying site before assigning the secondary factory cause.

- **Canonical storage is not directed witness order (CB35-R1-REV; R-2 discharged by CB35-R2-REV):** `CanonicalRoute::steps()` remains identical under `reversed()` even as `oriented_steps()` changes. An oracle that claims directed route identity must compare observed oriented steps to an independent oriented expectation and reject reversal.

- **Partially asserted composed identity (CB35-REV):** checking only a grid automorphism’s rotation leaves translation unconstrained; checking two distinguished route keys without ordered whole-route identity leaves unmarked edges unconstrained. A witness must reject changes to every advertised contract component.

- **Unconsumed negative stimulus (TB35-REV; RA-154 adds 204/242/247):** when checked atlas authority bypasses raw matching and edge-transition containers, mutating those containers does not exercise periodic negative guards; passing +4/legacy variants can also be vacuous. Bind expected failure to the actual single-writer source, without weakening tests.

- **Route cancellation is not local-cycle consistency (TB34-REV):** changing two matchings so a chosen periodic route sums to zero can leave nonzero residuals in distinct vertex stars. A valid face gauge must update every incident transition; never suppress the atlas cycle predicate to admit invalid fixture authority.

- **Vacuous witness:** RA-146/148 and CB31-REV (corrected statically in CB32-REV): equal-gauge row permutations cannot distinguish stale mapping; unpaired front records do not reach reciprocal periodic action guards. A path that is never reached, or a relation whose operands share an object (RA-124), cannot independently prove its advertised contract. Require separately sourced positive/negative oracles and actual prerequisite reachability.
- **Conflated authority:** row number, gauge, semantic ID, terminal incidence, certificate provenance or a per-node representative face (RA-72.4, RA-123) used as interchangeable identities. Find the unique writer and exact typed correspondence.
- **Premature credit:** compile-green, diagnostic data or focused PASS/RED presented as cumulative acceptance. Separate candidate evidence from reviewed promotion.
- **Predicted cause substituted for measured cause:** inspect the **actual first rejecting predicate** and discriminate its subconditions before proposing a repair.
- **Incomplete case analysis:** a contract excludes a case from one branch without assigning it to another. When a specification says "X cannot enter branch B", ask which branch admits X.
- **Incomplete execution mistaken for expected RED (RA-138):** one test-start marker without a terminal GoogleTest failure is not evidence of a completed negative outcome. Preserve the log but fail the harness.
- **Documentation drift:** a second “CURRENT” section appended rather than revising the existing one. Move incident history into its owning tracker, changelog, report or closure record.

Reusable rules and examples belong in [LESSONS.md](LESSONS.md), not here.

## 9. Code entry points

| Subject | Source |
|---|---|
| Pipeline and product wiring | [`src/pipeline/RemeshPipeline.cpp`](../../src/pipeline/RemeshPipeline.cpp) |
| Field tracing, rails, contacts and transport | [`src/geometry/SurfaceCellTracing.cpp`](../../src/geometry/SurfaceCellTracing.cpp) |
| Cut graph and region topology | [`SurfaceCutGraph.cpp`](../../src/geometry/SurfaceCutGraph.cpp), [`GlobalTopologyPlan.cpp`](../../src/geometry/GlobalTopologyPlan.cpp) |
| Geometry/network and pipeline tests | [`FieldAlignedCurveNetworkTests.cpp`](../../tests/FieldAlignedCurveNetworkTests.cpp), [`SurfaceCellsPhase10Tests.cpp`](../../tests/SurfaceCellsPhase10Tests.cpp), [`SurfaceCellPipelinePhase20Tests.cpp`](../../tests/SurfaceCellPipelinePhase20Tests.cpp) |
| Field-aligned network and SurfaceCells diagnostics display (GUI sections 6–7) | [`SourceRegionDisplay.cpp`](../../src/visualization/SourceRegionDisplay.cpp), [`FieldAlignedNetworkPolylines.cpp`](../../src/visualization/FieldAlignedNetworkPolylines.cpp), [`src/gui/Main.cpp`](../../src/gui/Main.cpp) |
| Field streamlines (GUI section 8) | [`FieldStreamlines.cpp`](../../src/visualization/FieldStreamlines.cpp), [`Streamlines.cpp`](../../src/geometry/Streamlines.cpp) |
| Cut graph and disc regions (GUI section 9) | [`CutGraphDisplay.cpp`](../../src/visualization/CutGraphDisplay.cpp) |
| Target size and feature heatmaps (GUI section 10) | [`TargetSizeDisplay.cpp`](../../src/visualization/TargetSizeDisplay.cpp) |
| Review helper conventions | [`.agents/Directional/tools/README.md`](tools/README.md) |

## 10. Outlook and upkeep

**Path forward:** finish M6-CP3 direct-production acceptance → **M7** verifier-owned disposition and strictly labeled degradation → **M8** module boundaries, scale/quality/resource calibration, packaging and production-ready D0 matrix. Future schedules and selector counts remain **unfrozen**; [ROADMAP.md](ROADMAP.md) owns future checkpoint descriptions.

### DURABLE — DO NOT DELETE, AND UPDATE AT EVERY REVIEW TURN

This landing page must remain easy to scan. Per [REVIEW_TURN_POLICY.md §3.1](REVIEW_TURN_POLICY.md#31-orientationmd--update-before-closing-without-exception), every Review updates the **currency line**, **§3** accepted state/selector/accounting, **§4** when witnesses change, **§7** prioritized open problems (remove resolved/stale claims), and **§8** for genuinely new patterns. Review also performs the required consolidation under [CLEAN_UP_POLICY.md](CLEAN_UP_POLICY.md).

**Never append** per-turn headers, repeated status copies, artifact IDs, detailed diagnostics, regression histories, full test ledgers, or frozen definitions. Update summaries **in place**, linking to the correct owner document. Only substantive changes in the project, fixture matrix or document navigation merit more material here.

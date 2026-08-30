# M3 CP4c — Consolidated Historical Record

**Purpose.** Durable, deduplicated history for the `M3-CP4c` family. Completed or superseded per-turn plans, reports, review records, and diagnostic selector records are folded into this file once they are no longer required for current or future work. Normative definitions, frozen selector lineage, current review authority, and the active CP4c-3 definition/gate remain separate. For execution authority, use `Future_Chat_Session_Handoff.md` and `TODO.md`.

**Current state (2026-08-30).** `M3-CP4c-0`, `M3-CP4c-0b`, `M3-CP4c-1`, and **`M3-CP4c-2` are CLOSED / ACCEPTED**. CP4c-2 closed at **365/365 PASS** on immutable package **67**. `M3-CP4c-3-DEFN` is **COMPLETE / DEFINITION + REVIEW/PLAN, COMBINED** and phase-1 `M3-CP4c-3-CB1` is **COMPLETE / BUILD GREEN / RUNTIME-FREE** on immutable package **68**. CP4c-3 remains **OPEN**, selector **367** is frozen and unselected, and the exact next turn is the **artifact-only CP4c-3 phase-1 TB on package 68**. Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**, authoritative M3 packages **68**, `selected_r2_branch=NONE`, and `gate_execution_authorized=false`.

## 1. Separate current/future authority

These CP4c files remain separate because current or future work depends on their exact bytes or adjudication:

- `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` — binding base contract plus Amendment 12.
- `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` — Amendment 13 and still-binding §§4/5/7/9; read with R2.
- `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` — Amendment 14, completeness theorem, AF5 and AG0–AG9.
- `Architecture_M3_CP4c2_Required_Green_Selector_357.txt` — superseded selector retained as frozen lineage authority.
- `Architecture_M3_CP4c2_Required_Green_Selector_358.txt` — withdrawn selector retained as frozen lineage authority.
- `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` — frozen prefix authority.
- `Architecture_M3_CP4c2_Required_Green_Selector_365.txt` — accepted CP4c-2 gate authority.
- `Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md` — CP4c-2 closure/adjudication authority and current carry-forward source for CP4c-3.
- `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md` — current CP4c-3 definitions, review decisions, and AK0–AK9 plan.
- `Architecture_M3_CP4c3_Required_Green_Selector_367.txt` — current frozen CP4c-3 gate.
- `M3_CP4c_Consolidated_Record.md` — this durable historical record.

`DESIGN.md` §7.2/§7.2.1 remains architecture authority. Current status, regression accounting, workflow lessons, and orientation context remain in `Future_Chat_Session_Handoff.md`, `TODO.md`, `Regression_Root_Cause_Tracker.md`, `CHANGELOG.md`, `LESSONS.md`, and `ORIENTATION.md`.

The retained selector lineage is intentional. DEFN-R2 AG0 requires the superseded 357 and withdrawn 358 files to remain historical authority, and CP4c-3 verifies frozen prefix continuity. Current frozen hashes are:

| Authority | SHA-256 |
|---|---|
| accepted 355 prefix | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 prefix | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 prefix | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| accepted 365 prefix | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| CP4c-3 selector 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |

## 2. Checkpoint closure record

| Checkpoint | Closed responsibility | Accepted result |
|---|---|---|
| **CP4c-0** | exact resolved continuation and grazing | **346/346 CLOSED** |
| **CP4c-0b** | exact crash-on-contact termination / arrival | **353/353 CLOSED** |
| **CP4c-1** | observability, diagnosability, non-vacuous terminal events | **355/355 CLOSED** |
| **CP4c-2** | closed/higher-genus region authority, cut graph, cellularity | **365/365 CLOSED** |
| **CP4c-3** | mechanical witness / missing field-transport adjacency plus inherited CP4c-2 debts | **OPEN; selector 367 frozen** |

### 2.1 CP4c-0

Continuation requires exact entry position plus barycentric direction. Branch labels are face-gauge-local; cross-face semantics use published transport/lift. Grazing is exact `Inflow/Tangent/Outflow`; edge transit is used when both adjacent faces drive along the carrier; no tolerance decides topology.

### 2.2 CP4c-0b

The initial termination theory was withdrawn. The accepted S0–S8 contract is exact crash-on-contact with fixed arrival priority and canonical tie handling; arithmetic guards are backstops, not semantic policy.

Accepted authority: source `93059089881c8715a168a61968a8d6874ee1a670`, GMP package `9671190795`, package SHA-256 `2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`, T5 run/job `33136084757 / 98736295227`, selector **353** SHA-256 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, final **353/353 PASS**. Non-gating U3/U4 census was **4/4 PASS** with zero gate credit. The prescribed sphere publishes 24 traces.

### 2.3 CP4c-1

C4/C5 closed the diagnosability and event-non-vacuity surface: tampered trace-intersection crossing data is rejected; every produced trace ends at exactly one actually produced typed terminal event; required terminal kinds are non-vacuously represented without forbidding lawful frozen kinds.

Accepted authority: source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`, GMP package `9675666067`, package SHA-256 `63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`, TB-R5 run/job `33161644741 / 98817323175`, selector **355** SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, final **355/355 PASS**. Observed terminal-kind union was exactly `{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}`. The torus lawfully contributes zero trace/event kinds; the mechanical witness remained outside CP4c-1 reach at `IncompleteCycleBasis`.

### 2.4 CP4c-2 accepted result

A2a′ `SurfaceCutGraph` is the certified pre-region authority. On the closed genus-1 torus it converts a non-cellular network to a certified cellular embedding with **28 cut edges**; A2b derives **4** regions; and the independent oracle reconciles the actual graph exactly: `V/E/F = 72/76/4` and `76 − 48 = 28` selected cut edges. Cellularity is certified over the **actual embedded graph** (Amendment 13), trace-crossed source edges are admissible cuts with proved completeness (Amendment 14), semantic and provenance identities are distinct, and enumeration invariance is explicitly proved. Criteria **C1**, **C3**, and **C6** are green.

Accepted authority:

- semantic/test source: `57444781af7bdc460e38cc68930a9a8c8199eeea`
- GMP package **67**: artifact `9736088354`
- package SHA-256: `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`
- packaged source archive SHA-256: `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`
- R10 run/job: `33331453506 / 99310594268`
- R10 result artifact: `9737796927`, SHA-256 `b02022367785d6a4790549ad127bff69f831404b6ea525f426b707794f71649b`
- R10 diagnostic artifact: `9737797177`, SHA-256 `0a374b6b240877049eacfec2c70be944c39ce3cc4e5a6c461c358a1b206e78c8`
- selector **365** SHA-256: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- final gate: **365 executed / 365 PASS / no first red**
- immutable pre/postflight: PASS; configure/compile/relink/repair/generated-discovery/source/test/fixture/selector/package mutation and benchmark execution all false.

CP4c-2 deliberately does **not** claim more than that accepted gate. The prescribed sphere still reaches `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28` before cut selection, and its independent pre-cut actual-graph oracle is non-cellular (`V/E/F = 18/30/18`, `chi=6` versus `sourceChi=2`). Amendment 14's ordinary trace-crossed proposal path was proved structurally unreachable because `traceCrossed` remained in the proposal barrier set, leaving saturation as the only promotion path (`R10-CAND-01`). The zero-node/zero-arc closed-surface behavior was also unresolved at CP4c-2 closure (`R8-CAND-02`). All three were explicitly transferred to CP4c-3 rather than silently treated as green.

## 3. CP4c-2 consolidated turn history

### 3.1 Amendment 12 — certified pre-region authority

A2a′ was introduced as a certified cut-graph authority before A2b region derivation. Repair/re-cutting after `GlobalTopologyPlan` regions exist remains forbidden. This moved topology reconciliation to the only permitted stage where a cut can legitimately change region topology.

### 3.2 Amendment 13 — actual embedded graph, not a proxy

R5 falsified the whole-source-face/source-edge-barrier partition as cellularity authority: proxy arithmetic could be internally self-consistent while certifying the wrong object. Amendment 13 makes the **actual embedded graph of `FieldAlignedCurveNetwork ∪ cutEdges`** normative. Graph/cut nodes are vertices, graph/cut arcs are edges, and dart orbits under the node rotation system are faces. Source-edge barriers remain proposal/diagnostic provenance only. The shared implementation authority is `EmbeddedGraphTopology.{h,cpp}`; the still-binding conventions live in DEFN-R1 §§4/5/7/9.

### 3.3 Semantic/provenance correction, CB5, and R7 re-proof

R6 exposed representation-dependent semantic identity. `candidate_hash` retains gauge-dependent `atlasDigest` for provenance/tamper rejection, while semantic identity excludes it.

CB5 semantic source `755485865a7cf9c485d754f22b82a41ee151824b` produced package **64**, artifact `9719216316`, SHA-256 `acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`, packaged source archive `78ca517ac7b96ee3737d6ae5b277fc4d06e7393c460f4c9585eb35b2541d84cf`, compile run `33267732093`, with GMP/GMPXX, `28/28` manifest PASS, and `runtimeExecution=false`.

A first R7 orchestration attempt stopped before runtime because prose contained fabricated abbreviated selector hashes. The durable correction is that selector authority is the committed bytes and hashes are always recomputed as full 64-lowercase-hex values. Corrected R7 run/job `33276039911 / 99162853852` consumed package 64, re-proved **355/355 PASS**, and produced result artifact `9721564203` (SHA-256 `a854e562facfd616f9f61eddf653dc9e5814c3b932661993b2b2861b2bdab8db`) and log artifact `9721564377` (SHA-256 `8edd56072491aa4267e3cd0d2c0942b0910a3e5a01f15e6bc21164bd0fbef3ec`). The run was immutable and artifact-only.

The then-frozen non-gating diagnostic selector contained exactly one identity, `GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable`. R7 ran four other diagnostics without executing that frozen identity or documenting a rationale. This became the durable lesson that a frozen non-gating selector is authority: every listed identity must run or be explicitly justified.

### 3.4 Sphere re-localization and CB6 definition stop

`SurfaceCutGraph::topology_error` was found to collapse 36 upstream `GlobalTopologyPlanErrorCode` values into `CellularityNotEstablished`; the sphere producer code was therefore not itself a cellularity verdict.

CB6 obeyed the frozen-definition trigger and stopped before implementation, compile, package, or runtime. From retained R7 result artifact `9721564203`, the independent actual-graph oracle reported `V=18, E=30, F=18, c=1, chi=6, sourceChi=2, excludedBoundaryOrbits=0`, `complex=actualEmbeddedGraph`, and `surfaceCutGraphCallsInsideOracle=0`. The prescribed sphere is genuinely **non-cellular pre-cut** while the producer also fails earlier through lossy error translation. Stable accounting stayed **44 / 14 / 30**, debt **5**, packages **64**.

### 3.5 Amendment 14 and CB7

DEFN-R2 proved the prior exclusion of trace-crossed source edges was based on a false representation premise. `build_arcs` already emits trace arcs at published event boundaries; subdivision occurs only in the derived arrangement, not in the immutable network. Amendment 14 therefore admits every non-network source edge as a cut, uses exact canonical crossing order, subdivides trace/cut arcs at published crossings, generalizes the edge-locus rotation system, and proves completeness through a source-1-skeleton saturation fallback.

CB7 semantic source `4f0f3ca74a88ba260a20c019437bc4995f2056e0` implemented that scope and froze selector **365**. Build-transport source `1230621baff6d04fb20df3b1bf48903cd65b5d69` differed only by the verified Eigen mirror transport at the same gitlink. Compile run/job `33287281975 / 99192562149` produced package **65**, artifact `9724864897`, SHA-256 `a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`, packaged source archive `3b4decd367a3fdb932754c3c6e420b536fa7607755e8ff2541f137f1589d5544`, with all standard targets linked against GMP/GMPXX and no runtime.

### 3.6 R8 witness defect and CB8

R8 consumed package 65. Accepted **355/355** and ordinals **356–358** passed, then ordinal **359** failed before enumeration comparison because its baseline `SurfaceCutGraph::make(...)` returned false; ordinals 360–365 were correctly not run under first-red hard stop. Result artifact `9725240893` (SHA-256 `056a3597183d6bb40d84038db164c0b8e0d2daea1f05468afc270dcd464a5229`) and log `9725241013` recorded an immutable artifact-only run.

Independent review classified `R8-CAND-01` as a **witness-construction / authority-surface mismatch**, not a product regression: the ordinal-359/361 test-local rail authority did not use production `authoritativeRails`, and related source authority fields were incomplete. Stable totals therefore did not change.

CB8 corrected only those witness identities and typed test helpers; no product implementation changed. Semantic/test source `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`, transport source `997d215e9ce0502f4a10afc62d08b2cd1fb3b037`, compile run/job `33292137782 / 99205507393`, package **66** artifact `9726295440`, package SHA-256 `1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`, packaged source archive `ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`. Build was GMP/GMPXX, runtime-free, manifest `28/28 PASS`.

### 3.7 R9 product red and CB9 correction

R9 run/job `33319911575 / 99279955697` consumed package 66, re-proved accepted **355/355**, passed **356–362**, and first-red hard-stopped at **363** with `InvalidCutGraphBinding`. Result/log artifacts were `9734625006 / 9734625165`. Static review proved the crossing producer was correct: exact `ExactUnitParameter` ordering, coincident crossings rejected rather than merged, and every sub-arc emitted in canonical `first()→second()` direction.

The defect was downstream A2b consumption of Amendment 14. A selected trace-crossed source edge legitimately owns multiple derived Cut sub-arcs, but region binding still required exactly one. Review also found a second stale consumer: the region-certificate `boundaryVertices` skip list over-inserted whole-source-edge endpoints, suppressing the interior-vertex ownership check. `R9-CAND-01` was therefore a genuine non-stable product defect while CP4c-2 was still unaccepted.

CB9 semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` corrected **exactly those two stale consumers**, added the requested fragment/orbit diagnostics, annotated the already-proved ordinal-359 semantic-digest rationale, and made typed-error helpers stop before `built.value()` fall-through. Compile-only run `33325344311`, prepackage job `99294371782`, package job `99294619815`, produced package **67** artifact `9736088354` with the accepted hashes listed in §2.4. No selector, error enum, sphere correction, crossing producer, benchmark, or unrelated product behavior changed.

### 3.8 R10 execution and independent closure review

R10 consumed immutable package 67 directly. Preflight validated package/source hashes, `28/28` internal manifest, GMP/GMPXX evidence, executable modes, selector hashes/cardinality/uniqueness, and exact identity resolution. The required-green selector executed one identity per fresh process and finished **365/365 PASS** with no first red. Ordinals 356–365 all passed, including first execution of 364 and 365.

Three frozen non-gating diagnostics executed: **2 PASS / 1 RED**. The prescribed-sphere scope publisher remained report-only red; cut-graph failure localization and the actual embedded-graph cellularity oracle passed. Ordinal 363 published **50** `fragment_reconciliation` rows and **128** `cut_edge_orbit_evidence` rows. AH6 showed `ordinary_proposal_selected_trace_crossed_edge=no` and `saturation_used=yes`; exact selected edge/locus/promoted count were not observable from the frozen test output.

R10-REV accepted the execution as valid, audited the CB8→CB9 conversion line by line, **closed `R9-CAND-01`**, opened `R10-CAND-01` as a non-stable quality/coverage debt, retained the sphere's two independent issues, and carried `R8-CAND-02` forward. It then **CLOSED / ACCEPTED CP4c-2 at 365/365**. Stable accounting remained **44 / 14 / 30**, debt **5**, packages **67**.

## 4. CP4c-3 carry-forward summary

This section is navigation only; `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md` is normative.

`M3-CP4c-3-DEFN` combined definition with review/plan and made four binding decisions:

1. The mechanical witness's `IncompleteCycleBasis` is a multi-site collapse. **CB1 has now instrumented all eight sites plus per-region cycle-basis shape, but no runtime has yet measured which reason fires.**
2. The prescribed sphere is now **in CP4c-3's gate** rather than remaining report-only; CB1 adds nine-way rotation-system provenance without fixing it.
3. CP4c-3 runs in two phases under one frozen selector, **367**, extended only by append. Phase-1 instrumentation is compile-green in package 68; phase-2 ordering still waits on the phase-1 TB/review.
4. AK0–AK9 govern the checkpoint; exact next is the **artifact-only CP4c-3 phase-1 TB on package 68**, not a product-correction CB.

Inherited CP4c-2 dispositions are now explicit:

- `M3-CP4c2-TB-X2-CAND-04`: sphere producer `RotationSystemInconsistent` before cut selection plus independently non-cellular pre-cut graph; CP4c-3 measures the blocking producer cause first.
- `M3-CP4c2-TB-X2-R10-CAND-01`: cause established; corrective is proposal-heuristic-only. Model a trace crossing as a per-face chord so trace-crossed edges are interior to proposal components; this does **not** reopen Amendment 14 certification.
- `M3-CP4c2-TB-X2-R8-CAND-02`: decided; an empty network on a closed surface must fail closed with a new appended typed `SurfaceCutGraphErrorCode`, preserving A2a single-writer authority.
- `M3-CP4c3-DEFN-CAND-01`: the mechanical `IncompleteCycleBasis` diagnostic surface is too collapsed; CB1 instruments exact origin before any product fix.

## 5. High-value reversals retained

- Face-local branch labels are not cross-face semantic identity; use published transport/lift.
- Tangency is a ratio, not excluded by large direction magnitude.
- Source-edge-barrier partitions are not cellularity authority; the actual embedded graph is normative.
- Self-consistent arithmetic can certify the wrong semantic object.
- Accepted-prefix red is a detection boundary, not proof the latest change caused the defect.
- Semantic and provenance digests are distinct authorities.
- Unexecuted diagnostics are unknown, not green; frozen non-gating selectors must be executed in full or explicitly justified.
- Sphere `CellularityNotEstablished` was a lossy producer bucket; an independent oracle separately proved pre-cut non-cellularity.
- A stage is not covered merely because accepted tests transitively reach it; gate membership must be explicit.
- Trace-crossed source edges are admissible cuts because arrangement subdivision does not mutate the immutable network.
- Cut completeness is proved by saturation with the source 1-skeleton.
- A test-local reconstruction of production authority is not equivalent to consuming the production authority.
- When a representation changes from one arc per source edge to multiple sub-arcs, every consumer must be re-derived by intent; fixing the producer alone is insufficient.

## 6. Historical retirement

All files below are historical-only after consolidation. Their exact bytes remain recoverable from Git history; current/future authority does not depend on them except where selector lineage is explicitly retained in §1.

### 6.1 Retired on 2026-08-29

- `Architecture_M3_CP4c_Required_Green_Selector.txt`
- `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`
- `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`
- `Architecture_M3_CP4c0_Required_Green_Selector.txt`
- `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`
- `Architecture_M3_CP4c0b_Diagnostic_Gate_Selector.txt`
- `Architecture_M3_CP4c0b_Non_Gating_Diagnostic_Selector.txt`
- `Architecture_M3_CP4c0b_Required_Green_Selector.txt`
- `Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt`
- `Architecture_M3_CP4c1_Required_Green_Selector.txt`
- `M3_CP4c0b_Closure_Record.md`
- `M3_CP4c1_Closure_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`

### 6.2 Retired by this 2026-08-30 consolidation

The durable facts from these superseded per-turn records are preserved in §§3–4 and in the normal project accounting records. They are removed rather than retained as parallel authority:

- `Architecture_M3_CP4c2_CB5_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB6_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB7_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB8_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB9_Code_Build_Report.md`
- `Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt`
- `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R8_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R9_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Report.md`

Historical per-turn CP4c records retired in earlier consolidation rounds remain represented here, in `CHANGELOG.md`, and in Git history; they are not resurrected.

### 6.3 Durable ORIENTATION authority

`ORIENTATION.md` is **DURABLE** and is not historical CP4c debris. Every REVIEW turn must update its currency line, current position, witness table when changed, open problems in priority order, and recurring-defect section when a new pattern or instance is found. It must not be deleted, renamed away, or collapsed into another document without explicit user authorization.

## 7. Resume pointer

After the durable start-of-turn checklist, current CP4c work should load only the authority needed for the active checkpoint:

1. `Future_Chat_Session_Handoff.md`
2. `TODO.md`
3. `ORIENTATION.md`
4. `Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md`
5. `Architecture_M3_CP4c3_Required_Green_Selector_367.txt`
6. `Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md`
7. `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md`
8. `Regression_Root_Cause_Tracker.md`
9. this consolidated record only when historical lineage is needed.

**Exact next:** artifact-only CP4c-3 phase-1 Test + Benchmark on immutable package **68** (`9739919234`), executing frozen selector **367 from ordinal 1** and publishing AK1–AK3 evidence. Do not proceed to phase-2 product corrections until that evidence is independently reviewed and the measured causes order phase 2.

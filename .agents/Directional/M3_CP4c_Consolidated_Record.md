# M3 CP4c — Consolidated Historical Record

**Purpose.** Durable, deduplicated history for the `M3-CP4c` family. Completed or superseded per-turn plans, reports, review records, and diagnostic selector records are folded into this file once they are no longer required for current or future work. Normative definitions, frozen selector lineage, current review authority, and the active CP4c-3 definition/gate remain separate. For execution authority, use `Future_Chat_Session_Handoff.md` and `TODO.md`.

**Current state — see `M3_CP4c_Current_And_Forward.md`.** Since 2026-09-03 this record holds **history only**. Current authority, the frozen successor, the open-candidate index and the resume pointer live in `M3_CP4c_Current_And_Forward.md`; normative definitions live in the frozen-definition chain; per-turn documents folded on 2026-09-03 are resolved by the **Folded document index** at the end of this file. As of `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`: CP4c-2 CLOSED / ACCEPTED at selector 365, CP4c-3 OPEN. The valid runtime authority remains TB27-R1 on selector 406 at 399 PASS / 7 RED, accepted authority **365/365**; **TB28-R2 is rejected as orchestration-invalid**. Stable accounting **44 / 14 / 30**, debt **5**, semantic M3 packages **93**.

These CP4c authorities remain separate because current or future work still depends on them:

- the CP4c-2 and CP4c-3 frozen `DEFN*` contracts and all frozen `Required_Green_Selector_*` lineage files;
- `Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md`, which closes CP4c-2 and supplies live CP4c-3 carry-forward authority;
- `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` and `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md`, which retain the current runtime boundary and the frozen CB25 scope; `Architecture_M3_CP4c3_TB16_Independent_Review_Record.md` remains CB19 rationale lineage;
- historical review/plan records still referenced by `DESIGN.md`, `LESSONS.md`, `ROADMAP.md`, `Regression_Root_Cause_Tracker.md`, or by a retained frozen definition/review authority. Their transitive dependency chain remains exact-byte authority and was deliberately excluded from this retirement.

All other superseded CP4c-3 per-turn files that had no live current/future dependency were folded into §§4/6 below and retired from the working tree. Git history remains the exact-byte recovery source for every retired file.

`DESIGN.md` §7.2/§7.2.1 remains architecture authority. Current status, regression accounting, workflow lessons, and orientation context remain in `Future_Chat_Session_Handoff.md`, `TODO.md`, `Regression_Root_Cause_Tracker.md`, `CHANGELOG.md`, `LESSONS.md`, and `ORIENTATION.md`.

The retained selector lineage is intentional. DEFN-R2 AG0 requires the superseded 357 and withdrawn 358 files to remain historical authority, and CP4c-3 verifies frozen prefix continuity. Current frozen hashes are:

| Authority | SHA-256 |
|---|---|
| accepted 355 prefix | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| 357 prefix | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| 361 prefix | `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b` |
| accepted 365 prefix | `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` |
| CP4c-3 selector 367 | `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf` |
| CP4c-3 selector 370 | `9160ea619afb9e10cbad30012d0bd354c263a2b749e690c271f653db3bf83525` |
| **CP4c-3 selector 373** | **`b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`** |
| **CP4c-3 selector 374 (gate)** | **`d496ce96b3776269cda8086a0a2173ce9a1f9967d81b2a80866266155c503c4f`** |
| CP4c-3 selector 375 (diagnostic) | `aa7b22bb265f321fad6f85128e572e0251dc5f60d68856ca7ec4323006a8f3a0` |
| **CP4c-3 selector 376 (TB9 execution / identity 376 diagnostic)** | **`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`** |
| **CP4c-3 selector 377 (TB10/TB11 execution; frozen prefix)** | **`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`** |
| **CP4c-3 selector 378 (TB12 execution / diagnostic projection)** | **`86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`** |
| **CP4c-3 selector 379 (TB13 execution / frozen prefix)** | **`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`** |
| **CP4c-3 selector 380 (TB14 execution)** | **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`** |
| **CP4c-3 selector 381 (TB15 execution / frozen prefix)** | **`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`** |
| **CP4c-3 selector 382 (TB16 execution / current selector)** | **`f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`** |

## 2. Checkpoint closure record

| Checkpoint | Closed responsibility | Accepted result |
|---|---|---|
| **CP4c-0** | exact resolved continuation and grazing | **346/346 CLOSED** |
| **CP4c-0b** | exact crash-on-contact termination / arrival | **353/353 CLOSED** |
| **CP4c-1** | observability, diagnosability, non-vacuous terminal events | **355/355 CLOSED** |
| **CP4c-2** | closed/higher-genus region authority, cut graph, cellularity | **365/365 CLOSED** |
| **CP4c-3** | mechanical witness / field-aligned continuation plus inherited CP4c-2 debts | **OPEN; TB17/package87 is current runtime authority at 374 PASS / 8 RED, accepted 365/365. First red 366 is `TraceCutFaceFragmentCountMismatch` at `(0,1,102)`. Exact next is independent `M3-CP4c-3-TB17-REV`.** |

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

This section is navigation only; `M3_CP4c_Frozen_Definitions.md` Part IV and
`M3_CP4c_Frozen_Definitions.md` Part VI remain normative. Current measured runtime authority is
`Architecture_M3_CP4c3_TB16_Artifact_Only_Test_Benchmark_Report.md`; current build/package authority is CB19/package 87.

### `M3-CP4c-3-TB16` — current measured runtime boundary

Artifact-only TB16 consumed immutable package **86** / source `a01016ca59314232526c8b1222c96235856ace6d` / selector **382**. Run/job `33709721203 / 100506452813`; result/log artifacts `9876548209` (`573f8eacf7de1ac993cfd2a4ef440514e2acb3bd6d0a85f322ac280bfec0b89f`) / `9876548556` (`2d0cd2ab4ff4068293d0a2bb8449d0119fa03014a93cb561575d1da7a55cb75b`). All 382 identities ran one-per-fresh-process. A temporary exact-`[ OK ]` summary parser repeated TB14's reporting-only bug; immutable exit codes and terminal logs reconstruct the authoritative ledger to **374 PASS / 8 RED**, accepted 1-365 **365/365 PASS**, true reds 366/367/368/369/370/371/372/374, corrected ledger SHA-256 `7c4464134a7be19150094bbee874ebe99878c3eaa004908d3660c1ffaa36b6fd`. No semantic rerun occurred.

Ordinal 366 clears the edge-25-31 `EdgeTraceSecondaryRankInvalid` frontier and reaches region construction, now failing `RegionTraceSourcePortCarrierNotAdmissible` at source face `(9,11,17)`. Selectors 380/381/382 pass. Complete mechanical attempt-0 rotation now publishes; with unchanged network incidence/TB12's retained five-ray census and selector-382 collision-free contact-relative rank ordering, the v47 obligation is discharged and TB11-CAND-01 / TB12-REV-CAND-01 / TB15-CAND-01 close. The new `M3-CP4c3-TB16-CAND-01` owns the region-building surface pending static adjudication. Pre/post package census is identical at `606d193e3641ec68114c5616d41bd0e8e43207756f79ae50356ce973c1be10db`; no benchmark/build/repair/mutation occurred. Stable accounting remains 44/14/30, debt 5, packages 83. Exact next: independent `M3-CP4c-3-TB16-REV` BQ0-BQ8.

### `M3-CP4c-3-TB15` — prior measured runtime boundary

Artifact-only TB15 consumed immutable package **85** / semantic source `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4` / selector **381** with no rebuild or repair. Run/job `33700074471 / 100477303760` executed all 381 identities one-per-fresh-process for **372 PASS / 9 RED**; accepted ordinals **1-365 remain 365/365 PASS** and first red **366** remains `RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid` at source edge `25-31` / face `(25,30,31)`, attempt 0 / zero cut edges. CB17's typed instrumentation identifies the exact branch as **`SourceVertexFallbackUnbound`** with source vertex 35, arc 19 / trace 5 / Reverse / `[0,5)`, outgoing carrier `25-31`, contact index 2, no incoming/other carrier, and a complete three-ray census. Result/log artifacts are `9873244271` / `9873244582`; immutable package postflight is unchanged. TB15-REV then proved the incidence valid, the fallback datum wrong, and the absolute corner-rank latent defect; it froze CB18 BP0-BP9. Stable accounting remains 44 / 14 / 30, debt 5, packages 82.

### `M3-CP4c-3-CB19` — current build/package boundary

CB19 final semantic source `bf971a6c9ad55e9c06c58f9fc73e9112808e5a1e` implements TB16-REV BR0–BR9 without Directional runtime. A shared `is_terminal_slit()` predicate makes a trace's last no-barrier segment non-material in both region-building loops before fragment-count, touched-edge or orbit-evidence mutation. `resolve_carrierless_corner_binding()` binds through the current segment's exact `entryPoint.source_support()`, fails closed unless it is a vertex of the selected face, and keeps `trace->sourceVertex` only as the first-segment consistency rule. The fragment invariant is explicitly `k real trace chords -> k+1 fragments`, with a terminal slit contributing zero. Complete trace-segment incidence is attached at the emitter and survives projection through `SurfaceCutGraphError`/production diagnostics. The independent fragment oracle mirrors the same contract; compiled observations cover a non-first carrier-less segment whose entry corner differs from the trace origin and a terminal slit with zero real-chord contribution. These witnesses are compiled but intentionally unexecuted until TB17.

Selectors 380/381/382 remain byte-frozen; selector 382 SHA-256 is `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`, accepted prefix 365 is `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, and no selector 383 was created. Authoritative eight-target GMP/GMPXX compile `33761967427 / 100670323823` is GREEN: result artifact `9895999746` (Actions digest `71b268f187b39ce547648c27543913e8fdef0bb1087eaaeca0d2948ce020c990`) and log `9896000247` (`767a9802e82e696aa714e9ca483813df253835a6132d9ec34e3b4a0e89b2c707`). Immutable package **87** run/job `33763450567 / 100675268847` is GREEN: artifact `9896472535` (Actions digest `78d1ac33c9db7592a8a852fafe91d0cabd0548ca5cf6309ceb50f689da9d9770`), inner tar `015c1113e2237e779076e397f4907b8a44f101ce159e566ff482f9c598f51c48`, packaged source `f54461f5cba89fdd8d54ad2a43d8476a1785676419535eaa21e1556e3e9b538a`, 27 fixtures and preserved executable modes. Package attempt `33763246701` failed only because its orchestration referenced the accepted 365 selector under the CP4c-3 filename; the corrected retry reused the same immutable compile artifact. `selected_gate=NONE`, `gate_execution_authorized=false`, `runtimeExecution=false`, `packageRepair=false` throughout. Stable **44 / 14 / 30**, debt **5**, semantic packages **84**. Exact next: artifact-only `M3-CP4c-3-TB17` on package 87 / selector 382 under BR9.

### `M3-CP4c-3-CB18` — prior build/package boundary

CB18 final semantic source `a01016ca59314232526c8b1222c96235856ace6d` implements TB15-REV BP0-BP9. In `edge_locus_secondary_rank`, the carrier-less fallback now uses the selected segment's exact far-end boundary support (entry for Reverse, exit for Forward) through `FieldBoundaryPoint::source_support()` and accepts only a vertex support that is a corner of the selected face. Its corner rank is contact-relative, `1 + 2*((corner + 2 - contactIndex) mod 3)`; the `contactIndex == 2` case recovers the shipped ordering. An unbindable far end remains typed `SourceVertexFallbackUnbound`. The carrier branch and excluded topology/collision/vertex-locus paths are unchanged. Compiled witnesses pin the previously successful singularity-start cases for contact indices 0/1/2, the positive Reverse vertex-entry case, the typed negative, fallback/carrier ordering, and ordinary two-carrier regression.

Selector **381** remains byte-frozen. Selector **382** is 381 plus exactly `GlobalTopologyPlan.EdgeLocusSecondaryRankUsesSegmentFarEndSupportAndContactRelativeOrdering`, SHA-256 `f30d5d5625682d928a4878e0139e6b04c9e9082f58e8a545c49c8a350d665a1a`. Authoritative eight-target GMP/GMPXX compile `33706268720 / 100495948544` is green; result/log artifacts `9875350611` (`cc2935716ecf7022fda6c120f0ef6313e60df553d34d7354b587e47ee9663d3a`) / `9875350974` (`ea39d44a9196e47934cb3ff626633c3031a2c607c542ef5e34298cc6665328f5`). Immutable package **86** run/job `33707299159 / 100499114323` is green: artifact `9875664940` (`8c98b134a527db87b83852de175288a320a158405d22867d95ba986cf68cbef8`), log `9875665222` (`fe86b4f391d731eb629461e1d79cb3b9543f1bab968fa922c1f8a0deb9565d28`), inner tar `125d2851164d7af62f90a3ff6ad8f360076a651c8575b655acac59fb50b9e9e7`, packaged source `c96446f169959c56f3c536c7fe711df6f7741d679cbd1413cc7c464838a659e8`, 57/57 manifest, 27 fixtures and six executable modes. Final packaging used direct artifact-ZIP extraction after an orchestration-only mode-loss attempt; no package repair and no Directional runtime occurred. TB16 has since runtime-proved accepted **365/365**, cleared the edge-rank frontier, and discharged the v47 obligation; package 86 remains the immutable TB16 runtime package but is superseded as build/package authority by CB19/package 87. Stable **44 / 14 / 30**, debt **5**, semantic packages **83**.

### `M3-CP4c-3-CB17` — prior build/package boundary

CB17 final source `1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4` adds diagnostic-only typed exits for `edge_locus_secondary_rank`, preserves the failing incidence, and publishes a bounded production edge-locus ray census without changing rank/topology semantics. Selector **381** is selector 380 plus one compiled witness, SHA-256 `af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`. Authoritative eight-target GMP/GMPXX compile `33697315308 / 100468915978` is green. Immutable package **85** artifact `9872426500` has Actions digest `6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`, inner tar `98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`, packaged source `cb078005cef48d97401ddfb843a4276f92c53086b0827a915b01344dc665c4a9`. No runtime executed. Packages advance to 82; accepted authority remains 365/365. Exact next: artifact-only TB15 on selector 381.

### `M3-CP4c-3-TB14` — prior measured runtime boundary

Artifact-only TB14 consumed immutable package **84** / selector **380** from source `6808c090f2dd229a48550d758f459bfd156da4b6`. After a local-host partial attempt was classified infrastructure-only, the user authorized a complete replacement on GitHub Actions. Run/job `33689875040 / 100445977571` completed all 380 fresh selector processes plus the retained non-gating diagnostic with no repository timeout. Result/log artifacts are `9869697113` (`a96d8ff82b467c0cfd89c1437fc0a146461ab18d4850e04515acc562070b975a`) / `9869697543` (`5e961520a3844d5b01ab77d4b85b5117c4124bfa03d4993812270e4563deb5f2`). A temporary exact-line `[ OK ]` parser mislabeled passing rows but preserved raw exit codes/logs; corrected immutable evidence is **371 PASS / 9 RED**, accepted 1-365 **365/365 PASS**, first red 366. Corrected ledger SHA-256 is `0b42866471ce0ad5939ab2d3c2d5c82f4efebb93c0a56ca7a60e295fad07397b`; no semantic rerun was used to repair reporting.

Ordinal 366 clears TB13's vertex-10 `VertexTracePortOrdinalInvalid` and now fails at source edge `25-31` / face `(25,30,31)` with `EdgeTraceSecondaryRankInvalid`, attempt 0 / zero cut edges / 450 candidates. Selector 379 PASSes; selector 380 REDs only at its final production assertion on the same new frontier. The old v47 collision remains absent, but complete attempt-0 rotation does not publish, so the five-ray v47/distinct-rank conjunction remains open. 368/369/370/374 retain prior owners; 371/372 inherit the new mechanical upstream stop. Package postflight is immutable. Stable accounting remains 44/14/30, debt 5, packages 81. Exact next: `M3-CP4c-3-TB14-REV` BM0-BM8.

### `M3-CP4c-3-CB16` — prior build/package boundary

CB16 final source `6808c090f2dd229a48550d758f459bfd156da4b6` adds the exact source-vertex corner fallback last in the Forward vertex-ray second-point chain and separates secondary-parameter failure from legacy port/ordinal failure. Eight-target GMP/GMPXX compile `33682499470 / 100422188581` is green. Immutable package **84** artifact `9867334959` has Actions SHA-256 `67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`; inner tar `8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`; selector 380 `1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`. TB14 now provides its runtime disposition; accepted authority remains 365/365.

### `M3-CP4c-3-TB13` — prior measured runtime boundary

Artifact-only TB13 consumed immutable package **83** / selector **379** from source `a2fd98eaa015ff5872890bb1945cf4e9e9493615`. Run/job `33671968437 / 100387569925`; result/log artifacts `9862995609` (`d7da71ea122a20225e6e3e7b9f2534fd3a7d8c1b1401ebc64b5f1191eb21bb8b`) / `9862996106` (`b9a6288472f0ec204f93aa0f209b457c365e4c8ecf98e166c100c99bb3f6caf4`). All 379 identities ran in fresh processes: **371 PASS / 8 RED**; accepted 1-365 green, first red 366, and selector 379 PASS. The old v47 `RotationRayOrderKeyCollision` is absent at ordinal 366, but production now fails earlier at source vertex 10 / face `(8,10,11)` under `VertexTracePortOrdinalInvalid`, attempt 0 / zero cut edges. Because that earlier failure prevents publication of the v47 five-ray census and former-pair secondary ranks, the TB11 closure conjunction is not satisfied. Package source reuses the new reason for both legacy port validation and exact secondary-parameter failure, so exact cause is underdetermined and owned by `M3-CP4c-3-TB13-REV` BK0-BK8. Package postflight is immutable; accepted authority 365/365, accounting 44/14/30, debt 5, packages 80.

### `M3-CP4c-3-CB15` — prior build/package boundary

CB15 final source `a2fd98eaa015ff5872890bb1945cf4e9e9493615` replaces vertex-locus origin-port ordinal ordering with exact locus-relative within-wedge rank and keeps exact coincidence fail-closed. Eight-target GMP/GMPXX compile `33667287957 / 100372314673` is green. Immutable package **83** artifact `9861269273` has Actions SHA-256 `1b8ce6a12edc8f7949deea3c43855e94e5755c0e73ed1cb603a2acd50901cab4`; inner tar `c09d98ed35e9155805f759f27f54491b03643851650ce49dcb65c2191fc069ff`; selector 379 `ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`. TB13 now provides its runtime disposition; accepted authority remains 365/365.

### `M3-CP4c-3-TB12` — prior measured runtime boundary

Artifact-only TB12 consumed package **82** / selector **378** with no rebuild or repair. Run/job
`33657062615 / 100338185825`; result/log artifacts `9857275334`
(`085b3de9ebf5a9a29cbcf883e4058c97855e11a1a7b2bc53f961c809dace9145`) / `9857276091`
(`89cac6cb1ea6444b8204d8b5ca9233daed7e0ff88986d8592af576e319cb4120`). All 378 selector identities ran in
fresh processes: **370 PASS / 8 RED**, accepted 1-365 green, first red 366. The retained collision pair is arc
20/trace 6/Forward/origin vertex 47 versus arc 23/trace 9/Reverse/origin vertex 71; both have
`(primary,secondary)=(3,0)` in face `(45,46,47)` / fan slot 1. The full fan census contains five rays and is not
truncated. Unmeasured `nonDiscComponentCount` and `remainingAdmissibleEdgeCount` are absent. Selector 378 PASSes
production diagnostic projection; the separate mechanical diagnostic ran once with zero gate credit. Package
postflight is immutable. The simplest duplicate-incidence identity case is falsified, but valid coincident/tie
semantics versus invalid/stale provenance or witness/precondition remains semantically unadjudicated. Exact next is
`M3-CP4c-3-TB12-REV` under BI0-BI7; accepted authority 365/365, accounting 44/14/30, debt 5, packages 79.

### `M3-CP4c-3-CB14` — prior build/package boundary

CB14 executed TB11-REV **BH0–BH9** as a **diagnostic-only** Code + Build turn. Final source
`71ece3ca184e90858d9222fb014b37c16d292294` retains both colliding rotation rays with typed key operands,
arc/trace/face identity, orientation, fan slot, and origin-port ordinal/source-vertex evidence; publishes a bounded
keyed-fan census; and prevents unmeasured certification counters from rendering as observed zeros. It also compiles
a production-renderer synthetic same-sector witness and the mechanical ordinal-366 diagnostic assertion. No
collision/order/incidence/rotation/cut semantics or fixtures changed.

Selector **377** remains byte-frozen at
`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`. Selector **378** is exactly 377 plus one
non-gating diagnostic identity, SHA-256 `86259d919b387ba4a610b42c4dd1a190ae340f693437b5a769cd50ca396440b8`.
Authoritative compile run/job `33653092570 / 100324843819` passed all eight standard targets with GMP/GMPXX and no
runtime. Immutable package **82** was frozen by run/job `33653737897 / 100327139865`: artifact `9855841174`
(Actions SHA-256 `4f597d260a6fb258767378489741326a6f6c2322522bdd60ef9fd071970c26ed`), inner tar
`58393e9927e80e894a753cafee074202fd6df8fec43d8cba244fe1404e23a5e1`, packaged source
`3ae91b7544749f00487ff57e1705d657d23d84ffe3107ce1a4565c3a24d35f1e`, 27 fixtures and six executables.

CB14 changes no acceptance: accepted authority remains **365/365**, CP4c-3 OPEN, stable **44 / 14 / 30**, debt
**5**, semantic packages **79**. Its diagnostic owner is discharged by TB12 runtime; package 82 remains current
build/package authority.

### `M3-CP4c-3-TB11` — prior measured runtime boundary

Artifact-only TB11 consumed package **81** / selector **377** with no rebuild or repair. Run/job `33611378451 / 100187075757`; 377 fresh processes produced **369 PASS / 8 RED**, with accepted 1–365 green and first red 366. Ordinal 366 now publishes `RotationRayOrderKeyCollision`, source vertex 47, certification attempt 0 / zero cut edges, 450 cut candidates, zero non-disc components and zero remaining admissible edges. Static package source maps the reason uniquely to `build_rotation_system` after key construction/sort and before final CCW rotation publication. The one non-gating diagnostic independently re-derived the same reason/stage and has zero gate credit. Package postflight is immutable. 367/371/372 remain upstream-blocked; 368/369/370/374 retain prior ownership. Exact next is `M3-CP4c-3-TB11-REV` under BG0–BG7; accepted authority 365/365, accounting 44/14/30, debt 5, packages 78.

### `M3-CP4c-3-TB10` — prior measured runtime boundary

Artifact-only TB10 consumed package **80** / selector **377** without rebuild or repair. Run/job
`33584653692 / 100106147126`, result artifact `9829700900`
(`2e7d978dd3ad2a5f0667ef3eed15c291ed8c7b91bb7e2d323557a8bc40763572`), log artifact `9829701136`
(`89f445c5934c3493ccf966e39f0c106c8418719a32c5d206055cafa932cce17d`). All 377 identities ran in fresh
processes: **369 PASS / 8 RED**. Ordinals 1–365 remain green; ordinal 366 is first red at
`CellularityNotEstablished/origin=RotationSystemInconsistent`. The old seed-47/singularity-5 terminal-ownership
condition is absent and identity 377 passes at v36 / `BarrierAbsorbed` / node 7, closing
`M3-CP4c3-TB9-REV-CAND-01`. The new `M3-CP4c3-TB10-CAND-01` is a production-projection diagnostic gap: the
cut-graph error carries the rotation-system subreason/locus but the pipeline failure string omits it. 367/371/372 are
upstream-blocked by that same mechanical stop; sphere 368, saturation 369, ordinal 370 and folded-cone 374 retain
their prior independent dispositions. Immutable postflight passed. Accepted authority stays **365/365**, stable
**44 / 14 / 30**, debt **5**, semantic packages **77**. Exact successor: independent
`M3-CP4c-3-TB10-REV` under BE0–BE7.

### `M3-CP4c-3-CB12` — prior build/package boundary

CB12 executed TB9-REV **BD0–BD9** as a product correction. Exact source
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15` carries explicit singularity port policy into terminal ownership.
`BarrierAbsorbed` arrivals resolve the singularity's already-created network node by support vertex; `Emit` retains
its existing port-owned path. Missing barrier node fails closed with a distinct condition. A compiled mechanical
witness derives v36, its `BarrierAbsorbed` singularity, network node and mandatory-barrier incidence and covers both
negative missing-node and positive node-owned termination cases.

Selectors 374/375/376 are unchanged. Selector **377** is selector 376 plus exactly
`ResolvedBranchCorrection.BarrierAbsorbedMechanicalTerminationUsesNetworkNodeWithoutPort`, SHA-256
`7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`. Compile run/job
`33581576670 / 100096794713` passed all eight required targets with GMP/GMPXX and no runtime. Package run/job
`33582280392 / 100098880900` froze immutable package **80**, artifact `9828786744`, inner tar
`4e8303489adb46528ae0a92c7ecf9dae65f0cbd57527740d845d318c65af02ce`, packaged source
`026a8b1efa2dc85fe2b474e0e64657bf8f997aee5b49f274c7c0c69d279fd18a`.

At the CB12 boundary, authority stayed **365/365**, CP4c-3 OPEN, stable **44 / 14 / 30**, debt **5**, semantic
packages **77**; `M3-CP4c3-TB9-REV-CAND-01` remained active pending TB10. TB10 has since consumed package 80,
closed that candidate, and moved the first red to `M3-CP4c3-TB10-CAND-01`.

### `M3-CP4c-3-CB11` — prior build/package boundary

CB11 executed TB8-REV **BB0–BB9** diagnostic-only. Final semantic/evidence source
`803300698289e0d0f629eaa878add1aebc7193c1` carries the trace-scoped network-error group, exact values,
published-edge/face authority, and a typed discriminator for all twelve `InvalidNetworkTerminalOwnership` emission
conditions through the production failure DTO/renderer. It also moves ordinal 329's losslessness guarantee to the
production projection and adds witnesses for both statically surviving ownership sites. The `terminalContact`
fall-through is diagnosed but deliberately unchanged.

Selector 374 and 375 hashes remain byte-frozen. Selector **376** is selector 375 plus exactly one diagnostic identity,
`ResolvedBranchCorrection.NetworkTerminalOwnershipConditionsSurviveProductionFailureProjection`, SHA-256
`6ab2d9fad0327e00bb2f782741afffe8a0ae08c08df8adbdf9accc6234bfa5e8`.

The first compile exposed an anonymous-namespace linkage defect in the diagnostic wrapper; a one-site linkage-only
correction produced final source `803300…`. Authoritative compile run/job `33573956609 / 100073749252` passed all
eight required targets with GMP/GMPXX and no runtime. Result/log artifacts are `9825961944 / 9825962219`.
Runtime-free package run/job `33574167362 / 100074416093` froze immutable package **79**, artifact `9826005253`, inner
tar `dfc197b50ea5b9b88468aa00665470af5aa0e2959de9c380fcd6aebdb978ec99`, packaged source
`61107e4fc90368793ebe97c3581cea6cb301effc74c6f39cc3259316066aa0f6`.

No acceptance changes in CB11: authority stays **365/365**, CP4c-3 OPEN, stable totals **44 / 14 / 30**, debt **5**,
semantic packages **76**. `M3-CP4c3-TB8-REV-CAND-01` closes at implementation/build scope;
`M3-CP4c3-TB8-CAND-01` remains active until TB9 names the firing site.

### `M3-CP4c-3-TB9` — prior runtime boundary

TB9 consumed immutable package **79** in run/job `33575920177 / 100079784804`. Result artifact `9826689980`
(`abea3172c6515bbf5b6fdede5abe96ae6086724299d014201ce3ff020016b68d`) and log artifact `9826690247`
(`c92be7d59ecfb963eb225099737ed99efcb169244bfaa4c9519a1a98967cd648`) are authoritative. Immutable
pre/postflight PASSed, static source mapping resolved every selector identity to exactly one packaged executable, and
all prohibited build/repair/discovery/mutation/benchmark flags remained false.

Selector 376 re-proved **365/365** accepted authority. Ordinal 366 remains first red at edge `36-38`, face
`(36,38,39)`, branch 2, but the production renderer now adds
`networkErrorCondition=SingularityTerminationPortOwnershipMismatch`, `traceSeedVertex=47`,
`traceSeedSingularity=5`, and five exact branch-2 history rows with `traceHistoryTruncated=false`. This resolves the
TB8 two-site ambiguity to `append_field_aligned_singularity_termination` and excludes the finalize/contact fall-through
as this first-red emitter. The old `publishedFaceCount` token is gone; the actual published-face collection is empty.

Report-only 367–375 is **2 PASS / 7 RED**: 373 and 375 pass; 367/371/372 share the mechanical ownership blocker;
368 sphere, 369 saturation, 370 empty-network, and 374 folded-cone dispositions remain unchanged. Diagnostic 376
PASSes with zero gate credit, runtime-closing `M3-CP4c3-TB8-REV-CAND-01`. `M3-CP4c3-TB8-CAND-01` stays active/gating
at the named singularity-terminal site; TB9-REV must determine which internal guard disjunct/invariant owns the
failure before any correction. Stable accounting remains **44 / 14 / 30**, debt **5**, packages **76**.

### `M3-CP4c-3-TB8` — prior runtime boundary

TB8 consumed immutable package 78 from semantic source `e2b59295c9920db5685239c2da188858839fa94f` in run/job
`33561723204 / 100035596811`. Result artifact `9821602279`
(`e9858ac5194646f888a193937e52cc504aa36a6940d79904b36f70c059026a62`) and log artifact `9821602943`
(`1f41626b53642bb30a00bcaafbbc3993d09870c20c2ffc15f2224670ecc65239`) are authoritative. Immutable pre/postflight
PASSed with all build/repair/mutation/benchmark flags false.

Selector 374 re-proved **365/365** and first-reds at ordinal 366 with
`InvalidNetworkTerminalOwnership;sourceEdge=36-38;sourceFace=36,38,39;branch=2;publishedFaceCount=0`, proving CB10
cleared the earlier source-vertex-11 seed stop while exposing a new later masking locus. Vertex 30 remains unreached.
Report-only 367–374 is **1 PASS / 7 RED** with the sphere/saturation/370/374 dispositions unchanged and 373
synthetically green. Diagnostic 375 PASSes separately with zero gate credit; together with green 328/329 it closes
the TB7 radial-arrival and TB7-REV audit/rendering defects, but not the general non-flat exact-fallback/budget class.

`M3-CP4c-3-TB1` consumed immutable package **68** (`9739919234`) directly in run/job
`33340448381 / 99335020672`. Result artifact `9740416876` has SHA-256
`713d4e6853adde54e17738d6d25e5a310a5f88ff8e4232abf67bb73c7a8cbdc0`; log artifact `9740417020` has
SHA-256 `8302f6ae50a8d5d29f92952aed0f144eb78bda3f070612f3dec67a63701debc0`. Immutable pre/postflight passed,
package/source were unchanged, and no configure/compile/relink/repair/generated-discovery/benchmark/mutation occurred.

The frozen 367 selector re-proved the accepted **365/365** prefix, then first-red hard-stopped at ordinal **366**:
`GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`. Required result:
**366 executed / 365 PASS / 1 RED**; ordinal 367 was not executed after the red.

Phase-1 measurements are now concrete:

- mechanical A1: `IncompleteCycleBasisReason=CycleTransportAdjacencyMissing`;
- mechanical locus: region `0`, source edge `0-3`, `fieldTransportAdjacencyExists=false`;
- mechanical AK2 row: `V/E/F=152/450/300`, χ=2, boundary loops=0, genus=0, interior local vertices=152,
  expected cycles=152, cycle rows=152, cycle curvatures=152, inner adjacencies=450;
- prescribed sphere: `RotationSystemInconsistent → TraceEventPositionInvalid` after source topology, atlas and network
  succeed (24 traces / 56 events);
- frozen non-gating diagnostics all executed report-only: torus retains a valid cut graph/global plan before the
  existing downstream tracing failure; mechanical and sphere reproduce the measured AK1–AK3 causes.

Inherited CP4c-2 dispositions remain explicit:

- `M3-CP4c2-TB-X2-CAND-04`: still active/non-stable, now localized by AK3 to `TraceEventPositionInvalid`; the
  independent pre-cut non-cellularity evidence remains separate.
- `M3-CP4c2-TB-X2-R10-CAND-01`: cause established; corrective remains proposal-heuristic-only, using per-face trace
  chords; Amendment 14 certification is not reopened.
- `M3-CP4c2-TB-X2-R8-CAND-02`: decided; an empty closed-surface network must fail closed with an appended typed
  `SurfaceCutGraphErrorCode`.
- `M3-CP4c3-DEFN-CAND-01`: no longer diagnostically ambiguous; TB1 measured
  `CycleTransportAdjacencyMissing`, and the independent review now owns AK6 corrective interpretation.

### `M3-CP4c-3-TB1-REV` adjudication (measures AL0–AL9)

Review record: `Architecture_M3_CP4c3_TB1_Independent_Review_Record.md`. TB1's execution is **ACCEPTED** as a valid
semantic red; the working tree is byte-identical to the packaged semantic source, and CB1 delivered AK1–AK3 exactly
as specified — additive, enumerated, no mapping changed and no enum value renumbered.

- **`M3-CP4c3-DEFN-CAND-01` → CAUSE ESTABLISHED.** Edge `0-3` is a `HardFeature` **barrier** by elimination over
  `FieldTransportAtlas::make`'s four adjacency buckets. It entered the cycle basis because
  `build_source_topology_regions` skips hard-feature edges when flood-filling regions and **skipping an adjacency
  disconnects nothing unless the edges separate** — region 0 is all 300 faces with `boundaryLoops=0`, so the edge
  stayed interior to the local mesh and the walk demanded an adjacency the atlas deliberately withheld. The region
  decomposition and the traversability classification **disagree about the same edge**. Region 0 is a sphere
  (`χ=2`, genus 0, no boundary) and every closed curve on a sphere separates, so the feature set necessarily
  contains at least one **open arc**; the torus escapes only because its four hard-feature loops **do** separate it.
  The corrective is a normative choice (**A** cut the local mesh along the arc, recommended; **D** typed fail-closed
  as the frozen fallback; **C** giving barrier edges an adjacency is **prohibited**) owned by `M3-CP4c-3-DEFN-R1`.
- **`M3-CP4c2-TB-X2-CAND-04` → ACTIVE / ONE LEVEL SHORT.** `TraceEventPositionInvalid` is itself a two-way collapse
  in `trace_event_position` — `positions.empty()` (a binding defect) versus `positions.size() > 1` (an ambiguity) —
  needing **opposite** fixes, plus a widening second pass that can manufacture the ambiguous case. Ambiguity is a
  suspicion, not a finding. **AL3** measures it; **AL4** forbids designing across it. Phase 2 is **not** authorized
  for this witness.
- **The two measured causes share no locus** (A1 `FieldTransportAtlas` versus A2a′ `EmbeddedGraphTopology`), so
  phase 2 opened for the mechanical witness alone and the inherited items remain independently workable under
  **AL6**.
- **`M3-CP4c3-TB1-ORCH-01`** is closed but **escalated**: its 63-hex digest is the third `R7-ORCH-01` occurrence, so
  **AL8** moves the 64-lowercase-hex validation into the orchestration payload authoring path.
- `LESSONS.md` **64** added: *when instrumenting a collapsed error, check whether the reason you are adding is
  itself a collapse before declaring the layer done.*

Stable accounting remains **44 / 14 / 30**, debt **5**, packages **68**; TB1 added **+0 events / +0 recurrences**.

### `M3-CP4c-3-DEFN-R1` — Amendment 15 (measures AM0–AM9)

Record: `M3_CP4c_Frozen_Definitions.md` Part V. Normative record: `DESIGN.md` §7.2.1
**Amendment 15**. Definition, review and planning in one turn under the standing cadence; no runtime, no compile,
no packaging, no gate execution, and no product/test/fixture/selector byte changed.

**Decision.** A region's face set and its published `euler_characteristic()` / `boundary_loop_count()` describe the
**uncut** source complex and are unchanged. A1 derives its tangent bundle, cycle basis and index quantities from
the region's **transport domain** — the region **cut along** `B(R) = { e ∈ hardFeatureEdges : both incident faces
∈ R }` — in A1's **derived local mesh only**. Option C stays prohibited; option D is the frozen fallback with a
declared trigger and the stated cost that C2 cannot then close.

**Two theorems, both forced by construction rather than observed:** `B(R)` is the entire defect class, because a
source-boundary edge and a region-/component-crossing edge each have at most one incident face in `R` and are
already local boundary edges, while a traversable edge has an adjacency — and isolation seams are traversable by
design, so they are **not** barriers; and the cut never disconnects, because a region *is* a connected component
of the face graph built without barrier edges, from which it follows that no subset of `B(R)` separates `R` and
that on a `χ=2, b=0` region every barrier component is a tree.

**Endpoint rule and arithmetic.** `copies(v)` = connected components of `star(v) ∖ B(R)` = `d_B(v)` interior,
`d_B(v) + 1` on the boundary, so an open arc's **tip is not duplicated** but becomes a boundary vertex; the result
is a manifold with boundary and `set_mesh` re-derives every count. `χ(R_cut) = χ(R) − χ(B) + ∂`, verified against
four independent cases. Mechanical witness: `χ' = 2 − c`, `b' = c`, genus 0, `interiorVertices' = 152 − |V(B)|`,
`innerAdjacencies = 450 − |B|`, cycle-matrix rank deficiency unchanged at **1**. Because `dual_cycles` indexes
columns into inner edges only, a barrier can never again raise `CycleTransportAdjacencyMissing`.

**Three costs, all required work:** replace (never delete) the local-mesh-versus-region cross-check with the cut
identity; disclose the move from the closed index equality to the weaker boundary-corrected branch; and make the
interior-singularity binding fail closed. The last opens **`M3-CP4c3-DEFN-R1-CAND-01`** — a pre-existing latent
gap at HEAD, not introduced here but made reachable by the cut — and is recorded as `LESSONS.md` **65**.

Gate **367** stays frozen and unselected; the append point 367 → **370** (AL7) → **373** (Amendment 15's three
identities) is defined but executed at CB2's freeze. Accounting unchanged, **+0 events / +0 recurrences**.

The exact next turn is **`M3-CP4c-3-CB2`** — Code + Build under **AM0–AM9**, runtime-free, GMP/GMPXX linked.

### `M3-CP4c-3-TB2` — orchestration-invalid fixture-root stop

TB2 consumed immutable package **69** and reproduced the complete artifact/source/GMP/selector preflight. The frozen
373 selector then began one identity per fresh process: ordinals **1–40** selected exactly once and exited green.
Ordinal **41**, `MilestoneGP26.PrescribedSphereSingularitiesMatchRecoveredValence`, selected once but threw before
product adjudication because it could not open
`/home/runner/work/Directional/Directional/benchmarks/fixtures/milestone_g_manifest.json`.

The manifest is present in the immutable packaged source. The harness lacked sibling/bin `test-data`, so
`TestFixturePaths` fell back to the producer binary's compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR`; the local
artifact-only execution materialized the packaged source elsewhere. This is **`M3-CP4c3-TB2-ORCH-01`**, not a
semantic product red. Because 41 Directional processes had already run, the frozen TB2 plan forbids an in-turn
corrected-root restart. Ordinals **42–373 were not executed**, so no CP4c-3 checkpoint-local runtime conclusion can
be drawn.

Postflight re-proved package SHA, **28/28** manifest, source archive, selector 373, executable mode and source-tree
immutability; no configure/compile/relink/repair/generated-discovery/benchmark or source/test/fixture/selector/package
mutation occurred. Stable accounting is unchanged at **44 / 14 / 30**, debt **5**, packages **69**.

**Superseded within the same turn.** The user authorized a fixture-only correction; package **70** (artifact
`9744461475`) relocated the exact immutable fixture tree from the packaged source archive into the sibling
`test-data` root the binary probes first, and run `33355714664` re-executed selector 373 from ordinal 1. The record
below is retained because it is where the packaging defect was first observed; the authoritative TB2 result is the
valid semantic red at ordinal 366.

### `M3-CP4c-3-TB2-REV` — Amendment 16 (measures AN0–AN9)

Record: `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md`. Normative record: `DESIGN.md` §7.2.1
**Amendment 16**. Review, definition and planning in one turn; no runtime, no compile, no packaging, no gate
execution, and no product/test/fixture/selector byte changed.

- **Execution ACCEPTED.** Selector 373 was recomputed from committed bytes and all six predecessor prefixes (355,
  357, 361, 365, 367, 370) reproduce exactly; the working tree is byte-identical to packaged source
  `005512f20ed56edc793f4d6505f3d2b4c2999c71`. The package-70 substitution is accepted as *relocation of already
  immutable bytes*, with one qualification: `semanticBinariesUnchanged=true` is self-reported and the two manifests
  (28 vs 55 entries) are not comparable line for line, so per-binary digests must be published (**AN2**).
- **Amendment 15 confirmed effective at runtime.** The mechanical witness advanced past `IncompleteCycleBasis`, and
  ordinals **1–365** are green, so the cut regressed nothing in the accepted gate.
- **New cause established by elimination:** `MissingSingularityBranchTransport` — `build_singularity_attachments`
  demands a branch transport on every radial edge of a **globally closed** one-ring fan, while `branchTransports`
  excludes every barrier by construction. **Proved pre-existing and merely unmasked**: CB2's diff to that file
  begins at old line 842, leaving `build_branch_transports`, `ordered_incident_fan` and
  `build_singularity_attachments` untouched.
- **Amendment 16** generalizes 15 to every A1 derivation that walks transport, prohibits supplying a barrier with a
  branch transport, and replaces a closed ring with the fan of one component of `star(v) ∖ B(R)`. It leaves the
  **port-emission policy** open pending AN1's census; **AN4** forbids designing across it.
- **Owned:** measure AM2 scoped its consumer audit by *symbol* rather than by *assumption*, so a faithful search
  could not have found this consumer. `LESSONS.md` **66**; **AN8** requires naming a consumer that holds the
  assumption without touching the changed data structures. `LESSONS.md` **67** records that per-site error
  instrumentation buys exactly one turn of visibility.
- **`M3-CP4c3-TB2-ORCH-01` reopened and reclassified** as a build/packaging contract defect owned by **AN3**: the
  binary's compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` fallback makes fixture resolution depend on the
  runner's directory layout.
- **Still unproved:** ordinals 367–373 never executed, so Amendment 15's three self-checks and AM1's barrier
  decomposition remain unmeasured and every DEFN-R1 prediction is unverified.

Exact successor: **`M3-CP4c-3-CB3`** — Code + Build under **AN0–AN9**, runtime-free, GMP/GMPXX linked.

### `M3-CP4c-3-CB3` — Amendment 16/P2 build green, package 71 portable

CB3 is **COMPLETE / BUILD GREEN / RUNTIME-FREE** at semantic source
`93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`. Static AN1 measurement found 8 prescribed +1 mechanical
singularities, 4 barrier-incident; all four are degree-2 `InteriorArc` facts with two cut-star components. Mechanical
`B(R)` is a four-component forest (`n=16, m=12, c=4, χ(B)=4`), while the prescribed sphere has zero active
barrier-incident singularities. Those facts select Amendment 16 **P2**: slit-bound barrier singularities are
`BarrierAbsorbed` and emit no singularity ports; no branch transport is ever created across a hard feature.

The atlas now publishes barrier-singularity census/classification and complete failure loci through pipeline
diagnostics. `build_singularity_attachments` skips the illegal closed-fan derivation for absorbed facts, and the
field-aligned producer respects the explicit port policy. The assumption audit also found
`canonical_field_aligned_candidate`, which independently assumed every singularity emitted `4-index` ports. No
sphere-specific correction was made and ordinals 367–373 remain frozen/unexecuted.

AN2 independently rehashes package 69/70 and proves all six binaries byte-identical. AN3 removes the compile-time
absolute `DIRECTIONAL_TEST_SOURCE_DIR` authority. Package **71** / artifact `9750235004`
(`bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`) carries 27 immutable fixtures under
`test-data/benchmarks/fixtures`; source archive SHA-256 is
`fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`. Run/job
`33370966957 / 99421816569` compiled all eight standard targets with GMP/GMPXX, source clean, build exit 0, and
`runtimeExecution=false`; package-fixtures job `99423544681` proved the manifest, fixture contract, and binary-byte
invariance. Stable accounting stays **44 / 14 / 30**, debt **5**; authoritative semantic package accounting becomes
**70**. Exact successor: artifact-only `M3-CP4c-3-TB3` on package 71 with selector 373.


### `M3-CP4c-3-TB3` — blocked before runtime by executable-mode package contract

TB3 is **COMPLETE / BLOCKED — PRE-RUNTIME / NO SEMANTIC VERDICT**. Run/job `33399144281 / 99510922630` consumed exact
package **71** (`9750235004`, `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`) and re-proved its complete internal manifest, semantic source
`93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, source archive `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`, and package-relative fixture payload. Before ordinal 1, all six
packaged test/benchmark executables were mode `0644`; policy forbids `chmod`, repacking, repair, or replacement
compilation inside artifact-only TB. Result/log artifacts are `9760518962` (`ec5bc5cccb99e38e4ce77533478c5864e756735b3511575d843bbafb328f4677`) and `9760519355`
(`b803c9f81df4a5acbea642860d88f8c61f3df8f13d2204cf836344f6efb1016d`). Selector execution is **0/373** and all runtime/build/mutation flags remain false.

`M3-CP4c3-TB3-ORCH-01` is **RESOLVED / PACKAGE CONTRACT CORRECTED / NON-STABLE**. TB3-REV traced package-71 mode loss to `actions/download-artifact@v4`; CB4-PKG then consumed raw artifact 9750227619 without replacement compilation and produced immutable package **72** in run/job `33411346157 / 99551438549`. Artifact `9765247195` has Actions SHA-256 `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`; inner `package72.tar.gz` is `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`. Independent clean extraction verifies the 55-entry manifest, semantic source/archive, GMP boundary, exactly 27 fixtures, and all six frozen binary hashes at mode `0755`. No Directional runtime or semantic mutation occurred. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.

### `M3-CP4c-3-TB3-R1` — valid semantic red at vertex-transit sector resolution

Mode-preserving package **72** enabled the first valid TB3 semantic execution. Run/job `33416686424 / 99568970224` passed immutable package/tar/source/GMP/fixture/binary-mode/selector preflight, then executed ordinals 1–365 as **365/365 PASS** and first-red at ordinal **366** `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` with `NotProductionReady/field-aligned-network/VertexTransitSectorUnresolved`. First-red semantics left 367–373 unexecuted. Result/log artifacts are `9767376410` (`7f2c9492d2dae96dfcf1732c320e772be05538a3552ce6a673bd83eb9189824e`) and `9767376976` (`492d19f1e08fd339f130a07dfcf891a3b7bbaaf537483fb54af6e9b96095ad72`); immutable postflight passed and all prohibited build/repair/mutation flags remained false.

The old `MissingSingularityBranchTransport` locus is cleared: atlas partition diagnostics are emitted and the mechanical witness reaches network construction. Static source localizes the new code to `resolve_field_vertex_transit`, which walks transported `(face,branch)` states around the hit vertex and requires exactly one `direction_in_vertex_sector` candidate. The production exception drops the typed network error's source vertex/face/branch/candidate-face details, so runtime does not reveal whether candidate cardinality is zero or greater than one, nor whether the failing arrival is `FaceInterior` or `EdgeTransit`. New non-stable gating candidate `M3-CP4c3-TB3-R1-CAND-01` is therefore routed to independent review, not patched inside TB. Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **70**.



### `M3-CP4c-3-CB5` — typed failure locus and immutable package 73

CB5 implements AP1/AP2 diagnostics only on source `2d22ef293363058cfdca96d01158a93d2c0200f8`. Atlas, field-aligned-network, surface-cut-graph and
global-topology-plan errors retain a shared typed locus; the network locus additionally carries arrival mode,
candidate cardinality/faces, `BarrierAbsorbed`, barrier incidence/degree and transport-star component count.
AP8 independently found cut-graph and global-topology typed-loss sites. No transit/product semantic correction
landed, selector 373 is unchanged, and no Directional runtime executed; M1/M2/M3 remain unadjudicated.

Full eight-target GMP compile `33433309655 / 99623694545` is green. Package-only run `33433718709 / 99625035344` produced
mode-preserving package **73** artifact `9773591345`, inner tar `fc939abc4110f4a658d80932b395f59c9fd7cecbbcde7caac0ba7b6a41d1aca1`, with 27 package-relative fixtures and
six `0755` executables. AP6 carries into TB4 as a separate report-only 367–373 pass after the gate first-red verdict,
with zero gate credit.

### `M3-CP4c-3-TB4` — valid semantic red with exact transit locus; AP6 diagnostics measured

Artifact-only TB4 on immutable package **73** is authoritative at run/job `33436492493 / 99634138202`. Package/source/GMP/27-fixture/six-`0755`/selector preflight and immutable postflight passed. The semantic gate re-proved ordinals **1–365 = 365/365 PASS** and first-red at ordinal **366**. CB5's typed locus now identifies `VertexTransitSectorUnresolved` at source vertex **30**, arrival face `(24,30,32)`, branch **1**, region 0, `FaceInterior`, with exactly **two** candidate faces `(25,30,31)` and `(30,31,119)`, `BarrierAbsorbed=false`, `barrierIncident=false`. This falsifies M1's zero-candidate prediction and direct M3's barrier-absorbed-vertex prediction, but does not prove M2's singular-holonomy premise.

After the gate verdict was fixed, AP6 executed ordinals **367–373** once report-only with zero gate credit: **1 PASS / 6 RED**. 368 reproduces the sphere's `RotationSystemInconsistent → TraceEventPositionInvalid` at trace 2/event 30; 369 reaches its intended assertion with `saturationUsed=true`; 370 stops earlier at `atlasBuild=false`; 371/372 are blocked by the same mechanical network red; 373 passes its synthetic barrier-arc singularity-binding contract. Result/log artifacts are `9774693166` (`056f86df2e387391227bcf52f59ba932dd64a5d02923a8ff688cd8e315ff8a7e`) / `9774693946` (`d2acc62037d0bce07ef98bb77a7cb42ee90758d8b72477d9d8516da2fa0afcb6`). Stable accounting remains **44 / 14 / 30**, debt **5**, semantic packages **71**. Exact successor is independent `M3-CP4c-3-TB4-REV`; no unchanged TB retry or semantic correction precedes review.

### `M3-CP4c-3-CB6` — Amendment 17 one-datum election and package 74

CB6 implements the TB4-REV Amendment-17 correction at final semantic source
`49536cf7b4b261bd52f36a91c861b6459db356a4`: vertex continuation election captures one arrival-face incoming
direction, transports that same geometric datum through the reachable fan, re-expresses it per face, and applies
the unchanged exact half-open sector predicate. Candidate-cell `pairing.direction` values are retained only as
diagnostics; published signed-lift branch transport remains separate authority. The audit channel records both
directions, transport path, composed quarter-turn and sector outcomes per reachable state.

CB6 also exposes ordinal 370's existing typed atlas-build error/locus without repairing its witness and publishes
`NoCarrierMatch / SourceEdgeUnavailable` for the prescribed-sphere no-source-edge diagnostic path without changing
sphere semantics. An independent same-pattern audit found per-cell representative/sector testing in
`FieldTransportAtlas.cpp` singularity-port incidence construction; it was intentionally left untouched. Synthetic
ordinal 373 remains partial evidence until the mechanical witness proves `unboundSingularityCount=0`.

The first compile-only attempt found one mechanical C++ access defect (`DomainResult<SourceVertexId>`); the sole
correction was `rowVertex.value()`. Corrected GMP/GMPXX compile run/job `33445894845 / 99664857496` is green with
`runtimeExecution=false`; raw result/log artifacts are `9778128771` / `9778129236`. Mode-preserving package **74**
from `33446658075 / 99667201075` is artifact `9778267541`, outer SHA-256
`bad0ade74ff8e47c9937013c0fcc3f1084272c66eda35a2db60800ff7b6b767d`, inner tar
`c8d5167652ea95504252f5adb4d1dc5d9f463a4dfacfb7e5e11bd086fe935d8e`, source archive
`5afa250d0dd8e003b91e7e5f887e3eed8658f16faa6754722bf8a2dd37a1c931`, with 27 package-relative fixtures and
six `0755` executables. Selector 373 remains unchanged. Stable accounting remains **44 / 14 / 30**, debt **5**;
semantic packages advance **71 → 72**. Exact successor is artifact-only `M3-CP4c-3-TB5`.


### `M3-CP4c-3-TB6-REV` — Amendment 17 still violated; CB8 frozen

Independent review re-established package 75 / TB6 authority and corrected one durable evidence-ID error: the TB6
result artifact is **`9782227361`**, SHA-256
`e39fcab4ec71c951f9dd7505d052d73fbee7a4f2f66105ae6ff7a47dad672a87`. The semantic TB6 result is unchanged:
365/365 accepted prefix green, first red 366 at regular vertex 30, report-only 367–373 = 1 PASS / 6 RED.

Static reconstruction proves CB7 fixed the CB6 float round-trip but not Amendment 17. Atlas `signedLift` rotates the
branch label, after which the target face's `nextPairing->direction` is stored as `incomingDirection`; election is
therefore still one exact local representative per cell. Candidate faces row 41 and row 208 have disjoint branch-
vector families in the committed raw field, so their elected representatives are necessarily distinct under every
gauge permutation. The missing runtime rows are a separate projection defect: resolver
`FieldAlignedCurveNetworkError::vertexTransitStates` retains them, while `network_failure_locus` /
`SurfaceCellFailureLocusDiagnostics` drops them.

The CB7 minimal witness is adjudicated as an omitted future gate-authority action: selector 373 stays immutable;
CB8 must strengthen the same identity and append it as ordinal 374 in a new required-green selector. Repaired ordinal
370 is a genuine independent product red owned by `SurfaceCutGraph::canonical_candidate` and is deferred from CB8.
Sphere and saturation remain deferred. Stable accounting stays **44 / 14 / 30**, debt **5**, semantic packages
**73**. Exact successor: **`M3-CP4c-3-CB8`**, Code + Build only, runtime-free.

### `M3-CP4c-3-CB8` — architectural stop, unchanged source build-green

CB8 audited semantic source `0d943f95b42e49813060399e83a1e4180e8348f6` and triggered AW1 before semantic
editing. The atlas has exact face-local `FieldBranchBoundaryPairing::direction` values plus branch correspondence by
quarter-turn/`signedLift`, but no exact/certified transform for one arbitrary ray across a general non-coplanar fan.
`SourceChartTransitionGraph` is topological only; the available physical transport path is floating/tolerance-based.
No product/test/fixture/selector byte changed and selector 374 was not created. The unchanged source remained GMP
build-green in run `33467212874`, result/log artifacts `9785279716 / 9785279945`, `runtimeExecution=false`; no new
semantic package was produced. Exact successor was independent CB8-REV.

### `M3-CP4c-3-CB8-REV` — one ray frozen; deeper vertex-star definition required

Independent review upholds the stop and chooses the primitive datum: one exact arrival-anchored ray written once by
A2a branch continuation. A target face's branch representative is not a projection of that ray, and an upstream
owner does not eliminate the need to derive the owner exactly. The correct reference problem is an arrival-anchored
intrinsic development of the source-vertex fan. Current GMP rationals are not a general construction type for
non-coplanar hinge unfolding, while current source has no exact algebraic/direct predicate with certified fallback.
More fundamentally, the design has not defined what a developed gap or overlap means on a non-flat star. Amendment
21 therefore forces a definition step before implementation: those outcomes must become typed exact states, not
face order, tolerance, hidden seam, or invented topology.

Authority remains minimal: A1 owns branch topology; A2a will own one seed and one derived vertex-star
owner/non-owner certificate from A0 geometry + A1 topology. Mechanical vertex 30 remains the falsifier of the old
per-cell mechanism, but no exact owner is guessed before the geometry is frozen. `M3-CP4c3-TB6-CAND-01` remains
active downstream at the production DTO. Selector 373 stays byte-frozen; selector 374 is blocked until an exact
non-coplanar witness fails under `incomingDirection = nextPairing->direction`. Stable totals stay **44 / 14 / 30**,
debt **5**, semantic packages **73**. Exact successor: **`M3-CP4c-3-DEFN-R2`**, combined Definition + Review/Plan,
measures AX0–AX9 in `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md`.

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

### 6.3 Retired by the 2026-08-31 consolidation

`Architecture_M3_CP4c3_CB1_Code_Build_Report.md` is the only additional CP4c per-turn record that became
historical after the prior consolidation. Its durable AK1–AK3 outcome and measured successor evidence are already
preserved in §4 and the retained TB1/review authorities. The non-duplicated compile/package provenance retained from
CB1 is:

- instrumentation commit `014c7f7f8d6984518cf5c81156a10d3e06298349`; corrected semantic source
  `48dd011c4aa689a245b74527ed9df0900ada9bf3`;
- the first compile-only run `33338011871` failed because `FieldAtlasRegionCycleBasisDiagnostics` was
  default-constructed despite its non-default-constructible `TopologyRegionId`; the only correction was aggregate
  initialization with `region.id()`;
- authoritative compile/package run/job `33338642383 / 99330058374`, package **68**, artifact `9739919234`,
  package SHA-256 `127c7b086a8849de7f0c14928f2c5d762c3bf71711821d0a1fabfefda889d11c`, packaged source archive
  SHA-256 `f1fce7f720718c8ac974d0d5f77ca1fee4244b10c710d2b505a1af162e4f937f`, compile-log artifact
  `9739919468` SHA-256 `2074a5d2035dd84fe62ad424a8d95dfebe7af219f520f9f07e062af57ade21cd`, internal manifest
  **28/28 verified**;
- build used `DIRECTIONAL_ENABLE_GMP=ON`, linked both GMPXX and GMP, reported `exactArithmeticBackend=GMP`,
  and executed no compiled binary.

The CB1 report's exact bytes remain recoverable from Git history and no current/future authority depends on the file.

### 6.4 Retired by the 2026-09-03 user-authorized consolidation

The user explicitly requested consolidation of every `*_M3_CP4c_*` historical document that no longer relates to current or future work. A dependency-closure audit started from the current/frozen CP4c definitions and selectors plus `Future_Chat_Session_Handoff.md`, `TODO.md`, `ORIENTATION.md`, `DESIGN.md`, `REORIENTATION_PLAN.md`, `LESSONS.md`, `ROADMAP.md`, and `Regression_Root_Cause_Tracker.md`, then followed references transitively through retained CP4c authorities. **Only files outside that live dependency closure were retired.**

Retired Code + Build evidence/plans (15):
  - `Architecture_M3_CP4c3_CB10_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB11_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB12_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB13_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB14_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB15_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB16_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB2_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB3_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB5_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB6_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB7_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB8_Code_Build_Report.md`
  - `Architecture_M3_CP4c3_CB8_Independent_Review_Plan.md`
  - `Architecture_M3_CP4c3_CB9_Code_Build_Report.md`

Retired Test + Benchmark / review evidence (28):
  - `Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB10_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB11_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB11_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB12_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB13_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB13_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB14_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB14_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB1_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB2_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB3_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB3_Independent_Review_Record.md`
  - `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Record.md`
  - `Architecture_M3_CP4c3_TB5_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB5_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB6_Independent_Review_Plan.md`
  - `Architecture_M3_CP4c3_TB6_Independent_Review_Record.md`
  - `Architecture_M3_CP4c3_TB7_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB7_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB8_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB8_Artifact_Only_Test_Benchmark_Report.md`
  - `Architecture_M3_CP4c3_TB9_Artifact_Only_Test_Benchmark_Plan.md`
  - `Architecture_M3_CP4c3_TB9_Artifact_Only_Test_Benchmark_Report.md`

Their durable semantic, runtime, build/package, reversal, and selector-lineage facts are already deduplicated in §§4-5 and the durable `CHANGELOG.md`; exact historical bytes remain recoverable from Git history. No frozen definition, selector, then-current TB15 runtime evidence/review authority, CP4c-2 closure authority, or transitive dependency of a live durable document was removed.

### 6.5 Durable ORIENTATION authority

`ORIENTATION.md` is **DURABLE** and is not historical CP4c debris. Every REVIEW turn must update its currency line, current position, witness table when changed, open problems in priority order, and recurring-defect section when a new pattern or instance is found. It must not be deleted, renamed away, or collapsed into another document without explicit user authorization.

## 7. Resume pointer

After the durable start-of-turn checklist, load:

1. `ORIENTATION.md` — read first.
2. `Future_Chat_Session_Handoff.md`
3. `TODO.md`
4. `Architecture_M3_CP4c3_TB16_Independent_Review_Record.md` — **current review authority and the BR0–BR9 measures.**
5. `Architecture_M3_CP4c3_TB16_Artifact_Only_Test_Benchmark_Report.md`
6. `Architecture_M3_CP4c3_Required_Green_Selector_382.txt`
7. `Regression_Root_Cause_Tracker.md`
8. `tools/README.md` — the read-only review helpers; run `review_check.py authority <sha>` first every turn.
9. `src/geometry/GlobalTopologyPlan.cpp` (`build_fragment_corner_incidence` `:180`, `build_regions` `:409`),
   `src/geometry/SurfaceCellTracing.cpp` (`incomingCarrier.reset()` at `:2335`, `:2432`).
10. this consolidated record only when historical lineage is needed.

**Exact next:** **`M3-CP4c-3-CB19` — product correction, Code + Build, runtime-free, GMP/GMPXX linked.** Follow
**BR0–BR9** in `Architecture_M3_CP4c3_TB16_Independent_Review_Record.md` §8. Bind the carrier-less branch to the
segment's own entry support in **both** loops and keep it fail-closed; settle the terminal-slit contract once and
apply it in both; **re-derive** the fragment-count invariant rather than assume it; publish the full incidence at
the emitter; and **demonstrate** accepted-boundary safety with pinned before/after values across the torus,
two-ring and mechanical witnesses. Selector 382 keeps every byte; ordinal 383 only on demonstrated falsification.
Prohibited: importing CB18's datum fix without settling the terminal-slit contract, or scoping the repair to the
source-port branch alone. The prescribed sphere, ordinal 370, saturation, the folded-cone witness, vertex 30, the
finalize/contact fall-through and the 371/372 fixture coupling all remain deferred and separately owned.

---
## Folded document index — DURABLE, DO NOT DELETE
Consolidated on **2026-09-03** at `M3-CP4c-3-TB17-REV`. The 35 per-turn plans, reports and review records
listed below were folded into this record: their conclusions are carried by this file, by
`Regression_Root_Cause_Tracker.md` (candidate adjudications), by `LESSONS.md` (durable lessons) and by
`ORIENTATION.md` (recurring patterns and facts). **Their full text is retained in git history** — recover any
of them with `git log --diff-filter=D -- .agents/Directional/<name>` and `git show <sha>^:<path>`.

This index exists so that citations elsewhere still resolve. `CHANGELOG.md`, this record and
`Regression_Root_Cause_Tracker.md` cite these filenames as statements about past turns; those citations were
deliberately **not** rewritten, because they describe what a turn produced at the time. Look the name up here.

**Not folded, and still live authority:** every `Required_Green_Selector_*.txt`, the current `M3-CP4c-3-TB17`
report and review record, `M3_CP4c_Current_And_Forward.md`, and the normative definitions — which were
themselves consolidated on 2026-09-03 into `M3_CP4c_Frozen_Definitions.md`, carrying all six source documents
**verbatim** with a citation map from the former filenames.

| Folded document | Lines | Recorded verdict or title |
|---|---:|---|
| `Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md` | 330 | M3-CP4c-2 TB-X2-R10 Independent Review Record |
| `Architecture_M3_CP4c3_TB1_Independent_Review_Record.md` | 312 | M3-CP4c-3 TB1 Phase-1 Independent Review Record |
| `Architecture_M3_CP4c3_TB2_Independent_Review_Record.md` | 417 | M3-CP4c-3 TB2 Independent Review Record |
| `Architecture_M3_CP4c3_TB3_R1_Artifact_Only_Test_Benchmark_Report.md` | 100 | **COMPLETE / VALID SEMANTIC RED — FIRST RED AT ORDINAL 366** |
| `Architecture_M3_CP4c3_TB3_R1_Independent_Review_Plan.md` | 87 | **FROZEN NEXT-TURN PLAN / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB4_Artifact_Only_Test_Benchmark_Report.md` | 139 | **COMPLETE / VALID SEMANTIC RED — FIRST RED AT ORDINAL 366; AP6 DIAGNOSTIC PASS COMPLETE** |
| `Architecture_M3_CP4c3_TB4_Independent_Review_Plan.md` | 115 | **FROZEN NEXT-TURN PLAN / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB4_Independent_Review_Record.md` | 396 | M3-CP4c-3 TB4 Independent Review Record |
| `Architecture_M3_CP4c3_TB5_Independent_Review_Plan.md` | 89 | M3-CP4c-3-TB5 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB5_Independent_Review_Record.md` | 473 | M3-CP4c-3 TB5 Independent Review Record |
| `Architecture_M3_CP4c3_TB7_Independent_Review_Plan.md` | 122 | M3-CP4c-3-TB7 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB7_Independent_Review_Record.md` | 567 | M3-CP4c-3-TB7 — Independent Review + Plan Record |
| `Architecture_M3_CP4c3_CB8_Code_Build_Plan.md` | 204 | M3-CP4c-3-CB8 Code + Build Plan — Exact Single-Authority Vertex Transit |
| `Architecture_M3_CP4c3_CB8_Independent_Review_Record.md` | 305 | **COMPLETE / CB8 ARCHITECTURAL STOP UPHELD / DEEPER DEFINITION REQUIRED / NO SUCCESSOR CB AUTHORIZED** |
| `Architecture_M3_CP4c3_TB8_Independent_Review_Plan.md` | 123 | M3-CP4c-3-TB8 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB8_Independent_Review_Record.md` | 426 | TB8 is a **valid semantic red**. The ordinal-366 first red is classified **BA2 category 3 — |
| `Architecture_M3_CP4c3_TB9_Independent_Review_Plan.md` | 133 | M3-CP4c-3-TB9 Independent Review + Plan — Frozen Scope |
| `Architecture_M3_CP4c3_TB9_Independent_Review_Record.md` | 441 | TB9 is a **valid semantic red**. Ordinal 366 is classified **BC2 category 1 — a genuine product |
| `Architecture_M3_CP4c3_TB10_Independent_Review_Plan.md` | 123 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` | 388 | M3-CP4c-3-TB10 — Independent Review + Plan Record |
| `Architecture_M3_CP4c3_TB11_Independent_Review_Plan.md` | 72 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB11_Independent_Review_Record.md` | 404 | TB11 is a **valid semantic red**. The ordinal-366 collision is **not adjudicable from the retained |
| `Architecture_M3_CP4c3_TB12_Independent_Review_Plan.md` | 112 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB12_Independent_Review_Record.md` | 344 | TB12 is a **valid semantic red**, and the root cause is now **proved**: BI2 alternative **2** — two |
| `Architecture_M3_CP4c3_TB13_Independent_Review_Plan.md` | 119 | **FROZEN SUCCESSOR / REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB13_Independent_Review_Record.md` | 371 | TB13 is a **valid semantic red**, and the condition TB13 called underdetermined is **determined here |
| `Architecture_M3_CP4c3_TB14_Independent_Review_Plan.md` | 134 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB14_Independent_Review_Record.md` | 335 | TB14 is a **valid semantic red**. CB16's correction worked and pushed the rotation past **every vertex |
| `Architecture_M3_CP4c3_TB15_Artifact_Only_Test_Benchmark_Report.md` | 103 | **COMPLETE / VALID SEMANTIC RED / BRANCH DISCRIMINATED / NON-STABLE** |
| `Architecture_M3_CP4c3_TB15_Independent_Review_Plan.md` | 96 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB15_Independent_Review_Record.md` | 355 | TB15 is a **valid semantic red** and CB17's diagnostics resolve it. The incidence is **valid**; the |
| `Architecture_M3_CP4c3_TB16_Artifact_Only_Test_Benchmark_Report.md` | 98 | **COMPLETE / VALID SEMANTIC RED / ACCEPTED PREFIX SAFE / V47 RE-PROVED / NON-STABLE** |
| `Architecture_M3_CP4c3_TB16_Independent_Review_Plan.md` | 66 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |
| `Architecture_M3_CP4c3_TB16_Independent_Review_Record.md` | 364 | M3-CP4c-3-TB16 — Independent Review + Plan Record |
| `Architecture_M3_CP4c3_TB17_Independent_Review_Plan.md` | 67 | **FROZEN SUCCESSOR / INDEPENDENT REVIEW + PLAN ONLY / NOT EXECUTED** |

**Total folded:** 35 documents, 8330 lines.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB18-REV`

The first application of the standing REVIEW-turn consolidation rule
(`CLEAN_UP_POLICY.md` §"Document consolidation — every REVIEW turn", user-authorized 2026-09-03). Each document's
durable facts were verified present in `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB17_Artifact_Only_Test_Benchmark_Report.md` | 94 | superseded runtime authority - TB17 375/8 red at selector 382; facts carried by the TB18 report |
| `Architecture_M3_CP4c3_TB17_Independent_Review_Record.md` | 340 | superseded review authority - BRQ0-BRQ8; falsified the fragment equality, named the owner class, froze CB20/BS0-BS9 |
| `Architecture_M3_CP4c3_CB20_Code_Build_Report.md` | 80 | consumed build report - **COMPLETE / DIAGNOSTIC-ONLY / COMPILE GREEN**; BS0-BS9 disposition carried by the TB18-REV record |
| `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Plan.md` | 101 | consumed evidence contract - the six BS9 discriminators; their dispositions carried by the TB18 report and the TB18-REV record |

**Total folded this turn:** 4 documents, 615 lines. **Running total:** 39 documents, 8945 lines.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB19-REV`

Second application of the standing REVIEW-turn consolidation rule. Each document's durable facts were verified
present in `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB18_Artifact_Only_Test_Benchmark_Report.md` | 148 | superseded runtime authority - TB18 375/8 at selector 383; superseded by the TB19 report |
| `Architecture_M3_CP4c3_TB18_Independent_Review_Record.md` | 366 | superseded review authority - BT0-BT9; falsified the fragment equality, proved shared ownership legitimate, froze CB21/BU0-BU9, retired BS9-5 |
| `Architecture_M3_CP4c3_CB21_Code_Build_Report.md` | 173 | consumed build report - the one-sided fragment-owner correction; BU0-BU9 disposition confirmed by TB19 and carried by the TB19-REV record |
| `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Plan.md` | 191 | consumed evidence contract - discriminators D1-D6; dispositions carried by the TB19 report |
| `Architecture_M3_CP4c3_TB19_Independent_Review_Plan.md` | 112 | consumed binding review plan - measures CR0-CR8, all discharged in the TB19-REV record |

**Total folded this turn:** 5 documents, 990 lines. **Running total:** 44 documents, 9935 lines.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB20-REV`

Third application of the standing REVIEW-turn consolidation rule. Each document's durable facts were verified
present in `Architecture_M3_CP4c3_TB20_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB19_Independent_Review_Record.md` | 337 | superseded review authority - CR0-CR8; proved the frontier locus an iteration artifact, kept the torus case separate, froze CB22/BV0-BV9 |
| `Architecture_M3_CP4c3_TB20_Independent_Review_Plan.md` | 131 | consumed binding review plan - measures CW0-CW9, all discharged in the TB20-REV record |

| `Architecture_M3_CP4c3_TB19_Artifact_Only_Test_Benchmark_Report.md` | 215 | superseded runtime authority - TB19 376/8 at selector 384; **retired by `M3-CP4c-3-TB20`'s stale-evidence cleanup (`ce9e6ad5`), indexed here at TB20-REV** |
| `Architecture_M3_CP4c3_CB22_Code_Build_Report.md` | 135 | consumed build report - the seed-state discriminator and component census; **retired by `M3-CP4c-3-TB20`'s stale-evidence cleanup (`ce9e6ad5`), indexed here at TB20-REV** |

**Total folded this turn:** 4 documents, 818 lines — 2 folded by this review, plus 2 that `M3-CP4c-3-TB20`'s
stale-evidence cleanup had already retired without an index entry. **Running total:** 48 documents, 10753 lines.

*A Code + Build or Test + Benchmark turn's stale-evidence cleanup does not write this index; the next REVIEW turn
indexes anything it retired, so a filename retired between reviews still resolves here.*

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB28-INDEPENDENT-REVIEW`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB28_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` | 319 | superseded review authority - CL0-CL9. Recorded the refutation of its own predecessor's all-bridges prediction, confirmed the partition mismatch, and set the **CL8 hard stop rule**, which is **discharged** by §4 of the TB28 review record |
| `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` | 172 | consumed build report - CK8/CK9 serialization and partition identity; superseded as package authority by CB32 |

**Folded here:** 2 documents, 491 lines.

**Retained deliberately, and not as "superseded":**
`Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md` is **the current valid semantic runtime
authority**, because `M3-CP4c-3-TB28-R2` was rejected as orchestration-invalid. It must not be folded until a valid
successor runtime exists. `Architecture_M3_CP4c3_TB28_R2_Artifact_Only_Test_Benchmark_Report.md` is retained as
**invalid-attempt provenance** and `Architecture_M3_CP4c3_TB28_Artifact_Only_Test_Benchmark_Plan.md` as the frozen
contract TB28-R3 re-executes; `Architecture_M3_CP4c3_CB32_Code_Build_Report.md` is the package under test.

**Also retained as current authority:** `Architecture_M3_CP4c3_TB28_Independent_Review_Record.md` (this review, the
frozen correction and the CB33/TB28-R3/CB34 sequence), `M3_CP4c_Current_And_Forward.md`,
`M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every
`Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-05 at `M3-CP4c-3-TB27-INDEPENDENT-REVIEW`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB27_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` | 343 | superseded review authority - CK0-CK9. Its two load-bearing claims are **runtime-confirmed** (an incidence count is not a separation; the census described a different object). Its §1.2 static all-bridges prediction is **refuted** - arcs 14 and 22 separate |
| `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md` | 93 | superseded runtime authority - TB26-R1, 397 PASS / 8 RED on selector 405, accepted 365/365; the ledger the CK measures were frozen against |
| `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md` | 220 | superseded runtime authority - TB25-R1, 393 PASS / 10 RED on selector 403; retained one turn longer as the `established=74 / unavailable=226` baseline, now carried by the TB27 review record and this index |

**Folded here:** 3 documents, 656 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB27_R1_Artifact_Only_Test_Benchmark_Report.md`
(**authoritative semantic runtime**), `Architecture_M3_CP4c3_CB31_Code_Build_Report.md` (the package under review),
`Architecture_M3_CP4c3_TB27_Independent_Review_Record.md` (this review and the frozen CB32 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB26-INDEPENDENT-REVIEW`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB26_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` | 344 | superseded review authority - CJ0-CJ9; diagnosed the starved seed rule, closed `M3-CP4c3-TB21-CAND-01` as ill-formed, and froze CB30. CJ7/CJ8/CJ9 are runtime-proved at TB26-R1; **CJ6's censuses are superseded as inadmissible about the failing component** - they are computed on the certifier's partition |
| `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` | 96 | consumed build report - publication survives ownership failure, `proves_embedded_cellularity()` introduced, conflict census added; superseded as package authority by CB30 |
| `Architecture_M3_CP4c3_TB26_Independent_Review_Intake.md` | 36 | consumed task brief - the seven mandatory review questions and stop rules for this review; its first premise (that `interiorArcs=4` selects the separating-arc horn) was **declined with reasons** in §1 of the review record |

**Folded here:** 3 documents, 476 lines.

**Noted:** `M3-CP4c-3-CB30` has no retained standalone Code + Build report. Its package authority
(`9957324848`) is carried by the TB26-R1 report and the CHANGELOG. A successor CB should restore the per-turn build
report so the package under test has a first-class provenance document.

**Retained as current authority:** `Architecture_M3_CP4c3_TB26_R1_Artifact_Only_Test_Benchmark_Report.md`
(**authoritative semantic runtime and current package provenance**),
`Architecture_M3_CP4c3_TB26_Independent_Review_Record.md` (this review and the frozen CB31 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB25-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB25_Independent_Review_Record.md`,
`Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md` **before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` | 370 | superseded review authority - CH0-CH9; found the ordering defect behind seven REDs, withdrew DEFN-R3.1's publication-not-computation clause, and froze CB28. CH6/CH7 are runtime-proved at TB25-R1 (384/385 recovered); **CH8's conflict census is superseded as vacuous** - it reads only established owners |
| `Architecture_M3_CP4c3_CB27_Code_Build_Report.md` | 128 | consumed build report - published the owner map, fixed ordinal 397, replaced 393 in place, made fixture resolution fail closed; superseded as package authority by CB28 |

**Indexed retrospectively under clause 3**, having been retired by `M3-CP4c-3-TB25-R1`'s stale-evidence cleanup
between reviews:

| Retired document | Verdict it carried |
|---|---|
| `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` | superseded runtime authority - TB24, 389 PASS / 12 RED on selector 401, accepted 365/365; the ledger TB24-REV adjudicated |
| `Architecture_M3_CP4c3_TB25_Artifact_Only_Test_Benchmark_Plan.md` | consumed evidence contract - the frozen TB25 execution boundary and its four-branch interpretation contract, preserved verbatim in the TB25-R1 report and applied by TB25-REV |
| `Architecture_M3_CP4c3_CB29_Code_Build_Report.md` | consumed control-only report - the pre-runtime harness correction after TB25's selector-injection failure; runtime-proved by TB25-R1 and closed as `M3-CP4c3-TB25-ORCH-01` |

**Folded here:** 2 documents, 498 lines, plus 3 retrospectively indexed.

**Retained as current authority:** `Architecture_M3_CP4c3_TB25_R1_Artifact_Only_Test_Benchmark_Report.md`
(**authoritative semantic runtime**), `Architecture_M3_CP4c3_CB28_Code_Build_Report.md` (the package under review),
`Architecture_M3_CP4c3_TB25_Independent_Review_Record.md` (this review and the frozen CB30 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB24-REV`

Mandatory REVIEW consolidation. Durable facts were verified present in
`Architecture_M3_CP4c3_TB24_Independent_Review_Record.md`, `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md`,
`Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`, `M3_CP4c_Current_And_Forward.md` and `CHANGELOG.md`
**before** any file was folded.

| Folded document | Lines | Verdict it carried |
|---|---|---|
| `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` | 213 | superseded runtime authority - TB23-R1, 389 PASS / 8 RED on selector 397, accepted 365/365; the corrected execution view that proved CB26's harness fix. Superseded by TB24 on selector 401 |
| `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` | 269 | superseded review authority - CE0-CE8; confirmed the harness fix, proved certified ownership absent from the published contract, and froze DEFN-R3, which DEFN-R3 discharged |
| `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Plan.md` | 131 | consumed evidence contract - the frozen TB24 execution boundary and discriminators D1-D6; fully executed and reported by TB24-EXEC, adjudicated by this review |

**Folded here:** 3 documents, 613 lines. Every durable fact each carried is retained above, in the TB24 review
record, or in the tracker.

**Retained as current authority:** `Architecture_M3_CP4c3_TB24_Artifact_Only_Test_Benchmark_Report.md` (**authoritative
semantic runtime**), `Architecture_M3_CP4c3_CB27_Code_Build_Report.md` (the package under review),
`Architecture_M3_CP4c3_TB24_Independent_Review_Record.md` (this review and the frozen CB28 scope),
`M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this
record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB23-R1-REV`

Seventh application of the standing REVIEW-turn consolidation rule, including retrospective indexing of the **five**
per-turn files `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup retired between reviews. Durable facts were verified
present in `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`,
`ORIENTATION.md`, `LESSONS.md` and `CHANGELOG.md` before folding.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` | 264 | superseded review authority - CC0-CC8; upheld the orchestration-invalid classification, located the harness defect and froze CB26/CD0-CD8, which CB26 discharged (folded by this review) |
| `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` | 112 | superseded runtime authority - TB22 387/6 at selector 393. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_CB25_Code_Build_Report.md` | 115 | consumed build report - the certificate-face diagnostics; CA1 partially met, CA2 met, CA3 satisfiable. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_CB26_Code_Build_Report.md` | 111 | consumed build report - the control-plane orchestration correction; confirmed at TB23-R1. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` | 200 | consumed evidence contract - re-executed by TB23-R1. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |
| `Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` | 100 | invalid-attempt provenance - orchestration-invalid, no semantic ledger. **Retired by `M3-CP4c-3-TB23-R1`'s stale-evidence cleanup, indexed here at TB23-R1-REV** |

**Total folded this turn:** 6 documents, 902 lines — 1 folded by this review, plus 5 retired by
`M3-CP4c-3-TB23-R1` without an index entry. **Running total:** 80 documents, 16117 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB23_R1_Artifact_Only_Test_Benchmark_Report.md` (runtime), `Architecture_M3_CP4c3_TB23_R1_Independent_Review_Record.md` (review and the frozen DEFN-R3 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB23-REV`

Sixth application of the standing REVIEW-turn consolidation rule. **No document was retired between reviews**, so
nothing needed retrospective indexing. Only one document was superseded — consolidation is not a quota, and the
TB22 report, the CB25 build report, the frozen TB23 plan and the TB23-EXEC report are all **retained** because each
remains live authority for the orchestration correction and its re-execution.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` | 326 | superseded review authority - BZ0-BZ8; proved both CB24 measurements vacuous and froze CB25/CA0-CA9, which CB25 statically discharged |

**Total folded this turn:** 1 document, 326 lines. **Running total:** 58 documents, 12481 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` (**authoritative semantic runtime**), `Architecture_M3_CP4c3_CB25_Code_Build_Report.md` (the package under re-execution), `Architecture_M3_CP4c3_TB23_Artifact_Only_Test_Benchmark_Plan.md` (the frozen plan), `Architecture_M3_CP4c3_TB23_EXEC_Artifact_Only_Test_Benchmark_Report.md` (invalid-attempt provenance), `Architecture_M3_CP4c3_TB23_Independent_Review_Record.md` (this review and the frozen CB26 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-04 at `M3-CP4c-3-TB22-REV`

Fifth application of the standing REVIEW-turn consolidation rule, including retrospective indexing of documents a
CB or TB turn retired between reviews. Durable facts verified present in
`Architecture_M3_CP4c3_TB22_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`LESSONS.md` and `CHANGELOG.md` **before** folding.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` | 330 | superseded review authority - BX0-BX8; withdrew the non-cellularity conclusion and froze CB24/BY0-BY9, whose BY3/BY4 wording TB22-REV found underspecified |
| `Architecture_M3_CP4c3_TB22_Independent_Review_Plan.md` | 80 | consumed binding review plan - measures BZ0-BZ8, all discharged in the TB22-REV record |
| `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` | 142 | superseded runtime authority - TB21 384/7 at selector 391. **Retired by `M3-CP4c-3-TB22`'s stale-evidence cleanup (`4207907c`), indexed here at TB22-REV** |
| `Architecture_M3_CP4c3_CB24_Code_Build_Report.md` | 88 | consumed build report - the projection diagnostics; **TB22-REV proved both of its measurements vacuous**. Retired by `M3-CP4c-3-TB22`'s stale-evidence cleanup (`4207907c`), indexed here at TB22-REV |

**Total folded this turn:** 4 documents, 640 lines — 2 folded by this review, plus 2 retired by
`M3-CP4c-3-TB22` without an index entry. **Running total:** 57 documents, 12155 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB22_Artifact_Only_Test_Benchmark_Report.md` (runtime), `Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` (review and the frozen CB25 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.

### Consolidated on 2026-09-03 at `M3-CP4c-3-TB21-REV`

Fourth application of the standing REVIEW-turn consolidation rule, including the retrospective indexing of
documents a CB or TB turn retired between reviews. Each document's durable facts were verified present in
`Architecture_M3_CP4c3_TB21_Independent_Review_Record.md`, `Regression_Root_Cause_Tracker.md`, `ORIENTATION.md`,
`LESSONS.md` and `CHANGELOG.md` **before** it was folded.

| Folded document | Lines | Recorded verdict or role |
|---|---:|---|
| `Architecture_M3_CP4c3_TB20_Artifact_Only_Test_Benchmark_Report.md` | 160 | superseded runtime authority - TB20 380/8 at the 388-identity selector; superseded by the TB21 report |
| `Architecture_M3_CP4c3_TB20_Independent_Review_Record.md` | 336 | superseded review authority - CW0-CW9; measured the Multiple branch, authorized the 371/372 decoupling, and reached a non-cellularity conclusion **withdrawn at TB21-REV** |
| `Architecture_M3_CP4c3_TB21_Independent_Review_Plan.md` | 89 | consumed binding review plan - measures BX0-BX8, all discharged in the TB21-REV record |
| `Architecture_M3_CP4c3_CB23_Code_Build_Report.md` | 88 | consumed build report - the Euler census diagnostics; BW0-BW9 confirmed by TB21. **Retired by `M3-CP4c-3-TB21`'s stale-evidence cleanup (`8396f23c0`), indexed here at TB21-REV** |
| `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Plan.md` | 89 | consumed evidence contract - discriminators D1-D6; dispositions carried by the TB21 report. **Retired by `M3-CP4c-3-TB21`'s stale-evidence cleanup (`8396f23c0`), indexed here at TB21-REV** |

**Total folded this turn:** 5 documents, 762 lines — 3 folded by this review, plus 2 retired by
`M3-CP4c-3-TB21` without an index entry. **Running total:** 53 documents, 11515 lines.

**Retained as current authority:** `Architecture_M3_CP4c3_TB21_Artifact_Only_Test_Benchmark_Report.md` (runtime), `Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` (review and the frozen CB24 scope), `M3_CP4c_Current_And_Forward.md`, `M3_CP4c_Frozen_Definitions.md`, `Required_Green_Selector_Manifest.md`, this record, and every `Required_Green_Selector_*.txt`.


# M3 CP4c — Consolidated Historical Record

**Purpose.** Durable, deduplicated history for the `M3-CP4c` family. Completed/superseded CP4c documents are consolidated here; only documents that remain normative, current evidence, or future-work inputs stay separate. For execution authority use `Future_Chat_Session_Handoff.md` and `TODO.md`.

**Current state (2026-08-30).** `M3-CP4c-0`, `M3-CP4c-0b`, and `M3-CP4c-1` are **CLOSED / ACCEPTED**. `M3-CP4c-2` is **OPEN / runtime-unaccepted**. R9-EXEC re-proved 355/355, passed 356-362, and hard-stopped at 363 with the first genuine product defect in this arc. R9-REV identified two stale Amendment-14 A2b consumers. **CB9 now corrects both and is BUILD GREEN / runtime-free** on semantic source `57444781af7bdc460e38cc68930a9a8c8199eeea` and immutable package **67**, artifact `9736088354` / `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`. The correction iterates all Cut sub-arcs, uses actual sub-arc endpoint `NodeLocus` authority for `boundaryVertices`, publishes AI2 fragment/orbit diagnostics, and fixes helper fall-through without widening the frozen representation or selector. Exact next is **`M3-CP4c-2-TB-X2-R10-EXEC`** on that immutable package; CP4c-3 remains blocked.

Stable accounting: **44 / 14 / 30**, produced-witness debt **5**, M3 packages **67**. `selected_r2_branch=NONE`; `selected_gate=NONE`; `gate_execution_authorized=false` at CB9 closeout.

## 1. Current separate authority

These files remain separate because they are still required by current or future work:

- `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` — still-binding base contract and Amendment 12; read with R1/R2.
- `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` — Amendment 13 and still-binding §§4/5/7/9; §6 case 2 and §8 are superseded by R2.
- `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md` — Amendment 14, completeness theorem, AF5 and AG0–AG9.
- `Architecture_M3_CP4c2_Required_Green_Selector_357.txt` and `_358.txt` — retained because current DEFN-R2 explicitly uses their frozen lineage/prefix authority; 357 is superseded and 358 withdrawn, neither is executable gate authority.
- `Architecture_M3_CP4c2_Required_Green_Selector_361.txt` — frozen prefix authority retained for lineage.
- `Architecture_M3_CP4c2_Required_Green_Selector_365.txt` — current CP4c-2 required-green authority; R9 executed through first red at ordinal 363.
- `Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt` — current report-only TB surface.
- `Architecture_M3_CP4c2_CB9_Code_Build_Report.md` — current immutable build/package 67 authority.
- `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Plan.md` — current frozen artifact-only execution plan.
- `Architecture_M3_CP4c2_CB8_Code_Build_Report.md` — retained predecessor package 66 authority.
- `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Plan.md` — retained predecessor executed plan.
- `Architecture_M3_CP4c2_CB7_Code_Build_Report.md` — retained predecessor Amendment-14 build authority.
- `Architecture_M3_CP4c2_CB5_Code_Build_Report.md` — retained predecessor package authority for R7 lineage.
- `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Report.md` — latest current runtime evidence; valid red at ordinal 363.
- `Architecture_M3_CP4c2_TB_X2_R8_Artifact_Only_Test_Benchmark_Report.md` — retained predecessor runtime evidence.
- `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md` — retained predecessor runtime lineage.
- `Architecture_M3_CP4c2_CB6_Code_Build_Report.md` — immediate AF1 definition-stop predecessor.

The authoritative architecture is also carried by `DESIGN.md` §7.2/§7.2.1; regression/status facts remain in `Regression_Root_Cause_Tracker.md`, `CHANGELOG.md`, `LESSONS.md`, and `ORIENTATION.md`.

## 2. Closed checkpoint record

| Checkpoint | Closed responsibility | Accepted result |
|---|---|---|
| **CP4c-0** | exact resolved continuation and grazing | **346/346 CLOSED** |
| **CP4c-0b** | exact crash-on-contact termination / arrival | **353/353 CLOSED** |
| **CP4c-1** | observability, diagnosability, non-vacuous terminal events | **355/355 CLOSED** |
| **CP4c-2** | closed/higher-genus region authority, cut graph, cellularity | active; inherited **355/355** re-proof green |
| **CP4c-3** | mechanical witness / missing field-transport adjacency | blocked |

### CP4c-0

Continuation requires exact entry position plus barycentric direction. Branch labels are face-gauge-local; cross-face semantics use published transport/lift. Grazing is exact `Inflow/Tangent/Outflow`; edge transit is used when both adjacent faces drive along the carrier; no tolerance decides topology.

### CP4c-0b

The initial termination theory was withdrawn. The accepted S0–S8 contract is exact crash-on-contact with fixed arrival priority and canonical tie handling; arithmetic guards are backstops, not semantic policy.

Accepted authority: source `93059089881c8715a168a61968a8d6874ee1a670`, GMP package `9671190795`, package SHA-256 `2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`, T5 run/job `33136084757 / 98736295227`, selector **353** SHA-256 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, final **353/353 PASS**. Non-gating U3/U4 census was **4/4 PASS** with zero gate credit. The prescribed sphere publishes 24 traces.

### CP4c-1

C4/C5 closed the diagnosability and event-non-vacuity surface: tampered trace-intersection crossing data is rejected; every produced trace ends at exactly one actually produced typed terminal event; required terminal kinds are non-vacuously represented without forbidding lawful frozen kinds.

Accepted authority: source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`, GMP package `9675666067`, package SHA-256 `63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`, TB-R5 run/job `33161644741 / 98817323175`, selector **355** SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, final **355/355 PASS**. Observed terminal-kind union was exactly `{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}`. The torus lawfully contributes zero trace/event kinds; the mechanical witness remains outside CP4c-1 reach at `IncompleteCycleBasis`.

## 3. CP4c-2 durable history

### 3.0 R9 execution — first Amendment-14 gate red

Authoritative artifact-only run/job `33319911575 / 99279955697` consumed CB8 package `9726295440`, passed immutable
preflight, ran three non-gating diagnostics, re-proved accepted 355/355, passed 356-362, and first-red hard-stopped at
363 with `InvalidCutGraphBinding`. Static localization on the immutable packaged source shows the new crossing authority
splits a selected trace-crossed source edge into multiple Cut arcs, while region binding still requires exactly one
Cut arc per selected source edge. This is `R9-CAND-01`, non-stable because CP4c-2 is unaccepted and predecessor 355
remains green. **R9-REV** confirmed the producer correct line by line — exact `ExactUnitParameter` ordering,
coincident crossings rejected not merged, every sub-arc in the canonical `first()→second()` direction — and found a
**second stale consumer EXEC did not reach**: `GlobalTopologyPlan.cpp:1239-1242` over-inserts whole-source-edge
endpoints into the `boundaryVertices` **skip list**, suppressing the interior-vertex ownership check with no error.
R8-CAND-01 is **closed** by 359/361 green; measure `AD3` is **resolved** and criterion **C3** is **green**. AH6 did
not apply because 363-365 were not all reached. Result/log artifacts `9734625006 / 9734625165`;
all mutation/build/benchmark flags false; postflight PASS.

### 3.0a CB9 — convert both stale Cut-sub-arc consumers

R9-REV authorized AI0-AI9. CB9 first re-derived every product reader of `arc.cutEdge`, `GlobalTopologyArcKind::Cut`, and `cut_edges()` rather than trusting the review table. Exactly two consumers were stale: region binding required one Cut arc per source cut edge, and region-certificate `boundaryVertices` inserted both whole-source-edge endpoints for each sub-arc. No other consumer required a representation change.

Semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` converts region binding to iterate all derived Cut sub-arcs while preserving the canonical `cutEdge.first()→cutEdge.second()` orientation dependency and the existing interior-dart formula. It reuses one `NodeLocus` map so only actual source-vertex endpoints of each boundary sub-arc enter the skip list, and it publishes per-face `fragment_reconciliation` plus per-face/cut-edge orbit-cardinality diagnostics under `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1`. The ordinal-359 semantic-digest rationale is annotated with its runtime falsifier and the two helper fall-throughs are stopped. No selector, sphere, crossing producer, enum, invariant, or benchmark scope changed.

Compile-only run `33325344311`: changed-owner prepackage job `99294371782` compiled producer tests 105/105; package job `99294619815` compiled the eight standard targets with GMP/GMPXX and `runtimeExecution=false`. Immutable package 67 is artifact `9736088354`, SHA-256 `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`, packaged source archive `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`, manifest 28/28 PASS. Runtime is intentionally unadjudicated until R10.


### 3.1 Why A2a′ exists

The torus proved the network alone need not be a cut graph: measured `V=48`, `E=48`, `chi=0`; a cellular embedding would require `F=0`. CP4c-2 therefore inserted pre-region `SurfaceCutGraph` (A2a′), preserving the prohibition on post-region repair/re-cut.

Amendment 12 narrowed the stop condition correctly: establishing a cellularity precondition before A2b derives regions is permitted; repairing/re-cutting a derived `GlobalTopologyPlan` region remains forbidden.

### 3.2 Representation correction — Amendment 13

R5 falsified the whole-source-face/source-edge-barrier partition as cellularity authority. The accepted two-ring showed the actual embedded graph and barrier proxy can each be internally self-consistent while the producer mixes them and certifies the wrong object.

Amendment 13 makes the **actual embedded graph of `FieldAlignedCurveNetwork ∪ cutEdges`** normative. Graph/cut nodes are vertices, graph/cut arcs are edges, and dart orbits under the node rotation system are faces. Source-edge barriers remain proposal/diagnostic provenance only. CB4 compiled shared `EmbeddedGraphTopology.{h,cpp}` at `cebc12082c6dbe4830095df08169797b7dab0c5c`, package `9714226920`.

The still-binding conventions live in DEFN-R1 §§4/5/7/9: one shared arc/dart/rotation/orbit authority, explicit boundary-orbit handling, corrected disconnected-graph Euler accounting, exact node/edge counting, certificates over the actual complex only, and an independent oracle that reconstructs the same semantic object without calling the producer.

### 3.3 Semantic/provenance split and R7 re-proof

R6 exposed representation-dependent semantic identity. `candidate_hash` retains gauge-dependent `atlasDigest` for provenance/tamper rejection, while semantic identity excludes it. CB5 source `755485865a7cf9c485d754f22b82a41ee151824b` produced immutable package `9719216316` (`sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`).

The first R7 attempt stopped before runtime because prose contained fabricated abbreviated selector hashes. DOC-R1 established the durable rule: selector authority is the committed bytes and hashes are always recomputed as full 64-lowercase-hex values. Corrected R7 run/job `33276039911 / 99162853852` passed immutable pre/postflight and **355/355**, closing `PR8-R043 / M3-CP4c2-R001`, `PR8-R044 / M3-CP4c2-R002`, and `M3-CP4c2-TB-X2-R7-ORCH-01`.

### 3.4 Sphere re-localization and CB6 definition stop

`SurfaceCutGraph::topology_error` collapses 36 upstream `GlobalTopologyPlanErrorCode` values into `CellularityNotEstablished`; therefore the sphere producer's code was not itself a cellularity verdict.

CB6 then obeyed AF1 before implementation/compile and read retained artifact `9721564203`. The independent actual-graph oracle reported:

`V=18, E=30, F=18, c=1, chi=6, sourceChi=2, excludedBoundaryOrbits=0`, `complex=actualEmbeddedGraph`, `surfaceCutGraphCallsInsideOracle=0`.

Thus the prescribed sphere is genuinely **non-cellular pre-cut** (`6 != 2`) while the producer also fails earlier through lossy error translation. DEFN-R1's trace-crossed completeness gap became live, so CB6 stopped before AF0/AF2/AF3/AF4 implementation and before compile/package/runtime.

### 3.5 Amendment 14 and current gate

DEFN-R2 proves the prior exclusion of trace-crossed source edges was based on a false representation premise. `build_arcs` already emits one trace arc per event; crossing points are published exactly at segment boundaries; subdivision occurs only in the derived arrangement, not in the immutable network.

Amendment 14 therefore admits every source edge not already a graph arc as a cut. Edge-interior crossing nodes are arrangement-local synthetic nodes, crossing order is exact along canonical source-edge orientation, and trace arcs are subdivided at the published crossing positions.

Completeness is now proved: `network ∪ source 1-skeleton` is cellular because open source triangles are discs and embedded trace sub-arcs only cut discs into discs. A sufficient cut set always exists within `|E_source|` source-edge promotions. `NoAdmissibleCutForNonDiscComponent` is retired in favor of explicit search exhaustion plus a published saturation last resort; DEFN-R1 Option B is withdrawn.

The concrete code gap is the edge-locus rotation: `build_rotation_system` currently handles `Mandatory` rays only at degree three and otherwise expects `Trace`; a crossing node has two collinear `Cut` rays plus two `Trace` rays. The existing four-sector model must be generalized, not duplicated.

Current gate authority is selector **361**, whole-file SHA-256 `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`. Its first 355 and first 357 entries reproduce the accepted-355 and candidate-357 authorities so `first_red_ordinal` remains comparable. 357 is superseded; 358 is withdrawn because its sole addition bound the out-of-scope mechanical witness. No gate is selected or executable yet.


### 3.6 CB7 implementation and package

CB7 semantic source `4f0f3ca74a88ba260a20c019437bc4995f2056e0` implements trace-crossed cut nodes,
exact crossing ordering, cut/trace arc subdivision, generalized edge-locus rotation, explicit search exhaustion and
published saturation, additive originating-error provenance, production-authority torus diagnostics, the repaired
withdrawn-barrier diagnostic, and an independent crossing oracle. A purpose-built three-ring witness asserts that a
trace-crossed cut is actually selected before exercising the two-Cut/two-Trace degree-four rotation.

Selector **365** appends the four DEFN-R2 identities to 361. Its whole-file SHA-256 is
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`; its 355/357/361 prefixes reproduce the
frozen authorities exactly.

GitLab load failures prevented the first compile checkout. The successful package used transport-only source
`1230621baff6d04fb20df3b1bf48903cd65b5d69`, substituting the verified GitHub Eigen mirror at the same exact gitlink
while changing no semantic path. Run/job `33287281975 / 99192562149` compiled all eight standard targets with
GMP/GMPXX and `runtimeExecution=false`. Immutable package artifact `9724864897` has SHA-256
`a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`. The canonical Eigen remote was restored
after packaging. Runtime behavior remains unadjudicated until R8.

## 4. Runtime evidence owed by R10

R10-EXEC must consume immutable package 67 without rebuild/repair, re-prove accepted 355/355, then execute 356-365 in frozen order with the first-semantic-red hard stop. Ordinal 363 must publish AI2 fragment-reconciliation and cut-edge-orbit evidence in its single gate process; if 363-365 are all reached, AH6 must distinguish ordinary tree-cotree selection from saturation. Three frozen non-gating diagnostics remain report-only. R10-REV, not EXEC, owns candidate/regression disposition and CP4c-2 acceptance planning. No benchmark is authorized.

## 5. High-value reversals retained

- Face-local branch labels are not cross-face semantic identity; use published transport/lift.
- Tangency is a ratio, not excluded by large direction magnitude.
- Source-edge-barrier partitions are not cellularity authority; actual embedded graph is normative.
- Self-consistent arithmetic can certify the wrong semantic object.
- Accepted-prefix red is a detection boundary, not proof the latest change caused the defect.
- Semantic and provenance digests are distinct authorities.
- Unexecuted diagnostics are unknown, not green.
- Sphere `CellularityNotEstablished` was a lossy producer bucket; independent oracle separately proved pre-cut non-cellularity.
- A stage is not covered merely because accepted tests transitively reach it; gate membership must be explicit.
- Trace-crossed source edges are admissible cuts because arrangement subdivision does not mutate the immutable network.
- Cut completeness is proved by saturation with the source 1-skeleton.

## 6. Historical retirement

The following completed or superseded CP4c files were consolidated here and removed from the working tree on 2026-08-29. Their exact bytes remain recoverable from Git history; no current/future authority depends on them.

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

Historical per-turn CP4c reports retired by earlier consolidation rounds remain represented here, in `CHANGELOG.md`, and in Git history; they are not resurrected.

### 6.6 Durable ORIENTATION authority

`ORIENTATION.md` is **DURABLE** and is not historical CP4c debris. Every REVIEW turn must update its currency line, current position, witness table when changed, open problems in priority order, and recurring-defect section when a new pattern or instance is found. It must not be deleted, renamed away, or collapsed into another document without explicit user authorization.

## 7. Resume pointer

Read, in order after the durable start-of-turn checklist:

1. `Future_Chat_Session_Handoff.md`
2. `TODO.md`
3. `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Plan.md`
4. `Architecture_M3_CP4c2_CB9_Code_Build_Report.md`
5. `Architecture_M3_CP4c2_TB_X2_R9_Independent_Review_Record.md`
6. `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Report.md`
7. `Architecture_M3_CP4c2_DEFN_R2_Frozen_Definitions.md`
8. `Regression_Root_Cause_Tracker.md`

**Exact next:** `M3-CP4c-2-TB-X2-R10-EXEC`, artifact-only on immutable GMP package `9736088354`. Do not rebuild, repair, chmod, regenerate discovery, mutate source/tests/fixtures/selectors, or execute benchmarks. Run selector 365 from ordinal 1 with the frozen first-red hard stop, AI2 diagnostics at ordinal 363, and AH6 when 363-365 are reached.

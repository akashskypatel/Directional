# M3 CP4c — Consolidated Historical Record

**Purpose.** Durable, deduplicated history for the complete `M3-CP4c` family. This is historical synthesis, not current-turn procedure. Use `Future_Chat_Session_Handoff.md` for the exact next action and `TODO.md` for open work.

**Current state (2026-08-29).** `M3-CP4c-0`, `M3-CP4c-0b`, and `M3-CP4c-1` are **CLOSED / ACCEPTED**. `M3-CP4c-2-TB-X2-R7-REV` is **COMPLETE**. R7 re-proved the inherited predecessor **355/355** on immutable package `9719216316` / source `755485865a7cf9c485d754f22b82a41ee151824b`, closing `PR8-R043 / M3-CP4c2-R001`, `PR8-R044 / M3-CP4c2-R002`, and `M3-CP4c2-TB-X2-R7-ORCH-01`. CP4c-2 remains **open / runtime-unaccepted**: 357/358 are unselected/unrun and no gate is authorized. Exact next is `M3-CP4c-2-CB6`; CP4c-3 remains blocked.

Accounting: **44 / 14 / 30**, debt **5**, M3 packages **64**; `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

## 1. Retained authority

This record does not replace frozen definitions/selectors, closure records, or current immutable evidence. Retain:

- `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md`
- `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`
- `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`
- `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`
- `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md`
- current `Architecture_M3_CP4c*_Required_Green_Selector*.txt` and non-gating selectors
- `M3_CP4c0b_Closure_Record.md`, `M3_CP4c1_Closure_Record.md`
- `Architecture_M3_CP4c2_CB5_Code_Build_Report.md` — current predecessor build/package authority
- `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md` — latest runtime evidence
- `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`, `LESSONS.md`, `ORIENTATION.md`

## 2. Checkpoint results

| Checkpoint | Responsibility | Result |
|---|---|---|
| **CP4c-0** | exact resolved continuation and grazing | **346/346 CLOSED** |
| **CP4c-0b** | exact crash-on-contact termination / arrival | **353/353 CLOSED** |
| **CP4c-1** | observability, diagnosability, non-vacuous terminal events | **355/355 CLOSED** |
| **CP4c-2** | closed/higher-genus region authority, cut graph, cellularity | active; inherited **355/355** re-proof green |
| **CP4c-3** | mechanical witness / missing field-transport adjacency | blocked |

**CP4c-0.** Continuation requires exact entry position plus barycentric direction. Branch labels are face-gauge-local; cross-face semantics use published transport/lift. Grazing is exact `Inflow/Tangent/Outflow`; edge transit is used when both adjacent faces drive along the carrier; no tolerance decides topology.

**CP4c-0b.** The first termination theory was withdrawn. The accepted S0-S8 contract is exact crash-on-contact with fixed arrival priority and canonical tie handling; arithmetic guards are backstops, not semantic policy.

**CP4c-1.** The witness/test contract was corrected rather than topology changed. Terminal-kind evidence is non-vacuous and vocabulary-constrained, not count-frozen.

## 3. CP4c-2 durable history

### A2a′ and representation correction

The torus proved the network alone need not be a cut graph: measured `V=48`, `E=48`, `chi=0`; a cellular embedding would require `F=0`. CP4c-2 therefore introduced pre-region `SurfaceCutGraph` (A2a′), while preserving the prohibition on post-region repair/re-cut.

The first design wrongly promoted the whole-source-face/source-edge-barrier partition to cellularity authority. R5 falsified it on the accepted two-ring:

| representation | V | E | F | Euler |
|---|---:|---:|---:|---:|
| actual embedded graph | 9 | 11 | 3 | **1** |
| source-edge-barrier proxy | 10 | 11 | 2 | **1** |
| mixed producer certificate | 9 | 11 | 2 | **0** |

DEFN-R1 Amendment 13 made the **actual embedded graph of `FieldAlignedCurveNetwork ∪ cutEdges`** normative: graph/cut nodes are vertices, graph/cut arcs are edges, and dart orbits under the node rotation system are faces. CB4 compiled shared `EmbeddedGraphTopology.{h,cpp}` at `cebc12082c6dbe4830095df08169797b7dab0c5c`, package `9714226920`.

### Semantic/provenance split

R6 exposed representation-dependent semantic identity. `candidate_hash` correctly retained gauge-dependent `atlasDigest` for provenance/tamper rejection, but semantic identity must not consume it. CB5 separated semantic and provenance digests while preserving provenance binding. CB5 source `755485865a7cf9c485d754f22b82a41ee151824b` produced package `9719216316` (`sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc`), compile/package only.

### R7 document-authority stop and accepted retry

The first R7 attempt stopped before runtime because four prose selector hashes were fabricated abbreviations. DOC-R1 recomputed the six selector authorities from committed bytes and established the durable full-64-lowercase-hex/recompute rule.

The six selector authorities were independently recomputed from committed bytes; current selector files remain the authority and hashes must be recomputed rather than transcribed.

Corrected R7 run/job `33276039911 / 99162853852` passed immutable pre/postflight and **355/355**, including ordinals 305 and 310. R7-REV closed R043, R044, and R7-ORCH-01 without changing cumulative totals.

### Sphere re-localization

`SurfaceCutGraph::topology_error` maps 39 `GlobalTopologyPlanErrorCode` values to three surface-cut codes and collapses **36** into `CellularityNotEstablished`. R7 published `errorSourceFace=25-27-28`; every reachable collapsed upstream error carrying a source face is `RotationSystemInconsistent` in `EmbeddedGraphTopology.cpp`, and neither call site evaluates cellularity.

Therefore the sphere's `CellularityNotEstablished` is **not a cellularity verdict**. A2a′ renamed a pre-existing embedded-graph rotation-system failure before any cellularity decision. `M3-CP4c2-TB-X2-CAND-04` is reclassified to **localized to shared embedded-graph authority / cellularity framing withdrawn** and remains non-stable.

## 4. R7-REV measures AF0-AF9

| Measure | Durable requirement |
|---|---|
| **AF0** | Carry `optional<GlobalTopologyPlanErrorCode>` through `SurfaceCutGraphError` and print it; additive only, no re-map/new enum. |
| **AF1** | First in CB6, no runtime: extract prescribed-sphere `m3Cp4c2ActualGraphOracle` from artifact `9721564203` and adjudicate “already cellular pre-cut.” |
| **AF2** | Rename the withdrawn-proxy D2 helper, remove line-number locus labels, remove/redefine `localizationConsistent` against actual embedded graph. |
| **AF3** | Rebuild torus digest diagnostics from production `torus.rawfield`; print typed atlas errors/loci; do not repair synthetic zero-transport torus. |
| **AF4** | Use the production witness for `SurfaceCutGraph.IsInvariantToSourceFaceAndEdgeEnumeration`; run it non-gating to settle AD3. |
| **AF5** | DEFN must state per-identity A2a′ gate membership before acceptance. |
| **AF6** | Run every frozen non-gating identity or state a per-identity skip rationale. |
| **AF7** | Gate remains closed; probe selector-358's added identity non-gating before 358 can be selected. |
| **AF8** | Apply R7 bookkeeping exactly; totals remain **44 / 14 / 30**, debt **5**, packages **64**. |
| **AF9** | CB6: no selector/fixture bytes, new error enum, error re-map, sphere product fix, 357/358, cumulative gate, or benchmark; GMP/GMPXX mandatory if compiling. |

## 5. High-value reversals

- Raw branch labels are not cross-face semantic identity; they are per-face gauge labels.
- Large direction magnitude does not exclude tangency; tangency is a ratio.
- The source-edge-barrier partition is not the cellularity complex; actual embedded graph is normative.
- Self-consistent arithmetic can certify the wrong semantic object.
- Accepted-prefix red is a detection boundary, not proof the latest change caused the defect.
- Semantic and provenance digests are separate authorities.
- Unexecuted diagnostics remain unknown.
- Sphere `CellularityNotEstablished` was a lossy error bucket, not a cellularity finding.
- A new stage is not covered merely because accepted tests transitively reach it; gate membership must be explicit.

## 6. Historical retirement

Earlier consolidation rounds retired superseded CP4c-parent, CP4c-0, CP4c-0b, CP4c-1, and pre-R7 CP4c-2 per-turn records after durable facts moved to this record, `CHANGELOG.md`, `LESSONS.md`, the regression tracker, frozen definitions, and closure records.

This pre-CB6 consolidation retires the remaining consumed historical control/review documents:

- `Architecture_M3_CP4c2_DOC_R1_Documentation_Correction_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md` (already classified retired; physical cleanup completed here)

Intentionally retained until superseded: `Architecture_M3_CP4c2_CB5_Code_Build_Report.md` as current build/package authority and `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md` as latest runtime evidence.

No frozen definition, selector, closure record, policy, product/test/fixture source, or immutable external artifact is retired.

## 7. Resume pointer

1. `ORIENTATION.md`
2. `Future_Chat_Session_Handoff.md`
3. `TODO.md`
4. `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md`
5. `Architecture_M3_CP4c2_CB5_Code_Build_Report.md`
6. CP4c-2 frozen definitions/selectors as needed

**Exact next:** `M3-CP4c-2-CB6`. This consolidation does not start it and performs no implementation, compile, test, benchmark, selector execution, or gate selection.

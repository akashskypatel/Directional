# M3 CP4c — Consolidated Historical Record

**Purpose.** Durable, deduplicated history for the complete `M3-CP4c` family. Superseded per-turn plans,
reports, execution evidence, and reviews are retired here after their durable facts are preserved. This file is
historical synthesis, not the current turn procedure.

**Current state (2026-08-29).** `M3-CP4c-0`, `M3-CP4c-0b`, and `M3-CP4c-1` are **CLOSED / ACCEPTED**.
`M3-CP4c-2-CB5` is complete/build-green at `755485865a7cf9c485d754f22b82a41ee151824b` with immutable package `9719216316`.
R7 artifact-only runtime re-proved the inherited accepted **355/355** and immutable postflight, but CP4c-2 remains
runtime-unaccepted because 357/358 are unselected/unrun. Exact next is independent `M3-CP4c-2-TB-X2-R7-REV`.
`M3-CP4c-3` remains blocked on CP4c-2 closure.

**Current accounting.** Stable regressions **44 events / 14 categories / 30 recurrences**; produced-witness debt
**5**; authoritative M3 packages **64**. Accepted runtime predecessor remains CP4c-1 **355/355**.
`selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`.

## 1. Authority split: what stays separate

This consolidation does **not** replace normative definitions, live selectors, closure records, or current
CP4c-2 evidence/plan authority.

| Authority | Role |
|---|---|
| `Architecture_M3_CP4c0_DEFN_Frozen_Definitions.md` | resolved continuation contract and amendments |
| `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` | grazing/edge-transit contract |
| `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md` | trace-termination contract |
| `Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md` | A2a′ / `SurfaceCutGraph` contract; superseded proxy text is explicitly withdrawn there |
| `Architecture_M3_CP4c2_DEFN_R1_Frozen_Definitions.md` | Amendment 13 actual-embedded-graph authority and AC0–AC9 |
| `Architecture_M3_CP4c*_Required_Green_Selector*.txt` | frozen accepted/gate selector authority |
| `Architecture_M3_CP4c2_Non_Gating_Diagnostic_Selector.txt` | current CP4c-2 non-gating diagnostics |
| `M3_CP4c0b_Closure_Record.md`, `M3_CP4c1_Closure_Record.md` | checkpoint closure authorities |
| `Architecture_M3_CP4c2_CB5_Code_Build_Report.md` | current immutable CP4c-2 build/package authority |
| `Architecture_M3_CP4c2_DOC_R1_Documentation_Correction_Report.md` | current documentation-correction/consolidation evidence |
| `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md` | frozen R7 runtime-execution contract |
| `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Benchmark_Report.md` | current exact R7 runtime evidence |
| `CHANGELOG.md` | exact per-turn commits, run/job IDs, package/artifact IDs, and immutable evidence identities |
| `Regression_Root_Cause_Tracker.md` | stable regression/candidate history |
| `LESSONS.md` | durable cross-turn lessons |

Any older CP4c filename cited in `CHANGELOG.md` is **historical provenance**. If the file appears in §8, its
content has been retired into this record and/or the durable owner listed above.

## 2. Why CP4c exists and how it split

`DESIGN.md` §4.5 required resolved inflow/outflow interval pairing with exact barycentric propagation, but the
implementation paired intervals without carrying enough state to resolve continuation robustly. TB-R1 then
showed that the committed production witnesses also exercised topology domains beyond the bounded-disc authority
that had originally validated A2b. The checkpoint was therefore split instead of treating every failure as one
local tracing bug.

| Checkpoint | Responsibility | Final/current gate state |
|---|---|---|
| **CP4c-0** | resolved continuation and grazing behavior | **346/346 CLOSED / ACCEPTED** |
| **CP4c-0b** | exact crash-on-contact termination / arrival semantics | **353/353 CLOSED / ACCEPTED** |
| **CP4c-1** | witness observability, diagnosability, non-vacuous terminal-event contract | **355/355 CLOSED / ACCEPTED** |
| **CP4c-2** | closed/higher-genus region authority, cut graph, cellularity | active; inherited 355 re-proof green; 357/358 branch unselected |
| **CP4c-3** | mechanical witness / missing field-transport adjacency (C2) | deferred |

The same review arc removed the attempt-budget/diagnostic-cap model and collapsed the old dedicated diagnostic
turn into the canonical `CB → TB → review/plan on red` workflow.

## 3. CP4c-0 — continuation and grazing, closed

### 3.1 Durable result

The early census exposed the structural ambiguity: non-degenerate witnesses produced the expected `2×1` /
`1×2` pairing split, so accepted witnesses already contained unresolved continuation cases. The missing state was
not another heuristic; it was the exact entry position and barycentric direction that A1 computed and later
consumers needed.

The review/implementation sequence established these durable rules:

- branch identity is per-face gauge-dependent; cross-face semantics travel through the published transport/lift,
  never by comparing raw branch labels;
- exact serialization must preserve branch values numerically rather than stream `uint8_t` as characters;
- the cross-edge flow disagreement observation is invalid as a universal discrete invariant near tangency;
- grazing is a three-way exact classification (`Inflow`, `Tangent`, `Outflow`), with **edge transit** rather than
  forced stop when both adjacent faces drive the trace along the carrier;
- no epsilon/tolerance may decide the grazing topology;
- the six initially non-terminating prescribed-sphere paths were a missing termination rule, not evidence that
  the grazing definition should be weakened.

The highest-value reviewer corrections were also preserved: canonical-normal parity did not explain the lift;
`|d|` magnitude did not exclude tangency because tangency is a ratio; and a fixture that imposes inconsistent
matching cannot be used to indict production transport.

### 3.2 Closure authority

Fresh semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed` produced GMP package `9649395432`
(`sha256:557207bf8f668884295258690e3bd31485cbd7709f0be47aa98daea0c53b3e2e`). Artifact-only re-proof
run/job `33079817998 / 98543736213` returned **346/346 PASS**, including the 316 accepted prefix and 328 prefix,
with zero timeout, escaping C++ exception, orchestration error, or immutable postflight mutation. Result/log
artifacts: `9649625534 / 9649626115`.

The earlier 344/346 GMP run remains valid historical evidence; its two reds were non-stable test-side issues:
backend-dependent lossy conversion (`CAND-01`) and a degenerate positive-control fixture (`CAND-02`). Focused
CB/TB corrections proved each, then the whole 346 re-proof closed the checkpoint.

## 4. CP4c-0b — exact trace termination, closed

The first P0.3 theory was withdrawn after review: the accepted contact mechanism contained distinct sites and
preconditions that could not be represented by one broad fallback. The replacement S0–S8 contract made
termination **crash-on-contact** over exact geometry, with a fixed arrival priority, explicit tie semantics, and
no seniority fallback.

Key durable conclusions:

- terminal contact is an exact predicate; approximate/tolerance-based topology is prohibited;
- the accepted two-ring/fan observations established the load-bearing site vocabulary and contact census;
- the production arrival order is `ArcLengthFiltered` with certified forward-error handling;
- tied/inconclusive simultaneous contact uses mutual termination rather than arbitrary ownership;
- instrumentation added for the T5 preflight gap was test/non-gating only and never changed product behavior;
- T4's seven diagnostic identities passed before the final accepted gate.

Closure authority: semantic/test source `93059089881c8715a168a61968a8d6874ee1a670`, immutable GMP package
`9671190795` (`sha256:2901926c86a467160bae11aa4aac422d86fb9b275feff974c1645dd03b9a05c1`), artifact-only
run/job `33136084757 / 98736295227`, **353/353 PASS**, result/log artifacts `9672113006 / 9672113408`.
`M3_CP4c0b_Closure_Record.md` is the closure pointer.

## 5. CP4c-1 — observability and non-vacuity, closed

CP4c-1 corrected the test/diagnostic contract rather than inventing new product topology. Its durable result is
that witness-level success cannot be inferred from a vacuous or over-constrained terminal-kind predicate.

The accepted C5 contract reaches the named membership checks and observes exactly
`{TraceIntersection(2), MandatoryBarrierTermination(3), SingularityTermination(4)}` across the producing
witnesses. Torus legitimately contributes no terminal kind, and the mechanical witness remains upstream at
`IncompleteCycleBasis`; neither condition invalidates the accepted contract. Historical diagnostics that asserted
the prescribed sphere *must fail* were retired as inverted preconditions.

Closure authority: semantic/test source `b1ce8ad65952bd2bd76238f6dfc55523f6a24747`, immutable GMP package
`9675666067` (`sha256:63b66788e724f7f22acc5f3bd204a1eb666a779ced96d1373f320e00cd45ec17`), artifact-only
run/job `33161644741 / 98817323175`, **355/355 PASS**, result/log artifacts `9681960334 / 9681960615`.
`M3_CP4c1_Closure_Record.md` is the closure pointer and CP4c-2 predecessor authority.

## 6. CP4c-2 — cut-graph/cellularity history through DOC-R1

### 6.1 Definition and theorem

CP4c-2 established that the torus failure was not a local `GlobalTopologyPlan` bug. For a cellular embedding,
`V - E + F = χ`; the measured torus network has `V=48`, `E=48`, `χ=0`, hence a cellular embedding would require
`F=0`, impossible for a non-empty complement. More generally, a disjoint union of closed curves has `E=V` and
cannot itself be a torus cut graph. A new pre-region authority, **`SurfaceCutGraph` (A2a′)**, is therefore
required to supply admissible cuts before A2b derives regions.

The stop boundary remained intact: A2a′ may supply cuts without reading a produced `GlobalTopologyPlan`; any
post-region repair/re-cut remains prohibited.

### 6.2 Diagnostic arc and the first wrong authority

CB1 compiled the initial A2a′ design and froze both 357/358 successor selectors. The first X2 execution did not
adjudicate the branch because the diagnostic harness itself did not publish enough authoritative state. R2–R4
successively repaired *observation* problems: pipeline-vs-atlas authority mismatch, missing pipeline snapshots,
and duplicated final publication. These turns were useful because they exposed a recurring pattern:
**a diagnostic number and its expectation must come from the same authority**.

The R2 review nevertheless made one substantive mistake: it promoted the whole-source-face / source-edge-barrier
partition to cellularity authority. R5 falsified that ruling on the accepted two-ring:

| representation | V | E | F | Euler value |
|---|---:|---:|---:|---:|
| actual embedded graph | 9 | 11 | 3 | **1** |
| source-edge-barrier proxy | 10 | 11 | 2 | **1** |
| mixed producer certificate | 9 | 11 | 2 | **0** |

Both complete representations are internally self-consistent; the producer failed because it mixed two domains.
That is **`PR8-R043 / M3-CP4c2-R001`**, `AUTHORITY_DOMAIN_CONFLATION / RP-01`. It also proves why
self-consistency cannot establish that the measured representation is the normative one.

### 6.3 DEFN-R1 / CB4 correction

Amendment 13 froze the normative cellularity complex as the **actual embedded graph** of
`FieldAlignedCurveNetwork ∪ cutEdges`: vertices are graph/cut nodes, edges are graph/cut arcs, faces are dart
orbits under the node rotation system. Two conventions are mandatory:

1. exclude the exterior orbit on surfaces with boundary;
2. include the disconnected-graph correction rather than applying connected Euler arithmetic to the torus's
   four degree-2 loop components.

A source edge crossed by an immutable trace at an interior point is not an admissible cut, because promoting it
would subdivide that trace. Completeness is proved for trace-free non-disc components (including the torus) and
remains unproved for trace-crossed non-disc components, which must fail closed with
`NoAdmissibleCutForNonDiscComponent` rather than widen admissibility.

CB4 source `cebc12082c6dbe4830095df08169797b7dab0c5c` created shared
`EmbeddedGraphTopology.{h,cpp}` and compiled AC0–AC9. Authoritative GMP package `9714226920`
(`sha256:931d422611a8144faf4efe3f9307b3a1a90bbce4cab6d8873eb95b32ca1b9f83`) was produced in run/job
`33250547011 / 99095357374`; compile log artifact `9714227128`; packaged source archive
`sha256:3bb299730077cd7bbd46acd5e10f6f7fec1d0e131bc882710a5676163e36b021`.

### 6.4 R6: R043 fixed at locus, R044 exposed

R6 immutable execution on package `9714226920` passed accepted ordinals **1–309**, including ordinal 305 that
opened R043. Ordinal **310** `GlobalTopologyPlan.RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling`
was the first red: baseline/relabeled semantic digests
`12176020141753559903 / 14339407889896379635`. The frozen hard stop correctly left 311–355, the independent
actual-complex oracle, retained barrier diagnostic, sphere D2, 357/358, cumulative gate, and benchmarks unrun.
Unconditional postflight passed, resolving the earlier R5 postflight-orchestration candidate.

Independent R6 review therefore records:

- **R043 is resolved at its locus but not closed.** It closes only after a full **355/355** run with ordinal 305
  green; a 309-prefix green is not acceptance.
- **`PR8-R044 / M3-CP4c2-R002` is active/stable**, `REPRESENTATION_DEPENDENT_IDENTITY / RP-05`.
  `SurfaceCutGraph::candidate_hash` correctly contains gauge-dependent `atlasDigest` for provenance/tamper
  rejection, but `GlobalTopologyPlan::candidate_semantic_digest` incorrectly consumes that provenance hash as
  semantic identity.
- The required fix is the already-established semantic/provenance split: add a gauge-invariant
  `SurfaceCutGraph::semantic_digest()` while leaving `candidate_hash` intact.
- A latent hazard remains at `SurfaceCutGraph.cpp:258`: certificate faces are keyed by raw orbit index, an
  enumeration artifact. AD3 requires a proof of invariance or a content-derived key; merely making ordinal 310
  pass after removing `atlasDigest` from semantic consumption is insufficient.
- `M3-CP4c2-TB-X2-CAND-04`, the prescribed sphere's `CellularityNotEstablished`, remains **unlocalized** after
  seven turns because D2 has repeatedly been sequenced behind an earlier hard stop.

Exact next: **`M3-CP4c-2-CB5`**, runtime-free, measures **AD0–AD9**. Its successor must re-prove the complete
355 accepted prefix; R043 and R044 close only when ordinals 305 and 310 are green in that full run.

### 6.5 CB5: semantic/provenance split compiled

CB5 implemented R6 AD0–AD9 at `755485865a7cf9c485d754f22b82a41ee151824b` and produced fresh GMP package `9719216316` /
`sha256:acb43cf0ec79437408c782193ece354eb790d9ae2159eaeb42546546ea20c3fc` with **28/28** internal-manifest verification and no runtime execution. `SurfaceCutGraph`
now exposes separate semantic and provenance digests while leaving `candidate_hash` unchanged for atlas/network
tamper binding; `GlobalTopologyPlan` consumes only the semantic cut-graph digest for semantic identity. The raw
orbit index was retained only after proving it is a canonical rank induced by totally sorted semantic arc
descriptors and canonical dart walking. Two non-gating cut-graph gauge-relabeling diagnostics were added for the
two-ring and torus witnesses. No selector changed. R043/R044 remain runtime-unclosed until full R7 355 evidence.

R7 keeps D2 behind a green full accepted prefix as required by AD9. If another upstream accepted-prefix stop prevents
D2, the next review may reconsider non-gating diagnostic sequencing; R7 itself does not weaken that stop rule.

### 6.6 R7 preflight stop and DOC-R1 documentation correction

The first R7 attempt never executed a Directional process. Immutable preflight found four prose constants (346,
353, 357, 358) that disagreed with unchanged selector bytes; 316 and 355 matched. The hard-stop/no-self-heal rule
worked correctly and the package remained unchanged. This is tracked as non-stable orchestration/document-authority
`M3-CP4c2-TB-X2-R7-ORCH-01`; stable regression accounting did not change.

Independent review proved the four values were transcription fabrications, not selector drift: one was only 63
characters and all four matched the prefix/suffix shape of earlier abbreviated hashes. DOC-R1 then independently
recomputed all six from committed bytes, corrected the four current-authority occurrences in the CB5 AD0 audit and
R7 plan, added source-file/derivation columns and 64-lowercase-hex authoring checks, and preserved the digest rule
in `LESSONS.md` 22n. No selector, package, semantic/test source, product, test, or fixture changed.

AE8 also moves the non-gating R7-2..R7-5 measurements before the accepted 355 prefix on retry. Each runs in a
fresh process against the immutable package, grants no accepted-count credit, and mutates nothing; the accepted
prefix remains the unchanged gate and still blocks 357/358/cumulative-gate/benchmark work on red.

DOC-R1 selector authority (recomputed from bytes): 316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`, 346 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`, 353 `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`, 355 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`, 357
`b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`, 358 `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`. Exact next is the artifact-only R7 retry on package `9719216316`.

### 6.7 R7 retry: full accepted re-proof green; non-gating torus precondition red

The corrected R7 retry on unchanged package `9719216316` completed under run/job `33276039911 / 99162853852`.
Immutable preflight passed all six recomputed selector authorities and postflight proved no package/source/test/fixture/
selector mutation, configure, compile, relink, repair, generated discovery, or benchmark. Raw evidence archive SHA-256
is `933190d3591aa7633fd3ebb6c1a119c1ad7d0b04cc2ca4254a8c325d3c7f1200`.

Non-gating publication ran first. The two-ring semantic/provenance split passed with equal semantic and unequal
provenance digests. The torus counterpart selected exactly once but failed at `baselineAtlas == true` before any
digest comparison, so it is a non-stable diagnostic candidate rather than accepted-count loss. The independent
actual-embedded-graph oracle, retained source-edge-barrier diagnostic, and prescribed-sphere D2 localization
identity all passed. D2 finally publishes the previously missing record: `surfaceCutGraphError=CellularityNotEstablished`,
`producerGlobalCountsReached=true`, `localizedSite=474-global-certificate`, and `localizationConsistent=false`;
interpretation is reserved for independent review.

The accepted predecessor selector then passed **355/355** in fresh processes, including ordinal 305 (R043 locus)
and ordinal 310 (R044 locus) in the same complete run. EXEC records that both frozen runtime closure conditions are
mechanically satisfied but does not reclassify stable records. Stable accounting remains **44 / 14 / 30** pending
R7-REV. Selector 357, selector 358, cumulative gate, and benchmarks were not run; `selected_r2_branch=NONE`,
`selected_gate=NONE`, `gate_execution_authorized=false`. Exact next is `M3-CP4c-2-TB-X2-R7-REV`.

### 6.8 R7-REV: three closures, and the collapsed typed error

Independent review of the R7 retry closed `PR8-R043 / M3-CP4c2-R001` (ordinal 305 green in a full 355/355),
`PR8-R044 / M3-CP4c2-R002` (ordinal 310 green in the same run, with the CB5 semantic/provenance split re-verified at
source as a correct application of the CP3a template), and `M3-CP4c2-TB-X2-R7-ORCH-01` (green R7-0 on all six
recomputed selector derivations). Stable totals were **not** changed: closure is a status change, not a count
change, so accounting remains **44 / 14 / 30**, debt **5**, M3 packages **64**.

The review's substantive finding re-framed the checkpoint. `SurfaceCutGraph::topology_error` maps 39
`GlobalTopologyPlanErrorCode` values onto three `SurfaceCutGraphErrorCode` values, collapsing **36 of them into
`CellularityNotEstablished`** while copying `sourceFace` through. It is the only producer of that code on the `make`
path that sets a `sourceFace`, and R7-5 published `errorSourceFace=25-27-28`. Its two call sites both enter
`EmbeddedGraphTopology.cpp`, where every code that survives the collapse and carries a `sourceFace` is
`RotationSystemInconsistent`. Neither call site evaluates cellularity. **The prescribed sphere therefore never
reached a cellularity decision; inserting A2a′ upstream renamed its pre-existing failure rather than changing it**,
and eight turns of planning reasoned about cuts and complexes for a mechanism that never ran. `CAND-04` was
re-classified accordingly and the cellularity framing withdrawn.

Three further findings were recorded as candidates: the D2 localization harness compares the actual embedded graph
against the **withdrawn** source-edge-barrier proxy under a misleading helper name and stale line-number site labels
(`R7-CAND-03`); the torus digest diagnostic builds a synthetic zero-transport witness with no production counterpart
and fails at its own precondition (`R7-CAND-01`, adjudicated); and **no `SurfaceCutGraph.*` identity appears in the
accepted 355 or in either candidate gate**, with the prescribed sphere in neither gate and selector 358's sole
addition binding the out-of-scope mechanical witness (`R7-CAND-04`).

Measures **AF0–AF9** were issued. No gate was selected: `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`. Exact next is `M3-CP4c-2-CB6`, a bounded diagnostic and witness-repair Code +
Build whose first measure, AF1, requires no build — it extracts the prescribed sphere's actual-embedded-graph oracle
row, already published by R7-3 and omitted from the R7 report, from retained result artifact `9721564203`.

## 7. High-value reversals and lessons retained from the review arc

| Earlier claim / approach | Final disposition |
|---|---|
| raw branch labels can be compared across faces | false; branch labels are per-face gauge labels |
| canonical-normal parity explains cross-edge disagreement | refuted; the gauge cancels in the lift |
| large direction magnitude excludes tangency | false; tangency is a ratio |
| the fan's imposed-matching disagreement indicts A1 | reversed; the fixture contradicts its geometry |
| source-edge-barrier partition is the cellularity complex | withdrawn; actual embedded graph is normative |
| self-consistent Euler arithmetic proves the representation is correct | false; two-ring proxy and actual complex both satisfy Euler |
| accepted-prefix failure identifies the commit that caused it | false; prefix re-proof is a detection boundary, not a blame boundary |
| one hash can serve semantic identity and provenance | false; semantic and provenance digests are distinct authorities |
| an observation hidden behind a prior failing gate is evidence of absence | false; unexecuted diagnostics remain unknown |
| the prescribed sphere's `CellularityNotEstablished` is a cellularity verdict | false; it is a `default:` bucket for 36 upstream codes, and the sphere never reached a cellularity decision |
| a new stage's own identities are covered because the stage is reached transitively | false; none of A2a′'s four identities is in any selector, and one of them is non-viable |

These lessons are also normalized in `LESSONS.md`; they are listed here only because they explain why several
historical CP4c retry documents existed.

## 8. Historical document retirement manifest

### 8.1 Earlier consolidation rounds

The 2026-08-26 through 2026-08-28 consolidation rounds already retired the original CP4c-parent, CP4c-0,
CP4c-0b, and CP4c-1 per-turn reports/review briefs once their durable facts were moved here, to `CHANGELOG.md`,
`LESSONS.md`, the regression tracker, frozen definitions, and closure records. Historical filenames in older
changelog entries remain provenance only.

### 8.2 2026-08-29 sixth consolidation — remaining superseded CP4c documents retired

The following **35** repository documents are now historical and are retired after this record, the changelog,
tracker, definitions, and closure records were reconciled. They are no longer current authority.

**CP4c-0 / CP4c-0b / CP4c-1:**

- `Architecture_M3_CP4c0_TB_R8_Review_And_CB9_Corrective_Record.md`
- `Architecture_M3_CP4c0_TB_R9_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c0b_CB2_Code_Build_Report.md`
- `Architecture_M3_CP4c0b_CB3_Instrumentation_Code_Build_Report.md`
- `Architecture_M3_CP4c0b_DG_Independent_Review_Record.md`
- `Architecture_M3_CP4c0b_DG_T4_EXEC_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c0b_DG_T4_Independent_Review_Record.md`
- `Architecture_M3_CP4c0b_P0_3_Independent_Review_Record.md`
- `Architecture_M3_CP4c0b_TB_T5_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c0b_TB_T5_Preflight_Blocker_Report.md`
- `Architecture_M3_CP4c0b_TB_T5_Preflight_Independent_Review_Record.md`
- `Architecture_M3_CP4c1_TB_R5_Artifact_Only_Test_Benchmark_Report.md`

**CP4c-2 before the current CB4/R6 authority:**

- `Architecture_M3_CP4c2_CB1_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB2_DIAG_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB2_DIAG_R1_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB2_DIAG_R2_Code_Build_Report.md`
- `Architecture_M3_CP4c2_CB3_DIAG_Code_Build_Report.md`
- `Architecture_M3_CP4c2_TB_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_EXEC_Artifact_Only_Evidence.md`
- `Architecture_M3_CP4c2_TB_X2_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R2_Artifact_Only_Test_Benchmark_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R2_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R3_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R3_EXEC_Artifact_Only_Evidence.md`
- `Architecture_M3_CP4c2_TB_X2_R3_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R4_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R4_EXEC_Artifact_Only_Evidence.md`
- `Architecture_M3_CP4c2_TB_X2_R4_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R5_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R5_EXEC_Artifact_Only_Evidence.md`
- `Architecture_M3_CP4c2_TB_X2_R5_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R6_Artifact_Only_Test_Benchmark_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_Review_Record.md`

**Retained current CP4c-2 authority after that round:** CB5 build report, R6 EXEC evidence, and the R7 artifact-only plan. Older
CB4/R6-review files were provenance pending the next consolidation round.

### 8.3 2026-08-29 seventh consolidation — superseded CP4c-2 turn records retired

After DOC-R1 preserved the R7 stop/review facts and corrected the current execution authority, the following six
per-turn records became historical-only and were retired under explicit user authorization:

- `Architecture_M3_CP4c2_CB4_Code_Build_Report.md`
- `Architecture_M3_CP4c2_TB_X2_R6_EXEC_Artifact_Only_Evidence.md`
- `Architecture_M3_CP4c2_TB_X2_R6_Independent_Review_Record.md`
- `Architecture_M3_CP4c2_TB_X2_R7_EXEC_Artifact_Only_Evidence.md`
- `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Plan.md`
- `Architecture_M3_CP4c2_TB_X2_R7_Independent_Review_Record.md`

Their durable facts remain in §§6.3-6.6, `CHANGELOG.md`, `Regression_Root_Cause_Tracker.md`, `LESSONS.md`, and the
current DOC-R1 report. Historical filenames in old changelog entries remain provenance tied to their original
commits/runs. No frozen definition, selector, closure record, product/test/fixture source, or immutable package was
retired or modified.

**Retained current CP4c-2 authority:** CB5 build report, DOC-R1 correction report, R7 artifact-only retry plan,
frozen definitions/selectors, closure records, and the durable cross-cutting trackers/policies.

## 9. Resume pointer

Do not resume implementation from this historical record. Use, in order:

1. `ORIENTATION.md` for cold-start architecture/current context;
2. `Future_Chat_Session_Handoff.md` for exact mandatory procedure and next turn;
3. `TODO.md` for open/blocked work;
4. `Architecture_M3_CP4c2_TB_X2_R7_Artifact_Only_Test_Plan.md` for the exact next execution;
5. `Architecture_M3_CP4c2_DOC_R1_Documentation_Correction_Report.md` for the corrected hash/consolidation evidence;
6. `Architecture_M3_CP4c2_CB5_Code_Build_Report.md` for current immutable build/package authority.

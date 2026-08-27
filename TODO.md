# Directional Surface-Cell TODO

Last updated: 2026-08-27 UTC

## Purpose

This is the single durable **task index** — open and blocked work only. It is deliberately forward-looking.

Closed milestone/checkpoint history lives in `M1_Closure_Record.md`, `M2_Closure_Record.md`, `M3_CP2_Closure_Record.md`, `M3_CP2b_Closure_Record.md`, `M3_CP3_Closure_Record.md`, and `M3_CP4ab_Closure_Record.md`. Exact runtime evidence lives in `CHANGELOG.md`, the current retained turn report, and `Regression_Root_Cause_Tracker.md`. Normative architecture lives in `DESIGN.md`; the checkpoint map to production-ready lives in `ROADMAP.md`; migration ordering lives in `REORIENTATION_PLAN.md`.

**Do not re-accumulate per-checkpoint, per-retry, or per-partial narrative here.** A closed checkpoint gets one line in `ROADMAP.md` §1 and a closure record; it does not stay in this file.

## Turn workflow — changed 2026-08-25

```
CB  →  TB  →  green?  →  checkpoint CLOSES
                ↓ red
        REVIEW + PLAN  →  CB  →  …
```

**Non-gating diagnostic identities** TB executes and reports them, the
gate count excludes them, each carries a written rationale and an owning corrective measure.

## Current focus — `M3-CP4c-0` CLOSED / ACCEPTED; `M3-CP4c-0b-CB1` authorized but stopped at frozen P0.3

**CP4c-0 has been split.** It was carrying two unrelated obligations under one gate: *how a trace continues* and *how a trace stops*. After CB-R10/TB-R10 and CB-R11/TB-R11 resolved both test-side TB-R9 candidates, the user explicitly authorized a fresh compile and complete frozen-gate re-proof. Fresh GMP package `9649395432` from semantic source `7bbc0480d9ab5954329b940992ef41a9223102ed` compiled all eight standard targets; artifact-only run/job `33079817998 / 98543736213` returned **346/346 PASS**, first-316 **316/316**, first-328 **328/328**, Q8 criteria 1/4/5 PASS, zero timeouts/exceptions, and immutable postflight PASS. CP4c-0 is therefore **CLOSED / ACCEPTED**. The termination half remains separately frozen under CP4c-0b.

| | **CP4c-0** — continuation | **CP4c-0b** — termination |
|---|---|---|
| owns | exact minimum-ratio continuation, `FieldBoundaryPoint`, grazing classification and edge transit, vertex dispatch, deterministic cost guards | trace/trace contact, arrival priority, contact node and event, retirement of the CB9 stand-in guards |
| gate | **346**, `20d3b0b1...`, **346/346 ACCEPTED** | frozen by `M3-CP4c-0b-CB1` as `346 + n` |
| Q8 | criteria **1, 4, 5** | criteria **2** and **3** |

**Q8 criteria 2 and 3 move together, and are not weakened** (Amendment 11). They are one piece of work: the six circulating traces are simultaneously what blocks criterion 2 and what satisfies criterion 3. **CP4c-0 closes on its own evidence** rather than being held hostage — nothing green stays in limbo.

**`M3-CP4c-0-TB-R9` final authority** — **COMPLETE / GATE GREEN 346/346** on fresh GMP package `9649395432`, authoritative run/job `33079817998 / 98543736213`. The unchanged selector, accepted first-316 and first-328 remain **346 identities / 316/316 / 328/328**; Q8 criteria 1/4/5 PASS; zero timeouts or escaping C++ exceptions; immutable postflight PASS. The original `344/346` run remains historical valid RED evidence, and both non-stable test-side candidates are resolved.

**`M3-CP4c-0b-CB1`** — **AUTHORIZED / STOPPED AT BINDING P0.3 BEFORE IMPLEMENTATION.** Static preflight on 2026-08-27 proved accepted CP3b already produces `FieldAlignedNetworkEventKind::TraceIntersection` (closure record + three production emission sites), while frozen P0.3 requires it to be declared and produced by nothing. The frozen plan says any P0 failure stops and returns to review. No P1-P9 product/test/build/runtime work was performed. **Exact next: independent review / plan correction for P0.3; CB1 resumes only after that review.**

**Alternative priority metrics are retained for future performance/quality comparison** (`StepCount`, `BarycentricTime`, `TraceSeniority`) but are reachable **only** from a diagnostic entry point the production pipeline never calls, with an identity asserting production cannot select a non-default value. A production-reachable priority argument is a second writer of network topology and a stop condition.

**Exact-backend build policy:** `.agents/Directional/GMP_COMPILE_POLICY.md` is durable repository-wide authority by explicit user instruction. **Every future compile must link GMP/GMPXX; fallback exact arithmetic is not authoritative compile evidence.** The durable ChatGPT Web compile workflow already ensures `libgmp-dev` is installed, configures `DIRECTIONAL_ENABLE_GMP=ON` with `GMP_ROOT=/usr`, verifies CMake discovery, verifies both `gmpxx` and `gmp` on generated link lines, and records `exactArithmeticBackend=GMP`. Artifact-only TB callers that execute dynamically linked binaries must provide the GMP runtime libraries.

- [x] `M3-CP4c-0-DEFN` — COMPLETE.
- [x] `M3-CP4c-0-CB1` — COMPLETE / BUILD GREEN.
- [x] `M3-CP4c-0-TB` — COMPLETE / VALID RED.
- [x] `M3-CP4c-0-TB-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB2` — COMPLETE / BUILD GREEN. Package `9586196535`.
- [x] `M3-CP4c-0-TB-R2` — COMPLETE / VALID SEMANTIC RED.
- [x] `M3-CP4c-0-TB-R2-REVIEW-PLAN` — COMPLETE.
- [x] `M3-CP4c-0-CB3` — COMPLETE / BUILD GREEN. Package `9589508430`.
- [x] `M3-CP4c-0-TB-R3` — COMPLETE / VALID SEMANTIC RED. 336/338; F3 2/2.
- [x] `M3-CP4c-0-TB-R3-REVIEW-PLAN` — COMPLETE. Both reds test-side; Amendment 7; G0–G8.
- [x] `M3-CP4c-0-CB4` — COMPLETE / BUILD GREEN. Package `9591540182`; test-side corrections only.
- [x] `M3-CP4c-0-TB-R4` — COMPLETE / VALID SEMANTIC RED. 338/338; Q8 RED criterion 2.
- [x] `M3-CP4c-0-TB-R4-REVIEW-PLAN` — COMPLETE. H0–H7 frozen.
- [x] `M3-CP4c-0-CB5` — COMPLETE / BUILD GREEN. Package `9601160869`.
- [x] `M3-CP4c-0-TB-R5` — COMPLETE / VALID SEMANTIC RED. 338/338; H1 delivered.
- [x] `M3-CP4c-0-TB-R5-REVIEW-PLAN` — COMPLETE. Amendment 8; J0–J7 frozen.
- [x] `M3-CP4c-0-CB6` — COMPLETE / BUILD GREEN. Package `9619352525`.
- [x] `M3-CP4c-0-TB-R6` — **COMPLETE / VALID SEMANTIC RED.** 338/338; F3 2/2; J3 legitimate 524/524 geometry agreement; Q8 RED criterion 2.
- [x] `M3-CP4c-0-TB-R6-REVIEW-PLAN` — **COMPLETE.** Root cause **identified**: the disagreements are a
  **near-tangency discretization phenomenon**, and **Amendment 4 / measure E5's invariant is too strong**
  for a piecewise-constant field. Reproduced the sphere census from the committed fixture alone —
  **exactly 144 directed**, matching runtime — and measured the tangency ratio: disagreeing median
  **0.0218** vs agreeing **0.9233**, every disagreement ≤ **0.2004**. At the live locus **every published
  term is independently verified correct** (matching 0 right with a 42° margin; `0 + 1 − 3 ≡ 2`
  reproduces the lift; both `dbary` triples match to 10 dp; mesh adjacency sound). **One class, not
  two.** Amendment 9 issued. Record:
  `M3_CP4c_Consolidated_Record.md` §3b (retired TB-R6 review).
- [x] `M3-CP4c-0-CB7` — **COMPLETE / BUILD GREEN.** Semantic source `077462da156c3e2dfbbc6867fc10d3e4442d853c`; package `9625495708`. K0–K7 diagnostic/contract-control only; no production semantics; all eight standard targets compiled/linked; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R7` — **COMPLETE / VALID SEMANTIC RED.** 338/338; F3 2/2; K1 near-tangency reproduced; K2 0/24 reaches grazing (non-decisive); J3 524/524 legitimate; K3 176/176 / 0 mismatches; Q8 RED criterion 2.
- [x] `M3-CP4c-0-DEFN-2` — **COMPLETE.** Closed the `DESIGN.md` §4.5 gap. Chose **grazing edge
  transit** over grazing terminus, refinement precondition, and a general edge-following mode, on a
  continuity proof against Amendment 3 rather than on K2 cost data — K2 measured the retired Cartesian
  rule and is void. Q8 **not amended**; criterion 3 re-homed to CP4c-1 with reasons.
  `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md`; Amendment 10; `DESIGN.md` §4.5.
- [x] `M3-CP4c-0-CB8` — **COMPLETE / BUILD GREEN.** Semantic source `19ba8e9c5e58f9c33c14b309841165d3f0401db5`; package `9628445643`. L0–L9 only; 343 required-green identities; all eight standard targets compiled/linked; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R8` — **INCOMPLETE / BLOCKED.** 342/343 completed; ordinal 338 RED after 853.437 s with `gcd(): while running too long!`; ordinal 343 incomplete at user cancellation; no acceptance credit.
- [x] `M3-CP4c-0-TB-R8-REVIEW-PLAN` + `M3-CP4c-0-CB9` — **COMPLETE.** Combined at user instruction.
  Root cause: non-terminating traces + two inert guards + an exact backend that throws out of a closed
  producer. Measures **N0–N7** implemented and compiled per translation unit; nothing executed.
  Deterministic product-level guard has landed, so the binding stop rule is discharged.
- [x] `M3-CP4c-0b-DEFN` — **COMPLETE.** Split the checkpoint; froze the trace-termination contract,
  the contact predicate, the `ArcLengthFiltered` arrival priority with mutual termination on
  inconclusive or tied arrivals, and the constrained alternatives harness. Amendment 11 moves Q8
  criteria 2 and 3 to CP4c-0b; `DESIGN.md` §4.6's termination guarantee is amended to name its
  condition. Record: `Architecture_M3_CP4c0b_DEFN_Trace_Termination_Frozen_Definitions.md`.
- [x] `M3-CP4c-0-TB-R9` — initial execution COMPLETE / VALID SEMANTIC RED **344/346** on GMP package `9634245265`; historical evidence retained. Final whole-gate re-proof is recorded below.
- [ ] `M3-CP4c-0-TB-R9-REVIEW-PLAN` — **SKIPPED BY EXPLICIT USER INSTRUCTION; NOT COMPLETED.** Its bypass does not grant acceptance or adjudicate `CAND-02`.
- [x] `M3-CP4c-0-CB-R10` — **COMPLETE / BUILD GREEN.** Test-only GMP-portability correction at semantic source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`; compile run/job `33067140968 / 98499967674`; immutable GMP package `9644214591`, SHA-256 `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`; all eight standard targets compile/link; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R10` — **COMPLETE / FOCUSED PASS.** Artifact-only run/job `33067370314 / 98500728780`; `ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` selected exactly once and PASS in 5 ms; immutable postflight PASS. This resolves `M3-CP4c0-TB-R9-CAND-01` only.
- [x] `M3-CP4c-0-CB-R11` — **COMPLETE / BUILD GREEN.** Test-only CAND-02 fixture correction at semantic source `267272d22f7de67ce7d8e368a53cc78a37ca3e8f`; compile run/job `33077493539 / 98535503386`; immutable GMP package `9648550565`, SHA-256 `1f0275e96fa75b7fc6fb447eaffb79b414c94230823da7897a4f2d91df33615c`; all eight standard targets compile/link; `runtimeExecution=false`.
- [x] `M3-CP4c-0-TB-R11` — **COMPLETE / FOCUSED PASS.** Artifact-only run/job `33077761701 / 98536455697`; `ExactContinuationMagnitudePolicyFailsClosedWithoutTolerance` selected exactly once and PASS in 39 ms; immutable postflight PASS. This resolves `M3-CP4c0-TB-R9-CAND-02`.
- [x] `M3-CP4c0-TB-R9-CAND-02` — **RESOLVED / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION.** The old positive control was exactly degenerate; the corrected witness proves a positive exact `1/4` edge exit while preserving the oversized-magnitude fail-closed case.
- [x] `M3-CP4c-0-TB-R9-REPROOF` — **COMPLETE / GATE GREEN 346/346 / CP4c-0 CLOSED / ACCEPTED.** Fresh compile run/job `33079499974 / 98542697746`, package `9649395432`; artifact-only TB run/job `33079817998 / 98543736213`; Q8 1/4/5 PASS; immutable pre/postflight PASS.
- [ ] `M3-CP4c-0b-CB1` — **AUTHORIZED / BLOCKED AT FROZEN P0.3 BEFORE IMPLEMENTATION.** Exact next is independent review / plan correction; P1-P9 remain untouched.
- [ ] `M3-CP4c-0b-P0.3-REVIEW-PLAN` — **NEXT / INDEPENDENT REVIEW BOUNDARY.** Reconcile frozen P0.3 with accepted CP3b `TraceIntersection` production; no product/test/build/runtime mutation in the review.
- [ ] `M3-CP4c-1` — OPEN, blocked on CP4c-0b. It **no longer owns** re-homed Q8 criterion 3, which
  belongs to CP4c-0b along with criterion 2.
- [ ] `M3-CP4c-2-DEFN` — BLOCKED.
- [ ] `M3-CP4c-3-DEFN` — BLOCKED.

Frozen CP4c-0 selector authority remains **346** `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`; accepted first-316 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`; first-328 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`. Latest accepted runtime is TB-R9 re-proof **346/346**, run/job `33079817998 / 98543736213`. Stable accounting remains **42 / 14 / 28**, produced-witness debt **5**, M3 packages **51**. Both TB-R9 non-stable candidates are resolved and pass in the complete frozen-gate context; CP4c-0 is **CLOSED / ACCEPTED**. **The only authorized successor from the failed P0 preflight is the independent P0.3 review/plan boundary; do not resume CB1 implementation before it.**

**TB-R6 disposition after review — corrected.** Three standing readings are **withdrawn**:

1. **The live locus does not indict `build_branch_transports`.** Its lift composes correctly
   (`0 + 1 − 3 ≡ 2`), its matching is geometrically right (nearest target raw index at 23.7°, next at
   66.3°), both gauges are right, and both published `dbary` triples reproduce from the fixture to 10
   decimal places. The decision-table row it satisfied is withdrawn as a diagnosis.
2. **There are not two classes.** The unequal-gauge (86/43) and equal-gauge/lift-0 (254/127) populations
   are the same **near-tangency** phenomenon seen through different bookkeeping.
3. **J3's 524/524 does not exclude H-B.** `independent_edge_measurement` re-implements **principal
   matching** — the algorithm H-B suspects — so it is an implementation cross-check, not an aliasing
   test. (H-B *is* excluded, but by direct measurement at the live locus, not by J3.)

**Root cause:** Amendment 4 / measure E5 asserts a **continuum** property that a piecewise-constant field
does not satisfy near edge tangency. The real gap is that **`DESIGN.md` §4.5 does not define what a trace
does at a grazing edge** — a `-DEFN` question, not a patch. **No production change is authorized; there
is nothing in A1 to fix.** Q8 stays red until the model question is settled.

## CP4c documentation — consolidated 2026-08-26

Twenty-four per-turn CP4c execution documents and superseded review briefs were retired into
**`M3_CP4c_Consolidated_Record.md`** under explicit user authorization, preserving every evidence
identifier. Thirty-three CP4c documents became twelve. Retained live: the CP4c-0 DEFN charter and frozen
definitions, the five independent reviews (they carry Amendments 1–7 and measure series E/F/G/H), and
all selector `.txt` authority files. A citation naming a retired document now points at the consolidated
record — **retired provenance, not lost authority**. CP4c-0 and CP4c-1 remain **OPEN**; the record is
historical and closes nothing.
## After M3 exit

`ROADMAP.md` §4 proposes the checkpoint decomposition for **M4–M8** — seventeen checkpoints plus five `-DEFN` planning turns to reach `M8-CP3`, the production-ready exit. That decomposition is a **proposal until each milestone's `-DEFN` turn freezes it**; gate arithmetic beyond 322 is deliberately not fixed.

## Carried forward from M2

- [ ] **3 latent fixture-authority sites** — `PatchDescriptorMilestoneETests.cpp:1220`, `:1260`, `:1811`. Defaulted completion options assert success but pass only because their complexes never reach boundary-ownership resolution; none are in the frozen selector.
- [ ] **Remove the `= {}` default** on the authority-consuming `complete_surface_cell_complex` overload (`PatchDescriptor.h:427`) so omission stops compiling.
- [ ] **Establish authority-carrying completion options as the local idiom.** `SurfaceCellComplexCompletionOptions` remains authority-unset by default across the affected tests.

## Carried forward from M1

**Produced-witness debt — `G4-B002` → revised M4 (3).** A fourth reopens section 14 scheduling.
- [ ] Re-prove `CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous` on a produced closed complex.
- [ ] Re-prove `PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` through the torus pipeline.
- [ ] Re-prove `MissingPeriodicRelationOwnerIsRejected` on produced periodic authority.

**Produced-witness debt — `G4-B003` → M5 (2).** A third reopens M5 scheduling.
- [ ] Re-prove `FullPeriodicRotationAndTranslationMaterialize` on produced nonzero-Z4 authority.
- [ ] Re-prove `TamperedFullPeriodicTransformIsRejected` on produced nonzero-Z4 authority.

**Criterion-5 disposition re-proof → M7.**
- [ ] Re-express M1 criterion 5 in disposition terms and re-run F1/F2/F3 under verifier-assigned `Certified`. M7 does not close until green.

## Deferred hygiene

- [ ] **Repair `.github/workflows/agent-turn-cleanup.yml` comment handling and trigger safety.** The workflow still deletes **all** PR conversation and inline review comments before its observer step, and creating `.agents/connector-triggers/turn-cleanup/manifest.txt` auto-triggers it. Run `32591251950 / 97075340976` demonstrated 27 conversation-comment deletions. User commit `c359ea925b04471500575a9dcc17bdc6e4bb52d1` explicitly superseded the old prohibition by requiring the manifest/workflow at every turn closeout. Until the workflow is repaired, preserve durable repository evidence before publishing the closeout manifest and treat PR comments as non-durable.

Inherited baseline-red / non-gating fixtures remain frozen in the M1 exclusion register. None may become required-green evidence before its precondition is independently established.

- [ ] `WU2A-TB-CAND-01`: successful-side-subdivision ownership-registry precondition.
- [ ] `WU2B-TB-CAND-01`: hard-rail region-copy valid front-boundary-authority precondition.
- [ ] `WU2B-TB-CAND-02`: side-repair rollback ownership-registry/domain-identity precondition.
- [ ] `WU2B-TB-CAND-03`: authoritative-cell-scope subdivision source-scope reconciliation.
- [ ] `WU2B-TB-CAND-04`: five simplification fixtures need independently proven removable/protected/healing preconditions.
- [ ] `WU2B-TB-CAND-05`: FlowRep mandatory-cycle witness needs `selectionSucceeded=true` before later-cycle evidence is creditable.
- [ ] `RA-REV-23-F3`: dispatch stitch-kind audit through an explicit classifier field rather than probe-name text; add a negative self-test.
- [ ] `RA-REV-22-F6`: remove non-falsifiable validation-used assertions or set them where each gate actually executes.
- [ ] `RA-TB6-H1`: repair repeated `TriMesh::set_mesh` / `DCEL::init` stale halfedge-twin reinitialization outside the R-A fixture path.

## Milestone status

Checkpoint decomposition, per-milestone acceptance mapping, and the path to production-ready are in **`ROADMAP.md`**. Summary only:

- [x] **M0** preserve evidence  ·  [x] **M1** single-authority cutover  ·  [x] **M2** closed stage products
- [ ] **M3 — field-aligned curve network.** CP4ab accepted at **316/316**; CP4c split into **CP4c-1 (318)**, **CP4c-2 (321)**, **CP4c-3 (322)**.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] `G4-B001 / PR8-R034 / G4-R007`: direct torus final `LocalSheetMismatch`; downstream of A2b and not a CP4c witness collision.
- [ ] `G4-B002`: exact torus `InvalidHardRailPairing`; revised M4.
- [ ] `G4-B003`: nonzero periodic Z4 production; M5.
- [ ] `G4-B004`: positive multi-isolation quotient witness; M5/M6.
- [ ] Bunny/Vase representative production and resource acceptance — later product gates.

## Design and calibration backlog

- [ ] Own the closed-rail cardinality contract once at the rail product boundary rather than re-guarding both closed representations at every consumer.
- [ ] Calibrate `T5` quality/resource thresholds from measured baselines before any milestone asserts a quality gate.
- [ ] Correct `DESIGN.md` section 6.7 invariant 2 so D1 `QualityRelaxed` consistently records missed quality gates.
- [ ] Define the M7 degraded producer algorithm and its fixed-boundary completion proof.
- [ ] **Audit every remaining `kBranchTopologyTolerance` comparison for dimensional coherence.**
  `direction_in_incident_vertex_sector` compares a Gram **determinant** — an area-squared quantity — to
  `1e-10`. After E2/E3 the surviving uses are admissibility guards only, but their scale is arbitrary and
  mesh-size dependent. Not a CP4c-0 measure; do not fold it into CB2.
- [ ] **Sweep for other tolerant-selector / exact-consumer seams.** CP4c-0 found the pattern three times
  in one subsystem (flow classification, vertex sector, cross-edge flow). The same audit is owed wherever
  an exact authority was introduced downstream of a `double` decision.

---

Historical stable totals are **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. M3 package count is **45**. PR #8 remains open, draft, and unmerged.

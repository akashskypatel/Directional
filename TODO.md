# Directional Surface-Cell TODO

Last updated: 2026-09-02 UTC

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

**`DEFN` absorbs `REVIEW + PLAN` — user-authorized 2026-08-30.** When `DEFN` is the next step in the chain it **is**
the review-and-plan turn: one turn freezes definitions, adjudicates inherited candidates, decides gate membership,
and issues the successor's measures. Only the `REVIEW+PLAN → DEFN` edge collapses; a red TB with no `DEFN` ahead of
it still gets its own review turn.

## Current focus — `M3-CP4c-3-TB11` (artifact-only Test + Benchmark)

`M3-CP4c-3-CB13` is **COMPLETE / BUILD GREEN / DIAGNOSTIC-ONLY**. Exact compile/package source:
`3070173894ee097f631b96c1c6d29f276df89a66`. Compile run/job `33598896270 / 100148036281` succeeded across all eight standard targets with GMP/GMPXX and `runtimeExecution=false`. Immutable package **81** was created by run/job `33599637764 / 100150255983`; artifact `9834661539`, Actions SHA-256 `10e18bc81c2f850a1e7bc3d4ce16830a5d5ebe7d1992cd728c1bb043dc71cb2f`, inner tar SHA-256 `4f49b3de157e51aff05736f9ac4b210372eb4bfb4dec3ddc793869071b2f9d88`.

CB13 discharged BF0–BF9:
- [x] **BF0** selectors 374–377 recomputed/frozen; accepted 365 prefix unchanged; no runtime/gate/benchmark/package repair; GMP/GMPXX proved.
- [x] **BF1** re-derived 46 total `EmbeddedGraphTopology.cpp` emission sites and reconciled the review's 28 narrower no-reason/no-edge-or-face subset with the actual **37 reasonless-site predicate**; typed all 37 plus eight same-code sites in `GlobalTopologyPlan.cpp`: **45 sites / 53 condition names**.
- [x] **BF2** added/copied `sourceVertex`; field audit records 11 other `GlobalTopologyPlanError` fields absent from `SurfaceCutGraphError`.
- [x] **BF3** projected reason/vertex/trace/event/cut-attempt shape and found DTO consumers by search; `fail_surface_cells` is an independently named consumer.
- [x] **BF4** certification attempt index and active cut-edge count are published.
- [x] **BF5** ordinal 366's existing failure message renders the new evidence; no gate ordinal added; `MechanicalWitnessStageReachabilityIsObservable` is non-gating diagnostic-only for TB11.
- [x] **BF6** audit-by-assumption found independent repeated-code/bare-emitter and subset-projection examples outside the review's named sites.
- [x] **BF7/BF8** no topology decision, ray order, cellularity, cut proposal, admissibility, tolerance, sphere/370/saturation/folded-cone/vertex-30/finalize-contact/371-372 behavior, or selector byte changed.
- [x] **BF9** TB11 discriminators frozen in `Architecture_M3_CP4c3_TB11_Artifact_Only_Test_Benchmark_Plan.md`.

### Exact next turn

Run **`M3-CP4c-3-TB11`** artifact-only on immutable package 81. Execute selector 377 from ordinal 1, one identity per fresh process, with normal mode-preserving extraction and no repository timeout on the complete selector. Then run `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` once with zero gate credit. Do not configure, compile, relink, repair, regenerate, mutate source/test/fixture/selector bytes, or run a benchmark.

Required discriminator: ordinal 366 must name a post-CB13 `rotationSystemReason`, map to exactly one producer phase, and publish `certificationAttempt`/`certificationCutEdges`; accepted 1–365 must stay green and first red remain 366. Carried reds 367/371/372 and 368/369/370/374 retain their existing ownership unless new exact evidence proves otherwise.

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3 package count **78**; accepted authority **365/365**; CP4c-3 **OPEN**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB10 is current runtime authority at accepted prefix 365 / first red 366, now `CellularityNotEstablished/origin=RotationSystemInconsistent`. CB12 ownership is runtime-proved; exact next is independent `M3-CP4c-3-TB10-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — moved mechanical first red:** TB10 runtime-proved CB12's barrier-absorbed termination correction and closed `M3-CP4c3-TB9-REV-CAND-01`. The gating frontier is ordinal 366 in `surface-cut-graph`, at `CellularityNotEstablished/origin=RotationSystemInconsistent`. TB10-REV proved the firing site is one of **28** `RotationSystemInconsistent` emission sites that publish neither a reason nor an edge/face locus, so the underlying condition is **unavailable at the current instrumentation and the loss is producer-side** — the projection repair alone would change nothing. `M3-CP4c3-TB10-CAND-01` is owned by diagnostic-only `M3-CP4c-3-CB13` (BF0–BF9). No product semantic correction is authorized or inferable. Vertex 30 and the separate finalize/contact fall-through remain open and untouched.
- [ ] **CP4c-3 ordinals 371/372 (deferred, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor, which throws unless all five downstream products are retained. Amendment 15's barrier-cycle and Euler-cut contracts have been unmeasured from TB2 through TB10 for a reason unrelated to either. Corrective is test-only (an atlas-scoped fixture accessor, assertions byte-unchanged); deferred because clearing ordinal 366 unblocks them automatically. `M3-CP4c3-TB10-REV-CAND-01`.

- [ ] **CP4c-3 ordinal 374 (deferred, different owner):** the folded-cone AY5 witness declares a flat-star field (`effort ≡ 0`, no singularities) on a star with `Θ = 3π/2`, so the atlas rejects it with `CycleTransportMismatch`. Corrective is test-only — derive matching/effort/singularities with `directional::fields::principal_matching`, keep the exact expected-owner derivation, certify against the whole admissibility chain. Selector 374 stays byte-frozen and is **not** withdrawn. TB8 repeated this pre-classified stop; it adds no new product evidence.
- [ ] **Prescribed sphere A2a′ upstream error:** ordinal 368 is now repeatedly measured report-only at `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. AL4 still forbids a sphere semantic fix until separately reviewed.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **77** after CB12/package 80; TB10 created no package. PR #8 remains open, draft, and unmerged.

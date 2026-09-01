# Directional Surface-Cell TODO

Last updated: 2026-09-01 UTC

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

## Current focus — `M3-CP4c-3-TB6` (Test + Benchmark, artifact-only)

`M3-CP4c-3-CB7` is **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE** at semantic/evidence source
`e926ada023bc51220628be550bbe9a87f98d7067`. Report:
`Architecture_M3_CP4c3_CB7_Code_Build_Report.md`. Immutable package **75** is artifact `9781487311`
(`547f2441b026b68d2bef10e7c7694faf994be473a1d2db68a6375d06b1e654b8`), inner tar
`8814b700a5c07290ce099ce1f719f01b2fbd5bcfd80f36037fe5bafc600f7896`. No Directional runtime executed.

### What CB7 completed

- **Amendment 19 reportability:** vertex transit now distinguishes typed seed-unavailable and walk-unexamined failures and records a typed per-state outcome before every suppressing branch.
- **Amendment 18 exactness:** the transit datum no longer passes through world-space doubles; both sector predicates consume exact rational branch directions transported through atlas branch authority.
- **Amendment 17 is measurable again, not accepted:** the existing incoming-direction election remains unchanged and publishes exact representative/incoming directions, path, composed quarter-turn, and election booleans.
- **Sphere binding publication:** claimed trace/edge, carrier availability and pass are now visible; no sphere fix was made.
- **Ordinal 370 witness repaired:** it now uses the accepted production torus field while preserving empty rails/network intent; the atlas rejection itself is unchanged.
- **AU8 landed:** a minimal exact transit witness is compiled, and TB6 must run every post-first-red remainder ordinal report-only with zero gate credit.

### Exact next turn

Run **`M3-CP4c-3-TB6`** artifact-only on immutable package **75** under
`Architecture_M3_CP4c3_TB6_Artifact_Only_Test_Benchmark_Plan.md`:

1. immutable package/source/GMP/fixtures/modes/selector preflight;
2. frozen selector 373 from ordinal 1, one identity per fresh process, first-red hard stop for gate credit;
3. preserve complete typed transit diagnostics at the stopping locus;
4. after the gate verdict is fixed, execute **every remaining ordinal through 373** once report-only with zero gate credit;
5. immutable byte/mode postflight; no configure/compile/relink/repair/generated discovery/package/source/test/fixture/selector mutation or benchmark.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB5-CAND-01` — silent seed-drop implementation corrected by CB7; **runtime acceptance pending TB6**.
- [ ] `M3-CP4c3-TB5-REV-CAND-01` — float round-trip removed from transit decision path; **runtime acceptance pending TB6**.
- [ ] `M3-CP4c3-TB3-R1-CAND-01` — vertex-30 Amendment-17 election remains **MASKED / UNACCEPTED** until TB6 actually reaches/measures it.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere cause measured; CB7 binding evidence compiled; **fix still unscheduled**.
- [ ] `M3-CP4c3-TB4-DIAG-CAND-01` — invalid ordinal-370 witness repaired in CB7; **runtime confirmation pending TB6**.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — now measurable through the repaired ordinal-370 witness.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — partial; mechanical zero-unbound still owed.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — `saturationUsed=true` reconfirmed; deferred behind the mechanical gate.

**Amendment 15's Euler-cut identity and barrier-exclusion contracts (371/372) remain UNMEASURED, not falsified** pending TB6.

### Scheduled from the adversarial architecture review — `ROADMAP.md` §3b / §3b-bis, **not CP4c-3 work**

Re-evaluated under a production lens on 2026-09-01
(`Architecture_Adversarial_Review_Reevaluation_Production_Lens.md`): five of six rejections reversed after the
fixtures were measured as near-uniform, sliver-free, low-valence meshes (area ratio ≤ 3.17, max aspect ≤ 2.67, max
valence 6, ≤ 152 V) that cannot exhibit the targeted cases. **Amendments 20 and 21** declared.

- [ ] **`M4-CP-COND`** — **Amendment 20**: the conditioning stage before A0. Admissibility certification, a
  conditioned immutable source product with a certified correspondence to the raw input, typed inadmissibility.
  Sliver repair-or-refusal, near-duplicate merging, bounded-lattice quantization and field-matching repair live
  here and **only** here.
- [ ] **`M4-CP-SCALE`** — S1 expression-swell measurement, S2 certified filters, S3 exact limit-cycle detection
  with a typed `LimitCycleTermination`, S4 incremental Betti early rejection.
- [ ] **`M5-CP-REG`** — **Amendment 21**: degeneracy taxonomy, regularization policy interface, certificate
  recording of every regularization and its mapping onto the D0–D4 ladder, plus the typed index-deficit
  reconciliation contract.
- [ ] **S5** genus ≥ 2 witness (M4). **S6** input-perturbation stability, promoted to the acceptance evidence for
  the conditioning contract (M4-CP-COND).

**Witness-coverage gap — never exercised:** slivers / anisotropy; valence > 6; scale beyond 152 V; **negative-index
singularities** (all are `+1`); boundary-truncated separatrices; inadmissible input fields; genus ≥ 2; exact ties
from symmetric input. Matrix and owners in `ROADMAP.md` §3b-bis.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, semantic packages **73**.

## Superseded — `M3-CP4c-3-TB2` execution record

`M3-CP4c-3-TB2` is **COMPLETE / RED — VALID SEMANTIC FIRST-RED AT ORDINAL 366** after the user-authorized orchestration/fixture remediation. Fixture-only package **70** (artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`) preserves semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71`, the frozen selector **373**, and byte-identical package-69 binaries while adding the immutable sibling `test-data` fixture payload. R4 run `33355714664` passed package/source/GMP/selector/mapping/fixture preflight, then executed ordinals **1–365** as exactly-selected green fresh processes.

Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected exactly once and exited 1 with `InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`. This is a valid semantic first-red. Ordinals **367–373** were not executed under first-red semantics. `M3-CP4c3-TB2-ORCH-01` is **RESOLVED / NON-STABLE** by package 70 and the R4 preflight; it adds **+0 stable events / +0 recurrences**. Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative semantic packages **69**.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — the cycle-basis half is **fixed and proved**; what remains is the same
  assumption at the singularity-port consumer. Frame settled by Amendment 16; policy blocked on **AN1**, implemented
  under **AN5**.
- [ ] `M3-CP4c3-TB2-CAND-01` — **CAUSE ESTABLISHED**; pre-existing and unmasked, not a regression. Closes on ordinal
  366 green in a run reaching at least 366.
- [ ] `M3-CP4c3-TB2-REV-CAND-01` — package-70 binary identity is self-reported and unverified against package 69's
  per-binary digests; owned by **AN2**.
- [ ] `M3-CP4c3-TB2-ORCH-01` — **reopened and reclassified** as a build/packaging contract defect: the packaged
  artifact cannot locate its own fixtures. Owned by **AN3**.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — correction remains compile-green/gating; ordinal 373 is still unexecuted because first-red stopped at 366.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere remains **ACTIVE / ONE LEVEL SHORT**; ordinal 368 remains unexecuted in R4.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — ordinal 369 remains unexecuted; product correction still unaccepted.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — ordinal 370 remains unexecuted; typed-error behavior still unaccepted.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 CB5 diagnostic instrumentation is compile/package-green on semantic source `2d22ef293363058cfdca96d01158a93d2c0200f8`, immutable package **73**. No semantic runtime has consumed it. Exact next is artifact-only `M3-CP4c-3-TB4` under unchanged selector 373 plus AP6's post-first-red non-gating diagnostic pass.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** Amendments 15 and 16/P2 are both implemented and **proved effective at runtime** — the mechanical witness clears **all of A1** and ordinals 1–365 stay green through both changes. It now first-reds in **A2a** at `VertexTransitSectorUnresolved`. Cause not established; three mechanisms enumerated and discriminated by **AP2**, with **AP4** forbidding design against the leading suspicion.
- [ ] **Prescribed sphere A2a′ upstream error:** resolved to `RotationSystemInconsistent → TraceEventPositionInvalid`. AM7 instrumentation is compile-green, but ordinal 368 has never been reached — first-red has stopped at 366 in three consecutive TB runs. **AP6** proposes a non-gating diagnostic pass so 367–373 stop being invisible. No sphere product disposition may be inferred.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **71** after CB5; package labels 70 and 72 were transport/envelope corrections rather than new semantic sources. PR #8 remains open, draft, and unmerged.

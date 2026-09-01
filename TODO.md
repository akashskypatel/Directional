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

## Current focus — `M3-CP4c-3-CB9` (Code + Build, runtime-free)

`M3-CP4c-3-DEFN-R2` is **COMPLETE**. It discharged CB8-REV's **AX1–AX8**, froze the vertex-star continuation
semantics the project had never written down, proved the mechanical locus exactly, and authorized **one** bounded
successor. Record: `Architecture_M3_CP4c3_DEFN_R2_Frozen_Definitions.md`. Nothing was executed, compiled, packaged
or mutated; selector **373** stays byte-frozen and **selector 374 still does not exist**.

### What DEFN-R2 froze

- **Amendment 22 — continuation is the straightest geodesic of the intrinsic vertex star.** One exact
  arrival-anchored ray (pointing *back* along the incoming trace), written once by A2a branch continuation; the
  admissible fan developed isometrically into one chart; continuation at `β = α + Θ/2` where `Θ` is the cone angle;
  the **unchanged** exact half-open sector convention applied to developed sectors; one typed certificate.
  Choosing `Θ/2` over `π` is the substance — it makes a non-flat star's gap/overlap **impossible** rather than
  adjudicated, and coincides with the ordinary straight line wherever `Θ = 2π`. A1 is not redefined: `signedLift`
  maps a branch label and is never a ray transform. Every candidate-local direction is demoted to audit data.
- **Amendment 23 — publish the budget.** The exact election is the sign of a sum of arccosines, degree up to `4^k`
  in fan length. Admissible only with a certified filter, an *implemented* exact fallback (the only path that can
  decide a continuation lying exactly on a radial ray), and a **declared budget** with a typed fail-closed state.
- **Typed states:** boundary-ray (decided by the existing convention, recorded as `onRadialRay`),
  `VertexStarTruncatedBeforeContinuation` (open fan — reported, never restored by crossing a barrier), and
  `VertexStarDegenerateSector` (reported at A2a with its locus; repaired only at the conditioning stage).

### The mechanical proof — vertex 30, exact

By rational identities over the committed fixture, with no factorization and no floating point: rows 43 and 218 are
exact right angles (`u·w = 0`), and `θ₂₀₉ + θ₂₀₈ = π/2`, `θ₄₁ + θ₄₀ = π/2` exactly
(`D₁D₂ ≥ 0 ∧ (D₁D₂)² = Q₁Q₂`). Hence **`Θ(v30) = 2π` exactly** — CB8-REV's explicitly non-authoritative float
observation is now a proof. The developed sectors give `sector(209) ∪ sector(208) = [π, 3π/2)`, which contains the
continuation of every `FaceInterior` seed from arrival face `(24,30,32)`. **Owner = row 209 `(30,119,123)` if
`α < θ₂₀₉`, else row 208 `(30,31,119)`; `α = θ₂₀₉` is the exact boundary-ray case. Row 41 `(25,30,31)` is
unreachable by any continuation** — so one of the two faces the current code elects is wrong about the surface, a
strictly stronger result than the cardinality argument the checkpoint has run on since TB4.

### Exact next turn

Run **`M3-CP4c-3-CB9`** — Code + Build, **runtime-free**, GMP/GMPXX linked — under **AY0–AY9**:

1. **AY1** the seed, written once per arrival event, sign and chart as frozen.
2. **AY2** the development and election, with `direction_in_vertex_sector` **unchanged** and applied to developed
   sectors; remove `incomingDirection = nextPairing->direction` and every per-candidate representative from the
   decision path, retaining them as audit rows.
3. **AY3** the certified filter, the *implemented* exact fallback, and the published budget (≥ 16).
4. **AY4** the typed states, each recorded **before** any conditional that can skip a state (Amendment 19).
5. **AY5** derive and commit the falsifying folded-fan witness; prove in the report that it fails under the old
   mechanism and passes under the frozen authority. Vertex 30 alone cannot discriminate the semantics — it is
   intrinsically flat — so a `Θ ≠ 2π` witness is required too.
6. **AY6** append ordinal **374** *only* if AY5 falsifies; otherwise report and stop. Selector 373 keeps every byte.
7. **AY7** implement §AX8's audit contract **and extend the `RemeshDiagnostics` projection in the same change** —
   this is the closure of `M3-CP4c3-TB6-CAND-01`.
8. **AY8** audit by assumption: *"a value reaching a topological decision was re-expressed by its consumer"* and
   *"an exact computation has no declared bound on its input size."*

**AY9 prohibits:** any floating-point step in the decision chain including `from_double_exact` of a transported
value; treating `signedLift` as a ray transform; deciding from a candidate's own representative; candidate
ordering, nearest-angle, seams or **any** tolerance; changing the half-open convention, the `FaceInterior` rule or
barrier/boundary truncation; inventing a port or face; repairing degenerate input geometry at A2a; publishing an
owner without its certificate; stubbing the exact fallback or shipping an unpublished budget; touching ordinal 370,
the sphere or saturation; reopening Amendments 12–23; changing any selector byte beyond the one authorized append;
and executing runtime, running a gate or benchmarking in a CB turn. **If the exact fallback cannot be implemented
within the frozen semantics, CB9 stops and reports** — a second architectural stop is a valid outcome, a tolerance
is not.

### CP4c-3 open items

- [ ] `M3-CP4c3-TB3-R1-CAND-01` — **ACTIVE / SEMANTICS FROZEN**; the expected answer at the measured locus is now
  known exactly. Owned by AY1–AY3.
- [ ] `M3-CP4c3-TB6-CAND-01` — **ACTIVE / CONTRACT FROZEN**; §AX8 fixes what the projection must publish, AY7
  closes it at the projection boundary.
- [ ] selector governance — selector 373 immutable; ordinal 374 conditional on AY5's falsification.
- [ ] `M3-CP4c3-DEFN-R2-CAND-01` — **NEW**; an exact computation with no declared bound on its input size.
  Amendment 23 requires a published budget and a typed state; AY8's second predicate sweeps for other instances.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — empty-network product red; deferred, untouched by this turn.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere `NoCarrierMatch / SourceEdgeUnavailable`; deferred, AL4 binding.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — `saturationUsed=true`; deferred quality/coverage debt.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — partial; mechanical zero-unbound proof still owed.

Stable accounting: **44 events / 14 categories / 30 recurrences**; debt **5**; semantic M3 packages **73**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 TB6 preserves the accepted 365-prefix but remains RED at ordinal 366. CB8 triggered its AW1 architectural stop because current products lack exact/certified one-ray projection across a non-coplanar fan. Exact next is combined `M3-CP4c-3-DEFN-R2`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** TB6 preserves the accepted 365-prefix and first-reds ordinal 366 at `VertexTransitSectorUnresolved`, source vertex 30, with two published faces. CB8 stopped before semantic editing because current source/atlas authority has no exact/certified arbitrary-ray projection across the non-coplanar fan. Owned next by `DEFN-R2` AX1–AX6; no candidate-order, tolerance, float-transport, `signedLift`-as-ray, target-representative shortcut, or undefined cone continuation.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **73** after CB7/package 75. PR #8 remains open, draft, and unmerged.

# Directional Surface-Cell TODO

Last updated: 2026-09-07 UTC

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

## Current focus — `M3-CP4c-3-CB42` (Code + Build, runtime-free) — MEASUREMENT ONLY

`M3-CP4c-3-TB36-REV` promoted TB36 to **current valid semantic runtime authority**:

- selector **409**, **402 PASS / 7 RED**, **accepted 1–365 = 365/365**, RED `366,367,368,369,370,374,398`;
- immutable CB41 package `10029250324` / source `14aa1368523580444929bc65cab0b65449240ec2`; run `34153857590`;
- certified ownership **300 / 0 / 0**; ordinals 312, 390, 393, 404, 406, 407, 408, 409 all PASS.

**The provenance contract is runtime confirmed, in both directions.** 366/367 advanced past `ClosedBeforeEnd` on
`regionBoundaryProvenance=FaceWalkOrbit` — CX8's falsifier, not triggered — while ordinals 312/409, which mutate a
**copy** of a real plan region, stayed PASS on `Unguaranteed`. `M3-CP4c3-TB35-REV-CAND-01` is **CLOSED / RUNTIME
PROVED**.

**The frozen CX5 measurement was in the wrong domain.** It censuses the **network graph**
(`NetworkArcId`/`NetworkNodeId`) while χ counts a **sub-mesh of whole source triangles**, and a network arc may be
a trace chord that is not a source edge at all. `22 = 22` says nothing about whether the boundary terms cancel.

**The open question reduces to one integer.** With `B_int` = barrier edges having both faces in the region and `X`
= sub-mesh vertices excluded from `interiorVertices`, **χ_true = X + B_int − 47**. Published χ = −3 means
`X + B_int = 44` — premise holds, region is **not** a disc. A disc needs 48 — premise false by exactly 4. **The
certificate cannot both cancel its boundary terms and certify discs.** New candidate
`M3-CP4c3-TB36-REV-CAND-01`.

Stable accounting remains **45 events / 14 categories / 31 recurrences** — no accepted green was lost, so **no new
event** — produced-witness debt **5**, semantic M3 package count **101**. CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB42`**, a runtime-free **Code + Build** turn under **CY6.1–CY6.6**. **Diagnostics only:**

- [ ] **CY6.1** publish `regionInteriorBarrierEdgeCount` (`B_int`) and `regionExcludedVertexCount` (`X`), with `X`
      split into mesh-boundary / `boundaryVertices` / `allOwned` causes;
- [ ] **CY6.2** publish the **sub-mesh** boundary counts in their own domain — source edges with exactly one
      incident face in the region, and their distinct source vertices;
- [ ] **CY6.3** publish `V_total`, `E_total` and `chiFull` beside the reduced value, **without changing the formula
      or forcing χ to 1**;
- [ ] **CY6.4** mark the network census as network-domain; retire or flag the redundant occurrence field;
- [ ] **CY6.5** keep ordinals 312/409 byte-identical and selector 409 byte-frozen; grep the corpus for
      `RegionEulerCharacteristicNotOne` first;
- [ ] **CY6.6** hand off to `M3-CP4c-3-TB37`.

**Must not:** correct the Euler formula, region construction or disc acceptance; decide the frontier from the
network census; publish a predicted χ for the mechanical fixture; weaken ordinal 398; touch 368/369/370/374;
re-open ownership or any retired guard. **Accepted prefix 365/365 and ordinals 312/409 PASS are stop conditions,
and since CB42 adds diagnostics only, any behaviour change at all is a defect in the turn.**

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted.
  CP4c-3 remains open. **`M3-CP4c-3-TB36` is the current valid semantic runtime authority** at **402 PASS / 7 RED**, accepted 365/365 on selector409 / package101. The provenance contract is runtime proved; the Euler question reduces to `χ_true = X + B_int − 47`, which the frozen network-domain census could not measure. Exact next is runtime-free **`M3-CP4c-3-CB42`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 region-frontier runtime proof:** source-face ownership is closed at last-runtime **300 / 0 / 0**.
  TB35-REV adjudicated the recovered prefix and proved the 366/367 frontier is provenance blindness. Part IX froze the correction. CB41 has now implemented and compiled exact derived face-walk provenance in package101 and added measurement-only evidence for the separate Euler frontier; TB36 owns the runtime verdict.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [x] **CP4c-3 ordinal 391 diagnostic dependency:** TB22 ordinal 391 PASSes; sphere is explicitly skipped with `reason=ordinal368-open` while mechanical/torus evidence runs. `M3-CP4c3-TB21-CAND-02` is CLOSED / runtime proved / non-stable.

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

Current totals remain **45 events / 14 categories / 31 recurrences**; produced-witness debt remains **5**. Authoritative M3 package count is **101**. **`M3-CP4c-3-TB36` is the current valid semantic runtime authority at 402 PASS / 7 RED, accepted 365/365 on selector 409**, promoted at TB36-REV. Exact next is runtime-free `M3-CP4c-3-CB42` under CY6.1–CY6.6, measurement only. PR #8 remains open, draft, and unmerged.

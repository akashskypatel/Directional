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

## Current focus — `M3-CP4c-3-CB43` (Code + Build, runtime-free) — CORRECT THE EULER CRITERION

`M3-CP4c-3-DEFN-R6` appended **Part X**. Runtime authority is unchanged:

- selector **409**, **402 PASS / 7 RED**, **accepted 1–365 = 365/365**, RED `366,367,368,369,370,374,398`;
- immutable CB42 package `10032277517` / source `89cbf1ff5e2b064a0a4652c6cdb9e32b6f4b001d`; run `34161464783`;
- certified ownership **300 / 0 / 0**; ordinals 312, 390, 393, 404, 406, 407, 408, 409 all PASS.

**The cancellation premise is NOT the defect.** The sub-mesh boundary cancels exactly, 20 against 20. **The defect
is that a barrier edge with both incident faces in the region is an interior cell being classified as boundary**:
12 such edges are dropped from `E_int` against 16 vertices from `V_int`, and `(20 − 20) + (16 − 12) = 4` is the
whole error. Measured `V/E/F/chiFull = 136/385/250/1` — **the region is a disc.**

**Part X freezes:** the certified complex is the **whole-face source sub-mesh** (so `χ = 1` is about that
rounding, not the traced region); the criterion is **`χ = V_total − E_total + F = 1`**, reduced form withdrawn;
the premise has **two** comment sites and both must go; `vertexCount`/`edgeCount` must not be repurposed because
`edgeCount` feeds the connectivity BFS; and reduced/full agree iff `X = E_one + B_int`, **which CB43 must prove
per region on every accepted fixture rather than assume**.

Stable accounting remains **45 events / 14 categories / 31 recurrences**, debt **5**, packages **102**. CP4c-3
remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB43`**, a runtime-free **Code + Build** turn under **CZ7.1–CZ7.7**:

- [ ] **CZ7.1** hoist CB42's sub-mesh accumulation out of the `eulerCharacteristic != 1` failure branch;
- [ ] **CZ7.2** add `V_total`/`E_total` certificate fields and compute χ from them;
- [ ] **CZ7.3** delete **both** premise comments — `GlobalTopologyPlan.cpp:2097–2098` and
      `include/directional/geometry/GlobalTopologyPlan.h:91–93`;
- [ ] **CZ7.4** discharge the `X = E_one + B_int` obligation **per region on every accepted fixture**;
- [ ] **CZ7.5** state the certificate-ordering / plan-hash decision and confirm by grep that no identity pins a
      hash literal;
- [ ] **CZ7.6** keep ordinals 312/409 byte-identical, selector 409 byte-frozen, region construction unchanged;
- [ ] **CZ7.7** hand off to `M3-CP4c-3-TB38`.

**Must not:** correct region construction; change ownership or the whole-face rounding; repurpose
`vertexCount`/`edgeCount`; weaken `proves_disc_topology()`; force χ to 1 or special-case a fixture; delete only one
premise comment; weaken ordinal 398; touch 368/369/370/374; change any accepted identity or selector byte.
**Accepted prefix 365/365 and ordinals 312/409 PASS are stop conditions.**

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
  CP4c-3 remains open. **`M3-CP4c-3-TB37` is the current valid semantic runtime authority** at **402 PASS / 7 RED**, accepted 365/365 on selector409 / package102. TB37 decided the Euler question: the region is a disc (`chiFull=1`) and the reduced certificate is wrong by exactly 4. Part X is frozen; exact next is runtime-free **`M3-CP4c-3-CB43`** under CZ7.1–CZ7.7.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 region-frontier runtime proof:** source-face ownership is closed at last-runtime **300 / 0 / 0**.
  TB36 proved the derived provenance contract; TB37 decided the Euler frontier. The certificate misclassifies interior barrier edges as boundary, dropping 12 edges against 16 vertices and rejecting a genuine disc. `DEFN-R6` writes the criterion; `CB43` implements it under a per-region equivalence proof on every accepted fixture.
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

Current totals remain **45 events / 14 categories / 31 recurrences**; produced-witness debt remains **5**. Authoritative M3 package count is **102**. **`M3-CP4c-3-TB37` is the current valid semantic runtime authority at 402 PASS / 7 RED, accepted 365/365 on selector 409**, promoted at TB37-REV. Part X is frozen; exact next is runtime-free `M3-CP4c-3-CB43` under CZ7.1–CZ7.7. PR #8 remains open, draft, and unmerged.

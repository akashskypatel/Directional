# Directional Surface-Cell TODO

Last updated: 2026-09-03 UTC

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

## Current focus — `M3-CP4c-3-CB24` (Code + Build, DIAGNOSTIC-ONLY)

`M3-CP4c-3-TB21-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB21_Independent_Review_Record.md` (**BX0–BX8** discharged, static only).

**TB20-REV's non-cellularity conclusion is WITHDRAWN.** The census it ordered proves the mechanical actual
embedded complex is **cellular**: `V=22, E=26, F=6, componentCount=1, chi=2, residual=0`, every face certified a
disc. Part I §3's "the network is not a cut graph" is an **implication with a premise** - Part I establishes
non-cellularity for the torus independently, from `V = E = 48` and `chi = 0`. TB20-REV applied the conclusion
without carrying the premise. There is **no normative conflict between documents**; the conflict was with a
misreading.

- **The two constructions count different objects.** `certify_actual_embedded_graph` + `proves_cellularity()`
  (`SurfaceCutGraph.cpp:451,478`) count nodes/arcs/face-walk orbits of the **embedded graph on the surface**, whose
  faces are bounded by arcs running through triangle interiors, and require every face to prove disc topology.
  `GlobalTopologyPlan.cpp:1102-1165` joins whole **uncut source triangles** across source edges not in
  `componentBarriers`. The second is a **projection** of the first. **Neither validates the other.**
- **The unstated contract.** The projection is faithful only if *every pair of adjacent uncut source triangles
  lying in different certificate faces is separated by an edge in `componentBarriers`*. Cellularity does not imply
  it; no construction states or checks it. **That is the real defect surface.**
- **Two readings, opposite corrections.** Component 0's complete boundary attribution is **orbit 0 -> 81 edges,
  orbit 1 -> 1, orbit 3 -> 1**, plus 14 barrier/no-seed, over 97 edges - one dominant orbit and two single-edge
  outliers. Either those two edges genuinely separate certificate faces and the barrier set is missing them, or
  two seed reads are wrong at `:1130-1140`.
- **The deciding rows already exist in the artifact.** TB20's first-64 window showed 44/1/1 and TB21's complete
  census shows 81/1/1, so **both minority rows lie inside the retained window** with edge key, owner count,
  barrier class and seed captured - and were summarized into counts by the report. **No new measurement is
  required**, only retention and projection by *distinctness*. Raising the 64/97 cap would be the wrong fix.
- **371 and 372 PASS** and `M3-CP4c3-TB10-REV-CAND-01` **closes / runtime proved**; the atlas accessor stays
  test-only and never becomes product authority.
- **Ordinal 391 is a self-inflicted diagnostic RED** - its sphere half needs `sphere.cutGraph` and hits the owned
  368 surface, because BW4 required one census witness to span all three witnesses. BY7 re-scopes it; no sphere
  product surface is touched.
- **`M3-CP4c3-TB20-REV-CAND-02` is downgraded to a formal documentation gap.** Its substantive argument rested on
  non-cellularity and does not survive; CB21 corrected a real unsoundness and **is not reverted**. Parts IV/V's
  written prohibition remains unlifted - owner: a DEFN turn.

368/369/370/374 unchanged under their existing owners. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB24`** under §10 **BY0–BY9** of
`Architecture_M3_CP4c3_TB21_Independent_Review_Record.md`. **No product semantic change.**

- [ ] **BY0** — selector 391 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BY1** — retain boundary rows **by distinctness**: one per distinct seed orbit and per distinct
      `noSeedReason` before filling the budget in order.
- [ ] **BY2** — publish the minority-orbit rows in full, including **which rule produced each seed**.
- [ ] **BY3** — attribute each minority edge's two sides to certificate faces.
- [ ] **BY4** — publish the **projection faithfulness residual**; zero or non-zero decides the owner.
- [ ] **BY5** — one witness per new field plus an unrelated-error regression witness.
- [ ] **BY6** — append the next selector **named by its identity count**; regenerate the selector manifest.
- [ ] **BY7** — re-scope ordinal 391 so the sphere half cannot red the mechanical/torus halves.
- [ ] **BY8** — **no product semantic change**; guard, barrier set, partition, `seedOrbits`, seed rule,
      `edgeOrbitEvidence`, face walk, rotation system, region drafts, CB21's comparison, `proves_cellularity()`
      and the certificate stay untouched; `localFragmentCount` stays non-fatal.
- [ ] **BY9** — publish the six `M3-CP4c-3-TB22` discriminators, chiefly the faithfulness residual and 391 green.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **86**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB21/selector391 is current runtime authority** at 384 PASS / 7 RED and accepted 365/365. Exact next: static independent **`M3-CP4c-3-TB21-REV`** under BX0–BX8.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 topology-authority contradiction:** TB21 preserves `UncutFaceComponentOrbitSeedNotUnique / component 0 / Multiple / seeds [0,1,3]` while the actual `SurfaceCutGraph` certificate reports `V=22,E=26,F=6,χ=2,residual=0` and proves cellularity. Exact owner is `M3-CP4c-3-TB21-REV` BX1–BX4; no guard/certificate correction is pre-authorized. `M3-CP4c3-TB21-CAND-01`.
- [x] **CP4c-3 ordinals 371/372 test coupling:** TB21's atlas-scoped accessor makes both identities execute their unchanged assertions and **PASS**. `M3-CP4c3-TB10-REV-CAND-01` is CLOSED / runtime proved.
- [ ] **CP4c-3 ordinal 391 diagnostic dependency:** the prescribed-sphere half cannot compare Euler census because `sphere.cutGraph` is unavailable at the existing ordinal-368 `CellularityNotEstablished` surface. Keep separate from the mechanical contradiction. `M3-CP4c3-TB21-CAND-02`.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **85**. **TB20/selector385 is current runtime authority: 380 PASS / 8 RED, accepted 365/365; the mechanical component seed branch is `Multiple` with count 3 and orbits `[0,1,3]`.** Exact next is planning-only `M3-CP4c-3-TB20-REV`. PR #8 remains open, draft, and unmerged.

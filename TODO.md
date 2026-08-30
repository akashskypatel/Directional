# Directional Surface-Cell TODO

Last updated: 2026-08-30 UTC

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

## Current focus — `M3-CP4c-3-CB1` — phase-1 instrumentation, no product fix

`M3-CP4c-3-DEFN` is complete and, under the new cadence, was also the review/plan turn:
`Architecture_M3_CP4c3_DEFN_Frozen_Definitions.md`. Measures **AK0–AK9**.

**`M3-CP4c-2` remains CLOSED / ACCEPTED at 365/365** — accepted source
`57444781af7bdc460e38cc68930a9a8c8199eeea`, package `9736088354`, selector 365 SHA-256
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

### The DEFN's four decisions

1. **`IncompleteCycleBasis` is a seven-way collapse.** Read at source, `src/authority/FieldTransportAtlas.cpp`
   returns that one code from **eight** sites (`:1597, :1613, :1673, :1682, :1688, :1700, :1751, :1818`) for seven
   distinct conditions, and **five of them publish nothing but a region id**. Site `:1682` is literally "no
   `FieldTransportAdjacency` for a cycle's edge" — the phrase `ROADMAP.md` uses for CP4c-3's parent responsibility —
   so the roadmap points at one site among seven that has never been confirmed. **No diagnostic has ever been run on
   the mechanical witness.** This is `LESSONS.md` 57 recurring in A1, and CP4c-2 paid eight turns for the identical
   pattern at `topology_error`. Instrument before designing.
2. **The prescribed sphere IS in CP4c-3's gate** (AJ2 discharged). It has sat outside two consecutive frozen gates;
   it is the only witness that cannot reach A2b at all, and A2b is what M4 builds on; and its problem (b) is
   directly coupled to `R10-CAND-01`, which CP4c-3 already owns. Adding a gated **witness** is not reallocating a
   **criterion** — `ROADMAP.md`'s C1/C3/C6→CP4c-2, C2→CP4c-3 allocation is untouched.
3. **`R8-CAND-02` decided, not deferred a third time:** an empty network on a closed surface is **rejected with a
   typed error**. A2a′ adds cuts to an existing network; cutting from scratch would make it the producer of the
   whole embedded graph, which is A2a's single-writer authority, and a "certified" plan from a witness with no
   field-aligned content is the vacuous-green shape `LESSONS.md` 64r warns about.
4. **Two phases against one frozen gate.** Phase 1 instruments (AK1–AK3); phase 2 fixes on measured causes
   (AK4–AK6). Ordering within phase 2 is a phase-1-review decision, since the measured causes may share a locus.

### CP4c-3 gate authority — selector 367, frozen

`.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_367.txt`, whole-file SHA-256
`ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`. Accepted 365 plus:

- **366** `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath` — criterion **C2**;
- **367** `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` — criterion **C3**'s full form,
  binding torus **and** mechanical, honouring DEFN-R2 §7.3's commitment to move the mechanical half to CP4c-3.

`head -355`, `head -357`, `head -361` and `head -365` all reproduce their frozen hashes, so `first_red_ordinal`
stays comparable across the whole CP4c arc. Both appended identities are **red today** — correct for a
required-green selector. `selected_gate=NONE`; `gate_execution_authorized=false`.

**To be appended by AK7, producing gate 370** — named now so they cannot be silently omitted:
`GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`,
`SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`,
`SurfaceCutGraph.EmptyNetworkOnClosedSurfaceIsRejectedWithTypedError`.

### CB1 scope — AK0–AK3, instrumentation only

- **AK1** add an optional **enumerated-reason** provenance field to `FieldAtlasBuildError` identifying which of the
  eight sites fired, populate all eight, and print it. **Additive only:** no re-mapping, no enum renumbering, no new
  `FieldAtlasBuildErrorCode` value. This is AF0's template applied to A1. Use an enumerated reason, **not a line
  number** — `LESSONS.md` 62's stale `419/437/474` labels are the counter-example.
- **AK2** publish the local-region-mesh shape for **every** region of the mechanical witness: `V/E/F`, computed
  `eulerCharacteristic`, `boundaryLoopCount`, `genus`, `interiorLocalVertices.size()`, `expectedCycleCount`, and the
  actual `bundle.cycles.rows()` / `cycleCurvatures.size()` / `innerAdjacencies.size()`. The site alone will not
  explain a count mismatch; the counts will.
- **AK3** print the sphere's `RotationSystemInconsistent` at **nine-way** granularity through the existing frozen
  non-gating sphere diagnostic. No product fix for the sphere in phase 1.
- **AK8** every "every consumer / every site / every region" measure requires the implementer to produce the
  enumeration by **search** and publish it; the DEFN's eight-site table is a cross-check to compare against
  afterwards, never to copy (`LESSONS.md` 59, 61).

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **67**.
`selected_r2_branch=NONE`.

### CP4c-3 open items

- [ ] **C2 / the mechanical witness** — A1 `IncompleteCycleBasis`, site unknown among seven. AK1/AK2, then AK6.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere, **now gated**. (a) producer `RotationSystemInconsistent` at
      source face `25-27-28` before cut selection; (b) independently non-cellular pre-cut
      (`V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`). Fixing (a) does not fix (b). AK3, then AK6.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — model trace crossings as **per-face chords** in the proposal heuristic so the
      ordinary tree–cotree path can reach them. Heuristic only; Amendment 14 is not reopened. AK4.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — implement decision 3 with a **new, appended** error code. AK5.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted; R10 closed CP4c-2 at **365/365** on immutable package `9736088354`, with criteria C1/C3/C6 green. CP4c-3 is **unblocked** and inherits three items — the prescribed sphere, Amendment 14's unexercised ordinary proposal path, and the zero-node/zero-arc question. `M3-CP4c-3-DEFN` froze CP4c-3's gate at **367**, put the sphere **in** the gate, and decided `R8-CAND-02`. Exact next is `M3-CP4c-3-CB1` under AK0-AK3, instrumentation only.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-2 R10 review:** EXEC is valid **365/365 GREEN**; review must interpret AI2 fragment/orbit evidence and AH6 saturation-only coverage, disposition candidates, and decide CP4c-2 acceptance eligibility without altering the executed package.
- [ ] **Prescribed sphere A2a′ upstream error:** AF0 now publishes `originatingTopologyError=RotationSystemInconsistent` at source face `25-27-28`; review the exact rotation-system locus before any product fix.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative M3 package count is **67**. PR #8 remains open, draft, and unmerged.

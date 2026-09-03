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

## Current focus — `M3-CP4c-3-CB23` (Code + Build, DIAGNOSTIC-ONLY + test decoupling)

`M3-CP4c-3-TB20-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB20_Independent_Review_Record.md` (**CW0–CW9** discharged, static only).

The branch is measured and the guard is normative.

- **Branch confirmed without inference.** `uncutFaceComponent=0`, `seedCount=3`, `seedState=Multiple`,
  `sourceFaceLocusKind=FirstUnlabeledFaceInIterationOrder`; component census `faceCount=191, seedOrbits=[0,1,3],
  seedOrbitsTruncated=false`; global census 9 rows untruncated. Both TB19-REV predictions hold.
- **Normative authority already adjudicates the guard and rules it CORRECT.**
  `M3_CP4c_Frozen_Definitions.md` **Part I §3**, on this exact construction and line: the rule "requires each
  resulting component to receive **exactly one** orbit seed from its labeled neighbours ... **The error code is
  correct and the producer is behaving correctly. There is no bug at that line.** It is reporting a missing
  input." The missing input is that **the network is not a cut graph of the surface**. **Parts IV and V** prohibit
  relaxing `proves_cellularity()`, the fragment-count invariant, or this guard; **Part VI** is vertex-star scoped
  and lifts none of them. **No correction is authorized at the guard.**
- **New information: the class now appears on a GENUS-0 witness.** Part I proved it for the torus from `chi = 0`
  and `E = V = 48`. The mechanical witness is closed with `chi = 2`, where that argument does not apply.
- **The bounded boundary evidence is sufficient; the missing datum is different and far smaller.** The 33
  unretained rows cannot change anything - `seedOrbitCount=3` is explicitly untruncated and more rows could only
  add orbits. What is missing is the **embedded graph's own `V`, `E` and connected-component count**, which decide
  cellularity by `V - E + F = chi` exactly as Part I decided the torus. TB19's "26 arcs" is the fragment-owner
  trace-arc census, not the graph's `E`. **No further boundary retention is warranted.**
- **371/372 decoupling is AUTHORIZED.** The two-consecutive-TB trigger fired, and the deferral reasoning has
  inverted: the frontier is architectural, not about to clear.
- **Escalated:** `M3-CP4c3-TB20-REV-CAND-02` - CB21 weakened the fragment-count invariant, which Parts IV and V
  prohibit, and TB18-REV authorized it without consulting those lists. Not reverted (CW5 binds the successor to
  preserve CB21); only a definition-level turn may resolve it.

368/369/370/374 are unchanged under their existing owners. **There is still no vertex-30 discriminator.**

**Selector convention break, recorded:** every selector file 357-384 is named by its identity count; the current
gate file is named 385 and holds **388**. Its bytes are frozen and correct - **do not rename it** - but never
derive a count from a selector filename.

### Exact next turn

Run **`M3-CP4c-3-CB23`** under §10 **BW0–BW9** of
`Architecture_M3_CP4c3_TB20_Independent_Review_Record.md`. **No product semantic change.**

- [ ] **BW0** — gate selector byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BW1** — publish the embedded graph's own `V`, `E`, `F` and connected-component count.
- [ ] **BW2** — publish `chi(S)` and the per-component residual `V - E + F - chi`, deciding cellularity.
- [ ] **BW3** — the failing component's per-orbit boundary attribution, bounded. **No extra boundary retention.**
- [ ] **BW4** — carry the census to the torus and prescribed-sphere paths.
- [ ] **BW5** — one witness per new field plus an unrelated-error regression witness.
- [ ] **BW6** — append the next selector **named by its identity count**; restate the convention.
- [ ] **BW7** — the **test-only** 371/372 atlas-scoped accessor: assertions byte-unchanged, selector membership
      unchanged, no product source touched.
- [ ] **BW8** — **no product semantic change**; the guard, barrier set, partition, `seedOrbits`,
      `edgeOrbitEvidence`, face walk, rotation system, region drafts, CB21's comparison and `proves_cellularity()`
      stay untouched; `localFragmentCount` stays non-fatal.
- [ ] **BW9** — publish the six `M3-CP4c-3-TB21` discriminators, chiefly that cellularity is decided and that
      371/372 execute their own assertions for the first time.

**The turn after TB21 is expected to be a definition turn**, owning both the cut-graph contract and
`M3-CP4c3-TB20-REV-CAND-02` (CB21's weakening of a prohibited invariant).

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **85**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB20/selector385 is current runtime authority** at 380 PASS / 8 RED and accepted 365/365. Exact next: planning-only **`M3-CP4c-3-TB20-REV`** under CW0–CW9.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — region ownership frontier:** TB20 runtime-proves the current mechanical branch is **`UncutFaceComponentOrbitSeedNotUnique / component 0 / seedState=Multiple / seedCount=3 / seedOrbits=[0,1,3]`**. The iteration-order source-face locus remains `(0,1,2)` and is non-discriminating. Exact owner is `M3-CP4c-3-TB20-REV` under CW1–CW4; vertex 30 and finalize/contact remain separate and untouched.
- [ ] **CP4c-3 ordinals 371/372 (trigger reached, test-coupling):** both read only `fixture.atlas`, yet abort in the shared `cp4c_mechanical_fixture()` constructor. TB19 and TB20 are now two consecutive TB turns with the same downstream `UncutFaceComponentOrbitSeedNotUnique` mechanical frontier, so the standing trigger is met. TB20-REV must adjudicate the already-specified test-only atlas-scoped accessor without changing their assertions or selector membership. `M3-CP4c3-TB10-REV-CAND-01`.

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

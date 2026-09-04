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

## Current focus — `M3-CP4c-3-CB25` (Code + Build, DIAGNOSTIC-ONLY)

`M3-CP4c-3-TB22-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB22_Independent_Review_Record.md` (**BZ0–BZ8** discharged, static only).

**Both CB24 measurements are vacuous - proved statically, not inferred.** BZ2 said not to accept a diagnostic's
name as its proof; neither diagnostic measures what its name says.

- **The faithfulness residual is a structural zero.** `GlobalTopologyPlan.cpp:1362-1389` requires an edge to be in
  `certificateSeparatingSourceEdges` **and not** in `componentBarriers`. That first set is populated only from
  Mandatory and Cut arcs (`:1191-1200`), whose source edges are exactly `mandatoryEdges` (`:674`) and `cutEdges`
  (`:649`), and `componentBarriers = mandatoryEdges u traceTouchedEdges u cutEdges` (`:1114-1116`). **The subset
  relation makes the conjunction empty; the loop body never executes.** `residual=0, witnessCount=0` on every
  mesh, unconditionally.
- **The certificate columns are the seed, re-printed.** `certificate_side_orbit` (`:1172-1184`) returns
  `edgeOrbitEvidence[(face,edge)]` when unique, else `fragmentOrbits[face]` when size 1 - the same two lookups the
  seed rule uses - and the component side is **assigned equal** to the labeled side (`:1272-1278`). The `3/3` and
  `1/1` agreement is a **tautology**: one value, computed once, displayed three times.
- **Two producers; the shipped path calls the wrong one.** `certificateSideOrbitsByEdge` (`:1204-1212`) *is*
  genuinely certificate-derived from `walk.orbitByDart`, but it is consulted **only** inside the unreachable
  residual loop.
- **The seed asks the wrong question.** `edgeOrbitEvidence` records a dart side of a chord in the **labeled
  neighbour** - evidence about that triangle's interior arrangement, not about which certified face the **uncut**
  triangle across the edge belongs to. The uniqueness guard is **preserved** as a safety property; `[0,1,3]` is
  fixture-specific and must not drive a general rule.
- **No correction is authorized.** Not a seed-rule CB (the causal claim still needs the certificate attribution
  that was never measured), not a DEFN (the definitions are not ambiguous; the code never asks the certificate),
  not a barrier-set change. **Both branches of `M3-CP4c3-TB21-CAND-01` remain live.**

**These were my own measures.** BY3 said "attribute each minority edge's two sides to certificate faces" and BY4
said "publish the projection faithfulness residual". Neither named its source of truth or stated a falsifiability
condition, so both were satisfiable without measuring anything. CA1-CA3 and CA6 fix that.

**371/372/391/392/393 all pass**; `M3-CP4c3-TB21-CAND-02` **closes / runtime proved**. 368/369/370/374 unchanged
under their existing owners. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB25`** under §8 **CA0–CA9** of
`Architecture_M3_CP4c3_TB22_Independent_Review_Record.md`. **No product semantic change.**

- [ ] **CA0** — selector 393 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **CA1** — derive certified faces **from the certificate**; retire or rename `certificate_side_orbit`.
- [ ] **CA2** — measure both sides of each minority edge **independently**; never assign one from the other.
- [ ] **CA3** — replace the residual with a satisfiable one; publish **examined** and **differing** counts
      separately.
- [ ] **CA4** — publish the failing component's certified-face multiset, bounded.
- [ ] **CA5** — one witness per new field plus an unrelated-error regression witness.
- [ ] **CA6** — **every new diagnostic must be falsifiable**, with a witness that exercises the variation;
      supersedes ordinal 393's contract.
- [ ] **CA7** — append the next selector **named by its identity count**; regenerate the selector manifest.
- [ ] **CA8** — **no product semantic change**; seed rule, guard, barrier set, partition, `seedOrbits`,
      `edgeOrbitEvidence`, face walk, rotation system, region drafts, CB21's comparison, `proves_cellularity()`
      and the certificate stay untouched.
- [ ] **CA9** — publish the six `M3-CP4c-3-TB23` discriminators, chiefly a **non-zero examined-pair count** and
      the certified-face multiset that names the live branch.

**No further diagnostic turn is authorized on this surface after TB23.**

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **87**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB22 is current runtime authority** at 387 PASS / 6 RED and accepted 365/365 on package 87 / selector393. Exact next: independent static **`M3-CP4c-3-TB22-REV`**.

- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 source-face seed/ownership projection:** TB22 measured residual 0; minority edges `10-79` and `29-35` stay within certificate faces `3/3` and `1/1` yet seed via `edgeOrbitEvidence`. Candidate is narrowed but not corrected. Exact owner: independent TB22-REV BZ2–BZ5. `M3-CP4c3-TB21-CAND-01`.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **87**. **TB21 remains current runtime authority: 384 PASS / 7 RED, accepted 365/365; CB24 artifact 9919225745 and selector393 are the exact next artifact-only validation authority.** Exact next is `M3-CP4c-3-TB22`; the mandatory successor after TB22 is independent `M3-CP4c-3-TB22-REV`. PR #8 remains open, draft, and unmerged.

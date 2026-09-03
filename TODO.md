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

## Current focus — `M3-CP4c-3-CB19` (product correction, Code + Build, runtime-free, GMP/GMPXX linked)

`M3-CP4c-3-TB16-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB16_Independent_Review_Record.md`, measures **BQ0–BQ8** discharged, static only.

**CB18 is runtime-proved.** TB16 (package 86, source `a01016ca59314232526c8b1222c96235856ace6d`, selector 382,
run/job `33709721203 / 100506452813`) is **374 PASS / 8 RED**, accepted **365/365**, selectors 380/381/382 all
PASS, edge-`25-31` cleared, mechanical attempt-0 rotation complete. `M3-CP4c3-TB11-CAND-01`,
`M3-CP4c3-TB12-REV-CAND-01` and `M3-CP4c3-TB15-CAND-01` are **CLOSED**.

**The new frontier is a product region-builder defect with two divergences in one copied loop.**

- **Wrong datum.** `build_regions` (`GlobalTopologyPlan.cpp:409`, run `:1660`) treats `incomingCarrier == nullopt`
  as a source-port incidence and searches the face for `trace->sourceVertex`. `incomingCarrier.reset()` at
  `SurfaceCellTracing.cpp:2335`/`:2432` — the two vertex-transit continuations — proves a carrier-less segment is
  ordinarily an Amendment-3 vertex continuation. **Fourth instance** of the class fixed at CB16/CB17/CB18.
- **Consumes a hypothetical carrier.** `build_fragment_corner_incidence` (`:180`, run `:1492`) skips a trace's
  final segment when there is no `terminalBarrier`; `build_regions` counts it in `tracePieceCount`, adds its
  `outgoingCarrier` to `traceTouchedEdges`, and derives orbit evidence from it.
- **The trigger is the second, and that is provable.** The earlier loop holds a textually identical predicate,
  iterates the same arcs, and **passed**; its only carrier-less escape is the terminal slit. So the failing segment
  is the trace's last segment on a trace with no `terminalBarrier`.
- **Proved from committed bytes:** face `(9,11,17)` is mesh row 18 in vertex 11's closed six-face fan; port
  vertices `{10,35,47,71}` are disjoint from row 18's corners `{9,11,17}`; a first segment's face always contains
  its trace's origin vertex — so the segment is **not a first segment** and the failing disjunct is `sourceCorner`
  not found.

Accepted authority remains **365**; CP4c-3 remains **OPEN**. **Vertex 30 is still not reached.**

### Exact next turn

Run **`M3-CP4c-3-CB19`** under **BR0–BR9** in
`Architecture_M3_CP4c3_TB16_Independent_Review_Record.md` §8.

- [ ] **BR0** selectors 380/381/382 byte-frozen and recomputed (LF-normalized) at authoring and preflight;
      accepted 365 prefix untouched; `selected_gate=NONE`; `gate_execution_authorized=false`; GMP/GMPXX proved.
- [ ] **BR1** bind the carrier-less branch to the segment's own entry support via
      `FieldBoundaryPoint::source_support()` in **both** loops, fail-closed; keep the trace-origin rule only as the
      first-segment special case.
- [ ] **BR2** settle the terminal-slit contract **once** and apply it in both loops; silence is not an option.
- [ ] **BR3** re-derive the fragment-count invariant `expected = tracePieceCount[face] + 1` (`:685-695`); state
      what a terminal slit contributes. A green count that absorbed a changed operand is a weakened check.
- [ ] **BR4** publish the full incidence at both emitters — trace, arc, orientation, segment index/range,
      first-segment flag, bound corner and its provenance, entry/exit supports, outgoing carrier.
- [ ] **BR5** **demonstrate** accepted-boundary safety: pin before/after for every currently-succeeding terminal
      slit and non-first carrier-less segment across torus, two-ring and mechanical. Ordinals 1–365 must stay green.
- [ ] **BR6** one positive witness (non-first carrier-less segment, entry corner ≠ trace origin corner) and one
      boundary/negative witness (a terminal slit asserting the BR2 contract). Selector 383 only on demonstrated
      falsification.
- [ ] **BR7** prohibited: importing CB18's datum fix without settling BR2; scoping the repair to the source-port
      branch; changing any rotation/cellularity/cut-proposal decision; touching the sphere, 370, saturation, the
      folded cone, vertex 30, finalize/contact, or the 371/372 coupling; any tolerance or float-derived decision.
- [ ] **BR8** audit by assumption: *"a per-segment decision bound to a whole-trace datum"* and *"two loops over the
      same collection where one skips a case the other does not"*, each naming a site outside the record.
- [ ] **BR9** publish the expected `M3-CP4c-3-TB17` discriminators.

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **83**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; **TB16/package86 is current runtime authority** at 374 PASS / 8 RED, accepted 365/365, first red 366 `RegionTraceSourcePortCarrierNotAdmissible` at face `(9,11,17)`. Exact next is static `M3-CP4c-3-TB16-REV` under BQ0-BQ8.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — region source-port carrier frontier:** TB16 proves accepted 365/365, clears the edge-25-31 `EdgeTraceSecondaryRankInvalid`, passes selectors 380/381/382, and discharges the v47 five-ray/distinct-rank obligation. The new first red 366 is `RegionTraceSourcePortCarrierNotAdmissible` at source face `(9,11,17)` after complete attempt-0 rotation. `M3-CP4c3-TB16-CAND-01` owns static adjudication of the carrier-less region segment; no correction is authorized before BQ0-BQ8 review. Vertex 30 and finalize/contact remain separate and untouched.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **83**. **TB16/package86 is current runtime authority: 374 PASS / 8 RED, accepted 365/365, first red 366 `RegionTraceSourcePortCarrierNotAdmissible` at face `(9,11,17)`.** Exact next is static `M3-CP4c-3-TB16-REV` under BQ0-BQ8. PR #8 remains open, draft, and unmerged.

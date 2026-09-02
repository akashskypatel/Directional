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

## Current focus — `M3-CP4c-3-CB13` (diagnostic-only Code + Build, runtime-free, GMP/GMPXX linked)

`M3-CP4c-3-TB10-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB10_Independent_Review_Record.md`, measures **BE0–BE7** discharged, static only.

**CB12 is runtime-proved and `M3-CP4c3-TB9-REV-CAND-01` is CLOSED.** TB10 (package 80, source
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`, selector 377, run/job `33584653692 / 100106147126`) re-proved
**365/365**, published `oldOrdinal366ConditionSeedPair=false`, and passed identity 377 at terminal **v36** /
singularity 4 / `BarrierAbsorbed` / network node **7**. The first red moved out of `field-aligned-network` into
**`surface-cut-graph`**.

**The moved red is provably unreadable, and that is the finding.**

- `EmbeddedGraphTopology.cpp` emits `RotationSystemInconsistent` from **46 sites**, all reachable from
  `SurfaceCutGraph::make`. Only **9** publish a `RotationSystemInconsistencyReason`, and **every one of those 9
  also sets `sourceEdge` and/or `sourceFace`**. The ordinal-366 renderer prints both when present and printed
  neither, so the firing site is one of the **28** publishing neither — 14 `build_rotation_system`,
  9 `walk_graph_faces`, 2 `build_arcs`, 2 `build_node_loci`, 1 `exterior_boundary_orbits`. **23 publish nothing at
  all**; 5 publish only `sourceVertex`.
- **Three sequential losses of one datum, and the previously reported one is the last:** the silent producer sites;
  `SurfaceCutGraph::topology_error`, whose `SurfaceCutGraphError` has **no `sourceVertex` field**; and
  `cut_graph_failure_locus`, which publishes only two of the ten fields the error carries. **Repairing the last one
  alone changes ordinal 366's output by nothing.**
- No product snapshot or existing identity rescues it, and **the failing phase — before, during or after fan ray
  ordering — is provably undecidable today.**

Ordinals 367/371/372 are **strictly upstream-blocked by one cause**, but 371/372 read only the A1 atlas and are
held by a fixture-helper precondition (`M3-CP4c3-TB10-REV-CAND-01`, deferred on purpose). Accepted authority
remains **365**; CP4c-3 remains **OPEN**.

### Exact next turn

Run **`M3-CP4c-3-CB13`** under **BF0–BF9** in
`Architecture_M3_CP4c3_TB10_Independent_Review_Record.md` §7. **Diagnostic-only**: it changes no topology decision,
adds no gate ordinal, and moves no selector byte.

- [ ] **BF0** selectors 374/375/376/377 byte-frozen and recomputed at authoring and preflight; accepted 365 prefix
      untouched; `selected_gate=NONE`; `gate_execution_authorized=false`; GMP/GMPXX linkage proved.
- [ ] **BF1** one typed name per condition at every silent producer site, scoped **by predicate** — "any site
      constructing a `RotationSystemInconsistent` error without assigning `rotationSystemInconsistencyReason`" —
      found by search; re-derive the counts (this review found 28 candidates of 46 in
      `EmbeddedGraphTopology.cpp`, plus 8 sites in `GlobalTopologyPlan.cpp`) and reconcile any difference.
- [ ] **BF2** add `sourceVertex` to `SurfaceCutGraphError` and copy it in `topology_error`; audit that mapper
      field-by-field and report anything else silently dropped.
- [ ] **BF3** extend `cut_graph_failure_locus` with the reason, vertex, trace, event, position failure/pass and
      cut-candidate evidence; find consumers by search and name one this measure did not name.
- [ ] **BF4** publish which `certify_actual_embedded_graph` attempt failed — initial uncut certification, or
      proposal *n* with *k* cut edges.
- [ ] **BF5** name the carrier: extend `append_cp4c_failure_locus` in the same change so **ordinal 366's own
      failure message** carries the answer; declare `MechanicalWitnessStageReachabilityIsObservable` a **non-gating
      diagnostic identity** for the successor TB.
- [ ] **BF6** audit by assumption, two predicates, each with a site named outside this record.
- [ ] **BF7** prohibited: changing any topology decision, ray ordering, cellularity test or cut proposal; adding or
      removing a gate ordinal; altering any selector byte; a tolerance or float-derived topological decision;
      repairing the sphere, ordinal 370, saturation, the folded-cone witness, vertex 30, the finalize/contact
      fall-through, or the 371/372 fixture coupling; inferring and "fixing" a producer before the measurement names
      it.
- [ ] **BF8** report the re-derived counts and reconciliation, per-site distinct-condition counts, the mapper audit,
      the consumer search, and an explicit statement that no topology decision changed.
- [ ] **BF9** publish the expected `M3-CP4c-3-TB11` discriminators.

Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt **5**; semantic M3
package count **77**.

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

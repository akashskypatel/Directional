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

## Current focus — `M3-CP4c-3-CB17` (Code + Build, DIAGNOSTIC-ONLY)

`M3-CP4c-3-TB14-REV` is **COMPLETE**. Record:
`Architecture_M3_CP4c3_TB14_Independent_Review_Record.md` (**BM0–BM8** discharged, static only).

CB16 cleared **every vertex locus** and TB14's first red moved to
`EdgeTraceSecondaryRankInvalid`, source edge `25-31`, source face `(25,30,31)` — mesh row **41** — attempt 0 /
zero cut edges. `M3-CP4c-3-TB14-REV` proved the branch is **not determined** by the retained evidence.

- **This is newly reachable code, not a regression.** Contact nodes are appended after every vertex node and
  `incidences` is a node-id map, so **all vertex loci precede all edge loci**. TB13 failed at a vertex locus, so
  `edge_locus_secondary_rank` had **never run** on this witness.
- **The locus is a contact node.** `build_node_loci` gives an edge locus to any node lacking a vertex locus whose
  event names a `sourceEdge` — not only to cut crossings — so `certificationCutEdges = 0` is consistent.
- **One emitter, collapse one layer down.** `EmbeddedGraphTopology.cpp:1440` is the only emitter, but the helper
  below it has **five** untyped `return std::nullopt` sites, and the emitter retains only `sourceEdge`,
  `sourceFace` and the reason.
- **Branches 1–3 excluded, 4 and 5 not separable.** The caller already resolved the face and required it in
  `sideRank`, and edge `25-31` is an edge of row 41. What remains — opposite-carrier versus source-vertex fallback
  — have **different owners and opposite corrections**: branch 4 makes the *producer* the owner, branch 5 the
  *rank contract*.
- *(Conditional, not asserted: if the fallback fires it cannot succeed here — it searches row 41's corners
  `{25,30,31}` for `trace.sourceVertex`, and the port-emitting singularities are `{10,35,47,71}`.)*

`M3-CP4c3-TB13-CAND-01` and `M3-CP4c3-TB13-REV-CAND-01` **CLOSE** — TB14 clears every vertex locus, which requires
CB16's vertex-exit case to resolve. `M3-CP4c3-TB14-CAND-01` transitions to **branch undetermined**.
**The v47 obligation stays open**: selector 380 REDs at its production assertion, so the five-ray/distinct-rank
proof is again unpublished; `M3-CP4c3-TB11-CAND-01` stays OPEN and `M3-CP4c3-TB12-REV-CAND-01` partially
discriminated. Sphere 368, saturation 369, ordinal 370, folded-cone 374, the 371/372 coupling, vertex 30 and the
finalize/contact fall-through are unchanged. **There is still no vertex-30 discriminator.**

### Exact next turn

Run **`M3-CP4c-3-CB17`** under §9 **BN0–BN9** of
`Architecture_M3_CP4c3_TB14_Independent_Review_Record.md`. **Diagnostic-only.**

- [ ] **BN0** — selector 380 byte-frozen; accepted 365 untouched; eight compile targets, **GMP/GMPXX mandatory**.
- [ ] **BN1** — typed failure reason per `nullopt` site in `edge_locus_secondary_rank`, mirroring CB16's
      `VertexTraceSecondaryParameterFailureReason`.
- [ ] **BN2** — retain arc, trace, orientation, segment interval, both carriers, `contactIndex`, the candidate
      `other` carrier, `trace.sourceVertex` and the face corners.
- [ ] **BN3** — project through the **production** renderer, reusing CB16's pattern.
- [ ] **BN4** — bounded edge-locus ray census with a truncation marker.
- [ ] **BN5** — one witness per typed reason plus a byte-identical regression witness.
- [ ] **BN6** — append selector 381 only on demonstrated falsification.
- [ ] **BN7** — **no semantic change**: rank formulas, fallback, `sideRank`, `key.primary`, collision detection,
      `build_node_loci` and contact-node construction untouched; no CB12/CB14/CB15/CB16 revert.
- [ ] **BN8** — audit by assumption; prove ordinals 1–365 unaffected by construction.
- [ ] **BN9** — publish the six `M3-CP4c-3-TB15` discriminators, **including that the v47 conjunction stays owed**.

Accepted semantic authority remains **365/365**; CP4c-3 remains **OPEN**. Stable accounting remains **44 events / 14
categories / 30 recurrences**; produced-witness debt **5**; authoritative semantic M3 package count **81**.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 remains open; TB14 is current valid runtime authority at accepted prefix 365 / first red 366 `EdgeTraceSecondaryRankInvalid` at edge 25-31. CB16/package84 remains current build authority. Exact next is independent `M3-CP4c-3-TB14-REV`.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2 — new edge-locus secondary-rank frontier:** TB14 re-proves accepted 365/365 and runtime-clears the CB16 vertex-10 `VertexTracePortOrdinalInvalid` failure. The first red is now `EdgeTraceSecondaryRankInvalid` at source edge `25-31` / face `(25,30,31)`, attempt 0 / zero cut edges. `M3-CP4c3-TB14-CAND-01` owns the new semantic question. Independent TB14-REV must identify the exact arc/trace/orientation/segment/carrier incidence and decide valid-rank contract gap versus stale/invalid provenance before any CB17 correction. The v47 full five-ray/distinct-rank production proof remains mandatory; selector 379 PASS and absence of the old collision are insufficient. Final closure of TB13 candidates is reserved for review. Vertex 30 and finalize/contact remain separate and untouched.

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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **81**. CB16 remains current BUILD + PACKAGE GREEN / RUNTIME-FREE authority; TB13 remains latest valid runtime authority. TB14 terminated orchestration-invalid/incomplete with no semantic disposition. Exact next is independent `M3-CP4c-3-TB14-REV`. PR #8 remains open, draft, and unmerged.

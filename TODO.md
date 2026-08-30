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

## Current focus — `M3-CP4c-3-DEFN` — definition and planning only

**`M3-CP4c-2` is CLOSED / ACCEPTED at 365/365.** Adjudicated by
`Architecture_M3_CP4c2_TB_X2_R10_Independent_Review_Record.md`. Measures **AJ0–AJ9**.

Accepted authority: source `57444781af7bdc460e38cc68930a9a8c8199eeea`, GMP package `9736088354`
(SHA-256 `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`), packaged source archive
`2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`, R10 run/job `33331453506 / 99310594268`,
result/log artifacts `9737796927 / 9737797177`, selector **365** SHA-256
`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`, final **365/365 PASS**, immutable
pre/postflight green, every mutation and benchmark flag false.

**What CP4c-2 delivered.** Criteria **C1**, **C3** and **C6** green. A2a′ `SurfaceCutGraph` is a certified
pre-region authority: the closed genus-1 torus goes from a non-cellular network to a certified cellular embedding
with 28 cut edges, A2b derives 4 regions, and producer and independent oracle agree term for term
(`V/E/F = 72/76/4`, `76 − 48 = 28`). Cellularity is certified in the actual embedded graph (Amendment 13),
trace-crossed source edges are admissible cuts with proved completeness (Amendment 14), semantic and provenance
identity are separate digests on a bounded *and* a closed witness, and enumeration invariance is proved.

**What it did not deliver** — the three items CP4c-3 inherits, listed below.

### CB9 was audited line by line before closure

`arcIndices.size() != 1U` → `arcIndices.empty()` drops only the upper bound and **keeps a typed failure for zero
arcs**; the per-face body runs once per sub-arc with both guards retained; the comment now **names the
canonical-direction dependency** the dart formula rests on. The `boundaryVertices` fix **tightens** — it resolves
each sub-arc endpoint through the shared `NodeLocus` authority and adds a typed error for an unresolvable node — so
it can only create reds, not manufacture a pass, and none appeared. `build_node_loci` is now computed once and
threaded, removing a pre-existing redundant recompute. **Nothing in the diff weakens a check.**

The AI2 fragment reconciliation is proved by the product, not merely published: `GlobalTopologyPlan.cpp:679-687`
unconditionally rejects unless `fragmentOrbits[face].size() == tracePieceCount[face] + 1`, and ordinal 363 passed.

### CP4c-3 scope — AJ0–AJ9

- **AJ0** record the closure in `M3_CP4c_Consolidated_Record.md` §2 and `ROADMAP.md` §1; package count **67**.
- **AJ1** freeze CP4c-3's gate by **appending** to accepted 365, so `head -355/-357/-361/-365` all still reproduce;
  state per-identity gating membership with a rationale.
- **AJ2** the prescribed sphere is CP4c-3's **first-class subject**, not a footnote — separate its two problems, and
  if it stays outside the gate, say why in writing.
- **AJ3** read the 178 retained AI2 rows from artifact `9737796927` and state the comparison explicitly. No runtime.
- **AJ4** own `R10-CAND-01`: model trace crossings as per-face chords in the proposal heuristic; require a witness
  where the **ordinary** path selects a trace-crossed edge with `saturationUsed=false`.
- **AJ5** decide `R8-CAND-02` rather than deferring it again.
- **AJ6** preserve CP4c-2's diagnostic surface — `originatingTopologyError`, the AI2 publication, the
  actual-embedded-graph oracle, the repaired D2 harness — and keep running the frozen non-gating selector in full.
- **AJ7** measures must carry their own enumerations, or require a **search** rather than a copy.
- **AJ8** no reopening of Amendments 12/13/14; no change to accepted selector 365's bytes; no implementation,
  compile, package, runtime, gate execution or benchmark in a definition turn.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative M3 packages **67**.
`selected_r2_branch=NONE`; `gate_execution_authorized=false`.

### Inherited by CP4c-3 from CP4c-2

- [ ] `M3-CP4c2-TB-X2-CAND-04` — the prescribed sphere. (a) producer `RotationSystemInconsistent` at source face
      `25-27-28`, `producerCutEdgeCount=0`, before cut selection; (b) independently, a non-cellular pre-cut graph
      (`V/E/F = 18/30/18`, `chi=6` vs `sourceChi=2`) needing trace-crossed cuts. Fixing (a) does not fix (b). AJ2.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — Amendment 14's **ordinary** trace-crossed proposal path is structurally
      unreachable; only saturation promotes such an edge, because `barriers` still contains `traceCrossed` so those
      edges bound components instead of lying inside them. Quality/coverage, not correctness. AJ4.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — zero-node / zero-arc closed-surface cut-graph behaviour. AJ5.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted; R10 closed CP4c-2 at **365/365** on immutable package `9736088354`, with criteria C1/C3/C6 green. CP4c-3 is **unblocked** and inherits three items — the prescribed sphere, Amendment 14's unexercised ordinary proposal path, and the zero-node/zero-arc question. Exact next is `M3-CP4c-3-DEFN` under AJ0-AJ9.
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

# Directional Surface-Cell TODO

Last updated: 2026-08-31 UTC

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

## Current focus — `M3-CP4c-3-CB3` (Code + Build, runtime-free)

`M3-CP4c-3-TB2-REV` is **COMPLETE**: it accepted TB2's execution, **confirmed Amendment 15 effective at runtime**,
established the ordinal-366 cause and **proved it pre-existing rather than a regression**, declared **Amendment 16**
(`DESIGN.md` §7.2.1), and issued **AN0–AN9**. Record:
`Architecture_M3_CP4c3_TB2_Independent_Review_Record.md`.

### What the review established

- **Amendment 15 works.** The mechanical witness advanced past `IncompleteCycleBasis`; ordinals **1–365** are green,
  so the cut regressed nothing in the accepted gate. Selector 373 and all six predecessor prefixes were recomputed
  from committed bytes and match.
- **Ordinal 366 is the same disagreement one consumer later.** `build_singularity_attachments` demands a branch
  transport on every radial edge of a **globally closed** one-ring fan, while `branchTransports` excludes every
  barrier by construction — so a singular vertex incident to a hard feature fails by construction. Established by
  the same elimination as TB1.
- **It is pre-existing and unmasked, not a regression:** CB2's diff to `FieldTransportAtlas.cpp` begins at old line
  842, leaving `build_branch_transports`, `ordered_incident_fan` and `build_singularity_attachments` untouched.
- **Amendment 16** generalizes 15 to every A1 derivation that walks transport. It fixes the prohibition (never give
  a barrier a branch transport, never close a fan across one) and **leaves the port-emission policy open** pending
  measurement — **AN4** forbids designing across it.
- **Still unproved:** ordinals 367–373 never ran, so Amendment 15's own self-checks and AM1's barrier decomposition
  remain unmeasured and every DEFN-R1 prediction is unverified.

### Exact next turn

Run **`M3-CP4c-3-CB3`** — Code + Build, runtime-free, GMP/GMPXX linked, under **AN0–AN9**:

1. **AN1** publish the failing locus (route the four fields the typed error already carries) for **every** error
   code the mechanical and sphere witnesses can reach, plus the barrier-incident singularity census and AM1's
   barrier decomposition;
2. **AN2** publish the four per-binary SHA-256 from packages 69 and 70 side by side;
3. **AN3** fix fixture resolution **in the package** — the compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR`
   fallback must stop being an authority — and report whether package 68 shipped a fixture tree;
4. **AN4** do not design the port correction until AN1 reports;
5. **AN5** implement Amendment 16 once the evidence chooses, naming which policy was taken and which measured fact
   chose it, and resolving the AM4-versus-port-derivation contradiction;
6. **AN7** correct the next TB plan's rerun rule to key on *"produced no semantic verdict"*;
7. **AN8** audit by assumption and name a consumer that holds it without touching the changed data structures.

## Superseded — `M3-CP4c-3-TB2` execution record

`M3-CP4c-3-TB2` is **COMPLETE / RED — VALID SEMANTIC FIRST-RED AT ORDINAL 366** after the user-authorized orchestration/fixture remediation. Fixture-only package **70** (artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`) preserves semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71`, the frozen selector **373**, and byte-identical package-69 binaries while adding the immutable sibling `test-data` fixture payload. R4 run `33355714664` passed package/source/GMP/selector/mapping/fixture preflight, then executed ordinals **1–365** as exactly-selected green fresh processes.

Ordinal **366**, `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`, selected exactly once and exited 1 with `InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`. This is a valid semantic first-red. Ordinals **367–373** were not executed under first-red semantics. `M3-CP4c3-TB2-ORCH-01` is **RESOLVED / NON-STABLE** by package 70 and the R4 preflight; it adds **+0 stable events / +0 recurrences**. Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**, authoritative semantic packages **69**.

### CP4c-3 open items

- [ ] **C2 / mechanical witness** — the cycle-basis half is **fixed and proved**; what remains is the same
  assumption at the singularity-port consumer. Frame settled by Amendment 16; policy blocked on **AN1**, implemented
  under **AN5**.
- [ ] `M3-CP4c3-TB2-CAND-01` — **CAUSE ESTABLISHED**; pre-existing and unmasked, not a regression. Closes on ordinal
  366 green in a run reaching at least 366.
- [ ] `M3-CP4c3-TB2-REV-CAND-01` — package-70 binary identity is self-reported and unverified against package 69's
  per-binary digests; owned by **AN2**.
- [ ] `M3-CP4c3-TB2-ORCH-01` — **reopened and reclassified** as a build/packaging contract defect: the packaged
  artifact cannot locate its own fixtures. Owned by **AN3**.
- [ ] `M3-CP4c3-DEFN-R1-CAND-01` — correction remains compile-green/gating; ordinal 373 is still unexecuted because first-red stopped at 366.
- [ ] `M3-CP4c2-TB-X2-CAND-04` — sphere remains **ACTIVE / ONE LEVEL SHORT**; ordinal 368 remains unexecuted in R4.
- [ ] `M3-CP4c2-TB-X2-R10-CAND-01` — ordinal 369 remains unexecuted; product correction still unaccepted.
- [ ] `M3-CP4c2-TB-X2-R8-CAND-02` — ordinal 370 remains unexecuted; typed-error behavior still unaccepted.

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
- [ ] **M3 — field-aligned curve network.** CP4ab, CP4c-0, CP4c-0b, CP4c-1 and **CP4c-2** are accepted. CP4c-3 CB2 remains **BUILD GREEN / RUNTIME-FREE** in immutable GMP package **69** with selector **373** frozen. User-authorized fixture-only package 70 reuses byte-identical semantic binaries and valid TB2 R4 proves ordinals 1–365 green before semantic first-red ordinal **366** at `MissingSingularityBranchTransport`. Exact next is independent `M3-CP4c-3-TB2-REV`; no further TB retry or product correction is authorized before review.
- [ ] **M4** global conformity plan — also discharges the 3 `G4-B002` produced-witness debts.
- [ ] **M5** certificate-carrying chart/quotient relations — also discharges the 2 `G4-B003` debts.
- [ ] **M6** occurrence, embedding, independent verification.
- [ ] **M7** disposition and graded degradation — D0–D4 plus the M1 criterion-5 forward re-proof.
- [ ] **M8** module boundaries and operational hardening — `M8-CP3` is the production-ready exit.
- [ ] **Pipeline A.** Unscheduled until Pipeline B is Certified and evidence shows integration would materially improve quality.

## Active product blockers

- [ ] **CP4c-3 criterion C2:** Amendment 15 is implemented and **proved effective at runtime** — the mechanical witness passes the cycle basis and ordinals 1–365 stay green. It now first-reds at `MissingSingularityBranchTransport`, the same assumption at the singularity-port consumer, proved pre-existing and unmasked. Frame settled by **Amendment 16**; the port-emission policy is blocked on AN1's census (AN4) and implemented under AN5.
- [ ] **Prescribed sphere A2a′ upstream error:** resolved to `RotationSystemInconsistent → TraceEventPositionInvalid`. AM7 instrumentation is compile-green, but ordinal 368 was not reached because first-red stopped at 366; no sphere product disposition may be inferred from TB2.
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

Current stable totals are **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count is **69**; fixture-only package 70 is execution transport with byte-identical package-69 binaries. PR #8 remains open, draft, and unmerged.

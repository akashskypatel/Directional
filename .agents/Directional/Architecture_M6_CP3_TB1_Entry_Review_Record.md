# M6-CP3-TB1-ENTRY-REV — Independent Review Record

**Disposition:** REJECTED FOR BOUNDED RECOVERY / CANDIDATE UNPROMOTED
**Reviewed candidate:** `11411137781 / 912760f1ffc785676f5d50717177b1cd8be69234`
**Runtime:** `37464309062 / 112271440079`, **373/497**
**Exact successor:** `M6-CP3-CB1-ENTRY-R1`

## Review authority and mechanics

Review uses exact snapshot `e1976187f5a6297dc34c08e4c6c1075f1e8a6903`, run/artifact `37473448866 / 11417518521`, provider digest `sha256:fdbde2bf020cfb17ff3e9f42c04401aed59a63e77a2fb234bb3950b6bb058f66`; the extracted manifest verified **5544/5544** entries. The semantic candidate remains `912760f1...`; later commits are control/status/documentation only. Runtime evidence is result/log `11413899043 / 11413964659`, with exact-one 497/497, zero skips, benchmark 0 and immutable package/source/execution-view postflight.

The frozen gate is focused30 30 + CP2-focused12 12 + selector449 449 + six CP3-entry identities = **497**. Review re-partitions every RED row exactly once; no `CAND-03` catch-all remains.

## Exact 124-row partition

| Candidate | Rows | Review disposition |
|---|---:|---|
| CAND-01 | 110 | **STABLE PRODUCTION REGRESSION / new `INCOMPLETE_AUTHORITY_PUBLICATION` singleton** |
| CAND-02 | 9 | **STABLE PRODUCTION REGRESSION / `RP-01 AUTHORITY_DOMAIN_CONFLATION` recurrence** |
| CAND-07 | 1 | **STABLE TEST-AUTHORITY REGRESSION / `RP-02 TEST_AUTHORITY_COVERAGE_GAP` recurrence** |
| CAND-04 | 1 | NON-STABLE D1 witness defect |
| CAND-05 | 2 | NON-STABLE D2 witness defect |
| CAND-06 | 1 | NON-STABLE D4 oracle defect |

Total = **124**. The authoritative row-level assignment is `Architecture_M6_CP3_TB1_Entry_Red_Classification.tsv`.

## CAND-01 — incomplete face-gauge authority publication

CB1 made `SurfacePhaseFrontProduct::sourceFaceBranchRotations` explicit and the top-level multi-region merge correctly fails closed unless every successful regional producer supplies one gauge value for every owned source face. `build_curved_bounded_disk_phase_front_for_faces()` publishes that state. `build_uniform_phase_front_for_faces()` and `build_periodic_annulus_phase_front_for_faces()` do not. Their products therefore fail at `InvalidFrontBoundaryAuthority`; 73 rows expose that reason directly and 37 further accepted rows fail downstream because the phase-front product no longer exists.

This is a production regression. Review deliberately creates new singleton **`INCOMPLETE_AUTHORITY_PUBLICATION`** rather than reusing historical `INCOMPLETE_ORBIT_PUBLICATION`: the historical key is explicitly orbit-domain-specific, while this event is omission of a newly authoritative face-gauge field across otherwise-valid producer variants. Reusing the old label would silently broaden its semantics.

**Recovery:** publish the already-computed exact face-gauge authority from every successful regional producer. Do not weaken the top-level completeness check, synthesize default gauges, recover from source rows, or add tolerant/fallback publication.

## CAND-02 — seam-specific OrdinaryFront evidence applied to non-seam OrdinaryFront

A6 currently asks `reciprocal_isolation_evidence(...)` for every `OrdinaryFront` before it determines whether the relation is the special cross-sheet collinear isolation-seam case. RA-30a requires that reciprocal isolation certificate only inside that seam branch. Non-seam OrdinaryFront remains identity transport with exact coordinate/scale/sourceChart/branch equality and its existing sheet/wedge checks.

The five explicit `MissingIsolationSeamEquivalenceAuthority:a6-side-evidence` rows plus focused30 ordinals 25–28 are one production regression: **existing `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence**.

**Recovery:** move the isolation-side-evidence requirement into the certified cross-sheet collinear seam branch only. Preserve every non-seam equality and every certified-seam reciprocal/quarter-turn check.

## CAND-07 — accepted focused30 relabel omits newly authoritative face gauge

Focused30 ordinal 12, `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant`, semantically relabels one HardRail topology region by rotating cell/edge branch labels but leaves `PhaseFrontDraft::sourceFaceBranchRotations` unchanged. After RA-30a, that vector is part of the authoritative A4 state. The reconstructed A5 is therefore correctly inconsistent and the test stops at its baseline.

Because this identity was already accepted green before CB1, the PASS→RED is a stable event, but the defect is test authority, not production. It is an **`RP-02 / TEST_AUTHORITY_COVERAGE_GAP` recurrence**. Recovery updates the semantic relabel helper to transform the explicit face gauges consistently; it must not weaken A5 validation.

## CAND-04 / CAND-05 / CAND-06 — non-stable CP3-entry test-authority defects

- **CAND-04 (D1):** the produced nonzero-Z4 witness does not exhibit the required 90°/270° endpoint face-gauge delta. RA-30a explicitly pre-classifies missing non-vacuity as test-authority RED. Replace/correct the real produced witness; never hand-build the production record.
- **CAND-05 (D2):** both HardRail tests call A5 before proving the required A4 90°/270° non-vacuity. Static review confirms the production certificate formula matches RA-30a: `C_a=F_a^-1∘B_a`, `C_b=F_b^-1∘B_b`, require `C_b∘C_a^-1=R_coord`. The witness/test ordering is defective; no production relaxation is authorized.
- **CAND-06 (D4):** the test equates a typed hard-feature barrier with arbitrary endpoint `chartComponent` inequality/change. `SourceChartTransitionGraph` semantics only require the hard edge be absent from admissible chart adjacency/union; alternate non-hard connectivity may leave global component labels equal. Rewrite the oracle against the barrier graph/transition semantics directly.

Existing lessons 199, 202 and 206 already cover the failure patterns; no new lesson is necessary.

## Stable accounting

Three accepted-green losses are distinct stable events:

1. CAND-01: +1 event, **+1 category**, +0 recurrence (`INCOMPLETE_AUTHORITY_PUBLICATION`).
2. CAND-02: +1 event, +0 category, +1 recurrence (`RP-01`).
3. CAND-07: +1 event, +0 category, +1 recurrence (`RP-02`).

Stable totals advance from **60 events / 16 categories / 44 recurrences** to **63 events / 17 categories / 46 recurrences**. Produced-witness debt remains **1** (`G4-B002`, M6-owned). CAND-04/05/06 are non-stable and add no totals.

Candidate `11411137781 / 912760f1...` is rejected and unpromoted. The reviewed runtime authority remains CP2 `11391685901 / 5ce3132ec01748eff5b15f82be07a1abe2bd1af6` until recovery is independently proved.

## Frozen recovery routing — RA-31

Exactly one bounded recovery is authorized:

`M6-CP3-CB1-ENTRY-R1` → `M6-CP3-TB1-ENTRY-R1-EXEC` (**497**) → mandatory `M6-CP3-TB1-ENTRY-R1-REV`.

The recovery scope is limited to two production corrections and four test-authority corrections:

- **P1:** publish complete exact face-gauge authority from uniform and periodic-annulus A4 regional producers.
- **P2:** scope reciprocal isolation-side evidence to certified cross-sheet collinear OrdinaryFront seams only.
- **T1:** make focused30 ordinal12 relabel the explicit face-gauge authority consistently.
- **T2:** repair/replace the D1 real-produced witness until the frozen 90°/270° non-vacuity is organic.
- **T3:** repair/replace the D2 real-produced HardRail witness and assert A4 non-vacuity before A5; if no bounded produced witness exists, stop for Review.
- **T4:** rewrite D4 against typed source-hard-feature barrier semantics, not arbitrary global component labels.

D3/D7 production checks remain unchanged; their entry failures are downstream CAND-01. No optimizer, final-validator, selector/routing, frozen identity name/order, tolerance, source-grid recovery, fallback or positional-identity change is authorized.

Fresh TB must rerun exactly **497** fresh exact-filter processes with exact-one selection, zero skips, benchmark 0 and immutable postflight. Review is mandatory regardless of green/red.

## Review closeout table

| Duty | Result |
|---|---|
| Mechanical evidence | Re-derived: 497 processes, 373 PASS / 124 RED, exact-one, zero skips, benchmark 0, immutable postflight. |
| RED partition | Exact 110 + 9 + 1 + 1 + 2 + 1 = 124; no catch-all remains. |
| Product diagnosis | CAND-01 and CAND-02 confirmed production regressions. |
| Test authority | CAND-07 stable; CAND-04/05/06 non-stable. |
| Accounting | **63 / 17 / 46**, debt 1. |
| Candidate | REJECTED / UNPROMOTED. |
| Recovery | RA-31; one bounded CB turn, then immutable 497-process TB and mandatory Review. |
| Boundary | Review changes are documentation/evidence only; no product/test/fixture/selector source mutation. |

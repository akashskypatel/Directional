# RA-134 — Audit of the TB28 review (RA-133): evidence and CB27 upheld; RED partition corrected; typed-reason harvest before DEFN-M1 (2026-10-22)

**Turn:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV-AUDIT` (independent audit of `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV`, RA-133).

**Verdict:**
- **Upheld:** RA-133's evidence and its CB27 authorization. CB27 gains three binding precondition assertions (RA-134.4).
- **Corrected:** RA-133's partition of the 35 RED rows. It groups by test topic, while claiming to group by "first observed failed stage".
- **Realigned:** 21 of the 35 REDs carry no typed reason. A test-only diagnostic turn (CB28) and a harvest (TB29) now come before DEFN-M1, so that DEFN-M1 is scoped from measured factory clauses rather than static inference.

## RA-134.1 Evidence re-derived independently

- **Artifact:** `12424484672`. The provider digest equals the local ZIP SHA-256 `a54110db…56e6`; it expires 2026-11-05T12:21:10Z. **1019/1019** manifest entries check.
- **Counts:** `combined-ledger.tsv` has 497 rows, no duplicate phase:ordinal, 462 PASS and 35 RED.
- **Against the TB21 inventory (48 RED), by set difference:**
  - PASS→RED: **none**;
  - RED→PASS: exactly `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 447, 448`; `cp3entry:3, 5`.
- RA-132's prediction (at least 462/497, zero regressions) holds exactly. CB25 and CB26 are regression-free on the frozen selector.

## RA-134.2 Correction — partition by first failing component

RA-133's "Periodic product/fixture setup" family (13 rows) merges two different failing components, and labels them fixture setup without evidence:
- **`selector:189–195`** throw at the periodic-route helper (SP10:4340), when `FieldTransportAtlas::make` (A3) fails;
- **`selector:220, 221, 296, 302, 304, 439`** throw at the direct periodic-owner helper (TQ:358), when the checked factory `SurfacePhaseFrontProduct::make` rejects.

**Measured partition of the 35** (component, then whether a typed reason is visible):

| First failing component | Rows | Typed reason in log |
|---|---|---|
| Checked phase-front factory (`make` / `construct_phase_front_product`) | `focused30:3` (TQ:2498 helper), `focused30:22, 23` (TQ:5942/5983), `selector:139, 140, 142` (SP10:6479 helper), `selector:220, 221, 296, 302, 304, 439` (TQ:358 helper), `cp3entry:4` (TQ:3900) — **13** | **none** |
| Same factory, wrong typed result | `selector:211, 219` (expected `InvalidOppositeEdge`); `selector:227, 230` (`InvalidPhaseFrontProduct` instead of `InvalidHardRailAuthority`) — **4** | code shown (int or name) |
| A3 `FieldTransportAtlas::make` | `selector:189–195` — **7** | **none** |
| A3, visible | `selector:442` (`SingularityMismatch`, edge (2,3)) — **1** | yes |
| A5 on a relabelled front | `focused30:12` (TQ:5158) — **1** | **none** (`a5_rejection_message` exists but is not streamed) |
| Producer disposition or oracle | `selector:204, 242, 247` (expected Rejected); `selector:250, 405` (expected Produced); `selector:201` (missing terminal vertex); `selector:174` (DCEL exception) — **7** | yes |
| Witness absence | `cp3entry:1` (D2, no odd gauge); `cp3entry:2` (hard-rail midline certificate) — **2** | yes |

**The checked factory is the first failure in 17 of 35.** RA-105.3 attributed M1 (10 rows) statically to one factory clause, the R2 certificate binding (S:8755–8775). Whether the six periodic-owner rows and `cp3entry:4` hit that clause, the H-pin (RA-105.4 covers periodic cut edges) or another clause is **unknown**. So DEFN-M1's scope cannot yet be stated: it may be 10, 17 or a split.

## RA-134.3 Realignment — measure typed reasons first

- The A7 episode (RA-129.3: one code shared by six checks, and an unmeasured inference) and LESSONS "Diagnostics, classifiers, and causal investigation" both apply: an error code without its site is only a symptom.
- `SurfacePhaseFrontProductError` already carries `code`, `sourceAuthoritySite`, `edge`, `event`, `cell`, `region` and `periodicRelation` (`SurfaceCellTracing.h:1935`). The helpers simply drop them.
- A **test-only, message-only** change makes all 21 silent rows self-describing at zero product risk.
- **New sequence:** CB27 → CB27-REV → **CB28 (diagnostic messages)** → CB28-REV → **TB29**, which runs CB27's negatives, D3/D7, the three A7 guards and the 21 silent rows plus the four wrong-code rows on the CB28 package → TB29-REV → DEFN-M1, scoped from the measured factory clauses.

## RA-134.4 CB27 upheld, with binding preconditions

The scope stays as RA-132.6/RA-133. Without these preconditions, a negative test can pass for the wrong reason:

1. **Unrelated seam.** Before running A7, assert that the tampered relation evidence **still contains a transition joining the two endpoint sheet sets**, with no transition on `certificate.seam()`. Otherwise the test cannot tell B4 apart from an "any connecting transition" rule.
2. **Lattice coordinate.** Assert that `support` and `placement.selectedFace` are still equal, and that only `latticeCoordinate` differs. That isolates the third clause of the A1 predicate.
3. **Outside wedge.** Assert that the substituted `interiorBinding` is not in that occurrence's `cornerWedgeBindings`, and that its face is a certificate side face.

Every case runs A7 against the **original** A6 product, as D7 does (TQ:4027–4055). If A7 rejects before the forest-edge branch, that is RA-133's STOP: record it, do not adapt.

## RA-134.5 CB28 scope (issued at CB27-REV; test-only, messages only)

Files: `tests/SurfaceCellTransitionQuotientTests.cpp` and `tests/SurfaceCellsPhase10Tests.cpp`.

1. **One test-local formatter** for `SurfacePhaseFrontProductError`: code as an integer, plus `sourceAuthoritySite`, `edge`, `event`, `cell`, `region` and `periodicRelation`.
2. **Helpers** append the formatted error to their exception text: TQ:358, TQ:2498, SP10:6479. The SP10:4340 helper appends the `FieldAtlasBuildError` code and location, mirroring the formatter at `FieldTransportAtlasTests.cpp:75`.
3. **Assertions stream the reason:** `ASSERT_NE` at TQ:5942, 5983 and 3900 stream the formatted factory error; TQ:5158 streams `a5_rejection_message`.
4. **No other change:** no assertion, control-flow, fixture, expected-value or production change.

## RA-134.6 Sequence and accounting

- **Sequence:** audit (this) → **CB27** → CB27-REV → CB28 → CB28-REV → TB29 → TB29-REV → DEFN-M1 (evidence-scoped) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt (A3 periodic-route `189–195`; `174`, `242`, `250`, `442`, adjacent-sheet helper) → census → RP-01 Review. `DEFN-SEAM-NZ` and the Periodic follow-up each wait for a witness. `DIAG-RETAIN` is scheduled clear of RP-01 turns.
- **Accounting (unchanged):** stable 66/17/49, debt 1, CP2 491/491; R3 403/497 rejected; **TB28 462/497 candidate**; selector 497 frozen. `RP-01` open, `RP-02` UNREACHED, Gate C suspended.

| Duty | Answer |
|---|---|
| Decisive claims re-derived | ZIP digest; 1019/1019; 497/462/35; set differences against TB21; first-failure text of all 35; helper throw sites (TQ:358, 2498; SP10:4340, 6479); `ASSERT_NE` sites; error-type fields; RA-105.3/105.4 attribution |
| Non-vacuity | CB27 preconditions make each negative discriminating; CB28 makes 21 REDs attributable |
| Obligations | RA-133 evidence upheld; partition corrected; DEFN-M1 deferred behind TB29; docs restored |
| Durable docs | Handoff (sequence and `DIAG-RETAIN` restored), TODO (contradiction removed, sequence added), tracker, CHANGELOG, ORIENTATION, ROADMAP, Frozen Definitions index |
| Boundary | Review-only; no source, test, selector, workflow or runtime change |

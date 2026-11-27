# TB-REV-189 adversarial continuation (2026-11-27 UTC)

Continues `M6-CP3-TB-REV-189` after the [independent review](Architecture_M6_CP3_TB_REV_189_Sphere_Route_Witness_Independent_Review_20261127.md). Runtime-free: static source and record review.

Haiku agents did the following:
- replayed the CB-213 diff and ran syntax-only checks in throwaway `CLAUDE_` worktrees, since removed;
- traced the phase-front scheduler, its guards and DESIGN;
- searched for digest exposure;
- searched the record history.

Product and test bytes are unchanged.

## Verdict

- **Upheld:**
  - the 1006/1006 activated test gate;
  - BB1, confirmed;
  - the BB3 falsification (my prediction was wrong);
  - B1 held and B2 carried.
- **Upheld, with a correction to me.** TB-REV-189 is right that A4 is scheduled per source-topology region, not per plan region. My TB-REV-188 adv. BB1/BB2 wrote "no A4 producer built any of the 14 plan regions", which implied the producers had been called per plan region. They never were.
- **Withdrawn: [CB-213](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#cb-213-exact-manifest-withdrawn-historical)**, and with it the conditional TB-EXEC-190 and TB-REV-190 (CC1, CC2).
- **Struck: the "DEFN on A4 ownership of closed-surface discs and §5.2 fallback".** DESIGN and RA-213/RA-214 already decide it (CC3).
- **Realigned:** resume the per-disc A4 route, steps 65A–65D, which has been planned since 2026-11-08 and never opened (CC4, CC5).
- **Corrections to my own work:**
  - Step 4 of my TB-REV-188 adv. turn sequence ("per-region A4 decline receipt, then an ownership DEFN") re-proposed the withdrawn CB102 and a decision that had already been made.
  - CB-211R and CB-212 were diagnostic-only CBs, contrary to RA-214 §1 item 3. Their results were real; BB3 was falsified and the route confirmed. But I should have searched the record first.

## Findings

**CC1 — The code already fixes CB-213's answer.**
- For a closed sphere without hard features, `build_source_topology_regions` produces exactly **one** region:
  - one BFS component (`SurfaceCellTracing.cpp:10995–11045`);
  - no boundary edges (`:11151–11154`);
  - χ = 2.
- Each producer's first test after `attempted` is the source-global `tracing_has_singularities(options)` (`:6717–6721`; guards at `:14803`, `:15675`, `:17155`). It is true whenever the network has any singularity port.
- A cross field on a sphere must have singularities (Poincaré–Hopf, Σ index = 2). TB189's plan lists 34 boundary-singularity incidences.
- So N = 1 and M = 3, and every attempt declines at that guard.
- Even without the guard, no producer's domain test admits a closed χ = 2 region:
  - periodic needs χ = 0 (`:15759`);
  - curved needs ≥ 4 boundary edges (`:17836`) and χ = 1;
  - uniform needs a planar rectangular frame.
- RA-213 measured this on Vase in a scratch probe: with the veto bypassed, curved returns `Rejected`. RA-213 concluded: "No producer can build a source region that A2b partitions … the veto is a symptom."
- Labels: TB-REV-189 and CB-213 call `SourceTopologyRegions` "A1 regions". In DESIGN, A1 is the field transport atlas. A source-topology region is the §7.1 producer domain. Stage names must not be conflated.

**CC2 — CB-213 repeats CB102 and breaks the standing rule.**
- CB102 asked for the same thing: per-region first-decline receipts. RA-213 withdrew it on 2026-11-08.
- RA-214 §1 item 3: a runtime fact is obtained as the TB evidence of a product slice the architecture keeps, "never a diagnostic-only CB".
- Design defects:
  - The receipt is keyed by the unit DESIGN does not use for A4.
  - It adds public API for a one-off diagnostic: a struct with two `const char *` fields, a public option and a network member. The header otherwise uses enums with `_name()` functions and has no `const char *` data members.
- Mechanically, CB-213 is sound, as the Haiku check confirmed:
  - hashes and replay match;
  - the warning sets are identical;
  - no digest, `sizeof`, equality or positional initialization exposure;
  - all 19 removed lines are behaviour-neutral splits of short-circuit conditions.
- **Withdrawn on direction, not on mechanics.**

**CC3 — The ownership question is decided.**
- DESIGN:
  - A2b regions are the faces of the certified embedding, and every one is a disc (§5 table; §7.2 steps 9–10).
  - A4 is "`RegionCellComplex` per region … cells conform exactly to the supplied plan" and is "local and parallel per region" (§5.1).
  - Every region consumes the plan unmodified (§2.1 item 7).
  - §5.2 lists exactly four degradation points, and "No other stage may degrade". A whole-surface legacy re-trace after `NotApplicable` is not one of them, so it cannot produce Certified, D2 or D3 output.
- RA-213 direction: "build A4 per **A2b disc**, consuming A3 on every arc it bounds … ports are corners. The veto stays until the per-disc producer exists."
- No new DEFN is needed for either question.

**CC4 — The sphere's discs are sets of face fragments, and no per-disc domain exists.**
- A2a–A3 are now certified for the sphere:
  - 14 discs, 14 certificates;
  - V18/E30/F14, χ = 2;
  - 30 trace arcs, 0 mandatory, 0 cut.
- The plan region support is a list of fragments: "A source face crossed by traces may … occur in multiple regions" (`GlobalTopologyPlan.h:80`). TB189 measures 368 fragments on the fixture's 192 faces.
- Producers consume whole-face `activeFaces`.
- The only plan-reading path is accepted-cut, and it is narrow:
  - it runs only on hard-feature regions;
  - it selects the single plan region equal to the whole source region (`:17243–17269`);
  - it requires 4 rectangular runs (`:18553–18560`, `:18985`);
  - it never reads `interiorSingularityFree`.
- So no A4 code can build any of the 14 discs. Building one requires the disc-domain construction of step 65C.

**CC5 — Trajectory.**
- Since D10 (2026-11-12), P13's A2a work (port counts, edge-slide traces, slide-entry activation) is on the trajectory, and the sphere's A2a–A3 now certify.
- From TB-REV-186 onwards, the chain moved to the legacy fallback's completion: B1, CB-210/211R/212 and CB-213. That work is off the trajectory.
- The documented A4 route, 65A → 65B → 65C (`…-A4-DISC-DOMAIN-CONSTRUCTION`, which also absorbs O41) → 65D, never opened. It is the only DESIGN route for any field with singularities: sphere, Vase and others.
- Amendment-19 defect, still open since RA-213: the three `…PhaseFrontProducerDeclined` flags are set only on the hard-feature `Rejected` path (`RemeshPipeline.cpp:13310–13312`). It belongs to the per-disc dispatch slice.

## Turn sequence

1. **`M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION`** (step 65C, re-baselined). Review, runtime-free, bounded.
   - (a) Reconcile 65A–65D against HEAD, with sphere and Vase as witnesses. The sphere has no boundary arcs, so 65A (boundary carriers) is not on its path.
   - (b) Freeze **one** exact, behaviour-neutral product slice that the architecture keeps. The expected slice is the per-disc domain representation:
     - per A2b region: fragments, oriented walk, corners, and the A3 breakpoints of each arc;
     - a typed validator, using an enum with `_name()`;
     - a non-vacuity unit test.
     - No producer may consume it. The veto stays.
   - (c) Record the TB predictions:
     - sphere: 14 valid domains whose fragments partition all 192 faces;
     - Vase: 3 domains;
     - 1006 rows otherwise unchanged; check digest neutrality per RA-211.
2. CB: the frozen slice, compile only.
3. TB-EXEC: full 1006-row gate plus the domain-validator receipts.
4. TB-REV.
5. Then, one DEFN → CB → TB at a time:
   1. per-disc dispatch with typed declines, which also fixes the Amendment-19 flags;
   2. boundary and corners;
   3. fill (§4.9);
   4. aggregation and the O41 switch exit.
6. B2 (BunnyRandom: the previous RED was `RotationSystemInconsistent` at A2b, and the run now times out at 600 s) is a shared-stage regression lead. The Review agent freezes its observation mechanism separately. No timeout increase.
7. Held:
   - B1 and fallback repair;
   - CB-207C/D;
   - parameter deletion → V3b → R1 → O48;
   - CB-190, J6, E5;
   - promotions.
   - Row858's legacy diagnostic lines (CB-210/211R/212) stay until the per-disc route replaces them.

## Lessons

- Before freezing a receipt or a DEFN, search the record for the same question. RA-213 and RA-214 had already settled A4's unit and withdrawn CB102. Two reviews, mine included, re-asked both 19 days later.
- Do not measure what the code already fixes.

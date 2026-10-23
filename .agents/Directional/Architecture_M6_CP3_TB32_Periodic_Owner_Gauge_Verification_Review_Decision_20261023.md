# RA-148 — Independent TB32 evidence Review (2026-10-23)

**Canonical turn:** `M6-CP3-TB32-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-VERIFY-REV`. **Decision:** ACCEPT immutable TB32 *bounded fixture/test evidence*; **DO NOT promote** M6-CP3, any A5/A6 produced result, odd transport, periodic holonomy, or RA-45.4. The only newly released unit is the separately bounded CB31 odd-transport/permutation witness; implementation is **not** performed in this Review.

## Independently reopened primary authority

- Exact CB30 semantic source `19267540081a4ff3a99826e3b9a766f1dbbded42`; eight-target GMP/GMPXX compile artifact `12531891913` ZIP SHA-256 `040b7b12e4b36fa78f2c5eae6465ddaadd2a1fbd8ee9bf18ebda6e35e9a3b97b`, **28/28** verified checksums; packaged `runtimeExecution=false`.
- TB32 [run 40028643379](https://github.com/akashskypatel/Directional/actions/runs/40028643379), artifact `12534679588`, ZIP SHA-256 `2c809e72489a69396c3c9e97e2a40ebb15f726de84a19b5610bb092fb9f85ddd`. Independently verified **1,006/1,006** packaged digests, **500/500** per-row individual GoogleTest RUN/terminal/verdict/exit/raw SHA-256 joins; no missing, duplicated or skipped case; immutable postflight, no rebuild/relink/configure/benchmark.
- TB31 baseline [run 39959505758](https://github.com/akashskypatel/Directional/actions/runs/39959505758), artifact `12506242253`, ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`, **1,000/1,000** digests. 497 cases independently recomputed at **472 PASS / 25 RED**.
- Frozen 497 identity/name/binary/order joins remain unchanged; TB32 manifest SHA-256 `597741409f06a80877cb8ae6f5fd2f92785de99a629a7d2c6453921858996437`, baseline 497 manifest `b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`. Original 497 outcomes: TB32 **478 PASS / 19 RED**. Three new independent factory controls PASS, yielding **481 PASS / 19 RED** in all 500. Exactly six RED→PASS (`selector:220,221,296,302,304,439`); **zero PASS→RED**. No inherited first-failure type changed.
- Accepted M5 selector449 SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`, static receipt `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`. Accepted CP2 491/491 and frozen original 497 remain distinct; no accepted selector is extended or promoted by TB32. The immutable log evidence does not itself prove a new accepted-prefix publication, and no such claim is made.

## Non-vacuity and scope

The actual source `tests/SurfaceCellTransitionQuotientTests.cpp` has six original call sites to the common topology-keyed, two-face, real-A3-gauge `direct_periodic_owner_fixture`. Their original owner-map assertions independently distinguish missing owner, differing owner order, duplicate owner identity, foreign region, unknown edge owner, and same identity/different action. The factory checks a supplied directed edge and reciprocal derived gauge. The three new controls establish the valid baseline before (1) deleting supplied gauges, which must reject at `InvalidSourceAuthority/face-gauge-missing`; (2) changing one gauge, which must reject at `InvalidSourceAuthority/gauge-pin-consistency;edge=0,2`; and (3) shifting both by +1, which must admit and preserve original owner identity/value and supplied shifted gauge **without requiring equal provenance digests**. Their PASS is meaningful within this controlled source-derived factory path.

**Explicit limit:** this planar two-face fixture has an unpaired front (`oppositeEdge=-1`) and no live periodic route. It does not force odd 1/3 atlas transport, unequal gauges under cyclic face/corner permutations, reciprocal periodic action, or a produced A6 relation outcome. Equal or trivially constant gauge permutations cannot falsify a stale face-row mapping. Review accepts only the narrow owner-fixture and factory negative/positive contracts; it does not accept general periodic topology or a production fix.

## Remaining 19 REDs — first failure, not guessed root cause

- **Seven `selector:189–195`:** `CycleTransportMismatch` from unavailable A3 fixture route. Do not classify as demonstrated production cycle root cause; obtain admissible source/atlas evidence first.
- **One `selector:442`:** `SingularityMismatch` on source edge `(2,3)`; existing owner remains.
- **One `focused30:12`:** A5 first rejection; existing owner remains.
- **One `cp3entry:4`:** open-rail-chain first rejection; existing owner remains.
- **Two `cp3entry:1/2`:** fixture/witness unavailable; produced proof not established.
- **Seven `selector:174,201,204,242,247,250,405`:** causally **untyped** at this gate; require earliest rejecting predicate and an independent falsifier, not a diagnosis inferred from the test name.

All 19 remain carried; no RED is silently waived. RA-146.2 unpaired-periodic limitation and RA-146.3 odd-transport/permutation gap remain open; RA-146.4 and RA-45.4 produced A6 outcome-invariance remain separate, including the unselected `M6CP3.A6UniformFaceGaugeRotationPreservesRelationOutcome`. G4-B002 closed-complex produced witness, DIAG-RETAIN, DEFN-SEAM-NZ, periodic and DEFN-T1 debts remain on existing owners. RP-01 unresolved, RP-02 unreached, Gate C suspended. No new stable regression: **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**.

## Exactly one bounded successor

**`M6-CP3-CB31-RP01-ODD-ATLAS-TRANSPORT-PERMUTATION` — Code + Build / compile-only.** [Plan](Architecture_M6_CP3_CB31_Odd_Atlas_Transport_Permutation_Code_Build_Plan_20261023.md) freezes RA-146.3's proof preconditions, positive/negative falsifiers, path restrictions and stop rules. The next turn must first prove genuine odd directed A3 transport via raw-field ingress; if its fixture cannot realize transport 1 or 3, **STOP and return evidence** instead of fabricating a transport or weakening the premise. No implementation, test execution or odd-transport claims are part of this Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | M5 accepted selector449 `d4a0d1b7...d6414` and receipt `9c88a5ed...7617`; TB31 original 497 manifest `b1c135d4...43e`, TB32 exact 500 manifest `59774140...6437`; no accepted-prefix mutation |
| Decisive claims independently re-derived | Three artifact archive hashes, 28/28 + 1,000/1,000 + 1,006/1,006 internal hashes, 500 raw run names/verdicts, 497 TB31/TB32 joins, six recoveries, zero regressions |
| Non-vacuity checked | Six original owner assertions and three independent checked-factory tamper/shift controls have actual discriminating source paths; unpaired/odd/A6 limitations explicit |
| Prior obligations discharged/carried | RA-146.1 factory fixture gate discharged by six runtime PASS; RA-146.2/3/4 and RA-45.4 carried; 19 RED, G4-B002, periodic/DEFN-T1, DIAG-RETAIN/DEFN-SEAM-NZ carried |
| Stable accounting | 66 / 17 / 49; debt 1; M5 449/449, CP2 491/491 accepted; CP3 478/497 candidate only |
| New candidates/obligations recorded | RA-148 scoped acceptance and CB31 odd-transport precondition/falsifiers in tracker; no new stable event |
| ORIENTATION currency line | RA-148 / 2026-10-23 |
| ORIENTATION §3 / §4 / §7 / §8 | §3 and §7 updated and superseded TB32-next warnings replaced; §4 representative fixture table unchanged because synthetic factory outcome does not change representative coverage; §8 corrected vacuity wording with RA-148 instance |
| CHANGELOG | RA-148 decision entry added |
| ROADMAP | CP3 current evidence updated; checkpoint not promoted |
| Selector manifest | n/a: no selector was added or accepted |
| LESSONS | Existing non-vacuous witness/independent oracle rules apply; no new generic pattern |
| Consolidation under CLEAN_UP_POLICY | n/a: current TB32 report, residual inventory, RA-146/147 and this Review/next-plan are load-bearing and cannot be folded without losing authority; historical status remains subordinate to current tables |
| Successor frozen | `M6-CP3-CB31-RP01-ODD-ATLAS-TRANSPORT-PERMUTATION`; exact falsifiers in CB31 plan |
| Turn boundary held | Review-only; no code/test/fixture/selector/build/workflow mutation or binary execution |
| review_check.py boundary | NOT YET VERIFIED against authentic full Git history; downloaded source snapshot excludes .git; synthetic-history check cannot substitute for required real-history boundary |
| `STATUS` lifecycle maintained | Entry published as IN_PROGRESS; final beacon publication is last repository mutation and determines final state |
| Pushed to origin, branch in sync | Pending transport/commit; connector commit readback can verify exact files but a source snapshot without Git history cannot support an actual `git status -sb` claim |

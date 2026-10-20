# RA-110 — TB19-REV: TB19A accepted; H-pin confirmed as a producer/factory gauge-domain mismatch; DEFN-P1 ordered (2026-10-20)

**Turn:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV`. **Inputs:**
- TB19 (RA-108, RA-109): run `39464430751`, artifact `12285225197`, report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`;
- TB19A: run `39484475466`, artifact `12292268624`, report `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`.

**Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, both at HEAD `59f6daf4b`, whose `src`, `include` and `tests` are identical to `d2c7483cd`. **Amends:** RA-105.7 and RA-106.7 (sequence only).

## RA-110.1 TB19A evidence verified; TB19A closed

- **Artifact.** Review downloaded `12292268624` independently:
  - ZIP SHA-256 `25d48ed7…7efa7c` matches; run `39484475466` succeeded on head `5335c610a`;
  - `SHA256SUMS` verifies every file, and the 7 raw-log hashes and the ledger match the report;
  - `execution-boundary.txt`: planned = executed = 7, red 6, missing 0, postflight true, no compile, relink, benchmark or selector-497 run.
- **Harness.** The diff against the TB19 harness is exactly RA-108.5: the staging path, the torus pre-check, the per-row not-found guard, the 7 rows, the counts and the labels. SHA-256 `21480db4…cabc` matches the dispatch request.
- **G1–G4 held.** The control `selector:443` PASS proves the torus fixture resolves.
- **Report accepted.** Its RA-109.4 classification is correct: {0,3} is the first edge of the minor cycle (TQ:910), which shares only vertex 0 with the major cycle.
- **Closeout.** The agent's turn ended with STATUS `IN_PROGRESS` and the TODO, CHANGELOG and handoff not updated. Review completes them in this turn, as in RA-109.2, and TB19A is closed.

## RA-110.2 Combined measurement: all nine M2 identities stop at the pin

| Identities | Fixture | Site | Edge |
|---|---|---|---|
| `cp3entry:2`, `cp3entry:6`, `focused30:12` | rectangle `hard_rail_fixture()` | `gauge-pin-consistency;edge=1,4` | cross-region hard-rail carrier |
| `cp3entry:1`, `focused30:6/20/24`, `selector:446/447` | nonzero-Z4 torus witness | `gauge-pin-consistency;edge=0,3` | minor-cycle hard edge (`torus_row408_hard_edges`) |

- Every rejecting edge is a member of the factory input `hardFeatureEdges`.
- No M2 identity reaches the certificate, endpoint or junction clauses. The R-route is **NOT REACHED** on all nine, so the RA-103.5 falsifier stays undetermined. It carries to the first TB after the pin is corrected.
- All nine codes are `product=0`, so the RA-106.5 non-zero-code follow-up is not invoked.

## RA-110.3 H-pin ruling

**Static basis:**
1. **Producers are per region.** S:18336–18352 runs uniform, then periodic annulus, then curved bounded disk for each topology region separately. Each producer roots its own gauge; the bounded disk sets root 0 at S:16255. No producer establishes the A3 relation between face gauges in two different regions; DEFN-P1 item 1 verifies this for each producer.
2. **Cut edges are skipped inside a region.** In a region with a hard feature and an accepted conformity plan (`useAcceptedCutDomain`, S:15333), the bounded-disk producer collects the conformity boundary carriers as `acceptedCutEdges` (S:15532). It omits them from:
   - face incidence (S:16000);
   - the gauge BFS (S:16217);
   - the reciprocal-transport check (S:16346).
3. **The pin checks every two-face edge.** It requires `compose(T_A3, g_first) == g_second` on each one, including the edges in items 1 and 2 (S:8509–8567).
4. **The cross-carrier transition is checked elsewhere, on the field.** `rail-transition-a3` (S:8717–8732) authenticates each `hardRailFieldTransitions` entry against the atlas without reading face gauges.
5. **Frozen text.** The pin on carriers contradicts:
   - RA-31a.1: the published F is region-relative;
   - RA-33.3: τ is not a difference of region gauges;
   - RA-34.3: requires a produced witness with `(F_b−F_a) mod 4 ≠ τ_ab`.

   RA-45.1 says the gauge is consumed only relationally.
6. **Torus.** RA-105.4: with nonzero Z4 holonomy on a dual loop, no face gauge satisfies the pin. TB19A measured the rejection at {0,3}.

**Rulings:**
- **H-pin is CONFIRMED.** The pin's domain is wider than the domain over which any producer establishes the face gauge. This is a defect in the checked factory's clause (RA-45.3's domain). It is neither fixture debt nor a producer defect.
- **The pin stays mandatory inside the gauge domain** (RA-45.3), and RA-45.5 (validate, never rewrite) stands. The `SurfaceCellFactoryRejectionSite` negative must still reject at an edge within a region's gauge domain.
- **Rail carrier versus periodic cut is not separated, and need not be.** On the torus witness every rejecting edge is both a hard edge and part of the cut graph. The correction is defined by the producers' gauge domain, not by edge type. DEFN-P1 states the predicate.
- **`focused30:12` is not uniform-relabel debt.** RA-105.7's condition, that Review keeps the present domain, does not hold. It stays an M2 production identity.

## RA-110.4 Constraints on the corrected domain

> **Amended by RA-111.3 (2026-10-20):** item 3 (exactness) is withdrawn; the domain must instead span each region. RA-111.4 gives the domain.

DEFN-P1 must define a domain that satisfies all five:
1. **Inputs.** It is computable from `make`'s inputs. `make` receives `hardFeatureEdges` and `sourceTopologyRegions`, but not the producer's `acceptedCutEdges`. If the domain needs more, DEFN-P1 names the minimal added input and does not design it.
2. **Producers.** It covers the uniform (S:13178), periodic-annulus (S:13997) and curved-bounded-disk (S:15284) producers.
3. **Exact.** It excludes exactly the edges no producer relates. Excluding an edge that some producer relates weakens RA-45.3, and is forbidden.
4. **Authority.** For each excluded edge class, it names the `make` clause that authenticates what is consumed across it (for example `rail-transition-a3`, or the periodic relation `branchAuthority` described at S:13104–13107), or it records a gap.
5. **Consumers.** It confirms or refutes RA-45.1 at the current source: does any production consumer read a gauge difference across an excluded edge?

## RA-110.5 Next unit — `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN` (Definition, documents only)

> **Amended by RA-111.2 (2026-10-20):** the first STOP condition is withdrawn; a producer relating an intra-region hard edge does not falsify H-pin.

**Deliverable:** `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_<date>.md`, containing:
1. **Producer table** (3 rows): the function and its S range, the gauge root rule, and the two-face edges excluded from its gauge domain, each with S lines.
2. **Cut-set inclusion:** is every `acceptedCutEdges` member (S:15532) in `hardFeatureEdges`? Give an S-line proof or a counterexample.
3. **Torus regions:** do the two faces at {0,3} lie in one topology region? Answer statically with S lines, or say that it cannot be decided statically.
4. **Domain:** the corrected domain as one predicate over `make`'s inputs (RA-110.4 item 1), plus the authority table for excluded edges (item 4).
5. **Consumer census** for RA-110.4 item 5, with S and `RemeshPipeline.cpp` lines.
6. **Oracle plan** for the later CB (not executed):
   - for each of the nine M2 identities, the prediction is "passes the pin" only, with nothing beyond it;
   - the `SurfaceCellFactoryRejectionSite` negative still rejects, at (0,4);
   - at least one proposed negative proves that the narrowed pin still rejects a one-face gauge change inside a hard-feature region's gauge domain.

**Out of scope:**
- code, tests, builds and runs;
- the M1 binding (RA-105.3);
- the R-route;
- fixture debt;
- edits to frozen RA text.

**STOP and return to Review** if any of these holds; each would falsify H-pin:
- a producer whose gauge domain includes a hard-feature carrier;
- a production consumer that reads a face-gauge difference across an excluded edge.

**On success:** `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN-REV` (Review, mandatory).

## RA-110.6 Sequence and accounting

- **Sequence:** DEFN-P1 → DEFN-P1-REV → [CB20, the pin domain, compile only → TB20, artifact-only on the nine M2 identities plus controls → TB20-REV] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review. The bracketed turns are planned and are authorized only by DEFN-P1-REV.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

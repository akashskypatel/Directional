# RA-111 — DEFN-P1 reviewed: census accepted; exactness withdrawn for a spanning domain; CB20 authorized (2026-10-20)

**Turn:** `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN-REV`. **Input:** `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_20261020.md` (`fe07a5e09`). **Lines:** S = `src/geometry/SurfaceCellTracing.cpp`, R = `src/pipeline/RemeshPipeline.cpp`, TQ = `tests/SurfaceCellTransitionQuotientTests.cpp`, all at HEAD `ca9c23e85`, whose `src`, `include` and `tests` are identical to `d2c7483cd`. **Amends:** RA-110.4 item 3 (withdrawn) and RA-110.5's first STOP condition (corrected).

## RA-111.1 Record verified

- **Producer table (item 1) is confirmed.** The uniform producer (S:13208–13229) and the periodic-annulus producer (S:14019–14039) both decline a region that has a hard feature and a conformity baseline. Only the curved bounded-disk producer runs there, and it excludes `acceptedCutEdges` (S:15333, S:16000, S:16217, S:16346).
- **Torus regions (item 3) are confirmed.** Review recomputed them from the committed `torus.obj`, omitting the 18 hard edges:
  - 144 faces form one region;
  - {0,3} lies between faces 1 and 22;
  - the non-hard dual graph is connected.
- **Consumer census (item 5) is confirmed.** R:4630–4642 reads one face's gauge, and R:5633–5655 compares presence and face identity only. No production consumer reads a gauge difference, which agrees with RA-45.1.
- **Cut-set inclusion (item 2) is accepted as open.** Nothing proves `acceptedCutEdges ⊆ hardFeatureEdges`. RA-111.5 explains why this does not block CB20.
- **The predicate (item 4) is correct under RA-110.4 item 3.** RA-111.3 withdraws that constraint, and RA-111.4 replaces the predicate.

## RA-111.2 The conditional STOP does not fire

- **Review's wording was wrong.** RA-110.5's first STOP ("a producer whose gauge domain includes a hard-feature carrier") assumed the correction would drop hard edges wholesale.
- **No falsification.** A producer that verifies transport across an intra-region hard edge does not make the pin wrong on that edge, so it does not falsify H-pin. H-pin concerns only edges the pin checks and no producer relates.
- **Corrected STOP:** a production consumer reads a face-gauge difference across an edge outside the pin domain. The census shows none.
- **The agent was right to raise the point.** Returning it to Review rather than resolving it was correct.

## RA-111.3 Exactness withdrawn; the domain must span each region

**RA-110.4 item 3 is withdrawn.** It required the pin to cover exactly the producer-related edges, which forced DEFN-P1 to ask for a new `make` input. The pin authenticates the gauge, and the gauge has only one degree of freedom per region:
- **Relational and region-relative.** The gauge is consumed only relationally (RA-45.1, census above) and is region-relative (RA-31a.1).
- **A spanning graph fixes the gauge.** Take a connected set G of pinned edges inside a region. The gauges that satisfy `compose(T_e, g_a) == g_b` on every edge of G form at most one orbit of the region's Z4 shift. Any edge beyond a spanning tree adds no constraint on the gauge; it only constrains the atlas's holonomy on a cycle.
- **So any spanning pinned set detects the same tampering as the full producer relation set.** The holonomy checks it leaves out are exactly what H-pin found misplaced in a gauge check.
- **The spanning set already exists.** Regions are the connected components of the graph of two-face, same-component, non-hard edges (S:9670–9727), so restricting the pin to that graph spans every region by construction.
- **No new `make` input or producer change is needed.**

## RA-111.4 Corrected domain (frozen for CB20)

```
pin(e, a, b)  <=>  two_face(e, a, b)  &&  e not in hardFeatureEdges
                   &&  region_for_row(a) == region_for_row(b)
```

**Span guard.** Within each region, the pinned edges must connect all of its faces. Otherwise `make` returns `InvalidSourceAuthority` with site `gauge-pin-span;region=<index>`. The guard keeps the pin non-vacuous whatever the source of `make`'s `hardFeatureEdges`. It cannot fire for a producer whose regions and hard edges come from the same options.

**Properties:**
- **Monotone.** The new domain is a subset of the current one, so every product the pin accepts today it still accepts. The only new acceptances are:
  - a gauge shift of a whole region (RA-31a.1; RA-45.4 applied per region);
  - fields whose holonomy crosses a hard edge.
- **RA-45.3's rejections still hold:** a one-face change, a change to a proper subset of a region, an A3 mismatch on a pinned edge, and an absent gauge. A3 across carriers stays with `rail-transition-a3` (S:8717–8732).
- **Existing oracles still hold:**
  - TQ:2749–2754 (`cp3entry:1`, one-face torus tamper) still rejects through the face's non-hard edges;
  - TQ:2833 (uniform rotation) is still accepted;
  - TQ:4987–5036 (`focused30:12`, one-region relabel) passes the pin.

## RA-111.5 Open item, not blocking

A non-hard accepted cut carrier, if one exists, stays pinned exactly as it is today. The result is a fail-closed rejection, never a silent acceptance. If TB20 shows `gauge-pin-consistency` on a non-hard edge, Review opens a follow-up on cut-set inclusion.

## RA-111.6 Next unit — `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN` (Code + Build, compile only)

**S (inside the pin block, S:8509–8567, only):**
1. **Domain skip.** In the incidence loop (S:8538), after the open-boundary skip and the incidence-size rejection, skip the edge (`continue`) when `hardFeatureEdges.contains(edge)` or `sourceTopologyRegions.region_for_row(incident[0]) != sourceTopologyRegions.region_for_row(incident[1])`.
2. **Span guard.** After the loop, union the faces of every pinned edge. Every face must share a root with the first face of its region (`region_for_row`, `TopologyRegionId::index()`). Otherwise return code 0 with site `std::string("gauge-pin-span;region=") + std::to_string(<index>)`.
3. **Comment.** Update the RA-45 comment (S:8509–8513) to state the domain in at most three lines.

**TQ (suite `SurfaceCellFactoryRejectionSite`, outside every frozen selector):**
4. **Tighten** `OneFaceGaugePinNamesSourceEdge`: the site must equal `gauge-pin-consistency;edge=0,4`.
5. **New** `RegionGaugeShiftPassesPin`:
   - the `hard_rail_fixture()` draft, with +1 mod 4 on the gauge of every face in the region that does not contain face 0;
   - assert the result is a product, or an error whose site does not begin with `gauge-pin-`.
   - *Amended by RA-112.4: the test asserts a product only.*
6. **New** `HardEdgeIsolatingFaceRejectsAtSpan`:
   - insert every non-hard two-face edge of face 0 into the draft's `hardFeatureEdges`;
   - expect `InvalidSourceAuthority` with site `gauge-pin-span;region=<face 0's region index>`.

**Static acceptance:**
- the S diff lies only inside S:8509–8567, plus the guard placed directly after the loop;
- no line is longer than 100 columns;
- all 48 `InvalidSourceAuthority` site labels are unique;
- nothing changes in the header, the producers, R, the selectors or any frozen test.

**Build:** GMP/GMPXX, the eight targets, package, `runtimeExecution=false`. The CB20 record gives the diff summary and the label → S-line entry for the new label.

**STOP and return to Review** on:
- a compile error (record the first diagnostic of each distinct error);
- face 0's region having a single face;
- any need to touch code outside the pin block.

**On success:** `M6-CP3-CB20-RP01-GAUGE-PIN-DOMAIN-REV` (Review). The TB20 rows are set there.

## RA-111.7 Sequence and accounting

> *Amended by RA-112.6: CB20 stopped at compile; CB20A and CB20A-REV follow before TB20.*

- **Sequence:** CB20 → CB20-REV → TB20 (artifact-only: the nine M2, the ten M1 as a no-regression check, the `SurfaceCellFactoryRejectionSite` suite, controls) → TB20-REV → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt → census → RP-01 Review.
- **Accounting is unchanged:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, TB18 candidate 448/497, selector 497. `RP-01` is open, `RP-02` is UNREACHED and Gate C is suspended.

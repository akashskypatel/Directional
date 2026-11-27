# TB-REV-191 adversarial continuation (2026-11-27 UTC)

Continues `M6-CP3-TB-REV-191` after the [independent review](Architecture_M6_CP3_TB_REV_191_Region_Boundary_Schedule_Independent_Review_20261127.md). Runtime-free: static source, DESIGN and receipt review. Haiku agents extracted DESIGN §5, §5.2, §7.2 and §7.4, and traced the A2b certificate, A3 count and A2a termination code. No binary was built or run, and product and test bytes are unchanged.

## Verdict

- **Upheld:**
  - the 1008/1008 test gate;
  - CB-214's mechanics;
  - all 16 predicted row858 lines.
- **Upheld, with a note:** the incidence lookup's chain branch (`chainOrdinal > 0`, reversed walk) matches A3's convention, where the incidence is read at the identifying arc (`GlobalConformityBaseline.cpp:378`). However:
  - no witness reaches it;
  - production builds only per-arc spans.

  Carried to 65A and the chain switch.
- **Corrected: TB-REV-191 left A4D5 open "pending measurement".** The 16 lines it accepted already decide most of it (DD1, DD2).
- **Corrected: my own DEFN-65C A4D5 note.** "34 incidences fit no integer mix of port valences" counted only sectors and ignored arrivals; they are accounted for exactly (DD1). Falsifier (2), "`interiorSingularityFree` is wrong", is excluded by code for vertex singularities (DD3).
- **Realigned:** the sphere plan's corner defect is upstream, at A2a, which has no degraded mode (DESIGN §5.2). A4 corner work on this plan would only re-measure it.
  - The successor `M6-CP3-DEFN-P13-A4-DISC-CORNERS` moves after an A2a fix.
  - The new successor is `M6-CP3-DEFN-P13-A2A-SINGULARITY-ARRIVAL-PORT-OWNERSHIP` (DD4).
- **Added to the sequence:** A4 construction for unequal opposite sides (DD5).

## Findings

**DD1 — The 14 node lists are the whole sphere embedding, and they account for every incidence.**
- **The embedding.** The lists give V18/E30/F14 and 30 paired node-pairs (no mismatch).
- **Node degrees:**

  | Nodes | Degree |
  |---|---|
  | 0, 7 | 4 |
  | 1, 2, 5, 6 | 5 |
  | 3, 4 | 3 |
  | 8–11 | 2 |
  | 12–17 | 3 |

- **The singular nodes are 0–7.** Two independent lines agree:
  - `boundarySingularities` counts distinct singularity IDs per region (`RegionCornerOwnership.h:76–127`). Of the five vertex sets that satisfy all 14 counts, only {0..7} leaves no regular node of degree 5, and a regular point has at most 4 field directions.
  - The network creates singularity nodes at setup (`SurfaceCellTracing.cpp:5469–5502`), and contact nodes take index `candidate.nodes.size()` (`:3022–3029`). The sphere has no mandatory edges. The independent pass confirmed the append but did not trace the call order, so this line is supporting evidence only.
- **The accounting.** Ports per singularity are `4 − indexNumerator` (`:5520`). By Poincaré–Hopf, eight singularities give Σvalence = 4·8 − 8 = **24 port traces**. The receipts then decompose exactly:
  - **6 T-junctions** (nodes 12–17), giving 24 + 6 = 30 arcs;
  - **4 mutual terminations** (nodes 8–11), from an inconclusive arrival order, where both traces stop (`SurfaceCellTracing.h:770–777`);
  - **24 − 6 − 8 = 10 arrivals** at singularities;
  - Σ singular degree = 24 + 10 = **34**, the 34 boundary-singularity incidences.
- **The arrivals.** An arrival terminates on vertex identity alone, with no direction or port check (`SurfaceCellTracing.cpp:3617–3633`, ownership `:2301–2338`). If every singularity has valence 3 (index +1/4), the arrivals land as follows: nodes 1, 2, 5 and 6 get two each; nodes 0 and 7 get one each. Individual valences are not printed, so this split is inferred.

**DD2 — Ten surplus arc-ends make at least four regions unfillable, and the defect is at A2a.**
- **Why surplus arc-ends matter.** A quad-patch corner must be a positive multiple of a quarter turn. A valence-3 node has three quarter sectors, so each surplus arc-end either:
  - splits a sector into sub-quarter corners, or
  - runs along a port's own separatrix, giving a zero-angle cusp.
- **The four sliver regions.** Each lies between two long arcs that join the same singular pair, with a short side of count 1–2. That is one separatrix connection traced from both ends:

  | Region | Shape | Singular pair | Paths between the pair |
  |---|---|---|---|
  | 2 | 1×32 strip | 1–5 | 1–12–5 and 1–14–5 |
  | 4 | 1×32 strip | 2–6 | 2–15–6 and 2–13–6 |
  | 5 | 35, 35, 2 wedge | 0–4 | direct, and via node 17 |
  | 10 | 2, 35, 35 wedge | 3–7 | direct, and via node 16 |

- **Why the wedges need a cusp.** The validator excludes interior singularities (DD3), and Σturning must be 4 quarters. With three corners, that is reachable only with a 2-quarter turn: a cusp at the apex (nodes 0 and 7, each one surplus).
  - So A4D5's falsifier (3) holds as a zero-angle corner.
  - Falsifier (1), a turning trace arc, is not needed to explain the wedges, and it is not measured.
- **Who owns the defect.** DESIGN A2a invariant 1: "every required singularity port is owned exactly once". Invariant 8 and §7.2 step 7 let network reduction "remove redundant traces".
  - An arrival realizes the separatrix of the port whose carrier it enters. In a constant-per-face field, a trace reaching a vertex through a face interior is collinear with that face's field ray from the vertex, which is a port ray.
  - The code neither claims that port nor removes its own trace. Contacts are taken only from `ProperCrossing` (`:4755–4758`), so a coincident or overlapping pair never meets. No reduction step was found by search.
- **Why A4 cannot absorb it.** DESIGN §5.2 gives A2a no degraded mode; :457 and :1050 forbid tiny-region collapse after the plan. Routing these regions to D3 in A4 would work around an A2a defect.
- Recorded as **O51** in the tracker; A4D5 is updated there.

**DD3 — `interiorSingularityFree` is sound for vertex singularities.**
- The candidate set is every vertex of the region's faces, or the fragment corners on cut faces (`RegionCornerOwnership.h:28–74`).
- A singularity there without a port on the region boundary fails with `RegionContainsInteriorSingularity`.
- The certificate field is set only after that validator succeeds (`GlobalTopologyPlan.cpp:1910–1937`).
- Gap, not a defect here: `RegionEulerCharacteristicNotOne` and `RegionInteriorDisconnected` are declared but never raised, and the Euler check only emits a diagnostic (`GlobalTopologyPlan.cpp:2227–2248`). The disc proof relies on `proves_disc_topology()` alone.

**DD4 — The trajectory had the order wrong.**
- **What TB-REV-191 froze.** It froze a corners DEFN that would measure three falsifiers, the 34 incidences and port valences, and also admit a Vase row. That repeats TB-REV-189 adv.'s lesson ("do not measure what the code already fixes"):
  - the valences and incidences are determined (DD1);
  - falsifier (2) is excluded (DD3);
  - the wedge corners are forced (DD2).
- **The turn was also not narrow:** a Vase row is a separate gate change.
- **The root-cause slice is at A2a.** Classify each singularity arrival against the target's port carriers, then remove the redundant port trace under invariant 8. A4 corners follow on the corrected plan.
- **What follows from fixing A2a:**
  - the sphere plan, regions and digests change, which is an announced behaviour change in its own gate turn;
  - the B1 and fallback lines are untouched.

**DD5 — Unequal opposite sides are the common case, and no turn builds them.**
- **The A3 side.** Counts are `round(∫ 1/h ds)` along the 3D path (`GlobalConformityBaselineSupport.cpp:281–297`), with per-region parity by a minimum T-join (`GlobalConformityBaseline.cpp:446–484`). There is no opposite-side constraint, as DESIGN :194, :739 and :741 intend.
- **On the sphere** (degree-2 nodes merged into their sides), the eight four-node regions compare as follows:

  | Regions | Opposite pairs |
  |---|---|
  | 0, 3, 8, 9 | 30 vs 35 and 32 vs 35 |
  | 6, 11 | 35 vs 35, but 70 vs 2 |
  | 2, 4 (the strips) | equal |

  The other six regions have 2, 3 or 5 nodes.
- **Who owns it.** DESIGN :194 and :739 give A4 "general-even-boundary constructibility" and "an A4 producer for unequal sides" (O40 class: irregular vertices). The sequence names only a "fill domain" (A2a′ fragments) and no construction step.
- **Consequence:** without that producer, A4 fills almost no sphere region even after the A2a fix. It is now an explicit item.

## Turn sequence

1. **`M6-CP3-DEFN-P13-A2A-SINGULARITY-ARRIVAL-PORT-OWNERSHIP`** (Review, runtime-free, bounded). Its scope:
   1. Confirm the arrival lifecycle from source.
   2. Resolve from DESIGN invariants 1 and 8 and §7.2 steps 5 and 7 which port an arrival owns. STOP for a user decision if that needs normative text beyond them.
   3. Freeze **one** behaviour-neutral exact slice with these parts:
      - a typed A2a arrival classification, computed by a free function and read by no stage. It must not be a hashed network member (RA-211);
      - for each singularity arrival, its target, its arrival carrier (face and branch, or radial edge), and the matching port or `NoPortCarrier`, plus whether that port's own trace exists;
      - one non-vacuity unit row;
      - row858 sphere and genus_two receipts.
   4. **Predicted:** 10 sphere arrivals, landing per DD1.
2. CB, compile only.
3. TB-EXEC, full gate.
4. TB-REV.
5. **DEFN for the behaviour change:** an arrival that claims a port removes that port's trace (invariant 8). It states the predicted sphere plan (no cusp regions) and the gate rows whose bytes change. Then CB → TB → TB-REV.
6. **Corners DEFN** (A4D2 part 2) on the corrected plan, then CB → TB.
7. **A gated Vase witness row:** its own CB and TB.
8. **A4 unequal-side construction** (DD5): DEFN, CB, TB.
9. Then, in order: the fill domain, 65B, 65D (O50 and the Amendment-19 flags), O41 and the switch exit.
10. **Held or carried, unchanged:** B1, B2, CB-207C/D, parameter deletion → V3b → R1 → O48, CB-190, J6, E5 and promotions.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix | Unchanged: 1008 `ca16b66d…4081`, 1006 `a9b80832…0587` and CP2 491. No selector or gate file was touched. |
| Decisive claims re-derived | <ul><li>DD1 was computed from the 14 TB191 lines and the TB189 `SpherePlanRegion` lines.</li><li>The citations were read from source.</li><li>An independent Haiku pass re-derived (a) V18/E30/F14 and the degrees; (b) the five singular-set solutions, of which only {0..7} has no regular degree-5 node; (d) the decomposition 6 + 8 + 10; (e) the four sliver path pairs; (f) the DD5 pairs; and (g) six of seven citations, the seventh in part.</li></ul> |
| Stable accounting | 67/17/50, debt 1, deferred 81; CP2 491/491; the 1008/1008 test gate only. |
| New candidates | **O51**, a non-stable A2a defect; A4D5 updated (tracker). |
| ORIENTATION, CHANGELOG, ROADMAP, LESSONS | Currency line, §7 priority and §8 pattern updated. CHANGELOG entry added. ROADMAP current-state line updated. Two LESSONS bullets added to §4. |
| Successor | Exactly one: `M6-CP3-DEFN-P13-A2A-SINGULARITY-ARRIVAL-PORT-OWNERSHIP`. |
| Turn boundary | Runtime-free. No product, test, fixture or selector byte changed. |

## Lessons

- Before freezing a measurement, extract everything already in hand: degrees, Euler's formula, and the Poincaré–Hopf surplus Σdegree − Σvalence at singular nodes. TB-REV-191's question was answerable from its own 16 lines.
- Before placing a geometric fix at a consumer, check whether DESIGN gives the producing stage a degraded mode. If it does not (§5.2), the fix belongs at the producer.

# M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION — step 65C re-baselined (2026-11-27 UTC)

**Turn type:** a same-agent DEFN, runtime-free (`REVIEW_TURN_POLICY.md`, `AGENT_POLICY.md`).

**Authority:**
- [TB-REV-189 adversarial continuation](Architecture_M6_CP3_TB_REV_189_Adversarial_Review_20261127.md), CC1–CC5;
- DESIGN §2.1 item 7, §5, §5.1, §5.2, §7.2, §7.3 and §7.4, including the D5 amendments;
- RA-213 §2–§4 and RA-214 §3–§5 (Vol D2);
- the [D10 record](Architecture_M6_CP3_DEFN_P13_A4_Size_Grading_Decision_Review_20261112.md) §5;
- the TB189 sphere plan (result `15171482516`).

**Source:** HEAD `6b57f90f0`. Its product bytes are identical to CB-212 source `39253c63…`, and only documents and `STATUS` differ.

Haiku agents did the following:
- mapped the A2b/A3 data model, the gate identity format and the fixture coverage;
- replayed the frozen diff and ran syntax-only checks in throwaway `CLAUDE_` worktrees, since removed.

No Directional binary was built or run. Product, test, selector and fixture bytes on the branch are unchanged.

## 1. Reconciling 65A–65D with HEAD

| Step (D10 §5) | State at HEAD | Sphere (closed, 14 discs, 30 trace arcs) | Vase (disc, 3 discs, boundary rim) |
|---|---|---|---|
| 65A A3 boundary-span carrier binding (D9c) | Partly done. CB104 records intervals on curved-disk boundary arcs (TB87/TB88). No carrier authority for chained spans. | Not on its path: there are no boundary or mandatory arcs. | Needed. |
| 65B A2b reciprocal trace intervals (D9) | Not started. There is no edge kind for a trace seam between two discs. | Needed before any produced disc can be accepted. It records that both discs consumed the same breakpoints. | Needed. |
| 65C disc-domain construction (this turn; includes O41 and the switch exit) | Not started. There is no per-disc domain. Accepted-cut takes only a plan region equal to the whole source region (`SurfaceCellTracing.cpp:17243–17269`). | Needed. | Needed. |
| 65D per-disc dispatch and aggregation | Not started. The scheduler iterates source-topology regions (`:20130`). The source-global veto stands (`:6717–6721`). | Needed. | Needed. |

**Measurability.** No gated row runs Vase end to end with retained products:
- row725 checks the mesh only;
- the Vase instance of `SurfaceCellDesignAcceptance` is not in the manifest.

Vase is therefore measured once a later DEFN admits a Vase row. Row858 already runs the sphere and genus_two with retention.

## 2. Definitions frozen

- **A4D1 — unit.** A4 constructs per A2b region (DESIGN §5 and §5.1; RA-213). Source-topology regions stay the domain of the existing producers only until per-disc dispatch replaces them. The veto stays until then.
- **A4D2 — the disc domain has three single-owner parts, frozen in this order:**
  1. **Boundary schedule**, this slice: the region walk, with every occurrence bound to its A3 span, incidence and count.
  2. **Corners:** the field turning at each walk node, and along any arc that turns, from A1 transport. Next DEFN.
  3. **Fill domain:** the disc's A2a′ fragments as exact source-attached polygons.

  65B precedes the acceptance of any produced disc. 65D follows the fill domain.
- **A4D3 — owner and placement.** The schedule lives in the A3 module (`GlobalConformityBaseline`), because DESIGN §7.4 D5 says "consumers resolve an arc to its span, chain ordinal and support-piece offset through the plan". It holds IDs and counts only and copies no plan data (§7.3).
  - Its join is the accepted-cut lookup (`SurfaceCellTracing.cpp:17280–17340`), and its path test equals `bound_arc_schedule` (`:14465–14489`).
  - The duplicate is debt **O50**: the dispatch slice moves the producer onto this one owner.
- **A4D4 — reachable failures only.** Three typed reasons:
  - `TopologyPlanMismatch`, reachable by pairing plans;
  - `ArcNotScheduled`, reachable because the A3 builder accepts arbitrary span supports;
  - `IncidenceNotFound`, a lookup failure.

  No check repeats a guarantee that A2b or A3 already validated (walk closure, parity, positivity, breakpoints). `IncidenceNotFound` has no unit witness, because validated A3 cannot reach it. Its absence on the sphere and genus_two is measured, not presumed.
- **A4D5 — corner hypothesis, frozen as a falsifier for the corner slice.**
  - On a disc with no interior singularity, whose boundary arcs are straight in the field's flat metric and whose corners lie only at walk nodes, Σ(2 − gapᵢ) = 4, where each gap is ≥ 1 quarter turn. That needs at least 4 convex corners.
  - Sphere regions 5 and 10 have 3 walk nodes each, so they cannot meet that condition. At least one of the following must hold:
    1. some arc turns, for example a slide-traced arc (RA-237/238);
    2. `interiorSingularityFree` is wrong;
    3. a node turns by more than a quarter.
  - The 34 boundary-singularity incidences also fit no integer mix of valence-2, valence-3 and valence-5 ports traced once per sector.
  - The corner slice must measure node and arc turning, and the valence of each port. A3 does not own this. DESIGN §7.4 makes local shape constructibility A4's, with D3 routing.

## 3. Frozen successor

**`M6-CP3-CB-214-P13-REGION-BOUNDARY-SCHEDULE`**, Code + Build, compile only. Then `M6-CP3-TB-EXEC-191`, a full gate of 1008 rows. The [exact manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md) states the hashes, the stop rules and the falsifiers.
- **Diff:** `0fc97ddc…b02b`, four paths, +316/−0:
  - product `GlobalConformityBaseline.h/.cpp`;
  - tests `GlobalConformityBaselineTests.cpp` (two new gate rows, 1007 and 1008) and `SurfaceCellTracingDisplayTests.cpp` (16 receipt lines in row858).
- **New manifest:** [1008 rows](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Full_Gate_Case_Manifest.tsv) `ca16b66d…4081`. Its header plus rows 1–1006 hash to `a9b80832…0587`.
- **Behaviour-neutral by construction.** No pipeline, producer or hashed structure calls or changes. Digests are unaffected because the new types are not members of any hashed or `sizeof`-measured struct (RA-211).
- **Predictions** for the sphere:
  - `built=1 regions=14 sides=60 arcs=30 pairedArcs=30 otherArcs=0`;
  - the per-region side counts from TB189 (4, 6, 4, 4, 4, 3, 5, 4, 4, 4, 3, 5, 4, 6);
  - every region even.
- **Prediction** for genus_two: `built=1 … otherArcs=0`.
- Any `built=0` falsifies A3 binding for trace-bounded discs. Record it; do not repair.

**Syntax-only check** (not compile evidence; preimage → postimage, 0 errors in both):

| Translation unit | Warnings, pre / post | New warnings |
|---|---|---|
| `src/geometry/GlobalConformityBaseline.cpp` | 23 / 23 | none |
| `tests/GlobalConformityBaselineTests.cpp` | 30 / 30 | none |
| `tests/SurfaceCellTracingDisplayTests.cpp` | 27 / 27 | none |

## 4. Sequence

1. CB-214, compile only.
2. TB-EXEC-191, 1008 rows.
3. TB-REV-191.
4. DEFN for the corners part of A4D2 (decides A4D5; admits a Vase row).
5. CB and TB for corners.
6. DEFN, CB and TB for the fill domain.
7. 65B.
8. 65D, which retires O50 and fixes the Amendment-19 flags.
9. O41 and the switch exit.
10. **Separate Review item:** the B2 observation mechanism.
11. **Held:** B1 and fallback repair, CB-207C/D, parameter deletion → V3b → R1 → O48, CB-190, J6, E5 and promotions.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The header plus rows 1–1006 of the new 1008-row manifest hash to `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`, which is TB189's frozen manifest. CP2 491 is unchanged; no selector file was touched. |
| Decisive claims independently re-derived | <ul><li>The A2b/A3 data model and the accepted-cut join were read from source.</li><li>The production per-arc input was checked (`RemeshPipeline.cpp:1005–1016`).</li><li>The baseline digest binding was checked (`GlobalConformityBaseline.cpp:608`).</li><li>The gate filter semantics were checked (local gate driver, `--gtest_filter` per row).</li><li>Vase is not a gated end-to-end row.</li><li>Sphere sides Σ = 60 was computed from the TB189 plan lines.</li><li>The diff was replayed and its hashes recomputed by an independent Haiku pass.</li></ul> |
| Non-vacuity checked | <ul><li>Unit row 1008 reaches `TopologyPlanMismatch` (triangle plan against square baseline) and `ArcNotScheduled` (fixed-edge supports) on valid built inputs.</li><li>Row 1007 checks each binding against `find_schedule`, walk-node continuity and parity.</li><li>The sphere and genus lines can print `built=0` or `otherArcs>0`.</li><li>`IncidenceNotFound` has no witness and is stated as such (A4D4).</li></ul> |
| Prior obligations discharged/carried | <ul><li>TB-REV-189 adv. NEXT_TURN deliverables (a), (b) and (c) are discharged here, except the Vase prediction, carried per §1 with the reason.</li><li>B1 held; B2 carried to a separate Review item.</li><li>The Amendment-19 flags and O49 go to 65D.</li><li>CB-207C/D, O41 and D6 are unchanged.</li></ul> |
| Stable accounting | 67/17/50, debt 1, deferred 81; CP2 491/491; the activated 1006/1006 is unpromoted. No change. |
| New candidates/obligations recorded | **O50** (duplicate arc-schedule lookup) and **A4D5** (corner falsifier), both in the tracker. |
| ORIENTATION currency line | `M6-CP3-DEFN-P13-A4-DISC-DOMAIN-CONSTRUCTION`, 2026-11-27. |
| ORIENTATION §3 / §4 / §7 / §8 | §3: the M6-CP3 row now names the domain slice. §4: n/a, no witness state changed. §7: the priority is CB-214. §8: an instance of "plan before producer domain" (LESSONS 531) is noted. |
| CHANGELOG | Entry added. |
| ROADMAP | The current-state line is updated. There is no checkpoint transition. |
| Selector manifest | A note was added that TB-EXEC-191 uses a 1008-row gate manifest. No selector file changed. |
| LESSONS | Existing 531 and 78 cited; no new lesson. |
| Consolidation under CLEAN_UP_POLICY | The withdrawn CB-211 prose plan and the withdrawn CB-213 manifest are folded verbatim into Vol D3, with their links repaired. |
| Successor frozen | Exactly one, `M6-CP3-CB-214-P13-REGION-BOUNDARY-SCHEDULE`. Its falsifiers are in the exact manifest and in §3. |
| Turn boundary held | Runtime-free. No product, test, selector, fixture or benchmark byte changed on the branch; the diff exists only as a review artifact. |
| review_check.py boundary | `python3 .agents/Directional/tools/review_check.py boundary`: **ALL CHECKS PASSED**, with durable files and rewrite sections preserved. |
| `STATUS` lifecycle maintained | Entry `IN_PROGRESS` at 2026-11-27T05:32:08Z; final `COMPLETE` with Successor CB-214. |
| Pushed to origin, branch in sync | Confirmed by `git status -sb` after the final push, reported in the turn response. |

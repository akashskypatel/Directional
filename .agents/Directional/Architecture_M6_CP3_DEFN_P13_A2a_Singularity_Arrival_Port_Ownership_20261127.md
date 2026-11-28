# M6-CP3-DEFN-P13-A2A-SINGULARITY-ARRIVAL-PORT-OWNERSHIP (2026-11-27 UTC)

**Turn type:** a same-agent DEFN, runtime-free (`REVIEW_TURN_POLICY.md`).

**Authority:**
- [TB-REV-191 adv.](Architecture_M6_CP3_TB_REV_191_Adversarial_Review_20261127.md) DD1–DD5;
- DESIGN §5.2, §7.2 steps 1, 5 and 7, and A2a invariants 1 and 8;
- [D13 = A](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md) (TB-REV-173 E1–E5);
- the TB191 result `15179335926`, read from its rows 858 and 1003.

**Source:** HEAD `78fb178a4`. Its product bytes are those of the CB-214 source.

The TB191 artifact was downloaded into an isolated scratch directory and read as data. No binary was built or run. Product, test, selector and fixture bytes on the branch are unchanged.

## 1. Arrival lifecycle (confirmed from source)

- **Two ways an arrival ends.** A trace ends at a singularity on vertex identity alone. That happens either by a face-interior vertex hit (`SurfaceCellTracing.cpp:3617–3633`) or at the end of a slide (`:3800–3815`). No arrival direction or port is compared.
- **Contacts:** only `ProperCrossing` contacts are taken (`:4755–4758`). Inconclusive ordering stops both traces (`SurfaceCellTracing.h:770–777`).
- **D13 already reduces the network.** `field_aligned_select_retraced_traces` (`:4290–4375`) works on traces that end at singularities, in port order. When one trace retraces another exactly along source edges (`ExactSourcePath.h:270–352`), it removes the later trace and records the removed port as the kept trace's `arrivalPort`. A retrace through a face is out of its scope (TB-REV-173 E3), and so is partial co-tracing (E5).
- **Correction to TB-REV-191 adv. DD2.** It said the code "neither claims that port nor removes its own trace … no reduction step was found by search". That is false for exact along-edge retraces. I missed D13 and CB-196…199B: a repeat of the TB-REV-189 adv. lesson to search the record first.
  - The sphere count still forces zero such pairs. With E = 24 − r + T, V = 8 + T + H, trace ends T + 2H + A = 24 − r, and singular degree 24 − r + A = 34, the only solution is r = 0.
  - So all 10 sphere arrivals are inexact. DD1's accounting stands.

## 2. Ownership: already decided

D13 = A, resolved from invariants 1 and 8, holds that a separatrix connection traced from both ends is one separatrix. One trace is kept; its origin port is owned by its departure, the other port by its arrival, and the redundant trace is removed (step 7). So **an arrival owns the port whose separatrix it realizes, and no new normative text is needed for ownership.**

What remains open is narrower:
- **AP0, recognition.** Which arrivals realize which port's separatrix when the two traces are not exact reverses? That is the E5 obligation.
- **AP4, removal.** How is a partially co-traced port trace removed (§4)?

## 3. New finding: the atlas groups each separatrix's rays and publishes only one

`build_singularity_attachments` (`FieldTransportAtlas.cpp:564–1055`) works as follows:
- It collects every field ray leaving a singular vertex into an incident face's wedge.
- It unites rays of neighbouring fan faces whose branches transport into each other across the radial edge between them (`:711–757`).
- It publishes one representative per class, the first in face-topology order, as the port (`:922–944`).

The other rays are discarded, so no downstream stage can tell that an arrival came in along the same separatrix as a port.

Measured in the TB191 logs (row858 atlas `partition` lines and `committedSlide` lines):

| Fixture | Rays | Classes | Shape |
|---|---|---|---|
| Sphere | 48 | 24 (all 8 singularities: 6 rays, 3 classes) | Every class has two rays, one in each face of one radial edge; no ray lies on an edge. |
| Mechanical (row 1003) | 12 | 12 | Each class is one ray, and every ray lies on a radial edge. |

**Every one of the 10 sphere arrivals is a slide along a radial edge into its singularity**, and each edge is the edge one class straddles. The arrivals land 1, 2, 2, 2, 2 and 1 at nodes 0, 1, 2, 5, 6 and 7, which confirms DD1's split. Each straddled class's port still has its own trace (r = 0), so the sphere has **10 partial co-traces**: one separatrix traced twice, diverging by the angle between the port ray and the edge. That is the sliver and cusp mechanism of DD2, now located exactly.

## 4. Definitions frozen

- **AP1 — owners.**
  - A1 owns separatrix classes, so it publishes every class ray with its port slot (`FieldBranchTopology::singularity_rays()`).
  - A2a classifies arrivals against them with a free function (`classify_field_aligned_singularity_arrivals`) that no stage reads.
  - Neither is a hashed member: the rays derive from what `semantic_digest()` covers, so no digest changes (RA-211).
- **AP2 — matching rule, exact and combinatorial.** The arrival's last exact piece decides the match:

  | Last piece | Matches, in order |
  |---|---|
  | Along a radial edge e (a slide, or a face piece on e) | the edge-supported port on e; else the class with a ray on e; else the class with a ray in each face of e |
  | Through a face interior, in face F on branch b | the class ray in F on b+2 |

  No tolerance is used.
- **AP3 — reachable outcomes:**
  - the approach (`FaceInterior` or `RadialEdge`);
  - the matched port, or none;
  - `portTraced`.

  `portTraced = false` with a port is a D13 retrace owner, witnessed on the mechanical fixture. `portTraced = true` is an unremoved partial co-trace (the sphere's 10, predicted). A null port is an arrival outside every class, which no witness reaches yet.
- **AP4 — removing a partial co-trace is not decided by DESIGN.** D13's remap moves contacts from the removed trace onto the kept one, which is valid only when the two coincide exactly. A partially co-traced port trace that is removed may have stopped other traces where it diverged from the arrival, and those traces would then end nowhere.
  - **Options for the behaviour DEFN:**
    - (A) suppress the claimed port and re-trace to a fixed point (claims only grow, so it terminates);
    - (B) a collinear head-on stop, excluded by D13 Rule 3;
    - (C) keep both, which violates invariant 1.
  - (A) is recommended. It is new normative text for §7.2 step 7, so the behaviour DEFN must **STOP for a user decision**.
- **AP5 — what corners now depend on.** A4 corners (A4D5) on the sphere stay blocked by O51 until AP4 lands. DD5 (A4 unequal-side construction) is unaffected.

## 5. Frozen successors

The [exact manifest](gates/Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Exact_Manifest.md) has the hashes, stop rules and predictions. This is two stacked compile-only CBs and one gate. The handoff named one diff; the split keeps A1 and A2a separate, because the classifier's input turned out to be unpublished A1 data (§3).
- **`M6-CP3-CB-215-P13-SINGULARITY-RAY-CLASSES`** (A1): `e6176e8f…4e83`, three paths, +115/−3, gate row 1009.
- **`M6-CP3-CB-216-P13-SINGULARITY-ARRIVAL-CLASSIFICATION`** (A2a): `d6e980a8…4bfa`, four paths, +251/−0, gate row 1010, and 12 lines in row858.
- **`M6-CP3-TB-EXEC-192`**: the [1010-row manifest](gates/Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Full_Gate_Case_Manifest.tsv) `c9f6325e…e9f5`, membership 1091. Sphere prediction: 10 radial-edge arrivals, all matched and all `portTraced=1`, with the exact trace, node and edge table.

**Syntax-only check** (not compile evidence; 0 errors everywhere, warning sets identical before and after):

| Diff | Translation unit | Warnings, pre / post |
|---|---|---|
| CB-215 | `src/authority/FieldTransportAtlas.cpp` | 56 / 56 |
| CB-215 | `tests/FieldAlignedCurveNetworkTests.cpp` | 42 / 42 |
| CB-216 | `src/geometry/SurfaceCellTracing.cpp` | 40 / 40 |
| CB-216 | `tests/FieldAlignedCurveNetworkTests.cpp` | 42 / 42 |
| CB-216 | `tests/SurfaceCellTracingDisplayTests.cpp` | 24 / 24 |

- The first CB-216 draft added one `-Wmissing-field-initializers` warning; it was fixed before freezing.
- The two CB-216 translation units that include `SourceChartTransitions.h` were checked with `-include iterator` on both sides. That header calls `std::inserter` without `<iterator>`, which local libc++ rejects identically before and after. It is a pre-existing portability gap, noted and not in scope.

## 6. Sequence

1. CB-215, compile only.
2. CB-216, compile only.
3. TB-EXEC-192, 1010 rows.
4. TB-REV-192.
5. Behaviour DEFN (AP4). STOP for a user decision on the removal rule; then CB → TB → TB-REV.
6. The corners DEFN, on the corrected plan.
7. A Vase row.
8. A4 unequal-side construction (DD5).
9. Fill domain, 65B, 65D and O41.
10. **Held or carried, unchanged:** B1, B2, CB-207C/D, parameter deletion → V3b → R1 → O48, CB-190, J6, E5 and promotions.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | The 1010-row manifest's header plus rows 1–1008 hash to `ca16b66d…4081` (TB191), and header plus rows 1–1006 to `a9b80832…0587`. CP2 491 is unchanged. |
| Decisive claims independently re-derived | <ul><li>Source lines read: the arrival paths, retrace selection, the atlas partition and slot order.</li><li>The TB191 logs were parsed by script: 48/24 sphere rays and classes, the 10 slides, the straddle table and the mechanical ray table.</li><li>r = 0 was derived from the counts.</li></ul> |
| Non-vacuity checked | <ul><li>Row 1009 fails on missing rays, a wrong slot or a wrong radial edge.</li><li>Row 1010 fails if the classifier's port differs from D13's `arrivalPort` on any of the four retraces. That is an independent cross-check.</li><li>The sphere lines can print `matched` below 10, `face-interior` or `portTraced=0`.</li><li>The null-port outcome has no witness, as stated.</li></ul> |
| Prior obligations | <ul><li>TB-REV-191 adv. NEXT_TURN (a), (b) and (c) are discharged.</li><li>(b) resolves to D13 = A; removal is AP4, user-pending at the behaviour DEFN.</li><li>DD2 is corrected (§1).</li><li>O51's root is restated (tracker).</li><li>A4D5 and DD5 are carried.</li></ul> |
| Stable accounting | 67/17/50, debt 1, deferred 81; CP2 491/491; the 1008/1008 test gate stands. No change. |
| New obligations | **O51** narrowed: inexact co-traces, removal pending AP4. A pre-existing `<iterator>` include gap in `SourceChartTransitions.h` is noted. |
| ORIENTATION, CHANGELOG, ROADMAP, selector manifest | Currency line and §7 updated; CHANGELOG entry; ROADMAP current-state line; selector manifest note for the 1010-row gate. |
| LESSONS | §4 gains one bullet: search the record for existing reductions before claiming one is absent (TB-REV-191 adv. DD2). |
| Successor frozen | NEXT_TURN `M6-CP3-CB-215-P13-SINGULARITY-RAY-CLASSES`, then CB-216, then TB-EXEC-192. |
| Turn boundary held | Runtime-free. No product, test, selector or fixture byte changed on the branch. |
| review_check.py boundary | Reported in the turn response. |

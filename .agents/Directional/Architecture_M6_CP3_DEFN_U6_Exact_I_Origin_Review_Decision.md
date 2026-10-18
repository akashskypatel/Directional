# RA-95 — DEFN-U6 stopped without a deliverable; Review locates the exact I-endpoint origin; DEFN-U6A narrowed (2026-10-18)

**Turn:** `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER-REV`. **Inputs:** HEAD `73a014c4e`. `src`, `include` and `tests` are identical to CB14A `2ee499a3`, so every `S:` line below is valid there. TB14A result `12141843937` raw logs. **S** = `src/geometry/SurfaceCellTracing.cpp`. **Amends:** RA-94.5 (order) and RA-94.6 (spec).

## RA-95.1 Turn state

- DEFN-U6 began (`acba9a334`) and requested a source snapshot (`df3458d23`; run `39148463200` succeeded). It then stopped with STATUS `IN_PROGRESS` and itself named as successor (`73a014c4e`).
- No deliverable and no document change exist, so there is nothing to adjudicate.
- RA-94.6 asked one turn to search a 21k-line file for an unlocalized origin, and to answer six items besides. That was too wide (LESSONS §6). Review localized the origin (RA-95.3) and narrows the turn (RA-95.5).

## RA-95.2 The 19 B3 identities are one shape (measured)

Every one of the 19 TB14A raw logs (focused30 3/12/14/15/17/18/22/23/24; focused12 5/6; selector 211/217/219/227/230/231; `cp3entry` 2/6) shows the same shape:
- `predicate=endpoint-1`, front 17/203, edge 1–4, faces 0/3, first failed condition `not-same-interior-carrier-point`;
- span 3 on both front records, with reciprocal ordinals `0/1→1/1` and `1/1→0/1`;
- face 0's barycentrics sum to exactly 1 + 2⁻⁵⁵, and face 3's to exactly 1.

Only `chi` differs: 0 in the 17 focused and selector identities, 3 in `cp3entry`. Satisfiability is therefore one template, and per-identity rows add nothing.

## RA-95.3 Exact origin located (Review trace; U6A verifies)

1. `append_arc_schedule` (S:17020-17046) reads the arc's single source-path piece and computes `first`/`second` with `exact_edge_parameter` (S:44-59), which takes the `ExactSourceEdgePoint::parameter` as a `FieldExactRational`. The span is the arc id (`ConformitySpanId::from_network_arc`), so both sides of span 3 share one arc and one schedule.
2. `location_parameter(ordinal)` (S:17205-17218) returns `first + local·(second − first)`, where `local` is the exact `breakpoint_location(span, ordinal)`. It is exact, computed at one site, keyed by (span, ordinal), and expressed in edge orientation (`edge.first` → `edge.second`).
3. **The exact value is lost here.** `append_point` (S:17177) calls `boundary_trace_point` (S:16944-16972):
   - `canonical = to_double(p)`;
   - `alpha = forward ? canonical : 1.0 − canonical`;
   - `bary[first] = 1 − alpha` and `bary[second] = alpha`.
4. The lattice-boundary override (S:17406-17421) places `acceptedBoundary[side].points[k]` at the boundary node. Cell corners copy `points[nodeIds]` (S:17500-17502), and the front edges copy the corners (S:17589-17590). The links onward to the three checkers are **not traced by Review**.

**Model check.** Take `c = to_double(p) = 0x1.9999999999999p-3`. Face 0, forward, then gives (`0x1.999999999999ap-1`, `0x1.9999999999999p-3`) with sum 1 + 2⁻⁵⁵. Face 3, reversed, gives (`0x1.999999999999ap-1`, `0x1.9999999999998p-3`) with sum exactly 1. Both observed triples match bit for bit. `a2bProbeBoundarySourceEntities` shows the same two parameters at region 0 node (5,1) and region 1 node (0,1). Because `to_double(1/5) = 0x1.999999999999ap-3`, p ≠ 1/5, and the exact value of p is not logged.

**Consequence:**
- The one-ULP pair is orientation-dependent rounding at a single site, applied to one producer-origin exact rational that both sides share by construction.
- RA-94.6's "no exact origin" branch is answered: an origin exists. It is the "single canonical parameter" that R9B:29 anticipated.
- The rule stays exact equality, never a tolerance.
- **RA-63.5 still binds.** The endpoint's (span, ordinal) is endpoint-level, unlike the record-level conjunct that RA-61.9 used, but it is not bound to geometry. The design must bind p to each side's doubles; otherwise a forged ordinal pairs different points.

## RA-95.4 Order (amends RA-94.5)

- The DEFN-first rationale (feasibility) is largely discharged by RA-95.3. A narrow documents-only U6A is kept to close link 4 and choose the representation.
- DEFN-U6A-REV then:
  - issues the CB15 (U4) specification;
  - issues the U6 CB specification, or DEFN-U6B if the design is still open;
  - schedules the fixture debt.
- The planned code order U4 → U5 → U6 is unchanged. U6 has no dependency on U4/U5, and DEFN-U6A-REV may reorder them with a reason.

## RA-95.5 DEFN-U6A — `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE` (documents only)

Deliverable `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md`, 80 lines or fewer, citing `file:line` at `2ee499a3`.

1. **Verify or refute** RA-95.3 steps 1–3. A refutation names the line.
2. **Link 4:** list every writer from `acceptedBoundary[side].points[k]` to the compared points at the factory (S:8750-8773), the consumer (S:19480) and the probe (S:20065). Include the corner copy, `reverse_phase_front_cell_cycle`, and any cross-region pairing. State whether any arithmetic touches the doubles after `boundary_trace_point`.
3. **Endpoint to (span, ordinal):** show how each side's `sharedBoundaryInterval` first/second ordinals and `orientation` map to `from`/`to`, and show that the template resolves to span 3, ordinal 1 on both sides.
4. **p itself:**
   - its formula in terms of the arc's `ExactSourceEdgePoint` and `breakpoint_location`;
   - whether p lies strictly in (0, 1);
   - the existing field that would print it, or else the minimal probe a CB would add (named, not written).
5. **Representation.** Compare these candidates:
   - (a) a per-endpoint exact `ExactSourceEdgePoint` on `SurfaceFrontEdge`, set only by the accepted-boundary producer;
   - (b) recomputing p at the checkers from (span, ordinal), stating whether the baseline plan reaches `make` and the consumer;
   - (c) any other candidate.

   For each, state:
   - what reaches all three checkers;
   - how p binds to the doubles, e.g. bit-equality with `boundary_trace_point(p)` for that face and orientation;
   - that an I endpoint from any other producer carries no exact point and stays rejected (fail closed).

   Recommend one.
6. **CB outline** of 10 lines or fewer, applying RA-94.6 items 3 and 5 (rule and negatives) to the recommendation. Include TB predictions:
   - the 19 move past `endpoint-1` of front 17/203;
   - only those of RA-76's 324 one-ULP pairs that share an exact origin are accepted.

   Include falsifiers. Review writes the CB specification.

**Out of scope:** code, builds, runs, probes, U4/U5, fixture debt, selector or harness. **If RA-95.3 is refuted:** say where and stop. Never a tolerance. **Gates:** `document_drift_audit.py --root .`.

## RA-95.6 Sequence

DEFN-U6A → DEFN-U6A-REV → CB15/TB15 (U4) → CB16/TB16 (U5) → U6 CB/TB → RP-01 Review. Each CB follows a reviewed TB, and a RED TB goes to Review. Accounting unchanged: 66/17/49, debt 1, CP2 491/491, R3 403/497, census 425/497.

# M4-CP-SCALE-DEFN-R1 — source-boundary alias reconciliation definition record

**Turn:** `M4-CP-SCALE-DEFN-R1`
**Disposition:** COMPLETE / DEFINITION FROZEN / RUNTIME-FREE
**Exact successor:** `M4-CP-SCALE-CB23`
**Accepted runtime authority unchanged:** artifact `10473134357`, semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47`, selector426 **426/426**, selector SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, first425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`, owners **30/280/75/41**.
**Stable accounting unchanged:** **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 1. Scope and evidence boundary

This turn is definition/review only. It executes no generated Directional runtime, performs no configure/compile/link/package operation, and changes no product, test, fixture, benchmark, build, or selector byte. The source proof was re-derived from exact snapshot run `35364783516`, artifact `10556186428`, event/snapshot SHA `e00453cae28c583f333b23324ba9dbcf8d5688e2`; the snapshot metadata reports `runtimeExecution=false`, 5,279 files and archive SHA-256 `35207fef1d0cd19fba09f09c3a7c0db5de531467847c6f4e05e8ccb7e9124ab8`.

One process deviation is recorded rather than normalized away: the initial control-plane invocation batched the root `STATUS` read with the handoff/TODO/tool-conservation reads before the entry beacon and before explicitly freezing `READ_MODE`. The entry beacon was still the first repository mutation, no source/code was inspected and no runtime/build occurred before correction, and the turn then froze `READ_MODE=snapshot` and used the verified snapshot for all broad inspection. This is an instance of the existing setup-order/authority-first lesson family, not a new product finding.

## 2. Static ownership/dataflow proof

| Datum / relation | Current producer or container | Semantic domain proved by source | DEFN-R1 disposition |
|---|---|---|---|
| source boundary loop row | `dual_cycles` in `src/geometry/MeshTopology.cpp` | one aggregate row for every connected source `mesh.boundaryLoops[i]`; every vertex on that loop maps to the same row through `vertex2cycle` | **global source-boundary cycle** |
| boundary index numerator | `effort_to_indices` / cross-field finalization | computed once on the complete source cycle basis before projection back to vertices | **one global numeric fact per source-boundary cycle** |
| `crossField.singularCycles/singularIndices` at boundary vertices | field producer | per-vertex projection of the same aggregate source-boundary cycle index | **legacy aliases, never owners** |
| `rawBoundarySingularity` | `FieldTransportAtlas::make` | copies the legacy vertex-keyed representation | **representation input only; must be reconciled then collapsed** |
| regional `FieldCycleWitness::BoundaryLoop` | `FieldTransportAtlas::make` after hard-feature partition | typed by `TopologyRegionId`; its `turningLift` is recomputed on that regional mesh and receives the region Gauss-Bonnet correction | **region-relative cycle fact, not global index authority** |
| `boundaryCycleByGlobalVertex` | current atlas implementation | vertex -> one regional boundary cycle | **invalid authority shape when a cut vertex belongs to several regional loops; must be replaced** |
| `sourceBoundaryBoundSingularityCount` | atlas diagnostics | current writer-side count only; no independent semantic consumer found | **diagnostic only** |
| `separatingFeatureCycleByGlobalVertex` | atlas | globally interior singularity incident to hard feature separating two topology regions | **preserve CB21 owner semantics** |
| `slitCycleByGlobalVertex` | atlas | globally interior singularity on a same-region slit boundary | **preserve existing owner semantics** |

The decisive source facts are independent of R9's error string. `dual_cycles` explicitly aggregates each source boundary loop and maps every vertex on that loop to that one row. `effort_to_indices(CartesianField&)` computes `fullIndices` over the cycle basis and then projects the relevant row index to vertices. In contrast, every atlas `FieldCycleWitness` contains a `TopologyRegionId`, and region construction recomputes a boundary cycle lift after hard-feature partition and Gauss-Bonnet correction. Those two numbers therefore live in different authority domains.

The independent boundary validator already reflects the intended global contract for the uncut one-region case: it reconstructs whole-source cycle facts, finds the global boundary-loop row, and requires every supplied raw alias on that source loop to equal the global lift. The existing negative that mutates one supplied boundary alias must remain rejecting. `SurfaceArrangement.cpp` also provides a compatible identity precedent: source boundary loops are canonically reconstructed from exact source boundary edges rather than owned by one incident regional object.

## 3. Normative amendment — source-global boundary-cycle authority

### D1 — one global numeric owner

For each connected source boundary loop, A1 SHALL expose one typed **source-global boundary-cycle fact**. Its identity is a source-topology identity, distinct from `FieldCycleId` and `TopologyRegionId`. The implementation SHALL introduce `SourceBoundaryCycleId` or an equivalently typed source-boundary-cycle key; it MUST NOT use a source vertex, a regional cycle ID, a minimum region, or container order as this identity.

The canonical semantic key is the source component plus the exact cyclic source-boundary topology represented by its `SourceEdgeTopologyKey` loop, canonicalized independently of source-face row order and loop start/orientation. The numeric `indexNumerator` is the value from the **same producer cycle-index computation** that currently yields `fullIndices` and the legacy boundary aliases. A1 SHALL NOT reconstruct a second competing boundary-index number from regional atlas cycles.

### D2 — regional loops are support associations

A regional `FieldCycleWitness::BoundaryLoop` remains region-relative authority for its own regional topology and `turningLift`. A source-global boundary cycle MAY be associated with one or more regional boundary loops after hard-feature partitioning. Multiple associations are normal when a hard cut reaches a source-boundary vertex or partitions the source boundary across regions.

For one source-global boundary cycle `G`, let `E(G)` be its exact source-boundary edge set and let `S(R)` be the subset of true source-boundary edges supported by an associated regional boundary loop `R`. A successful atlas SHALL satisfy:

`union S(R) = E(G)` and `S(R_i) intersect S(R_j) = empty` for distinct associated regional loops, with all associations on the same source component.

Regional loops may additionally contain hard-feature cut edges; those edges are not members of `E(G)`. Source-boundary vertices may occur in multiple regional associations at cut endpoints and therefore cannot own the association. Zero regional associations, incomplete edge cover, duplicated source-boundary edge cover, or foreign-component cover is a typed reconciliation failure.

### D3 — exact legacy-alias reconciliation before collapse

Legacy per-vertex boundary singularities are a redundant encoding of D1 and remain useful only as a falsifiable compatibility surface until the field product is migrated. For global boundary cycle fact `G=(K,n)`:

- when `n != 0`, the producer representation SHALL contain exactly one alias `(v,n)` for every source-boundary vertex `v` on `K`;
- when `n == 0`, it SHALL contain no nonzero boundary alias on `K`;
- every supplied boundary alias SHALL map to exactly one global source-boundary cycle and equal that cycle's producer-owned `n`;
- duplicate, missing, foreign, or numerically inconsistent aliases SHALL reject before alias collapse.

After this exact check, the per-vertex aliases are discarded as representation, and D2's regional support-cover relation is checked. The implementation SHALL NOT compare the global `n` to any regional `BoundaryLoop.turningLift`, individually, by sum, or through a selected representative. This preserves tamper rejection without introducing a second numeric authority.

### D4 — publication and port semantics

The atlas SHALL retain the typed source-global boundary-cycle facts and the exact global-to-regional support association separately from `cycles()`, whose `FieldCycleWitness` entries remain region-relative. Legacy per-vertex aliases are not published as semantic owners.

Source-global boundary-cycle facts SHALL NOT become `FieldSingularityFact`, SHALL NOT create `FieldSingularityPortAttachment`s, and SHALL NOT participate in the four-index interior port-class arithmetic. `sourceBoundaryBoundSingularityCount` remains diagnostic only; under the corrected representation it counts, per region, reconciled nonzero global source-boundary facts that have source-boundary support in that region. The same global fact may therefore contribute once to more than one region's diagnostic count. This count carries no numeric or ownership authority.

### D5 — frozen unaffected authority

The following semantics are unchanged: CB21 globally-interior separating owners and `BarrierAbsorbed` zero-port behavior; same-region slit ownership; exact-one-owner reconciliation for interior singularities; branch/port-class arithmetic; region/cycle ordering and all-component support; hard-feature partition authority; accepted selector426/first425 bytes; retained genus-two fixture/rawfield bytes; TB11 package authority; and the prohibition on selector427 before reviewed S5 acceptance.

## 4. R9 and carried-obligation adjudication

`M4-CP-SCALE-TB12-R9-EXEC-CAND-01` remains **OPEN / PRODUCT / existing `RP-01 AUTHORITY_DOMAIN_CONFLATION` / NON-STABLE**. DEFN-R1 does not claim recovery because it executes no product correction. It does, however, close the specification gap: R9's second regional insertion and later global-numerator/relative-lift comparison are both invalid uses of a global fact through region-relative keys.

R8 `RP-02 TEST_AUTHORITY_COVERAGE_GAP` remains **CLOSED / CORRECTION ESTABLISHED**. Production S5 `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01` remains OPEN; R9 did not execute S5. `M4-CP-SCALE-DEFN-OBS-04` remains OPEN / NARROWED, because source/topology/raw-field authority is supported but production atlas/A3 reachability is still unproved. The dedicated `make_zero_transport_field` audit and all inherited CP3 / `G4-B002` / `G4-B003` obligations keep their existing owners.

No stable regression is added or reclassified, so totals remain **49 / 14 / 35** and debt **5**.

## 5. Exact successor — `M4-CP-SCALE-CB23`

CB23 is one bounded Code + Build turn implementing only the frozen D1-D5 boundary-authority migration and focused test authority. It may compile/package but SHALL execute no generated Directional runtime. Its authoritative plan is `Architecture_M4_CP_SCALE_CB23_Source_Boundary_Global_Cycle_Authority_Code_Build_Plan.md`.

The implementation MUST stop rather than broaden if it cannot expose the global numeric fact from the existing field producer's same cycle-index computation; if it needs a minimum/stable region to choose an owner; if any global-index/regional-turning-lift equality remains; if source-boundary edge cover cannot be made exact without weakening hard-feature partition semantics; or if the correction touches selector427, fixture bytes, S5 acceptance, or unrelated interior-owner logic.

## Review closeout

| Required closeout item | DEFN-R1 result |
|---|---|
| Accepted selector prefix re-hashed | **UNCHANGED / carried from accepted TB11 and R9 Review.** DEFN-R1 changes no selector and does not use selector bytes to decide D1-D5; selector426 remains `41f4d559...b5114`, first425 `e0e0f394...790e0b`. |
| Decisive claims independently re-derived | **YES.** Whole-source boundary-cycle aggregation/projection, region-relative cycle reconstruction/correction, raw alias reconciliation, interior separating/slit ownership and independent boundary validator were re-derived statically from the exact snapshot. |
| Non-vacuity / falsifier checked | **YES.** R9's cut boundary vertex belongs to multiple real regional loops; one legacy one-owner map must collide. Existing single-alias mutation remains a required rejector, and D2 adds exact edge-cover falsifiers. |
| Prior observations / candidates reconciled | **YES.** R9 CAND-01 remains open RP-01; R8 RP-02 remains closed; production S5 RP-01 and DEFN-OBS-04 remain open; accounting unchanged. |
| New candidate / observation | **NO new stable candidate.** CB23 owns implementation of the frozen rule; process-order deviation is recorded as an existing setup-order lesson instance. |
| `ORIENTATION.md` updated | **YES.** Currency, §3, witness state, open problems and recurring RP-01 instance updated. |
| `CHANGELOG.md`, `ROADMAP.md`, TODO, handoff updated | **YES.** Current authority and exact successor changed to DEFN-R1 -> CB23. |
| Selector manifest updated | **N/A.** No selector byte or lineage changes. |
| `LESSONS.md` updated | **N/A.** The reusable lesson is already represented by authority-domain/legacy-alias collapse and setup-order lessons; no novel durable lesson is introduced. |
| Consolidation performed | **YES.** R9 Review and consumed DEFN-R1 plan are folded into `M4_Consolidated_Record.md` §2.67 and removed from the live set. |
| Exact one successor | **YES: `M4-CP-SCALE-CB23`.** |
| Turn boundary | **PASS.** Documentation/definition only; no product/test/fixture/build/selector mutation and no Directional runtime. |
| `review_check.py boundary` | **PASS.** `review_check.py boundary --expect-selector 426=41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` passed every product/test/build/selector/durable-marker check. |
| `STATUS` lifecycle | Entry beacon: `M4-CP-SCALE-DEFN-R1 / IN_PROGRESS`, started `2026-09-18T15:48:00Z`. Final COMPLETE beacon with successor `M4-CP-SCALE-CB23` is reserved as the last repository mutation after cleanup. |
| Pushed to origin / branch in sync | Durable documentation is transported to the configured working branch; final control-plane verification occurs after cleanup and before the last `STATUS` write. |

---

## Independent review addendum (reviewing agent)

Runtime-free. The definition is **upheld**. An independent source trace of
`rawBoundarySingularity`, `boundaryCycleByGlobalVertex` and the source-boundary `BoundaryLoop` witnesses was
performed against the exact atlas source and corroborates D1–D5 rather than correcting them. One additional
consumer site is recorded for CB23, and two checks are recorded as closed so they are not re-opened.

### V1 — D2's edge-partition holds exactly on the subject that failed

The invariant is not merely plausible; it is satisfied where the old one broke. For the skew fan, the global
source-boundary edge set is `E(G) = {(0,1), (1,2), (2,3), (3,0)}`. Cutting at the radial hard features `(1,4)` and
`(3,4)` yields regions `{0,3}` and `{1,2}`, whose true source-boundary edges are:

- region `{0,3}` (faces `(0,1,4)`, `(3,0,4)`) supports `{(0,1), (3,0)}`;
- region `{1,2}` (faces `(1,2,4)`, `(2,3,4)`) supports `{(1,2), (2,3)}`.

Their union is exactly `E(G)` and their intersection is empty, so D2's cover-and-disjointness relation holds.
Meanwhile source-boundary vertices `1` and `3` each occur in **both** associations — precisely the situation that
made the old per-vertex map fail.

Partitioning on **edges** rather than vertices is the load-bearing choice. A hard-feature cut meeting the source
boundary splits it *at a vertex*, so vertices are necessarily shared while edges are not. An invariant keyed on
vertices could not have been made exact; this one can.

### V2 — both population sites must convert, and the *uncovered* one is the single-face path

`boundaryCycleByGlobalVertex` is populated at two sites with different uniqueness semantics:

- `src/authority/FieldTransportAtlas.cpp:2087` — plain `emplace`, failing on **any** duplicate key. It sits inside
  the guard `regionRows.size() == 1U && region.euler_characteristic() == 1 && region.boundary_loop_count() == 1`
  (`:2027`), so it serves **single-face disc regions** only;
- `:2390-2393` — the general path. It emplaces and rejects only a *different* stored owner
  (`!inserted.second && inserted.first->second != owner`), tolerating idempotent re-insertion.

**Correction to this addendum's first revision**, which attributed R9's failure to `:2087`: it did not. The skew
fan's regions `{0,3}` and `{1,2}` carry two faces each, so `regionRows.size() == 1U` is false and they take the
**general** path. R9 failed at `:2393`, because regions `{0,3}` and `{1,2}` supply *different* owners for shared
boundary vertex `1`.

That reverses which site needs attention. The CB23 plan's required control — *"one hard-cut source boundary cycle
supports two regional boundary loops → atlas construction succeeds and retains both support associations"* — uses
the skew fan and therefore exercises the general path that already failed. **The single-face path at `:2087` has no
planned coverage**, and it is the stricter of the two: it rejects *any* duplicate, so a single-face region whose
boundary loop covers only part of `E(G)` would still fail after the general path is converted.

The case is realizable, so the obligation is satisfiable rather than aspirational: cutting the skew fan at `(1,4)`
and `(2,4)` leaves face `1` alone as a region — triangle `(1,2,4)`, `χ = 1`, one boundary loop, satisfying the
`:2027` guard — whose only true source-boundary edge is `(1,2)`, a proper subset of `E(G)`. That reaches `:2087`
with a partial cover.

CB23 must therefore convert **both** population sites and the reconciliation consumer at `:2504-2516`, and its
focused test authority needs a **single-face-region** subject alongside the existing skew-fan control.

### V3 — two checks closed, so they are not re-opened

- **`BoundaryLoop.turningLift` is not overloaded.** Two construction paths assign it from different expressions —
  `:2052-2055` sets `turningLift = requiredIndexSum = 4 · χ(region)`, while the general path at `:2194/:2271` sets
  it from the rounded exact holonomy lift. The shortcut is guarded by
  `regionRows.size() == 1 && region.euler_characteristic() == 1 && region.boundary_loop_count() == 1`, so it fires
  only for a single-face disc region, where `4 · χ = 4` is that region's own boundary holonomy. Both paths
  therefore yield a region-relative quantity, and D2's treatment of `turningLift` as region-relative authority is
  consistent across them. No action.
- **The cross-domain equality is removed where it lives.** `:2512` required
  `boundaryCycle.turningLift == numerator`, comparing a region-relative lift against a global per-vertex alias
  numerator. D3's prohibition on comparing an alias numerator to any regional `turningLift` reaches exactly that
  site, which is the one CB21 left standing when it removed the same equality from eligibility.

### V4 — beacon shape

`STATUS` currently carries `Resumed at: UNKNOWN` and `Ended at: UNKNOWN`. The canonical format specifies
`<UTC_TIMESTAMP_OR_EMPTY>` for both, so those should be empty rather than `UNKNOWN`; `Successor: UNKNOWN` is valid
and correct while the successor is undetermined. Left for the owning turn to correct at closeout rather than
rewritten here, since the turn is still `IN_PROGRESS` under the implementation agent.

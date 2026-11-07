# RA-150 — TB34-REV audit: periodic-route fixture is a face gauge, not a transition edit (2026-10-24)

**Turn:** `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV-AUDIT` (Review, documents only). **Audited:** [TB34-REV](Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md) and its [CB34 plan](Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md). Source inspected at `c57e4e1d9` (no product/test change since CB33 `f807c2b89`). **Verdict:** owner classification **ACCEPTED**; CB34 transformation **CORRECTED** (RA-150.3), precondition and stop rules **ADDED**. No runtime or build was run in Review.

## RA-150.1 — Classification independently confirmed

- Parsed `benchmarks/fixtures/milestone-g/cylinder.obj` and `cylinder.rawfield` (script, Python `-I`): faces 0 `(0,1,2)`, 1 `(0,2,3)`, 30 `(30,0,3)`, 32 `(3,2,32)`; vertices 0,1 boundary, 2,3 interior. Route steps 0/1 are faces 0→1 over `(0,2)` and 1→30 over `(0,3)` (`expected_forward_periodic_route`, SP10:4205).
- Principal matchings recomputed from the raw field by hinge transport are **0 on every interior edge** (including all three face-1 edges).
- The vertex-2 star contains `(0,2)` and `(2,3)`; the vertex-3 star contains `(0,3)` and `(2,3)`. The two-edge edit therefore breaks **both** LocalVertex cycles. Whether region-local row 0 is vertex 2 or vertex 3 does not matter: TB34-REV's "vertex 2" relies on unverified local ordering.
- S1 (`FieldTransportAtlas.cpp:2581`) compares matching composition with the effort/curvature lift. It correctly rejects a field whose matchings no longer agree with its effort around a vertex. **Fixture invalid; A3 not at fault.**
- S2 is unreachable: correction ≡ 0 mod 4 is enforced at FTA:2689, and S1 already checked the same cycle. **RA-149.3's two-site premise is withdrawn.**

## RA-150.2 — Missing history (affects TB35 predictions)

- `selector:189–195` are rows 189–195 of the accepted 449-line green prefix. They went RED at R3, once A4 required A3 (four `A4_NOT_PRODUCED_UNTYPED`, `193` `A4_INVALID_FINAL_CELL_STATE`).
- R4 (`7ccdcd527`, `2be228d96`, `e0cc0415b`; 2026-10-11) added `build_periodic_route_network_with_source_atlas`. Its record and comment say the source A3 is built "from the original full fixture cross field", but every call site passes the **edited** field. That is what moved the first failure to S1.
- **Prohibited "fix":** passing `fixture.authoritativeField` as `sourceField`. A4 takes route transport from A3 `transition_value` (raw matching, FTA:2039). The negatives `NonzeroNetCycle…` and `Malformed…` depend on tracing/source disagreement producing `PeriodicHolonomyMismatch`, so the positives must have source == tracing.
- **Prediction:** clearing S1 may re-expose an A4 first failure from R3. That is a new producer-owner finding (STOP → Review). It is not a reason to retune the fixture.

## RA-150.3 — Correction: a gauge acts on the face frame too

The CB34 plan changes only the three edge `matching` values and forbids changing anything else. That is a transition coboundary, not a gauge change:
- With face 1's directions untouched, matching ±1 pairs vectors that are 90° apart, while `effort` still says they are aligned. The field becomes geometrically inconsistent on each edge.
- A3 accepts it only because S1 checks cycle residues, not per-edge geometry. That would make a test pass by relying on a validator gap (LESSONS §2).
- In A4, `resolve_branch_transition` sets target branch = source + A3 transport and then uses the target face axis (`SurfaceCellTracing.cpp`, atlas branch). Face 1's propagated branch would physically turn 90°.

**Required representation gauge, g(face1)=+1, applied to the CrossFieldResult used as both source and tracing field:**
1. **Frame:** relabel face 1's quarter-turn frame (`primaryDirections`, `secondaryDirections` and the `rawField` row's four vectors) so its A3 `rawGauge` shifts by +1. A3 orders directions as `{p, s, −p, −s}` (FTA:275). The expected relabel is `p'=−s, s'=p` with vectors shifted `u'_k=u_{k−1}`, but the CB **must confirm the direction with the invariance oracle**, not take it from this text.
2. **Transitions:** add the directed difference g(to)−g(from) to all three interior edges of face 1, also updating the compact `matching` entries if populated: 0→1 **+1**, 1→30 **−1**, 1→32 **−1**. `effort` is unchanged.
3. **Precondition:** the original directed matchings on those three edges are 0. Apply the change additively and `throw` if the precondition fails. Never *set* values.
4. Find face 1 by route topology (`expectedRoute[0].targetFace == expectedRoute[1].sourceFace`), so reflected and reordered fixtures resolve correctly. Find the third edge as face 1's remaining interior edge.

**Invariance oracle** (new test identity outside the frozen selector; non-tautological):
- A3 built from the gauge field succeeds.
- Its `branch_topology().semantic_digest()`, `frames()` and `transports()` equal those of A3 built from the unedited `authoritativeField`.
- Its raw `transition_value` is +1/−1/−1 on the three directed face-1 steps.
- The two-edge-only construction (the current helper) fails `make` with `CycleTransportMismatch`, `site=cycle-transport`, LocalVertex.

## RA-150.4 — Turn decomposition

CB34 (amended) is one test file, compile only. Edits:
- the gauge helper (frame, transitions, precondition, topology-located face);
- the new invariance-oracle test.

It makes no change to the seven test bodies, production, selectors or workflows. Then CB34-REV, followed by TB35 on the Review-issued manifest:
- 7 rows;
- the invariance oracle;
- 2 A3 guards;
- 3 TB33 controls.

Then TB35-REV. On S1 clear but A4 RED, write a DEFN for the periodic-producer owner and do no fixture tuning. The remaining queue is unchanged: untyped 7 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01. `DIAG-RETAIN`, DEFN-SEAM-NZ, Periodic, RA-146.2/4, RA-45.4 and G4-B002 are carried.

## RA-150.5 — Minor notes (no turn)

- CB33-REV says S1 `sourceVertex` is "unavailable until after the return". It is a pure lookup (`interiorLocalVertices[row]` → `globalVertexByLocal`) and is available before the return without reordering. The omission is accepted and carried as optional diagnostic debt.
- S2's `cycleRowIndex` is atlas-global. Leave the dead guard as is.

**Accounting unchanged:** stable 66/17/49, debt 1; CP2 491/491 accepted; TB32 481/500 candidate (19 inherited RED); TB34 5 PASS / 7 RED diagnostic; selector 497 frozen; RP-01 open, RP-02 unreached, Gate C suspended.

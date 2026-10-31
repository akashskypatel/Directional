# M6 CP3 R6 — corner-assignment authority: source-static definition

**Turn:** `M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC` (Definition only). **Source authority:** exact snapshot commit `c85bd360098bb0675443b5ca62702a9b2df0a686`, run `38837317846`, artifact `12019178209`; artifact ZIP SHA-256 `37dab2b2f1292e7f0a530042b90be1d9813ee4e7eb4e76df7cd50226c2e98bdb`; `source.tar.gz` and all 5,656 manifest entries verified. The prior independently reviewed RP-01 observation is RA-70, immutable TB5 artifact `12017109271`; **no execution** in this turn.

## Verdict: the pre-nominated three writers do not own the measured phase-front corner

The instruction to name one of the three named `proposal.corners` writers as the producer of `SurfacePhaseFrontCell::corners[(side+1)%4].face` is falsified by the source call graph. **None of the three is the active producer of that field on the rejected phase-front path.** It would be a false attribution to name `:11269` merely because it discards one of two corner walks.

| Named writer | Source of its corner `face` | Relation to boundary path | Reachability for the measured phase-front rejection |
|---|---|---|---|
| `SurfaceCellTracing.cpp:10479` | `bottomLeft/Right`, `topLeft/Right` returned by `intersect_proposal_flowlines`; `ProposalFlowlineIntersection.point` retains a source face | Extracts each `boundaryPaths` immediately from the paired flowlines at `:10481-10492`; geometric boundary closure is checked at `:10526` | This writes **`SurfaceCellProposal`**, in the seed-proposal fallback, not `SurfacePhaseFrontCell`; `make_surface_cell_proposal` calls it at `:11214-11218` and the network calls that function only at `:19814` after the rejected phase-front return. Not reached. |
| `:11269` | In the fallback `make_surface_cell_proposal`, `xy.point` from one walk order replaces the corresponding corner; `yx.point` is not retained (`:11225-11269`) | The `xy`/`yx` disagreement checks only 3D distance (`:11263-11273`); independent side walks then populate `boundaryPaths` (`:11294-11363`). Geometric endpoint matching can accept a different supporting face at a common vertex | **RA-70.14's named falsifier holds:** phase-front rejection returns at `:19801-19803`; the fallback call at `:19814` is not reached. The lack of a face comparison is real in this fallback but does not explain RP-01. |
| `:19790` | Copies already published `SurfacePhaseFrontCell::corners` into `SurfaceCellProposal::corners` unchanged | Copies `cell.boundaryPaths` at `:19791` without reconciling face identity | Executes only if `network.phaseFront.is_produced()` at `:19781`; rejected phase-front exits at `:19801-19803`. It is propagation, not an origin; not reached for RP-01. |

## Actual producer and missing authority (single responsibility boundary)

1. `build_uniform_phase_front_state` chooses the planar `build_uniform_phase_front_for_faces` producer first (`:17724`, `:17884-17890`). That producer samples all lattice vertices through **`point_on_source`** (`:12949-12959`). This function loops over active source faces and accepts the **first** face whose barycentric coordinates contain the lattice UV point (`:11477-11509`), returning its `face` independently of the cell side and any subsequently traced path. At a shared source vertex, more than one triangle can satisfy the barycentric test.
2. `build_uniform_phase_front_for_faces` copies those preselected `SurfaceTracePoint`s into `SurfacePhaseFrontCell::corners` at **`:12985-12989`**, then constructs each `boundaryPaths[side]` separately using `segment_on_source` at `:13012-13022`. It creates `SurfaceFrontEdge.from`/`.to` directly from those corners (`:13031-13035`), so later A4 endpoint checks inherit the choice.
3. `orient_and_validate_phase_front_cell` calls `validate_closed_boundary_paths` (`:12718-12722`, `:12736-12739`), but that validator defines corner/path equality as **3D positional distance within tolerance** (`:7319-7357`), not source-face/chart identity or route-incidence agreement. A shared vertex represented in f7 and f3 can be position-coincident and still violate the oriented path's source-face authority. A possible cycle reversal (`:12728-12731`) reorders corners, but does not supply an authoritative per-side face.
4. The A4 route rejection occurs before the produced-cell copy at `:19790`: `endpoint_certificate` is called at `:19353-19359`, and a missing certificate enters the rejection block at `:19360`. RA-70 already observed `toFace=7` with second path faces `{3}` in all 21 junction cases while 23 controls have `toFace=3`; both groups have path-face sequence `{0},{3}` and `hit_from=1`. That is source evidence of a **corner face decoupled from its owning route**, not a defect in route publishing or in consumer edge admission.

**Named locus:** the *planar phase-front lattice point-to-source-face selection* `point_on_source` at `:11477-11509`, as made authoritative for corner faces by `build_uniform_phase_front_for_faces` at `:12953-12959` / `:12985-12989` **without reconciliation to `boundaryPaths`**. This is one producer responsibility, not the unrelated fallback `xy.point` writer. The source proves that this producer permits the missing consistency check; the exact per-vertex choice responsible for f7 remains the **reviewable attribution**, not an executed new measurement.

**Rejected alternatives:** do not relax A2b/A3/A4 orientation/carrier checks, construct a consumer-side vertex-star bypass (RA-65 gate C remains SUSPENDED and moot for RP-01), reinterpret the edge-key domain, or claim `:11269` causes a phase-front rejection. No repair, new predicate, producer change, compile, test, benchmark, selector change, or acceptance promotion is authorized in this Definition turn. RP-02 remains UNREACHED; stable ledger 66/17/49, debt 1; accepted CP2 491/491; rejected R3 403/497; frozen selector 497 unchanged.

## Independent decision gate

The separately bounded successor is **`M6-CP3-DEFN-R6-CORNER-ASSIGNMENT-AUTHORITY-SPEC-REV`**, an evidence-only independent Review of this source-static locus. **Falsifiers**: (a) source control flow reaches either `:10479` or `:11269` before the A4 rejection, (b) the measured phase-front cells are not produced by planar `point_on_source`, (c) a pre-A4 check already requires the selected corner's source face to belong to the oriented owning boundary path, or (d) a later mutation between `:12987` and A4 actually changes that source face. If any falsifier holds, reject the attribution and re-open the source producer census. Review must independently trace source and decide the exact implementation successor, if any. No successor code/TB work is preauthorized.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector data accessed or changed; no acceptance claim |
| Decisive claims independently re-derived | Source-static control-flow and actual corner producer/validator read from verified exact snapshot; no prior narrative treated as producer authority |
| Non-vacuity checked | Four explicit falsifiers above; the designated `:11269` hypothesis failed against reachability |
| Prior obligations discharged/carried | RA-70.14 prediction **falsified**; RP-01 producer classification submitted for Review, RA-65 gate C suspended; RP-02 remains unreached |
| Stable accounting | 66/17/49, debt 1; accepted CP2 491/491, rejected R3 403/497, frozen 497; unchanged |
| New candidates/obligations recorded | No new stable ID; RP-01 locus refined in tracker and handoff |
| ORIENTATION currency line | R6 Definition, 2026-10-16 |
| ORIENTATION §3 / §4 / §7 / §8 | Current state, no new runtime, review priority and false-locus pattern recorded; prior sections retained |
| CHANGELOG | New R6 Definition entry |
| ROADMAP | n/a: CP3 milestone/checkpoint state unchanged; current R4 historical status is superseded by TODO/handoff |
| Selector manifest | n/a: no accepted or proposed selector modification |
| LESSONS | Existing evidence-priority and false-positive reachability discipline applies; no novel generalized lesson claimed |
| Consolidation under CLEAN_UP_POLICY | n/a: Definition does not authorize Review-only historical consolidation |
| Successor frozen | One independent evidence-only Review named above; further code/TB successor not authorized |
| Turn boundary held | Source read and documentation only; no C++/test/selector/benchmark/compile/runtime changes |
| review_check.py boundary | PASS: `python3 .agents/Directional/tools/review_check.py boundary` in local Git-backed exact snapshot with staged six-document diff; no product/test/selector mutations |
| `STATUS` lifecycle maintained | Entry set to R6 IN_PROGRESS; final beacon written last after repository verification |
| Pushed to origin, branch in sync | Require GitHub remote commit/ref evidence; no local-origin claim from snapshot |

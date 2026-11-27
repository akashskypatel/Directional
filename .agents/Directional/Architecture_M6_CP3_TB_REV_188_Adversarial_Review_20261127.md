# TB-REV-188 adversarial continuation (2026-11-27 UTC)

Continues `M6-CP3-TB-REV-188` after the [independent review](Architecture_M6_CP3_TB_REV_188_Completion_Receipt_Activated_Full_Gate_Independent_Review_20261127.md). Runtime-free: static source review. Haiku agents traced call paths read-only and ran syntax-only checks in a throwaway `CLAUDE_` worktree, since removed. Product and test bytes are unchanged.

## Verdict

- **Upheld:** the 1006/1006 activated test gate, the row971 discharge (A1), and V5 non-acceptance with B2 carried.
- **Upheld with a correction:** B1's root class. The repeated node is in the original input cell.
- **Realigned: the trajectory.** TB-REV-188 says the sphere "reaches completion". It does, but only the completion of the **legacy tracing fallback**, not of the architecture route. CB-211's question (which input cell repeats a node) is about that fallback. The decisive open question is why no A4 producer built any of the sphere's 14 plan regions.
- **Withdrawn:** the [CB-211 prose plan](gates/Architecture_M6_CP3_CB211_P13_Completion_Input_Boundary_Witness_Plan_20261127.md).
  - It is a prose plan, not an exact diff.
  - It bundles a mapping between stages that it defines nowhere ("record UNKNOWN").
  - Replaced by two exact test-only diffs, CB-211R and CB-212, measured in one gate.
- **Corrected, my own earlier statements:**
  - [TB-REV-185 adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md) X1 predicted that activation sends the sphere into quotient production (`:13316`). The CB-210 string shows it took the `phaseFrontProduct == nullptr` branch instead, so it never ran quotient production.
  - [TB-REV-186 adv.](Architecture_M6_CP3_TB_REV_186_Adversarial_Review_20261126.md) AA3 called completion preparation "the product blocker". It is the fallback's blocker, not the architecture's.

## Findings

**BB1 — The sphere is on the legacy fallback. This is certain from the code plus the measured string.**
- A `BoundaryParityRepair:` detail comes only from `complete_surface_cell_complex`. That runs only in the `else` branch of `useAuthoritativePhaseFront` (`RemeshPipeline.cpp:13961–13997`), and the produced branch cannot emit `PreparationRejected`. So `traceNetwork.phaseFront.produced_product()` was null (`:13120`, `:13329`).
- Row858 prints an empty `firstInvalidStage`. A phase-front rejection writes `tracing/phase-front` into that empty field (`:13259–13266`), and nothing on the path to completion clears it (`:13000–14400`). So the outcome is almost certainly `NotApplicable`; that is inferred, and CB-211R prints it.
- `build_uniform_phase_front_state` returns `NotApplicable` exactly when every regional producer (uniform, periodic annulus, curved bounded-disk) declined a region, none produced any region, and there are no hard features: "the historical NotApplicable fallback" (`SurfaceCellTracing.cpp:20225–20233`).
- The network then falls through to the legacy seed and trace path (`:22447–22450`), followed by arrangement, simplification and closed completion. The code itself calls this "the legacy tracing fallback" (`RemeshPipeline.cpp:13317–13319`).

**BB2 — That route cannot produce certified output, so repairing B1 is off the trajectory.**
- DESIGN §2.1 item 7 requires every region to consume the certified plan unmodified. §2.1 forbids fallback or generic-producer substitution in certified output. §5.2 allows degradation only per region at A4, by a declared degraded producer (D2) or by omission (D3).
- The legacy route re-traces from seeds and recomputes parity itself (closed-completion `BoundaryParityRepair`). A4's postcondition says "no shared decision is recomputed"; parity is A3's T-join.
- A topology repair of the fallback's completion input would at best produce an uncertified sphere through a substitute path. That could be mistaken for progress.
- The architecture-route blocker is **A4 coverage of the sphere's 14 plan regions**, whose per-region decline reasons are not retained (a `NotApplicable` phase front has no payload, `SurfaceCellTracing.h:2437`).

**BB3 — B1 correction and a falsifiable prediction (fallback evidence, kept off the critical path).**
- The independent review's chain (same-cell twins excluded; fresh split nodes unique; order kept) is correct. It omits three things:
  1. `subdivide_surface_cell_complex_edges` rebuilds and audits **every** cell, touched or not (`SurfaceCellFeasibilityRepair.cpp:1352–1618`). The reported cell is therefore the lowest-indexed non-simple cell of the whole complex and need not relate to the parity selection.
  2. The rebuild resets every closed cell to one cycle (`:1600–1602`). Parity repair accepts non-disk input (`validate_incidence_allowing_nondisk`, `:1665`) but can only output all-simple cells, and it spends 106 full rebuilds discovering a precondition failure. This contract gap is recorded, not repaired.
  3. A disjoint multi-cycle cell fails as `NonSimpleBoundary` at the cycle junction (`:527`), not as `RepeatedBoundaryNode`. So the audited cell is either a pinched single walk or cycles that share their junction node.
- **Contract contradiction in the code.** The arrangement sets `disk = simpleCycle || cutCellDisk` (`SurfaceArrangement.cpp:6402`). A bridged cut-cell disk is labelled a disk. Simplification's bridge healing skips every `disk` cell, and every bridge with singularity support or without layout support (`SurfaceComplexSimplification.cpp:1587–1594`). Completion then requires simple boundaries for all cells.
- **Prediction (recorded by CB-212; not a gate condition):** the audited input cell has `disk=1` and `cutCellDisk=1` or `sameCellTwinHalfedges>0`. A different class falsifies BB3, not the gate.
- Numeric node IDs are not comparable across stages; simplification compacts nodes (`:1205–1218`). CB-212 therefore takes a census of each complex separately and maps nothing between them.

**BB4 — CB-211R and CB-212, exact, test-only, independently compilable.** Both touch `tests/SurfaceCellTracingDisplayTests.cpp` and print only, after the unchanged `SphereCompletionFailure` line. They add no assertion and no product field. Replay is exact (`0089c18e…` → `ae573fe4…` → `6149b26d…`). The syntax-only check gives 0 errors and 27 warnings for the preimage and both postimages, the same set, all in headers. This is not compile evidence. See the [manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md).
- **CB-211R** (route and plan): phase-front outcome and disposition, the three declined flags, seed and trace counts; plan arc kinds; for each of the 14 regions, boundary arcs, distinct walk nodes, repeated arcs, arc kinds, source faces, disc certificate and boundary singularities. All read from retained snapshots (`productSnapshots.globalTopologyPlan` is stored unconditionally, `:13005`).
- **CB-212** (fallback input): a census of the arrangement and simplified complexes (`disk`, `cutCellDisk`, bridge, multi-cycle, odd, repeated-node, same-cell-twin), the healing counters, the audit, and the audited input cell with its bridge halfedges' healing attributes.
  - The retained `simplifiedComplex` is exactly the parity input. In retain mode both it and `completionComplex` copy `simplifiedComplexForHash` (`:13934–13939`, `:14355–14358`), and completion does not modify it before the first pass (`PatchDescriptor.cpp:3339–3548`, `:2510–2525`). A preparation rejection then finalizes on that pass (`:3657–3659`).

**BB5 — Carried.**
- B2: BunnyRandom bounded stack and cost observation. Its exact contract is frozen after TB-REV-189, on immutable TB161 and CB-210 packages.
- B1 repair is held until a DEFN decides the role of the fallback.
- CB-207C/D, close_sheets at 0.02, J6/E5/CB-190 and CP3/497/D0/H4 are unchanged. Stable accounting is 67/17/50, debt 1, deferred 81.

## Turn sequence

1. `M6-CP3-CB-211R-P13-SPHERE-ROUTE-PLAN-WITNESS`: exact diff, compile only.
2. `M6-CP3-CB-212-P13-SPHERE-COMPLETION-INPUT-CENSUS`: exact diff on the CB-211R source, compile only.
3. `M6-CP3-TB-EXEC-189`: full 1006-row gate on the CB-212 package, STOP-on-RED. Only row858 gains lines; no V5.
4. `M6-CP3-TB-REV-189`: adjudicate the route.
   - If `NotApplicable`, freeze an exact receipt of the per-region A4 decline reasons (a non-semantic product diagnostic), then a DEFN on A4 ownership of closed-surface disc regions with boundary singularities, and on whether DESIGN §5.2 permits the whole-surface fallback once a certified plan exists.
   - Then the B2 observation.
5. Held: B1 repair, parameter deletion, V3b, R1, O48.

## Lessons

- Before investigating a stage failure, establish which route reached that stage. A fallback's failure is not the architecture's blocker.
- A first-failure audit over a whole-complex rebuild names the lowest-indexed bad cell, not the cause; take a census of all cells (RA-210).

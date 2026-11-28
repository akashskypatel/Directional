# TB-REV-185 adversarial continuation (2026-11-25 UTC)

Continues `M6-CP3-TB-REV-185` after the [independent review](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md). Runtime-free: source reading plus Haiku read-only work (pipeline stage order, sphere-premise test census, row979-versus-pipeline argument comparison, syntax-only check of CB-206 in a throwaway `CLAUDE_` worktree, since removed). Product and test bytes unchanged.

## Verdict

- **Upheld:** TB185V 1006/1006 preactivation acceptance; CB-206 diff bytes (`e1be85e0…9cdb`, both preimages equal HEAD, `git apply --check` passes); row648/978/979 edits and the row1006 eleven-line transcript as predictions.
- **Rejected as sequenced:** CB-206 → TB-EXEC-186 (full gate) before QF1. Activation moves the sphere past its current cut failure into quotient production — the stage where TB185T stalled — in at least five gated rows. The frozen full gate has no per-case timeout, so a stall repeats the TB185 → 185R/S/T cycle.
- **Realigned:** QF1 A/B (exact, frozen, preimage still HEAD) and their own behaviour-preserving gate first; then CB-206; then a bounded termination diagnostic of the sphere rows before any activation full gate.

## Findings

**X1 — Activation puts QF1 on the activation critical path (contradicts TB-REV-185's "QF1 not an activation prerequisite" and my own TB-REV-185T W2 framing).**
- `RemeshPipeline.cpp:12936–12954`: a `SurfaceCutGraph::make` failure returns `fail_surface_cells` immediately. Plan (`:12958`) and `build_authoritative_phase_front_mesh_with_hard_features` → `SurfaceQuotientProducer::produce` → `quotient_forest_path` (`:13316`) run only after the cut succeeds.
- Today the sphere stops at `CutSearchExhaustedBeforeCellularity`, so the sphere has **never** run quotient production in any gate. CB-206's own row648 prediction says the activated cut and plan succeed (V18/E30/F14), so the sphere will reach `:13316`.
- Size: sphere_prescribed 98 V / 192 F; close_sheets 32 V / 36 F, which stayed in `quotient_forest_path` past 575 s at production defaults (lengthRatio 0.02, `RemeshPipeline.h:202`).
- Gated sphere-pipeline rows that will newly run quotient production: 648 (pipeline-products, 0.2), 843/844 (`produced_network()`, defaults; sphere is first and stays eligible), 858 (`run_fixture`, defaults), 1006 (pipeline-products 0.2 and polyline-defaults 0.02). Termination is unmeasured; QF1 sufficiency is unmeasured (TB-REV-185T adv. W4).

**X2 — Row 858 is a sphere-premise gated row missing from the V10 classification.**
- `SurfaceCellTracingDisplayTests.cpp:194`: `ASSERT_NE("None", sphereDiagnostics.terminalFailureCode)` — "whichever stage stops sphere_prescribed". It survives a later-stage stop, but goes RED if the activated sphere pipeline fully succeeds, which is the intended product direction.
- TB-REV-185 lists 858 only as "remains accepted, no activated stop-location prediction". Its outcome is the sphere's terminal stage under activation: unknown. It must be measured before the full gate, not discovered as a STOP in it.
- Also not classified: row848 (`produced_regions()`, sphere third — neutral while torus/genus_two are accepted); non-gated `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` (failure branch today, success branch asserts quad degree 4 and validation acceptance); deferred sphere-success rows (`PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath`, `CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures`, `Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable`) stay deferred, outcomes reported only.

**X3 — Row648 prediction is grounded, but narrower than the row it gates.**
- Pipeline cut/plan calls (`:12936`, `:12958`) take the same mesh/regions/atlas/network arguments as row979's direct calls (`tests:~18090`, `~18153`); nothing filters between network and cut. So V18/E30/F14/χ2/residual 0 and `plan->cut_graph_digest() == cutGraph->semantic_digest()` are a sound prediction (API: `GlobalTopologyPlan.h:761`, `SurfaceCutGraph.h:301–302,415`).
- But `build_cp4c_pipeline_products_fixture` runs the whole remesh, so row648 also gates termination and every post-plan stage on the sphere. Not a defect in the diff; it is why X1 precedes the full gate.

**X4 — CB-206 syntax (TB-REV-185 claimed none).** Throwaway worktree of HEAD `4708e3b61`: apply clean, both postimages match (`ad3c5ea3…0de1`, `073d5254…17da`). llvm clang++ `-fsyntax-only -Wall -Wextra -include iterator`: SurfaceCellTracing.cpp 0 errors / 43 warnings at HEAD and patched; FieldAlignedCurveNetworkTests.cpp 0 / 45 both; diagnostic sets identical, none in the edited ranges. Not compile evidence.

**X5 — Carried.** U1–U4, W1–W6, S2 row393 whitelist, S3/V11 row669, V5 BunnyRandom, R1–R6, J6/E5/CB-190, CP3/497/D0/H4 held. QF1 non-stable. No new stable event.

## Turn sequence (supersedes TB-REV-185 recommendation and handoff step 4A/4B order)

1. `M6-CP3-CB-207A-QF1-QUOTIENT-FOREST-ADJACENCY-ONCE-PER-OWNER` — exact, compile only.
2. `M6-CP3-CB-207B-QF1-VERIFIER-FOREST-EDGES-BY-CLASS` — exact, compile only.
3. `M6-CP3-TB-EXEC-187Q` — full 1006 gate; every row N1–N3-equal to TB185V (behaviour preservation); record row1006 elapsed. Any material difference is STOP.
4. `M6-CP3-TB-REV-187Q` — accept/reject QF1 A/B as behaviour-preserving.
5. `M6-CP3-CB-206-P13-SLIDE-ENTRY-ACTIVATION` — exact as frozen (preimages untouched by 207A/B), compile only.
6. `M6-CP3-TB-EXEC-186T` — bounded diagnostic, no gate credit: rows 648, 843, 844, 858, 979, 1006 each once under a per-row observation cap (TB185T harness contract); record organic exit or bounded cutoff, elapsed, sphere terminal stage/code/locus, full logs; stack samples on cutoff.
7. `M6-CP3-TB-REV-186T` — classify; freeze exact amendments (e.g. row858 premise, CB-207C size receipt) as separate CBs, or authorize the full gate unchanged.
8. `M6-CP3-TB-EXEC-186` (full gate + V5, STOP-on-RED vs TB185V and CB-206 receipts) → `M6-CP3-TB-REV-186`.
9. Then CB-207C if still needed, parameter deletion, V3b, R1, O48; CB-190 off path.

## Lessons

- Before freezing a gate for a change that turns a failure into a success, find every stage the success newly unlocks and check it against known cost and termination defects.
- A row whose premise is "fixture X still fails somewhere" is a reach row of any repair of X; classify it before the gate.

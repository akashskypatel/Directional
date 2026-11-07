# RA-157 — TB40-REV audit: 250 discharge confirmed; CB39 spec re-bound (2026-10-25)

**Turn:** `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY-REV-AUDIT`. **Verdict:** TB40-REV is **accepted**. Selector250's focused candidate discharge stands, with no census, selector497 or CP3 promotion. The CB39 handoff it issued is **too vague to review against** and is replaced by RA-157.3. Static review only.

## RA-157.1 Independent verification

- TB40 result `12616556389`: ZIP `84d63107…e7a320`, **29/29** `SHA256SUMS`, 13/13 ledger rows, `unexpected_pass=1` on 250 only, postflight true. `raw/1.log` holds one test, `[ OK ]`.
- Between `c9d7c80f6` and `41f39ba92`, the only change under `src`, `include`, `tests`, `cmake`, `benchmarks` and `tools` is `tests/SurfaceCellsPhase10Tests.cpp` +50/−0. The PASS is therefore attributable to the RA-156.3 rail authority.

## RA-157.2 Findings

- **K1 — the CB39 handoff dropped the RA-155.3 A oracle.**
  - "Independent non-vacuous source support" and "preserve … original" do not say which A4 assertions go, what baseline proves the cause, or which error fields are asserted.
  - Code facts that bind the spec:
    - A3 keys transitions by `sourceVertex0`/`sourceVertex1` (`FieldTransportAtlas.cpp:1966–1975`). A `sourceEdge=-1` tamper is therefore found and reaches `:2020`, which returns `NonReciprocalAdjacency` with `error.sourceEdge = key`.
    - That `if` has five disjuncts sharing one code. The face disjuncts are false only because faces are untouched, so an **untampered-A3 success baseline is required** to attribute the failure to the `sourceEdge` disjunct.
    - A4 reads the atlas first (`authoritative_edge_transition_lookup`, `SurfaceCellTracing.cpp:12565`). TB38 confirms 204 is `Produced`/`None` (`raw` `:1634/1636`). The existing A4 negative blocks in 191 and 204 are unsatisfiable under D1 and must be **removed, not weakened**.
- **K2 — new observation O4.** CB39 removes the only witness of A4 `MissingTransitionProvenance` (`SurfaceCellTracing.cpp:12656, 12698, 12707`). Whether those sites are reachable with a valid A3 is unknown, like O2. Added to the scope of the legacy-path DEFN turn: inventory them, then bind a stimulus or classify them as defensive.
- **K3 — residual weakness, not scheduled.** 250's positive assertions check only per-sheet cell existence and the periodic owner. They do not check that the disk's cells respect the closed rail. Selector 236 covers that for the disk alone.
- **K4 — documentation drift.**
  - The tracker has two TB40-REV entries for one decision.
  - TODO's "EXACT NEXT" lists four turns.
  - The handoff sequence jumps from step 1 to step 3.
  - All three are corrected here.

## RA-157.3 Bound spec — `M6-CP3-CB39-RP01-A3-SOURCE-EDGE-TAMPER-REHOME` (Code + Build, test-only, compile only)

- **Scope:** only the bodies of 204 (`SurfaceCellsPhase10Tests.cpp:1615`) and 191 (`:5053`). Test names and suites stay the same.
- **Each test:**
  1. Build A2 with `build_source_topology_regions(mesh.F, options)`, using the same options the current helper uses.
  2. `ASSERT_TRUE` that `FieldTransportAtlas::make(mesh, A2, hardFeatureEdges, untamperedField)` succeeds; this is the baseline.
  3. Apply the existing `sourceEdge = -1` tamper, unchanged.
  4. Run `make` on the tampered field and assert `!result`, `result.error().code == NonReciprocalAdjacency` and `result.error().sourceEdge == tamperedKey`.
- **Per test:**
  - **204** keeps its untampered A4 baseline: `Produced` plus non-empty route observations. Its tampered key is `fixture.forwardRoute.sourceTopology[1]`, i.e. edge (6,7). Its untampered field is `fixture.authoritativeField`, on the segment-route plane mesh.
  - **191** uses `balanced_periodic_route_field(fixture)` as the untampered field. Its tampered key is `fixture.expectedRoute.front().currentTopology`. It uses the periodic cylinder mesh with the periodic helper's options.
- **Remove:** in both tests, the A4 call on the tampered field and its rejection assertions. There must be no A4 call on tampered input.
- **Unchanged:** fixtures, helpers, other tests, production code, selectors, the harness and workflows.
- **STOP → Review if:**
  - a fixture's A2 options cannot be reproduced without editing a helper;
  - the baseline `make` fails;
  - the expected key is not interior.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of 30 lines or fewer with the exact hunks.

## RA-157.4 Sequence

1. CB39 → CB39-REV, which freezes the TB41 rows for 191 and 204.
2. `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME` (192, 247) → REV.
3. `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME` (189) → REV.
4. `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN` (251, 252, `:2936`) → REV.
5. `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` → REV.
6. `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` (190, 242, O2, O4) → REV.
7. 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 → census → RP-01 Review.

Carried: `DIAG-RETAIN`, O1, O2, O3, O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002.

**Accounting unchanged:**
- stable 66/17/49, debt 1;
- CP2 491/491 accepted;
- TB38 490/504 candidate; 250 is a focused candidate;
- selector497 frozen;
- RP-01 open.

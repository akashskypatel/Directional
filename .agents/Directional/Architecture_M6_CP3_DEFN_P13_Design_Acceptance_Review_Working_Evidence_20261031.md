# P13 design-acceptance matrix — independently verified working evidence (2026-10-31)

**Canonical turn:** `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (DEFN/Review, unfinished).
**Repository:** `akashskypatel/Directional`, branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft.
**Inspection source:** immutable source snapshot `0a3f22557b651ab0e370b7cafd25f95efaf2e2b1`; run `41212749593`, artifact `13047161542`, outer SHA-256 `26b1947a3bba9ec74b130f35fbf68dee84140f7b176a0d35492290380b327d6f`. All 6,046 snapshot file hashes verified. This is a review working record, not P13 acceptance.

## Independent TB62 review first

- Re-downloaded TB62 immutable result artifact `13046191343`; independently verified outer ZIP SHA-256 `95a1b5f87b711e4a9587210fce9ff474623f078726e4c416f47ce2f4d0c5c303` and all 1,734 internal manifest hashes.
- Rehashed frozen 863-case manifest `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341` and deferred v4 ledger `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`; checked 863 ordered (row,kind,identity,test,binary) joins to result ledger.
- Recomputed all 863 raw-process log SHA-256 receipts. Each shows an exact selected GoogleTest filter, exactly one matching RUN and OK, one passed test; recorded run=passed=1, skipped=0, exit=0. Membership set exactly equals 863 gated plus 82 distinct deferred identities (945 total), with no overlap or duplication. Kind breakdown: 854 GUARD, 9 POSITIVE.
- The `execution-boundary.json` reports postflight=true; compile/relink/configure/benchmark=false, zero RED/abnormal/missing/skipped/control-bad. This was independently matched against the ledger and logs, not inferred from a successful workflow badge.
- The result binds source to CB63 semantic commit `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`, package `13043004468`. TB62's retained report documents successful 10-target Linux compile/GMP-GMPXX linkage, 11 separate CLI assertions, and GUI link only. This review independently reverified the **test-result** archive **and CB63 immutable compiled package** (artifact `13043004468`, ZIP SHA-256 `14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`, 30/30 internal package hashes), exact source `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`, successful build exit 0, Release, CLI=ON, GUI=ON, GMP=ON, and generated link commands including both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` for authority-kernel tests, CLI, and GUI. The supplementary CLI sidecar's eleven runtime receipts were **not** independently byte-audited here; they remain supported by the TB62 report. GUI *appearance* and cross-platform parity are NOT established; macOS O16 row 283 remains carried.
- Stable accounting remains 66 events / 17 categories / 49 recurrences, debt 1; accepted CP2 491/491; selector497 not promoted; no CP3 acceptance.

## P13 six-fixture acceptance matrix

The authoritative source contract is `tests/SurfaceCellDesignAcceptanceTests.cpp`: each of six parameterized cases invokes `remesh_from_raw_cross_field` with `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and the independent product oracle. It requires produced output, requested/executed SurfaceCells identity, zero fallback/recovery, `CompletedSurfaceCells` origin, no terminal error, nonempty all-quad mesh and per-face degree 4. Neither a failed-closed output nor a legacy recovery constitutes a pass.

| Fixture | Frozen ledger/gate identity | Independently reverified TB62 result | P13 disposition |
|---|---|---|---|
| Plane | gated `offgate:364`, row 797 | PASS, exact GTest receipt | Existing positive control; not new P13 repair |
| MultiFaceSeam | gated `offgate:363`, row 796 | PASS, exact GTest receipt | Existing positive control |
| CloseSheets | gated `offgate:361`, row 795 | PASS, exact GTest receipt | Existing same-sheet control |
| Cylinder | deferred `offgate:362` | NOT EXECUTED in TB62; historical 600 s timeout | First P13 target; no current gate acceptance |
| BunnyRandom | deferred `offgate:360` | NOT EXECUTED in TB62; historical independent-oracle failure, A3 cut-domain Euler mismatch | Distinct product/topology investigation |
| Vase | deferred `offgate:365` | NOT EXECUTED in TB62; historical 600 s timeout | Distinct bounded nonrectangular/paving investigation |

Earlier RA-180.3 reports a **local** Cylinder run finishing in 179 s before and after A3 exactness changes, but explicitly distinguishes that from the 600 s CI timeout. This record has not independently re-executed Cylinder, so neither success nor reproducible current Linux performance is claimed.

## Causal review obligations / falsifiers

1. **Cylinder first, max 300 seconds in a separately authorized immutable diagnostic execution:** capture exact exit/timeout, first failure, stage reached, independent oracle, output origin, source-chart and periodic holonomy, and per-stage time/peak memory. A historical local PASS and a CI timeout do not establish the current package outcome. Any 300 s timeout is an incomplete runtime observation, not a product-green result.
2. **O6 / nonrectangular bounded disks:** source `src/geometry/SurfaceCellTracing.cpp` at the polygonal phase/chart construction branch explicitly rejects `!phaseRecord.rectangular` with `InvalidBoundedDiskFrontPairing` after constructing the chart; it states polygonal lattice clipping/pairing is not implemented. Do not treat earlier chart validity as a completed quad producer, or replace it with rectangular coercion. For Vase/Bunny, derive which produced disk(s) actually reach this branch before prescribing a product correction.
3. **Exact atlas (RA-176.3):** A3 topological face gauge, ordering and tie decisions must use exact semantics of stored doubles; confirm source-chart authority and independently varying source-row/order controls, not merely a passing build with one FMA setting.
4. **O9 (RA-178.3):** previous produced open-rail routes were single-carrier. On every actually reached P13 fixture record maximum `route.oriented_steps().size()`; any produced route >1 falsifies the prior non-reachability ruling and must witness the A4 junction-certificate path. Zero routes is NOT proof of a single-step bound.
5. **O15c (RA-181.3):** independently record maximum A4 exact continuation width in bits for each executed design fixture. The bound is 4,096 bits (`kFieldExactContinuationMagnitudeBits`). Any `BranchContinuationExactMagnitudeExceeded` or measured width >2,048 bits triggers an exact-direction/limit design decision. Prior sphere_prescribed 1,531-bit observation is not a measurement of these six fixtures.
6. **Non-vacuity:** a P13 admission requires a real direct `CompletedSurfaceCells` product and a passing independent oracle. Per-fixture probes must record stages and reasons even for timeouts; never count mere reached predicates or partial output as a valid mesh.

## Boundary and next action

`REVIEW_TURN_POLICY.md` §4.3 and `Turn_Cadence.md` §6 explicitly require Review/DEFN to remain runtime-free, while the current handoff describes this DEFN as 'probe-capable' and expects 300-second fixture executions. The latter is not an express amendment to the former. Consequently **no new Directional runtime or compile was executed in this DEFN**. The execution authority for the planned P13 probes must be reconciled under repository turn policy (e.g. a separately authorized artifact-only TB/diagnostic turn) before invoking binaries. Do not silently treat prior runtimes or static review as completed new probes.

**Current result:** TB62 platform evidence independently re-adjudicated within stated limits; P13 matrix source/ledger mapped; one source-supported O6 failure path identified. P13 producer reachability, fresh Cylinder/Vase/Bunny runtime, exact-atlas/route-width measurements, independent correction plan and mandatory Review closeout remain UNFINISHED. Keep the canonical turn active; do not invent or enter a successor and do not promote CP3.

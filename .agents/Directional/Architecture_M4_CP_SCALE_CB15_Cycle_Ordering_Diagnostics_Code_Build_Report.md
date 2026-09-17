# M4-CP-SCALE-CB15 — Cycle-Ordering Diagnostics Code + Build Report

**Turn:** `M4-CP-SCALE-CB15`
**Disposition:** **COMPLETE / DIAGNOSTICS-ONLY COMPILE+PACKAGE GREEN / NO GENERATED RUNTIME**
**Exact compile source:** `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21`
**Candidate artifact:** `10517300204`
**Accepted runtime authority entering/leaving:** package `10473134357` / source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**

## 1. Scope held

CB15 implemented only the Review-authorized decision-neutral discriminator for the existing `IncompleteCycleBasis / CycleOrderingFailed` path. No cycle-basis repair, field/transport rule change, raw-field/fixture change, selector publication, benchmark change, CMake ownership change, or generated Directional runtime occurred.

The semantic implementation is confined to the three authorized paths:

- `include/directional/authority/FieldTransportAtlas.h` — additive diagnostic enum/record and optional error field;
- `src/authority/FieldTransportAtlas.cpp` — populate diagnostics at the already-existing ordering rejection boundaries;
- `tests/FieldAlignedCurveNetworkTests.cpp` — additive receipt rendering, including the independent-atlas failure receipt needed by the frozen S5 focus.

Implementation commit `d1bd3c9634df9c59df127de93efb3af54f404711` adds the production diagnostics. Receipt-only amendment `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21` exposes those diagnostics in the existing S5 structured stdout without changing any assertion, precondition, selection identity, or expected semantic result.

A later duplicate Drive-apply attempt failed closed because all three intended source paths had already advanced from that attempt's base after the successful source application. It produced no source mutation and no generated Directional runtime; it is retained only as orchestration provenance.

## 2. Diagnostic contract implemented

`FieldCycleOrderingDiagnostics` now reports the exact zero-based `cycleRowIndex`, existing-partition `cycleKind` (`LocalVertex`, `BoundaryLoop`, `HandleGenerator`), `supportEdgeCount`, `uniqueFromFaceCount`, optional current face/source edge, and one `CycleOrderingFailureReason` from:

- `DuplicateFromFace`;
- `MissingSuccessorFromFace`;
- `SupportEdgeReused`;
- `DirectedAdjacencyFaceMismatch`;
- `OpenOrUnconsumedSupport`.

The outer production error remains `FieldAtlasBuildErrorCode::IncompleteCycleBasis` and `IncompleteCycleBasisReason::CycleOrderingFailed`. The S5 receipt can now emit `independentAtlasFailure={...cycleOrdering={row=...,kind=...,supportEdges=...,uniqueFromFaces=...,reason=...,currentFace=...,sourceEdge=...}}` when that frozen failure occurs.

## 3. Decision-neutrality static proof

Side-by-side source review preserves every pre-existing `order_cycle_steps` success/failure predicate and its ordering. The implementation only records already-computed row/support/locus state immediately before the same pre-existing `nullopt` returns. The successful ordered `FieldTransportStep` sequence, `directed_transport` result, cycle composition, lift/integrality checks and all later semantic products are unchanged.

The focused test amendment is receipt-only: `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` keeps the same filter identity, topology/field/atlas preconditions, assertions and A3 reachability requirements. No selector row changes and no selector427 exists.

Frozen bytes remain exact:

- selector426: 426 unique LF rows, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- first425 prefix: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- owner census: **30 authority-kernel / 280 producer / 75 completion / 41 validation**;
- `genus_two.obj`: `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
- `genus_two.rawfield`: `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
- `genus_two.fixturemeta.json`: `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

## 4. Compile/package evidence

Mandatory reusable compile run/job `35266024382 / 105353384257` compiled exact source `94072bb4f24bdc82a24fd0bb07b6dcf37a420a21` under Release/static/Ninja/PRE_TEST with mandatory GMP/GMPXX.

Result artifact `10517300204` (`m4-cp-scale-cb15-compile-result-35266024382`) has provider/local SHA-256 `dceab12b7fe9ee8feccf972837455b89f6fe8b4bc30b44ee4947fc2343bd2711`. Its self-excluding recursive `SHA256SUMS` verifies **28/28**. Packaged source archive `source-94072bb4f24bdc82a24fd0bb07b6dcf37a420a21.tar.gz` hashes to `14a1eccff69d402b72bf803f47b0ebf778f96d9f2da87baf46b74b1e49873ebc`. Preflight/build exits are `0/0`; all five recorded source-status snapshots are empty.

All standard targets compile/link:

`directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`.

Authoritative generated link evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`; package metadata records `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`, and out-of-tree build authority. Packaged executable modes are `0755`; producer SHA-256 is `3c5ff0af1b1b3ba78781692b9661c8c59e167acc14793feae291104fcecd269c`.

Compile log artifact `10517200410` has provider SHA-256 `7fe9e37d63d9a74eb58e40d4c40fe82ab206fe66ea6341c71b26ea07cec872b3`.

## 5. Acceptance boundary and successor

This compile-green package is a **candidate only**. CB15 grants no S5 runtime credit, does not promote package `10517300204`, does not close `M4-CP-SCALE-TB12-R1-EXEC-CAND-01`, and does not change accepted runtime authority. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**.

The exact successor is `M4-CP-SCALE-TB12-R2-EXEC` under `Architecture_M4_CP_SCALE_TB12_R2_Artifact_Only_Test_Benchmark_Plan.md`. It must consume artifact `10517300204` unchanged and execute exactly one fresh S5 producer process to capture the new ordering discriminator. Selector426 runtime and benchmarks remain withheld in that diagnostic retry. A valid focused RED then routes to mandatory Review; unexpected GREEN or changed outer error/reason is diagnostic non-neutrality evidence and grants no S5 credit.

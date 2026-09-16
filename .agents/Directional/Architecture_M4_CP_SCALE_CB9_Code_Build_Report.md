# M4-CP-SCALE-CB9 — S4 Independent Oracle + Reachability Code + Build Report

**Turn:** `M4-CP-SCALE-CB9`
**Type:** Code + Build, compile/package only
**Disposition:** **COMPLETE / COMPILE + PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Entering accepted runtime authority:** package `10425344367`, source `01b1124af094044e32d6887ff0615881333d12ce`, selector425 **425/425**
**Candidate semantic source:** `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`
**Candidate package artifact:** `10428779988`

## 1. Scope and result

CB9 establishes only the prerequisite portion of `M4-CP-SCALE-DEFN-OBS-03`. It adds one independent, test-side exact topology oracle and a production-reachable subject/control matrix. It does **not** add a production early-reject branch, alter A2a' cut selection, alter the final actual-embedded certificate, publish selector426, or claim S4 gate credit.

The semantic changed-path set is exactly one file:

- `tests/FieldAlignedCurveNetworkTests.cpp`

There is no production/header/CMake/fixture/benchmark/selector semantic change.

## 2. Read-only production seam and independent invariant

Static source tracing proves `SurfaceCutGraph::canonical_candidate` begins from the empty cut set and evaluates the actual embedded candidate topology before proposing the next cut. The retained torus fixture reaches all upstream source-authority, atlas and field-aligned-network preconditions, so that initial empty-cut state is a production-reachable candidate rather than a synthetic topology object.

The test-side oracle reuses the existing independent embedded-graph reconstruction only for incidence facts, then derives its S4 covered class without calling the product's decisive `proves_embedded_cellularity()` / `proves_disc_topology()` helpers. For an observed embedded candidate it derives:

- connected-component count `c`;
- first Betti number `b1 = E - V + c`;
- required complement-face count `F_required = chi(source) - sourceComponents + b1`;
- covered rejection `observedFaces != F_required`.

The covered class is explicitly bounded as `BettiFaceCountMismatch`; CB9 does not claim a universal incremental topology theorem.

## 3. Focused prerequisite authority

New diagnostic identity, deliberately outside selector425:

`M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral`

The identity supplies the frozen subject/control matrix:

1. **Production-reachable negative.** Empty torus cuts give `V/E/F = 18/30/18`, graph/source components `1/1`, `b1=13`, `F_required=12`; the independent oracle rejects. The separately reconstructed unchanged product certificate has graph Euler `6` versus source Euler `0` and does not prove cellularity.
2. **Positive control.** The production-accepted cut set gives `V/E/F = 72/76/4`, `b1=5`, `F_required=4`; the independent oracle does not reject and the unchanged production certificate proves cellularity. Independent topology fields are checked against the product certificate.
3. **Adversarial boundary control.** A one-accepted-edge candidate is classified by the independent invariant and cross-checked against the unchanged product Euler/cellularity result without hard-coding fixture identity or an expected direction.
4. **Enumeration control.** Reversing the accepted cut enumeration leaves the exact state identity and derived invariant unchanged.
5. **Decision-neutrality control.** A second unchanged `SurfaceCutGraph::make` invocation must reproduce the same cut set, certificate and semantic/provenance digests; the diagnostic oracle has no path into product decisions.

The focused identity has exactly one source definition and is compiled into `directional_surface_cell_producer_tests`.

## 4. Selector and accepted-authority preservation

Packaged selector425 remains byte-identical:

- rows: **425**, all nonblank and unique;
- SHA-256: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`.

No selector426 exists or is authorized by this turn. Current accepted runtime authority therefore remains TB7 Review package `10425344367` / source `01b1124af094044e32d6887ff0615881333d12ce` / selector425 **425/425** until later runtime and Review adjudication.

## 5. Authoritative compile/package evidence

Authoritative compile run/job:

- run `35051977240`;
- workload job `104654125358`;
- exact semantic source `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`;
- result/package artifact `10428779988`, provider SHA-256 `7470947abba0ca2dc1e8bccd0caba8efdaa53abeaa3b1ae5130a550a3b462bd6`;
- diagnostic-log artifact `10428819823`, provider SHA-256 `cc7c783f9aa3a777527d2e35a4c560fea458de8c31672073bb64ce00448fd4f0`;
- packaged source archive SHA-256 `cd0d0c7e084bbf86fbac4086eb076ad987f55d389b5e5c63ec95fcd4724cde55`;
- root `SHA256SUMS` SHA-256 `e3423161932039366ccf1c4728cab9a3a7115340abd587923be10be3cd7a818b`, **26/26** entries independently verified.

Compiled owner binaries are exactly:

- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`.

The reusable compile authority configured `DIRECTIONAL_ENABLE_GMP=ON`, found GMP 6.3.0, and its generated authoritative link command contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so`. `metadata/command-boundary.txt` records `exactArithmeticBackend=GMP`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `semanticContracts=compiled-not-executed`. Preflight and build exit codes are both `0`; all pre/configure/post-build/final source-status receipts are clean.

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI, fuzzer or custom input was executed in CB9.

## 6. Regression/accounting disposition

No runtime ran, no accepted-green result changed, and no product-semantic defect was observed. No stable event/category/recurrence is added. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

`M4-CP-SCALE-DEFN-OBS-03` remains **OPEN**. CB9 supplies only a compile-green prerequisite candidate; runtime and independent Review are still required before any production accelerator can be authorized.

## 7. Frozen successor

Exact successor is `M4-CP-SCALE-TB8-EXEC` under `Architecture_M4_CP_SCALE_TB8_Artifact_Only_Test_Benchmark_Plan.md`, followed by mandatory `M4-CP-SCALE-TB8-REV`.

TB8 must consume artifact `10428779988` without rebuild/repair, run the focused S4 prerequisite once, then run selector425 as 425 additional fresh exact-filter processes in exact file order, preserve immutable postflight, and execute no benchmark. Only Review may accept the prerequisite or authorize later production S4 work.

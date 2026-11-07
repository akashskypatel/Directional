# M6-CP3-CB1-ENTRY-R4 — feature-curve-to-rail source owner integrity (2026-10-14)

**Turn authority:** same canonical R4 Code + Build, PR #8 draft/open. Frozen 497 selector and historical ledger unchanged. No generated Directional executable, test, benchmark, CLI or TB497 was run.

## Source-first defect

On exact immutable prior source `bbf2902ab56c6000867e538c16300720f95b14ff`, `src/pipeline/RemeshPipeline.cpp::build_authoritative_surface_cell_rails` assigned each emitted rail `component=curve.component` and `curveId=curve.id` while the curve's constituent `AdaptiveFeatureEdge` carried its own `component` and `curve`. The function checked edge vertex order but did not compare these ownership fields. The pre-A2a `rail_interval_refs` invocation passes a null `FieldAlignedCurveNetwork`, so the downstream A2a source-component comparison (recent RA-43.4 guard) cannot validate this early producer claim. This is a producer input-integrity gap, not evidence of a default-pipeline runtime failure.

## Bounded implementation and source oracles

- Producer now checks the edge’s `component` and `curve` against the emitted curve before recording the rail interval. Existing `InvalidFeatureEdge` and exact `failedEdgeIndex` reject both mismatches. No public ABI, status enum, CMake, workflow permissions, or selector changes.
- Existing `MilestoneBClosure.ContiguousHardCurveRemainsOneOrderedRail` retains its positive and adds one-field real-map negative controls for a foreign component and a foreign curve, with exact failing edge index 1. That test belongs to optional historical target and is **not** itself covered by the eight standard compiled targets.
- The *mandatory producer target* contains `tests/SurfaceCellREPackageTests.cpp::SurfaceCellClosedProductContracts.RailBuildRejectionCarriesFailureWithoutConsumableRails`, extended with a valid source-owned positive and one-field component/curve negatives retaining the original test identity; exact failure edge index 0. This compensates for the historical-only test placement without changing the standard target or adding a selector identity.

## Exact applied source authority

1. Base `bbf2902ab56c6000867e538c16300720f95b14ff`, 2-path patch SHA-256 `b767705c1f9013f5b77bf514981fe1f5eff3f51910a3570413b9c883f7877207`. Dispatcher `69218b70c1bcbbe015c222aa9a479cc0abbaf03a`, [apply run 38545692355](https://github.com/akashskypatel/Directional/actions/runs/38545692355) success, immutable apply artifact `11883748723` SHA-256 `187fed56727b4f3d5cec2804f44d88cc419d7c58b81d39fdb45da2155b971793`, applied commit `d7c67df66bcd098331ed440c27834cbffeb34231`.
2. Follow-up base `d7c67df66bcd098331ed440c27834cbffeb34231`, one-path patch SHA-256 `bfdc9f2deff7968449c81020eb6d2fa63d3bf20cac6e7a908c32b4f304eb5ccc`; dispatcher `8d679248defbfc161a6e4759af291ac26908eb12`; [apply run 38546093028](https://github.com/akashskypatel/Directional/actions/runs/38546093028) success, artifact `11884576859` SHA-256 `ea769bd61fc9bf26bf92969c22b9f5e026a0b6c414687910278115487a8800f7`. **Final semantic commit `ef916e0c3d8257a71ebbbb00f5eee64b9363a7b9`**; exactly `src/pipeline/RemeshPipeline.cpp`, `tests/MilestoneBClosureTests.cpp`, and `tests/SurfaceCellREPackageTests.cpp` changed semantically.
3. Full-index exact-base forward/reverse application, whitespace guard and source-target reproduction passed for both patches. Both staged Google Drive files (IDs `1dKdarVSS0NaOCEgdNrgKCU2mjxLDIKfi`, `1XF1YzNY4kmn6tNxuxDhFXdQvxM8uXjVU`) were permanently deleted by owner-authorized connector after verified apply. Preserve downloadable backup patches, **never replay either**.

## Compile-only boundary and continuation

Exact pinned eight-target GMP/GMPXX compile request `da7dd5e3cac4ec723d683c6d1e04fe8af727cef9`, key `m6-cp3-r4-feature-owner-compile`, `source_sha=ef916e0c3d8257a71ebbbb00f5eee64b9363a7b9`. **Completion and immutable package remain pending as of this document’s initial publication.** Reconcile matching mailbox, actual compile job, 28/28 manifest, eight targets, GMPXX/GMP generated link, five clean source-status records, `runtimeExecution=false`, and no-runtime boundary before marking GREEN. Do not infer test PASS from compile.

Remaining R4: independent RA-43.1/RA-43.2 source-selected A4-to-A1 branch/filled-side Review; RA-43.4 residual and diagnostics, RA-47.12 liveness, 39 endpoint/34 Phase10/seven DCEL/88 CP2/six CP3, organic D1/D2/D3/D5/A6/A7 and real odd-τ multi-carrier. No successor or TB497.


## Exact-source compile verified — run 38546332857

The pending final compile is **GREEN** on exact semantic source `ef916e0c3d8257a71ebbbb00f5eee64b9363a7b9`. Durable request commit `da7dd5e3cac4ec723d683c6d1e04fe8af727cef9` published mailbox `m6-cp3-r4-feature-owner-compile`: [workflow 38546332857](https://github.com/akashskypatel/Directional/actions/runs/38546332857), compile job `115793330631` SUCCESS, mailbox job `115794376540` SUCCESS; Test + Benchmark and Drive apply skipped. Mailbox source and event commits match the pinned request.

Result artifact **`11884004619`**, independently verified outer ZIP SHA-256 **`cb73b51e7a0b5e60c00f17583b3da897b3d8b27d0e3b82d8c085745e24aa56eb`**, **28/28** self-excluding manifest hashes, all **8/8** requested compiled targets, exit `0/0`, CMake `DIRECTIONAL_ENABLE_GMP=ON`, generated link with both `libgmpxx.so` and `libgmp.so`, **five clean source-status files**, exact source archive named `source-ef916e0c3d8257a71ebbbb00f5eee64b9363a7b9.tar.gz`. Packaged source contains the `edge.component != curve.component || edge.curve != curve.id` production guard, historical and mandatory-target source oracles, and CMake registration of `SurfaceCellREPackageTests.cpp` in the standard producer target. Log artifact `11884179488`, digest `dc6e4ee31d372d2282ef89484ea7e82acd7172f9be1ebb364422f383f1f9f0c5`.

Boundary is explicit `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`; **no tests or Directional binaries were run**, so these new source oracles have no runtime PASS credit. Artifact-only Test + Benchmark requires a separately authorized turn. Same R4 and all other open gates remain; never repeat an unchanged successful compile.

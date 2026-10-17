# M6-CP3-CB1-ENTRY-R4 — Seven Phase10 source A2/A3 ingress candidate repairs (2026-10-11)

**Authority:** canonical R4 remains IN_PROGRESS; successor UNKNOWN. Code + Build only; no generated Directional binary/test/benchmark/discovery was executed. PR #8 remains draft/unmerged.

## Exact source, scope and motivation

A fresh source snapshot `38109641213` / event `e212ce6024d60b36c80e23f1ce94a38e5034cb6c`, artifact `11691577164`, provider ZIP SHA256 `2fb3a64d3a9678bc321fa94780994e9758790efda1b769dbd8963d295f036be9` was inspected locally; **6071/6071** source SHA256SUMS entries verified; `runtimeExecution=false`.

Frozen rejected R3 independent review overlay `.agents/Directional/Architecture_M6_CP3_TB1_Entry_R3_Independent_94_Review_Overlay.tsv` records the following seven frozen CP2-accepted tests as R3-RED:

| Ordinal | Frozen identity | Historical R3 first class |
|---|---|---|
| 144 | `SurfaceCellAuthorityContractCutover.MaterializerConsumesPublishedTopologyRegionsExactlyOnce` | `A4_NOT_PRODUCED_UNTYPED` |
| 145 | `SurfaceCellAuthorityContractCutover.MultiSheetCellsDeriveCompleteSheetSetFromOwningRegion` | `A4_INVALID_FINAL_CELL_STATE` |
| 152 | `SurfaceCellAuthorityContractCutover.SameExtentForeignSourceTopologyDoesNotMatchPublishedAuthority` | `A4_NOT_PRODUCED_UNTYPED` |
| 200 | `SurfaceCellPhaseFrontFieldChartAuthorityMigration.PlanarMultiFaceFrontPublishesCheckedSingleChart` | `A4_INVALID_FINAL_CELL_STATE` |
| 246 | `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology` | `A4_INVALID_FINAL_CELL_STATE` |
| 249 | `SurfaceCellsPhase10.PhaseFrontComposesBoundedAndPeriodicAuthoritativeSheets` | `A4_INVALID_FINAL_CELL_STATE` |
| 256 | `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority` | `A4_INVALID_FINAL_CELL_STATE` |

All seven retained a direct `build_surface_cell_network(mesh.V, mesh.F, crossField, targetSize, options)` call with a null independent `fieldTransportAtlas`. The one-file change migrates each existing call to the previously verified `build_phase10_with_source_atlas(mesh, crossField, targetSize, options)` helper; that helper constructs source topology from the original source mesh and labels and calls `FieldTransportAtlas::make` from that authority and original cross field before entering the unchanged A4 producer. This addresses missing ingress authority but does **not** prove that the separately reported historical A4 final-cell-state errors are fixed.

`tests/SurfaceCellsPhase10Tests.cpp` only: 14 insertions/14 deletions, seven substitutions. Patch SHA256 `ab249d40341036f9563bbb91aee2e450c44a528136d4d499fd7e1f14bc7695e3`; diff-body SHA256 `da2d126e073c31ce59ef05a44297b726e91998b854fae1306c26c434dddd5a6a`; exact base `601aefdcc3f5d6c1d5c777e609545eb25b173fac`; `git diff --check` and `git apply --cached --check` PASS. Drive-apply workflow `38109848235`, job `114382996578` SUCCESS, source commit `d268e7660648ddfaf689f2fd00a5d2e2ada6497a`; patch staged in Drive, then owner-permanently deleted after exact apply/result/log verification. Library backup: `/Directional/Evidence/Directional_M6_CP3_R4_Seven_Phase10_A3_Source_Fixture_Recovery.patch`.

## Mandatory compile-only evidence

Run `38109941607` / job `114383284022`; exact source `d268e7660648ddfaf689f2fd00a5d2e2ada6497a`; eight mandatory targets, GMP/GMPXX linked, preflight/build exits `0/0`, manifest `28/28`, clean source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11690494421` ZIP SHA256 `b81f408a7367126d50108be60cb1f467cf976a330570aaa1046f84a7989b980c`; diagnostic `11690928607` ZIP SHA256 `9f783d727ba6de013e65452725cd990d0cc9a85de0ac47cfa4bac9643e1159a6`.

The compile receipt is **not runtime semantic acceptance**. No frozen selector was run, and the seven R3-red historical identities are not marked restored. Remain within R4; no authorization to start immutable frozen 497-case Test + Benchmark.

## Continuation

Review remaining old null-atlas positive fixture sites against exact R3 overlay with independent root-cause analysis; then close genuine multi-carrier/odd-τ, 39 endpoint, 34 Phase10, seven DCEL negatives, 88 CP2 regressions and six CP3 entry gates without relaxing test identities or A3 contracts. Source-valid dual-simple-nonhard-path witness on a hard-cut two-manifold star requires separate design/review adjudication; do not fabricate a nonmanifold fixture or certify it complete.

# CB-188 — region visit reader (Code + Build)

## Situation

The exact frozen region reader change is committed to `agent/surface_cell_quad/p5-recover-bridge-healing`. All eight authorized targets compiled. No test or benchmark binary ran.

## Background

- Authority: [TB-REV-168 adversarial review](Architecture_M6_CP3_TB_REV_168_Adversarial_Review_20261123.md), Q1–Q7, and the [independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), contract R1–R4.
- Frozen diff: `Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Exact.diff`, 5171 bytes, SHA-256 `5f06c14baca2c35874ae74d48ea98809fe7eeefb57276b0be94c918005d05944`.
- Only changed source file: `src/geometry/GlobalTopologyPlan.cpp`. Its verified content SHA-256 changed from `e1e186541960dceffb596fc484386eb3a8cdbe7ca8ebd8a66a37c5a48a3db459` to `5af71bc023c494a1a5a8ddeb3bb150c347941faa14e64e1e508b0113a8650aae`. `GlobalTopologyPlan.h` was not changed.
- Source commit: [`b2e976f204fa5b2988a9cbe5a77defd106a96aad`](https://github.com/akashskypatel/Directional/commit/b2e976f204fa5b2988a9cbe5a77defd106a96aad). The [patch application run](https://github.com/akashskypatel/Directional/actions/runs/45101754928) succeeded. The workflow verified the patch base and SHA-256, then applied the exact source diff. The temporary Google Drive patch files were deleted after the successful push.
- Exact [compile run 45101939539](https://github.com/akashskypatel/Directional/actions/runs/45101939539), package `14786260085`, outer ZIP SHA-256 `d877a0ea4c05cfe93275506823652abb6b0e012dd3a5925103606e28e69625a5`. Full packaged file checksum manifest passed.
- Eight targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`.
- Compile and preflight exit codes: `0`. Build metadata: `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, and an actual linker command with both `libgmpxx.so` and `libgmp.so`. All packaged source status files were empty. `runtimeExecution=false`.

## Assessment

`build_regions` now reads the shared `ArcFaceVisit` classification for exact source-face cut counts and fragment owner sets. The existing diagnostic segment loop and the other frozen reader contracts remain unchanged. No test source, fixture, selector, manifest, or workflow definition was changed. No dynamic behavior has been verified in this Code + Build turn. The last accepted runtime gate remains TB168: 993/993 PASS, CP2 491/491, membership 1074. Stable regression totals remain 66/17/49, with one produced-witness debt item and 81 deferred identities. CP3/497/D0/H4 and production remain unpromoted.

The first source/document connector reads preceded the explicit snapshot-mode gate. The agent stopped piecemeal reads, obtained and checksum-verified the exact 5775-file source snapshot, and used that snapshot for implementation verification. The source change itself matched the frozen diff without additions.

## Recommendation

Start only `M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE` as a separate immutable Test + Benchmark turn. Use package `14786260085` from source `b2e976f204fa5b2988a9cbe5a77defd106a96aad` and the unchanged TB168 993-row manifest. Require 993/993 PASS, CP2 491/491, membership 1074, and exact N1–N3 comparison against TB168 result artifact `14781634158` for all rows other than 979, with zero allowance. On row 979, the four faces `6-8-9`, `16-20-21`, `32-33-34`, and `40-45-46` must each print `traceChordCount=4`, `expectedFragmentCount=5`, `ownerCount=5`, `ownerDeficit=0`. Preserve `SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9` and all other row-979 lines. Any other changed line must STOP for independent Review. Do not run a census or rebuild. Then perform the separate TB-REV-169 turn. CB-189 is not authorized in this turn.

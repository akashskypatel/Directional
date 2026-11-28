# TB157 — immutable full-gate execution record (GREEN, 2026-11-21 UTC)

## Turn authority
- Canonical turn: `M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 open/draft.
- Entry `STATUS` commit: `a772e4d6aad12008895b120fdadc526642869c2f`, `Started at: 2026-11-21T18:15:13Z`.
- Source-snapshot trigger: `3fb03720991b79f16371543f1b835a0bb2c0b7a1`; snapshot workflow [44934533315](https://github.com/akashskypatel/Directional/actions/runs/44934533315), artifact `14718564682`, ZIP SHA-256 `38438349589eecadebb6c11aeb44e4cfa3a523e80e9a0feac1d6b349f8903181`; 5683/5683 source checksums verified.
- Source-snapshot temporary trigger to clean after remote evidence capture: `.agents/connector-triggers/source-snapshot/m6-cp3-tb157-20261121-1016.txt`.

## Frozen package and baselines — verified locally
- Immutable CB173 semantic source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, compile artifact `14718074764`, outer ZIP SHA-256 `cad613506dbadff3179f17a8492a57062d31cf27cfff6d1378417f351ab5ad09`, 28/28 packaged checksums verified. No rebuild, relink, test-source, fixture, or selector mutation.
- Previous full-gate artifact `14715014772`, ZIP SHA-256 `0bfac9c0eaf626408d666a5bd298b681236e7f54c69bfd25340b6064aa8d1e9b`, 972 rows; downloaded and checksum-verified.
- Previous census artifact `14716036015`, ZIP SHA-256 `847b88f3e95881ed2044c6ed9cd49bce9eba1e89a567a95bb202d3fbe8bd1680`, three rows; downloaded and checksum-verified.

## Situation — scoped Test + Benchmark GREEN

The exact CB-173 artifact-only gate and production census completed successfully. This is a scoped test gate, **not** CP3 or production acceptance. No source, tests, fixtures, selector, manifest, package, or reusable workflow changed during execution. Independent TB-REV-157 remains required.

## Full-gate evidence

- Request event `c3d7a59111e7d4e2fecde5ec332ba5c72c316fd3`; [run 44934860027](https://github.com/akashskypatel/Directional/actions/runs/44934860027); result artifact `14719149475`, ZIP SHA-256 `9609b0e0eb8b51d692118859fef7f0556f7de5e69c336c1bb5033d2694194d11`. The outer digest and **1958/1958** internal SHA256SUMS are verified.
- **975/975 PASS**, 0 RED, 0 skipped, 0 duplicates, 0 control errors, membership **1056**, postflight true. CP2 accepted prefix **491/491** remains green. Frozen manifest 975 rows; rows **973–975** all individually PASS.
- Independent TB156 gate artifact `14715014772` (ZIP SHA-256 `0bfac9c0eaf626408d666a5bd298b681236e7f54c69bfd25340b6064aa8d1e9b`) verified **1952/1952** internal checksums. Rows **1–972 MATCH exactly under frozen N1–N3 with empty allowance**, zero ledger/raw normalized differences; 563 raw logs byte-equal and all baseline M3 support records retained.
- Zero occurrences in all gate logs of `RotationTraceRaysAlongSharedEdge`, `RayRunsAlongLocusEdge` or `FirstPieceNotLeavingLocusIntoFace`.
- Exact execution boundary: artifact `14718074764`, semantic source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `exit=0`, `postflight=true`.

## Production census evidence

- Request event `023d516b7ce12fb9960ee83732b1302279e8cfaf`; [run 44934894555](https://github.com/akashskypatel/Directional/actions/runs/44934894555); result artifact `14719268782`, ZIP SHA-256 `9e8f561953ba4ad552a5c30cd2430d0e23c22230e074abd3e2c4ce60b92ebd63`; verified **9/9** internal hashes and source/package identity.
- All **3/3** rows MATCH the independent TB156 census artifact `14716036015` (ZIP SHA-256 `847b88f3e95881ed2044c6ed9cd49bce9eba1e89a567a95bb202d3fbe8bd1680`) under N1–N4, including unmasked `platform-digest`. Ledger/raw normalized difference list is empty, forbidden reason list empty.
- Cylinder **PASS**; BunnyRandom and Vase **RED as expected**, at their unchanged baseline sites. This is baseline agreement, **not** direct production success. Census execution counts: planned/executed **3/3**, pass **1**, RED **2**, skipped **0**, postflight true; no compile, configure, relink, benchmark or package repair.

## Assessment — regression tracker and limitations

- No new stable regression or candidate was observed in TB157. Keep stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. Existing sphere failures remain at `CutSearchExhaustedBeforeCellularity`; row 686 stays V18/E30/F18, Euler characteristic **6** versus source **2**; the four unowned slide contacts remain. Slide carriers remain withheld from cuts under interim Amendment 14.
- The along-locus-edge helper passed its three new focused tests, but the stop switch is still **unwired**. No CP3, selector497, D0 or H4 promotion is supported.
- The verified four-file handoff, TODO, root CHANGELOG and regression-tracker documentation patch applied as commit `8bd348e72c69b2f95a3f8a7f3706e8f968beca94`; Drive staging file retired by the authorized owner connector. Tool-call accounting remains partial/unknown; no exact count is claimed.

## Recommendation — one next independent turn

Close TB157 after temporary-state cleanup and the final root STATUS beacon. The sole authorized successor, **not started here**, is `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE`. The Review must independently re-derive both run results and, if upheld, freeze the separate stop-switch-helper Code + Build as an exact patch with a reaching test (TB-REV-156 V3). No successor implementation is authorized within TB157.

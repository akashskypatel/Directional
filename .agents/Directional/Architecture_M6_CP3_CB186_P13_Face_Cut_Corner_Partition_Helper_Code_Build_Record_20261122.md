# CB-186 — exact face-cut corner partition helper (Code + Build)

## Situation

The frozen face-cut corner partition helper and five gated tests were added without connecting the helper to production. No Directional test, benchmark, discovery, or compiled binary was executed.

## Background

- Authority: [TB-REV-166 adversarial review](Architecture_M6_CP3_TB_REV_166_Adversarial_Review_20261122.md), findings L1–L8. The withdrawn prose CB-186 is not implementation authority.
- Frozen exact diff: `Architecture_M6_CP3_CB186_P13_Face_Cut_Corner_Partition_Helper_Exact.diff`, SHA-256 `a89c7a9ce54bfea2f893868550fe5250e4bf4aaa5f3db72da0951cd8a01eb4b7`, +400/−0.
- Snapshot: source `3b258437eaa958effc7e061d92d9a801da9410e2`; [run 45060989239](https://github.com/akashskypatel/Directional/actions/runs/45060989239), artifact `14768673925`; all 5,758/5,758 file hashes verified.
- Frozen postimages: `src/geometry/FaceCutCornerPartition.h` SHA-256 `cea681185d69a83001999360ea37d173b6780c2a7ed3adac3caa42e49016ce4e`; `tests/FieldAlignedCurveNetworkTests.cpp` SHA-256 `8ccfc38b237322e65962644593a81308142bee9f963ab3330784c094a98c1e24`.
- Verified patch transport: full SHA-256 `c2cc84ae51423a3572edf7658e744a5401936abe9672eb954aa127d3c66ee5bc`; diff body SHA-256 `a89c7a9ce54bfea2f893868550fe5250e4bf4aaa5f3db72da0951cd8a01eb4b7`.
- [Apply workflow run 45061307639](https://github.com/akashskypatel/Directional/actions/runs/45061307639), result artifact `14769700589`, ZIP SHA-256 `9ea44f5590a2f55f1f25efa8a7c1b5fdbf8200a40b9a4b2c735100e93d4549a0`; `job_status=success`, applied exact two-path commit `b500c425063dbc5c09f13cd08b811cacba0e3afe`, no runtime, Drive transport retired by owner.
- [Eight-target GMP/GMPXX compile run 45061915460](https://github.com/akashskypatel/Directional/actions/runs/45061915460), immutable package `14769469723`, ZIP SHA-256 `1290d5ed50df98056b5eaed34f0d81ca4d156dbcd026589db10f9d271b985ddf`, source `b500c425063dbc5c09f13cd08b811cacba0e3afe`; source manifest 28 checks PASS, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.

## Assessment

The code adds the pure, unwired `partition_face_corners` operation and five `FaceCutCornerPartition.*` tests. Tests were compiled, not run. The next Test + Benchmark turn must execute the five new tests and the accepted 984-row predecessor gate. The `build_fragment_corner_incidence` reader, other code, selectors, manifests, and production path were not changed. Latest runtime acceptance remains TB166 984/984 and CP2 491/491; stable 66/17/49, debt1, deferred81; CP3/497/D0/H4 held.

## Recommendation

Next turn only: `M6-CP3-TB-EXEC-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE`. Run immutable package `14769469723` on the exact 989-row manifest `gates/Architecture_M6_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Case_Manifest.tsv` (SHA-256 `5c0841993d9b9c5537a3b78a3f7df39e61ee82e09b1ce9b4be3f4510ff088c50`). Require 989/989 PASS, CP2 491/491, membership 1070, predecessor rows 1–984 under N1–N3 with no differences and the five new tests PASS. No census, rebuild or activation. Then independent `M6-CP3-TB-REV-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE`. Any helper-test failure returns to Review without test edits.

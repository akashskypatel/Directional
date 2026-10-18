# M6 CP3 TB13A — immutable truth-table harvest, 2026-10-18

- Turn `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE`; source `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b`; CB13A artifact `12132184878`, ZIP SHA-256 `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072`.
- Harness `.agents/Directional/tools/m6_cp3_r10_open_rail_chain_interval_truth_table_harness.sh`, SHA-256 `a42ae6e0b3de79f16388a5017ac7426b4174d8184dd3de9b99b6b9df12d4350b`; executor `c278c683de4477b803bb0a93007cdf51e45c64d7`.
- [Run 39121449664](https://github.com/akashskypatel/Directional/actions/runs/39121449664), result `12134411966`, ZIP SHA-256 `17decdbf00d4515f893fdf1131b88074799cc1ac44d7d4a45fc499843b9fad61`. SHA256SUMS 10/10; exact selection 6/6, missing 0, immutable postflight.
- #1 `OpenRailRouteChainIntervalTruthTable`: PASS.
- #2 `OpenHardRailChainProvenanceIsSourceValidated`: PASS.
- #3/#4 expected B2 endpoint-1 RED, front 61/179, first_failure byte-identical to TB13 SHA-256 `cbf8bbfec6fe754c85e78626909bbc9347e097dabba6ad5fadf0eed63541bf9f`.
- #5/#6 expected B3 endpoint-1 RED, front 17/203, first_failure byte-identical to TB13 SHA-256 `923d41c54e9b148b7a8bbb67a8f65fbef399051d986f5653ef3a905ca785e11e`.
- Falsifiers absent: #1 RED, any changed #3–#6 first_failure, `open-rail-chain-interval` in raw logs.
- No compile, relink, benchmarks, selector497 run, semantic/test/fixture changes.
- RA-88.5 upheld, U3 scoped closed; B2 U4/U5 and B3 U6 DEFN remain. No direct-production acceptance.
- No new stable regressions; totals 66/17/49, debt 1; CP2 accepted 491/491; R3 rejected 403/497; RP-01 open, RP-02 unreached, Gate C suspended.
- Next `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`, not executed in TB13A.

# CB168B — region-support diagnostic framing (Code + Build, 2026-11-19 UTC)

## Situation

**Compile PASS.** `M6-CP3-CB168B-P13-REGION-SUPPORT-DIAGNOSTIC-FRAMING` source `ddd4d158701bdcca73fe3eb5034d51dd4ff1b694`. [compile run 44454804395](https://github.com/akashskypatel/Directional/actions/runs/44454804395); immutable package `14497790061` SHA-256 `7df9fa3c092e9e761803566f7d00445f2f2e4010f358bd9362c6723f04a41d68`, compile log `14496842699`. Eight mandatory GNU Multiple Precision (`GMP`) and C++ GMP (`GMPXX`) targets compiled. `runtimeExecution=false`; no tests or product runtime were run.

## Background

[RA-265 frozen plan](Architecture_M6_CP3_CB168B_CB168C_TB144_P13_Framing_And_Struck_Position_Plan_20261119.md); [exact diff](Architecture_M6_CP3_CB168B_P13_Region_Support_Diagnostic_Framing_Exact.diff) SHA-256 `7ec11b82448a3f2c563852a796a6eb3774e5674a625d7f38bf4db6adeaedaf12`. Source precheck from CB168A `b77a81ff5250aabbf6dd58cf4e9e6c208d4a973f` to snapshot `de714c1e5a9a5ff299a3e16867565c791efac8cc` found no changes under `src/`, `include/` or `tests/`. The exact source snapshot run `44454127676` passed external and internal checksum checks; 5,599 source files, artifact `14497306633` SHA-256 `be2284e01e383b621143ab8b3bdb297cf1ed66548555f5d4cf8e9d28d0f8156d`.

The only production edit is `src/geometry/GlobalTopologyPlan.cpp`, `+28/-19`. All seven `M3_CP4AB_FRAGMENT_DIAG` writers now format the complete record and its newline first, then perform one `std::cerr` insertion. The record text, region logic, normalization, and other product source are unchanged. Local exact diff and changed hunks checked byte-identical; preimage `63d3bbc7cbd2305abef8f5f60fe48a7766b66ad7`, postimage `b3896f59bbcdee5d3f354326bb8676f9c5eff534`.

## Assessment

A full-index Git work-preservation patch was checked against the exact snapshot source. Local whitespace validation passed. This patch was preserved in the user's Directional Library and staged in `My Drive/Directional-CI`. Drive apply [run 44454568086](https://github.com/akashskypatel/Directional/actions/runs/44454568086) succeeded and pushed source commit `ddd4d158701bdcca73fe3eb5034d51dd4ff1b694`; immutable result artifact `14496793468` SHA-256 `c6ceacd5271ef3c8e0643772e51bb0ecafd82343f7b30e048048e63e7c4a31ab`. Owner-side Drive cleanup succeeded. Compile source/package/hash evidence is recorded above.

This is compile evidence only. The unchanged previous runtime authority is TB143 under RA-265: 962/962 matching prior records under N1–N7, accepted prefix 491/491, known row858 RED, stable 66/17/49, debt 1, deferred 81. CB168B does not establish runtime or product acceptance.

## Recommendation

Close `M6-CP3-CB168B-P13-REGION-SUPPORT-DIAGNOSTIC-FRAMING` after durable documentation and final status update. Next authorized turn is `M6-CP3-CB168C-P13-CARRIER-CONTACT-STRUCK-POSITION-HELPER`, exact patch `f8badfdf09864bb88b9ff4d2a870b8e0ba1b03f57b4513d5dfc0f9f7719ee204`, compile only. Then `M6-CP3-TB144-P13-FRAMING-AND-STRUCK-POSITION-FULL-GATE-EXEC` tests the combined immutable package; do not run its tests during CB168B.

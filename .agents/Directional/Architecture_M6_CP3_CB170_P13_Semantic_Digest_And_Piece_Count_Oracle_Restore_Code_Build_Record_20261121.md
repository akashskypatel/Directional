# CB-170 — semantic digest and piece-count oracle restoration (2026-11-21 UTC)

## Situation

The frozen C1 and C4 corrections were committed on the working branch and compiled. This was a Code + Build turn. No program test or benchmark was run, and no production acceptance is claimed.

## Background

- Canonical turn: `M6-CP3-CB-170-P13-SEMANTIC-DIGEST-AND-PIECE-COUNT-ORACLE-RESTORE`.
- Source snapshot base: `a4787a21848f0f6b61aa6dda1011f7c1d5b5be93` (run `44891152374`, artifact `14701788328`; 5,665/5,665 file hashes pass).
- Frozen diff: `Architecture_M6_CP3_CB170_P13_Digest_And_Piece_Count_Oracle_Restore_Exact.diff`, body SHA-256 `494a58729162fc88764d01cccc3e9b480ac1f2565f9b4c391295c21fcc1ab8a3`.
- Work-preservation/transport patch: SHA-256 `ae3832c6ce180b79bb649ffef7087a0b7e69a90fb313fcdd7ec83d6f5b05bc34`, exact intended paths `src/geometry/GlobalTopologyPlan.cpp` and `tests/FieldAlignedCurveNetworkTests.cpp`.
- Apply: [workflow 44891382419](https://github.com/akashskypatel/Directional/actions/runs/44891382419); exact semantic source `9e4bd863a3e825371c6d4ce551dd7badd196ad4d`, apply artifact `14701763774`, apply ZIP SHA-256 `e200e200c4272eb44c440b15a5740cb3e609b04b12135deeb793339c0d86cb3e` and `runtimeExecution=false`. Transient Drive patch deleted only after successful push.
- Compile: [workflow 44891525358](https://github.com/akashskypatel/Directional/actions/runs/44891525358), artifact `14701819126`, ZIP SHA-256 `bf5b2ca85d46d4b78fa619a21f8eedda77a3ab862030848e82a78da3de0d113a`, eight specified GMP/GMPXX targets, `runtimeExecution=false`. Verification: 28/28 internal SHA-256 entries verified; source SHA exact; GMP ON and GMPXX/GMP link proof present; five source-status files empty; build/preflight exit codes zero..

## Assessment

- C1: removed `sourcePieceCounts` hashing from `candidate_semantic_digest` in `GlobalTopologyPlan.cpp`, preserving the existing exact replay comparison that binds those counts. Exact resulting file SHA-256: `a41f0d4d986f2d9aa6ffb18163c2aefae971a349026ec4a15af504ce6d7a7bf5`.
- C4: restored the row 966 independent trace-record count oracle: no edge transit implies exactly one source piece; edge transit expects one or two pieces. Counts are read from `record.edgeTransitEntry` and `record.edgeTransitExit`, not copied from the producer under test. Exact resulting test file SHA-256: `c8e32186369854791cf4c42e39e50892fdf1cb3ab1997c55eaf0ce264bd7ea02`.
- C2/C3 are **not corrected** in this turn. The exact stacked CB-171 diff is the only authorized next Code + Build work.
- No test, benchmark, fixture, selector, manifest, workflow YAML, or unrelated producer change. Previous TB154 971/971 and census 3/3 are historical results, not rerun here. CP2 accepted 491/491; stable 66/17/49, debt one, deferred 81. Sphere χ6 vs 2, four slide contacts and rows 669/698 remain unresolved. No CP3/selector497/D0/H4 promotion.
- Procedure note: several early direct repository policy/document reads preceded the snapshot-mode gate; the mistake was identified and the required exact snapshot was obtained before source analysis. This is a workflow compliance defect, not a test result.

## Recommendation

**Next independent turn:** `M6-CP3-CB-171-P13-EDGE-LOCUS-RANK-AND-ALONG-EDGE-COINCIDENCE` (C2/C3; exact stacked diff and compile only). Then the separately authorized TB-EXEC-155 must execute the immutable full gate and census. This CB-170 session does not begin CB-171 or TB-EXEC-155.

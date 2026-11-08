# TB84 — Contact predicates immutable gate and production census (2026-11-08 UTC)

**Turn:** `M6-CP3-TB84-P13-CONTACT-PREDICATES-FULL-GATE-EXEC`, separate artifact-only Test + Benchmark under RA-210.6. **COMPLETE / MATCH**, not CP3 promotion or Vase/BunnyRandom production success.

## Immutable authority and verified execution

- **Semantic source:** `553932b04fb433b560e24c59d23751f70f7f2c3e`; CB99 GMP/GMPXX eight-target compile [42425406875](https://github.com/akashskypatel/Directional/actions/runs/42425406875); immutable artifact `13595960339`, outer ZIP SHA-256 `54721cbd0c970064c614b64cf4241cbb3afb60ee7a96c482314057b7d9b20f35`; package manifest **28/28** and source archive SHA-256 `b1bff0cd58508482fa4c4145d273ebc6c8ed7d4538a162bfad250cb631de33db` verified. Archived executable modes preserved. Build `runtimeExecution=false`.
- **Executor authority:** `53c1d3d91146f86de5462635cdca17a32a15406c`; snapshot run [42427519502](https://github.com/akashskypatel/Directional/actions/runs/42427519502), artifact `13596515084`, outer ZIP `63836000d18638ec3da5ab018751201308c028d028a0553336940f368328c8f0`, source **6,221/6,221** SHA256SUMS checked; snapshot had no runtime. Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`, self-check PASS.
- **Gate manifest:** `Architecture_M6_TB84_P13_Contact_Predicates_Full_Gate_Case_Manifest.tsv`, SHA-256 `09eff7ed146ef39836706f4d87ae8e9309e35ab16787b6d1e8c3f39314a0b7ff`; **906 unique rows**, preserved TB83 903-row prefix. Deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 deferred. Census manifest `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, three rows.

## Full semantic gate — MATCH

- Dispatcher event `0ecc4314444945bf0529accdec7765de428244a8`; [run 42427677870](https://github.com/akashskypatel/Directional/actions/runs/42427677870) SUCCESS; result artifact **`13595899602`**, outer ZIP SHA-256 `8ea27927dc3e8770264ef9b87e6f0183ac2ffe2088d78949f801b8308c7553c1`.
- Verified ZIP and **1,820/1,820** SHA256SUMS records; ledger **906/906 PASS**, no red, abnormal, missing, skipped, duplicate or control error; membership **987 = 906 gated + 81 deferred**, postflight true, exit 0. No configure/compile/relink/benchmark. All first 903 identities/verdicts match TB83 and all four pinned gate `platform-digest` lines (795 CloseSheets, 796 MultiFaceSeam, 797 Plane, 864 Cylinder) match TB83 byte-for-byte.
- New GUARD **904** `SourceAuthoritativeMeshValidatorPhase22.CoplanarContactIsMeasuredInLengthUnits`, **905** `SourceAuthoritativeMeshValidatorPhase22.ConcaveQuadContactUsesTrianglesInsideTheQuad`, and **906** `PureQuadCompletionPhase18.QuadEmbeddingRejectsACornerOnTheOppositeEdgeAtThePositionTolerance`: all PASS.

## Production census — MATCH (two observed expected REDs)

- Dispatcher event `e66bd0e44d25f68fc2127dd1bc33b5cbbfec05b3`; [run 42427753547](https://github.com/akashskypatel/Directional/actions/runs/42427753547) SUCCESS; result artifact **`13597160142`**, ZIP SHA-256 `4a84f7955e90e492f380ece72e7d251c144f87ebfcb25bd76268c7dd9bf656c2`. Independently verified **9/9** internal SHA256SUMS records, three raw-log hashes, resource logs, ledger and execution boundary. **1 PASS / 2 registered RED**, zero abnormal, missing, skipped or bad controls, postflight true, exit 0, all mutation flags false.
- **Cylinder:** PASS (11.96 s wall, peak RSS 48,488 KiB), full platform digest **exactly** TB83; `validationIssues=0`.
- **BunnyRandom:** expected RED (0.95 s wall, peak RSS 23,512 KiB); `InvalidFieldTransportAtlas:field-transport-atlas/SingularityPortClassCountMismatch;sourceVertex=49`, P13-e. Full platform digest **exactly** TB83, no direct output.
- **Vase:** expected RED (251.09 s wall, peak RSS 2,080,440 KiB); `NotProductionReady:completion detail=AggregateCompletionValidationFailure`, `validationIssues=0`, 189,462 trace segments, 26,817 arrangement cells, **67,750 informational completed quads**. Full digest byte-identical to TB83 through `simplification`; completion hash becomes `946b59dbe8279a65/67750` from `5a2aff2aff729ab8/67750`; suffix changes from four strict issues to zero. This is fail-closed, **not** successful source-authoritative Vase output.
- Complete raw test logs naturally differ in elapsed time/process pointer addresses; *byte-identical* here means the prescribed platform-digest lines and registered semantic outcome, not entire raw log bytes.

## Regression classification, acceptance and successor

- All RA-210.6 registered falsifiers match. The three contact-predicate fixes remove the four prior Vase strict validator issues; the remaining aggregate quality/shape failure is **P13-n candidate** for Review, not a new stable regression. BunnyRandom P13-e persists as an existing separate candidate; no accepted gate regression or new stable event/category/recurrence is justified. **Stable 66/17/49, debt 1, accepted CP2 491/491** unchanged; selector497 and CP3 **unpromoted**.
- Next separate Review: **`M6-CP3-DEFN-P13-SIDE-SUBDIVISION-QUALITY`**, RA-210.4. Measure the A3 conformity-plan side-count / degree-2 source-edge crossings versus completion's interior-vertex topology and independently check concave-quad quality metrics. No Review or code changes are part of TB84.

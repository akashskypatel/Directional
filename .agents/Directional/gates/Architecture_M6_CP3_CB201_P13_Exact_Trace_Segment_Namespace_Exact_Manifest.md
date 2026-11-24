# CB-201 exact manifest — trace-segment helper namespace (2026-11-24 UTC)

**Review artifact only.** The proposed diff is not applied or compiled in TB-REV-180.

- Owner: `M6-CP3-CB-201-P13-EXACT-TRACE-SEGMENT-NAMESPACE` (Code + Build only).
- Authority: [TB-REV-180](../Architecture_M6_CP3_TB_REV_180_Cross_Partition_Arc_Census_Independent_Review_20261124.md), K6 of [TB-REV-178](../M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-179-folded-records--2026-11-24-utc). The seven mechanical controls are green; the rename condition is met.
- Semantic preimage: `4c2b4cf16732cddb58252d5e758ea0b24449ed2a`. Verified review snapshot `9e38e162eec9d61db0cc35cb8eab030ede3a8329` has identical product/test/build bytes.
- Exact [diff](../Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Exact.diff) SHA-256 `0da2ffe20ff5f0b4913acba5fa5dfd3e18c0e23ef1f6965d9d94098696d8d91c`, 27,844 bytes, 7 paths, +66/−66. `git apply --check` and `git diff --check` passed in an isolated scratch copy. Source lines are preserved. No compile or project runtime executed in Review.

## Scope

Move `FaceChartPoint`, `face_chart_segment_parameter`, `exact_trace_segment_end`, `canonical_boundary_barycentric`, and `exact_trace_segment_pieces` from the downstream `embedded_graph_topology_detail` namespace to `exact_trace_segment_detail`. Update the consumers, including test qualifications, without changing any function body behavior, signature type, test expectation, source line count, data contract, digest algorithm, selection or incidence policy. The A2a producer and its reference-remap helper no longer name the downstream namespace for these shared trace-segment operations. No compatibility alias in the downstream namespace. No new source file or test identity.

## Exact file preimages and postimages (SHA-256)

| Path | Before | After |
|---|---|---|
| `src/geometry/ArcFaceVisits.h` | `0838e637c620252886ec75a6c85bdcd036b623e5cd7c2f405adcec5000028a9e` | `9a53888d66b631683f70bbf4b11e42103221da543dfae85cf77f5833621d769c` |
| `src/geometry/EmbeddedGraphTopology.cpp` | `61a0fbac4ada9b7a5efbb83c725122af78479411a2a1af2d2f02c8f9ebdead30` | `5a1b576e90371c39c8c5f9a50079cdea29d8f0dbdde3885b06579a40de6715ea` |
| `src/geometry/EmbeddedGraphTopology.h` | `bb2c298f7e2353a6cc9949228db729b5bb84d5ea266413b849a5ba23b311b2a6` | `419d15e41c326080e6ed28a0e28735dbb1997746c9949688514b6aa7956cd985` |
| `src/geometry/ExactTraceSegmentPieces.h` | `6279c6d6e08a14d2b80dff799231249d2e8a9939c09fa88bf2b52eb314bac9da` | `bc0e878db7b8ea7eaff9c0b8c1cd2cd5d27cdf4e58f2e123805460b6c52f1da5` |
| `src/geometry/RetracedTraceReferences.h` | `bcab2d6292b9f1317471c0659e714b4afd7339e1def7c07d5d409f85b2356944` | `aaff2ebda27a61f195a366877b9c01f4ce20ab8122176856ec9c448c81968504` |
| `src/geometry/SurfaceCellTracing.cpp` | `642c829db50360c59ddb7b5ff2b2871a904b639cd1749a3bf11b5d74c911ada9` | `4b2e56873e3e2464621738633509a9540389516fddc1686bb4fe84d773be53fb` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `6e83fc338d7632c4540691cb12403d7b495ecd0ddea52f31d792c29c267e0b7b` | `af3204703d804c905d0e46f9edb2d483197f2eaaa3bea6128a5accd1189f156b` |

## Execution and falsifiers

1. Freeze the current source and verify all seven preimages and the diff hash. Apply only the frozen patch. Verify all postimages, no downstream qualifications of the moved operations, the unchanged test identities, and no semantic edits outside the seven paths. A preimage/postimage mismatch, remaining downstream name or unexpected diff is STOP; return to Review. Do not repair by expanding scope.
2. Compile only the eight durable-default GMP/GMPXX targets through `agent-compile-reusable.yml`, with exact source/package receipts, zero test/benchmark/discovery execution and `runtimeExecution=false`. A compile failure is STOP; do not silently broaden this frozen patch.
3. Separate artifact-only TB after the successful CB. Reuse [`Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv), SHA-256 `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`, 1,003 gated + 81 deferred. Baseline TB180 result `14951803089`, source `4c2b4cf16732cddb58252d5e758ea0b24449ed2a`, run `45457449013`, result ZIP SHA-256 `67e784747b1c8d04bf781b69b486f3310876fde101b7935f0207fd2fd36a39f8`. All 1,003 cases must PASS, every ledger field except raw-log hash must match, all normalized raw bytes must match under N1–N3 only. N1 GoogleTest elapsed time, N2 line endings, N3 counted complete fragment-record ordering; no source-line normalization or other receipt exception. No changed semantic digest, membership, diagnostic or corruption classification. Any material difference, new RED, missing/duplicate result or changed membership is STOP; independent Review decides.
4. K6 remains open until that independent Review. J6 production struck-reference witness debt, E5, row979, Branch A, CB-190 and CP3/497/D0/H4 remain held. The full-gate baseline acceptance does not establish production sphere or mesh acceptance.

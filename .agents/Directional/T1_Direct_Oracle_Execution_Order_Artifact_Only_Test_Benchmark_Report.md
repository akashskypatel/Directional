# T1 Direct-Oracle Execution Order — Artifact-Only Test + Benchmark Report

**Status:** accepted  
**Turn type:** Test + Benchmark only  
**Date:** 2026-08-09 UTC  
**Production behavior delta:** none  
**Review policy:** `never`

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8, open and unmerged

## 1. Decision

T1 direct-oracle integration is **accepted**.

The corrected immutable artifact proves the intended `RP-02 / TA-05` execution-order invariant: every direct `RemeshResult` that returns is independently inspected before the unchanged fatal `ASSERT_TRUE(result.success)` product assertion.

The independent oracle remains a separate observation. It does not convert known-red products to success and it does not replace the production contract.

M1 authority-kernel migration may now begin in a separate Code + Build turn. Production gate G4 remains active because this T1 turn is test-only and does not repair the known-red torus or G6 Bunny/Vase behavior.

## 2. Immutable authority

| Evidence | Value |
|---|---|
| Implementation | `7c169ddf8167093c16755f2160e224994e50307c` |
| Build/event commit | `92231989472e31a81fe1394ddb3918a957f4bc57` |
| Workflow run/job | `31324710550 / 93273122696` |
| Result artifact | `9041289209` |
| Result SHA-256 | `c40dd0207d842dd4b7f52ccc6a7358f049d8d359bc476b0ef9090dff061e85ad` |
| Log artifact | `9041289317` |
| Log SHA-256 | `899b952308fc378a919794191df5374113fb1f29343bb22759c4408b0a82dd13` |
| Recursive manifest | **51/51**, `0221c7e2dfce157461170e9da2add52a6ccfbdf800d1490926d00206bb9f207d` |
| Configuration | Release / static / Ninja / GoogleTest `PRE_TEST` |
| Compile closure | **117/117**, eight approved targets |
| Runtime during Code + Build | `runtimeExecution=false` |
| Artifact retention | through 2026-08-23 UTC |

The non-authoritative first workflow attempt `31324642747` is not used as compile or runtime authority.

## 3. Preflight and postflight

Preflight verified:

- both outer ZIP SHA-256 digests exactly;
- safe extraction;
- all **51/51** recursive package checksums;
- 52 regular package files including `SHA256SUMS`;
- six ELF executables and two static libraries;
- all 27 packaged fixture files;
- exact source authority metadata and `runtimeExecution=false`;
- exact one-file implementation patch;
- exact source archive and compile database;
- exact unchanged oracle/CMake blobs;
- exact 29-name oracle manifest with labels `contract-required;oracle-mutation`.

Key packaged hashes:

- one-file patch: `9bd727649d10f9d66246cb8e82c15d5beaa88cfb33189d1cc543f4c7d8fa1572`;
- source archive: `b31492fa478b1e4c2b2369198bde320027d3c12c4e964835b055afef8e084e61`;
- compile database: `1fa77cb933c96829d3c41fee73e072da6460c7eb9301e24e7865d2c902616885`;
- oracle manifest: `7bf35470385bd90d5d8bf69cdd7af675a25b599d22d1a352343fb2eeb3d3f3c0`.

A runtime locator symlink `bin/test-data -> ../test-data` was added outside the packaged regular-file set. Final postflight reverified both outer ZIPs and all **51/51** packaged regular-file hashes. No packaged regular file changed.

## 4. Static source invariant

The packaged source has exactly this ordering:

```text
result = remesh_from_raw_cross_field(...)
independentOracle = inspect_surface_cell_product(input, result)
EXPECT_TRUE(independentOracle.ok())
ASSERT_TRUE(result.success)
... unchanged product assertions ...
```

The implementation patch names only `tests/SurfaceCellDesignAcceptanceTests.cpp` and moves the pre-existing oracle block. Production source/API, fixtures, oracle implementation/mutation tests, CMake, validator, benchmark, tracing, arrangement, completion, optimizer, quotient, and pipeline behavior remain unchanged.

## 5. Independent oracle discovery and mutation adequacy

`directional_surface_cell_oracle_tests` was discovered exactly once.

- immutable manifest: **29** names;
- runtime discovery: **29** names;
- names and order: exact match;
- individual positive/mutation/metamorphic execution: **29/29 passed**.

The accepted oracle families cover schema/domain corruption, nonfinite/out-of-range output, quad degree metadata, repeated/degenerate/duplicate faces, incidence and winding, boundary cycles, topology component/Euler changes, vertex and face lineage corruption, backend/fallback/recovery/origin/terminal disposition corruption, and row/cycle/reversal canonicalization.

No production success flag or production validator result is used as the independent oracle.

## 6. Retained focused authority

The four multi-rail, seven face-chart, and seven canonical contracts all pass individually: **18/18**.

An initial orchestration attempt used the wrong suite prefix for five canonical test filters and selected zero tests. Those zero-test invocations are not authority. The exact suite names were then resolved from the packaged source and all five were executed individually; the final retained authority is **18/18 real selected tests**.

## 7. Bounded suite authority

| Executable/group | Result | Disposition |
|---|---:|---|
| Producer, literal `-*BunnyRandom*:*Vase*` | **154/163** | nine historical failures retained |
| Completion/simplification | **154/164** | ten historical failures retained |
| Validation | **71/71** | pass |
| Compiled API | **8/8** | pass |
| Aggregate | **387/406** | unchanged |

The authoritative producer execution completed all 163 selected tests in 37.81 seconds and exited 1 due to the same nine known failures: seven transition-quotient cases, strict-validator timing, and historical exact-torus `InvalidHardRailPairing`.

No historical failure was hidden, disabled, converted to expected success, or used to reject the T1 test-architecture correction.

## 8. Six direct acceptance cases

Each direct case ran in a fresh process with SurfaceCells direct production options unchanged.

| Case | Runtime result | Independent oracle evidence |
|---|---|---|
| Plane | **pass**, 1.025 s | reached; no issue |
| MultiFaceSeam | **pass**, 1.563 s | reached; no issue |
| CloseSheets | **pass**, 12.759 s | reached; no issue |
| Cylinder | **pass**, 6.711 s | reached; no issue |
| BunnyRandom | **known-red fail**, 54.580 s, `NotProductionReady:completion` | reached first; independently reports empty/nonquad/topology/origin/terminal issues before product-success failure |
| Vase | **bounded timeout**, 60.00 s | production did not return; no oracle result can exist |

### Bunny execution-order proof

The returned Bunny result first fails the nonfatal oracle assertion at source line 197 with independent observations including:

- `EmptyOutput`;
- `NonQuadOutput`;
- `ConnectedComponentMismatch`;
- `EulerCharacteristicMismatch`;
- `OutputOriginMismatch`;
- `TerminalFailureObserved:NotProductionReady:completion`.

Only after that evidence does the unchanged fatal product assertion fail at source line 199 with:

`terminal=NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

This is the exact counterexample required by the T1 correction. The known-red product remains red; the test architecture now observes it independently before the fatal product contract ends the test.

### Vase classification

Vase did not return within the bounded 60-second guard. This is runtime-safety evidence only. It is not correctness acceptance and is not proof of nontermination. Because no `RemeshResult` returned, no independent oracle invocation was possible or synthesized.

## 9. Regression-pattern disposition

Primary pattern: `RP-02 / TA-05`.

- `RP-02` direct-integration defect: **test-authority resolved** by this immutable artifact.
- `TA-05`: the returned-result execution-order requirement is **closed** for T1.
- `TA-01` remains only partially addressed: T1 supplies topology/lineage/disposition oracle foundations, while geometry/field/feature/quality authority remains staged later.
- `AR-12` test-evidence foundation is now established, but later representative/quality expansion remains governed by T2–T6.
- `RP-01`, `RP-03` through `RP-09`: no production implementation boundary changed.

No stable PR-wide production regression event or recurrence is created or resolved by this test-only correction. Historical totals remain **34 events / 14 categories / 20 recurrences**.

`PR8-R034 / G4-R007` remains **active** under production artifact `9031804178`: direct torus is still 0/3 with 241 `LocalSheetMismatch` issues after 192 completed quads, complete lineage, `4/8/4`, and `1/0/0` topology.

## 10. T1 closeout and next turn

T1 independent test-oracle/package foundation is now accepted at its defined boundary:

- immutable package authority;
- exact discovery;
- 29/29 mutation/metamorphic adequacy;
- direct green product observation;
- independent observation of a returned known-red product before fatal production assertion;
- no assertion weakening or product-status laundering.

The next turn is **M1a Authority Kernel Core — Code + Build only** under `.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Code_Build_Plan.md`. It must introduce strong semantic ID domains, checked conversions, tagged source support, exact grid-automorphism algebra, transition steps, canonical routes, and a bounded compatibility boundary with **no intended production behavior change**. No generated project binary may run in that Code + Build turn.

M1a must preserve the accepted T1 test authority and the existing behavioral production baseline; it may not repair G4-R007 incidentally by bypassing the architecture migration boundary.

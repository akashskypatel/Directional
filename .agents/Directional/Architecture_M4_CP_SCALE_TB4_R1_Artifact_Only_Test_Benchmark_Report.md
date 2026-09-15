# M4-CP-SCALE-TB4-R1 Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB4-R1-EXEC`
**Disposition:** COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED
**Mandatory successor:** `M4-CP-SCALE-TB4-REV`
**Runtime authority after EXEC:** unchanged pending Review; accepted package `10360085644` / semantic source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423** remains authority.

## 1. Immutable candidate authority

TB4-R1-EXEC restarted the full frozen gate from process 1 against only the immutable CB4 candidate:

- candidate artifact: `10378808176` (`m4-cp-scale-cb4-result-34923091581`);
- provider/result-ZIP SHA-256: `a60fbbb7127b2fb36952cc9fef8d58cce366204ffbcbdcd7ace2de69ff7e488a`;
- semantic source: `905dabe390577d63ed6a9289e3f3d53aa4144936`;
- packaged source archive SHA-256: `e604279d0754e44d7aa02c7d1418e73cd23ec5fd5599b05b0bda929da248428d`;
- package `SHA256SUMS`: **28/28** entries verified, manifest SHA-256 `b3364c9a0ce63f497a942b4ed8739403e4b4e9541ccf5b4faf13aab1a72f587f`;
- selector423: **423 LF rows**, SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`;
- first422 SHA-256: `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`;
- static owner census: **30 authority-kernel / 277 producer / 75 completion / 41 validation**.

The retry imported **zero semantic result** from orchestration-invalid predecessor `M4-CP-SCALE-TB4-EXEC`. The execution view was reconstructed from the immutable package and packaged source archive. No configure, compile, relink, generated discovery, repair, package/source/test/fixture/selector mutation, or benchmark execution occurred.

The turn-start source snapshot was run `34978777764`, artifact `10400472261`, exact control source `41ba01eb13df8789ca610ba6300c2b76eb8a6aef`, provider SHA-256 `2511c86e5981eace813d3b4ce39d30ba54e9472decd8a3d6b3c574bd1292b91f`, internal source archive SHA-256 `9d55d493db33e4b33cb3ebe8e83ea984dc53781be63b3a8427809d042370e2aa`, `runtimeExecution=false`.

## 2. Corrected execution-view preflight

Before any Directional runtime, the frozen payload materialized the package's source `benchmarks/fixtures` subtree at exactly `view/test-data/benchmarks/fixtures`. The source and execution-view fixture manifests are byte-identical and each hashes to:

`50a426d843eb2de8e7e9814d9c1ed735ed6b6766606611e2226c5120ea24cb78`.

All immutable before-census receipts were emitted using the same basename contract consumed by postflight. All **423** selector rows were written as `UNEXECUTED` before focused runtime began. This mechanically falsifies both runner defects that invalidated the predecessor attempt; it does not retroactively grant that predecessor semantic credit.

## 3. Focused S2 execution

The frozen focused identity executed exactly once in a fresh exact-filter process:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

Mechanical result: **1/1 PASS** (`exit=0`, selected `1`, passed `1`, skipped `0`).

All six required subject receipts were present:

| Subject | exact ray | oracle sign | expected owner | route | q4 winding | center lift | matching quarter-turn |
|---|---|---:|---|---:|---:|---:|---:|
| positive-strict-interior | `1/2` | +1 | `0-1-3` | Filter | -1 | 0 | 0 |
| negative-opposite-order | `2/1` | -1 | `0-2-3` | Filter | -1 | 0 | 0 |
| near-boundary-certified | `2^40/(2^40-1)` | -1 | `0-2-3` | Filter | -1 | `-1.41358e-16` | 0 |
| exact-boundary-fallback | `1/1` | 0 | `0-1-3` | ExactFallback | -1 | `-1.41358e-16` | 0 |
| tamper-base | `5/4` | -1 | `0-2-3` | Filter | -1 | `-1.41358e-16` | 0 |
| tamper-crossed | `3/4` | +1 | `0-1-3` | Filter | -1 | 0 | 0 |

Every receipt also reports wrapped q4 phase sum `-6.28319`, center-cycle effort `-6.28319`, center curvature `1.5708`, and `suppliedSingularities=3`. The small printed floating residual on three center-lift diagnostics is retained verbatim as evidence and receives no independent semantic interpretation in EXEC. The focused raw log reports exactly one selected/passed GoogleTest and no skip/failure. Review owns semantic adjudication.

Focused wall time was approximately **0.02 s** with maximum RSS **10,632 KiB**.

## 4. Selector423 execution

Focused S2 PASS authorized the cumulative gate. Every frozen selector423 identity then executed exactly once in its own fresh exact-filter owner process. Generated discovery was not used.

Mechanical result:

- selector423: **423/423 PASS**;
- RED: **0**;
- SKIP: **0**;
- timeout: **0**;
- selection mismatch: **0**;
- unexecuted: **0**;
- owner census: **30 / 277 / 75 / 41**.

The selector process ledger has **424** lines including its header and SHA-256 `005445645d14eb09d0af5d05650722e124543056eaea87d45ed7c7fdb042acb9`. The 423 per-process `/usr/bin/time` receipts sum to approximately **844.27 s** wall time; maximum single-process wall time was **83.45 s** at ordinal 143 (`SurfaceCellAuthorityContractCutover.HardRailPairingIsFaceRowOrderInvariant`), and maximum selector-process RSS was **22,708 KiB**. These are execution diagnostics only, not a new performance gate.

## 5. Exact immutable postflight

Mandatory postflight completed and independently re-verified the package manifest. Every frozen execution surface is byte/mode identical before and after runtime:

```text
package_census_equal=true
source_census_equal=true
execution_view_census_equal=true
package_manifest_verified=true
selector_rows=423
selector_sha256=4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343
first422_sha256=bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc
```

Census SHA-256 values are unchanged pre/post:

- package census: `2445ee8602cb38ce87aaa79bdecf89d70512a1bee1cecc813d9eb6ccde26ebe2`;
- source census: `8b4676a77d47ee07414558a65fc447098b4b2a153a9b80a24aadafe6bfabfe33`;
- execution-view census: `89889fd1757658acad50e3bc5350caf28f513acf8fb08f120ea12c8b3d6a0cc9`.

`final-status.txt` records `mechanical_exit=0`, `preflightPass=true`, `postflightPass=true`, `runtimeStarted=true`, `focusedResult=PASS`, `selectorCompleted=true`, and explicitly `configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `repairExecution=false`, `generatedDiscovery=false`, `mutationExecution=false`, `benchmarkExecution=false`.

## 6. Workflow and evidence authority

Artifact-only run/job `34979463245 / 104415713013` completed successfully on control event SHA `f07ec0996f89dd859e510af6c170fcf940290282`. The exact temporary workflow schema-validation job `104415656804` also completed successfully before execution.

Published artifacts:

- result artifact `10402080226`, `m4-cp-scale-tb4-r1-exec-result-34979463245`, provider SHA-256 `862a59893fdf0f1dd9572791f9c332e652a155ffc735b59e38b17be6f54bd4c8`;
- diagnostic artifact `10401626794`, `m4-cp-scale-tb4-r1-exec-log-34979463245`, provider SHA-256 `44d26728de2d5f20329b706dafbb43dd04ec93ed34d8b22184d8838d3b93dcdd`.

The result artifact's nested `Directional__M4-CP-SCALE-TB4-R1-EXEC__evidence.zip` has SHA-256 `843449af7e86efb0320677f6fd4301abe9888878fcdceac1d938d6812ca06c15`. Its self-excluding internal `SHA256SUMS` contains **865** entries, hashes to `584329e4125716b81622ed0aed42d509a109a33dcbbba3f35706d58c072b07db`, and verifies **865/865**.

The payload used by this run was frozen in CB5 at SHA-256 `a83ad830677f32aa0a882158c1e800762c65957ce5bb69645acbc511a8b37673` (driver) and `10fa3684a75968e5a14256c90f7e24fec486eb8d63553f9c6daee873ace20967` (library); the temporary caller verified both hashes before execution.

## 7. Predecessor orchestration candidates and regression intake

The retry provides the frozen falsifiers for both non-stable orchestration candidates opened by invalid TB4-EXEC:

- `M4-CP-SCALE-TB4-EXEC-CAND-01`: **CLOSED / FALSIFIER PASSED / NON-STABLE** — fixture-backed selector rows reached their intended bodies with the exact packaged fixture subtree at the consumer path; selector423 finished 423/423 PASS with no missing-test-data exception.
- `M4-CP-SCALE-TB4-EXEC-CAND-02`: **CLOSED / FALSIFIER PASSED / NON-STABLE** — one shared census-basename contract produced every preflight input consumed by postflight, and mandatory postflight completed with all three before/after censuses equal.

No new RED, skip, timeout, selection mismatch, immutable-input drift, or new regression/candidate was observed. Stable accounting therefore remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

The orchestration-invalid predecessor remains provenance only: run/job `34938070127 / 104280301940`, result artifact `10384800591` SHA-256 `3c6b5cc9ae54f8ebc0bfed9d4097003dbd0250f8cfc3053a89ad3ef95ca27065`, diagnostic artifact `10384696446` SHA-256 `79abfc66e2d7883444a60fcccc81b904e11ca378b93f2bd94abebdd8e76d810b`, nested evidence SHA-256 `ee5948335006b10e4f00d295e181489a6b9352634df26952f4c52dacf7c8e0ca`. None of its focused or selector observations are imported as semantic evidence.

## 8. Authority boundary and successor

`M4-CP-SCALE-TB4-R1-EXEC` is **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED**. EXEC does not promote candidate `10378808176`, does not close CP-SCALE, and does not change accepted runtime authority or stable accounting.

**Exact next turn: `M4-CP-SCALE-TB4-REV` — runtime-free Review.**

Review must independently reopen the primary R1 evidence, source/test authority and frozen CP-SCALE/S2 requirements; adjudicate whether candidate `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` is semantically acceptable; update `ORIENTATION.md`; perform mandatory Review consolidation; and either promote/re-plan according to evidence. No retry, compile, rebuild, package repair, source/test/fixture/selector mutation, or later CP-SCALE implementation is authorized before Review.

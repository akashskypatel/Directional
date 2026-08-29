# M3-CP4c-2-CB3-DIAG Code + Build Report

## Verdict

**COMPLETE / BUILD GREEN / RUNTIME-FREE.** `M3-CP4c-2-CB3-DIAG` implements only the observability and publication-hygiene corrections authorized by the R4 independent review under measures **AA0-AA9**. No Directional runtime, test, benchmark, selector gate, cumulative gate, or acceptance attempt ran in this turn.

The exact semantic/test source is `76d757aab0ce18df09ce2823302d2dc224965187`. The authoritative GMP compile run is `33230423139`; both the changed-owner precompile and the eight-target package compile completed successfully. The immutable full package is artifact `9708324052`, SHA-256 `48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`; compile log artifact `9708324292`, SHA-256 `d200b4210a1adc204fd2fd90df07727c73c8c35c65110d99233ea44d9bd5d0fd`. The packaged source archive hashes to `f16141613e877c78746548596449ef494fb9f4b384736526d74eaaf54a0a9a2d`.

## Source authority and preservation

The turn froze source authority `3703a398eebe9b67f6a18bbba2d441f927cbcec7` before inspection. Source snapshot run `33229983412` produced artifact `9708170284`, SHA-256 `299c73be94beb16dabd26920487638bfd9f09757158595a6085728b04b8b383b`; its recursive source archive is `d647e4b8ac3648576939a832156790b1de33fff90bfdd399fe9784758553e06d` over 5,211 files.

Before remote application, the exact three-file semantic patch was emitted as `Directional__M3-CP4c-2-CB3-DIAG__base-3703a398eebe__work-preservation.patch`, SHA-256 `6f7ade8d0fbe02093d352c6e81151625940d25caaf74073d16dd223efbd0cd40`, diff-body SHA-256 `4139c2eabefa94b8655d70fc2122a697f5951be8660b219824a840a0bf7d1f9c`. Schema-validated Drive application run `33230323825` applied those bytes and produced semantic commit `76d757aab0ce18df09ce2823302d2dc224965187`; result/log artifacts are `9708273848` / `9708274148`. The staged Drive transport was permanently deleted after the successful push.

## Authorized implementation

### AA1 — publish product snapshots at the construction boundary

`src/pipeline/RemeshPipeline.cpp` now assigns each retained diagnostic snapshot immediately after that product is successfully constructed:

- `sourceTopologyRegions` after source-topology-region construction;
- `fieldTransportAtlas` after atlas construction;
- `fieldAlignedCurveNetwork` after network construction;
- `surfaceCutGraph` after cut-graph construction;
- `globalTopologyPlan` after plan construction.

The former all-at-end snapshot block was removed. No `fail_surface_cells(...)` call, failure code, failure-stage string, product build order, or branch/return control flow changed. This is the only `src/` change in the turn.

### AA5 — one D1 witness record per witness

`tests/FieldAlignedCurveNetworkTests.cpp` now:

- counts publications by witness name;
- emits each `m3Cp4c2Y1` record only at its owning witness publication site;
- stores only witness name/status in the final assertion failure summary, so GoogleTest cannot re-emit a full Y1 record;
- publishes `m3Cp4c2PublicationCounts;torus=...;prescribed-sphere=...;two-ring=...;total=...`;
- requires each witness count to equal one.

This corrects `R4-CAND-01` without weakening the diagnostic assertion or hard-coding a product outcome.

### Required lesson

`.agents/Directional/LESSONS.md` now records the R4 review lesson: when a result independently discharges a checkpoint premise, it must be reported as a finding even if another contract violation makes the overall turn semantic red.

## AA0 selector authority

No selector file changed. Static recomputation from the exact source is unchanged:

| Authority | Lines | SHA-256 |
|---|---:|---|
| accepted first-316 | 316 | `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c` |
| accepted CP4c-0 | 346 | `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a` |
| accepted CP4c-0b | 353 | `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5` |
| accepted CP4c-1 | 355 | `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa` |
| frozen candidate | 357 | `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70` |
| frozen candidate | 358 | `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62` |

`selected_r2_branch=NONE`, `selected_gate=NONE`, and `gate_execution_authorized=false` remain unchanged.

## Compile evidence

Compile run `33230423139` is **GREEN** with `runtimeExecution=false` and `exactArithmeticBackend=GMP`.

The changed-owner job compiled `directional_surface_cell_producer_tests` first. The package job then compiled/link-checked exactly the eight standard targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

GMP/GMPXX linkage evidence names both `libgmpxx` and `libgmp`; preflight/build exit codes are `0/0`. All packaged source-status snapshots are empty, and the package's `SHA256SUMS` verifies completely. No generated binary was executed.

Artifacts:

- changed-owner result `9708313428`, SHA-256 `f35a1e33384fb963fe03574d0312be96f2f56572a5279b977fc985478e846c77`;
- changed-owner log `9708313563`, SHA-256 `2f7aaf48e7e878a8d314ee386a42de53eb9c96f1728b2d0a1908bacfe4321dc7`;
- full package `9708324052`, SHA-256 `48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`;
- full compile log `9708324292`, SHA-256 `d200b4210a1adc204fd2fd90df07727c73c8c35c65110d99233ea44d9bd5d0fd`.

## Candidate disposition after Code + Build

Compilation does not adjudicate runtime behavior.

- `M3-CP4c2-TB-X2-R4-CAND-01`: **ACTIVE / CORRECTIVE SOURCE COMPILED / RUNTIME PENDING**. R5 must prove one Y1 publication per witness and the machine-checkable count record.
- `M3-CP4c2-TB-X2-R4-CAND-02`: **LOCALIZED / CORRECTIVE SOURCE COMPILED / RUNTIME PENDING**. R5 must prove that a prescribed-sphere cut-graph failure retains the already-built source-topology/atlas/network products.
- `M3-CP4c2-TB-X2-R4-CAND-03`: remains **ACTIVE / OUT-OF-SCOPE FOR CP4c-2**; R5 must continue to report the torus downstream tracing failure without fixing it.
- `M3-CP4c2-TB-X2-R2-CAND-02`: remains **ACTIVE** until the prescribed sphere is measured in the same complex.
- `M3-CP4c2-TB-X2-CAND-04`: remains **ACTIVE / UNLOCALIZED** until D2 publishes the exact 419/437/474 failure site.

Stable regression accounting remains **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. This new immutable full package advances M3 package accounting from **61 to 62**.

## Successor

Exact next is artifact-only **`M3-CP4c-2-TB-X2-R5-EXEC`** on immutable package `9708324052`, using `Architecture_M3_CP4c2_TB_X2_R5_Artifact_Only_Test_Benchmark_Plan.md`. R5-EXEC must first re-prove accepted prefixes 316/346/353/355 before any CP4c-2-local diagnostic receives credit. It must execute no configure, compile, relink, repair, source/test/fixture/selector mutation, benchmark, or cumulative 357/358 gate.

After EXEC preserves raw evidence, the next boundary is independent **`M3-CP4c-2-TB-X2-R5-REV`**. No branch or gate may be selected before that review.

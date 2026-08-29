# M3-CP4c-2-TB-X2-R5 Artifact-Only Test + Benchmark Plan

## Scope and authority

This plan is for **`M3-CP4c-2-TB-X2-R5-EXEC`**, artifact-only runtime execution on the immutable CB3-DIAG package. It is execution-only evidence gathering; interpretation/branch selection belongs to independent `M3-CP4c-2-TB-X2-R5-REV`.

Immutable authority:

- semantic/test source: `76d757aab0ce18df09ce2823302d2dc224965187`;
- compile run: `33230423139`;
- full package artifact: `9708324052` / `sha256:48e01cea66817525766566a1145b92beb22dbb847e4211629fe4c3373d23ff7a`;
- compile log: `9708324292` / `sha256:d200b4210a1adc204fd2fd90df07727c73c8c35c65110d99233ea44d9bd5d0fd`;
- packaged source archive SHA-256: `f16141613e877c78746548596449ef494fb9f4b384736526d74eaaf54a0a9a2d`;
- exact arithmetic backend: GMP/GMPXX;
- CB boundary: `runtimeExecution=false`.

Prior R4 evidence used by AA2 only:

- R4 result artifact: `9707662462`;
- authoritative R4 run/job: `33228460953 / 99036688477`.

No benchmark is authorized by this diagnostic successor. `benchmarkExecution=false` throughout.

## Frozen selector authority

R5 must recompute these hashes from the package/source before execution and fail closed on any mismatch:

- first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 346: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- first 353: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
- accepted 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`;
- frozen 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`;
- frozen 358: `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`.

Neither 357 nor 358 is authorized for runtime in R5-EXEC. `selected_gate=NONE` remains binding.

## Execution order and stop rules

### R5-0 — immutable package preflight

Before running any Directional executable:

1. verify package artifact SHA-256 and internal `SHA256SUMS`;
2. verify `metadata/source-commit.txt` equals the semantic/test source;
3. verify package metadata states `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
4. verify GMP/GMPXX linkage and the required executable inventory;
5. capture byte-and-mode inventories for package and materialized source;
6. recompute all six selector hashes above.

Any mismatch is an orchestration/evidence stop. Do not repair the package.

### R5-1 — AA8 accepted-prefix re-proof first

Before any CP4c-2-local credit, re-run the accepted authority in order, using the package's existing frozen selector identities and one test identity per fresh process:

1. accepted first-316 — require **316/316 PASS**;
2. accepted first-346 — require the added 30 identities and cumulative **346/346 PASS**;
3. accepted first-353 — require the added 7 identities and cumulative **353/353 PASS**;
4. accepted CP4c-1 selector — require the added 2 identities and cumulative **355/355 PASS**.

Do not execute already-proven identities twice merely to produce cumulative arithmetic if the harness can preserve prefix evidence and execute only each newly added suffix once. The report must still prove each frozen prefix exactly.

**Hard stop:** any accepted-prefix regression ends R5 immediately. Preserve the first red identity, stdout/stderr, exit code, immutable postflight, and classify it for review. Under AA8, no CP4c-2 diagnostic gets credit and the review must consider reverting AA1. Do not execute D1 or D2 after an accepted-prefix regression.

### R5-2 — AA2 prior-artifact byte-identity check

Without executing a Directional binary, inspect `d1-records.txt` from prior result artifact `9707662462`:

1. isolate the two prescribed-sphere `m3Cp4c2Y1` lines;
2. require exactly two prior copies;
3. compare the complete bytes, including ordering, delimiters, and line content;
4. publish `sphereDuplicateByteIdentical=true|false` and the SHA-256 of each line.

**Hard stop:** if the two lines differ by any byte, the R4 admissibility ruling is void. Preserve evidence, set `selected_r2_branch=NONE`, keep `selected_gate=NONE`, skip D1/D2, and hand off to R5-REV.

### R5-3 — D1 exactly once

Run exactly one fresh process selecting only:

`GlobalTopologyPlan.Cp4c2IndependentNetworkOnlyCellularityOracleIsObservable`

Required publication contract:

- exactly one `m3Cp4c2Y1` record for each of `torus`, `prescribed-sphere`, and `two-ring`;
- exactly one `m3Cp4c2PublicationCounts` record;
- counts must be `torus=1`, `prescribed-sphere=1`, `two-ring=1`, `total=3`;
- no fourth full Y1 line may be introduced by the final assertion;
- each witness record must include construction status, product snapshot availability, terminal code/stage, rail/barrier authority, source/network complex counts, per-component Euler/boundary-cycle terms, and oracle self-consistency fields defined by the compiled diagnostic.

Required witness checks:

**Torus**
- preserve the frozen network-only control: `barrierV=48`, `barrierE=48`, `sourceChi=0`, `networkOnlyCellular=false`, `oracleSelfConsistent=true`;
- require retained cut graph and global topology plan when the pipeline reaches them;
- classify any residual `terminalFailureStage=tracing` as downstream A2b / `R4-CAND-03`, not as a CP4c-2 repair authorization;
- publish the per-component topology showing the expected annular decomposition if observed; do not encode four annuli as an expectation in production/test semantics.

**Prescribed sphere**
- after AA1, require already-built source-topology, atlas, and network snapshots to remain observable when failure occurs at `surface-cut-graph/CellularityNotEstablished`;
- use those actual pipeline products to compute the same independent network-only cellularity oracle as the other witnesses;
- publish all per-component Euler/boundary-cycle terms and `oracleSelfConsistent`;
- do not infer or hard-code whether the network is cellular.

**Two-ring**
- preserve synthetic/AtlasDerived authority;
- publish the same full Y1/per-component contract and require oracle self-consistency.

A D1 semantic red is valid evidence. Preserve it; do not edit or rebuild.

### R5-4 — AA4 D2 exact failure localization

D2 is authorized only after R5-1, R5-2, and a structurally admissible D1 publication set complete.

Run exactly one fresh process selecting only:

`GlobalTopologyPlan.Cp4c2CutGraphFailureLocalizationIsObservable`

For the prescribed sphere's `CellularityNotEstablished`, publish the exact owning return locus among the frozen `SurfaceCutGraph` sites **419 / 437 / 474** and the complete term-by-term certificate used at that site. The output must distinguish the three mechanisms rather than restating the shared enum alone.

If the sphere no longer fails with `CellularityNotEstablished`, publish the observed path and do not synthesize a locus.

### R5-5 — immutable postflight

After the last authorized runtime:

- re-run package and materialized-source byte/mode inventories;
- require exact equality with preflight;
- record `configureOccurred=false`, `compileOccurred=false`, `relinkOccurred=false`, `repairOccurred=false`, `generatedDiscoveryOccurred=false`, `mutationOccurred=false`, `benchmarkExecution=false`;
- preserve raw per-process stdout/stderr and exit codes.

## EXEC output requirements

`M3-CP4c-2-TB-X2-R5-EXEC` must produce raw evidence only. It must not choose Y5, select 357/358, run the cumulative gate, close CP4c-2, or author a corrective implementation plan.

The EXEC closeout must state separately any premise-discharging finding already evidenced — especially whether the torus still derives a GlobalTopologyPlan — even if another witness makes the overall diagnostic semantic red.

All observed regressions or diagnostic defects must be entered/updated in `Regression_Root_Cause_Tracker.md` as candidate/non-stable unless evidence independently satisfies the stable-count criteria. Accepted stable totals begin at **42 / 14 / 28**, debt **5**, M3 packages **62**.

## Review boundary

After EXEC evidence is durably preserved, **stop implementation/runtime progression**. Exact next is independent **`M3-CP4c-2-TB-X2-R5-REV`**. The reviewer alone may:

- adjudicate AA2 and candidate closure;
- classify the prescribed-sphere network-only result;
- use D2 to localize `CAND-04`;
- select or reject Y5 Branch A/B;
- authorize one of frozen 357/358, or neither;
- author any corrective Code + Build plan.

# M6-CP3-CB1-ENTRY-R3 — compiled first-failure evidence and independent review gate

**Prepared:** 2026-10-09 18:53 UTC. **Role:** same unfinished R3 Code + Build turn; source/static audit and compile verification only. This document is **not** a Review verdict, a Test + Benchmark result, proof of production witness generation, or authorization of another turn.

## 1. Exact source and compile evidence

- Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 (draft/open); **latest semantic source** `89b17c90a3941f080d47f47d10fea9f23cf2b818` (the older `2ae6f5d1...` source and compile `37861343725` are superseded).
- Mandatory GMP/GMPXX compile-only workflow **37970925842**, compile job **113957160157**: SUCCESS. Published immutable result artifact **11634853973**, ZIP SHA-256 **`101f2a1f5f135721eede3bffaf24d73ad0d90e090b2ed3a4a9f08b755e01c9d3`**. Nested `SHA256SUMS`: **28/28 correct**, validated with leading `./` manifest path normalization. Source tar `source/source-89b17c90a3941f080d47f47d10fea9f23cf2b818.tar.gz`, SHA-256 `d54fcfd7a4456ddec3151f030c9547fd205976b882e82c6fdfb49c0af40c0b50`.
- `metadata/source-commit.txt` matches, preflight/build exit codes are 0, all 8 required targets are listed and present; generated link evidence shows `libgmpxx.so` and `libgmp.so`; command boundary explicitly has `exactArithmeticBackend=GMP` and **`runtimeExecution=false`**; five source-status files are empty. No compiled Directional program, test, benchmark or test discovery was executed.
- Source/fixture/selector change boundary: the most recent semantic delta is fail-only `SCOPED_TRACE` in two RE terminal-ordering test sites. Previous compiled instrumentation covers direct A4 and dependent Phase10 fixture/assertion sites. No frozen selector changes.

## 2. Historical R2 evidence — categorization, not current results

The exact frozen historical `Architecture_M6_CP3_TB1_Entry_R2_Red_Classification.tsv` has **53 distinct R2 RED identities** from the old 497-case run. Source classification counts:

| Historical R2 class | R2 RED | Diagnostic context in latest source |
|---|---:|---|
| A4 certificate false rejection | 25 | 17 constant-field shared-rectangle fixture throws, 2 nonconstant D2 fixture throws, and 6 Phase10 entry assertions; producer first-predicate reporting available in `tests/SurfaceCellTransitionQuotientTests.cpp:371–405` and `tests/SurfaceCellsPhase10Tests.cpp` |
| Phase10 producer/provenance reachability | 12 | `SurfaceCellsPhase10Tests.cpp` has fail-context and `surfaceCellFirstInvalidProducerReason` reporting at dependent assertions; do not infer a single root cause |
| RE-package terminal code/stage mismatch | 2 | `SurfaceCellREPackageTests.cpp` now includes `SCOPED_TRACE` of original error code/stage/detail and first producer stage/reason at source lines ~225 and ~379 |
| Torus downstream A5/A6 unavailable | 6 | Organic producer/consumer result not established |
| Periodic odd-A3 organic witness | 5 | Genuine tracer-produced nonzero Z4 witness not established |
| D3/D7 seam-collinear organic witness | 2 | Genuine seam-collinear OrdinaryFront with A6/A7 not established |
| D5 ordinary route organic witness | 1 | Genuine ordinary route and hard-feature barrier not established |

The first three groups total **39 R2 first-observable loci** (25+12+2); they are not automatically 39 distinct root causes, and test-source reporters only become evidence of the actual cause when an independently authorized artifact-only runtime run prints them. The other **14 historical R2 REDs** are organic-witness/downstream categories requiring real process results. Historical **47 CP2 previously accepted→R2 RED** identities remain unrecovered until the future test gate.

## 3. Static reporter check against the latest source

- `require_produced()` in `SurfaceCellTransitionQuotientTests.cpp` appends `hardRailRouteDiagnostic` when a rejected phase-front product has a first invalid predicate. This preserves failure; it does not choose a replacement witness.
- `retained_pipeline_first_failure()` reports the first producer stage and reason if a preflight fails before the phase-front product is available.
- `hard_rail_first_failure_detail()` in `SurfaceCellsPhase10Tests.cpp` reports the producer's first invalid route detail only after rejection; additional assertions reference pipeline `surfaceCellFirstInvalidProducerReason`. Do not conflate the six Phase10 direct A4 sites with the 12 Phase10 dependent historical identities.
- Two RE terminal code/stage sites, historical selector ordinals **176** (`SurfaceCellFieldAlignedNetworkAuthority.ProductionConsumesTypedSkeletonWithoutRawSingularityProjection`) and **201** (`SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement`), now contain fail-context `SCOPED_TRACE` of original failure and first invalid producer context. Both original injected-stage assertions remain.
- All these source paths are compiled into the package, **not executed**. A compiler success does not prove the failure path will be reached or that the test fixture is nonvacuous.

## 4. Frozen test selection and independent decisions

The frozen **497 = 30 focused + 12 CP2 focused + 449 selector + 6 CP3** exact processes must not be extended, rewritten, replaced, or silently counted as more. Source-defined extra tests outside the frozen selection are documented in `Architecture_M6_CP3_R3_Frozen_497_Supplemental_Test_Coverage_Audit.md` (factory face-incidence case plus three additional CP3 names). Compilation is not execution; a separate exact-one/no-skip supplemental artifact-only process set requires independent authorization.

An independent Review must explicitly decide **A**: whether A4's producer-attested nonrail `FieldTransportAtlas` transport is a trusted source for the public `SurfacePhaseFrontProduct::make`, or whether the factory contract requires independent A3 input; **B**: how to close compile-only R3 while preserving genuine produced-witness and regression runtime gates for the separate immutable Test + Benchmark turn; and **C**: whether four nonselected test identities require separately counted artifact-only execution. The review request already exists; this record does not answer it. RA-39 terminal-carrier endpoint topology is previously accepted and is not reopened.

## 5. Exact next actions — same turn, no unauthorized successor

1. Obtain and record a formal independent decision on A/B/C before schema/selector/execution changes. Do not manufacture an A3 source oracle, relax tests, or run binary discovery under Code + Build.
2. If the review permits compile-only R3 closure, preserve this precise immutable source/package and its 39 fail-context reporters as the candidate for separate artifact-only Test + Benchmark execution. The future frozen 497 must be uninterrupted to organic result, and each selected identity must execute exactly once with zero skips; supplemental tests, if authorized, are separately accounted.
3. Future actual results must investigate all R2 39 first-observable failures *individually* and track all 47 accepted-green losses before any promotion. A genuine empty A4 two-carrier search stops for independent producer review rather than an invented positive.

**Status determination:** R3 is still unfinished. No new successor is authorized and no runtime acceptance claim is supported.

# M3-CP4c-3-CB28 — Certified Ownership Conflict Census Code + Build Report

**Turn:** `M3-CP4c-3-CB28`
**Verdict:** **COMPLETE / COMPILE GREEN / RUNTIME NOT EXECUTED / SEMANTICALLY UNACCEPTED**
**Date:** 2026-09-04

## Scope and authority

CB28 executed only the runtime-free Code + Build scope frozen by `M3-CP4c-3-TB24-REV` CH6–CH9. It did not
correct the source-face ownership derivation and did not execute Directional tests, benchmarks, generated binaries,
`ctest`, CLI commands, fuzzers, help/version commands, or custom runtime inputs.

- frozen implementation base: `2ec2a978001be478d99e0730005fae5d379e974b`;
- primary CB28 semantic commit: `8a8b9af7b3d3d51bba8b710f841a867c77840440`;
- compile-fix semantic commit / final CB28 product source: `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`;
- selector 403: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_403.txt`, 403 identities,
  LF SHA-256 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`;
- selector 401 remains the exact 401-line prefix, SHA-256
  `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`;
- selector 397 remains byte-frozen, SHA-256
  `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`.

## CH6–CH9 implementation

**CH6 — publication survives ownership failure.** `SurfaceCutGraphCellularityCertificate` now separates embedded
cellularity from complete source-face ownership through `proves_embedded_cellularity()`. Source-face ownership rows
publish `Established`, `Unavailable`, or `Conflicting` status. `proves_cellularity()` remains the stronger public
predicate and still requires a complete, established ownership map; it was not weakened.

**CH7 — the consumer can reach its census.** Candidate publication can survive ownership-certificate failure, and
`GlobalTopologyPlan` checks the published ownership rows rather than losing the whole `cutGraph` before its own
component/owner consistency evidence can be formed. This is compiled instrumentation only; CB28 makes no runtime
claim that ordinals 366, 384, 389, or 390 have changed state.

**CH8 — certified-owner conflict census.** The certificate can publish a conflict census for source edges whose two
established incident-face owners differ. Each row names the source edge, both source faces, both certified owners,
and the independently derived barrier classification (`None`, `TraceOutgoingCarrier`, `TraceIncomingCarrier`,
`MandatoryEdge`, or `CutEdge`). The census is published on the ownership-failure path so TB25 can distinguish a
missing/omitted barrier classification from non-barrier owner disagreement or an ownership-incompleteness mechanism.

**CH9 — selector 403.** Selector 403 retains selector 401 as an exact prefix and appends two gating identities:

1. `SurfaceCutGraph.CertifiedOwnerConflictCensusPublishesOnOwnershipFailure`
2. `SurfaceCutGraph.CertifiedOwnerConflictCensusNamesANonBarrierEdgeSeparatingCertifiedFaces`

Ordinal 385's diagnostic assertions were replaced in place as authorized; ordinal 398 remains gating. No accepted
identity 1–365 was changed.

## Compile correction

The first semantic implementation default-constructed `SurfaceCutGraphCertifiedOwnerConflict`, but its topology-key
members have no default constructors. Compile run `33897882778` exposed that single C++ error. The bounded follow-up
changed only `src/geometry/CertifiedOwnerConflictCensus.h` to aggregate-construct the row from the already-computed
edge/faces/owners/barrier class. The correction was applied by Drive workflow run `33907693680` and produced final
semantic source `3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`. No runtime occurred in the failed or corrective attempts.

The earlier compile-caller run `33897746403` created zero jobs because of the temporary caller permission ceiling;
it is orchestration provenance only and carries no semantic credit.

## Final compile evidence

Final compile-only run **`33907875533`**, workload job **`101137084443`**, completed **SUCCESS** against exact source
`3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`.

- configuration: Release/static `PRE_TEST`;
- GMP/GMPXX: enabled and linked;
- preflight `directional_core`: exit 0;
- exact approved targets: `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`;
- build exit: 0; compile status: 0; source remained clean;
- immutable compile result/package artifact: **`9950303110`**, SHA-256
  **`84c9cd0bdf5d8bef2288e1ca57d52bcec8d1503f368d82101ae10cfa14c49189`**;
- persistent compile log artifact: **`9950303474`**, SHA-256
  **`c0401abdcab22df514a05b09084c27fb408619106652b0e4d7a02ceaaa33e204`**;
- artifact-manifest self-verification: PASS;
- `runtimeExecution=false`.

The compile log records that no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI,
fuzzer, help/version command, or custom input was executed.

## Acceptance and accounting

CB28 is compile-green but **not semantic acceptance evidence**. TB24 remains the latest semantic runtime authority:
**389 PASS / 12 RED**, accepted **365/365**, RED ordinals
`366,367,368,369,370,374,384,385,389,390,393,398`. Stable regression accounting therefore remains
**44 events / 14 categories / 30 recurrences** and produced-witness debt remains **5**. CB28 is semantic M3 package
**90**. CP4c-3 remains **OPEN**.

## Exact successor

**`M3-CP4c-3-TB25-EXEC`** — execute selector 403 exactly once against immutable CB28 compile artifact `9950303110`
under `Architecture_M3_CP4c3_TB25_Artifact_Only_Test_Benchmark_Plan.md`. TB25-EXEC records evidence only; it must
not rebuild, relink, repair, mutate source/tests/selectors, interpret the result as closure, or perform independent
review. CB28 itself does **not** execute TB25.

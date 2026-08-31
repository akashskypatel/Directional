# M3 CP4c-3 TB3-R1 — Artifact-Only Test + Benchmark Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB3-R1`
Status: **FROZEN RETRY PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`
- Immutable mode-preserving package **72**: artifact `9765247195`, `m3-cp4c3-package72-33411346157`
- Actions outer SHA-256: `41ebe4dec4a3eb5c8194900a3f27a0377c3271212edd10fb952c48f55a6a2e6d`
- `package72.tar.gz` SHA-256: `20630897aa432572d0929022abef3861fff80c2b5792c223071990dd2e3c6a73`
- Packaged source archive SHA-256: `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`
- Frozen selector 373: `Architecture_M3_CP4c3_Required_Green_Selector_373.txt`, SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Fixture authority: `test-data/benchmarks/fixtures`, exactly 27 immutable files inside the tarball.

Frozen executable authority after clean tar extraction:

| binary | SHA-256 | required mode |
|---|---|---:|
| `directional_benchmarks` | `971426cf6846af474df1652d4a64a4bacebcc090bf0c91ed1366ffbcf8720431` | `0755` |
| `directional_compiled_api_tests` | `9eee80431354ba7f6a8122f0755cce40a367219e4596f15be6ea5b891880c07b` | `0755` |
| `directional_surface_cell_authority_kernel_tests` | `319338df85e52036a2a38cf8a515236c13f3d18b205c3f830b3f58a46970be67` | `0755` |
| `directional_surface_cell_completion_tests` | `e895a6bf556a73fd213070095ec44a22a755d22a970208e929f45386cec15ea3` | `0755` |
| `directional_surface_cell_producer_tests` | `23acd5a3bba6355d1a35ab62c9fa817e410be10ee095bedcaada7995ddacf575` | `0755` |
| `directional_surface_cell_validation_tests` | `e8a9bc573c964d09ca24e8691ef4fe1eef93b270451e6f581aae474f820b98f7` | `0755` |

## Objective

TB3-R1 is the first runtime validation of Amendment 16/P2. The preceding TB3 attempt produced no Directional process and no semantic verdict because package 71 lost executable modes. This retry begins from ordinal 1 and provides no product credit for CB4-PKG's packaging-only assertions.

## Artifact-only preflight

Before any Directional process executes:

1. download artifact `9765247195` directly and verify outer SHA-256 `41ebe4de…2e6d`; do not configure, compile, relink, repair, regenerate discovery, or substitute another package;
2. require exactly the frozen `package72.tar.gz`, its digest record and package result metadata; verify tarball SHA-256 `20630897…6a73`;
3. extract the tarball **without permission repair** and verify the complete 55-entry internal `SHA256SUMS`, source commit `93ed2ff…a9b4`, source archive `fb3080e5…812fb`, clean source-status records, `runtimeExecution=false`, and GMP/GMPXX link evidence;
4. require all six executable hashes and all six modes `0755` exactly as frozen above; any mode/hash mismatch is an orchestration blocker and must stop before runtime;
5. verify `test-data/benchmarks/fixtures` contains exactly 27 files and includes `mechanical_feature.obj`, `mechanical_feature.rawfield`, `sphere_prescribed.obj`, `sphere_prescribed.rawfield`, and `milestone_g_manifest.json`; statically prove no compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` authority remains;
6. recompute selector 373 plus frozen 355/357/361/365/367/370 prefix hashes, exact cardinality, uniqueness, and byte-prefix continuity;
7. require all package/source/test/fixture/selector mutation, configure, compile, relink, repair, generated-discovery, and benchmark flags false.

A failed precondition is an orchestration blocker, not a semantic result. Preserve it and stop before runtime. Do not `chmod`, repack, or repair package 72 inside TB.

## Ordered execution

Execute selector ordinals **1 through 373 in order, one exact identity per fresh process**. Every process must select exactly one identity. Preserve identity, ordinal, command, stdout/stderr, exit code, selection count, and structured diagnostics. Stop immediately at the first semantic red; do not execute later ordinals afterward.

Required closure result: **373/373 PASS** plus immutable postflight. The already accepted 365-prefix must remain green.

### Required checkpoint-local evidence

- **366 — mechanical production path:** require production to advance through `FieldTransportAtlas` and `FieldAlignedCurveNetwork` without `MissingSingularityBranchTransport`. Record every barrier-incident singularity row (source vertex, index, `d_B(v)`, transport-star component count, class, and port policy), aggregate count **4**, `BarrierAbsorbed` count **4**, and emitted port count **0** for those four. Record AM1 barrier decomposition (`n/m/c/χ(B)/∂`), component tree/cycle status, cycle rows/curvatures/inner adjacencies, and exact typed locus if any stage fails. Branch transport across a hard feature remains prohibited.
- **367 — retained production form:** preserve full comparable CP4c-3 provenance and result.
- **368 — prescribed sphere:** record `NoCarrierMatch` versus `AmbiguousCarrierMatch`, precise/widened pass, candidate count/loci, and originating topology error. Do not design a correction inside TB.
- **369 — ordinary proposal:** prove/falsify `OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`, keeping saturation distinct from ordinary selection.
- **370 — empty network:** prove/falsify typed `EmptyNetworkOnClosedSurface` with its frozen locus contract.
- **371 — barrier-cycle exclusion:** require barrier edges absent from inner-edge cycle columns.
- **372 — cut identity:** verify `χ(R_cut) = χ(R) − χ(B) + ∂` from independently reported counts.
- **373 — barrier singularity binding:** require the prescribed barrier-arc singularity to remain slit-bound with **unbound = 0**, `portPolicy=BarrierAbsorbed`, and zero emitted/attached singularity ports for that absorbed fact.

## Retry and stop rules

A deterministic semantic red is never retried unchanged. Preserve the first red and route to independent `REVIEW + PLAN`.

An orchestration/control failure may restart from ordinal 1 only after its exact control defect is diagnosed and corrected without mutating package 72 and only when the failed attempt produced no semantic verdict. Any restarted attempt begins again at ordinal 1; it does not resume at the previous stopping ordinal.

## Regression/accounting closeout

For every observed semantic red, update `Regression_Root_Cause_Tracker.md` before TB closes. Promote a stable event/recurrence only if the evidence meets the tracker's stable criteria; otherwise record/update a candidate and explicitly preserve stable totals. Do not count orchestration blockers as product semantics.

## Immutable postflight

After semantic execution, re-hash the downloaded package artifact, tarball, extracted package manifest/source archive, selector/prefix files, executable hashes/modes, and fixtures. Require equality with preflight and prove no configure, compile, relink, repair, generated discovery, benchmark, or package/source/test/fixture/selector mutation occurred. A postflight mismatch invalidates semantic authority and is an orchestration failure.

## Benchmark plan

None. No benchmark is frozen for CP4c-3 closure.

## Completion criteria

- **GREEN:** 373/373 PASS + immutable pre/postflight PASS + no prohibited activity → CP4c-3 closes.
- **RED:** valid first semantic red → CP4c-3 remains open; exact successor is independent `REVIEW + PLAN`.
- **BLOCKED:** orchestration/pre/postflight invalid with no semantic verdict → preserve package 72 and repair only the control plane before any restart.

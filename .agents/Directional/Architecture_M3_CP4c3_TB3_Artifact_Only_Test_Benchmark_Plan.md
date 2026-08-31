# M3 CP4c-3 TB3 — Artifact-Only Test + Benchmark Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB3`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation identity

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence source: `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`
- Immutable GMP package **71**: artifact `9750235004`
- Actions SHA-256: `bcda529df43e1ddca2de0af8eacaca165c839be01961d6edb36b9b0a5df2b038`
- Packaged source archive SHA-256: `fb3080e58f41f7c55790f8a77ad9989ce4a91e212ae323ab71afc9bc061812fb`
- Package fixture log: artifact `9750235481`, SHA-256 `e628989374fb6b1529ab0a6c8c9a41ff764770aa2e67d64bafeaf580c5c78f8b`
- Frozen selector 373: `Architecture_M3_CP4c3_Required_Green_Selector_373.txt`, SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Fixture authority: `test-data/benchmarks/fixtures`, 27 immutable files, package-relative.

## Objective

TB3 is the first runtime validation of Amendment 16/P2 and must also reach the still-unexecuted CP4c-3 ordinals 367–373 if earlier identities remain green. It provides no credit for compile-only assertions from CB3.

## Artifact-only preflight

Before any Directional process executes:

1. download artifact `9750235004` directly; do not configure, compile, relink, repair, regenerate discovery, or substitute another binary;
2. verify Actions digest `bcda529d…2b038`, the complete internal manifest, source commit `93ed2ff50ddad96c9a6aa93f327b3e4d9d93a9b4`, packaged source archive `fb3080e5…812fb`, executable modes, clean source-status records, `runtimeExecution=false`, and GMP/GMPXX link evidence;
3. require `metadata/fixture-package-contract.txt` to declare package-relative authority, `compileTimeAbsoluteSourceFallback=false`, and fixture count 27; verify the selected runtime fixture root `test-data/benchmarks/fixtures` contains at least `mechanical_feature.obj`, `mechanical_feature.rawfield`, `sphere_prescribed.obj`, `sphere_prescribed.rawfield`, and `milestone_g_manifest.json`;
4. statically prove no compile-time absolute `DIRECTIONAL_TEST_SOURCE_DIR` authority remains in the packaged producer test binary/source;
5. recompute selector 373 plus frozen 355/357/361/365/367/370 prefix hashes, exact cardinality, uniqueness, and byte-prefix continuity;
6. require all package/source/test/fixture/selector mutation, configure, compile, relink, repair, generated-discovery, and benchmark flags false.

A failed precondition is an orchestration blocker, not a semantic result. Preserve it and stop before runtime.

## Ordered execution

Execute selector ordinals **1 through 373 in order, one exact identity per fresh process**. Every process must select exactly one identity. Preserve identity, ordinal, command, stdout/stderr, exit code, selection count, and structured diagnostics. Stop immediately at the first semantic red; do not execute later ordinals afterward.

Required closure result: **373/373 PASS** plus immutable postflight. The already accepted 365-prefix must remain green.

### Required evidence when checkpoint-local identities are reached

- **366 — mechanical production path:** require the production path to advance through `FieldTransportAtlas` and `FieldAlignedCurveNetwork` without `MissingSingularityBranchTransport`. Record every barrier-incident singularity row (source vertex, index, `d_B(v)`, transport-star component count, class, and port policy), aggregate count **4**, `BarrierAbsorbed` count **4**, and emitted port count **0** for those four. Record AM1 barrier decomposition (`n/m/c/χ(B)/∂`, component tree/cycle status), cycle rows/curvatures/inner adjacencies, and exact typed locus if any stage fails. A branch transport across a hard feature is a defect, not an allowed workaround.
- **367 — retained production form:** preserve full comparable CP4c-3 provenance and result.
- **368 — prescribed sphere:** record `NoCarrierMatch` versus `AmbiguousCarrierMatch`, precise/widened pass, candidate count/loci, and originating topology error. AL4 still forbids designing a fix inside TB.
- **369 — ordinary proposal:** prove/falsify `OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`, keeping saturation distinct from ordinary selection.
- **370 — empty network:** prove/falsify typed `EmptyNetworkOnClosedSurface` with its frozen locus contract.
- **371 — barrier-cycle exclusion:** require barrier edges absent from inner-edge cycle columns.
- **372 — cut identity:** verify `χ(R_cut) = χ(R) − χ(B) + ∂` from independently reported counts.
- **373 — barrier singularity binding:** require the prescribed barrier-arc singularity to remain slit-bound with **unbound = 0**, `portPolicy=BarrierAbsorbed`, and zero emitted/attached singularity ports for that absorbed fact.

## Retry rule

A deterministic semantic red is never retried unchanged.

An orchestration/control failure may restart from ordinal 1 only after the exact control defect is diagnosed and corrected **without mutating package 71**, and only when the prior attempt **produced no semantic verdict**. This is intentionally not keyed to whether zero Directional processes executed: preceding green processes followed by a harness/control blocker do not themselves constitute a checkpoint semantic verdict. Once a valid semantic first-red exists, preserve it and route to review instead of restarting.

## Regression/accounting closeout

For every observed semantic red, update `Regression_Root_Cause_Tracker.md` before TB closes. Promote a stable event/recurrence only if the evidence meets the tracker's stable criteria; otherwise record/update a candidate and explicitly preserve stable totals. Do not count an orchestration blocker as product semantics.

## Immutable postflight

After semantic execution, re-hash package 71, its source archive, selector/prefix files, executable modes, fixtures, and all internal manifest entries. Require byte/mode equality with preflight and prove no configure, compile, relink, repair, discovery, benchmark, or package/source/test/fixture/selector mutation occurred. A postflight mismatch invalidates the semantic authority and is an orchestration failure.

## Benchmark plan

None. No benchmark is frozen for CP4c-3 closure.

## Completion criteria

- **GREEN:** 373/373 PASS + immutable pre/postflight PASS + no prohibited activity → CP4c-3 closes.
- **RED:** valid first semantic red → CP4c-3 remains open; exact successor is independent `REVIEW + PLAN`.
- **BLOCKED:** orchestration/pre/postflight invalid with no semantic verdict → repair only the control plane, preserve package 71, and restart according to the corrected rerun rule.

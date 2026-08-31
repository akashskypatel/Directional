# M3 CP4c-3 TB2 — Artifact-Only Test + Benchmark Report

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB2`
Status: **COMPLETE / RED — VALID SEMANTIC FIRST-RED AT ORDINAL 366**

- Phase: M3 / CP4c-3
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Immutable semantic/evidence source: `005512f20ed56edc793f4d6505f3d2b4c2999c71`
- Immutable GMP semantic package **69**: artifact `9742715856`, SHA-256 `2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`
- User-authorized fixture-only execution package **70**: artifact `9744461475`, SHA-256 `4265079b78af1a95300eebdaa5f2b2643030aa1ad2f51b70f904d88b16de7fe5`
- Packaged source archive SHA-256: `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`
- Frozen selector 373 SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Exact static target-map SHA-256: `f73ea05bb146a7e4a71329b5bd4344898c7fc643094be4858ea8a17ab075d740`
- Authoritative execution: run `33355714664`, result artifact `9745109157`, log artifact `9745109337`

## 1. Orchestration remediation authority

The original package-69 TB2 attempt exposed `M3-CP4c3-TB2-ORCH-01`: after ordinals 1–40 were green, ordinal 41 failed before product adjudication because `TestFixturePaths` exhausted sibling/bin `test-data` probes and fell back to the missing absolute compile-time `DIRECTIONAL_TEST_SOURCE_DIR`. The required manifest already existed in the immutable packaged source.

The user explicitly authorized an orchestration/fixture-only correction and same-turn regeneration/re-execution. Package 70 therefore copied the exact `benchmarks/fixtures` tree from the immutable embedded source archive into sibling `test-data/benchmarks/fixtures`. Regeneration proved the semantic binaries byte-identical to package 69 and recorded `semanticBinariesUnchanged=true`; no configure, compile, relink, product/test source repair, or runtime occurred while producing package 70.

R1–R3 were orchestration-only mapping/preflight trials. Each failed before yielding gate authority. Their failures are control-plane history only and are superseded by R4.

## 2. R4 immutable preflight

Before the first Directional process, R4 proved:

- package-70 outer SHA-256 matched exactly;
- internal package manifest: **55/55 PASS**;
- semantic source commit and packaged source archive matched the frozen authority;
- source-status snapshots were empty;
- `exactArithmeticBackend=GMP` and both `libgmpxx` / `libgmp` link evidence reproduced;
- selector 373 had **373 lines / 373 unique identities** and matched the frozen SHA-256;
- the static target map matched SHA-256 `f73ea05bb146a7e4a71329b5bd4344898c7fc643094be4858ea8a17ab075d740` with producer 227 / authority-kernel 30 / completion 75 / validation 41;
- a known fixture manifest plus the mechanical and prescribed-sphere assets existed at the sibling package `test-data` root selected before the compile-time fallback;
- all four packaged test binaries retained executable mode `0755`;
- generated test discovery, configure, compile, relink, repair and benchmark execution were all false.

This closes `M3-CP4c3-TB2-ORCH-01` as a non-stable harness defect.

## 3. Valid gate result

R4 executed selector 373 in frozen order, one exact `--gtest_filter=<identity>` per fresh process, stopping at the first semantic red.

Ordinals **1–365** each selected exactly one test and exited 0. Ordinal **366** produced the first red:

- ordinal: **366**
- identity: `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`
- selected count: **1**
- process exit: **1**
- exception: `mechanical feature pipeline did not retain CP4c topology authority: InvalidFieldTransportAtlas/field-transport-atlas/MissingSingularityBranchTransport`

This is a valid semantic failure inside the tested product path. It is not an orchestration failure. Ordinals **367–373** were not executed under first-red semantics.

The result is therefore **365 passed / 366 executed / first-red 366**.

## 4. Product-evidence boundary

The mechanical witness's prior TB1 stop was `IncompleteCycleBasis → CycleTransportAdjacencyMissing`. R4 proves that the CB2/Amendment-15 implementation advances beyond that earlier failure and reaches later field-atlas singularity attachment. TB2 does **not** establish why `MissingSingularityBranchTransport` occurs and does not authorize a fix.

In particular, no one may infer from this failure that a hard-feature barrier should receive a transport adjacency: Amendment 15 explicitly prohibits that shortcut. The independent review must trace `build_singularity_attachments`, the slit-bound prescribed-singularity cycle binding, and the branch-transport contract before deciding whether the consumer expectation is invalid, a non-barrier route is missing, or another representation mismatch exists upstream.

Because first-red stopped at 366, ordinals 367–373 — including the prescribed sphere, R10, R8, and the three Amendment-15 local identities — remain unmeasured in this run.

## 5. Postflight immutability

R4 postflight reported **PASS** and re-proved:

- `packageMutation=false`;
- `sourceMutation=false`;
- `selectorMutation=false`;
- `mappingMutation=false`;
- `compileExecution=false`;
- `relinkExecution=false`;
- `repairExecution=false`;
- `generatedDiscovery=false`;
- `benchmarkExecution=false`.

Package 70 is fixture-only execution transport; package 69 remains the semantic build authority because the semantic binaries are byte-identical. Selector 373 and semantic source `005512f20ed56edc793f4d6505f3d2b4c2999c71` remain frozen.

## 6. Regression and accounting disposition

`M3-CP4c3-TB2-ORCH-01` is **RESOLVED / ORCHESTRATION / NON-STABLE**.

New candidate `M3-CP4c3-TB2-CAND-01` is **ACTIVE / REVIEW REQUIRED / NON-STABLE** for the exact ordinal-366 `MissingSingularityBranchTransport` first-red. It is not promoted to a stable regression event because CP4c-3 is unaccepted and the accepted 365-prefix is green.

Stable accounting remains **44 events / 14 categories / 30 recurrences**. Produced-witness debt remains **5**. Authoritative semantic M3 package count remains **69**.

## 7. Disposition and exact successor

`M3-CP4c-3-TB2` is formally complete as **RED — VALID SEMANTIC FIRST-RED AT ORDINAL 366**. CP4c-3 remains **OPEN**.

Exact successor: independent **`M3-CP4c-3-TB2-REV` — REVIEW + PLAN**. It must update `ORIENTATION.md`, adjudicate `M3-CP4c3-TB2-CAND-01`, and establish the singularity-attachment/branch-transport contract before prescribing any product correction. No product/test/build correction, semantic rebuild, or TB retry is authorized before that review.

# M3 CP4c-3 TB2 — Artifact-Only Test + Benchmark Plan

Date: 2026-08-31 UTC
Turn: `M3-CP4c-3-TB2`
Status: **FROZEN SUCCESSOR PLAN / NOT EXECUTED**

## Validation Identity

- Phase: M3 / CP4c-3
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: `005512f20ed56edc793f4d6505f3d2b4c2999c71`
- Immutable build package **69**: artifact `9742715856`, Actions SHA-256 `2accc6d7cbbd48531919518ceb93a9d8f837b1c5683769a88ef915e4f092efc5`
- Diagnostic build log: artifact `9742715997`, SHA-256 `f0f94864be943658bc4d461bdafc312b1d40333e7eca9d2dd4ae88cacdfb218b`
- Packaged source archive SHA-256: `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`
- Frozen selector: `Architecture_M3_CP4c3_Required_Green_Selector_373.txt`, SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`
- Planned environment: execute only the packaged producer/test binaries; GMP/GMPXX authority must reproduce from package evidence before runtime.

## Validation Objective

TB2 determines whether the Amendment 15 A1 transport cut and its fail-closed controls satisfy the complete cumulative CP4c-3 gate without regressing the accepted 365-prefix. It also executes the inherited prescribed-sphere, proposal-heuristic, and empty-network identities that were appended under AL7/AM8. The build proves only compilation; this turn provides the first semantic evidence for all six new ordinals 368–373 and re-evaluates ordinals 366–367 on the corrected source.

## Preconditions

Before any Directional runtime:

1. download artifact `9742715856` directly; do not rebuild, relink, repair, regenerate discovery, or substitute another executable;
2. verify the Actions artifact digest, internal 28-entry manifest, source commit `005512f20ed56edc793f4d6505f3d2b4c2999c71`, source archive SHA-256 `c7cd8b4bbba2d3b374da7c7f18e27c0e688ffe7679c261b644c6fffbf34426b1`, executable modes, empty source-status snapshots, `runtimeExecution=false`, and `exactArithmeticBackend=GMP` with both GMP/GMPXX link evidence;
3. recompute selector 373 SHA-256 `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834` and all frozen prefix hashes 355/357/361/365/367/370 from packaged/committed bytes; require 64 lowercase hex, exact cardinality, uniqueness, and byte-prefix continuity;
4. require every mutation/repair/compile/configure/generated-discovery/benchmark flag false before semantic execution.

Any precondition failure is an orchestration blocker: stop before runtime and preserve the mismatch. It is not a semantic gate result.

## Ordered Execution Plan

### 1. Cumulative required-green selector 373

Execute ordinals **1 through 373 in order, one identity per fresh process**, using the immutable packaged executable. Each identity must select exactly once. Stop immediately at the first red; do not execute later ordinals after that first red. Preserve stdout/stderr, exit code, exact identity/ordinal, diagnostics, and process-level selection count for every executed identity.

Required outcome for closure: **373/373 PASS** with no zero-selected, duplicate-selected, crash, timeout, or escaping exception. The already accepted **365/365 prefix must remain green**. A red at any ordinal keeps CP4c-3 open and routes to `REVIEW + PLAN`; do not repair or rebuild inside TB.

### 2. CP4c-3 new semantic surfaces

When reached under first-red ordering, record these exact additional facts:

- **366 mechanical production path:** AM1 barrier-set/component decomposition, including whether source edge `0-3` belongs to `B(R)`, `n/m/c/χ(B)/∂`, component tree/cycle shape, tips/branches/boundary incidence, post-cut local topology, cycle rows/curvatures/inner adjacencies, witness-kind/index sums, and absorbed `correction`.
- **367 retained full production form:** preserve existing CP4c-3 provenance so a pass/failure remains comparable to TB1.
- **368 prescribed sphere:** AM7 `NoCarrierMatch` versus `AmbiguousCarrierMatch`, precise versus widened pass, candidate count/loci, and originating topology error. Do not infer or implement a fix in execution.
- **369 ordinary trace-crossed proposal:** prove or falsify `OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation`; saturation evidence must remain distinguishable from ordinary selection.
- **370 empty closed-surface network:** prove or falsify typed `EmptyNetworkOnClosedSurface` rejection with its frozen locus contract.
- **371 barrier-cycle exclusion:** `NonSeparatingBarrierEdgeIsAbsentFromLocalCycleBasis` must prove barrier edges are absent from inner-edge cycle columns rather than merely tolerated when adjacency is missing.
- **372 cut identity:** `CutTransportDomainSatisfiesTheEulerCutIdentity` must verify `χ(R_cut) = χ(R) − χ(B) + ∂` from independently reported counts.
- **373 singularity binding:** `PrescribedSingularityOnABarrierArcRemainsBoundToACycle` must report local-cycle/slit-boundary/unbound counts and require **unbound = 0**.

### 3. Regression/accounting review

For every semantic red, categorize it in `Regression_Root_Cause_Tracker.md` before TB closes. Promote a stable event/recurrence only when the evidence satisfies the tracker's stable criteria; otherwise update/create a candidate and explicitly keep stable totals unchanged. The compile-only default-construction failure from CB2 is not semantic runtime evidence.

### 4. Immutable postflight

After semantic execution, re-hash the package, source archive, selectors, executable modes, and all internal manifest entries; compare against preflight. Assert no configure, compile, relink, repair, generated discovery, source/test/fixture/selector/package mutation, or benchmark occurred. Postflight mismatch invalidates the execution authority and must be preserved as orchestration evidence rather than interpreted as product semantics.

## Benchmark Plan

- Applicable: **no** for this checkpoint gate. No benchmark is frozen for TB2.
- Runtime/memory data may be recorded diagnostically but has no gate credit and may not replace correctness evidence.

## Unit-Test Design Check

The six appended identities were authored and compiled in CB2. TB2 does not edit them. Each is a semantic contract: three inherited production-path questions (sphere, ordinary proposal, empty network) and three Amendment-15 controls (barrier exclusion, cut identity, singularity binding). Their acceptance is the boolean/product evidence produced by the immutable package, not assertions introduced during execution.

## Stop and Blocker Conditions

Stop and preserve evidence when artifact/source/selector identity does not match; integrity/GMP preflight fails; an identity selects zero or more than once; the first semantic red occurs; a process crashes/times out/throws outside the typed product boundary; or postflight detects mutation. Do not rerun an unchanged deterministic failure and do not compile a replacement package in TB.

## Plan-Defined Reruns

No semantic retry is authorized for a deterministic red. An orchestration-only failure before Directional runtime may be retried only after its exact control defect is diagnosed and corrected without mutating the immutable package. First-red ordering starts again from ordinal 1 only when the prior attempt executed no Directional runtime; otherwise preserve the semantic run and route to review.

## Completion Criteria

- **Green:** 373/373 PASS, immutable pre/postflight PASS, no prohibited activity → CP4c-3 closes.
- **Red:** valid first semantic red with accepted evidence → CP4c-3 remains open and exact successor is independent `REVIEW + PLAN`.
- **Blocked:** pre/postflight or orchestration authority invalid → repair only the control plane, preserve package 69, and do not count a semantic attempt.

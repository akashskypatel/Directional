# M3-CP4c-3-TB15 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN / EXACT NEXT TURN / ARTIFACT-ONLY.
**Owner:** `M3-CP4c-3-TB15`.
**Prerequisite:** `M3-CP4c-3-CB17` is COMPLETE / BUILD + PACKAGE GREEN / DIAGNOSTIC-ONLY / RUNTIME-FREE.

## 1. Immutable authority

TB15 consumes only immutable package **85** produced by CB17:

- semantic source **`1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`**;
- compile run/job **`33697315308 / 100468915978`**;
- compile result artifact **`9872340053`**, Actions digest **`3a814357edf9b1f2424f4047b6c84b1e37ed54dc1751ab6a1fa3b125af206274`**;
- compile log artifact **`9872340412`**, Actions digest **`fcda1a3fbd206e6b9ce159dea3516a18b405897d842528268a28ad0827023b39`**;
- package run/job **`33697837275 / 100470530585`**;
- package artifact **`9872426500`**, Actions digest **`6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`**;
- package log artifact **`9872426826`**, Actions digest **`33ee68f4217af33ce8c37049820c3a7f41bae55c29c97972025887f616d99b20`**;
- inner deterministic `package85.tar.gz` SHA-256 **`98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`**;
- packaged source archive SHA-256 **`cb078005cef48d97401ddfb843a4276f92c53086b0827a915b01344dc665c4a9`**;
- selector **381**, SHA-256 **`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`**;
- frozen selector **380**, SHA-256 **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`**;
- accepted prefix remains **365/365**.

No checkout build, configure, relink, package repair, source/test/fixture/selector mutation, generated discovery, or benchmark execution is permitted in TB15. Despite the canonical turn name, **no benchmark is frozen for this diagnostic gate**.

## 2. Preflight

Before executing any Directional identity:

1. verify package artifact `9872426500` against the recorded Actions digest;
2. extract package 85 and verify internal `SHA256SUMS`, exact source commit, `runtimeExecution=false`, `packageRepair=false`, and `exactArithmeticBackend=GMP`;
3. verify GMPXX/GMP linkage evidence, 27 package-relative fixtures, and executable mode on all six packaged `directional_*` binaries;
4. verify selectors 373-381, their recorded hashes, line counts, uniqueness, and every append-only prefix relation through 381;
5. record a byte-and-mode census for all immutable package files needed for postflight comparison.

A preflight identity/hash/mode mismatch is orchestration failure. Execute zero semantic identities until corrected; do not repair the package.

## 3. Gate execution

Execute selector **381** from ordinal 1 in order. Run **one exact identity per fresh process**. Record identity, exit status and relevant diagnostics for every ordinal.

- Ordinals **1-365** are the accepted boundary and must remain **365/365 PASS**.
- The first semantic red at or after ordinal 366 is the checkpoint frontier. Gate credit stops there, but the remainder through ordinal 381 still executes once each as report-only evidence.
- Do not rerun a semantic red to seek a different result. A rerun is allowed only for a demonstrated orchestration failure that executed no creditable semantic identity.
- Execute `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` exactly once as the retained **non-gating diagnostic**, in a fresh process, with zero gate credit.
- Execute no benchmark.

## 4. BN9 mandatory discriminators

TB15 must publish all six CB17 discriminators:

1. **Accepted boundary:** ordinals 1-365 remain 365/365 PASS.
2. **No semantic movement:** ordinal 366 remains `RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid` at source edge **25-31**, face `(25,30,31)`, certification attempt 0 / zero cut edges. Any change in frontier locus/reason/attempt falsifies CB17 BN7 and stops semantic diagnosis of the new typed reason.
3. **Exact typed branch:** the ordinal-366 production line names the exact `EdgeTraceSecondaryRankFailureReason`: one of `TraceRayFaceUnavailable`, `SourceFaceRecordUnavailable`, `ContactEdgeUnavailable`, `OppositeCarrierNotInFace`, `CoincidentLocalEdgeIndex`, or `SourceVertexFallbackUnbound`.
4. **Retained incidence:** the same line carries arc, trace, orientation, segment interval, incoming carrier, outgoing carrier, resolved contact index, candidate other carrier when available, trace source vertex and face corners.
5. **Bounded census:** the edge-locus rotation-ray census is present and includes total count plus explicit truncation state; each published ray carries kind, primary, secondary when available, arc, trace, orientation and source face.
6. **Inherited v47 obligation:** the full five-ray/distinct-secondary v47 conjunction remains owed. Selector 380 is expected to remain RED at the upstream edge-locus frontier until its responsible owner is corrected. Do not close `M3-CP4c3-TB11-CAND-01` or `M3-CP4c3-TB12-REV-CAND-01` merely because the old v47 collision is absent.

**There is no vertex-30 discriminator.** Do not infer vertex-30 reachability from later selector execution.

## 5. Selector-381 witness

`GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible` is the appended selector identity at ordinal 381. Execute it once in normal selector position. A pass establishes only the bounded diagnostic contract: each typed branch is reachable through the constructed production diagnostic surface and successful rank behavior remains byte-for-byte/equality-equivalent. It does not identify which branch owns ordinal 366; only the production ordinal-366 diagnostic can do that.

## 6. Branch ownership and review routing

TB15 is a diagnostic discrimination turn. If ordinal 366 remains at the frozen locus and supplies a typed reason, preserve that measured branch as the new authoritative semantic evidence. Do **not** implement a correction in TB15.

- `OppositeCarrierNotInFace` identifies the producer/trace-carrier side as the next review target.
- `SourceVertexFallbackUnbound` identifies the fallback/rank-contract side as the next review target.
- Any of the other four typed reasons contradicts the TB14-REV elimination assumptions and must be reviewed before a correction is authorized.
- If the typed field is absent or the locus moves, classify CB17 diagnostic instrumentation as falsified and route to independent review.

Every observed regression/candidate must be categorized in `Regression_Root_Cause_Tracker.md` before TB15 closes. Stable historical counts change only if tracker rules are satisfied.

## 7. Postflight and accounting

After all required processes complete, recompute the preflight byte-and-mode census. Package 85 must be bit/mode-identical. Record that no configure/build/relink/repair/generated discovery/source/test/fixture/selector mutation or benchmark occurred.

Starting accounting:

- accepted semantic authority: **365/365**;
- stable regressions: **44 events / 14 categories / 30 recurrences**;
- produced-witness debt: **5**;
- authoritative semantic M3 package count: **82**.

TB15 does not increment package count.

## 8. Completion and stop rules

TB15 is complete only when:

- all 381 selector identities were attempted exactly once under the fresh-process rule, subject only to an orchestration failure that executed no creditable semantic identity;
- the retained non-gating diagnostic ran once;
- all six BN9 discriminators are reported;
- selector-381 witness disposition is recorded;
- every observed regression/candidate is updated in the tracker;
- package postflight is immutable.

A semantic red routes to independent **REVIEW + PLAN**. TB15 performs no product/test/fixture/selector correction and no unchanged semantic retry. If the gate is unexpectedly fully green, close CP4c-3 only if all inherited obligations and checkpoint criteria are actually satisfied; otherwise route the unexplained state to independent review rather than inferring closure.

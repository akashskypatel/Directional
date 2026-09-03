# M3-CP4c-3-TB15 Artifact-Only Test + Benchmark Report

Date: 2026-09-03 UTC
Turn: `M3-CP4c-3-TB15`
Status: **COMPLETE / VALID SEMANTIC RED / BRANCH DISCRIMINATED / NON-STABLE**

## Immutable authority and execution boundary

TB15 consumed immutable package **85** only:

- semantic/package source **`1e671ef79a4cf3fbbcfc8664c9d792ace26b58e4`**;
- package artifact **`9872426500`**, Actions SHA-256 **`6c0e960b3f689bae2d2ef7f79c32709f63d1fefa87ecefdf6351427ac91ea0e2`**;
- inner `package85.tar.gz` SHA-256 **`98f5940254beaa50ec200157a3cbe6ab0ec15d8a5117006679d42684968aad08`**;
- packaged source archive SHA-256 **`cb078005cef48d97401ddfb843a4276f92c53086b0827a915b01344dc665c4a9`**;
- selector **381**, SHA-256 **`af667aae37dc6c2342c8f084b4c7ff97719798d76bce5cbb34163afecdd38d90`**;
- selector 380 frozen prefix SHA-256 **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`**;
- accepted selector-365 prefix SHA-256 **`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`**.

Authoritative execution:

- run/job **`33700074471 / 100477303760`**;
- orchestration event SHA `3f089689fc57b93e59ac1952b8f34d47cc195501` — control-plane only, not semantic source;
- result artifact **`9873244271`**, SHA-256 **`4bf9cbbf415aecf42f08f6840890e7e21dfd18899cfec863f4984ddab618493a`**;
- diagnostic-log artifact **`9873244582`**, SHA-256 **`243d8867a5a2807d329d2945184ca4999622ed1ae2129fbe30026d2c40919c46`**.

Preflight verified the package/source hashes, internal `SHA256SUMS`, exact source commit, GMP/GMPXX evidence, 27 package-relative fixtures, all six executable modes (`755`), selectors 373-381 and every append-only prefix relation. Runtime flags were `runtimeExecution=true`, `benchmarkExecution=false`, `configureExecution=false`, `compileExecution=false`, `relinkExecution=false`, `packageRepair=false`, `generatedDiscovery=false`, and source/test/fixture/selector mutation all false.

## Gate result

Selector **381** completed all 381 exact identities, one per fresh process, for **372 PASS / 9 RED**.

- ordinals **1-365: 365/365 PASS**;
- first semantic red: **ordinal 366**;
- report-only reds: **366, 367, 368, 369, 370, 371, 372, 374, 380**;
- selector-381 appended witness `GlobalTopologyPlan.EdgeLocusSecondaryRankFailuresAreTypedAndProductionVisible`: **PASS**;
- selector 380 remains **RED** at its production assertion;
- retained non-gating `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`: **RED**, exit 1, zero gate credit.

The ordinal-366 frontier did **not move**. It remains:

`RotationSystemInconsistent -> EdgeTraceSecondaryRankInvalid`, source edge `25-31`, source face `(25,30,31)`, certification attempt 0 / zero cut edges / 450 candidates.

## BN9 discriminator disposition

1. **PASS — accepted boundary.** Ordinals 1-365 are again **365/365 PASS**.
2. **PASS — no semantic movement.** Ordinal 366 remains exactly at edge `25-31` / face `(25,30,31)`, reason `EdgeTraceSecondaryRankInvalid`, attempt 0 / zero cut edges. CB17 BN7 is not falsified.
3. **DISCRIMINATED — exact typed branch.** Production reports **`edgeTraceSecondaryFailure=SourceVertexFallbackUnbound`**. The TB14-REV surviving alternative `OppositeCarrierNotInFace` is excluded at the actual frontier.
4. **PASS — retained incidence.** The failing trace ray is arc **19**, trace **5**, **Reverse**, segment interval **`[0,5)`**, source vertex **35**. Incoming carrier is `none`; outgoing carrier is **`25-31`**; resolved contact index is **2**; candidate other carrier is `none`; face corners are **`{25,30,31}`**.
5. **PASS — bounded ray census.** Production publishes **3 rays**, `rotationFanCensusTruncated=false`: mandatory `(primary=2, secondary=0, arc=4, Reverse)`, mandatory `(primary=0, secondary=0, arc=5, Forward)`, and the failing trace `(primary=3, secondary=unavailable, arc=19, trace=5, Reverse, sourceFace=25,30,31)`.
6. **OPEN — inherited v47 obligation.** Selector 380 is still RED because attempt-0 rotation stops at this upstream edge-locus rank failure. The full five-ray v47 rotation and distinct former-pair secondary ranks are still unpublished; absence of the historical collision remains insufficient.

The appended selector-381 witness PASS proves the bounded typed-diagnostic surface is constructible and the successful rank path remains equality-equivalent under its focused contract. It does **not** prove the missing rank is semantically valid; independent review owns that decision.

## Exact branch evidence

The full ordinal-366 production line materially reduces the TB14-REV ambiguity:

- `sourceVertex=35` is not a corner of the resolved source face `{25,30,31}`;
- the trace has no incoming carrier and outgoing carrier `25-31` at contact index 2;
- the candidate other carrier is unavailable;
- the helper reaches the `SourceVertexFallbackUnbound` branch rather than an opposite-carrier-in-face rejection;
- the ray census is complete rather than truncated.

This proves which diagnostic branch fires, not yet whether the branch reflects a stale/invalid produced incidence or an under-specified edge-locus rank fallback. No correction is authorized in TB15.

## Carried report-only surfaces

The remainder preserves prior ownership:

- 367 and the shared mechanical 371/372 fixtures inherit the same ordinal-366 upstream edge-rank stop;
- 368 remains prescribed-sphere `TraceEventPositionInvalid` / `NoCarrierMatch / SourceEdgeUnavailable`;
- 369 remains the saturation-versus-ordinary-proposal coverage surface;
- 370 remains the empty-network typed-code/locus surface;
- 374 remains the pre-classified folded-cone `atlasBuild=false` fixture surface;
- vertex 30 and finalize/contact remain independently owned and are not reached by this evidence.

The retained non-gating diagnostic independently reports `originatingRotationSystemReason=EdgeTraceSecondaryRankInvalid`, trace 5, claimed source edge `25-31`, incoming-carrier matches 0, outgoing-carrier matches 1, furthest stage `field-aligned-network`, and no global-topology-plan snapshot.

## Package-metadata discrepancy

Package 85's frozen `fixture-package-contract.txt` names a non-gating diagnostic identity that does not exist:
`GlobalTopologyPlan.EdgeTraceSecondaryRankUnavailableIsTypedAndObservable`. The frozen TB15 plan instead explicitly requires `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable`, which exists and was executed exactly once.

This is **non-stable package metadata**, not semantic evidence. The immutable package was not repaired or repackaged. The frozen turn plan controlled the diagnostic selection, so the mismatch did not change selector execution, gate credit, package bytes, or the semantic disposition. It is recorded for future package-authoring cleanup.

## Regression and candidate categorization

- **`M3-CP4c3-TB15-CAND-01` — ACTIVE / GATING / NON-STABLE:** ordinal 366 is now specifically `SourceVertexFallbackUnbound` at the retained arc-19/trace-5 Reverse contact incidence. Independent TB15-REV must decide semantic validity and exact owner before any correction.
- **`M3-CP4c3-TB14-CAND-01` — DISCRIMINATED / SUPERSEDED BY TB15-CAND-01 / NON-STABLE:** TB15 excludes the opposite-carrier branch and resolves the ambiguity that TB14-REV intentionally left open.
- **`M3-CP4c3-TB15-PKG-01` — RECORDED / NON-GATING PACKAGE METADATA / NON-STABLE:** package 85 names the wrong non-gating diagnostic identity; no semantic process depends on that metadata field in this frozen turn.

All are on the still-unaccepted CP4c-3 surface or control-plane metadata. Stable accounting remains **44 events / 14 categories / 30 recurrences**; produced-witness debt remains **5**; authoritative semantic M3 package count remains **82**.

## Immutable postflight

The complete 58-file package byte/mode census is exactly identical before and after runtime. Pre/post census SHA-256 is **`3235eb993863ba4e4eaa88e83e46d6c4663eb5ebb6c2b4f3990ab6d1a8af6295`**. No benchmark, configure, compile, relink, package repair, generated discovery, source/test/fixture/selector mutation, or product correction occurred.

## Phase status and exact successor

TB15 is **COMPLETE / VALID SEMANTIC RED / BRANCH DISCRIMINATED / NON-STABLE**. Accepted semantic authority remains **365/365**. Package 85/source `1e671ef7...` remains immutable semantic/build authority for this measured result; the first red remains ordinal 366, now specifically `SourceVertexFallbackUnbound`.

Exact successor is **`M3-CP4c-3-TB15-REV` — independent REVIEW + PLAN only**, under `Architecture_M3_CP4c3_TB15_Independent_Review_Plan.md`. It must determine whether this contact-node Reverse-ray fallback is semantically invalid provenance or a rank-contract gap, preserve the v47 obligation and independent carried surfaces, and freeze exactly one bounded successor. No runtime, benchmark, compile, package, or product/test/fixture/selector mutation is authorized in that review.

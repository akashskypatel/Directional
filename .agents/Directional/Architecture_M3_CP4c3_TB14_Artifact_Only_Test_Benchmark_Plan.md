# M3-CP4c-3-TB14 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN / EXACT NEXT TURN / ARTIFACT-ONLY.
**Owner:** `M3-CP4c-3-TB14`.
**Prerequisite:** `M3-CP4c-3-CB16` is COMPLETE / BUILD + PACKAGE GREEN / RUNTIME-FREE.

## 1. Immutable authority

TB14 consumes only immutable package **84** produced by CB16:

- semantic source **`6808c090f2dd229a48550d758f459bfd156da4b6`**;
- compile run/job **`33682499470 / 100422188581`**;
- compile result artifact **`9866902345`**, Actions digest **`410f18cd45f0662d480592bc2bb567bb6ab02583cf0a0dd06629b5c57a0174f9`**;
- package run/job **`33683929335 / 100426817194`**;
- package artifact **`9867334959`**, Actions digest **`67f1ea7012f3b0e06a1dd60e87d40c7e593e5260703cab425c9021cb0c2ebd55`**;
- package log artifact **`9867335519`**, Actions digest **`f4b1c14c5736f4ca3e19e06533c89aa44198d180a16b4508e77350e1256b75c3`**;
- inner deterministic `package84.tar.gz` SHA-256 **`8385a994ebff3e9d3583f95f769e107a73dcec892c7d9073502103a981a40eff`**;
- packaged source archive SHA-256 **`ca898abdf3e5a4d01429048f13a2a6f09dd6bc70dabd3b866209533f9e43db95`**;
- selector **380**, SHA-256 **`1a95d32852507441c10c0c81154a595ebc367fe4137143ec9290d85d852a0e4e`**;
- frozen selector **379**, SHA-256 **`ef51298f32dd095b469e97e3a86daf2727282bdd283c1e6b777a5705842594b7`**;
- accepted prefix remains **365/365**.

No checkout build, configure, relink, package repair, source/test/fixture/selector mutation, generated discovery, or benchmark execution is permitted in TB14.

## 2. Preflight

Before executing any Directional identity:

1. verify package artifact `9867334959` against the recorded Actions digest;
2. extract package 84 and verify the internal `SHA256SUMS`, exact source commit, `runtimeExecution=false`, `packageRepair=false`, and `exactArithmeticBackend=GMP`;
3. verify GMPXX/GMP linkage evidence, 27 package-relative fixtures, and executable mode on all six packaged `directional_*` binaries;
4. verify selectors 373-380, their recorded hashes, line counts, uniqueness, and every append-only prefix relation through 380;
5. record a byte-and-mode census for all immutable package files needed for postflight comparison.

A preflight identity/hash/mode mismatch is an orchestration failure. Execute zero semantic identities until corrected; do not repair the package.

## 3. Gate execution

Execute selector **380** from ordinal 1 in order. Run **one exact identity per fresh process**. Record identity, exit status and relevant diagnostics for every ordinal.

- Ordinals **1-365** are the accepted boundary and must remain **365/365 PASS**.
- The first semantic red at or after ordinal 366 is the checkpoint frontier. Gate credit stops there, but the remainder through ordinal 380 still executes once each as report-only evidence.
- Do not rerun a semantic red to seek a different result. A rerun is allowed only for a demonstrated orchestration failure that executed no creditable semantic identity.
- Execute `GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable` exactly once as the retained **non-gating diagnostic**, in a fresh process, with zero gate credit.
- No benchmark is part of this turn unless a frozen TB14 criterion explicitly requires one; none does.

## 4. BL9 mandatory discriminators

TB14 must publish all six CB16 discriminators:

1. **Accepted boundary:** ordinals 1-365 remain 365/365 PASS.
2. **Vertex-10 correction:** ordinal 366 no longer reports the TB13 source-vertex-10 rotation failure through the old ambiguous `VertexTracePortOrdinalInvalid` path. An identical repeat falsifies CB16.
3. **Reason separation:** any remaining vertex-trace secondary-parameter rotation red is distinguishable. `VertexTraceSecondaryParameterUnavailable` must identify its `VertexTraceSecondaryParameterFailureReason` plus arc, trace, orientation and segment bounds; `VertexTracePortOrdinalInvalid` now means the legacy port/ordinal emitter specifically.
4. **BK7 / v47 conjunction:** the old v47 `RotationRayOrderKeyCollision` remains absent **and** the full five-ray v47 rotation is published with distinct secondary ranks for the former pair (arc 20 / trace 6 / Forward and arc 23 / trace 9 / Reverse). Absence of the old error alone is insufficient.
5. **Candidate closure rule:** `M3-CP4c3-TB11-CAND-01` and `M3-CP4c3-TB12-REV-CAND-01` close only when discriminators 1, 2 and 4 all hold. `M3-CP4c3-TB13-CAND-01` and `M3-CP4c3-TB13-REV-CAND-01` close only if runtime confirms the vertex-10 product correction and typed split at the production boundary.
6. **Downstream reach:** if certification reaches face walking, record the first legitimate `nonDiscComponentCount` / `remainingAdmissibleEdgeCount` evidence and the exact producing reason/locus. Their absence is not itself a failure if an earlier semantic red stops execution.

**No vertex-30 discriminator exists in TB14.** Do not infer reachability or correctness at vertex 30 from CB16 compile evidence.

## 5. Selector-380 witness

`GlobalTopologyPlan.VertexExitSecondaryParameterUsesExactCornerSupportAndTypedFailure` is a normal gating selector identity at ordinal 380. It must be executed once in its normal selector position. Its pass confirms only the compiled bounded witness contract; it does not replace the production discriminators above.

## 6. Carried report-only surfaces

Unless execution produces new discriminating evidence, preserve their existing ownership and do not repair them in TB14:

- ordinal 368 prescribed sphere;
- ordinal 369 saturation;
- ordinal 370 carried gate;
- ordinals 371/372 shared fixture coupling;
- ordinal 374 folded-cone witness;
- vertex 30 and finalize/contact fall-through.

Any observed regression must be categorized in `Regression_Root_Cause_Tracker.md` before TB14 closes. A non-stable failure on the still-unaccepted CP4c-3 surface does not change stable totals unless evidence satisfies the tracker rules.

## 7. Postflight and accounting

After all required processes complete, recompute the preflight byte-and-mode census. Package 84 must be bit/mode-identical. Record that no configure/build/relink/repair/generated discovery/source/test/fixture/selector mutation or benchmark occurred.

Starting accounting is:

- accepted semantic authority: **365/365**;
- stable regressions: **44 events / 14 categories / 30 recurrences**;
- produced-witness debt: **5**;
- authoritative semantic M3 package count: **81**.

TB14 does not increment package count.

## 8. Completion and stop rules

TB14 is complete only when:

- all 380 selector identities were attempted exactly once under the fresh-process rule, subject only to an orchestration failure that executed no creditable identity;
- the retained non-gating diagnostic ran once;
- all six BL9 discriminators are reported;
- selector-380 witness disposition is recorded;
- every observed regression/candidate is updated in the tracker;
- package postflight is immutable.

A green TB14 closes CP4c-3 under the normal CB -> TB workflow. Any semantic red routes to an independent **REVIEW + PLAN**. TB14 itself performs no product/test/fixture/selector correction and no unchanged semantic retry.

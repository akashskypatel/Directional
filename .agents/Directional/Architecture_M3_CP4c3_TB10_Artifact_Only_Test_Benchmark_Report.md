# M3-CP4c-3-TB10 — Artifact-Only Test + Benchmark Report

**Turn:** `M3-CP4c-3-TB10`
**Date:** 2026-09-02 UTC
**Verdict:** **COMPLETE / VALID SEMANTIC RED / FIRST RED ORDINAL 366 / CB12 OWNERSHIP CORRECTION RUNTIME-PROVED**
**Next turn:** independent **`M3-CP4c-3-TB10-REV` — REVIEW + PLAN only** under
`Architecture_M3_CP4c3_TB10_Independent_Review_Plan.md`. No unchanged TB retry, product correction, rebuild, repackage,
or acceptance attempt is authorized before review.

## 1. Immutable authority and orchestration

TB10 consumed only immutable package **80** built from semantic source
`a3b6f1a41feaa8a115faf11de52f85ce4cc42a15`.

- authoritative compile run/job: `33581576670 / 100096794713`;
- immutable package run/job: `33582280392 / 100098880900`;
- package artifact: `9828786744`, Actions SHA-256
  `f4643d0535684f81de5afc9660ef40f2ffb941d1c540b91026225681314fe20e`;
- inner `package80.tar.gz` SHA-256:
  `4e8303489adb46528ae0a92c7ecf9dae65f0cbd57527740d845d318c65af02ce`;
- packaged source archive SHA-256:
  `026a8b1efa2dc85fe2b474e0e64657bf8f997aee5b49f274c7c0c69d279fd18a`;
- execution selector **377** SHA-256:
  `7255ac86e525e245c0c24231b70c9494349a4c1cc1dfcfeee9817cc6426cbec1`;
- TB10 run/job: **`33584653692 / 100106147126`**;
- result artifact: **`9829700900`**, Actions SHA-256
  **`2e7d978dd3ad2a5f0667ef3eed15c291ed8c7b91bb7e2d323557a8bc40763572`**;
- log artifact: **`9829701136`**, Actions SHA-256
  **`89f445c5934c3493ccf966e39f0c106c8418719a32c5d206055cafa932cce17d`**.

Preflight verified package/source/selector hashes, internal manifest, GMP/GMPXX evidence, 27 fixtures, six executable
payloads with archived mode `0755`, exact selector cardinality/uniqueness/prefix relations, and one executable owner
for every selector identity before runtime. No package repair occurred.

## 2. Ordered gate result

Selector **377** executed from ordinal 1 with **377 fresh processes** and exactly one selected identity per process.
The organic result is **369 PASS / 8 RED**.

- ordinals **1–365 = 365/365 PASS**;
- first red: ordinal **366**
  `GlobalTopologyPlan.MechanicalFeatureWitnessDerivesRegionsThroughProductionEntryPath`;
- ordinal 366 now fails at
  `NotProductionReady/surface-cut-graph/CellularityNotEstablished/origin=RotationSystemInconsistent`;
- the old TB9 condition+seed is absent: `oldOrdinal366ConditionSeedPair=false`;
- after first red, ordinals 367–377 executed report-only with zero gate credit;
- accepted semantic authority therefore remains **365/365** and CP4c-3 remains **OPEN**.

The moved first red is real semantic evidence. It is not acceptance and it is not a stable regression-count event on
this still-unaccepted CP4c-3 surface.

## 3. BD9 discriminator verdict

All CB12-specific closure discriminators pass:

1. **PASS — accepted prefix:** ordinals 1–365 remain 365/365 green.
2. **PASS — old ownership failure cleared:** ordinal 366 does not report
   `SingularityTerminationPortOwnershipMismatch` at seed vertex 47 / singularity 5.
3. **PASS — genuinely later failure:** the first red moved to surface-cut-graph
   `CellularityNotEstablished` with originating `RotationSystemInconsistent`, not a renamed terminal-ownership error.
4. **PASS — mechanical node ownership:** identity **377 PASSes** and publishes
   `m3Cp4c3BD5;terminalVertex=36;singularity=4;portPolicy=BarrierAbsorbed;node=7;incidentMandatoryEdges=36-37,36-96`.
   The identity also includes the fail-closed missing-node negative and positive `SingularityTermination` publication
   at v36's network node.
5. **CLOSED — `M3-CP4c3-TB9-REV-CAND-01`:** discriminators 1, 2, and 4 all pass, so the barrier-absorbed
   singularity-arrival ownership defect is runtime-proved corrected.

No vertex-30 conclusion is authorized by these results. `M3-CP4c3-TB6-CAND-01` remains active.

## 4. Complete red disposition and root-cause classification

Every observed red is categorized here and in `Regression_Root_Cause_Tracker.md` before TB10 closeout.

| Ordinal | Identity / observed surface | Classification and disposition |
|---:|---|---|
| **366** | mechanical production entry path → `CellularityNotEstablished/origin=RotationSystemInconsistent` | **NEW GATING / DIAGNOSTIC INSUFFICIENCY / NON-STABLE**, `M3-CP4c3-TB10-CAND-01`. Package-80 source proves `SurfaceCutGraphError` already carries `originatingRotationSystemInconsistencyReason`, source edge/face, trace/event and position diagnostics, but `RemeshPipeline.cpp`'s surface-cut-graph failure string renders only the cut-graph code and `originatingTopologyError`. The exact rotation-system subreason/locus is therefore lost at the production projection boundary. Review must adjudicate the underlying product condition before any semantic correction. |
| 367 | rotation-system/face-walk agreement witness | **REPORT-ONLY / UPSTREAM-BLOCKED by CAND-01.** It throws the same mechanical surface-cut-graph `RotationSystemInconsistent` exception before measuring its own contract. |
| 368 | prescribed sphere | **REPORT-ONLY / EXISTING PRODUCT CANDIDATE.** Reproduces `M3-CP4c2-TB-X2-CAND-04`: `RotationSystemInconsistent → TraceEventPositionInvalid`, trace 2/event 30, `NoCarrierMatch / SourceEdgeUnavailable`. No new sphere inference. |
| 369 | ordinary proposal without saturation | **REPORT-ONLY / EXISTING QUALITY-COVERAGE CANDIDATE.** Reproduces `M3-CP4c2-TB-X2-R10-CAND-01` with `saturationUsed=true`. |
| 370 | empty network on closed surface | **REPORT-ONLY / EXISTING PRODUCT CANDIDATE.** Reproduces `M3-CP4c2-TB-X2-R8-CAND-02`: actual code `CellularityNotEstablished` (4), expected `EmptyNetworkOnClosedSurface` (6), and no source-face locus. |
| 371 | non-separating barrier/local cycle-basis witness | **REPORT-ONLY / UPSTREAM-BLOCKED by CAND-01.** Same mechanical surface-cut-graph exception before its own contract is measured. |
| 372 | Euler cut-identity witness | **REPORT-ONLY / UPSTREAM-BLOCKED by CAND-01.** Same mechanical surface-cut-graph exception before its own contract is measured. |
| 374 | folded-cone owner-election witness | **REPORT-ONLY / PRE-CLASSIFIED WITNESS PRECONDITION**, `M3-CP4c3-TB7-CAND-02`; `atlasBuild=false` before the intended folded-cone election. No product inference. |

The eight reds add **+0 stable events / +0 stable recurrences**. Stable totals remain **44 events / 14 categories /
30 recurrences**; produced-witness debt remains **5**; semantic package count remains **77**.

## 5. Immutable postflight

Postflight re-ran the internal package manifest, recomputed the package-tree byte/mode census, and compared it with
preflight. The censuses are identical and the manifest verifies after all 377 processes.

Recorded boundary flags:

- `runtimeExecution=true` — expected for this Test + Benchmark turn;
- `configureExecution=false`;
- `compileExecution=false`;
- `relinkExecution=false`;
- `packageRepair=false`;
- `generatedDiscovery=false`;
- `productMutation=false`;
- `testMutation=false`;
- `fixtureMutation=false`;
- `selectorMutation=false`;
- `benchmarkExecution=false`.

No benchmark executed; TB10 is correctness validation only.

## 6. Exact successor

**`M3-CP4c-3-TB10-REV` — independent REVIEW + PLAN only.** Review the moved mechanical first red, recover or prove
the exact `RotationSystemInconsistent` subreason/locus from immutable evidence and package-80 source, decide whether
the next owner is diagnostic projection or product semantics, adjudicate all carried candidates without combining
unrelated sphere/saturation/370/folded-cone debt, update `ORIENTATION.md`, and freeze exactly one bounded successor.
No Directional runtime, compile, package, product/test/fixture/selector mutation, or unchanged TB retry is authorized
inside the review turn.

# Future Chat Session Handoff — Directional

**DURABLE — live resume authority**
**Status:** `M4-CP3-TB7-REV` COMPLETE / CANDIDATE REJECTED / TEST-AUTHORITY STABLE EVENT / CP3 OPEN
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-CB10`

## Current authority

- M1-M3: CLOSED / ACCEPTED. M4-CP1/CP2 remain historical accepted framed closures.
- Corrected R4 artifact `10289601000` remains accepted M4-CP3 runtime authority at selector403 **403/403**; selector403 SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`.
- CB9 semantic correction is **RECOVERY PROVED / RETAINED**, but package `10305678151` remains **REJECTED / UNPROMOTED** because TB7 reached accepted ordinal211 RED.
- Stable accounting is now **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. CP3 and `G4-B002` remain OPEN.

## TB7 Review disposition

TB7 mechanically produced **223 = 222 PASS / 1 RED** with immutable postflight. Focused recovery is **12/12 GREEN**: ordinal138 2/2, row408 2/2, rows404-407 8/8. This closes `M4-CP3-TB6-REV-CAND-01` **RECOVERY PROVED**; CB9's bounded-disc applicability correction remains required.

Ordinal211 `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected` is a separate accepted-prefix regression. Review proved:

1. the entire `SurfaceCellTransitionQuotientTests.cpp` file is byte-identical in accepted R4, CB5 and current/CB9 source (`4372a939...982f25`);
2. accepted R4 selector403 403/403 therefore proves ordinal211 historical PASS;
3. CB5 changed production hard-rail pairing to require exact A3 `sharedBoundaryInterval` identity;
4. the unchanged `hard_rail_fixture()` still supplies manual hard rail authority without `GlobalTopologyPlan` / `GlobalConformityBaselinePlan`;
5. it now fails fixture production at `InvalidHardRailPairing` before ordinal211's intended reciprocal-opposite tamper;
6. CB9's one-line change is inside accepted-cut handling and is unreachable from this no-plan fixture.

Classification: `M4-CP3-TB7-REV-CAND-01` **OPEN / TEST-AUTHORITY / FIXTURE-PRECONDITION DRIFT AFTER A3→A4 CUTOVER / STABLE EVENT**. Product fail-closed behavior is correct: frozen M4 authority forbids restoring floating `support_key` or inventing shared subdivisions without A3.

Only ordinal211 is a proved runtime RED. Five later accepted identities share the same fixture and are static at-risk consumers: ordinals217, 219, 227, 230 and 231. TB8 must execute all six after correction.

## Exact next — `M4-CP3-CB10`

Follow `.agents/Directional/Architecture_M4_CP3_CB10_Code_Build_Plan.md` exactly.

CB10 is **test-authority-only and runtime-free**. Before mutation it must prove G1-G4: accepted identity/byte continuity, exact missing-A3 fixture path, frozen product strictness, and one authority-complete replacement fixture route. If proven, migrate only `make_hard_rail_fixture()` onto production A2b/A3 authority while preserving the 3×3 mesh, hard support and all six downstream identity bodies/names.

Production source, A2b/A3 writers, hard-rail missing-interval rejection, CB8 occurrence-domain logic, CB9 applicability correction, rows404-408 and selector identity lists are frozen. A product fallback or second semantic dependency is a STOP back to Review.

Compile/package all eight current CP3 owner targets through the mandatory reusable GMP workflow. Execute **no Directional runtime**. CB10 must author the artifact-only TB8 plan; TB8 Review remains promotion owner.

## Carried obligations

- `M4-CP3-TB1-R1-REV-OBS-01`: multiplicity-2 end-to-end oracle remains carried/non-blocking.
- `M4-CP3-CB4-REV-OBS-02`: row399 path/`sourceFaces` divergence tamper detector remains carried/non-blocking.
- TB3 provenance warning remains: row408 is a constructed production torus witness, not evidence that `InvalidHardRailPairing` was historically observed in that exact path.

## Context Load Plan

```yaml
load_next:
  - .agents/Directional/Architecture_M4_CP3_CB10_Code_Build_Plan.md
required:
  - .agents/Directional/Architecture_M4_CP3_TB7_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB9_Code_Build_Report.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md
do_not_preload:
  - M5/M6 implementation
  - any product fallback for no-plan hard rails
  - selector continuation runtime before a new compiled package exists
```

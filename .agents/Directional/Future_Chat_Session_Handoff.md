# Future Chat Session Handoff — Directional

**Status:** `M4-CP3-DEFN-R1` COMPLETE / EXACT NEXT `M4-CP3-CB2`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** Code + Build, runtime-free

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- M4 package117 / selector382 **382/382** remains latest accepted runtime authority for the historical fully framed CP1/CP2 contract.
- Stable regression accounting: **47 events / 14 categories / 33 recurrences**.
- Produced-witness debt: **5**.
- `M4-CP3-CB1`: HALTED correctly at its pre-mutation derivation guard; no semantic mutation/build/runtime.
- `M4-CP3-DEFN-R1`: COMPLETE / runtime-free; current production-baseline definition is `Architecture_M4_DEFN_Frozen_Definitions.md` §17.

## DEFN-R1 decision

Independent source re-derivation showed the CB1 gap is broader than artificial cuts: accepted A2b has no universal source-derived `ConformityFamily/ConformitySign` for arbitrary `Mandatory` hard-feature/source-boundary arcs either. Trace-local branch integers are face-gauge-local and cannot substitute.

Frozen production baseline:

1. one exact positive count per full A2b arc (`Mandatory`, `Trace`, `Cut`), with exact support and compact `{span, exactOrdinal}` breakpoints unchanged;
2. baseline incidences carry region/span/orientation and preserve multiplicity; family/sign are not production-baseline semantic inputs;
3. each region requires even total scheduled boundary-incidence count;
4. exact preferred counts/objective remain `J=(Σ|x-d|, canonical count vector)`;
5. exact optimizer is minimum-cardinality T-join on preferred-parity residuals plus canonical lex-prefix constrained re-solves;
6. `x_s=2` for all spans proves baseline mathematical feasibility for every well-formed binding, so CP2-style ordinary infeasible subsets are not production-baseline outcomes;
7. A4 owns stronger local field/shape/geometry constructibility and may never repair/renegotiate A3 shared breakpoints.

Alternatives B (field-certify every cut) and C (invent deterministic frame labels) are rejected. M3 A2a'/A2b authority is not reopened.

## CP1/CP2 disposition

Historical package117/selector382 results and closure records remain factual and accepted evidence for the old framed domain. They are not rewritten and stable counts do not change. Their **production-sufficiency** obligations are superseded/re-opened for re-proof inside CP3 under the new parity baseline. Existing selector382 identities must not be weakened; any compatibility implementation needed to keep them executable must be explicit and structurally non-production.

## Exact next — `M4-CP3-CB2`

Use `.agents/Directional/Architecture_M4_CP3_CB2_Code_Build_Plan.md` exactly.

CB2 scope: implement and compile the family-free baseline parity A3 scheduler/certificate/validator and new independent regression/oracle source. Preserve accepted selector382 as an exact prefix of the new selector. Do not production-wire A3 into A4 yet. The new semantic core must first pass its own immutable artifact-only TB. A later CP3 CB performs producer cutover only after that acceptance.

Mandatory CB2 guard: if the production baseline cannot be bound from exact A2b arc/support/boundary incidence authority without family/sign, or if legacy framed semantics cannot be isolated from the production binder, stop before mutation and return to definition review.

No local build. All compile work uses the durable GitHub compile reusable with mandatory GMP/GMPXX. No Directional runtime in CB2.

## Current definition/review evidence

- DEFN source snapshot event: `7e90e48b0e267d312fd5c92f900c248042e4bdd9`
- snapshot run/job: `34547115117 / 103102082492`
- snapshot artifact: `10179427792`
- artifact SHA-256: `22455a3803749481b8f59496640eac621b107afbb96f05c5026bb4fe5925088d`
- current review: `.agents/Directional/Architecture_M4_CP3_DEFN_R1_Review_Record.md`
- current frozen definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §17
- successor plan: `.agents/Directional/Architecture_M4_CP3_CB2_Code_Build_Plan.md`

## Consolidation state

DEFN-R1 folds the superseded current CP2 review plus consumed CP3 CB1 plan/guard into `M4_Consolidated_Record.md` after preserving all durable facts. Full prior text remains recoverable from Git history. Retained current runtime report is `Architecture_M4_CP2_TB2_R1_Test_Benchmark_Report.md`.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: implementation design/corrective planning
    path: turn-based-coding-agent/modules/engineering-guidelines/MODULE.md
  - trigger: unit-test source design/change
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector / Actions / artifacts
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md#17-m4-cp3-defn-r1-amendment--baseline-conformity-is-exact-shared-subdivision-plus-region-parity
  - .agents/Directional/Architecture_M4_CP3_DEFN_R1_Review_Record.md
  - .agents/Directional/Architecture_M4_CP3_CB2_Code_Build_Plan.md
templates_when_producing:
  - CODE_BUILD_REPORT.md
  - TEST_PLAN.md
do_not_preload:
  - sibling turn files
  - historical M4 per-turn records already folded into M4_Consolidated_Record.md
  - research/provenance/examples not cited by the CB2 plan
```

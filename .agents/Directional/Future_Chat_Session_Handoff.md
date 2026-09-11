# Future Chat Session Handoff — Directional

**Status:** `M4-CP3-CB3` COMPLETE / TEST-ONLY RECOVERY COMPILE+PACKAGE GREEN / PACKAGE119 UNPROMOTED / EXACT NEXT `M4-CP3-TB1-R1-EXEC`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-TB1-R1-EXEC`, artifact-only Test + Benchmark execution

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- M4 package117 / selector382 **382/382** remains latest accepted runtime authority for historical fully framed CP1/CP2.
- Stable regression accounting: **47 events / 14 categories / 33 recurrences**.
- Produced-witness debt: **5**.
- `M4-CP3-DEFN-R1`: current production-baseline definition is `Architecture_M4_DEFN_Frozen_Definitions.md` §17.
- package118 / selector394 remains immutable historical TB1 evidence at **387/394** and is unpromoted.
- `M4-CP3-CB3`: complete. Exact semantic source `fd532c2f768d0ff6493260deb670cb34b6757712` changes only `tests/GlobalConformityBaselineTests.cpp` semantically, passes changed-owner preflight and full package compile through mandatory GMP/GMPXX, and executes no Directional runtime.
- post-build candidate package119 / selector394 is compile-valid but **unpromoted**. Runtime proof belongs to `M4-CP3-TB1-R1-EXEC` and later review.
- production A3→A4 cutover remains blocked.

## Frozen production A3 contract

§17 freezes one exact positive count per full A2b arc, family/sign-free region/span/orientation incidences with multiplicity, per-region even boundary count, exact preferred-count objective `J=(Σ|x-d|, canonical count vector)`, exact minimum-cardinality T-join plus canonical lex-prefix refinement, compact exact-ordinal breakpoints, and an independent validator. A4 owns stronger local constructibility and may not renegotiate A3 shared breakpoints.

## CB3 semantic correction

Only `tests/GlobalConformityBaselineTests.cpp` changed semantically:

1. `make_triangle_mesh()` is now the frozen DCEL-valid four-vertex/three-face triangular-boundary disk with exactly three source-boundary terminals.
2. ordinal392 uses target size `0.25`, asserts preferred count `4`, retains `count > 1`, forward/reverse exact ordinal and denominator assertions.
3. ordinal390's independent exhaustive oracle reconstructs per-region span-incidence multiplicity; same-region double incidences therefore have zero parity effect modulo two.
4. ordinal389 asserts live preferred/final `1 -> 2` and `2 -> 1` cases by semantic values.
5. ordinal391 proves all nine tamper-validator calls execute.
6. corrected ordinals **386,388,389,390,391,392,394** emit deterministic success-visible `M4_CP3_BASELINE_RECEIPT` lines from live values after intended assertions/calls.

No product source, selector, fixture file, CMake/build logic, reusable workflow, or frozen definition changed.

## CB3 compile/package evidence

### Work preservation/application

- implementation patch: `Directional__M4-CP3-CB3__base-28666c847089__work-preservation.patch`
- patch SHA-256: `e2ca8228625bf4f77471a81acf2aa6585b9c92a89ab8718ce9e6669eda195ec1`
- diff-body SHA-256: `622f60387d1102ec093a8954a0f5ef4a0c35783fbbef468e53125391e9928a85`
- Drive apply run/job: `34563736366 / 103151647274`
- Drive apply result artifact: `10185254954`
- semantic source: `fd532c2f768d0ff6493260deb670cb34b6757712`
- consumed Drive patch: permanently deleted after successful application

### Changed-owner preflight

- run/job: `34563902380 / 103152000174`
- target: `directional_surface_cell_producer_tests`
- result/log artifacts: `10185317910 / 10185318261`
- result/log SHA-256: `64b8279ea3d2c67ef45d39bdca586188f7979740fde000e9f8fb1b7c21568d08 / 12f8790de7acb2bafcea14591649c536f0ef7680b00c39ae527a736734cb788e`
- result: PASS, GMP/GMPXX linked, source clean, `runtimeExecution=false`

### Full package compile

- run/job: `34564069513 / 103152491832`
- exact semantic source: `fd532c2f768d0ff6493260deb670cb34b6757712`
- candidate package119 artifact: `10185370005` — `m4-cp3-cb3-package-result-34564069513`
- package ZIP SHA-256: `9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8`
- compile-log artifact: `10185370244`
- compile-log SHA-256: `5287155c1d96f03ea64b4faff02dcc54f33298f76b81160d581a5b5a8f176cb5`
- all eight approved targets compile/link green;
- package manifest verifies **28/28**;
- all packaged source-status files are empty;
- command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`;
- packaged selector394 is exactly 394 rows at `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- its first 382 rows remain `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`.

No generated Directional binary, test, benchmark, `ctest`, discovery/list, CLI, fuzzer, help/version command, or custom Directional input executed in CB3.

## Exact next — `M4-CP3-TB1-R1-EXEC`

Execute `Architecture_M4_CP3_TB1_R1_Test_Benchmark_Plan.md` against immutable candidate package119 artifact `10185370005` without rebuild or repair.

Required runtime matrix:

1. selector rows 383-394 focused pass A — expected **12/12**;
2. selector rows 383-394 focused pass B — expected **12/12**, identical ordered verdict vector;
3. for 386/388/389/390/391/392/394, exactly one matching success-visible receipt per focused process, with exact A/B receipt bytes deterministic and plan-defined parsed invariants satisfied;
4. accepted predecessor selector382 — expected **382/382**;
5. cumulative selector394 — expected **394/394**;
6. pre/post package/source/execution-view censuses identical and `SHA256SUMS` **28/28** before/after.

Expected semantic runtime process count: **800** fresh processes.

TB-EXEC is runtime execution and raw evidence preservation only. It must not diagnose by editing, rebuild, mutate package/source/selector bytes, promote package119, or production-wire A3→A4. Stop after evidence at `M4-CP3-TB1-R1-REV`, which owns diagnosis/disposition and any next plan.

## Current evidence

- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §17
- accepted runtime predecessor: package117 / selector382 **382/382**
- historical candidate compile report: `.agents/Directional/Architecture_M4_CP3_CB2_Code_Build_Report.md`
- historical TB report/review: `.agents/Directional/Architecture_M4_CP3_TB1_Test_Benchmark_Report.md`, `.agents/Directional/Architecture_M4_CP3_TB1_Review_Record.md`
- frozen CB3 plan: `.agents/Directional/Architecture_M4_CP3_CB3_Code_Build_Plan.md`
- completed CB3 report: `.agents/Directional/Architecture_M4_CP3_CB3_Code_Build_Report.md`
- exact next runtime plan: `.agents/Directional/Architecture_M4_CP3_TB1_R1_Test_Benchmark_Plan.md`
- selector: `.agents/Directional/Architecture_M4_CP3_Required_Green_Selector_394.txt`
- regression classification: `.agents/Directional/Regression_Root_Cause_Tracker.md` candidates `M4-CP3-TB1-REV-CAND-01/02`

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB.md
conditional_modules:
  - trigger: artifact-only runtime execution
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector / workflow / artifact handling
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB1_R1_Test_Benchmark_Plan.md
  - .agents/Directional/Architecture_M4_CP3_CB3_Code_Build_Report.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md#17-m4-cp3-defn-r1-amendment--baseline-conformity-is-exact-shared-subdivision-plus-region-parity
do_not_preload:
  - product implementation files unless runtime review later identifies a product defect
  - historical M4 plans already consolidated
```

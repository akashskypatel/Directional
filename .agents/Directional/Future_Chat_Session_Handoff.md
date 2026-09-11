# Future Chat Session Handoff — Directional

**Status:** `M4-CP3-TB1-REV` COMPLETE / PACKAGE118 NOT PROMOTED / TWO NON-STABLE TEST-AUTHORITY CANDIDATES / EXACT NEXT `M4-CP3-TB1-PLAN`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-TB1-PLAN`, runtime-free planning only

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- M4 package117 / selector382 **382/382** remains latest accepted runtime authority for historical fully framed CP1/CP2.
- Stable regression accounting: **47 events / 14 categories / 33 recurrences**.
- Produced-witness debt: **5**.
- `M4-CP3-DEFN-R1`: current production-baseline definition is `Architecture_M4_DEFN_Frozen_Definitions.md` §17.
- `M4-CP3-CB2`: compile/package green at semantic source `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`; package118 is candidate only.
- `M4-CP3-TB1-EXEC`: complete, immutable postflight green, candidate selector394 measured **387/394** with RED ordinals **386,388,389,390,391,392,394**.
- `M4-CP3-TB1-REV`: complete; all seven REDs are adjudicated as two non-stable test-authority candidates. No production defect was established, but package118 remains unpromoted because seven intended contracts are not validly green.

## Frozen production A3 contract

§17 freezes one exact positive count per full A2b arc, family/sign-free region/span/orientation incidences with multiplicity, per-region even boundary count, exact preferred-count objective `J=(Σ|x-d|, canonical count vector)`, exact minimum-cardinality T-join plus canonical lex-prefix refinement, compact exact-ordinal breakpoints, and an independent validator. A4 owns stronger local constructibility and may not renegotiate A3 shared breakpoints.

## TB1 execution authority

- package118 artifact `10182447649`, SHA-256 `1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5`;
- semantic source `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`;
- run/job `34557818974 / 103134172994`;
- result artifact `10183361985`, SHA-256 `9f1b15e00616d487b99edc4f6681c9097dc68ff4091a5432f95f34a5c1ea9cec`;
- diagnostic artifact `10183362199`, SHA-256 `90f9b68699157351532984c176b1aa0c8943becc54a4c75acde24973346d4eda`;
- exactly **800** fresh processes, zero timeout/skip/selection mismatch; focused rows383-394 **5/12 twice** with identical vectors; predecessor **382/382**; cumulative **387/394**; package/source/execution-view pre/post census pairs identical; package manifest **28/28** before and after.

## TB1 review adjudication

Review independently re-opened raw artifact `10183361985` and exact review-source snapshot `3ec69ffeb88f6378ca8a7a680ef8f3a7e4be64f4` (snapshot run/artifact `34559829994 / 10183917322`, outer SHA-256 `a3bc151e640b5f89ad08825f694ec13c8e59c3518764429babdb4ff7043909fb`, **5250/5250** files verified). No Directional runtime/compile occurred in review.

1. **`M4-CP3-TB1-REV-CAND-01` — invalid one-face triangle fixture / non-stable.** Ordinals **386,388,389,390,391,394** all call `make_triangle_mesh()`. A one-face triangle is rejected by strict `TriMesh` DCEL consistency because the face has no interior edge, so these tests die before intended baseline semantics.
2. **`M4-CP3-TB1-REV-CAND-02` — invalid count precondition / non-stable.** Ordinal **392** validly builds the square baseline, then assumes `schedule().front().count > 1`. Runtime gives `1`; frozen §17.6 allows the lex-minimal parity flip to map first-span preferred `d=2` to `1`. The breakpoint fixture failed to guarantee its own interior-ordinal precondition.

Both candidates are `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Stable totals remain **47 / 14 / 33**, debt **5**. Package117/selector382 stays accepted. Package118/selector394 stays immutable candidate evidence and is **not promoted**. Production A3→A4 cutover remains blocked.

## Exact next — `M4-CP3-TB1-PLAN`

Planning/documentation only. Freeze the smallest Code + Build correction for the two review candidates: a DCEL-valid fixture that preserves the six tests' intended three-terminal semantics, and an independently guaranteed `count>1` span for ordinal392. Preserve all semantic assertions, selector394 identity order/names, and exact selector382 prefix. Do not execute runtime, compile, mutate product/tests, promote package118, or perform A3→A4 cutover in TB-PLAN. Product-source change scope is presumptively zero unless planning uncovers contradictory evidence.

## Current evidence

- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §17
- accepted runtime predecessor: package117 / selector382 **382/382**
- candidate compile report: `.agents/Directional/Architecture_M4_CP3_CB2_Code_Build_Report.md`
- raw TB report: `.agents/Directional/Architecture_M4_CP3_TB1_Test_Benchmark_Report.md`
- current review authority: `.agents/Directional/Architecture_M4_CP3_TB1_Review_Record.md`
- regression classification: `.agents/Directional/Regression_Root_Cause_Tracker.md` candidates `M4-CP3-TB1-REV-CAND-01/02`

## Consolidation state

`Architecture_M4_CP3_CB2_Code_Build_Plan.md` was retired after CB2 and is now indexed in `M4_Consolidated_Record.md`. The TB1 plan/report remain retained runtime provenance until a corrected successor supersedes them. No selector, durable policy, closure record, or normative definition is retired.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/TB-PLAN.md
conditional_modules:
  - trigger: unit-test fixture/expectation planning
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector / workflow / patch handling
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_TB1_Review_Record.md
  - .agents/Directional/Regression_Root_Cause_Tracker.md
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md#17-m4-cp3-defn-r1-amendment--baseline-conformity-is-exact-shared-subdivision-plus-region-parity
do_not_preload:
  - Code + Build sibling turn files
  - new runtime work
```

# Future Chat Session Handoff — Directional

**Status:** `M4-CP3-TB1-PLAN` COMPLETE / TEST-ONLY RECOVERY PLAN FROZEN / PACKAGE118 UNPROMOTED / EXACT NEXT `M4-CP3-CB3`
**Repository:** `akashskypatel/Directional`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**PR:** #8, open / draft / unmerged
**Canonical next turn:** `M4-CP3-CB3`, canonical Code + Build / compile-package only

## Current authority

- M1-M3: CLOSED / ACCEPTED.
- M4 package117 / selector382 **382/382** remains latest accepted runtime authority for historical fully framed CP1/CP2.
- Stable regression accounting: **47 events / 14 categories / 33 recurrences**.
- Produced-witness debt: **5**.
- `M4-CP3-DEFN-R1`: current production-baseline definition is `Architecture_M4_DEFN_Frozen_Definitions.md` §17.
- `M4-CP3-CB2`: compile/package green at semantic source `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`; package118 is candidate only.
- `M4-CP3-TB1-EXEC`: complete, immutable postflight green, candidate selector394 measured **387/394** with RED ordinals **386,388,389,390,391,392,394**.
- `M4-CP3-TB1-REV`: complete and independently amended at source `2a3dcd3cbfd4a862262f76efc10fbce975b7c154`; both findings upheld. Five new identities are proved, while 386/388/389/390/391/394 and the breakpoint half of 392 remain unproved.
- `M4-CP3-TB1-PLAN`: complete; authoritative test-only recovery plan is `Architecture_M4_CP3_CB3_Code_Build_Plan.md`. Product-source change scope is frozen to zero.

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

Review independently re-opened raw artifact `10183361985` and exact review-source snapshot `3ec69ffeb88f6378ca8a7a680ef8f3a7e4be64f4` (snapshot run/artifact `34559829994 / 10183917322`, outer SHA-256 `a3bc151e640b5f89ad08825f694ec13c8e59c3518764429babdb4ff7043909fb`, **5250/5250** files verified). No Directional runtime/compile occurred in review. The user-supplied independent verification amendment is commit `2a3dcd3cbfd4a862262f76efc10fbce975b7c154`; this planning turn fetched it through exact source-snapshot run/artifact `34561685590 / 10184536501` (provider SHA-256 `80a69e342574fb5c819c6c9333defe8a1baa96e9dbd54b51b4799950e4ab8f63`, inner `source.tar.gz` SHA-256 `4dde4235047322b41c2abc472f023d67925acb1eb15f7f0931d67b9cc81a6b98`, **5251** files, `runtimeExecution=false`).

1. **`M4-CP3-TB1-REV-CAND-01` — invalid one-face triangle fixture / non-stable.** Ordinals **386,388,389,390,391,394** all call `make_triangle_mesh()`. A one-face triangle is rejected by strict `TriMesh` DCEL consistency because the face has no interior edge, so these tests die before intended baseline semantics.
2. **`M4-CP3-TB1-REV-CAND-02` — invalid count precondition / non-stable.** Ordinal **392** validly builds the square baseline, then assumes `schedule().front().count > 1`. Runtime gives `1`; frozen §17.6 allows the lex-minimal parity flip to map first-span preferred `d=2` to `1`. The breakpoint fixture failed to guarantee its own interior-ordinal precondition.

Both candidates are `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. Stable totals remain **47 / 14 / 33**, debt **5**. Package117/selector382 stays accepted. Package118/selector394 stays immutable candidate evidence and is **not promoted**. Production A3→A4 cutover remains blocked.

## Exact next — `M4-CP3-CB3`

Execute `Architecture_M4_CP3_CB3_Code_Build_Plan.md` as a test-only Code + Build turn. Change only `tests/GlobalConformityBaselineTests.cpp`: replace the invalid one-face helper with the frozen four-vertex/three-face triangular-boundary disk; make ordinal392 independently guarantee `count>1` via target size `0.25` / preferred count `4`; and add success-visible receipts for all seven previously blocked identities, including exhaustive-oracle comparison count, nine tamper rows, and ordinal392 live breakpoint ordinals/denominators. Preserve selector394 bytes/hash and exact selector382 prefix. Compile/package through mandatory GMP workflow only; no runtime, product-source mutation, promotion, or A3→A4 cutover.

## Current evidence

- normative definition: `.agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md` §17
- accepted runtime predecessor: package117 / selector382 **382/382**
- candidate compile report: `.agents/Directional/Architecture_M4_CP3_CB2_Code_Build_Report.md`
- raw TB report: `.agents/Directional/Architecture_M4_CP3_TB1_Test_Benchmark_Report.md`
- current review authority: `.agents/Directional/Architecture_M4_CP3_TB1_Review_Record.md` (including independent §11 amendment)
- authoritative corrective plan: `.agents/Directional/Architecture_M4_CP3_CB3_Code_Build_Plan.md`
- regression classification: `.agents/Directional/Regression_Root_Cause_Tracker.md` candidates `M4-CP3-TB1-REV-CAND-01/02`

## Consolidation state

`Architecture_M4_CP3_CB2_Code_Build_Plan.md` was retired after CB2 and is now indexed in `M4_Consolidated_Record.md`. The TB1 plan/report remain retained runtime provenance until a corrected successor supersedes them. No selector, durable policy, closure record, or normative definition is retired.

## Context Load Plan

```yaml
load_next:
  - turn-based-coding-agent/references/turns/CB.md
conditional_modules:
  - trigger: test-source design/repair is material
    path: turn-based-coding-agent/modules/unit-testing/MODULE.md
  - trigger: GitHub connector / workflow / patch handling
    path: turn-based-coding-agent/modules/github-connector/MODULE.md
deep_references:
  - .agents/Directional/Architecture_M4_CP3_CB3_Code_Build_Plan.md
  - .agents/Directional/Architecture_M4_CP3_TB1_Review_Record.md#11-independent-verification-addendum-reviewing-agent
  - .agents/Directional/Architecture_M4_DEFN_Frozen_Definitions.md#17-m4-cp3-defn-r1-amendment--baseline-conformity-is-exact-shared-subdivision-plus-region-parity
do_not_preload:
  - Test + Benchmark execution turn files
  - historical M4 plans already consolidated
```

# M3-CP4c-3-TB46 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN / EXACT NEXT / ARTIFACT-ONLY
**Turn:** `M3-CP4c-3-TB46-EXEC`
**Authority:** completed `M3-CP4c-3-CB51`
**Immutable package:** package111, artifact `10112532452`
**Exact semantic source:** `4f0663ef3468996abce6f59109f1c67f5be5f604`
**Selector:** `Architecture_M3_CP4c3_Required_Green_Selector_409.txt`, 409 identities, byte-frozen

## 1. Immutable inputs

TB46 consumes only the accepted CB51 package and frozen selector409.

Package111 authority:

- compile run/job: `34372482691 / 102536964376`
- result artifact: `10112532452`
- provider ZIP SHA-256: `62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`
- compile log artifact: `10112533158`
- log provider ZIP SHA-256: `2fc66875001184207e5ab59c8838eb95bca69219143ea53ce56e4b2a0ca315ff`
- packaged source archive SHA-256: `813d375e8ca38e65b01ea54a668cd067033def144eefe2f375b98a1a29ae0c37`
- package root manifest: 28 entries, 28/28 verified, manifest excludes itself
- package metadata source SHA: `4f0663ef3468996abce6f59109f1c67f5be5f604`
- package metadata: `runtimeExecution=false`, `exactArithmeticBackend=GMP`

Selector409 SHA-256:
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.

Before runtime, TB46 must re-verify the downloaded artifact digest, root manifest, source SHA, selector hash and all
six packaged executable identities. Any mismatch is orchestration failure, not a semantic result.

## 2. Artifact-only boundary

TB46 may extract and execute the immutable package. It must not configure, compile, link, regenerate, patch,
repackage, mutate fixtures/selectors/source, or write into the packaged source/input tree.

All mutation/repair flags remain false. Preserve byte+mode censuses of immutable inputs before and after execution.
A mismatch is orchestration failure. No result from a malformed or mutated run is semantic authority.

Do not invoke test discovery/list/help/version commands to choose tests. Use selector409 as the exact execution list.
A zero-selected identity, missing executable, harness mapping failure, timeout or infrastructure failure is
orchestration failure, never PASS/SKIP.

## 3. Exact execution contract

Execute **all 409 selector identities exactly once**, each in a fresh process, in selector order. Map each identity
to the same packaged executable family used by the established CP4c-3 artifact-only harness. Preserve per-ordinal:

- ordinal and exact selector identity;
- selected executable/filter;
- process exit/conclusion;
- raw stdout/stderr;
- timeout/orchestration state;
- stable receipt/diagnostic lines needed by the checks below.

The full suite is not partitioned/retried/stiched to manufacture completion. No expected aggregate PASS/RED count is
frozen by this plan.

## 4. Mandatory semantic measurements

TB46 must report, without speculative repricing:

1. **Accepted prefix:** ordinals 1–365 are **365/365 PASS**.
2. **Ordinal367:** reaches and executes the corrected independent fragment partition/disc oracle. Evidence must show
   the retired unconditional terminal-no-barrier skip is not the controlling rule; terminal separation is decided
   from the independent forward/reverse face-walk orbits.
3. **Protected 390/393/406/407:** each reaches the successful-plan branch, observes non-empty producer frontier
   evidence, executes its real Part XII predicate, rejects its deliberately corrupted same-domain copy, and emits a
   non-vacuous receipt with `terminalSubjectBranch=PlanFrontier`. None may stop on the retired
   `ASSERT_FALSE(plan.has_value())` precondition.
4. **Protected controls:** 311/312/314/315/356/357/404/408/409 remain PASS.
5. **Carried owners:** 368/369/370/374/398 are reported exactly as observed. TB46 does not merge, reassign or reprice
   their owners merely because another identity changes state.
6. **Ownership:** established/unavailable/conflicting remains **300/0/0** unless runtime evidence proves otherwise;
   any change must be reported, not normalized away.
7. **Retired-code silence:** previously retired error/proxy identities remain absent from raw logs.
8. **Controls:** selector count/hash, one-process-per-identity accounting, zero selector mismatch, and immutable
   pre/post byte+mode censuses are recorded.

TB46 must separately record the observed PASS/RED/SKIP aggregate and exact RED ordinal list. This plan intentionally
freezes no expected aggregate.

## 5. Evidence preservation

Preserve immutable result and diagnostic-log artifacts containing at least:

- package111 artifact/digest and semantic source identity;
- selector409 count/hash;
- exact command/harness contract and environment;
- one row per ordinal with process result;
- raw per-identity logs/receipts;
- focused measurements from §4;
- pre/post immutable-input byte+mode censuses;
- timeout, selector-mismatch and harness/orchestration counts.

Do not accept the run if required result/log artifact upload fails.

## 6. Review and routing

After execution, review the evidence before changing any product/test/build source.

- A semantic RED routes to `M3-CP4c-3-TB46-REV` / REVIEW + PLAN; no retry, patch or further CB occurs first.
- An orchestration failure produces no semantic ledger and routes to the bounded CB orchestration-correction edge.
- If the measured gate is green under the checkpoint's frozen acceptance rules, close CP4c-3 according to the
  standing turn workflow.

Stable regression totals are not pre-changed by this plan. Any observed regression must be classified in
`Regression_Root_Cause_Tracker.md` before TB46 closes.

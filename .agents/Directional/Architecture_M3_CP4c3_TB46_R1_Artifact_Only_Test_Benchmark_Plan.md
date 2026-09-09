# M3-CP4c-3-TB46-R1 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN / EXACT NEXT / ARTIFACT-ONLY
**Turn:** `M3-CP4c-3-TB46-R1`
**Authority:** completed runtime-free `M3-CP4c-3-CB52`
**Immutable package:** package111, artifact `10112532452`
**Exact semantic source:** `4f0663ef3468996abce6f59109f1c67f5be5f604`
**Selector:** `Architecture_M3_CP4c3_Required_Green_Selector_409.txt`, 409 identities, byte-frozen

## 1. Retry provenance and immutable inputs

The first TB46 attempt is orchestration-invalid: run/job `34374946991 / 102545334482` executed **0/409** selector
identities and no Directional runtime. It contributes no semantic result.

CB52 subsequently proved the byte-identical generic harness `--preflight-only` path green on package111 in run/job
`34378914278 / 102558671063`. That proof executed no Directional runtime and changed no package/selector bytes.

TB46-R1 consumes only:

- package111 result artifact `10112532452`, name `m3-cp4c3-cb51-package111-result-34372482691`;
- package provider/download SHA-256 `62ae325186ef31d2936e1a797c55cef43f8aef62449b33a26e29cb1ecd9185da`;
- exact semantic source `4f0663ef3468996abce6f59109f1c67f5be5f604`;
- selector409, 409 rows, SHA-256
  `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- generic artifact-only harness SHA-256
  `aaadab351c0ba28a39c87eff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.

Before runtime, re-verify provider/download digest, 28/28 root manifest, source SHA, GMP/GMPXX evidence, selector
count/hash, all six executable identities, identity map and execution-view staging. Any mismatch is orchestration
failure, never a semantic result.

## 2. Corrected caller boundary

The TB46-R1 caller must preserve the CB52 failure-containment correction:

1. presence-only checks for required bootstrap variables; never print `GH_TOKEN` or another secret;
2. verify the frozen harness SHA-256 and `bash -n` before invocation;
3. invoke the generic harness so the caller can explicitly capture the child exit rather than losing evidence to
   caller-level `errexit`;
4. upload harness result and persistent log artifacts under `if: always()`;
5. propagate nonzero status only after evidence-upload steps have had an opportunity to run.

This caller correction does not alter the generic harness, package111, selector409, execution mapping, semantic
measurements or per-identity timeout.

## 3. Artifact-only execution contract

Execute **all 409 selector identities exactly once**, each in a fresh process, in selector order, with
`timeout -k 5s 180s` per identity. Use selector409 as the exact list; do not use generated test discovery to choose
work. Preserve per ordinal the identity, mapped executable, process exit, selection count, raw stdout/stderr,
resource record, timeout state, result and failure-detail digest.

No configure, compile, relink, rebuild, package repair, mode repair, source/test/fixture/selector mutation, fixture
substitution or retry/stitching is permitted. Preserve package/source/execution-view pre/post byte+mode censuses.

The plan freezes **no expected aggregate PASS/RED count**.

## 4. Mandatory semantic measurements

TB46-R1 must report the same unconsumed semantic measurements frozen for TB46:

1. ordinals **1–365 = 365/365 PASS**;
2. ordinal367 reaches and executes the corrected independent fragment partition/disc oracle, with terminal
   separation decided by independently derived forward/reverse face-walk orbit equality;
3. protected 390/393/406/407 each reach the successful-plan `PlanFrontier` branch, observe non-empty producer
   frontier evidence, execute their real Part XII predicate, reject the deliberately corrupted same-domain copy and
   emit non-vacuous receipts;
4. protected controls 311/312/314/315/356/357/404/408/409 remain measured explicitly;
5. carried owners 368/369/370/374/398 are reported exactly as observed, without merge/repricing by adjacency;
6. ownership established/unavailable/conflicting is reported and compared with entering **300/0/0**;
7. retired error/proxy identities remain absent from raw logs;
8. selector count/hash, 409 fresh-process accounting, selection mismatches, timeout count and immutable pre/post
   censuses are recorded.

Record the observed PASS/RED/SKIP aggregate and exact RED ordinal list after execution; do not normalize it to an
expected total.

## 5. Evidence and routing

Result and diagnostic-log artifacts are mandatory. They must bind the package/artifact digest, source, selector,
harness, command boundary, one row per selector ordinal, raw per-identity logs, focused receipts, resource records
and immutable postflight.

- A **semantic RED** routes to `M3-CP4c-3-TB46-R1-REV` / REVIEW + PLAN. No retry or CB occurs first.
- An **orchestration failure** creates no semantic ledger and routes to the bounded CB orchestration-correction edge.
- A valid green gate closes CP4c-3 under the standing turn workflow.

Every observed regression must be categorized in `Regression_Root_Cause_Tracker.md` before this TB closes.

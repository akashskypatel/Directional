# M4-CP-SCALE-TB8-EXEC — Artifact-Only Test + Benchmark Report

**Date:** 2026-09-16 UTC
**State:** COMPLETE / VALID MECHANICALLY RED / FOCUSED S4 PREREQUISITE RED / SELECTOR425 FAIL-FAST UNEXECUTED / IMMUTABLE POSTFLIGHT PASS / REVIEW OWED
**Mandatory successor:** `M4-CP-SCALE-TB8-REV`

## 1. Frozen input authority

The execution consumed the immutable CB9 candidate only. No package/source/test/fixture repair or rebuild occurred.

- Candidate artifact: `10428779988`
- Provider artifact SHA-256: `7470947abba0ca2dc1e8bccd0caba8efdaa53abeaa3b1ae5130a550a3b462bd6`
- Semantic source: `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`
- Packaged source archive SHA-256: `cd0d0c7e084bbf86fbac4086eb076ad987f55d389b5e5c63ec95fcd4724cde55`
- Root package `SHA256SUMS` SHA-256: `e3423161932039366ccf1c4728cab9a3a7115340abd587923be10be3cd7a818b`
- Root package manifest entries: **26**, all verified before and after runtime
- Selector425 SHA-256: `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`
- Selector ownership census: **30 authority-kernel / 279 producer / 75 completion / 41 validation**
- Focused identity: `M4CPScaleS4Prereq.IndependentTopologyOracleIsReachableAndDecisionNeutral`
- Focus owner/binary: producer / `directional_surface_cell_producer_tests`

Accepted M4 runtime authority is **unchanged**: package `10425344367`, semantic source `01b1124af094044e32d6887ff0615881333d12ce`, selector425 **425/425 PASS** from TB7 Review.

## 2. Authoritative execution

- Runtime workflow run: `35053875774`
- Runtime execute job: `104659839191`
- Result artifact: `10430235842`, provider SHA-256 `1728a1f5a2b0c250eb328de4dde78a9076bd77b450cb0e4164e1f92e1b2ac5c8`
- Workflow log artifact: `10430201060`, provider SHA-256 `229b343047c64d2f9259d791fdd4e323ad753e7b0cc549304dd8603bc2fbefbc`
- Nested evidence ZIP SHA-256: `373fd6291ae215606a4f12e47688155277afdfc330111f166b971f68e46df1ce`
- Nested evidence manifest: **29/29 verified**
- Harness exit: `0`; workflow execute job: success

The successful harness/job status means the immutable execution protocol completed and preserved evidence; it does **not** mean the candidate passed the semantic gate.

## 3. Focused S4 prerequisite outcome

The focus process was run first and exactly once as required:

- selected: **1**
- executed: **1**
- passed: **0**
- skipped: **0**
- process exit: **1**
- elapsed: **97 ms**
- mechanical result: **RED**

The first assertion failure is at `tests/FieldAlignedCurveNetworkTests.cpp:14164`:

```text
Expected equality of these values:
  18U
    Which is: 18
  negativeInvariant->vertexCount
    Which is: 48
```

Because the assertion failed before the receipt site, no structured S4 prerequisite receipt was emitted. TB8-EXEC records the observation only. It does **not** adjudicate whether the independent oracle, the production-reachable negative construction, or the expected count is wrong; that semantic determination belongs exclusively to `M4-CP-SCALE-TB8-REV`.

## 4. Fail-fast selector disposition

The frozen plan requires stop-on-first-semantic-anomaly. The focused process was RED, so selector425 did not start.

- Selector processes expected if focus passed: **425**
- Selector processes actually executed: **0**
- Selector rows explicitly recorded UNEXECUTED: **425**
- No selector PASS->RED transition was observed because no selector row ran.

This is correct fail-fast behavior, not an orchestration omission. The accepted TB7 selector425 authority therefore remains unchanged pending Review.

## 5. Immutable postflight

Postflight completed after the focused failure and proved the runtime did not alter the immutable inputs:

- package census equal: `true`
- semantic-source census equal: `true`
- execution-view census equal: `true`
- package manifest reverified: `true`
- semantic source remained `939db1d0bcf7c0d3be8d0960b994c1d53d0a1edf`
- selector remained `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`

The runtime evidence explicitly records all prohibited operations as false:

- configure execution: false
- compile execution: false
- relink execution: false
- repair execution: false
- generated discovery: false
- mutation execution: false
- benchmark execution: false

The candidate binaries were executed directly from the packaged artifact with archived executable modes intact. No rebuild or permission/content repair occurred.

## 6. Mechanical classification and accounting

TB8-EXEC is **VALID MECHANICALLY RED**, not an orchestration failure. The focused S4 prerequisite is the only executed semantic process and fails deterministically at the `18` versus `48` vertex-count assertion. The fail-fast rule then leaves the complete selector425 remainder unexecuted while preserving an exact immutable postflight.

No stable regression/category/recurrence change is authorized by this execution-only turn. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. `M4-CP-SCALE-DEFN-OBS-03` remains **OPEN / REVIEW OWED / NON-STABLE**.

## 7. Required Review handoff

`M4-CP-SCALE-TB8-REV` must independently reopen:

1. candidate artifact `10428779988` and semantic source authority;
2. result/log artifacts `10430235842 / 10430201060` and nested evidence;
3. the focused S4 prerequisite source and its independent topology oracle;
4. the production-reachable empty-cut torus negative construction;
5. the exact `18` expected versus `48` observed vertex-count discrepancy;
6. fail-fast selector non-execution and immutable postflight evidence.

Review decides whether the CB9 prerequisite test authority must be corrected/rejected or can be accepted under a justified interpretation. No S4 production activation, selector426 publication, candidate promotion, or downstream checkpoint advance is authorized before that Review.

## 8. Tool-use ledger note

The execution continued across a session-compaction boundary, so the exact cumulative tool-call ledger for the whole turn is unavailable in memory. Per `TOOL_USE_CONSERVATION_POLICY.md`, the ledger is reported as **partial/unknown rather than reconstructed or guessed**. No tool calls were made solely to reconstruct accounting.

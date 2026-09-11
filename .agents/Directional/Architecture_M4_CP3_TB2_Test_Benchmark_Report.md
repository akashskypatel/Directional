# M4-CP3-TB2 Test + Benchmark Turn Report — package120 artifact-only execution

- Phase: `M4-CP3-TB2-EXEC`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Execution mode: granular `TB-EXEC`, artifact-only
- Validated source commit: `3f909a5a2cfd305d423faf7a260bc465c7b06892`
- Build artifacts: package120 artifact `10280703200`, provider/download ZIP SHA-256 `3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4`
- Test + Benchmark plan reference: `Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md`
- Environment: GitHub Actions `ubuntu-24.04`; runtime used only immutable packaged binaries plus fixture bytes derived from the package-owned source archive
- Execution run/job: `34647838897 / 103422811636`
- Result artifact: `10283220925` (`m4-cp3-tb2-exec-result-34647838897`), provider digest `sha256:314428caf9b240b992f56a48a471e210c0c8361331004d7a0a268ea9fbca4c6f`
- Diagnostic artifact: `10283302336` (`m4-cp3-tb2-exec-log-34647838897`), provider digest `sha256:369889439612977466961821fb8fd082c37fb9da12525c0f74280beafc7a9c4c`

## Plan Execution

- Plan items completed: immutable artifact/source/selector preflight; static owner mapping; focused rows 395-403 pass A; focused rows 395-403 pass B; selector394 compatibility gate; selector403 cumulative gate; immutable package/source/execution-view postflight; raw process evidence preservation.
- Plan items blocked/skipped: none. Performance benchmarking was explicitly not applicable and was not executed.
- Deviations from plan: none material. No semantic retry was performed.
- Stop conditions encountered: none.

Preflight established the exact candidate bytes and authority required by the frozen plan:

```text
artifact ID                  = 10280703200
source SHA                   = 3f909a5a2cfd305d423faf7a260bc465c7b06892
provider/download ZIP digest = 3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4
ZIP bytes                    = 29760920
manifest                     = 28/28
selector403                  = 403 rows
selector403 SHA-256          = e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
selector403 first394 SHA-256 = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector403 first382 SHA-256 = 1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f
```

Static packaged-source ownership resolved every selector identity to exactly one default owner. Selector403 totals were **30 authority-kernel / 257 producer / 75 completion / 41 validation**; selector394 totals were **30 / 248 / 75 / 41**.

## Tests Executed

Exactly the frozen matrix was executed, one fresh GTest process per selector identity with strict single-test selection:

1. focused rows 395-403, pass A: 9 processes;
2. focused rows 395-403, pass B: 9 processes;
3. accepted-prefix selector394: 394 processes;
4. cumulative selector403: 403 processes.

Total semantic runtime processes: **815**.

Every process required exit `0`, exactly one requested `[ RUN      ]`, exactly one matching `[       OK ]`, zero `[  SKIPPED ]`, and no second selected test.

## Test Results

- Passed: **815/815 processes**.
- Failed: **0**.
- Skipped: **0**.
- Selection mismatches: **0**.
- Timeouts: **0**.
- Focused pass A: **9/9 PASS**.
- Focused pass B: **9/9 PASS**; ordered identity/verdict vector matched pass A.
- Accepted-prefix compatibility: **394/394 PASS**, owner totals **30 / 248 / 75 / 41**.
- Cumulative candidate: **403/403 PASS**, owner totals **30 / 257 / 75 / 41**.
- Runtime: process-level elapsed times are preserved in `process-ledger.tsv`; this turn freezes no performance criterion.
- Raw evidence: result artifact `10283220925`; diagnostic artifact `10283302336`.

The result artifact terminal summary records:

```text
preflight_outcome=success
runtime_outcome=success
postflight_outcome=success
expected_processes=815
observed_processes=815
```

## Benchmarks Executed

None. The frozen plan marks benchmarking not applicable for this authority-publication/binding change.

## Benchmark Results

- Baseline: not applicable.
- Current: not applicable.
- Variance: not applicable.
- Correctness/quality: covered by the frozen test matrix, not a performance benchmark.
- Runtime: no benchmark runtime metric frozen.
- Memory: no benchmark memory metric frozen.
- Determinism: focused rows 395-403 repeated once and produced the same ordered PASS vector.
- Evidence: result artifact `10283220925`.

## Immutable Postflight

Postflight re-censused the immutable package tree, extracted package-owned source tree, and disposable execution view and required exact path/mode/size/SHA-256 equality with their pre-execution censuses.

Measured postflight:

```text
package_immutable=PASS
source_immutable=PASS
execution_view_immutable=PASS
manifest_post=28/28
configure=false
compile=false
relink=false
generated_discovery=false
package_repair=false
```

No configure, compile, relink, generated discovery, package permission repair, selector mutation, source/test/fixture mutation, or benchmark execution occurred in TB2-EXEC.

## TB-REVIEW Findings

Not performed in this turn. `M4-CP3-TB2-EXEC` is raw execution/evidence preservation only. Interpretation, regression classification, promotion, and successor authorization belong exclusively to `M4-CP3-TB2-REV`.

Package120 therefore remains **candidate / unpromoted** despite the measured green execution. Accepted runtime authority remains package119 / selector394 **394/394** until independent TB2 review explicitly accepts or rejects package120.

Stable regression accounting remains **47 events / 14 categories / 33 recurrences** and produced-witness debt remains **5**; TB2-EXEC performs no review classification update.

## Phase Status

**Complete — measured green, pending independent TB2 review.**

## TB-PLAN / Proposed Next Code + Build Plan

Status: not applicable in `TB-EXEC`. No corrective Code + Build plan is authored here because no execution blocker occurred and review has not yet adjudicated the candidate.

## Optional Review Decision

- Review: required by the frozen plan.
- Reason: only `M4-CP3-TB2-REV` may interpret this evidence, promote package120, update regression disposition, or authorize a later A3→A4 cutover.

## Granular Summary

- TB-EXEC report/evidence: this report plus artifacts `10283220925` and `10283302336`.
- TB-REVIEW report/findings: pending `M4-CP3-TB2-REV`.
- TB-PLAN report/plan: not reached.

## Live Handoff

- Path: `.agents/Directional/Future_Chat_Session_Handoff.md`
- Evidence commit: this report's durable documentation commit.
- Updated or verified unchanged: candidate source/artifact/selector authority; accepted package119 predecessor; stable regression accounting; produced-witness debt.
- Authoritative or pending plan reference: `Architecture_M4_CP3_TB2_Test_Benchmark_Plan.md` remains the frozen execution authority; review is pending.
- Next canonical turn: Test + Benchmark review boundary.
- Next subturn when granular: **`M4-CP3-TB2-REV` / `TB-REVIEW`**.
- Agent entry-point links verified: handoff and frozen TB2 plan.
- New failure lesson recorded, if any: none; no semantic or orchestration failure occurred.

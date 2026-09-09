# M3-CP4c-3-TB47 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN / EXACT SUCCESSOR / ARTIFACT-ONLY

**EXEC turn:** `M3-CP4c-3-TB47-EXEC`
**Required review boundary:** `M3-CP4c-3-TB47-REV`
**Entering semantic runtime authority:** TB46-R1/package111/selector409 — **403 PASS / 6 RED / 0 SKIP**, accepted
**365/365**, RED `[367,368,369,370,374,398]`
**Stable accounting entering:** **47 events / 14 categories / 33 recurrences**, debt **5**, ownership **300/0/0**,
packages **112**

## Validation Identity

- Phase: `M3-CP4c-3-TB47-EXEC`.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Evidence commit to validate: `c772b53f1c42e117a948f14f77a33ab3dd2619a2`.
- Build artifact: package112 artifact `10119861923`,
  `m3-cp4c3-cb53-package112-result-34391561462`.
- Artifact provider/download SHA-256:
  `3abab0f9d4248c838dc0009d3264fb68ce338a0f20160f7c4b325e28f2c24320`.
- Packaged source archive SHA-256:
  `07955e1be63d35caf335537ca26e83363202a592fcf2542ac7414ec55857e931`.
- Root package manifest: **28/28 PASS** at CB53 closeout.
- Selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt`, exactly 409 non-empty
  rows, SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.
- Generic artifact-only harness: `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`, SHA-256
  `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.
- Accepted-prefix count: 365.
- Planned environment/platform: GitHub Actions `ubuntu-24.04`, artifact-only execution; no configure/build/relink.

## Validation Objective

Validate the one CB53 test-authority correction under the complete unchanged selector409 gate without introducing a
new source, package, selector, fixture, or expected aggregate.

The focused question is whether ordinal367
`GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnProducedWitnesses` can proceed without the retired two-sided
local-fragment/global-owner injectivity rejection. If ordinal367 remains RED, EXEC must preserve its exact new
failure clause/detail and **must not classify it**. `M3-CP4c-3-TB47-REV` owns semantic adjudication.

The full 409 gate is required because CB53 changed a test helper compiled into the producer test binary. Accepted,
protected, control, and carried identities must therefore be observed from the same immutable execution package.
No aggregate PASS/RED count is frozen in advance.

## Preconditions

- Required fixtures/inputs: only fixtures already embedded or source-packaged by package112; no new input may be
  generated or repaired.
- Required selector: exact selector409 bytes and order above.
- Required harness: exact generic harness bytes above.
- Required dependencies/runtime: `bash`, `curl`, `unzip`, `sha256sum`, Python 3, GNU `timeout`, `/usr/bin/time`, and
  the six package112 executable binaries.
- Per-identity control: `timeout -k 5s 180s`.
- Outer elapsed cutoff: **none**.
- Every selector identity runs in one fresh process with `GTEST_FAIL_IF_NO_TEST_SELECTED=1` and `GTEST_COLOR=no`.
- Artifact integrity checks before runtime:
  1. artifact ID/name/provider digest and downloaded ZIP SHA must exactly match the frozen package112 authority;
  2. root `SHA256SUMS` must verify 28/28;
  3. packaged source SHA must equal `c772b53f1c42e117a948f14f77a33ab3dd2619a2`;
  4. build and compile-preflight exits must both be zero;
  5. command boundary must contain `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
     `exactArithmeticBackend=GMP`, `preflightCompile=true`;
  6. GMP/GMPXX evidence must identify both libraries;
  7. all six required executables must exist, be executable, and be hashed;
  8. selector count/hash and harness hash must match;
  9. the harness must derive a unique binary/source owner for every selector identity before runtime.

No chmod/mode repair, binary repair, package repair, source/test/fixture/selector mutation, configure, compile, relink,
generated discovery, or benchmark execution is permitted.

## Ordered Execution Plan

### 1. Direct / Focused Validation

- Command/test: execute the frozen generic artifact-only harness in `--execute` mode against package112 and
  selector409. The harness runs ordinal367 as its normal selector position in a fresh process.
- Purpose: determine the actual post-CB53 behavior of the independently derived fragment partition.
- Expected result: **no aggregate is frozen**. Ordinal367 must no longer be rejected merely because distinct global
  owner count is lower than the local-fragment upper bound. If it is RED, its retained failure detail must expose
  the next actual failing clause or a genuine high-side `FragmentCountRule` over-count.
- Acceptance criterion: exactly one ordinal367 process row, exactly one selected test, no timeout/orchestration
  failure, and a complete raw log/failure-detail digest sufficient for review. A lower-owner-count equality failure
  is a hard falsifier of the CB53 correction.
- Evidence to preserve: ordinal367 raw log, resource record, failure detail/digest, ledger row, and any receipts
  emitted by the test.

### 2. Related Regression Validation

- Command/test: the same single selector409 execution; do not launch a second focused suite.
- Purpose:
  - preserve accepted prefix 1-365 as the primary no-regression gate;
  - observe the explicit out-of-scope ordinal307 equality without editing it;
  - re-observe protected 390/393/406/407 and the established controls;
  - record carried 368/369/370/374/398 without merging or repricing them in EXEC;
  - census retired failure tokens.
- Expected result: accepted prefix remains **365/365**; no expected total aggregate is frozen. Ordinal307 is expected
  to remain within the accepted prefix, but if it fires EXEC records a raw RED and review applies the frozen
  **oracle-drift, not product-regression** disposition rather than silently repairing it.
- Acceptance criterion: all 409 identities have one ledger row and one selected process; no accepted-prefix RED may
  be ignored; protected/control/carry changes are reported exactly as measured.
- Evidence to preserve: complete ledger, identity map, failure-detail table, raw logs, resource records, protected
  receipts, retired-token census, and accepted-prefix summary.

### 3. Integration / Broader Validation

- Command/test: no separate invocation; selector409 is the integration gate.
- Purpose: cover every currently required CP4c-3 selector identity from the same immutable package and source.
- Expected result: mechanical execution completeness, not a predetermined semantic color vector.
- Acceptance criterion:
  - 409/409 identities executed in ordinal order;
  - one fresh process per identity;
  - `selected=1` for every row;
  - timeout count 0;
  - immutable package/source/execution-view postflight censuses equal their preflight censuses.
- Evidence to preserve: `semantic-summary.txt`, `ledger.tsv`, `identity-map.tsv`, all census files, execution-boundary
  record, artifact/selector authority records, executable hashes, and resource summary.

### 4. Full / Platform Validation

- Command/test: the selector409 run is the full platform validation for this test-authority-only change.
- Purpose: prove package112 is executable on the same Ubuntu artifact-only class used by the promoted runtime
  authority without any build-side assistance.
- Expected result: no orchestration fault; semantic REDs, if any, remain raw evidence for review.
- Acceptance criterion: the harness exits successfully after a complete mechanically valid run; `benchmark_execution`,
  `configure_execution`, `compile_execution`, `relink_execution`, `generated_discovery`, `package_repair`,
  `mode_repair`, and `source_test_fixture_selector_mutation` all remain false.
- Evidence to preserve: workflow result/log artifacts plus the full harness result directory.

## Benchmark Plan

- Applicable: **no**.
- Baseline commit/result: TB46-R1/package111 is the semantic runtime comparison authority, but no performance claim
  is evaluated by CB53/TB47.
- Inputs/corpus: selector409 only.
- Repetitions/warmup: one execution per identity, no warmup.
- Correctness/quality criteria: selector integrity, accepted-prefix preservation, exact raw failure evidence, immutable
  postflight.
- Runtime budget: 180 seconds per identity, no outer elapsed cutoff.
- Memory budget: record maximum RSS per identity; no new acceptance threshold is introduced.
- Variance tolerance: not applicable; no benchmark metric is being compared.
- Determinism requirement: one ordinal-ordered fresh process per identity; any nondeterministic semantic difference is
  reported to review rather than rerun until green.

## Unit-Test Design Check

- Contract under test: DEFN-R3.4 permits a non-injective local-fragment -> global-face-walk-owner projection and
  forbids only a distinct-owner over-count above `tracePieces + 1`.
- Scenario/boundary represented: ordinal367's produced witness reaches the independent fragment partition after
  CB51 terminal-separation handling.
- Why fixture values expose plausible broken behavior: TB46-R1 actually reached the stale final cardinality clause;
  the correction is therefore exercised by an observed runtime path, not an invented fixture.
- Isolation/test-double rationale: none added; the helper independently derives forward/reverse face-walk orbits and
  does not query product-owned fragment partitions.
- Assertion semantics: high-side over-count remains a failure; lower distinct-owner count is permitted. The unrelated
  ordinal307 equality is explicitly out of scope and unchanged.

## Stop and Blocker Conditions

Stop execution and preserve all evidence when:

- artifact/source identity does not match this plan;
- artifact provider/download digest or root manifest fails;
- selector or harness count/hash mismatches;
- a required executable is absent or not executable;
- identity-map ownership is not exactly one binary/source per selector row;
- any build/configure/relink/discovery/repair/mutation path attempts to execute;
- selection integrity fails;
- any identity times out;
- source/package/execution-view postflight differs from preflight;
- the harness reports orchestration failure.

A semantic test RED is **not** an orchestration blocker and is not grounds for an EXEC rerun. Complete the mechanically
valid run, preserve the RED evidence, then stop at TB47-REV.

## Plan-Defined Reruns

- Allowed repetitions/retries: none for semantic outcomes. A retry is allowed only after a proven orchestration or
  infrastructure defect, using the **same** package112/source/selector/harness bytes and restarting selector409 at
  ordinal 1.
- Seeds/order permutations: none.
- Nondeterminism investigation: deferred to review; EXEC does not loop until green.

## Completion Criteria

`M3-CP4c-3-TB47-EXEC` is complete when:

- artifact/package/source/selector/harness authority is verified;
- all 409 planned identities have one recorded fresh-process result or an explicit orchestration blocker;
- raw logs, per-identity resources, failure-detail digests, ledger, identity map, semantic summary, boundary record,
  and immutability censuses are preserved;
- EXEC records the exact measured aggregate and RED ordinals without semantic repricing;
- no benchmark/build/repair/mutation path executed;
- the handoff routes **unconditionally to `M3-CP4c-3-TB47-REV`** for independent diagnostic review and planning.

TB47-EXEC must not edit product/test/fixture/selector source, compile a replacement package, alter gate membership,
withdraw a carried owner, or promote its own semantic result.

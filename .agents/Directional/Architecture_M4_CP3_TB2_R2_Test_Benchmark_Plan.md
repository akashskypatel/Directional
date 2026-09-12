# M4-CP3-TB2-R2 Test + Benchmark Plan — artifact-only corrected row400 acceptance gate

**Status:** FROZEN EXECUTION PLAN
**Turn:** `M4-CP3-TB2-R2-EXEC`
**Boundary:** artifact-only Test + Benchmark execution
**Compilation/relink:** forbidden
**Promotion:** forbidden in EXEC; Review owns disposition

## Validation Identity

- Phase: `M4-CP3-TB2-R2-EXEC`.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Evidence commit to validate: `58521f6d1c4fb5d625da7cde50e002cf4688beee`.
- Build artifact: `10289601000`, `m4-cp3-cb4-r4-package-result-34665925501`.
- Artifact provider/ZIP SHA-256: `ef8c0d87f8dc8ed48269f833ec946f52189f7df63bcdf4c5df6c113f098992b9`.
- Artifact size: `29,764,498` bytes.
- Packaged source archive SHA-256: `b8eb7a8352c587353c0aefda93243050a32f5cd123d6ce50e49a7ca9ce0912f0`.
- Package manifest: 28 entries; `SHA256SUMS` SHA-256 `d6d3c5bbad41394177cf4ef7b522cef47660e47b6865eebb98a702df506dc43b`.
- Planned platform: GitHub-hosted Linux runner, executing the immutable packaged binaries directly without configure/build/relink.

Frozen selector authority:

```text
accepted selector394 rows   = 394
accepted selector394 SHA256 = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
successor selector403 rows  = 403
successor selector403 SHA256= c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
successor first394 SHA256   = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
owner partition             = 30 / 257 / 75 / 41
row400                      = EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking
```

Four owner executable SHA-256 values:

```text
authority-kernel 5efacc3ad52085a8ab76bad451bfc70c337e44a73a8f81a165f06ab1cd3041b3
producer         50402382ba9052ee593cad7482bbdbf50da62f52f1f0dac133be27257a9fa056
completion       1701820d85d91fe674cb3dd3496669f0a49ca43e6068a170fb0277227aba094a
validation       303af6ab231bf88b6b618df03315c9999a27595b8b55871922935f5098a4ca5f
```

## Validation Objective

Validate the R3 terminal-contact canonical→raw oriented barycentric correction and its replacement row400 using the corrected immutable package, while re-proving the entire accepted selector394 prefix and cumulative successor selector403.

The defect under recovery is the prior row400 test-authority gap plus the stale packaged-test identity that prevented the corrected candidate from packaging. The Code + Build turn changed no product/test/selector semantics beyond the already reviewed R3 correction; therefore the bounded runtime proof is exactly the focused replacement identity plus predecessor and cumulative selectors.

## Preconditions

- Download artifact `10289601000` once as the immutable package under test.
- Verify the outer artifact/provider SHA-256 and byte size before extraction.
- Verify `sha256sum -c SHA256SUMS` for all 28 package entries before runtime.
- Verify `metadata/source-commit.txt` equals `58521f6d1c4fb5d625da7cde50e002cf4688beee`.
- Verify all recorded source-status files are empty.
- Verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `exactArithmeticBackend=GMP`, and the successful compile/package boundary.
- Verify packaged source archive SHA-256, then extract it read-only for selector/source evidence.
- Re-hash selector394 and selector403 from packaged source; verify first394 byte identity and `30/257/75/41` unique owner mapping before any test process.
- Re-prove row400 exists exactly once in packaged source and is uniquely owned by `directional_surface_cell_producer_tests`.
- Re-open the row400 fixture and independently verify its discriminator remains present: raw oriented source row `[3,0,4]`, canonical key row `[0,3,4]`, canonical weights `[1/6,1/3,1/2]`, locus source vertex `4`, correct remapped secondary parameter `1/3`, wrong positional interpretation `2/3`.
- Record package, source and execution-view censuses before runtime, including modes, sizes and hashes.
- Do not configure, compile, relink, regenerate discovery data, repair package contents, modify selectors or mutate source.

## Ordered Execution Plan

All test invocations use exact `--gtest_filter=<full identity>` and execute **one fresh process per identity**. Each process must select and execute exactly one test. Owner executable is determined from the frozen unique ownership map, not by discovery at runtime.

### 1. Direct / Focused Validation A

- Process count: exactly `1`.
- Test: `EmbeddedGraphTopology.TerminalContactCanonicalBarycentricsRemapToOrientedSourceFaceForVertexRayRanking`.
- Owner: `bin/directional_surface_cell_producer_tests`.
- Purpose: first independent runtime proof of the replacement row400 contract.
- Expected: exit `0`, exactly one selected/executed test, `1/1 PASS`, no skip/timeout.
- Preserve: raw stdout/stderr, exit code, exact command/filter, owner hash, timing and receipt/evidence text if emitted.

### 2. Direct / Focused Validation B

- Process count: exactly `1`, a new process independent of Focused A.
- Same exact row400 identity and owner executable.
- Expected: `1/1 PASS` with no skip/timeout/selection mismatch.
- Additional acceptance: focused A/B verdict and success-visible semantic evidence must agree byte-for-byte wherever the test emits deterministic receipt data.

### 3. Accepted Predecessor Regression Gate

- Process count: exactly `394`.
- Iterate accepted selector394 in frozen file order.
- Execute one fresh exact-filter process for each row on its unique owner executable.
- Expected: `394 PASS / 0 RED`, no skips, timeouts, second-test executions or selection mismatches.
- Preserve an ordinal ledger with selector row, identity, owner, command, exit, verdict and raw-log reference.

### 4. Cumulative Successor Gate

- Process count: exactly `403`.
- Iterate successor selector403 in frozen file order.
- Execute one fresh exact-filter process for each row on its unique owner executable.
- Expected: `403 PASS / 0 RED`; row400 is PASS at successor ordinal 400; owner totals exactly `30 / 257 / 75 / 41`.
- Preserve the same complete ordinal ledger and per-process raw evidence.

### Frozen process census

```text
focused row400 A          1
focused row400 B          1
accepted selector394    394
successor selector403   403
---------------------------
TOTAL                   799 fresh processes
```

No other GTest, benchmark, binary, discovery/listing, `ctest`, help/version or custom-input process is authorized.

## Immutable Postflight

After process 799:

- run `sha256sum -c SHA256SUMS` again and require all 28 entries PASS;
- re-hash package/source/execution-view censuses and require byte identity with preflight;
- verify packaged source, selectors, binaries, metadata, modes and sizes did not change;
- record exact actual process count and first failure, if any.

If a process fails, preserve evidence and apply the stop rules below; do not mutate or repair the package.

## Benchmark Plan

- Applicable: **no**.
- Baseline: n/a; R4 changed build-contract metadata only and the frozen recovery plan defines no performance/resource acceptance metric.
- Benchmark binaries are present only because they are part of the standard package. They must not execute in this turn.

## Unit-Test Design Check

Reference: `modules/unit-testing/MODULE.md`.

- Contract under test: terminal-contact canonical barycentric components must be remapped by source-vertex identity into raw oriented `SourceFaceRecord::vertices` order before vertex-ray ranking consumes them.
- Scenario/boundary: a real fan seam with raw `[3,0,4]` versus canonical `[0,3,4]` and unequal barycentric weights.
- Why fixture values expose plausible broken behavior: correct identity remap yields exact `1/3`; positional misuse yields `2/3`, so the former bug cannot pass accidentally.
- Isolation rationale: row400 exercises the bounded terminal-contact basis contract while selector gates guard predecessor/cumulative integration.
- Assertion semantics: exact arithmetic result and independently derived wrong-basis discriminator; no positivity/sum-only ordering surrogate is sufficient.

## Stop and Blocker Conditions

Stop execution and preserve evidence immediately when:

- artifact ID, outer digest, byte size, source commit or source archive digest differs;
- any of 28 manifest entries fails before runtime;
- selector394/selector403 bytes, row counts, first394 prefix or owner partition differ;
- row400 is absent, duplicated, renamed, not producer-owned, or its independent `1/3` versus `2/3` discriminator cannot be re-derived from packaged source;
- any planned process selects zero or more than one test;
- any planned process is RED, SKIP, times out, crashes or has a selection mismatch;
- package/source/execution-view mutates;
- continuing would require configure, compile, relink, package repair, selector/source mutation or an unplanned runtime.

On any semantic RED, do **not** continue merely to accumulate failures unless the frozen harness can safely preserve already planned independent evidence without obscuring the first failure. Record the first failure and terminate according to project TB policy.

## Plan-Defined Reruns

- Planned repeated validation is only the explicit focused A/B pair already included in the 799-process census.
- No ad-hoc retries of a deterministic failure.
- No seeds/order permutations beyond frozen selector order.
- Suspected orchestration failure may be retried only after preserving evidence and proving no semantic process started; any correction must remain harness-only and leave package/source/selectors immutable.

## Completion Criteria

`M4-CP3-TB2-R2-EXEC` is complete when:

- preflight artifact/source/selector/owner checks are green;
- exactly 799 fresh processes reach their organic planned outcomes or the run stops at a frozen blocker with complete evidence;
- focused A and B each record `1/1 PASS` for row400;
- selector394 records `394/394 PASS`;
- selector403 records `403/403 PASS` with owner partition `30/257/75/41`;
- immutable postflight is green;
- raw per-process and summary evidence is preserved sufficiently for `M4-CP3-TB2-R2-REV` to re-derive every decisive claim without reconstructing intent from chat context.

Even a fully green EXEC does not promote the candidate. Exact successor after EXEC is **`M4-CP3-TB2-R2-REV`**.

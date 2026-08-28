# M3-CP4c-1 CB3 Artifact-Only Test + Benchmark Plan

## Validation Identity

- Phase: `M3-CP4c-1-TB-R4`
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`
- Evidence commit to validate: `66a065b5e07910568a317e24f0fc6b93d890d104`
- Build artifact: `9673249952` (`m3-cp4c1-cb3-compile-result-33139188595`)
- GitHub artifact digest: `sha256:17a3f8da793fc20562e5ec2f0ab441d39f795dd146171e989fb952e6f942d2ea`
- Compile log artifact: `9673250286`, digest `sha256:cffa6fc4a72c0d60fa2199131cdd6073c7a8c7f15482a0e48af98cb3dadf32b9`
- Exact arithmetic backend: GMP
- Required selector: `.agents/Directional/Architecture_M3_CP4c1_Required_Green_Selector.txt`, **355**, SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- Non-gating selector: `.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt`, **5**, SHA-256 `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`
- Planned environment/platform: GitHub-hosted Ubuntu runner, artifact-only execution from the immutable package; no configure/build/relink

## Validation Objective

Prove that CP4c-1 can close on current accepted authority without rewriting any accepted contract.

The next TB must establish all of the following in one immutable artifact-only authority:

1. the already accepted CP4c-0b selector remains an exact ordered **353/353 green prefix**;
2. C4 and C5, now ordinals **354/355**, are both green without re-authoring;
3. the five historical CP4c-1 diagnostics execute as report-only/non-gating observations with zero gate credit;
4. the package and extracted source remain byte/mode immutable before and after runtime.

The expected semantic result is **355/355 required green**. If C4 or C5 is red, that is a valid CP4c-1 semantic red, not permission to weaken or demote the identity. If any of the first 353 is red, it is an accepted-authority regression.

## Preconditions

Before executing any Directional binary:

- download exact artifact `9673249952`;
- verify the artifact identity/digest exposed by GitHub matches the frozen reference above;
- verify all **28** entries in `SHA256SUMS`;
- verify `metadata/source-commit.txt` equals `66a065b5e07910568a317e24f0fc6b93d890d104`;
- verify `metadata/preflight-exit-code.txt == 0` and `metadata/build-exit-code.txt == 0`;
- verify every packaged source-status snapshot is empty;
- verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- verify GMP/GMPXX runtime dependencies needed by the packaged test binaries are present;
- extract `source/source-66a065b5e07910568a317e24f0fc6b93d890d104.tar.gz` and verify its SHA-256 is `3ba7e745a25dddbacd0e18b79672ebac5a8e94a944ed45c60174216f2770c628`;
- verify the packaged required selector is exactly **355 lines** with SHA-256 `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`;
- verify its first 353 lines hash to `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`;
- verify its first 346 lines hash to `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- verify its first 316 lines hash to `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- verify ordinals 354/355 are exactly C4/C5:
  - `FieldAlignedCurveNetwork.RejectsTamperedTraceIntersectionCrossing`
  - `FieldAlignedCurveNetwork.EveryTraceTerminatesAtATypedEventKindThatIsActuallyProduced`
- verify the five-line non-gating selector hashes to `9f4f287e074d66da9d69c16e22320ed6fe161b6b09de4dc7dd0618741c7fb130`.

Capture a pre-runtime byte-and-mode inventory of the package, extracted source, fixtures, both selectors, and executable files. A mismatch is a blocker, never a reason to rebuild.

## Ordered Execution Plan

### 1. Required 355-identity gate

Execute the required selector in exact file order, **one identity per fresh process** against the packaged binaries. Do not use generated discovery to decide what to run; the selector is authority.

For each ordinal, the harness must:

- route the exact `Suite.Test` identity to the packaged test executable that owns it;
- execute with a filter that can select only that exact identity;
- verify exactly one test was selected; zero-selected is orchestration failure;
- capture exit status, elapsed time, stdout/stderr, and any `C++ exception with description`;
- record PASS/RED without rewriting expected output.

Preserve an ordered ledger containing ordinal, identity, owning executable, selected count, exit code, elapsed time, and result.

Required acceptance:

- ordinals 1–316: **316/316 PASS**;
- ordinals 1–346: **346/346 PASS**;
- ordinals 1–353: **353/353 PASS**;
- ordinals 354–355: **C4 1/1 PASS and C5 1/1 PASS**;
- full selector: **355/355 PASS**;
- `zeroSelected=0`;
- escaping C++ exceptions: **0**;
- first red ordinal: **none**.

If any required identity is red, preserve the exact first-red evidence. Do not edit expectations, selectors, fixtures, or product code inside TB.

### 2. Five non-gating CP4c-1 diagnostics

Execute each identity in `.agents/Directional/Architecture_M3_CP4c1_Non_Gating_Diagnostic_Selector.txt` once in a fresh process and report it separately from the gate.

These identities are historical observation surfaces. Several intentionally terminate with diagnostic failure output, and predecessor work has invalidated some old failure preconditions. Therefore:

- they contribute **zero gate credit** regardless of PASS/RED;
- do not rewrite them inside TB to manufacture green;
- record exact selected count, exit code, elapsed time, and emitted report/failure text;
- classify whether each result is consistent with current CP4c-0/0b accepted behavior;
- a zero-selected or infrastructure-invalid execution is still orchestration failure and must be corrected before the TB can be durably closed.

No non-gating result may be used to demote C4/C5 or weaken the 355 gate.

### 3. CP4c-1 semantic review from the immutable results

Without changing code:

- verify C4 selected an **actually produced terminal `TraceIntersection`** before tampering its incidence and that the tampered candidate was rejected with `InvalidNetworkEventIncidence`;
- verify C5 observed exactly the required terminal event-kind set, including both `TraceIntersection` and `MandatoryBarrierTermination`;
- preserve the sphere/two-ring/fan contributor diagnostics emitted on failure if either identity is red;
- compare the result against predecessor T5 authority only as provenance: predecessor acceptance is 353/353, not a substitute for executing C4/C5.

This step is evidence interpretation only; it does not authorize a new build.

### 4. Immutable postflight

After all planned runtime:

- recompute package and extracted-source byte-and-mode inventories;
- verify `SHA256SUMS` still passes 28/28;
- verify required/non-gating selector bytes and hashes are unchanged;
- verify fixtures and executable bytes/modes are unchanged;
- record `configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`, and `mutationOccurred=false`.

Postflight mismatch invalidates acceptance.

## Benchmark Plan

- Applicable: **no performance acceptance benchmark**.
- Timing is evidence-only. Preserve per-identity elapsed times so regressions such as prior non-terminating traces remain observable.
- Do not impose a repository/job timeout whose purpose is to terminate the complete required semantic suite. Platform service limits are infrastructure constraints, not semantic results.
- Do not split, stitch, or retry partial required-gate results to manufacture one green acceptance run.

## Unit-Test Design Check

No new unit-test source is authored in TB. The two checkpoint-local required contracts are already frozen:

- C4: terminal `TraceIntersection` is genuinely produced, then a tampered terminal/interior incidence is rejected.
- C5: every trace terminates at an actually produced typed terminal event kind, with both `TraceIntersection` and `MandatoryBarrierTermination` non-vacuously represented.

The next turn validates those existing contracts; it does not redesign them.

## Stop and Blocker Conditions

Stop and preserve evidence when:

- artifact/source identity or any frozen checksum/prefix hash is wrong;
- GMP/GMPXX runtime support required by the packaged binaries is unavailable;
- a planned identity selects zero tests;
- the package/source/fixture/selector inventory changes;
- the workflow attempts configure, compile, relink, regeneration, repair, or semantic mutation;
- a platform/infrastructure failure prevents a trustworthy result.

Semantic red is not infrastructure failure. If an identity executes correctly and fails its assertion, record the red and complete only the remaining evidence collection that does not risk corrupting provenance.

## Plan-Defined Reruns

- Do not rerun a deterministic semantic red unchanged merely to seek green.
- An orchestration-only retry is permitted only after diagnosing and correcting the control-plane defect, with the package/source/selectors byte-identical.
- If a run starts runtime and fails due orchestration, retain that attempt as non-semantic control evidence and identify exactly which planned identities did or did not execute.
- Never compile a replacement revision inside TB.

## Completion Criteria

TB-R4 is complete when:

- exact immutable artifact preflight is green;
- every required identity has a trustworthy result or the turn has a documented blocker;
- all five non-gating diagnostics have trustworthy report-only results or a documented blocker;
- immutable postflight is green;
- raw result/log artifacts are preserved with run/job/artifact IDs and digests;
- every observed regression/candidate is classified in `Regression_Root_Cause_Tracker.md` before closeout;
- the result is adjudicated without changing product/test/fixture/selector/build semantics.

Checkpoint closure requires **355/355 required green**, including accepted **353/353**, C4, and C5. On that result CP4c-1 may close and the following planning checkpoint is `M3-CP4c-2-DEFN`. Any valid semantic red leaves CP4c-1 open.

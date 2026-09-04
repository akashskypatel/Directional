# M3-CP4c-3-CB29 — TB25 Orchestration Correction Code + Build Report

**Turn:** `M3-CP4c-3-CB29`
**Verdict:** **COMPLETE / CONTROL PROOF GREEN / RUNTIME NOT EXECUTED / SEMANTIC AUTHORITY UNCHANGED**
**Date:** 2026-09-04

## Scope and authority

CB29 is the user-authorized orchestration-correction `CB` following the pre-runtime-invalid first TB25 attempt. It
owns only `M3-CP4c3-TB25-ORCH-01`. No Directional product source, test, fixture, selector, CMake/build semantics, or
immutable package byte was changed. No configure, compile, relink, repackage, executable-mode repair, Directional
test, benchmark, generated binary, `ctest`, CLI, fuzzer, help/version command, or custom runtime input was executed.

The immutable product/runtime candidate remains CB28 artifact **`9950303110`**, SHA-256
`84c9cd0bdf5d8bef2288e1ca57d52bcec8d1503f368d82101ae10cfa14c49189`, semantic source
`3d7f7f9a3afad3ed37fc615a206801cf6310f4ac`, selector 403 with 403 identities and LF SHA-256
`60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`.

## Invalid-attempt provenance retained

The first `M3-CP4c-3-TB25-EXEC` attempt remains invalid provenance, not semantic evidence:

- run/job `33910913448 / 101146905061`;
- schema validation succeeded;
- materialization failed with exact message `selector injection point missing`;
- `Execute immutable TB25 gate` was skipped; **0/403** identities ran and `ledger_available=false`;
- result artifact `9951314815`, SHA-256
  `e573a591dddbf49e4624cc99bc01c781acb56b5e086b06c33b525c7a4e7a69ac`;
- log artifact `9951315281`, SHA-256
  `2eb0dd521df88fe1baec5608e981c4744f266c2a4c2fed3dab8d601ac06a9c92`.

The defect was exactly the tracker finding: the historical TB24 shell body was left-shifted by ten YAML indentation
columns, then an insertion anchor requiring twelve leading spaces was searched in the transformed body.

## Correction

CB29 removes that indentation-sensitive insertion contract. The corrected control has two independently verifiable
pre-runtime pieces:

1. **Standalone TB25 harness materialization.** The proven TB24 execution body from commit
   `0624b916dfa16aa47751bd4f40b75bcf5bd76b5a`, blob
   `44b1ad0e7934be2662c1ea326f70baa3537a5977`, is extracted once and transformed only by the frozen TB25 deltas:
   selector 397→401, selector 401→403, TB24→TB25, new-witness threshold 398→402, and class label
   `new-cb27-witness`→`new-cb28-witness`. There is no selector-authority text injection after indentation removal.
2. **Separate selector-authority preflight.** Before any future Directional runtime, the immutable CB28 package is
   independently checked for provider/outer digest, internal manifest, exact semantic source, `runtimeExecution=false`,
   GMP authority, selector-365/401/403 hashes and counts, selector 365 as the exact first 365 lines of 403, and selector
   401 as the exact first 401 lines of 403.

This representation makes the previous failure mode impossible without weakening any frozen runtime requirement.
Selector 365 remains a mandatory accepted-prefix check; it is moved to an explicit pre-runtime authority proof rather
than injected into generated shell text.

## Remote pre-runtime proof

Temporary proof caller install commit: `973a68eac307164eb7eba97147a5e836dd538336`. Trigger commit:
`78beea42c4753a060a0857685ccf0f893d246b78`.

Workflow run **`33915621191`**, proof job **`101162027243`**, completed **SUCCESS**. Schema validation also completed
SUCCESS before the proof workload.

- proof result artifact: **`9953038617`**, SHA-256
  **`f1216938b3d543d4d3fcb498279b1ce432feac008ec240afbf9ae18b1fbe31cf`**;
- proof diagnostic-log artifact: **`9953039237`**, SHA-256
  **`5c2a3900e7d225e52651ced15edf6be0a0c320caf4c76aa247f06ec04dc17ac9`**;
- historical YAML SHA-256: `976394ddce270de22fa4d92e0f60940e8fbb045198d37de942c8737a82892dbc`;
- materialized TB25 harness SHA-256:
  **`13ec524fa0fe609949b147ab36bf710392244b8202684ece2eea10eb5c83e0e9`**;
- standalone harness `bash -n`: PASS;
- `package_authority_valid=true`;
- `selector365_exact_prefix_of_403=true`;
- `selector401_exact_prefix_of_403=true`;
- `pre_runtime_harness_valid=true`;
- `runtime_started=false`;
- `directional_runtime_invocations=0`.

The proof downloaded and verified artifact `9950303110` but invoked no executable from it. It therefore establishes
only control-plane readiness, not semantic runtime behavior.

### Closeout transport provenance

The first documentation-apply attempt, run/job `33916327274 / 101164286424`, verified the staged patch bytes and
base successfully, then failed before commit because the patch metadata encoded six `intended_paths` with commas
while the durable Drive reusable consumes semicolon-delimited paths. The changed-path comparison therefore treated
the six paths as one literal string and failed closed. No repository documentation commit, Drive retirement,
Directional runtime, or semantic evidence resulted. The patch metadata delimiter was corrected before retry; the
diff body and intended documentation edits were not relaxed.

## Acceptance and accounting

CB29 adds no semantic runtime evidence and no semantic package. Latest valid semantic runtime remains
`M3-CP4c-3-TB24-EXEC`: **389 PASS / 12 RED**, accepted **365/365**, RED ordinals
`366,367,368,369,370,374,384,385,389,390,393,398`. Stable regression accounting remains
**44 events / 14 categories / 30 recurrences**, produced-witness debt remains **5**, semantic M3 package count remains
**90**, and CP4c-3 remains **OPEN**.

`M3-CP4c3-TB25-ORCH-01` is now **CONTROL FIX PROVED / AWAITING RE-EXECUTION / NON-STABLE**. It is not closed by
CB29 alone: falsification requires a fresh TB25 attempt to pass corrected preflight and begin the unchanged selector
403 gate from ordinal 1.

## Exact successor

**`M3-CP4c-3-TB25-R1`** — fresh artifact-only re-execution of immutable artifact `9950303110` against selector 403
under the **unchanged** `Architecture_M3_CP4c3_TB25_Artifact_Only_Test_Benchmark_Plan.md`. Reuse the CB29-proved
pre-runtime representation and exact harness SHA above. TB25-R1 may not rebuild, reconfigure, relink, repair, mutate
source/tests/fixtures/selectors/package bytes, or substitute a replacement package. Interpretation and semantic
adjudication still belong to the subsequent independent review if the runtime is RED.

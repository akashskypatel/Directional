# M4-CP3-TB6 Artifact-Only Test + Benchmark Plan — A4 cut-open occurrence recovery

**Turn:** `M4-CP3-TB6-EXEC`
**Status:** FROZEN BY `M4-CP3-CB8` / NOT STARTED
**Turn type:** Test + Benchmark / immutable artifact-only
**Candidate semantic source:** `6934d9edfb56b44f956fbc64a89a501aaed042af`
**Candidate package:** artifact `10303165017`, provider SHA-256 `d601e5efc4d6a3cafc34d4a5ead0a5a44040e3026d31b3f75afad59c71b68112`
**Entering accepted runtime authority:** R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**
**Candidate selector408:** `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` / unpromoted
**Mandatory successor:** `M4-CP3-TB6-REV`

## 1. Immutable package authority

TB6 consumes artifact `10303165017` directly. No repository checkout may substitute for packaged source or executables. Before any generated Directional runtime:

- verify provider/download identity and preserve the downloaded bytes;
- verify all **28/28** root `SHA256SUMS` entries;
- verify `metadata/source-commit.txt` is exactly `6934d9edfb56b44f956fbc64a89a501aaed042af`;
- verify source archive SHA-256 `7b906b0ad1560d3cb158178ae224d2d391e8fee66d7268f78ba2ed172a0ec5eb`;
- verify all packaged source-status snapshots are empty;
- verify compile metadata states `exactArithmeticBackend=GMP` and `runtimeExecution=false`;
- verify the expected packaged executables/archives exist and are executable where applicable;
- materialize one fresh execution view from the immutable package without changing package bytes;
- record complete package and execution-view byte+mode censuses before runtime.

Forbidden: configure, compile, relink, build-system generation, package repair, generated discovery regeneration, source/test/fixture mutation, selector mutation, symlink repair, or substitution of host/repository files.

## 2. Frozen selector and owner authority

Before semantic bodies execute:

```text
selector403 rows/hash = 403 / c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector408 rows/hash = 408 / c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484
first403 = byte-identical selector403
owners = 30 authority-kernel / 262 producer / 75 completion / 41 validation
row408 = producer-owned
```

Any row count/hash/prefix/owner drift is orchestration RED and stops before semantic execution.

Every selector identity must run in its own fresh exact-filter process. Each process must select **exactly one** GTest identity. Zero or multiple selected identities, timeout, crash, abnormal termination, or skipped identity is RED. Do not use aggregate wildcard invocations as acceptance evidence.

## 3. Focused A4 recovery gate — first and fail-fast

Run the exact identity below **twice**, each in a fresh process:

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

Both runs must select exactly one identity and PASS. The test's frozen assertions must continue to establish:

- exact effective `HardFeature` authority equals the 18-edge two-generator torus cut graph;
- A1/A2a/A2b/A3 products and accepted topology/baseline receipts remain present;
- A4 phase-front disposition is `Produced`;
- hard-rail phase-front edges carry exact `sharedBoundaryInterval`;
- at least one exact shared hard interval is present;
- terminal detail is not `InvalidHardRailPairing`.

The two runs are the recovery discriminator for CB8's occurrence-domain change. Any RED/SKIP/crash/timeout/selection mismatch stops TB6 immediately. Do not spend rows404-407 or cumulative selector processes after a focused failure.

## 4. Cumulative gate — only after focused 2/2 GREEN

Run rows404-407 twice, in frozen selector order, fresh exact-filter process per identity. All **8/8** must PASS.

Then run the accepted selector403 as **403 fresh exact-filter processes** and require **403/403 PASS**. This re-proves the reviewed accepted prefix inside the candidate package without changing accepted authority.

Then run candidate selector408 as **408 fresh exact-filter processes** and require **408/408 PASS**.

The complete gate is therefore exactly:

- 2 focused row408 recovery processes;
- 8 rows404-407 repetition processes;
- 403 accepted-prefix processes;
- 408 candidate-selector processes;
- **821 fresh processes total**.

Use the same fail-fast discipline as TB5. Stop at the first semantic RED/SKIP/crash/timeout/selection mismatch and preserve that earliest actual seam. Do not repair or rerun around it in EXEC.

## 5. Immutable postflight

Postflight is mandatory whether the gate is GREEN or fail-fast RED. Recompute and compare against preflight:

- package byte+mode census;
- packaged source byte+mode census;
- execution-view byte+mode census;
- selector403/408 bytes and hashes;
- packaged source commit and source archive hash.

No difference is allowed. Record `runtimeMutation=false`, `sourceMutation=false`, `packageMutation=false`, `buildInvocation=false`.

## 6. Evidence and disposition

Package one TB6 result artifact and one diagnostic log artifact containing at minimum:

- immutable package/source/selector authority;
- exact process order and per-process selected-count/exit/verdict;
- focused row408 2/2 evidence;
- rows404-407 evidence if reached;
- selector403 and selector408 totals if reached;
- earliest failure seam when fail-fast stops;
- immutable pre/postflight comparison;
- explicit no-build/no-repair/no-source-mutation statement.

EXEC does **not** promote the package, alter stable regression accounting, close `M4-CP3-TB5-REV-CAND-01`, close CP3/`G4-B002`, or amend M4 definitions. Those decisions belong only to `M4-CP3-TB6-REV`. If TB6 is GREEN, Review must independently re-open the evidence before promotion. If TB6 is RED, Review must classify the observed candidate/non-stable or stable regression surface before any successor Code + Build is authorized.

# M3-CP4c-3-TB28-R3 — Artifact-Only Control Test + Benchmark Plan

**Turn:** `M3-CP4c-3-TB28-R3`
**Boundary:** Test + Benchmark only; artifact-only runtime.
**Immutable evidence source:** `098ac7d93ea203222dd0ac50cdb68667744f0fd4`
**Immutable package:** artifact `9975737868` (`m3-cp4c3-cb32-compile-result-33987769718`)
**Package ZIP SHA-256:** `16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`
**Selector:** 407 identities, LF SHA-256 `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`
**Execution harness:** `.agents/Directional/tools/m3_cp4c3_tb28_r3_harness.sh --execute`
**Authority:** CM7–CM9 of `Architecture_M3_CP4c3_TB28_Independent_Review_Record.md`.

## 1. Purpose and credibility gate

TB28-R3 is a **control re-execution** of the unchanged CB32 package after CB33 repairs only the runtime harness.
It does not retest a product correction and it does not grant semantic credit to TB28-R1 or TB28-R2.

The latest valid semantic runtime authority before R3 remains `M3-CP4c-3-TB27-R1`: selector 406,
**399 PASS / 7 RED**, accepted prefix **365/365**, RED ordinals
`[366,367,368,369,370,374,398]`.

R3 is credible only if the unchanged product reproduces the three known control REDs **366, 367, and 398**.
If any of those three is reported PASS while selection integrity is otherwise valid, stop the current correction
sequence: do not apply CB34. Replace the runtime harness wholesale with the already-proven
`.agents/Directional/tools/m3_cp4c3_tb23_r1_harness.sh` architecture before another semantic attempt.

## 2. Hard prohibitions

The R3 execution must not:

- configure, compile, relink, rebuild, or repackage Directional;
- repair executable modes or mutate package bytes;
- run generated discovery, `--gtest_list_tests`, `ctest`, or a replacement selector;
- change source, test, fixture, benchmark, build, or selector bytes;
- change any accepted identity 1–365 or selector 397/401/403/405/406/407;
- rerun a semantic RED to obtain a cleaner result;
- widen or narrow selector 407;
- execute `directional_benchmarks`;
- quote TB28-R2's reported `407 PASS / 0 RED` as semantic evidence;
- introduce a fourth source-face-ownership diagnostic or alter the product correction frozen by independent review.

An orchestration failure is not semantic evidence and may be retried only after preserving the first actionable
failure and correcting the harness/control plane without changing semantic bytes.

## 3. Immutable preflight

Run the CB33 harness in a fresh GitHub Actions runtime workspace. The harness must finish all preflight checks before
starting a Directional process.

### 3.1 Package authority

Require exactly:

- artifact ID `9975737868`;
- artifact name `m3-cp4c3-cb32-compile-result-33987769718`;
- provider/download ZIP digest
  `sha256:16190a2da150d1e170dbbaa8df8d51437aabdb77e6a54aeab547e0dc0c4d84ec`;
- root `SHA256SUMS` verification PASS;
- packaged source `098ac7d93ea203222dd0ac50cdb68667744f0fd4`;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `preflightCompile=true`, and
  `exactArithmeticBackend=GMP` in package evidence.

Extraction must preserve archived executable modes. Do not use Python `zipfile.extractall` or any mode repair.

### 3.2 Runtime executable authority

Record SHA-256, Unix mode, and size for **every packaged runtime executable**, not merely the binary that happens to
run the first row. At minimum the CB32 package contains:

- `directional_benchmarks`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_validation_tests`.

The benchmark executable is recorded but is not executed.

### 3.3 Selector and identity map authority

Verify LF-normalized selector hashes and exact prefix relationships:

- 365 prefix SHA `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`;
- selector397 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`;
- selector401 `0d0857a97158dfd0763b536718c24ba257417866aad3d8e51d6f0093be5a5869`;
- selector403 `60ff6daa0e1dc71fe9c856ee9559d665628b756ed634f70ffce5881ec2514007`;
- selector405 `615370b65e590dadb59d7a233c6ce74b7dc8cb46a1f40fd3ea5a44257583aae7`;
- selector406 `efd8f9c764316c87c12ce6400d9a0160a682ca185dec1340fa04b7130df80ac0`;
- selector407 `9e5b7c62901b694399b215bc02a5ade09f3466795b20181c42a039a32f9718ae`.

Construct the identity-to-binary map **statically** from packaged source by parsing selector407,
`cmake/DirectionalTests.cmake`, and `TEST*` declarations. Require exactly one compiled owner for every one of the
407 identities. Publish the full map and its SHA-256. Do not execute a Directional binary to discover tests.

### 3.4 Execution view and censuses

Create a separate execution view from immutable package/source bytes so executable-relative fixtures resolve using
the frozen consumer rule in `tests/TestFixturePaths.h`. Copying immutable bytes into this disposable runtime view is
allowed; editing, chmod repair, regeneration, or fixture substitution is not.

Before runtime, publish byte+mode censuses for:

1. immutable package tree;
2. extracted immutable packaged source tree;
3. execution-view tree.

All mutation/boundary flags must begin false: configure, compile, relink, generated discovery, package repair,
mode repair, source/test/fixture/selector mutation, and benchmark execution.

Any failure in sections 3.1–3.4 sets `runtime_started=false`, preserves evidence, and terminates as orchestration
failure.

## 4. Runtime execution contract

Execute selector407 in its frozen order, **one identity per fresh process and fresh working directory**. For each
ordinal, route through the static identity map and invoke the assigned test executable with:

```sh
env GTEST_FAIL_IF_NO_TEST_SELECTED=1 GTEST_COLOR=no \
  "$EXEC_VIEW/bin/$binary" --gtest_filter="$identity"
```

The CB33 harness additionally retains the existing focused per-process timeout of 180 seconds and records
`/usr/bin/time -v` resource evidence. A timeout is orchestration failure, not semantic RED/PASS evidence.

### 4.1 Selection proof

For every row record the count of GoogleTest `[ RUN ]` entries. The required selected count is exactly **1**.

- `selected == 1 && exit == 0` -> PASS;
- `selected == 1 && exit != 0` -> RED;
- `selected != 1` -> **orchestration-invalid row and RED; never PASS**, regardless of exit code.

A zero-selected GoogleTest invocation returning exit 0 must therefore remain impossible to misclassify as green.

### 4.2 Complete execution

Do not stop at the first semantic RED. Execute all 407 rows once so the later publication identities are retained.
No semantic retry is allowed.

## 5. Required evidence products

The run must publish a complete ordered ledger with exactly:

`ordinal, identity, binary, exit, selected, result, raw_log`.

Require ordinals 1..407 with no gaps or duplicates. Preserve and hash:

- `ledger.tsv` and ledger SHA-256;
- full `identity-map.tsv` and SHA-256;
- all 407 per-ordinal raw logs;
- `runtime-executables.tsv` with SHA-256/mode/size for all runtime executables;
- semantic summary: total PASS/RED, RED ordinal list, selection-mismatch list;
- accepted-prefix result for ordinals 1–365 and any RED ordinals in that prefix;
- explicit control result for 366/367/398;
- raw-log index and raw evidence for 366, 367, 398, 404, 406, and 407;
- per-process resource logs and resource summary;
- pre/post package, packaged-source, and execution-view censuses;
- execution-boundary flags proving no configure/compile/relink/discovery/repair/benchmark/mutation occurred;
- invalid-attempt provenance for TB28-R1 and TB28-R2.

Postflight must show all three byte+mode censuses unchanged.

## 6. Semantic interpretation and mandatory diagnostic census

Only after selection integrity and postflight immutability are proven may the row results be interpreted.

### 6.1 Control gate

First inspect 366, 367, and 398.

- If all three are RED, the R3 harness control is credible and the remaining rows may be reviewed semantically.
- If any is PASS, classify the run as harness-control failure despite any apparently green total. Do not authorize
  CB34; replace the harness wholesale as required by independent review.

### 6.2 Accepted prefix

Ordinals 1–365 are the accepted prefix. Report the exact count independently. Any RED in this prefix is an accepted
regression and must be entered in `Regression_Root_Cause_Tracker.md` before TB28-R3 closes.

### 6.3 Source-face ownership publication

For the ownership diagnosis, publish/adjudicate the census for the **191-face failing component** named by the valid
TB27 evidence. Do not substitute an incidental 27-face `ReliefTopologyBuildFailed` candidate or whichever object
happens to fail first.

For every relevant separating interior arc, retain:

- arc identity;
- forward/reverse face-walk orbit;
- crossed source faces;
- source-face component attribution under the certifier and failing-plan partitions;
- trace-cut state and typed exclusion reason;
- truncation state;
- complete component/domain/face-set identities needed to compare the 191-face object.

TB28-R3 does not choose a new product correction. The separating-arc barrier rule is already frozen by independent
review.

## 7. TB-EXEC / TB-REV split

### TB28-R3-EXEC

Runtime execution only. Consume the immutable package and this plan exactly, preserve raw artifacts, and do not
interpret or repair semantic failures beyond the mechanical integrity checks required to know whether the run is
valid.

### TB28-R3-REV

Review the immutable R3 evidence only. It must:

1. verify artifact/source/selector/executable/identity-map/census integrity;
2. prove every ledger row selected exactly one test;
3. apply the 366/367/398 credibility gate before considering totals;
4. report accepted-prefix status and all RED ordinals;
5. classify every observed regression in `Regression_Root_Cause_Tracker.md` without inventing a stable event when
   evidence does not justify one;
6. evaluate the 191-face source-face-ownership publication;
7. decide only whether the already-frozen CM9 sequence may proceed to CB34 or whether the harness must be replaced.

No new runtime work is authorized inside TB-REV.

## 8. Exit routes

### Credible control

If orchestration is valid, selection is exactly one on all 407 rows, postflight is immutable, and 366/367/398 are
RED, close R3 with the actual semantic ledger. The next implementation turn is **`M3-CP4c-3-CB34`**, which may
apply only the frozen separating-arc barrier correction.

### Harness control failure

If any of 366/367/398 is PASS on the unchanged product, stop. Do not interpret the apparent selector total as
product evidence. Replace the R3 harness wholesale with the proven TB23-R1 harness architecture before any retry.

### Orchestration failure

If package integrity, identity routing, selected count, timeout, evidence upload, or census integrity fails, preserve
the first actionable evidence and stop without semantic credit. A retry is allowed only after a bounded
control-plane correction that cannot change product/test/fixture/selector bytes.

PR #8 remains draft and unmerged throughout this gate.

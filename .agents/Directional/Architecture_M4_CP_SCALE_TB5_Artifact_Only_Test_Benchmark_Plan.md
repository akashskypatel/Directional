# M4-CP-SCALE-TB5 Artifact-Only Test + Benchmark Plan

**Turn:** `M4-CP-SCALE-TB5-EXEC`
**Status:** AUTHORIZED EXECUTION PLAN / IMMUTABLE ARTIFACT ONLY / REVIEW REQUIRED
**Candidate compile authority:** source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`; compile run/job `34994665690 / 104467833192`; result artifact `10407605295`; result provider SHA-256 `29f68b3880fb9d2d521aa74541112af9de5d35fdc982decfdbc8067305e747e5`; log artifact `10406473227`; log provider SHA-256 `517ab8efbcebef96c30ca55a5caa7c85bc94467933d164a94f66b3e977dae00d`.
**Selector authority under test:** `Architecture_M4_CP_SCALE_CB6_Required_Green_Selector_424.txt`, exactly 424 LF-terminated identities, SHA-256 `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca`; first 423 rows byte-identical to accepted selector423 SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; row424 exactly `M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`.
**Owner census:** `30 authority-kernel / 278 producer / 75 completion / 41 validation`.
**Semantic status entering EXEC:** candidate only. Accepted runtime authority remains package `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` under selector423 until mandatory Review adjudicates TB5.

## 1. Boundary

This is an artifact-only `TB-EXEC` turn. It may execute only binaries and immutable inputs already packaged by CB6. It must not configure, compile, relink, regenerate, patch, repair, rewrite fixtures, mutate selectors, alter permissions, or change production/test/benchmark/build semantics. No runtime result is accepted by EXEC itself; `M4-CP-SCALE-TB5-REV` is mandatory.

A zero-selected process, missing row, duplicate row, wrong owner, wrong binary, timeout, crash, SKIP, altered package, altered execution view, or missing evidence is orchestration/validation failure, never PASS.

## 2. Immutable preflight

Before launching any Directional process:

1. Download exact artifact `10407605295` and verify provider digest `29f68b3880fb9d2d521aa74541112af9de5d35fdc982decfdbc8067305e747e5`.
2. Extract once into a fresh read/write execution staging root without modifying the immutable downloaded archive.
3. Verify the package `SHA256SUMS` completely: **28/28** entries must pass.
4. Verify package metadata identifies exact source `0d8e4aa3472fae26c22d49bc0d81acc5e98378d3`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and clean source status.
5. Verify packaged source archive SHA-256 `55bbe23520e7398fcf2e639623492007d445dd219ca1960cb5f63b301cd7b0c3` and extract it only for static provenance/fixture materialization.
6. Verify executable mode and packaged presence of all required owner binaries:
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
7. Verify GMP/GMPXX link evidence from the package; no replacement binary may be built.
8. Re-hash selector424 to `f202a1720c0a5288471d04836402b8432eb6f4f788da68a12e70dacb875466ca` and verify exactly 424 nonblank, unique identities with final LF.
9. Re-hash selector424 rows 1–423 to accepted selector423 SHA-256 `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343` and verify row424 is exactly the S2 identity above.
10. Re-derive unique exact-filter ownership against packaged test source: every selector identity must have exactly one owner and the census must be exactly **30 / 278 / 75 / 41**.
11. Materialize a fresh execution view using the already-corrected TB4-R1 package fixture convention: packaged `benchmarks/fixtures/**` must appear at `test-data/benchmarks/fixtures/**` for binaries that resolve fixtures through the packaged test-data root. Do not rename, repair, or synthesize fixture content.
12. Capture byte+mode censuses for immutable package, extracted source, and execution view before runtime.

Any failed preflight condition stops EXEC before semantic credit.

## 3. Required runtime execution

Execute selector424 cumulatively in **exact file order**, one fresh process per selector row. For each row:

1. Resolve its statically proven owner binary from the preflight mapping.
2. Start exactly one fresh process using an exact gtest filter equal to that identity; no wildcard or discovery/list command is allowed.
3. Preserve raw stdout, stderr, exit code, elapsed time, owner binary, ordinal, identity, and selection count.
4. Require exactly one selected test, exactly one PASS, exit code 0, no SKIP, no crash, and no timeout.
5. Record the row in a single ordered ledger. Do not import the TB4-R1 focused S2 result as row424 credit; row424 must execute freshly in this TB5 run.

The cumulative acceptance surface is **424/424**. The required owner totals in the execution ledger are **30 authority-kernel / 278 producer / 75 completion / 41 validation**.

No benchmark is required for this selector-publication turn; the word “Benchmark” in the canonical TB turn name does not authorize unrelated runtime.

## 4. Postflight and evidence

After the last row, without mutating the execution view:

1. Capture the same package/source/execution-view byte+mode censuses used at preflight and require exact equality.
2. Re-run the package's static checksum verification and require **28/28** again.
3. Re-hash selector424 and its 423-row prefix again.
4. Verify ordered ledger cardinality is 424 with no duplicate/missing ordinal and exactly the frozen owner census.
5. Emit a non-self-referential SHA-256 manifest for every substantive evidence file and verify every listed entry.
6. Package raw per-row process evidence, ordered ledger, pre/post censuses, preflight/postflight receipts, source/selector hashes, and a machine-readable summary.
7. Preserve result and detailed log as separate artifacts. Evidence-upload failure blocks completion.

EXEC reports mechanical observations only. It must not promote the package, accept selector424, discharge `M4-CP-SCALE-TB4-REV-OBS-01`, change stable accounting, or close CP-SCALE.

## 5. Acceptance / stop / rerun rules

Mechanical GREEN requires all of:

- exact artifact/source provenance verified;
- package checksum **28/28** preflight and postflight;
- selector424 exact hash/prefix/row424/owner census verified;
- **424/424 PASS** in exact row order;
- **0 RED / 0 SKIP / 0 timeout / 0 crash / 0 selection mismatch / 0 unexecuted**;
- exact package/source/execution-view pre/post equality;
- complete raw evidence and non-self-referential evidence manifest.

If orchestration is malformed, stop, preserve evidence, and route to a bounded runtime-free CB correction followed by a fresh TB retry from process 1. Do not salvage partial semantic credit.

If any correctly orchestrated selector row is semantic RED, stop only if the frozen harness says fail-fast; otherwise preserve the complete prescribed run. In either case, do not repair in TB. Route the evidence to mandatory `M4-CP-SCALE-TB5-REV`.

## 6. Mandatory successor

Regardless of GREEN or RED, the next semantic adjudication turn is **`M4-CP-SCALE-TB5-REV`**. Only Review may promote candidate artifact `10407605295`, accept selector424 as cumulative required-green authority, discharge `M4-CP-SCALE-TB4-REV-OBS-01`, or revise stable accounting. CP-SCALE remains open after S2 because S3, S4 and S5 are still separate frozen obligations.

# M4-CP-SCALE-CB5 Orchestration Correction Plan — immutable TB4 retry harness

**Status:** COMPLETE / STATIC GREEN
**Turn type:** Code + Build cadence slot, **runtime-free control-plane correction only**
**Semantic source/package:** frozen; no product/test/fixture/CMake/selector/package mutation
**Exact immutable candidate:** artifact `10378808176`, semantic source `905dabe390577d63ed6a9289e3f3d53aa4144936`

## 1. Purpose

Correct only the two runner-harness defects that invalidate TB4-EXEC. This is not a product Code + Build turn and must not compile or execute Directional binaries. The existing CB4 candidate package is reused byte-for-byte.

## 2. Frozen diagnosis

TB4-EXEC run `34938070127` is invalid for two independent orchestration reasons:

1. **Execution-view fixture layout.** The payload copied packaged `benchmarks/fixtures` into `view/test-data/benchmarks`, but `tests/TestFixturePaths.h` requires a path ending in `test-data/benchmarks/fixtures`. All 40 selector RED observations share the resulting missing-test-data exception and receive zero semantic credit.
2. **Postflight receipt basename.** Preflight wrote `execution-view-before.tsv`; `postflight()` tried to read `execution-view-census-before.tsv`, producing `FileNotFoundError` after the package checksum re-verification. The captured before/after censuses are actually identical, but the frozen receipt contract did not complete.

## 3. Authorized edit surface

Only runner/control-plane files for the next artifact-only execution may change. No edit is authorized to:

- production source;
- test source;
- fixture bytes;
- CMake/build semantics;
- reusable workflow permissions or reusable compile/workflow implementations;
- selector423 or any predecessor selector;
- CB4 candidate package/artifact;
- exact S2 oracle semantics.

## 4. Required corrections

1. Materialize the packaged source archive's `benchmarks/fixtures` subtree exactly under `view/test-data/benchmarks/fixtures`, preserving bytes and modes. Do not synthesize, rewrite or fetch fixtures from another source.
2. Use one internally consistent execution-view census basename before and after runtime. Prefer `execution-view-census-before.tsv` / `execution-view-census-after.tsv` so the names match `postflight()`'s package/source pattern.
3. Add static harness assertions that the expected fixture directory exists and contains the packaged subtree before any Directional runtime can start, and that every preflight census filename consumed by postflight is produced by the same payload version.
4. Preserve exact package/source/selector hash checks, the 28-entry self-excluding package manifest, owner census **30/277/75/41**, focused-first S2 process, full 423-row preinitialization, one fresh exact-filter process per selector row, fail-closed selection mismatch handling, resource receipts and immutable postflight.
5. Preserve failed-attempt provenance from TB4-EXEC; do not convert its 383/40 observation surface or focused PASS into semantic credit.

## 5. Verification — runtime forbidden

CB5 closes only after static/non-Directional verification proves:

- the control payload parses/compiles as Python where applicable;
- its fixture source and destination paths resolve to `benchmarks/fixtures` and `test-data/benchmarks/fixtures` respectively;
- the postflight census inputs exactly match the names emitted by preflight;
- no product/test/fixture/CMake/selector byte changed;
- no compile, configure, link, generated discovery, test, benchmark, CLI or other Directional binary executed.

A source snapshot/diff inspection is sufficient; no rebuild is authorized because the immutable candidate package already compiled GREEN in CB4.

## 6. Frozen retry

If and only if CB5 completes its static checks, exact next is `M4-CP-SCALE-TB4-R1-EXEC` against the same immutable artifact `10378808176` / semantic source `905dabe390577d63ed6a9289e3f3d53aa4144936`.

The retry must restart the entire frozen gate from process 1. It may use no semantic result from invalid TB4-EXEC. It must:

- verify the immutable candidate package and selectors from scratch;
- preinitialize all 423 selector rows as `UNEXECUTED`;
- run focused S2 once first;
- on focused RED, preserve the full untouched remainder and exact postflight then stop;
- on focused PASS, run all 423 selector identities once each in fresh exact-filter processes;
- complete exact package/source/execution-view postflight;
- execute no rebuild/repair/mutation/discovery/benchmark.

After a mechanically valid retry, the ordinary mandatory successor is `M4-CP-SCALE-TB4-REV` for independent semantic adjudication.

## 7. STOP rules

STOP and return for explicit re-planning if correcting either defect requires changing semantic source, tests, fixtures, selectors, package bytes, reusable workflow permissions, or accepted runtime authority. Do not recompile merely to make runner layout easier. Do not weaken the immutable census/postflight contract.

## 8. CB5 static verification outcome

CB5 completed the authorized control-plane correction without compiling or executing Directional. Exact inspection authority was source-snapshot run `34974644691` at control head `6103a19473cccd2cccedb023c633bfcfe10ece29`; snapshot artifact `10398945458` has provider SHA-256 `b314cfc3a78f97d1163df4827776c300ef0360b41b0f72656256efbef4592184`, and its internal `source.tar.gz` hashes `fae8d18911efa690784bf138da12d83d56ccea3835465fab65150cc0e1c2d2c1`. The semantic candidate remains artifact `10378808176` / source `905dabe390577d63ed6a9289e3f3d53aa4144936` unchanged.

The successor payload is `.agents/Directional/turn-payloads/m4_cp_scale_tb4_r1_exec.py` plus `m4_cp_scale_tb4_r1_exec_lib.py`, SHA-256 `a83ad830677f32aa0a882158c1e800762c65957ce5bb69645acbc511a8b37673` / `10fa3684a75968e5a14256c90f7e24fec486eb8d63553f9c6daee873ace20967`. Static verification established all frozen CB5 requirements:

- both Python payload files parse and `py_compile` successfully;
- fixture source is exactly `benchmarks/fixtures` and destination exactly `test-data/benchmarks/fixtures`; an isolated non-Directional helper exercise copied all **27** packaged fixture files and proved relative paths, file bytes, directory/file modes and symlink targets identical;
- one shared `CENSUS_BASES = (package, source, execution-view)` / `census_path(name, phase)` authority emits every `*-census-before.tsv` receipt consumed by postflight and the matching `*-census-after.tsv`;
- immutable candidate/package/source/selector constants, 28-member manifest checks, owner census **30/277/75/41**, focused-first S2, 423-row `UNEXECUTED` preinitialization, one fresh exact-filter process per row, fail-closed selection mismatch and immutable postflight remain in the payload;
- local diff inspection before documentation edits showed only the two successor runner payloads added: no production source, test source, fixture bytes, CMake/build semantics, selectors, reusable workflow permissions or package bytes changed;
- `runtimeExecution=false`; no Directional configure, compile, link, generated discovery, test, benchmark, CLI, repair or mutation executed.

The invalid TB4 attempt `34938070127` remains provenance only and contributes no semantic ledger. Accepted runtime authority and stable accounting are unchanged. Exact next is fresh `M4-CP-SCALE-TB4-R1-EXEC` from process 1 on the same immutable artifact, followed after a mechanically valid attempt by mandatory `M4-CP-SCALE-TB4-REV`.

**Process evidence note.** The start-of-turn read-mode gate was declared after several initial control/document connector reads. Once detected, piecemeal repository inspection stopped, `READ_MODE=snapshot` was enforced, and all implementation/static analysis proceeded from the verified exact snapshot above. No repository-applicable source work was authored before that correction.

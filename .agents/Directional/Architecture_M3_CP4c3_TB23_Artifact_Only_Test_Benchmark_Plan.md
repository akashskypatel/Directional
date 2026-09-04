# M3-CP4c-3-TB23 — Artifact-Only Test + Benchmark Plan

## Authority

- Canonical successor turn: **`M3-CP4c-3-TB23-R1`**, artifact-only Test + Benchmark re-execution under the CB26 orchestration correction, followed by independent **`M3-CP4c-3-TB23-R1-REV`**.
- `TB23-R1` is execution/evidence preservation only. It must not diagnose beyond recording plan-defined structured fields, edit source/test/build logic, compile, relink, regenerate, repair the package, or create a replacement artifact.
- `TB23-EXEC` / `TB23-REV` are retained historical provenance: the first execution was orchestration-invalid and the review froze the CB26 correction. Their raw runtime ledger is not semantic authority.
- Semantic source: `e12396d471c0754b112a40272a7992020ff49ced`.
- Immutable build artifact: `9921914679`, `m3-cp4c3-cb25-package-result-33831662949`, Actions digest `sha256:db346ad93460a20f12315eea984df3fa5bdd054cf5046fb5756d366f444a4fe7`.
- Compile run/job: `33831662949 / 100895799092`.
- Selector: `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_397.txt`, exactly **397** unique identities, LF SHA-256 `d67e5fb72196313c54fbc21be0b446ab0fba3974c47c02e18c33dfe9b4853ee5`.
- Frozen predecessor selector 393: exactly **393** identities, LF SHA-256 `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d` and exact prefix of selector 397.
- Accepted selector 365: exactly **365** identities, LF SHA-256 `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1` and exact prefix.
- Benchmark execution: **none**. This is a diagnostic selector gate, not a performance turn.


## CB26 orchestration amendment — binding for `M3-CP4c-3-TB23-R1`

`M3-CP4c-3-TB23-EXEC` is retained as an **orchestration-invalid attempt**. Its raw `342 PASS / 55 RED`
ledger is provenance only and is not semantic authority. `M3-CP4c-3-TB23-R1` re-executes this same frozen
397-identity semantic contract against the **same immutable package**. CB26 changes only the execution harness and
preflight layout; it does **not** change product, test, fixture, selector, package, compile, or link bytes.

The corrected harness is `.agents/Directional/tools/m3_cp4c3_tb23_r1_harness.sh`. It has two explicit modes:
`--preflight-only` (CB26 static/control-plane validation, no Directional runtime) and `--execute` (TB23-R1 only).
An omitted or unknown mode fails closed instead of defaulting to runtime.

### Required execution-view layout

The immutable package and immutable packaged-source extraction remain untouched. The harness constructs a separate
execution view:

```text
<execution-view>/
  bin/<six packaged executables>      # hard links to immutable package/bin bytes
  test-data/benchmarks/fixtures/...   # copied from immutable packaged source/benchmarks/fixtures
```

For a staged executable `<execution-view>/bin/<binary>`, reproduce `tests/TestFixturePaths.h` exactly:

1. candidate 1: `<execution-view>/test-data` (`executableDirectory.parent_path() / "test-data"`);
2. candidate 2: `<execution-view>/bin/test-data` (`executableDirectory / "test-data"`);
3. select the first candidate containing `benchmarks/fixtures`;
4. if neither candidate contains that tree, **stop before Directional runtime** with orchestration failure.

CB26/TB23-R1 must verify a known committed fixture through that selected consumer path, not through the extracted
source workspace. The intended corrected view selects candidate 1. Package and packaged-source pre/post byte+mode
censuses must remain equal to the preserved TB23 authority (`9c7b12f4beba6f64e4ab1af3980554ba7b9f46af535ec2d2f2a9650f0359a927`
and `e7bec1591154b4d9d79cd64ad27871305f54a51ba15946dc2042b55f6d2d8654`).

## TB23-R1 preflight — fail closed before Directional runtime

1. Download the exact Actions artifact by artifact ID. Record the provider artifact digest and the downloaded outer archive SHA-256.
2. Extract with an ordinary mode-preserving archive tool. **Do not use Python `zipfile.extractall`, `chmod`, or any content/mode repair.** If required executable mode is absent, stop as orchestration failure.
3. Run only static/package checks before Directional runtime:
   - `sha256sum -c SHA256SUMS` from the package root;
   - `metadata/source-commit.txt` equals `e12396d471c0754b112a40272a7992020ff49ced`;
   - `metadata/build-exit-code.txt` and `metadata/preflight-exit-code.txt` are zero;
   - `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `preflightCompile=true`;
   - `metadata/gmp-evidence.txt` proves `DIRECTIONAL_ENABLE_GMP=ON`, CMake GMP discovery, and both `gmpxx` and `gmp` on the authoritative generated link command;
   - `metadata/compiled-targets.txt` contains exactly the eight CB25 package targets;
   - all required six test/benchmark executables are present and executable with archived mode intact;
   - source archive exists and hashes through the package manifest.
4. Extract `source/source-e12396d471c0754b112a40272a7992020ff49ced.tar.gz` into an isolated immutable packaged-source root **with its repository-root paths intact**. Before runtime, construct the CB26 execution view described above: hard-link the six packaged executables under `<execution-view>/bin`, copy the packaged-source `benchmarks/fixtures` tree to `<execution-view>/test-data/benchmarks/fixtures`, reproduce `test_data_root()`'s two-candidate resolution rule against the staged executable path, and require a known committed fixture at the selected path. If neither candidate resolves, stop before Directional runtime. Do not patch the binary, mutate the immutable package/source trees, or relocate individual fixtures after runtime begins.
5. From the extracted source, run the read-only selector checks:
   - `python .agents/Directional/tools/selector_probe.py hash 365`
   - `python .agents/Directional/tools/selector_probe.py hash 393`
   - `python .agents/Directional/tools/selector_probe.py hash 397`
   - `python .agents/Directional/tools/selector_probe.py prefix 365 397`
   - `python .agents/Directional/tools/selector_probe.py prefix 393 397`
   Require the exact counts/hashes above and exact prefix truth.
6. Build a **static** identity-to-binary map from packaged source/CMake ownership. Do not execute a generated binary with `--gtest_list_tests`, help, version, discovery, or any other non-plan runtime command. Every selector identity must map to exactly one packaged binary; zero or multiple owners is orchestration failure.
7. Record a recursive byte+mode census of the immutable extracted package before the first Directional process. This is the postflight comparison authority.

## TB23-R1 runtime protocol

Execute all **397 selector identities in ordinal order**, one exact identity per **fresh process**:

```bash
"$EXECUTION_VIEW/bin/$OWNER_BINARY" --gtest_filter="$TEST_IDENTITY"
```

Rules:

- exactly one selector identity per fresh process;
- no process-level test retry;
- no zero-selected process is accepted;
- record ordinal, exact identity, owner binary, command, exit code, PASS/RED, and raw stdout/stderr;
- continue after plan-defined semantic REDs so all 397 identities receive one result;
- no full-suite elapsed-time watchdog; no `timeout` around the complete selector gate;
- do not run benchmarks, `ctest`, unrelated tests, or any binary-discovery command;
- do not repair permissions/content/fixtures or rebuild/relink anything after execution starts.

## Expected selector ledger and acceptance/discriminator checks

The plan does **not** predeclare CP4c-3 green. It expects the inherited diagnostic surface to remain RED at ordinal 366 while the new witnesses PASS and make that RED discriminating.

### D1 — accepted prefix

Ordinals **1–365 must be 365/365 PASS**. Any RED is an accepted-prefix regression and the turn is semantic RED regardless of later diagnostics.

### D2 — ordinal 366 semantic locus must not move

Ordinal 366 must still terminate at exactly:

- detail code `UncutFaceComponentOrbitSeedNotUnique`;
- failing uncut component `0`;
- seed state `Multiple`;
- exact seed orbits `[0,1,3]`;
- failing component face count `191`.

Movement of this product locus falsifies CB25 CA8.

### D3 — CA3 pair measurement is exercised

Ordinal 366 must publish both:

- `uncutFaceCertificatePairExaminedCount` > 0;
- `uncutFaceCertificatePairDifferingCount` as an independently computed count.

The CB25 production witness also requires the differing count to be > 0. Record bounded pair rows and truncation exactly as emitted. A missing field, zero examined count, or production witness failure is RED and must be preserved verbatim.

### D4 — CA2 independent certified sides

For every minority seed row emitted at ordinal 366, preserve:

- source edge;
- contributed seed orbit and seed rule;
- component source face and labeled source face;
- independently resolved `componentSideCertifiedFace`;
- independently resolved `labeledSideCertifiedFace`;
- explicit unavailable state where applicable.

Do not infer one side from the other in the TB harness. Record whether at least one available certified face differs from the seed value, as required by the production witness.

### D5 — CA4 failing-component certified-face multiset

Preserve:

- component face count;
- certified-face observation count;
- unavailable count;
- distinct certified-face count;
- bounded `(certifiedFace, multiplicity)` table;
- truncation flag.

Adjudication for `M3-CP4c-3-TB23-R1-REV` is deliberately binary: **one distinct certified face versus several distinct certified faces** names which live branch of `M3-CP4c3-TB21-CAND-01` remains causal. TB23-R1 records the data and does not choose the correction.

### D6 — carried surfaces and new witnesses

Require the inherited selector behavior outside the diagnostic locus:

- REDs remain ordinals **367, 368, 369, 370, 374** under their existing owners;
- ordinals **371, 372, 391, 392, 393** remain PASS;
- new ordinals **394–397** each select exactly once and PASS;
- every other identity after 365 retains its selector-defined result unless the structured evidence establishes a new regression.

With only the six inherited semantic REDs, the expected complete ledger is **391 PASS / 6 RED = 397**. This arithmetic is a consistency check, not permission to manufacture the expected result.

## Evidence to preserve

TB23-R1 must upload separate result and diagnostic-log artifacts containing at minimum:

- exact package artifact ID/name/provider digest and downloaded archive SHA-256;
- semantic source SHA;
- package `SHA256SUMS` verification result;
- GMP/GMPXX and command-boundary verification;
- exact executable mode census;
- selector 365/393/397 counts, hashes, and prefix checks;
- static identity-to-binary map and its SHA-256;
- complete 397-row ledger and ledger SHA-256;
- raw per-identity stdout/stderr and exit code;
- structured D2–D5 ordinal-366 fields copied without reinterpretation;
- list of exact RED ordinals and identities;
- pre/post recursive byte+mode census and equality result;
- flags proving no configure/compile/relink/regeneration/discovery/repair/source-test-fixture-selector mutation/benchmark occurred.

After the last process, recompute the recursive byte+mode census and require it to equal preflight exactly. Package mutation is orchestration failure even if semantic outputs look correct.

## Stop and routing rules

- **TB23-R1 preflight orchestration failure:** stop before Directional runtime; preserve the failed control-plane attempt and return to an orchestration-correction CB. It consumes no semantic result.
- **After runtime begins:** do not repair the immutable package or change launch roots. Preserve the result as semantic or orchestration-invalid according to the frozen contract.
- **Any accepted-prefix RED:** preserve all available evidence and route directly to `M3-CP4c-3-TB23-R1-REV`; do not patch in TB.
- **Expected ordinal-366 RED with discriminating CA3/CA4 evidence:** complete all 397 identities, preserve the full ledger, then route to `M3-CP4c-3-TB23-R1-REV`.
- **No further diagnostic Code + Build turn is authorized on this surface after CB25.** CB26 is orchestration-only and does not add product diagnostics. `M3-CP4c-3-TB23-R1-REV` is the independent reasoning boundary that owns the correction decision.
- TB23-R1 must not edit `Regression_Root_Cause_Tracker.md`; `M3-CP4c-3-TB23-R1-REV` owns classification/documentation after reviewing the immutable execution evidence.

## Success criterion for TB23-R1

`M3-CP4c-3-TB23-R1` is complete when the immutable artifact is proven unchanged, all 397 identities have exactly one fresh-process result, the accepted prefix is 365/365, D2–D6 are fully recorded, and result/log artifacts make the run independently reviewable. Because ordinal 366 is expected to remain semantic RED, **TB23-R1 completion is not checkpoint acceptance**. Exact successor: `M3-CP4c-3-TB23-R1-REV`.

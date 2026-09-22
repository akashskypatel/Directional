# M5-CP3-CB13 R11 Result-Manifest Finalization Orchestration Correction Plan

**Turn:** `M5-CP3-CB13`  
**Type:** **Code + Build / control-plane-only / runtime-free**  
**Owner:** `M5-CP3-TB1-R11-EXEC-CAND-01`  
**Candidate authority:** reuse `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` unchanged  
**If correction validates:** fresh `M5-CP3-TB1-R11-R1-EXEC` -> mandatory `M5-CP3-TB1-R11-R1-REV`

## 1. Goal

R11 completed all 446 planned Directional processes and immutable runtime postflight, then failed the frozen result
self-manifest contract. The caller created `SHA256SUMS.new` inside the result tree before `find`; the temporary file was
therefore hashed into the manifest and removed by `mv`, leaving **913 rows for 912 actual non-manifest files**.

CB13 corrects this **orchestration-only** defect. It does not interpret R11's diagnostic process vector, alter Directional
source/tests/fixtures/selector/routing semantics, or rebuild/repackage the candidate.

## 2. Authorized scope

Only the fresh R11-R1 GitHub Actions control plane and its turn-local orchestration payload/trigger may change semantically.
The correction must preserve:

- candidate artifact/source `10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`;
- routing artifact `10592987234`, identity-map SHA-256
  `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`;
- selector430 SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6` and first427
  `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- the exact 9 mechanism + 1 focused + 6 produced + 430 selector process set/order;
- exact-one selection, zero-skip, benchmark-zero, immutability and fail-closed semantics.

No Directional configure, compile, relink, generated discovery, test process or benchmark may execute in CB13.

## 3. Exact correction

Write the temporary final manifest **outside** the result directory. Required shape:

```bash
manifest_tmp="${RUNNER_TEMP}/${TURN_ID}-SHA256SUMS.final"
(
  set -euo pipefail
  cd "$result"
  find . -type f ! -name SHA256SUMS -print0 \
    | LC_ALL=C sort -z \
    | xargs -0 sha256sum > "$manifest_tmp"
  mv "$manifest_tmp" SHA256SUMS
  sha256sum -c SHA256SUMS
  manifest_rows="$(grep -cve '^$' SHA256SUMS)"
  actual_non_manifest="$(find . -type f ! -name SHA256SUMS | wc -l | tr -d ' ')"
  test "$manifest_rows" = "$actual_non_manifest"
)
```

Equivalent syntax is allowed only if it proves the same property: no temporary manifest output exists beneath `$result` while
the result evidence is enumerated.

The caller must copy `driver-authority.txt` into `$result` **before** final manifest generation. `SHA256SUMS` itself is
the only intended self-exclusion. If evidence shape remains unchanged, R11-R1 expects **912/912** rows/files; that expected count
is not permission to omit an unexpected evidence file.

## 4. Static and synthetic CB13 verification

Before authorizing Directional runtime, CB13 must prove:

1. workflow schema validation succeeds;
2. the manifest temporary path is outside `$result` during enumeration;
3. driver-authority copy precedes final manifest generation;
4. final `sha256sum -c SHA256SUMS` is fail-closed;
5. manifest row count is independently compared with actual non-manifest file count;
6. a bounded synthetic result directory containing ordinary evidence plus `driver-authority.txt` produces one manifest row
   for every actual non-manifest file and no row for the temporary manifest path;
7. any verification/count mismatch propagates nonzero;
8. no Directional executable is invoked;
9. candidate/routing/selector hashes and the 446-process plan are unchanged.

The synthetic proof may use shell/Python/coreutils only.

## 5. Fresh R11-R1 freeze requirements

If CB13 is green, freeze **`M5-CP3-TB1-R11-R1-EXEC`** against the same immutable candidate. It must restart all **446**
fresh exact-filter processes from ordinal 1, require exact-one/zero-skip, execute **0** benchmarks, perform no
configure/compile/relink/generated-discovery/repair/mutation, and complete exact immutable postflight plus full result-manifest
verification/count equality.

R11-R1 must not reuse any R11 process result, ledger decision or semantic status as acceptance evidence. R11 artifacts
`10714199742 / 10715035437` remain preserved only as invalid-attempt provenance.

## 6. Review ownership and stop conditions

CB13 must not adjudicate R11's diagnostic rows4/5, close the A3-directed ordering candidate, promote CB12, discharge debt or
change selector-publication eligibility. A mechanically complete R11-R1 routes according to ordinary cadence; semantic RED is
reviewed by `M5-CP3-TB1-R11-R1-REV`.

Stop if the correction would require Directional source/test/fixture/selector/routing mutation, candidate rebuild, weakening
manifest completeness, excluding any evidence file other than `SHA256SUMS`, or executing Directional runtime inside CB13.

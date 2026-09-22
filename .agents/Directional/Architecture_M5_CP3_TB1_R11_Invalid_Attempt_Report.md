# M5-CP3-TB1-R11 Artifact-Only Test + Benchmark Invalid-Attempt Report

**Turn:** `M5-CP3-TB1-R11-EXEC`  
**Boundary:** artifact-only Test + Benchmark / immutable candidate / no rebuild or package repair  
**Disposition:** **ORCHESTRATION INVALID / NO SEMANTIC LEDGER / INVALID ATTEMPT PRESERVED / CONTROL-PLANE CORRECTION REQUIRED**  
**Exact successor:** `M5-CP3-CB13`

## 1. Immutable authority and attempt evidence

R11 consumed only CB12 candidate artifact `10713410215`, semantic source
`8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188`. Candidate ZIP SHA-256 is
`faf4def9e6823f718e56091876bb97047f5e91a8bfb561ca40d91d70d2af61ce`; root `SHA256SUMS` verifies **28/28** at
`352f7553e2f0dc627ada385d78327bcb93d4f3b66125f4faf540d6965a1c2c33`; packaged source archive SHA-256 is
`506e9d75976802f7045b95344ef8cc0ff1e4d39b8343bdaddaa009a58e04a673`.

Attempt run/job is `35771152416 / 106892972571`, event SHA
`3ba8a2450c03e82afbd6c5fd529809cc7d0d7dd4`. Workflow schema validation passed. Invalid-attempt result/log artifacts are
`10714199742 / 10715035437` at provider/download ZIP SHA-256
`26b0d4aa711fa1481f45d6eb4dc8dc0d605126abb08fa744a6843f958df1f23e /
aa80f1859fce582fdba8a0a7e31c6d8a5edae3c0e521b800171a1af8494b3d7f`.

Driver authority records template SHA-256
`370ebb5aaa6b77f8839ac0a7c5a20f24a22cd584876ea17a11d222a5ec4f9624`, writer SHA-256
`d8b7d77d7425c02de4327aae47ac20614e1fbc36afe1c66b3af9d1d3a8128995`, rendered-driver SHA-256
`0507d937e18a97150031518ffd42c0dddc9520095f3bbebcf0f9dc2fc10ca996`, and copied `driver-authority.txt`
SHA-256 `273276fdf6488fb89702e24e90ee12f17550413e54655cf3fd70ccfefae14609`.

## 2. Deterministic finalization failure

R11 corrected R10's post-copy omission by placing `driver-authority.txt` in the result before regenerating the manifest, but
the replacement finalizer redirected its temporary output **inside the same result tree**:

```text
find . -type f ! -name SHA256SUMS -print0 \
  | LC_ALL=C sort -z \
  | xargs -0 sha256sum > SHA256SUMS.new
mv SHA256SUMS.new SHA256SUMS
```

Shell redirection creates `SHA256SUMS.new` before `find` walks the tree. The temporary empty file therefore becomes a
manifest row. After `mv`, that referenced path no longer exists, so final verification fails exactly on
`./SHA256SUMS.new`.

The uploaded result contains **913 total files = 912 non-manifest evidence files + `SHA256SUMS`**. Its invalid manifest has
**913 rows**, SHA-256 `8d66c6993da9cac570c6953d2f802d179ae7186f2ae6d58a6b5dd1c20dd937f4`. Independent inspection verifies
all **912 actual non-manifest evidence files**; the sole failed row is the removed temporary file. Workflow log records
`result_manifest_rows=913`, `result_non_manifest_files=912`, `result_finalization_exit=1`, and `driver_exit=1`.
The final fail-closed workflow step therefore correctly concludes failure.

## 3. Runtime provenance is diagnostic only

All **446/446** planned fresh exact-filter processes ran before finalization failed. Preserved raw ledgers show:

- mechanism **9/9 PASS**;
- focused atlas **1/1 PASS**;
- produced **4/6 PASS**, with rows4/5 reporting `PeriodicActionCorrespondenceMismatch`;
- selector430 **430/430 PASS**;
- exact-one selection, zero skips and benchmark **0**.

The runtime driver also records exact immutable postflight: package/source/execution-view censuses are unchanged, candidate
manifest remains 28/28, and configure/compile/relink/generated-discovery/package-repair/mode-repair/source-test-fixture-selector
mutation counters are all zero.

Those rows are **invalid-attempt provenance only**. Durable cadence says an orchestration failure produces no semantic ledger.
R11 therefore does not adjudicate CB12, close/open a product regression from the raw vector, promote the candidate, discharge
debt, close observations, or authorize selector publication.

## 4. Accounting and owner

Open `M5-CP3-TB1-R11-EXEC-CAND-01` as:

**OPEN / ORCHESTRATION / SELF-INCLUSION TEMP-MANIFEST PATH / NON-STABLE / OWNER `M5-CP3-CB13` -> `M5-CP3-TB1-R11-R1-EXEC` / +0.**

Accepted runtime authority remains package/source
`10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains
**50 events / 14 categories / 36 recurrences** and project produced-witness debt remains **3**. CB12 candidate
`10713410215 / 8ff6fdc720b3e8da5c4f5765850f8fe69d4b2188` remains unpromoted. Selector publication remains prohibited.

The prior product/acceptance obligations remain open for a mechanically valid fresh retry and Review:
`M5-CP3-TB1-R10-REV-CAND-01`, `M5-CP3-TB1-R10-EXEC-CAND-01`, `M5-CP3-TB1-R10-REV-OBS-01`,
`M5-CP3-TB1-R6-REV-OBS-01`, and `M5-CP2-TB1-REV-OBS-01`.

## 5. Exact successor

Exact successor is runtime-free control-plane-only **`M5-CP3-CB13`**, governed by
`.agents/Directional/Architecture_M5_CP3_CB13_R11_Result_Manifest_Finalization_Orchestration_Correction_Plan.md`.

If CB13 validates, its successor is fresh artifact-only **`M5-CP3-TB1-R11-R1-EXEC`**. That retry must consume the same
immutable CB12 candidate, restart the entire frozen 446-process gate from process 1, and import **zero semantic rows** from this
invalid attempt. A mechanically complete retry then follows the ordinary cadence; semantic RED routes to mandatory
`M5-CP3-TB1-R11-R1-REV`.

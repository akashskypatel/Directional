# TB47 same-turn R52 — compiled but unselected hard-rail controls (2026-10-28)

**Canonical turn:** `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` — still `IN_PROGRESS`. This is an independent, runtime-free Review supplement, not a TB execution, Code + Build authorization, frozen selector change, or successor.

## Independent primary-byte audit

- Re-downloaded immutable CB47 compile/package artifact **12732383172**, outer SHA-256 `c2bf478d0cd610514528c10db62256e30407c1db600d7b8c2723371f765d910e`; verified **28/28** packaged SHA256SUMS. Its source commit is `08d41626e3487f3cba2e8fed5fe1f2185da8ac9f`, `runtimeExecution=false`.
- Re-downloaded original TB47 artifact **12734719880**, outer SHA-256 `f03efe3c2f75b113ac9e05329799955e4306d611feb4d83c38a2cd672be6b04d`; verified **1,014/1,014** internal SHA256SUMS and **504** ledger rows.
- Reused independently verified source snapshot **12792353485**, outer SHA-256 `1347b6b15ebea7d98845cfb962858bf2735d7b1b5a737f29f8929cb0288fcaf7`, 5,951/5,951 source checksums. The C++ test source extracted from the exact CB47 package and this snapshot both hash to `bec57b16e2475cd21be975fad22411925bdceaabd496f3258801d0f7875ea661`.
- The frozen TB47 manifest in both package/source snapshot has SHA-256 `488a20b658fc18ddf64addacd9f3150b35b68b067fd37ba7b11346db958d5955`: exactly **504 unique selected cases**, expected **500 PASS / 4 RED**.

## Compiled owner tests omitted from TB47 selection

The original `bin/directional_surface_cell_producer_tests` ELF binary contains `M6CP3_<name>_Test::TestBody()` symbols verified with `nm -C`, with matching source `TEST(M6CP3, ...)` bodies and exact binary GTest name strings for all three:

1. `M6CP3.A5RejectsA4AcceptedHardRailEndpointBranchForgery`
2. `M6CP3.CheckedA4RejectsGlobalHardRailSideSwapWithSelfInverseTau`
3. `M6CP3.A5RejectsSourceEquivalentHardRailSelectedFaceRechart`

All three identities are **absent** from the 504-row frozen TB47 manifest. This strengthens the R47/R48 earlier *source-only/unselected* finding: there is **no compilation prerequisite** to run these exact already-built test bodies in a separately authorized artifact-only TB procedure. It does **not** prove they ran, pass, isolate a unique first error site, or satisfy G2 paired source-produced covariance. The original `focused30:12` remains a failed incoherent one-sided relabel positive and must not be credited as a valid covariance check.

The read-only audit script `tb47_r52_compiled_unselected_owner_audit.py` (SHA-256 `62da594a2ba84caff5c6eca0c0baf54cd63a2850330df19a2a55ed7dfd3bf95d`) yields receipt `tb47_r52_compiled_unselected_owner_receipt.json` (SHA-256 `a0865b63733548f37fb7d1fe074a910d26b6e0d89594050a9b7a5c0047b4ab1d`). Four controls are independently rejected: missing TestBody symbol, removed source TEST, a falsely selected case, and removed binary name string. The script and JSON are preserved as downloadable ChatGPT artifacts, not introduced into product/test source.

## Disposition and mandatory limits

- **New narrow finding:** all three pre-authored negative test bodies are compiled into the existing immutable package; a future authorized TB could measure them without recompilation or test-source edits. This is an **availability** finding only.
- **Still outstanding:** native execution/first-error locus and restoration for each relevant negative; G2 paired constant/raw-arm-reindexed *source-produced* A3/A4/A5/A6 equality; G1 source-producible independent positive plus explicit invalid-authority negative; G3 producer-native odd periodic face-gauge witness; masked A5 periodic tail; E2 independently owned `cp3entry:2`; and authentic parent-wise Git-history validation.
- **No promotion:** accepted CP2 remains **491/491**, TB47 remains unpromoted **500 PASS/4 RED**, selector497 frozen, stable **66 events /17 categories/49 recurrences**, debt **1**. Do not start E2-PATCH, CB48, TB48, or any successor until the active review formally authorizes it.
- **Execution boundary:** no Directional binary was run, no C++ build/test/benchmark executed, and no product, test, fixture, selector, manifest, or workflow source changed. `review_check.py boundary` invoked on the history-free source snapshot returned **exit 1** because genuine rewrite ancestry/baseline Git history was unavailable; incidental selector PASS/untracked output from that synthetic tree is **not** authentic boundary approval. The checker has independent false-green issues documented in R38/R50/R51.

This supplement should be consolidated into the active `Architecture_M6_CP3_DEFN_TB47_Gauge_Cluster_Independent_Review_20261027.md` at the next authorized documentation consolidation. Do not manufacture runtime evidence from compiled symbol presence.

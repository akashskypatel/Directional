# M5-CP1-CB2 Orchestration-Correction Report

**Turn:** `M5-CP1-CB2`
**Turn closeout:** **COMPLETE**
**Disposition:** **STATIC GREEN / CONTROL-PLANE CORRECTION PROVED / RUNTIME-FREE**
**Semantic candidate unchanged:** artifact `10595705100`, source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Routing authority unchanged:** artifact `10592987234`
**Exact successor:** `M5-CP1-TB1-R2-EXEC`

## 1. Outcome

CB2 repairs only the artifact-only executor control plane that blocked R1. It adds one canonical checked-in harness and one schema-valid executor template, proves the harness and all frozen artifact/routing literals against immutable local extracts, and independently validates the future workflow on GitHub Actions. **No Directional binary, configure, compile, relink, generated discovery, package repair, test/fixture/selector mutation, or benchmark executed.**

Canonical control-plane authority is:

- harness: `.agents/Directional/tools/m5_cp1_tb1_r2_artifact_only_harness.sh`, SHA-256 `b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`;
- executor template: `.agents/Directional/tools/m5_cp1_tb1_r2_executor.yml`, SHA-256 `9c9c2527176645d143cf1f972ad5d493db44bc819179fb04a1845f7bd20a12a1`;
- installation commit: `adbd441195fa2dbc122a7463f14e56d6e281c78f`.

The future retry boundary is therefore fresh `M5-CP1-TB1-R2-EXEC`; R1 is not retried in place and contributes no semantic evidence.

## 2. C1 — canonical harness bytes: GREEN

The canonical UTF-8 harness passes `bash -n`. Deterministic `gzip -n -9` plus Base64 generation and a fresh decode reproduce the harness byte-for-byte at the same SHA-256. Local pre-trigger receipts record:

- canonical harness SHA-256 `b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`;
- deterministic GZip SHA-256 `9a1a594a7f77b5cc15ebd3be860690c24b5cb0d92ed98788119fdc455b638e45`;
- Base64 text SHA-256 `a2c59b7f2357626914c99356d2e5e5318cd7303dcb3a9dec154ade256275a643`;
- decoded round-trip SHA-256 `b706d03adde7d7d3daacb6ac46c4cb35468a40e162d7fb9d1617d4e562d37302`;
- `roundtrip_byte_identical=true`, `gzip_deterministic=true`.

The R2 executor reads this canonical repository file directly. No compressed/Base64 payload is embedded in the workflow.

## 3. C2 — immutable artifact/path resolution: GREEN

CB2 downloaded each immutable input once and used local extracts only. It did **not** execute a packaged Directional binary.

Candidate artifact `10595705100` re-hashes to `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`. Root `SHA256SUMS` re-hashes to `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d` and verifies **28/28**. The packaged source archive re-hashes to `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`; `metadata/source-commit.txt` remains `b98f461b9a392cc182891a81c0a84b0b01dfbb45`; clean-source and GMP/GMPXX receipts are present.

Selector authority resolves exactly: selector430 has **430 LF rows**, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`, and its first427 prefix hashes to `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

Routing artifact `10592987234` re-hashes to `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`. `identity-map.tsv` is header + **430 rows / 430 unique identities**, SHA-256 `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`, with owner census **31 / 283 / 75 / 41**.

All nine frozen focused identities resolve exactly once in packaged producer-test source; the superseded `M4CP4.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` identity resolves zero times. The ninth identity remains `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization`; its direct-helper body retains exactly two holonomies and two owned periodic edges before reorder and remains mechanism-only.

## 4. C3 — literal/workflow validation: GREEN

All expected SHA-256 literals in the canonical harness/template are lowercase 64-hex values. All frozen paths and counts above were mechanically checked. The executor contains no `timeout-minutes` and the canonical harness contains no shell `timeout` watchdog.

Final static-validation run `35490228347` is GREEN:

- caller-schema job `106023788966`: **success**;
- executor-template schema job `106023789037`: **success**;
- static-proof job `106023806911`: **success**;
- static-proof artifact `10598826679`, ZIP SHA-256 `d765ed4d54b07f130e83f44dd499d61584e6dab1693b32db9472d14004b05b2d`;
- receipt: `bash_n=true`, `schema_valid=true`, `permission_ceiling_valid=true`, `hidden_timeout_watchdog=false`, `roundtrip_byte_identical=true`, `runtimeExecution=false`.

The two SchemaStore report artifacts are `10599330445` (`20e546cc05cd34d8459736bb21c8096632b2afac862c6b01b6a8a40250b63c24`) and `10598448978` (`3664837fe5652aacaa0570966f9dc9e5ada642bc6d6abfc27ea92b5f1191cdcc`).

Three earlier validation attempts receive no acceptance credit but are retained as control-plane evidence: `35490108751` stopped at workflow startup because the caller ceiling was `contents: read` while the reusable observer declares a `contents: write` branch-file job; `35490134991` proved both schemas green but the auxiliary digest checker incorrectly treated the 40-hex source commit as a SHA-256 literal; `35490179325` again proved both schemas green but the corrected checker had over-escaped regular expressions and matched zero literals. No Directional runtime occurred in any attempt. The final run corrects the validator itself rather than weakening an executor requirement.

## 5. C4 — fresh retry boundary: GREEN

The canonical template is named and routed only for `M5-CP1-TB1-R2-EXEC`. Its trigger namespace is `.agents/connector-triggers/m5-cp1-tb1-r2-exec-20260920.txt`; its concurrency group is R2-specific; it starts the immutable harness from ordinal 1; each focused and selector identity runs in a fresh exact-filter process. It imports no result, process row, or semantic credit from R1.

R2 preserves exactly **9** focused identities, selector430 **430** rows, immutable postflight, and benchmark count **0**. Focused semantic RED does not silently mutate or repair the package; orchestration failures remain fail-closed.

## 6. Change and boundary evidence

The canonical tool/template pair was transported as one verified Drive patch:

- patch SHA-256 `deacc5da3b4621c1999a3afc66d7429298acebf092be0bc22cab61d361109dc7`;
- apply run `35490050504`, job `106023349098`: **success**;
- apply result artifact `10599115939`, ZIP SHA-256 `3e90be3072dc0333d904739452aaf68c1b173ec76b0638041bcab6a7f2e69037`;
- applied commit `adbd441195fa2dbc122a7463f14e56d6e281c78f`;
- workflow identity could not trash the staged Drive file, so owner-side connector deletion was completed successfully after evidence capture.

A whole-range diff from snapshot-trigger authority `7b6b488af828594d776d9550a77924819235fe0c` through pre-closeout control head shows only the two authorized canonical tool files plus temporary CB2 connector markers. Product, test, fixture, selector, benchmark, `src/**`, and `include/**` paths are untouched.

Turn source snapshot run `35489627113` / artifact `10598328416` has outer SHA-256 `d362b862e8fcc7a6f676c8cce37bfd633dfd76f3b0f207a0b0cf9dcfdfec774a`; its internal source archive SHA-256 is `f3c8d8a5bd4d8215e9d7cb40172f78043e0bde2de9bba10bcdf20e4a47574d57`, **5292** files, `runtimeExecution=false`.

## 7. Accounting and successor

CB2 creates no semantic regression event and discharges no production debt. Stable accounting remains **49 events / 14 categories / 35 recurrences**; produced-witness debt remains **5**. Candidate `10595705100` stays unchanged and unpromoted; accepted runtime authority stays M4 package `10591801825` / selector430 **430/430**.

`M5-CP1-TB1-R2-EXEC` is the exact successor. It must install the schema-green canonical executor template verbatim as `.github/workflows/m5-cp1-tb1-r2-exec.yml`, verify its frozen SHA-256 and the canonical harness SHA-256 before triggering, then execute only the frozen artifact-only gate. CB2 performs no R2 semantic runtime.

Tool-call accounting is partial/unknown after context compaction and is not reconstructed with additional calls.

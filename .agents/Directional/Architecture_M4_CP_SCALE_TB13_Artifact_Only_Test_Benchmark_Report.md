# M4-CP-SCALE-TB13-EXEC — selector427 artifact-only Test + Benchmark report

**Turn:** `M4-CP-SCALE-TB13-EXEC`
**Result:** **ALL GREEN / REVIEW REQUIRED / NOT YET PROMOTED**
**Immutable package:** artifact `10565723112` / `m4-cp-scale-cb24-result-35391181281`
**Exact compiled source:** `6fe075f7d9397a561fe50b79517b4f714fb9eeef`
**Benchmark execution:** 0

## 1. Execution authority

TB13 consumed the CB24 package exactly. Input artifact provider ZIP SHA-256 is `96e9e900e67777f31fbbf97d05efc44ed8c944d9f2bc031a5826e47602ea7bfa`; packaged source archive SHA-256 is `3b6b587efadf3b83082b11e5f7a9e1c06b5c8f1ce0671d82db707ffc7fac3bfd`; package `SHA256SUMS` is **28/28**. Package metadata records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, clean source receipts, executable modes `0755`, and authoritative GMPXX+GMP linkage.

Execution workflow run/job `35393657851 / 105757517161` ran from control SHA `6df7419e2e7f910a93e985ebf0693ecc1644c6db`. The frozen Drive harness is `1-KvdWwIBT81skkdNudg5xOkrQp5qjasA`, **16,485 bytes**, SHA-256 `b34ea0caf1b27016d84124452dc13e5bb0a3105556a24041a47a09020e1697aa`. The caller's SchemaStore validation job `105757458094` is GREEN before the execution job proceeds.

## 2. Immutable preflight

The packaged selector is exactly **427 LF rows**, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; first426 is `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`; first425 is `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`; row427 is exactly `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`. Static ownership is **30 authority-kernel / 281 producer / 75 completion / 41 validation**.

The execution harness froze package, packaged-source, and runtime execution-view byte+mode censuses before the first generated process. The execution view preserves packaged binary bytes/modes and supplies only the immutable packaged fixture tree at the compiled sibling `test-data/benchmarks/fixtures` path; no package or permission repair occurred.

## 3. Runtime gate

All selector427 identities executed **exactly once in exact file order**, one fresh process per identity, using the owning packaged test binary and exact GTest filter with fail-on-zero-selection enabled.

- **PASS:** 427
- **RED:** 0
- **SKIP:** 0
- **crash:** 0
- **timeout:** 0
- **selection mismatch:** 0
- **unexecuted:** 0
- exact selected-count receipt: **427 rows with selected=1**
- exact skipped-count receipt: **427 rows with skipped=0**
- PASS ownership: **30 / 281 / 75 / 41**

Row427 `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` PASSes in its own fresh producer-test process. The complete 427-row ledger SHA-256 is `2a71510891fd7cc9c4e33483a908ce4505c4bcd315053ea6f72f7055322abfed`; `identity-map.tsv` is `69756384783390b6eb5f0324dce006939e4b287f28c2b9313f9f889d42c8ebcf`, and its identity sequence is byte-order equivalent to selector427.

## 4. Immutable postflight and evidence

Postflight completed after row427 and proves exact equality with preflight:

- package census before/after SHA-256: `1e48857b5810aa9520754d37c4d684e27a40eb494a46dd55d71256c2df2ca70c`;
- packaged-source census before/after SHA-256: `be93504b4d81a3c92c633389bce39c93aaaf968b14296df370bebeaaed75edf4`;
- execution-view census before/after SHA-256: `d2079a0b45e0f1a9c8df827d6a6fdfd78e1efa88d56310ce3d72be872a3d5b5a`;
- package manifest verification before/after is identical at SHA-256 `3fab9b68ce79a2140bd963584a8be1b4ff06b3a421d3bb7fcaf481ad46d19721`;
- result evidence manifest contains **870** self-excluding entries and hashes to `94f02091cfcbc672ab05679e91175fdf4a828efef013d935ad067af913c5bb93`.

Result artifact `10566648975` / `m4-cp-scale-tb13-result-35393657851` has provider ZIP SHA-256 `3dd23c08cad9eccd49e61fae4cd14cb735bccc5a00ef23f2192af339aef1f366`. Persistent log artifact `10567158604` has provider ZIP SHA-256 `f7987aa4219881b966f324dff939294585fb3992980ebf730d0dbb9889b1cda6`. The evidence boundary records `orchestration_failure=false`, `semantic_non_green=false`, `runtime_started=true`, `postflight_complete=true`, `stop_reason=all_green`.

Benchmark/build/configure/compile/relink/generated-discovery/repair/package-repair/mode-repair/source/test/fixture/selector-mutation counts are all **zero**.

## 5. EXEC disposition

TB13 provides the fresh cumulative selector427 runtime leg required by `M4-CP-SCALE-TB12-R10-REV-OBS-01`, but EXEC does **not** independently promote CB24 package `10565723112` or grant cumulative S5 selector credit. Accepted current M4 runtime authority therefore remains R10 Review package `10560828304` / semantic source `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff` / selector426 **426/426** until mandatory Review adjudicates TB13.

No accepted-green regression is observed and no new regression candidate is opened. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. `M4-CP-SCALE-TB12-R10-REV-OBS-01` now has both publication and fresh-runtime legs complete; only independent Review remains.

Exact successor: **`M4-CP-SCALE-TB13-REV`**. Review must be runtime-free, independently re-open artifact `10566648975` plus the immutable input package authority, re-derive selector/prefix/owner authority and complete-ledger/postflight evidence, and decide promotion/cumulative S5 credit.

## 6. Turn-end hygiene

Durable closeout evidence was applied through the Google Drive patch workflow run/job `35395903278 / 105764581759`. The preservation patch SHA-256 was `acf74da62318e1e33140ccdf4e932db0384d8d000a64fe5f2cc6897961e526fc`; it applied at commit `48ecb7e81941a9904d8685a2a591d708cd6c268a`. Apply result artifact `10567233918` has provider ZIP SHA-256 `a208433a91a89f822dc406da8d736966aa5b47dcd0b6c099a025177569054fcc`; its recorded `runtimeExecution=false`.

Temporary callers were removed connector-first at commits `1fcb155a86b5024a9b91bf172153e691674738e2` and `5bf720d8fc561002e13056b255ba559d26d67b34`. Mandatory cleanup run/job `35396046077 / 105764992899` completed GREEN and produced cleanup commit `10f33521e9046269bd1fa0b978ec16dd3c6f8e7b`. Cleanup result artifact `10567403690` has provider ZIP SHA-256 `5c8664427a2527d390315ed23e8fd242fb27d8d938048bf2c2967b8164a30bc9`; cleanup removed the TB13 execution marker, closeout-apply marker, initial source-snapshot marker, and resume source-snapshot marker. The cleanup workflow deleted five PR conversation comments and zero inline review comments, leaving zero of each before its observer, and records `runtimeExecution=false`.

The post-cleanup workflow inventory contains only the seven durable agent workflows: compile, Google Drive patch transport, recent-runs observer, run observer, source snapshot, turn cleanup, and workflow schema validator. Immutable Actions evidence remains preserved. The consumed frozen harness, the applied closeout preservation patch, and the obsolete pre-reconcile preservation patch were all permanently retired from Google Drive after their work was authoritative in repository/Actions evidence.

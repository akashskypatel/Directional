# M4-CP4-CB6 — TB2 orchestration-correction Code + Build plan

**Turn type:** Code + Build / control-plane-only / runtime-free
**Authorized by:** `M4-CP4-TB2-EXEC` orchestration-invalid closeout
**Semantic scope:** no product, test, fixture, selector, CMake, package, or accepted-runtime change

## 1. Purpose

Correct only the execution control defect that invalidated TB2: the 431-process full gate was hosted inside a foreground tool call with an external 300-second deadline. The immutable CB4/CB5 packages and frozen composite semantic gate are reusable and must not be rebuilt or changed.

## 2. Frozen authorities

Preserve exactly:

- full CB4 artifact `10578784752`, source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`;
- CB5 delta artifact `10582435470`, source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`;
- selector427, 427 LF rows, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, owners **30 / 281 / 75 / 41**;
- exact TB2 focus rows1/2/5/6 and owner routing frozen in `Architecture_M4_CP4_TB2_Artifact_Only_Test_Benchmark_Plan.md`;
- benchmark count zero and all build/repair/mutation counters zero.

No artifact may be rebuilt or repackaged. No generated Directional binary may execute in CB6.

## 3. Required orchestration correction

Author a bounded, auditable R1 execution harness and caller that can run the complete gate to an organic result without a full-suite elapsed-time cutoff.

1. Host R1 on GitHub Actions (or another repository-authorized execution plane) rather than inside a foreground ChatGPT container-tool call.
2. The workload job must have **no `timeout-minutes`** whose purpose is to terminate the full gate and the harness must not wrap the full gate or any selector process in `timeout`/watchdog logic.
3. Download each immutable artifact once by exact artifact ID; verify the frozen provider SHA-256 before extraction.
4. Extract executable payloads with ordinary `unzip`/`tar` preserving archived modes. Python `zipfile.extractall` and post-extraction `chmod` repair remain prohibited.
5. Reconstruct the exact composite view: producer/validation from CB4; authority-kernel/completion from CB5; packaged-source fixtures at sibling `test-data/benchmarks/fixtures`.
6. Re-derive the exact 30/281/75/41 owner map statically from packaged source/CMake authority before runtime; generated test discovery remains prohibited.
7. Execute four focus rows then selector427 from ordinal 1 as **431 fresh exact-filter processes**. Semantic RED must not truncate later focus or selector rows. Selection mismatch, skip, missing executable, hash/mode/source mismatch, or incomplete postflight is orchestration failure.
8. Always emit complete raw logs, per-process ledger, first-semantic-RED summary, pre/post byte+mode censuses, manifest re-verification, boundary counters, and a self-excluding result manifest.
9. Upload result and diagnostic-log artifacts under `if: always()` so a semantic RED remains inspectable.

## 4. Workflow publication rules

Any new/modified `.github/workflows/**` caller must follow `GitHub_Workflow_Policy.md`: draft outside the active workflow directory when practical, validate the exact YAML through `agent-workflow-schema-validator-reusable.yml`, install caller and trigger marker in separate commits, use `agent-run-observer-reusable.yml`, and keep the caller temporary. Required permissions are limited to what artifact read, repository checkout, observer reporting, and artifact upload actually require; reusable-workflow permission ceilings may not be weakened or guessed.

CB6 may author control-plane scripts/caller definitions and run schema/static preflight only. **It must not trigger R1 Directional runtime.**

## 5. Verification and closeout

CB6 is complete only when static evidence proves:

- the corrected execution path contains no full-suite timeout/watchdog;
- exact artifact IDs/hashes, selector hash/cardinality, owner census, focus set, process order, and fixture layout are frozen;
- semantic nonzero is captured without shell `errexit` truncation and mandatory postflight still runs;
- the invalid TB2 attempts are retained only as no-credit provenance;
- no product/test/fixture/selector/CMake/package semantic bytes changed;
- no Directional runtime, compile, or repackage occurred.

Exact successful successor: **`M4-CP4-TB2-R1-EXEC`**, which re-executes the complete 431-process frozen gate from scratch against the same immutable packages. R1 must not resume from any invalid TB2 ordinal.

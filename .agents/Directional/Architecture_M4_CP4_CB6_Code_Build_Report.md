# M4-CP4-CB6 — Code + Build report

**Turn:** `M4-CP4-CB6`
**Result:** **COMPLETE / CONTROL-PLANE CORRECTION GREEN / RUNTIME-FREE**
**Successful successor:** `M4-CP4-TB2-R1-EXEC`

## 1. Scope and authority

CB6 corrects only the execution-plane defect that invalidated `M4-CP4-TB2-EXEC`: the full 431-process gate had been launched through a foreground ChatGPT tool call carrying an external 300-second deadline. No product, test, fixture, selector, CMake, package, accepted-runtime, regression-accounting, or debt semantics are changed.

Frozen runtime inputs remain exactly:

- full CB4 artifact `10578784752`, source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`;
- CB5 delta artifact `10582435470`, source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`;
- selector427 at 427 LF rows / 34,783 bytes / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- owner census `30 / 281 / 75 / 41`;
- the four M4-owned focused identities in the frozen order from TB2;
- producer/validation routing to CB4 and authority-kernel/completion routing to CB5;
- benchmark count zero and all configure/compile/relink/discovery/repair/mutation counters zero.

Accepted M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 2. Durable R1 execution payload

Drive patch transport committed the successor payloads as commit `cac96243ef6489107db03e47b11467efc61cd918`:

- `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-harness.sh` — mode `755`, 30,249 bytes, SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`;
- `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-caller-draft.yml` — mode `644`, 5,531 bytes, SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c`.

The harness downloads each immutable artifact once, verifies the frozen provider and package/source/manifest hashes, re-derives the exact semantic source delta and owner map statically, reconstructs the composite execution view with archived modes intact, materializes the sibling fixture tree, executes four focused rows followed by selector427 as **431 fresh exact-filter processes**, and requires exact-one selection with zero skips. Semantic RED is recorded without truncating later semantic rows; orchestration failure alone terminates further runtime. Mandatory postflight re-censuses both package/source trees and the execution view, re-hashes selector427, re-verifies both package manifests, and emits a self-excluding result manifest plus complete process ledger/raw logs.

## 3. Timeout correction and static verification

The corrected execution plane is GitHub Actions, not a foreground ChatGPT container execution call. The workload caller contains no `timeout-minutes` field, and the harness contains no shell `timeout`/watchdog invocation. The caller itself fail-closes if such a token appears in the harness before execution.

Static checks on the durable bytes establish:

- `bash -n` succeeds for the harness;
- exact CB4/CB5 artifact IDs and frozen provider/source/archive/manifest hashes are embedded;
- selector hash/cardinality and owner census are frozen;
- the exact four focus identities and owner routing are frozen;
- semantic nonzero exits are classified and recorded without shell `errexit` truncation;
- the combined ledger is required to contain exactly 431 rows;
- immutable postflight and manifest re-verification are mandatory whenever runtime starts;
- result and diagnostic artifacts are uploaded under `if: always()`.

The temporary validation carrier initially exposed an observer permission-ceiling mismatch. After correcting that carrier only, run `35441822764` completed successfully. The exact R1 caller draft was then validated through `agent-workflow-schema-validator-reusable.yml` in run `35441895809`, conclusion **success**. Fresh source snapshot run `35442292005` re-captured the durable payload bytes with `runtimeExecution=false`; local verification re-hashed the harness/caller to the values above.

## 4. Runtime boundary

CB6 executed **no generated Directional binary**, no compile, no configure, no relink, no benchmark, no package rebuild/repackage, and no semantic test process. Therefore CB6 creates no runtime credit, package promotion, regression-accounting change, or debt discharge.

The two interrupted TB2 attempts remain audit-only and contribute zero process rows to successor acceptance.

## 5. Closeout disposition

CB6's control defect is corrected and statically verified. Exact successor is **`M4-CP4-TB2-R1-EXEC`**. R1 must install the exact validated caller bytes, keep workflow-install and trigger commits separate, and run the complete 431-process gate from ordinal 1 on the unchanged immutable CB4+CB5 composite. It may not resume either invalid TB2 attempt.

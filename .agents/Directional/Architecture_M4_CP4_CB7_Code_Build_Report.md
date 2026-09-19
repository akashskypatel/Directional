# M4-CP4-CB7 — Code + Build report

**Turn:** `M4-CP4-CB7`
**Result:** **COMPLETE / CONTROL-PLANE CORRECTION GREEN / RUNTIME-FREE**
**Successful successor:** `M4-CP4-TB2-R2-EXEC`

## 1. Scope and frozen authority

CB7 corrects only the reusable-workflow caller permission ceiling that made R1 run `35444642320` terminate with `startup_failure` before job construction. It changes no product, test, fixture, selector, CMake, package, accepted-runtime, regression-accounting or debt semantics.

Frozen runtime inputs remain exactly:

- full CB4 artifact `10578784752`, source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`;
- CB5 delta artifact `10582435470`, source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`;
- harness `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-harness.sh`, mode `755`, 30,249 bytes, SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`;
- selector427 at 427 LF rows / 34,783 bytes / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- owner census **30 / 281 / 75 / 41**, the four M4-owned focused rows and CB4/CB5 composite routing;
- benchmark count zero and all configure/compile/relink/discovery/repair/mutation counters zero.

Accepted M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 2. Authorized correction

Commit `bbb64a7923900c0b0ce8c52680ef4588b85c691a` changes exactly one line in the durable caller draft: top-level `contents: read` becomes `contents: write`. `actions: read`, `issues: write`, `pull-requests: write`, `commit_run_file: false`, trigger path, workload, harness hash and all semantic execution rules remain byte-unchanged.

Corrected durable caller authority is:

- `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-caller-draft.yml`;
- mode `644`;
- 5,532 bytes;
- SHA-256 `488326cd8cbf1ee4078796b8ecd7031f578b87272eb62df5fa2d7d42fd42d719`.

The R1 caller SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c` remains invalid-attempt provenance only.

## 3. Static verification

Final validation run `35446771294` at event SHA `d5a47d338e52d7aaef7825deb236ca7780a5c0cd` is GREEN. Its reusable schema-validator job validates the corrected durable caller, and its independent `static-check` job verifies:

- exact caller permissions `actions: read / contents: write / issues: write / pull-requests: write`;
- observer reusable `branch-file` maximum ceiling `contents: write`;
- `commit_run_file: false` remains frozen;
- corrected caller SHA-256 `488326cd8cbf1ee4078796b8ecd7031f578b87272eb62df5fa2d7d42fd42d719`;
- unchanged harness SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`;
- no workload `timeout-minutes` field and no harness shell `timeout`/watchdog.

Static receipt artifact `10585314838` has provider SHA-256 `62b8b3aeceafdc1ca96d00484ed2c839c3fcd8fb8e67dc2de07ac88e2ae1ce55` and records `static_permission_ceiling_valid=true`. Closeout source snapshot run `35447156743` at event SHA `582f572265da47098eb533258e930d9eec88f6a6` succeeds with `runtimeExecution=false`; source artifact `10584734731` has provider SHA-256 `c0be9328ba17da8f71660a42410579dc2ea7e7ed70176b9d9c7e520e6f0c97c9`.

The temporary validator required two bounded detector corrections before the final green run: the static timeout check now detects actual YAML `timeout-minutes:` fields rather than harmless explanatory string literals. Those validator-only edits do not change the successor caller or harness.

## 4. Runtime boundary and disposition

CB7 executes **no generated Directional binary**, no configure, compile, relink, benchmark, package acquisition for semantic execution, rebuild or repackage. Therefore CB7 creates no runtime credit, package promotion, regression-accounting change or debt discharge.

R1 run `35444642320` remains **ORCHESTRATION INVALID / NO SEMANTIC LEDGER / NON-STABLE** with zero jobs and zero credit. The earlier TB2 interrupted attempts likewise remain audit-only.

## 5. Successor

Exact successor is immutable artifact-only **`M4-CP4-TB2-R2-EXEC`**. R2 must install the corrected caller bytes exactly, re-prove installed hash/schema/permission ceiling, and execute the complete frozen gate as **431 fresh processes from ordinal 1** against the unchanged CB4+CB5 composite. It may not resume or import rows from any TB2/R1 invalid attempt. Any orchestration-valid semantic result routes to mandatory runtime-free `M4-CP4-TB2-R2-REV`.

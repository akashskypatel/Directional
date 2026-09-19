# M4-CP4-CB7 — R1 caller permission-ceiling orchestration correction plan

**Turn type:** Code + Build / control-plane-only / runtime-free
**Authorized by:** `M4-CP4-TB2-R1-EXEC` orchestration-invalid closeout
**Semantic scope:** no product, test, fixture, selector, CMake, package or accepted-runtime change

## 1. Purpose

Correct only the GitHub Actions caller permission ceiling that caused R1 run `35444642320` to terminate with `startup_failure` before any job instantiated. The frozen immutable packages, harness, selector and semantic gate remain reusable and must not be rebuilt, repackaged or otherwise changed.

## 2. Frozen authorities

Preserve exactly:

- CB4 artifact `10578784752`, source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`;
- CB5 delta artifact `10582435470`, source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`;
- harness `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-harness.sh`, mode `755`, SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`;
- selector427 at 427 LF rows / 34,783 bytes / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- owner census **30 / 281 / 75 / 41**, exact four-row focus set and CB4/CB5 routing;
- benchmark count zero and all build/repair/mutation/discovery counters zero.

The failed R1 caller SHA-256 `88ab6b51201801f2468add9b3f1ee4ad890c751052c48b1a7c0e9f773af8699c` remains invalid-attempt provenance only.

## 3. Authorized correction

Change only the successor caller control contract required to satisfy reusable-workflow permissions:

1. raise the caller's top-level `contents` permission ceiling from `read` to `write`, matching the maximum `contents: write` ceiling declared by the optional `branch-file` job in `agent-run-observer-reusable.yml`;
2. do not enable `commit_run_file`; the permission is a static reusable-workflow ceiling, not authorization to create a branch observation file;
3. leave `actions: read`, `issues: write`, `pull-requests: write`, the runtime workload, harness hash, triggers, process order and semantic gate unchanged;
4. derive and record the corrected caller SHA-256 and preserve exact byte identity between the durable draft and later temporary installed caller;
5. schema-validate the corrected caller and statically verify caller-vs-called-workflow permission ceilings before any successor runtime is authorized.

Do not change reusable-workflow permissions themselves.

## 4. Verification boundary

CB7 may publish/validate control-plane YAML and static receipts only. It executes **no generated Directional binary**, no configure, compile, relink, benchmark, package download for semantic execution, rebuild or repackage.

CB7 is complete only when evidence proves:

- the corrected caller satisfies the observer reusable's maximum declared permission ceiling;
- caller/harness byte hashes and modes are frozen;
- there is no full-suite `timeout-minutes`, shell `timeout` or watchdog;
- CB4/CB5 artifact identities, selector427, focus set and 30/281/75/41 routing are unchanged;
- the R1 `startup_failure` remains zero-credit audit provenance;
- no Directional runtime or compile occurred.

## 5. Successor

Exact successful successor is **`M4-CP4-TB2-R2-EXEC`**. R2 re-runs all **431 fresh processes from ordinal 1** against the unchanged immutable CB4+CB5 composite. It may not resume or import rows from TB2 or R1 invalid attempts. Any orchestration-valid semantic R2 result routes to mandatory runtime-free Review.

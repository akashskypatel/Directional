# M4-CP3-TB4 Artifact-Only Test + Benchmark Plan — corrected exact-torus hard-rail witness

**Status:** FROZEN BY `M4-CP3-CB6` AFTER BUILD GREEN
**Execution turn:** `M4-CP3-TB4-EXEC`
**Review turn:** `M4-CP3-TB4-REV`
**Package source:** `9d66fcebe4b91ab74a6d0234c46643a2723ab643`
**Package run/job:** `34673625938 / 103499484128`
**Package artifact:** `10292005428`
**Package artifact SHA-256:** `7723188540182f9515b95efd83c13dd1dbc6f0813532a98cd8df0778a12a882f`
**Accepted predecessor selector403:** `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`
**Candidate selector408:** `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`

## 1. Turn boundary

`M4-CP3-TB4-EXEC` is immutable **artifact-only runtime execution**. Consume only package artifact `10292005428`; do not configure, compile, relink, regenerate discovery/code, alter source/fixtures/manifests, repair permissions, or execute an unpackaged binary.

Extract with a normal archive tool that preserves executable mode bits. Python `zipfile.extractall` is forbidden for executable payloads. Missing executable mode is orchestration RED, not permission to `chmod` the package.

`TB4-EXEC` records mechanical evidence only. It may not promote the package, close CP3, alter stable regression accounting, or diagnose a red result. `TB4-REV` independently re-opens package/results and owns acceptance, regression classification, CP3 disposition, document consolidation, and successor planning.

## 2. Immutable preflight

Before any produced binary executes, verify and record all of the following:

1. downloaded artifact ID `10292005428` and outer SHA-256 `7723188540182f9515b95efd83c13dd1dbc6f0813532a98cd8df0778a12a882f`;
2. package metadata source `9d66fcebe4b91ab74a6d0234c46643a2723ab643`, build `runtimeExecution=false`, and compile exit `0`;
3. package `SHA256SUMS` hash `26529a4d12434bc737e4952f09f9790dd8f36d4151e1500154fa7a60497101af`, exactly 28 entries, and recursive self-check success;
4. source archive SHA-256 `3c82e4778ec4ea4631e25d39ed18f7f7ed68a2a24a1ad08e3ebfe298dfe331a9`;
5. the four selector-owner executables are present and executable without mutation: authority-kernel, producer, completion, validation;
6. accepted selector403 is byte-identical at SHA `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
7. candidate selector408 is byte-identical at SHA `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` with exactly 408 LF identities;
8. candidate rows1-403 are byte-identical to accepted selector403;
9. all 408 identities map uniquely to packaged executables with static owner partition **30 / 262 / 75 / 41**, zero missing/ambiguous identities, and row408 producer-owned;
10. packaged row408 identity remains exactly `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity` and its source contains the CB6 explicit hard-rail helper/path;
11. no build tree, compiler invocation, CMake configure, generated discovery state, package edit, or permission repair is introduced by TB.

Any failed preflight item is orchestration RED. Do not execute the semantic gate after immutable package authority fails.

## 3. Frozen fresh-process gate — exactly 821 processes

Each process must use one exact fully qualified GTest identity and must select exactly one test. Zero selection, multiple selection, skip, crash, timeout, or nonzero exit is RED. Do not use a broad filter that selects multiple tests in one process.

Execute from the beginning in this exact phase order:

### A. Corrected row408 focused pass A — 1 process

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

Record enough output to prove the row's own assertions reached the corrected witness: authoritative rails non-empty, at least one hard-feature rail, retained topology/baseline/trace authority, `phaseFront=Produced`, exact A2b/A3 conformity digests, at least one `HardRail` edge, exact shared interval on every hard-rail edge, and no `InvalidHardRailPairing` terminal detail.

### B. Corrected row408 focused pass B — 1 fresh process

Execute the same identity again in a new process. Require the same pass/fail result and deterministic semantic evidence.

### C. Rows404-407 collateral controls — 8 fresh processes

Execute each of rows404-407 once in pass A and once again in pass B, preserving selector order within each pass:

404. `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt`
405. `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals`
406. `SurfaceCellAuthorityContractCutover.ExactSharedBoundaryIntervalRejectsMissingOrTamperedIdentityWithoutFallback`
407. `SurfaceCellAuthorityContractCutover.A3SharedBoundaryCutoverPreservesA4LocalFamilyAndAdvanceSign`

### D. Accepted selector403 — 403 fresh processes

Execute all 403 accepted identities in selector order, one exact identity per process. Required result: **403/403 PASS**, no skips/timeouts/crashes.

### E. Candidate selector408 — 408 fresh processes

Execute all 408 candidate identities in selector order, one exact identity per process. Required result: **408/408 PASS**, no skips/timeouts/crashes.

Total fresh exact-filter processes: `1 + 1 + 8 + 403 + 408 = 821`.

## 4. Fail-fast rule

Stop the semantic gate at the first RED process and preserve the exact phase, ordinal/identity, owner executable, exit status, stdout/stderr, elapsed time, and already-completed process ledger. Do not diagnose or repair during `TB4-EXEC`.

A RED focused row408 must stop before controls/selectors. A RED control must stop before cumulative selectors. A RED selector403 must stop before selector408. No partial phase may be reported as a completed later phase.

## 5. Runtime constraints

- Use the immutable package binaries only.
- No rebuild/reconfigure/relink/discovery generation.
- No package mutation or `chmod` repair.
- No local source checkout as executable authority.
- Do not impose an arbitrary timeout on the complete gate merely to save agent time. If infrastructure itself terminates a process, record that as RED/orchestration evidence.
- Preserve exact fresh-process semantics; process reuse is not allowed.

## 6. Mandatory postflight

After the semantic gate, regardless of PASS or fail-fast RED:

1. re-run the full package `SHA256SUMS` check;
2. re-hash selector403 and selector408;
3. re-hash the source archive;
4. verify executable modes are unchanged;
5. verify no packaged source/metadata/binary timestamp/content was modified by the gate where the archive representation permits that check;
6. record total process count and phase counts actually executed;
7. upload the complete execution ledger, stdout/stderr evidence, immutable pre/postflight record, and machine-readable summary as workflow artifacts.

A postflight authority failure invalidates semantic promotion even if every test process passed.

## 7. Mechanical TB4-EXEC exit states

`TB4-EXEC` may report only one of:

- **GREEN:** all 821 processes PASS and immutable postflight passes;
- **SEMANTIC RED:** immutable preflight passed, at least one test process failed/skipped/crashed/timed out/nonselected/multiselected, fail-fast honored, immutable postflight preserved;
- **ORCHESTRATION RED:** immutable package authority/preflight/postflight or execution mechanics failed.

It must not classify root cause, promote selector408, or close CP3.

## 8. Review obligations

`M4-CP3-TB4-REV` must independently verify package authority, process cardinality, exact-filter selection, row408 non-vacuity, rows404-407 collateral controls, accepted selector403, candidate selector408, and postflight immutability.

Only Review may decide whether:

- CB6 corrected the fixture precondition without changing product semantics;
- the production torus path carrying shared hard-rail authority completes without `InvalidHardRailPairing`;
- selector408/package `10292005428` is promotable;
- `G4-B002` and M4-CP3 may close or another bounded corrective turn is required;
- stable regression accounting changes.

No later checkpoint begins before that Review disposition.

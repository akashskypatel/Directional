# M4-CP3-TB8 Artifact-Only Test + Benchmark Plan — verify CB10 hard-rail fixture authority and census the accepted prefix

**Turn chain:** `M4-CP3-TB8-EXEC` → `M4-CP3-TB8-REV`
**Type:** immutable artifact-only runtime execution, then independent review/adjudication
**Candidate source:** `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`
**Candidate package:** compile artifact `10307919492`
**Package provider digest:** `8988a12fa8b2e6476bf3fd91a6a6936eaef8a9ab7c73837b74ea2e980d29b2ec`
**Accepted runtime authority entering:** corrected R4 artifact `10289601000`, selector403 **403/403**

## 1. Immutable authority

TB8-EXEC must execute the packaged CB10 binaries directly. It must not configure, compile, relink, regenerate, discover replacement binaries, edit source/tests/fixtures/selectors, repair the package, or mutate package bytes/modes.

Frozen selector authority:

- selector403: `.agents/Directional/Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt`, SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, 403 identities;
- selector408: `.agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt`, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`, 408 identities.

The package was compile-green with `runtimeExecution=false`; runtime acceptance is wholly owned by TB8 Review.

## 2. Preflight

Before executing any Directional identity, TB8-EXEC must prove:

1. downloaded artifact ID/digest exactly match the frozen package;
2. root `SHA256SUMS` verifies **28/28**;
3. metadata/source authority names exact semantic source `1611e9ef57bd1437b4422ab2fca7acef20b19a3a`;
4. packaged source archive and manifest agree with that source;
5. source-status before/after/final snapshots are empty;
6. exact arithmetic metadata proves GMP/GMPXX;
7. selector403/408 bytes, counts and hashes match the frozen values;
8. required packaged binaries are executable and their byte+mode census is recorded;
9. no package mutation occurs while establishing the execution view.

If package/source integrity fails, stop before semantic runtime and return the mechanical failure to Review. A semantic test RED does **not** authorize package repair.

## 3. Execution ledger

Every invocation must be a fresh process using an exact test identity/filter. Record process number, identity/ordinal, selected-test count, exit status, PASS/RED/SKIP/crash/timeout classification, and concise failure text. Exact selection count must be one for focused/ordinal/row processes.

### A. Six corrected shared-fixture identities — focused A/B

Execute each identity twice in independent fresh processes:

- ordinal211 `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected`;
- ordinal217 `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- ordinal219 `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected`;
- ordinal227 `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed`;
- ordinal230 `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed`;
- ordinal231 `SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity`.

Required focused result for promotion: **12/12 GREEN**. These processes must demonstrate that the production-backed fixture itself reaches `Produced` before each test applies its existing intended tamper/oracle.

### B. Earlier recovered discriminator — ordinal138 A/B

Run accepted selector403 ordinal138 twice. Required for promotion: **2/2 GREEN**.

### C. New torus witness — row408 A/B

Run selector408 row408 twice. Required for promotion: **2/2 GREEN**.

### D. Candidate rows404-407 A/B

Run rows404, 405, 406 and 407 twice each. Required for promotion: **8/8 GREEN**. Fail-fast may be used within this candidate-only block after an authoritative RED, but all completed processes must still be recorded.

### E. Accepted selector403 cumulative census — mandatory non-fail-fast

Execute **all 403 accepted identities to completion**, one fresh process per identity, even if one or more accepted identities RED.

This phase is explicitly **non-fail-fast for semantic test failures**. The result must publish the complete accepted-prefix RED set as exact `(ordinal, identity, reason)` tuples. Only infrastructure/package-integrity failure, crash preventing further execution, or detected package mutation may abort the accepted-prefix census.

Promotion requires **403/403 GREEN**. Any accepted RED keeps the CB10 package unpromoted and must be classified by TB8 Review; the complete RED census is still required.

### F. Selector408 cumulative candidate gate

Execute selector408 from ordinal1 through ordinal408 in fresh processes. Accepted ordinals1-403 must remain non-fail-fast so the accepted-prefix census cannot be truncated. Candidate rows404-408 may use fail-fast after the accepted prefix is complete.

Promotion requires **408/408 GREEN**.

## 4. Postflight immutability

After runtime, repeat the authoritative package/source/execution-view byte+mode census and prove equality with preflight. Re-run root `SHA256SUMS` and selector hashes. Any package mutation invalidates semantic conclusions and is a mechanical RED.

## 5. EXEC boundary

`M4-CP3-TB8-EXEC` is mechanical runtime execution only. It must not:

- classify root cause;
- promote/reject the package semantically;
- close/reopen stable events;
- edit product/test/fixture/selector authority;
- change accepted runtime authority;
- choose a corrective implementation.

It reports the exact process ledger, focused counts, complete selector403 RED census, selector408 outcome, and immutable postflight.

## 6. Mandatory Review successor

`M4-CP3-TB8-REV` must independently review the immutable package, execution ledger, complete accepted-prefix census and postflight before any promotion or next CB decision.

Review may promote the CB10 candidate only if all required focused gates and selector408 are GREEN and immutable pre/postflight is exact. If any accepted identity REDs, Review must classify each observed accepted-prefix regression before authorizing a successor implementation. One-defect-per-cycle fail-fast must not be reintroduced for the accepted selector403 prefix.

No new benchmark/performance acceptance gate is introduced by CB10; execute only benchmark activity already explicitly required by frozen CP3 authority. Otherwise TB8 is test/runtime validation of the immutable package.

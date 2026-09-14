# M4-CP-COND-TB4 artifact-only Test + Benchmark plan

**Status:** frozen successor plan authored by `M4-CP-COND-CB4`; execute only after CB4 compile/package GREEN.

**Turn type:** Test + Benchmark / immutable artifact only / runtime execution allowed / no rebuild or mutation.

## 1. Authority

TB4 consumes exactly the immutable compile/package artifact produced by `M4-CP-COND-CB4`. It must verify the packaged source SHA, selector422 bytes, selector408 predecessor bytes, executable owner set, GMP/GMPXX linkage evidence, checksums/modes, clean-source receipts, and `runtimeExecution=false` before launching any Directional process.

Accepted predecessor runtime authority remains CP3 package `10307919492` / selector408 until mandatory TB4 Review promotes a successor. TB4-EXEC is mechanical evidence only and may not close CP-COND.

## 2. Immutable preflight

Before runtime:

1. Verify the outer artifact digest and every packaged checksum/mode receipt.
2. Verify the packaged source SHA exactly matches the CB4 compile source authority and source status is clean.
3. Verify selector408 is exactly 408 LF rows / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.
4. Verify selector422 is exactly 422 LF rows / `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`.
5. Verify selector422 rows 1-408 are byte-identical to packaged selector408.
6. Verify rows 409-422 are exactly the fourteen CP-COND identities frozen by the CB4 plan, in order.
7. Verify `InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` is absent from selector422.
8. Verify the packaged owner executables exist for all four selector partitions plus compiled API/core/pipeline support and required runtime libraries.
9. Verify GMP/GMPXX exact-arithmetic evidence and reject any fallback package.
10. Verify the package states `runtimeExecution=false`; any evidence of CB4 runtime is a package-boundary RED.
11. Record immutable byte+mode censuses for package, source archive, selectors, and execution view for exact postflight comparison.

Any preflight failure stops before Directional runtime and is reported as package/authority RED.

## 3. Authoritative execution surface

Launch **423 fresh processes** from the immutable package only:

- Processes 1-422: one exact-filter process for each selector422 row, in selector order.
- Process 423: one exact-filter process for `InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker`, expected **SKIP** and report-only/non-selector.

Each process must select exactly one intended test identity. Generated discovery, enumeration, list/help/version probes, rebuilds, relinks, source edits, fixture edits, selector edits, and package repair are prohibited.

## 4. Required GREEN receipts

TB4-EXEC is mechanically GREEN only if all are true:

- selector422: **422/422 PASS**;
- inherited rows 1-408: **408/408 PASS**;
- appended rows 409-422: **14/14 PASS**;
- report-only boundary process: **1 expected SKIP** and remains outside selector422;
- gating total: **422/422 PASS**;
- total launched Directional processes: **423**;
- zero gating RED;
- zero crash;
- zero timeout;
- zero actual-selection mismatch;
- no rebuild/configure/relink/mutation;
- package/source/selector/execution-view postflight exactly equals preflight byte+mode census.

A report-only boundary SKIP is not selector credit and does not satisfy frozen CP-COND conjunct 4. It is carried to Review exactly as a named unresolved blocker unless independent authority proves the alternate frozen condition.

## 5. Evidence rules

Produce deterministic process and summary ledgers that record ordinal, requested identity, actual selected identity, exit status, PASS/RED/SKIP classification, duration, executable owner, and immutable package identity.

The checksum manifest must be **non-self-referential**: generate checksums over all substantive evidence files first and do not include the checksum output itself in its own input set. `sha256sum -c` over the published manifest must pass without special-casing.

Publish:

- exact artifact/source/selector identities;
- package preflight result;
- 423-process ledger and aggregate counts;
- immutable postflight comparison;
- non-self-referential evidence checksum manifest;
- concise TB4-EXEC report.

## 6. Stop and successor

TB4-EXEC must not promote the CB4 package or selector422, modify the repository, rebuild, repair, or close CP-COND.

On mechanical completion, the mandatory successor is **`M4-CP-COND-TB4-REV`**. Review must independently reopen the immutable package/evidence bytes, adjudicate cumulative selector authority and frozen CP-COND exit conjuncts, and only then may it promote selector422/package authority or close CP-COND.

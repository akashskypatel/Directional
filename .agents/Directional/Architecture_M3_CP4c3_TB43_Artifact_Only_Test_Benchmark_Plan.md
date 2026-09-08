# M3-CP4c-3-TB43 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN BY CB48 / NOT YET EXECUTED
**Canonical turn:** Test + Benchmark / artifact-only execution
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Definition authority:** `M3_CP4c_Frozen_Definitions.md` Part XII
**Immutable package:** package108 artifact `10076272909` / `m3-cp4c3-cb48-package108-result-34276935866`
**Package artifact digest:** `sha256:a2578a82e82c3e1bdc5798e0bf96028e3e854ccbeb65c7a111a6489fa1593612`
**Exact semantic source:** `531b517fb129425f113b5f811215f1d2b1939ee2`
**Packaged source archive SHA-256:** `2bce00134c172973225bbe44e87a2708477bde5fed2d531b8d0b9636945fb7c3`
**Compile provenance:** run `34276935866`, package job `102233583990`
**Selector:** 409 identities, SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`

## 1. Purpose and boundary

TB43 is the first runtime measurement of the CB48 Part XII implementation. It is **artifact-only**. It must not
configure, compile, relink, regenerate discovery/code, modify packaged source/tests/fixtures/selectors, repair
package contents or permissions, or benchmark. It consumes package108 exactly as produced by CB48.

TB43-EXEC records raw execution facts only. It does not interpret failures, reprice stable accounting, weaken a
gate, patch the package, or authorize implementation. A semantic RED routes to independent
`M3-CP4c-3-TB43-REV` under the normal cadence.

## 2. Immutable package preflight

Before any Directional runtime starts:

1. download package artifact `10076272909` exactly once and verify provider SHA-256
   `a2578a82e82c3e1bdc5798e0bf96028e3e854ccbeb65c7a111a6489fa1593612`;
2. extract the archive with a mode-preserving ordinary archive tool. Do **not** use Python `zipfile.extractall` for
   executable payloads, and do not `chmod` or otherwise repair mode bits after extraction;
3. verify the package's recursive self-excluding `SHA256SUMS` exactly; CB48 produced **28/28** root entries;
4. verify package source identity is exactly `531b517fb129425f113b5f811215f1d2b1939ee2` and packaged source archive
   SHA-256 is `2bce00134c172973225bbe44e87a2708477bde5fed2d531b8d0b9636945fb7c3`;
5. verify `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and authoritative
   link evidence includes both GMPXX and GMP;
6. verify selector409 is exactly
   `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e` and contains exactly 409 identities;
7. verify the accepted 1–365 selector prefix is unchanged from the current accepted authority;
8. verify no source, test, fixture, selector, executable-mode, or package byte changed during preflight.

Any package/hash/source/selector/mode mismatch is orchestration failure. It is never permission to repair the
immutable package or to continue with partial semantic evidence.

## 3. Execution contract

Execute the full selector409 gate in ordinal order with **one identity per fresh process** and every mutation/recovery
flag false. Every selector identity must run exactly once. Zero-selected filters, duplicate execution, omitted
identities, or stitched partial runs invalidate the attempt.

The repository must impose **no elapsed-time cutoff** on the complete 409-identity gate. Do not wrap the full gate
in `timeout`, do not use a job timeout intended to terminate it, and do not partition/retry merely to evade elapsed
runtime. Platform-level failure or explicit human cancellation is orchestration/infrastructure failure, not
semantic evidence.

No benchmark runs in TB43.

## 4. Frozen accepted/control obligations

The accepted prefix must remain **365/365**. In particular, ordinals
**311/312/314/315/356/357/404/408/409** remain frozen controls. Any accepted-prefix regression is a hard falsifier
and must be preserved exactly for review; EXEC may not weaken or bypass it.

Selector409 bytes are immutable for this TB.

## 5. Protected Part XII obligations — 390/393/406/407

For each protected identity, raw output must prove the Part XII oracle actually executed:

- `branch=UncutCensus`;
- `censusPredicateExecuted=yes`;
- `sameDomainCorruptionRejected=yes`;
- terminal subject relation is one of the typed values and, on the standing mechanical witness, is expected
  `Outside`;
- the producer census predicate is evaluated on real `P_U` rows, independently of the terminal failure subject;
- when the RegionCertification evidence branch is applicable, the exact failing-face owner-orbit set and expected
  orbit membership are present.

A PASS lacking these receipts is an invalid gate result because it permits a skipped oracle to masquerade as
recovery. A deliberately corrupted same-domain census being accepted is a semantic RED/falsifier, not a reason to
remove the negative.

## 6. Carried failure owners

CB48 deliberately did not correct the following owners:

- 366/367: `RegionSourceFaceOwningFragmentMissing`; the new exact owner-orbit relation is observation only;
- 368/369/370: prescribed-sphere upstream surfaces under their existing owners;
- 374: folded-cone field/admissibility owner;
- 398: its existing prescribed-sphere owner.

If any carried identity changes color or failure locus, preserve the exact evidence and route interpretation to
review. Do not force the expected vector by modifying package bytes, selector membership, fixtures, or assertions.

## 7. Frozen falsifier, not a synthesized result

If CB48 repaired only the protected census-domain oracle and every carried owner remains unchanged, the expected
TB43 vector is:

- **402 PASS / 7 RED / 0 SKIP**;
- accepted **365/365**;
- RED `[366,367,368,369,370,374,398]`;
- 390/393/406/407 PASS only with their non-vacuity receipts and same-domain corruption rejection.

This is a **falsifier**. TB43 must measure it; EXEC must not print or promote it as though it were pre-established.

## 8. Evidence and immutable postflight

Preserve:

- run and workload job IDs;
- exact package/source/selector identities;
- one raw log per identity or an equivalently lossless fresh-process evidence surface;
- aggregate PASS/RED/SKIP counts and exact RED ordinal list derived from process exit status plus terminal evidence;
- accepted-prefix count;
- protected Part XII receipts for 390/393/406/407;
- complete failure-detail rows for every RED identity;
- pre/post package byte+mode census proving package immutability.

After execution, re-run the package integrity census without modifying package bytes. Any postflight mutation makes
the attempt invalid.

## 9. Turn termination

TB43-EXEC ends after preserving raw artifact-only evidence and updating the regression tracker intake required for
every observed regression. It makes no semantic promotion or corrective plan.

- If the gate is fully green, normal checkpoint closure rules apply.
- If any semantic RED remains — including the standing expected seven — the exact successor is independent
  `M3-CP4c-3-TB43-REV`.
- Orchestration failure instead routes to the bounded orchestration-correction CB edge; it is not semantic RED.

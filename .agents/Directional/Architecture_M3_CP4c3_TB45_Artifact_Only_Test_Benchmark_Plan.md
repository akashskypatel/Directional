# M3-CP4c-3-TB45 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN / EXACT SUCCESSOR / ARTIFACT-ONLY
**Turn:** `M3-CP4c-3-TB45-EXEC`
**Canonical turn:** Test + Benchmark
**Subturn:** TB-EXEC
**Authoring source:** `M3-CP4c-3-CB50`
**Runtime build/repair:** FORBIDDEN

## 1. Immutable authorities

TB45-EXEC consumes, without rebuild or repair:

- semantic source: `46554ef2bc1b36fff100e4de0a274a0fb6d3f26d`;
- immutable package110 artifact: `10095738820`,
  `m3-cp4c3-cb50-package110-result-34330825605`;
- package provider SHA-256: `7edc47632dbd863508c97d5716dd9df5e469671e0b327a133848ff3c37142000`;
- packaged source archive SHA-256: `8ae8fcd115c5b150642ad090272a001de89520d28ba69c2564cd476473374e80`;
- compile run/job: `34330825605 / 102398794843`;
- compile log artifact: `10095739319`;
- selector409:
  `.agents/Directional/Architecture_M3_CP4c3_Required_Green_Selector_409.txt`;
- selector409 SHA-256: `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
- unchanged generic artifact-only harness SHA-256: `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`;
- accepted-prefix selector count: **365**.

Before runtime, verify the downloaded artifact digest, all **28/28** package `SHA256SUMS`, source commit, executable
modes, selector409 digest, harness digest and `metadata/command-boundary.txt` containing
`runtimeExecution=false` and `exactArithmeticBackend=GMP`.

A mismatch is orchestration failure. Do not repair bytes, modes, paths, selectors or binaries.

## 2. Immutable execution boundary

TB45-EXEC may execute only the packaged binaries and packaged/source fixtures required by selector409. It must not:

- configure, compile, relink or regenerate discovery;
- modify source, tests, fixtures, selectors, package files or executable modes;
- replace the compiled source revision;
- add exploratory runtime outside this plan;
- run benchmarks unless selector409 itself explicitly selects one (the current selector does not);
- interpret or plan a fix. Semantic adjudication belongs to `M3-CP4c-3-TB45-REV`.

Use the same proven artifact-only execution model as TB44: one **fresh process per identity**, exact ordinal order,
real per-identity `timeout -k 5s 180s`, and **no outer elapsed-time cutoff** on the complete 409-identity gate.

## 3. Ordered execution

1. Download package artifact `10095738820` exactly once.
2. Verify provider digest and 28/28 recursive package manifest.
3. Materialize the packaged source archive in the execution view without editing it.
4. Verify selector409 and harness digests before the first runtime process.
5. Record pre-execution byte+mode censuses for package, source and execution view.
6. Execute selector ordinals **1 through 409 exactly once**, in order, each in a fresh process/work directory.
7. For every ordinal, record:
   - ordinal and exact selector row/test;
   - selected test count;
   - process exit;
   - timeout state;
   - complete stdout/stderr;
   - deterministic receipt/detail strings;
   - elapsed time when the existing harness records it.
8. Record post-execution byte+mode censuses and prove equality with pre-execution censuses.
9. Produce the raw pass/red/skip vector, accepted-prefix count, timeout count, selection-mismatch count, detail
   digests, ledger digest and failure-detail table digest.
10. Preserve raw result and persistent log artifacts. Do not promote the vector in EXEC.

Zero-selected or multi-selected rows are orchestration failures, never PASS/SKIP. A timeout is orchestration failure,
never semantic PASS/SKIP.

## 4. CB50 direct falsifiers

### 4.1 Ordinals 366 / 367 — fragment-corner per-source-corner projection

For each identity, retain full raw failure detail and count occurrences of:

- `FragmentCornerSourceCornerMismatch`;
- source face set `10,11,79`;
- `FragmentCornerRayOrdinalDuplicate`;
- `FragmentCornerOrbitChainMismatch`;
- any later fail-closed terminal surface.

**Required observation:** the TB44 `FragmentCornerSourceCornerMismatch` on source faces `10,11,79` must not
reproduce. PASS is acceptable; a later/different fail-closed guard is reviewable evidence. Reappearance of the same
whole-face/source-corner mismatch falsifies CB50.

Do not reinterpret a later guard in EXEC.

### 4.2 Ordinals 390 / 393 / 406 / 407 — typed terminal subject

Each identity must still prove non-vacuity before terminal evidence:

- `branch=UncutCensus`;
- `censusPredicateExecuted=yes`;
- `sameDomainCorruptionRejected=yes`;
- `terminalSubjectRelation=Outside`;
- `regionCertificationEvidenceBranchExecuted=yes`.

It must additionally publish a valid `terminalSubjectBranch`:

- `Region` only when current-region evidence is authoritatively present and valid; or
- `SourceFace` when no current region exists, with region-only owner/count fields absent.

`Unresolved`, fabricated region fields, a skipped producer predicate or a missing corruption rejection is RED even
if the terminal helper otherwise passes.

## 5. Frozen controls and carried owners

TB45-EXEC must separately report:

- accepted identities **1–365 = 365/365**;
- carried RED owners **368, 369, 370, 374, 398** without merging/repricing them;
- frozen controls **311, 312, 314, 315, 356, 357, 404, 408, 409**;
- ordinal 385 ownership publication, expected **300 established / 0 unavailable / 0 conflicting**;
- retired-code silence for:
  - `TraceArcDoesNotSeparateItsSides`;
  - `UncutFaceComponentOrbitSeedNotUnique`;
  - `RegionEulerCharacteristicNotOne`.

Selector409 bytes and all fixtures remain frozen.

## 6. Acceptance and stop rules

The TB45-EXEC workload is mechanically valid only when:

- all 409 identities execute exactly once;
- every row selects exactly one intended test;
- timeout count is zero;
- package/source/execution-view byte+mode censuses are unchanged;
- no configure/compile/relink/repair/mutation/benchmark action occurred;
- complete raw logs and result artifacts are uploaded.

Do **not** freeze or assert a synthetic expected aggregate. If all six CB50-targeted RED identities recover while
the five carried REDs remain, **404 PASS / 5 RED** is only the arithmetic consequence, not a pre-authored oracle.

A semantic RED does not authorize retry or repair in TB-EXEC. Preserve evidence and advance to independent
`M3-CP4c-3-TB45-REV`. An orchestration failure follows the project's retry rule and must not be promoted as
semantic evidence.

## 7. Required evidence package

The EXEC report must record:

- exact source/package/selector/harness identities and hashes;
- workflow run ID and artifact-only execute job ID;
- result/log artifact IDs and provider digests;
- all 409 per-identity outcomes;
- accepted-prefix result;
- selection and timeout counts;
- pre/post immutability censuses;
- 366/367 old-locus occurrence counts and new terminal detail;
- 390/393/406/407 non-vacuity + `terminalSubjectBranch` receipts;
- carried-owner and frozen-control outcomes;
- ownership census and retired-code counts.

No stable regression repricing or corrective plan occurs in TB45-EXEC.

## 8. Exact successor

After mechanically valid execution, exact next is **`M3-CP4c-3-TB45-REV`**, independent evidence-only review.
Stop the orchestrator at that independent-review boundary as required by the project orchestration policy.

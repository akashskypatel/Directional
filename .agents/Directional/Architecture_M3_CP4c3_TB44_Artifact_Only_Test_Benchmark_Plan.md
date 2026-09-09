# M3-CP4c-3-TB44 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN BY CB49 / NOT YET EXECUTED
**Canonical turn:** Test + Benchmark
**Exact subturn:** `M3-CP4c-3-TB44-EXEC`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Definition authority:** `M3_CP4c_Frozen_Definitions.md` Part VIII R4.1/R4.2, Part XI/Part XI-A, Part XII
**Immutable package:** package109 artifact `10081938891` /
`m3-cp4c3-cb49-result-34292599472`
**Package artifact SHA-256:** `285ee15784ea29468c367fa9e4778fd835f1e9582370fdcb26a5050a15c4d617`
**Exact semantic source:** `cf969597bda5c49e734b98db0c0165b421c4ee12`
**Packaged source archive SHA-256:** `7dead808562e8faf0a90e242532e2965bc9260f24505958eb5f242c19b1273ca`
**Compile provenance:** run `34292599472`, package job `102282385344`
**Selector:** 409 identities, SHA-256
`eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`
**Generic harness:** `.agents/Directional/tools/m3_cp4c3_artifact_only_harness.sh`,
frozen SHA-256 `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`

## 1. Purpose and boundary

TB44 is the first runtime measurement of the CB49 corner-incidence ownership correction.
It is **artifact-only**. It must not configure, compile, relink, regenerate
discovery/code, alter package contents or executable modes, modify source/tests/fixtures/
selectors, or repair the immutable package.

`TB44-EXEC` records raw execution facts and regression-tracker intake only. It does not
adjudicate a new failure, promote package109, reprice stable accounting, weaken a gate, or
plan a correction. The exact successor is independent `M3-CP4c-3-TB44-REV`.

No benchmark is authorized in TB44.

## 2. Immutable package preflight

Before any Directional runtime starts:

1. Download artifact `10081938891` exactly once and verify provider SHA-256
   `285ee15784ea29468c367fa9e4778fd835f1e9582370fdcb26a5050a15c4d617`.
2. Extract with an ordinary mode-preserving archive tool. Do **not** use Python
   `zipfile.extractall` for executable payloads and do not `chmod` or otherwise repair
   packaged permissions.
3. Verify the package's recursive self-excluding `SHA256SUMS` exactly; CB49 produced
   **28/28** root entries.
4. Verify exact source
   `cf969597bda5c49e734b98db0c0165b421c4ee12` and source-archive SHA-256
   `7dead808562e8faf0a90e242532e2965bc9260f24505958eb5f242c19b1273ca`.
5. Verify `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
   `exactArithmeticBackend=GMP`, and authoritative link evidence containing both GMPXX
   and GMP.
6. Verify selector409 is exactly
   `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`
   with exactly 409 identities and an unchanged accepted 1–365 prefix.
7. Verify the generic artifact-only harness bytes are exactly
   `aaadab351c0ba28a39c87aff1948f83ab0c4c71520662177e5cdf6fd08b30ed3`.
8. Verify package byte+mode census before runtime. No source, test, fixture, selector,
   executable mode, or package byte may change during preflight.

Any package/hash/source/selector/harness/mode mismatch is orchestration failure. It is
never permission to repair the package or continue with partial semantic evidence.

## 3. Timeout-control restoration — TB43 EF10.2

TB43's runner-temporary execution view removed the generic harness's per-identity timeout,
making the reported `timeout_count=0` vacuous. TB44 **restores the frozen generic harness
unchanged**.

The authoritative harness invocation is therefore its existing:

```text
timeout -k 5s 180s <one selector identity in one fresh process>
```

Requirements:

- Do not materialize a TB44 execution view that removes or bypasses this timeout.
- `timeout_count` must be measured from real per-identity execution and must be `0`.
- A 124/137 timeout is orchestration failure, never PASS, RED, or SKIP.
- This per-identity process bound does **not** authorize an elapsed-time cutoff on the
  complete selector409 gate. The outer complete gate must run without repository-imposed
  elapsed-time termination, partitioning, or stitched continuation.

This explicitly satisfies TB43-REV EF10.2.

## 4. Execution contract

Execute the complete selector409 gate in ordinal order:

- one identity per fresh process;
- each identity exactly once;
- all mutation/recovery flags false;
- no zero-selected filters, duplicate execution, omitted identities, or stitched partial
  runs;
- no package repair, rebuild, relink, selector regeneration, or test discovery execution.

The complete selector409 gate has no repository-imposed outer elapsed-time cutoff.
Platform service failure or explicit human cancellation is orchestration/infrastructure
failure, not semantic evidence.

## 5. Frozen accepted/control obligations

The accepted prefix must remain **365/365**. In particular, the frozen controls
311/312/314/315/356/357/404/408/409 must remain PASS under their unchanged assertions.

Any accepted-prefix regression is a hard scope falsifier and must be preserved exactly for
TB44-REV. EXEC may not weaken, skip, or re-author the control.

## 6. Direct CB49 falsifier — ordinals 366/367

TB43 measured both identities RED at the exact owner-missing locus:

- code: `RegionSourceFaceOwningFragmentMissing`;
- `sourceFace=10,11,79`;
- expected owner orbit `1`;
- complete present owner-orbit set `[2,3]`;
- expected-orbit membership false;
- local fragment / owner / expected-fragment counts `3/3/3`.

CB49 is falsified if either 366 or 367 reproduces this exact locus.

Legitimate measured outcomes are:

1. PASS; or
2. advancement to a later existing fail-closed guard.

If either identity advances, preserve the exact first downstream failure. In particular,
if `RegionInteriorVertexCornerOwnerMissing` becomes newly observable, record it exactly
for independent review. EXEC must not patch or reinterpret a downstream guard.

Do **not** freeze an aggregate `404 PASS / 5 RED` result. That is only the arithmetic
consequence if both identities go green and every other identity remains unchanged.

## 7. Protected Part XII controls — 390/393/406/407

Each must remain PASS and publish non-vacuity receipts proving:

- `branch=UncutCensus`;
- `censusPredicateExecuted=yes`;
- `terminalSubjectRelation=Outside`;
- `sameDomainCorruptionRejected=yes`;
- `regionCertificationEvidenceBranchExecuted=yes` when applicable;
- the producer census predicate executes on real `P_U` rows independently of the terminal
  failure subject.

A PASS lacking the receipts is invalid evidence, not recovery.

## 8. Carried RED scope controls

CB49 did not own the following failures. TB44 must preserve their current failure owners
and detailed semantic surfaces:

- **368** — prescribed-sphere cellularity path, currently
  `RotationSystemInconsistent -> TraceEventPositionInvalid`;
- **369** — prescribed-sphere saturation/quality owner with `saturationUsed=true`;
- **370** — prescribed-sphere empty-closed-surface expectation mismatch;
- **374** — folded-cone field/admissibility owner (`atlasBuild=false`);
- **398** — prescribed-sphere cellularity owner.

Any movement in one of these five identities falsifies the claimed CB49 scope and must be
preserved for TB44-REV. EXEC may not normalize the vector by changing inputs, filters, or
expectations.

## 9. Ownership and retired-code controls

The standing ownership census must remain:

```text
established=300
unavailable=0
conflicting=0
```

Retired-code/recovery/mutation evidence must remain silent under the frozen selector
configuration. Any change is a hard review input.

## 10. Ordered execution plan

### 10.1 Preflight

Perform §2 and §3 completely. Record package/provider/source/selector/harness identities,
28/28 manifest result, byte+mode census, executable-mode census, GMP/GMPXX evidence and
the active 180-second per-identity timeout control.

### 10.2 Full selector409 semantic gate

Run all 409 identities through the frozen generic harness in ordinal order, one fresh
process each. Preserve one raw stream per identity or an equivalently lossless evidence
surface plus process exit status.

### 10.3 Required derived evidence

Derive only from the actual process records:

- PASS / RED / SKIP totals;
- exact RED ordinal list;
- accepted-prefix result;
- selected/executed count and duplicate/zero-selected census;
- real timeout count;
- complete failure-detail rows for every RED identity;
- exact 366/367 terminal locus;
- Part XII receipts for 390/393/406/407;
- carried-owner evidence for 368/369/370/374/398;
- ownership 300/0/0 and retired-code silence.

Do not synthesize expected colors.

### 10.4 Immutable postflight

Re-run package checksum and byte+mode censuses without mutating the package. Preflight and
postflight must match exactly.

## 11. Regression-tracker intake

Before TB44-EXEC closes, categorize every observed regression in
`Regression_Root_Cause_Tracker.md` as required by project policy.

- Existing carried REDs may reference their existing stable/non-stable owners, but the
  TB44 observation must be recorded.
- A new or moved failure gets a candidate/non-stable intake unless evidence already
  justifies a stable event.
- EXEC records facts only; root-cause adjudication and corrective planning belong to
  TB44-REV.
- Stable historical totals must not be changed without review-quality evidence.

## 12. Evidence to preserve

Preserve at minimum:

- workflow run and workload job IDs;
- artifact ID/name/provider digest;
- exact source and source-archive digest;
- selector and harness digest;
- 28/28 package manifest verification;
- package pre/post byte+mode censuses;
- per-identity process evidence and exit status;
- aggregate result and exact RED ordinal list;
- accepted-prefix result;
- selected/executed/duplicate/zero-selected/timeout counts;
- protected Part XII receipts;
- complete failure-detail rows;
- ownership and retired-code evidence.

## 13. Stop and blocker conditions

Stop and classify as orchestration/infrastructure failure if:

- immutable package, source, selector, harness, checksum, or executable modes do not match;
- the frozen harness's per-identity timeout is absent/bypassed;
- any identity times out;
- selector execution is incomplete, duplicate, zero-selected, or out of contract;
- the package changes pre/post;
- execution requires rebuild, relink, permission repair, source/test/fixture mutation or
  selector regeneration.

A semantic RED is not an orchestration blocker. Preserve it and finish the contracted gate
unless the harness contract itself declares the attempt invalid.

## 14. Plan-defined reruns

- No semantic retry is authorized.
- Do not rerun a RED hoping for a different color.
- A diagnosed infrastructure/orchestration failure may be retried only after preserving
  the failed attempt and correcting the orchestration defect without changing package,
  selector, harness, tests, or semantic inputs.
- Do not partition or stitch runs to evade elapsed runtime.

## 15. Completion and handoff

TB44-EXEC is complete when every planned item has a recorded result or explicit
orchestration blocker, raw evidence is preserved, immutable postflight passes, and
regression-tracker intake is committed.

The exact successor is **independent `M3-CP4c-3-TB44-REV`**, regardless of the measured
color vector. EXEC does not promote package109, authorize a correction, or continue into
implementation.

# M3-CP4c-3-TB42 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN SUCCESSOR PLAN / EXECUTION-ONLY
**Canonical turn:** Test + Benchmark
**First subturn:** `M3-CP4c-3-TB42-EXEC`
**Successor boundary:** independent `M3-CP4c-3-TB42-REV` — stop the implementation loop there
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Evidence source:** `5dacce6019ea34316c48743f3033d2bb5c26281a`
**Immutable package artifact:** `10070788592` / `directional-m3-cp4c3-cb47-result-34262805758`
**Artifact digest:** `sha256:f3a936866dc0bc0a81ed7d6d06380836e98e5c32806ac5a8680cf4a0ab393114`
**Selector409 SHA-256:** `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`

## 1. Validation objective

Execute the CB47 package without configure, compile, relink, regeneration, patching, fixture mutation, selector mutation, or source mutation. CB47 is diagnostic-only. TB42 must determine the actual subject/domain of the protected region-frontier census while preserving all accepted and protected behavior.

The active question is deliberately narrow: for protected ordinals 390/393/406/407, does the frontier partition have a population, which existing locator reaches it, does the existing guard accept that locator, and is the failing source face/region represented in `componentByFace`?

TB42-EXEC gathers evidence only. It does not promote, redefine, weaken, correct, or reclassify the oracle. Independent TB42-REV owns the interpretation and the pre-named `M3-CP4c-3-DEFN-R8` decision.

## 2. Preconditions and artifact integrity

Before any runtime execution:

1. download the immutable package artifact `10070788592` exactly once;
2. verify artifact/source metadata names exact evidence source `5dacce6019ea34316c48743f3033d2bb5c26281a`;
3. verify root `SHA256SUMS` completely (`28/28` expected PASS entries);
4. verify packaged source status is empty;
5. verify `runtimeExecution=false` in compile metadata;
6. verify `exactArithmeticBackend=GMP` and preserved GMPXX+GMP link evidence;
7. verify selector409 has exactly 409 identities and SHA-256 `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`;
8. verify selector408 remains the byte-identical prefix expected by the package manifest;
9. use the packaged artifact-only harness and fixtures only; do not rebuild or regenerate anything.

Any source/artifact/checksum/selector/harness mismatch is an orchestration blocker, not a product failure. Stop and preserve evidence.

## 3. Ordered execution plan

### 3.1 Execute the required-green selector

Run all **409** selector identities exactly once, one fresh process per identity, using the same packaged artifact-only harness/environment contract as TB41. Do not merge multiple identities into one process and do not retry an unchanged deterministic result merely to seek a pass.

Preserve per-identity:

- exit status and PASS/RED result;
- stable failure code/stage;
- complete failure detail bytes;
- failure-locus diagnostics;
- source-face ownership census;
- all CB47 `regionFrontier*` measurement fields when present;
- deterministic digest/evidence identifiers used by the existing harness.

### 3.2 Accepted-prefix and recovered-anchor stop gates

The following are hard stop conditions:

- accepted ordinals **1–365 = 365/365 PASS**;
- ordinals **311, 314, 356, 357 PASS** through the content-derived canonical-cycle-anchor contract;
- ordinals **312, 315, 409 PASS**, preserving the production binding/content-anchor falsifiers;
- selector409 bytes unchanged.

If any accepted identity changes, stop TB42-EXEC after preserving the raw evidence. Do not continue to reinterpret later EC7 measurements as acceptance evidence.

### 3.3 Protected EC7 population/domain measurements

Ordinals **390, 393, 406, 407 are expected to remain RED** because CB47 added diagnostics only. For each, require the failure detail to publish:

- `unlabeledFaceCount`;
- `frontierPartitionComponentCount`;
- `ownerConsistencyRowCount`;
- `regionFrontierLocator` when any locator is available;
- `regionFrontierLocatorSurvivedGuard`;
- `regionFrontierFailureSourceFaceInPartition`;
- failing-region source-face total;
- failing-region source-face count present in `componentByFace`;
- existing `regionFrontierComponentCount`.

Preserve exact values per identity; do not collapse them to one representative row.

TB42-REV classification matrix, frozen here so EXEC does not invent interpretation:

| Observation | Review-owned interpretation path |
|---|---|
| `frontierPartitionComponentCount == 0` | The census has no subject. `DEFN-R8` decides whether frontier census is legitimate at `RegionCertification`; do not widen `unlabeledFaces` in EXEC. |
| population non-zero, no locator resolves | Domain/locator mismatch; review must identify which object is missing from locator authority. |
| locator resolves, guard is false | EC3's benign-guard premise is refuted; review re-derives guard/domain relationship. |
| locator resolves, guard true, but published component count remains zero | Diagnostic collection contradiction; preserve exact row and stop semantic inference. |
| measurement fields absent | CB47 evidence surface failed its contract; classify as implementation/evidence defect, not oracle success. |

A PASS of 390/393/406/407 is not expected and must be reviewed as a possible oracle weakening or changed control path before any promotion.

### 3.4 Related protected owners and controls

Require and record:

- ordinals **404 and 408 PASS**;
- source-face ownership **300 established / 0 unavailable / 0 conflicting**;
- ordinals **366/367** remain under `RegionSourceFaceOwningFragmentMissing` and preserve their source-face / owning-orbit / owner-census measurement unless the exact runtime proves a different pre-existing owner transition;
- ordinals **368/369/370/374/398** remain under their existing owners; TB42 does not correct them;
- retired proxy/legacy region-disc error codes remain absent where the current contract says they are retired;
- binding, content anchor, `region_orbit`, and orbit-keyed lookup behavior remains unchanged.

### 3.5 Complete gate result

Record the exact 409-result ledger and RED list. Because CB47 is measurement-only, the expected aggregate is the TB41 baseline **398 PASS / 11 RED**, but aggregate equality alone is insufficient. Acceptance requires the identity-level gates above and the new EC7 measurements.

No benchmark is required for CB47 diagnostics. Do not introduce performance acceptance or execute unrelated representative-mesh benchmarks in TB42.

## 4. Unit-test design and assertion integrity

The protected oracle remains behavioral and unchanged: the later region-frontier evidence must be non-empty when its contract applies. TB42 must not weaken an assertion, add a tolerance, recognize a fixture, skip an identity, or change expected diagnostic values to manufacture green.

The new CB47 fields are diagnostic context, not substitute success criteria. Their purpose is to make a failing protected assertion actionable and falsifiable.

## 5. Stop and blocker conditions

Stop execution and preserve evidence when:

- package/source identity or checksums fail;
- selector409 identity count/hash differs;
- accepted 1–365 is not 365/365;
- 311/314/356/357 or 312/315/409 regress;
- required packaged harness/fixtures are missing;
- a zero-selected filter or orchestration error occurs;
- continuing would require build, relink, source edit, selector edit, fixture edit, or any other TB-forbidden mutation.

A runtime RED is not itself an orchestration blocker; preserve it and continue only when the preceding hard gates allow the remaining planned identities to be meaningfully executed.

## 6. Reruns and determinism

No automatic reruns. A deterministic failed identity is executed once. Re-execution is allowed only when the first attempt was demonstrably infrastructure/orchestration-invalid and TB-REV later authorizes a bounded rerun. Do not use retries to mask flakiness.

## 7. Completion criteria and handoff

TB42-EXEC is complete when all planned identities have a result or explicit blocker and raw evidence is preserved sufficiently for independent review to evaluate every EC7 criterion without reconstructing intent from chat context.

TB42-EXEC must update the runtime report/evidence only within the TB boundary. It **must not promote itself or issue the corrective plan**. The exact successor is **independent `M3-CP4c-3-TB42-REV`**, and the implementation/orchestration loop stops completely at that boundary as required by project policy.

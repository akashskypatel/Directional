# M3-CP4c-3-TB22 — Artifact-Only Test + Benchmark Plan

## 1. Validation identity

- Phase/turn: **`M3-CP4c-3-TB22`** — Test + Benchmark, artifact-only.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Evidence source to validate: **`d69729a69a40b020968ed6ef1fbc1bc788284518`**.
- Immutable compile package: artifact **`9919225745`**, `m3-cp4c3-cb24-compile-result-33823590494`.
- Artifact SHA-256: **`7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`**.
- Packaged source archive SHA-256: **`34d938298466d4be9b73a6034d1ed21230104c6634a1dfaa82b2ab71f81fa704`**.
- Gate selector: **393 identities**, SHA-256 **`ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`**.
- Frozen selector-391 prefix: **`f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`**.
- Accepted selector-365 prefix: **`6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`**.

No configure, compile, relink, regeneration, source/test/fixture/selector mutation, package repair, or benchmark execution is authorized in TB22.

## 2. Objective and binding discriminators

TB22 measures CB24's diagnostic-only output without choosing a correction. The complete run must make these six BY9 discriminators reviewable:

1. accepted ordinals **1–365 remain 365/365 PASS**;
2. ordinal **366 remains the same semantic surface**: `UncutFaceComponentOrbitSeedNotUnique`, component 0, `seedState=Multiple`, seed count 3, seed orbits `[0,1,3]`, 191 faces;
3. both minority seed-orbit boundary rows are retained and published in full, including the seed rule;
4. each minority row publishes the certificate face on each side;
5. the mechanical **projection-faithfulness residual** and all retained residual witness rows are published exactly;
6. ordinal **391 no longer REDs because of the prescribed-sphere dependency**; mechanical and torus assertions/reporting remain independent, while the sphere half is skipped-with-reason while ordinal 368 remains open.

Ordinals 371/372 must remain PASS. The previously carried surfaces 367/368/369/370/374 must remain unchanged unless the runtime evidence itself demonstrates otherwise. New ordinals 392/393 are required-green witnesses and are expected PASS. If the only REDs are the carried 366/367/368/369/370/374 surfaces, the complete ledger is **387 PASS / 6 RED**. Any deviation is evidence, not permission to edit or weaken validation.

## 3. Artifact preflight — before any Directional binary executes

1. Download artifact **9919225745** exactly once and verify its SHA-256 equals `7955c243d7968e51e62f0f8d4b0cc96da313a2356ee8bf2eeba7c995b856e87d`.
2. Extract with an ordinary archive tool that preserves executable modes. **Do not use Python `zipfile` extraction** or any path that loses packaged permissions; do not repair permissions after extraction.
3. Run the package's internal `SHA256SUMS` verification and require all entries to match.
4. Verify `metadata/source-commit.txt` is exactly `d69729a69a40b020968ed6ef1fbc1bc788284518`.
5. Verify `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`.
6. Verify selector 393 has exactly 393 identities and SHA-256 `ee8cc03360c30b7ef662c3972b852d8b6f17dddbf5abac29a632e02227644c4d`; selector 391 has 391 identities and SHA-256 `f60638a5890e133d7eb3cfcee2783c000192f310a41ef5ec1b4ec3b0cf6086c0`; prove selector 391 is an exact byte prefix of selector 393. Verify accepted selector 365 is the frozen prefix.
7. Before runtime, resolve each selector identity statically from packaged source/CMake/test definitions to exactly one packaged test binary. Do **not** execute generated binaries for test discovery, listing, help, or version output. A missing, duplicate, or zero-selected identity is orchestration failure.
8. Record a recursive **byte + mode census** of the extracted package before runtime. This preflight census is the immutable postflight comparison authority for TB22.

Any preflight mismatch stops TB22 as an orchestration/integrity failure. It is not a semantic RED and must not be repaired in-place.

## 4. Ordered execution plan

### 4.1 Complete selector ledger

Execute selector ordinals **1 through 393 in order**, one identity per **fresh process**, using the exact full identity as the test filter. Preserve for every ordinal:

- ordinal and exact identity;
- resolved binary;
- exact command/filter;
- process exit code;
- selected-test count/evidence proving the intended identity actually ran;
- complete stdout/stderr log;
- PASS/RED/orchestration classification.

A valid semantic RED does **not** stop the planned remainder. Continue through ordinal 393 so the independent review receives one complete immutable ledger. Stop only when artifact integrity, identity resolution, zero-selection, or another plan-defined orchestration prerequisite makes later evidence invalid.

### 4.2 Accepted-prefix gate

Require ordinals **1–365 = 365/365 PASS**. Any accepted-prefix RED is a gating regression. Preserve raw evidence and continue the report-only remainder only when the artifact/selector process remains valid; do not repair or rerun with altered inputs.

### 4.3 Mechanical ordinal 366 and BY2–BY4 evidence

For ordinal 366, record the complete typed failure and require the pre-existing semantic identity to remain recognizable. In its production-path diagnostic output capture all lines with these CB24 evidence families:

- `m3Cp4c3BY2BY3;...` — record each retained minority row in full, including `sourceEdge`, seed orbit, `seedRule`, component/labeled source faces, and component/labeled certificate faces plus the other published boundary metadata;
- `m3Cp4c3BY4;...` — record `projectionFaithfulnessResidual`, witness count, truncation state, and every retained residual witness row.

Do **not** assume the BY4 residual should be zero. A zero residual and a non-zero residual imply different owners and are adjudicated only by `M3-CP4c-3-TB22-REV`.

### 4.4 Re-scoped ordinal 391 and appended witnesses

For ordinal 391, prove that the mechanical and torus halves execute their unchanged assertions/reporting independently of the prescribed-sphere dependency. Record the explicit sphere skip reason. The old failure solely because `sphere.cutGraph` is absent must not recur.

Execute ordinals 392 and 393 normally as required-green identities and retain their complete assertion output. They are validation witnesses for the new diagnostic fields and retention/projection contract; they do not define the mechanical production result.

### 4.5 Carried discriminator checks

Record exact status/error identity for 367/368/369/370/374 and require 371/372 to remain PASS. Any changed carried surface is a review finding. Do not infer common root cause from an error-name match alone.

## 5. Postflight and evidence package

After ordinal 393:

1. Recompute the recursive byte + mode census of the extracted package and require it to be **identical** to the preflight census.
2. Produce an exact 393-row ledger, hash the ledger with SHA-256, and record PASS/RED totals and exact RED ordinal set.
3. Preserve the artifact/source/selector authority, complete per-ordinal logs, identity-to-binary mapping, pre/post census and its digest, the exact BY2/BY3 minority rows, all BY4 residual data, ordinal-391 skip evidence, and summaries for the carried discriminators.
4. Record explicitly that no configure/compile/relink/regeneration/repair/mutation/benchmark occurred.

Benchmark plan: **not applicable**. `directional_benchmarks` is packaged compile evidence only and must not be executed in TB22.

## 6. Rerun and nondeterminism rules

No discretionary retries. A deterministic semantic RED is recorded once. A rerun is allowed only after a diagnosed orchestration/infrastructure failure where the rerun uses the **same immutable artifact, selector, command, identity, and inputs** and does not stitch partial semantic outcomes into a fabricated pass. Zero-selected is never pass. Do not regenerate discovery data from binaries.

## 7. Completion and successor boundary

TB22 is complete only when all 393 planned identities have a result or an explicit plan-valid blocker, raw evidence is preserved, the package postflight is immutable, and the regression/root-cause tracker is updated as required for every observed RED/candidate before durable closeout.

The mandatory successor is **independent `M3-CP4c-3-TB22-REV`**. That review owns interpretation of the BY4 residual and the next correction owner. TB22 itself must not modify implementation, test, fixture, selector, build logic, frozen definitions, or candidate ownership. A DEFN turn is not pre-scheduled; it becomes appropriate only if the independent review concludes the barrier-set contract itself must be restated.

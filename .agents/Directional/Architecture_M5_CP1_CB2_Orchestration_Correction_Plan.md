# M5-CP1-CB2 Orchestration-Correction Plan

**Turn:** `M5-CP1-CB2`
**Type:** Code + Build cadence slot, **control-plane-only / runtime-free / no package rebuild**
**Input candidate:** artifact `10595705100`, source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`
**Routing authority:** artifact `10592987234`
**Predecessor:** `M5-CP1-TB1-R1-EXEC` — blocked before Directional runtime by corrupt embedded executor payload
**Intended successor on static green:** `M5-CP1-TB1-R2-EXEC`

## 1. Objective

Repair only the artifact-only execution control plane that prevented R1 from starting. Semantic package/test/selector/routing authority and credit rules are frozen. Prove the next executor can be decoded and resolved against the actual immutable artifacts **before** semantic runtime is triggered. No Directional compile or runtime is authorized.

## 2. Frozen authorities

Do not change candidate `10595705100`; semantic source `b98f461b9a392cc182891a81c0a84b0b01dfbb45`; candidate ZIP `fdc4046630c6f48b2bc76aad74ebc07b443a024fc9cfd76507bae515eb8668ea`; root manifest `8330461b8c5e489059e2ec320cb2e2d5243d6ef36dc01b667b5cefc09f609a3d`; source archive `4f51257db12ae24363a45ddfa62778200e9ac0a8ef4ce2b585c8c606350d78b9`; selector430 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; selector427 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`; routing artifact `10592987234` / ZIP `352c8cfc9c9b89cf0d532c8e0836339a31ba35fd6e854a781721cbc76f02afce`; routing identity-map `7a92e7a3b8a69466423c4a0d2ad5ece2dcd4912f04eeb99e1f32fa70b4a5cf6c`; focused count **9**; selector count **430**; benchmark count **0**.

Focused row 9 remains `SurfaceCellTransitionQuotient.PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization` and remains **mechanism-only / no produced-witness credit**.

## 3. Authorized changes

Only control-plane material needed to make the next executor reproducible and statically verifiable may change. Prefer one canonical harness source whose encoded form is generated mechanically rather than hand-transcribed.

Authorized: reconstruct the intended harness from the frozen R1 contract; mechanically generate compressed/Base64 bytes; record canonical/encoded hashes; validate workflow schema and permission ceiling; freeze a fresh R2 execution plan only after static preflight passes.

Not authorized: `src/**`/`include/**` semantic changes; test/fixture/selector edits; package rebuild/relink; generated discovery; Directional runtime; mutation of artifacts `10595705100`/`10592987234`; weakening exact-selection/postflight/fail-closed rules; production-debt credit.

## 4. Mandatory pre-trigger proof

### C1 — canonical harness bytes

- one canonical UTF-8 harness source;
- `bash -n` passes;
- canonical SHA-256 recorded;
- any GZip/Base64 payload is generated deterministically from those bytes;
- fresh decode reproduces byte-identical harness bytes and the same SHA-256.

### C2 — immutable artifact/path resolution

Using locally extracted immutable artifacts only: verify candidate/routing ZIP hashes, candidate root manifest **28/28**, every harness-referenced path, selector430 exact 430 rows/hash, routing identity-map header + 430 unique rows/hash, and all nine focused identities. **Do not run a Directional binary.**

### C3 — literal/workflow validation

Verify every expected digest literal is exactly 64 lowercase hexadecimal characters; expected paths/counts are mechanically validated; temporary YAML passes the durable schema validator; caller permissions satisfy reusable-workflow ceilings; workload has no hidden timeout/watchdog.

### C4 — fresh retry boundary

R1 is not retried in place. Any future runtime is `M5-CP1-TB1-R2-EXEC`, starts from ordinal 1 with fresh processes, and inherits no semantic evidence from R1.

## 5. Verification and closeout

CB2 is static-green only when C1–C4 are evidenced and no unauthorized path changed. Stable accounting remains **49 / 14 / 35**, debt **5**. On green, freeze exactly one next artifact-only `M5-CP1-TB1-R2-EXEC` plan preserving the semantic gate in the current R1 report. Do not execute R2 inside CB2.

# M4-CP3-TB5 Artifact-Only Test + Benchmark Plan

**Status:** FROZEN FOR EXECUTION
**Canonical turn:** Test + Benchmark
**Exact subturn:** `M4-CP3-TB5-EXEC`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Evidence commit:** `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`
**Immutable candidate artifact:** `10293750596`
**Artifact SHA-256:** `f95decac9b059bcc7c7b341ecda1e95e8a5b0028211eaa7f902144a196c60831`
**Compile log artifact:** `10293990184` / `72447200a886c4e07768f8e81a156f0878f400321cddd054341cf68d758863f9`
**Source archive SHA-256:** `ca16770d8ceff1da119687284eb7c01b31af9ce237be01753ed4c962305ff18d`
**Package manifest SHA-256:** `43e8e4c35712c8b69d4906288390745f2bdb507160cf52c31ad8f7545faa91ed` / 28 entries
**Accepted authority retained until Review:** R4 artifact `10289601000` / selector403 **403/403**

## 1. Validation objective

Measure whether the CB7 test-authority correction finally instantiates the intended 18-edge torus A3→A4 shared-boundary seam without weakening any accepted control.

The execution must answer only these runtime questions:

1. Does row408 pass twice in fresh exact-filter processes, including its new exact 18-edge effective-hard-authority assertion?
2. Do rows404-407 remain green twice each?
3. Does accepted selector403 remain 403/403?
4. Does candidate selector408 become 408/408?
5. Does the immutable package/source/execution view remain byte-identical before and after execution?

EXEC does **not** diagnose failures, promote the package/selector, close CP3, close `G4-B002`, or modify regression accounting. Those decisions belong to mandatory `M4-CP3-TB5-REV`.

## 2. Preconditions and immutable provenance

Before any Directional runtime process:

- download artifact `10293750596` exactly once;
- verify provider/archive SHA-256 `f95decac9b059bcc7c7b341ecda1e95e8a5b0028211eaa7f902144a196c60831`;
- verify root `SHA256SUMS` reports **28/28 PASS**;
- verify `metadata/source-commit.txt` equals `dbcc2f1fe07b611ce7360cd00e31ae4e6cd157c8`;
- verify `metadata/preflight-target.txt` is `directional_surface_cell_producer_tests` and both preflight/build exit codes are `0`;
- verify `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- verify the source archive hashes to `ca16770d8ceff1da119687284eb7c01b31af9ce237be01753ed4c962305ff18d`;
- verify selector403 SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`, 403 LF rows;
- verify selector408 SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`, 408 LF rows, and first403 byte-identical to selector403;
- verify owner partition `30 / 262 / 75 / 41`, zero missing/ambiguous, row408 producer-owned;
- verify packaged executable set and hashes are unchanged from the manifest;
- record OS/runner/compiler and GMP dependency metadata from the package.

Any mismatch is orchestration failure and a **STOP before runtime**, never a semantic RED/SKIP/PASS.

## 3. Process discipline

Every identity runs in its own fresh process against the packaged owner binary. No configure, compile, relink, generated discovery, fixture mutation, package repair, environment-dependent selector generation, or source edit is allowed.

Per-process form:

```text
timeout -k 5s 180s <packaged-owner-binary> \
  --gtest_filter='<exact Suite.Test identity>' \
  --gtest_color=no
```

For every process preserve:

- ordinal/phase/repetition;
- exact identity and owner binary;
- selected-test count, which must equal exactly `1`;
- exit code / PASS / RED / SKIP / timeout / crash classification;
- stdout/stderr and duration;
- any deterministic success/failure receipt emitted by the identity.

A zero- or multi-selected filter is orchestration failure. A timeout is not a semantic pass or skip.

## 4. Frozen ordered execution — 821 fresh processes

### Phase A — row408 focused A: 1 process

Run exactly:

`RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`

Owner: `directional_surface_cell_producer_tests`.

**Acceptance:** selects exactly one identity and PASSes. If RED/SKIP/crash/timeout/selection mismatch occurs, preserve evidence and **fail-fast; do not execute phases B-E**.

### Phase B — row408 focused B: 1 process

Repeat the exact row408 identity in a second fresh process.

**Acceptance:** selects exactly one identity and PASSes with deterministic semantic receipts. Any failure is fail-fast; do not execute phases C-E.

### Phase C — rows404-407 controls A+B: 8 processes

Execute candidate-selector ordinals 404, 405, 406, and 407 in selector order, then repeat the same four identities once more in fresh processes.

**Acceptance:** **8/8 PASS**, each exact identity selected once. Any first failure is fail-fast; preserve raw evidence and do not enter cumulative selectors.

### Phase D — accepted selector403: 403 processes

Execute every identity from `Architecture_M4_CP3_CB4_R3_Required_Green_Selector_403.txt` in exact LF row order, one fresh process per identity, using the statically proven owner mapping.

**Acceptance:** **403/403 PASS**, zero SKIP/crash/timeout/selection mismatch. Any first failure is fail-fast and blocks phase E.

### Phase E — candidate selector408: 408 processes

Execute every identity from `Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt` in exact LF row order, one fresh process per identity, using the same owner mapping.

**Acceptance:** **408/408 PASS**, zero SKIP/crash/timeout/selection mismatch.

### Frozen ledger

```text
phase A row408 focused A           1
phase B row408 focused B           1
phase C rows404-407 controls A+B   8
phase D accepted selector403     403
phase E candidate selector408    408
-----------------------------------
total                            821
```

No process from TB3 or TB4 may be credited toward these counts.

## 5. Immutable postflight

After the final executed process, or immediately after a fail-fast semantic stop, re-hash without modifying:

- package root `SHA256SUMS` subjects;
- source archive;
- selector403 and selector408;
- owner-mapping inputs/execution view;
- packaged binaries/libraries and relevant fixtures;
- package/source metadata used in preflight.

Pre/post digests must match exactly. Record the number of processes actually executed and the phase/ordinal that caused any stop.

## 6. Benchmarks

**Applicable:** no performance benchmark is authorized in TB5.

This is a semantic artifact-only acceptance gate. Do not execute `directional_benchmarks`; its presence in the package is compile/package evidence only.

## 7. Unit-test design check

- **Contract under test:** effective row408 production HardFeature authority must equal the 18 explicit torus cut-graph edges, then the existing exact A3→A4 shared-boundary contract must hold.
- **Scenario/boundary:** a smooth torus carrying two explicit source-edge generators while automatic feature classification is intentionally suppressed only for this witness.
- **Broken behavior exposed:** reintroducing automatic Hard edges, dropping/replacing one user edge, changing effective rail composition, or failing the downstream A3→A4 seam makes row408 RED.
- **Isolation rationale:** row-local options isolate a test-fixture precondition and do not change production behavior or other rows.
- **Assertion semantics:** exact source-edge set equality is stronger than count equality and is evaluated before downstream seam assertions.

## 8. Stop and blocker conditions

Stop and preserve evidence when any of the following occurs:

- package/source/digest/selector/owner preflight mismatch;
- exact-filter selection count is not one;
- any semantic process is RED, SKIP, crash, or timeout;
- immutable postflight changes;
- executing the frozen plan would require source/fixture/build/package mutation;
- required artifact or runtime dependency is unavailable.

Do not rebuild or repair inside TB-EXEC.

## 9. Plan-defined reruns

The only repetitions authorized are the frozen focused A/B and rows404-407 A/B repetitions already counted in 821. No retry of a failed semantic process is authorized. Infrastructure/orchestration failures may be classified by Review; TB-EXEC must not silently rerun them.

## 10. Evidence to preserve

Publish raw result and diagnostic/log artifacts containing:

- exact candidate artifact/source/digests;
- immutable pre/postflight tables;
- all process records through completion or fail-fast;
- phase totals and overall total;
- PASS/RED/SKIP/crash/timeout/selection-mismatch counts;
- row408 emitted receipts on each focused run when reached;
- accepted-selector403 and candidate-selector408 totals when reached;
- final source/package/execution-view hashes.

## 11. Completion and mandatory successor

TB5-EXEC is complete when every planned item has a result or an explicit stop blocker and raw evidence is preserved.

**Mandatory successor:** `M4-CP3-TB5-REV` (`TB-REVIEW`). Review must independently reopen this frozen plan and raw evidence before deciding package/selector promotion, `M4-CP3-TB4-REV-CAND-01`, stable accounting, `G4-B002`, or CP3 status.

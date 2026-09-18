# M4-CP-SCALE-CB20 — Frozen Harness Orchestration Correction Code + Build Plan

**Turn:** `M4-CP-SCALE-CB20`
**Type:** Code + Build / control-plane-only orchestration correction
**Predecessor:** `M4-CP-SCALE-TB12-R6-EXEC`
**Successor on control-plane GREEN:** `M4-CP-SCALE-TB12-R7-EXEC`
**Generated Directional runtime:** **forbidden**

## 1. Goal

Correct exactly the shell-harness defect proved by R6 while leaving the candidate package and every product/test/fixture/selector/build semantic byte unchanged.

R6 failed before its first semantic process at frozen harness line 225:

```bash
local stem="$(printf '%03d' "$ledger_ord")-${phase}-$(printf '%03d' "$phase_ord")" dir="$RESULT/raw/$stem" work="$RUNTIME/$stem"
```

Under `set -u`, `$stem` is expanded for `dir`/`work` before that same `local` command has made `stem` available. This is the only authorized harness-semantic correction.

## 2. Immutable authorities

Do not modify or rebuild:

- CB18 candidate artifact `10532133889` / semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- package ZIP/provider SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- package manifest SHA-256 `44fd665474f12d79b916eacb77df9dfc07cf7478503e82a8c1ac7f80c64da5bd` / 28 entries;
- selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114` and its 30/280/75/41 owner census;
- retained genus-two OBJ/rawfield/metadata bytes;
- original frozen harness Drive file `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`, 18,459 bytes, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`.

The original Drive harness is evidence and must not be overwritten in place.

## 3. Authorized correction

Create a corrected successor harness from the exact old bytes. In `run_row`, replace only the one compound `local` statement with nounset-safe sequential initialization, for example:

```bash
local ledger_ord="$1" phase="$2" phase_ord="$3" identity="$4" binary="$5"
local stem dir work
stem="$(printf '%03d' "$ledger_ord")-${phase}-$(printf '%03d' "$phase_ord")"
dir="$RESULT/raw/$stem"
work="$RUNTIME/$stem"
```

No other harness behavior, gate order, hashes, package rules, owner map, ledger shape, fail-fast semantics, postflight, benchmark disposition, or test filter may change.

Required static proof before publication:

1. Re-hash original harness as exactly `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`.
2. Produce an exact unified diff and require that only the line-225 declaration is replaced by the sequential declarations above.
3. `bash -n` must pass.
4. Run a **non-Directional shell micro-proof** under `set -u` with representative `ledger_ord/phase/phase_ord/RESULT/RUNTIME` values and require the derived `stem`, `dir`, and `work` strings to match their expected values. Do not invoke any generated Directional binary.
5. Hash the corrected harness and upload those exact bytes as a **new** Drive file. Record new file ID, byte count, and SHA-256.

## 4. Fresh R7 caller

Prepare a fresh `M4-CP-SCALE-TB12-R7-EXEC` caller from the already validated R6 control topology. Change only the outer turn/run naming, exact R7 marker path, corrected harness Drive ID/hash, and corresponding R7 result/log artifact names.

The caller must retain exactly:

```yaml
permissions:
  actions: read
  contents: write
  id-token: write
  issues: write
  pull-requests: write
```

It must still use the durable schema validator and observer, and it must execute the corrected frozen harness without a workflow/job elapsed-time watchdog around the full semantic gate.

Author the draft outside `.github/workflows/**`. Materialize every expected SHA-256 literal through `write_orchestration_payload.py` placeholders. Validate the exact draft against SchemaStore using `agent-workflow-schema-validator-reusable.yml`, then publish byte-identically and record draft/published Git blob equality plus byte SHA-256.

**Do not create the R7 execution marker in CB20.** CB20 cleanup retires the temporary caller after its exact published bytes are content-addressed, mirroring CB19. R7 must reinstall those exact bytes before it creates its marker in a separate commit.

## 5. Code + Build boundary

This is a control-plane-only correction. The candidate package already exists and no repository product/test/build semantic source needs compilation.

Required flags/evidence:

```text
configureExecuted=false
compileExecuted=false
relinkExecuted=false
repackageExecuted=false
generatedDirectionalRuntime=false
testExecution=false
benchmarkExecution=false
discoveryExecution=false
packageRepair=false
```

Do not change production source, tests, fixtures, selector files, CMake, benchmark logic, candidate package bytes, or accepted authority. Do not execute the 436-row semantic gate in CB20.

## 6. Acceptance

CB20 is GREEN only if all of the following hold:

- original harness exact hash is re-proved;
- corrected harness has a one-statement-only semantic diff and passes `bash -n` plus the nounset micro-proof;
- corrected harness is frozen under a new Drive ID/hash without overwriting the old file;
- fresh R7 caller exact permission ceiling and trigger contract are correct;
- SchemaStore validation is GREEN and published caller bytes are identical to the validated draft;
- R7 marker remains absent;
- candidate package/selector/genus-two authority remains unchanged;
- zero generated Directional runtime/build/test/benchmark/discovery occurs.

If any control-plane proof fails, remain in CB20 and correct only that control-plane defect. Do not advance to R7 until the caller/harness pair is frozen and validated.

## 7. R7 semantic boundary

`M4-CP-SCALE-TB12-R7-EXEC` reuses the unchanged CB18 candidate and the same 436-row gate:

```text
Gate A0 5 -> Gate A 4 -> S5 1 -> selector426 426 only if all ten focused rows are green
benchmark 0
exact immutable postflight required
```

R7 is the next semantic attempt. CB20 itself grants no S5/A3/selector credit.

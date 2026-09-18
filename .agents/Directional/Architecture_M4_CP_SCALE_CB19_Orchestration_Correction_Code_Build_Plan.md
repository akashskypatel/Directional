# M4-CP-SCALE-CB19 — R5 Startup-Failure Orchestration Correction Plan

**Turn:** `M4-CP-SCALE-CB19`
**Type:** Code + Build / control-plane-only orchestration correction
**Runtime:** forbidden
**Production/test/fixture/selector/build semantic mutation:** forbidden
**Compile/repackage:** not required; reuse CB18 artifact `10532133889` unchanged

## 1. Goal

Correct only the GitHub Actions reusable-workflow permission ceiling that prevented `M4-CP-SCALE-TB12-R5-EXEC` from instantiating jobs. Preserve the exact CB18 package, exact R5 semantic execution contract and exact frozen harness, then issue a fresh artifact-only R6 execution plan.

Success means the corrected R6 caller bytes are statically valid and grant the permission union required by every called reusable workflow/job. CB19 itself must execute **zero** generated Directional runtime and must not rebuild or repackage the candidate.

## 2. Frozen authority

Do not alter or regenerate:

- candidate artifact `10532133889`, SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- selector426 / first425 / retained genus-two bytes;
- the 436-row R5 semantic gate order and fail-fast rules;
- frozen harness Drive file ID `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`.

The R5 startup-failed run `35311252926` and fallback probe `35311498108` remain invalid-attempt provenance. Neither may be treated as semantic evidence.

## 3. Exact correction

The failed caller declared `contents: read` while invoking `agent-run-observer-reusable.yml`. Its statically reachable `branch-file` job declares `contents: write`, even though `commit_run_file=false` would skip that job at runtime. GitHub rejects the reusable permission ceiling before job instantiation.

The fresh R6 execution caller must therefore declare this exact top-level permission union:

```yaml
permissions:
  actions: read
  contents: write
  id-token: write
  issues: write
  pull-requests: write
```

No fallback recent-runs probe is part of the normal path. The standard observer comment is expected to become available once the caller can instantiate jobs. If observation still fails, use repository-wide Actions metadata before any retry; do not retrigger blindly.

## 4. Code + Build procedure

1. Re-fetch the current durable observer reusable and schema validator; re-confirm the static permission union before authoring caller bytes.
2. Freeze the exact R6 caller bytes outside an active trigger path or otherwise validate them before trigger eligibility.
3. Validate the exact caller against the configured GitHub workflow schema and verify reusable inputs/permissions manually against current reusable definitions.
4. Do not create or modify the R6 execution marker in CB19. Do not execute the harness, candidate binaries, tests, discovery or benchmarks.
5. Do not compile/relink/repackage: this correction does not touch source/build semantics and the immutable package is reused unchanged.
6. Produce `Architecture_M4_CP_SCALE_TB12_R6_Artifact_Only_Test_Benchmark_Plan.md` that reuses the R5 semantic gate unchanged and adds the corrected caller permission contract/provenance.
7. Close CB19 only when the corrected control-plane contract is recoverable and the exact successor is `M4-CP-SCALE-TB12-R6-EXEC`.

## 5. R6 semantic contract must remain unchanged

R6 must still, after exact immutable preflight, initialize the complete **436-row** ledger before runtime and execute in this order:

1. CB18 ownership-preservation Gate A0: **5/5**;
2. frozen CB16/CB17 Gate A: **4/4**;
3. unchanged S5 focus: **1/1**;
4. selector426: **426/426** only when all ten focused processes are green;
5. benchmark execution: **0**;
6. exact immutable postflight.

One identity per fresh process, no elapsed-time watchdog for the full semantic gate, fail-fast with later rows explicitly `UNEXECUTED`, no dynamic discovery, no package repair, and no mutation/configure/compile/relink remain mandatory.

## 6. Stop rules

STOP rather than broaden CB19 if the correction would require production/test/fixture/selector/build semantic edits, artifact replacement, harness regeneration, or generated Directional runtime. Such a finding would invalidate the assumption that R5 failed only at the caller permission ceiling and requires explicit reclassification before proceeding.

# M4-CP-SCALE-TB12-R5-EXEC — Artifact-Only Test + Benchmark Report

**Turn:** `M4-CP-SCALE-TB12-R5-EXEC`
**Type:** Test + Benchmark / immutable artifact only
**Status:** **COMPLETE / ORCHESTRATION FAILURE / NO SEMANTIC LEDGER**
**Candidate artifact:** `10532133889`
**Semantic source:** `079933f2ec31a9323218e73c7ae0d3ea1d11103c`
**Exact next:** `M4-CP-SCALE-CB19`

## 1. Outcome

R5 did **not** reach package preflight or generated Directional runtime. The execution caller triggered at commit `f501d246fecb66cf7e54fe6d74fd94d165ca786e`; GitHub created workflow run `35311252926`, but the run completed as `startup_failure` with **zero jobs instantiated**. Therefore the frozen 436-row semantic ledger was never initialized by the execution harness, Gate A0/A/S5/selector426 executed **0** processes, benchmark execution is **0**, and no package byte was consumed or mutated.

This is orchestration failure, not semantic RED. It grants no acceptance/rejection credit, does not consume a semantic retry, and leaves every product/test/fixture/selector claim unchanged.

## 2. Deterministic control-plane cause

The temporary R5 caller invoked `.github/workflows/agent-run-observer-reusable.yml` while declaring only `contents: read`. The durable observer reusable contains a `branch-file` nested job with `permissions.contents: write`. GitHub validates reusable-workflow permission ceilings statically, including nested jobs that would be skipped by `commit_run_file: false`; the caller therefore could not instantiate any jobs.

This is exactly the permission-union rule frozen in `GitHub_Workflow_Policy.md`: caller permissions must cover every called reusable workflow/job even when a nested job has a runtime `if:` that would skip it. The correction is control-plane-only: the successor caller must grant `contents: write`. No production/test/fixture/selector/build change is implicated.

## 3. Invalid-attempt provenance

### Primary execution attempt

- workflow: `M4 CP SCALE TB12 R5 EXEC`
- run: `35311252926`
- trigger/event SHA: `f501d246fecb66cf7e54fe6d74fd94d165ca786e`
- conclusion: `startup_failure`
- instantiated jobs: **0**
- package preflight: **not reached**
- harness download: **not reached**
- Directional runtime: **0**
- semantic ledger: **none**
- result/log artifacts from workload: **none**

### Observer fallback probe

Because the expected observer comment could not exist when zero jobs instantiated, a bounded recent-runs probe was attempted. Probe run `35311498108`, trigger SHA `0326b6de0053175b138e370e306f66fcee67b998`, also ended `startup_failure` with zero jobs because its caller repeated the same `contents: read` permission defect. Repository-wide Actions metadata then exposed both exact startup-failed runs directly. The probe is invalid-attempt orchestration provenance only and has no semantic effect.

`M4-CP-SCALE-TB12-R5-EXEC-CAND-01` is therefore **RESOLVED / ORCHESTRATION / NON-STABLE**. It is not added to stable regression accounting and does not reclassify the open product `M4-CP-SCALE-TB12-R4-EXEC-CAND-01 / RP-01`.

## 4. Frozen candidate and harness retention

The immutable CB18 candidate remains:

- artifact `10532133889`, provider SHA-256 `4793e0155349a7f6c1e1a7833f5474d468cae89fcdd40916ec3eca192ff09c3a`;
- semantic source `079933f2ec31a9323218e73c7ae0d3ea1d11103c`;
- source archive SHA-256 `2d08714f478e0ac93946b02b3f62ca16c099666b3bf3a6f5c40de9e98fb296ea`;
- selector426 SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`, first425 `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- retained genus-two OBJ/rawfield/metadata hashes unchanged from CB18.

The exact pre-authored R5 execution harness is retained for the corrected retry at Google Drive file ID `1WnSzFMBLSu5OdFjZTGbkgym8D-ikUdVC`, SHA-256 `dbd9d8a51cb9b3fe62a576911fd5eff8c9658586a1bb3644c2fde3ddd43186a2`. Because the failed workflow never instantiated a workload job, the harness was never downloaded or executed. The successor must reuse these exact bytes rather than regenerate the harness.

## 5. Authority and disposition

Accepted M4 runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**, owner census **30/280/75/41**. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**. CB18 candidate `10532133889` remains unpromoted; S5/A3 remain uncredited; no selector427 exists.

Per `Turn_Cadence.md`, exact next is control-plane-only `M4-CP-SCALE-CB19`. It must correct the caller permission ceiling without changing or rebuilding the immutable candidate, preserve this invalid-attempt provenance, and hand the same frozen semantic plan to fresh `M4-CP-SCALE-TB12-R6-EXEC`.


## 6. Post-closeout duplicate execution — invalid attempt only

After the authoritative R5 closeout above had already routed orchestration failure to `M4-CP-SCALE-CB19`, a later duplicate execution caller was authored with the corrected `contents: write` ceiling and triggered **before CB19 was completed**. This violates the frozen cadence edge `orchestration failure -> CB orchestration fix -> fresh TB`, so the resulting runtime cannot replace R5, cannot be relabeled as R6, and has zero semantic or stable authority. The duplicate also regenerated its harness rather than reusing the frozen Drive harness required by the CB19 plan.

Retained invalid-attempt provenance:

- workflow run/job: `35312751970 / 105497993610`;
- event SHA: `f80df6752d300557a98f59399c23f524263075d2`;
- result artifact `10534520770`, SHA-256 `511d82154b10564cb68a340d551cf8652e4dc4fed7d6813f3f2bbfd2d714b791`;
- workflow log artifact `10534211366`, SHA-256 `4cfa9cfe0f2d73e17391b731d1c93b7073cb798e8fac4816af55d19cc0b3b013`;
- immutable package/source/selector/genus-two preflight passed and exact postflight reported package/source/execution-view/fixture census equality;
- full 436-row ledger was initialized, but fail-fast executed only global row 1 and left **435 `UNEXECUTED`**; benchmark execution remained **0**;
- row 1 selected/executed exactly one `FieldTransportAtlas.SeparatingHardFeatureSingularityOwnsCanonicalBoundaryCycle` process and RED with exit 1 at `tests/FieldTransportAtlasTests.cpp:2572`: `built=false`, `code=SingularityMismatch;sourceVertex=8`;
- row-1 stdout/stderr SHA-256: `999dc96ac83ed8786e34863024428242db4e9d6aaac337b812544884133dd137 / e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855`.

These bytes are retained only so later R6/Review can recognize a repeated observation if it occurs under valid cadence. They do **not** open, close, reprice or reclassify any product/test candidate. Accepted runtime authority, stable accounting, S5/A3 status and exact successor remain exactly as in §5: `M4-CP-SCALE-CB19` next, then a fresh `M4-CP-SCALE-TB12-R6-EXEC` using the frozen harness.

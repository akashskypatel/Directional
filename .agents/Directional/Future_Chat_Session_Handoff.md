# Future Chat Session Handoff

**DURABLE — resume authority for the active working branch.**

## Current authority

`M4-CP4-CB7` is **COMPLETE / CONTROL-PLANE CORRECTION GREEN / RUNTIME-FREE**. CB7 changes exactly one durable caller-control line at commit `bbb64a7923900c0b0ce8c52680ef4588b85c691a`: `.agents/Directional/turn-payloads/m4-cp4-tb2-r1-caller-draft.yml` raises top-level `contents: read` to `contents: write` so the caller can satisfy the optional `contents: write` ceiling declared by `agent-run-observer-reusable.yml`'s `branch-file` job. `commit_run_file` remains false and reusable-workflow permissions are unchanged.

Corrected caller authority is mode `644`, 5,532 bytes, SHA-256 `488326cd8cbf1ee4078796b8ecd7031f578b87272eb62df5fa2d7d42fd42d719`. Harness authority remains mode `755`, 30,249 bytes, SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`. Final validation run `35446771294` is GREEN for both schema validation and the independent static permission/timeout boundary check; static receipt artifact `10585314838` records `static_permission_ceiling_valid=true`. Closeout snapshot run `35447156743` is GREEN with `runtimeExecution=false`.

CB7 executed no Directional runtime, compile, rebuild or repackage. Accepted M4 runtime authority therefore remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. CB4 `10578784752` and CB5 `10582435470` remain immutable/unpromoted. TB2 and R1 orchestration-invalid attempts remain audit-only with zero semantic credit.

## Exact next turn

**`M4-CP4-TB2-R2-EXEC`** — immutable artifact-only full-gate re-execution under `Architecture_M4_CP4_TB2_R2_Artifact_Only_Test_Benchmark_Plan.md`.

1. Begin with mandatory Test + Benchmark stale-evidence cleanup while preserving current authority.
2. Publish the corrected caller bytes exactly as temporary `.github/workflows/m4-cp4-tb2-r1-exec.yml`; re-hash to `488326cd8cbf1ee4078796b8ecd7031f578b87272eb62df5fa2d7d42fd42d719`, schema-validate the installed bytes, and re-check the caller/reusable permission ceiling before runtime. The R1-labelled carrier filenames are intentionally retained; semantic turn authority is R2.
3. Keep CB4/CB5 package hashes, selector427, owner census **30 / 281 / 75 / 41**, four-row focus set and composite routing unchanged.
4. Execute all four focused rows and all 427 selector rows from ordinal 1: **431 fresh processes**, with zero credit from any prior invalid attempt. Semantic RED continues; orchestration failure stops.
5. Complete immutable postflight and evidence publication whenever runtime starts. Any orchestration-valid semantic result routes to mandatory runtime-free `M4-CP4-TB2-R2-REV`.

### Carried obligations and owners

- `G4-B002` produced closed-complex debt — **OPEN / M4-CP4**, runtime re-proof owner `M4-CP4-TB2-R2-EXEC` after CB7, then Review;
- `G4-B002` periodic reorder debt — **OPEN / M5**, M5-CP1 mechanism + M5-CP3 production proof;
- `G4-B002` missing-owner debt — **OPEN / M5**, M5-CP2 mechanism + M5-CP3 production proof;
- `M4-CP4-TB1-R3-CAND-01` — **CORRECTED IN CB5 / RUNTIME RE-PROOF PENDING / NON-STABLE**;
- `M4-CP4-TB1-R3-CAND-02` — M4 ownership question CLOSED / two debts re-homed to M5 / non-stable;
- `M4-CP4-TB1-R3-CAND-03` — **CORRECTED IN CB5 / RUNTIME RE-PROOF PENDING / NON-STABLE**;
- `M4-CP4-TB1-R3-REV-OBS-01` — **DISCHARGED** by exact one-region torus derivation;
- `M4-CP3-TB1-R1-REV-OBS-01`, `M4-CP4-TB1-R2-REV-OBS-01`, `M4-CP4-TB1-R2-REV-OBS-02`, and `M4-CP-SCALE-TB2-REV-OBS-02` — **DISCHARGED**;
- `M4-CP-SCALE-TB1-REV-OBS-01` — M8-CP2;
- `M4-CP-SCALE-DEFN-OBS-01` — M8-CP2 only if observationally equivalent, otherwise reopen A2a/M3;
- `M4-CP3-CB4-REV-OBS-02` — first legitimate row399/path/`sourceFaces` binder touch;
- row408 historical provenance — truth constraint;
- two `G4-B003` debts — M5-owned, unchanged.

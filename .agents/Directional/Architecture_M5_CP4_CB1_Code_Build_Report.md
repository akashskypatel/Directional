# M5-CP4-CB1 — Focused Multi-Isolation Quotient Witness Code + Build Report

**Turn:** `M5-CP4-CB1`
**Role:** Code + Build
**Disposition:** **COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE / NO SEMANTIC ACCEPTANCE CLAIM**
**Successor:** `M5-CP4-TB1-EXEC`

## 1. Scope completed

CB1 added exactly one focused producer-boundary identity:

`M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion`

Only `tests/SurfaceCellTransitionQuotientTests.cpp` changed semantically. Product source, committed torus fixture/field bytes, `torus_fixture()` semantics, selector448, and all pre-existing ungated identities remain unchanged. The implementation commit is `094d235e0f0f1fcea97fd7147320b8697565e36c`.

The identity uses the fixed `torus_fixture()` subject and statically checks the six frozen facts in order with fact-naming assertion messages:

1. producer disposition is `Produced`;
2. one authoritative topology region spans at least two pipeline-derived isolation sheets;
3. that same region owns an internal isolation seam;
4. that region/seam owns a checked reciprocal `SurfaceIsolationSeamTransportCertificate`, independently reconciled to source incidence and transition authority;
5. that same region owns a canonical periodic relation whose ID is independently recomputed from region plus carrier routes;
6. reciprocal `PeriodicCut` edges in the same region explicitly name that exact relation and preserve opposite-edge/shared-boundary provenance.

The test does not invoke materialization or assert M6 occurrence, output-lineage, embedding, or verifier outcomes. It does not inject source sheet labels or alter the fixed subject after authoring.

## 2. Static row-449 ownership

CB1 does not publish selector449. The precommitted TB1 routing extension is:

```text
449	M5CP4.ProducedTorusPeriodicRelationOwnsMultiIsolationRegion	directional_surface_cell_producer_tests
```

Accepted selector448 remains exactly 448 rows / 36,382 bytes with SHA-256 `70ff08601bf244fcb4883e5d0601d5e7a3a44f52a8e855544a065c6ca5c75789`. Its static routing receipt remains exactly 448 rows with SHA-256 `c91a5e2f3d84d7d38b7c7c58afd157448cb225ebdbbfac3da2ef6259e811dd7c`.

## 3. Compile/package evidence

The exact compile source is `535ec760b7c39dd437de69afebec568fafb44aab`. GitHub Actions run/job `35934640705 / 107428875643` completed successfully through the mandatory reusable compile workflow.

Compiled owner targets:

- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`

Immutable result artifact:

- artifact ID: `10782841045`
- name: `directional-m5-cp4-cb1-result-35934640705`
- provider SHA-256: `3772d2c323bb4995bcb4503960d1bef1251442a3a7a95d8c0660680008042da6`
- compile log artifact: `10782293664`, SHA-256 `3915faea4f6a505153ca7f22f0a6c10017f1e78bd8dc015ccadf840bc8fd47b2`

Artifact verification is green:

- `source-commit.txt` exactly names `535ec760b7c39dd437de69afebec568fafb44aab`;
- `build-exit-code.txt` is `0`;
- `command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and `exactArithmeticBackend=GMP`;
- `DIRECTIONAL_ENABLE_GMP:BOOL=ON` is present in `CMakeCache.txt`;
- `gmp-evidence.txt` records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the generated authoritative link command;
- all four requested binaries plus the packaged libraries/metadata/source archive are covered by the recursive self-excluding manifest; all **26/26** manifest rows verify;
- final source status is clean.

No generated Directional binary, test, benchmark, discovery command, `ctest`, or semantic runtime was executed in this turn.

## 4. Preservation and transport evidence

The implementation patch was emitted before remote orchestration as `Directional__M5-CP4-CB1__base-0ca68c9689b1__work-preservation.patch` with SHA-256 `a7a93b0d9a03d5e8d29c505f2638f0dde8891a10697644533b4bd292ff34414b` and diff-body SHA-256 `f52b95abb17f3bf357843475f8bfc0ef823470bbb5232f870aae53befa567fcb`.

Google Drive patch-apply run `35934473466` verified the patch/base/intended-path contract and pushed implementation commit `094d235e0f0f1fcea97fd7147320b8697565e36c`. The workflow identity lacked trash ownership, so owner-authorized connector cleanup permanently deleted the staged Drive file after push/evidence verification.

## 5. Process observations

- `M5-CP4-CB1-OBS-01` — **process-only / no semantic effect.** The turn began repository document inspection before explicitly selecting the mandatory `READ_MODE`. Piecemeal inspection stopped; substantive source analysis used exact source-snapshot run/artifact `35933738856 / 10782620320`, snapshot SHA `0ca68c9689b165db34eb0b52ccce89263afb7499`.
- `M5-CP4-CB1-OBS-02` — **process-only / no semantic effect.** The available connector surface exposed no direct workflow-dispatch action for the reusable schema validator. Temporary apply/compile callers therefore gated their workloads on an in-run schema-validation job; both validation jobs passed before their workloads executed, but this does not satisfy the stricter prepublication-validation ordering in `GitHub_Workflow_Policy.md`.
- The whole-turn tool-call ledger is **partial/unknown** because calls made before the conservation-policy ledger was initialized were not recorded consistently. No tool calls were spent reconstructing it.

## 6. Disposition

CB1 satisfies its runtime-free authoring and compile/package boundary. It does **not** establish that the six-fact subject is runtime-green, does not accept conjunct 8, does not publish selector449, and does not close M5.

Exact successor: **`M5-CP4-TB1-EXEC`**, artifact-only, using result artifact `10782841045`. TB1 must execute selector448 plus the single row-449 identity as **449 fresh exact-filter processes**, with exact-one selection, zero skips, benchmark 0, immutable postflight, and no rebuild/repair. Mandatory successor after TB1 execution is `M5-CP4-TB1-REV`.

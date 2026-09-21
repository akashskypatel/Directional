# M5-CP3-CB9 Code + Build Report

**Turn:** `M5-CP3-CB9`
**Boundary:** **Code + Build only / runtime-free / test-authority-only**
**Disposition:** **COMPLETE / STATIC SCOPE GREEN / GMP COMPILE-PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Exact successor:** `M5-CP3-TB1-R8-EXEC`

## 1. Goal and bounded scope

CB9 implements only the produced-witness authority corrections frozen by `M5-CP3-TB1-R7-REV`. The semantic change is confined to:

- `tests/SurfaceCellTransitionQuotientTests.cpp`

No production source, public header, committed fixture, selector, CMake ownership, frozen definition, routing authority, benchmark semantic, or accepted test expectation changed. The semantic commit is `1907c26ed4de03b96c11e8f3500a65167bd2e42b`; the exact compile/package source is `1023eea6090a1f6c2d47ecaceb1099967c32e6c2`. Relative to the frozen CB9 source-snapshot base `55adf8d1a8a1ee0b3acd5835efa21c2e06c8a3ef`, the only semantic source diff is the authorized test file (`+610 / -36`).

## 2. Implemented witness authority

### Goal A — deterministic genuine nonzero-Z4 source witness

The test now builds a deterministic quarter-winding raw cross field over the existing committed `milestone-g/torus.obj` geometry. It finalizes that field through the normal cross-field finalizer, enumerates the unchanged row408 18-edge hard-feature authority, and requires a nonzero source transition on an independently selected hard-edge carrier before inspecting produced periodic relations.

The witness retains exact carrier, A3 span, reciprocal boundary-occurrence IDs, occurrence-owned source faces, source quarter-turn, atlas quarter-turn, source-path orientation, and a canonical one-step generator route. Construction fails closed if retained source/A3 authority is unavailable, the field is not produced, no independently selected nonzero carrier exists, or the pipeline-finalized source transition diverges from the independently finalized source transition.

### Goal B — directed source oracle

The expected transition direction is derived from canonical A3 source-path parameter orientation and exact boundary-occurrence source-face ownership. Carrier `sourceEdgeFaces` storage order is not used to choose direction. The resulting source quarter-turn must agree with retained atlas value before it can become a witness, making forward versus inverse direction observable for R8.

### Goal C — rows 4 and 5

`M5CP3.ProducedTorusNonzeroZ4RotationTranslationMaterializes` now resolves the produced relation from the independently selected source/A3 witness rather than searching product output for an arbitrary nonzero action. It requires the published generator route and rotation to match the independent witness before materialization evidence is considered.

`M5CP3.ProducedTorusTamperedNonzeroZ4TransformRejectsTyped` reuses that same relation, changes only the action rotation, proves the action changed while the stable semantic relation ID did not, and retains the exact expected typed rejection `NonReciprocalPeriodicRelation`.

### Goal D — row 6

`M5CP3.ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate` now derives candidate source routes from finalized source transitions on carriers outside the produced periodic-owner carrier set. Before insertion it requires the constructed relation ID to be absent from the relation table, unowned by every phase-front edge, and absent from the baseline selected certificate. Only then is the relation appended and relation storage permuted; the existing invariance assertions remain on materialization success, selected certificate signature, completion hash, consumed-periodic count, and non-consumption of the added ID.

These are static/code properties only in CB9. No runtime semantic credit is claimed until immutable R8 execution and mandatory Review.

## 3. Patch transport and preservation

The authoritative test-only patch was applied from Google Drive staging file `1s2lJdUsj6L6JRzM-lPoPGiHhqXqJmOZV`, SHA-256 `89af1b2a1e4a76058c54358a101d5ef2bd7a250f0bfc3b132f1ad5d4606f4e9b`, against exact base `55adf8d1a8a1ee0b3acd5835efa21c2e06c8a3ef`. The apply result records semantic commit `1907c26ed4de03b96c11e8f3500a65167bd2e42b`, `runtimeExecution=false`, successful job status, and owner-side Drive retirement required.

An independently prepared alternative work-preservation patch was not applied after the authoritative branch implementation was detected. It carries no repository authority.

## 4. Mandatory GMP compile/package evidence

Authoritative compile/package workflow run/job:

- run: `35644260337`
- compile job: `106480821581`
- exact source: `1023eea6090a1f6c2d47ecaceb1099967c32e6c2`
- candidate artifact: `10660365136` (`m5-cp3-cb9-result-35644260337`)
- candidate ZIP SHA-256: `30333b2edbcd011ca52ae9e7e134884f72f4425a56103f179b6a3b6b3d1b0729`
- compile log artifact: `10660330234`
- log ZIP SHA-256: `7957e1f97820866a6b26d0149e6ca98ec67de857273c0f24185418c9e8c657d1`
- root `SHA256SUMS`: **28/28 verified**, file SHA-256 `9cfe8fac63bf730c59b271eec7ee5948debca285d73eec4b9cbc81396b58e464`
- packaged source archive SHA-256: `38dff143f89ee882cd40f85d2344fb96b68f87eb864d52a352a5404e244a5bbc`
- preflight/build exits: `0 / 0`
- explicit GMPXX + GMP linkage: present
- source-status receipts before/after configure/build/final: empty
- `runtimeExecution=false`

All eight required targets compile/package green:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional binary, test, benchmark, test discovery/listing, `ctest`, CLI, fuzzer, help/version command, or custom input executed in CB9.

## 5. Authority and accounting disposition

CB9 is compile evidence only. Candidate `10660365136` is **not** promoted by this turn. Accepted runtime authority remains package/source `10601978228 / 0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

Stable accounting remains **50 events / 14 categories / 36 recurrences**. Project produced-witness debt remains **3**: two M5 nonzero-Z4 debts and one M6 closed-complex debt. `M5-CP3-TB1-R7-CAND-02`, `M5-CP3-TB1-R7-CAND-03`, and `M5-CP3-TB1-R6-REV-OBS-01` are **correction built / runtime unadjudicated** and remain open through R8 Review. Selector publication remains prohibited.

## 6. Exact successor

`M5-CP3-TB1-R8-EXEC` must consume candidate artifact `10660365136` immutably and execute the frozen 446-process gate under `Architecture_M5_CP3_TB1_R8_Artifact_Only_Test_Benchmark_Plan.md`. Any semantic RED routes directly to mandatory `M5-CP3-TB1-R8-REV`; EXEC may not repair tests or production. Even an all-green execution requires independent Review before debt credit, candidate promotion, or selector publication.

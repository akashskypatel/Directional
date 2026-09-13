# M4-CP-COND-CB2 — Code + Build Package-Closure Plan

**Status:** FROZEN by `M4-CP-COND-TB1-REV`
**Boundary:** Code + Build only; compile/package only; **no Directional runtime**
**Semantic source:** **exactly** `b576d061e23873b7b4193b158138d2097c75a728`
**Purpose:** close the immutable test-artifact owner set without changing semantics
**Exact successor:** `M4-CP-COND-TB2-EXEC`; mandatory review after execution: `M4-CP-COND-TB2-REV`

## 1. Frozen diagnosis

TB1 failed package preflight before runtime because CB1 artifact `10312168742` contains only the producer owner executable while accepted selector408 is owned by four binaries. Review re-derived 30 authority-kernel / 262 producer / 75 completion / 41 validation identities; the absent three owners cover 146 accepted rows.

This is a package-closure control experiment. No semantic defect is established. Existing `LESSONS.md` 3 and 170 require changing only the package owner set while holding source/test/fixture/selector semantics fixed.

## 2. Authorized source state

CB2 must build **exactly unchanged** semantic source `b576d061e23873b7b4193b158138d2097c75a728`. No cherry-pick, source repair, test edit, fixture edit, selector edit, CMake semantic edit, reusable-workflow permission/edit, benchmark edit, or generated test discovery is authorized.

Control-plane trigger/caller/document commits may exist on the working branch, but compile source authority must be the exact semantic SHA above. GMP and GMPXX remain mandatory exact-arithmetic dependencies; fallback arithmetic is forbidden.

## 3. Exact compile/package target set

Compile/package these existing targets and no semantic substitute:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`

No test or benchmark binary may be executed in CB2. `runtimeExecution=false` is mandatory.

## 4. Required package receipts

The immutable CB2 artifact must prove before closeout:

- exact semantic source `b576d061e23873b7b4193b158138d2097c75a728`;
- configure/build/preflight exits zero;
- empty source status before/after configure/build/final;
- GMP and GMPXX present in the exact linked build;
- root package checksums verify;
- the four selector owner binaries physically exist in `bin/`;
- `directional_compiled_api_tests` physically exists in `bin/`;
- packaged selector408 is exactly 408 LF rows at SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- its first403 prefix remains SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- no product/test/fixture/selector/build-system semantic byte differs from `b576d061...`;
- `runtimeExecution=false` and no Directional process was launched.

CB2 is compile/package evidence only. It cannot close the candidate or promote CP-COND.

## 5. Frozen artifact-only successor plan

CB2 must emit `Architecture_M4_CP_COND_CB2_Artifact_Only_Test_Benchmark_Plan.md` binding TB2 to the new immutable package while preserving the **same semantic gate** frozen for TB1:

1. fail-closed package/source/GMP/GMPXX/selector/owner-set preflight;
2. 14 focused prospective CP-COND identities, one fresh exact-filter process each;
3. `BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` exactly once as report-only/non-selector evidence, never green credit;
4. complete accepted selector408 census, all 408 identities in fresh exact-filter processes;
5. immutable package/source/selector/execution-view postflight and complete ledger/evidence artifacts;
6. no rebuild/configure/relink/package repair/generated discovery/source-test-fixture-selector mutation during TB2;
7. mandatory successor `M4-CP-COND-TB2-REV` for semantic adjudication, stable accounting, recovery closure and any promotion.

No gate may be removed or added merely to make the rebuilt package green.

## 6. STOP / falsifiers

Stop before compile/package and return to Review if any of the following becomes necessary or true:

- semantic source is anything other than exact `b576d061e23873b7b4193b158138d2097c75a728`;
- any product, test, fixture, selector, CMake semantic, reusable workflow, or benchmark source edit is proposed;
- any of the four selector-owner test binaries cannot be compiled from the frozen source;
- selector408 row count/hash or accepted first403 prefix changes;
- GMP/GMPXX is absent or a fallback exact-arithmetic backend would be used;
- any Directional test/benchmark/runtime process executes during CB2;
- package completeness appears to require changing test ownership or generated discovery instead of compiling existing targets;
- the package is repaired/augmented after its immutable artifact is frozen;
- the TB2 plan changes the TB1 semantic gate surface rather than only rebinding it to the package-closed artifact.

Any falsifier invalidates the package-closure control experiment.

## 7. Recovery disposition

`M4-CP-COND-TB1-EXEC-CAND-01` remains OPEN after CB2 even if compilation is green. Only TB2 runtime plus mandatory `M4-CP-COND-TB2-REV` can prove recovery and adjudicate CP-COND semantics.

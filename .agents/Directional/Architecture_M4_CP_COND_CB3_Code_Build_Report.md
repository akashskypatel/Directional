# M4-CP-COND-CB3 Code + Build Report

**Turn:** `M4-CP-COND-CB3`
**Disposition:** COMPLETE / TEST-AUTHORITY CORRECTION IMPLEMENTED / COMPILE GREEN / RUNTIME UNADJUDICATED
**Product semantics:** unchanged from `b576d061e23873b7b4193b158138d2097c75a728`
**CB3 test-authority source:** `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`
**Runtime in CB3:** none
**Exact successor:** `M4-CP-COND-TB3-EXEC`

## 1. Authorized correction

Only `tests/InputConditionerTests.cpp` changed semantically. `InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved` keeps its identity but no longer obtains its expected negative index from authored `72°/90°` constants or a prefilled numerator.

The test-local oracle now:

1. decodes the actual binary64 mesh/field components into exact GMP integers/rationals by their IEEE-754 bit patterns;
2. derives the unique closed interior face fan from `raw.faces`;
3. proves the raw four-branch field is nonzero, tangent, opposite-paired, orthogonal, equal-norm and consistently handed using exact arithmetic;
4. derives the unique exact/discrete cross-face Z4 branch transport from the raw branch bytes and accumulates the cycle residue;
5. derives the signed principal cycle numerator from that source-derived transport; and
6. independently applies the same oracle to the conditioner-preserved output and requires equality with the raw result.

For the committed witness the exact pre-mutation derivation yields Z4 offsets `[3,3,3,3,3]`, cycle residue `3`, and signed principal numerator `-1`. This is a static/source-side derivation only; no Directional binary was executed in CB3.

## 2. Mutation falsifier

The raw-data discriminator flips one least-significant bit of one raw branch component. The independent oracle must then become inadmissible or produce a different cycle result. For the committed discriminator, exact opposite-pair admissibility is broken. The expected result therefore depends on the raw subject and cannot survive the mutation vacuously.

The oracle does not call production transport/singularity/finalization helpers, does not read production matching/singularity output, and does not recover the answer from authored degree/sector constants.

## 3. Frozen-authority guards

- Selector408 remains 408 LF rows / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.
- First403 remains `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`.
- No `src/**`, `include/**`, public API, CMake semantic, selector, A3/A4 semantic, or reusable-workflow permission change was required.
- Boundary-truncated separatrix remains report-only / non-selector.
- Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

## 4. GitHub compile/package evidence

Authoritative compile run/job: `34785549072 / 103800273458`.

Immutable compile package:

- artifact `10325879420`;
- provider digest `sha256:d046b8cbdcfe22af5ca732139612e96673d597fef47b5e36d1a54b1542493b2b`;
- source `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`;
- root `SHA256SUMS` has **27/27** entries and hashes to `d292ee76bd1234b073084ebdfc772e248dd6757ee477b484dded158463194c2d`;
- packaged source archive hashes to `c5e8ea58d2564a6cf0f70691f14ee2329f3d92b855f0bd58c9e22811494c9c5c`;
- compile log artifact `10326034194`, provider digest `sha256:37b795ef962e4edb00314f165ebf86c32585726d6baf8951fb1822deb521a5f6`.

The required target set compiled and linked GREEN:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`

Preflight and build exit codes are `0`. Source status is empty before configure, after configure, after build, and at final package capture. GMP/GMPXX evidence records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the owner test link. `command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`.

The package manifest was independently verified **27/27** after download. No runtime/test/benchmark execution markers appear in the configure/build evidence.

## 5. Closeout transport retry

The first closeout-document Drive application run `34785876978` failed in `Download and verify Drive patch` before `git apply` because the locally emitted docs diff lacked the mandatory `Directional-Work-Preservation-Patch-v1` metadata envelope (`base_sha`, `diff_body_sha256`, and `intended_paths`). Result evidence records `applied_commit_sha=unavailable`, `runtimeExecution=false`, and no Drive trash/retirement action. No repository semantic or documentation path was mutated by that failed attempt. The bounded retry uses the same reviewed document changes inside the required preservation envelope; no content scope is widened.

## 5. Deliberately not executed

No focused identity, accepted selector identity, report-only identity, benchmark, or other Directional runtime was executed. CB3 claims compilation/package correctness only; semantic runtime authority remains CP3 package `10307919492` / selector408 **408/408** until mandatory TB3 execution and Review.

## 7. Frozen TB3 handoff

`M4-CP-COND-TB3-EXEC` must consume artifact `10325879420` exactly, without rebuild, configure, relink, repair, generated discovery, fixture/source/selector mutation, or permission repair. It must execute the unchanged **14 focused + one report-only boundary + selector408 408/408** surface in 423 fresh exact-filter processes with immutable preflight/postflight. The complete frozen contract is `Architecture_M4_CP_COND_TB3_EXEC_Plan.md`.

`M4-CP-COND-TB3-REV` remains mandatory and exclusively owns candidate closure, package promotion, semantic acceptance, stable-event adjudication, and CP-COND closure.

# M3-CP4c-0 TB-R10 — Focused GMP Portability Verification Report

## Status

**COMPLETE / FOCUSED PASS.** This report owns the bounded corrective verification requested after the user explicitly skipped `M3-CP4c-0-TB-R9-REVIEW-PLAN` and authorized `CB-R10` followed by `TB-R10` for the GMP-related defect only.

This is **not** a full 346-identity CP4c-0 acceptance run. It resolves `M3-CP4c0-TB-R9-CAND-01` only. `M3-CP4c0-TB-R9-CAND-02` remains active, so CP4c-0 remains OPEN and latest accepted runtime remains CP4ab 316/316.

## CB-R10 correction and package authority

- Corrected semantic source: `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`.
- Changed path: `tests/FieldAlignedCurveNetworkTests.cpp` only.
- Correction: preserve the existing `ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip` identity and production predicate, but construct its intended lossy witness independently of `ENumber::to_double(int)` backend behavior. Exact `epsilon = 1/7` is converted through an explicitly lossy numerator/denominator-to-double round trip in test code, and the test first proves the reconstructed direction differs before invoking production exact classification.
- No GMP, exact-number, continuation, selector, fixture, or production semantics changed.
- Compile run/job: `33067140968 / 98499967674`.
- Immutable package artifact: `9644214591`.
- Package ZIP SHA-256: `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`.
- Compile log: `9644214963 / d88c8ff55082db4c27d377688af5400d08f40b329ec305b6538aacc1899201c2`.
- GMP: `libgmp-dev 2:6.3.0+dfsg-2ubuntu6.1`; CMake found `/usr/include/x86_64-linux-gnu`, `/usr/lib/x86_64-linux-gnu/libgmpxx.so`, and `/usr/lib/x86_64-linux-gnu/libgmp.so`; generated test linkage contains both gmpxx and gmp.
- All eight standard targets compiled/linked; preflight exit `0`; build exit `0`; source-status snapshots empty.
- Code+Build boundary: `runtimeExecution=false`; no Directional binary, test, benchmark, discovery, CLI, fuzzer, help/version command, or custom input executed.

## TB-R10 immutable artifact-only authority

- Run/job: `33067370314 / 98500728780`.
- Consumed only package artifact `9644214591` from source `30ef2792e2915e0016dfd11f5fa2b3727e5503c0`.
- Downloaded ZIP SHA-256 matched `b9e7729fb557eddc203e38a1c11564bab3ad180982e10740d4374fe06748a390`.
- Ordinary `unzip`, no package repair.
- Package `SHA256SUMS` verified; build/preflight exit codes `0`; GMP backend metadata verified; all source-status files empty; producer test binary executable.
- Preflight and postflight complete package hash inventories are byte-identical: **PASS**.
- Mutation/configuration flags: `configure=false`, `compile=false`, `relink=false`, `repair=false`, `generatedDiscovery=false`, `performanceBenchmark=false`.

## Focused regression result

Identity:

`ResolvedBranchCorrection.ExactVertexSectorUsesPublishedDirectionAcrossLossyRoundTrip`

Target: `directional_surface_cell_producer_tests`.

Result:

- selected: `1`;
- exit: `0`;
- failures: `0`;
- errors: `0`;
- status: **PASS**;
- harness elapsed: `5 ms`;
- focused safety timeout: `60 s`, not hit.

Result artifact: `9644274456`, SHA-256 `4d80bc1ca8e9d0f624e709eb7c467e5b1c2c880d6a1619f1f8ced95151305693`.

Diagnostic log artifact: `9644274922`, SHA-256 `2c8922ccf03e356db0e78fbe07a4a22bb99019009e4e40669f58bba16fcdd122`.

## Disposition and boundary

`M3-CP4c0-TB-R9-CAND-01` is **RESOLVED / NON-STABLE / TEST-SIDE GMP PORTABILITY**. The TB-R9 failure was caused by a backend-specific test precondition that failed before exercising production behavior; CB-R10 made the intended lossy witness explicit and backend-independent, and TB-R10 proved the unchanged production predicate under the GMP-linked package.

Stable accounting changes by **+0 events / +0 recurrences** and remains **42 events / 14 categories / 28 recurrences**. Produced-witness debt remains **5**. CB-R10 is M3 package **49**.

`M3-CP4c0-TB-R9-CAND-02` remains **ACTIVE / NON-STABLE / TEST-SIDE FIXTURE-PRECONDITION**. The skipped TB-R9 review remains skipped/not completed. No full-gate rerun, `CAND-02` correction, CP4c-0 acceptance, or CP4c-0b entry is implied or authorized by this report.

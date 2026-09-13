# M4-CP-COND-CB2 Code + Build Record

**Turn:** `M4-CP-COND-CB2`
**Disposition:** COMPLETE / COMPILE-PACKAGE GREEN / OWNER SET CLOSED
**Runtime:** not executed
**Semantic source:** `b576d061e23873b7b4193b158138d2097c75a728`
**Mandatory successor:** `M4-CP-COND-TB2-EXEC`; mandatory review after execution: `M4-CP-COND-TB2-REV`

## 1. Scope held fixed

CB2 executed the control experiment frozen by `M4-CP-COND-TB1-REV`: change only compile/package target coverage while holding the semantic source, product/test/fixture/selector/CMake semantics and reusable workflows fixed. No semantic source commit was created.

The exact compiled target set was:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`

No Directional binary, test, benchmark, generated discovery command, CLI, fuzzer, help/version command or custom input was executed.

## 2. Compile/package authority

GitHub Actions run/job `34771486767 / 103761775124` is GREEN.

- immutable result artifact: `10321878900` (`m4-cp-cond-cb2-result-34771486767`)
- provider/download ZIP SHA-256: `d8016a8d0b30c8edcbbd64ac96d752ee5087fd35dc568a1b1c9e4cef9a66ee28`
- compile log artifact: `10321354949`
- compile log SHA-256: `054ff8a2ccfc91837dda77016d08d01594ea60a29d2b6d1d308f0b0ad83ce454`
- packaged source archive SHA-256: `31e667a6891f9f9d2c938da98c7d23d048c3d60f6960e139e379631e7aa70c10`
- root `SHA256SUMS`: 27 entries, all verified; manifest SHA-256 `10f45675750aca16d99fbc69a6affc1a75dd5b112977de5fb32da34e47bf37ad`

Package receipts independently verified after download:

- `metadata/source-commit.txt` is exactly `b576d061e23873b7b4193b158138d2097c75a728`;
- preflight and build exit codes are both `0`;
- all five source-status receipts are empty;
- `metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`;
- GMP evidence includes both `libgmpxx.so` and `libgmp.so` on the authoritative authority-kernel test link command;
- the raw artifact ZIP preserves mode `0755` on all five packaged test executables;
- package contains `lib/libdirectional_core.a` and `lib/libdirectional_pipeline.a` plus all five required test/API executables in `bin/`.

The activity log explicitly records: `No generated Directional binary, test, benchmark, discovery command, ctest, CLI, fuzzer, help/version command, or custom input was executed.`

## 3. Selector/source immutability

The packaged semantic-source archive was extracted without modification. The accepted selector is unchanged:

- `Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt`: exactly 408 LF rows, zero CR bytes;
- selector408 SHA-256: `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`;
- first403 prefix SHA-256: `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`.

No product, test, fixture, selector, CMake semantic or reusable-workflow byte was changed to obtain the package. CB2 therefore satisfies the frozen package-closure prediction without introducing a second explanatory variable.

## 4. Recovery disposition

CB2 proves only that the missing cumulative owner executables can be compiled and packaged from the exact unchanged semantic source. It does **not** provide semantic recovery evidence because no Directional identity executed.

`M4-CP-COND-TB1-EXEC-CAND-01` therefore remains **OPEN / RECOVERY PACKAGE CLOSED / PRE-SEMANTIC / NON-STABLE PENDING TB2 REVIEW**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. Accepted runtime authority remains CP3 package `10307919492` / selector408 **408/408**.

Only `M4-CP-COND-TB2-EXEC` followed by mandatory `M4-CP-COND-TB2-REV` may prove semantic recovery, close the candidate, alter stable accounting or promote CP-COND.

## 5. Successor authority

`Architecture_M4_CP_COND_CB2_Artifact_Only_Test_Benchmark_Plan.md` freezes the artifact-only successor against artifact `10321878900`. It preserves TB1's semantic surface exactly: 14 focused prospective gates, one explicit report-only boundary blocker, the complete accepted selector408 census, and immutable postflight. No package repair or runtime compilation is authorized.

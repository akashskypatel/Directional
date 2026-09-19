# M4-CP4-CB2 — orchestration/package closure Code + Build plan

**Turn:** `M4-CP4-CB2`
**Type:** Code + Build / runtime-free orchestration correction
**Predecessor:** `M4-CP4-TB1-EXEC` ORCHESTRATION INVALID
**Semantic baseline:** CP4 implementation commit `024427475aebf438c678caa27c35415f32c31198`; selector427 byte-frozen

## 1. Goal

Repair only the two deterministic TB1 orchestration/package-closure defects without changing product, test, fixture, selector or benchmark semantics:

1. package every executable owner needed by exact selector427, including `directional_surface_cell_validation_tests`;
2. freeze a corrected TB1-R1 harness whose clean-source preflight checks the receipt names actually emitted by the durable reusable compile workflow and does not invent `source-status-after-package.txt`.

This is not a semantic correction turn. No CP4 implementation behavior, focused identity body, owner mapping, selector row, fixture or benchmark is authorized to change.

## 2. Compile/package authority

Use `.github/workflows/agent-compile-reusable.yml` as the only compile implementation, with mandatory GMP/GMPXX and **all eight standard targets**:

- `directional_core`;
- `directional_pipeline`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_compiled_api_tests`;
- `directional_benchmarks`.

Require exact source identity, clean source receipts, package `SHA256SUMS`, packaged source archive digest, `exactArithmeticBackend=GMP`, explicit `gmpxx` + `gmp` link evidence, executable modes and `runtimeExecution=false`. No generated Directional binary/test/benchmark/discovery/list/help/version/CLI/fuzzer/custom input may execute in CB2.

Package closure must prove all four selector-owner executables are present and executable before CB2 closes:

- authority-kernel;
- producer;
- completion;
- validation.

Do not hard-code a manifest entry count as acceptance authority; record the actual fresh package census and hashes. Historical all-eight packages commonly contained 28 manifest entries and six executable artifacts, but fresh CB2 evidence governs.

## 3. Frozen retry-orchestration correction

Prepare the next artifact-only TB harness/caller without executing it. The corrected harness preflight must verify the reusable compile package's actual clean receipt set:

- `source-status-before-configure.txt`;
- `source-status-preconfigure.txt`;
- `source-status-after-configure.txt`;
- `source-status-after-build.txt`;
- `source-status-final.txt`.

It must not require `source-status-after-package.txt` unless the reusable compile workflow itself is durably changed to emit and bind such a receipt in a separately authorized workflow-policy change; no such change is authorized here.

Freeze exact retry harness/caller bytes and SHA-256 only after the fresh candidate artifact/source/package facts are known. Preserve the existing runtime contract: six focused fresh one-selected processes followed by exact selector427 in file order, one fresh process per row, complete 433-row ledger, benchmark 0, no generated discovery, no repair, exact immutable postflight.

## 4. Semantic immutability and stop conditions

CB2 must not modify:

- `include/**`, `src/**`, `tests/**`, `benchmarks/**`, `cmake/**` or `CMakeLists.txt` semantics;
- `Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt` bytes or owner mapping;
- CP4 frozen definitions, work bounds, exact-width report-only status, produced-subject contracts, A2b/A3 ownership or zero-transport semantics.

If a product/test/fixture/selector edit appears necessary to make the package compile or the retry executable, stop and route to Review/Plan rather than widening CB2.

If mandatory compile/package integrity fails, diagnose and repair only bounded build/orchestration defects within Code + Build. Generated runtime remains forbidden.

## 5. Successor

If all-eight GMP compile/package evidence is green, all four selector-owner executables are packaged, selector427 is still exact, and the corrected retry harness/caller is frozen without runtime, close CB2 with exactly one successor:

**`M4-CP4-TB1-R1-EXEC`** — fresh immutable artifact-only execution against the new CB2 candidate package, re-running all six focused identities plus all 427 selector rows from scratch.

Accepted runtime authority remains package `10565723112` / selector427 **427/427** until a later mandatory Review explicitly promotes new authority.

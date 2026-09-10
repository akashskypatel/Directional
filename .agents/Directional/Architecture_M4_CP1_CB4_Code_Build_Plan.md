# M4-CP1-CB4 Code + Build Plan — package closure and artifact execution contract

**Status:** ISSUED / RUNTIME-FREE / NO PRODUCT-SEMANTIC CHANGE
**Turn:** `M4-CP1-CB4`
**Entering semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Entering accepted runtime authority:** M3 package113/TB48, selector365 365/365
**Frozen M4 gate:** `Architecture_M4_CP1_Required_Green_Selector_373.txt`, SHA-256
`6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`

## 1. Purpose and hard boundary

Correct the two package/control-plane defects adjudicated by `M4-CP1-TB1-REV` without changing M4 product semantics,
test semantics, fixtures, selector membership, or the exact solver. CB4 is Code + Build, so it may author the bounded
artifact-only harness/control logic and compile/package through GitHub Actions, but it executes **no Directional
runtime**.

Package114 is immutable failed-gate evidence and is never repaired in place. CB4 produces a new candidate package only
after proving package closure against the frozen selector.

## 2. Frozen static owner map

Before compile orchestration, re-derive selector373 ownership from the exact semantic source and require this exact
partition:

- `directional_surface_cell_authority_kernel_tests`: **30** rows;
- `directional_surface_cell_producer_tests`: **227** rows;
- `directional_surface_cell_completion_tests`: **75** rows;
- `directional_surface_cell_validation_tests`: **41** rows;
- total **373**, with **0 missing / 0 duplicate** identities;
- first 365: 30 / 219 / 75 / 41;
- rows 366-373: all eight owned by `directional_surface_cell_producer_tests`.

Any changed partition, missing definition, duplicate definition, or selector hash mismatch is a stop. Do not move test
source between targets to make the count agree.

## 3. Semantic no-drift guard

The package correction must compile the exact semantic source
`680f9f1573d3c7e56a273366436463e40e196131`. No change is authorized under `include/`, `src/`, `tests/`,
`benchmarks/fixtures/`, `cmake/DirectionalTests.cmake`, the M4 selector, exact-arithmetic adapters, or A3 solver/validator
source. Documentation and turn-specific harness/control files may advance the branch independently; record the
semantic evidence SHA separately from planning/handoff commits.

If the durable compile workflow cannot build an exact historical/current semantic SHA while the control plane lives at
a later documentation commit, stop and re-plan rather than rebasing product semantics merely for convenience.

## 4. Package-closure compile

Use the mandatory GitHub compile/package workflow with GMP and GMPXX authoritative. Compile at least the four exact
selector-owner test executables, plus their normal library dependencies:

- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`.

Using the durable reusable workflow's established full default target set is acceptable and preferred when it is the
smaller control-plane change; do not invent a new cache namespace or per-turn cache epoch. Do not change reusable
workflow permissions.

Require compile/link success and `runtimeExecution=false`. The resulting candidate package must contain all four owner
executables with executable mode intact, `metadata/source-commit.txt` equal to the semantic source above, GMP/GMPXX
link evidence, the package-owned source archive, and a complete verified `SHA256SUMS`. Record all executable hashes and
the immutable artifact/provider digest. Do not count the package as accepted yet.

## 5. Artifact-only successor harness

Author or adapt one bounded M4 CP1 artifact-only harness using the already-proven M3 pattern rather than a single-binary
filter. It must, before any Directional process:

1. verify the exact candidate artifact ID/provider digest, semantic source, GMP/GMPXX metadata, and every package
   `SHA256SUMS` entry;
2. extract only the package-owned `source/source-<semantic-sha>.tar.gz` into a fresh source view and verify its source
   authority;
3. re-derive the 373-row identity-to-owner map from `cmake/DirectionalTests.cmake` plus exact test definitions and
   require one owner for every selector row with the frozen 30/227/75/41 partition;
4. require every mapped owner binary to exist and be executable;
5. copy immutable package binaries into a fresh execution view and materialize
   `execution-view/test-data/benchmarks/fixtures` only from the package-owned source archive;
6. verify at least one known fixture through the same sibling/legacy layout accepted by `TestFixturePaths.h`, and
   census package, extracted source, and execution view before runtime;
7. pre-author immutable postflight checks proving all three views remain byte/mode unchanged.

The execution view is a derived read-only launch layout, not a repaired package. Do not modify package bytes, synthesize
fixtures externally, use the runner checkout as source/fixture authority, or add a new fallback to `TestFixturePaths`.

## 6. Compile-time/static verification in CB4

CB4 may run static syntax/structure checks that do not execute a Directional generated binary. At minimum verify:

- selector373 hash/count and exact one-owner mapping;
- target list covers every owner binary;
- the successor harness contains explicit zero/multiple-owner, missing-binary, selected-count, fixture-root,
  immutable-census, and mutation fail-closed checks;
- shell/static syntax checks for the harness/control payload;
- source-status evidence shows no semantic source/test/fixture/selector drift;
- GMP/GMPXX linkage and package composition from the GitHub compile result.

No focused test, `--gtest_list_tests`, discovery execution, benchmark, CLI invocation, or other Directional binary may
run in CB4.

## 7. Successor TB plan requirement

Only after the new immutable package has exact artifact/hash authority may CB4 issue the next artifact-only TB plan.
That plan must name the package/harness hashes and require:

- preflight owner mapping **373/373 exact-once** and resolved fixture root before runtime;
- the eight CP1 identities twice from their mapped producer owner, **8 selected / 8 executed** each run;
- the frozen selector373 one identity per fresh process through its mapped owner binary, every row `selected=1`;
- accepted predecessor rows 1-365 reported separately from rows 366-373;
- immutable package/source/execution-view postflight;
- classification of every assertion-level RED, crash, timeout, skip, or nondeterministic receipt.

A complete **373/373 PASS** with all integrity checks green may close M4-CP1 under the standing turn policy. A genuine
assertion-level RED after valid preflight routes normally to Review + Plan. A pre-runtime owner/binary/fixture mismatch
is orchestration failure and confers no semantic gate result.

## 8. Prohibited substitutions

CB4 must not:

- change or shrink selector373;
- merge all tests into `directional_surface_cell_producer_tests`;
- relocate 146 accepted test definitions;
- modify production A3/solver/validator semantics;
- alter test assertions or fixtures;
- change `TestFixturePaths` to accept an unverified runner path;
- edit reusable-workflow permissions;
- repair package114 or execute it again;
- begin CP2/CP3 work.

## 9. Stop condition and predicted receipt

Stop before runtime handoff if the exact semantic source cannot be rebuilt with all four owner executables, if the
frozen owner map does not remain 30/227/75/41, if any package executable/source archive/hash evidence is missing, or if
the pre-authored harness cannot prove the consumer-visible fixture root from package-owned bytes.

**Predicted correction receipt:** the new package will eliminate the 146 owner omissions because it carries all four
established owner binaries; the corrected execution view will eliminate the 38 `test-data` setup failures before their
semantic assertions. Any remaining RED after those controls is not predicted away and must be treated as new runtime
evidence.

# M4-CP4-CB4 — focused test-authority correction Code + Build report

**Turn:** `M4-CP4-CB4`
**Result:** **COMPLETE / TEST-AUTHORITY CORRECTED / COMPILE GREEN / RUNTIME UNADJUDICATED**
**Semantic source:** `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`
**Compile run/job:** `35425760541 / 105851314444`
**Candidate package:** artifact `10578784752`
**Runtime boundary:** compile/package only; no generated Directional runtime executed

## 1. Scope and static proof

CB4 implements only the three test-authority corrections authorized by `M4-CP4-TB1-R2-REV`:

1. `tests/SurfaceComplexSimplificationPhase17Tests.cpp` now reads the repository rawfield header as `(degree, faceCount)`, requires degree `4` and the expected face count, and sizes the test-local matrix as `faceCount x (3*degree)`. No fixture or product parser changed.
2. `tests/SurfaceCellTransitionQuotientTests.cpp` now gives the two focused produced-torus periodic-owner witnesses the accepted row408 hard-rail production precondition: fail-closed SurfaceCells, recovery disabled, retained intermediates, 179/180-degree automatic-feature suppression, and the accepted two fundamental cycles yielding exactly 18 distinct explicit hard edges. Before semantic credit, the witnesses require a `Produced` phase front, at least two distinct produced periodic relation IDs and at least two periodic edges resolving through those IDs. Reordering checks typed semantic owner tuples; the discriminating swap rejects `InvalidPeriodicRelation`; the missing-owner witness clears exactly one selected periodic edge relation and requires `MissingPeriodicRelationOwner` from the checked factory.
3. `tests/FieldTransportAtlasTests.cpp` now uses a bounded genuinely non-flat four-triangle fan for the zero-transport negative. The test independently computes the apex angle defect and requires it to be nonzero before constructing the zero-transport field; the flat positive remains unchanged and the negative still expects `CycleTransportMismatch`.

Static verification before compile proved:

- exactly those three test files changed semantically;
- `git diff --check` clean;
- no product, committed fixture, selector, benchmark, CMake, or durable reusable-workflow semantic change;
- selector427 remains **427 LF rows** / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- the periodic-owner test authority contains explicit runtime multiplicity assertions rather than inferring multiplicity from injected cycles;
- the zero-transport negative proves nonzero intrinsic angle defect before expecting rejection.

## 2. Work-preservation and semantic-source authority

The exact three-file semantic diff was preserved before remote application as `Directional__M4-CP4-CB4__base-ade03e08258e__work-preservation.patch`:

- patch SHA-256: `9b816ba1b2e722116ba6c56911bb378a36b444e4ba314db8a5e79db3d07b1b10`;
- diff-body SHA-256: `487a53862c876d274917a2dac75f0b216c979aa1307531d7982792ce04a63fd3`;
- verified with `git apply --check` and `git diff --check` against exact snapshot base `ade03e08258edec729fe09407180d2e833b20dba`.

Drive-apply run/job `35425671573 / 105851079167` validated and applied those exact bytes. Result artifact `10578664663` has provider SHA-256 `2c1d8d652ac878517c10e35a71c5a8a629f3601de639f2d38cb18eaa1f77741f`; log artifact `10578994381` has `62cd74762d0b248cbc2496aae46e38cee1df7da28c6cdc46b5fb9f62edbaa6d2`. The workflow produced semantic commit `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, recorded `runtimeExecution=false`, and required owner-side Drive retirement; the staged Drive file was then permanently deleted through the user-authorized connector.

## 3. Compile/package evidence

The mandatory reusable GMP/GMPXX compile is GREEN:

- workflow run/job: `35425760541 / 105851314444`;
- exact requested/compiled source: `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`;
- candidate result/package artifact: `10578784752`, provider SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`;
- persistent compile-log artifact: `10579290075`, provider SHA-256 `99fa0e16d6f5e110a3157008bb58b3064d404eeb9f1b73177cbd705f79790868`;
- package `SHA256SUMS` SHA-256 `8d3c8902504ed6ef4f09f26329fcf7bddeeaa3fff9c023772c5f7e81abcb33b2`, all **28/28** entries verified;
- packaged source archive SHA-256 `dd7dd3351ad3ea10f56ef9ce2021fc8ea84e10d682560b93f70ca1d79b089175`;
- all five source-status receipts are empty;
- configure authority records `DIRECTIONAL_ENABLE_GMP=ON`; generated authoritative link evidence includes both `gmpxx` and `gmp`; `exactArithmeticBackend=GMP`;
- eight approved targets compiled/linked: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`;
- command boundary records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`, and out-of-tree build authority.

No generated Directional binary, GoogleTest discovery/listing, test, benchmark, `ctest`, CLI, fuzzer, help/version command, or custom input executed in CB4.

## 4. Disposition

CB4 is compile-valid only. It does **not** promote candidate artifact `10578784752`, discharge any produced-witness debt, close any R2 Review candidate, change accepted runtime authority, or change stable regression accounting. Accepted M4 runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**.

`M4-CP4-TB1-R2-REV-CAND-01/02/03` are therefore **CORRECTED IN CB4 / RUNTIME RE-PROOF PENDING / NON-STABLE**. `M4-CP4-TB1-R2-REV-OBS-01` remains non-gating and is frozen into the R3 execution-control requirement: the semantic stop field must preserve the first semantic non-green or be explicitly encoded as the last; the complete ledger/raw logs remain authoritative.

## 5. Exact successor

Exact successor is **`M4-CP4-TB1-R3-EXEC`** under `Architecture_M4_CP4_TB1_R3_Artifact_Only_Test_Benchmark_Plan.md`, consuming immutable candidate artifact `10578784752` directly with no rebuild or package repair. R3 must execute all six focused identities and exact selector427 under immutable pre/postflight. Any trustworthy semantic result routes to mandatory runtime-free **`M4-CP4-TB1-R3-REV`**.

Tool-call ledger: partial/unknown after conversation compaction; no reconstructed exact total is claimed.

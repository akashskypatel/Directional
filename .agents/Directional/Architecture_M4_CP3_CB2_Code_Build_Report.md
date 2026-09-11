# M4-CP3-CB2 Code + Build Report — family-free baseline parity A3 semantic core

**Status:** COMPLETE / COMPILE + PACKAGE GREEN / RUNTIME-FREE
**Turn:** `M4-CP3-CB2`
**Normative definition:** `Architecture_M4_DEFN_Frozen_Definitions.md` §17
**Accepted runtime predecessor:** package117 / selector382 **382/382**
**Candidate successor package:** package118 / selector394
**Evidence source:** `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`
**Exact next:** `M4-CP3-TB1-EXEC`

## 1. Boundary and result

CB2 implemented and compile-validated the frozen family/sign-free production-baseline A3 semantic core. No production A3→A4 cutover was performed and no generated Directional binary was executed.

The implementation now provides:

- one exact positive subdivision count per full A2b span, independent of `ConformityFamily` / `ConformitySign`;
- exact region-boundary incidence multiplicity, including same-region double incidence and one-ended terminal/exterior handling;
- exact minimum-cardinality T-join parity optimization plus canonical lex-prefix constrained refinement;
- compact exact `{span, exactOrdinal}` breakpoint identity;
- a parity certificate carrying residual/T-set, component/exterior, optimum/selected-flip, lex-refinement, count/parity and semantic-digest evidence;
- an independent validator that reconstructs baseline parity authority from topology/input rather than trusting producer-derived rows;
- twelve deterministic regression/oracle identities for the frozen §17 contract;
- an explicit production-baseline binder separated structurally from the retained historical framed solver surface.

Accepted selector382 was not edited. Candidate selector394 appends only the twelve new CB2 identities.

## 2. Source authority and bounded compile repair

The primary implementation landed at `0461cc14d4ebe19a5d4ffddf5dc5a5a8ea944d0e`. Its first compile attempt was run `34553011994`, job `103119678993`, and failed in `GlobalConformityParityGraph.cpp` before package creation.

The first actionable compiler error was an unqualified sibling-namespace type:

```text
error: ‘ExactWeight’ was not declared in this scope;
did you mean ‘directional::geometry::global_conformity_detail::ExactWeight’?
```

The correction was deliberately narrow: the three `ExactWeight` uses in the new parity-graph translation unit were qualified as `global_conformity_detail::ExactWeight`. No algorithm, contract, test expectation, selector byte, CMake target, reusable workflow permission, or runtime behavior changed. The repaired semantic source is:

```text
c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc
```

The compile-repair preservation patch has SHA-256 `44791c47b59fc93f49750baf9cd0766a34a49541d19e032fc734bc3da5f40a58` and diff-body SHA-256 `08c7d0cee647bb31864efac7d7de349b77f1dbb8b0b9cc37ecb1d5ae8959d366`.

## 3. Compile/package evidence

The diagnosed retry used the mandatory durable compile reusable and exact semantic source `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`.

| Evidence | Authority |
|---|---|
| workflow run | `34555543569` |
| compile job | `103127378612` |
| trigger event SHA | `54c20e8900a496a99bb913278ef367d969860a26` |
| semantic source | `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc` |
| result/package artifact | `10182447649` — `m4-cp3-cb2-package118-result-34555543569` |
| result/package SHA-256 | `1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5` |
| compile-log artifact | `10182448078` — `m4-cp3-cb2-package118-log-34555543569` |
| compile-log SHA-256 | `815b33bd493ff41268c6acc60506ae5b8f4d2987f7378fe29746af33cf018b22` |
| schema-validation artifact | `10182407330` — SHA-256 `c3b3f8fa32ec16517aabb2744f2b6947b21e8f045ec8b972913c3641e1fd0c82` |

Package118 verification established:

- provider artifact digest equals the downloaded ZIP SHA-256 above;
- recursive self-excluding `SHA256SUMS` verifies **28/28** files and covers the exact package file set;
- `metadata/source-commit.txt` is exactly `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`;
- preflight and final build exit codes are both `0`;
- source-status records are empty before/after configure/build;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`;
- `DIRECTIONAL_ENABLE_GMP=ON`, `exactArithmeticBackend=GMP`, and the authoritative link command contains both `gmpxx` and `gmp`;
- all eight approved targets linked:
  - `directional_core`
  - `directional_pipeline`
  - `directional_surface_cell_authority_kernel_tests`
  - `directional_surface_cell_producer_tests`
  - `directional_surface_cell_completion_tests`
  - `directional_surface_cell_validation_tests`
  - `directional_compiled_api_tests`
  - `directional_benchmarks`.

No test, benchmark, `ctest`, discovery/list/help/version command, CLI, fuzzer, or custom Directional input executed in CB2.

## 4. Selector394 publication facts

`Architecture_M4_CP3_Required_Green_Selector_394.txt` contains exactly **394 LF rows** at SHA-256:

```text
6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
```

Its first **382** rows are byte-identical to accepted selector382 and hash to:

```text
1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f
```

The twelve appended identities, rows 383-394, are all producer-owned `GlobalConformityBaseline.*` tests. Static ownership is therefore **30 authority-kernel / 248 producer / 75 completion / 41 validation = 394**.

Candidate selector394 is compile-valid only. It is not accepted runtime authority until the artifact-only TB and review gates succeed. Package117 / selector382 **382/382** therefore remains the accepted runtime authority at CB2 closeout.

## 5. Acceptance against the CB2 plan

CB2 satisfies every compile-time exit criterion:

- family/sign-free input/product/scheduler/certificate/validator matches frozen §17;
- all twelve prescribed regression/oracle identities exist and compile;
- selector382 is byte-unchanged and an exact prefix of selector394;
- production baseline cannot dispatch through the retained framed solver entry surface;
- exact pushed repaired source compiled through mandatory GMP/GMPXX and produced immutable package118 evidence;
- no Directional runtime occurred;
- the exact package118 artifact-only TB plan is issued as `Architecture_M4_CP3_TB1_Test_Benchmark_Plan.md`.

Production A3→A4 cutover remains explicitly deferred. Stable regression accounting remains **47 events / 14 categories / 33 recurrences** and produced-witness debt remains **5**.

## 6. Next state

Exact next is artifact-only **`M4-CP3-TB1-EXEC`** against package118 artifact `10182447649`. TB-EXEC executes the frozen plan and preserves raw evidence only. It does not rebuild, mutate semantic source/package bytes, diagnose by editing, promote package118, or perform A3→A4 cutover.

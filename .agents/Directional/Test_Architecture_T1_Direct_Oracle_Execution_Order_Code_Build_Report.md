# T1 Direct-Oracle Execution Order — Code + Build Report

**Status:** completed; immutable runtime acceptance required  
**Turn type:** Code + Build only  
**Production behavior delta:** none  
**Date:** 2026-08-09 UTC  
**Review policy:** `never`

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
Draft PR: #8, open and unmerged

## 1. Objective and result

This turn closes the compile/package portion of the T1 direct-oracle execution-order correction identified by immutable artifact `9040549377`.

The only implementation change moves the existing independent product-oracle observation in `tests/SurfaceCellDesignAcceptanceTests.cpp` so that it executes immediately after a returned `RemeshResult` and before the unchanged fatal `ASSERT_TRUE(result.success)` product assertion.

The correction compiles and packages successfully. It does **not** establish runtime acceptance. No generated Directional binary, test, discovery command, benchmark, `ctest`, CLI/GUI command, help/list/version command, or custom input was executed in this Code + Build turn.

M1 remains blocked until the following immutable Test + Benchmark turn accepts this artifact.

## 2. Exact source authority

| Evidence | Value |
|---|---|
| Entering branch head | `4cee37f202a8781980b57677a110380f1596d527` |
| Implementation commit | `7c169ddf8167093c16755f2160e224994e50307c` |
| Implementation source blob before | `0cef4afa8d12606bab11e2f2aba2313df1f99e47` |
| Implementation source blob after | `aff7894aae3397bef47be777a8bf7e2fbb0c27ef` |
| Successful build/event commit | `92231989472e31a81fe1394ddb3918a957f4bc57` |
| Workflow verifier-fix commit | `05145df93df4512892ef2e07d1263cd11ce59b5b` |
| Workflow cleanup commit | `e28ec8c995986cbfd5bd99084c33e6e23ca23a00` |
| Trigger cleanup commit | `083aacc6413e2d704a38d119f2081bedcaf6b8ca` |

The implementation diff is exactly one source file and one statement-block relocation. No predicate, expected value, fixture, production option, public call, or existing product assertion changed.

Before:

```text
result = remesh_from_raw_cross_field(...)
ASSERT_TRUE(result.success)
... unchanged product assertions ...
independentOracle = inspect_surface_cell_product(input, result)
EXPECT_TRUE(independentOracle.ok())
```

After:

```text
result = remesh_from_raw_cross_field(...)
independentOracle = inspect_surface_cell_product(input, result)
EXPECT_TRUE(independentOracle.ok())
ASSERT_TRUE(result.success)
... unchanged product assertions ...
```

The independent oracle remains nonfatal and is evaluated exactly once for every returned result. A production call that does not return still cannot be inspected; that remains runtime/resource evidence rather than synthesized oracle evidence.

## 3. Scope verification

Implementation path changed:

- `tests/SurfaceCellDesignAcceptanceTests.cpp`

Unchanged implementation authority includes:

- all production source and public API;
- fixtures and benchmark manifests;
- `tests/support/SurfaceCellProductOracle.cpp`;
- `tests/support/SurfaceCellProductOracle.h`;
- `tests/SurfaceCellProductOracleTests.cpp`;
- `cmake/DirectionalTests.cmake`;
- production validators, tracing, arrangement, completion, optimizer, quotient, pipeline behavior, and benchmark-quality decisions.

The accepted test-oracle source/CMake blobs packaged by the successful build are:

- `cmake/DirectionalTests.cmake` — `1a951f040e9a9d90ae45bcfd0891ef1ca1758eb1`;
- `tests/SurfaceCellDesignAcceptanceTests.cpp` — `aff7894aae3397bef47be777a8bf7e2fbb0c27ef`;
- `tests/SurfaceCellProductOracleTests.cpp` — `28932c8c2dbe844b62f8fe848e6ebb9ef67550de`;
- `tests/support/SurfaceCellProductOracle.cpp` — `e3b04f4c45ab9acaa078c29defb868326db504dd`;
- `tests/support/SurfaceCellProductOracle.h` — `6d3130238bb283e56e42cdf2f4864f5cb8f567d1`.

Static workflow inspection verified the oracle call occurs before the fatal success assertion and that the implementation diff contains only the same four nonblank oracle-observation lines removed from the old position and added at the new position.

## 4. Mandatory repeated-pattern review

| Pattern | Touched? | Exact affected boundary | Corrective invariant / evidence | Following counterfactual or representative evidence |
|---|---|---|---|---|
| `RP-01` | no semantic-domain change | typed test-oracle index/topology/lineage domains | oracle support and its source blob are unchanged | retain exact 29/29 mutation suite |
| `RP-02` | **yes, primary** | `SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput` | independent oracle now observes every returned `RemeshResult` before any fatal production-success assertion; existing product assertions remain unchanged | Bunny returned failure must emit independent oracle evidence before the unchanged product failure; four green cases remain green; 29/29 oracle suite |
| `RP-03` | no | production disposition versus oracle report | separate values and assertions remain unchanged | disposition mutation suite retained |
| `RP-04` | no | no algorithm/search/work change | statement relocation only; no new recursion, loop, retry, or cumulative state | following bounded runtime only |
| `RP-05` | no | canonical oracle identity | oracle implementation unchanged | canonical row/cycle/reversal metamorphic contract retained |
| `RP-06` | no | storage/authority ownership | no storage or production state changed | byte-identical oracle support and production source |
| `RP-07` | no | cyclic face/boundary logic | cyclic implementation unchanged | cyclic/reversed mutation contracts retained |
| `RP-08` | no | producer/fallback disposition | production options and product assertions unchanged | direct fallback/recovery/backend/origin evidence retained |
| `RP-09` | no | chart/relation authority | no product resolver or relation-consumption logic changed | retained 18 focused contracts; torus remains separate known-red authority |

No new stable regression event or recurrence is created by this test-architecture correction. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains the active production regression.

## 5. Build authority

Authoritative successful run:

| Evidence | Value |
|---|---|
| Workflow run / job | `31324710550 / 93273122696` |
| Event/build commit | `92231989472e31a81fe1394ddb3918a957f4bc57` |
| Result artifact | `9041289209` — `t1-direct-oracle-execution-order-code-build` |
| Result artifact SHA-256 | `c40dd0207d842dd4b7f52ccc6a7358f049d8d359bc476b0ef9090dff061e85ad` |
| Log artifact | `9041289317` — `t1-direct-oracle-execution-order-code-build-logs` |
| Log artifact SHA-256 | `899b952308fc378a919794191df5374113fb1f29343bb22759c4408b0a82dd13` |
| Recursive manifest | **51/51** entries; manifest digest `0221c7e2dfce157461170e9da2add52a6ccfbdf800d1490926d00206bb9f207d` |
| Retention | through 2026-08-23 UTC |
| Runtime boundary | `runtimeExecution=false` |

Configuration/toolchain:

- Ubuntu 24.04;
- Release;
- Ninja;
- `BUILD_SHARED_LIBS=OFF`;
- GoogleTest discovery mode `PRE_TEST`;
- CMake 3.31.6;
- GCC 13.3.0;
- Ninja 1.13.2;
- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`;
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`;
- polyscope `59da72df6517cab8379865899bdffdbc96171301`.

Exactly eight approved targets compiled and linked:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_oracle_tests`;
6. `directional_surface_cell_completion_tests`;
7. `directional_surface_cell_validation_tests`;
8. `directional_benchmarks`.

Ninja completed **117/117** with exit status zero in **8:26.53** wall time and peak resident set **1,834,136 KiB**.

## 6. Immutable package verification

The downloaded successful package was verified after the run:

- both outer ZIP SHA-256 values match GitHub artifact metadata;
- recursive `SHA256SUMS` passes **51/51**;
- package contains 52 regular files including the checksum manifest;
- inventory contains six ELF executables, two static libraries, and all 27 fixture files;
- exact 29-name oracle manifest remains present with labels `contract-required;oracle-mutation`;
- oracle manifest SHA-256 is `7bf35470385bd90d5d8bf69cdd7af675a25b599d22d1a352343fb2eeb3d3f3c0`;
- implementation patch SHA-256 is `9bd727649d10f9d66246cb8e82c15d5beaa88cfb33189d1cc543f4c7d8fa1572`;
- source archive SHA-256 is `b31492fa478b1e4c2b2369198bde320027d3c12c4e964835b055afef8e084e61`;
- compile database SHA-256 is `1fa77cb933c96829d3c41fee73e072da6460c7eb9301e24e7865d2c902616885`;
- packaged `final-blobs.txt` SHA-256 is `e117a286e24379498e5be39a24f88320be485cb796a4ddd073a9070fedbca48d`;
- archived implementation tree contains only the permanent `.github/workflows/agent-source-snapshot.yml` workflow;
- the temporary build workflow and trigger were removed from the live branch after artifact verification.

The package authority records:

- implementation commit `7c169ddf8167093c16755f2160e224994e50307c`;
- event/build commit `92231989472e31a81fe1394ddb3918a957f4bc57`;
- entering T1 runtime artifact `9040549377`;
- entering branch head `4cee37f202a8781980b57677a110380f1596d527`;
- `runtimeExecution=false`;
- review policy `never`.

## 7. Workflow-verifier false positive

Initial workflow run `31324642747` / job `93272950162` stopped in the static source-verification step before prerequisite installation, configuration, or compilation. Its Python checker incorrectly treated relocated blank-line placement as a non-order source change.

That first attempt:

- executed no generated Directional binary;
- ran no test, discovery, benchmark, or `ctest` command;
- did not modify the implementation source;
- produced only diagnostic log artifact `9041168513`.

The workflow verifier was corrected to compare the exact nonblank added/removed oracle block. The implementation commit remained `7c169ddf8167093c16755f2160e224994e50307c`. The successful authoritative build is run `31324710550` only.

This infrastructure false positive is not a product regression or test-authority recurrence.

## 8. Acceptance state

Code + Build acceptance is complete:

- scope is exactly the authorized statement-order change;
- all existing product assertions are preserved unchanged;
- production and oracle-support behavior are unchanged;
- eight targets compile/link **117/117**;
- immutable package authority retains the exact 29-name oracle manifest;
- `runtimeExecution=false`.

T1 direct integration remains **pending immutable runtime acceptance**. This Code + Build result must not be promoted to test acceptance by compilation alone.

## 9. Mandatory next turn

Type: **Test + Benchmark**

Consume exactly:

- result artifact `9041289209`;
- log artifact `9041289317`;
- implementation `7c169ddf8167093c16755f2160e224994e50307c`;
- build/event commit `92231989472e31a81fe1394ddb3918a957f4bc57`.

The following immutable turn must:

1. verify both outer ZIP digests, all **51/51** manifest entries, package/source/dependency closure, exact patch, six-executable/two-library/27-fixture inventory, and `runtimeExecution=false`;
2. rebuild, relink, edit, substitute, or regenerate nothing;
3. discover `directional_surface_cell_oracle_tests` exactly once and require the unchanged exact 29-name manifest;
4. run all 29 oracle contracts individually and require **29/29**;
5. retain the 18 focused contracts and bounded producer/completion/validation/API authority;
6. run the six existing direct acceptance cases in fresh processes;
7. require Plane, MultiFaceSeam, CloseSheets, and Cylinder to remain green with no oracle issue;
8. require every direct product process that **returns** a failed result to emit independent oracle evidence before the unchanged fatal `result.success` assertion failure;
9. keep Bunny/Vase known-red product status explicit; do not disable, convert to expected failure, or count them green;
10. use a bounded process guard for any nonreturning known-red case and classify timeout only as runtime-safety evidence;
11. accept T1 only if there is no oracle false positive/negative, no package/discovery authority gap, no assertion weakening, and every returned direct result reaches the oracle.

If that immutable acceptance passes, M1 authority-kernel Code + Build may begin. T2 remains responsible for the complete ten-case semantic fixture matrix and declared resource budgets.

# M1c Field-Transition Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** Test + Benchmark only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Input:** exact immutable M1c Code + Build artifact  
**Source/build mutation:** prohibited  
**Review policy:** `never`

## 1. Objective

Semantically validate the exact M1c build without rebuilding, relinking, regenerating, editing, substituting, or repairing product/test/fixture content.

M1c changes only the authoritative `fields::CrossFieldEdgeTransition` consumer inside:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`.

The turn must prove:

1. typed source-face/source-vertex authority preserves the intended transition truth table;
2. canonical source-edge identity is endpoint-order invariant;
3. quarter-turn transport is exact modulo four and reverse traversal is algebraic inverse;
4. malformed authoritative metadata remains fail-closed and never falls through to legacy matching;
5. the untouched legacy fallback remains unchanged;
6. M1b/M1a/T1 and direct required-green product authority remain preserved.

A focused pass alone is not acceptance.

## 2. Exact immutable authority

| Evidence | Required value |
|---|---|
| Migration base | `512d9523f13158a9f71b406b6db7137a1db3c504` |
| M1c implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Build/event commit | `ebda31859a18005844f81274393211991361cbbb` |
| Build run/job | `31334345368 / 93297618568` |
| Result artifact | `9043971772` |
| Result SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Package manifest | **54/54**, `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| Package regular files | **55**, including manifest |
| Compile closure | Release/static/Ninja **120/120** |
| Runtime in build turn | **false** |

Expected packaged producer executable SHA-256:
`9608ec2a0fc8eec52e4ceb61df53c0aae5670f9834b358a08e390ac9bb93fbdd`.

Expected unchanged preservation executables:

- oracle: `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority-kernel: `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation: `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

## 3. Immutable preflight

Before executing any packaged Directional binary:

1. download exact artifacts `9043971772` and `9043971968` by build-run/artifact identity;
2. verify each GitHub artifact digest exactly;
3. reject absolute or path-escaping ZIP entries;
4. verify `SHA256SUMS` itself has SHA-256 `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d`;
5. verify every **54/54** packaged checksum;
6. verify `metadata/build-authority.json` identifies implementation `e139fca...`, build event `ebda318...`, run `31334345368`, `runtimeExecution=false`, M1c focused count 6, M1b count 6, M1a count 14, and T1 count 29;
7. verify source blobs and the producer/oracle/authority/validation executable content hashes;
8. verify the expected fixture manifest/files are present;
9. record original outer ZIP hashes for postflight comparison.

If archive extraction strips executable mode, restore only executable permission bits **after** content-hash verification. Permission restoration must not change file content.

Any package/content mismatch is a hard stop.

## 4. Prohibited operations

Do not:

- configure CMake;
- compile or link anything;
- regenerate tests or fixtures;
- edit, patch, substitute, or repair packaged product/test/fixture content;
- copy in a different executable or fixture;
- convert a failing required gate into an expected failure;
- use zero-test selection as success.

Runtime fixture locators may be non-regular filesystem metadata when required, provided packaged regular-file content remains unchanged.

## 5. Runtime sequence

### A. M1c focused discovery authority

Use only `bin/directional_surface_cell_producer_tests`.

Discover the dedicated suite and require exactly these six unique names:

1. `SurfaceCellFieldTransitionAuthorityMigration.ForwardQuarterTurnUsesTypedModuloTransport`;
2. `SurfaceCellFieldTransitionAuthorityMigration.ReverseTraversalUsesExactQuarterTurnInverse`;
3. `SurfaceCellFieldTransitionAuthorityMigration.EquivalentQuarterTurnsNormalizeSemantically`;
4. `SurfaceCellFieldTransitionAuthorityMigration.ReversedSourceEdgeEndpointsPreserveSemanticIdentity`;
5. `SurfaceCellFieldTransitionAuthorityMigration.MalformedAuthoritativeFaceOrEdgeFailsClosed`;
6. `SurfaceCellFieldTransitionAuthorityMigration.LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent`.

Reject missing, duplicate, extra selected M1c members, or zero selection.

### B. M1c focused semantic contracts

Run each of the six contracts individually in a fresh process. Require **6/6**.

Record filter, selected count, stdout/stderr, return code, and elapsed time for every contract.

These are relation-focused gates:

- forward +1 transport;
- exact reverse inverse;
- `+5 == +1` semantically while raw compatibility matching is preserved;
- reversed source-edge endpoints preserve semantic identity;
- malformed authoritative face/edge fails closed despite valid fallback inputs;
- `edgeTransitions == nullptr` legacy matching fallback remains unchanged.

### C. Existing transition counterexamples

Run and require green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

The periodic tamper must still reject with `PeriodicHolonomyMismatch`; do not weaken the expected typed failure.

### D. Complete relevant producer preservation

Run the complete packaged producer test executable under an explicit process guard large enough for the accepted suite. Require:

- nonzero selected-test count;
- no disabled/filtered required tests masquerading as success;
- zero unexpected failures.

If the complete producer target contains intentionally long product cases that make a single aggregate process impractical, use the repository's accepted segmented procedure while retaining exact selection accounting. Do not omit a required segment silently.

### E. M1b preservation

Using the unchanged packaged validation executable:

1. discover exactly the six `SurfaceOptimizationRailAuthorityMigration` contracts;
2. run them individually in fresh processes and require **6/6**;
3. require complete validation discovery to remain exactly **77**;
4. run complete validation and require **77/77**.

This is the accepted M1b preservation gate; M1c focused tests do not substitute for it.

### F. M1a authority-kernel preservation

Using `directional_surface_cell_authority_kernel_tests`:

- require discovery exactly **14**;
- run all 14 individually or through the already accepted exact procedure;
- require **14/14**.

### G. T1 independent-oracle preservation

Using `directional_surface_cell_oracle_tests`:

- require discovery exactly **29**;
- execute the accepted oracle suite;
- require **29/29**.

### H. Direct required-green product preservation

Repeat the exact accepted M1b direct-product procedure for:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

Each must:

1. select exactly the intended existing direct test;
2. use direct `SurfaceCells`, fail-closed fallback, and recovery-disabled semantics already encoded by the test;
3. return success;
4. pass the independent product oracle;
5. preserve valid pure-quad/topology/lineage/origin/terminal-stage requirements.

Use `.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md` and its accepted report as the command/selection authority rather than inventing new product tests.

### I. Bunny and Vase standing comparison

Bunny and Vase are **not green acceptance baselines**.

Per explicit user authorization, these long-running cases may use a temporary artifact-only GitHub Actions workflow to avoid local execution-tool timeout issues. The workflow must:

1. download exact M1c artifact `9043971772` from build run `31334345368`;
2. verify GitHub digest, all 54 package checksums, implementation metadata, and producer executable hash before runtime;
3. never configure/build/relink/regenerate/substitute/edit packaged regular content;
4. restore executable mode only after hash verification if required;
5. run the exact existing Bunny/Vase tests with explicit process guards;
6. retain filter, selected count, stdout/stderr, return code, elapsed time, and evidence-artifact digest;
7. treat workflow success as orchestration success only and classify the GoogleTest result from logs;
8. delete temporary workflow/trigger files before turn closeout.

Comparison authority from accepted M1b:

- Bunny: known-red `NotProductionReady:completion`, independent oracle rejects the invalid returned product before the fatal success assertion;
- Vase: bounded nonreturn at 60 s, safety-only evidence.

A different failure mode, loss of independent-oracle ordering, crash, unbounded process, or unexpected product success is material evidence requiring investigation. Do not relabel either case merely to make the turn green.

## 6. Postflight immutability

After all runtime work:

1. rehash the original downloaded artifact ZIPs and require exact equality with preflight/GitHub digests;
2. reverify `SHA256SUMS` and every **54/54** packaged member;
3. confirm no packaged regular file content changed;
4. record any permission-only executable restoration separately;
5. if a temporary GitHub Actions runtime workflow was used, remove it and its trigger/helper files before closeout.

## 7. Acceptance criteria

M1c becomes immutable accepted only if all are true:

1. preflight package/source/executable authority is exact;
2. M1c discovery is exactly six and focused contracts are **6/6**;
3. all three explicit pre-existing transition counterexamples remain green;
4. complete relevant producer preservation has zero unexpected failures and nonzero exact selection authority;
5. M1b focused contracts remain **6/6** and full validation remains **77/77**;
6. M1a remains exact 14 and **14/14**;
7. T1 remains exact 29 and **29/29**;
8. Plane/MultiFaceSeam/CloseSheets/Cylinder remain green and independent-oracle clean;
9. Bunny/Vase remain explicitly classified from evidence without synthetic acceptance;
10. postflight preserves both artifact ZIP hashes and all **54/54** package checksums;
11. no source/build/product/test/fixture mutation occurred.

Only then may project records say M1c is accepted and plan another production consumer.

## 8. Failure policy

If any required-green gate regresses:

- remain at M1c;
- capture exact failing semantic relation and independent evidence;
- update the stable regression tracker only if previously accepted authority is genuinely lost;
- return to a corrective **Code + Build** turn;
- do not advance to another M1 consumer, G4 remediation, or broader architecture slice.

If package authority fails before runtime, stop without executing binaries.

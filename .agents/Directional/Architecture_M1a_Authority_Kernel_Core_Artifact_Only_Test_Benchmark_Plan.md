# M1a Authority Kernel Core — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** Test + Benchmark only  
**Architecture milestone:** M1a — authority kernel core  
**Implementation under test:** `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7`  
**Production behavior delta from Code + Build:** none  
**Review policy:** `never`

## 1. Objective

Accept or reject the M1a authority-domain kernel using only the immutable compile artifact from the completed Code + Build turn. This turn validates strong domain separation, exact grid-automorphism algebra, source-support representation, transition/route semantics, and compatibility-adapter counterexamples while preserving the already accepted T1 oracle and direct production comparison boundary.

No implementation, test, fixture, CMake, validator, benchmark, workflow, or production source may be repaired in this turn. Any semantic failure is reported and returned to a later Code + Build.

## 2. Immutable authority

Use exactly:

| Evidence | Value |
|---|---|
| Entering pre-M1a branch head | `9f1d3ebd91403252e990f785c3521588197b4fd4` |
| M1a implementation | `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7` |
| Build/event commit | `a29c1f673ea93e1614751f42a0c1fef94d23e1fe` |
| Workflow run/job | `31327073928 / 93279043100` |
| Result artifact | `9041930767` |
| Result SHA-256 | `1c1325c038ffe26b80e00dbb69fb15de8b0d0a42673d9720f28bcd9de8549ec5` |
| Log artifact | `9041930871` |
| Log SHA-256 | `e99e053ea4503b720dbe9b6c9ed4762a4eedcbf67c15261e8ea4317824c427cb` |
| Recursive manifest | **53/53**, `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6` |
| Package regular files | **54** including manifest |
| Compile closure | Release/static/Ninja **120/120** |
| Code + Build boundary | `runtimeExecution=false` |
| Retention | through **2026-08-23 UTC** |

Accepted comparison authority remains T1 artifact `9041289209` and production G4 artifact `9031804178` where explicitly referenced.

## 3. Preflight

Before executing any packaged binary:

1. verify both outer ZIP SHA-256 digests exactly;
2. reject unsafe or escaping archive paths;
3. extract into an isolated directory without changing package regular files;
4. verify all **53/53** `SHA256SUMS` members and the manifest digest;
5. verify package inventory:
   - seven ELF executables;
   - two static libraries;
   - 27 fixtures;
   - source patch/archive/compile database;
   - build and command-boundary metadata;
   - 14-name authority-kernel static manifest;
   - unchanged 29-name T1 oracle manifest;
6. verify `runtimeExecution=false` in both build-authority and command-boundary evidence;
7. verify implementation/event commits and source blobs from the Code + Build report;
8. verify all eight pre-existing binaries/libraries remain byte-identical to accepted T1 artifact `9041289209`;
9. add only a non-regular runtime locator such as `bin/test-data -> ../test-data` if needed; do not mutate any packaged regular file.

Any package/source/dependency mismatch is a stop condition.

## 4. Authority-kernel discovery and execution

Run `directional_surface_cell_authority_kernel_tests --gtest_list_tests` **exactly once** and require the discovered test set to match the immutable 14-name manifest exactly, with no missing or extra tests.

Then run each of the 14 tests individually in a fresh process:

1. `SurfaceCellAuthorityKernel.StrongIdsAreStaticallyNonInterconvertible`
2. `SurfaceCellAuthorityKernel.CheckedLegacyConversionAcceptsAndRejectsDomainErrors`
3. `SurfaceCellAuthorityKernel.NumericCoincidenceDoesNotConflateDomains`
4. `SurfaceCellAuthorityKernel.SourceEdgeCanonicalizationPreservesExplicitOrientation`
5. `SurfaceCellAuthorityKernel.SourceSupportAlternativesRemainTypeDistinct`
6. `SurfaceCellAuthorityKernel.QuarterTurnNormalizesAndCyclesExactly`
7. `SurfaceCellAuthorityKernel.GridAutomorphismIdentityInverseAndAssociativityAreExact`
8. `SurfaceCellAuthorityKernel.NonzeroRotationTranslationRoundTripIsExact`
9. `SurfaceCellAuthorityKernel.BoundaryStepWithoutInteriorTransitionIsValid`
10. `SurfaceCellAuthorityKernel.InteriorStepRequiresNamedInteriorTransition`
11. `SurfaceCellAuthorityKernel.CanonicalRouteReversalRoundTripIsExact`
12. `SurfaceCellAuthorityKernel.RepresentationHandlePerturbationDoesNotChangeCanonicalRoute`
13. `SurfaceCellAuthorityKernel.LegacyAdapterRoundTripPreservesSemanticValue`
14. `SurfaceCellAuthorityKernel.DeliberateCrossDomainAdapterMisuseIsRejected`

Require **14/14**. A process pass is authoritative only if the contract exercises its intended positive/counterexample/metamorphic semantics; compilation or no-crash is not semantic proof.

## 5. M1a semantic acceptance criteria

The 14-contract family must establish all of the following:

- high-risk authority domains are statically non-interconvertible;
- valid named legacy conversion is exact;
- negative, out-of-range, and supplied-domain mismatch are typed rejections;
- equal raw numerals in distinct domains do not imply semantic equality/conversion;
- canonical source-edge topology is endpoint-order invariant while directed orientation is explicit;
- source-support alternatives remain tagged/type-distinct;
- quarter turns normalize modulo four and four unit turns close to identity;
- grid automorphism satisfies left/right identity, left/right inverse, and representative associativity exactly;
- nonzero Z4 rotation plus translation round-trips exactly;
- source boundary step without interior transition is valid;
- an interior step without its named transition is typed-rejected;
- route reversal is exact and involutive;
- representation-handle perturbation cannot change canonical semantic route;
- named legacy adapter round trip preserves semantic value;
- deliberate cross-domain adapter misuse fails typed.

Any false positive/negative or domain conflation blocks M1b.

## 6. Accepted T1 preservation authority

The accepted T1 independent-oracle/package boundary must remain green.

### Oracle

Run `directional_surface_cell_oracle_tests --gtest_list_tests` exactly once and require exact match to its immutable **29-name** manifest. Run all 29 oracle contracts individually and require **29/29**.

### Direct production cases

Run the six existing direct acceptance cases in fresh processes:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder;
- BunnyRandom;
- Vase.

Required interpretation:

- Plane, MultiFaceSeam, CloseSheets, Cylinder must remain green and independent-oracle clean;
- BunnyRandom remains explicitly known-red unless production behavior truly changes, but because M1a existing producer binary is byte-identical to T1, its expected comparison is the accepted T1 failure path; it must still reach independent-oracle evidence before the unchanged fatal product-success assertion if it returns;
- Vase remains explicit known-red/deferred; use a bounded 60-second process guard and treat timeout only as runtime-safety evidence, not correctness or nontermination proof;
- do not disable, expected-failure-convert, or count Bunny/Vase green.

Because all pre-existing executables are byte-identical to T1, any changed result is first treated as an execution/environment discrepancy and investigated without source edits.

## 7. Regression-pattern review

| Pattern | M1a state to validate | Acceptance evidence |
|---|---|---|
| `RP-01` | strong domain separation and checked conversions | static + negative runtime contracts |
| `RP-02` | accepted independent oracle/package boundary preserved | exact 29 discovery + 29/29 + direct oracle integration |
| `RP-05` | semantic identity excludes representation handles | representation perturbation + reversal/canonicalization contracts |
| `RP-07` | cyclic/Z4 semantics explicit and exact | quarter-turn, automorphism, route reversal contracts |
| `RP-03`, `RP-04`, `RP-06`, `RP-08`, `RP-09` | untouched | byte-identical pre-existing production executables and unchanged direct behavior |

M1a failure does not create a historical production regression unless previously accepted product authority is actually lost. New architecture that has not yet been accepted is classified as pending/failed migration work, not automatically a recurrence.

## 8. Postflight

After runtime:

- re-hash both original artifact ZIPs;
- verify all 53 packaged manifest entries again;
- verify no packaged regular file was altered or added;
- record any runtime-only symlink separately;
- retain exact stdout/stderr/exit status/timing for every executed process;
- record discovery output hashes and the exact selected test names.

## 9. Acceptance and next turn

M1a is accepted only if:

1. package/source/dependency authority is exact;
2. authority-kernel discovery is exact 14 names;
3. authority-kernel contracts pass **14/14** with intended semantic coverage;
4. T1 oracle discovery is exact and contracts remain **29/29**;
5. Plane, MultiFaceSeam, CloseSheets, Cylinder remain green and oracle-clean;
6. known-red Bunny/Vase remain explicit and are not synthetically promoted;
7. no pre-existing production result changes relative to accepted T1 comparison authority;
8. no package mutation, test weakening, source substitution, or expected-failure conversion occurs.

If accepted, the next turn may be **M1b — first production consumer migration, Code + Build only**, but only after a bounded M1b plan identifies one exact consumer boundary and its compatibility rollback point. Do not migrate multiple consumers in one slice.

If any condition fails, stop at M1a and write a corrective Code + Build plan. Do not repair source during this Test + Benchmark turn.

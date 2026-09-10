# M4-CP3-CB1 Code + Build Plan

**Turn:** `M4-CP3-CB1`
**Status:** **AUTHORIZED AFTER M4-CP2 CLOSURE / RUNTIME-FREE CODE + BUILD**
**Boundary:** production A3->A4 conformity-plan cutover only; compile/package, no Directional runtime
**Accepted predecessor:** package117 / selector382 **382/382**

## 1. Goal

Production-wire the accepted A3 `GlobalConformityOutcome` before A4 regional production and make the verified `GlobalConformityPlan` the sole authority for shared-boundary counts/breakpoints. Retire local target/grid selection and floating/tolerance post-hoc support pairing **as shared-boundary semantic authority** without broad remesher refactoring.

Success in this CB means the smallest source/test/build delta implementing the CP3 cutover compiles through the mandatory reusable GMP/GMPXX workflow and is packaged as the next immutable candidate. It does not mean CP3 runtime acceptance; the successor Test + Benchmark turn owns that.

## 2. Assumptions and hard pre-mutation falsifier

The frozen definition requires every boundary incidence to carry `ConformityFamily`, `ConformitySign`, orientation, and an exact support-piece path derived from accepted A0-A2b field/topology authority. Current `GlobalTopologyPlan` directly carries arc kind, orientation, source carriers and region boundary occurrences but does **not** directly publish family/sign.

Before changing product, test, selector, or CMake semantics, prove from current accepted source that **every production A2b boundary occurrence used by CP3 has one unique source-derived mapping** to:

1. `ConformitySpanId` / exact ordered `ConformitySupportPiece` path;
2. `ConformityFamily::{U,V}`;
3. `ConformitySign::{Positive,Negative}`;
4. incidence orientation relative to canonical span direction.

The derivation may use the bound `FieldAlignedCurveNetwork`, `SurfaceCutGraph`, `FieldTransportAtlas`, explicit source support and topology orientation. It may **not** compare raw `FieldBranch` integers across faces as a global gauge, infer family/sign from approximate geometry, use tolerances/quantization, or infer support from `GlobalTopologyArc::sourceFaces` when exact path authority exists elsewhere.

**Falsifier / stop rule:** if any production arc kind or boundary occurrence cannot be assigned these facts uniquely from existing accepted authority, stop CB1 before semantic mutation and route to a bounded definition review. Do not invent a convention, add tolerance, use local chart output as oracle, or silently exclude the arc.

## 3. Production A3 input and outcome seam

After §2 passes:

1. Add the smallest production input builder that consumes the exact accepted A0-A2b products plus source vertices/target metric and produces `GlobalConformityInput` with one canonical full-A2b span and multiplicity-preserving incidence per frozen definition.
2. Reuse existing `build_global_conformity_outcome(...)` and `validate_global_conformity_outcome(...)`; do not create a second scheduler/solver/certificate implementation.
3. In the SurfaceCells production path, build/validate A3 outcome **after** `GlobalTopologyPlan` and **before** regional A4 production.
4. If the outcome contains any typed `ConformityInfeasibleSubset`, do not synthesize an A4 schedule. Propagate/retain the typed A3 state at the narrowest existing pipeline boundary that can represent failure today; D0-D4 disposition assignment remains M7-owned and is not introduced here.
5. For an all-feasible outcome, pass an immutable `const GlobalConformityPlan&` (or equivalently immutable handle) into A4. A4 may resolve and validate IDs but may not rewrite the plan.

Do not duplicate CP2 validation logic in the pipeline. The production path must consume the same semantic outcome surface that package117 already certifies.

## 4. A4 shared-boundary cutover

Change only the shared-boundary seam necessary for CP3:

- Resolve each shared A2b span from the plan and consume its exact positive `count`.
- Represent each consumed breakpoint by `ConformityBreakpointId {span, exactOrdinal}` and resolve source location with the plan's exact support-piece generator; do not enumerate an unbounded exact count merely to establish identity.
- For a reversed boundary incidence, map exact ordinal `j` to `x_s - j` so both chart copies name the same physical breakpoint under opposite orientation.
- A4 `targetSize` may continue to influence **interior-only** layout decisions after the boundary schedule is fixed, but it may not choose a different shared count, insert/delete/coalesce/reorder shared breakpoints, or change shared breakpoint identity.
- Replace post-production semantic pairing by quantized floating `support_key` with exact span/incidence/ordinal identity. `support_key` may remain only as non-authoritative diagnostic code if removing it entirely would be unrelated to the cutover.
- Do not create a compatibility fallback that silently re-enters the old local-count or floating-pairing path when A3 data is present or invalid.

The expected product effect is that the exact-torus path no longer fails `InvalidHardRailPairing` because two sides are paired by common A3 authority rather than reconstructed from produced floating positions.

## 5. Tests and selector extension

Test-source changes are authorized because CP3 needs new compiled gate identities. Preserve selector382 byte-for-byte as the prefix. After the §2 derivation guard succeeds, append exactly these six identities in order to a new **selector388**:

383. `GlobalConformityProductionInput.DerivesCanonicalIncidencesFromAcceptedA2bAuthority`
384. `SurfaceCellConformity.SharedBoundariesConsumeExactScheduledOrdinals`
385. `SurfaceCellConformity.FixedPlanTargetPerturbationPreservesSharedBreakpoints`
386. `SurfaceCellConformity.InsertDeleteReorderSharedBreakpointTamperIsRejected`
387. `SurfaceCellConformity.HardRailPairingUsesSpanOrdinalIdentityWithoutSupportQuantization`
388. `SurfaceCellsPhase10.ExactCommittedTorusClearsInvalidHardRailPairingThroughA3`

Required semantics:

- 383 independently constructs the expected family/sign/orientation/support mapping from accepted source authority and compares it to production input; producer/oracle may not call the same helper.
- 384 proves both incidences consume the same exact span count and exact ordinals, including reversed `j -> x_s-j` correspondence.
- 385 holds one immutable plan fixed, perturbs A4-local target values, and proves shared breakpoint IDs/locations/order are unchanged while permitting interior-only layout differences.
- 386 tampers shared-boundary insertion/deletion/reordering or plan binding and requires typed rejection rather than normalization/fallback.
- 387 proves opposite hard-rail copies are paired by exact plan identity and remains green under a perturbation that would distinguish floating support quantization from exact identity.
- 388 uses the existing exact committed torus production witness, proves it reaches A3/A4 under the new seam, and specifically proves `InvalidHardRailPairing` no longer terminates that path. Do not convert unrelated downstream failures into this identity's success.

Before publication record selector388 line count, LF SHA-256 and exact selector382 prefix SHA-256 in `Required_Green_Selector_Manifest.md` during CB closeout. No accepted identity may be changed, removed, reordered, or silently re-owned merely to make the new gate compile.

## 6. Scope exclusions

This CB must not:

- change CP1/CP2 solver, objective, theorem, certificate, infeasibility or semantic-digest contracts except an additive API adaptation strictly required to consume accepted immutable authority;
- discharge any of the three `G4-B002` produced-witness debts — they remain CP4 runtime obligations;
- implement CP-COND or CP-SCALE;
- implement M5 quotient relations, M6 embedding/verifier stages, or M7 dispositions;
- repair prescribed-sphere 368/398, ordinary proposal 369, folded-cone 374, or accepted-ordinal307 debt;
- introduce geometry/tolerance matching as A3/A4 identity;
- run a Directional test, benchmark, discovery command, CLI/help/version command, fuzzer, or custom runtime during Code + Build.

## 7. Surgical implementation targets

Expected touched implementation surfaces are limited to the existing A3/A4 seam, principally:

- `include/directional/geometry/GlobalConformityPlan.h` only if a narrow production-input/consumer API is required;
- `src/geometry/GlobalConformityProblem.cpp` / related existing A3 input implementation;
- `src/pipeline/RemeshPipeline.cpp` production ordering/binding;
- `include/directional/geometry/SurfaceCellTracing.h` and `src/geometry/SurfaceCellTracing.cpp` only for immutable plan consumption and exact shared-boundary pairing;
- focused existing test files and `cmake/DirectionalTests.cmake` only as required to own identities 383-388;
- append-only `Architecture_M4_CP3_Required_Green_Selector_388.txt` and manifest documentation.

If implementation pressure spreads into unrelated topology/cut-graph internals, stop and re-evaluate whether the §2 authority mapping was actually proved. A senior-engineering review should be able to explain every changed line as necessary for A3->A4 shared-boundary authority.

## 8. Build and package requirements

1. Perform no local build.
2. Push the verified source/test/selector delta on the working branch.
3. Compile only through `.github/workflows/agent-compile-reusable.yml`; mandatory exact backend is GMP with both GMP and GMPXX link evidence.
4. Compile `directional_core` and every test owner required by selector388. Derive the selector-to-owner partition from source before packaging; do not assume only the producer target changed.
5. Package the full selector388 owner set, fixtures/source archive, clean source-status receipts, command boundary with `runtimeExecution=false`, and recursive self-excluding `SHA256SUMS` under the reusable workflow contract.
6. If compilation fails, preserve the first actionable error and repair only the diagnosed compile/source defect within this CB. Do not execute runtime to diagnose a compile failure.
7. On compile green, assign the next package number only from current repository authority (expected package118 if no intervening build has consumed it) and record exact source/run/job/artifact/hash evidence. Do not hard-code package118 into source semantics.

## 9. Verification goals for CB closeout

CB1 closes only if:

- §2 source-authority derivation guard passed and is documented;
- exact A3 outcome is production-wired before A4;
- shared A4 breakpoint identity/count comes only from immutable plan authority;
- local target/grid and floating `support_key` have no remaining semantic authority over shared boundaries;
- identities 383-388 compile and selector388 exactly extends selector382;
- all selector owners compile/package with GMP/GMPXX and clean source status;
- `runtimeExecution=false` is proven;
- no Directional runtime occurred;
- an executable artifact-only Test + Benchmark plan is authored for the exact candidate package.

Compile green is not CP3 acceptance.

## 10. Mandatory successor Test + Benchmark plan content

At CB closeout author exactly one artifact-only successor plan that, against the immutable CB1 package and without rebuild/repair, must at minimum:

1. verify package/source/selector/owner integrity and executable modes before runtime;
2. execute CP3 identities 383-388 in focused fresh processes, with any plan-defined repeat needed for determinism;
3. execute the full selector388 one identity per fresh process in frozen order;
4. prove fixed-plan target perturbation leaves shared breakpoint IDs/order/locations unchanged;
5. prove exact-torus reaches A3/A4 and no longer exits as `InvalidHardRailPairing`;
6. preserve any later downstream torus failure separately rather than crediting it as CP3 success unless the frozen CP3 exit requires that later stage;
7. compare package/source/execution-view censuses before/after and record all prohibited-execution flags;
8. classify any RED/orchestration failure in the regression tracker before TB closeout;
9. route to runtime-free review for promotion/CP3 closure.

No benchmark is required by CP3 unless the succeeding plan identifies a frozen performance criterion; current CP3 criteria are semantic.

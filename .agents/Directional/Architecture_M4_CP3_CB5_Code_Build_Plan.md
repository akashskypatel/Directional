# M4-CP3-CB5 Code + Build Plan — production A3→A4 exact shared-boundary cutover

**Status:** FROZEN / AUTHORIZED AFTER `M4-CP3-TB2-R2-REV`
**Turn:** `M4-CP3-CB5`
**Date:** 2026-09-12 UTC
**Canonical turn:** Code + Build
**Runtime in this turn:** FORBIDDEN
**Accepted entering runtime authority:** corrected R4 artifact `10289601000` / selector403 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7` / **403/403**

## 1. Objective

Perform the deferred production A3→A4 cutover required by frozen definitions §17.8-§17.12: A4 must consume the accepted immutable `GlobalConformityBaselinePlan` shared subdivision, materialize the same exact shared breakpoints on both sides, and stop using locally reconstructed/quantized geometry as shared-boundary pairing authority.

This is one bounded authority cutover. It does **not** redesign A3, change its optimizer/counts/breakpoint schedule, change A2b exact-path publication, change A4's local field-family/advance-sign semantics, or close CP3 by compilation alone.

## 2. Entering facts frozen by review

- accepted A3 semantic/build source: `58521f6d1c4fb5d625da7cde50e002cf4688beee`;
- accepted package artifact: `10289601000`;
- accepted selector403 SHA: `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
- selector403 first394 exactly equals accepted predecessor `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- A2b publishes one canonical ordered exact source path per accepted arc; production A3 binds exactly one `ConformitySpanInput` per arc and publishes an independently validated `GlobalConformityBaselinePlan`;
- `GlobalConformityBaselinePlan::schedule()` owns exact span counts/support pieces and `breakpoint_location(span, ordinal)` owns compact exact breakpoint locations;
- current production builds the accepted baseline in `RemeshPipeline.cpp` immediately before `build_surface_cell_network(...)`, but A4 receives no baseline pointer today;
- current hard-rail pairing in `SurfaceCellTracing.cpp` groups endpoints through `support_key`, which uses `1e-9` classification tolerance and `1e12` rounded barycentric quantization; frozen §17 assigns that shared-boundary agreement to accepted A3 authority instead;
- `SurfaceFrontEdge::family` / `advanceSign` are A4-local and remain so.

## 3. Mandatory pre-mutation derivation guard

Before changing product/test/build source, CB5 must statically derive one exact handoff from the accepted products to the current A4 hard-rail boundary representation.

For every shared hard-rail boundary segment the proposed cutover will pair, prove all of the following using only accepted A2b/A3 identities:

1. exactly one owning A2b arc / `ConformitySpanId` is determined;
2. its two endpoints are exactly two consecutive accepted A3 breakpoint ordinals (including schedule endpoints when appropriate);
3. orientation from the A2b arc/span into each A4 chart copy is known exactly;
4. both chart copies therefore receive the same typed shared-boundary interval identity independent of floating point coordinates;
5. no local target size, grid count, tolerance, quantized barycentric key, synthetic-node allocation order or post-hoc partner search is needed to decide shared-breakpoint identity.

### Guard stop

If even one required mapping is ambiguous, missing, only geometrically inferable, or requires a new upstream semantic convention, **STOP before semantic mutation**. Record the precise missing authority and return to Review. Do not invent a fallback or extend scope silently.

## 4. Authorized implementation if and only if the guard passes

The smallest sufficient cutover is authorized:

1. thread the accepted `GlobalTopologyPlan`/`GlobalConformityBaselinePlan` authority from `RemeshPipeline` into the production A4 phase-front path through a typed immutable interface;
2. materialize each A3-owned shared-boundary breakpoint exactly from the accepted span schedule/support path; floating coordinates may be derived only as a rendering/geometric representation of that already-identified exact point, never as the identity used to pair the boundary;
3. publish typed shared-boundary provenance on the A4 boundary edge/segment sufficient to identify span, exact endpoint ordinals and orientation;
4. pair opposite hard-rail chart copies by that exact typed identity plus the already-frozen route/topology conditions, removing `support_key` from shared-boundary semantic pairing authority;
5. leave A4-local `family` and `advanceSign` checks intact and locally derived;
6. reject missing/contradictory accepted A3 schedule identity explicitly; do not repair, re-solve or renegotiate counts/breakpoints inside A4;
7. preserve all non-shared-boundary behavior outside the cutover.

Removing the helper named `support_key` is not itself the objective. The semantic requirement is that no tolerance/rounded geometry controls shared-boundary pairing or breakpoint identity after the cutover.

## 5. Required Code + Build tests

CB5 must add focused deterministic source coverage whose names are chosen during implementation but whose contracts are frozen here:

- **production handoff:** the pipeline passes its independently validated A3 plan into A4 and the A4 product records/consumes the exact plan identity rather than reconstructing a local schedule;
- **fixed-plan target perturbation:** with one accepted A3 plan held fixed, at least two A4-local target/grid settings produce byte/equality-identical typed shared-boundary breakpoint identities; local interior construction may differ, shared A3 breakpoints may not;
- **exact pairing discriminator:** a witness in which floating/rounded endpoint coincidence is not sufficient must pair through exact span+ordinal identity, and a tampered/missing interval identity must reject rather than fall back to `support_key`;
- **A4-local frame preservation:** family/advanceSign remain locally derived and are not copied from A3;
- **exact-torus production path:** compile a focused witness that will later prove the accepted plan removes the `InvalidHardRailPairing` stop through exact shared-boundary identity. Runtime execution is deferred to TB.

Do not add tests merely to discharge `M4-CP3-TB1-R1-REV-OBS-01` or `M4-CP3-CB4-REV-OBS-02` unless the cutover itself naturally creates an independently falsifiable witness. Those obligations remain separately owned to avoid a two-variable control experiment.

## 6. Selector and ownership rules

- Accepted selector403 bytes/hash are immutable and must remain an exact prefix of any CB5 successor selector.
- New required-green identities may be appended only after static unique-definition/owner mapping succeeds.
- Recompute the owner partition from CMake source membership and `TEST*` definitions; do not infer ownership by filename convention.
- Any accepted identity loss, reorder, rename or deletion is an immediate STOP.
- No historical selector file is edited.

## 7. Compile/package verification

No local compile and no Directional runtime are allowed.

After semantic/test changes are committed and pushed, compile only through `.github/workflows/agent-compile-reusable.yml` with GMP/GMPXX (`DIRECTIONAL_ENABLE_GMP=ON`) and `runtimeExecution=false`.

Order:

1. changed-owner preflight target(s) for every touched packaged-test owner;
2. full package compile of the frozen eight targets:
   - `directional_core`
   - `directional_pipeline`
   - `directional_surface_cell_authority_kernel_tests`
   - `directional_surface_cell_producer_tests`
   - `directional_surface_cell_completion_tests`
   - `directional_surface_cell_validation_tests`
   - `directional_compiled_api_tests`
   - `directional_benchmarks`
3. require clean source status, GMP/GMPXX link evidence, package manifest self-check, owner executables present/executable, and `runtimeExecution=false`.

No GTest discovery/listing, `ctest`, test, benchmark, produced executable, CLI/help/version or custom-input Directional runtime may execute in CB5.

## 8. Frozen stop conditions

CB5 stops and returns to Review before further semantic mutation if any of the following occurs:

- §3 cannot derive unique exact span+ordinal interval identity for all intended shared hard-rail segments;
- accepted A3 plan bytes/counts/breakpoints would need modification or local renegotiation;
- A2b exact-path semantics or accepted selector403 rows would need modification;
- pairing still requires tolerance/rounded geometric identity after the proposed cutover;
- implementation would source A4 `family`/`advanceSign` from A3;
- a second unrelated production defect is needed to make the exact-torus witness compile/reach the intended path;
- any mandatory compile reveals a semantic/build dependency outside this frozen cutover.

One new dependency means stop, preserve the patch/evidence, and return to Review rather than widening the turn.

## 9. Future Test + Benchmark acceptance after green packaging

A later artifact-only TB plan must be frozen from the compiled package. At minimum it must require:

1. accepted selector403 **403/403** as predecessor compatibility;
2. every appended CB5 required-green identity in fresh exact-filter processes;
3. focused fixed-plan target/grid perturbation proving identical consumed shared-breakpoint identity;
4. focused exact-torus production proof that the prior `InvalidHardRailPairing` stop is removed through accepted A3 schedule identity, not through weakened family/sign checks or tolerance;
5. exact negative/tamper coverage proving missing/contradictory schedule identity rejects without local repair;
6. immutable package/source/execution-view postflight and zero compile/relink/discovery/package repair.

TB-EXEC cannot self-promote. A later Review must decide CP3 closure against the full frozen exit criteria.

## 10. Exit from CB5

CB5 closes only with either:

- **GUARD STOP:** precise missing-authority record, zero semantic mutation/compile/runtime; or
- **BUILD GREEN:** guard proof + bounded exact A3→A4 cutover + focused tests + accepted-prefix-preserving successor selector + GMP package evidence, still runtime-unproved.

No other outcome authorizes runtime or CP3 closure.

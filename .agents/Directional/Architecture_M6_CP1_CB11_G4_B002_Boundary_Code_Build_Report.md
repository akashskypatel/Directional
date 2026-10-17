# M6-CP1-CB11-G4 — A6 closed-complex boundary Code + Build report

## Disposition

**COMPLETE / COMPILE+PACKAGE GREEN / RUNTIME-FREE.**

Exact semantic source: `582da20a925ba920c923bf5aacb9e0e56ef0723d`.

This turn implements the R4 D3 A6 closed-complex boundary and the RA-20 / RA-21 / RA-21b contract:
- immutable A6-owned `SurfaceQuotientClosedComplexView`;
- canonical side-incidence edge identity and quotient class lineage;
- independent `relationKind` and typed-source `hardFeatureProtected`;
- strip identity from opposite-edge transitive closure;
- A6-boundary candidate extraction without arrangement authority;
- focused identities 25–28, including the degree-2-chain contraction equivalence oracle on the produced torus.

No Directional runtime was executed in Code + Build.

## Compile correction history

The first compile attempt, run `37212895863` / job `111467510280`, failed only in compile contracts:
- the RA-21b positional precondition attempted equality on `SurfaceTracePoint` / `SurfaceTraceSegment`, which intentionally do not define `operator==`;
- a legacy compile-time API assertion saw the temporary hard-feature parameter on the public phase-front materializer.

The bounded correction at semantic commit `582da20a925ba920c923bf5aacb9e0e56ef0723d`:
- replaced those test comparisons with explicit field-wise exact comparisons;
- kept the public three-argument `build_authoritative_phase_front_mesh` API unchanged and moved hard-feature injection to a private production helper.

No validator was weakened and no runtime was used to diagnose or verify the correction.

## Final compile/package authority

Final compile run/job: `37216400150 / 111477707423` — **SUCCESS**.

Artifacts:
- result `11308472138`, outer SHA-256 `a4d178678bcbc9c29fc4003ffc9205ef220873bfb0e5247b21a453fffdc8d04d`;
- log `11308317584`, outer SHA-256 `c93259fde3e19ecd928440691682233b54a5208728826ee5d694635a04cd2b76`.

Package verification:
- recursive self-excluding manifest: **28/28 OK**;
- preflight exit: `0`;
- build exit: `0`;
- exact packaged source: `582da20a925ba920c923bf5aacb9e0e56ef0723d`;
- final source status: clean;
- `runtimeExecution=false`;
- exact arithmetic backend: GMP;
- all standard eight targets compiled/linked:
  - `directional_core`
  - `directional_pipeline`
  - `directional_surface_cell_authority_kernel_tests`
  - `directional_surface_cell_producer_tests`
  - `directional_surface_cell_completion_tests`
  - `directional_surface_cell_validation_tests`
  - `directional_compiled_api_tests`
  - `directional_benchmarks`.

Selector authority:
- focused-24 SHA-256: `6bcc8a544cbc0296df4cdb66dcb0c2dc7f86c88dfb340b795462c8c9544067bf`;
- focused-28 SHA-256: `9154a986ce005c53f99faad3551989b05516abe9e4fd02dce585a645d70a011d`;
- focused-28 is an exact 24-line prefix extension by identities 25–28;
- selector449 remains SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414`.

The next immutable TB gate is **focused 28 + selector449 = 477 fresh exact-filter processes**, followed by mandatory Review. Code + Build makes no runtime, promotion, debt-closure, `G4-B002` closure, or CP1-closure claim.

## Durable closeout

The final six-file durable closeout patch was generated from verified snapshot base `747fec14224fd71032afe4d7f993253181ed9613`, with full patch SHA-256 `7bea8c9f53d69f3ab52f176b382714483ec6202de373b73f57b9c8cd0f235db3` and diff-body SHA-256 `e03efbf72163b3dedb794a358193f1a8aba38702de978df060e43120c2fcdcc8`.

Drive-apply run/job `37219662356 / 111487290074` succeeded and produced commit `09593888235d04433d89332ae2432f923acca55b`; result artifact `11309461860` has outer SHA-256 `5c83a28c10de3b8c0bd4720ce0e54201b72ad9954fad7907ae33b8ae58eec9fc`. The workflow recorded `runtimeExecution=false` and required owner-side Drive retirement; the user-authorized Drive connector then permanently deleted the staged patch successfully.

Temporary closeout and compile callers were retired first, followed by their markers and all three CB11 source-snapshot markers. Cleanup through commit `b16e682683ed18ec3281c2e9de0fc6bae0b03d61` leaves no CB11 temporary caller or trigger state.

Exact successor: `M6-CP1-TB11-G4-EXEC`, consuming the immutable compile candidate and executing **477** fresh exact-filter processes before mandatory Review.

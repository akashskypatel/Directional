# CB168L — slide-interior cut position Code + Build record (2026-11-20 UTC)

Turn: `M6-CP3-CB168L-P13-SLIDE-INTERIOR-CUT-POSITION`. **Complete: compile-only, no product runtime execution.**

## Source and change authority

- Authorized exact frozen diff: `.agents/Directional/Architecture_M6_CP3_CB168L_P13_Slide_Interior_Cut_Position_Exact.diff`, SHA-256 `26401a6beb41aca02b0096c7079016a493b99444c0d92decd5d3b499f5ca8f3a`.
- Parent/source snapshot: `22f7f9433b6661418c953ca54253926134f13cff`, source snapshot workflow [44689074423](https://github.com/akashskypatel/Directional/actions/runs/44689074423), artifact `14607303985`.
- Precheck against CB168K `0955d28e37a4f17f2488f0f4dd196a2d24aa3c11`: no changes to `src`, `include`, `tests`. Exact patch passed `git apply --check` and `git diff --check`.
- Transport header preserved the frozen diff body exactly; complete transport patch SHA-256 `9b2ff8401549c73717757ca527547ac840033dd1089564567dbc87ebacbfd9b0`. Initial raw-diff transport failed metadata validation; corrected run [44689775859](https://github.com/akashskypatel/Directional/actions/runs/44689775859) succeeded, result artifact `14607822971`. Both temporary Drive staging files were retired by the owner control plane.
- Applied semantic source commit: `041bde764365710e6d5148c43751da91205ffd35`. Exact changed files: `src/geometry/EmbeddedGraphTopology.cpp` +61/−2; `src/geometry/EmbeddedGraphTopology.h` +18/−2; `tests/FieldAlignedCurveNetworkTests.cpp` +118/−2. No other source/test/fixture/selector changes.

## Compile evidence

- Standard eight-target GMP/GMPXX compile-only workflow [run 44689989713](https://github.com/akashskypatel/Directional/actions/runs/44689989713) **SUCCESS**.
- Immutable package artifact `14608341511`, ZIP SHA-256 `d189282ce898af54c3cb48d2eaa47107ebaaf36ca2d0afcaec9689dec926084b`; packaged manifest **28/28** hashes verified.
- Target list: `directional_core`; `directional_pipeline`; `directional_surface_cell_authority_kernel_tests`; `directional_surface_cell_producer_tests`; `directional_surface_cell_completion_tests`; `directional_surface_cell_validation_tests`; `directional_compiled_api_tests`; `directional_benchmarks`.
- `build-exit-code=0`; GMP link evidence names `libgmpxx.so` and `libgmp.so`; `exactArithmeticBackend=GMP`; `runtimeExecution=false`; final source status clean.
- **No Directional tests, benchmarks, or compiled binaries were executed in this turn.** Added assertions are compile-valid only, not runtime verified.

## Semantics and limitations

- Added inert `carrier_contact_slide_position` for strict exact interior slide-contact loci, with empty and out-of-range rejection.
- `exact_trace_piece_path_between` clips the traversed slide edge piece. Normal straight clipping is unchanged. Updated row 960 expected paths and added row 964 positive/negative assertions.
- No production caller change; `build_arcs` still uses `exact_trace_path_between` and therefore writes the previous face chords. EPO-3, H4/CB169, row686 oracle, stop switch and all topology acceptance are deferred.
- TB149 remains authoritative runtime PASS: gate 963/963, CP2 491/491, census 3/3 under N1–N4. Stable 66 events / 17 categories / 49 recurrences; one produced-witness debt, 81 deferred. Sphere row686 χ6 versus source2 remains unresolved; no CP3 or D0 promotion.

**Authorized successor (not executed here):** `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-EXEC`, frozen manifest `bce554e6723dfaa77f54d070aab7edc6508cd3aaf69a6120871e21b349b78926`.

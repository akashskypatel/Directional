# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Current runtime authority — artifact 9016834575

The current runtime-proven curved-disk authority remains:

- curved-disk semantics **6/6**;
- sheet coverage **3/3**;
- G4 relation semantics **5/5**;
- retained G0-G3 **17/17**;
- exact direct hashes unchanged for plane/seam/close-sheets/cylinder;
- no passing direct fallback/recovery;
- exact torus `Rejected / InvalidBoundedDiskTopology` at `tracing/phase-front` on the first non-hard internal edge that is nevertheless an authoritative cross-sheet boundary.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Report.md`.

## Source-sheet-boundary Code + Build complete

Exact artifact **`9019024467`** (`g4-source-sheet-boundary-code-build`) is compile-valid and awaiting artifact-only validation.

- implementation `b425898fa7367406fa0c07e8f4441a37efc01315`;
- cleanup `3fcfd2cf2996919eed5c951a9148d83deb5aa6f8`;
- workflow run/job `31247546780 / 93078496378`;
- ZIP SHA-256 `a26f8acc7301d50cb232e192aa7ffecfda5e84c403d4224a8f1f99f315bd990f`;
- internal manifest SHA-256 `7bffb8dbf76c1532af0a2c1701db4dcb25df581e233cf18312e62d2c1bca7975`;
- recursive checksums **48/48**;
- 49 files / 27 fixtures / five executables / two project static libraries;
- seven approved targets **111/111**;
- `runtimeExecution=false`.

The correction preserves the authoritative distinction:

1. genuine source boundary → valid;
2. hard-feature internal boundary → valid;
3. non-hard internal edge whose opposite face has a different authoritative component/sheet → valid source-sheet boundary;
4. non-hard same-component/same-sheet internal edge → invalid hidden cut.

No classifier/hard-feature mutation, validator change, fallback/recovery, periodic-authority change or generic completion repair was introduced.

Compile-only regressions add a real non-hard cross-sheet witness, its same-sheet negative control, row-order invariance and strengthened torus advancement. They have not executed yet.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Code_Build_Report.md`.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Source_Sheet_Boundary_Authority_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against artifact `9019024467`.

Required order:

1. exact artifact/source/blob/checksum authority;
2. three new source-sheet-boundary semantic cases;
3. retain prior curved-disk 6/6, sheet coverage 3/3, G4 relations 5/5 and G0-G3 17/17;
4. retain exact deterministic direct plane/seam/close-sheets/cylinder baselines;
5. classify exact torus in at least three independent processes.

The prior non-hard-boundary `InvalidBoundedDiskTopology` terminal result is no longer sufficient. Preferred result is complete authoritative torus materialization/direct strict-valid pure-quad output. A deeper deterministic bounded-disk or materialization invariant is acceptable material progress only when source-sheet boundary authority is runtime-proven live and no generic/fallback path substitutes for producer authority.

Entering bounded-suite baseline remains producer **112/113**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **334/345**. Prescribed sphere remains deferred unless torus reaches direct strict-valid production.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.

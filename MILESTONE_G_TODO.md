# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Runtime authority — artifact 9015931928

Current runtime-proven authority remains artifact **`9015931928`** until the curved-disk candidate executes artifact-only.

- sheet coverage **3/3**;
- G4 relation semantics **5/5**;
- retained G0-G3 **17/17**;
- direct plane/seam/close-sheets/cylinder exact deterministic baselines unchanged;
- no fallback/recovery.

Exact torus currently rejects directly at `tracing/phase-front` as `UnsupportedSourceSheetTopology` after retaining three periodic-annulus relations. The old partial `NotApplicable -> generic zero-cell arrangement/completion` path is gone.

Read-only source/topology authority identifies the missing class as non-planar χ=1 source-sheet disks with one genuine source/hard-feature boundary. Observed face IDs, sheet counts, relation counts, and loop lengths are diagnostics only.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`.

## Curved bounded disk Code + Build complete

Artifact **`9016834575`** (`g4-curved-disk-code-build`):

- implementation `90046be649a0fd051e6c44eceec07198dc542c29`;
- cleanup `508211936b790dfb40cdbece7900bb0522368b76`;
- workflow run/job `31240168780 / 93059691196`;
- ZIP SHA-256 `6bf7f897926ffeb4634edba67390f60070f8d1413f97bc41fac4435f6ae28e67`;
- internal manifest SHA-256 `e0ec3737e23fbb5c21b6c0be6acb3aa8b3f538b954c566867b6c309a6f5f4736`;
- recursive checksums **48/48**;
- 49 total package files / 27 fixtures / five executables / two project libraries;
- approved targets **111/111**;
- log artifact `9016834752`, SHA-256 `6e0ed0906bc9f935ac80b6d8fd40f0654f203020a7b7c6cde6d9a4e49b067db1`;
- `runtimeExecution=false`.

The implementation adds a generalized intrinsic curved bounded disk-sheet phase-front producer:

1. structural applicability from connected χ=1 / one authoritative boundary rather than fixture IDs;
2. reciprocal 4-RoSy gauge transport validated over the simply connected sheet;
3. boundary U+/V+/U-/V- phase classification from transported field alignment;
4. intrinsic boundary arc-length coordinates plus harmonic/Tutte interior parameterization;
5. source-triangle-owned lattice/front/cell provenance and exact hard/source boundary termination;
6. structural composition after existing planar bounded and periodic-annulus producers;
7. typed fail-closed reasons for disk topology, transport, boundary phase, chart and front pairing.

No hard-feature demotion, annulus coercion, Euclidean seam welding, fallback/recovery, generic completion repair, or validator change was introduced.

Compile-only regressions were added for curved-disk applicability, row-order invariance, hard-boundary preservation, invalid reciprocal transport, mixed planar/periodic/curved composition, and exact torus producer advancement. They have **not executed yet**.

Detailed compile record: `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Report.md`.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact `9016834575`.

Required order:

1. verify exact artifact/source/blob/checksum authority;
2. run new curved-disk focused semantics;
3. retain sheet-coverage 3/3, relation 5/5 and G0-G3 17/17;
4. retain exact deterministic direct plane/seam/close-sheets/cylinder baselines;
5. classify exact torus in at least three independent processes.

The prior `UnsupportedSourceSheetTopology` terminal result is no longer sufficient. Preferred result is complete five-sheet authoritative coverage/materialization and strict-valid direct torus output. A deeper deterministic typed bounded-disk or materialization invariant is acceptable material progress only if curved-disk applicability is live, canonical periodic authority remains intact, and no generic/fallback path substitutes for producer authority.

Entering bounded-suite baseline remains producer **107/108**, completion/simplification **154/164**, validation **60/60**, API **8/8**, aggregate **329/340**. Record actual new totals after runtime rather than predicting them.

Prescribed sphere remains deferred unless torus reaches direct strict-valid production. Review policy remains `never`. Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.
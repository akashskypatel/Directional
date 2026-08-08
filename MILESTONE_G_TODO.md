# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Current runtime authority — artifact 9014730437

The latest runtime-proven G4 authority remains artifact `9014730437` until the new sheet-coverage candidate executes artifact-only:

- G4 periodic-relation semantics **5/5**;
- G0-G3 focused retention **17/17**;
- direct plane/seam/close-sheets/cylinder deterministic 3/3 with hashes `730caeae49ec872c`, `5bdf34d7802e9fb0`, `89b052762f52a5af`, `32135be51d7a0a26`;
- cylinder remains direct strict-valid 288 pure quads / 320 V, zero validation failures, one periodic relation `r=0`, `t=(32,0)`, route 32, cut 4;
- bounded producer **105/106**, completion/simplification **154/164**, validation **60/60**, API **8/8**;
- no fallback/recovery.

Torus under that artifact naturally retains two periodic relations but the aggregate phase-front remains `NotApplicable`; the generic path then reaches 670 traces / 113 embedded arcs / zero arrangement cells and fails completion at `SideSubdivisionRepair:InvalidInputIncidence`.

## G4 sheet-coverage Code + Build completed

Exact candidate artifact **`9015931928`** (`g4-sheet-coverage-code-build`) was produced by workflow run/job `31237248211 / 93051938159`.

Source authority:

- implementation commit `856554ce648e5df09ac50f5c94e3e8f098181524`;
- final compile-source commit `a647215b4993338b054f04d4c8e54e7ef5370001`;
- payload cleanup `e46a6d99a45f22f31672c8e5a3367735427d827e`.

Artifact authority:

- ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- internal checksum-manifest SHA-256 `c801b0bb157ba2e1b4537c636306d300ab289db2b89e915718efc73394c03635`;
- recursive checksums **47/47**;
- 48 package files / 27 fixtures / five executables / two static libraries;
- seven approved Release/static/Ninja targets compile/link **111/111**;
- detailed log artifact `9015932044`;
- metadata records `runtimeExecution=false`.

Implementation contract:

1. all canonical authoritative `(component, sheet)` work items are evaluated before whole-surface authority is exposed;
2. existing bounded and periodic local producers still define supported topology classes;
3. if every local sheet succeeds, cells/edges/events are composed only after exact source component/sheet ownership is verified;
4. if no sheet is applicable, overall `NotApplicable` is preserved;
5. if some authoritative content is produced but a later sheet remains unsupported, the whole phase-front rejects as typed `UnsupportedSourceSheetTopology` rather than leaking partial `NotApplicable`;
6. aggregate ownership/incomplete coverage rejects as typed `IncompleteSourceSheetCoverage`;
7. canonical multi-relation periodic authority and hard-feature/source-sheet barriers remain intact.

Compile-only regressions were added for mixed bounded+periodic composition, later unsupported-sheet fail-closed behavior under face-order reversal, and the exact torus producer boundary. They have **not** been executed yet.

## Active G4 runtime decision

The next artifact-only turn must prove:

1. the new sheet-coverage regressions pass;
2. the prior five G4 relation semantics remain **5/5**;
3. all 17 G0-G3 focused contracts remain **17/17**;
4. direct plane/seam/close-sheets/cylinder preserve exact deterministic hashes and strict validation;
5. exact torus no longer follows partial `NotApplicable -> 670 generic traces -> zero arrangement -> SideSubdivisionRepair`;
6. no fallback/recovery, source-grid recovery, hard-feature weakening, positional sheet merge, or Euclidean seam weld is used.

Preferred result: fully `Produced` authoritative phase-front, exact materialization, and direct strict-valid closed torus output.

Acceptable material progress: an earlier deterministic typed `UnsupportedSourceSheetTopology` or exact materialization invariant that retains the canonical relation collection and prevents the opaque downstream generic zero-cell path. If that occurs, identify the exact missing source-sheet topology/producer as the next G4 implementation slice.

The prescribed singular sphere remains deferred until the torus producer coverage/materialization contract is closed.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Plan.md` as **Test + Benchmark only** against exact artifact `9015931928`. No source/test/fixture/validator/benchmark/build edit, configure, compile, or relink is permitted.

Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.

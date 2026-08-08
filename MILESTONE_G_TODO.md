# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → G3 cylinder / periodic holonomy [passed] → **G4 topology-distinct completion and singularities [active]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Runtime authority — artifact 9015931928

The sheet-coverage candidate is now runtime-proven artifact-only:

- artifact `9015931928`, workflow run/job `31237248211 / 93051938159`;
- implementation `856554ce648e5df09ac50f5c94e3e8f098181524`;
- final compile source `a647215b4993338b054f04d4c8e54e7ef5370001`;
- ZIP SHA-256 `108580a2a20bdd7d50169ed076e7b0583466d5ab11c1a2170814eb4fbe8f3cc4`;
- recursive checksums **47/47**;
- sheet-coverage semantics **3/3**;
- G4 relation semantics **5/5**;
- retained G0-G3 focused contracts **17/17**.

Direct three-process authority remains unchanged:

- plane hash `730caeae49ec872c`, 64 quads / 81 V;
- seam hash `5bdf34d7802e9fb0`, 64 quads / 81 V;
- close sheets hash `89b052762f52a5af`, 200 quads / 242 V / two components;
- cylinder hash `32135be51d7a0a26`, 288 pure quads / 320 V, one relation `r=0`, `t=(32,0)`, route 32, cut 4, 1,728 traces, 290 arrangement/simplified cells, zero validation failures, two genuine exterior annulus loops;
- no fallback/recovery.

Detailed runtime record: `.agents/Directional/Gate_4_Closed_Genus_One_Sheet_Coverage_Artifact_Only_Test_Benchmark_Report.md`.

## G4 sheet-coverage decision

The prior torus partial-authority path is closed. Exact torus now fails deterministically and directly at the authoritative producer boundary:

- disposition `Rejected`;
- stage `tracing/phase-front`;
- reason `UnsupportedSourceSheetTopology`;
- first invalid source face 48;
- periodic relation count **3**;
- trace/arrangement/completion counts remain zero after rejection;
- terminal `NotProductionReady:tracing`;
- no fallback/recovery.

This is material progress because a precise producer topology is now first-blocking instead of partial `NotApplicable` followed by zero-cell generic arrangement/completion.

## Active G4 blocker — curved bounded disk producer

Read-only packaged-source/topology analysis reproduces the 48 hard feature edges and four closed feature curves and finds five authoritative source sheets:

- three χ=0 annuli with two boundary loops, already supported by the periodic producer;
- two non-planar χ=1 disks with one genuine boundary loop, currently unsupported.

The first unsupported disk contains face 48 and has one 22-edge boundary loop; the second has one 18-edge boundary loop. These IDs/counts are diagnostic evidence only and may not become implementation branching or ownership rules.

Required next contract:

1. add a generalized intrinsic curved bounded disk-sheet phase-front producer for connected simply connected non-planar source sheets with one authoritative boundary;
2. derive chart/phase authority from source topology and reciprocal field transport, not raw IDs/order/count/proximity;
3. preserve exact hard-feature/source-sheet boundary ownership;
4. preserve existing planar bounded and periodic-annulus producer contracts;
5. compose all supported source sheets under the existing exact-once aggregate coverage contract;
6. fail typed at the next genuine field/chart/materialization invariant rather than generic `NotApplicable` or downstream fallback;
7. preserve sheet-coverage 3/3, G4 relation 5/5, G0-G3 17/17, and all direct hashes.

Do not demote the torus's hard-feature rails, treat the disks as annuli via artificial cuts, Euclidean-weld seams, special-case face 48 or observed sheet counts, or repair generic arrangement/completion first.

## Bounded suites

- producer **107/108**; only `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` fails and remains classified as the existing sub-millisecond performance threshold;
- completion/simplification **154/164**, unchanged historical ten failures;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **329/340**.

## Next turn

Execute `.agents/Directional/Gate_4_Closed_Genus_One_Curved_Disk_Sheet_Code_Build_Plan.md` as **Code + Build only**. No generated Directional project binary may execute in that turn.

Prescribed sphere remains deferred until torus sheet coverage/materialization closes. Review policy remains `never`. Every completed turn ends with a new top-level PR #8 conversation comment after all other repository writes.

# M6-CP3-DEFN-P13-A4-UNEQUAL-SIDE-CONSTRUCTION — combinatorial filling of four-corner discs (2026-11-28 UTC)

## Situation

Defines A4's combinatorial construction for a four-corner disc with positive side counts and even total (DESIGN §4.9: A4 owns general-even-boundary constructibility; embedding is a separate step) and freezes CB-221, a pure function with no production caller. Runtime-free. Scope per [TB-REV-195 adv.](Architecture_M6_CP3_TB_REV_195_Adversarial_Review_20261128.md) GG2/GG4.

## UC1 — Census

`PureQuadCompletion` has no construction for unequal opposite counts: ClosedForm requires equal pairs (`PureQuadCompletion.cpp:44–85`, `:1930–1935`); `TransitionTemplate` is a fixed two-quad template for a six-edge boundary only (`:2071–2088`, dispatch `:2501–2504`); Pattern/BoundedCombinatorial are boundary-only and capped at 128 edges. `validate_pure_quad_completion` exists but needs vertex positions. DESIGN sets no budget or placement rule for interior irregular vertices.

## UC2 — Policy (reviewer default, owner may override)

The user was asked to choose an irregular-vertex policy (minimal templates / graded transitions / equal sides upstream) and instead instructed the turn to be completed. The reviewer chose **minimal irregular vertices**: consistent with D10 (graded size transitions deferred, RA-234), the smallest construction, and A3 count ownership unchanged. The owner may replace it with graded transitions when D10 is reopened.

## UC3 — Boundary rule and an impossibility result

The boundary stays regular: corners valence 2, every other boundary vertex valence 3 (irregular boundary vertices would sit on boundaries shared with neighbouring regions). Under that rule not every even-total input is fillable (proof by the author, accepted): two adjacent unit sides force all sides to be 1 (e.g. (3,1,1,1), (2,2,1,1)), and b = d = 1 forces a = c (e.g. (4,1,2,1)). My original requirement ("every positive even-total input") was wrong; the construction has an explicit domain instead.

## UC4 — Construction family and domain (CB-221)

- Grid: a = c and b = d → a × b grid, no irregular vertex.
- Pentagon–triangle: five grid blocks around one valence-5 vertex glued along a full side to three blocks around one valence-3 vertex, four boundary corners. Applies when some rotation (A, B, C, D) satisfies A ≥ 2, B ≥ 2, C + D ≥ A + B + 4 and A + B ≥ |C − D| + 4 (all block sizes positive; derivation in the code comment). Two irregular vertices (one 3, one 5) are the minimum for unequal opposite sides. Covers both parity classes: (30,35,35,32) via rotation (32,30,35,35), (31,35,35,31) via (31,31,35,35); requires |a − c| + |b − d| ≥ 4.
- Outside: `OutsideConstructionDomain` (other families may fill some of these later); `OddBoundary`, `NonPositiveSide`, `SideBeyondSizeBound` (2^16 per side).
- API: `quadrangulate_four_sided_disc(std::array<std::size_t, 4>)` → `FourSidedDiscQuadrangulation {vertexCount, quads, boundary (from side 0's start corner), sideStarts, irregularVertices}` or `FourSidedDiscQuadrangulationFailure`. New files `include/directional/geometry/FourSidedDiscQuadrangulation.h`, `src/geometry/FourSidedDiscQuadrangulation.cpp` (core library); tests `tests/FourSidedDiscQuadrangulationTests.cpp` in `directional_surface_cell_completion_tests`.
- Tests:
  - `ExhaustiveBoxFillsTheConstructionDomainAndRejectsTheRest` (all sides 1..10: 5000 even-total inputs, 100 grids + 2200 two-vertex fills = 2300 in domain pass an independent structural checker — pure quads, manifold, connected, Euler 1, boundary partition, corner valence 2, boundary valence 3, interior valence 4 except the reported 3/5 pair; every out-of-domain input yields `OutsideConstructionDomain`);
  - `SphereRegionSchedulesAreFilledInEverySymmetry` (three sphere tuples × 8 symmetries; 2, 2, 0 irregular vertices);
  - `RejectsUnfillableAndInvalidBoundaries` ((3,1,1,1), (2,2,1,1), (4,1,2,1), odd total, zero side, over-bound);
  - `RepeatedCallsGiveIdenticalDiscs`.
- Verification (syntax only, not compile evidence): independent apply/reverse and hashes; new files 0 errors / 0 warnings; CMake hunks only add the files to the core library and the completion test binary; no plan identifiers; an independent script reproduced 5000 / 100 / 2200 from the C++ predicate (rotations only; reflections add none).
- Risk: correctness is argued on paper; TB-EXEC-196 is the first execution.

## UC5 — Turn sequence

1. `M6-CP3-CB-221-P13-FOUR-SIDED-DISC-QUADRANGULATION` (compile only) → 2. `M6-CP3-TB-EXEC-196` → 3. `M6-CP3-TB-REV-196` → 4. `M6-CP3-DEFN-P13-A4-DISC-EMBEDDING` (DESIGN §4.9, Tutte) → CB/TB → 5. `M6-CP3-DEFN-P13-A4-SPHERE-REGION-CONSTRUCTION` → CB/TB → 6. `M6-CP3-DEFN-P13-A4-RAIL-AND-CUT-CORNERS` → CB/TB → Vase row → 65B → 65D (O50, Amendment-19) → O41/switch.

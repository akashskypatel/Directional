# M6-CP3-TB-REV-195 — adversarial review (2026-11-28 UTC)

## Situation

The [independent review](Architecture_M6_CP3_TB_REV_195_Region_Corner_Sides_Independent_Review_20261128.md) accepted the 1015-row test gate and CR1–CR4 for the pinned witness and confirmed DD5. **Upheld.** Its successor — one "general constructive A4 contract" for unequal opposite sides — is too broad for one turn and ignores what exists and what does not. Realigned below.

## Findings

**GG1 — Upheld.** Every TB195 prediction matched (`SphereRegionCornerSides built=1 regions=8 corners=32 sides=32`, eight region lines, genus `unsupported-arc-kind` as allowed); the independent table equals the CR2/FF4 table; guards 1014/1015 are non-vacuous (the reversed walk turns 1, not 4).

**GG2 — DD5 must be split along DESIGN's own seam.** DESIGN §4.9 separates A4's combinatorial "general-even-boundary constructibility" from the injective embedding (Tutte's barycentric embedding, Zhou et al. 2020). A census of the code (read-only) shows:

- `PureQuadCompletion` ClosedForm requires equal opposite sides (`side_inequalities_hold`, `PureQuadCompletion.cpp:44`, `:1935`; grid `:2013`); an unequal 4-sided patch is rejected as `SideInequality`.
- `Pattern` and `BoundedCombinatorial` are boundary-only diagonal quadrangulations (`:2139`, no interior vertices) and reject boundaries over `maxBoundaryEdges = 128` (`:2416`); every non-sliver sphere region has 132.
- A `TransitionTemplate` backend exists in the enum (`PureQuadCompletion.h:107`) but was not examined; it must be censused before any new construction is defined.
- No Tutte/barycentric/harmonic embedding exists anywhere in src/.

So nothing in the repository fills a four-corner disc with unequal opposite counts and interior vertices, and nothing embeds one. Disposition: three independently testable steps — (1) a pure combinatorial construction (side counts → pure-quad disc), (2) its injective embedding into the region, (3) wiring the sphere's eight regions — each its own DEFN → CB → TB.

**GG3 — The corner rule covers trace arcs only.** `RegionCornerSides.cpp:110–115` refuses any walk node on a Mandatory or Cut arc. genus_two is closed (`genus_two.fixturemeta.json`), so its refusal is most likely from A2a′ cut arcs (inferred); Vase has a boundary rim, whose corners are the D5/O38 rim-corner product (RA-224/225). A corner-rule extension (Mandatory via the O38 product, Cut arcs typed) must precede the Vase row; the Vase row must not assume CR1 covers rails.

**GG4 — The construction must cover two parity classes.** For side counts (a, b, c, d) with even total, a − c ≡ b − d (mod 2). On the sphere: regions 0, 3, 5, 6 have odd/odd opposite differences (5 and 3), regions 1, 7 even/even (4 and 4), slivers 2, 4 equal (0, 0). The combinatorial step's falsifiers must include both non-trivial classes, the sliver strip, and an exhaustive small-case sweep.

## Turn sequence

1. `M6-CP3-DEFN-P13-A4-UNEQUAL-SIDE-CONSTRUCTION` (NEXT, runtime-free): combinatorial only. Census `TransitionTemplate` first; then define the construction family for a four-corner disc with positive side counts and even total, with a constructive argument per parity class; freeze CB-221 as a pure function plus exhaustive tests. No geometry, no pipeline wiring.
2. `M6-CP3-CB-221-P13-FOUR-SIDED-DISC-QUADRANGULATION` (compile only) → TB-EXEC-196 → TB-REV-196.
3. `M6-CP3-DEFN-P13-A4-DISC-EMBEDDING` (DESIGN §4.9, Tutte) → CB/TB.
4. `M6-CP3-DEFN-P13-A4-SPHERE-REGION-CONSTRUCTION` (schedule + corner sides + construction + embedding for the eight sphere regions) → CB/TB.
5. `M6-CP3-DEFN-P13-A4-RAIL-AND-CUT-CORNERS` (CR1 extension) → CB/TB.
6. Vase row → 65B → 65D (O50, Amendment-19) → O41/switch.

## Closeout

| Duty | Answer |
|---|---|
| Upheld | Gate 1015/1015 test only; CR1–CR4; DD5. |
| Realigned | Successor split (GG2); corner-extension step before Vase (GG3); parity falsifiers (GG4). |
| Boundary | Runtime-free; documentation only. |

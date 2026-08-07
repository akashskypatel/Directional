# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [production runtime contract satisfied; formal closure pending test witness]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G3 endpoint artifact validation complete

Exact tested authority:

- source/test commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- artifact `9010838200`;
- artifact SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- patch SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`;
- recursive checksums **44/44**;
- artifact-only execution with no rebuild or implementation/test/fixture/validator/build edits.

Raw focused/retained contracts: **16/17**. Both endpoint-canonicalization contracts pass; typed field ambiguity passes; all six previously regressed nominal G3 periodic contracts are restored; all seven G1/G2 retained contracts pass.

## Exact cylinder — production G3 closure contract satisfied

The exact cylinder now produces direct authoritative output:

- producer `Produced`;
- output origin `CompletedSurfaceCells`;
- holonomy `r=0`, `t=(32,0)`, route 32, cut 4;
- 1,728 traces;
- 290 arrangement / 290 simplified cells;
- 288 completed/output quads;
- 320 provenance/output vertices;
- zero non-quads;
- validation failures **0**;
- field P95 `8.537736463e-07°`;
- surface approximation P95 `2.832791574e-16`;
- no fallback/recovery;
- output hash `32135be51d7a0a26`, deterministic 3/3.

Independent topology inspection shows exactly 64 boundary edges forming two 32-edge degree-2 loops, one at z=-1 and one at z=+1. The artificial cut is therefore not an exterior seam. Complete provenance is retained (`320 == 320`), and one direct completed cell maps to one output quad (`288 == 288`).

`surfaceCellValidationFailures=0` authoritatively proves the existing normal/field/warpage and other strict validation gates pass. Raw normal/warpage P95 are not serialized by the benchmark JSON; independent serialized-geometry cross-checks report zero warpage and ~`8.54e-7°` nearest-source normal error.

This is material progress over artifact `9008118764`, which rejected at `InvalidPeriodicChart` cell 29 with zero traces/output. The no-progress counter resets; mandatory Review is not triggered.

## Sole formal closure blocker — incorrect unit-test witness

`SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` reaches `Produced` but fails only:

```text
Expected: exactInterRingEdges > 0
Actual:   0
```

Classification: **incorrect expectation / invalid witness precondition**, not production failure.

The test only counts a V-family phase-front edge when both endpoints are distinct exact source vertices. Its fixture has 0.5 source-ring spacing and its target is 0.25, so production uses two V steps per source inter-ring edge. Such an un-subdivided phase-front witness cannot exist even for the correct axial correspondence.

The fixture remains valid. Correct the witness to inspect nonzero source-attached V boundary-path segments, reconstruct their source-space direction from face+barycentric provenance, compare against the local authoritative V cross-field family, and require a nonempty observation set. Do not rely on source IDs, historical grid/count values, or exact un-subdivided source-edge cardinality.

## Required next turn

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md` as **Code + Build only**.

1. Expected production source change: none.
2. Replace only the invalid `exactInterRingEdges` witness with subdivision-invariant source-attached V segment evidence.
3. Preserve the field-ambiguous typed-rejection test unchanged.
4. Preserve endpoint, annulus, cut/holonomy, source-strip, artificial-cut, malformed-holonomy and G1/G2 tests unchanged.
5. Compile/package the established seven approved targets with `PRE_TEST`.
6. Execute no generated Directional binary.
7. Remove bounded workflow/trigger/payload after artifact verification.

The following artifact-only turn must obtain 17/17 focused/retained contracts and revalidate exact cylinder/G0-G2. If cylinder retains the strict-valid direct periodic output above, mark G3 passed and activate G4.

## Supporting suites

- bounded producer: **99/101**; failures are the incorrect field witness and known scheduler-sensitive validator-overhead performance check;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- bounded aggregate: **321/333**;
- bunny: later-gate `NotApplicable`, 80,862 traces, ~22.42 s;
- vase: later-gate 45 s bounded timeout; failure only.

Direct gate status outranks aggregate totals. Review policy remains `never`. Every completed turn ends with a new top-level PR #8 comment after all other repository writes.

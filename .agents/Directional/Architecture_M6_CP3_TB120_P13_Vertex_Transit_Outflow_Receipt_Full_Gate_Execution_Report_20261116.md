# TB120 — vertex-transit outflow receipt full-gate execution (2026-11-16 UTC)

## Situation

The immutable CB139 diagnostic package was tested without rebuild. The 947-case full gate and the registered three-case production census returned a **scoped MATCH** against TB119. This is evidence for P13-e.14, not CP3 or production acceptance. **Next separate turn:** `M6-CP3-DEFN-P13-VERTEX-TRANSIT-OUTFLOW-OUTCOME`. No Review work is performed in TB120. The census ledger has exactly two nonsemantic `first_failure` source-line offsets (405 to 432) from the diagnostic test edit; verdicts and typed reasons are unchanged.

## Background — immutable source and runs

- Compiled source `c520674030c76be455111d7c41aae7d5f53ce900` and artifact `14199183882` (ZIP `daac64075be07c96f0654a933cb0be919f6ce8046c67104786c1caaa1760d120`, 28/28 internal hashes, GMP/GMPXX, compile-only in CB139).
- Executor semantic-source snapshot `415ca426398274884df14de21d14e0077ac96d19`; source, include and tests trees match CB139 exactly.
- Full gate [run 43810896818](https://github.com/akashskypatel/Directional/actions/runs/43810896818), result artifact `14199814782`, outer SHA-256 `fd52e7909650c25466eab857e9473fd2c448b502a25ad99df1fca02530cf7206`; immutable 947-case manifest `3aac432b9f466e5ce06601c90a08ad09c1886dfeb97c38b05e9bd46f51a1190b`.
- Census [run 43810956948](https://github.com/akashskypatel/Directional/actions/runs/43810956948), result artifact `14201142306`, outer SHA-256 `4d680693e516a34a68037d24028de2a215042f34f3f9e93f5aa87288b7b90aec`; immutable three-case manifest `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`.
- The independent local evidence analyzer checked all result files against each artifact's `SHA256SUMS`, and compared test ledger semantics and frozen receipt lines to TB119. Gate records: 947; census records: 3; mismatched ledger records: 0/2; changed frozen receipt rows: 0/0.

## Assessment

1. Gate execution boundary: `{"artifact": 14199183882, "benchmark": false, "compile": false, "configure": false, "error": "", "exit": 0, "relink": false, "source": "c520674030c76be455111d7c41aae7d5f53ce900", "state": {"abnormal": 0, "control_bad": 0, "duplicate": 0, "executed": 947, "later_positive_red": 0, "membership": 1028, "missing": 0, "passed": 947, "planned": 947, "postflight": true, "red": 0, "red_site_bad": 0, "skipped": 0, "unexpected_pass": 0}}`. Gate diagnostic R1 count `0`, with per-row counts `{}`.
2. Census execution boundary: `{"artifact": 14199183882, "benchmark": false, "compile": false, "configure": false, "error": "", "exit": 0, "relink": false, "source": "c520674030c76be455111d7c41aae7d5f53ce900", "state": {"abnormal": 0, "control_bad": 0, "duplicate": 0, "executed": 3, "later_positive_red": 0, "membership": 0, "missing": 0, "passed": 1, "planned": 3, "postflight": true, "red": 2, "red_site_bad": 0, "skipped": 0, "unexpected_pass": 0}}`. Census diagnostic R1 count `3`, with per-row counts `{"2": 3}`.
3. Census outcomes:
- Row 1: `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder` — PASS; terminal []; edge-port departures 0
- Row 2: `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom` — RED; terminal ["terminal=NotProductionReady:field-aligned-network detail=BranchContinuationDegenerateEntry traceSegments=0 arrangementCells=0 completedQuads=0 completion= locus face=(137,149,162) branch=0 edge=(137,149) parameter=0/1 exact=0/1 seedVertex=138 seedSingularity=12 history=2"]; edge-port departures 16
- Row 3: `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase` — RED; terminal ["terminal=NotProductionReady:completion detail=AggregateCompletionValidationFailure traceSegments=189462 arrangementCells=26817 completedQuads=67750 completion= locus history=0"]; edge-port departures 0
4. Outflow diagnostic records, observed verbatim:
- Row 2: `FieldAlignedCurveNetwork.vertexTransitWithoutOutflow singularity=6 sourceVertex=49 trace=24 step=0 vertex=48 mode=EdgeTransit arrival=(25,48,49) arrivalBranch=1 carrier=(48,49) owner=(48,271,272) ownerBranch=3 w48=-126.553 w271=128.802 w272=-2.2485 onRadialRay=0 closedFan=1 sectors=7`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitWithoutOutflow singularity=12 sourceVertex=138 trace=51 step=0 vertex=137 mode=EdgeTransit arrival=(137,138,347) arrivalBranch=2 carrier=(137,138) owner=(137,149,162) ownerBranch=0 w137=-160.152 w149=-43.6059 w162=203.758 onRadialRay=0 closedFan=1 sectors=6`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitWithoutOutflow singularity=27 sourceVertex=302 trace=99 step=0 vertex=349 mode=EdgeTransit arrival=(49,302,349) arrivalBranch=1 carrier=(302,349) owner=(5,102,349) ownerBranch=2 w5=98.7874 w102=-0.71448 w349=-98.0729 onRadialRay=0 closedFan=1 sectors=7`
5. Vertex-transit sector records, observed verbatim:
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=0 face=(25,48,49) branch=1 next=25 previous=49 owner=0 inOwnSector=0 w25=-16.9786 w48=119.813 w49=-102.835`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=1 face=(48,49,109) branch=2 next=49 previous=109 owner=0 inOwnSector=0 w48=165.599 w49=-140.962 w109=-24.6364`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=2 face=(48,109,368) branch=1 next=109 previous=368 owner=0 inOwnSector=0 w48=102.26 w109=-211.593 w368=109.333`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=3 face=(48,271,368) branch=1 next=368 previous=271 owner=0 inOwnSector=0 w48=-107.528 w271=139.79 w368=-32.2624`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=4 face=(48,271,272) branch=3 next=271 previous=272 owner=1 inOwnSector=0 w48=-126.553 w271=128.802 w272=-2.2485`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=5 face=(48,86,272) branch=3 next=272 previous=86 owner=0 inOwnSector=0 w48=-8.8432 w86=-49.1058 w272=57.949`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=48 trace=24 step=0 index=6 face=(25,48,86) branch=0 next=86 previous=25 owner=0 inOwnSector=0 w25=-51.2419 w48=35.8159 w86=15.426`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=137 trace=51 step=0 index=0 face=(137,138,347) branch=2 next=347 previous=138 owner=0 inOwnSector=0 w137=216.393 w138=-183.549 w347=-32.8435`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=137 trace=51 step=0 index=1 face=(136,137,138) branch=3 next=138 previous=136 owner=0 inOwnSector=0 w136=-8.58931 w137=218.379 w138=-209.789`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=137 trace=51 step=0 index=2 face=(136,137,149) branch=0 next=136 previous=149 owner=0 inOwnSector=0 w136=-46.9056 w137=-25.3715 w149=72.2771`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=137 trace=51 step=0 index=3 face=(137,149,162) branch=0 next=149 previous=162 owner=1 inOwnSector=0 w137=-160.152 w149=-43.6059 w162=203.758`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=137 trace=51 step=0 index=4 face=(137,158,162) branch=0 next=162 previous=158 owner=0 inOwnSector=1 w137=-145.36 w158=12.9799 w162=132.38`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=137 trace=51 step=0 index=5 face=(137,158,347) branch=3 next=158 previous=347 owner=0 inOwnSector=0 w137=25.5422 w158=64.5205 w347=-90.0627`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=0 face=(49,302,349) branch=1 next=49 previous=302 owner=0 inOwnSector=0 w49=-27.6618 w302=-88.9884 w349=116.65`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=1 face=(302,349,437) branch=1 next=302 previous=437 owner=0 inOwnSector=0 w302=-30.2828 w349=185.157 w437=-154.874`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=2 face=(349,437,455) branch=1 next=437 previous=455 owner=0 inOwnSector=0 w349=194.994 w437=-225.331 w455=30.3377`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=3 face=(102,349,455) branch=2 next=455 previous=102 owner=0 inOwnSector=0 w102=115.078 w349=76.7833 w455=-191.861`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=4 face=(5,102,349) branch=2 next=102 previous=5 owner=1 inOwnSector=0 w5=98.7874 w102=-0.71448 w349=-98.0729`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=5 face=(5,306,349) branch=2 next=5 previous=306 owner=0 inOwnSector=1 w5=95.146 w306=9.75805 w349=-104.904`
- Row 2: `FieldAlignedCurveNetwork.vertexTransitSector vertex=349 trace=99 step=0 index=6 face=(49,306,349) branch=1 next=306 previous=49 owner=0 inOwnSector=0 w49=-56.8986 w306=164.858 w349=-107.96`
6. Any ledger differences: `[{"row": 2, "fields": {"first_failure": ["../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:405: Failure", "../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:432: Failure"]}}, {"row": 3, "fields": {"first_failure": ["../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:405: Failure", "../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:432: Failure"]}}]`. Any receipt differences: `[]`.
7. The frozen RA-239 predictions are observed: P1 `parameter=0/1 exact=0/1`; P2 exactly one R1 with seedVertex=138, seedSingularity=12, step=0=history−2 and owner face/branch equal the locus; P3 no R1 in the 947 gate rows or Cylinder. These are measurements, not gate requirements. The H1/H2 hypotheses remain unreviewed. These raw diagnostic records are measurements, not independent proof of the cause. Stable 66 events/17 categories/49 recurrences, debt1, deferred81, CP2 491/491 remain inherited only; CP3/selector497 unpromoted; `chainRimSchedules=false`; O42/O43 open; D11=A and D10 deferred.

## Recommendation

Preserve both immutable output archives and their SHA-256 digests. Transfer the exact terminal locus, outflow record and sector list to the separate Review turn `M6-CP3-DEFN-P13-VERTEX-TRANSIT-OUTFLOW-OUTCOME`. Do not change source, tests, manifests, or accepted selectors inside TB120.

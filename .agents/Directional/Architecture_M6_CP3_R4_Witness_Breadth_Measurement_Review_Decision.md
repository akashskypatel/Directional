# Review decision — the breadth measurement, the carrier it measured, and the control it did not provide

**Turn adjudicated:** `M6-CP3-TB1-R4-WITNESS-BREADTH` (Test + Benchmark, artifact-only).
**Disposition:** the **measurement is ACCEPTED**; its **reported turn state is CORRECTED** (the workflow
concluded `failure`, the measurement did not); the **control claim in my own prior `NEXT_TURN` is
WITHDRAWN as false on the bytes**; **RA-56.5 is RESOLVED**; the repair remains **DEFERRED** behind one
corrected control rung and the census. Frozen as **RA-57**. No promotion, no new stable event, no 497 run.
Ledger **66/17/49**, debt **1**, CP2 **491/491**, R3 **403/497**, frozen selector **497** — all unchanged.

Evidence files frozen beside this record:
`Architecture_M6_CP3_R4_Witness_Breadth_Ledger_20261015.tsv`,
`Architecture_M6_CP3_R4_Witness_Breadth_Measured_Predicates_20261015.tsv`,
`Architecture_M6_CP3_R4_Witness_Breadth_Execution_Boundary_20261015.txt`.

## RA-57.1 — the measurement is accepted, and I re-derived it from the artifact rather than from a report

No TB report was written. The turn closed `IN_PROGRESS` with `Successor` pointing at itself
(`63388be98`, "pending documentation transport"). I therefore took the evidence from the immutable
result artifact directly, not from prose: run `38676433923`, artifact `11946622500` (not expired),
downloaded ZIP SHA-256 `127c77580a9e77dafb1889575b8d69bdbe0271f7a3fc8041fc6c904e9918c6a3`.

`execution-boundary.txt` reads `artifact_id=11939982141`, `source_sha=953f812f…`, `executed=4`,
`red=4`, `missing=0`, `postflight=true`, `compile=false`, `relink=false`, `benchmarks=false`,
`selector497=false`. `immutability.txt` reads `package=true source=true execution_view=true
selector=true`, and `manifest-before.txt` / `manifest-after.txt` are **28 OK / 28 OK**. The harness
(`.agents/Directional/tools/m6_cp3_r4_witness_breadth_harness.sh`, SHA-256
`db1aea68782f68196da0abf26be24f6648e9c565d305f3200ced09740aedd65a`, matching the dispatch record)
re-verifies the provider digest, the artifact digest, the package manifest, the packaged source hash
and **all four frozen selector hashes** before and after execution. `git diff a44bbf534..HEAD --
src include tests cmake` is **empty**. The prohibitions held: the measurement rung edited no source.

**The turn's product is therefore complete and valid.** What is missing is only the write-up, which
this Review supplies from the bytes.

## RA-57.2 — 4/4 RED, four independent entry paths, one single carrier. The carrier is now MEASURED.

| # | identity | owning file | first predicate |
|---|---|---|---|
| 1 | `M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm` | `tests/SurfaceCellTransitionQuotientTests.cpp:9111` | `endpoint-1` |
| 2 | `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement` | `tests/SurfaceCellREPackageTests.cpp:520` | `endpoint-1` |
| 3 | `SurfaceCellAuthorityContractCutover.DuplicateSourceTerminalContactRejectsAtFirstA4ConsumerPredicate` | `tests/SurfaceCellsPhase10Tests.cpp:7148` | `endpoint-1` |
| 4 | `SurfaceCellAuthorityContractCutover.StandaloneRailDiagnosticModeCannotBypassProducedNetworkTypedIngress` | `tests/SurfaceCellsPhase10Tests.cpp:6503` | `endpoint-1` |

All four fail at `tracing/phase-front` with `InvalidHardRailRouteCertificate`, all four with
`a2bProbeFailure=no-exact-terminal-corner`, all four on source edge `(1,4)` with `faces=0,3`, all four
`locus=3`, `rail=2`, `routeLength=1`, `step=0`, `vertex=-1`, `faceEnds=0,2|0,3`,
`carrier=1 a3=1 contact=1 closedChain=0`.

Three distinct files, three distinct fixture builders, one focused-factory entry, two focused-producer
entries and **one full `remesh_from_raw_cross_field` pipeline entry**. **RA-56.8 is satisfied: this is no
longer one measured identity, it is a measured carrier.** The `A4_ROUTE_CERTIFICATE_REJECTION` reading of
RA-56.3 is confirmed by execution, not inferred from a static inventory.

## RA-57.3 — my own control was not a control. WITHDRAWN.

My prior `NEXT_TURN` ordered identity 1 first and said, in terms: *"run this FIRST. It is THE CONTROL, on
a **different fixture**. It separates 'the rectangular hard-rail family is down' from 'A4 production is
down generally.'"* **That claim is false on the bytes and I withdraw it.**

`make_nonconstant_hard_rail_fixture` (`tests/SurfaceCellTransitionQuotientTests.cpp:776-853`) builds a
3×3 planar grid over `vertices(9,3)` / `faces(8,3)` by the same nested `y`/`x` loop as
`make_rectangular_internal_hard_feature_grid` (`tests/SurfaceCellREPackageTests.cpp:46-75`, `columns =
rows = 3`), and inserts `userHardEdges {1,4}` and `{4,7}` at `:830-831` — **the identical midline rail
chain `1→4→7` with the identical terminals `{1,7}`** that `build_rectangular_hard_rail_phase_front`
uses. It is a different *file*, a different *builder* and a different *field*. It is the **same mesh,
the same hard feature and the same rail**. It never had the discriminating power I assigned it.

This is a design error in the instrument I specified, not an execution defect: the executor ran exactly
what was ordered, ran all four as RA-56.4 required, and the harness proves it. The error is mine and is
recorded here rather than quietly amended, per `RP-03`.

## RA-57.4 — what the rung therefore cannot establish

**All four identities run on the same 3×3 unit planar grid with the `x=1` midline hard feature.** The
breadth rung measured **one mesh through four entries**, not four meshes. It establishes that the defect
is not entry-path-specific, not fixture-helper-specific and not confined to the focused producer. It
establishes **nothing** about mesh generality, and it does **not** separate "all open hard-rail
production is down" from "A4 production is down generally." That question is still open and is now the
first thing the next rung must answer.

## RA-57.5 — RA-56.5 is RESOLVED: the geometry is ACROSS-rail, not ALONG-rail

The emitter at `src/geometry/SurfaceCellTracing.cpp:18948` prints
`faceEnds = first.from.face, second.to.face | first.to.face, second.from.face`, and `:18939-18940` make
`currentFace` / `expectedFace` fallback echoes of the first two — RA-56.1 confirmed again. Reading the
measured `faceEnds=0,2|0,3` through that emitter:

- `first.from.face = 0`, `first.to.face = 0` — the first front begins and ends **inside face 0**;
- `second.from.face = 3`, `second.to.face = 2` — the second front begins **in face 3**.

On this mesh `face 0 = (0,1,4)` and `face 3 = (1,5,4)` are exactly the two faces incident to edge
`(1,4)` (`edge[0]=1,4:faces=0,3`), i.e. the two sides of the rail. The paired probes confirm it:
`a2bProbeFrom` is in face **0**, `a2bProbeTo` is in face **3**, and both resolve to the same point on
`(1,4)`.

**The two fronts approach the rail from opposite faces and meet at a shared interior point of it.** They
are not two collinear intervals running along the rail. The retained repair plan's prescription — *"ordered
rail interval/face-side ownership"* — presumes the along-rail frame and is therefore the wrong vocabulary.
**It must be amended before `M6-CP3-CB1-R4-WITNESS-REPAIR` is re-entered.** This was the RA-45.2 category
error RA-56.5 was raised to prevent; it is now caught before any code was written against it.

## RA-57.6 — the failure is field-independent and transition-independent

Identity 1 runs a **non-constant** field (`constant_xy_field` with the `centerX > 1.0` patch rewriting
faces 2, 3, 6, 7 — face 3 is one of the two rail faces) and reports `edge[0]=1,4:faces=0,3:**chi=3**`.
Identities 2–4 run a constant field and report **`chi=0`** on the same edge. The A3 transition index
across the rail differs by 3 and **the failure is byte-identical**. Identities 1 and 2 pair at interior
parameter **0.2**; identities 3 and 4 at **0.25**. Same failure.

Two different fields, two different A3 transitions, two different interior parameters, identical
rejection. **The defect does not depend on the field, on the transition, or on where along the rail the
fronts meet — only on the fact that they meet anywhere other than a terminal corner.** Any repair
proposing a tolerance, a parameter special case or a transition-conditioned branch is already falsified.

**Second-order hazard, recorded not chased:** identity 1/2's two charts report the shared third
barycentric as `0x1.9999999999999p-3` and `0x1.9999999999998p-3` — **one ULP apart**. A replacement
certificate that demands bit-exact agreement of the two charts' coordinates would fail here exactly as
`exact_corner` does now. The correct instrument is the exact rational parameter on the shared source
edge, not a float comparison in either chart.

## RA-57.7 — three live hypotheses remain, and `routeLength=1` promotes the third

`routeLength=1` with `step=0` in **all four** means every failing route is a **single step**. A genuine
route from an interior rail point to a whole-rail terminal would in general be longer. The hypothesis
set is therefore:

- **(a) the certificate is too strict** — the pairing is correct and an interior shared rail point ought
  to be certifiable by exact rational parameter rather than one-hot corner;
- **(b) the pairing is wrong** — these two fronts should never have been offered as a terminal-closing
  pair;
- **(c) the route is truncated** — the route should have continued to a terminal and stopped at step 0.

`routeLength=1` is evidence for (c) and it was not previously on the list. **None of the three may be
chosen now.** Choosing before the census is the RA-45.2 category error; RA-57.5 only removed a fourth,
wrong, frame.

## RA-57.8 — two design defects in the measurement harness

**(i) A measurement rung must not fail its workflow on RED.** Line 85 is a bare `[[ "$red" == 0 ]]` as
the script's last statement, so four expected REDs set exit 1, the `test_benchmark / runtime` job
concluded `failure`, and the turn was left `IN_PROGRESS` with its product unreported even though
`executed=4 missing=0 postflight=true` and every immutability receipt passed. RED **is** the product of a
triage rung. The orchestration verdict must come from `executed`, `missing` and `postflight` only; the
RED count belongs in the ledger, which already carries it. Line 84's `die 'incomplete breadth'` is
correct and stays.

**(ii) `die` on non-selection re-introduces the early stop RA-56.4 removed.** Line 68 aborts the whole
loop with exit 90 if `picked != 1` for any identity, so one mistyped or retired identity would silently
cost every identity after it — the same failure mode as stop-at-first-RED, through a different door. It
must record `NOT_SELECTED` for that ordinal and `continue`.

## RA-57.9 — RA-52.6 now has a measured violation

Identity 4 is the retained attempt that RA-52.6's forward reading — *a retained guard needs a retained
attempt* — kept alive. It is RED at its `Produced` precondition
(`tests/SurfaceCellsPhase10Tests.cpp:6506`), so the retained attempt **cannot presently run**, and the
guard it was retained to exercise is therefore unexercised at runtime. Identity 1 is the same shape: the
test body throws inside `nonconstant_hard_rail_fixture()` on its first line, so the forged-germ rejection
the test exists to prove is never reached. **Two guards are now known-unexercised for the same upstream
reason.** They stay retained and fail-closed; nothing is retired. This is recorded, not chased.

## RA-57.10 — a gtest suite name is not unique across targets

`SurfaceCellPipelinePhase20` has members in **both** `tests/SurfaceCellREPackageTests.cpp` (in
`directional_surface_cell_producer_tests`, `cmake/DirectionalTests.cmake:83`) and
`tests/SurfaceCellPipelinePhase20Tests.cpp` (in the `DIRECTIONAL_BUILD_HISTORICAL_TESTS`-gated
`directional_surface_cell_historical_tests`, `cmake/DirectionalTests.cmake:571`). A bare `Suite.*`
filter denotes **different sets in different binaries**. The fully qualified `Suite.Name` citation rule
adopted after RA-56 held here and must continue to; a suite-level filter must never be used to name an
obligation.

## RA-57.11 — a throwing fixture singleton has a blast radius

`nonconstant_hard_rail_fixture()` (`tests/SurfaceCellTransitionQuotientTests.cpp:855-858`) is a
`static` function-local singleton. It throws. **Every** consumer goes RED with it — at least
`:2837`, `:2863`, `:3890`, `:8813`, `:8858`, `:9112`, plus `make_nonconstant_hard_rail_fixture(true)` at
`:2935`. This is consistent with the carrier inventory's 19 Quotient-owned members and predicts that a
single upstream repair clears them together. It also means the census must report **which fixture
singleton** each failing identity hangs off, or it will count one defect many times and read it as many
defects.

## RA-57.12 — the census design is amended

RA-56 prescribed deciding the along/across question "from `faceEnds`". RA-57.5 has now decided it, and in
doing so showed that `faceEnds` is **an echo set with low discriminating power**: it was byte-identical
across two mesh families, two fields, two transitions and two parameters. The census must therefore key
on fields that actually vary — `routeLength`, `step`, `chi`, the probe charts and parameters, the owning
fixture singleton, and whether `closedChainPresent` is 0 or 1 — and must not be read as corroboration
when `faceEnds` repeats.

**Lesson, minted:** *a signal that never varies is not a measurement.* Four identical `faceEnds` across
four entries looked like four confirmations and were one echo printed four times.

## Obligations carried, none retired

`RP-02` still open — the network-bound consumer has still never been reached. `R4-OHF-02` recorded, guard
retained, no probe. `RP-01`, `RP-03` standing. RA-41's junction/sector clauses frozen **UNEXERCISED at
runtime**, now joined by the two guards of RA-57.9. The two Phase14 supplementals still require a
separately packaged historical executable (`cmake/DirectionalTests.cmake:554-572`) and must not be
bundled into a measurement rung. Backlog beyond the census: the 39-identity carrier, 34 Phase10, seven
DCEL, six CP3, the CP2 restorations outside the 37, organic D1/D2/D3/D5 and A6/A7, odd-τ. The retained
repair plan `Architecture_M6_CP3_R4_Witness_Interval_Terminal_Recovery_Code_Build_Plan.md` stands except
for the interval vocabulary RA-57.5 invalidates.

## Successor

**`M6-CP3-TB1-R4-TRUE-CONTROL`** — artifact-only, no rebuild, same package. The control I failed to
specify, now specified from the bytes: identities whose fixtures carry **no interior midline hard rail**,
and one whose rail is a **closed chain** rather than an open one. All are already inside
`directional_surface_cell_producer_tests`, so the rung is free. Only after it may
`M6-CP3-TB1-R4-ENDPOINT39-CENSUS` be read correctly, then `M6-CP3-TB1-R4-CARRIER-REV`, then the retained
and amended `M6-CP3-CB1-R4-WITNESS-REPAIR`.

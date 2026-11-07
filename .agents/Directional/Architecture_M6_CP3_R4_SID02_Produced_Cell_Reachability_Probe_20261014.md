# M6-CP3-CB1-R4-SID02-PROBE — source-only equal-opposite-corner reachability

Authority: RA-52.5 / `R4-SID-02` in `Architecture_M6_CP3_R4_Selected_Branch_And_Diagnostic_Optout_Review_Decision.md`. Exact source snapshot `43e8a503baa1896fd133eecda5ce6a323b9229ed`; Actions run `38625280153`, artifact `11923063390`, outer SHA-256 `99a9b858868faea05480bc42d9c6e7bbc0019c8069bc4a025edc6f8559b68291`; source archive SHA-256 `aea5c4590518cbc62e0dc3153374da3aa67bfa967cb50a4bf9786f2cc85e6622`; **5596/5596 hashes verified**. Inspection only: no build, executable, test, benchmark, or source code mutation.

## Answer and disposition

**The precise configuration `corners[0] == corners[2] && corners[1] == corners[3]` cannot be emitted by the currently implemented A4 source producers as an accepted `SurfacePhaseFrontCell`, when equality denotes the same geometric corner/point.** Retire **that exact** `R4-SID-02` proposed A5-locus repair as producer-unreachable; retain existing fail-closed validators. Do **not** add an A5 guard, a new receipt/producer/namespace, or runtime/acceptance credit in this turn.

## Complete producer census and proof

1. `src/geometry/SurfaceCellTracing.cpp:12772` produces the uniform planar cells (`:12918-12965`). Every candidate goes through `orient_and_validate_phase_front_cell` (`:12627-12682`, call `:12957`). That function checks **all six** distinct corner-position pairs and rejects a separation no greater than `max(1e-12, 1e-9 * target)` before orientation validation. Thus identical opposite corners fail with `InvalidCellOrientation` before the cell is appended at `:13036`.
2. Periodic-annulus producer (`:13545`, cell at `:14629`) requires a finite, nonzero `phase_front_loop_normal` and positive orientation (`:14682-14709`) before appending at `:14761`. For a physical alternating two-point cycle A,B,A,B, the four directed cross-products are A×B + B×A + A×B + B×A = 0, so it cannot pass. Reversal at `:12364-12374` cannot change this.
3. Curved bounded-disk producer (`:14832`, cell at `:17188`) imposes the same nonzero, positively aligned loop-normal requirements (`:17230-17262`) before appending at `:17344`. The same cancellation holds.
4. These three variants are the complete dispatched region-build cases at `:17819-17832`; final aggregation at `:17950-18010` renumbers cells but does not alter corners. `publish_phase_front_result` (`:12721-12761`) is the only producer publication path, delegating to the checked `SurfacePhaseFrontProduct::make`. The legacy proposal tracer is not a produced phase-front cell (`:19543-19570`).

**Independent A5 discriminator:** Each producer assigns a quad's corner lattice coordinates `(u,v), (u+1,v), (u+1,v+1), (u,v+1)` (`:12935-12938`, `:14629-14644`, `:17188-17212`). Reversing orientation only permutes them. Front edges copy the corresponding per-corner lattice states and `filledSide` (`:12965-12994`, `:14711-14734`, `:17264-17290`). At A5, `lattice_equal` compares exact `latticeCoordinate` values as well as phase, chart, branch, scale (`src/pipeline/RemeshPipeline.cpp:3311-3321`, applied at `:3583-3588`). Sides 0 and 2 therefore **cannot** both authenticate one unchanged front-edge lattice-state pair even if their trace positions were identical. The proposed ambiguity is not established by coincident trace points alone.

## Scope caveat: tolerance is not point identity

A5 `trace_equal` (`src/pipeline/RemeshPipeline.cpp:3307-3310`) accepts same-face barycentric differences of norm ≤ `1e-10`; this is **not** `operator==` and does not imply identical world-space positions on arbitrary-scale triangles. The strict equal-point result above should **not** be expanded into a universal proof that *near-equal under this tolerance* is impossible on all input scales. That broader numerical scenario is not the precise equal-corner configuration specified by RA-52.5, and A5's independent lattice discriminator remains in effect. No near-equality witness was constructed or executed.

## Downstream guard and acceptance boundary

If quotient equivalence later merges corners, `SurfaceQuotientProducer::publish_records_for_validation` rejects a classed cell with fewer than four distinct corner classes as `DegenerateClassedQuad` (`src/pipeline/RemeshPipeline.cpp:6340-6351`); A6's adjacent-only check (`:8446-8449`) and A7's `quad-degenerate` check (`:7482-7486`) remain fail-closed. Those later checks are distinct from proving an A4-produced raw cell with equal opposite corners. RA-52 is preserved as historical review authority; this source-only probe refines its conditional reachability conclusion without changing frozen definitions.

**Next independent work:** the authorized single comment correction at `src/geometry/SurfaceCellTracing.cpp:1457-1459`; do not touch `:1460-1467`. Other RA-52 obligations remain as listed in the current handoff. There is no authorized canonical successor turn ID in this source-only probe; the turn beacon may use `Successor: UNKNOWN`.

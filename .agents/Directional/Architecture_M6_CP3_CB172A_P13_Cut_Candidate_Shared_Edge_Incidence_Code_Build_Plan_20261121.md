# M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE — bounded Code + Build plan (frozen at TB-REV-155)

**Authority:** M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE ([independent review](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Independent_Review_20261121.md)). Source starting point: verified current working branch after this Review; immutable TB155 semantic source `65ae140e49db5bd04d202390e71b50f455ff152e`. **Next separate turn only.** Do not start implementation in TB-REV-155.

## Requirement

Restore exact, deterministic validity of the existing cut-graph rotation construction when a trace-piece ray lies along a source edge. Preserve all genuine distinct incurrences, source-chart identities, mandatory ownership, and fail-closed checks. Diagnose the actual pair before changing any ordering or cut set.

## Narrow sequence

1. At `EmbeddedGraphTopology.cpp` along-edge duplicate-primary rejection and `SurfaceCutGraph.cpp` cut-candidate building, capture both exact conflicting incidences with stable arc ID, kind (Trace / Cut / Mandatory), trace ID and piece end, source vertex, source edge and source chart. Capture certification attempt and cut-edge count. Do not use world-space distances or unspecified incidental ordering.
2. Reproduce the trace14 edge0–69 collision independently on a small source-authoritative case, with a positive non-colliding control and a distinct-incidence **negative control that must still reject**. Test cut-candidate stages, not only the pre-cut network used by row971.
3. If both incidences have a proved single semantic owner, implement a canonical representation or exact cut-candidate compatibility rule at the source of duplication; if they are distinct and their ordering is undefined, **retain the fail-closed guard and STOP for further independent design review**, rather than skipping needed cuts or hiding the error.
4. Preserve the accepted source-face-locus assertion on row858; do not alter the test to accept a missing face. The production error must be accurately attributed with source location. Only a separately reviewed contract change can replace an accepted failure-locus requirement.
5. Extend the existing exact tests only where needed to distinguish valid shared-edge co-ownership from invalid collision. Keep all unrelated assertions, selectors, and frozen manifests unchanged. Run only the mandatory GMP/GMPXX compile targets through existing reusable workflow, no runtime tests or benchmarks in this Code + Build turn.

## Before-built falsifiers and STOP

- No paired, independently verifiable provenance at the failing certification → **STOP** without a semantic fix.
- A distinct valid incidence is silently removed, two source sheets merged, a mandatory cut omitted, or an edge ray sorted with a made-up second parameter → **STOP**.
- Formerly accepted source-face assertion weakened, source chart or edge identity lost, any unchanged-row expectation modified, or selector altered → **STOP**.
- Any compile failure, GMP/GMPXX absence, or unverified source/package identity → **STOP**.
- A compile-only PASS does not prove runtime. The authorized successor after a successful CB is a separately frozen immutable full gate plus census and independent Review; only those can decide TB155 STOP removal.

**Held:** stop-switch, four-contact χ+4 repair, RA-275 S4a seed proof, O48/O49, selector497/CP3 promotion, unrelated work.

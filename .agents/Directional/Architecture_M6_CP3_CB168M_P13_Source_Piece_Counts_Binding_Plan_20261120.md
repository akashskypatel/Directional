# CB168M, CB168N and TB151 — exact EPO-3 source-piece binding (frozen by RA-273, 2026-11-20 UTC)

## Situation

TB150 PASS stands. The production graph still writes each slide as one face chord. Before real slide pieces can be published (the cutover), every trace arc needs an exact binding from segments to pieces: EPO-3 in the [TB140 Review](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md).

[RA-273](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Independent_Review_20261120.md#ra-273--adversarial-re-review-of-this-review-2026-11-20-utc) withdraws the earlier prose version of this plan for three reasons:
- it was not an exact patch;
- its required two-piece positive was unreachable through the replay;
- its digest rule would have broken its own census MATCH.

It is replaced by two exact compile-only turns and one Test + Benchmark.

## Exact patches (apply in order)

| Turn | Patch | SHA-256 | Numstat |
|---|---|---|---|
| `M6-CP3-CB168M-P13-SOURCE-PIECE-BINDING-HELPER` | [diff](Architecture_M6_CP3_CB168M_P13_Source_Piece_Binding_Helper_Exact.diff) | `f65b470dfa00dfedd808a3d6db9a602e77147b77747771826c78f662f30abf91` | `48 4 src/geometry/EmbeddedGraphTopology.cpp; 26 3 src/geometry/EmbeddedGraphTopology.h; 133 0 tests/FieldAlignedCurveNetworkTests.cpp` |
| `M6-CP3-CB168N-P13-SOURCE-PIECE-COUNTS-FIELD` | [diff](Architecture_M6_CP3_CB168N_P13_Source_Piece_Counts_Field_Exact.diff) | `eddf8000ad40251a3b8a60b3d197229f8f8b5406b2789998e9c3d96ce4e37dc2` | `6 0 include/directional/geometry/GlobalTopologyPlan.h; 5 1 src/geometry/EmbeddedGraphTopology.cpp; 7 13 src/geometry/GlobalTopologyPlan.cpp; 91 0 tests/FieldAlignedCurveNetworkTests.cpp` |

**Prechecks.**
- **CB168M:** `git diff --quiet 041bde764365710e6d5148c43751da91205ffd35 HEAD -- src include tests`, then `git apply --check`. Preimage SHA-256: `EmbeddedGraphTopology.cpp` `28802d65…486d`, `.h` `4399eed3…172c`, tests `324b9e82…eaa9`.
- **CB168N:** applies on the CB168M result. Preimages: `EmbeddedGraphTopology.cpp` `ca8d4ae6…9201`, tests `a78bbab5…bb4`, `GlobalTopologyPlan.h` `9ed3a4ce…c959`, `GlobalTopologyPlan.cpp` `3825ba33…1439`.

The Review ran `git apply --check` for both in order. `-fsyntax-only -Wall -Wextra -include iterator` warning counts equal HEAD, with 0 errors:

| File | Warnings |
|---|---|
| `EmbeddedGraphTopology.cpp` | 22 |
| `FieldAlignedCurveNetworkTests.cpp` | 42 |
| `GlobalTopologyPlan.cpp` | 24 |
| `SurfaceCutGraph.cpp` | 27 |
| `GlobalConformityBaselineTests.cpp` | 30 |

Each CB compiles the eight RA-245 GMP/GMPXX targets with `runtimeExecution=false`. STOP on any precheck, apply, compile or package-hash failure.

### CB168M — binding helper, unwired

- **`source_piece_binding_failure(sourceFaces, sourcePieceCounts, sourcePath)`** in `embedded_graph_topology_detail`. It returns nothing when the binding holds. Otherwise it returns `SourcePieceBindingFailure{segment}`, where `segment` is empty when the counts do not partition the path.
- **The rule:**
  - counts are parallel to faces, each count is 1 or 2, and the counts sum to the path size;
  - segment k's pieces are `[face(F_k)]`, `[face(F_k), edge of F_k]` or `[edge of F_k]`;
  - an edge piece ends at a source vertex unless it is the path's last piece;
  - canonicity is checked by the existing predicate, not here.
- **`exact_trace_piece_path_between(…, std::vector<std::size_t> *pieceCounts = nullptr)`** reports each segment's piece count after clipping, and writes the counts only on success. Counts and path come from one decomposition (EPO-2).
- **Row 965 test `FieldAlignedCarrierOccupancy.SourcePieceCountsBindEachTraceSegmentToItsRealPieces`.** It uses the row 960 slide fixture.
  - **Positives:** for eight ranges (whole trace, slide cut, face cut and segment bounds) plus an edge-only departure, the produced counts equal the expected ones and the helper accepts them. The `[2,1]`, `[2]` and `[1,1]` cases cover all three shapes on real output.
  - **Negatives:**
    - counts with no partition: missing, extra, a wrong sum, zero/three, above two;
    - a split in the wrong place (`[1,2]`);
    - a wrong face;
    - permuted pieces;
    - an edge that is not an edge of the face;
    - a non-last edge piece ending inside an edge, against the same shape ending at a vertex;
    - the last-piece exemption;
    - counts untouched when the path fails.

### CB168N — field and validator, all-ones producer

- `GlobalTopologyArc` and `ArcDraft` gain `std::vector<std::size_t> sourcePieceCounts`, appended last. Every positional initializer stays source-compatible: the inventory lists 10-element initializers in tests and the 11-element converter, which is updated.
- `build_arcs` assigns `ones(sourceFaces.size())` to trace arcs. `exact_trace_path_between` and every path are unchanged.
- `validate_candidate_structure` replaces the 1:1 rule with `source_piece_binding_failure` and keeps `InvalidSourceBinding`. It sets `failure.sourceFace` exactly when a segment is named, so the old error detail is preserved for count-1 face pieces. A mandatory or cut arc must have empty counts.
- **Intentional relaxation:** a trace segment may now be one edge piece of its face at the structure stage. The replay against the producer still rejects anything the producer did not emit.
- **No digest change** (RA-273 S2.3).
- **Row 966 test `GlobalTopologyPlan.IndependentValidationBindsTraceSegmentsToSourcePieceCounts`.** It uses the cp3b fixture of the accepted tamper matrix, row 441, which is left untouched.
  - Production arcs carry all-ones counts, edge arcs carry empty ones, and the untampered candidate rebuilds.
  - Missing, extra and summed counts, and a count on an edge arc, are rejected as `InvalidSourceBinding` on that arc. The old code would have reached the replay and returned `RegionBoundaryArcNotOwnedByNetwork`.
  - The last chord is split into a face piece and an edge piece of its face. With count 1 the binding rejects it. With count 2 only the replay rejects it (`RegionBoundaryArcNotOwnedByNetwork`), which proves the validator is no longer 1:1.
  - **Test precondition:** a cp3b trace arc ends at an interior edge point. Row 441's split mandatory arc implies one exists. If it does not, row 966 is RED; that is a test defect routed to Review, not a product failure.

## Frozen `M6-CP3-TB151-P13-SOURCE-PIECE-COUNTS-FULL-GATE-EXEC`

- **Inputs:**
  - the immutable CB168N package;
  - manifest [`gates/Architecture_M6_TB151_P13_Source_Piece_Counts_Full_Gate_Case_Manifest.tsv`](gates/Architecture_M6_TB151_P13_Source_Piece_Counts_Full_Gate_Case_Manifest.tsv), SHA-256 `2a902d364612071db04ffa5a116cd988c0babccae58308152cb368df0ff612da`. It is the TB150 manifest byte-for-byte plus rows 965 and 966: 966 gated + 81 deferred, membership 1047;
  - the unchanged three-row census.
- **STOP on failure:**
  - rows 965 and 966 PASS;
  - rows 1–964 MATCH TB150 under N1–N3, with receipt lines compared raw and no deletion;
  - 491/491;
  - census 3/3 MATCH TB150 under N1–N4, including every `platform-digest` field;
  - no compile, relink, configure or benchmark.
- **Expected:** every prior row and census line is byte-identical after normalization, because paths, digests and dispatch are unchanged. Any difference is a STOP routed to Review.
- **Successor:** `M6-CP3-TB151-P13-SOURCE-PIECE-COUNTS-FULL-GATE-REV`. It freezes the cutover split from the RA-273 S4 reader inventory.

## Deferred, not authorized here

EPO-2 producer conversion, EPO-4 rays and ranks, EPO-6/O49, the H4 cutover, the row 686 piece oracle, the stop switch, O48, and any promotion. Counts enter the digest at the cutover.

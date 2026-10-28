# TB47 same-turn R54 — torus hard-carrier survival under one-face cyclic arm relabel

**Boundary and status.** Independent Review-only numerical/source audit within `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER`. No native Directional execution, compile, benchmark, test/fixture/selector/manifest/workflow edit, or successor action. R53's G3 *conditional* face-gauge coboundary does not by itself establish a produced odd periodic witness.

## New first-owner precondition: the candidate can disappear before the gauge test

In the frozen C++ test source `tests/SurfaceCellTransitionQuotientTests.cpp`, `make_nonzero_z4_torus_witness_fixture()` fills `nonzeroHardCarriers` **only** when `sourceCrossField` has a nonzero `QuarterTurn` on each of the 18 hard edges (source around lines 1702–1711). `enumerate_torus_source_witnesses()` again requires nonzero *directed* `sourceRotation`, a matching A3 atlas transition and a valid exact one-carrier canonical route (around lines 1560–1687). A subsequent odd face-gauge delta is insufficient if its source carrier becomes zero after relabel. Thus the previously suggested face-1 shift must independently prove `c0` survives source matching and A3/route eligibility **before** measuring A4 gauges.

**Original native TB47 authority:** immutable `raw/492.log` SHA-256 `696b459ddc597c479d4df97e59da0663e09f4b2018829d065d62e0c741b9e7ff` records five nonzero hard carriers, five source/A3 candidates, five reciprocal/holonomy matches and zero odd face-gauge pairs; selected `c0` is `(0,3)`. The log **does not publish c0's numeric matching or from/to face order**. Do not retroactively label a predicted value native.

## Independent source-faithful numeric reproduction (Python, not native)

Reconstructed the committed 72-vertex/144-face `torus.obj`, the precise `torus_nonzero_z4_raw_field()` frame formula, `TriMesh::compute_geometric_quantities` local face bases, `PCFaceTangentBundle::init` complex edge connection, and the branch-nearest/effort/winding logic of `principal_matching` in a standalone Python/NumPy probe. An edge's first/second face is **modeled** by first indexed OBJ incidence; this must be confirmed against the native `TriMesh::EF` before assigning an authoritative directed sign. All five baseline nonzero source-hard carriers match the native **carrier identities and count**: `(0,3)`, `(0,61)`, `(3,25)`, `(25,37)`, `(37,49)`. Each has modeled baseline matching `1` modulo 4; this value is **not** in the published native log.

A face-1 cyclic advance, explicitly `new arm[j] = old arm[(j+1)%4]`, leaves the unordered 4-RoSy vectors and geometry unchanged. The independent numeric model predicts:

| Source edge | Original model χ | Face-1 advance χ | Inverse cycle χ | Incidence from/to (modeled) |
|---|---:|---:|---:|---|
| `(0,2)` non-hard | 0 | 3 | 1 | 0 → 1 |
| `(0,3)` hard, c0 | 1 | **2** | **0** | 1 → 22 |
| `(2,3)` non-hard | 0 | 1 | 3 | 1 → 24 |

All other 213 source-edge matching values are unchanged in the model; all three changed-edge source efforts are unchanged to `1e-12`. The hard-carrier census remains **five** under the face-1 advance and falls to **four** under the inverse cycle. The inverse therefore **extinguishes c0 in the model** and fails the witness candidate precondition even though its hypothetical face-gauge difference is odd. The two non-hard A3 matching changes have opposite signs due to directed source-edge orientation; a uniform signed increment across all three edges is incorrect. The first implementation of this numeric audit incorrectly assumed that sign and failed its assertion; the corrected audit checks source-first/source-second orientation independently. A second initial failure was a NumPy `int64` JSON serialization issue; resolved without changing numerical assertions.

The independent combinatorial eligibility audit exhaustively enumerates hypothetical nonzero χ in `{1,2,3}` and ±1 shifts, identifying **2 of 6** zero-result combinations `(1,-1)`, `(3,+1)`. This is a conditional Z4 counterexample to treating every odd gauge shift as a valid A3 source generator. It does *not* prove native c0's χ or which cyclic permutation the real producer preserves.

## Required next native proof, without weakening the frozen singleton

In a **separate** source-produced fixture (not the seven-consumer frozen torus singleton), preserve a baseline/advanced/inverse arm-order comparison and record each direction's actual produced `CrossFieldEdgeTransition` `firstFace`, `secondFace`, signed `matching`, and `effort` on the three exact edges above and all 18 hard carriers. Independently require the advanced-input c0 source χ remains nonzero, agrees with the exact A3 atlas on both orientations and survives `GlobalTopologyPlan` mandatory one-carrier route enumeration; explicitly demand the inverse-extinction negative **only if natively reproduced**, rather than assuming it. Then measure the *new* A4 connected accepted-cut domain, native root/face gauge, reciprocal periodic route, A5 retained canonical occurrence/action, A6 selected relation, and first-owner wrong-sign/restore. Fail at the earliest typed producer rejection, not by selecting an unrelated carrier or creating proxy pass evidence.

**Files and limits:** source snapshot `c08de57f6c76d53e6de856c6ca9228a7ff4db507` verified 5951/5951; `tests/SurfaceCellTransitionQuotientTests.cpp` SHA-256 `bec57b16e2475cd21be975fad22411925bdceaabd496f3258801d0f7875ea661`; `torus.obj` SHA-256 `8a6e0b63382a5eab8b02dc6e07f35e1611c736bf9c5744533fcee573de84c1d8`. `tb47_r54_torus_carrier_eligibility_audit.py` (static gate/table) and `tb47_r54_source_matching_numeric_probe.py` (independent numeric model) plus their exact JSON receipts are preserved in the chat evidence archive. **No new native pipeline acceptance, odd A4 gauge pair or A5/A6 PASS is claimed.**

**Disposition:** G3 remains open; G1/G2, 15 masked periodic A5 assertion sites, separate E2 and authentic history review remain open. Last accepted M6-CP2 491/491; TB47 500 PASS/4 registered RED candidate, selector497 unpromoted, stable 66/17/49 debt 1. R54 is an additional exact preflight to consolidate into the active DEFN-G Review; do not begin CB48/TB48 or successor.

# TB-REV-166 — adversarial continuation (2026-11-22 UTC)

Continues `M6-CP3-TB-REV-166-P13-STAGED-MULTI-CUT-FACE-RECEIPT-FULL-GATE` after the [independent review](Architecture_M6_CP3_TB_REV_166_Staged_Multi_Cut_Face_Receipt_Independent_Review_20261122.md). Runtime-free: source reading, the TB166 raw receipt, Haiku read-only audits, `git apply --check` and `-fsyntax-only` only.

## Verdict

- **Upheld:** TB166 acceptance (984/984, N1–N3 0 mismatches, 179 receipt lines) and the K5 discharge for edge-supported departures. Haiku re-derived it from the raw lines: all 24 port carriers exclude their source vertex, all print `slide=-`, and no arrival slide edge equals any port carrier at the same node.
- **Withdrawn:** the prose CB-186. It was not an exact diff, it was one monolithic turn, and its contract would have failed on the sphere witness itself (L3–L7). It is replaced by an exact CB-186 (pure helper plus five gated tests) and an exact 989-row TB167 manifest.
- **Corrected (mine):** K3 claimed that every face piece has two boundary ends. Ten of the 136 visits disprove it (L4).

## Findings

**L1 — K5 discharge holds.**
- The source argument is right: `edgePortCarrier` exists only when the first carrier contains the singular vertex (`SurfaceCellTracing.cpp:4342–4345`). No port in this witness qualifies.
- Arrivals per node (n0 `0-69`; n1 `6-8`, `8-9`; n2 `16-21`, `20-21`; n5 `32-34`, `33-34`; n6 `40-45`, `45-46`; n7 `49-62`) never meet a port carrier.
- The general A2a co-trace guard stays a producer obligation.

**L2 — CB-186 was handed over as prose.**
- RA-225 and RA-261 require exact patches for the implementation agent. TB-REV-166 instead gave a specification and asked the implementation agent to design an exact geometric algorithm, its types and its tests.
- That one turn also bundled six positive classes, permutation suites and seven negative controls.

**L3 — The output contract missed the consumer's second requirement.**
- `build_region_certificate` needs:
  - a key for **every** fragment orbit of a cut face (`RegionSourceFaceOwningFragmentMissing`, `GlobalTopologyPlan.cpp:2237–2256`);
  - at least one owner for every corner (`RegionInteriorVertexCornerOwnerMissing`, `:2287–2294`).
- Region source faces come from both dart orbits of every arc visiting the face (`add_fragment_orbit`, `:1101–1106`). So the strip between two nested chords (the 16 opposite faces) is a region that touches **no** corner.
- A corner-only helper wired as TB-REV-166 specified would move the stop to `RegionSourceFaceOwningFragmentMissing`.
- Contract: the helper returns corner sets, and CB-187 keys every fragment orbit of the face, empty sets included.

**L4 — Interior ends are normal; rejecting them would fail six sphere faces.**
- Ten visits are terminal slits (`exit=-`, `last=1`; `is_terminal_slit` at `:338`), in faces `0-1-2`, `0-2-3`, `18-19-24` (three), `25-26-27`, `25-27-28` (two) and `43-48-49` (two).
- Arcs 11/12 (trace 9, segment 0) and 16/17 (trace 13, segment 0) are single segments split **inside** faces `18-19-24` and `25-27-28`, where those slits stop on them.
- TB-REV-166's "missing ordered endpoints → typed rejection" and my K3 premise both get this wrong.
- The exact rule is local to each boundary end:
  - an entering end has the forward orbit before it and the reverse orbit after it (in corner order);
  - a leaving end has the opposite;
  - consecutive ends must agree on the orbit between them.
- Interior ends need no case of their own. An equal-sided slit separates nothing, which subsumes the legacy skip at `:520–526`. A distinct-sided slit that stops on nothing is rejected. The legacy reader instead treated such a slit as a chord to its hypothetical outgoing carrier, which was a guess.

**L5 — "Ties → rejection" contradicts the required 6-8-9 case.**
- Ports 3 and 4 share corner `v8`, and slide arrivals share points with their own slides.
- Cut ends at one boundary point are ordered exactly by where each straight cut's other end lies.
- Only coincident cuts, or a shared point with an end inside the face, are unordered.
- This replaces port-ordinal order with geometry, and the agreement walk subsumes `FragmentCornerOrbitChainMismatch`.

**L6 — Some negative controls were in the wrong layer.**
- "An incoming slide sharing an edge-supported departing port", "non-disk geometry" and "source/sheet/rail identity" cannot be reached by a pure face helper: it never sees edge pieces, sheets or rails. Tests for them there would be vacuous (AGENTS.md: a test must be able to fail).
- They stay with A2a and the region certificate.

**L7 — The specified tests would never have run.**
- Gate rows are exact `--gtest_filter` names (`tools/m6_cp3_local_gate_driver.py:138–141`).
- The membership harness requires every listed test to be governed (`tools/m6_cp3_targeted_artifact_harness.sh:140–160`).
- TB-REV-166's "no selector change" with new tests means the tests are ungated and membership fails.
- Frozen: the TB167 manifest, rows 985–989 added after rows 1–984 of TB165 unchanged.

**L8 — The v2 receipt (mine) has two limits.**
- It prints segment-level ends for every arc, so split arcs (0/1, 11/12, 16/17) print identical lines.
- `exit=-` hides where a slit stops.
- Rounded laminarity (113 F chords, 64 pairs with distinct ends, 0 interleaved) is evidence only.
- CB-187 must take arc ends from node loci and the arc's own pieces, not from segment supports.
- `SourceFaceRecord` vertex order is not documented as counter-clockwise. The helper names sides relative to `face.vertices` order, exactly as the `turn` rule does, and the turn-1, turn-2 and ray-fan tests pin that equivalence (RA-274).

## Frozen artifacts

| Artifact | SHA-256 | Content |
|---|---|---|
| `Architecture_M6_CP3_CB186_P13_Face_Cut_Corner_Partition_Helper_Exact.diff` | `a89c7a9ce54bfea2f893868550fe5250e4bf4aaa5f3db72da0951cd8a01eb4b7` | 19,386 B, +400/−0. New `src/geometry/FaceCutCornerPartition.h` (`cea68118…ce4e`): `FaceBoundaryPosition`, `FaceCutPiece`, `FaceCutPartitionFailure`, `partition_face_corners`. Unwired. Test file `c62c51b0…ffe2` → `8ccfc38b237322e65962644593a81308142bee9f963ab3330784c094a98c1e24`: include plus five `FaceCutCornerPartition.*` tests (turn and ray rules; nested strip; 6-8-9 with order and renumbering invariance; interior ends and equal-sided slit; ten rejections, each reaching its own rule). |
| `gates/Architecture_M6_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Case_Manifest.tsv` | `5c0841993d9b9c5537a3b78a3f7df39e61ee82e09b1ce9b4be3f4510ff088c50` | 989 rows: rows 1–984 are TB165 `8d56ee1d…1e69` byte for byte; rows 985–989 are the five new tests (`directional_surface_cell_producer_tests`, PASS). |

Checks (Haiku, fresh worktree at `718f7c2ca`):
- The preimage `c62c51b0…ffe2` matched, and the header was absent before applying.
- `git apply --check`, `git apply` and `git diff --check` pass. Both postimage hashes match.
- `git apply --numstat` gives 234 + 166 lines added and 0 removed.
- `-fsyntax-only` (clang, C++20, `-Wall -Wextra`, GMP defines): 0 errors and 42 warnings both before and after, with identical normalized warning sets.
- The header compiles on its own (`-Wpedantic`), with 0 warnings from it; its 6 warnings come from gmpxx/ENumberGMP.
- Manifest rows 1–984 are byte-identical to TB165. Rows 985–989 equal the five new test names. No name collisions.
- Nothing was built or run.

## TB167 rules (STOP unless all hold)

1. 989/989 PASS; CP2 491/491; membership 1070 (989 gating + 81 deferred).
2. Rows 1–984 equal TB166 result `14765434765` under N1–N3, row 979 included, with zero allowance (the helper is unwired).
3. Rows 985–989 PASS, logs published.
4. No census: no production path changes.
5. Any failure → BLOCKED and back to Review. A failing helper test is reported verbatim, never edited.

## Turn sequence

1. **CB-186** — apply the exact helper diff (compile only).
2. **TB-EXEC-167** — 989 rows, rules above.
3. **TB-REV-167** — freeze an exact CB-187. It is a Review-only follow-on (RA-219), because it must read arc pieces and node loci against a helper that has been proven to run. CB-187 contract:
   - build `FaceCutPiece`s from each arc's own face pieces, with ends from node loci or edge transits (an interior end → `nullopt`);
   - pass no edge-only pieces;
   - key every fragment orbit of the face;
   - map each helper failure to a typed plan error;
   - remove the one-cut and ray branches.
4. **CB-187** (compile only).
5. **TB-EXEC/REV-168** — staged plan built, or the next typed stage.
6. CB-188 activation (V3/V4/V5/V10/V11).
7. TB-EXEC/REV-169.
8. CB-189 V3b.
9. R1, then O48.

## Lessons

- Before freezing a reader's replacement, read every check the consumer applies to the reader's output, not only the field it was asked to produce.
- A receipt that prints segment-level ends hides split arcs and interior ends. Check the shape premise ("two boundary ends") against every visit, not only the faces named in the prediction.
- A tie rule must be checked against the required positive cases before it is frozen.

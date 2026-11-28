# CB-215, CB-216 exact manifests and TB-EXEC-192 contract (2026-11-27 UTC)

**Review artifact only.** Frozen by [`M6-CP3-DEFN-P13-A2A-SINGULARITY-ARRIVAL-PORT-OWNERSHIP`](../Architecture_M6_CP3_DEFN_P13_A2a_Singularity_Arrival_Port_Ownership_20261127.md). Nothing here has been applied, built or run.

Review checks, all run in throwaway `CLAUDE_` worktrees that have since been removed:
- `git apply --check` and apply, forward on HEAD `78fb178a4` and stacked, then reverse to a clean tree;
- `git diff --check`;
- clang++ `-fsyntax-only` before and after each diff (results in the DEFN record). This is not compile evidence.

Both diffs are compile-only and behaviour-neutral, with two independent Code + Build turns and one gate after both.

## `M6-CP3-CB-215-P13-SINGULARITY-RAY-CLASSES` — A1, compile only

**Diff:** [the diff file](../Architecture_M6_CP3_CB215_P13_Singularity_Ray_Classes_Exact.diff), 10,226 B, SHA-256 `e6176e8f0a12eccb191356e57819eb4c22402e7e28ff84b6e6dffdc5aeb44e83`. Three paths, +115/−3, on source `78fb178a4` (product bytes equal to the CB-214 source `9ed55608…`).

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `include/directional/authority/FieldTransportAtlas.h` | `0621740796c089cbc7f6858fa6d98d6e8fc8ba2da3482b9e4b00192eb0a16079` | `4cf6517bf83b9772898197f7a878b7b3761f448a9c14572c0cec4db91c9daf0c` |
| `src/authority/FieldTransportAtlas.cpp` | `7b0b8138cfe70f6a98c2f1cf0b6efafaa653a50444ebb8bad02078f7021a0841` | `0956d4cfb955fab0a0be2a9997bde43beb495498c7b08133620ada6387375679` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `a371dffbb30576dfe492631ecd68f2006b1cef01b721f2518a8472362e617584` | `72509d64f641c64829ee259b735d7a5448b62990fd427c8b4334bd622821f3ef` |

**Change.** `FieldBranchTopology::singularity_rays()` publishes every face ray the port partition already computes. Each ray records:
- singularity and vertex;
- start face and branch;
- `portSlot`, the `localSlot` of its class's port;
- `alongRadialEdge`, set when the ray has zero weight on one far vertex.

The rays are sorted. They are not in `semantic_digest()` or any hash, so no digest changes. The single caller and the private constructor are the only other changes; ports, classes and slots are unchanged.

**Test (gate row 1009):** `FieldTransportAtlas.MechanicalSingularityRaysLieOnRadialEdgesAndNameTheirPortSlot`. On the mechanical fixture it requires:
- 12 attachments and 12 sorted rays;
- every attachment is exactly one ray with the same slot (one ray per class there);
- the 12 rays and their radial edges equal the table read from the TB191 row-1003 atlas log.

**CB steps:**
1. Verify the diff hash and the three preimages.
2. Apply.
3. Compile the eight GMP/GMPXX targets with `runtimeExecution=false`.
4. Require an immutable package and 28/28 checks.

STOP on any mismatch.

## `M6-CP3-CB-216-P13-SINGULARITY-ARRIVAL-CLASSIFICATION` — A2a, compile only, on CB-215

**Diff:** [the diff file](../Architecture_M6_CP3_CB216_P13_Singularity_Arrival_Classification_Exact.diff), 13,166 B, SHA-256 `d6e980a89dc6bdc47569e81dabffb763b645d60023f542d6f9d24dac2f664bfa`. Four paths, +251/−0; its preimages are CB-215's postimages or unchanged files.

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `daf7b7a0c9fb66bcf58db10b534e502f7294463fb94fa7b4b30c10243e1f19d3` | `7fcb9fc2f30b4856f11fe8357c2e91fbf4a1c5d927a878cfeda7d0c9d8def49e` |
| `src/geometry/SurfaceCellTracing.cpp` | `ad3c5ea3a9f73031e076330ab583b9951dadb6f92b1174991f521cc31a5c0de1` | `d6dbb123c7d86db3f12032c7827dc68c1b4629c328cfcea956bd7fa010bc650a` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `72509d64f641c64829ee259b735d7a5448b62990fd427c8b4334bd622821f3ef` (CB-215 postimage) | `9b08f17416d2a9468e6a8668793429b02b4cbc4d167b488e35bfb2f762cf338b` |
| `tests/SurfaceCellTracingDisplayTests.cpp` | `004b6afb0ed74e9236f21b829b025da25489123d62416cba979289603481d630` (CB-214 postimage) | `730c06d9504e07c59050986fdf3ed27133a33d7a2e21d5f326906d3c30b9613e` |

**Change.** It adds three things:
- a free function, `classify_field_aligned_singularity_arrivals(network, atlas)`;
- `FieldAlignedArrivalApproach`, with `field_aligned_arrival_approach_name`;
- `FieldAlignedSingularityArrival`.

For each trace ending at a singularity, in trace order, it records the target, its node, the approach (`RadialEdge` when the last exact piece runs along an edge, otherwise `FaceInterior`), the edge, the matched port and `portTraced`. Matching works as follows:
- **Along a radial edge:** the edge-supported port on it, else the class with a ray on it, else the class with a ray in each face of it.
- **Through a face interior:** the ray in that face on `branch.rotated(2)`.

It returns empty on an atlas-digest mismatch or an unavailable exact path. No stage reads it, and the network is not changed (RA-211).

**Tests:**
- **Gate row 1010:** `FieldAlignedCurveNetwork.MechanicalRetraceArrivalsRealizeTheRemovedPortsSeparatrix` requires:
  - one record per singularity-ending trace, in order;
  - every matched port belongs to the target, sits on the record's node, and reports `portTraced` truthfully;
  - each of the four D13 retrace arrivals is `RadialEdge` with `port == arrivalPort` and `portTraced == false`. This independently cross-checks the CB-196…199B exact-retrace selector.
- **Row858** gains, after the 16 CB-214 lines: one sphere summary, one line per sphere arrival, and one genus_two summary. Existing assertions are unchanged.

**CB steps:** the same as CB-215, after CB-215 is compiled.

## `M6-CP3-TB-EXEC-192` — full gate on the CB-216 package

**Inputs:**
- the CB-216 package;
- harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`;
- **manifest [1010 rows](Architecture_M6_CP3_CB215_CB216_TB192_Singularity_Arrival_Full_Gate_Case_Manifest.tsv)**, SHA-256 `c9f6325eee41ebead3d516d3bfcbef3141c9dee8c7051cef1e08ad146f60e9f5`. Its header plus rows 1–1008 equal TB191's `ca16b66d…4081`, and header plus rows 1–1006 equal `a9b80832…0587`;
- deferred `fd433f54…64ce` (81), so membership is 1091.

No rebuild, retry, timeout substitution or V5.

**Comparisons**, under N1–N3 against TB191 result `15179335926`:
- All 1010 rows must PASS.
- Rows 1–1008 except row858 must be N1–N3-equal, including the 13 named controls and rows 1003, 1007 and 1008.
- **Row858:**
  - Every byte through the last TB191 line (`GenusRegionBoundarySchedules …`) must equal TB191.
  - Exactly 12 lines follow; then the suffix must be N1/N2-equal.

**Predictions.** They are derived from the TB191 row858 atlas-partition and `committedSlide` lines. A mismatch is STOP for review, never a repair.
- `SphereSingularityArrivals classified=1 arrivals=10 radialEdge=10 faceInterior=0 matched=10 portTraced=10`.
- 10 `SphereSingularityArrival` lines, in this order. Every line is `approach=radial-edge portTraced=1`, and its `port` lies in the listed range (ports 3s…3s+2 of singularity s):

  | trace | node | edge | port range |
  |---|---|---|---|
  | 0 | 1 | 6-8 | 3–5 |
  | 1 | 2 | 16-21 | 6–8 |
  | 9 | 1 | 8-9 | 3–5 |
  | 10 | 7 | 49-62 | 21–23 |
  | 11 | 2 | 20-21 | 6–8 |
  | 12 | 6 | 40-45 | 18–20 |
  | 13 | 5 | 32-34 | 15–17 |
  | 14 | 0 | 0-69 | 0–2 |
  | 21 | 5 | 33-34 | 15–17 |
  | 22 | 6 | 45-46 | 18–20 |

  The two arrivals at one node name different ports. Port ids are measured.
- `GenusSingularityArrivals classified=1 …`: all counts are measured.
- These outcomes falsify the A2a co-trace finding, O51: `unavailable`, `classified=0`, any sphere arrival with `matched` below 10, a `face-interior` line, or `portTraced=0`. Record them; do not repair.

**Not allowed:**
- gate credit before `M6-CP3-TB-REV-192`;
- any tracing, retrace-selection, A2b or A3 behaviour change, or a change to dispatch or the veto;
- B1 or fallback repair;
- CB-207D;
- promotion of CP3/497/D0/H4.

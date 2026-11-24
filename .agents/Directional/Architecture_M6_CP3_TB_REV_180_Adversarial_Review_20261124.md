# TB-REV-180 — adversarial continuation (2026-11-24 UTC)

This continues turn `M6-CP3-TB-REV-180` after the [independent review](Architecture_M6_CP3_TB_REV_180_Cross_Partition_Arc_Census_Independent_Review_20261124.md).

The review was runtime-free. It used:
- source reading;
- Haiku read-only work: the CB-201 pre/postimage and apply check, `clang++ -fsyntax-only` on three patched TUs, an inventory of the held items, an API inventory, and extraction of the TB180 row-979 raw log (`raw/979.log`, SHA-256 `c361e049…c608`, matching the ledger).

## Verdict

- **Upheld:** TB180 accepted at 1003/1003, with the seven controls green and the TB170 recurrence closed at the control boundary.
- **Upheld:** CB-201 exact diff, unamended (N1).
- **Realigned:** the trajectory after CB-201. "Row979 — read printed locus first" was not a turn. The printed evidence already exists in TB180 and is read here (N2). It points at a granularity disagreement between two plan readers (N3). The successor after the CB-201 gate is now a narrow product correction with a falsifier, not an open-ended investigation.

## Findings

**N1 — CB-201 is mechanically sound and namespace-only.**
- The diff hash `0da2ffe2…d91c` and all seven pre- and postimages match the manifest. It applies cleanly at HEAD: +66/−66, and `git diff --check` is clean.
- `clang++ -fsyntax-only` on the patched `EmbeddedGraphTopology.cpp`, `SurfaceCellTracing.cpp` and the test TU gives 0 errors, with warning counts equal to HEAD (3/3/9).
- None of the moved names is still qualified by the downstream namespace. ArcFaceVisits.h keeps `embedded::` only for symbols that stay downstream (`SourceFaceRecord`, `source_piece_binding_failure`, `exact_source_point_barycentric`).
- `GlobalTopologyPlan.cpp:428` and `SurfaceCutGraph.cpp:206,434,940,1071` contain `using namespace embedded_graph_topology_detail`, and none of them uses a moved symbol unqualified. These TUs were not syntax-checked here, and the CB compile is the falsifier.
- `FaceChartPoint` is an alias of `std::array<FieldExactRational,3>`, so moving its namespace changes no ADL associated namespace. No same-named overloads exist in both namespaces, so overload resolution cannot change.
- The one non-rename line replaces a blank line with the test alias `trace_segment` (`tests/…:70–73`), which keeps line numbers fixed.

**N2 — the row-979 printed locus is already published, and it rules out a missing port.**

TB180 row 979 (identical to TB179 apart from timing):
- `SphereStagedPlan outcome=RegionContainsInteriorSingularity`, with `sourceVertex=8`, failure stage `RegionCertification`, and a failing region of 46 source faces.
- Vertex 8 is network node 1, with `SingularValence node=1 ports=3 arrivals=2 arcEnds=5`:
  - departures: arcs 5, 6 and 7 (traces 3, 4 and 5);
  - arrivals: arc 1 (trace 0, slide 6-8) and arc 12 (trace 9, slide 8-9).
- Traces 3 and 4 both leave through face `6-8-9` across edge `6-9`. Nodes 2, 5 and 6 have the same shape.

So the port node is on the graph and bounds every sector around vertex 8. A region can still be reported as containing vertex 8 if it reaches the vertex only by face-level membership.

**N3 — candidate product defect P1: the interior-singularity check reads regions at face granularity, but regions are fragment-granular.**

How each reader decides which vertices a region contains:

| Reader | Rule | Where |
|---|---|---|
| Contract | `GlobalTopologyRegion::sourceFaces` is fragment support: "A source face crossed by traces may therefore occur in multiple regions." | `GlobalTopologyPlan.h:78–81` |
| `validate_region_interior_singularities` | A vertex "reaches" the region when *any incident source face* is in `regionFaces`. | `GlobalTopologyPlan.cpp:1791–1806` |
| `build_region_certificate` | A cut face contributes only the corners owned by the region's orbit, through `fragmentCorners[face][owningOrbit]`. | `GlobalTopologyPlan.cpp:2196–2222` |

- The singularity check runs before the owning orbit is known (`:2394` versus `region_orbit` at `:2400`). It is never given `fragmentCorners`, although that is built at `:2389`.
- So a region that owns only a strip of a cut face that misses vertex v's corner is reported as containing v, even though its boundary correctly omits v's port node.
- This is the same class as S1 (TB-REV-167): two readers of one fact disagree.
- **Not proven as the row-979 cause.** The error's projected locus does not name the failing region (`RemeshPipeline.cpp:684–686` projects the region only in one case), so the faces involved are unknown.
- The correction is justified by the contract alone. The TB decides whether it is also the cause.

**N4 — independent-review gap.** It records row 979 as "not a valid sphere plan". That presumes the rejection is lawful. N3 shows the rejecting predicate disagrees with the plan's own region contract, so row 979 stays *unclassified* until CB-202's TB.

**N5 — carried.** J6 (production struck-reference witness), E5, Branch A and CB-190 stay held. CP3/497/D0/H4 are not promoted.

## CB-202 requirements, to be frozen as an exact diff by TB-REV-181

These requirements bind the Review. The implementation agent receives only the exact diff.

1. **One source.** Extract the region-vertex derivation from `build_region_certificate` (`:2185–2222`) into one helper: an uncut face contributes all its vertices; a cut face contributes `fragmentCorners[face][owningOrbit]`. Both the singularity check and the certificate use that helper.
2. **Corner-granular check.** A singular vertex is interior when it is in that set and no port node of its singularity is on the region's boundary. The helper keeps the existing `RegionSourceFaceOwningFragmentMissing` failure.
3. **Precedence preserved.** Before freezing, census every test that asserts `RegionOrbitMissing`, a boundary-walk error, or `RegionContainsInteriorSingularity`. Either keep the reported-error order, or itemize each row whose code changes.
4. **Falsifiers.** Add one appended unit guard:
   - (a) A region that owns only a non-corner fragment of a singular-vertex-incident face is *not* rejected.
   - (b) A region that owns the corner, with no port node on its boundary, *is* rejected with `RegionContainsInteriorSingularity`.
   - The existing `GlobalTopologyPlan.RejectsRegionWithWrongEulerCharacteristicOrInteriorSingularity` (`tests/…:4277`) must stay unchanged and PASS.
5. **Locus.** The row-979 `SphereStagedPlan` line also prints `error.region` (test-only, an append within the row-979 body).
6. **TB rule.**
   - Only row 979 and the new guard row may change.
   - Prediction: row 979 moves past `RegionContainsInteriorSingularity`.
   - If it does not, P1 is falsified as the cause: the rejection is lawful, and the route is A2a network topology at node 1 (two departures through `6-8-9`/`6-9`).

## Turn sequence

1. `M6-CP3-CB-201-P13-EXACT-TRACE-SEGMENT-NAMESPACE`: exact diff, compile only.
2. `M6-CP3-TB-EXEC-181-P13-TRACE-SEGMENT-NAMESPACE-FULL-GATE`: TB179 manifest unchanged; all 1003 rows N1–N3-identical to TB180.
3. `M6-CP3-TB-REV-181`: close K6 and freeze the exact CB-202 diff against the requirements above.
4. CB-202 (corner-granular interior-singularity reach) → TB-EXEC-182 → TB-REV-182: classify row 979.
5. Then the row-979 successor (built plan → Branch A, or A2a), then CB-190.

## Lessons

- Before scheduling "read the locus", read the receipts already in the latest gate artifact. TB180 row 979 already published the singular-node valence.
- When a predicate tests membership in a fragment-granular set, check that it reads fragments rather than whole faces, and that no other reader of the same fact decides it differently.

# CB-202 exact manifest — region-corner singularity reach (2026-11-24 UTC)

**Review artifact only.** No application, build or runtime is authorized in TB-REV-181.

- Owner: `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH` (Code + Build only).
- Authority: [TB-REV-181](../Architecture_M6_CP3_TB_REV_181_Region_Corner_Ownership_Independent_Review_20261124.md), [TB-REV-180 requirements 1–6](../M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc).
- Semantic preimage `b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3`. Verified snapshot `1aebcd183113512cce435d45b7ae373164f1b8f7` has identical product/test/build bytes.
- Exact [diff](../Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact.diff) SHA-256 `26ec484d0434afd3f0376661e945bdbd73d1c9a1fc206e7b589be34bb3ba5332`, 25,159 bytes, three paths, +297/−105. Scratch `git apply --check`, application and `git diff --check` pass; all postimages verified. No compile or runtime verification in Review.

## Required behavior

One internal `region_corner_vertices` helper derives the source vertices of a region from its owning orbit. An uncut face contributes its three vertices; a cut face contributes only the corner set of the owning orbit (including an empty set for a strip). An absent owning orbit on a cut face retains `RegionSourceFaceOwningFragmentMissing`, including region, face and the exact orbit inventory. The singularity validator and the disc certificate consume the same set. A reached singularity with no port node on the region boundary is rejected with `RegionContainsInteriorSingularity`. No change to A2a trace selection, cut partition production, field, topology, Euler proof, ownership rules, public API, or acceptance criterion.

The existing whole-domain negative (row355) deliberately claims the union of all regions with an exterior-only walk, so a single canonical interior orbit cannot represent that claim. For candidate validation only, when one supplied region claims the entire certified multi-region partition, prove the complete support union and exact exterior arc census after validating the closed walk. Every authoritative graph dart is unique; an arc occurring once in the partition is exterior and an arc occurring twice is internal. The candidate must list every exterior arc exactly once, with no internal arc. Both walk directions are admissible for this rejection-only proof. Use the same helper on every canonical orbit and union the corner sets. If an interior singularity exists, return the existing typed rejection; otherwise reject `RegionOrbitMissing`. Never accept the union, invent an orbit, or use whole-face reach on a cut face. No fallback for partial or unmatched support. This preserves the existing negative's meaningful failure, not merely its expected code.

## Exact preimages and postimages (SHA-256)

| Path | Before | After |
|---|---|---|
| `src/geometry/GlobalTopologyPlan.cpp` | `44395316a518c0cef8cd9afabdc622d69900496c1f6e4a290c37715602fb366f` | `37b7cd52d1a22b602aff856716f25e8185732ac0cc3d37268dba8ca58564446c` |
| `src/geometry/RegionCornerOwnership.h` | `ABSENT` | `c5d376fe783e374a97bf48b0a0ea16cfcbc175947a0f1a6ab88192343193e60a` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `af3204703d804c905d0e46f9edb2d483197f2eaaa3bea6128a5accd1189f156b` | `9f08edd716bd07348305e4f6edc460aa09bd2d2b9e3255806611301b553cd690` |

## Rejection precedence census (complete exact enum references in test source)

| Row / test | Required result and static basis |
|---|---|
| 354 `GlobalTopologyPlan.RejectsRegionWithMultipleBoundaryWalks` | Existing `RegionBoundaryNotSingleWalk`, arc unchanged. Duplicate walk fails the unguaranteed boundary check before ownership. |
| 654 `GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected` | Existing `RegionBoundaryNotSingleWalk`, `ClosedBeforeEnd` and exact arc. Same proof. |
| 355 `GlobalTopologyPlan.RejectsRegionWithWrongEulerCharacteristicOrInteriorSingularity` | Existing `RegionContainsInteriorSingularity`, region/singularity/vertex all present. Complete-partition union rejection; existing test byte-identical. |
| 966 `GlobalTopologyPlan.IndependentValidationBindsTraceSegmentsToSourcePieceCounts` | Existing `RegionBoundaryArcNotOwnedByNetwork` for fabricated continuation; earlier exact replay and binding checks remain. |
| No direct test asserts `RegionOrbitMissing` | Unmatched walk cannot establish one interior orbit; retain typed error. |

For malformed candidates that do not claim the full partition, a broken walk or missing orbit now precedes any unprovable interior reach. Missing corner ownership can precede later certificate support checks; this is intentional because reach cannot be decided without corner ownership. The four listed accepted tests must remain PASS with exact prior raw receipts. No other frozen row is granted a precedence exception. The new guard deliberately provides independent exact corner inputs for the same face, one non-singular-corner region, one singular-corner region without a boundary port, a cornerless strip, a boundary-port case, an uncut face and a missing orbit. It exercises the same helper and rejecting predicate as production. Removing corner filtering breaks the positive; removing rejection breaks the negative. The old full-candidate negative exercises the rejection-only union in production validation. All existing tests retain their physical line positions: only line50 (new private include) and row979 receipt line18184 change; one test is appended at EOF. Row979 prints `error.region`.

## Build and separate runtime falsifier

1. Verify the exact preimages and patch SHA-256; apply only this diff. Verify all three postimages and the path set. Compile the eight default targets with GNU Multiple Precision (GMP/GMPXX); `runtimeExecution=false`. No tests, membership discovery, benchmarks, runtime, unrelated repairs, validator relaxation or fixture edits. A mismatch or compile failure is STOP; return to Review.
2. After the separate successful CB, use the immutable package for `M6-CP3-TB-EXEC-182-P13-REGION-CORNER-SINGULARITY-REACH-FULL-GATE`. [Frozen case manifest](Architecture_M6_TB182_P13_Region_Corner_Singularity_Reach_Full_Gate_Case_Manifest.tsv) SHA-256 `d778afbe65e181391116a67ada06f4482e9786917ca58dd2a17f7b7459d8ca5f`, exact first 1003 rows plus one new guard row1004; old prefix SHA-256 `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`. Deferred ledger `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`, 81 unchanged. Expected 1004 gated + 81 deferred = 1085 membership. All 1004 cases must PASS. Compare with TB181 result `14967943314` ZIP SHA-256 `877efb75d3ed801aab7fdc9931356254155162a114d9fc36a2f680f02ec9fa6b`. All 1003 inherited rows retain ledger fields except log SHA; only row979 raw receipt may change, plus new row1004. N1/N2/N3 only (elapsed time, line endings, counted full fragment record ordering). No broad normalization, unrelated semantic-digest change or new regression. Any off-row change, new RED, missing/duplicate/extra membership, lost negative or unknown result is STOP.
3. Prediction: row979 moves beyond `RegionContainsInteriorSingularity`; the region field identifies the actual locus if rejected. If the typed rejection remains, P1 is falsified as the row979 cause under the frozen prior requirement; use the exact region/vertex/port evidence to classify the lawful rejection, and return to Review for A2a node1 (two departures through face6-8-9 / edge6-9). If it advances but does not build, classify the new earliest reason before planning; no Branch A activation. If the plan builds, only TB-REV-182 may authorize the later Branch A turn. The guard and complete gate, not static reasoning, decide these claims.
4. CP3/497/D0/H4, J6 production struck-reference witness debt, E5, CB-190 and Branch A stay held. No promotion.
